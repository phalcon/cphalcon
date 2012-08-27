
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
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\Resultset constructor
 *
 * @param Phalcon\Mvc\Model $model
 * @param Phalcon\Mvc\Model\Result $result
 * @param Phalcon\Cache\Backend $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct){

	zval *model = NULL, *result = NULL, *cache = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &model, &result, &cache) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!cache) {
		PHALCON_ALLOC_ZVAL_MM(cache);
		ZVAL_NULL(cache);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_model"), model TSRMLS_CC);
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
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid){

	zval *type = NULL, *result = NULL, *row = NULL, *model = NULL, *active_row = NULL, *rows = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zend_is_true(type)) {
		PHALCON_INIT_VAR(result);
		phalcon_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (Z_TYPE_P(result) != IS_BOOL || (Z_TYPE_P(result) == IS_BOOL && Z_BVAL_P(result))) {
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetcharray", result, PH_NO_CHECK);
			if (Z_TYPE_P(row) != IS_BOOL || (Z_TYPE_P(row) == IS_BOOL && Z_BVAL_P(row))) {
				PHALCON_INIT_VAR(model);
				phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(active_row);
				PHALCON_CALL_STATIC_PARAMS_2(active_row, "phalcon\\mvc\\model", "dumpresult", model, row);
				phalcon_update_property_zval(this_ptr, SL("_activeRow"), active_row TSRMLS_CC);
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			}
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
			phalcon_update_property_zval(this_ptr, SL("_activeRow"), row TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize){

	zval *records = NULL, *valid = NULL, *current = NULL, *cache = NULL, *data = NULL, *serialized = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(records);
	array_init(records);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rewind", PH_NO_CHECK);
	ws_c3ae_0:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "valid", PH_NO_CHECK);
		PHALCON_CPY_WRT(valid, r0);
		if (Z_TYPE_P(valid) != IS_BOOL || (Z_TYPE_P(valid) == IS_BOOL && !Z_BVAL_P(valid))) {
			goto we_c3ae_0;
		}
		PHALCON_INIT_VAR(current);
		PHALCON_CALL_METHOD(current, this_ptr, "current", PH_NO_CHECK);
		phalcon_array_append(&records, current, PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "next", PH_NO_CHECK);
		goto ws_c3ae_0;
	we_c3ae_0:
	
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
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize){

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

/**
 * Returns current row in the resultset
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current){

	zval *active_row = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(active_row);
	phalcon_read_property(&active_row, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	
	RETURN_CCTOR(active_row);
}

