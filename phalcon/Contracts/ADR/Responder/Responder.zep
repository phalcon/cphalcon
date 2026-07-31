
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

namespace Phalcon\Contracts\ADR\Responder;

use Phalcon\Contracts\ADR\Payload\Payload;
use Phalcon\Http\RequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Turns a payload into an HTTP response. The only layer that speaks HTTP.
 */
interface Responder
{
    public function __invoke(<RequestInterface> request, <ResponseInterface> response, <Payload> payload) -> <ResponseInterface>;
}
