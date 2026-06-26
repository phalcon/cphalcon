
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

namespace Phalcon\Container;

use Closure;
use Phalcon\Container\Definition\Processor\ClosureProcessor;
use Phalcon\Container\Definition\Processor\ObjectProcessor;
use Phalcon\Container\Definition\Processor\Processor;
use Phalcon\Container\Definition\Processor\StringProcessor;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Definition\ServiceLifetime;
use Phalcon\Container\Exceptions\CannotExtendResolved;
use Phalcon\Container\Exceptions\CircularAliasFound;
use Phalcon\Container\Exceptions\InstanceNotFound;
use Phalcon\Container\Exceptions\NoProcessorFound;
use Phalcon\Container\Exceptions\ParameterNotFound;
use Phalcon\Container\Exceptions\ServiceNotFound;
use Phalcon\Container\Exceptions\ServiceNotRegistered;
use Phalcon\Container\Resolver\Lazy\Lazy;
use Phalcon\Container\Resolver\Resolver;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Di\InjectionAwareInterface;
use ReflectionException;

class Container implements Collection
{
    /**
     * @var array<string, string>
     */
    protected aliases = [];
    /**
     * @var bool
     */
    protected autowire = true;
    /**
     * @var array<string, string>
     */
    protected instanceLifetimes = [];
    /**
     * @var array<string, object>
     */
    protected instances = [];
    /**
     * @var array<string, mixed>
     */
    protected parameters = [];
    /**
     * @var array<string, Processor>
     */
    protected processors = [];
    /**
     * @var Resolver
     */
    protected resolver;
    /**
     * @var array<string, ServiceDefinition>
     */
    protected services = [];
    /**
     * @var array<string, list<string>>
     */
    protected tags = [];

    public function __construct()
    {
        let this->resolver   = new Resolver();
        let this->processors = [
            new ObjectProcessor(),
            new ClosureProcessor(),
            new StringProcessor()
        ];
    }

    /**
     * Bind an interface to a concrete class
     *
     * @param string $interface
     * @param string $concrete
     *
     * @return ServiceDefinition
     */
    public function bind(string interfaceName, string concrete) -> <ServiceDefinition>
    {
        return this->set(interfaceName, concrete);
    }

    /**
     * Resolve to a closure on a get()
     *
     * @param string $name
     *
     * @return Closure
     */
    public function callableGet(string name) -> <Closure>
    {
        var serviceName;

        let serviceName = name;

        return function () use (serviceName) {
            return this->get(serviceName);
        };
    }

    /**
     * Resolve to a closure on a new()
     * @param string $name
     *
     * @return Closure
     */
    public function callableNew(string name) -> <Closure>
    {
        var serviceName;

        let serviceName = name;

        return function () use (serviceName) {
            return this->$new(serviceName);
        };
    }

    /**
     * Extends the definition
     *
     * @param string   $name
     * @param callable $callable
     *
     * @return void
     * @throws CannotExtendResolved
     * @throws ServiceNotFound
     */
    public function extend(string name, callable callableObject) -> void
    {
        let name = this->resolveAlias(name);

        if (array_key_exists(name, this->instances)) {
            throw new CannotExtendResolved(name);
        }

        if (!array_key_exists(name, this->services)) {
            throw new ServiceNotFound(name);
        }

        this->services[name]->addExtender(callableObject);
    }

    /**
     * Resolve and return an element registerd in the container
     *
     * @param string $name
     *
     * @return mixed
     * @throws ServiceNotFound
     */
    public function get(string name) -> mixed
    {
        let name = this->resolveAlias(name);

        if (array_key_exists(name, this->parameters)) {
            return this->resolveParameter(name);
        }

        if (array_key_exists(name, this->instances)) {
            return this->instances[name];
        }

        return this->resolve(name, true);
    }

    /**
     * Return an alias
     *
     * @param string $name
     *
     * @return string
     */
    public function getAlias(string name) -> string
    {
        var alias;

        if (fetch alias, this->aliases[name]) {
            return alias;
        }

        return "";
    }

    /**
     * Return services by tag
     *
     * @param string $tag
     *
     * @return list<mixed>
     */
    public function getByTag(string tag) -> array
    {
        var names, result, serviceName;

        if (!fetch names, this->tags[tag]) {
            let names = [];
        }

        let result = [];

        for serviceName in names {
            let result[] = this->get(serviceName);
        }

        return result;
    }

    /**
     * Return the service definition
     *
     * @param string $name
     *
     * @return ServiceDefinition
     * @throws ServiceNotFound
     */
    public function getDefinition(string name) -> <ServiceDefinition>
    {
        if (!array_key_exists(name, this->services)) {
            throw new ServiceNotFound(name);
        }

        return this->services[name];
    }

