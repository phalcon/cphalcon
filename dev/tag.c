
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Tag
 *
 * Phalcon_Tag is designed to simplify building of HTML tags.
 * It provides a set of helpers to generate HTML in a dynamic way.
 * This component is an abstract class that you can extend to add more helpers.
 */

/**
 * Sets the request dispatcher. A valid dispatcher is required to generated absolute paths
 *
 * @param Phalcon_Dispatcher $dipatcher
 */
PHP_METHOD(Phalcon_Tag, setDispatcher){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, v0 TSRMLS_CC);
	RETURN_NULL();
}

/**
 * Internally gets the request dispatcher
 *
 * @return Phalcon_Dispatcher
 */
PHP_METHOD(Phalcon_Tag, _getDispatcher){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r0, r1, "getdispatcher", PHALCON_CALL_DEFAULT);
		zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, r0 TSRMLS_CC);
	}
	t1 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
}

/**
 * Assigns values to tags
 *
 * 
 *
 * @param string $id
 * @param string $value
 */
PHP_METHOD(Phalcon_Tag, displayTo){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", v1, 0x044);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_tag_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Only scalar values can be assigned to UI components", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	PHALCON_ARRAY_UPDATE(t0, v0, v1);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, t0 TSRMLS_CC);
	
	RETURN_NULL();
}

