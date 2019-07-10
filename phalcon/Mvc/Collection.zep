
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc;

use MongoDB\BSON\ObjectId;
use MongoDB\BSON\Unserializable;
use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;
use Phalcon\Mvc\Collection\Document;
use Phalcon\Mvc\Collection\Exception;
use Phalcon\Mvc\Collection\ManagerInterface;
use Phalcon\Messages\Message as Message;
use Phalcon\Validation\ValidationInterface;
use Phalcon\Storage\Serializer\SerializerInterface;
use Serializable;

/**
 * Phalcon\Mvc\Collection
 *
 * This component implements a high level abstraction for NoSQL databases which
 * works with documents
 */
abstract class Collection implements EntityInterface, CollectionInterface, InjectionAwareInterface, Unserializable, \Serializable
{
    const DIRTY_STATE_DETACHED = 2;
    const DIRTY_STATE_PERSISTENT = 0;
    const DIRTY_STATE_TRANSIENT = 1;
    const OP_CREATE = 1;
    const OP_DELETE = 3;
    const OP_NONE = 0;
    const OP_UPDATE = 2;

    public _id;

    protected connection;

    protected container;

    protected dirtyState = 1;

    protected static disableEvents;

    protected errorMessages = [];

    protected modelsManager;

    protected operationMade = 0;

    protected static reserved;

    protected skipped;

    protected source;

