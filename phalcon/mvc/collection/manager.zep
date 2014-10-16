
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

namespace Phalcon\Mvc\Collection;

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\EntityInterface;
use Phalcon\Mvc\Entity\Manager as EntityManager;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of collections, keeping record of relations
 * between the different collections of the application.
 *
 * A CollectionManager is injected to a collection via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set('collectionManager', function(){
 *      return new \Phalcon\Mvc\Collection\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
class Manager extends EntityManager implements ManagerInterface
{
	protected _connectionServices;

	protected _implicitObjectsIds;


	/**
	 * Initializes a collection in the collection manager
	 *
	 * @param Phalcon\Mvc\EntityInterface entity
	 * @return boolean
	 */
	public function initialize(<EntityInterface> entity) -> boolean
	{
		var status, eventsManager;

		let status = parent::initialize(entity);

		if status !== true {
			return false;
		}

		/**
		 * If an EventsManager is available we pass to it every initialized entity
		 */
		let eventsManager = <EventsManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("collectionManager:afterInitialize", this, entity);
		}

		return true;
	}

	/**
	 * Sets a connection service for a specific collection
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @param string connectionService
	 */
	public function setConnectionService(<CollectionInterface> collection, string! connectionService) -> void
	{
		let this->_connectionServices[get_class(collection)] = connectionService;
	}

	/**
	 * Sets whether a collection must use implicit objects ids
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @param boolean useImplicitObjectIds
	 */
	public function useImplicitObjectIds(<CollectionInterface> collection, boolean useImplicitObjectIds) -> void
	{
		let this->_implicitObjectsIds[get_class(collection)] = useImplicitObjectIds;
	}

	/**
	 * Checks if a collection is using implicit object ids
	 *
	 * @param Phalcon\Mvc\CollectionInterface collection
	 * @return boolean
	 */
	public function isUsingImplicitObjectIds(<CollectionInterface> collection) -> boolean
	{
		var implicit;

		/**
		* All collections use by default are using implicit object ids
		*/
		if fetch implicit, this->_implicitObjectsIds[get_class(collection)] {
			return implicit;
		}

		return true;
	}

	/**
	 * Returns the connection related to a collection
	 *
	 * @param Phalcon\Mvc\CollectionInterface $collection
	 * @return \Mongo
	 */
	public function getConnection(<CollectionInterface> collection)
	{
		var service, connectionService, connection, dependencyInjector, entityName;

		if typeof collection != "object" {
			throw new Exception("A valid collection instance is required");
		}

		let service = "mongo";
		let connectionService = this->_connectionServices;
		if typeof connectionService == "array" {
			let entityName = get_class(collection);

			/**
			* Check if the collection has a custom connection service
			*/
			if isset connectionService[entityName] {
				let service = connectionService[entityName];
			}
		}

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Request the connection service from the DI
		 */
		let connection = dependencyInjector->getShared(service);
		if typeof connection != "object" {
			throw new Exception("Invalid injected connection service");
		}

		return connection;
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
			let status = eventsManager->fire("collection:" . eventName, entity);
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
				let status = customEventsManager->fire("collection:" . eventName, entity);
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
			return eventsManager->fire("collection:" . eventName, entity, data);
		}

		return false;
	}
}
