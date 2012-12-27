
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as the're required
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &columns_types, &result, &cache) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!cache) {
		PHALCON_INIT_VAR(cache);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_columnTypes"), columns_types TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_result"), result TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_type"), 1 TSRMLS_CC);
	if (PHALCON_IS_NOT_FALSE(result)) {
		PHALCON_INIT_VAR(fetch_assoc);
		ZVAL_LONG(fetch_assoc, 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_assoc);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid){

	zval *type = NULL, *result, *row = NULL, *rows, *underscore, *empty_str;
	zval *active_row, *columns_types, *column = NULL, *alias = NULL;
	zval *source = NULL, *instance = NULL, *attributes = NULL, *column_map = NULL;
	zval *row_model = NULL, *attribute = NULL, *column_alias = NULL, *value = NULL;
	zval *model_attribute = NULL, *sql_alias = NULL, *n_alias = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
	
		/** 
		 * The result is bigger than 32 rows so it's retrieved one by one
		 */
		PHALCON_OBS_VAR(result);
		phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (PHALCON_IS_NOT_FALSE(result)) {
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetch", result);
		} else {
			PHALCON_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		/** 
		 * The full rows are dumped in this_ptr->rows
		 */
		PHALCON_OBS_VAR(rows);
		phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_ARRAY) { 
			Z_SET_ISREF_P(rows);
			PHALCON_INIT_NVAR(row);
			PHALCON_CALL_FUNC_PARAMS_1(row, "current", rows);
			Z_UNSET_ISREF_P(rows);
			if (Z_TYPE_P(row) == IS_OBJECT) {
				Z_SET_ISREF_P(rows);
				PHALCON_CALL_FUNC_PARAMS_1_NORETURN("next", rows);
				Z_UNSET_ISREF_P(rows);
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
	
			PHALCON_INIT_VAR(underscore);
			ZVAL_STRING(underscore, "_", 1);
	
			PHALCON_INIT_VAR(empty_str);
			ZVAL_STRING(empty_str, "", 1);
	
			/** 
			 * Each row in a complex result is a Phalcon_Mvc_Model_Row instance
			 */
			PHALCON_INIT_VAR(active_row);
			object_init_ex(active_row, phalcon_mvc_model_row_ce);
	
			PHALCON_OBS_VAR(columns_types);
			phalcon_read_property(&columns_types, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	
			if (!phalcon_valid_foreach(columns_types TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(columns_types);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(alias, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(column);
	
				PHALCON_OBS_NVAR(type);
				phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
				if (PHALCON_COMPARE_STRING(type, "object")) {
	
					/** 
					 * Object columns are assigned column by column
					 */
					PHALCON_OBS_NVAR(source);
					phalcon_array_fetch_string(&source, column, SL("column"), PH_NOISY_CC);
	
					PHALCON_OBS_NVAR(instance);
					phalcon_array_fetch_string(&instance, column, SL("instance"), PH_NOISY_CC);
	
					PHALCON_OBS_NVAR(attributes);
					phalcon_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY_CC);
	
					PHALCON_OBS_NVAR(column_map);
					phalcon_array_fetch_string(&column_map, column, SL("columnMap"), PH_NOISY_CC);
	
					/** 
					 * Assign the values from the _source_attribute notation to its real column name
					 */
					PHALCON_INIT_NVAR(row_model);
					array_init(row_model);
	
					if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
						return;
					}
	
					ah1 = Z_ARRVAL_P(attributes);
					zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_FOREACH_VALUE(attribute);
	
						/** 
						 * Columns are supposed to be in the form _table_field
						 */
						PHALCON_INIT_NVAR(column_alias);
						PHALCON_CONCAT_VVVV(column_alias, underscore, source, underscore, attribute);
	
						PHALCON_OBS_NVAR(value);
						phalcon_array_fetch(&value, row, column_alias, PH_NOISY_CC);
						phalcon_array_update_zval(&row_model, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
					/** 
					 * Assign the values to the attributes using a column map
					 */
					PHALCON_INIT_NVAR(model_attribute);
					PHALCON_CALL_STATIC_PARAMS_3(model_attribute, "phalcon\\mvc\\model", "dumpresultmap", instance, row_model, column_map);
	
					/** 
					 * The complete object is assigned to an attribute with the name of the alias or
					 * the model name
					 */
					PHALCON_OBS_NVAR(attribute);
					phalcon_array_fetch_string(&attribute, column, SL("balias"), PH_NOISY_CC);
					phalcon_update_property_zval_zval(active_row, attribute, model_attribute TSRMLS_CC);
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
						phalcon_update_property_zval_zval(active_row, alias, value TSRMLS_CC);
					} else {
						PHALCON_INIT_NVAR(n_alias);
						phalcon_fast_str_replace(n_alias, underscore, empty_str, alias TSRMLS_CC);
						phalcon_update_property_zval_zval(active_row, n_alias, value TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			/** 
			 * Store the generated row in this_ptr->activeRow to be retrieved by 'current'
			 */
			phalcon_update_property_zval(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
		} else {
			/** 
			 * The row is already built so we just assign it to activeRecord
			 */
			phalcon_update_property_zval(this_ptr, SL("_activeRow"), row TSRMLS_CC);
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
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize){

	zval *records, *valid = NULL, *current = NULL, *cache, *column_types;
	zval *data, *serialized;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(records);
	array_init(records);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind");
	
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "valid");
		PHALCON_CPY_WRT(valid, r0);
		if (PHALCON_IS_NOT_FALSE(valid)) {
		} else {
			break;
		}
	
		PHALCON_INIT_NVAR(current);
		PHALCON_CALL_METHOD(current, this_ptr, "current");
		phalcon_array_append(&records, current, PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "next");
	}
	
	PHALCON_OBS_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(column_types);
	phalcon_read_property(&column_types, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	array_init_size(data, 3);
	phalcon_array_update_string(&data, SL("cache"), &cache, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("rows"), &records, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("columnTypes"), &column_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(serialized);
	PHALCON_CALL_FUNC_PARAMS_1(serialized, "serialize", data);
	
	RETURN_CCTOR(serialized);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize){

	zval *data, *resultset, *rows, *cache, *column_types;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_FUNC_PARAMS_1(resultset, "unserialize", data);
	if (Z_TYPE_P(resultset) == IS_ARRAY) { 
		PHALCON_OBS_VAR(rows);
		phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
	
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, resultset, SL("cache"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	
		PHALCON_OBS_VAR(column_types);
		phalcon_array_fetch_string(&column_types, resultset, SL("columnTypes"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_columnTypes"), column_types TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

