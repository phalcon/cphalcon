
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Queue\Consumer;

/**
 * Immutable lifetime bounds for a Worker. A value of 0 means "no limit".
 * The worker stops on whichever bound trips first.
 */
class WorkerOptions
{
    /**
     * Seconds added to maxSeconds (randomised per worker) so a pool does not
     * restart in lockstep.
     *
     * @var int
     */
    protected jitter = 0;

    /**
     * Memory ceiling in megabytes.
     *
     * @var int
     */
    protected maxMemory = 0;

    /**
     * Maximum number of messages to process.
     *
     * @var int
     */
    protected maxMessages = 0;

    /**
     * Maximum run time in seconds.
     *
     * @var int
     */
    protected maxSeconds = 0;

    public function __construct(int maxMessages = 0, int maxSeconds = 0, int maxMemory = 0, int jitter = 0)
    {
        let this->maxMessages = maxMessages,
            this->maxSeconds  = maxSeconds,
            this->maxMemory   = maxMemory,
            this->jitter      = jitter;
    }

    public function getJitter() -> int
    {
        return this->jitter;
    }

    public function getMaxMemory() -> int
    {
        return this->maxMemory;
    }

    public function getMaxMessages() -> int
    {
        return this->maxMessages;
    }

    public function getMaxSeconds() -> int
    {
        return this->maxSeconds;
    }
}
