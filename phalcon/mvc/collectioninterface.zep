
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use Phalcon\Messages\MessageInterface;

/**
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
interface CollectionInterface
{

	/**
	 * Sets a value for the _id property, creates a MongoId object if needed
	 *
	 * @param mixed id
	 */
	public function setId(id);

	/**
	 * Returns the value of the _id property
	 *
	 * @return MongoId
	 */
	public function getId();

	/**
	 * Returns an array with reserved properties that cannot be part of the insert/update
	 */
	public function getReservedAttributes() -> array;

	/**
	 * Returns collection name mapped in the model
	 */
	public function getSource() -> string;

	/**
	 * Sets a service in the services container that returns the Mongo database
	 */
	public function setConnectionService(string! connectionService);

	/**
	 * Retrieves a database connection
	 *
	 * @return MongoDb
	 */
	public function getConnection();

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 */
	public function setDirtyState(int dirtyState) -> <\Phalcon\Mvc\CollectionInterface>;

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 *
	 * @return int
	 */
	public function getDirtyState() -> int;

	/**
	 * Returns a cloned collection
	 */
	public static function cloneResult(<CollectionInterface> collection, array! document) -> <CollectionInterface>;

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 */
	public function fireEvent(string! eventName) -> bool;

	/**
	 * Fires an event, implicitly listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns bool false
	 */
	public function fireEventCancel(string! eventName) -> bool;

	/**
	 * Check whether validation process has generated any messages
	 */
	public function validationHasFailed() -> bool;

	/**
	 * Returns all the validation messages
	 */
	public function getMessages() -> <MessageInterface[]>;

	/**
	 * Appends a customized message on the validation process
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Creates/Updates a collection based on the values in the attributes
	 */
	public function save() -> bool;

	/**
	 * Find a document by its id
	 *
	 * @param string id
	 */
	public static function findById(var id) -> <CollectionInterface> | null;

	/**
	 * Allows to query the first record that match the specified conditions
	 */
	public static function findFirst(array parameters = null) -> array;

	/**
	 * Allows to query a set of records that match the specified conditions
	 */
	public static function find(array parameters = null) -> array;

	/**
	 * Perform a count over a collection
	 */
	public static function count(array parameters = null) -> int;

	/**
	 * Deletes a model instance. Returning true on success or false otherwise
	 */
	public function delete() -> bool;
}
