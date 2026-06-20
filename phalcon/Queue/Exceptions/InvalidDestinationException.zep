
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Exceptions;

/**
 * Thrown when a destination is not valid for the operation, for example a
 * Topic passed where a Queue is required.
 */
class InvalidDestinationException extends Exception
{
}
