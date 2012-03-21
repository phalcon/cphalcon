
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
#include "kernel/memory.h"

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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_dispatcher", sizeof("_dispatcher")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", v1, 0x04A);
	Z_DELREF_P(v1);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_tag_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Only scalar values can be assigned to UI components", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (Z_TYPE_P(t0) != IS_ARRAY) {
		convert_to_array(t0);
	}
	Z_ADDREF_P(v1);
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_array_fetch(&t1, t0, v0, PHALCON_SILENT_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		t2 = zend_read_static_property(phalcon_tag_class_entry, "_displayValues", sizeof("_displayValues")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_array_fetch(&t3, t2, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(t3);
	} else {
		phalcon_init_global("_POST" TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					a0 = *gv0;
				} else {
					PHALCON_INIT_VAR(a0);
					array_init(a0);
				}
			}
		}
		if (!a0) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
		}
		eval_int = phalcon_array_isset(a0, v0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", 0x02B);
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch(&r1, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_RETURN_CHECK_CTOR(r1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_ALLOC_ZVAL_MM(r3);
				phalcon_array_fetch(&r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r2, "stripslashes", r3, 0x02C);
				Z_DELREF_P(r3);
				PHALCON_RETURN_DZVAL(r2);
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Builds a HTML A tag using framework conventions
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, linkTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_NULL(v1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "", 1);
	eval_int = phalcon_array_isset_long(v2, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r0);
	} else {
		eval_int = phalcon_array_isset_string(v2, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_string(&r1, v2, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r1);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "action", strlen("action")+1);
		}
	}
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "", 1);
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_long(&r2, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r2);
	} else {
		eval_int = phalcon_array_isset_string(v2, "text", strlen("text")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v2, "text", strlen("text"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r3);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "text", strlen("text")+1);
		}
	}
	PHALCON_INIT_VAR(v4);
	ZVAL_STRING(v4, "", 1);
	if (!PHALCON_COMPARE_STRING(v3, "")) {
		eval_int = phalcon_array_isset_string(v2, "confirm", strlen("confirm")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset_string(v2, "onclick", strlen("onclick")+1);
			if (!eval_int) {
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				Z_ADDREF_P(t0);
				if (Z_REFCOUNT_P(v2) > 1) {
					zval *new_zv;
					Z_DELREF_P(v2);
					ALLOC_ZVAL(new_zv);
					INIT_PZVAL_COPY(new_zv, v2);
					v2 = new_zv;
					zval_copy_ctor(new_zv);
				}
				phalcon_array_update_string(v2, "onclick", strlen("onclick"), t0 TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, v2, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CONCAT_LEFT(r6, "if(!confirm('", r5);
			PHALCON_ALLOC_ZVAL_MM(r7);
			phalcon_array_fetch_string(&r7, v2, "onclick", strlen("onclick"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_VBOTH(r4, r6, "')) { return false; }; ", r7);
			Z_ADDREF_P(r4);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "onclick", strlen("onclick"), r4 TSRMLS_CC);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "confirm", strlen("confirm")+1);
		}
		PHALCON_ALLOC_ZVAL_MM(r8);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_STATIC_PARAMS(r8, "phalcon_utils", "geturl", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_BOTH(r9,  "<a href=\"", r8, "\" ");
		PHALCON_CPY_WRT(v4, r9);
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes84:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee84;
			} else {
				PHALCON_INIT_VAR(v6);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v6, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v6, num);
					}
				}
			}
			v5 = *hd;
			Z_REFCOUNT_P(v5);
			if (Z_TYPE_P(v6) != IS_LONG) {
				PHALCON_INIT_VAR(r11);
				PHALCON_CONCAT_LEFT(r11, " ", v6);
				PHALCON_INIT_VAR(r10);
				PHALCON_CONCAT_VBOTH(r10, r11, "=\"", v5);
				PHALCON_INIT_VAR(r12);
				PHALCON_CONCAT_RIGHT(r12, r10, "\" ");
				PHALCON_INIT_VAR(r13);
				concat_function(r13, v4, r12 TSRMLS_CC);
				PHALCON_CPY_WRT(v4, r13);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes84;
			fee84:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_BOTH(r14,  ">", v1, "</a>");
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, v4, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r15);
	}
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Builds a HTML input[type="text"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textField){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v1, 0, r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	eval_int = phalcon_array_isset_string(v1, "name", strlen("name")+1);
	if (!eval_int) {
		Z_ADDREF_P(v2);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v1, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			Z_ADDREF_P(v2);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v1, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v1, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r3);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r4);
	}
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CONCAT_LEFT(r6, "<input type=\"text\" id=\"", v2);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_VBOTH(r5, r6, "\" value=\"", v3);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CONCAT_RIGHT(r7, r5, "\" ");
	PHALCON_CPY_WRT(v4, r7);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes85:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee85;
		} else {
			PHALCON_INIT_VAR(v6);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v6, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v6, num);
				}
			}
		}
		v5 = *hd;
		Z_REFCOUNT_P(v5);
		if (Z_TYPE_P(v6) != IS_LONG) {
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VBOTH(r8, v6, "=\"", v5);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "\" ");
			PHALCON_INIT_VAR(r10);
			concat_function(r10, v4, r9 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r10);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes85;
		fee85:
		if(0){ };
	}
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL_MM(r11);
	concat_function(r11, v4, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r11);
	PHALCON_RETURN_CTOR(v4);
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

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_string(v1, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "value", strlen("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r1);
		} else {
			PHALCON_INIT_VAR(v2);
			ZVAL_STRING(v2, "", 1);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_BOTH(r2,  "<input type=\"submit\" value=\"", v2, "\" ");
	PHALCON_CPY_WRT(v3, r2);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes86:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee86;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		v4 = *hd;
		Z_REFCOUNT_P(v4);
		if (Z_TYPE_P(v5) != IS_LONG) {
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_VBOTH(r3, v5, "=\"", v4);
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_RIGHT(r4, r3, "\" ");
			PHALCON_INIT_VAR(r5);
			concat_function(r5, v3, r4 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r5);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes86;
		fee86:
		if(0){ };
	}
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_ALLOC_ZVAL_MM(r6);
	concat_function(r6, v3, t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r6);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds a HTML SELECT tag using an array for options
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, selectStatic){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	eval_int = phalcon_array_isset_string(v2, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v4);
		p0[0] = v4;
		PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r1);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v2, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r2);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_LEFT(r4, "<select id=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_VBOTH(r3, r4, "\" name=\"", v4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_RIGHT(r5, r3, "\" ");
	PHALCON_CPY_WRT(v5, r5);
	eval_int = phalcon_array_isset_string(v2, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(v6);
		ZVAL_STRING(v6, "@", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, v2, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r6);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(v7);
		ZVAL_STRING(v7, "Choose...", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, v2, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r7);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyText", strlen("dummyText")+1);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v8, t0);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes87:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee87;
		} else {
			PHALCON_INIT_VAR(v10);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v10, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v10, num);
				}
			}
		}
		v9 = *hd;
		Z_REFCOUNT_P(v9);
		if (Z_TYPE_P(v10) != IS_LONG) {
			if (Z_TYPE_P(v9) != IS_ARRAY) { 
				PHALCON_INIT_VAR(r8);
				PHALCON_CONCAT_VBOTH(r8, v10, "=\"", v9);
				PHALCON_INIT_VAR(r9);
				PHALCON_CONCAT_RIGHT(r9, r8, "\" ");
				PHALCON_INIT_VAR(r10);
				concat_function(r10, v5, r9 TSRMLS_CC);
				PHALCON_CPY_WRT(v5, r10);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes87;
		fee87:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CONCAT_LEFT(r11, ">", v8);
	PHALCON_ALLOC_ZVAL_MM(r12);
	concat_function(r12, v5, r11 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r12);
	eval_int = phalcon_array_isset_string(v2, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_VBOTH(r15, t1, "<option value=\"", v6);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_VBOTH(r14, r15, "\">", v7);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_VBOTH(r13, r14, "</option>", v8);
		PHALCON_ALLOC_ZVAL_MM(r16);
		concat_function(r16, v5, r13 TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r16);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "useDummy", strlen("useDummy")+1);
	}
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch_long(&r17, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r17);
		if (Z_TYPE_P(v1) == IS_ARRAY) { 
			if (Z_TYPE_P(v1) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v1);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes88:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee88;
				} else {
					PHALCON_INIT_VAR(v12);
					htype = zend_hash_get_current_key_ex(ah1, &index, &index_len, &num, 0, &hp1);
					if (htype == HASH_KEY_IS_STRING) {
						ZVAL_STRINGL(v12, index, index_len-1, 1);
					} else {
						if (htype == HASH_KEY_IS_LONG) {
							ZVAL_LONG(v12, num);
						}
					}
				}
				v11 = *hd;
				Z_REFCOUNT_P(v11);
				PHALCON_INIT_VAR(r18);
				is_equal_function(r18, v12, v3 TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_STRING(t2, "", 1);
				PHALCON_INIT_VAR(r19);
				is_not_identical_function(r19, t2, v3 TSRMLS_CC);
				PHALCON_INIT_VAR(r20);
				phalcon_and_function(r20, r18, r19 TSRMLS_CC);
				if (zend_is_true(r20)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "\t", 1);
					PHALCON_INIT_VAR(r23);
					PHALCON_CONCAT_VBOTH(r23, t3, "<option value=\"", v12);
					PHALCON_INIT_VAR(r22);
					PHALCON_CONCAT_VBOTH(r22, r23, "\" selected=\"selected\">", v11);
					PHALCON_INIT_VAR(r21);
					PHALCON_CONCAT_VBOTH(r21, r22, "</option>", v8);
					PHALCON_INIT_VAR(r24);
					concat_function(r24, v5, r21 TSRMLS_CC);
					PHALCON_CPY_WRT(v5, r24);
				} else {
					PHALCON_INIT_VAR(t4);
					ZVAL_STRING(t4, "\t", 1);
					PHALCON_INIT_VAR(r27);
					PHALCON_CONCAT_VBOTH(r27, t4, "<option value=\"", v12);
					PHALCON_INIT_VAR(r26);
					PHALCON_CONCAT_VBOTH(r26, r27, "\">", v11);
					PHALCON_INIT_VAR(r25);
					PHALCON_CONCAT_VBOTH(r25, r26, "</option>", v8);
					PHALCON_INIT_VAR(r28);
					concat_function(r28, v5, r25 TSRMLS_CC);
					PHALCON_CPY_WRT(v5, r28);
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes88;
				fee88:
				if(0){ };
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_tag_exception_class_entry);
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "Data supplied for Phalcon_Tag::selectStatic is not valid", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		}
	}
	PHALCON_INIT_VAR(t5);
	ZVAL_STRING(t5, "</select>", 1);
	PHALCON_ALLOC_ZVAL_MM(r29);
	concat_function(r29, v5, t5 TSRMLS_CC);
	PHALCON_CPY_WRT(v5, r29);
	PHALCON_RETURN_CTOR(v5);
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
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t0 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r0);
	eval_int = phalcon_array_isset_string(v2, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v4);
		p0[0] = v4;
		PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v5, r1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v2, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r2);
	}
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CONCAT_LEFT(r4, "<select id='", v4);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CONCAT_VBOTH(r3, r4, "' name='", v4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_RIGHT(r5, r3, "' ");
	PHALCON_CPY_WRT(v6, r5);
	if (Z_TYPE_P(v2) == IS_ARRAY) { 
		if (Z_TYPE_P(v2) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v2);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes89:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee89;
			} else {
				PHALCON_INIT_VAR(v8);
				htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
				if (htype == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(v8, index, index_len-1, 1);
				} else {
					if (htype == HASH_KEY_IS_LONG) {
						ZVAL_LONG(v8, num);
					}
				}
			}
			v7 = *hd;
			Z_REFCOUNT_P(v7);
			if (Z_TYPE_P(v8) != IS_LONG) {
				if (Z_TYPE_P(v7) != IS_ARRAY) { 
					PHALCON_INIT_VAR(r6);
					PHALCON_CONCAT_VBOTH(r6, v8, "='", v7);
					PHALCON_INIT_VAR(r7);
					PHALCON_CONCAT_RIGHT(r7, r6, "' ");
					PHALCON_INIT_VAR(r8);
					concat_function(r8, v6, r7 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r8);
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes89;
			fee89:
			if(0){ };
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_LEFT(r9, ">", v3);
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v6, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r10);
	eval_int = phalcon_array_isset_string(v2, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(v9);
		ZVAL_STRING(v9, "", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, v2, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r11);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(v10);
		ZVAL_STRING(v10, "Choose...", 1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, v2, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, r12);
		PHALCON_SEPARATE(v2);
		phalcon_array_unset_string(v2, "dummyText", strlen("dummyText")+1);
	}
	eval_int = phalcon_array_isset_string(v2, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_VBOTH(r15, t1, "<option value=\"", v9);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_VBOTH(r14, r15, "\">", v10);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_VBOTH(r13, r14, "</option>", v3);
		PHALCON_ALLOC_ZVAL_MM(r16);
		concat_function(r16, v6, r13 TSRMLS_CC);
		PHALCON_CPY_WRT(v6, r16);
	}
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch_long(&r17, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v11, r17);
		if (zend_is_true(v11)) {
			if (Z_TYPE_P(v11) == IS_OBJECT) {
				eval_int = phalcon_array_isset_string(v2, "using", strlen("using")+1);
				if (!eval_int) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_tag_exception_class_entry);
					PHALCON_INIT_VAR(p1[0]);
					ZVAL_STRING(p1[0], "The 'using' parameter is required", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					PHALCON_MM_RESTORE();
					return;
				} else {
					PHALCON_ALLOC_ZVAL_MM(r18);
					phalcon_array_fetch_string(&r18, v2, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r18) != IS_ARRAY) { 
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_tag_exception_class_entry);
						PHALCON_INIT_VAR(p2[0]);
						ZVAL_STRING(p2[0], "The 'using' parameter should be an Array", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						PHALCON_MM_RESTORE();
						return;
					}
				}
				PHALCON_ALLOC_ZVAL_MM(r19);
				phalcon_array_fetch_string(&r19, v2, "using", strlen("using"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v12, r19);
				PHALCON_CALL_METHOD_NORETURN(v11, "rewind", PHALCON_CALL_DEFAULT);
				ws90:
				PHALCON_INIT_VAR(r20);
				PHALCON_CALL_METHOD(r20, v11, "valid", PHALCON_CALL_DEFAULT);
				if (!zend_is_true(r20)) {
					goto we90;
				}
				PHALCON_INIT_VAR(r21);
				PHALCON_CALL_METHOD(r21, v11, "current", PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v13, r21);
				PHALCON_INIT_VAR(r22);
				PHALCON_INIT_VAR(r23);
				phalcon_array_fetch_long(&r23, v12, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r23);
				p6[0] = r23;
				PHALCON_CALL_METHOD_PARAMS(r22, v13, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p6[0]);
				PHALCON_CPY_WRT(v14, r22);
				PHALCON_INIT_VAR(r24);
				PHALCON_INIT_VAR(r25);
				phalcon_array_fetch_long(&r25, v12, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r25);
				p7[0] = r25;
				PHALCON_CALL_METHOD_PARAMS(r24, v13, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p7[0]);
				PHALCON_CPY_WRT(v15, r24);
				PHALCON_INIT_VAR(r26);
				is_equal_function(r26, v5, v14 TSRMLS_CC);
				if (zend_is_true(r26)) {
					PHALCON_INIT_VAR(t2);
					ZVAL_STRING(t2, "\t", 1);
					PHALCON_INIT_VAR(r29);
					PHALCON_CONCAT_VBOTH(r29, t2, "<option selected=\"selected\" value=\"", v14);
					PHALCON_INIT_VAR(r28);
					PHALCON_CONCAT_VBOTH(r28, r29, "'>", v15);
					PHALCON_INIT_VAR(r27);
					PHALCON_CONCAT_VBOTH(r27, r28, "</option>", v3);
					PHALCON_INIT_VAR(r30);
					concat_function(r30, v6, r27 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r30);
				} else {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "\t", 1);
					PHALCON_INIT_VAR(r33);
					PHALCON_CONCAT_VBOTH(r33, t3, "<option value=\"", v14);
					PHALCON_INIT_VAR(r32);
					PHALCON_CONCAT_VBOTH(r32, r33, "\">", v15);
					PHALCON_INIT_VAR(r31);
					PHALCON_CONCAT_VBOTH(r31, r32, "</option>", v3);
					PHALCON_INIT_VAR(r34);
					concat_function(r34, v6, r31 TSRMLS_CC);
					PHALCON_CPY_WRT(v6, r34);
				}
				PHALCON_CALL_METHOD_NORETURN(v11, "next", PHALCON_CALL_DEFAULT);
				goto ws90;
				we90:
				if(0) { };
			}
		}
	}
	PHALCON_INIT_VAR(t4);
	ZVAL_STRING(t4, "</select>", 1);
	PHALCON_ALLOC_ZVAL_MM(r35);
	concat_function(r35, v6, t4 TSRMLS_CC);
	PHALCON_CPY_WRT(v6, r35);
	PHALCON_RETURN_CTOR(v6);
}

