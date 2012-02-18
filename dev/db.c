
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
 * Php_Db
 *
 * Php_Db and its related classes provide a simple SQL database interface for Phalcon Framework.
 * The Php_Db is the basic class you use to connect your PHP application to an RDBMS.
 * There is a different Adapter class for each brand of RDBMS
 */

PHP_METHOD(Phalcon_Db, __construct){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "__construct", 0);
	phalcon_step_over("Phalcon_Db::__construct (Assignment) File=Library/Phalcon/Db.php Line=31");
	//$descriptor
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_descriptor", strlen("_descriptor"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::__construct (Method) File=Library/Phalcon/Db.php Line=34");
}

PHP_METHOD(Phalcon_Db, setLogger){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "setLogger", 0);
	phalcon_step_over("Phalcon_Db::setLogger (Assignment) File=Library/Phalcon/Db.php Line=35");
	//$logger
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_logger", strlen("_logger"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::setLogger (Method) File=Library/Phalcon/Db.php Line=38");
}

PHP_METHOD(Phalcon_Db, log){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "log", 0);
	phalcon_step_over("Phalcon_Db::log (If) File=Library/Phalcon/Db.php Line=39");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db::log (Block) File=Library/Phalcon/Db.php Line=39");
		phalcon_step_over("Phalcon_Db::log (MethodCall) File=Library/Phalcon/Db.php Line=40");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_logger", sizeof("_logger")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(t1, "log" TSRMLS_CC);
		//$sqlStatement
		Z_ADDREF_P(v0);
		p0[0] = v0;
		phalcon_debug_param(v0 TSRMLS_CC);
		//$type
		Z_ADDREF_P(v1);
		p0[1] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "log", 2, p0, PHALCON_CALL_DEFAULT);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::log (Method) File=Library/Phalcon/Db.php Line=44");
}

