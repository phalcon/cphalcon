
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

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\Model;
use Phalcon\Cache\BackendInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\ResultsetInterface;

/**
 * Phalcon\Mvc\Model\Resultset
 *
 * This component allows to Phalcon\Mvc\Model returns large resulsets with the minimum memory consumption
 * Resulsets can be traversed using a standard foreach or a while statement. If a resultset is serialized
 * it will dump all the rows into a big array. Then unserialize will retrieve the rows as they were before
 * serializing.
 *
 * <code>
 *
 * //Using a standard foreach
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as robot) {
 *  echo robot->name, "\n";
 * }
 *
 * //Using a while
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * $robots->rewind();
 * while ($robots->valid()) {
 *  $robot = $robots->current();
 *  echo $robot->name, "\n";
 *  $robots->next();
 * }
 * </code>
 *
 */
abstract class Resultset
	implements ResultsetInterface, \Iterator, \SeekableIterator, \Countable, \ArrayAccess, \Serializable
{

	protected _type = 0;

	protected _result;

	protected _cache;

	protected _isFresh = true;

	protected _pointer = -1;

	protected _count;

	protected _activeRow;

	protected _rows;

	protected _errorMessages;

	protected _hydrateMode = 0;

	const TYPE_RESULT_FULL = 0;

	const TYPE_RESULT_PARTIAL = 1;

	const HYDRATE_RECORDS = 0;

	const HYDRATE_OBJECTS = 2;

	const HYDRATE_ARRAYS = 1;

	/**
	 * Moves cursor to next row in the resultset
	 */
	public function next()
	{
		let this->_pointer++;
	}

	/**
	 * Gets pointer number of active row in the resultset
	 *
	 * @return int
	 */
	public function key()
	{
		return this->_pointer;
	}

	/**
	 * Rewinds resultset to its beginning
	 */
	public final function rewind()
	{
		var rows, result;

		if this->_type {

			/**
			 * Here, the resultset act as a result that is fetched one by one
			 */
			let result = this->_result;
			if result !== false {
				if this->_activeRow !== null {
					result->dataSeek(0);
				}
			}
		} else {

			/**
			 * Here, the resultset act as an array
			 */
			let rows = this->_rows;
			if rows === null {
				let result = this->_result;
				if typeof result == "object" {
					let rows = result->fetchAll(),
						this->_rows = rows;
				}
			}

			if typeof rows == "array" {
				reset(rows);
			}
		}

		let this->_pointer = 0;
	}

	/**
	 * Changes internal pointer to a specific position in the resultset
	 */
	public final function seek(int position)
	{
		var result, rows; int i;

		if this->_pointer != position {

			if this->_type {

				/**
				 * Here, the resultset act as a result that is fetched one by one
				 */
				let result = this->_result;
				if result !== false {
					result->dataSeek(position);
				}
			} else {

				/**
				 * Here, the resultset act as an array
				 */
				let rows = this->_rows;
				if rows === null {
					let result = this->_result;
					if typeof result == "object" {
						let rows = result->fetchAll(),
							this->_rows = rows;
					}
				}

				if typeof rows == "array" {
					let i = 0;
					reset(rows);
					while i < position {
						next(rows);
						let i++;
					}
				}
			}

			let this->_pointer = position;
		}
	}

	/**
	 * Counts how many rows are in the resultset
	 */
	public final function count() -> int
	{
		var count, result, rows;

		let count = this->_count;

		/**
		 * We only calculate the row number is it wasn't calculated before
		 */
		if typeof count === "null" {
			let count = 0;
			if this->_type {

				/**
				 * Here, the resultset act as a result that is fetched one by one
				 */
				let result = this->_result;
				if result !== false {
					let count = intval(result->numRows());
				}
			} else {

				/**
				 * Here, the resultset act as an array
				 */
				let rows = this->_rows;
				if rows === null {
					let result = this->_result;
					if typeof result == "object" {
						let rows = result->fetchAll(),
							this->_rows = rows;
					}
				}
				let count = count(rows);
			}
			let this->_count = count;
		}
		return count;
	}

	/**
	 * Checks whether offset exists in the resultset
	 */
	public function offsetExists(int index) -> boolean
	{
		return index < this->count();
	}

	/**
	 * Gets row in a specific position of the resultset
	 */
	public function offsetGet(int! index) -> <ModelInterface> | boolean
	{
		if index < this->count() {

			/**
			 * Check if the last record returned is the current requested
			 */
			if this->_pointer == index {
				return this->current();
			}

			/**
			 * Move the cursor to the specific position
			 */
			this->seek(index);

			/**
			 * Check if the last record returned is the requested
			 */
			if this->{"valid"}() !== false {
				return this->current();
			}

			return false;
		}
		throw new Exception("The index does not exist in the cursor");
	}

	/**
	 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 *
	 * @param int index
	 * @param Phalcon\Mvc\ModelInterface value
	 */
	public function offsetSet(var index, var value)
	{
		throw new Exception("Cursor is an immutable ArrayAccess object");
	}

	/**
	 * Resulsets cannot be changed. It has only been implemented to meet the definition of the ArrayAccess interface
	 */
	public function offsetUnset(int offset)
	{
		throw new Exception("Cursor is an immutable ArrayAccess object");
	}

	/**
	 * Returns the internal type of data retrieval that the resultset is using
	 */
	public function getType() -> int
	{
		return this->_type;
	}

	/**
	 * Get first row in the resultset
	 */
	public function getFirst() -> <ModelInterface> | boolean
	{
		/**
		 * Check if the last record returned is the current requested
		 */
		if this->_pointer == 0 {
			return this->current();
		}

		/**
		 * Otherwise re-execute the statement
		 */
		this->rewind();
		if this->{"valid"}() !== false {
			return this->current();
		}
		return false;
	}

	/**
	 * Get last row in the resultset
	 */
	public function getLast() -> <ModelInterface> | boolean
	{
		this->seek(this->count() - 1);
		if this->{"valid"}() !== false {
			return this->current();
		}
		return false;
	}

	/**
	 * Set if the resultset is fresh or an old one cached
	 */
	public function setIsFresh(boolean isFresh) -> <Resultset>
	{
		let this->_isFresh = isFresh;
		return this;
	}

	/**
	 * Tell if the resultset if fresh or an old one cached
	 */
	public function isFresh() -> boolean
	{
		return this->_isFresh;
	}

	/**
	 * Sets the hydration mode in the resultset
	 */
	public function setHydrateMode(int hydrateMode) -> <Resultset>
	{
		let this->_hydrateMode = hydrateMode;
		return this;
	}

	/**
	 * Returns the current hydration mode
	 */
	public function getHydrateMode() -> int
	{
		return this->_hydrateMode;
	}

	/**
	 * Returns the associated cache for the resultset
	 */
	public function getCache() -> <BackendInterface>
	{
		return this->_cache;
	}

	/**
	 * Returns current row in the resultset
	 */
	public final function current() -> <ModelInterface>
	{
		return this->_activeRow;
	}

	/**
	 * Returns the error messages produced by a batch operation
	 */
	public function getMessages() -> <\Phalcon\Mvc\Model\MessageInterface[]>
	{
		return this->_errorMessages;
	}

	/**
	 * Updates every record in the resultset
	 *
	 * @param array data
	 * @param Closure conditionCallback
	 * @return boolean
	 */
	public function update(var data, <\Closure> conditionCallback = null) -> boolean
	{
		boolean transaction;
		var record, connection = null;

		let transaction = false;
		for record in iterator(this) {

			if transaction === false {

				/**
				 * We only can update resultsets if every element is a complete object
				 */
				if !method_exists(record, "getWriteConnection") {
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
					continue;
				}
			}

			/**
			 * Try to update the record
			 */
			if !record->save(data) {

				/**
				 * Get the messages from the record that produce the error
				 */
				let this->_errorMessages = record->getMessages();

				/**
				 * Rollback the transaction
				 */
				connection->rollback();
				let transaction = false;
				break;
			}
		}

		/**
		 * Commit the transaction
		 */
		if transaction === true {
			connection->commit();
		}

		return true;
	}

	/**
	 * Deletes every record in the resultset
	 */
	public function delete(<\Closure> conditionCallback = null) -> boolean
	{
		boolean transaction;
		var record, connection = null;

		let transaction = false;
		for record in iterator(this) {

			if transaction === false {

				/**
				 * We only can delete resultsets if every element is a complete object
				 */
				if !method_exists(record, "getWriteConnection") {
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
				let this->_errorMessages = record->getMessages();

				/**
				 * Rollback the transaction
				 */
				connection->rollback();
				let transaction = false;
				break;
			}
		}

		/**
		 * Commit the transaction
		 */
		if transaction === true {
			connection->commit();
		}

		return true;
	}

	/**
	 * Filters a resultset returning only those the developer requires
	 *
	 *<code>
	 * $filtered = $robots->filter(function($robot){
	 *		if ($robot->id < 3) {
	 *			return $robot;
	 *		}
	 *	});
	 *</code>
	 *
	 * @param callback filter
	 * @return Phalcon\Mvc\Model[]
	 */
	public function filter(var filter) -> array
	{
		var records, record, parameters, processedRecord;

		let records = [],
			parameters = [];

		for record in iterator(this) {

			let parameters[0] = record,
				processedRecord = call_user_func_array(filter, parameters);

			/**
			 * Only add processed records to 'records' if the returned value is an array/object
			 */
			if typeof processedRecord != "object" {
				if typeof processedRecord != "array" {
					continue;
				}
			}

			let records[] = processedRecord;
		}

		return records;
	}
}
