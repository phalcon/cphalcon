
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Exceptions;

use Exception as BaseException;

/**
 * Generic exception for the Queue component, and the base for every typed
 * queue exception.
 */
class Exception extends BaseException implements QueueThrowable
{
}
