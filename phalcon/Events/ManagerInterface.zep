
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

/**
 * Phalcon\Events\ManagerInterface
 *
 * Interface for Phalcon\Events managers.
 */
interface ManagerInterface
{
    /**
     * Attach a listener to the events manager
     *
     * @param object|callable handler
     */
    public function attach(string! eventType, handler) -> void;

    /**
     * Detach the listener from the events manager
     *
     * @param object handler
     */
    public function detach(string! eventType, handler) -> void;

    /**
     * Removes all events from the EventsManager
     */
    public function detachAll(string! type = null) -> void;

    /**
     * Fires an event in the events manager causing the active listeners to be
     * notified about it
     *
     * @param object source
     * @param mixed  data
     * @return mixed
     */
    public function fire(string! eventType, object source, var data = null, bool cancelable = true);

    /**
     * Returns all the attached listeners of a certain type
     */
    public function getListeners(string! type) -> array;

    /**
     * Check whether certain type of event has listeners
     */
    public function hasListeners(string! type) -> bool;
}
