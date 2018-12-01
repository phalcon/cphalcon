/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Db\AdapterInterface;
use Phalcon\DiInterface;
use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\Model\CriteriaInterface;
use Phalcon\Mvc\Model\ModelInterface;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\TransactionInterface;
use Phalcon\Mvc\ModelInterface;

/**
 * Phalcon\Mvc\ModelInterface
 *
 * Interface for Phalcon\Mvc\Model
 */
interface ModelInterface
{
	/**
	 * Appends a customized message on the validation process
	 */
	public function appendMessage(<MessageInterface> message) ->  <ModelInterface>;

	/**
	 * Assigns values to a model from an array
	 *
	 * @param array columnMap
	 */
	public function assign(array! data, var dataColumnMap = null, var whiteList = null) -> <ModelInterface>;

	/**
	 * Allows to calculate the average value on a column matching the specified conditions
	 *
	 * @param array parameters
	 * @return double
	 */
	public static function average(parameters = null) -> float;

	/**
	 * Assigns values to a model from an array returning a new model
	 */
	public static function cloneResult(<ModelInterface> base, array! data, int dirtyState = 0) -> <ModelInterface>;

	/**
	 * Assigns values to a model from an array returning a new model
	 *
	 * @param \Phalcon\Mvc\Model base
	 * @param array columnMap
	 * @return \Phalcon\Mvc\Model result
	 */
	public static function cloneResultMap(base, array! data, var columnMap, int dirtyState = 0, bool keepSnapshots = null) -> <ModelInterface>;

	/**
	 * Returns an hydrated result based on the data and the column map
	 *
	 * @param array columnMap
	 */
	public static function cloneResultMapHydrate(array! data, var columnMap, int hydrationMode);

	/**
	 * Allows to count how many records match the specified conditions
	 *
	 * @param array parameters
	 * @return int
	 */
	public static function count(parameters = null) -> int;

	/**
	 * Inserts a model instance. If the instance already exists in the persistence it will throw an exception
	 * Returning true on success or false otherwise.
	 */
	public function create() -> bool;

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 */
	public function delete() -> bool;

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
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 */
	public function fireEvent(string! eventName) -> bool;

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns bool false
	 */
	public function fireEventCancel(string! eventName) -> bool;

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 */
	public function getDirtyState() -> int;

	/**
	 * Returns array of validation messages
	 */
	public function getMessages() -> <MessageInterface[]>;

	/**
	 * Returns the models meta-data service related to the entity instance.
	 */
	public function getModelsMetaData() -> <MetaDataInterface>;

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 */
	public function getOperationMade() -> int;

	/**
	 * Gets internal database connection
	 */
	public function getReadConnection() -> <AdapterInterface>;

	/**
	 * Returns DependencyInjection connection service used to read data
	 */
	public function getReadConnectionService() -> string;

	/**
	 * Returns related records based on defined relations
	 *
	 * @param array arguments
	 */
	public function getRelated(string alias, arguments = null) -> <ResultsetInterface>;

	/**
	 * Returns schema name where table mapped is located
	 */
	public function getSchema() -> string;

	/**
	 * Returns table name mapped in the model
	 */
	public function getSource() -> string;

	/**
	 * Gets internal database connection
	 */
	public function getWriteConnection() -> <AdapterInterface>;

	/**
	 * Returns DependencyInjection connection service used to write data
	 */
	public function getWriteConnectionService() -> string;

	/**
	 * Allows to get the maximum value of a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function maximum(parameters = null) -> var;

	/**
	 * Allows to get the minimum value of a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return mixed
	 */
	public static function minimum(parameters = null) -> var;

	/**
	 * Create a criteria for a specific model
	 */
	public static function query(<DiInterface> dependencyInjector = null) -> <CriteriaInterface>;

	/**
	 * Refreshes the model attributes re-querying the record from the database
	 */
	public function refresh() -> <ModelInterface>;

	/**
	 * Inserts or updates a model instance. Returning true on success or false otherwise.
	 */
	public function save() -> bool;

	/**
	 * Sets both read/write connection services
	 */
	public function setConnectionService(string connectionService) -> void;

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 */
	public function setDirtyState(int dirtyState) -> <ModelInterface> | bool;

	/**
	 * Sets the DependencyInjection connection service used to read data
	 */
	public function setReadConnectionService(string connectionService) -> void;

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array columnMap
	 */
	public function setSnapshotData(array! data, columnMap = null) -> void;

	/**
	 * Sets a transaction related to the Model instance
	 */
	public function setTransaction(<TransactionInterface> transaction) -> <ModelInterface>;

	/**
	 * Sets the DependencyInjection connection service used to write data
	 */
	public function setWriteConnectionService(string connectionService) -> void;

	/**
	 * Skips the current operation forcing a success state
	 */
	public function skipOperation(bool skip) -> void;

	/**
	 * Allows to calculate a sum on a column that match the specified conditions
	 *
	 * @param array parameters
	 * @return double
	 */
	public static function sum(parameters = null) -> float;

	/**
	 * Check whether validation process has generated any messages
	 */
	public function validationHasFailed() -> bool;

	/**
	 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
	 * Returning true on success or false otherwise.
	 */
	public function update() -> bool;
}
