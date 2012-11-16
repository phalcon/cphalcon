
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * Helps to create PHQL queries using an OO interface
 *
 *<code>
 *
 *</code>
 */


/**
 * Phalcon\Mvc\Model\Query\Builder initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Query, Builder, mvc_model_query_builder, phalcon_mvc_model_query_builder_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_models"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_joins"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_conditions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_group"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_having"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_order"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_limit"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_forUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_query_builder_ce, SL("_sharedLock"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_query_builder_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query\Builder
 *
 * @param array $params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct){

	zval *params, *dependency_injector = NULL, *conditions = NULL;
	zval *group_clause, *having_clause, *order_clause;
	zval *limit_clause, *for_update, *shared_lock;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(params, SS("di"));
	if (eval_int) {
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_array_fetch_string(&dependency_injector, params, SL("di"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	/** 
	 * Process conditions
	 */
	eval_int = phalcon_array_isset_long(params, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(conditions);
		phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SS("conditions"));
		if (eval_int) {
			PHALCON_INIT_NVAR(conditions);
			phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
		}
	}
	
	/** 
	 * Assign GROUP clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("group"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_clause);
		phalcon_array_fetch_string(&group_clause, params, SL("group"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_group"), group_clause TSRMLS_CC);
	}
	
	/** 
	 * Assign HAVING clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("having"));
	if (eval_int) {
		PHALCON_INIT_VAR(having_clause);
		phalcon_array_fetch_string(&having_clause, params, SL("having"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_group"), having_clause TSRMLS_CC);
	}
	
	/** 
	 * Assign ORDER clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("order"));
	if (eval_int) {
		PHALCON_INIT_VAR(order_clause);
		phalcon_array_fetch_string(&order_clause, params, SL("order"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_order"), order_clause TSRMLS_CC);
	}
	
	/** 
	 * Assign LIMIT clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit_clause);
		phalcon_array_fetch_string(&limit_clause, params, SL("limit"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_limit"), limit_clause TSRMLS_CC);
	}
	
	/** 
	 * Assign FOR UPDATE clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("for_update"));
	if (eval_int) {
		PHALCON_INIT_VAR(for_update);
		phalcon_array_fetch_string(&for_update, params, SL("for_update"), PH_NOISY_CC);
		if (zend_is_true(for_update)) {
			phalcon_update_property_bool(this_ptr, SL("_forUpdate"), 1 TSRMLS_CC);
		}
	}
	
	/** 
	 * Assign SHARED LOCK clause
	 */
	eval_int = phalcon_array_isset_string(params, SS("shared_lock"));
	if (eval_int) {
		PHALCON_INIT_VAR(shared_lock);
		phalcon_array_fetch_string(&shared_lock, params, SL("shared_lock"), PH_NOISY_CC);
		if (zend_is_true(shared_lock)) {
			phalcon_update_property_bool(this_ptr, SL("_sharedLock"), 1 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_url_exception_ce, "The dependency injector must be an Object");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the columns to be queried
 *
 * @param string|array $columns
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setColumns){

	zval *columns;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &columns) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns){


	RETURN_MEMBER(this_ptr, "_columns");
}

