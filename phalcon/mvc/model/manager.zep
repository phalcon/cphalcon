
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Relation;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Mvc\Model\BehaviorInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\Di.
 *
 * <code>
 * use Phalcon\Di;
 * use Phalcon\Mvc\Model\Manager as ModelsManager;
 *
 * $di = new Di();
 *
 * $di->set(
 *     "modelsManager",
 *     function() {
 *         return new ModelsManager();
 *     }
 * );
 *
 * $robot = new Robots($di);
 * </code>
 */
class Manager implements ManagerInterface, InjectionAwareInterface, EventsAwareInterface
{

	protected _dependencyInjector;

	protected _eventsManager;

	protected _customEventsManager = [];

	protected _readConnectionServices = [];

	protected _writeConnectionServices = [];

	protected _aliases = [];

	protected _modelVisibility = [];

	/**
	 * Has many relations
	 */
	protected _hasMany = [];

	/**
	 * Has many relations by model
	 */
	protected _hasManySingle = [];

	/**
	 * Has one relations
	 */
	protected _hasOne = [];

	/**
	 * Has one relations by model
	 */
	protected _hasOneSingle = [];

	/**
	 * Belongs to relations
	 */
	protected _belongsTo = [];

	/**
	 * All the relationships by model
	 */
	protected _belongsToSingle = [];

	/**
	 * Has many-Through relations
	 */
	protected _hasManyToMany = [];

	/**
	 * Has many-Through relations by model
	 */
	protected _hasManyToManySingle = [];

	/**
	 * Mark initialized models
	 */
	protected _initialized = [];

	protected _prefix = "";

	protected _sources = [];

	protected _schemas = [];

	/**
	 * Models' behaviors
	 */
	protected _behaviors = [];

	/**
	 * Last model initialized
	 */
	protected _lastInitialized;

	/**
	 * Last query created/executed
	 */
	protected _lastQuery;

	/**
	 * Stores a list of reusable instances
	 */
	protected _reusable = [];

	protected _keepSnapshots = [];

	/**
	 * Does the model use dynamic update, instead of updating all rows?
	 */
	protected _dynamicUpdate = [];

	protected _namespaceAliases = [];

	/**
	 * Sets the DependencyInjector container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a global events manager
	 */
	public function setEventsManager(<EventsManagerInterface> eventsManager) -> <Manager>
	{
		let this->_eventsManager = eventsManager;
		return this;
	}

	/**
	 * Returns the internal event manager
	 */
	public function getEventsManager() -> <EventsManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Sets a custom events manager for a specific model
	 */
	public function setCustomEventsManager(<ModelInterface> model, <EventsManagerInterface> eventsManager)
	{
		let this->_customEventsManager[get_class_lower(model)] = eventsManager;
	}

	/**
	 * Returns a custom events manager related to a model
	 */
	public function getCustomEventsManager(<ModelInterface> model) -> <EventsManagerInterface> | boolean
	{
		var eventsManager;

		if !fetch eventsManager, this->_customEventsManager[get_class_lower(model)] {
			return false;
		}

		return eventsManager;
	}

	/**
	 * Initializes a model in the model manager
	 */
	public function initialize(<ModelInterface> model) -> boolean
	{
		var className, eventsManager;

		let className = get_class_lower(model);

		/**
		 * Models are just initialized once per request
		 */
		if isset this->_initialized[className] {
			return false;
		}

		/**
		 * Update the model as initialized, this avoid cyclic initializations
		 */
		let this->_initialized[className] = true;

		/**
		 * Call the 'initialize' method if it's implemented
		 */
		if method_exists(model, "initialize") {
			model->{"initialize"}();
		}

		/**
		 * Update the last initialized model, so it can be used in modelsManager:afterInitialize
		 */
		let this->_lastInitialized = model;

		/**
		 * If an EventsManager is available we pass to it every initialized model
		 */
		let eventsManager = <EventsManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("modelsManager:afterInitialize", this, model);
		}

