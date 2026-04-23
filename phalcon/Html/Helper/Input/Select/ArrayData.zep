
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input\Select;

/**
 * Wraps a plain PHP array as a SELECT data provider.
 *
 * Keys are option values; string values are labels;
 * array values define optgroups.
 */
class ArrayData implements SelectDataInterface
{
    /**
     * @var array
     */
    protected data = [];

    /**
     * @param array data
     */
    public function __construct(array data = [])
    {
        let this->data = data;
    }

    /**
     * @return array
     */
    public function getOptions() -> array
    {
        return this->data;
    }
}
