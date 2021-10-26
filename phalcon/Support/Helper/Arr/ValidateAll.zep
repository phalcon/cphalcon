
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
 * Returns `true` if the provided function returns `true` for all elements of
 * the collection, `false` otherwise.
 */
class ValidateAll extends AbstractArr
{
    /**
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     */
    public function __invoke(array collection, var method) -> bool
    {
        return count(this->toFilter(collection, method)) === count(collection);
    }
}
