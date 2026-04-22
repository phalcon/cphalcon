
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
