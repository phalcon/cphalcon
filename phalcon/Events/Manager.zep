
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
use SplPriorityQueue;

/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if
 * needed, the normal flow of operation. With the EventsManager the developer
 * can create hooks or plugins that will offer monitoring of data, manipulation,
 * conditional execution and much more.
 */
class Manager implements ManagerInterface
{
    const DEFAULT_PRIORITY = 100;

    /**
     * @var bool
     */
    protected collect = false;

    /**
     * @var bool
     */
    protected enablePriorities = false;

    protected events = null;

    protected eventsOptions = null;

    protected responses;

    /**
     * Attach a listeneres to the events manager from provider
     *
     * @param \Phalcon\Events\ProviderInterface provider
     */
    final public function registerProvider(<ProviderInterface> provider) -> <ManagerInterface>
    {
        var events, listeners, listener, eventType, eventsOptions, eventOptions;

        let events = provider->getListeners();

        for eventType, listeners in events {
            let eventType = (string) eventType;
            for listener in listeners {
                this->attach(eventType, listener);
            }
        }

        let eventsOptions = provider->getOptions();

        for eventType, eventOptions in eventsOptions {
            this->setEventOptions(eventType, eventOptions);
        }

        return this;
    }

    /**
     * Attach a listener to the events manager
     *
     * @param object|callable handler
     */
    public function attach(string! eventType, var handler, int! priority = self::DEFAULT_PRIORITY) -> void
    {
        var priorityQueue;

        this->isValidHandler(handler);

        if !fetch priorityQueue, this->events[eventType] {
            // Create a SplPriorityQueue to store the events with priorities
            let priorityQueue = new SplPriorityQueue();

            // Set extraction flags to extract only the Data
            priorityQueue->setExtractFlags(
                SplPriorityQueue::EXTR_DATA
            );

            // Append the events to the queue
            let this->events[eventType] = priorityQueue;
        }

        if !this->enablePriorities {
            let priority = self::DEFAULT_PRIORITY;
        }

        // Insert the handler in the queue
        priorityQueue->insert(handler, priority);
    }

