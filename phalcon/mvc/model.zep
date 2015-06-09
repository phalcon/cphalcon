
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

namespace Phalcon\Mvc;

use Phalcon\Di;
use Phalcon\Text;
use Phalcon\Db\Column;
use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Message;
use Phalcon\Mvc\Model\ResultInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Db\AdapterInterface;
use Phalcon\Db\DialectInterface;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Relation;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Mvc\Model\BehaviorInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MetadataInterface;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

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
 * The bulk of your application's business logic will be concentrated in the models.</p>
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
abstract class Model implements ModelInterface, ResultInterface, InjectionAwareInterface, \Serializable
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
	 */
	public final function __construct(<DiInterface> dependencyInjector = null, <ManagerInterface> modelsManager = null)
	{
		/**
		 * We use a default DI if the user doesn't define one
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault();
		}

		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		let this->_dependencyInjector = dependencyInjector;

		/**
		 * Inject the manager service from the DI
		 */
		if typeof modelsManager != "object" {
			let modelsManager = <ManagerInterface> dependencyInjector->getShared("modelsManager");
			if typeof modelsManager != "object" {
				throw new Exception("The injected service 'modelsManager' is not valid");
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
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a custom events manager
	 */
	protected function setEventsManager(<EventsManagerInterface> eventsManager)
	{
		this->_modelsManager->setCustomEventsManager(this, eventsManager);
	}

	/**
	 * Returns the custom events manager
	 */
	protected function getEventsManager() -> <EventsManagerInterface>
	{
		return this->_modelsManager->getCustomEventsManager(this);
	}

	/**
	 * Returns the models meta-data service related to the entity instance
	 */
	public function getModelsMetaData() -> <MetaDataInterface>
	{
		var metaData, dependencyInjector;

		let metaData = this->_modelsMetaData;
		if typeof metaData != "object" {

			/**
			 * Check if the DI is valid
			 */
			let dependencyInjector = <DiInterface> this->_dependencyInjector;
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
			}

			/**
			 * Obtain the models-metadata service from the DI
			 */
			let metaData = <MetaDataInterface> dependencyInjector->getShared("modelsMetadata");
			if typeof metaData != "object" {
				throw new Exception("The injected service 'modelsMetadata' is not valid");
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
	 */
	public function getModelsManager() -> <ManagerInterface>
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
	 */
	public function setTransaction(<TransactionInterface> transaction) -> <Model>
	{
		let this->_transaction = transaction;
		return this;
	}

	/**
	 * Sets table name which model should be mapped
	 */
	protected function setSource(string! source) -> <Model>
	{
		(<ManagerInterface> this->_modelsManager)->setModelSource(this, source);
		return this;
	}

	/**
	 * Returns table name mapped in the model
	 */
	public function getSource() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getModelSource(this);
	}

	/**
	 * Sets schema name where table mapped is located
	 */
	protected function setSchema(string! schema) -> <Model>
	{
		return (<ManagerInterface> this->_modelsManager)->setModelSchema(this, schema);
	}

	/**
	 * Returns schema name where table mapped is located
	 */
	public function getSchema() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getModelSchema(this);
	}

	/**
	 * Sets the DependencyInjection connection service name
	 */
	public function setConnectionService(string! connectionService) -> <Model>
	{
		(<ManagerInterface> this->_modelsManager)->setConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to read data
	 */
	public function setReadConnectionService(string! connectionService) -> <Model>
	{
		(<ManagerInterface> this->_modelsManager)->setReadConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Sets the DependencyInjection connection service name used to write data
	 */
	public function setWriteConnectionService(string! connectionService) -> <Model>
	{
		return (<ManagerInterface> this->_modelsManager)->setWriteConnectionService(this, connectionService);
	}

	/**
	 * Returns the DependencyInjection connection service name used to read data related the model
	 */
	public function getReadConnectionService() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getReadConnectionService(this);
	}

	/**
	 * Returns the DependencyInjection connection service name used to write data related to the model
	 */
	public function getWriteConnectionService() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getWriteConnectionService(this);
	}

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 */
	public function setDirtyState(int dirtyState) -> <ModelInterface>
	{
		let this->_dirtyState = dirtyState;
		return this;
	}

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 */
	public function getDirtyState() -> int
	{
		return this->_dirtyState;
	}

	/**
	 * Gets the connection used to read data for the model
	 */
	public function getReadConnection() -> <AdapterInterface>
	{
		return (<ManagerInterface> this->_modelsManager)->getReadConnection(this);
	}

	/**
	 * Gets the connection used to write data to the model
	 */
	public function getWriteConnection() -> <AdapterInterface>
	{
		var transaction;

		let transaction = <TransactionInterface> this->_transaction;
		if typeof transaction == "object" {
			return transaction->getConnection();
		}

		return (<ManagerInterface> this->_modelsManager)->getWriteConnection(this);
	}

	/**
	 * Assigns values to a model from an array
	 *
	 * <code>
	 * $robot->assign(array(
	 *    'type' => 'mechanical',
	 *    'name' => 'Astro Boy',
	 *    'year' => 1952
	 * ));
	 *
	 * //assign by db row, column map needed
	 * $robot->assign($dbRow, array(
	 *    'db_type' => 'type',
	 *    'db_name' => 'name',
	 *    'db_year' => 'year'
	 * ));
	 *
	 * //allow assign only name and year
	 * $robot->assign($_POST, null, array('name', 'year');
	 *
	 *</code>
	 *
	 * @param array data
	 * @param array dataColumnMap array to transform keys of data to another
	 * @param array whiteList
	 * @return Phalcon\Mvc\Model
	 */
	public function assign(array! data, var dataColumnMap = null, var whiteList = null) -> <Model>
	{
		var key, keyMapped, value, attribute, attributeField, possibleSetter, metaData, columnMap, dataMapped;

		// apply column map for data, if exist
		if typeof dataColumnMap == "array" {
			let dataMapped = [];
			for key, value in data {
				if fetch keyMapped, dataColumnMap[key] {
					let dataMapped[keyMapped] = value;
				}
			}
		} else {
			let dataMapped = data;
		}

		if count(dataMapped) == 0 {
			return this;
		}

		let metaData = this->getModelsMetaData();

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getColumnMap(this);
		} else {
			let columnMap = null;
		}

		for attribute in metaData->getAttributes(this) {

			// Check if we need to rename the field
			if typeof columnMap == "array" {
				if !fetch attributeField, columnMap[attribute] {
					throw new Exception("Column '" . attribute. "' doesn\'t make part of the column map");
				}
			} else {
				let attributeField = attribute;
			}

			// The value in the array passed
			// Check if we there is data for the field
			if fetch value, dataMapped[attributeField] {

				// If white-list exists check if the attribute is on that list
				if typeof whiteList == "array" {
					if !in_array(attributeField, whiteList) {
						continue;
					}
				}

				// Try to find a possible getter
				let possibleSetter = "set" . attributeField;
				if method_exists(this, possibleSetter) {
					this->{possibleSetter}(value);
				} else {
					let this->{attributeField} = value;
				}
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
	 * @param Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row base
	 * @param array data
	 * @param array columnMap
	 * @param int dirtyState
	 * @param boolean keepSnapshots
	 * @return Phalcon\Mvc\Model
	 */
	public static function cloneResultMap(var base, array! data, var columnMap, int dirtyState = 0, boolean keepSnapshots = null) -> <Model>
	{
		var instance, attribute, key, value;

		let instance = clone base;

		/**
		 * Change the dirty state to persistent
		 */
		instance->setDirtyState(dirtyState);

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
						let instance->{attribute} = value;
					} else {
						throw new Exception("Column '" . key . "' doesn't make part of the column map");
					}
				} else {
					let instance->{key} = value;
				}
			}
		}

		/**
		 * Models that keep snapshots store the original data in t
		 */
		if keepSnapshots {
			instance->setSnapshotData(data, columnMap);
		}

		/**
		 * Call afterFetch, this allows the developer to execute actions after a record is fetched from the database
		 */
		if method_exists(instance, "afterFetch") {
			instance->{"afterFetch"}();
		}

		return instance;
	}

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array data
	 * @param array columnMap
	 * @param int hydrationMode
	 * @return mixed
	 */
	public static function cloneResultMapHydrate(array! data, var columnMap, int hydrationMode)
	{
		var hydrateArray, hydrateObject, key, value, attribute;

		/**
		 * If there is no column map and the hydration mode is arrays return the data as it is
		 */
		if typeof columnMap != "array" {
			if hydrationMode == Resultset::HYDRATE_ARRAYS {
				return data;
			}
		}

		/**
		 * Create the destination object according to the hydration mode
		 */
		if hydrationMode == Resultset::HYDRATE_ARRAYS {
			let hydrateArray = [];
		} else {
			let hydrateObject = new \stdclass();
		}

		for key, value in data {
			if typeof key == "string" {
				if typeof columnMap == "array" {

					/**
					 * Every field must be part of the column map
					 */
					if !fetch attribute, columnMap[key] {
						throw new Exception("Column '" . key . "' doesn't make part of the column map");
					}

					if hydrationMode == Resultset::HYDRATE_ARRAYS {
						let hydrateArray[attribute] = value;
					} else {
						let hydrateObject->{attribute} = value;
					}
				} else {
					if hydrationMode == Resultset::HYDRATE_ARRAYS {
						let hydrateArray[key] = value;
					} else {
						let hydrateObject->{key} = value;
					}
				}
			}
		}

		if hydrationMode == Resultset::HYDRATE_ARRAYS {
			return hydrateArray;
		}

		return hydrateObject;
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
	 * @param Phalcon\Mvc\ModelInterface $base
	 * @param array data
	 * @param int dirtyState
	 * @return Phalcon\Mvc\ModelInterface
	 */
	public static function cloneResult(<ModelInterface> base, array! data, int dirtyState = 0)
	{
		var instance, key, value;

		/**
		 * Clone the base record
		 */
		let instance = clone base;

		/**
		 * Mark the object as persistent
		 */
		instance->setDirtyState(dirtyState);

		for key, value in data {
			if typeof key != "string" {
				throw new Exception("Invalid key in array data provided to dumpResult()");
			}
			let instance->{key} = value;
		}

		/**
		 * Call afterFetch, this allows the developer to execute actions after a record is fetched from the database
		 */
		if method_exists(instance, "afterFetch") {
			instance->{"afterFetch"}();
		}

		return instance;
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
	public static function find(var parameters = null) -> <ResultsetInterface>
	{
		var params, builder, query, bindParams, bindTypes, cache, resultset, hydration, dependencyInjector, manager;
		let dependencyInjector = \Phalcon\Di::getDefault();
		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

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
		let builder = manager->createBuilder(params);
		builder->from(get_called_class());

		let query = builder->getQuery();

		/**
		 * Check for bind parameters
		 */
		if fetch bindParams, params["bind"] {
			fetch bindTypes, params["bindTypes"];
		} else {
			let bindTypes = null;
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
	public static function findFirst(parameters = null) -> <Model>
	{
		var params, builder, query, bindParams, bindTypes, cache, resultset, hydration, dependencyInjector, manager;
		let dependencyInjector = \Phalcon\Di::getDefault();
		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

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
		let builder = manager->createBuilder(params);
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
	 * Create a criteria for a specific model
	 */
	public static function query(<DiInterface> dependencyInjector = null) -> <Criteria>
	{
		var criteria;

		/**
		 * Use the global dependency injector if there is no one defined
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault();
		}

		/**
		 * Gets Criteria instance from DI container
		 */
		if dependencyInjector instanceof DiInterface {
			let criteria = <CriteriaInterface> dependencyInjector->get("Phalcon\\Mvc\\Model\\Criteria");
		} else {
			let criteria = new Criteria();
			criteria->setDI(dependencyInjector);
		}

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
	protected function _exists(<MetadataInterface> metaData, <AdapterInterface> connection, var table = null) -> boolean
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
						throw new Exception("Column '" . field . "' isn't part of the column map");
					}
				} else {
					let attributeField = field;
				}

				/**
				 * If the primary key attribute is set append it to the conditions
				 */
				let value = null;
				if fetch value, this->{attributeField} {

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
			let this->_dirtyState = self::DIRTY_STATE_PERSISTENT;
			return true;
		} else {
			let this->_dirtyState = self::DIRTY_STATE_TRANSIENT;
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
	protected static function _groupResult(string! functionName, string! alias, var parameters) -> <ResultsetInterface>
	{
		var params, distinctColumn, groupColumn, columns,
			bindParams, bindTypes, resultset, cache, firstRow, groupColumns,
			builder, query, dependencyInjector, manager;
		let dependencyInjector = \Phalcon\Di::getDefault();
		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

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
		let builder = manager->createBuilder(params);
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
		 * Pass the cache options to the query
		 */
		if fetch cache, params["cache"] {
			query->cache(cache);
		}

		/**
		 * Execute the query
		 */
		let resultset = query->execute(bindParams, bindTypes);

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
	public static function count(var parameters = null)
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
	public static function sum(var parameters = null)
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
	public static function maximum(var parameters = null)
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
	public static function minimum(parameters = null)
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
	public static function average(var parameters = null)
	{
		return self::_groupResult("AVG", "average", parameters);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 */
	public function fireEvent(string! eventName) -> boolean
	{
		/**
		 * Check if there is a method with the same name of the event
		 */
		if method_exists(this, eventName) {
			this->{eventName}();
		}

		/**
		 * Send a notification to the events manager
		 */
		return (<ManagerInterface> this->_modelsManager)->notifyEvent(eventName, this);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 */
	public function fireEventCancel(string! eventName) -> boolean
	{
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
		if (<ManagerInterface> this->_modelsManager)->notifyEvent(eventName, this) === false {
			return false;
		}

		return true;
	}

	/**
	 * Cancel the current operation
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
	 * class Robots extends \Phalcon\Mvc\Model
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
	 */
	public function appendMessage(<MessageInterface> message) -> <Model>
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
	 *class Subscriptors extends \Phalcon\Mvc\Model
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
	 */
	protected function validate(<Model\ValidatorInterface> validator) -> <Model>
	{
		var message;

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
	 *class Subscriptors extends \Phalcon\Mvc\Model
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
	 */
	public function validationHasFailed() -> boolean
	{
		var errorMessages;
		let errorMessages = this->_errorMessages;
		if typeof errorMessages == "array" {
			return count(errorMessages) > 0;
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
	 */
	public function getMessages(var filter = null) -> <MessageInterface[]>
	{
		var filtered, message;

		if typeof filter == "string" && !empty filter {
			let filtered = [];
			for message in this->_errorMessages {
				if message->getField() == filter {
					let filtered[] = message;
				}
			}
			return filtered;
		}
		return this->_errorMessages;
	}

	/**
	 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
	 * to verify that inserted/updated values are present in the related entity
	 */
	protected function _checkForeignKeysRestrict() -> boolean
	{
		var manager, belongsTo, foreignKey, relation, conditions,
			position, bindParams, extraConditions, message, fields,
			referencedFields, field, referencedModel, value, allowNulls;
		int action, numberNull;
		boolean error, validateWithNulls = false;

		/**
		 * Get the models manager
		 */
		let manager = <ManagerInterface> this->_modelsManager;

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
					if action == Relation::ACTION_RESTRICT {

						/**
						 * Load the referenced model if needed
						 */
						let referencedModel = manager->load(relation->getReferencedModel());

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
								fetch value, this->{field};
								let conditions[] = "[" . referencedFields[position] . "] = ?" . position,
									bindParams[] = value;
								if typeof value == "null" {
									let numberNull++;
								}
							}

							let validateWithNulls = numberNull == count(fields);

						} else {

							fetch value, this->{fields};
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
						if !validateWithNulls && !referencedModel->count([join(" AND ", conditions), "bind": bindParams]) {

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
							this->appendMessage(new Message(message, fields, "ConstraintViolation"));
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
	 */
	protected function _checkForeignKeysReverseCascade() -> boolean
	{
		var manager, relations, relation, foreignKey,
			resultset, conditions, bindParams, referencedModel,
			referencedFields, fields, field, position, value,
			extraConditions;
		int action;

		/**
		 * Get the models manager
		 */
		let manager = <ManagerInterface> this->_modelsManager;

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
					if action == Relation::ACTION_CASCADE {

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
				}
			}

		}

		return true;
	}

	/**
	 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
	 */
	protected function _checkForeignKeysReverseRestrict() -> boolean
	{
		boolean error;
		var manager, relations, foreignKey, relation,
			relationClass, referencedModel, fields, referencedFields,
			conditions, bindParams,position, field,
			value, extraConditions, message;
		int action;

		/**
		 * Get the models manager
		 */
		let manager = <ManagerInterface> this->_modelsManager;

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
					if action == Relation::ACTION_RESTRICT {

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
							this->appendMessage(new Message(message, fields, "ConstraintViolation"));
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
	 */
	protected function _preSave(<MetadataInterface> metaData, boolean exists, var identityField) -> boolean
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
			if this->fireEventCancel("beforeValidation") === false {
				return false;
			}

			/**
			 * Call the specific beforeValidation event for the current action
			 */
			if !exists {
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
					let defaultValues = metaData->getDefaultValues(this);
				}

				/**
				 * Get string attributes that allow empty strings as defaults
				 */
				let emptyStringValues = metaData->getEmptyStringAttributes(this);

				let error = false;
				for field in notNull {

					/**
					 * We don't check fields that must be omitted
					 */
					if !isset automaticAttributes[field] {

						let isNull = false;

						if typeof columnMap == "array" {
							if !fetch attributeField, columnMap[field] {
								throw new Exception("Column '" . field . "' isn't part of the column map");
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
									if isset emptyStringValues[field] {
										if value === null {
											let isNull = true;
										}
									} else {
										if value === null || value === "" {
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
							 * A implicit PresenceOf message is created
							 */
							let this->_errorMessages[] = new Message(attributeField . " is required", attributeField, "PresenceOf"),
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
	 */
	protected function _postSave(boolean success, boolean exists) -> boolean
	{
		if success === true {
			if exists {
				this->fireEvent("afterUpdate");
			} else {
				this->fireEvent("afterCreate");
			}
		}

		return success;
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
	protected function _doLowInsert(<MetadataInterface> metaData, <AdapterInterface> connection,
		table, identityField) -> boolean
	{
		var bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes,
			field, columnMap, value, attributeField, success, bindType,
			defaultValue, sequenceName, defaultValues, source, schema;
		boolean useExplicitIdentity;

		let bindSkip = Column::BIND_SKIP;

		let fields = [],
			values = [],
			bindTypes = [];

		let attributes = metaData->getAttributes(this),
			bindDataTypes = metaData->getBindTypes(this),
			automaticAttributes = metaData->getAutomaticCreateAttributes(this),
			defaultValues = metaData->getDefaultValues(this);

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
						throw new Exception("Column '" . field . "' isn't part of the column map");
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

						if value === null && isset defaultValues[field] {
							let value = defaultValues[field];
						}

						/**
						 * Every column must have a bind data type defined
						 */
						if !fetch bindType, bindDataTypes[field] {
							throw new Exception("Column '" . field . "' have not defined a bind data type");
						}

						let values[] = value, bindTypes[] = bindType;
					} else {

						let bindTypes[] = bindSkip;

						fetch value, defaultValues[field];
						let values[] = value;
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
					throw new Exception("Identity column '" . identityField . "' isn't part of the column map");
				}
			} else {
				let attributeField = identityField;
			}

			/**
			 * Check if the developer set an explicit value for the column
			 */
			if fetch value, this->{attributeField} {

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
				if method_exists(this, "getSequenceName") {
					let sequenceName = this->{"getSequenceName"}();
				} else {

					let source = this->getSource(),
						schema = this->getSchema();

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
	protected function _doLowUpdate(<MetaDataInterface> metaData, <AdapterInterface> connection, var table) -> boolean
	{
		var bindSkip, fields, values, bindTypes, manager, bindDataTypes, field,
			automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes,
			snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType;
		boolean useDynamicUpdate, changed;

		let bindSkip = Column::BIND_SKIP,
			fields = [],
			values = [],
			bindTypes = [],
			manager = <ManagerInterface> this->_modelsManager;

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
									switch (bindType) {
										case Column::TYPE_BOOLEAN:
											let changed = (boolean)snapshotValue !== (boolean)value;
											break;
										case Column::TYPE_INTEGER:
											let changed = (int)snapshotValue !== (int)value;
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
											let changed = (string)snapshotValue !== (string)value;
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
	protected function _preSaveRelatedRecords(<AdapterInterface> connection, related) -> boolean
	{
		var className, manager, type, relation, columns, referencedFields,
			referencedModel, message, nesting, name, record;

		let nesting = false;

		/**
		 * Start an implicit transaction
		 */
		connection->begin(nesting);

		let className = get_class(this),
			manager = <ManagerInterface> this->getModelsManager();

		for name, record in related {

			/**
			 * Try to get a relation with the same name
			 */
			let relation = <RelationInterface> manager->getRelationByAlias(className, name);
			if typeof relation == "object" {

				/**
				 * Get the relation type
				 */
				let type = relation->getType();

				/**
				 * Only belongsTo are stored before save the master record
				 */
				if type == Relation::BELONGS_TO {

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
					if !record->save() {

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
	 * @param  Phalcon\Db\AdapterInterface connection
	 * @param  Phalcon\Mvc\ModelInterface[] related
	 * @return boolean
	 */
	protected function _postSaveRelatedRecords(<AdapterInterface> connection, related) -> boolean
	{
		var nesting, className, manager, relation, name, record, message,
			columns, referencedModel, referencedFields, relatedRecords, value,
			recordAfter, intermediateModel, intermediateFields, intermediateValue,
			intermediateModelName, intermediateReferencedFields;
		boolean isThrough;

		let nesting = false,
			className = get_class(this),
			manager = <ManagerInterface> this->getModelsManager();

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

				if !fetch value, this->{columns} {
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

					if isThrough {

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
						let intermediateValue = recordAfter->readAttribute(referencedFields);

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

				}
			} else {
				if typeof record != "array" {
					connection->rollback(nesting);
					throw new Exception("There are no defined relations for the model '" . className . "' using alias '" . name . "'");
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
	public function save(var data = null, var whiteList = null) -> boolean
	{
		var metaData, related, schema, writeConnection, readConnection,
			source, table, identityField, exists, success;

		let metaData = this->getModelsMetaData();

		if typeof data == "array" && count(data) > 0 {
			this->assign(data, null, whiteList);
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
				throw new \Phalcon\Mvc\Model\ValidationFailed(this, this->_errorMessages);
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
			} else {
				/**
				 * Save the post-related records
				 */
				let success = this->_postSaveRelatedRecords(writeConnection, related);
			}
		}

		if success === false {
			this->fireEvent("notSave");
			this->_cancelOperation();
		} else {
			this->fireEvent("afterSave");
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
	public function create(var data = null, var whiteList = null) -> boolean
	{
		var metaData;

		let metaData = this->getModelsMetaData();

		/**
		 * Get the current connection
		 * If the record already exists we must throw an exception
		 */
		if this->_exists(metaData, this->getReadConnection()) {
			let this->_errorMessages = [
				new Message("Record cannot be created because it already exists", null, "InvalidCreateAttempt")
			];
			return false;
		}

		/**
		 * Using save() anyways
		 */
		return this->save(data, whiteList);
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
	public function update(var data = null, var whiteList = null) -> boolean
	{
		var metaData;

		/**
		 * We don't check if the record exists if the record is already checked
		 */
		if this->_dirtyState {

			let metaData = this->getModelsMetaData();

			if this->_exists(metaData, this->getReadConnection()) {
				let this->_errorMessages = [new Message("Record cannot be updated because it does not exist", null, "InvalidUpdateAttempt")];
				return false;
			}
		}

		/**
		 * Call save() anyways
		 */
		return this->save(data, whiteList);
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
			if !fetch value, this->{attributeField} {
				throw new Exception("Cannot delete the record because the primary key attribute: '" . attributeField . "' wasn't set");
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
		let success = writeConnection->delete(table, join(" AND ", conditions), values, bindTypes);

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
	 */
	public function getOperationMade() -> int
	{
		return this->_operationMade;
	}

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh() -> <Model>
	{
		var metaData, readConnection, schema, source, table,
			uniqueKey, tables, uniqueParams, dialect, row, fields, attribute;

		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
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
			if !this->_exists(metaData, readConnection, table) {
				throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
			}

			let uniqueKey = this->_uniqueKey;
		}

		let uniqueParams = this->_uniqueParams;
		if typeof uniqueParams != "array" {
			throw new Exception("The record cannot be refreshed because it does not exist or is deleted");
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
			tables = dialect->select([
				"columns": fields,
				"tables": readConnection->escapeIdentifier(table),
				"where": uniqueKey
			]),
			row = readConnection->fetchOne(tables, \Phalcon\Db::FETCH_ASSOC, uniqueParams, this->_uniqueTypes);

		/**
		 * Get a column map if any
		 * Assign the resulting array to the this object
		 */
		if typeof row == "array" {
			this->assign(row, metaData->getColumnMap(this));
		}

		return this;
	}

	/**
	 * Skips the current operation forcing a success state
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
	 */
	public function readAttribute(string! attribute)
	{
		if !isset this->{attribute} {
			return null;
		}

		return this->{attribute};
	}

	/**
	 * Writes an attribute value by its name
	 *
	 *<code>
	 * 	$robot->writeAttribute('name', 'Rosey');
	 *</code>
	 */
	public function writeAttribute(string! attribute, var value)
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
	 *}
	 *</code>
	 */
	protected function skipAttributes(array! attributes)
	{
		var keysAttributes, metaData, attribute;

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
	 *}
	 *</code>
	 */
	protected function skipAttributesOnCreate(array! attributes) -> void
	{
		var keysAttributes, attribute;

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		this->getModelsMetaData()->setAutomaticCreateAttributes(this, keysAttributes);
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
	 *}
	 *</code>
	 */
	protected function skipAttributesOnUpdate(array! attributes) -> void
	{
		var keysAttributes, attribute;

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		this->getModelsMetaData()->setAutomaticUpdateAttributes(this, keysAttributes);
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
	 *       $this->allowEmptyStringValues(array('name'));
	 *   }
	 *}
	 *</code>
	 */
	protected function allowEmptyStringValues(array! attributes) -> void
	{
		var keysAttributes, attribute;

		let keysAttributes = [];
		for attribute in attributes {
			let keysAttributes[attribute] = null;
		}

		this->getModelsMetaData()->setEmptyStringAttributes(this, keysAttributes);
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
	 *}
	 *</code>
	 */
	protected function hasOne(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasOne(this, fields, referenceModel, referencedFields, options);
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
	 */
	protected function belongsTo(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addBelongsTo(this, fields, referenceModel, referencedFields, options);
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
	 *}
	 *</code>
	 */
	protected function hasMany(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasMany(this, fields, referenceModel, referencedFields, options);
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
	protected function hasManyToMany(var fields, string! intermediateModel, var intermediateFields, var intermediateReferencedFields,
		string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasManyToMany(
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
	 *}
	 *</code>
	 */
	public function addBehavior(<BehaviorInterface> behavior) -> void
	{
		(<ManagerInterface> this->_modelsManager)->addBehavior(this, behavior);
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
	 *}
	 *</code>
	 */
	protected function keepSnapshots(boolean keepSnapshot) -> void
	{
		(<ManagerInterface> this->_modelsManager)->keepSnapshots(this, keepSnapshot);
	}

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array data
	 * @param array columnMap
	 */
	public function setSnapshotData(array! data, columnMap = null)
	{
		var key, value, snapshot, attribute;

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
					throw new Exception("Column '" . key . "' doesn't make part of the column map");
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
	 */
	public function hasSnapshotData() -> boolean
	{
		var snapshot;
		let snapshot = this->_snapshot;

		return typeof snapshot == "array";
	}

	/**
	 * Returns the internal snapshot data
	 */
	public function getSnapshotData() -> array
	{
		return this->_snapshot;
	}

	/**
	 * Check if a specific attribute has changed
	 * This only works if the model is keeping data snapshots
	 *
	 * @param string|array fieldName
	 */
	public function hasChanged(var fieldName = null) -> boolean
	{
		var snapshot, metaData, columnMap, allAttributes, value,
			originalValue, name;

		let snapshot = this->_snapshot;
		if typeof snapshot != "array" {
			throw new Exception("The record doesn't have a valid data snapshot");
		}

		/**
		 * Dirty state must be DIRTY_PERSISTENT to make the checking
		 */
		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Exception("Change checking cannot be performed because the object has not been persisted or is deleted");
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
		if typeof fieldName == "string" {

			/**
			 * We only make this validation over valid fields
			 */
			if typeof columnMap == "array" {
				if !isset columnMap[fieldName] {
					throw new Exception("The field '" . fieldName . "' is not part of the model");
				}
			} else {
				if !isset allAttributes[fieldName] {
					throw new Exception("The field '" . fieldName . "' is not part of the model");
				}
			}

			/**
			 * The field is not part of the model, throw exception
			 */
			if !fetch value, this->{fieldName} {
				throw new Exception("The field '" . fieldName . "' is not defined on the model");
			}

			/**
			 * The field is not part of the data snapshot, throw exception
			 */
			if !fetch originalValue, snapshot[fieldName] {
				throw new Exception("The field '" . fieldName . "' was not found in the snapshot");
			}

			/**
			 * Check if the field has changed
			 */
			return value != originalValue;
		}

		/**
		 * Check every attribute in the model
		 */
		for name, _ in allAttributes {

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
	 */
	public function getChangedFields() -> array
	{
		var metaData, changed, name, snapshot,
			columnMap, allAttributes, value;

		let snapshot = this->_snapshot;
		if typeof snapshot != "array" {
			throw new Exception("The record doesn't have a valid data snapshot");
		}

		/**
		 * Dirty state must be DIRTY_PERSISTENT to make the checking
		 */
		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Exception("Change checking cannot be performed because the object has not been persisted or is deleted");
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

		for name, _ in allAttributes {

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
	 *}
	 *</code>
	 */
	protected function useDynamicUpdate(boolean dynamicUpdate) -> void
	{
		(<ManagerInterface> this->_modelsManager)->useDynamicUpdate(this, dynamicUpdate);
	}

	/**
	 * Returns related records based on defined relations
	 *
	 * @param string alias
	 * @param array arguments
	 * @return Phalcon\Mvc\Model\ResultsetInterface
	 */
	public function getRelated(string alias, arguments = null) -> <ResultsetInterface>
	{
		var relation, className, manager;

		/**
		 * Query the relation by alias
		 */
		let className = get_class(this),
			manager = <ManagerInterface> this->_modelsManager,
			relation = <RelationInterface> manager->getRelationByAlias(className, alias);
		if typeof relation != "object" {
			throw new Exception("There is no defined relations for the model '" . className . "' using alias '" . alias . "'");
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
	protected function _getRelatedRecords(string! modelName, string! method, var arguments)
	{
		var manager, relation, queryMethod, extraArgs;

		let manager = <ManagerInterface> this->_modelsManager;

		let relation = false,
			queryMethod = null;

		/**
		 * Calling find/findFirst if the method starts with "get"
		 */
		if starts_with(method, "get") {
			let relation = <RelationInterface> manager->getRelationByAlias(modelName, substr(method, 3));
		}

		/**
		 * Calling count if the method starts with "count"
		 */
		if typeof relation != "object" {
			if starts_with(method, "count") {
				let queryMethod = "count",
					relation = <RelationInterface> manager->getRelationByAlias(modelName, substr(method, 5));
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
	public function __call(string method, arguments = null)
	{
		var modelName, status, records;

		let modelName = get_class(this);

		/**
		 * Check if there is a default action using the magic getter
		 */
		let records = this->_getRelatedRecords(modelName, method, arguments);
		if records !== null {
			return records;
		}

		/**
		 * Try to find a replacement for the missing method in a behavior/listener
		 */
		let status = (<ManagerInterface> this->_modelsManager)->missingMethod(this, method, arguments);
		if status !== null {
			return status;
		}

		/**
		 * The method doesn't exist throw an exception
		 */
		throw new Exception("The method '" . method . "' doesn't exist on model '" . modelName . "'");
	}

	/**
	 * Handles method calls when a static method is not implemented
	 *
	 * @param	string method
	 * @param	array arguments
	 * @return	mixed
	 */
	public static function __callStatic(string method, arguments = null)
	{
		var extraMethod, type, modelName, value, model,
			attributes, field, extraMethodFirst, metaData;

		let extraMethod = null;

		/**
		 * Check if the method starts with "findFirst"
		 */
		if starts_with(method, "findFirstBy") {
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

		if !extraMethod {
			throw new Exception("The static method '" . method . "' doesn't exist on model '" . modelName . "'");
		}

		if !fetch value, arguments[0] {
			throw new Exception("The static method '" . method . "' requires one argument");
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
					throw new Exception("Cannot resolve attribute '" . extraMethod . "' in the model");
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
		var lowerProperty, related, modelName, manager, lowerKey, relation, referencedModel,
			key, item;

		/**
		 * Values are probably relationships if they are objects
		 */
		if typeof value == "object" {
			if value instanceof ModelInterface {
				let lowerProperty = strtolower(property),
					this->{lowerProperty} = value,
					this->_related[lowerProperty] = value,
					this->_dirtyState = self::DIRTY_STATE_TRANSIENT;
				return value;
			}
		}

		/**
		 * Check if the value is an array
		 */
		if typeof value == "array" {

			let lowerProperty = strtolower(property),
				modelName = get_class(this),
				manager = this->getModelsManager();

			let related = [];
			for key, item in value {
				if typeof item == "object" {
					if item instanceof ModelInterface {
						let related[] = item;
					}
				} else {
					let lowerKey = strtolower(key),
						this->{lowerKey} = item,
						relation = <RelationInterface> manager->getRelationByAlias(modelName, lowerProperty);
						if typeof relation == "object" {
							let referencedModel = manager->load(relation->getReferencedModel());
							referencedModel->writeAttribute(lowerKey, item);
						}
				}
			}

			if count(related) > 0 {
				let this->_related[lowerProperty] = related,
					this->_dirtyState = self::DIRTY_STATE_TRANSIENT;
			}

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
		var modelName, manager, lowerProperty, relation, result, method;

		let modelName = get_class(this),
			manager = this->getModelsManager(),
			lowerProperty = strtolower(property);

		/**
		 * Check if the property is a relationship
		 */
		let relation = <RelationInterface> manager->getRelationByAlias(modelName, lowerProperty);
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
				if result instanceof ModelInterface {
					let this->_related[lowerProperty] = result;
				}
			}

			return result;
		}

		/**
		 * Check if the property has getters
		 */
		let method = "get" . Text::camelize(property);

		if method_exists(this, method) {
			return this->{method}();
		}

		/**
		 * A notice is shown if the property is not defined and it isn't a relationship
		 */
		trigger_error("Access to undefined property " . modelName . "::" . property);
		return null;
	}

	/**
	 * Magic method to check if a property is a valid relation
	 */
	public function __isset(string! property) -> boolean
	{
		var modelName, manager, relation;

		let modelName = get_class(this),
			manager = <ManagerInterface> this->getModelsManager();

		/**
		 * Check if the property is a relationship
		 */
		let relation = <RelationInterface> manager->getRelationByAlias(modelName, property);
		return typeof relation == "object";
	}

	/**
	 * Serializes the object ignoring connections, services, related objects or static properties
	 */
	public function serialize() -> string
	{
		/**
		 * Use the standard serialize function to serialize the array data
		 */
		return serialize(this->toArray());
	}

	/**
	 * Unserializes the object from a serialized string
	 */
	public function unserialize(string! data)
	{
		var attributes, dependencyInjector, manager, key, value;

		let attributes = unserialize(data);
		if typeof attributes == "array" {

			/**
			 * Obtain the default DI
			 */
			let dependencyInjector = Di::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
			}

			/**
			 * Update the dependency injector
			 */
			let this->_dependencyInjector = dependencyInjector;

			/**
			 * Gets the default modelsManager service
			 */
			let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");
			if typeof manager != "object" {
				throw new Exception("The injected service 'modelsManager' is not valid");
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
		}
	}

	/**
	 * Returns a simple representation of the object that can be used with var_dump
	 *
	 *<code>
	 * var_dump($robot->dump());
	 *</code>
	 */
	public function dump() -> array
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
	 * @param array $columns
	 * @return array
	 */
	public function toArray(columns = null) -> array
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
					throw new Exception("Column '" . attribute . "' doesn't make part of the column map");
				}
			} else {
				let attributeField = attribute;
			}

			if typeof columns == "array" {
				if !in_array(attributeField, columns) {
					continue;
				}
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
	 */
	public static function setup(array! options) -> void
	{
		var disableEvents, columnRenaming, notNullValidations,
			exceptionOnFailedSave, phqlLiterals, virtualForeignKeys, lateStateBinding;

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

        /**
         * Enables/Disables late state binding on model hydration
         */
        if fetch lateStateBinding, options["lateStateBinding"] {
            globals_set("orm.late_state_binding", lateStateBinding);
        }
	}

	/**
	 * Reset a model instance data
	 */
	public function reset()
	{
		let this->_uniqueParams = null;
		let this->_snapshot = null;
	}
}
