
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

use Phalcon\Di\InjectionAwareInterface;
use Phalcon\DiInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;
use Phalcon\Mvc\Entity\ManagerInterface;
use Phalcon\Mvc\Entity\ValidatorInterface;
use Phalcon\Mvc\Entity\MessageInterface;
use Phalcon\Mvc\Entity\BehaviorInterface;
use Phalcon\Mvc\Entity\Exception as EntityException;

abstract class Entity implements EntityInterface, InjectionAwareInterface, \Serializable
{
	const OP_NONE 	= 0;
	const OP_CREATE = 1;
	const OP_UPDATE = 2;
	const OP_DELETE = 3;

	const DIRTY_STATE_PERSISTENT = 0;
	const DIRTY_STATE_TRANSIENT  = 1;
	const DIRTY_STATE_DETACHED   = 2;

	protected _entityManager;

	protected _dependencyInjector;

	protected _operationMade = 0;

	protected _dirtyState = 1;

	protected _errorMessages;

	protected _skipped;
	
	protected _snapshot;

	/**
	 * Phalcon\Mvc\Entity constructor
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param Phalcon\Mvc\Entity\ManagerInterface entityManager
	 * @param string entityManagerServiceName
	 */
	public function __construct(<DiInterface> dependencyInjector = null, <ManagerInterface> entityManager = null, string entityManagerServiceName = "entityManager")
	{
		/**
		 * We use a default DI if the user doesn't define one
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = \Phalcon\Di::getDefault();
		}

		if typeof dependencyInjector != "object" {
			throw new EntityException("A dependency injector container is required to obtain the services related to the ORM");
		}

		let this->_dependencyInjector = dependencyInjector;

		/**
		 * Inject the manager service from the DI
		 */
		if typeof entityManager != "object" {
			let entityManager = <ManagerInterface> dependencyInjector->getShared(entityManagerServiceName);
			if typeof entityManager != "object" {
				throw new EntityException("The injected service '" . entityManagerServiceName . "' is not valid");
			}
		}

		/**
		 * Update the entities-manager
		 */
		let this->_entityManager = entityManager;

		/**
		 * The manager always initializes the object
		 */
		entityManager->initialize(this);

		/**
		 * This allows the developer to execute initialization stuff every time an instance is created
		 */
		if method_exists(this, "onConstruct") {
			this->{"onConstruct"}();
		}
	}

	/**
	 * Sets the dependency injection container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets a custom events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	protected function setEventsManager(<EventsManagerInterface> eventsManager)
	{
		this->_entityManager->setCustomEventsManager(this, eventsManager);
	}

	/**
	 * Returns the custom events manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	protected function getEventsManager() -> <EventsManagerInterface>
	{
		return this->_entityManager->getCustomEventsManager(this);
	}

	/**
	 * Assigns values to a entity from an array
	 *
	 *<code>
	 *$robot->assign(array(
	 *  'type' => 'mechanical',
	 *  'name' => 'Astro Boy',
	 *  'year' => 1952
	 *));
	 *</code>
	 *
	 * @param array data
	 * @param array fieldMap
	 * @return Phalcon\Mvc\Entity
	 */
	public function assign(array! data, var fieldMap = null) -> <Entity>
	{
		var key, value, attribute;

		for key, value in data {

			/**
			 * Only string keys in the data are valid
			 */
			if typeof fieldMap == "array" {

				/**
				 * Every field must be part of the column map
				 */
				if fetch attribute, fieldMap[key] {
					let this->{attribute} = value;
				} else {
					throw new EntityException("Field '" . key. "' doesn\'t make part of the field map");
				}
			} else {
				let this->{key} = value;
			}
		}

		return this;
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 *
	 * @param string eventName
	 * @return boolean
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
		return (<ManagerInterface> this->_entityManager)->notifyEvent(eventName, this);
	}

