
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

/**
 * Phalcon\Events\Manager
 *
 * Phalcon Events Manager, offers an easy way to intercept and manipulate, if needed,
 * the normal flow of operation. With the EventsManager the developer can create hooks or
 * plugins that will offer monitoring of data, manipulation, conditional execution and much more.
 *
 */
class Manager implements Phalcon\Events\ManagerInterface
{

	protected _events = null;

	protected _collect = false;

	protected _enablePriorities = false;

	protected _responses;

	/**
	 * Attach a listener to the events manager
	 *
	 * @param string eventType
	 * @param object handler
	 * @param int priority
	 */
	public function attach(string! eventType, var handler, int! priority=100)
	{
		var priorityQueue, events;

		if typeof handler != "object" {
			throw new Phalcon\Events\Exception("Event handler must be an Object");
		}

		let events = this->_events;
		if typeof events != "array" {
			let events = [];
		}

		if fetch priorityQueue, events[eventType] {

			if this->_enablePriorities {

				/**
				 * Create a SplPriorityQueue to store the events with priorities
				 */
				let priorityQueue = new SplPriorityQueue();

				/**
				 * Extract only the Data
				 * Set extraction flags
				 */
				priorityQueue->setExtractFlags(1);

				/**
				 * Append the events to the queue
				 */
				let events[eventType] = priorityQueue,
					this->_events = events;

			} else {
				let priorityQueue = [];
			}

		}

		/**
		 * Insert the handler in the queue
		 */
		if typeof priorityQueue == "object" {
			priorityQueue->insert(handler, priority);
		} else {

			/**
			 * Append the events to the queue
			 */
			let priorityQueue[] = handler,
				events[eventType] = priorityQueue,
				this->_events = events;
		}

	}

	/**
	 * Set if priorities are enabled in the EventsManager
	 *
	 * @param boolean enablePriorities
	 */
	public function enablePriorities(boolean enablePriorities)
	{
		let this->_enablePriorities = enablePriorities;
	}

	/**
	 * Returns if priorities are enabled
	 *
	 * @return boolean
	 */
	public function arePrioritiesEnabled() -> boolean
	{
		return this->_enablePriorities;
	}

	/**
	 * Tells the event manager if it needs to collect all the responses returned by every
	 * registered listener in a single fire
	 *
	 * @param boolean collect
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
	 *
	 * @param string type
	 */
	public function dettachAll(string type=null)
	{
		var events;
		let events = this->_events;
		if type === null {
			let events = null;
		} else {
			if isset events[type] {
				let events[type] = null;
			}
		}
		let this->_events = events;
	}

