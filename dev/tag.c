
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
#include "kernel/concat.h"
#include "kernel/operators.h"
/**
 * Phalcon_Tag
 *
 * Phalcon_Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the request dispatcher. A valid dispatcher is required to generate absolute paths
 *
 * @param Phalcon_Dispatcher $dispatcher
 */
PHP_METHOD(Phalcon_Tag, setDispatcher){

	zval *dispatcher = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dispatcher) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("Phalcon_Tag"), SL("_dispatcher"), dispatcher TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Tag, _getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Tag"), SL("_dispatcher") TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r0, r1, "getdispatcher", PHALCON_NO_CHECK);
		phalcon_update_static_property(SL("Phalcon_Tag"), SL("_dispatcher"), r0 TSRMLS_CC);
	}
	PHALCON_OBSERVE_VAR(t1);
	phalcon_read_static_property(&t1, SL("Phalcon_Tag"), SL("_dispatcher") TSRMLS_CC);
	
	RETURN_CHECK_CTOR(t1);
}

/**
 * Assigns default values to generated tags by helpers
 *
 * 
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
	t0 = zend_read_static_property(phalcon_tag_ce, SL("_displayValues"), PHALCON_FETCH_CLASS_SILENT);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	phalcon_array_update(&t0, id, &value, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon_tag_ce"), SL("_displayValues"), t0 TSRMLS_CC);
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Alias of Phalcon_Tag::setDefault
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
	RETURN_DZVAL(r0);
}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using Phalcon_Tag::displayTo or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, getValue){

	zval *name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Tag"), SL("_displayValues") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, name, PHALCON_SILENT TSRMLS_CC);
	if (zend_is_true(t1)) {
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("Phalcon_Tag"), SL("_displayValues") TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, name, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_get_global(&g0, SL("_POST")+1 TSRMLS_CC);
		eval_int = phalcon_array_isset(g0, name);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc");
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, g0, name, PHALCON_NOISY TSRMLS_CC);
				
				RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				phalcon_array_fetch(&r2, g0, name, PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r3, "stripslashes", r2);
				RETURN_DZVAL(r3);
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
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_static_property(SL("Phalcon_Tag"), SL("_displayValues"), a0 TSRMLS_CC);
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
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *parameters = NULL, *text = NULL, *params = NULL, *action = NULL, *code = NULL, *value = NULL;
	zval *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
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
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &parameters, &text) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!text) {
		PHALCON_INIT_VAR(text);
		ZVAL_NULL(text);
	} else {
		PHALCON_SEPARATE_PARAM(text);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a0, text, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(action);
	ZVAL_STRING(action, "", 1);
	eval_int = phalcon_array_isset_long(params, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_long(&r0, params, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(action, r0);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_string(&r1, params, SL("action"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(action, r1);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("action")+1);
		}
	}
	
	PHALCON_INIT_VAR(text);
	ZVAL_STRING(text, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, params, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(text, r2);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("text")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, params, SL("text"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(text, r3);
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
			phalcon_array_update_string(&params, SL("onclick"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, params, SL("confirm"), PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, params, SL("onclick"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_SVSV(r4, "if(!confirm('", r5, "')) { return false; }; ", r6);
		phalcon_array_update_string(&params, SL("onclick"), &r4, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("confirm")+1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_STATIC_PARAMS_1(r8, "phalcon_utils", "geturl", action);
	PHALCON_CONCAT_SVS(r7, "<a href=\"", r8, "\" ");
	PHALCON_CPY_WRT(code, r7);
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
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_SVSVS(r9, " ", key, "=\"", value, "\" ");
			phalcon_concat_self(&code, r9 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_1;
		fee_9b93_1:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CONCAT_SVS(r10, ">", text, "</a>");
	phalcon_concat_self(&code, r10 TSRMLS_CC);
	
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
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
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
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("id"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_long(&params, 0, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, params, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id, r1);
	eval_int = phalcon_array_isset_string(params, SL("name")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, params, SL("name"), PHALCON_NOISY TSRMLS_CC);
		if (!zend_is_true(r2)) {
			phalcon_array_update_string(&params, SL("name"), &id, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, params, SL("value"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, r3);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getvalue", id);
		PHALCON_CPY_WRT(value, r4);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_SVSVSVS(r5, "<input type=\"", type, "\" id=\"", id, "\" value=\"", value, "\" ");
	PHALCON_CPY_WRT(code, r5);
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
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_VSVS(r6, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r6 TSRMLS_CC);
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
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "text", 1);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="password"] tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, passwordField){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "password", 1);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="hidden"] tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, hiddenField){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "hidden", 1);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="file"] tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, fileField){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "file", 1);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="check"] tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, checkField){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "checkbox", 1);
	PHALCON_CALL_SELF_PARAMS_2(r0, this_ptr, "_inputfield", c0, parameters);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * 
 *
 * @param array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *parameters = NULL, *params = NULL, *value = NULL, *code = NULL, *avalue = NULL;
	zval *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
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
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("value"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, r0);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, params, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(value, r1);
		} else {
			PHALCON_INIT_VAR(value);
			ZVAL_STRING(value, "", 1);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_SVS(r2, "<input type=\"submit\" value=\"", value, "\" ");
	PHALCON_CPY_WRT(code, r2);
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
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_VSVS(r3, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r3 TSRMLS_CC);
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
 * 
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
		PHALCON_INIT_VAR(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_tag_select", "select", parameters, data);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML SELECT tag using a Phalcon_Model resultset as options
 *
 * 
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
		PHALCON_INIT_VAR(data);
		ZVAL_NULL(data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon_tag_select", "select", parameters, data);
	RETURN_DZVAL(r0);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *parameters = NULL, *params = NULL, *id = NULL, *content = NULL, *code = NULL, *avalue = NULL;
	zval *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
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
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("id"), PHALCON_NOISY TSRMLS_CC);
		phalcon_array_update_long(&params, 0, &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, params, 0, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(id, r1);
	eval_int = phalcon_array_isset_string(params, SL("name")+1);
	if (!eval_int) {
		phalcon_array_update_string(&params, SL("name"), &id, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, params, SL("name"), PHALCON_NOISY TSRMLS_CC);
		if (!zend_is_true(r2)) {
			phalcon_array_update_string(&params, SL("name"), &id, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, params, SL("value"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(content, r3);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "getvalue", id);
		PHALCON_CPY_WRT(content, r4);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_SVS(r5, "<textarea id=\"", id, "\" ");
	PHALCON_CPY_WRT(code, r5);
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
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_VSVS(r6, key, "=\"", avalue, "\" ");
			phalcon_concat_self(&code, r6 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_4;
		fee_9b93_4:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_SVS(r7, ">", content, "</textarea>");
	phalcon_concat_self(&code, r7 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a HTML FORM tag
 *
 * 
 *
 * @param array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *parameters = NULL, *params = NULL, *dispatcher = NULL, *action_parameters = NULL;
	zval *action = NULL, *code = NULL, *avalue = NULL, *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *c0 = NULL;
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
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	PHALCON_CPY_WRT(dispatcher, r0);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, dispatcher, "getparams", PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_fast_join(r2, c0, r1 TSRMLS_CC);
	PHALCON_CPY_WRT(action_parameters, r2);
	eval_int = phalcon_array_isset_long(params, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(params, SL("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, params, SL("action"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(action, r3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, dispatcher, "getcontrollername", PHALCON_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CALL_METHOD(r6, dispatcher, "getactionname", PHALCON_NO_CHECK);
			PHALCON_CONCAT_VSV(r4, r5, "/", r6);
			PHALCON_CPY_WRT(action, r4);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_long(&r7, params, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(action, r7);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("method")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "post", 1);
		phalcon_array_update_string(&params, SL("method"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("confirm")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, params, SL("onsubmit"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_array_fetch_string(&r10, params, SL("onsubmit"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, params, SL("confirm"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_VSVS(r9, r10, ";if(!confirm(\"", r11, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, r8, r9 TSRMLS_CC);
		phalcon_array_update_string(&params, SL("onsubmit"), &r12, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_SEPARATE(params);
		phalcon_array_unset_string(params, SL("confirm")+1);
	}
	
	if (zend_is_true(action_parameters)) {
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CALL_STATIC_PARAMS_1(r13, "phalcon_utils", "geturl", action);
		PHALCON_CPY_WRT(action, r13);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_VSV(r15, action, "/", action_parameters);
		PHALCON_CALL_STATIC_PARAMS_1(r14, "phalcon_utils", "geturl", r15);
		PHALCON_CPY_WRT(action, r14);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch_string(&r17, params, SL("parameters"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_SV(r16, "?", r17);
		phalcon_concat_self(&action, r16 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_CONCAT_SVS(r18, "<form action=\"", action, "\" ");
	PHALCON_CPY_WRT(code, r18);
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
			PHALCON_INIT_VAR(r19);
			PHALCON_CONCAT_VSVS(r19, key, "= \"", avalue, "\" ");
			phalcon_concat_self(&code, r19 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_5;
		fee_9b93_5:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r20);
	PHALCON_CONCAT_VS(r20, code, ">");
	
	RETURN_CTOR(r20);
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

	phalcon_update_static_property(SL("Phalcon_Tag"), SL("_documentTitle"), title TSRMLS_CC);
	
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
	phalcon_read_static_property(&t0, SL("Phalcon_Tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, title TSRMLS_CC);
	phalcon_update_static_property(SL("Phalcon_Tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add before the title of view content
 *
 * @param string $title
 */
PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *title = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &title) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, title, t0);
	phalcon_update_static_property(SL("Phalcon_Tag"), SL("_documentTitle"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Get the title of view content
 *
 * @return string
 */
PHP_METHOD(Phalcon_Tag, getTitle){

	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("Phalcon_Tag"), SL("_documentTitle") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
	PHALCON_CONCAT_SVSV(r0, "<title>", t0, "</title>", t1);
	
	RETURN_CTOR(r0);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * 
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *parameters = NULL, *local = NULL, *params = NULL, *code = NULL, *value = NULL, *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
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
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a0, local, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&params, SL("href"), &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("href"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, params, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(local, r1);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, params, SL("local"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(local, r2);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/css", 1);
		phalcon_array_update_string(&params, SL("type"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, params, SL("href"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS_1(r3, "phalcon_utils", "geturl", r4);
		phalcon_array_update_string(&params, SL("href"), &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_SVSVS(r5, " ", key, "=\"", value, "\"");
			phalcon_concat_self(&code, r5 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_6;
		fee_9b93_6:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
	PHALCON_CONCAT_SV(r6, ">", t2);
	phalcon_concat_self(&code, r6 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

/**
 * Builds a SCRIPT[type="javascript"] tag
 *
 * 
 *
 * @param array $parameters
 * @param   boolean $local
 * @return string
 */
PHP_METHOD(Phalcon_Tag, javascriptInclude){

	zval *parameters = NULL, *local = NULL, *params = NULL, *code = NULL, *value = NULL, *key = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
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
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (!local) {
		PHALCON_INIT_VAR(local);
		ZVAL_BOOL(local, 1);
	} else {
		PHALCON_SEPARATE_PARAM(local);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a0, local, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&params, SL("src"), &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("src"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(local);
	ZVAL_STRING(local, "", 1);
	eval_int = phalcon_array_isset_long(params, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, params, 1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(local, r1);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, params, SL("local"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(local, r2);
			PHALCON_SEPARATE(params);
			phalcon_array_unset_string(params, SL("local")+1);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("type")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/javascript", 1);
		phalcon_array_update_string(&params, SL("type"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	if (zend_is_true(local)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, params, SL("src"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_STATIC_PARAMS_1(r3, "phalcon_utils", "geturl", r4);
		phalcon_array_update_string(&params, SL("src"), &r3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_SVSVS(r5, " ", key, "=\"", value, "\" ");
			phalcon_concat_self(&code, r5 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_9b93_7;
		fee_9b93_7:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
	PHALCON_CONCAT_SV(r6, "></script>", t2);
	phalcon_concat_self(&code, r6 TSRMLS_CC);
	
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
	zval *a0 = NULL;
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
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(params, a0);
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, params, 0, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update_string(&params, SL("src"), &r0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			phalcon_array_update_string(&params, SL("src"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, params, SL("src"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_STATIC_PARAMS_1(r1, "phalcon_utils", "geturl", r2);
	phalcon_array_update_string(&params, SL("src"), &r1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
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
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t1 TSRMLS_CC);
	PHALCON_CONCAT_SV(r4, ">", t1);
	phalcon_concat_self(&code, r4 TSRMLS_CC);
	
	RETURN_CTOR(code);
}

