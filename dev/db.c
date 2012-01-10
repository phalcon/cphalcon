
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

PHP_METHOD(Phalcon_Db, __construct){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, setLogger){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(zend_is_true(t0)){
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v0);
		p0[0] = v0;
		Z_ADDREF_P(v1);
		p0[1] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, fetchOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	if(v1){
		Z_DELREF_P(v1);
		if(!Z_REFCOUNT_P(v1)){
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	if(zend_is_true(v1)){
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v1);
		p1[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r1, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(a0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, fetchAll){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if(v1){
		Z_DELREF_P(v1);
		if(!Z_REFCOUNT_P(v1)){
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	if(v2){
		Z_DELREF_P(v2);
		if(!Z_REFCOUNT_P(v2)){
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	PHALCON_INIT_FALSE(t0);
	PHALCON_NOT_EQUAL_FUNCTION(r1, v2, t0);
	if(zend_is_true(r1)){
		ws11:
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v2);
		p1[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		if(v3){
			Z_DELREF_P(v3);
			if(!Z_REFCOUNT_P(v3)){
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r2);
		v3 = r2;
		if(!zend_is_true(v3)){
			goto we11;
		}
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v3, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v1;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v1);
					*v1 = *orig_ptr;
					zval_copy_ctor(v1);
					Z_SET_REFCOUNT_P(v1, 1);
					Z_UNSET_ISREF_P(v1);
				}
			}
			phalcon_array_append(v1, copy TSRMLS_CC);
		}
		goto ws11;
		we11:
		v3 = NULL;
	}
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

PHP_METHOD(Phalcon_Db, insert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE){
		RETURN_NULL();
	}

	if(!v2){
		PHALCON_INIT_NULL(v2);
	}
	if(!v3){
		PHALCON_INIT_BOOL(v3, 0);
	}
	
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_STRING(v4, "", 0);
	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_ALLOC_ZVAL(r0);
		p0[0] = v1;
		PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, r0, t0);
		if(zend_is_true(r1)){
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_both(r2,  "Unable to insert into ", v0, " without data" TSRMLS_CC);
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_PARAM_BOOL(p1[2], 1);
			Z_ADDREF_P(this_ptr);
			p1[3] = this_ptr;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			if(zend_is_true(v3)){
				FOREACH_KV(v1, ac0, fes12, fee12, ah0, hp0, v6, v5)
					if(!r3){
						PHALCON_ALLOC_ZVAL(r3);
					} else {
						if(Z_REFCOUNT_P(r3)>1){
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
					phalcon_array_fetch(r3, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					if(Z_TYPE_P(r3)==IS_OBJECT){
						if(!r4){
							PHALCON_ALLOC_ZVAL(r4);
						} else {
							if(Z_REFCOUNT_P(r4)>1){
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
						phalcon_array_fetch(r4, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						if(!r5){
							PHALCON_ALLOC_ZVAL(r5);
						} else {
							if(Z_REFCOUNT_P(r5)>1){
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
							}
						}
						phalcon_instance_of(r5, r4, phalcon_db_rawvalue_class_entry);
						if(zend_is_true(r5)){
							if(!r6){
								PHALCON_ALLOC_ZVAL(r6);
							} else {
								if(Z_REFCOUNT_P(r6)>1){
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
							if(!r7){
								PHALCON_ALLOC_ZVAL(r7);
							} else {
								if(Z_REFCOUNT_P(r7)>1){
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
							if(!r8){
								PHALCON_ALLOC_ZVAL(r8);
							} else {
								if(Z_REFCOUNT_P(r8)>1){
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
							phalcon_array_fetch(r8, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_CALL_DEFAULT);
							Z_ADDREF_P(r7);
							p2[0] = r7;
							PHALCON_CALL_FUNC_PARAMS(r6, "addslashes", 1, p2);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r6, 1, 0);
								Z_SET_REFCOUNT_P(copy, 0);
								{
									zval *orig_ptr = v1;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										ALLOC_ZVAL(v1);
										*v1 = *orig_ptr;
										zval_copy_ctor(v1);
										Z_SET_REFCOUNT_P(v1, 1);
										Z_UNSET_ISREF_P(v1);
									}
								}
								phalcon_array_update(v1, v6, copy TSRMLS_CC);
							}
							goto fes12;
						} else {
							if(!r9){
								PHALCON_ALLOC_ZVAL(r9);
							} else {
								if(Z_REFCOUNT_P(r9)>1){
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
							if(!r10){
								PHALCON_ALLOC_ZVAL(r10);
							} else {
								if(Z_REFCOUNT_P(r10)>1){
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
							phalcon_array_fetch(r10, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(r10);
							p4[0] = r10;
							PHALCON_CALL_FUNC_PARAMS(r9, "addslashes", 1, p4);
							if(!r11){
								PHALCON_ALLOC_ZVAL(r11);
							} else {
								if(Z_REFCOUNT_P(r11)>1){
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
							phalcon_concat_both(r11,  "'", r9, "'" TSRMLS_CC);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r11, 1, 0);
								Z_SET_REFCOUNT_P(copy, 0);
								{
									zval *orig_ptr = v1;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										ALLOC_ZVAL(v1);
										*v1 = *orig_ptr;
										zval_copy_ctor(v1);
										Z_SET_REFCOUNT_P(v1, 1);
										Z_UNSET_ISREF_P(v1);
									}
								}
								phalcon_array_update(v1, v6, copy TSRMLS_CC);
							}
						}
					} else {
						if(!r12){
							PHALCON_ALLOC_ZVAL(r12);
						} else {
							if(Z_REFCOUNT_P(r12)>1){
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
						phalcon_array_fetch(r13, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						Z_ADDREF_P(r13);
						p5[0] = r13;
						PHALCON_CALL_FUNC_PARAMS(r12, "addslashes", 1, p5);
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
						phalcon_concat_both(r14,  "'", r12, "'" TSRMLS_CC);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r14, 1, 0);
							Z_SET_REFCOUNT_P(copy, 0);
							{
								zval *orig_ptr = v1;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									ALLOC_ZVAL(v1);
									*v1 = *orig_ptr;
									zval_copy_ctor(v1);
									Z_SET_REFCOUNT_P(v1, 1);
									Z_UNSET_ISREF_P(v1);
								}
							}
							phalcon_array_update(v1, v6, copy TSRMLS_CC);
						}
					}
				END_FOREACH(ac0, fes12, fee12, ah0, hp0);
			}
		}
		if(Z_TYPE_P(v2)==IS_ARRAY){
			PHALCON_ALLOC_ZVAL(r17);
			phalcon_concat_left(r17, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r18);
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], ", ", 1);
			p6[1] = v2;
			PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p6);
			PHALCON_ALLOC_ZVAL(r16);
			phalcon_concat_vboth(r16, r17, " (", r18 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r19);
			PHALCON_ALLOC_ZVAL(p7[0]);
			ZVAL_STRING(p7[0], ", ", 1);
			p7[1] = v1;
			PHALCON_CALL_FUNC_PARAMS(r19, "join", 2, p7);
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_concat_vboth(r15, r16, ") VALUES (", r19 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_concat_right(r20, r15, ")" TSRMLS_CC);
			if(v4){
				Z_DELREF_P(v4);
				if(!Z_REFCOUNT_P(v4)){
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r20);
			v4 = r20;
		} else {
			PHALCON_ALLOC_ZVAL(r22);
			phalcon_concat_left(r22, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r23);
			PHALCON_ALLOC_ZVAL(p8[0]);
			ZVAL_STRING(p8[0], ", ", 1);
			p8[1] = v1;
			PHALCON_CALL_FUNC_PARAMS(r23, "join", 2, p8);
			PHALCON_ALLOC_ZVAL(r21);
			phalcon_concat_vboth(r21, r22, " VALUES (", r23 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r24);
			phalcon_concat_right(r24, r21, ")" TSRMLS_CC);
			if(v4){
				Z_DELREF_P(v4);
				if(!Z_REFCOUNT_P(v4)){
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r24);
			v4 = r24;
		}
		PHALCON_ALLOC_ZVAL(r25);
		Z_ADDREF_P(v4);
		p9[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r25, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p10[0]);
		ZVAL_STRING(p10[0], "The second parameter for insert isn't an Array", 1);
		PHALCON_PARAM_LONG(p10[1], 0);
		PHALCON_PARAM_BOOL(p10[2], 1);
		Z_ADDREF_P(this_ptr);
		p10[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p10, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, update){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL, NULL, NULL, NULL }, *p3[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE){
		RETURN_NULL();
	}

	if(!v3){
		PHALCON_INIT_NULL(v3);
	}
	if(!v4){
		PHALCON_INIT_BOOL(v4, 0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_both(r0,  "UPDATE ", v0, " SET " TSRMLS_CC);
	if(v5){
		Z_DELREF_P(v5);
		if(!Z_REFCOUNT_P(v5)){
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(r0);
	v5 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	p0[0] = v1;
	PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
	PHALCON_ALLOC_ZVAL(r2);
	p1[0] = v2;
	PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p1);
	PHALCON_NOT_EQUAL_FUNCTION(r3, r1, r2);
	if(zend_is_true(r3)){
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "The number of values to update is not the same as fields", 1);
		PHALCON_PARAM_LONG(p2[1], 0);
		PHALCON_PARAM_BOOL(p2[2], 1);
		Z_ADDREF_P(this_ptr);
		p2[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_LONG(v6, 0);
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(a0);
	v7 = a0;
	FOREACH_V(v1, ac0, fes13, fee13, ah0, hp0, v8)
		if(zend_is_true(v4)){
			if(!r4){
				PHALCON_ALLOC_ZVAL(r4);
			} else {
				if(Z_REFCOUNT_P(r4)>1){
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
			phalcon_array_fetch(r4, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			if(Z_TYPE_P(r4)==IS_OBJECT){
				if(!r5){
					PHALCON_ALLOC_ZVAL(r5);
				} else {
					if(Z_REFCOUNT_P(r5)>1){
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
				phalcon_array_fetch(r5, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				if(!r6){
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if(Z_REFCOUNT_P(r6)>1){
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
					}
				}
				phalcon_instance_of(r6, r5, phalcon_db_rawvalue_class_entry);
				if(zend_is_true(r6)){
					if(!r7){
						PHALCON_ALLOC_ZVAL(r7);
					} else {
						if(Z_REFCOUNT_P(r7)>1){
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
					if(!r8){
						PHALCON_ALLOC_ZVAL(r8);
					} else {
						if(Z_REFCOUNT_P(r8)>1){
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
					if(!r9){
						PHALCON_ALLOC_ZVAL(r9);
					} else {
						if(Z_REFCOUNT_P(r9)>1){
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
					phalcon_array_fetch(r9, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_CALL_DEFAULT);
					Z_ADDREF_P(r8);
					p3[0] = r8;
					PHALCON_CALL_FUNC_PARAMS(r7, "addslashes", 1, p3);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r7, 1, 0);
						Z_SET_REFCOUNT_P(copy, 0);
						{
							zval *orig_ptr = v2;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								ALLOC_ZVAL(v2);
								*v2 = *orig_ptr;
								zval_copy_ctor(v2);
								Z_SET_REFCOUNT_P(v2, 1);
								Z_UNSET_ISREF_P(v2);
							}
						}
						phalcon_array_update(v2, v6, copy TSRMLS_CC);
					}
				} else {
					if(!r10){
						PHALCON_ALLOC_ZVAL(r10);
					} else {
						if(Z_REFCOUNT_P(r10)>1){
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
					if(!r11){
						PHALCON_ALLOC_ZVAL(r11);
					} else {
						if(Z_REFCOUNT_P(r11)>1){
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
					phalcon_array_fetch(r11, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r11);
					p5[0] = r11;
					PHALCON_CALL_FUNC_PARAMS(r10, "addslashes", 1, p5);
					if(!r12){
						PHALCON_ALLOC_ZVAL(r12);
					} else {
						if(Z_REFCOUNT_P(r12)>1){
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
					phalcon_concat_both(r12,  "'", r10, "'" TSRMLS_CC);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r12, 1, 0);
						Z_SET_REFCOUNT_P(copy, 0);
						{
							zval *orig_ptr = v2;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								ALLOC_ZVAL(v2);
								*v2 = *orig_ptr;
								zval_copy_ctor(v2);
								Z_SET_REFCOUNT_P(v2, 1);
								Z_UNSET_ISREF_P(v2);
							}
						}
						phalcon_array_update(v2, v6, copy TSRMLS_CC);
					}
				}
			} else {
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
				phalcon_array_fetch(r14, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r14);
				p6[0] = r14;
				PHALCON_CALL_FUNC_PARAMS(r13, "addslashes", 1, p6);
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
				phalcon_concat_both(r15,  "'", r13, "'" TSRMLS_CC);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r15, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					{
						zval *orig_ptr = v2;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							ALLOC_ZVAL(v2);
							*v2 = *orig_ptr;
							zval_copy_ctor(v2);
							Z_SET_REFCOUNT_P(v2, 1);
							Z_UNSET_ISREF_P(v2);
						}
					}
					phalcon_array_update(v2, v6, copy TSRMLS_CC);
				}
			}
		}
		if(!r17){
			PHALCON_ALLOC_ZVAL(r17);
		} else {
			if(Z_REFCOUNT_P(r17)>1){
				{
					zval *orig_ptr = r17;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r17);
						*r17 = *orig_ptr;
						zval_copy_ctor(r17);
						Z_SET_REFCOUNT_P(r17, 1);
						Z_UNSET_ISREF_P(r17);
					}
				}
			} else {
				FREE_ZVAL(r17);
				PHALCON_ALLOC_ZVAL(r17);
			}
		}
		phalcon_array_fetch(r17, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(!r16){
			PHALCON_ALLOC_ZVAL(r16);
		} else {
			if(Z_REFCOUNT_P(r16)>1){
				{
					zval *orig_ptr = r16;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(r16);
						*r16 = *orig_ptr;
						zval_copy_ctor(r16);
						Z_SET_REFCOUNT_P(r16, 1);
						Z_UNSET_ISREF_P(r16);
					}
				}
			} else {
				FREE_ZVAL(r16);
				PHALCON_ALLOC_ZVAL(r16);
			}
		}
		phalcon_concat_vboth(r16, v8, " = ", r17 TSRMLS_CC);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r16, 1, 0);
			Z_SET_REFCOUNT_P(copy, 1);
			{
				zval *orig_ptr = v7;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v7);
					*v7 = *orig_ptr;
					zval_copy_ctor(v7);
					Z_SET_REFCOUNT_P(v7, 1);
					Z_UNSET_ISREF_P(v7);
				}
			}
			phalcon_array_append(v7, copy TSRMLS_CC);
		}
		{
			zval *orig_ptr = v6;
			if (Z_REFCOUNT_P(orig_ptr) > 1) {
				Z_DELREF_P(orig_ptr);
				ALLOC_ZVAL(v6);
				*v6 = *orig_ptr;
				zval_copy_ctor(v6);
				Z_SET_REFCOUNT_P(v6, 1);
				Z_UNSET_ISREF_P(v6);
			}
		}
		increment_function(v6);
	END_FOREACH(ac0, fes13, fee13, ah0, hp0);
	PHALCON_ALLOC_ZVAL(r18);
	PHALCON_ALLOC_ZVAL(p7[0]);
	ZVAL_STRING(p7[0], ", ", 1);
	p7[1] = v7;
	PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p7);
	PHALCON_CONCAT_FUNCTION(r19, v5, r18);
	if(v5){
		Z_DELREF_P(v5);
		if(!Z_REFCOUNT_P(v5)){
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(r19);
	v5 = r19;
	PHALCON_INIT_NULL(t0);
	PHALCON_NOT_EQUAL_FUNCTION(r20, v3, t0);
	if(zend_is_true(r20)){
		PHALCON_ALLOC_ZVAL(r21);
		phalcon_concat_left(r21, " WHERE ", v3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r22, v5, r21);
		if(v5){
			Z_DELREF_P(v5);
			if(!Z_REFCOUNT_P(v5)){
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r22);
		v5 = r22;
	}
	PHALCON_ALLOC_ZVAL(r23);
	Z_ADDREF_P(v5);
	p8[0] = v5;
	PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r23, 1, 0);
}

PHP_METHOD(Phalcon_Db, delete){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE){
		RETURN_NULL();
	}

	if(!v1){
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v1);
	p0[0] = v1;
	PHALCON_CALL_FUNC_PARAMS(r0, "trim", 1, p0);
	if(!phalcon_compare_strict_string(r0, "")){
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_left(r3, "DELETE FROM ", v0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, " WHERE ", v1 TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r1, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_left(r5, "DELETE FROM ", v0 TSRMLS_CC);
		Z_ADDREF_P(r5);
		p2[0] = r5;
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "query", 1, p2, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r4, 1, 0);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "BEGIN", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(zend_is_true(t0)){
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "ROLLBACK", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_PARAM_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if(zend_is_true(t0)){
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "COMMIT", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		RETURN_ZVAL(r0, 1, 0);
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_PARAM_BOOL(p1[2], 1);
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *v0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE){
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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

PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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

PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "name", strlen("name") TSRMLS_CC);
	if(eval_int){
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(Z_TYPE_P(t2)>IS_BOOL){
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "schema", strlen("schema") TSRMLS_CC);
	if(eval_int){
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "schema", sizeof("schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(Z_TYPE_P(t2)>IS_BOOL){
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		eval_int = phalcon_isset_property(t3, "name", strlen("name") TSRMLS_CC);
		if(eval_int){
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, t4, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			if(Z_TYPE_P(t5)>IS_BOOL){
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(t5);
					zval_copy_ctor(return_value);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			} else {
				{
					zend_uchar is_ref = Z_ISREF_P(return_value);
					zend_uint refcount = Z_REFCOUNT_P(return_value);
					*(return_value) = *(t5);
					Z_SET_ISREF_TO_P(return_value, is_ref);
			 		Z_SET_REFCOUNT_P(return_value, refcount);
				}
			}
			return;
		} else {
			RETURN_STRING("", 1);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "username", strlen("username") TSRMLS_CC);
	if(eval_int){
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(Z_TYPE_P(t2)>IS_BOOL){
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	eval_int = phalcon_isset_property(t0, "host", strlen("host") TSRMLS_CC);
	if(eval_int){
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(Z_TYPE_P(t2)>IS_BOOL){
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(t2);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		RETURN_STRING("", 1);
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE){
		RETURN_NULL();
	}

	if(!v0){
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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

PHP_METHOD(Phalcon_Db, factory){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *ac0 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;
	int eval_int;
	zend_class_entry *ce0;

	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE){
		RETURN_NULL();
	}

	if(!v2){
		PHALCON_INIT_BOOL(v2, 0);
	}
	
	if(phalcon_compare_strict_string(v0, "")){
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "A valid adapter name is required", 1);
		PHALCON_PARAM_LONG(p0[1], 0);
		PHALCON_PARAM_BOOL(p0[2], 1);
		PHALCON_PARAM_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	if(Z_TYPE_P(v1)!=IS_ARRAY){
		if(Z_TYPE_P(v1)!=IS_OBJECT){
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_db_exception_class_entry);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_PARAM_BOOL(p1[2], 1);
			PHALCON_PARAM_NULL(p1[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i1 TSRMLS_CC);
			Z_ADDREF_P(i1);
			return;
		}
	}
	if(Z_TYPE_P(v1)==IS_ARRAY){
		PHALCON_ALLOC_ZVAL(i2);
		object_init(i2);
		if(v3){
			Z_DELREF_P(v3);
			if(!Z_REFCOUNT_P(v3)){
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(i2);
		v3 = i2;
		FOREACH_KV(v1, ac0, fes14, fee14, ah0, hp0, v5, v4)
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v3, Z_STRVAL_P(v5), Z_STRLEN_P(v5), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes14, fee14, ah0, hp0);
	} else {
		if(v3){
			Z_DELREF_P(v3);
			if(!Z_REFCOUNT_P(v3)){
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(v1);
		v3 = v1;
	}
	eval_int = phalcon_isset_property(v3, "layer", strlen("layer") TSRMLS_CC);
	if(eval_int){
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, v3, "layer", sizeof("layer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		if(v6){
			Z_DELREF_P(v6);
			if(!Z_REFCOUNT_P(v6)){
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(t0);
		v6 = t0;
	} else {
		PHALCON_ALLOC_ZVAL(v6);
		ZVAL_STRING(v6, "native", 0);
	}
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_left(r0, "Phalcon_Db_", v0 TSRMLS_CC);
	if(v7){
		Z_DELREF_P(v7);
		if(!Z_REFCOUNT_P(v7)){
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(r0);
	v7 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	Z_ADDREF_P(v7);
	p2[0] = v7;
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p2);
	if(zend_is_true(r1)){
		ce0 = zend_fetch_class(Z_STRVAL_P(v7), Z_STRLEN_P(v7), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(i3);
		object_init_ex(i3, ce0);
		Z_ADDREF_P(v3);
		p3[0] = v3;
		Z_ADDREF_P(v2);
		p3[1] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p3, PHALCON_CALL_CHECK);
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(i3);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
			Z_SET_REFCOUNT_P(return_value, refcount);
		}
		return;
	} else {
		PHALCON_ALLOC_ZVAL(i4);
		object_init_ex(i4, phalcon_db_exception_class_entry);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Database adapter class ", v7, " was not found" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p4[0] = r2;
		PHALCON_PARAM_LONG(p4[1], 0);
		PHALCON_PARAM_BOOL(p4[2], 1);
		PHALCON_PARAM_NULL(p4[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p4, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	RETURN_NULL();
}

