
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

#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the request dispatcher. A valid dispatcher is required to generate absolute paths
 *
 * @param Phalcon\Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Tag, setDispatcher){

	zval *dispatcher = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dispatcher) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dispatcher) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_tag_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VS(r0, dispatcher, " must be an Object");
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", r0, c0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_dispatcher"), dispatcher TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon\Dispatcher
 */
PHP_METHOD(Phalcon_Tag, _getDispatcher){

	zval *dispatcher = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(dispatcher);
	phalcon_read_static_property(&dispatcher, SL("phalcon\\tag"), SL("_dispatcher") TSRMLS_CC);
	if (!zend_is_true(dispatcher)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon\\controller\\front", "getinstance");
		PHALCON_INIT_VAR(dispatcher);
		PHALCON_CALL_METHOD(dispatcher, r0, "getdispatcher", PH_NO_CHECK);
		phalcon_update_static_property(SL("phalcon\\tag"), SL("_dispatcher"), dispatcher TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(dispatcher);
}

/**
 * Assigns default values to generated tags by helpers
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, setDefault){

	zval *id = NULL, *value = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &id, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (zend_is_true(value)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", value);
		if (!zend_is_true(r0)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_tag_exception_ce, "Only scalar values can be assigned to UI components");
			return;
		}
	}
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_update(&t0, id, &value, PH_COPY TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), t0 TSRMLS_CC);
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Alias of Phalcon\Tag::setDefault
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, displayTo){

	zval *id = NULL, *value = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &id, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "setdefault", id, value);
	RETURN_CTOR(r0);
}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon\Tag::setDefault or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue){

	zval *name = NULL, *display_values = NULL, *post = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *g0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(display_values);
	phalcon_read_static_property(&display_values, SL("phalcon\\tag"), SL("_displayValues") TSRMLS_CC);
	eval_int = phalcon_array_isset(display_values, name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, display_values, name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	} else {
		phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
		PHALCON_CPY_WRT(post, g0);
		eval_int = phalcon_array_isset(post, name);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC(r1, "get_magic_quotes_gpc");
			if (!zend_is_true(r1)) {
				PHALCON_ALLOC_ZVAL_MM(r2);
				phalcon_array_fetch(&r2, post, name, PH_NOISY_CC);
				
				RETURN_CCTOR(r2);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r3);
				phalcon_array_fetch(&r3, post, name, PH_NOISY_CC);
				PHALCON_ALLOC_ZVAL_MM(r4);
				PHALCON_CALL_FUNC_PARAMS_1(r4, "stripslashes", r3);
				RETURN_CTOR(r4);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resets the request and internal values to avoid those fields will have any default value
 */
PHP_METHOD(Phalcon_Tag, resetInput){

	zval *value = NULL, *key = NULL;
	zval *a0 = NULL;
	zval *g0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_displayValues"), a0 TSRMLS_CC);
	phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
	if (phalcon_valid_foreach(g0 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(g0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_0;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		phalcon_array_unset(g0, key);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_0;
		fee_9b93_0:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *parameters = NULL, *text = NULL, *params = NULL, *action = NULL, *code = NULL, *value = NULL;
	zval *key = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &text) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!text) {
		PHALCON_ALLOC_ZVAL_MM(text);
		ZVAL_NULL(text);
	} else {
		PHALCON_SEPARATE_PARAM(text);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, text, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(action);
	ZVAL_STRING(action, "", 1);
	eval_int = phalcon_array_isset_long(params, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(action);
		phalcon_array_fetch_long(&action, params, 0, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, params, SL("action"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("action")+1);
		}
	}
	
	PHALCON_INIT_VAR(text);
	ZVAL_STRING(text, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(text);
		phalcon_array_fetch_long(&text, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("text")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(text);
			phalcon_array_fetch_string(&text, params, SL("text"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("text")+1);
		}
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "", 1);
	eval_int = phalcon_array_isset_string(params, SL("confirm")+1);
	if (eval_int) {
		eval_int = phalcon_array_isset_string(params, SL("onclick")+1);
		if (!eval_int) {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("onclick"), &t0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("confirm"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("onclick"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVSV(r2, "if(!confirm('", r0, "')) { return false; }; ", r1);
		phalcon_array_update_string(&params, SL("onclick"), &r2, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("confirm")+1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_STATIC_PARAMS_1(r3, "phalcon\\utils", "geturl", action);
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<a href=\"", r3, "\" ");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_1;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_SVSVS(r4, " ", key, "=\"", value, "\" ");
			phalcon_concat_self(&code, r4 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_1;
		fee_9b93_1:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_SVS(r5, ">", text, "</a>");
	phalcon_concat_self(&code, r5 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds generic INPUT tags
 *
 * @param   string $type
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, _inputField){

	zval *type = NULL, *parameters = NULL, *params = NULL, *id = NULL, *value = NULL, *code = NULL;
	zval *avalue = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &type, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("id"), PH_NOISY_CC);
		phalcon_array_update_long(&params, 0, &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(params, SL("name")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("name"), PH_NOISY_CC);
		if (!zend_is_true(r1)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch_string(&value, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_SELF_PARAMS_1(value, this_ptr, "getvalue", id);
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVSVSVS(code, "<input type=\"", type, "\" id=\"", id, "\" value=\"", value, "\" ");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_2:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_2;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_VSVS(r2, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r2 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_2;
		fee_9b93_2:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *parameters = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "text", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML input[type="password"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, passwordField){

	zval *parameters = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "password", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, hiddenField){

	zval *parameters = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "hidden", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML input[type="file"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, fileField){

	zval *parameters = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "file", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML input[type="check"] tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, checkField){

	zval *parameters = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "checkbox", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *parameters = NULL, *params = NULL, *value = NULL, *code = NULL, *avalue = NULL;
	zval *key = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch_string(&value, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_long(&value, params, 0, PH_NOISY_CC);
		} else {
			PHALCON_INIT_VAR(value);
			ZVAL_STRING(value, "", 1);
		}
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<input type=\"submit\" value=\"", value, "\" ");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_3;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r0);
			PHALCON_CONCAT_VSVS(r0, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r0 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_3;
		fee_9b93_3:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	phalcon_concat_self(&code, t0 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a HTML SELECT tag using a PHP array for options
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *parameters = NULL, *data = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_ALLOC_ZVAL_MM(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon\\tag\\select", "selectfield", parameters, data);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML SELECT tag using a Phalcon_Model resultset as options
 *
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *parameters = NULL, *data = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!data) {
		PHALCON_ALLOC_ZVAL_MM(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon\\tag\\select", "selectfield", parameters, data);
	RETURN_CTOR(r0);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *parameters = NULL, *params = NULL, *id = NULL, *content = NULL, *code = NULL, *avalue = NULL;
	zval *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("id"), PH_NOISY_CC);
		phalcon_array_update_long(&params, 0, &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(id);
	phalcon_array_fetch_long(&id, params, 0, PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(params, SL("name")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("name"), PH_NOISY_CC);
		if (!zend_is_true(r1)) {
			phalcon_array_update_string(&params, SL("name"), &id, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(content);
		phalcon_array_fetch_string(&content, params, SL("value"), PH_NOISY_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		PHALCON_INIT_VAR(content);
		PHALCON_CALL_SELF_PARAMS_1(content, this_ptr, "getvalue", id);
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<textarea id=\"", id, "\" ");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_4:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_4;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r2);
			PHALCON_CONCAT_VSVS(r2, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r2 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_4;
		fee_9b93_4:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_SVS(r3, ">", content, "</textarea>");
	phalcon_concat_self(&code, r3 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a HTML FORM tag
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *parameters = NULL, *params = NULL, *dispatcher = NULL, *action_parameters = NULL;
	zval *action = NULL, *code = NULL, *avalue = NULL, *key = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(dispatcher);
	PHALCON_CALL_SELF(dispatcher, this_ptr, "_getdispatcher");
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, dispatcher, "getparams", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(action_parameters);
	phalcon_fast_join(action_parameters, c0, r0 TSRMLS_CC);
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(action);
			phalcon_array_fetch_string(&action, params, SL("action"), PH_NOISY_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_METHOD(r1, dispatcher, "getcontrollername", PH_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CALL_METHOD(r2, dispatcher, "getactionname", PH_NO_CHECK);
			PHALCON_INIT_VAR(action);
			PHALCON_CONCAT_VSV(action, r1, "/", r2);
		}
	} else {
		PHALCON_INIT_VAR(action);
		phalcon_array_fetch_long(&action, params, 0, PH_NOISY_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("method")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "post", 1);
		phalcon_array_update_string(&params, SL("method"), &t0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("confirm")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, params, SL("onsubmit"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, params, SL("onsubmit"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, params, SL("confirm"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_VSVS(r6, r4, ";if(!confirm(\"", r5, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL_MM(r7);
		concat_function(r7, r3, r6 TSRMLS_CC);
		phalcon_array_update_string(&params, SL("onsubmit"), &r7, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("confirm")+1);
	}
	
	if (zend_is_true(action_parameters)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CALL_STATIC_PARAMS_1(r8, "phalcon\\utils", "geturl", action);
		PHALCON_CPY_WRT(action, r8);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_VSV(r9, action, "/", action_parameters);
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CALL_STATIC_PARAMS_1(r10, "phalcon\\utils", "geturl", r9);
		PHALCON_CPY_WRT(action, r10);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, params, SL("parameters"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_SV(r12, "?", r11);
		phalcon_concat_self(&action, r12 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	PHALCON_CONCAT_SVS(code, "<form action=\"", action, "\" ");
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_5:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_5;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(avalue);
		ZVAL_ZVAL(avalue, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r13);
			PHALCON_CONCAT_VSVS(r13, key, "= \"", avalue, "\" ");
			phalcon_concat_self(&code, r13 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_5;
		fee_9b93_5:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_VS(r14, code, ">");
	
	RETURN_CTOR(r14);
}

/**
 * Builds a HTML close FORM tag
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, endForm){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("</form>", 1);
}

/**
 * Set the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, setTitle){

	zval *title = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), title TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add to title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *title = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, title TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add before the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *title = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, title, t0);
	phalcon_update_static_property(SL("phalcon\\tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Get the title of view content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitle){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant(SL("PHP_EOL"), t1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVSV(r0, "<title>", t0, "</title>", t1);
	
	RETURN_CTOR(r0);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *parameters = NULL, *local = NULL, *params = NULL, *code = NULL, *value = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &parameters, &local) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_ALLOC_ZVAL_MM(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, local, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("href"), &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("href"), &t0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/css", 1);
		phalcon_array_update_string(&params, SL("type"), &t1, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("href"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC_PARAMS_1(r2, "phalcon\\utils", "geturl", r1);
		phalcon_array_update_string(&params, SL("href"), &r2, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<link rel=\"stylesheet\"", 1);
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_6:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_6;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_SVSVS(r3, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, r3 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_6;
		fee_9b93_6:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant(SL("PHP_EOL"), t2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_SV(r4, ">", t2);
	phalcon_concat_self(&code, r4 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude){

	zval *parameters = NULL, *local = NULL, *params = NULL, *code = NULL, *value = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &parameters, &local) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_ALLOC_ZVAL_MM(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&params, local, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("src"), &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("src"), &t0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_INIT_VAR(local);
		phalcon_array_fetch_long(&local, params, 1, PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(local);
			phalcon_array_fetch_string(&local, params, SL("local"), PH_NOISY_CC);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/javascript", 1);
		phalcon_array_update_string(&params, SL("type"), &t1, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, params, SL("src"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC_PARAMS_1(r2, "phalcon\\utils", "geturl", r1);
		phalcon_array_update_string(&params, SL("src"), &r2, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<script", 1);
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_7;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_SVSVS(r3, " ", key, "=\"", value, "\" ");
			phalcon_concat_self(&code, r3 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_7;
		fee_9b93_7:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant(SL("PHP_EOL"), t2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_SV(r4, "></script>", t2);
	phalcon_concat_self(&code, r4 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *parameters = NULL, *params = NULL, *code = NULL, *value = NULL, *key = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(params);
		array_init(params);
		phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PH_NOISY_CC);
			phalcon_array_update_string(&params, SL("src"), &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("src"), &t0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, params, SL("src"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_STATIC_PARAMS_1(r2, "phalcon\\utils", "geturl", r1);
	phalcon_array_update_string(&params, SL("src"), &r2, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(code);
	ZVAL_STRING(code, "<img", 1);
	if (phalcon_valid_foreach(params TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_9b93_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_9b93_8;
		} else {
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		}
		PHALCON_INIT_VAR(value);
		ZVAL_ZVAL(value, *hd, 1, 0);
		if (Z_TYPE_P(key) != IS_LONG) {
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_SVSVS(r3, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, r3 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_8;
		fee_9b93_8:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant(SL("PHP_EOL"), t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_SV(r4, ">", t1);
	phalcon_concat_self(&code, r4 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

