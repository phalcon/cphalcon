
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR;

use Closure;
use Phalcon\ADR\Container\AdrProvider;
use Phalcon\ADR\Events\Event;
use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\Container\Container;
use Phalcon\Container\ContainerFactory;
use Phalcon\Contracts\ADR\ADRTypes;
use Phalcon\Contracts\ADR\Application as ApplicationInterface;
use Phalcon\Contracts\ADR\Dispatcher as DispatcherInterface;
use Phalcon\Contracts\ADR\Router\AttributeFilter as AttributeFilterInterface;
use Phalcon\Contracts\ADR\Router\Router as RouterInterface;
use Phalcon\Contracts\Events\Manager;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

/**
 * ADR composition root. Owns (or accepts) a container, exposes a small
 * registration surface that hides the container's definition API, configures
 * the convention router, and handles the request through the ADR flow.
 *
 * When no container is supplied one is created with the ADR defaults
 * (`AdrProvider`) registered. Type-hinted dependencies autowire; only scalar
 * parameters need to be declared via `define()`.
 *
 * @phpstan-import-type adr_definition_params from ADRTypes
 * @phpstan-import-type adr_middleware_map from ADRTypes
 */
final class Application implements ApplicationInterface
{
    protected string actionDirectory = "";
    protected string baseNamespace = "";
    protected <Container> container;

    /**
     * @phpstan-var adr_middleware_map
     */
    protected array middlewareMap = [];
    protected string wordSeparator = "";

    public function __construct(<Container> container = null)
    {
        if container === null {
            let container = (new ContainerFactory())
                ->addProvider(new AdrProvider())
                ->newContainer();
        }

        let this->container = container;
    }

    /**
     * Bind an interface to a concrete class.
     */
    public function bind(string interfaceName, string concrete) -> <static>
    {
        this->container->bind(interfaceName, concrete);

        return this;
    }

    /**
     * Register a class together with explicit values for its constructor
     * parameters. Type-hinted dependencies autowire; only the supplied
     * (usually scalar) parameters are declared. Lazy values (e.g.
     * `new Phalcon\Container\Resolver\Lazy\Env(...)`) may be passed as values.
     *
     * @phpstan-param adr_definition_params $parameters
     */
    public function define(string className, array parameters = []) -> <static>
    {
        var definition, param, value;

        let definition = this->container->set(className, className);

        for param, value in parameters {
            definition->setArgument(param, value);
        }

        return this;
    }

    /**
     * Register a post-build extender (decorator) for a service.
     */
    public function extend(string name, <Closure> extender) -> <static>
    {
        this->container->extend(name, extender);

        return this;
    }

    /**
     * Register a factory closure for a service.
     */
    public function factory(string name, <Closure> factory) -> <static>
    {
        this->container->set(name, factory);

        return this;
    }

    /**
     * Returns the underlying container for definition-level access.
     */
    public function getContainer() -> <Container>
    {
        return this->container;
    }

    /**
     * Routes the request, writes the matched attributes onto it, dispatches
     * the Action and returns the response. A single try/catch routes any error
     * through the error responder; if that itself fails, a bare 500 is returned
     * so nothing escapes uncaught.
     */
    public function handle(<AttributeRequest> request) -> <ResponseInterface>
    {
        var attributes, dispatcher, events, exception, key, match, 
            response, router, value;

        let router     = this->container->get(RouterInterface::class),
            dispatcher = this->container->get(DispatcherInterface::class),
            events     = this->container->get(Manager::class);

        if this->baseNamespace !== "" {
            router->setBaseNamespace(this->baseNamespace);
        }

        if !empty this->middlewareMap {
            router->setMiddlewareMap(this->middlewareMap);
        }

        if this->actionDirectory !== "" {
            router->setActionDirectory(this->actionDirectory);
        }

        if this->wordSeparator !== "" {
            router->setWordSeparator(this->wordSeparator);
        }

        /**
         * A reused request object (long-lived worker) keeps the attributes of
         * the previous route. Only the current match may fill the bag.
         */
        request->getAttributes()->clear();

        events->fire(Event::APPLICATION_BEFORE_HANDLE, this, request);

        try {
            let match = router->match(request);
            if match === null {
                throw new RouteNotFound();
            }

            let attributes = this->container
                ->get(AttributeFilterInterface::class)
                ->filter(match->getAction(), match->getAttributes());

            for key, value in attributes {
                request->getAttributes()->set(key, value);
            }

            let response = dispatcher->dispatch(
                match->getAction(),
                request,
                match->getMiddleware()
            );
        } catch \Throwable, exception {
            try {
                let response = this->container->get(ErrorResponder::class)->handle(
                    request,
                    new Response(),
                    exception
                );
            } catch \Throwable {
                let response = new Response();

                response->setStatusCode(500)->setContent("Internal Server Error");
            }
        }

        events->fire(Event::APPLICATION_AFTER_HANDLE, this, response);

        return response;
    }

    /**
     * Attach a guard (middleware) to every Action under a namespace prefix.
     */
    public function secureWith(string guard, string prefix) -> <static>
    {
        var list = [];

        if isset this->middlewareMap[prefix] {
            let list = this->middlewareMap[prefix];
        }

        let list[] = guard,
            this->middlewareMap[prefix] = list;

        return this;
    }

    /**
     * Register a service with a raw definition (class-string, closure or value).
     */
    public function set(string name, var definition) -> <static>
    {
        this->container->set(name, definition);

        return this;
    }

    /**
     * Set the filesystem root that backs the base namespace.
     */
    public function setActionDirectory(string actionDirectory) -> <static>
    {
        let this->actionDirectory = actionDirectory;

        return this;
    }

    /**
     * Set the base namespace the convention router derives Actions from.
     */
    public function setBaseNamespace(string baseNamespace) -> <static>
    {
        let this->baseNamespace = baseNamespace;

        return this;
    }

    /**
     * Set the single delimiter between words in a path segment.
     */
    public function setWordSeparator(string wordSeparator) -> <static>
    {
        let this->wordSeparator = wordSeparator;

        return this;
    }
}
