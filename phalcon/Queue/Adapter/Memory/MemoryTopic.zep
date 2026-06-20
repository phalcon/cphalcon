
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

namespace Phalcon\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\Topic as TopicInterface;

/**
 * A named in-process topic destination.
 */
class MemoryTopic implements TopicInterface
{
    /**
     * @var string
     */
    protected topicName = "";

    /**
     * MemoryTopic constructor.
     */
    public function __construct(string topicName)
    {
        let this->topicName = topicName;
    }

    /**
     * Returns the topic name.
     */
    public function getTopicName() -> string
    {
        return this->topicName;
    }
}
