
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Support\Helper\Arr;

/**
 * Filters a collection using array_filter with an optional callable
 */
trait FilterTrait
{
    /**
     * Helper method to filter the collection
     *
     * @param array         $collection
     * @param callable|null $method
     *
     * @return array
     */
    protected static function toFilter(
        array collection,
        var method = null
    ) -> array {
        if (!method || !is_callable(method)) {
            return collection;
        }

        return array_filter(collection, method);
    }
}
