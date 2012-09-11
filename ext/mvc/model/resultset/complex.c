
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as the're required
 */

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array $columnsTypes
 * @param Phalcon\Db\Result $result
 * @param Phalcon\Cache\Backend $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct){

	zval *columns_types = NULL, *result = NULL, *cache = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &columns_types, &result, &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!cache) {
		PHALCON_ALLOC_ZVAL_MM(cache);
		ZVAL_NULL(cache);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_columnTypes"), columns_types TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_result"), result TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_type"), 1 TSRMLS_CC);
	if (Z_TYPE_P(result) != IS_BOOL || (Z_TYPE_P(result) == IS_BOOL && Z_BVAL_P(result))) {
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", c0, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid){

	zval *type = NULL, *result = NULL, *row = NULL, *rows = NULL, *active_row = NULL, *columns_types = NULL;
	zval *column = NULL, *alias = NULL, *source = NULL, *instance = NULL, *attributes = NULL;
	zval *model = NULL, *row_model = NULL, *attribute = NULL, *column_alias = NULL;
	zval *value = NULL, *model_attribute = NULL, *model_name = NULL, *n_alias = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
		PHALCON_INIT_VAR(result);
		phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (Z_TYPE_P(result) != IS_BOOL || (Z_TYPE_P(result) == IS_BOOL && Z_BVAL_P(result))) {
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetcharray", result, PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		PHALCON_INIT_VAR(rows);
		phalcon_read_property(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		Z_SET_ISREF_P(rows);
		
		PHALCON_INIT_VAR(row);
		PHALCON_CALL_FUNC_PARAMS_1(row, "current", rows);
		Z_UNSET_ISREF_P(rows);
		if (zend_is_true(row)) {
			Z_SET_ISREF_P(rows);
			PHALCON_CALL_FUNC_PARAMS_1_NORETURN("next", rows);
			Z_UNSET_ISREF_P(rows);
		}
	}
	
	if (Z_TYPE_P(row) != IS_BOOL || (Z_TYPE_P(row) == IS_BOOL && Z_BVAL_P(row))) {
		PHALCON_INIT_VAR(active_row);
		object_init_ex(active_row, phalcon_mvc_model_row_ce);
		
		PHALCON_INIT_VAR(columns_types);
		phalcon_read_property(&columns_types, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(columns_types TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(columns_types);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_2d8e_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_2d8e_0;
			}
			
			PHALCON_INIT_VAR(alias);
			PHALCON_GET_FOREACH_KEY(alias, ah0, hp0);
			PHALCON_INIT_VAR(column);
			ZVAL_ZVAL(column, *hd, 1, 0);
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
			if (PHALCON_COMPARE_STRING(type, "object")) {
				PHALCON_INIT_VAR(source);
				phalcon_array_fetch_string(&source, column, SL("column"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(instance);
				phalcon_array_fetch_string(&instance, column, SL("instance"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(attributes);
				phalcon_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(model);
				if (phalcon_clone(model, instance TSRMLS_CC) == FAILURE) {
					return;
				}
				
				PHALCON_INIT_VAR(row_model);
				array_init(row_model);
				if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
					return;
				}
				
				ah1 = Z_ARRVAL_P(attributes);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_2d8e_1:
					if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
						goto fee_2d8e_1;
					}
					
					PHALCON_INIT_VAR(attribute);
					ZVAL_ZVAL(attribute, *hd, 1, 0);
					PHALCON_INIT_VAR(column_alias);
					PHALCON_CONCAT_SVSV(column_alias, "_", source, "_", attribute);
					
					PHALCON_INIT_VAR(value);
					phalcon_array_fetch(&value, row, column_alias, PH_NOISY_CC);
					phalcon_array_update_zval(&row_model, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
					zend_hash_move_forward_ex(ah1, &hp1);
					goto fes_2d8e_1;
				fee_2d8e_1:
				
				PHALCON_INIT_VAR(model_attribute);
				PHALCON_CALL_STATIC_PARAMS_2(model_attribute, "phalcon\\mvc\\model", "dumpresult", model, row_model);
				
				PHALCON_INIT_VAR(model_name);
				phalcon_array_fetch_string(&model_name, column, SL("model"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(attribute);
				PHALCON_CALL_FUNC_PARAMS_1(attribute, "lcfirst", model_name);
				phalcon_update_property_zval_zval(active_row, attribute, model_attribute TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(value);
				phalcon_array_fetch(&value, row, alias, PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(column, SL("balias")+1);
				if (eval_int) {
					phalcon_update_property_zval_zval(active_row, alias, value TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(c0);
					ZVAL_STRING(c0, "_", 1);
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "", 1);
					PHALCON_INIT_VAR(n_alias);
					phalcon_fast_str_replace(n_alias, c0, c1, alias TSRMLS_CC);
					phalcon_update_property_zval_zval(active_row, n_alias, value TSRMLS_CC);
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_2d8e_0;
		fee_2d8e_0:
		
		phalcon_update_property_zval(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		phalcon_update_property_bool(this_ptr, SL("_activeRow"), 0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize){

	zval *records = NULL, *valid = NULL, *current = NULL, *cache = NULL, *data = NULL, *serialized = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(records);
	array_init(records);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PH_NO_CHECK);
	ws_2d8e_2:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "valid", PH_NO_CHECK);
		PHALCON_CPY_WRT(valid, r0);
		if (Z_TYPE_P(valid) != IS_BOOL || (Z_TYPE_P(valid) == IS_BOOL && !Z_BVAL_P(valid))) {
			goto we_2d8e_2;
		}
		PHALCON_INIT_VAR(current);
		PHALCON_CALL_METHOD(current, this_ptr, "current", PH_NO_CHECK);
		phalcon_array_append(&records, current, PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "next", PH_NO_CHECK);
		goto ws_2d8e_2;
	we_2d8e_2:
	
	PHALCON_INIT_VAR(cache);
	phalcon_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	phalcon_array_update_string(&data, SL("cache"), &cache, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&data, SL("rows"), &records, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
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

	zval *data = NULL, *resultset = NULL, *rows = NULL, *cache = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_long(this_ptr, SL("_type"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_FUNC_PARAMS_1(resultset, "unserialize", data);
	if (Z_TYPE_P(resultset) == IS_ARRAY) { 
		PHALCON_INIT_VAR(rows);
		phalcon_array_fetch_string(&rows, resultset, SL("rows"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_rows"), rows TSRMLS_CC);
		
		PHALCON_INIT_VAR(cache);
		phalcon_array_fetch_string(&cache, resultset, SL("cache"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_cache"), cache TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

