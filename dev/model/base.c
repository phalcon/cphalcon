
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

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
		PHALCON_OBSERVE_VAR(t0);
		phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
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
	phalcon_get_class(r2, this_ptr TSRMLS_CC);
	PHALCON_CPY_WRT(class_name, r2);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_initialized", sizeof("_initialized")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t1)) {
		if (phalcon_method_exists_ex(this_ptr, "initialize", strlen("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "initialize", PHALCON_NO_CHECK);
		}
		phalcon_update_property_bool(this_ptr, "_initialized", strlen("_initialized"), 1 TSRMLS_CC);
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
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Internal method to create a connection. Automatically dumps mapped table meta-data
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
		PHALCON_OBSERVE_VAR(t1);
		phalcon_read_static_property(&t1, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
		PHALCON_CALL_METHOD(r0, t1, "getconnection", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_connection", strlen("_connection"), r0 TSRMLS_CC);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "dump", PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return an array with the attributes names
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns an array of attributes that are part of the related table primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getprimarykeyattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns an array of attributes that aren't part of the primary key
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getNonPrimaryKeyAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getnonprimarykeyattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns an array of not-nullable attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getNotNullAttributes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getnotnullattributes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns an array of numeric attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getDataTypesNumeric){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getdatatypesnumeric", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns an array of data-types attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_Base, getDataTypes){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t0, "getmetadata", PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1(r0, r1, "getdatatypes", this_ptr, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns the name of the identity field
 *
 * @return string
 */
PHP_METHOD(Phalcon_Model_Base, getIdentityField){

	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
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
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
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
	phalcon_update_property_bool(this_ptr, "_dumped", strlen("_dumped"), 1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "getattributes", PHALCON_NO_CHECK);
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
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, "", 1);
			phalcon_update_property_zval_zval(this_ptr, field, t1 TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_0;
		fee_f9eb_0:
		if(0){}
	} else {
		return;
	}
	
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
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, manager, "getmetadata", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r6, r7, "getattributes", model, PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r5, connection, "getcolumnlist", r6, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(r8);
		concat_function(r8, select, r5 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r8);
	}
	
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_LEFT(r10, " FROM ", schema);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_VBOTH(r9, r10, ".", source);
		PHALCON_ALLOC_ZVAL_MM(r11);
		concat_function(r11, select, r9 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r11);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_LEFT(r12, " FROM ", source);
		PHALCON_ALLOC_ZVAL_MM(r13);
		concat_function(r13, select, r12 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r13);
	}
	
	PHALCON_INIT_VAR(number_rows);
	ZVAL_STRING(number_rows, "n", 1);
	eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		phalcon_array_fetch_string(&r14, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CONCAT_BOTH(r15,  " WHERE ", r14, " ");
		PHALCON_ALLOC_ZVAL_MM(r16);
		concat_function(r16, select, r15 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r16);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r17);
		PHALCON_ALLOC_ZVAL_MM(r18);
		PHALCON_CALL_METHOD(r18, manager, "getmetadata", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1(r17, r18, "getprimarykeyattributes", model, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r17);
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_ALLOC_ZVAL_MM(r20);
			phalcon_array_fetch_long(&r20, params, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_FUNC_PARAMS_1(r19, "is_numeric", r20, 0x02B);
			if (zend_is_true(r19)) {
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r22);
					phalcon_array_fetch_long(&r22, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r23);
					PHALCON_ALLOC_ZVAL_MM(r24);
					phalcon_array_fetch_long(&r24, params, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_CALL_METHOD_PARAMS_1(r23, connection, "addquotes", r24, PHALCON_NO_CHECK);
					PHALCON_ALLOC_ZVAL_MM(r21);
					PHALCON_CONCAT_VBOTH(r21, r22, " = ", r23);
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r21, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					
					PHALCON_INIT_VAR(number_rows);
					ZVAL_STRING(number_rows, "1", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_model_exception_ce);
					PHALCON_INIT_VAR(c0);
					ZVAL_STRING(c0, "Source related to this model does not have a primary key defined", 1);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL_MM(r25);
				phalcon_array_fetch_long(&r25, params, 0, PHALCON_NOISY TSRMLS_CC);
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				PHALCON_INIT_VAR(r26);
				is_identical_function(r26, t0, r25 TSRMLS_CC);
				if (zend_is_true(r26)) {
					eval_int = phalcon_array_isset_long(primary_keys, 0);
					if (eval_int) {
						PHALCON_ALLOC_ZVAL_MM(r27);
						phalcon_array_fetch_long(&r27, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r28);
						PHALCON_CONCAT_RIGHT(r28, r27, " = ''");
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r28, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(i1);
						object_init_ex(i1, phalcon_model_exception_ce);
						PHALCON_INIT_VAR(c1);
						ZVAL_STRING(c1, "Source related to this model does not have a primary key defined", 1);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
						phalcon_throw_exception(i1 TSRMLS_CC);
						return;
					}
				} else {
					PHALCON_ALLOC_ZVAL_MM(r29);
					phalcon_array_fetch_long(&r29, params, 0, PHALCON_NOISY TSRMLS_CC);
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r29, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(number_rows);
				ZVAL_STRING(number_rows, "n", 1);
			}
		}
		
		eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r30);
			phalcon_array_fetch_string(&r30, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r31);
			PHALCON_CONCAT_LEFT(r31, " WHERE ", r30);
			PHALCON_ALLOC_ZVAL_MM(r32);
			concat_function(r32, select, r31 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r32);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r33);
		phalcon_array_fetch_string(&r33, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r33)) {
			PHALCON_ALLOC_ZVAL_MM(r34);
			phalcon_array_fetch_string(&r34, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r35);
			PHALCON_CONCAT_LEFT(r35, " GROUP BY ", r34);
			PHALCON_ALLOC_ZVAL_MM(r36);
			concat_function(r36, select, r35 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r36);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r37);
		phalcon_array_fetch_string(&r37, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r37)) {
			PHALCON_ALLOC_ZVAL_MM(r38);
			phalcon_array_fetch_string(&r38, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r39);
			PHALCON_CONCAT_LEFT(r39, " ORDER BY ", r38);
			PHALCON_ALLOC_ZVAL_MM(r40);
			concat_function(r40, select, r39 TSRMLS_CC);
			PHALCON_CPY_WRT(select, r40);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r41);
		phalcon_array_fetch_string(&r41, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r41)) {
			PHALCON_ALLOC_ZVAL_MM(r42);
			PHALCON_ALLOC_ZVAL_MM(r43);
			phalcon_array_fetch_string(&r43, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_CALL_METHOD_PARAMS_2(r42, connection, "limit", select, r43, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r42);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "for_update", strlen("for_update")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r44);
		phalcon_array_fetch_string(&r44, params, "for_update", strlen("for_update"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r44)) {
			PHALCON_ALLOC_ZVAL_MM(r45);
			PHALCON_CALL_METHOD_PARAMS_1(r45, connection, "forupdate", select, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r45);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "shared_lock", strlen("shared_lock")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r46);
		phalcon_array_fetch_string(&r46, params, "shared_lock", strlen("shared_lock"), PHALCON_NOISY TSRMLS_CC);
		if (zend_is_true(r46)) {
			PHALCON_ALLOC_ZVAL_MM(r47);
			PHALCON_CALL_METHOD_PARAMS_1(r47, connection, "sharedlock", select, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(select, r47);
		}
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_array_update_string(&a0, "return", strlen("return"), &number_rows, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a0, "sql", strlen("sql"), &select, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
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
				PHALCON_CALL_FUNC_PARAMS_1(r6, "is_numeric", r7, 0x02B);
				if (zend_is_true(r6)) {
					PHALCON_ALLOC_ZVAL_MM(r9);
					phalcon_array_fetch_long(&r9, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r10);
					phalcon_array_fetch_long(&r10, params, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r8);
					PHALCON_CONCAT_VBOTH(r8, r9, " = '", r10);
					PHALCON_ALLOC_ZVAL_MM(r11);
					PHALCON_CONCAT_RIGHT(r11, r8, "'");
					phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r11, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r12);
					phalcon_array_fetch_long(&r12, params, 0, PHALCON_NOISY TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r12, "")) {
						PHALCON_ALLOC_ZVAL_MM(r13);
						phalcon_array_fetch_long(&r13, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_ALLOC_ZVAL_MM(r14);
						PHALCON_CONCAT_RIGHT(r14, r13, " = ''");
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r14, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					} else {
						PHALCON_ALLOC_ZVAL_MM(r15);
						phalcon_array_fetch_long(&r15, params, 0, PHALCON_NOISY TSRMLS_CC);
						phalcon_array_update_string(&params, "conditions", strlen("conditions"), &r15, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
			PHALCON_CALL_FUNC_PARAMS_1(r33, "is_numeric", params, 0x02B);
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
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_OBSERVE_VAR(t1);
		phalcon_read_static_property(&t1, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_get_class(r1, this_ptr TSRMLS_CC);
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
	if (!zend_is_true(t0)) {
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
	if (phalcon_clone(i0, base TSRMLS_CC) == FAILURE){
		return;
	}
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
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_1;
			fee_f9eb_1:
			if(0){}
		} else {
			return;
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
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
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
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
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
		phalcon_array_update_string(&params, "limit", strlen("limit"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
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
		PHALCON_CALL_METHOD(r4, this_ptr, "getprimarykeyattributes", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r4);
		
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CALL_METHOD(r5, this_ptr, "getdatatypesnumeric", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(numeric_typed, r5);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_fast_count(r6, primary_keys TSRMLS_CC);
		
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
				if(0){}
			} else {
				return;
			}
			
			PHALCON_ALLOC_ZVAL_MM(r16);
			phalcon_fast_count(r16, where_pk TSRMLS_CC);
			if (zend_is_true(r16)) {
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_ALLOC_ZVAL_MM(r17);
				phalcon_fast_join(r17, c0, where_pk TSRMLS_CC);
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
		PHALCON_CALL_METHOD(r21, this_ptr, "getprimarykeyattributes", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(primary_keys, r21);
		
		PHALCON_ALLOC_ZVAL_MM(r22);
		PHALCON_CALL_METHOD(r22, this_ptr, "getdatatypesnumeric", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(data_type_numeric, r22);
		
		PHALCON_ALLOC_ZVAL_MM(r23);
		phalcon_fast_count(r23, primary_keys TSRMLS_CC);
		
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
				if(0){}
			} else {
				return;
			}
			
			PHALCON_ALLOC_ZVAL_MM(r33);
			phalcon_fast_count(r33, where_pk TSRMLS_CC);
			if (zend_is_true(r33)) {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, " AND ", 1);
				PHALCON_ALLOC_ZVAL_MM(r34);
				phalcon_fast_join(r34, c1, where_pk TSRMLS_CC);
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

PHP_METHOD(Phalcon_Model_Base, _prepareGroupResult){

	zval *function = NULL, *alias = NULL, *parameters = NULL, *class_name = NULL;
	zval *model = NULL, *manager = NULL, *connection = NULL, *params = NULL, *schema = NULL;
	zval *source = NULL, *table = NULL, *group_column = NULL, *select = NULL, *condition = NULL;
	zval *primary_keys = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL, *r25 = NULL, *r26 = NULL, *r27 = NULL;
	zval *r28 = NULL, *r29 = NULL, *r30 = NULL, *r31 = NULL, *r32 = NULL, *r33 = NULL, *r34 = NULL;
	zval *r35 = NULL, *r36 = NULL, *r37 = NULL, *r38 = NULL, *r39 = NULL, *r40 = NULL, *r41 = NULL;
	zval *r42 = NULL, *r43 = NULL, *r44 = NULL, *r45 = NULL, *r46 = NULL, *r47 = NULL, *r48 = NULL;
	zval *r49 = NULL, *r50 = NULL, *r51 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *p12[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &function, &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC(r0, "get_called_class", 0x03F);
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
	
	eval_int = phalcon_array_isset_string(params, "column", strlen("column")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_array_fetch_string(&r6, params, "column", strlen("column"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(group_column, r6);
	} else {
		PHALCON_INIT_VAR(group_column);
		ZVAL_STRING(group_column, "*", 1);
	}
	
	eval_int = phalcon_array_isset_string(params, "distinct", strlen("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r10);
		PHALCON_CONCAT_LEFT(r10, "SELECT ", function);
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, params, "distinct", strlen("distinct"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_VBOTH(r9, r10, "(DISTINCT ", r11);
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_VBOTH(r8, r9, ") AS ", alias);
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_VBOTH(r7, r8, " FROM ", table);
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CONCAT_RIGHT(r12, r7, " ");
		PHALCON_CPY_WRT(select, r12);
	} else {
		eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r17);
			phalcon_array_fetch_string(&r17, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_CONCAT_LEFT(r18, "SELECT ", r17);
			PHALCON_ALLOC_ZVAL_MM(r16);
			PHALCON_CONCAT_VBOTH(r16, r18, ", ", function);
			PHALCON_ALLOC_ZVAL_MM(r15);
			PHALCON_CONCAT_VBOTH(r15, r16, "(", group_column);
			PHALCON_ALLOC_ZVAL_MM(r14);
			PHALCON_CONCAT_VBOTH(r14, r15, ") AS ", alias);
			PHALCON_ALLOC_ZVAL_MM(r13);
			PHALCON_CONCAT_VBOTH(r13, r14, " FROM ", table);
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_CONCAT_RIGHT(r19, r13, " ");
			PHALCON_CPY_WRT(select, r19);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_CONCAT_LEFT(r23, "SELECT ", function);
			PHALCON_ALLOC_ZVAL_MM(r22);
			PHALCON_CONCAT_VBOTH(r22, r23, "(", group_column);
			PHALCON_ALLOC_ZVAL_MM(r21);
			PHALCON_CONCAT_VBOTH(r21, r22, ") AS ", alias);
			PHALCON_ALLOC_ZVAL_MM(r20);
			PHALCON_CONCAT_VBOTH(r20, r21, " FROM ", table);
			PHALCON_ALLOC_ZVAL_MM(r24);
			PHALCON_CONCAT_RIGHT(r24, r20, " ");
			PHALCON_CPY_WRT(select, r24);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "conditions", strlen("conditions")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r25);
		phalcon_array_fetch_string(&r25, params, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r26);
		PHALCON_CONCAT_BOTH(r26,  " WHERE ", r25, " ");
		PHALCON_ALLOC_ZVAL_MM(r27);
		concat_function(r27, select, r26 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r27);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r28);
			phalcon_array_fetch_long(&r28, params, 0, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(condition, r28);
			
			PHALCON_ALLOC_ZVAL_MM(r29);
			PHALCON_CALL_FUNC_PARAMS_1(r29, "is_numeric", condition, 0x02B);
			if (zend_is_true(r29)) {
				PHALCON_ALLOC_ZVAL_MM(r30);
				PHALCON_ALLOC_ZVAL_MM(r31);
				PHALCON_CALL_METHOD(r31, manager, "getmetadata", PHALCON_NO_CHECK);
				PHALCON_CALL_METHOD_PARAMS_1(r30, r31, "getprimarykeyattributes", model, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(primary_keys, r30);
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r33);
					phalcon_array_fetch_long(&r33, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
					PHALCON_ALLOC_ZVAL_MM(r34);
					PHALCON_CONCAT_LEFT(r34, " WHERE ", r33);
					PHALCON_ALLOC_ZVAL_MM(r32);
					PHALCON_CONCAT_VBOTH(r32, r34, " = '", condition);
					PHALCON_ALLOC_ZVAL_MM(r35);
					PHALCON_CONCAT_RIGHT(r35, r32, "'");
					PHALCON_ALLOC_ZVAL_MM(r36);
					concat_function(r36, select, r35 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r36);
				} else {
					PHALCON_INIT_VAR(t0);
					ZVAL_STRING(t0, " WHERE 0=1", 1);
					PHALCON_ALLOC_ZVAL_MM(r37);
					concat_function(r37, select, t0 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r37);
				}
			} else {
				if (zend_is_true(condition)) {
					PHALCON_ALLOC_ZVAL_MM(r38);
					PHALCON_CONCAT_LEFT(r38, " WHERE ", condition);
					PHALCON_ALLOC_ZVAL_MM(r39);
					concat_function(r39, select, r38 TSRMLS_CC);
					PHALCON_CPY_WRT(select, r39);
				}
			}
		}
	}
	
	eval_int = phalcon_array_isset_string(params, "group", strlen("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r40);
		phalcon_array_fetch_string(&r40, params, "group", strlen("group"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r41);
		PHALCON_CONCAT_BOTH(r41,  " GROUP BY ", r40, " ");
		PHALCON_ALLOC_ZVAL_MM(r42);
		concat_function(r42, select, r41 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r42);
	}
	
	eval_int = phalcon_array_isset_string(params, "having", strlen("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r43);
		phalcon_array_fetch_string(&r43, params, "having", strlen("having"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r44);
		PHALCON_CONCAT_BOTH(r44,  " HAVING ", r43, " ");
		PHALCON_ALLOC_ZVAL_MM(r45);
		concat_function(r45, select, r44 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r45);
	}
	
	eval_int = phalcon_array_isset_string(params, "order", strlen("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r46);
		phalcon_array_fetch_string(&r46, params, "order", strlen("order"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r47);
		PHALCON_CONCAT_BOTH(r47,  " ORDER BY ", r46, " ");
		PHALCON_ALLOC_ZVAL_MM(r48);
		concat_function(r48, select, r47 TSRMLS_CC);
		PHALCON_CPY_WRT(select, r48);
	}
	
	eval_int = phalcon_array_isset_string(params, "limit", strlen("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r49);
		PHALCON_ALLOC_ZVAL_MM(r50);
		phalcon_array_fetch_string(&r50, params, "limit", strlen("limit"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2(r49, connection, "_limit", select, r50, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(select, r49);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r51);
	p12[0] = connection;
	p12[1] = params;
	p12[2] = select;
	p12[3] = alias;
	PHALCON_CALL_SELF_PARAMS(r51, this_ptr, "_getgroupresult", 4, p12);
	PHALCON_RETURN_DZVAL(r51);
}

PHP_METHOD(Phalcon_Model_Base, _getGroupResult){

	zval *connection = NULL, *params = NULL, *select_statement = NULL;
	zval *alias = NULL, *result_resource = NULL, *count = NULL, *row_object = NULL;
	zval *num = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
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
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init(i1);
			PHALCON_CPY_WRT(row_object, i1);
			
			PHALCON_INIT_VAR(result_resource);
			ZVAL_BOOL(result_resource, 0);
		}
		
		
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_model_resultset_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i2, "__construct", row_object, result_resource, PHALCON_CHECK);
		
		PHALCON_RETURN_CTOR(i2);
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

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

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
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "COUNT", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "rowcount", 1);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Allows to a calculate a summatory on a column that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return double
 */
PHP_METHOD(Phalcon_Model_Base, sum){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

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
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "SUM", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "sumatory", 1);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Base, maximum){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

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
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "MAX", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "maximum", 1);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * 
 *
 * @param array $params
 * @return mixed
 */
PHP_METHOD(Phalcon_Model_Base, minimum){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

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
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "MIN", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "minimum", 1);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * 
 *
 * @param array $params
 * @return double
 */
PHP_METHOD(Phalcon_Model_Base, average){

	zval *parameters = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL, *c1 = NULL;

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
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "AVG", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "average", 1);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	PHALCON_RETURN_DZVAL(r0);
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
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1 TSRMLS_CC);
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
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "gettype", message, 0x040);
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_BOTH(r1,  "Invalid message format '", r0, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
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
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", class_name, 0x012);
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
			if(0){}
		} else {
			return;
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
			if(0){}
		} else {
			return;
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

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
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

PHP_METHOD(Phalcon_Model_Base, _checkForeignKeys){

	zval *manager = NULL, *belongs_to = NULL, *error = NULL, *relation = NULL, *options = NULL;
	zval *foreign_key = NULL, *conditions = NULL, *referenced_model = NULL;
	zval *fields = NULL, *referenced_fields = NULL, *field = NULL, *n = NULL, *value = NULL;
	zval *rowcount = NULL, *user_message = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL, *r24 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CPY_WRT(manager, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, manager, "getbelongsto", this_ptr, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(belongs_to, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, belongs_to TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		if (phalcon_valid_foreach(belongs_to TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(belongs_to);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_6:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_6;
			}
			
			PHALCON_INIT_VAR(relation);
			ZVAL_ZVAL(relation, *hd, 1, 0);
			eval_int = phalcon_array_isset_string(relation, "op", strlen("op")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_string(&r2, relation, "op", strlen("op"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(options, r2);
				eval_int = phalcon_array_isset_string(options, "foreignKey", strlen("foreignKey")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(r3);
					phalcon_array_fetch_string(&r3, options, "foreignKey", strlen("foreignKey"), PHALCON_NOISY TSRMLS_CC);
					PHALCON_CPY_WRT(foreign_key, r3);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_VAR(a0);
						array_init(a0);
						PHALCON_CPY_WRT(conditions, a0);
						
						PHALCON_INIT_VAR(r4);
						
						PHALCON_INIT_VAR(r5);
						phalcon_array_fetch_string(&r5, relation, "rt", strlen("rt"), PHALCON_NOISY TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_1(r4, manager, "getmodel", r5, PHALCON_NO_CHECK);
						PHALCON_CPY_WRT(referenced_model, r4);
						
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch_string(&r6, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(fields, r6);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							PHALCON_INIT_VAR(r7);
							phalcon_array_fetch_string(&r7, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
							PHALCON_CPY_WRT(referenced_fields, r7);
							if (phalcon_valid_foreach(fields TSRMLS_CC)) {
								ah1 = Z_ARRVAL_P(fields);
								zend_hash_internal_pointer_reset_ex(ah1, &hp1);
								fes_f9eb_7:
								if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
									goto fee_f9eb_7;
								} else {
									PHALCON_INIT_VAR(n);
									PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								}
								PHALCON_INIT_VAR(field);
								ZVAL_ZVAL(field, *hd, 1, 0);
								PHALCON_INIT_VAR(t1);
								phalcon_read_property_zval(&t1, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
								PHALCON_CPY_WRT(value, t1);
								
								PHALCON_INIT_VAR(r9);
								phalcon_array_fetch(&r9, referenced_fields, n, PHALCON_NOISY TSRMLS_CC);
								
								PHALCON_INIT_VAR(r8);
								PHALCON_CONCAT_VBOTH(r8, r9, " = '", value);
								
								PHALCON_INIT_VAR(r10);
								PHALCON_CONCAT_RIGHT(r10, r8, "'");
								phalcon_array_append(&conditions, r10, PHALCON_SEPARATE_PLZ TSRMLS_CC);
								zend_hash_move_forward_ex(ah1, &hp1);
								goto fes_f9eb_7;
								fee_f9eb_7:
								if(0){}
							} else {
								return;
							}
						} else {
							PHALCON_INIT_VAR(t2);
							phalcon_read_property_zval(&t2, this_ptr, fields, PHALCON_NOISY TSRMLS_CC);
							PHALCON_CPY_WRT(value, t2);
							
							PHALCON_INIT_VAR(t3);
							ZVAL_NULL(t3);
							
							PHALCON_INIT_VAR(r11);
							is_identical_function(r11, t3, value TSRMLS_CC);
							
							PHALCON_INIT_VAR(t4);
							ZVAL_STRING(t4, "", 1);
							
							PHALCON_INIT_VAR(r12);
							is_identical_function(r12, t4, value TSRMLS_CC);
							
							PHALCON_INIT_VAR(r13);
							ZVAL_BOOL(r13, zend_is_true(r11) || zend_is_true(r12));
							if (zend_is_true(r13)) {
								goto fes_f9eb_6;
							}
							
							
							PHALCON_INIT_VAR(r15);
							phalcon_array_fetch_string(&r15, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
							
							PHALCON_INIT_VAR(r14);
							PHALCON_CONCAT_VBOTH(r14, r15, " = '", value);
							
							PHALCON_INIT_VAR(r16);
							PHALCON_CONCAT_RIGHT(r16, r14, "'");
							phalcon_array_append(&conditions, r16, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, "conditions", strlen("conditions")+1);
						if (eval_int) {
							PHALCON_INIT_VAR(r17);
							phalcon_array_fetch_string(&r17, foreign_key, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
							phalcon_array_append(&conditions, r17, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						}
						
						
						PHALCON_INIT_VAR(r18);
						PHALCON_CALL_METHOD(r18, this_ptr, "getconnection", PHALCON_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnection", r18, PHALCON_NO_CHECK);
						
						PHALCON_INIT_VAR(r19);
						
						PHALCON_INIT_VAR(c0);
						ZVAL_STRING(c0, " AND ", 1);
						
						PHALCON_INIT_VAR(r20);
						phalcon_fast_join(r20, c0, conditions TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_1(r19, referenced_model, "count", r20, PHALCON_NO_CHECK);
						PHALCON_CPY_WRT(rowcount, r19);
						if (!zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, "message", strlen("message")+1);
							if (eval_int) {
								PHALCON_INIT_VAR(r21);
								phalcon_array_fetch_string(&r21, foreign_key, "message", strlen("message"), PHALCON_NOISY TSRMLS_CC);
								PHALCON_CPY_WRT(user_message, r21);
							} else {
								if (Z_TYPE_P(fields) == IS_ARRAY) { 
									PHALCON_INIT_VAR(c1);
									ZVAL_STRING(c1, ", ", 1);
									PHALCON_INIT_VAR(r22);
									phalcon_fast_join(r22, c1, fields TSRMLS_CC);
									PHALCON_INIT_VAR(r23);
									PHALCON_CONCAT_BOTH(r23,  "Value of fields \"", r22, "\" does not exist on referenced table");
									PHALCON_CPY_WRT(user_message, r23);
								} else {
									PHALCON_INIT_VAR(r24);
									PHALCON_CONCAT_BOTH(r24,  "Value of field \"", fields, "\" does not exist on referenced table");
									PHALCON_CPY_WRT(user_message, r24);
								}
							}
							
							PHALCON_INIT_VAR(i0);
							object_init_ex(i0, phalcon_model_message_ce);
							
							PHALCON_INIT_VAR(c2);
							ZVAL_STRING(c2, "ConstraintViolation", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i0, "__construct", user_message, fields, c2, PHALCON_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", i0, PHALCON_NO_CHECK);
							
							PHALCON_INIT_VAR(error);
							ZVAL_BOOL(error, 1);
							goto fee_f9eb_6;
						}
					}
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_6;
			fee_f9eb_6:
			if(0){}
		} else {
			return;
		}
		if (zend_is_true(error)) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c3, PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _checkForeignKeysReverse){

	zval *manager = NULL, *relations = NULL, *error = NULL, *relation = NULL, *options = NULL;
	zval *foreign_key = NULL, *fields = NULL, *referenced_name = NULL;
	zval *referenced_fields = NULL, *referenced_model = NULL;
	zval *conditions = NULL, *field = NULL, *n = NULL, *value = NULL, *rowcount = NULL, *user_message = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL;
	zval *a0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CPY_WRT(manager, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, manager, "gethasoneandhasmany", this_ptr, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(relations, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_fast_count(r1, relations TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		if (phalcon_valid_foreach(relations TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(relations);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_8:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_8;
			}
			
			PHALCON_INIT_VAR(relation);
			ZVAL_ZVAL(relation, *hd, 1, 0);
			eval_int = phalcon_array_isset_string(relation, "op", strlen("op")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_string(&r2, relation, "op", strlen("op"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(options, r2);
				eval_int = phalcon_array_isset_string(options, "foreignKey", strlen("foreignKey")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(r3);
					phalcon_array_fetch_string(&r3, options, "foreignKey", strlen("foreignKey"), PHALCON_NOISY TSRMLS_CC);
					PHALCON_CPY_WRT(foreign_key, r3);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_VAR(r4);
						phalcon_array_fetch_string(&r4, relation, "fi", strlen("fi"), PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(fields, r4);
						
						PHALCON_INIT_VAR(r5);
						phalcon_array_fetch_string(&r5, relation, "rt", strlen("rt"), PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(referenced_name, r5);
						
						PHALCON_INIT_VAR(r6);
						phalcon_array_fetch_string(&r6, relation, "rf", strlen("rf"), PHALCON_NOISY TSRMLS_CC);
						PHALCON_CPY_WRT(referenced_fields, r6);
						
						PHALCON_INIT_VAR(r7);
						PHALCON_CALL_METHOD_PARAMS_1(r7, manager, "getmodel", referenced_name, PHALCON_NO_CHECK);
						PHALCON_CPY_WRT(referenced_model, r7);
						
						PHALCON_INIT_VAR(a0);
						array_init(a0);
						PHALCON_CPY_WRT(conditions, a0);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							if (phalcon_valid_foreach(fields TSRMLS_CC)) {
								ah1 = Z_ARRVAL_P(fields);
								zend_hash_internal_pointer_reset_ex(ah1, &hp1);
								fes_f9eb_9:
								if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
									goto fee_f9eb_9;
								} else {
									PHALCON_INIT_VAR(n);
									PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								}
								PHALCON_INIT_VAR(field);
								ZVAL_ZVAL(field, *hd, 1, 0);
								PHALCON_INIT_VAR(t1);
								phalcon_read_property_zval(&t1, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
								PHALCON_CPY_WRT(value, t1);
								
								PHALCON_INIT_VAR(r9);
								phalcon_array_fetch(&r9, referenced_fields, n, PHALCON_NOISY TSRMLS_CC);
								
								PHALCON_INIT_VAR(r8);
								PHALCON_CONCAT_VBOTH(r8, r9, " = '", value);
								
								PHALCON_INIT_VAR(r10);
								PHALCON_CONCAT_RIGHT(r10, r8, "'");
								phalcon_array_append(&conditions, r10, PHALCON_SEPARATE_PLZ TSRMLS_CC);
								zend_hash_move_forward_ex(ah1, &hp1);
								goto fes_f9eb_9;
								fee_f9eb_9:
								if(0){}
							} else {
								return;
							}
						} else {
							PHALCON_INIT_VAR(t2);
							phalcon_read_property_zval(&t2, this_ptr, fields, PHALCON_NOISY TSRMLS_CC);
							PHALCON_CPY_WRT(value, t2);
							
							PHALCON_INIT_VAR(r11);
							PHALCON_CONCAT_VBOTH(r11, referenced_fields, " = '", value);
							
							PHALCON_INIT_VAR(r12);
							PHALCON_CONCAT_RIGHT(r12, r11, "'");
							phalcon_array_append(&conditions, r12, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, "conditions", strlen("conditions")+1);
						if (eval_int) {
							PHALCON_INIT_VAR(r13);
							phalcon_array_fetch_string(&r13, foreign_key, "conditions", strlen("conditions"), PHALCON_NOISY TSRMLS_CC);
							phalcon_array_append(&conditions, r13, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						}
						
						
						PHALCON_INIT_VAR(r14);
						PHALCON_CALL_METHOD(r14, this_ptr, "getconnection", PHALCON_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnection", r14, PHALCON_NO_CHECK);
						
						PHALCON_INIT_VAR(r15);
						
						PHALCON_INIT_VAR(c0);
						ZVAL_STRING(c0, " AND ", 1);
						
						PHALCON_INIT_VAR(r16);
						phalcon_fast_join(r16, c0, conditions TSRMLS_CC);
						PHALCON_CALL_METHOD_PARAMS_1(r15, referenced_model, "count", r16, PHALCON_NO_CHECK);
						PHALCON_CPY_WRT(rowcount, r15);
						if (zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, "message", strlen("message")+1);
							if (eval_int) {
								PHALCON_INIT_VAR(r17);
								phalcon_array_fetch_string(&r17, foreign_key, "message", strlen("message"), PHALCON_NOISY TSRMLS_CC);
								PHALCON_CPY_WRT(user_message, r17);
							} else {
								PHALCON_INIT_VAR(r18);
								PHALCON_CONCAT_LEFT(r18, "Record is referenced by model ", referenced_name);
								PHALCON_CPY_WRT(user_message, r18);
							}
							
							PHALCON_INIT_VAR(i0);
							object_init_ex(i0, phalcon_model_message_ce);
							
							PHALCON_INIT_VAR(c1);
							ZVAL_STRING(c1, "ConstraintViolation", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i0, "__construct", user_message, fields, c1, PHALCON_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", i0, PHALCON_NO_CHECK);
							
							PHALCON_INIT_VAR(error);
							ZVAL_BOOL(error, 1);
							goto fee_f9eb_8;
						}
					}
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_8;
			fee_f9eb_8:
			if(0){}
		} else {
			return;
		}
		if (zend_is_true(error)) {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c2, PHALCON_NO_CHECK);
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Model_Base, _preSave){

	zval *disable_events = NULL, *exists = NULL, *identity_field = NULL;
	zval *generator = NULL, *not_null = NULL, *data_type_numeric = NULL;
	zval *error = NULL, *num_fields = NULL, *i = NULL, *is_null = NULL, *field = NULL, *value = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL, *r22 = NULL, *r23 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *c7 = NULL, *c8 = NULL, *c9 = NULL, *c10 = NULL, *c11 = NULL, *c12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &disable_events, &exists, &identity_field) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

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
	PHALCON_CALL_METHOD(r3, this_ptr, "_checkforeignkeys", PHALCON_NO_CHECK);
	if (Z_TYPE_P(r3) == IS_BOOL && !Z_BVAL_P(r3)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "getnotnullattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(not_null, r4);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_CALL_METHOD(r5, this_ptr, "getdatatypesnumeric", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type_numeric, r5);
	if (Z_TYPE_P(not_null) == IS_ARRAY) { 
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		phalcon_fast_count(r6, not_null TSRMLS_CC);
		PHALCON_CPY_WRT(num_fields, r6);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		fs_f9eb_10:
			
			PHALCON_INIT_VAR(r7);
			is_smaller_function(r7, i, num_fields TSRMLS_CC);
			if (!zend_is_true(r7)) {
				goto fe_f9eb_10;
			}
			PHALCON_INIT_VAR(is_null);
			ZVAL_BOOL(is_null, 0);
			
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch(&r8, not_null, i, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(field, r8);
			
			PHALCON_INIT_VAR(t0);
			phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(value, t0);
			eval_int = phalcon_array_isset(data_type_numeric, field);
			if (!eval_int) {
				PHALCON_INIT_VAR(t1);
				ZVAL_NULL(t1);
				PHALCON_INIT_VAR(r9);
				is_identical_function(r9, t1, value TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_STRING(t2, "", 1);
				PHALCON_INIT_VAR(r10);
				is_identical_function(r10, t2, value TSRMLS_CC);
				PHALCON_INIT_VAR(r11);
				ZVAL_BOOL(r11, zend_is_true(r9) || zend_is_true(r10));
				if (zend_is_true(r11)) {
					PHALCON_INIT_VAR(is_null);
					ZVAL_BOOL(is_null, 1);
				}
			} else {
				PHALCON_INIT_VAR(r12);
				PHALCON_CALL_FUNC_PARAMS_1(r12, "is_numeric", value, 0x02B);
				if (!zend_is_true(r12)) {
					PHALCON_INIT_VAR(is_null);
					ZVAL_BOOL(is_null, 1);
				}
			}
			
			if (zend_is_true(is_null)) {
				PHALCON_INIT_VAR(r13);
				boolean_not_function(r13, exists TSRMLS_CC);
				PHALCON_INIT_VAR(r14);
				is_equal_function(r14, field, identity_field TSRMLS_CC);
				PHALCON_INIT_VAR(r15);
				phalcon_and_function(r15, r13, r14);
				if (zend_is_true(r15)) {
					goto fi_f9eb_10;
				}
				
				PHALCON_INIT_VAR(i0);
				object_init_ex(i0, phalcon_model_message_ce);
				
				PHALCON_INIT_VAR(r16);
				PHALCON_CONCAT_RIGHT(r16, field, " is required");
				
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "PresenceOf", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i0, "__construct", r16, field, c3, PHALCON_CHECK);
				
				PHALCON_INIT_VAR(t3);
				phalcon_read_property(&t3, this_ptr, "_errorMessages", sizeof("_errorMessages")-1, PHALCON_NOISY TSRMLS_CC);
				phalcon_array_append(&t3, i0, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), t3 TSRMLS_CC);
				
				PHALCON_INIT_VAR(error);
				ZVAL_BOOL(error, 1);
			}
			fi_f9eb_10:
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto fs_f9eb_10;
		fe_f9eb_10:
		if (zend_is_true(error)) {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_VAR(c4);
				ZVAL_STRING(c4, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c4, PHALCON_NO_CHECK);
			}
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	
	PHALCON_INIT_VAR(c5);
	ZVAL_STRING(c5, "validation", 1);
	PHALCON_CALL_METHOD_PARAMS_1(r17, this_ptr, "_callevent", c5, PHALCON_NO_CHECK);
	if (Z_TYPE_P(r17) == IS_BOOL && !Z_BVAL_P(r17)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c6);
			ZVAL_STRING(c6, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c6, PHALCON_NO_CHECK);
		}
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	if (!zend_is_true(disable_events)) {
		if (!zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(r18);
			PHALCON_INIT_VAR(c7);
			ZVAL_STRING(c7, "afterValidationOnCreate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r18, this_ptr, "_callevent", c7, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r18) == IS_BOOL && !Z_BVAL_P(r18)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r19);
			PHALCON_INIT_VAR(c8);
			ZVAL_STRING(c8, "afterValidationOnUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r19, this_ptr, "_callevent", c8, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r19) == IS_BOOL && !Z_BVAL_P(r19)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(r20);
		
		PHALCON_INIT_VAR(c9);
		ZVAL_STRING(c9, "afterValidation", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r20, this_ptr, "_callevent", c9, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r20) == IS_BOOL && !Z_BVAL_P(r20)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		
		PHALCON_ALLOC_ZVAL_MM(r21);
		
		PHALCON_INIT_VAR(c10);
		ZVAL_STRING(c10, "beforeSave", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r21, this_ptr, "_callevent", c10, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r21) == IS_BOOL && !Z_BVAL_P(r21)) {
			PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		if (zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(r22);
			PHALCON_INIT_VAR(c11);
			ZVAL_STRING(c11, "beforeUpdate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r22, this_ptr, "_callevent", c11, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r22) == IS_BOOL && !Z_BVAL_P(r22)) {
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation", PHALCON_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_ALLOC_ZVAL_MM(r23);
			PHALCON_INIT_VAR(c12);
			ZVAL_STRING(c12, "beforeCreate", 1);
			PHALCON_CALL_METHOD_PARAMS_1(r23, this_ptr, "_callevent", c12, PHALCON_NO_CHECK);
			if (Z_TYPE_P(r23) == IS_BOOL && !Z_BVAL_P(r23)) {
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
	zval *identity_field = NULL, *fields = NULL, *values = NULL, *attributes = NULL;
	zval *field = NULL, *value = NULL, *id = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzzz", &connection, &table, &data_type, &data_type_numeric, &identity_field) == FAILURE) {
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
	PHALCON_CALL_METHOD(r0, this_ptr, "getattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(attributes, r0);
	if (phalcon_valid_foreach(attributes TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_11;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		PHALCON_INIT_VAR(r1);
		is_not_equal_function(r1, field, identity_field TSRMLS_CC);
		if (zend_is_true(r1)) {
			phalcon_array_append(&fields, field, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			
			PHALCON_INIT_VAR(t0);
			phalcon_read_property_zval(&t0, this_ptr, field, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(value, t0);
			if (Z_TYPE_P(value) == IS_OBJECT) {
				PHALCON_INIT_VAR(r2);
				phalcon_instance_of(r2, value, phalcon_db_rawvalue_ce TSRMLS_CC);
				if (zend_is_true(r2)) {
					PHALCON_INIT_VAR(r3);
					PHALCON_CALL_METHOD(r3, value, "getvalue", PHALCON_NO_CHECK);
					phalcon_array_append(&values, r3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r4);
					PHALCON_CALL_FUNC_PARAMS_1(r4, "strval", value, 0x051);
					phalcon_array_append(&values, r4, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				}
			} else {
				PHALCON_INIT_VAR(t1);
				ZVAL_STRING(t1, "", 1);
				PHALCON_INIT_VAR(r5);
				is_identical_function(r5, t1, value TSRMLS_CC);
				PHALCON_INIT_VAR(t2);
				ZVAL_NULL(t2);
				PHALCON_INIT_VAR(r6);
				is_identical_function(r6, t2, value TSRMLS_CC);
				PHALCON_INIT_VAR(r7);
				ZVAL_BOOL(r7, zend_is_true(r5) || zend_is_true(r6));
				if (zend_is_true(r7)) {
					PHALCON_INIT_VAR(t3);
					ZVAL_STRING(t3, "NULL", 1);
					phalcon_array_append(&values, t3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					eval_int = phalcon_array_isset(data_type_numeric, field);
					if (eval_int) {
						phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r8);
						phalcon_array_fetch(&r8, data_type, field, PHALCON_NOISY TSRMLS_CC);
						if (PHALCON_COMPARE_STRING(r8, "date")) {
							PHALCON_INIT_VAR(r9);
							PHALCON_INIT_VAR(t4);
							phalcon_read_property(&t4, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
							PHALCON_CALL_METHOD_PARAMS_1(r9, t4, "getdateusingformat", value, PHALCON_NO_CHECK);
							phalcon_array_append(&values, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(r10);
							PHALCON_CONCAT_BOTH(r10,  "'", value, "'");
							phalcon_array_append(&values, r10, PHALCON_SEPARATE_PLZ TSRMLS_CC);
						}
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_11;
		fee_f9eb_11:
		if(0){}
	} else {
		return;
	}
	if (zend_is_true(identity_field)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property_zval(&t5, this_ptr, identity_field, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(id, t5);
		phalcon_array_append(&fields, identity_field, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_FUNC_PARAMS_1(r11, "is_null", id, 0x041);
		
		PHALCON_INIT_VAR(t6);
		ZVAL_STRING(t6, "", 1);
		
		PHALCON_INIT_VAR(r12);
		is_identical_function(r12, t6, id TSRMLS_CC);
		
		PHALCON_INIT_VAR(r13);
		ZVAL_BOOL(r13, zend_is_true(r11) || zend_is_true(r12));
		if (zend_is_true(r13)) {
			PHALCON_INIT_VAR(t7);
			ZVAL_STRING(t7, "null", 1);
			phalcon_array_append(&values, t7, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		} else {
			phalcon_array_append(&values, id, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CALL_METHOD_PARAMS_3(r14, connection, "insert", table, values, fields, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r14);
}

PHP_METHOD(Phalcon_Model_Base, _doLowUpdate){

	zval *connection = NULL, *table = NULL, *data_type = NULL, *data_type_numeric = NULL;
	zval *fields = NULL, *values = NULL, *non_primary = NULL, *field = NULL, *value = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *p4[] = { NULL, NULL, NULL, NULL };
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
	PHALCON_CALL_METHOD(r0, this_ptr, "getnonprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(non_primary, r0);
	if (phalcon_valid_foreach(non_primary TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(non_primary);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_f9eb_12:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_f9eb_12;
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
				PHALCON_INIT_VAR(r3);
				PHALCON_CALL_FUNC_PARAMS_1(r3, "strval", value, 0x051);
				phalcon_array_append(&values, r3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			}
		} else {
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, "", 1);
			PHALCON_INIT_VAR(r4);
			is_identical_function(r4, t1, value TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_NULL(t2);
			PHALCON_INIT_VAR(r5);
			is_identical_function(r5, t2, value TSRMLS_CC);
			PHALCON_INIT_VAR(r6);
			ZVAL_BOOL(r6, zend_is_true(r4) || zend_is_true(r5));
			if (zend_is_true(r6)) {
				PHALCON_INIT_VAR(t3);
				ZVAL_STRING(t3, "NULL", 1);
				phalcon_array_append(&values, t3, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset(data_type_numeric, field);
				if (eval_int) {
					phalcon_array_append(&values, value, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r7);
					phalcon_array_fetch(&r7, data_type, field, PHALCON_NOISY TSRMLS_CC);
					if (PHALCON_COMPARE_STRING(r7, "date")) {
						PHALCON_INIT_VAR(r8);
						PHALCON_CALL_METHOD_PARAMS_1(r8, connection, "getdateusingformat", value, PHALCON_NO_CHECK);
						phalcon_array_append(&values, r8, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r9);
						PHALCON_CONCAT_BOTH(r9,  "'", value, "'");
						phalcon_array_append(&values, r9, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					}
				}
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_f9eb_12;
		fee_f9eb_12:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	p4[0] = table;
	p4[1] = fields;
	p4[2] = values;
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_uniqueKey", sizeof("_uniqueKey")-1, PHALCON_NOISY TSRMLS_CC);
	p4[3] = t4;
	PHALCON_CALL_METHOD_PARAMS(r10, connection, "update", 4, p4, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r10);
}

/**
 * Inserts or updates a model instance. Returns true on success or else false .
 *
 * 
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Base, save){

	zval *exists = NULL, *disable_events = NULL, *identity_field = NULL;
	zval *schema = NULL, *source = NULL, *table = NULL, *connection = NULL, *data_type = NULL;
	zval *primary_keys = NULL, *data_type_numeric = NULL, *success = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p9[] = { NULL, NULL, NULL, NULL }, *p10[] = { NULL, NULL, NULL, NULL, NULL };

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
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), a0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1 TSRMLS_CC);
	PHALCON_CPY_WRT(disable_events, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "getidentityfield", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(identity_field, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_presave", disable_events, exists, identity_field, PHALCON_NO_CHECK);
	if (Z_TYPE_P(r2) == IS_BOOL && !Z_BVAL_P(r2)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD(r3, this_ptr, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, this_ptr, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(source, r4);
	if (zend_is_true(schema)) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		PHALCON_CONCAT_VBOTH(r5, schema, ".", source);
		PHALCON_CPY_WRT(table, r5);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(connection, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD(r6, this_ptr, "getdatatypes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type, r6);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, this_ptr, "getprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(primary_keys, r7);
	
	PHALCON_ALLOC_ZVAL_MM(r8);
	PHALCON_CALL_METHOD(r8, this_ptr, "getdatatypesnumeric", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(data_type_numeric, r8);
	if (zend_is_true(exists)) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		p9[0] = connection;
		p9[1] = table;
		p9[2] = data_type;
		p9[3] = data_type_numeric;
		PHALCON_CALL_METHOD_PARAMS(r9, this_ptr, "_dolowupdate", 4, p9, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r9);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r10);
		p10[0] = connection;
		p10[1] = table;
		p10[2] = data_type;
		p10[3] = data_type_numeric;
		p10[4] = identity_field;
		PHALCON_CALL_METHOD_PARAMS(r10, this_ptr, "_dolowinsert", 5, p10, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r10);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r11);
	PHALCON_CALL_METHOD(r11, connection, "isundertransaction", PHALCON_NO_CHECK);
	if (!zend_is_true(r11)) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_METHOD(r12, connection, "gethaveautocommit", PHALCON_NO_CHECK);
		if (zend_is_true(r12)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "commit", PHALCON_NO_CHECK);
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	PHALCON_CALL_METHOD_PARAMS_3(r13, this_ptr, "_postsave", disable_events, success, exists, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r13);
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
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *a0 = NULL, *a1 = NULL;
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
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_errorMessages", strlen("_errorMessages"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, this_ptr, "_checkforeignkeysreverse", PHALCON_NO_CHECK);
	if (Z_TYPE_P(r1) == IS_BOOL && !Z_BVAL_P(r1)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD(r2, this_ptr, "getprimarykeyattributes", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(primary_keys, r2);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_fast_count(r3, primary_keys TSRMLS_CC);
	
	PHALCON_INIT_VAR(t4);
	ZVAL_LONG(t4, 1);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, r3, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_long(&r5, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
		phalcon_read_property_zval(&t5, this_ptr, r5, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(primary_key_value, t5);
		
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_long(&r7, primary_keys, 0, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_CONCAT_VBOTH(r6, r7, " = '", primary_key_value);
		
		PHALCON_ALLOC_ZVAL_MM(r8);
		PHALCON_CONCAT_RIGHT(r8, r6, "'");
		PHALCON_CPY_WRT(conditions, r8);
	} else {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(conditions, a1);
		if (phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(primary_keys);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_f9eb_13:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_f9eb_13;
			}
			
			PHALCON_INIT_VAR(primary_key);
			ZVAL_ZVAL(primary_key, *hd, 1, 0);
			PHALCON_INIT_VAR(t6);
			phalcon_read_property_zval(&t6, this_ptr, primary_key, PHALCON_NOISY TSRMLS_CC);
			PHALCON_CPY_WRT(primary_key_value, t6);
			
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_VBOTH(r9, primary_key, " = '", primary_key_value);
			
			PHALCON_INIT_VAR(r10);
			PHALCON_CONCAT_RIGHT(r10, r9, "'");
			phalcon_array_append(&conditions, r10, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_f9eb_13;
			fee_f9eb_13:
			if(0){}
		} else {
			return;
		}
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_fast_join(r11, c0, conditions TSRMLS_CC);
		PHALCON_CPY_WRT(conditions, r11);
	}
	
	PHALCON_OBSERVE_VAR(t7);
	phalcon_read_static_property(&t7, phalcon_model_base_ce, "_disableEvents", sizeof("_disableEvents")-1 TSRMLS_CC);
	PHALCON_CPY_WRT(disable_events, t7);
	if (!zend_is_true(disable_events)) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "beforeDelete", 1);
		PHALCON_CALL_METHOD_PARAMS_1(r12, this_ptr, "_callevent", c1, PHALCON_NO_CHECK);
		if (Z_TYPE_P(r12) == IS_BOOL && !Z_BVAL_P(r12)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_read_property(&t8, this_ptr, "_connection", sizeof("_connection")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2(r13, t8, "delete", table, conditions, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(success, r13);
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
	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
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
 * @param   array $options
 */
PHP_METHOD(Phalcon_Model_Base, hasOne){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_OBSERVE_VAR(t1);
		phalcon_read_static_property(&t1, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		p0[4] = options;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasone", 5, p0, PHALCON_NO_CHECK);
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
 * @param   array $options
 */
PHP_METHOD(Phalcon_Model_Base, belongsTo){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_OBSERVE_VAR(t1);
		phalcon_read_static_property(&t1, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		p0[4] = options;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addbelongsto", 5, p0, PHALCON_NO_CHECK);
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
 * @param   array $options
 */
PHP_METHOD(Phalcon_Model_Base, hasMany){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_OBSERVE_VAR(t1);
		phalcon_read_static_property(&t1, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
		p0[0] = this_ptr;
		p0[1] = fields;
		p0[2] = reference_model;
		p0[3] = referenced_fields;
		p0[4] = options;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "addhasmany", 5, p0, PHALCON_NO_CHECK);
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

	zval *method = NULL, *arguments = NULL, *manager_method = NULL, *model_name = NULL;
	zval *manager = NULL, *requested_relation = NULL, *query_method = NULL;
	zval *model_args = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL;
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
	
	PHALCON_INIT_VAR(manager_method);
	ZVAL_BOOL(manager_method, 0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_get_class(r0, this_ptr TSRMLS_CC);
	PHALCON_CPY_WRT(model_name, r0);
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, phalcon_model_base_ce, "_manager", sizeof("_manager")-1 TSRMLS_CC);
	PHALCON_CPY_WRT(manager, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 3);
	PHALCON_CALL_FUNC_PARAMS_3(r1, "substr", method, c0, c1, 0x002);
	if (PHALCON_COMPARE_STRING(r1, "get")) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_INIT_VAR(c2);
		ZVAL_LONG(c2, 3);
		PHALCON_CALL_FUNC_PARAMS_2(r2, "substr", method, c2, 0x002);
		PHALCON_CPY_WRT(requested_relation, r2);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD_PARAMS_2(r3, manager, "existsbelongsto", model_name, requested_relation, PHALCON_NO_CHECK);
		if (zend_is_true(r3)) {
			PHALCON_INIT_VAR(manager_method);
			ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			
			PHALCON_INIT_VAR(query_method);
			ZVAL_STRING(query_method, "findFirst", 1);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD_PARAMS_2(r4, manager, "existshasmany", model_name, requested_relation, PHALCON_NO_CHECK);
			if (zend_is_true(r4)) {
				PHALCON_INIT_VAR(manager_method);
				ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				
				PHALCON_INIT_VAR(query_method);
				ZVAL_STRING(query_method, "find", 1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r5);
				PHALCON_CALL_METHOD_PARAMS_2(r5, manager, "existshasone", model_name, requested_relation, PHALCON_NO_CHECK);
				if (zend_is_true(r5)) {
					PHALCON_INIT_VAR(manager_method);
					ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					
					PHALCON_INIT_VAR(query_method);
					ZVAL_STRING(query_method, "findFirst", 1);
				}
			}
		}
	}
	
	if (!zend_is_true(manager_method)) {
		PHALCON_ALLOC_ZVAL_MM(r6);
		PHALCON_INIT_VAR(c3);
		ZVAL_LONG(c3, 0);
		PHALCON_INIT_VAR(c4);
		ZVAL_LONG(c4, 5);
		PHALCON_CALL_FUNC_PARAMS_3(r6, "substr", method, c3, c4, 0x002);
		if (PHALCON_COMPARE_STRING(r6, "count")) {
			PHALCON_INIT_VAR(query_method);
			ZVAL_STRING(query_method, "count", 1);
			
			PHALCON_ALLOC_ZVAL_MM(r7);
			
			PHALCON_INIT_VAR(c5);
			ZVAL_LONG(c5, 5);
			PHALCON_CALL_FUNC_PARAMS_2(r7, "substr", method, c5, 0x002);
			PHALCON_CPY_WRT(requested_relation, r7);
			
			PHALCON_ALLOC_ZVAL_MM(r8);
			PHALCON_CALL_METHOD_PARAMS_2(r8, manager, "existsbelongsto", model_name, requested_relation, PHALCON_NO_CHECK);
			if (zend_is_true(r8)) {
				PHALCON_INIT_VAR(manager_method);
				ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r9);
				PHALCON_CALL_METHOD_PARAMS_2(r9, manager, "existshasmany", model_name, requested_relation, PHALCON_NO_CHECK);
				if (zend_is_true(r9)) {
					PHALCON_INIT_VAR(manager_method);
					ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r10);
					PHALCON_CALL_METHOD_PARAMS_2(r10, manager, "existshasone", model_name, requested_relation, PHALCON_NO_CHECK);
					if (zend_is_true(r10)) {
						PHALCON_INIT_VAR(manager_method);
						ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					}
				}
			}
		}
	}
	
	if (zend_is_true(manager_method)) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		phalcon_array_append(&a1, query_method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a1, model_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a1, requested_relation, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a1, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CPY_WRT(model_args, a1);
		
		PHALCON_ALLOC_ZVAL_MM(r11);
		
		PHALCON_INIT_VAR(a2);
		array_init(a2);
		phalcon_array_append(&a2, manager, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		phalcon_array_append(&a2, manager_method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r12);
		PHALCON_CALL_FUNC_PARAMS_2(r12, "array_merge", model_args, arguments, 0x043);
		PHALCON_CALL_FUNC_PARAMS_2(r11, "call_user_func_array", a2, r12, 0x013);
		PHALCON_RETURN_DZVAL(r11);
	}
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_exception_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r14);
	PHALCON_CONCAT_LEFT(r14, "The method \"", method);
	
	PHALCON_ALLOC_ZVAL_MM(r13);
	PHALCON_CONCAT_VBOTH(r13, r14, "\" doesn't exist on model \"", model_name);
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	PHALCON_CONCAT_RIGHT(r15, r13, "\"");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r15, PHALCON_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

