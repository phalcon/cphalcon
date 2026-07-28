
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

use Phalcon\ADR\Events\Event;
use Phalcon\ADR\Exceptions\NotAnAction;
use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\ADR\Dispatcher as DispatcherInterface;
use Phalcon\Contracts\Container\Ioc\IocContainer;
use Phalcon\Contracts\Events\Manager;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\ResponseInterface;

/**
 * Resolves the Action (and middleware) through the container, wraps it in the
 * pipeline and runs it, firing the `pipeline:*` events. Global middleware is
 * resolved once and cached; only route middleware resolves per request.
 *
 * The container resolution is the one deliberate Service Locator: it uses the
 * resolve-only `IocContainer` contract, so a container swap is a two-method
 * adapter. Everything else is constructor-injected.
 */
final class Dispatcher implements DispatcherInterface
{
    protected <IocContainer> container;
    protected <Manager> events;
    /**
     * @var array
     */
    protected array globalMiddleware;
    /**
     * @var array|null
     */
    protected ?array resolvedGlobal = null;

    public function __construct(
        <IocContainer> container, 
        <Manager> events, 
        array globalMiddleware = []
    ) {
        let this->container        = container,
            this->events           = events,
            this->globalMiddleware = globalMiddleware;
    }

    public function dispatch(
        string actionClass, 
        <AttributeRequest> request, 
        array routeMiddleware = []
    ) -> <ResponseInterface> {
        var action, middleware, terminal, pipeline, response;

        let action = this->container->getService(actionClass);
        if !(action instanceof Action) {
            throw new NotAnAction(actionClass);
        }

        let middleware = array_merge(this->resolveGlobal(), this->resolveAll(routeMiddleware)),
            terminal   = new EventfulHandler(action, this->events),
            pipeline   = new Pipeline(middleware, terminal);

        this->events->fire(Event::PIPELINE_BEFORE_DISPATCH, this, request);

        let response = pipeline->__invoke(request);

        this->events->fire(Event::PIPELINE_AFTER_DISPATCH, this, response);

        return response;
    }

    protected function resolveAll(array classes) -> array
    {
        var className;
        array result;

        for className in classes {
            let result[] = this->container->getService(className);
        }

        return result;
    }

    protected function resolveGlobal() -> array
    {
        if null === this->resolvedGlobal {
            let this->resolvedGlobal = this->resolveAll(this->globalMiddleware);
        }

        return this->resolvedGlobal;
    }
}
