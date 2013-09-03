
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
 * Phalcon\Mvc\CollectionInterface
 *
 * Interface for Phalcon\Mvc\Collection
 */
interface CollectionInterface
{

	/**
	 * Phalcon\Mvc\Collection
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(dependencyInjector=null);

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
	 *
	 * @return array
	 */
	public function getReservedAttributes();

	/**
	 * Returns collection name mapped in the model
	 *
	 * @return string
	 */
	public function getSource();

	/**
	 * Sets a service in the services container that returns the Mongo database
	 *
	 * @param string connectionService
	 */
	public function setConnectionService(connectionService);

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
	public function readAttribute(attribute);

	/**
	 * Writes an attribute value by its name
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(attribute, value);

	/**
	 * Returns a cloned collection
	 *
	 * @param Phalcon\Mvc\Collection collection
	 * @param array document
	 * @return Phalcon\Mvc\Collection
	 */
	public static function cloneResult(collection, document);

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEvent(eventName);

	/**
	 * Fires an event, implicitly listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEventCancel(eventName);

	/**
	 * Check whether validation process has generated any messages
	 *
	 * @return boolean
	 */
	public function validationHasFailed();

	/**
	 * Returns all the validation messages
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getMessages();

	/**
	 * Appends a customized message on the validation process
	 *
	 * @param Phalcon\Mvc\Model\MessageInterface message
	 */
	public function appendMessage(message);

	/**
	 * Creates/Updates a collection based on the values in the atributes
	 *
	 * @return boolean
	 */
	public function save();

	/**
	 * Find a document by its id
	 *
	 * @param string id
	 * @return Phalcon\Mvc\Collection
	 */
	public static function findById(id);

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function findFirst(parameters=null);

	/**
	 * Allows to query a set of records that match the specified conditions
	 *
	 * @param 	array parameters
	 * @return  array
	 */
	public static function find(parameters=null);

	/**
	 * Perform a count over a collection
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function count(parameters=null);

	/**
	 * Deletes a model instance. Returning true on success or false otherwise
	 *
	 * @return boolean
	 */
	public function delete();

}
