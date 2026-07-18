
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
use Phalcon\Contracts\Container\Service\Collection;
use Phalcon\Contracts\Container\Service\Provider;
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
        services->bind(
            "Phalcon\\Contracts\\Events\\Manager", 
            "Phalcon\\Events\\Manager"
        );
        services->setAlias("Phalcon\\Contracts\\Events\\Manager", "eventsManager");

        // Request (attribute-bearing) and response
        services->bind(
            "Phalcon\\Contracts\\Http\\AttributeRequestInterface", 
            "Phalcon\\Http\\Request"
        );
        services->setAlias(
            "Phalcon\\Contracts\\Http\\AttributeRequestInterface", 
            "request"
        );

        services->bind("Phalcon\\Http\\ResponseInterface", "Phalcon\\Http\\Response");
        services->setAlias("Phalcon\\Http\\ResponseInterface", "response");

        // Logger default - null sink until the application binds its own
        services->set(
            "Phalcon\\Contracts\\Logger\\Logger",
            function (container) {
                var adapters, noop;

                let noop     = new Noop(),
                    adapters = ["main" : noop];

                return new Logger("adr", adapters);
            }
        );

        // Default responder
        services->bind(
            "Phalcon\\Contracts\\ADR\\Responder\\Responder", 
            "Phalcon\\ADR\\Responder\\JsonResponder"
        );
        services->setAlias("Phalcon\\Contracts\\ADR\\Responder\\Responder", "responder");

        // Dispatcher - handed the container instance and the events manager
        services->set(
            "Phalcon\\Contracts\\ADR\\Dispatcher",
            function (container) {
                return new Dispatcher(container, container->get("eventsManager"));
            }
        );
        services->setAlias("Phalcon\\Contracts\\ADR\\Dispatcher", "dispatcher");

        // Router
        services->bind(
            "Phalcon\\Contracts\\ADR\\Router\\Router", 
            "Phalcon\\ADR\\Router\\Router"
        );
        services->setAlias("Phalcon\\Contracts\\ADR\\Router\\Router", "router");

        // Emitter
        services->bind(
            "Phalcon\\Contracts\\ADR\\Emitter\\Emitter", 
            "Phalcon\\ADR\\Emitter\\SapiEmitter"
        );
        services->setAlias("Phalcon\\Contracts\\ADR\\Emitter\\Emitter", "emitter");
    }
}
