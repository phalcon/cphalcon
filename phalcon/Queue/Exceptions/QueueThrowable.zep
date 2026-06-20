
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
 * Base throwable contract for the Queue component. Every queue exception
 * implements it, so callers can catch all queue errors with a single type.
 */
interface QueueThrowable extends \Throwable
{
}
