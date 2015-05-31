
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
use Phalcon\Mvc\Model\QueryInterface;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Query\BuilderInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\DI.
 *
 * <code>
 * $di = new \Phalcon\DI();
 *
 * $di->set('modelsManager', function() {
 *      return new \Phalcon\Mvc\Model\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
class Manager implements ManagerInterface, InjectionAwareInterface, EventsAwareInterface
{

	protected _dependencyInjector;

	protected _eventsManager;

	protected _customEventsManager;

	protected _readConnectionServices;

	protected _writeConnectionServices;

	protected _aliases;

	/**
	 * Has many relations
	 */
	protected _hasMany;

	/**
	 * Has many relations by model
	 */
	protected _hasManySingle;

	/**
	 * Has one relations
	 */
	protected _hasOne;

	/**
	 * Has one relations by model
	 */
	protected _hasOneSingle;

	/**
	 * Belongs to relations
	 */
	protected _belongsTo;

	/**
	 * All the relationships by model
	 */
	protected _belongsToSingle;

	/**
	 * Has many-Through relations
	 */
	protected _hasManyToMany;

	/**
	 * Has many-Through relations by model
	 */
	protected _hasManyToManySingle;

	/**
	 * Mark initialized models
	 */
	protected _initialized;

	protected _sources;

	protected _schemas;

	/**
	 * Models' behaviors
	 */
	protected _behaviors;

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
	protected _reusable;

	protected _keepSnapshots;

	/**
	 * Does the model use dynamic update, instead of updating all rows?
	 */
	protected _dynamicUpdate;

	protected _namespaceAliases;

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
		var customEventsManager, eventsManager;
		let customEventsManager = this->_customEventsManager;
		if typeof customEventsManager == "array" {
			if fetch eventsManager, customEventsManager[get_class_lower(model)] {
				return eventsManager;
			}
		}
		return false;
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
		let this->_initialized[className] = model;

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
	public function load(string! modelName, boolean newInstance = false) -> <ModelInterface>
	{
		var model;

		/**
		 * Check if a model with the same is already loaded
		 */
		if fetch model, this->_initialized[strtolower(modelName)] {
			if newInstance {
				return new {modelName}(this->_dependencyInjector, this);
			}
			model->reset();
			return model;
		}

		/**
		 * Load it using an autoloader
		 */
		if class_exists(modelName) {
			return new {modelName}(this->_dependencyInjector, this);
		}

		/**
		 * The model doesn't exist throw an exception
		 */
		throw new Exception("Model '" . modelName . "' could not be loaded");
	}

	/**
	 * Sets the mapped source for a model
	 */
	public function setModelSource(<ModelInterface> model, string! source) -> void
	{
		let this->_sources[get_class_lower(model)] = source;
	}

	/**
	 * Returns the mapped source for a model
	 */
	public function getModelSource(<ModelInterface> model) -> string
	{
		var sources, entityName, source;

		let entityName = get_class_lower(model);

		let sources = this->_sources;
		if typeof sources == "array" {
			if fetch source, sources[entityName] {
				return source;
			}
		}

		let source = uncamelize(get_class_ns(model)),
			this->_sources[entityName] = source;
		return source;
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
		var schemas, schema;
		let schemas = this->_schemas;
		if typeof schemas == "array" {
			if fetch schema, schemas[get_class_lower(model)] {
				return schema;
			}
		}
		return "";
	}

	/**
	 * Sets both write and read connection service for a model
	 */
	public function setConnectionService(<ModelInterface> model, string! connectionService) -> void
	{
		var entityName;
		let entityName = get_class_lower(model),
			this->_readConnectionServices[entityName] = connectionService,
			this->_writeConnectionServices[entityName] = connectionService;
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
		var dependencyInjector, service = null, connection;

		/**
		 * Check if the model has a custom connection service
		 */
		if typeof connectionServices == "array" {
			fetch service, connectionServices[get_class_lower(model)];
		}

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Request the connection service from the DI
		 */
		if service {
			let connection = <AdapterInterface> dependencyInjector->getShared(service);
		} else {
			let connection = <AdapterInterface> dependencyInjector->getShared("db");
		}

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
	 * Returns the connection service name used to read or write data related to a model depending on the connection services
	 */
	public function _getConnectionService(<ModelInterface> model, connectionServices) -> string
	{
		var connection;

		if typeof connectionServices == "array" {
			if fetch connection, connectionServices[get_class_lower(model)] {
				return connection;
			}
		}

		return "db";
	}

	/**
	 * Receives events generated in the models and dispatches them to a events-manager if available
	 * Notify the behaviors that are listening in the model
	 */
	public function notifyEvent(string! eventName, <ModelInterface> model)
	{
		var status, behavior, modelsBehaviors, eventsManager,
			customEventsManager, behaviors;

		let status = null;

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
		let customEventsManager = this->_customEventsManager;
		if typeof customEventsManager == "array" {
			if fetch customEventsManager, customEventsManager[get_class_lower(model)] {
				let status = customEventsManager->fire("model:" . eventName, model);
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
	 */
	public function missingMethod(<ModelInterface> model, string! eventName, var data)
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
		let eventsManager = this->_eventsManager;
		if typeof eventsManager == "object" {
			return eventsManager->fire("model:" . eventName, model, data);
		}

		return null;
	}

	/**
	 * Binds a behavior to a model
	 */
	public function addBehavior(<ModelInterface> model, <\Phalcon\Mvc\Model\BehaviorInterface> behavior)
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
		var keepSnapshots, isKeeping;
		let keepSnapshots = this->_keepSnapshots;
		if typeof keepSnapshots == "array" {
			if fetch isKeeping, keepSnapshots[get_class_lower(model)] {
				return isKeeping;
			}
		}
		return false;
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
		var dynamicUpdate, isUsing;
		let dynamicUpdate = this->_dynamicUpdate;
		if typeof dynamicUpdate == "array" {
			if fetch isUsing, dynamicUpdate[get_class_lower(model)] {
				return isUsing;
			}
		}
		return false;
	}

	/**
	 * Setup a 1-1 relation between two models
	 *
	 * @param   Phalcon\Mvc\Model model
	 * @param	mixed fields
	 * @param	string referencedModel
	 * @param	mixed referencedFields
	 * @param	array options
	 * @return  Phalcon\Mvc\Model\Relation
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
	 * @param   Phalcon\Mvc\Model model
	 * @param	mixed fields
	 * @param	string referencedModel
	 * @param	mixed referencedFields
	 * @param	array options
	 * @return  Phalcon\Mvc\Model\Relation
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
	 * @param 	Phalcon\Mvc\ModelInterface model
	 * @param	mixed fields
	 * @param	string referencedModel
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
	 * @param 	Phalcon\Mvc\ModelInterface model
	 * @param	string fields
	 * @param	string intermediateModel
	 * @param	string intermediateFields
	 * @param	string intermediateReferencedFields
	 * @param	string referencedModel
	 * @param	string referencedFields
	 * @param   array options
	 * @return  Phalcon\Mvc\Model\Relation
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
		var aliases, relation;
		let aliases = this->_aliases;
		if typeof aliases == "array" {
			if fetch relation, aliases[strtolower(modelName . "$" . alias)] {
				return relation;
			}
		}
		return false;
	}

	/**
	 * Helper method to query records based on a relation definition
	 *
	 * @return Phalcon\Mvc\Model\Resultset\Simple|Phalcon\Mvc\Model\Resultset\Simple|false
	 */
	public function getRelationRecords(<RelationInterface> relation, string! method, <ModelInterface> record, var parameters = null)
	{
		var preConditions, placeholders, referencedModel, intermediateModel,
			intermediateFields, joinConditions, fields, builder, extraParameters,
			conditions, refPosition, field, referencedFields, findParams,
			findArguments, retrieveMethod, uniqueKey, records, arguments;
		boolean reusable;

		/**
		 * Re-use conditions
		 */
		let preConditions = null;

		if typeof parameters == "array" {
			if fetch preConditions, parameters[0] {
				unset parameters[0];
			} else {
				if fetch preConditions, parameters["conditions"] {
					unset parameters["conditions"];
				}
			}
		} else {
			if typeof parameters == "string" {
				let preConditions = parameters;
			}
		}

		/**
		 * Re-use bound parameters
		 */
		if typeof parameters == "array" {
			if fetch placeholders, parameters["bind"] {
				unset parameters["bind"];
			} else {
				let placeholders = [];
			}
		} else {
			let placeholders = [];
		}

		/**
		 * Returns parameters that must be always used when the related records are obtained
		 */
		let extraParameters = relation->getParams();
		if typeof extraParameters == "array" {
			if typeof parameters == "array" {
				let parameters = array_merge(parameters, extraParameters);
			} else {
				let parameters = extraParameters;
			}
		}

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
				let conditions[] = "[" . intermediateModel . "].[" . intermediateFields . "] = ?0",
					placeholders[] = record->readAttribute(fields);
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
			 * Add extra conditions passed by the programmer
			 */
			if !empty preConditions {
				let conditions[] = preConditions;
			}

			/**
			 * We don't trust the user or the database so we use bound parameters
			 * Create a query builder
			 */
			let builder = this->createBuilder(parameters);

			builder->from(referencedModel);
			builder->innerJoin(intermediateModel, join(" AND ", joinConditions));
			builder->andWhere(join(" AND ", conditions), placeholders);

			/**
			 * Get the query
			 * Execute the query
			 */
			return builder->getQuery()->execute();
		}

		if preConditions !== null {
			let conditions = [preConditions];
		} else {
			let conditions = [];
		}

		/**
		 * Appends conditions created from the fields defined in the relation
		 */
		let fields = relation->getFields();
		if typeof fields != "array" {
			let conditions[] = "[". relation->getReferencedFields() . "] = ?0",
				placeholders[] = record->readAttribute(fields);
		} else {

			/**
			 * Compound relation
			 */
			let referencedFields = relation->getReferencedFields();
			for refPosition, field in relation->getReferencedFields() {
				let conditions[] = "[". referencedFields[refPosition] . "] = ?" . refPosition,
					placeholders[] = record->readAttribute(field);
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

		if typeof parameters == "array" {
			let findArguments = array_merge(findParams, parameters);
		} else {
			let findArguments = findParams;
		}

		/**
		 * Join conditions in '0' and 'conditions'
		 */
		if isset findArguments[0] && isset findArguments["conditions"] {
			let findArguments[0] = "(" . findArguments[0] . ") AND (" . findArguments["conditions"] . ")";
			unset findArguments["conditions"];
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

		let arguments = [findArguments];

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
		let this->_reusable = null;
	}

	/**
	 * Gets belongsTo related records from a model
	 */
	public function getBelongsToRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ResultsetInterface> | boolean
	{
		var belongsTo, keyRelation, relations;

		let belongsTo = this->_hasMany;
		if typeof belongsTo == "array" {

			/**
			 * Check if there is a relation between them
			 */
			let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
			if !isset belongsTo[keyRelation] {
				return false;
			}

			/**
			 * "relations" is an array with all the belongsTo relationships to that model
			 * Perform the query
			 */
			let relations = belongsTo[keyRelation];
			return this->getRelationRecords(relations[0], method, record, parameters);
		}

		return false;
	}

	/**
	 * Gets hasMany related records from a model
	 */
	public function getHasManyRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ResultsetInterface> | boolean
	{
		var hasMany, keyRelation, relations;

		let hasMany = this->_hasMany;
		if typeof hasMany == "array" {

			/**
			 * Check if there is a relation between them
			 */
			let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
			if !isset hasMany[keyRelation] {
				return false;
			}

			/**
			 * "relations" is an array with all the hasMany relationships to that model
			 * Perform the query
			 */
			let relations = hasMany[keyRelation];
			return this->getRelationRecords(relations[0], method, record, parameters);
		}

		return false;
	}

	/**
	 * Gets belongsTo related records from a model
	 */
	public function getHasOneRecords(string! method, string! modelName, var modelRelation, <ModelInterface> record, parameters = null)
		-> <ModelInterface> | boolean
	{
		var hasOne, keyRelation, relations;

		let hasOne = this->_hasOne;
		if typeof hasOne == "array" {

			/**
			 * Check if there is a relation between them
			 */
			let keyRelation = strtolower(modelName) . "$" . strtolower(modelRelation);
			if !isset hasOne[keyRelation] {
				return false;
			}

			/**
			 * "relations" is an array with all the belongsTo relationships to that model
			 * Perform the query
			 */
			let relations = hasOne[keyRelation];
			return this->getRelationRecords(relations[0], method, record, parameters);
		}

		return false;
	}

	/**
	 * Gets all the belongsTo relations defined in a model
	 *
	 *<code>
	 *	$relations = $modelsManager->getBelongsTo(new Robots());
	 *</code>
	 */
	public function getBelongsTo(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var belongsToSingle, relations;
		let belongsToSingle = this->_belongsToSingle;
		if typeof belongsToSingle == "array" {
			if fetch relations, belongsToSingle[get_class_lower(model)] {
				return relations;
			}
		}
		return [];
	}

	/**
	 * Gets hasMany relations defined on a model
	 */
	public function getHasMany(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var hasManySingle, relations;
		let hasManySingle = this->_hasManySingle;
		if typeof hasManySingle == "array" {
			if fetch relations, hasManySingle[get_class_lower(model)] {
				return relations;
			}

		}
		return [];
	}

	/**
	 * Gets hasOne relations defined on a model
	 */
	public function getHasOne(<ModelInterface> model) -> array
	{
		var hasOneSingle, relations;
		let hasOneSingle = this->_hasOneSingle;
		if typeof hasOneSingle == "array" {
			if fetch relations, hasOneSingle[get_class_lower(model)] {
				return relations;
			}
		}
		return [];
	}

	/**
	 * Gets hasManyToMany relations defined on a model
	 */
	public function getHasManyToMany(<ModelInterface> model) -> <RelationInterface[]> | array
	{
		var hasManyToManySingle, relations;
		let hasManyToManySingle = this->_hasManyToManySingle;
		if typeof hasManyToManySingle == "array" {
			if fetch relations, hasManyToManySingle[get_class_lower(model)] {
				return relations;
			}
		}
		return [];
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
		var entityName, allRelations, relations,
			belongsTo, relation, hasOne, hasMany;

		let entityName = strtolower(modelName),
			allRelations = [];

		/**
		 * Get belongs-to relations
		 */
		let belongsTo = this->_belongsToSingle;
		if typeof belongsTo == "array" {
			if fetch relations, belongsTo[entityName] {
				for relation in relations {
					let allRelations[] = relation;
				}
			}
		}

		/**
		 * Get has-many relations
		 */
		let hasMany = this->_hasManySingle;
		if typeof hasMany == "array" {
			if fetch relations, hasMany[entityName] {
				for relation in relations {
					let allRelations[] = relation;
				}
			}
		}

		/**
		 * Get has-one relations
		 */
		let hasOne = this->_hasOneSingle;
		if typeof hasOne == "array" {
			if fetch relations, hasOne[entityName] {
				for relation in relations {
					let allRelations[] = relation;
				}
			}
		}

		return allRelations;
	}

	/**
	 * Query the first relationship defined between two models
	 */
	public function getRelationsBetween(string! first, string! second) -> <RelationInterface[]> | boolean
	{
		var keyRelation, belongsTo, hasMany, hasOne, relations;

		let keyRelation = strtolower(first) . "$" . strtolower(second);

		/**
		 * Check if it's a belongs-to relationship
		 */
		let belongsTo = this->_belongsTo;
		if typeof belongsTo == "array" {
			if fetch relations, belongsTo[keyRelation] {
				return relations;
			}
		}

		/**
		 * Check if it's a has-many relationship
		 */
		let hasMany = this->_hasMany;
		if typeof hasMany == "array" {
			if fetch relations, hasMany[keyRelation] {
				return relations;
			}
		}

		/**
		 * Check whether it's a has-one relationship
		 */
		let hasOne = this->_hasOne;
		if typeof hasOne == "array" {
			if fetch relations, hasOne[keyRelation] {
				return relations;
			}
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
		var dependencyInjector, query;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injection object is required to access ORM services");
		}

		/**
		 * Gets Query instance from DI container
		 */
		let query = <QueryInterface> dependencyInjector->get("Phalcon\\Mvc\\Model\\Query", [phql, dependencyInjector]);
		let this->_lastQuery = query;

		/**
		 * Execute the query
		 */
		return query->execute(placeholders, types);
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
		return <BuilderInterface> dependencyInjector->get("Phalcon\\Mvc\\Model\\Query\\Builder", [params, dependencyInjector]);
	}

	/**
	 * Returns the lastest query created or executed in the models manager
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
}
