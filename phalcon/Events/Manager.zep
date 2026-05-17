
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Events;

use Closure;
use Phalcon\Contracts\Events\Subscriber;

/**
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if
 * needed, the normal flow of operation. With the EventsManager the developer
 * can create hooks or plugins that will offer monitoring of data, manipulation,
 * conditional execution and much more.
 */
class Manager implements ManagerInterface
{
    /**
     * @var bool
     */
    protected collect = false;

    /**
     * @var bool
     */
    protected enablePriorities = false;

    /**
     * Parsed-eventType cache. Memoizes the strpos + substr work done in
     * fire() so the same event name fired repeatedly (the common case
     * for db:beforeQuery, model:afterSave, etc.) collapses to a single
     * hash lookup.
     *
     * Shape: `eventNameCache[$eventType] = [typePrefix, eventName]`
     *
     * Unbounded by design — distinct event types in a typical Phalcon
     * application are well under 100 keys, and the cache never needs
     * invalidation (parse is deterministic for a given eventType string).
     *
     * @var array
     */
    protected eventNameCache = [];

    /**
     * Listener storage. Shape:
     *
     *   events[$eventType] = [
     *       [handler, kind, priority],
     *       ...
     *   ]
     *
     * kept sorted by priority descending (FIFO within the same priority).
     *
     * `kind` is classified once at attach() time so fireQueue() can
     * dispatch via a simple branch:
     *
     *   0 — Closure: direct invocation, no array alloc per call
     *   1 — generic callable (array, string, invokable object):
     *       call_user_func_array
     *   2 — plain object: dynamic dispatch via method named after the
     *       event (the classic Phalcon listener pattern)
     *
     * @var array
     */
    protected events = [];

    /**
     * @var array
     */
    protected responses = [];

    /**
     * @var array
     */
    protected subscribers = [];

    /**
     * Registers an event subscriber. The subscriber's getSubscribedEvents()
     * map is parsed and each entry is attached through the regular listener
     * pipeline.
     */
    public function addSubscriber(<Subscriber> subscriber) -> void
    {
        var eventName, events, params;

        let this->subscribers[spl_object_id(subscriber)] = subscriber;

        let events = call_user_func(
            [get_class(subscriber), "getSubscribedEvents"]
        );

        for eventName, params in events {
            this->processSubscriberEntry(
                subscriber,
                eventName,
                params,
                false
            );
        }
    }

    /**
     * Attach a listener to the events manager
     *
     * @param object|callable handler
     */
    public function attach(
        string eventType,
        var handler,
        int priority = self::DEFAULT_PRIORITY
    ) -> void {
        var existing, index, queue;
        int insertAt, kind;
        array newQueue, tuple;

        // Classify the handler kind ONCE so fireQueue() doesn't have to
        // run instanceof / is_callable per fire per listener.
        if handler instanceof Closure {
            let kind = 0;
        } elseif is_callable(handler) {
            // Generic callable: [obj, method], [class, method], 'function',
            // or an invokable object (one with __invoke).
            let kind = 1;
        } elseif typeof handler == "object" {
            // Plain object — method-named-after-event dispatch.
            let kind = 2;
        } else {
            throw new Exception(
                "Event handler must be an Object or Callable"
            );
        }

        if !this->enablePriorities {
            let priority = self::DEFAULT_PRIORITY;
        }

        let tuple = [handler, kind, priority];

        if !fetch queue, this->events[eventType] {
            let this->events[eventType] = [tuple];

            return;
        }

        // Sorted-insert: descending priority, FIFO within same priority.
        let insertAt = -1;

        for index, existing in queue {
            if existing[2] < priority {
                let insertAt = index;

                break;
            }
        }

        if insertAt == -1 {
            let queue[] = tuple;
            let this->events[eventType] = queue;

            return;
        }

        let newQueue = [];

        for index, existing in queue {
            if index == insertAt {
                let newQueue[] = tuple;
            }

            let newQueue[] = existing;
        }

        let this->events[eventType] = newQueue;
    }

    /**
     * Returns if priorities are enabled
     */
    public function arePrioritiesEnabled() -> bool
    {
        return this->enablePriorities;
    }