	/**
	 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
	 * This method stops if one of the callbacks/listeners returns boolean false
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEventCancel(string! eventName)
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
		if (<ManagerInterface> this->_entityManager)->notifyEvent(eventName, this) === false {
			return false;
		}

		return true;
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
	 *
	 * @param Phalcon\Mvc\Model\MessageInterface message
	 * @return Phalcon\Mvc\Model
	 */
	public function appendMessage(<MessageInterface> message) -> <\Phalcon\Mvc\Model>
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
	 *
	 * @param object validator
	 * @return Phalcon\Mvc\Entity
	 */
	protected function validate(<ValidatorInterface> validator) -> <Entity>
	{
		var message;

		/**
		 * Valid validators are objects
		 */
		if typeof validator != "object" {
			throw new EntityException("Validator must be an Object");
		}

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
	 *
	 * @return boolean
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
	 *
	 * @return Phalcon\Mvc\Entity\MessageInterface[]
	 */
	public function getMessages(var filter = null)
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
	 * Reads an attribute value by its name
	 *
	 * <code>
	 * echo $robot->readAttribute('name');
	 * </code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(string! attribute)
	{
		if isset this->{attribute} {
			return this->{attribute};
		}
		return null;
	}

	/**
	 * Writes an attribute value by its name
	 *
	 * <code>
	 * 	$robot->writeAttribute('name', 'Rosey');
	 * </code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string! attribute, value)
	{
		let this->{attribute} = value;
	}

		/**
	 * Handles method calls when a method is not implemented
	 *
	 * @param	string method
	 * @param	array arguments
	 * @return	mixed
	 */
	public function __call(string method, var arguments = null)
	{
		var entityName, status;

		let entityName = get_class(this);

		/**
		 * Try to find a replacement for the missing method in a behavior/listener
		 */
		let status = (<ManagerInterface> this->_entityManager)->missingMethod(this, method, arguments);
		if status !== null {
			return status;
		}

		/**
		 * The method doesn't exist throw an exception
		 */
		throw new EntityException("The method '" . method . "' doesn't exist on entity '" . entityName . "'");
	}

	/**
	 * Returns a simple representation of the object that can be used with var_dump
	 *
	 *<code>
	 * var_dump($robot->dump());
	 *</code>
	 *
	 * @return array
	 */
	public function dump()
	{
		return get_object_vars(this);
	}

	/**
	 * Inserts or updates a entity instance. Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function save(var data = null, var whiteList = null) -> boolean
	{
		boolean exists = false;

		if this->_dirtyState === self::DIRTY_STATE_PERSISTENT {
			let exists = true;
		}

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

		/**
		 * Call the main validation event
		 */
		if this->fireEventCancel("validation") === false {
			this->fireEvent("onValidationFails");
			return false;
		}

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

		if exists {
			let this->_operationMade = self::OP_UPDATE;
		} else {
			let this->_operationMade = self::OP_CREATE;
		}

		/**
		 * Clean the messages
		 */
		let this->_errorMessages = [];
		let this->_dirtyState = self::DIRTY_STATE_PERSISTENT;

		if exists {
			this->fireEvent("afterUpdate");
		} else {
			this->fireEvent("afterCreate");
		}
		this->fireEvent("afterSave");

		return true;
	}

	/**
	 * Inserts a entity instance. If the instance already exists in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function create(var data = null, var whiteList = null) -> boolean
	{
		/**
		 * Call the beforeValidation
		 */
		if this->fireEventCancel("beforeValidation") === false {
			return false;
		}
		if this->fireEventCancel("beforeValidationOnCreate") === false {
			return false;
		}

		/**
		 * Call the main validation event
		 */
		if this->fireEventCancel("validation") === false {
			this->fireEvent("onValidationFails");
			return false;
		}

		if this->fireEventCancel("afterValidationOnCreate") === false {
			return false;
		}

		if this->fireEventCancel("afterValidation") === false {
			return false;
		}


		let this->_skipped = false;

		/**
		 * Run Before Callbacks
		 */
		if this->fireEventCancel("beforeCreate") === false {
			return false;
		}

		/**
		 * Always return true if the operation is skipped
		 */
		if this->_skipped === true {
			return true;
		}

		let this->_operationMade = self::OP_CREATE;

		/**
		 * Clean the messages
		 */
		let this->_errorMessages = [];
		let this->_dirtyState = self::DIRTY_STATE_PERSISTENT;

		this->fireEvent("afterCreate");

