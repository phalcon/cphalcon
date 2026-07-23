
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

namespace Phalcon\ADR\Front;

use Phalcon\ADR\Application;
use Phalcon\ADR\Container\AdrProvider;
use Phalcon\Container\Container;
use Phalcon\Contracts\ADR\Application as ApplicationInterface;
use Phalcon\Contracts\ADR\Emitter\Emitter;
use Phalcon\Contracts\Front\FrontController;
use Phalcon\Contracts\Http\AttributeRequest;

/**
 * Boots a container, builds the Application, handles the request and emits the
 * response. Userland front controllers override `loadEnvironment()`,
 * `registerProviders()` and optionally `getApplication()`; bootstrap is
 * `exit((new AppFront(dirname(__DIR__)))->run());`.
 */
abstract class AbstractHttpFront implements FrontController
{
    /**
     * @var string
     */
    protected projectRoot;

    public function __construct(string projectRoot)
    {
        let this->projectRoot = projectRoot;
    }

    /**
     * @return int<0,254>
     */
    final public function run() -> int
    {
        var container, request, application, response, exception;

        try {
            let container = this->buildContainer();

            this->loadEnvironment(container);
            this->registerProviders(container);

            let request     = container->get(AttributeRequest::class),
                application = this->getApplication(container),
                response    = application->handle(request);

            container->get(Emitter::class)->emit(response);

            return 0;
        } catch \Throwable, exception {
            return this->handleBootError(exception);
        }

        return 0;
    }

    protected function buildContainer() -> <Container>
    {
        return new Container();
    }

    /**
     * Builds the Application the front will hand the request to. Override to
     * configure it (`setBaseNamespace()`/`secureWith()`) or to wire a different
     * `Phalcon\Contracts\ADR\Application` implementation.
     */
    protected function getApplication(<Container> container) -> <ApplicationInterface>
    {
        return new Application(container);
    }

    protected function handleBootError(<\Throwable> exception) -> int
    {
        error_log((string) exception);

        if !headers_sent() {
            http_response_code(500);
            header("Content-Type: text/plain; charset=utf-8");
            echo "Internal Server Error\n";
        }

        return 1;
    }

    protected function loadEnvironment(<Container> container) -> void
    {
    }

    protected function registerProviders(<Container> container) -> void
    {
        (new AdrProvider())->provide(container);
    }
}
