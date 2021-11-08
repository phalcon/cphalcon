
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
 * Filters a collection using array_filter and using the callable (if defined)
 */
class Filter extends AbstractArr
{
    /**
     * @param array         $collection
     * @param callable|null $method
     *
     * @return mixed
     */
    public function __invoke(array collection, var method = null) -> var
    {
        var filtered;

        let filtered = this->toFilter(collection, method);

        return reset(filtered);
    }
}
