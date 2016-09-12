
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc;

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Mvc\Collection\Document;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Collection\ManagerInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;
use Phalcon\Mvc\Collection\Exception;
use Phalcon\Mvc\Model\MessageInterface;
use Phalcon\Mvc\Model\Message as Message;

/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
abstract class Collection implements EntityInterface, CollectionInterface, InjectionAwareInterface, \Serializable
{

	public _id;

	protected _dependencyInjector;

	protected _modelsManager;

	protected _source;

	protected _operationMade = 0;

	protected _connection;

	protected _errorMessages = [];

	protected static _reserved;

	protected static _disableEvents;

	protected _skipped = false;

	const OP_NONE = 0;

	const OP_CREATE = 1;

	const OP_UPDATE = 2;

	const OP_DELETE = 3;

	/**
	 * Phalcon\Mvc\Collection constructor
	 */
	public final function __construct(<DiInterface> dependencyInjector = null, <ManagerInterface> modelsManager = null)
	{
		/**
		 * We use a default DI if the user doesn't define one
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Di::getDefault();
		}

		if ! extension_loaded("mongodb") {
			throw new Exception("MongoDB extension is not loaded! see http://pecl.php.net/package/mongodb .");
		}

		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		let this->_dependencyInjector = dependencyInjector;

		/**
		 * Inject the manager service from the DI
		 */
		if typeof modelsManager != "object" {
			let modelsManager = dependencyInjector->getShared("collectionManager");
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

	/**
	 * Sets a value for the _id property, creates a MongoId object if needed
	 *
	 * @param mixed id
	 */
	public function setId(id)
	{
		var mongoId;

		if typeof id != "object" {
			/**
			 * Check if the model use implicit ids
			 */
			if this->_modelsManager->isUsingImplicitObjectIds(this) {
				let mongoId = static::_getMongoId(id);
			} else {
				let mongoId = id;
			}
		} else {
			let mongoId = id;
		}

		let this->_id = mongoId;
	}

	/**
	 * Returns the value of the _id property
	 *
	 * @return \MongoDB\BSON\ObjectID
	 */
	public function getId()
	{
		return this->_id;
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
	protected function setEventsManager(<ManagerInterface> eventsManager)
	{
		this->_modelsManager->setCustomEventsManager(this, eventsManager);
	}

	/**
	 * Returns the custom events manager
	 */
	protected function getEventsManager() -> <ManagerInterface>
	{
		return this->_modelsManager->getCustomEventsManager(this);
	}

	/**
	 * Returns the models manager related to the entity instance
	 */
	public function getCollectionManager() -> <ManagerInterface>
	{
		return this->_modelsManager;
	}

	/**
	 * Returns an array with reserved properties that cannot be part of the insert/update
	 */
	public function getReservedAttributes() -> array
	{
		var reserved;

		let reserved = self::_reserved;
		if reserved === null {
			let reserved = [
				"_connection": true,
				"_dependencyInjector": true,
				"_source": true,
				"_operationMade": true,
				"_errorMessages": true
			];
			let self::_reserved = reserved;
		}
		return reserved;
	}

	/**
	 * Sets if a model must use implicit objects ids
	 */
	protected function useImplicitObjectIds(boolean useImplicitObjectIds)
	{
		this->_modelsManager->useImplicitObjectIds(this, useImplicitObjectIds);
	}

	/**
	 * Sets collection name which model should be mapped
	 */
	protected function setSource(string! source) -> <Collection>
	{
		let this->_source = source;
		return this;
	}

	/**
	 * Returns collection name mapped in the model
	 */
	public function getSource() -> string
	{
		var dbname;

		if !this->_source {
			let dbname = this->_modelsManager->getDatabaseName();
			if empty(dbname) {
				throw new Exception("database name is empty!");
			}
    		let this->_source = dbname . "." . uncamelize(get_class_ns(this));
		}

		return this->_source;
	}

	/**
	 * Sets the DependencyInjection connection service name
	 */
	public function setConnectionService(string! connectionService) -> <Collection>
	{
		this->_modelsManager->setConnectionService(this, connectionService);
		return this;
	}

	/**
	 * Returns DependencyInjection connection service
	 */
	public function getConnectionService() -> string
	{
		return this->_modelsManager->getConnectionService(this);
	}

	/**
	 * Retrieves a database connection
	 *
	 * @return \MongoDb
	 */
	public function getConnection()
	{
		if typeof this->_connection != "object" {
			let this->_connection = this->_modelsManager->getConnection(this);
		}

		return this->_connection;
	}

	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 *	echo $robot->readAttribute('name');
	 *</code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(string! attribute)
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
	 *	$robot->writeAttribute('name', 'Rosey');
	 *</code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(string attribute, var value)
	{
		let this->{attribute} = value;
	}

	/**
	 * Returns a cloned collection
	 */
	public static function cloneResult(<CollectionInterface> collection, object! document) -> <CollectionInterface>
	{
		var clonedCollection;

		let clonedCollection = clone collection;

		if typeof document == "object" {
			var props, prop, value;
			let props = get_object_vars(document);

			for prop, value in props {
				clonedCollection->writeAttribute(prop, value);
			}
		}

		if method_exists(clonedCollection, "afterFetch") {
			clonedCollection->{"afterFetch"}();
		}

		return clonedCollection;
	}

	/**
	 * Returns a collection resultset
	 *
	 * @param array params
	 * @param \Phalcon\Mvc\Collection collection
	 * @param \MongoDb\Driver\Manager connection
	 * @param boolean unique
	 * @return array
	 */
	protected static function _getResultset(var params, <CollectionInterface> collection, connection, boolean unique)
	{
		var source, conditions, queryOptions, base, documentsCursor, mongoDocuments,
			fields, skip, limit, sort, document, collections, className, mongoQuery;

    	let queryOptions = [];
		let source = collection->getSource();

		/**
		 * Check if "class" clause was defined
		 */
		if fetch className, params["class"] {
			let base = new {className}();

			if !(base instanceof CollectionInterface || base instanceof Collection\Document) {
				throw new Exception("Object of class '" . className . "' must be an implementation of Phalcon\\Mvc\\CollectionInterface or an instance of Phalcon\\Mvc\\Collection\\Document");
			}
		} else {
			let base = collection;
		}

		if empty source {
			throw new Exception("Method getSource() returns empty string");
		}

		/**
		 * Convert the string to an array
		 */
		if !fetch conditions, params[0] {
			if !fetch conditions, params["conditions"] {
				let conditions = [];
			}
		}

		if typeof conditions != "array" {
			throw new Exception("Find parameters must be an array");
		}

		/**
		 * Perform the find
		 */
		if fetch fields, params["fields"] {
			let queryOptions["projection"] = fields;
		}

		/**
		 * Check if a "limit" clause was defined
		 */
		if fetch limit, params["limit"] {
			let queryOptions["limit"] = limit;
		}

		/**
		 * Check if a "sort" clause was defined
		 */
		if fetch sort, params["sort"] {
			let queryOptions["sort"] = sort;
		}

		/**
		 * Check if a "skip" clause was defined
		 */
		if fetch skip, params["skip"] {
			let queryOptions["skip"] = skip;
		}

    	if count(queryOptions) > 0 {
    		let mongoQuery = new \MongoDB\Driver\Query(conditions, queryOptions);
    	} else {
    		let mongoQuery = new \MongoDB\Driver\Query(conditions);
    	}

		/**
		 * @var \MongoDb\Driver\Cursor mongoCursor
		 */
    	let documentsCursor = connection->executeQuery(source, mongoQuery);
    	let mongoDocuments = documentsCursor->toArray();

		if unique === true {

			if count(mongoDocuments) == 0 {
				return false;
			}

			/**
			 * Requesting a single result
     		 */
			let document = mongoDocuments[0];

			/**
			 * Assign the values to the base object
			 */
			return static::cloneResult(base, document);
		}

		/**
		 * Requesting a complete resultset
		 */
		let collections = [];
		for document in mongoDocuments {

			/**
			 * Assign the values to the base object
			 */
			let collections[] = static::cloneResult(base, document);
		}

		return collections;
	}

	/**
	 * Perform a count over a resultset
	 *
	 * @param array params
	 * @param \Phalcon\Mvc\Collection collection
	 * @param \MongoDb\Driver\Manager connection
	 * @return int
	 */
	protected static function _getGroupResultset(params, <Collection> collection, connection) -> int
	{
		var source, mongoQuery, conditions, queryOptions,
			mongoId, limit, sort, skip, documentsCursor;

		let source = collection->getSource();
		let queryOptions = [];
		let conditions = [];

		if empty source {
			throw new Exception("Method getSource() returns empty string");
		}

		/**
		 * Convert the string to an array
		 */
		if !fetch conditions, params[0] {
			if !fetch conditions, params["conditions"] {
				let conditions = [];
			}
		}

		if fetch mongoId, conditions["_id"] {
    		let conditions["_id"] = static::_getMongoId(mongoId);
		}

		if isset params["limit"] || isset params["sort"] || isset params["skip"] {

			/**
			 * Check if a "limit" clause was defined
			 */
			if fetch limit, params["limit"] {
				let queryOptions["limit"] = limit;
			}

			/**
			 * Check if a "sort" clause was defined
			 */
			if fetch sort, params["sort"] {
				let queryOptions["sort"] = sort;
			}

			/**
			 * Check if a "skip" clause was defined
			 */
			if fetch skip, params["skip"] {
				let queryOptions["skip"] = skip;
			}

			/**
			 * Perform the find
			 */
			let mongoQuery = new \MongoDB\Driver\Query(conditions, queryOptions);
		} else {
    		/**
     		 * Perform the find
     		 */
    		let mongoQuery = new \MongoDB\Driver\Query(conditions);
		}

    	/**
 		 * Only "count" is supported
 		 */
    	let documentsCursor = connection->executeQuery(source, mongoQuery);

    	return count(documentsCursor->toArray());
	}

	/**
	 * Executes internal hooks before save a document
	 *
	 * @param \Phalcon\DiInterface dependencyInjector
	 * @param boolean disableEvents
	 * @param boolean exists
	 * @return boolean
	 */
	protected final function _preSave(dependencyInjector, boolean disableEvents, boolean exists) -> boolean
	{
		var eventName;

		/**
		 * Run Validation Callbacks Before
		 */
		if !disableEvents {

			if this->fireEventCancel("beforeValidation") === false {
				return false;
			}

			if !exists {
				let eventName = "beforeValidationOnCreate";
			} else {
				let eventName = "beforeValidationOnUpdate";
			}

			if this->fireEventCancel(eventName) === false {
				return false;
			}

		}

		/**
		 * Run validation
		 */
		if this->fireEventCancel("validation") === false {
			if !disableEvents {
				this->fireEvent("onValidationFails");
			}
			return false;
		}

		if !disableEvents {

			/**
			 * Run Validation Callbacks After
			 */
			if !exists {
				let eventName = "afterValidationOnCreate";
			} else {
				let eventName = "afterValidationOnUpdate";
			}

			if this->fireEventCancel(eventName) === false {
				return false;
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

			if exists {
				let eventName = "beforeUpdate";
			} else {
				let eventName = "beforeCreate";
			}

			if this->fireEventCancel(eventName) === false {
				return false;
			}

		}

		return true;
	}

	/**
	 * Executes internal events after save a document
	 */
	protected final function _postSave(boolean disableEvents, boolean success, boolean exists) -> boolean
	{
		var eventName;

		if success {
			if !disableEvents {
				if exists {
					let eventName = "afterUpdate";
				} else {
					let eventName = "afterCreate";
				}

				this->fireEvent(eventName);

				this->fireEvent("afterSave");
			}

			return success;
		}

		if !disableEvents {
			this->fireEvent("notSave");
		}

		this->_cancelOperation(disableEvents);

		return false;
	}

	/**
	 * Executes validators on every validation call
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
	 *
	 *class Subscriptors extends \Phalcon\Mvc\Collection
	 *{
	 *
	 *	public function validation()
	 *	{
	 *		this->validate(new ExclusionIn(array(
	 *			'field' => 'status',
	 *			'domain' => array('A', 'I')
	 *		)));
	 *		if (this->validationHasFailed() == true) {
	 *			return false;
	 *		}
	 *	}
	 *
	 *}
	 *</code>
	 */
	protected function validate(<Model\ValidatorInterface> validator) -> void
	{
		var message;

		if validator->validate(this) === false {
			for message in validator->getMessages() {
				let this->_errorMessages[] = message;
			}
		}
	}

	/**
	 * Check whether validation process has generated any messages
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
	 *
	 *class Subscriptors extends \Phalcon\Mvc\Collection
	 *{
	 *
	 *	public function validation()
	 *	{
	 *		this->validate(new ExclusionIn(array(
	 *			'field' => 'status',
	 *			'domain' => array('A', 'I')
	 *		)));
	 *		if (this->validationHasFailed() == true) {
	 *			return false;
	 *		}
	 *	}
	 *
	 *}
	 *</code>
	 */
	public function validationHasFailed() -> boolean
	{
		return (count(this->_errorMessages) > 0);
	}

	/**
	 * Fires an internal event
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
		return this->_modelsManager->notifyEvent(eventName, this);
	}

	/**
	 * Fires an internal event that cancels the operation
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
		if this->_modelsManager->notifyEvent(eventName, this) === false {
			return false;
		}

		return true;
	}

	/**
	 * Cancel the current operation
	 */
	protected function _cancelOperation(boolean disableEvents) -> boolean
	{
		var eventName;

		if !disableEvents {
			if this->_operationMade == self::OP_DELETE {
				let eventName = "notDeleted";
			} else {
				let eventName = "notSaved";
			}
			this->fireEvent(eventName);
		}
		return false;
	}

	/**
	 * Checks if the document exists in the collection
	 *
	 * @param \MongoCollection collection
	 * @return boolean
	 */
	protected function _exists(collection = null) -> boolean
	{
		var checkCollection, mongoId;

    	let checkCollection = this;
    	if typeof collection == "object" {
        	let checkCollection = collection;
    	}

		if ! fetch mongoId, checkCollection->_id {
			return false;
		}

    	let mongoId = static::_getMongoId(mongoId);

    	return static::count([ "conditions": ["_id": mongoId] ]) > 0;
	}

	/**
	 * Returns all the validation messages
	 *
	 * <code>
	 * $robot = new Robots();
	 * $robot->type = 'mechanical';
	 * $robot->name = 'Astro Boy';
	 * $robot->year = 1952;
	 * if ($robot->save() == false) {
	 *	echo "Umh, We can't store robots right now ";
	 *	foreach ($robot->getMessages() as message) {
	 *		echo message;
	 *	}
	 *} else {
	 *	echo "Great, a new robot was saved successfully!";
	 *}
	 * </code>
	 */
	public function getMessages() -> <MessageInterface[]>
	{
		return this->_errorMessages;
	}

	/**
	 * Appends a customized message on the validation process
	 *
	 *<code>
	 *	use \Phalcon\Mvc\Model\Message as Message;
	 *
	 *	class Robots extends \Phalcon\Mvc\Model
	 *	{
	 *
	 *		public function beforeSave()
	 *		{
	 *			if ($this->name == 'Peter') {
	 *				message = new Message("Sorry, but a robot cannot be named Peter");
	 *				$this->appendMessage(message);
	 *			}
	 *		}
	 *	}
	 *</code>
	 */
	public function appendMessage(<MessageInterface> message)
	{
		let this->_errorMessages[] = message;
	}

	/**
	 * Creates/Updates a collection based on the values in the attributes
	 */
	public function save() -> boolean
	{
		var exists, data, success, status, id, mongoBulkWrite, writeResult;

		/**
		 * Check the dirty state of the current operation to update the current operation
		 */
		let exists = this->_exists();

		if exists === false {
			let this->_operationMade = self::OP_CREATE;
		} else {
			let this->_operationMade = self::OP_UPDATE;
		}

		/**
		 * The messages added to the validator are reset here
		 */
		let this->_errorMessages = [];

		/**
		 * Execute the preSave hook
		 */
		if this->_preSave(this->_dependencyInjector, self::_disableEvents, exists) === false {
			return false;
		}

		let data = this->toArray();

		let success = false;

		/**
		 * We always use safe stores to get the success state
		 * Save the document
		 */
    	let mongoBulkWrite = new \MongoDB\Driver\BulkWrite(["ordered": true]);
    	if this->_operationMade == self::OP_CREATE {
        	mongoBulkWrite->insert(data);
    	} else {
        	mongoBulkWrite->update(["_id" : this->_id], data, ["w": true]);
    	}
    	let writeResult = this->getConnection()->executeBulkWrite(this->getSource(), mongoBulkWrite);

    	if this->_operationMade == self::OP_CREATE {
        	let status = writeResult->getInsertedCount();
    	} else {
        	let status = writeResult->getModifiedCount();
    	}

		if status > 0 {
        	let success = true;
        	if exists === false {
            	if fetch id, data["_id"] {
                	let this->_id = static::_getMongoId(id);
            	}
        	}
		}

		/**
		 * Call the postSave hooks
		 */
		return this->_postSave(self::_disableEvents, success, exists);
	}

	/**
	 * Creates a collection based on the values in the attributes
	 */
	public function create() -> boolean
	{
		var exists, data, success, id, mongoBulkWrite, writeResult;

		/**
		 * Check the dirty state of the current operation to update the current operation
		 */
		let exists = false;
		let this->_operationMade = self::OP_CREATE;

		/**
		 * The messages added to the validator are reset here
		 */
		let this->_errorMessages = [];

		/**
		 * Execute the preSave hook
		 */
		if this->_preSave(this->_dependencyInjector, self::_disableEvents, exists) === false {
			return false;
		}

		let data = this->toArray();

		let success = false;


    	if fetch id, data["_id"] {
        	/**
         	* Check if the model use implicit ids
         	*/
        	if this->_modelsManager->isUsingImplicitObjectIds(this) {
            	let id = static::_getMongoId(id);
            	let data["_id"] = id;
        	} else {
            	let data["_id"] = id;
        	}
    	} else {
        	let id = static::_getMongoId(id);
        	let data["_id"] = id;
    	}

		/**
		 * We always use safe stores to get the success state
		 * Save the document
		 */
    	let mongoBulkWrite = new \MongoDB\Driver\BulkWrite(["ordered": true]);
    	mongoBulkWrite->insert(data);

    	let writeResult = this->getConnection()->executeBulkWrite(this->getSource(), mongoBulkWrite);

    	if writeResult->getInsertedCount() > 0 {
        	let success = true;
        	if exists === false {
            	let this->_id = id;
        	}
    	}

		/**
		 * Call the postSave hooks
		 */
		return this->_postSave(self::_disableEvents, success, exists);
	}

	/**
	 * Creates a document based on the values in the attributes, if not found by criteria
	 * Preferred way to avoid duplication is to create index on attribute
	 *
	 * $robot = new Robot();
	 * $robot->name = "MyRobot";
	 * $robot->type = "Droid";
	 *
	 * //create only if robot with same name and type does not exist
	 * $robot->createIfNotExist( array( "name", "type" ) );
	 */
	public function createIfNotExist(array! criteria) -> boolean
	{
		var exists, data, keys, query, queryResult, mongoQuery, mongoCursor,
			id, success, doc, bulkWrite, writeResult;

		if empty criteria {
			throw new Exception("Criteria parameter must be array with one or more attributes of the model");
		}

		/**
		 * Assume non-existance to fire beforeCreate events - no update does occur anyway
		 */
		let exists = false;

		/**
		 * Reset current operation
		 */
		let this->_operationMade = self::OP_NONE;

		/**
		 * The messages added to the validator are reset here
		 */
		let this->_errorMessages = [];

		/**
		 * Execute the preSave hook
		 */
		if this->_preSave(this->_dependencyInjector, self::_disableEvents, exists) === false {
			return false;
		}

		let keys = array_flip(criteria);
		let data = this->toArray();

		if array_diff_key( keys, data ) {
			throw new Exception("Criteria parameter must be array with one or more attributes of the model");
		}

		let query = array_intersect_key( data, keys );

		let success = false;

    	/**
     	 * try to find the document using query
     	 */
    	let mongoQuery = new \MongoDB\Driver\Query(query);
    	let mongoCursor = this->getConnection()->executeQuery( this->getSource(), mongoQuery );
    	let queryResult = mongoCursor->toArray();

    	if fetch doc, queryResult[0] {
        	if fetch id, doc->_id {
            	if typeof id == "object" {
                	let exists = true;
            	}
        	}
    	}

		/**
		 * $setOnInsert in conjunction with upsert ensures creating a new document
		 * "new": false returns null if new document created, otherwise new or old document could be returned
		 */
		if exists {
			this->appendMessage( new Message("Document already exists") );
		} else {
        	let bulkWrite = new \MongoDB\Driver\BulkWrite( [ "ordered" : true ] );
        	bulkWrite->update( query, data, [ "new": true, "upsert": true ] );
        	let writeResult = this->getConnection()->executeBulkWrite(this->getSource(), bulkWrite );
			if writeResult->getUpsertedCount() > 0 {
            	let mongoQuery = new \MongoDB\Driver\Query(query);
            	let mongoCursor = this->getConnection()->executeQuery( this->getSource(), mongoQuery );
            	let doc = mongoCursor->toArray()[0];
            	if fetch id, doc->_id{
                	let success = true;
                	let this->_operationMade = self::OP_CREATE;
                	let this->_id = id;
            	}
			}
		}

		/**
		 * Call the postSave hooks
		 */
		return this->_postSave(self::_disableEvents, success, exists);
	}

	/**
	 * Creates/Updates a collection based on the values in the attributes
	 */
	public function update() -> boolean
	{
		var exists, data, success,
			mongoBulkWrite, writeResult;

		/**
		 * Check the dirty state of the current operation to update the current operation
		 */
		let exists = this->_exists();

		if ! exists {
			throw new Exception("The document cannot be updated because it doesn't exist");
		}

		let this->_operationMade = self::OP_UPDATE;

		/**
		 * The messages added to the validator are reset here
		 */
		let this->_errorMessages = [];

		/**
		 * Execute the preSave hook
		 */
		if this->_preSave(this->_dependencyInjector, self::_disableEvents, exists) === false {
			return false;
		}

		let data = this->toArray();

		let success = false;

		/**
		 * We always use safe stores to get the success state
		 * Save the document
		 */
		let mongoBulkWrite = new \MongoDB\Driver\BulkWrite(["ordered": true]);
		mongoBulkWrite->update(["_id": this->_id], data, ["w": true]);
    	let writeResult = this->getConnection()->executeBulkWrite(this->getSource(), mongoBulkWrite);

		if writeResult->getModifiedCount() > 0 {
        	let success = true;
		} else {
			let success = false;
		}

		/**
		 * Call the postSave hooks
		 */
		return this->_postSave(self::_disableEvents, success, exists);
	}

	/**
	 * Find a document by its id (_id)
	 *
	 * <code>
	 * // Find user by using \MongoDB\BSON\ObjectID object
	 * $user = Users::findById(new \MongoDB\BSON\ObjectID('545eb081631d16153a293a66'));
	 *
	 * // Find user by using id as sting
	 * $user = Users::findById('45cbc4a0e4123f6920000002');
	 *
	 * // Validate input
	 * if ($user = Users::findById($_POST['id'])) {
	 *     // ...
	 * }
	 *
	 * @return \Phalcon\Mvc\Connection|null
	 */
	public static function findById(var id) -> <Collection> | null
	{
		var className, collection, mongoId;

		if typeof id != "object" {
			if !preg_match("/^[a-f0-9]{24}$/i", id) {
				return null;
			}

			let className = get_called_class();

			let collection = new {className}();

			/**
			 * Check if the model use implicit ids
			 */
			if collection->getCollectionManager()->isUsingImplicitObjectIds(collection) {
				let mongoId = static::_getMongoId(id);
			} else {
				let mongoId = id;
			}

		} else {
			let mongoId = id;
		}

		return static::findFirst([ "conditions": ["_id": mongoId] ]);
	}

	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * <code>
	 * // What's the first robot in the robots table?
	 * $robot = Robots::findFirst();
	 * echo 'The robot name is ', $robot->name, "\n";
	 *
	 * // What's the first mechanical robot in robots table?
	 * $robot = Robots::findFirst([
	 *     ['type' => 'mechanical']
	 * ]);
	 * echo 'The first mechanical robot name is ', $robot->name, "\n";
	 *
	 * // Get first virtual robot ordered by name
	 * $robot = Robots::findFirst([
	 *     ['type' => 'mechanical'],
	 *     'order' => ['name' => 1]
	 * ]);
	 * echo 'The first virtual robot name is ', $robot->name, "\n";
	 *
	 * // Get first robot by id (_id)
	 * $robot = Robots::findFirst([
	 *     ['_id' => new \MongoDB\BSON\ObjectID('45cbc4a0e4123f6920000002')]
	 * ]);
	 * echo 'The robot id is ', $robot->_id, "\n";
	 * </code>
	 *
	 * @return \Phalcon\Mvc\Connection|[]
	 */
	public static function findFirst(array parameters = null) -> array
	{
		var className, collection, connection;

		let className = get_called_class();

		let collection = new {className}();

		let connection = collection->getConnection();

		return static::_getResultset(parameters, collection, connection, true);
	}

	/**
	 * Allows to query a set of records that match the specified conditions
	 *
	 * <code>
	 *
	 * //How many robots are there?
	 * $robots = Robots::find();
	 * echo "There are ", count($robots), "\n";
	 *
	 * //How many mechanical robots are there?
	 * $robots = Robots::find(array(
	 *     array("type" => "mechanical")
	 * ));
	 * echo "There are ", count(robots), "\n";
	 *
	 * //Get and print virtual robots ordered by name
	 * $robots = Robots::findFirst(array(
	 *     array("type" => "virtual"),
	 *     "order" => array("name" => 1)
	 * ));
	 * foreach ($robots as $robot) {
	 *	   echo $robot->name, "\n";
	 * }
	 *
	 * //Get first 100 virtual robots ordered by name
	 * $robots = Robots::find(array(
	 *     array("type" => "virtual"),
	 *     "order" => array("name" => 1),
	 *     "limit" => 100
	 * ));
	 * foreach ($robots as $robot) {
	 *	   echo $robot->name, "\n";
	 * }
	 * </code>
	 *
	 * @return \Phalcon\Mvc\Connection[]|[]
	 */
	public static function find(array parameters = null) -> array
	{
		var className, collection;

		let className = get_called_class();

		let collection = new {className}();

		return static::_getResultset(parameters, collection, collection->getConnection(), false);
	}

	/**
	 * Perform a count over a collection
	 *
	 *<code>
	 * echo 'There are ', Robots::count(), ' robots';
	 *</code>
	 *
	 * @return int
	 */
	public static function count(array parameters = null) -> array
	{
		var className, collection, connection;

		let className = get_called_class();

		let collection = new {className}();

		let connection = collection->getConnection();

		return static::_getGroupResultset(parameters, collection, connection);
	}

	/**
	 * Perform an aggregation using the Mongo aggregation framework
	 */
	public static function aggregate(array parameters = null) -> array
	{
		var className, model, connection, source, dbName,
			collectionName, _tmp, mongoCommand, mongoResult, arrayResult;

		let className = get_called_class();

		let model = new {className}();

		let connection = model->getConnection();

		let source = model->getSource();
		if empty source {
			throw new Exception("Method getSource() returns empty string");
		}

		let _tmp = explode(".", source);
		let dbName = _tmp[0];
		let collectionName = _tmp[1];

    	let mongoCommand = new \MongoDB\Driver\Command([
        	"aggregate": collectionName,
        	"pipeline": parameters
    	]);
    	let mongoResult = connection->executeCommand(dbName, mongoCommand);
    	let arrayResult = mongoResult->toArray();

    	if arrayResult[0]->ok == 1 {
        	return arrayResult[0]->result;
    	} else {
        	return [];
    	}
	}

	/**
	 * Allows to perform a summatory group for a column in the collection
	 */
	public static function summatory(string! field, conditions = null, finalize = null) -> array
	{
    	//  FIXME: (>_<)
    	throw new Exception("Ooops, this method temporarily unavailable!");
	}

	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 *
	 * <code>
	 *	$robot = Robots::findFirst();
	 *	$robot->delete();
	 *
	 *	foreach (Robots::find() as $robot) {
	 *		$robot->delete();
	 *	}
	 * </code>
	 */
	public function delete() -> boolean
	{
		var disableEvents, id, connection, source,
			mongoId, success, mongoBulkWrite, mongoWriteResult;

		if !fetch id, this->_id {
			throw new Exception("The document cannot be deleted because it doesn't exist");
		}

		let disableEvents = self::_disableEvents;

		if !disableEvents {
			if this->fireEventCancel("beforeDelete") === false {
				return false;
			}
		}

		if this->_skipped === true {
			return true;
		}

		let connection = this->getConnection();

		let source = this->getSource();
		if empty source {
			throw new Exception("Method getSource() returns empty string");
		}

		if typeof id == "object" {
			let mongoId = id;
		} else {
			/**
			 * Is the collection using implicit object Ids?
			 */
			if this->_modelsManager->isUsingImplicitObjectIds(this) {
				let mongoId = static::_getMongoId(id);
			} else {
				let mongoId = id;
			}
		}

		let success = false;

		/**
		 * Remove the instance
		 */

		let mongoBulkWrite = new \MongoDB\Driver\BulkWrite(["ordered": true]);
		mongoBulkWrite->delete(["_id": mongoId]);
		let mongoWriteResult = this->getConnection()->executeBulkWrite(this->getSource(), mongoBulkWrite);

		/**
		 * Check the operation status
		 */
    	if mongoWriteResult->getDeletedCount() > 0 {
        	let success = true;
        	if !disableEvents {
            	this->fireEvent("afterDelete");
        	}
    	}

		return success;
	}

	/**
	 * Sets up a behavior in a collection
	 */
	protected function addBehavior(<BehaviorInterface> behavior) -> void
	{
		(<ManagerInterface> this->_modelsManager)->addBehavior(this, behavior);
	}

	/**
	 * Skips the current operation forcing a success state
	 */
	public function skipOperation(boolean skip)
	{
		let this->_skipped = skip;
	}

	/**
	 * Returns the instance as an array representation
	 *
	 *<code>
	 * print_r($robot->toArray());
	 *</code>
	 */
	public function toArray() -> array
	{
		var data, reserved, key, value;

		let reserved = this->getReservedAttributes();

		/**
		 * Get an array with the values of the object
		 * We only assign values to the public properties
		 */
		let data = [];
		for key, value in get_object_vars(this) {
			if key == "_id" {
				if value {
					let data[key] = value;
				}
			} else {
				if !isset reserved[key] {
					let data[key] = value;
				}
			}
		}

		return data;
	}

	/**
	 * Serializes the object ignoring connections or protected properties
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
	 */
	public function unserialize(string! data)
	{
		var attributes, dependencyInjector, manager, key, value;

		let attributes = unserialize(data);
		if typeof attributes == "array" {

			/**
			 * Obtain the default DI
			 */
			let dependencyInjector = Di::getDefault();
			if typeof dependencyInjector != "object" {
				throw new Exception("A dependency injector container is required to obtain the services related to the ODM");
			}

			/**
			 * Update the dependency injector
			 */
			let this->_dependencyInjector = dependencyInjector;

			/**
			 * Gets the default modelsManager service
			 */
			let manager = dependencyInjector->getShared("collectionManager");
			if typeof manager != "object" {
				throw new Exception("The injected service 'collectionManager' is not valid");
			}

			/**
			 * Update the models manager
			 */
			let this->_modelsManager = manager;

			/**
			 * Update the objects attributes
			 */
			for key, value in attributes {
				let this->{key} = value;
			}
		}
	}

	/**
	 * Get or generate mongoId
	 * @return \MongoDB\BSON\ObjectID
	 */
	private static function _getMongoId(mongoId = null)
	{
		var oid;

		if mongoId == null {
			return new \MongoDB\BSON\ObjectID();
		} else {
			if typeof mongoId == "string" {
				return new \MongoDB\BSON\ObjectID(mongoId);
			}
			if typeof mongoId == "array" {
				if fetch oid, mongoId["oid"] {
					return new \MongoDB\BSON\ObjectID(oid);
				}
			}
		}

		return mongoId;
	}
}
