
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

use Phalcon\Db\AdapterInterface;
use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\MetaDataInterface;

/**
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 */
interface ModelInterface
{

	public static function getRepositoryClass() -> string;

	/**
	 * Sets a transaction related to the Model instance
	 */
	public function setTransaction(<TransactionInterface> transaction) -> <ModelInterface>;

	/**
	 * Returns table name mapped in the model
	 */
	public function getSource() -> string;

	/**
	 * Returns schema name where table mapped is located
	 */
	public function getSchema() -> string;

	/**
	 * Sets both read/write connection services
	 */
	public function setConnectionService(string connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to write data
	 */
	public function setWriteConnectionService(string connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to read data
	 */
	public function setReadConnectionService(string connectionService) -> void;

	/**
	 * Returns DependencyInjection connection service used to read data
	 */
	public function getReadConnectionService() -> string;

	/**
	 * Returns DependencyInjection connection service used to write data
	 */
	public function getWriteConnectionService() -> string;

	/**
	 * Gets internal database connection
	 */
	public function getReadConnection() -> <\Phalcon\Db\AdapterInterface>;

	/**
	 * Gets internal database connection
	 */
	public function getWriteConnection() -> <\Phalcon\Db\AdapterInterface>;

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 */
	public function setDirtyState(int dirtyState) -> <ModelInterface>;

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 */
	public function getDirtyState() -> int;

	/**
	 * Assigns values to a model from an array
	 *
	 * @param array columnMap
	 */
	public function assign(array! data, var dataColumnMap = null, var whiteList = null) -> <ModelInterface>;

	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 * @param \Phalcon\Mvc\Model base
	 * @param array columnMap
	 * @return \Phalcon\Mvc\Model result
	 */
	public static function cloneResultMap(base, array! data, var columnMap, int dirtyState = 0, boolean keepSnapshots = null);

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array columnMap
	 */
	public static function cloneResultMapHydrate(array! data, var columnMap, int hydrationMode);

	/**
	 * Allows to query a set of records that match the specified conditions
	 */
	public static function find(var parameters = null) -> <ResultsetInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * @param array parameters
	 */
	public static function findFirst(parameters = null) -> <ModelInterface>;

	/**
	 * Allows to count how many records match the specified conditions
	 *
	 * @param array parameters
	 * @return int
	 */
	public static function count(parameters = null);

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 */
	public function fireEvent(string! eventName) -> boolean;

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 */
	public function fireEventCancel(string! eventName) -> boolean;

	/**
	 * Cancel the current operation
	 */
	public function cancelOperation();

	/**
	 * Appends a customized message on the validation process
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Clears messages used in the validation process
	 */
	public function clearMessages();

	/**
	 * Check whether validation process has generated any messages
	 */
	public function validationHasFailed() -> boolean;

	/**
	 * Returns array of validation messages
	 */
	public function getMessages() -> <MessageInterface[]>;

	public function setUniqueKey(uniqueKey);

	public function getUniqueKey();

	public function setUniqueParams(uniqueParams);

	public function getUniqueParams();

	public function setUniqueTypes(uniqueTypes);

	public function getUniqueTypes();

	public function resetUniqueParams();

	/**
	 * Sets the type of the latest operation performed by the ORM
	 */
	public function setOperationMade(int operationMade);

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 */
	public function getOperationMade() -> int;

	/**
	 * Skips the current operation forcing a success state
	 */
	public function skipOperation(boolean skip);

	/**
	 * Has the current operation been skipped?
	 */
	public function isSkipped() -> boolean;

	/**
	 * Returns related records based on defined relations
	 *
	 * @param array arguments
	 */
	public function getRelated(string alias, arguments = null) -> <ResultsetInterface>;

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array columnMap
	 */
	public function setSnapshotData(array! data, columnMap = null);

	public function updateSnapshot(newSnapshot, oldSnapshot);
}