/**
 * Builds a HTML TEXTAREA tag
 *
 * 
 *
 * @paramarray $parameters
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, textArea){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_long(v1, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r0);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_long(v1, 0, r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_long(&r1, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r1);
	eval_int = phalcon_array_isset_string(v1, "name", strlen("name")+1);
	if (!eval_int) {
		Z_ADDREF_P(v2);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v1, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			Z_ADDREF_P(v2);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "name", strlen("name"), v2 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v1, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v1, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r3);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_SELF_PARAMS(r4, this_ptr, "_getvaluefromaction", 1, p0);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v3, r4);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CONCAT_BOTH(r5,  "<textarea id=\"", v2, "\" ");
	PHALCON_CPY_WRT(v4, r5);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes91:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee91;
		} else {
			PHALCON_INIT_VAR(v6);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v6, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v6, num);
				}
			}
		}
		v5 = *hd;
		Z_REFCOUNT_P(v5);
		if (Z_TYPE_P(v6) != IS_LONG) {
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_VBOTH(r6, v6, "=\"", v5);
			PHALCON_INIT_VAR(r7);
			PHALCON_CONCAT_RIGHT(r7, r6, "\" ");
			PHALCON_INIT_VAR(r8);
			concat_function(r8, v4, r7 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r8);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes91;
		fee91:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CONCAT_BOTH(r9,  ">", v3, "</textarea>");
	PHALCON_ALLOC_ZVAL_MM(r10);
	concat_function(r10, v4, r9 TSRMLS_CC);
	PHALCON_CPY_WRT(v4, r10);
	PHALCON_RETURN_CTOR(v4);
}

/**
 * Builds a HTML FORM tag
 *
 * 
 *
 * @paramarray $parameters
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
	zval *p5[] = { NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v0);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "/", 1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v2, "getparams", PHALCON_CALL_DEFAULT);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "join", c0, r2, 0x00D);
	PHALCON_CPY_WRT(v0, r1);
	eval_int = phalcon_array_isset_long(v1, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(v1, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			phalcon_array_fetch_string(&r3, v1, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, v2, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CALL_METHOD(r6, v2, "getactionname", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_VBOTH(r4, r5, "/", r6);
			PHALCON_CPY_WRT(v3, r4);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_long(&r7, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r7);
	}
	eval_int = phalcon_array_isset_string(v1, "method", strlen("method")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "post", 1);
		Z_ADDREF_P(t0);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "method", strlen("method"), t0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "confirm", strlen("confirm")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, v1, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_array_fetch_string(&r10, v1, "onsubmit", strlen("onsubmit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, v1, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_VBOTH(r9, r10, ";if(!confirm(\"", r11);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_RIGHT(r12, r9, "\")) { return false; }");
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, r8, r12 TSRMLS_CC);
		Z_ADDREF_P(r13);
		if (Z_REFCOUNT_P(v1) > 1) {
			zval *new_zv;
			Z_DELREF_P(v1);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v1);
			v1 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v1, "onsubmit", strlen("onsubmit"), r13 TSRMLS_CC);
		PHALCON_SEPARATE(v1);
		phalcon_array_unset_string(v1, "confirm", strlen("confirm")+1);
	}
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_STATIC_PARAMS(r14, "phalcon_utils", "geturl", 1, p5);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v3, r14);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_VBOTH(r16, v3, "/", v0);
		Z_ADDREF_P(r16);
		p6[0] = r16;
		PHALCON_CALL_STATIC_PARAMS(r15, "phalcon_utils", "geturl", 1, p6);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v3, r15);
	}
	eval_int = phalcon_array_isset_string(v1, "parameters", strlen("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r17);
		phalcon_array_fetch_string(&r17, v1, "parameters", strlen("parameters"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CONCAT_LEFT(r18, "?", r17);
		PHALCON_ALLOC_ZVAL_MM(r19);
		concat_function(r19, v3, r18 TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r19);
	}
	PHALCON_ALLOC_ZVAL_MM(r20);
	PHALCON_CONCAT_BOTH(r20,  "<form action=\"", v3, "\" ");
	PHALCON_CPY_WRT(v4, r20);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes92:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee92;
		} else {
			PHALCON_INIT_VAR(v6);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v6, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v6, num);
				}
			}
		}
		v5 = *hd;
		Z_REFCOUNT_P(v5);
		if (Z_TYPE_P(v6) != IS_LONG) {
			PHALCON_INIT_VAR(r21);
			PHALCON_CONCAT_VBOTH(r21, v6, "= \"", v5);
			PHALCON_INIT_VAR(r22);
			PHALCON_CONCAT_RIGHT(r22, r21, "\" ");
			PHALCON_INIT_VAR(r23);
			concat_function(r23, v4, r22 TSRMLS_CC);
			PHALCON_CPY_WRT(v4, r23);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes92;
		fee92:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r24);
	PHALCON_CONCAT_RIGHT(r24, v4, ">");
	PHALCON_RETURN_CTOR(r24);
}

/**
 * Builds a HTML close FORM tag
 *
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, endForm){


	PHALCON_MM_GROW();
	PHALCON_MM_RESTORE();
	RETURN_STRING("</form>", 1);
}

PHP_METHOD(Phalcon_Tag, setTitle){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, appendTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, t0, v0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, prependTitle){

	zval *v0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	concat_function(r0, v0, t0 TSRMLS_CC);
	zend_update_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Tag, getTitle){

	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_tag_class_entry, "_documentTitle", sizeof("_documentTitle")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_BOTH(r0,  "<title>", t0, "</title>");
	PHALCON_RETURN_CTOR(r0);
}

/**
 * Builds a LINK[rel="stylesheet"] tag
 *
 * 
 *
 * @paramarray $parameters
 * @param   boolean $local
 * @returnstring
 */
