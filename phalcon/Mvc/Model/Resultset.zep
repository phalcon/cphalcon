
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
use Phalcon\Mvc\Model\Exceptions\CursorIsImmutable;
use Phalcon\Mvc\Model\Exceptions\IndexNotInCursor;
use Phalcon\Mvc\Model\Exceptions\InvalidResultsetCacheService;
use Phalcon\Mvc\Model\Exceptions\InvalidReturnedRecord;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Storage\Serializer\SerializerInterface;
use Phalcon\Support\Settings;
use SeekableIterator;

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
 * $invoices = Invoices::find(
 *     [
 *         "inv_status_flag = 1",
 *         "order" => "inv_title",
 *     ]
 * );
 *
 * foreach ($invoices as invoice) {
 *     echo invoice->inv_title, "\n";
 * }
 *
 * // Using a while
 * $invoices = Invoices::find(
 *     [
 *         "inv_status_flag = 1",
 *         "order" => "inv_title",
 *     ]
 * );
 *
 * $invoices->rewind();
 *
 * while ($invoices->valid()) {
 *     $invoice = $invoices->current();
 *
 *     echo $invoice->inv_title, "\n";
 *
 *     $invoices->next();
 * }
 * ```
 * @template TKey
 * @template TValue
 * @implements Iterator<TKey, TValue>
 * @implements ArrayAccess<TKey, TValue>
 */
abstract class Resultset
    implements ResultsetInterface, Iterator, SeekableIterator, Countable, ArrayAccess, JsonSerializable
{
    /**
     * @var int
     */
    const HYDRATE_ARRAYS      = 1;
    /**
     * @var int
     */
    const HYDRATE_OBJECTS     = 2;
    /**
     * @var int
     */
    const HYDRATE_RECORDS     = 0;
    /**
     * @var int
     */
    const TYPE_RESULT_FULL    = 0;
    /**
     * @var int
     */
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
     * Number of rows, or null while it has not been worked out yet. Resolved
     * lazily by count() - asking the driver up front costs SQLite an extra
     * statement on every single result-set.
     *
     * @var int|null
     */
    protected count = null;

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
        var prefetchRecords;

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
                true !== is_a(cache,  CacheInterface::class) &&
                true !== is_a(cache,  "Psr\\SimpleCache\\CacheInterface")
            ) {
                throw new InvalidResultsetCacheService();
            }


            let this->cache = cache;
        }

        /**
         * Do the fetch using only associative indexes
         */
        result->setFetchMode(Enum::FETCH_ASSOC);

        /**
         * Consume the first row. The statement has already been executed by
         * `Model\Query::executeSelect()`, so this costs no extra round trip,
         * and it is the only way to tell an empty result-set from a populated
         * one without asking the driver for a row count - which SQLite can
         * only answer by running a second statement.
         */
        let this->row = result->$fetch();

        /**
         * Empty result-set
         */
        if typeof this->row != "array" {
            let this->count = 0,
                this->rows  = [];

            return;
        }

        /**
         * Small result-sets with less equals 32 rows are fetched at once.
         * The count is only worth asking for when the prefetch is switched on,
         * which it is not by default.
         */
        let prefetchRecords = (int) Settings::get("orm.resultset_prefetch_records");

        if prefetchRecords > 0 && this->count() <= prefetchRecords {
            this->materialize();
        }
    }

    /**
     * Counts how many rows are in the resultset
     */
    final public function count() -> int
    {
        var result;

        if this->count === null {
            let result = this->result;

            if typeof this->rows == "array" {
                let this->count = count(this->rows);
            } elseif typeof result == "object" {
                let this->count = (int) result->numRows();
            } else {
                let this->count = 0;
            }
        }

        return this->count;
    }

    /**
     * Deletes every record in the resultset
     */
    public function delete(<Closure> conditionCallback = null) -> bool
    {
        bool result, transaction;
        var record, connection, isUnderTransaction = null;

        let result = true;
        let transaction = false;
        let isUnderTransaction = false;

        this->rewind();

        while this->valid() {
            let record = this->current();

            if transaction === false {
                /**
                 * We only can delete resultsets if every element is a complete object
                 */
                if unlikely !method_exists(record, "getWriteConnection") {
                    throw new InvalidReturnedRecord();
                }

                let connection = record->getWriteConnection(),
                    transaction = true,
                    isUnderTransaction = connection->isUnderTransaction();

                /**
                 * If we already under transaction we should not begin or commit it
                 */
                if isUnderTransaction === false {
                    connection->begin();
                }
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
        if transaction === true && isUnderTransaction === false {
            connection->commit();
        }
        this->refresh();
        return result;
    }

    /**
     * Filters a resultset returning only those the developer requires
     *
     *```php
     * $filtered = $invoices->filter(
     *     function ($invoice) {
     *         if ($invoice->inv_id < 3) {
     *             return $invoice;
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
     * $model = new Invoices();
     * $manager = $model->getModelsManager();
     *
     * // \Invoices
     * $manager->createQuery('SELECT * FROM Invoices')
     *         ->execute()
     *         ->getFirst();
     *
     * // \Phalcon\Mvc\Model\Row
     * $manager->createQuery('SELECT r.inv_id FROM Invoices AS r')
     *         ->execute()
     *         ->getFirst();
     *
     * // NULL
     * $manager->createQuery('SELECT r.inv_id FROM Invoices AS r WHERE r.inv_title = "NON-EXISTENT"')
     *         ->execute()
     *         ->getFirst();
     * ```
     *
     * @return ModelInterface|Row|null
     */
    public function getFirst() -> var | null
    {
        this->seek(0);

        /**
         * Positioning at the first row already tells us whether there is one,
         * so there is no need to work out the whole count
         */
        if !this->valid() {
            return null;
        }

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

        let count = this->count();

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
     * $invoices = Invoices::find();
     *
     * echo json_encode($invoices);
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
     * Fetches every remaining row of the underlying cursor into memory,
     * turning the resultset into TYPE_RESULT_FULL.
     *
     * Free when called before the cursor has been advanced: the statement has
     * already been executed by Model\Query::executeSelect() and only the row
     * the constructor consumed is missing from the cursor, so no re-execution
     * takes place. Idempotent.
     */
    public function materialize() -> void
    {
        var records, result;

        if typeof this->rows == "array" {
            return;
        }

        let result = this->result;

        if typeof result != "object" {
            let this->rows = [];

            return;
        }

        if this->pointer > 0 {
            /**
             * The cursor has been advanced past the first row, so it has to be
             * replayed from the beginning
             */
            result->execute();

            let records = result->fetchAll();
        } else {
            /**
             * The cursor sits right behind the row the constructor consumed, so
             * the whole set is that row followed by whatever is left
             */
            let records = result->fetchAll();

            if typeof records != "array" {
                let records = [];
            }

            if typeof this->row == "array" {
                let records = array_merge([this->row], records);
            }
        }

        let this->row  = null,
            this->rows = typeof records == "array" ? records : [];
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
     * Checks whether offset exists in the resultset
     */
    public function offsetExists(var index) -> bool
    {
        return index < this->count();
    }

    /**
     * Gets row in a specific position of the resultset
     */
    public function offsetGet(mixed index) -> mixed
    {
        if unlikely index >= this->count() {
            throw new IndexNotInCursor();
        }

        /**
         * Move the cursor to the specific position
         */
        this->seek(index);

        return this->{"current"}();
    }

    /**
     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     *
     * @param int offset
     * @param \Phalcon\Mvc\ModelInterface value
     */
    public function offsetSet(var offset, var value) -> void
    {
        throw new CursorIsImmutable();
    }

    /**
     * Resultsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
     */
    public function offsetUnset(var offset) -> void
    {
        throw new CursorIsImmutable();
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
                } else {
                    /**
                     * Past the end - the previous row must not be left behind
                     * as the current one
                     */
                    let this->row = false;
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
        var record, connection, isUnderTransaction = null;

        let transaction = false;
        let isUnderTransaction = false;

        this->rewind();

        while this->valid() {
            let record = this->current();

            if transaction === false {
                /**
                 * We only can update resultsets if every element is a complete object
                 */
                if unlikely !method_exists(record, "getWriteConnection") {
                    throw new InvalidReturnedRecord();
                }

                let connection = record->getWriteConnection(),
                    transaction = true,
                    isUnderTransaction = connection->isUnderTransaction();

                /**
                 * If we already under transaction we should not begin or commit it
                 */
                if isUnderTransaction === false {
                    connection->begin();
                }
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
        if transaction === true && isUnderTransaction === false {
            connection->commit();
        }
        this->refresh();
        return transaction;
    }

    /**
     * Check whether internal resource has rows to fetch
     *
     * Driven by the row the cursor is parked on rather than by the count, so
     * that a plain traversal never has to ask the driver how many rows there
     * are - on SQLite that answer costs a second statement.
     */
    public function valid() -> bool
    {
        /**
         * Nothing has been fetched yet, or the rows have just been pulled into
         * memory - position the cursor before reporting
         */
        if this->row === null {
            this->seek(this->pointer);
        }

        return typeof this->row == "array";
    }

    public function refresh() -> bool
    {
        var prefetchRecords, result, success;

        /**
         * 'false' is given as result for empty result-sets
         */
        if typeof this->result !== "object" {
            let this->count = 0;
            let this->rows = [];

            return true;
        }
        let result = this->result;
        let success = result->execute();
        if false === success {
            return false;
        }

        /**
         * The statement has been replayed, so everything derived from the
         * previous run has to go - including the cursor position
         */
        let this->isFresh   = true,
            this->count     = null,
            this->rows      = null,
            this->row       = null,
            this->activeRow = null,
            this->pointer   = 0;

        /**
         * Consume the first row to tell an empty result-set from a populated
         * one, the same way the constructor does
         */
        let this->row = result->$fetch();

        /**
         * Empty result-set
         */
        if typeof this->row != "array" {
            let this->count = 0,
                this->rows  = [];

            return true;
        }

        /**
         * Small result-sets with less equals 32 rows are fetched at once
         */
        let prefetchRecords = (int) Settings::get("orm.resultset_prefetch_records");

        if prefetchRecords > 0 && this->count() <= prefetchRecords {
            this->materialize();
        }

        return true;
    }

    public function getResult() -> var
    {
        return this->result;
    }
}
