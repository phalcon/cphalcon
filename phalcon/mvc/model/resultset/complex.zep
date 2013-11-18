
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
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */
class Complex extends Phalcon\Mvc\Model\Resultset implements Phalcon\Mvc\Model\ResultsetInterface
{
	protected _columnTypes;

	/**
	 * Phalcon\Mvc\Model\Resultset\Complex constructor
	 *
	 * @param array columnTypes
	 * @param Phalcon\Db\ResultInterface result
	 * @param Phalcon\Cache\BackendInterface cache
	 */
	public function __construct(var columnTypes, <Phalcon\Db\ResultInterface> result, <Phalcon\Cache\BackendInterface> cache=null)
	{
		/**
		 * Column types, tell the resultset how to build the result
		 */
		let this->_columnTypes = columnTypes;

		/**
		 * Valid resultsets are Phalcon\Db\ResultInterface instances
		 */
		let this->_result = result;

		/**
		 * Update the related cache if any
		 */
		if cache !== null {
			let this->_cache = cache;
		}

		/**
		 * Resultsets type 1 are traversed one-by-one
		 */
		let this->_type = 1;

		/**
		 * If the database result is an object, change it to fetch assoc
		 */
		if typeof result == "object" {
			result->setFetchMode(1);
		}
	}

	/**
	 * Check whether internal resource has rows to fetch
	 *
	 * @return boolean
	 */
	public function valid() -> boolean
	{
		var result, rows, row, underscore, emptyStr, hydrateMode,
			dirtyState, alias, activeRow, type, columnTypes,
			column, columnValue, value, attribute, source, attributes,
			columnMap, rowModel, keepSnapshots, sqlAlias;

		if this->_type {

			/**
			 * The result is bigger than 32 rows so it's retrieved one by one
			 */
			let result = this->_result;
			if result !== false {
				let row = result->$fetch(result);
			} else {
				let row = false;
			}
		} else {
			/**
			 * The full rows are dumped in this_ptr->rows
			 */
			let rows = this->_rows;
			if typeof rows == "array" {
				let row = current(rows);
				if typeof row == "object" {
					next(rows);
				}
			} else {
				let row = false;
			}
		}

		/**
		 * Valid records are arrays
		 */
		if typeof row == "object" || typeof row == "array" {

			/**
			 * The result type=1 so we need to build every row
			 */
			if this->_type {

				/**
				 * Get current hydration mode
				 */
				let hydrateMode = this->_hydrateMode;

				let underscore = "_", emptyStr = "";

				/**
				 * Each row in a complex result is a Phalcon\Mvc\Model\Row instance
				 */
				switch hydrateMode {
					case 0:
						let activeRow = new Phalcon\Mvc\Model\Row();
						break;
					case 1:
						let activeRow = [];
						break;
					case 2:
						let activeRow = new stdClass();
						break;
				}

				/**
				 * Create every record according to the column types
				 */
				let columnTypes = this->_columnTypes;

				/**
				 * Set records as dirty state PERSISTENT by default
				 */
				let dirtyState = 0;

				for alias, column in columnTypes {

					let type = column["type"];
					if typeof type == "object" {

						/**
						 * Object columns are assigned column by column
						 */
						let source = column["column"],
							attributes = column["attributes"],
							columnMap = column["columnMap"];

						/**
						 * Assign the values from the _source_attribute notation to its real column name
						 */
						let rowModel = [];
						for attribute in attributes {

							/**
							 * Columns are supposed to be in the form _table_field
							 */
							let columnValue = row[underscore . source . underscore. attribute], rowModel[attribute] = columnValue;
						}

						/**
						 * Generate the column value according to the hydration type
						 */
						switch hydrateMode {
							case 0:

								/**
								 * Check if the resultset must keep snapshots
								 */
								if !fetch keepSnapshots, column["keepSnapshots"] {
									let keepSnapshots = false;
								}

								/**
								 * Get the base instance
								 * Assign the values to the attributes using a column map
								 */
								let value = Phalcon\Mvc\Model::cloneResultMap(column["instance"], rowModel, columnMap, dirtyState, keepSnapshots);
								break;
							default:
								/**
				 				 * Other kinds of hydrations
				 				 */
								let value = Phalcon\Mvc\Model::cloneResultMapHydrate(rowModel, columnMap, hydrateMode);
								break;
						}

						/**
						 * The complete object is assigned to an attribute with the name of the alias or the model name
						 */
						let attribute = column["balias"];

					} else {

						/**
						 * Scalar columns are simply assigned to the result object
						 */
						if fetch sqlAlias, column["sqlAlias"] {
							let value = row[sqlAlias];
						} else {
							let value = row[alias];
						}

						/**
						 * If a "balias" is defined is not an unnamed scalar
						 */
						if isset column["balias"] {
							let attribute = alias;
						} else {
							let attribute = str_replace(underscore, "", alias);
						}
					}

					/**
					 * Assign the instance according to the hydration type
					 */
					switch hydrateMode {
						case 1:
							let activeRow[attribute] = value;
							break;
						default:
							let activeRow->{attribute} = value;
							break;
					}
				}

				/**
				 * Store the generated row in this_ptr->activeRow to be retrieved by 'current'
				 */
				let this->_activeRow = activeRow;
			} else {

				/**
				 * The row is already built so we just assign it to the activeRow
				 */
				let this->_activeRow = row;
			}

			return true;
		}

		/**
		 * There are no results to retrieve so we update this_ptr->activeRow as false
		 */
		let this->_activeRow = false;
		return false;
	}

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does.
	 *
	 * @return array
	 */
	public function toArray()
	{
		var records, current;
		let records = [];
		for current in iterator(this) {
			let records[] = current;
		}
		return records;
	}

	/**
	 * Serializing a resultset will dump all related rows into a big array
	 *
	 * @return string
	 */
	public function serialize()
	{
		var records, cache, columnTypes, hydrateMode, serialized;

		/**
		 * Obtain the records as an array
		 */
		let records = this->toArray();

		let cache = this->_cache,
			columnTypes = this->_columnTypes,
			hydrateMode = this->_hydrateMode;

		let serialized = serialize([
			"cache"       : cache,
			"rows"        : records,
			"columnTypes" : columnTypes,
			"hydrateMode" : hydrateMode
		]);

		/**
		 * Avoid return bad serialized data
		 */
		if typeof serialized != "string" {
			return null;
		}

		return serialized;
	}

	/**
	 * Unserializing a resultset will allow to only works on the rows present in the saved state
	 *
	 * @param string data
	 */
	public function unserialize(data)
	{
		var resultset;

		let this->_type = 0;

		let resultset = unserialize(data);
		if typeof resultset != "array" {
			throw new Phalcon\Mvc\Model\Exception("Invalid serialization data");
		}

		let this->_rows = resultset["rows"],
			this->_cache = resultset["cache"],
			this->_columnTypes = resultset["columnTypes"],
			this->_hydrateMode = resultset["hydrateMode"];
	}

}