    /**
     * Removes every registered subscriber and detaches each listener they
     * contributed. Listeners attached via attach() are untouched.
     *
     * Iterates a snapshot of `subscribers` so removeSubscriber() can safely
     * mutate the original property during the walk.
     */
    public function clearSubscribers() -> void
    {
        var snapshot, subscriber;

        let snapshot = this->subscribers;

        for subscriber in snapshot {
            this->removeSubscriber(subscriber);
        }
    }

    /**
     * Tells the event manager if it needs to collect all the responses returned
     * by every registered listener in a single fire
     */
    public function collectResponses(bool collect) -> void
    {
        let this->collect = collect;
    }

    /**
     * Detach the listener from the events manager
     *
     * @param object|callable handler
     */
    public function detach(string eventType, var handler) -> void
    {
        var existing, newQueue, queue;

        if unlikely false === this->isValidHandler(handler) {
            throw new Exception(
                "Event handler must be an Object or Callable"
            );
        }

        if fetch queue, this->events[eventType] {
            let newQueue = [];

            for existing in queue {
                if existing[0] !== handler {
                    let newQueue[] = existing;
                }
            }

            let this->events[eventType] = newQueue;
        }
    }

    /**
     * Removes all events from the EventsManager
     */
    public function detachAll(string! type = null) -> void
    {
        if type === null {
            let this->events = null;
        } else {
            if isset this->events[type] {
                unset this->events[type];
            }
        }
    }

    /**
     * Set if priorities are enabled in the EventsManager.
     *
     * A priority queue of events is a data structure similar
     * to a regular queue of events: we can also put and extract
     * elements from it. The difference is that each element in a
     * priority queue is associated with a value called priority.
     * This value is used to order elements of a queue: elements
     * with higher priority are retrieved before the elements with
     * lower priority.
     */
    public function enablePriorities(bool enablePriorities) -> void
    {
        let this->enablePriorities = enablePriorities;
    }

    /**
     * Fires an event in the events manager causing the active listeners to be
     * notified about it
     *
     *```php
     * $eventsManager->fire("db", $connection);
     *```
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
    ) {
        var cached, colonPos, event, eventName, events, fireEvents,
            status, type;
        bool hasFullQueue, hasTypeQueue;

        let events = this->events;

        if empty events {
            return null;
        }

        // Cache hit: the eventType parse is deterministic, and the same
        // names fire over and over (db:beforeQuery × N per request etc.).
        // After warm-up this collapses to a single hash lookup.
        if fetch cached, this->eventNameCache[eventType] {
            let type      = cached[0];
            let eventName = cached[1];
        } else {
            let colonPos = strpos(eventType, ":");

            if unlikely colonPos === false {
                throw new Exception("Invalid event type " . eventType);
            }

            let type      = substr(eventType, 0, colonPos);
            let eventName = substr(eventType, colonPos + 1);

            let this->eventNameCache[eventType] = [type, eventName];
        }

        let hasTypeQueue = isset events[type];
        let hasFullQueue = isset events[eventType];

        // Short-circuit BEFORE allocating Event: in production most fires
        // have zero matching listeners (a model lifecycle event with no
        // user-attached behavior, a DB event without a tracer, etc.).
        if !hasTypeQueue && !hasFullQueue {
            return null;
        }

        if this->collect {
            let this->responses = [];
        }

        let event  = new Event(eventName, source, data, cancelable);
        let status = null;

        if hasTypeQueue {
            let fireEvents = events[type];
            let status     = this->fireQueue(fireEvents, event);
        }

        if hasFullQueue {
            let fireEvents = events[eventType];
            let status     = this->fireQueue(fireEvents, event);
        }

        return status;
    }

    /**
     * Internal handler to call a queue of events
     *
     * @return mixed
     */
    final public function fireQueue(array queue, <EventInterface> event)
    {
        var data, eventName, handler, source, status, tuple;
        bool cancelable, collect;
        int kind;

        let status     = null;
        let eventName  = event->getType();
        let source     = event->getSource();
        let data       = event->getData();
        let cancelable = (bool) event->isCancelable();
        let collect    = (bool) this->collect;

        for tuple in queue {
            let handler = tuple[0];
            let kind    = (int) tuple[1];

            // Closure: most common path, direct invocation via Zephir's
            // `{var}(...)` callable-invocation syntax. This goes through
            // PHP's normal closure call path so arity mismatch (closure
            // declares fewer params than we pass) is tolerated, unlike
            // `handler->__invoke(...)` which uses a strict C call.
            if kind == 0 {
                let status = {handler}(event, source, data);
            } elseif kind == 2 {
                // Plain object — method named after the event.
                if !method_exists(handler, eventName) {
                    continue;
                }

                let status = handler->{eventName}(event, source, data);
            } else {
                // Generic callable.
                let status = call_user_func_array(
                    handler,
                    [event, source, data]
                );
            }

            if collect {
                let this->responses[] = status;
            }

            if cancelable && event->isStopped() {
                break;
            }
        }

        return status;
    }

