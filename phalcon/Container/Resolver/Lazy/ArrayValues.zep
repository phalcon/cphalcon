
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */

namespace Phalcon\Container\Resolver\Lazy;

use ArrayAccess;
use ArrayIterator;
use Countable;
use IteratorAggregate;

class ArrayValues extends Lazy implements ArrayAccess, Countable, IteratorAggregate
{
    /**
     * @var array<array-key, mixed>
     */
    protected values = [];

    /**
     * @param array<array-key, mixed> $values
     */
    public function __construct(array values = [])
    {
        let this->values = values;
    }

    public function count() -> int
    {
        return count(this->values);
    }

    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->values);
    }

    /**
     * @param iterable<array-key, mixed> $values
     *
     * @return void
     */
    public function merge(var values) -> void
    {
        var key, value;

        for key, value in values {
            if (is_int(key)) {
                let this->values[] = value;
            } else {
                let this->values[key] = value;
            }
        }
    }

    public function offsetExists(mixed offset) -> bool
    {
        return array_key_exists(offset, this->values);
    }

    public function offsetGet(mixed offset) -> mixed
    {
        return this->values[offset];
    }

    public function offsetSet(mixed offset, mixed value) -> void
    {
        if (offset === null) {
            let this->values[] = value;
        } else {
            let this->values[offset] = value;
        }
    }

    public function offsetUnset(mixed offset) -> void
    {
        unset(this->values[offset]);
    }

    /**
     * Resolve to an array, where each element has itself been lazy-resolved.
     *
     * @param object $container
     *
     * @return array<array-key, mixed>
     */
    public function resolve(object container) -> array
    {
        return this->resolveValues(container, this->values);
    }

    protected function resolveValue(object container, var value) -> mixed
    {
        if (typeof value === "object" && value instanceof Lazy) {
            return value->resolve(container);
        }

        if (is_array(value)) {
            return this->resolveValues(container, value);
        }

        return value;
    }

    /**
     * @param object                  $container
     * @param array<array-key, mixed> $values
     *
     * @return array
     */
    protected function resolveValues(object container, array values) -> array
    {
        var result, key, value;

        let result = [];

        for key, value in values {
            let result[key] = this->resolveValue(container, value);
        }

        return result;
    }
}