		return true;
	}

	/**
	 * Updates a entity instance. If the instance doesn't exist in the persistance it will throw an exception
	 * Returning true on success or false otherwise.
	 *
	 * @param  array data
	 * @param  array whiteList
	 * @return boolean
	 */
	public function update(var data = null, var whiteList = null) -> boolean
	{
		/**
		 * Call the beforeValidation
		 */
		if this->fireEventCancel("beforeValidation") === false {
			return false;
		}
		if this->fireEventCancel("beforeValidationOnUpdate") === false {
			return false;
		}

		/**
		 * Call the main validation event
		 */
		if this->fireEventCancel("validation") === false {
			this->fireEvent("onValidationFails");
			return false;
		}

		if this->fireEventCancel("afterValidationOnUpdate") === false {
			return false;
		}

		if this->fireEventCancel("afterValidation") === false {
			return false;
		}


		let this->_skipped = false;

		/**
		 * Run Before Callbacks
		 */
		if this->fireEventCancel("beforeUpdate") === false {
			return false;
		}

		/**
		 * Always return true if the operation is skipped
		 */
		if this->_skipped === true {
			return true;
		}


		let this->_operationMade = self::OP_UPDATE;

		/**
		 * Clean the messages
		 */
		let this->_errorMessages = [];
		let this->_dirtyState = self::DIRTY_STATE_PERSISTENT;

		this->fireEvent("afterUpdate");

		return true;
	}

	/**
	 * Deletes a entity instance. Returning true on success or false otherwise.
	 *
	 * @return boolean
	 */
	public function delete() -> boolean
	{
		/**
		 * Operation made is OP_DELETE
		 */
		let this->_operationMade = self::OP_DELETE,
			this->_errorMessages = [];

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

		this->fireEvent("afterDelete");

		/**
		 * Force perform the record existence checking again
		 */
		let this->_dirtyState = self::DIRTY_STATE_DETACHED;

		return true;	
	}

		/**
	 * Setups a behavior in a model
	 *
	 *<code>
	 *<?php
	 *
	 *use Phalcon\Mvc\Model\Behavior\Timestampable;
	 *
	 *class Robots extends \Phalcon\Mvc\Entity
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
	 *
	 *}
	 *</code>
	 *
	 * @param Phalcon\Mvc\Entity\BehaviorInterface behavior
	 */
	protected function addBehavior(<BehaviorInterface> behavior)
	{
		(<ManagerInterface> this->_entityManager)->addBehavior(this, behavior);
	}

	/**
	 * Sets if the model must keep the original record snapshot in memory
	 *
	 *<code>
	 *<?php
	 *
	 *class Robots extends \Phalcon\Mvc\Entity
	 *{
	 *
	 *   public function initialize()
	 *   {
	 *		$this->keepSnapshots(true);
	 *   }
	 *
	 *}
	 *</code>
	 *
	 * @param boolean keepSnapshots
	 */
	protected function keepSnapshots(boolean keepSnapshot)
	{
		(<ManagerInterface> this->_entityManager)->keepSnapshots(this, keepSnapshot);
	}

	/**
	 * Sets the record's snapshot data.
	 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
	 *
	 * @param array data
	 * @param array fieldMap
	 */
	public function setSnapshotData(array! data, var fieldMap = null)
	{
		var key, value, snapshot, attribute;

		/**
		 * Build the snapshot based on a column map
		 */
		if typeof fieldMap == "array" {

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
				if !fetch attribute, fieldMap[key] {
					throw new EntityException("Column '" . key . "' doesn't make part of the column map");
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
	 *
	 * @return boolean
	 */
	public function hasSnapshotData() -> boolean
	{
		var snapshot;
		let snapshot = this->_snapshot;
		if typeof snapshot == "array" {
			return true;
		}
		return false;
	}

	/**
	 * Returns the internal snapshot data
	 *
	 * @return array
	 */
	public function getSnapshotData()
	{
		return this->_snapshot;
	}

	/**
	 * Returns the type of the latest operation performed by the ORM
	 * Returns one of the OP_* class constants
	 *
	 * @return int
	 */
	public function getOperationMade()
	{
		return this->_operationMade;
	}

	/**
	 * Skips the current operation forcing a success state
	 *
	 * @param boolean skip
	 */
	public function skipOperation(boolean skip)
	{
		let this->_skipped = skip;
	}

	/**
	 * Returns the instance as an array representation
	 *
	 *<code>
	 * print_r(robot->to[]);
	 *</code>
	 *
	 * @return array
	 */
	public function toArray() -> array
	{
		return get_object_vars(this);
	}

	/**
	 * Serializes the object ignoring connections or protected properties
	 *
	 * @return string
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
	 *
	 * @param string data
	 */
	public function unserialize(data) -> void
	{
		var attributes, dependencyInjector, manager, key, value;

		if typeof data == "string" {

			let attributes = unserialize(data);
			if typeof attributes == "array" {

				/**
				 * Obtain the default DI
				 */
				let dependencyInjector = \Phalcon\Di::getDefault();
				if typeof dependencyInjector != "object" {
					throw new EntityException("A dependency injector container is required to obtain the services related to the ODM");
				}

				/**
				 * Update the dependency injector
				 */
				let this->_dependencyInjector = dependencyInjector;

				/**
				 * Gets the default entityManager service
				 */
				let manager = dependencyInjector->getShared("entityManager");
				if typeof manager != "object" {
					throw new EntityException("The injected service 'entityManager' is not valid");
				}

				/**
				 * Update the entities manager
				 */
				let this->_entityManager = manager;

				/**
				 * Update the objects attributes
				 */
				for key, value in attributes {
					let this->{key} = value;
				}
			}
		}

		throw new EntityException("Invalid serialization data");
	}

	/**
	 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
	 *
	 * @param int dirtyState
	 * @return Phalcon\Mvc\Entity
	 */
	public function setDirtyState(int dirtyState) -> <\Phalcon\Mvc\Entity>
	{
		let this->_dirtyState = dirtyState;
		return this;
	}

	/**
	 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
	 *
	 * @return int
	 */
	public function getDirtyState() -> int
	{
		return this->_dirtyState;
	}
}
