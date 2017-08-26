
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

use Phalcon\Db\Column;
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
		var className, repository, eventsManager;

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

		let repository = this->getRepository(get_class(model));

		/**
		 * Call the 'initialize' method if it's implemented
		 */
		if method_exists(repository, "initialize") {
			repository->{"initialize"}();
		}

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
		var model;

		/**
		 * The model doesn't exist throw an exception
		 */
		if !class_exists(modelName) {
			throw new Exception("Model '" . modelName . "' could not be loaded");
		}

		/**
		 * Load it using an autoloader
		 */
		let model = new {modelName}(this->_dependencyInjector, this);

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
	public function useDynamicUpdate(string! modelClass, boolean dynamicUpdate)
	{
		var entityName;
		let entityName = strtolower(modelClass),
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
	public function addHasOne(string modelClass, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = strtolower(modelClass),
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
	public function addBelongsTo(string! modelClass, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, relation, keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = strtolower(modelClass),
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
	public function addHasMany(string! modelClass, var fields, string! referencedModel,
		var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, hasMany, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations;

		let entityName = strtolower(modelClass),
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
	public function addHasManyToMany(string! modelClass, var fields, string! intermediateModel,
		var intermediateFields, var intermediateReferencedFields, string! referencedModel, var referencedFields, var options = null) -> <Relation>
	{
		var entityName, referencedEntity, hasManyToMany, relation,
			keyRelation, relations, alias, lowerAlias, singleRelations, intermediateEntity;

		let entityName = strtolower(modelClass),
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
		var placeholders, referencedModel, intermediateModel, referencedModelRepository,
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

		let referencedModelRepository = this->getRepository(referencedModel);

		/**
		 * Load the referenced model
		 * Call the function in the model
		 */
		let records = call_user_func_array([referencedModelRepository, retrieveMethod], arguments);

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

	public function getRepository(string! modelClass) -> <RepositoryInterface>
	{
		var repositoryClass, repository;

		let repositoryClass = {modelClass}::getRepositoryClass();

		let repository = new {repositoryClass}(modelClass, this);

		return repository;
	}

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh(<ModelInterface> model) -> <ModelInterface>
	{
		var metaData, readConnection, schema, source, table,
			uniqueKey, tables, uniqueParams, dialect, row, fields, attribute, columnMap;

		if model->getDirtyState() != Model::DIRTY_STATE_PERSISTENT {
			throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
		}

		let metaData = model->getModelsMetaData(),
			readConnection = model->getReadConnection();

		let schema = model->getSchema(),
			source = model->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		let uniqueKey = model->getUniqueKey();
		if !uniqueKey {

			/**
			 * We need to check if the record exists
			 */
			if !this->exists(model, metaData, readConnection, table) {
				throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
			}

			let uniqueKey = model->getUniqueKey();
		}

		let uniqueParams = model->getUniqueParams();
		if typeof uniqueParams != "array" {
			throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
		}

		/**
		 * We only refresh the attributes in the model's metadata
		 */
		let fields = [];
		for attribute in metaData->getAttributes(model) {
			let fields[] = [attribute];
		}

		/**
		 * We directly build the SELECT to save resources
		 */
		let dialect = readConnection->getDialect(),
			tables = dialect->select([
				"columns": fields,
				"tables":  readConnection->escapeIdentifier(table),
				"where":   uniqueKey
			]),
			row = readConnection->fetchOne(tables, \Phalcon\Db::FETCH_ASSOC, uniqueParams, model->getUniqueTypes());

		/**
		 * Get a column map if any
		 * Assign the resulting array to the model object
		 */
		if typeof row == "array" {
			let columnMap = metaData->getColumnMap(model);
			model->assign(row, columnMap);
			if this->isKeepingSnapshots(model) {
				model->setSnapshotData(row, columnMap);
			}
		}

		return model;
	}

	/**
	 * Checks whether a model instance already exists
	 *
	 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
	 * @param \Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @return boolean
	 */
	public function exists(<ModelInterface> model, <MetaDataInterface> metaData, <AdapterInterface> connection, var table = null) -> boolean
	{
		int numberEmpty, numberPrimary;
		var uniqueParams, uniqueTypes, uniqueKey, columnMap, primaryKeys,
			wherePk, field, attributeField, value, bindDataTypes,
			joinWhere, num, type, schema, source;

		let uniqueParams = null,
			uniqueTypes = null;

		/**
		 * Builds a unique primary key condition
		 */
		let uniqueKey = model->getUniqueKey();
		if uniqueKey === null {

			let primaryKeys = metaData->getPrimaryKeyAttributes(model),
				bindDataTypes = metaData->getBindTypes(model);

			let numberPrimary = count(primaryKeys);
			if !numberPrimary {
				return false;
			}

			/**
			 * Check if column renaming is globally activated
			 */
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(model);
			} else {
				let columnMap = null;
			}

			let numberEmpty = 0,
				wherePk = [],
				uniqueParams = [],
				uniqueTypes = [];

			/**
			 * We need to create a primary key based on the current data
			 */
			for field in primaryKeys {

				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				/**
				 * If the primary key attribute is set append it to the conditions
				 */
				let value = null;
				if fetch value, model->{attributeField} {

					/**
					 * We count how many fields are empty, if all fields are empty we don't perform an 'exist' check
					 */
					if value === null || value === "" {
						let numberEmpty++;
					}
					let uniqueParams[] = value;

				} else {
					let uniqueParams[] = null,
						numberEmpty++;
				}

				if !fetch type, bindDataTypes[field] {
					throw new Exception("Column '" . field . "' isn't part of the table columns");
				}

				let uniqueTypes[] = type,
					wherePk[] = connection->escapeIdentifier(field) . " = ?";
			}

			/**
			 * There are no primary key fields defined, assume the record does not exist
			 */
			if numberPrimary == numberEmpty {
				return false;
			}

			let joinWhere = join(" AND ", wherePk);

			/**
			 * The unique key is composed of 3 parts _uniqueKey, uniqueParams, uniqueTypes
			 */
			model->setUniqueKey(joinWhere);
			model->setUniqueParams(uniqueParams);
			model->setUniqueTypes(uniqueTypes);
			let uniqueKey = joinWhere;
		}

		/**
		 * If we already know if the record exists we don't check it
		 */
		if !model->getDirtyState() {
			return true;
		}

		if uniqueKey === null {
			let uniqueKey = model->getUniqueKey();
		}

		if uniqueParams === null {
			let uniqueParams = model->getUniqueParams();
		}

		if uniqueTypes === null {
			let uniqueTypes = model->getUniqueTypes();
		}

		let schema = model->getSchema(),
			source = model->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		/**
		 * Here we use a single COUNT(*) without PHQL to make the execution faster
		 */
		let num = connection->fetchOne(
			"SELECT COUNT(*) \"rowcount\" FROM " . connection->escapeIdentifier(table) . " WHERE " . uniqueKey,
			null,
			uniqueParams,
			uniqueTypes
		);

		if num["rowcount"] {
			model->setDirtyState(Model::DIRTY_STATE_PERSISTENT);
			return true;
		} else {
			model->setDirtyState(Model::DIRTY_STATE_TRANSIENT);
		}

		return false;
	}

	/**
	 * Inserts or updates a model instance. Returning true on success or false otherwise.
	 *
	 *<code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // Creating a new robot
	 * $robot = new Robots();
	 *
	 * $robot->type = "mechanical";
	 * $robot->name = "Astro Boy";
	 * $robot->year = 1952;
	 *
	 * $modelsManager->save($robot);
	 *
	 * // Updating a robot name
	 * $robot = $robotsRepository->findFirst("id = 100");
	 *
	 * $robot->name = "Biomass";
	 *
	 * $modelsManager->save($robot);
	 *</code>
	 */
	public function save(<ModelInterface> model) -> boolean
	{
		var metaData, related, schema, writeConnection, readConnection,
			source, table, identityField, exists, success;

		let metaData = model->getModelsMetaData();

		/**
		 * Create/Get the current database connection
		 */
		let writeConnection = model->getWriteConnection();

		/**
		 * Fire the start event
		 */
		model->fireEvent("prepareSave");

		/**
		 * Save related records in belongsTo relationships
		 */
		let related = model->getRelatedProperty();
		if typeof related == "array" {
			if this->_preSaveRelatedRecords(model, writeConnection, related) === false {
				return false;
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
		 * Create/Get the current database connection
		 */
		let readConnection = model->getReadConnection();

		/**
		 * We need to check if the record exists
		 */
		let exists = this->exists(model, metaData, readConnection, table);

		if exists {
			model->setOperationMade(Model::OP_UPDATE);
		} else {
			model->setOperationMade(Model::OP_CREATE);
		}

		/**
		 * Clean the messages
		 */
		model->clearMessages();

		/**
		 * Query the identity field
		 */
		let identityField = metaData->getIdentityField(model);

		/**
		 * _preSave() makes all the validations
		 */
		if this->_preSave(model, metaData, exists, identityField) === false {

			/**
			 * Rollback the current transaction if there was validation errors
			 */
			if typeof related == "array" {
				writeConnection->rollback(false);
			}

			/**
			 * Throw exceptions on failed saves?
			 */
			if globals_get("orm.exception_on_failed_save") {
				/**
				 * Launch a Phalcon\Mvc\Model\ValidationFailed to notify that the save failed
				 */
				throw new ValidationFailed(model, model->getMessages());
			}

			return false;
		}

		/**
		 * Depending if the record exists we do an update or an insert operation
		 */
		if exists {
			let success = this->_doLowUpdate(model, metaData, writeConnection, table);
		} else {
			let success = this->_doLowInsert(model, metaData, writeConnection, table, identityField);
		}

		/**
		 * Change the dirty state to persistent
		 */
		if success {
			model->setDirtyState(Model::DIRTY_STATE_PERSISTENT);
		}

		if typeof related == "array" {

			/**
			 * Rollbacks the implicit transaction if the master save has failed
			 */
			if success === false {
				writeConnection->rollback(false);
			} else {
				/**
				 * Save the post-related records
				 */
				let success = this->_postSaveRelatedRecords(model, writeConnection, related);
			}
		}

		/**
		 * _postSave() invokes after* events if the operation was successful
		 */
		if globals_get("orm.events") {
			let success = this->_postSave(model, success, exists);
		}

		if success === false {
			model->cancelOperation();
		} else {
			model->fireEvent("afterSave");
		}

		return success;
	}

	/**
	 * Executes internal hooks before save a record
	 */
	protected function _preSave(<ModelInterface> model, <MetaDataInterface> metaData, boolean exists, var identityField) -> boolean
	{
		var notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues,
			field, attributeField, value, emptyStringValues;
		boolean error, isNull;

		/**
		 * Run Validation Callbacks Before
		 */
		if globals_get("orm.events") {

			/**
			 * Call the beforeValidation
			 */
			if model->fireEventCancel("beforeValidation") === false {
				return false;
			}

			/**
			 * Call the specific beforeValidation event for the current action
			 */
			if !exists {
				if model->fireEventCancel("beforeValidationOnCreate") === false {
					return false;
				}
			} else {
				if model->fireEventCancel("beforeValidationOnUpdate") === false {
					return false;
				}
			}
		}

		/**
		 * Check for Virtual foreign keys
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysRestrict(model) === false {
				return false;
			}
		}

		/**
		 * Columns marked as not null are automatically validated by the ORM
		 */
		if globals_get("orm.not_null_validations") {

			let notNull = metaData->getNotNullAttributes(model);
			if typeof notNull == "array" {

				/**
				 * Gets the fields that are numeric, these are validated in a different way
				 */
				let dataTypeNumeric = metaData->getDataTypesNumeric(model);

				if globals_get("orm.column_renaming") {
					let columnMap = metaData->getColumnMap(model);
				} else {
					let columnMap = null;
				}

				/**
				 * Get fields that must be omitted from the SQL generation
				 */
				if exists {
					let automaticAttributes = metaData->getAutomaticUpdateAttributes(model);
				} else {
					let automaticAttributes = metaData->getAutomaticCreateAttributes(model);
				}
				let defaultValues = metaData->getDefaultValues(model);

				/**
				 * Get string attributes that allow empty strings as defaults
				 */
				let emptyStringValues = metaData->getEmptyStringAttributes(model);

				let error = false;
				for field in notNull {

					/**
					 * We don't check fields that must be omitted
					 */
					if isset automaticAttributes[field] {
						continue;
					}

					let isNull = false;

					if typeof columnMap == "array" {
						if !fetch attributeField, columnMap[field] {
							throw new Exception("Column '" . field . "' isn't part of the column map");
						}
					} else {
						let attributeField = field;
					}

					/**
					 * Field is null when: 1) is not set, 2) is numeric but
					 * its value is not numeric, 3) is null or 4) is empty string
					 * Read the attribute from the this_ptr using the real or renamed name
					 */
					if fetch value, model->{attributeField} {

						/**
						 * Objects are never treated as null, numeric fields must be numeric to be accepted as not null
						 */
						if typeof value != "object" {
							if !isset dataTypeNumeric[field] {
								if isset emptyStringValues[field] {
									if value === null {
										let isNull = true;
									}
								} else {
									if value === null || (value === "" && (!isset defaultValues[field] || value !== defaultValues[field])) {
										let isNull = true;
									}
								}
							} else {
								if !is_numeric(value) {
									let isNull = true;
								}
							}
						}

					} else {
						let isNull = true;
					}

					if isNull === true {

						if !exists {
							/**
							 * The identity field can be null
							 */
							if field == identityField {
								continue;
							}

							/**
							 * The field have default value can be null
							 */
							if isset defaultValues[field] {
								continue;
							}
						}

						/**
						 * An implicit PresenceOf message is created
						 */
						model->appendMessage(new Message(attributeField . " is required", attributeField, "PresenceOf"));

						let error = true;
					}
				}

				if error === true {
					if globals_get("orm.events") {
						model->fireEvent("onValidationFails");
						model->cancelOperation();
					}
					return false;
				}
			}
		}

		/**
		 * Call the main validation event
		 */
		if model->fireEventCancel("validation") === false {
			if globals_get("orm.events") {
				model->fireEvent("onValidationFails");
			}
			return false;
		}

		/**
		 * Run Validation
		 */
		if globals_get("orm.events") {

			/**
			 * Run Validation Callbacks After
			 */
			if !exists {
				if model->fireEventCancel("afterValidationOnCreate") === false {
					return false;
				}
			} else {
				if model->fireEventCancel("afterValidationOnUpdate") === false {
					return false;
				}
			}

			if model->fireEventCancel("afterValidation") === false {
				return false;
			}

			/**
			 * Run Before Callbacks
			 */
			if model->fireEventCancel("beforeSave") === false {
				return false;
			}

			model->skipOperation(false);

			/**
			 * The operation can be skipped here
			 */
			if exists {
				if model->fireEventCancel("beforeUpdate") === false {
					return false;
				}
			} else {
				if model->fireEventCancel("beforeCreate") === false {
					return false;
				}
			}

			/**
			 * Always return true if the operation is skipped
			 */
			if model->isSkipped() {
				return true;
			}

		}

		return true;
	}

	/**
	 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
	 * to verify that inserted/updated values are present in the related entity
	 */
	protected final function _checkForeignKeysRestrict(<ModelInterface> model) -> boolean
	{
		var belongsTo, foreignKey, relation, conditions,
			position, bindParams, extraConditions, message, fields,
			referencedFields, field, referencedModelRepository, value, allowNulls;
		int action, numberNull;
		boolean error, validateWithNulls;

		/**
		 * We check if some of the belongsTo relations act as virtual foreign key
		 */
		let belongsTo = this->getBelongsTo(model);

		let error = false;
		for relation in belongsTo {

			let validateWithNulls = false;
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

			/**
			 * Load the referenced model if needed
			 */
			let referencedModelRepository = this->getRepository(relation->getReferencedModel());

			/**
			 * Since relations can have multiple columns or a single one, we need to build a condition for each of these cases
			 */
			let conditions = [], bindParams = [];

			let numberNull = 0,
				fields = relation->getFields(),
				referencedFields = relation->getReferencedFields();

			if typeof fields == "array" {
				/**
				 * Create a compound condition
				 */
				for position, field in fields {
					fetch value, model->{field};
					let conditions[] = "[" . referencedFields[position] . "] = ?" . position,
						bindParams[] = value;
					if typeof value == "null" {
						let numberNull++;
					}
				}

				let validateWithNulls = numberNull == count(fields);

			} else {

				fetch value, model->{fields};
				let conditions[] = "[" . referencedFields . "] = ?0",
					bindParams[] = value;

				if typeof value == "null" {
					let validateWithNulls = true;
				}
			}

			/**
			 * Check if the virtual foreign key has extra conditions
			 */
			if fetch extraConditions, foreignKey["conditions"] {
				let conditions[] = extraConditions;
			}

			/**
			 * Check if the relation definition allows nulls
			 */
			if validateWithNulls {
				if fetch allowNulls, foreignKey["allowNulls"] {
					let validateWithNulls = (boolean) allowNulls;
				} else {
					let validateWithNulls = false;
				}
			}

			/**
			 * We don't trust the actual values in the object and pass the values using bound parameters
			 * Let's make the checking
			 */
			if !validateWithNulls && !referencedModelRepository->count([join(" AND ", conditions), "bind": bindParams]) {

				/**
				 * Get the user message or produce a new one
				 */
				if !fetch message, foreignKey["message"] {
					if typeof fields == "array" {
						let message = "Value of fields \"" . join(", ", fields) . "\" does not exist on referenced table";
					} else {
						let message = "Value of field \"" . fields . "\" does not exist on referenced table";
					}
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
		 * Call 'onValidationFails' if the validation fails
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
	 * Saves related records that must be stored prior to save the master record
	 *
	 * @param \Phalcon\Db\AdapterInterface connection
	 * @param \Phalcon\Mvc\ModelInterface[] related
	 * @return boolean
	 */
	protected function _preSaveRelatedRecords(<ModelInterface> model, <AdapterInterface> connection, related) -> boolean
	{
		var className, manager, type, relation, columns, referencedFields,
			referencedModel, message, nesting, name, record;

		let nesting = false;

		/**
		 * Start an implicit transaction
		 */
		connection->begin(nesting);

		let className = get_class(model),
			manager = <ManagerInterface> model->getModelsManager();

		for name, record in related {

			/**
			 * Try to get a relation with the same name
			 */
			let relation = <RelationInterface> manager->getRelationByAlias(className, name);

			if typeof relation !== "object" {
				continue;
			}

			/**
			 * Get the relation type
			 */
			let type = relation->getType();

			/**
			 * Only belongsTo are stored before save the master record
			 */
			if type !== Relation::BELONGS_TO {
				continue;
			}

			if typeof record != "object" {
				connection->rollback(nesting);
				throw new Exception("Only objects can be stored as part of belongs-to relations");
			}

			let columns = relation->getFields(),
				referencedModel = relation->getReferencedModel(),
				referencedFields = relation->getReferencedFields();

			if typeof columns == "array" {
				connection->rollback(nesting);
				throw new Exception("Not implemented");
			}

			/**
			 * If dynamic update is enabled, saving the record must not take any action
			 */
			if !manager->save(record) {

				/**
				 * Get the validation messages generated by the referenced model
				 */
				for message in record->getMessages() {

					/**
					 * Set the related model
					 */
					if typeof message == "object" {
						message->setModel(record);
					}

					/**
					 * Appends the messages to the current model
					 */
					model->appendMessage(message);
				}

				/**
				 * Rollback the implicit transaction
				 */
				connection->rollback(nesting);
				return false;
			}

			/**
			 * Read the attribute from the referenced model and assigns it to the current model
			 * Assign it to the model
			 */
			let model->{columns} = record->readAttribute(referencedFields);
		}

		return true;
	}


	/**
	 * Save the related records assigned in the has-one/has-many relations
	 *
	 * @param  Phalcon\Db\AdapterInterface connection
	 * @param  Phalcon\Mvc\ModelInterface[] related
	 * @return boolean
	 */
	protected function _postSaveRelatedRecords(<ModelInterface> model, <AdapterInterface> connection, related) -> boolean
	{
		var nesting, className, manager, relation, name, record, message,
			columns, referencedModel, referencedFields, relatedRecords, value,
			recordAfter, intermediateModel, intermediateFields, intermediateValue,
			intermediateModelName, intermediateReferencedFields;
		boolean isThrough;

		let nesting = false,
			className = get_class(model),
			manager = <ManagerInterface> model->getModelsManager();

		for name, record in related {

			/**
			 * Try to get a relation with the same name
			 */
			let relation = <RelationInterface> manager->getRelationByAlias(className, name);
			if typeof relation == "object" {

				/**
				 * Discard belongsTo relations
				 */
				if relation->getType() == Relation::BELONGS_TO {
					continue;
				}

				if typeof record != "object" && typeof record != "array" {
					connection->rollback(nesting);
					throw new Exception("Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations");
				}

				let columns = relation->getFields(),
					referencedModel = relation->getReferencedModel(),
					referencedFields = relation->getReferencedFields();

				if typeof columns == "array" {
					connection->rollback(nesting);
					throw new Exception("Not implemented");
				}

				/**
				 * Create an implicit array for has-many/has-one records
				 */
				if typeof record == "object" {
					let relatedRecords = [record];
				} else {
					let relatedRecords = record;
				}

				if !fetch value, model->{columns} {
					connection->rollback(nesting);
					throw new Exception("The column '" . columns . "' needs to be present in the model");
				}

				/**
				 * Get the value of the field from the current model
				 * Check if the relation is a has-many-to-many
				 */
				let isThrough = (boolean) relation->isThrough();

				/**
				 * Get the rest of intermediate model info
				 */
				if isThrough {
					let intermediateModelName = relation->getIntermediateModel(),
						intermediateFields = relation->getIntermediateFields(),
						intermediateReferencedFields = relation->getIntermediateReferencedFields();
				}

				for recordAfter in relatedRecords {

					/**
					 * For non has-many-to-many relations just assign the local value in the referenced model
					 */
					if !isThrough {

						/**
						 * Assign the value to the
						 */
						recordAfter->writeAttribute(referencedFields, value);
					}

					/**
					 * Save the record and get messages
					 */
					if !manager->save(recordAfter) {

						/**
						 * Get the validation messages generated by the referenced model
						 */
						for message in recordAfter->getMessages() {

							/**
							 * Set the related model
							 */
							if typeof message == "object" {
								message->setModel(record);
							}

							/**
							 * Appends the messages to the current model
							 */
							model->appendMessage(message);
						}

						/**
						 * Rollback the implicit transaction
						 */
						connection->rollback(nesting);
						return false;
					}

					if isThrough {

						/**
						 * Create a new instance of the intermediate model
						 */
						let intermediateModel = manager->load(intermediateModelName);

						/**
						 * Write value in the intermediate model
						 */
						intermediateModel->writeAttribute(intermediateFields, value);

						/**
						 * Get the value from the referenced model
						 */
						let intermediateValue = recordAfter->readAttribute(referencedFields);

						/**
						 * Write the intermediate value in the intermediate model
						 */
						intermediateModel->writeAttribute(intermediateReferencedFields, intermediateValue);

						/**
						 * Save the record and get messages
						 */
						if !manager->save(intermediateModel) {

							/**
							 * Get the validation messages generated by the referenced model
							 */
							for message in intermediateModel->getMessages() {

								/**
								 * Set the related model
								 */
								if typeof message == "object" {
									message->setModel(record);
								}

								/**
								 * Appends the messages to the current model
								 */
								model->appendMessage(message);
							}

							/**
							 * Rollback the implicit transaction
							 */
							connection->rollback(nesting);
							return false;
						}
					}

				}
			} else {
				if typeof record != "array" {
					connection->rollback(nesting);

					throw new Exception(
						"There are no defined relations for the model '" . className . "' using alias '" . name . "'"
					);
				}
			}
		}

		/**
		 * Commit the implicit transaction
		 */
		connection->commit(nesting);
		return true;
	}

	/**
	 * Executes internal events after save a record
	 */
	protected function _postSave(<ModelInterface> model, boolean success, boolean exists) -> boolean
	{
		if success {
			if exists {
				model->fireEvent("afterUpdate");
			} else {
				model->fireEvent("afterCreate");
			}
		}

		return success;
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
		if this->exists(model, metaData, model->getReadConnection()) {
			model->clearMessages();

			model->appendMessage(
				new Message("Record cannot be created because it already exists", null, "InvalidCreateAttempt")
			);

			return false;
		}

		/**
		 * Using save() anyways
		 */
		return this->save(model);
	}

	/**
	 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 *<code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * // Updating a robot name
	 * $robot = $robotsRepository->findFirst("id = 100");
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

			if !this->exists(model, metaData, model->getReadConnection()) {
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
		return this->save(model);
	}

	/**
	 * Sends a pre-build INSERT SQL statement to the relational database system
	 *
	 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
	 * @param \Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @param boolean|string identityField
	 * @return boolean
	 */
	protected function _doLowInsert(<ModelInterface> model, <MetaDataInterface> metaData, <AdapterInterface> connection, table, identityField) -> boolean
	{
		var bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes,
			field, columnMap, value, attributeField, success, bindType,
			defaultValue, sequenceName, defaultValues, source, schema, snapshot, lastInsertedId;
		boolean useExplicitIdentity;

		let bindSkip = Column::BIND_SKIP;

		let fields = [],
			values = [],
			snapshot = [],
			bindTypes = [];

		let attributes = metaData->getAttributes(model),
			bindDataTypes = metaData->getBindTypes(model),
			automaticAttributes = metaData->getAutomaticCreateAttributes(model),
			defaultValues = metaData->getDefaultValues(model);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(model);
		} else {
			let columnMap = null;
		}

		/**
		 * All fields in the model makes part or the INSERT
		 */
		for field in attributes {

			if isset automaticAttributes[field] {
				continue;
			}

			/**
			 * Check if the model has a column map
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[field] {
					throw new Exception("Column '" . field . "' isn't part of the column map");
				}
			} else {
				let attributeField = field;
			}

			/**
			 * Check every attribute in the model except identity field
			 */
			if field == identityField {
				continue;
			}

			/**
			 * This isset checks that the property be defined in the model
			 */
			if fetch value, model->{attributeField} {

				if value === null && isset defaultValues[field] {
					let snapshot[attributeField] = null;
					let value = connection->getDefaultValue();
				} else {
					let snapshot[attributeField] = value;
				}

				/**
				 * Every column must have a bind data type defined
				 */
				if !fetch bindType, bindDataTypes[field] {
					throw new Exception("Column '" . field . "' have not defined a bind data type");
				}

				let fields[] = field, values[] = value, bindTypes[] = bindType;
			} else {

				if isset defaultValues[field] {
					let values[] = connection->getDefaultValue();
					/**
					 * This is default value so we set null, keep in mind it's value in database!
					 */
					let snapshot[attributeField] = null;
				} else {
					let values[] = value;
					let snapshot[attributeField] = value;
				}

				let fields[] = field, bindTypes[] = bindSkip;
			}
		}

		/**
		 * If there is an identity field we add it using "null" or "default"
		 */
		if identityField !== false {

			let defaultValue = connection->getDefaultIdValue();

			/**
			 * Not all the database systems require an explicit value for identity columns
			 */
			let useExplicitIdentity = (boolean) connection->useExplicitIdValue();
			if useExplicitIdentity {
				let fields[] = identityField;
			}

			/**
			 * Check if the model has a column map
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[identityField] {
					throw new Exception("Identity column '" . identityField . "' isn't part of the column map");
				}
			} else {
				let attributeField = identityField;
			}

			/**
			 * Check if the developer set an explicit value for the column
			 */
			if fetch value, model->{attributeField} {

				if value === null || value === "" {
					if useExplicitIdentity {
						let values[] = defaultValue, bindTypes[] = bindSkip;
					}
				} else {

					/**
					 * Add the explicit value to the field list if the user has defined a value for it
					 */
					if !useExplicitIdentity {
						let fields[] = identityField;
					}

					/**
					 * The field is valid we look for a bind value (normally int)
					 */
					if !fetch bindType, bindDataTypes[identityField] {
						throw new Exception("Identity column '" . identityField . "' isn\'t part of the table columns");
					}

					let values[] = value, bindTypes[] = bindType;
				}
			} else {
				if useExplicitIdentity {
					let values[] = defaultValue, bindTypes[] = bindSkip;
				}
			}
		}

		/**
		 * The low level insert is performed
		 */
		let success = connection->insert(table, values, fields, bindTypes);
		if success && identityField !== false {

			/**
			 * We check if the model have sequences
			 */
			let sequenceName = null;
			if connection->supportSequences() === true {
				if method_exists(model, "getSequenceName") {
					let sequenceName = model->{"getSequenceName"}();
				} else {

					let source = model->getSource(),
						schema = model->getSchema();

					if empty schema {
						let sequenceName = source . "_" . identityField . "_seq";
					} else {
						let sequenceName = schema . "." . source . "_" . identityField . "_seq";
					}
				}
			}

			/**
			 * Recover the last "insert id" and assign it to the object
			 */
			let lastInsertedId = connection->lastInsertId(sequenceName);

			let model->{attributeField} = lastInsertedId;
			let snapshot[attributeField] = lastInsertedId;

			if this->isKeepingSnapshots(model) && globals_get("orm.update_snapshot_on_save") {
				model->setSnapshotData(snapshot);
			}

			/**
			 * Since the primary key was modified, we delete the _uniqueParams
			 * to force any future update to re-build the primary key
			 */
			model->resetUniqueParams();
		}

		return success;
	}

	/**
	 * Sends a pre-build UPDATE SQL statement to the relational database system
	 *
	 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
	 * @param \Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @return boolean
	 */
	protected function _doLowUpdate(<ModelInterface> model, <MetaDataInterface> metaData, <AdapterInterface> connection, var table) -> boolean
	{
		var bindSkip, fields, values, dataType, dataTypes, bindTypes, bindDataTypes, field,
			automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes,
			snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType, newSnapshot, success, oldSnapshot;
		boolean useDynamicUpdate, changed;

		let bindSkip = Column::BIND_SKIP,
			fields = [],
			values = [],
			bindTypes = [],
			newSnapshot = [];

		/**
		 * Check if the model must use dynamic update
		 */
		let useDynamicUpdate = (boolean) this->isUsingDynamicUpdate(model);

		let snapshot = model->getSnapshotData();

		if useDynamicUpdate {
			if typeof snapshot != "array" {
				let useDynamicUpdate = false;
			}
		}

		let dataTypes = metaData->getDataTypes(model),
			 bindDataTypes = metaData->getBindTypes(model),
			nonPrimary = metaData->getNonPrimaryKeyAttributes(model),
			automaticAttributes = metaData->getAutomaticUpdateAttributes(model);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(model);
		} else {
			let columnMap = null;
		}

		/**
		 * We only make the update based on the non-primary attributes, values in primary key attributes are ignored
		 */
		for field in nonPrimary {

			if isset automaticAttributes[field] {
				continue;
			}

			/**
			 * Check a bind type for field to update
			 */
			if !fetch bindType, bindDataTypes[field] {
				throw new Exception("Column '" . field . "' have not defined a bind data type");
			}

			/**
			 * Check if the model has a column map
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[field] {
					throw new Exception("Column '" . field . "' isn't part of the column map");
				}
			} else {
				let attributeField = field;
			}

			/**
			 * Get the field's value
			 * If a field isn't set we pass a null value
			 */
			if fetch value, model->{attributeField} {

				/**
				 * When dynamic update is not used we pass every field to the update
				 */
				if !useDynamicUpdate {
					let fields[] = field, values[] = value;
					let bindTypes[] = bindType;
				} else {

					/**
					 * If the field is not part of the snapshot we add them as changed
					 */
					if !fetch snapshotValue, snapshot[attributeField] {
						let changed = true;
					} else {
						/**
						 * See https://github.com/phalcon/cphalcon/issues/3247
						 * Take a TEXT column with value '4' and replace it by
						 * the value '4.0'. For PHP '4' and '4.0' are the same.
						 * We can't use simple comparison...
						 *
						 * We must use the type of snapshotValue.
						 */
						if value === null {
							let changed = snapshotValue !== null;
						} else {
							if snapshotValue === null {
								let changed = true;
							} else {

								if !fetch dataType, dataTypes[field] {
									throw new Exception("Column '" . field . "' have not defined a data type");
								}

								switch dataType {

									case Column::TYPE_BOOLEAN:
										let changed = (boolean) snapshotValue !== (boolean) value;
										break;

									case Column::TYPE_INTEGER:
										let changed = (int) snapshotValue !== (int) value;
										break;

									case Column::TYPE_DECIMAL:
									case Column::TYPE_FLOAT:
										let changed = floatval(snapshotValue) !== floatval(value);
										break;

									case Column::TYPE_DATE:
									case Column::TYPE_VARCHAR:
									case Column::TYPE_DATETIME:
									case Column::TYPE_CHAR:
									case Column::TYPE_TEXT:
									case Column::TYPE_VARCHAR:
									case Column::TYPE_BIGINTEGER:
										let changed = (string) snapshotValue !== (string) value;
										break;

									/**
									 * Any other type is not really supported...
									 */
									default:
										let changed = value != snapshotValue;
								}
							}
						}
					}

					/**
					 * Only changed values are added to the SQL Update
					 */
					if changed {
						let fields[] = field, values[] = value;
						let bindTypes[] = bindType;
					}
				}

				let newSnapshot[attributeField] = value;
			} else {
				let newSnapshot[attributeField] = null;
				let fields[] = field, values[] = null, bindTypes[] = bindSkip;
			}
		}

		/**
		 * If there is no fields to update we return true
		 */
		if !count(fields) {
			return true;
		}

		let uniqueKey = model->getUniqueKey(),
			uniqueParams = model->getUniqueParams(),
			uniqueTypes = model->getUniqueTypes();

		/**
		 * When unique params is null we need to rebuild the bind params
		 */
		if typeof uniqueParams != "array" {

			let primaryKeys = metaData->getPrimaryKeyAttributes(model);

			/**
			 * We can't create dynamic SQL without a primary key
			 */
			if !count(primaryKeys) {
				throw new Exception("A primary key must be defined in the model in order to perform the operation");
			}

			let uniqueParams = [];
			for field in primaryKeys {

				/**
				 * Check if the model has a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				if fetch value, model->{attributeField} {
					let newSnapshot[attributeField] = value;
					let uniqueParams[] = value;
				} else {
					let newSnapshot[attributeField] = null;
					let uniqueParams[] = null;
				}
			}
		}

		/**
		 * We build the conditions as an array
		 * Perform the low level update
		 */
		let success = connection->update(table, fields, values, [
			"conditions" : uniqueKey,
			"bind"	     : uniqueParams,
			"bindTypes"  : uniqueTypes
		], bindTypes);

		if success && this->isKeepingSnapshots(model) && globals_get("orm.update_snapshot_on_save") {
			if typeof snapshot == "array" {
				let newSnapshot = array_merge(snapshot, newSnapshot);
				let oldSnapshot = snapshot;
			} else {
				let oldSnapshot = [];
			}

			model->updateSnapshot(newSnapshot, oldSnapshot);
		}

		return success;
	}

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * $robot = $robotsRepository->findFirst("id=100");
	 *
	 * $modelsManager->delete($robot);
	 *
	 * $robots = $robotsRepository->find("type = 'mechanical'");
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
			}

			/**
			 * The operation can be skipped
			 */
			if model->isSkipped() {
				return true;
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
			relationClass, referencedModelRepository, fields, referencedFields,
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
			if isset foreignKey["action"] {
				let action = (int) foreignKey["action"];
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
			let referencedModelRepository = this->getRepository(relationClass);

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
			if referencedModelRepository->count([join(" AND ", conditions), "bind": bindParams]) {

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
			resultset, conditions, bindParams, referencedModelRepository,
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
			if isset foreignKey["action"] {
				let action = (int) foreignKey["action"];
			}

			/**
			 * Check only if the operation is restrict
			 */
			if action != Relation::ACTION_CASCADE {
				continue;
			}

			let referencedModelRepository = this->getRepository(relation->getReferencedModel());

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
			let resultset = referencedModelRepository->find([
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
