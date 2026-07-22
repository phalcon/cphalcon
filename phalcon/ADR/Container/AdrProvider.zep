
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

namespace Phalcon\ADR\Container;

use Phalcon\ADR\Dispatcher;
use Phalcon\ADR\Emitter\SapiEmitter;
use Phalcon\ADR\Responder\JsonResponder;
use Phalcon\ADR\Router\Router;
use Phalcon\Contracts\ADR\Dispatcher as DispatcherContract;
use Phalcon\Contracts\ADR\Emitter\Emitter as EmitterContract;
use Phalcon\Contracts\ADR\Responder\Responder as ResponderContract;
use Phalcon\Contracts\ADR\Router\Router as RouterContract;
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Contracts\Container\Service\Provider;
use Phalcon\Contracts\Events\Manager as EventsManagerContract;
use Phalcon\Contracts\Http\AttributeRequest as RequestContract;
use Phalcon\Contracts\Logger\Logger as LoggerContract;
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Html\Escaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\TagFactory;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Logger\Adapter\Noop;
use Phalcon\Logger\Logger;

/**
 * Registers the ADR seams in the container; concretes autowire.
 *
 * Used instead of `Phalcon\Container\Provider\Web` for ADR applications. It
 * shares the short aliases (`request`/`response`/`router`/`eventsManager`) but
 * binds the ADR contracts behind them.
 */
class AdrProvider implements Provider
{
    /**
     * @param Collection $services
     *
     * @return void
     */
    public function provide(<Collection> services) -> void
    {
        // Native events manager
        services->bind(EventsManagerContract::class, EventsManager::class);
        services->setAlias(EventsManagerContract::class, "eventsManager");

        // Request (attribute-bearing) and response
        services->bind(RequestContract::class, Request::class);
        services->setAlias(RequestContract::class, "request");

        services->bind(ResponseInterface::class, Response::class);
        services->setAlias(ResponseInterface::class, "response");

        // HTML escaper and tag helpers - a view needs them, the container
        // autowires the factory from the escaper binding
        services->bind(EscaperInterface::class, Escaper::class);
        services->setAlias(EscaperInterface::class, "escaper");

        services->set(TagFactory::class, TagFactory::class);
        services->setAlias(TagFactory::class, "tag");

        // Logger default - null sink until the application binds its own
        services->set(
            LoggerContract::class,
            function (container) {
                var adapters, noop;

                let noop     = new Noop(),
                    adapters = ["main" : noop];

                return new Logger("adr", adapters);
            }
        );

        // Default responder
        services->bind(ResponderContract::class, JsonResponder::class);
        services->setAlias(ResponderContract::class, "responder");

        // Dispatcher - handed the container instance and the events manager
        services->set(
            DispatcherContract::class,
            function (container) {
                return new Dispatcher(
                    container,
                    container->get(EventsManagerContract::class)
                );
            }
        );
        services->setAlias(DispatcherContract::class, "dispatcher");

        // Router
        services->bind(RouterContract::class, Router::class);
        services->setAlias(RouterContract::class, "router");

        // Emitter
        services->bind(EmitterContract::class, SapiEmitter::class);
        services->setAlias(EmitterContract::class, "emitter");
    }
}
