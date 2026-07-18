
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
 * Thin enabler for the native `_method` override.
 *
 * `Request::getMethod()` already honors `X-HTTP-Method-Override` and, when the
 * parameter-override flag is on, the `_method` field. This middleware only
 * turns that flag on, and only for a `POST` request whose `_method` names a
 * safe verb (`PUT`/`PATCH`/`DELETE`), so `_method` cannot spoof an arbitrary
 * method.
 */
class MethodOverrideMiddleware implements Middleware
{
    /**
     * @var array
     */
    protected allowed = ["DELETE", "PATCH", "PUT"];

    public function __invoke(<AttributeRequestInterface> request, <Handler> next) -> <ResponseInterface>
    {
        var spoofed;

        if "POST" === request->getMethod() {
            let spoofed = strtoupper((string) request->getPost("_method"));

            if in_array(spoofed, this->allowed, true) {
                request->setHttpMethodParameterOverride(true);
            }
        }

        return next->__invoke(request);
    }
}
