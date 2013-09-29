
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector/Services Container such as Phalcon\DI.
 *
 * <code>
 * $di = new Phalcon\DI();
 *
 * $di->set('modelsManager', function() {
 *      return new Phalcon\Mvc\Model\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
class Manager
	//implements Phalcon_Mvc_Model_ManagerInterface, Phalcon_DI_InjectionAwareInterface, Phalcon_Events_EventsAwareInterface
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
	 *
	 */
	protected _dynamicUpdate;

	protected _namespaceAliases;

	/**
	 * Sets the DependencyInjector container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the DependencyInjector container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a global events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	public function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager) -> <Phalcon\Events\ManagerInterface>
	{
		let this->_eventsManager = eventsManager;
	}

	/**
	 * Returns the internal event manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	public function getEventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		return this->_eventsManager;
	}

	/**
	 * Initializes a model in the model manager
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return boolean
	 */
	public function initialize(<Phalcon\Mvc\ModelInterface> model) -> boolean
	{
		var className, initialized, eventsManager;

		let className = get_class_lower(model);

		let initialized = this->_initialized;

		/**
		 * Models are just initialized once per request
		 */
		if isset initialized[className] {
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
		let eventsManager = <Phalcon\Events\ManagerInterface> this->_eventsManager;
		if typeof eventsManager == "object" {
			eventsManager->fire("modelsManager:afterInitialize", this, model);
		}

		return true;
	}

	/**
	 * Check whether a model is already initialized
	 *
	 * @param string modelName
	 * @return bool
	 */
	public function isInitialized(modelName) -> boolean
	{
		var initialized;
		let initialized = this->_initialized;
		return isset initialized[strtolower(modelName)];
	}

	/**
	 * Get last initialized model
	 *
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function getLastInitialized() -> <Phalcon\Mvc\ModelInterface>
	{
		return this->_lastInitialized;
	}

	/**
	 * Loads a model throwing an exception if it doesn't exist
	 *
	 * @param  string modelName
	 * @param  boolean newInstance
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public function load(string modelName, boolean newInstance=false) -> <Phalcon\Mvc\ModelInterface>
	{
		var initialized, model;

		/**
		 * Check if a model with the same is already loaded
		 */
		let initialized = this->_initialized;
		if fetch model, initialized[strtolower(modelName)] {
			if newInstance {
				return clone model;
			}
			return model;
		}

		/**
		 * Load it using an autoloader
		 */
		if class_exists(modelName) {
			//return new {modelName}(this->_dependencyInjector, this);
		}

		/**
		 * The model doesn't exist throw an exception
		 */
		throw new Phalcon\Mvc\Model\Exception("Model '" . modelName . "' could not be loaded");
	}

	/**
	 * Returns the mapped source for a model
	 *
	 * @param Phalcon\Mvc\Model model
	 * @return string
	 */
	public function getModelSource(<Phalcon\Mvc\ModelInterface> model) -> string
	{
		var sources, entityName, source;

		let entityName = get_class_lower($model);

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
	 *
	 * @param Phalcon\Mvc\Model model
	 * @param string schema
	 * @return string
	 */
	public function setModelSchema(<Phalcon\Mvc\ModelInterface> model, schema) -> string
	{
		let this->_schemas[get_class_lower(model)] = schema;
	}

	/**
	 * Returns the mapped schema for a model
	 *
	 * @param Phalcon\Mvc\Model model
	 * @return string
	 */
	public function getModelSchema(<Phalcon\Mvc\ModelInterface> model) -> string
	{
		var schemas, schema;
		let schemas = this->_schemas;
		if typeof schemas == "array" {
			if fetch schema, schemas[get_class_lower(model)] {
				return schema;
			}
		}
		return null;
	}

	/**
	 * Sets both write and read connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setConnectionService(<Phalcon\Mvc\ModelInterface> model, connectionService)
	{
		var entityName;
		let entityName = get_class_lower(model),
			this->_readConnectionServices[entityName] = connectionService,
			this->_writeConnectionServices[entityName] = connectionService;
	}

	/**
	 * Sets write connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setWriteConnectionService(<Phalcon\Mvc\ModelInterface> model, connectionService)
	{
		let this->_writeConnectionServices[get_class_lower(model)] = connectionService;
	}

	/**
	 * Sets read connection service for a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string connectionService
	 */
	public function setReadConnectionService(<Phalcon\Mvc\ModelInterface> model, connectionService)
	{
		let this->_readConnectionServices[get_class_lower(model)] = connectionService;
	}

	/**
	 * Returns the connection to read data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getReadConnection(<Phalcon\Mvc\ModelInterface> model) -> <Phalcon\Db\AdapterInterface>
	{
		var connectionServices, dependencyInjector, service, connection;

		let connectionServices = this->_readConnectionServices;

		/**
		 * Check if the model has a custom connection service
		 */
		if typeof connectionServices == "array" {
			fetch service, connectionServices[get_class_lower(model)];
		}

		let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Request the connection service from the DI
		 */
		if service {
			let connection = <Phalcon\Db\AdapterInterface> dependencyInjector->getShared(service);
		} else {
			let connection = <Phalcon\Db\AdapterInterface> dependencyInjector->getShared("db");
		}
		if typeof connection != "object" {
			throw new Phalcon\Mvc\Model\Exception("Invalid injected connection service");
		}

		return connection;
	}

	/**
	 * Returns the connection to write data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getWriteConnection(<Phalcon\Mvc\ModelInterface> model) -> <Phalcon\Db\AdapterInterface>
	{
		var connectionServices, dependencyInjector, service, connection;

		let connectionServices = this->_writeConnectionServices;

		/**
		 * Check if the model has a custom connection service
		 */
		if typeof connectionServices == "array" {
			fetch service, connectionServices[get_class_lower(model)];
		}

		let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Request the connection service from the DI
		 */
		if service {
			let connection = <Phalcon\Db\AdapterInterface> dependencyInjector->getShared(service);
		} else {
			let connection = <Phalcon\Db\AdapterInterface> dependencyInjector->getShared("db");
		}
		if typeof connection != "object" {
			throw new Phalcon\Mvc\Model\Exception("Invalid injected connection service");
		}

		return connection;
	}

	/**
	 * Returns the connection service name used to read data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string
	 */
	public function getReadConnectionService(<Phalcon\Mvc\ModelInterface> model) -> string
	{
		var connectionServices, connection;
		let connectionServices = this->_readConnectionServices;
		if typeof connectionServices == "array" {
			if fetch connection, connectionServices[get_class_lower(model)] {
				return connection;
			}
		}
		return "db";
	}

	/**
	 * Returns the connection service name used to write data related to a model
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param string
	 */
	public function getWriteConnectionService(<Phalcon\Mvc\ModelInterface> model) -> string
	{
		var connectionServices, connection;
		let connectionServices = this->_writeConnectionServices;
		if typeof connectionServices == "array" {
			if fetch connection, connectionServices[get_class_lower(model)] {
				return connection;
			}
		}
		return "db";
	}

	/**
	 * Returns a relation by its alias
	 *
	 * @param string modelName
	 * @param string alias
	 * @return Phalcon\Mvc\Model\Relation
	 */
	public function getRelationByAlias(string modelName, string alias) -> <Phalcon\Mvc\Model\Relation>
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

}
