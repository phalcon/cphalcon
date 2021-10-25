
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Class SliceRight
 *
 * @package Phalcon\Support\Arr
 */
class SliceRight
{
    /**
     * Returns a new array with the X elements from the right
     *
     * @param array $collection
     * @param int   $elements
     *
     * @return array
     */
    public function __invoke(array collection, int elements = 1) -> array
    {
        return array_slice(collection, elements);
    }
}
