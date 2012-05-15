
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

	zval *manager = NULL, *class_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!manager) {
		PHALCON_INIT_VAR(manager);
		ZVAL_NULL(manager);
	}
	
	if (!zend_is_true(manager)) {
		t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		if (!zend_is_true(t0)) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_STATIC(r1, "phalcon_controller_front", "getinstance");
			PHALCON_CALL_METHOD(r0, r1, "getmodelcomponent", PHALCON_NO_CHECK);
			zend_update_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, r0 TSRMLS_CC);
		}
	} else {
		zend_update_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, manager TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "get_class", this_ptr, 0x02E);
	PHALCON_CPY_WRT(class_name, r2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_initialized", sizeof("_initialized")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t1)) {
		if (phalcon_method_exists_ex(this_ptr, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_NO_CHECK);
		}
		zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_initialized", strlen("_initialized"), 1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
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
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Internal method to get table mapped attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes that are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getprimarykeyattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes which are not part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getnonprimarykeyattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get attributes that are part of table mapped primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getnotnullattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get numerical-typed attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getdatatypesnumeric", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get data-types attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, _getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getdatatypes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Internal method to get identity field
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, _getIdentityField){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getidentityfield", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Dumps mapped table meta-data
 *
 * @return Phalcon_Model_Base
 */
PHP_METHOD(Phalcon_Model_Base, dump){

	zval *attributes = NULL, *field = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_dumpLock", strlen("_dumpLock"), 1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t1, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(attributes, r0);
	if (phalcon_valid_foreach(attributes TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_0;
		}
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
		if (!eval_int) {
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			phalcon_update_property_zval(this_ptr, Z_STRVAL_P(field), Z_STRLEN_P(field), t2 TSRMLS_CC);
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

	zval *manager = NULL, *model = NULL, *connection = NULL, *params = NULL, *meta_data = NULL;
	zval *source = NULL, *schema = NULL, *select = NULL, *number_rows = NULL, *primary_keys = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &manager, &model, &connection, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	PHALCON_SEPARATE_PARAM(params);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, manager, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(meta_data, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(source, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r2);
	PHALCON_INIT_VAR(select);
	ZVAL_STRING(select, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(params, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, params, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, select, r3 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r4);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_METHOD_PARAMS_1(r6, meta_data, "getattributes", model, PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r5, connection, "getcolumnlist", r6, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r7);
		concat_function(r7, select, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r7);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_LEFT(r9, " FROM ", schema);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_VBOTH(r8, r9, ".", source);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, select, r8 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r10);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_LEFT(r11, " FROM ", source);
		PHALCON_ALLOC_ZVAL_MM(r12);
		concat_function(r12, select, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r12);
	}
	
	PHALCON_INIT_VAR(number_rows);
	ZVAL_STRING(number_rows, "n", 1);
	eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r13);
		phalcon_array_fetch_string(&r13, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_BOTH(r14,  " WHERE ", r13, " ");
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, select, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r15);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CALL_METHOD_PARAMS_1(r16, meta_data, "getprimarykeyattributes", model, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r16);
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r17);
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, params, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r17, "is_numeric", r18, 0x027);
			if (zend_is_true(r17)) {
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r20);
					phalcon_array_fetch_long(&r20, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r21);
					PHALCON_ALLOC_ZVAL_MM(r22);
					phalcon_array_fetch_long(&r22, params, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS_1(r21, connection, "addquotes", r22, PHALCON_NO_CHECK);
					PHALCON_ALLOC_ZVAL_MM(r19);
					PHALCON_CONCAT_VBOTH(r19, r20, " = ", r21);
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), r19, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					PHALCON_INIT_VAR(number_rows);
					ZVAL_STRING(number_rows, "1", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_ce);
					PHALCON_INIT_VAR(c0);
					ZVAL_STRING(c0, "Has not been defined a primary key for source related to this model", 1);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL_MM(r23);
				phalcon_array_fetch_long(&r23, params, 0, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_INIT_VAR(r24);
				is_identical_function(r24, t0, r23 TSRMLS_CC);
				if (zend_is_true(r24)) {
					eval_int = phalcon_array_isset_long(primary_keys, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL_MM(r25);
						phalcon_array_fetch_long(&r25, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r26);
						PHALCON_CONCAT_RIGHT(r26, r25, " = ''");
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), r26, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_model_exception_ce);
						PHALCON_INIT_VAR(c1);
						ZVAL_STRING(c1, "Has not been defined a primary key for source related to this model", 1);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
						phalcon_throw_exception(i1 TSRMLS_CC);
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r27);
					phalcon_array_fetch_long(&r27, params, 0, PHALCON_NOISY TSRMLS_CC);
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), r27, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				PHALCON_INIT_VAR(number_rows);
				ZVAL_STRING(number_rows, "n", 1);
			}
		}
		eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r28);
			phalcon_array_fetch_string(&r28, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r29);
			PHALCON_CONCAT_LEFT(r29, " WHERE ", r28);
			PHALCON_ALLOC_ZVAL_MM(r30);
			concat_function(r30, select, r29 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r30);
		}
	}
	eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r31);
		phalcon_array_fetch_string(&r31, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r31)) {
			PHALCON_ALLOC_ZVAL_MM(r32);
			phalcon_array_fetch_string(&r32, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CONCAT_LEFT(r33, " GROUP BY ", r32);
			PHALCON_ALLOC_ZVAL_MM(r34);
			concat_function(r34, select, r33 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r34);
		}
		
	}
	
	eval_int = phalcon_array_isset_string(params, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r35);
		phalcon_array_fetch_string(&r35, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r35)) {
			PHALCON_ALLOC_ZVAL_MM(r36);
			phalcon_array_fetch_string(&r36, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r37);
			PHALCON_CONCAT_LEFT(r37, " ORDER BY ", r36);
			PHALCON_ALLOC_ZVAL_MM(r38);
			concat_function(r38, select, r37 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r38);
		}
		
	}
	
	eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		phalcon_array_fetch_string(&r39, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r39)) {
			PHALCON_ALLOC_ZVAL_MM(r40);
			PHALCON_ALLOC_ZVAL_MM(r41);
			phalcon_array_fetch_string(&r41, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_2(r40, connection, "limit", select, r41, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r40);
		}
		
	}
	
	eval_int = phalcon_array_isset_string(params, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r42);
		phalcon_array_fetch_string(&r42, params, "for_update", strlen("for_update"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r42)) {
			PHALCON_ALLOC_ZVAL_MM(r43);
			PHALCON_CALL_METHOD_PARAMS_1(r43, connection, "forupdate", select, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r43);
		}
		
	}
	
	eval_int = phalcon_array_isset_string(params, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r44);
		phalcon_array_fetch_string(&r44, params, "shared_lock", strlen("shared_lock"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r44)) {
			PHALCON_ALLOC_ZVAL_MM(r45);
			PHALCON_CALL_METHOD_PARAMS_1(r45, connection, "sharedlock", select, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r45);
		}
		
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_array_update_string(&a0, "return", strlen("return"), number_rows, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a0, "sql", strlen("sql"), select, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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

	zval *manager = NULL, *model = NULL, *connection = NULL, *select = NULL, *params = NULL;
	zval *primary_keys = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &manager, &model, &connection, &select, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	PHALCON_SEPARATE_PARAM(select);
	
	if (!params) {
		PHALCON_INIT_VAR(params);
		ZVAL_STRING(params, "", 1);
	} else {
		PHALCON_SEPARATE_PARAM(params);
	}
	
	if (Z_TYPE_P(params) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_array_fetch_string(&r0, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r0)) {
				PHALCON_ALLOC_ZVAL_MM(r1);
				phalcon_array_fetch_string(&r1, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CONCAT_BOTH(r2,  " WHERE ", r1, " ");
				PHALCON_ALLOC_ZVAL_MM(r3);
				concat_function(r3, select, r2 TSRMLS_CC);
				PHALCON_CPY_WRT(select, r3);
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_CALL_METHOD(r5, manager, "getmetadata", PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1(r4, r5, "getprimarykeyattributes", model, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(primary_keys, r4);
			eval_int = phalcon_array_isset_long(params, 0);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r6);
				PHALCON_ALLOC_ZVAL_MM(r7);
				phalcon_array_fetch_long(&r7, params, 0, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CALL_FUNC_PARAMS_1(r6, "is_numeric", r7, 0x027);
				if (zend_is_true(r6)) {
					PHALCON_ALLOC_ZVAL_MM(r9);
					phalcon_array_fetch_long(&r9, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r10);
					phalcon_array_fetch_long(&r10, params, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, " = '", r10);
					PHALCON_ALLOC_ZVAL_MM(r11);
					PHALCON_CONCAT_RIGHT(r11, r8, "'");
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), r11, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r12);
					phalcon_array_fetch_long(&r12, params, 0, PHALCON_NOISY TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r12, "")) {
						PHALCON_ALLOC_ZVAL_MM(r13);
						phalcon_array_fetch_long(&r13, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r14);
						PHALCON_CONCAT_RIGHT(r14, r13, " = ''");
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), r14, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(r15);
						phalcon_array_fetch_long(&r15, params, 0, PHALCON_NOISY TSRMLS_CC);
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), r15, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					}
					
				}
				
			}
			
			eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
			if (eval_int) {
				PHALCON_ALLOC_ZVAL_MM(r16);
				phalcon_array_fetch_string(&r16, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_CONCAT_LEFT(r17, " WHERE ", r16);
				PHALCON_ALLOC_ZVAL_MM(r18);
				concat_function(r18, select, r17 TSRMLS_CC);
				PHALCON_CPY_WRT(select, r18);
			}
			
		}
		
		eval_int = phalcon_array_isset_string(params, "order", strlen("order")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r19);
			phalcon_array_fetch_string(&r19, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				phalcon_array_fetch_string(&r20, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CONCAT_LEFT(r21, " ORDER BY ", r20);
				PHALCON_ALLOC_ZVAL_MM(r22);
				concat_function(r22, select, r21 TSRMLS_CC);
				PHALCON_CPY_WRT(select, r22);
			}
			
		} else {
			PHALCON_INIT_VAR(t0);
			ZVAL_STRING(t0, " ORDER BY 1", 1);
			PHALCON_ALLOC_ZVAL_MM(r23);
			concat_function(r23, select, t0 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r23);
		}
		
		eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r24);
			phalcon_array_fetch_string(&r24, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r24)) {
				PHALCON_ALLOC_ZVAL_MM(r25);
				PHALCON_ALLOC_ZVAL_MM(r26);
				phalcon_array_fetch_string(&r26, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CALL_METHOD_PARAMS_2(r25, connection, "limit", select, r26, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(select, r25);
			}
			
		}
		
		eval_int = phalcon_array_isset_string(params, "for_update", strlen("for_update")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r27);
			phalcon_array_fetch_string(&r27, params, "for_update", strlen("for_update"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r27)) {
				PHALCON_ALLOC_ZVAL_MM(r28);
				PHALCON_CALL_METHOD_PARAMS_1(r28, connection, "forupdate", select, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(select, r28);
			}
			
		}
		
		eval_int = phalcon_array_isset_string(params, "shared_lock", strlen("shared_lock")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r29);
			phalcon_array_fetch_string(&r29, params, "shared_lock", strlen("shared_lock"), PHALCON_NOISY TSRMLS_CC);
			if (zend_is_true(r29)) {
				PHALCON_ALLOC_ZVAL_MM(r30);
				PHALCON_CALL_METHOD_PARAMS_1(r30, connection, "sharedlock", select, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(select, r30);
			}
			
		}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CALL_FUNC_PARAMS_1(r31, "strlen", params, 0x001);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r32);
		is_smaller_function(r32, t1, r31 TSRMLS_CC);
		if (zend_is_true(r32)) {
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "is_numeric", params, 0x027);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r35);
				phalcon_array_fetch_long(&r35, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
				PHALCON_ALLOC_ZVAL_MM(r36);
				PHALCON_CONCAT_LEFT(r36, "WHERE ", r35);
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_CONCAT_VBOTH(r34, r36, " = '", params);
				PHALCON_ALLOC_ZVAL_MM(r37);
				PHALCON_CONCAT_RIGHT(r37, r34, "'");
				PHALCON_ALLOC_ZVAL_MM(r38);
				concat_function(r38, select, r37 TSRMLS_CC);
				PHALCON_CPY_WRT(select, r38);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r39);
				PHALCON_CONCAT_LEFT(r39, "WHERE ", params);
				PHALCON_ALLOC_ZVAL_MM(r40);
				concat_function(r40, select, r39 TSRMLS_CC);
				PHALCON_CPY_WRT(select, r40);
			}
			
		}
		
	}
	
	PHALCON_RETURN_CHECK_CTOR(select);
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

	zval *model = NULL, *connection = NULL, *select = NULL, *result_resource = NULL;
	zval *unique_row = NULL, *count = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL, *i1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &model, &connection, &select, &result_resource) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, select, "return", strlen("return"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "1", 1);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t0 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD_PARAMS_1(r2, connection, "numrows", result_resource, PHALCON_NO_CHECK);
		if (!zend_is_true(r2)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		} else {
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c0, PHALCON_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD_PARAMS_1(r3, connection, "fetcharray", result_resource, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(unique_row, r3);
			PHALCON_INIT_VAR(c1);
			ZVAL_LONG(c1, 2);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c1, PHALCON_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_SELF_PARAMS_1(r4, this_ptr, "dumpresult", unique_row);
			PHALCON_RETURN_DZVAL(r4);
		}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD_PARAMS_1(r5, connection, "numrows", result_resource, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(count, r5);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, t1, count TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_resultset_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", model, result_resource, PHALCON_CHECK);
			PHALCON_RETURN_CTOR(i0);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_ce);
			PHALCON_INIT_VAR(c2);
			ZVAL_BOOL(c2, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", model, c2, PHALCON_CHECK);
			PHALCON_RETURN_CTOR(i1);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Overwrites default model manager
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Base, setManager){

	zval *manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	zend_update_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns internal models manager
 *
 * @return Phalcon_Model_Manager
 */
PHP_METHOD(Phalcon_Model_Base, getManager){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
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

	zval *transaction = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, transaction, "getconnection", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Transaction should be an object", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_isView", sizeof("_isView")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 */
PHP_METHOD(Phalcon_Model_Base, setSource){

	zval *source = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &source) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), source TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getSource){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x02E);
		PHALCON_CALL_METHOD_PARAMS_1(r0, t1, "getsource", r1, PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_source", strlen("_source"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 */
PHP_METHOD(Phalcon_Model_Base, setSchema){

	zval *schema = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), schema TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY TSRMLS_CC);
	if (PHALCON_COMPARE_STRING(t0, "")) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getdatabasename", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r0 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t2);
}

