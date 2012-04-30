
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	if (!zend_is_true(v0)) {
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t0)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
			PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_CALL_DEFAULT);
			zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, r0 TSRMLS_CC);
		}
	} else {
		zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "get_class", this_ptr, 0x02F);
	PHALCON_CPY_WRT(v1, r2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_initialized", sizeof("_initialized")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t1)) {
		if (phalcon_method_exists_ex(this_ptr, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_CALL_DEFAULT);
		}
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_initialized", strlen("_initialized"), 1 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Internal method for make a connection. Automatically dumps mapped table meta-data
 *
 */
PHP_METHOD(Phalcon_Model_Base, _connect){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_CALL_DEFAULT);
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnonprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getnotnullattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypesnumeric", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getdatatypes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Dumps mapped table meta-data
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, dump){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *p0[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_CALL_DEFAULT);
	Z_ADDREF_P(this_ptr);
	p0[0] = this_ptr;
	PHALCON_CALL_METHOD_PARAMS(r0, r1, "getattributes", 1, p0, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p0[0]);
	PHALCON_CPY_WRT(v0, r0);
	if (Z_TYPE_P(v0) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v0);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_0;
		}
		PHALCON_INIT_VAR(v1);
		ZVAL_ZVAL(v1, *hd, 1, 0);
		eval_int = phalcon_isset_property_zval(this_ptr, v1 TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, eval_int);
		if (!zend_is_true(t2)) {
			PHALCON_INIT_VAR(t3);
			ZVAL_STRING(t3, "", 1);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v1), Z_STRLEN_P(v1), t3 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_0;
		fee_f9eb_0:
		if(0){ };
	}
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v3);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, v0, "getmetadata", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, v1, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v5, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v1, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r2);
	PHALCON_INIT_VAR(v7);
	ZVAL_STRING(v7, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(v3, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v3, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, v7, r3 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, ", ", 1);
		PHALCON_ALLOC_ZVAL_MM(r6);
		Z_ADDREF_P(v1);
		p4[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r6, v4, "getattributes", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_CALL_FUNC_PARAMS_2(r5, "join", c0, r6, 0x00D);
		PHALCON_ALLOC_ZVAL_MM(r7);
		concat_function(r7, v7, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r7);
	}
	if (zend_is_true(v6)) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_LEFT(r9, " FROM ", v6);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_VBOTH(r8, r9, ".", v5);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v7, r8 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r10);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, " FROM ", v5);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, v7, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r12);
	}
	PHALCON_INIT_VAR(v8);
	ZVAL_STRING(v8, "n", 1);
	eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_BOTH(r14,  " WHERE ", r13, " ");
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, v7, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v7, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		Z_ADDREF_P(v1);
		p5[0] = v1;
		PHALCON_CALL_METHOD_PARAMS(r16, v4, "getprimarykeyattributes", 1, p5, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v9, r16);
		eval_int = phalcon_array_isset_long(v3, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r17, "is_numeric", r18, 0x00B);
			if (zend_is_true(r17)) {
				eval_int = phalcon_array_isset_long(v9, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r20);
					phalcon_array_fetch_long(&r20, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r21);
					PHALCON_ALLOC_ZVAL_MM(r22);
					phalcon_array_fetch_long(&r22, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r22);
					p7[0] = r22;
					PHALCON_CALL_METHOD_PARAMS(r21, v2, "addquotes", 1, p7, PHALCON_CALL_DEFAULT);
					Z_DELREF_P(p7[0]);
					PHALCON_ALLOC_ZVAL_MM(r19);
					PHALCON_CONCAT_VBOTH(r19, r20, " = ", r21);
					Z_ADDREF_P(r19);
					if (Z_REFCOUNT_P(v3) > 1) {
						zval *new_zv;
						Z_DELREF_P(v3);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v3);
						v3 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r19 TSRMLS_CC);
					PHALCON_INIT_VAR(v8);
					ZVAL_STRING(v8, "1", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_class_entry);
					PHALCON_INIT_VAR(p8[0]);
					ZVAL_STRING(p8[0], "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p8, PHALCON_CALL_CHECK);
					zend_throw_exception_object(i0 TSRMLS_CC);
					Z_ADDREF_P(i0);
					PHALCON_MM_RESTORE();
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL_MM(r23);
				phalcon_array_fetch_long(&r23, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_INIT_VAR(r24);
				is_identical_function(r24, t0, r23 TSRMLS_CC);
				if (zend_is_true(r24)) {
					eval_int = phalcon_array_isset_long(v9, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL_MM(r25);
						phalcon_array_fetch_long(&r25, v9, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r26);
						PHALCON_CONCAT_RIGHT(r26, r25, " = ''");
						Z_ADDREF_P(r26);
						if (Z_REFCOUNT_P(v3) > 1) {
							zval *new_zv;
							Z_DELREF_P(v3);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v3);
							v3 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v3, "conditions", strlen("conditions"), r26 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_model_exception_class_entry);
						PHALCON_INIT_VAR(p9[0]);
						ZVAL_STRING(p9[0], "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p9, PHALCON_CALL_CHECK);
						zend_throw_exception_object(i1 TSRMLS_CC);
						Z_ADDREF_P(i1);
						PHALCON_MM_RESTORE();
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r27);
					phalcon_array_fetch_long(&r27, v3, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					Z_ADDREF_P(r27);
					if (Z_REFCOUNT_P(v3) > 1) {
						zval *new_zv;
						Z_DELREF_P(v3);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v3);
						v3 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v3, "conditions", strlen("conditions"), r27 TSRMLS_CC);
				}
				PHALCON_INIT_VAR(v8);
				ZVAL_STRING(v8, "n", 1);
			}
		}
		eval_int = phalcon_array_isset_string(v3, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r28);
			phalcon_array_fetch_string(&r28, v3, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r29);
			PHALCON_CONCAT_LEFT(r29, " WHERE ", r28);
			PHALCON_ALLOC_ZVAL_MM(r30);
			concat_function(r30, v7, r29 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r30);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r31);
		phalcon_array_fetch_string(&r31, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r31)) {
			PHALCON_ALLOC_ZVAL_MM(r32);
			phalcon_array_fetch_string(&r32, v3, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CONCAT_LEFT(r33, " GROUP BY ", r32);
			PHALCON_ALLOC_ZVAL_MM(r34);
			concat_function(r34, v7, r33 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r34);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r35);
		phalcon_array_fetch_string(&r35, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r35)) {
			PHALCON_ALLOC_ZVAL_MM(r36);
			phalcon_array_fetch_string(&r36, v3, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r37);
			PHALCON_CONCAT_LEFT(r37, " ORDER BY ", r36);
			PHALCON_ALLOC_ZVAL_MM(r38);
			concat_function(r38, v7, r37 TSRMLS_CC);
			PHALCON_CPY_WRT(v7, r38);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		phalcon_array_fetch_string(&r39, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r39)) {
			PHALCON_ALLOC_ZVAL_MM(r40);
			Z_ADDREF_P(v7);
			p10[0] = v7;
			PHALCON_ALLOC_ZVAL_MM(r41);
			phalcon_array_fetch_string(&r41, v3, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(r41);
			p10[1] = r41;
			PHALCON_CALL_METHOD_PARAMS(r40, v2, "limit", 2, p10, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p10[0]);
			Z_DELREF_P(p10[1]);
			PHALCON_CPY_WRT(v7, r40);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r42);
		phalcon_array_fetch_string(&r42, v3, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r42)) {
			PHALCON_ALLOC_ZVAL_MM(r43);
			Z_ADDREF_P(v7);
			p11[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r43, v2, "forupdate", 1, p11, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p11[0]);
			PHALCON_CPY_WRT(v7, r43);
		}
	}
	eval_int = phalcon_array_isset_string(v3, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r44);
		phalcon_array_fetch_string(&r44, v3, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
		if (zend_is_true(r44)) {
			PHALCON_ALLOC_ZVAL_MM(r45);
			Z_ADDREF_P(v7);
			p12[0] = v7;
			PHALCON_CALL_METHOD_PARAMS(r45, v2, "sharedlock", 1, p12, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p12[0]);
			PHALCON_CPY_WRT(v7, r45);
		}
	}
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(v8);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "return", v8);
	Z_ADDREF_P(v7);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "sql", v7);
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
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p3[] = { NULL, NULL }, *p4[] = { NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &v0, &v1, &v2, &v3, &v4) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v3);
	
	if (!v4) {
		PHALCON_INIT_VAR(v4);
		ZVAL_STRING(v4, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(v4);
	}
	
	if (Z_TYPE_P(v4) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch_string(&r1, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CONCAT_BOTH(r2,  " WHERE ", r1, " ");
				PHALCON_ALLOC_ZVAL_MM(r3);
				concat_function(r3, v3, r2 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r3);
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, v0, "getmetadata", PHALCON_CALL_DEFAULT);
			Z_ADDREF_P(v1);
			p0[0] = v1;
			PHALCON_CALL_METHOD_PARAMS(r4, r5, "getprimarykeyattributes", 1, p0, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p0[0]);
			PHALCON_CPY_WRT(v5, r4);
			eval_int = phalcon_array_isset_long(v4, 0);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_ALLOC_ZVAL_MM(r7);
				phalcon_array_fetch_long(&r7, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS_1(r6, "is_numeric", r7, 0x00B);
				if (zend_is_true(r6)) {
					PHALCON_ALLOC_ZVAL_MM(r9);
					phalcon_array_fetch_long(&r9, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r10);
					phalcon_array_fetch_long(&r10, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, " = '", r10);
					PHALCON_ALLOC_ZVAL_MM(r11);
					PHALCON_CONCAT_RIGHT(r11, r8, "'");
					Z_ADDREF_P(r11);
					if (Z_REFCOUNT_P(v4) > 1) {
						zval *new_zv;
						Z_DELREF_P(v4);
						ALLOC_ZVAL(new_zv);
						INIT_PZVAL_COPY(new_zv, v4);
						v4 = new_zv;
						zval_copy_ctor(new_zv);
					}
					phalcon_array_update_string(v4, "conditions", strlen("conditions"), r11 TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r12);
					phalcon_array_fetch_long(&r12, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r12, "")) {
						PHALCON_ALLOC_ZVAL_MM(r13);
						phalcon_array_fetch_long(&r13, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r14);
						PHALCON_CONCAT_RIGHT(r14, r13, " = ''");
						Z_ADDREF_P(r14);
						if (Z_REFCOUNT_P(v4) > 1) {
							zval *new_zv;
							Z_DELREF_P(v4);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v4);
							v4 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r14 TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(r15);
						phalcon_array_fetch_long(&r15, v4, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
						Z_ADDREF_P(r15);
						if (Z_REFCOUNT_P(v4) > 1) {
							zval *new_zv;
							Z_DELREF_P(v4);
							ALLOC_ZVAL(new_zv);
							INIT_PZVAL_COPY(new_zv, v4);
							v4 = new_zv;
							zval_copy_ctor(new_zv);
						}
						phalcon_array_update_string(v4, "conditions", strlen("conditions"), r15 TSRMLS_CC);
					}
				}
			}
			eval_int = phalcon_array_isset_string(v4, "conditions", strlen("conditions")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r16);
				phalcon_array_fetch_string(&r16, v4, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_CONCAT_LEFT(r17, " WHERE ", r16);
				PHALCON_ALLOC_ZVAL_MM(r18);
				concat_function(r18, v3, r17 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r18);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "order", strlen("order")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r19);
			phalcon_array_fetch_string(&r19, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				phalcon_array_fetch_string(&r20, v4, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CONCAT_LEFT(r21, " ORDER BY ", r20);
				PHALCON_ALLOC_ZVAL_MM(r22);
				concat_function(r22, v3, r21 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r22);
			}
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_ALLOC_ZVAL_MM(r23);
			concat_function(r23, v3, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r23);
		}
		eval_int = phalcon_array_isset_string(v4, "limit", strlen("limit")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			phalcon_array_fetch_string(&r24, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r24)) {
				PHALCON_ALLOC_ZVAL_MM(r25);
				Z_ADDREF_P(v3);
				p3[0] = v3;
				PHALCON_ALLOC_ZVAL_MM(r26);
				phalcon_array_fetch_string(&r26, v4, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
				Z_ADDREF_P(r26);
				p3[1] = r26;
				PHALCON_CALL_METHOD_PARAMS(r25, v2, "limit", 2, p3, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p3[0]);
				Z_DELREF_P(p3[1]);
				PHALCON_CPY_WRT(v3, r25);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "for_update", strlen("for_update")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r27);
			phalcon_array_fetch_string(&r27, v4, "for_update", strlen("for_update"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r27)) {
				PHALCON_ALLOC_ZVAL_MM(r28);
				Z_ADDREF_P(v3);
				p4[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r28, v2, "forupdate", 1, p4, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p4[0]);
				PHALCON_CPY_WRT(v3, r28);
			}
		}
		eval_int = phalcon_array_isset_string(v4, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r29);
			phalcon_array_fetch_string(&r29, v4, "shared_lock", strlen("shared_lock"), PHALCON_NOISY_FETCH TSRMLS_CC);
			if (zend_is_true(r29)) {
				PHALCON_ALLOC_ZVAL_MM(r30);
				Z_ADDREF_P(v3);
				p5[0] = v3;
				PHALCON_CALL_METHOD_PARAMS(r30, v2, "sharedlock", 1, p5, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p5[0]);
				PHALCON_CPY_WRT(v3, r30);
			}
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CALL_FUNC_PARAMS_1(r31, "strlen", v4, 0x001);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r32);
		is_smaller_function(r32, t1, r31 TSRMLS_CC);
		if (zend_is_true(r32)) {
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "is_numeric", v4, 0x00B);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r35);
				phalcon_array_fetch_long(&r35, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r36);
				PHALCON_CONCAT_LEFT(r36, "WHERE ", r35);
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_CONCAT_VBOTH(r34, r36, " = '", v4);
				PHALCON_ALLOC_ZVAL_MM(r37);
				PHALCON_CONCAT_RIGHT(r37, r34, "'");
				PHALCON_ALLOC_ZVAL_MM(r38);
				concat_function(r38, v3, r37 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r38);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r39);
				PHALCON_CONCAT_LEFT(r39, "WHERE ", v4);
				PHALCON_ALLOC_ZVAL_MM(r40);
				concat_function(r40, v3, r39 TSRMLS_CC);
				PHALCON_CPY_WRT(v3, r40);
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
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL }, *p7[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, v2, "return", strlen("return"), PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "1", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		Z_ADDREF_P(v3);
		p0[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r2, v1, "numrows", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_ALLOC_ZVAL_MM(r3);
		is_equal_function(r3, r2, t1 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		} else {
			PHALCON_ALLOC_ZVAL_MM(t2);
			phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
			Z_ADDREF_P(t2);
			p1[0] = t2;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p1, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p1[0]);
			PHALCON_ALLOC_ZVAL_MM(r4);
			Z_ADDREF_P(v3);
			p2[0] = v3;
			PHALCON_CALL_METHOD_PARAMS(r4, v1, "fetcharray", 1, p2, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p2[0]);
			PHALCON_CPY_WRT(v4, r4);
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_get_class_constant(t3, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
			Z_ADDREF_P(t3);
			p3[0] = t3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v1, "setfetchmode", 1, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			PHALCON_ALLOC_ZVAL_MM(r5);
			Z_ADDREF_P(v4);
			p4[0] = v4;
			PHALCON_CALL_SELF_PARAMS(r5, this_ptr, "dumpresult", 1, p4);
			Z_DELREF_P(p4[0]);
			PHALCON_RETURN_DZVAL(r5);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r6);
		Z_ADDREF_P(v3);
		p5[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r6, v1, "numrows", 1, p5, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p5[0]);
		PHALCON_CPY_WRT(v5, r6);
		PHALCON_INIT_VAR(t4);
		ZVAL_LONG(t4, 0);
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, t4, v5 TSRMLS_CC);
		if (zend_is_true(r7)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p6[0] = v0;
			Z_ADDREF_P(v3);
			p6[1] = v3;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 2, p6, PHALCON_CALL_CHECK);
			Z_DELREF_P(p6[0]);
			Z_DELREF_P(p6[1]);
			PHALCON_RETURN_CTOR(i0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v0);
			p7[0] = v0;
			PHALCON_INIT_VAR(p7[1]);
			ZVAL_BOOL(p7[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p7, PHALCON_CALL_CHECK);
			Z_DELREF_P(p7[0]);
			PHALCON_RETURN_CTOR(i1);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Overwrittes default model manager
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns internal models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Model_Base, getManager){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, v0, "getconnection", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Transaction should be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 */
PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x02F);
		Z_ADDREF_P(r1);
		p0[0] = r1;
		PHALCON_CALL_METHOD_PARAMS(r0, t1, "getsource", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 */
PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_CALL_DEFAULT);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Overwrittes internal Phalcon_Db connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Base, setConnection){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Gets internal Phalcon_Db connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *index;
	uint index_len;
	ulong num;
	int htype;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	phalcon_clone(i0, v0 TSRMLS_CC);
	PHALCON_CPY_WRT(v2, i0);
	if (Z_TYPE_P(v1) == IS_ARRAY) { 
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_1;
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
			PHALCON_INIT_VAR(v3);
			ZVAL_ZVAL(v3, *hd, 1, 0);
			phalcon_update_property_zval(v2, Z_STRVAL_P(v4), Z_STRLEN_P(v4), v3 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_1;
			fee_f9eb_1:
			if(0){ };
		}
	}
	PHALCON_RETURN_CHECK_CTOR(v2);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * 
 *
 * @param array $parameters
 * @return  Phalcon_Model_Resulset
 */
PHP_METHOD(Phalcon_Model_Base, find){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p6[] = { NULL, NULL, NULL, NULL }, *p7[] = { NULL }, *p8[] = { NULL, NULL, NULL, NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	Z_ADDREF_P(v3);
	p6[0] = v3;
	Z_ADDREF_P(v2);
	p6[1] = v2;
	Z_ADDREF_P(v4);
	p6[2] = v4;
	Z_ADDREF_P(v5);
	p6[3] = v5;
	PHALCON_CALL_SELF_PARAMS(r3, this_ptr, "_createsqlselectmulti", 4, p6);
	Z_DELREF_P(p6[0]);
	Z_DELREF_P(p6[1]);
	Z_DELREF_P(p6[2]);
	Z_DELREF_P(p6[3]);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_string(&r5, v6, "sql", strlen("sql"), PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(r5);
	p7[0] = r5;
	PHALCON_CALL_METHOD_PARAMS(r4, v4, "query", 1, p7, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p7[0]);
	PHALCON_CPY_WRT(v7, r4);
	PHALCON_ALLOC_ZVAL_MM(r6);
	Z_ADDREF_P(v2);
	p8[0] = v2;
	Z_ADDREF_P(v4);
	p8[1] = v4;
	Z_ADDREF_P(v6);
	p8[2] = v6;
	Z_ADDREF_P(v7);
	p8[3] = v7;
	PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_createresultset", 4, p8);
	Z_DELREF_P(p8[0]);
	Z_DELREF_P(p8[1]);
	Z_DELREF_P(p8[2]);
	Z_DELREF_P(p8[3]);
	PHALCON_RETURN_DZVAL(r6);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * 
 *
 * @param array $parameters
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, findFirst){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *p3[] = { NULL }, *p5[] = { NULL }, *p9[] = { NULL }, *p11[] = { NULL, NULL, NULL, NULL, NULL }, *p12[] = { NULL }, *p13[] = { NULL }, *p14[] = { NULL, NULL }, *p15[] = { NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_NULL(v0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r4);
	PHALCON_INIT_VAR(v8);
	ZVAL_STRING(v8, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(v5, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v5, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		concat_function(r6, v8, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r6);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, ", ", 1);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CALL_METHOD(r9, v3, "getmetadata", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(v2);
		p9[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r8, r9, "getattributes", 1, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		PHALCON_CALL_FUNC_PARAMS_2(r7, "join", c0, r8, 0x00D);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, v8, r7 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r10);
	}
	if (!PHALCON_COMPARE_STRING(v6, "")) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_LEFT(r12, " FROM ", v6);
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_VBOTH(r11, r12, ".", v7);
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, v8, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r13);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_LEFT(r14, " FROM ", v7);
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, v8, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(v8, r15);
	}
	eval_int = phalcon_array_isset_string(v5, "limit", strlen("limit")+1);
	PHALCON_INIT_VAR(r16);
	ZVAL_BOOL(r16, eval_int);
	if (!zend_is_true(r16)) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		Z_ADDREF_P(t0);
		if (Z_REFCOUNT_P(v5) > 1) {
			zval *new_zv;
			Z_DELREF_P(v5);
			ALLOC_ZVAL(new_zv);
			INIT_PZVAL_COPY(new_zv, v5);
			v5 = new_zv;
			zval_copy_ctor(new_zv);
		}
		phalcon_array_update_string(v5, "limit", strlen("limit"), t0 TSRMLS_CC);
	}
	PHALCON_INIT_VAR(v9);
	ZVAL_BOOL(v9, 0);
	PHALCON_ALLOC_ZVAL_MM(r17);
	Z_ADDREF_P(v3);
	p11[0] = v3;
	Z_ADDREF_P(v2);
	p11[1] = v2;
	Z_ADDREF_P(v4);
	p11[2] = v4;
	Z_ADDREF_P(v8);
	p11[3] = v8;
	Z_ADDREF_P(v5);
	p11[4] = v5;
	PHALCON_CALL_SELF_PARAMS(r17, this_ptr, "_createsqlselectone", 5, p11);
	Z_DELREF_P(p11[0]);
	Z_DELREF_P(p11[1]);
	Z_DELREF_P(p11[2]);
	Z_DELREF_P(p11[3]);
	Z_DELREF_P(p11[4]);
	PHALCON_CPY_WRT(v8, r17);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_class_entry, "DB_ASSOC", strlen("DB_ASSOC") TSRMLS_CC);
	Z_ADDREF_P(t1);
	p12[0] = t1;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p12, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p12[0]);
	PHALCON_ALLOC_ZVAL_MM(r18);
	Z_ADDREF_P(v8);
	p13[0] = v8;
	PHALCON_CALL_METHOD_PARAMS(r18, v4, "fetchone", 1, p13, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p13[0]);
	PHALCON_CPY_WRT(v10, r18);
	if (zend_is_true(v10)) {
		PHALCON_ALLOC_ZVAL_MM(r19);
		Z_ADDREF_P(v2);
		p14[0] = v2;
		Z_ADDREF_P(v10);
		p14[1] = v10;
		PHALCON_CALL_SELF_PARAMS(r19, this_ptr, "dumpresult", 2, p14);
		Z_DELREF_P(p14[0]);
		Z_DELREF_P(p14[1]);
		PHALCON_CPY_WRT(v9, r19);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_get_class_constant(t2, phalcon_db_class_entry, "DB_BOTH", strlen("DB_BOTH") TSRMLS_CC);
	Z_ADDREF_P(t2);
	p15[0] = t2;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v4, "setfetchmode", 1, p15, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p15[0]);
	PHALCON_RETURN_CHECK_CTOR(v9);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p7[] = { NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v0, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v1, r1);
		if (zend_is_true(v0)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_VBOTH(r2, v0, ".", v1);
			PHALCON_CPY_WRT(v2, r2);
		} else {
			PHALCON_CPY_WRT(v2, v1);
		}
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) AS rowcount FROM ", v2, " WHERE ");
		PHALCON_CPY_WRT(v3, r3);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v4, a0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v6, r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", v5, 0x007);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, t1, r6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			if (Z_TYPE_P(v5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah0 = Z_ARRVAL_P(v5);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f9eb_2:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f9eb_2;
				}
				PHALCON_INIT_VAR(v7);
				ZVAL_ZVAL(v7, *hd, 1, 0);
				PHALCON_INIT_VAR(t2);
				phalcon_read_property_zval(&t2, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, t2);
				PHALCON_INIT_VAR(t3);
				ZVAL_NULL(t3);
				PHALCON_INIT_VAR(r8);
				is_not_identical_function(r8, t3, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "", 1);
				PHALCON_INIT_VAR(r9);
				is_not_identical_function(r9, t4, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r10);
				phalcon_and_function(r10, r8, r9);
				if (zend_is_true(r10)) {
					eval_int = phalcon_array_isset(v6, v7);
					if (eval_int) {
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_LEFT(r12, " ", v7);
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, r12, " = ", v8);
						Z_ADDREF_P(r11);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r11 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_LEFT(r14, " ", v7);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_VBOTH(r13, r14, " = '", v8);
						PHALCON_INIT_VAR(r15);
						PHALCON_CONCAT_RIGHT(r15, r13, "'");
						Z_ADDREF_P(r15);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r15 TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f9eb_2;
				fee_f9eb_2:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CALL_FUNC_PARAMS_1(r16, "count", v4, 0x007);
			if (zend_is_true(r16)) {
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r17, "join", c0, v4, 0x00D);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r17 TSRMLS_CC);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_LONG(0);
			}
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r18);
			concat_function(r18, v3, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(v3, r18);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(0);
		}
		PHALCON_ALLOC_ZVAL_MM(r19);
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_read_property(&t6, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(v3);
		p7[0] = v3;
		PHALCON_CALL_METHOD_PARAMS(r19, t6, "fetchone", 1, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		PHALCON_CPY_WRT(v9, r19);
		PHALCON_ALLOC_ZVAL_MM(r20);
		phalcon_array_fetch_string(&r20, v9, "rowcount", strlen("rowcount"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r20);
	} else {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v4, a1);
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CALL_METHOD(r21, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v5, r21);
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_CALL_METHOD(r22, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
		PHALCON_CPY_WRT(v10, r22);
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_CALL_FUNC_PARAMS_1(r23, "count", v5, 0x007);
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 0);
		PHALCON_INIT_VAR(r24);
		is_smaller_function(r24, t7, r23 TSRMLS_CC);
		if (zend_is_true(r24)) {
			if (Z_TYPE_P(v5) != IS_ARRAY) {
				php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
			} else {
				ah1 = Z_ARRVAL_P(v5);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_f9eb_3:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_f9eb_3;
				}
				PHALCON_INIT_VAR(v7);
				ZVAL_ZVAL(v7, *hd, 1, 0);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property_zval(&t8, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				PHALCON_CPY_WRT(v8, t8);
				PHALCON_INIT_VAR(t9);
				ZVAL_NULL(t9);
				PHALCON_INIT_VAR(r25);
				is_not_identical_function(r25, t9, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t10);
				ZVAL_STRING(t10, "", 1);
				PHALCON_INIT_VAR(r26);
				is_not_identical_function(r26, t10, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r27);
				phalcon_and_function(r27, r25, r26);
				if (zend_is_true(r27)) {
					eval_int = phalcon_array_isset(v10, v7);
					if (eval_int) {
						PHALCON_INIT_VAR(r29);
						PHALCON_CONCAT_LEFT(r29, " ", v7);
						PHALCON_INIT_VAR(r28);
						PHALCON_CONCAT_VBOTH(r28, r29, " = ", v8);
						Z_ADDREF_P(r28);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r28 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r31);
						PHALCON_CONCAT_LEFT(r31, " ", v7);
						PHALCON_INIT_VAR(r30);
						PHALCON_CONCAT_VBOTH(r30, r31, " = '", v8);
						PHALCON_INIT_VAR(r32);
						PHALCON_CONCAT_RIGHT(r32, r30, "'");
						Z_ADDREF_P(r32);
						PHALCON_SEPARATE_ARRAY(v4);
						phalcon_array_append(v4, r32 TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_f9eb_3;
				fee_f9eb_3:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "count", v4, 0x007);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r34, "join", c1, v4, 0x00D);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r34 TSRMLS_CC);
				PHALCON_MM_RESTORE();
				RETURN_TRUE;
			} else {
				PHALCON_MM_RESTORE();
				RETURN_LONG(0);
			}
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(0);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p3[] = { NULL }, *p4[] = { NULL, NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v1, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		Z_ADDREF_P(v2);
		p0[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r0, v0, "query", 1, p0, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p0[0]);
		PHALCON_CPY_WRT(v4, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		Z_ADDREF_P(v4);
		p1[0] = v4;
		PHALCON_CALL_METHOD_PARAMS(r1, v0, "numrows", 1, p1, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p1[0]);
		PHALCON_CPY_WRT(v5, r1);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r2);
		is_smaller_function(r2, t0, v5 TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_row_class_entry);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
			PHALCON_CPY_WRT(v6, i0);
			Z_ADDREF_P(v0);
			p3[0] = v0;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(v6, "setconnection", 1, p3, PHALCON_CALL_DEFAULT);
			Z_DELREF_P(p3[0]);
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_class_entry);
			Z_ADDREF_P(v6);
			p4[0] = v6;
			Z_ADDREF_P(v4);
			p4[1] = v4;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p4, PHALCON_CALL_CHECK);
			Z_DELREF_P(p4[0]);
			Z_DELREF_P(p4[1]);
			PHALCON_RETURN_CTOR(i1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_model_resultset_class_entry);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init(i3);
			Z_ADDREF_P(i3);
			p5[0] = i3;
			PHALCON_INIT_VAR(p5[1]);
			ZVAL_BOOL(p5[1], 0);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 2, p5, PHALCON_CALL_CHECK);
			Z_DELREF_P(p5[0]);
			PHALCON_RETURN_CTOR(i2);
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v2);
		p6[0] = v2;
		PHALCON_CALL_METHOD_PARAMS(r3, v0, "fetchone", 1, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		PHALCON_CPY_WRT(v7, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch(&r4, v7, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r4);
	}
	PHALCON_MM_RESTORE();
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
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL;
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!v0) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(v1, r0);
	ce0 = zend_fetch_class(Z_STRVAL_P(v1), Z_STRLEN_P(v1), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	PHALCON_CPY_WRT(v2, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, v1, "getmanager");
	PHALCON_CPY_WRT(v3, r1);
	if (!zend_is_true(v3)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, v3, "getconnection", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r2);
	Z_ADDREF_P(v4);
	p5[0] = v4;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(v2, "setconnection", 1, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	if (Z_TYPE_P(v0) != IS_ARRAY) { 
		if (Z_TYPE_P(v0) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			Z_ADDREF_P(v0);
			PHALCON_SEPARATE_ARRAY(a0);
			add_next_index_zval(a0, v0);
			PHALCON_CPY_WRT(v5, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(v5, a1);
		}
	} else {
		PHALCON_CPY_WRT(v5, v0);
	}
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, v2, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, v2, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r4);
	if (zend_is_true(v6)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, v6, ".", v7);
		PHALCON_CPY_WRT(v8, r5);
	} else {
		PHALCON_CPY_WRT(v8, v7);
	}
	eval_int = phalcon_array_isset_string(v5, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, v5, "distinct", strlen("distinct"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_LEFT(r8, "SELECT COUNT(DISTINCT ", r7);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_VBOTH(r6, r8, ") AS rowcount FROM ", v8);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_RIGHT(r9, r6, " ");
		PHALCON_CPY_WRT(v9, r9);
	} else {
		eval_int = phalcon_array_isset_string(v5, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			phalcon_array_fetch_string(&r11, v5, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r12);
			PHALCON_CONCAT_LEFT(r12, "SELECT ", r11);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, ", COUNT(*) AS rowcount FROM ", v8);
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, " ");
			PHALCON_CPY_WRT(v9, r13);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_BOTH(r14,  "SELECT COUNT(*) AS rowcount FROM ", v8, " ");
			PHALCON_CPY_WRT(v9, r14);
		}
	}
	eval_int = phalcon_array_isset_string(v5, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_array_fetch_string(&r15, v5, "conditions", strlen("conditions"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_BOTH(r16,  " WHERE ", r15, " ");
		PHALCON_ALLOC_ZVAL_MM(r17);
		concat_function(r17, v9, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r17);
	} else {
		eval_int = phalcon_array_isset_long(v5, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, v5, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v10, r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_CALL_FUNC_PARAMS_1(r19, "is_numeric", v10, 0x00B);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CALL_METHOD(r21, v3, "getmetadata", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(v2);
				p9[0] = v2;
				PHALCON_CALL_METHOD_PARAMS(r20, r21, "getprimarykeyattributes", 1, p9, PHALCON_CALL_DEFAULT);
				Z_DELREF_P(p9[0]);
				PHALCON_CPY_WRT(v11, r20);
				eval_int = phalcon_array_isset_long(v11, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r23);
					phalcon_array_fetch_long(&r23, v11, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r24);
					PHALCON_CONCAT_LEFT(r24, " WHERE ", r23);
					PHALCON_ALLOC_ZVAL_MM(r22);
					PHALCON_CONCAT_VBOTH(r22, r24, " = '", v10);
					PHALCON_ALLOC_ZVAL_MM(r25);
					PHALCON_CONCAT_RIGHT(r25, r22, "'");
					PHALCON_ALLOC_ZVAL_MM(r26);
					concat_function(r26, v9, r25 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r26);
				} else {
					PHALCON_INIT_VAR(t0);
					ZVAL_STRING(t0, " WHERE 0=1", 1);
					PHALCON_ALLOC_ZVAL_MM(r27);
					concat_function(r27, v9, t0 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r27);
				}
			} else {
				if (zend_is_true(v10)) {
					PHALCON_ALLOC_ZVAL_MM(r28);
					PHALCON_CONCAT_LEFT(r28, " WHERE ", v10);
					PHALCON_ALLOC_ZVAL_MM(r29);
					concat_function(r29, v9, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(v9, r29);
				}
			}
		}
	}
	eval_int = phalcon_array_isset_string(v5, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r30);
		phalcon_array_fetch_string(&r30, v5, "group", strlen("group"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CONCAT_BOTH(r31,  " GROUP BY ", r30, " ");
		PHALCON_ALLOC_ZVAL_MM(r32);
		concat_function(r32, v9, r31 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r32);
	}
	eval_int = phalcon_array_isset_string(v5, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r33);
		phalcon_array_fetch_string(&r33, v5, "having", strlen("having"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r34);
		PHALCON_CONCAT_BOTH(r34,  " HAVING ", r33, " ");
		PHALCON_ALLOC_ZVAL_MM(r35);
		concat_function(r35, v9, r34 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r35);
	}
	eval_int = phalcon_array_isset_string(v5, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r36);
		phalcon_array_fetch_string(&r36, v5, "order", strlen("order"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r37);
		PHALCON_CONCAT_BOTH(r37,  " ORDER BY ", r36, " ");
		PHALCON_ALLOC_ZVAL_MM(r38);
		concat_function(r38, v9, r37 TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r38);
	}
	eval_int = phalcon_array_isset_string(v5, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		Z_ADDREF_P(v9);
		p11[0] = v9;
		PHALCON_ALLOC_ZVAL_MM(r40);
		phalcon_array_fetch_string(&r40, v5, "limit", strlen("limit"), PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(r40);
		p11[1] = r40;
		PHALCON_CALL_METHOD_PARAMS(r39, v4, "_limit", 2, p11, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p11[0]);
		Z_DELREF_P(p11[1]);
		PHALCON_CPY_WRT(v9, r39);
	}
	PHALCON_ALLOC_ZVAL_MM(r41);
	Z_ADDREF_P(v4);
	p12[0] = v4;
	Z_ADDREF_P(v5);
	p12[1] = v5;
	Z_ADDREF_P(v9);
	p12[2] = v9;
	PHALCON_INIT_VAR(p12[3]);
	ZVAL_STRING(p12[3], "rowcount", 1);
	PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_getgroupresult", 4, p12);
	Z_DELREF_P(p12[0]);
	Z_DELREF_P(p12[1]);
	Z_DELREF_P(p12[2]);
	PHALCON_RETURN_DZVAL(r41);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *v0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (phalcon_method_exists(this_ptr, v0 TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(v0), PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *v0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_BOOL(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, t0, t1 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_get_class_constant(t3, phalcon_model_base_class_entry, "OP_DELETE", strlen("OP_DELETE") TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, t2, t3 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(p0[0]);
			ZVAL_STRING(p0[0], "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		} else {
			PHALCON_INIT_VAR(p1[0]);
			ZVAL_STRING(p1[0], "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "isautomatic");
	if (zend_is_true(r2)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_STATIC(r3, "phalcon_transaction_manager", "getautomatic");
		PHALCON_CPY_WRT(v0, r3);
		Z_ADDREF_P(this_ptr);
		p4[0] = this_ptr;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(v0, "setrollbackedrecord", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		PHALCON_CALL_METHOD_NORETURN(v0, "rollback", PHALCON_CALL_DEFAULT);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(v0) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", v0, 0x02F);
		if (!PHALCON_COMPARE_STRING(r0, "Phalcon_Model_Message")) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_class_entry);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", v0, 0x02F);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Invalid message format '", r1, "'");
			Z_ADDREF_P(r2);
			p1[0] = r2;
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
			Z_DELREF_P(p1[0]);
			zend_throw_exception_object(i0 TSRMLS_CC);
			Z_ADDREF_P(i0);
			PHALCON_MM_RESTORE();
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "gettype", v0, 0x03F);
		Z_DELREF_P(v0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "Invalid message format '", r3, "'");
		Z_ADDREF_P(r4);
		p3[0] = r4;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	phalcon_array_append(t0, v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Executes validators on every validation call
 *
 *
 *
 * @param string $validatorClass
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_Base, validate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL }, *p5[] = { NULL, NULL, NULL, NULL }, *p6[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_Validator_", v0);
	PHALCON_CPY_WRT(v2, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", v2, 0x00F);
	Z_DELREF_P(v2);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Validator '", v0, "' does not exist");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(v1) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Parameter options must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p2, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i1 TSRMLS_CC);
		Z_ADDREF_P(i1);
		PHALCON_MM_RESTORE();
		return;
	}
	eval_int = phalcon_array_isset_string(v1, "field", strlen("field")+1);
	PHALCON_INIT_VAR(r3);
	ZVAL_BOOL(r3, eval_int);
	if (!zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p3[0]);
		ZVAL_STRING(p3[0], "Field name to be validated is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p3, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i2 TSRMLS_CC);
		Z_ADDREF_P(i2);
		PHALCON_MM_RESTORE();
		return;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v1, "field", strlen("field"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r4);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	Z_ADDREF_P(v3);
	PHALCON_CALL_FUNC_PARAMS_1(r5, "is_array", v3, 0x03D);
	Z_DELREF_P(v3);
	PHALCON_INIT_VAR(t0);
	ZVAL_BOOL(t0, 0);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, r5, t0 TSRMLS_CC);
	if (zend_is_true(r6)) {
		ce0 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		Z_ADDREF_P(this_ptr);
		p5[0] = this_ptr;
		Z_ADDREF_P(v3);
		p5[1] = v3;
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property_zval(&t1, this_ptr, v3, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t1);
		p5[2] = t1;
		Z_ADDREF_P(v1);
		p5[3] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 4, p5, PHALCON_CALL_CHECK);
		Z_DELREF_P(p5[0]);
		Z_DELREF_P(p5[1]);
		Z_DELREF_P(p5[2]);
		Z_DELREF_P(p5[3]);
		PHALCON_CPY_WRT(v4, i3);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v5, a0);
		if (Z_TYPE_P(v3) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v3);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_4;
			}
			PHALCON_INIT_VAR(v6);
			ZVAL_ZVAL(v6, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property_zval(&t2, this_ptr, v6, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(t2);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, t2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_4;
			fee_f9eb_4:
			if(0){ };
		}
		ce1 = zend_fetch_class(Z_STRVAL_P(v2), Z_STRLEN_P(v2), ZEND_FETCH_CLASS_DEFAULT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, ce1);
		Z_ADDREF_P(this_ptr);
		p6[0] = this_ptr;
		Z_ADDREF_P(v3);
		p6[1] = v3;
		Z_ADDREF_P(v5);
		p6[2] = v5;
		Z_ADDREF_P(v1);
		p6[3] = v1;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p6, PHALCON_CALL_CHECK);
		Z_DELREF_P(p6[0]);
		Z_DELREF_P(p6[1]);
		Z_DELREF_P(p6[2]);
		Z_DELREF_P(p6[3]);
		PHALCON_CPY_WRT(v4, i4);
	}
	PHALCON_CALL_METHOD_NORETURN(v4, "checkoptions", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, v4, "validate", PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r7) == IS_BOOL && !Z_BVAL_P(r7)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CALL_METHOD(r8, v4, "getmessages", PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r8) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah1 = Z_ARRVAL_P(r8);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_f9eb_5:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_f9eb_5;
			}
			PHALCON_INIT_VAR(v7);
			ZVAL_ZVAL(v7, *hd, 1, 0);
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v7);
			phalcon_array_append(t3, v7 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t3 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_f9eb_5;
			fee_f9eb_5:
			if(0){ };
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Check whether validation process has generated any messages
 *
 *
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, validationHasFailed){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x007);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_INIT_VAR(r1);
	is_smaller_function(r1, t1, r0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Model_Base, _preSave){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL, *v11 = NULL, *v12 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL }, *p10[] = { NULL, NULL, NULL }, *p11[] = { NULL, NULL, NULL }, *p12[] = { NULL }, *p14[] = { NULL }, *p15[] = { NULL }, *p17[] = { NULL }, *p19[] = { NULL }, *p21[] = { NULL }, *p23[] = { NULL }, *p25[] = { NULL }, *p27[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), a0 TSRMLS_CC);
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "beforeValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "beforeValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(p4[0]);
			ZVAL_STRING(p4[0], "beforeValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r2, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_INIT_VAR(v2);
	ZVAL_NULL(v2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "_getnotnullattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v4, r4);
	if (Z_TYPE_P(v3) == IS_ARRAY) { 
		PHALCON_INIT_VAR(v5);
		ZVAL_BOOL(v5, 0);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "count", v3, 0x007);
		PHALCON_CPY_WRT(v6, r5);
		PHALCON_INIT_VAR(v7);
		ZVAL_LONG(v7, 0);
		fs_f9eb_6:
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, v7, v6 TSRMLS_CC);
		if (!zend_is_true(r6)) {
			goto fe_f9eb_6;
		}
		PHALCON_INIT_VAR(v8);
		ZVAL_BOOL(v8, 0);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch(&r7, v3, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v9, r7);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, v9, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, t0);
		eval_int = phalcon_array_isset(v4, v9);
		PHALCON_INIT_VAR(r8);
		ZVAL_BOOL(r8, eval_int);
		if (!zend_is_true(r8)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_NULL(t1);
			PHALCON_INIT_VAR(r9);
			is_identical_function(r9, t1, v10 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r10);
			is_identical_function(r10, t2, v10 TSRMLS_CC);
			PHALCON_INIT_VAR(r11);
			ZVAL_BOOL(r11, zend_is_true(r9) || zend_is_true(r10));
			if (zend_is_true(r11)) {
				PHALCON_INIT_VAR(v8);
				ZVAL_BOOL(v8, 1);
			}
		} else {
			PHALCON_INIT_VAR(r12);
			PHALCON_CALL_FUNC_PARAMS_1(r12, "is_numeric", v10, 0x00B);
			if (!zend_is_true(r12)) {
				PHALCON_INIT_VAR(v8);
				ZVAL_BOOL(v8, 1);
			}
		}
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_INIT_VAR(r13);
		is_equal_function(r13, v8, t3 TSRMLS_CC);
		if (zend_is_true(r13)) {
			PHALCON_INIT_VAR(r14);
			boolean_not_function(r14, v1 TSRMLS_CC);
			PHALCON_INIT_VAR(t4);
			ZVAL_STRING(t4, "id", 1);
			PHALCON_INIT_VAR(r15);
			is_equal_function(r15, v9, t4 TSRMLS_CC);
			PHALCON_INIT_VAR(r16);
			phalcon_and_function(r16, r14, r15);
			if (zend_is_true(r16)) {
				goto fi_f9eb_6;
			}
			PHALCON_INIT_VAR(r17);
			PHALCON_INIT_VAR(p10[0]);
			ZVAL_STRING(p10[0], "_id", 1);
			PHALCON_INIT_VAR(p10[1]);
			ZVAL_STRING(p10[1], "", 1);
			p10[2] = v9;
			PHALCON_CALL_FUNC_PARAMS(r17, "str_replace", 3, p10, 0x003);
			PHALCON_CPY_WRT(v11, r17);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_message_class_entry);
			PHALCON_INIT_VAR(r18);
			PHALCON_CONCAT_RIGHT(r18, v11, " is required");
			Z_ADDREF_P(r18);
			p11[0] = r18;
			Z_ADDREF_P(v9);
			p11[1] = v9;
			PHALCON_INIT_VAR(p11[2]);
			ZVAL_STRING(p11[2], "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 3, p11, PHALCON_CALL_CHECK);
			Z_DELREF_P(p11[0]);
			Z_DELREF_P(p11[1]);
			PHALCON_CPY_WRT(v12, i0);
			PHALCON_INIT_VAR(t5);
			phalcon_read_property(&t5, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
			Z_ADDREF_P(v12);
			phalcon_array_append(t5, v12 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t5 TSRMLS_CC);
			PHALCON_INIT_VAR(v5);
			ZVAL_BOOL(v5, 1);
		}
		fi_f9eb_6:
		PHALCON_SEPARATE(v7);
		increment_function(v7);
		goto fs_f9eb_6;
		fe_f9eb_6:
		if (zend_is_true(v5)) {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p12[0]);
				ZVAL_STRING(p12[0], "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p12, PHALCON_CALL_DEFAULT);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r19);
	PHALCON_INIT_VAR(p14[0]);
	ZVAL_STRING(p14[0], "validation", 1);
	PHALCON_CALL_METHOD_PARAMS(r19, this_ptr, "_callevent", 1, p14, PHALCON_CALL_DEFAULT);
	if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p15[0]);
			ZVAL_STRING(p15[0], "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p15, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	if (!zend_is_true(v0)) {
		if (!zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_INIT_VAR(p17[0]);
			ZVAL_STRING(p17[0], "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r20, this_ptr, "_callevent", 1, p17, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_INIT_VAR(p19[0]);
			ZVAL_STRING(p19[0], "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r21, this_ptr, "_callevent", 1, p19, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_INIT_VAR(p21[0]);
		ZVAL_STRING(p21[0], "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS(r22, this_ptr, "_callevent", 1, p21, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_INIT_VAR(p23[0]);
		ZVAL_STRING(p23[0], "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS(r23, this_ptr, "_callevent", 1, p23, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (zend_is_true(v1)) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(p25[0]);
			ZVAL_STRING(p25[0], "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS(r24, this_ptr, "_callevent", 1, p25, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r24) == IS_BOOL && !Z_BVAL_P(r24)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r25);
			PHALCON_INIT_VAR(p27[0]);
			ZVAL_STRING(p27[0], "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS(r25, this_ptr, "_callevent", 1, p27, PHALCON_CALL_DEFAULT);
			if (Z_TYPE_P(r25) == IS_BOOL && !Z_BVAL_P(r25)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _postSave){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p3[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (zend_is_true(v1)) {
		if (zend_is_true(v2)) {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p0[0]);
				ZVAL_STRING(p0[0], "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p0, PHALCON_CALL_DEFAULT);
			}
		} else {
			if (!zend_is_true(v0)) {
				PHALCON_INIT_VAR(p1[0]);
				ZVAL_STRING(p1[0], "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p1, PHALCON_CALL_DEFAULT);
			}
		}
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p2[0]);
			ZVAL_STRING(p2[0], "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p2, PHALCON_CALL_DEFAULT);
		}
		PHALCON_RETURN_CHECK_CTOR(v1);
	} else {
		if (!zend_is_true(v0)) {
			PHALCON_INIT_VAR(p3[0]);
			ZVAL_STRING(p3[0], "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "_callevent", 1, p3, PHALCON_CALL_DEFAULT);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_CALL_DEFAULT);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _doLowInsert){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL, *v10 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *p2[] = { NULL }, *p4[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v5, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r0);
	if (Z_TYPE_P(v6) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v6);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_7;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		if (!PHALCON_COMPARE_STRING(v7, "id")) {
			Z_ADDREF_P(v7);
			PHALCON_SEPARATE_ARRAY(v4);
			phalcon_array_append(v4, v7 TSRMLS_CC);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property_zval(&t0, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v8, t0);
			if (Z_TYPE_P(v8) == IS_OBJECT) {
				PHALCON_INIT_VAR(r1);
				phalcon_instance_of(r1, v8, phalcon_db_rawvalue_class_entry TSRMLS_CC);
				if (zend_is_true(r1)) {
					PHALCON_INIT_VAR(r2);
					PHALCON_CALL_METHOD(r2, v8, "getvalue", PHALCON_CALL_DEFAULT);
					Z_ADDREF_P(r2);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, r2 TSRMLS_CC);
				} else {
					convert_to_string(v8);
					Z_ADDREF_P(v8);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, v8 TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(t1);
				ZVAL_STRING(t1, "", 1);
				PHALCON_INIT_VAR(r3);
				is_identical_function(r3, t1, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_NULL(t2);
				PHALCON_INIT_VAR(r4);
				is_identical_function(r4, t2, v8 TSRMLS_CC);
				PHALCON_INIT_VAR(r5);
				ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
				if (zend_is_true(r5)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "NULL", 1);
					Z_ADDREF_P(t3);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, t3 TSRMLS_CC);
				} else {
					eval_int = phalcon_array_isset(v3, v7);
					if (eval_int) {
						Z_ADDREF_P(v8);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, v8 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch(&r6, v2, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
						if (PHALCON_COMPARE_STRING(r6, "date")) {
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(t4);
							phalcon_read_property(&t4, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
							Z_ADDREF_P(v8);
							p2[0] = v8;
							PHALCON_CALL_METHOD_PARAMS(r7, t4, "getdateusingformat", 1, p2, PHALCON_CALL_DEFAULT);
							Z_DELREF_P(p2[0]);
							Z_ADDREF_P(r7);
							PHALCON_SEPARATE_ARRAY(v5);
							phalcon_array_append(v5, r7 TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(r8);
							PHALCON_CONCAT_BOTH(r8,  "'", v8, "'");
							Z_ADDREF_P(r8);
							PHALCON_SEPARATE_ARRAY(v5);
							phalcon_array_append(v5, r8 TSRMLS_CC);
						}
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_7;
		fee_f9eb_7:
		if(0){ };
	}
	PHALCON_INIT_VAR(v9);
	ZVAL_STRING(v9, "", 1);
	eval_int = phalcon_isset_property(this_ptr, "id", strlen("id") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "id", sizeof("id")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v10, t5);
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "id", 1);
		Z_ADDREF_P(t6);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, t6 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r9);
		Z_ADDREF_P(v10);
		PHALCON_CALL_FUNC_PARAMS_1(r9, "is_null", v10, 0x040);
		Z_DELREF_P(v10);
		PHALCON_INIT_VAR(t7);
		ZVAL_STRING(t7, "", 1);
		PHALCON_INIT_VAR(r10);
		is_identical_function(r10, t7, v10 TSRMLS_CC);
		PHALCON_INIT_VAR(r11);
		ZVAL_BOOL(r11, zend_is_true(r9) || zend_is_true(r10));
		if (zend_is_true(r11)) {
			PHALCON_INIT_VAR(t8);
			ZVAL_STRING(t8, "null", 1);
			Z_ADDREF_P(t8);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, t8 TSRMLS_CC);
		} else {
			Z_ADDREF_P(v10);
			PHALCON_SEPARATE_ARRAY(v5);
			phalcon_array_append(v5, v10 TSRMLS_CC);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	Z_ADDREF_P(v1);
	p4[0] = v1;
	Z_ADDREF_P(v5);
	p4[1] = v5;
	Z_ADDREF_P(v4);
	p4[2] = v4;
	PHALCON_CALL_METHOD_PARAMS(r12, v0, "insert", 3, p4, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p4[0]);
	Z_DELREF_P(p4[1]);
	Z_DELREF_P(p4[2]);
	PHALCON_RETURN_DZVAL(r12);
}

PHP_METHOD(Phalcon_Model_Base, _doLowUpdate){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL, *v6 = NULL;
	zval *v7 = NULL, *v8 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *p2[] = { NULL }, *p3[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &v0, &v1, &v2, &v3) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(v4, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(v5, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getnonprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r0);
	if (Z_TYPE_P(v6) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(v6);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_8;
		}
		PHALCON_INIT_VAR(v7);
		ZVAL_ZVAL(v7, *hd, 1, 0);
		Z_ADDREF_P(v7);
		PHALCON_SEPARATE_ARRAY(v4);
		phalcon_array_append(v4, v7 TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v8, t0);
		if (Z_TYPE_P(v8) == IS_OBJECT) {
			PHALCON_INIT_VAR(r1);
			phalcon_instance_of(r1, v8, phalcon_db_rawvalue_class_entry TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_METHOD(r2, v8, "getvalue", PHALCON_CALL_DEFAULT);
				Z_ADDREF_P(r2);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, r2 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(t1);
				phalcon_read_property_zval(&t1, this_ptr, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
				convert_to_string(t1);
				Z_ADDREF_P(t1);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, t1 TSRMLS_CC);
			}
		} else {
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r3);
			is_identical_function(r3, t2, v8 TSRMLS_CC);
			PHALCON_INIT_VAR(t3);
			ZVAL_NULL(t3);
			PHALCON_INIT_VAR(r4);
			is_identical_function(r4, t3, v8 TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
			if (zend_is_true(r5)) {
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "NULL", 1);
				Z_ADDREF_P(t4);
				PHALCON_SEPARATE_ARRAY(v5);
				phalcon_array_append(v5, t4 TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset(v3, v7);
				if (eval_int) {
					Z_ADDREF_P(v8);
					PHALCON_SEPARATE_ARRAY(v5);
					phalcon_array_append(v5, v8 TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, v2, v7, PHALCON_NOISY_FETCH TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r6, "date")) {
						PHALCON_INIT_VAR(r7);
						Z_ADDREF_P(v8);
						p2[0] = v8;
						PHALCON_CALL_METHOD_PARAMS(r7, v0, "getdateusingformat", 1, p2, PHALCON_CALL_DEFAULT);
						Z_DELREF_P(p2[0]);
						Z_ADDREF_P(r7);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, r7 TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r8);
						PHALCON_CONCAT_BOTH(r8,  "'", v8, "'");
						Z_ADDREF_P(r8);
						PHALCON_SEPARATE_ARRAY(v5);
						phalcon_array_append(v5, r8 TSRMLS_CC);
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_8;
		fee_f9eb_8:
		if(0){ };
	}
	PHALCON_ALLOC_ZVAL_MM(r9);
	Z_ADDREF_P(v1);
	p3[0] = v1;
	Z_ADDREF_P(v4);
	p3[1] = v4;
	Z_ADDREF_P(v5);
	p3[2] = v5;
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t5);
	p3[3] = t5;
	PHALCON_CALL_METHOD_PARAMS(r9, v0, "update", 4, p3, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p3[0]);
	Z_DELREF_P(p3[1]);
	Z_DELREF_P(p3[2]);
	Z_DELREF_P(p3[3]);
	PHALCON_RETURN_DZVAL(r9);
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
	zval *v7 = NULL, *v8 = NULL, *v9 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *p2[] = { NULL, NULL }, *p8[] = { NULL, NULL, NULL, NULL }, *p9[] = { NULL, NULL, NULL, NULL }, *p13[] = { NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v0, r0);
	if (!zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_get_class_constant(t0, phalcon_model_base_class_entry, "OP_CREATE", strlen("OP_CREATE") TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), t0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_get_class_constant(t1, phalcon_model_base_class_entry, "OP_UPDATE", strlen("OP_UPDATE") TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), t1 TSRMLS_CC);
	}
	t2 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v1, t2);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(v1);
	p2[0] = v1;
	Z_ADDREF_P(v0);
	p2[1] = v0;
	PHALCON_CALL_METHOD_PARAMS(r1, this_ptr, "_presave", 2, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	Z_DELREF_P(p2[1]);
	if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getschema", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v2, r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getsource", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v3, r3);
	if (zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, v2, ".", v3);
		PHALCON_CPY_WRT(v4, r4);
	} else {
		PHALCON_CPY_WRT(v4, v3);
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t3);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v6, r5);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v7, r6);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, this_ptr, "_getdatatypesnumeric", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v8, r7);
	if (zend_is_true(v0)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		Z_ADDREF_P(v5);
		p8[0] = v5;
		Z_ADDREF_P(v4);
		p8[1] = v4;
		Z_ADDREF_P(v6);
		p8[2] = v6;
		Z_ADDREF_P(v8);
		p8[3] = v8;
		PHALCON_CALL_METHOD_PARAMS(r8, this_ptr, "_dolowupdate", 4, p8, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p8[0]);
		Z_DELREF_P(p8[1]);
		Z_DELREF_P(p8[2]);
		Z_DELREF_P(p8[3]);
		PHALCON_CPY_WRT(v9, r8);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r9);
		Z_ADDREF_P(v5);
		p9[0] = v5;
		Z_ADDREF_P(v4);
		p9[1] = v4;
		Z_ADDREF_P(v6);
		p9[2] = v6;
		Z_ADDREF_P(v8);
		p9[3] = v8;
		PHALCON_CALL_METHOD_PARAMS(r9, this_ptr, "_dolowinsert", 4, p9, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p9[0]);
		Z_DELREF_P(p9[1]);
		Z_DELREF_P(p9[2]);
		Z_DELREF_P(p9[3]);
		PHALCON_CPY_WRT(v9, r9);
	}
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, v5, "isundertransaction", PHALCON_CALL_DEFAULT);
	if (!zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, v5, "gethaveautocommit", PHALCON_CALL_DEFAULT);
		if (zend_is_true(r11)) {
			PHALCON_CALL_METHOD_NORETURN(v5, "commit", PHALCON_CALL_DEFAULT);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	Z_ADDREF_P(v1);
	p13[0] = v1;
	Z_ADDREF_P(v9);
	p13[1] = v9;
	Z_ADDREF_P(v0);
	p13[2] = v0;
	PHALCON_CALL_METHOD_PARAMS(r12, this_ptr, "_postsave", 3, p13, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p13[0]);
	Z_DELREF_P(p13[1]);
	Z_DELREF_P(p13[2]);
	PHALCON_RETURN_DZVAL(r12);
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
	zval *c0 = NULL;
	zval *p4[] = { NULL }, *p5[] = { NULL, NULL }, *p6[] = { NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, t1, ".", t2);
		PHALCON_CPY_WRT(v0, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v0, t3);
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_get_class_constant(t4, phalcon_model_base_class_entry, "OP_DELETE", strlen("OP_DELETE") TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_operationMade", strlen("_operationMade"), t4 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_CALL_DEFAULT);
	PHALCON_CPY_WRT(v1, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", v1, 0x007);
	PHALCON_INIT_VAR(t5);
	ZVAL_LONG(t5, 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, r2, t5 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(t6);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_read_property_zval(&t6, this_ptr, r4, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, t6);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_long(&r6, v1, 0, PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, " = '", v2);
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_RIGHT(r7, r5, "'");
		PHALCON_CPY_WRT(v3, r7);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v3, a0);
		if (Z_TYPE_P(v1) != IS_ARRAY) {
			php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
		} else {
			ah0 = Z_ARRVAL_P(v1);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_9:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_9;
			}
			PHALCON_INIT_VAR(v4);
			ZVAL_ZVAL(v4, *hd, 1, 0);
			PHALCON_INIT_VAR(t7);
			phalcon_read_property_zval(&t7, this_ptr, v4, PHALCON_NOISY_FETCH TSRMLS_CC);
			PHALCON_CPY_WRT(v2, t7);
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VBOTH(r8, v4, " = '", v2);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "'");
			Z_ADDREF_P(r9);
			PHALCON_SEPARATE_ARRAY(v3);
			phalcon_array_append(v3, r9 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_9;
			fee_f9eb_9:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r10, "join", c0, v3, 0x00D);
		PHALCON_CPY_WRT(v3, r10);
	}
	t8 = zend_read_static_property(phalcon_model_base_class_entry, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(v5, t8);
	if (!zend_is_true(v5)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_INIT_VAR(p4[0]);
		ZVAL_STRING(p4[0], "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS(r11, this_ptr, "_callevent", 1, p4, PHALCON_CALL_DEFAULT);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_read_property(&t9, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p5[0] = v0;
	Z_ADDREF_P(v3);
	p5[1] = v3;
	PHALCON_CALL_METHOD_PARAMS(r12, t9, "delete", 2, p5, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p5[0]);
	Z_DELREF_P(p5[1]);
	PHALCON_CPY_WRT(v6, r12);
	if (zend_is_true(v6)) {
		if (!zend_is_true(v5)) {
			PHALCON_INIT_VAR(p6[0]);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dump", sizeof("_dump")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property_zval(&t1, this_ptr, v0, PHALCON_NOISY_FETCH TSRMLS_CC);
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_CALL_DEFAULT);
	}
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(v0), Z_STRLEN_P(v0), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
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
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
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
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
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

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
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
		Z_DELREF_P(p0[0]);
		Z_DELREF_P(p0[1]);
		Z_DELREF_P(p0[2]);
		Z_DELREF_P(p0[3]);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
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
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL, *a8 = NULL, *a9 = NULL, *a10 = NULL, *a11 = NULL, *a12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL, NULL, NULL }, *p4[] = { NULL, NULL }, *p7[] = { NULL, NULL }, *p10[] = { NULL, NULL }, *p13[] = { NULL, NULL, NULL }, *p17[] = { NULL, NULL }, *p20[] = { NULL, NULL }, *p23[] = { NULL, NULL }, *p26[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(v1, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	p0[0] = v0;
	PHALCON_INIT_VAR(p0[1]);
	ZVAL_LONG(p0[1], 0);
	PHALCON_INIT_VAR(p0[2]);
	ZVAL_LONG(p0[2], 3);
	PHALCON_CALL_FUNC_PARAMS(r0, "substr", 3, p0, 0x002);
	Z_DELREF_P(p0[0]);
	if (PHALCON_COMPARE_STRING(r0, "get")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x02F);
		PHALCON_CPY_WRT(v2, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c0);
		ZVAL_LONG(c0, 3);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", v0, c0, 0x002);
		Z_DELREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "ucfirst", r3, 0x041);
		PHALCON_CPY_WRT(v3, r2);
		t0 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		Z_ADDREF_P(v2);
		p4[0] = v2;
		Z_ADDREF_P(v3);
		p4[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r4, v4, "existsbelongsto", 2, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
		Z_DELREF_P(p4[1]);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			add_next_index_stringl(a1, "findFirst", strlen("findFirst"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a1);
			add_next_index_zval(a1, this_ptr);
			PHALCON_CPY_WRT(v5, a1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a2);
			add_next_index_zval(a2, v4);
			add_next_index_stringl(a2, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a2);
			PHALCON_ALLOC_ZVAL_MM(r6);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r6, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r6);
			PHALCON_CALL_FUNC_PARAMS_2(r5, "call_user_func_array", a2, r6, 0x010);
			Z_DELREF_P(a2);
			Z_DELREF_P(r6);
			PHALCON_RETURN_DZVAL(r5);
		}
		PHALCON_ALLOC_ZVAL_MM(r7);
		Z_ADDREF_P(v2);
		p7[0] = v2;
		Z_ADDREF_P(v3);
		p7[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r7, v4, "existshasmany", 2, p7, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p7[0]);
		Z_DELREF_P(p7[1]);
		if (zend_is_true(r7)) {
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			add_next_index_stringl(a3, "find", strlen("find"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a3);
			add_next_index_zval(a3, this_ptr);
			PHALCON_CPY_WRT(v5, a3);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a4);
			add_next_index_zval(a4, v4);
			add_next_index_stringl(a4, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a4);
			PHALCON_ALLOC_ZVAL_MM(r9);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r9, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r9);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "call_user_func_array", a4, r9, 0x010);
			Z_DELREF_P(a4);
			Z_DELREF_P(r9);
			PHALCON_RETURN_DZVAL(r8);
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		Z_ADDREF_P(v2);
		p10[0] = v2;
		Z_ADDREF_P(v3);
		p10[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r10, v4, "existshasone", 2, p10, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p10[0]);
		Z_DELREF_P(p10[1]);
		if (zend_is_true(r10)) {
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			add_next_index_stringl(a5, "findFirst", strlen("findFirst"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a5);
			add_next_index_zval(a5, this_ptr);
			PHALCON_CPY_WRT(v5, a5);
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a6);
			add_next_index_zval(a6, v4);
			add_next_index_stringl(a6, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a6);
			PHALCON_ALLOC_ZVAL_MM(r12);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r12);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "call_user_func_array", a6, r12, 0x010);
			Z_DELREF_P(a6);
			Z_DELREF_P(r12);
			PHALCON_RETURN_DZVAL(r11);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r13);
	Z_ADDREF_P(v0);
	p13[0] = v0;
	PHALCON_INIT_VAR(p13[1]);
	ZVAL_LONG(p13[1], 0);
	PHALCON_INIT_VAR(p13[2]);
	ZVAL_LONG(p13[2], 5);
	PHALCON_CALL_FUNC_PARAMS(r13, "substr", 3, p13, 0x002);
	Z_DELREF_P(p13[0]);
	if (PHALCON_COMPARE_STRING(r13, "count")) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_FUNC_PARAMS_1(r14, "get_class", this_ptr, 0x02F);
		PHALCON_CPY_WRT(v2, r14);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_ALLOC_ZVAL_MM(r16);
		Z_ADDREF_P(v0);
		PHALCON_INIT_VAR(c1);
		ZVAL_LONG(c1, 5);
		PHALCON_CALL_FUNC_PARAMS_2(r16, "substr", v0, c1, 0x002);
		Z_DELREF_P(v0);
		PHALCON_CALL_FUNC_PARAMS_1(r15, "ucfirst", r16, 0x041);
		PHALCON_CPY_WRT(v3, r15);
		t1 = zend_read_static_property(phalcon_model_base_class_entry, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(v4, t1);
		PHALCON_ALLOC_ZVAL_MM(r17);
		Z_ADDREF_P(v2);
		p17[0] = v2;
		Z_ADDREF_P(v3);
		p17[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r17, v4, "existsbelongsto", 2, p17, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p17[0]);
		Z_DELREF_P(p17[1]);
		if (zend_is_true(r17)) {
			PHALCON_INIT_VAR(a7);
			array_init(a7);
			add_next_index_stringl(a7, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a7);
			add_next_index_zval(a7, this_ptr);
			PHALCON_CPY_WRT(v5, a7);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(a8);
			array_init(a8);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a8);
			add_next_index_zval(a8, v4);
			add_next_index_stringl(a8, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a8);
			PHALCON_ALLOC_ZVAL_MM(r19);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r19);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "call_user_func_array", a8, r19, 0x010);
			Z_DELREF_P(a8);
			Z_DELREF_P(r19);
			PHALCON_RETURN_DZVAL(r18);
		}
		PHALCON_ALLOC_ZVAL_MM(r20);
		Z_ADDREF_P(v2);
		p20[0] = v2;
		Z_ADDREF_P(v3);
		p20[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r20, v4, "existshasmany", 2, p20, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p20[0]);
		Z_DELREF_P(p20[1]);
		if (zend_is_true(r20)) {
			PHALCON_INIT_VAR(a9);
			array_init(a9);
			add_next_index_stringl(a9, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a9);
			add_next_index_zval(a9, this_ptr);
			PHALCON_CPY_WRT(v5, a9);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_INIT_VAR(a10);
			array_init(a10);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a10);
			add_next_index_zval(a10, v4);
			add_next_index_stringl(a10, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a10);
			PHALCON_ALLOC_ZVAL_MM(r22);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r22, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r22);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "call_user_func_array", a10, r22, 0x010);
			Z_DELREF_P(a10);
			Z_DELREF_P(r22);
			PHALCON_RETURN_DZVAL(r21);
		}
		PHALCON_ALLOC_ZVAL_MM(r23);
		Z_ADDREF_P(v2);
		p23[0] = v2;
		Z_ADDREF_P(v3);
		p23[1] = v3;
		PHALCON_CALL_METHOD_PARAMS(r23, v4, "existshasone", 2, p23, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p23[0]);
		Z_DELREF_P(p23[1]);
		if (zend_is_true(r23)) {
			PHALCON_INIT_VAR(a11);
			array_init(a11);
			add_next_index_stringl(a11, "count", strlen("count"), 1);
			Z_ADDREF_P(v2);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, v2);
			Z_ADDREF_P(v3);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, v3);
			Z_ADDREF_P(this_ptr);
			PHALCON_SEPARATE_ARRAY(a11);
			add_next_index_zval(a11, this_ptr);
			PHALCON_CPY_WRT(v5, a11);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(a12);
			array_init(a12);
			Z_ADDREF_P(v4);
			PHALCON_SEPARATE_ARRAY(a12);
			add_next_index_zval(a12, v4);
			add_next_index_stringl(a12, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a12);
			PHALCON_ALLOC_ZVAL_MM(r25);
			Z_ADDREF_P(v5);
			Z_ADDREF_P(v1);
			PHALCON_CALL_FUNC_PARAMS_2(r25, "array_merge", v5, v1, 0x042);
			Z_DELREF_P(v5);
			Z_DELREF_P(v1);
			Z_ADDREF_P(r25);
			PHALCON_CALL_FUNC_PARAMS_2(r24, "call_user_func_array", a12, r25, 0x010);
			Z_DELREF_P(a12);
			Z_DELREF_P(r25);
			PHALCON_RETURN_DZVAL(r24);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_class_entry);
	PHALCON_ALLOC_ZVAL_MM(r27);
	PHALCON_CONCAT_LEFT(r27, "Method \"", v0);
	PHALCON_ALLOC_ZVAL_MM(r28);
	PHALCON_CALL_FUNC_PARAMS_1(r28, "get_class", this_ptr, 0x02F);
	PHALCON_ALLOC_ZVAL_MM(r26);
	PHALCON_CONCAT_VBOTH(r26, r27, "\" doesn't exist on model \"", r28);
	PHALCON_ALLOC_ZVAL_MM(r29);
	PHALCON_CONCAT_RIGHT(r29, r26, "\"");
	Z_ADDREF_P(r29);
	p26[0] = r29;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p26, PHALCON_CALL_CHECK);
	Z_DELREF_P(p26[0]);
	zend_throw_exception_object(i0 TSRMLS_CC);
	Z_ADDREF_P(i0);
	PHALCON_MM_RESTORE();
	return;
}

