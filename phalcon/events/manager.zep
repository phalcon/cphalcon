
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Events;

use Phalcon\Events\Event;
use SplPriorityQueue as PriorityQueue;

/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */
class Manager implements ManagerInterface
{

	protected _events = null;

	protected _collect = false;

	protected _enablePriorities = false;

	protected _responses;

	/**
	 * Attach a listener to the events manager
	 *
	 * @param string eventType
	 * @param object|callable handler
	 * @param int priority
	 */
	public function attach(string! eventType, var handler, int! priority = 100)
	{
		var priorityQueue;

		if typeof handler != "object" {
			throw new Exception("Event handler must be an Object");
		}

		if !fetch priorityQueue, this->_events[eventType] {

			if this->_enablePriorities {

				// Create a SplPriorityQueue to store the events with priorities
				let priorityQueue = new PriorityQueue();

				// Extract only the Data // Set extraction flags
				priorityQueue->setExtractFlags(PriorityQueue::EXTR_DATA);

				// Append the events to the queue
				let this->_events[eventType] = priorityQueue;

			} else {
				let priorityQueue = [];
			}
		}

		// Insert the handler in the queue
		if typeof priorityQueue == "object" {
			priorityQueue->insert(handler, priority);
		} else {
			// Append the events to the queue
			let priorityQueue[] = handler;
			let this->_events[eventType] = priorityQueue;
		}

	}

	/**
	 * Detach the listener from the events manager
	 *
	 * @param string eventType
	 * @param object handler
	 */
	public function detach(string! eventType, var handler)
	{
		var priorityQueue, newPriorityQueue, key, data;

		if typeof handler != "object" {
			throw new Exception("Event handler must be an Object");
		}

		if fetch priorityQueue, this->_events[eventType] {

			if typeof priorityQueue == "object" {

				// SplPriorityQueue hasn't method for element deletion, so we need to rebuild queue
				let newPriorityQueue = new PriorityQueue();
				newPriorityQueue->setExtractFlags(\SplPriorityQueue::EXTR_DATA);

				priorityQueue->setExtractFlags(PriorityQueue::EXTR_BOTH);
				priorityQueue->top();

				while priorityQueue->valid() {
					let data = priorityQueue->current();
					priorityQueue->next();
					if data["data"] !== handler {
						newPriorityQueue->insert(data["data"], data["priority"]);
					}
				}

				let this->_events[eventType] = newPriorityQueue;
			} else {
				let key = array_search(handler, priorityQueue, true);
				if key !== false {
					unset priorityQueue[key];
				}
				let this->_events[eventType] = priorityQueue;
			}
		}
	}

	/**
	 * Set if priorities are enabled in the EventsManager
	 */
	public function enablePriorities(boolean enablePriorities)
	{
		let this->_enablePriorities = enablePriorities;
	}

	/**
	 * Returns if priorities are enabled
	 */
	public function arePrioritiesEnabled() -> boolean
	{
		return this->_enablePriorities;
	}

	/**
	 * Tells the event manager if it needs to collect all the responses returned by every
	 * registered listener in a single fire
	 */
	public function collectResponses(boolean collect)
	{
		let this->_collect = collect;
	}

	/**
	 * Check if the events manager is collecting all all the responses returned by every
	 * registered listener in a single fire
	 */
	public function isCollecting() -> boolean
	{
		return this->_collect;
	}

	/**
	 * Returns all the responses returned by every handler executed by the last 'fire' executed
	 *
	 * @return array
	 */
	public function getResponses()
	{
		return this->_responses;
	}

	/**
	 * Removes all events from the EventsManager
	 */
	public function detachAll(string! type = null)
	{
		if type === null {
			let this->_events = null;
		} else {
			if isset this->_events[type] {
				unset this->_events[type];
			}
		}
	}

	/**
	 * Alias of detachAll
	 */
	public function dettachAll(string! type = null)
	{
		this->detachAll(type);
	}