    /**
     * Returns all the attached listeners of a certain type
     */
    public function getListeners(string type) -> array
    {
        var existing, queue;
        array listeners;

        let listeners = [];

        if fetch queue, this->events[type] {
            for existing in queue {
                let listeners[] = existing[0];
            }
        }

        return listeners;
    }

    /**
     * Returns all the responses returned by every handler executed by the last
     * 'fire' executed
     */
    public function getResponses() -> array
    {
        return this->responses;
    }

    /**
     * Returns the list of registered subscriber instances. Useful for
     * introspection and test setup/teardown.
     */
    public function getSubscribers() -> array
    {
        return array_values(this->subscribers);
    }

    /**
     * Check whether certain type of event has listeners
     */
    public function hasListeners(string! type) -> bool
    {
        return isset this->events[type];
    }

    /**
     * Check if the events manager is collecting all all the responses returned
     * by every registered listener in a single fire
     */
    public function isCollecting() -> bool
    {
        return this->collect;
    }

    public function isValidHandler(handler) -> bool
    {
        if unlikely typeof handler != "object" && !is_callable(handler) {
            return false;
        }

        return true;
    }

    /**
     * Removes a previously registered subscriber. Detaches every listener the
     * subscriber declared via getSubscribedEvents(). Idempotent — calling
     * with a subscriber that was never added (or already removed) is a no-op.
     */
    public function removeSubscriber(<Subscriber> subscriber) -> void
    {
        var eventName, events, key, params;

        let key = spl_object_id(subscriber);

        if !isset this->subscribers[key] {
            return;
        }

        unset this->subscribers[key];

        let events = call_user_func(
            [get_class(subscriber), "getSubscribedEvents"]
        );

        for eventName, params in events {
            this->processSubscriberEntry(
                subscriber,
                eventName,
                params,
                true
            );
        }
    }

    /**
     * Parses one entry of a subscriber's getSubscribedEvents() map and either
     * attaches or detaches the resulting listeners depending on `detaching`.
     */
    private function processSubscriberEntry(
        object subscriber,
        string eventName,
        var params,
        bool detaching
    ) -> void {
        var firstParam, listener, methodName;
        int priority;

        if typeof params == "string" {
            if detaching {
                this->detach(eventName, [subscriber, params]);
            } else {
                this->attach(eventName, [subscriber, params]);
            }

            return;
        }

        if unlikely typeof params != "array" {
            throw new Exception(
                "Invalid event subscriber configuration for " . eventName
            );
        }

        if !fetch firstParam, params[0] {
            throw new Exception(
                "Invalid event subscriber configuration for " . eventName
            );
        }

        if typeof firstParam == "string" {
            let methodName = firstParam;
            let priority   = self::DEFAULT_PRIORITY;

            if isset params[1] {
                let priority = (int) params[1];
            }

            if detaching {
                this->detach(eventName, [subscriber, methodName]);
            } else {
                this->attach(
                    eventName,
                    [subscriber, methodName],
                    priority
                );
            }

            return;
        }

        if typeof firstParam == "array" {
            for listener in params {
                let methodName = listener[0];
                let priority   = self::DEFAULT_PRIORITY;

                if isset listener[1] {
                    let priority = (int) listener[1];
                }

                if detaching {
                    this->detach(eventName, [subscriber, methodName]);
                } else {
                    this->attach(
                        eventName,
                        [subscriber, methodName],
                        priority
                    );
                }
            }

            return;
        }

        throw new Exception(
            "Invalid event subscriber configuration for " . eventName
        );
    }
}
