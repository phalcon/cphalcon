
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
 * Php_Model_Base
 *
 * <p>Php_Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object- relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
 *
 * <p>Php_Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interact with databases while is also easy to use.</p>
 *
 * 
 *
 */

/**
 * Php_Model_Base constructor
 *
 * @param Php_Model_Manager $manager
 *
 */
PHP_METHOD(Phalcon_Model_Base, __construct){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
		PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
		}
	} else {
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, v0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "initialize", 1);
	if (phalcon_method_exists(this_ptr, t0 TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
	}
	RETURN_NULL();
}

/**
 * Internal method for make a connection. Automatically dumps mapped table meta-data
 *
 */
PHP_METHOD(Phalcon_Model_Base, _connect){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
		}
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_CALL_DEFAULT);
	RETURN_NULL();
}

/**
 * Internal method for get table mapped attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Internal method for get attributes which are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Internal method for get attributes which are not part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnonprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Internal method for get attributes which are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnotnullattributes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Internal method for get numerical-typed attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypesnumeric", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Internal method for get data-types attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Dumps mapped table meta-data
 *
 * @return Php_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, dump){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *ac0 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	FOREACH_V(v0, ac0, fes65, fee65, ah0, hp0, v1)
		eval_int = phalcon_isset_property_zval(this_ptr, v1 TSRMLS_CC);
		if (!eval_int) {
			if (!t2) {
				PHALCON_ALLOC_ZVAL(t2);
			} else {
				if (Z_REFCOUNT_P(t2) > 1) {
					SEPARATE_ZVAL(&t2);
				} else {
					if (Z_TYPE_P(t2) != IS_STRING) {
						FREE_ZVAL(t2);
						PHALCON_ALLOC_ZVAL(t2);
					}
				}
			}
			ZVAL_STRING(t2, "", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1), copy TSRMLS_CC);
			}
		}
	END_FOREACH(ac0, fes65, fee65, ah0, hp0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	if (Z_TYPE_P(this_ptr) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL }, *p9[] = { NULL }, *p10[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(v1);
	ZVAL_STRING(v1, "SELECT ", 0);
	eval_int = phalcon_array_isset_string(v0, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_array_fetch_string(r0, v0, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r1, v1, r0);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r1);
		v1 = r1;
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], ", ", 1);
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_METHOD(r3, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		p1[1] = r3;
		PHALCON_CALL_FUNC_PARAMS(r2, "join", 2, p1);
		PHALCON_CONCAT_FUNCTION(r4, v1, r2);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r4);
		v1 = r4;
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_concat_left(r6, " FROM ", t1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_vboth(r5, r6, ".", t2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r7, v1, r5);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r7);
		v1 = r7;
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_concat_left(r8, " FROM ", t3 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v1, r8);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r9);
		v1 = r9;
	}
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_STRING(v2, "n", 0);
	eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_array_fetch_string(r10, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r11);
		phalcon_concat_both(r11,  " WHERE ", r10, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r12, v1, r11);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r12);
		v1 = r12;
	} else {
		PHALCON_ALLOC_ZVAL(r13);
		PHALCON_CALL_METHOD(r13, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r13);
		v3 = r13;
		eval_int = phalcon_array_isset_long(v3, 0);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL(t4);
			phalcon_read_property(t4, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t4);
			if (zend_is_true(t4)) {
				PHALCON_ALLOC_ZVAL(t5);
				ZVAL_STRING(t5, "id", 1);
				{
					zval *orig_ptr = v3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v3);
						*v3 = *orig_ptr;
						zval_copy_ctor(v3);
						Z_SET_REFCOUNT_P(v3, 1);
						Z_UNSET_ISREF_P(v3);
					}
				}
				phalcon_array_update_long(v3, 0, t5 TSRMLS_CC);
			}
		}
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r14);
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_array_fetch_long(r15, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r15);
			p4[0] = r15;
			PHALCON_CALL_FUNC_PARAMS(r14, "is_numeric", 1, p4);
			if (zend_is_true(r14)) {
				eval_int = phalcon_array_isset_long(v3, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL(r17);
					phalcon_array_fetch_long(r17, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r18);
					PHALCON_ALLOC_ZVAL(t6);
					phalcon_read_property(t6, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t6);
					PHALCON_ALLOC_ZVAL(r19);
					phalcon_array_fetch_long(r19, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r19);
					p5[0] = r19;
					PHALCON_CALL_METHOD_PARAMS(r18, t6, "addquotes", 1, p5, PHALCON_CALL_DEFAULT);
					PHALCON_ALLOC_ZVAL(r16);
					phalcon_concat_vboth(r16, r17, " = ", r18 TSRMLS_CC);
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
					phalcon_array_update_string(v0, "conditions", strlen("conditions"), r16 TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(v2);
					ZVAL_STRING(v2, "1", 0);
				} else {
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_ALLOC_ZVAL(p6[0]);
					ZVAL_STRING(p6[0], "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p6, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_array_fetch_long(r20, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(t7);
				ZVAL_STRING(t7, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r21, r20, t7);
				if (zend_is_true(r21)) {
					eval_int = phalcon_array_isset_long(v3, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL(r22);
						phalcon_array_fetch_long(r22, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r23);
						phalcon_concat_right(r23, r22, " = ''" TSRMLS_CC);
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
						phalcon_array_update_string(v0, "conditions", strlen("conditions"), r23 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL(i1);
						object_init_ex(i1, phalcon_model_exception_class_entry);
						PHALCON_ALLOC_ZVAL(p7[0]);
						ZVAL_STRING(p7[0], "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p7, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL(r24);
					phalcon_array_fetch_long(r24, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
					phalcon_array_update_string(v0, "conditions", strlen("conditions"), r24 TSRMLS_CC);
				}
				PHALCON_ALLOC_ZVAL(v2);
				ZVAL_STRING(v2, "n", 0);
			}
		}
		eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r25);
			phalcon_array_fetch_string(r25, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r26);
			phalcon_concat_left(r26, " WHERE ", r25 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r27, v1, r26);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r27);
			v1 = r27;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_array_fetch_string(r28, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r28)) {
			PHALCON_ALLOC_ZVAL(r29);
			phalcon_array_fetch_string(r29, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r30);
			phalcon_concat_left(r30, " GROUP BY ", r29 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r31, v1, r30);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r31);
			v1 = r31;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r32);
		phalcon_array_fetch_string(r32, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r32)) {
			PHALCON_ALLOC_ZVAL(r33);
			phalcon_array_fetch_string(r33, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r34);
			phalcon_concat_left(r34, " ORDER BY ", r33 TSRMLS_CC);
			PHALCON_CONCAT_FUNCTION(r35, v1, r34);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r35);
			v1 = r35;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r36);
		phalcon_array_fetch_string(r36, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r36)) {
			PHALCON_ALLOC_ZVAL(r37);
			PHALCON_ALLOC_ZVAL(t8);
			phalcon_read_property(t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t8);
			Z_ADDREF_P(v1);
			p8[0] = v1;
			PHALCON_ALLOC_ZVAL(r38);
			phalcon_array_fetch_string(r38, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r38);
			p8[1] = r38;
			PHALCON_CALL_METHOD_PARAMS(r37, t8, "limit", 2, p8, PHALCON_CALL_DEFAULT);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r37);
			v1 = r37;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r39);
		phalcon_array_fetch_string(r39, v0, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r39)) {
			PHALCON_ALLOC_ZVAL(r40);
			PHALCON_ALLOC_ZVAL(t9);
			phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t9);
			Z_ADDREF_P(v1);
			p9[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r40, t9, "forupdate", 1, p9, PHALCON_CALL_DEFAULT);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r40);
			v1 = r40;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r41);
		phalcon_array_fetch_string(r41, v0, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r41)) {
			PHALCON_ALLOC_ZVAL(r42);
			PHALCON_ALLOC_ZVAL(t10);
			phalcon_read_property(t10, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t10);
			Z_ADDREF_P(v1);
			p10[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r42, t10, "sharedlock", 1, p10, PHALCON_CALL_DEFAULT);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(r42);
			v1 = r42;
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v2, 1, 0);
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
		add_assoc_zval(a0, "return", copy);
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
		add_assoc_zval(a0, "sql", copy);
	}
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

PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL, NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	if (!v1) {
		PHALCON_ALLOC_ZVAL(v1);
		ZVAL_STRING(v1, "", 0);
	}
	
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(v1, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_string(r0, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch_string(r1, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r2);
				phalcon_concat_both(r2,  " WHERE ", r1, " " TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r3, v0, r2);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r3);
				v0 = r3;
			}
		} else {
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(r4);
			v2 = r4;
			eval_int = phalcon_array_isset_long(v1, 0);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(r5);
				PHALCON_ALLOC_ZVAL(r6);
				phalcon_array_fetch_long(r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r6);
				p1[0] = r6;
				PHALCON_CALL_FUNC_PARAMS(r5, "is_numeric", 1, p1);
				if (zend_is_true(r5)) {
					PHALCON_ALLOC_ZVAL(r8);
					phalcon_array_fetch_long(r8, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r9);
					phalcon_array_fetch_long(r9, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r7);
					phalcon_concat_vboth(r7, r8, " = '", r9 TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r10);
					phalcon_concat_right(r10, r7, "'" TSRMLS_CC);
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
					phalcon_array_update_string(v1, "conditions", strlen("conditions"), r10 TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL(r11);
					phalcon_array_fetch_long(r11, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (phalcon_compare_strict_string(r11, "")) {
						PHALCON_ALLOC_ZVAL(r12);
						phalcon_array_fetch_long(r12, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r13);
						phalcon_concat_right(r13, r12, " = ''" TSRMLS_CC);
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
						phalcon_array_update_string(v1, "conditions", strlen("conditions"), r13 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL(r14);
						phalcon_array_fetch_long(r14, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
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
						phalcon_array_update_string(v1, "conditions", strlen("conditions"), r14 TSRMLS_CC);
					}
				}
			}
			eval_int = phalcon_array_isset_string(v1, "conditions", strlen("conditions")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(r15);
				phalcon_array_fetch_string(r15, v1, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r16);
				phalcon_concat_left(r16, " WHERE ", r15 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r17, v0, r16);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r17);
				v0 = r17;
			}
		}
		eval_int = phalcon_array_isset_string(v1, "order", strlen("order")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r18);
			phalcon_array_fetch_string(r18, v1, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r18)) {
				PHALCON_ALLOC_ZVAL(r19);
				phalcon_array_fetch_string(r19, v1, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, " ORDER BY ", r19 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r21, v0, r20);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r21);
				v0 = r21;
			}
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_CONCAT_FUNCTION(r22, v0, t0);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(r22);
			v0 = r22;
		}
		eval_int = phalcon_array_isset_string(v1, "limit", strlen("limit")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r23);
			phalcon_array_fetch_string(r23, v1, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r23)) {
				PHALCON_ALLOC_ZVAL(r24);
				PHALCON_ALLOC_ZVAL(t1);
				phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t1);
				Z_ADDREF_P(v0);
				p2[0] = v0;
				PHALCON_ALLOC_ZVAL(r25);
				phalcon_array_fetch_string(r25, v1, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r25);
				p2[1] = r25;
				PHALCON_CALL_METHOD_PARAMS(r24, t1, "limit", 2, p2, PHALCON_CALL_DEFAULT);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r24);
				v0 = r24;
			}
		}
		eval_int = phalcon_array_isset_string(v1, "for_update", strlen("for_update")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r26);
			phalcon_array_fetch_string(r26, v1, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r26)) {
				PHALCON_ALLOC_ZVAL(r27);
				PHALCON_ALLOC_ZVAL(t2);
				phalcon_read_property(t2, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t2);
				Z_ADDREF_P(v0);
				p3[0] = v0;
				PHALCON_CALL_METHOD_PARAMS(r27, t2, "forupdate", 1, p3, PHALCON_CALL_DEFAULT);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r27);
				v0 = r27;
			}
		}
		eval_int = phalcon_array_isset_string(v1, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r28);
			phalcon_array_fetch_string(r28, v1, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r28)) {
				PHALCON_ALLOC_ZVAL(r29);
				PHALCON_ALLOC_ZVAL(t3);
				phalcon_read_property(t3, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t3);
				Z_ADDREF_P(v0);
				p4[0] = v0;
				PHALCON_CALL_METHOD_PARAMS(r29, t3, "sharedlock", 1, p4, PHALCON_CALL_DEFAULT);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r29);
				v0 = r29;
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL(r30);
		p5[0] = v1;
		PHALCON_CALL_FUNC_PARAMS(r30, "strlen", 1, p5);
		PHALCON_ALLOC_ZVAL(t4);
		ZVAL_LONG(t4, 0);
		PHALCON_SMALLER_FUNCTION(r31, t4, r30);
		if (zend_is_true(r31)) {
			PHALCON_ALLOC_ZVAL(r32);
			Z_ADDREF_P(v1);
			p6[0] = v1;
			PHALCON_CALL_FUNC_PARAMS(r32, "is_numeric", 1, p6);
			if (zend_is_true(r32)) {
				PHALCON_ALLOC_ZVAL(r34);
				phalcon_array_fetch_long(r34, v2, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r35);
				phalcon_concat_left(r35, "WHERE ", r34 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r33);
				phalcon_concat_vboth(r33, r35, " = '", v1 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r36);
				phalcon_concat_right(r36, r33, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r37, v0, r36);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r37);
				v0 = r37;
			} else {
				PHALCON_ALLOC_ZVAL(r38);
				phalcon_concat_left(r38, "WHERE ", v1 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r39, v0, r38);
				if (v0) {
					if (!Z_REFCOUNT_P(v0)) {
						FREE_ZVAL(v0);
					}
				}
				Z_ADDREF_P(r39);
				v0 = r39;
			}
		}
	}
	if (Z_TYPE_P(v0) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v0);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v0);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

PHP_METHOD(Phalcon_Model_Base, _createResultset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL }, *p7[] = { NULL, NULL }, *p8[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(t0);
	v2 = t0;
	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v0, "return", strlen("return"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_STRING(t1, "1", 1);
	PHALCON_EQUAL_FUNCTION(r1, r0, t1);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v1);
		p0[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r2, v2, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(t2);
		ZVAL_LONG(t2, 0);
		PHALCON_EQUAL_FUNCTION(r3, r2, t2);
		if (zend_is_true(r3)) {
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 0 TSRMLS_CC);
			RETURN_FALSE;
		} else {
			PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_ASSOC");
			Z_ADDREF_P(t3);
			p1[0] = t3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r4);
			Z_ADDREF_P(v1);
			p2[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r4, v2, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r4);
			v3 = r4;
			PHALCON_GET_CLASS_CONSTANT(t4, phalcon_db_class_entry, "DB_BOTH");
			Z_ADDREF_P(t4);
			p3[0] = t4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(v3);
			p4[0] = v3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p4, PHALCON_CALL_DEFAULT);
			phalcon_update_property_long(this_ptr, "_count", strlen("_count"), 1 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r5);
			Z_ADDREF_P(v3);
			p5[0] = v3;
			PHALCON_CALL_METHOD_PARAMS(r5, this_ptr, "dumpresult", 1, p5, PHALCON_CALL_DEFAULT);
			RETURN_ZVAL(r5, 1, 0);
		}
	} else {
		PHALCON_ALLOC_ZVAL(r6);
		Z_ADDREF_P(v1);
		p6[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r6, v2, "numrows", 1, p6, PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r6, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_count", strlen("_count"), copy TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(t5);
		phalcon_read_property(t5, this_ptr, "_count", sizeof("_count")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t5);
		PHALCON_ALLOC_ZVAL(t6);
		ZVAL_LONG(t6, 0);
		PHALCON_SMALLER_FUNCTION(r7, t6, t5);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(this_ptr);
			p7[0] = this_ptr;
			Z_ADDREF_P(v1);
			p7[1] = v1;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p7, PHALCON_CALL_CHECK);
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i0);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(this_ptr);
			p8[0] = this_ptr;
			PHALCON_PARAM_BOOL(p8[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p8, PHALCON_CALL_CHECK);
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		}
	}
	RETURN_NULL();
}

/**
 * Overwrittes default model manager
 *
 * @param Php_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Sets a transaction related to the Model instance
 *
 *
 *
 * @param Php_Transaction $transaction
 */
