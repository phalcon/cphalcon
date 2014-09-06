/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/resultset/simple.h"
#include "mvc/model/resultset.h"
#include "mvc/model/resultsetinterface.h"
#include "mvc/model/exception.h"
#include "mvc/model.h"

#include <ext/pdo/php_pdo_driver.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/variables.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains complete objects.
 * This class builds every complete object as it is required
 */
zend_class_entry *phalcon_mvc_model_resultset_simple_ce;

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize);
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_INFO(0, cache)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, renameColumns)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_resultset_simple_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, __construct, arginfo_phalcon_mvc_model_resultset_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, valid, arginfo_iterator_valid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, toArray, arginfo_phalcon_mvc_model_resultset_simple_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, serialize, arginfo_serializable_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, unserialize, arginfo_serializable_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Resultset\Simple initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

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
	zval *fetch_assoc, *limit, *row_count = NULL, *big_resultset;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 2, &column_map, &model, &result, &cache, &keep_snapshots);
	
	if (!cache) {
		cache = PHALCON_GLOBAL(z_null);
	}
	
	if (!keep_snapshots) {
		keep_snapshots = PHALCON_GLOBAL(z_null);
	}
	
	phalcon_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_columnMap"), column_map TSRMLS_CC);
	if (Z_TYPE_P(result) != IS_OBJECT) {
		RETURN_MM_NULL();
	}
	
	/** 
	 * Use only fetch assoc
	 */
	PHALCON_INIT_VAR(fetch_assoc);
	ZVAL_LONG(fetch_assoc, PDO_FETCH_ASSOC);
	PHALCON_CALL_METHOD(NULL, result, "setfetchmode", fetch_assoc);
	
	PHALCON_INIT_VAR(limit);
	ZVAL_LONG(limit, 32);
	
	PHALCON_CALL_METHOD(&row_count, result, "numrows");
	
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
	phalcon_update_property_this(this_ptr, SL("_count"), row_count TSRMLS_CC);
	
	/** 
	 * Set if the returned resultset must keep the record snapshots
	 */
	phalcon_update_property_this(this_ptr, SL("_keepSnapshots"), keep_snapshots TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether the internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid){

	zval *type, *result = NULL, *row = NULL, *rows = NULL, *dirty_state, *hydrate_mode;
	zval *keep_snapshots, *column_map, *model, *active_row = NULL;
        zend_class_entry *model_ce;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(type)) {
	
		PHALCON_OBS_VAR(result);
		phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(result) == IS_OBJECT) {
			PHALCON_CALL_METHOD(&row, result, "fetch", result);
		} else {
			PHALCON_INIT_VAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		PHALCON_OBS_VAR(rows);
		phalcon_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(rows) != IS_ARRAY) { 
	
			PHALCON_OBS_NVAR(result);
			phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				PHALCON_CALL_METHOD(&rows, result, "fetchall");
				phalcon_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
			}
		}
	
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(row);
			phalcon_array_get_current(row, rows);
			if (PHALCON_IS_NOT_FALSE(row)) {
				zend_hash_move_forward(Z_ARRVAL_P(rows));
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
	phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Tell if the resultset is keeping snapshots
	 */
	PHALCON_OBS_VAR(keep_snapshots);
	phalcon_read_property_this(&keep_snapshots, this_ptr, SL("_keepSnapshots"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Get the resultset column map
	 */
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY TSRMLS_CC);

	/** 
	 * Hydrate based on the current hydration
	 */
	switch (phalcon_get_intval(hydrate_mode)) {
	
		case 0:
			/** 
			 * this_ptr->model is the base entity
			 */
			PHALCON_OBS_VAR(model);
			phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);

			model_ce = Z_OBJCE_P(model);

			if (instanceof_function_ex(model_ce, phalcon_mvc_model_ce, 0 TSRMLS_CC)) {
	                        PHALCON_CALL_CE_STATIC(&active_row, model_ce, "cloneresultmap", model, row, column_map, dirty_state, keep_snapshots);
			} else {
				PHALCON_CALL_CE_STATIC(&active_row, phalcon_mvc_model_ce, "cloneresultmap", model, row, column_map, dirty_state, keep_snapshots);
			}
			break;
	
		default:
			/** 
			 * Other kinds of hydrations
			 */
			PHALCON_CALL_CE_STATIC(&active_row, phalcon_mvc_model_ce, "cloneresultmaphydrate", row, column_map, hydrate_mode);
			break;
	
	}
	phalcon_update_property_this(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
	RETURN_MM_TRUE;
}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than it currently does. Exporting the resultset to an array
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

	phalcon_fetch_params(1, 0, 1, &rename_columns);
	
	if (!rename_columns) {
		rename_columns = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(type)) {
	
		PHALCON_OBS_VAR(result);
		phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(result) == IS_OBJECT) {
	
			PHALCON_OBS_VAR(active_row);
			phalcon_read_property_this(&active_row, this_ptr, SL("_activeRow"), PH_NOISY TSRMLS_CC);
	
			/** 
			 * Check if we need to re-execute the query
			 */
			if (Z_TYPE_P(active_row) != IS_NULL) {
				PHALCON_CALL_METHOD(NULL, result, "execute");
			}
	
			/** 
			 * We fetch all the results in memory
			 */
			PHALCON_CALL_METHOD(&records, result, "fetchall");
		} else {
			PHALCON_INIT_NVAR(records);
			array_init(records);
		}
	} else {
		PHALCON_OBS_NVAR(records);
		phalcon_read_property_this(&records, this_ptr, SL("_rows"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(records) != IS_ARRAY) { 
	
			PHALCON_OBS_NVAR(result);
			phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
	
				PHALCON_OBS_NVAR(active_row);
				phalcon_read_property_this(&active_row, this_ptr, SL("_activeRow"), PH_NOISY TSRMLS_CC);
	
				/** 
				 * Check if we need to re-execute the query
				 */
				if (Z_TYPE_P(active_row) != IS_NULL) {
					PHALCON_CALL_METHOD(NULL, result, "execute");
				}
	
				/** 
				 * We fetch all the results in memory again
				 */
				PHALCON_CALL_METHOD(&records, result, "fetchall");
				phalcon_update_property_this(this_ptr, SL("_rows"), records TSRMLS_CC);
	
				/** 
				 * Update the row count
				 */
				PHALCON_INIT_VAR(row_count);
				phalcon_fast_count(row_count, records TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_count"), row_count TSRMLS_CC);
			}
			else {
				PHALCON_INIT_NVAR(records);
				array_init(records);
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
		phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(column_map) != IS_ARRAY) { 
			RETURN_CCTOR(records);
		}
	
		PHALCON_INIT_VAR(renamed_records);
		array_init(renamed_records);
		if (Z_TYPE_P(records) == IS_ARRAY) { 
	
			phalcon_is_iterable(records, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(record);
	
				PHALCON_INIT_NVAR(renamed);
				array_init(renamed);
	
				phalcon_is_iterable(record, &ah1, &hp1, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
					PHALCON_GET_HKEY(key, ah1, hp1);
					PHALCON_GET_HVALUE(value);
	
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
					phalcon_array_fetch(&renamed_key, column_map, key, PH_NOISY);
	
					/** 
					 * Add the value renamed
					 */
					phalcon_array_update_zval(&renamed, renamed_key, value, PH_COPY | PH_SEPARATE);
	
					zend_hash_move_forward_ex(ah1, &hp1);
				}
	
				/** 
				 * Append the renamed records to the main array
				 */
				phalcon_array_append(&renamed_records, renamed, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
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

	zval *rename_columns, *records = NULL, *model, *cache;
	zval *column_map, *hydrate_mode, *data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(rename_columns);
	ZVAL_BOOL(rename_columns, 0);
	
	PHALCON_CALL_METHOD(&records, this_ptr, "toarray", rename_columns);
	
	PHALCON_OBS_VAR(model);
	phalcon_read_property_this(&model, this_ptr, SL("_model"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_read_property_this(&column_map, this_ptr, SL("_columnMap"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(data);
	array_init_size(data, 5);
	phalcon_array_update_string(&data, SL("model"), model, PH_COPY);
	phalcon_array_update_string(&data, SL("cache"), cache, PH_COPY);
	phalcon_array_update_string(&data, SL("rows"), records, PH_COPY);
	phalcon_array_update_string(&data, SL("columnMap"), column_map, PH_COPY);
	phalcon_array_update_string(&data, SL("hydrateMode"), hydrate_mode, PH_COPY);
	
	/** 
	 * Force to re-execute the query
	 */
	phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
	
	/** 
	 * Serialize the cache using the serialize function
	 */
	phalcon_serialize(return_value, &data TSRMLS_CC);
	RETURN_MM();
}

/**
 * Unserializing a resultset only works on the rows present in the saved state
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize){

	zval *data, *resultset, *model, *rows, *cache, *column_map;
	zval *hydrate_mode;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(resultset);
	phalcon_unserialize(resultset, data TSRMLS_CC);
	if (Z_TYPE_P(resultset) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_OBS_VAR(model);
	phalcon_array_fetch_string(&model, resultset, SL("model"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	
	PHALCON_OBS_VAR(rows);
	phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
	
	PHALCON_OBS_VAR(cache);
	phalcon_array_fetch_string(&cache, resultset, SL("cache"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_map);
	phalcon_array_fetch_string(&column_map, resultset, SL("columnMap"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_columnMap"), column_map TSRMLS_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_array_fetch_string(&hydrate_mode, resultset, SL("hydrateMode"), PH_NOISY);
	phalcon_update_property_this(this_ptr, SL("_hydrateMode"), hydrate_mode TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}
