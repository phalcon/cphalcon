
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Adapter;

use Phalcon\Contracts\Queue\Destination as DestinationInterface;
use Phalcon\Contracts\Queue\Queue as QueueInterface;
use Phalcon\Queue\Exceptions\InvalidDestinationException;

/**
 * Shared "destination must be a queue" guard. Producers (on send) and contexts
 * (on createConsumer) both reject any non-queue destination with the same typed
 * exception; this keeps that single rule in one place. The `action` verb
 * ("send to", "consume from") tailors the message to the caller.
 */
class QueueDestinationGuard
{
    /**
     * Throws InvalidDestinationException unless the destination is a queue.
     */
    public static function assertQueue(<DestinationInterface> destination, string action) -> void
    {
        if unlikely !(destination instanceof QueueInterface) {
            throw new InvalidDestinationException(action);
        }
    }
}
