
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\Queue as QueueInterface;

/**
 * A named Beanstalkd queue destination (a tube).
 */
class BeanstalkQueue implements QueueInterface
{
    /**
     * @var string
     */
    protected queueName = "";

    public function __construct(string queueName)
    {
        let this->queueName = queueName;
    }

    public function getQueueName() -> string
    {
        return this->queueName;
    }
}
