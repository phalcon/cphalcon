
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

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Queue\Adapter\AbstractMessage;

/**
 * Beanstalkd-backed message. Carries the reserved job id so the consumer can
 * delete, release, bury or touch it; all other behavior comes from
 * AbstractMessage.
 */
class BeanstalkMessage extends AbstractMessage
{
    /**
     * The reserved Beanstalkd job id, or null before it is reserved.
     *
     * @var string | null
     */
    protected jobId = null;

    public function getJobId() -> string | null
    {
        return this->jobId;
    }

    public function setJobId(string jobId) -> void
    {
        let this->jobId = jobId;
    }
}
