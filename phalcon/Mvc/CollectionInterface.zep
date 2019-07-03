
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
 * Interface for Phalcon\Mvc\Collection
 */
interface CollectionInterface
{
    /**
     * Appends a customized message on the validation process
     */
    public function appendMessage(<MessageInterface> message);

    /**
     * Returns a cloned collection
     */
    public static function cloneResult(<CollectionInterface> collection, array! document) -> <CollectionInterface>;

    /**
     * Perform a count over a collection
     */
    public static function count(array parameters = null) -> int;

    /**
     * Deletes a model instance. Returning true on success or false otherwise
     */
    public function delete() -> bool;

    /**
     * Allows to query a set of records that match the specified conditions
     */
    public static function find(array parameters = null) -> array;

    /**
     * Find a document by its id
     *
     * @param string id
     */
    public static function findById(var id) -> <CollectionInterface> | bool;

    /**
     * Allows to query the first record that match the specified conditions
     */
    public static function findFirst(array parameters = null) -> <CollectionInterface> | bool;

    /**
     * Fires an event, implicitly calls behaviors and listeners in the events
     * manager are notified
     */
    public function fireEvent(string! eventName) -> bool;

    /**
     * Fires an event, implicitly listeners in the events manager are notified
     * This method stops if one of the callbacks/listeners returns bool false
     */
    public function fireEventCancel(string! eventName) -> bool;

    /**
     * Retrieves a database connection
     *
     * @return MongoDb
     */
    public function getConnection();

    /**
     * Returns one of the DIRTY_STATE_* constants telling if the record exists
     * in the database or not
     */
    public function getDirtyState() -> int;

    /**
     * Returns the value of the _id property
     *
     * @return MongoId
     */
    public function getId();

    /**
     * Returns all the validation messages
     */
    public function getMessages() -> <MessageInterface[]>;

    /**
     * Returns an array with reserved properties that cannot be part of the
     * insert/update
     */
    public function getReservedAttributes() -> array;

    /**
     * Returns collection name mapped in the model
     */
    public function getSource() -> string;

    /**
     * Creates/Updates a collection based on the values in the attributes
     */
    public function save() -> bool;

    /**
     * Sets a service in the services container that returns the Mongo database
     */
    public function setConnectionService(string! connectionService);

    /**
     * Sets the dirty state of the object using one of the DIRTY_STATE_*
     * constants
     */
    public function setDirtyState(int dirtyState) -> <CollectionInterface>;

    /**
     * Sets a value for the _id property, creates a MongoId object if needed
     *
     * @param mixed id
     */
    public function setId(id);
}