	/**
	 * Internal handler to call a queue of events
	 *
	 * @param \SplPriorityQueue|array queue
	 * @param Phalcon\Events\Event event
	 * @return mixed
	 */
	public function fireQueue(var queue, var event)
	{
		var status, arguments, eventName, data, iterator, source, handler;
		boolean collect, cancelable;

		if typeof queue != "array" && typeof queue != "object" {
			throw new Phalcon\Events\Exception("The queue is not valid");
		}

		if typeof event != "object" {
			throw new Phalcon\Events\Exception("The event is not valid");
		}

		let status = null, arguments = null;

		/**
		 * Get the event type
		 */
		let eventName = event->getType();
		if typeof eventName != "string" {
			throw new Phalcon\Events\Exception("The event type not valid");
		}

		/**
		 * Get the object who triggered the event
		 */
		let source = event->getSource();

		/**
		 * Get extra data passed to the event
		 */
		let data = event->getData();

		/**
		 * Tell if the event is cancelable
		 */
		let cancelable = (boolean) event->getCancelable();

		/**
		 * Responses need to be traced?
		 */
		let collect = (boolean) this->_collect;

		if queue == "object" {

			/**
			 * We need to clone the queue before iterate over it
			 */
			let iterator = clone queue;

			/**
			 * Move the queue to the top
			 */
			iterator->top();

			while iterator->valid() {

				/**
				 * Get the current data
				 */
				let handler = iterator->current();

				/**
				 * Only handler objects are valid
				 */
				if typeof handler == "object" {

					/**
					 * Check if the event is a closure
					 */
					if handler instanceof Closure {

						/**
						 * Create the closure arguments
						 */
						if arguments === null {
							let arguments = [event, source, data];
						}

						/**
						 * Call the function in the PHP userland
						 */
						let status = call_user_func_array(handler, arguments);

						/**
						 * Trace the response
						 */
						if collect {
							let this->_responses[] = status;
						}

						if cancelable {

							/**
							 * Check if the event was stopped by the user
						 	 */
							if event->isStopped() {
								break;
							}
						}

					} else {

						/**
						 * Check if the listener has implemented an event with the same name
						 */
						if method_exists(handler, eventName) {

							/**
							 * Call the function in the PHP userland
							 */
							let status = handler->{eventName}(event, source, data);

							/**
							 * Collect the response
							 */
							if collect {
								let this->_responses[] = status;
							}

							if cancelable {

								/**
								 * Check if the event was stopped by the user
						 		 */
								if event->isStopped() {
									break;
								}
							}

						}

					}
				}

			}

		} else {

			for queue in handler {

				/**
				 * Only handler objects are valid
				 */
				if typeof handler == "object" {

					/**
					 * Check if the event is a closure
					 */
					if handler instanceof Closure {

						/**
						 * Create the closure arguments
						 */
						if arguments === null {
							let arguments = [event, source, data];
						}

						/**
						 * Call the function in the PHP userland
						 */
						let status = call_user_func_array(handler, arguments);

						/**
						 * Trace the response
						 */
						if collect {
							let this->_responses[] = status;
						}

						if cancelable {

							/**
							 * Check if the event was stopped by the user
						 	 */
							if event->isStopped() {
								break;
							}
						}

					} else {

						/**
						 * Check if the listener has implemented an event with the same name
						 */
						if method_exists(handler, eventName) {

							/**
							 * Call the function in the PHP userland
							 */
							let status = handler->{eventName}(event, source, data);

							/**
							 * Collect the response
							 */
							if collect {
								let this->_responses[] = status;
							}

							if cancelable {

								/**
								 * Check if the event was stopped by the user
						 		 */
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
	public function fire(string! eventType, source, data=null, boolean cancelable=true)
	{
		var events, eventParts, type, eventName, event, status, fireEvents;

		let events = this->_events;
		if typeof events != "array" {
			return null;
		}

		/**
		 * All valid events must have a colon separator
		 */
		if !memstr(eventType, ":") {
			throw new Phalcon\Events\Exception("Invalid event type " . eventType);
		}

		let eventParts = explode(":", eventType),
			type = eventParts[0],
			eventName = eventParts[1];

		let status = null;

		/**
		 * Responses must be traced?
		 */
		if this->_collect {
			let this->_responses = null;
		}

		let event = null;

		/**
		 * Check if events are grouped by type
		 */
		if fetch fireEvents, events[type] {

			if typeof fireEvents == "object" || typeof fireEvents == "array" {

				/**
				 * Create the event context
				 */
				let event = new Phalcon\Events\Event(eventName, source, data, cancelable);

				/**
				 * Call the events queue
				 */
				let status = this->fireQueue(fireEvents, event);

			}
		}

		/**
		 * Check if there are listeners for the event type itself
		 */
		if fetch fireEvents, events[eventType] {

			if typeof fireEvents == "object" || typeof fireEvents == "array" {

				/**
				 * Create the event if it wasn't created before
				 */
				if event === null {
					let event = new Phalcon\Events\Event(eventName, source, data, cancelable);
				}

				/**
				 * Call the events queue
				 */
				let status = this->fireQueue(fireEvents, event);
			}

		}

		return status;
	}

	/**
	 * Check whether certain type of event has listeners
	 *
	 * @param string type
	 * @return boolean
	 */
	public function hasListeners(string! type)
	{
		var events;
		let events = this->_events;
		if typeof events == "array" {
			return isset events[type];
		}
		return false;
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
