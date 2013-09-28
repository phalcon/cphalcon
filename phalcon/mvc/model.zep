
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

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\Model
 *
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
 *
 * <p>Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.</p>
 *
 * <code>
 *
 * $robot = new Robots();
 * $robot->type = 'mechanical';
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 *
 */
abstract class Model //implements Phalcon\Mvc\ModelInterface, Phalcon\Mvc\Model\ResultInterface,
	//Phalcon\Di\InjectionAwareInterface, Serializable
{

	protected _dependencyInjector;

	protected _modelsManager;

	protected _modelsMetaData;

	protected _errorMessages;

	protected _operationMade = 0;

	protected _dirtyState = 1;

	protected _transaction;

	protected _uniqueKey;

	protected _uniqueParams;

	protected _uniqueTypes;

	protected _skipped;

	protected _related;

	protected _snapshot;

	const OP_NONE = 0;

	const OP_CREATE = 1;

	const OP_UPDATE = 2;

	const OP_DELETE = 3;

	const DIRTY_STATE_PERSISTENT = 0;

	const DIRTY_STATE_TRANSIENT = 1;

	const DIRTY_STATE_DETACHED = 2;

	/**
	 * Phalcon\Mvc\Model constructor
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param Phalcon\Mvc\Model\ManagerInterface modelsManager
	 */
	public final function __construct(<Phalcon\DiInterface> dependencyInjector=null,
			<Phalcon\Mvc\Model\ManagerInterface> modelsManager=null)
	{

		/**
		 * We use a default DI if the user doesn't define one
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Phalcon\Di::getDefault();
		}

		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		let this->_dependencyInjector = dependencyInjector;

		/**
		 * Inject the manager service from the DI
		 */
		if typeof modelsManager != "object" {
			let modelsManager = <Phalcon\Mvc\Model\Manager> dependencyInjector->getShared("modelsManager");
			if typeof modelsManager != "object" {
				throw new Phalcon\Mvc\Model\Exception("The injected service 'modelsManager' is not valid");
			}
		}

		/**
		 * Update the models-manager
		 */
		let this->_modelsManager = modelsManager;

		/**
		 * The manager always initializes the object
		 */
		modelsManager->initialize(this);

		/**
		 * This allows the developer to execute initialization stuff every time an instance is created
		 */
		if method_exists(this, "onConstruct") {
			this->{"onConstruct"}();
		}
	}

	/**
	 * Sets the dependency injection container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a custom events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	protected function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		var modelsManager;
		let modelsManager = this->_modelsManager;
		modelsManager->setCustomEventsManager(this, eventsManager);
	}

	/**
	 * Returns the custom events manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	protected function getEventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		var modelsManager;
		let modelsManager = this->_modelsManager;
		return modelsManager->getCustomEventsManager(this);
	}

	/**
	 * Returns the models meta-data service related to the entity instance
	 *
	 * @return Phalcon\Mvc\Model\MetaDataInterface
	 */
	public function getModelsMetaData() -> <Phalcon\Mvc\Model\MetaDataInterface>
	{
		var metaData, dependencyInjector;

		let metaData = this->_modelsMetaData;
		if typeof metaData != "object" {

			/**
			 * Check if the DI is valid
			 */
			let dependencyInjector = <Phalcon\DiInterface> this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
				throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
			}

			/**
			 * Obtain the models-metadata service from the DI
			 */
			let metaData = <Phalcon\Mvc\Model\MetaDataInterface> dependencyInjector->getShared("modelsMetadata");
			if typeof metaData != "object" {
				throw new Phalcon\Mvc\Model\Exception("The injected service 'modelsMetadata' is not valid");
			}

			/**
			 * Update the models-metada property
			 */
			let this->_modelsMetaData = metaData;
		}
		return metaData;
	}

	/**
	 * Returns the models manager related to the entity instance
	 *
	 * @return Phalcon\Mvc\Model\ManagerInterface
	 */
	public function getModelsManager() -> <Phalcon\Mvc\Model\ManagerInterface>
	{
		return this->_modelsManager;
	}

	/**
	 * Sets a transaction related to the Model instance
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
	 *use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
	 *
	 *try {
	 *
	 *  $txManager = new TxManager();
	 *
	 *  $transaction = $txManager->get();
	 *
	 *  $robot = new Robots();
	 *  $robot->setTransaction($transaction);
	 *  $robot->name = 'WALL·E';
	 *  $robot->created_at = date('Y-m-d');
	 *  if ($robot->save() == false) {
	 *    $transaction->rollback("Can't save robot");
	 *  }
	 *
	 *  $robotPart = new RobotParts();
	 *  $robotPart->setTransaction($transaction);
	 *  $robotPart->type = 'head';
	 *  if ($robotPart->save() == false) {
	 *    $transaction->rollback("Robot part cannot be saved");
	 *  }
	 *
	 *  $transaction->commit();
	 *
	 *} catch (TxFailed $e) {
	 *  echo 'Failed, reason: ', $e->getMessage();
	 *}
	 *
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
	 * @return Phalcon\Mvc\Model
	 */
	public function setTransaction(<Phalcon\Mvc\Model\TransactionInterface> transaction) -> <Phalcon\Mvc\Model>
	{
		if typeof transaction == "object" {
			let this->_transaction = transaction;
			return this;
		}
		throw new Phalcon\Mvc\Model\Exception("Transaction should be an object");
	}

	/**
	 * Sets table name which model should be mapped
	 *
	 * @param string source
	 * @return Phalcon\Mvc\Model
	 */
	protected function setSource(source) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = this->_modelsManager;
		modelsManager->setModelSource(this, source);
		return this;
	}

	/**
	 * Returns table name mapped in the model
	 *
	 * @return string
	 */
	public function getSource() -> string
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getModelSource(this);
	}

	/**
	 * Sets schema name where table mapped is located
	 *
	 * @param string schema
	 * @return Phalcon\Mvc\Model
	 */
	protected function setSchema(schema) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		modelsManager->setModelSchema(this, schema);
		return this;
	}

	/**
	 * Returns schema name where table mapped is located
	 *
	 * @return string
	 */
	public function getSchema() -> string
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getModelSchema(this);
	}

	/**
	 * Sets the DependencyInjection connection service name
	 *
	 * @param string connectionService
	 * @return Phalcon\Mvc\Model
	 */
	public function setConnectionService(string connectionService) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		modelsManager->setConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to read data
	 *
	 * @param string connectionService
	 * @return Phalcon\Mvc\Model
	 */
	public function setReadConnectionService(string connectionService) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		modelsManager->setReadConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to write data
	 *
	 * @param string connectionService
	 * @return Phalcon\Mvc\Model
	 */
	public function setWriteConnectionService(string connectionService) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		modelsManager->setWriteConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Returns the DependencyInjection connection service name used to read data related the model
	 *
	 * @return string
	 */
	public function getReadConnectionService() -> string
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getReadConnectionService(this);
	}

	/**
	 * Returns the DependencyInjection connection service name used to write data related to the model
	 *
	 * @return string
	 */
	public function getWriteConnectionService() -> string
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getWriteConnectionService(this);
	}

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 *
	 * @param int dirtyState
	 * @return Phalcon\Mvc\Model
	 */
	public function setDirtyState(int dirtyState) -> <Phalcon\Mvc\Model>
	{
		let this->_dirtyState = dirtyState;
		return this;
	}

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 *
	 * @return int
	 */
	public function getDirtyState() -> int
	{
		return this->_dirtyState;
	}

	/**
	 * Gets the connection used to read data for the model
	 *
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getReadConnection() -> <Phalcon\Db\AdapterInterface>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getReadConnection(this);
	}

	/**
	 * Gets the connection used to write data to the model
	 *
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getWriteConnection() -> <Phalcon\Db\AdapterInterface>
	{
		var modelsManager, transaction;

		let transaction = <Phalcon\Mvc\Model\TransactionInterface> this->_transaction;
		if typeof transaction == "object" {
			return transaction->getConnection();
		}

		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->getWriteConnection(this);
	}

	/**
	 * Assigns values to a model from an array
	 *
	 *<code>
	 *$robot->assign(array(
	 *  'type' => 'mechanical',
	 *  'name' => 'Astro Boy',
	 *  'year' => 1952
	 *));
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model object
	 * @param array data
	 * @param array columnMap
	 * @return Phalcon\Mvc\Model
	 */
	public function assign(var data, var columnMap=null)
	{
		var key, value, attribute;

		if typeof data != "array" {
			throw new Phalcon\Mvc\Model\Exception("Data to dump in the object must be an Array");
		}

		for key, value in data {

			/**
			 * Only string keys in the data are valid
			 */
			if typeof columnMap == "array" {

				/**
				 * Every field must be part of the column map
				 */
				if fetch attribute, columnMap[key] {
					let this->{attribute} = value;
				} else {
					throw new Phalcon\Mvc\Model\Exception("Column '" . key. "' doesn\'t make part of the column map");
				}
			} else {
				let this->{key} = value;
			}
		}
	}

	/**
	 * Assigns values to a model from an array returning a new model.
	 *
	 *<code>
	 *$robot = \Phalcon\Mvc\Model::cloneResultMap(new Robots(), array(
	 *  'type' => 'mechanical',
	 *  'name' => 'Astro Boy',
	 *  'year' => 1952
	 *));
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model base
	 * @param array data
	 * @param array columnMap
	 * @param int dirtyState
	 * @param boolean keepSnapshots
	 * @return Phalcon\Mvc\Model
	 */
	public static function cloneResultMap(<Phalcon\Mvc\ModelInterface> base, var data, var columnMap,
		int dirtyState=0, boolean keepSnapshots=null) -> <Phalcon\Mvc\Model>
	{
		var object, attribute, key, value;

		if typeof data != "array" {
			throw new Phalcon\Mvc\Model\Exception("Data to dump in the object must be an Array");
		}

		let object = clone base;

		/**
		 * Change the dirty state to persistent
		 */
		object->setDirtyState(dirtyState);

		for key, value in data {

			if typeof key == "string" {

				/**
				 * Only string keys in the data are valid
				 */
				if typeof columnMap == "array" {
					/**
					 * Every field must be part of the column map
					 */
					if fetch attribute, columnMap[key] {
						let object->{attribute} = value;
					} else {
						throw new Phalcon\Mvc\Model\Exception("Column '" . key . "' doesn't make part of the column map");
					}
				} else {
					let object->{key} = value;
				}
			}
		}

		/**
		 * Models that keep snapshots store the original data in t
		 */
		if keepSnapshots {
			object->setSnapshotData(data, columnMap);
		}

		/**
		 * Call afterFetch, this allows the developer to execute actions after a record is fetched from the database
		 */
		if method_exists(object, "afterFetch") {
			object->afterFetch();
		}

		return object;
	}

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array data
	 * @param array columnMap
	 * @param int hydrationMode
	 * @return mixed
	 */
	public static function cloneResultMapHydrate(var data, columnMap, int hydrationMode)
	{
		var hydrate, key, value, attribute;

		if typeof data != "array" {
			throw new Phalcon\Mvc\Model\Exception("Data to hidrate must be an Array");
		}

		/**
		 * If there is no column map and the hydration mode is arrays return the data as it is
		 */
		if typeof columnMap != "array" {
			if hydrationMode == Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS {
				return data;
			}
		}

		/**
		 * Create the destination object according to the hydration mode
		 */
		if hydrationMode == Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS {
			let hydrate = [];
		} else {
			let hydrate = new stdclass();
		}

		for key, value in data {
			if typeof key == "string" {
				if typeof columnMap == "array" {

					/**
					 * Every field must be part of the column map
					 */
					if !fetch attribute, columnMap[key] {
						throw new Phalcon\Mvc\Model\Exception("Column '" . key . "' doesn't make part of the column map");
					}

					if hydrationMode == Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS {
						let hydrate[attribute] = value;
					} else {
						let hydrate->{attribute} = value;
					}
				} else {
					if hydrationMode == Phalcon\Mvc\Model\Resultset::HYDRATE_ARRAYS {
						let hydrate[key] = value;
					} else {
						let hydrate->{key} = value;
					}
				}
			}
		}

		return hydrate;
	}

	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 *<code>
	 *$robot = Phalcon\Mvc\Model::cloneResult(new Robots(), array(
	 *  'type' => 'mechanical',
	 *  'name' => 'Astro Boy',
	 *  'year' => 1952
	 *));
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model $base
	 * @param array data
	 * @param int dirtyState
	 * @return Phalcon\Mvc\Model
	 */
	public static function cloneResult(<Phalcon\Mvc\ModelInterface> base, var data, int dirtyState=0)
	{
		var object, key, value;

		if typeof data != "array" {
			throw new Phalcon\Mvc\Model\Exception("Data to dump in the object must be an Array");
		}

		/**
		 * Clone the base record
		 */
		let object = clone base;

		/**
		 * Mark the object as persistent
		 */
		object->setDirtyState(dirtyState);

		for key, value in data {
			if typeof key != "string" {
				throw new Phalcon\Mvc\Model\Exception("Invalid key in array data provided to dumpResult()");
			}
			let object->{key} = value;
		}

		/**
		 * Call afterFetch, this allows the developer to execute actions after a record is fetched from the database
		 */
		if method_exists(object, "afterFetch") {
			object->afterFetch();
		}

		return object;
	}

	/**
	 * Allows to query a set of records that match the specified conditions
	 *
	 * <code>
	 *
	 * //How many robots are there?
	 * $robots = Robots::find();
	 * echo "There are ", count($robots), "\n";
	 *
	 * //How many mechanical robots are there?
	 * $robots = Robots::find("type='mechanical'");
	 * echo "There are ", count($robots), "\n";
	 *
	 * //Get and print virtual robots ordered by name
	 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
	 * foreach ($robots as $robot) {
	 *	   echo $robot->name, "\n";
	 * }
	 *
	 * //Get first 100 virtual robots ordered by name
	 * $robots = Robots::find(array("type='virtual'", "order" => "name", "limit" => 100));
	 * foreach ($robots as $robot) {
	 *	   echo $robot->name, "\n";
	 * }
	 * </code>
	 *
	 * @param 	array parameters
	 * @return  Phalcon\Mvc\Model\ResultsetInterface
	 */
	public static function find(var parameters=null) -> <Phalcon\Mvc\Model\ResultsetInterface>
	{
		var modelName, params, builder, query, bindParams, bindTypes,
			cache, resultset, hydration;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = new Phalcon\Mvc\Model\Query\Builder(params);
		builder->from(get_called_class());

		let query = builder->getQuery(),
			bindParams = null,
			bindTypes = null;

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {
			//fetch bindTypes, params["bindTypes"];
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		let resultset = query->execute(bindParams, bindTypes);

		/**
		 * Define an hydration mode
		 */
		if typeof resultset == "object" {
			if fetch hydration, params["hydration"] {
				resultset->setHydrateMode(hydration);
			}
		}

		return resultset;
	}

}
