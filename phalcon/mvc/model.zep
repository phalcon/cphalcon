
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

namespace Phalcon\Mvc;

use Phalcon\Di;
use Phalcon\Db\Column;
use Phalcon\Db\RawValue;
use Phalcon\DiInterface;
use Phalcon\Mvc\Model\Message;
use Phalcon\Mvc\Model\ResultInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\ManagerInterface;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\Criteria;
use Phalcon\Db\AdapterInterface;
use Phalcon\Db\DialectInterface;
use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Mvc\Model\Relation;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Mvc\Model\BehaviorInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Model\Message;
use Phalcon\ValidationInterface;
use Phalcon\Validation\Message\Group;
use Phalcon\Mvc\Model\ValidationFailed;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Validation\Message\Group as ValidationMessageGroup;

/**
 * Phalcon\Mvc\Model
 *
 * Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application's business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.
 *
 * <code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if (!$modelsManager->save($robot)) {
 *     echo "Umh, We can store robots: ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
abstract class Model implements EntityInterface, ModelInterface, ResultInterface, InjectionAwareInterface, \Serializable, \JsonSerializable
{

	protected _dependencyInjector;

	protected _modelsManager;

	protected _modelsMetaData;

	protected _errorMessages = [];

	protected _operationMade = 0;

	protected _dirtyState = 1;

	protected _transaction;

	protected _uniqueKey;

	protected _uniqueParams;

	protected _uniqueTypes;

	protected _skipped;

	protected _related;

	protected _snapshot;

	protected _oldSnapshot = [];

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

	public static function getRepositoryClass() -> string
	{
		return "Phalcon\\Mvc\\Model\\Repository";
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

			let dependencyInjector = <DiInterface> this->_dependencyInjector;

			/**
			 * Obtain the models-metadata service from the DI
			 */
			let metaData = <MetaDataInterface> dependencyInjector->getShared("modelsMetadata");
			if typeof metaData != "object" {
				throw new Exception("The injected service 'modelsMetadata' is not valid");
			}

			/**
			 * Update the models-metadata property
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
	 * use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
	 * use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
	 *
	 * try {
	 *     $txManager = new TxManager();
	 *
	 *     $transaction = $txManager->get();
	 *
	 *     $robot = new Robots();
	 *
	 *     $robot->setTransaction($transaction);
	 *
	 *     $robot->name       = "WALL·E";
	 *     $robot->created_at = date("Y-m-d");
	 *
	 *     if (!$modelsManager->save($robot)) {
	 *         $transaction->rollback("Can't save robot");
	 *     }
	 *
	 *     $robotPart = new RobotParts();
	 *
	 *     $robotPart->setTransaction($transaction);
	 *
	 *     $robotPart->type = "head";
	 *
	 *     if (!$modelsManager->save($robotPart)) {
	 *         $transaction->rollback("Robot part cannot be saved");
	 *     }
	 *
	 *     $transaction->commit();
	 * } catch (TxFailed $e) {
	 *     echo "Failed, reason: ", $e->getMessage();
	 * }
	 *</code>
	 */
	public function setTransaction(<TransactionInterface> transaction) -> <Model>
	{
		let this->_transaction = transaction;
		return this;
	}

	/**
	 * Sets the table name to which model should be mapped
	 */
	protected function setSource(string! source) -> <Model>
	{
		(<ManagerInterface> this->_modelsManager)->setModelSource(this, source);
		return this;
	}

	/**
	 * Returns the table name mapped in the model
	 */
	public function getSource() -> string
	{
		return (<ManagerInterface> this->_modelsManager)->getModelSource(this);
	}

	/**
	 * Sets schema name where the mapped table is located
	 */
	protected function setSchema(string! schema) -> <Model>
	{
		return (<ManagerInterface> this->_modelsManager)->setModelSchema(this, schema);
	}

	/**
	 * Returns schema name where the mapped table is located
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
		var transaction;

		let transaction = <TransactionInterface> this->_transaction;
		if typeof transaction == "object" {
			return transaction->getConnection();
		}

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
	 * $robot->assign(
	 *     [
	 *         "type" => "mechanical",
	 *         "name" => "Astro Boy",
	 *         "year" => 1952,
	 *     ]
	 * );
	 *
	 * // Assign by db row, column map needed
	 * $robot->assign(
	 *     $dbRow,
	 *     [
	 *         "db_type" => "type",
	 *         "db_name" => "name",
	 *         "db_year" => "year",
	 *     ]
	 * );
	 *
	 * // Allow assign only name and year
	 * $robot->assign(
	 *     $_POST,
	 *     null,
	 *     [
	 *         "name",
	 *         "year",
	 *     ]
	 * );
	 *
	 * // By default assign method will use setters if exist, you can disable it by using ini_set to directly use properties
	 *
	 * ini_set("phalcon.orm.disable_assign_setters", true);
	 *
	 * $robot->assign(
	 *     $_POST,
	 *     null,
	 *     [
	 *         "name",
	 *         "year",
	 *     ]
	 * );
	 * </code>
	 *
	 * @param array dataColumnMap array to transform keys of data to another
	 * @param array whiteList
	 */
	public function assign(array! data, var dataColumnMap = null, var whiteList = null) -> <Model>
	{
		var key, keyMapped, value, attribute, attributeField, metaData, columnMap, dataMapped, disableAssignSetters;

		let disableAssignSetters = globals_get("orm.disable_assign_setters");

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
					if !globals_get("orm.ignore_unknown_columns") {
						throw new Exception("Column '" . attribute. "' doesn\'t make part of the column map");
					} else {
						continue;
					}
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
				if disableAssignSetters || !this->_possibleSetter(attributeField, value) {
					let this->{attributeField} = value;
				}
			}
		}

		return this;
	}

	/**
	 * Assigns values to a model from an array, returning a new model.
	 *
	 *<code>
	 * $robot = \Phalcon\Mvc\Model::cloneResultMap(
	 *     new Robots(),
	 *     [
	 *         "type" => "mechanical",
	 *         "name" => "Astro Boy",
	 *         "year" => 1952,
	 *     ]
	 * );
	 *</code>
	 *
	 * @param \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row base
	 * @param array columnMap
	 */
	public static function cloneResultMap(var base, array! data, var columnMap, int dirtyState = 0, boolean keepSnapshots = null) -> <Model>
	{
		var instance, attribute, key, value, castValue, attributeName;

		let instance = clone base;

		// Change the dirty state to persistent
		instance->setDirtyState(dirtyState);

		for key, value in data {

			if typeof key == "string" {

				// Only string keys in the data are valid
				if typeof columnMap != "array" {
					let instance->{key} = value;
					continue;
				}

				// Every field must be part of the column map
				if !fetch attribute, columnMap[key] {
					if !globals_get("orm.ignore_unknown_columns") {
						throw new Exception("Column '" . key . "' doesn't make part of the column map");
					} else {
						continue;
					}
				}

				if typeof attribute != "array" {
					let instance->{attribute} = value;
					continue;
				}

				if value != "" && value !== null {
					switch attribute[1] {

						case Column::TYPE_INTEGER:
							let castValue = intval(value, 10);
							break;

						case Column::TYPE_DOUBLE:
						case Column::TYPE_DECIMAL:
						case Column::TYPE_FLOAT:
							let castValue = doubleval(value);
							break;

						case Column::TYPE_BOOLEAN:
							let castValue = (boolean) value;
							break;

						default:
							let castValue = value;
							break;
					}
				} else {
					switch attribute[1] {

						case Column::TYPE_INTEGER:
						case Column::TYPE_DOUBLE:
						case Column::TYPE_DECIMAL:
						case Column::TYPE_FLOAT:
						case Column::TYPE_BOOLEAN:
							let castValue = null;
							break;

						default:
							let castValue = value;
							break;
					}
				}

				let attributeName = attribute[0],
					instance->{attributeName} = castValue;
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
		if method_exists(instance, "fireEvent") {
			instance->{"fireEvent"}("afterFetch");
		}

		return instance;
	}

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array columnMap
	 * @return mixed
	 */
	public static function cloneResultMapHydrate(array! data, var columnMap, int hydrationMode)
	{
		var hydrateArray, hydrateObject, key, value, attribute, attributeName;

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
			if typeof key != "string" {
				continue;
			}

			if typeof columnMap == "array" {

				/**
				 * Every field must be part of the column map
				 */
				if !fetch attribute, columnMap[key] {
					if !globals_get("orm.ignore_unknown_columns") {
						throw new Exception("Column '" . key . "' doesn't make part of the column map");
					} else {
						continue;
					}
				}

				/**
				 * Attribute can store info about his type
				 */
				if (typeof attribute == "array") {
					let attributeName = attribute[0];
				} else {
					let attributeName = attribute;
				}

				if hydrationMode == Resultset::HYDRATE_ARRAYS {
					let hydrateArray[attributeName] = value;
				} else {
					let hydrateObject->{attributeName} = value;
				}
			} else {
				if hydrationMode == Resultset::HYDRATE_ARRAYS {
					let hydrateArray[key] = value;
				} else {
					let hydrateObject->{key} = value;
				}
			}
		}

		if hydrationMode == Resultset::HYDRATE_ARRAYS {
			return hydrateArray;
		}

		return hydrateObject;
	}

	/**
	 * Query for a set of records that match the specified conditions
	 *
	 * @deprecated
	 */
	public static function find(var parameters = null) -> <ResultsetInterface>
	{
		var dependencyInjector, manager, repository;

		let dependencyInjector = Di::getDefault();

		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

		let repository = manager->getRepository(get_called_class());

		return repository->find(parameters);
	}

	/**
	 * Query the first record that matches the specified conditions
	 *
	 * @param string|array parameters
	 *
	 * @deprecated
	 */
	public static function findFirst(var parameters = null) -> <Model>
	{
		var dependencyInjector, manager, repository;

		let dependencyInjector = Di::getDefault();

		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

		let repository = manager->getRepository(get_called_class());

		return repository->findFirst(parameters);
	}

	/**
	 * Counts how many records match the specified conditions
	 *
	 * @param array parameters
	 *
	 * @deprecated
	 */
	public static function count(var parameters = null)
	{
		var dependencyInjector, manager, repository;

		let dependencyInjector = Di::getDefault();

		let manager = <ManagerInterface> dependencyInjector->getShared("modelsManager");

		let repository = manager->getRepository(get_called_class());

		return repository->count(parameters);
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
	public function cancelOperation()
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
	 * use Phalcon\Mvc\Model;
	 * use Phalcon\Mvc\Model\Message as Message;
	 *
	 * class Robots extends Model
	 * {
	 *     public function beforeSave()
	 *     {
	 *         if ($this->name === "Peter") {
	 *             $message = new Message(
	 *                 "Sorry, but a robot cannot be named Peter"
	 *             );
	 *
	 *             $this->appendMessage($message);
	 *         }
	 *     }
	 * }
	 * </code>
	 */
	public function appendMessage(<MessageInterface> message) -> <Model>
	{
		let this->_errorMessages[] = message;
		return this;
	}

	/**
	 * Clears messages used in the validation process
	 */
	public function clearMessages() -> <Model>
	{
		let this->_errorMessages = [];
		return this;
	}

	/**
	 * Executes validators on every validation call
	 *
	 *<code>
	 * use Phalcon\Mvc\Model;
	 * use Phalcon\Validation;
	 * use Phalcon\Validation\Validator\ExclusionIn;
	 *
	 * class Subscriptors extends Model
	 * {
	 *     public function validation()
	 *     {
	 *         $validator = new Validation();
	 *
	 *         $validator->add(
	 *             "status",
	 *             new ExclusionIn(
	 *                 [
	 *                     "domain" => [
	 *                         "A",
	 *                         "I",
	 *                     ],
	 *                 ]
	 *             )
	 *         );
	 *
	 *         return $this->validate($validator);
	 *     }
	 * }
	 *</code>
	 */
	protected function validate(<ValidationInterface> validator) -> boolean
	{
		var messages, message;

		let messages = validator->validate(null, this);

		// Call the validation, if it returns not the boolean
		// we append the messages to the current object
		if typeof messages == "boolean" {
			return messages;
		}

		for message in iterator(messages) {
			this->appendMessage(
				new Message(
					message->getMessage(),
					message->getField(),
					message->getType(),
					null,
					message->getCode()
				)
			);
		}

		// If there is a message, it returns false otherwise true
		return !count(messages);
	}

	/**
	 * Check whether validation process has generated any messages
	 *
	 *<code>
	 * use Phalcon\Mvc\Model;
	 * use Phalcon\Validation;
	 * use Phalcon\Validation\Validator\ExclusionIn;
	 *
	 * class Subscriptors extends Model
	 * {
	 *     public function validation()
	 *     {
	 *         $validator = new Validation();
	 *
	 *         $validator->validate(
	 *             "status",
	 *             new ExclusionIn(
	 *                 [
	 *                     "domain" => [
	 *                         "A",
	 *                         "I",
	 *                     ],
	 *                 ]
	 *             )
	 *         );
	 *
	 *         return $this->validate($validator);
	 *     }
	 * }
	 *</code>
	 */
	public function validationHasFailed() -> boolean
	{
		return count(this->_errorMessages) > 0;
	}

	/**
	 * Returns array of validation messages
	 *
	 *<code>
	 * $robot = new Robots();
	 *
	 * $robot->type = "mechanical";
	 * $robot->name = "Astro Boy";
	 * $robot->year = 1952;
	 *
	 * if (!$modelsManager->save($robot)) {
	 *     echo "Umh, We can't store robots right now ";
	 *
	 *     $messages = $robot->getMessages();
	 *
	 *     foreach ($messages as $message) {
	 *         echo $message;
	 *     }
	 * } else {
	 *     echo "Great, a new robot was saved successfully!";
	 * }
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

	public function updateSnapshot(newSnapshot, oldSnapshot)
	{
		let this->_snapshot    = newSnapshot;
		let this->_oldSnapshot = oldSnapshot;
	}

	public function setUniqueKey(uniqueKey)
	{
		let this->_uniqueKey = uniqueKey;
	}

	public function getUniqueKey()
	{
		return this->_uniqueKey;
	}

	public function setUniqueParams(uniqueParams)
	{
		let this->_uniqueParams = uniqueParams;
	}

	public function getUniqueParams()
	{
		return this->_uniqueParams;
	}

	public function setUniqueTypes(uniqueTypes)
	{
		let this->_uniqueTypes = uniqueTypes;
	}

	public function getUniqueTypes()
	{
		return this->_uniqueTypes;
	}

	public function resetUniqueParams()
	{
		let this->_uniqueParams = null;
	}

	/**
	 * Sets the type of the latest operation performed by the ORM
	 */
	public function setOperationMade(int operationMade) -> <Model>
	{
		let this->_operationMade = operationMade;
		return this;
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
	 * Skips the current operation forcing a success state
	 */
	public function skipOperation(boolean skip)
	{
		let this->_skipped = skip;
	}

	/**
	 * Has the current operation been skipped?
	 */
	public function isSkipped() -> boolean
	{
		return this->_skipped;
	}

	/**
	 * Reads an attribute value by its name
	 *
	 * <code>
	 * echo $robot->readAttribute("name");
	 * </code>
	 */
	public function readAttribute(string! attribute) -> var | null
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
	 * $robot->writeAttribute("name", "Rosey");
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
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->skipAttributes(
	 *             [
	 *                 "price",
	 *             ]
	 *         );
	 *     }
	 * }
	 *</code>
	 */
	protected function skipAttributes(array! attributes)
	{
		this->skipAttributesOnCreate(attributes);
		this->skipAttributesOnUpdate(attributes);
	}

	/**
	 * Sets a list of attributes that must be skipped from the
	 * generated INSERT statement
	 *
	 *<code>
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->skipAttributesOnCreate(
	 *             [
	 *                 "created_at",
	 *             ]
	 *         );
	 *     }
	 * }
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
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->skipAttributesOnUpdate(
	 *             [
	 *                 "modified_in",
	 *             ]
	 *         );
	 *     }
	 * }
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
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->allowEmptyStringValues(
	 *             [
	 *                 "name",
	 *             ]
	 *         );
	 *     }
	 * }
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
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->hasOne("id", RobotsDescription::class, "robots_id");
	 *     }
	 * }
	 *</code>
	 *
	 * @deprecated
	 */
	protected function hasOne(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasOne(get_called_class(), fields, referenceModel, referencedFields, options);
	}

	/**
	 * Setup a reverse 1-1 or n-1 relation between two models
	 *
	 *<code>
	 *
	 * class RobotsParts extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->belongsTo("robots_id", Robots::class, "id");
	 *     }
	 * }
	 *</code>
	 *
	 * @deprecated
	 */
	protected function belongsTo(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addBelongsTo(
			get_called_class(),
			fields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Setup a 1-n relation between two models
	 *
	 *<code>
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->hasMany("id", RobotsParts::class, "robots_id");
	 *     }
	 * }
	 *</code>
	 *
	 * @deprecated
	 */
	protected function hasMany(var fields, string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasMany(
			get_called_class(),
			fields,
			referenceModel,
			referencedFields,
			options
		);
	}

	/**
	 * Setup an n-n relation between two models, through an intermediate relation
	 *
	 *<code>
	 *
	 * class Robots extends \Phalcon\Mvc\Model
	 * {
	 *     public function initialize()
	 *     {
	 *         // Setup a many-to-many relation to Parts through RobotsParts
	 *         $this->hasManyToMany(
	 *             "id",
	 *             RobotsParts::class,
	 *             "robots_id",
	 *             "parts_id",
	 *             Parts::class,
	 *             "id",
	 *         );
	 *     }
	 * }
	 *</code>
	 *
	 * @param	string|array fields
	 * @param	string|array intermediateFields
	 * @param	string|array intermediateReferencedFields
	 * @param   string|array referencedFields
	 * @param   array options
	 *
	 * @deprecated
	 */
	protected function hasManyToMany(var fields, string! intermediateModel, var intermediateFields, var intermediateReferencedFields,
		string! referenceModel, var referencedFields, options = null) -> <Relation>
	{
		return (<ManagerInterface> this->_modelsManager)->addHasManyToMany(
			get_called_class(),
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
	 *
	 * use Phalcon\Mvc\Model;
	 * use Phalcon\Mvc\Model\Behavior\Timestampable;
	 *
	 * class Robots extends Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->addBehavior(
	 *             new Timestampable(
	 *                [
	 *                    "onCreate" => [
	 *                         "field"  => "created_at",
	 *                         "format" => "Y-m-d",
	 * 	                   ],
	 *                 ]
	 *             )
	 *         );
	 *     }
	 * }
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
	 *
	 * use Phalcon\Mvc\Model;
	 *
	 * class Robots extends Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->keepSnapshots(true);
	 *     }
	 * }
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
					if !globals_get("orm.ignore_unknown_columns") {
						throw new Exception("Column '" . key . "' doesn't make part of the column map");
					} else {
						continue;
					}
				}

				if typeof attribute == "array" {
					if !fetch attribute, attribute[0] {
						if !globals_get("orm.ignore_unknown_columns") {
							throw new Exception("Column '" . key . "' doesn't make part of the column map");
						} else {
							continue;
						}
					}
				}

				let snapshot[attribute] = value;
			}
		} else {
			let snapshot = data;
		}

		let this->_oldSnapshot = snapshot;
		let this->_snapshot = snapshot;
	}

	/**
	 * Checks if the object has internal snapshot data
	 */
	public function hasSnapshotData() -> boolean
	{
		return typeof this->_snapshot == "array";
	}

	/**
	 * Returns the internal snapshot data
	 */
	public function getSnapshotData() -> array
	{
		return this->_snapshot;
	}

	/**
	 * Returns the internal old snapshot data
	 */
	public function getOldSnapshotData() -> array
	{
		return this->_oldSnapshot;
	}

	/**
	 * Check if a specific attribute has changed
	 * This only works if the model is keeping data snapshots
	 *
	 *<code>
	 * $robot = new Robots();
	 *
	 * $robot->type = "mechanical";
	 * $robot->name = "Astro Boy";
	 * $robot->year = 1952;
	 *
	 * $modelsManager->create($robot);
	 * $robot->type = "hydraulic";
	 * $hasChanged = $robot->hasChanged("type"); // returns true
	 * $hasChanged = $robot->hasChanged(["type", "name"]); // returns true
	 * $hasChanged = $robot->hasChanged(["type", "name", true]); // returns false
	 *</code>
	 *
	 * @param string|array fieldName
	 */
	public function hasChanged(var fieldName = null, boolean allFields = false) -> boolean
	{
		var changedFields;

		let changedFields = this->getChangedFields();

		/**
		 * If a field was specified we only check it
		 */
		if typeof fieldName == "string" {
			return in_array(fieldName, changedFields);
		} elseif typeof fieldName == "array" {
			if allFields {
				return array_intersect(fieldName, changedFields) == fieldName;
			}

			return count(array_intersect(fieldName, changedFields)) > 0;
		}

		return count(changedFields) > 0;
	}

	/**
	 * Check if a specific attribute was updated
	 * This only works if the model is keeping data snapshots
	 *
	 * @param string|array fieldName
	 */
	public function hasUpdated(var fieldName = null, boolean allFields = false) -> boolean
	{
		var updatedFields;

		let updatedFields = this->getUpdatedFields();

		/**
		 * If a field was specified we only check it
		 */
		if typeof fieldName == "string" {
			return in_array(fieldName, updatedFields);
		} elseif typeof fieldName == "array" {
			if allFields {
				return array_intersect(fieldName, updatedFields) == fieldName;
			}

			return count(array_intersect(fieldName, updatedFields)) > 0;
		}

		return count(updatedFields) > 0;
	}

	/**
	 * Returns a list of changed values.
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * $robots = $robotsRepository->findFirst();
	 * print_r($robots->getChangedFields()); // []
	 *
	 * $robots->deleted = 'Y';
	 *
	 * $robots->getChangedFields();
	 * print_r($robots->getChangedFields()); // ["deleted"]
	 * </code>
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
			if value !== snapshot[name] {
				let changed[] = name;
				continue;
			}
		}

		return changed;
	}

	/**
	 * Returns a list of updated values.
	 *
	 * <code>
	 * $robotsRepository = $modelsManager->getRepository(Robots::class);
	 *
	 * $robots = $robotsRepository->findFirst();
	 * print_r($robots->getChangedFields()); // []
	 *
	 * $robots->deleted = 'Y';
	 *
	 * $robots->getChangedFields();
	 * print_r($robots->getChangedFields()); // ["deleted"]
	 * $modelsManager->save($robots);
	 * print_r($robots->getChangedFields()); // []
	 * print_r($robots->getUpdatedFields()); // ["deleted"]
	 * </code>
	 */
	public function getUpdatedFields()
	{
		var updated, name, snapshot,
			oldSnapshot, value;

		let snapshot = this->_snapshot;
		let oldSnapshot = this->_oldSnapshot;

		if !globals_get("orm.update_snapshot_on_save") {
			throw new Exception("Update snapshot on save must be enabled for this method to work properly");
		}

		if typeof snapshot != "array" {
			throw new Exception("The record doesn't have a valid data snapshot");
		}

		/**
		 * Dirty state must be DIRTY_PERSISTENT to make the checking
		 */
		if this->_dirtyState != self::DIRTY_STATE_PERSISTENT {
			throw new Exception("Change checking cannot be performed because the object has not been persisted or is deleted");
		}

		let updated = [];

		for name, value in snapshot {
			/**
			 * If some attribute is not present in the oldSnapshot, we assume the record as changed
			 */
			if !isset oldSnapshot[name] {
				let updated[] = name;
				continue;
			}

			if value !== oldSnapshot[name] {
				let updated[] = name;
				continue;
			}
		}

		return updated;
	}

	/**
	 * Sets if a model must use dynamic update instead of the all-field update
	 *
	 *<code>
	 *
	 * use Phalcon\Mvc\Model;
	 *
	 * class Robots extends Model
	 * {
	 *     public function initialize()
	 *     {
	 *         $this->useDynamicUpdate(true);
	 *     }
	 * }
	 *</code>
	 */
	protected function useDynamicUpdate(boolean dynamicUpdate) -> void
	{
		(<ManagerInterface> this->_modelsManager)->useDynamicUpdate(this, dynamicUpdate);
	}

	/**
	 * Returns related records based on defined relations
	 *
	 * @param array arguments
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
		return manager->getRelationRecords(relation, null, this, arguments);
	}

	public function getRelatedProperty()
	{
		return this->_related;
	}

	/**
	 * Returns related records defined relations depending on the method name
	 *
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
		elseif starts_with(method, "count") {
			let queryMethod = "count",
				relation = <RelationInterface> manager->getRelationByAlias(modelName, substr(method, 5));
		}

		/**
		 * If the relation was found perform the query via the models manager
		 */
		if typeof relation != "object" {
			return null;
		}

		fetch extraArgs, arguments[0];

		return manager->getRelationRecords(
			relation,
			queryMethod,
			this,
			extraArgs
		);
	}

	/**
	 * Handles method calls when a method is not implemented
	 *
	 * @return	mixed
	 */
	public function __call(string method, array arguments)
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
	 * Magic method to assign values to the the model
	 *
	 * @param mixed value
	 */
	public function __set(string property, value)
	{
		var lowerProperty, related, modelName, manager, lowerKey,
			relation, referencedModel, key, item, dirtyState;

		/**
		 * Values are probably relationships if they are objects
		 */
		if typeof value == "object" {
			if value instanceof ModelInterface {
				let dirtyState = this->_dirtyState;
				if (value->getDirtyState() != dirtyState) {
					let dirtyState = self::DIRTY_STATE_TRANSIENT;
				}
				let lowerProperty = strtolower(property),
					this->{lowerProperty} = value,
					this->_related[lowerProperty] = value,
					this->_dirtyState = dirtyState;
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

		// Use possible setter.
		if this->_possibleSetter(property, value) {
			return value;
		}

		// Throw an exception if there is an attempt to set a non-public property.
		if property_exists(this, property) {
			let manager = this->getModelsManager();
			if !manager->isVisibleModelProperty(this, property) {
				throw new Exception("Property '" . property . "' does not have a setter.");
			}
		}

		let this->{property} = value;

		return value;
	}

	/**
	 * Check for, and attempt to use, possible setter.
	 */
	protected final function _possibleSetter(string property, var value) -> boolean
	{
		var possibleSetter;

		let possibleSetter = "set" . camelize(property);
		if method_exists(this, possibleSetter) {
			this->{possibleSetter}(value);
			return true;
		}
		return false;
	}

	/**
	 * Magic method to get related records using the relation alias as a property
	 *
	 * @return \Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
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

			/*
			 Not fetch a relation if it is on CamelCase
			 */
			if isset this->{lowerProperty} && typeof this->{lowerProperty} == "object" {
				return this->{lowerProperty};
			}
			/**
			 * Get the related records
			 */
			let result = manager->getRelationRecords(relation, null, this, null);

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
		let method = "get" . camelize(property);

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
		var attributes, snapshot, manager;

		let attributes = this->toArray(),
			manager = <ManagerInterface> this->getModelsManager();

		if manager->isKeepingSnapshots(this) {
			let snapshot = this->_snapshot;
			/**
			 * If attributes is not the same as snapshot then save snapshot too
			 */
			if snapshot != null && attributes != snapshot {
				return serialize(["_attributes": attributes, "_snapshot": snapshot]);
			}
		}

		return serialize(attributes);
	}

	/**
	 * Unserializes the object from a serialized string
	 */
	public function unserialize(string! data)
	{
		var attributes, dependencyInjector, manager, key, value, snapshot;

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
			if manager->isKeepingSnapshots(this) {
				if fetch snapshot, attributes["_snapshot"] {
					let this->_snapshot = snapshot;
					let attributes = attributes["_attributes"];
				}
				else {
					let this->_snapshot = attributes;
				}
			}

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
	 * var_dump(
	 *     $robot->dump()
	 * );
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
	 * print_r(
	 *     $robot->toArray()
	 * );
	 *</code>
	 *
	 * @param array $columns
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
					if !globals_get("orm.ignore_unknown_columns") {
						throw new Exception("Column '" . attribute . "' doesn't make part of the column map");
					} else {
						continue;
					}
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
	* Serializes the object for json_encode
	*
	*<code>
	* echo json_encode($robot);
	*</code>
	*/
	public function jsonSerialize() -> array
	{
		return this->toArray();
	}

	/**
	 * Enables/disables options in the ORM
	 */
	public static function setup(array! options) -> void
	{
		var disableEvents, columnRenaming, notNullValidations,
			exceptionOnFailedSave, phqlLiterals, virtualForeignKeys,
			lateStateBinding, castOnHydrate, ignoreUnknownColumns,
			updateSnapshotOnSave, disableAssignSetters;

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

		/**
		 * Enables/Disables automatic cast to original types on hydration
		 */
		if fetch castOnHydrate, options["castOnHydrate"] {
			globals_set("orm.cast_on_hydrate", castOnHydrate);
		}

		/**
		 * Allows to ignore unknown columns when hydrating objects
		 */
		if fetch ignoreUnknownColumns, options["ignoreUnknownColumns"] {
			globals_set("orm.ignore_unknown_columns", ignoreUnknownColumns);
		}

		if fetch updateSnapshotOnSave, options["updateSnapshotOnSave"] {
			globals_set("orm.update_snapshot_on_save", updateSnapshotOnSave);
		}

		if fetch disableAssignSetters, options["disableAssignSetters"] {
			globals_set("orm.disable_assign_setters", disableAssignSetters);
		}
	}
}
