
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
 |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc;

/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
class Collection //implements Phalcon\Mvc\CollectionInterface, Phalcon\Di\InjectionAwareInterface, Serializable
{

	public _id;

	protected _dependencyInjector;

	protected _modelsManager;

	protected _source;

	protected _operationMade = 0;

	protected _connection;

	protected _errorMessages;

	protected static _reserved;

	protected static _disableEvents;

	const OP_NONE = 0;

	const OP_CREATE = 1;

	const OP_UPDATE = 2;

	const OP_DELETE = 3;

	/**
	 * Phalcon\Mvc\Model constructor
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param Phalcon\Mvc\Collection\ManagerInterface modelsManager
	 */
	public final function __construct(dependencyInjector=null, modelsManager=null)
	{
 		/**
		 * We use a default DI if the user doesn't define one
		 */
		if typeof dependencyInjector != "object" {
			let dependencyInjector = Phalcon\DI::getDefault();
		}
 
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
		}
 
		let this->_dependencyInjector = dependencyInjector;
 
		/**
		 * Inject the manager service from the DI
		 */
		if typeof modelsManager != "object" {
			let modelsManager = dependencyInjector->getShared('collectionManager');
			if typeof modelsManager != "object" {
				throw new Phalcon\Mvc\Model\Exception("The injected service 'modelsManager' is not valid");
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
		if (method_exists(this, 'onConstruct')) {
			this->onConstruct();
		}
	}
 
	/**
	 * Sets a value for the _id property, creates a MongoId object if needed
	 *
	 * @param mixed id
	 */
	public function setId(id)
	{
		var modelsManager, useImplicitIds;

		if typeof id != "object" {
 
			let modelsManager = this->_modelsManager;
 
			/**
			 * Check if the model use implicit ids
			 */
			let useImplicitIds = modelsManager->isUsingImplicitObjectIds(this);
			if useImplicitIds {
				let mongoId = new MongoId(id);
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
	 * @return \MongoId
	 */
	public function getId()
	{
		return this->_id;
	}
 
	/**
	 * Sets the dependency injection container
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function setDI(<Phalcon\DiInterface dependencyInjector> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}
 
	/**
	 * Returns the dependency injection container
	 *
	 * @return Phalcon\DiInterface
	 */
	public function getDI() -> <Phalcon\DiInterface>
	{
		return this->_dependencyInjector;
	}
 
	/**
	 * Sets a custom events manager
	 *
	 * @param Phalcon\Events\ManagerInterface eventsManager
	 */
	protected function setEventsManager(<Phalcon\Events\ManagerInterface> eventsManager)
	{
		var modelsManager;

		let modelsManager = this->_modelsManager;
		modelsManager->setCustomEventsManager(this, eventsManager);
	}
 
	/**
	 * Returns the custom events manager
	 *
	 * @return Phalcon\Events\ManagerInterface
	 */
	protected function getEventsManager() -> <Phalcon\Events\ManagerInterface>
	{
		var modelsManager;
		
		modelsManager = this->_modelsManager;
		return modelsManager->getCustomEventsManager(this);
	}
 
	/**
	 * Returns the models manager related to the entity instance
	 *
	 * @return Phalcon\Mvc\Model\ManagerInterface
	 */
	public function getModelsManager() -> <Phalcon\Mvc\Model\ManagerInterface>
	{
		return this->_modelsManager;
	}
 
	/**
	 * Returns an array with reserved properties that cannot be part of the insert/update
	 *
	 * @return array
	 */
	public function getReservedAttributes()
	{
		var reserved;

		let reserved = self::_reserved;
		if (reserved===null) {
			let reserved = array(
				'_connection' => true,
				'_dependencyInjector' => true,
				'_source' => true,
				'_operationMade' => true,
				'_errorMessages' => true
			);
			let self::_reserved = reserved;
		}
		return reserved;
	}
 
	/**
	 * Sets if a model must use implicit objects ids
	 *
	 * @param boolean useImplicitObjectIds
	 */
	protected function useImplicitObjectIds(useImplicitObjectIds)
	{
		var modelsManager;

		let modelsManager = this->_modelsManager;
		modelsManager->useImplicitObjectIds(this, useImplicitObjectIds);
	}
 
	/**
	 * Sets collection name which model should be mapped
	 *
	 * @param string source
	 * @return Phalcon\Mvc\Collection
	 */
	protected function setSource(source) -> <Phalcon\Mvc\Collection>
	{
		let this->_source = source;
		return this;
	}
 
	/**
	 * Returns collection name mapped in the model
	 *
	 * @return string
	 */
	public function getSource()
	{
		var source, className;

		let source = this->_source;
		if(!source){
			let className = get_class_ns(this);
			let source = uncamelize(className);
			let this->_source = source;
		}
		return source;
	}
 
	/**
	 * Sets the DependencyInjection connection service name
	 *
	 * @param string connectionService
	 * @return Phalcon\Mvc\Model
	 */
	public function setConnectionService(connectionService) -> <Phalcon\Mvc\Model>
	{
		var modelsManager;

		let modelsManager = this->_modelsManager;
		modelsManager->setConnectionService(this, connectionService);
		return this;
	}
 
	/**
	 * Returns DependencyInjection connection service
	 *
	 * @return string
	 */
	public function getConnectionService()
	{
		var modelsManager;

		modelsManager = this->_modelsManager;
		return modelsManager->getConnectionService(this);
	}
 
	/**
	 * Retrieves a database connection
	 *
	 * @return \MongoDb
	 */
	public function getConnection()
	{
		var connection, modelsManager;

		let connection = this->_connection;
		if typeof connection != "object" {
			let modelsManager = this->_modelsManager;
			let connection = modelsManager->getConnection(this);
			let this->_connection = connection;
		}
		return connection;
	}
 
	/**
	 * Reads an attribute value by its name
	 *
	 *<code>
	 *	echo robot->readAttribute('name');
	 *</code>
	 *
	 * @param string attribute
	 * @return mixed
	 */
	public function readAttribute(attribute)
	{
		var attribute;

		if isset(this->attribute) {
			let attributeValue = this->attribute;
			return attributeValue;
		}
		return null;
	}
 
	/**
	 * Writes an attribute value by its name
	 *
	 *<code>
	 *	robot->writeAttribute('name', 'Rosey');
	 *</code>
	 *
	 * @param string attribute
	 * @param mixed value
	 */
	public function writeAttribute(attribute, value)
	{
		let this->attribute = value;
	}
 
	/**
	 * Returns a cloned collection
	 *
	 * @param Phalcon\Mvc\Collection collection
	 * @param array document
	 * @return Phalcon\Mvc\Collection
	 */
	public static function cloneResult(collection, document) -> <Phalcon\Mvc\Collection>
	{
 		var clonedCollection;

		if typeof collection != "object" {
			throw new Phalcon\Mvc\Collection\Exception("Invalid collection");
		}
 
		if typeof document != "object" {
			throw new Phalcon\Mvc\Collection\Exception("Invalid document");
		}
 
		let clonedCollection = clone collection;
		for key,value in document 
		{
			clonedCollection->writeAttribute(key, value);
		}
 
		return clonedCollection;
	}
 
	/**
	 * Returns a collection resultset
	 *
	 * @param array params
	 * @param Phalcon\Mvc\Collection collection
	 * @param \MongoDb connection
	 * @param boolean unique
	 * @return array
	 */
	protected static function _getResultset(params, collection, connection, unique) 
	{
 
		source = collection->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		mongoCollection = connection->selectCollection(source);
 
		/**
		 * Convert the string to an array
		 */
		if(isset(params[0])){
			conditions = params[0];
		} else {
			if(isset(params['conditions'])){
				conditions = params['conditions'];
			} else {
				conditions = array();
			}
		}
 
		/**
		 * Perform the find
		 */
		if (isset(params['fields'])) {
			fields = params['fields'];
			documentsCursor = mongoCollection->find(conditions, fields);
		} else {
			documentsCursor = mongoCollection->find(conditions);
		}
 
		/**
		 * Check if a 'limit' clause was defined
		 */
		if(isset(params['limit'])){
			limit = params['limit'];
			documentsCursor->limit(limit);
		}
 
		/**
		 * Check if a 'sort' clause was defined
		 */
		if(isset(params['sort'])){
			sort = params['sort'];
			documentsCursor->sort(sort);
		}
 
		/**
		 * Check if a 'skip' clause was defined
		 */
		if(isset(params['skip'])){
			sort = params['skip'];
			documentsCursor->skip(sort);
		}
 
		/**
		 * If a group of specific fields are requested we use a Phalcon\Mvc\Collection\Document instead
		 */
		if (isset(params['fields'])) {
			base = new Phalcon_Mvc_Collection_Document();
		} else {
			base = collection;
		}
 
		if (unique === true) {
 
			/**
			 * Requesting a single result
			 */
			documentsCursor->rewind();
 
			document = documentsCursor->current();
			if (is_array(document)) {
 
				/**
				 * Assign the values to the base object
				 */
				return self::cloneResult(base, document);
			}
			return false;
		}
 
		/**
		 * Requesting a complete resultset
		 */
		collections = array();
		documentsArray = iterator_to_array(documentsCursor);
		foreach (documentsArray as document) {
 
			/**
			 * Assign the values to the base object
			 */
			collectionCloned = self::cloneResult(base, document);
 
			collections[] = collectionCloned;
		}
 
		return collections;
	}
 
	/**
	 * Perform a count over a resultset
	 *
	 * @param array params
	 * @param Phalcon\Mvc\Collection collection
	 * @param \MongoDb connection
	 * @return int
	 */
	protected static function _getGroupResultset(params, collection, connection){
 
		source = collection->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		mongoCollection = connection->selectCollection(source);
 
		/**
		 * Convert the string to an array
		 */
		if(isset(params[0])){
			conditions = params[0];
		} else {
			if(isset(params['conditions'])){
				conditions = params['conditions'];
			} else {
				conditions = array();
			}
		}
 
		simple = true;
 
		if(isset(params['limit'])){
			simple = false;
		} else {
			if(isset(params['sort'])){
				simple = false;
			} else {
				if(isset(params['skip'])){
					simple = false;
				}
			}
		}
 
		if (simple===false) {
 
			/**
			 * Perform the find
			 */
			documentsCursor = mongoCollection->find(conditions);
 
			/**
			 * Check if a 'limit' clause was defined
			 */
			if(isset(params['limit'])){
				limit = params['limit'];
				documentsCursor->limit(limit);
			}
 
			/**
			 * Check if a 'sort' clause was defined
			 */
			if(isset(params['sort'])){
				sort = params['sort'];
				documentsCursor->sort(sort);
			}
 
			/**
			 * Check if a 'skip' clause was defined
			 */
			if(isset(params['skip'])){
				sort = params['skip'];
				documentsCursor->skip(sort);
			}
 
			/**
			 * Only 'count' is supported
			 */
			return count(documentsCursor);
		}
 
		return mongoCollection->count(conditions);
	}
 
	/**
	 * Executes internal hooks before save a document
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param boolean disableEvents
	 * @param boolean exists
	 * @return boolean
	 */
	protected function _preSave(dependencyInjector, disableEvents, exists){
 
		/**
		 * Run Validation Callbacks Before
		 */
		if(!disableEvents){
 
			eventName = 'beforeValidation';
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
			if(!exists){
				eventName = 'beforeValidationOnCreate';
			} else {
				eventName = 'beforeValidationOnUpdate';
			}
 
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
		}
 
		/**
		 * Run validation
		 */
		eventName = 'validation';
		status = this->fireEventCancel(eventName);
		if(status===false){
			if(!disableEvents){
				eventName = 'onValidationFails';
				this->fireEvent(eventName);
			}
			return false;
		}
 
		if(!disableEvents){
 
			/**
			 * Run Validation Callbacks After
			 */
			if(!exists){
				eventName = 'afterValidationOnCreate';
			} else {
				eventName = 'afterValidationOnUpdate';
			}
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
			eventName = 'afterValidation';
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
			/**
			 * Run Before Callbacks
			 */
			eventName = 'beforeSave';
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
			if(exists){
				eventName = 'beforeUpdate';
			} else {
				eventName = 'beforeCreate';
			}
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
 
		}
 
		return true;
	}
 
	/**
	 * Executes internal events after save a document
	 *
	 * @param boolean disableEvents
	 * @param boolean success
	 * @param boolean exists
	 * @return boolean
	 */
	protected function _postSave(disableEvents, success, exists){
 
		if (success===true) {
			if (!disableEvents) {
 
				if (exists===true) {
					eventName = 'afterUpdate';
				} else {
					eventName = 'afterCreate';
				}
				this->fireEvent(eventName);
 
				eventName = 'afterSave';
				this->fireEvent(eventName);
			}
			return success;
		}
 
		if (!disableEvents) {
			eventName = 'notSave';
			this->fireEvent(eventName);
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
	 *class Subscriptors extends Phalcon\Mvc\Collection
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
	 *
	 * @param object validator
	 */
	protected function validate(validator){
 
		if(!is_object(validator)){
			throw new Phalcon\Mvc\Model\Exception("Validator must be an Object");
		}
 
		status = validator->validate(this);
		if(status===false){
			messages = validator->getMessages();
			foreach(messages as message){
				this->_errorMessages[] = message;
			}
		}
	}
 
	/**
	 * Check whether validation process has generated any messages
	 *
	 *<code>
	 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
	 *
	 *class Subscriptors extends Phalcon\Mvc\Collection
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
	 *
	 * @return boolean
	 */
	public function validationHasFailed(){
		errorMessages = this->_errorMessages;
		if(is_array(errorMessages)){
			if(count(errorMessages)){
				return true;
			}
		}
		return false;
	}
 
	/**
	 * Fires an internal event
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEvent(eventName){
 
		/**
		 * Check if there is a method with the same name of the event
		 */
		if(method_exists(this, eventName)){
			this->eventName();
		}
 
		/**
		 * Send a notification to the events manager
		 */
		modelsManager = this->_modelsManager;
		return modelsManager->notifyEvent(eventName, this);
	}
 
	/**
	 * Fires an internal event that cancels the operation
	 *
	 * @param string eventName
	 * @return boolean
	 */
	public function fireEventCancel(eventName){
 
		/**
		 * Check if there is a method with the same name of the event
		 */
		if (method_exists(this, eventName)) {
			status = this->eventName();
			if(status===false){
				return false;
			}
		}
 
		/**
		 * Send a notification to the events manager
		 */
		modelsManager = this->_modelsManager;
		status = modelsManager->notifyEvent(eventName, this);
		if (status===false) {
			return false;
		}
 
		return true;
	}
 
	/**
	 * Cancel the current operation
	 *
	 * @return boolean
	 */
	protected function _cancelOperation(disableEvents){
		if (!disableEvents) {
			operationMade = this->_operationMade;
			if (operationMade==3) {
				eventName = 'notDeleted';
			} else {
				eventName = 'notSaved';
			}
			this->fireEvent(eventName);
		}
		return false;
	}
 
	/**
	 * Checks if the document exists in the collection
	 *
	 * @param \MongoCollection collection
	 */
	protected function _exists(collection){
		if(isset(this->_id)){
 
			id = this->_id;
			if(is_object(id)){
				mongoId = id;
			} else {
 
				modelsManager = this->_modelsManager;
 
				/**
				 * Check if the model use implicit ids
				 */
				useImplicitIds = modelsManager->isUsingImplicitObjectIds(this);
				if (useImplicitIds) {
					mongoId = new MongoId(id);
					this->_id = mongoId;
				} else {
					mongoId = id;
				}
			}
 
			parameters = array('_id' => mongoId);
 
			/**
			 * Perform the count using the function provided by the driver
			 */
			documentCount = collection->count(parameters);
 
			zero = 0;
			return documentCount > zero;
		}
		return false;
	}
 
	/**
	 * Returns all the validation messages
	 *
	 * <code>
	 *robot = new Robots();
	 *robot->type = 'mechanical';
	 *robot->name = 'Astro Boy';
	 *robot->year = 1952;
	 *if (robot->save() == false) {
	 *	echo "Umh, We can't store robots right now ";
	 *	foreach (robot->getMessages() as message) {
	 *		echo message;
	 *	}
	 *} else {
	 *	echo "Great, a new robot was saved successfully!";
	 *}
	 * </code>
	 *
	 * @return Phalcon\Mvc\Model\MessageInterface[]
	 */
	public function getMessages(){
		return this->_errorMessages;
	}
 
	/**
	 * Appends a customized message on the validation process
	 *
	 *<code>
	 *	use \Phalcon\Mvc\Model\Message as Message;
	 *
	 *	class Robots extends Phalcon\Mvc\Model
	 *	{
	 *
	 *		public function beforeSave()
	 *		{
	 *			if (this->name == 'Peter') {
	 *				message = new Message("Sorry, but a robot cannot be named Peter");
	 *				this->appendMessage(message);
	 *			}
	 *		}
	 *	}
	 *</code>
	 *
	 * @param Phalcon\Mvc\Model\MessageInterface message
	 */
	public function appendMessage(message){
		if(!is_object(message)){
			type = gettype(message);
			exceptionMessage = "Invalid message format '".type."'";
			throw new Phalcon\Mvc\Model\Exception(exceptionMessage);
		}
		this->_errorMessages[] = message;
	}
 
	/**
	 * Creates/Updates a collection based on the values in the atributes
	 *
	 * @return boolean
	 */
	public function save(){
 
		dependencyInjector = this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ORM");
		}
 
		source = this->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		connection = this->getConnection();
 
		/**
		 * Choose a collection according to the collection name
		 */
		collection = connection->selectCollection(source);
 
		/**
		 * Check the dirty state of the current operation to update the current operation
		 */
		exists = this->_exists(collection);
 
		if(exists===false){
			this->_operationMade = 1;
		} else {
			this->_operationMade = 2;
		}
 
		emptyArray = array();
 
		/**
		 * The messages added to the validator are reset here
		 */
		this->_errorMessages = emptyArray;
 
		disableEvents = self::_disableEvents;
 
		/**
		 * Execute the preSave hook
		 */
		status = this->_preSave(dependencyInjector, disableEvents, exists);
		if(status===false){
			return false;
		}
 
		data = array();
 
		reserved = this->getReservedAttributes();
		properties = get_object_vars(this);
 
		/**
		 * We only assign values to the public properties
		 */
		foreach (properties as key => value) {
			if(key=='_id'){
				if(!is_null(value)){
					data[key] = value;
				}
			} else {
				if(!isset(reserved[key])){
					data[key] = value;
				}
			}
		}
 
		success = false;
 
		/**
		 * We always use safe stores to get the success state
		 */
		options = array("safe" => true);
 
		/**
		 * Save the document
		 */
		status = collection->save(data, options);
		if(is_array(status)){
			if(isset(status['ok'])){
				ok = status['ok'];
				if(ok){
					success = true;
					if(exists===false){
						if(isset(data['_id'])){
							id = data['_id'];
							this->_id = id;
						}
					}
				}
			}
		} else {
			success = false;
		}
 
		/**
		 * Call the postSave hooks
		 */
		return this->_postSave(disableEvents, success, exists);
	}
 
	/**
	 * Find a document by its id (_id)
	 *
	 * @param string|\MongoId id
	 * @return Phalcon\Mvc\Collection
	 */
	public static function findById(id){
 
		if typeof id != "object" {
 
			className = get_called_class();
 
			collection = new className();
 
			modelsManager = collection->getModelsManager();
 
			/**
			 * Check if the model use implicit ids
			 */
			useImplicitIds = modelsManager->isUsingImplicitObjectIds(collection);
			if (useImplicitIds) {
				mongoId = new MongoId(id);
			} else {
				mongoId = id;
			}
 
		} else {
			mongoId = id;
		}
 
		conditions = array('_id' => mongoId);
		parameters = array(conditions);
		return self::findFirst(parameters);
	}
 
	/**
	 * Allows to query the first record that match the specified conditions
	 *
	 * <code>
	 *
	 * //What's the first robot in the robots table?
	 * robot = Robots::findFirst();
	 * echo "The robot name is ", robot->name, "\n";
	 *
	 * //What's the first mechanical robot in robots table?
	 * robot = Robots::findFirst(array(
	 *     array("type" => "mechanical")
	 * ));
	 * echo "The first mechanical robot name is ", robot->name, "\n";
	 *
	 * //Get first virtual robot ordered by name
	 * robot = Robots::findFirst(array(
	 *     array("type" => "mechanical"),
	 *     "order" => array("name" => 1)
	 * ));
	 * echo "The first virtual robot name is ", robot->name, "\n";
	 *
	 * </code>
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function findFirst(parameters=null){
 
		if(!is_null(parameters)){
			if(!is_array(parameters)){
				throw new Phalcon\Mvc\Collection\Exception("Invalid parameters for findFirst");
			}
		}
 
		className = get_called_class();
 
		collection = new className();
 
		connection = collection->getConnection();
 
		unique = true;
		return self::_getResultset(parameters, collection, connection, unique);
	}
 
	/**
	 * Allows to query a set of records that match the specified conditions
	 *
	 * <code>
	 *
	 * //How many robots are there?
	 * robots = Robots::find();
	 * echo "There are ", count(robots), "\n";
	 *
	 * //How many mechanical robots are there?
	 * robots = Robots::find(array(
	 *     array("type" => "mechanical")
	 * ));
	 * echo "There are ", count(robots), "\n";
	 *
	 * //Get and print virtual robots ordered by name
	 * robots = Robots::findFirst(array(
	 *     array("type" => "virtual"),
	 *     "order" => array("name" => 1)
	 * ));
	 * foreach (robots as robot) {
	 *	   echo robot->name, "\n";
	 * }
	 *
	 * //Get first 100 virtual robots ordered by name
	 * robots = Robots::find(array(
	 *     array("type" => "virtual"),
	 *     "order" => array("name" => 1),
	 *     "limit" => 100
	 * ));
	 * foreach (robots as robot) {
	 *	   echo robot->name, "\n";
	 * }
	 * </code>
	 *
	 * @param 	array parameters
	 * @return  array
	 */
	public static function find(parameters=null){
 
		if(!is_null(parameters)){
			if(!is_array(parameters)){
				throw new Phalcon\Mvc\Collection\Exception("Invalid parameters for find");
			}
		}
 
		className = get_called_class();
 
		collection = new className();
 
		connection = collection->getConnection();
 
		unique = false;
		return self::_getResultset(parameters, collection, connection, unique);
	}
 
	/**
	 * Perform a count over a collection
	 *
	 *<code>
	 * echo 'There are ', Robots::count(), ' robots';
	 *</code>
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function count(parameters=null){
 
		if(!is_null(parameters)){
			if(!is_array(parameters)){
				throw new Phalcon\Mvc\Collection\Exception("Invalid parameters for count");
			}
		}
 
		className = get_called_class();
 
		collection = new className();
 
		connection = collection->getConnection();
 
		return self::_getGroupResultset(parameters, collection, connection);
	}
 
	/**
	 * Perform an aggregation using the Mongo aggregation framework
	 *
	 *
	 * @param array parameters
	 * @return array
	 */
	public static function aggregate(parameters){
 
		if(!is_null(parameters)){
			if(!is_array(parameters)){
				throw new Phalcon\Mvc\Collection\Exception("Invalid parameters for aggregate");
			}
		}
 
		className = get_called_class();
 
		model = new className();
 
		connection = model->getConnection();
 
		source = model->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		collection = connection->selectCollection(source);
 
		return collection->aggregate(parameters);
	}
 
	/**
	 * Allows to perform a summatory group for a column in the collection
	 *
	 * @param string field
	 * @param array conditions
	 * @param string finalize
	 * @return array
	 */
	public static function summatory(field, conditions=null, finalize=null){
 
		if (!is_string(field)) {
			throw new Phalcon\Mvc\Collection\Exception("Invalid field name for group");
		}
 
		className = get_called_class();
 
		model = new className();
 
		connection = model->getConnection();
 
		source = model->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		collection = connection->selectCollection(source);
 
		keys = array();
 
		emptyArray = array();
 
		/**
		 * Uses a javascript hash to group the results
		 */
		initial = array("summatory" => emptyArray);
 
		/**
		 * Uses a javascript hash to group the results, however this is slow with larger datasets
		 */
		reduce = "function (curr, result) { if (typeof result.summatory[curr.".field."] === \"undefined\") { result.summatory[curr.".field."] = 1; } else { result.summatory[curr.".field."]++; } }";
 
		group = collection->group(keys, initial, reduce);
 
		if (isset(group['retval'])) {
			retval = group['retval'];
			if (isset(retval[0])) {
				firstRetval = retval[0];
				if (isset(firstRetval["summatory"])) {
					summatory = firstRetval["summatory"];
					return summatory;
				}
				return firstRetval;
			}
			return retval;
		}
	}
 
	/**
	 * Deletes a model instance. Returning true on success or false otherwise.
	 *
	 * <code>
	 *
	 *	robot = Robots::findFirst();
	 *	robot->delete();
	 *
	 *	foreach (Robots::find() as robot) {
	 *		robot->delete();
	 *	}
	 * </code>
	 *
	 * @return boolean
	 */
	public function delete(){
 
		if(!isset(this->_id)){
			throw new Phalcon\Mvc\Collection\Exception("The document cannot be deleted because it doesn't exist");
		}
 
		disableEvents = self::_disableEvents;
 
		if(!disableEvents){
			eventName = 'beforeDelete';
			status = this->fireEventCancel(eventName);
			if(status===false){
				return false;
			}
		}
 
		id = this->_id;
		connection = this->getConnection();
 
		source = this->getSource();
		if (is_empty(source)) {
			throw new Phalcon\Mvc\Collection\Exception("Method getSource() returns empty string");
		}
 
		/**
		 * Get the \MongoCollection
		 */
		collection = connection->selectCollection(source);
 
		if(is_object(id)){
			mongoId = id;
		} else {
 
			modelsManager = this->_modelsManager;
 
			/**
			 * Is the collection using implicit object Ids?
			 */
			useImplicitIds = modelsManager->isUsingImplicitObjectIds(this);
			if (useImplicitIds) {
				mongoId = new MongoId(id);
			} else {
				mongoId = id;
			}
		}
 
		idCondition = array('_id' => mongoId);
 
		success = false;
		options = array("safe" => true);
 
		/**
		 * Remove the instance
		 */
		status = collection->remove(idCondition, options);
		if(!is_array(status)){
			return false;
		}
 
		/**
		 * Check the operation status
		 */
		if(isset(status['ok'])){
			ok = status['ok'];
			if(ok){
				success = true;
				if(!disableEvents){
					eventName = 'afterDelete';
					this->fireEvent(eventName);
				}
			}
		} else {
			success = false;
		}
 
		return success;
	}
 
	/**
	 * Returns the instance as an array representation
	 *
	 *<code>
	 * print_r(robot->toArray());
	 *</code>
	 *
	 * @return array
	 */
	public function toArray(){
 
		data = array();
 
		reserved = this->getReservedAttributes();
 
		/**
		 * Get an array with the values of the object
		 */
		properties = get_object_vars(this);
 
		/**
		 * We only assign values to the public properties
		 */
		foreach (properties as key => value) {
			if (key=='_id') {
				if(!is_null(value)){
					data[key] = value;
				}
			} else {
				if(!isset(reserved[key])){
					data[key] = value;
				}
			}
		}
 
		return data;
	}
 
	/**
	 * Serializes the object ignoring connections or protected properties
	 *
	 * @return string
	 */
	public function serialize(){
 
		data = this->toArray();
 
		/**
		 * Use the standard serialize function to serialize the array data
		 */
		return serialize(data);
	}
 
	/**
	 * Unserializes the object from a serialized string
	 *
	 * @param string data
	 */
	public function unserialize(data){
		if(is_string(data)){
			attributes = unserialize(data);
			if(is_array(attributes)){
 
				/**
				 * Obtain the default DI
				 */
				dependencyInjector = Phalcon\DI::getDefault();
				if (!is_object(dependencyInjector)) {
					throw new Phalcon\Mvc\Model\Exception("A dependency injector container is required to obtain the services related to the ODM");
				}
 
				/**
				 * Update the dependency injector
				 */
				this->_dependencyInjector = dependencyInjector;
 
				/**
				 * Gets the default modelsManager service
				 */
				service = 'collectionManager';
				manager = dependencyInjector->getShared(service);
				if(!is_object(manager)){
					throw new Phalcon\Mvc\Model\Exception("The injected service 'collectionManager' is not valid");
				}
 
				/**
				 * Update the models manager
				 */
				this->_modelsManager = manager;
 
				/**
				 * Update the objects attributes
				 */
				foreach (attributes as key => value) {
					this->key = value;
				}
 
				return null;
			}
		}
		throw new Phalcon\Mvc\Model\Exception('Invalid serialization data');
	}
}
