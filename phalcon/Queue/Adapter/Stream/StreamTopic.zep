
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Stream;

use Phalcon\Contracts\Queue\Topic as TopicInterface;

/**
 * A named filesystem topic destination.
 */
class StreamTopic implements TopicInterface
{
    /**
     * @var string
     */
    protected topicName = "";

    public function __construct(string topicName)
    {
        let this->topicName = topicName;
    }

    public function getTopicName() -> string
    {
        return this->topicName;
    }
}
