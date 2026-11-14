
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Models\MetaData;

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

        if typeof table !== "string" || table === "" {
            throw new InvalidSourceTable();
        }

        return table;
    }
}