PHP_METHOD(Phalcon_Db, fetchOne){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "fetchOne", 0);
	phalcon_step_over("Phalcon_Db::fetchOne (Assignment) File=Library/Phalcon/Db.php Line=45");
	//$resultQuery
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
	//$sqlQuery
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	phalcon_debug_assign("$resultQuery", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::fetchOne (If) File=Library/Phalcon/Db.php Line=46");
	//$resultQuery
	if (zend_is_true(v1)) {
		phalcon_step_over("Phalcon_Db::fetchOne (Block) File=Library/Phalcon/Db.php Line=46");
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "fetcharray" TSRMLS_CC);
		//$resultQuery
		Z_ADDREF_P(v1);
		p1[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r1, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Db::fetchOne (Block) File=Library/Phalcon/Db.php Line=48");
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		phalcon_debug_vdump("Returning > ", a0 TSRMLS_CC);
		phalcon_step_out_entry();
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
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::fetchOne (Method) File=Library/Phalcon/Db.php Line=53");
}

PHP_METHOD(Phalcon_Db, fetchAll){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "fetchAll", 0);
	phalcon_step_over("Phalcon_Db::fetchAll (Assignment) File=Library/Phalcon/Db.php Line=54");
	//$results
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(a0);
	v1 = a0;
	phalcon_debug_assign("$results", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::fetchAll (Assignment) File=Library/Phalcon/Db.php Line=55");
	//$resultQuery
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
	//$sqlQuery
	Z_ADDREF_P(v0);
	p0[0] = v0;
	phalcon_debug_param(v0 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r0);
	v2 = r0;
	phalcon_debug_assign("$resultQuery", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::fetchAll (If) File=Library/Phalcon/Db.php Line=56");
	//$resultQuery
	PHALCON_INIT_FALSE(t0);
	PHALCON_NOT_EQUAL_FUNCTION(r1, v2, t0);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db::fetchAll (Block) File=Library/Phalcon/Db.php Line=56");
		phalcon_step_over("Phalcon_Db::fetchAll (While) File=Library/Phalcon/Db.php Line=57");
		ws12:
		//$row
		PHALCON_ALLOC_ZVAL(r2);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "fetcharray" TSRMLS_CC);
		//$resultQuery
		Z_ADDREF_P(v2);
		p1[0] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "fetcharray", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r2 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r2);
		v3 = r2;
		phalcon_debug_assign("$row", r2 TSRMLS_CC);
		if (!zend_is_true(v3)) {
			goto we12;
		}
		phalcon_step_over("Phalcon_Db::fetchAll (Block) File=Library/Phalcon/Db.php Line=57");
		phalcon_step_over("Phalcon_Db::fetchAll (Assignment) File=Library/Phalcon/Db.php Line=58");
		//$row
		//$results
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
		goto ws12;
		we12:
		v3 = NULL;
	}
	//$results
	phalcon_debug_vdump("Returning > ", v1 TSRMLS_CC);
	phalcon_step_out_entry();
	{
		zend_uchar is_ref = Z_ISREF_P(return_value);
		zend_uint refcount = Z_REFCOUNT_P(return_value);
		*(return_value) = *(v1);
		zval_copy_ctor(return_value);
		Z_SET_ISREF_TO_P(return_value, is_ref);
		Z_SET_REFCOUNT_P(return_value, refcount);
	}
	return;
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::fetchAll (Method) File=Library/Phalcon/Db.php Line=64");
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	if (!v2) {
		PHALCON_INIT_NULL(v2);
	}
	if (!v3) {
		PHALCON_INIT_BOOL(v3, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "insert", 0);
	phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=65");
	//$insertSQL
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_STRING(v4, "", 0);
	phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=66");
	//$values
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=66");
		phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=67");
		PHALCON_ALLOC_ZVAL(r0);
		//$values
		p0[0] = v1;
		phalcon_debug_param(v1 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS(r0, "count", 1, p0);
		phalcon_debug_vdump("count > ", r0 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_EQUAL_FUNCTION(r1, r0, t0);
		if (zend_is_true(r1)) {
			phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=67");
			phalcon_step_over("Phalcon_Db::insert (Throw) File=Library/Phalcon/Db.php Line=68");
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_db_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
			phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
			//$table
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_both(r2,  "Unable to insert into ", v0, " without data" TSRMLS_CC);
			Z_ADDREF_P(r2);
			p1[0] = r2;
			phalcon_debug_param(r2 TSRMLS_CC);
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_PARAM_BOOL(p1[2], 1);
			//$this
			Z_ADDREF_P(this_ptr);
			p1[3] = this_ptr;
			phalcon_debug_param(this_ptr TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		} else {
			phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=69");
			phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=70");
			//$automaticQuotes
			if (zend_is_true(v3)) {
				phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=70");
				phalcon_step_over("Phalcon_Db::insert (Foreach) File=Library/Phalcon/Db.php Line=71");
				//$values
				//$value
				//$key
				FOREACH_KV(v1, ac0, fes13, fee13, ah0, hp0, v6, v5)
					phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=71");
					phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=72");
					//$key
					//$values
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
					phalcon_array_fetch(r3, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (Z_TYPE_P(r3) == IS_OBJECT) {
						phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=72");
						phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=73");
						//$key
						//$values
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
						phalcon_array_fetch(r4, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (!r5) {
							PHALCON_ALLOC_ZVAL(r5);
						} else {
							if (Z_REFCOUNT_P(r5) > 1){ 
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
						phalcon_instance_of(r5, r4, phalcon_db_rawvalue_class_entry TSRMLS_CC);
						if (zend_is_true(r5)) {
							phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=73");
							phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=74");
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
							//$key
							//$values
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
							phalcon_array_fetch(r8, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
							phalcon_debug_method_call(r8, "getvalue" TSRMLS_CC);
							PHALCON_CALL_METHOD(r7, r8, "getvalue", PHALCON_CALL_DEFAULT);
							phalcon_debug_vdump("MethodReturn > ", r7 TSRMLS_CC);
							phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
							Z_ADDREF_P(r7);
							p2[0] = r7;
							phalcon_debug_param(r7 TSRMLS_CC);
							PHALCON_CALL_FUNC_PARAMS(r6, "addslashes", 1, p2);
							phalcon_debug_vdump("addslashes > ", r6 TSRMLS_CC);
							//$values
							//$key
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
							phalcon_step_over("Phalcon_Db::insert (Continue) File=Library/Phalcon/Db.php Line=75");
							goto fes13;
						} else {
							phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=76");
							phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=77");
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
							//$key
							//$values
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
							phalcon_array_fetch(r10, v1, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(r10);
							p4[0] = r10;
							phalcon_debug_param(r10 TSRMLS_CC);
							PHALCON_CALL_FUNC_PARAMS(r9, "addslashes", 1, p4);
							phalcon_debug_vdump("addslashes > ", r9 TSRMLS_CC);
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
							phalcon_concat_both(r11,  "'", r9, "'" TSRMLS_CC);
							//$values
							//$key
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
						phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=79");
						phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=80");
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
						//$key
						//$values
						if (!r13) {
							PHALCON_ALLOC_ZVAL(r13);
						} else {
							if (Z_REFCOUNT_P(r13) > 1) {
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
						phalcon_debug_param(r13 TSRMLS_CC);
						PHALCON_CALL_FUNC_PARAMS(r12, "addslashes", 1, p5);
						phalcon_debug_vdump("addslashes > ", r12 TSRMLS_CC);
						if (!r14) {
							PHALCON_ALLOC_ZVAL(r14);
						} else {
							if (Z_REFCOUNT_P(r14) > 1) {
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
						//$values
						//$key
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
				END_FOREACH(ac0, fes13, fee13, ah0, hp0);
			}
		}
		phalcon_step_over("Phalcon_Db::insert (If) File=Library/Phalcon/Db.php Line=85");
		//$fields
		if (Z_TYPE_P(v2) == IS_ARRAY) { 
			phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=85");
			phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=86");
			//$insertSQL
			//$table
			PHALCON_ALLOC_ZVAL(r17);
			phalcon_concat_left(r17, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r18);
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], ", ", 1);
			//$fields
			p6[1] = v2;
			phalcon_debug_param(v2 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p6);
			phalcon_debug_vdump("join > ", r18 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r16);
			phalcon_concat_vboth(r16, r17, " (", r18 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r19);
			PHALCON_ALLOC_ZVAL(p7[0]);
			ZVAL_STRING(p7[0], ", ", 1);
			//$values
			p7[1] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r19, "join", 2, p7);
			phalcon_debug_vdump("join > ", r19 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_concat_vboth(r15, r16, ") VALUES (", r19 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r20);
			phalcon_concat_right(r20, r15, ")" TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r20);
			v4 = r20;
			phalcon_debug_assign("$insertSQL", r20 TSRMLS_CC);
		} else {
			phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=87");
			phalcon_step_over("Phalcon_Db::insert (Assignment) File=Library/Phalcon/Db.php Line=88");
			//$insertSQL
			//$table
			PHALCON_ALLOC_ZVAL(r22);
			phalcon_concat_left(r22, "INSERT INTO ", v0 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r23);
			PHALCON_ALLOC_ZVAL(p8[0]);
			ZVAL_STRING(p8[0], ", ", 1);
			//$values
			p8[1] = v1;
			phalcon_debug_param(v1 TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS(r23, "join", 2, p8);
			phalcon_debug_vdump("join > ", r23 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r21);
			phalcon_concat_vboth(r21, r22, " VALUES (", r23 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r24);
			phalcon_concat_right(r24, r21, ")" TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r24);
			v4 = r24;
			phalcon_debug_assign("$insertSQL", r24 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(r25);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
		//$insertSQL
		Z_ADDREF_P(v4);
		p9[0] = v4;
		phalcon_debug_param(v4 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "query", 1, p9, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r25 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r25 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r25, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Db::insert (Block) File=Library/Phalcon/Db.php Line=91");
		phalcon_step_over("Phalcon_Db::insert (Throw) File=Library/Phalcon/Db.php Line=92");
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p10[0]);
		ZVAL_STRING(p10[0], "The second parameter for insert isn't an Array", 1);
		PHALCON_PARAM_LONG(p10[1], 0);
		PHALCON_PARAM_BOOL(p10[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p10[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p10, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::insert (Method) File=Library/Phalcon/Db.php Line=96");
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		RETURN_NULL();
	}

	if (!v3) {
		PHALCON_INIT_NULL(v3);
	}
	if (!v4) {
		PHALCON_INIT_BOOL(v4, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v3 > ", v3 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v4 > ", v4 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "update", 0);
	phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=97");
	//$updateSql
	//$table
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_both(r0,  "UPDATE ", v0, " SET " TSRMLS_CC);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(r0);
	v5 = r0;
	phalcon_debug_assign("$updateSql", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::update (If) File=Library/Phalcon/Db.php Line=98");
	PHALCON_ALLOC_ZVAL(r1);
	//$fields
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "count", 1, p0);
	phalcon_debug_vdump("count > ", r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r2);
	//$values
	p1[0] = v2;
	phalcon_debug_param(v2 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p1);
	phalcon_debug_vdump("count > ", r2 TSRMLS_CC);
	PHALCON_NOT_EQUAL_FUNCTION(r3, r1, r2);
	if (zend_is_true(r3)) {
		phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=98");
		phalcon_step_over("Phalcon_Db::update (Throw) File=Library/Phalcon/Db.php Line=99");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "The number of values to update is not the same as fields", 1);
		PHALCON_PARAM_LONG(p2[1], 0);
		PHALCON_PARAM_BOOL(p2[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p2[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p2, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=101");
	//$i
	PHALCON_ALLOC_ZVAL(v6);
	ZVAL_LONG(v6, 0);
	phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=102");
	//$updateValues
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	if (v7) {
		Z_DELREF_P(v7);
		if (!Z_REFCOUNT_P(v7)) {
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(a0);
	v7 = a0;
	phalcon_debug_assign("$updateValues", a0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::update (Foreach) File=Library/Phalcon/Db.php Line=103");
	//$fields
	//$field
	FOREACH_V(v1, ac0, fes14, fee14, ah0, hp0, v8)
		phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=103");
		phalcon_step_over("Phalcon_Db::update (If) File=Library/Phalcon/Db.php Line=104");
		//$automaticQuotes
		if (zend_is_true(v4)) {
			phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=104");
			phalcon_step_over("Phalcon_Db::update (If) File=Library/Phalcon/Db.php Line=105");
			//$i
			//$values
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
			phalcon_array_fetch(r4, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (Z_TYPE_P(r4) == IS_OBJECT) {
				phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=105");
				phalcon_step_over("Phalcon_Db::update (If) File=Library/Phalcon/Db.php Line=106");
				//$i
				//$values
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
				phalcon_array_fetch(r5, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
				if (!r6) {
					PHALCON_ALLOC_ZVAL(r6);
				} else {
					if (Z_REFCOUNT_P(r6) > 1){ 
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
				phalcon_instance_of(r6, r5, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r6)) {
					phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=106");
					phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=107");
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
					//$i
					//$values
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
					phalcon_array_fetch(r9, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
					phalcon_debug_method_call(r9, "getvalue" TSRMLS_CC);
					PHALCON_CALL_METHOD(r8, r9, "getvalue", PHALCON_CALL_DEFAULT);
					phalcon_debug_vdump("MethodReturn > ", r8 TSRMLS_CC);
					phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
					Z_ADDREF_P(r8);
					p3[0] = r8;
					phalcon_debug_param(r8 TSRMLS_CC);
					PHALCON_CALL_FUNC_PARAMS(r7, "addslashes", 1, p3);
					phalcon_debug_vdump("addslashes > ", r7 TSRMLS_CC);
					//$values
					//$i
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
					phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=108");
					phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=109");
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
					//$i
					//$values
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
					phalcon_array_fetch(r11, v2, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r11);
					p5[0] = r11;
					phalcon_debug_param(r11 TSRMLS_CC);
					PHALCON_CALL_FUNC_PARAMS(r10, "addslashes", 1, p5);
					phalcon_debug_vdump("addslashes > ", r10 TSRMLS_CC);
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
					phalcon_concat_both(r12,  "'", r10, "'" TSRMLS_CC);
					//$values
					//$i
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
				phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=111");
				phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=112");
				if (!r13) {
					PHALCON_ALLOC_ZVAL(r13);
				} else {
					if (Z_REFCOUNT_P(r13) > 1) {
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
				//$i
				//$values
				if (!r14) {
					PHALCON_ALLOC_ZVAL(r14);
				} else {
					if (Z_REFCOUNT_P(r14) > 1) {
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
				phalcon_debug_param(r14 TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS(r13, "addslashes", 1, p6);
				phalcon_debug_vdump("addslashes > ", r13 TSRMLS_CC);
				if (!r15) {
					PHALCON_ALLOC_ZVAL(r15);
				} else {
					if (Z_REFCOUNT_P(r15) > 1) {
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
				//$values
				//$i
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
		phalcon_step_over("Phalcon_Db::update (Assignment) File=Library/Phalcon/Db.php Line=115");
		//$field
		//$i
		//$values
		if (!r17) {
			PHALCON_ALLOC_ZVAL(r17);
		} else {
			if (Z_REFCOUNT_P(r17) > 1) {
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
		if (!r16) {
			PHALCON_ALLOC_ZVAL(r16);
		} else {
			if (Z_REFCOUNT_P(r16) > 1) {
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
		//$updateValues
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
		phalcon_step_over("Phalcon_Db::update (PostIncDecOp) File=Library/Phalcon/Db.php Line=116");
		//$i
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
		phalcon_debug_vdump("PostIncrementing $i", v6);
	END_FOREACH(ac0, fes14, fee14, ah0, hp0);
	phalcon_step_over("Phalcon_Db::update (AssignOp) File=Library/Phalcon/Db.php Line=118");
	//$updateSql
	PHALCON_ALLOC_ZVAL(r18);
	PHALCON_ALLOC_ZVAL(p7[0]);
	ZVAL_STRING(p7[0], ", ", 1);
	//$updateValues
	p7[1] = v7;
	phalcon_debug_param(v7 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r18, "join", 2, p7);
	phalcon_debug_vdump("join > ", r18 TSRMLS_CC);
	PHALCON_CONCAT_FUNCTION(r19, v5, r18);
	//$updateSql
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(r19);
	v5 = r19;
	phalcon_debug_assign("$updateSql", r19 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::update (If) File=Library/Phalcon/Db.php Line=119");
	//$whereCondition
	PHALCON_INIT_NULL(t0);
	PHALCON_NOT_EQUAL_FUNCTION(r20, v3, t0);
	if (zend_is_true(r20)) {
		phalcon_step_over("Phalcon_Db::update (Block) File=Library/Phalcon/Db.php Line=119");
		phalcon_step_over("Phalcon_Db::update (AssignOp) File=Library/Phalcon/Db.php Line=120");
		//$updateSql
		//$whereCondition
		PHALCON_ALLOC_ZVAL(r21);
		phalcon_concat_left(r21, " WHERE ", v3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r22, v5, r21);
		//$updateSql
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r22);
		v5 = r22;
		phalcon_debug_assign("$updateSql", r22 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r23);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
	//$updateSql
	Z_ADDREF_P(v5);
	p8[0] = v5;
	phalcon_debug_param(v5 TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "query", 1, p8, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r23 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r23 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r23, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::update (Method) File=Library/Phalcon/Db.php Line=125");
}

PHP_METHOD(Phalcon_Db, delete){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "delete", 0);
	phalcon_step_over("Phalcon_Db::delete (If) File=Library/Phalcon/Db.php Line=126");
	PHALCON_ALLOC_ZVAL(r0);
	//$whereCondition
	Z_ADDREF_P(v1);
	p0[0] = v1;
	phalcon_debug_param(v1 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r0, "trim", 1, p0);
	phalcon_debug_vdump("trim > ", r0 TSRMLS_CC);
	if (!phalcon_compare_strict_string(r0, "")) {
		phalcon_step_over("Phalcon_Db::delete (Block) File=Library/Phalcon/Db.php Line=126");
		PHALCON_ALLOC_ZVAL(r1);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
		//$table
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_left(r3, "DELETE FROM ", v0 TSRMLS_CC);
		//$whereCondition
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, r3, " WHERE ", v1 TSRMLS_CC);
		Z_ADDREF_P(r2);
		p1[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "query", 1, p1, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r1 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r1 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r1, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Db::delete (Block) File=Library/Phalcon/Db.php Line=128");
		PHALCON_ALLOC_ZVAL(r4);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
		//$table
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_left(r5, "DELETE FROM ", v0 TSRMLS_CC);
		Z_ADDREF_P(r5);
		p2[0] = r5;
		phalcon_debug_param(r5 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "query", 1, p2, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r4 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r4 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r4, 1, 0);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::delete (Method) File=Library/Phalcon/Db.php Line=133");
}

PHP_METHOD(Phalcon_Db, begin){

	zval *r0 = NULL;
	zval *p0[] = { NULL };

	phalcon_step_into_entry("Phalcon_Db", "begin", 0);
	phalcon_step_over("Phalcon_Db::begin (Assignment) File=Library/Phalcon/Db.php Line=134");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::begin (Assignment) File=Library/Phalcon/Db.php Line=135");
	//$this
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	//$this
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(p0[0]);
	ZVAL_STRING(p0[0], "BEGIN", 1);
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
	phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
	phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
	phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
	phalcon_step_out_entry();
	RETURN_ZVAL(r0, 1, 0);
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::begin (Method) File=Library/Phalcon/Db.php Line=139");
}

PHP_METHOD(Phalcon_Db, rollback){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	phalcon_step_into_entry("Phalcon_Db", "rollback", 0);
	phalcon_step_over("Phalcon_Db::rollback (If) File=Library/Phalcon/Db.php Line=140");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db::rollback (Block) File=Library/Phalcon/Db.php Line=140");
		phalcon_step_over("Phalcon_Db::rollback (Assignment) File=Library/Phalcon/Db.php Line=141");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db::rollback (Assignment) File=Library/Phalcon/Db.php Line=142");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "ROLLBACK", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r0, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Db::rollback (Block) File=Library/Phalcon/Db.php Line=144");
		phalcon_step_over("Phalcon_Db::rollback (Throw) File=Library/Phalcon/Db.php Line=145");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_PARAM_BOOL(p1[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::rollback (Method) File=Library/Phalcon/Db.php Line=149");
}

PHP_METHOD(Phalcon_Db, commit){

	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL, NULL, NULL };

	phalcon_step_into_entry("Phalcon_Db", "commit", 0);
	phalcon_step_over("Phalcon_Db::commit (If) File=Library/Phalcon/Db.php Line=150");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		phalcon_step_over("Phalcon_Db::commit (Block) File=Library/Phalcon/Db.php Line=150");
		phalcon_step_over("Phalcon_Db::commit (Assignment) File=Library/Phalcon/Db.php Line=151");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_underTransaction", strlen("_underTransaction"), 0 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db::commit (Assignment) File=Library/Phalcon/Db.php Line=152");
		//$this
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_autoCommit", strlen("_autoCommit"), 1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		//$this
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(this_ptr, "query" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "COMMIT", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "query", 1, p0, PHALCON_CALL_DEFAULT);
		phalcon_debug_vdump("MethodReturn > ", r0 TSRMLS_CC);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", r0 TSRMLS_CC);
		phalcon_step_out_entry();
		RETURN_ZVAL(r0, 1, 0);
	} else {
		phalcon_step_over("Phalcon_Db::commit (Block) File=Library/Phalcon/Db.php Line=154");
		phalcon_step_over("Phalcon_Db::commit (Throw) File=Library/Phalcon/Db.php Line=155");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not an active transaction on relational manager", 1);
		PHALCON_PARAM_LONG(p1[1], 0);
		PHALCON_PARAM_BOOL(p1[2], 1);
		//$this
		Z_ADDREF_P(this_ptr);
		p1[3] = this_ptr;
		phalcon_debug_param(this_ptr TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p1, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::commit (Method) File=Library/Phalcon/Db.php Line=159");
}

PHP_METHOD(Phalcon_Db, setUnderTransaction){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "setUnderTransaction", 0);
	phalcon_step_over("Phalcon_Db::setUnderTransaction (Assignment) File=Library/Phalcon/Db.php Line=160");
	//$underTransaction
	//$this
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_underTransaction", strlen("_underTransaction"), copy TSRMLS_CC);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::setUnderTransaction (Method) File=Library/Phalcon/Db.php Line=163");
}

PHP_METHOD(Phalcon_Db, isUnderTransaction){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Db", "isUnderTransaction", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_underTransaction", sizeof("_underTransaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::isUnderTransaction (Method) File=Library/Phalcon/Db.php Line=167");
}

PHP_METHOD(Phalcon_Db, getHaveAutoCommit){

	zval *t0 = NULL;

	phalcon_step_into_entry("Phalcon_Db", "getHaveAutoCommit", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_autoCommit", sizeof("_autoCommit")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::getHaveAutoCommit (Method) File=Library/Phalcon/Db.php Line=171");
}

PHP_METHOD(Phalcon_Db, getDatabaseName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Db", "getDatabaseName", 0);
	phalcon_step_over("Phalcon_Db::getDatabaseName (If) File=Library/Phalcon/Db.php Line=172");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	eval_int = phalcon_isset_property(t0, "name", strlen("name") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db::getDatabaseName (Block) File=Library/Phalcon/Db.php Line=172");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(t2) > IS_BOOL) {
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
		phalcon_step_over("Phalcon_Db::getDatabaseName (Block) File=Library/Phalcon/Db.php Line=174");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::getDatabaseName (Method) File=Library/Phalcon/Db.php Line=179");
}

PHP_METHOD(Phalcon_Db, getDefaultSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Db", "getDefaultSchema", 0);
	phalcon_step_over("Phalcon_Db::getDefaultSchema (If) File=Library/Phalcon/Db.php Line=180");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	eval_int = phalcon_isset_property(t0, "schema", strlen("schema") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db::getDefaultSchema (Block) File=Library/Phalcon/Db.php Line=180");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "schema", sizeof("schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(t2) > IS_BOOL) {
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
		phalcon_step_over("Phalcon_Db::getDefaultSchema (Block) File=Library/Phalcon/Db.php Line=182");
		phalcon_step_over("Phalcon_Db::getDefaultSchema (If) File=Library/Phalcon/Db.php Line=183");
		//$this
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		eval_int = phalcon_isset_property(t3, "name", strlen("name") TSRMLS_CC);
		if (eval_int) {
			phalcon_step_over("Phalcon_Db::getDefaultSchema (Block) File=Library/Phalcon/Db.php Line=183");
			//$this
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t4);
			PHALCON_ALLOC_ZVAL(t5);
			phalcon_read_property(t5, t4, "name", sizeof("name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t5);
			phalcon_debug_vdump("Returning > ", t5 TSRMLS_CC);
			phalcon_step_out_entry();
			if (Z_TYPE_P(t5) > IS_BOOL) {
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
			phalcon_step_over("Phalcon_Db::getDefaultSchema (Block) File=Library/Phalcon/Db.php Line=185");
			phalcon_step_out_entry();
			RETURN_STRING("", 1);
		}
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::getDefaultSchema (Method) File=Library/Phalcon/Db.php Line=191");
}

PHP_METHOD(Phalcon_Db, getUsername){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Db", "getUsername", 0);
	phalcon_step_over("Phalcon_Db::getUsername (If) File=Library/Phalcon/Db.php Line=192");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	eval_int = phalcon_isset_property(t0, "username", strlen("username") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db::getUsername (Block) File=Library/Phalcon/Db.php Line=192");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "username", sizeof("username")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(t2) > IS_BOOL) {
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
		phalcon_step_over("Phalcon_Db::getUsername (Block) File=Library/Phalcon/Db.php Line=194");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::getUsername (Method) File=Library/Phalcon/Db.php Line=199");
}

PHP_METHOD(Phalcon_Db, getHostName){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	phalcon_step_into_entry("Phalcon_Db", "getHostName", 0);
	phalcon_step_over("Phalcon_Db::getHostName (If) File=Library/Phalcon/Db.php Line=200");
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	eval_int = phalcon_isset_property(t0, "host", strlen("host") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db::getHostName (Block) File=Library/Phalcon/Db.php Line=200");
		//$this
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_descriptor", sizeof("_descriptor")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, t1, "host", sizeof("host")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		phalcon_debug_vdump("Returning > ", t2 TSRMLS_CC);
		phalcon_step_out_entry();
		if (Z_TYPE_P(t2) > IS_BOOL) {
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
		phalcon_step_over("Phalcon_Db::getHostName (Block) File=Library/Phalcon/Db.php Line=202");
		phalcon_step_out_entry();
		RETURN_STRING("", 1);
	}
	phalcon_step_out_entry();
	RETURN_NULL();
	phalcon_step_over("Phalcon_Db::getHostName (Method) File=Library/Phalcon/Db.php Line=207");
}

PHP_METHOD(Phalcon_Db, getConnectionId){

	zval *v0 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_BOOL(v0, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "getConnectionId", 0);
	//$this
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_idConnection", sizeof("_idConnection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	phalcon_debug_vdump("Returning > ", t0 TSRMLS_CC);
	phalcon_step_out_entry();
	if (Z_TYPE_P(t0) > IS_BOOL) {
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
	phalcon_step_out_entry();
	phalcon_step_over("Phalcon_Db::getConnectionId (Method) File=Library/Phalcon/Db.php Line=214");
}

/**
 * Instantiates Php_Db adapter using given parameters
 */
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

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	if (!v2) {
		PHALCON_INIT_BOOL(v2, 0);
	}
	
	phalcon_debug_vdump("Receiving Param &v0 > ", v0 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v1 > ", v1 TSRMLS_CC);
	phalcon_debug_vdump("Receiving Param &v2 > ", v2 TSRMLS_CC);
	phalcon_step_into_entry("Phalcon_Db", "factory", 0);
	phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=216");
	//$adapterName
	if (phalcon_compare_strict_string(v0, "")) {
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=216");
		phalcon_step_over("Phalcon_Db::factory (Throw) File=Library/Phalcon/Db.php Line=217");
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i0, "__construct" TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(p0[0]);
		ZVAL_STRING(p0[0], "A valid adapter name is required", 1);
		PHALCON_PARAM_LONG(p0[1], 0);
		PHALCON_PARAM_BOOL(p0[2], 1);
		PHALCON_PARAM_NULL(p0[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 4, p0, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=220");
	//$options
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=220");
		phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=221");
		//$options
		if (Z_TYPE_P(v1) != IS_OBJECT) {
			phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=221");
			phalcon_step_over("Phalcon_Db::factory (Throw) File=Library/Phalcon/Db.php Line=222");
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_db_exception_class_entry);
			phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
			phalcon_debug_method_call(i1, "__construct" TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "The parameter 'options' must be an Array or Object", 1);
			PHALCON_PARAM_LONG(p1[1], 0);
			PHALCON_PARAM_BOOL(p1[2], 1);
			PHALCON_PARAM_NULL(p1[3]);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 4, p1, PHALCON_CALL_CHECK);
			phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
			zend_throw_exception_object(i1 TSRMLS_CC);
			Z_ADDREF_P(i1);
			return;
		}
	}
	phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=226");
	//$options
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=226");
		phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=227");
		//$descriptor
		PHALCON_ALLOC_ZVAL(i2);
		object_init(i2);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(i2);
		v3 = i2;
		phalcon_debug_assign("$descriptor", i2 TSRMLS_CC);
		phalcon_step_over("Phalcon_Db::factory (Foreach) File=Library/Phalcon/Db.php Line=228");
		//$options
		//$value
		//$key
		FOREACH_KV(v1, ac0, fes15, fee15, ah0, hp0, v5, v4)
			phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=228");
			phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=229");
			//$key
			//$value
			//$descriptor
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v3, Z_STRVAL_P(v5), Z_STRLEN_P(v5), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes15, fee15, ah0, hp0);
	} else {
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=231");
		phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=232");
		//$descriptor
		//$options
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(v1);
		v3 = v1;
		phalcon_debug_assign("$descriptor", v1 TSRMLS_CC);
	}
	phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=235");
	//$descriptor
	eval_int = phalcon_isset_property(v3, "layer", strlen("layer") TSRMLS_CC);
	if (eval_int) {
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=235");
		phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=236");
		//$layer
		//$descriptor
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_read_property(t0, v3, "layer", sizeof("layer")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t0);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(t0);
		v6 = t0;
		phalcon_debug_assign("$layer", t0 TSRMLS_CC);
	} else {
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=237");
		phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=238");
		//$layer
		PHALCON_ALLOC_ZVAL(v6);
		ZVAL_STRING(v6, "native", 0);
	}
	phalcon_step_over("Phalcon_Db::factory (Assignment) File=Library/Phalcon/Db.php Line=241");
	//$className
	//$adapterName
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_concat_left(r0, "Phalcon_Db_", v0 TSRMLS_CC);
	if (v7) {
		Z_DELREF_P(v7);
		if (!Z_REFCOUNT_P(v7)) {
			FREE_ZVAL(v7);
		}
	}
	Z_ADDREF_P(r0);
	v7 = r0;
	phalcon_debug_assign("$className", r0 TSRMLS_CC);
	phalcon_step_over("Phalcon_Db::factory (If) File=Library/Phalcon/Db.php Line=242");
	PHALCON_ALLOC_ZVAL(r1);
	//$className
	Z_ADDREF_P(v7);
	p2[0] = v7;
	phalcon_debug_param(v7 TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS(r1, "class_exists", 1, p2);
	phalcon_debug_vdump("class_exists > ", r1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=242");
		//$className
		ce0 = zend_fetch_class(Z_STRVAL_P(v7), Z_STRLEN_P(v7), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(i3);
		object_init_ex(i3, ce0);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i3, "__construct" TSRMLS_CC);
		//$descriptor
		Z_ADDREF_P(v3);
		p3[0] = v3;
		phalcon_debug_param(v3 TSRMLS_CC);
		//$persistent
		Z_ADDREF_P(v2);
		p3[1] = v2;
		phalcon_debug_param(v2 TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 2, p3, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_vdump("Returning > ", i3 TSRMLS_CC);
		phalcon_step_out_entry();
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
		phalcon_step_over("Phalcon_Db::factory (Block) File=Library/Phalcon/Db.php Line=244");
		phalcon_step_over("Phalcon_Db::factory (Throw) File=Library/Phalcon/Db.php Line=245");
		PHALCON_ALLOC_ZVAL(i4);
		object_init_ex(i4, phalcon_db_exception_class_entry);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		phalcon_debug_method_call(i4, "__construct" TSRMLS_CC);
		//$className
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_both(r2,  "Database adapter class ", v7, " was not found" TSRMLS_CC);
		Z_ADDREF_P(r2);
		p4[0] = r2;
		phalcon_debug_param(r2 TSRMLS_CC);
		PHALCON_PARAM_LONG(p4[1], 0);
		PHALCON_PARAM_BOOL(p4[2], 1);
		PHALCON_PARAM_NULL(p4[3]);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p4, PHALCON_CALL_CHECK);
		phalcon_assert_class(this_ptr, "Phalcon_Db" TSRMLS_CC);
		zend_throw_exception_object(i4 TSRMLS_CC);
		Z_ADDREF_P(i4);
		return;
	}
	phalcon_step_out_entry();
	RETURN_NULL();
}