/**
 * Overwrites internal Phalcon_Db connection
 *
 * @param Phalcon_Db $connection
 */
PHP_METHOD(Phalcon_Model_Base, setConnection){

	zval *connection = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), connection TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets internal Phalcon_Db connection
 *
 * @return Phalcon_Db
 */
PHP_METHOD(Phalcon_Model_Base, getConnection){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
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

	zval *base = NULL, *result = NULL, *object = NULL, *value = NULL, *key = NULL;
	zval *i0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &base, &result) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	phalcon_clone(i0, base TSRMLS_CC);
	PHALCON_CPY_WRT(object, i0);
	if (Z_TYPE_P(result) == IS_ARRAY) { 
		if (phalcon_valid_foreach(result TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(result);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_1:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_1;
			} else {
				PHALCON_INIT_VAR(key);
				hash_type = zend_hash_get_current_key_ex(ah0, &hash_index, &hash_index_len, &hash_num, 0, &hp0);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(key, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(key, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval(object, Z_STRVAL_P(key), Z_STRLEN_P(key), value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_1;
			fee_f9eb_1:
			if(0){ };
		}
	}
	
	PHALCON_RETURN_CHECK_CTOR(object);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * 
 *
 * @param array $parameters
 * @return  Phalcon_Model_Resultset
 */
PHP_METHOD(Phalcon_Model_Base, find){

	zval *parameters = NULL, *class_name = NULL, *model = NULL, *manager = NULL;
	zval *connection = NULL, *params = NULL, *select = NULL, *result_resource = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *p6[] = { NULL, NULL, NULL, NULL }, *p8[] = { NULL, NULL, NULL, NULL };
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(class_name, r0);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(model, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, class_name, "getmanager");
	PHALCON_CPY_WRT(manager, r1);
	if (!zend_is_true(manager)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, manager, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(connection, r2);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", connection, PHALCON_NO_CHECK);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(params, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(params, a1);
		}
		
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	p6[0] = manager;
	p6[1] = model;
	p6[2] = connection;
	p6[3] = params;
	PHALCON_CALL_SELF_PARAMS(r3, this_ptr, "_createsqlselectmulti", 4, p6);
	PHALCON_CPY_WRT(select, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_string(&r5, select, "sql", strlen("sql"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r4, connection, "query", r5, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(result_resource, r4);
	PHALCON_ALLOC_ZVAL_MM(r6);
	p8[0] = model;
	p8[1] = connection;
	p8[2] = select;
	p8[3] = result_resource;
	PHALCON_CALL_SELF_PARAMS(r6, this_ptr, "_createresultset", 4, p8);
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

	zval *parameters = NULL, *class_name = NULL, *model = NULL, *manager = NULL;
	zval *connection = NULL, *params = NULL, *schema = NULL, *source = NULL, *select = NULL;
	zval *record = NULL, *result = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p11[] = { NULL, NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(class_name, r0);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(model, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, class_name, "getmanager");
	PHALCON_CPY_WRT(manager, r1);
	if (!zend_is_true(manager)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, manager, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(connection, r2);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", connection, PHALCON_NO_CHECK);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(params, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(params, a1);
		}
		
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(source, r4);
	PHALCON_INIT_VAR(select);
	ZVAL_STRING(select, "SELECT ", 1);
	eval_int = phalcon_array_isset_string(params, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, params, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r6);
		concat_function(r6, select, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r6);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CALL_METHOD(r9, manager, "getmetadata", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r8, r9, "getattributes", model, PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r7, connection, "getcolumnlist", r8, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r10);
		concat_function(r10, select, r7 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r10);
	}
	
	if (!PHALCON_COMPARE_STRING(schema, "")) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_LEFT(r12, " FROM ", schema);
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_VBOTH(r11, r12, ".", source);
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, select, r11 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r13);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CONCAT_LEFT(r14, " FROM ", source);
		PHALCON_ALLOC_ZVAL_MM(r15);
		concat_function(r15, select, r14 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r15);
	}
	
	eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 1);
		phalcon_array_update_string(&params, "limit", strlen("limit"), t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(record);
	ZVAL_BOOL(record, 0);
	PHALCON_ALLOC_ZVAL_MM(r16);
	p11[0] = manager;
	p11[1] = model;
	p11[2] = connection;
	p11[3] = select;
	p11[4] = params;
	PHALCON_CALL_SELF_PARAMS(r16, this_ptr, "_createsqlselectone", 5, p11);
	PHALCON_CPY_WRT(select, r16);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c1, PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_METHOD_PARAMS_1(r17, connection, "fetchone", select, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(result, r17);
	if (zend_is_true(result)) {
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CALL_SELF_PARAMS_2(r18, this_ptr, "dumpresult", model, result);
		PHALCON_CPY_WRT(record, r18);
	}
	
	PHALCON_INIT_VAR(c2);
	ZVAL_LONG(c2, 2);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(connection, "setfetchmode", c2, PHALCON_NO_CHECK);
	PHALCON_RETURN_CHECK_CTOR(record);
}

PHP_METHOD(Phalcon_Model_Base, _exists){

	zval *schema = NULL, *source = NULL, *table = NULL, *query = NULL, *where_pk = NULL, *primary_keys = NULL;
	zval *numeric_typed = NULL, *key = NULL, *value = NULL, *num = NULL, *data_type_numeric = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_forceExists", sizeof("_forceExists")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, "getschema", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(schema, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, this_ptr, "getsource", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(source, r1);
		if (zend_is_true(schema)) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_VBOTH(r2, schema, ".", source);
			PHALCON_CPY_WRT(table, r2);
		} else {
			PHALCON_CPY_WRT(table, source);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_BOTH(r3,  "SELECT COUNT(*) AS rowcount FROM ", table, " WHERE ");
		PHALCON_CPY_WRT(query, r3);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(where_pk, a0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD(r4, this_ptr, "_getprimarykeyattributes", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r4);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypesnumeric", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(numeric_typed, r5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CALL_FUNC_PARAMS_1(r6, "count", primary_keys, 0x007);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 0);
		PHALCON_INIT_VAR(r7);
		is_smaller_function(r7, t1, r6 TSRMLS_CC);
		if (zend_is_true(r7)) {
			if (phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(primary_keys);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f9eb_2:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f9eb_2;
				}
				PHALCON_INIT_VAR(key);
				ZVAL_ZVAL(key, *hd, 1, 0);
				PHALCON_INIT_VAR(t2);
				phalcon_read_property_zval(&t2, this_ptr, key, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(value, t2);
				PHALCON_INIT_VAR(t3);
				ZVAL_NULL(t3);
				PHALCON_INIT_VAR(r8);
				is_not_identical_function(r8, t3, value TSRMLS_CC);
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "", 1);
				PHALCON_INIT_VAR(r9);
				is_not_identical_function(r9, t4, value TSRMLS_CC);
				PHALCON_INIT_VAR(r10);
				phalcon_and_function(r10, r8, r9);
				if (zend_is_true(r10)) {
					eval_int = phalcon_array_isset(numeric_typed, key);
					if (eval_int) {
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_LEFT(r12, " ", key);
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, r12, " = ", value);
						phalcon_array_append(&where_pk, r11, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r14);
						PHALCON_CONCAT_LEFT(r14, " ", key);
						PHALCON_INIT_VAR(r13);
						PHALCON_CONCAT_VBOTH(r13, r14, " = '", value);
						PHALCON_INIT_VAR(r15);
						PHALCON_CONCAT_RIGHT(r15, r13, "'");
						phalcon_array_append(&where_pk, r15, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f9eb_2;
				fee_f9eb_2:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CALL_FUNC_PARAMS_1(r16, "count", where_pk, 0x007);
			if (zend_is_true(r16)) {
				PHALCON_ALLOC_ZVAL_MM(r17);
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r17, "join", c0, where_pk, 0x00C);
				phalcon_update_property_zval(this_ptr, "_uniqueKey", strlen("_uniqueKey"), r17 TSRMLS_CC);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_LONG(0);
			}
			
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r18);
			concat_function(r18, query, t5 TSRMLS_CC);
			PHALCON_CPY_WRT(query, r18);
		} else {
			PHALCON_MM_RESTORE();
			RETURN_LONG(0);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r19);
		PHALCON_ALLOC_ZVAL_MM(t6);
		phalcon_read_property(&t6, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1(r19, t6, "fetchone", query, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(num, r19);
		PHALCON_ALLOC_ZVAL_MM(r20);
		phalcon_array_fetch_string(&r20, num, "rowcount", strlen("rowcount"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r20);
	} else {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(where_pk, a1);
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_CALL_METHOD(r21, this_ptr, "_getprimarykeyattributes", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r21);
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_CALL_METHOD(r22, this_ptr, "_getdatatypesnumeric", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(data_type_numeric, r22);
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_CALL_FUNC_PARAMS_1(r23, "count", primary_keys, 0x007);
		PHALCON_INIT_VAR(t7);
		ZVAL_LONG(t7, 0);
		PHALCON_INIT_VAR(r24);
		is_smaller_function(r24, t7, r23 TSRMLS_CC);
		if (zend_is_true(r24)) {
			if (phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(primary_keys);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_f9eb_3:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_f9eb_3;
				}
				PHALCON_INIT_VAR(key);
				ZVAL_ZVAL(key, *hd, 1, 0);
				PHALCON_INIT_VAR(t8);
				phalcon_read_property_zval(&t8, this_ptr, key, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(value, t8);
				PHALCON_INIT_VAR(t9);
				ZVAL_NULL(t9);
				PHALCON_INIT_VAR(r25);
				is_not_identical_function(r25, t9, value TSRMLS_CC);
				PHALCON_INIT_VAR(t10);
				ZVAL_STRING(t10, "", 1);
				PHALCON_INIT_VAR(r26);
				is_not_identical_function(r26, t10, value TSRMLS_CC);
				PHALCON_INIT_VAR(r27);
				phalcon_and_function(r27, r25, r26);
				if (zend_is_true(r27)) {
					eval_int = phalcon_array_isset(data_type_numeric, key);
					if (eval_int) {
						PHALCON_INIT_VAR(r29);
						PHALCON_CONCAT_LEFT(r29, " ", key);
						PHALCON_INIT_VAR(r28);
						PHALCON_CONCAT_VBOTH(r28, r29, " = ", value);
						phalcon_array_append(&where_pk, r28, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r31);
						PHALCON_CONCAT_LEFT(r31, " ", key);
						PHALCON_INIT_VAR(r30);
						PHALCON_CONCAT_VBOTH(r30, r31, " = '", value);
						PHALCON_INIT_VAR(r32);
						PHALCON_CONCAT_RIGHT(r32, r30, "'");
						phalcon_array_append(&where_pk, r32, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_f9eb_3;
				fee_f9eb_3:
				if(0){ };
			}
			PHALCON_ALLOC_ZVAL_MM(r33);
			PHALCON_CALL_FUNC_PARAMS_1(r33, "count", where_pk, 0x007);
			if (zend_is_true(r33)) {
				PHALCON_ALLOC_ZVAL_MM(r34);
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, " AND ", 1);
				PHALCON_CALL_FUNC_PARAMS_2(r34, "join", c1, where_pk, 0x00C);
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
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *connection = NULL, *params = NULL, *select_statement = NULL;
	zval *alias = NULL, *result_resource = NULL, *count = NULL, *row_object = NULL;
	zval *num = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &connection, &params, &select_statement, &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	
	eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS_1(r0, connection, "query", select_statement, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(result_resource, r0);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD_PARAMS_1(r1, connection, "numrows", result_resource, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(count, r1);
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		PHALCON_INIT_VAR(r2);
		is_smaller_function(r2, t0, count TSRMLS_CC);
		if (zend_is_true(r2)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_row_ce);
			PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
			PHALCON_CPY_WRT(row_object, i0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(row_object, "setconnection", connection, PHALCON_NO_CHECK);
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_model_resultset_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", row_object, result_resource, PHALCON_CHECK);
			PHALCON_RETURN_CTOR(i1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_model_resultset_ce);
			PHALCON_ALLOC_ZVAL_MM(i3);
			object_init(i3);
			PHALCON_INIT_VAR(c0);
			ZVAL_BOOL(c0, 0);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i2, "__construct", i3, c0, PHALCON_CHECK);
			PHALCON_RETURN_CTOR(i2);
		}
		
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD_PARAMS_1(r3, connection, "fetchone", select_statement, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(num, r3);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch(&r4, num, alias, PHALCON_NOISY TSRMLS_CC);
		PHALCON_RETURN_CHECK_CTOR(r4);
	}
	
	PHALCON_MM_RESTORE();
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

	zval *parameters = NULL, *class_name = NULL, *model = NULL, *manager = NULL;
	zval *connection = NULL, *params = NULL, *schema = NULL, *source = NULL, *table = NULL;
	zval *select = NULL, *condition = NULL, *primary_keys = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p12[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		ZVAL_STRING(parameters, "", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03E);
	PHALCON_CPY_WRT(class_name, r0);
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(model, i0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_ZVAL_STATIC(r1, class_name, "getmanager");
	PHALCON_CPY_WRT(manager, r1);
	if (!zend_is_true(manager)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not model manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, manager, "getconnection", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(connection, r2);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnection", connection, PHALCON_NO_CHECK);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_append(&a0, parameters, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(params, a0);
		} else {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(params, a1);
		}
		
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(source, r4);
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, schema, ".", source);
		PHALCON_CPY_WRT(table, r5);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	eval_int = phalcon_array_isset_string(params, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, params, "distinct", strlen("distinct"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_LEFT(r8, "SELECT COUNT(DISTINCT ", r7);
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_VBOTH(r6, r8, ") AS rowcount FROM ", table);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_RIGHT(r9, r6, " ");
		PHALCON_CPY_WRT(select, r9);
	} else {
		eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r11);
			phalcon_array_fetch_string(&r11, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r12);
			PHALCON_CONCAT_LEFT(r12, "SELECT ", r11);
			PHALCON_ALLOC_ZVAL_MM(r10);
			PHALCON_CONCAT_VBOTH(r10, r12, ", COUNT(*) AS rowcount FROM ", table);
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_CONCAT_RIGHT(r13, r10, " ");
			PHALCON_CPY_WRT(select, r13);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_BOTH(r14,  "SELECT COUNT(*) AS rowcount FROM ", table, " ");
			PHALCON_CPY_WRT(select, r14);
		}
		
	}
	
	eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r15);
		phalcon_array_fetch_string(&r15, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_CONCAT_BOTH(r16,  " WHERE ", r15, " ");
		PHALCON_ALLOC_ZVAL_MM(r17);
		concat_function(r17, select, r16 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r17);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r18);
			phalcon_array_fetch_long(&r18, params, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(condition, r18);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_CALL_FUNC_PARAMS_1(r19, "is_numeric", condition, 0x027);
			if (zend_is_true(r19)) {
				PHALCON_ALLOC_ZVAL_MM(r20);
				PHALCON_ALLOC_ZVAL_MM(r21);
				PHALCON_CALL_METHOD(r21, manager, "getmetadata", PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1(r20, r21, "getprimarykeyattributes", model, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(primary_keys, r20);
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r23);
					phalcon_array_fetch_long(&r23, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r24);
					PHALCON_CONCAT_LEFT(r24, " WHERE ", r23);
					PHALCON_ALLOC_ZVAL_MM(r22);
					PHALCON_CONCAT_VBOTH(r22, r24, " = '", condition);
					PHALCON_ALLOC_ZVAL_MM(r25);
					PHALCON_CONCAT_RIGHT(r25, r22, "'");
					PHALCON_ALLOC_ZVAL_MM(r26);
					concat_function(r26, select, r25 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r26);
				} else {
					PHALCON_INIT_VAR(t0);
					ZVAL_STRING(t0, " WHERE 0=1", 1);
					PHALCON_ALLOC_ZVAL_MM(r27);
					concat_function(r27, select, t0 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r27);
				}
			} else {
				if (zend_is_true(condition)) {
					PHALCON_ALLOC_ZVAL_MM(r28);
					PHALCON_CONCAT_LEFT(r28, " WHERE ", condition);
					PHALCON_ALLOC_ZVAL_MM(r29);
					concat_function(r29, select, r28 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r29);
				}
			}
		}
	}
	eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r30);
		phalcon_array_fetch_string(&r30, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r31);
		PHALCON_CONCAT_BOTH(r31,  " GROUP BY ", r30, " ");
		PHALCON_ALLOC_ZVAL_MM(r32);
		concat_function(r32, select, r31 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r32);
	}
	
	eval_int = phalcon_array_isset_string(params, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r33);
		phalcon_array_fetch_string(&r33, params, "having", strlen("having"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r34);
		PHALCON_CONCAT_BOTH(r34,  " HAVING ", r33, " ");
		PHALCON_ALLOC_ZVAL_MM(r35);
		concat_function(r35, select, r34 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r35);
	}
	
	eval_int = phalcon_array_isset_string(params, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r36);
		phalcon_array_fetch_string(&r36, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r37);
		PHALCON_CONCAT_BOTH(r37,  " ORDER BY ", r36, " ");
		PHALCON_ALLOC_ZVAL_MM(r38);
		concat_function(r38, select, r37 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r38);
	}
	
	eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r39);
		PHALCON_ALLOC_ZVAL_MM(r40);
		phalcon_array_fetch_string(&r40, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2(r39, connection, "_limit", select, r40, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(select, r39);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r41);
	p12[0] = connection;
	p12[1] = params;
	p12[2] = select;
	PHALCON_INIT_VAR(p12[3]);
	ZVAL_STRING(p12[3], "rowcount", 1);
	PHALCON_CALL_SELF_PARAMS(r41, this_ptr, "_getgroupresult", 4, p12);
	PHALCON_RETURN_DZVAL(r41);
}

PHP_METHOD(Phalcon_Model_Base, _callEvent){

	zval *event_name = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, this_ptr, Z_STRVAL_P(event_name), PHALCON_NO_CHECK);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _cancelOperation){

	zval *transaction = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	t0 = zend_read_static_property(phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_operationMade", sizeof("_operationMade")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 3);
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_equal_function(r0, t1, t2 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c0, PHALCON_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c1, PHALCON_NO_CHECK);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_STATIC(r1, "phalcon_transaction_manager", "isautomatic");
	if (zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_STATIC(r2, "phalcon_transaction_manager", "getautomatic");
		PHALCON_CPY_WRT(transaction, r2);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setrollbackedrecord", this_ptr, PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_NORETURN(transaction, "rollback", PHALCON_NO_CHECK);
	} else {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends a customized message on the validation process
 *
 * 
 *
 * @param Phalcon_Model_Message $message
 */
PHP_METHOD(Phalcon_Model_Base, appendMessage){

	zval *message = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (Z_TYPE_P(message) == IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "get_class", message, 0x02E);
		if (!PHALCON_COMPARE_STRING(r0, "Phalcon_Model_Message")) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", message, 0x02E);
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_CONCAT_BOTH(r2,  "Invalid message format '", r1, "'");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(message);
		PHALCON_CALL_FUNC_PARAMS_1(r3, "gettype", message, 0x03F);
		Z_DELREF_P(message);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_BOTH(r4,  "Invalid message format '", r3, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r4, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t0, message, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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

	zval *validator_class = NULL, *options = NULL, *class_name = NULL;
	zval *field = NULL, *validator = NULL, *values = NULL, *single_field = NULL;
	zval *message = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL, *i4 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL;
	zval *p4[] = { NULL, NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &validator_class, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_LEFT(r0, "Phalcon_Model_Validator_", validator_class);
	PHALCON_CPY_WRT(class_name, r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	Z_ADDREF_P(class_name);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", class_name, 0x00E);
	Z_DELREF_P(class_name);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Validator '", validator_class, "' does not exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Parameter options must be an array", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_array_isset_string(options, "field", strlen("field")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Field name to be validated is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i2 TSRMLS_CC);
		return;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, options, "field", strlen("field"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(field, r3);
	}
	
	if (Z_TYPE_P(field) != IS_ARRAY) { 
		ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, ce0);
		p4[0] = this_ptr;
		p4[1] = field;
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
		p4[2] = t0;
		p4[3] = options;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 4, p4, PHALCON_CHECK);
		PHALCON_CPY_WRT(validator, i3);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(values, a0);
		if (phalcon_valid_foreach(field TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(field);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_4;
			}
			PHALCON_INIT_VAR(single_field);
			ZVAL_ZVAL(single_field, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			phalcon_read_property_zval(&t1, this_ptr, single_field, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&values, t1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_4;
			fee_f9eb_4:
			if(0){ };
		}
		ce1 = phalcon_fetch_class(class_name TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i4);
		object_init_ex(i4, ce1);
		p5[0] = this_ptr;
		p5[1] = field;
		p5[2] = values;
		p5[3] = options;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i4, "__construct", 4, p5, PHALCON_CHECK);
		PHALCON_CPY_WRT(validator, i4);
	}
	
	PHALCON_CALL_METHOD_NORETURN(validator, "checkoptions", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, validator, "validate", PHALCON_NO_CHECK);
	if (Z_TYPE_P(r4) == IS_BOOL && !Z_BVAL_P(r4)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, validator, "getmessages", PHALCON_NO_CHECK);
		if (phalcon_valid_foreach(r5 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(r5);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_f9eb_5:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_f9eb_5;
			}
			PHALCON_INIT_VAR(message);
			ZVAL_ZVAL(message, *hd, 1, 0);
			PHALCON_INIT_VAR(t2);
			phalcon_read_property(&t2, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&t2, message, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t2 TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_f9eb_5;
			fee_f9eb_5:
			if(0){ };
		}
	}
	
	
	PHALCON_MM_RESTORE();
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
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Model_Base, _preSave){

	zval *disable_events = NULL, *exists = NULL, *generator = NULL, *not_null = NULL;
	zval *data_type_numeric = NULL, *error = NULL, *num_fields = NULL;
	zval *i = NULL, *is_null = NULL, *field = NULL, *value = NULL, *human_field = NULL, *message = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *c7 = NULL, *c8 = NULL, *c9 = NULL, *c10 = NULL, *c11 = NULL, *c12 = NULL, *c13 = NULL;
	zval *c14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &disable_events, &exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), a0 TSRMLS_CC);
	if (!zend_is_true(disable_events)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "beforeValidation", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "_callevent", c0, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (!zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "beforeValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r1, this_ptr, "_callevent", c1, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r2);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "beforeValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r2, this_ptr, "_callevent", c2, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_INIT_VAR(generator);
	ZVAL_NULL(generator);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "_getnotnullattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(not_null, r3);
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "_getdatatypesnumeric", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type_numeric, r4);
	if (Z_TYPE_P(not_null) == IS_ARRAY) { 
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_FUNC_PARAMS_1(r5, "count", not_null, 0x007);
		PHALCON_CPY_WRT(num_fields, r5);
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		fs_f9eb_6:
		PHALCON_INIT_VAR(r6);
		is_smaller_function(r6, i, num_fields TSRMLS_CC);
		if (!zend_is_true(r6)) {
			goto fe_f9eb_6;
		}
		PHALCON_INIT_VAR(is_null);
		ZVAL_BOOL(is_null, 0);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch(&r7, not_null, i, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(field, r7);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, t0);
		eval_int = phalcon_array_isset(data_type_numeric, field);
		if (!eval_int) {
			PHALCON_INIT_VAR(t1);
			ZVAL_NULL(t1);
			PHALCON_INIT_VAR(r8);
			is_identical_function(r8, t1, value TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r9);
			is_identical_function(r9, t2, value TSRMLS_CC);
			PHALCON_INIT_VAR(r10);
			ZVAL_BOOL(r10, zend_is_true(r8) || zend_is_true(r9));
			if (zend_is_true(r10)) {
				PHALCON_INIT_VAR(is_null);
				ZVAL_BOOL(is_null, 1);
			}
			
		} else {
			PHALCON_INIT_VAR(r11);
			PHALCON_CALL_FUNC_PARAMS_1(r11, "is_numeric", value, 0x027);
			if (!zend_is_true(r11)) {
				PHALCON_INIT_VAR(is_null);
				ZVAL_BOOL(is_null, 1);
			}
			
		}
		
		PHALCON_INIT_VAR(t3);
		ZVAL_BOOL(t3, 1);
		PHALCON_INIT_VAR(r12);
		is_equal_function(r12, is_null, t3 TSRMLS_CC);
		if (zend_is_true(r12)) {
			PHALCON_INIT_VAR(r13);
			boolean_not_function(r13, exists TSRMLS_CC);
			PHALCON_INIT_VAR(t4);
			ZVAL_STRING(t4, "id", 1);
			PHALCON_INIT_VAR(r14);
			is_equal_function(r14, field, t4 TSRMLS_CC);
			PHALCON_INIT_VAR(r15);
			phalcon_and_function(r15, r13, r14);
			if (zend_is_true(r15)) {
				goto fi_f9eb_6;
			}
			PHALCON_INIT_VAR(r16);
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "_id", 1);
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "", 1);
			PHALCON_CALL_FUNC_PARAMS_3(r16, "str_replace", c3, c4, field, 0x003);
			PHALCON_CPY_WRT(human_field, r16);
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_message_ce);
			PHALCON_INIT_VAR(r17);
			PHALCON_CONCAT_RIGHT(r17, human_field, " is required");
			PHALCON_INIT_VAR(c5);
			ZVAL_STRING(c5, "PresenceOf", 1);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i0, "__construct", r17, field, c5, PHALCON_CHECK);
			PHALCON_CPY_WRT(message, i0);
			PHALCON_INIT_VAR(t5);
			phalcon_read_property(&t5, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_append(&t5, message, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t5 TSRMLS_CC);
			PHALCON_INIT_VAR(error);
			ZVAL_BOOL(error, 1);
		}
		
		fi_f9eb_6:
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto fs_f9eb_6;
		fe_f9eb_6:
		if (zend_is_true(error)) {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_VAR(c6);
				ZVAL_STRING(c6, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c6, PHALCON_NO_CHECK);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
	}
	
	PHALCON_ALLOC_ZVAL_MM(r18);
	PHALCON_INIT_VAR(c7);
	ZVAL_STRING(c7, "validation", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r18, this_ptr, "_callevent", c7, PHALCON_NO_CHECK);
	if (Z_TYPE_P(r18) == IS_BOOL && !Z_BVAL_P(r18)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c8);
			ZVAL_STRING(c8, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c8, PHALCON_NO_CHECK);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	if (!zend_is_true(disable_events)) {
		if (!zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_INIT_VAR(c9);
			ZVAL_STRING(c9, "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r19, this_ptr, "_callevent", c9, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_INIT_VAR(c10);
			ZVAL_STRING(c10, "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r20, this_ptr, "_callevent", c10, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		PHALCON_ALLOC_ZVAL_MM(r21);
		PHALCON_INIT_VAR(c11);
		ZVAL_STRING(c11, "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r21, this_ptr, "_callevent", c11, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_INIT_VAR(c12);
		ZVAL_STRING(c12, "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r22, this_ptr, "_callevent", c12, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		if (zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_INIT_VAR(c13);
			ZVAL_STRING(c13, "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r23, this_ptr, "_callevent", c13, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(c14);
			ZVAL_STRING(c14, "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r24, this_ptr, "_callevent", c14, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r24) == IS_BOOL && !Z_BVAL_P(r24)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _postSave){

	zval *disable_events = NULL, *success = NULL, *exists = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &disable_events, &success, &exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	if (zend_is_true(success)) {
		if (zend_is_true(exists)) {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c0, PHALCON_NO_CHECK);
			}
		} else {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c1, PHALCON_NO_CHECK);
			}
		}
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c2, PHALCON_NO_CHECK);
		}
		
		PHALCON_RETURN_CHECK_CTOR(success);
	} else {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c3, PHALCON_NO_CHECK);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _doLowInsert){

	zval *connection = NULL, *table = NULL, *data_type = NULL, *data_type_numeric = NULL;
	zval *fields = NULL, *values = NULL, *attributes = NULL, *field = NULL, *value = NULL;
	zval *identity_field = NULL, *id = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &connection, &table, &data_type, &data_type_numeric) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(fields, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(values, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(attributes, r0);
	if (phalcon_valid_foreach(attributes TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_7:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_7;
		}
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		if (!PHALCON_COMPARE_STRING(field, "id")) {
			phalcon_array_append(&fields, field, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(value, t0);
			if (Z_TYPE_P(value) == IS_OBJECT) {
				PHALCON_INIT_VAR(r1);
				phalcon_instance_of(r1, value, phalcon_db_rawvalue_ce TSRMLS_CC);
				if (zend_is_true(r1)) {
					PHALCON_INIT_VAR(r2);
					PHALCON_CALL_METHOD(r2, value, "getvalue", PHALCON_NO_CHECK);
					phalcon_array_append(&values, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					convert_to_string(value);
					phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				}
				
			} else {
				PHALCON_INIT_VAR(t1);
				ZVAL_STRING(t1, "", 1);
				PHALCON_INIT_VAR(r3);
				is_identical_function(r3, t1, value TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_NULL(t2);
				PHALCON_INIT_VAR(r4);
				is_identical_function(r4, t2, value TSRMLS_CC);
				PHALCON_INIT_VAR(r5);
				ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
				if (zend_is_true(r5)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "NULL", 1);
					phalcon_array_append(&values, t3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					eval_int = phalcon_array_isset(data_type_numeric, field);
					if (eval_int) {
						phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch(&r6, data_type, field, PHALCON_NOISY TSRMLS_CC);
						if (PHALCON_COMPARE_STRING(r6, "date")) {
							PHALCON_INIT_VAR(r7);
							PHALCON_INIT_VAR(t4);
							phalcon_read_property(&t4, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
							PHALCON_CALL_METHOD_PARAMS_1(r7, t4, "getdateusingformat", value, PHALCON_NO_CHECK);
							phalcon_array_append(&values, r7, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(r8);
							PHALCON_CONCAT_BOTH(r8,  "'", value, "'");
							phalcon_array_append(&values, r8, PHALCON_SEPARATE_PLZ TSRMLS_CC);
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
	PHALCON_ALLOC_ZVAL_MM(r9);
	PHALCON_CALL_METHOD(r9, this_ptr, "_getidentityfield", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(identity_field, r9);
	if (zend_is_true(identity_field)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property_zval(&t5, this_ptr, identity_field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(id, t5);
		phalcon_array_append(&fields, identity_field, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r10);
		Z_ADDREF_P(id);
		PHALCON_CALL_FUNC_PARAMS_1(r10, "is_null", id, 0x040);
		Z_DELREF_P(id);
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "", 1);
		PHALCON_INIT_VAR(r11);
		is_identical_function(r11, t6, id TSRMLS_CC);
		PHALCON_INIT_VAR(r12);
		ZVAL_BOOL(r12, zend_is_true(r10) || zend_is_true(r11));
		if (zend_is_true(r12)) {
			PHALCON_INIT_VAR(t7);
			ZVAL_STRING(t7, "null", 1);
			phalcon_array_append(&values, t7, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		} else {
			phalcon_array_append(&values, id, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
		
	}
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	PHALCON_CALL_METHOD_PARAMS_3(r13, connection, "insert", table, values, fields, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r13);
}

PHP_METHOD(Phalcon_Model_Base, _doLowUpdate){

	zval *connection = NULL, *table = NULL, *data_type = NULL, *data_type_numeric = NULL;
	zval *fields = NULL, *values = NULL, *non_primary = NULL, *field = NULL, *value = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *p3[] = { NULL, NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &connection, &table, &data_type, &data_type_numeric) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(fields, a0);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_CPY_WRT(values, a1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_getnonprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(non_primary, r0);
	if (phalcon_valid_foreach(non_primary TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(non_primary);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_8;
		}
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		phalcon_array_append(&fields, field, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_INIT_VAR(t0);
		phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(value, t0);
		if (Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_INIT_VAR(r1);
			phalcon_instance_of(r1, value, phalcon_db_rawvalue_ce TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_METHOD(r2, value, "getvalue", PHALCON_NO_CHECK);
				phalcon_array_append(&values, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(t1);
				phalcon_read_property_zval(&t1, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
				convert_to_string(t1);
				phalcon_array_append(&values, t1, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
			
		} else {
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			PHALCON_INIT_VAR(r3);
			is_identical_function(r3, t2, value TSRMLS_CC);
			PHALCON_INIT_VAR(t3);
			ZVAL_NULL(t3);
			PHALCON_INIT_VAR(r4);
			is_identical_function(r4, t3, value TSRMLS_CC);
			PHALCON_INIT_VAR(r5);
			ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
			if (zend_is_true(r5)) {
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "NULL", 1);
				phalcon_array_append(&values, t4, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset(data_type_numeric, field);
				if (eval_int) {
					phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r6);
					phalcon_array_fetch(&r6, data_type, field, PHALCON_NOISY TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r6, "date")) {
						PHALCON_INIT_VAR(r7);
						PHALCON_CALL_METHOD_PARAMS_1(r7, connection, "getdateusingformat", value, PHALCON_NO_CHECK);
						phalcon_array_append(&values, r7, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r8);
						PHALCON_CONCAT_BOTH(r8,  "'", value, "'");
						phalcon_array_append(&values, r8, PHALCON_SEPARATE_PLZ TSRMLS_CC);
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
	p3[0] = table;
	p3[1] = fields;
	p3[2] = values;
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY TSRMLS_CC);
	p3[3] = t5;
	PHALCON_CALL_METHOD_PARAMS(r9, connection, "update", 4, p3, PHALCON_NO_CHECK);
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

	zval *exists = NULL, *disable_events = NULL, *schema = NULL, *source = NULL;
	zval *table = NULL, *connection = NULL, *data_type = NULL, *primary_keys = NULL;
	zval *data_type_numeric = NULL, *success = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p8[] = { NULL, NULL, NULL, NULL }, *p9[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "_exists", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(exists, r0);
	if (!zend_is_true(exists)) {
		phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 2 TSRMLS_CC);
	}
	
	t0 = zend_read_static_property(phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(disable_events, t0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_2(r1, this_ptr, "_presave", disable_events, exists, PHALCON_NO_CHECK);
	if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r2);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(source, r3);
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CONCAT_VBOTH(r4, schema, ".", source);
		PHALCON_CPY_WRT(table, r4);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(connection, t1);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "_getdatatypes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type, r5);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "_getprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(primary_keys, r6);
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, this_ptr, "_getdatatypesnumeric", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type_numeric, r7);
	if (zend_is_true(exists)) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		p8[0] = connection;
		p8[1] = table;
		p8[2] = data_type;
		p8[3] = data_type_numeric;
		PHALCON_CALL_METHOD_PARAMS(r8, this_ptr, "_dolowupdate", 4, p8, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r8);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r9);
		p9[0] = connection;
		p9[1] = table;
		p9[2] = data_type;
		p9[3] = data_type_numeric;
		PHALCON_CALL_METHOD_PARAMS(r9, this_ptr, "_dolowinsert", 4, p9, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r9);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	PHALCON_CALL_METHOD(r10, connection, "isundertransaction", PHALCON_NO_CHECK);
	if (!zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_METHOD(r11, connection, "gethaveautocommit", PHALCON_NO_CHECK);
		if (zend_is_true(r11)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "commit", PHALCON_NO_CHECK);
		}
		
	}
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_CALL_METHOD_PARAMS_3(r12, this_ptr, "_postsave", disable_events, success, exists, PHALCON_NO_CHECK);
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

	zval *table = NULL, *primary_keys = NULL, *primary_key_value = NULL;
	zval *conditions = NULL, *primary_key = NULL, *disable_events = NULL;
	zval *success = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_schema", sizeof("_schema")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_VBOTH(r0, t1, ".", t2);
		PHALCON_CPY_WRT(table, r0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_source", sizeof("_source")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(table, t3);
	}
	
	phalcon_update_property_long(this_ptr, "_operationMade", strlen("_operationMade"), 3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_getprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(primary_keys, r1);
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_FUNC_PARAMS_1(r2, "count", primary_keys, 0x007);
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, r2, t4 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_long(&r4, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
		phalcon_read_property_zval(&t5, this_ptr, r4, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(primary_key_value, t5);
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_long(&r6, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, r6, " = '", primary_key_value);
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_RIGHT(r7, r5, "'");
		PHALCON_CPY_WRT(conditions, r7);
	} else {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(conditions, a0);
		if (phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(primary_keys);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_9:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_9;
			}
			PHALCON_INIT_VAR(primary_key);
			ZVAL_ZVAL(primary_key, *hd, 1, 0);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property_zval(&t6, this_ptr, primary_key, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(primary_key_value, t6);
			PHALCON_INIT_VAR(r8);
			PHALCON_CONCAT_VBOTH(r8, primary_key, " = '", primary_key_value);
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_RIGHT(r9, r8, "'");
			phalcon_array_append(&conditions, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_9;
			fee_f9eb_9:
			if(0){ };
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		PHALCON_CALL_FUNC_PARAMS_2(r10, "join", c0, conditions, 0x00C);
		PHALCON_CPY_WRT(conditions, r10);
	}
	t7 = zend_read_static_property(phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	PHALCON_CPY_WRT(disable_events, t7);
	if (!zend_is_true(disable_events)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r11, this_ptr, "_callevent", c1, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r11) == IS_BOOL && !Z_BVAL_P(r11)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
	}
	
	PHALCON_ALLOC_ZVAL_MM(r12);
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2(r12, t8, "delete", table, conditions, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(success, r12);
	if (zend_is_true(success)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c2, PHALCON_NO_CHECK);
		}
		
	}
	
	PHALCON_RETURN_CHECK_CTOR(success);
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

	zval *attribute = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attribute) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dump", sizeof("_dump")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property_zval(&t1, this_ptr, attribute, PHALCON_NOISY TSRMLS_CC);
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

	zval *attribute = NULL, *value = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dumped", sizeof("_dumped")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	phalcon_update_property_zval(this_ptr, Z_STRVAL_P(attribute), Z_STRLEN_P(attribute), value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 *
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, hasOne){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &fields, &reference_model, &referenced_fields) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasone", 4, p0, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, belongsTo){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &fields, &reference_model, &referenced_fields) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addbelongsto", 4, p0, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation 1-n between two models
     *
 *
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 */
PHP_METHOD(Phalcon_Model_Base, hasMany){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &fields, &reference_model, &referenced_fields) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	
	
	t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
	if (zend_is_true(t0)) {
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasmany", 4, p0, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is not models manager related to this model", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_MM_RESTORE();
}

/**
 * Handles methods when a method does not exist
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 * @throwsPhalcon_Model_Exception
 */
PHP_METHOD(Phalcon_Model_Base, __call){

	zval *method = NULL, *arguments = NULL, *entity_name = NULL, *requested_relation = NULL;
	zval *manager = NULL, *entity_arguments = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL, *a8 = NULL, *a9 = NULL, *a10 = NULL, *a11 = NULL, *a12 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!arguments) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(arguments, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 3);
	PHALCON_CALL_FUNC_PARAMS_3(r0, "substr", method, c0, c1, 0x002);
	if (PHALCON_COMPARE_STRING(r0, "get")) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "get_class", this_ptr, 0x02E);
		PHALCON_CPY_WRT(entity_name, r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_INIT_VAR(c2);
		ZVAL_LONG(c2, 3);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "substr", method, c2, 0x002);
		PHALCON_CALL_FUNC_PARAMS_1(r2, "ucfirst", r3, 0x041);
		PHALCON_CPY_WRT(requested_relation, r2);
		t0 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(manager, t0);
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD_PARAMS_2(r4, manager, "existsbelongsto", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r4)) {
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			add_next_index_stringl(a1, "findFirst", strlen("findFirst"), 1);
			phalcon_array_append(&a1, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a1, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a1, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a1);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			phalcon_array_append(&a2, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a2, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a2);
			PHALCON_ALLOC_ZVAL_MM(r6);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r6, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r6);
			PHALCON_CALL_FUNC_PARAMS_2(r5, "call_user_func_array", a2, r6, 0x00F);
			Z_DELREF_P(a2);
			Z_DELREF_P(r6);
			PHALCON_RETURN_DZVAL(r5);
		}
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD_PARAMS_2(r7, manager, "existshasmany", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r7)) {
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			add_next_index_stringl(a3, "find", strlen("find"), 1);
			phalcon_array_append(&a3, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a3, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a3, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a3);
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			phalcon_array_append(&a4, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a4, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a4);
			PHALCON_ALLOC_ZVAL_MM(r9);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r9, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r9);
			PHALCON_CALL_FUNC_PARAMS_2(r8, "call_user_func_array", a4, r9, 0x00F);
			Z_DELREF_P(a4);
			Z_DELREF_P(r9);
			PHALCON_RETURN_DZVAL(r8);
		}
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CALL_METHOD_PARAMS_2(r10, manager, "existshasone", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r10)) {
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			add_next_index_stringl(a5, "findFirst", strlen("findFirst"), 1);
			phalcon_array_append(&a5, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a5, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a5, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a5);
			PHALCON_ALLOC_ZVAL_MM(r11);
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			phalcon_array_append(&a6, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a6, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a6);
			PHALCON_ALLOC_ZVAL_MM(r12);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r12);
			PHALCON_CALL_FUNC_PARAMS_2(r11, "call_user_func_array", a6, r12, 0x00F);
			Z_DELREF_P(a6);
			Z_DELREF_P(r12);
			PHALCON_RETURN_DZVAL(r11);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(r13);
	PHALCON_INIT_VAR(c3);
	ZVAL_LONG(c3, 0);
	PHALCON_INIT_VAR(c4);
	ZVAL_LONG(c4, 5);
	PHALCON_CALL_FUNC_PARAMS_3(r13, "substr", method, c3, c4, 0x002);
	if (PHALCON_COMPARE_STRING(r13, "count")) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		PHALCON_CALL_FUNC_PARAMS_1(r14, "get_class", this_ptr, 0x02E);
		PHALCON_CPY_WRT(entity_name, r14);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_ALLOC_ZVAL_MM(r16);
		PHALCON_INIT_VAR(c5);
		ZVAL_LONG(c5, 5);
		PHALCON_CALL_FUNC_PARAMS_2(r16, "substr", method, c5, 0x002);
		PHALCON_CALL_FUNC_PARAMS_1(r15, "ucfirst", r16, 0x041);
		PHALCON_CPY_WRT(requested_relation, r15);
		t1 = zend_read_static_property(phalcon_model_base_ce, "_manager", sizeof("_manager")-1, (zend_bool) ZEND_FETCH_CLASS_SILENT TSRMLS_CC);
		PHALCON_CPY_WRT(manager, t1);
		PHALCON_ALLOC_ZVAL_MM(r17);
		PHALCON_CALL_METHOD_PARAMS_2(r17, manager, "existsbelongsto", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r17)) {
			PHALCON_INIT_VAR(a7);
			array_init(a7);
			add_next_index_stringl(a7, "count", strlen("count"), 1);
			phalcon_array_append(&a7, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a7, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a7, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a7);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(a8);
			array_init(a8);
			phalcon_array_append(&a8, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a8, "getBelongsToRecords", strlen("getBelongsToRecords"), 1);
			Z_ADDREF_P(a8);
			PHALCON_ALLOC_ZVAL_MM(r19);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r19, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r19);
			PHALCON_CALL_FUNC_PARAMS_2(r18, "call_user_func_array", a8, r19, 0x00F);
			Z_DELREF_P(a8);
			Z_DELREF_P(r19);
			PHALCON_RETURN_DZVAL(r18);
		}
		PHALCON_ALLOC_ZVAL_MM(r20);
		PHALCON_CALL_METHOD_PARAMS_2(r20, manager, "existshasmany", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r20)) {
			PHALCON_INIT_VAR(a9);
			array_init(a9);
			add_next_index_stringl(a9, "count", strlen("count"), 1);
			phalcon_array_append(&a9, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a9, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a9, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a9);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_INIT_VAR(a10);
			array_init(a10);
			phalcon_array_append(&a10, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a10, "getHasManyRecords", strlen("getHasManyRecords"), 1);
			Z_ADDREF_P(a10);
			PHALCON_ALLOC_ZVAL_MM(r22);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r22, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r22);
			PHALCON_CALL_FUNC_PARAMS_2(r21, "call_user_func_array", a10, r22, 0x00F);
			Z_DELREF_P(a10);
			Z_DELREF_P(r22);
			PHALCON_RETURN_DZVAL(r21);
		}
		PHALCON_ALLOC_ZVAL_MM(r23);
		PHALCON_CALL_METHOD_PARAMS_2(r23, manager, "existshasone", entity_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r23)) {
			PHALCON_INIT_VAR(a11);
			array_init(a11);
			add_next_index_stringl(a11, "count", strlen("count"), 1);
			phalcon_array_append(&a11, entity_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a11, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			phalcon_array_append(&a11, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			PHALCON_CPY_WRT(entity_arguments, a11);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_INIT_VAR(a12);
			array_init(a12);
			phalcon_array_append(&a12, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			add_next_index_stringl(a12, "getHasOneRecords", strlen("getHasOneRecords"), 1);
			Z_ADDREF_P(a12);
			PHALCON_ALLOC_ZVAL_MM(r25);
			Z_ADDREF_P(entity_arguments);
			Z_ADDREF_P(arguments);
			PHALCON_CALL_FUNC_PARAMS_2(r25, "array_merge", entity_arguments, arguments, 0x042);
			Z_DELREF_P(entity_arguments);
			Z_DELREF_P(arguments);
			Z_ADDREF_P(r25);
			PHALCON_CALL_FUNC_PARAMS_2(r24, "call_user_func_array", a12, r25, 0x00F);
			Z_DELREF_P(a12);
			Z_DELREF_P(r25);
			PHALCON_RETURN_DZVAL(r24);
		}
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_ce);
	PHALCON_ALLOC_ZVAL_MM(r27);
	PHALCON_CONCAT_LEFT(r27, "Method \"", method);
	PHALCON_ALLOC_ZVAL_MM(r28);
	PHALCON_CALL_FUNC_PARAMS_1(r28, "get_class", this_ptr, 0x02E);
	PHALCON_ALLOC_ZVAL_MM(r26);
	PHALCON_CONCAT_VBOTH(r26, r27, "\" doesn't exist on model \"", r28);
	PHALCON_ALLOC_ZVAL_MM(r29);
	PHALCON_CONCAT_RIGHT(r29, r26, "\"");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r29, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