/**
 * Sets the models who makes part of the query
 *
 * @param string|array $models
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setModels){

	zval *models;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &models) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_models"), models TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Return the models who makes part of the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getModels){


	RETURN_MEMBER(this_ptr, "_models");
}

/**
 * Sets conditions for the query
 *
 * @param int $conditions
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setConditions){

	zval *conditions;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &conditions) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_conditions"), conditions TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Return the conditions for the query
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getConditions){


	RETURN_MEMBER(this_ptr, "_conditions");
}

/**
 * Sets a HAVING condition clause
 *
 * @param int $having
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setHaving){

	zval *having;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &having) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_having"), having TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Return the columns to be queried
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving){


	RETURN_MEMBER(this_ptr, "_having");
}

/**
 * Sets a LIMIT clause
 *
 * @param int $limit
 * @param int $offset
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setLimit){

	zval *limit, *offset = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &limit, &offset) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!offset) {
		PHALCON_INIT_NVAR(offset);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_limit"), limit TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Returns the current LIMIT clause
 *
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit){


	RETURN_MEMBER(this_ptr, "_limit");
}

/**
 * Sets a LIMIT clause
 *
 * @param string $group
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setGroup){

	zval *group;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_group"), group TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Returns the GROUP BY clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroup){


	RETURN_MEMBER(this_ptr, "_group");
}

/**
 * Returns a PHQL statement built based on the builder parameters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql){

	zval *dependency_injector, *models, *conditions = NULL;
	zval *one, *number_models, *invalid_condition;
	zval *model = NULL, *service_name, *meta_data, *model_instance;
	zval *no_primary = NULL, *primary_keys, *connection;
	zval *first_primary_key, *column_map, *attribute_field = NULL;
	zval *exception_message, *primary_key_condition;
	zval *phql, *columns, *joined_models, *group, *having;
	zval *order, *limit;
	zval *r0 = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(models);
	phalcon_read_property(&models, this_ptr, SL("_models"), PH_NOISY_CC);
	if (Z_TYPE_P(models) == IS_ARRAY) { 
		if (!phalcon_fast_count_ev(models TSRMLS_CC)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	} else {
		if (!zend_is_true(models)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "At least one model is required to build the query");
			return;
		}
	}
	
	PHALCON_INIT_VAR(conditions);
	phalcon_read_property(&conditions, this_ptr, SL("_conditions"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_numeric", conditions);
	if (zend_is_true(r0)) {
		if (Z_TYPE_P(models) == IS_ARRAY) { 
			PHALCON_INIT_VAR(one);
			ZVAL_LONG(one, 1);
	
			PHALCON_INIT_VAR(number_models);
			phalcon_fast_count(number_models, models TSRMLS_CC);
	
			PHALCON_INIT_VAR(invalid_condition);
			is_smaller_function(invalid_condition, one, number_models TSRMLS_CC);
			if (PHALCON_IS_TRUE(invalid_condition)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot build the query. Invalid condition");
				return;
			}
	
			PHALCON_INIT_VAR(model);
			phalcon_array_fetch_long(&model, models, 0, PH_NOISY_CC);
		} else {
			PHALCON_CPY_WRT(model, models);
		}
	
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "modelsMetadata", 1);
	
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service_name, PH_NO_CHECK);
		ce0 = phalcon_fetch_class(model TSRMLS_CC);
	
		PHALCON_INIT_VAR(model_instance);
		object_init_ex(model_instance, ce0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model_instance, "__construct", dependency_injector, PH_CHECK);
	
		PHALCON_INIT_VAR(no_primary);
		ZVAL_BOOL(no_primary, 1);
	
		PHALCON_INIT_VAR(primary_keys);
		PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", model_instance, PH_NO_CHECK);
		if (phalcon_fast_count_ev(primary_keys TSRMLS_CC)) {
			eval_int = phalcon_array_isset_long(primary_keys, 0);
			if (eval_int) {
				PHALCON_INIT_VAR(connection);
				PHALCON_CALL_METHOD(connection, model_instance, "getconnection", PH_NO_CHECK);
	
				PHALCON_INIT_VAR(first_primary_key);
				phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY_CC);
	
				PHALCON_INIT_VAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", model_instance, PH_NO_CHECK);
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					eval_int = phalcon_array_isset(column_map, first_primary_key);
					if (eval_int) {
						PHALCON_INIT_VAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, first_primary_key, PH_NOISY_CC);
					} else {
						PHALCON_INIT_VAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", first_primary_key, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, first_primary_key);
				}
	
				PHALCON_INIT_VAR(primary_key_condition);
				PHALCON_CONCAT_VSV(primary_key_condition, attribute_field, " = ", conditions);
				PHALCON_CPY_WRT(conditions, primary_key_condition);
	
				ZVAL_BOOL(no_primary, 0);
			}
		}
	
		if (PHALCON_IS_TRUE(no_primary)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
			return;
		}
	}
	
	PHALCON_INIT_VAR(phql);
	ZVAL_STRING(phql, "SELECT ", 1);
	
	PHALCON_INIT_VAR(columns);
	phalcon_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) != IS_NULL) {
		phalcon_concat_self(phql, columns TSRMLS_CC);
	} else {
		if (Z_TYPE_P(models) == IS_ARRAY) { 
	
			if (!phalcon_valid_foreach(models TSRMLS_CC)) {
				return;
			}
	
			ah0 = Z_ARRVAL_P(models);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
			ph_cycle_start_0:
	
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
	
				PHALCON_GET_FOREACH_VALUE(model);
	
				PHALCON_SCONCAT_VS(phql, model, ".*");
	
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
	
			ph_cycle_end_0:
			if(0){}
	
		} else {
			PHALCON_SCONCAT_VS(phql, models, ".*");
		}
	}
	
	if (Z_TYPE_P(models) == IS_ARRAY) { 
		PHALCON_INIT_VAR(joined_models);
		phalcon_fast_join_str(joined_models, SL(", "), models TSRMLS_CC);
		PHALCON_SCONCAT_SV(phql, " FROM ", joined_models);
	} else {
		PHALCON_SCONCAT_SV(phql, " FROM ", models);
	}
	
	if (zend_is_true(conditions)) {
		PHALCON_SCONCAT_SV(phql, " WHERE ", conditions);
	}
	
	PHALCON_INIT_VAR(group);
	phalcon_read_property(&group, this_ptr, SL("_group"), PH_NOISY_CC);
	if (Z_TYPE_P(group) != IS_NULL) {
		PHALCON_SCONCAT_SV(phql, " GROUP BY ", group);
	
		PHALCON_INIT_VAR(having);
		phalcon_read_property(&having, this_ptr, SL("_having"), PH_NOISY_CC);
		if (Z_TYPE_P(having) != IS_NULL) {
			PHALCON_SCONCAT_SV(phql, " HAVING ", having);
		}
	}
	
	PHALCON_INIT_VAR(order);
	phalcon_read_property(&order, this_ptr, SL("_order"), PH_NOISY_CC);
	if (Z_TYPE_P(order) != IS_NULL) {
		PHALCON_SCONCAT_SV(phql, " ORDER BY ", order);
	}
	
	PHALCON_INIT_VAR(limit);
	phalcon_read_property(&limit, this_ptr, SL("_limit"), PH_NOISY_CC);
	if (Z_TYPE_P(limit) != IS_NULL) {
		PHALCON_SCONCAT_SV(phql, " LIMIT ", limit);
	}
	
	zend_print_zval(phql, 1);
	
	PHALCON_INIT_VAR(t0);
	zend_get_constant(SL("PHP_EOL"), t0 TSRMLS_CC);
	zend_print_zval(t0, 1);
	
	RETURN_CTOR(phql);
}

/**
 * Returns the query built
 *
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery){

	zval *phql, *query, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(phql);
	PHALCON_CALL_METHOD(phql, this_ptr, "getphql", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql, PH_CHECK);
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector, PH_NO_CHECK);
	
	RETURN_CTOR(query);
}

