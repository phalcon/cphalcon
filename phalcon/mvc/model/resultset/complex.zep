
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework													  |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)	   |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled	 |
 | with this package in the file docs/LICENSE.txt.						|
 |																		|
 | If you did not receive a copy of the license and are unable to		 |
 | obtain it through the world-wide-web, please send an email			 |
 | to license@phalconphp.com so we can send you a copy immediately.	   |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>					  |
 |		  Eduar Carvajal <eduar@phalconphp.com>						 |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model\Resultset;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\BackendInterface;
use Phalcon\Db\ResultInterface;
use Phalcon\Mvc\Model\Row;

/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */
class Complex extends Resultset implements ResultsetInterface
{
	protected _columnTypes;

	/**
	* Unserialised result-set hydrated all rows already. unserialise() sets _disableHydration to true
	*/
	protected _disableHydration = false;

	/**
	 * Phalcon\Mvc\Model\Resultset\Complex constructor
	 *
	 * @param array columnTypes
	 * @param Phalcon\Db\ResultInterface result
	 * @param Phalcon\Cache\BackendInterface cache
	 */
	public function __construct(var columnTypes, <\Phalcon\Db\ResultInterface> result = null, <BackendInterface> cache = null)
	{
		/**
		 * Column types, tell the resultset how to build the result
		 */
		let this->_columnTypes = columnTypes;

		parent::__construct(result, cache);
	}

	/**
	 * Returns current row in the resultset
	 */
	public final function current() -> <ModelInterface> | boolean
	{
		var row, hydrateMode,
			dirtyState, alias, activeRow, type, columnTypes,
			column, columnValue, value, attribute, source, attributes,
			columnMap, rowModel, keepSnapshots, sqlAlias;


		let activeRow = this->_activeRow;
		if activeRow !== null {
			return activeRow;
		}

		/**
		 * Current row is set by seek() operations
		 */
		let row = this->_row;

		/**
		 * Resultset was unserialized, we do not need to hydrate
		 */
		if this->_disableHydration {
			let this->_activeRow = row;
			return row;
		}

		/**
		 * Valid records are arrays
		 */
		if typeof row != "array" {
			let this->_activeRow = false;
			return false;
		}

		/**
		 * Get current hydration mode
		 */
		let hydrateMode = this->_hydrateMode;

		/**
		 * Each row in a complex result is a Phalcon\Mvc\Model\Row instance
		 */
		switch hydrateMode {

			case Resultset::HYDRATE_RECORDS:
				let activeRow = new Row();
				break;

			case Resultset::HYDRATE_ARRAYS:
				let activeRow = [];
				break;

			case Resultset::HYDRATE_OBJECTS:
			default:
				let activeRow = new \stdClass();
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

			if typeof column != "array" {
				throw new Exception("Column type is corrupt");
			}

			let type = column["type"];
			if type == "object" {

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
					let columnValue = row["_" . source . "_". attribute],
						rowModel[attribute] = columnValue;
				}

				/**
				 * Generate the column value according to the hydration type
				 */
				switch hydrateMode {

					case Resultset::HYDRATE_RECORDS:

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
						let value = Model::cloneResultMap(column["instance"], rowModel, columnMap, dirtyState, keepSnapshots);
						break;

					default:
						/**
		 				 * Other kinds of hydrations
		 				 */
						let value = Model::cloneResultMapHydrate(rowModel, columnMap, hydrateMode);
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
					fetch value, row[alias];
				}

				/**
				 * If a "balias" is defined is not an unnamed scalar
				 */
				if isset column["balias"] {
					let attribute = alias;
				} else {
					let attribute = str_replace("_", "", alias);
				}
			}

			/**
			 * Assign the instance according to the hydration type
			 */
			switch hydrateMode {

				case Resultset::HYDRATE_ARRAYS:
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
		return activeRow;
	}

	/**
	 * Returns a complete resultset as an array, if the resultset has a big number of rows
	 * it could consume more memory than currently it does.
	 */
	public function toArray() -> array
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
	 */
	public function serialize() -> string
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
			"cache"	      : cache,
			"rows"		  : records,
			"columnTypes" : columnTypes,
			"hydrateMode" : hydrateMode
		]);

		return serialized;
	}

	/**
	 * Unserializing a resultset will allow to only works on the rows present in the saved state
	 */
	public function unserialize(string! data) -> void
	{
		var resultset;

		/**
		* Rows are already hydrated
		*/
		let this->_disableHydration = true;

		let resultset = unserialize(data);
		if typeof resultset != "array" {
			throw new Exception("Invalid serialization data");
		}

		let this->_rows = resultset["rows"],
			this->_count = count(resultset["rows"]),
			this->_cache = resultset["cache"],
			this->_columnTypes = resultset["columnTypes"],
			this->_hydrateMode = resultset["hydrateMode"];
	}

}
