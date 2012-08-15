
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Tag\Select
 *
 * Generates a SELECT html tag using an static array of values or a Phalcon\Model resultset
 */

/**
 * Generates a SELECT tag 
 *
 * @param array $parameters
 * @param array $data
 */
PHP_METHOD(Phalcon_Tag_Select, selectField){

	zval *parameters = NULL, *data = NULL, *params = NULL, *eol = NULL, *id = NULL, *value = NULL, *dummy_value = NULL;
	zval *dummy_text = NULL, *code = NULL, *avalue = NULL, *key = NULL, *close_option = NULL;
	zval *options = NULL, *using = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
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
		PHALCON_ALLOC_ZVAL_MM(data);
		ZVAL_NULL(data);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, data, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(eol);
	zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	
	PHALCON_INIT_VAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_STATIC_PARAMS_1(value, "phalcon\\tag", "getvalue", id);
	} else {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch_string(&value, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("dummyValue")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_value);
		ZVAL_STRING(dummy_value, "", 1);
	} else {
		PHALCON_INIT_VAR(dummy_value);
		phalcon_array_fetch_string(&dummy_value, params, SL("dummyValue"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("dummyValue")+1);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("dummyText")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_text);
		ZVAL_STRING(dummy_text, "Choose...", 1);
	} else {
		PHALCON_INIT_VAR(dummy_text);
		phalcon_array_fetch_string(&dummy_text, params, SL("dummyText"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("dummyText")+1);
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVSVS(code, "<select id=\"", id, "\" name=\"", id, "\"");
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(params TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9c31_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_9c31_0;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_INIT_VAR(avalue);
			ZVAL_ZVAL(avalue, *hd, 1, 0);
			if (Z_TYPE_P(key) != IS_LONG) {
				if (Z_TYPE_P(avalue) != IS_ARRAY) { 
					PHALCON_INIT_VAR(r0);
					PHALCON_CONCAT_SVSVS(r0, " ", key, "=\"", avalue, "\"");
					phalcon_concat_self(&code, r0 TSRMLS_CC);
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_9c31_0;
		fee_9c31_0:
		if(0){}
		
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CONCAT_SV(r1, ">", eol);
	phalcon_concat_self(&code, r1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(close_option);
	PHALCON_CONCAT_SV(close_option, "</option>", eol);
	eval_int = phalcon_array_isset_string(params, SL("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVSVV(r2, "\t<option value=\"", dummy_value, "\">", dummy_text, close_option);
		phalcon_concat_self(&code, r2 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(options);
		phalcon_array_fetch_long(&options, params, 1, PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(options, data);
	}
	
	if (Z_TYPE_P(options) == IS_OBJECT) {
		eval_int = phalcon_array_isset_string(params, SL("using")+1);
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "The 'using' parameter is required");
			return;
		} else {
			PHALCON_INIT_VAR(using);
			phalcon_array_fetch_string(&using, params, SL("using"), PH_NOISY_CC);
			if (Z_TYPE_P(using) != IS_ARRAY) { 
				PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "The 'using' parameter should be an Array");
				return;
			}
		}
		p0[0] = options;
		p0[1] = using;
		p0[2] = value;
		p0[3] = close_option;
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_SELF_PARAMS(r3, this_ptr, "_optionsfromresultset", 4, p0);
		phalcon_concat_self(&code, r3 TSRMLS_CC);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_SELF_PARAMS_3(r4, this_ptr, "_optionsfromarray", options, value, close_option);
			phalcon_concat_self(&code, r4 TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper");
			return;
		}
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "</select>", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset){

	zval *resultset = NULL, *using = NULL, *value = NULL, *close_option = NULL;
	zval *code = NULL, *option = NULL, *option_value = NULL, *option_text = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &resultset, &using, &value, &close_option) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	PHALCON_CALL_METHOD_NORETURN(resultset, "rewind", PH_NO_CHECK);
	ws_9c31_1:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, resultset, "valid", PH_NO_CHECK);
		if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0))) {
			goto we_9c31_1;
		}
		PHALCON_INIT_VAR(option);
		PHALCON_CALL_METHOD(option, resultset, "current", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch_long(&r1, using, 0, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(option_value);
		PHALCON_CALL_METHOD_PARAMS_1(option_value, option, "readattribute", r1, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_long(&r2, using, 1, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(option_text);
		PHALCON_CALL_METHOD_PARAMS_1(option_text, option, "readattribute", r2, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(r3);
		is_equal_function(r3, value, option_value TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_SVSVV(r4, "\t<option selected=\"selected\" value=\"", option_value, "\">", option_text, close_option);
			phalcon_concat_self(&code, r4 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_SVSVV(r5, "\t<option value=\"", option_value, "\">", option_text, close_option);
			phalcon_concat_self(&code, r5 TSRMLS_CC);
		}
		
		PHALCON_CALL_METHOD_NORETURN(resultset, "next", PH_NO_CHECK);
		goto ws_9c31_1;
	we_9c31_1:
	
	RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray){

	zval *data = NULL, *value = NULL, *close_option = NULL, *code = NULL, *option_text = NULL;
	zval *option_value = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
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
	if (!phalcon_valid_foreach(data TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(data);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_9c31_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9c31_2;
		}
		
		PHALCON_INIT_VAR(option_value);
		PHALCON_GET_FOREACH_KEY(option_value, ah0, hp0);
		PHALCON_INIT_VAR(option_text);
		ZVAL_ZVAL(option_text, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		is_equal_function(r0, option_value, value TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(r1);
			PHALCON_CONCAT_SVSVV(r1, "\t<option selected=\"selected\" value=\"", option_value, "\">", option_text, close_option);
			phalcon_concat_self(&code, r1 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_SVSVV(r2, "\t<option value=\"", option_value, "\">", option_text, close_option);
			phalcon_concat_self(&code, r2 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9c31_2;
	fee_9c31_2:
	if(0){}
	
	
	RETURN_CTOR(code);
}

