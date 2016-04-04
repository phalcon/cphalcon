
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework													  |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)	      |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled	  |
 | with this package in the file docs/LICENSE.txt.						  |
 |																		  |
 | If you did not receive a copy of the license and are unable to		  |
 | obtain it through the world-wide-web, please send an email			  |
 | to license@phalconphp.com so we can send you a copy immediately.	      |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>					  |
 |		  Eduar Carvajal <eduar@phalconphp.com>					          |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model\Resultset;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Cache\BackendInterface;
use ReflectionMethod;
use ReflectionException;
use Closure;
use ArrayObject;

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

	protected _realModel;

	protected _columnMap;

	protected _keepSnapshots = false;

	protected _fireAfterFetch = false;

	protected _closure = null;

	protected _keysDifference = null;

	protected _checkedRemoving = false;

	protected _needsRemoving = false;

	/**
	 * Phalcon\Mvc\Model\Resultset\Simple constructor
	 *
	 * @param array columnMap
	 * @param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
	 * @param \Phalcon\Db\Result\Pdo|null result
	 * @param \Phalcon\Cache\BackendInterface cache
	 * @param boolean keepSnapshots
	 * @param \Phalcon\Mvc\ModelInterface realModel
	 */
	public function __construct(var columnMap, var model, result, <BackendInterface> cache = null, keepSnapshots = null, var realModel = null, bool fireAfterFetch = false)
	{
		let this->_model = model,
			this->_columnMap = columnMap,
			this->_realModel = realModel,
			this->_fireAfterFetch = fireAfterFetch;

		/**
		 * Set if the returned resultset must keep the record snapshots
		 */
		let this->_keepSnapshots = keepSnapshots;

		parent::__construct(result, cache);
	}

	/**
	 * Returns current row in the resultset
	 */
	public final function current() -> <ModelInterface> | boolean
	{
		var row, hydrateMode, columnMap, activeRow, modelName, closure,
		countOriginal, countParsed, objectClosure, rowObject, key, value, arrayObject, arrayCopy, parsedKeys;

		let activeRow = this->_activeRow;
		if activeRow !== null {
			return activeRow;
		}

		/**
		 * Current row is set by seek() operations
		 */
		let row = this->_row;

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
		 * Get the resultset column map
		 */
		let columnMap = this->_columnMap;

		if this->_fireAfterFetch && (this->_model instanceof \Phalcon\Mvc\Model\Row || this->_model instanceof \stdclass) {
			if this->_closure == null {
				let closure = this->_getAfterFetchClosure(this->_realModel, false);
			}
			else {
				let closure = this->_closure; // if we already have closure use this closure
			}
			if closure != null {
				let rowObject = new \stdclass();
				for key, value in row {
					let rowObject->{key} = value;
				}
				let objectClosure = closure->bindTo(rowObject);
				{objectClosure}();
				let arrayObject = new ArrayObject(rowObject);
				let arrayCopy = arrayObject->getArrayCopy();
				if !this->_checkedRemoving {
					let this->_checkedRemoving = true;
					let parsedKeys = get_object_vars(rowObject);
					let countParsed = count(parsedKeys);
					let countOriginal = count(row);
					if countOriginal != countParsed {
						if this->_keysDifference == null {
							let this->_keysDifference = array_diff_key(arrayCopy,row);
							let this->_needsRemoving = true;
							// we can save some time by storing keys and then unset them instead of intersect each time
						}
					}
				}
				if this->_needsRemoving {
					for key, value in this->_keysDifference {
						unset(arrayCopy[key]);
					}
					let row = arrayCopy;
				}
				else {
					let row = arrayCopy;
				}
			}
		}

		/**
		 * Hydrate based on the current hydration
		 */
		switch hydrateMode {

			case Resultset::HYDRATE_RECORDS:

				/**
				 * Set records as dirty state PERSISTENT by default
				 * Performs the standard hydration based on objects
				 */
				if globals_get("orm.late_state_binding") {

					if this->_model instanceof \Phalcon\Mvc\Model {
						let modelName = get_class(this->_model);
					} else {
						let modelName = "Phalcon\\Mvc\\Model";
					}

					let activeRow = {modelName}::cloneResultMap(
						this->_model,
						row,
						columnMap,
						Model::DIRTY_STATE_PERSISTENT,
						this->_keepSnapshots
					);
				} else {
					let activeRow = Model::cloneResultMap(
						this->_model,
						row,
						columnMap,
						Model::DIRTY_STATE_PERSISTENT,
						this->_keepSnapshots
					);
				}
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
	 *
	 * @param bool removeAdditionalColumns
	 */
	public function toArray(boolean removeAdditionalColumns = false, boolean renameColumns = true) -> array
	{
		var result, records, renamedKey,
			key, value, parsedRecords, columnMap, closure,
			parsedRecord, countRecord, countParsedRecord, record, renamed, rowObject;

		/**
		 * If _rows is not present, fetchAll from database
		 * and keep them in memory for further operations
		 */
		let records = this->_rows;
		if typeof records != "array" {
			let result = this->_result;
			if this->_row !== null {
				// re-execute query if required and fetchAll rows
				result->execute();
			}
			let records = result->fetchAll();
			let this->_row = null;
			let this->_rows = records; // keep result-set in memory
		}

		/**
		 * We need to rename the whole set here, this could be slow
		 */
		if renameColumns {

			/**
			 * Get the resultset column map
			 */
			let columnMap = this->_columnMap;
			if typeof columnMap != "array" && !this->_fireAfterFetch {
				return records;
			}

			let parsedRecords = [];
			if typeof records == "array" {

				if this->_fireAfterFetch {
					if this->_closure != null {
						let closure = this->_closure;
					}
					else {
						let closure = this->_getAfterFetchClosure(this->_realModel, false);
					}
					if closure == null {
						let this->_fireAfterFetch = false;
						if typeof columnMap != "array" {
							return records;
						}
					}
				}

				for record in records {

					if typeof columnMap == "array" {
						let renamed = [];
						if this->_fireAfterFetch {
							let rowObject = new \stdclass();
						}
						for key, value in record {

							/**
							 * Check if the key is part of the column map
							 */
							if !fetch renamedKey, columnMap[key] {
								throw new Exception("Column '" . key . "' is not part of the column map");
							}

							if typeof renamedKey == "array" {

								if !fetch renamedKey, renamedKey[0] {
									throw new Exception("Column '" . key . "' is not part of the column map");
								}
							}

							let renamed[renamedKey] = value;
							if this->_fireAfterFetch {
								let rowObject->{renamedKey} = value;
							}
						}
						if !this->_fireAfterFetch {
							let parsedRecords[] = renamed;
						}
						else {
							let parsedRecord = this->_executeClosure(closure, rowObject);
							// check if afterFetch is adding new records to record, if yes then record original records
							if !this->_checkedRemoving {
								let this->_checkedRemoving = false;
								// we are just using count, i think it's enough and we don't need to use array_keys and compare result of each
								let countRecord = count(renamed);
								let countParsedRecord = count(parsedRecord);
								// if user wants te remove additional columns then remove them using array_intersect_key
								if countRecord != countParsedRecord {
									let this->_needsRemoving = true;
									if this->_keysDifference == null {
										let this->_keysDifference = array_diff_key(parsedRecord, renamed);
										// we can save some time by storing keys and then unset them instead of intersect each time
									}
								}
							}
							if removeAdditionalColumns && this->_needsRemoving {
								for key, value in this->_keysDifference {
									unset(parsedRecord[key]);
								}
							}
							let parsedRecords[] = parsedRecord;
						}
					}
					else {
						let parsedRecord = this->_executeClosure(closure, record);
						if !this->_checkedRemoving {
							let this->_checkedRemoving = false;
							// we are just using count, i think it's enough and we don't need to use array_keys and compare result of each
							let countRecord = count(record);
							let countParsedRecord = count(parsedRecord);
							// if user wants te remove additional columns then remove them using array_intersect_key
							if countRecord != countParsedRecord {
								let this->_needsRemoving = true;
								if this->_keysDifference == null {
									let this->_keysDifference = array_diff_key(parsedRecord, record);
									// we can save some time by storing keys and then unset them instead of intersect each time
								}
							}
						}
						if removeAdditionalColumns && this->_needsRemoving {
							for key,value in this->_keysDifference {
								unset(parsedRecord[key]);
							}
						}
						let parsedRecords[] = parsedRecord;
					}
				}
			}

			return parsedRecords;
		}

		return records;
	}

	private function _executeClosure(<Closure> closure, var record) -> array
	{
		var rowObject, objectClosure, arrayObject, arrayCopy, key, value;

		// for some odd reason casting (object)record is casting record to stdclass but it's also changing type record in function above
		if typeof record == "array" {
			let rowObject = new \stdclass();
			for key, value in record {
				let rowObject->{key} = value;
			}
		}
		else {
			let rowObject = record;
		}
		let objectClosure = closure->bindTo(rowObject);
		{objectClosure}();
		// in zephir casting object to array doesn't work, so we need to use ArrayObject, we could possibly save some time if we could just (array)rowObject
		let arrayObject = new ArrayObject(rowObject);
		let arrayCopy = arrayObject->getArrayCopy();
		return arrayCopy;
	}

	private function _getAfterFetchClosure(object realModel, bool fromEventsManager = false)
	{
		var e, reflectionMethod, eventsManager, realModelName, modelsManager, eventsManagerName, closure;
		try {
			if !fromEventsManager {
				let realModelName = get_class(realModel);
				let reflectionMethod = new ReflectionMethod(realModelName,"afterFetch");
				let closure = reflectionMethod->getClosure(realModel);
				let this->_closure = closure;
				return closure;
			}
			let modelsManager = realModel->getModelsManager();
			if typeof modelsManager == "object" {
				let eventsManager = modelsManager->getCustomEventsManager(realModel);
				if typeof eventsManager == "object" {
					let eventsManagerName = get_class(eventsManager);
					let reflectionMethod = new ReflectionMethod(eventsManagerName,"afterFetch");
					let closure = reflectionMethod->getClosure(eventsManager);
					let this->_closure = closure;
					return closure;
				}
				return null;
			}
			return null;
		}
		catch ReflectionException, e {
			if !fromEventsManager {
				return this->_getAfterFetchClosure(realModel, true);
			}
			return null;
		}
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
			"model"	   : this->_model,
			"cache"	   : this->_cache,
			"rows"		: this->toArray(false, false),
			"columnMap"   : this->_columnMap,
			"hydrateMode" : this->_hydrateMode,
			"realModel" : this->_realModel,
			"fireAfterFetch" : this->_fireAfterFetch,
			"closure" : this->_closure,
			"keysDifference" : this->_keysDifference,
			"checkedRemoving" : this->_checkedRemoving,
			"needsRemoving" : this->_needsRemoving
		]);
	}

	/**
	 * Unserializing a resultset will allow to only works on the rows present in the saved state
	 */
	public function unserialize(string! data) -> void
	{
		var resultset;

		let resultset = unserialize(data);
		if typeof resultset != "array" {
			throw new Exception("Invalid serialization data");
		}

		let this->_model = resultset["model"],
			this->_rows = resultset["rows"],
			this->_count = count(resultset["rows"]),
			this->_cache = resultset["cache"],
			this->_columnMap = resultset["columnMap"],
			this->_hydrateMode = resultset["hydrateMode"],
			this->_realModel = resultset["realModel"],
			this->_fireAfterFetch = resultset["fireAfterFetch"],
			this->_closure = resultset["closure"],
			this->_keysDifference = resultset["keysDifference"],
			this->_checkedRemoving = resultset["checkedRemoving"],
			this->_needsRemoving = resultset["needsRemoving"];
	}
}
