
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Model\Query
 *
 * Phalcon\Model\Query is designed to simplify building of search on models.
 * It provides a set of helpers to generate searchs in a dynamic way to support differents databases.
 *
 * 
 *
 */

PHP_METHOD(Phalcon_Model_Query, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;

	PHALCON_MM_GROW();

	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_model_query_ce, this_ptr, SL("_data"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_model_query_ce, this_ptr, SL("_models"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	zend_update_property(phalcon_model_query_ce, this_ptr, SL("_parameters"), a2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	zend_update_property(phalcon_model_query_ce, this_ptr, SL("_conditions"), a3 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Set the Phalcon_Model_Manager instance to use in a query
 *
 * @param Phalcon\Model\Manager $manager
 */
PHP_METHOD(Phalcon_Model_Query, setManager){

	zval *manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_manager"), manager TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, SL("_models"), PH_NOISY_CC);
	phalcon_array_append(&t0, model, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_models"), t0 TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, SL("_conditions"), PH_NOISY_CC);
	phalcon_array_append(&t0, condition, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_conditions"), t0 TSRMLS_CC);
	
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

	phalcon_update_property_zval(this_ptr, SL("_parameters"), parameter TSRMLS_CC);
	
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

	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_model_exception_ce, "Data parameter must be an Array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_data"), data TSRMLS_CC);
	
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

	phalcon_update_property_zval(this_ptr, SL("_limit"), limit TSRMLS_CC);
	
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
	zval *connection = NULL, *i = NULL, *parameters = NULL, *conditions = NULL;
	zval *value = NULL, *param = NULL, *condition = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *c0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (!zend_is_true(t0)) {
		PHALCON_INIT_VAR(controller_front);
		PHALCON_CALL_STATIC(controller_front, "phalcon\\controller\\front", "getinstance");
		
		PHALCON_INIT_VAR(model_manager);
		PHALCON_CALL_METHOD(model_manager, controller_front, "getmodelcomponent", PH_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "setmanager", model_manager, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(model_manager);
		phalcon_read_property(&model_manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_models"), PH_NOISY_CC);
	if (phalcon_valid_foreach(t1 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_a355_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_a355_0;
		}
		
		PHALCON_INIT_VAR(model_name);
		ZVAL_ZVAL(model_name, *hd, 1, 0);
		PHALCON_INIT_VAR(entity);
		PHALCON_CALL_METHOD_PARAMS_1(entity, model_manager, "getmodel", model_name, PH_NO_CHECK);
		if (!zend_is_true(entity)) {
			PHALCON_INIT_VAR(i0);
			object_init_ex(i0, phalcon_model_exception_ce);
			PHALCON_INIT_VAR(r0);
			PHALCON_CONCAT_SVS(r0, "The model ", model_name, " does not exist");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
		
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD(meta_data, model_manager, "getmetadata", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(attributes);
		PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", entity, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(numeric_types);
		PHALCON_CALL_METHOD_PARAMS_1(numeric_types, meta_data, "getdatatypesnumeric", entity, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, entity, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, SL("_data"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(r1);
		phalcon_fast_count(r1, t2 TSRMLS_CC);
		if (zend_is_true(r1)) {
			PHALCON_INIT_VAR(i);
			ZVAL_LONG(i, 0);
			
			PHALCON_INIT_VAR(parameters);
			array_init(parameters);
			
			PHALCON_INIT_VAR(conditions);
			array_init(conditions);
			
			PHALCON_INIT_VAR(t3);
			phalcon_read_property(&t3, this_ptr, SL("_data"), PH_NOISY_CC);
			if (phalcon_valid_foreach(t3 TSRMLS_CC)) {
				ah1 = Z_ARRVAL_P(t3);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
				fes_a355_1:
				if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
					goto fee_a355_1;
				} else {
					PHALCON_INIT_VAR(param);
					PHALCON_GET_FOREACH_KEY(param, ah1, hp1);
				}
				PHALCON_INIT_VAR(value);
				ZVAL_ZVAL(value, *hd, 1, 0);
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_FUNC_PARAMS_2(r2, "in_array", param, attributes);
				if (zend_is_true(r2)) {
					PHALCON_INIT_VAR(t4);
					ZVAL_STRING(t4, "", 1);
					PHALCON_INIT_VAR(r3);
					is_not_identical_function(r3, t4, value TSRMLS_CC);
					PHALCON_INIT_VAR(r5);
					PHALCON_CALL_FUNC_PARAMS_1(r5, "is_null", value);
					PHALCON_INIT_VAR(r4);
					boolean_not_function(r4, r5 TSRMLS_CC);
					PHALCON_INIT_VAR(r6);
					phalcon_and_function(r6, r3, r4);
					if (zend_is_true(r6)) {
						if (!PHALCON_COMPARE_STRING(value, "@")) {
							eval_int = phalcon_array_isset(numeric_types, param);
							if (eval_int) {
								PHALCON_INIT_VAR(condition);
								PHALCON_CONCAT_VSV(condition, param, " = ?", i);
								phalcon_array_update(&parameters, i, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
							} else {
								PHALCON_INIT_VAR(condition);
								PHALCON_CONCAT_VSV(condition, param, " LIKE ?", i);
								
								PHALCON_INIT_VAR(r7);
								PHALCON_CONCAT_SVS(r7, "%", value, "%");
								phalcon_array_update(&parameters, i, &r7, PH_COPY | PH_SEPARATE TSRMLS_CC);
							}
							phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
						}
					}
				}
				PHALCON_SEPARATE(i);
				increment_function(i);
				zend_hash_move_forward_ex(ah1, &hp1);
				goto fes_a355_1;
				fee_a355_1:
				if(0){}
			} else {
				return;
			}
		} else {
			PHALCON_INIT_VAR(parameters);
			phalcon_read_property(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(conditions);
			phalcon_read_property(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
		}
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, " AND ", 1);
		
		PHALCON_INIT_VAR(r8);
		phalcon_fast_join(r8, c0, conditions TSRMLS_CC);
		
		PHALCON_INIT_VAR(r9);
		PHALCON_CALL_METHOD_PARAMS_2(r9, connection, "bindparams", r8, parameters, PH_NO_CHECK);
		PHALCON_CPY_WRT(conditions, r9);
		if (PHALCON_COMPARE_STRING(conditions, "")) {
			PHALCON_INIT_VAR(conditions);
			ZVAL_STRING(conditions, "1=1", 1);
		}
		
		
		RETURN_CCTOR(conditions);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_a355_0;
		fee_a355_0:
		if(0){}
	} else {
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Get instance of model query
 *
 * @param string $modelName
 * @param array $data
 * @return Phalcon\Model\Query
 */
PHP_METHOD(Phalcon_Model_Query, fromInput){

	zval *model_name = NULL, *data = NULL, *query = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_model_query_ce);
	PHALCON_CALL_METHOD_NORETURN(query, "__construct", PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "from", model_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setinputdata", data, PH_NO_CHECK);
	
	RETURN_CTOR(query);
}