    /**
     * Return a stored instance
     *
     * @param string $name
     *
     * @return object
     * @throws InstanceNotFound
     */
    public function getInstance(string name) -> object
    {
        if (!array_key_exists(name, this->instances)) {
            throw new InstanceNotFound(name);
        }

        return this->instances[name];
    }

    /**
     * Return a parameter
     *
     * @param string $name
     *
     * @return mixed
     * @throws ParameterNotFound
     */
    public function getParameter(string name) -> mixed
    {
        if (!array_key_exists(name, this->parameters)) {
            throw new ParameterNotFound(name);
        }

        return this->resolveParameter(name);
    }

    /**
     * Return the resolver
     *
     * @return Resolver
     */
    public function getResolver() -> <Resolver>
    {
        return this->resolver;
    }

    /**
     * Resolve an return a service
     *
     * @param string $serviceName
     *
     * @return object
     * @throws ServiceNotFound
     * @throws ServiceNotRegistered
     */
    public function getService(string serviceName) -> object
    {
        var result;

        let result = this->get(serviceName);

        if (!is_object(result)) {
            throw new ServiceNotRegistered(serviceName);
        }

        return result;
    }

    /**
     * Does the container have a particular service
     *
     * @param string $name
     *
     * @return bool
     * @throws CircularAliasFound
     */
    public function has(string name) -> bool
    {
        let name = this->resolveAlias(name);

        if (
            array_key_exists(name, this->parameters)
            || array_key_exists(name, this->instances)
            || array_key_exists(name, this->services)
        ) {
            return true;
        }

        return this->autowire && this->resolver->isResolvableClass(name);
    }

    /**
     * Does the service have an alias
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasAlias(string name) -> bool
    {
        return array_key_exists(name, this->aliases);
    }

    /**
     * Does the service have a definition
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasDefinition(string name) -> bool
    {
        return array_key_exists(name, this->services);
    }

    /**
     * Does the service have an instance
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasInstance(string name) -> bool
    {
        return array_key_exists(name, this->instances);
    }

    /**
     * Does the service have a parameter
     *
     * @param string $name
     *
     * @return bool
     */
    public function hasParameter(string name) -> bool
    {
        return array_key_exists(name, this->parameters);
    }

    /**
     * Does the container have a particular service
     *
     * @param string $serviceName
     *
     * @return bool
     * @throws CircularAliasFound
     */
    public function hasService(string serviceName) -> bool
    {
        return this->has(serviceName);
    }

    /**
     * Is AutoWiring enabled
     *
     * @return bool
     */
    public function isAutowireEnabled() -> bool
    {
        return this->autowire;
    }

    /**
     * Resolve and return a new service
     *
     * @param string $name
     *
     * @return mixed
     * @throws CircularAliasFound
     * @throws ReflectionException
     * @throws ServiceNotFound
     */
    public function $new(string name) -> mixed
    {
        let name = this->resolveAlias(name);

        return this->resolve(name, false);
    }

    /**
     * Return a new service definition
     *
     * @param string $name
     *
     * @return ServiceDefinition
     */
    public function newDefinition(string name) -> <ServiceDefinition>
    {
        return new ServiceDefinition(name, "string");
    }

    /**
     * Set a service
     *
     * @param string $name
     * @param mixed  $definition
     *
     * @return ServiceDefinition
     * @throws NoProcessorFound
     */
    public function set(string name, var definition) -> <ServiceDefinition>
    {
        var processor, def;

        let processor = this->findProcessor(definition);
        let def       = processor->process(name, definition, this);
        def->setContainer(this);

        let this->services[name] = def;

        return def;
    }

    /**
     * Set an alias
     *
     * @param string $name
     * @param string $alias
     *
     * @return static
     * @throws CircularAliasFound
     */

    public function setAlias(string name, string alias) -> <static>
    {
        this->detectCircularAlias(alias, name);
        let this->aliases[alias] = name;

        return this;
    }

    /**
     * Set AutoWire
     *
     * @param bool $enabled
     *
     * @return static
     */
    public function setAutowire(bool enabled) -> <static>
    {
        let this->autowire = enabled;

        return this;
    }

    /**
     * Set a definition
     *
     * @param string            $name
     * @param ServiceDefinition $definition
     *
     * @return static
     */
    public function setDefinition(string name, <ServiceDefinition> definition) -> <static>
    {
        let this->services[name] = definition;

        return this;
    }

    /**
     * Set an instance
     *
     * @param string $name
     * @param object $instance
     * @param string $lifetime
     *
     * @return static
     */
    public function setInstance(string name, object instance, string lifetime) -> <static>
    {
        let this->instances[name]         = instance;
        let this->instanceLifetimes[name] = lifetime;

        return this;
    }

