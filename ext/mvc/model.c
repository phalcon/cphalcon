
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
#include "kernel/string.h"

/**
 * Phalcon\Mvc\Model
 *
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
 *
 * <p>Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.</p>
 *
 * <code>
 *
 * $robot = new Robots();
 * $robot->type = 'mechanical'
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo $message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
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
	zval *db_service = NULL, *service_name, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzz", &dependency_injector, &manager_service, &db_service) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_NVAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	if (!manager_service) {
		PHALCON_INIT_NVAR(manager_service);
	}
	
	if (!db_service) {
		PHALCON_INIT_NVAR(db_service);
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_INIT_VAR(service_name);
	ZVAL_STRING(service_name, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service_name, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(manager, "initialize", this_ptr, PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI){

	zval *dependency_injector;

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

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager){

	zval *events_manager;

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

	zval *dependency_injector, *model, *connection;
	zval *params, *service_name, *meta_data, *source;
	zval *schema, *select, *bound_params = NULL, *bind_types = NULL;
	zval *attributes, *table, *conditions = NULL, *no_primary = NULL;
	zval *primary_keys, *first_primary_key, *primary_key_condition;
	zval *bind_params, *converted_params, *converted_sql;
	zval *group_clause, *order_clause, *limit_clause;
	zval *for_update, *shared_lock, *dialect, *sql;
	zval *statement;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &dependency_injector, &model, &connection, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(service_name);
	ZVAL_STRING(service_name, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(select);
	array_init(select);
	
	PHALCON_INIT_VAR(bound_params);
	
	PHALCON_INIT_VAR(bind_types);
	
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
	eval_int = phalcon_array_isset_string(params, SS("conditions"));
	if (eval_int) {
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(no_primary);
			ZVAL_BOOL(no_primary, 0);
			
			PHALCON_INIT_NVAR(conditions);
			phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
			if (Z_TYPE_P(conditions) == IS_LONG) {
				PHALCON_INIT_VAR(primary_keys);
				PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", model, PH_NO_CHECK);
				eval_int = phalcon_array_isset_long(primary_keys, 0);
				if (eval_int) {
					PHALCON_INIT_VAR(first_primary_key);
					phalcon_array_fetch_long(&first_primary_key, primary_keys, 0, PH_NOISY_CC);
					
					PHALCON_INIT_VAR(primary_key_condition);
					PHALCON_CONCAT_VSV(primary_key_condition, first_primary_key, " = ", conditions);
					PHALCON_CPY_WRT(conditions, primary_key_condition);
				} else {
					ZVAL_BOOL(no_primary, 1);
				}
				
				if (PHALCON_IS_TRUE(no_primary)) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Source related to this model does not have a primary key defined");
					return;
				}
			}
		}
	}
	
	if (zend_is_true(conditions)) {
		eval_int = phalcon_array_isset_string(params, SS("bind"));
		if (eval_int) {
			PHALCON_INIT_VAR(bind_params);
			phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(converted_params);
			PHALCON_CALL_METHOD_PARAMS_2(converted_params, connection, "convertboundparams", conditions, bind_params, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(converted_sql);
			phalcon_array_fetch_string(&converted_sql, converted_params, SL("sql"), PH_NOISY_CC);
			phalcon_array_update_string(&select, SL("where"), &converted_sql, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			phalcon_array_fetch_string(&bound_params, converted_params, SL("params"), PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(params, SS("bindTypes"));
			if (eval_int) {
				phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY_CC);
			}
		} else {
			phalcon_array_update_string(&select, SL("where"), &conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SS("group"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_clause);
		phalcon_array_fetch_string(&group_clause, params, SL("group"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("group"), &group_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("order"));
	if (eval_int) {
		PHALCON_INIT_VAR(order_clause);
		phalcon_array_fetch_string(&order_clause, params, SL("order"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("order"), &order_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit_clause);
		phalcon_array_fetch_string(&limit_clause, params, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("limit"), &limit_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("for_update"));
	if (eval_int) {
		PHALCON_INIT_VAR(for_update);
		phalcon_array_fetch_string(&for_update, params, SL("for_update"), PH_NOISY_CC);
		if (zend_is_true(for_update)) {
			phalcon_array_update_string_bool(&select, SL("for_update"), 1, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SS("shared_lock"));
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
	if (Z_TYPE_P(bound_params) != IS_NULL) {
		PHALCON_INIT_VAR(statement);
		array_init(statement);
		phalcon_array_update_string(&statement, SL("sql"), &sql, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&statement, SL("params"), &bound_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&statement, SL("types"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		RETURN_CTOR(statement);
	}
	
	
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

	zval *model_name, *params, *unique, *dependency_injector = NULL;
	zval *cache = NULL, *cache_options, *key, *lifetime = NULL, *cache_service = NULL;
	zval *model, *connection, *resultset = NULL, *is_fresh;
	zval *bind_params = NULL, *bind_types = NULL, *select = NULL, *sql = NULL, *result;
	zval *count, *fetch_assoc, *row, *fetch_both, *dumped_result;
	zval *result_data = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model_name, &params, &unique) == FAILURE) {
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
	
	PHALCON_INIT_VAR(cache);
	eval_int = phalcon_array_isset_string(params, SS("cache"));
	if (eval_int) {
		PHALCON_INIT_VAR(cache_options);
		phalcon_array_fetch_string(&cache_options, params, SL("cache"), PH_NOISY_CC);
		if (Z_TYPE_P(cache_options) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid caching options");
			return;
		}
		
		eval_int = phalcon_array_isset_string(cache_options, SS("key"));
		if (eval_int) {
			PHALCON_INIT_VAR(key);
			phalcon_array_fetch_string(&key, cache_options, SL("key"), PH_NOISY_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A cache key must be provided to identify the cached resultset in the cache backend");
			return;
		}
		
		eval_int = phalcon_array_isset_string(cache_options, SS("lifetime"));
		if (eval_int) {
			PHALCON_INIT_VAR(lifetime);
			phalcon_array_fetch_string(&lifetime, cache_options, SL("lifetime"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(lifetime);
			ZVAL_LONG(lifetime, 3600);
		}
		
		eval_int = phalcon_array_isset_string(cache_options, SS("service"));
		if (eval_int) {
			PHALCON_INIT_VAR(cache_service);
			phalcon_array_fetch_string(&cache_service, cache_options, SL("service"), PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(cache_service);
			ZVAL_STRING(cache_service, "modelsCache", 1);
		}
		
		PHALCON_CALL_METHOD_PARAMS_1(cache, dependency_injector, "getshared", cache_service, PH_NO_CHECK);
	}
	
	ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
	PHALCON_INIT_VAR(model);
	object_init_ex(model, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", dependency_injector, PH_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	if (Z_TYPE_P(cache) != IS_NULL) {
		PHALCON_INIT_VAR(resultset);
		PHALCON_CALL_METHOD_PARAMS_2(resultset, cache, "get", key, lifetime, PH_NO_CHECK);
		if (Z_TYPE_P(resultset) != IS_NULL) {
			PHALCON_INIT_VAR(is_fresh);
			ZVAL_BOOL(is_fresh, 0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(resultset, "setisfresh", is_fresh, PH_NO_CHECK);
			
			RETURN_CCTOR(resultset);
		}
	}
	
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	p0[0] = dependency_injector;
	p0[1] = model;
	p0[2] = connection;
	p0[3] = params;
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_createsqlselect", 4, p0);
	PHALCON_CPY_WRT(select, r0);
	if (Z_TYPE_P(select) == IS_ARRAY) { 
		PHALCON_INIT_VAR(sql);
		phalcon_array_fetch_string(&sql, select, SL("sql"), PH_NOISY_CC);
		
		phalcon_array_fetch_string(&bind_params, select, SL("params"), PH_NOISY_CC);
		
		phalcon_array_fetch_string(&bind_types, select, SL("types"), PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(sql, select);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, connection, "query", sql, bind_params, bind_types, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD_PARAMS_1(count, result, "numrows", result, PH_NO_CHECK);
	if (PHALCON_IS_TRUE(unique)) {
		if (!zend_is_true(count)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		} else {
			PHALCON_INIT_VAR(fetch_assoc);
			ZVAL_LONG(fetch_assoc, 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_assoc, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(row);
			PHALCON_CALL_METHOD_PARAMS_1(row, result, "fetcharray", result, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(fetch_both);
			ZVAL_LONG(fetch_both, 2);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_both, PH_NO_CHECK);
			
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
	
	PHALCON_INIT_NVAR(resultset);
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
 *<code>
 *try {
 *
 *  $transactionManager = new Phalcon\Mvc\Model\Transaction\Manager();
 *
 *  $transaction = $transactionManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if($robot->save()==false){
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *}
 *catch(Phalcon\Mvc\Model\Transaction\Failed $e){
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 * @param Phalcon\Mvc\Model\Transaction $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction){

	zval *transaction, *connection;

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
	
	RETURN_CTOR(this_ptr);
}

/**
 * Sets table name which model should be mapped
 *
 * @param string $source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource){

	zval *source;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &source) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource){

	zval *source = NULL, *class_name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(source);
	phalcon_read_property(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!zend_is_true(source)) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, this_ptr TSRMLS_CC);
		
		PHALCON_INIT_NVAR(source);
		phalcon_uncamelize(source, class_name TSRMLS_CC);
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

	zval *schema;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &schema) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_schema"), schema TSRMLS_CC);
	
	RETURN_CTORW(this_ptr);
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema){

	zval *schema;

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

	zval *connection_service;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection_service) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_connectionService"), connection_service TSRMLS_CC);
	
}

/**
 * Returns DependencyInjection connection service
 *
 * @return $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model, getConnectionService){

	zval *connection_service;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(connection_service);
	phalcon_read_property(&connection_service, this_ptr, SL("_connectionService"), PH_NOISY_CC);
	
	RETURN_CCTOR(connection_service);
}

/**
 *
 */
