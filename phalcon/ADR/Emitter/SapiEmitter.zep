
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

namespace Phalcon\ADR\Emitter;

use Phalcon\ADR\Emitter\Exceptions\HeadersAlreadySent;
use Phalcon\Contracts\ADR\Emitter\Emitter;
use Phalcon\Http\ResponseInterface;

/**
 * Emits a response through the SAPI (headers + body via `Response::send()`).
 * Refuses to emit once headers have already been sent.
 */
class SapiEmitter implements Emitter
{
    public function emit(<ResponseInterface> response) -> void
    {
        if headers_sent() {
            throw new HeadersAlreadySent("Headers have already been sent; cannot emit the response.");
        }

        response->send();
    }
}
