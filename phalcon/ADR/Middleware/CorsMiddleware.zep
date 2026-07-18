
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

namespace Phalcon\ADR\Middleware;

use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\ADR\Middleware;
use Phalcon\Contracts\Http\AttributeRequestInterface;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;

/**
 * CORS middleware. Inert by default: it emits nothing until an origin allowlist
 * is configured, and only for requests whose `Origin` is on it. The allowed
 * origin is always echoed back explicitly, so credentials are never paired with
 * a wildcard origin. Preflight `OPTIONS` requests are answered directly.
 */
class CorsMiddleware implements Middleware
{
    /**
     * @var bool
     */
    protected allowCredentials = false;

    /**
     * @var array
     */
    protected allowedHeaders;

    /**
     * @var array
     */
    protected allowedMethods;

    /**
     * @var array
     */
    protected allowedOrigins;

    /**
     * @var int
     */
    protected maxAge = 0;

    public function __construct(array config = [])
    {
        let this->allowedOrigins   = isset config["origins"] ? config["origins"] : [],
            this->allowedMethods   = isset config["methods"] ? config["methods"] : ["GET", "POST", "PUT", "PATCH", "DELETE", "OPTIONS"],
            this->allowedHeaders   = isset config["headers"] ? config["headers"] : ["Content-Type", "Authorization"],
            this->allowCredentials = isset config["credentials"] ? (bool) config["credentials"] : false,
            this->maxAge           = isset config["maxAge"] ? (int) config["maxAge"] : 0;
    }

    public function __invoke(<AttributeRequestInterface> request, <Handler> next) -> <ResponseInterface>
    {
        var origin, response;

        let origin = request->getHeader("Origin");

        if empty origin || !this->isAllowed(origin) {
            return next->__invoke(request);
        }

        if "OPTIONS" === request->getMethod() {
            let response = new Response();
            response->setStatusCode(204);
            this->applyHeaders(response, origin);
            response->setHeader("Access-Control-Allow-Methods", implode(", ", this->allowedMethods));
            response->setHeader("Access-Control-Allow-Headers", implode(", ", this->allowedHeaders));

            if this->maxAge > 0 {
                response->setHeader("Access-Control-Max-Age", (string) this->maxAge);
            }

            return response;
        }

        let response = next->__invoke(request);
        this->applyHeaders(response, origin);

        return response;
    }

    protected function applyHeaders(<ResponseInterface> response, string origin) -> void
    {
        response->setHeader("Access-Control-Allow-Origin", origin);

        if this->allowCredentials {
            response->setHeader("Access-Control-Allow-Credentials", "true");
        }
    }

    protected function isAllowed(string origin) -> bool
    {
        if in_array("*", this->allowedOrigins, true) {
            return true;
        }

        return in_array(origin, this->allowedOrigins, true);
    }
}
