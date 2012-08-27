
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

#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model
 *
 * Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.
 *
 * 
 *
 */

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DI $dependencyInjector
 * @param string $managerService
 * @param string $dbService
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct){

	zval *dependency_injector = NULL, *manager_service = NULL;
	zval *db_service = NULL, *manager = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &dependency_injector, &manager_service, &db_service) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!dependency_injector) {
		PHALCON_ALLOC_ZVAL_MM(dependency_injector);
		ZVAL_NULL(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	if (!manager_service) {
		PHALCON_ALLOC_ZVAL_MM(manager_service);
		ZVAL_NULL(manager_service);
	}
	
	if (!db_service) {
		PHALCON_ALLOC_ZVAL_MM(db_service);
		ZVAL_NULL(db_service);
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_VAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(manager, "initialize", this_ptr, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager){

	zval *events_manager = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Creates a SQL statement which returns many rows
 *
 * @param Phalcon\DI $dependencyInjector
 * @param Phalcon\Mvc\Model $model
 * @param Phalcon\Db $connection
 * @param array $params
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, _createSQLSelect){

	zval *dependency_injector = NULL, *model = NULL, *connection = NULL;
	zval *params = NULL, *meta_data = NULL, *source = NULL, *schema = NULL, *select = NULL;
	zval *attributes = NULL, *table = NULL, *conditions = NULL, *no_primary = NULL;
	zval *primary_keys = NULL, *first_primary_key = NULL, *bind_params = NULL;
	zval *bind_conditions = NULL, *group_clause = NULL, *order_clause = NULL;
	zval *limit_clause = NULL, *for_update = NULL, *shared_lock = NULL;
	zval *dialect = NULL, *sql = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &dependency_injector, &model, &connection, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(select);
	array_init(select);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", model, PH_NO_CHECK);
	phalcon_array_update_string(&select, SL("columns"), &attributes, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema, ".", source);
		phalcon_array_update_string(&select, SL("tables"), &table, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		phalcon_array_update_string(&select, SL("tables"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(conditions);
	ZVAL_NULL(conditions);
	eval_int = phalcon_array_isset_string(params, SL("conditions")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(no_primary);
			ZVAL_BOOL(no_primary, 0);
			
			PHALCON_INIT_VAR(conditions);
			phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
			if (Z_TYPE_P(conditions) == IS_LONG) {
				PHALCON_INIT_VAR(primary_keys);
				PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", model, PH_NO_CHECK);
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_INIT_VAR(first_primary_key);
					phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY_CC);
					
					PHALCON_ALLOC_ZVAL_MM(r0);
					PHALCON_CONCAT_VSV(r0, first_primary_key, " = ", conditions);
					PHALCON_CPY_WRT(conditions, r0);
				} else {
					PHALCON_INIT_VAR(no_primary);
					ZVAL_BOOL(no_primary, 1);
				}
				
				if (Z_TYPE_P(no_primary) == IS_BOOL && Z_BVAL_P(no_primary)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
					return;
				}
			}
		}
	}
	
	if (zend_is_true(conditions)) {
		eval_int = phalcon_array_isset_string(params, SL("bind")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(bind_params);
			phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(bind_conditions);
			PHALCON_CALL_METHOD_PARAMS_2(bind_conditions, connection, "bindparams", conditions, bind_params, PH_NO_CHECK);
			phalcon_array_update_string(&select, SL("where"), &bind_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&select, SL("where"), &conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("group")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(group_clause);
		phalcon_array_fetch_string(&group_clause, params, SL("group"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("group"), &group_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("order")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(order_clause);
		phalcon_array_fetch_string(&order_clause, params, SL("order"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("order"), &order_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit_clause);
		phalcon_array_fetch_string(&limit_clause, params, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("limit"), &limit_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("for_update")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(for_update);
		phalcon_array_fetch_string(&for_update, params, SL("for_update"), PH_NOISY_CC);
		if (zend_is_true(for_update)) {
			phalcon_array_update_string_bool(&select, SL("for_update"), 1, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SL("shared_lock")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(shared_lock);
		phalcon_array_fetch_string(&shared_lock, params, SL("shared_lock"), PH_NOISY_CC);
		if (zend_is_true(shared_lock)) {
			phalcon_array_update_string_bool(&select, SL("shared_lock"), 1, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, dialect, "select", select, PH_NO_CHECK);
	
	RETURN_CCTOR(sql);
}

/**
 * Gets a resulset from the cache or creates one
 *
 * @param string $modelName
 * @param Phalcon\Db $connection
 * @param array $params
 * @param boolean $unique
 */
PHP_METHOD(Phalcon_Mvc_Model, _getOrCreateResultset){

	zval *model_name = NULL, *params = NULL, *unique = NULL, *dependency_injector = NULL;
	zval *cache = NULL, *select = NULL, *key = NULL, *lifetime = NULL, *cache_service = NULL;
	zval *cache_options = NULL, *model = NULL, *connection = NULL, *md5select = NULL;
	zval *resultset = NULL, *result = NULL, *count = NULL, *row = NULL, *dumped_result = NULL;
	zval *result_data = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL }, *p1[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model_name, &params, &unique) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	
	PHALCON_INIT_VAR(cache);
	ZVAL_NULL(cache);
	
	PHALCON_INIT_VAR(select);
	ZVAL_NULL(select);
	eval_int = phalcon_array_isset_string(params, SL("cache")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(key);
		ZVAL_NULL(key);
		
		PHALCON_INIT_VAR(lifetime);
		ZVAL_NULL(lifetime);
		
		PHALCON_INIT_VAR(cache_service);
		ZVAL_STRING(cache_service, "modelsCache", 1);
		
		PHALCON_INIT_VAR(cache_options);
		phalcon_array_fetch_string(&cache_options, params, SL("cache"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC_PARAMS_1(r0, "is_bool", cache_options);
		if (zend_is_true(r0)) {
			if (zend_is_true(cache_options)) {
				PHALCON_INIT_VAR(lifetime);
				ZVAL_LONG(lifetime, 3600);
				
				PHALCON_INIT_VAR(cache);
				PHALCON_CALL_METHOD_PARAMS_1(cache, dependency_injector, "getshared", cache_service, PH_NO_CHECK);
			}
		} else {
			if (Z_TYPE_P(cache_options) == IS_ARRAY) { 
				eval_int = phalcon_array_isset_string(cache_options, SL("key")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(key);
					phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
				}
				eval_int = phalcon_array_isset_string(cache_options, SL("lifetime")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(lifetime);
					phalcon_array_fetch_string(&lifetime, cache_options, SL("lifetime"), PH_NOISY_CC);
				}
				
				eval_int = phalcon_array_isset_string(cache_options, SL("service")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(cache_service);
					phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY_CC);
				}
			} else {
				if (Z_TYPE_P(cache_options) == IS_LONG) {
					PHALCON_CPY_WRT(lifetime, cache_options);
				} else {
					if (Z_TYPE_P(cache_options) == IS_OBJECT) {
						PHALCON_CPY_WRT(cache, cache_options);
					} else {
						PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid caching options");
						return;
					}
				}
			}
		}
		
		if (Z_TYPE_P(cache) == IS_NULL) {
			PHALCON_INIT_VAR(cache);
			PHALCON_CALL_METHOD_PARAMS_1(cache, dependency_injector, "getshared", cache_service, PH_NO_CHECK);
		}
	}
	
	ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", dependency_injector, PH_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	if (Z_TYPE_P(cache) != IS_NULL) {
		if (Z_TYPE_P(key) == IS_NULL) {
			p0[0] = dependency_injector;
			p0[1] = model;
			p0[2] = connection;
			p0[3] = params;
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_SELF_PARAMS(r1, this_ptr, "_createsqlselect", 4, p0);
			PHALCON_CPY_WRT(select, r1);
			
			PHALCON_INIT_VAR(md5select);
			PHALCON_CALL_FUNC_PARAMS_1(md5select, "md5", select);
			
			PHALCON_INIT_VAR(key);
			PHALCON_CONCAT_SV(key, "phc", md5select);
		}
		
		PHALCON_INIT_VAR(resultset);
		PHALCON_CALL_METHOD_PARAMS_2(resultset, cache, "get", key, lifetime, PH_NO_CHECK);
		if (Z_TYPE_P(resultset) != IS_NULL) {
			
			RETURN_CCTOR(resultset);
		}
	}
	
	if (Z_TYPE_P(select) == IS_NULL) {
		p1[0] = dependency_injector;
		p1[1] = model;
		p1[2] = connection;
		p1[3] = params;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_SELF_PARAMS(r2, this_ptr, "_createsqlselect", 4, p1);
		PHALCON_CPY_WRT(select, r2);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, connection, "query", select, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD_PARAMS_1(count, result, "numrows", result, PH_NO_CHECK);
	if (Z_TYPE_P(unique) == IS_BOOL && Z_BVAL_P(unique)) {
		if (!zend_is_true(count)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		} else {
			PHALCON_INIT_VAR(c0);
			ZVAL_LONG(c0, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", c0, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetcharray", result, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(c1);
			ZVAL_LONG(c1, 2);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", c1, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(dumped_result);
			PHALCON_CALL_SELF_PARAMS_2(dumped_result, this_ptr, "dumpresult", model, row);
			
			RETURN_CCTOR(dumped_result);
		}
	}
	
	if (zend_is_true(count)) {
		PHALCON_CPY_WRT(result_data, result);
	} else {
		PHALCON_INIT_VAR(result_data);
		ZVAL_BOOL(result_data, 0);
	}
	
	PHALCON_INIT_VAR(resultset);
	object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", model, result_data, cache, PH_CHECK);
	if (Z_TYPE_P(cache) != IS_NULL) {
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(cache, "save", key, resultset, lifetime, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(resultset);
}

/**
 * Sets a transaction related to the Model instance
 *
 * @param Phalcon\Mvc\Model\Transaction $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction){

	zval *transaction = NULL, *connection = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Transaction should be an object");
		return;
	}
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource){

	zval *source = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &source) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource){

	zval *source = NULL, *class_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(source);
	phalcon_read_property(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!zend_is_true(source)) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, this_ptr TSRMLS_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_STATIC_PARAMS_1(source, "phalcon\\text", "uncamelize", class_name);
		phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(source);
}

/**
 * Sets schema name where table mapped is located
 *
 * @param string $schema
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema){

	zval *schema = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_schema"), schema TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema){

	zval *schema = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(schema);
	phalcon_read_property(&schema, this_ptr, SL("_schema"), PH_NOISY_CC);
	
	RETURN_CCTOR(schema);
}

/**
 * Sets DependencyInjection connection service
 *
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService){

	zval *connection_service = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection_service) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_connectionService"), connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns DependencyInjection connection service
 *
 * @return $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model, getConnectionService){

	zval *connection_service = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(connection_service);
	phalcon_read_property(&connection_service, this_ptr, SL("_connectionService"), PH_NOISY_CC);
	
	RETURN_CCTOR(connection_service);
}

/**
 *
 */
PHP_METHOD(Phalcon_Mvc_Model, setForceExists){

	zval *force_exists = NULL, *force_exists_bool = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &force_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(force_exists);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_cast(r0, force_exists, IS_BOOL);
	PHALCON_CPY_WRT(force_exists_bool, r0);
	phalcon_update_property_zval(this_ptr, SL("_forceExists"), force_exists TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets internal database connection
 *
 * @return Phalcon\Db
 */
PHP_METHOD(Phalcon_Mvc_Model, getConnection){

	zval *connection = NULL, *connection_service = NULL, *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_INIT_VAR(connection_service);
		phalcon_read_property(&connection_service, this_ptr, SL("_connectionService"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD_PARAMS_1(connection, dependency_injector, "getshared", connection_service, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 * @param array $result
 * @param Phalcon\Mvc\Model\Base $base
 * @return Phalcon\Mvc\Model\Base $result
 */
PHP_METHOD(Phalcon_Mvc_Model, dumpResult){

	zval *base = NULL, *result = NULL, *object = NULL, *value = NULL, *key = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
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
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "setforceexists", c0, PH_NO_CHECK);
	if (Z_TYPE_P(result) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(result TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(result);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8adf_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8adf_0;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8adf_0;
		fee_8adf_0:
		if(0){}
		
	}
	
	
	RETURN_CCTOR(object);
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * @param array $parameters
 * @return  Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, find){

	zval *parameters = NULL, *model_name = NULL, *params = NULL, *resultset = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	PHALCON_CALL_FUNC(model_name, "get_called_class");
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init(params);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 0);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_SELF_PARAMS_3(resultset, this_ptr, "_getorcreateresultset", model_name, params, c0);
	
	RETURN_CCTOR(resultset);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * @param array $parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst){

	zval *parameters = NULL, *model_name = NULL, *params = NULL, *model = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	PHALCON_CALL_FUNC(model_name, "get_called_class");
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init(params);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("limit")+1);
	if (!eval_int) {
		phalcon_array_update_string_string(&params, SL("limit"), SL("1"), PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_SELF_PARAMS_3(model, this_ptr, "_getorcreateresultset", model_name, params, c0);
	
	RETURN_CCTOR(model);
}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\Metadata $metaData
 * @param Phalcon\Db $connection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists){

	zval *meta_data = NULL, *connection = NULL, *unique_key = NULL, *primary_keys = NULL;
	zval *primary_keys_count = NULL, *where_pk = NULL, *null_value = NULL;
	zval *empty_str = NULL, *field = NULL, *value = NULL, *is_not_null = NULL, *is_not_empty = NULL;
	zval *not_null = NULL, *sanitized_value = NULL, *pk_condition = NULL;
	zval *where_pk_count = NULL, *join_where = NULL, *force_exists = NULL;
	zval *schema = NULL, *source = NULL, *table = NULL, *select = NULL, *num = NULL, *row_count = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &meta_data, &connection) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(connection);
	
	PHALCON_INIT_VAR(unique_key);
	phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(unique_key) == IS_NULL) {
		PHALCON_INIT_VAR(primary_keys);
		PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(primary_keys_count);
		phalcon_fast_count(primary_keys_count, primary_keys TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_not_equal_function(r0, primary_keys_count, t0 TSRMLS_CC);
		if (zend_is_true(r0)) {
			PHALCON_INIT_VAR(where_pk);
			array_init(where_pk);
			
			PHALCON_INIT_VAR(connection);
			PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(null_value);
			ZVAL_NULL(null_value);
			
			PHALCON_INIT_VAR(empty_str);
			ZVAL_STRING(empty_str, "", 1);
			if (!phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(primary_keys);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_8adf_1:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_8adf_1;
				}
				
				PHALCON_INIT_VAR(field);
				ZVAL_ZVAL(field, *hd, 1, 0);
				eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
				if (eval_int) {
					PHALCON_INIT_VAR(value);
					phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
					
					PHALCON_INIT_VAR(is_not_null);
					is_not_identical_function(is_not_null, null_value, value TSRMLS_CC);
					
					PHALCON_INIT_VAR(is_not_empty);
					is_not_identical_function(is_not_empty, empty_str, value TSRMLS_CC);
					
					PHALCON_INIT_VAR(not_null);
					phalcon_and_function(not_null, is_not_null, is_not_empty);
					if (zend_is_true(not_null)) {
						PHALCON_INIT_VAR(sanitized_value);
						PHALCON_CALL_METHOD_PARAMS_1(sanitized_value, connection, "escapestring", value, PH_NO_CHECK);
						
						PHALCON_INIT_VAR(pk_condition);
						PHALCON_CONCAT_VSV(pk_condition, field, " = ", sanitized_value);
						phalcon_array_append(&where_pk, pk_condition, PH_SEPARATE TSRMLS_CC);
					}
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_8adf_1;
			fee_8adf_1:
			
			PHALCON_INIT_VAR(where_pk_count);
			phalcon_fast_count(where_pk_count, where_pk TSRMLS_CC);
			if (zend_is_true(where_pk_count)) {
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, " AND ", 1);
				PHALCON_INIT_VAR(join_where);
				phalcon_fast_join(join_where, c0, where_pk TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_uniqueKey"), join_where TSRMLS_CC);
				PHALCON_CPY_WRT(unique_key, join_where);
			} else {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(force_exists);
	phalcon_read_property(&force_exists, this_ptr, SL("_forceExists"), PH_NOISY_CC);
	if (Z_TYPE_P(force_exists) == IS_BOOL && !Z_BVAL_P(force_exists)) {
		PHALCON_INIT_VAR(schema);
		PHALCON_CALL_METHOD(schema, this_ptr, "getschema", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD(source, this_ptr, "getsource", PH_NO_CHECK);
		if (zend_is_true(schema)) {
			PHALCON_INIT_VAR(table);
			PHALCON_CONCAT_VSV(table, schema, ".", source);
		} else {
			PHALCON_CPY_WRT(table, source);
		}
		
		PHALCON_INIT_VAR(select);
		PHALCON_CONCAT_SVSV(select, "SELECT COUNT(*) AS rowcount FROM ", table, " WHERE ", unique_key);
		
		PHALCON_INIT_VAR(num);
		PHALCON_CALL_METHOD_PARAMS_1(num, connection, "fetchone", select, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(row_count);
		phalcon_array_fetch_string(&row_count, num, SL("rowcount"), PH_NOISY_CC);
		if (zend_is_true(row_count)) {
			phalcon_update_property_bool(this_ptr, SL("_forceExists"), 1 TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		} else {
			phalcon_update_property_bool(this_ptr, SL("_forceExists"), 0 TSRMLS_CC);
		}
	} else {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Generate a SQL SELECT statement for an aggregate
 *
 * @param string $function
 * @param string $alias
 * @param array $parameters
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, _prepareGroupResult){

	zval *function = NULL, *alias = NULL, *parameters = NULL, *params = NULL, *group_column = NULL;
	zval *dependency_injector = NULL, *class_name = NULL, *model = NULL;
	zval *connection = NULL, *schema = NULL, *source = NULL, *table = NULL, *select = NULL;
	zval *conditions = NULL, *resultset = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &function, &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init(params);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SL("column")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(group_column);
		phalcon_array_fetch_string(&group_column, params, SL("column"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(group_column);
		ZVAL_STRING(group_column, "*", 1);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	
	PHALCON_INIT_VAR(class_name);
	PHALCON_CALL_FUNC(class_name, "get_called_class");
	ce0 = phalcon_fetch_class(class_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", dependency_injector, PH_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema, ".", source);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("distinct")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, params, SL("distinct"), PH_NOISY_CC);
		PHALCON_INIT_VAR(select);
		PHALCON_CONCAT_SVSV(select, "SELECT ", function, "(DISTINCT ", r0);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_SVSVS(r1, ") AS ", alias, " FROM ", table, " ");
		phalcon_concat_self(&select, r1 TSRMLS_CC);
	} else {
		eval_int = phalcon_array_isset_string(params, SL("group")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r2);
			phalcon_array_fetch_string(&r2, params, SL("group"), PH_NOISY_CC);
			PHALCON_INIT_VAR(select);
			PHALCON_CONCAT_SVSVSV(select, "SELECT ", r2, ", ", function, "(", group_column);
			
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CONCAT_SVSVS(r3, ") AS ", alias, " FROM ", table, " ");
			phalcon_concat_self(&select, r3 TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(select);
			PHALCON_CONCAT_SVSVS(select, "SELECT ", function, "(", group_column, ") AS ");
			
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CONCAT_VSVS(r4, alias, " FROM ", table, " ");
			phalcon_concat_self(&select, r4 TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(conditions);
	ZVAL_NULL(conditions);
	eval_int = phalcon_array_isset_string(params, SL("conditions")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(conditions);
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(conditions);
			phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
		}
	}
	
	if (zend_is_true(conditions)) {
		eval_int = phalcon_array_isset_string(params, SL("bind")+1);
		if (eval_int) {
			PHALCON_ALLOC_ZVAL_MM(r5);
			phalcon_array_fetch_string(&r5, params, SL("bind"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r6);
			PHALCON_CALL_METHOD_PARAMS_2(r6, connection, "bindparams", conditions, r5, PH_NO_CHECK);
			PHALCON_CPY_WRT(conditions, r6);
		}
		
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CONCAT_SV(r7, " WHERE ", conditions);
		phalcon_concat_self(&select, r7 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("group")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, params, SL("group"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r9);
		PHALCON_CONCAT_SVS(r9, " GROUP BY ", r8, " ");
		phalcon_concat_self(&select, r9 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("having")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r10);
		phalcon_array_fetch_string(&r10, params, SL("having"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CONCAT_SVS(r11, " HAVING ", r10, " ");
		phalcon_concat_self(&select, r11 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("order")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, params, SL("order"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r13);
		PHALCON_CONCAT_SVS(r13, " ORDER BY ", r12, " ");
		phalcon_concat_self(&select, r13 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SL("limit")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r14);
		phalcon_array_fetch_string(&r14, params, SL("limit"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(r15);
		PHALCON_CALL_METHOD_PARAMS_2(r15, connection, "_limit", select, r14, PH_NO_CHECK);
		PHALCON_CPY_WRT(select, r15);
	}
	
	p0[0] = connection;
	p0[1] = params;
	p0[2] = select;
	p0[3] = alias;
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CALL_SELF_PARAMS(r16, this_ptr, "_getgroupresult", 4, p0);
	PHALCON_CPY_WRT(resultset, r16);
	
	RETURN_CCTOR(resultset);
}

/**
 * Generate a resulset from an SQL select with aggregations
 *
 * @param Phalcon\Db $connection
 * @param array $params
 * @param string $sqlSelect
 * @param string $alias
 * @return array|Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, _getGroupResult){

	zval *connection = NULL, *params = NULL, *sql_select = NULL, *alias = NULL;
	zval *result = NULL, *count = NULL, *row_object = NULL, *cache = NULL, *resultset = NULL;
	zval *num = NULL, *group_value = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &connection, &params, &sql_select, &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(params, SL("group")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_1(result, connection, "query", sql_select, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(count);
		PHALCON_CALL_METHOD(count, result, "numrows", PH_NO_CHECK);
		if (zend_is_true(count)) {
			PHALCON_INIT_VAR(row_object);
			object_init_ex(row_object, phalcon_mvc_model_row_ce);
		} else {
			PHALCON_INIT_VAR(row_object);
			object_init(row_object);
			
			PHALCON_INIT_VAR(result);
			ZVAL_BOOL(result, 0);
		}
		
		PHALCON_INIT_VAR(cache);
		ZVAL_NULL(cache);
		
		PHALCON_INIT_VAR(resultset);
		object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", row_object, result, cache, PH_CHECK);
		
		RETURN_CTOR(resultset);
	}
	
	PHALCON_INIT_VAR(num);
	PHALCON_CALL_METHOD_PARAMS_1(num, connection, "fetchone", sql_select, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(group_value);
	phalcon_array_fetch(&group_value, num, alias, PH_NOISY_CC);
	
	RETURN_CCTOR(group_value);
}

/**
 * Allows to count how many records match the specified conditions
 *
 * @param array $parameters
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, count){

	zval *parameters = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "COUNT", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "rowcount", 1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_SELF_PARAMS_3(r0, this_ptr, "_preparegroupresult", c0, c1, parameters);
	RETURN_CTOR(r0);
}

/**
 * Allows to a calculate a summatory on a column that match the specified conditions
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, sum){

	zval *parameters = NULL, *group = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "SUM", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "sumatory", 1);
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", c0, c1, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum){

	zval *parameters = NULL, *group = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "MAX", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "maximum", 1);
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", c0, c1, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum){

	zval *parameters = NULL, *group = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "MIN", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "minimum", 1);
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", c0, c1, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average){

	zval *parameters = NULL, *group = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_ALLOC_ZVAL_MM(parameters);
		ZVAL_NULL(parameters);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "AVG", 1);
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "average", 1);
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", c0, c1, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Fires an internal event
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _callEvent){

	zval *event_name = NULL, *status = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, Z_STRVAL_P(event_name), PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Fires an internal event that cancels the operation
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _callEventCancel){

	zval *event_name = NULL, *status = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, Z_STRVAL_P(event_name), PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Cancel the current operation
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation){

	zval *disable_events = NULL, *operation_made = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &disable_events) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(operation_made);
		phalcon_read_property(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY_CC);
		if (phalcon_compare_strict_long(operation_made, 3 TSRMLS_CC)) {
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "notDeleted", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c0, PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "notSaved", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c1, PH_NO_CHECK);
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Appends a customized message on the validation process
 *
 * @param Phalcon\Mvc\Model\Message $message
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage){

	zval *message = NULL, *type = NULL, *exception_message = NULL, *exception = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_FUNC_PARAMS_1(type, "gettype", message);
		
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_mvc_model_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	phalcon_array_append(&t0, message, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes validators on every validation call
 *
 * @param object $validator
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, validate){

	zval *validator = NULL, *status = NULL, *messages = NULL, *message = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &validator) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object");
		return;
	}
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, validator, "validate", this_ptr, PH_NO_CHECK);
	if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, validator, "getmessages", PH_NO_CHECK);
		if (!phalcon_valid_foreach(messages TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(messages);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8adf_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8adf_2;
			}
			
			PHALCON_INIT_VAR(message);
			ZVAL_ZVAL(message, *hd, 1, 0);
			PHALCON_INIT_VAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
			phalcon_array_append(&t0, message, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t0 TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8adf_2;
		fee_8adf_2:
		if(0){}
		
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether validation process has generated any messages
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed){

	zval *number_messages = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	PHALCON_INIT_VAR(number_messages);
	phalcon_fast_count(number_messages, t0 TSRMLS_CC);
	if (zend_is_true(number_messages)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns all the validation messages
 *
 * @return Phalcon\Mvc\Model\Message[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages){

	zval *error_messages = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(error_messages);
	phalcon_read_property(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	
	RETURN_CCTOR(error_messages);
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeys){

	zval *dependency_injector = NULL, *disable_events = NULL;
	zval *manager = NULL, *belongs_to = NULL, *error = NULL, *relation = NULL, *options = NULL;
	zval *foreign_key = NULL, *conditions = NULL, *relation_class = NULL;
	zval *referenced_model = NULL, *fields = NULL, *referenced_fields = NULL;
	zval *field = NULL, *n = NULL, *value = NULL, *rowcount = NULL, *user_message = NULL;
	zval *message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &dependency_injector, &disable_events) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(belongs_to);
	PHALCON_CALL_METHOD_PARAMS_1(belongs_to, manager, "getbelongsto", this_ptr, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, belongs_to TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		if (!phalcon_valid_foreach(belongs_to TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(belongs_to);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8adf_3:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8adf_3;
			}
			
			PHALCON_INIT_VAR(relation);
			ZVAL_ZVAL(relation, *hd, 1, 0);
			eval_int = phalcon_array_isset_string(relation, SL("op")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(options);
				phalcon_array_fetch_string(&options, relation, SL("op"), PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(options, SL("foreignKey")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(foreign_key);
					phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY_CC);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_VAR(conditions);
						array_init(conditions);
						
						PHALCON_INIT_VAR(relation_class);
						phalcon_array_fetch_string(&relation_class, relation, SL("rt"), PH_NOISY_CC);
						ce0 = phalcon_fetch_class(relation_class TSRMLS_CC);
						
						PHALCON_INIT_VAR(referenced_model);
						object_init_ex(referenced_model, ce0);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "__construct", dependency_injector, PH_CHECK);
						
						PHALCON_INIT_VAR(fields);
						phalcon_array_fetch_string(&fields, relation, SL("fi"), PH_NOISY_CC);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							PHALCON_INIT_VAR(referenced_fields);
							phalcon_array_fetch_string(&referenced_fields, relation, SL("rf"), PH_NOISY_CC);
							if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
								return;
							}
							
							ah1 = Z_ARRVAL_P(fields);
							zend_hash_internal_pointer_reset_ex(ah1, &hp1);
							fes_8adf_4:
								if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
									goto fee_8adf_4;
								}
								
								PHALCON_INIT_VAR(n);
								PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								PHALCON_INIT_VAR(field);
								ZVAL_ZVAL(field, *hd, 1, 0);
								PHALCON_INIT_VAR(value);
								phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
								
								PHALCON_INIT_VAR(r1);
								phalcon_array_fetch(&r1, referenced_fields, n, PH_NOISY_CC);
								
								PHALCON_INIT_VAR(r2);
								PHALCON_CONCAT_VSVS(r2, r1, " = '", value, "'");
								phalcon_array_append(&conditions, r2, PH_SEPARATE TSRMLS_CC);
								zend_hash_move_forward_ex(ah1, &hp1);
								goto fes_8adf_4;
							fee_8adf_4:
							if(0){}
							
						} else {
							PHALCON_INIT_VAR(value);
							phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
							
							PHALCON_INIT_VAR(t0);
							ZVAL_NULL(t0);
							
							PHALCON_INIT_VAR(r3);
							is_identical_function(r3, t0, value TSRMLS_CC);
							
							PHALCON_INIT_VAR(t1);
							ZVAL_STRING(t1, "", 1);
							
							PHALCON_INIT_VAR(r4);
							is_identical_function(r4, t1, value TSRMLS_CC);
							
							PHALCON_INIT_VAR(r5);
							ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
							if (zend_is_true(r5)) {
								goto fes_8adf_3;
							}
							
							PHALCON_INIT_VAR(r6);
							phalcon_array_fetch_string(&r6, relation, SL("rf"), PH_NOISY_CC);
							
							PHALCON_INIT_VAR(r7);
							PHALCON_CONCAT_VSVS(r7, r6, " = '", value, "'");
							phalcon_array_append(&conditions, r7, PH_SEPARATE TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, SL("conditions")+1);
						if (eval_int) {
							PHALCON_INIT_VAR(r8);
							phalcon_array_fetch_string(&r8, foreign_key, SL("conditions"), PH_NOISY_CC);
							phalcon_array_append(&conditions, r8, PH_SEPARATE TSRMLS_CC);
						}
						
						PHALCON_INIT_VAR(r9);
						PHALCON_CALL_METHOD(r9, this_ptr, "getconnectionservice", PH_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnectionservice", r9, PH_NO_CHECK);
						
						PHALCON_INIT_VAR(c1);
						ZVAL_STRING(c1, " AND ", 1);
						
						PHALCON_INIT_VAR(r10);
						phalcon_fast_join(r10, c1, conditions TSRMLS_CC);
						
						PHALCON_INIT_VAR(rowcount);
						PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", r10, PH_NO_CHECK);
						if (!zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, SL("message")+1);
							if (eval_int) {
								PHALCON_INIT_VAR(user_message);
								phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
							} else {
								if (Z_TYPE_P(fields) == IS_ARRAY) { 
									PHALCON_INIT_VAR(c2);
									ZVAL_STRING(c2, ", ", 1);
									PHALCON_INIT_VAR(r11);
									phalcon_fast_join(r11, c2, fields TSRMLS_CC);
									PHALCON_INIT_VAR(user_message);
									PHALCON_CONCAT_SVS(user_message, "Value of fields \"", r11, "\" does not exist on referenced table");
								} else {
									PHALCON_INIT_VAR(user_message);
									PHALCON_CONCAT_SVS(user_message, "Value of field \"", fields, "\" does not exist on referenced table");
								}
							}
							
							PHALCON_INIT_VAR(message);
							object_init_ex(message, phalcon_mvc_model_message_ce);
							
							PHALCON_INIT_VAR(c3);
							ZVAL_STRING(c3, "ConstraintViolation", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, c3, PH_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message, PH_NO_CHECK);
							
							PHALCON_INIT_VAR(error);
							ZVAL_BOOL(error, 1);
							goto fee_8adf_3;
						}
					}
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8adf_3;
		fee_8adf_3:
		
		if (zend_is_true(error)) {
			PHALCON_INIT_VAR(c4);
			ZVAL_STRING(c4, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c4, PH_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events, PH_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Reads both "hasMany" and "hasOne" relations and check the virtual foreign keys when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverse){

	zval *dependency_injector = NULL, *disable_events = NULL;
	zval *manager = NULL, *relations = NULL, *error = NULL, *relation = NULL, *options = NULL;
	zval *foreign_key = NULL, *fields = NULL, *referenced_name = NULL;
	zval *referenced_fields = NULL, *referenced_model = NULL;
	zval *conditions = NULL, *field = NULL, *n = NULL, *value = NULL, *referenced_field = NULL;
	zval *connection_service = NULL, *rowcount = NULL, *user_message = NULL;
	zval *message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &dependency_injector, &disable_events) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(relations);
	PHALCON_CALL_METHOD_PARAMS_1(relations, manager, "gethasoneandhasmany", this_ptr, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, relations TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		if (!phalcon_valid_foreach(relations TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(relations);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8adf_5:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8adf_5;
			}
			
			PHALCON_INIT_VAR(relation);
			ZVAL_ZVAL(relation, *hd, 1, 0);
			eval_int = phalcon_array_isset_string(relation, SL("op")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(options);
				phalcon_array_fetch_string(&options, relation, SL("op"), PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(options, SL("foreignKey")+1);
				if (eval_int) {
					PHALCON_INIT_VAR(foreign_key);
					phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY_CC);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_VAR(fields);
						phalcon_array_fetch_string(&fields, relation, SL("fi"), PH_NOISY_CC);
						
						PHALCON_INIT_VAR(referenced_name);
						phalcon_array_fetch_string(&referenced_name, relation, SL("rt"), PH_NOISY_CC);
						
						PHALCON_INIT_VAR(referenced_fields);
						phalcon_array_fetch_string(&referenced_fields, relation, SL("rf"), PH_NOISY_CC);
						ce0 = phalcon_fetch_class(referenced_name TSRMLS_CC);
						
						PHALCON_INIT_VAR(referenced_model);
						object_init_ex(referenced_model, ce0);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "__construct", dependency_injector, PH_CHECK);
						
						PHALCON_INIT_VAR(conditions);
						array_init(conditions);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
								return;
							}
							
							ah1 = Z_ARRVAL_P(fields);
							zend_hash_internal_pointer_reset_ex(ah1, &hp1);
							fes_8adf_6:
								if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
									goto fee_8adf_6;
								}
								
								PHALCON_INIT_VAR(n);
								PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								PHALCON_INIT_VAR(field);
								ZVAL_ZVAL(field, *hd, 1, 0);
								eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
								if (eval_int) {
									PHALCON_INIT_VAR(value);
									phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
								} else {
									PHALCON_INIT_VAR(value);
									ZVAL_NULL(value);
								}
								
								PHALCON_INIT_VAR(referenced_field);
								phalcon_array_fetch(&referenced_field, referenced_fields, n, PH_NOISY_CC);
								
								PHALCON_INIT_VAR(r1);
								PHALCON_CONCAT_VSVS(r1, referenced_field, " = '", value, "'");
								phalcon_array_append(&conditions, r1, PH_SEPARATE TSRMLS_CC);
								zend_hash_move_forward_ex(ah1, &hp1);
								goto fes_8adf_6;
							fee_8adf_6:
							if(0){}
							
						} else {
							eval_int = phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC);
							if (eval_int) {
								PHALCON_INIT_VAR(value);
								phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
							} else {
								PHALCON_INIT_VAR(value);
								ZVAL_NULL(value);
							}
							
							PHALCON_INIT_VAR(r2);
							PHALCON_CONCAT_VSVS(r2, referenced_fields, " = '", value, "'");
							phalcon_array_append(&conditions, r2, PH_SEPARATE TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, SL("conditions")+1);
						if (eval_int) {
							PHALCON_INIT_VAR(r3);
							phalcon_array_fetch_string(&r3, foreign_key, SL("conditions"), PH_NOISY_CC);
							phalcon_array_append(&conditions, r3, PH_SEPARATE TSRMLS_CC);
						}
						
						PHALCON_INIT_VAR(connection_service);
						PHALCON_CALL_METHOD(connection_service, this_ptr, "getconnectionservice", PH_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnectionservice", connection_service, PH_NO_CHECK);
						
						PHALCON_INIT_VAR(c1);
						ZVAL_STRING(c1, " AND ", 1);
						
						PHALCON_INIT_VAR(r4);
						phalcon_fast_join(r4, c1, conditions TSRMLS_CC);
						
						PHALCON_INIT_VAR(rowcount);
						PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", r4, PH_NO_CHECK);
						if (zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, SL("message")+1);
							if (eval_int) {
								PHALCON_INIT_VAR(user_message);
								phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
							} else {
								PHALCON_INIT_VAR(user_message);
								PHALCON_CONCAT_SV(user_message, "Record is referenced by model ", referenced_name);
							}
							
							PHALCON_INIT_VAR(message);
							object_init_ex(message, phalcon_mvc_model_message_ce);
							
							PHALCON_INIT_VAR(c2);
							ZVAL_STRING(c2, "ConstraintViolation", 1);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, c2, PH_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message, PH_NO_CHECK);
							
							PHALCON_INIT_VAR(error);
							ZVAL_BOOL(error, 1);
							goto fee_8adf_5;
						}
					}
				}
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8adf_5;
		fee_8adf_5:
		
		if (zend_is_true(error)) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c3, PH_NO_CHECK);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events, PH_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Executes internal hooks before save a record
 *
 * @param Phalcon\DI $dependencyInjector
 * @param Phalcon\Mvc\Model\Metadata $metaData
 * @param boolean $disableEvents
 * @param boolean $exists
 * @param string $identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave){

	zval *dependency_injector = NULL, *meta_data = NULL, *disable_events = NULL;
	zval *exists = NULL, *identity_field = NULL, *status = NULL, *not_null = NULL;
	zval *data_type_numeric = NULL, *error = NULL, *num_fields = NULL;
	zval *null_value = NULL, *empty_str = NULL, *i = NULL, *is_null = NULL, *field = NULL;
	zval *value = NULL, *is_null_value = NULL, *is_empty_str = NULL, *is_numeric = NULL;
	zval *is_identity_field = NULL, *message = NULL, *model_message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *c7 = NULL, *c8 = NULL, *c9 = NULL, *c10 = NULL, *c11 = NULL, *c12 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzzz", &dependency_injector, &meta_data, &disable_events, &exists, &identity_field) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "beforeValidation", 1);
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c0, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		if (!zend_is_true(exists)) {
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "beforeValidationOnCreate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c1, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "beforeValidationOnUpdate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c2, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_2(r0, this_ptr, "_checkforeignkeys", dependency_injector, disable_events, PH_NO_CHECK);
	if (Z_TYPE_P(r0) == IS_BOOL && !Z_BVAL_P(r0)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(not_null);
	PHALCON_CALL_METHOD_PARAMS_1(not_null, meta_data, "getnotnullattributes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(data_type_numeric);
	PHALCON_CALL_METHOD_PARAMS_1(data_type_numeric, meta_data, "getdatatypesnumeric", this_ptr, PH_NO_CHECK);
	if (Z_TYPE_P(not_null) == IS_ARRAY) { 
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		
		PHALCON_INIT_VAR(num_fields);
		phalcon_fast_count(num_fields, not_null TSRMLS_CC);
		
		PHALCON_INIT_VAR(null_value);
		ZVAL_NULL(null_value);
		
		PHALCON_INIT_VAR(empty_str);
		ZVAL_STRING(empty_str, "", 1);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		fs_8adf_7:
			
			PHALCON_INIT_VAR(r1);
			is_smaller_function(r1, i, num_fields TSRMLS_CC);
			if (!zend_is_true(r1)) {
				goto fe_8adf_7;
			}
			PHALCON_INIT_VAR(is_null);
			ZVAL_BOOL(is_null, 0);
			
			PHALCON_INIT_VAR(field);
			phalcon_array_fetch(&field, not_null, i, PH_NOISY_CC);
			eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
			if (eval_int) {
				PHALCON_INIT_VAR(value);
				phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
				eval_int = phalcon_array_isset(data_type_numeric, field);
				if (!eval_int) {
					PHALCON_INIT_VAR(t0);
					ZVAL_NULL(t0);
					PHALCON_INIT_VAR(is_null_value);
					is_identical_function(is_null_value, t0, value TSRMLS_CC);
					
					PHALCON_INIT_VAR(t1);
					ZVAL_STRING(t1, "", 1);
					
					PHALCON_INIT_VAR(is_empty_str);
					is_identical_function(is_empty_str, t1, value TSRMLS_CC);
					
					PHALCON_INIT_VAR(is_null);
					ZVAL_BOOL(is_null, zend_is_true(is_null_value) || zend_is_true(is_empty_str));
				} else {
					PHALCON_INIT_VAR(is_numeric);
					PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", value);
					if (!zend_is_true(is_numeric)) {
						PHALCON_INIT_VAR(is_null);
						ZVAL_BOOL(is_null, 1);
					}
				}
			} else {
				PHALCON_INIT_VAR(is_null);
				ZVAL_BOOL(is_null, 1);
			}
			
			if (zend_is_true(is_null)) {
				if (Z_TYPE_P(exists) == IS_BOOL && !Z_BVAL_P(exists)) {
					PHALCON_INIT_VAR(is_identity_field);
					is_equal_function(is_identity_field, field, identity_field TSRMLS_CC);
					if (zend_is_true(is_identity_field)) {
						goto fi_8adf_7;
					}
				}
				
				PHALCON_INIT_VAR(message);
				PHALCON_CONCAT_VS(message, field, " is required");
				
				PHALCON_INIT_VAR(model_message);
				object_init_ex(model_message, phalcon_mvc_model_message_ce);
				
				PHALCON_INIT_VAR(c3);
				ZVAL_STRING(c3, "PresenceOf", 1);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, c3, PH_CHECK);
				
				PHALCON_INIT_VAR(t2);
				phalcon_read_property(&t2, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
				phalcon_array_append(&t2, model_message, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t2 TSRMLS_CC);
				
				PHALCON_INIT_VAR(error);
				ZVAL_BOOL(error, 1);
			}
			fi_8adf_7:
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto fs_8adf_7;
		fe_8adf_7:
		if (zend_is_true(error)) {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_VAR(c4);
				ZVAL_STRING(c4, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c4, PH_NO_CHECK);
			}
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events, PH_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(c5);
	ZVAL_STRING(c5, "validation", 1);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c5, PH_NO_CHECK);
	if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c6);
			ZVAL_STRING(c6, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c6, PH_NO_CHECK);
		}
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	if (!zend_is_true(disable_events)) {
		if (!zend_is_true(exists)) {
			PHALCON_INIT_VAR(c7);
			ZVAL_STRING(c7, "afterValidationOnCreate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c7, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_INIT_VAR(c8);
			ZVAL_STRING(c8, "afterValidationOnUpdate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c8, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
		
		PHALCON_INIT_VAR(c9);
		ZVAL_STRING(c9, "afterValidation", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c9, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		PHALCON_INIT_VAR(c10);
		ZVAL_STRING(c10, "beforeSave", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c10, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		if (zend_is_true(exists)) {
			PHALCON_INIT_VAR(c11);
			ZVAL_STRING(c11, "beforeUpdate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c11, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		} else {
			PHALCON_INIT_VAR(c12);
			ZVAL_STRING(c12, "beforeCreate", 1);
			PHALCON_INIT_VAR(status);
			PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", c12, PH_NO_CHECK);
			if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
				PHALCON_MM_RESTORE();
				RETURN_FALSE;
			}
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Executes internal events after save a record
 *
 * @param boolean $disableEvents
 * @param boolean $success
 * @param boolean $exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave){

	zval *disable_events = NULL, *success = NULL, *exists = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &disable_events, &success, &exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(success) == IS_BOOL && Z_BVAL_P(success)) {
		if (!zend_is_true(disable_events)) {
			if (Z_TYPE_P(exists) == IS_BOOL && Z_BVAL_P(exists)) {
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "afterUpdate", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c0, PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(c1);
				ZVAL_STRING(c1, "afterCreate", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c1, PH_NO_CHECK);
			}
			
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c2, PH_NO_CHECK);
		}
		
		RETURN_CCTOR(success);
	} else {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c3, PH_NO_CHECK);
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events, PH_NO_CHECK);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\Metadata $metaData
 * @param Phalcon\Db $connection
 * @param string $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert){

	zval *meta_data = NULL, *connection = NULL, *table = NULL, *identity_field = NULL;
	zval *null_value = NULL, *fields = NULL, *values = NULL, *attributes = NULL;
	zval *field = NULL, *value = NULL, *id = NULL, *success = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &meta_data, &connection, &table, &identity_field) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(null_value);
	object_init_ex(null_value, phalcon_db_rawvalue_ce);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "null", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(null_value, "__construct", c0, PH_CHECK);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr, PH_NO_CHECK);
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_8adf_8:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_8adf_8;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		PHALCON_INIT_VAR(r0);
		is_not_equal_function(r0, field, identity_field TSRMLS_CC);
		if (zend_is_true(r0)) {
			phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
			eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
			if (eval_int) {
				PHALCON_INIT_VAR(value);
				phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(t0);
				ZVAL_STRING(t0, "", 1);
				
				PHALCON_INIT_VAR(r1);
				is_identical_function(r1, t0, value TSRMLS_CC);
				
				PHALCON_INIT_VAR(t1);
				ZVAL_NULL(t1);
				
				PHALCON_INIT_VAR(r2);
				is_identical_function(r2, t1, value TSRMLS_CC);
				
				PHALCON_INIT_VAR(r3);
				ZVAL_BOOL(r3, zend_is_true(r1) || zend_is_true(r2));
				if (zend_is_true(r3)) {
					phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
				}
			} else {
				phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
			}
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_8adf_8;
	fee_8adf_8:
	
	if (zend_is_true(identity_field)) {
		phalcon_array_append(&fields, identity_field, PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_isset_property_zval(this_ptr, identity_field TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(id);
			phalcon_read_property_zval(&id, this_ptr, identity_field, PH_NOISY_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_FUNC_PARAMS_1(r4, "is_null", id);
			
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "", 1);
			
			PHALCON_ALLOC_ZVAL_MM(r5);
			is_identical_function(r5, t2, id TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r6);
			ZVAL_BOOL(r6, zend_is_true(r4) || zend_is_true(r5));
			if (zend_is_true(r6)) {
				phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&values, id, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_3(success, connection, "insert", table, values, fields, PH_NO_CHECK);
	if (zend_is_true(identity_field)) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		PHALCON_CALL_METHOD(r7, connection, "lastinsertid", PH_NO_CHECK);
		phalcon_update_property_zval_zval(this_ptr, identity_field, r7 TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(success);
}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\Metadata $metaData
 * @param Phalcon\Db $connection
 * @param string $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate){

	zval *meta_data = NULL, *connection = NULL, *table = NULL, *null_value = NULL;
	zval *fields = NULL, *values = NULL, *non_primary = NULL, *field = NULL, *value = NULL;
	zval *is_exactly_null = NULL, *is_empty = NULL, *is_null = NULL, *success = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &meta_data, &connection, &table) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(null_value);
	object_init_ex(null_value, phalcon_db_rawvalue_ce);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "null", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(null_value, "__construct", c0, PH_CHECK);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(non_primary);
	PHALCON_CALL_METHOD_PARAMS_1(non_primary, meta_data, "getnonprimarykeyattributes", this_ptr, PH_NO_CHECK);
	if (!phalcon_valid_foreach(non_primary TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(non_primary);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_8adf_9:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_8adf_9;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(value);
			phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(t0);
			ZVAL_NULL(t0);
			
			PHALCON_INIT_VAR(is_exactly_null);
			is_identical_function(is_exactly_null, t0, value TSRMLS_CC);
			
			PHALCON_INIT_VAR(t1);
			ZVAL_STRING(t1, "", 1);
			
			PHALCON_INIT_VAR(is_empty);
			is_identical_function(is_empty, t1, value TSRMLS_CC);
			
			PHALCON_INIT_VAR(is_null);
			ZVAL_BOOL(is_null, zend_is_true(is_empty) || zend_is_true(is_exactly_null));
			if (Z_TYPE_P(is_exactly_null) == IS_BOOL && Z_BVAL_P(is_exactly_null)) {
				phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_8adf_9;
	fee_8adf_9:
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_4(success, connection, "update", table, fields, values, t2, PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save){

	zval *dependency_injector = NULL, *meta_data = NULL, *connection = NULL;
	zval *exists = NULL, *disable_events = NULL, *identity_field = NULL;
	zval *status = NULL, *schema = NULL, *source = NULL, *table = NULL, *success = NULL, *post_success = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection, PH_NO_CHECK);
	if (Z_TYPE_P(exists) == IS_BOOL && !Z_BVAL_P(exists)) {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 2 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), a0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\model"), SL("_disableEvents") TSRMLS_CC);
	
	PHALCON_INIT_VAR(identity_field);
	PHALCON_CALL_METHOD_PARAMS_1(identity_field, meta_data, "getidentityfield", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_5(status, this_ptr, "_presave", dependency_injector, meta_data, disable_events, exists, identity_field, PH_NO_CHECK);
	if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, this_ptr, "getschema", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource", PH_NO_CHECK);
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema, ".", source);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	if (Z_TYPE_P(exists) == IS_BOOL && Z_BVAL_P(exists)) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "_dolowupdate", meta_data, connection, table, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_4(success, this_ptr, "_dolowinsert", meta_data, connection, table, identity_field, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(post_success);
	PHALCON_CALL_METHOD_PARAMS_3(post_success, this_ptr, "_postsave", disable_events, success, exists, PH_NO_CHECK);
	
	RETURN_CCTOR(post_success);
}

PHP_METHOD(Phalcon_Mvc_Model, create){

	zval *dependency_injector = NULL, *meta_data = NULL, *connection = NULL;
	zval *exists = NULL, *field = NULL, *message = NULL, *model_message = NULL;
	zval *messages = NULL, *success = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection, PH_NO_CHECK);
	if (Z_TYPE_P(exists) == IS_BOOL && Z_BVAL_P(exists)) {
		PHALCON_INIT_VAR(field);
		ZVAL_NULL(field);
		
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Record cannot be created because it already exists", 1);
		
		PHALCON_INIT_VAR(model_message);
		object_init_ex(model_message, phalcon_mvc_model_message_ce);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "InvalidCreateAttempt", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, c1, PH_CHECK);
		
		PHALCON_INIT_VAR(messages);
		array_init(messages);
		phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save", PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

PHP_METHOD(Phalcon_Mvc_Model, update){

	zval *dependency_injector = NULL, *meta_data = NULL, *connection = NULL;
	zval *exists = NULL, *field = NULL, *message = NULL, *model_message = NULL;
	zval *messages = NULL, *success = NULL;
	zval *c0 = NULL, *c1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection, PH_NO_CHECK);
	if (Z_TYPE_P(exists) == IS_BOOL && !Z_BVAL_P(exists)) {
		PHALCON_INIT_VAR(field);
		ZVAL_NULL(field);
		
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Record cannot be updated because it does not exists", 1);
		
		PHALCON_INIT_VAR(model_message);
		object_init_ex(model_message, phalcon_mvc_model_message_ce);
		
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "InvalidUpdateAttempt", 1);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, c1, PH_CHECK);
		
		PHALCON_INIT_VAR(messages);
		array_init(messages);
		phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save", PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, delete){

	zval *dependency_injector = NULL, *meta_data = NULL, *connection = NULL;
	zval *disable_events = NULL, *check_foreign_keys = NULL;
	zval *values = NULL, *conditions = NULL, *primary_keys = NULL, *primary_key = NULL;
	zval *primary_value = NULL, *primary_condition = NULL, *status = NULL;
	zval *schema = NULL, *source = NULL, *table = NULL, *success = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	phalcon_update_property_long(this_ptr, SL("_operationMade"), 3 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), a0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\model"), SL("_disableEvents") TSRMLS_CC);
	
	PHALCON_INIT_VAR(check_foreign_keys);
	PHALCON_CALL_METHOD_PARAMS_2(check_foreign_keys, this_ptr, "_checkforeignkeysreverse", dependency_injector, disable_events, PH_NO_CHECK);
	if (Z_TYPE_P(check_foreign_keys) == IS_BOOL && !Z_BVAL_P(check_foreign_keys)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_INIT_VAR(primary_keys);
	PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr, PH_NO_CHECK);
	if (!phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(primary_keys);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_8adf_10:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_8adf_10;
		}
		
		PHALCON_INIT_VAR(primary_key);
		ZVAL_ZVAL(primary_key, *hd, 1, 0);
		PHALCON_INIT_VAR(primary_value);
		phalcon_read_property_zval(&primary_value, this_ptr, primary_key, PH_NOISY_CC);
		phalcon_array_append(&values, primary_value, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(primary_condition);
		PHALCON_CONCAT_VS(primary_condition, primary_key, " = ?");
		phalcon_array_append(&conditions, primary_condition, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_8adf_10;
	fee_8adf_10:
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, " AND ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_join(r0, c1, conditions TSRMLS_CC);
	PHALCON_CPY_WRT(conditions, r0);
	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "beforeDelete", 1);
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_callevent", c2, PH_NO_CHECK);
		if (Z_TYPE_P(status) == IS_BOOL && !Z_BVAL_P(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, this_ptr, "getschema", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource", PH_NO_CHECK);
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		PHALCON_CONCAT_VSV(table, schema, ".", source);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_3(success, connection, "delete", table, conditions, values, PH_NO_CHECK);
	if (zend_is_true(success)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_VAR(c3);
			ZVAL_STRING(c3, "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", c3, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(success);
}

/**
 * Reads an attribute value by its name
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute){

	zval *attribute = NULL, *attribute_value = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attribute) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC);
	if (eval_int) {
		PHALCON_INIT_VAR(attribute_value);
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY_CC);
		
		RETURN_CCTOR(attribute_value);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Writes an attribute value by its name
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute){

	zval *attribute = NULL, *value = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &value) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *dependency_injector = NULL, *manager = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addhasone", this_ptr, fields, reference_model, referenced_fields, options, PH_NO_CHECK);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *dependency_injector = NULL, *manager = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addbelongsto", this_ptr, fields, reference_model, referenced_fields, options, PH_NO_CHECK);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation 1-n between two models
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany){

	zval *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *dependency_injector = NULL, *manager = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addhasmany", this_ptr, fields, reference_model, referenced_fields, options, PH_NO_CHECK);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
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
 * @throwsPhalcon\Mvc\Model\Exception
 */
PHP_METHOD(Phalcon_Mvc_Model, __call){

	zval *method = NULL, *arguments = NULL, *dependency_injector = NULL;
	zval *manager = NULL, *manager_method = NULL, *model_name = NULL;
	zval *action = NULL, *requested_relation = NULL, *exists = NULL, *query_method = NULL;
	zval *model_args = NULL, *arguments_merge = NULL, *call_message = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL, *c4 = NULL, *c5 = NULL, *c6 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_INIT_VAR(manager_method);
	ZVAL_BOOL(manager_method, 0);
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr TSRMLS_CC);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 0);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_LONG(c2, 3);
	
	PHALCON_INIT_VAR(action);
	PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, c1, c2);
	if (PHALCON_COMPARE_STRING(action, "get")) {
		PHALCON_INIT_VAR(c3);
		ZVAL_LONG(c3, 3);
		PHALCON_INIT_VAR(requested_relation);
		PHALCON_CALL_FUNC_PARAMS_2(requested_relation, "substr", method, c3);
		
		PHALCON_INIT_VAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existsbelongsto", model_name, requested_relation, PH_NO_CHECK);
		if (zend_is_true(exists)) {
			PHALCON_INIT_VAR(manager_method);
			ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			
			PHALCON_INIT_VAR(query_method);
			ZVAL_STRING(query_method, "findFirst", 1);
		} else {
			PHALCON_INIT_VAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasmany", model_name, requested_relation, PH_NO_CHECK);
			if (zend_is_true(exists)) {
				PHALCON_INIT_VAR(manager_method);
				ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				
				PHALCON_INIT_VAR(query_method);
				ZVAL_STRING(query_method, "find", 1);
			} else {
				PHALCON_INIT_VAR(exists);
				PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasone", model_name, requested_relation, PH_NO_CHECK);
				if (zend_is_true(exists)) {
					PHALCON_INIT_VAR(manager_method);
					ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					
					PHALCON_INIT_VAR(query_method);
					ZVAL_STRING(query_method, "findFirst", 1);
				}
			}
		}
	}
	
	if (!zend_is_true(manager_method)) {
		PHALCON_INIT_VAR(c4);
		ZVAL_LONG(c4, 0);
		PHALCON_INIT_VAR(c5);
		ZVAL_LONG(c5, 5);
		PHALCON_INIT_VAR(action);
		PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, c4, c5);
		if (PHALCON_COMPARE_STRING(action, "count")) {
			PHALCON_INIT_VAR(query_method);
			ZVAL_STRING(query_method, "count", 1);
			
			PHALCON_INIT_VAR(c6);
			ZVAL_LONG(c6, 5);
			
			PHALCON_INIT_VAR(requested_relation);
			PHALCON_CALL_FUNC_PARAMS_2(requested_relation, "substr", method, c6);
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_METHOD_PARAMS_2(r0, manager, "existsbelongsto", model_name, requested_relation, PH_NO_CHECK);
			if (zend_is_true(r0)) {
				PHALCON_INIT_VAR(manager_method);
				ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r1);
				PHALCON_CALL_METHOD_PARAMS_2(r1, manager, "existshasmany", model_name, requested_relation, PH_NO_CHECK);
				if (zend_is_true(r1)) {
					PHALCON_INIT_VAR(manager_method);
					ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				} else {
					PHALCON_ALLOC_ZVAL_MM(r2);
					PHALCON_CALL_METHOD_PARAMS_2(r2, manager, "existshasone", model_name, requested_relation, PH_NO_CHECK);
					if (zend_is_true(r2)) {
						PHALCON_INIT_VAR(manager_method);
						ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					}
				}
			}
		}
	}
	
	if (zend_is_true(manager_method)) {
		PHALCON_INIT_VAR(model_args);
		array_init(model_args);
		phalcon_array_append(&model_args, query_method, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&model_args, model_name, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&model_args, requested_relation, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&model_args, this_ptr, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(arguments_merge);
		PHALCON_CALL_FUNC_PARAMS_2(arguments_merge, "array_merge", model_args, arguments);
		
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		phalcon_array_append(&a0, manager, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&a0, manager_method, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_FUNC_PARAMS_2(r3, "call_user_func_array", a0, arguments_merge);
		RETURN_CTOR(r3);
	}
	
	PHALCON_INIT_VAR(call_message);
	PHALCON_CONCAT_SVSVS(call_message, "The method \"", method, "\" doesn't exist on model \"", model_name, "\"");
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_mvc_model_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", call_message, PH_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
}

PHP_METHOD(Phalcon_Mvc_Model, serialize){

	zval *dependency_injector = NULL, *meta_data = NULL, *attributes = NULL;
	zval *null_value = NULL, *data = NULL, *attribute = NULL, *value = NULL, *serialize = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", c0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(null_value);
	ZVAL_NULL(null_value);
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_8adf_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_8adf_11;
		}
		
		PHALCON_INIT_VAR(attribute);
		ZVAL_ZVAL(attribute, *hd, 1, 0);
		eval_int = phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute, PH_NOISY_CC);
			phalcon_array_update_zval(&data, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&data, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_8adf_11;
	fee_8adf_11:
	
	PHALCON_INIT_VAR(serialize);
	PHALCON_CALL_FUNC_PARAMS_1(serialize, "serialize", data);
	
	RETURN_CCTOR(serialize);
}

PHP_METHOD(Phalcon_Mvc_Model, unserialize){

	zval *data = NULL, *attributes = NULL, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_FUNC_PARAMS_1(attributes, "unserialize", data);
	if (Z_TYPE_P(attributes) == IS_ARRAY) { 
		if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(attributes);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_8adf_12:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_8adf_12;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_8adf_12;
		fee_8adf_12:
		if(0){}
		
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

