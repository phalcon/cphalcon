
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

namespace Phalcon\ADR\Kernel;

use Phalcon\ADR\Container\AdrProvider;
use Phalcon\Container\Container;
use Phalcon\Contracts\ADR\Kernel\Kernel;

/**
 * Boots a container, resolves the Application, handles the request and emits the
 * response. Userland kernels override `loadEnvironment()` / `registerProviders()`;
 * bootstrap is `exit((new AppKernel(dirname(__DIR__)))->run());`.
 */
abstract class AbstractHttpKernel implements Kernel
{
    /**
     * @var string
     */
    protected projectRoot;

    public function __construct(string projectRoot)
    {
        let this->projectRoot = projectRoot;
    }

    final public function run() -> int
    {
        var container, request, application, response, exception;

        try {
            let container = this->buildContainer();

            this->loadEnvironment(container);
            this->registerProviders(container);

            let request     = container->get("request"),
                application = container->get("Phalcon\\ADR\\Application"),
                response    = application->handle(request);

            container->get("Phalcon\\Contracts\\ADR\\Emitter\\Emitter")->emit(response);

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