PHP_METHOD(Phalcon_Tag, stylesheetLink){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_BOOL(v1, 1);
	} else {
		PHALCON_SEPARATE_PARAM(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		Z_ADDREF_P(v1);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v1);
		PHALCON_CPY_WRT(v2, a0);
	} else {
		PHALCON_CPY_WRT(v2, v0);
	}
	eval_int = phalcon_array_isset_string(v2, "href", strlen("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v2, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r0);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "href", strlen("href"), r0 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			Z_ADDREF_P(t0);
			if (Z_REFCOUNT_P(v2) > 1) {
				zval *new_zv;
				Z_DELREF_P(v2);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v2);
				v2 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v2, "href", strlen("href"), t0 TSRMLS_CC);
		}
	}
	PHALCON_INIT_VAR(v1);
	ZVAL_STRING(v1, "", 1);
	eval_int = phalcon_array_isset_long(v2, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_long(&r1, v2, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r1);
	} else {
		eval_int = phalcon_array_isset_string(v2, "local", strlen("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, v2, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v1, r2);
			PHALCON_SEPARATE(v2);
			phalcon_array_unset_string(v2, "local", strlen("local")+1);
		}
	}
	eval_int = phalcon_array_isset_string(v2, "type", strlen("type")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "text/css", 1);
		Z_ADDREF_P(t1);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "type", strlen("type"), t1 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v2, "href", strlen("href"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r4);
		p0[0] = r4;
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_utils", "geturl", 1, p0);
		Z_DELREF_P(p0[0]);
		Z_ADDREF_P(r3);
		if (Z_REFCOUNT_P(v2) > 1) {
			zval *new_zv;
			Z_DELREF_P(v2);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v2);
			v2 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v2, "href", strlen("href"), r3 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v3);
	ZVAL_STRING(v3, "<link rel=\"stylesheet\" ", 1);
	if (Z_TYPE_P(v2) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes93:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee93;
		} else {
			PHALCON_INIT_VAR(v5);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v5, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v5, num);
				}
			}
		}
		v4 = *hd;
		Z_REFCOUNT_P(v4);
		if (Z_TYPE_P(v5) != IS_LONG) {
			PHALCON_INIT_VAR(r6);
			PHALCON_CONCAT_LEFT(r6, " ", v5);
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_VBOTH(r5, r6, "=\"", v4);
			PHALCON_INIT_VAR(r7);
			PHALCON_CONCAT_RIGHT(r7, r5, "\" ");
			PHALCON_INIT_VAR(r8);
			concat_function(r8, v3, r7 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r8);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes93;
		fee93:
		if(0){ };
	}
	PHALCON_INIT_VAR(t2);
	ZVAL_STRING(t2, ">", 1);
	PHALCON_ALLOC_ZVAL_MM(r9);
	concat_function(r9, v3, t2 TSRMLS_CC);
	PHALCON_CPY_WRT(v3, r9);
	PHALCON_RETURN_CTOR(v3);
}