PHP_METHOD(Phalcon_Mvc_Model, setForceExists){

	zval *force_exists, *force_exists_bool = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &force_exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(force_exists);
	
	PHALCON_INIT_VAR(r0);
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

	zval *connection = NULL, *connection_service, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_INIT_VAR(connection_service);
		phalcon_read_property(&connection_service, this_ptr, SL("_connectionService"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD_PARAMS_1(connection, dependency_injector, "getshared", connection_service, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::dumpResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param array $result
 * @param Phalcon\Mvc\Model $base
 * @return Phalcon\Mvc\Model $result
 */
PHP_METHOD(Phalcon_Mvc_Model, dumpResult){

	zval *base, *result, *object, *force_exists, *value = NULL;
	zval *key = NULL;
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

	if (Z_TYPE_P(result) == IS_ARRAY) { 
		PHALCON_INIT_VAR(object);
		if (phalcon_clone(object, base TSRMLS_CC) == FAILURE) {
			return;
		}
		
		PHALCON_INIT_VAR(force_exists);
		ZVAL_BOOL(force_exists, 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "setforceexists", force_exists, PH_NO_CHECK);
		
		if (!phalcon_valid_foreach(result TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(result);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
			
			phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		
		RETURN_CCTOR(object);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
	return;
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots);
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find("type='mechanical'");
 * echo "There are ", count($robots);
 *
 * //Get and print virtual robots ordered by name
  * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
  * //Get first 100 virtual robots ordered by name
  * $robots = Robots::find(array("type='virtual'", "order" => "name", "limit" => 100));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array $parameters
 * @return  Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, find){

	zval *parameters = NULL, *model_name, *params = NULL, *one_row;
	zval *resultset;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	PHALCON_CALL_FUNC(model_name, "get_called_class");
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init(params);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	PHALCON_INIT_VAR(one_row);
	ZVAL_BOOL(one_row, 0);
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_SELF_PARAMS_3(resultset, this_ptr, "_getorcreateresultset", model_name, params, one_row);
	
	RETURN_CCTOR(resultset);
}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name;
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst("type='mechanical'");
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * //Get first virtual robot ordered by name
  * $robot = Robots::findFirst(array("type='virtual'", "order" => "name"));
 * echo "The first virtual robot name is ", $robot->name;
 *
 * </code>
 *
 * @param array $parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst){

	zval *parameters = NULL, *model_name, *params = NULL, *one_row;
	zval *model;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	PHALCON_CALL_FUNC(model_name, "get_called_class");
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init(params);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("limit"));
	if (!eval_int) {
		phalcon_array_update_string_string(&params, SL("limit"), SL("1"), PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(one_row);
	ZVAL_BOOL(one_row, 1);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_SELF_PARAMS_3(model, this_ptr, "_getorcreateresultset", model_name, params, one_row);
	
	RETURN_CCTOR(model);
}

/**
 * Create a criteria for a especific model
 *
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model, query){

	zval *dependency_injector = NULL, *model_name, *criteria;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_NVAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	PHALCON_INIT_VAR(model_name);
	PHALCON_CALL_FUNC(model_name, "get_called_class");
	if (Z_TYPE_P(dependency_injector) == IS_NULL) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	
	PHALCON_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	PHALCON_CALL_METHOD_NORETURN(criteria, "__construct", PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "setdi", dependency_injector, PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "setmodelname", model_name, PH_NO_CHECK);
	
	RETURN_CTOR(criteria);
}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\Metadata $metaData
 * @param Phalcon\Db $connection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists){

	zval *meta_data, *connection = NULL, *table = NULL, *unique_key = NULL;
	zval *primary_keys, *primary_keys_count, *where_pk;
	zval *field = NULL, *value = NULL, *sanitized_value = NULL, *pk_condition = NULL;
	zval *where_pk_count, *join_where, *force_exists;
	zval *schema, *source, *select, *num, *row_count;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &meta_data, &connection, &table) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(connection);
	
	if (!table) {
		PHALCON_INIT_NVAR(table);
	} else {
		PHALCON_SEPARATE_PARAM(table);
	}
	
	PHALCON_INIT_VAR(unique_key);
	phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(unique_key) == IS_NULL) {
		PHALCON_INIT_VAR(primary_keys);
		PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(primary_keys_count);
		phalcon_fast_count(primary_keys_count, primary_keys TSRMLS_CC);
		if (!phalcon_compare_strict_long(primary_keys_count, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(where_pk);
			array_init(where_pk);
			
			PHALCON_INIT_NVAR(connection);
			PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
			
			if (!phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(primary_keys);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
				
				PHALCON_GET_FOREACH_VALUE(field);
				
				eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
				if (eval_int) {
					PHALCON_INIT_NVAR(value);
					phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
					if (PHALCON_IS_NOT_EMPTY(value)) {
						if (Z_TYPE_P(value) != IS_LONG) {
							PHALCON_INIT_NVAR(sanitized_value);
							PHALCON_CALL_METHOD_PARAMS_1(sanitized_value, connection, "escapestring", value, PH_NO_CHECK);
						} else {
							PHALCON_CPY_WRT(sanitized_value, value);
						}
						
						PHALCON_INIT_NVAR(pk_condition);
						PHALCON_CONCAT_VSV(pk_condition, field, " = ", sanitized_value);
						phalcon_array_append(&where_pk, pk_condition, PH_SEPARATE TSRMLS_CC);
					}
				}
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
				
			ph_cycle_end_0:
			
			PHALCON_INIT_VAR(where_pk_count);
			phalcon_fast_count(where_pk_count, where_pk TSRMLS_CC);
			if (zend_is_true(where_pk_count)) {
				PHALCON_INIT_VAR(join_where);
				phalcon_fast_join_str(join_where, SL(" AND "), where_pk TSRMLS_CC);
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
	if (PHALCON_IS_FALSE(force_exists)) {
		if (Z_TYPE_P(table) == IS_NULL) {
			PHALCON_INIT_VAR(schema);
			PHALCON_CALL_METHOD(schema, this_ptr, "getschema", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD(source, this_ptr, "getsource", PH_NO_CHECK);
			if (zend_is_true(schema)) {
				PHALCON_INIT_NVAR(table);
				PHALCON_CONCAT_VSV(table, schema, ".", source);
			} else {
				PHALCON_CPY_WRT(table, source);
			}
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

	zval *function, *alias, *parameters, *params = NULL, *group_column = NULL;
	zval *dependency_injector, *class_name, *model;
	zval *connection, *schema, *source, *table = NULL, *bound_params = NULL;
	zval *bind_types = NULL, *select, *distinct_column;
	zval *columns = NULL, *group_columns, *conditions = NULL, *bind_params;
	zval *converted_params, *converted_sql, *group_clause;
	zval *having_clause, *order_clause, *limit_clause;
	zval *dialect, *sql, *statement = NULL, *resultset = NULL;
	zval *r0 = NULL;
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
			PHALCON_INIT_NVAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	eval_int = phalcon_array_isset_string(params, SS("column"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_column);
		phalcon_array_fetch_string(&group_column, params, SL("column"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(group_column);
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
	
	PHALCON_INIT_VAR(bound_params);
	
	PHALCON_INIT_VAR(bind_types);
	
	PHALCON_INIT_VAR(select);
	array_init(select);
	phalcon_array_update_string(&select, SL("tables"), &table, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(params, SS("distinct"));
	if (eval_int) {
		PHALCON_INIT_VAR(distinct_column);
		phalcon_array_fetch_string(&distinct_column, params, SL("distinct"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(columns);
		PHALCON_CONCAT_VSVSV(columns, function, "(DISTINCT ", distinct_column, ") AS ", alias);
	} else {
		eval_int = phalcon_array_isset_string(params, SS("group"));
		if (eval_int) {
			PHALCON_INIT_VAR(group_columns);
			phalcon_array_fetch_string(&group_columns, params, SL("group"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSVSV(columns, group_columns, ", ", function, "(", group_column, ") AS ", alias);
		} else {
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSV(columns, function, "(", group_column, ") AS ", alias);
		}
	}
	
	phalcon_array_update_string(&select, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(conditions);
	eval_int = phalcon_array_isset_string(params, SS("conditions"));
	if (eval_int) {
		phalcon_array_fetch_string(&conditions, params, SL("conditions"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_long(params, 0);
		if (eval_int) {
			PHALCON_INIT_NVAR(conditions);
			phalcon_array_fetch_long(&conditions, params, 0, PH_NOISY_CC);
		}
	}
	
	if (zend_is_true(conditions)) {
		eval_int = phalcon_array_isset_string(params, SS("bind"));
		if (eval_int) {
			PHALCON_INIT_VAR(bind_params);
			phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(converted_params);
			PHALCON_CALL_METHOD_PARAMS_2(converted_params, connection, "convertboundparams", conditions, bind_params, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(converted_sql);
			phalcon_array_fetch_string(&converted_sql, converted_params, SL("sql"), PH_NOISY_CC);
			phalcon_array_update_string(&select, SL("where"), &converted_sql, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			phalcon_array_fetch_string(&bound_params, converted_params, SL("params"), PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(params, SS("bindTypes"));
			if (eval_int) {
				phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY_CC);
			}
		} else {
			phalcon_array_update_string(&select, SL("where"), &conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(params, SS("group"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_clause);
		phalcon_array_fetch_string(&group_clause, params, SL("group"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("group"), &group_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("having"));
	if (eval_int) {
		PHALCON_INIT_VAR(having_clause);
		phalcon_array_fetch_string(&having_clause, params, SL("having"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("having"), &having_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("order"));
	if (eval_int) {
		PHALCON_INIT_VAR(order_clause);
		phalcon_array_fetch_string(&order_clause, params, SL("order"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("order"), &order_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(params, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit_clause);
		phalcon_array_fetch_string(&limit_clause, params, SL("limit"), PH_NOISY_CC);
		phalcon_array_update_string(&select, SL("limit"), &limit_clause, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, dialect, "select", select, PH_NO_CHECK);
	if (Z_TYPE_P(bound_params) != IS_NULL) {
		PHALCON_INIT_VAR(statement);
		array_init(statement);
		phalcon_array_update_string(&statement, SL("sql"), &sql, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&statement, SL("params"), &bound_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&statement, SL("types"), &bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(statement, sql);
	}
	
	p0[0] = connection;
	p0[1] = params;
	p0[2] = statement;
	p0[3] = alias;
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_SELF_PARAMS(r0, this_ptr, "_getgroupresult", 4, p0);
	PHALCON_CPY_WRT(resultset, r0);
	
	RETURN_CCTOR(resultset);
}

/**
 * Generate a resulset from an SQL select with aggregations
 *
 * @param Phalcon\Db $connection
 * @param array $params
 * @param string $select
 * @param string $alias
 * @return array|Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model, _getGroupResult){

	zval *connection, *params, *select, *alias, *sql = NULL, *bind_params = NULL;
	zval *bind_types = NULL, *result = NULL, *count, *row_object = NULL;
	zval *cache, *resultset, *num, *group_value;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &connection, &params, &select, &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(select) == IS_ARRAY) { 
		PHALCON_INIT_VAR(sql);
		phalcon_array_fetch_string(&sql, select, SL("sql"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(bind_params);
		phalcon_array_fetch_string(&bind_params, select, SL("params"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(bind_types);
		phalcon_array_fetch_string(&bind_types, select, SL("types"), PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(sql, select);
		
		PHALCON_INIT_NVAR(bind_params);
		
		PHALCON_INIT_NVAR(bind_types);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, connection, "query", sql, bind_params, bind_types, PH_NO_CHECK);
	eval_int = phalcon_array_isset_string(params, SS("group"));
	if (eval_int) {
		PHALCON_INIT_VAR(count);
		PHALCON_CALL_METHOD(count, result, "numrows", PH_NO_CHECK);
		if (zend_is_true(count)) {
			PHALCON_INIT_VAR(row_object);
			object_init_ex(row_object, phalcon_mvc_model_row_ce);
		} else {
			PHALCON_INIT_NVAR(row_object);
			object_init(row_object);
			
			PHALCON_INIT_NVAR(result);
			ZVAL_BOOL(result, 0);
		}
		
		PHALCON_INIT_VAR(cache);
		
		PHALCON_INIT_VAR(resultset);
		object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", row_object, result, cache, PH_CHECK);
		
		RETURN_CTOR(resultset);
	}
	
	PHALCON_INIT_VAR(num);
	PHALCON_CALL_METHOD(num, result, "fetcharray", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(group_value);
	phalcon_array_fetch(&group_value, num, alias, PH_NOISY_CC);
	
	RETURN_CCTOR(group_value);
}

/**
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number;
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type='mechanical'");
 * echo "There are ", $number, " mechanical robots";
 *
 * </code>
 *
 * @param array $parameters
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, count){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "COUNT", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "rowcount", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", function, alias, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to a calculate a summatory on a column that match the specified conditions
 *
 * <code>
 *
 * //How much are all robots?
 * $sum = Robots::sum(array('column' => 'price'));
 * echo "The total price of robots is ", $sum;
 *
 * //How much are mechanical robots?
 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum;
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, sum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "SUM", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "sumatory", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", function, alias, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the maximum robot id?
 * $id = Robots::maximum(array('column' => 'id'));
 * echo "The maximum robot id is: ", $id;
 *
 * //What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
 * echo "The maximum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MAX", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "maximum", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", function, alias, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the minimum robot id?
 * $id = Robots::minimum(array('column' => 'id'));
 * echo "The minimum robot id is: ", $id;
 *
 * //What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(array("type='mechanical'", 'column' => 'id'));
 * echo "The minimum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MIN", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "minimum", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", function, alias, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * <code>
 *
 * //What's the average price of robots?
 * $average = Robots::average(array('column' => 'price'));
 * echo "The average price is ", $average;
 *
 * //What's the average price of mechanical robots?
 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
 * echo "The average price of mechanical robots is ", $average;
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "AVG", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "average", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_preparegroupresult", function, alias, parameters);
	
	RETURN_CCTOR(group);
}

/**
 * Fires an internal event
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _callEvent){

	zval *event_name, *events_manager, *fire_event_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, Z_STRVAL_P(event_name), PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", fire_event_name, this_ptr, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Fires an internal event that cancels the operation
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _callEventCancel){

	zval *event_name, *status = NULL, *events_manager, *fire_event_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, Z_STRVAL_P(event_name), PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", fire_event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
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

	zval *disable_events, *operation_made, *event_name = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &disable_events) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(operation_made);
		phalcon_read_property(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY_CC);
		if (phalcon_compare_strict_long(operation_made, 3 TSRMLS_CC)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "notDeleted", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "notSaved", 1);
		}
		
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
	}
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends Phalcon\Mvc\Model
 * {
 *
 *   public function beforeSave()
 *   {
 *     if (this->name == 'Peter') {
 *        $message = new Message("Sorry, but a robot cannot be named Peter");
 *        $this->appendMessage($message);
 *     }
 *   }
 * }
 * </code>
 *
 * @param Phalcon\Mvc\Model\Message $message
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage){

	zval *message, *type, *exception_message;
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
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	phalcon_array_append(&t0, message, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @param object $validator
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, validate){

	zval *validator, *status, *messages, *message = NULL;
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
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, validator, "getmessages", PH_NO_CHECK);
		
		if (!phalcon_valid_foreach(messages TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(messages);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(message);
			
			PHALCON_INIT_NVAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
			phalcon_array_append(&t0, message, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t0 TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed){

	zval *error_messages, *number_messages;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(error_messages);
	phalcon_read_property(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_messages);
	phalcon_fast_count(number_messages, error_messages TSRMLS_CC);
	if (!phalcon_compare_strict_long(number_messages, 0 TSRMLS_CC)) {
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Returns all the validation messages
 *
 * <code>
 *$robot = new Robots();
 *$robot->type = 'mechanical';
 *$robot->name = 'Astro Boy';
 *$robot->year = 1952;
 *if ($robot->save() == false) {
 *  echo "Umh, We can't store robots right now ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo $message;
 *  }
 *} else {
 *  echo "Great, a new robot was saved successfully!";
 *}
 * </code>
 *
 * @return Phalcon\Mvc\Model\Message[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages){

	zval *error_messages;

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

	zval *dependency_injector, *disable_events;
	zval *service, *manager, *belongs_to, *number_belongs_to;
	zval *error = NULL, *relation = NULL, *options = NULL, *foreign_key = NULL;
	zval *conditions = NULL, *relation_class = NULL, *referenced_model = NULL;
	zval *fields = NULL, *referenced_fields = NULL, *field = NULL, *n = NULL, *value = NULL;
	zval *referenced_field = NULL, *condition = NULL, *extra_conditions = NULL;
	zval *connection_service = NULL, *join_conditions = NULL;
	zval *rowcount = NULL, *user_message = NULL, *joined_fields = NULL;
	zval *type = NULL, *message = NULL, *event_name;
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
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(belongs_to);
	PHALCON_CALL_METHOD_PARAMS_1(belongs_to, manager, "getbelongsto", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(number_belongs_to);
	phalcon_fast_count(number_belongs_to, belongs_to TSRMLS_CC);
	if (!phalcon_compare_strict_long(number_belongs_to, 0 TSRMLS_CC)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		
		if (!phalcon_valid_foreach(belongs_to TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(belongs_to);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(relation);
			
			eval_int = phalcon_array_isset_string(relation, SS("op"));
			if (eval_int) {
				PHALCON_INIT_NVAR(options);
				phalcon_array_fetch_string(&options, relation, SL("op"), PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(options, SS("foreignKey"));
				if (eval_int) {
					PHALCON_INIT_NVAR(foreign_key);
					phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY_CC);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_NVAR(conditions);
						array_init(conditions);
						
						PHALCON_INIT_NVAR(relation_class);
						phalcon_array_fetch_string(&relation_class, relation, SL("rt"), PH_NOISY_CC);
						ce0 = phalcon_fetch_class(relation_class TSRMLS_CC);
						
						PHALCON_INIT_NVAR(referenced_model);
						object_init_ex(referenced_model, ce0);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "__construct", dependency_injector, PH_CHECK);
						
						PHALCON_INIT_NVAR(fields);
						phalcon_array_fetch_string(&fields, relation, SL("fi"), PH_NOISY_CC);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							PHALCON_INIT_NVAR(referenced_fields);
							phalcon_array_fetch_string(&referenced_fields, relation, SL("rf"), PH_NOISY_CC);
							
							if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
								return;
							}
							
							ah1 = Z_ARRVAL_P(fields);
							zend_hash_internal_pointer_reset_ex(ah1, &hp1);
							
							ph_cycle_start_1:
							
								if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
									goto ph_cycle_end_1;
								}
								
								PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								PHALCON_GET_FOREACH_VALUE(field);
								
								PHALCON_INIT_NVAR(value);
								phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
								
								PHALCON_INIT_NVAR(referenced_field);
								phalcon_array_fetch(&referenced_field, referenced_fields, n, PH_NOISY_CC);
								
								PHALCON_INIT_NVAR(condition);
								PHALCON_CONCAT_VSVS(condition, referenced_field, " = '", value, "'");
								phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
								
								zend_hash_move_forward_ex(ah1, &hp1);
								goto ph_cycle_start_1;
								
							ph_cycle_end_1:
							if(0){}
							
						} else {
							PHALCON_INIT_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
							if (PHALCON_IS_EMPTY(value)) {
								goto ph_cycle_start_0;
							}
							
							PHALCON_INIT_NVAR(referenced_field);
							phalcon_array_fetch_string(&referenced_field, relation, SL("rf"), PH_NOISY_CC);
							
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, referenced_field, " = '", value, "'");
							phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, SS("conditions"));
						if (eval_int) {
							PHALCON_INIT_NVAR(extra_conditions);
							phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY_CC);
							phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE TSRMLS_CC);
						}
						
						PHALCON_INIT_NVAR(connection_service);
						PHALCON_CALL_METHOD(connection_service, this_ptr, "getconnectionservice", PH_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnectionservice", connection_service, PH_NO_CHECK);
						
						PHALCON_INIT_NVAR(join_conditions);
						phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
						
						PHALCON_INIT_NVAR(rowcount);
						PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", join_conditions, PH_NO_CHECK);
						if (!zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, SS("message"));
							if (eval_int) {
								PHALCON_INIT_NVAR(user_message);
								phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
							} else {
								if (Z_TYPE_P(fields) == IS_ARRAY) { 
									PHALCON_INIT_NVAR(joined_fields);
									phalcon_fast_join_str(joined_fields, SL(", "), fields TSRMLS_CC);
									
									PHALCON_INIT_NVAR(user_message);
									PHALCON_CONCAT_SVS(user_message, "Value of fields \"", joined_fields, "\" does not exist on referenced table");
								} else {
									PHALCON_INIT_NVAR(user_message);
									PHALCON_CONCAT_SVS(user_message, "Value of field \"", fields, "\" does not exist on referenced table");
								}
							}
							
							PHALCON_INIT_NVAR(type);
							ZVAL_STRING(type, "ConstraintViolation", 1);
							
							PHALCON_INIT_NVAR(message);
							object_init_ex(message, phalcon_mvc_model_message_ce);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, type, PH_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message, PH_NO_CHECK);
							
							PHALCON_INIT_NVAR(error);
							ZVAL_BOOL(error, 1);
							goto ph_cycle_end_0;
						}
					}
				}
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		if (PHALCON_IS_TRUE(error)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
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

	zval *dependency_injector, *disable_events;
	zval *service, *manager, *relations, *number_relations;
	zval *error = NULL, *relation = NULL, *options = NULL, *foreign_key = NULL;
	zval *fields = NULL, *referenced_name = NULL, *referenced_fields = NULL;
	zval *referenced_model = NULL, *conditions = NULL, *field = NULL;
	zval *n = NULL, *value = NULL, *referenced_field = NULL, *condition = NULL;
	zval *extra_conditions = NULL, *connection_service = NULL;
	zval *join_conditions = NULL, *rowcount = NULL, *user_message = NULL;
	zval *type = NULL, *message = NULL, *event_name;
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
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(relations);
	PHALCON_CALL_METHOD_PARAMS_1(relations, manager, "gethasoneandhasmany", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(number_relations);
	phalcon_fast_count(number_relations, relations TSRMLS_CC);
	if (!phalcon_compare_strict_long(number_relations, 0 TSRMLS_CC)) {
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
		
		if (!phalcon_valid_foreach(relations TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(relations);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(relation);
			
			eval_int = phalcon_array_isset_string(relation, SS("op"));
			if (eval_int) {
				PHALCON_INIT_NVAR(options);
				phalcon_array_fetch_string(&options, relation, SL("op"), PH_NOISY_CC);
				eval_int = phalcon_array_isset_string(options, SS("foreignKey"));
				if (eval_int) {
					PHALCON_INIT_NVAR(foreign_key);
					phalcon_array_fetch_string(&foreign_key, options, SL("foreignKey"), PH_NOISY_CC);
					if (zend_is_true(foreign_key)) {
						PHALCON_INIT_NVAR(fields);
						phalcon_array_fetch_string(&fields, relation, SL("fi"), PH_NOISY_CC);
						
						PHALCON_INIT_NVAR(referenced_name);
						phalcon_array_fetch_string(&referenced_name, relation, SL("rt"), PH_NOISY_CC);
						
						PHALCON_INIT_NVAR(referenced_fields);
						phalcon_array_fetch_string(&referenced_fields, relation, SL("rf"), PH_NOISY_CC);
						ce0 = phalcon_fetch_class(referenced_name TSRMLS_CC);
						
						PHALCON_INIT_NVAR(referenced_model);
						object_init_ex(referenced_model, ce0);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "__construct", dependency_injector, PH_CHECK);
						
						PHALCON_INIT_NVAR(conditions);
						array_init(conditions);
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							
							if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
								return;
							}
							
							ah1 = Z_ARRVAL_P(fields);
							zend_hash_internal_pointer_reset_ex(ah1, &hp1);
							
							ph_cycle_start_1:
							
								if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
									goto ph_cycle_end_1;
								}
								
								PHALCON_GET_FOREACH_KEY(n, ah1, hp1);
								PHALCON_GET_FOREACH_VALUE(field);
								
								eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
								if (eval_int) {
									PHALCON_INIT_NVAR(value);
									phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
								} else {
									PHALCON_INIT_NVAR(value);
								}
								
								PHALCON_INIT_NVAR(referenced_field);
								phalcon_array_fetch(&referenced_field, referenced_fields, n, PH_NOISY_CC);
								
								PHALCON_INIT_NVAR(condition);
								PHALCON_CONCAT_VSVS(condition, referenced_field, " = '", value, "'");
								phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
								
								zend_hash_move_forward_ex(ah1, &hp1);
								goto ph_cycle_start_1;
								
							ph_cycle_end_1:
							if(0){}
							
						} else {
							eval_int = phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC);
							if (eval_int) {
								PHALCON_INIT_NVAR(value);
								phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
							} else {
								PHALCON_INIT_NVAR(value);
							}
							
							PHALCON_INIT_NVAR(condition);
							PHALCON_CONCAT_VSVS(condition, referenced_fields, " = '", value, "'");
							phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
						}
						
						eval_int = phalcon_array_isset_string(foreign_key, SS("conditions"));
						if (eval_int) {
							PHALCON_INIT_NVAR(extra_conditions);
							phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY_CC);
							phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE TSRMLS_CC);
						}
						
						PHALCON_INIT_NVAR(connection_service);
						PHALCON_CALL_METHOD(connection_service, this_ptr, "getconnectionservice", PH_NO_CHECK);
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_model, "setconnectionservice", connection_service, PH_NO_CHECK);
						
						PHALCON_INIT_NVAR(join_conditions);
						phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
						
						PHALCON_INIT_NVAR(rowcount);
						PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", join_conditions, PH_NO_CHECK);
						if (zend_is_true(rowcount)) {
							eval_int = phalcon_array_isset_string(foreign_key, SS("message"));
							if (eval_int) {
								PHALCON_INIT_NVAR(user_message);
								phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
							} else {
								PHALCON_INIT_NVAR(user_message);
								PHALCON_CONCAT_SV(user_message, "Record is referenced by model ", referenced_name);
							}
							
							PHALCON_INIT_NVAR(type);
							ZVAL_STRING(type, "ConstraintViolation", 1);
							
							PHALCON_INIT_NVAR(message);
							object_init_ex(message, phalcon_mvc_model_message_ce);
							PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, type, PH_CHECK);
							PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message, PH_NO_CHECK);
							
							PHALCON_INIT_NVAR(error);
							ZVAL_BOOL(error, 1);
							goto ph_cycle_end_0;
						}
					}
				}
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		if (PHALCON_IS_TRUE(error)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
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

	zval *dependency_injector, *meta_data, *disable_events;
	zval *exists, *identity_field, *event_name = NULL, *status = NULL;
	zval *not_null, *data_type_numeric, *error = NULL, *num_fields;
	zval *null_value, *empty_str, *i, *is_null = NULL, *field = NULL;
	zval *value = NULL, *is_numeric = NULL, *is_identity_field = NULL;
	zval *message = NULL, *type = NULL, *model_message = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzzz", &dependency_injector, &meta_data, &disable_events, &exists, &identity_field) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeValidation", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnUpdate", 1);
		}
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "_checkforeignkeys", dependency_injector, disable_events, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(status)) {
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
		
		PHALCON_INIT_VAR(empty_str);
		ZVAL_STRING(empty_str, "", 1);
		
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		ph_cycle_start_0:
			
			PHALCON_INIT_NVAR(r0);
			is_smaller_function(r0, i, num_fields TSRMLS_CC);
			if (!zend_is_true(r0)) {
				goto ph_cycle_end_0;
			}
			PHALCON_INIT_NVAR(is_null);
			ZVAL_BOOL(is_null, 0);
			
			PHALCON_INIT_NVAR(field);
			phalcon_array_fetch(&field, not_null, i, PH_NOISY_CC);
			eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
			if (eval_int) {
				PHALCON_INIT_NVAR(value);
				phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
				eval_int = phalcon_array_isset(data_type_numeric, field);
				if (!eval_int) {
					if (PHALCON_IS_EMPTY(value)) {
						PHALCON_INIT_NVAR(is_null);
						ZVAL_BOOL(is_null, 1);
					}
				} else {
					PHALCON_INIT_NVAR(is_numeric);
					PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", value);
					if (PHALCON_IS_FALSE(is_numeric)) {
						PHALCON_INIT_NVAR(is_null);
						ZVAL_BOOL(is_null, 1);
					}
				}
			} else {
				PHALCON_INIT_NVAR(is_null);
				ZVAL_BOOL(is_null, 1);
			}
			
			if (PHALCON_IS_TRUE(is_null)) {
				if (PHALCON_IS_FALSE(exists)) {
					PHALCON_INIT_NVAR(is_identity_field);
					is_equal_function(is_identity_field, field, identity_field TSRMLS_CC);
					if (PHALCON_IS_TRUE(is_identity_field)) {
						goto ph_cycle_incr_0;
					}
				}
				
				PHALCON_INIT_NVAR(message);
				PHALCON_CONCAT_VS(message, field, " is required");
				
				PHALCON_INIT_NVAR(type);
				ZVAL_STRING(type, "PresenceOf", 1);
				
				PHALCON_INIT_NVAR(model_message);
				object_init_ex(model_message, phalcon_mvc_model_message_ce);
				PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, type, PH_CHECK);
				
				PHALCON_INIT_NVAR(t0);
				phalcon_read_property(&t0, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
				phalcon_array_append(&t0, model_message, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_errorMessages"), t0 TSRMLS_CC);
				
				PHALCON_INIT_NVAR(error);
				ZVAL_BOOL(error, 1);
			}
			ph_cycle_incr_0:
			PHALCON_SEPARATE(i);
			increment_function(i);
			goto ph_cycle_start_0;
		ph_cycle_end_0:
		if (PHALCON_IS_TRUE(error)) {
			if (!zend_is_true(disable_events)) {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
			}
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_canceloperation", disable_events, PH_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "validation", 1);
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(status)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
		}
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	if (!zend_is_true(disable_events)) {
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnUpdate", 1);
		}
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterValidation", 1);
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
		
		if (zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeUpdate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeCreate", 1);
		}
		
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
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

	zval *disable_events, *success, *exists, *event_name = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &disable_events, &success, &exists) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (PHALCON_IS_TRUE(success)) {
		if (!zend_is_true(disable_events)) {
			if (PHALCON_IS_TRUE(exists)) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "afterUpdate", 1);
			} else {
				PHALCON_INIT_NVAR(event_name);
				ZVAL_STRING(event_name, "afterCreate", 1);
			}
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
			
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
		}
		
		RETURN_CCTOR(success);
	} else {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "notSave", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
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

	zval *meta_data, *connection, *table, *identity_field;
	zval *null_value, *bind_skip, *fields, *values;
	zval *bind_types, *attributes, *bind_data_types;
	zval *automatic_attributes, *field = NULL, *is_identity_field = NULL;
	zval *exception_message = NULL, *value = NULL, *bind_type = NULL;
	zval *default_value, *id, *success, *sequence_name = NULL;
	zval *support_sequences, *source, *last_insert_id;
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
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(automatic_attributes);
	PHALCON_CALL_METHOD_PARAMS_1(automatic_attributes, meta_data, "getautomaticcreateattributes", this_ptr, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(field);
		
		eval_int = phalcon_array_isset(automatic_attributes, field);
		if (!eval_int) {
			PHALCON_INIT_NVAR(is_identity_field);
			is_not_equal_function(is_identity_field, field, identity_field TSRMLS_CC);
			if (PHALCON_IS_TRUE(is_identity_field)) {
				phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
				eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
				if (eval_int) {
					eval_int = phalcon_array_isset(bind_data_types, field);
					if (!eval_int) {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the table columns");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
					
					PHALCON_INIT_NVAR(value);
					phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
					phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
					
					PHALCON_INIT_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY_CC);
					phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
				}
			}
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	if (PHALCON_IS_NOT_FALSE(identity_field)) {
		PHALCON_INIT_VAR(default_value);
		PHALCON_CALL_METHOD(default_value, connection, "getdefaultidvalue", PH_NO_CHECK);
		phalcon_array_append(&fields, identity_field, PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_isset_property_zval(this_ptr, identity_field TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_VAR(id);
			phalcon_read_property_zval(&id, this_ptr, identity_field, PH_NOISY_CC);
			if (PHALCON_IS_EMPTY(id)) {
				phalcon_array_append(&values, default_value, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&bind_data_types, bind_skip, PH_SEPARATE TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset(bind_data_types, identity_field);
				if (!eval_int) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Identity column '", identity_field, "\" isn't part of the table columns");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
				phalcon_array_append(&values, id, PH_SEPARATE TSRMLS_CC);
				
				PHALCON_INIT_NVAR(bind_type);
				phalcon_array_fetch(&bind_type, bind_data_types, identity_field, PH_NOISY_CC);
				phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			phalcon_array_append(&values, default_value, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_4(success, connection, "insert", table, values, fields, bind_types, PH_NO_CHECK);
	if (PHALCON_IS_NOT_FALSE(identity_field)) {
		PHALCON_INIT_VAR(sequence_name);
		
		PHALCON_INIT_VAR(support_sequences);
		PHALCON_CALL_METHOD(support_sequences, connection, "supportsequences", PH_NO_CHECK);
		if (PHALCON_IS_TRUE(support_sequences)) {
			if (phalcon_method_exists_ex(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD(sequence_name, this_ptr, "getsequencename", PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(source);
				PHALCON_CALL_METHOD(source, this_ptr, "getsource", PH_NO_CHECK);
				
				PHALCON_INIT_NVAR(sequence_name);
				PHALCON_CONCAT_VSVS(sequence_name, source, "_", identity_field, "_seq");
			}
		}
		
		PHALCON_INIT_VAR(last_insert_id);
		PHALCON_CALL_METHOD_PARAMS_1(last_insert_id, connection, "lastinsertid", sequence_name, PH_NO_CHECK);
		phalcon_update_property_zval_zval(this_ptr, identity_field, last_insert_id TSRMLS_CC);
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

	zval *meta_data, *connection, *table, *null_value;
	zval *bind_skip, *fields, *values, *bind_types;
	zval *bind_data_types, *non_primary, *field = NULL;
	zval *exception_message = NULL, *value = NULL, *bind_type = NULL;
	zval *unique_key, *success;
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
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(non_primary);
	PHALCON_CALL_METHOD_PARAMS_1(non_primary, meta_data, "getnonprimarykeyattributes", this_ptr, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(non_primary TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(non_primary);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(field);
		
		eval_int = phalcon_array_isset(bind_data_types, field);
		if (!eval_int) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the table columns");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
		phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_isset_property_zval(this_ptr, field TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
			phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(unique_key);
	phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_5(success, connection, "update", table, fields, values, unique_key, bind_types, PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical'
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->save();
 *
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->save();
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save){

	zval *dependency_injector, *service, *meta_data;
	zval *schema, *source, *table = NULL, *connection, *exists;
	zval *disable_events = NULL, *identity_field, *status;
	zval *success = NULL, *post_success;
	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
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
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_3(exists, this_ptr, "_exists", meta_data, connection, table, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(exists)) {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 1 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 2 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), a0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\model"), SL("_disableEvents") TSRMLS_CC);
	
	PHALCON_INIT_VAR(identity_field);
	PHALCON_CALL_METHOD_PARAMS_1(identity_field, meta_data, "getidentityfield", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_5(status, this_ptr, "_presave", dependency_injector, meta_data, disable_events, exists, identity_field, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	if (PHALCON_IS_TRUE(exists)) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "_dolowupdate", meta_data, connection, table, PH_NO_CHECK);
	} else {
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD_PARAMS_4(success, this_ptr, "_dolowinsert", meta_data, connection, table, identity_field, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(post_success);
	PHALCON_CALL_METHOD_PARAMS_3(post_success, this_ptr, "_postsave", disable_events, success, exists, PH_NO_CHECK);
	
	RETURN_CCTOR(post_success);
}

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical'
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->create();
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, create){

	zval *dependency_injector, *service, *meta_data;
	zval *connection, *exists, *field, *type, *message;
	zval *model_message, *messages, *success;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection, PH_NO_CHECK);
	if (zend_is_true(exists)) {
		PHALCON_INIT_VAR(field);
		
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InvalidCreateAttempt", 1);
		
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Record cannot be created because it already exists", 1);
		
		PHALCON_INIT_VAR(model_message);
		object_init_ex(model_message, phalcon_mvc_model_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, type, PH_CHECK);
		
		PHALCON_INIT_VAR(messages);
		array_init(messages);
		phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save", PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Updates a model instance. If the instance doesn't exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->save();
 *</code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, update){

	zval *force_exists, *dependency_injector;
	zval *service, *meta_data, *connection, *exists;
	zval *field, *type, *message, *model_message, *messages;
	zval *success;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(force_exists);
	phalcon_read_property(&force_exists, this_ptr, SL("_forceExists"), PH_NOISY_CC);
	if (!zend_is_true(force_exists)) {
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
			return;
		}
		
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "modelsMetadata", 1);
		
		PHALCON_INIT_VAR(meta_data);
		PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection, PH_NO_CHECK);
		if (!zend_is_true(exists)) {
			PHALCON_INIT_VAR(field);
			
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "InvalidUpdateAttempt", 1);
			
			PHALCON_INIT_VAR(message);
			ZVAL_STRING(message, "Record cannot be updated because it does not exists", 1);
			
			PHALCON_INIT_VAR(model_message);
			object_init_ex(model_message, phalcon_mvc_model_message_ce);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, type, PH_CHECK);
			
			PHALCON_INIT_VAR(messages);
			array_init(messages);
			phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save", PH_NO_CHECK);
	
	RETURN_CCTOR(success);
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *$robot = Robots::findFirst("id=100");
 *$robot->delete();
 *
 *foreach(Robots::find("type = 'mechanical'") as $robot){
 *   $robot->delete();
 *}
 * </code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, delete){

	zval *dependency_injector, *service, *meta_data;
	zval *connection, *disable_events = NULL, *check_foreign_keys;
	zval *values, *bind_types, *conditions = NULL, *primary_keys;
	zval *bind_data_types, *primary_key = NULL, *exception_message = NULL;
	zval *value = NULL, *primary_condition = NULL, *bind_type = NULL;
	zval *event_name = NULL, *status, *schema, *source, *table = NULL;
	zval *success;
	zval *a0 = NULL;
	zval *r0 = NULL;
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
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection", PH_NO_CHECK);
	phalcon_update_property_long(this_ptr, SL("_operationMade"), 3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), a0 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(disable_events);
	phalcon_read_static_property(&disable_events, SL("phalcon\\mvc\\model"), SL("_disableEvents") TSRMLS_CC);
	
	PHALCON_INIT_VAR(check_foreign_keys);
	PHALCON_CALL_METHOD_PARAMS_2(check_foreign_keys, this_ptr, "_checkforeignkeysreverse", dependency_injector, disable_events, PH_NO_CHECK);
	if (PHALCON_IS_FALSE(check_foreign_keys)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_INIT_VAR(primary_keys);
	PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr, PH_NO_CHECK);
	
	if (!phalcon_valid_foreach(primary_keys TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(primary_keys);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(primary_key);
		
		eval_int = phalcon_array_isset(bind_data_types, primary_key);
		if (!eval_int) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", primary_key, "\" isn't part of the table columns");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
		eval_int = phalcon_isset_property_zval(this_ptr, primary_key TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, primary_key, PH_NOISY_CC);
			phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(primary_condition);
			PHALCON_CONCAT_VS(primary_condition, primary_key, " = ?");
			phalcon_array_append(&conditions, primary_condition, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, primary_key, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot delete the record because one of the primary key attributes isn't set");
			return;
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(r0);
	phalcon_fast_join_str(r0, SL(" AND "), conditions TSRMLS_CC);
	PHALCON_CPY_WRT(conditions, r0);
	if (!zend_is_true(disable_events)) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeDelete", 1);
		
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "_calleventcancel", event_name, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
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
	PHALCON_CALL_METHOD_PARAMS_4(success, connection, "delete", table, conditions, values, bind_types, PH_NO_CHECK);
	if (zend_is_true(success)) {
		if (!zend_is_true(disable_events)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_callevent", event_name, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(success);
}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade){

	zval *operation_made;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(operation_made);
	phalcon_read_property(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY_CC);
	
	RETURN_CCTOR(operation_made);
}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute){

	zval *attribute, *attribute_value;
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
 * <code>
 * $robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute){

	zval *attribute, *value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes){

	zval *attributes, *dependency_injector, *service;
	zval *meta_data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	if (Z_TYPE_P(meta_data) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(meta_data, "setautomaticattributes", attributes, PH_NO_CHECK);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne){

	zval *fields, *reference_model, *referenced_fields;
	zval *options, *dependency_injector, *service;
	zval *manager;

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
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
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
 *<code>
 *
 *class RobotsParts extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->belongsTo('robots_id', 'Robots', 'id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *dependency_injector, *service;
	zval *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
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
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *dependency_injector, *service;
	zval *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addhasmany", this_ptr, fields, reference_model, referenced_fields, options, PH_NO_CHECK);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns related records based on defined relations
 *
 * @param string $modelName
 * @param array $arguments
 * @return Phalcon\Mvc\Model\Resultset\Simple
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated){

	zval *model_name, *arguments = NULL, *dependency_injector;
	zval *service, *manager, *class_name, *exists = NULL, *manager_method = NULL;
	zval *query_method = NULL, *exception_message, *call_object;
	zval *model_args, *result;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &model_name, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_NVAR(arguments);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, this_ptr TSRMLS_CC);
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existsbelongsto", class_name, model_name, PH_NO_CHECK);
	if (zend_is_true(exists)) {
		PHALCON_INIT_VAR(manager_method);
		ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
		
		PHALCON_INIT_VAR(query_method);
		ZVAL_STRING(query_method, "findFirst", 1);
	} else {
		PHALCON_INIT_NVAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasmany", class_name, model_name, PH_NO_CHECK);
		if (zend_is_true(exists)) {
			PHALCON_INIT_NVAR(manager_method);
			ZVAL_STRING(manager_method, "getHasManyRecords", 1);
			
			PHALCON_INIT_NVAR(query_method);
			ZVAL_STRING(query_method, "find", 1);
		} else {
			PHALCON_INIT_NVAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasone", class_name, model_name, PH_NO_CHECK);
			if (zend_is_true(exists)) {
				PHALCON_INIT_NVAR(manager_method);
				ZVAL_STRING(manager_method, "getHasOneRecords", 1);
				
				PHALCON_INIT_NVAR(query_method);
				ZVAL_STRING(query_method, "findFirst", 1);
			} else {
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "There is not defined relations between '", class_name, "\" and \"", model_name, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		}
	}
	
	PHALCON_INIT_VAR(call_object);
	array_init(call_object);
	phalcon_array_append(&call_object, manager, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&call_object, manager_method, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(model_args);
	array_init(model_args);
	phalcon_array_append(&model_args, query_method, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&model_args, class_name, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&model_args, model_name, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&model_args, this_ptr, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&model_args, arguments, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_FUNC_PARAMS_2(result, "call_user_func_array", call_object, model_args);
	
	RETURN_CCTOR(result);
}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param string $modelName
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __getRelatedRecords){

	zval *model_name, *method, *arguments, *dependency_injector;
	zval *service, *manager, *zero, *three, *manager_method = NULL;
	zval *action = NULL, *requested_relation = NULL, *exists = NULL, *query_method = NULL;
	zval *five, *extra_args = NULL, *call_args, *call_object;
	zval *result;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model_name, &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "There is not models manager related to this model");
		return;
	}
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(three);
	ZVAL_LONG(three, 3);
	
	PHALCON_INIT_VAR(manager_method);
	ZVAL_BOOL(manager_method, 0);
	
	PHALCON_INIT_VAR(action);
	PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, zero, three);
	if (PHALCON_COMPARE_STRING(action, "get")) {
		PHALCON_INIT_VAR(requested_relation);
		PHALCON_CALL_FUNC_PARAMS_2(requested_relation, "substr", method, three);
		
		PHALCON_INIT_VAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existsbelongsto", model_name, requested_relation, PH_NO_CHECK);
		if (zend_is_true(exists)) {
			ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			
			PHALCON_INIT_VAR(query_method);
			ZVAL_STRING(query_method, "findFirst", 1);
		} else {
			PHALCON_INIT_NVAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasmany", model_name, requested_relation, PH_NO_CHECK);
			if (zend_is_true(exists)) {
				PHALCON_INIT_NVAR(manager_method);
				ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				
				PHALCON_INIT_NVAR(query_method);
				ZVAL_STRING(query_method, "find", 1);
			} else {
				PHALCON_INIT_NVAR(exists);
				PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasone", model_name, requested_relation, PH_NO_CHECK);
				if (zend_is_true(exists)) {
					PHALCON_INIT_NVAR(manager_method);
					ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					
					PHALCON_INIT_NVAR(query_method);
					ZVAL_STRING(query_method, "findFirst", 1);
				}
			}
		}
	}
	
	if (PHALCON_IS_FALSE(manager_method)) {
		PHALCON_INIT_VAR(five);
		ZVAL_LONG(five, 5);
		
		PHALCON_INIT_NVAR(action);
		PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, zero, five);
		if (PHALCON_COMPARE_STRING(action, "count")) {
			PHALCON_INIT_NVAR(query_method);
			ZVAL_STRING(query_method, "count", 1);
			
			PHALCON_INIT_NVAR(requested_relation);
			PHALCON_CALL_FUNC_PARAMS_2(requested_relation, "substr", method, five);
			
			PHALCON_INIT_NVAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existsbelongsto", model_name, requested_relation, PH_NO_CHECK);
			if (zend_is_true(exists)) {
				PHALCON_INIT_NVAR(manager_method);
				ZVAL_STRING(manager_method, "getBelongsToRecords", 1);
			} else {
				PHALCON_INIT_NVAR(exists);
				PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasmany", model_name, requested_relation, PH_NO_CHECK);
				if (zend_is_true(exists)) {
					PHALCON_INIT_NVAR(manager_method);
					ZVAL_STRING(manager_method, "getHasManyRecords", 1);
				} else {
					PHALCON_INIT_NVAR(exists);
					PHALCON_CALL_METHOD_PARAMS_2(exists, manager, "existshasone", model_name, requested_relation, PH_NO_CHECK);
					if (zend_is_true(exists)) {
						PHALCON_INIT_NVAR(manager_method);
						ZVAL_STRING(manager_method, "getHasOneRecords", 1);
					}
				}
			}
		}
	}
	
	if (PHALCON_IS_NOT_FALSE(manager_method)) {
		eval_int = phalcon_array_isset_long(arguments, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(extra_args);
			phalcon_array_fetch_long(&extra_args, arguments, 0, PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(extra_args);
		}
		
		PHALCON_INIT_VAR(call_args);
		array_init(call_args);
		phalcon_array_append(&call_args, query_method, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, model_name, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, requested_relation, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, this_ptr, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, extra_args, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(call_object);
		array_init(call_object);
		phalcon_array_append(&call_object, manager, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_object, manager_method, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_FUNC_PARAMS_2(result, "call_user_func_array", call_object, call_args);
		
		RETURN_CCTOR(result);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Handles methods when a method does not exist
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call){

	zval *method, *arguments = NULL, *model_name, *records;
	zval *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_NVAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr TSRMLS_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_3(records, this_ptr, "__getrelatedrecords", model_name, method, arguments, PH_NO_CHECK);
	if (Z_TYPE_P(records) != IS_NULL) {
		
		RETURN_CCTOR(records);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVSVS(exception_message, "The method \"", method, "\" doesn't exist on model \"", model_name, "\"");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Serializes the object ignoring connections or static properties
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize){

	zval *dependency_injector, *service, *meta_data;
	zval *attributes, *null_value, *data, *attribute = NULL;
	zval *value = NULL, *serialize;
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
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(attribute);
		
		eval_int = phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC);
		if (eval_int) {
			PHALCON_INIT_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute, PH_NOISY_CC);
			phalcon_array_update_zval(&data, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&data, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(serialize);
	PHALCON_CALL_FUNC_PARAMS_1(serialize, "serialize", data);
	
	RETURN_CCTOR(serialize);
}

/**
 * Unserializes the object from a serialized string
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize){

	zval *data, *attributes, *value = NULL, *key = NULL;
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

	if (Z_TYPE_P(data) == IS_STRING) {
		PHALCON_INIT_VAR(attributes);
		PHALCON_CALL_FUNC_PARAMS_1(attributes, "unserialize", data);
		if (Z_TYPE_P(attributes) == IS_ARRAY) { 
			
			if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(attributes);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
					goto ph_cycle_end_0;
				}
				
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(value);
				
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
				
			ph_cycle_end_0:
			
			PHALCON_MM_RESTORE();
			RETURN_NULL();
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
	return;
}

