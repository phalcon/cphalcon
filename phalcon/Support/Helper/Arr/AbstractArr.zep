
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
 * Class AbstractArr
 *
 * @package Phalcon\Support\Helper\Str
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
