
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
 * Phalcon_Model_Base
 *
 * Phalcon_Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object- relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.
 *
 * Phalcon_Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interact with databases while is also easy to use.
 *
 * 
 *
 */

/**
 * Phalcon_Model_Base constructor
 *
 * @param Phalcon_Model_Manager $manager
 *
 */
PHP_METHOD(Phalcon_Model_Base, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_NULL(v0);
	}
	
	if (!zend_is_true(v0)) {
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t0)) {
			PHALCON_ALLOC_ZVAL(r0);
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
			PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
			zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, r0 TSRMLS_CC);
		}
	} else {
		zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "get_class", this_ptr, 0x03E);
	PHALCON_CPY_WRT(v1, r2);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property(t1, this_ptr, "_initialized", sizeof("_initialized")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		if (phalcon_method_exists_ex(this_ptr, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
		}
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_initialized", strlen("_initialized"), 1 TSRMLS_CC);
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
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_connection", r0);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	RETURN_ZVAL(r0, 1, 0);
}

/**
 * Dumps mapped table meta-data
 *
 * @return Phalcon_Model_Base
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
	if (zend_is_true(t0)) {
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_ALLOC_ZVAL(r1);
	t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	FOREACH_V(v0, ac0, fes68, fee68, ah0, hp0, v1)
		eval_int = phalcon_isset_property_zval(this_ptr, v1 TSRMLS_CC);
		if (!eval_int) {
			PHALCON_INIT_VARTYPE(t2, IS_STRING);
			ZVAL_STRING(t2, "", 1);
			PHALCON_UPDATE_PROPERTY_CPY(this_ptr, Z_STRVAL_P(v1), t2);
		}
	END_FOREACH(ac0, fes68, fee68, ah0, hp0);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 0 TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(this_ptr);
}

/**
 * Creates SQL statement which returns many rows
 *
 * @param Phalcon_Manager $manager
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectMulti){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL;
	zval *c0 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL }, *p7[] = { NULL }, *p8[] = { NULL }, *p9[] = { NULL }, *p10[] = { NULL, NULL }, *p11[] = { NULL }, *p12[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, v0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, v1, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v5, r1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v1, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r2);
	PHALCON_ALLOC_ZVAL(v7);
	ZVAL_STRING(v7, "SELECT ", 0);
	eval_int = phalcon_array_isset_string(v3, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_array_fetch_string(r3, v3, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r4);
		concat_function(r4, v7, r3 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r4);
	} else {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_ALLOC_ZVAL(c0);
		ZVAL_STRING(c0, ", ", 1);
		PHALCON_ALLOC_ZVAL(r6);
		Z_ADDREF_P(v1);
		p4[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r6, v4, "getattributes", 1, p4, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_FUNC_PARAMS_2(r5, "join", c0, r6, 0x00B);
		FREE_ZVAL(c0);
		PHALCON_ALLOC_ZVAL(r7);
		concat_function(r7, v7, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r7);
	}
	if (zend_is_true(v6)) {
		PHALCON_ALLOC_ZVAL(r9);
		PHALCON_CONCAT_LEFT(r9, " FROM ", v6);
		PHALCON_ALLOC_ZVAL(r8);
		PHALCON_CONCAT_VBOTH(r8, r9, ".", v5);
		PHALCON_ALLOC_ZVAL(r10);
		concat_function(r10, v7, r8 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r10);
	} else {
		PHALCON_ALLOC_ZVAL(r11);
		PHALCON_CONCAT_LEFT(r11, " FROM ", v5);
		PHALCON_ALLOC_ZVAL(r12);
		concat_function(r12, v7, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r12);
	}
	PHALCON_ALLOC_ZVAL(v8);
	ZVAL_STRING(v8, "n", 0);
	eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r13);
		phalcon_array_fetch_string(r13, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_CONCAT_BOTH(r14,  " WHERE ", r13, " ");
		PHALCON_ALLOC_ZVAL(r15);
		concat_function(r15, v7, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r15);
	} else {
		PHALCON_ALLOC_ZVAL(r16);
		Z_ADDREF_P(v1);
		p5[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r16, v4, "getprimarykeyattributes", 1, p5, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v9, r16);
		eval_int = phalcon_array_isset_long(v3, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r17);
			PHALCON_ALLOC_ZVAL(r18);
			phalcon_array_fetch_long(r18, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r18);
			PHALCON_CALL_FUNC_PARAMS_1(r17, "is_numeric", r18, 0x029);
			if (zend_is_true(r17)) {
				eval_int = phalcon_array_isset_long(v9, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL(r20);
					phalcon_array_fetch_long(r20, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r21);
					PHALCON_ALLOC_ZVAL(r22);
					phalcon_array_fetch_long(r22, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r22);
					p7[0] = r22;
					PHALCON_CALL_METHOD_PARAMS(r21, v2, "addquotes", 1, p7, PHALCON_CALL_DEFAULT);
					PHALCON_ALLOC_ZVAL(r19);
					PHALCON_CONCAT_VBOTH(r19, r20, " = ", r21);
					PHALCON_SEPARATE_PARAM(v3);
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r19 TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(v8);
					ZVAL_STRING(v8, "1", 0);
				} else {
					PHALCON_ALLOC_ZVAL(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_ALLOC_ZVAL(p8[0]);
					ZVAL_STRING(p8[0], "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p8, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL(r23);
				phalcon_array_fetch_long(r23, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_ALLOC_ZVAL(r24);
				is_identical_function(r24, t0, r23 TSRMLS_CC);
				if (zend_is_true(r24)) {
					eval_int = phalcon_array_isset_long(v9, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL(r25);
						phalcon_array_fetch_long(r25, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r26);
						PHALCON_CONCAT_RIGHT(r26, r25, " = ''");
						PHALCON_SEPARATE_PARAM(v3);
						phalcon_array_update_string(v3, "conditions", strlen("conditions"), r26 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL(i1);
						object_init_ex(i1, phalcon_model_exception_class_entry);
						PHALCON_ALLOC_ZVAL(p9[0]);
						ZVAL_STRING(p9[0], "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p9, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL(r27);
					phalcon_array_fetch_long(r27, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_SEPARATE_PARAM(v3);
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r27 TSRMLS_CC);
				}
				PHALCON_ALLOC_ZVAL(v8);
				ZVAL_STRING(v8, "n", 0);
			}
		}
		eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r28);
			phalcon_array_fetch_string(r28, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r29);
			PHALCON_CONCAT_LEFT(r29, " WHERE ", r28);
			PHALCON_ALLOC_ZVAL(r30);
			concat_function(r30, v7, r29 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r30);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r31);
		phalcon_array_fetch_string(r31, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r31)) {
			PHALCON_ALLOC_ZVAL(r32);
			phalcon_array_fetch_string(r32, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r33);
			PHALCON_CONCAT_LEFT(r33, " GROUP BY ", r32);
			PHALCON_ALLOC_ZVAL(r34);
			concat_function(r34, v7, r33 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r34);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r35);
		phalcon_array_fetch_string(r35, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r35)) {
			PHALCON_ALLOC_ZVAL(r36);
			phalcon_array_fetch_string(r36, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r37);
			PHALCON_CONCAT_LEFT(r37, " ORDER BY ", r36);
			PHALCON_ALLOC_ZVAL(r38);
			concat_function(r38, v7, r37 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r38);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r39);
		phalcon_array_fetch_string(r39, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r39)) {
			PHALCON_ALLOC_ZVAL(r40);
			Z_ADDREF_P(v7);
			p10[0] = v7;
			PHALCON_ALLOC_ZVAL(r41);
			phalcon_array_fetch_string(r41, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r41);
			p10[1] = r41;
			PHALCON_CALL_METHOD_PARAMS(r40, v2, "limit", 2, p10, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v7, r40);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r42);
		phalcon_array_fetch_string(r42, v3, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r42)) {
			PHALCON_ALLOC_ZVAL(r43);
			Z_ADDREF_P(v7);
			p11[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r43, v2, "forupdate", 1, p11, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v7, r43);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r44);
		phalcon_array_fetch_string(r44, v3, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r44)) {
			PHALCON_ALLOC_ZVAL(r45);
			Z_ADDREF_P(v7);
			p12[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r45, v2, "sharedlock", 1, p12, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v7, r45);
		}
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v8, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		PHALCON_SEPARATE(a0);
		add_assoc_zval(a0, "return", copy);
	}
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v7, 1, 0);
		Z_SET_REFCOUNT_P(copy, 0);
		Z_UNSET_ISREF_P(copy);
		PHALCON_SEPARATE(a0);
		add_assoc_zval(a0, "sql", copy);
	}
	PHALCON_RETURN_CTOR(a0);
}

/**
 * Creates SQL statement which returns many rows
 *
 * @param Phalcon_Manager $manager
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _createSQLSelectOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL;
	zval *t0 = NULL;
	zval *p0[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		RETURN_NULL();
	}

	if (!v4) {
		PHALCON_ALLOC_ZVAL(v4);
		ZVAL_STRING(v4, "", 0);
	}
	
	if (Z_TYPE_P(v4) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r0);
			phalcon_array_fetch_string(r0, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL(r1);
				phalcon_array_fetch_string(r1, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r2);
				PHALCON_CONCAT_BOTH(r2,  " WHERE ", r1, " ");
				PHALCON_ALLOC_ZVAL(r3);
				concat_function(r3, v3, r2 TSRMLS_CC);
				PHALCON_CPY_WRT_PARAM(v3, r3);
			}
		} else {
			PHALCON_ALLOC_ZVAL(r4);
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_CALL_METHOD(r5, v0, "getmetadata", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r4, r5, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v5, r4);
			eval_int = phalcon_array_isset_long(v4, 0);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(r6);
				PHALCON_ALLOC_ZVAL(r7);
				phalcon_array_fetch_long(r7, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r7);
				PHALCON_CALL_FUNC_PARAMS_1(r6, "is_numeric", r7, 0x029);
				if (zend_is_true(r6)) {
					PHALCON_ALLOC_ZVAL(r9);
					phalcon_array_fetch_long(r9, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r10);
					phalcon_array_fetch_long(r10, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, " = '", r10);
					PHALCON_ALLOC_ZVAL(r11);
					PHALCON_CONCAT_RIGHT(r11, r8, "'");
					PHALCON_SEPARATE_PARAM(v4);
					phalcon_array_update_string(v4, "conditions", strlen("conditions"), r11 TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL(r12);
					phalcon_array_fetch_long(r12, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r12, "")) {
						PHALCON_ALLOC_ZVAL(r13);
						phalcon_array_fetch_long(r13, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL(r14);
						PHALCON_CONCAT_RIGHT(r14, r13, " = ''");
						PHALCON_SEPARATE_PARAM(v4);
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r14 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL(r15);
						phalcon_array_fetch_long(r15, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_SEPARATE_PARAM(v4);
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r15 TSRMLS_CC);
					}
				}
			}
			eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL(r16);
				phalcon_array_fetch_string(r16, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r17);
				PHALCON_CONCAT_LEFT(r17, " WHERE ", r16);
				PHALCON_ALLOC_ZVAL(r18);
				concat_function(r18, v3, r17 TSRMLS_CC);
				PHALCON_CPY_WRT_PARAM(v3, r18);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "order", strlen("order")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r19);
			phalcon_array_fetch_string(r19, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL(r20);
				phalcon_array_fetch_string(r20, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r21);
				PHALCON_CONCAT_LEFT(r21, " ORDER BY ", r20);
				PHALCON_ALLOC_ZVAL(r22);
				concat_function(r22, v3, r21 TSRMLS_CC);
				PHALCON_CPY_WRT_PARAM(v3, r22);
			}
		} else {
			PHALCON_ALLOC_ZVAL(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_ALLOC_ZVAL(r23);
			concat_function(r23, v3, t0 TSRMLS_CC);
			PHALCON_CPY_WRT_PARAM(v3, r23);
		}
		eval_int = phalcon_array_isset_string(v4, "limit", strlen("limit")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r24);
			phalcon_array_fetch_string(r24, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r24)) {
				PHALCON_ALLOC_ZVAL(r25);
				Z_ADDREF_P(v3);
				p3[0] = v3;
				PHALCON_ALLOC_ZVAL(r26);
				phalcon_array_fetch_string(r26, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r26);
				p3[1] = r26;
				PHALCON_CALL_METHOD_PARAMS(r25, v2, "limit", 2, p3, PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT_PARAM(v3, r25);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "for_update", strlen("for_update")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r27);
			phalcon_array_fetch_string(r27, v4, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r27)) {
				PHALCON_ALLOC_ZVAL(r28);
				Z_ADDREF_P(v3);
				p4[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r28, v2, "forupdate", 1, p4, PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT_PARAM(v3, r28);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r29);
			phalcon_array_fetch_string(r29, v4, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r29)) {
				PHALCON_ALLOC_ZVAL(r30);
				Z_ADDREF_P(v3);
				p5[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r30, v2, "sharedlock", 1, p5, PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT_PARAM(v3, r30);
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL(r31);
		PHALCON_CALL_FUNC_PARAMS_1(r31, "strlen", v4, 0x01E);
		if (!phalcon_is_smaller_strict_long(r31, 0)) {
			PHALCON_ALLOC_ZVAL(r32);
			Z_ADDREF_P(v4);
			PHALCON_CALL_FUNC_PARAMS_1(r32, "is_numeric", v4, 0x029);
			if (zend_is_true(r32)) {
				PHALCON_ALLOC_ZVAL(r34);
				phalcon_array_fetch_long(r34, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL(r35);
				PHALCON_CONCAT_LEFT(r35, "WHERE ", r34);
				PHALCON_ALLOC_ZVAL(r33);
				PHALCON_CONCAT_VBOTH(r33, r35, " = '", v4);
				PHALCON_ALLOC_ZVAL(r36);
				PHALCON_CONCAT_RIGHT(r36, r33, "'");
				PHALCON_ALLOC_ZVAL(r37);
				concat_function(r37, v3, r36 TSRMLS_CC);
				PHALCON_CPY_WRT_PARAM(v3, r37);
			} else {
				PHALCON_ALLOC_ZVAL(r38);
				PHALCON_CONCAT_LEFT(r38, "WHERE ", v4);
				PHALCON_ALLOC_ZVAL(r39);
				concat_function(r39, v3, r38 TSRMLS_CC);
				PHALCON_CPY_WRT_PARAM(v3, r39);
			}
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * Creates a resultset from a SQL statement
 *
 * @param Phalcon_Model_Base $model
 * @param Phalcon_Db $connection
 * @param array $select
 * @param resource $resultResource
 * @return Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Base, _createResultset){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	phalcon_array_fetch_string(r0, v2, "return", strlen("return"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(t0);
	ZVAL_STRING(t0, "1", 1);
	PHALCON_ALLOC_ZVAL(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r2, v1, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_ALLOC_ZVAL(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_ALLOC_ZVAL(r3);
		is_equal_function(r3, r2, t1 TSRMLS_CC);
		if (zend_is_true(r3)) {
			RETURN_FALSE;
		} else {
			PHALCON_ALLOC_ZVAL(t2);
			phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
			Z_ADDREF_P(t2);
			p1[0] = t2;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r4);
			Z_ADDREF_P(v3);
			p2[0] = v3;
			PHALCON_CALL_METHOD_PARAMS(r4, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			PHALCON_CPY_WRT(v4, r4);
			PHALCON_ALLOC_ZVAL(t3);
			phalcon_get_class_constant(t3, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
			Z_ADDREF_P(t3);
			p3[0] = t3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(r5);
			Z_ADDREF_P(v4);
			p4[0] = v4;
			PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "dumpresult", 1, p4);
			RETURN_ZVAL(r5, 1, 0);
		}
	} else {
		PHALCON_ALLOC_ZVAL(r6);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r6, v1, "numrows", 1, p5, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r6);
		if (!phalcon_is_smaller_strict_long(v5, 0)) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p6[0] = v0;
			Z_ADDREF_P(v3);
			p6[1] = v3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p6, PHALCON_CALL_CHECK);
			PHALCON_RETURN_CTOR(i0);
		} else {
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p7[0] = v0;
			PHALCON_ALLOC_ZVAL(p7[1]);
			ZVAL_BOOL(p7[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p7, PHALCON_CALL_CHECK);
			PHALCON_RETURN_CTOR(i1);
		}
	}
	RETURN_NULL();
}

/**
 * Overwrittes default model manager
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	RETURN_NULL();
}

/**
 * Returns internal models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Model_Base, getManager){

	zval *t0 = NULL;

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets a transaction related to the Model instance
 *
 *
 *
 * @param Phalcon_Transaction $transaction
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
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_connection", r0);
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
	PHALCON_RETURN_CHECK_CTOR(this_ptr);
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
	PHALCON_RETURN_CHECK_CTOR(t0);
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

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_source", v0);
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
	zval *p0[] = { NULL };

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x03E);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_source", r0);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
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

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_schema", v0);
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
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_schema", r0);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_read_property(t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Overwrittes internal Phalcon_Db connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Base, setConnection){

	zval *v0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_connection", v0);
	RETURN_NULL();
}

/**
 * Gets internal Phalcon_Db connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *
 *
 * @param array $result
 * @param Phalcon_Model_Base $base
 * @return Phalcon_Model_Base $result
 */
PHP_METHOD(Phalcon_Model_Base, dumpResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL;
	zval *s0 = NULL;
	zval *ac0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_clone(&s0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, s0);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		FOREACH_KV(v1, ac0, fes69, fee69, ah0, hp0, v4, v3)
			PHALCON_UPDATE_PROPERTY_CPY(v2, Z_STRVAL_P(v4), v3);
		END_FOREACH(ac0, fes69, fee69, ah0, hp0);
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return Phalcon_Model_Resulset
 */
PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL, NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL, NULL, NULL };
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			PHALCON_CPY_WRT_PARAM(v0, a1);
		}
	}
	PHALCON_ALLOC_ZVAL(r3);
	Z_ADDREF_P(v3);
	p6[0] = v3;
	Z_ADDREF_P(v2);
	p6[1] = v2;
	Z_ADDREF_P(v4);
	p6[2] = v4;
	Z_ADDREF_P(v0);
	p6[3] = v0;
	PHALCON_CALL_SELF_PARAMS(r3, this_ptr, "_createsqlselectmulti", 4, p6);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_ALLOC_ZVAL(r5);
	phalcon_array_fetch_string(r5, v5, "sql", strlen("sql"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r5);
	p7[0] = r5;
	PHALCON_CALL_METHOD_PARAMS(r4, v4, "query", 1, p7, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r4);
	PHALCON_ALLOC_ZVAL(r6);
	Z_ADDREF_P(v2);
	p8[0] = v2;
	Z_ADDREF_P(v4);
	p8[1] = v4;
	Z_ADDREF_P(v5);
	p8[2] = v5;
	Z_ADDREF_P(v6);
	p8[3] = v6;
	PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_createresultset", 4, p8);
	RETURN_ZVAL(r6, 1, 0);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL, NULL, NULL, NULL, NULL }, *p12[] = { NULL }, *p13[] = { NULL }, *p14[] = { NULL, NULL }, *p15[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			PHALCON_CPY_WRT_PARAM(v0, a1);
		}
	}
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r4);
	PHALCON_ALLOC_ZVAL(v7);
	ZVAL_STRING(v7, "SELECT ", 0);
	eval_int = phalcon_array_isset_string(v0, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r5);
		phalcon_array_fetch_string(r5, v0, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r6);
		concat_function(r6, v7, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r6);
	} else {
		PHALCON_ALLOC_ZVAL(r7);
		PHALCON_ALLOC_ZVAL(c0);
		ZVAL_STRING(c0, ", ", 1);
		PHALCON_ALLOC_ZVAL(r8);
		PHALCON_ALLOC_ZVAL(r9);
		PHALCON_CALL_METHOD(r9, v3, "getmetadata", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(v2);
		p9[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r8, r9, "getattributes", 1, p9, PHALCON_CALL_DEFAULT);
		PHALCON_CALL_FUNC_PARAMS_2(r7, "join", c0, r8, 0x00B);
		FREE_ZVAL(c0);
		PHALCON_ALLOC_ZVAL(r10);
		concat_function(r10, v7, r7 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r10);
	}
	if (!PHALCON_COMPARE_STRING(v5, "")) {
		PHALCON_ALLOC_ZVAL(r12);
		PHALCON_CONCAT_LEFT(r12, " FROM ", v5);
		PHALCON_ALLOC_ZVAL(r11);
		PHALCON_CONCAT_VBOTH(r11, r12, ".", v6);
		PHALCON_ALLOC_ZVAL(r13);
		concat_function(r13, v7, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r13);
	} else {
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_CONCAT_LEFT(r14, " FROM ", v6);
		PHALCON_ALLOC_ZVAL(r15);
		concat_function(r15, v7, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r15);
	}
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL(t0);
		ZVAL_LONG(t0, 1);
		PHALCON_SEPARATE_PARAM(v0);
		phalcon_array_update_string(v0, "limit", strlen("limit"), t0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL(v8);
	ZVAL_BOOL(v8, 0);
	PHALCON_ALLOC_ZVAL(r16);
	Z_ADDREF_P(v3);
	p11[0] = v3;
	Z_ADDREF_P(v2);
	p11[1] = v2;
	Z_ADDREF_P(v4);
	p11[2] = v4;
	Z_ADDREF_P(v7);
	p11[3] = v7;
	Z_ADDREF_P(v0);
	p11[4] = v0;
	PHALCON_CALL_SELF_PARAMS(r16, this_ptr, "_createsqlselectone", 5, p11);
	PHALCON_CPY_WRT(v7, r16);
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_get_class_constant(t1, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p12[0] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p12, PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r17);
	Z_ADDREF_P(v7);
	p13[0] = v7;
	PHALCON_CALL_METHOD_PARAMS(r17, v4, "fetchone", 1, p13, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v9, r17);
	if (zend_is_true(v9)) {
		PHALCON_ALLOC_ZVAL(r18);
		Z_ADDREF_P(v2);
		p14[0] = v2;
		Z_ADDREF_P(v9);
		p14[1] = v9;
		PHALCON_CALL_SELF_PARAMS(r18, this_ptr, "dumpresult", 2, p14);
		PHALCON_CPY_WRT(v8, r18);
	}
	PHALCON_ALLOC_ZVAL(t2);
	phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
	Z_ADDREF_P(t2);
	p15[0] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p15, PHALCON_CALL_DEFAULT);
	PHALCON_RETURN_CHECK_CTOR(v8);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL, *t11 = NULL, *t12 = NULL, *t13 = NULL;
	zval *t14 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *ac0 = NULL, *ac1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p7[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT_PARAM(v0, r0);
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		if (zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_CONCAT_VBOTH(r2, v0, ".", v1);
			PHALCON_CPY_WRT(v2, r2);
		} else {
			PHALCON_CPY_WRT(v2, v1);
		}
		PHALCON_ALLOC_ZVAL(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) AS rowcount FROM ", v2, " WHERE ");
		PHALCON_CPY_WRT(v3, r3);
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v4, a0);
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r4);
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v6, r5);
		PHALCON_ALLOC_ZVAL(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", v5, 0x008);
		if (!phalcon_is_smaller_strict_long(r6, 0)) {
			FOREACH_V(v5, ac0, fes70, fee70, ah0, hp0, v7)
				PHALCON_INIT_VAR(t1);
				phalcon_read_property_zval(t1, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t2, IS_NULL);
				ZVAL_NULL(t2);
				PHALCON_INIT_VARTYPE(r7, IS_BOOL);
				is_not_identical_function(r7, t2, t1 TSRMLS_CC);
				PHALCON_INIT_VAR(t3);
				phalcon_read_property_zval(t3, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t4, IS_STRING);
				ZVAL_STRING(t4, "", 1);
				PHALCON_INIT_VARTYPE(r8, IS_BOOL);
				is_not_identical_function(r8, t4, t3 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(r9, IS_BOOL);
				phalcon_and_function(r9, r7, r8 TSRMLS_CC);
				if (zend_is_true(r9)) {
					eval_int = phalcon_array_isset(v6, v7);
					if (eval_int) {
						PHALCON_INIT_RESULT(r11);
						PHALCON_CONCAT_LEFT(r11, " ", v7);
						PHALCON_INIT_VAR(t5);
						phalcon_read_property_zval(t5, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r10);
						PHALCON_CONCAT_VBOTH(r10, r11, " = ", t5);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v4);
							phalcon_array_append(v4, copy TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_RESULT(r13);
						PHALCON_CONCAT_LEFT(r13, " ", v7);
						PHALCON_INIT_VAR(t6);
						phalcon_read_property_zval(t6, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r12);
						PHALCON_CONCAT_VBOTH(r12, r13, " = '", t6);
						PHALCON_INIT_RESULT(r14);
						PHALCON_CONCAT_RIGHT(r14, r12, "'");
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r14, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v4);
							phalcon_array_append(v4, copy TSRMLS_CC);
						}
					}
				}
			END_FOREACH(ac0, fes70, fee70, ah0, hp0);
			PHALCON_ALLOC_ZVAL(r15);
			PHALCON_CALL_FUNC_PARAMS_1(r15, "count", v4, 0x008);
			if (zend_is_true(r15)) {
				PHALCON_ALLOC_ZVAL(r16);
				PHALCON_ALLOC_ZVAL(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r16, "join", c0, v4, 0x00B);
				FREE_ZVAL(c0);
				PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_uniqueKey", r16);
			} else {
				RETURN_LONG(0);
			}
			PHALCON_ALLOC_ZVAL(t7);
			phalcon_read_property(t7, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r17);
			concat_function(r17, v3, t7 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r17);
		} else {
			RETURN_LONG(0);
		}
		PHALCON_ALLOC_ZVAL(r18);
		PHALCON_ALLOC_ZVAL(t8);
		phalcon_read_property(t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r18, t8, "fetchone", 1, p7, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v8, r18);
		PHALCON_ALLOC_ZVAL(r19);
		phalcon_array_fetch_string(r19, v8, "rowcount", strlen("rowcount"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r19);
	} else {
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v4, a1);
		PHALCON_ALLOC_ZVAL(r20);
		PHALCON_CALL_METHOD(r20, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r20);
		PHALCON_ALLOC_ZVAL(r21);
		PHALCON_CALL_METHOD(r21, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v9, r21);
		PHALCON_ALLOC_ZVAL(r22);
		PHALCON_CALL_FUNC_PARAMS_1(r22, "count", v5, 0x008);
		if (!phalcon_is_smaller_strict_long(r22, 0)) {
			FOREACH_V(v5, ac1, fes71, fee71, ah1, hp1, v7)
				PHALCON_INIT_VAR(t9);
				phalcon_read_property_zval(t9, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t10, IS_NULL);
				ZVAL_NULL(t10);
				PHALCON_INIT_VARTYPE(r23, IS_BOOL);
				is_not_identical_function(r23, t10, t9 TSRMLS_CC);
				PHALCON_INIT_VAR(t11);
				phalcon_read_property_zval(t11, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t12, IS_STRING);
				ZVAL_STRING(t12, "", 1);
				PHALCON_INIT_VARTYPE(r24, IS_BOOL);
				is_not_identical_function(r24, t12, t11 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(r25, IS_BOOL);
				phalcon_and_function(r25, r23, r24 TSRMLS_CC);
				if (zend_is_true(r25)) {
					eval_int = phalcon_array_isset(v9, v7);
					if (eval_int) {
						PHALCON_INIT_RESULT(r27);
						PHALCON_CONCAT_LEFT(r27, " ", v7);
						PHALCON_INIT_VAR(t13);
						phalcon_read_property_zval(t13, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r26);
						PHALCON_CONCAT_VBOTH(r26, r27, " = ", t13);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r26, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v4);
							phalcon_array_append(v4, copy TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_RESULT(r29);
						PHALCON_CONCAT_LEFT(r29, " ", v7);
						PHALCON_INIT_VAR(t14);
						phalcon_read_property_zval(t14, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_INIT_RESULT(r28);
						PHALCON_CONCAT_VBOTH(r28, r29, " = '", t14);
						PHALCON_INIT_RESULT(r30);
						PHALCON_CONCAT_RIGHT(r30, r28, "'");
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r30, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v4);
							phalcon_array_append(v4, copy TSRMLS_CC);
						}
					}
				}
			END_FOREACH(ac1, fes71, fee71, ah1, hp1);
			PHALCON_ALLOC_ZVAL(r31);
			PHALCON_CALL_FUNC_PARAMS_1(r31, "count", v4, 0x008);
			if (zend_is_true(r31)) {
				PHALCON_ALLOC_ZVAL(r32);
				PHALCON_ALLOC_ZVAL(c1);
				ZVAL_STRING(c1, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r32, "join", c1, v4, 0x00B);
				FREE_ZVAL(c1);
				PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_uniqueKey", r32);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	int eval_int;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(v1, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r0);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r0, v0, "query", 1, p0, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v4, r0);
		PHALCON_ALLOC_ZVAL(r1);
		Z_ADDREF_P(v4);
		p1[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r1, v0, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r1);
		if (!phalcon_is_smaller_strict_long(v5, 0)) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_row_class_entry);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v6, i0);
			Z_ADDREF_P(v0);
			p3[0] = v0;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			PHALCON_ALLOC_ZVAL(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v6);
			p4[0] = v6;
			Z_ADDREF_P(v4);
			p4[1] = v4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			PHALCON_RETURN_CTOR(i1);
		} else {
			PHALCON_ALLOC_ZVAL(i2);
			object_init_ex(i2, phalcon_model_resultset_class_entry);
			PHALCON_ALLOC_ZVAL(i3);
			object_init(i3);
			Z_ADDREF_P(i3);
			p5[0] = i3;
			PHALCON_ALLOC_ZVAL(p5[1]);
			ZVAL_BOOL(p5[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			PHALCON_RETURN_CTOR(i2);
		}
	} else {
		PHALCON_ALLOC_ZVAL(r2);
		Z_ADDREF_P(v2);
		p6[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r2, v0, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v7, r2);
		PHALCON_ALLOC_ZVAL(r3);
		phalcon_array_fetch(r3, v7, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r3);
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
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL, NULL }, *p12[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_ALLOC_ZVAL(v0);
		ZVAL_STRING(v0, "", 0);
	}
	
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
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
		} else {
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			PHALCON_CPY_WRT_PARAM(v0, a1);
		}
	}
	PHALCON_ALLOC_ZVAL(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v5, r3);
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r4);
	if (zend_is_true(v5)) {
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_CONCAT_VBOTH(r5, v5, ".", v6);
		PHALCON_CPY_WRT(v7, r5);
	} else {
		PHALCON_CPY_WRT(v7, v6);
	}
	eval_int = phalcon_array_isset_string(v0, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r7);
		phalcon_array_fetch_string(r7, v0, "distinct", strlen("distinct"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r8);
		PHALCON_CONCAT_LEFT(r8, "SELECT COUNT(DISTINCT ", r7);
		PHALCON_ALLOC_ZVAL(r6);
		PHALCON_CONCAT_VBOTH(r6, r8, ") AS rowcount FROM ", v7);
		PHALCON_ALLOC_ZVAL(r9);
		PHALCON_CONCAT_RIGHT(r9, r6, " ");
		PHALCON_CPY_WRT(v8, r9);
	} else {
		eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r11);
			phalcon_array_fetch_string(r11, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r12);
			PHALCON_CONCAT_LEFT(r12, "SELECT ", r11);
			PHALCON_ALLOC_ZVAL(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, ", COUNT(*) AS rowcount FROM ", v7);
			PHALCON_ALLOC_ZVAL(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, " ");
			PHALCON_CPY_WRT(v8, r13);
		} else {
			PHALCON_ALLOC_ZVAL(r14);
			PHALCON_CONCAT_BOTH(r14,  "SELECT COUNT(*) AS rowcount FROM ", v7, " ");
			PHALCON_CPY_WRT(v8, r14);
		}
	}
	eval_int = phalcon_array_isset_string(v0, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r15);
		phalcon_array_fetch_string(r15, v0, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r16);
		PHALCON_CONCAT_BOTH(r16,  " WHERE ", r15, " ");
		PHALCON_ALLOC_ZVAL(r17);
		concat_function(r17, v8, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r17);
	} else {
		eval_int = phalcon_array_isset_long(v0, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r18);
			phalcon_array_fetch_long(r18, v0, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v9, r18);
			PHALCON_ALLOC_ZVAL(r19);
			Z_ADDREF_P(v9);
			PHALCON_CALL_FUNC_PARAMS_1(r19, "is_numeric", v9, 0x029);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL(r20);
				PHALCON_ALLOC_ZVAL(r21);
				PHALCON_CALL_METHOD(r21, v3, "getmetadata", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(v2);
				p9[0] = v2;
				PHALCON_CALL_METHOD_PARAMS(r20, r21, "getprimarykeyattributes", 1, p9, PHALCON_CALL_DEFAULT);
				PHALCON_CPY_WRT(v10, r20);
				eval_int = phalcon_array_isset_long(v10, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL(r23);
					phalcon_array_fetch_long(r23, v10, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL(r24);
					PHALCON_CONCAT_LEFT(r24, " WHERE ", r23);
					PHALCON_ALLOC_ZVAL(r22);
					PHALCON_CONCAT_VBOTH(r22, r24, " = '", v9);
					PHALCON_ALLOC_ZVAL(r25);
					PHALCON_CONCAT_RIGHT(r25, r22, "'");
					PHALCON_ALLOC_ZVAL(r26);
					concat_function(r26, v8, r25 TSRMLS_CC);
					PHALCON_CPY_WRT(v8, r26);
				} else {
					PHALCON_ALLOC_ZVAL(t0);
					ZVAL_STRING(t0, " WHERE 0=1", 1);
					PHALCON_ALLOC_ZVAL(r27);
					concat_function(r27, v8, t0 TSRMLS_CC);
					PHALCON_CPY_WRT(v8, r27);
				}
			} else {
				if (zend_is_true(v9)) {
					PHALCON_ALLOC_ZVAL(r28);
					PHALCON_CONCAT_LEFT(r28, " WHERE ", v9);
					PHALCON_ALLOC_ZVAL(r29);
					concat_function(r29, v8, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v8, r29);
				}
			}
		}
	}
	eval_int = phalcon_array_isset_string(v0, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r30);
		phalcon_array_fetch_string(r30, v0, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r31);
		PHALCON_CONCAT_BOTH(r31,  " GROUP BY ", r30, " ");
		PHALCON_ALLOC_ZVAL(r32);
		concat_function(r32, v8, r31 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r32);
	}
	eval_int = phalcon_array_isset_string(v0, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r33);
		phalcon_array_fetch_string(r33, v0, "having", strlen("having"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r34);
		PHALCON_CONCAT_BOTH(r34,  " HAVING ", r33, " ");
		PHALCON_ALLOC_ZVAL(r35);
		concat_function(r35, v8, r34 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r35);
	}
	eval_int = phalcon_array_isset_string(v0, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r36);
		phalcon_array_fetch_string(r36, v0, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r37);
		PHALCON_CONCAT_BOTH(r37,  " ORDER BY ", r36, " ");
		PHALCON_ALLOC_ZVAL(r38);
		concat_function(r38, v8, r37 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r38);
	}
	eval_int = phalcon_array_isset_string(v0, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL(r39);
		Z_ADDREF_P(v8);
		p11[0] = v8;
		PHALCON_ALLOC_ZVAL(r40);
		phalcon_array_fetch_string(r40, v0, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r40);
		p11[1] = r40;
		PHALCON_CALL_METHOD_PARAMS(r39, v4, "_limit", 2, p11, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v8, r39);
	}
	PHALCON_ALLOC_ZVAL(r41);
	Z_ADDREF_P(v4);
	p12[0] = v4;
	Z_ADDREF_P(v0);
	p12[1] = v0;
	Z_ADDREF_P(v8);
	p12[2] = v8;
	PHALCON_ALLOC_ZVAL(p12[3]);
	ZVAL_STRING(p12[3], "rowcount", 1);
	PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_getgroupresult", 4, p12);
	RETURN_ZVAL(r41, 1, 0);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL;
	zval *r0 = NULL;

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, v0 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			RETURN_FALSE;
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
	PHALCON_ALLOC_ZVAL(t1);
	ZVAL_BOOL(t1, 0);
	PHALCON_ALLOC_ZVAL(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_get_class_constant(t3, phalcon_model_base_class_entry, "OP_DELETE", strlen("OP_DELETE") TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r1);
		is_equal_function(r1, t2, t3 TSRMLS_CC);
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
		PHALCON_CPY_WRT_PARAM(v0, r3);
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
 * @param Phalcon_Model_Message $message
 */
PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x03E);
		if (!PHALCON_COMPARE_STRING(r0, "Phalcon_Model_Message")) {
			PHALCON_ALLOC_ZVAL(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", v0, 0x03E);
			PHALCON_ALLOC_ZVAL(r2);
			PHALCON_CONCAT_BOTH(r2,  "Invalid message format '", r1, "'");
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
		PHALCON_CALL_FUNC_PARAMS_1(r3, "gettype", v0, 0x040);
		PHALCON_ALLOC_ZVAL(r4);
		PHALCON_CONCAT_BOTH(r4,  "Invalid message format '", r3, "'");
		Z_ADDREF_P(r4);
		p3[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		return;
	}
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	{
		zval *copy;
		ALLOC_ZVAL(copy);
		ZVAL_ZVAL(copy, v0, 1, 0);
		Z_SET_REFCOUNT_P(copy, 1);
		Z_UNSET_ISREF_P(copy);
		phalcon_array_append(t0, copy TSRMLS_CC);
	}
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t0 TSRMLS_CC);
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
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	zval *p2[] = { NULL }, *p4[] = { NULL }, *p6[] = { NULL }, *p12[] = { NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p14[] = { NULL }, *p16[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL }, *p29[] = { NULL }, *p38[] = { NULL }, *p39[] = { NULL, NULL, NULL, NULL }, *p42[] = { NULL }, *p44[] = { NULL, NULL, NULL }, *p48[] = { NULL }, *p49[] = { NULL }, *p50[] = { NULL }, *p51[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT_PARAM(v0, r0);
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL(t0);
		phalcon_get_class_constant(t0, phalcon_model_base_class_entry, "OP_CREATE", strlen("OP_CREATE") TSRMLS_CC);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_operationMade", t0);
	} else {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_get_class_constant(t1, phalcon_model_base_class_entry, "OP_UPDATE", strlen("OP_UPDATE") TSRMLS_CC);
		PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_operationMade", t1);
	}
	PHALCON_ALLOC_ZVAL(a0);
	array_init(a0);
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_errorMessages", a0);
	t2 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
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
	PHALCON_ALLOC_ZVAL(v2);
	ZVAL_NULL(v2);
	PHALCON_ALLOC_ZVAL(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r4);
	PHALCON_ALLOC_ZVAL(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r5);
	if (Z_TYPE_P(v3) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL(v5);
		ZVAL_BOOL(v5, 0);
		PHALCON_ALLOC_ZVAL(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", v3, 0x008);
		PHALCON_CPY_WRT(v6, r6);
		PHALCON_ALLOC_ZVAL(v7);
		ZVAL_LONG(v7, 0);
		fs72:
		PHALCON_ALLOC_ZVAL(r7);
		is_smaller_function(r7, v7, v6 TSRMLS_CC);
		if (!zend_is_true(r7)) {
			goto fe72;
		}
		PHALCON_INIT_VARTYPE(v8, IS_BOOL);
		ZVAL_BOOL(v8, 0);
		PHALCON_INIT_RESULT(r8);
		phalcon_array_fetch(r8, v3, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r8);
		PHALCON_INIT_VAR(t3);
		phalcon_read_property_zval(t3, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, t3);
		eval_int = phalcon_array_isset(v4, v9);
		if (!eval_int) {
			PHALCON_INIT_VARTYPE(t4, IS_NULL);
			ZVAL_NULL(t4);
			PHALCON_INIT_VARTYPE(r9, IS_BOOL);
			is_identical_function(r9, t4, v10 TSRMLS_CC);
			PHALCON_INIT_VARTYPE(t5, IS_STRING);
			ZVAL_STRING(t5, "", 1);
			PHALCON_INIT_VARTYPE(r10, IS_BOOL);
			is_identical_function(r10, t5, v10 TSRMLS_CC);
			PHALCON_INIT_VARTYPE(r11, IS_BOOL);
			ZVAL_BOOL(r11, zend_is_true(r9) || zend_is_true(r10));
			if (zend_is_true(r11)) {
				PHALCON_INIT_VARTYPE(v8, IS_BOOL);
				ZVAL_BOOL(v8, 1);
			}
		} else {
			PHALCON_INIT_RESULT(r12);
			Z_ADDREF_P(v10);
			PHALCON_CALL_FUNC_PARAMS_1(r12, "is_numeric", v10, 0x029);
			if (!zend_is_true(r12)) {
				PHALCON_INIT_VARTYPE(v8, IS_BOOL);
				ZVAL_BOOL(v8, 1);
			}
		}
		PHALCON_INIT_VARTYPE(t6, IS_BOOL);
		ZVAL_BOOL(t6, 1);
		if (!r13) {
			PHALCON_ALLOC_ZVAL(r13);
		} else {
			if (Z_REFCOUNT_P(r13) > 1){ 
				PHALCON_SEPARATE(r13);
			}
		}
		is_equal_function(r13, v8, t6 TSRMLS_CC);
		if (zend_is_true(r13)) {
			if (!r14) {
				PHALCON_ALLOC_ZVAL(r14);
			} else {
				if (Z_REFCOUNT_P(r14) > 1){ 
					PHALCON_SEPARATE(r14);
				}
			}
			boolean_not_function(r14, v0 TSRMLS_CC);
			PHALCON_INIT_VARTYPE(t7, IS_STRING);
			ZVAL_STRING(t7, "id", 1);
			if (!r15) {
				PHALCON_ALLOC_ZVAL(r15);
			} else {
				if (Z_REFCOUNT_P(r15) > 1){ 
					PHALCON_SEPARATE(r15);
				}
			}
			is_equal_function(r15, v9, t7 TSRMLS_CC);
			PHALCON_INIT_VARTYPE(r16, IS_BOOL);
			phalcon_and_function(r16, r14, r15 TSRMLS_CC);
			if (zend_is_true(r16)) {
				goto fi72;
			}
			PHALCON_INIT_RESULT(r17);
			PHALCON_INIT_VARTYPE(p12[0], IS_STRING);
			ZVAL_STRING(p12[0], "_id", 1);
			PHALCON_INIT_VARTYPE(p12[1], IS_STRING);
			ZVAL_STRING(p12[1], "", 1);
			p12[2] = v9;
			PHALCON_CALL_FUNC_PARAMS(r17, "str_replace", 3, p12, 0x017);
			PHALCON_CPY_WRT(v11, r17);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_message_class_entry);
			PHALCON_INIT_RESULT(r18);
			PHALCON_CONCAT_RIGHT(r18, v11, " is required");
			Z_ADDREF_P(r18);
			p13[0] = r18;
			Z_ADDREF_P(v9);
			p13[1] = v9;
			PHALCON_INIT_VARTYPE(p13[2], IS_STRING);
			ZVAL_STRING(p13[2], "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p13, PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v12, i0);
			PHALCON_INIT_VAR(t8);
			phalcon_read_property(t8, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v12, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				phalcon_array_append(t8, copy TSRMLS_CC);
			}
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t8 TSRMLS_CC);
			PHALCON_INIT_VARTYPE(v5, IS_BOOL);
			ZVAL_BOOL(v5, 1);
		}
		fi72:
		PHALCON_SEPARATE(v7);
		increment_function(v7);
		goto fs72;
		fe72:
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
	PHALCON_CPY_WRT(v13, r26);
	PHALCON_ALLOC_ZVAL(r27);
	PHALCON_CALL_METHOD(r27, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v14, r27);
	if (zend_is_true(v13)) {
		PHALCON_ALLOC_ZVAL(r28);
		PHALCON_CONCAT_VBOTH(r28, v13, ".", v14);
		PHALCON_CPY_WRT(v15, r28);
	} else {
		PHALCON_CPY_WRT(v15, v14);
	}
	PHALCON_ALLOC_ZVAL(t9);
	phalcon_read_property(t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v16, t9);
	PHALCON_ALLOC_ZVAL(r29);
	PHALCON_CALL_METHOD(r29, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v17, r29);
	PHALCON_ALLOC_ZVAL(r30);
	PHALCON_CALL_METHOD(r30, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v18, r30);
	PHALCON_ALLOC_ZVAL(r31);
	PHALCON_CALL_METHOD(r31, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r31);
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v19, a1);
		PHALCON_ALLOC_ZVAL(a2);
		array_init(a2);
		PHALCON_CPY_WRT(v20, a2);
		PHALCON_ALLOC_ZVAL(r32);
		PHALCON_CALL_METHOD(r32, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v21, r32);
		FOREACH_V(v21, ac0, fes73, fee73, ah0, hp0, v9)
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(v19);
				phalcon_array_append(v19, copy TSRMLS_CC);
			}
			PHALCON_INIT_VAR(t10);
			phalcon_read_property_zval(t10, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v10, t10);
			if (Z_TYPE_P(v10) == IS_OBJECT) {
				PHALCON_INIT_VARTYPE(r33, IS_BOOL);
				phalcon_instance_of(r33, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r33)) {
					PHALCON_INIT_RESULT(r34);
					PHALCON_CALL_METHOD(r34, v10, "getvalue", PHALCON_CALL_DEFAULT);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, r34, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						Z_UNSET_ISREF_P(copy);
						PHALCON_SEPARATE(v20);
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				} else {
					PHALCON_INIT_VAR(t11);
					phalcon_read_property_zval(t11, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
					convert_to_string(t11);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t11, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						Z_UNSET_ISREF_P(copy);
						PHALCON_SEPARATE(v20);
						phalcon_array_append(v20, copy TSRMLS_CC);
					}
				}
			} else {
				PHALCON_INIT_VARTYPE(t12, IS_STRING);
				ZVAL_STRING(t12, "", 1);
				PHALCON_INIT_VARTYPE(r35, IS_BOOL);
				is_identical_function(r35, t12, v10 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(t13, IS_NULL);
				ZVAL_NULL(t13);
				PHALCON_INIT_VARTYPE(r36, IS_BOOL);
				is_identical_function(r36, t13, v10 TSRMLS_CC);
				PHALCON_INIT_VARTYPE(r37, IS_BOOL);
				ZVAL_BOOL(r37, zend_is_true(r35) || zend_is_true(r36));
				if (zend_is_true(r37)) {
					PHALCON_INIT_VARTYPE(t14, IS_STRING);
					ZVAL_STRING(t14, "NULL", 1);
					{
						zval *copy;
						ALLOC_ZVAL(copy);
						ZVAL_ZVAL(copy, t14, 1, 0);
						Z_SET_REFCOUNT_P(copy, 1);
						Z_UNSET_ISREF_P(copy);
						PHALCON_SEPARATE(v20);
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
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v20);
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						PHALCON_INIT_RESULT(r38);
						phalcon_array_fetch(r38, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (PHALCON_COMPARE_STRING(r38, "date")) {
							PHALCON_INIT_RESULT(r39);
							Z_ADDREF_P(v10);
							p38[0] = v10;
							PHALCON_CALL_METHOD_PARAMS(r39, v16, "getdateusingformat", 1, p38, PHALCON_CALL_DEFAULT);
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r39, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								Z_UNSET_ISREF_P(copy);
								PHALCON_SEPARATE(v20);
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
							PHALCON_INIT_RESULT(r40);
							PHALCON_CONCAT_BOTH(r40,  "'", v10, "'");
							{
								zval *copy;
								ALLOC_ZVAL(copy);
								ZVAL_ZVAL(copy, r40, 1, 0);
								Z_SET_REFCOUNT_P(copy, 1);
								Z_UNSET_ISREF_P(copy);
								PHALCON_SEPARATE(v20);
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						}
					}
				}
			}
		END_FOREACH(ac0, fes73, fee73, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r41);
		Z_ADDREF_P(v15);
		p39[0] = v15;
		Z_ADDREF_P(v19);
		p39[1] = v19;
		Z_ADDREF_P(v20);
		p39[2] = v20;
		PHALCON_ALLOC_ZVAL(t15);
		phalcon_read_property(t15, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t15);
		p39[3] = t15;
		PHALCON_CALL_METHOD_PARAMS(r41, v16, "update", 4, p39, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v22, r41);
	} else {
		PHALCON_ALLOC_ZVAL(a3);
		array_init(a3);
		PHALCON_CPY_WRT(v19, a3);
		PHALCON_ALLOC_ZVAL(a4);
		array_init(a4);
		PHALCON_CPY_WRT(v20, a4);
		PHALCON_ALLOC_ZVAL(r42);
		PHALCON_CALL_METHOD(r42, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v23, r42);
		FOREACH_V(v23, ac1, fes74, fee74, ah1, hp1, v9)
			if (!PHALCON_COMPARE_STRING(v9, "id")) {
				{
					zval *copy;
					ALLOC_ZVAL(copy);
					ZVAL_ZVAL(copy, v9, 1, 0);
					Z_SET_REFCOUNT_P(copy, 1);
					Z_UNSET_ISREF_P(copy);
					PHALCON_SEPARATE(v19);
					phalcon_array_append(v19, copy TSRMLS_CC);
				}
				PHALCON_INIT_VAR(t16);
				phalcon_read_property_zval(t16, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v10, t16);
				if (Z_TYPE_P(v10) == IS_OBJECT) {
					PHALCON_INIT_VARTYPE(r43, IS_BOOL);
					phalcon_instance_of(r43, v10, phalcon_db_rawvalue_class_entry TSRMLS_CC);
					if (zend_is_true(r43)) {
						PHALCON_INIT_RESULT(r44);
						PHALCON_CALL_METHOD(r44, v10, "getvalue", PHALCON_CALL_DEFAULT);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, r44, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v20);
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					} else {
						convert_to_string(v10);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, v10, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v20);
							phalcon_array_append(v20, copy TSRMLS_CC);
						}
					}
				} else {
					PHALCON_INIT_VARTYPE(t17, IS_STRING);
					ZVAL_STRING(t17, "", 1);
					PHALCON_INIT_VARTYPE(r45, IS_BOOL);
					is_identical_function(r45, t17, v10 TSRMLS_CC);
					PHALCON_INIT_VARTYPE(t18, IS_NULL);
					ZVAL_NULL(t18);
					PHALCON_INIT_VARTYPE(r46, IS_BOOL);
					is_identical_function(r46, t18, v10 TSRMLS_CC);
					PHALCON_INIT_VARTYPE(r47, IS_BOOL);
					ZVAL_BOOL(r47, zend_is_true(r45) || zend_is_true(r46));
					if (zend_is_true(r47)) {
						PHALCON_INIT_VARTYPE(t19, IS_STRING);
						ZVAL_STRING(t19, "NULL", 1);
						{
							zval *copy;
							ALLOC_ZVAL(copy);
							ZVAL_ZVAL(copy, t19, 1, 0);
							Z_SET_REFCOUNT_P(copy, 1);
							Z_UNSET_ISREF_P(copy);
							PHALCON_SEPARATE(v20);
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
								Z_UNSET_ISREF_P(copy);
								PHALCON_SEPARATE(v20);
								phalcon_array_append(v20, copy TSRMLS_CC);
							}
						} else {
							PHALCON_INIT_RESULT(r48);
							phalcon_array_fetch(r48, v17, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
							if (PHALCON_COMPARE_STRING(r48, "date")) {
								PHALCON_INIT_RESULT(r49);
								PHALCON_INIT_VAR(t20);
								phalcon_read_property(t20, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
								Z_ADDREF_P(v10);
								p42[0] = v10;
								PHALCON_CALL_METHOD_PARAMS(r49, t20, "getdateusingformat", 1, p42, PHALCON_CALL_DEFAULT);
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r49, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									Z_UNSET_ISREF_P(copy);
									PHALCON_SEPARATE(v20);
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							} else {
								PHALCON_INIT_RESULT(r50);
								PHALCON_CONCAT_BOTH(r50,  "'", v10, "'");
								{
									zval *copy;
									ALLOC_ZVAL(copy);
									ZVAL_ZVAL(copy, r50, 1, 0);
									Z_SET_REFCOUNT_P(copy, 1);
									Z_UNSET_ISREF_P(copy);
									PHALCON_SEPARATE(v20);
									phalcon_array_append(v20, copy TSRMLS_CC);
								}
							}
						}
					}
				}
			}
		END_FOREACH(ac1, fes74, fee74, ah1, hp1);
		PHALCON_ALLOC_ZVAL(v24);
		ZVAL_STRING(v24, "", 0);
		eval_int = phalcon_isset_property(this_ptr, "id", strlen("id") TSRMLS_CC);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL(r51);
			PHALCON_ALLOC_ZVAL(t21);
			phalcon_read_property(t21, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t21);
			PHALCON_CALL_FUNC_PARAMS_1(r51, "is_null", t21, 0x041);
			PHALCON_ALLOC_ZVAL(t22);
			phalcon_read_property(t22, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t23);
			ZVAL_STRING(t23, "", 1);
			PHALCON_ALLOC_ZVAL(r52);
			is_identical_function(r52, t23, t22 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(r53);
			ZVAL_BOOL(r53, zend_is_true(r51) || zend_is_true(r52));
			if (zend_is_true(r53)) {
				phalcon_update_property_string(this_ptr, "id", strlen("id"), "null" TSRMLS_CC);
			}
			PHALCON_ALLOC_ZVAL(t24);
			ZVAL_STRING(t24, "id", 1);
			PHALCON_SEPARATE(v19);
			phalcon_array_append(v19, t24 TSRMLS_CC);
			PHALCON_ALLOC_ZVAL(t25);
			phalcon_read_property(t25, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_SEPARATE(v20);
			phalcon_array_append(v20, t25 TSRMLS_CC);
		}
		PHALCON_ALLOC_ZVAL(r54);
		PHALCON_ALLOC_ZVAL(t26);
		phalcon_read_property(t26, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v15);
		p44[0] = v15;
		Z_ADDREF_P(v20);
		p44[1] = v20;
		Z_ADDREF_P(v19);
		p44[2] = v19;
		PHALCON_CALL_METHOD_PARAMS(r54, t26, "insert", 3, p44, PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v22, r54);
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
		PHALCON_RETURN_CHECK_CTOR(v22);
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
	zval *c0 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL(t0);
	phalcon_read_property(t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL(t1);
		phalcon_read_property(t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(t2);
		phalcon_read_property(t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r0);
		PHALCON_CONCAT_VBOTH(r0, t1, ".", t2);
		PHALCON_CPY_WRT_PARAM(v0, r0);
	} else {
		PHALCON_ALLOC_ZVAL(t3);
		phalcon_read_property(t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT_PARAM(v0, t3);
	}
	PHALCON_ALLOC_ZVAL(t4);
	phalcon_get_class_constant(t4, phalcon_model_base_class_entry, "OP_DELETE", strlen("OP_DELETE") TSRMLS_CC);
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, "_operationMade", t4);
	PHALCON_ALLOC_ZVAL(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", v1, 0x008);
	PHALCON_ALLOC_ZVAL(t5);
	ZVAL_LONG(t5, 1);
	PHALCON_ALLOC_ZVAL(r3);
	is_equal_function(r3, r2, t5 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL(t6);
		PHALCON_ALLOC_ZVAL(r4);
		phalcon_array_fetch_long(r4, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_read_property_zval(t6, this_ptr, r4, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t6);
		PHALCON_ALLOC_ZVAL(r6);
		phalcon_array_fetch_long(r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, " = '", v2);
		PHALCON_ALLOC_ZVAL(r7);
		PHALCON_CONCAT_RIGHT(r7, r5, "'");
		PHALCON_CPY_WRT(v3, r7);
	} else {
		PHALCON_ALLOC_ZVAL(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		FOREACH_V(v1, ac0, fes75, fee75, ah0, hp0, v4)
			PHALCON_INIT_VAR(t7);
			phalcon_read_property_zval(t7, this_ptr, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, t7);
			PHALCON_INIT_RESULT(r8);
			PHALCON_CONCAT_VBOTH(r8, v4, " = '", v2);
			PHALCON_INIT_RESULT(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "'");
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, r9, 1, 0);
				Z_SET_REFCOUNT_P(copy, 1);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(v3);
				phalcon_array_append(v3, copy TSRMLS_CC);
			}
		END_FOREACH(ac0, fes75, fee75, ah0, hp0);
		PHALCON_ALLOC_ZVAL(r10);
		PHALCON_ALLOC_ZVAL(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r10, "join", c0, v3, 0x00B);
		FREE_ZVAL(c0);
		PHALCON_CPY_WRT(v3, r10);
	}
	t8 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t8);
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
	Z_ADDREF_P(v0);
	p5[0] = v0;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS(r12, t9, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r12);
	if (zend_is_true(v6)) {
		if (!zend_is_true(v5)) {
			PHALCON_ALLOC_ZVAL(p6[0]);
			ZVAL_STRING(p6[0], "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p6, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v6);
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
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL(t1);
	phalcon_read_property_zval(t1, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t1);
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
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_UPDATE_PROPERTY_CPY(this_ptr, Z_STRVAL_P(v0), v1);
	RETURN_NULL();
}

/**
 * Setup a 1-1 relation between two models
 *
 *
 * 
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Base, hasOne){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasone", 4, p0, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *
 *
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Base, belongsTo){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addbelongsto", 4, p0, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Setup a relation 1-n between two models
     *
 *
 *
 * @parammixed $fields
 * @paramstring $referenceModel
 * @parammixed $referencedFields 
 */
PHP_METHOD(Phalcon_Model_Base, hasMany){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		RETURN_NULL();
	}

	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		Z_ADDREF_P(this_ptr);
		p0[0] = this_ptr;
		Z_ADDREF_P(v0);
		p0[1] = v0;
		Z_ADDREF_P(v1);
		p0[2] = v1;
		Z_ADDREF_P(v2);
		p0[3] = v2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasmany", 4, p0, PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_ALLOC_ZVAL(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		return;
	}
	RETURN_NULL();
}

/**
 * Handles methods when a method does not exist
 *
 * @paramstring $method
 * @paramarray $arguments
 * @returnmixed
 * @throwsPhalcon_Model_Exception
 */
PHP_METHOD(Phalcon_Model_Base, __call){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL, *a8 = NULL, *a9 = NULL, *a10 = NULL, *a11 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p10[] = { NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p17[] = { NULL, NULL }, *p20[] = { NULL, NULL }, *p23[] = { NULL, NULL }, *p26[] = { NULL };

	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_ALLOC_ZVAL(p0[1]);
	ZVAL_LONG(p0[1], 0);
	PHALCON_ALLOC_ZVAL(p0[2]);
	ZVAL_LONG(p0[2], 3);
	PHALCON_CALL_FUNC_PARAMS(r0, "substr", 3, p0, 0x00A);
	if (PHALCON_COMPARE_STRING(r0, "get")) {
		PHALCON_ALLOC_ZVAL(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x03E);
		PHALCON_CPY_WRT(v2, r1);
		PHALCON_ALLOC_ZVAL(r2);
		PHALCON_ALLOC_ZVAL(r3);
		Z_ADDREF_P(v0);
		PHALCON_ALLOC_ZVAL(c0);
		ZVAL_LONG(c0, 3);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", v0, c0, 0x00A);
		FREE_ZVAL(c0);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "ucfirst", r3, 0x042);
		PHALCON_CPY_WRT(v3, r2);
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t0);
		PHALCON_ALLOC_ZVAL(r4);
		Z_ADDREF_P(v2);
		p4[0] = v2;
		Z_ADDREF_P(v3);
		p4[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r4, v4, "existsbelongsto", 2, p4, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r4)) {
			PHALCON_ALLOC_ZVAL(a0);
			array_init(a0);
			add_next_index_string(a0, "findFirst", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a0);
				add_next_index_zval(a0, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a0);
				add_next_index_zval(a0, copy);
			}
			PHALCON_SEPARATE(a0);
			add_next_index_zval(a0, this_ptr);
			PHALCON_CPY_WRT(v5, a0);
			PHALCON_ALLOC_ZVAL(r5);
			PHALCON_ALLOC_ZVAL(a1);
			array_init(a1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a1);
				add_next_index_zval(a1, copy);
			}
			add_next_index_string(a1, "getBelongsToRecords", 1);
			Z_ADDREF_P(a1);
			PHALCON_ALLOC_ZVAL(r6);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r6, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r6);
			PHALCON_CALL_FUNC_PARAMS_2(r5, "call_user_func_array", a1, r6, 0x001);
			RETURN_ZVAL(r5, 1, 0);
		}
		PHALCON_ALLOC_ZVAL(r7);
		Z_ADDREF_P(v2);
		p7[0] = v2;
		Z_ADDREF_P(v3);
		p7[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "existshasmany", 2, p7, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL(a2);
			array_init(a2);
			add_next_index_string(a2, "find", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a2);
				add_next_index_zval(a2, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a2);
				add_next_index_zval(a2, copy);
			}
			PHALCON_SEPARATE(a2);
			add_next_index_zval(a2, this_ptr);
			PHALCON_CPY_WRT(v5, a2);
			PHALCON_ALLOC_ZVAL(r8);
			PHALCON_ALLOC_ZVAL(a3);
			array_init(a3);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a3);
				add_next_index_zval(a3, copy);
			}
			add_next_index_string(a3, "getHasManyRecords", 1);
			Z_ADDREF_P(a3);
			PHALCON_ALLOC_ZVAL(r9);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r9, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r9);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "call_user_func_array", a3, r9, 0x001);
			RETURN_ZVAL(r8, 1, 0);
		}
		PHALCON_ALLOC_ZVAL(r10);
		Z_ADDREF_P(v2);
		p10[0] = v2;
		Z_ADDREF_P(v3);
		p10[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r10, v4, "existshasone", 2, p10, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r10)) {
			PHALCON_ALLOC_ZVAL(a4);
			array_init(a4);
			add_next_index_string(a4, "findFirst", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a4);
				add_next_index_zval(a4, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a4);
				add_next_index_zval(a4, copy);
			}
			PHALCON_SEPARATE(a4);
			add_next_index_zval(a4, this_ptr);
			PHALCON_CPY_WRT(v5, a4);
			PHALCON_ALLOC_ZVAL(r11);
			PHALCON_ALLOC_ZVAL(a5);
			array_init(a5);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a5);
				add_next_index_zval(a5, copy);
			}
			add_next_index_string(a5, "getHasOneRecords", 1);
			Z_ADDREF_P(a5);
			PHALCON_ALLOC_ZVAL(r12);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r12);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "call_user_func_array", a5, r12, 0x001);
			RETURN_ZVAL(r11, 1, 0);
		}
	}
	PHALCON_ALLOC_ZVAL(r13);
	Z_ADDREF_P(v0);
	p13[0] = v0;
	PHALCON_ALLOC_ZVAL(p13[1]);
	ZVAL_LONG(p13[1], 0);
	PHALCON_ALLOC_ZVAL(p13[2]);
	ZVAL_LONG(p13[2], 5);
	PHALCON_CALL_FUNC_PARAMS(r13, "substr", 3, p13, 0x00A);
	if (PHALCON_COMPARE_STRING(r13, "count")) {
		PHALCON_ALLOC_ZVAL(r14);
		PHALCON_CALL_FUNC_PARAMS_1(r14, "get_class", this_ptr, 0x03E);
		PHALCON_CPY_WRT(v2, r14);
		PHALCON_ALLOC_ZVAL(r15);
		PHALCON_ALLOC_ZVAL(r16);
		Z_ADDREF_P(v0);
		PHALCON_ALLOC_ZVAL(c1);
		ZVAL_LONG(c1, 5);
		PHALCON_CALL_FUNC_PARAMS_2(r16, "substr", v0, c1, 0x00A);
		FREE_ZVAL(c1);
		PHALCON_CALL_FUNC_PARAMS_1(r15, "ucfirst", r16, 0x042);
		PHALCON_CPY_WRT(v3, r15);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t1);
		PHALCON_ALLOC_ZVAL(r17);
		Z_ADDREF_P(v2);
		p17[0] = v2;
		Z_ADDREF_P(v3);
		p17[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r17, v4, "existsbelongsto", 2, p17, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r17)) {
			PHALCON_ALLOC_ZVAL(a6);
			array_init(a6);
			add_next_index_string(a6, "count", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a6);
				add_next_index_zval(a6, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a6);
				add_next_index_zval(a6, copy);
			}
			PHALCON_SEPARATE(a6);
			add_next_index_zval(a6, this_ptr);
			PHALCON_CPY_WRT(v5, a6);
			PHALCON_ALLOC_ZVAL(r18);
			PHALCON_ALLOC_ZVAL(a7);
			array_init(a7);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a7);
				add_next_index_zval(a7, copy);
			}
			add_next_index_string(a7, "getBelongsToRecords", 1);
			Z_ADDREF_P(a7);
			PHALCON_ALLOC_ZVAL(r19);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r19);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "call_user_func_array", a7, r19, 0x001);
			RETURN_ZVAL(r18, 1, 0);
		}
		PHALCON_ALLOC_ZVAL(r20);
		Z_ADDREF_P(v2);
		p20[0] = v2;
		Z_ADDREF_P(v3);
		p20[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r20, v4, "existshasmany", 2, p20, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r20)) {
			PHALCON_ALLOC_ZVAL(a8);
			array_init(a8);
			add_next_index_string(a8, "count", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a8);
				add_next_index_zval(a8, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a8);
				add_next_index_zval(a8, copy);
			}
			PHALCON_SEPARATE(a8);
			add_next_index_zval(a8, this_ptr);
			PHALCON_CPY_WRT(v5, a8);
			PHALCON_ALLOC_ZVAL(r21);
			PHALCON_ALLOC_ZVAL(a9);
			array_init(a9);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a9);
				add_next_index_zval(a9, copy);
			}
			add_next_index_string(a9, "getHasManyRecords", 1);
			Z_ADDREF_P(a9);
			PHALCON_ALLOC_ZVAL(r22);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r22, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r22);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "call_user_func_array", a9, r22, 0x001);
			RETURN_ZVAL(r21, 1, 0);
		}
		PHALCON_ALLOC_ZVAL(r23);
		Z_ADDREF_P(v2);
		p23[0] = v2;
		Z_ADDREF_P(v3);
		p23[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r23, v4, "existshasone", 2, p23, PHALCON_CALL_DEFAULT);
		if (zend_is_true(r23)) {
			PHALCON_ALLOC_ZVAL(a10);
			array_init(a10);
			add_next_index_string(a10, "count", 1);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v2, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a10);
				add_next_index_zval(a10, copy);
			}
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v3, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a10);
				add_next_index_zval(a10, copy);
			}
			PHALCON_SEPARATE(a10);
			add_next_index_zval(a10, this_ptr);
			PHALCON_CPY_WRT(v5, a10);
			PHALCON_ALLOC_ZVAL(r24);
			PHALCON_ALLOC_ZVAL(a11);
			array_init(a11);
			{
				zval *copy;
				ALLOC_ZVAL(copy);
				ZVAL_ZVAL(copy, v4, 1, 0);
				Z_SET_REFCOUNT_P(copy, 0);
				Z_UNSET_ISREF_P(copy);
				PHALCON_SEPARATE(a11);
				add_next_index_zval(a11, copy);
			}
			add_next_index_string(a11, "getHasOneRecords", 1);
			Z_ADDREF_P(a11);
			PHALCON_ALLOC_ZVAL(r25);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r25, "array_merge", v5, v1, 0x043);
			Z_ADDREF_P(r25);
			PHALCON_CALL_FUNC_PARAMS_2(r24, "call_user_func_array", a11, r25, 0x001);
			RETURN_ZVAL(r24, 1, 0);
		}
	}
	PHALCON_ALLOC_ZVAL(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_ALLOC_ZVAL(r27);
	PHALCON_CONCAT_LEFT(r27, "Method \"", v0);
	PHALCON_ALLOC_ZVAL(r28);
	PHALCON_CALL_FUNC_PARAMS_1(r28, "get_class", this_ptr, 0x03E);
	PHALCON_ALLOC_ZVAL(r26);
	PHALCON_CONCAT_VBOTH(r26, r27, "\" doesn't exist on model \"", r28);
	PHALCON_ALLOC_ZVAL(r29);
	PHALCON_CONCAT_RIGHT(r29, r26, "\"");
	Z_ADDREF_P(r29);
	p26[0] = r29;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p26, PHALCON_CALL_CHECK);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	return;
}

