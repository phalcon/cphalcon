
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

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"

/**
 * Phalcon\Filter
 *
 * The Phalcon_Filter component provides a set of commonly needed data filters. It provides
 * object oriented wrappers to the php filter extension
 *
 *
 *
 */

/**
 * Sanizites a value with a specified single or set of filters
 *
 * @param  mixed $value
 * @param  mixed $filters
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, sanitize){

	zval *value = NULL, *filters = NULL, *silent = NULL, *new_value = NULL, *filter = NULL;
	zval *filter_value = NULL, *sanizited_value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &value, &filters, &silent) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!silent) {
		PHALCON_ALLOC_ZVAL_MM(silent);
		ZVAL_BOOL(silent, 0);
	}
	
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		PHALCON_CPY_WRT(new_value, value);
		if (Z_TYPE_P(value) != IS_NULL) {
			if (!phalcon_valid_foreach(filters TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(filters);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_e618_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_0;
				}
				
				PHALCON_INIT_VAR(filter);
				ZVAL_ZVAL(filter, *hd, 1, 0);
				PHALCON_INIT_VAR(filter_value);
				PHALCON_CALL_METHOD_PARAMS_3(filter_value, this_ptr, "_sanitize", new_value, filter, silent, PH_NO_CHECK);
				PHALCON_CPY_WRT(new_value, filter_value);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_0;
			fee_e618_0:
			if(0){}
			
		}
		
		
		RETURN_CCTOR(new_value);
	}
	
	PHALCON_INIT_VAR(sanizited_value);
	PHALCON_CALL_METHOD_PARAMS_3(sanizited_value, this_ptr, "_sanitize", value, filters, silent, PH_NO_CHECK);
	
	RETURN_CCTOR(sanizited_value);
}

/**
 * Internal sanizite wrapper to filter_var
 *
 * @param  mixed $value
 * @param  string $filter
 * @param  boolean $silent
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter, _sanitize){

	zval *value = NULL, *filter = NULL, *silent = NULL, *filtered = NULL, *exception_message = NULL;
	zval *exception = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &value, &filter, &silent) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!silent) {
		PHALCON_ALLOC_ZVAL_MM(silent);
		ZVAL_BOOL(silent, 0);
	}
	
	if (PHALCON_COMPARE_STRING(filter, "email")) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 517);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t0);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "int")) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 519);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t1);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "string")) {
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 513);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t2);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "float")) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 520);
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 4096);
		phalcon_array_update_string(&a0, SL("flags"), &t4, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_3(filtered, "filter_var", value, t3, a0);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "alphanum")) {
		PHALCON_INIT_VAR(filtered);
		phalcon_filter_alphanum(filtered, value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "extraspaces")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "trim", value);
		goto se_e618_1;
	}
	if (PHALCON_COMPARE_STRING(filter, "striptags")) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strip_tags", value);
		goto se_e618_1;
	}
	if (!zend_is_true(silent)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Sanitize filter ", filter, " is not supported");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	} else {
		PHALCON_CPY_WRT(filtered, value);
	}
	se_e618_1:
	
	RETURN_CCTOR(filtered);
}