	/**
	 * Internal handler to call a queue of events
	 *
	 * @param \SplPriorityQueue|array queue
	 * @param Phalcon\Events\Event event
	 * @return mixed
	 */
	public final function fireQueue(var queue, <Event> event)
	{
		var status, arguments, eventName, data, iterator, source, handler;
		boolean collect, cancelable;

		if typeof queue != "array" {
			if typeof queue == "object" {
				if !(queue instanceof \SplPriorityQueue) {
					throw new Exception(sprintf("Unexpected value type: expected object of type SplPriorityQueue, %s given", get_class(queue)));
				}
			} else {
				throw new Exception("The queue is not valid");
			}
		}

		let status = null, arguments = null;

		// Get the event type
		let eventName = event->getType();
		if typeof eventName != "string" {
			throw new Exception("The event type not valid");
		}

		// Get the object who triggered the event
		let source = event->getSource();

		// Get extra data passed to the event
		let data = event->getData();

		// Tell if the event is cancelable
		let cancelable = (boolean) event->getCancelable();

		// Responses need to be traced?
		let collect = (boolean) this->_collect;

		if typeof queue == "object" {

			// We need to clone the queue before iterate over it
			let iterator = clone queue;

			// Move the queue to the top
			iterator->top();

			while iterator->valid() {

				// Get the current data
				let handler = iterator->current();
				iterator->next();

				// Only handler objects are valid
				if typeof handler == "object" {

					// Check if the event is a closure
					if handler instanceof \Closure {

						// Create the closure arguments
						if arguments === null {
							let arguments = [event, source, data];
						}

						// Call the function in the PHP userland
						let status = call_user_func_array(handler, arguments);

						// Trace the response
						if collect {
							let this->_responses[] = status;
						}

						if cancelable {

							// Check if the event was stopped by the user
							if event->isStopped() {
								break;
							}
						}

					} else {

						// Check if the listener has implemented an event with the same name
						if method_exists(handler, eventName) {

							// Call the function in the PHP userland
							let status = handler->{eventName}(event, source, data);

							// Collect the response
							if collect {
								let this->_responses[] = status;
							}

							if cancelable {

								// Check if the event was stopped by the user
								if event->isStopped() {
									break;
								}
							}
						}
					}
				}

			}

		} else {

			for handler in queue {

				// Only handler objects are valid
				if typeof handler == "object" {

					// Check if the event is a closure
					if handler instanceof \Closure {

						// Create the closure arguments
						if arguments === null {
							let arguments = [event, source, data];
						}

						// Call the function in the PHP userland
						let status = call_user_func_array(handler, arguments);

						// Trace the response
						if collect {
							let this->_responses[] = status;
						}

						if cancelable {

							// Check if the event was stopped by the user
							if event->isStopped() {
								break;
							}
						}

					} else {

						// Check if the listener has implemented an event with the same name
						if method_exists(handler, eventName) {

							// Call the function in the PHP userland
							let status = handler->{eventName}(event, source, data);

							// Collect the response
							if collect {
								let this->_responses[] = status;
							}

							if cancelable {

								// Check if the event was stopped by the user
								if event->isStopped() {
									break;
								}
							}

						}

					}
				}
			}
		}

		return status;
	}

	/**
	 * Fires an event in the events manager causing that active listeners be notified about it
	 *
	 *<code>
	 *	$eventsManager->fire('db', $connection);
	 *</code>
	 *
	 * @param string eventType
	 * @param object source
	 * @param mixed  data
	 * @param boolean cancelable
	 * @return mixed
	 */
	public function fire(string! eventType, source, data = null, boolean cancelable = true)
	{
		var events, eventParts, type, eventName, event, status, fireEvents;

		let events = this->_events;
		if typeof events != "array" {
			return null;
		}

		// All valid events must have a colon separator
		if !memstr(eventType, ":") {
			throw new Exception("Invalid event type " . eventType);
		}

		let eventParts = explode(":", eventType),
			type = eventParts[0],
			eventName = eventParts[1];

		let status = null;

		// Responses must be traced?
		if this->_collect {
			let this->_responses = null;
		}

		let event = null;

		// Check if events are grouped by type
		if fetch fireEvents, events[type] {

			if typeof fireEvents == "object" || typeof fireEvents == "array" {

				// Create the event context
				let event = new Event(eventName, source, data, cancelable);

				// Call the events queue
				let status = this->fireQueue(fireEvents, event);

			}
		}

		// Check if there are listeners for the event type itself
		if fetch fireEvents, events[eventType] {

			if typeof fireEvents == "object" || typeof fireEvents == "array" {

				// Create the event if it wasn't created before
				if event === null {
					let event = new Event(eventName, source, data, cancelable);
				}

				// Call the events queue
				let status = this->fireQueue(fireEvents, event);
			}

		}

		return status;
	}

	/**
	 * Check whether certain type of event has listeners
	 */
	public function hasListeners(string! type) -> boolean
	{
		return isset this->_events[type];
	}

	/**
	 * Returns all the attached listeners of a certain type
	 *
	 * @param string type
	 * @return array
	 */
	public function getListeners(string! type)
	{
		var events, fireEvents;
		let events = this->_events;
		if typeof events == "array" {
			if fetch fireEvents, events[type] {
				return fireEvents;
			}
		}
		return [];
	}
}
