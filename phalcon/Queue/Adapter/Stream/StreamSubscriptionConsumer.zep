
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

namespace Phalcon\Queue\Adapter\Stream;

use Phalcon\Queue\Adapter\AbstractSubscriptionConsumer;

/**
 * Consumes from several filesystem queues at once. The round-robin poll loop
 * lives in AbstractSubscriptionConsumer.
 */
class StreamSubscriptionConsumer extends AbstractSubscriptionConsumer
{
    /**
     * Retained for transports that may later need it for a native multi-queue
     * receive; the shared poll loop does not use it.
     *
     * @var StreamContext
     */
    protected context;

    public function __construct(<StreamContext> context, int pollInterval = 200)
    {
        let this->context      = context,
            this->pollInterval = pollInterval;
    }
}
