
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

namespace Phalcon\Container\Resolver;

use Closure;
use Phalcon\Container\Exceptions\CannotResolveParameter;
use Phalcon\Container\Resolver\Lazy\Lazy;
use Phalcon\Contracts\Container\Resolver\ResolverService;
use ReflectionClass;
use ReflectionException;
use ReflectionFunction;
use ReflectionMethod;
use ReflectionNamedType;
use ReflectionParameter;
use ReflectionType;

class Resolver implements ResolverService
{
    /**
     * Is this a resolvable class?
     *
     * @param string $className
     *
     * @return bool
     */
    public function isResolvableClass(string className) -> bool
    {
        if (!class_exists(className)) {
            return false;
        }

        return (new ReflectionClass(className))->isInstantiable();
    }

    /**
     * Resolve a call
     *
     * @param object   $ioc
     * @param callable $callable
     * @param array    $arguments
     *
     * @return mixed
     * @throws ReflectionException
     */
    public function resolveCall(
        object ioc,
        callable callableObject,
        array arguments
    ) -> mixed {
        var closure, reflection, params, resolved;

        let closure    = callableObject instanceof Closure
            ? callableObject
            : Closure::fromCallable(callableObject);
        let reflection = new ReflectionFunction(closure);
        let params     = reflection->getParameters();
        let resolved   = this->resolveParameters(ioc, params, arguments);

        return call_user_func_array(callableObject, resolved);
    }

    /**
     * Resolve a class
     *
     * @param object $ioc
     * @param string $className
     * @param array  $arguments
     *
     * @return object
     * @throws ReflectionException
     */
    public function resolveClass(
        object ioc,
        string className,
        array arguments
    ) -> object {
        var reflection, constructor, params, resolved;

        let reflection  = new ReflectionClass(className);
        let constructor = reflection->getConstructor();

        if (constructor === null) {
            return reflection->newInstanceArgs([]);
        }

        let params   = constructor->getParameters();
        let resolved = this->resolveParameters(ioc, params, arguments);

        return reflection->newInstanceArgs(resolved);
    }

    /**
     * Resolve a method
     *
     * @param object           $ioc
     * @param ReflectionMethod $method
     * @param object           $object
     *
     * @return void
     * @throws ReflectionException
     */
    public function resolveMethod(
        object ioc,
        <ReflectionMethod> method,
        object instance
    ) -> void {
        var params, resolved;

        let params   = method->getParameters();
        let resolved = this->resolveParameters(ioc, params, []);

        method->invokeArgs(instance, resolved);
    }

    /**
     * Resolve parameters
     *
     * @param object              $ioc
     * @param ReflectionParameter $parameter
     *
     * @return mixed
     * @throws CannotResolveParameter
     * @throws ReflectionException
     */
    public function resolveParameter(
        object ioc,
        <ReflectionParameter> parameter
    ) -> mixed {
        var type, typeName, declaringClass, declaringName;

        let type = parameter->getType();

        if (type instanceof ReflectionNamedType && !type->isBuiltin()) {
            let typeName = type->getName();

            if (method_exists(ioc, "has") && ioc->has(typeName)) {
                return ioc->get(typeName);
            }
        }

        if (parameter->isOptional()) {
            if (parameter->isDefaultValueAvailable()) {
                return parameter->getDefaultValue();
            }

            return null;
        }

        let declaringClass = parameter->getDeclaringClass();
        let declaringName  = declaringClass !== null ? declaringClass->getName() : "unknown";

        throw new CannotResolveParameter(
            parameter->getName(),
            declaringName
        );
    }

    public function resolveParameters(
        object ioc,
        array parameters,
        array arguments
    ) -> array {
        var resolved, position, parameter, name;

        let resolved = [];

        for position, parameter in parameters {
            let name = parameter->getName();

            if (array_key_exists(position, arguments)) {
                let resolved[position] = this->resolveArg(ioc, arguments[position]);
                continue;
            }

            if (array_key_exists(name, arguments)) {
                let resolved[position] = this->resolveArg(ioc, arguments[name]);
                continue;
            }

            let resolved[position] = this->resolveParameter(ioc, parameter);
        }

        return resolved;
    }

    /**
     * type is ReflectionType
     */
    public function resolveType(
        object ioc,
        var type
    ) -> mixed {
        if (type instanceof ReflectionNamedType) {
            return type->getName();
        }

        return null;
    }

    private function resolveArg(object ioc, var arg) -> mixed
    {
        if (typeof arg === "object" && arg instanceof Lazy) {
            return arg->resolve(ioc);
        }

        return arg;
    }
}
