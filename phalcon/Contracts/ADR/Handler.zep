
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
 * Receives the request and returns a response. The terminal handler in the
 * pipeline is the Action.
 */
interface Handler
{
    public function __invoke(<AttributeRequestInterface> request) -> <ResponseInterface>;
}
