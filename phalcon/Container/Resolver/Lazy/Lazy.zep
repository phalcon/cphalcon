
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

use Phalcon\Container\Interop\Resolver\Resolvable;

abstract class Lazy implements Resolvable
{
    public function __invoke(object container) -> var
    {
        return this->resolve(container);
    }

    abstract public function resolve(object container) -> var;

    protected function resolveArgument(object container, var argument) -> var
    {
        if argument instanceof Lazy {
            return argument->resolve(container);
        }

        return argument;
    }

    protected function resolveArguments(object container, array arguments) -> array
    {
        var key, argument, resolved;

        let resolved = [];

        for key, argument in arguments {
            let resolved[key] = this->resolveArgument(container, argument);
        }

        return resolved;
    }
}