
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Di\Exception\AutowireException;
use Phalcon\Di\AutowireTypesProviderInterface;
use Phalcon\Di\Exception\BindException;

class Autowire implements AutowireInterface
{
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

    /**
     * @var bool
     */
    protected bindClassInterfaces;

    /**
     * @var array
     */
    protected binds = [] {set, get};

    public function __construct(array binds = [], bool bindClassInterfaces = false, bool useShared = false)
    {
        let this->useShared = useShared;
        let this->bindClassInterfaces = bindClassInterfaces;
        this->addBinds(binds);
    }

    public function resolveMethod(<DiInterface> container, object obj, string method, array parameters = []) -> var
    {
        var methodParameters, callParameters, autowireTypes = [];

        let methodParameters = this->resolveMethodParamters(obj, method);

        if empty methodParameters {
            obj->{method}();
            return;
        }

        if obj instanceof AutowireTypesProviderInterface || obj instanceof AutowireTypesStaticProviderInterface {
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

        if is_subclass_of(className, "Phalcon\Di\AutowireTypesStaticProviderInterface") {
            let autowireTypes = array_merge(autowireTypes, {className}::getAutowireTypes());
        }

        let instanceParameters = this->prepareCallParameters(container, constructorParamters, parameters, autowireTypes);

        return create_instance_params(className, instanceParameters);
    }

    protected function resolveMethodParamters(object obj, string method) -> array
    {
        string keyCache;
        var reflection, parameters = [], objClass;

        let objClass = get_class(obj);
        let keyCache = str_replace("\\", "-", objClass) . "_" . method;

        /**
         * If keyCache is pretty long let's create sha1 of it to avoid storing long keys while caching
         */
        if keyCache->length() > this->maxKeyLength {
            let keyCache = keyCache->sha1();
        }

        let parameters = this->fetchParamsFromCache(keyCache);

        if parameters !== null {
            return parameters;
        }

        try {
            let reflection = new \ReflectionMethod(objClass, method);
        } catch \ReflectionException {
            throw new AutowireException("Class '" . objClass . "' does not have method '" . method . "'");
        }

        return this->resolveReflectionParamters(reflection->getParameters(), keyCache);
    }

    protected function fetchParamsFromCache(string key) -> array | null
    {
        if isset this->localCache[key] {
            return this->localCache[key];
        }

        return null;
    }

    protected function resolveConstructorParameters(string! className) -> array
    {
        string keyCache;
        var reflection, constructor, parameters;

        let keyCache = str_replace("\\", "-", className);

        /**
         * If keyCache is pretty long let's create sha1 of it to avoid storing long keys while caching
         */
        if keyCache->length() > this->maxKeyLength {
            let keyCache = keyCache->sha1();
        }

        let parameters = this->fetchParamsFromCache(keyCache);

        if parameters !== null {
            return parameters;
        }

        let reflection = new \ReflectionClass(className);

        if unlikely !reflection->isInstantiable() {
            throw new AutowireException("Class '" . className . "' is not instantiable ");
        }

        let constructor = reflection->getConstructor();

        if constructor === null {
            let this->localCache[className] = [];

            return [];
        }

        return this->resolveReflectionParamters(constructor->getParameters(), keyCache);
    }

    protected function resolveReflectionParamters(array reflectionParameters, string keyCache) -> array
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

        return parameters;
    }

    protected function prepareCallParameters(<DiInterface> container, array methodParameters, array parameters, array autowireTypes = []) -> array
    {
        var bind, useShared, parameterClass, parameterOptional, parameterDefault, parameterName, parameterHasDefault,
            autowireType, instanceParameters = [], parameter;

        let useShared = this->useShared;

        for parameter in methodParameters {
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

                if this->hasBind(parameterClass, autowireType) {
                    let bind = this->getBind(parameterClass, autowireType);
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
                throw new AutowireException("Missing value for parameter '" . parameterName . "'");
            }
        }

        return instanceParameters;
    }

    public function bind(string !className, var definition, bool isShared = false) -> <AutowireInterface>
    {
        var interfaces, singleInterface;

        if unlikely !class_exists(className) && !interface_exists(className) {
            throw new BindException("Bind class or interface '" . className . "' does not exist");
        }

        if typeof definition === "object" && definition instanceof BindDefinitionInterface {
            let this->binds[className][definition->getDefinition()] = definition;
        } elseif typeof definition === "string" {
            let this->binds[className][definition] = new BindDefinition(
                className,
                definition,
                isShared
            );
        } else {
            throw new BindException("Definition should be a string or object implementing BindDefinitionInterface");
        }

        if this->bindClassInterfaces && class_exists(className) {
            let interfaces = class_implements(className);

            for singleInterface in interfaces {
                this->bind(singleInterface, definition, isShared);
            }
        }

        return this;
    }

    public function hasBind(string! className, string definition = null) -> bool
    {
        if definition != null {
            if likely isset this->binds[className][definition] {
                return true;
            }

            throw new BindException("Implementation '" . definition . "' does not exists for class '" . className . "'");
        }

        return isset this->binds[className];
    }

    public function getBind(string! className, string definition = null) -> <BindDefinitionInterface> | null
    {
        if definition != null {
            if likely isset this->binds[className][definition] {
                return this->binds[className][definition];
            }

            throw new BindException("Implementation '" . definition . "' does not exists for class '" . className . "'");
        }

        if isset this->binds[className] {
            if unlikely count(this->binds[className]) > 1 {
                throw new BindException(
                    "More than one possible definitions for class '" . className . "', please provide
                     which implementation should be used for this class using setAutowireTypes on service or implement
                     one of the inerfaces - Phalcon\Di\AutowireTypesProviderInterface or Phalcon\Di\AutowireTypesStaticProviderInterface
                     depending if this is __construct or method autowiring"
                );
            }

            return array_values(this->binds[className])[0];
        }

        return null;
    }

    public function addBinds(array binds, bool replace = false) -> void
    {
        var className, definition, subdefinition;

        for className, definition in binds {
            if isset this->binds[className] && replace {
                let this->binds[className] = [];
            }

            if typeof definition === "array" {
                for subdefinition in definition {
                    this->bind(className, subdefinition);
                }
            } else {
                this->bind(className, definition);
            }
        }
    }
}
