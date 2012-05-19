
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

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Model_Query
 *
 * Phalcon_Model_Query is designed to simplify building of search on models.
 * It provides a set of helpers to generate searchs in a dynamic way to support differents databases.
 *
 * 
 *
 */

PHP_METHOD(Phalcon_Model_Query, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_model_query_ce, this_ptr, "_models", strlen("_models"), a0 TSRMLS_CC);
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_model_query_ce, this_ptr, "_parameters", strlen("_parameters"), a1 TSRMLS_CC);
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_model_query_ce, this_ptr, "_conditions", strlen("_conditions"), a2 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Set the data to use to make the conditions in query
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Model_Query, setInputData){

	zval *data = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_data", strlen("_data"), data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the Phalcon_Model_Manager instance to use in a query
 *
 * 
 *
 * @param Phalcon_Model_Manager $manager
 */
PHP_METHOD(Phalcon_Model_Query, setManager){

	zval *manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_manager", strlen("_manager"), manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add models to use in query
 *
 * @param string $model
 */
PHP_METHOD(Phalcon_Model_Query, from){

	zval *model = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t0, model, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_models", strlen("_models"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Add conditions to use in query
 *
 * @param string $condition
 */
PHP_METHOD(Phalcon_Model_Query, where){

	zval *condition = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &condition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&t0, condition, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_conditions", strlen("_conditions"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set parameter in query to different database adapters.
 *
 * @param string $parameter
 */
PHP_METHOD(Phalcon_Model_Query, setParameters){

	zval *parameter = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &parameter) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_parameters", strlen("_parameters"), parameter TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the limit of rows to show
 *
 * @param int $limit
 */
PHP_METHOD(Phalcon_Model_Query, setLimit){

	zval *limit = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &limit) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_limit", strlen("_limit"), limit TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Model_Query, getResultset){


	
}

/**
 * Get the conditions of query
 *
 * @return string $query
 */
PHP_METHOD(Phalcon_Model_Query, getConditions){

	zval *controller_front = NULL, *model_manager = NULL, *model_name = NULL;
	zval *entity = NULL, *meta_data = NULL, *attributes = NULL, *numeric_types = NULL;
	zval *i = NULL, *parameters = NULL, *value = NULL, *param = NULL, *condition = NULL, *condition_where = NULL;
	zval *where = NULL, *parameter_index = NULL, *ret = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL, *r18 = NULL, *r19 = NULL, *r20 = NULL;
	zval *r21 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_STATIC(r0, "phalcon_controller_front", "getinstance");
		PHALCON_CPY_WRT(controller_front, r0);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, controller_front, "getmodelcomponent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(model_manager, r1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setmanager", model_manager, PHALCON_NO_CHECK);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_manager", sizeof("_manager")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(model_manager, t1);
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_models", sizeof("_models")-1, PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(t2 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t2);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_a355_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_a355_0;
		}
		PHALCON_INIT_VAR(model_name);
		ZVAL_ZVAL(model_name, *hd, 1, 0);
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD_PARAMS_1(r2, model_manager, "getmodel", model_name, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(entity, r2);
		if (!zend_is_true(entity)) {
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_exception_ce);
			PHALCON_INIT_VAR(r3);
			PHALCON_CONCAT_BOTH(r3,  "The model ", model_name, " does not exist");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r3, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
		PHALCON_INIT_VAR(r4);
		PHALCON_CALL_METHOD(r4, model_manager, "getmetadata", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(meta_data, r4);
		PHALCON_INIT_VAR(r5);
		PHALCON_CALL_METHOD_PARAMS_1(r5, meta_data, "getattributes", entity, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(attributes, r5);
		PHALCON_INIT_VAR(r6);
		PHALCON_CALL_METHOD_PARAMS_1(r6, meta_data, "getdatatypesnumeric", entity, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(numeric_types, r6);
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(parameters, a0);
		PHALCON_INIT_VAR(t3);
		phalcon_read_property(&t3, this_ptr, "_data", sizeof("_data")-1, PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(t3 TSRMLS_CC)) {
			ah1 = Z_ARRVAL_P(t3);
			zend_hash_internal_pointer_reset_ex(ah1, &hp1);
			fes_a355_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_a355_1;
			} else {
				PHALCON_INIT_VAR(param);
				hash_type = zend_hash_get_current_key_ex(ah1, &hash_index, &hash_index_len, &hash_num, 0, &hp1);
				if (hash_type == HASH_KEY_IS_STRING) {
					ZVAL_STRINGL(param, hash_index, hash_index_len-1, 1);
				} else {
					if (hash_type == HASH_KEY_IS_LONG) {
						ZVAL_LONG(param, hash_num);
					}
				}
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(r7);
			PHALCON_CALL_FUNC_PARAMS_2(r7, "in_array", param, attributes, 0x03E);
			if (zend_is_true(r7)) {
				PHALCON_INIT_VAR(t4);
				ZVAL_STRING(t4, "@", 1);
				PHALCON_INIT_VAR(r8);
				is_not_equal_function(r8, value, t4 TSRMLS_CC);
				PHALCON_INIT_VAR(r9);
				phalcon_and_function(r9, value, r8);
				if (zend_is_true(r9)) {
					eval_int = phalcon_array_isset(numeric_types, param);
					if (eval_int) {
						PHALCON_INIT_VAR(r10);
						PHALCON_CONCAT_VBOTH(r10, param, " = ?", i);
						PHALCON_CPY_WRT(condition, r10);
						phalcon_array_update(&parameters, i, value, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r11);
						PHALCON_CONCAT_VBOTH(r11, param, " LIKE ?", i);
						PHALCON_CPY_WRT(condition, r11);
						PHALCON_INIT_VAR(r12);
						PHALCON_CONCAT_BOTH(r12,  "%", value, "%");
						phalcon_array_update(&parameters, i, r12, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					}
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "where", condition, PHALCON_NO_CHECK);
				}
			}
			phalcon_increment_function(&i, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_a355_1;
			fee_a355_1:
			if(0){ };
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setparameters", parameters, PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(condition_where, a1);
		PHALCON_INIT_VAR(t5);
		phalcon_read_property(&t5, this_ptr, "_parameters", sizeof("_parameters")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(parameters, t5);
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(&t6, this_ptr, "_conditions", sizeof("_conditions")-1, PHALCON_NOISY TSRMLS_CC);
		if (phalcon_valid_foreach(t6 TSRMLS_CC)) {
			ah2 = Z_ARRVAL_P(t6);
			zend_hash_internal_pointer_reset_ex(ah2, &hp2);
			fes_a355_2:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_a355_2;
			}
			PHALCON_INIT_VAR(condition);
			ZVAL_ZVAL(condition, *hd, 1, 0);
			PHALCON_INIT_VAR(r13);
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "?", 1);
			PHALCON_CALL_FUNC_PARAMS_2(r13, "explode", c0, condition, 0x009);
			PHALCON_CPY_WRT(where, r13);
			eval_int = phalcon_array_isset_long(where, 1);
			if (eval_int) {
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch_long(&r14, where, 1, PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(parameter_index, r14);
				eval_int = phalcon_array_isset(parameters, parameter_index);
				if (eval_int) {
					PHALCON_INIT_VAR(r15);
					phalcon_array_fetch(&r15, parameters, parameter_index, PHALCON_NOISY TSRMLS_CC);
					PHALCON_CPY_WRT(value, r15);
					if (zend_is_true(value)) {
						PHALCON_INIT_VAR(r17);
						phalcon_array_fetch_long(&r17, where, 0, PHALCON_NOISY TSRMLS_CC);
						PHALCON_INIT_VAR(r16);
						PHALCON_CONCAT_VBOTH(r16, r17, " '", value);
						PHALCON_INIT_VAR(r18);
						PHALCON_CONCAT_RIGHT(r18, r16, "'");
						phalcon_array_append(&condition_where, r18, PHALCON_SEPARATE_PLZ TSRMLS_CC);
					}
				} else {
					PHALCON_INIT_VAR(i1);
					object_init_ex(i1, phalcon_model_exception_ce);
					PHALCON_INIT_VAR(r19);
					PHALCON_CONCAT_BOTH(r19,  "Placeholder ", parameter_index, " could not be replaced");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r19, PHALCON_CHECK);
					phalcon_throw_exception(i1 TSRMLS_CC);
					return;
				}
			}
			zend_hash_move_forward_ex(ah2, &hp2);
			goto fes_a355_2;
			fee_a355_2:
			if(0){ };
		}
		PHALCON_INIT_VAR(r20);
		phalcon_fast_count(r20, condition_where TSRMLS_CC);
		if (!zend_is_true(r20)) {
			PHALCON_INIT_VAR(ret);
			ZVAL_STRING(ret, "1=1", 1);
		} else {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, " AND ", 1);
			PHALCON_INIT_VAR(r21);
			phalcon_fast_join(r21, c1, condition_where TSRMLS_CC);
			PHALCON_CPY_WRT(ret, r21);
		}
		PHALCON_RETURN_CHECK_CTOR(ret);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_a355_0;
		fee_a355_0:
		if(0){ };
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Get instace of model query
 *
 * @param string $modelName
 * @param array $data
 * @return Phalcon_Model_Query $query
 */
PHP_METHOD(Phalcon_Model_Query, fromInput){

	zval *model_name = NULL, *data = NULL, *query = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_model_query_ce);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(query, i0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "from", model_name, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setinputdata", data, PHALCON_NO_CHECK);
	PHALCON_RETURN_CTOR(query);
}

