
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

namespace Phalcon\Container\Interop\Resolver;

use Phalcon\Container\Interop\Resolver\ReflectionParameterResolver;

interface ResolverService extends ReflectionParameterResolver
{
    public function isResolvableClass(string! className) -> bool;

    public function resolveCall(object ioc, var callableObject, array arguments) -> var;

    public function resolveClass(object ioc, string! className, array arguments) -> object;

    public function resolveMethod(object ioc, var method, object obj) -> void;

    public function resolveParameters(object ioc, array parameters, array arguments) -> array;

    public function resolveType(object ioc, var type) -> var;
}
