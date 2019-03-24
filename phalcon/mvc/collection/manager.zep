
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection;

use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
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
 * </code>
 */
class Manager implements InjectionAwareInterface, EventsAwareInterface
{

    protected container;

    protected _initialized;

    protected _lastInitialized;

    protected eventsManager;

    protected _customEventsManager;

    protected _connectionServices;

    protected _implicitObjectsIds;

    protected _behaviors;

    protected _serviceName = "mongo" { get, set };

    /**
     * Sets the DependencyInjector container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Returns the DependencyInjector container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Sets the event manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface>
    {
        return this->eventsManager;
    }

    /**
     * Sets a custom events manager for a specific model
     */
    public function setCustomEventsManager(<CollectionInterface> model, <ManagerInterface> eventsManager) -> void
    {
        let this->_customEventsManager[get_class(model)] = eventsManager;
    }

    /**
     * Returns a custom events manager related to a model
     */
    public function getCustomEventsManager(<CollectionInterface> model) -> var | null
    {
        var customEventsManager, className;

        let customEventsManager = this->_customEventsManager;
        if typeof customEventsManager == "array" {
            let className = get_class_lower(model);
            if isset customEventsManager[className] {
                return customEventsManager[className];
            }
        }

        return null;
    }

    /**
     * Initializes a model in the models manager
     */
    public function initialize(<CollectionInterface> model) -> void
    {
        var className, initialized, eventsManager;

        let className = get_class(model);
        let initialized = this->_initialized;

        /**
        * Models are just initialized once per request
        */
        if !isset initialized[className] {

            /**
            * Call the 'initialize' method if it's implemented
            */
            if method_exists(model, "initialize") {
                model->{"initialize"}();
            }

            /**
            * If an EventsManager is available we pass to it every initialized model
            */
            let eventsManager = this->eventsManager;
            if typeof eventsManager == "object" {
                eventsManager->fire("collectionManager:afterInitialize", model);
            }

            let this->_initialized[className] = model;
            let this->_lastInitialized = model;
        }
    }

    /**
     * Check whether a model is already initialized
     */
    public function isInitialized(string! modelName) -> bool
    {
        return isset this->_initialized[strtolower(modelName)];
    }

    /**
     * Get the latest initialized model
     */
    public function getLastInitialized() -> <CollectionInterface>
    {
        return this->_lastInitialized;
    }

    /**
     * Sets a connection service for a specific model
     */
    public function setConnectionService(<CollectionInterface> model, string! connectionService) -> void
    {
        let this->_connectionServices[get_class(model)] = connectionService;
    }

    /**
     * Gets a connection service for a specific model
     */
    public function getConnectionService(<CollectionInterface> model) -> string
    {
        var service, entityName;

        let service = this->_serviceName;
        let entityName = get_class(model);
        if isset this->_connectionServices[entityName] {
            let service = this->_connectionServices[entityName];
        }

        return service;
    }

    /**
     * Sets whether a model must use implicit objects ids
     */
    public function useImplicitObjectIds(<CollectionInterface> model, bool useImplicitObjectIds) -> void
    {
        let this->_implicitObjectsIds[get_class(model)] = useImplicitObjectIds;
    }

    /**
     * Checks if a model is using implicit object ids
     */
    public function isUsingImplicitObjectIds(<CollectionInterface> model) -> bool
    {
        var implicit;

        /**
        * All collections use by default are using implicit object ids
        */
        if fetch implicit, this->_implicitObjectsIds[get_class(model)] {
            return implicit;
        }

        return true;
    }

    /**
     * Returns the connection related to a model
     *
     * @return \Mongo
     */
    public function getConnection(<CollectionInterface> model)
    {
        var service, connectionService, connection, container, entityName;

        let service = this->_serviceName;
        let connectionService = this->_connectionServices;
        if typeof connectionService == "array" {
            let entityName = get_class(model);

            /**
            * Check if the model has a custom connection service
            */
            if isset connectionService[entityName] {
                let service = connectionService[entityName];
            }
        }

        let container = this->container;
        if typeof container != "object" {
            throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
        }

        /**
         * Request the connection service from the DI
         */
        let connection = container->getShared(service);
        if typeof connection != "object" {
            throw new Exception("Invalid injected connection service");
        }

        return connection;
    }

    /**
     * Receives events generated in the models and dispatches them to an events-manager if available
     * Notify the behaviors that are listening in the model
     */
    public function notifyEvent(string! eventName, <CollectionInterface> model)
    {
        var behavior, behaviors, modelsBehaviors, eventsManager, status = null, customEventsManager;

        let behaviors = this->_behaviors;
        if typeof behaviors == "array" {
            if fetch modelsBehaviors, behaviors[get_class_lower(model)] {

                /**
                 * Notify all the events on the behavior
                 */
                for behavior in modelsBehaviors {
                    let status = behavior->notify(eventName, model);
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
            let status = eventsManager->fire( "collection:". eventName, model);
            if !status {
                return status;
            }
        }

        /**
         * A model can has a specific events manager for it
         */
        let customEventsManager = this->_customEventsManager;
        if typeof customEventsManager == "array" {
            if isset customEventsManager[get_class_lower(model)] {
                let status = customEventsManager->fire("collection:" . eventName, model);
                if !status {
                    return status;
                }
            }
        }

        return status;
    }

    /**
     * Dispatch an event to the listeners and behaviors
     * This method expects that the endpoint listeners/behaviors returns true
     * meaning that at least one was implemented
     */
    public function missingMethod(<CollectionInterface> model, string! eventName, var data) -> bool
    {
        var behaviors, modelsBehaviors, result, eventsManager, behavior;

        /**
         * Dispatch events to the global events manager
         */
        let behaviors = this->_behaviors;
        if typeof behaviors == "array" {

            if fetch modelsBehaviors, behaviors[get_class_lower(model)] {

                /**
                 * Notify all the events on the behavior
                 */
                for behavior in modelsBehaviors {
                    let result = behavior->missingMethod(model, eventName, data);
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
            return eventsManager->fire("model:" . eventName, model, data);
        }

        return false;
    }

    /**
     * Binds a behavior to a model
     */
    public function addBehavior(<CollectionInterface> model, <BehaviorInterface> behavior)
    {
        var entityName, modelsBehaviors;

        let entityName = get_class_lower(model);

        /**
         * Get the current behaviors
         */
        if !fetch modelsBehaviors, this->_behaviors[entityName] {
            let modelsBehaviors = [];
        }

        /**
         * Append the behavior to the list of behaviors
         */
        let modelsBehaviors[] = behavior;

        /**
         * Update the behaviors list
         */
        let this->_behaviors[entityName] = modelsBehaviors;
    }
}
