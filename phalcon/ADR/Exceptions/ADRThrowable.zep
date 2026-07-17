
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

/**
 * Base throwable contract for the ADR component. Every ADR exception implements
 * it, so callers can catch all ADR errors with a single type.
 */
interface ADRThrowable extends \Throwable
{
}
