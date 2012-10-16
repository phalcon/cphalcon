
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
#include "kernel/operators.h"
#include "kernel/concat.h"
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

	zval *parameters, *data = NULL, *params = NULL, *eol, *id = NULL, *name, *value = NULL;
	zval *dummy_value = NULL, *dummy_text = NULL, *code, *avalue = NULL;
	zval *key = NULL, *close_option, *options = NULL, *using, *resultset_options = NULL;
	zval *array_options;
	zval *r0 = NULL;
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
		PHALCON_INIT_NVAR(data);
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
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(id);
		phalcon_array_fetch_string(&id, params, SL("id"), PH_NOISY_CC);
		phalcon_array_update_long(&params, 0, &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_NVAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(params, SS("name"));
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(name);
		phalcon_array_fetch_string(&name, params, SL("name"), PH_NOISY_CC);
		if (!zend_is_true(name)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SS("id"));
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("id"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("value"));
	if (!eval_int) {
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_STATIC_PARAMS_1(value, "phalcon\\tag", "getvalue", id);
	} else {
		PHALCON_INIT_NVAR(value);
		phalcon_array_fetch_string(&value, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SS("value"));
	}
	
	eval_int = phalcon_array_isset_string(params, SS("dummyValue"));
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_value);
		ZVAL_STRING(dummy_value, "", 1);
	} else {
		PHALCON_INIT_NVAR(dummy_value);
		phalcon_array_fetch_string(&dummy_value, params, SL("dummyValue"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SS("dummyValue"));
	}
	
	eval_int = phalcon_array_isset_string(params, SS("dummyText"));
	if (!eval_int) {
		PHALCON_INIT_VAR(dummy_text);
		ZVAL_STRING(dummy_text, "Choose...", 1);
	} else {
		PHALCON_INIT_NVAR(dummy_text);
		phalcon_array_fetch_string(&dummy_text, params, SL("dummyText"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SS("dummyText"));
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<select", 1);
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		
		if (!phalcon_valid_foreach(params TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(avalue);
			
			if (Z_TYPE_P(key) != IS_LONG) {
				if (Z_TYPE_P(avalue) != IS_ARRAY) { 
					PHALCON_SCONCAT_SVSVS(code, " ", key, "=\"", avalue, "\"");
				}
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_SCONCAT_SV(code, ">", eol);
	
	PHALCON_INIT_VAR(close_option);
	PHALCON_CONCAT_SV(close_option, "</option>", eol);
	eval_int = phalcon_array_isset_string(params, SS("useDummy"));
	if (eval_int) {
		PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", dummy_value, "\">", dummy_text, close_option);
	}
	
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(options);
		phalcon_array_fetch_long(&options, params, 1, PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(options, data);
	}
	
	if (Z_TYPE_P(options) == IS_OBJECT) {
		eval_int = phalcon_array_isset_string(params, SS("using"));
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
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_optionsfromresultset", 4, p0);
		PHALCON_CPY_WRT(resultset_options, r0);
		phalcon_concat_self(code, resultset_options TSRMLS_CC);
	} else {
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			PHALCON_INIT_VAR(array_options);
			PHALCON_CALL_SELF_PARAMS_3(array_options, this_ptr, "_optionsfromarray", options, value, close_option);
			phalcon_concat_self(code, array_options TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Invalid data provided to SELECT helper");
			return;
		}
	}
	
	phalcon_concat_self_str(code, SL("</select>") TSRMLS_CC);
	
	RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset){

	zval *resultset, *using, *value, *close_option;
	zval *code, *using_zero = NULL, *using_one = NULL, *option = NULL, *option_value = NULL;
	zval *option_text = NULL, *is_equals = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &resultset, &using, &value, &close_option) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	PHALCON_CALL_METHOD_NORETURN(resultset, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
		
		PHALCON_INIT_NVAR(r0);
		PHALCON_CALL_METHOD(r0, resultset, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_TRUE(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_NVAR(using_zero);
		phalcon_array_fetch_long(&using_zero, using, 0, PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(using_one);
		phalcon_array_fetch_long(&using_one, using, 1, PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(option);
		PHALCON_CALL_METHOD(option, resultset, "current", PH_NO_CHECK);
		
		PHALCON_INIT_NVAR(option_value);
		PHALCON_CALL_METHOD_PARAMS_1(option_value, option, "readattribute", using_zero, PH_NO_CHECK);
		
		PHALCON_INIT_NVAR(option_text);
		PHALCON_CALL_METHOD_PARAMS_1(option_text, option, "readattribute", using_one, PH_NO_CHECK);
		
		PHALCON_INIT_NVAR(is_equals);
		is_equal_function(is_equals, value, option_value TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equals)) {
			PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", option_value, "\">", option_text, close_option);
		} else {
			PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", option_value, "\">", option_text, close_option);
		}
		
		PHALCON_CALL_METHOD_NORETURN(resultset, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
	RETURN_CTOR(code);
}

PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray){

	zval *data, *value, *close_option, *code, *option_text = NULL;
	zval *option_value = NULL, *is_equals = NULL;
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
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_KEY(option_value, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(option_text);
		
		PHALCON_INIT_NVAR(is_equals);
		is_equal_function(is_equals, value, option_value TSRMLS_CC);
		if (PHALCON_IS_TRUE(is_equals)) {
			PHALCON_SCONCAT_SVSVV(code, "\t<option selected=\"selected\" value=\"", option_value, "\">", option_text, close_option);
		} else {
			PHALCON_SCONCAT_SVSVV(code, "\t<option value=\"", option_value, "\">", option_text, close_option);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	
	RETURN_CTOR(code);
}

