
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Support;

use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Di\DiInterface;
use Throwable;

/**
 * Abstract base class for service locators.
 *
 * Provides a unified way to register, validate, and resolve services
 * from a DI container, with support for both legacy Di and new Container.
 *
 * @template T of object
 */
abstract class AbstractLocator
{
    /**
     * @var Collection|DiInterface
     */
    protected container;

    /**
     * @phpstan-var array<string, class-string<T>>
     * @var array
     */
    protected services = [];

    /**
     * @phpstan-param array<string, class-string<T>> $services
     */
    public function __construct(
        var container,
        array services = []
    ) {
        if (!(container instanceof Collection) && !(container instanceof DiInterface)) {
            throw new \TypeError("The parameter must be an instance of Collection or DiInterface");
        }

        var definition, name;

        let this->container = container;
        let this->services  = this->getServices();

        for name, definition in services {
            this->register(name, definition);
        }
    }

    /**
     * Returns the full registered service map (defaults plus any added via
     * register()).
     *
     * @return array<string, class-string<T>>
     */
    public function getAll() -> array
    {
        return this->services;
    }

    /**
     * Returns the class-string registered under the given name.
     *
     * @return class-string<T>
     *
     * @throws Exception
     */
    public function getClass(string name) -> string
    {
        return this->getService(name);
    }

    /**
     * Whether a service with the given name is registered.
     */
    public function has(string name) -> bool
    {
        return isset(this->services[name]);
    }

    /**
     * Retrieve a service instance from the container.
     *
     * On the `DiInterface` path this returns the container's **shared**
     * instance (`getShared()`) — despite the name, it is not a fresh build.
     * Locators whose services carry per-activation state should override this
     * method to resolve a fresh instance; see `Auth\Access\AccessLocator`, which uses
     * `ContainerResolver::resolveFresh` for exactly that reason.
     *
     * @return T
     */
    public function newInstance(string name) -> object
    {
        var definition, exceptionClass;

        let definition = this->getService(name);

        if (true !== this->container->has(definition)) {
            let exceptionClass = this->getExceptionClass();
            throw new {exceptionClass}(
                "Service " . name . " was not found in the DI container"
            );
        }

        if (this->container instanceof DiInterface) {
            /** @var T */
            return this->container->getShared(definition);
        }

        /** @var T */
        return this->container->get(definition);
    }

    /**
     * Register a service or override an existing one.
     *
     * @phpstan-param class-string<T> $definition
     *
     * @throws Exception
     */
    public function register(string name, string definition) -> <static>
    {
        var exceptionClass, interfaceClass;

        let interfaceClass = this->getInterfaceClass();

        if (! is_subclass_of(definition, interfaceClass)) {
            let exceptionClass = this->getExceptionClass();
            throw new {exceptionClass}(
                "Definition " . definition
                . " must implement " . interfaceClass
            );
        }

        let this->services[name] = definition;

        return this;
    }

    /**
     * Get the exception class to throw on errors.
     *
     * @return class-string<Throwable>
     */
    abstract protected function getExceptionClass() -> string;

    /**
     * Get the interface/class that all registered services must implement.
     * This allows different locators to enforce different contracts.
     *
     * @return class-string
     */
    abstract protected function getInterfaceClass() -> string;

    /**
     * Get the service class name for a given name.
     *
     * @return class-string<T>
     *
     * @throws Exception
     */
    protected function getService(string name) -> string
    {
        var exceptionClass;

        if (! isset(this->services[name])) {
            let exceptionClass = this->getExceptionClass();
            throw new {exceptionClass}(
                "Service " . name . " is not registered"
            );
        }

        return this->services[name];
    }

    /**
     * Get the default services for this locator.
     *
     * @return array<string, class-string<T>>
     */
    abstract protected function getServices() -> array;
}
