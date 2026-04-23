
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

namespace Phalcon\Container;

use Phalcon\Container\Definition\Processor\ClosureProcessor;
use Phalcon\Container\Definition\Processor\ObjectProcessor;
use Phalcon\Container\Definition\Processor\Processor;
use Phalcon\Container\Definition\Processor\StringProcessor;
use Phalcon\Container\Definition\ServiceDefinition;
use Phalcon\Container\Definition\ServiceLifetime;
use Phalcon\Container\Exception\Invalid;
use Phalcon\Container\Exception\NotFound;
use Phalcon\Container\Interop\Service\Collection;
use Phalcon\Container\Resolver\Lazy\Lazy;
use Phalcon\Container\Resolver\Resolver;
use Phalcon\Di\InjectionAwareInterface;
use RuntimeException;
use TypeError;

class Container implements Collection
{
    /**
     * @var array
     */
    protected aliases = [];
    /**
     * @var bool
     */
    protected autowire = true;
    /**
     * @var array
     */
    protected instanceLifetimes = [];
    /**
     * @var array
     */
    protected instances = [];
    /**
     * @var array
     */
    protected parameters = [];
    /**
     * @var array
     */
    protected processors = [];
    /**
     * @var Resolver
     */
    protected resolver;
    /**
     * @var array
     */
    protected services = [];
    /**
     * @var array
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

    public function bind(string! interfaceName, string! concrete) -> <ServiceDefinition>
    {
        return this->set(interfaceName, concrete);
    }

    public function callableGet(string! name) -> var
    {
        throw new RuntimeException("Not implemented: requires Zephir \$this-in-closure support");
    }

    public function callableNew(string! name) -> var
    {
        throw new RuntimeException("Not implemented: requires Zephir \$this-in-closure support");
    }

    public function extend(string! name, var callableObject) -> void
    {
        if unlikely !is_callable(callableObject) {
            throw new TypeError("Argument 'callableObject' must be callable");
        }

        let name = this->resolveAlias(name);

        if isset(this->instances[name]) {
            throw Invalid::cannotExtendResolved(name);
        }

        if !isset(this->services[name]) {
            throw NotFound::serviceNotFound(name);
        }

        this->services[name]->addExtender(callableObject);
    }

    public function get(string! name) -> var
    {
        let name = this->resolveAlias(name);

        if array_key_exists(name, this->parameters) {
            return this->resolveParameter(name);
        }

        if isset(this->instances[name]) {
            return this->instances[name];
        }

        return this->resolve(name, true);
    }

    public function getAlias(string! name) -> string
    {
        if isset(this->aliases[name]) {
            return this->aliases[name];
        }

        return "";
    }

    public function getByTag(string! tag) -> array
    {
        var names, serviceName, result;

        if isset(this->tags[tag]) {
            let names = this->tags[tag];
        } else {
            let names = [];
        }

        let result = [];

        for serviceName in names {
            let result[] = this->get(serviceName);
        }

        return result;
    }

    public function getDefinition(string! name) -> <ServiceDefinition>
    {
        if !isset(this->services[name]) {
            throw NotFound::serviceNotFound(name);
        }

        return this->services[name];
    }

    public function getInstance(string! name) -> object
    {
        if !isset(this->instances[name]) {
            throw NotFound::instanceNotFound(name);
        }

        return this->instances[name];
    }

    public function getParameter(string! name) -> var
    {
        if !array_key_exists(name, this->parameters) {
            throw NotFound::parameterNotFound(name);
        }

        return this->resolveParameter(name);
    }

    public function getResolver() -> <Resolver>
    {
        return this->resolver;
    }

    public function getService(string! serviceName) -> object
    {
        var result;

        let result = this->get(serviceName);

        if !is_object(result) {
            throw Invalid::serviceNotFound(serviceName);
        }

        return result;
    }

    public function has(string! name) -> bool
    {
        let name = this->resolveAlias(name);

        if (array_key_exists(name, this->parameters)
            || isset(this->instances[name])
            || isset(this->services[name])
        ) {
            return true;
        }

        return this->autowire && this->resolver->isResolvableClass(name);
    }

    public function hasAlias(string! name) -> bool
    {
        return isset(this->aliases[name]);
    }

    public function hasDefinition(string! name) -> bool
    {
        return isset(this->services[name]);
    }

    public function hasInstance(string! name) -> bool
    {
        return isset(this->instances[name]);
    }

    public function hasParameter(string! name) -> bool
    {
        return array_key_exists(name, this->parameters);
    }

    public function hasService(string! serviceName) -> bool
    {
        return this->has(serviceName);
    }

    public function isAutowireEnabled() -> bool
    {
        return this->autowire;
    }

    public function $new(string! name) -> var
    {
        let name = this->resolveAlias(name);

        return this->resolve(name, false);
    }

    public function newDefinition(string! name) -> <ServiceDefinition>
    {
        return new ServiceDefinition(name, "string");
    }

    public function set(string! name, var definition) -> <ServiceDefinition>
    {
        var processor, def;

        let processor = this->findProcessor(definition);
        let def       = processor->process(name, definition, this);
        def->setContainer(this);

        let this->services[name] = def;

        return def;
    }

    public function setAlias(string! name, string! alias) -> <Container>
    {
        this->detectCircularAlias(alias, name);
        let this->aliases[alias] = name;

        return this;
    }

    public function setAutowire(bool enabled) -> <Container>
    {
        let this->autowire = enabled;

        return this;
    }

    public function setDefinition(string! name, <ServiceDefinition> definition) -> <Container>
    {
        let this->services[name] = definition;

        return this;
    }

    public function setInstance(string! name, object instance, string! lifetime) -> <Container>
    {
        let this->instances[name]         = instance;
        let this->instanceLifetimes[name] = lifetime;

        return this;
    }

    public function setParameter(string! name, var value) -> <Container>
    {
        let this->parameters[name] = value;

        return this;
    }

    public function setTag(string! tag, string! serviceName) -> void
    {
        var tagList;

        if !isset(this->tags[tag]) {
            let this->tags[tag] = [];
        }

        if !in_array(serviceName, this->tags[tag], true) {
            let tagList         = this->tags[tag];
            let tagList[]       = serviceName;
            let this->tags[tag] = tagList;
        }
    }

    public function unsetAlias(string! name) -> void
    {
        unset(this->aliases[name]);
    }

    public function unsetDefinition(string! name) -> void
    {
        unset(this->services[name]);
    }

    public function unsetInstance(string! name) -> void
    {
        unset(this->instances[name]);
        unset(this->instanceLifetimes[name]);
    }

    public function unsetInstances(string! lifetime) -> void
    {
        var name, lt, toUnset;

        let toUnset = [];

        for name, lt in this->instanceLifetimes {
            if lt === lifetime {
                let toUnset[] = name;
            }
        }

        for name in toUnset {
            unset(this->instances[name]);
            unset(this->instanceLifetimes[name]);
        }
    }

    public function unsetParameter(string! name) -> void
    {
        unset(this->parameters[name]);
    }

    private function detectCircularAlias(string! alias, string! target) -> void
    {
        var current, seen;

        let current = target;
        let seen    = [];

        loop {
            if current === alias {
                throw Invalid::circularAlias(alias);
            }

            if isset(seen[current]) {
                break;
            }

            if !isset(this->aliases[current]) {
                break;
            }

            let seen[current] = true;
            let current       = this->aliases[current];
        }
    }

    private function findProcessor(var definition) -> <Processor>
    {
        var processor;

        for processor in this->processors {
            if processor->canProcess(definition) {
                return processor;
            }
        }

        throw Invalid::noProcessorFound();
    }

    private function resolve(string! name, bool cache) -> var
    {
        var definition, instance, lifetime;

        if !isset(this->services[name]) {
            if this->autowire && class_exists(name) {
                this->set(name, name);
            } else {
                throw NotFound::serviceNotFound(name);
            }
        }

        let definition = this->services[name];
        definition->freeze(this);

        let instance = definition->buildService(this);

//  @todo wire the container with the framework
//        if instance instanceof InjectionAwareInterface {
//            instance->setDI(this);
//        }

        let lifetime = definition->getLifetime();

        if cache && lifetime !== ServiceLifetime::TRANSIENT {
            let this->instances[name]         = instance;
            let this->instanceLifetimes[name] = lifetime;
        }

        return instance;
    }

    private function resolveAlias(string! name) -> string
    {
        var seen, current;

        let seen    = [];
        let current = name;

        while isset(this->aliases[current]) {
            if isset(seen[current]) {
                throw Invalid::circularAlias(name);
            }

            let seen[current] = true;
            let current       = this->aliases[current];
        }

        return current;
    }

    private function resolveParameter(string! name) -> var
    {
        var value, resolved;

        let value = this->parameters[name];

        if is_object(value) && value instanceof Lazy {
            let resolved             = value->resolve(this);
            let this->parameters[name] = resolved;

            return resolved;
        }

        return value;
    }
}
