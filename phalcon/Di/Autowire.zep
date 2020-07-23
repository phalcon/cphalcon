
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Cache\Adapter\AdapterInterface;
use Phalcon\Di\Exception\AutowireException;

class Autowire implements AutowireInterface
{
    /**
     * @var AdapterInterface|null
     */
    protected cache;

    /**
     * @var bool
     */
    protected useShared;

    /**
     * @var array
     */
    protected localCache = [];

    /**
     * @var int
     */
    protected maxKeyLength = 250;

    public function __construct(<AdapterInterface> cache = null, bool useShared = false)
    {
        let this->cache = cache;
        let this->useShared = useShared;
    }

    public function resolveMethod(<DiInterface> container, object obj, string method, array parameters = []) -> var
    {
        var methodParameters, useShared, callParameters, bind, autowireTypes = [];

        let methodParameters = this->resolveMethodParamters(obj, method);

        if empty methodParameters {
            obj->{method}();
            return;
        }

        if obj instanceof AutowireTypesProviderInterface {
            let autowireTypes = obj->getAutowireTypes();
        }

        let callParameters = this->prepareCallParameters(container, methodParameters, parameters, autowireTypes);

        return call_user_func_array([obj, method], callParameters);
    }

    public function resolve(<DiInterface> container, string! className, array parameters = [], array autowireTypes = []) -> object
    {
        var constructorParamters, instanceParameters;

        if unlikely !class_exists(className) {
            throw new AutowireException(
                "Class '" . className . "' wasn't found by autowire compomenent"
            );
        }

        let constructorParamters = this->resolveConstructorParameters(className);

        if empty constructorParamters {
            return create_instance(className);
        }

        let instanceParameters = this->prepareCallParameters(container, constructorParamters, parameters, autowireTypes);

        return create_instance_params(className, instanceParameters);
    }

    protected function resolveMethodParamters(object obj, string method) -> array
    {
        var cache, reflection, parameters = [], key, parameter, keyCache, objClass;

        let objClass = get_class(obj);
        let keyCache = get_class(obj) . "::" . method;
        let cache = this->cache;

        let parameters = this->fetchParamsFromCache(keyCache, cache);

        if !empty parameters {
            return parameters;
        }

        try {
            let reflection = new \ReflectionMethod(objClass, method);
        } catch \ReflectionException {
            throw new AutowireException("Class '" . objClass . "' does not have method '" . method . "'");
        }

        return this->resolveReflectionParamters(reflection->getParameters(), keyCache, cache);
    }

    protected function fetchParamsFromCache(string key, <AdapterInterface> cache = null) -> array
    {
        if isset this->localCache[key] {
            return this->localCache[key];
        }

        if cache != null && cache->has(key) {
            let parameters = cache->get(key);
            let this->localCache[key] = parameters;

            return parameters;
        }

        return [];
    }

    protected function resolveConstructorParameters(string! className) -> array
    {
        var cache, reflection, constructor, parameters, keyCache;

        let cache = this->cache;
        let keyCache = className;

        /**
         * If className is pretty long let's create sha1 of it to avoid storing long keys while caching
         */
        if className->length() > this->maxKeyLength {
            let keyCache = className->sha1();
        }

        let parameters = this->fetchParamsFromCache(keyCache);

        if !empty parameters {
            return parameters;
        }

        let reflection = new \ReflectionClass(className);

        if unlikely !reflection->isInstantiable() {
            throw new AutowireException("Class '" . className . "' is not instantiable ");
        }

        let constructor = reflection->getConstructor();

        if constructor === null {
            if cache != null {
                cache->set(className, []);
            }

            let this->localCache[className] = [];

            return [];
        }

        return this->resolveReflectionParamters(constructor->getParameters(), keyCache, cache);
    }

    protected function resolveReflectionParamters(array reflectionParameters, string keyCache, <AdapterInterface> cache = null) -> array
    {
        var parameters = [], parameter;

        for parameter in reflectionParameters {
            let parameters[] = [
                "name" : parameter->getName(),
                "class" : parameter->getClass() ? parameter->getClass()->name : null,
                "optional" : parameter->isOptional(),
                "hasDefault" : parameter->isDefaultValueAvailable(),
                "default" : parameter->isDefaultValueAvailable() ? parameter->getDefaultValue() : null
            ];
        }

        let this->localCache[keyCache] = parameters;

        if cache != null {
            cache->set(keyCache, parameters);
        }

        return parameters;
    }

    protected function prepareCallParameters(<DiInterface> container, array methodParameters, array parameters, array autowireTypes = []) -> array
    {
        var bind, useShared, parameterClass, parameterOptional, parameterDefault, parameterName, parameterHasDefault,
            autowireType, instanceParameters = [], parameter;

        let useShared = this->useShared;

        for parameter in constructorParamters {
            let parameterClass = parameter["class"],
                parameterName = parameter["name"],
                parameterOptional = parameter["optional"],
                parameterDefault = parameter["default"],
                parameterHasDefault = parameter["hasDefault"],
                autowireType = null;

            if parameterClass {
                /**
                 * Check if any bind exists for this class
                 */
                if isset autowireTypes[parameterClass] {
                    let autowireType = autowireTypes[parameterClass];
                }

                if container->hasBind(parameterClass, autowireType) {
                    let bind = container->getBind(parameterClass, autowireType);
                    let instanceParameters[] = bind->resolve(container);
                } else {
                    if useShared {
                        let instanceParameters[] = container->getShared(parameterClass);
                    } else {
                        let instanceParameters[] = container->get(parameterClass);
                    }
                }
            } elseif isset parameters[parameterName] {
                let instanceParameters[] = parameters[parameterName];
            } elseif parameterHasDefault {
                let instanceParameters[] = parameterDefault;
            } else {
                throw new AutowireException("Missing parameter value for '" . parameterName . "'");
            }
        }

        return instanceParameters;
    }
}
