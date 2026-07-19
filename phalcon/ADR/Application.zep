
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
use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\Contracts\ADR\Application as ApplicationInterface;
use Phalcon\Contracts\ADR\Dispatcher as DispatcherInterface;
use Phalcon\Contracts\ADR\Router\Router as RouterInterface;
use Phalcon\Contracts\Events\Manager;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

/**
 * Routes the request, writes the matched attributes onto it, dispatches the
 * Action and returns the response. A single try/catch routes any error through
 * the error responder; if that itself fails, a bare 500 is returned so nothing
 * escapes uncaught.
 */
final class Application implements ApplicationInterface
{
    /**
     * @var DispatcherInterface
     */
    protected dispatcher;

    /**
     * @var ErrorResponder
     */
    protected errorResponder;

    /**
     * @var Manager
     */
    protected events;

    /**
     * @var RouterInterface
     */
    protected router;

    public function __construct(
        <RouterInterface> router,
        <DispatcherInterface> dispatcher,
        <ErrorResponder> errorResponder,
        <Manager> events
    ) {
        let this->router         = router,
            this->dispatcher     = dispatcher,
            this->errorResponder = errorResponder,
            this->events         = events;
    }

    public function handle(<AttributeRequest> request) -> <ResponseInterface>
    {
        var match, response, key, value, exception;

        this->events->fire(Event::APPLICATION_BEFORE_HANDLE, this, request);

        try {
            let match = this->router->match(request);
            if match === null {
                throw new RouteNotFound();
            }

            for key, value in match->getAttributes() {
                request->getAttributes()->set(key, value);
            }

            let response = this->dispatcher->dispatch(
                match->getAction(), 
                request, 
                match->getMiddleware()
            );
        } catch \Throwable, exception {
            try {
                let response = this->errorResponder->handle(
                    request, 
                    new Response(), 
                    exception
                );
            } catch \Throwable {
                let response = new Response();

                response->setStatusCode(500)->setContent("Internal Server Error");
            }
        }

        this->events->fire(Event::APPLICATION_AFTER_HANDLE, this, response);

        return response;
    }
}
