
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
	protected function setSource(string! source) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
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
	protected function setSchema(string! schema) -> <Phalcon\Mvc\Model>
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
	public function setConnectionService(string! connectionService) -> <Phalcon\Mvc\Model>
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
	public function setReadConnectionService(string! connectionService) -> <Phalcon\Mvc\Model>
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
	public function setWriteConnectionService(string! connectionService) -> <Phalcon\Mvc\Model>
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
	 * @param array data
	 * @param array columnMap
	 * @return Phalcon\Mvc\Model
	 */
	public function assign(var data, var columnMap=null) -> <Phalcon\Mvc\Model>
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

		return this;
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
		var params, builder, query, bindParams, bindTypes, cache, resultset, hydration;

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
			fetch bindTypes, params["bindTypes"];
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

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * <code>
	 *
	 * //What's the first robot in robots table?
	 * $robot = Robots::findFirst();
	 * echo "The robot name is ", $robot->name;
	 *
	 * //What's the first mechanical robot in robots table?
	 * $robot = Robots::findFirst("type='mechanical'");
	 * echo "The first mechanical robot name is ", $robot->name;
	 *
	 * //Get first virtual robot ordered by name
	 * $robot = Robots::findFirst(array("type='virtual'", "order" => "name"));
	 * echo "The first virtual robot name is ", $robot->name;
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return Phalcon\Mvc\Model
	 */
	public static function findFirst(parameters=null) -> <Phalcon\Mvc\Model>
	{
		var params, builder, query, bindParams, bindTypes, cache;

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

		/**
		 * We only want the first record
		 */
		builder->limit(1);
		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		let bindParams = null, bindTypes = null;
		if fetch bindParams, params["bind"] {
			fetch bindTypes, params["bindTypes"];
		}

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Return only the first row
		 */
		query->setUniqueRow(true);

		/**
		 * Execute the query passing the bind-params and casting-types
		 */
		return query->execute(bindParams, bindTypes);
	}

	/**
	 * Create a criteria for a specific model
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return Phalcon\Mvc\Model\Criteria
	 */
	public static function query(<Phalcon\DiInterface> dependencyInjector=null) -> <Phalcon\Mvc\Model\Criteria>
	{
		var criteria;

		/**
		 * Use the global dependency injector if there is no one defined
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Phalcon\Di::getDefault();
		}

		let criteria = new Phalcon\Mvc\Model\Criteria();
		criteria->setDI(dependencyInjector);
		criteria->setModelName(get_called_class());

		return criteria;
	}

	/**
	 * Checks if the current record already exists or not
	 *
	 * @param Phalcon\Mvc\Model\MetadataInterface metaData
	 * @param Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @return boolean
	 */
	protected function _exists(<Phalcon\Mvc\Model\MetadataInterface> metaData,
		<Phalcon\Db\AdapterInterface> connection, var table=null) -> boolean
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
		let uniqueKey = this->_uniqueKey;
		if uniqueKey === null {

			let primaryKeys = metaData->getPrimaryKeyAttributes(this),
				bindDataTypes = metaData->getBindTypes(this);

			let numberPrimary = count(primaryKeys);
			if !numberPrimary {
				return false;
			}

			/**
			 * Check if column renaming is globally activated
			 */
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(this);
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
						throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				/**
				 * If the primary key attribute is set append it to the conditions
				 */
				let value = null;
				if 1 { //@todo fetch value, this->{attributeField}

					/**
					 * We count how many fields are empty, if all fields are empy we don't perform an 'exist' check
					 */
					if empty value {
						let numberEmpty++;
					}
					let uniqueParams[] = value;

				} else {
					let uniqueParams[] = null,
						numberEmpty++;
				}

				if !fetch type, bindDataTypes[field] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the table columns");
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
			let this->_uniqueKey = joinWhere,
				this->_uniqueParams = uniqueParams,
				this->_uniqueTypes = uniqueTypes,
				uniqueKey = joinWhere;
		}

		/**
		 * If we already know if the record exists we don't check it
		 */
		if !this->_dirtyState {
			return true;
		}

		if uniqueKey === null {
			let uniqueKey = this->_uniqueKey;
		}

		if uniqueParams === null {
			let uniqueParams = this->_uniqueParams;
		}

		if uniqueTypes === null {
			let uniqueTypes = this->_uniqueTypes;
		}

		let schema = this->getSchema(), source = this->getSource();
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
			let this->_dirtyState = 0;
			return true;
		} else {
			let this->_dirtyState = 1;
		}

		return false;
	}

	/**
	 * Generate a PHQL SELECT statement for an aggregate
	 *
	 * @param string function
	 * @param string alias
	 * @param array parameters
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	protected static function _groupResult(string! functionName, string! alias, var parameters) -> <Phalcon\Mvc\Model\ResultsetInterface>
	{
		var params, distinctColumn, groupColumn, columns,
			bindParams, bindTypes, resultset, cache, firstRow, groupColumns,
			builder, query;

		if typeof parameters != "array" {
			let params = [];
			if parameters !== null {
				let params[] = parameters;
			}
		} else {
			let params = parameters;
		}

		if !fetch groupColumn, params["column"] {
			let groupColumn = '*';
		}

		/**
		 * Builds the columns to query according to the received parameters
		 */
		if fetch distinctColumn, params["distinct"] {
			let columns = functionName . "(DISTINCT " . distinctColumn . ") AS " . alias;
		} else {
			if fetch groupColumns, params["group"] {
				let columns = groupColumns . ", " . functionName . "(" . groupColumn . ") AS " . alias;
			} else {
				let columns = functionName . "(" . groupColumn . ") AS " . alias;
			}
		}

		/**
		 * Builds a query with the passed parameters
		 */
		let builder = new Phalcon\Mvc\Model\Query\Builder(params);
		builder->columns(columns);
		builder->from(get_called_class());

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		let bindParams = null, bindTypes = null;
		if fetch bindParams, params["bind"] {
			fetch bindTypes, params["bindTypes"];
		}

		/**
		 * Execute the query
		 */
		let resultset = query->execute(bindParams, bindTypes);

		/**
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Return the full resultset if the query is grouped
		 */
		if isset params["group"] {
			return resultset;
		}

		/**
		 * Return only the value in the first result
		 */
		let firstRow = resultset->getFirst();
		return firstRow->{alias};
	}

	/**
	 * Allows to count how many records match the specified conditions
	 *
	 * <code>
	 *
	 * //How many robots are there?
	 * $number = Robots::count();
	 * echo "There are ", $number, "\n";
	 *
	 * //How many mechanical robots are there?
	 * $number = Robots::count("type='mechanical'");
	 * echo "There are ", $number, " mechanical robots\n";
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function count(var parameters=null)
	{
		return self::_groupResult("COUNT", "rowcount", parameters);
	}

	/**
	 * Allows to calculate a summatory on a column that match the specified conditions
	 *
	 * <code>
	 *
	 * //How much are all robots?
	 * $sum = Robots::sum(array('column' => 'price'));
	 * echo "The total price of robots is ", $sum, "\n";
	 *
	 * //How much are mechanical robots?
	 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
	 * echo "The total price of mechanical robots is  ", $sum, "\n";
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function sum(var parameters=null)
	{
		return self::_groupResult("SUM", "sumatory", parameters);
	}

	/**
	 * Allows to get the maximum value of a column that match the specified conditions
	 *
	 * <code>
	 *
	 * //What is the maximum robot id?
	 * $id = Robots::maximum(array('column' => 'id'));
	 * echo "The maximum robot id is: ", $id, "\n";
	 *
	 * //What is the maximum id of mechanical robots?
	 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
	 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function maximum(var parameters=null)
	{
		return self::_groupResult("MAX", "maximum", parameters);
	}

	/**
	 * Allows to get the minimum value of a column that match the specified conditions
	 *
	 * <code>
	 *
	 * //What is the minimum robot id?
	 * $id = Robots::minimum(array('column' => 'id'));
	 * echo "The minimum robot id is: ", $id;
	 *
	 * //What is the minimum id of mechanical robots?
	 * $sum = Robots::minimum(array("type='mechanical'", 'column' => 'id'));
	 * echo "The minimum robot id of mechanical robots is ", $id;
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function minimum(parameters=null)
	{
		return self::_groupResult("MIN", "minimum", parameters);
	}

	/**
	 * Allows to calculate the average value on a column matching the specified conditions
	 *
	 * <code>
	 *
	 * //What's the average price of robots?
	 * $average = Robots::average(array('column' => 'price'));
	 * echo "The average price is ", $average, "\n";
	 *
	 * //What's the average price of mechanical robots?
	 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
	 * echo "The average price of mechanical robots is ", $average, "\n";
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return double
	 */
	public static function average(var parameters=null)
	{
		return self::_groupResult("AVG", "average", parameters);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEvent(string! eventName) -> boolean
	{
		var modelsManager;

		/**
		 * Check if there is a method with the same name of the event
		 */
		if method_exists(this, eventName) {
			this->{eventName}();
		}

		/**
		 * Send a notification to the events manager
		 */
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		return modelsManager->notifyEvent(eventName, this);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEventCancel(string! eventName)
	{
		var modelsManager;

		/**
		 * Check if there is a method with the same name of the event
		 */
		if method_exists(this, eventName) {
			if this->{eventName}() === false {
				return false;
			}
		}

		/**
		 * Send a notification to the events manager
		 */
		let modelsManager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;
		if modelsManager->notifyEvent(eventName, this) === false {
			return false;
		}

		return true;
	}

	/**
	 * Cancel the current operation
	 *
	 */
	protected function _cancelOperation()
	{
		if this->_operationMade == self::OP_DELETE {
			this->fireEvent("notDeleted");
		} else {
			this->fireEvent("notSaved");
		}
	}

	/**
	 * Appends a customized message on the validation process
	 *
	 * <code>
	 * use \Phalcon\Mvc\Model\Message as Message;
	 *
	 * class Robots extends Phalcon\Mvc\Model
	 * {
	 *
	 *   public function beforeSave()
	 *   {
	 *     if ($this->name == 'Peter') {
	 *        $message = new Message("Sorry, but a robot cannot be named Peter");
	 *        $this->appendMessage($message);
	 *     }
	 *   }
	 * }
	 * </code>
	 *
	 * @param Phalcon\Mvc\Model\MessageInterface message
	 * @return Phalcon\Mvc\Model
	 */
	public function appendMessage(<Phalcon\Mvc\Model\MessageInterface> message) -> <Phalcon\Mvc\Model>
	{
		let this->_errorMessages[] = message;
		return this;
	}

	/**
	 * Executes validators on every validation call
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
	 *
	 *class Subscriptors extends Phalcon\Mvc\Model
	 *{
	 *
	 *	public function validation()
	 *  {
	 * 		$this->validate(new ExclusionIn(array(
	 *			'field' => 'status',
	 *			'domain' => array('A', 'I')
	 *		)));
	 *		if ($this->validationHasFailed() == true) {
	 *			return false;
	 *		}
	 *	}
	 *
	 *}
	 *</code>
	 *
	 * @param object validator
	 * @return Phalcon\Mvc\Model
	 */
	protected function validate(validator) -> <Phalcon\Mvc\Model>
	{
		var message;

		/**
		 * Valid validators are objects
		 */
		if typeof validator != "object" {
			throw new Phalcon\Mvc\Model\Exception("Validator must be an Object");
		}

		/**
		 * Call the validation, if it returns false we append the messages to the current object
		 */
		if validator->validate(this) === false {
			for message in validator->getMessages() {
				let this->_errorMessages[] = message;
			}
		}

		return this;
	}

	/**
	 * Check whether validation process has generated any messages
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
	 *
	 *class Subscriptors extends Phalcon\Mvc\Model
	 *{
	 *
	 *	public function validation()
	 *  {
	 * 		$this->validate(new ExclusionIn(array(
	 *			'field' => 'status',
	 *			'domain' => array('A', 'I')
	 *		)));
	 *		if ($this->validationHasFailed() == true) {
	 *			return false;
	 *		}
	 *	}
	 *
	 *}
	 *</code>
	 *
	 * @return boolean
	 */
	public function validationHasFailed() -> boolean
	{
		var errorMessages;
		let errorMessages = this->_errorMessages;
		if typeof errorMessages == "array" {
			if count(errorMessages) {
				return true;
			}
		}
		return false;
	}

	/**
	 * Returns all the validation messages
	 *
	 *<code>
	 *	$robot = new Robots();
	 *	$robot->type = 'mechanical';
	 *	$robot->name = 'Astro Boy';
	 *	$robot->year = 1952;
	 *	if ($robot->save() == false) {
	 *  	echo "Umh, We can't store robots right now ";
	 *  	foreach ($robot->getMessages() as $message) {
	 *			echo $message;
	 *		}
	 *	} else {
	 *  	echo "Great, a new robot was saved successfully!";
	 *	}
	 * </code>
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getMessages()
	{
		return this->_errorMessages;
	}

	/**
	 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
	 * to verify that inserted/updated values are present in the related entity
	 *
	 * @return boolean
	 */
	protected function _checkForeignKeysRestrict() -> boolean
	{
		var manager, belongsTo, foreignKey, relation, conditions,
			position, bindParams, extraConditions, message, fields,
			referencedFields, field, action, referencedModel, value;
		boolean error;

		/**
		 * Get the models manager
		 */
		let manager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;

		/**
		 * We check if some of the belongsTo relations act as virtual foreign key
		 */
		let belongsTo = manager->getBelongsTo(this);
		if count(belongsTo) {

			let error = false;
			for relation in belongsTo {

				let foreignKey = relation->getForeignKey();
				if foreignKey !== false {

					/**
					 * By default action is restrict
					 */
					let action = Phalcon\Mvc\Model\Relation::ACTION_RESTRICT;

					/**
					 * Try to find a different action in the foreign key's options
					 */
					if typeof foreignKey == "array" {
						fetch action, foreignKey["action"];
					}

					/**
					 * Check only if the operation is restrict
					 */
					if action == Phalcon\Mvc\Model\Relation::ACTION_RESTRICT {

						/**
						 * Load the referenced model if needed
						 */
						let referencedModel = manager->load(relation->getReferencedModel());

						/**
						 * Since relations can have multiple columns or a single one, we need to build a condition for each of these cases
						 */
						let conditions = [], bindParams = [];

						let fields = relation->getFields(),
							referencedFields = relation->getReferencedFields();

						if typeof fields == "array" {
							/**
							 * Create a compound condition
							 */
							for position, field in fields {
								fetch value, this->{field};
								let conditions[] = "[" . referencedFields[position] . "] = ?" . position,
									bindParams[] = value;
							}
						} else {
							fetch value, this->{fields};
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
						 * We don't trust the actual values in the object and pass the values using bound parameters
						 * Let's make the checking
						 */
						if !referencedModel->count([join(" AND ", conditions), "bind": bindParams]) {

							/**
							 * Get the user message or produce a new one
							 */
							if !fetch message, foreignKey["message"] {
								if typeof fields == "array" {
									let message = "Value of fields '" . join(", ", fields) . "' does not exist on referenced table";
								} else {
									let message = "Value of field '" . fields . "' does not exist on referenced table";
								}
							}

							/**
							 * Create a message
							 */
							this->appendMessage(new Phalcon\Mvc\Model\Message(message, fields, "ConstraintViolation"));
							let error = true;
							break;
						}

					}
				}
			}

			/**
			 * Call 'onValidationFails' if the validation fails
			 */
			if error === true {
				if globals_get("orm.events") {
					this->fireEvent("onValidationFails");
					this->_cancelOperation();
				}
				return false;
			}
		}

		return true;
	}

	/**
	 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
	 *
	 * @return boolean
	 */
	protected function _checkForeignKeysReverseCascade() -> boolean
	{

		var manager, relations, relation, foreignKey,
			resulset, conditions, bindParams, referencedModel,
			referencedFields, action, fields, field, position, value,
			extraConditions;

		/**
		 * Get the models manager
		 */
		let manager = <Phalcon\Mvc\Model\ManagerInterface> this->_modelsManager;

		/**
		 * We check if some of the hasOne/hasMany relations is a foreign key
		 */
		let relations = manager->getHasOneAndHasMany(this);

		if count(relations) {

			for relation in relations {

				/**
				 * Check if the relation has a virtual foreign key
				 */
				let foreignKey = relation->getForeignKey();
				if foreignKey !== false {

					/**
					 * By default action is restrict
					 */
					let action = Phalcon\Mvc\Model\Relation::NO_ACTION;

					/**
					 * Try to find a different action in the foreign key's options
					 */
					if typeof foreignKey == "array" {
						fetch action, foreignKey["action"];
					}

					/**
					 * Check only if the operation is restrict
					 */
					if action == Phalcon\Mvc\Model\Relation::ACTION_CASCADE {

						/**
						 * Load a plain instance from the models manager
						 */
						let referencedModel = manager->load(relation->getReferencedModel());

						let fields = relation->getFields(),
							referencedFields = relation->getReferencedFields();

						/**
						 * Create the checking conditions. A relation can has many fields or a single one
						 */
						let conditions = [], bindParams = [];

						if typeof fields == "array" {
							for position, field in fields {
								fetch value, this->{field};
								let conditions[] = "[". referencedFields[position] . "] = ?" . position,
									bindParams[] = value;
							}
						} else {
							fetch value, this->{fields};
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
						let resulset = referencedModel->find([join(" AND ", conditions), "bind": bindParams]);

						/**
						 * Delete the resultset
						 * Stop the operation if needed
						 */
						if resulset->delete() === false {
							return false;
						}
					}
				}
			}

		}

		return true;
	}

	/**
	 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
	 *
	 * @return boolean
	 */
	protected function _checkForeignKeysReverseRestrict() -> boolean
	{
		boolean error;
		var manager, relations, foreignKey, action, relation,
			relationClass, referencedModel, fields, referencedFields,
			conditions, bindParams,position, field,
			value, extraConditions, message;

		/**
		 * Get the models manager
		 */
		let manager = this->_modelsManager;

		/**
		 * We check if some of the hasOne/hasMany relations is a foreign key
		 */
		let relations = manager->getHasOneAndHasMany(this);
		if count(relations) {

			let error = false;
			for relation in relations {

				/**
				 * Check if the relation has a virtual foreign key
				 */
				let foreignKey = relation->getForeignKey();
				if foreignKey !== false {

					/**
					 * By default action is restrict
					 */
					let action = 1;

					/**
					 * Try to find a different action in the foreign key's options
					 */
					if typeof foreignKey == "array" {
						fetch action, foreignKey["action"];
					}

					/**
					 * Check only if the operation is restrict
					 */
					if action == 1 {

						let relationClass = relation->getReferencedModel();

						/**
						 * Load a plain instance from the models manager
						 */
						let referencedModel = manager->load(relationClass);

						let fields = relation->getFields(),
							referencedFields = relation->getReferencedFields();

						/**
						 * Create the checking conditions. A relation can has many fields or a single one
						 */
						let conditions = [], bindParams = [];

						if typeof fields == "array" {
							for position, field in fields {
								fetch value, this->{field};
								let conditions[] = "[" . referencedFields[position] . "] = ?" . position,
									bindParams[] = value;
							}
						} else {
							fetch value, this->{fields};
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
							this->appendMessage(new Phalcon\Mvc\Model\Message(message, fields, "ConstraintViolation"));
							let error = true;
							break;
						}
					}
				}
			}

			/**
			 * Call validation fails event
			 */
			if error === true {
				if globals_get("orm.events") {
					this->fireEvent("onValidationFails");
					this->_cancelOperation();
				}
				return false;
			}
		}

		return true;
	}

	/**
	 * Executes internal hooks before save a record
	 *
	 * @param Phalcon\Mvc\Model\MetadataInterface metaData
	 * @param boolean exists
	 * @param string identityField
	 * @return boolean
	 */
	protected function _preSave(<Phalcon\Mvc\Model\MetadataInterface> metaData, boolean exists, var identityField) -> boolean
	{

		var notNull, columnMap, dataTypeNumeric, automaticAttributes, field, attributeField, value;
		boolean error, isNull;

		/**
		 * Run Validation Callbacks Before
		 */
		if globals_get("orm.events") {

			/**
			 * Call the beforeValidation
			 */
			if this->fireEventCancel("beforeValidation") ===false {
				return false;
			}

			/**
			 * Call the specific beforeValidation event for the current action
			 */
			if exists {
				if this->fireEventCancel("beforeValidationOnCreate") === false {
					return false;
				}
			} else {
				if this->fireEventCancel("beforeValidationOnUpdate") === false {
					return false;
				}
			}
		}

		/**
		 * Check for Virtual foreign keys
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysRestrict() === false {
				return false;
			}
		}

		/**
		 * Columns marked as not null are automatically validated by the ORM
		 */
		if globals_get("orm.not_null_validations") {

			let notNull = metaData->getNotNullAttributes(this);
			if typeof notNull == "array" {

				/**
				 * Gets the fields that are numeric, these are validated in a diferent way
				 */
				let dataTypeNumeric = metaData->getDataTypesNumeric(this);

				if globals_get("orm.column_renaming") {
					let columnMap = metaData->getColumnMap(this);
				} else {
					let columnMap = null;
				}

				/**
				 * Get fields that must be omitted from the SQL generation
				 */
				if exists {
					let automaticAttributes = metaData->getAutomaticUpdateAttributes(this);
				} else {
					let automaticAttributes = metaData->getAutomaticCreateAttributes(this);
				}

				let error = false;
				for field in notNull {

					/**
					 * We don"t check fields that must be omitted
					 */
					if !isset automaticAttributes[field] {

						let isNull = false;

						if typeof columnMap == "array" {
							if !fetch attributeField, columnMap[field] {
								throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the column map");
							}
						} else {
							let attributeField = field;
						}

						/**
						 * Field is null when: 1) is not set, 2) is numeric but its value is not numeric, 3) is null or 4) is empty string
						 * Read the attribute from the this_ptr using the real or renamed name
						 */
						if fetch value, this->{attributeField} {

							/**
							 * Objects are never treated as null, numeric fields must be numeric to be accepted as not null
							 */
							if typeof value != "object" {
								if !isset dataTypeNumeric[field] {
									if empty value {
										let isNull = true;
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
							}

							/**
							 * A implicit PresenceOf message is created
							 */
							let this->_errorMessages[] = new Phalcon\Mvc\Model\Message(attributeField . " is required", attributeField, "PresenceOf"),
								error = true;
						}
					}
				}

				if error === true {
					if globals_get("orm.events") {
						this->fireEvent("onValidationFails");
						this->_cancelOperation();
					}
					return false;
				}
			}
		}

		/**
		 * Call the main validation event
		 */
		if this->fireEventCancel("validation") === false {
			if globals_get("orm.events") {
				this->fireEvent("onValidationFails");
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
				if this->fireEventCancel("afterValidationOnCreate") === false {
					return false;
				}
			} else {
				if this->fireEventCancel("afterValidationOnUpdate") === false {
					return false;
				}
			}

			if this->fireEventCancel("afterValidation") === false {
				return false;
			}

			/**
			 * Run Before Callbacks
			 */
			if this->fireEventCancel("beforeSave") === false {
				return false;
			}

			let this->_skipped = false;

			/**
			 * The operation can be skipped here
			 */
			if exists {
				if this->fireEventCancel("beforeUpdate") === false {
					return false;
				}
			} else {
				if this->fireEventCancel("beforeCreate") === false {
					return false;
				}
			}

			/**
			 * Always return true if the operation is skipped
			 */
			if this->_skipped === true {
				return true;
			}

		}

		return true;
	}

	/**
	 * Executes internal events after save a record
	 *
	 * @param boolean success
	 * @param boolean exists
	 * @return boolean
	 */
	protected function _postSave(boolean success, boolean exists) -> boolean
	{

		if success === true {
			if exists {
				this->fireEvent("afterUpdate");
			} else {
				this->fireEvent("afterCreate");
			}
			this->fireEvent("afterSave");
			return success;
		}

		this->fireEvent("notSave");
		this->_cancelOperation();
		return false;
	}

	/**
	 * Sends a pre-build INSERT SQL statement to the relational database system
	 *
	 * @param Phalcon\Mvc\Model\MetadataInterface metaData
	 * @param Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @param boolean|string identityField
	 * @return boolean
	 */
	protected function _doLowInsert(<Phalcon\Mvc\Model\MetadataInterface> metaData, <Phalcon\Db\AdapterInterface> connection,
		table, identityField)
	{
		var bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes,
			field, columnMap, value, attributeField, success, bindType, defaultValue, sequenceName;
		boolean useExplicitIdentity;

		let bindSkip = Phalcon\Db\Column::BIND_SKIP;

		let fields = [],
			values = [],
			bindTypes = [];

		let attributes = metaData->getAttributes(this),
			bindDataTypes = metaData->getBindTypes(this),
			automaticAttributes = metaData->getAutomaticCreateAttributes(this);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(this);
		} else {
			let columnMap = null;
		}

		/**
		 * All fields in the model makes part or the INSERT
		 */
		for field in attributes {

			if !isset automaticAttributes[field] {

				/**
				 * Check if the model has a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				/**
				 * Check every attribute in the model except identity field
				 */
				if field != identityField {

					let fields[] = field;

					/**
					 * This isset checks that the property be defined in the model
					 */
					if fetch value, this->{attributeField} {

						/**
						 * Every column must have a bind data type defined
						 */
						if !fetch bindType, bindDataTypes[field] {
							throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' have not defined a bind data type");
						}

						let values[] = value, bindTypes[] = bindType;
					} else {
						let values[] = null, bindTypes[] = bindSkip;
					}
				}
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
					throw new Phalcon\Mvc\Model\Exception("Identity column '" . identityField . "' isn't part of the column map");
				}
			} else {
				let attributeField = identityField;
			}

			/**
			 * Check if the developer set an explicit value for the column
			 */
			if fetch value, this->{attributeField} {

				if empty value {
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
						throw new Phalcon\Mvc\Model\Exception("Identity column '" . identityField . "' isn\'t part of the table columns");
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
				if method_exists(this, "getSequenceName") {
					let sequenceName = this->{"getSequenceName"}();
				} else {
					let sequenceName = this->getSource() . "_" . identityField . "_seq";
				}
			}

			/**
			 * Recover the last "insert id" and assign it to the object
			 */
			let this->{attributeField} = connection->lastInsertId(sequenceName);

			/**
			 * Since the primary key was modified, we delete the _uniqueParams to force any future update to re-build the primary key
			 */
			let this->_uniqueParams = null;
		}

		return success;
	}

	/**
	 * Sends a pre-build UPDATE SQL statement to the relational database system
	 *
	 * @param Phalcon\Mvc\Model\MetaDataInterface metaData
	 * @param Phalcon\Db\AdapterInterface connection
	 * @param string|array table
	 * @return boolean
	 */
	protected function _doLowUpdate(<Phalcon\Mvc\Model\MetaDataInterface> metaData, <Phalcon\Db\AdapterInterface> connection, var table) -> boolean
	{
		var bindSkip, fields, values, bindTypes, manager, bindDataTypes, field,
			automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes,
			snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType;
		boolean useDynamicUpdate, changed;

		let bindSkip = Phalcon\Db\Column::BIND_SKIP,
			fields = [],
			values = [],
			bindTypes = [],
			manager = this->_modelsManager;

		/**
		 * Check if the model must use dynamic update
		 */
		let useDynamicUpdate = (boolean) manager->isUsingDynamicUpdate(this);

		if useDynamicUpdate {
			let snapshot = this->_snapshot;
			if typeof snapshot != "array" {
				let useDynamicUpdate = false;
			}
		}

		let bindDataTypes = metaData->getBindTypes(this),
			nonPrimary = metaData->getNonPrimaryKeyAttributes(this),
			automaticAttributes = metaData->getAutomaticUpdateAttributes(this);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(this);
		} else {
			let columnMap = null;
		}

		/**
		 * We only make the update based on the non-primary attributes, values in primary key attributes are ignored
		 */
		for field in nonPrimary {

			if !isset automaticAttributes[field] {

				/**
				 * Check a bind type for field to update
				 */
				if !fetch bindType, bindDataTypes[field] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' have not defined a bind data type");
				}

				/**
				 * Check if the model has a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				/**
				 * Get the field's value
				 * If a field isn't set we pass a null value
				 */
				if fetch value, this->{attributeField} {

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
							let changed = value != snapshotValue;
						}

						/**
						 * Only changed values are added to the SQL Update
						 */
						if changed {
							let fields[] = field, values[] = value;
							let bindTypes[] = bindType;
						}
					}

				} else {
					let fields[] = field, values[] = null, bindTypes[] = bindSkip;
				}
			}
		}

		/**
		 * If there is no fields to update we return true
		 */
		if !count(fields) {
			return true;
		}

		let uniqueKey = this->_uniqueKey,
			uniqueParams = this->_uniqueParams,
			uniqueTypes = this->_uniqueTypes;

		/**
		 * When unique params is null we need to rebuild the bind params
		 */
		if typeof uniqueParams != "array" {

			let primaryKeys = metaData->getPrimaryKeyAttributes(this);

			/**
			 * We can't create dynamic SQL without a primary key
			 */
			if !count(primaryKeys) {
				throw new Phalcon\Mvc\Model\Exception("A primary key must be defined in the model in order to perform the operation");
			}

			let uniqueParams = [];
			for field in primaryKeys {

				/**
				 * Check if the model has a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Phalcon\Mvc\Model\Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				if fetch value, this->{attributeField} {
					let uniqueParams[] = value;
				} else {
					let uniqueParams[] = null;
				}

			}
		}

		/**
		 * We build the conditions as an array
		 * Perform the low level update
		 */
		return connection->update(table, fields, values, [
			"conditions": uniqueKey,
			"bind"      : uniqueParams,
			"bindTypes" : uniqueTypes
		], bindTypes);
	}

	/**
	 * Saves related records that must be stored prior to save the master record
	 *
	 * @param Phalcon\Db\AdapterInterface connection
	 * @param Phalcon\Mvc\ModelInterface[] related
	 * @return boolean
	 */
	protected function _preSaveRelatedRecords(<Phalcon\Db\AdapterInterface> connection, related) -> boolean
	{
		var className, manager, type, relation, columns, referencedFields,
			referencedModel, message, nesting, name, record;

		let nesting = false;

		/**
		 * Start an implicit transaction
		 */
		connection->begin(nesting);

		let className = get_class(this),
			manager = this->getModelsManager();

		for name, record in related {

			/**
			 * Try to get a relation with the same name
			 */
			let relation = manager->getRelationByAlias(className, name);
			if typeof relation == "object" {

				/**
				 * Get the relation type
				 */
				let type = relation->getType();

				/**
				 * Only belongsTo are stored before save the master record
				 */
				if type == 0 {

					if typeof record != "object" {
						connection->rollback(nesting);
						throw new Phalcon\Mvc\Model\Exception("Only objects can be stored as part of belongs-to relations");
					}

					let columns = relation->getFields(),
						referencedModel = relation->getReferencedModel(),
						referencedFields = relation->getReferencedFields();

					if typeof columns == "array" {
						connection->rollback(nesting);
						throw new Phalcon\Mvc\Model\Exception("Not implemented");
					}

					/**
					 * If dynamic update is enabled, saving the record must not take any action
					 */
					if !record->save() {

						/**
						 * Get the validation messages generated by the referenced model
						 */
						for message in record->getMessages() {

							/**
							 * Set the related model
							 */
							if typeof record == "object" {
								message->setModel(record);
							}

							/**
							 * Appends the messages to the current model
							 */
							this->appendMessage(message);
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
					let this->{columns} = record->readAttribute(referencedFields);
				}

			}
		}

		return true;
	}

	/**
	 * Save the related records assigned in the has-one/has-many relations
	 *
	 * @param Phalcon\Db\AdapterInterface connection
	 * @param Phalcon\Mvc\ModelInterface[] related
	 * @return boolean
	 */
	protected function _postSaveRelatedRecords(<Phalcon\Db\AdapterInterface> connection, related) -> boolean
	{
		var nesting, className, manager, relation, name, record, message,
			columns, referencedModel, referencedFields, relatedRecords, value,
			recordAfter, intermediateModel, intermediateFields, intermediateValue,
			intermediateModelName, intermediateReferencedFields;
		boolean isThrough;

		let nesting = false,
			className = get_class(this),
			manager = this->getModelsManager();

		for name, record in related {

			/**
			 * Try to get a relation with the same name
			 */
			let relation = manager->getRelationByAlias(className, name);
			if typeof relation == "object" {

				/**
				 * Discard belongsTo relations
				 */
				if relation->getType() == 0 {
					continue;
				}

				if typeof record != "object" {
					if typeof record != "array" {
						connection->rollback(nesting);
						throw new Phalcon\Mvc\Model\Exception("Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations");
					}
				}

				let columns = relation->getFields(),
					referencedModel = $relation->getReferencedModel(),
					referencedFields = $relation->getReferencedFields();

				if typeof columns == "array" {
					connection->rollback(nesting);
					throw new Phalcon\Mvc\Model\Exception("Not implemented");
				}

				/**
				 * Create an implicit array for has-many/has-one records
				 */
				if typeof record == "object" {
					let relatedRecords = [record];
				} else {
					let relatedRecords = record;
				}

				if !fetch value, this->{columns} {
					connection->rollback(nesting);
					throw new Phalcon\Mvc\Model\Exception("The column '" . columns . "' needs to be present in the model");
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

					} else {

						/**
						 * Create a new instance of the intermediate model
						 */
						let intermediateModel = manager->load(intermediateModelName, true);

						/**
						 * Write value in the intermediate model
						 */
						intermediateModel->writeAttribute(intermediateFields, value);

						/**
						 * Get the value from the referenced model
						 */
						let intermediateValue = recordAfter->{referencedFields};

						/**
						 * Write the intermediate value in the intermediate model
						 */
						intermediateModel->writeAttribute(intermediateReferencedFields, intermediateValue);

						/**
						 * Save the record and get messages
						 */
						if !intermediateModel->save() {

							/**
							 * Get the validation messages generated by the referenced model
							 */
							for message in intermediateModel->getMessages() {

								/**
								 * Set the related model
								 */
								if typeof message != "object" {
									message->setModel(record);
								}

								/**
								 * Appends the messages to the current model
								 */
								this->appendMessage(message);
							}

							/**
							 * Rollback the implicit transaction
							 */
							connection->rollback(nesting);
							return false;
						}
					}

					/**
					 * Save the record and get messages
					 */
					if !recordAfter->save() {

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
							this->appendMessage(message);
						}

						/**
						 * Rollback the implicit transaction
						 */
						connection->rollback(nesting);
						return false;
					}
				}
			} else {
				if typeof record != "array" {
					connection->rollback(nesting);
					throw new Phalcon\Mvc\Model\Exception("There are no defined relations for the model '" . className . "' using alias '" . name . "'");
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
	 * Inserts or updates a model instance. Returning true on success or false otherwise.
	 *
	 *<code>
	 *	//Creating a new robot
	 *	$robot = new Robots();
	 *	$robot->type = 'mechanical';
	 *	$robot->name = 'Astro Boy';
	 *	$robot->year = 1952;
	 *	$robot->save();
	 *
	 *	//Updating a robot name
	 *	$robot = Robots::findFirst("id=100");
	 *	$robot->name = "Biomass";
	 *	$robot->save();
	 *</code>
	 *
	 * @param array data
	 * @param array whiteList
	 * @return boolean
	 */
	public function save(var data=null, var whiteList=null) -> boolean
	{
		var metaData, attribute, attributes, related,
			schema, possibleSetter, value, writeConnection, readConnection,
			source, table, identityField, exists, success;

		let metaData = this->getModelsMetaData();

		/**
		 * Assign the values passed
		 */
		if data !== null {

			if typeof data != "array" {
				throw new Phalcon\Mvc\Model\Exception("Data passed to save() must be an array");
			}

			/**
			 * Get the reversed column map for future renamings
			 */
			let attributes = metaData->getColumnMap(this);
			if typeof attributes == "array" {
				/**
				 * Use the standard column map if there are no renamings
				 */
				let attributes = metaData->getAttributes(this);
			}

			for attribute in attributes {

				if fetch value, data[attribute] {

					/**
					 * If the white-list is an array check if the attribute is on that list
					 */
					if typeof whiteList == "array" {
						if !in_array(attribute, whiteList) {
							continue;
						}
					}

					/**
					 * We check if the field has a setter
					 */
					let possibleSetter = "set" . attribute;
					if method_exists(this, possibleSetter) {
						this->{possibleSetter}(value);
					} else {
						/**
						 * Otherwise we assign the attribute directly
						 */
						let this->{attribute} = value;
					}
				}

			}
		}

		/**
		 * Create/Get the current database connection
		 */
		let writeConnection = this->getWriteConnection();

		/**
		 * Save related records in belongsTo relationships
		 */
		let related = this->_related;
		if typeof related == "array" {
			if this->_preSaveRelatedRecords(writeConnection, related) === false {
				return false;
			}
		}

		let schema = this->getSchema(),
			source = this->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		/**
		 * Create/Get the current database connection
		 */
		let readConnection = this->getReadConnection();

		/**
		 * We need to check if the record exists
		 */
		let exists = this->_exists(metaData, readConnection, table);
		if exists {
			let this->_operationMade = self::OP_UPDATE;
		} else {
			let this->_operationMade = self::OP_CREATE;
		}

		/**
		 * Clean the messages
		 */
		let this->_errorMessages = [];

		/**
		 * Query the identity field
		 */
		let identityField = metaData->getIdentityField(this);

		/**
		 * _preSave() makes all the validations
		 */
		if this->_preSave(metaData, exists, identityField) === false {

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
				throw new Phalcon\Mvc\Model\ValidationFailed(this, this->_errorMessages);
			}

			return false;
		}

		/**
		 * Depending if the record exists we do an update or an insert operation
		 */
		if exists {
			let success = this->_doLowUpdate(metaData, writeConnection, table);
		} else {
			let success = this->_doLowInsert(metaData, writeConnection, table, identityField);
		}

		/**
		 * Change the dirty state to persistent
		 */
		if success {
			let this->_dirtyState = self::DIRTY_STATE_PERSISTENT;
		}

		/**
		 * _postSave() makes all the validations
		 */
		if globals_get("orm.events") {
			let success = this->_postSave(success, exists);
		}

		if typeof related == "array" {

			/**
			 * Rollbacks the implicit transaction if the master save has failed
			 */
			if success === false {
				writeConnection->rollback(false);
				return false;
			}

			/**
			 * Save the post-related records
			 */
			if this->_postSaveRelatedRecords(writeConnection, related) === false {
				return false;
			}
		}

		return success;
	}

	/**
	 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 *<code>
	 *	//Creating a new robot
	 *	$robot = new Robots();
	 *	$robot->type = 'mechanical';
	 *	$robot->name = 'Astro Boy';
	 *	$robot->year = 1952;
	 *	$robot->create();
	 *
	 *  //Passing an array to create
	 *  $robot = new Robots();
	 *  $robot->create(array(
	 *      'type' => 'mechanical',
	 *      'name' => 'Astroy Boy',
	 *      'year' => 1952
	 *  ));
	 *</code>
	 *
	 * @param array data
	 * @param array whiteList
	 * @return boolean
	 */
	public function create(var data=null, var whiteList=null) -> boolean
	{
		var metaData, attribute, possibleSetter, value, columnMap, attributeField;

		let metaData = this->getModelsMetaData();

		/**
		 * Assign the values passed
		 */
		if data !== null {

			if typeof data != "array" {
				throw new Phalcon\Mvc\Model\Exception("Data passed to create() must be an array");
			}

			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(this);
			} else {
				let columnMap = null;
			}

			/**
			 * We assign the fields starting from the current attributes in the model
			 */
			for attribute in metaData->getAttributes(this) {

				/**
				 * Check if we need to rename the field
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[attribute]{
						throw new Phalcon\Mvc\Model\Exception("Column '" . attribute . "' isn't part of the column map");
					}
				} else {
					let attributeField = attribute;
				}

				/**
				 * The value in the array passed
				 * Check if we there is data for the field
				 */
				if fetch value, data[attributeField] {

					/**
					 * If the white-list is an array check if the attribute is on that list
					 */
					if typeof whiteList == "array" {
						if !in_array(attributeField, whiteList) {
							continue;
						}
					}

					/**
					 * Check if the field has a posible setter
					 */
					let possibleSetter = "set" . attributeField;
					if method_exists(this, possibleSetter) {
						this->{possibleSetter}(value);
					} else {
						let this->{attributeField} = value;
					}
				}
			}
		}

		/**
		 * Get the current connection
		 * If the record already exists we must throw an exception
		 */
		if this->_exists(metaData, this->getReadConnection()) {
			let this->_errorMessages = [
				new Phalcon\Mvc\Model\Message("Record cannot be created because it already exists", null, "InvalidCreateAttempt")
			];
			return false;
		}

		/**
		 * Using save() anyways
		 */
		return this->save();
	}

	/**
	 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 *<code>
	 *	//Updating a robot name
	 *	$robot = Robots::findFirst("id=100");
	 *	$robot->name = "Biomass";
	 *	$robot->update();
	 *</code>
	 *
	 * @param array data
	 * @param array whiteList
	 * @return boolean
	 */
	public function update(var data=null, var whiteList=null) -> boolean
	{
		var metaData, columnMap, attribute, attributeField,
			possibleSetter, value;

		let metaData = null;

		/**
		 * Assign the values bassed on the passed
		 */
		if data !== null {

			if typeof data != "array" {
				throw new Phalcon\Mvc\Model\Exception("Data passed to update() must be an array");
			}

			let metaData = this->getModelsMetaData();
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(this);
			} else {
				let columnMap = null;
			}

			/**
			 * We assign the fields starting from the current attributes in the model
			 */
			for attribute in metaData->getAttributes(this) {

				/**
				 * Check if we need to rename the field
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[attribute] {
						throw new Phalcon\Mvc\Model\Exception("Column '" . attribute . "' isn't part of the column map");
					}
				} else {
					let attributeField = attribute;
				}

				/**
				 * Check if we there is data for the field
				 * Reads the attribute from the data
				 */
				if fetch value, data[attributeField] {

					/**
					 * If the white-list is an array check if the attribute is on that list
					 */
					if typeof whiteList == "array" {
						if !in_array(attributeField, whiteList) {
							continue;
						}
					}

					/**
					 * Try to find a possible getter
					 */
					let possibleSetter = "set" . attributeField;
					if method_exists(this, possibleSetter) {
						this->{possibleSetter}(value);
					} else {
						let this->{attributeField} = value;
					}
				}
			}

		}

		/**
		 * We don't check if the record exists if the record is already checked
		 */
		if this->_dirtyState {

			if metaData === null {
				let metaData = this->getModelsMetaData();
			}

			if this->_exists(metaData, this->getReadConnection()) {
				let this->_errorMessages = [new Phalcon\Mvc\Model\Message("Record cannot be updated because it does not exist", null, "InvalidUpdateAttempt")];
				return false;
			}
		}

		/**
		 * Call save() anyways
		 */
		return this->save();
	}

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 *
	 * <code>
	 *$robot = Robots::findFirst("id=100");
	 *$robot->delete();
	 *
	 *foreach (Robots::find("type = 'mechanical'") as $robot) {
	 *   $robot->delete();
	 *}
	 * </code>
	 *
	 * @return boolean
	 */
	public function delete() -> boolean
	{
		var metaData, writeConnection, values, bindTypes, primaryKeys,
			bindDataTypes, columnMap, attributeField, conditions, primaryKey,
			bindType, value, schema, source, table, success;

		let metaData = this->getModelsMetaData(),
			writeConnection = this->getWriteConnection();

		/**
		 * Operation made is OP_DELETE
		 */
		let this->_operationMade = self::OP_DELETE,
			this->_errorMessages = [];

		/**
		 * Check if deleting the record violates a virtual foreign key
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysReverseRestrict() === false {
				return false;
			}
		}

		let values = [],
			bindTypes = [],
			conditions = [];

		let primaryKeys = metaData->getPrimaryKeyAttributes(this),
			bindDataTypes = metaData->getBindTypes(this);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(this);
		} else {
			let columnMap = null;
		}

		/**
		 * We can't create dynamic SQL without a primary key
		 */
		if !count(primaryKeys) {
			throw new Phalcon\Mvc\Model\Exception("A primary key must be defined in the model in order to perform the operation");
		}

		/**
		 * Create a condition from the primary keys
		 */
		for primaryKey in primaryKeys {

			/**
			 * Every column part of the primary key must be in the bind data types
			 */
			if !fetch bindType, bindDataTypes[primaryKey] {
				throw new Phalcon\Mvc\Model\Exception("Column '" . primaryKey . "' have not defined a bind data type");
			}

			/**
			 * Take the column values based on the column map if any
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[primaryKey] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . primaryKey . "' isn't part of the column map");
				}
			} else {
				let attributeField = primaryKey;
			}

			/**
			 * If the attribute is currently set in the object add it to the conditions
			 */
			if !fetch value, this->{attributeField} {
				throw new Phalcon\Mvc\Model\Exception("Cannot delete the record because the primary key attribute: '" . attributeField . "' wasn't set");
			}

			/**
			 * Escape the column identifier
			 */
			let values[] = value,
				conditions[] = writeConnection->escapeIdentifier(primaryKey) . " = ?",
				bindTypes[] = bindType;
		}

		if globals_get("orm.events") {

			let this->_skipped = false;

			/**
			 * Fire the beforeDelete event
			 */
			if this->fireEventCancel("beforeDelete") === false {
				return false;
			} else {
				/**
				 * The operation can be skipped
				 */
				if this->_skipped === true {
					return true;
				}
			}
		}

		let schema = this->getSchema(),
			source = this->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		/**
		 * Join the conditions in the array using an AND operator
		 * Do the deletion
		 */
		let success = writeConnection->delete(table, join(" AND ", $conditions), values, bindTypes);

		/**
		 * Check if there is virtual foreign keys with cascade action
		 */
		if globals_get("orm.virtual_foreign_keys") {
			if this->_checkForeignKeysReverseCascade() === false {
				return false;
			}
		}

		if globals_get("orm.events") {
			if success {
				this->fireEvent("afterDelete");
			}
		}

		/**
		 * Force perform the record existence checking again
		 */
		let this->_dirtyState = self::DIRTY_STATE_DETACHED;

		return success;
	}

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 *
	 * @return int
	 */
	public function getOperationMade()
	{
		return this->_operationMade;
	}

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh()
	{
		var metaData, readConnection, schema, source, table,
			uniqueKey, uniqueParams, dialect, row, fields, attribute;

		if this->_dirtyState != 0 {
			throw new Phalcon\Mvc\Model\Exception("The record cannot be refreshed because it does not exist or is deleted");
		}

		let metaData = this->getModelsMetaData(),
			readConnection = this->getReadConnection();

		let schema = this->getSchema(),
			source = this->getSource();

		if schema {
			let table = [schema, source];
		} else {
			let table = source;
		}

		let uniqueKey = this->_uniqueKey;
		if !uniqueKey {

			/**
			 * We need to check if the record exists
			 */
			if this->_exists(metaData, readConnection, table) {
				throw new Phalcon\Mvc\Model\Exception("The record cannot be refreshed because it does not exist or is deleted");
			}

			let uniqueKey = this->_uniqueKey;
		}

		let uniqueParams = this->_uniqueParams;
		if typeof uniqueParams != "array" {
			throw new Phalcon\Mvc\Model\Exception("The record cannot be refreshed because it does not exist or is deleted");
		}

		/**
		 * We only refresh the attributes in the model's metadata
		 */
		let fields = [];
		for attribute in metaData->getAttributes(this) {
			let fields[] = [attribute];
		}

		/**
		 * We directly build the SELECT to save resources
		 */
		let dialect = readConnection->getDialect(),
			row = readConnection->fetchOne(dialect->select([
				"columns": fields,
				"tables": readConnection->escapeIdentifier(table),
				"where": uniqueKey
			]), Phalcon\Db::FETCH_ASSOC, uniqueParams, this->_uniqueTypes);

		/**
		 * Get a column map if any
		 * Assign the resulting array to the this object
		 */
		if typeof row == "array" {
			this->assign(row, metaData->getColumnMap(this));
		}
	}

	/**
	 * Skips the current operation forcing a success state
	 *
	 * @param boolean skip
	 */
	public function skipOperation(boolean skip)
	{
		let this->_skipped = skip;
	}

	/**
	 * Reads an attribute value by its name
	 *
	 * <code>
	 * echo $robot->readAttribute('name');
	 * </code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(string! attribute)
	{
		if isset this->{attribute} {
			return this->{attribute};
		}
		return null;
	}

	/**
	 * Writes an attribute value by its name
	 *
	 * <code>
	 * 	$robot->writeAttribute('name', 'Rosey');
	 * </code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value)
	{
		let this->{attribute} = value;
	}

	/**
	 * Sets a list of attributes that must be skipped from the
	 * generated INSERT/UPDATE statement
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->skipAttributes(array('price'));
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param array attributes
	 */
	protected function skipAttributes(attributes)
	{
		var keysAttributes, metaData, attribute;

		if typeof attributes != "array" {
			throw new Phalcon\Mvc\Model\Exception("Attributes must be an array");
		}

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		let metaData = this->getModelsMetaData();
		metaData->setAutomaticCreateAttributes(this, keysAttributes);
		metaData->setAutomaticUpdateAttributes(this, keysAttributes);
	}

	/**
	 * Sets a list of attributes that must be skipped from the
	 * generated INSERT statement
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->skipAttributesOnCreate(array('created_at'));
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param array attributes
	 */
	protected function skipAttributesOnCreate(var attributes)
	{
		var keysAttributes, metaData, attribute;

		if typeof attributes != "array" {
			throw new Phalcon\Mvc\Model\Exception("Attributes must be an array");
		}

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		let metaData = this->getModelsMetaData();
		metaData->setAutomaticCreateAttributes(this, keysAttributes);
	}

	/**
	 * Sets a list of attributes that must be skipped from the
	 * generated UPDATE statement
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->skipAttributesOnUpdate(array('modified_in'));
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param array attributes
	 */
	protected function skipAttributesOnUpdate(attributes)
	{
		var keysAttributes, metaData, attribute;

		if typeof attributes != "array" {
			throw new Phalcon\Mvc\Model\Exception("Attributes must be an array");
		}

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		let metaData = this->getModelsMetaData();
		metaData->setAutomaticUpdateAttributes(this, keysAttributes);
	}

	/**
	 * Setup a 1-1 relation between two models
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param	mixed fields
	 * @param	string referenceModel
	 * @param	mixed referencedFields
	 * @param   array options
	 * @return  Phalcon\Mvc\Model\Relation
	 */
	protected function hasOne(fields, string! referenceModel, referencedFields, options=null) -> <Phalcon\Mvc\Model\Relation>
	{
		var manager;
		let manager = this->_modelsManager;
		return manager->addHasOne(this, fields, referenceModel, referencedFields, options);
	}

	/**
	 * Setup a relation reverse 1-1  between two models
	 *
	 *<code>
	 *<?php
	 *
	 *class RobotsParts extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->belongsTo('robots_id', 'Robots', 'id');
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param	mixed fields
	 * @param	string referenceModel
	 * @param	mixed referencedFields
	 * @param   array options
	 * @return  Phalcon\Mvc\Model\Relation
	 */
	protected function belongsTo(fields, string! referenceModel, referencedFields, options=null) -> <Phalcon\Mvc\Model\Relation>
	{
		var manager;
		let manager = this->_modelsManager;
		return manager->addBelongsTo(this, fields, referenceModel, referencedFields, options);
	}

	/**
	 * Setup a relation 1-n between two models
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param	mixed fields
	 * @param	string referenceModel
	 * @param	mixed referencedFields
	 * @param   array options
	 * @return  Phalcon\Mvc\Model\Relation
	 */
	protected function hasMany(fields, string! referenceModel, referencedFields, options=null) -> <Phalcon\Mvc\Model\Relation>
	{
		var manager;
		let manager = this->_modelsManager;
		return manager->addHasMany(this, fields, referenceModel, referencedFields, options);
	}

	/**
	 * Setup a relation n-n between two models through an intermediate relation
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *       //Setup a many-to-many relation to Parts through RobotsParts
	 *       $this->hasManyToMany(
	 *			'id',
	 *			'RobotsParts',
	 *			'robots_id',
	 *			'parts_id',
	 *			'Parts',
	 *			'id'
	 *		);
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param	string|array fields
	 * @param	string intermediateModel
	 * @param	string|array intermediateFields
	 * @param	string|array intermediateReferencedFields
	 * @param	string referencedModel
	 * @param   string|array referencedFields
	 * @param   array options
	 * @return  Phalcon\Mvc\Model\Relation
	 */
	protected function hasManyToMany(fields, string! intermediateModel, intermediateFields, intermediateReferencedFields,
		string referenceModel, referencedFields, options=null) -> <Phalcon\Mvc\Model\Relation>
	{
		var manager;
		let manager = this->_modelsManager;
		return manager->addHasManyToMany(
			this,
			fields,
			intermediateModel,
			intermediateFields,
			intermediateReferencedFields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Setups a behavior in a model
	 *
	 *<code>
	 *<?php
	 *
	 *use Phalcon\Mvc\Model\Behavior\Timestampable;
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *		$this->addBehavior(new Timestampable(array(
	 *			'onCreate' => array(
	 *				'field' => 'created_at',
	 *				'format' => 'Y-m-d'
	 *			)
	 *		)));
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model\BehaviorInterface behavior
	 */
	protected function addBehavior(<Phalcon\Mvc\Model\BehaviorInterface> behavior)
	{
		var manager;
		let manager = this->_modelsManager;
		manager->addBehavior(this, behavior);
	}

	/**
	 * Sets if the model must keep the original record snapshot in memory
     *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *		$this->keepSnapshots(true);
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param boolean keepSnapshots
	 */
	protected function keepSnapshots(boolean keepSnapshot)
	{
		var manager;
		let manager = this->_modelsManager;
		manager->keepSnapshots(this, keepSnapshot);
	}

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array data
	 * @param array columnMap
	 */
	public function setSnapshotData(data, columnMap=null)
	{
		var key, value, snapshot, attribute;

		if typeof data == "array" {
			throw new Phalcon\Mvc\Model\Exception("The snapshot data must be an array");
		}

		/**
		 * Build the snapshot based on a column map
		 */
		if typeof columnMap == "array" {

			let snapshot = [];
			for key, value in data {

				/**
				 * Use only strings
				 */
				if typeof key != "string" {
					continue;
				}

				/**
				 * Every field must be part of the column map
				 */
				if !fetch attribute, columnMap[key] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . key . "' doesn't make part of the column map");
				}

				let snapshot[attribute] = value;
			}

			let this->_snapshot = snapshot;
			return null;
		}

		let this->_snapshot = data;
	}

	/**
	 * Checks if the object has internal snapshot data
	 *
	 * @return boolean
	 */
	public function hasSnapshotData() -> boolean
	{
		var snapshot;
		let snapshot = this->_snapshot;
		if typeof snapshot == "array" {
			return true;
		}
		return false;
	}

	/**
	 * Returns the internal snapshot data
	 *
	 * @return array
	 */
	public function getSnapshotData()
	{
		return this->_snapshot;
	}

	/**
	 * Check if a specific attribute has changed
	 * This only works if the model is keeping data snapshots
	 *
	 * @param string|array fieldName
	 */
	public function hasChanged(var fieldName=null) -> boolean
	{
		var snapshot, metaData, columnMap, allAttributes, value,
			originalValue, name, type;

		let snapshot = this->_snapshot;
		if typeof snapshot != "array" {
			throw new Phalcon\Mvc\Model\Exception("The record doesn't have a valid data snapshot");
		}

		/**
		 * Dirty state must be DIRTY_PERSISTENT to make the checking
		 */
		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Phalcon\Mvc\Model\Exception("Change checking cannot be performed because the object has not been persisted or is deleted");
		}

		/**
		 * Return the models meta-data
		 */
		let metaData = this->getModelsMetaData();

		/**
		 * The reversed column map is an array if the model has a column map
		 */
		let columnMap = metaData->getReverseColumnMap(this);

		/**
		 * Data types are field indexed
		 */
		if typeof columnMap != "array" {
			let allAttributes = metaData->getDataTypes(this);
		} else {
			let allAttributes = columnMap;
		}

		/**
		 * If a field was specified we only check it
		 */
		if typeof fieldName == "array" {

			/**
			 * We only make this validation over valid fields
			 */
			if typeof columnMap == "array" {
				if !isset columnMap[fieldName] {
					throw new Phalcon\Mvc\Model\Exception("The field '" . fieldName . "' is not part of the model");
				}
			} else {
				if !isset allAttributes[fieldName] {
					throw new Phalcon\Mvc\Model\Exception("The field '" . fieldName . "' is not part of the model");
				}
			}

			/**
			 * The field is not part of the model, throw exception
			 */
			if !fetch value, this->{fieldName} {
				throw new Phalcon\Mvc\Model\Exception("The field '" . fieldName . "' is not defined on the model");
			}

			/**
			 * The field is not part of the data snapshot, throw exception
			 */
			if !fetch originalValue, snapshot[fieldName] {
				throw new Phalcon\Mvc\Model\Exception("The field '" . fieldName . "' was not found in the snapshot");
			}

			/**
			 * Check if the field has changed
			 */
			return value != originalValue;
		}

		/**
		 * Check every attribute in the model
		 */
		for name, type in allAttributes {

			/**
			 * If some attribute is not present in the snapshot, we assume the record as changed
			 */
			if !fetch originalValue, snapshot[name] {
				return true;
			}

			/**
			 * If some attribute is not present in the model, we assume the record as changed
			 */
			if !fetch value, this->{name} {
				return true;
			}

			/**
			 * Check if the field has changed
			 */
			if value != originalValue {
				return true;
			}
		}

		return false;
	}

	/**
	 * Returns a list of changed values
	 *
	 * @return array
	 */
	public function getChangedFields()
	{
		var metaData, changed, name, type, snapshot,
			columnMap, allAttributes, value;

		let snapshot = this->_snapshot;
		if typeof snapshot != "array" {
			throw new Phalcon\Mvc\Model\Exception("The record doesn't have a valid data snapshot");
		}

		/**
		 * Dirty state must be DIRTY_PERSISTENT to make the checking
		 */
		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Phalcon\Mvc\Model\Exception("Change checking cannot be performed because the object has not been persisted or is deleted");
		}

		/**
		 * Return the models meta-data
		 */
		let metaData = this->getModelsMetaData();

		/**
		 * The reversed column map is an array if the model has a column map
		 */
		let columnMap = metaData->getReverseColumnMap(this);

		/**
		 * Data types are field indexed
		 */
		if typeof columnMap != "array" {
			let allAttributes = metaData->getDataTypes(this);
		} else {
			let allAttributes = columnMap;
		}

		/**
		 * Check every attribute in the model
		 */
		let changed = [];
		for name, type in allAttributes {

			/**
			 * If some attribute is not present in the snapshot, we assume the record as changed
			 */
			if !isset snapshot[name] {
				let changed[] = name;
				continue;
			}

			/**
			 * If some attribute is not present in the model, we assume the record as changed
			 */
			if !fetch value, this->{name} {
				let changed[] = name;
				continue;
			}

			/**
			 * Check if the field has changed
			 */
			if value != snapshot[name] {
				let changed[] = name;
				continue;
			}

		}

		return changed;
	}

	/**
	 * Sets if a model must use dynamic update instead of the all-field update
     *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Model
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *		$this->useDynamicUpdate(true);
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param boolean dynamicUpdate
	 */
	protected function useDynamicUpdate(boolean dynamicUpdate)
	{
		var manager;
		let manager = this->_modelsManager;
		manager->useDynamicUpdate(this, dynamicUpdate);
	}

	/**
	 * Returns related records based on defined relations
	 *
	 * @param string alias
	 * @param array arguments
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getRelated(string alias, arguments=null) -> <Phalcon\Mvc\Model\ResultsetInterface>
	{
		var manager, relation, className;

		let manager = this->_modelsManager;

		/**
		 * Query the relation by alias
		 */
		let className = get_class(this),
			relation = manager->getRelationByAlias(className, alias);
		if typeof relation != "object" {
			throw new Phalcon\Mvc\Model\Exception("There is no defined relations for the model '" . className . "' using alias '" . alias . "'");
		}

		/**
		 * Call the 'getRelationRecords' in the models manager
		 */
		return call_user_func_array(
			[manager, "getRelationRecords"],
			[relation, null, this, arguments]
		);
	}

	/**
	 * Returns related records defined relations depending on the method name
	 *
	 * @param string modelName
	 * @param string method
	 * @param array arguments
	 * @return mixed
	 */
	protected function _getRelatedRecords(string modelName, string method, arguments)
	{
		var manager, relation, queryMethod, extraArgs;

		let manager = this->_modelsManager;

		let relation = false,
			queryMethod = null;

		/**
		 * Calling find/findFirst if the method starts with "get"
		 */
		if starts_with(method, "get") {
			let relation = manager->getRelationByAlias(modelName, substr(method, 3));
		}

		/**
		 * Calling count if the method starts with "count"
		 */
		if typeof relation != "object" {
			if starts_with(method, "count") {
				let queryMethod = "count",
					relation = manager->getRelationByAlias("count", substr(method, 5));
			}
		}

		/**
		 * If the relation was found perform the query via the models manager
		 */
		if typeof relation == "object" {
			fetch extraArgs, arguments[0];
			return call_user_func_array(
				[manager, "getRelationRecords"],
				[relation, queryMethod, this, extraArgs]
			);
		}

		return null;
	}

	/**
	 * Handles method calls when a method is not implemented
	 *
	 * @param	string method
	 * @param	array arguments
	 * @return	mixed
	 */
	public function __call(string method, arguments=null)
	{
		var modelName, modelsManager, status, records;

		let modelName = get_class(this);

		/**
		 * Check if there is a default action using the magic getter
		 */
		let records = this->_getRelatedRecords(modelName, method, arguments);
		if records!==null {
			return records;
		}

		/**
		 * Try to find a replacement for the missing method in a behavior/listener
		 */
		let modelsManager = this->_modelsManager,
			status = modelsManager->missingMethod(this, method, arguments);
		if status !== null {
			return status;
		}

		/**
		 * The method doesn't exist throw an exception
		 */
		throw new Phalcon\Mvc\Model\Exception("The method '" . method . "' doesn't exist on model '" . modelName . "'");
	}

	/**
	 * Handles method calls when a static method is not implemented
	 *
	 * @param	string method
	 * @param	array arguments
	 * @return	mixed
	 */
	public static function __callStatic(string method, arguments=null)
	{
		var extraMethod, type, modelName, value, model,
			attributes, field, extraMethodFirst, metaData;

		let extraMethod = null;

		/**
		 * Check if the method starts with "findFirst"
		 */
		if start_with(method, "findFirstBy") {
			let type = "findFirst",
				extraMethod = substr(method, 11);
		}

		/**
		 * Check if the method starts with "find"
		 */
		if extraMethod === null {
			if starts_with(method, "findBy") {
				let type = "find",
					extraMethod = substr(method, 6);
			}
		}

		/**
		 * Check if the method starts with "count"
		 */
		if extraMethod === null {
			if starts_with(method, "countBy") {
				let type = "count",
					extraMethod = substr(method, 7);
			}
		}

		/**
		 * The called class is the model
		 */
		let modelName = get_called_class();

		if extraMethod {
			throw new Phalcon\Mvc\Model\Exception("The static method '" . method . "' doesn't exist on model '" . modelName . "'");
		}

		if !fetch value, arguments[0] {
			throw new Phalcon\Mvc\Model\Exception("The static method '" . method . "' requires one argument");
		}

		let model = new {modelName}(),
			metaData = model->getModelsMetaData();

		/**
		 * Get the attributes
		 */
		let attributes = metaData->getReverseColumnMap(model);
		if typeof attributes != "array" {
			let attributes = metaData->getDataTypes(model);
		}

		/**
		 * Check if the extra-method is an attribute
		 */
		if isset attributes[extraMethod] {
			let field = extraMethod;
		} else {

			/**
			 * Lowercase the first letter of the extra-method
			 */
			let extraMethodFirst = lcfirst(extraMethod);
			if isset attributes[extraMethodFirst] {
				let field = extraMethodFirst;
			} else {

				/**
				 * Get the possible real method name
				 */
				let field = uncamelize(extraMethod);
				if !isset attributes[field] {
					throw new Phalcon\Mvc\Model\Exception("Cannot resolve attribute '" . extraMethod . "' in the model");
				}
			}
		}

		/**
		 * Execute the query
		 */
		return {modelName}::{type}([
			"conditions": field . " = ?0",
			"bind"      : [value]
		]);
	}

	/**
	 * Magic method to assign values to the the model
	 *
	 * @param string property
	 * @param mixed value
	 */
	public function __set(string property, value)
	{
		var lowerProperty;

		/**
		 * Values are probably relationships if they are objects
		 */
		if typeof value == "object" {
			if value instanceof Phalcon\Mvc\ModelInterface {
				let lowerProperty = strtolower(property),
					this->{lowerProperty} = value,
					this->_related[lowerProperty] = value,
					this->_dirtyState = 1;
				return value;
			}
		}

		/**
		 * Check if the value is an array
		 */
		if typeof value == "array" {
			let lowerProperty = strtolower(property),
				this->_related[lowerProperty] = value,
				this->_dirtyState = 1;
			return value;
		}

		/**
		 * Fallback assigning the value to the instance
		 */
		let this->{property} = value;

		return value;
	}

	/**
	 * Magic method to get related records using the relation alias as a property
	 *
	 * @param string property
	 * @return Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
	 */
	public function __get(string! property)
	{
		var modelName, manager, lowerProperty, relation, result;

		let modelName = get_class(this),
			manager = this->getModelsManager(),
			lowerProperty = strtolower(property);

		/**
		 * Check if the property is a relationship
		 */
		let relation = manager->getRelationByAlias(modelName, lowerProperty);
		if typeof relation == "object" {

			/**
			 * Get the related records
			 */
			let result = call_user_func_array(
				[manager, "getRelationRecords"],
				[relation, null, this, null]
			);

			/**
			 * Assign the result to the object
			 */
			if typeof result == "object" {

				/**
				 * We assign the result to the instance avoiding future queries
				 */
				let this->{lowerProperty} = result;

				/**
				 * For belongs-to relations we store the object in the related bag
				 */
				if result instanceof Phalcon\Mvc\ModelInterface {
					let this->_related[lowerProperty] = result;
				}
			}

			return result;
		}

		/**
		 * A notice is shown if the property is not defined and it isn't a relationship
		 */
		trigger_error("Access to undefined property " . modelName . "::" . property);
		return null;
	}

	/**
	 * Magic method to check if a property is a valid relation
	 *
	 * @param string property
	 */
	public function __isset(string! property)
	{
		var modelName, manager, relation;

		let modelName = get_class(this),
			manager = this->getModelsManager();

		/**
		 * Check if the property is a relationship
		 */
		let relation = manager->getRelationByAlias(modelName, property);
		if typeof relation == "object" {
			return true;
		}

		return false;
	}

	/**
	 * Serializes the object ignoring connections, services, related objects or static properties
	 *
	 * @return string
	 */
	public function serialize() -> string
	{
		var data, metaData, value, attribute;

		let data = [],
			metaData = this->getModelsMetaData();
		for attribute in metaData->getAttributes(this) {
			if fetch value, this->{attribute} {
				let data[attribute] = value;
			} else {
				let data[attribute] = null;
			}
		}

		/**
		 * Use the standard serialize function to serialize the array data
		 */
		return serialize(data);
	}

	/**
	 * Unserializes the object from a serialized string
	 *
	 * @param string data
	 */
	public function unserialize(var data)
	{
		var attributes, dependencyInjector, manager, key, value;

		if typeof data == "string" {
			let attributes = unserialize(data);
			if typeof attributes == "array" {

				/**
				 * Obtain the default DI
				 */
				let dependencyInjector = Phalcon\Di::getDefault();
				if typeof dependencyInjector != "object" {
					throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
				}

				/**
				 * Update the dependency injector
				 */
				let this->_dependencyInjector = dependencyInjector;

				/**
				 * Gets the default modelsManager service
				 */
				let manager = dependencyInjector->getShared("modelsManager");
				if typeof manager != "object" {
					throw new Phalcon\Mvc\Model\Exception("The injected service 'modelsManager' is not valid");
				}

				/**
				 * Update the models manager
				 */
				let this->_modelsManager = manager;

				/**
				 * Try to initialize the model
				 */
				manager->initialize(this);

				/**
				 * Update the objects attributes
				 */
				for key, value in attributes {
					let this->{key} = value;
				}

				return null;
			}
		}
		throw new Phalcon\Mvc\Model\Exception("Invalid serialization data");
	}

	/**
	 * Returns a simple representation of the object that can be used with var_dump
	 *
	 *<code>
	 * var_dump($robot->dump());
	 *</code>
	 *
	 * @return array
	 */
	public function dump()
	{
		return get_object_vars(this);
	}

	/**
	 * Returns the instance as an array representation
	 *
	 *<code>
	 * print_r($robot->toArray());
	 *</code>
	 *
	 * @return array
	 */
	public function toArray()
	{
		var data, metaData, columnMap, attribute,
			attributeField, value;

		let data = [],
			metaData = this->getModelsMetaData(),
			columnMap = metaData->getColumnMap(this);
		for attribute in metaData->getAttributes(this) {

			/**
			 * Check if the columns must be renamed
			 */
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[attribute] {
					throw new Phalcon\Mvc\Model\Exception("Column '" . attribute . "' doesn't make part of the column map");
				}
			} else {
				let attributeField = attribute;
			}

			if fetch value, this->{attributeField} {
				let data[attributeField] = value;
			} else {
				let data[attributeField] = null;
			}
		}

		return data;
	}

	/**
	 * Enables/disables options in the ORM
	 *
	 * @param array options
	 */
	public static function setup(var options)
	{
		var disableEvents, columnRenaming, notNullValidations,
			exceptionOnFailedSave, phqlLiterals, virtualForeignKeys;

		if typeof options != "array" {
			throw new Phalcon\Mvc\Model\Exception("Options must be an array");
		}

		/**
		 * Enables/Disables globally the internal events
		 */
		if fetch disableEvents, options["events"] {
			globals_set("orm.events", disableEvents);
		}

		/**
		 * Enables/Disables virtual foreign keys
		 */
		if fetch virtualForeignKeys, options["virtualForeignKeys"] {
			globals_set("orm.virtual_foreign_keys", virtualForeignKeys);
		}

		/**
		 * Enables/Disables column renaming
		 */
		if fetch columnRenaming, options["columnRenaming"] {
			globals_set("orm.column_renaming", columnRenaming);
		}

		/**
		 * Enables/Disables automatic not null validation
		 */
		if fetch notNullValidations, options["notNullValidations"] {
			globals_set("orm.not_null_validations", notNullValidations);
		}

		/**
		 * Enables/Disables throws an exception if the saving process fails
		 */
		if fetch exceptionOnFailedSave, options["exceptionOnFailedSave"] {
			globals_set("orm.exception_on_failed_save", exceptionOnFailedSave);
		}

		/**
		 * Enables/Disables literals in PHQL this improves the security of applications
		 */
		if fetch phqlLiterals, options["phqlLiterals"] {
			globals_set("orm.enable_literals", phqlLiterals);
		}

	}

}
