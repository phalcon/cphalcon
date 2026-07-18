
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
use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\ResponseInterface;

/**
 * Ensures every request carries an `X-Request-Id`, reusing an incoming one or
 * generating it, exposing it on the request attributes and the response.
 */
class RequestIdMiddleware implements Middleware
{
    public function __invoke(<AttributeRequestInterface> request, <Handler> next) -> <ResponseInterface>
    {
        var id, response;

        let id = request->getHeader("X-Request-Id");
        if empty id {
            let id = bin2hex(random_bytes(16));
        }

        request->getAttributes()->set("requestId", id);

        let response = next->__invoke(request);
        response->setHeader("X-Request-Id", id);

        return response;
    }
}
