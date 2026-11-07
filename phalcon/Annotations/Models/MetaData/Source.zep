
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Models\MetaData;

/**
 * Names the table of a model when the annotations service uses AttributesReader.
 * An explicit setSource() takes precedence. The model manager applies its
 * table prefix to the source.
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
}
