
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, service-interop
 * and resolver-interop. These have been copied and implemented here since
 * PHP extensions cannot have more than one namespace.
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

use ArrayIterator;
use Phalcon\Container\Resolver\Lazy\Lazy;

class ArrayValues extends Lazy implements \ArrayAccess, \Countable, \IteratorAggregate
{
    /**
     * @var array
     */
    protected values = [];

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

    public function merge(var values) -> void
    {
        var key, value;

        for key, value in values {
            if typeof key == "integer" {
                let this->values[] = value;
            } else {
                let this->values[key] = value;
            }
        }
    }

    public function offsetExists(mixed offset) -> bool
    {
        return isset(this->values[offset]);
    }

    public function offsetGet(mixed offset) -> mixed
    {
        return this->values[offset];
    }

    public function offsetSet(mixed offset, mixed value) -> void
    {
        if offset === null {
            let this->values[] = value;
        } else {
            let this->values[offset] = value;
        }
    }

    public function offsetUnset(mixed offset) -> void
    {
        unset(this->values[offset]);
    }

    public function resolve(object container) -> array
    {
        return this->resolveValues(container, this->values);
    }

    protected function resolveValue(object container, var value) -> var
    {
        if value instanceof Lazy {
            return value->resolve(container);
        }

        if typeof value == "array" {
            return this->resolveValues(container, value);
        }

        return value;
    }

    protected function resolveValues(object container, array values) -> array
    {
        var key, value, result;

        let result = [];

        for key, value in values {
            let result[key] = this->resolveValue(container, value);
        }

        return result;
    }
}
