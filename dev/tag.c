
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
	if (Z_TYPE_P(t1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
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
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	PHALCON_CALL_FUNC_PARAMS(r0, "is_scalar", strlen("is_scalar"), 1, p0);
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
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
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
	zval *p1[] = { NULL };
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
		if (Z_TYPE_P(t3) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t3);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t3);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		phalcon_init_global("_POST" TSRMLS_CC);
		if (&EG(symbol_table)) {
			if( zend_hash_find(&EG(symbol_table), "_POST", sizeof("_POST"), (void **) &gv0) == SUCCESS) {
				if(Z_TYPE_PP(gv0)==IS_ARRAY){
					a0 = *gv0;
				} else {
					PHALCON_INIT_ARRAY(a0);
				}
			}
		}
		if (!a0) {
			PHALCON_INIT_ARRAY(a0);
		}
		eval_int = phalcon_array_isset(a0, v0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_CALL_FUNC(r0, "get_magic_quotes_gpc", strlen("get_magic_quotes_gpc"));
			if (!zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch(r1, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (Z_TYPE_P(r1) > IS_BOOL) {
					{
						zend_uchar is_ref = Z_ISREF_P(return_value);
						zend_uint refcount = Z_REFCOUNT_P(return_value);
						*(return_value) = *(r1);
						zval_copy_ctor(return_value);
						Z_SET_ISREF_TO_P(return_value, is_ref);
				 		Z_SET_REFCOUNT_P(return_value, refcount);
					}
				} else {
					{
						zend_uchar is_ref = Z_ISREF_P(return_value);
						zend_uint refcount = Z_REFCOUNT_P(return_value);
						*(return_value) = *(r1);
						Z_SET_ISREF_TO_P(return_value, is_ref);
				 		Z_SET_REFCOUNT_P(return_value, refcount);
					}
				}
				return;
			} else {
				PHALCON_ALLOC_ZVAL(r2);
				PHALCON_ALLOC_ZVAL(r3);
				phalcon_array_fetch(r3, a0, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r3);
				p1[0] = r3;
				PHALCON_CALL_FUNC_PARAMS(r2, "stripslashes", strlen("stripslashes"), 1, p1);
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
		PHALCON_INIT_NULL(v1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "", 0);
	eval_int = phalcon_array_isset_long(v0, 0);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
	} else {
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_string(r1, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r1);
			v2 = r1;
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_unset_string(v0, "action", strlen("action")+1);
		}
	}
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_long(r2, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v1) {
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r2);
		v1 = r2;
	} else {
		eval_int = phalcon_array_isset_string(v0, "text", strlen("text")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "text", strlen("text"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v1) {
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r3);
			v1 = r3;
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_unset_string(v0, "text", strlen("text")+1);
		}
	}
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_STRING(v3, "", 0);
	if (!phalcon_compare_strict_string(v2, "")) {
		eval_int = phalcon_array_isset_string(v0, "confirm", strlen("confirm")+1);
		if (eval_int) {
			eval_int = phalcon_array_isset_string(v0, "onclick", strlen("onclick")+1);
			if (!eval_int) {
				PHALCON_ALLOC_ZVAL(t0);
				ZVAL_STRING(t0, "", 1);
				{
					zval *orig_ptr = v0;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						ALLOC_ZVAL(v0);
						*v0 = *orig_ptr;
						zval_copy_ctor(v0);
						Z_SET_REFCOUNT_P(v0, 1);
						Z_UNSET_ISREF_P(v0);
					}
				}
				phalcon_array_update_string(v0, "onclick", strlen("onclick"), t0 TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(r5);
			phalcon_array_fetch_string(r5, v0, "confirm", strlen("confirm"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r6);
			phalcon_concat_left(r6, "if(!confirm('", r5 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_array_fetch_string(r7, v0, "onclick", strlen("onclick"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r6, "')) { return false; }; ", r7 TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "onclick", strlen("onclick"), r4 TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
		}
		PHALCON_ALLOC_ZVAL(r8);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_STATIC_PARAMS(r8, "phalcon_utils", "geturl", 1, p0);
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_concat_both(r9,  "<a href=\"", r8, "\" " TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r9);
		v3 = r9;
		FOREACH_KV(v0, ac0, fes76, fee76, ah0, hp0, v5, v4)
			if (Z_TYPE_P(v5) != IS_LONG) {
				if (!r11) {
					PHALCON_ALLOC_ZVAL(r11);
				} else {
					if (Z_REFCOUNT_P(r11) > 1) {
						{
							zval *orig_ptr = r11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r11);
								*r11 = *orig_ptr;
								zval_copy_ctor(r11);
								Z_SET_REFCOUNT_P(r11, 1);
								Z_UNSET_ISREF_P(r11);
							}
						}
					} else {
						FREE_ZVAL(r11);
						PHALCON_ALLOC_ZVAL(r11);
					}
				}
				phalcon_concat_left(r11, " ", v5 TSRMLS_CC);
				if (!r10) {
					PHALCON_ALLOC_ZVAL(r10);
				} else {
					if (Z_REFCOUNT_P(r10) > 1) {
						{
							zval *orig_ptr = r10;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r10);
								*r10 = *orig_ptr;
								zval_copy_ctor(r10);
								Z_SET_REFCOUNT_P(r10, 1);
								Z_UNSET_ISREF_P(r10);
							}
						}
					} else {
						FREE_ZVAL(r10);
						PHALCON_ALLOC_ZVAL(r10);
					}
				}
				phalcon_concat_vboth(r10, r11, "=\"", v4 TSRMLS_CC);
				if (!r12) {
					PHALCON_ALLOC_ZVAL(r12);
				} else {
					if (Z_REFCOUNT_P(r12) > 1) {
						{
							zval *orig_ptr = r12;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r12);
								*r12 = *orig_ptr;
								zval_copy_ctor(r12);
								Z_SET_REFCOUNT_P(r12, 1);
								Z_UNSET_ISREF_P(r12);
							}
						}
					} else {
						FREE_ZVAL(r12);
						PHALCON_ALLOC_ZVAL(r12);
					}
				}
				phalcon_concat_right(r12, r10, "\" " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r13, v3, r12);
				if (v3) {
					Z_DELREF_P(v3);
					if (!Z_REFCOUNT_P(v3)) {
						FREE_ZVAL(v3);
					}
				}
				Z_ADDREF_P(r13);
				v3 = r13;
			}
		END_FOREACH(ac0, fes76, fee76, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r14);
		phalcon_concat_both(r14,  ">", v1, "</a>" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r15, v3, r14);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r15);
		v3 = r15;
	}
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r4);
		v1 = r4;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r5);
		v1 = r5;
	}
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_array_fetch_long(r8, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r9);
	phalcon_concat_left(r9, "<input type=\"text\" id=\"", r8 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_concat_vboth(r7, r9, "\" value=\"", v1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r10);
	phalcon_concat_right(r10, r7, "\" " TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r10);
	v2 = r10;
	FOREACH_KV(v0, ac0, fes77, fee77, ah0, hp0, v3, v1)
		if (Z_TYPE_P(v3) != IS_LONG) {
			if (!r11) {
				PHALCON_ALLOC_ZVAL(r11);
			} else {
				if (Z_REFCOUNT_P(r11) > 1) {
					{
						zval *orig_ptr = r11;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r11);
							*r11 = *orig_ptr;
							zval_copy_ctor(r11);
							Z_SET_REFCOUNT_P(r11, 1);
							Z_UNSET_ISREF_P(r11);
						}
					}
				} else {
					FREE_ZVAL(r11);
					PHALCON_ALLOC_ZVAL(r11);
				}
			}
			phalcon_concat_vboth(r11, v3, "=\"", v1 TSRMLS_CC);
			if (!r12) {
				PHALCON_ALLOC_ZVAL(r12);
			} else {
				if (Z_REFCOUNT_P(r12) > 1) {
					{
						zval *orig_ptr = r12;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r12);
							*r12 = *orig_ptr;
							zval_copy_ctor(r12);
							Z_SET_REFCOUNT_P(r12, 1);
							Z_UNSET_ISREF_P(r12);
						}
					}
				} else {
					FREE_ZVAL(r12);
					PHALCON_ALLOC_ZVAL(r12);
				}
			}
			phalcon_concat_right(r12, r11, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r13, v2, r12);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r13);
			v2 = r13;
		}
	END_FOREACH(ac0, fes77, fee77, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_CONCAT_FUNCTION(r14, v2, t0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r14);
	v2 = r14;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r1);
			phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r1);
			v1 = r1;
		} else {
			PHALCON_ALLOC_ZVAL(v1);
			ZVAL_STRING(v1, "", 0);
		}
	}
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_concat_both(r2,  "<input type=\"submit\" value=\"", v1, "\" " TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r2);
	v2 = r2;
	FOREACH_KV(v0, ac0, fes78, fee78, ah0, hp0, v3, v1)
		if (Z_TYPE_P(v3) != IS_LONG) {
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_concat_vboth(r3, v3, "=\"", v1 TSRMLS_CC);
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_concat_right(r4, r3, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r5, v2, r4);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r5);
			v2 = r5;
		}
	END_FOREACH(ac0, fes78, fee78, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, " />", 1);
	PHALCON_CONCAT_FUNCTION(r6, v2, t0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r6);
	v2 = r6;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
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
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r2);
		v2 = r2;
	}
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_concat_left(r5, "<select id=\"", r4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_concat_vboth(r3, r5, "\" name=\"", r6 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_concat_right(r7, r3, "\" " TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r7);
	v3 = r7;
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v4);
		ZVAL_STRING(v4, "@", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_array_fetch_string(r8, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r8);
		v4 = r8;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "Choose...", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r9);
		phalcon_array_fetch_string(r9, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r9);
		v5 = r9;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	FOREACH_KV(v0, ac0, fes79, fee79, ah0, hp0, v7, v6)
		if (Z_TYPE_P(v7) != IS_LONG) {
			if (Z_TYPE_P(v6) != IS_ARRAY) { 
				if (!r10) {
					PHALCON_ALLOC_ZVAL(r10);
				} else {
					if (Z_REFCOUNT_P(r10) > 1) {
						{
							zval *orig_ptr = r10;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r10);
								*r10 = *orig_ptr;
								zval_copy_ctor(r10);
								Z_SET_REFCOUNT_P(r10, 1);
								Z_UNSET_ISREF_P(r10);
							}
						}
					} else {
						FREE_ZVAL(r10);
						PHALCON_ALLOC_ZVAL(r10);
					}
				}
				phalcon_concat_vboth(r10, v7, "=\"", v6 TSRMLS_CC);
				if (!r11) {
					PHALCON_ALLOC_ZVAL(r11);
				} else {
					if (Z_REFCOUNT_P(r11) > 1) {
						{
							zval *orig_ptr = r11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r11);
								*r11 = *orig_ptr;
								zval_copy_ctor(r11);
								Z_SET_REFCOUNT_P(r11, 1);
								Z_UNSET_ISREF_P(r11);
							}
						}
					} else {
						FREE_ZVAL(r11);
						PHALCON_ALLOC_ZVAL(r11);
					}
				}
				phalcon_concat_right(r11, r10, "\" " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r12, v3, r11);
				if (v3) {
					Z_DELREF_P(v3);
					if (!Z_REFCOUNT_P(v3)) {
						FREE_ZVAL(v3);
					}
				}
				Z_ADDREF_P(r12);
				v3 = r12;
			}
		}
	END_FOREACH(ac0, fes79, fee79, ah0, hp0);
	PHALCON_GET_CONSTANT(t0, "PHP_EOL");
	PHALCON_ALLOC_ZVAL(r13);
	phalcon_concat_left(r13, ">", t0 TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r14, v3, r13);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r14);
	v3 = r14;
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_concat_vboth(r17, t1, "<option value=\"", v4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, r17, "\">", v5 TSRMLS_CC);
		PHALCON_GET_CONSTANT(t2, "PHP_EOL");
		PHALCON_ALLOC_ZVAL(r15);
		phalcon_concat_vboth(r15, r16, "</option>", t2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r18, v3, r15);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r18);
		v3 = r18;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
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
				PHALCON_EQUAL_FUNCTION(r21, v9, v2);
				if (!t3) {
					PHALCON_ALLOC_ZVAL(t3);
				} else {
					if (Z_REFCOUNT_P(t3) > 1) {
						SEPARATE_ZVAL(&t3);
					} else {
						if (Z_TYPE_P(t3) != IS_STRING) {
							FREE_ZVAL(t3);
							PHALCON_ALLOC_ZVAL(t3);
						}
					}
				}
				ZVAL_STRING(t3, "", 1);
				PHALCON_NOT_IDENTICAL_FUNCTION(r22, v2, t3);
				PHALCON_AND_FUNCTION(r23, r21, r22);
				if (zend_is_true(r23)) {
					if (!t4) {
						PHALCON_ALLOC_ZVAL(t4);
					} else {
						if (Z_REFCOUNT_P(t4) > 1) {
							SEPARATE_ZVAL(&t4);
						} else {
							if (Z_TYPE_P(t4) != IS_STRING) {
								FREE_ZVAL(t4);
								PHALCON_ALLOC_ZVAL(t4);
							}
						}
					}
					ZVAL_STRING(t4, "\t", 1);
					if (!r26) {
						PHALCON_ALLOC_ZVAL(r26);
					} else {
						if (Z_REFCOUNT_P(r26) > 1) {
							{
								zval *orig_ptr = r26;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r26);
									*r26 = *orig_ptr;
									zval_copy_ctor(r26);
									Z_SET_REFCOUNT_P(r26, 1);
									Z_UNSET_ISREF_P(r26);
								}
							}
						} else {
							FREE_ZVAL(r26);
							PHALCON_ALLOC_ZVAL(r26);
						}
					}
					phalcon_concat_vboth(r26, t4, "<option value=\"", v9 TSRMLS_CC);
					if (!r25) {
						PHALCON_ALLOC_ZVAL(r25);
					} else {
						if (Z_REFCOUNT_P(r25) > 1) {
							{
								zval *orig_ptr = r25;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r25);
									*r25 = *orig_ptr;
									zval_copy_ctor(r25);
									Z_SET_REFCOUNT_P(r25, 1);
									Z_UNSET_ISREF_P(r25);
								}
							}
						} else {
							FREE_ZVAL(r25);
							PHALCON_ALLOC_ZVAL(r25);
						}
					}
					phalcon_concat_vboth(r25, r26, "\" selected=\"selected\">", v8 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t5, "PHP_EOL");
					if (!r24) {
						PHALCON_ALLOC_ZVAL(r24);
					} else {
						if (Z_REFCOUNT_P(r24) > 1) {
							{
								zval *orig_ptr = r24;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r24);
									*r24 = *orig_ptr;
									zval_copy_ctor(r24);
									Z_SET_REFCOUNT_P(r24, 1);
									Z_UNSET_ISREF_P(r24);
								}
							}
						} else {
							FREE_ZVAL(r24);
							PHALCON_ALLOC_ZVAL(r24);
						}
					}
					phalcon_concat_vboth(r24, r25, "</option>", t5 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r27, v3, r24);
					if (v3) {
						Z_DELREF_P(v3);
						if (!Z_REFCOUNT_P(v3)) {
							FREE_ZVAL(v3);
						}
					}
					Z_ADDREF_P(r27);
					v3 = r27;
				} else {
					if (!t6) {
						PHALCON_ALLOC_ZVAL(t6);
					} else {
						if (Z_REFCOUNT_P(t6) > 1) {
							SEPARATE_ZVAL(&t6);
						} else {
							if (Z_TYPE_P(t6) != IS_STRING) {
								FREE_ZVAL(t6);
								PHALCON_ALLOC_ZVAL(t6);
							}
						}
					}
					ZVAL_STRING(t6, "\t", 1);
					if (!r30) {
						PHALCON_ALLOC_ZVAL(r30);
					} else {
						if (Z_REFCOUNT_P(r30) > 1) {
							{
								zval *orig_ptr = r30;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r30);
									*r30 = *orig_ptr;
									zval_copy_ctor(r30);
									Z_SET_REFCOUNT_P(r30, 1);
									Z_UNSET_ISREF_P(r30);
								}
							}
						} else {
							FREE_ZVAL(r30);
							PHALCON_ALLOC_ZVAL(r30);
						}
					}
					phalcon_concat_vboth(r30, t6, "<option value=\"", v9 TSRMLS_CC);
					if (!r29) {
						PHALCON_ALLOC_ZVAL(r29);
					} else {
						if (Z_REFCOUNT_P(r29) > 1) {
							{
								zval *orig_ptr = r29;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r29);
									*r29 = *orig_ptr;
									zval_copy_ctor(r29);
									Z_SET_REFCOUNT_P(r29, 1);
									Z_UNSET_ISREF_P(r29);
								}
							}
						} else {
							FREE_ZVAL(r29);
							PHALCON_ALLOC_ZVAL(r29);
						}
					}
					phalcon_concat_vboth(r29, r30, "\">", v8 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t7, "PHP_EOL");
					if (!r28) {
						PHALCON_ALLOC_ZVAL(r28);
					} else {
						if (Z_REFCOUNT_P(r28) > 1) {
							{
								zval *orig_ptr = r28;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r28);
									*r28 = *orig_ptr;
									zval_copy_ctor(r28);
									Z_SET_REFCOUNT_P(r28, 1);
									Z_UNSET_ISREF_P(r28);
								}
							}
						} else {
							FREE_ZVAL(r28);
							PHALCON_ALLOC_ZVAL(r28);
						}
					}
					phalcon_concat_vboth(r28, r29, "</option>", t7 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r31, v3, r28);
					if (v3) {
						Z_DELREF_P(v3);
						if (!Z_REFCOUNT_P(v3)) {
							FREE_ZVAL(v3);
						}
					}
					Z_ADDREF_P(r31);
					v3 = r31;
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
	PHALCON_CONCAT_FUNCTION(r32, v3, t8);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r32);
	v3 = r32;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getvaluefromaction", 1, p0);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r0);
		v2 = r0;
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r2);
		v2 = r2;
	}
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_array_fetch_long(r4, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_concat_left(r5, "<select id='", r4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r6);
	phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r3);
	phalcon_concat_vboth(r3, r5, "' name='", r6 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_concat_right(r7, r3, "' " TSRMLS_CC);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r7);
	v3 = r7;
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		FOREACH_KV(v0, ac0, fes81, fee81, ah0, hp0, v4, v2)
			if (Z_TYPE_P(v4) != IS_LONG) {
				if (Z_TYPE_P(v2) != IS_ARRAY) { 
					if (!r8) {
						PHALCON_ALLOC_ZVAL(r8);
					} else {
						if (Z_REFCOUNT_P(r8) > 1) {
							{
								zval *orig_ptr = r8;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r8);
									*r8 = *orig_ptr;
									zval_copy_ctor(r8);
									Z_SET_REFCOUNT_P(r8, 1);
									Z_UNSET_ISREF_P(r8);
								}
							}
						} else {
							FREE_ZVAL(r8);
							PHALCON_ALLOC_ZVAL(r8);
						}
					}
					phalcon_concat_vboth(r8, v4, "='", v2 TSRMLS_CC);
					if (!r9) {
						PHALCON_ALLOC_ZVAL(r9);
					} else {
						if (Z_REFCOUNT_P(r9) > 1) {
							{
								zval *orig_ptr = r9;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r9);
									*r9 = *orig_ptr;
									zval_copy_ctor(r9);
									Z_SET_REFCOUNT_P(r9, 1);
									Z_UNSET_ISREF_P(r9);
								}
							}
						} else {
							FREE_ZVAL(r9);
							PHALCON_ALLOC_ZVAL(r9);
						}
					}
					phalcon_concat_right(r9, r8, "' " TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r10, v3, r9);
					if (v3) {
						Z_DELREF_P(v3);
						if (!Z_REFCOUNT_P(v3)) {
							FREE_ZVAL(v3);
						}
					}
					Z_ADDREF_P(r10);
					v3 = r10;
				}
			}
		END_FOREACH(ac0, fes81, fee81, ah0, hp0);
	}
	PHALCON_GET_CONSTANT(t0, "PHP_EOL");
	PHALCON_ALLOC_ZVAL(r11);
	phalcon_concat_left(r11, ">", t0 TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r12, v3, r11);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r12);
	v3 = r12;
	eval_int = phalcon_array_isset_string(v0, "dummyValue", strlen("dummyValue")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_STRING(v5, "", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_array_fetch_string(r13, v0, "dummyValue", strlen("dummyValue"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r13);
		v5 = r13;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "dummyValue", strlen("dummyValue")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "dummyText", strlen("dummyText")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(v6);
		ZVAL_STRING(v6, "Choose...", 0);
	} else {
		PHALCON_ALLOC_ZVAL(r14);
		phalcon_array_fetch_string(r14, v0, "dummyText", strlen("dummyText"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r14);
		v6 = r14;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "dummyText", strlen("dummyText")+1);
	}
	eval_int = phalcon_array_isset_string(v0, "useDummy", strlen("useDummy")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "\t", 1);
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_concat_vboth(r17, t1, "<option value=\"", v5 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, r17, "\">", v6 TSRMLS_CC);
		PHALCON_GET_CONSTANT(t2, "PHP_EOL");
		PHALCON_ALLOC_ZVAL(r15);
		phalcon_concat_vboth(r15, r16, "</option>", t2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r18, v3, r15);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r18);
		v3 = r18;
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
				if (v7) {
					Z_DELREF_P(v7);
					if (!Z_REFCOUNT_P(v7)) {
						FREE_ZVAL(v7);
					}
				}
				Z_ADDREF_P(r22);
				v7 = r22;
				PHALCON_ALLOC_ZVAL(r23);
				phalcon_array_fetch_long(r23, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (v8) {
					Z_DELREF_P(v8);
					if (!Z_REFCOUNT_P(v8)) {
						FREE_ZVAL(v8);
					}
				}
				Z_ADDREF_P(r23);
				v8 = r23;
				PHALCON_CALL_METHOD_NORETURN(v8, "rewind", PHALCON_CALL_DEFAULT);
				ws82:
				PHALCON_ALLOC_ZVAL(r24);
				PHALCON_CALL_METHOD(r24, v8, "valid", PHALCON_CALL_DEFAULT);
				if (!zend_is_true(r24)) {
					goto we82;
				}
				if (!r25) {
					PHALCON_ALLOC_ZVAL(r25);
				} else {
					if (Z_REFCOUNT_P(r25) > 1) {
						{
							zval *orig_ptr = r25;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r25);
								*r25 = *orig_ptr;
								zval_copy_ctor(r25);
								Z_SET_REFCOUNT_P(r25, 1);
								Z_UNSET_ISREF_P(r25);
							}
						}
					} else {
						FREE_ZVAL(r25);
						PHALCON_ALLOC_ZVAL(r25);
					}
				}
				PHALCON_CALL_METHOD(r25, v8, "current", PHALCON_CALL_DEFAULT);
				if (v9) {
					Z_DELREF_P(v9);
					if (!Z_REFCOUNT_P(v9)) {
						FREE_ZVAL(v9);
					}
				}
				Z_ADDREF_P(r25);
				v9 = r25;
				if (!r26) {
					PHALCON_ALLOC_ZVAL(r26);
				} else {
					if (Z_REFCOUNT_P(r26) > 1) {
						{
							zval *orig_ptr = r26;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r26);
								*r26 = *orig_ptr;
								zval_copy_ctor(r26);
								Z_SET_REFCOUNT_P(r26, 1);
								Z_UNSET_ISREF_P(r26);
							}
						}
					} else {
						FREE_ZVAL(r26);
						PHALCON_ALLOC_ZVAL(r26);
					}
				}
				if (!r27) {
					PHALCON_ALLOC_ZVAL(r27);
				} else {
					if (Z_REFCOUNT_P(r27) > 1) {
						{
							zval *orig_ptr = r27;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r27);
								*r27 = *orig_ptr;
								zval_copy_ctor(r27);
								Z_SET_REFCOUNT_P(r27, 1);
								Z_UNSET_ISREF_P(r27);
							}
						}
					} else {
						FREE_ZVAL(r27);
						PHALCON_ALLOC_ZVAL(r27);
					}
				}
				phalcon_array_fetch_long(r27, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r27);
				p6[0] = r27;
				PHALCON_CALL_METHOD_PARAMS(r26, v9, "readattribute", 1, p6, PHALCON_CALL_DEFAULT);
				PHALCON_EQUAL_FUNCTION(r28, v2, r26);
				if (zend_is_true(r28)) {
					if (!t3) {
						PHALCON_ALLOC_ZVAL(t3);
					} else {
						if (Z_REFCOUNT_P(t3) > 1) {
							SEPARATE_ZVAL(&t3);
						} else {
							if (Z_TYPE_P(t3) != IS_STRING) {
								FREE_ZVAL(t3);
								PHALCON_ALLOC_ZVAL(t3);
							}
						}
					}
					ZVAL_STRING(t3, "\t", 1);
					if (!r32) {
						PHALCON_ALLOC_ZVAL(r32);
					} else {
						if (Z_REFCOUNT_P(r32) > 1) {
							{
								zval *orig_ptr = r32;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r32);
									*r32 = *orig_ptr;
									zval_copy_ctor(r32);
									Z_SET_REFCOUNT_P(r32, 1);
									Z_UNSET_ISREF_P(r32);
								}
							}
						} else {
							FREE_ZVAL(r32);
							PHALCON_ALLOC_ZVAL(r32);
						}
					}
					if (!r33) {
						PHALCON_ALLOC_ZVAL(r33);
					} else {
						if (Z_REFCOUNT_P(r33) > 1) {
							{
								zval *orig_ptr = r33;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r33);
									*r33 = *orig_ptr;
									zval_copy_ctor(r33);
									Z_SET_REFCOUNT_P(r33, 1);
									Z_UNSET_ISREF_P(r33);
								}
							}
						} else {
							FREE_ZVAL(r33);
							PHALCON_ALLOC_ZVAL(r33);
						}
					}
					phalcon_array_fetch_long(r33, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r33);
					p7[0] = r33;
					PHALCON_CALL_METHOD_PARAMS(r32, v9, "readattribute", 1, p7, PHALCON_CALL_DEFAULT);
					if (!r31) {
						PHALCON_ALLOC_ZVAL(r31);
					} else {
						if (Z_REFCOUNT_P(r31) > 1) {
							{
								zval *orig_ptr = r31;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r31);
									*r31 = *orig_ptr;
									zval_copy_ctor(r31);
									Z_SET_REFCOUNT_P(r31, 1);
									Z_UNSET_ISREF_P(r31);
								}
							}
						} else {
							FREE_ZVAL(r31);
							PHALCON_ALLOC_ZVAL(r31);
						}
					}
					phalcon_concat_vboth(r31, t3, "<option selected=\"selected\" value=\"", r32 TSRMLS_CC);
					if (!r34) {
						PHALCON_ALLOC_ZVAL(r34);
					} else {
						if (Z_REFCOUNT_P(r34) > 1) {
							{
								zval *orig_ptr = r34;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r34);
									*r34 = *orig_ptr;
									zval_copy_ctor(r34);
									Z_SET_REFCOUNT_P(r34, 1);
									Z_UNSET_ISREF_P(r34);
								}
							}
						} else {
							FREE_ZVAL(r34);
							PHALCON_ALLOC_ZVAL(r34);
						}
					}
					if (!r35) {
						PHALCON_ALLOC_ZVAL(r35);
					} else {
						if (Z_REFCOUNT_P(r35) > 1) {
							{
								zval *orig_ptr = r35;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r35);
									*r35 = *orig_ptr;
									zval_copy_ctor(r35);
									Z_SET_REFCOUNT_P(r35, 1);
									Z_UNSET_ISREF_P(r35);
								}
							}
						} else {
							FREE_ZVAL(r35);
							PHALCON_ALLOC_ZVAL(r35);
						}
					}
					phalcon_array_fetch_long(r35, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r35);
					p8[0] = r35;
					PHALCON_CALL_METHOD_PARAMS(r34, v9, "readattribute", 1, p8, PHALCON_CALL_DEFAULT);
					if (!r30) {
						PHALCON_ALLOC_ZVAL(r30);
					} else {
						if (Z_REFCOUNT_P(r30) > 1) {
							{
								zval *orig_ptr = r30;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r30);
									*r30 = *orig_ptr;
									zval_copy_ctor(r30);
									Z_SET_REFCOUNT_P(r30, 1);
									Z_UNSET_ISREF_P(r30);
								}
							}
						} else {
							FREE_ZVAL(r30);
							PHALCON_ALLOC_ZVAL(r30);
						}
					}
					phalcon_concat_vboth(r30, r31, "'>", r34 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t4, "PHP_EOL");
					if (!r29) {
						PHALCON_ALLOC_ZVAL(r29);
					} else {
						if (Z_REFCOUNT_P(r29) > 1) {
							{
								zval *orig_ptr = r29;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r29);
									*r29 = *orig_ptr;
									zval_copy_ctor(r29);
									Z_SET_REFCOUNT_P(r29, 1);
									Z_UNSET_ISREF_P(r29);
								}
							}
						} else {
							FREE_ZVAL(r29);
							PHALCON_ALLOC_ZVAL(r29);
						}
					}
					phalcon_concat_vboth(r29, r30, "</option>", t4 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r36, v3, r29);
					if (v3) {
						Z_DELREF_P(v3);
						if (!Z_REFCOUNT_P(v3)) {
							FREE_ZVAL(v3);
						}
					}
					Z_ADDREF_P(r36);
					v3 = r36;
				} else {
					if (!t5) {
						PHALCON_ALLOC_ZVAL(t5);
					} else {
						if (Z_REFCOUNT_P(t5) > 1) {
							SEPARATE_ZVAL(&t5);
						} else {
							if (Z_TYPE_P(t5) != IS_STRING) {
								FREE_ZVAL(t5);
								PHALCON_ALLOC_ZVAL(t5);
							}
						}
					}
					ZVAL_STRING(t5, "\t", 1);
					if (!r40) {
						PHALCON_ALLOC_ZVAL(r40);
					} else {
						if (Z_REFCOUNT_P(r40) > 1) {
							{
								zval *orig_ptr = r40;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r40);
									*r40 = *orig_ptr;
									zval_copy_ctor(r40);
									Z_SET_REFCOUNT_P(r40, 1);
									Z_UNSET_ISREF_P(r40);
								}
							}
						} else {
							FREE_ZVAL(r40);
							PHALCON_ALLOC_ZVAL(r40);
						}
					}
					if (!r41) {
						PHALCON_ALLOC_ZVAL(r41);
					} else {
						if (Z_REFCOUNT_P(r41) > 1) {
							{
								zval *orig_ptr = r41;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r41);
									*r41 = *orig_ptr;
									zval_copy_ctor(r41);
									Z_SET_REFCOUNT_P(r41, 1);
									Z_UNSET_ISREF_P(r41);
								}
							}
						} else {
							FREE_ZVAL(r41);
							PHALCON_ALLOC_ZVAL(r41);
						}
					}
					phalcon_array_fetch_long(r41, v7, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r41);
					p9[0] = r41;
					PHALCON_CALL_METHOD_PARAMS(r40, v9, "readattribute", 1, p9, PHALCON_CALL_DEFAULT);
					if (!r39) {
						PHALCON_ALLOC_ZVAL(r39);
					} else {
						if (Z_REFCOUNT_P(r39) > 1) {
							{
								zval *orig_ptr = r39;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r39);
									*r39 = *orig_ptr;
									zval_copy_ctor(r39);
									Z_SET_REFCOUNT_P(r39, 1);
									Z_UNSET_ISREF_P(r39);
								}
							}
						} else {
							FREE_ZVAL(r39);
							PHALCON_ALLOC_ZVAL(r39);
						}
					}
					phalcon_concat_vboth(r39, t5, "<option value=\"", r40 TSRMLS_CC);
					if (!r42) {
						PHALCON_ALLOC_ZVAL(r42);
					} else {
						if (Z_REFCOUNT_P(r42) > 1) {
							{
								zval *orig_ptr = r42;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r42);
									*r42 = *orig_ptr;
									zval_copy_ctor(r42);
									Z_SET_REFCOUNT_P(r42, 1);
									Z_UNSET_ISREF_P(r42);
								}
							}
						} else {
							FREE_ZVAL(r42);
							PHALCON_ALLOC_ZVAL(r42);
						}
					}
					if (!r43) {
						PHALCON_ALLOC_ZVAL(r43);
					} else {
						if (Z_REFCOUNT_P(r43) > 1) {
							{
								zval *orig_ptr = r43;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r43);
									*r43 = *orig_ptr;
									zval_copy_ctor(r43);
									Z_SET_REFCOUNT_P(r43, 1);
									Z_UNSET_ISREF_P(r43);
								}
							}
						} else {
							FREE_ZVAL(r43);
							PHALCON_ALLOC_ZVAL(r43);
						}
					}
					phalcon_array_fetch_long(r43, v7, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r43);
					p10[0] = r43;
					PHALCON_CALL_METHOD_PARAMS(r42, v9, "readattribute", 1, p10, PHALCON_CALL_DEFAULT);
					if (!r38) {
						PHALCON_ALLOC_ZVAL(r38);
					} else {
						if (Z_REFCOUNT_P(r38) > 1) {
							{
								zval *orig_ptr = r38;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r38);
									*r38 = *orig_ptr;
									zval_copy_ctor(r38);
									Z_SET_REFCOUNT_P(r38, 1);
									Z_UNSET_ISREF_P(r38);
								}
							}
						} else {
							FREE_ZVAL(r38);
							PHALCON_ALLOC_ZVAL(r38);
						}
					}
					phalcon_concat_vboth(r38, r39, "\">", r42 TSRMLS_CC);
					PHALCON_GET_CONSTANT(t6, "PHP_EOL");
					if (!r37) {
						PHALCON_ALLOC_ZVAL(r37);
					} else {
						if (Z_REFCOUNT_P(r37) > 1) {
							{
								zval *orig_ptr = r37;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(r37);
									*r37 = *orig_ptr;
									zval_copy_ctor(r37);
									Z_SET_REFCOUNT_P(r37, 1);
									Z_UNSET_ISREF_P(r37);
								}
							}
						} else {
							FREE_ZVAL(r37);
							PHALCON_ALLOC_ZVAL(r37);
						}
					}
					phalcon_concat_vboth(r37, r38, "</option>", t6 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r44, v3, r37);
					if (v3) {
						Z_DELREF_P(v3);
						if (!Z_REFCOUNT_P(v3)) {
							FREE_ZVAL(v3);
						}
					}
					Z_ADDREF_P(r44);
					v3 = r44;
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
						if (!t7) {
							PHALCON_ALLOC_ZVAL(t7);
						} else {
							if (Z_REFCOUNT_P(t7) > 1) {
								SEPARATE_ZVAL(&t7);
							} else {
								if (Z_TYPE_P(t7) != IS_STRING) {
									FREE_ZVAL(t7);
									PHALCON_ALLOC_ZVAL(t7);
								}
							}
						}
						ZVAL_STRING(t7, "\t", 1);
						if (!r50) {
							PHALCON_ALLOC_ZVAL(r50);
						} else {
							if (Z_REFCOUNT_P(r50) > 1) {
								{
									zval *orig_ptr = r50;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r50);
										*r50 = *orig_ptr;
										zval_copy_ctor(r50);
										Z_SET_REFCOUNT_P(r50, 1);
										Z_UNSET_ISREF_P(r50);
									}
								}
							} else {
								FREE_ZVAL(r50);
								PHALCON_ALLOC_ZVAL(r50);
							}
						}
						phalcon_array_fetch_long(r50, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (!r49) {
							PHALCON_ALLOC_ZVAL(r49);
						} else {
							if (Z_REFCOUNT_P(r49) > 1) {
								{
									zval *orig_ptr = r49;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r49);
										*r49 = *orig_ptr;
										zval_copy_ctor(r49);
										Z_SET_REFCOUNT_P(r49, 1);
										Z_UNSET_ISREF_P(r49);
									}
								}
							} else {
								FREE_ZVAL(r49);
								PHALCON_ALLOC_ZVAL(r49);
							}
						}
						phalcon_concat_vboth(r49, t7, "<option value=\"", r50 TSRMLS_CC);
						if (!r51) {
							PHALCON_ALLOC_ZVAL(r51);
						} else {
							if (Z_REFCOUNT_P(r51) > 1) {
								{
									zval *orig_ptr = r51;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r51);
										*r51 = *orig_ptr;
										zval_copy_ctor(r51);
										Z_SET_REFCOUNT_P(r51, 1);
										Z_UNSET_ISREF_P(r51);
									}
								}
							} else {
								FREE_ZVAL(r51);
								PHALCON_ALLOC_ZVAL(r51);
							}
						}
						phalcon_array_fetch_long(r51, v9, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (!r48) {
							PHALCON_ALLOC_ZVAL(r48);
						} else {
							if (Z_REFCOUNT_P(r48) > 1) {
								{
									zval *orig_ptr = r48;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r48);
										*r48 = *orig_ptr;
										zval_copy_ctor(r48);
										Z_SET_REFCOUNT_P(r48, 1);
										Z_UNSET_ISREF_P(r48);
									}
								}
							} else {
								FREE_ZVAL(r48);
								PHALCON_ALLOC_ZVAL(r48);
							}
						}
						phalcon_concat_vboth(r48, r49, "\">", r51 TSRMLS_CC);
						PHALCON_GET_CONSTANT(t8, "PHP_EOL");
						if (!r47) {
							PHALCON_ALLOC_ZVAL(r47);
						} else {
							if (Z_REFCOUNT_P(r47) > 1) {
								{
									zval *orig_ptr = r47;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r47);
										*r47 = *orig_ptr;
										zval_copy_ctor(r47);
										Z_SET_REFCOUNT_P(r47, 1);
										Z_UNSET_ISREF_P(r47);
									}
								}
							} else {
								FREE_ZVAL(r47);
								PHALCON_ALLOC_ZVAL(r47);
							}
						}
						phalcon_concat_vboth(r47, r48, "</option>", t8 TSRMLS_CC);
						PHALCON_CONCAT_FUNCTION(r52, v3, r47);
						if (v3) {
							Z_DELREF_P(v3);
							if (!Z_REFCOUNT_P(v3)) {
								FREE_ZVAL(v3);
							}
						}
						Z_ADDREF_P(r52);
						v3 = r52;
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
	PHALCON_CONCAT_FUNCTION(r53, v3, t9);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r53);
	v3 = r53;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v3);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "id", strlen("id"), PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_long(v0, 0, r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v0, "name", strlen("name")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "name", strlen("name"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "name", strlen("name"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (!zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_long(r3, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "name", strlen("name"), r3 TSRMLS_CC);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "value", strlen("value")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "value", strlen("value"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r4);
		v1 = r4;
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "value", strlen("value")+1);
	} else {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r6);
		p0[0] = r6;
		PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "_getvaluefromaction", 1, p0);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r5);
		v1 = r5;
	}
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r8);
	phalcon_concat_both(r8,  "<textarea id=\"", r7, "\" " TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r8);
	v2 = r8;
	FOREACH_KV(v0, ac0, fes84, fee84, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) != IS_LONG) {
			if (!r9) {
				PHALCON_ALLOC_ZVAL(r9);
			} else {
				if (Z_REFCOUNT_P(r9) > 1) {
					{
						zval *orig_ptr = r9;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r9);
							*r9 = *orig_ptr;
							zval_copy_ctor(r9);
							Z_SET_REFCOUNT_P(r9, 1);
							Z_UNSET_ISREF_P(r9);
						}
					}
				} else {
					FREE_ZVAL(r9);
					PHALCON_ALLOC_ZVAL(r9);
				}
			}
			phalcon_concat_vboth(r9, v4, "=\"", v3 TSRMLS_CC);
			if (!r10) {
				PHALCON_ALLOC_ZVAL(r10);
			} else {
				if (Z_REFCOUNT_P(r10) > 1) {
					{
						zval *orig_ptr = r10;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r10);
							*r10 = *orig_ptr;
							zval_copy_ctor(r10);
							Z_SET_REFCOUNT_P(r10, 1);
							Z_UNSET_ISREF_P(r10);
						}
					}
				} else {
					FREE_ZVAL(r10);
					PHALCON_ALLOC_ZVAL(r10);
				}
			}
			phalcon_concat_right(r10, r9, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r11, v2, r10);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r11);
			v2 = r11;
		}
	END_FOREACH(ac0, fes84, fee84, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r12);
	phalcon_concat_both(r12,  ">", v1, "</textarea>" TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r13, v2, r12);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r13);
	v2 = r13;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
	zval *t0 = NULL;
	zval *ac0 = NULL;
	zval *p1[] = { NULL, NULL }, *p5[] = { NULL }, *p6[] = { NULL };
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_SELF(r0, this_ptr, "_getdispatcher");
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(p1[0]);
	ZVAL_STRING(p1[0], "/", 1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v1, "getparams", PHALCON_CALL_DEFAULT);
	p1[1] = r2;
	PHALCON_CALL_FUNC_PARAMS(r1, "join", strlen("join"), 2, p1);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	eval_int = phalcon_array_isset_long(v0, 0);
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(v0, "action", strlen("action")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r3);
			phalcon_array_fetch_string(r3, v0, "action", strlen("action"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r3);
			v3 = r3;
		} else {
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, v1, "getcontrollername", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r6);
			PHALCON_CALL_METHOD(r6, v1, "getactionname", PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r4);
			phalcon_concat_vboth(r4, r5, "/", r6 TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r4);
			v3 = r4;
		}
	} else {
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_array_fetch_long(r7, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r7);
		v3 = r7;
	}
	eval_int = phalcon_array_isset_string(v0, "method", strlen("method")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_STRING(t0, "post", 1);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
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
		phalcon_concat_vboth(r9, r10, ";if(!confirm(\"", r11 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r12);
		phalcon_concat_right(r12, r9, "\")) { return false; }" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r13, r8, r12);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "onsubmit", strlen("onsubmit"), r13 TSRMLS_CC);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_unset_string(v0, "confirm", strlen("confirm")+1);
	}
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL(r14);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_STATIC_PARAMS(r14, "phalcon_utils", "geturl", 1, p5);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r14);
		v3 = r14;
	} else {
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_ALLOC_ZVAL(r16);
		phalcon_concat_vboth(r16, v3, "/", v2 TSRMLS_CC);
		Z_ADDREF_P(r16);
		p6[0] = r16;
		PHALCON_CALL_STATIC_PARAMS(r15, "phalcon_utils", "geturl", 1, p6);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r15);
		v3 = r15;
	}
	eval_int = phalcon_array_isset_string(v0, "parameters", strlen("parameters")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_array_fetch_string(r17, v0, "parameters", strlen("parameters"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r18);
		phalcon_concat_left(r18, "?", r17 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r19, v3, r18);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r19);
		v3 = r19;
	}
	PHALCON_ALLOC_ZVAL(r20);
	phalcon_concat_both(r20,  "<form action=\"", v3, "\" " TSRMLS_CC);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r20);
	v4 = r20;
	FOREACH_KV(v0, ac0, fes85, fee85, ah0, hp0, v6, v5)
		if (Z_TYPE_P(v6) != IS_LONG) {
			if (!r21) {
				PHALCON_ALLOC_ZVAL(r21);
			} else {
				if (Z_REFCOUNT_P(r21) > 1) {
					{
						zval *orig_ptr = r21;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r21);
							*r21 = *orig_ptr;
							zval_copy_ctor(r21);
							Z_SET_REFCOUNT_P(r21, 1);
							Z_UNSET_ISREF_P(r21);
						}
					}
				} else {
					FREE_ZVAL(r21);
					PHALCON_ALLOC_ZVAL(r21);
				}
			}
			phalcon_concat_vboth(r21, v6, "= \"", v5 TSRMLS_CC);
			if (!r22) {
				PHALCON_ALLOC_ZVAL(r22);
			} else {
				if (Z_REFCOUNT_P(r22) > 1) {
					{
						zval *orig_ptr = r22;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r22);
							*r22 = *orig_ptr;
							zval_copy_ctor(r22);
							Z_SET_REFCOUNT_P(r22, 1);
							Z_UNSET_ISREF_P(r22);
						}
					}
				} else {
					FREE_ZVAL(r22);
					PHALCON_ALLOC_ZVAL(r22);
				}
			}
			phalcon_concat_right(r22, r21, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r23, v4, r22);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r23);
			v4 = r23;
		}
	END_FOREACH(ac0, fes85, fee85, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r24);
	phalcon_concat_right(r24, v4, ">" TSRMLS_CC);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r24);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
	PHALCON_CONCAT_FUNCTION(r0, t0, v0);
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
	phalcon_concat_both(r0,  "<title>", t0, "</title>" TSRMLS_CC);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r0);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
		PHALCON_INIT_BOOL(v1, 1);
	}
	
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_string(v0, "href", strlen("href")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "href", strlen("href"), r0 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "href", strlen("href"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "", 0);
	eval_int = phalcon_array_isset_long(v0, 1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r1);
		phalcon_array_fetch_long(r1, v0, 1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v1) {
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
	} else {
		eval_int = phalcon_array_isset_string(v0, "local", strlen("local")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_array_fetch_string(r2, v0, "local", strlen("local"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v1) {
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r2);
			v1 = r2;
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_unset_string(v0, "local", strlen("local")+1);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "type", strlen("type")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_STRING(t1, "text/css", 1);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "type", strlen("type"), t1 TSRMLS_CC);
	}
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "href", strlen("href"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r4);
		p0[0] = r4;
		PHALCON_CALL_STATIC_PARAMS(r3, "phalcon_utils", "geturl", 1, p0);
		{
			zval *orig_ptr = v0;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				ALLOC_ZVAL(v0);
				*v0 = *orig_ptr;
				zval_copy_ctor(v0);
				Z_SET_REFCOUNT_P(v0, 1);
				Z_UNSET_ISREF_P(v0);
			}
		}
		phalcon_array_update_string(v0, "href", strlen("href"), r3 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "<link rel=\"stylesheet\" ", 0);
	FOREACH_KV(v0, ac0, fes86, fee86, ah0, hp0, v4, v3)
		if (Z_TYPE_P(v4) != IS_LONG) {
			if (!r6) {
				PHALCON_ALLOC_ZVAL(r6);
			} else {
				if (Z_REFCOUNT_P(r6) > 1) {
					{
						zval *orig_ptr = r6;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r6);
							*r6 = *orig_ptr;
							zval_copy_ctor(r6);
							Z_SET_REFCOUNT_P(r6, 1);
							Z_UNSET_ISREF_P(r6);
						}
					}
				} else {
					FREE_ZVAL(r6);
					PHALCON_ALLOC_ZVAL(r6);
				}
			}
			phalcon_concat_left(r6, " ", v4 TSRMLS_CC);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					{
						zval *orig_ptr = r5;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r5);
							*r5 = *orig_ptr;
							zval_copy_ctor(r5);
							Z_SET_REFCOUNT_P(r5, 1);
							Z_UNSET_ISREF_P(r5);
						}
					}
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			phalcon_concat_vboth(r5, r6, "=\"", v3 TSRMLS_CC);
			if (!r7) {
				PHALCON_ALLOC_ZVAL(r7);
			} else {
				if (Z_REFCOUNT_P(r7) > 1) {
					{
						zval *orig_ptr = r7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r7);
							*r7 = *orig_ptr;
							zval_copy_ctor(r7);
							Z_SET_REFCOUNT_P(r7, 1);
							Z_UNSET_ISREF_P(r7);
						}
					}
				} else {
					FREE_ZVAL(r7);
					PHALCON_ALLOC_ZVAL(r7);
				}
			}
			phalcon_concat_right(r7, r5, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r8, v2, r7);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r8);
			v2 = r8;
		}
	END_FOREACH(ac0, fes86, fee86, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t2);
	ZVAL_STRING(t2, ">", 1);
	PHALCON_CONCAT_FUNCTION(r9, v2, t2);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r9);
	v2 = r9;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v2);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
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
			{
				zval *orig_ptr = a0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(a0);
					*a0 = *orig_ptr;
					zval_copy_ctor(a0);
					Z_SET_REFCOUNT_P(a0, 1);
					Z_UNSET_ISREF_P(a0);
				}
			}
			add_next_index_zval(a0, copy);
		}
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a0);
		v0 = a0;
	}
	eval_int = phalcon_array_isset_string(v0, "src", strlen("src")+1);
	if (!eval_int) {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_long(r0, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "src", strlen("src"), r0 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, "", 1);
			{
				zval *orig_ptr = v0;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					ALLOC_ZVAL(v0);
					*v0 = *orig_ptr;
					zval_copy_ctor(v0);
					Z_SET_REFCOUNT_P(v0, 1);
					Z_UNSET_ISREF_P(v0);
				}
			}
			phalcon_array_update_string(v0, "src", strlen("src"), t0 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v0, "src", strlen("src"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p0[0] = r2;
	PHALCON_CALL_STATIC_PARAMS(r1, "phalcon_utils", "geturl", 1, p0);
	{
		zval *orig_ptr = v0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			ALLOC_ZVAL(v0);
			*v0 = *orig_ptr;
			zval_copy_ctor(v0);
			Z_SET_REFCOUNT_P(v0, 1);
			Z_UNSET_ISREF_P(v0);
		}
	}
	phalcon_array_update_string(v0, "src", strlen("src"), r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "<img ", 0);
	FOREACH_KV(v0, ac0, fes87, fee87, ah0, hp0, v3, v2)
		if (Z_TYPE_P(v3) != IS_LONG) {
			if (!r4) {
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if (Z_REFCOUNT_P(r4) > 1) {
					{
						zval *orig_ptr = r4;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r4);
							*r4 = *orig_ptr;
							zval_copy_ctor(r4);
							Z_SET_REFCOUNT_P(r4, 1);
							Z_UNSET_ISREF_P(r4);
						}
					}
				} else {
					FREE_ZVAL(r4);
					PHALCON_ALLOC_ZVAL(r4);
				}
			}
			phalcon_concat_left(r4, " ", v3 TSRMLS_CC);
			if (!r3) {
				PHALCON_ALLOC_ZVAL(r3);
			} else {
				if (Z_REFCOUNT_P(r3) > 1) {
					{
						zval *orig_ptr = r3;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r3);
							*r3 = *orig_ptr;
							zval_copy_ctor(r3);
							Z_SET_REFCOUNT_P(r3, 1);
							Z_UNSET_ISREF_P(r3);
						}
					}
				} else {
					FREE_ZVAL(r3);
					PHALCON_ALLOC_ZVAL(r3);
				}
			}
			phalcon_concat_vboth(r3, r4, "=\"", v2 TSRMLS_CC);
			if (!r5) {
				PHALCON_ALLOC_ZVAL(r5);
			} else {
				if (Z_REFCOUNT_P(r5) > 1) {
					{
						zval *orig_ptr = r5;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r5);
							*r5 = *orig_ptr;
							zval_copy_ctor(r5);
							Z_SET_REFCOUNT_P(r5, 1);
							Z_UNSET_ISREF_P(r5);
						}
					}
				} else {
					FREE_ZVAL(r5);
					PHALCON_ALLOC_ZVAL(r5);
				}
			}
			phalcon_concat_right(r5, r3, "\" " TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r6, v1, r5);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r6);
			v1 = r6;
		}
	END_FOREACH(ac0, fes87, fee87, ah0, hp0);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, ">", 1);
	PHALCON_CONCAT_FUNCTION(r7, v1, t1);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r7);
	v1 = r7;
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
}

