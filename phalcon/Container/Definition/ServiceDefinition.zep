
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
namespace Phalcon\Container\Definition;

use Phalcon\Container\Definition\DefinitionType;
use Phalcon\Container\Definition\ServiceLifetime;
use Phalcon\Container\Exception\Invalid;
use ReflectionClass;
use TypeError;

class ServiceDefinition
{
    /**
     * @var array
     */
    protected arguments = [];
    /**
     * @var string|null
     */
    protected className = null;
    /**
     * @var object|null
     */
    protected container = null;
    /**
     * @var array
     */
    protected constructorArgs = [];
    /**
     * @var array
     */
    protected extenders = [];
    /**
     * @var callable|null
     */
    protected factory = null;
    /**
     * @var bool
     */
    protected frozen = false;
    /**
     * @var bool
     */
    protected isCacheable = false;
    /**
     * @var string
     */
    protected lifetime;
    /**
     * @var mixed
     */
    protected raw = null;
    /**
     * @var string
     */
    protected serviceName;
    /**
     * @var array
     */
    protected tags = [];
    /**
     * @var string
     */
    protected type;

    public function __construct(string! serviceName, string! type, var raw = null)
    {
        let this->serviceName = serviceName;
        let this->type        = type;
        let this->raw         = raw;
        let this->lifetime    = ServiceLifetime::SCOPED;
    }

    public function addExtender(var extender) -> <ServiceDefinition>
    {
        if unlikely !is_callable(extender) {
            throw new TypeError("Argument 'extender' must be callable");
        }

        this->checkFrozen();
        let this->extenders[] = extender;

        return this;
    }

    public function addTag(string! tag) -> <ServiceDefinition>
    {
        this->checkFrozen();

        if !in_array(tag, this->tags, true) {
            let this->tags[] = tag;
        }

        if this->container !== null && method_exists(this->container, "setTag") {
            this->container->setTag(tag, this->serviceName);
        }

        return this;
    }

    public function buildService(object container) -> object
    {
        var args, classValue, extender, factory, instance, reflection;

        if this->hasFactory() {
            let factory  = this->factory;
            let instance = {factory}(container);
        } else {
            let classValue = this->className !== null ? this->className : this->serviceName;
            let args       = this->resolveArgs(container, this->constructorArgs);
            let reflection = new ReflectionClass(classValue);
            let instance   = reflection->newInstanceArgs(args);
        }

        for extender in this->extenders {
            let instance = {extender}(instance, container);
        }

        return instance;
    }

    public function freeze(object container) -> void
    {
        var classValue, reflection, constructor, params;

        if this->frozen {
            return;
        }

        if (this->type === DefinitionType::DEF_STRING
            && method_exists(container, "isAutowireEnabled")
            && container->isAutowireEnabled()
        ) {
            let classValue  = this->className !== null ? this->className : this->serviceName;
            let reflection  = new ReflectionClass(classValue);
            let constructor = reflection->getConstructor();
            let params      = constructor !== null ? constructor->getParameters() : [];

            if method_exists(container, "getResolver") {
                let this->constructorArgs = container->getResolver()->resolveParameters(
                    container,
                    params,
                    this->arguments
                );
            }
        } elseif this->type === DefinitionType::DEF_STRING && !empty(this->arguments) {
            let this->constructorArgs = this->arguments;
        }

        let this->frozen = true;
    }

    public function getArguments() -> array
    {
        return this->arguments;
    }

    public function getClass() -> string
    {
        if this->className === null {
            throw Invalid::noClassSet(this->serviceName);
        }

        return this->className;
    }

    public function getConstructorArgs() -> array
    {
        return this->constructorArgs;
    }

    public function getExtenders() -> array
    {
        return this->extenders;
    }

    public function getFactory() -> var
    {
        if this->factory === null {
            throw Invalid::noFactorySet(this->serviceName);
        }

        return this->factory;
    }

    public function getLifetime() -> string
    {
        return this->lifetime;
    }

    public function getServiceName() -> string
    {
        return this->serviceName;
    }

    public function getTags() -> array
    {
        return this->tags;
    }

    public function getType() -> string
    {
        return this->type;
    }

    public function hasClass() -> bool
    {
        return this->className !== null;
    }

    public function hasExtenders() -> bool
    {
        return !empty(this->extenders);
    }

    public function hasFactory() -> bool
    {
        return this->factory !== null;
    }

    public function isCacheable() -> bool
    {
        return this->isCacheable && this->frozen;
    }

    public function isFrozen() -> bool
    {
        return this->frozen;
    }

    public function setArgument(var param, var value) -> <ServiceDefinition>
    {
        if unlikely (typeof param !== "integer" && typeof param !== "string") {
            throw new TypeError("Argument 'param' must be int or string");
        }

        this->checkFrozen();
        let this->arguments[param] = value;

        return this;
    }

    public function setClass(string! classValue) -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->className = classValue;

        return this;
    }

    public function setContainer(var container) -> <ServiceDefinition>
    {
        if unlikely (typeof container !== "object" && container !== null) {
            throw new TypeError("Argument 'container' must be object or null");
        }

        let this->container = container;

        return this;
    }

    public function setExtenders(array extenders) -> <ServiceDefinition>
    {
        var key, extender;

        this->checkFrozen();

        for key, extender in extenders {
            if !is_callable(extender) {
                throw Invalid::invalidExtender(this->serviceName, key);
            }
        }

        let this->extenders = extenders;

        return this;
    }

    public function setFactory(var factory) -> <ServiceDefinition>
    {
        if unlikely !is_callable(factory) {
            throw new TypeError("Argument 'factory' must be callable");
        }

        this->checkFrozen();
        let this->factory = factory;

        return this;
    }

    public function setIsCacheable(bool isCacheable) -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->isCacheable = isCacheable;

        return this;
    }

    public function setLifetime(string! lifetime) -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->lifetime = lifetime;

        return this;
    }

    public function unsetClass() -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->className = null;

        return this;
    }

    public function unsetExtenders() -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->extenders = [];

        return this;
    }

    public function unsetFactory() -> <ServiceDefinition>
    {
        this->checkFrozen();
        let this->factory = null;

        return this;
    }

    protected function checkFrozen() -> void
    {
        if this->frozen {
            throw Invalid::frozenDefinition(this->serviceName);
        }
    }

    private function resolveArgs(object container, array args) -> array
    {
        var key, arg, resolved;

        let resolved = [];

        for key, arg in args {
            if is_object(arg) && method_exists(arg, "resolve") {
                let resolved[key] = arg->resolve(container);
            } else {
                let resolved[key] = arg;
            }
        }

        return resolved;
    }
}