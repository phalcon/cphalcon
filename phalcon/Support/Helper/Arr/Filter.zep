
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

use Phalcon\Traits\Support\Helper\Arr\FilterTrait;

/**
 * Filters an array using array_filter. If a callback is supplied, it will be
 * used.
 */
class Filter
{
    use FilterTrait;

    /**
     * @param array<array-key, mixed> $collection
     * @param callable|null           $method
     *
     * @return array
     */
    public function __invoke(array collection, var method = null) -> array
    {
        return this->toFilter(collection, method);
    }
}
