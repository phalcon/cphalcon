
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\Model\Criteria
 *
 * This class allows to build the array parameter required by Phalcon\Mvc\Model::find
 * and Phalcon\Mvc\Model::findFirst, using an object-oriented interfase
 */


/**
 * Phalcon\Mvc\Model\Criteria initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Criteria){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Criteria, mvc_model_criteria, phalcon_mvc_model_criteria_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_criteria_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_criteria_ce TSRMLS_CC, 2, phalcon_mvc_model_criteriainterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI){

	zval *dependency_injector;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Dependency Injector is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "di", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI){

	zval *params, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("di"))) {
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_array_fetch_string(&dependency_injector, params, SL("di"), PH_NOISY_CC);
		RETURN_CCTOR(dependency_injector);
	}
	
	RETURN_MM_NULL();
}

/**
 * Set a model on which the query will be executed
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName){

	zval *model_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(model_name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_model"), model_name TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Returns an internal model name on which the criteria will be applied
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName){

	zval *model;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	RETURN_CCTOR(model);
}

/**
 * Adds the bind parameter to the criteria
 *
 * @param string $bindParams
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind){

	zval *bind_params;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &bind_params) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(bind_params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bind parameters must be an Array");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "bind", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, bind_params TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, where){

	zval *conditions;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "conditions", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, conditions TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the conditions parameter to the criteria
 *
 * @param string $conditions
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions){

	zval *conditions;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(conditions) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Conditions must be string");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "conditions", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, conditions TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the order-by parameter to the criteria
 *
 * @param string $orderColumns
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, order){

	zval *order_columns;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &order_columns) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(order_columns) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Order columns must be string");
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "order", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, order_columns TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the limit parameter to the criteria
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit){

	zval *limit, *offset = NULL, *limit_clause;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &limit, &offset) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!offset) {
		PHALCON_INIT_NVAR(offset);
	}
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", limit);
	if (!zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Rows limit parameter must be integer");
		return;
	}
	if (Z_TYPE_P(offset) == IS_NULL) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "limit", 1);
		phalcon_update_property_array(this_ptr, SL("_params"), t0, limit TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(limit_clause);
		array_init_size(limit_clause, 2);
		phalcon_array_update_string(&limit_clause, SL("number"), &limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&limit_clause, SL("offset"), &offset, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "limit", 1);
		phalcon_update_property_array(this_ptr, SL("_params"), t1, limit_clause TSRMLS_CC);
	}
	
	
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the "for_update" parameter to the criteria
 *
 * @param boolean $forUpdate
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate){

	zval *for_update = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &for_update) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!for_update) {
		PHALCON_INIT_NVAR(for_update);
		ZVAL_BOOL(for_update, 1);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "for_update", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, for_update TSRMLS_CC);
	RETURN_CTOR(this_ptr);
}

/**
 * Adds the "shared_lock" parameter to the criteria
 *
 * @param boolean $sharedLock
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock){

	zval *shared_lock = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &shared_lock) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!shared_lock) {
		PHALCON_INIT_NVAR(shared_lock);
		ZVAL_BOOL(shared_lock, 1);
	}
	
	PHALCON_INIT_VAR(t0);
	ZVAL_STRING(t0, "shared_lock", 1);
	phalcon_update_property_array(this_ptr, SL("_params"), t0, shared_lock TSRMLS_CC);
	RETURN_CTOR(this_ptr);
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the conditions parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("conditions"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the limit parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("limit"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("limit"), PH_NOISY_CC);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the order parameter in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder){

	zval *params, *conditions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(params);
	phalcon_read_property(&params, this_ptr, SL("_params"), PH_NOISY_CC);
	if (phalcon_array_isset_string(params, SS("order"))) {
		PHALCON_OBS_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("order"), PH_NOISY_CC);
		RETURN_CCTOR(conditions);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns all the parameters defined in the criteria
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams){


	RETURN_MEMBER(this_ptr, "_params");
}

/**
 * Builds a Phalcon\Mvc\Model\Criteria based on an input array like $_POST
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param string $modelName
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput){

	zval *dependency_injector, *model_name, *data;
	zval *conditions, *service, *meta_data, *model;
	zval *data_types, *bind, *value = NULL, *field = NULL, *type = NULL, *condition = NULL;
	zval *value_pattern = NULL, *criteria, *join_conditions;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &dependency_injector, &model_name, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Input data must be an Array");
		return;
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	if (phalcon_fast_count_ev(data TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "modelsMetadata", 1);
	
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service);
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		if (phalcon_has_constructor(model TSRMLS_CC)) {
			PHALCON_CALL_METHOD_NORETURN(model, "__construct");
		}
	
		PHALCON_INIT_VAR(data_types);
		PHALCON_CALL_METHOD_PARAMS_1(data_types, meta_data, "getdatatypes", model);
	
		PHALCON_INIT_VAR(bind);
		array_init(bind);
	
		if (!phalcon_valid_foreach(data TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(data);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(field, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (phalcon_array_isset(data_types, field)) {
				if (Z_TYPE_P(value) != IS_NULL) {
					if (!PHALCON_COMPARE_STRING(value, "")) {
	
						PHALCON_OBS_NVAR(type);
						phalcon_array_fetch(&type, data_types, field, PH_NOISY_CC);
						if (phalcon_compare_strict_long(type, 2 TSRMLS_CC)) {
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, field, " LIKE :", field, ":");
	
							PHALCON_INIT_NVAR(value_pattern);
							PHALCON_CONCAT_SVS(value_pattern, "%", value, "%");
							phalcon_array_update_zval(&bind, field, &value_pattern, PH_COPY | PH_SEPARATE TSRMLS_CC);
						} else {
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, field, "=:", field, ":");
							phalcon_array_update_zval(&bind, field, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
						}
	
						phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
					}
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	if (phalcon_fast_count_ev(conditions TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_conditions);
		phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "where", join_conditions);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "bind", bind);
	}
	
	
	RETURN_CTOR(criteria);
}

/**
 * Executes a find using the parameters built with the criteria
 *
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute){

	zval *model, *params, *resultset;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(model);
	phalcon_read_property(&model, this_ptr, SL("_model"), PH_NOISY_CC);
	if (Z_TYPE_P(model) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Model name must be string");
		return;
	}
	
	PHALCON_INIT_VAR(params);
	PHALCON_CALL_METHOD(params, this_ptr, "getparams");
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_STATIC_ZVAL_PARAMS_1(resultset, model, "find", params);
	
	RETURN_CCTOR(resultset);
}

