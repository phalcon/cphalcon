
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Events;

/**
 * Canonical contract for Phalcon\Events\Event.
 */
interface Event
{
    /**
     * Gets event data
     */
    public function getData() -> var;

    /**
     * Gets event type
     */
    public function getType() -> var;

    /**
     * Check whether the event is cancelable
     */
    public function isCancelable() -> bool;

    /**
     * Check whether the event is currently stopped
     */
    public function isStopped() -> bool;

    /**
     * Sets event data
     */
    public function setData(var data = null) -> <Event>;

    /**
     * Sets event type
     */
    public function setType(string type) -> <Event>;

    /**
     * Stops the event preventing propagation
     */
    public function stop() -> <Event>;
}
