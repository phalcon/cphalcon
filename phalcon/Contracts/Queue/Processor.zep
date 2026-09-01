
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

namespace Phalcon\Contracts\Queue;

/**
 * Processes a single message. The return value tells the consumer what to
 * do next: acknowledge, reject, or requeue.
 *
 * The literal constant values are kept compatible with the wider interop
 * ecosystem.
 */
interface Processor
{
    /**
     * @var string
     */
    const ACK     = "enqueue.ack";
    /**
     * @var string
     */
    const REJECT  = "enqueue.reject";
    /**
     * @var string
     */
    const REQUEUE = "enqueue.requeue";

    /**
     * Processes the message and returns one of the ACK / REJECT / REQUEUE
     * constants, or an object whose string form is one of those values.
     *
     * @return string|object
     */
    public function process(<Message> message, <Context> context) -> string | object;
}
