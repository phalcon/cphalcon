
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 *```php
 * $phql = "SELECT c.price*0.16 AS taxes, c.* FROM Cars AS c JOIN Brands AS b
 *          WHERE b.name = :name: ORDER BY c.name";
 *
 * $result = $manager->executeQuery(
 *     $phql,
 *     [
 *         "name" => "Lamborghini",
 *     ]
 * );
 *
 * foreach ($result as $row) {
 *     echo "Name: ",  $row->cars->name, "\n";
 *     echo "Price: ", $row->cars->price, "\n";
 *     echo "Taxes: ", $row->taxes, "\n";
 * }
 *
 * // with transaction
 * use Phalcon\Mvc\Model\Query;
 * use Phalcon\Mvc\Model\Transaction;
 *
 * // $di needs to have the service "db" registered for this to work
 * $di = Phalcon\Di\FactoryDefault::getDefault();
 *
 * $phql = 'SELECT * FROM Invoices';
 *
 * $myTransaction = new Transaction($di);
 * $myTransaction->begin();
 *
 * $newInvoice = new Invoices();
 * $newInvoice->setTransaction($myTransaction);
 * $newInvoice->inv_status_flag = 1;
 * $newInvoice->inv_title = "Test Invoice";
 * $newInvoice->inv_total = 100;
 * $newInvoice->save();
 *
 * $queryWithTransaction = new Query($phql, $di);
 * $queryWithTransaction->setTransaction($myTransaction);
 *
 * $resultWithEntries = $queryWithTransaction->execute();
 *
 * $queryWithOutTransaction = new Query($phql, $di);
 * $resultWithOutEntries = $queryWithTransaction->execute();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, phalcon, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);

	/**
	 * @var array
	 * TODO: Add default value, instead of null, also remove type check
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("ast"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("bindParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("bindTypes"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("cache"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("cacheOptions"), ZEND_ACC_PROTECTED);
	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("enableImplicitJoins"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("intermediate"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("internalPhqlCache"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var \Phalcon\Mvc\Model\ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("manager"), ZEND_ACC_PROTECTED);
	/**
	 * @var \Phalcon\Mvc\Model\MetaDataInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("metaData"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("models"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("modelsInstances"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_query_ce, SL("nestingLevel"), -1, ZEND_ACC_PROTECTED);
	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("phql"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_model_query_ce, SL("resultsetRowClass"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_query_ce, SL("sharedLock"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("sqlAliases"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("sqlAliasesModels"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("sqlAliasesModelsInstances"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("sqlColumnAliases"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("sqlModelsAliases"), ZEND_ACC_PROTECTED);
	/**
	 * TransactionInterface so that the query can wrap a transaction
	 * around batch updates and intermediate selects within the transaction.
	 * however if a model got a transaction set inside it will use the local
	 * transaction instead of this one
	 *
	 * @var TransactionInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("transaction"), ZEND_ACC_PROTECTED);
	/**
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_query_ce, SL("uniqueRow"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_model_query_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Query;
	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_DELETE"), 303);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_INSERT"), 306);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_SELECT"), 309);

	/**
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_mvc_model_query_ce, SL("TYPE_UPDATE"), 300);

	zend_class_implements(phalcon_mvc_model_query_ce, 1, phalcon_mvc_model_queryinterface_ce);
	zend_class_implements(phalcon_mvc_model_query_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string|null phql
 * @param DiInterface|null container
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval phql_zv, *container = NULL, container_sub, *options_param = NULL, __$true, __$false, __$null, enableImplicitJoins, _2, _3, _0$$5, _1$$5;
	zend_string *phql = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql_zv);
	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&enableImplicitJoins);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("enableImplicitJoins", 19, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("bindTypes", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(phql)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		container = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		options_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!phql) {
		ZEPHIR_INIT_VAR(&phql_zv);
	} else {
		zephir_memory_observe(&phql_zv);
	ZVAL_STR_COPY(&phql_zv, phql);
	}
	if (!container) {
		container = &container_sub;
		container = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1054, &phql_zv);
	if (Z_TYPE_P(container) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, container);
		zephir_check_call_status();
	}
	zephir_memory_observe(&enableImplicitJoins);
	if (zephir_array_isset_string_fetch(&enableImplicitJoins, &options, SL("enable_implicit_joins"), 0)) {
		if (ZEPHIR_IS_TRUE(&enableImplicitJoins)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1055, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1055, &__$false);
		}
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "orm.enable_implicit_joins");
		ZEPHIR_CALL_CE_STATIC(&_0$$5, phalcon_support_settings_ce, "get", NULL, 0, &_1$$5);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1055, &_0$$5);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1056, &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1057, &_3);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the cache parameters of the query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, cache)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *cacheOptions_param = NULL;
	zval cacheOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cacheOptions);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("cacheOptions", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(cacheOptions, cacheOptions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &cacheOptions_param);
	zephir_get_arrval(&cacheOptions, cacheOptions_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1058, &cacheOptions);
	RETURN_THIS();
}

/**
 * Destroys the internal PHQL cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, clean)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_mvc_model_query_ce, ZEND_STRL("internalPhqlCache"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes a parsed PHQL statement
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams_param = NULL, *bindTypes_param = NULL, adapter, cacheLifetime, cacheOptions, cacheService, defaultBindParams, defaultBindTypes, intermediate, mergedParams, mergedTypes, preparedResult, type, uniqueRow, cache, key, lifetime, result, _0, _1$$4, _2$$5, _3$$3, _4$$3, _5$$3, _7$$3, _6$$7, _8$$11, _9$$10, _10$$20, _11$$22;
	zval bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&cacheLifetime);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&defaultBindParams);
	ZVAL_UNDEF(&defaultBindTypes);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
	ZVAL_UNDEF(&preparedResult);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&uniqueRow);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$20);
	ZVAL_UNDEF(&_11$$22);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uniqueRow", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("cacheOptions", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("bindTypes", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("type", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &bindParams_param, &bindTypes_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	ZEPHIR_INIT_VAR(&cache);
	ZVAL_NULL(&cache);
	ZEPHIR_INIT_VAR(&key);
	ZVAL_STRING(&key, "");
	ZEPHIR_INIT_VAR(&lifetime);
	ZVAL_NULL(&lifetime);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_BOOL(&result, 0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1059, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueRow, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1058, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cacheOptions, &_0);
	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (UNEXPECTED(Z_TYPE_P(&cacheOptions) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_model_query_exceptions_invalidcachingoptions_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model/Query.zep", 348);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&key);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0)))) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_missingcachekey_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 355);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0))) {
			ZEPHIR_INIT_NVAR(&cacheService);
			ZVAL_STRING(&cacheService, "modelsCache");
		}
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_2, 1060, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&cache, &_3$$3, "getshared", NULL, 0, &cacheService);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Phalcon\\Cache\\CacheInterface");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_a", NULL, 203, &cache, &_4$$3);
		zephir_check_call_status();
		if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3))) {
			ZEPHIR_INIT_VAR(&_6$$7);
			object_init_ex(&_6$$7, phalcon_mvc_model_query_exceptions_invalidquerycacheservice_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model/Query.zep", 365);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&adapter, &cache, "getadapter", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&cacheLifetime, &adapter, "getlifetime", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&lifetime);
		if (!(zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0))) {
			ZEPHIR_CPY_WRT(&lifetime, &cacheLifetime);
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, 0);
		ZEPHIR_CALL_METHOD(&_7$$3, &cache, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$3)) {
			ZEPHIR_CALL_METHOD(&result, &cache, "get", NULL, 0, &key);
			zephir_check_call_status();
		}
		if (!(ZEPHIR_IS_EMPTY(&result))) {
			if (UNEXPECTED(Z_TYPE_P(&result) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_8$$11);
				object_init_ex(&_8$$11, phalcon_mvc_model_query_exceptions_invalidcachedresultset_ce);
				ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$11, "phalcon/Mvc/Model/Query.zep", 386);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_9$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &result, "setisfresh", NULL, 0, &_9$$10);
			zephir_check_call_status();
			if (zephir_is_true(&uniqueRow)) {
				ZEPHIR_CALL_METHOD(&preparedResult, &result, "getfirst", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedResult, &result);
			}
			RETURN_CCTOR(&preparedResult);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1061, &cache);
	}
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&defaultBindParams);
	zephir_read_property_cached(&defaultBindParams, this_ptr, _zephir_prop_4, 1056, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_add_function(&mergedParams, &defaultBindParams, &bindParams);
	zephir_memory_observe(&defaultBindTypes);
	zephir_read_property_cached(&defaultBindTypes, this_ptr, _zephir_prop_5, 1057, PH_NOISY_CC);
	if (Z_TYPE_P(&defaultBindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&mergedTypes);
		zephir_add_function(&mergedTypes, &defaultBindTypes, &bindTypes);
	} else {
		ZEPHIR_CPY_WRT(&mergedTypes, &bindTypes);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 1062, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&type, &_0);
	if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_3; }
	goto zephir_switch_0_clause_4;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeselect", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeinsert", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeupdate", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executedelete", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_10$$20);
		object_init_ex(&_10$$20, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$20, "__construct", NULL, 0, &type);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$20, "phalcon/Mvc/Model/Query.zep", 469);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_INIT_VAR(&_11$$22);
			object_init_ex(&_11$$22, phalcon_mvc_model_query_exceptions_resultsetnoncacheable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$22, "phalcon/Mvc/Model/Query.zep", 480);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &cache, "set", NULL, 0, &key, &result, &lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(&uniqueRow)) {
		ZEPHIR_CALL_METHOD(&preparedResult, &result, "getfirst", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedResult, &result);
	}
	RETURN_CCTOR(&preparedResult);
}

/**
 * Returns default bind params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams)
{

	RETURN_MEMBER_TYPED(getThis(), "bindParams", IS_ARRAY);
}

/**
 * Returns default bind types
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes)
{

	RETURN_MEMBER_TYPED(getThis(), "bindTypes", IS_ARRAY);
}

/**
 * Returns the current cache backend instance
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCache)
{

	RETURN_MEMBER(getThis(), "cache");
}

/**
 * Returns the current cache options
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "cacheOptions", IS_ARRAY);
}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Returns the intermediate representation of the PHQL statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate)
{

	RETURN_MEMBER_TYPED(getThis(), "intermediate", IS_ARRAY);
}

/**
 * Executes the query returning the first result
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams_param = NULL, *bindTypes_param = NULL, _0, _1;
	zval bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uniqueRow", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &bindParams_param, &bindTypes_param);
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1059, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &bindParams, &bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getfirst", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns an associative array with the SQL to be generated by the internal PHQL,
 * and arrays with bound parameters and their types (only works in SELECT statements).
 *
 *```php
 * [
 *     'sql' => 'SELECT * FROM co_invoices WHERE inv_cst_id = :cst_id',
 *     'bind' => ['cst_id' => 123],
 *     'bindTypes => ['cst_id' => 1] // 1 corresponds to int
 * ]
 *```
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSql)
{
	zval intermediate, _0, _4, _1$$3, _2$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("bindTypes", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1062, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 309)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1056, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_2, 1057, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executeselect", NULL, 0, &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_mvc_model_query_exceptions_multiplesqlstatementsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "phalcon/Mvc/Model/Query.zep", 592);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * @return TransactionInterface|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getTransaction)
{

	RETURN_MEMBER(getThis(), "transaction");
}

/**
 * Gets the type of PHQL statement executed
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_LONG);
}

/**
 * Returns the class that will be used to hydrate rows that are not mapped
 * to a model (custom columns/joins). An empty string means the default
 * Phalcon\Mvc\Model\Row is used.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getResultsetRowClass)
{

	RETURN_MEMBER_TYPED(getThis(), "resultsetRowClass", IS_STRING);
}

/**
 * Check if the query is programmed to get only the first row in the
 * resultset
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow)
{

	RETURN_MEMBER(getThis(), "uniqueRow");
}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang
 * generating another intermediate representation that could be executed by
 * Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse)
{
	zval intermediate, phql, ast, irPhql, uniqueId, type, _0, _1$$5, _2$$7, _3$$13, _4$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&phql);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&uniqueId);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$13);
	ZVAL_UNDEF(&_4$$14);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("intermediate", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("type", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("ast", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1063, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&intermediate, &_0);
	if (Z_TYPE_P(&intermediate) == IS_ARRAY) {
		RETURN_CCTOR(&intermediate);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1054, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&phql, &_0);
	ZEPHIR_CALL_CE_STATIC(&ast, phalcon_mvc_model_query_lang_ce, "parsephql", NULL, 0, &phql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&irPhql);
	ZVAL_NULL(&irPhql);
	ZEPHIR_INIT_VAR(&uniqueId);
	ZVAL_NULL(&uniqueId);
	if (Z_TYPE_P(&ast) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&uniqueId);
		if (zephir_array_isset_string_fetch(&uniqueId, &ast, SL("id"), 0)) {
			ZEPHIR_OBS_NVAR(&irPhql);
			zephir_read_static_property_ce(&_1$$5, phalcon_mvc_model_query_ce, SL("internalPhqlCache"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&irPhql, &_1$$5, &uniqueId, 0)) {
				if (Z_TYPE_P(&irPhql) == IS_ARRAY) {
					zephir_array_fetch_string(&_2$$7, &ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 667);
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1062, &_2$$7);
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "refreshschemasinintermediate", NULL, 0, &irPhql);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
		zephir_memory_observe(&type);
		if (zephir_array_isset_string_fetch(&type, &ast, SL("type"), 0)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1064, &ast);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1062, &type);
			if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_clause_4;
			zephir_switch_0_clause_0: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareselect", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareinsert", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareupdate", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "preparedelete", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_VAR(&_3$$13);
				object_init_ex(&_3$$13, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$13, "__construct", NULL, 0, &type, &phql);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$13, "phalcon/Mvc/Model/Query.zep", 707);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

		}
	}
	if (UNEXPECTED(Z_TYPE_P(&irPhql) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_4$$14);
		object_init_ex(&_4$$14, phalcon_mvc_model_query_exceptions_corruptedast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$14, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$14, "phalcon/Mvc/Model/Query.zep", 713);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &irPhql, SL("z"), 1, &uniqueId);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1063, &irPhql);
	RETURN_CCTOR(&irPhql);
}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *bindParams_param = NULL, *merge_param = NULL, currentBindParams, _0$$3;
	zval bindParams;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&currentBindParams);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindParams", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (merge) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property_cached(&currentBindParams, this_ptr, _zephir_prop_0, 1056, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1056, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1056, &bindParams);
	}
	RETURN_THIS();
}

/**
 * Set default bind parameters
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool merge;
	zval *bindTypes_param = NULL, *merge_param = NULL, currentBindTypes, _0$$4;
	zval bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&currentBindTypes);
	ZVAL_UNDEF(&_0$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindTypes", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (UNEXPECTED(merge)) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property_cached(&currentBindTypes, this_ptr, _zephir_prop_0, 1057, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1057, &_0$$4);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1057, &bindTypes);
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1057, &bindTypes);
	}
	RETURN_THIS();
}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, manager, metaData, _0, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("metaData", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &container);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "modelsManager");
	ZEPHIR_CALL_METHOD(&manager, container, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_invalidinjectedmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 777);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, container, "getshared", NULL, 0, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_invalidinjectedmetadata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 783);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1065, &manager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1066, &metaData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1060, container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Allows to set the IR to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *intermediate_param = NULL;
	zval intermediate;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("intermediate", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &intermediate_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1063, &intermediate);
	RETURN_THIS();
}

/**
 * Set SHARED LOCK clause
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setSharedLock)
{
	zval *sharedLock_param = NULL, __$true, __$false;
	zend_bool sharedLock;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("sharedLock", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(sharedLock)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(0, 1, &sharedLock_param);
	if (!sharedLock_param) {
		sharedLock = 0;
	} else {
		}
	if (sharedLock) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1067, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1067, &__$false);
	}
	RETURN_THISW();
}

/**
 * allows to wrap a transaction around all queries
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setTransaction)
{
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &transaction);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1068, transaction);
	RETURN_THISW();
}

/**
 * Sets the type of PHQL statement to be executed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setType)
{
	zval *type_param = NULL, _0;
	zend_long type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("type", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &type_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1062, &_0);
	RETURN_THISW();
}

/**
 * Sets the class used to hydrate rows that are not mapped to a model
 * (custom columns/joins). The class must be a subclass of
 * Phalcon\Mvc\Model\Row.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setResultsetRowClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval resultsetRowClass_zv, _0$$3, _1, _2, _3$$4;
	zend_string *resultsetRowClass = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultsetRowClass_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resultsetRowClass", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(resultsetRowClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&resultsetRowClass_zv);
	ZVAL_STR_COPY(&resultsetRowClass_zv, resultsetRowClass);
	if (UNEXPECTED(!(zephir_class_exists(&resultsetRowClass_zv, 1)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_resultsetrowclassnotfound_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &resultsetRowClass_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 840);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\Row");
	ZEPHIR_CALL_FUNCTION(&_2, "is_subclass_of", NULL, 150, &resultsetRowClass_zv, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_mvc_model_query_exceptions_invalidresultsetrowclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &resultsetRowClass_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model/Query.zep", 844);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1069, &resultsetRowClass_zv);
	RETURN_THIS();
}

/**
 * Tells to the query if only the first row in the resultset must be
 * returned
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow)
{
	zval *uniqueRow_param = NULL, __$true, __$false;
	zend_bool uniqueRow;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uniqueRow", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(uniqueRow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &uniqueRow_param);
	if (uniqueRow) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1059, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1059, &__$false);
	}
	RETURN_THISW();
}

/**
 * Executes the DELETE intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, records, connection, record, exception, _1, _4, _12, _0$$3, _2$$4, _3$$5, _6$$7, _8$$8, _10$$6;
	zval intermediate, bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams_param, &bindTypes_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	zephir_memory_observe(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 871);
	if (UNEXPECTED(zephir_array_isset_value_long(&models, 1))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_deletemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 874);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 877);
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1070, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_1, &modelName, 0))) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_2$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getrelatedrecords", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_3$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_3$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_4, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&record, &records, "current", &_5, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_6$$7, &record, "delete", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_6$$7))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_7, 0);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_8$$8, 0);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_8$$8, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &records, "next", &_9, 0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_10$$6);
			ZVAL_OBJ(&_10$$6, EG(exception));
			Z_ADDREF_P(&_10$$6);
			if (zephir_is_instance_of(&_10$$6, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_10$$6);
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_11, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 936);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_12, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the INSERT intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeInsert)
{
	zend_string *_9;
	zend_ulong _8;
	zend_bool automaticFields = 0, _25, _21$$8, _35$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL, *_17 = NULL, *_19 = NULL, *_20 = NULL, *_23 = NULL, *_27 = NULL, *_29 = NULL, *_34 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, attributeName, attributes, connection, dialect, exprValue, fieldName, fields, insertModel, insertValue, insertValues, manager, metaData, model, modelName, number, value, values, wildcard, columnMap, _0, _1, *_5, _6, *_7, _24, _37, _2$$4, _3$$4, _4$$7, _10$$8, _12$$11, _14$$11, _15$$11, _16$$12, _18$$13, _22$$15, _26$$17, _28$$20, _30$$20, _31$$20, _32$$21, _33$$22, _36$$24;
	zval intermediate, bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&insertModel);
	ZVAL_UNDEF(&insertValue);
	ZVAL_UNDEF(&insertValues);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_36$$24);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("metaData", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams_param, &bindTypes_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	ZEPHIR_INIT_VAR(&columnMap);
	ZVAL_NULL(&columnMap);
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &intermediate, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 964);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1070, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0))) {
		ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_2, 1066, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_1);
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", NULL, 0, &model);
	zephir_check_call_status();
	automaticFields = 0;
	zephir_memory_observe(&fields);
	if (!(zephir_array_isset_string_fetch(&fields, &intermediate, SL("fields"), 0))) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(&fields, &attributes);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_2$$4, phalcon_support_settings_ce, "get", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_2$$4)) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
	}
	zephir_memory_observe(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 999);
	if (UNEXPECTED(zephir_fast_count_int(&fields) != zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, phalcon_mvc_model_query_exceptions_insertcolumncountmismatch_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model/Query.zep", 1006);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	if (Z_TYPE_P(&values) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &values);
		_5 = &_6;
	} else {
		_5 = &values;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Model/Query.zep", 1073);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&number, _9);
			} else {
				ZVAL_LONG(&number, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1016);
			zephir_array_fetch_string(&_10$$8, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1018);
			if (ZEPHIR_IS_LONG(&_10$$8, 260)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_10$$8, 258)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_10$$8, 259)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_10$$8, 322)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&_10$$8, 273)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&_10$$8, 274)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&_10$$8, 277)) { goto zephir_switch_0_clause_6; }
			goto zephir_switch_0_clause_7;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_11, 0, &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				ZVAL_NULL(&insertValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD(&_12$$11, &dialect, "getsqlexpression", &_13, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$11);
				ZVAL_STRING(&_14$$11, ":");
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_14$$11, &_15$$11, &_12$$11);
				ZEPHIR_OBS_NVAR(&insertValue);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0)))) {
					ZEPHIR_INIT_NVAR(&_16$$12);
					object_init_ex(&_16$$12, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", &_17, 0, &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$12, "phalcon/Mvc/Model/Query.zep", 1040);
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_18$$13, &dialect, "getsqlexpression", &_19, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_20, 65, &_18$$13);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1053);
			_21$$8 = automaticFields;
			if (_21$$8) {
				_21$$8 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			}
			if (_21$$8) {
				ZEPHIR_OBS_NVAR(&attributeName);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0)))) {
					ZEPHIR_INIT_NVAR(&_22$$15);
					object_init_ex(&_22$$15, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
					ZEPHIR_CALL_METHOD(NULL, &_22$$15, "__construct", &_23, 0, &fieldName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$15, "phalcon/Mvc/Model/Query.zep", 1061);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeName, &fieldName);
			}
			zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, _5, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1016);
				zephir_array_fetch_string(&_26$$17, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1018);
				if (ZEPHIR_IS_LONG(&_26$$17, 260)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_26$$17, 258)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_26$$17, 259)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_26$$17, 322)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_26$$17, 273)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_26$$17, 274)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_26$$17, 277)) { goto zephir_switch_1_clause_6; }
				goto zephir_switch_1_clause_7;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_27, 0, &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					ZVAL_NULL(&insertValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD(&_28$$20, &dialect, "getsqlexpression", &_29, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_30$$20);
					ZVAL_STRING(&_30$$20, ":");
					ZEPHIR_INIT_NVAR(&_31$$20);
					ZVAL_STRING(&_31$$20, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_30$$20, &_31$$20, &_28$$20);
					ZEPHIR_OBS_NVAR(&insertValue);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0)))) {
						ZEPHIR_INIT_NVAR(&_32$$21);
						object_init_ex(&_32$$21, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_32$$21, "__construct", &_17, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_32$$21, "phalcon/Mvc/Model/Query.zep", 1040);
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_33$$22, &dialect, "getsqlexpression", &_34, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_20, 65, &_33$$22);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1053);
				_35$$17 = automaticFields;
				if (_35$$17) {
					_35$$17 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				}
				if (_35$$17) {
					ZEPHIR_OBS_NVAR(&attributeName);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0)))) {
						ZEPHIR_INIT_NVAR(&_36$$24);
						object_init_ex(&_36$$24, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
						ZEPHIR_CALL_METHOD(NULL, &_36$$24, "__construct", &_23, 0, &fieldName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_36$$24, "phalcon/Mvc/Model/Query.zep", 1061);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &fieldName);
				}
				zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&insertModel, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &insertModel, "assign", NULL, 0, &insertValues);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_37, &insertModel, "create", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_37, &insertModel);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the SELECT intermediate representation producing a
 * Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeSelect)
{
	zval _121$$86, _136$$87;
	zend_string *_35, *_97, *_104, *_114, *_165$$103;
	zend_ulong _34, _96, _103, _113, _164$$103;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_9 = NULL, *_12 = NULL, *_16 = NULL, *_25 = NULL, *_38 = NULL, *_39 = NULL, *_41 = NULL, *_43 = NULL, *_53 = NULL, *_69 = NULL, *_70 = NULL, *_73 = NULL, *_83 = NULL, *_128 = NULL, *_132 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isKeepingSnapshots = 0, isSimpleStd, _14, _28, _66, _100, _107, _134, _6$$3, _17$$9, _64$$32, _49$$35, _60$$41, _94$$50, _79$$53, _90$$59, _115$$84, _158$$100, _169$$103, _173$$91;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *simulate_param = NULL, __$true, __$null, aliasCopy, attribute, attributes, bindCounts, cache, column, columnAlias, columnMap, columns, columns1, connectionTypes, dialect, instance, manager, metaData, modelName, models, processed, processedTypes, result, resultData, resultObject, resultsetClassName, selectColumns, simpleColumnMap, sqlAlias, sqlColumn, sqlSelect, typeWildcard, typesColumnMap, value, wildcard, wildcardValue, connection, model, _0, *_1, _2, *_3, _13, *_21, _22, *_23, _27, *_31, _32, *_33, _65, *_95, _99, *_102, _106, rawWildcards, rawValue, placeholder, *_110, _111, *_112, _116, *_117, _118, *_119, _133, _146, _4$$3, _7$$3, _10$$7, _11$$8, _15$$9, _18$$9, _19$$13, _20$$14, _24$$16, _26$$15, _29$$21, _30$$20, _36$$32, _37$$33, _40$$35, _42$$35, *_44$$35, *_45$$35, _48$$35, _52$$35, _47$$38, _51$$39, _54$$40, *_55$$41, _56$$41, *_57$$41, _59$$41, _62$$45, _63$$46, _67$$50, _68$$51, _71$$53, _72$$53, *_74$$53, *_75$$53, _78$$53, _82$$53, _77$$56, _81$$57, _84$$58, *_85$$59, _86$$59, *_87$$59, _89$$59, _92$$63, _93$$64, _98$$71, _101$$75, _105$$77, _108$$80, _109$$83, _120$$86, _122$$86, _123$$86, _124$$86, _125$$86, _126$$86, _127$$86, _129$$86, _130$$86, _131$$86, _135$$87, _137$$87, _138$$87, _139$$87, _140$$87, _141$$87, _142$$87, _143$$87, _144$$87, _145$$87, _147$$92, _148$$93, _149$$95, _150$$95, _172$$95, _151$$100, *_152$$100, _153$$100, *_154$$100, _157$$100, _156$$101, _160$$102, *_161$$103, _162$$103, *_163$$103, _168$$103, _167$$104, _171$$105, _179$$91, _174$$108, _175$$107, _176$$107, _177$$109;
	zval intermediate, bindParams, bindTypes, _46$$38, _50$$39, _58$$42, _61$$43, _76$$56, _80$$57, _88$$60, _91$$61, _155$$101, _159$$102, _166$$104, _170$$105, _178$$107;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_46$$38);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_58$$42);
	ZVAL_UNDEF(&_61$$43);
	ZVAL_UNDEF(&_76$$56);
	ZVAL_UNDEF(&_80$$57);
	ZVAL_UNDEF(&_88$$60);
	ZVAL_UNDEF(&_91$$61);
	ZVAL_UNDEF(&_155$$101);
	ZVAL_UNDEF(&_159$$102);
	ZVAL_UNDEF(&_166$$104);
	ZVAL_UNDEF(&_170$$105);
	ZVAL_UNDEF(&_178$$107);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&aliasCopy);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columns1);
	ZVAL_UNDEF(&connectionTypes);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&processed);
	ZVAL_UNDEF(&processedTypes);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&resultData);
	ZVAL_UNDEF(&resultObject);
	ZVAL_UNDEF(&resultsetClassName);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&simpleColumnMap);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&typeWildcard);
	ZVAL_UNDEF(&typesColumnMap);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&wildcardValue);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_99);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&rawWildcards);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_133);
	ZVAL_UNDEF(&_146);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_37$$33);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_48$$35);
	ZVAL_UNDEF(&_52$$35);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_56$$41);
	ZVAL_UNDEF(&_59$$41);
	ZVAL_UNDEF(&_62$$45);
	ZVAL_UNDEF(&_63$$46);
	ZVAL_UNDEF(&_67$$50);
	ZVAL_UNDEF(&_68$$51);
	ZVAL_UNDEF(&_71$$53);
	ZVAL_UNDEF(&_72$$53);
	ZVAL_UNDEF(&_78$$53);
	ZVAL_UNDEF(&_82$$53);
	ZVAL_UNDEF(&_77$$56);
	ZVAL_UNDEF(&_81$$57);
	ZVAL_UNDEF(&_84$$58);
	ZVAL_UNDEF(&_86$$59);
	ZVAL_UNDEF(&_89$$59);
	ZVAL_UNDEF(&_92$$63);
	ZVAL_UNDEF(&_93$$64);
	ZVAL_UNDEF(&_98$$71);
	ZVAL_UNDEF(&_101$$75);
	ZVAL_UNDEF(&_105$$77);
	ZVAL_UNDEF(&_108$$80);
	ZVAL_UNDEF(&_109$$83);
	ZVAL_UNDEF(&_120$$86);
	ZVAL_UNDEF(&_122$$86);
	ZVAL_UNDEF(&_123$$86);
	ZVAL_UNDEF(&_124$$86);
	ZVAL_UNDEF(&_125$$86);
	ZVAL_UNDEF(&_126$$86);
	ZVAL_UNDEF(&_127$$86);
	ZVAL_UNDEF(&_129$$86);
	ZVAL_UNDEF(&_130$$86);
	ZVAL_UNDEF(&_131$$86);
	ZVAL_UNDEF(&_135$$87);
	ZVAL_UNDEF(&_137$$87);
	ZVAL_UNDEF(&_138$$87);
	ZVAL_UNDEF(&_139$$87);
	ZVAL_UNDEF(&_140$$87);
	ZVAL_UNDEF(&_141$$87);
	ZVAL_UNDEF(&_142$$87);
	ZVAL_UNDEF(&_143$$87);
	ZVAL_UNDEF(&_144$$87);
	ZVAL_UNDEF(&_145$$87);
	ZVAL_UNDEF(&_147$$92);
	ZVAL_UNDEF(&_148$$93);
	ZVAL_UNDEF(&_149$$95);
	ZVAL_UNDEF(&_150$$95);
	ZVAL_UNDEF(&_172$$95);
	ZVAL_UNDEF(&_151$$100);
	ZVAL_UNDEF(&_153$$100);
	ZVAL_UNDEF(&_157$$100);
	ZVAL_UNDEF(&_156$$101);
	ZVAL_UNDEF(&_160$$102);
	ZVAL_UNDEF(&_162$$103);
	ZVAL_UNDEF(&_168$$103);
	ZVAL_UNDEF(&_167$$104);
	ZVAL_UNDEF(&_171$$105);
	ZVAL_UNDEF(&_179$$91);
	ZVAL_UNDEF(&_174$$108);
	ZVAL_UNDEF(&_175$$107);
	ZVAL_UNDEF(&_176$$107);
	ZVAL_UNDEF(&_177$$109);
	ZVAL_UNDEF(&_121$$86);
	ZVAL_UNDEF(&_136$$87);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("metaData", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sharedLock", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("cache", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("resultsetRowClass", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 4)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(simulate)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 1, &intermediate_param, &bindParams_param, &bindTypes_param, &simulate_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	if (!simulate_param) {
		simulate = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	ZEPHIR_INIT_VAR(&model);
	ZVAL_NULL(&model);
	isSimpleStd = 1;
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&connectionTypes);
	array_init(&connectionTypes);
	zephir_memory_observe(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1111);
	if (Z_TYPE_P(&models) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &models);
		_1 = &_2;
	} else {
		_1 = &models;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 1146);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _3);
			ZEPHIR_OBS_NVAR(&model);
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 1070, PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&model, &_4$$3, &modelName, 0))) {
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_5, 0, &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
			}
			_6$$3 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
			if (_6$$3) {
				zephir_array_fetch_string(&_7$$3, &intermediate, SL("forUpdate"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1120);
				_6$$3 = zephir_is_true(&_7$$3);
			}
			if (_6$$3) {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", &_8, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_9, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&connection) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_10$$7, &connection, "gettype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&connectionTypes, &_10$$7, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
					ZEPHIR_INIT_NVAR(&_11$$8);
					object_init_ex(&_11$$8, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
					ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", &_12, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$8, "phalcon/Mvc/Model/Query.zep", 1141);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_13, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&modelName, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&model);
				zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_1, 1070, PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&model, &_15$$9, &modelName, 0))) {
					ZEPHIR_CALL_METHOD(&model, &manager, "load", &_16, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
				}
				_17$$9 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
				if (_17$$9) {
					zephir_array_fetch_string(&_18$$9, &intermediate, SL("forUpdate"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1120);
					_17$$9 = zephir_is_true(&_18$$9);
				}
				if (_17$$9) {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", &_8, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_9, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&connection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_19$$13, &connection, "gettype", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&connectionTypes, &_19$$13, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
						ZEPHIR_INIT_NVAR(&_20$$14);
						object_init_ex(&_20$$14, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$14, "__construct", &_12, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$14, "phalcon/Mvc/Model/Query.zep", 1141);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	zephir_memory_observe(&columns);
	zephir_array_fetch_string(&columns, &intermediate, SL("columns"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1146);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(&columns1, &columns);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_22);
		zephir_string_to_char_array(&_22, &columns);
		_21 = &_22;
	} else {
		_21 = &columns;
	}
	zephir_is_iterable(_21, 0, "phalcon/Mvc/Model/Query.zep", 1174);
	if (Z_TYPE_P(_21) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21), _23)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _23);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_24$$16);
				object_init_ex(&_24$$16, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
				ZEPHIR_CALL_METHOD(NULL, &_24$$16, "__construct", &_25, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_24$$16, "phalcon/Mvc/Model/Query.zep", 1158);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_26$$15, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1161);
			if (ZEPHIR_IS_STRING(&_26$$15, "scalar")) {
				if (!(zephir_array_isset_value_string(&column, SL("balias")))) {
					isComplex = 1;
				}
				haveScalars = 1;
			} else {
				haveObjects = 1;
				numberObjects++;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _21, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _21, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, _21, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, _21, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_29$$21);
					object_init_ex(&_29$$21, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
					ZEPHIR_CALL_METHOD(NULL, &_29$$21, "__construct", &_25, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_29$$21, "phalcon/Mvc/Model/Query.zep", 1158);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_string(&_30$$20, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1161);
				if (ZEPHIR_IS_STRING(&_30$$20, "scalar")) {
					if (!(zephir_array_isset_value_string(&column, SL("balias")))) {
						isComplex = 1;
					}
					haveScalars = 1;
				} else {
					haveObjects = 1;
					numberObjects++;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	if (!(isComplex)) {
		if (haveObjects) {
			if (haveScalars) {
				isComplex = 1;
			} else {
				if (numberObjects == 1) {
					isSimpleStd = 0;
				} else {
					isComplex = 1;
				}
			}
		} else {
			isSimpleStd = 1;
		}
	}
	ZEPHIR_INIT_VAR(&instance);
	ZVAL_NULL(&instance);
	ZEPHIR_INIT_VAR(&selectColumns);
	array_init(&selectColumns);
	ZEPHIR_INIT_VAR(&simpleColumnMap);
	array_init(&simpleColumnMap);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1066, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_32);
		zephir_string_to_char_array(&_32, &columns);
		_31 = &_32;
	} else {
		_31 = &columns;
	}
	zephir_is_iterable(_31, 0, "phalcon/Mvc/Model/Query.zep", 1280);
	if (Z_TYPE_P(_31) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_31), _34, _35, _33)
		{
			ZEPHIR_INIT_NVAR(&aliasCopy);
			if (_35 != NULL) { 
				ZVAL_STR_COPY(&aliasCopy, _35);
			} else {
				ZVAL_LONG(&aliasCopy, _34);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _33);
			ZEPHIR_OBS_NVAR(&sqlColumn);
			zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1197);
			zephir_array_fetch_string(&_36$$32, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1200);
			if (ZEPHIR_IS_STRING(&_36$$32, "object")) {
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1201);
				ZEPHIR_OBS_NVAR(&instance);
				zephir_read_property_cached(&_37$$33, this_ptr, _zephir_prop_1, 1070, PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&instance, &_37$$33, &modelName, 0))) {
					ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_38, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
				}
				ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_39, 0, &instance);
				zephir_check_call_status();
				if (isComplex) {
					ZEPHIR_INIT_NVAR(&_42$$35);
					ZVAL_STRING(&_42$$35, "orm.column_renaming");
					ZEPHIR_CALL_CE_STATIC(&_40$$35, phalcon_support_settings_ce, "get", &_41, 0, &_42$$35);
					zephir_check_call_status();
					if (zephir_is_true(&_40$$35)) {
						ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_43, 0, &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&columnMap);
						ZVAL_NULL(&columnMap);
					}
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_42$$35);
						zephir_string_to_char_array(&_42$$35, &attributes);
						_44$$35 = &_42$$35;
					} else {
						_44$$35 = &attributes;
					}
					zephir_is_iterable(_44$$35, 0, "phalcon/Mvc/Model/Query.zep", 1237);
					if (Z_TYPE_P(_44$$35) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_44$$35), _45$$35)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _45$$35);
							ZEPHIR_INIT_NVAR(&_46$$38);
							zephir_create_array(&_46$$38, 3, 0);
							zephir_array_fast_append(&_46$$38, &attribute);
							zephir_array_fast_append(&_46$$38, &sqlColumn);
							ZEPHIR_INIT_NVAR(&_47$$38);
							ZEPHIR_CONCAT_SVSV(&_47$$38, "_", &sqlColumn, "_", &attribute);
							zephir_array_fast_append(&_46$$38, &_47$$38);
							zephir_array_append(&selectColumns, &_46$$38, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1230);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _44$$35, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$35 = 1;
						while (1) {
							if (_49$$35) {
								_49$$35 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _44$$35, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$35, _44$$35, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _44$$35, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_50$$39);
								zephir_create_array(&_50$$39, 3, 0);
								zephir_array_fast_append(&_50$$39, &attribute);
								zephir_array_fast_append(&_50$$39, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_51$$39);
								ZEPHIR_CONCAT_SVSV(&_51$$39, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_50$$39, &_51$$39);
								zephir_array_append(&selectColumns, &_50$$39, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1230);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
					zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
					zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
					ZEPHIR_CALL_METHOD(&_52$$35, &manager, "iskeepingsnapshots", &_53, 0, &instance);
					zephir_check_call_status();
					isKeepingSnapshots = zephir_get_boolval(&_52$$35);
					if (isKeepingSnapshots) {
						ZEPHIR_INIT_NVAR(&_54$$40);
						ZVAL_BOOL(&_54$$40, isKeepingSnapshots);
						zephir_array_update_multi(&columns1, &_54$$40, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
					}
				} else {
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_56$$41);
						zephir_string_to_char_array(&_56$$41, &attributes);
						_55$$41 = &_56$$41;
					} else {
						_55$$41 = &attributes;
					}
					zephir_is_iterable(_55$$41, 0, "phalcon/Mvc/Model/Query.zep", 1254);
					if (Z_TYPE_P(_55$$41) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_55$$41), _57$$41)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _57$$41);
							ZEPHIR_INIT_NVAR(&_58$$42);
							zephir_create_array(&_58$$42, 2, 0);
							zephir_array_fast_append(&_58$$42, &attribute);
							zephir_array_fast_append(&_58$$42, &sqlColumn);
							zephir_array_append(&selectColumns, &_58$$42, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1252);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _55$$41, "rewind", NULL, 0);
						zephir_check_call_status();
						_60$$41 = 1;
						while (1) {
							if (_60$$41) {
								_60$$41 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _55$$41, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_59$$41, _55$$41, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_59$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _55$$41, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_61$$43);
								zephir_create_array(&_61$$43, 2, 0);
								zephir_array_fast_append(&_61$$43, &attribute);
								zephir_array_fast_append(&_61$$43, &sqlColumn);
								zephir_array_append(&selectColumns, &_61$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1252);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				}
			} else {
				ZEPHIR_INIT_NVAR(&columnAlias);
				if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_62$$45);
					zephir_create_array(&_62$$45, 2, 0);
					zephir_array_fast_append(&_62$$45, &sqlColumn);
					zephir_array_fast_append(&_62$$45, &__$null);
					ZEPHIR_CPY_WRT(&columnAlias, &_62$$45);
				} else {
					ZEPHIR_INIT_NVAR(&_63$$46);
					zephir_create_array(&_63$$46, 3, 0);
					zephir_array_fast_append(&_63$$46, &sqlColumn);
					zephir_array_fast_append(&_63$$46, &__$null);
					zephir_array_fast_append(&_63$$46, &aliasCopy);
					ZEPHIR_CPY_WRT(&columnAlias, &_63$$46);
				}
				zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
			}
			_64$$32 = !isComplex;
			if (_64$$32) {
				_64$$32 = isSimpleStd;
			}
			if (_64$$32) {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _31, "rewind", NULL, 0);
		zephir_check_call_status();
		_66 = 1;
		while (1) {
			if (_66) {
				_66 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _31, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_65, _31, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_65)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&aliasCopy, _31, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, _31, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sqlColumn);
				zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1197);
				zephir_array_fetch_string(&_67$$50, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1200);
				if (ZEPHIR_IS_STRING(&_67$$50, "object")) {
					ZEPHIR_OBS_NVAR(&modelName);
					zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1201);
					ZEPHIR_OBS_NVAR(&instance);
					zephir_read_property_cached(&_68$$51, this_ptr, _zephir_prop_1, 1070, PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset_fetch(&instance, &_68$$51, &modelName, 0))) {
						ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_69, 0, &modelName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
					}
					ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_70, 0, &instance);
					zephir_check_call_status();
					if (isComplex) {
						ZEPHIR_INIT_NVAR(&_72$$53);
						ZVAL_STRING(&_72$$53, "orm.column_renaming");
						ZEPHIR_CALL_CE_STATIC(&_71$$53, phalcon_support_settings_ce, "get", &_41, 0, &_72$$53);
						zephir_check_call_status();
						if (zephir_is_true(&_71$$53)) {
							ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_73, 0, &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&columnMap);
							ZVAL_NULL(&columnMap);
						}
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_72$$53);
							zephir_string_to_char_array(&_72$$53, &attributes);
							_74$$53 = &_72$$53;
						} else {
							_74$$53 = &attributes;
						}
						zephir_is_iterable(_74$$53, 0, "phalcon/Mvc/Model/Query.zep", 1237);
						if (Z_TYPE_P(_74$$53) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_74$$53), _75$$53)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _75$$53);
								ZEPHIR_INIT_NVAR(&_76$$56);
								zephir_create_array(&_76$$56, 3, 0);
								zephir_array_fast_append(&_76$$56, &attribute);
								zephir_array_fast_append(&_76$$56, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_77$$56);
								ZEPHIR_CONCAT_SVSV(&_77$$56, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_76$$56, &_77$$56);
								zephir_array_append(&selectColumns, &_76$$56, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1230);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _74$$53, "rewind", NULL, 0);
							zephir_check_call_status();
							_79$$53 = 1;
							while (1) {
								if (_79$$53) {
									_79$$53 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _74$$53, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_78$$53, _74$$53, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_78$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, _74$$53, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_80$$57);
									zephir_create_array(&_80$$57, 3, 0);
									zephir_array_fast_append(&_80$$57, &attribute);
									zephir_array_fast_append(&_80$$57, &sqlColumn);
									ZEPHIR_INIT_NVAR(&_81$$57);
									ZEPHIR_CONCAT_SVSV(&_81$$57, "_", &sqlColumn, "_", &attribute);
									zephir_array_fast_append(&_80$$57, &_81$$57);
									zephir_array_append(&selectColumns, &_80$$57, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1230);
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
						zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
						zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
						ZEPHIR_CALL_METHOD(&_82$$53, &manager, "iskeepingsnapshots", &_83, 0, &instance);
						zephir_check_call_status();
						isKeepingSnapshots = zephir_get_boolval(&_82$$53);
						if (isKeepingSnapshots) {
							ZEPHIR_INIT_NVAR(&_84$$58);
							ZVAL_BOOL(&_84$$58, isKeepingSnapshots);
							zephir_array_update_multi(&columns1, &_84$$58, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
						}
					} else {
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_86$$59);
							zephir_string_to_char_array(&_86$$59, &attributes);
							_85$$59 = &_86$$59;
						} else {
							_85$$59 = &attributes;
						}
						zephir_is_iterable(_85$$59, 0, "phalcon/Mvc/Model/Query.zep", 1254);
						if (Z_TYPE_P(_85$$59) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_85$$59), _87$$59)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _87$$59);
								ZEPHIR_INIT_NVAR(&_88$$60);
								zephir_create_array(&_88$$60, 2, 0);
								zephir_array_fast_append(&_88$$60, &attribute);
								zephir_array_fast_append(&_88$$60, &sqlColumn);
								zephir_array_append(&selectColumns, &_88$$60, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1252);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _85$$59, "rewind", NULL, 0);
							zephir_check_call_status();
							_90$$59 = 1;
							while (1) {
								if (_90$$59) {
									_90$$59 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _85$$59, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_89$$59, _85$$59, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_89$$59)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, _85$$59, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_91$$61);
									zephir_create_array(&_91$$61, 2, 0);
									zephir_array_fast_append(&_91$$61, &attribute);
									zephir_array_fast_append(&_91$$61, &sqlColumn);
									zephir_array_append(&selectColumns, &_91$$61, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1252);
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
					}
				} else {
					if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
						ZEPHIR_INIT_NVAR(&_92$$63);
						zephir_create_array(&_92$$63, 2, 0);
						zephir_array_fast_append(&_92$$63, &sqlColumn);
						zephir_array_fast_append(&_92$$63, &__$null);
						ZEPHIR_CPY_WRT(&columnAlias, &_92$$63);
					} else {
						ZEPHIR_INIT_NVAR(&_93$$64);
						zephir_create_array(&_93$$64, 3, 0);
						zephir_array_fast_append(&_93$$64, &sqlColumn);
						zephir_array_fast_append(&_93$$64, &__$null);
						zephir_array_fast_append(&_93$$64, &aliasCopy);
						ZEPHIR_CPY_WRT(&columnAlias, &_93$$64);
					}
					zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
				}
				_94$$50 = !isComplex;
				if (_94$$50) {
					_94$$50 = isSimpleStd;
				}
				if (_94$$50) {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&aliasCopy);
	ZEPHIR_INIT_VAR(&processed);
	array_init(&processed);
	ZEPHIR_INIT_VAR(&bindCounts);
	array_init(&bindCounts);
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&bindParams, 0, "phalcon/Mvc/Model/Query.zep", 1301);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindParams), _96, _97, _95)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_97 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _97);
			} else {
				ZVAL_LONG(&wildcard, _96);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _95);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&wildcardValue);
				ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
			} else {
				ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
			}
			zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_98$$71);
				ZVAL_LONG(&_98$$71, zephir_fast_count_int(&value));
				zephir_array_update_zval(&bindCounts, &wildcardValue, &_98$$71, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindParams, "rewind", NULL, 0);
		zephir_check_call_status();
		_100 = 1;
		while (1) {
			if (_100) {
				_100 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bindParams, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_99, &bindParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_99)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&wildcard, &bindParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &bindParams, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&wildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&wildcardValue);
					ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
				} else {
					ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
				}
				zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_101$$75);
					ZVAL_LONG(&_101$$75, zephir_fast_count_int(&value));
					zephir_array_update_zval(&bindCounts, &wildcardValue, &_101$$75, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	ZEPHIR_INIT_VAR(&processedTypes);
	array_init(&processedTypes);
	zephir_is_iterable(&bindTypes, 0, "phalcon/Mvc/Model/Query.zep", 1314);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindTypes), _103, _104, _102)
		{
			ZEPHIR_INIT_NVAR(&typeWildcard);
			if (_104 != NULL) { 
				ZVAL_STR_COPY(&typeWildcard, _104);
			} else {
				ZVAL_LONG(&typeWildcard, _103);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _102);
			if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&_105$$77);
				ZEPHIR_CONCAT_SV(&_105$$77, ":", &typeWildcard);
				zephir_array_update_zval(&processedTypes, &_105$$77, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindTypes, "rewind", NULL, 0);
		zephir_check_call_status();
		_107 = 1;
		while (1) {
			if (_107) {
				_107 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bindTypes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_106, &bindTypes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_106)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&typeWildcard, &bindTypes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &bindTypes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_108$$80);
					ZEPHIR_CONCAT_SV(&_108$$80, ":", &typeWildcard);
					zephir_array_update_zval(&processedTypes, &_108$$80, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&typeWildcard);
	if (!(ZEPHIR_IS_EMPTY(&bindCounts))) {
		zephir_array_update_string(&intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, &dialect, "select", NULL, 0, &intermediate);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1067, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_109$$83, &dialect, "sharedlock", NULL, 0, &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_109$$83);
	}
	ZEPHIR_INIT_VAR(&rawWildcards);
	array_init(&rawWildcards);
	if (Z_TYPE_P(&processed) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_111);
		zephir_string_to_char_array(&_111, &processed);
		_110 = &_111;
	} else {
		_110 = &processed;
	}
	zephir_is_iterable(_110, 0, "phalcon/Mvc/Model/Query.zep", 1351);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_110), _113, _114, _112)
	{
		ZEPHIR_INIT_NVAR(&wildcard);
		if (_114 != NULL) { 
			ZVAL_STR_COPY(&wildcard, _114);
		} else {
			ZVAL_LONG(&wildcard, _113);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _112);
		_115$$84 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_115$$84) {
			_115$$84 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
		}
		if (_115$$84) {
			zephir_array_append(&rawWildcards, &wildcard, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1340);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	ZEPHIR_INIT_VAR(&_116);
	ZEPHIR_INIT_NVAR(&_116);
	zephir_create_closure_ex(&_116, NULL, phalcon_90__closure_ce, SL("__invoke"));
	ZEPHIR_MAKE_REF(&rawWildcards);
	ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 0, &rawWildcards, &_116);
	ZEPHIR_UNREF(&rawWildcards);
	zephir_check_call_status();
	if (Z_TYPE_P(&rawWildcards) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_118);
		zephir_string_to_char_array(&_118, &rawWildcards);
		_117 = &_118;
	} else {
		_117 = &rawWildcards;
	}
	zephir_is_iterable(_117, 0, "phalcon/Mvc/Model/Query.zep", 1376);
	if (Z_TYPE_P(_117) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_117), _119)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			ZVAL_COPY(&wildcard, _119);
			ZEPHIR_OBS_NVAR(&_120$$86);
			zephir_array_fetch(&_120$$86, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1359);
			zephir_cast_to_string(&_121$$86, &_120$$86);
			ZEPHIR_CPY_WRT(&rawValue, &_121$$86);
			ZVAL_LONG(&_122$$86, 0);
			ZVAL_LONG(&_123$$86, 1);
			ZEPHIR_INIT_NVAR(&_124$$86);
			zephir_substr(&_124$$86, &wildcard, 0 , 1 , 0);
			if (ZEPHIR_IS_STRING_IDENTICAL(&_124$$86, ":")) {
				ZVAL_LONG(&_125$$86, 1);
				ZEPHIR_INIT_NVAR(&placeholder);
				zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			} else {
				ZEPHIR_CPY_WRT(&placeholder, &wildcard);
			}
			ZEPHIR_INIT_NVAR(&_126$$86);
			ZVAL_STRING(&_126$$86, "/");
			ZEPHIR_CALL_FUNCTION(&_127$$86, "preg_quote", &_128, 0, &placeholder, &_126$$86);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_129$$86);
			ZEPHIR_CONCAT_SVS(&_129$$86, "/:", &_127$$86, "\\b/");
			ZEPHIR_INIT_NVAR(&_126$$86);
			object_init_ex(&_126$$86, phalcon_91__closure_ce);
			zephir_update_property_zval(&_126$$86, SL("rawValue"), &rawValue);
			ZEPHIR_INIT_NVAR(&_130$$86);
			ZEPHIR_INIT_NVAR(&_130$$86);
			zephir_create_closure_bound(&_130$$86, &_126$$86, NULL, phalcon_91__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_131$$86, "preg_replace_callback", &_132, 0, &_129$$86, &_130$$86, &sqlSelect);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sqlSelect, &_131$$86);
			zephir_array_unset(&processed, &wildcard, PH_SEPARATE);
			zephir_array_unset(&processedTypes, &wildcard, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _117, "rewind", NULL, 0);
		zephir_check_call_status();
		_134 = 1;
		while (1) {
			if (_134) {
				_134 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _117, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_133, _117, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_133)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&wildcard, _117, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_135$$87);
				zephir_array_fetch(&_135$$87, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1359);
				zephir_cast_to_string(&_136$$87, &_135$$87);
				ZEPHIR_CPY_WRT(&rawValue, &_136$$87);
				ZVAL_LONG(&_137$$87, 0);
				ZVAL_LONG(&_138$$87, 1);
				ZEPHIR_INIT_NVAR(&_139$$87);
				zephir_substr(&_139$$87, &wildcard, 0 , 1 , 0);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_139$$87, ":")) {
					ZVAL_LONG(&_140$$87, 1);
					ZEPHIR_INIT_NVAR(&placeholder);
					zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				} else {
					ZEPHIR_CPY_WRT(&placeholder, &wildcard);
				}
				ZEPHIR_INIT_NVAR(&_141$$87);
				ZVAL_STRING(&_141$$87, "/");
				ZEPHIR_CALL_FUNCTION(&_142$$87, "preg_quote", &_128, 0, &placeholder, &_141$$87);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_143$$87);
				ZEPHIR_CONCAT_SVS(&_143$$87, "/:", &_142$$87, "\\b/");
				ZEPHIR_INIT_NVAR(&_141$$87);
				object_init_ex(&_141$$87, phalcon_92__closure_ce);
				zephir_update_property_zval(&_141$$87, SL("rawValue"), &rawValue);
				ZEPHIR_INIT_NVAR(&_144$$87);
				ZEPHIR_INIT_NVAR(&_144$$87);
				zephir_create_closure_bound(&_144$$87, &_141$$87, NULL, phalcon_92__closure_ce, SL("__invoke"));
				ZEPHIR_CALL_FUNCTION(&_145$$87, "preg_replace_callback", &_132, 0, &_143$$87, &_144$$87, &sqlSelect);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&sqlSelect, &_145$$87);
				zephir_array_unset(&processed, &wildcard, PH_SEPARATE);
				zephir_array_unset(&processedTypes, &wildcard, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&wildcard);
	if (simulate) {
		zephir_create_array(return_value, 3, 0);
		zephir_array_update_string(return_value, SL("sql"), &sqlSelect, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bind"), &processed, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(return_value, SL("bindTypes"), &processedTypes, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&result, &connection, "query", NULL, 0, &sqlSelect, &processed, &processedTypes);
	zephir_check_call_status();
	if (zephir_instance_of_ev(&result, phalcon_db_resultinterface_ce)) {
		ZEPHIR_CPY_WRT(&resultData, &result);
	} else {
		ZEPHIR_INIT_NVAR(&resultData);
		ZVAL_NULL(&resultData);
	}
	zephir_read_property_cached(&_146, this_ptr, _zephir_prop_4, 1061, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_146);
	if (!(isComplex)) {
		if (isSimpleStd) {
			zephir_read_property_cached(&_147$$92, this_ptr, _zephir_prop_5, 1069, PH_NOISY_CC | PH_READONLY);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_147$$92, "")) {
				zephir_read_property_cached(&_148$$93, this_ptr, _zephir_prop_5, 1069, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&resultObject);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&resultObject, &_148$$93);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&resultObject);
				object_init_ex(&resultObject, phalcon_mvc_model_row_ce);
				if (zephir_has_constructor(&resultObject)) {
					ZEPHIR_CALL_METHOD(NULL, &resultObject, "__construct", NULL, 0);
					zephir_check_call_status();
				}

			}
			isKeepingSnapshots = 0;
		} else {
			if (Z_TYPE_P(&instance) == IS_OBJECT) {
				ZEPHIR_CPY_WRT(&resultObject, &instance);
			} else {
				ZEPHIR_CPY_WRT(&resultObject, &model);
			}
			ZEPHIR_INIT_VAR(&_150$$95);
			ZVAL_STRING(&_150$$95, "orm.cast_on_hydrate");
			ZEPHIR_CALL_CE_STATIC(&_149$$95, phalcon_support_settings_ce, "get", &_41, 0, &_150$$95);
			zephir_check_call_status();
			if (!(zephir_is_true(&_149$$95))) {
				ZEPHIR_CALL_METHOD(&simpleColumnMap, &metaData, "getcolumnmap", NULL, 0, &resultObject);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&typesColumnMap, &metaData, "getdatatypes", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&simpleColumnMap);
				if (Z_TYPE_P(&columnMap) == IS_NULL) {
					array_init(&simpleColumnMap);
					ZEPHIR_CALL_METHOD(&_151$$100, &metaData, "getattributes", NULL, 0, &resultObject);
					zephir_check_call_status();
					if (Z_TYPE_P(&_151$$100) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_153$$100);
						zephir_string_to_char_array(&_153$$100, &_151$$100);
						_152$$100 = &_153$$100;
					} else {
						_152$$100 = &_151$$100;
					}
					zephir_is_iterable(_152$$100, 0, "phalcon/Mvc/Model/Query.zep", 1450);
					if (Z_TYPE_P(_152$$100) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_152$$100), _154$$100)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _154$$100);
							ZEPHIR_INIT_NVAR(&_155$$101);
							zephir_create_array(&_155$$101, 2, 0);
							zephir_array_fast_append(&_155$$101, &attribute);
							ZEPHIR_OBS_NVAR(&_156$$101);
							zephir_array_fetch(&_156$$101, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1448);
							zephir_array_fast_append(&_155$$101, &_156$$101);
							zephir_array_update_zval(&simpleColumnMap, &attribute, &_155$$101, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _152$$100, "rewind", NULL, 0);
						zephir_check_call_status();
						_158$$100 = 1;
						while (1) {
							if (_158$$100) {
								_158$$100 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _152$$100, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_157$$100, _152$$100, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_157$$100)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _152$$100, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_159$$102);
								zephir_create_array(&_159$$102, 2, 0);
								zephir_array_fast_append(&_159$$102, &attribute);
								ZEPHIR_OBS_NVAR(&_160$$102);
								zephir_array_fetch(&_160$$102, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1448);
								zephir_array_fast_append(&_159$$102, &_160$$102);
								zephir_array_update_zval(&simpleColumnMap, &attribute, &_159$$102, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				} else {
					array_init(&simpleColumnMap);
					if (Z_TYPE_P(&columnMap) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_162$$103);
						zephir_string_to_char_array(&_162$$103, &columnMap);
						_161$$103 = &_162$$103;
					} else {
						_161$$103 = &columnMap;
					}
					zephir_is_iterable(_161$$103, 0, "phalcon/Mvc/Model/Query.zep", 1459);
					if (Z_TYPE_P(_161$$103) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_161$$103), _164$$103, _165$$103, _163$$103)
						{
							ZEPHIR_INIT_NVAR(&column);
							if (_165$$103 != NULL) { 
								ZVAL_STR_COPY(&column, _165$$103);
							} else {
								ZVAL_LONG(&column, _164$$103);
							}
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _163$$103);
							ZEPHIR_INIT_NVAR(&_166$$104);
							zephir_create_array(&_166$$104, 2, 0);
							zephir_array_fast_append(&_166$$104, &attribute);
							ZEPHIR_OBS_NVAR(&_167$$104);
							zephir_array_fetch(&_167$$104, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1457);
							zephir_array_fast_append(&_166$$104, &_167$$104);
							zephir_array_update_zval(&simpleColumnMap, &column, &_166$$104, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _161$$103, "rewind", NULL, 0);
						zephir_check_call_status();
						_169$$103 = 1;
						while (1) {
							if (_169$$103) {
								_169$$103 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _161$$103, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_168$$103, _161$$103, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_168$$103)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&column, _161$$103, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, _161$$103, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_170$$105);
								zephir_create_array(&_170$$105, 2, 0);
								zephir_array_fast_append(&_170$$105, &attribute);
								ZEPHIR_OBS_NVAR(&_171$$105);
								zephir_array_fetch(&_171$$105, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1457);
								zephir_array_fast_append(&_170$$105, &_171$$105);
								zephir_array_update_zval(&simpleColumnMap, &column, &_170$$105, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					ZEPHIR_INIT_NVAR(&column);
				}
			}
			ZEPHIR_CALL_METHOD(&_172$$95, &manager, "iskeepingsnapshots", NULL, 0, &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_172$$95);
		}
		_173$$91 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce);
		if (_173$$91) {
			_173$$91 = (zephir_method_exists_ex(&resultObject, ZEND_STRL("getresultsetclass")) == SUCCESS);
		}
		if (_173$$91) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, &resultObject, "getresultsetclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (UNEXPECTED(!(zephir_class_exists(&resultsetClassName, 1)))) {
					ZEPHIR_INIT_VAR(&_174$$108);
					object_init_ex(&_174$$108, phalcon_mvc_model_query_exceptions_resultsetclassnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_174$$108, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_174$$108, "phalcon/Mvc/Model/Query.zep", 1473);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_175$$107);
				ZVAL_STRING(&_175$$107, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_176$$107, "is_subclass_of", NULL, 150, &resultsetClassName, &_175$$107);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_176$$107))) {
					ZEPHIR_INIT_VAR(&_177$$109);
					object_init_ex(&_177$$109, phalcon_mvc_model_query_exceptions_invalidresultsetclass_ce);
					ZEPHIR_CALL_METHOD(NULL, &_177$$109, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_177$$109, "phalcon/Mvc/Model/Query.zep", 1477);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_178$$107);
				zephir_create_array(&_178$$107, 5, 0);
				zephir_array_fast_append(&_178$$107, &simpleColumnMap);
				zephir_array_fast_append(&_178$$107, &resultObject);
				zephir_array_fast_append(&_178$$107, &resultData);
				zephir_array_fast_append(&_178$$107, &cache);
				ZEPHIR_INIT_NVAR(&_175$$107);
				ZVAL_BOOL(&_175$$107, isKeepingSnapshots);
				zephir_array_fast_append(&_178$$107, &_175$$107);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &resultsetClassName, &_178$$107);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_179$$91, 1);
		} else {
			ZVAL_BOOL(&_179$$91, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &simpleColumnMap, &resultObject, &resultData, &cache, &_179$$91);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	zephir_read_property_cached(&_146, this_ptr, _zephir_prop_5, 1069, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &columns1, &resultData, &cache, &_146);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the UPDATE intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeUpdate)
{
	zval _32$$16, _39$$17, _48$$20, _54$$21, _80$$33, _86$$34, _95$$37, _101$$38;
	zend_bool _59, _43$$13, _27$$15, _44$$19, _90$$30, _76$$32, _91$$36;
	zend_string *_7;
	zend_ulong _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_15 = NULL, *_16 = NULL, *_21 = NULL, *_23 = NULL, *_30 = NULL, *_34 = NULL, *_40 = NULL, *_55 = NULL, *_57 = NULL, *_61 = NULL, *_63 = NULL, *_67 = NULL, *_87 = NULL, *_102 = NULL, *_106 = NULL, *_108 = NULL, *_110 = NULL, *_112 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, exception, sqlExpr, namedParams, paramKey, paramKeys, paramValue, _1, *_3, _4, *_5, _58, _105, _113, _0$$3, _2$$4, _8$$5, _10$$10, _12$$10, _13$$10, _14$$11, _17$$12, _18$$12, _19$$12, _20$$13, _22$$13, *_24$$13, _25$$13, *_26$$13, _42$$13, _28$$16, _29$$16, _31$$16, _33$$16, _35$$17, _36$$17, _37$$17, _38$$17, _41$$17, _45$$20, _46$$20, _47$$20, _49$$20, _50$$21, _51$$21, _52$$21, _53$$21, _56$$21, _60$$22, _62$$27, _64$$27, _65$$27, _66$$28, _68$$29, _69$$29, _70$$29, _71$$30, _72$$30, *_73$$30, _74$$30, *_75$$30, _89$$30, _77$$33, _78$$33, _79$$33, _81$$33, _82$$34, _83$$34, _84$$34, _85$$34, _88$$34, _92$$37, _93$$37, _94$$37, _96$$37, _97$$38, _98$$38, _99$$38, _100$$38, _103$$38, _104$$39, _107$$41, _109$$42, _111$$40;
	zval intermediate, bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&selectBindParams);
	ZVAL_UNDEF(&selectBindTypes);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&sqlExpr);
	ZVAL_UNDEF(&namedParams);
	ZVAL_UNDEF(&paramKey);
	ZVAL_UNDEF(&paramKeys);
	ZVAL_UNDEF(&paramValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_105);
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_45$$20);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_50$$21);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_64$$27);
	ZVAL_UNDEF(&_65$$27);
	ZVAL_UNDEF(&_66$$28);
	ZVAL_UNDEF(&_68$$29);
	ZVAL_UNDEF(&_69$$29);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_71$$30);
	ZVAL_UNDEF(&_72$$30);
	ZVAL_UNDEF(&_74$$30);
	ZVAL_UNDEF(&_89$$30);
	ZVAL_UNDEF(&_77$$33);
	ZVAL_UNDEF(&_78$$33);
	ZVAL_UNDEF(&_79$$33);
	ZVAL_UNDEF(&_81$$33);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_84$$34);
	ZVAL_UNDEF(&_85$$34);
	ZVAL_UNDEF(&_88$$34);
	ZVAL_UNDEF(&_92$$37);
	ZVAL_UNDEF(&_93$$37);
	ZVAL_UNDEF(&_94$$37);
	ZVAL_UNDEF(&_96$$37);
	ZVAL_UNDEF(&_97$$38);
	ZVAL_UNDEF(&_98$$38);
	ZVAL_UNDEF(&_99$$38);
	ZVAL_UNDEF(&_100$$38);
	ZVAL_UNDEF(&_103$$38);
	ZVAL_UNDEF(&_104$$39);
	ZVAL_UNDEF(&_107$$41);
	ZVAL_UNDEF(&_109$$42);
	ZVAL_UNDEF(&_111$$40);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_86$$34);
	ZVAL_UNDEF(&_95$$37);
	ZVAL_UNDEF(&_101$$38);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &intermediate_param, &bindParams_param, &bindTypes_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	zephir_memory_observe(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1527);
	if (UNEXPECTED(zephir_array_isset_value_long(&models, 1))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_updatemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 1530);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1533);
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1070, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_1, &modelName, 0))) {
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_2$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&fields);
	zephir_array_fetch_string(&fields, &intermediate, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1552);
	zephir_memory_observe(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1553);
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_CPY_WRT(&selectBindParams, &bindParams);
	ZEPHIR_CPY_WRT(&selectBindTypes, &bindTypes);
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &fields);
		_3 = &_4;
	} else {
		_3 = &fields;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model/Query.zep", 1666);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&number, _7);
			} else {
				ZVAL_LONG(&number, _6);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _5);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1568);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1569);
			if (zephir_array_isset_value_string(&field, SL("balias"))) {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1572);
			} else {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1574);
			}
			zephir_array_fetch_string(&_8$$5, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1577);
			if (ZEPHIR_IS_LONG(&_8$$5, 260)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_8$$5, 258)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_8$$5, 259)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_8$$5, 322)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&_8$$5, 273)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&_8$$5, 274)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&_8$$5, 277)) { goto zephir_switch_0_clause_6; }
			goto zephir_switch_0_clause_7;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_9, 0, &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&updateValue);
				ZVAL_NULL(&updateValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD(&_10$$10, &dialect, "getsqlexpression", &_11, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_STRING(&_12$$10, ":");
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_12$$10, &_13$$10, &_10$$10);
				ZEPHIR_OBS_NVAR(&updateValue);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0)))) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					object_init_ex(&_14$$11, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", &_15, 0, &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$11, "phalcon/Mvc/Model/Query.zep", 1598);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
				zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_CALL_METHOD(&sqlExpr, &dialect, "getsqlexpression", &_16, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&namedParams);
				array_init(&namedParams);
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_STRING(&_17$$12, "/:([a-zA-Z0-9_]+)/");
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_STRING(&_19$$12, "/:([a-zA-Z0-9_]+)/");
				zephir_preg_match(&_18$$12, &_19$$12, &sqlExpr, &namedParams, 1, 0 , 0 );
				if (zephir_is_true(&_18$$12)) {
					zephir_array_fetch_long(&_20$$13, &namedParams, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1624);
					ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_21, 442, &_20$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZEPHIR_INIT_NVAR(&_22$$13);
					zephir_create_closure_ex(&_22$$13, NULL, phalcon_93__closure_ce, SL("__invoke"));
					ZEPHIR_MAKE_REF(&paramKeys);
					ZEPHIR_CALL_FUNCTION(NULL, "usort", &_23, 0, &paramKeys, &_22$$13);
					ZEPHIR_UNREF(&paramKeys);
					zephir_check_call_status();
					if (Z_TYPE_P(&paramKeys) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_25$$13);
						zephir_string_to_char_array(&_25$$13, &paramKeys);
						_24$$13 = &_25$$13;
					} else {
						_24$$13 = &paramKeys;
					}
					zephir_is_iterable(_24$$13, 0, "phalcon/Mvc/Model/Query.zep", 1653);
					if (Z_TYPE_P(_24$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_24$$13), _26$$13)
						{
							ZEPHIR_INIT_NVAR(&paramKey);
							ZVAL_COPY(&paramKey, _26$$13);
							ZEPHIR_OBS_NVAR(&paramValue);
							if (zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0)) {
								_27$$15 = Z_TYPE_P(&paramValue) == IS_LONG;
								if (!(_27$$15)) {
									_27$$15 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
								}
								if (_27$$15) {
									ZEPHIR_INIT_NVAR(&_28$$16);
									ZVAL_STRING(&_28$$16, "/");
									ZEPHIR_CALL_FUNCTION(&_29$$16, "preg_quote", &_30, 0, &paramKey, &_28$$16);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_31$$16);
									ZEPHIR_CONCAT_SVS(&_31$$16, "/:", &_29$$16, "\\b/");
									zephir_cast_to_string(&_32$$16, &paramValue);
									ZEPHIR_CALL_FUNCTION(&_33$$16, "preg_replace", &_34, 6, &_31$$16, &_32$$16, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_33$$16);
								} else {
									ZEPHIR_INIT_NVAR(&_35$$17);
									ZVAL_STRING(&_35$$17, "/");
									ZEPHIR_CALL_FUNCTION(&_36$$17, "preg_quote", &_30, 0, &paramKey, &_35$$17);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_37$$17);
									ZEPHIR_CONCAT_SVS(&_37$$17, "/:", &_36$$17, "\\b/");
									zephir_cast_to_string(&_39$$17, &paramValue);
									ZEPHIR_CALL_METHOD(&_38$$17, &connection, "escapestring", &_40, 0, &_39$$17);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_41$$17, "preg_replace", &_34, 6, &_37$$17, &_38$$17, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_41$$17);
								}
								zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
								zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _24$$13, "rewind", NULL, 0);
						zephir_check_call_status();
						_43$$13 = 1;
						while (1) {
							if (_43$$13) {
								_43$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _24$$13, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_42$$13, _24$$13, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_42$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&paramKey, _24$$13, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&paramValue);
								if (zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0)) {
									_44$$19 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_44$$19)) {
										_44$$19 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_44$$19) {
										ZEPHIR_INIT_NVAR(&_45$$20);
										ZVAL_STRING(&_45$$20, "/");
										ZEPHIR_CALL_FUNCTION(&_46$$20, "preg_quote", &_30, 0, &paramKey, &_45$$20);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_47$$20);
										ZEPHIR_CONCAT_SVS(&_47$$20, "/:", &_46$$20, "\\b/");
										zephir_cast_to_string(&_48$$20, &paramValue);
										ZEPHIR_CALL_FUNCTION(&_49$$20, "preg_replace", &_34, 6, &_47$$20, &_48$$20, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_49$$20);
									} else {
										ZEPHIR_INIT_NVAR(&_50$$21);
										ZVAL_STRING(&_50$$21, "/");
										ZEPHIR_CALL_FUNCTION(&_51$$21, "preg_quote", &_30, 0, &paramKey, &_50$$21);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_52$$21);
										ZEPHIR_CONCAT_SVS(&_52$$21, "/:", &_51$$21, "\\b/");
										zephir_cast_to_string(&_54$$21, &paramValue);
										ZEPHIR_CALL_METHOD(&_53$$21, &connection, "escapestring", &_55, 0, &_54$$21);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_56$$21, "preg_replace", &_34, 6, &_52$$21, &_53$$21, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_56$$21);
									}
									zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
									zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
								}
						}
					}
					ZEPHIR_INIT_NVAR(&paramKey);
				}
				ZEPHIR_INIT_NVAR(&updateValue);
				object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_57, 65, &sqlExpr);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_59 = 1;
		while (1) {
			if (_59) {
				_59 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_58, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_58)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&field, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1568);
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1569);
				if (zephir_array_isset_value_string(&field, SL("balias"))) {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1572);
				} else {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1574);
				}
				zephir_array_fetch_string(&_60$$22, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1577);
				if (ZEPHIR_IS_LONG(&_60$$22, 260)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_60$$22, 258)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_60$$22, 259)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_60$$22, 322)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_60$$22, 273)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_60$$22, 274)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_60$$22, 277)) { goto zephir_switch_1_clause_6; }
				goto zephir_switch_1_clause_7;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_61, 0, &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&updateValue);
					ZVAL_NULL(&updateValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD(&_62$$27, &dialect, "getsqlexpression", &_63, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_64$$27);
					ZVAL_STRING(&_64$$27, ":");
					ZEPHIR_INIT_NVAR(&_65$$27);
					ZVAL_STRING(&_65$$27, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_64$$27, &_65$$27, &_62$$27);
					ZEPHIR_OBS_NVAR(&updateValue);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0)))) {
						ZEPHIR_INIT_NVAR(&_66$$28);
						object_init_ex(&_66$$28, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_66$$28, "__construct", &_15, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_66$$28, "phalcon/Mvc/Model/Query.zep", 1598);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
					zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_CALL_METHOD(&sqlExpr, &dialect, "getsqlexpression", &_67, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&namedParams);
					array_init(&namedParams);
					ZEPHIR_INIT_NVAR(&_68$$29);
					ZVAL_STRING(&_68$$29, "/:([a-zA-Z0-9_]+)/");
					ZEPHIR_INIT_NVAR(&_69$$29);
					ZEPHIR_INIT_NVAR(&_70$$29);
					ZVAL_STRING(&_70$$29, "/:([a-zA-Z0-9_]+)/");
					zephir_preg_match(&_69$$29, &_70$$29, &sqlExpr, &namedParams, 1, 0 , 0 );
					if (zephir_is_true(&_69$$29)) {
						zephir_array_fetch_long(&_71$$30, &namedParams, 1, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1624);
						ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_21, 442, &_71$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_72$$30);
						ZEPHIR_INIT_NVAR(&_72$$30);
						zephir_create_closure_ex(&_72$$30, NULL, phalcon_94__closure_ce, SL("__invoke"));
						ZEPHIR_MAKE_REF(&paramKeys);
						ZEPHIR_CALL_FUNCTION(NULL, "usort", &_23, 0, &paramKeys, &_72$$30);
						ZEPHIR_UNREF(&paramKeys);
						zephir_check_call_status();
						if (Z_TYPE_P(&paramKeys) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_74$$30);
							zephir_string_to_char_array(&_74$$30, &paramKeys);
							_73$$30 = &_74$$30;
						} else {
							_73$$30 = &paramKeys;
						}
						zephir_is_iterable(_73$$30, 0, "phalcon/Mvc/Model/Query.zep", 1653);
						if (Z_TYPE_P(_73$$30) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_73$$30), _75$$30)
							{
								ZEPHIR_INIT_NVAR(&paramKey);
								ZVAL_COPY(&paramKey, _75$$30);
								ZEPHIR_OBS_NVAR(&paramValue);
								if (zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0)) {
									_76$$32 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_76$$32)) {
										_76$$32 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_76$$32) {
										ZEPHIR_INIT_NVAR(&_77$$33);
										ZVAL_STRING(&_77$$33, "/");
										ZEPHIR_CALL_FUNCTION(&_78$$33, "preg_quote", &_30, 0, &paramKey, &_77$$33);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_79$$33);
										ZEPHIR_CONCAT_SVS(&_79$$33, "/:", &_78$$33, "\\b/");
										zephir_cast_to_string(&_80$$33, &paramValue);
										ZEPHIR_CALL_FUNCTION(&_81$$33, "preg_replace", &_34, 6, &_79$$33, &_80$$33, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_81$$33);
									} else {
										ZEPHIR_INIT_NVAR(&_82$$34);
										ZVAL_STRING(&_82$$34, "/");
										ZEPHIR_CALL_FUNCTION(&_83$$34, "preg_quote", &_30, 0, &paramKey, &_82$$34);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_84$$34);
										ZEPHIR_CONCAT_SVS(&_84$$34, "/:", &_83$$34, "\\b/");
										zephir_cast_to_string(&_86$$34, &paramValue);
										ZEPHIR_CALL_METHOD(&_85$$34, &connection, "escapestring", &_87, 0, &_86$$34);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_88$$34, "preg_replace", &_34, 6, &_84$$34, &_85$$34, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_88$$34);
									}
									zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
									zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _73$$30, "rewind", NULL, 0);
							zephir_check_call_status();
							_90$$30 = 1;
							while (1) {
								if (_90$$30) {
									_90$$30 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _73$$30, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_89$$30, _73$$30, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_89$$30)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&paramKey, _73$$30, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&paramValue);
									if (zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0)) {
										_91$$36 = Z_TYPE_P(&paramValue) == IS_LONG;
										if (!(_91$$36)) {
											_91$$36 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
										}
										if (_91$$36) {
											ZEPHIR_INIT_NVAR(&_92$$37);
											ZVAL_STRING(&_92$$37, "/");
											ZEPHIR_CALL_FUNCTION(&_93$$37, "preg_quote", &_30, 0, &paramKey, &_92$$37);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_94$$37);
											ZEPHIR_CONCAT_SVS(&_94$$37, "/:", &_93$$37, "\\b/");
											zephir_cast_to_string(&_95$$37, &paramValue);
											ZEPHIR_CALL_FUNCTION(&_96$$37, "preg_replace", &_34, 6, &_94$$37, &_95$$37, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_96$$37);
										} else {
											ZEPHIR_INIT_NVAR(&_97$$38);
											ZVAL_STRING(&_97$$38, "/");
											ZEPHIR_CALL_FUNCTION(&_98$$38, "preg_quote", &_30, 0, &paramKey, &_97$$38);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_99$$38);
											ZEPHIR_CONCAT_SVS(&_99$$38, "/:", &_98$$38, "\\b/");
											zephir_cast_to_string(&_101$$38, &paramValue);
											ZEPHIR_CALL_METHOD(&_100$$38, &connection, "escapestring", &_102, 0, &_101$$38);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_103$$38, "preg_replace", &_34, 6, &_99$$38, &_100$$38, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_103$$38);
										}
										zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
										zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
									}
							}
						}
						ZEPHIR_INIT_NVAR(&paramKey);
					}
					ZEPHIR_INIT_NVAR(&updateValue);
					object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_57, 65, &sqlExpr);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getrelatedrecords", NULL, 0, &model, &intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_104$$39, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_104$$39);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_105, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_105))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&record, &records, "current", &_106, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, &record, "assign", NULL, 0, &updateValues);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_107$$41, &record, "update", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_107$$41))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_108, 0);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_109$$42, 0);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_109$$42, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &records, "next", &_110, 0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_111$$40);
			ZVAL_OBJ(&_111$$40, EG(exception));
			Z_ADDREF_P(&_111$$40);
			if (zephir_is_instance_of(&_111$$40, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_111$$40);
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_112, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 1716);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_113, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_113);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCallArgument)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, _0;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(argument, argument_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &argument_param);
	zephir_get_arrval(&argument, argument_param);
	zephir_array_fetch_string(&_0, &argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1733);
	if (ZEPHIR_IS_LONG(&_0, 352)) {
		zephir_create_array(return_value, 1, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("all"));
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getexpression", NULL, 0, &argument);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCaseExpression)
{
	zend_bool _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _2, *_3, _12, _21, _22, _5$$4, _6$$4, _8$$4, _10$$5, _11$$5, _15$$7, _16$$7, _17$$7, _19$$8, _20$$8;
	zval expr, _4$$4, _9$$5, _14$$7, _18$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	ZEPHIR_INIT_VAR(&whenClauses);
	array_init(&whenClauses);
	zephir_array_fetch_string(&_0, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1751);
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 1766);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&whenExpr);
			ZVAL_COPY(&whenExpr, _3);
			if (zephir_array_isset_value_string(&whenExpr, SL("right"))) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				zephir_create_array(&_4$$4, 3, 0);
				add_assoc_stringl_ex(&_4$$4, SL("type"), SL("when"));
				zephir_array_fetch_string(&_6$$4, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1755);
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getexpression", &_7, 0, &_6$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_4$$4, SL("expr"), &_5$$4, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_8$$4, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1756);
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getexpression", &_7, 0, &_8$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_4$$4, SL("then"), &_5$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_4$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1757);
			} else {
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_create_array(&_9$$5, 2, 0);
				add_assoc_stringl_ex(&_9$$5, SL("type"), SL("else"));
				zephir_array_fetch_string(&_11$$5, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1761);
				ZEPHIR_CALL_METHOD(&_10$$5, this_ptr, "getexpression", &_7, 0, &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_9$$5, SL("expr"), &_10$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_9$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1762);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_12, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&whenExpr, _1, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset_value_string(&whenExpr, SL("right"))) {
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_create_array(&_14$$7, 3, 0);
					add_assoc_stringl_ex(&_14$$7, SL("type"), SL("when"));
					zephir_array_fetch_string(&_16$$7, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1755);
					ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "getexpression", &_7, 0, &_16$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_14$$7, SL("expr"), &_15$$7, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_17$$7, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1756);
					ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "getexpression", &_7, 0, &_17$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_14$$7, SL("then"), &_15$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_14$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1757);
				} else {
					ZEPHIR_INIT_NVAR(&_18$$8);
					zephir_create_array(&_18$$8, 2, 0);
					add_assoc_stringl_ex(&_18$$8, SL("type"), SL("else"));
					zephir_array_fetch_string(&_20$$8, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1761);
					ZEPHIR_CALL_METHOD(&_19$$8, this_ptr, "getexpression", &_7, 0, &_20$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_18$$8, SL("expr"), &_19$$8, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_18$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1762);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&whenExpr);
	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("case"));
	zephir_array_fetch_string(&_22, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1768);
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "getexpression", &_7, 0, &_22);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_21, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Resolves an expression from its intermediate code into an array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getExpression)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0, _103$$80;
	zval *expr_param = NULL, *quoting_param = NULL, __$true, bind, bindType, exprType, exprLeft, exprListItem, exprRight, listItems, name, value, valueParts, exprReturn, left, right, _105, _0$$5, _1$$6, _2$$7, _3$$8, _4$$9, _5$$10, _6$$11, _7$$12, _8$$13, _9$$14, _10$$15, _11$$16, _12$$17, _13$$18, _14$$19, _15$$20, _16$$21, _17$$22, _18$$23, _19$$25, _20$$26, _21$$27, _22$$28, _23$$29, _24$$30, _25$$31, _26$$32, _27$$33, _28$$34, _29$$34, _30$$35, _31$$36, _32$$38, _33$$39, _34$$40, _35$$40, _36$$40, _37$$40, _38$$40, _39$$41, _40$$41, _41$$41, _42$$44, _43$$44, _44$$44, _45$$45, _46$$45, _47$$45, _48$$46, _49$$46, _50$$46, _51$$47, _52$$47, _53$$47, _54$$48, _55$$48, _56$$48, _57$$49, _58$$49, _59$$49, _60$$50, _64$$50, _65$$50, _61$$51, _62$$52, _63$$53, _66$$54, _67$$55, _68$$55, _69$$56, _70$$57, _71$$58, _72$$59, _73$$60, _74$$61, _75$$62, _76$$63, _77$$64, _78$$65, _79$$66, _80$$67, _81$$68, _82$$69, _83$$70, _84$$71, _85$$72, _86$$73, _87$$73, _88$$73, _89$$73, _90$$73, _94$$73, _95$$73, _91$$74, _92$$74, _93$$74, _96$$77, _97$$77, _98$$77, _99$$78, *_100$$80, _102$$80, _101$$81, _104$$82;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&exprType);
	ZVAL_UNDEF(&exprLeft);
	ZVAL_UNDEF(&exprListItem);
	ZVAL_UNDEF(&exprRight);
	ZVAL_UNDEF(&listItems);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&valueParts);
	ZVAL_UNDEF(&exprReturn);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&_105);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$16);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$21);
	ZVAL_UNDEF(&_17$$22);
	ZVAL_UNDEF(&_18$$23);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$26);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$28);
	ZVAL_UNDEF(&_23$$29);
	ZVAL_UNDEF(&_24$$30);
	ZVAL_UNDEF(&_25$$31);
	ZVAL_UNDEF(&_26$$32);
	ZVAL_UNDEF(&_27$$33);
	ZVAL_UNDEF(&_28$$34);
	ZVAL_UNDEF(&_29$$34);
	ZVAL_UNDEF(&_30$$35);
	ZVAL_UNDEF(&_31$$36);
	ZVAL_UNDEF(&_32$$38);
	ZVAL_UNDEF(&_33$$39);
	ZVAL_UNDEF(&_34$$40);
	ZVAL_UNDEF(&_35$$40);
	ZVAL_UNDEF(&_36$$40);
	ZVAL_UNDEF(&_37$$40);
	ZVAL_UNDEF(&_38$$40);
	ZVAL_UNDEF(&_39$$41);
	ZVAL_UNDEF(&_40$$41);
	ZVAL_UNDEF(&_41$$41);
	ZVAL_UNDEF(&_42$$44);
	ZVAL_UNDEF(&_43$$44);
	ZVAL_UNDEF(&_44$$44);
	ZVAL_UNDEF(&_45$$45);
	ZVAL_UNDEF(&_46$$45);
	ZVAL_UNDEF(&_47$$45);
	ZVAL_UNDEF(&_48$$46);
	ZVAL_UNDEF(&_49$$46);
	ZVAL_UNDEF(&_50$$46);
	ZVAL_UNDEF(&_51$$47);
	ZVAL_UNDEF(&_52$$47);
	ZVAL_UNDEF(&_53$$47);
	ZVAL_UNDEF(&_54$$48);
	ZVAL_UNDEF(&_55$$48);
	ZVAL_UNDEF(&_56$$48);
	ZVAL_UNDEF(&_57$$49);
	ZVAL_UNDEF(&_58$$49);
	ZVAL_UNDEF(&_59$$49);
	ZVAL_UNDEF(&_60$$50);
	ZVAL_UNDEF(&_64$$50);
	ZVAL_UNDEF(&_65$$50);
	ZVAL_UNDEF(&_61$$51);
	ZVAL_UNDEF(&_62$$52);
	ZVAL_UNDEF(&_63$$53);
	ZVAL_UNDEF(&_66$$54);
	ZVAL_UNDEF(&_67$$55);
	ZVAL_UNDEF(&_68$$55);
	ZVAL_UNDEF(&_69$$56);
	ZVAL_UNDEF(&_70$$57);
	ZVAL_UNDEF(&_71$$58);
	ZVAL_UNDEF(&_72$$59);
	ZVAL_UNDEF(&_73$$60);
	ZVAL_UNDEF(&_74$$61);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_76$$63);
	ZVAL_UNDEF(&_77$$64);
	ZVAL_UNDEF(&_78$$65);
	ZVAL_UNDEF(&_79$$66);
	ZVAL_UNDEF(&_80$$67);
	ZVAL_UNDEF(&_81$$68);
	ZVAL_UNDEF(&_82$$69);
	ZVAL_UNDEF(&_83$$70);
	ZVAL_UNDEF(&_84$$71);
	ZVAL_UNDEF(&_85$$72);
	ZVAL_UNDEF(&_86$$73);
	ZVAL_UNDEF(&_87$$73);
	ZVAL_UNDEF(&_88$$73);
	ZVAL_UNDEF(&_89$$73);
	ZVAL_UNDEF(&_90$$73);
	ZVAL_UNDEF(&_94$$73);
	ZVAL_UNDEF(&_95$$73);
	ZVAL_UNDEF(&_91$$74);
	ZVAL_UNDEF(&_92$$74);
	ZVAL_UNDEF(&_93$$74);
	ZVAL_UNDEF(&_96$$77);
	ZVAL_UNDEF(&_97$$77);
	ZVAL_UNDEF(&_98$$77);
	ZVAL_UNDEF(&_99$$78);
	ZVAL_UNDEF(&_102$$80);
	ZVAL_UNDEF(&_101$$81);
	ZVAL_UNDEF(&_104$$82);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("bindParams", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("phql", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(quoting)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &expr_param, &quoting_param);
	zephir_get_arrval(&expr, expr_param);
	if (!quoting_param) {
		quoting = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&exprReturn);
	array_init(&exprReturn);
	ZEPHIR_INIT_VAR(&left);
	ZVAL_NULL(&left);
	ZEPHIR_INIT_VAR(&right);
	ZVAL_NULL(&right);
	zephir_memory_observe(&exprType);
	if (zephir_array_isset_string_fetch(&exprType, &expr, SL("type"), 0)) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(&exprType, 409)) {
			zephir_memory_observe(&exprLeft);
			if (zephir_array_isset_string_fetch(&exprLeft, &expr, SL("left"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_0$$5, 1);
				} else {
					ZVAL_BOOL(&_0$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&left, this_ptr, "getexpression", NULL, 0, &exprLeft, &_0$$5);
				zephir_check_call_status();
			}
			zephir_memory_observe(&exprRight);
			if (zephir_array_isset_string_fetch(&exprRight, &expr, SL("right"), 0)) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_1$$6, 1);
				} else {
					ZVAL_BOOL(&_1$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&right, this_ptr, "getexpression", NULL, 0, &exprRight, &_1$$6);
				zephir_check_call_status();
			}
		}
		if (ZEPHIR_IS_LONG(&exprType, '<')) { goto zephir_switch_0_clause_0; }
		if (ZEPHIR_IS_LONG(&exprType, '=')) { goto zephir_switch_0_clause_1; }
		if (ZEPHIR_IS_LONG(&exprType, '>')) { goto zephir_switch_0_clause_2; }
		if (ZEPHIR_IS_LONG(&exprType, 270)) { goto zephir_switch_0_clause_3; }
		if (ZEPHIR_IS_LONG(&exprType, 271)) { goto zephir_switch_0_clause_4; }
		if (ZEPHIR_IS_LONG(&exprType, 272)) { goto zephir_switch_0_clause_5; }
		if (ZEPHIR_IS_LONG(&exprType, 266)) { goto zephir_switch_0_clause_6; }
		if (ZEPHIR_IS_LONG(&exprType, 267)) { goto zephir_switch_0_clause_7; }
		if (ZEPHIR_IS_LONG(&exprType, 401)) { goto zephir_switch_0_clause_8; }
		if (ZEPHIR_IS_LONG(&exprType, 402)) { goto zephir_switch_0_clause_9; }
		if (ZEPHIR_IS_LONG(&exprType, 403)) { goto zephir_switch_0_clause_10; }
		if (ZEPHIR_IS_LONG(&exprType, 404)) { goto zephir_switch_0_clause_11; }
		if (ZEPHIR_IS_LONG(&exprType, 405)) { goto zephir_switch_0_clause_12; }
		if (ZEPHIR_IS_LONG(&exprType, 406)) { goto zephir_switch_0_clause_13; }
		if (ZEPHIR_IS_LONG(&exprType, 416)) { goto zephir_switch_0_clause_14; }
		if (ZEPHIR_IS_LONG(&exprType, 417)) { goto zephir_switch_0_clause_15; }
		if (ZEPHIR_IS_LONG(&exprType, 418)) { goto zephir_switch_0_clause_16; }
		if (ZEPHIR_IS_LONG(&exprType, 355)) { goto zephir_switch_0_clause_17; }
		if (ZEPHIR_IS_LONG(&exprType, '+')) { goto zephir_switch_0_clause_18; }
		if (ZEPHIR_IS_LONG(&exprType, '-')) { goto zephir_switch_0_clause_19; }
		if (ZEPHIR_IS_LONG(&exprType, '*')) { goto zephir_switch_0_clause_20; }
		if (ZEPHIR_IS_LONG(&exprType, '/')) { goto zephir_switch_0_clause_21; }
		if (ZEPHIR_IS_LONG(&exprType, '%')) { goto zephir_switch_0_clause_22; }
		if (ZEPHIR_IS_LONG(&exprType, '&')) { goto zephir_switch_0_clause_23; }
		if (ZEPHIR_IS_LONG(&exprType, '|')) { goto zephir_switch_0_clause_24; }
		if (ZEPHIR_IS_LONG(&exprType, 356)) { goto zephir_switch_0_clause_25; }
		if (ZEPHIR_IS_LONG(&exprType, 407)) { goto zephir_switch_0_clause_26; }
		if (ZEPHIR_IS_LONG(&exprType, 367)) { goto zephir_switch_0_clause_27; }
		if (ZEPHIR_IS_LONG(&exprType, 258)) { goto zephir_switch_0_clause_28; }
		if (ZEPHIR_IS_LONG(&exprType, 259)) { goto zephir_switch_0_clause_29; }
		if (ZEPHIR_IS_LONG(&exprType, 414)) { goto zephir_switch_0_clause_30; }
		if (ZEPHIR_IS_LONG(&exprType, 334)) { goto zephir_switch_0_clause_31; }
		if (ZEPHIR_IS_LONG(&exprType, 335)) { goto zephir_switch_0_clause_32; }
		if (ZEPHIR_IS_LONG(&exprType, 260)) { goto zephir_switch_0_clause_33; }
		if (ZEPHIR_IS_LONG(&exprType, 273)) { goto zephir_switch_0_clause_34; }
		if (ZEPHIR_IS_LONG(&exprType, 274)) { goto zephir_switch_0_clause_35; }
		if (ZEPHIR_IS_LONG(&exprType, 277)) { goto zephir_switch_0_clause_36; }
		if (ZEPHIR_IS_LONG(&exprType, 322)) { goto zephir_switch_0_clause_37; }
		if (ZEPHIR_IS_LONG(&exprType, 268)) { goto zephir_switch_0_clause_38; }
		if (ZEPHIR_IS_LONG(&exprType, 351)) { goto zephir_switch_0_clause_39; }
		if (ZEPHIR_IS_LONG(&exprType, 275)) { goto zephir_switch_0_clause_40; }
		if (ZEPHIR_IS_LONG(&exprType, 357)) { goto zephir_switch_0_clause_41; }
		if (ZEPHIR_IS_LONG(&exprType, '!')) { goto zephir_switch_0_clause_42; }
		if (ZEPHIR_IS_LONG(&exprType, 365)) { goto zephir_switch_0_clause_43; }
		if (ZEPHIR_IS_LONG(&exprType, 366)) { goto zephir_switch_0_clause_44; }
		if (ZEPHIR_IS_LONG(&exprType, 315)) { goto zephir_switch_0_clause_45; }
		if (ZEPHIR_IS_LONG(&exprType, 323)) { goto zephir_switch_0_clause_46; }
		if (ZEPHIR_IS_LONG(&exprType, 408)) { goto zephir_switch_0_clause_47; }
		if (ZEPHIR_IS_LONG(&exprType, 330)) { goto zephir_switch_0_clause_48; }
		if (ZEPHIR_IS_LONG(&exprType, 332)) { goto zephir_switch_0_clause_49; }
		if (ZEPHIR_IS_LONG(&exprType, 331)) { goto zephir_switch_0_clause_50; }
		if (ZEPHIR_IS_LONG(&exprType, 276)) { goto zephir_switch_0_clause_51; }
		if (ZEPHIR_IS_LONG(&exprType, 333)) { goto zephir_switch_0_clause_52; }
		if (ZEPHIR_IS_LONG(&exprType, 336)) { goto zephir_switch_0_clause_53; }
		if (ZEPHIR_IS_LONG(&exprType, 358)) { goto zephir_switch_0_clause_54; }
		if (ZEPHIR_IS_LONG(&exprType, 350)) { goto zephir_switch_0_clause_55; }
		if (ZEPHIR_IS_LONG(&exprType, 409)) { goto zephir_switch_0_clause_56; }
		if (ZEPHIR_IS_LONG(&exprType, 309)) { goto zephir_switch_0_clause_57; }
		goto zephir_switch_0_clause_58;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_VAR(&_2$$7);
			zephir_create_array(&_2$$7, 4, 0);
			add_assoc_stringl_ex(&_2$$7, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_2$$7, SL("op"), SL("<"));
			zephir_array_update_string(&_2$$7, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2$$7, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_2$$7);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_VAR(&_3$$8);
			zephir_create_array(&_3$$8, 4, 0);
			add_assoc_stringl_ex(&_3$$8, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_3$$8, SL("op"), SL("="));
			zephir_array_update_string(&_3$$8, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_3$$8, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_3$$8);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_VAR(&_4$$9);
			zephir_create_array(&_4$$9, 4, 0);
			add_assoc_stringl_ex(&_4$$9, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_4$$9, SL("op"), SL(">"));
			zephir_array_update_string(&_4$$9, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$9, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_4$$9);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_VAR(&_5$$10);
			zephir_create_array(&_5$$10, 4, 0);
			add_assoc_stringl_ex(&_5$$10, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_5$$10, SL("op"), SL("<>"));
			zephir_array_update_string(&_5$$10, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$10, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_5$$10);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_4: ;
			ZEPHIR_INIT_VAR(&_6$$11);
			zephir_create_array(&_6$$11, 4, 0);
			add_assoc_stringl_ex(&_6$$11, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_6$$11, SL("op"), SL("<="));
			zephir_array_update_string(&_6$$11, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$11, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_6$$11);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_5: ;
			ZEPHIR_INIT_VAR(&_7$$12);
			zephir_create_array(&_7$$12, 4, 0);
			add_assoc_stringl_ex(&_7$$12, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_7$$12, SL("op"), SL(">="));
			zephir_array_update_string(&_7$$12, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$12, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_7$$12);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_6: ;
			ZEPHIR_INIT_VAR(&_8$$13);
			zephir_create_array(&_8$$13, 4, 0);
			add_assoc_stringl_ex(&_8$$13, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_8$$13, SL("op"), SL("AND"));
			zephir_array_update_string(&_8$$13, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8$$13, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_8$$13);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_7: ;
			ZEPHIR_INIT_VAR(&_9$$14);
			zephir_create_array(&_9$$14, 4, 0);
			add_assoc_stringl_ex(&_9$$14, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_9$$14, SL("op"), SL("OR"));
			zephir_array_update_string(&_9$$14, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_9$$14, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_9$$14);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_8: ;
			ZEPHIR_INIT_VAR(&_10$$15);
			zephir_create_array(&_10$$15, 4, 0);
			add_assoc_stringl_ex(&_10$$15, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_10$$15, SL("op"), SL("@@"));
			zephir_array_update_string(&_10$$15, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$15, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_10$$15);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_9: ;
			ZEPHIR_INIT_VAR(&_11$$16);
			zephir_create_array(&_11$$16, 4, 0);
			add_assoc_stringl_ex(&_11$$16, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_11$$16, SL("op"), SL("@>"));
			zephir_array_update_string(&_11$$16, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$16, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_11$$16);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_10: ;
			ZEPHIR_INIT_VAR(&_12$$17);
			zephir_create_array(&_12$$17, 4, 0);
			add_assoc_stringl_ex(&_12$$17, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_12$$17, SL("op"), SL("<@"));
			zephir_array_update_string(&_12$$17, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_12$$17, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_12$$17);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_11: ;
			ZEPHIR_INIT_VAR(&_13$$18);
			zephir_create_array(&_13$$18, 4, 0);
			add_assoc_stringl_ex(&_13$$18, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_13$$18, SL("op"), SL("&&"));
			zephir_array_update_string(&_13$$18, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$18, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_13$$18);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_12: ;
			ZEPHIR_INIT_VAR(&_14$$19);
			zephir_create_array(&_14$$19, 4, 0);
			add_assoc_stringl_ex(&_14$$19, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_14$$19, SL("op"), SL("||"));
			zephir_array_update_string(&_14$$19, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$19, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_14$$19);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_13: ;
			ZEPHIR_INIT_VAR(&_15$$20);
			zephir_create_array(&_15$$20, 4, 0);
			add_assoc_stringl_ex(&_15$$20, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_15$$20, SL("op"), SL("->"));
			zephir_array_update_string(&_15$$20, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$20, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_15$$20);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_14: ;
			ZEPHIR_INIT_VAR(&_16$$21);
			zephir_create_array(&_16$$21, 4, 0);
			add_assoc_stringl_ex(&_16$$21, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_16$$21, SL("op"), SL("->>"));
			zephir_array_update_string(&_16$$21, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$21, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_16$$21);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_15: ;
			ZEPHIR_INIT_VAR(&_17$$22);
			zephir_create_array(&_17$$22, 4, 0);
			add_assoc_stringl_ex(&_17$$22, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_17$$22, SL("op"), SL("#>"));
			zephir_array_update_string(&_17$$22, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_17$$22, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_17$$22);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_16: ;
			ZEPHIR_INIT_VAR(&_18$$23);
			zephir_create_array(&_18$$23, 4, 0);
			add_assoc_stringl_ex(&_18$$23, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_18$$23, SL("op"), SL("#>>"));
			zephir_array_update_string(&_18$$23, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_18$$23, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_18$$23);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_17: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getqualified", NULL, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_18: ;
			ZEPHIR_INIT_VAR(&_19$$25);
			zephir_create_array(&_19$$25, 4, 0);
			add_assoc_stringl_ex(&_19$$25, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_19$$25, SL("op"), SL("+"));
			zephir_array_update_string(&_19$$25, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_19$$25, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_19$$25);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_19: ;
			ZEPHIR_INIT_VAR(&_20$$26);
			zephir_create_array(&_20$$26, 4, 0);
			add_assoc_stringl_ex(&_20$$26, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_20$$26, SL("op"), SL("-"));
			zephir_array_update_string(&_20$$26, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_20$$26, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_20$$26);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_20: ;
			ZEPHIR_INIT_VAR(&_21$$27);
			zephir_create_array(&_21$$27, 4, 0);
			add_assoc_stringl_ex(&_21$$27, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_21$$27, SL("op"), SL("*"));
			zephir_array_update_string(&_21$$27, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_21$$27, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_21$$27);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_21: ;
			ZEPHIR_INIT_VAR(&_22$$28);
			zephir_create_array(&_22$$28, 4, 0);
			add_assoc_stringl_ex(&_22$$28, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_22$$28, SL("op"), SL("/"));
			zephir_array_update_string(&_22$$28, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_22$$28, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_22$$28);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_22: ;
			ZEPHIR_INIT_VAR(&_23$$29);
			zephir_create_array(&_23$$29, 4, 0);
			add_assoc_stringl_ex(&_23$$29, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_23$$29, SL("op"), SL("%"));
			zephir_array_update_string(&_23$$29, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_23$$29, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_23$$29);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_23: ;
			ZEPHIR_INIT_VAR(&_24$$30);
			zephir_create_array(&_24$$30, 4, 0);
			add_assoc_stringl_ex(&_24$$30, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_24$$30, SL("op"), SL("&"));
			zephir_array_update_string(&_24$$30, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_24$$30, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_24$$30);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_24: ;
			ZEPHIR_INIT_VAR(&_25$$31);
			zephir_create_array(&_25$$31, 4, 0);
			add_assoc_stringl_ex(&_25$$31, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_25$$31, SL("op"), SL("|"));
			zephir_array_update_string(&_25$$31, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_25$$31, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_25$$31);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_25: ;
		zephir_switch_0_clause_26: ;
			ZEPHIR_INIT_VAR(&_26$$32);
			zephir_create_array(&_26$$32, 2, 0);
			add_assoc_stringl_ex(&_26$$32, SL("type"), SL("parentheses"));
			zephir_array_update_string(&_26$$32, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_26$$32);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_27: ;
			ZEPHIR_INIT_VAR(&_27$$33);
			zephir_create_array(&_27$$33, 3, 0);
			add_assoc_stringl_ex(&_27$$33, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_27$$33, SL("op"), SL("-"));
			zephir_array_update_string(&_27$$33, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_27$$33);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_28: ;
		zephir_switch_0_clause_29: ;
		zephir_switch_0_clause_30: ;
			ZEPHIR_INIT_VAR(&_28$$34);
			zephir_create_array(&_28$$34, 2, 0);
			add_assoc_stringl_ex(&_28$$34, SL("type"), SL("literal"));
			zephir_memory_observe(&_29$$34);
			zephir_array_fetch_string(&_29$$34, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2076);
			zephir_array_update_string(&_28$$34, SL("value"), &_29$$34, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_28$$34);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_31: ;
			ZEPHIR_INIT_VAR(&_30$$35);
			zephir_create_array(&_30$$35, 2, 0);
			add_assoc_stringl_ex(&_30$$35, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_30$$35, SL("value"), SL("TRUE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_30$$35);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_32: ;
			ZEPHIR_INIT_VAR(&_31$$36);
			zephir_create_array(&_31$$36, 2, 0);
			add_assoc_stringl_ex(&_31$$36, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_31$$36, SL("value"), SL("FALSE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_31$$36);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_33: ;
			zephir_memory_observe(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2097);
			ZEPHIR_INIT_NVAR(&exprReturn);
			if (quoting) {
				ZEPHIR_INIT_VAR(&_32$$38);
				zephir_create_array(&_32$$38, 3, 0);
				add_assoc_stringl_ex(&_32$$38, SL("type"), SL("literal"));
				zephir_array_update_string(&_32$$38, SL("value"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_32$$38, SL("escape"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_32$$38);
			} else {
				ZEPHIR_INIT_VAR(&_33$$39);
				zephir_create_array(&_33$$39, 2, 0);
				add_assoc_stringl_ex(&_33$$39, SL("type"), SL("literal"));
				zephir_array_update_string(&_33$$39, SL("value"), &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_33$$39);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_34: ;
			ZEPHIR_INIT_VAR(&_34$$40);
			zephir_create_array(&_34$$40, 2, 0);
			add_assoc_stringl_ex(&_34$$40, SL("type"), SL("placeholder"));
			ZEPHIR_INIT_VAR(&_35$$40);
			zephir_array_fetch_string(&_36$$40, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2123);
			ZEPHIR_INIT_VAR(&_37$$40);
			ZVAL_STRING(&_37$$40, "?");
			ZEPHIR_INIT_VAR(&_38$$40);
			ZVAL_STRING(&_38$$40, ":");
			zephir_fast_str_replace(&_35$$40, &_37$$40, &_38$$40, &_36$$40);
			zephir_array_update_string(&_34$$40, SL("value"), &_35$$40, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_34$$40);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_35: ;
			ZEPHIR_INIT_VAR(&_39$$41);
			zephir_create_array(&_39$$41, 2, 0);
			add_assoc_stringl_ex(&_39$$41, SL("type"), SL("placeholder"));
			zephir_array_fetch_string(&_40$$41, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2132);
			ZEPHIR_INIT_VAR(&_41$$41);
			ZEPHIR_CONCAT_SV(&_41$$41, ":", &_40$$41);
			zephir_array_update_string(&_39$$41, SL("value"), &_41$$41, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_39$$41);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_36: ;
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2137);
			if (zephir_memnstr_str(&value, SL(":"), "phalcon/Mvc/Model/Query.zep", 2139)) {
				ZEPHIR_INIT_VAR(&valueParts);
				zephir_fast_explode_str(&valueParts, SL(":"), &value, LONG_MAX);
				zephir_memory_observe(&name);
				zephir_array_fetch_long(&name, &valueParts, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2141);
				zephir_memory_observe(&bindType);
				zephir_array_fetch_long(&bindType, &valueParts, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2142);
				if (ZEPHIR_IS_STRING(&bindType, "str")) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_STRING(&bindType, "int")) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_STRING(&bindType, "double")) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_STRING(&bindType, "bool")) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_STRING(&bindType, "blob")) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_STRING(&bindType, "null")) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_STRING(&bindType, "array")) { goto zephir_switch_1_clause_6; }
				if (ZEPHIR_IS_STRING(&bindType, "array-str")) { goto zephir_switch_1_clause_7; }
				if (ZEPHIR_IS_STRING(&bindType, "array-int")) { goto zephir_switch_1_clause_8; }
				goto zephir_switch_1_clause_9;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_VAR(&_42$$44);
					ZVAL_LONG(&_42$$44, 2);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_42$$44);
					ZEPHIR_INIT_VAR(&_43$$44);
					zephir_create_array(&_43$$44, 2, 0);
					add_assoc_stringl_ex(&_43$$44, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_44$$44);
					ZEPHIR_CONCAT_SV(&_44$$44, ":", &name);
					zephir_array_update_string(&_43$$44, SL("value"), &_44$$44, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_43$$44);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_VAR(&_45$$45);
					ZVAL_LONG(&_45$$45, 1);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_45$$45);
					ZEPHIR_INIT_VAR(&_46$$45);
					zephir_create_array(&_46$$45, 2, 0);
					add_assoc_stringl_ex(&_46$$45, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_47$$45);
					ZEPHIR_CONCAT_SV(&_47$$45, ":", &name);
					zephir_array_update_string(&_46$$45, SL("value"), &_47$$45, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_46$$45);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_VAR(&_48$$46);
					ZVAL_LONG(&_48$$46, 32);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_48$$46);
					ZEPHIR_INIT_VAR(&_49$$46);
					zephir_create_array(&_49$$46, 2, 0);
					add_assoc_stringl_ex(&_49$$46, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_50$$46);
					ZEPHIR_CONCAT_SV(&_50$$46, ":", &name);
					zephir_array_update_string(&_49$$46, SL("value"), &_50$$46, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_49$$46);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_VAR(&_51$$47);
					ZVAL_LONG(&_51$$47, 5);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_51$$47);
					ZEPHIR_INIT_VAR(&_52$$47);
					zephir_create_array(&_52$$47, 2, 0);
					add_assoc_stringl_ex(&_52$$47, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_53$$47);
					ZEPHIR_CONCAT_SV(&_53$$47, ":", &name);
					zephir_array_update_string(&_52$$47, SL("value"), &_53$$47, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_52$$47);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_VAR(&_54$$48);
					ZVAL_LONG(&_54$$48, 3);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_54$$48);
					ZEPHIR_INIT_VAR(&_55$$48);
					zephir_create_array(&_55$$48, 2, 0);
					add_assoc_stringl_ex(&_55$$48, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_56$$48);
					ZEPHIR_CONCAT_SV(&_56$$48, ":", &name);
					zephir_array_update_string(&_55$$48, SL("value"), &_56$$48, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_55$$48);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_VAR(&_57$$49);
					ZVAL_LONG(&_57$$49, 0);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_57$$49);
					ZEPHIR_INIT_VAR(&_58$$49);
					zephir_create_array(&_58$$49, 2, 0);
					add_assoc_stringl_ex(&_58$$49, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_59$$49);
					ZEPHIR_CONCAT_SV(&_59$$49, ":", &name);
					zephir_array_update_string(&_58$$49, SL("value"), &_59$$49, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_58$$49);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
				zephir_switch_1_clause_7: ;
				zephir_switch_1_clause_8: ;
					zephir_memory_observe(&bind);
					zephir_read_property_cached(&_60$$50, this_ptr, _zephir_prop_0, 1056, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&bind, &_60$$50, &name, 0)))) {
						ZEPHIR_INIT_VAR(&_61$$51);
						object_init_ex(&_61$$51, phalcon_mvc_model_query_exceptions_bindvaluerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_61$$51, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_61$$51, "phalcon/Mvc/Model/Query.zep", 2210);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(Z_TYPE_P(&bind) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(&_62$$52);
						object_init_ex(&_62$$52, phalcon_mvc_model_query_exceptions_bindtyperequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_62$$52, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_62$$52, "phalcon/Mvc/Model/Query.zep", 2214);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(ZEPHIR_IS_EMPTY(&bind))) {
						ZEPHIR_INIT_VAR(&_63$$53);
						object_init_ex(&_63$$53, phalcon_mvc_model_query_exceptions_emptyarrayplaceholdervalue_ce);
						ZEPHIR_CALL_METHOD(NULL, &_63$$53, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_63$$53, "phalcon/Mvc/Model/Query.zep", 2218);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_64$$50);
					zephir_create_array(&_64$$50, 4, 0);
					add_assoc_stringl_ex(&_64$$50, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_65$$50);
					ZEPHIR_CONCAT_SV(&_65$$50, ":", &name);
					zephir_array_update_string(&_64$$50, SL("value"), &_65$$50, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_64$$50, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
					add_assoc_long_ex(&_64$$50, SL("times"), zephir_fast_count_int(&bind));
					ZEPHIR_CPY_WRT(&exprReturn, &_64$$50);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_VAR(&_66$$54);
					object_init_ex(&_66$$54, phalcon_mvc_model_query_exceptions_unknownbindtype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_66$$54, "__construct", NULL, 0, &bindType);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_66$$54, "phalcon/Mvc/Model/Query.zep", 2231);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

			} else {
				ZEPHIR_INIT_VAR(&_67$$55);
				zephir_create_array(&_67$$55, 2, 0);
				add_assoc_stringl_ex(&_67$$55, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_68$$55);
				ZEPHIR_CONCAT_SV(&_68$$55, ":", &value);
				zephir_array_update_string(&_67$$55, SL("value"), &_68$$55, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_67$$55);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_37: ;
			ZEPHIR_INIT_VAR(&_69$$56);
			zephir_create_array(&_69$$56, 2, 0);
			add_assoc_stringl_ex(&_69$$56, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_69$$56, SL("value"), SL("NULL"));
			ZEPHIR_CPY_WRT(&exprReturn, &_69$$56);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_38: ;
			ZEPHIR_INIT_VAR(&_70$$57);
			zephir_create_array(&_70$$57, 4, 0);
			add_assoc_stringl_ex(&_70$$57, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_70$$57, SL("op"), SL("LIKE"));
			zephir_array_update_string(&_70$$57, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_70$$57, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_70$$57);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_39: ;
			ZEPHIR_INIT_VAR(&_71$$58);
			zephir_create_array(&_71$$58, 4, 0);
			add_assoc_stringl_ex(&_71$$58, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_71$$58, SL("op"), SL("NOT LIKE"));
			zephir_array_update_string(&_71$$58, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_71$$58, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_71$$58);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_40: ;
			ZEPHIR_INIT_VAR(&_72$$59);
			zephir_create_array(&_72$$59, 4, 0);
			add_assoc_stringl_ex(&_72$$59, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_72$$59, SL("op"), SL("ILIKE"));
			zephir_array_update_string(&_72$$59, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_72$$59, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_72$$59);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_41: ;
			ZEPHIR_INIT_VAR(&_73$$60);
			zephir_create_array(&_73$$60, 4, 0);
			add_assoc_stringl_ex(&_73$$60, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_73$$60, SL("op"), SL("NOT ILIKE"));
			zephir_array_update_string(&_73$$60, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_73$$60, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_73$$60);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_42: ;
			ZEPHIR_INIT_VAR(&_74$$61);
			zephir_create_array(&_74$$61, 3, 0);
			add_assoc_stringl_ex(&_74$$61, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_74$$61, SL("op"), SL("NOT "));
			zephir_array_update_string(&_74$$61, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_74$$61);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_43: ;
			ZEPHIR_INIT_VAR(&_75$$62);
			zephir_create_array(&_75$$62, 3, 0);
			add_assoc_stringl_ex(&_75$$62, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_75$$62, SL("op"), SL(" IS NULL"));
			zephir_array_update_string(&_75$$62, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_75$$62);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_44: ;
			ZEPHIR_INIT_VAR(&_76$$63);
			zephir_create_array(&_76$$63, 3, 0);
			add_assoc_stringl_ex(&_76$$63, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_76$$63, SL("op"), SL(" IS NOT NULL"));
			zephir_array_update_string(&_76$$63, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_76$$63);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_45: ;
			ZEPHIR_INIT_VAR(&_77$$64);
			zephir_create_array(&_77$$64, 4, 0);
			add_assoc_stringl_ex(&_77$$64, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_77$$64, SL("op"), SL("IN"));
			zephir_array_update_string(&_77$$64, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_77$$64, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_77$$64);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_46: ;
			ZEPHIR_INIT_VAR(&_78$$65);
			zephir_create_array(&_78$$65, 4, 0);
			add_assoc_stringl_ex(&_78$$65, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_78$$65, SL("op"), SL("NOT IN"));
			zephir_array_update_string(&_78$$65, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_78$$65, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_78$$65);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_47: ;
			ZEPHIR_INIT_VAR(&_79$$66);
			zephir_create_array(&_79$$66, 3, 0);
			add_assoc_stringl_ex(&_79$$66, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_79$$66, SL("op"), SL("EXISTS"));
			zephir_array_update_string(&_79$$66, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_79$$66);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_48: ;
			ZEPHIR_INIT_VAR(&_80$$67);
			zephir_create_array(&_80$$67, 3, 0);
			add_assoc_stringl_ex(&_80$$67, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_80$$67, SL("op"), SL("DISTINCT "));
			zephir_array_update_string(&_80$$67, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_80$$67);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_49: ;
			ZEPHIR_INIT_VAR(&_81$$68);
			zephir_create_array(&_81$$68, 4, 0);
			add_assoc_stringl_ex(&_81$$68, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_81$$68, SL("op"), SL("NOT BETWEEN"));
			zephir_array_update_string(&_81$$68, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_81$$68, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_81$$68);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_50: ;
			ZEPHIR_INIT_VAR(&_82$$69);
			zephir_create_array(&_82$$69, 4, 0);
			add_assoc_stringl_ex(&_82$$69, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_82$$69, SL("op"), SL("BETWEEN"));
			zephir_array_update_string(&_82$$69, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_82$$69, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_82$$69);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_51: ;
			ZEPHIR_INIT_VAR(&_83$$70);
			zephir_create_array(&_83$$70, 4, 0);
			add_assoc_stringl_ex(&_83$$70, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_83$$70, SL("op"), SL("AGAINST"));
			zephir_array_update_string(&_83$$70, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_83$$70, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_83$$70);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_52: ;
			ZEPHIR_INIT_VAR(&_84$$71);
			zephir_create_array(&_84$$71, 3, 0);
			add_assoc_stringl_ex(&_84$$71, SL("type"), SL("cast"));
			zephir_array_update_string(&_84$$71, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_84$$71, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_84$$71);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_53: ;
			ZEPHIR_INIT_VAR(&_85$$72);
			zephir_create_array(&_85$$72, 3, 0);
			add_assoc_stringl_ex(&_85$$72, SL("type"), SL("convert"));
			zephir_array_update_string(&_85$$72, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_85$$72, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_85$$72);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_54: ;
			ZEPHIR_INIT_VAR(&_86$$73);
			zephir_array_fetch_string(&_87$$73, &expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2409);
			ZEPHIR_INIT_VAR(&_88$$73);
			ZVAL_STRING(&_88$$73, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			ZEPHIR_INIT_VAR(&_89$$73);
			ZEPHIR_INIT_VAR(&_90$$73);
			ZVAL_STRING(&_90$$73, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			zephir_preg_match(&_89$$73, &_90$$73, &_87$$73, &_86$$73, 0, 0 , 0 );
			if (UNEXPECTED(!zephir_is_true(&_89$$73))) {
				ZEPHIR_INIT_VAR(&_91$$74);
				object_init_ex(&_91$$74, phalcon_mvc_model_query_exceptions_unsafeidentifier_ce);
				zephir_array_fetch_string(&_92$$74, &expr, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2410);
				zephir_read_property_cached(&_93$$74, this_ptr, _zephir_prop_1, 1054, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_91$$74, "__construct", NULL, 0, &_92$$74, &_93$$74);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_91$$74, "phalcon/Mvc/Model/Query.zep", 2410);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_94$$73);
			zephir_create_array(&_94$$73, 2, 0);
			add_assoc_stringl_ex(&_94$$73, SL("type"), SL("literal"));
			zephir_memory_observe(&_95$$73);
			zephir_array_fetch_string(&_95$$73, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2416);
			zephir_array_update_string(&_94$$73, SL("value"), &_95$$73, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_94$$73);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_55: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getfunctioncall", NULL, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_56: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getcaseexpression", NULL, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_57: ;
			ZEPHIR_INIT_VAR(&_96$$77);
			zephir_create_array(&_96$$77, 2, 0);
			add_assoc_stringl_ex(&_96$$77, SL("type"), SL("select"));
			ZVAL_BOOL(&_98$$77, 1);
			ZEPHIR_CALL_METHOD(&_97$$77, this_ptr, "prepareselect", NULL, 0, &expr, &_98$$77);
			zephir_check_call_status();
			zephir_array_update_string(&_96$$77, SL("value"), &_97$$77, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_96$$77);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_58: ;
			ZEPHIR_INIT_VAR(&_99$$78);
			object_init_ex(&_99$$78, phalcon_mvc_model_query_exceptions_unknownphqlexpressiontype_ce);
			ZEPHIR_CALL_METHOD(NULL, &_99$$78, "__construct", NULL, 0, &exprType);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_99$$78, "phalcon/Mvc/Model/Query.zep", 2439);
			ZEPHIR_MM_RESTORE();
			return;
		zephir_switch_0_end: ;

		RETURN_CCTOR(&exprReturn);
	}
	if (zephir_array_isset_value_string(&expr, SL("domain"))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getqualified", NULL, 0, &expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_array_isset_value_long(&expr, 0)) {
		ZEPHIR_INIT_VAR(&listItems);
		array_init(&listItems);
		zephir_is_iterable(&expr, 0, "phalcon/Mvc/Model/Query.zep", 2462);
		if (Z_TYPE_P(&expr) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _100$$80)
			{
				ZEPHIR_INIT_NVAR(&exprListItem);
				ZVAL_COPY(&exprListItem, _100$$80);
				ZEPHIR_CALL_METHOD(&_101$$81, this_ptr, "getexpression", NULL, 0, &exprListItem);
				zephir_check_call_status();
				zephir_array_append(&listItems, &_101$$81, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2459);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &expr, "rewind", NULL, 0);
			zephir_check_call_status();
			_103$$80 = 1;
			while (1) {
				if (_103$$80) {
					_103$$80 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &expr, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_102$$80, &expr, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_102$$80)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&exprListItem, &expr, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_104$$82, this_ptr, "getexpression", NULL, 0, &exprListItem);
					zephir_check_call_status();
					zephir_array_append(&listItems, &_104$$82, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2459);
			}
		}
		ZEPHIR_INIT_NVAR(&exprListItem);
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("list"));
		zephir_array_fast_append(return_value, &listItems);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_105);
	object_init_ex(&_105, phalcon_mvc_model_query_exceptions_unknownphqlexpression_ce);
	ZEPHIR_CALL_METHOD(NULL, &_105, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_105, "phalcon/Mvc/Model/Query.zep", 2468);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getFunctionCall)
{
	zend_bool _12$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, name, _0, _1, _2, _3, _19, _4$$3, _5$$3, *_6$$7, _7$$7, *_8$$7, _11$$7, _9$$8, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11, _18$$12;
	zval expr, functionArgs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&functionArgs);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("phql", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	zephir_memory_observe(&name);
	zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2480);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
	zephir_preg_match(&_2, &_3, &name, &_0, 0, 0 , 0 );
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, phalcon_mvc_model_query_exceptions_unsafeidentifier_ce);
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 1054, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0, &name, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Mvc/Model/Query.zep", 2487);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&arguments);
	if (zephir_array_isset_string_fetch(&arguments, &expr, SL("arguments"), 0)) {
		if (zephir_array_isset_value_string(&expr, SL("distinct"))) {
			distinct = 1;
		} else {
			distinct = 0;
		}
		if (zephir_array_isset_value_long(&arguments, 0)) {
			ZEPHIR_INIT_VAR(&functionArgs);
			array_init(&functionArgs);
			if (Z_TYPE_P(&arguments) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_7$$7);
				zephir_string_to_char_array(&_7$$7, &arguments);
				_6$$7 = &_7$$7;
			} else {
				_6$$7 = &arguments;
			}
			zephir_is_iterable(_6$$7, 0, "phalcon/Mvc/Model/Query.zep", 2504);
			if (Z_TYPE_P(_6$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6$$7), _8$$7)
				{
					ZEPHIR_INIT_NVAR(&argument);
					ZVAL_COPY(&argument, _8$$7);
					ZEPHIR_CALL_METHOD(&_9$$8, this_ptr, "getcallargument", &_10, 0, &argument);
					zephir_check_call_status();
					zephir_array_append(&functionArgs, &_9$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2502);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				_12$$7 = 1;
				while (1) {
					if (_12$$7) {
						_12$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _6$$7, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_11$$7, _6$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_11$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&argument, _6$$7, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "getcallargument", &_10, 0, &argument);
						zephir_check_call_status();
						zephir_array_append(&functionArgs, &_13$$9, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2502);
				}
			}
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			ZEPHIR_INIT_VAR(&_14$$10);
			zephir_create_array(&_14$$10, 1, 0);
			ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "getcallargument", &_10, 0, &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&_14$$10, &_15$$10);
			ZEPHIR_CPY_WRT(&functionArgs, &_14$$10);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_16$$11);
			zephir_array_fetch_string(&_16$$11, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2514);
			zephir_array_update_string(return_value, SL("name"), &_16$$11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_17$$11);
			ZVAL_LONG(&_17$$11, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_17$$11, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_18$$12);
			zephir_array_fetch_string(&_18$$12, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2521);
			zephir_array_update_string(return_value, SL("name"), &_18$$12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	zephir_memory_observe(&_19);
	zephir_array_fetch_string(&_19, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2530);
	zephir_array_update_string(return_value, SL("name"), &_19, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Returns a processed group clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getGroupClause)
{
	zend_bool _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, *_0$$3, _3$$3, _1$$4, _5$$5, _6$$6, _7$$6;
	zval group, groupParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(group, group_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group_param);
	zephir_get_arrval(&group, group_param);
	if (zephir_array_isset_value_long(&group, 0)) {
		ZEPHIR_INIT_VAR(&groupParts);
		array_init(&groupParts);
		zephir_is_iterable(&group, 0, "phalcon/Mvc/Model/Query.zep", 2550);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _0$$3);
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getexpression", &_2, 0, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupParts, &_1$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2548);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_3$$3, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "getexpression", &_2, 0, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupParts, &_5$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2548);
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		ZEPHIR_INIT_VAR(&_6$$6);
		zephir_create_array(&_6$$6, 1, 0);
		ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "getexpression", &_2, 0, &group);
		zephir_check_call_status();
		zephir_array_fast_append(&_6$$6, &_7$$6);
		ZEPHIR_CPY_WRT(&groupParts, &_6$$6);
	}
	RETURN_CTOR(&groupParts);
}

/**
 * Resolves a JOIN clause checking if the associated models exist
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoin)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval join;
	zval *manager, manager_sub, *join_param = NULL, qualified, modelName, source, model, schema, _1, _0$$3;

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&qualified);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&join);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_mvc_model_managerinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(join, join_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &manager, &join_param);
	zephir_get_arrval(&join, join_param);
	zephir_memory_observe(&qualified);
	if (zephir_array_isset_string_fetch(&qualified, &join, SL("qualified"), 0)) {
		zephir_array_fetch_string(&_0$$3, &qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2567);
		if (ZEPHIR_IS_LONG(&_0$$3, 355)) {
			zephir_memory_observe(&modelName);
			zephir_array_fetch_string(&modelName, &qualified, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2568);
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			zephir_create_array(return_value, 4, 0);
			zephir_array_update_string(return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("modelName"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model/Query.zep", 2583);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves a JOIN type
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoinType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *join_param = NULL, type, _1, _2, _0$$3;
	zval join;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("phql", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(join, join_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &join_param);
	zephir_get_arrval(&join, join_param);
	zephir_memory_observe(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &join, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 2594);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&type, 360)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&type, 361)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&type, 362)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&type, 363)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&type, 364)) { goto zephir_switch_0_clause_4; }
	goto zephir_switch_0_end;
	zephir_switch_0_clause_0: ;
		RETURN_MM_STRING("INNER");
	zephir_switch_0_clause_1: ;
		RETURN_MM_STRING("LEFT");
	zephir_switch_0_clause_2: ;
		RETURN_MM_STRING("RIGHT");
	zephir_switch_0_clause_3: ;
		RETURN_MM_STRING("CROSS");
	zephir_switch_0_clause_4: ;
		RETURN_MM_STRING("FULL OUTER");
	zephir_switch_0_end: ;

	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_query_exceptions_unknownjointype_ce);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1054, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &type, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model/Query.zep", 2614);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Processes the JOINs in the query returning an internal representation for
 * the database dialect
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoins)
{
	zend_string *_20, *_43, *_26$$19, *_46$$23, *_68$$38;
	zend_ulong _19, _42, _25$$19, _45$$23, _67$$38;
	zend_bool _12, _35, _65, _59$$32, _78$$47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_8 = NULL, *_22 = NULL, *_47 = NULL, *_48 = NULL, *_51 = NULL, *_53 = NULL, *_54 = NULL, *_69 = NULL, *_70 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select_param = NULL, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, _0, *_1, _2, *_3, _11, *_18, *_29, _30, *_31, _34, *_38, _39, _40, *_41, _64, _6$$9, _7$$9, _9$$11, _10$$11, _13$$12, _14$$14, _15$$14, _16$$16, _17$$16, _21$$18, _23$$19, *_24$$19, _32$$21, _33$$21, _36$$22, _37$$22, *_44$$23, _49$$28, _50$$28, _52$$29, *_55$$32, _56$$32, *_57$$32, _58$$32, _61$$36, *_66$$38, _71$$43, _72$$43, _73$$44, *_74$$47, _75$$47, *_76$$47, _77$$47, _80$$51;
	zval select, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, _27$$20, _28$$20, _60$$36, _62$$37, _63$$37, _79$$51, _81$$52, _82$$52;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&joinModels);
	ZVAL_UNDEF(&joinSources);
	ZVAL_UNDEF(&joinTypes);
	ZVAL_UNDEF(&joinPreCondition);
	ZVAL_UNDEF(&joinPrepared);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_60$$36);
	ZVAL_UNDEF(&_62$$37);
	ZVAL_UNDEF(&_63$$37);
	ZVAL_UNDEF(&_79$$51);
	ZVAL_UNDEF(&_81$$52);
	ZVAL_UNDEF(&_82$$52);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&fromModels);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&selectJoins);
	ZVAL_UNDEF(&joinItem);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&joinData);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&realModelName);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&joinType);
	ZVAL_UNDEF(&aliasExpr);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&joinAliasName);
	ZVAL_UNDEF(&joinExpr);
	ZVAL_UNDEF(&fromModelName);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joinModel);
	ZVAL_UNDEF(&joinSource);
	ZVAL_UNDEF(&preCondition);
	ZVAL_UNDEF(&modelNameAlias);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&modelAlias);
	ZVAL_UNDEF(&sqlJoin);
	ZVAL_UNDEF(&sqlJoinItem);
	ZVAL_UNDEF(&selectTables);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&tableItem);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_23$$19);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_61$$36);
	ZVAL_UNDEF(&_71$$43);
	ZVAL_UNDEF(&_72$$43);
	ZVAL_UNDEF(&_73$$44);
	ZVAL_UNDEF(&_75$$47);
	ZVAL_UNDEF(&_77$$47);
	ZVAL_UNDEF(&_80$$51);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("sqlAliasesModels", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sqlModelsAliases", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("sqlAliasesModelsInstances", 25, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("enableImplicitJoins", 19, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(select, select_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &select_param);
	zephir_get_arrval(&select, select_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1071, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1073, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModels, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1074, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlModelsAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1075, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1070, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&modelsInstances, &_0);
	ZEPHIR_CPY_WRT(&fromModels, &models);
	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	ZEPHIR_INIT_VAR(&joinModels);
	array_init(&joinModels);
	ZEPHIR_INIT_VAR(&joinSources);
	array_init(&joinSources);
	ZEPHIR_INIT_VAR(&joinTypes);
	array_init(&joinTypes);
	ZEPHIR_INIT_VAR(&joinPreCondition);
	array_init(&joinPreCondition);
	ZEPHIR_INIT_VAR(&joinPrepared);
	array_init(&joinPrepared);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&tables);
	zephir_array_fetch_string(&tables, &select, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2650);
	if (!(zephir_array_isset_value_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectTables);
		zephir_create_array(&selectTables, 1, 0);
		zephir_array_fast_append(&selectTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectTables, &tables);
	}
	zephir_memory_observe(&joins);
	zephir_array_fetch_string(&joins, &select, SL("joins"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2658);
	if (!(zephir_array_isset_value_long(&joins, 0))) {
		ZEPHIR_INIT_VAR(&selectJoins);
		zephir_create_array(&selectJoins, 1, 0);
		zephir_array_fast_append(&selectJoins, &joins);
	} else {
		ZEPHIR_CPY_WRT(&selectJoins, &joins);
	}
	if (Z_TYPE_P(&selectJoins) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &selectJoins);
		_1 = &_2;
	} else {
		_1 = &selectJoins;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 2805);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&joinItem);
			ZVAL_COPY(&joinItem, _3);
			ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getjoin", &_4, 0, &manager, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&source);
			zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2672);
			ZEPHIR_OBS_NVAR(&schema);
			zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2673);
			ZEPHIR_OBS_NVAR(&model);
			zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2674);
			ZEPHIR_OBS_NVAR(&realModelName);
			zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2675);
			ZEPHIR_INIT_NVAR(&completeSource);
			zephir_create_array(&completeSource, 2, 0);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
			ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getjointype", &_5, 0, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&aliasExpr);
			if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2687);
				if (UNEXPECTED(zephir_array_isset_value(&joinModels, &alias))) {
					ZEPHIR_INIT_NVAR(&_6$$9);
					object_init_ex(&_6$$9, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_7$$9, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_6$$9, "__construct", &_8, 0, &alias, &_7$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$9, "phalcon/Mvc/Model/Query.zep", 2693);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2699);
				zephir_array_update_zval(&joinTypes, &alias, &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinSources, &alias, &completeSource, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinPrepared, &alias, &joinItem, PH_COPY | PH_SEPARATE);
			} else {
				if (UNEXPECTED(zephir_array_isset_value(&joinModels, &realModelName))) {
					ZEPHIR_INIT_NVAR(&_9$$11);
					object_init_ex(&_9$$11, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_10$$11, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", &_8, 0, &realModelName, &_10$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model/Query.zep", 2750);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinTypes, &realModelName, &joinType, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinModels, &realModelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinSources, &realModelName, &completeSource, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&joinPrepared, &realModelName, &joinItem, PH_COPY | PH_SEPARATE);
			}
			zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&joinItem, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getjoin", &_4, 0, &manager, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2672);
				ZEPHIR_OBS_NVAR(&schema);
				zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2673);
				ZEPHIR_OBS_NVAR(&model);
				zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2674);
				ZEPHIR_OBS_NVAR(&realModelName);
				zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2675);
				ZEPHIR_INIT_NVAR(&_13$$12);
				zephir_create_array(&_13$$12, 2, 0);
				zephir_array_fast_append(&_13$$12, &source);
				zephir_array_fast_append(&_13$$12, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_13$$12);
				ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getjointype", &_5, 0, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&aliasExpr);
				if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2687);
					if (UNEXPECTED(zephir_array_isset_value(&joinModels, &alias))) {
						ZEPHIR_INIT_NVAR(&_14$$14);
						object_init_ex(&_14$$14, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_15$$14, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_14$$14, "__construct", &_8, 0, &alias, &_15$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$14, "phalcon/Mvc/Model/Query.zep", 2693);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2699);
					zephir_array_update_zval(&joinTypes, &alias, &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinSources, &alias, &completeSource, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinPrepared, &alias, &joinItem, PH_COPY | PH_SEPARATE);
				} else {
					if (UNEXPECTED(zephir_array_isset_value(&joinModels, &realModelName))) {
						ZEPHIR_INIT_NVAR(&_16$$16);
						object_init_ex(&_16$$16, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_17$$16, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_16$$16, "__construct", &_8, 0, &realModelName, &_17$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$16, "phalcon/Mvc/Model/Query.zep", 2750);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinTypes, &realModelName, &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinModels, &realModelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinSources, &realModelName, &completeSource, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&joinPrepared, &realModelName, &joinItem, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&joinItem);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1071, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1072, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1073, &sqlAliasesModels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1074, &sqlModelsAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1075, &sqlAliasesModelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1070, &modelsInstances);
	zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2825);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _19, _20, _18)
	{
		ZEPHIR_INIT_NVAR(&joinAliasName);
		if (_20 != NULL) { 
			ZVAL_STR_COPY(&joinAliasName, _20);
		} else {
			ZVAL_LONG(&joinAliasName, _19);
		}
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _18);
		ZEPHIR_OBS_NVAR(&joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0)) {
			ZEPHIR_CALL_METHOD(&_21$$18, this_ptr, "getexpression", &_22, 0, &joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_21$$18, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 1055, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_23$$19);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2837);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _25$$19, _26$$19, _24$$19)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_26$$19 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _26$$19);
			} else {
				ZVAL_LONG(&joinAliasName, _25$$19);
			}
			ZEPHIR_INIT_NVAR(&_23$$19);
			ZVAL_COPY(&_23$$19, _24$$19);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2827);
			ZEPHIR_OBS_NVAR(&joinSource);
			zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2828);
			ZEPHIR_OBS_NVAR(&preCondition);
			zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2829);
			ZEPHIR_INIT_NVAR(&_27$$20);
			zephir_create_array(&_27$$20, 3, 0);
			zephir_array_update_string(&_27$$20, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_27$$20, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_28$$20);
			zephir_create_array(&_28$$20, 1, 0);
			zephir_array_fast_append(&_28$$20, &preCondition);
			zephir_array_update_string(&_27$$20, SL("conditions"), &_28$$20, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, &_27$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2834);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_23$$19);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	if (Z_TYPE_P(&selectTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_30);
		zephir_string_to_char_array(&_30, &selectTables);
		_29 = &_30;
	} else {
		_29 = &selectTables;
	}
	zephir_is_iterable(_29, 0, "phalcon/Mvc/Model/Query.zep", 2852);
	if (Z_TYPE_P(_29) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_29), _31)
		{
			ZEPHIR_INIT_NVAR(&tableItem);
			ZVAL_COPY(&tableItem, _31);
			zephir_array_fetch_string(&_32$$21, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2846);
			ZEPHIR_OBS_NVAR(&_33$$21);
			zephir_array_fetch_string(&_33$$21, &_32$$21, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2846);
			zephir_array_update_zval(&fromModels, &_33$$21, &__$true, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _29, "rewind", NULL, 0);
		zephir_check_call_status();
		_35 = 1;
		while (1) {
			if (_35) {
				_35 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _29, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_34, _29, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_34)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tableItem, _29, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_36$$22, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2846);
				ZEPHIR_OBS_NVAR(&_37$$22);
				zephir_array_fetch_string(&_37$$22, &_36$$22, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2846);
				zephir_array_update_zval(&fromModels, &_37$$22, &__$true, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&tableItem);
	if (Z_TYPE_P(&fromModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_39);
		zephir_string_to_char_array(&_39, &fromModels);
		_38 = &_39;
	} else {
		_38 = &fromModels;
	}
	ZEPHIR_INIT_VAR(&_40);
	zephir_is_iterable(_38, 0, "phalcon/Mvc/Model/Query.zep", 2970);
	if (Z_TYPE_P(_38) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_38), _42, _43, _41)
		{
			ZEPHIR_INIT_NVAR(&fromModelName);
			if (_43 != NULL) { 
				ZVAL_STR_COPY(&fromModelName, _43);
			} else {
				ZVAL_LONG(&fromModelName, _42);
			}
			ZEPHIR_INIT_NVAR(&_40);
			ZVAL_COPY(&_40, _41);
			zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 2968);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _45$$23, _46$$23, _44$$23)
			{
				ZEPHIR_INIT_NVAR(&joinAlias);
				if (_46$$23 != NULL) { 
					ZVAL_STR_COPY(&joinAlias, _46$$23);
				} else {
					ZVAL_LONG(&joinAlias, _45$$23);
				}
				ZEPHIR_INIT_NVAR(&joinModel);
				ZVAL_COPY(&joinModel, _44$$23);
				ZEPHIR_OBS_NVAR(&joinSource);
				zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2857);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2862);
				ZEPHIR_OBS_NVAR(&preCondition);
				if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0))) {
					ZEPHIR_OBS_NVAR(&modelNameAlias);
					zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2871);
					ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_47, 0, &fromModelName, &modelNameAlias);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
						ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_48, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (Z_TYPE_P(&relations) == IS_ARRAY) {
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_49$$28);
								object_init_ex(&_49$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_50$$28, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_49$$28, "__construct", &_51, 0, &fromModelName, &joinModel, &_50$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_49$$28, "phalcon/Mvc/Model/Query.zep", 2895);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2901);
						}
					}
					if (Z_TYPE_P(&relation) == IS_OBJECT) {
						ZEPHIR_OBS_NVAR(&modelAlias);
						zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2912);
						ZEPHIR_CALL_METHOD(&_52$$29, &relation, "isthrough", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_52$$29))) {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getsinglejoin", &_53, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getmultijoin", &_54, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						}
						if (zephir_array_isset_value_long(&sqlJoin, 0)) {
							if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_56$$32);
								zephir_string_to_char_array(&_56$$32, &sqlJoin);
								_55$$32 = &_56$$32;
							} else {
								_55$$32 = &sqlJoin;
							}
							zephir_is_iterable(_55$$32, 0, "phalcon/Mvc/Model/Query.zep", 2942);
							if (Z_TYPE_P(_55$$32) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_55$$32), _57$$32)
								{
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
									ZVAL_COPY(&sqlJoinItem, _57$$32);
									zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2940);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _55$$32, "rewind", NULL, 0);
								zephir_check_call_status();
								_59$$32 = 1;
								while (1) {
									if (_59$$32) {
										_59$$32 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _55$$32, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_58$$32, _55$$32, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_58$$32)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&sqlJoinItem, _55$$32, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2940);
								}
							}
							ZEPHIR_INIT_NVAR(&sqlJoinItem);
						} else {
							zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2943);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_60$$36);
						zephir_create_array(&_60$$36, 3, 0);
						zephir_array_update_string(&_60$$36, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_60$$36, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_61$$36);
						array_init(&_61$$36);
						zephir_array_update_string(&_60$$36, SL("conditions"), &_61$$36, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_60$$36, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2954);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_62$$37);
					zephir_create_array(&_62$$37, 3, 0);
					zephir_array_update_string(&_62$$37, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_62$$37, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_63$$37);
					zephir_create_array(&_63$$37, 1, 0);
					zephir_array_fast_append(&_63$$37, &preCondition);
					zephir_array_update_string(&_62$$37, SL("conditions"), &_63$$37, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_62$$37, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2965);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&joinModel);
			ZEPHIR_INIT_NVAR(&joinAlias);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _38, "rewind", NULL, 0);
		zephir_check_call_status();
		_65 = 1;
		while (1) {
			if (_65) {
				_65 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _38, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_64, _38, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_64)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&fromModelName, _38, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_40, _38, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 2968);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _67$$38, _68$$38, _66$$38)
				{
					ZEPHIR_INIT_NVAR(&joinAlias);
					if (_68$$38 != NULL) { 
						ZVAL_STR_COPY(&joinAlias, _68$$38);
					} else {
						ZVAL_LONG(&joinAlias, _67$$38);
					}
					ZEPHIR_INIT_NVAR(&joinModel);
					ZVAL_COPY(&joinModel, _66$$38);
					ZEPHIR_OBS_NVAR(&joinSource);
					zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2857);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2862);
					ZEPHIR_OBS_NVAR(&preCondition);
					if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0))) {
						ZEPHIR_OBS_NVAR(&modelNameAlias);
						zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2871);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_69, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_70, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (Z_TYPE_P(&relations) == IS_ARRAY) {
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_71$$43);
									object_init_ex(&_71$$43, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_72$$43, this_ptr, _zephir_prop_7, 1054, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_71$$43, "__construct", &_51, 0, &fromModelName, &joinModel, &_72$$43);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_71$$43, "phalcon/Mvc/Model/Query.zep", 2895);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2901);
							}
						}
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_OBS_NVAR(&modelAlias);
							zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2912);
							ZEPHIR_CALL_METHOD(&_73$$44, &relation, "isthrough", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_73$$44))) {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getsinglejoin", &_53, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getmultijoin", &_54, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							}
							if (zephir_array_isset_value_long(&sqlJoin, 0)) {
								if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_75$$47);
									zephir_string_to_char_array(&_75$$47, &sqlJoin);
									_74$$47 = &_75$$47;
								} else {
									_74$$47 = &sqlJoin;
								}
								zephir_is_iterable(_74$$47, 0, "phalcon/Mvc/Model/Query.zep", 2942);
								if (Z_TYPE_P(_74$$47) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_74$$47), _76$$47)
									{
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
										ZVAL_COPY(&sqlJoinItem, _76$$47);
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2940);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _74$$47, "rewind", NULL, 0);
									zephir_check_call_status();
									_78$$47 = 1;
									while (1) {
										if (_78$$47) {
											_78$$47 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _74$$47, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_77$$47, _74$$47, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_77$$47)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&sqlJoinItem, _74$$47, "current", NULL, 0);
										zephir_check_call_status();
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2940);
									}
								}
								ZEPHIR_INIT_NVAR(&sqlJoinItem);
							} else {
								zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2943);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_79$$51);
							zephir_create_array(&_79$$51, 3, 0);
							zephir_array_update_string(&_79$$51, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_79$$51, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_80$$51);
							array_init(&_80$$51);
							zephir_array_update_string(&_79$$51, SL("conditions"), &_80$$51, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_79$$51, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2954);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_81$$52);
						zephir_create_array(&_81$$52, 3, 0);
						zephir_array_update_string(&_81$$52, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_81$$52, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$52);
						zephir_create_array(&_82$$52, 1, 0);
						zephir_array_fast_append(&_82$$52, &preCondition);
						zephir_array_update_string(&_81$$52, SL("conditions"), &_82$$52, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_81$$52, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2965);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&joinModel);
				ZEPHIR_INIT_NVAR(&joinAlias);
		}
	}
	ZEPHIR_INIT_NVAR(&_40);
	ZEPHIR_INIT_NVAR(&fromModelName);
	RETURN_CTOR(&sqlJoins);
}

/**
 * Returns a processed limit clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getLimitClause)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limitClause_param = NULL, number, offset, _0$$3, _1$$4;
	zval limitClause, limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limitClause);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(limitClause, limitClause_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &limitClause_param);
	zephir_get_arrval(&limitClause, limitClause_param);
	ZEPHIR_INIT_VAR(&limit);
	array_init(&limit);
	zephir_memory_observe(&number);
	if (zephir_array_isset_string_fetch(&number, &limitClause, SL("number"), 0)) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getexpression", NULL, 0, &number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&offset);
	if (zephir_array_isset_string_fetch(&offset, &limitClause, SL("offset"), 0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getexpression", NULL, 0, &offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&limit);
}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string joinSource
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getMultiJoin)
{
	zend_bool _14$$3;
	zend_ulong _4$$3;
	zval sqlJoins, _10$$4, _12$$4, _19$$6, _20$$6, _22$$8, _23$$8, _24$$8, _26$$8, _27$$8, _28$$8, _29$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, _0, *_1$$3, _2$$3, *_3$$3, _13$$3, _6$$5, _7$$5, _9$$4, _15$$7, _16$$7, _17$$6, _18$$6, _21$$8, _25$$8;
	zend_string *joinType = NULL, *modelAlias = NULL, *joinAlias = NULL, *_5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType_zv);
	ZVAL_UNDEF(&joinSource_sub);
	ZVAL_UNDEF(&modelAlias_zv);
	ZVAL_UNDEF(&joinAlias_zv);
	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateSource);
	ZVAL_UNDEF(&intermediateSchema);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&referencedModelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&intermediateField);
	ZVAL_UNDEF(&sqlEqualsJoinCondition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("phql", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(joinType)
		Z_PARAM_ZVAL(joinSource)
		Z_PARAM_STR(modelAlias)
		Z_PARAM_STR(joinAlias)
		Z_PARAM_OBJECT_OF_CLASS(relation, phalcon_mvc_model_relationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	joinSource = ZEND_CALL_ARG(execute_data, 2);
	relation = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&joinType_zv);
	ZVAL_STR_COPY(&joinType_zv, joinType);
	zephir_memory_observe(&modelAlias_zv);
	ZVAL_STR_COPY(&modelAlias_zv, modelAlias);
	zephir_memory_observe(&joinAlias_zv);
	ZVAL_STR_COPY(&joinAlias_zv, joinAlias);
	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", NULL, 0, &intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSource, &intermediateModel, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSchema, &intermediateModel, "getschema", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("sqlAliases"), &intermediateModelName, &intermediateSource);
	zephir_update_property_array(this_ptr, SL("sqlAliasesModelsInstances"), &intermediateModelName, &intermediateModel);
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getreferencedmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &fields);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = &fields;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Mvc/Model/Query.zep", 3104);
		if (Z_TYPE_P(_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1$$3), _4$$3, _5$$3, _3$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_5$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _5$$3);
				} else {
					ZVAL_LONG(&field, _4$$3);
				}
				ZEPHIR_INIT_NVAR(&position);
				ZVAL_COPY(&position, _3$$3);
				if (UNEXPECTED(!(zephir_array_isset_value(&referencedFields, &position)))) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property_cached(&_7$$5, this_ptr, _zephir_prop_1, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_8, 0, &modelAlias_zv, &joinAlias_zv, &_7$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model/Query.zep", 3071);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&intermediateField);
				zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3077);
				ZEPHIR_INIT_NVAR(&sqlEqualsJoinCondition);
				zephir_create_array(&sqlEqualsJoinCondition, 4, 0);
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 3, 0);
				add_assoc_long_ex(&_10$$4, SL("type"), 355);
				zephir_array_update_string(&_10$$4, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getqualified", &_11, 0, &_10$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_9$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_12$$4);
				zephir_create_array(&_12$$4, 3, 0);
				add_assoc_stringl_ex(&_12$$4, SL("type"), SL("qualified"));
				zephir_array_update_string(&_12$$4, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_12$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getqualified", &_11, 0, &_12$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_9$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_14$$3 = 1;
			while (1) {
				if (_14$$3) {
					_14$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_13$$3, _1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _1$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&position, _1$$3, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(!(zephir_array_isset_value(&referencedFields, &position)))) {
						ZEPHIR_INIT_NVAR(&_15$$7);
						object_init_ex(&_15$$7, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_16$$7, this_ptr, _zephir_prop_1, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_15$$7, "__construct", &_8, 0, &modelAlias_zv, &joinAlias_zv, &_16$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$7, "phalcon/Mvc/Model/Query.zep", 3071);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&intermediateField);
					zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3077);
					ZEPHIR_INIT_NVAR(&_17$$6);
					zephir_create_array(&_17$$6, 4, 0);
					add_assoc_stringl_ex(&_17$$6, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_17$$6, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_19$$6);
					zephir_create_array(&_19$$6, 3, 0);
					add_assoc_long_ex(&_19$$6, SL("type"), 355);
					zephir_array_update_string(&_19$$6, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_19$$6, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$6, this_ptr, "getqualified", &_11, 0, &_19$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$6, SL("left"), &_18$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$6);
					zephir_create_array(&_20$$6, 3, 0);
					add_assoc_stringl_ex(&_20$$6, SL("type"), SL("qualified"));
					zephir_array_update_string(&_20$$6, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$6, this_ptr, "getqualified", &_11, 0, &_20$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$6, SL("right"), &_18$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlEqualsJoinCondition, &_17$$6);
			}
		}
		ZEPHIR_INIT_NVAR(&position);
		ZEPHIR_INIT_NVAR(&field);
	} else {
		ZEPHIR_INIT_VAR(&_21$$8);
		zephir_create_array(&_21$$8, 2, 0);
		ZEPHIR_INIT_VAR(&_22$$8);
		zephir_create_array(&_22$$8, 3, 0);
		zephir_array_update_string(&_22$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_23$$8);
		zephir_create_array(&_23$$8, 2, 0);
		zephir_array_fast_append(&_23$$8, &intermediateSource);
		zephir_array_fast_append(&_23$$8, &intermediateSchema);
		zephir_array_update_string(&_22$$8, SL("source"), &_23$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_23$$8);
		zephir_create_array(&_23$$8, 1, 0);
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 4, 0);
		add_assoc_stringl_ex(&_24$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_24$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 3, 0);
		add_assoc_long_ex(&_26$$8, SL("type"), 355);
		zephir_array_update_string(&_26$$8, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_26$$8, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getqualified", &_11, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("left"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 3, 0);
		add_assoc_stringl_ex(&_27$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_27$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_27$$8, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getqualified", &_11, 0, &_27$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("right"), &_25$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_23$$8, &_24$$8);
		zephir_array_update_string(&_22$$8, SL("conditions"), &_23$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_21$$8, &_22$$8);
		ZEPHIR_INIT_NVAR(&_22$$8);
		zephir_create_array(&_22$$8, 3, 0);
		zephir_array_update_string(&_22$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_22$$8, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_23$$8);
		zephir_create_array(&_23$$8, 1, 0);
		ZEPHIR_INIT_NVAR(&_24$$8);
		zephir_create_array(&_24$$8, 4, 0);
		add_assoc_stringl_ex(&_24$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_24$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_28$$8);
		zephir_create_array(&_28$$8, 3, 0);
		add_assoc_long_ex(&_28$$8, SL("type"), 355);
		zephir_array_update_string(&_28$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_28$$8, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getqualified", &_11, 0, &_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("left"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_29$$8);
		zephir_create_array(&_29$$8, 3, 0);
		add_assoc_stringl_ex(&_29$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_29$$8, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_29$$8, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getqualified", &_11, 0, &_29$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("right"), &_25$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_23$$8, &_24$$8);
		zephir_array_update_string(&_22$$8, SL("conditions"), &_23$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_21$$8, &_22$$8);
		ZEPHIR_CPY_WRT(&sqlJoins, &_21$$8);
	}
	RETURN_CTOR(&sqlJoins);
}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string order
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getOrderClause)
{
	zend_bool _10;
	zval orderParts, orderPartSort;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderItem, orderPartExpr, orderSort, *_0, _1, *_2, _9, _3$$5, _5$$7, _6$$8, _7$$8, _8$$9, _11$$10, _12$$12, _13$$12, _14$$13, _15$$13, _16$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&orderParts);
	ZVAL_UNDEF(&orderPartSort);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(order)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &order);
	if (!(zephir_array_isset_value_long(order, 0))) {
		ZEPHIR_INIT_VAR(&orderColumns);
		zephir_create_array(&orderColumns, 1, 0);
		zephir_array_fast_append(&orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(&orderColumns, order);
	}
	ZEPHIR_INIT_VAR(&orderParts);
	array_init(&orderParts);
	if (Z_TYPE_P(&orderColumns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_string_to_char_array(&_1, &orderColumns);
		_0 = &_1;
	} else {
		_0 = &orderColumns;
	}
	zephir_is_iterable(_0, 0, "phalcon/Mvc/Model/Query.zep", 3213);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_0), _2)
		{
			ZEPHIR_INIT_NVAR(&orderItem);
			ZVAL_COPY(&orderItem, _2);
			zephir_array_fetch_string(&_3$$5, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3195);
			ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getexpression", &_4, 0, &_3$$5);
			zephir_check_call_status();
			if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 1)) {
				if (ZEPHIR_IS_LONG(&orderSort, 327)) {
					ZEPHIR_INIT_NVAR(&orderPartSort);
					zephir_create_array(&orderPartSort, 2, 0);
					zephir_array_fast_append(&orderPartSort, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_5$$7);
					ZVAL_STRING(&_5$$7, "ASC");
					zephir_array_fast_append(&orderPartSort, &_5$$7);
				} else {
					ZEPHIR_INIT_NVAR(&_6$$8);
					zephir_create_array(&_6$$8, 2, 0);
					zephir_array_fast_append(&_6$$8, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_7$$8);
					ZVAL_STRING(&_7$$8, "DESC");
					zephir_array_fast_append(&_6$$8, &_7$$8);
					ZEPHIR_CPY_WRT(&orderPartSort, &_6$$8);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_8$$9);
				zephir_create_array(&_8$$9, 1, 0);
				zephir_array_fast_append(&_8$$9, &orderPartExpr);
				ZEPHIR_CPY_WRT(&orderPartSort, &_8$$9);
			}
			zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3210);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _0, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&orderItem, _0, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_11$$10, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3195);
				ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getexpression", &_4, 0, &_11$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&orderSort);
				if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0)) {
					if (ZEPHIR_IS_LONG(&orderSort, 327)) {
						ZEPHIR_INIT_NVAR(&_12$$12);
						zephir_create_array(&_12$$12, 2, 0);
						zephir_array_fast_append(&_12$$12, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_13$$12);
						ZVAL_STRING(&_13$$12, "ASC");
						zephir_array_fast_append(&_12$$12, &_13$$12);
						ZEPHIR_CPY_WRT(&orderPartSort, &_12$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_14$$13);
						zephir_create_array(&_14$$13, 2, 0);
						zephir_array_fast_append(&_14$$13, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_15$$13);
						ZVAL_STRING(&_15$$13, "DESC");
						zephir_array_fast_append(&_14$$13, &_15$$13);
						ZEPHIR_CPY_WRT(&orderPartSort, &_14$$13);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_16$$14);
					zephir_create_array(&_16$$14, 1, 0);
					zephir_array_fast_append(&_16$$14, &orderPartExpr);
					ZEPHIR_CPY_WRT(&orderPartSort, &_16$$14);
				}
				zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3210);
		}
	}
	ZEPHIR_INIT_NVAR(&orderItem);
	RETURN_CTOR(&orderParts);
}

/**
 * Replaces the model's name to its source name in a qualified-name
 * expression
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getQualified)
{
	zend_bool _3, _4, _27$$14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL, *_25 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _0, _5, _1$$3, _2$$3, _6$$6, _10$$6, _11$$6, _7$$7, _8$$7, _9$$7, _12$$8, _13$$9, _14$$9, _15$$12, _16$$12, _17$$14, *_18$$14, _19$$14, *_20$$14, _26$$14, _35$$14, _39$$14, _40$$14, _21$$15, _23$$17, _24$$17, _28$$18, _30$$20, _31$$20, _32$$21, _33$$21, _34$$21, _36$$22, _37$$23, _38$$23, _41$$27, _42$$27, _43$$27;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&nestingLevel);
	ZVAL_UNDEF(&sqlColumnAliases);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&realColumnName);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&hasModel);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_42$$27);
	ZVAL_UNDEF(&_43$$27);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("nestingLevel", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sqlColumnAliases", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("metaData", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("sqlAliasesModelsInstances", 25, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("models", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	zephir_memory_observe(&columnName);
	zephir_array_fetch_string(&columnName, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3227);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1076, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&nestingLevel, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1077, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &nestingLevel)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1077, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &nestingLevel, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3235);
		ZEPHIR_CPY_WRT(&sqlColumnAliases, &_2$$3);
	} else {
		ZEPHIR_INIT_NVAR(&sqlColumnAliases);
		array_init(&sqlColumnAliases);
	}
	_3 = zephir_array_isset_value(&sqlColumnAliases, &columnName);
	if (_3) {
		_4 = !(zephir_array_isset_value_string(&expr, SL("domain")));
		if (!(_4)) {
			_4 = zephir_isempty_dim_string(&expr, SL("domain"));
		}
		_3 = _4;
	}
	if (_3) {
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
		zephir_array_update_string(return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_2, 1066, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_5);
	zephir_memory_observe(&columnDomain);
	if (zephir_array_isset_string_fetch(&columnDomain, &expr, SL("domain"), 0)) {
		zephir_read_property_cached(&_6$$6, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_6$$6);
		zephir_memory_observe(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0)))) {
			ZEPHIR_INIT_VAR(&_7$$7);
			object_init_ex(&_7$$7, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property_cached(&_8$$7, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_9$$7);
			ZVAL_STRING(&_9$$7, "11");
			ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 0, &columnDomain, &_9$$7, &_8$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$7, "phalcon/Mvc/Model/Query.zep", 3259);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_10$$6, phalcon_support_settings_ce, "get", NULL, 0, &_11$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$6)) {
			zephir_read_property_cached(&_12$$8, this_ptr, _zephir_prop_5, 1075, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_12$$8);
			zephir_memory_observe(&model);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&model, &sqlAliasesModelsInstances, &columnDomain, 0)))) {
				ZEPHIR_INIT_VAR(&_13$$9);
				object_init_ex(&_13$$9, phalcon_mvc_model_query_exceptions_nomodelforalias_ce);
				zephir_read_property_cached(&_14$$9, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_13$$9, "__construct", NULL, 0, &columnDomain, &_14$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$9, "phalcon/Mvc/Model/Query.zep", 3276);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			zephir_memory_observe(&realColumnName);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0)))) {
				ZEPHIR_INIT_VAR(&_15$$12);
				object_init_ex(&_15$$12, phalcon_mvc_model_query_exceptions_columnnotindomain_ce);
				zephir_read_property_cached(&_16$$12, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_15$$12, "__construct", NULL, 0, &columnName, &columnDomain, &_16$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$12, "phalcon/Mvc/Model/Query.zep", 3286);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&realColumnName, &columnName);
		}
	} else {
		number = 0;
		ZEPHIR_INIT_VAR(&hasModel);
		ZVAL_BOOL(&hasModel, 0);
		zephir_read_property_cached(&_17$$14, this_ptr, _zephir_prop_6, 1070, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_17$$14) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_19$$14);
			zephir_string_to_char_array(&_19$$14, &_17$$14);
			_18$$14 = &_19$$14;
		} else {
			_18$$14 = &_17$$14;
		}
		zephir_is_iterable(_18$$14, 0, "phalcon/Mvc/Model/Query.zep", 3318);
		if (Z_TYPE_P(_18$$14) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_18$$14), _20$$14)
			{
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _20$$14);
				ZEPHIR_CALL_METHOD(&_21$$15, &metaData, "hasattribute", &_22, 0, &model, &columnName);
				zephir_check_call_status();
				if (zephir_is_true(&_21$$15)) {
					number++;
					if (UNEXPECTED(number > 1)) {
						ZEPHIR_INIT_NVAR(&_23$$17);
						object_init_ex(&_23$$17, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
						zephir_read_property_cached(&_24$$17, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_23$$17, "__construct", &_25, 0, &columnName, &_24$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_23$$17, "phalcon/Mvc/Model/Query.zep", 3307);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&hasModel, &model);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _18$$14, "rewind", NULL, 0);
			zephir_check_call_status();
			_27$$14 = 1;
			while (1) {
				if (_27$$14) {
					_27$$14 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _18$$14, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_26$$14, _18$$14, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_26$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&model, _18$$14, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_28$$18, &metaData, "hasattribute", &_29, 0, &model, &columnName);
					zephir_check_call_status();
					if (zephir_is_true(&_28$$18)) {
						number++;
						if (UNEXPECTED(number > 1)) {
							ZEPHIR_INIT_NVAR(&_30$$20);
							object_init_ex(&_30$$20, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
							zephir_read_property_cached(&_31$$20, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &_30$$20, "__construct", &_25, 0, &columnName, &_31$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_30$$20, "phalcon/Mvc/Model/Query.zep", 3307);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&hasModel, &model);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&hasModel))) {
			ZEPHIR_INIT_VAR(&_32$$21);
			object_init_ex(&_32$$21, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
			zephir_read_property_cached(&_33$$21, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_34$$21);
			ZVAL_STRING(&_34$$21, "1");
			ZEPHIR_CALL_METHOD(NULL, &_32$$21, "__construct", NULL, 0, &columnName, &_34$$21, &_33$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_32$$21, "phalcon/Mvc/Model/Query.zep", 3319);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_35$$14, this_ptr, _zephir_prop_7, 1071, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&models, &_35$$14);
		if (UNEXPECTED(Z_TYPE_P(&models) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_36$$22);
			object_init_ex(&_36$$22, phalcon_mvc_model_query_exceptions_modelslistnotloaded_ce);
			ZEPHIR_CALL_METHOD(NULL, &_36$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_36$$22, "phalcon/Mvc/Model/Query.zep", 3328);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0);
		ZEPHIR_OBS_NVAR(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &models, &className, 0)))) {
			ZEPHIR_INIT_VAR(&_37$$23);
			object_init_ex(&_37$$23, phalcon_mvc_model_query_exceptions_modelsourcenotfound_ce);
			zephir_read_property_cached(&_38$$23, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_37$$23, "__construct", NULL, 0, &className, &_38$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_37$$23, "phalcon/Mvc/Model/Query.zep", 3337);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_40$$14);
		ZVAL_STRING(&_40$$14, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_39$$14, phalcon_support_settings_ce, "get", NULL, 0, &_40$$14);
		zephir_check_call_status();
		if (zephir_is_true(&_39$$14)) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&realColumnName);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0)))) {
				ZEPHIR_INIT_VAR(&_41$$27);
				object_init_ex(&_41$$27, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
				zephir_read_property_cached(&_42$$27, this_ptr, _zephir_prop_4, 1054, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_43$$27);
				ZVAL_STRING(&_43$$27, "3");
				ZEPHIR_CALL_METHOD(NULL, &_41$$27, "__construct", NULL, 0, &columnName, &_43$$27, &_42$$27);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_41$$27, "phalcon/Mvc/Model/Query.zep", 3354);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&realColumnName, &columnName);
		}
	}
	zephir_create_array(return_value, 4, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
	zephir_array_update_string(return_value, SL("domain"), &source, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("name"), &realColumnName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("balias"), &columnName, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Gets the read connection from the model if there is no transaction set
 * inside the query object
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getReadConnection)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, bindParams, bindTypes;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, connection, transaction, _0, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);
	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(&intermediate);
	} else {
		zephir_get_arrval(&intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1068, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectreadconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectreadconnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_readconnectionmissing_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3396);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Query the records on which the UPDATE/DELETE operation will be done
 *
 * @return ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getRelatedRecords)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, bindParams, bindTypes, _0, _1;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, selectIr, joinConditions, whereConditions, limitConditions, query, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&selectIr);
	ZVAL_UNDEF(&joinConditions);
	ZVAL_UNDEF(&whereConditions);
	ZVAL_UNDEF(&limitConditions);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &model, &intermediate_param, &bindParams_param, &bindTypes_param);
	zephir_get_arrval(&intermediate, intermediate_param);
	zephir_get_arrval(&bindParams, bindParams_param);
	zephir_get_arrval(&bindTypes, bindTypes_param);
	ZEPHIR_INIT_VAR(&selectIr);
	zephir_create_array(&selectIr, 3, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0);
	add_assoc_stringl_ex(&_1, SL("type"), SL("object"));
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	zephir_array_update_string(&_1, SL("model"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, model, "getsource", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3426);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3428);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&joinConditions);
	if (zephir_array_isset_string_fetch(&joinConditions, &intermediate, SL("joins"), 0)) {
		zephir_array_update_string(&selectIr, SL("joins"), &joinConditions, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&whereConditions);
	if (zephir_array_isset_string_fetch(&whereConditions, &intermediate, SL("where"), 0)) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limitConditions);
	if (zephir_array_isset_string_fetch(&limitConditions, &intermediate, SL("limit"), 0)) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&query);
	object_init_ex(&query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(NULL, &query, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 1060, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &query, "setdi", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 309);
	ZEPHIR_CALL_METHOD(NULL, &query, "settype", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "setintermediate", NULL, 0, &selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves a column from its intermediate representation into an array
 * used to determine if the resultset produced is simple or complex
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSelectColumn)
{
	zend_bool _13$$4;
	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, columnData, balias, eager, _30, _0$$3, _1$$4, *_2$$4, _3$$4, *_4$$4, _12$$4, _7$$5, _8$$5, _9$$5, _11$$6, _14$$7, _15$$7, _16$$7, _17$$7, _18$$8, _19$$9, _20$$10, _26$$10, _21$$11, _22$$11, _23$$11, _24$$13, _25$$13, _27$$15, _28$$16, _29$$18;
	zval column, sqlColumns, sqlColumn;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&columnDomain);
	ZVAL_UNDEF(&sqlColumnAlias);
	ZVAL_UNDEF(&preparedAlias);
	ZVAL_UNDEF(&sqlExprColumn);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&columnData);
	ZVAL_UNDEF(&balias);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$18);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("sqlAliasesModels", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(column, column_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column_param);
	zephir_get_arrval(&column, column_param);
	zephir_memory_observe(&columnType);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columnType, &column, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 3476);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	zephir_memory_observe(&eager);
	zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_0, 1071, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_1$$4) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_string_to_char_array(&_3$$4, &_1$$4);
			_2$$4 = &_3$$4;
		} else {
			_2$$4 = &_1$$4;
		}
		zephir_is_iterable(_2$$4, 0, "phalcon/Mvc/Model/Query.zep", 3506);
		if (Z_TYPE_P(_2$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_2$$4), _5$$4, _6$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&modelName);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&modelName, _6$$4);
				} else {
					ZVAL_LONG(&modelName, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&source);
				ZVAL_COPY(&source, _4$$4);
				ZEPHIR_INIT_NVAR(&sqlColumn);
				zephir_create_array(&sqlColumn, 4, 0);
				add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
				zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_STRING(&_8$$5, "\\");
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_fast_strpos(&_9$$5, &modelName, &_8$$5, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_9$$5)) {
					ZEPHIR_CPY_WRT(&_7$$5, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&_7$$5, "lcfirst", &_10, 180, &modelName);
					zephir_check_call_status();
				}
				zephir_array_update_string(&sqlColumn, SL("balias"), &_7$$5, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&eager) != IS_NULL) {
					zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_11$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3500);
					zephir_array_update_string(&sqlColumn, SL("eagerType"), &_11$$6, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3503);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _2$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_13$$4 = 1;
			while (1) {
				if (_13$$4) {
					_13$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _2$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12$$4, _2$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelName, _2$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, _2$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_create_array(&_14$$7, 4, 0);
					add_assoc_stringl_ex(&_14$$7, SL("type"), SL("object"));
					zephir_array_update_string(&_14$$7, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_14$$7, SL("column"), &source, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_15$$7);
					ZEPHIR_INIT_NVAR(&_16$$7);
					ZVAL_STRING(&_16$$7, "\\");
					ZEPHIR_INIT_NVAR(&_17$$7);
					zephir_fast_strpos(&_17$$7, &modelName, &_16$$7, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_17$$7)) {
						ZEPHIR_CPY_WRT(&_15$$7, &modelName);
					} else {
						ZEPHIR_CALL_FUNCTION(&_15$$7, "lcfirst", &_10, 180, &modelName);
						zephir_check_call_status();
					}
					zephir_array_update_string(&_14$$7, SL("balias"), &_15$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlColumn, &_14$$7);
					if (Z_TYPE_P(&eager) != IS_NULL) {
						zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
						zephir_array_fetch_string(&_18$$8, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3500);
						zephir_array_update_string(&sqlColumn, SL("eagerType"), &_18$$8, PH_COPY | PH_SEPARATE);
					}
					zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3503);
			}
		}
		ZEPHIR_INIT_NVAR(&source);
		ZEPHIR_INIT_NVAR(&modelName);
		RETURN_CTOR(&sqlColumns);
	}
	if (UNEXPECTED(!(zephir_array_isset_value_string(&column, SL("column"))))) {
		ZEPHIR_INIT_VAR(&_19$$9);
		object_init_ex(&_19$$9, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_19$$9, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_19$$9, "phalcon/Mvc/Model/Query.zep", 3510);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		zephir_read_property_cached(&_20$$10, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_20$$10);
		zephir_memory_observe(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3522);
		ZEPHIR_OBS_NVAR(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0)))) {
			ZEPHIR_INIT_VAR(&_21$$11);
			object_init_ex(&_21$$11, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property_cached(&_22$$11, this_ptr, _zephir_prop_2, 1054, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_23$$11);
			ZVAL_STRING(&_23$$11, "2");
			ZEPHIR_CALL_METHOD(NULL, &_21$$11, "__construct", NULL, 0, &columnDomain, &_23$$11, &_22$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_21$$11, "phalcon/Mvc/Model/Query.zep", 3525);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		zephir_memory_observe(&preparedAlias);
		zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		zephir_read_property_cached(&_20$$10, this_ptr, _zephir_prop_3, 1073, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliasesModels, &_20$$10);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3539);
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			if (ZEPHIR_IS_EQUAL(&columnDomain, &modelName)) {
				ZEPHIR_INIT_VAR(&_24$$13);
				ZVAL_STRING(&_24$$13, "\\");
				ZEPHIR_INIT_VAR(&_25$$13);
				zephir_fast_strpos(&_25$$13, &modelName, &_24$$13, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_25$$13)) {
					ZEPHIR_CPY_WRT(&preparedAlias, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_10, 180, &modelName);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_VAR(&_26$$10);
		zephir_create_array(&_26$$10, 4, 0);
		add_assoc_stringl_ex(&_26$$10, SL("type"), SL("object"));
		zephir_array_update_string(&_26$$10, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_26$$10, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_26$$10, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&sqlColumn, &_26$$10);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_27$$15, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3561);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_27$$15, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3564);
		RETURN_CTOR(&sqlColumns);
	}
	if (ZEPHIR_IS_LONG(&columnType, 354)) {
		ZEPHIR_INIT_VAR(&_28$$16);
		zephir_create_array(&_28$$16, 1, 0);
		add_assoc_stringl_ex(&_28$$16, SL("type"), SL("scalar"));
		ZEPHIR_CPY_WRT(&sqlColumn, &_28$$16);
		zephir_memory_observe(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3578);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "getexpression", NULL, 0, &columnData);
		zephir_check_call_status();
		zephir_memory_observe(&balias);
		if (zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_29$$18, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3591);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_29$$18, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3595);
		RETURN_CTOR(&sqlColumns);
	}
	ZEPHIR_INIT_VAR(&_30);
	object_init_ex(&_30, phalcon_mvc_model_query_exceptions_unknowncolumntype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_30, "__construct", NULL, 0, &columnType);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_30, "phalcon/Mvc/Model/Query.zep", 3600);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string joinSource
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleJoin)
{
	zend_bool _18$$4;
	zend_ulong _8$$4;
	zval _1$$3, _3$$3, _4$$3, _13$$5, _15$$5, _16$$5, _21$$7, _23$$7, _24$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _0$$3, _2$$3, *_5$$4, _6$$4, *_7$$4, _17$$4, _10$$6, _11$$6, _14$$5, _19$$8, _20$$8, _22$$7;
	zend_string *joinType = NULL, *modelAlias = NULL, *joinAlias = NULL, *_9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&joinType_zv);
	ZVAL_UNDEF(&joinSource_sub);
	ZVAL_UNDEF(&modelAlias_zv);
	ZVAL_UNDEF(&joinAlias_zv);
	ZVAL_UNDEF(&relation_sub);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&sqlJoinConditions);
	ZVAL_UNDEF(&sqlJoinPartialConditions);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedField);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("phql", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_STR(joinType)
		Z_PARAM_ZVAL(joinSource)
		Z_PARAM_STR(modelAlias)
		Z_PARAM_STR(joinAlias)
		Z_PARAM_OBJECT_OF_CLASS(relation, phalcon_mvc_model_relationinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	joinSource = ZEND_CALL_ARG(execute_data, 2);
	relation = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&joinType_zv);
	ZVAL_STR_COPY(&joinType_zv, joinType);
	zephir_memory_observe(&modelAlias_zv);
	ZVAL_STR_COPY(&modelAlias_zv, modelAlias);
	zephir_memory_observe(&joinAlias_zv);
	ZVAL_STR_COPY(&joinAlias_zv, joinAlias);
	ZEPHIR_INIT_VAR(&sqlJoinConditions);
	ZVAL_NULL(&sqlJoinConditions);
	ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 4, 0);
		add_assoc_stringl_ex(&_1$$3, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_1$$3, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		add_assoc_long_ex(&_3$$3, SL("type"), 355);
		zephir_array_update_string(&_3$$3, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$3, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getqualified", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("left"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 3, 0);
		add_assoc_stringl_ex(&_4$$3, SL("type"), SL("qualified"));
		zephir_array_update_string(&_4$$3, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getqualified", NULL, 0, &_4$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("right"), &_2$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&sqlJoinConditions, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&sqlJoinPartialConditions);
		array_init(&sqlJoinPartialConditions);
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_6$$4);
			zephir_string_to_char_array(&_6$$4, &fields);
			_5$$4 = &_6$$4;
		} else {
			_5$$4 = &fields;
		}
		zephir_is_iterable(_5$$4, 0, "phalcon/Mvc/Model/Query.zep", 3688);
		if (Z_TYPE_P(_5$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5$$4), _8$$4, _9$$4, _7$$4)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_9$$4 != NULL) { 
					ZVAL_STR_COPY(&position, _9$$4);
				} else {
					ZVAL_LONG(&position, _8$$4);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _7$$4);
				ZEPHIR_OBS_NVAR(&referencedField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0)))) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					object_init_ex(&_10$$6, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_0, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", &_12, 0, &modelAlias_zv, &joinAlias_zv, &_11$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$6, "phalcon/Mvc/Model/Query.zep", 3660);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 4, 0);
				add_assoc_stringl_ex(&_13$$5, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_13$$5, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 3, 0);
				add_assoc_long_ex(&_15$$5, SL("type"), 355);
				zephir_array_update_string(&_15$$5, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getqualified", NULL, 0, &_15$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("left"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$5);
				zephir_create_array(&_16$$5, 3, 0);
				add_assoc_stringl_ex(&_16$$5, SL("type"), SL("qualified"));
				zephir_array_update_string(&_16$$5, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_16$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getqualified", NULL, 0, &_16$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("right"), &_14$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoinPartialConditions, &_13$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3685);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _5$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_18$$4 = 1;
			while (1) {
				if (_18$$4) {
					_18$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_17$$4, _5$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, _5$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&field, _5$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&referencedField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0)))) {
						ZEPHIR_INIT_NVAR(&_19$$8);
						object_init_ex(&_19$$8, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_20$$8, this_ptr, _zephir_prop_0, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_19$$8, "__construct", &_12, 0, &modelAlias_zv, &joinAlias_zv, &_20$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$8, "phalcon/Mvc/Model/Query.zep", 3660);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_21$$7);
					zephir_create_array(&_21$$7, 4, 0);
					add_assoc_stringl_ex(&_21$$7, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_21$$7, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_23$$7);
					zephir_create_array(&_23$$7, 3, 0);
					add_assoc_long_ex(&_23$$7, SL("type"), 355);
					zephir_array_update_string(&_23$$7, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$7, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_22$$7, this_ptr, "getqualified", NULL, 0, &_23$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_21$$7, SL("left"), &_22$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$7);
					zephir_create_array(&_24$$7, 3, 0);
					add_assoc_stringl_ex(&_24$$7, SL("type"), SL("qualified"));
					zephir_array_update_string(&_24$$7, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$7, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_22$$7, this_ptr, "getqualified", NULL, 0, &_24$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_21$$7, SL("right"), &_22$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoinPartialConditions, &_21$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3685);
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		ZEPHIR_INIT_NVAR(&position);
	}
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("conditions"), &sqlJoinConditions, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval qualifiedName;
	zval *manager, manager_sub, *qualifiedName_param = NULL, modelName, model, source, schema, _0$$3;

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&qualifiedName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_mvc_model_managerinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(qualifiedName, qualifiedName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &manager, &qualifiedName_param);
	zephir_get_arrval(&qualifiedName, qualifiedName_param);
	zephir_memory_observe(&modelName);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&modelName, &qualifiedName, SL("name"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 3710);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		zephir_create_array(return_value, 2, 0);
		zephir_array_fast_append(return_value, &schema);
		zephir_array_fast_append(return_value, &source);
		RETURN_MM();
	}
	RETURN_CCTOR(&source);
}

/**
 * Gets the write connection from the model if there is no transaction
 * inside the query object
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getWriteConnection)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, bindParams, bindTypes;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, connection, transaction, _0, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("transaction", 11, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_OBJECT_OF_CLASS(model, phalcon_mvc_modelinterface_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(intermediate, intermediate_param)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &model, &intermediate_param, &bindParams_param, &bindTypes_param);
	if (!intermediate_param) {
		ZEPHIR_INIT_VAR(&intermediate);
	} else {
		zephir_get_arrval(&intermediate, intermediate_param);
	}
	if (!bindParams_param) {
		ZEPHIR_INIT_VAR(&bindParams);
		array_init(&bindParams);
	} else {
		zephir_get_arrval(&bindParams, bindParams_param);
	}
	if (!bindTypes_param) {
		ZEPHIR_INIT_VAR(&bindTypes);
		array_init(&bindTypes);
	} else {
		zephir_get_arrval(&bindTypes, bindTypes_param);
	}
	ZEPHIR_INIT_VAR(&connection);
	ZVAL_NULL(&connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1068, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectwriteconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectwriteconnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_writeconnectionmissing_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3746);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareDelete)
{
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, _0, *_3, _4, *_5, _9, _1$$3, _2$$4, _7$$8, _8$$9, _12$$13, _13$$14, _14$$17, _15$$17, _16$$18;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&delete);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&deleteTables);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&sqlDelete);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$17);
	ZVAL_UNDEF(&_16$$18);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("ast", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("sqlAliasesModelsInstances", 25, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1064, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&delete);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&delete, &ast, SL("delete"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3768);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 3772);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	if (!(zephir_array_isset_value_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&deleteTables);
		zephir_create_array(&deleteTables, 1, 0);
		zephir_array_fast_append(&deleteTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&deleteTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&deleteTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &deleteTables);
		_3 = &_4;
	} else {
		_3 = &deleteTables;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model/Query.zep", 3832);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _5);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3796);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3797);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_7$$8);
				zephir_create_array(&_7$$8, 2, 0);
				zephir_array_fast_append(&_7$$8, &source);
				zephir_array_fast_append(&_7$$8, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_7$$8);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$9);
				zephir_create_array(&_8$$9, 2, 0);
				zephir_array_fast_append(&_8$$9, &source);
				zephir_array_fast_append(&_8$$9, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_8$$9);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3814);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3815);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3821);
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3825);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3796);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3797);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_11, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_12$$13);
					zephir_create_array(&_12$$13, 2, 0);
					zephir_array_fast_append(&_12$$13, &source);
					zephir_array_fast_append(&_12$$13, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_12$$13);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$14);
					zephir_create_array(&_13$$14, 2, 0);
					zephir_array_fast_append(&_13$$14, &source);
					zephir_array_fast_append(&_13$$14, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_13$$14);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3814);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3815);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3821);
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3825);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1071, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1070, &modelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1072, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1075, &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlDelete);
	array_init(&sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_15$$17, 1);
		ZEPHIR_CALL_METHOD(&_14$$17, this_ptr, "getexpression", NULL, 0, &where, &_15$$17);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_14$$17, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_16$$18, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_16$$18, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlDelete);
}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareInsert)
{
	zval _9$$7, _16$$8;
	zend_bool notQuoting = 0, _15, _29$$9;
	zval ast, qualifiedName, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, _0, _5, *_6, _7, *_8, _14, _1$$3, _2$$4, _3$$5, _4$$6, _10$$7, _11$$7, _12$$7, _17$$8, _18$$8, _19$$8, *_20$$9, _21$$9, *_22$$9, _28$$9, _23$$10, _25$$11, _26$$11, _30$$12, _32$$13, _33$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_24 = NULL, *_27 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&exprValues);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&sqlInsert);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&sqlFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_16$$8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("ast", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("metaData", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("phql", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1064, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&ast, SL("qualifiedName"))))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3866);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_value_string(&ast, SL("values"))))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 3870);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3873);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&qualifiedName, SL("name"))))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 3877);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3881);
	ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_create_array(&_4$$6, 2, 0);
		zephir_array_fast_append(&_4$$6, &schema);
		zephir_array_fast_append(&_4$$6, &source);
		ZEPHIR_CPY_WRT(&source, &_4$$6);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(&exprValues);
	array_init(&exprValues);
	zephir_array_fetch_string(&_5, &ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3894);
	if (Z_TYPE_P(&_5) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &_5);
		_6 = &_7;
	} else {
		_6 = &_5;
	}
	zephir_is_iterable(_6, 0, "phalcon/Mvc/Model/Query.zep", 3902);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6), _8)
		{
			ZEPHIR_INIT_NVAR(&exprValue);
			ZVAL_COPY(&exprValue, _8);
			ZEPHIR_INIT_NVAR(&_9$$7);
			zephir_create_array(&_9$$7, 2, 0);
			ZEPHIR_OBS_NVAR(&_10$$7);
			zephir_array_fetch_string(&_10$$7, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3897);
			zephir_array_update_string(&_9$$7, SL("type"), &_10$$7, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_12$$7, 1);
			} else {
				ZVAL_BOOL(&_12$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "getexpression", &_13, 0, &exprValue, &_12$$7);
			zephir_check_call_status();
			zephir_array_update_string(&_9$$7, SL("value"), &_11$$7, PH_COPY | PH_SEPARATE);
			zephir_array_append(&exprValues, &_9$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3899);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&exprValue, _6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$8);
				zephir_create_array(&_16$$8, 2, 0);
				ZEPHIR_OBS_NVAR(&_17$$8);
				zephir_array_fetch_string(&_17$$8, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3897);
				zephir_array_update_string(&_16$$8, SL("type"), &_17$$8, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_19$$8, 1);
				} else {
					ZVAL_BOOL(&_19$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_18$$8, this_ptr, "getexpression", &_13, 0, &exprValue, &_19$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_16$$8, SL("value"), &_18$$8, PH_COPY | PH_SEPARATE);
				zephir_array_append(&exprValues, &_16$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3899);
		}
	}
	ZEPHIR_INIT_NVAR(&exprValue);
	ZEPHIR_INIT_VAR(&sqlInsert);
	zephir_create_array(&sqlInsert, 2, 0);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1066, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	zephir_memory_observe(&fields);
	if (zephir_array_isset_string_fetch(&fields, &ast, SL("fields"), 0)) {
		ZEPHIR_INIT_VAR(&sqlFields);
		array_init(&sqlFields);
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_21$$9);
			zephir_string_to_char_array(&_21$$9, &fields);
			_20$$9 = &_21$$9;
		} else {
			_20$$9 = &fields;
		}
		zephir_is_iterable(_20$$9, 0, "phalcon/Mvc/Model/Query.zep", 3924);
		if (Z_TYPE_P(_20$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_20$$9), _22$$9)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _22$$9);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3913);
				ZEPHIR_CALL_METHOD(&_23$$10, &metaData, "hasattribute", &_24, 0, &model, &name);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_23$$10))) {
					ZEPHIR_INIT_NVAR(&_25$$11);
					object_init_ex(&_25$$11, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
					zephir_read_property_cached(&_26$$11, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_25$$11, "__construct", &_27, 0, &modelName, &name, &_26$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_25$$11, "phalcon/Mvc/Model/Query.zep", 3917);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3921);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _20$$9, "rewind", NULL, 0);
			zephir_check_call_status();
			_29$$9 = 1;
			while (1) {
				if (_29$$9) {
					_29$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _20$$9, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_28$$9, _20$$9, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_28$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _20$$9, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3913);
					ZEPHIR_CALL_METHOD(&_30$$12, &metaData, "hasattribute", &_31, 0, &model, &name);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_30$$12))) {
						ZEPHIR_INIT_NVAR(&_32$$13);
						object_init_ex(&_32$$13, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
						zephir_read_property_cached(&_33$$13, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_32$$13, "__construct", &_27, 0, &modelName, &name, &_33$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_32$$13, "phalcon/Mvc/Model/Query.zep", 3917);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3921);
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&sqlInsert);
}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareSelect)
{
	zend_string *_88$$56, *_91$$56, *_94$$56, *_97$$56, *_100$$56, *_103$$56;
	zend_ulong _87$$56, _90$$56, _93$$56, _96$$56, _99$$56, _102$$56;
	zval _18$$24, _35$$29, _59$$45, _74$$50, _115$$76, _120$$83, _129$$91, _134$$98;
	zval models, modelsInstances, sqlAliases, sqlAliasesModels, sqlAliasesModelsInstances, sqlColumns, sqlModels, sqlModelsAliases, sqlTables, _29$$24, _30$$24, _31$$24, _44$$29, _45$$29, _46$$29, _68$$45, _69$$45, _70$$45, _83$$50, _84$$50, _85$$50;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_19 = NULL, *_21 = NULL, *_24 = NULL, *_27 = NULL, *_36 = NULL, *_38 = NULL, *_49 = NULL, *_60 = NULL, *_62 = NULL, *_75 = NULL, *_77 = NULL, *_109 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zend_bool merge, _48, _122, _33$$21, _72$$42, _117$$70, _131$$85;
	zval *ast = NULL, ast_sub, *merge_param = NULL, __$null, __$true, alias, automaticJoins, bestAlias, column, columns, completeSource, distinct, eagerType, groupBy, having, joinAlias, joins, limit, manager, mergeKey, mergeValue, metaData, model, modelName, order, qualifiedName, relation, relationModel, relations, schema, select, selectColumns, selectedModel, selectedModels, source, sqlColumn, sqlColumnAliases, sqlJoins, sqlSelect, tables, where, with, withItem, withs, tempModels, tempModelsInstances, tempSqlAliasesModels, tempSqlAliasesModelsInstances, tempSqlModelsAliases, tempSqlAliases, _3, *_6, _7, *_8, _47, *_105, _106, *_107, _121, _135, _0$$3, _1$$5, _2$$6, _4$$11, _5$$12, _10$$17, _11$$17, _13$$19, *_14$$21, _15$$21, *_16$$21, _32$$21, _17$$24, _20$$25, _22$$27, _23$$27, _25$$28, _26$$28, _28$$26, _34$$29, _37$$30, _39$$32, _40$$32, _41$$33, _42$$33, _43$$31, _50$$35, _51$$38, _52$$38, _53$$40, _54$$43, *_55$$42, _56$$42, *_57$$42, _71$$42, _58$$45, _61$$46, _63$$48, _64$$48, _65$$49, _66$$49, _67$$47, _73$$50, _76$$51, _78$$53, _79$$53, _80$$54, _81$$54, _82$$52, *_86$$56, *_89$$56, *_92$$56, *_95$$56, *_98$$56, *_101$$56, _104$$65, _108$$70, *_110$$70, _111$$70, *_112$$70, _116$$70, _113$$75, _114$$76, _118$$82, _119$$83, _123$$85, *_124$$85, _125$$85, *_126$$85, _130$$85, _127$$90, _128$$91, _132$$97, _133$$98, _136$$102, _137$$103, _138$$104, _139$$105, _140$$106;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ast_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&automaticJoins);
	ZVAL_UNDEF(&bestAlias);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&eagerType);
	ZVAL_UNDEF(&groupBy);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&mergeKey);
	ZVAL_UNDEF(&mergeValue);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relationModel);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&selectedModel);
	ZVAL_UNDEF(&selectedModels);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&sqlColumnAliases);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&with);
	ZVAL_UNDEF(&withItem);
	ZVAL_UNDEF(&withs);
	ZVAL_UNDEF(&tempModels);
	ZVAL_UNDEF(&tempModelsInstances);
	ZVAL_UNDEF(&tempSqlAliasesModels);
	ZVAL_UNDEF(&tempSqlAliasesModelsInstances);
	ZVAL_UNDEF(&tempSqlModelsAliases);
	ZVAL_UNDEF(&tempSqlAliases);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_121);
	ZVAL_UNDEF(&_135);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_15$$21);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_22$$27);
	ZVAL_UNDEF(&_23$$27);
	ZVAL_UNDEF(&_25$$28);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_37$$30);
	ZVAL_UNDEF(&_39$$32);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$33);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_51$$38);
	ZVAL_UNDEF(&_52$$38);
	ZVAL_UNDEF(&_53$$40);
	ZVAL_UNDEF(&_54$$43);
	ZVAL_UNDEF(&_56$$42);
	ZVAL_UNDEF(&_71$$42);
	ZVAL_UNDEF(&_58$$45);
	ZVAL_UNDEF(&_61$$46);
	ZVAL_UNDEF(&_63$$48);
	ZVAL_UNDEF(&_64$$48);
	ZVAL_UNDEF(&_65$$49);
	ZVAL_UNDEF(&_66$$49);
	ZVAL_UNDEF(&_67$$47);
	ZVAL_UNDEF(&_73$$50);
	ZVAL_UNDEF(&_76$$51);
	ZVAL_UNDEF(&_78$$53);
	ZVAL_UNDEF(&_79$$53);
	ZVAL_UNDEF(&_80$$54);
	ZVAL_UNDEF(&_81$$54);
	ZVAL_UNDEF(&_82$$52);
	ZVAL_UNDEF(&_104$$65);
	ZVAL_UNDEF(&_108$$70);
	ZVAL_UNDEF(&_111$$70);
	ZVAL_UNDEF(&_116$$70);
	ZVAL_UNDEF(&_113$$75);
	ZVAL_UNDEF(&_114$$76);
	ZVAL_UNDEF(&_118$$82);
	ZVAL_UNDEF(&_119$$83);
	ZVAL_UNDEF(&_123$$85);
	ZVAL_UNDEF(&_125$$85);
	ZVAL_UNDEF(&_130$$85);
	ZVAL_UNDEF(&_127$$90);
	ZVAL_UNDEF(&_128$$91);
	ZVAL_UNDEF(&_132$$97);
	ZVAL_UNDEF(&_133$$98);
	ZVAL_UNDEF(&_136$$102);
	ZVAL_UNDEF(&_137$$103);
	ZVAL_UNDEF(&_138$$104);
	ZVAL_UNDEF(&_139$$105);
	ZVAL_UNDEF(&_140$$106);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_69$$45);
	ZVAL_UNDEF(&_70$$45);
	ZVAL_UNDEF(&_83$$50);
	ZVAL_UNDEF(&_84$$50);
	ZVAL_UNDEF(&_85$$50);
	ZVAL_UNDEF(&_18$$24);
	ZVAL_UNDEF(&_35$$29);
	ZVAL_UNDEF(&_59$$45);
	ZVAL_UNDEF(&_74$$50);
	ZVAL_UNDEF(&_115$$76);
	ZVAL_UNDEF(&_120$$83);
	ZVAL_UNDEF(&_129$$91);
	ZVAL_UNDEF(&_134$$98);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("ast", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("metaData", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("phql", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("sqlAliasesModels", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("sqlModelsAliases", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("sqlAliasesModelsInstances", 25, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("nestingLevel", 12, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ast)
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &ast, &merge_param);
	if (!ast) {
		ast = &ast_sub;
		ZEPHIR_CPY_WRT(ast, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(ast);
	}
	if (!merge_param) {
		merge = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&tempModels);
	array_init(&tempModels);
	ZEPHIR_INIT_VAR(&tempModelsInstances);
	array_init(&tempModelsInstances);
	ZEPHIR_INIT_VAR(&tempSqlAliasesModels);
	array_init(&tempSqlAliasesModels);
	ZEPHIR_INIT_VAR(&tempSqlAliasesModelsInstances);
	array_init(&tempSqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&tempSqlModelsAliases);
	array_init(&tempSqlModelsAliases);
	ZEPHIR_INIT_VAR(&tempSqlAliases);
	array_init(&tempSqlAliases);
	if (ZEPHIR_IS_EMPTY(ast)) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 1064, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(ast, &_0$$3);
	}
	zephir_memory_observe(&select);
	if (!(zephir_array_isset_string_fetch(&select, ast, SL("select"), 0))) {
		ZEPHIR_CPY_WRT(&select, ast);
	}
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &select, SL("tables"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model/Query.zep", 3963);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		object_init_ex(&_2$$6, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model/Query.zep", 3967);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("nestingLevel")));
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModels);
	array_init(&sqlAliasesModels);
	ZEPHIR_INIT_VAR(&sqlModelsAliases);
	array_init(&sqlModelsAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	if (!(zephir_array_isset_value_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectedModels);
		zephir_create_array(&selectedModels, 1, 0);
		zephir_array_fast_append(&selectedModels, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectedModels, &tables);
	}
	if (!(zephir_array_isset_value_long(&columns, 0))) {
		ZEPHIR_INIT_VAR(&selectColumns);
		zephir_create_array(&selectColumns, 1, 0);
		zephir_array_fast_append(&selectColumns, &columns);
	} else {
		ZEPHIR_CPY_WRT(&selectColumns, &columns);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_3);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 1066, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_3);
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_4$$11);
		object_init_ex(&_4$$11, phalcon_mvc_model_query_exceptions_missingmodelsmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$11, "phalcon/Mvc/Model/Query.zep", 4032);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_5$$12);
		object_init_ex(&_5$$12, phalcon_mvc_model_query_exceptions_missingmetadata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$12, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$12, "phalcon/Mvc/Model/Query.zep", 4036);
		ZEPHIR_MM_RESTORE();
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	if (Z_TYPE_P(&selectedModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &selectedModels);
		_6 = &_7;
	} else {
		_6 = &selectedModels;
	}
	zephir_is_iterable(_6, 0, "phalcon/Mvc/Model/Query.zep", 4179);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6), _8)
		{
			ZEPHIR_INIT_NVAR(&selectedModel);
			ZVAL_COPY(&selectedModel, _8);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4044);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4045);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_9, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&completeSource);
				zephir_create_array(&completeSource, 2, 0);
				zephir_array_fast_append(&completeSource, &source);
				zephir_array_fast_append(&completeSource, &schema);
			} else {
				ZEPHIR_CPY_WRT(&completeSource, &source);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0)) {
				if (UNEXPECTED(zephir_array_isset_value(&sqlAliases, &alias))) {
					ZEPHIR_INIT_NVAR(&_10$$17);
					object_init_ex(&_10$$17, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
					zephir_read_property_cached(&_11$$17, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_10$$17, "__construct", &_12, 0, &alias, &_11$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$17, "phalcon/Mvc/Model/Query.zep", 4068);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4080);
				} else {
					ZEPHIR_INIT_NVAR(&_13$$19);
					zephir_create_array(&_13$$19, 3, 0);
					zephir_array_fast_append(&_13$$19, &source);
					zephir_array_fast_append(&_13$$19, &__$null);
					zephir_array_fast_append(&_13$$19, &alias);
					ZEPHIR_CPY_WRT(&completeSource, &_13$$19);
				}
				zephir_array_update_zval(&models, &modelName, &alias, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_CPY_WRT(&alias, &source);
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&with);
			if (zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0)) {
				if (!(zephir_array_isset_value_long(&with, 0))) {
					ZEPHIR_INIT_NVAR(&withs);
					zephir_create_array(&withs, 1, 0);
					zephir_array_fast_append(&withs, &with);
				} else {
					ZEPHIR_CPY_WRT(&withs, &with);
				}
				if (Z_TYPE_P(&withs) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_15$$21);
					zephir_string_to_char_array(&_15$$21, &withs);
					_14$$21 = &_15$$21;
				} else {
					_14$$21 = &withs;
				}
				zephir_is_iterable(_14$$21, 0, "phalcon/Mvc/Model/Query.zep", 4171);
				if (Z_TYPE_P(_14$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14$$21), _16$$21)
					{
						ZEPHIR_INIT_NVAR(&withItem);
						ZVAL_COPY(&withItem, _16$$21);
						ZEPHIR_INIT_NVAR(&_17$$24);
						ZVAL_LONG(&_17$$24, number);
						ZEPHIR_INIT_NVAR(&_18$$24);
						ZEPHIR_CONCAT_SV(&_18$$24, "AA", &_17$$24);
						ZEPHIR_CPY_WRT(&joinAlias, &_18$$24);
						ZEPHIR_OBS_NVAR(&relationModel);
						zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4106);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_19, 0, &modelName, &relationModel);
						zephir_check_call_status();
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_20$$25);
							ZVAL_STRING(&_20$$25, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_20$$25);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_21, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
								ZEPHIR_INIT_NVAR(&_22$$27);
								object_init_ex(&_22$$27, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
								zephir_read_property_cached(&_23$$27, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_22$$27, "__construct", &_24, 0, &modelName, &relationModel, &_23$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_22$$27, "phalcon/Mvc/Model/Query.zep", 4129);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_25$$28);
								object_init_ex(&_25$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_26$$28, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_25$$28, "__construct", &_27, 0, &modelName, &relationModel, &_26$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_25$$28, "phalcon/Mvc/Model/Query.zep", 4136);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4142);
							ZEPHIR_INIT_NVAR(&_28$$26);
							ZVAL_STRING(&_28$$26, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_28$$26);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_29$$24);
						zephir_create_array(&_29$$24, 5, 0);
						add_assoc_long_ex(&_29$$24, SL("type"), 353);
						zephir_array_update_string(&_29$$24, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_29$$24, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_29$$24, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_29$$24, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
						zephir_array_append(&selectColumns, &_29$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4155);
						ZEPHIR_INIT_NVAR(&_30$$24);
						zephir_create_array(&_30$$24, 3, 0);
						add_assoc_long_ex(&_30$$24, SL("type"), 360);
						ZEPHIR_INIT_NVAR(&_31$$24);
						zephir_create_array(&_31$$24, 2, 0);
						add_assoc_long_ex(&_31$$24, SL("type"), 355);
						zephir_array_update_string(&_31$$24, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_30$$24, SL("qualified"), &_31$$24, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_31$$24);
						zephir_create_array(&_31$$24, 2, 0);
						add_assoc_long_ex(&_31$$24, SL("type"), 355);
						zephir_array_update_string(&_31$$24, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_30$$24, SL("alias"), &_31$$24, PH_COPY | PH_SEPARATE);
						zephir_array_append(&automaticJoins, &_30$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4167);
						number++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _14$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					_33$$21 = 1;
					while (1) {
						if (_33$$21) {
							_33$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _14$$21, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_32$$21, _14$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_32$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&withItem, _14$$21, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_34$$29);
							ZVAL_LONG(&_34$$29, number);
							ZEPHIR_INIT_NVAR(&_35$$29);
							ZEPHIR_CONCAT_SV(&_35$$29, "AA", &_34$$29);
							ZEPHIR_CPY_WRT(&joinAlias, &_35$$29);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4106);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_36, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_37$$30);
								ZVAL_STRING(&_37$$30, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_37$$30);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_38, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_39$$32);
									object_init_ex(&_39$$32, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_40$$32, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_39$$32, "__construct", &_24, 0, &modelName, &relationModel, &_40$$32);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_39$$32, "phalcon/Mvc/Model/Query.zep", 4129);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_41$$33);
									object_init_ex(&_41$$33, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_42$$33, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_41$$33, "__construct", &_27, 0, &modelName, &relationModel, &_42$$33);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_41$$33, "phalcon/Mvc/Model/Query.zep", 4136);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4142);
								ZEPHIR_INIT_NVAR(&_43$$31);
								ZVAL_STRING(&_43$$31, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_43$$31);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_44$$29);
							zephir_create_array(&_44$$29, 5, 0);
							add_assoc_long_ex(&_44$$29, SL("type"), 353);
							zephir_array_update_string(&_44$$29, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_44$$29, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_44$$29, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_44$$29, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_44$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4155);
							ZEPHIR_INIT_NVAR(&_45$$29);
							zephir_create_array(&_45$$29, 3, 0);
							add_assoc_long_ex(&_45$$29, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_46$$29);
							zephir_create_array(&_46$$29, 2, 0);
							add_assoc_long_ex(&_46$$29, SL("type"), 355);
							zephir_array_update_string(&_46$$29, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_45$$29, SL("qualified"), &_46$$29, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_46$$29);
							zephir_create_array(&_46$$29, 2, 0);
							add_assoc_long_ex(&_46$$29, SL("type"), 355);
							zephir_array_update_string(&_46$$29, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_45$$29, SL("alias"), &_46$$29, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_45$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4167);
							number++;
					}
				}
				ZEPHIR_INIT_NVAR(&withItem);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4173);
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4174);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_48 = 1;
		while (1) {
			if (_48) {
				_48 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_47, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_47)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&selectedModel, _6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4044);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4045);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_49, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_50$$35);
					zephir_create_array(&_50$$35, 2, 0);
					zephir_array_fast_append(&_50$$35, &source);
					zephir_array_fast_append(&_50$$35, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_50$$35);
				} else {
					ZEPHIR_CPY_WRT(&completeSource, &source);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0)) {
					if (UNEXPECTED(zephir_array_isset_value(&sqlAliases, &alias))) {
						ZEPHIR_INIT_NVAR(&_51$$38);
						object_init_ex(&_51$$38, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
						zephir_read_property_cached(&_52$$38, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_51$$38, "__construct", &_12, 0, &alias, &_52$$38);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_51$$38, "phalcon/Mvc/Model/Query.zep", 4068);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
						zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4080);
					} else {
						ZEPHIR_INIT_NVAR(&_53$$40);
						zephir_create_array(&_53$$40, 3, 0);
						zephir_array_fast_append(&_53$$40, &source);
						zephir_array_fast_append(&_53$$40, &__$null);
						zephir_array_fast_append(&_53$$40, &alias);
						ZEPHIR_CPY_WRT(&completeSource, &_53$$40);
					}
					zephir_array_update_zval(&models, &modelName, &alias, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_CPY_WRT(&alias, &source);
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&with);
				if (zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0)) {
					if (!(zephir_array_isset_value_long(&with, 0))) {
						ZEPHIR_INIT_NVAR(&_54$$43);
						zephir_create_array(&_54$$43, 1, 0);
						zephir_array_fast_append(&_54$$43, &with);
						ZEPHIR_CPY_WRT(&withs, &_54$$43);
					} else {
						ZEPHIR_CPY_WRT(&withs, &with);
					}
					if (Z_TYPE_P(&withs) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_56$$42);
						zephir_string_to_char_array(&_56$$42, &withs);
						_55$$42 = &_56$$42;
					} else {
						_55$$42 = &withs;
					}
					zephir_is_iterable(_55$$42, 0, "phalcon/Mvc/Model/Query.zep", 4171);
					if (Z_TYPE_P(_55$$42) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_55$$42), _57$$42)
						{
							ZEPHIR_INIT_NVAR(&withItem);
							ZVAL_COPY(&withItem, _57$$42);
							ZEPHIR_INIT_NVAR(&_58$$45);
							ZVAL_LONG(&_58$$45, number);
							ZEPHIR_INIT_NVAR(&_59$$45);
							ZEPHIR_CONCAT_SV(&_59$$45, "AA", &_58$$45);
							ZEPHIR_CPY_WRT(&joinAlias, &_59$$45);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4106);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_60, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_61$$46);
								ZVAL_STRING(&_61$$46, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_61$$46);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_62, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_63$$48);
									object_init_ex(&_63$$48, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_64$$48, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_63$$48, "__construct", &_24, 0, &modelName, &relationModel, &_64$$48);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_63$$48, "phalcon/Mvc/Model/Query.zep", 4129);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_65$$49);
									object_init_ex(&_65$$49, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_66$$49, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_65$$49, "__construct", &_27, 0, &modelName, &relationModel, &_66$$49);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_65$$49, "phalcon/Mvc/Model/Query.zep", 4136);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4142);
								ZEPHIR_INIT_NVAR(&_67$$47);
								ZVAL_STRING(&_67$$47, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_67$$47);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_68$$45);
							zephir_create_array(&_68$$45, 5, 0);
							add_assoc_long_ex(&_68$$45, SL("type"), 353);
							zephir_array_update_string(&_68$$45, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_68$$45, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_68$$45, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_68$$45, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_68$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4155);
							ZEPHIR_INIT_NVAR(&_69$$45);
							zephir_create_array(&_69$$45, 3, 0);
							add_assoc_long_ex(&_69$$45, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_70$$45);
							zephir_create_array(&_70$$45, 2, 0);
							add_assoc_long_ex(&_70$$45, SL("type"), 355);
							zephir_array_update_string(&_70$$45, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_69$$45, SL("qualified"), &_70$$45, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_70$$45);
							zephir_create_array(&_70$$45, 2, 0);
							add_assoc_long_ex(&_70$$45, SL("type"), 355);
							zephir_array_update_string(&_70$$45, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_69$$45, SL("alias"), &_70$$45, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_69$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4167);
							number++;
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _55$$42, "rewind", NULL, 0);
						zephir_check_call_status();
						_72$$42 = 1;
						while (1) {
							if (_72$$42) {
								_72$$42 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _55$$42, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_71$$42, _55$$42, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_71$$42)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&withItem, _55$$42, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_73$$50);
								ZVAL_LONG(&_73$$50, number);
								ZEPHIR_INIT_NVAR(&_74$$50);
								ZEPHIR_CONCAT_SV(&_74$$50, "AA", &_73$$50);
								ZEPHIR_CPY_WRT(&joinAlias, &_74$$50);
								ZEPHIR_OBS_NVAR(&relationModel);
								zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4106);
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_75, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_76$$51);
									ZVAL_STRING(&_76$$51, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_76$$51);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_77, 0, &modelName, &relationModel);
									zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
										ZEPHIR_INIT_NVAR(&_78$$53);
										object_init_ex(&_78$$53, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
										zephir_read_property_cached(&_79$$53, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_METHOD(NULL, &_78$$53, "__construct", &_24, 0, &modelName, &relationModel, &_79$$53);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_78$$53, "phalcon/Mvc/Model/Query.zep", 4129);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
										ZEPHIR_INIT_NVAR(&_80$$54);
										object_init_ex(&_80$$54, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
										zephir_read_property_cached(&_81$$54, this_ptr, _zephir_prop_3, 1054, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_METHOD(NULL, &_80$$54, "__construct", &_27, 0, &modelName, &relationModel, &_81$$54);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_80$$54, "phalcon/Mvc/Model/Query.zep", 4136);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&relation);
									zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4142);
									ZEPHIR_INIT_NVAR(&_82$$52);
									ZVAL_STRING(&_82$$52, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_82$$52);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_INIT_NVAR(&_83$$50);
								zephir_create_array(&_83$$50, 5, 0);
								add_assoc_long_ex(&_83$$50, SL("type"), 353);
								zephir_array_update_string(&_83$$50, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
								zephir_array_append(&selectColumns, &_83$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4155);
								ZEPHIR_INIT_NVAR(&_84$$50);
								zephir_create_array(&_84$$50, 3, 0);
								add_assoc_long_ex(&_84$$50, SL("type"), 360);
								ZEPHIR_INIT_NVAR(&_85$$50);
								zephir_create_array(&_85$$50, 2, 0);
								add_assoc_long_ex(&_85$$50, SL("type"), 355);
								zephir_array_update_string(&_85$$50, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_84$$50, SL("qualified"), &_85$$50, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_85$$50);
								zephir_create_array(&_85$$50, 2, 0);
								add_assoc_long_ex(&_85$$50, SL("type"), 355);
								zephir_array_update_string(&_85$$50, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_84$$50, SL("alias"), &_85$$50, PH_COPY | PH_SEPARATE);
								zephir_array_append(&automaticJoins, &_84$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4167);
								number++;
						}
					}
					ZEPHIR_INIT_NVAR(&withItem);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4173);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4174);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&selectedModel);
	if (!(merge)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1071, &models);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1070, &modelsInstances);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1072, &sqlAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1073, &sqlAliasesModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1074, &sqlModelsAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1075, &sqlAliasesModelsInstances);
	} else {
		ZEPHIR_OBS_NVAR(&tempModels);
		zephir_read_property_cached(&tempModels, this_ptr, _zephir_prop_4, 1071, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempModelsInstances);
		zephir_read_property_cached(&tempModelsInstances, this_ptr, _zephir_prop_5, 1070, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliases);
		zephir_read_property_cached(&tempSqlAliases, this_ptr, _zephir_prop_6, 1072, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModels);
		zephir_read_property_cached(&tempSqlAliasesModels, this_ptr, _zephir_prop_7, 1073, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlModelsAliases);
		zephir_read_property_cached(&tempSqlModelsAliases, this_ptr, _zephir_prop_8, 1074, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModelsInstances);
		zephir_read_property_cached(&tempSqlAliasesModelsInstances, this_ptr, _zephir_prop_9, 1075, PH_NOISY_CC);
		zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query.zep", 4203);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _87$$56, _88$$56, _86$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_88$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _88$$56);
			} else {
				ZVAL_LONG(&mergeKey, _87$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _86$$56);
			zephir_update_property_array(this_ptr, SL("models"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&modelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4207);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&modelsInstances), _90$$56, _91$$56, _89$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_91$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _91$$56);
			} else {
				ZVAL_LONG(&mergeKey, _90$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _89$$56);
			zephir_update_property_array(this_ptr, SL("modelsInstances"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliases, 0, "phalcon/Mvc/Model/Query.zep", 4211);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliases), _93$$56, _94$$56, _92$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_94$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _94$$56);
			} else {
				ZVAL_LONG(&mergeKey, _93$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _92$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliases"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModels, 0, "phalcon/Mvc/Model/Query.zep", 4215);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliasesModels), _96$$56, _97$$56, _95$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_97$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _97$$56);
			} else {
				ZVAL_LONG(&mergeKey, _96$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _95$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliasesModels"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlModelsAliases, 0, "phalcon/Mvc/Model/Query.zep", 4219);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlModelsAliases), _99$$56, _100$$56, _98$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_100$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _100$$56);
			} else {
				ZVAL_LONG(&mergeKey, _99$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _98$$56);
			zephir_update_property_array(this_ptr, SL("sqlModelsAliases"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4222);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliasesModelsInstances), _102$$56, _103$$56, _101$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_103$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _103$$56);
			} else {
				ZVAL_LONG(&mergeKey, _102$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _101$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliasesModelsInstances"), &mergeKey, &mergeValue);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
	}
	zephir_memory_observe(&joins);
	zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (!(ZEPHIR_IS_EMPTY(&joins))) {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			if (zephir_array_isset_value_long(&joins, 0)) {
				ZEPHIR_INIT_VAR(&_104$$65);
				zephir_fast_array_merge(&_104$$65, &joins, &automaticJoins);
				zephir_array_update_string(&select, SL("joins"), &_104$$65, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&automaticJoins, &joins, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4232);
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getjoins", NULL, 0, &select);
		zephir_check_call_status();
	} else {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getjoins", NULL, 0, &select);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&sqlJoins);
			array_init(&sqlJoins);
		}
	}
	position = 0;
	ZEPHIR_INIT_VAR(&sqlColumnAliases);
	array_init(&sqlColumnAliases);
	if (Z_TYPE_P(&selectColumns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_106);
		zephir_string_to_char_array(&_106, &selectColumns);
		_105 = &_106;
	} else {
		_105 = &selectColumns;
	}
	zephir_is_iterable(_105, 0, "phalcon/Mvc/Model/Query.zep", 4283);
	if (Z_TYPE_P(_105) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_105), _107)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _107);
			ZEPHIR_CALL_METHOD(&_108$$70, this_ptr, "getselectcolumn", &_109, 0, &column);
			zephir_check_call_status();
			if (Z_TYPE_P(&_108$$70) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_111$$70);
				zephir_string_to_char_array(&_111$$70, &_108$$70);
				_110$$70 = &_111$$70;
			} else {
				_110$$70 = &_108$$70;
			}
			zephir_is_iterable(_110$$70, 0, "phalcon/Mvc/Model/Query.zep", 4281);
			if (Z_TYPE_P(_110$$70) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_110$$70), _112$$70)
				{
					ZEPHIR_INIT_NVAR(&sqlColumn);
					ZVAL_COPY(&sqlColumn, _112$$70);
					ZEPHIR_OBS_NVAR(&alias);
					if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
						zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
						zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_string(&_113$$75, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4271);
							if (ZEPHIR_IS_STRING(&_113$$75, "scalar")) {
								ZEPHIR_INIT_NVAR(&_114$$76);
								ZVAL_LONG(&_114$$76, position);
								ZEPHIR_INIT_NVAR(&_115$$76);
								ZEPHIR_CONCAT_SV(&_115$$76, "_", &_114$$76);
								zephir_array_update_zval(&sqlColumns, &_115$$76, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4274);
							}
						}
					}
					position++;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _110$$70, "rewind", NULL, 0);
				zephir_check_call_status();
				_117$$70 = 1;
				while (1) {
					if (_117$$70) {
						_117$$70 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _110$$70, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_116$$70, _110$$70, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_116$$70)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&sqlColumn, _110$$70, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_string(&_118$$82, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4271);
								if (ZEPHIR_IS_STRING(&_118$$82, "scalar")) {
									ZEPHIR_INIT_NVAR(&_119$$83);
									ZVAL_LONG(&_119$$83, position);
									ZEPHIR_INIT_NVAR(&_120$$83);
									ZEPHIR_CONCAT_SV(&_120$$83, "_", &_119$$83);
									zephir_array_update_zval(&sqlColumns, &_120$$83, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4274);
								}
							}
						}
						position++;
				}
			}
			ZEPHIR_INIT_NVAR(&sqlColumn);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _105, "rewind", NULL, 0);
		zephir_check_call_status();
		_122 = 1;
		while (1) {
			if (_122) {
				_122 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _105, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_121, _105, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_121)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, _105, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_123$$85, this_ptr, "getselectcolumn", &_109, 0, &column);
				zephir_check_call_status();
				if (Z_TYPE_P(&_123$$85) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_125$$85);
					zephir_string_to_char_array(&_125$$85, &_123$$85);
					_124$$85 = &_125$$85;
				} else {
					_124$$85 = &_123$$85;
				}
				zephir_is_iterable(_124$$85, 0, "phalcon/Mvc/Model/Query.zep", 4281);
				if (Z_TYPE_P(_124$$85) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_124$$85), _126$$85)
					{
						ZEPHIR_INIT_NVAR(&sqlColumn);
						ZVAL_COPY(&sqlColumn, _126$$85);
						ZEPHIR_OBS_NVAR(&alias);
						if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_fetch_string(&_127$$90, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4271);
								if (ZEPHIR_IS_STRING(&_127$$90, "scalar")) {
									ZEPHIR_INIT_NVAR(&_128$$91);
									ZVAL_LONG(&_128$$91, position);
									ZEPHIR_INIT_NVAR(&_129$$91);
									ZEPHIR_CONCAT_SV(&_129$$91, "_", &_128$$91);
									zephir_array_update_zval(&sqlColumns, &_129$$91, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4274);
								}
							}
						}
						position++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _124$$85, "rewind", NULL, 0);
					zephir_check_call_status();
					_131$$85 = 1;
					while (1) {
						if (_131$$85) {
							_131$$85 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _124$$85, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_130$$85, _124$$85, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_130$$85)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&sqlColumn, _124$$85, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&alias);
							if (zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0)) {
								zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
							} else {
								ZEPHIR_OBS_NVAR(&alias);
								if (zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0)) {
									zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_fetch_string(&_132$$97, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4271);
									if (ZEPHIR_IS_STRING(&_132$$97, "scalar")) {
										ZEPHIR_INIT_NVAR(&_133$$98);
										ZVAL_LONG(&_133$$98, position);
										ZEPHIR_INIT_NVAR(&_134$$98);
										ZEPHIR_CONCAT_SV(&_134$$98, "_", &_133$$98);
										zephir_array_update_zval(&sqlColumns, &_134$$98, &sqlColumn, PH_COPY | PH_SEPARATE);
									} else {
										zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4274);
									}
								}
							}
							position++;
					}
				}
				ZEPHIR_INIT_NVAR(&sqlColumn);
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&_135);
	zephir_read_property_cached(&_135, this_ptr, _zephir_prop_10, 1076, PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("sqlColumnAliases"), &_135, &sqlColumnAliases);
	ZEPHIR_INIT_VAR(&sqlSelect);
	zephir_create_array(&sqlSelect, 3, 0);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&distinct);
	if (zephir_array_isset_string_fetch(&distinct, &select, SL("distinct"), 0)) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&sqlJoins))) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, ast, SL("where"), 0)) {
		ZEPHIR_CALL_METHOD(&_136$$102, this_ptr, "getexpression", NULL, 0, &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_136$$102, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_137$$103, this_ptr, "getgroupclause", NULL, 0, &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_137$$103, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&having);
	if (zephir_array_isset_string_fetch(&having, ast, SL("having"), 0)) {
		ZEPHIR_CALL_METHOD(&_138$$104, this_ptr, "getexpression", NULL, 0, &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_138$$104, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&order);
	if (zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_139$$105, this_ptr, "getorderclause", NULL, 0, &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_139$$105, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_140$$106, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_140$$106, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(ast, SL("forUpdate"))) {
		zephir_array_update_string(&sqlSelect, SL("forUpdate"), &__$true, PH_COPY | PH_SEPARATE);
	}
	if (merge) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1071, &tempModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1070, &tempModelsInstances);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1072, &tempSqlAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1073, &tempSqlAliasesModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1074, &tempSqlModelsAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1075, &tempSqlAliasesModelsInstances);
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("nestingLevel")));
	RETURN_CCTOR(&sqlSelect);
}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareUpdate)
{
	zval _22$$21, _31$$22;
	zend_bool notQuoting = 0, _11, _27;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, updateTables, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, joins, sqlJoins, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, _0, *_4, _5, *_6, _10, *_15, _16, *_17, _26, _1$$3, _2$$4, _3$$5, _8$$9, _9$$10, _13$$14, _14$$15, _18$$21, _19$$21, _20$$21, _23$$21, _24$$21, _25$$21, _28$$22, _29$$22, _30$$22, _32$$22, _33$$22, _34$$22, _35$$24, _36$$24, _37$$25;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ast);
	ZVAL_UNDEF(&update);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&updateTables);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&sqlFields);
	ZVAL_UNDEF(&sqlValues);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&exprColumn);
	ZVAL_UNDEF(&sqlUpdate);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$21);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_31$$22);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("ast", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("manager", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("models", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("modelsInstances", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("sqlAliases", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("sqlAliasesModels", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("sqlModelsAliases", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("sqlAliasesModelsInstances", 25, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1064, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&update);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&update, &ast, SL("update"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 4361);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 4365);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&values);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&values, &update, SL("values"), 0)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 4369);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&models);
	array_init(&models);
	ZEPHIR_INIT_VAR(&modelsInstances);
	array_init(&modelsInstances);
	ZEPHIR_INIT_VAR(&sqlTables);
	array_init(&sqlTables);
	ZEPHIR_INIT_VAR(&sqlModels);
	array_init(&sqlModels);
	ZEPHIR_INIT_VAR(&sqlAliases);
	array_init(&sqlAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModels);
	array_init(&sqlAliasesModels);
	ZEPHIR_INIT_VAR(&sqlModelsAliases);
	array_init(&sqlModelsAliases);
	ZEPHIR_INIT_VAR(&sqlAliasesModelsInstances);
	array_init(&sqlAliasesModelsInstances);
	if (!(zephir_array_isset_value_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&updateTables);
		zephir_create_array(&updateTables, 1, 0);
		zephir_array_fast_append(&updateTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&updateTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&updateTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &updateTables);
		_4 = &_5;
	} else {
		_4 = &updateTables;
	}
	zephir_is_iterable(_4, 0, "phalcon/Mvc/Model/Query.zep", 4441);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _6);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4395);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4396);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_7, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_8$$9);
				zephir_create_array(&_8$$9, 2, 0);
				zephir_array_fast_append(&_8$$9, &source);
				zephir_array_fast_append(&_8$$9, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_8$$9);
			} else {
				ZEPHIR_INIT_NVAR(&_9$$10);
				zephir_create_array(&_9$$10, 2, 0);
				zephir_array_fast_append(&_9$$10, &source);
				zephir_array_fast_append(&_9$$10, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_9$$10);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4421);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4422);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4430);
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4434);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4395);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4396);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_12, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_13$$14);
					zephir_create_array(&_13$$14, 2, 0);
					zephir_array_fast_append(&_13$$14, &source);
					zephir_array_fast_append(&_13$$14, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_13$$14);
				} else {
					ZEPHIR_INIT_NVAR(&_14$$15);
					zephir_create_array(&_14$$15, 2, 0);
					zephir_array_fast_append(&_14$$15, &source);
					zephir_array_fast_append(&_14$$15, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_14$$15);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4421);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4422);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4430);
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4434);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1071, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1070, &modelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1072, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1073, &sqlAliasesModels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1074, &sqlModelsAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1075, &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	zephir_memory_observe(&joins);
	if (zephir_array_isset_string_fetch(&joins, &update, SL("joins"), 0)) {
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getjoins", NULL, 0, &update);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&sqlFields);
	array_init(&sqlFields);
	ZEPHIR_INIT_VAR(&sqlValues);
	array_init(&sqlValues);
	if (!(zephir_array_isset_value_long(&values, 0))) {
		ZEPHIR_INIT_VAR(&updateValues);
		zephir_create_array(&updateValues, 1, 0);
		zephir_array_fast_append(&updateValues, &values);
	} else {
		ZEPHIR_CPY_WRT(&updateValues, &values);
	}
	notQuoting = 0;
	if (Z_TYPE_P(&updateValues) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_16);
		zephir_string_to_char_array(&_16, &updateValues);
		_15 = &_16;
	} else {
		_15 = &updateValues;
	}
	zephir_is_iterable(_15, 0, "phalcon/Mvc/Model/Query.zep", 4480);
	if (Z_TYPE_P(_15) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15), _17)
		{
			ZEPHIR_INIT_NVAR(&updateValue);
			ZVAL_COPY(&updateValue, _17);
			zephir_array_fetch_string(&_19$$21, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4472);
			if (notQuoting) {
				ZVAL_BOOL(&_20$$21, 1);
			} else {
				ZVAL_BOOL(&_20$$21, 0);
			}
			ZEPHIR_CALL_METHOD(&_18$$21, this_ptr, "getexpression", &_21, 0, &_19$$21, &_20$$21);
			zephir_check_call_status();
			zephir_array_append(&sqlFields, &_18$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4472);
			ZEPHIR_OBS_NVAR(&exprColumn);
			zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4473);
			ZEPHIR_INIT_NVAR(&_22$$21);
			zephir_create_array(&_22$$21, 2, 0);
			ZEPHIR_OBS_NVAR(&_23$$21);
			zephir_array_fetch_string(&_23$$21, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4475);
			zephir_array_update_string(&_22$$21, SL("type"), &_23$$21, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_25$$21, 1);
			} else {
				ZVAL_BOOL(&_25$$21, 0);
			}
			ZEPHIR_CALL_METHOD(&_24$$21, this_ptr, "getexpression", &_21, 0, &exprColumn, &_25$$21);
			zephir_check_call_status();
			zephir_array_update_string(&_22$$21, SL("value"), &_24$$21, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlValues, &_22$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4477);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _15, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _15, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, _15, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&updateValue, _15, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_29$$22, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4472);
				if (notQuoting) {
					ZVAL_BOOL(&_30$$22, 1);
				} else {
					ZVAL_BOOL(&_30$$22, 0);
				}
				ZEPHIR_CALL_METHOD(&_28$$22, this_ptr, "getexpression", &_21, 0, &_29$$22, &_30$$22);
				zephir_check_call_status();
				zephir_array_append(&sqlFields, &_28$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4472);
				ZEPHIR_OBS_NVAR(&exprColumn);
				zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4473);
				ZEPHIR_INIT_NVAR(&_31$$22);
				zephir_create_array(&_31$$22, 2, 0);
				ZEPHIR_OBS_NVAR(&_32$$22);
				zephir_array_fetch_string(&_32$$22, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4475);
				zephir_array_update_string(&_31$$22, SL("type"), &_32$$22, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_34$$22, 1);
				} else {
					ZVAL_BOOL(&_34$$22, 0);
				}
				ZEPHIR_CALL_METHOD(&_33$$22, this_ptr, "getexpression", &_21, 0, &exprColumn, &_34$$22);
				zephir_check_call_status();
				zephir_array_update_string(&_31$$22, SL("value"), &_33$$22, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlValues, &_31$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4477);
		}
	}
	ZEPHIR_INIT_NVAR(&updateValue);
	ZEPHIR_INIT_VAR(&sqlUpdate);
	zephir_create_array(&sqlUpdate, 4, 0);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	if (!(ZEPHIR_IS_EMPTY(&sqlJoins))) {
		zephir_array_update_string(&sqlUpdate, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_36$$24, 1);
		ZEPHIR_CALL_METHOD(&_35$$24, this_ptr, "getexpression", &_21, 0, &where, &_36$$24);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_35$$24, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_37$$25, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_37$$25, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlUpdate);
}

/**
 * Refreshes the schema/source of every model referenced in a cached
 * intermediate representation. The PHQL cache is keyed by the PHQL
 * string only, so a model that switches its schema or source at
 * runtime (for instance via setSchema()/setSource() in initialize())
 * would otherwise see the value frozen at first parse. See #17020.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, refreshSchemasInIntermediate)
{
	zend_bool _12, _7$$6, _14$$15;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *irPhql_param = NULL, __$null, manager, models, tables, modelName, model, schema, source, currentTable, alias, index, _0, *_1, _2, *_3, _11;
	zval irPhql, _8$$10, _9$$11, _10$$13, _15$$19, _16$$20, _17$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_15$$19);
	ZVAL_UNDEF(&_16$$20);
	ZVAL_UNDEF(&_17$$22);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&currentTable);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("manager", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(irPhql, irPhql_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &irPhql_param);
	zephir_get_arrval(&irPhql, irPhql_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1065, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&manager) != IS_OBJECT) {
		RETURN_CTOR(&irPhql);
	}
	zephir_memory_observe(&models);
	if (!(zephir_array_isset_string_fetch(&models, &irPhql, SL("models"), 0))) {
		RETURN_CTOR(&irPhql);
	}
	zephir_memory_observe(&tables);
	if (!(zephir_array_isset_string_fetch(&tables, &irPhql, SL("tables"), 0))) {
		RETURN_CTOR(&irPhql);
	}
	if (Z_TYPE_P(&models) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &models);
		_1 = &_2;
	} else {
		_1 = &models;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 4564);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&index, _5);
			} else {
				ZVAL_LONG(&index, _4);
			}
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _3);
			if (!(zephir_array_isset_value(&tables, &index))) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4536);
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_NULL(&alias);
			_7$$6 = Z_TYPE_P(&currentTable) == IS_ARRAY;
			if (_7$$6) {
				_7$$6 = zephir_array_isset_value_long(&currentTable, 2);
			}
			if (_7$$6) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4546);
			}
			if (zephir_is_true(&schema)) {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_8$$10);
					zephir_create_array(&_8$$10, 3, 0);
					zephir_array_fast_append(&_8$$10, &source);
					zephir_array_fast_append(&_8$$10, &schema);
					zephir_array_fast_append(&_8$$10, &alias);
					zephir_array_update_zval(&tables, &index, &_8$$10, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_9$$11);
					zephir_create_array(&_9$$11, 2, 0);
					zephir_array_fast_append(&_9$$11, &source);
					zephir_array_fast_append(&_9$$11, &schema);
					zephir_array_update_zval(&tables, &index, &_9$$11, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_10$$13);
					zephir_create_array(&_10$$13, 3, 0);
					zephir_array_fast_append(&_10$$13, &source);
					zephir_array_fast_append(&_10$$13, &__$null);
					zephir_array_fast_append(&_10$$13, &alias);
					zephir_array_update_zval(&tables, &index, &_10$$13, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&modelName, _1, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset_value(&tables, &index))) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_13, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&currentTable);
				zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4536);
				ZEPHIR_INIT_NVAR(&alias);
				ZVAL_NULL(&alias);
				_14$$15 = Z_TYPE_P(&currentTable) == IS_ARRAY;
				if (_14$$15) {
					_14$$15 = zephir_array_isset_value_long(&currentTable, 2);
				}
				if (_14$$15) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4546);
				}
				if (zephir_is_true(&schema)) {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_15$$19);
						zephir_create_array(&_15$$19, 3, 0);
						zephir_array_fast_append(&_15$$19, &source);
						zephir_array_fast_append(&_15$$19, &schema);
						zephir_array_fast_append(&_15$$19, &alias);
						zephir_array_update_zval(&tables, &index, &_15$$19, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_16$$20);
						zephir_create_array(&_16$$20, 2, 0);
						zephir_array_fast_append(&_16$$20, &source);
						zephir_array_fast_append(&_16$$20, &schema);
						zephir_array_update_zval(&tables, &index, &_16$$20, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_17$$22);
						zephir_create_array(&_17$$22, 3, 0);
						zephir_array_fast_append(&_17$$22, &source);
						zephir_array_fast_append(&_17$$22, &__$null);
						zephir_array_fast_append(&_17$$22, &alias);
						zephir_array_update_zval(&tables, &index, &_17$$22, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	ZEPHIR_INIT_NVAR(&index);
	zephir_array_update_string(&irPhql, SL("tables"), &tables, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(&irPhql);
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _10, _12, _14, _16, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8, _13$$9, _15$$10, _17$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_17$$11);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("sqlModelsAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sqlModelsAliases"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sqlColumnAliases"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sqlAliasesModels"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("sqlAliases"), &_9$$7);
		}
		zephir_read_property_ex(&_10, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("modelsInstances"), &_11$$8);
		}
		zephir_read_property_ex(&_12, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_12) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_13$$9);
			array_init(&_13$$9);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("models"), &_13$$9);
		}
		zephir_read_property_ex(&_14, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_14) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_15$$10);
			array_init(&_15$$10);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindTypes"), &_15$$10);
		}
		zephir_read_property_ex(&_16, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_16) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_17$$11);
			array_init(&_17$$11);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindParams"), &_17$$11);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

