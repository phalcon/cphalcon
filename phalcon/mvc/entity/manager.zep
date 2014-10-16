
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Entity;

use Phalcon\Mvc\EntityInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

class Manager implements ManagerInterface, InjectionAwareInterface, EventsAwareInterface
{
	protected _dependencyInjector;

	protected _eventsManager;

	protected _customEventsManager;

	/**
	 * Mark initialized entities
	 */
	protected _initialized;

	/**
	 * Entities' behaviors
	 */
	protected _behaviors;

	/**
	 * Last entity initialized
	 */
	protected _lastInitialized;

	protected _keepSnapshots;

	protected _dynamicUpdate;

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<\Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <\Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a global events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<EventsManagerInterface> eventsManager) -> <Manager>
	{
		let this->_eventsManager = eventsManager;
		return this;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <EventsManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets a custom events manager for a specific entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setCustomEventsManager(<EntityInterface> entity, <EventsManagerInterface> eventsManager)
	{
		let this->_customEventsManager[get_class_lower(entity)] = eventsManager;
	}

	/**
	 * Returns a custom events manager related to a entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getCustomEventsManager(<EntityInterface> entity) -> <EventsManagerInterface> | boolean
	{
		var customEventsManager, eventsManager;
		let customEventsManager = this->_customEventsManager;
		if typeof customEventsManager == "array" {
			if fetch eventsManager, customEventsManager[get_class_lower(entity)] {
				return eventsManager;
			}
		}
		return false;
	}

	/**
	 * Initializes a entity in the entity manager
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @return boolean
	 */
	public function initialize(<EntityInterface> entity) -> boolean
	{
		var className, eventsManager;

		let className = get_class_lower(entity);

		/**
		 * Entities are just initialized once per request
		 */
		if isset this->_initialized[className] {
			return false;
		}

		/**
		 * Update the entity as initialized, this avoid cyclic initializations
		 */
		let this->_initialized[className] = entity;

		/**
		 * Call the 'initialize' method if it's implemented
		 */
		if method_exists(entity, "initialize") {
			entity->{"initialize"}();
		}

		/**
		 * Update the last initialized entity, so it can be used in entitiesManager:afterInitialize
		 */
		let this->_lastInitialized = entity;

		/**
		 * If an EventsManager is available we pass to it every initialized entity
		 */
		let eventsManager = <EventsManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("entityManager:afterInitialize", this, entity);
		}

		return true;
	}

	/**
	 * Check whether a entity is already initialized
	 *
	 * @param string entityName
	 * @return bool
	 */
	public function isInitialized(string! entityName) -> boolean
	{
		return isset this->_initialized[strtolower(entityName)];
	}

	/**
	 * Get last initialized entity
	 *
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function getLastInitialized() -> <EntityInterface>
	{
		return this->_lastInitialized;
	}

	/**
	 * Loads a entity throwing an exception if it doesn't exist
	 *
	 * @param  string entityName
	 * @param  boolean newInstance
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function load(string! entityName, boolean newInstance = false) -> <EntityInterface>
	{
		var entity;

		/**
		 * Check if a entity with the same is already loaded
		 */
		if fetch entity, this->_initialized[strtolower(entityName)] {
			if newInstance {
				return new {entityName}(this->_dependencyInjector, this);
			}
			return entity;
		}

		/**
		 * Load it using an autoloader
		 */
		if class_exists(entityName) {
			return new {entityName}(this->_dependencyInjector, this);
		}

		/**
		 * The entity doesn't exist throw an exception
		 */
		throw new Exception("Entity '" . entityName . "' could not be loaded");
	}

	/**
	 * Receives events generated in the entities and dispatches them to a events-manager if available
	 * Notify the behaviors that are listening in the entity
	 *
	 * @param string eventName
	 * @param Phalcon\Mvc\EntityInterface entity
	 */
	public function notifyEvent(string! eventName, <EntityInterface> entity)
	{
		var status, behavior, entitiesBehaviors, eventsManager,
			customEventsManager, behaviors;

		let status = null;

		/**
		 * Dispatch events to the global events manager
		 */
		let behaviors = this->_behaviors;
		if typeof behaviors == "array" {
			if fetch entitiesBehaviors, behaviors[get_class_lower(entity)] {

				/**
				 * Notify all the events on the behavior
				 */
				for behavior in entitiesBehaviors {
					let status = behavior->notify(eventName, entity);
					if status === false {
						return false;
					}
				}
			}

		}

		/**
		 * Dispatch events to the global events manager
		 */
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			let status = eventsManager->fire("entity:" . eventName, entity);
			if status === false {
				return status;
			}
		}

		/**
		 * A entity can has a specific events manager for it
		 */
		let customEventsManager = this->_customEventsManager;
		if typeof customEventsManager == "array" {
			if fetch customEventsManager, customEventsManager[get_class_lower(entity)] {
				let status = customEventsManager->fire("entity:" . eventName, entity);
				if status === false {
					return false;
				}
			}
		}

		return status;
	}

	/**
	 * Dispatch a event to the listeners and behaviors
	 * This method expects that the endpoint listeners/behaviors returns true
	 * meaning that a least one was implemented
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param string eventName
	 * @param array data
	 * @return boolean
	 */
	public function missingMethod(<EntityInterface> entity, string! eventName, array! data) -> boolean
	{
		var behaviors, entitiesBehaviors, result, eventsManager, behavior;

		/**
		 * Dispatch events to the global events manager
		 */
		let behaviors = this->_behaviors;
		if typeof behaviors == "array" {

			if fetch entitiesBehaviors, behaviors[get_class_lower(entity)] {

				/**
				 * Notify all the events on the behavior
				 */
				for behavior in entitiesBehaviors {
					let result = behavior->missingMethod(entity, eventName, data);
					if result !== null {
						return result;
					}
				}
			}

		}

		/**
		 * Dispatch events to the global events manager
		 */
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			return eventsManager->fire("entity:" . eventName, entity, data);
		}

		return false;
	}

	/**
	 * Binds a behavior to a entity
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param Phalcon\Mvc\Entity\BehaviorInterface behavior
	 */
	public function addBehavior(<EntityInterface> entity, <\Phalcon\Mvc\Entity\BehaviorInterface> behavior)
	{
		var entityName, entitiesBehaviors;

		let entityName = get_class_lower(entity);

		/**
		 * Get the current behaviors
		 */
		if !fetch entitiesBehaviors, this->_behaviors[entityName] {
			let entitiesBehaviors = [];
		}

		/**
		 * Append the behavior to the list of behaviors
		 */
		let entitiesBehaviors[] = behavior;

		/**
		 * Update the behaviors list
		 */
		let this->_behaviors[entityName] = entitiesBehaviors;
	}

	/**
	 * Sets if a entity must keep snapshots
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param boolean keepSnapshots
	 */
	public function keepSnapshots(<EntityInterface> entity, boolean keepSnapshots) -> void
	{
		let this->_keepSnapshots[get_class_lower(entity)] = keepSnapshots;
	}

	/**
	 * Checks if a entity is keeping snapshots for the queried records
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @return boolean
	 */
	public function isKeepingSnapshots(<EntityInterface> entity) -> boolean
	{
		var keepSnapshots, isKeeping;
		let keepSnapshots = this->_keepSnapshots;
		if typeof keepSnapshots == "array" {
			if fetch isKeeping, keepSnapshots[get_class_lower(entity)] {
				return isKeeping;
			}
		}
		return false;
	}

	/**
	 * Sets if a entity must use dynamic update instead of the all-field update
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @param boolean dynamicUpdate
	 */
	public function useDynamicUpdate(<EntityInterface> entity, boolean dynamicUpdate)
	{
		var entityName;
		let entityName = get_class_lower(entity),
			this->_dynamicUpdate[entityName] = dynamicUpdate,
			this->_keepSnapshots[entityName] = dynamicUpdate;
	}

	/**
	 * Checks if a entity is using dynamic update instead of all-field update
	 *
	 * @param Phalcon\Mvc\Entity entity
	 * @return boolean
	 */
	public function isUsingDynamicUpdate(<EntityInterface> entity) -> boolean
	{
		var dynamicUpdate, isUsing;
		let dynamicUpdate = this->_dynamicUpdate;
		if typeof dynamicUpdate == "array" {
			if fetch isUsing, dynamicUpdate[get_class_lower(entity)] {
				return isUsing;
			}
		}
		return false;
	}
}
