
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
#include "kernel/array.h"
#include "kernel/concat.h"

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
	zval *r0 = NULL, *r1 = NULL;
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
			if (phalcon_valid_foreach(filters TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(filters);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_e618_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_e618_0;
				}
				PHALCON_INIT_VAR(filter);
				ZVAL_ZVAL(filter, *hd, 1, 0);
				PHALCON_INIT_VAR(r0);
				PHALCON_CALL_METHOD_PARAMS_3(r0, this_ptr, "_sanitize", new_value, filter, silent, PH_NO_CHECK);
				PHALCON_CPY_WRT(new_value, r0);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_e618_0;
				fee_e618_0:
				if(0){}
			} else {
				return;
			}
		}
		
		
		RETURN_CCTOR(new_value);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_3(r1, this_ptr, "_sanitize", value, filters, silent, PH_NO_CHECK);
	RETURN_CTOR(r1);
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

	zval *value = NULL, *filter = NULL, *silent = NULL, *filtered = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &value, &filter, &silent) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!silent) {
		PHALCON_ALLOC_ZVAL_MM(silent);
		ZVAL_BOOL(silent, 0);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "email", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, filter, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 517);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t1);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, "int", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, filter, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 519);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t3);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "string", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, filter, t4 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(t5);
		ZVAL_LONG(t5, 513);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_2(filtered, "filter_var", value, t5);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t6);
	ZVAL_STRING(t6, "float", 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, filter, t6 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 520);
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_INIT_VAR(t8);
		ZVAL_LONG(t8, 4096);
		phalcon_array_update_string(&a0, SL("flags"), &t8, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_3(filtered, "filter_var", value, t7, a0);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t9);
	ZVAL_STRING(t9, "alphanum", 1);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, filter, t9 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_INIT_VAR(filtered);
		phalcon_filter_alphanum(filtered, value);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t10);
	ZVAL_STRING(t10, "extraspaces", 1);
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_equal_function(r5, filter, t10 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "trim", value);
		goto se_e618_1;
	}
	PHALCON_INIT_VAR(t11);
	ZVAL_STRING(t11, "striptags", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, filter, t11 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(filtered);
		PHALCON_CALL_FUNC_PARAMS_1(filtered, "strip_tags", value);
		goto se_e618_1;
	}
	if (!zend_is_true(silent)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_SVS(r7, "Sanitize filter ", filter, " is not supported");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r7, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	} else {
		PHALCON_CPY_WRT(filtered, value);
	}
	se_e618_1:
	
	RETURN_CCTOR(filtered);
}

