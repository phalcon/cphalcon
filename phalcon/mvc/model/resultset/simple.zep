
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

namespace Phalcon\Mvc\Model\Resultset;

use Phalcon\Db;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */
class Simple extends Resultset
	implements \Iterator, \SeekableIterator, \Countable, \ArrayAccess, \Serializable
{

	protected _model;

	protected _columnMap;

	protected _keepSnapshots = false;

	/**
	 * Phalcon\Mvc\Model\Resultset\Simple constructor
	 *
	 * @param array columnMap
	 * @param Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
	 * @param Phalcon\Db\Result\Pdo|null result
	 * @param Phalcon\Cache\BackendInterface cache
	 * @param boolean keepSnapshots
	 */
	public function __construct(var columnMap, var model, result, <BackendInterface> cache = null, keepSnapshots = null)
	{
		var rowCount;

		let this->_model = model,
			this->_result = result,
			this->_cache = cache,
			this->_columnMap = columnMap;

		if typeof result != "object" {
			return;
		}

		/**
		 * Do the fetch using only associative indexes
		 */
		result->setFetchMode(Db::FETCH_ASSOC);

		let rowCount = result->numRows();

		/**
		 * Check if it's a big resultset
		 */
		if rowCount > 32 {
			let this->_type = 1;
		} else {
			let this->_type = 0;
		}

		/**
		 * Update the row-count
		 */
		let this->_count = rowCount;

		/**
		 * Set if the returned resultset must keep the record snapshots
		 */
		let this->_keepSnapshots = keepSnapshots;
	}

	/**
	 * Returns current row in the resultset
	 */
	public final function current() -> <ModelInterface> | boolean
	{
		var result, row, hydrateMode, columnMap, activeRow;
		
		let activeRow = this->_activeRow;
		if activeRow !== null {
			return activeRow;
		}

		/**
		 * Get current row
		 */
		if this->_type {
			/**
			 * Fetch from PDO one-by-one. Functions "next" and "seek" set this->_row
			 */
			let row = this->_row;
		} else {
			/**
			 * Fetch from array. Functions "next" and "seek" set this->_pointer
			 * We have to ensure this->_rows is populated
			 */
			if this->_rows === null {
				let result = this->_result;
				if typeof result == "object" {
					let this->_rows = result->fetchAll();
				}
			}

			if typeof this->_rows == "array" {
				if !fetch row, this->_rows[this->_pointer] {
					let row = false;
				}
			} else {
				let row = false;
			}
		}

		if typeof row != "array" {
			let this->_activeRow = false;
			return false;
		}

		/**
		 * Get current hydration mode
		 */
		let hydrateMode = this->_hydrateMode;

		/**
		 * Get the resultset column map
		 */
		let columnMap = this->_columnMap;		

		/**
		 * Hydrate based on the current hydration
		 */
		switch hydrateMode {

			case Resultset::HYDRATE_RECORDS:
				/**
				 * Set records as dirty state PERSISTENT by default
				 * Performs the standard hydration based on objects
				 */
				let activeRow = Model::cloneResultMap(
					this->_model,
					row,
					columnMap,
					Model::DIRTY_STATE_PERSISTENT,
					this->_keepSnapshots
				);
				break;

			default:
				/**
				 * Other kinds of hydrations
				 */
				let activeRow = Model::cloneResultMapHydrate(row, columnMap, hydrateMode);
				break;
		}

		let this->_activeRow = activeRow;
		return activeRow;
	}

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does. Export the resultset to an array
	 * couldn't be faster with a large number of records
	 */
	public function toArray(boolean renameColumns = true) -> array
	{
		var result, records, record, renamed, renamedKey,
			key, value, renamedRecords, columnMap;

		if this->_type {
			/**
			* Fetch from PDO one-by-one. For toArray we fetch all rows at once
			*/
			let result = this->_result;
			if typeof result == "object" {
				// re-execute query if required and fetchAll rows
				if this->_row !== null {
					result->execute();
				}
				let records = result->fetchAll();
				let this->_row = null; 
			} else {
				let records = [];
			}

		} else {
			/**
			 * Fetch from array. this->_rows is alreay our data-array we want to return
			 */
			let records = this->_rows;
			if typeof records != "array" {
				let result = this->_result;
				if typeof result == "object" {
					/**
					 * We fetch all the results in memory again
					 */
					let records = result->fetchAll(),
						this->_rows = records;
				} else {
					let records = [];
				}
			}
		}

		/**
		 * We need to rename the whole set here, this could be slow
		 */
		if renameColumns {

			/**
			 * Get the resultset column map
			 */
			let columnMap = this->_columnMap;
			if typeof columnMap != "array" {
				return records;
			}

			let renamedRecords = [];
			if typeof records == "array" {

				for record in records {

					let renamed = [];
					for key, value in record {

						/**
						 * Check if the key is part of the column map
						 */
						if !fetch renamedKey, columnMap[key] {
							throw new Exception("Column '" . key . "' is not part of the column map");
						}

						/**
						 * Add the value renamed
						 */
						let renamed[renamedKey] = value;
					}

					/**
					 * Append the renamed records to the main array
					 */
					let renamedRecords[] = renamed;
				}
			}

			return renamedRecords;
		}

		return records;
	}

	/**
	 * Serializing a resultset will dump all related rows into a big array
	 */
	public function serialize() -> string
	{
		/**
		 * Serialize the cache using the serialize function
		 */
		return serialize([
			"model"       : this->_model,
			"cache"       : this->_cache,
			"rows"        : this->toArray(false),
			"columnMap"   : this->_columnMap,
			"hydrateMode" : this->_hydrateMode
		]);
	}

	/**
	 * Unserializing a resultset will allow to only works on the rows present in the saved state
	 */
	public function unserialize(string! data) -> void
	{
		var resultset;

		/**
		 * Enable fetch by array
		 */
		let this->_type = 0;

		let resultset = unserialize(data);
		if typeof resultset != "array" {
			throw new Exception("Invalid serialization data");
		}

		let this->_model = resultset["model"],
			this->_rows = resultset["rows"],
			this->_cache = resultset["cache"],
			this->_columnMap = resultset["columnMap"],
			this->_hydrateMode = resultset["hydrateMode"];
	}
}
