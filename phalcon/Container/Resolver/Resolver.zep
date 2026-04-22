
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

namespace Phalcon\Container\Resolver;

use Closure;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Interop\Resolver\ResolverService;
use Phalcon\Container\Resolver\Lazy\Lazy;
use ReflectionClass;
use ReflectionFunction;
use ReflectionNamedType;

class Resolver implements ResolverService
{
    public function isResolvableClass(string! className) -> bool
    {
        var reflection;

        if !class_exists(className) {
            return false;
        }

        let reflection = new \ReflectionClass(className);

        return reflection->isInstantiable();
    }

    public function resolveCall(object container, var callableObject, array arguments) -> var
    {
        var closure, reflection, params, resolved;

        if callableObject instanceof Closure {
            let closure = callableObject;
        } else {
            let closure = Closure::fromCallable(callableObject);
        }

        let reflection = new ReflectionFunction(closure);
        let params     = reflection->getParameters();
        let resolved   = this->resolveParameters(container, params, arguments);

        return call_user_func_array(callableObject, resolved);
    }

    public function resolveClass(object container, string! className, array arguments) -> object
    {
        var reflection, constructor, params, resolved;

        let reflection  = new ReflectionClass(className);
        let constructor = reflection->getConstructor();

        if constructor === null {
            return reflection->newInstanceArgs([]);
        }

        let params   = constructor->getParameters();
        let resolved = this->resolveParameters(container, params, arguments);

        return reflection->newInstanceArgs(resolved);
    }

    public function resolveMethod(object container, var method, object obj) -> void
    {
        var params, resolved;

        let params   = method->getParameters();
        let resolved = this->resolveParameters(container, params, []);

        method->invokeArgs(obj, resolved);
    }

    public function resolveParameter(object container, var parameter) -> var
    {
        var type, typeName, declaringClass;

        let type = parameter->getType();

        if type instanceof ReflectionNamedType && !type->isBuiltin() {
            let typeName = type->getName();

            if method_exists(container, "has") && container->has(typeName) {
                return container->get(typeName);
            }
        }

        if parameter->isOptional() {
            return parameter->getDefaultValue();
        }

        let declaringClass = parameter->getDeclaringClass();

        throw Invalid::cannotResolveParameter(
            parameter->getName(),
            declaringClass !== null ? declaringClass->getName() : "unknown"
        );
    }

    public function resolveParameters(object container, array parameters, array arguments) -> array
    {
        var position, parameter, name, resolved;

        let resolved = [];

        for position, parameter in parameters {
            let name = parameter->getName();

            if array_key_exists(position, arguments) {
                let resolved[position] = this->resolveArg(container, arguments[position]);
                continue;
            }

            if array_key_exists(name, arguments) {
                let resolved[position] = this->resolveArg(container, arguments[name]);
                continue;
            }

            let resolved[position] = this->resolveParameter(container, parameter);
        }

        return resolved;
    }

    public function resolveType(object container, var type) -> mixed
    {
        if type instanceof ReflectionNamedType {
            return type->getName();
        }

        return null;
    }

    private function resolveArg(object container, var arg) -> var
    {
        if arg instanceof Lazy {
            return arg->resolve(container);
        }

        return arg;
    }
}
