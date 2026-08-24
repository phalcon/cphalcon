
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

namespace Phalcon\ADR\Responder;

use Phalcon\Contracts\ADR\Payload\Payload;
use Phalcon\Contracts\ADR\Responder\Responder;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Applies a `Redirect` value object carried on the payload result: sets the
 * status code and the `Location` header. A no-op when the result is not a
 * redirect.
 */
class RedirectResponder implements Responder
{
    public function __invoke(
        <RequestInterface> request, 
        <ResponseInterface> response, 
        <Payload> payload
    ) -> <ResponseInterface> {
        var result, url;

        let result = payload->getResult();
        if typeof result == "object" && result instanceof Redirect {
            let url = result->url();

            /**
             * An internal redirect must not honor an absolute (scheme:) or
             * protocol-relative (//host) target, otherwise a request-derived
             * value such as "//evil.tld" or "http://evil.tld" becomes an open
             * redirect (CWE-601). This mirrors Http\Response::redirect(). An
             * explicit external redirect opts out of the gate.
             */
            if !result->external() &&
                preg_match("~^(?:[a-z][a-z0-9+.\\-]*:|//)~i", url) {
                let url = "/";
            }

            response
                ->setStatusCode(result->status())
                ->setHeader("Location", url);
        }

        return response;
    }
}
