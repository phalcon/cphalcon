
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
use Phalcon\Http\ResponseInterface;

/**
 * Adds an `X-Response-Time` header measuring how long the rest of the pipeline
 * took to produce the response.
 */
class TimingMiddleware implements Middleware
{
    public function __invoke(<AttributeRequestInterface> request, <Handler> next) -> <ResponseInterface>
    {
        var start, response, elapsed;

        let start    = microtime(true),
            response = next->__invoke(request),
            elapsed  = (microtime(true) - start) * 1000.0;

        response->setHeader("X-Response-Time", sprintf("%.2fms", elapsed));

        return response;
    }
}
