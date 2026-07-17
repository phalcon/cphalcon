
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

namespace Phalcon\Contracts\ADR;

use Phalcon\Contracts\Http\AttributeRequestInterface;
use Phalcon\Http\ResponseInterface;

/**
 * Wraps the handler chain. Middleware may pass the request through to the next
 * handler, decorate the response, short-circuit by returning its own response,
 * or throw to route through the error responder.
 */
interface Middleware
{
    public function __invoke(<AttributeRequestInterface> request, <Handler> next) -> <ResponseInterface>;
}