PHP_METHOD(Phalcon_Model_Base, setTransaction){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), copy TSRMLS_CC);
		}
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "Transaction should be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	if (Z_TYPE_P(this_ptr) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(this_ptr);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Checks wheter model is mapped to a database view
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, isView){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 */
PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getSource){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p1[] = { NULL }, *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (phalcon_compare_strict_string(t0, "")) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(r1);
		p1[0] = this_ptr;
		PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p1);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
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
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 */
PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getSchema){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (phalcon_compare_strict_string(t0, "")) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, r0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t2);
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
}

/**
 * Gets internal Php_Db connection
 *
 * @return Php_Db
 */
PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *
 *
 * @param array $result
 * @return Php_Model $result
 */
PHP_METHOD(Phalcon_Model_Base, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *s0 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_clone(&s0, this_ptr TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(s0);
	v1 = s0;
	zend_update_property_bool(Z_OBJCE_P(v1), v1, "_forceExists", strlen("_forceExists"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		FOREACH_KV(v0, ac0, fes66, fee66, ah0, hp0, v3, v2)
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(v1, Z_STRVAL_P(v3), Z_STRLEN_P(v3), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes66, fee66, ah0, hp0);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	if (Z_TYPE_P(v1) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v1);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v1);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Assigns values to a model from an array
 *
 *
 *
 * @param array $result
 */
PHP_METHOD(Phalcon_Model_Base, dumpResultSelf){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	if (Z_TYPE_P(v0) == IS_ARRAY) { 
		FOREACH_KV(v0, ac0, fes67, fee67, ah0, hp0, v2, v1)
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v1, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v2), Z_STRLEN_P(v2), copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes67, fee67, ah0, hp0);
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	RETURN_NULL();
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return Php_Model_Resulset
 */
PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
		}
	}
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_createsqlselectmulti", 1, p1, PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	PHALCON_ALLOC_ZVAL(r2);
	phalcon_array_fetch_string(r2, v1, "sql", strlen("sql"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r2);
	p2[0] = r2;
	PHALCON_CALL_METHOD_PARAMS(r1, t0, "query", 1, p2, PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	PHALCON_ALLOC_ZVAL(r3);
	Z_ADDREF_P(v1);
	p3[0] = v1;
	Z_ADDREF_P(v2);
	p3[1] = v2;
	PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_createresultset", 2, p3, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r3, 1, 0);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return Php_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p4[] = { NULL, NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_NULL(v0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
		}
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	PHALCON_ALLOC_ZVAL(v3);
	ZVAL_STRING(v3, "SELECT ", 0);
	eval_int = phalcon_array_isset_string(v0, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "clear", PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_array_fetch_string(r2, v0, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r3, v3, r2);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r3);
		v3 = r3;
	} else {
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], ", ", 1);
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		p4[1] = r5;
		PHALCON_CALL_FUNC_PARAMS(r4, "join", 2, p4);
		PHALCON_CONCAT_FUNCTION(r6, v3, r4);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r6);
		v3 = r6;
	}
	if (!phalcon_compare_strict_string(v1, "")) {
		PHALCON_ALLOC_ZVAL(r8);
		phalcon_concat_left(r8, " FROM ", v1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_concat_vboth(r7, r8, ".", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r9, v3, r7);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r9);
		v3 = r9;
	} else {
		PHALCON_ALLOC_ZVAL(r10);
		phalcon_concat_left(r10, " FROM ", v2 TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r11, v3, r10);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r11);
		v3 = r11;
	}
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 1);
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
		phalcon_array_update_string(v0, "limit", strlen("limit"), t0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(v4);
	ZVAL_BOOL(v4, 0);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(t1);
	v5 = t1;
	PHALCON_ALLOC_ZVAL(r12);
	Z_ADDREF_P(v3);
	p6[0] = v3;
	Z_ADDREF_P(v0);
	p6[1] = v0;
	PHALCON_CALL_METHOD_PARAMS(r12, this_ptr, "_createsqlselectone", 2, p6, PHALCON_CALL_DEFAULT);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r12);
	v3 = r12;
	PHALCON_GET_CLASS_CONSTANT(t2, phalcon_db_class_entry, "DB_ASSOC");
	Z_ADDREF_P(t2);
	p7[0] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p7, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r13);
	Z_ADDREF_P(v3);
	p8[0] = v3;
	PHALCON_CALL_METHOD_PARAMS(r13, v5, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r13);
	v6 = r13;
	if (zend_is_true(v6)) {
		Z_ADDREF_P(v6);
		p9[0] = v6;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "dumpresultself", 1, p9, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(r14);
		Z_ADDREF_P(v6);
		p10[0] = v6;
		PHALCON_CALL_METHOD_PARAMS(r14, this_ptr, "dumpresult", 1, p10, PHALCON_CALL_DEFAULT);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
	}
	PHALCON_GET_CLASS_CONSTANT(t3, phalcon_db_class_entry, "DB_BOTH");
	Z_ADDREF_P(t3);
	p11[0] = t3;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v5, "setfetchmode", 1, p11, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v4) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v4);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v4);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Allows to query whether exists at least one record that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return Php_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, exists){

	zval *v0 = NULL;
	zval *r0 = NULL;
	zval *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_exists", 1, p1, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL }, *p13[] = { NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		if (v1) {
			Z_DELREF_P(v1);
			if (!Z_REFCOUNT_P(v1)) {
				FREE_ZVAL(v1);
			}
		}
		Z_ADDREF_P(r0);
		v1 = r0;
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(r1);
		v2 = r1;
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_vboth(r2, v1, ".", v2 TSRMLS_CC);
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(r2);
			v3 = r2;
		} else {
			if (v3) {
				Z_DELREF_P(v3);
				if (!Z_REFCOUNT_P(v3)) {
					FREE_ZVAL(v3);
				}
			}
			Z_ADDREF_P(v2);
			v3 = v2;
		}
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_both(r3,  "SELECT COUNT(*) AS rowcount FROM ", v3, " WHERE " TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r3);
		v4 = r3;
		if (phalcon_compare_strict_string(v0, "")) {
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a0);
			v0 = a0;
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r4);
			v5 = r4;
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
			if (v6) {
				Z_DELREF_P(v6);
				if (!Z_REFCOUNT_P(v6)) {
					FREE_ZVAL(v6);
				}
			}
			Z_ADDREF_P(r5);
			v6 = r5;
			PHALCON_ALLOC_ZVAL(r6);
			p4[0] = v5;
			PHALCON_CALL_FUNC_PARAMS(r6, "count", 1, p4);
			PHALCON_ALLOC_ZVAL(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_SMALLER_FUNCTION(r7, t1, r6);
			if (zend_is_true(r7)) {
				FOREACH_V(v5, ac0, fes68, fee68, ah0, hp0, v7)
					if (!t2) {
						PHALCON_ALLOC_ZVAL(t2);
					} else {
						if (Z_REFCOUNT_P(t2) > 1) {
							{
								zval *orig_ptr = t2;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t2);
									*t2 = *orig_ptr;
									zval_copy_ctor(t2);
									Z_SET_REFCOUNT_P(t2, 1);
									Z_UNSET_ISREF_P(t2);
								}
							}
						} else {
							FREE_ZVAL(t2);
							PHALCON_ALLOC_ZVAL(t2);
						}
					}
					phalcon_read_property_zval(t2, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t2);
					PHALCON_INIT_NULL(t3);
					PHALCON_NOT_IDENTICAL_FUNCTION(r8, t2, t3);
					if (!t4) {
						PHALCON_ALLOC_ZVAL(t4);
					} else {
						if (Z_REFCOUNT_P(t4) > 1) {
							{
								zval *orig_ptr = t4;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t4);
									*t4 = *orig_ptr;
									zval_copy_ctor(t4);
									Z_SET_REFCOUNT_P(t4, 1);
									Z_UNSET_ISREF_P(t4);
								}
							}
						} else {
							FREE_ZVAL(t4);
							PHALCON_ALLOC_ZVAL(t4);
						}
					}
					phalcon_read_property_zval(t4, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t4);
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
					ZVAL_STRING(t5, "", 1);
					PHALCON_NOT_IDENTICAL_FUNCTION(r9, t4, t5);
					PHALCON_AND_FUNCTION(r10, r8, r9);
					if (zend_is_true(r10)) {
						eval_int = phalcon_array_isset(v6, v7);
						if (eval_int) {
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
							phalcon_concat_left(r12, " ", v7 TSRMLS_CC);
							if (!t6) {
								PHALCON_ALLOC_ZVAL(t6);
							} else {
								if (Z_REFCOUNT_P(t6) > 1) {
									{
										zval *orig_ptr = t6;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(t6);
											*t6 = *orig_ptr;
											zval_copy_ctor(t6);
											Z_SET_REFCOUNT_P(t6, 1);
											Z_UNSET_ISREF_P(t6);
										}
									}
								} else {
									FREE_ZVAL(t6);
									PHALCON_ALLOC_ZVAL(t6);
								}
							}
							phalcon_read_property_zval(t6, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
							zval_copy_ctor(t6);
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
							phalcon_concat_vboth(r11, r12, " = ", t6 TSRMLS_CC);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r11, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
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
								phalcon_array_append(v0, copy TSRMLS_CC);
							}
						} else {
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
							phalcon_concat_left(r14, " ", v7 TSRMLS_CC);
							if (!t7) {
								PHALCON_ALLOC_ZVAL(t7);
							} else {
								if (Z_REFCOUNT_P(t7) > 1) {
									{
										zval *orig_ptr = t7;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(t7);
											*t7 = *orig_ptr;
											zval_copy_ctor(t7);
											Z_SET_REFCOUNT_P(t7, 1);
											Z_UNSET_ISREF_P(t7);
										}
									}
								} else {
									FREE_ZVAL(t7);
									PHALCON_ALLOC_ZVAL(t7);
								}
							}
							phalcon_read_property_zval(t7, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
							zval_copy_ctor(t7);
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
							phalcon_concat_vboth(r13, r14, " = '", t7 TSRMLS_CC);
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
							phalcon_concat_right(r15, r13, "'" TSRMLS_CC);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r15, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
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
								phalcon_array_append(v0, copy TSRMLS_CC);
							}
						}
					}
				END_FOREACH(ac0, fes68, fee68, ah0, hp0);
				PHALCON_ALLOC_ZVAL(r16);
				p5[0] = v0;
				PHALCON_CALL_FUNC_PARAMS(r16, "count", 1, p5);
				if (zend_is_true(r16)) {
					PHALCON_ALLOC_ZVAL(r17);
					PHALCON_ALLOC_ZVAL(p6[0]);
					ZVAL_STRING(p6[0], " AND ", 1);
					p6[1] = v0;
					PHALCON_CALL_FUNC_PARAMS(r17, "join", 2, p6);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r17, 1, 0);
						Z_SET_REFCOUNT_P(copy, 0);
						phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), copy TSRMLS_CC);
					}
				} else {
					RETURN_LONG(0);
				}
				PHALCON_ALLOC_ZVAL(t8);
				phalcon_read_property(t8, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t8);
				PHALCON_CONCAT_FUNCTION(r18, v4, t8);
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r18);
				v4 = r18;
			} else {
				RETURN_LONG(0);
			}
		} else {
			PHALCON_ALLOC_ZVAL(r19);
			Z_ADDREF_P(v0);
			p7[0] = v0;
			PHALCON_CALL_FUNC_PARAMS(r19, "is_numeric", 1, p7);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, "id = ", v0 TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r21, v4, r20);
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r21);
				v4 = r21;
			} else {
				PHALCON_CONCAT_FUNCTION(r22, v4, v0);
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r22);
				v4 = r22;
			}
		}
		PHALCON_ALLOC_ZVAL(r23);
		PHALCON_ALLOC_ZVAL(t9);
		phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t9);
		Z_ADDREF_P(v4);
		p8[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r23, t9, "fetchone", 1, p8, PHALCON_CALL_DEFAULT);
		if (v8) {
			Z_DELREF_P(v8);
			if (!Z_REFCOUNT_P(v8)) {
				FREE_ZVAL(v8);
			}
		}
		Z_ADDREF_P(r23);
		v8 = r23;
		PHALCON_ALLOC_ZVAL(r24);
		phalcon_array_fetch_string(r24, v8, "rowcount", strlen("rowcount"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r24) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r24);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r24);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(a1);
		v0 = a1;
		PHALCON_ALLOC_ZVAL(r25);
		PHALCON_CALL_METHOD(r25, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r25);
		v5 = r25;
		PHALCON_ALLOC_ZVAL(r26);
		PHALCON_CALL_METHOD(r26, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		if (v9) {
			Z_DELREF_P(v9);
			if (!Z_REFCOUNT_P(v9)) {
				FREE_ZVAL(v9);
			}
		}
		Z_ADDREF_P(r26);
		v9 = r26;
		PHALCON_ALLOC_ZVAL(r27);
		p11[0] = v5;
		PHALCON_CALL_FUNC_PARAMS(r27, "count", 1, p11);
		PHALCON_ALLOC_ZVAL(t10);
		ZVAL_LONG(t10, 0);
		PHALCON_SMALLER_FUNCTION(r28, t10, r27);
		if (zend_is_true(r28)) {
			FOREACH_V(v5, ac1, fes69, fee69, ah1, hp1, v7)
				if (!t11) {
					PHALCON_ALLOC_ZVAL(t11);
				} else {
					if (Z_REFCOUNT_P(t11) > 1) {
						{
							zval *orig_ptr = t11;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t11);
								*t11 = *orig_ptr;
								zval_copy_ctor(t11);
								Z_SET_REFCOUNT_P(t11, 1);
								Z_UNSET_ISREF_P(t11);
							}
						}
					} else {
						FREE_ZVAL(t11);
						PHALCON_ALLOC_ZVAL(t11);
					}
				}
				phalcon_read_property_zval(t11, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t11);
				PHALCON_INIT_NULL(t12);
				PHALCON_NOT_IDENTICAL_FUNCTION(r29, t11, t12);
				if (!t13) {
					PHALCON_ALLOC_ZVAL(t13);
				} else {
					if (Z_REFCOUNT_P(t13) > 1) {
						{
							zval *orig_ptr = t13;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t13);
								*t13 = *orig_ptr;
								zval_copy_ctor(t13);
								Z_SET_REFCOUNT_P(t13, 1);
								Z_UNSET_ISREF_P(t13);
							}
						}
					} else {
						FREE_ZVAL(t13);
						PHALCON_ALLOC_ZVAL(t13);
					}
				}
				phalcon_read_property_zval(t13, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t13);
				if (!t14) {
					PHALCON_ALLOC_ZVAL(t14);
				} else {
					if (Z_REFCOUNT_P(t14) > 1) {
						SEPARATE_ZVAL(&t14);
					} else {
						if (Z_TYPE_P(t14) != IS_STRING) {
							FREE_ZVAL(t14);
							PHALCON_ALLOC_ZVAL(t14);
						}
					}
				}
				ZVAL_STRING(t14, "", 1);
				PHALCON_NOT_IDENTICAL_FUNCTION(r30, t13, t14);
				PHALCON_AND_FUNCTION(r31, r29, r30);
				if (zend_is_true(r31)) {
					eval_int = phalcon_array_isset(v9, v7);
					if (eval_int) {
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
						phalcon_concat_left(r33, " ", v7 TSRMLS_CC);
						if (!t15) {
							PHALCON_ALLOC_ZVAL(t15);
						} else {
							if (Z_REFCOUNT_P(t15) > 1) {
								{
									zval *orig_ptr = t15;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(t15);
										*t15 = *orig_ptr;
										zval_copy_ctor(t15);
										Z_SET_REFCOUNT_P(t15, 1);
										Z_UNSET_ISREF_P(t15);
									}
								}
							} else {
								FREE_ZVAL(t15);
								PHALCON_ALLOC_ZVAL(t15);
							}
						}
						phalcon_read_property_zval(t15, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						zval_copy_ctor(t15);
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
						phalcon_concat_vboth(r32, r33, " = ", t15 TSRMLS_CC);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r32, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
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
							phalcon_array_append(v0, copy TSRMLS_CC);
						}
					} else {
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
						phalcon_concat_left(r35, " ", v7 TSRMLS_CC);
						if (!t16) {
							PHALCON_ALLOC_ZVAL(t16);
						} else {
							if (Z_REFCOUNT_P(t16) > 1) {
								{
									zval *orig_ptr = t16;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(t16);
										*t16 = *orig_ptr;
										zval_copy_ctor(t16);
										Z_SET_REFCOUNT_P(t16, 1);
										Z_UNSET_ISREF_P(t16);
									}
								}
							} else {
								FREE_ZVAL(t16);
								PHALCON_ALLOC_ZVAL(t16);
							}
						}
						phalcon_read_property_zval(t16, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						zval_copy_ctor(t16);
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
						phalcon_concat_vboth(r34, r35, " = '", t16 TSRMLS_CC);
						if (!r36) {
							PHALCON_ALLOC_ZVAL(r36);
						} else {
							if (Z_REFCOUNT_P(r36) > 1) {
								{
									zval *orig_ptr = r36;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r36);
										*r36 = *orig_ptr;
										zval_copy_ctor(r36);
										Z_SET_REFCOUNT_P(r36, 1);
										Z_UNSET_ISREF_P(r36);
									}
								}
							} else {
								FREE_ZVAL(r36);
								PHALCON_ALLOC_ZVAL(r36);
							}
						}
						phalcon_concat_right(r36, r34, "'" TSRMLS_CC);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r36, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
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
							phalcon_array_append(v0, copy TSRMLS_CC);
						}
					}
				}
			END_FOREACH(ac1, fes69, fee69, ah1, hp1);
			PHALCON_ALLOC_ZVAL(r37);
			p12[0] = v0;
			PHALCON_CALL_FUNC_PARAMS(r37, "count", 1, p12);
			if (zend_is_true(r37)) {
				PHALCON_ALLOC_ZVAL(r38);
				PHALCON_ALLOC_ZVAL(p13[0]);
				ZVAL_STRING(p13[0], " AND ", 1);
				p13[1] = v0;
				PHALCON_CALL_FUNC_PARAMS(r38, "join", 2, p13);
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, r38, 1, 0);
					Z_SET_REFCOUNT_P(copy, 0);
					phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), copy TSRMLS_CC);
				}
				RETURN_TRUE;
			} else {
				RETURN_LONG(0);
			}
		} else {
			RETURN_LONG(0);
		}
	}
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(t0);
	v3 = t0;
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v1);
		p0[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r0, v3, "query", 1, p0, PHALCON_CALL_DEFAULT);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r0);
		v4 = r0;
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v4);
		p1[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r1, v3, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		if (v5) {
			Z_DELREF_P(v5);
			if (!Z_REFCOUNT_P(v5)) {
				FREE_ZVAL(v5);
			}
		}
		Z_ADDREF_P(r1);
		v5 = r1;
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_SMALLER_FUNCTION(r2, t1, v5);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_row_class_entry);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			if (v6) {
				Z_DELREF_P(v6);
				if (!Z_REFCOUNT_P(v6)) {
					FREE_ZVAL(v6);
				}
			}
			Z_ADDREF_P(i0);
			v6 = i0;
			Z_ADDREF_P(v3);
			p3[0] = v3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v6);
			p4[0] = v6;
			Z_ADDREF_P(v4);
			p4[1] = v4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i1);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		} else {
			PHALCON_ALLOC_ZVAL(i2);
			object_init_ex(i2, phalcon_model_resultset_class_entry);
			PHALCON_ALLOC_ZVAL(i3);
			object_init(i3);
			Z_ADDREF_P(i3);
			p5[0] = i3;
			PHALCON_PARAM_BOOL(p5[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(i2);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
				Z_SET_REFCOUNT_P(return_value, refcount);
			}
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL(r3);
		Z_ADDREF_P(v1);
		p6[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r3, v3, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		if (v7) {
			Z_DELREF_P(v7);
			if (!Z_REFCOUNT_P(v7)) {
				FREE_ZVAL(v7);
			}
		}
		Z_ADDREF_P(r3);
		v7 = r3;
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch(r4, v7, v2, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (Z_TYPE_P(r4) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r4);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(r4);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	}
	RETURN_NULL();
}

/**
 * Allows to count how many records match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return int
 */
PHP_METHOD(Phalcon_Model_Base, count){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL, NULL, NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			if (v0) {
				if (!Z_REFCOUNT_P(v0)) {
					FREE_ZVAL(v0);
				}
			}
			Z_ADDREF_P(a1);
			v0 = a1;
		}
	}
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r0);
	v1 = r0;
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	if (v2) {
		Z_DELREF_P(v2);
		if (!Z_REFCOUNT_P(v2)) {
			FREE_ZVAL(v2);
		}
	}
	Z_ADDREF_P(r1);
	v2 = r1;
	if (zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r2);
		phalcon_concat_vboth(r2, v1, ".", v2 TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r2);
		v3 = r2;
	} else {
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(v2);
		v3 = v2;
	}
	eval_int = phalcon_array_isset_string(v0, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_string(r4, v0, "distinct", strlen("distinct"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_left(r5, "SELECT COUNT(DISTINCT ", r4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_concat_vboth(r3, r5, ") AS rowcount FROM ", v3 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_concat_right(r6, r3, " " TSRMLS_CC);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r6);
		v4 = r6;
	} else {
		eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r8);
			phalcon_array_fetch_string(r8, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r9);
			phalcon_concat_left(r9, "SELECT ", r8 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r7);
			phalcon_concat_vboth(r7, r9, ", COUNT(*) AS rowcount FROM ", v3 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r10);
			phalcon_concat_right(r10, r7, " " TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r10);
			v4 = r10;
		} else {
			PHALCON_ALLOC_ZVAL(r11);
			phalcon_concat_both(r11,  "SELECT COUNT(*) AS rowcount FROM ", v3, " " TSRMLS_CC);
			if (v4) {
				Z_DELREF_P(v4);
				if (!Z_REFCOUNT_P(v4)) {
					FREE_ZVAL(v4);
				}
			}
			Z_ADDREF_P(r11);
			v4 = r11;
		}
	}
	eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r12);
		phalcon_array_fetch_string(r12, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_concat_both(r13,  " WHERE ", r12, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r14, v4, r13);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r14);
		v4 = r14;
	} else {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r15);
			phalcon_array_fetch_long(r15, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			if (v5) {
				Z_DELREF_P(v5);
				if (!Z_REFCOUNT_P(v5)) {
					FREE_ZVAL(v5);
				}
			}
			Z_ADDREF_P(r15);
			v5 = r15;
			PHALCON_ALLOC_ZVAL(r16);
			Z_ADDREF_P(v5);
			p3[0] = v5;
			PHALCON_CALL_FUNC_PARAMS(r16, "is_numeric", 1, p3);
			if (zend_is_true(r16)) {
				PHALCON_ALLOC_ZVAL(r17);
				PHALCON_CALL_METHOD(r17, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
				if (v6) {
					Z_DELREF_P(v6);
					if (!Z_REFCOUNT_P(v6)) {
						FREE_ZVAL(v6);
					}
				}
				Z_ADDREF_P(r17);
				v6 = r17;
				PHALCON_ALLOC_ZVAL(t0);
				phalcon_read_property(t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t0);
				if (zend_is_true(t0)) {
					PHALCON_ALLOC_ZVAL(t1);
					ZVAL_STRING(t1, "id", 1);
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
					phalcon_array_update_long(v6, 0, t1 TSRMLS_CC);
				}
				PHALCON_ALLOC_ZVAL(r19);
				phalcon_array_fetch_long(r19, v6, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_concat_left(r20, " WHERE ", r19 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r18);
				phalcon_concat_vboth(r18, r20, " = '", v5 TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r21);
				phalcon_concat_right(r21, r18, "'" TSRMLS_CC);
				PHALCON_CONCAT_FUNCTION(r22, v4, r21);
				if (v4) {
					Z_DELREF_P(v4);
					if (!Z_REFCOUNT_P(v4)) {
						FREE_ZVAL(v4);
					}
				}
				Z_ADDREF_P(r22);
				v4 = r22;
			} else {
				if (zend_is_true(v5)) {
					PHALCON_ALLOC_ZVAL(r23);
					phalcon_concat_left(r23, " WHERE ", v5 TSRMLS_CC);
					PHALCON_CONCAT_FUNCTION(r24, v4, r23);
					if (v4) {
						Z_DELREF_P(v4);
						if (!Z_REFCOUNT_P(v4)) {
							FREE_ZVAL(v4);
						}
					}
					Z_ADDREF_P(r24);
					v4 = r24;
				}
			}
		}
	}
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r25);
		phalcon_array_fetch_string(r25, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r26);
		phalcon_concat_both(r26,  " GROUP BY ", r25, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r27, v4, r26);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r27);
		v4 = r27;
	}
	eval_int = phalcon_array_isset_string(v0, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_array_fetch_string(r28, v0, "having", strlen("having"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r29);
		phalcon_concat_both(r29,  " HAVING ", r28, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r30, v4, r29);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r30);
		v4 = r30;
	}
	eval_int = phalcon_array_isset_string(v0, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r31);
		phalcon_array_fetch_string(r31, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r32);
		phalcon_concat_both(r32,  " ORDER BY ", r31, " " TSRMLS_CC);
		PHALCON_CONCAT_FUNCTION(r33, v4, r32);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r33);
		v4 = r33;
	}
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r34);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "connection", sizeof("connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		Z_ADDREF_P(v4);
		p5[0] = v4;
		PHALCON_ALLOC_ZVAL(r35);
		phalcon_array_fetch_string(r35, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r35);
		p5[1] = r35;
		PHALCON_CALL_METHOD_PARAMS(r34, t2, "_limit", 2, p5, PHALCON_CALL_DEFAULT);
		if (v4) {
			Z_DELREF_P(v4);
			if (!Z_REFCOUNT_P(v4)) {
				FREE_ZVAL(v4);
			}
		}
		Z_ADDREF_P(r34);
		v4 = r34;
	}
	PHALCON_ALLOC_ZVAL(r36);
	Z_ADDREF_P(v0);
	p6[0] = v0;
	Z_ADDREF_P(v4);
	p6[1] = v4;
	PHALCON_ALLOC_ZVAL(p6[2]);
	ZVAL_STRING(p6[2], "rowcount", 1);
	PHALCON_CALL_METHOD_PARAMS(r36, this_ptr, "_getgroupresult", 3, p6, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r36, 1, 0);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, v0 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			RETURN_FALSE;
		}
	} else {
		eval_int = phalcon_isset_property_zval(this_ptr, v0 TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(t0);
			phalcon_read_property_zval(t0, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t0);
			if (v1) {
				Z_DELREF_P(v1);
				if (!Z_REFCOUNT_P(v1)) {
					FREE_ZVAL(v1);
				}
			}
			Z_ADDREF_P(t0);
			v1 = t0;
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_CALL_METHOD(r1, this_ptr, Z_STRVAL_P(v1), PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				RETURN_FALSE;
			}
		}
	}
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL };

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_FALSE(t1);
	PHALCON_EQUAL_FUNCTION(r0, t0, t1);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_GET_CLASS_CONSTANT(t3, phalcon_model_base_class_entry, "OP_DELETE");
		PHALCON_EQUAL_FUNCTION(r1, t2, t3);
		if (zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL(p0[0]);
			ZVAL_STRING(p0[0], "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		} else {
			PHALCON_ALLOC_ZVAL(p1[0]);
			ZVAL_STRING(p1[0], "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "isautomatic");
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CALL_STATIC(r3, "phalcon_transaction_manager", "getautomatic");
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r3);
		v0 = r3;
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setrollbackedrecord", 1, p4, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_METHOD_NORETURN(v0, "rollback", PHALCON_CALL_DEFAULT);
	} else {
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Appends a customized message on the validation process
 *
 * 
 *
 * @param Php_Model_Message $message
 */
PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL }, *p3[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL(r0);
		p0[0] = v0;
		PHALCON_CALL_FUNC_PARAMS(r0, "get_class", 1, p0);
		if (!phalcon_compare_strict_string(r0, "Phalcon_Model_Message")) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL(r1);
			p2[0] = v0;
			PHALCON_CALL_FUNC_PARAMS(r1, "get_class", 1, p2);
			PHALCON_ALLOC_ZVAL(r2);
			phalcon_concat_both(r2,  "Invalid message format '", r1, "'" TSRMLS_CC);
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(r3);
		Z_ADDREF_P(v0);
		p4[0] = v0;
		PHALCON_CALL_FUNC_PARAMS(r3, "gettype", 1, p4);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_concat_both(r4,  "Invalid message format '", r3, "'" TSRMLS_CC);
		Z_ADDREF_P(r4);
		p3[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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
	phalcon_array_append(t0, v0 TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

/**
 * Returns all the validation messages
 *
 * 
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getMessages){

	zval *t0 = NULL;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
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
}

/**
 * Inserts or updates a model instance. Returns true on success or else false .
 *
 * 
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, save){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL, *v13 = NULL;
	zval *v14 = NULL, *v15 = NULL, *v16 = NULL, *v17 = NULL, *v18 = NULL, *v19 = NULL, *v20 = NULL;
	zval *v21 = NULL, *v22 = NULL, *v23 = NULL, *v24 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL, *r52 = NULL, *r53 = NULL, *r54 = NULL, *r55 = NULL;
	zval *r56 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL, *t15 = NULL, *t16 = NULL, *t17 = NULL, *t18 = NULL, *t19 = NULL, *t20 = NULL;
	zval *t21 = NULL, *t22 = NULL, *t23 = NULL, *t24 = NULL, *t25 = NULL, *t26 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL;
	zval *i0 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *p2[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p10[] = { NULL }, *p11[] = { NULL }, *p12[] = { NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p14[] = { NULL }, *p16[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL }, *p29[] = { NULL }, *p38[] = { NULL }, *p39[] = { NULL, NULL, NULL, NULL }, *p42[] = { NULL }, *p43[] = { NULL }, *p44[] = { NULL, NULL, NULL }, *p48[] = { NULL }, *p49[] = { NULL }, *p50[] = { NULL }, *p51[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	if (v0) {
		if (!Z_REFCOUNT_P(v0)) {
			FREE_ZVAL(v0);
		}
	}
	Z_ADDREF_P(r0);
	v0 = r0;
	if (!zend_is_true(v0)) {
		PHALCON_GET_CLASS_CONSTANT(t0, phalcon_model_base_class_entry, "OP_CREATE");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t0, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
		}
	} else {
		PHALCON_GET_CLASS_CONSTANT(t1, phalcon_model_base_class_entry, "OP_UPDATE");
		{
			zval *copy;
			ALLOC_ZVAL(copy);
			ZVAL_ZVAL(copy, t1, 1, 0);
			Z_SET_REFCOUNT_P(copy, 0);
			phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, a0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(t2);
	v1 = t2;
	if (!zend_is_true(v1)) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_ALLOC_ZVAL(p2[0]);
		ZVAL_STRING(p2[0], "beforeValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		if (!zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_ALLOC_ZVAL(p4[0]);
			ZVAL_STRING(p4[0], "beforeValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL(r3);
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], "beforeValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r3) == IS_BOOL && !Z_BVAL_P(r3)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
	}
	PHALCON_INIT_NULL(v2);
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	if (v3) {
		Z_DELREF_P(v3);
		if (!Z_REFCOUNT_P(v3)) {
			FREE_ZVAL(v3);
		}
	}
	Z_ADDREF_P(r4);
	v3 = r4;
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r5);
	v4 = r5;
	if (Z_TYPE_P(v3) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_BOOL(v5, 0);
		PHALCON_ALLOC_ZVAL(r6);
		p10[0] = v3;
		PHALCON_CALL_FUNC_PARAMS(r6, "count", 1, p10);
		if (v6) {
			Z_DELREF_P(v6);
			if (!Z_REFCOUNT_P(v6)) {
				FREE_ZVAL(v6);
			}
		}
		Z_ADDREF_P(r6);
		v6 = r6;
		PHALCON_ALLOC_ZVAL(v7);
		ZVAL_LONG(v7, 0);
		fs70:
		PHALCON_SMALLER_FUNCTION(r7, v7, v6);
		if (!zend_is_true(r7)) {
			goto fe70;
		}
		if (!v8) {
			PHALCON_ALLOC_ZVAL(v8);
		} else {
			if (Z_REFCOUNT_P(v8) > 1) {
				SEPARATE_ZVAL(&v8);
			} else {
				if (Z_TYPE_P(v8) != IS_BOOL) {
					FREE_ZVAL(v8);
					PHALCON_ALLOC_ZVAL(v8);
				}
			}
		}
		ZVAL_BOOL(v8, 0);
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
		phalcon_array_fetch(r8, v3, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		if (v9) {
			Z_DELREF_P(v9);
			if (!Z_REFCOUNT_P(v9)) {
				FREE_ZVAL(v9);
			}
		}
		Z_ADDREF_P(r8);
		v9 = r8;
		if (!t3) {
			PHALCON_ALLOC_ZVAL(t3);
		} else {
			if (Z_REFCOUNT_P(t3) > 1) {
				{
					zval *orig_ptr = t3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t3);
						*t3 = *orig_ptr;
						zval_copy_ctor(t3);
						Z_SET_REFCOUNT_P(t3, 1);
						Z_UNSET_ISREF_P(t3);
					}
				}
			} else {
				FREE_ZVAL(t3);
				PHALCON_ALLOC_ZVAL(t3);
			}
		}
		phalcon_read_property_zval(t3, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		if (v10) {
			Z_DELREF_P(v10);
			if (!Z_REFCOUNT_P(v10)) {
				FREE_ZVAL(v10);
			}
		}
		Z_ADDREF_P(t3);
		v10 = t3;
		eval_int = phalcon_array_isset(v4, v9);
		if (!eval_int) {
			PHALCON_INIT_NULL(t4);
			PHALCON_IDENTICAL_FUNCTION(r9, v10, t4);
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
			ZVAL_STRING(t5, "", 1);
			PHALCON_IDENTICAL_FUNCTION(r10, v10, t5);
			PHALCON_OR_FUNCTION(r11, r9, r10);
			if (zend_is_true(r11)) {
				if (!v8) {
					PHALCON_ALLOC_ZVAL(v8);
				} else {
					if (Z_REFCOUNT_P(v8) > 1) {
						SEPARATE_ZVAL(&v8);
					} else {
						if (Z_TYPE_P(v8) != IS_BOOL) {
							FREE_ZVAL(v8);
							PHALCON_ALLOC_ZVAL(v8);
						}
					}
				}
				ZVAL_BOOL(v8, 1);
			}
		} else {
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
			Z_ADDREF_P(v10);
			p11[0] = v10;
			PHALCON_CALL_FUNC_PARAMS(r12, "is_numeric", 1, p11);
			if (!zend_is_true(r12)) {
				if (!v8) {
					PHALCON_ALLOC_ZVAL(v8);
				} else {
					if (Z_REFCOUNT_P(v8) > 1) {
						SEPARATE_ZVAL(&v8);
					} else {
						if (Z_TYPE_P(v8) != IS_BOOL) {
							FREE_ZVAL(v8);
							PHALCON_ALLOC_ZVAL(v8);
						}
					}
				}
				ZVAL_BOOL(v8, 1);
			}
		}
		PHALCON_INIT_TRUE(t6);
		PHALCON_EQUAL_FUNCTION(r13, v8, t6);
		if (zend_is_true(r13)) {
			PHALCON_BOOLEAN_NOT_FUNCTION(r14, v0);
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
			ZVAL_STRING(t7, "id", 1);
			PHALCON_EQUAL_FUNCTION(r15, v9, t7);
			PHALCON_AND_FUNCTION(r16, r14, r15);
			if (zend_is_true(r16)) {
				goto fi70;
			}
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
			if (!p12[0]) {
				PHALCON_ALLOC_ZVAL(p12[0]);
			} else {
				if (Z_REFCOUNT_P(p12[0]) > 1) {
					SEPARATE_ZVAL(&p12[0]);
				} else {
					if (Z_TYPE_P(p12[0]) != IS_STRING) {
						FREE_ZVAL(p12[0]);
						PHALCON_ALLOC_ZVAL(p12[0]);
					}
				}
			}
			ZVAL_STRING(p12[0], "_id", 1);
			if (!p12[1]) {
				PHALCON_ALLOC_ZVAL(p12[1]);
			} else {
				if (Z_REFCOUNT_P(p12[1]) > 1) {
					SEPARATE_ZVAL(&p12[1]);
				} else {
					if (Z_TYPE_P(p12[1]) != IS_STRING) {
						FREE_ZVAL(p12[1]);
						PHALCON_ALLOC_ZVAL(p12[1]);
					}
				}
			}
			ZVAL_STRING(p12[1], "", 1);
			p12[2] = v9;
			PHALCON_CALL_FUNC_PARAMS(r17, "str_replace", 3, p12);
			if (v11) {
				Z_DELREF_P(v11);
				if (!Z_REFCOUNT_P(v11)) {
					FREE_ZVAL(v11);
				}
			}
			Z_ADDREF_P(r17);
			v11 = r17;
			if (!i0) {
				PHALCON_ALLOC_ZVAL(i0);
			} else {
				if (Z_REFCOUNT_P(i0) > 1) {
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
			object_init_ex(i0, phalcon_model_message_class_entry);
			if (!r18) {
				PHALCON_ALLOC_ZVAL(r18);
			} else {
				if (Z_REFCOUNT_P(r18) > 1) {
					{
						zval *orig_ptr = r18;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(r18);
							*r18 = *orig_ptr;
							zval_copy_ctor(r18);
							Z_SET_REFCOUNT_P(r18, 1);
							Z_UNSET_ISREF_P(r18);
						}
					}
				} else {
					FREE_ZVAL(r18);
					PHALCON_ALLOC_ZVAL(r18);
				}
			}
			phalcon_concat_right(r18, v11, " is required" TSRMLS_CC);
			Z_ADDREF_P(r18);
			p13[0] = r18;
			Z_ADDREF_P(v9);
			p13[1] = v9;
			if (!p13[2]) {
				PHALCON_ALLOC_ZVAL(p13[2]);
			} else {
				if (Z_REFCOUNT_P(p13[2]) > 1) {
					SEPARATE_ZVAL(&p13[2]);
				} else {
					if (Z_TYPE_P(p13[2]) != IS_STRING) {
						FREE_ZVAL(p13[2]);
						PHALCON_ALLOC_ZVAL(p13[2]);
					}
				}
			}
			ZVAL_STRING(p13[2], "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p13, PHALCON_CALL_CHECK);
			if (v12) {
				Z_DELREF_P(v12);
				if (!Z_REFCOUNT_P(v12)) {
					FREE_ZVAL(v12);
				}
			}
			Z_ADDREF_P(i0);
			v12 = i0;
			if (!t8) {
				PHALCON_ALLOC_ZVAL(t8);
			} else {
				if (Z_REFCOUNT_P(t8) > 1) {
					{
						zval *orig_ptr = t8;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t8);
							*t8 = *orig_ptr;
							zval_copy_ctor(t8);
							Z_SET_REFCOUNT_P(t8, 1);
							Z_UNSET_ISREF_P(t8);
						}
					}
				} else {
					FREE_ZVAL(t8);
					PHALCON_ALLOC_ZVAL(t8);
				}
			}
			phalcon_read_property(t8, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t8);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v12, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = t8;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(t8);
						*t8 = *orig_ptr;
						zval_copy_ctor(t8);
						Z_SET_REFCOUNT_P(t8, 1);
						Z_UNSET_ISREF_P(t8);
					}
				}
				phalcon_array_append(t8, copy TSRMLS_CC);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, t8, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), copy TSRMLS_CC);
			}
			if (!v5) {
				PHALCON_ALLOC_ZVAL(v5);
			} else {
				if (Z_REFCOUNT_P(v5) > 1) {
					SEPARATE_ZVAL(&v5);
				} else {
					if (Z_TYPE_P(v5) != IS_BOOL) {
						FREE_ZVAL(v5);
						PHALCON_ALLOC_ZVAL(v5);
					}
				}
			}
			ZVAL_BOOL(v5, 1);
		}
		fi70:
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
		increment_function(v7);
		goto fs70;
		fe70:
		r7 = NULL;
		if (zend_is_true(v5)) {
			if (!zend_is_true(v1)) {
				PHALCON_ALLOC_ZVAL(p14[0]);
				ZVAL_STRING(p14[0], "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p14, PHALCON_CALL_DEFAULT);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL(r19);
	PHALCON_ALLOC_ZVAL(p16[0]);
	ZVAL_STRING(p16[0], "validation", 1);
	PHALCON_CALL_METHOD_PARAMS(r19, this_ptr, "_callevent", 1, p16, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(p17[0]);
			ZVAL_STRING(p17[0], "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p17, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	if (!zend_is_true(v1)) {
		if (!zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL(r20);
			PHALCON_ALLOC_ZVAL(p19[0]);
			ZVAL_STRING(p19[0], "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r20, this_ptr, "_callevent", 1, p19, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL(r21);
			PHALCON_ALLOC_ZVAL(p21[0]);
			ZVAL_STRING(p21[0], "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r21, this_ptr, "_callevent", 1, p21, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
		PHALCON_ALLOC_ZVAL(r22);
		PHALCON_ALLOC_ZVAL(p23[0]);
		ZVAL_STRING(p23[0], "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r22, this_ptr, "_callevent", 1, p23, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL(r23);
		PHALCON_ALLOC_ZVAL(p25[0]);
		ZVAL_STRING(p25[0], "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "_callevent", 1, p25, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			RETURN_FALSE;
		}
		if (zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL(r24);
			PHALCON_ALLOC_ZVAL(p27[0]);
			ZVAL_STRING(p27[0], "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r24, this_ptr, "_callevent", 1, p27, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r24) == IS_BOOL && !Z_BVAL_P(r24)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL(r25);
			PHALCON_ALLOC_ZVAL(p29[0]);
			ZVAL_STRING(p29[0], "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "_callevent", 1, p29, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r25) == IS_BOOL && !Z_BVAL_P(r25)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				RETURN_FALSE;
			}
		}
	}
	PHALCON_ALLOC_ZVAL(r26);
	PHALCON_CALL_METHOD(r26, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	if (v13) {
		Z_DELREF_P(v13);
		if (!Z_REFCOUNT_P(v13)) {
			FREE_ZVAL(v13);
		}
	}
	Z_ADDREF_P(r26);
	v13 = r26;
	PHALCON_ALLOC_ZVAL(r27);
	PHALCON_CALL_METHOD(r27, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	if (v14) {
		Z_DELREF_P(v14);
		if (!Z_REFCOUNT_P(v14)) {
			FREE_ZVAL(v14);
		}
	}
	Z_ADDREF_P(r27);
	v14 = r27;
	if (zend_is_true(v13)) {
		PHALCON_ALLOC_ZVAL(r28);
		phalcon_concat_vboth(r28, v13, ".", v14 TSRMLS_CC);
		if (v15) {
			Z_DELREF_P(v15);
			if (!Z_REFCOUNT_P(v15)) {
				FREE_ZVAL(v15);
			}
		}
		Z_ADDREF_P(r28);
		v15 = r28;
	} else {
		if (v15) {
			Z_DELREF_P(v15);
			if (!Z_REFCOUNT_P(v15)) {
				FREE_ZVAL(v15);
			}
		}
		Z_ADDREF_P(v14);
		v15 = v14;
	}
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	if (v16) {
		Z_DELREF_P(v16);
		if (!Z_REFCOUNT_P(v16)) {
			FREE_ZVAL(v16);
		}
	}
	Z_ADDREF_P(t9);
	v16 = t9;
	PHALCON_ALLOC_ZVAL(r29);
	PHALCON_CALL_METHOD(r29, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	if (v17) {
		Z_DELREF_P(v17);
		if (!Z_REFCOUNT_P(v17)) {
			FREE_ZVAL(v17);
		}
	}
	Z_ADDREF_P(r29);
	v17 = r29;
	PHALCON_ALLOC_ZVAL(r30);
	PHALCON_CALL_METHOD(r30, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	if (v18) {
		Z_DELREF_P(v18);
		if (!Z_REFCOUNT_P(v18)) {
			FREE_ZVAL(v18);
		}
	}
	Z_ADDREF_P(r30);
	v18 = r30;
	PHALCON_ALLOC_ZVAL(r31);
	PHALCON_CALL_METHOD(r31, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	if (v4) {
		Z_DELREF_P(v4);
		if (!Z_REFCOUNT_P(v4)) {
			FREE_ZVAL(v4);
		}
	}
	Z_ADDREF_P(r31);
	v4 = r31;
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		if (v19) {
			Z_DELREF_P(v19);
			if (!Z_REFCOUNT_P(v19)) {
				FREE_ZVAL(v19);
			}
		}
		Z_ADDREF_P(a1);
		v19 = a1;
		PHALCON_ALLOC_ZVAL(a2);
		array_init(a2);
		if (v20) {
			Z_DELREF_P(v20);
			if (!Z_REFCOUNT_P(v20)) {
				FREE_ZVAL(v20);
			}
		}
		Z_ADDREF_P(a2);
		v20 = a2;
		PHALCON_ALLOC_ZVAL(r32);
		PHALCON_CALL_METHOD(r32, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
		if (v21) {
			Z_DELREF_P(v21);
			if (!Z_REFCOUNT_P(v21)) {
				FREE_ZVAL(v21);
			}
		}
		Z_ADDREF_P(r32);
		v21 = r32;
		FOREACH_V(v21, ac0, fes71, fee71, ah0, hp0, v9)
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v19;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v19);
						*v19 = *orig_ptr;
						zval_copy_ctor(v19);
						Z_SET_REFCOUNT_P(v19, 1);
						Z_UNSET_ISREF_P(v19);
					}
				}
				phalcon_array_append(v19, copy TSRMLS_CC);
			}
			if (!t10) {
				PHALCON_ALLOC_ZVAL(t10);
			} else {
				if (Z_REFCOUNT_P(t10) > 1) {
					{
						zval *orig_ptr = t10;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t10);
							*t10 = *orig_ptr;
							zval_copy_ctor(t10);
							Z_SET_REFCOUNT_P(t10, 1);
							Z_UNSET_ISREF_P(t10);
						}
					}
				} else {
					FREE_ZVAL(t10);
					PHALCON_ALLOC_ZVAL(t10);
				}
			}
			phalcon_read_property_zval(t10, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t10);
			if (v10) {
				Z_DELREF_P(v10);
				if (!Z_REFCOUNT_P(v10)) {
					FREE_ZVAL(v10);
				}
			}
			Z_ADDREF_P(t10);
			v10 = t10;
			if (Z_TYPE_P(v10) == IS_OBJECT) {
				if (!r33) {
					PHALCON_ALLOC_ZVAL(r33);
				} else {
					if (Z_REFCOUNT_P(r33) > 1){ 
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
					}
				}
				phalcon_instance_of(r33, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r33)) {
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
					PHALCON_CALL_METHOD(r34, v10, "getvalue", PHALCON_CALL_DEFAULT);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r34, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				} else {
					if (!t11) {
						PHALCON_ALLOC_ZVAL(t11);
					} else {
						if (Z_REFCOUNT_P(t11) > 1) {
							{
								zval *orig_ptr = t11;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(t11);
									*t11 = *orig_ptr;
									zval_copy_ctor(t11);
									Z_SET_REFCOUNT_P(t11, 1);
									Z_UNSET_ISREF_P(t11);
								}
							}
						} else {
							FREE_ZVAL(t11);
							PHALCON_ALLOC_ZVAL(t11);
						}
					}
					phalcon_read_property_zval(t11, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
					zval_copy_ctor(t11);
					convert_to_string(t11);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t11, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				}
			} else {
				if (!t12) {
					PHALCON_ALLOC_ZVAL(t12);
				} else {
					if (Z_REFCOUNT_P(t12) > 1) {
						SEPARATE_ZVAL(&t12);
					} else {
						if (Z_TYPE_P(t12) != IS_STRING) {
							FREE_ZVAL(t12);
							PHALCON_ALLOC_ZVAL(t12);
						}
					}
				}
				ZVAL_STRING(t12, "", 1);
				PHALCON_IDENTICAL_FUNCTION(r35, v10, t12);
				PHALCON_INIT_NULL(t13);
				PHALCON_IDENTICAL_FUNCTION(r36, v10, t13);
				PHALCON_OR_FUNCTION(r37, r35, r36);
				if (zend_is_true(r37)) {
					if (!t14) {
						PHALCON_ALLOC_ZVAL(t14);
					} else {
						if (Z_REFCOUNT_P(t14) > 1) {
							SEPARATE_ZVAL(&t14);
						} else {
							if (Z_TYPE_P(t14) != IS_STRING) {
								FREE_ZVAL(t14);
								PHALCON_ALLOC_ZVAL(t14);
							}
						}
					}
					ZVAL_STRING(t14, "NULL", 1);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						{
							zval *orig_ptr = v20;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(v20);
								*v20 = *orig_ptr;
								zval_copy_ctor(v20);
								Z_SET_REFCOUNT_P(v20, 1);
								Z_UNSET_ISREF_P(v20);
							}
						}
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				} else {
					eval_int = phalcon_array_isset(v4, v9);
					if (eval_int) {
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, v10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
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
						phalcon_array_fetch(r38, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (phalcon_compare_strict_string(r38, "date")) {
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
							Z_ADDREF_P(v10);
							p38[0] = v10;
							PHALCON_CALL_METHOD_PARAMS(r39, v16, "getdateusingformat", 1, p38, PHALCON_CALL_DEFAULT);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r39, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
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
							phalcon_concat_both(r40,  "'", v10, "'" TSRMLS_CC);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r40, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						}
					}
				}
			}
		END_FOREACH(ac0, fes71, fee71, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r41);
		Z_ADDREF_P(v15);
		p39[0] = v15;
		Z_ADDREF_P(v19);
		p39[1] = v19;
		Z_ADDREF_P(v20);
		p39[2] = v20;
		PHALCON_ALLOC_ZVAL(t15);
		phalcon_read_property(t15, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t15);
		Z_ADDREF_P(t15);
		p39[3] = t15;
		PHALCON_CALL_METHOD_PARAMS(r41, v16, "update", 4, p39, PHALCON_CALL_DEFAULT);
		if (v22) {
			Z_DELREF_P(v22);
			if (!Z_REFCOUNT_P(v22)) {
				FREE_ZVAL(v22);
			}
		}
		Z_ADDREF_P(r41);
		v22 = r41;
	} else {
		PHALCON_ALLOC_ZVAL(a3);
		array_init(a3);
		if (v19) {
			Z_DELREF_P(v19);
			if (!Z_REFCOUNT_P(v19)) {
				FREE_ZVAL(v19);
			}
		}
		Z_ADDREF_P(a3);
		v19 = a3;
		PHALCON_ALLOC_ZVAL(a4);
		array_init(a4);
		if (v20) {
			Z_DELREF_P(v20);
			if (!Z_REFCOUNT_P(v20)) {
				FREE_ZVAL(v20);
			}
		}
		Z_ADDREF_P(a4);
		v20 = a4;
		PHALCON_ALLOC_ZVAL(r42);
		PHALCON_CALL_METHOD(r42, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		if (v23) {
			Z_DELREF_P(v23);
			if (!Z_REFCOUNT_P(v23)) {
				FREE_ZVAL(v23);
			}
		}
		Z_ADDREF_P(r42);
		v23 = r42;
		FOREACH_V(v23, ac1, fes72, fee72, ah1, hp1, v9)
			if (!phalcon_compare_strict_string(v9, "id")) {
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v9, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					{
						zval *orig_ptr = v19;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(v19);
							*v19 = *orig_ptr;
							zval_copy_ctor(v19);
							Z_SET_REFCOUNT_P(v19, 1);
							Z_UNSET_ISREF_P(v19);
						}
					}
					phalcon_array_append(v19, copy TSRMLS_CC);
				}
				if (!t16) {
					PHALCON_ALLOC_ZVAL(t16);
				} else {
					if (Z_REFCOUNT_P(t16) > 1) {
						{
							zval *orig_ptr = t16;
							if (Z_REFCOUNT_P(orig_ptr) > 1) {
								Z_DELREF_P(orig_ptr);
								ALLOC_ZVAL(t16);
								*t16 = *orig_ptr;
								zval_copy_ctor(t16);
								Z_SET_REFCOUNT_P(t16, 1);
								Z_UNSET_ISREF_P(t16);
							}
						}
					} else {
						FREE_ZVAL(t16);
						PHALCON_ALLOC_ZVAL(t16);
					}
				}
				phalcon_read_property_zval(t16, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
				zval_copy_ctor(t16);
				if (v10) {
					Z_DELREF_P(v10);
					if (!Z_REFCOUNT_P(v10)) {
						FREE_ZVAL(v10);
					}
				}
				Z_ADDREF_P(t16);
				v10 = t16;
				if (Z_TYPE_P(v10) == IS_OBJECT) {
					if (!r43) {
						PHALCON_ALLOC_ZVAL(r43);
					} else {
						if (Z_REFCOUNT_P(r43) > 1){ 
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
						}
					}
					phalcon_instance_of(r43, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
					if (zend_is_true(r43)) {
						if (!r44) {
							PHALCON_ALLOC_ZVAL(r44);
						} else {
							if (Z_REFCOUNT_P(r44) > 1) {
								{
									zval *orig_ptr = r44;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(r44);
										*r44 = *orig_ptr;
										zval_copy_ctor(r44);
										Z_SET_REFCOUNT_P(r44, 1);
										Z_UNSET_ISREF_P(r44);
									}
								}
							} else {
								FREE_ZVAL(r44);
								PHALCON_ALLOC_ZVAL(r44);
							}
						}
						PHALCON_CALL_METHOD(r44, v10, "getvalue", PHALCON_CALL_DEFAULT);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r44, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						convert_to_string(v10);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, v10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					}
				} else {
					if (!t17) {
						PHALCON_ALLOC_ZVAL(t17);
					} else {
						if (Z_REFCOUNT_P(t17) > 1) {
							SEPARATE_ZVAL(&t17);
						} else {
							if (Z_TYPE_P(t17) != IS_STRING) {
								FREE_ZVAL(t17);
								PHALCON_ALLOC_ZVAL(t17);
							}
						}
					}
					ZVAL_STRING(t17, "", 1);
					PHALCON_IDENTICAL_FUNCTION(r45, v10, t17);
					PHALCON_INIT_NULL(t18);
					PHALCON_IDENTICAL_FUNCTION(r46, v10, t18);
					PHALCON_OR_FUNCTION(r47, r45, r46);
					if (zend_is_true(r47)) {
						if (!t19) {
							PHALCON_ALLOC_ZVAL(t19);
						} else {
							if (Z_REFCOUNT_P(t19) > 1) {
								SEPARATE_ZVAL(&t19);
							} else {
								if (Z_TYPE_P(t19) != IS_STRING) {
									FREE_ZVAL(t19);
									PHALCON_ALLOC_ZVAL(t19);
								}
							}
						}
						ZVAL_STRING(t19, "NULL", 1);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, t19, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							{
								zval *orig_ptr = v20;
								if (Z_REFCOUNT_P(orig_ptr) > 1) {
									Z_DELREF_P(orig_ptr);
									ALLOC_ZVAL(v20);
									*v20 = *orig_ptr;
									zval_copy_ctor(v20);
									Z_SET_REFCOUNT_P(v20, 1);
									Z_UNSET_ISREF_P(v20);
								}
							}
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						eval_int = phalcon_array_isset(v4, v9);
						if (eval_int) {
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, v10, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								{
									zval *orig_ptr = v20;
									if (Z_REFCOUNT_P(orig_ptr) > 1) {
										Z_DELREF_P(orig_ptr);
										ALLOC_ZVAL(v20);
										*v20 = *orig_ptr;
										zval_copy_ctor(v20);
										Z_SET_REFCOUNT_P(v20, 1);
										Z_UNSET_ISREF_P(v20);
									}
								}
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
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
							phalcon_array_fetch(r48, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
							if (phalcon_compare_strict_string(r48, "date")) {
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
								if (!t20) {
									PHALCON_ALLOC_ZVAL(t20);
								} else {
									if (Z_REFCOUNT_P(t20) > 1) {
										{
											zval *orig_ptr = t20;
											if (Z_REFCOUNT_P(orig_ptr) > 1) {
												Z_DELREF_P(orig_ptr);
												ALLOC_ZVAL(t20);
												*t20 = *orig_ptr;
												zval_copy_ctor(t20);
												Z_SET_REFCOUNT_P(t20, 1);
												Z_UNSET_ISREF_P(t20);
											}
										}
									} else {
										FREE_ZVAL(t20);
										PHALCON_ALLOC_ZVAL(t20);
									}
								}
								phalcon_read_property(t20, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
								zval_copy_ctor(t20);
								Z_ADDREF_P(v10);
								p42[0] = v10;
								PHALCON_CALL_METHOD_PARAMS(r49, t20, "getdateusingformat", 1, p42, PHALCON_CALL_DEFAULT);
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r49, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									{
										zval *orig_ptr = v20;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(v20);
											*v20 = *orig_ptr;
											zval_copy_ctor(v20);
											Z_SET_REFCOUNT_P(v20, 1);
											Z_UNSET_ISREF_P(v20);
										}
									}
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							} else {
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
								phalcon_concat_both(r50,  "'", v10, "'" TSRMLS_CC);
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r50, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									{
										zval *orig_ptr = v20;
										if (Z_REFCOUNT_P(orig_ptr) > 1) {
											Z_DELREF_P(orig_ptr);
											ALLOC_ZVAL(v20);
											*v20 = *orig_ptr;
											zval_copy_ctor(v20);
											Z_SET_REFCOUNT_P(v20, 1);
											Z_UNSET_ISREF_P(v20);
										}
									}
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							}
						}
					}
				}
			}
		END_FOREACH(ac1, fes72, fee72, ah1, hp1);
		PHALCON_ALLOC_ZVAL(v24);
		ZVAL_STRING(v24, "", 0);
		eval_int = phalcon_isset_property(this_ptr, "id", strlen("id") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r51);
			PHALCON_ALLOC_ZVAL(t21);
			phalcon_read_property(t21, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t21);
			Z_ADDREF_P(t21);
			p43[0] = t21;
			PHALCON_CALL_FUNC_PARAMS(r51, "is_null", 1, p43);
			PHALCON_ALLOC_ZVAL(t22);
			phalcon_read_property(t22, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t22);
			PHALCON_ALLOC_ZVAL(t23);
			ZVAL_STRING(t23, "", 1);
			PHALCON_IDENTICAL_FUNCTION(r52, t22, t23);
			PHALCON_OR_FUNCTION(r53, r51, r52);
			if (zend_is_true(r53)) {
				phalcon_update_property_string(this_ptr, "id", strlen("id"), "null" TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(t24);
			ZVAL_STRING(t24, "id", 1);
			{
				zval *orig_ptr = v19;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v19);
					*v19 = *orig_ptr;
					zval_copy_ctor(v19);
					Z_SET_REFCOUNT_P(v19, 1);
					Z_UNSET_ISREF_P(v19);
				}
			}
			phalcon_array_append(v19, t24 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t25);
			phalcon_read_property(t25, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t25);
			{
				zval *orig_ptr = v20;
				if (Z_REFCOUNT_P(orig_ptr) > 1) {
					Z_DELREF_P(orig_ptr);
					ALLOC_ZVAL(v20);
					*v20 = *orig_ptr;
					zval_copy_ctor(v20);
					Z_SET_REFCOUNT_P(v20, 1);
					Z_UNSET_ISREF_P(v20);
				}
			}
			phalcon_array_append(v20, t25 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(r54);
		PHALCON_ALLOC_ZVAL(t26);
		phalcon_read_property(t26, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t26);
		Z_ADDREF_P(v15);
		p44[0] = v15;
		Z_ADDREF_P(v20);
		p44[1] = v20;
		Z_ADDREF_P(v19);
		p44[2] = v19;
		PHALCON_CALL_METHOD_PARAMS(r54, t26, "insert", 3, p44, PHALCON_CALL_DEFAULT);
		if (v22) {
			Z_DELREF_P(v22);
			if (!Z_REFCOUNT_P(v22)) {
				FREE_ZVAL(v22);
			}
		}
		Z_ADDREF_P(r54);
		v22 = r54;
	}
	PHALCON_ALLOC_ZVAL(r55);
	PHALCON_CALL_METHOD(r55, v16, "isundertransaction", PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r55)) {
		PHALCON_ALLOC_ZVAL(r56);
		PHALCON_CALL_METHOD(r56, v16, "gethaveautocommit", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r56)) {
			PHALCON_CALL_METHOD_NORETURN(v16, "commit", PHALCON_CALL_DEFAULT);
		}
	}
	if (zend_is_true(v22)) {
		if (zend_is_true(v0)) {
			if (!zend_is_true(v1)) {
				PHALCON_ALLOC_ZVAL(p48[0]);
				ZVAL_STRING(p48[0], "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p48, PHALCON_CALL_DEFAULT);
			}
		} else {
			if (!zend_is_true(v1)) {
				PHALCON_ALLOC_ZVAL(p49[0]);
				ZVAL_STRING(p49[0], "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p49, PHALCON_CALL_DEFAULT);
			}
		}
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(p50[0]);
			ZVAL_STRING(p50[0], "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p50, PHALCON_CALL_DEFAULT);
		}
		if (Z_TYPE_P(v22) > IS_BOOL) {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v22);
				zval_copy_ctor(return_value);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		} else {
			{
				zend_uchar is_ref = Z_ISREF_P(return_value);
				zend_uint refcount = Z_REFCOUNT_P(return_value);
				*(return_value) = *(v22);
				Z_SET_ISREF_TO_P(return_value, is_ref);
		 		Z_SET_REFCOUNT_P(return_value, refcount);
			}
		}
		return;
	} else {
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL(p51[0]);
			ZVAL_STRING(p51[0], "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p51, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		RETURN_FALSE;
	}
	RETURN_NULL();
}

/**
 * Deletes a model instance. Returns true on success or else false .
 *
 * 
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, delete){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL;
	zval *ac0 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t1);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t2);
		PHALCON_ALLOC_ZVAL(r0);
		phalcon_concat_vboth(r0, t1, ".", t2 TSRMLS_CC);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(r0);
		v0 = r0;
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t3);
		if (v0) {
			if (!Z_REFCOUNT_P(v0)) {
				FREE_ZVAL(v0);
			}
		}
		Z_ADDREF_P(t3);
		v0 = t3;
	}
	PHALCON_GET_CLASS_CONSTANT(t4, phalcon_model_base_class_entry, "OP_DELETE");
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, t4, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), copy TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	if (v1) {
		Z_DELREF_P(v1);
		if (!Z_REFCOUNT_P(v1)) {
			FREE_ZVAL(v1);
		}
	}
	Z_ADDREF_P(r1);
	v1 = r1;
	PHALCON_ALLOC_ZVAL(r2);
	p2[0] = v1;
	PHALCON_CALL_FUNC_PARAMS(r2, "count", 1, p2);
	PHALCON_ALLOC_ZVAL(t5);
	ZVAL_LONG(t5, 1);
	PHALCON_EQUAL_FUNCTION(r3, r2, t5);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL(t6);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_long(r4, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_read_property_zval(t6, this_ptr, r4, PHALCON_NOISY_FETCH TSRMLS_CC);
		zval_copy_ctor(t6);
		if (v2) {
			Z_DELREF_P(v2);
			if (!Z_REFCOUNT_P(v2)) {
				FREE_ZVAL(v2);
			}
		}
		Z_ADDREF_P(t6);
		v2 = t6;
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_concat_vboth(r5, r6, " = '", v2 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_concat_right(r7, r5, "'" TSRMLS_CC);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r7);
		v3 = r7;
	} else {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(a0);
		v3 = a0;
		FOREACH_V(v1, ac0, fes73, fee73, ah0, hp0, v4)
			if (!t7) {
				PHALCON_ALLOC_ZVAL(t7);
			} else {
				if (Z_REFCOUNT_P(t7) > 1) {
					{
						zval *orig_ptr = t7;
						if (Z_REFCOUNT_P(orig_ptr) > 1) {
							Z_DELREF_P(orig_ptr);
							ALLOC_ZVAL(t7);
							*t7 = *orig_ptr;
							zval_copy_ctor(t7);
							Z_SET_REFCOUNT_P(t7, 1);
							Z_UNSET_ISREF_P(t7);
						}
					}
				} else {
					FREE_ZVAL(t7);
					PHALCON_ALLOC_ZVAL(t7);
				}
			}
			phalcon_read_property_zval(t7, this_ptr, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			zval_copy_ctor(t7);
			if (v2) {
				Z_DELREF_P(v2);
				if (!Z_REFCOUNT_P(v2)) {
					FREE_ZVAL(v2);
				}
			}
			Z_ADDREF_P(t7);
			v2 = t7;
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
			phalcon_concat_vboth(r8, v4, " = '", v2 TSRMLS_CC);
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
			phalcon_concat_right(r9, r8, "'" TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				{
					zval *orig_ptr = v3;
					if (Z_REFCOUNT_P(orig_ptr) > 1) {
						Z_DELREF_P(orig_ptr);
						ALLOC_ZVAL(v3);
						*v3 = *orig_ptr;
						zval_copy_ctor(v3);
						Z_SET_REFCOUNT_P(v3, 1);
						Z_UNSET_ISREF_P(v3);
					}
				}
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes73, fee73, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r10);
		PHALCON_ALLOC_ZVAL(p3[0]);
		ZVAL_STRING(p3[0], " AND ", 1);
		p3[1] = v3;
		PHALCON_CALL_FUNC_PARAMS(r10, "join", 2, p3);
		if (v3) {
			Z_DELREF_P(v3);
			if (!Z_REFCOUNT_P(v3)) {
				FREE_ZVAL(v3);
			}
		}
		Z_ADDREF_P(r10);
		v3 = r10;
	}
	t8 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (v5) {
		Z_DELREF_P(v5);
		if (!Z_REFCOUNT_P(v5)) {
			FREE_ZVAL(v5);
		}
	}
	Z_ADDREF_P(t8);
	v5 = t8;
	if (!zend_is_true(v5)) {
		PHALCON_ALLOC_ZVAL(r11);
		PHALCON_ALLOC_ZVAL(p4[0]);
		ZVAL_STRING(p4[0], "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS(r11, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL(r12);
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t9);
	Z_ADDREF_P(v0);
	p5[0] = v0;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS(r12, t9, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	if (v6) {
		Z_DELREF_P(v6);
		if (!Z_REFCOUNT_P(v6)) {
			FREE_ZVAL(v6);
		}
	}
	Z_ADDREF_P(r12);
	v6 = r12;
	if (zend_is_true(v6)) {
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
		}
	}
	if (Z_TYPE_P(v6) > IS_BOOL) {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			zval_copy_ctor(return_value);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	} else {
		{
			zend_uchar is_ref = Z_ISREF_P(return_value);
			zend_uint refcount = Z_REFCOUNT_P(return_value);
			*(return_value) = *(v6);
			Z_SET_ISREF_TO_P(return_value, is_ref);
	 		Z_SET_REFCOUNT_P(return_value, refcount);
		}
	}
	return;
}

/**
 * Reads an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Base, readAttribute){

	zval *v0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dump", sizeof("_dump")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property_zval(t1, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t1);
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
 * Writes an attribute value by its name
 *
 * 
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Model_Base, writeAttribute){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	zval_copy_ctor(t0);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v1, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), copy TSRMLS_CC);
	}
	RETURN_NULL();
}

