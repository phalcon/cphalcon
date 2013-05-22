
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
#include "kernel/string.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */


/**
 * Phalcon\Mvc\Model\Resultset\Complex initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, mvc_model_resultset_complex, "phalcon\\mvc\\model\\resultset", phalcon_mvc_model_resultset_complex_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("_columnTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_resultset_complex_ce TSRMLS_CC, 1, phalcon_mvc_model_resultsetinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array $columnsTypes
 * @param Phalcon\Db\ResultInterface $result
 * @param Phalcon\Cache\BackendInterface $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct){

	zval *columns_types, *result, *cache = NULL, *fetch_assoc;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &columns_types, &result, &cache);
	
	if (!cache) {
		PHALCON_INIT_VAR(cache);
	}
	
	/** 
	 * Column types, tell the resultset how to build the result
	 */
	phalcon_update_property_this(this_ptr, SL("_columnTypes"), columns_types TSRMLS_CC);
	
	/** 
	 * Valid resultsets are Phalcon\Db\ResultInterface instances
	 */
	phalcon_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	
	/** 
	 * Update the related cache if any
	 */
	if (Z_TYPE_P(cache) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	
	/** 
	 * Resultsets type 1 are traversed one-by-one
	 */
	phalcon_update_property_long(this_ptr, SL("_type"), 1 TSRMLS_CC);
	
	/** 
	 * If the database result is an object, change it to fetch assoc
	 */
	if (Z_TYPE_P(result) == IS_OBJECT) {
		PHALCON_INIT_VAR(fetch_assoc);
		ZVAL_LONG(fetch_assoc, 1);
		phalcon_call_method_p1_noret(result, "setfetchmode", fetch_assoc);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid){

	zval *type = NULL, *result, *row = NULL, *rows, *hydrate_mode, *underscore;
	zval *empty_str, *active_row = NULL, *columns_types;
	zval *dirty_state, *column = NULL, *alias = NULL, *source = NULL, *attributes = NULL;
	zval *column_map = NULL, *row_model = NULL, *attribute = NULL, *column_alias = NULL;
	zval *column_value = NULL, *keep_snapshots = NULL, *instance = NULL;
	zval *value = NULL, *sql_alias = NULL, *n_alias = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property_this(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
	
		/** 
		 * The result is bigger than 32 rows so it's retrieved one by one
		 */
		PHALCON_OBS_VAR(result);
		phalcon_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (PHALCON_IS_NOT_FALSE(result)) {
			PHALCON_INIT_VAR(row);
			phalcon_call_method_p1(row, result, "fetch", result);
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		/** 
		 * The full rows are dumped in this_ptr->rows
		 */
		PHALCON_OBS_VAR(rows);
		phalcon_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
	
			PHALCON_INIT_NVAR(row);
			phalcon_array_get_current(row, rows TSRMLS_CC);
			if (Z_TYPE_P(row) == IS_OBJECT) {
				phalcon_array_next(rows);
			}
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}
	
	/** 
	 * Valid records are arrays
	 */
	if (Z_TYPE_P(row) == IS_ARRAY || Z_TYPE_P(row) == IS_OBJECT) {
	
		/** 
		 * The result type=1 so we need to build every row
		 */
		if (zend_is_true(type)) {
	
			/** 
			 * Get current hydration mode
			 */
			PHALCON_OBS_VAR(hydrate_mode);
			phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(underscore);
			ZVAL_STRING(underscore, "_", 1);
	
			PHALCON_INIT_VAR(empty_str);
			ZVAL_STRING(empty_str, "", 1);
	
			/** 
			 * Each row in a complex result is a Phalcon\Mvc\Model\Row instance
			 */
	
			switch (phalcon_get_intval(hydrate_mode)) {
	
				case 0:
					PHALCON_INIT_VAR(active_row);
					object_init_ex(active_row, phalcon_mvc_model_row_ce);
					break;
	
				case 1:
					PHALCON_INIT_NVAR(active_row);
					array_init(active_row);
					break;
	
				case 2:
					PHALCON_INIT_NVAR(active_row);
					object_init(active_row);
					break;
	
			}
	
			/** 
			 * Create every record according to the column types
			 */
			PHALCON_OBS_VAR(columns_types);
			phalcon_read_property_this(&columns_types, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	
			/** 
			 * Set records as dirty state PERSISTENT by default
			 */
			PHALCON_INIT_VAR(dirty_state);
			ZVAL_LONG(dirty_state, 0);
	
			if (!phalcon_is_iterable(columns_types, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HKEY(alias, ah0, hp0);
				PHALCON_GET_HVALUE(column);
	
				PHALCON_OBS_NVAR(type);
				phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
				if (PHALCON_IS_STRING(type, "object")) {
	
					/** 
					 * Object columns are assigned column by column
					 */
					PHALCON_OBS_NVAR(source);
					phalcon_array_fetch_string(&source, column, SL("column"), PH_NOISY_CC);
	
					PHALCON_OBS_NVAR(attributes);
					phalcon_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY_CC);
	
					PHALCON_OBS_NVAR(column_map);
					phalcon_array_fetch_string(&column_map, column, SL("columnMap"), PH_NOISY_CC);
	
					/** 
					 * Assign the values from the _source_attribute notation to its real column name
					 */
					PHALCON_INIT_NVAR(row_model);
					array_init(row_model);
	
					if (!phalcon_is_iterable(attributes, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
						return;
					}
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_HVALUE(attribute);
	
						/** 
						 * Columns are supposed to be in the form _table_field
						 */
						PHALCON_INIT_NVAR(column_alias);
						PHALCON_CONCAT_VVVV(column_alias, underscore, source, underscore, attribute);
	
						PHALCON_OBS_NVAR(column_value);
						phalcon_array_fetch(&column_value, row, column_alias, PH_NOISY_CC);
						phalcon_array_update_zval(&row_model, attribute, &column_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
					/** 
					 * Generate the column value according to the hydration type
					 */
	
					switch (phalcon_get_intval(hydrate_mode)) {
	
						case 0:
							/** 
							 * Check if the resultset must keep snapshots
							 */
							if (phalcon_array_isset_string(column, SS("keepSnapshots"))) {
								PHALCON_OBS_NVAR(keep_snapshots);
								phalcon_array_fetch_string(&keep_snapshots, column, SL("keepSnapshots"), PH_NOISY_CC);
							} else {
								PHALCON_INIT_NVAR(keep_snapshots);
								ZVAL_BOOL(keep_snapshots, 0);
							}
	
							/** 
							 * Get the base instance
							 */
							PHALCON_OBS_NVAR(instance);
							phalcon_array_fetch_string(&instance, column, SL("instance"), PH_NOISY_CC);
	
							/** 
							 * Assign the values to the attributes using a column map
							 */
							PHALCON_INIT_NVAR(value);
							PHALCON_CALL_STATIC_PARAMS_5(value, "phalcon\\mvc\\model", "cloneresultmap", instance, row_model, column_map, dirty_state, keep_snapshots);
							break;
	
						default:
							/** 
							 * Other kinds of hydrations
							 */
							PHALCON_INIT_NVAR(value);
							PHALCON_CALL_STATIC_PARAMS_3(value, "phalcon\\mvc\\model", "cloneresultmaphydrate", row_model, column_map, hydrate_mode);
							break;
	
					}
	
					/** 
					 * The complete object is assigned to an attribute with the name of the alias or
					 * the model name
					 */
					PHALCON_OBS_NVAR(attribute);
					phalcon_array_fetch_string(&attribute, column, SL("balias"), PH_NOISY_CC);
				} else {
					/** 
					 * Scalar columns are simply assigned to the result object
					 */
					if (phalcon_array_isset_string(column, SS("sqlAlias"))) {
						PHALCON_OBS_NVAR(sql_alias);
						phalcon_array_fetch_string(&sql_alias, column, SL("sqlAlias"), PH_NOISY_CC);
	
						PHALCON_OBS_NVAR(value);
						phalcon_array_fetch(&value, row, sql_alias, PH_NOISY_CC);
					} else {
						PHALCON_OBS_NVAR(value);
						phalcon_array_fetch(&value, row, alias, PH_NOISY_CC);
					}
	
					/** 
					 * If a 'balias' is defined is not an unnamed scalar
					 */
					if (phalcon_array_isset_string(column, SS("balias"))) {
						PHALCON_CPY_WRT(attribute, alias);
					} else {
						PHALCON_INIT_NVAR(n_alias);
						phalcon_fast_str_replace(n_alias, underscore, empty_str, alias TSRMLS_CC);
						PHALCON_CPY_WRT(attribute, n_alias);
					}
				}
	
				/** 
				 * Assign the instance according to the hydration type
				 */
	
				switch (phalcon_get_intval(hydrate_mode)) {
	
					case 1:
						phalcon_array_update_zval(&active_row, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
						break;
	
					default:
						phalcon_update_property_zval_zval(active_row, attribute, value TSRMLS_CC);
						break;
	
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			/** 
			 * Store the generated row in this_ptr->activeRow to be retrieved by 'current'
			 */
			phalcon_update_property_this(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
		} else {
			/** 
			 * The row is already built so we just assign it to the activeRow
			 */
			phalcon_update_property_this(this_ptr, SL("_activeRow"), row TSRMLS_CC);
		}
		RETURN_MM_TRUE;
	}
	
	/** 
	 * There are no results to retrieve so we update this_ptr->activeRow as false
	 */
	phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
	RETURN_MM_FALSE;
}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray){

	zval *records, *valid = NULL, *current = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(records);
	array_init(records);
	phalcon_call_method_noret(this_ptr, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		phalcon_call_method(r0, this_ptr, "valid");
		PHALCON_CPY_WRT(valid, r0);
		if (PHALCON_IS_NOT_FALSE(valid)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(current);
		phalcon_call_method(current, this_ptr, "current");
		phalcon_array_append(&records, current, PH_SEPARATE TSRMLS_CC);
		phalcon_call_method_noret(this_ptr, "next");
	}
	
	RETURN_CTOR(records);
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize){

	zval *records, *cache, *column_types, *hydrate_mode;
	zval *data, *serialized;

	PHALCON_MM_GROW();

	/** 
	 * Obtain the records as an array
	 */
	PHALCON_INIT_VAR(records);
	phalcon_call_method(records, this_ptr, "toarray");
	
	PHALCON_OBS_VAR(cache);
	phalcon_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(column_types);
	phalcon_read_property_this(&column_types, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_read_property_this(&hydrate_mode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	array_init_size(data, 4);
	phalcon_array_update_string(&data, SL("cache"), &cache, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("rows"), &records, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("columnTypes"), &column_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("hydrateMode"), &hydrate_mode, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(serialized);
	phalcon_call_func_p1(serialized, "serialize", data);
	RETURN_CCTOR(serialized);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize){

	zval *data, *resultset, *rows, *cache, *column_types;
	zval *hydrate_mode;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(resultset);
	phalcon_call_func_p1(resultset, "unserialize", data);
	if (Z_TYPE_P(resultset) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_OBS_VAR(rows);
	phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY_CC);
	phalcon_update_property_this(this_ptr, SL("_rows"), rows TSRMLS_CC);
	
	PHALCON_OBS_VAR(cache);
	phalcon_array_fetch_string(&cache, resultset, SL("cache"), PH_NOISY_CC);
	phalcon_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
	PHALCON_OBS_VAR(column_types);
	phalcon_array_fetch_string(&column_types, resultset, SL("columnTypes"), PH_NOISY_CC);
	phalcon_update_property_this(this_ptr, SL("_columnTypes"), column_types TSRMLS_CC);
	
	PHALCON_OBS_VAR(hydrate_mode);
	phalcon_array_fetch_string(&hydrate_mode, resultset, SL("hydrateMode"), PH_NOISY_CC);
	phalcon_update_property_this(this_ptr, SL("_hydrateMode"), hydrate_mode TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

