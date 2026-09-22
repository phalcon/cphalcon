
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Models\MetaData;

/**
 * Names the table of a model. No framework code reads it today.
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
