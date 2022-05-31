
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
 * Abstract class offering methods to help with the Arr namespace. This can
 * be moved to a trait once Zephir supports it.
 *
 * @todo move to trait when there is support for it
 */
abstract class AbstractArr
{
    /**
     * Helper method to filter the collection
     *
     * @param array         $collection
     * @param callable|null $method
     *
     * @return array
     */
    protected function toFilter(
        array collection,
        var method = null
    ) -> array {
        if (!method || !is_callable(method)) {
            return collection;
        }

        return array_filter(collection, method);
    }
}
