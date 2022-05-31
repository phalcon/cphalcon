
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Returns a new array with n elements removed from the right.
 */
class SliceRight
{
    /**
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