    /**
     * Phalcon\Mvc\Collection constructor
     */
    final public function __construct(<DiInterface> container = null, <ManagerInterface> modelsManager = null)
    {
        /**
         * We use a default DI if the user doesn't define one
         */
        if typeof container != "object" {
            let container = Di::getDefault();
        }

        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound(
                    "the services related to the ODM"
                )
            );
        }

        let this->container = container;

        /**
         * Inject the manager service from the DI
         */
        if typeof modelsManager != "object" {
            let modelsManager = container->getShared("collectionManager");
            if unlikely typeof modelsManager != "object" {
                throw new Exception(
                    "The injected service 'modelsManager' is not valid"
                );
            }
        }

        /**
         * Update the models-manager
         */
        let this->modelsManager = modelsManager;

        /**
         * The manager always initializes the object
         */
        modelsManager->initialize(this);

        /**
         * This allows the developer to execute initialization stuff every time
         * an instance is created
         */
        if method_exists(this, "onConstruct") {
            this->{"onConstruct"}();
        }
    }

    /**
     * Sets up a behavior in a collection
     */
    protected function addBehavior(<BehaviorInterface> behavior) -> void
    {
        (<ManagerInterface> this->modelsManager)->addBehavior(this, behavior);
    }

    /**
     * Perform an aggregation using the Mongo aggregation framework
     */
    public static function aggregate(array parameters = null, array options = null) -> array
    {
        var className, model, connection, source;

        let className = get_called_class();

        let model = new {className}();

        let connection = model->getConnection();

        let source = model->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        return connection->selectCollection(source)->aggregate(
            parameters,
            options
        );
    }

    /**
     * Appends a customized message on the validation process
     *
     *```php
     * use \Phalcon\Messages\Message as Message;
     *
     * class Robots extends \Phalcon\Mvc\Model
     * {
     *     public function beforeSave()
     *     {
     *         if ($this->name === "Peter") {
     *             $message = new Message(
     *                 "Sorry, but a robot cannot be named Peter"
     *             );
     *
     *             $this->appendMessage(message);
     *         }
     *     }
     * }
     *```
     */
    public function appendMessage(<MessageInterface> message)
    {
        let this->errorMessages[] = message;
    }

    /**
     * Returns a cloned collection
     */
    public static function cloneResult(<CollectionInterface> collection, array! document) -> <CollectionInterface>
    {
        var clonedCollection, key, value;

        let clonedCollection = clone collection;
        for key, value in document {
            clonedCollection->writeAttribute(key, value);
        }

        if method_exists(clonedCollection, "afterFetch") {
            clonedCollection->{"afterFetch"}();
        }

        return clonedCollection;
    }

    /**
     * Creates a collection based on the values in the attributes
     */
    public function create() -> bool
    {
        var data, success, status, collection;
        bool exists;

        let collection = this->prepareCU();

        /**
         * Check the dirty state of the current operation to update the current
         * operation
         */
        let exists = false;
        let this->operationMade = self::OP_CREATE;

        /**
         * The messages added to the validator are reset here
         */
        let this->errorMessages = [];

        /**
         * Execute the preSave hook
         */
        if this->preSave(this->container, self::disableEvents, exists) === false {
            return false;
        }

        let data = this->toArray();

        let success = false;

        /**
         * We always use safe stores to get the success state
         * Save the document
         */
        let status = collection->insertOne(data, ["w": true]);
        if status->isAcknowledged() {
            let success = true;

            if exists === false {
                let this->_id = status->getInsertedId();
                let this->dirtyState = self::DIRTY_STATE_PERSISTENT;
            }
        }

        /**
         * Call the postSave hooks
         */
        return this->postSave(self::disableEvents, success, exists);
    }

    /**
     * Creates a document based on the values in the attributes, if not found by
     * criteria. Preferred way to avoid duplication is to create index o
     * attribute
     *
     * ```php
     * $robot = new Robot();
     *
     * $robot->name = "MyRobot";
     * $robot->type = "Droid";
     *
     * // Create only if robot with same name and type does not exist
     * $robot->createIfNotExist(
     *     [
     *         "name",
     *         "type",
     *     ]
     * );
     * </code>
     * ```
     *
     * @deprecated
     */
    public function createIfNotExist(array! criteria) -> bool
    {
        var exists, data, keys, query,
            success, status, doc, collection;

        if unlikely empty criteria {
            throw new Exception(
                "Criteria parameter must be array with one or more attributes of the model"
            );
        }

        /**
         * Choose a collection according to the collection name
         */
        let collection = this->prepareCU();

        /**
         * Assume non-existence to fire beforeCreate events - no update does
         * occur anyway
         */
        let exists = false;

        /**
         * Reset current operation
         */

        let this->operationMade = self::OP_NONE;

        /**
         * The messages added to the validator are reset here
         */
        let this->errorMessages = [];

        /**
         * Execute the preSave hook
         */
        if this->preSave(this->container, self::disableEvents, exists) === false {
            return false;
        }

        let keys = array_flip(criteria);
        let data = this->toArray();

        if unlikely array_diff_key(keys, data) {
            throw new Exception(
                "Criteria parameter must be array with one or more attributes of the model"
            );
        }

        let query = array_intersect_key(data, keys);

        let success = false;

        /**
         * $setOnInsert in conjunction with upsert ensures creating a new document
         * "new": false returns null if new document created, otherwise new or old document could be returned
         */
        let status = collection->findAndModify(
            query,
            ["$setOnInsert": data],
            null,
            ["new": false, "upsert": true]
        );

        if status == null {
            let doc = collection->findOne(query);
            if typeof doc == "array" {
                let success = true;
                let this->operationMade = self::OP_CREATE;
                let this->_id = doc["_id"];
            }
        } else {
            this->appendMessage(
                new Message("Document already exists")
            );
        }

        /**
         * Call the postSave hooks
         */
        return this->postSave(self::disableEvents, success, exists);
    }

    /**
     * Perform a count over a collection
     *
     *```php
     * echo "There are ", Robots::count(), " robots";
     *```
     */
    public static function count(array parameters = null) -> int
    {
        var className, collection, connection;

        let className = get_called_class();

        let collection = new {className}();

        let connection = collection->getConnection();

        return static::getGroupResultset(parameters, collection, connection);
    }

    /**
     * Deletes a model instance. Returning true on success or false otherwise.
     *
     * ```php
     * $robot = Robots::findFirst();
     *
     * $robot->delete();
     *
     * $robots = Robots::find();
     *
     * foreach ($robots as $robot) {
     *     $robot->delete();
     * }
     * ```
     */
    public function delete() -> bool
    {
        var disableEvents, status, id, connection, source,
            collection, objectId, success;

        if unlikely !fetch id, this->_id {
            throw new Exception(
                "The document cannot be deleted because it doesn't exist"
            );
        }

        let disableEvents = self::disableEvents;
        let this->skipped = false;

        if !disableEvents {
            if this->fireEventCancel("beforeDelete") === false {
                return false;
            }
        }

        /**
         * Always return true if the operation is skipped
         */
        if this->skipped === true {
            return true;
        }

        let connection = this->getConnection();

        let source = this->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        /**
         * Get the \MongoDB\Collection
         */
        let collection = connection->selectCollection(source);

        if typeof id == "object" {
            let objectId = id;
        } else {
            /**
             * Is the collection using implicit object Ids?
             */
            if this->modelsManager->isUsingImplicitObjectIds(this) {
                let objectId = new ObjectId(id);
            } else {
                let objectId = id;
            }
        }

        let success = false;

        /**
         * Remove the instance
         */
        let status = collection->deleteOne(
            [
                "_id": objectId
            ],
            [
                "w": true
            ]
        );

        if status->getDeletedCount() === 0 {
            return false;
        }

        /**
         * Check the operation status
         */
        if status->isAcknowledged() {
            let success = true;
            if !disableEvents {
                this->fireEvent("afterDelete");
            }
            let this->dirtyState = self::DIRTY_STATE_DETACHED;
        } else {
            let success = false;
        }

        return success;
    }

    /**
     * Allows to query a set of records that match the specified conditions
     *
     * ```php
     * // How many robots are there?
     * $robots = Robots::find();
     *
     * echo "There are ", count($robots), "\n";
     *
     * // How many mechanical robots are there?
     * $robots = Robots::find(
     *     [
     *         [
     *             "type" => "mechanical",
     *         ]
     *     ]
     * );
     *
     * echo "There are ", count(robots), "\n";
     *
     * // Get and print virtual robots ordered by name
     * $robots = Robots::findFirst(
     *     [
     *         [
     *             "type" => "virtual"
     *         ],
     *         "order" => [
     *             "name" => 1,
     *         ]
     *     ]
     * );
     *
     * foreach ($robots as $robot) {
     *       echo $robot->name, "\n";
     * }
     *
     * // Get first 100 virtual robots ordered by name
     * $robots = Robots::find(
     *     [
     *         [
     *             "type" => "virtual",
     *         ],
     *         "order" => [
     *             "name" => 1,
     *         ],
     *         "limit" => 100,
     *     ]
     * );
     *
     * foreach ($robots as $robot) {
     *       echo $robot->name, "\n";
     * }
     * ```
     */
    public static function find(array parameters = null) -> array
    {
        var className, collection;

        let className = get_called_class();
        let collection = new {className}();

        return static::getResultset(
            parameters,
            collection,
            collection->getConnection(),
            false
        );
    }

    /**
     * Find a document by its id (_id)
     *
     * <code>
     * // Find user by using \MongoDB\BSON\ObjectId object
     * $user = Users::findById(
     *     new \MongoDB\BSON\ObjectId("545eb081631d16153a293a66")
     * );
     *
     * // Find user by using id as sting
     * $user = Users::findById("45cbc4a0e4123f6920000002");
     *
     * // Validate input
     * if ($user = Users::findById($_POST["id"])) {
     *     // ...
     * }
     * ```
     */
    public static function findById(var id) -> <CollectionInterface> | bool
    {
        var className, collection, objectId;

        if typeof id != "object" {
            if !preg_match("/^[a-f\d]{24}$/i", id) {
                return false;
            }

            let className = get_called_class();

            let collection = new {className}();

            /**
             * Check if the model use implicit ids
             */
            if collection->getCollectionManager()->isUsingImplicitObjectIds(collection) {
                let objectId = new ObjectId(id);
            } else {
                let objectId = id;
            }

        } else {
            let objectId = id;
        }

        return static::findFirst(
            [
                [
                    "_id": objectId
                ]
            ]
        );
    }

    /**
     * Allows to query the first record that match the specified conditions
     *
     * ```php
     * // What's the first robot in the robots table?
     * $robot = Robots::findFirst();
     *
     * echo "The robot name is ", $robot->name, "\n";
     *
     * // What's the first mechanical robot in robots table?
     * $robot = Robots::findFirst(
     *     [
     *         [
     *             "type" => "mechanical",
     *         ]
     *     ]
     * );
     *
     * echo "The first mechanical robot name is ", $robot->name, "\n";
     *
     * // Get first virtual robot ordered by name
     * $robot = Robots::findFirst(
     *     [
     *         [
     *             "type" => "mechanical",
     *         ],
     *         "order" => [
     *             "name" => 1,
     *         ],
     *     ]
     * );
     *
     * echo "The first virtual robot name is ", $robot->name, "\n";
     *
     * // Get first robot by id (_id)
     * $robot = Robots::findFirst(
     *     [
     *         [
     *             "_id" => new \MongoDB\BSON\ObjectId("45cbc4a0e4123f6920000002"),
     *         ]
     *     ]
     * );
     *
     * echo "The robot id is ", $robot->_id, "\n";
     * ```
     */
    public static function findFirst(array parameters = null) -> <CollectionInterface> | bool
    {
        var className, collection, connection;

        let className = get_called_class();

        let collection = new {className}();

        let connection = collection->getConnection();

        return static::getResultset(parameters, collection, connection, true);
    }

    /**
     * Fires an internal event
     */
    public function fireEvent(string! eventName) -> bool
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
        return this->modelsManager->notifyEvent(eventName, this);
    }

    /**
     * Fires an internal event that cancels the operation
     */
    public function fireEventCancel(string! eventName) -> bool
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
        if this->modelsManager->notifyEvent(eventName, this) === false {
            return false;
        }

        return true;
    }

    /**
     * Returns the models manager related to the entity instance
     */
    public function getCollectionManager() -> <ManagerInterface>
    {
        return this->modelsManager;
    }

    /**
     * Retrieves a database connection
     *
     * @return \MongoDb
     */
    public function getConnection()
    {
        if typeof this->connection != "object" {
            let this->connection = this->modelsManager->getConnection(this);
        }

        return this->connection;
    }

    /**
     * Returns DependencyInjection connection service
     */
    public function getConnectionService() -> string
    {
        return this->modelsManager->getConnectionService(this);
    }

    /**
     * Returns the dependency injection container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Returns one of the DIRTY_STATE_* constants telling if the document exists
     * in the collection or not
     */
    public function getDirtyState() -> int
    {
        return this->dirtyState;
    }

    /**
     * Returns the custom events manager
     */
    protected function getEventsManager() -> <ManagerInterface>
    {
        return this->modelsManager->getCustomEventsManager(this);
    }

    /**
     * Returns the value of the _id property
     *
     * @return \MongoDB\BSON\ObjectId
     */
    public function getId()
    {
        return this->_id;
    }

    /**
     * Returns all the validation messages
     *
     * ```php
     * $robot = new Robots();
     *
     * $robot->type = "mechanical";
     * $robot->name = "Astro Boy";
     * $robot->year = 1952;
     *
     * if ($robot->save() === false) {
     *     echo "Umh, We can't store robots right now ";
     *
     *     $messages = $robot->getMessages();
     *
     *     foreach ($messages as $message) {
     *         echo $message;
     *     }
     * } else {
     *     echo "Great, a new robot was saved successfully!";
     * }
     * ```
     */
    public function getMessages() -> <MessageInterface[]>
    {
        return this->errorMessages;
    }

    /**
     * Returns an array with reserved properties that cannot be part of the
     * insert/update
     */
    public function getReservedAttributes() -> array
    {
        var reserved;

        let reserved = self::reserved;
        if typeof reserved != "array" {
            let reserved = [
                "connection"    : true,
                "container"     : true,
                "source"        : true,
                "operationMade" : true,
                "errorMessages" : true,
                "dirtyState"    : true,
                "modelsManager" : true,
                "skipped"       : true
            ];
            let self::reserved = reserved;
        }
        return reserved;
    }

    /**
     * Returns collection name mapped in the model
     */
    public function getSource() -> string
    {
        var collection;

        if !this->source {
            let collection = this;
            let this->source = uncamelize(get_class_ns(collection));
        }

        return this->source;
    }

    /**
     * Reads an attribute value by its name
     *
     *```php
     *    echo $robot->readAttribute("name");
     *```
     */
    public function readAttribute(string! attribute) -> var | null
    {
        if !isset this->{attribute} {
            return null;
        }

        return this->{attribute};
    }

    /**
     * Creates/Updates a collection based on the values in the attributes
     */
    public function save() -> bool
    {
        var exists, data, success, status, collection;

        let collection = this->prepareCU();

        /**
         * Check the dirty state of the current operation to update the current
         * operation
         */
        let exists = this->exists(collection);

        if exists === false {
            let this->operationMade = self::OP_CREATE;
        } else {
            let this->operationMade = self::OP_UPDATE;
        }

        /**
         * The messages added to the validator are reset here
         */
        let this->errorMessages = [];

        /**
         * Execute the preSave hook
         */
        if this->preSave(this->container, self::disableEvents, exists) === false {
            return false;
        }

        let data = this->toArray();

        let success = false;

        /**
         * We always use safe stores to get the success state
         * Save the document
         */
        switch(this->operationMade) {
            case self::OP_CREATE:
                let status = collection->insertOne(data, ["w": true]);
                break;

            case self::OP_UPDATE:
                let status = collection->updateOne(["_id": this->_id], ["$set": data], ["w": true]);
                break;

            default:
                throw new Exception("Invalid operation requested for " . __METHOD__);
        }

        if status->isAcknowledged() {
            let success = true;

            if exists === false {
                let this->_id = status->getInsertedId();
                let this->dirtyState = self::DIRTY_STATE_PERSISTENT;
            }
        }

        /**
         * Call the postSave hooks
         */
        return this->postSave(self::disableEvents, success, exists);
    }

    /**
     * Serializes the object ignoring connections or protected properties
     */
    public function serialize() -> string
    {
        var container, serializer;

        /**
         * Obtain the default DI
         */
        let container = Di::getDefault();
        if unlikely typeof container != "object" {
            throw new Exception(
                "The dependency injector container is not valid"
            );
        }

        if container->has("serializer") {
            let serializer = <SerializerInterface> this->container->getShared("serializer");
            serializer->setData(this->toArray());

            return serializer->serialize();
        }

        /**
         * Use the standard serialize function to serialize the array data
         */
        return serialize(this->toArray());
    }

    /**
     * Sets the DependencyInjection connection service name
     */
    public function setConnectionService(string! connectionService) -> <Collection>
    {
        this->modelsManager->setConnectionService(this, connectionService);
        return this;
    }

    /**
     * Sets the dependency injection container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Sets the dirty state of the object using one of the DIRTY_STATE_*
     * constants
     */
    public function setDirtyState(int dirtyState) -> <CollectionInterface>
    {
        let this->dirtyState = dirtyState;
        return this;
    }

    /**
     * Sets a custom events manager
     */
    protected function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        this->modelsManager->setCustomEventsManager(this, eventsManager);
    }

    /**
     * Sets a value for the _id property, creates a ObjectId object if needed
     *
     * @param mixed id
     */
    public function setId(id)
    {
        var objectId;

        if typeof id != "object" {

            /**
             * Check if the model use implicit ids
             */
            if this->modelsManager->isUsingImplicitObjectIds(this) {
                let objectId = new ObjectId(id);
            } else {
                let objectId = id;
            }

        } else {
            let objectId = id;
        }
        let this->_id = objectId;
    }

    /**
     * Sets collection name which model should be mapped
     */
    protected function setSource(string! source) -> <Collection>
    {
        let this->source = source;
        return this;
    }

    /**
     * Skips the current operation forcing a success state
     */
    public function skipOperation(bool skip)
    {
        let this->skipped = skip;
    }

    /**
     * Allows to perform a summatory group for a column in the collection
     *
     * @deprecated
     */
    public static function summatory(string! field, conditions = null, finalize = null) -> array
    {
        var className, model, connection, source, collection, initial,
            reduce, group, retval, firstRetval;

        let className = get_called_class();

        let model = new {className}();

        let connection = model->getConnection();

        let source = model->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        let collection = connection->selectCollection(source);

        /**
         * Uses a javascript hash to group the results
         */
        let initial = [
            "summatory": []
        ];

        /**
         * Uses a javascript hash to group the results, however this is slow
         * with larger datasets
         */
        let reduce = "function (curr, result) { if (typeof result.summatory[curr." . field . "] === \"undefined\") { result.summatory[curr." . field . "] = 1; } else { result.summatory[curr." . field . "]++; } }";

        let group = collection->group([], initial, reduce);

        if fetch retval, group["retval"] {
            if fetch firstRetval, retval[0] {
                if isset firstRetval["summatory"] {
                    return firstRetval["summatory"];
                }
                return firstRetval;
            }
            return retval;
        }

        return [];
    }

    /**
     * Returns the instance as an array representation
     *
     *```php
     * print_r(
     *     $robot->toArray()
     * );
     *```
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
     * Unserializes the object from a serialized string
     */
    public function unserialize(var data)
    {
        var attributes, container, manager, key, value, serializer;

        /**
         * Obtain the default DI
         */
        let container = Di::getDefault();
        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound(
                    "the services related to the ODM"
                )
            );
        }

        /**
         * Update the dependency injector
         */
        let this->container = container;
        if container->has("serializer") {
            let serializer = <SerializerInterface> container->getShared("serializer");
            let attributes = serializer->unserialize(data);
        } else {
            let attributes = unserialize(data);
        }
        if typeof attributes == "array" {
            /**
             * Gets the default modelsManager service
             */
            let manager = container->getShared("collectionManager");
            if unlikely typeof manager != "object" {
                throw new Exception(
                    "The injected service 'collectionManager' is not valid"
                );
            }

            /**
             * Update the models manager
             */
            let this->modelsManager = manager;

            /**
             * Update the objects attributes
             */
            for key, value in attributes {
                let this->{key} = value;
            }
        }
    }

    /**
     * Creates/Updates a collection based on the values in the attributes
     */
    public function update() -> bool
    {
        var exists, data, success, status, collection;

        let collection = this->prepareCU();

        /**
         * Check the dirty state of the current operation to update the current
         * operation
         */
        let exists = this->exists(collection);

        if unlikely !exists {
            throw new Exception(
                "The document cannot be updated because it doesn't exist"
            );
        }

        let this->operationMade = self::OP_UPDATE;

        /**
         * The messages added to the validator are reset here
         */
        let this->errorMessages = [];

        /**
         * Execute the preSave hook
         */
        if this->preSave(this->container, self::disableEvents, exists) === false {
            return false;
        }

        let data = this->toArray();

        let success = false;

        /**
         * We always use safe stores to get the success state
         * Save the document
         */
        let status = collection->updateOne(
            [
                "_id": this->_id
            ],
            ["$set": data],
            [
                "w": true
            ]
        );

        if status->isAcknowledged() {
            let success = true;
        }

        /**
         * Call the postSave hooks
         */
        return this->postSave(self::disableEvents, success, exists);
    }

    /**
     * Executes validators on every validation call
     *
     *```php
     * use Phalcon\Mvc\Collection;
     * use Phalcon\Validation;
     * use Phalcon\Validation\Validator\ExclusionIn;
     *
     * class Subscriptors extends Collection
     * {
     *     public function validation()
     *     {
     *         $validator = new Validation();
     *
     *         $validator->add(
     *             "status",
     *             new ExclusionIn(
     *                 [
     *                     "domain" => [
     *                         "A",
     *                         "I",
     *                     ],
     *                 ]
     *             )
     *         );
     *
     *         return $this->validate($validator);
     *     }
     * }
     *```
     */
    protected function validate(<ValidationInterface> validator) -> bool
    {
        var messages, message;

        let messages = validator->validate(null, this);

        // Call the validation, if it returns not the bool
        // we append the messages to the current object
        if typeof messages == "boolean" {
            return messages;
        }

        for message in iterator(messages) {
            this->appendMessage(
                new Message(
                    message->getMessage(),
                    message->getField(),
                    message->getType(),
                    null,
                    message->getCode()
                )
            );
        }

        // If there is a message, it returns false otherwise true
        return !count(messages);
    }

    /**
     * Sets if a model must use implicit objects ids
     */
    protected function useImplicitObjectIds(bool useImplicitObjectIds)
    {
        this->modelsManager->useImplicitObjectIds(this, useImplicitObjectIds);
    }

    /**
     * Writes an attribute value by its name
     *
     *```php
     *    $robot->writeAttribute("name", "Rosey");
     *```
     */
    public function writeAttribute(string attribute, var value)
    {
        let this->{attribute} = value;
    }

    /**
     * Cancel the current operation
     */
    protected function cancelOperation(bool disableEvents) -> bool
    {
        var eventName;

        if !disableEvents {
            if this->operationMade == self::OP_DELETE {
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
     * @param MongoCollection collection
     */
    protected function exists(collection) -> bool
    {
        var id, objectId, exists;

        if !fetch id, this->_id {
            return false;
        }

        if typeof id == "object" {
            let objectId = id;
        } else {

            /**
             * Check if the model use implicit ids
             */
            if this->modelsManager->isUsingImplicitObjectIds(this) {
                let objectId = new ObjectId(id);
                let this->_id = objectId;
            } else {
                let objectId = id;
            }
        }

        /**
         * If we already know if the document exists we don't check it
         */
         if !this->dirtyState {
            return true;
         }

        /**
         * Perform the count using the function provided by the driver
         */
        let exists = collection->count(["_id": objectId]) > 0;

        if exists {
            let this->dirtyState = self::DIRTY_STATE_PERSISTENT;
        } else {
            let this->dirtyState = self::DIRTY_STATE_TRANSIENT;
        }

        return exists;
    }

    /**
     * Perform a count over a resultset
     *
     * @param array params
     * @param \MongoDb connection
     */
    protected static function getGroupResultset(params, <Collection> collection, connection) -> int
    {
        var source, mongoCollection, conditions;

        let source = collection->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        let mongoCollection = connection->selectCollection(source);

        /**
         * Convert the string to an array
         */
        if !fetch conditions, params[0] {
            if !fetch conditions, params["conditions"] {
                let conditions = [];
            }
        }

        return mongoCollection->count(conditions, params);
    }

    /**
     * Returns a collection resultset
     *
     * @param array params
     * @param \MongoDb connection
     * @return array
     */
    protected static function getResultset(var params, <CollectionInterface> collection, connection, bool unique)
    {
        var source, mongoCollection, conditions, base,
        documentsCursor, document, className;

        /**
         * Check if "class" clause was defined
         */
        if fetch className, params["class"] {
            let base = new {className}();

            if unlikely !(base instanceof CollectionInterface || base instanceof Collection\Document) {
                throw new Exception(
                    "Object of class '" . className . "' must be an implementation of Phalcon\\Mvc\\CollectionInterface or an instance of Phalcon\\Mvc\\Collection\\Document"
                );
            }
        } else {
            let base = collection;
        }

        if base instanceof Collection {
            base->setDirtyState(self::DIRTY_STATE_PERSISTENT);
        }

        let source = collection->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        let mongoCollection = connection->selectCollection(source);

        if unlikely typeof mongoCollection != "object" {
            throw new Exception("Couldn't select mongo collection");
        }

        /**
         * Convert the string to an array
         */
        if !fetch conditions, params[0] {
            if !fetch conditions, params["conditions"] {
                let conditions = [];
            }
        }

        if unlikely typeof conditions != "array" {
            throw new Exception("Find parameters must be an array");
        }

        /**
         * Check if a "typeMap" clause was defined or force default
         */
        if !isset params["typeMap"] {
            let params["typeMap"] = ["root": get_class(base), "document": "array"];
        }

        if unique {

            /**
             * Requesting a single result
             */
            let document = mongoCollection->findOne(conditions, params);

            if empty document {
                return false;
            }

            if method_exists(base, "afterFetch") {
                base->{"afterFetch"}();
            }

            return document;
        }

        /**
         * Requesting a complete resultset
         */
        let documentsCursor = mongoCollection->find(conditions, params);

        if method_exists(base, "afterFetch") {
            base->{"afterFetch"}();
        }

        return documentsCursor->toArray();
    }

    /**
     * Executes internal hooks before save a document
     */
    final protected function preSave(<DiInterface> container, bool disableEvents, bool exists) -> bool
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

            let this->skipped = false;

            /**
             * The operation can be skipped here
             */
            if exists {
                let eventName = "beforeUpdate";
            } else {
                let eventName = "beforeCreate";
            }

            if this->fireEventCancel(eventName) === false {
                return false;
            }

            /**
             * Always return true if the operation is skipped
             */
            if this->skipped === true {
                return true;
            }
        }

        return true;
    }

    /**
     * Executes internal events after save a document
     */
    final protected function postSave(bool disableEvents, bool success, bool exists) -> bool
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
            this->fireEvent("notSaved");
        }

        this->cancelOperation(disableEvents);
        return false;
    }

    /**
     * Shared Code for CU Operations
     * Prepares Collection
     */
    protected function prepareCU()
    {
        var container, connection, source, collection;

        let container = this->container;
        if unlikely typeof container != "object" {
            throw new Exception(
                Exception::containerServiceNotFound(
                    "the services related to the ODM"
                )
            );
        }

        let source = this->getSource();
        if unlikely empty source {
            throw new Exception("Method getSource() returns empty string");
        }

        let connection = this->getConnection();

        /**
         * Choose a collection according to the collection name
         */
        let collection = connection->selectCollection(source);

        return collection;
    }

    /**
	 * {@inheritdoc}
	 */
	public function bsonUnserialize(array data)
	{
		var container, manager, key, value;

		/**
		 * Obtain the default DI
		 */
		let container = Di::getDefault();
		if typeof container != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		/**
		 * Update the dependency injector
		 */
		let this->container = container;

		let manager = container->getShared("collectionManager");
		if typeof manager != "object" {
			throw new Exception("The injected service 'collectionManager' is not valid");
		}

		/**
		 * Update the models manager
		 */
		let this->modelsManager = manager;

		/**
		 * Update the objects attributes
		 */
		for key, value in data {
			let this->{key} = value;
		}

		if method_exists(this, "afterFetch") {
			this->{"afterFetch"}();
		}
	}
}
