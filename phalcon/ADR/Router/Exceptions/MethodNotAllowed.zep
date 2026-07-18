
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

namespace Phalcon\ADR\Router\Exceptions;

use Phalcon\ADR\Exceptions\Exception;

/**
 * Thrown when a route matches the path but not the request method.
 */
class MethodNotAllowed extends Exception
{
}
