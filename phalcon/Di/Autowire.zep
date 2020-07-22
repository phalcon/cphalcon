
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

    public function resolve(<DiInterface> container, string! className, array parameters = [], array autowireTypes = []) -> object
    {
        var constructorParamters, parameter, instanceParameters, autowireType, parameterClass,
            parameterOptional, parameterDefault, parameterName, parameterHasDefault, useShared, bind;

        if unlikely !class_exists(className) {
            throw new AutowireException(
                "Class '" . className . "' wasn't found by autowire compomenent"
            );
        }

        let constructorParamters = this->resolveConstructorParameters(className);
        let useShared = this->useShared;

        if empty constructorParamters {
            return create_instance(className);
        }

        let instanceParameters = [];

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

        return create_instance_params(className, instanceParameters);
    }

    protected function resolveConstructorParameters(string! className) -> array
    {
        var cache, reflection, constructor, reflectionParameters, parameters, key, parameter;

        let cache = this->cache;

        /**
         * If className is pretty long let's create sha1 of it to avoid storing long keys while caching
         */
        if className->length() > this->maxKeyLength {
            let className = className->sha1();
        }

        if isset this->localCache[className] {
            return this->localCache[className];
        }

        if cache != null && cache->has("PHAW!" . className) {
            let parameters = cache->get("PHAW!" . className);
            let this->localCache[className] = parameters;

            return parameters;
        }

        let reflection = new \ReflectionClass(className);
        let constructor = reflection->getConstructor();

        if constructor === null {
            if cache != null {
                cache->set("PHAW!" . className, []);
            }

            let this->localCache[className] = [];

            return [];
        }

        let reflectionParameters = constructor->getParameters();
        let parameters = [];

        for parameter in reflectionParameters {
            let parameters[] = [
                "name" : parameter->getName(),
                "class" : parameter->getClass() ? parameter->getClass()->name : null,
                "optional" : parameter->isOptional(),
                "hasDefault" : parameter->isDefaultValueAvailable(),
                "default" : parameter->isDefaultValueAvailable() ? parameter->getDefaultValue() : null
            ];
        }

        let this->localCache[className] = parameters;

        if cache != null {
            cache->set("PHAW!" . className, parameters);
        }

        return parameters;
    }
}