		return true;
	}

	/**
	 * Check whether a model is already initialized
	 */
	public function isInitialized(string! modelName) -> boolean
	{
		return isset this->_initialized[strtolower(modelName)];
	}

	/**
	 * Get last initialized model
	 */
	public function getLastInitialized() -> <ModelInterface>
	{
		return this->_lastInitialized;
	}

	/**
	 * Loads a model throwing an exception if it doesn't exist
	 */
	public function load(string! modelName) -> <ModelInterface>
	{
		var model, colonPos, namespaceName, namespaceAlias, className;

		/**
		 * Check if a modelName is an alias
		 */
		let colonPos = strpos(modelName, ":");

		if colonPos !== false {
			let className = substr(modelName, colonPos + 1);
			let namespaceAlias = substr(modelName, 0, colonPos);
			let namespaceName = this->getNamespaceAlias(namespaceAlias);
			let modelName = namespaceName . "\\" . className;
		}

		/**
		 * The model doesn't exist throw an exception
		 */
		if !class_exists(modelName) {
			throw new Exception("Model '" . modelName . "' could not be loaded");
		}

		/**
		 * Load it using an autoloader
		 */
		let model = new {modelName}(null, this->_dependencyInjector, this);

		return model;
	}

	/**
	 * Sets the prefix for all model sources.
	 *
	 * <code>
	 * use Phalcon\Mvc\Model\Manager;
	 *
	 * $di->set("modelsManager", function () {
	 *     $modelsManager = new Manager();
	 *     $modelsManager->setModelPrefix("wp_");
	 *
	 *     return $modelsManager;
	 * });
	 *
	 * $robots = new Robots();
	 * echo $robots->getSource(); // wp_robots
	 * </code>
	 */
	public function setModelPrefix(string! prefix) -> void
	{
		let this->_prefix = prefix;
	}

	/**
	 * Returns the prefix for all model sources.
	 *
	 * <code>
	 * use Phalcon\Mvc\Model\Manager;
	 *
	 * $di->set("modelsManager", function () {
	 *     $modelsManager = new Manager();
	 *     $modelsManager->setModelPrefix("wp_");
	 *
	 *     return $modelsManager;
	 * });
	 *
	 * $robots = new Robots();
	 * echo $robots->getSource(); // wp_robots
	 * </code>
	 */
	public function getModelPrefix() -> string
	{
		return this->_prefix;
	}

	/**
	 * Sets the mapped source for a model
	 */
	public function setModelSource(<ModelInterface> model, string! source) -> void
	{
		let this->_sources[get_class_lower(model)] = source;
	}

	/**
	 * Check whether a model property is declared as public.
	 *
	 * <code>
	 * $isPublic = $manager->isVisibleModelProperty(
	 *     new Robots(),
	 *     "name"
	 * );
	 * </code>
	 */
	public final function isVisibleModelProperty(<ModelInterface> model, string property) -> boolean
	{
		var properties, className;

		let className = get_class(model);

		if !isset this->_modelVisibility[className] {
			let this->_modelVisibility[className] = get_object_vars(model);
		}

		let properties = this->_modelVisibility[className];

		return array_key_exists(property, properties);
	}

	/**
	 * Returns the mapped source for a model
	 */
	public function getModelSource(<ModelInterface> model) -> string
	{
		var entityName;

		let entityName = get_class_lower(model);

		if !isset this->_sources[entityName] {
			let this->_sources[entityName] = uncamelize(get_class_ns(model));
		}

		return this->_prefix . this->_sources[entityName];
	}

	/**
	 * Sets the mapped schema for a model
	 */
	public function setModelSchema(<ModelInterface> model, string! schema) -> void
	{
		let this->_schemas[get_class_lower(model)] = schema;
	}

	/**
	 * Returns the mapped schema for a model
	 */
	public function getModelSchema(<ModelInterface> model) -> string
	{
		var schema;

		if !fetch schema, this->_schemas[get_class_lower(model)] {
			return "";
		}

		return schema;
	}

	/**
	 * Sets both write and read connection service for a model
	 */
	public function setConnectionService(<ModelInterface> model, string! connectionService) -> void
	{
		this->setReadConnectionService(model, connectionService);
		this->setWriteConnectionService(model, connectionService);
	}

	/**
	 * Sets write connection service for a model
	 */
	public function setWriteConnectionService(<ModelInterface> model, string! connectionService) -> void
	{
		let this->_writeConnectionServices[get_class_lower(model)] = connectionService;
	}

	/**
	 * Sets read connection service for a model
	 */
	public function setReadConnectionService(<ModelInterface> model, string! connectionService) -> void
	{
		let this->_readConnectionServices[get_class_lower(model)] = connectionService;
	}

	/**
	 * Returns the connection to read data related to a model
	 */
	public function getReadConnection(<ModelInterface> model) -> <AdapterInterface>
	{
		return this->_getConnection(model, this->_readConnectionServices);
	}

	/**
	 * Returns the connection to write data related to a model
	 */
	public function getWriteConnection(<ModelInterface> model) -> <AdapterInterface>
	{
		return this->_getConnection(model, this->_writeConnectionServices);
	}

	/**
	 * Returns the connection to read or write data related to a model depending on the connection services.
	 */
	protected function _getConnection(<ModelInterface> model, connectionServices) -> <AdapterInterface>
	{
		var dependencyInjector, service, connection;

		let service = this->_getConnectionService(model, connectionServices);

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Request the connection service from the DI
		 */
		let connection = <AdapterInterface> dependencyInjector->getShared(service);

		if typeof connection != "object" {
			throw new Exception("Invalid injected connection service");
		}

		return connection;
	}

	/**
	 * Returns the connection service name used to read data related to a model
	 */
	public function getReadConnectionService(<ModelInterface> model) -> string
	{
		return this->_getConnectionService(model, this->_readConnectionServices);
	}

	/**
	 * Returns the connection service name used to write data related to a model
	 */
	public function getWriteConnectionService(<ModelInterface> model) -> string
	{
		return this->_getConnectionService(model, this->_writeConnectionServices);
	}

	/**
	 * Returns the connection service name used to read or write data related to
	 * a model depending on the connection services
	 */
	public function _getConnectionService(<ModelInterface> model, connectionServices) -> string
	{
		var connection;

		if !fetch connection, connectionServices[get_class_lower(model)] {
			return "db";
		}

		return connection;
	}

	/**
	 * Receives events generated in the models and dispatches them to an events-manager if available
	 * Notify the behaviors that are listening in the model
	 */
	public function notifyEvent(string! eventName, <ModelInterface> model)
	{
		var status, behavior, modelsBehaviors, eventsManager, customEventsManager;

		let status = null;

		/**
		 * Dispatch events to the global events manager
		 */
		if fetch modelsBehaviors, this->_behaviors[get_class_lower(model)] {

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

		/**
		 * Dispatch events to the global events manager
		 */
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			let status = eventsManager->fire("model:" . eventName, model);
			if status === false {
				return status;
			}
		}

		/**
		 * A model can has a specific events manager for it
		 */
		if fetch customEventsManager, this->_customEventsManager[get_class_lower(model)] {
			let status = customEventsManager->fire("model:" . eventName, model);
			if status === false {
				return false;
			}
		}

		return status;
	}

	/**
	 * Dispatch an event to the listeners and behaviors
	 * This method expects that the endpoint listeners/behaviors returns true
	 * meaning that a least one was implemented
	 */
	public function missingMethod(<ModelInterface> model, string! eventName, var data)
	{
		var modelsBehaviors, result, eventsManager, behavior;

		/**
		 * Dispatch events to the global events manager
		 */
		if fetch modelsBehaviors, this->_behaviors[get_class_lower(model)] {

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

		/**
		 * Dispatch events to the global events manager
		 */
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			return eventsManager->fire("model:" . eventName, model, data);
		}

		return null;
	}

	/**
	 * Binds a behavior to a model
	 */
	public function addBehavior(<ModelInterface> model, <BehaviorInterface> behavior)
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

	/**
	 * Sets if a model must keep snapshots
	 */
	public function keepSnapshots(<ModelInterface> model, boolean keepSnapshots) -> void
	{
		let this->_keepSnapshots[get_class_lower(model)] = keepSnapshots;
	}

	/**
	 * Checks if a model is keeping snapshots for the queried records
	 */
	public function isKeepingSnapshots(<ModelInterface> model) -> boolean
	{
		var isKeeping;

		if !fetch isKeeping, this->_keepSnapshots[get_class_lower(model)] {
			return false;
		}

		return isKeeping;
	}

	/**
	 * Sets if a model must use dynamic update instead of the all-field update
	 */
	public function useDynamicUpdate(<ModelInterface> model, boolean dynamicUpdate)
	{
		var entityName;
		let entityName = get_class_lower(model),
			this->_dynamicUpdate[entityName] = dynamicUpdate,
			this->_keepSnapshots[entityName] = dynamicUpdate;
	}

	/**
	 * Checks if a model is using dynamic update instead of all-field update
	 */
	public function isUsingDynamicUpdate(<ModelInterface> model) -> boolean
	{
		var isUsing;

		if !fetch isUsing, this->_dynamicUpdate[get_class_lower(model)] {
			return false;
		}

		return isUsing;
	}

	/**
	 * Setup a 1-1 relation between two models
	 *
	 * @param	array options
	 */
	public function addHasOne(<ModelInterface> model, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = get_class_lower(model),
			referencedEntity = strtolower(referencedModel);

		let keyRelation = entityName . "$" . referencedEntity;

		if !fetch relations, this->_hasOne[keyRelation] {
			let relations = [];
		}

		/**
		 * Check if the number of fields are the same
		 */
		if typeof referencedFields == "array" {
			if count(fields) != count(referencedFields) {
				throw new Exception("Number of referenced fields are not the same");
			}
		}

		/**
		 * Create a relationship instance
		 */
		let relation = new Relation(
			Relation::HAS_ONE,
			referencedModel,
			fields,
			referencedFields,
			options
		);

		/**
		 * Check an alias for the relation
		 */
		if fetch alias, options["alias"] {
			if typeof alias != "string" {
				throw new Exception("Relation alias must be a string");
			}
			let lowerAlias = strtolower(alias);
		} else {
			let lowerAlias = referencedEntity;
		}

		/**
		 * Append a new relationship
		 * Update the global alias
		 * Update the relations
		 */
		let relations[] = relation,
			this->_aliases[entityName . "$" . lowerAlias] = relation,
			this->_hasOne[keyRelation] = relations;

		/**
		 * Get existing relations by model
		 */
		if !fetch singleRelations, this->_hasOneSingle[entityName] {
			let singleRelations = [];
		}

		/**
		 * Append a new relationship
		 */
		let singleRelations[] = relation;

		/**
		 * Update relations by model
		 */
		let this->_hasOneSingle[entityName] = singleRelations;

		return relation;
	}

	/**
	 * Setup a relation reverse many to one between two models
	 *
	 * @param	array options
	 */
	public function addBelongsTo(<ModelInterface> model, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = get_class_lower(model),
			referencedEntity = strtolower(referencedModel);

		let keyRelation = entityName . "$" . referencedEntity;

		if !fetch relations, this->_belongsTo[keyRelation] {
			let relations = [];
		}

		/**
		 * Check if the number of fields are the same
		 */
		if typeof referencedFields == "array" {
			if count(fields) != count(referencedFields) {
				throw new Exception("Number of referenced fields are not the same");
			}
		}

		/**
		 * Create a relationship instance
		 */
		let relation = new Relation(
			Relation::BELONGS_TO,
			referencedModel,
			fields,
			referencedFields,
			options
		);

		/**
		 * Check an alias for the relation
		 */
		if fetch alias, options["alias"] {
			if typeof alias != "string" {
				throw new Exception("Relation alias must be a string");
			}
			let lowerAlias = strtolower(alias);
		} else {
			let lowerAlias = referencedEntity;
		}

		/**
		 * Append a new relationship
		 * Update the global alias
		 * Update the relations
		 */
		let relations[] = relation,
			this->_aliases[entityName . "$" . lowerAlias] = relation,
			this->_belongsTo[keyRelation] = relations;

		/**
		 * Get existing relations by model
		 */
		if !fetch singleRelations, this->_belongsToSingle[entityName] {
			let singleRelations = [];
		}

		/**
		 * Append a new relationship
		 */
		let singleRelations[] = relation;

		/**
		 * Update relations by model
		 */
		let this->_belongsToSingle[entityName] = singleRelations;

		return relation;
	}

	/**
	 * Setup a relation 1-n between two models
	 *
	 * @param	mixed referencedFields
	 * @param	array options
	 */
	public function addHasMany(<ModelInterface> model, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, hasMany, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = get_class_lower(model),
			referencedEntity = strtolower(referencedModel),
			keyRelation = entityName . "$" . referencedEntity;

		let hasMany = this->_hasMany;
		if !fetch relations, hasMany[keyRelation] {
			let relations = [];
		}

		/**
		 * Check if the number of fields are the same
		 */
		if typeof referencedFields == "array" {
			if count(fields) != count(referencedFields) {
				throw new Exception("Number of referenced fields are not the same");
			}
		}

		/**
		 * Create a relationship instance
		 */
		let relation = new Relation(
			Relation::HAS_MANY,
			referencedModel,
			fields,
			referencedFields,
			options
		);

		/**
		 * Check an alias for the relation
		 */
		if fetch alias, options["alias"] {
			if typeof alias != "string" {
				throw new Exception("Relation alias must be a string");
			}
			let lowerAlias = strtolower(alias);
		} else {
			let lowerAlias = referencedEntity;
		}

		/**
		 * Append a new relationship
		 * Update the global alias
		 * Update the relations
		 */
		let relations[] = relation,
			this->_aliases[entityName . "$" . lowerAlias] = relation,
			this->_hasMany[keyRelation] = relations;

		/**
		 * Get existing relations by model
		 */
		if !fetch singleRelations, this->_hasManySingle[entityName] {
			let singleRelations = [];
		}

		/**
		 * Append a new relationship
		 */
		let singleRelations[] = relation;

		/**
		 * Update relations by model
		 */
		let this->_hasManySingle[entityName] = singleRelations;

		return relation;
	}

	/**
	 * Setups a relation n-m between two models
	 *
	 * @param	string fields
	 * @param	string intermediateFields
	 * @param	string intermediateReferencedFields
	 * @param	string referencedFields
	 * @param   array options
	 */
	public function addHasManyToMany(<ModelInterface> model, var fields, string! intermediateModel,
		var intermediateFields, var intermediateReferencedFields, string! referencedModel, var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, hasManyToMany, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations, intermediateEntity;

		let entityName = get_class_lower(model),
			intermediateEntity = strtolower(intermediateModel),
			referencedEntity = strtolower(referencedModel),
			keyRelation = entityName . "$" . referencedEntity;

		let hasManyToMany = this->_hasManyToMany;
		if !fetch relations, hasManyToMany[keyRelation] {
			let relations = [];
		}

		/**
		 * Check if the number of fields are the same from the model to the intermediate model
		 */
		if typeof intermediateFields == "array" {
			if count(fields) != count(intermediateFields) {
				throw new Exception("Number of referenced fields are not the same");
			}
		}

		/**
		 * Check if the number of fields are the same from the intermediate model to the referenced model
		 */
		if typeof intermediateReferencedFields == "array" {
			if count(fields) != count(intermediateFields) {
				throw new Exception("Number of referenced fields are not the same");
			}
		}

		/**
		 * Create a relationship instance
		 */
		let relation = new Relation(
			Relation::HAS_MANY_THROUGH,
			referencedModel,
			fields,
			referencedFields,
			options
		);

		/**
		 * Set extended intermediate relation data
		 */
		relation->setIntermediateRelation(intermediateFields, intermediateModel, intermediateReferencedFields);

		/**
		 * Check an alias for the relation
		 */
		if fetch alias, options["alias"] {
			if typeof alias != "string" {
				throw new Exception("Relation alias must be a string");
			}
			let lowerAlias = strtolower(alias);
		} else {
			let lowerAlias = referencedEntity;
		}

		/**
		 * Append a new relationship
		 */
		let relations[] = relation;

		/**
		 * Update the global alias
		 */
		let this->_aliases[entityName . "$" . lowerAlias] = relation;

		/**
		 * Update the relations
		 */
		let this->_hasManyToMany[keyRelation] = relations;

		/**
		 * Get existing relations by model
		 */
		if !fetch singleRelations, this->_hasManyToManySingle[entityName] {
			let singleRelations = [];
		}

		/**
		 * Append a new relationship
		 */
		let singleRelations[] = relation;

		/**
		 * Update relations by model
		 */
		let this->_hasManyToManySingle[entityName] = singleRelations;

		return relation;
	}

	/**
	 * Checks whether a model has a belongsTo relation with another model
	 */
	public function existsBelongsTo(string! modelName, string! modelRelation) -> boolean
	{
		var entityName, keyRelation;

		let entityName = strtolower(modelName);

		/**
		 * Relationship unique key
		 */
		let keyRelation = entityName . "$" . strtolower(modelRelation);

		/**
		 * Initialize the model first
		 */
		if !isset this->_initialized[entityName] {
			this->load(modelName);
		}

		return isset this->_belongsTo[keyRelation];
	}

	/**
	 * Checks whether a model has a hasMany relation with another model
	 */
	public function existsHasMany(string! modelName, string! modelRelation) -> boolean
	{
		var entityName, keyRelation;

		let entityName = strtolower(modelName);

		/**
		 * Relationship unique key
		 */
		let keyRelation = entityName . "$" . strtolower(modelRelation);

		/**
		 * Initialize the model first
		 */
		if !isset this->_initialized[entityName] {
			this->load(modelName);
		}

		return isset this->_hasMany[keyRelation];
	}

	/**
	 * Checks whether a model has a hasOne relation with another model
	 */
	public function existsHasOne(string! modelName, string! modelRelation) -> boolean
	{
		var entityName, keyRelation;

		let entityName = strtolower(modelName);

		/**
		 * Relationship unique key
		 */
		let keyRelation = entityName . "$" . strtolower(modelRelation);

		/**
		 * Initialize the model first
		 */
		if !isset this->_initialized[entityName] {
			this->load(modelName);
		}

		return isset this->_hasOne[keyRelation];
	}

	/**
	 * Checks whether a model has a hasManyToMany relation with another model
	 */
	public function existsHasManyToMany(string! modelName, string! modelRelation) -> boolean
	{
		var entityName, keyRelation;

		let entityName = strtolower(modelName);

		/**
		 * Relationship unique key
		 */
		let keyRelation = entityName . "$" . strtolower(modelRelation);

		/**
		 * Initialize the model first
		 */
		if !isset this->_initialized[entityName] {
			this->load(modelName);
		}

		return isset this->_hasManyToMany[keyRelation];
	}

	/**
	 * Returns a relation by its alias
	 */
	public function getRelationByAlias(string! modelName, string! alias) -> <Relation> | boolean
	{
		var relation;

		if !fetch relation, this->_aliases[strtolower(modelName . "$" . alias)] {
			return false;
		}

		return relation;
	}

	/**
	 * Merge two arrays of find parameters
	 */
	protected final function _mergeFindParameters(var findParamsOne, var findParamsTwo) -> array
	{
		var key, value, findParams;

		if typeof findParamsOne == "string" && typeof findParamsTwo == "string" {
			return ["(" . findParamsOne . ") AND (" . findParamsTwo . ")"];
		}

		let findParams = [];
		if typeof findParamsOne == "array"  {

			for key, value in findParamsOne {

				if key === 0 || key === "conditions" {
					if !isset findParams[0] {
						let findParams[0] = value;
					} else {
						let findParams[0] = "(" . findParams[0] . ") AND (" . value . ")";
					}
					continue;
				}

				let findParams[key] = value;
			}
		} else {
			if typeof findParamsOne == "string" {
				let findParams = ["conditions": findParamsOne];
			}
		}

		if typeof findParamsTwo == "array"  {

			for key, value in findParamsTwo {

				if key === 0 || key === "conditions" {
					if !isset findParams[0] {
						let findParams[0] = value;
					} else {
						let findParams[0] = "(" . findParams[0] . ") AND (" . value . ")";
					}
					continue;
				}

				if key === "bind" || key === "bindTypes" {
					if !isset findParams[key] {
						if typeof value == "array" {
							let findParams[key] = value;
						}
					} else {
						if typeof value == "array" {
							let findParams[key] = array_merge(findParams[key], value);
						}
					}
					continue;
				}

				let findParams[key] = value;
			}
		} else {
			if typeof findParamsTwo == "string" {
				if !isset findParams[0] {
					let findParams[0] = findParamsTwo;
				} else {
					let findParams[0] = "(" . findParams[0] . ") AND (" . findParamsTwo . ")";
				}
			}
		}

		return findParams;
	}

	/**
	 * Helper method to query records based on a relation definition
	 *
	 * @return \Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|int|false
	 */
	public function getRelationRecords(<RelationInterface> relation, string! method, <ModelInterface> record, var parameters = null)
	{
		var placeholders, referencedModel, intermediateModel,
			intermediateFields, joinConditions, fields, builder, extraParameters,
			conditions, refPosition, field, referencedFields, findParams,
			findArguments, retrieveMethod, uniqueKey, records, arguments, rows, firstRow;
		boolean reusable;

		/**
		 * Re-use bound parameters
		 */
		let placeholders = [];

		/**
		 * Returns parameters that must be always used when the related records are obtained
		 */
		let extraParameters = relation->getParams();

		/**
		 * Perform the query on the referenced model
		 */
		let referencedModel = relation->getReferencedModel();

		/**
		 * Check if the relation is direct or through an intermediate model
		 */
		if relation->isThrough() {

			let conditions = [];

			let intermediateModel = relation->getIntermediateModel(),
				intermediateFields = relation->getIntermediateFields();

			/**
			 * Appends conditions created from the fields defined in the relation
			 */
			let fields = relation->getFields();
			if typeof fields != "array" {
				let conditions[] = "[" . intermediateModel . "].[" . intermediateFields . "] = :APR0:",
					placeholders["APR0"] = record->readAttribute(fields);
			} else {
				throw new Exception("Not supported");
			}

			let joinConditions = [];

			/**
			 * Create the join conditions
			 */
			let intermediateFields = relation->getIntermediateReferencedFields();
			if typeof intermediateFields != "array" {
				let joinConditions[] = "[" . intermediateModel . "].[" . intermediateFields . "] = [" . referencedModel . "].[" . relation->getReferencedFields() . "]";
			} else {
				throw new Exception("Not supported");
			}

			/**
			 * We don't trust the user or the database so we use bound parameters
			 * Create a query builder
			 */
			let builder = this->createBuilder(this->_mergeFindParameters(extraParameters, parameters));

			builder->from(referencedModel);
			builder->innerJoin(intermediateModel, join(" AND ", joinConditions));
			builder->andWhere(join(" AND ", conditions), placeholders);

			if method == "count" {
				builder->columns("COUNT(*) AS rowcount");

				let rows = builder->getQuery()->execute();

				let firstRow = rows->getFirst();

				return (int) firstRow->readAttribute("rowcount");
			}

			/**
			 * Get the query
			 * Execute the query
			 */
			return builder->getQuery()->execute();
		}

		let conditions = [];

		/**
		 * Appends conditions created from the fields defined in the relation
		 */
		let fields = relation->getFields();
		if typeof fields != "array" {
			let conditions[] = "[". relation->getReferencedFields() . "] = :APR0:",
				placeholders["APR0"] = record->readAttribute(fields);
		} else {

			/**
			 * Compound relation
			 */
			let referencedFields = relation->getReferencedFields();
			for refPosition, field in relation->getFields() {
				let conditions[] = "[". referencedFields[refPosition] . "] = :APR" . refPosition . ":",
					placeholders["APR" . refPosition] = record->readAttribute(field);
			}
		}

		/**
		 * We don't trust the user or data in the database so we use bound parameters
		 * Create a valid params array to pass to the find/findFirst method
		 */
		let findParams = [
			join(" AND ", conditions),
			"bind"      : placeholders,
			"di"        : record->{"getDi"}()
		];

		let findArguments = this->_mergeFindParameters(findParams, parameters);

		if typeof extraParameters == "array" {
			let findParams = this->_mergeFindParameters(findArguments, extraParameters);
		} else {
			let findParams = findArguments;
		}

		/**
		 * Check the right method to get the data
		 */
		if method === null {
			switch relation->getType() {

				case Relation::BELONGS_TO:
				case Relation::HAS_ONE:
					let retrieveMethod = "findFirst";
					break;

				case Relation::HAS_MANY:
					let retrieveMethod = "find";
					break;

				default:
					throw new Exception("Unknown relation type");
			}
		} else {
			let retrieveMethod = method;
		}

		let arguments = [findParams];

		/**
		 * Find first results could be reusable
		 */
		let reusable = (boolean) relation->isReusable();
		if reusable {
			let uniqueKey = unique_key(referencedModel, arguments),
				records = this->getReusableRecords(referencedModel, uniqueKey);
			if typeof records == "array" || typeof records == "object" {
				return records;
			}
		}

		/**
		 * Load the referenced model
		 * Call the function in the model
		 */
		let records = call_user_func_array([this->load(referencedModel), retrieveMethod], arguments);

		/**
		 * Store the result in the cache if it's reusable
		 */
		if reusable {
			this->setReusableRecords(referencedModel, uniqueKey, records);
		}

		return records;
	}

	/**
	 * Returns a reusable object from the internal list
	 */
	public function getReusableRecords(string! modelName, string! key)
	{
		var records;
		if fetch records, this->_reusable[key] {
			return records;
		}
		return null;
	}

	/**
	 * Stores a reusable record in the internal list
	 */
	public function setReusableRecords(string! modelName, string! key, var records)
	{
		let this->_reusable[key] = records;
	}

	/**
	 * Clears the internal reusable list
	 */
	public function clearReusableObjects()
	{
		let this->_reusable = [];
	}

	/**
	 * Gets belongsTo related records from a model
	 */
	public function getBelongsToRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ResultsetInterface> | boolean
	{
		var keyRelation, relations;

		/**
		 * Check if there is a relation between them
		 */
		let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
		if !fetch relations, this->_hasMany[keyRelation] {
			return false;
		}

		/**
		 * "relations" is an array with all the belongsTo relationships to that model
		 * Perform the query
		 */
		return this->getRelationRecords(relations[0], method, record, parameters);
	}

	/**
	 * Gets hasMany related records from a model
	 */
	public function getHasManyRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ResultsetInterface> | boolean
	{
		var keyRelation, relations;

		/**
		 * Check if there is a relation between them
		 */
		let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
		if !fetch relations, this->_hasMany[keyRelation] {
			return false;
		}

		/**
		 * "relations" is an array with all the hasMany relationships to that model
		 * Perform the query
		 */
		return this->getRelationRecords(relations[0], method, record, parameters);
	}

	/**
	 * Gets belongsTo related records from a model
	 */
	public function getHasOneRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ModelInterface> | boolean
	{
		var keyRelation, relations;

		/**
		 * Check if there is a relation between them
		 */
		let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
		if !fetch relations, this->_hasOne[keyRelation] {
			return false;
		}

		/**
		 * "relations" is an array with all the belongsTo relationships to that model
		 * Perform the query
		 */
		return this->getRelationRecords(relations[0], method, record, parameters);
	}

	/**
	 * Gets all the belongsTo relations defined in a model
	 *
	 *<code>
	 * $relations = $modelsManager->getBelongsTo(
	 *     new Robots()
	 * );
	 *</code>
	 */
	public function getBelongsTo(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var relations;

		if !fetch relations, this->_belongsToSingle[get_class_lower(model)] {
			return [];
		}

		return relations;
	}

	/**
	 * Gets hasMany relations defined on a model
	 */
	public function getHasMany(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var relations;

		if !fetch relations, this->_hasManySingle[get_class_lower(model)] {
			return [];
		}

		return relations;
	}

	/**
	 * Gets hasOne relations defined on a model
	 */
	public function getHasOne(<ModelInterface> model) -> array
	{
		var relations;

		if !fetch relations, this->_hasOneSingle[get_class_lower(model)] {
			return [];
		}

		return relations;
	}

	/**
	 * Gets hasManyToMany relations defined on a model
	 */
	public function getHasManyToMany(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var relations;

		if !fetch relations, this->_hasManyToManySingle[get_class_lower(model)] {
			return [];
		}

		return relations;
	}

	/**
	 * Gets hasOne relations defined on a model
	 */
	public function getHasOneAndHasMany(<ModelInterface> model) -> <RelationInterface[]>
	{
		return array_merge(this->getHasOne(model), this->getHasMany(model));
	}

	/**
	 * Query all the relationships defined on a model
	 */
	public function getRelations(string! modelName) -> <RelationInterface[]>
	{
		var entityName, allRelations, relations, relation;

		let entityName = strtolower(modelName),
			allRelations = [];

		/**
		 * Get belongs-to relations
		 */
		if fetch relations, this->_belongsToSingle[entityName] {
			for relation in relations {
				let allRelations[] = relation;
			}
		}

		/**
		 * Get has-many relations
		 */
		if fetch relations, this->_hasManySingle[entityName] {
			for relation in relations {
				let allRelations[] = relation;
			}
		}

		/**
		 * Get has-one relations
		 */
		if fetch relations, this->_hasOneSingle[entityName] {
			for relation in relations {
				let allRelations[] = relation;
			}
		}

		return allRelations;
	}

	/**
	 * Query the first relationship defined between two models
	 */
	public function getRelationsBetween(string! first, string! second) -> <RelationInterface[]> | boolean
	{
		var keyRelation, relations;

		let keyRelation = strtolower(first) . "$" . strtolower(second);

		/**
		 * Check if it's a belongs-to relationship
		 */
		if fetch relations, this->_belongsTo[keyRelation] {
			return relations;
		}

		/**
		 * Check if it's a has-many relationship
		 */
		if fetch relations, this->_hasMany[keyRelation] {
			return relations;
		}

		/**
		 * Check whether it's a has-one relationship
		 */
		if fetch relations, this->_hasOne[keyRelation] {
			return relations;
		}

		return false;
	}

	/**
	 * Creates a Phalcon\Mvc\Model\Query without execute it
	 */
	public function createQuery(string! phql) -> <QueryInterface>
	{
		var dependencyInjector, query;

		let dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access ORM services");
		}

		/**
		 * Create a query
		 */
		let query = <QueryInterface> dependencyInjector->get("Phalcon\\Mvc\\Model\\Query", [phql, dependencyInjector]);
		let this->_lastQuery = query;
		return query;
	}

	/**
	 * Creates a Phalcon\Mvc\Model\Query and execute it
	 */
	public function executeQuery(string! phql, var placeholders = null, var types = null) -> <QueryInterface>
	{
		var query;

		let query = this->createQuery(phql);

		if typeof placeholders == "array" {
			query->setBindParams(placeholders);
		}

		if typeof types == "array" {
			query->setBindTypes(types);
		}

		/**
		 * Execute the query
		 */
		return query->execute();
	}

	/**
	 * Creates a Phalcon\Mvc\Model\Query\Builder
	 */
	public function createBuilder(var params = null) -> <BuilderInterface>
	{
		var dependencyInjector;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access ORM services");
		}

		/**
		 * Gets Builder instance from DI container
		 */
		return <BuilderInterface> dependencyInjector->get(
			"Phalcon\\Mvc\\Model\\Query\\Builder",
			[
				params,
				dependencyInjector
			]
		);
	}

	/**
	 * Returns the last query created or executed in the models manager
	 */
	public function getLastQuery() -> <QueryInterface>
	{
		return this->_lastQuery;
	}

	/**
	 * Registers shorter aliases for namespaces in PHQL statements
	 */
	public function registerNamespaceAlias(string alias, string namespaceName) -> void
	{
		let this->_namespaceAliases[alias] = namespaceName;
	}

	/**
	 * Returns a real namespace from its alias
	 */
	public function getNamespaceAlias(string! alias) -> string
	{
		var namespaceName;

		if fetch namespaceName, this->_namespaceAliases[alias] {
			return namespaceName;
		}
		throw new Exception("Namespace alias '" . alias . "' is not registered");
	}

	/**
	 * Returns all the registered namespace aliases
	 */
	public function getNamespaceAliases() -> array
	{
		return this->_namespaceAliases;
	}

	/**
	 * Inserts a model instance. If the instance already exists in the persistence it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 *<code>
	 * // Creating a new robot
	 * $robot = new Robots();
	 *
	 * $robot->type = "mechanical";
	 * $robot->name = "Astro Boy";
	 * $robot->year = 1952;
	 *
	 * $modelsManager->create($robot);
	 *
	 * // Passing an array to create
	 * $robot = new Robots();
	 *
	 * $robot->assign(
	 *     [
	 *         "type" => "mechanical",
	 *         "name" => "Astro Boy",
	 *         "year" => 1952,
	 *     ]
	 * );
	 *
	 * $modelsManager->create($robot);
	 *</code>
	 */
	public function create(<ModelInterface> model) -> boolean
	{
		var metaData;

		let metaData = model->getModelsMetaData();

		/**
		 * Get the current connection
		 * If the record already exists we must throw an exception
		 */
		if model->exists(metaData, model->getReadConnection()) {
			model->clearMessages();

			model->appendMessage(
				new Message("Record cannot be created because it already exists", null, "InvalidCreateAttempt")
			);

			return false;
		}

		/**
		 * Using save() anyways
		 */
		return model->save();
	}

	/**
	 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 *<code>
	 * // Updating a robot name
	 * $robot = Robots::findFirst("id = 100");
	 *
	 * $robot->name = "Biomass";
	 *
	 * $modelsManager->update($robot);
	 *</code>
	 */
	public function update(<ModelInterface> model) -> boolean
	{
		var metaData;

		/**
		 * We don't check if the record exists if the record is already checked
		 */
		if model->getDirtyState() {

			let metaData = model->getModelsMetaData();

			if !model->exists(metaData, model->getReadConnection()) {
				model->clearMessages();

				model->appendMessage(
					new Message(
						"Record cannot be updated because it does not exist",
						null,
						"InvalidUpdateAttempt"
					)
				);

				return false;
			}
		}

		/**
		 * Call save() anyways
		 */
		return model->save();
	}

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 *
	 * <code>
	 * $robot = Robots::findFirst("id=100");
	 *
	 * $modelsManager->delete($robot);
	 *
	 * $robots = Robots::find("type = 'mechanical'");
	 *
	 * foreach ($robots as $robot) {
	 *     $modelsManager->delete($robot);
	 * }
	 * </code>
	 */
	public function delete(<ModelInterface> model) -> boolean
	{
		var metaData, writeConnection, values, bindTypes, primaryKeys,
			bindDataTypes, columnMap, attributeField, conditions, primaryKey,
			bindType, value, schema, source, table, success;

		let metaData = model->getModelsMetaData(),
			writeConnection = model->getWriteConnection();

		/**
		 * Operation made is OP_DELETE
		 */
		model->setOperationMade(Model::OP_DELETE);
		
		model->clearMessages();

		/**
		 * Check if deleting the record violates a virtual foreign key
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysReverseRestrict(model) === false {
				return false;
			}
		}

		let values = [],
			bindTypes = [],
			conditions = [];

		let primaryKeys = metaData->getPrimaryKeyAttributes(model),
			bindDataTypes = metaData->getBindTypes(model);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(model);
		} else {
			let columnMap = null;
		}

		/**
		 * We can't create dynamic SQL without a primary key
		 */
		if !count(primaryKeys) {
			throw new Exception("A primary key must be defined in the model in order to perform the operation");
		}

		/**
		 * Create a condition from the primary keys
		 */
		for primaryKey in primaryKeys {

			/**
			 * Every column part of the primary key must be in the bind data types
			 */
			if !fetch bindType, bindDataTypes[primaryKey] {
				throw new Exception("Column '" . primaryKey . "' have not defined a bind data type");
			}

			/**
			 * Take the column values based on the column map if any
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[primaryKey] {
					throw new Exception("Column '" . primaryKey . "' isn't part of the column map");
				}
			} else {
				let attributeField = primaryKey;
			}

			/**
			 * If the attribute is currently set in the object add it to the conditions
			 */
			if !fetch value, model->{attributeField} {
				throw new Exception(
					"Cannot delete the record because the primary key attribute: '" . attributeField . "' wasn't set"
				);
			}

			/**
			 * Escape the column identifier
			 */
			let values[] = value,
				conditions[] = writeConnection->escapeIdentifier(primaryKey) . " = ?",
				bindTypes[] = bindType;
		}

		if globals_get("orm.events") {

			model->skipOperation(false);

			/**
			 * Fire the beforeDelete event
			 */
			if model->fireEventCancel("beforeDelete") === false {
				return false;
			} else {
				/**
				 * The operation can be skipped
				 */
				if model->isSkipped() {
					return true;
				}
			}
		}

		let schema = model->getSchema(),
			source = model->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		/**
		 * Join the conditions in the array using an AND operator
		 * Do the deletion
		 */
		let success = writeConnection->delete(table, join(" AND ", conditions), values, bindTypes);

		/**
		 * Check if there is virtual foreign keys with cascade action
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysReverseCascade(model) === false {
				return false;
			}
		}

		if globals_get("orm.events") {
			if success {
				model->fireEvent("afterDelete");
			}
		}

		/**
		 * Force perform the record existence checking again
		 */
		model->setDirtyState(Model::DIRTY_STATE_DETACHED);

		return success;
	}

	/**
	 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
	 */
	protected final function _checkForeignKeysReverseRestrict(<ModelInterface> model) -> boolean
	{
		boolean error;
		var relations, foreignKey, relation,
			relationClass, referencedModel, fields, referencedFields,
			conditions, bindParams,position, field,
			value, extraConditions, message;
		int action;

		/**
		 * We check if some of the hasOne/hasMany relations is a foreign key
		 */
		let relations = this->getHasOneAndHasMany(model);

		let error = false;
		for relation in relations {

			/**
			 * Check if the relation has a virtual foreign key
			 */
			let foreignKey = relation->getForeignKey();
			if foreignKey === false {
				continue;
			}

			/**
			 * By default action is restrict
			 */
			let action = Relation::ACTION_RESTRICT;

			/**
			 * Try to find a different action in the foreign key's options
			 */
			if typeof foreignKey == "array" {
				if isset foreignKey["action"] {
					let action = (int) foreignKey["action"];
				}
			}

			/**
			 * Check only if the operation is restrict
			 */
			if action != Relation::ACTION_RESTRICT {
				continue;
			}

			let relationClass = relation->getReferencedModel();

			/**
			 * Load a plain instance
			 */
			let referencedModel = this->load(relationClass);

			let fields = relation->getFields(),
				referencedFields = relation->getReferencedFields();

			/**
			 * Create the checking conditions. A relation can has many fields or a single one
			 */
			let conditions = [], bindParams = [];

			if typeof fields == "array" {

				for position, field in fields {
					fetch value, model->{field};
					let conditions[] = "[" . referencedFields[position] . "] = ?" . position,
						bindParams[] = value;
				}

			} else {
				fetch value, model->{fields};
				let conditions[] = "[" . referencedFields . "] = ?0",
					bindParams[] = value;
			}

			/**
			 * Check if the virtual foreign key has extra conditions
			 */
			if fetch extraConditions, foreignKey["conditions"] {
				let conditions[] = extraConditions;
			}

			/**
			 * We don't trust the actual values in the object and then we're passing the values using bound parameters
			 * Let's make the checking
			 */
			if referencedModel->count([join(" AND ", conditions), "bind": bindParams]) {

				/**
				 * Create a new message
				 */
				if !fetch message, foreignKey["message"] {
					let message = "Record is referenced by model " . relationClass;
				}

				/**
				 * Create a message
				 */
				model->appendMessage(new Message(message, fields, "ConstraintViolation"));
				let error = true;
				break;
			}
		}

		/**
		 * Call validation fails event
		 */
		if error === true {
			if globals_get("orm.events") {
				model->fireEvent("onValidationFails");
				model->cancelOperation();
			}
			return false;
		}

		return true;
	}

	/**
	 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
	 */
	protected final function _checkForeignKeysReverseCascade(<ModelInterface> model) -> boolean
	{
		var relations, relation, foreignKey,
			resultset, conditions, bindParams, referencedModel,
			referencedFields, fields, field, position, value,
			extraConditions;
		int action;

		/**
		 * We check if some of the hasOne/hasMany relations is a foreign key
		 */
		let relations = this->getHasOneAndHasMany(model);

		for relation in relations {

			/**
			 * Check if the relation has a virtual foreign key
			 */
			let foreignKey = relation->getForeignKey();
			if foreignKey === false {
				continue;
			}

			/**
			 * By default action is restrict
			 */
			let action = Relation::NO_ACTION;

			/**
			 * Try to find a different action in the foreign key's options
			 */
			if typeof foreignKey == "array" {
				if isset foreignKey["action"] {
					let action = (int) foreignKey["action"];
				}
			}

			/**
			 * Check only if the operation is restrict
			 */
			if action != Relation::ACTION_CASCADE {
				continue;
			}

			/**
			 * Load a plain instance
			 */
			let referencedModel = this->load(relation->getReferencedModel());

			let fields = relation->getFields(),
				referencedFields = relation->getReferencedFields();

			/**
			 * Create the checking conditions. A relation can has many fields or a single one
			 */
			let conditions = [], bindParams = [];

			if typeof fields == "array" {
				for position, field in fields {
					fetch value, model->{field};
					let conditions[] = "[". referencedFields[position] . "] = ?" . position,
						bindParams[] = value;
				}
			} else {
				fetch value, model->{fields};
				let conditions[] = "[" . referencedFields . "] = ?0",
					bindParams[] = value;
			}

			/**
			 * Check if the virtual foreign key has extra conditions
			 */
			if fetch extraConditions, foreignKey["conditions"] {
				let conditions[] = extraConditions;
			}

			/**
			 * We don't trust the actual values in the object and then we're passing the values using bound parameters
			 * Let's make the checking
			 */
			let resultset = referencedModel->find([
				join(" AND ", conditions),
				"bind": bindParams
			]);

			/**
			 * Delete the resultset
			 * Stop the operation if needed
			 */
			if resultset->delete() === false {
				return false;
			}
		}

		return true;
	}

	/**
 	 * Destroys the current PHQL cache
 	 */
	public function __destruct()
	{
		phalcon_orm_destroy_cache();
		Query::clean();
	}
}
