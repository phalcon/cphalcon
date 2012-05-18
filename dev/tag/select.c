
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

PHP_METHOD(Phalcon_Tag_Select, select){

	zval *parameters = NULL, *data = NULL, *params = NULL, *eol = NULL, *id = NULL, *value = NULL, *dummy_value = NULL;
	zval *dummy_text = NULL, *code = NULL, *avalue = NULL, *key = NULL, *close_option = NULL;
	zval *options = NULL, *using = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *p3[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
		ZVAL_NULL(data);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a0, data, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_CPY_WRT(eol, t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, params, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id, r0);
	eval_int = phalcon_array_isset_string(params, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC_PARAMS_1(r1, "phalcon_tag", "getvalue", id);
		PHALCON_CPY_WRT(value, r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, params, "value", strlen("value"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, r2);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, "value", strlen("value")+1);
	}
	eval_int = phalcon_array_isset_string(params, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_value);
		ZVAL_STRING(dummy_value, "", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, params, "dummyValue", strlen("dummyValue"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(dummy_value, r3);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(params, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_text);
		ZVAL_STRING(dummy_text, "Choose...", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, params, "dummyText", strlen("dummyText"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(dummy_text, r4);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, "dummyText", strlen("dummyText")+1);
	}
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "<select id=\"", id);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_VBOTH(r5, r6, "\" name=\"", id);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_RIGHT(r7, r5, "\"");
	PHALCON_CPY_WRT(code, r7);
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		if (phalcon_valid_foreach(params TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(params);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_9c31_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9c31_0;
			} else {
				PHALCON_INIT_VAR(key);
				hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(key, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(avalue);
			ZVAL_ZVAL(avalue, *hd, 1, 0);
			if (Z_TYPE_P(key) != IS_LONG) {
				if (Z_TYPE_P(avalue) != IS_ARRAY) { 
					PHALCON_INIT_VAR(r9);
					PHALCON_CONCAT_LEFT(r9, " ", key);
					PHALCON_INIT_VAR(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, "=\"", avalue);
					PHALCON_INIT_VAR(r10);
					PHALCON_CONCAT_RIGHT(r10, r8, "\"");
					PHALCON_INIT_VAR(r11);
					concat_function(r11, code, r10 TSRMLS_CC);
					PHALCON_CPY_WRT(code, r11);
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9c31_0;
			fee_9c31_0:
			if(0){ };
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_CONCAT_LEFT(r12, ">", eol);
	PHALCON_ALLOC_ZVAL_MM(r13);
	concat_function(r13, code, r12 TSRMLS_CC);
	PHALCON_CPY_WRT(code, r13);
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_LEFT(r14, "</option>", eol);
	PHALCON_CPY_WRT(close_option, r14);
	eval_int = phalcon_array_isset_string(params, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_LEFT(r16, "\t<option value=\"", dummy_value);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_VBOTH(r15, r16, "\">", dummy_text);
		PHALCON_ALLOC_ZVAL_MM(r17);
		concat_function(r17, r15, close_option TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r18);
		concat_function(r18, code, r17 TSRMLS_CC);
		PHALCON_CPY_WRT(code, r18);
	}
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r19);
		phalcon_array_fetch_long(&r19, params, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(options, r19);
	} else {
		PHALCON_CPY_WRT(options, data);
	}
	if (Z_TYPE_P(options) == IS_OBJECT) {
		eval_int = phalcon_array_isset_string(params, "using", strlen("using")+1);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_tag_exception_ce);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "The 'using' parameter is required", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		} else {
			PHALCON_ALLOC_ZVAL_MM(r20);
			phalcon_array_fetch_string(&r20, params, "using", strlen("using"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(using, r20);
			if (Z_TYPE_P(using) != IS_ARRAY) { 
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, phalcon_tag_exception_ce);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "The 'using' parameter should be an Array", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
				phalcon_throw_exception(i1 TSRMLS_CC);
				return;
			}
		}
		PHALCON_ALLOC_ZVAL_MM(r21);
		p3[0] = options;
		p3[1] = using;
		p3[2] = value;
		p3[3] = close_option;
		PHALCON_CALL_SELF_PARAMS(r21, this_ptr, "_optionsfromresultset", 4, p3);
		PHALCON_ALLOC_ZVAL_MM(r22);
		concat_function(r22, code, r21 TSRMLS_CC);
		PHALCON_CPY_WRT(code, r22);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_CALL_SELF_PARAMS_3(r23, this_ptr, "_optionsfromarray", options, value, close_option);
			PHALCON_ALLOC_ZVAL_MM(r24);
			concat_function(r24, code, r23 TSRMLS_CC);
			PHALCON_CPY_WRT(code, r24);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_tag_exception_ce);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "Invalid data provided to SELECT helper", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c2, PHALCON_CHECK);
			phalcon_throw_exception(i2 TSRMLS_CC);
			return;
		}
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, "</select>", 1);
	PHALCON_ALLOC_ZVAL_MM(r25);
	concat_function(r25, code, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(code, r25);
	PHALCON_RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset){

	zval *resultset = NULL, *using = NULL, *value = NULL, *close_option = NULL;
	zval *code = NULL, *option = NULL, *option_value = NULL, *option_text = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &resultset, &using, &value, &close_option) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	PHALCON_CALL_METHOD_NORETURN(resultset, "rewind", PHALCON_NO_CHECK);
	ws_9c31_1:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, resultset, "valid", PHALCON_NO_CHECK);
		if (!zend_is_true(r0)) {
			goto we_9c31_1;
		}
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, resultset, "current", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(option, r1);
		
		PHALCON_INIT_VAR(r2);
		
		PHALCON_INIT_VAR(r3);
		phalcon_array_fetch_long(&r3, using, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1(r2, option, "readattribute", r3, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(option_value, r2);
		
		PHALCON_INIT_VAR(r4);
		
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_long(&r5, using, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1(r4, option, "readattribute", r5, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(option_text, r4);
		
		PHALCON_INIT_VAR(r6);
		is_equal_function(r6, value, option_value TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_LEFT(r8, "\t<option selected=\"selected\" value=\"", option_value);
			PHALCON_INIT_VAR(r7);
			PHALCON_CONCAT_VBOTH(r7, r8, "\">", option_text);
			PHALCON_INIT_VAR(r9);
			concat_function(r9, r7, close_option TSRMLS_CC);
			PHALCON_INIT_VAR(r10);
			concat_function(r10, code, r9 TSRMLS_CC);
			PHALCON_CPY_WRT(code, r10);
		} else {
			PHALCON_INIT_VAR(r12);
			PHALCON_CONCAT_LEFT(r12, "\t<option value=\"", option_value);
			PHALCON_INIT_VAR(r11);
			PHALCON_CONCAT_VBOTH(r11, r12, "\">", option_text);
			PHALCON_INIT_VAR(r13);
			concat_function(r13, r11, close_option TSRMLS_CC);
			PHALCON_INIT_VAR(r14);
			concat_function(r14, code, r13 TSRMLS_CC);
			PHALCON_CPY_WRT(code, r14);
		}
		PHALCON_CALL_METHOD_NORETURN(resultset, "next", PHALCON_NO_CHECK);
		goto ws_9c31_1;
	we_9c31_1:
	if(0) { };
	PHALCON_RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray){

	zval *data = NULL, *value = NULL, *close_option = NULL, *code = NULL, *option_text = NULL;
	zval *option_value = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &data, &value, &close_option) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	if (phalcon_valid_foreach(data TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(data);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9c31_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9c31_2;
		} else {
			
			PHALCON_INIT_VAR(option_value);
			hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
			if (hash_type == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(option_value, hash_index, hash_index_len-1, 1);
			} else {
				if (hash_type == HASH_KEY_IS_LONG) {
					ZVAL_LONG(option_value, hash_num);
				}
			}
		}
		
		PHALCON_INIT_VAR(option_text);
		ZVAL_ZVAL(option_text, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, option_value, value TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_LEFT(r2, "\t<option selected=\"selected\" value=\"", option_value);
			PHALCON_INIT_VAR(r1);
			PHALCON_CONCAT_VBOTH(r1, r2, "\">", option_text);
			PHALCON_INIT_VAR(r3);
			concat_function(r3, r1, close_option TSRMLS_CC);
			PHALCON_INIT_VAR(r4);
			concat_function(r4, code, r3 TSRMLS_CC);
			PHALCON_CPY_WRT(code, r4);
		} else {
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_LEFT(r6, "\t<option value=\"", option_value);
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_VBOTH(r5, r6, "\">", option_text);
			PHALCON_INIT_VAR(r7);
			concat_function(r7, r5, close_option TSRMLS_CC);
			PHALCON_INIT_VAR(r8);
			concat_function(r8, code, r7 TSRMLS_CC);
			PHALCON_CPY_WRT(code, r8);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9c31_2;
		fee_9c31_2:
		if(0){ };
	}
	PHALCON_RETURN_CTOR(code);
}

