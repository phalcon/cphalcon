
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
use Phalcon\Events\Exceptions\InvalidEventHandler;
use Phalcon\Events\Exceptions\InvalidEventType;
use Phalcon\Events\Exceptions\InvalidSubscriberConfiguration;
use Phalcon\Events\Exceptions\NoListenersForEvent;

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
     * Re-entrancy depth of fire()/fireAll(). 0 means no fire is in
     * progress. Incremented on every fire entry, decremented on exit.
     * Used to keep nested fire() calls from clobbering the outer
     * caller's `$this->responses` accumulator.
     *
     * @var int
     */
    protected fireDepth = 0;

    /**
     * Manager-level kill switch. When true, every fire()/fireAll()/
     * fireQueue() call returns immediately (null or empty array) without
     * dispatching. Cleared by resume(). Survives across fire() calls,
     * unlike Event::stop() which only stops the current dispatch chain.
     *
     * @var bool
     */
    protected halted = false;

    /**
     * When true, a listener returning literal `false` (with the event's
     * `cancelable` flag on) short-circuits the dispatch loop and pins
     * the fire() return as `false`. Default off — preserves the pre-5.13
     * "last-wins" contract for codebases that rely on later listeners
     * overriding an earlier false return [#17019].
     *
     * @var bool
     */
    protected stopOnFalse = false;

    /**
     * When true, fire()/fireAll() throw on dispatch of an event that
     * has zero matching listeners. Catches typos in dev. Default off.
     *
     * @var bool
     */
    protected strict = false;

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
     * Memoized method_exists() results for the OBJECT_METHOD dispatch
     * path in dispatch(). Keyed by `handlerClass => [methodName => bool]`.
     * A class doesn't gain methods at runtime so the lookup is permanent.
     *
     * @var array
     */
    protected methodExistsCache = [];

    /**
     * Maximum number of distinct handler classes retained in
     * methodExistsCache. 0 (default) keeps the original unbounded
     * behavior; a positive value clears the cache when adding a new
     * class would exceed it. Re-warming is cheap (method_exists is
     * O(1)) and the cap is meant for very long-lived workers that see
     * many distinct listener classes over time.
     *
     * @var int
     */
    protected methodExistsCacheLimit = 0;

    /**
     * Memoized getSubscribedEvents() maps keyed by Subscriber class name.
     * The static method's return is stable for the lifetime of a class
     * definition, so the cache never needs invalidation.
     *
     * @var array
     */
    protected subscriberEventsCache = [];

    /**
     * Listener storage. Shape:
     *
     *   events[$eventType] = [
     *       [handler, type, priority]            // types 0, 1, 3
     *       [handler, type, priority, className] // type 2 carries
     *                                            // resolved class name
     *       ...
     *   ]
     *
     * Kept sorted by priority descending when priorities are enabled
     * (FIFO within the same priority); otherwise listeners are simply
     * appended in attach order.
     *
     * `type` is classified once at attach() time so dispatch() can
     * route via a simple branch:
     *
     *   0 — Closure: direct invocation via `{handler}(args)`, no
     *       arg-array alloc per call
     *   1 — [obj, method] array callable: direct dynamic dispatch
     *       `handler[0]->{handler[1]}(args)`
     *   2 — plain object: dynamic dispatch via method named after the
     *       event (the classic Phalcon listener pattern); class name is
     *       captured at attach time to skip get_class() per fire
     *   3 — generic callable (string fn name, invokable object,
     *       [class, staticMethod]): call_user_func_array
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
        var className, eventName, events, params;

        let this->subscribers[spl_object_id(subscriber)] = subscriber;

        let className = get_class(subscriber);

        if !fetch events, this->subscriberEventsCache[className] {
            let events = {className}::getSubscribedEvents();
            let this->subscriberEventsCache[className] = events;
        }

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
    final public function attach(
        string eventType,
        var handler,
        int priority = self::DEFAULT_PRIORITY
    ) -> void {
        int type;

        // Classify the handler type ONCE so fireQueue() doesn't have to
        // run instanceof / is_callable per fire per listener.
        //
        //   0 — Closure: direct invocation via Zephir {handler}(args)
        //   1 — [obj, method] array callable: direct dynamic dispatch
        //   2 — plain object, method named after the event (classic Phalcon)
        //   3 — generic callable: string function, invokable object,
        //       [class, staticMethod] etc.
        if handler instanceof Closure {
            let type = 0;
        } elseif typeof handler == "array"
            && isset handler[0]
            && isset handler[1]
            && typeof handler[0] == "object"
            && typeof handler[1] == "string"
        {
            let type = 1;
        } elseif typeof handler == "object" {
            if is_callable(handler) {
                // Invokable object — generic callable.
                let type = 3;
            } else {
                // Plain object — method named after the event. Capture
                // the class name once at attach time so fireQueue() can
                // skip get_class() per fire (type=2 tuples carry it).
                this->insertHandlerEntry(
                    eventType,
                    handler,
                    2,
                    priority,
                    get_class(handler)
                );
                return;
            }
        } elseif is_callable(handler) {
            let type = 3;
        } else {
            throw new InvalidEventHandler();
        }

        this->insertHandlerEntry(eventType, handler, type, priority);
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
            throw new InvalidEventHandler();
        }

        if fetch queue, this->events[eventType] {
            let newQueue = [];

            for existing in queue {
                if existing[0] !== handler {
                    let newQueue[] = existing;
                }
            }

            // Drop the key when the last listener is gone so fire() can
            // short-circuit cleanly and hasListeners() tells the truth.
            if count(newQueue) > 0 {
                let this->events[eventType] = newQueue;
            } else {
                unset this->events[eventType];
            }
        }
    }

    /**
     * Removes all events from the EventsManager
     */
    public function detachAll(string type = null) -> void
    {
        if type === null {
            let this->events = [];
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
    final public function fire(
        string eventType,
        object source,
        var data = null,
        bool cancelable = true
    ) {
        var cached, colonPos, event, eventName, ex, fireEvents, stashed,
            status, type, wasDepth;
        bool collect, hasFullQueue, hasTypeQueue;

        // Manager-level kill switch — halt() trips this and every fire
        // returns null without dispatching until resume() clears it.
        if this->halted {
            return null;
        }

        // Fast exit on a manager with no listeners attached at all.
        // Done BEFORE parsing the eventType so a misformed name (no
        // colon) doesn't raise "Invalid event type" on a manager that
        // would have had nothing to dispatch to anyway.
        if empty this->events {
            if unlikely this->strict {
                throw new NoListenersForEvent(eventType);
            }

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
                throw new InvalidEventType(eventType);
            }

            let type      = substr(eventType, 0, colonPos);
            let eventName = substr(eventType, colonPos + 1);

            let this->eventNameCache[eventType] = [type, eventName];
        }

        let hasTypeQueue = isset this->events[type];
        let hasFullQueue = isset this->events[eventType];

        // Short-circuit BEFORE allocating Event: in production most fires
        // have zero matching listeners (a model lifecycle event with no
        // user-attached behavior, a DB event without a tracer, etc.).
        if !hasTypeQueue && !hasFullQueue {
            if unlikely this->strict {
                throw new NoListenersForEvent(eventType);
            }

            return null;
        }

        // Increment reentrancy depth. Nested fire() calls stash and
        // restore $this->responses so the outer caller's collected
        // state is never clobbered.
        let wasDepth        = this->fireDepth;
        let this->fireDepth = wasDepth + 1;
        let collect         = this->collect;

        if collect {
            if wasDepth > 0 {
                let stashed = this->responses;
            }

            let this->responses = [];
        }

        // Wrap dispatch in try/catch so a throwing listener cannot
        // leak the incremented fireDepth or the stashed responses —
        // important for long-lived managers (workers, daemons) where
        // a single dirty teardown would poison every subsequent fire.
        try {
            let event  = new Event(eventName, source, data, cancelable);
            let status = null;

            if hasTypeQueue {
                let fireEvents = this->events[type];
                let status     = this->dispatch(
                    fireEvents,
                    event,
                    eventName,
                    source,
                    data,
                    cancelable,
                    collect
                );
            }

            // stopOnFalse propagation: dispatch already short-circuited
            // its queue; skip the fully-qualified queue too and pin
            // the fire() return as false.
            if !(this->stopOnFalse && cancelable && status === false)
                && hasFullQueue
                && (!cancelable || !event->isStopped())
            {
                let fireEvents = this->events[eventType];
                let status     = this->dispatch(
                    fireEvents,
                    event,
                    eventName,
                    source,
                    data,
                    cancelable,
                    collect
                );
            }
        } catch \Throwable, ex {
            if collect && wasDepth > 0 {
                let this->responses = stashed;
            }

            let this->fireDepth = wasDepth;
            throw ex;
        }

        if collect && wasDepth > 0 {
            let this->responses = stashed;
        }

        let this->fireDepth = wasDepth;

        return status;
    }

    /**
     * Fires an event and returns every listener's return value as an
     * indexed array. Independent of collectResponses(); the caller's
     * collected state on `$this->responses` is preserved (stashed and
     * restored across the call).
     *
     *```php
     * $results = $eventsManager->fireAll("db:beforeQuery", $connection);
     *```
     */
    public function fireAll(
        string eventType,
        object source,
        var data = null,
        bool cancelable = true
    ) -> array
    {
        var cached, colonPos, dispatchStatus, event, eventName, ex,
            fireEvents, responses, stashed, type, wasDepth;
        bool hasFullQueue, hasTypeQueue;

        // Manager-level kill switch — see fire().
        if this->halted {
            return [];
        }

        // Fast exit on a manager with no listeners. Mirrors fire().
        if empty this->events {
            if unlikely this->strict {
                throw new NoListenersForEvent(eventType);
            }

            return [];
        }

        if fetch cached, this->eventNameCache[eventType] {
            let type      = cached[0];
            let eventName = cached[1];
        } else {
            let colonPos = strpos(eventType, ":");

            if unlikely colonPos === false {
                throw new InvalidEventType(eventType);
            }

            let type      = substr(eventType, 0, colonPos);
            let eventName = substr(eventType, colonPos + 1);

            let this->eventNameCache[eventType] = [type, eventName];
        }

        let hasTypeQueue = isset this->events[type];
        let hasFullQueue = isset this->events[eventType];

        if !hasTypeQueue && !hasFullQueue {
            if unlikely this->strict {
                throw new NoListenersForEvent(eventType);
            }

            return [];
        }

        let wasDepth        = this->fireDepth;
        let this->fireDepth = wasDepth + 1;
        let stashed         = this->responses;
        let this->responses = [];

        // Same exception-safety wrap as fire() — a throwing listener
        // must not leak fireDepth or strand the stashed responses.
        try {
            let event = new Event(eventName, source, data, cancelable);
            let dispatchStatus = null;

            if hasTypeQueue {
                let fireEvents = this->events[type];
                let dispatchStatus = this->dispatch(
                    fireEvents,
                    event,
                    eventName,
                    source,
                    data,
                    cancelable,
                    true
                );
            }

            // stopOnFalse propagation across the two dispatch legs.
            if !(this->stopOnFalse && cancelable && dispatchStatus === false)
                && hasFullQueue
                && (!cancelable || !event->isStopped())
            {
                let fireEvents = this->events[eventType];
                this->dispatch(
                    fireEvents,
                    event,
                    eventName,
                    source,
                    data,
                    cancelable,
                    true
                );
            }
        } catch \Throwable, ex {
            let this->responses = stashed;
            let this->fireDepth = wasDepth;
            throw ex;
        }

        let responses       = this->responses;
        let this->responses = stashed;
        let this->fireDepth = wasDepth;

        return responses;
    }

    /**
     * Internal handler to call a queue of events.
     *
     * Kept at its original 2-arg signature for BC; thin wrapper around
     * the private `dispatch()` helper. Direct callers pay the cost of
     * re-extracting metadata from the Event; the framework's own fire()
     * path bypasses this wrapper and calls dispatch() with hoisted args.
     *
     * @return mixed
     */
    final public function fireQueue(array queue, <EventInterface> event)
    {
        if this->halted {
            return null;
        }

        return this->dispatch(
            queue,
            event,
            event->getType(),
            event->getSource(),
            event->getData(),
            event->isCancelable(),
            this->collect
        );
    }

    /**
     * Manager-level kill switch. After halt(), every fire()/fireAll()/
     * fireQueue() call returns immediately without dispatching, until
     * resume() is called. Use this when a listener needs to abort all
     * subsequent event activity for the lifetime of the manager (e.g.
     * a security check that cancels everything downstream).
     */
    public function halt() -> void
    {
        let this->halted = true;
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
     * Returns the configured method_exists-cache cap (0 = unlimited).
     * See setMethodExistsCacheLimit().
     */
    public function getMethodExistsCacheLimit() -> int
    {
        return this->methodExistsCacheLimit;
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

    /**
     * Returns whether the manager-level kill switch is engaged. See halt().
     */
    public function isHalted() -> bool
    {
        return this->halted;
    }

    /**
     * Returns whether the stop-on-false short-circuit is enabled.
     * See setStopOnFalse().
     */
    public function isStopOnFalse() -> bool
    {
        return this->stopOnFalse;
    }

    /**
     * Returns whether strict mode is enabled. When true, fire()/fireAll()
     * throw when an event has no matching listeners — useful in dev to
     * catch typos. Default off.
     */
    public function isStrict() -> bool
    {
        return this->strict;
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
        var className, eventName, events, key, params;

        let key = spl_object_id(subscriber);

        if !isset this->subscribers[key] {
            return;
        }

        unset this->subscribers[key];

        let className = get_class(subscriber);

        if !fetch events, this->subscriberEventsCache[className] {
            let events = {className}::getSubscribedEvents();
            let this->subscriberEventsCache[className] = events;
        }

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
     * Clears the manager-level kill switch set by halt(). Subsequent
     * fire()/fireAll()/fireQueue() calls resume normal dispatch.
     */
    public function resume() -> void
    {
        let this->halted = false;
    }

    /**
     * Caps the number of distinct handler classes retained in the
     * method_exists memoization cache. 0 disables the cap (the
     * default; preserves the original unbounded behavior). When the
     * cap is exceeded, the cache is cleared and re-warms on subsequent
     * fires.
     */
    public function setMethodExistsCacheLimit(int methodExistsCacheLimit) -> void
    {
        let this->methodExistsCacheLimit = methodExistsCacheLimit;
    }

    /**
     * Enables/disables the stop-on-false short-circuit. When true, a
     * listener returning literal `false` (with cancelable=true) stops
     * the current event's queue and pins the fire() return as `false`.
     * Later listeners cannot overwrite the cancel. Default off.
     *
     * Independent of halt() / event->stop() — only governs how the
     * dispatch loop reacts to a `false` listener return.
     */
    public function setStopOnFalse(bool flag) -> void
    {
        let this->stopOnFalse = flag;
    }

    /**
     * Enables/disables strict mode. When true, fire()/fireAll() throw
     * when dispatching an event with zero matching listeners.
     */
    public function setStrict(bool strict) -> void
    {
        let this->strict = strict;
    }

    /**
     * Hot dispatch loop. Called by fire()/fireAll() with hoisted args,
     * and by fireQueue() as a BC wrapper. Owns the documented
     * aggregation contract:
     *
     * 1. **Last non-null wins** — `status` only updates when a listener
     *    returns a non-null value. A chain of nulls leaves the last
     *    real return intact.
     * 2. **stop() determinism** — when a listener calls
     *    `$event->stop()` (and cancelable=true), that listener's
     *    return value becomes the dispatch return — even if null.
     *
     * Note: returning `false` from a listener does **not** short-circuit
     * the queue. Callers that want to stop downstream listeners must call
     * `$event->stop()`. (Some consumers, like the dispatcher, check the
     * return value of `fire()` for `false` and act on it themselves; that
     * remains in their own dispatch logic.)
     *
     * Appends every listener's return to $this->responses when
     * `collect` is true (the caller manages stashing/restoring around
     * nested fires).
     *
     * @return mixed
     */
    private function dispatch(
        array queue,
        <EventInterface> event,
        string eventName,
        var source,
        var data,
        bool cancelable,
        bool collect
    ) {
        var handler, handlerCallable, handlerClass, handlerObject, type,
            ret, status, tuple;
        int queueSize;

        let status    = null;
        let queueSize = count(queue);

        // Single-handler fast path: very common (one listener attached
        // for an event). Skip the foreach + per-iter cancelable check.
        if queueSize == 1 {
            let tuple   = queue[0];
            let handler = tuple[0];
            let type    = tuple[1];

            if type == 0 {
                let ret = {handler}(event, source, data);
            } elseif type == 1 {
                let handlerObject   = handler[0];
                let handlerCallable = handler[1];
                let ret = handlerObject->{handlerCallable}(event, source, data);
            } elseif type == 2 {
                let handlerClass = tuple[3];

                if !isset this->methodExistsCache[handlerClass][eventName] {
                    if !isset this->methodExistsCache[handlerClass]
                        && this->methodExistsCacheLimit > 0
                        && count(this->methodExistsCache) >= this->methodExistsCacheLimit {
                        let this->methodExistsCache = [];
                    }
                    let this->methodExistsCache[handlerClass][eventName] = method_exists(handler, eventName);
                }

                if !this->methodExistsCache[handlerClass][eventName] {
                    return status;
                }

                let ret = handler->{eventName}(event, source, data);
            } else {
                let ret = call_user_func_array(handler, [event, source, data]);
            }

            if collect {
                let this->responses[] = ret;
            }

            // Opt-in hard `false`-cancel — single-handler variant.
            if this->stopOnFalse && cancelable && ret === false {
                return false;
            }

            return ret;
        }

        for tuple in queue {
            let handler = tuple[0];
            let type    = tuple[1];

            // Closure: direct invocation via Zephir's `{var}(...)`
            // callable-invocation syntax. Routes through PHP's normal
            // closure call path so arity mismatch is tolerated, unlike
            // `handler->__invoke(...)` which uses a strict C call path
            // that segfaults on mismatch.
            if type == 0 {
                let ret = {handler}(event, source, data);
            } elseif type == 1 {
                // [obj, method] direct dispatch — no arg-array alloc,
                // no call_user_func_array overhead.
                let handlerObject   = handler[0];
                let handlerCallable = handler[1];
                let ret = handlerObject->{handlerCallable}(event, source, data);
            } elseif type == 2 {
                // Plain object — method named after the event. Class
                // name was captured at attach time (tuple[3]); cache
                // method_exists per (class, eventName) since classes
                // don't gain methods at runtime.
                let handlerClass = tuple[3];

                if !isset this->methodExistsCache[handlerClass][eventName] {
                    if !isset this->methodExistsCache[handlerClass]
                        && this->methodExistsCacheLimit > 0
                        && count(this->methodExistsCache) >= this->methodExistsCacheLimit {
                        let this->methodExistsCache = [];
                    }
                    let this->methodExistsCache[handlerClass][eventName] = method_exists(handler, eventName);
                }

                if !this->methodExistsCache[handlerClass][eventName] {
                    continue;
                }

                let ret = handler->{eventName}(event, source, data);
            } else {
                // type == 3: generic callable (string fn name,
                // invokable object, [class, staticMethod]).
                let ret = call_user_func_array(
                    handler,
                    [event, source, data]
                );
            }

            if collect {
                let this->responses[] = ret;
            }

            // Opt-in hard `false`-cancel: when setStopOnFalse(true) has
            // been called, a listener returning false short-circuits
            // the queue and pins the dispatch return as false. fire()
            // checks the return and propagates accordingly.
            if this->stopOnFalse && cancelable && ret === false {
                return false;
            }

            // stop() determinism: if the listener stopped the event,
            // its return is the dispatch result (even if null) and the
            // queue is abandoned.
            if cancelable && event->isStopped() {
                return ret;
            }

            // Last non-null wins.
            if ret !== null {
                let status = ret;
            }
        }

        return status;
    }

    /**
     * Stores a pre-classified listener tuple in the queue for an event
     * type. Bypasses attach()'s type classification — callers that
     * already know the type (the subscriber path) skip the instanceof /
     * is_callable cascade.
     *
     * type=2 tuples carry a 4th element `className` so dispatch() can
     * skip the per-fire get_class() lookup against methodExistsCache.
     */
    private function insertHandlerEntry(
        string eventType,
        var handler,
        int type,
        int priority,
        var className = null
    ) -> void {
        var existing, index, queue, tuple, prioritiesOn;
        int insertAt;

        let prioritiesOn = this->enablePriorities;

        if !prioritiesOn {
            let priority = self::DEFAULT_PRIORITY;
        }

        if type == 2 {
            let tuple = [handler, type, priority, className];
        } else {
            let tuple = [handler, type, priority];
        }

        if !fetch queue, this->events[eventType] {
            let this->events[eventType] = [tuple];
            return;
        }

        // Priorities disabled (the default): every existing element has
        // identical priority, so the sorted-insert is wasted work.
        // Append and return.
        if !prioritiesOn {
            let queue[] = tuple;
            let this->events[eventType] = queue;
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

        array_splice(queue, insertAt, 0, [tuple]);
        let this->events[eventType] = queue;
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
        var firstParam, listener, methodName, priority;

        if typeof params == "string" {
            if detaching {
                this->detach(eventName, [subscriber, params]);
            } else {
                this->insertHandlerEntry(
                    eventName,
                    [subscriber, params],
                    1,
                    self::DEFAULT_PRIORITY
                );
            }

            return;
        }

        if unlikely typeof params != "array" {
            throw new InvalidSubscriberConfiguration(eventName);
        }

        if !fetch firstParam, params[0] {
            throw new InvalidSubscriberConfiguration(eventName);
        }

        if typeof firstParam == "string" {
            let methodName = firstParam;
            let priority   = self::DEFAULT_PRIORITY;

            if isset params[1] {
                let priority = params[1];
            }

            if detaching {
                this->detach(eventName, [subscriber, methodName]);
            } else {
                this->insertHandlerEntry(
                    eventName,
                    [subscriber, methodName],
                    1,
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
                    let priority = listener[1];
                }

                if detaching {
                    this->detach(eventName, [subscriber, methodName]);
                } else {
                    this->insertHandlerEntry(
                        eventName,
                        [subscriber, methodName],
                        1,
                        priority
                    );
                }
            }

            return;
        }

        throw new InvalidSubscriberConfiguration(eventName);
    }
}
