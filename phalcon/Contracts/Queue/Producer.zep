
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
 * Sends messages to a destination.
 */
interface Producer
{
    /**
     * Returns the delivery delay (in milliseconds) or null when not set.
     */
    public function getDeliveryDelay() -> int | null;

    /**
     * Returns the message priority or null when not set.
     */
    public function getPriority() -> int | null;

    /**
     * Returns the time to live (in milliseconds) or null when not set.
     */
    public function getTimeToLive() -> int | null;

    /**
     * Sends a message to the given destination.
     */
    public function send(<Destination> destination, <Message> message) -> void;

    /**
     * Sets the delivery delay (in milliseconds). Null clears it.
     */
    public function setDeliveryDelay(var deliveryDelay = null) -> <Producer>;

    /**
     * Sets the message priority. Null clears it.
     */
    public function setPriority(var priority = null) -> <Producer>;

    /**
     * Sets the time to live (in milliseconds). Null clears it.
     */
    public function setTimeToLive(var timeToLive = null) -> <Producer>;
}
