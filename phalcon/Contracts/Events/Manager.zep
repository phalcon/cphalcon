
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
 * Canonical contract for Phalcon\Events\Manager.
 */
interface Manager
{
    /**
     * @var int
     */
    const DEFAULT_PRIORITY = 100;

    /**
     * Registers an event subscriber. The subscriber's getSubscribedEvents()
     * map is parsed and each entry is attached through the regular listener
     * pipeline.
     */
    public function addSubscriber(<Subscriber> subscriber) -> void;

    /**
     * Returns whether priority ordering is currently enabled.
     */
    public function arePrioritiesEnabled() -> bool;

    /**
     * Attach a listener to the events manager.
     *
     * @param object|callable handler
     */
    public function attach(
        string eventType,
        handler,
        int priority = self::DEFAULT_PRIORITY
    ) -> void;

    /**
     * Toggle response collection on/off.
     */
    public function collectResponses(bool collect) -> void;

    /**
     * Detach a listener from the events manager.
     *
     * @param object|callable handler
     */
    public function detach(string eventType, handler) -> void;

    /**
     * Removes all listeners — globally or for a single event type.
     */
    public function detachAll(string type = null) -> void;

    /**
     * Toggle priority ordering on/off.
     */
    public function enablePriorities(bool enablePriorities) -> void;

    /**
     * Fires an event, notifying the active listeners.
     *
     * @param object source
     * @param mixed  data
     * @return mixed
     */
    public function fire(
        string eventType,
        object source,
        var data = null,
        bool cancelable = true
    );

    /**
     * Returns all listeners attached to the given event type.
     */
    public function getListeners(string type) -> array;

    /**
     * Returns the responses recorded during the last fire (when collecting).
     */
    public function getResponses() -> array;

    /**
     * Check whether the given event type has any listeners.
     */
    public function hasListeners(string type) -> bool;

    /**
     * Check whether the manager is currently collecting responses.
     */
    public function isCollecting() -> bool;

    /**
     * Returns true when the given handler is an object or callable.
     */
    public function isValidHandler(var handler) -> bool;

    /**
     * Removes a previously registered subscriber. Detaches every listener the
     * subscriber declared via getSubscribedEvents(). Idempotent.
     */
    public function removeSubscriber(<Subscriber> subscriber) -> void;
}
