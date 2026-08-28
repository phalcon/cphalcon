
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
use Phalcon\Contracts\Container\ContainerTypes;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Contracts\Container\Service\Enumerable;
use Phalcon\Di\InjectionAwareInterface;
use ReflectionException;

/**
 * @phpstan-import-type container_aliases from ContainerTypes
 * @phpstan-import-type container_instance_lifetimes from ContainerTypes
 * @phpstan-import-type container_instances from ContainerTypes
 * @phpstan-import-type container_parameters from ContainerTypes
 * @phpstan-import-type container_processors from ContainerTypes
 * @phpstan-import-type container_service_names from ContainerTypes
 * @phpstan-import-type container_service_tags from ContainerTypes
 * @phpstan-import-type container_services from ContainerTypes
 * @phpstan-import-type container_tagged_services from ContainerTypes
 */
class Container implements Collection, Enumerable
{
    /**
     * @phpstan-var container_aliases
     */
    protected array aliases = [];
    protected bool autowire = true;
    /**
     * @phpstan-var container_instance_lifetimes
     */
    protected array instanceLifetimes = [];
    /**
     * @phpstan-var container_instances
     */
    protected array instances = [];
    /**
     * @phpstan-var container_parameters
     */
    protected array parameters = [];
    /**
     * @phpstan-var container_processors
     */
    protected array processors = [];
    protected <Resolver> resolver;
    /**
     * @phpstan-var container_services
     */
    protected array services = [];
    /**
     * @phpstan-var container_service_tags
     */
    protected array tags = [];

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
     */
    public function bind(string interfaceName, string concrete) -> <ServiceDefinition>
    {
        return this->set(interfaceName, concrete);
    }

    /**
     * Resolve to a closure on a get()
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
     * @phpstan-return container_tagged_services
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
     */
    public function getResolver() -> <Resolver>
    {
        return this->resolver;
    }

    /**
     * Resolve an return a service
     *
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
     * Returns the names of every registered service definition. Names that
     * only exist as an alias, a pre-set instance or a parameter are not
     * included.
     *
     * @phpstan-return container_service_names
     */
    public function getServiceNames() -> array
    {
        return array_keys(this->services);
    }

    /**
     * Does the container have a particular service
     *
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
     */
    public function hasAlias(string name) -> bool
    {
        return array_key_exists(name, this->aliases);
    }

    /**
     * Does the service have a definition
     */
    public function hasDefinition(string name) -> bool
    {
        return array_key_exists(name, this->services);
    }

    /**
     * Does the service have an instance
     */
    public function hasInstance(string name) -> bool
    {
        return array_key_exists(name, this->instances);
    }

    /**
     * Does the service have a parameter
     */
    public function hasParameter(string name) -> bool
    {
        return array_key_exists(name, this->parameters);
    }

    /**
     * Does the container have a particular service
     *
     * @throws CircularAliasFound
     */
    public function hasService(string serviceName) -> bool
    {
        return this->has(serviceName);
    }

    /**
     * Is AutoWiring enabled
     */
    public function isAutowireEnabled() -> bool
    {
        return this->autowire;
    }

    /**
     * Resolve and return a new service
     *
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
     */
    public function newDefinition(string name) -> <ServiceDefinition>
    {
        return new ServiceDefinition(name, "string");
    }

    /**
     * Set a service
     *
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
     */
    public function setAutowire(bool enabled) -> <static>
    {
        let this->autowire = enabled;

        return this;
    }

    /**
     * Set a definition
     */
    public function setDefinition(string name, <ServiceDefinition> definition) -> <static>
    {
        let this->services[name] = definition;

        return this;
    }

    /**
     * Set an instance
     */
    public function setInstance(string name, object instance, string lifetime) -> <static>
    {
        let this->instances[name]         = instance;
        let this->instanceLifetimes[name] = lifetime;

        return this;
    }

    /**
     * Set a parameter
     */
    public function setParameter(string name, var value) -> <static>
    {
        let this->parameters[name] = value;

        return this;
    }

    /**
     * Register a tag with a service
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
     */
    public function unsetAlias(string name) -> void
    {
        unset(this->aliases[name]);
    }

    /**
     * Remove a definition
     */
    public function unsetDefinition(string name) -> void
    {
        unset(this->services[name]);
    }

    /**
     * Remove an instance
     */
    public function unsetInstance(string name) -> void
    {
        unset(this->instances[name]);
        unset(this->instanceLifetimes[name]);
    }

    /**
     * Remove instances based on lifetime
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
     */
    public function unsetParameter(string name) -> void
    {
        unset(this->parameters[name]);
    }

    /**
     * Detect circular aliases
     *
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

        /**
         * `setDI()` only accepts a `Phalcon\Di\DiInterface` and this container
         * is not one, so this always raised a `TypeError` for an injection
         * aware service.
         */
        // if (instance instanceof InjectionAwareInterface) {
        //     instance->setDI(this);
        // }

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
