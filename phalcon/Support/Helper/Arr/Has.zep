
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
 * Class Has
 *
 * @package Phalcon\Support\Arr
 */
class Has
{
    /**
     * Helper method to check if an element exists in a collection
     *
     * @param array      $collection
     * @param string|int $index
     *
     * @return bool
     */
    public function __invoke(array collection, var index) -> bool
    {
        return array_key_exists(index, collection);
    }
}
