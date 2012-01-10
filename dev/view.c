
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

PHP_METHOD(Phalcon_View, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *v0 = NULL;

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_params", strlen("_params"), a0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a1);
	array_init(a1);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesBefore", strlen("_templatesBefore"), a1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(a2);
	array_init(a2);
	zend_update_property(phalcon_view_class_entry, this_ptr, "_templatesAfter", strlen("_templatesAfter"), a2 TSRMLS_CC);
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_frontController", strlen("_frontController"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setViewsDir){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_viewsDir", strlen("_viewsDir"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setTemplateBefore){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

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
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_templatesBefore", strlen("_templatesBefore"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setTemplateAfter){

	zval *v0 = NULL;
	zval *a0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

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
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_templatesAfter", strlen("_templatesAfter"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, setParamToView){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *orig_ptr = t0;
		if (Z_REFCOUNT_P(orig_ptr) > 1) {
			Z_DELREF_P(orig_ptr);
			ALLOC_ZVAL(t0);
			*t0 = *orig_ptr;
			zval_copy_ctor(t0);
			Z_SET_REFCOUNT_P(t0, 1);
			Z_UNSET_ISREF_P(t0);
		}
	}
	phalcon_array_update(t0, v0, v1 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, render){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	zval *ac0 = NULL, *ac1 = NULL, *ac2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p8[] = { NULL }, *p13[] = { NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_frontController", sizeof("_frontController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r0, t0, "getbasepath", PHALCON_CALL_DEFAULT);
	if(v1){
		Z_DELREF_P(v1);
		if(!Z_REFCOUNT_P(v1)){
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v0, "getcontrollername", PHALCON_CALL_DEFAULT);
	if(v2){
		Z_DELREF_P(v2);
		if(!Z_REFCOUNT_P(v2)){
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v0, "getactionname", PHALCON_CALL_DEFAULT);
	if(v3){
		Z_DELREF_P(v3);
		if(!Z_REFCOUNT_P(v3)){
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r2);
	v3 = r2;
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	FOREACH_KV(t1, ac0, fes6, fee6, ah0, hp0, v5, v4)
		ZEND_SET_SYMBOL(EG(active_symbol_table), Z_STRVAL_P(v5), v4);
	END_FOREACH(ac0, fes6, fee6, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_FUNC(r3, "ob_get_contents");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, r3, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r4);
	phalcon_concat_right(r4, v1, "app/views/" TSRMLS_CC);
	if(v6){
		Z_DELREF_P(v6);
		if(!Z_REFCOUNT_P(v6)){
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r4);
	v6 = r4;
	PHALCON_CONCAT_FUNCTION(r6, v6, v2);
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_concat_vboth(r5, r6, "/", v3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r7);
	phalcon_concat_right(r7, r5, ".phtml" TSRMLS_CC);
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(r7);
	v7 = r7;
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_ALLOC_ZVAL(r8);
		PHALCON_CALL_FUNC(r8, "ob_get_contents");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r8, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_layoutsDir", sizeof("_layoutsDir")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(v8){
		Z_DELREF_P(v8);
		if(!Z_REFCOUNT_P(v8)){
			FREE_ZVAL(v8);
		}
	}
	Z_ADDREF_P(t2);
	v8 = t2;
	PHALCON_ALLOC_ZVAL(t3);
	phalcon_read_property(t3, this_ptr, "_templatesBefore", sizeof("_templatesBefore")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(v9){
		Z_DELREF_P(v9);
		if(!Z_REFCOUNT_P(v9)){
			FREE_ZVAL(v9);
		}
	}
	Z_ADDREF_P(t3);
	v9 = t3;
	if(Z_TYPE_P(v9)==IS_ARRAY){
		if(v7){
			Z_DELREF_P(v7);
			if(!Z_REFCOUNT_P(v7)){
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(v6);
		v7 = v6;
		if(phalcon_compare_strict_string(v8, "")){
			PHALCON_ALLOC_ZVAL(t4);
			ZVAL_STRING(t4, "layouts/", 0);
			PHALCON_CONCAT_FUNCTION(r9, v7, t4);
			if(v7){
				Z_DELREF_P(v7);
				if(!Z_REFCOUNT_P(v7)){
					FREE_ZVAL(v7);
				}
			}
			Z_ADDREF_P(r9);
			v7 = r9;
		} else {
			PHALCON_ALLOC_ZVAL(r10);
			phalcon_concat_right(r10, v8, "/" TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r11, v7, r10);
			if(v7){
				Z_DELREF_P(v7);
				if(!Z_REFCOUNT_P(v7)){
					FREE_ZVAL(v7);
				}
			}
			Z_ADDREF_P(r11);
			v7 = r11;
		}
		FOREACH_V(v9, ac1, fes7, fee7, ah1, hp1, v10)
			PHALCON_CONCAT_FUNCTION(r12, v7, v10);
			if(!r13){
				PHALCON_ALLOC_ZVAL(r13);
			} else {
				if(Z_REFCOUNT_P(r13)>1){
					{
						zval *orig_ptr = r13;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r13);
							*r13 = *orig_ptr;
							zval_copy_ctor(r13);
							Z_SET_REFCOUNT_P(r13, 1);
							Z_UNSET_ISREF_P(r13);
						}
					}
				} else {
					FREE_ZVAL(r13);
					PHALCON_ALLOC_ZVAL(r13);
				}
			}
			phalcon_concat_right(r13, r12, ".phtml" TSRMLS_CC);
			if(v11){
				Z_DELREF_P(v11);
				if(!Z_REFCOUNT_P(v11)){
					FREE_ZVAL(v11);
				}
			}
			Z_ADDREF_P(r13);
			v11 = r13;
			if(phalcon_file_exists(v11 TSRMLS_CC)==SUCCESS){
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_require(v11 TSRMLS_CC);
				if(EG(exception)||EG(exit_status)==255){
					return;
				}
				if(!r14){
					PHALCON_ALLOC_ZVAL(r14);
				} else {
					if(Z_REFCOUNT_P(r14)>1){
						{
							zval *orig_ptr = r14;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r14);
								*r14 = *orig_ptr;
								zval_copy_ctor(r14);
								Z_SET_REFCOUNT_P(r14, 1);
								Z_UNSET_ISREF_P(r14);
							}
						}
					} else {
						FREE_ZVAL(r14);
						PHALCON_ALLOC_ZVAL(r14);
					}
				}
				PHALCON_CALL_FUNC(r14, "ob_get_contents");
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r14, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			} else {
				if(!i0){
					PHALCON_ALLOC_ZVAL(i0);
				} else {
					if(Z_REFCOUNT_P(i0)>1){
						{
							zval *orig_ptr = i0;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(i0);
								*i0 = *orig_ptr;
								zval_copy_ctor(i0);
								Z_SET_REFCOUNT_P(i0, 1);
								Z_UNSET_ISREF_P(i0);
							}
						}
					} else {
						FREE_ZVAL(i0);
						PHALCON_ALLOC_ZVAL(i0);
					}
				}
				object_init_ex(i0, phalcon_view_exception_class_entry);
				if(!r15){
					PHALCON_ALLOC_ZVAL(r15);
				} else {
					if(Z_REFCOUNT_P(r15)>1){
						{
							zval *orig_ptr = r15;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(r15);
								*r15 = *orig_ptr;
								zval_copy_ctor(r15);
								Z_SET_REFCOUNT_P(r15, 1);
								Z_UNSET_ISREF_P(r15);
							}
						}
					} else {
						FREE_ZVAL(r15);
						PHALCON_ALLOC_ZVAL(r15);
					}
				}
				phalcon_concat_both(r15,  "Template '", v10, "' was not found on templates directory" TSRMLS_CC);
				Z_ADDREF_P(r15);
				p8[0] = r15;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p8, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i0 TSRMLS_CC);
				Z_ADDREF_P(i0);
				return;
			}
		END_FOREACH(ac1, fes7, fee7, ah1, hp1);
	}
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(v6);
	v7 = v6;
	if(phalcon_compare_strict_string(v8, "")){
		PHALCON_ALLOC_ZVAL(t5);
		ZVAL_STRING(t5, "layouts/", 0);
		PHALCON_CONCAT_FUNCTION(r16, v7, t5);
		if(v7){
			Z_DELREF_P(v7);
			if(!Z_REFCOUNT_P(v7)){
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(r16);
		v7 = r16;
	} else {
		PHALCON_ALLOC_ZVAL(r17);
		phalcon_concat_right(r17, v8, "/" TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r18, v7, r17);
		if(v7){
			Z_DELREF_P(v7);
			if(!Z_REFCOUNT_P(v7)){
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(r18);
		v7 = r18;
	}
	PHALCON_ALLOC_ZVAL(r19);
	phalcon_concat_right(r19, v2, ".phtml" TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r20, v7, r19);
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(r20);
	v7 = r20;
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_ALLOC_ZVAL(r21);
		PHALCON_CALL_FUNC(r21, "ob_get_contents");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r21, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t6);
	phalcon_read_property(t6, this_ptr, "_templatesAfter", sizeof("_templatesAfter")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(v12){
		Z_DELREF_P(v12);
		if(!Z_REFCOUNT_P(v12)){
			FREE_ZVAL(v12);
		}
	}
	Z_ADDREF_P(t6);
	v12 = t6;
	if(Z_TYPE_P(v12)==IS_ARRAY){
		if(v7){
			Z_DELREF_P(v7);
			if(!Z_REFCOUNT_P(v7)){
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(v6);
		v7 = v6;
		if(phalcon_compare_strict_string(v8, "")){
			PHALCON_ALLOC_ZVAL(t7);
			ZVAL_STRING(t7, "layouts/", 0);
			PHALCON_CONCAT_FUNCTION(r22, v7, t7);
			if(v7){
				Z_DELREF_P(v7);
				if(!Z_REFCOUNT_P(v7)){
					FREE_ZVAL(v7);
				}
			}
			Z_ADDREF_P(r22);
			v7 = r22;
		} else {
			PHALCON_ALLOC_ZVAL(r23);
			phalcon_concat_right(r23, v8, "/" TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r24, v7, r23);
			if(v7){
				Z_DELREF_P(v7);
				if(!Z_REFCOUNT_P(v7)){
					FREE_ZVAL(v7);
				}
			}
			Z_ADDREF_P(r24);
			v7 = r24;
		}
		FOREACH_V(v12, ac2, fes8, fee8, ah2, hp2, v13)
			PHALCON_CONCAT_FUNCTION(r25, v7, v13);
			if(!r26){
				PHALCON_ALLOC_ZVAL(r26);
			} else {
				if(Z_REFCOUNT_P(r26)>1){
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
			phalcon_concat_right(r26, r25, ".phtml" TSRMLS_CC);
			if(v11){
				Z_DELREF_P(v11);
				if(!Z_REFCOUNT_P(v11)){
					FREE_ZVAL(v11);
				}
			}
			Z_ADDREF_P(r26);
			v11 = r26;
			if(phalcon_file_exists(v11 TSRMLS_CC)==SUCCESS){
				PHALCON_CALL_FUNC_NORETURN("ob_clean");
				phalcon_require(v11 TSRMLS_CC);
				if(EG(exception)||EG(exit_status)==255){
					return;
				}
				if(!r27){
					PHALCON_ALLOC_ZVAL(r27);
				} else {
					if(Z_REFCOUNT_P(r27)>1){
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
				PHALCON_CALL_FUNC(r27, "ob_get_contents");
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r27, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
				}
			} else {
				if(!i1){
					PHALCON_ALLOC_ZVAL(i1);
				} else {
					if(Z_REFCOUNT_P(i1)>1){
						{
							zval *orig_ptr = i1;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(i1);
								*i1 = *orig_ptr;
								zval_copy_ctor(i1);
								Z_SET_REFCOUNT_P(i1, 1);
								Z_UNSET_ISREF_P(i1);
							}
						}
					} else {
						FREE_ZVAL(i1);
						PHALCON_ALLOC_ZVAL(i1);
					}
				}
				object_init_ex(i1, phalcon_view_exception_class_entry);
				if(!r28){
					PHALCON_ALLOC_ZVAL(r28);
				} else {
					if(Z_REFCOUNT_P(r28)>1){
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
				phalcon_concat_both(r28,  "Template '", v10, "' was not found on templates directory" TSRMLS_CC);
				Z_ADDREF_P(r28);
				p13[0] = r28;
				PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p13, PHALCON_CALL_CHECK);
				zend_throw_exception_object(i1 TSRMLS_CC);
				Z_ADDREF_P(i1);
				return;
			}
		END_FOREACH(ac2, fes8, fee8, ah2, hp2);
	}
	PHALCON_ALLOC_ZVAL(r29);
	phalcon_concat_right(r29, v1, "app/views/index.phtml" TSRMLS_CC);
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(r29);
	v7 = r29;
	if(phalcon_file_exists(v7 TSRMLS_CC)==SUCCESS){
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
		phalcon_require(v7 TSRMLS_CC);
		if(EG(exception)||EG(exit_status)==255){
			return;
		}
		PHALCON_ALLOC_ZVAL(r30);
		PHALCON_CALL_FUNC(r30, "ob_get_contents");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r30, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_content", strlen("_content"), copy TSRMLS_CC);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, getContent){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_content", sizeof("_content")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(Z_TYPE_P(t0)>IS_BOOL){
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(t0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

PHP_METHOD(Phalcon_View, url){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_frontController", sizeof("_frontController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(v1){
		Z_DELREF_P(v1);
		if(!Z_REFCOUNT_P(v1)){
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(t0);
	v1 = t0;
	if(Z_TYPE_P(v0)==IS_ARRAY){
		p0[0] = v0;
		PHALCON_CALL_FUNC_PARAMS_NORETURN("print_r", 1, p0);
	} else {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, v1, "getbaseuri", PHALCON_CALL_DEFAULT);
		PHALCON_CONCAT_FUNCTION(r1, r0, v0);
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(r1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View, path){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_frontController", sizeof("_frontController")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(v1){
		Z_DELREF_P(v1);
		if(!Z_REFCOUNT_P(v1)){
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(t0);
	v1 = t0;
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v1, "getbasepath", PHALCON_CALL_DEFAULT);
	PHALCON_CONCAT_FUNCTION(r1, r0, v0);
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(r1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
}

