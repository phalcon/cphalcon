
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

namespace Phalcon\Container\Definition;

use Phalcon\Container\Exceptions\FrozenDefinition;
use Phalcon\Container\Exceptions\InvalidExtender;
use Phalcon\Container\Exceptions\NoClassSet;
use Phalcon\Container\Exceptions\NoFactorySet;
use ReflectionClass;
use ReflectionException;

class ServiceDefinition
{
    /**
     * @phpstan-var array<array-key, mixed>
     * @var array
     */
    protected arguments = [];
    /**
     * @var object | null
     */
    protected container = null;

    /**
     * @var string | null
     */
    protected className = null;
    /**
     * @var array
     */
    protected constructorArgs = [];
    /**
     * @var array<array-key, callable>
     */
    protected extenders  = [];

    /**
     * @var callable | null
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
    protected lifetime = ServiceLifetime::SCOPED;
    /**
     *  @var mixed
     */
    protected raw = null;
    /**
     *  @var string
     */
    protected serviceName;
    /**
     * @phpstan-var array<array-key, string>
     * @var array
     */
    protected tags = [];
    /**
     *  @var string
     */
    protected type;

    public function __construct(
        string serviceName,
        string type,
        var raw = null
    ) {
        let this->serviceName = serviceName;
        let this->type = type;
        let this->raw = raw;
    }

    /**
     * Adds an extender
     *
     * @param callable $extender
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function addExtender(callable extender) -> <static>
    {
        this->checkFrozen();
        let this->extenders[] = extender;

        return this;
    }

    /**
     * Adds a tag
     *
     * @param string $tag
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function addTag(string tag) -> <static>
    {
        this->checkFrozen();

        if (!in_array(tag, this->tags, true)) {
            let this->tags[] = tag;
        }

        if (
            this->container !== null
            && method_exists(this->container, "setTag")
        ) {
            this->container->setTag(tag, this->serviceName);
        }

        return this;
    }

    /**
     * Builds a service and returns the instance back
     *
     * @param object $container
     *
     * @return object
     * @throws ReflectionException
     */
    public function buildService(object container) -> object
    {
        var args, className, extender, factory, instance, reflection;

        if (this->hasFactory()) {
            let factory  = this->factory;
            let instance = {factory}(container);
        } else {
            let className  = this->className !== null ? this->className : this->serviceName;
            let args       = this->resolveArgs(container, this->constructorArgs);
            let reflection = new ReflectionClass(className);
            let instance   = reflection->newInstanceArgs(args);
        }

        for extender in this->extenders {
            let instance = {extender}(instance, container);
        }

        return instance;
    }

    /**
     * Freezes the container
     *
     * @param object $container
     *
     * @return void
     * @throws ReflectionException
     */
    public function freeze(object container) -> void
    {
        var className, constructor, params, reflection;

        if (this->frozen) {
            return;
        }

        if (
            this->type === DefinitionType::STRING_TYPE &&
            method_exists(container, "isAutowireEnabled") &&
            container->isAutowireEnabled()
        ) {
            let className   = this->className !== null ? this->className : this->serviceName;
            let reflection  = new ReflectionClass(className);
            let constructor = reflection->getConstructor();
            let params      = constructor !== null ? constructor->getParameters() : [];

            if (method_exists(container, "getResolver")) {
                let this->constructorArgs = container->getResolver()->resolveParameters(
                    container,
                    params,
                    this->arguments
                );
            }
        } elseif (this->type === DefinitionType::STRING_TYPE && !empty(this->arguments)) {
            let this->constructorArgs = this->arguments;
        }

        let this->frozen = true;
    }

    /**
     * Returns the arguments
     *
     * @return array
     */
    public function getArguments() -> array
    {
        return this->arguments;
    }

    /**
     * Returns the class
     *
     * @return string
     * @throws NoClassSet
     */
    public function getClass() -> string
    {
        if (this->className === null) {
            throw new NoClassSet(this->serviceName);
        }

        return this->className;
    }

    /**
     * Returns the constructor arguments
     *
     * @return array
     */
    public function getConstructorArgs() -> array
    {
        return this->constructorArgs;
    }

    /**
     * Returns the extenders
     *
     * @return array<array-key, callable>
     */
    public function getExtenders() -> array
    {
        return this->extenders;
    }