/**
 * Every helper call this function to check whether a component has a predefined
 * value using Phalcon_Tag::displayTo or value from $_POST
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_Tag, _getValueFromAction){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval **gv0;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_array_fetch(t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		t2 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_array_fetch(t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_init_global("_POST" TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					a0 = *gv0;
				} else {
					PHALCON_ALLOC_ZVAL(a0);
					array_init(a0);
				}
			}
		}
		if (!a0) {
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
		}
		eval_int = phalcon_array_isset(a0, v0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", 0x045);
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch(r1, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r3);
				phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "stripslashes", r3, 0x046);
				RETURN_ZVAL(r2, 1, 0);
			}
		}
	}
	RETURN_NULL();
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_NULL(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "action", strlen("action")+1);
		}
	}
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_long(r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v1, r2);
	} else {
		eval_int = phalcon_array_isset_string(v0, "text", strlen("text")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "text", strlen("text"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT_PARAM(v1, r3);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "text", strlen("text")+1);
		}
	}
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_STRING(v3, "", 0);
	if (!PHALCON_COMPARE_STRING(v2, "")) {
		eval_int = phalcon_array_isset_string(v0, "confirm", strlen("confirm")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset_string(v0, "onclick", strlen("onclick")+1);
			if (!eval_int) {
				PHALCON_ALLOC_ZVAL(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_SEPARATE_PARAM(v0);
				phalcon_array_update_string(v0, "onclick", strlen("onclick"), t0 TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_array_fetch_string(r5, v0, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r6);
			PHALCON_CONCAT_LEFT(r6, "if(!confirm('", r5);
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_array_fetch_string(r7, v0, "onclick", strlen("onclick"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_CONCAT_VBOTH(r4, r6, "')) { return false; }; ", r7);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "onclick", strlen("onclick"), r4 TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
		}
		PHALCON_ALLOC_ZVAL(r8);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_STATIC_PARAMS(r8, "phalcon_utils", "geturl", 1, p0);
		PHALCON_ALLOC_ZVAL(r9);
		PHALCON_CONCAT_BOTH(r9,  "<a href=\"", r8, "\" ");
		PHALCON_CPY_WRT(v3, r9);
		FOREACH_KV(v0, ac0, fes76, fee76, ah0, hp0, v5, v4)
			if (Z_TYPE_P(v5) != IS_LONG) {
				PHALCON_INIT_RESULT(r11);
				PHALCON_CONCAT_LEFT(r11, " ", v5);
				PHALCON_INIT_RESULT(r10);
				PHALCON_CONCAT_VBOTH(r10, r11, "=\"", v4);
				PHALCON_INIT_RESULT(r12);
				PHALCON_CONCAT_RIGHT(r12, r10, "\" ");
				PHALCON_INIT_RESULT(r13);
				concat_function(r13, v3, r12 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r13);
			}
		END_FOREACH(ac0, fes76, fee76, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_CONCAT_BOTH(r14,  ">", v1, "</a>");
		PHALCON_ALLOC_ZVAL(r15);
		concat_function(r15, v3, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r15);
	}
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r4);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v1, r5);
	}
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_array_fetch_long(r8, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r9);
	PHALCON_CONCAT_LEFT(r9, "<input type=\"text\" id=\"", r8);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CONCAT_VBOTH(r7, r9, "\" value=\"", v1);
	PHALCON_ALLOC_ZVAL(r10);
	PHALCON_CONCAT_RIGHT(r10, r7, "\" ");
	PHALCON_CPY_WRT(v2, r10);
	FOREACH_KV(v0, ac0, fes77, fee77, ah0, hp0, v3, v1)
		if (Z_TYPE_P(v3) != IS_LONG) {
			PHALCON_INIT_RESULT(r11);
			PHALCON_CONCAT_VBOTH(r11, v3, "=\"", v1);
			PHALCON_INIT_RESULT(r12);
			PHALCON_CONCAT_RIGHT(r12, r11, "\" ");
			PHALCON_INIT_RESULT(r13);
			concat_function(r13, v2, r12 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r13);
		}
	END_FOREACH(ac0, fes77, fee77, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL(r14);
	concat_function(r14, v2, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r14);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, submitButton){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r0);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r1);
		} else {
			PHALCON_ALLOC_ZVAL(v1);
			ZVAL_STRING(v1, "", 0);
		}
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CONCAT_BOTH(r2,  "<input type=\"submit\" value=\"", v1, "\" ");
	PHALCON_CPY_WRT(v2, r2);
	FOREACH_KV(v0, ac0, fes78, fee78, ah0, hp0, v3, v1)
		if (Z_TYPE_P(v3) != IS_LONG) {
			PHALCON_INIT_RESULT(r3);
			PHALCON_CONCAT_VBOTH(r3, v3, "=\"", v1);
			PHALCON_INIT_RESULT(r4);
			PHALCON_CONCAT_RIGHT(r4, r3, "\" ");
			PHALCON_INIT_RESULT(r5);
			concat_function(r5, v2, r4 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r5);
		}
	END_FOREACH(ac0, fes78, fee78, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL(r6);
	concat_function(r6, v2, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r6);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Builds a HTML SELECT tag using an array for options
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
	}
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id=\"", r4);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CONCAT_VBOTH(r3, r5, "\" name=\"", r6);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CONCAT_RIGHT(r7, r3, "\" ");
	PHALCON_CPY_WRT(v3, r7);
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v4);
		ZVAL_STRING(v4, "@", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_string(r8, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r8);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "Choose...", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_array_fetch_string(r9, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r9);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	FOREACH_KV(v0, ac0, fes79, fee79, ah0, hp0, v7, v6)
		if (Z_TYPE_P(v7) != IS_LONG) {
			if (Z_TYPE_P(v6) != IS_ARRAY) { 
				PHALCON_INIT_RESULT(r10);
				PHALCON_CONCAT_VBOTH(r10, v7, "=\"", v6);
				PHALCON_INIT_RESULT(r11);
				PHALCON_CONCAT_RIGHT(r11, r10, "\" ");
				PHALCON_INIT_RESULT(r12);
				concat_function(r12, v3, r11 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r12);
			}
		}
	END_FOREACH(ac0, fes79, fee79, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r13);
	PHALCON_CONCAT_LEFT(r13, ">", t0);
	PHALCON_ALLOC_ZVAL(r14);
	concat_function(r14, v3, r13 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r14);
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		PHALCON_CONCAT_VBOTH(r17, t1, "<option value=\"", v4);
		PHALCON_ALLOC_ZVAL(r16);
		PHALCON_CONCAT_VBOTH(r16, r17, "\">", v5);
		PHALCON_ALLOC_ZVAL(t2);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_CONCAT_VBOTH(r15, r16, "</option>", t2);
		PHALCON_ALLOC_ZVAL(r18);
		concat_function(r18, v3, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r18);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "useDummy", strlen("useDummy")+1);
	}
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_array_fetch_long(r19, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r19) == IS_ARRAY) { 
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_array_fetch_long(r20, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			FOREACH_KV(r20, ac1, fes80, fee80, ah1, hp1, v9, v8)
				if (!r21) {
					PHALCON_ALLOC_ZVAL(r21);
				} else {
					if (Z_REFCOUNT_P(r21) > 1){ 
						PHALCON_SEPARATE(r21);
					}
				}
				is_equal_function(r21, v9, v2 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t3, IS_STRING);
				ZVAL_STRING(t3, "", 1);
				PHALCON_INIT_VARTYPE(r22, IS_BOOL);
				is_not_identical_function(r22, t3, v2 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(r23, IS_BOOL);
				phalcon_and_function(r23, r21, r22 TSRMLS_CC);
				if (zend_is_true(r23)) {
					PHALCON_INIT_VARTYPE(t4, IS_STRING);
					ZVAL_STRING(t4, "\t", 1);
					PHALCON_INIT_RESULT(r26);
					PHALCON_CONCAT_VBOTH(r26, t4, "<option value=\"", v9);
					PHALCON_INIT_RESULT(r25);
					PHALCON_CONCAT_VBOTH(r25, r26, "\" selected=\"selected\">", v8);
					PHALCON_INIT_VAR(t5);
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t5 TSRMLS_CC);
					PHALCON_INIT_RESULT(r24);
					PHALCON_CONCAT_VBOTH(r24, r25, "</option>", t5);
					PHALCON_INIT_RESULT(r27);
					concat_function(r27, v3, r24 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r27);
				} else {
					PHALCON_INIT_VARTYPE(t6, IS_STRING);
					ZVAL_STRING(t6, "\t", 1);
					PHALCON_INIT_RESULT(r30);
					PHALCON_CONCAT_VBOTH(r30, t6, "<option value=\"", v9);
					PHALCON_INIT_RESULT(r29);
					PHALCON_CONCAT_VBOTH(r29, r30, "\">", v8);
					PHALCON_INIT_VAR(t7);
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t7 TSRMLS_CC);
					PHALCON_INIT_RESULT(r28);
					PHALCON_CONCAT_VBOTH(r28, r29, "</option>", t7);
					PHALCON_INIT_RESULT(r31);
					concat_function(r31, v3, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r31);
				}
			END_FOREACH(ac1, fes80, fee80, ah1, hp1);
		} else {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_tag_exception_class_entry);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "Data supplied for Phalcon_Tag::selectStatic is not valid", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	}
	PHALCON_ALLOC_ZVAL(t8);
	ZVAL_STRING(t8, "</select>", 1);
	PHALCON_ALLOC_ZVAL(r32);
	concat_function(r32, v3, t8 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r32);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a HTML SELECT tag using a resultset as options
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, select){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL, *r52 = NULL, *r53 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p12[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
	}
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CONCAT_LEFT(r5, "<select id='", r4);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CONCAT_VBOTH(r3, r5, "' name='", r6);
	PHALCON_ALLOC_ZVAL(r7);
	PHALCON_CONCAT_RIGHT(r7, r3, "' ");
	PHALCON_CPY_WRT(v3, r7);
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		FOREACH_KV(v0, ac0, fes81, fee81, ah0, hp0, v4, v2)
			if (Z_TYPE_P(v4) != IS_LONG) {
				if (Z_TYPE_P(v2) != IS_ARRAY) { 
					PHALCON_INIT_RESULT(r8);
					PHALCON_CONCAT_VBOTH(r8, v4, "='", v2);
					PHALCON_INIT_RESULT(r9);
					PHALCON_CONCAT_RIGHT(r9, r8, "' ");
					PHALCON_INIT_RESULT(r10);
					concat_function(r10, v3, r9 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r10);
				}
			}
		END_FOREACH(ac0, fes81, fee81, ah0, hp0);
	}
	PHALCON_ALLOC_ZVAL(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r11);
	PHALCON_CONCAT_LEFT(r11, ">", t0);
	PHALCON_ALLOC_ZVAL(r12);
	concat_function(r12, v3, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r12);
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_array_fetch_string(r13, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r13);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v6);
		ZVAL_STRING(v6, "Choose...", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r14);
		phalcon_array_fetch_string(r14, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r14);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		PHALCON_CONCAT_VBOTH(r17, t1, "<option value=\"", v5);
		PHALCON_ALLOC_ZVAL(r16);
		PHALCON_CONCAT_VBOTH(r16, r17, "\">", v6);
		PHALCON_ALLOC_ZVAL(t2);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_CONCAT_VBOTH(r15, r16, "</option>", t2);
		PHALCON_ALLOC_ZVAL(r18);
		concat_function(r18, v3, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r18);
	}
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_array_fetch_long(r19, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r19)) {
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_array_fetch_long(r20, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r20) == IS_OBJECT) {
				eval_int = phalcon_array_isset_string(v0, "using", strlen("using")+1);
				if (!eval_int) {
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_tag_exception_class_entry);
					PHALCON_ALLOC_ZVAL(p1[0]);
					ZVAL_STRING(p1[0], "The 'using' parameter is required", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				} else {
					PHALCON_ALLOC_ZVAL(r21);
					phalcon_array_fetch_string(r21, v0, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r21) != IS_ARRAY) { 
						PHALCON_ALLOC_ZVAL(i1);
						object_init_ex(i1, phalcon_tag_exception_class_entry);
						PHALCON_ALLOC_ZVAL(p2[0]);
						ZVAL_STRING(p2[0], "The 'using' parameter should be an Array", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				}
				PHALCON_ALLOC_ZVAL(r22);
				phalcon_array_fetch_string(r22, v0, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v7, r22);
				PHALCON_ALLOC_ZVAL(r23);
				phalcon_array_fetch_long(r23, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, r23);
				PHALCON_CALL_METHOD_NORETURN(v8, "rewind", PHALCON_CALL_DEFAULT);
				ws82:
				PHALCON_ALLOC_ZVAL(r24);
				PHALCON_CALL_METHOD(r24, v8, "valid", PHALCON_CALL_DEFAULT);
				if (!zend_is_true(r24)) {
					goto we82;
				}
				PHALCON_INIT_RESULT(r25);
				PHALCON_CALL_METHOD(r25, v8, "current", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v9, r25);
				PHALCON_INIT_RESULT(r26);
				PHALCON_INIT_RESULT(r27);
				phalcon_array_fetch_long(r27, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r27);
				p6[0] = r27;
				PHALCON_CALL_METHOD_PARAMS(r26, v9, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				if (!r28) {
					PHALCON_ALLOC_ZVAL(r28);
				} else {
					if (Z_REFCOUNT_P(r28) > 1){ 
						PHALCON_SEPARATE(r28);
					}
				}
				is_equal_function(r28, v2, r26 TSRMLS_CC);
				if (zend_is_true(r28)) {
					PHALCON_INIT_VARTYPE(t3, IS_STRING);
					ZVAL_STRING(t3, "\t", 1);
					PHALCON_INIT_RESULT(r32);
					PHALCON_INIT_RESULT(r33);
					phalcon_array_fetch_long(r33, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r33);
					p7[0] = r33;
					PHALCON_CALL_METHOD_PARAMS(r32, v9, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
					PHALCON_INIT_RESULT(r31);
					PHALCON_CONCAT_VBOTH(r31, t3, "<option selected=\"selected\" value=\"", r32);
					PHALCON_INIT_RESULT(r34);
					PHALCON_INIT_RESULT(r35);
					phalcon_array_fetch_long(r35, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r35);
					p8[0] = r35;
					PHALCON_CALL_METHOD_PARAMS(r34, v9, "readattribute", 1, p8, PHALCON_CALL_DEFAULT);
					PHALCON_INIT_RESULT(r30);
					PHALCON_CONCAT_VBOTH(r30, r31, "'>", r34);
					PHALCON_INIT_VAR(t4);
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t4 TSRMLS_CC);
					PHALCON_INIT_RESULT(r29);
					PHALCON_CONCAT_VBOTH(r29, r30, "</option>", t4);
					PHALCON_INIT_RESULT(r36);
					concat_function(r36, v3, r29 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r36);
				} else {
					PHALCON_INIT_VARTYPE(t5, IS_STRING);
					ZVAL_STRING(t5, "\t", 1);
					PHALCON_INIT_RESULT(r40);
					PHALCON_INIT_RESULT(r41);
					phalcon_array_fetch_long(r41, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r41);
					p9[0] = r41;
					PHALCON_CALL_METHOD_PARAMS(r40, v9, "readattribute", 1, p9, PHALCON_CALL_DEFAULT);
					PHALCON_INIT_RESULT(r39);
					PHALCON_CONCAT_VBOTH(r39, t5, "<option value=\"", r40);
					PHALCON_INIT_RESULT(r42);
					PHALCON_INIT_RESULT(r43);
					phalcon_array_fetch_long(r43, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r43);
					p10[0] = r43;
					PHALCON_CALL_METHOD_PARAMS(r42, v9, "readattribute", 1, p10, PHALCON_CALL_DEFAULT);
					PHALCON_INIT_RESULT(r38);
					PHALCON_CONCAT_VBOTH(r38, r39, "\">", r42);
					PHALCON_INIT_VAR(t6);
					zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t6 TSRMLS_CC);
					PHALCON_INIT_RESULT(r37);
					PHALCON_CONCAT_VBOTH(r37, r38, "</option>", t6);
					PHALCON_INIT_RESULT(r44);
					concat_function(r44, v3, r37 TSRMLS_CC);
					PHALCON_CPY_WRT(v3, r44);
				}
				PHALCON_CALL_METHOD_NORETURN(v8, "next", PHALCON_CALL_DEFAULT);
				goto ws82;
				we82:
				r24 = NULL;
			} else {
				PHALCON_ALLOC_ZVAL(r45);
				phalcon_array_fetch_long(r45, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(r45) == IS_ARRAY) { 
					PHALCON_ALLOC_ZVAL(r46);
					phalcon_array_fetch_long(r46, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					FOREACH_V(r46, ac1, fes83, fee83, ah1, hp1, v9)
						PHALCON_INIT_VARTYPE(t7, IS_STRING);
						ZVAL_STRING(t7, "\t", 1);
						PHALCON_INIT_RESULT(r50);
						phalcon_array_fetch_long(r50, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r49);
						PHALCON_CONCAT_VBOTH(r49, t7, "<option value=\"", r50);
						PHALCON_INIT_RESULT(r51);
						phalcon_array_fetch_long(r51, v9, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r48);
						PHALCON_CONCAT_VBOTH(r48, r49, "\">", r51);
						PHALCON_INIT_VAR(t8);
						zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t8 TSRMLS_CC);
						PHALCON_INIT_RESULT(r47);
						PHALCON_CONCAT_VBOTH(r47, r48, "</option>", t8);
						PHALCON_INIT_RESULT(r52);
						concat_function(r52, v3, r47 TSRMLS_CC);
						PHALCON_CPY_WRT(v3, r52);
					END_FOREACH(ac1, fes83, fee83, ah1, hp1);
				} else {
					PHALCON_ALLOC_ZVAL(i2);
					object_init_ex(i2, phalcon_tag_exception_class_entry);
					PHALCON_ALLOC_ZVAL(p12[0]);
					ZVAL_STRING(p12[0], "Options value should be an Array or Object", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p12, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i2 TSRMLS_CC);
					Z_ADDREF_P(i2);
					return;
				}
			}
		}
	}
	PHALCON_ALLOC_ZVAL(t9);
	ZVAL_STRING(t9, "</select>", 1);
	PHALCON_ALLOC_ZVAL(r53);
	concat_function(r53, v3, t9 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r53);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r4);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		PHALCON_CPY_WRT(v1, r5);
	}
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	PHALCON_CONCAT_BOTH(r8,  "<textarea id=\"", r7, "\" ");
	PHALCON_CPY_WRT(v2, r8);
	FOREACH_KV(v0, ac0, fes84, fee84, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) != IS_LONG) {
			PHALCON_INIT_RESULT(r9);
			PHALCON_CONCAT_VBOTH(r9, v4, "=\"", v3);
			PHALCON_INIT_RESULT(r10);
			PHALCON_CONCAT_RIGHT(r10, r9, "\" ");
			PHALCON_INIT_RESULT(r11);
			concat_function(r11, v2, r10 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r11);
		}
	END_FOREACH(ac0, fes84, fee84, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r12);
	PHALCON_CONCAT_BOTH(r12,  ">", v1, "</textarea>");
	PHALCON_ALLOC_ZVAL(r13);
	concat_function(r13, v2, r12 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r13);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Builds a HTML FORM tag
 *
 * 
 *
 * @paramarray $params
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, form){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *p5[] = { NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	PHALCON_CPY_WRT(v1, r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(c0);
	ZVAL_STRING(c0, "/", 1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v1, "getparams", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "join", c0, r2, 0x00B);
	FREE_ZVAL(c0);
	PHALCON_CPY_WRT(v2, r1);
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r3);
		} else {
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r6);
			PHALCON_CALL_METHOD(r6, v1, "getactionname", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_CONCAT_VBOTH(r4, r5, "/", r6);
			PHALCON_CPY_WRT(v3, r4);
		}
	} else {
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r7);
	}
	eval_int = phalcon_array_isset_string(v0, "method", strlen("method")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_STRING(t0, "post", 1);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "method", strlen("method"), t0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "confirm", strlen("confirm")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_string(r8, v0, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_array_fetch_string(r10, v0, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r11);
		phalcon_array_fetch_string(r11, v0, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r9);
		PHALCON_CONCAT_VBOTH(r9, r10, ";if(!confirm(\"", r11);
		PHALCON_ALLOC_ZVAL(r12);
		PHALCON_CONCAT_RIGHT(r12, r9, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL(r13);
		concat_function(r13, r8, r12 TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "onsubmit", strlen("onsubmit"), r13 TSRMLS_CC);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL(r14);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_STATIC_PARAMS(r14, "phalcon_utils", "geturl", 1, p5);
		PHALCON_CPY_WRT(v3, r14);
	} else {
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_ALLOC_ZVAL(r16);
		PHALCON_CONCAT_VBOTH(r16, v3, "/", v2);
		Z_ADDREF_P(r16);
		p6[0] = r16;
		PHALCON_CALL_STATIC_PARAMS(r15, "phalcon_utils", "geturl", 1, p6);
		PHALCON_CPY_WRT(v3, r15);
	}
	eval_int = phalcon_array_isset_string(v0, "parameters", strlen("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_array_fetch_string(r17, v0, "parameters", strlen("parameters"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		PHALCON_CONCAT_LEFT(r18, "?", r17);
		PHALCON_ALLOC_ZVAL(r19);
		concat_function(r19, v3, r18 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r19);
	}
	PHALCON_ALLOC_ZVAL(r20);
	PHALCON_CONCAT_BOTH(r20,  "<form action=\"", v3, "\" ");
	PHALCON_CPY_WRT(v4, r20);
	FOREACH_KV(v0, ac0, fes85, fee85, ah0, hp0, v6, v5)
		if (Z_TYPE_P(v6) != IS_LONG) {
			PHALCON_INIT_RESULT(r21);
			PHALCON_CONCAT_VBOTH(r21, v6, "= \"", v5);
			PHALCON_INIT_RESULT(r22);
			PHALCON_CONCAT_RIGHT(r22, r21, "\" ");
			PHALCON_INIT_RESULT(r23);
			concat_function(r23, v4, r22 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r23);
		}
	END_FOREACH(ac0, fes85, fee85, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r24);
	PHALCON_CONCAT_RIGHT(r24, v4, ">");
	PHALCON_RETURN_CTOR(r24);
}

/**
 * Builds a HTML close FORM tag
 *
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, endForm){


	RETURN_STRING("</form>", 1);
}

PHP_METHOD(Phalcon_Tag, setTitle){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, v0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	concat_function(r0, v0, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, getTitle){

	zval *t0 = NULL;
	zval *r0 = NULL;

	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CONCAT_BOTH(r0,  "<title>", t0, "</title>");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * 
 *
 * @paramarray $params
 * @param   boolean $local
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_BOOL(v1, 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_string(v0, "href", strlen("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "href", strlen("href"), r0 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "href", strlen("href"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v1, r1);
	} else {
		eval_int = phalcon_array_isset_string(v0, "local", strlen("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch_string(r2, v0, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT_PARAM(v1, r2);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_unset_string(v0, "local", strlen("local")+1);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "type", strlen("type")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "text/css", 1);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "type", strlen("type"), t1 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "href", strlen("href"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r4);
		p0[0] = r4;
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_utils", "geturl", 1, p0);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "href", strlen("href"), r3 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "<link rel=\"stylesheet\" ", 0);
	FOREACH_KV(v0, ac0, fes86, fee86, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) != IS_LONG) {
			PHALCON_INIT_RESULT(r6);
			PHALCON_CONCAT_LEFT(r6, " ", v4);
			PHALCON_INIT_RESULT(r5);
			PHALCON_CONCAT_VBOTH(r5, r6, "=\"", v3);
			PHALCON_INIT_RESULT(r7);
			PHALCON_CONCAT_RIGHT(r7, r5, "\" ");
			PHALCON_INIT_RESULT(r8);
			concat_function(r8, v2, r7 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r8);
		}
	END_FOREACH(ac0, fes86, fee86, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, ">", 1);
	PHALCON_ALLOC_ZVAL(r9);
	concat_function(r9, v2, t2 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r9);
	PHALCON_RETURN_CTOR(v2);
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $params
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			Z_UNSET_ISREF_P(copy);
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, copy);
		}
		PHALCON_CPY_WRT_PARAM(v0, a0);
	}
	eval_int = phalcon_array_isset_string(v0, "src", strlen("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "src", strlen("src"), r0 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			PHALCON_SEPARATE_PARAM(v0);
			phalcon_array_update_string(v0, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v0, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "geturl", 1, p0);
	PHALCON_SEPARATE_PARAM(v0);
	phalcon_array_update_string(v0, "src", strlen("src"), r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "<img ", 0);
	FOREACH_KV(v0, ac0, fes87, fee87, ah0, hp0, v3, v2)
		if (Z_TYPE_P(v3) != IS_LONG) {
			PHALCON_INIT_RESULT(r4);
			PHALCON_CONCAT_LEFT(r4, " ", v3);
			PHALCON_INIT_RESULT(r3);
			PHALCON_CONCAT_VBOTH(r3, r4, "=\"", v2);
			PHALCON_INIT_RESULT(r5);
			PHALCON_CONCAT_RIGHT(r5, r3, "\" ");
			PHALCON_INIT_RESULT(r6);
			concat_function(r6, v1, r5 TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r6);
		}
	END_FOREACH(ac0, fes87, fee87, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, ">", 1);
	PHALCON_ALLOC_ZVAL(r7);
	concat_function(r7, v1, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v1, r7);
	PHALCON_RETURN_CTOR(v1);
}

