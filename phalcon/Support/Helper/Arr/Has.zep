
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
 * Checks an array if it has an element with a specific key and returns
 * `true`/`false` accordingly
 */
class Has
{
    /**
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
