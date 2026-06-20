
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\Queue as QueueInterface;

/**
 * A named in-process queue destination.
 */
class MemoryQueue implements QueueInterface
{
    /**
     * @var string
     */
    protected queueName = "";

    /**
     * MemoryQueue constructor.
     */
    public function __construct(string queueName)
    {
        let this->queueName = queueName;
    }

    /**
     * Returns the queue name.
     */
    public function getQueueName() -> string
    {
        return this->queueName;
    }
}
