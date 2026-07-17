
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

namespace Phalcon\ADR\Exceptions;

use Exception as BaseException;

/**
 * Generic exception for the ADR component, and the base for every typed ADR
 * exception.
 */
class Exception extends BaseException implements ADRThrowable
{
}
