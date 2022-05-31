
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
 * Returns `true` if the provided function returns `true` for at least one
 * element of the collection, `false` otherwise.
 */
class ValidateAny extends AbstractArr
{
    /**
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     */
    public function __invoke(array collection, var method) -> bool
    {
        return count(this->toFilter(collection, method)) > 0;
    }
}
