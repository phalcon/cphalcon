
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

use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\ResponseInterface;

/**
 * Resolves an Action by class name, builds the middleware pipeline around it and
 * runs it to produce a response.
 */
interface Dispatcher
{
    public function dispatch(string actionClass, <AttributeRequest> request, array routeMiddleware = []) -> <ResponseInterface>;
}
