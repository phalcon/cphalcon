
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */


/**
 * Phalcon\Mvc\Model\Resultset\Simple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, mvc_model_resultset_simple, "phalcon\\mvc\\model\\resultset", phalcon_mvc_model_resultset_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_columnMap"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_resultset_simple_ce, SL("_keepSnapshots"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 5, zend_ce_iterator, spl_ce_SeekableIterator, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_serializable);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array $columnMap
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Db\Result\Pdo $result
 * @param Phalcon\Cache\BackendInterface $cache
 * @param boolean $keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct){

	zval *column_map, *model, *result, *cache = NULL, *keep_snapshots = NULL;
	zval *fetch_assoc, *limit, *row_count, *big_resultset;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &column_map, &model, &result, &cache, &keep_snapshots) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!cache) {
		PHALCON_INIT_VAR(cache);
	}
	
	if (!keep_snapshots) {
		PHALCON_INIT_VAR(keep_snapshots);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_result"), result TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_columnMap"), column_map TSRMLS_CC);
	if (Z_TYPE_P(result) != IS_OBJECT) {
		RETURN_MM_NULL();
	}
	
	/** 
	 * Use only fetch assoc
	 */
	PHALCON_INIT_VAR(fetch_assoc);
	ZVAL_LONG(fetch_assoc, 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_assoc);
	
	PHALCON_INIT_VAR(limit);
	ZVAL_LONG(limit, 32);
	
	PHALCON_INIT_VAR(row_count);
	PHALCON_CALL_METHOD(row_count, result, "numrows");
	
	/** 
	 * Check if it's a big resultset
	 */
	PHALCON_INIT_VAR(big_resultset);
	is_smaller_function(big_resultset, limit, row_count TSRMLS_CC);
	if (PHALCON_IS_TRUE(big_resultset)) {
		phalcon_update_property_long(this_ptr, SL("_type"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	}
	
	/** 
	 * Update the row-count
	 */
	phalcon_update_property_zval(this_ptr, SL("_count"), row_count TSRMLS_CC);
	
	/** 
	 * Set if the returned resultset must keep the record snapshots
	 */
	phalcon_update_property_zval(this_ptr, SL("_keepSnapshots"), keep_snapshots TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid){

	zval *type, *result = NULL, *row = NULL, *rows = NULL, *dirty_state, *hydrate_mode;
	zval *keep_snapshots, *column_map, *model, *active_row = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
	
		PHALCON_OBS_VAR(result);
		phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (Z_TYPE_P(result) == IS_OBJECT) {
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetch", result);
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		PHALCON_OBS_VAR(rows);
		phalcon_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) != IS_ARRAY) { 
	
			PHALCON_OBS_NVAR(result);
			phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				PHALCON_INIT_NVAR(rows);
				PHALCON_CALL_METHOD(rows, result, "fetchall");
				phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
			}
		}
	
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(row);
			phalcon_array_get_current(row, rows TSRMLS_CC);
			if (PHALCON_IS_NOT_FALSE(row)) {
				phalcon_array_next(rows);
			}
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}
	
	if (Z_TYPE_P(row) != IS_ARRAY) { 
		phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Set records as dirty state PERSISTENT by default
	 */
	PHALCON_INIT_VAR(dirty_state);
	ZVAL_LONG(dirty_state, 0);
	
	/** 
	 * Get current hydration mode
	 */
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	
	/** 
	 * Tell if the resultset is keeping snapshots
	 */
	PHALCON_OBS_VAR(keep_snapshots);
	phalcon_read_property_this(&keep_snapshots, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	
	/** 
	 * Get the resultset column map
	 */
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	
	/** 
	 * Hydrate based on the current hydration
	 */
	
	switch (phalcon_get_intval(hydrate_mode)) {
	
		case 0:
			/** 
			 * this_ptr->model is the base entity
			 */
			PHALCON_OBS_VAR(model);
			phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	
			/** 
			 * Performs the standard hydration based on objects
			 */
			PHALCON_INIT_VAR(active_row);
			PHALCON_CALL_STATIC_PARAMS_5(active_row, "phalcon\\mvc\\model", "cloneresultmap", model, row, column_map, dirty_state, keep_snapshots);
			break;
	
		default:
			/** 
			 * Other kinds of hydrations
			 */
			PHALCON_INIT_NVAR(active_row);
			PHALCON_CALL_STATIC_PARAMS_3(active_row, "phalcon\\mvc\\model", "cloneresultmaphydrate", row, column_map, hydrate_mode);
			break;
	
	}
	phalcon_update_property_zval(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
	RETURN_MM_TRUE;
}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 *
 * @param boolean $renameColumns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray){

	zval *rename_columns = NULL, *type, *result = NULL, *active_row = NULL;
	zval *records = NULL, *row_count, *column_map, *renamed_records;
	zval *record = NULL, *renamed = NULL, *value = NULL, *key = NULL, *exception_message = NULL;
	zval *renamed_key = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &rename_columns) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!rename_columns) {
		PHALCON_INIT_VAR(rename_columns);
		ZVAL_BOOL(rename_columns, 1);
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
	
		PHALCON_OBS_VAR(result);
		phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (Z_TYPE_P(result) == IS_OBJECT) {
	
			PHALCON_OBS_VAR(active_row);
			phalcon_read_property_this(&active_row, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	
			/** 
			 * Check if we need to re-execute the query
			 */
			if (Z_TYPE_P(active_row) != IS_NULL) {
				PHALCON_CALL_METHOD_NORETURN(result, "execute");
			}
	
			/** 
			 * We fetch all the results in memory
			 */
			PHALCON_INIT_VAR(records);
			PHALCON_CALL_METHOD(records, result, "fetchall");
		} else {
			PHALCON_INIT_NVAR(records);
			array_init(records);
		}
	} else {
		PHALCON_OBS_NVAR(records);
		phalcon_read_property_this(&records, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(records) != IS_ARRAY) { 
	
			PHALCON_OBS_NVAR(result);
			phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
	
				PHALCON_OBS_NVAR(active_row);
				phalcon_read_property_this(&active_row, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	
				/** 
				 * Check if we need to re-execute the query
				 */
				if (Z_TYPE_P(active_row) != IS_NULL) {
					PHALCON_CALL_METHOD_NORETURN(result, "execute");
				}
	
				/** 
				 * We fetch all the results in memory again
				 */
				PHALCON_INIT_NVAR(records);
				PHALCON_CALL_METHOD(records, result, "fetchall");
				phalcon_update_property_zval(this_ptr, SL("_rows"), records TSRMLS_CC);
	
				/** 
				 * Update the row count
				 */
				PHALCON_INIT_VAR(row_count);
				phalcon_fast_count(row_count, records TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_count"), row_count TSRMLS_CC);
			}
		}
	}
	
	/** 
	 * We need to rename the whole set here, this could be slow
	 */
	if (zend_is_true(rename_columns)) {
	
		/** 
		 * Get the resultset column map
		 */
		PHALCON_OBS_VAR(column_map);
		phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
		if (Z_TYPE_P(column_map) != IS_ARRAY) { 
			RETURN_CCTOR(records);
		}
	
		PHALCON_INIT_VAR(renamed_records);
		array_init(renamed_records);
	
		if (!phalcon_is_iterable(records, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(record);
	
			PHALCON_INIT_NVAR(renamed);
			array_init(renamed);
	
			if (!phalcon_is_iterable(record, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(key, ah1, hp1);
				PHALCON_GET_FOREACH_VALUE(value);
	
				/** 
				 * Check if the key is part of the column map
				 */
				if (!phalcon_array_isset(column_map, key)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", key, "' is not part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				/** 
				 * Get the renamed column
				 */
				PHALCON_OBS_NVAR(renamed_key);
				phalcon_array_fetch(&renamed_key, column_map, key, PH_NOISY_CC);
	
				/** 
				 * Add the value renamed
				 */
				phalcon_array_update_zval(&renamed, renamed_key, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
			/** 
			 * Append the renamed records to the main array
			 */
			phalcon_array_append(&renamed_records, renamed, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	
		RETURN_CTOR(renamed_records);
	}
	
	
	RETURN_CCTOR(records);
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize){

	zval *rename_columns, *records, *model, *cache;
	zval *column_map, *hydrate_mode, *data, *serialized;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(rename_columns);
	ZVAL_BOOL(rename_columns, 0);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_1(records, this_ptr, "toarray", rename_columns);
	
	PHALCON_OBS_VAR(model);
	phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	array_init_size(data, 5);
	phalcon_array_update_string(&data, SL("model"), &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("cache"), &cache, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("rows"), &records, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("columnMap"), &column_map, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("hydrateMode"), &hydrate_mode, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Force to re-execute the query
	 */
	phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
	
	/** 
	 * Serialize the cache using the serialize function
	 */
	PHALCON_INIT_VAR(serialized);
	PHALCON_CALL_FUNC_PARAMS_1(serialized, "serialize", data);
	RETURN_CCTOR(serialized);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize){

	zval *data, *resultset, *model, *rows, *cache, *column_map;
	zval *hydrate_mode;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_FUNC_PARAMS_1(resultset, "unserialize", data);
	if (Z_TYPE_P(resultset) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_OBS_VAR(model);
	phalcon_array_fetch_string(&model, resultset, SL("model"), PH_NOISY_CC);
	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
	
	PHALCON_OBS_VAR(rows);
	phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY_CC);
	phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
	
	PHALCON_OBS_VAR(cache);
	phalcon_array_fetch_string(&cache, resultset, SL("cache"), PH_NOISY_CC);
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_array_fetch_string(&column_map, resultset, SL("columnMap"), PH_NOISY_CC);
	phalcon_update_property_zval(this_ptr, SL("_columnMap"), column_map TSRMLS_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_array_fetch_string(&hydrate_mode, resultset, SL("hydrateMode"), PH_NOISY_CC);
	phalcon_update_property_zval(this_ptr, SL("_hydrateMode"), hydrate_mode TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