/**
 * Builds HTML IMG tags
 *
 * @param  array $parameters
 * @return string
 */
PHP_METHOD(Phalcon_Tag, image){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		Z_ADDREF_P(v0);
		PHALCON_SEPARATE_ARRAY(a0);
		add_next_index_zval(a0, v0);
		PHALCON_CPY_WRT(v1, a0);
	} else {
		PHALCON_CPY_WRT(v1, v0);
	}
	eval_int = phalcon_array_isset_string(v1, "src", strlen("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v1, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_long(&r0, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r0);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "src", strlen("src"), r0 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, "", 1);
			Z_ADDREF_P(t0);
			if (Z_REFCOUNT_P(v1) > 1) {
				zval *new_zv;
				Z_DELREF_P(v1);
				ALLOC_ZVAL(new_zv);
				INIT_PZVAL_COPY(new_zv, v1);
				v1 = new_zv;
				zval_copy_ctor(new_zv);
			}
			phalcon_array_update_string(v1, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, v1, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "geturl", 1, p0);
	Z_DELREF_P(p0[0]);
	Z_ADDREF_P(r1);
	if (Z_REFCOUNT_P(v1) > 1) {
		zval *new_zv;
		Z_DELREF_P(v1);
		ALLOC_ZVAL(new_zv);
		INIT_PZVAL_COPY(new_zv, v1);
		v1 = new_zv;
		zval_copy_ctor(new_zv);
	}
	phalcon_array_update_string(v1, "src", strlen("src"), r1 TSRMLS_CC);
	PHALCON_INIT_VAR(v2);
	ZVAL_STRING(v2, "<img ", 1);
	if (Z_TYPE_P(v1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes94:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee94;
		} else {
			PHALCON_INIT_VAR(v4);
			htype = zend_hash_get_current_key_ex(ah0, &index, &index_len, &num, 0, &hp0);
			if (htype == HASH_KEY_IS_STRING) {
				ZVAL_STRINGL(v4, index, index_len-1, 1);
			} else {
				if (htype == HASH_KEY_IS_LONG) {
					ZVAL_LONG(v4, num);
				}
			}
		}
		v3 = *hd;
		Z_REFCOUNT_P(v3);
		if (Z_TYPE_P(v4) != IS_LONG) {
			PHALCON_INIT_VAR(r4);
			PHALCON_CONCAT_LEFT(r4, " ", v4);
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_VBOTH(r3, r4, "=\"", v3);
			PHALCON_INIT_VAR(r5);
			PHALCON_CONCAT_RIGHT(r5, r3, "\" ");
			PHALCON_INIT_VAR(r6);
			concat_function(r6, v2, r5 TSRMLS_CC);
			PHALCON_CPY_WRT(v2, r6);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes94;
		fee94:
		if(0){ };
	}
	PHALCON_INIT_VAR(t1);
	ZVAL_STRING(t1, ">", 1);
	PHALCON_ALLOC_ZVAL_MM(r7);
	concat_function(r7, v2, t1 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, r7);
	PHALCON_RETURN_CTOR(v2);
}

