
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

namespace Phalcon\Mvc\Model\Resultset;

/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */
class Simple extends Phalcon\Mvc\Model\Resultset
	implements Iterator, SeekableIterator, Countable, ArrayAccess, Serializable
{

	protected _model;

	protected _columnMap;

	protected _keepSnapshots = false;

	/**
	 * Phalcon\Mvc\Model\Resultset\Simple constructor
	 *
	 * @param array columnMap
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\Db\Result\Pdo result
	 * @param Phalcon\Cache\BackendInterface cache
	 * @param boolean keepSnapshots
	 */
	public function __construct(columnMap, <Phalcon\Mvc\ModelInterface> model,
		<Phalcon\Db\Result\Pdo> result, <Phalcon\Cache\BackendInterface> cache=null, keepSnapshots=null)
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
		result->setFetchMode(Phalcon\Db::FETCH_ASSOC);


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
	 * Check whether internal resource has rows to fetch
	 *
	 * @return boolean
	 */
	public function valid() -> boolean
	{
		var result, row, rows, hydrateMode, columnMap, activeRow;

		if this->_type {

			let result = this->_result;
			if typeof result == "object" {
				let row = result->$fetch(result);
			} else {
				let row = false;
			}
		} else {

			let rows = this->_rows;
			if typeof rows != "array" {
				let result = this->_result;
				if typeof result == "object" {
					let this->_rows = result->fetchAll();
				}
			}

			if typeof rows == "array" {
				let row = current(rows);
				if row !== false {
					next(rows);
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
		if hydrateMode == 0 {
			/**
			 * Set records as dirty state PERSISTENT by default
			 * Performs the standard hydration based on objects
			 */
			let activeRow = Phalcon\Mvc\Model::cloneResultMap(
				this->_model,
				row,
				columnMap,
				Phalcon\Mvc\Model::DIRTY_STATE_PERSISTENT,
				this->_keepSnapshots
			);
		} else {
			/**
			 * Other kinds of hydrations
			 */
			let activeRow = Phalcon\Mvc\Model::cloneResultMapHydrate(row, columnMap, hydrateMode);
		}

		let this->_activeRow = activeRow;
		return true;
	}

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does. Export the resultset to an array
	 * couldn't be faster with a large number of records
	 *
	 * @param boolean renameColumns
	 * @return array
	 */
	public function toArray(boolean renameColumns=true)
	{
		var result, activeRow, records, record, renamed, renamedKey,
			key, value, renamedRecords, columnMap;

		if this->_type {

			let result = this->_result;
			if typeof result == "object" {

				let activeRow = this->_activeRow;

				/**
				 * Check if we need to re-execute the query
				 */
				if activeRow !== null {
					result->execute();
				}

				/**
				 * We fetch all the results in memory
				 */
				let records = result->fetchAll();
			} else {
				let records = [];
			}

		} else {

			let records = this->_rows;
			if typeof records != "array" {
				let result = this->_result;
				if typeof result == "object" {

					let activeRow = this->_activeRow;

					/**
				 	 * Check if we need to re-execute the query
				 	 */
					if activeRow !== null {
						result->execute();
					}

					/**
					 * We fetch all the results in memory again
					 */
					let records = result->fetchAll(),
						this->_rows = records;

					/**
					 * Update the row count
					 */
					let this->_count = count(records);
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
						if fetch renamedKey, columnMap[key] {
							throw new Phalcon\Mvc\Model\Exception("Column '" . key . "' is not part of the column map");
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
	 *
	 * @return string
	 */
	public function serialize() -> string
	{

		/**
		 * Force to re-execute the query
		 */
		let this->_activeRow = false;

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
	 *
	 * @param string data
	 */
	public function unserialize(string! data)
	{
		var resultset;

		let this->_type = 0;

		let resultset = unserialize(data);
		if typeof resultset != "array" {
			throw new Phalcon\Mvc\Model\Exception("Invalid serialization data");
		}

		let this->_model = resultset["model"],
			this->_rows = resultset["rows"],
			this->_cache = resultset["cache"],
			this->_columnMap = resultset["columnMap"],
			this->_hydrateMode = resultset["hydrateMode"];
	}

}