    /**
     * Set a parameter
     *
     * @param string $name
     * @param mixed  $value
     *
     * @return static
     */
    public function setParameter(string name, var value) -> <static>
    {
        let this->parameters[name] = value;

        return this;
    }

    /**
     * Register a tag with a service
     *
     * @param string $tag
     * @param string $serviceName
     *
     * @return void
     */
    public function setTag(string tag, string serviceName) -> void
    {
        if (!array_key_exists(tag, this->tags)) {
            let this->tags[tag] = [];
        }

        if (!in_array(serviceName, this->tags[tag], true)) {
            let this->tags[tag][] = serviceName;
        }
    }

    /**
     * Remove an alias
     *
     * @param string $name
     *
     * @return void
     */
    public function unsetAlias(string name) -> void
    {
        unset(this->aliases[name]);
    }

    /**
     * Remove a definition
     *
     * @param string $name
     *
     * @return void
     */
    public function unsetDefinition(string name) -> void
    {
        unset(this->services[name]);
    }

    /**
     * Remove an instance
     *
     * @param string $name
     *
     * @return void
     */
    public function unsetInstance(string name) -> void
    {
        unset(this->instances[name]);
        unset(this->instanceLifetimes[name]);
    }

    /**
     * Remove instances based on lifetime
     *
     * @param string $lifetime
     *
     * @return void
     */
    public function unsetInstances(string lifetime) -> void
    {
        var name, instanceLifetime;

        for name, instanceLifetime in this->instanceLifetimes {
            if (instanceLifetime === lifetime) {
                unset(this->instances[name]);
                unset(this->instanceLifetimes[name]);
            }
        }
    }

    /**
     * Remove a parameter
     *
     * @param string $name
     *
     * @return void
     */
    public function unsetParameter(string name) -> void
    {
        unset(this->parameters[name]);
    }

    /**
     * Detect circular aliases
     *
     * @param string $alias
     * @param string $target
     *
     * @return void
     * @throws CircularAliasFound
     */
    private function detectCircularAlias(string alias, string target) -> void
    {
        var current, seen;

        let current = target;
        let seen    = [];

        while (true) {
            if (current === alias) {
                throw new CircularAliasFound(alias);
            }

            if (array_key_exists(current, seen)) {
                break;
            }

            if (!array_key_exists(current, this->aliases)) {
                break;
            }

            let seen[current] = true;
            let current       = this->aliases[current];
        }
    }

    /**
     * Locate a processor
     *
     * @param mixed $definition
     *
     * @return Processor
     * @throws NoProcessorFound
     */
    private function findProcessor(var definition) -> <Processor>
    {
        var processor;

        for processor in this->processors {
            if (processor->canProcess(definition)) {
                return processor;
            }
        }

        throw new NoProcessorFound();
    }

    /**
     * Resolve the service
     *
     * @param string $name
     * @param bool   $cache
     *
     * @return mixed
     * @throws ServiceNotFound
     * @throws ReflectionException
     */
    private function resolve(string name, bool cache) -> mixed
    {
        var definition, instance, lifetime;

        if (!array_key_exists(name, this->services)) {
            if (this->autowire && class_exists(name)) {
                this->set(name, name);
            } else {
                throw new ServiceNotFound(name);
            }
        }

        let definition = this->services[name];
        definition->freeze(this);

        let instance = definition->buildService(this);

        if (instance instanceof InjectionAwareInterface) {
            instance->setDI(this);
        }

        let lifetime = definition->getLifetime();

        if (cache && lifetime !== ServiceLifetime::TRANSIENT) {
            let this->instances[name]         = instance;
            let this->instanceLifetimes[name] = lifetime;
        }

        return instance;
    }

    /**
     * Resolve an alias
     *
     * @param string $name
     *
     * @return string
     * @throws CircularAliasFound
     */
    private function resolveAlias(string name) -> string
    {
        var seen, current;

        let seen    = [];
        let current = name;

        while (array_key_exists(current, this->aliases)) {
            if (array_key_exists(current, seen)) {
                throw new CircularAliasFound(name);
            }

            let seen[current] = true;
            let current       = this->aliases[current];
        }

        return current;
    }

    /**
     * Resolve a paramater
     *
     * @param string $name
     *
     * @return mixed
     */
    private function resolveParameter(string name) -> mixed
    {
        var value, resolved;

        let value = this->parameters[name];

        if (typeof value === "object" && value instanceof Lazy) {
            let resolved               = value->resolve(this);
            let this->parameters[name] = resolved;

            return resolved;
        }

        return value;
    }
}
