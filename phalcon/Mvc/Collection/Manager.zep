
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection;

use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of collections, keeping record of relations
 * between the different collections of the application.
 *
 * A CollectionManager is injected to a collection via a Dependency Injector Container such as Phalcon\Di.
 *
 * ```php
 * $di = new \Phalcon\Di();
 *
 * $di->set(
 *     "collectionManager",
 *     function () {
 *         return new \Phalcon\Mvc\Collection\Manager();
 *     }
 * );
 *
 * $robot = new Robots($di);
 * ```
 */
class Manager implements ManagerInterface, InjectionAwareInterface, EventsAwareInterface
{
    protected behaviors;

    protected connectionServices;

    protected container;

    protected customEventsManager;

    protected eventsManager;

    protected implicitObjectsIds;

    protected initialized;

    protected lastInitialized;

    protected serviceName = "mongo" { get, set };

    /**
     * Binds a behavior to a collection
     */
    public function addBehavior(<CollectionInterface> collection, <BehaviorInterface> behavior)
    {
        var entityName, collectionsBehaviors;

        let entityName = get_class_lower(collection);

        /**
         * Get the current behaviors
         */
        if !fetch collectionsBehaviors, this->behaviors[entityName] {
            let collectionsBehaviors = [];
        }

        /**
         * Append the behavior to the list of behaviors
         */
        let collectionsBehaviors[] = behavior;

        /**
         * Update the behaviors list
         */
        let this->behaviors[entityName] = collectionsBehaviors;
    }

    /**
     * Returns a custom events manager related to a collection
     */
    public function getCustomEventsManager(<CollectionInterface> collection) -> var | null
    {
        var customEventsManager, className;

        let customEventsManager = this->customEventsManager;
        if typeof customEventsManager == "array" {
            let className = get_class_lower(collection);
            if isset customEventsManager[className] {
                return customEventsManager[className];
            }
        }

        return null;
    }

    /**
     * Returns the connection related to a collection
     *
     * @return \MongoDB\Database
     */
    public function getConnection(<CollectionInterface> collection)
    {
        var service, connectionService, connection, container, entityName;

        let service = this->serviceName;
        let connectionService = this->connectionServices;
        if typeof connectionService == "array" {
            let entityName = get_class(collection);

            /**
            * Check if the collection has a custom connection service
            */
            if isset connectionService[entityName] {
                let service = connectionService[entityName];
            }
        }

        let container = this->container;
        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound(
                    "the services related to the ODM"
                )
            );
        }

        /**
         * Request the connection service from the DI
         */
        let connection = container->getShared(service);
        if unlikely typeof connection != "object" {
            throw new Exception("Invalid injected connection service");
        }

        return connection;
    }

    /**
     * Gets a connection service for a specific collection
     */
    public function getConnectionService(<CollectionInterface> collection) -> string
    {
        var service, entityName;

        let service = this->serviceName;
        let entityName = get_class(collection);
        if isset this->connectionServices[entityName] {
            let service = this->connectionServices[entityName];
        }

        return service;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <EventsManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Get the latest initialized collection
     */
    public function getLastInitialized() -> <CollectionInterface>
    {
        return this->lastInitialized;
    }

    /**
     * Checks if a collection is using implicit object ids
     */
    public function isUsingImplicitObjectIds(<CollectionInterface> collection) -> bool
    {
        var implicit;

        /**
        * All collections use by default are using implicit object ids
        */
        if fetch implicit, this->implicitObjectsIds[get_class(collection)] {
            return implicit;
        }

        return true;
    }

    /**
     * Check whether a collection is already initialized
     */
    public function isInitialized(string! className) -> bool
    {
        return isset this->initialized[strtolower(className)];
    }

    /**
     * Initializes a collection in the collections manager
     */
    public function initialize(<CollectionInterface> collection) -> void
    {
        var className, initialized, eventsManager;

        let className = get_class_lower(collection);
        let initialized = this->initialized;

        /**
         * Collections are just initialized once per request
         */
        if !isset initialized[className] {
            /**
             * Call the 'initialize' method if it's implemented
             */
            if method_exists(collection, "initialize") {
                collection->{"initialize"}();
            }

            /**
             * If an EventsManager is available we pass to it every initialized collection
             */
            let eventsManager = this->eventsManager;
            if typeof eventsManager == "object" {
                eventsManager->fire("collectionManager:afterInitialize", collection);
            }

            let this->initialized[className] = collection;
            let this->lastInitialized = collection;
        }
    }

    /**
     * Dispatch an event to the listeners and behaviors
     * This method expects that the endpoint listeners/behaviors returns true
     * meaning that at least one was implemented
     */
    public function missingMethod(<CollectionInterface> collection, string! eventName, var data) -> bool
    {
        var behaviors, collectionsBehaviors, result, eventsManager, behavior;

        /**
         * Dispatch events to the global events manager
         */
        let behaviors = this->behaviors;
        if typeof behaviors == "array" {

            if fetch collectionsBehaviors, behaviors[get_class_lower(collection)] {

                /**
                 * Notify all the events on the behavior
                 */
                for behavior in collectionsBehaviors {
                    let result = behavior->missingMethod(collection, eventName, data);
                    if result !== null {
                        return result;
                    }
                }
            }
        }

        /**
         * Dispatch events to the global events manager
         */
        let eventsManager = this->eventsManager;
        if typeof eventsManager == "object" {
            return eventsManager->fire("collection:" . eventName, collection, data);
        }

        return false;
    }

    /**
     * Receives events generated in the collections and dispatches them to an events-manager if available
     * Notify the behaviors that are listening in the collection
     */
    public function notifyEvent(string! eventName, <CollectionInterface> collection)
    {
        var behavior, behaviors, collectionsBehaviors, eventsManager, status = null,
            customEventsManager;

        let behaviors = this->behaviors;
        if typeof behaviors == "array" {
            if fetch collectionsBehaviors, behaviors[get_class_lower(collection)] {

                /**
                 * Notify all the events on the behavior
                 */
                for behavior in collectionsBehaviors {
                    let status = behavior->notify(eventName, collection);
                    if status === false {
                        return false;
                    }
                }
            }
        }

        /**
         * Dispatch events to the global events manager
         */
        let eventsManager = this->eventsManager;
        if typeof eventsManager == "object" {
            let status = eventsManager->fire( "collection:". eventName, collection);
            if !status {
                return status;
            }
        }

        /**
         * A collection can has a specific events manager for it
         */
        let customEventsManager = this->customEventsManager;
        if typeof customEventsManager == "array" {
            if isset customEventsManager[get_class_lower(collection)] {
                let status = customEventsManager->fire("collection:" . eventName, collection);
                if !status {
                    return status;
                }
            }
        }

        return status;
    }

    /**
     * Sets a custom events manager for a specific collection
     */
    public function setCustomEventsManager(<CollectionInterface> collection, <EventsManagerInterface> eventsManager) -> void
    {
        let this->customEventsManager[get_class(collection)] = eventsManager;
    }

    /**
     * Sets a connection service for a specific collection
     */
    public function setConnectionService(<CollectionInterface> collection, string! connectionService) -> void
    {
        let this->connectionServices[get_class(collection)] = connectionService;
    }

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets the event manager
     */
    public function setEventsManager(<EventsManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Sets whether a collection must use implicit objects ids
     */
    public function useImplicitObjectIds(<CollectionInterface> collection, bool useImplicitObjectIds) -> void
    {
        let this->implicitObjectsIds[get_class(collection)] = useImplicitObjectIds;
    }
}
