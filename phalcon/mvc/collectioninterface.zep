
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

use Phalcon\Mvc\Model\MessageInterface;

/**
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
interface CollectionInterface
{

	/**
	 * Sets a value for the _id propery, creates a MongoId object if needed
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
	 * Reads an attribute value by its name
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(string! attribute);

	/**
	 * Writes an attribute value by its name
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value);

	/**
	 * Returns a cloned collection
	 */
	public static function cloneResult(<CollectionInterface> collection, array! document) -> <CollectionInterface>;

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 */
	public function fireEvent(string! eventName) -> boolean;

	/**
	 * Fires an event, implicitly listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 */
	public function fireEventCancel(string! eventName) -> boolean;

	/**
	 * Check whether validation process has generated any messages
	 */
	public function validationHasFailed() -> boolean;

	/**
	 * Returns all the validation messages
	 */
	public function getMessages() -> <MessageInterface[]>;

	/**
	 * Appends a customized message on the validation process
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Creates/Updates a collection based on the values in the atributes
	 */
	public function save() -> boolean;

	/**
	 * Find a document by its id
	 *
	 * @param string id
	 * @return Phalcon\Mvc\Collection
	 */
	public static function findById(id) -> <CollectionInterface>;

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function findFirst(array parameters = null);

	/**
	 * Allows to query a set of records that match the specified conditions
	 *
	 * @param 	array parameters
	 * @return  array
	 */
	public static function find(array parameters = null);

	/**
	 * Perform a count over a collection
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function count(array parameters = null);

	/**
	 * Deletes a model instance. Returning true on success or false otherwise
	 */
	public function delete() -> boolean;
}