    /**
     * Returns the factory
     *
     * @return callable
     * @throws NoFactorySet
     */
    public function getFactory() -> callable
    {
        if (this->factory === null) {
            throw new NoFactorySet(this->serviceName);
        }

        return this->factory;
    }

    /**
     * Returns the lifetime
     *
     * @return string
     */
    public function getLifetime() -> string
    {
        return this->lifetime;
    }

    /**
     * Returns the name of the service
     *
     * @return string
     */
    public function getServiceName() -> string
    {
        return this->serviceName;
    }

    /**
     * Returns the tags
     *
     * @return array<array-key, string>
     */
    public function getTags() -> array
    {
        return this->tags;
    }

    /**
     * Returns the type
     *
     * @return string
     */
    public function getType() -> string
    {
        return this->type;
    }

    /**
     * Does it have a class
     *
     * @return bool
     */
    public function hasClass() -> bool
    {
        return this->className !== null;
    }

    /**
     * Do we have extenders
     *
     * @return bool
     */
    public function hasExtenders() -> bool
    {
        return !empty(this->extenders);
    }

    /**
     * Does it have a factory
     *
     * @return bool
     */
    public function hasFactory() -> bool
    {
        return this->factory !== null;
    }

    /**
     * Is it cacheable
     *
     * @return bool
     */
    public function isCacheable() -> bool
    {
        return this->isCacheable && this->frozen;
    }

    /**
     * Is it frozen
     *
     * @return bool
     */
    public function isFrozen() -> bool
    {
        return this->frozen;
    }

    /**
     * Set an argument
     *
     * @param int|string $param
     * @param mixed      $value
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function setArgument(var param, var value) -> <static>
    {
        this->checkFrozen();
        let this->arguments[param] = value;

        return this;
    }

    /**
     * Set the container
     *
     * @param object $container
     *
     * @return static
     */
    public function setContainer(object container) -> <static>
    {
        let this->container = container;

        return this;
    }

    /**
     * Set a class
     *
     * @param string $className
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function setClass(string className) -> <static>
    {
        this->checkFrozen();
        let this->className = className;

        return this;
    }

    /**
     * Set extenders
     *
     * @param array<array-key, callable> $extenders
     *
     * @return static
     * @throws FrozenDefinition
     * @throws InvalidExtender
     */
    public function setExtenders(array extenders) -> <static>
    {
        var extender, key;

        this->checkFrozen();

        for key, extender in extenders {
            if (!is_callable(extender)) {
                throw new InvalidExtender(this->serviceName, (string) key);
            }
        }

        let this->extenders = extenders;

        return this;
    }

    /**
     * Set a factory
     *
     * @param callable $factory
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function setFactory(callable factory) -> <static>
    {
        this->checkFrozen();
        let this->factory = factory;

        return this;
    }

    /**
     * Set cachable
     * @param bool $isCacheable
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function setIsCacheable(bool isCacheable) -> <static>
    {
        this->checkFrozen();
        let this->isCacheable = isCacheable;

        return this;
    }

    /**
     * Set lifetime
     *
     * @param string $lifetime
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function setLifetime(string lifetime) -> <static>
    {
        this->checkFrozen();
        let this->lifetime = lifetime;

        return this;
    }

    /**
     * Unset class
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function unsetClass() -> <static>
    {
        this->checkFrozen();
        let this->className = null;

        return this;
    }

    /**
     * Unset extenders
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function unsetExtenders() -> <static>
    {
        this->checkFrozen();
        let this->extenders = [];

        return this;
    }

    /**
     * Unset the factory
     *
     * @return static
     * @throws FrozenDefinition
     */
    public function unsetFactory() -> <static>
    {
        this->checkFrozen();
        let this->factory = null;

        return this;
    }

    /**
     * Check if frozen
     *
     * @return void
     * @throws FrozenDefinition
     */
    protected function checkFrozen() -> void
    {
        if (this->frozen) {
            throw new FrozenDefinition(this->serviceName);
        }
    }

    /**
     * Resolve arguments
     *
     * @param object $container
     * @param array  $args
     *
     * @return array
     */
    private function resolveArgs(object container, array args) -> array
    {
        var resolved, key, argument;

        let resolved = [];

        for key, argument in args {
            if (is_object(argument) && method_exists(argument, "resolve")) {
                let resolved[key] = argument->resolve(container);
            } else {
                let resolved[key] = argument;
            }
        }

        return resolved;
    }
}
