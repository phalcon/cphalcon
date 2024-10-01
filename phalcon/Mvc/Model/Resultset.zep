
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use ArrayAccess;
use Closure;
use Countable;
use Iterator;
use JsonSerializable;
use Phalcon\Cache\CacheInterface;
use Phalcon\Db\Enum;
use Phalcon\Messages\MessageInterface;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Storage\Serializer\SerializerInterface;
use SeekableIterator;
use Serializable;

/**
 * Phalcon\Mvc\Model\Resultset
 *
 * This component allows to Phalcon\Mvc\Model returns large resultsets with the minimum memory consumption
 * Resultsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
 * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
 * serializing.
 *
 * ```php
 *
 * // Using a standard foreach
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($robots as robot) {
 *     echo robot->name, "\n";
 * }
 *
 * // Using a while
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * $robots->rewind();
 *
 * while ($robots->valid()) {
 *     $robot = $robots->current();
 *
 *     echo $robot->name, "\n";
 *
 *     $robots->next();
 * }
 * ```
 * @template TKey
 * @template TValue
 * @implements Iterator<TKey, TValue>
 */
abstract class Resultset
    implements ResultsetInterface, Iterator, SeekableIterator, Countable, ArrayAccess, Serializable, JsonSerializable
{
    const HYDRATE_ARRAYS      = 1;
    const HYDRATE_OBJECTS     = 2;
    const HYDRATE_RECORDS     = 0;
    const TYPE_RESULT_FULL    = 0;
    const TYPE_RESULT_PARTIAL = 1;

    /**
     * @var mixed|null
     */
    protected activeRow = null;

    /**
     * @var CacheInterface|null
     */
    protected cache = null;

    /**
     * @var int
     */
    protected count = 0;

    /**
     * @var array
     */
    protected errorMessages = [];

    /**
     * @var int
     */
    protected hydrateMode = 0;

    /**
     * @var bool
     */
    protected isFresh = true;

    /**
     * @var int
     */
    protected pointer = 0;

    /**
     * @var mixed|null
     */
    protected row = null;

    /**
     * @var array|null
     */
    protected rows = null;

    /**
     * Phalcon\Db\ResultInterface or false for empty resultset
     *
     * @var ResultInterface|bool
     */
    protected result;

    /**
     * Phalcon\Mvc\Model\Resultset constructor
     *
     * @param ResultInterface|false $result
     * @param mixed|null            $cache
     */
    public function __construct(var result, var cache = null)
    {
        var prefetchRecords, rowCount, rows;

        /**
         * 'false' is given as result for empty result-sets
         */
        if typeof result !== "object" {
            let this->count = 0;
            let this->rows = [];

            return;
        }

        /**
         * Valid resultsets are Phalcon\Db\ResultInterface instances
         */
        let this->result = result;

        /**
         * Update the related cache if any
         */
        if cache !== null {
            if unlikely (
                true !== is_a(cache,  "Phalcon\\Cache\\CacheInterface") &&
                true !== is_a(cache,  "Psr\\SimpleCache\\CacheInterface")
            ) {
                throw new Exception(
                    "Cache service must be an object implementing " .
                    "Phalcon\Cache\CacheInterface or Psr\SimpleCache\CacheInterface"
                );
            }


            let this->cache = cache;
        }

        /**
         * Do the fetch using only associative indexes
         */
        result->setFetchMode(Enum::FETCH_ASSOC);

        /**
         * Update the row-count
         */
        let rowCount    = result->numRows(),
            this->count = rowCount;

        /**
         * Empty result-set
         */
        if rowCount == 0 {
            let this->rows = [];

            return;
        }

        /**
         * Small result-sets with less equals 32 rows are fetched at once
         */
        let prefetchRecords = (int) globals_get("orm.resultset_prefetch_records");
        if prefetchRecords > 0 && rowCount <= prefetchRecords {
            /**
             * Fetch ALL rows from database
             */
            let rows = result->fetchAll();

            if typeof rows == "array" {
                let this->rows = rows;
            } else {
                let this->rows = [];
            }
        }
    }

    /**
     * Counts how many rows are in the resultset
     */
    final public function count() -> int
    {
        return this->count;
    }

    /**
     * Deletes every record in the resultset
     */
    public function delete(<Closure> conditionCallback = null) -> bool
    {
        bool result, transaction;
        var record, connection = null;

        let result = true;
        let transaction = false;

        this->rewind();

        while this->valid() {
            let record = this->current();

            if transaction === false {
                /**
                 * We only can delete resultsets if every element is a complete object
                 */
                if unlikely !method_exists(record, "getWriteConnection") {
                    throw new Exception("The returned record is not valid");
                }

                let connection = record->getWriteConnection(),
                    transaction = true;

                connection->begin();
            }

            /**
             * Perform additional validations
             */
            if typeof conditionCallback == "object" {
                if call_user_func_array(conditionCallback, [record]) === false {
                    this->next();

                    continue;
                }
            }

            /**
             * Try to delete the record
             */
            if !record->delete() {
                /**
                 * Get the messages from the record that produce the error
                 */
                let this->errorMessages = record->getMessages();

                /**
                 * Rollback the transaction
                 */
                connection->rollback();

                let result = false;
                let transaction = false;

                break;
            }

            this->next();
        }

        /**
         * Commit the transaction
         */
        if transaction === true {
            connection->commit();
        }

        return result;
    }

    /**
     * Filters a resultset returning only those the developer requires
     *
     *```php
     * $filtered = $robots->filter(
     *     function ($robot) {
     *         if ($robot->id < 3) {
     *             return $robot;
     *         }
     *     }
     * );
     *```
     */
    public function filter(callable filter) -> <ModelInterface[]>
    {
        var record, processedRecord;
        array records;

        let records = [];

        this->rewind();

        while this->valid() {
            let record = this->current();

            let processedRecord = call_user_func_array(
                filter,
                [
                    record
                ]
            );

            /**
             * Only add processed records to 'records' if the returned value is an array/object
             */
            if typeof processedRecord != "object" && typeof processedRecord != "array" {
                this->next();

                continue;
            }

            let records[] = processedRecord;

            this->next();
        }

        return records;
    }

    /**
     * Returns the associated cache for the resultset
     */
    public function getCache() -> <CacheInterface> | null
    {
        return this->cache;
    }

    /**
     * Get first row in the resultset
     *
     * ```php
     * $model = new Robots();
     * $manager = $model->getModelsManager();
     *
     * // \Robots
     * $manager->createQuery('SELECT * FROM Robots')
     *         ->execute()
     *         ->getFirst();
     *
     * // \Phalcon\Mvc\Model\Row
     * $manager->createQuery('SELECT r.id FROM Robots AS r')
     *         ->execute()
     *         ->getFirst();
     *
     * // NULL
     * $manager->createQuery('SELECT r.id FROM Robots AS r WHERE r.name = "NON-EXISTENT"')
     *         ->execute()
     *         ->getFirst();
     * ```
     *
     * @return ModelInterface|Row|null
     */
    public function getFirst() -> var | null
    {
        if this->count == 0 {
            return null;
        }

        this->seek(0);

        return this->{"current"}();
    }

    /**
     * Returns the current hydration mode
     */
    public function getHydrateMode() -> int
    {
        return this->hydrateMode;
    }

    /**
     * Get last row in the resultset
     */
    public function getLast() -> <ModelInterface> | null
    {
        var count;

        let count = this->count;

        if count == 0 {
            return null;
        }

        this->seek(count - 1);

        return this->{"current"}();
    }

    /**
     * Returns the error messages produced by a batch operation
     */
    public function getMessages() -> <MessageInterface[]>
    {
        return this->errorMessages;
    }

    /**
     * Returns the internal type of data retrieval that the resultset is using
     */
    public function getType() -> int
    {
        return typeof this->rows == "array" ? self::TYPE_RESULT_FULL : self::TYPE_RESULT_PARTIAL;
    }

    /**
     * Tell if the resultset if fresh or an old one cached
     */
    public function isFresh() -> bool
    {
        return this->isFresh;
    }

    /**
     * Returns serialised model objects as array for json_encode.
     * Calls jsonSerialize on each object if present
     *
     *```php
     * $robots = Robots::find();
     *
     * echo json_encode($robots);
     *```
     */
    public function jsonSerialize() -> array
    {
        var current;
        array records;

        let records = [];

        this->rewind();

        while this->valid() {
            let current = this->current();

            if typeof current == "object" && method_exists(current, "jsonSerialize") {
                let records[] = current->{"jsonSerialize"}();
            } else {
                let records[] = current;
            }

            this->next();
        }

        return records;
    }

    /**
     * Gets pointer number of active row in the resultset
     *
     * @return TKey|null
     */
    public function key() -> int | null
    {
        if !this->valid() {
            return null;
        }

        return this->pointer;
    }

    /**
     * Moves cursor to next row in the resultset
     */
    public function next() -> void
    {
        // Seek to the next position
        this->seek(
            this->pointer + 1
        );
    }

    /**
     * Gets row in a specific position of the resultset
     */
    public function offsetGet(mixed index) -> mixed
    {
        if unlikely index >= this->count {
            throw new Exception("The index does not exist in the cursor");
        }

        /**
         * Move the cursor to the specific position
         */
        this->seek(index);

        return this->{"current"}();
    }

    /**
     * Checks whether offset exists in the resultset
     */
    public function offsetExists(var index) -> bool
    {
        return index < this->count;
    }

    /**
     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param int offset
     * @param \Phalcon\Mvc\ModelInterface value
     */
    public function offsetSet(var offset, var value) -> void
    {
        throw new Exception("Cursor is an immutable ArrayAccess object");
    }

    /**
     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     */
    public function offsetUnset(var offset) -> void
    {
        throw new Exception("Cursor is an immutable ArrayAccess object");
    }

    /**
     * Rewinds resultset to its beginning
     */
    final public function rewind() -> void
    {
        this->seek(0);
    }

    /**
     * Changes the internal pointer to a specific position in the resultset.
     * Set the new position if required, and then set this->row
     */
    final public function seek(var position) -> void
    {
        var result, row;

        if this->pointer != position || this->row === null {
            if typeof this->rows == "array" {
                /**
                 * All rows are in memory
                 */
                if fetch row, this->rows[position] {
                    let this->row = row;
                }

                let this->pointer = position;
                let this->activeRow = null;

                return;
            }

            /**
             * Fetch from PDO one-by-one.
             */
            let result = this->result;

            if this->row === null && this->pointer === 0 {
                /**
                 * Fresh result-set: Query was already executed in
                 * `Model\Query::executeSelect()`
                 * The first row is available with fetch
                 */
                let this->row = result->$fetch();
            }

            if this->pointer > position {
                /**
                 * Current pointer is ahead requested position: e.g. request a
                 * previous row. It is not possible to rewind. Re-execute query
                 * with dataSeek.
                 */
                result->dataSeek(position);

                let this->row = result->$fetch();
                let this->pointer = position;
            }

            while this->pointer < position {
                /**
                 * Requested position is greater than current pointer, seek
                 * forward until the requested position is reached. We do not
                 * need to re-execute the query!
                 */
                let this->row = result->$fetch();
                let this->pointer++;
            }

            let this->pointer = position;
            let this->activeRow = null;
        }
    }

    /**
     * Sets the hydration mode in the resultset
     */
    public function setHydrateMode(int hydrateMode) -> <ResultsetInterface>
    {
        let this->hydrateMode = hydrateMode;

        return this;
    }

    /**
     * Set if the resultset is fresh or an old one cached
     */
    public function setIsFresh(bool isFresh) -> <ResultsetInterface>
    {
        let this->isFresh = isFresh;

        return this;
    }

    /**
     * Updates every record in the resultset
     *
     * @param array data
     */
    public function update(var data, <Closure> conditionCallback = null) -> bool
    {
        bool transaction;
        var record, connection = null;

        let transaction = false;

        this->rewind();

        while this->valid() {
            let record = this->current();

            if transaction === false {
                /**
                 * We only can update resultsets if every element is a complete object
                 */
                if unlikely !method_exists(record, "getWriteConnection") {
                    throw new Exception("The returned record is not valid");
                }

                let connection = record->getWriteConnection(),
                    transaction = true;

                connection->begin();
            }

            /**
             * Perform additional validations
             */
            if typeof conditionCallback == "object" {
                if call_user_func_array(conditionCallback, [record]) === false {
                    this->next();

                    continue;
                }
            }

            record->assign(data);

            /**
             * Try to update the record
             */
            if !record->save() {
                /**
                 * Get the messages from the record that produce the error
                 */
                let this->errorMessages = record->getMessages();

                /**
                 * Rollback the transaction
                 */
                connection->rollback();

                let transaction = false;

                break;
            }

            this->next();
        }

        /**
         * Commit the transaction
         */
        if transaction === true {
            connection->commit();
        }

        return transaction;
    }

    /**
     * Check whether internal resource has rows to fetch
     */
    public function valid() -> bool
    {
        return this->pointer < this->count;
    }
}
