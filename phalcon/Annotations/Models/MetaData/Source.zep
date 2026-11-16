
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Models\MetaData;

use Phalcon\Annotations\Adapter\AdapterInterface;
use Phalcon\Annotations\AttributesReader;
use Phalcon\Annotations\Collection;
use Phalcon\Annotations\Exceptions\InvalidSourceTable;

/**
 * Names the table of a model when the annotations service uses AttributesReader.
 * An explicit setSource() takes precedence. The model manager applies its
 * table prefix to the source.
 * The attribute applies only to the class declaring it; it is not inherited.
 * PHPDoc @Source annotations do not change the model's table.
 * A Source attribute must specify a non-empty string table name.
 *
 * ```php
 * use Phalcon\Annotations\Models\MetaData\Source;
 * use Phalcon\Mvc\Model;
 *
 * #[Source(table: "customers")]
 * class Customers extends Model
 * {
 * }
 * ```
 */
#[\Attribute(\Attribute::TARGET_CLASS)]
class Source
{
    /**
     * @var string
     */
    public table;

    public function __construct(string table)
    {
        let this->table = table;
    }

    /**
     * Returns the table from a Source annotation, or null when none is present.
     * Named arguments take precedence over positional arguments.
     *
     * @throws InvalidSourceTable
     */
    public static function getTable(<Collection> annotations) -> string | null
    {
        var sourceAnnotation, table;

        if !annotations->has("Source") {
            return null;
        }

        let sourceAnnotation = annotations->get("Source"),
            table = sourceAnnotation->getNamedArgument("table");

        if table === null {
            let table = sourceAnnotation->getArgument(0);
        }

        if typeof table !== "string" || trim(table) === "" {
            throw new InvalidSourceTable(table);
        }

        return table;
    }

    /**
     * Returns the model's table when the adapter uses AttributesReader.
     * Other readers do not opt in and are not asked to parse the class.
     *
     * @throws InvalidSourceTable
     */
    public static function getTableFromAdapter(<AdapterInterface> adapter, string className) -> string | null
    {
        var annotations;

        if !(adapter->getReader() instanceof AttributesReader) {
            return null;
        }

        let annotations = adapter->get(className)->getClassAnnotations();

        if annotations === null {
            return null;
        }

        return self::getTable(annotations);
    }
}
