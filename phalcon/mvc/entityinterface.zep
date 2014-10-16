
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

use Phalcon\Mvc\Entity\MessageInterface;

interface EntityInterface
{
	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEvent(eventName);

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEventCancel(eventName);

	/**
	 * Appends a customized message on the validation process
	 *
	 * @param Phalcon\Mvc\Entity\MessageInterface message
	 */
	public function appendMessage(<MessageInterface> message);

	/**
	 * Check whether validation process has generated any messages
	 *
	 * @return boolean
	 */
	public function validationHasFailed();

	/**
	 * Returns all the validation messages
	 *
	 * @return Phalcon\Mvc\Entity\MessageInterface[]
	 */
	public function getMessages();

	/**
	 * Assigns values to a model from an array
	 *
	 * @param array data
	 * @param array columnMap
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function assign(array! data, var columnMap = null);

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 *
	 * @param int dirtyState
	 * @return Phalcon\Mvc\EntityInterface
	 */
	public function setDirtyState(int dirtyState);

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 *
	 * @return int
	 */
	public function getDirtyState() -> int;

	/**
	 * Reads an attribute value by its name
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(string attribute);

	/**
	 * Writes an attribute value by its name
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string attribute, value);

	/**
	 * Inserts or updates a entity instance. Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function save(var data = null, var whiteList = null);

	/**
	 * Inserts a entity instance. If the instance already exists in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function create(var data = null, var whiteList = null);

	/**
	 * Updates a entity instance. If the instance doesn't exist in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function update(var data = null, var whiteList = null);

	/**
	 * Deletes a entity instance. Returning true on success or false otherwise.
	 *
	 * @return boolean
	 */
	public function delete();

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array data
	 * @param array fieldMap
	 */
	public function setSnapshotData(array! data, var fieldMap = null);

	/**
	 * Skips the current operation forcing a success state
	 *
	 * @param boolean skip
	 */
	public function skipOperation(boolean skip);

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 *
	 * @return int
	 */
	public function getOperationMade();
}
