
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
	protected function setSource(string source) -> <Phalcon\Mvc\Model>
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
	protected function setSchema(string schema) -> <Phalcon\Mvc\Model>
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
	public static function query(dependencyInjector=null)
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
	protected static function _groupResult(string functionName, string alias, var parameters) -> <Phalcon\Mvc\Model\ResultsetInterface>
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
		//@todo return firstRow->{alias};
		return null;
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
	public static function count(parameters=null)
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
	public static function sum(parameters=null)
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
	 * @param array $parameters
	 * @return mixed
	 */
	public static function maximum($parameters=null)
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
	 * @param array $parameters
	 * @return double
	 */
	public static function average(parameters=null)
	{
		return self::_groupResult("AVG", "average", parameters);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEvent(string eventName) -> boolean
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
	public function fireEventCancel(string eventName)
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
	 * @param Phalcon\Mvc\Model\MessageInterface $message
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
			resulset, conditions, bindParams, bindTypes, referencedModel,
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
	 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
	 * @param Phalcon\Db\AdapterInterface $connection
	 * @param string $table
	 * @return boolean
	 */
	protected function _doLowInsert($metaData, $connection, $table, $identityField)
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
			snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys;
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
				if !isset bindDataTypes[field] {
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
						let bindTypes[] = bindDataTypes[field];
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
							let bindTypes[] = bindDataTypes[field];
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
				throw new Phalcon_Mvc_Model_Exception("A primary key must be defined in the model in order to perform the operation");
			}

			let uniqueParams = [];
			for field in primaryKeys {

				/**
				 * Check if the model has a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[field] {
						throw new Phalcon_Mvc_Model_Exception("Column '" . field . "' isn't part of the column map");
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

}