    /**
     * Returns if priorities are enabled
     */
    public function arePrioritiesEnabled() -> bool
    {
        return this->enablePriorities;
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
     * @param object handler
     */
    public function detach(string! eventType, var handler) -> void
    {
        var priorityQueue, newPriorityQueue, data;

        this->isValidHandler(handler);

        if fetch priorityQueue, this->events[eventType] {
            /**
             * SplPriorityQueue doesn't have a method for element deletion so we
             * need to rebuild queue
             */
            let newPriorityQueue = new SplPriorityQueue();

            newPriorityQueue->setExtractFlags(
                SplPriorityQueue::EXTR_DATA
            );

            priorityQueue->setExtractFlags(
                SplPriorityQueue::EXTR_BOTH
            );

            priorityQueue->top();

            while priorityQueue->valid() {
                let data = priorityQueue->current();

                priorityQueue->next();

                if data["data"] !== handler {
                    newPriorityQueue->insert(
                        data["data"],
                        data["priority"]
                    );
                }
            }

            let this->events[eventType] = newPriorityQueue;
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
     * Set if priorities are enabled in the EventsManager
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
    public function fire(string! eventType, object source, var data = null, bool cancelable = true, bool strict = false)
    {
        var eventParts, type, eventName, status, eventArgs;

        if typeof this->events != "array" {
            return null;
        }

        // All valid events must have a colon separator
        if unlikely !memstr(eventType, ":") {
            throw new Exception("Invalid event type " . eventType);
        }

        let eventParts = explode(":", eventType),
            type = eventParts[0],
            eventName = eventParts[1];

        let status = null;

        // Responses must be traced?
        if this->collect {
            let this->responses = null;
        }

        let eventArgs  = [eventName, source, data, cancelable, strict];

        // Check if events are grouped by type
        let status = this->fireEvents(type, eventArgs, status);

        // Check if there are listeners for the event type itself
        let status = this->fireEvents(eventType, eventArgs, status);

        return status;
    }

    final public function fireEvents(string! eventType, array! eventArgs, var status = null) -> null | bool
    {
        var events, event, fireEvents, eventName, source, data, cancelable, strict;

        let events = this->events;
        if fetch fireEvents, events[eventType] {
            let eventName   = eventArgs[0],
                source      = eventArgs[1],
                data        = eventArgs[2],
                cancelable  = eventArgs[3],
                strict      = eventArgs[4];

            let cancelable = this->getEventOption(eventType, "cancelable", cancelable),
                strict     = this->getEventOption(eventType, "strict", strict);

            // Create the event context
            let event = new Event(eventName, source, data, cancelable, strict);

            if typeof fireEvents == "object" {
                // Call the events queue
                let status = this->fireQueue(fireEvents, event);
            }
        }

        return status;
    }

    /**
     * Internal handler to call a queue of events
     *
     * @return mixed
     */
    final public function fireQueue(<SplPriorityQueue> queue, <EventInterface> event)
    {
        var status, eventName, data, iterator, source, handler;
        bool collect, cancelable, strict;

        let status = null;

        // Get the event type
        let eventName = event->getType();

        if unlikely typeof eventName != "string" {
            throw new Exception("The event type not valid");
        }

        // Get the object who triggered the event
        let source = event->getSource();

        // Get extra data passed to the event
        let data = event->getData();

        // Tell if the event is cancelable
        let cancelable = (bool) event->isCancelable();

        // Tell if the event is strict
        let strict = (bool) event->isStrict();

        // Responses need to be traced?
        let collect = (bool) this->collect;

        // We need to clone the queue before iterate over it
        let iterator = clone queue;

        // Move the queue to the top
        iterator->top();

        while iterator->valid() {
            // Get the current data
            let handler = iterator->current();

            iterator->next();

            // Only handler objects and callables are valid
            if false === this->isValidHandler(handler, true) {
                continue;
            }

            // Check if the event handler is a closure or callable|invokable
            if handler instanceof Closure || is_callable(handler) {
                // Call the function in the PHP userland
                let status = call_user_func_array(
                    handler,
                    [event, source, data]
                );
            } else {
                // Check if the listener has implemented an event with the same name
                if !method_exists(handler, eventName) {
                    continue;
                }

                let status = handler->{eventName}(event, source, data);
            }

            // Trace the response
            if collect {
                let this->responses[] = status;
            }

            if strict {
                // Check if status is null or false
                if null === status || false === status {
                    break;
                }
            }

            if cancelable {
                // Check if the event was stopped by the user
                if event->isStopped() {
                    break;
                }
            }
        }

        return status;
    }

    /**
     * Returns all the attached listeners of a certain type
     */
    public function getListeners(string! type) -> array
    {
        var fireEvents, priorityQueue;
        array listeners;

        if !fetch fireEvents, this->events[type] {
            return [];
        }

        let listeners = [];

        let priorityQueue = clone fireEvents;

        priorityQueue->top();

        while priorityQueue->valid() {
            let listeners[] = priorityQueue->current();

            priorityQueue->next();
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
     * Check if given handler is object or callable
     */
    protected function isValidHandler(var handler, bool silent = false) -> bool
    {
        if unlikely (typeof handler != "object" && !is_callable(handler)) {
            if silent {
                return false;
            } else {
                throw new Exception("Event handler must be an Object or Callable");
            }
        }

        return true;
    }

    /**
     * Sets events options
     */
    public function setEventOptions(string! eventType, array! eventOptions) -> <ManagerInterface>
    {
        if unlikely !isset this->eventsOptions[eventType] {
            let this->eventsOptions[eventType] = eventOptions;
        }

        return this;
    }

    /**
     * Returns given event options
     */
    public function getEventOption(string! eventType, string option, var defaultValue = null) -> null | bool
    {
        var eventOptions;

        let eventOptions = this->getEventOptions(eventType);

        if null !== eventOptions && isset eventOptions[option] && typeof eventOptions[option] === "boolean" {
            return eventOptions[option];
        }

        return defaultValue;
    }

    /**
     * Returns given event options
     */
    public function getEventOptions(string! eventType) -> null | array
    {
        var eventsOptions, eventOptions, eventParts, type;

        let eventsOptions = this->eventsOptions;

        if fetch eventOptions, eventsOptions[eventType] {
            return eventOptions;
        }

        // Get by event type namespace, if not found by event type name
        if likely memstr(eventType, ":") {
            let eventParts = explode(":", eventType),
                type = eventParts[0];

            if fetch eventOptions, eventsOptions[type] {
                if typeof eventOptions == "array" {
                    return eventOptions;
                }

            }
        }

        return null;
    }
}
