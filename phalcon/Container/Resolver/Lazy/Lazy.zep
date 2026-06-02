
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

use Phalcon\Contracts\Container\Resolver\Resolvable;

abstract class Lazy implements Resolvable
{
    public function __invoke(object ioc) -> mixed
    {
        return this->resolve(ioc);
    }

    abstract public function resolve(object ioc) -> mixed;

    protected function resolveArgument(object ioc, var argument) -> mixed
    {
        if (typeof argument === "object" && argument instanceof Lazy) {
            return argument->resolve(ioc);
        }

        return argument;
    }

    /**
     * @param object                  $ioc
     * @param array<array-key, mixed> $arguments
     *
     * @return array<array-key, mixed>
     */
    protected function resolveArguments(object ioc, array arguments) -> array
    {
        var resolved, key, argument;

        let resolved = [];

        for key, argument in arguments {
            let resolved[key] = this->resolveArgument(ioc, argument);
        }

        return resolved;
    }
}
