
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\DiInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\Model\MessageInterface;

/**
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 */
interface ModelInterface
{

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
	public function setConnectionService(string! connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to write data
	 */
	public function setWriteConnectionService(string! connectionService) -> void;

	/**
	 * Sets the DependencyInjection connection service used to read data
	 */
	public function setReadConnectionService(string! connectionService) -> void;

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
	 */
	public function assign(array! data, array dataColumnMap = null, array whiteList = null) -> <ModelInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 */
	public function findAll(var parameters = null) -> <\Phalcon\Mvc\Model\ResultsetInterface>;
	
	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 * @param Phalcon\Mvc\Model base
	 * @param array data
	 * @param array columnMap
	 * @param int dirtyState
	 * @param boolean keepSnapshots
	 * @return Phalcon\Mvc\Model result
	 */
	public static function cloneResultMap(var base, array! data, array columnMap, int dirtyState = 0, boolean keepSnapshots = false);

	/**
	 * Assigns values to a model from an array returning a new model
	 */
	public static function cloneResult(<ModelInterface> base, array data, int dirtyState = 0) -> <ModelInterface>;

	/**
	 * Returns an hydrated result based on the data and the column map
	 */
	public static function cloneResultMapHydrate(array! data, array columnMap, int hydrationMode) -> var;

	/**
	 * Allows to query a set of records that match the specified conditions
	 */
	public static function find(var parameters = null) -> <\Phalcon\Mvc\Model\ResultsetInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 */
	public static function findFirst(var parameters = null) -> <ModelInterface>;

	/**
	 * Create a criteria for a especific model
	 */
	public static function query(<DiInterface> dependencyInjector = null) -> <\Phalcon\Mvc\Model\CriteriaInterface>;

	/**
	 * Allows to count how many records match the specified conditions
	 */
	public static function count(var parameters = null) -> int;

	/**
	 * Allows to calculate a summatory on a column that match the specified conditions
	 */
	public static function sum(var parameters = null) -> double;

	/**
	 * Allows to get the maximum value of a column that match the specified conditions
	 */
	public static function maximum(var parameters = null) -> var;

	/**
	 * Allows to get the minimum value of a column that match the specified conditions
	 */
	public static function minimum(var parameters = null) -> var;

	/**
	 * Allows to calculate the average value on a column matching the specified conditions
	 */
	public static function average(var parameters = null) -> double;

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
	 * Appends a customized message on the validation process
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Check whether validation process has generated any messages
	 */
	public function validationHasFailed() -> boolean;

	/**
	 * Returns all the validation messages
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getMessages();

	/**
	 * Inserts or updates a model instance. Returning true on success or false otherwise.
	 */
	public function save(array data = null, array whiteList = null) -> boolean;

	/**
	 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 */
	public function create(array data = null, array whiteList = null) -> boolean;

	/**
	 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 */
	public function update(array data = null, array whiteList = null) -> boolean;

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 */
	public function delete() -> boolean;

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 */
	public function getOperationMade() -> int;

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh() -> void;

	/**
	 * Skips the current operation forcing a success state
	 */
	public function skipOperation(boolean! skip) -> void;

	/**
	 * Reads an attribute value by its name
	 */
	public function readAttribute(string! attribute) -> var;

	/**
	 * Writes an attribute value by its name
	 */
	public function writeAttribute(string! attribute, var value) -> void;

	/**
	 * Returns related records based on defined relations
	 */
	public function getRelated(string! alias,array arguments = null) -> <\Phalcon\Mvc\Model\ResultsetInterface>;

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 */
	public function setSnapshotData(array! data, array columnMap = null) -> void;
}
