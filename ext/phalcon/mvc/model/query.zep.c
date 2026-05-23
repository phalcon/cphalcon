
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
#include "ext/spl/spl_exceptions.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "phalcon/mvc/model/orm.h"


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
 * $phql = 'SELECT * FROM robot';
 *
 * $myTransaction = new Transaction($di);
 * $myTransaction->begin();
 *
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->type = "mechanical";
 * $newRobot->name = "Astro Boy";
 * $newRobot->year = 1952;
 * $newRobot->save();
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
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_query_ce, SL("uniqueRow"), 0, ZEND_ACC_PROTECTED);
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
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("internalPhqlCache"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("phql"), &phql_zv);
	if (Z_TYPE_P(container) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, container);
		zephir_check_call_status();
	}
	zephir_memory_observe(&enableImplicitJoins);
	if (zephir_array_isset_string_fetch(&enableImplicitJoins, &options, SL("enable_implicit_joins"), 0)) {
		if (ZEPHIR_IS_TRUE(&enableImplicitJoins)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("enableImplicitJoins"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("enableImplicitJoins"), &__$false);
		}
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_STRING(&_1$$5, "orm.enable_implicit_joins");
		ZEPHIR_CALL_CE_STATIC(&_0$$5, phalcon_support_settings_ce, "get", NULL, 0, &_1$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("enableImplicitJoins"), &_0$$5);
	}
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &_3);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(cacheOptions, cacheOptions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &cacheOptions_param);
	zephir_get_arrval(&cacheOptions, cacheOptions_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cacheOptions"), &cacheOptions);
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
	zval *bindParams_param = NULL, *bindTypes_param = NULL, adapter, cache, cacheLifetime, cacheOptions, cacheService, defaultBindParams, defaultBindTypes, intermediate, key, lifetime, mergedParams, mergedTypes, preparedResult, result, type, uniqueRow, _0, _1$$4, _2$$5, _3$$3, _4$$3, _5$$3, _7$$3, _6$$7, _8$$11, _9$$10, _10$$20, _11$$22;
	zval bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&cacheLifetime);
	ZVAL_UNDEF(&cacheOptions);
	ZVAL_UNDEF(&cacheService);
	ZVAL_UNDEF(&defaultBindParams);
	ZVAL_UNDEF(&defaultBindTypes);
	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&mergedParams);
	ZVAL_UNDEF(&mergedTypes);
	ZVAL_UNDEF(&preparedResult);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&uniqueRow);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueRow"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueRow, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cacheOptions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cacheOptions, &_0);
	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (UNEXPECTED(Z_TYPE_P(&cacheOptions) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_model_query_exceptions_invalidcachingoptions_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model/Query.zep", 336);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&key);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0)))) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_missingcachekey_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 343);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&cacheService);
		if (!(zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0))) {
			ZEPHIR_INIT_NVAR(&cacheService);
			ZVAL_STRING(&cacheService, "modelsCache");
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&cache, &_3$$3, "getshared", NULL, 0, &cacheService);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Phalcon\\Cache\\CacheInterface");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_a", NULL, 158, &cache, &_4$$3);
		zephir_check_call_status();
		if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_5$$3))) {
			ZEPHIR_INIT_VAR(&_6$$7);
			object_init_ex(&_6$$7, phalcon_mvc_model_query_exceptions_invalidquerycacheservice_ce);
			ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model/Query.zep", 353);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&adapter, &cache, "getadapter", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&cacheLifetime, &adapter, "getlifetime", NULL, 0);
		zephir_check_call_status();
		zephir_memory_observe(&lifetime);
		if (!(zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0))) {
			ZEPHIR_CPY_WRT(&lifetime, &cacheLifetime);
		}
		ZEPHIR_INIT_VAR(&result);
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
				zephir_throw_exception_debug(&_8$$11, "phalcon/Mvc/Model/Query.zep", 374);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &cache);
	}
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&defaultBindParams);
	zephir_read_property(&defaultBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_add_function(&mergedParams, &defaultBindParams, &bindParams);
	zephir_memory_observe(&defaultBindTypes);
	zephir_read_property(&defaultBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(&defaultBindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&mergedTypes);
		zephir_add_function(&mergedTypes, &defaultBindTypes, &bindTypes);
	} else {
		ZEPHIR_CPY_WRT(&mergedTypes, &bindTypes);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&type, &_0);
	do {
		if (ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "executeselect", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 306)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "executeinsert", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 300)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "executeupdate", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(&type, 303)) {
			ZEPHIR_CALL_METHOD(&result, this_ptr, "executedelete", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_VAR(&_10$$20);
		object_init_ex(&_10$$20, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
		ZEPHIR_CALL_METHOD(NULL, &_10$$20, "__construct", NULL, 0, &type);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$20, "phalcon/Mvc/Model/Query.zep", 457);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_INIT_VAR(&_11$$22);
			object_init_ex(&_11$$22, phalcon_mvc_model_query_exceptions_resultsetnoncacheable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$22, "phalcon/Mvc/Model/Query.zep", 468);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("uniqueRow"), PH_NOISY_CC | PH_READONLY);
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
 *     'sql' => 'SELECT * FROM parts WHERE robot = :robot',
 *     'bind' => ['robot' => 123],
 *     'bindTypes => ['robot' => 1] // 1 corresponds to int
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("type"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 309)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executeselect", NULL, 0, &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_mvc_model_query_exceptions_multiplesqlstatementsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "phalcon/Mvc/Model/Query.zep", 580);
	ZEPHIR_MM_RESTORE();
	return;
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
 * @return TransactionInterface|null
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getTransaction)
{

	RETURN_MEMBER(getThis(), "transaction");
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("intermediate"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&intermediate, &_0);
	if (Z_TYPE_P(&intermediate) == IS_ARRAY) {
		RETURN_CCTOR(&intermediate);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
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
					zephir_array_fetch_string(&_2$$7, &ast, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 645);
					zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_2$$7);
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "refreshschemasinintermediate", NULL, 0, &irPhql);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
		zephir_memory_observe(&type);
		if (zephir_array_isset_string_fetch(&type, &ast, SL("type"), 0)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("ast"), &ast);
			zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
			do {
				if (ZEPHIR_IS_LONG(&type, 309)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareselect", NULL, 0);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 306)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareinsert", NULL, 0);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 300)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_prepareupdate", NULL, 0);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&type, 303)) {
					ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "_preparedelete", NULL, 0);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_INIT_VAR(&_3$$13);
				object_init_ex(&_3$$13, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$13, "__construct", NULL, 0, &type, &phql);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$13, "phalcon/Mvc/Model/Query.zep", 685);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	if (UNEXPECTED(Z_TYPE_P(&irPhql) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_4$$14);
		object_init_ex(&_4$$14, phalcon_mvc_model_query_exceptions_corruptedast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$14, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$14, "phalcon/Mvc/Model/Query.zep", 691);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &irPhql, SL("z"), 1, &uniqueId);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("intermediate"), &irPhql);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindParams, bindParams_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindParams_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindParams, bindParams_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (merge) {
		zephir_memory_observe(&currentBindParams);
		zephir_read_property(&currentBindParams, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindParams"), &bindParams);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(bindTypes, bindTypes_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(merge)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &bindTypes_param, &merge_param);
	ZEPHIR_OBS_COPY_OR_DUP(&bindTypes, bindTypes_param);
	if (!merge_param) {
		merge = 0;
	} else {
		}
	if (UNEXPECTED(merge)) {
		zephir_memory_observe(&currentBindTypes);
		zephir_read_property(&currentBindTypes, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &_0$$4);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindTypes"), &bindTypes);
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
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 755);
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
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 761);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("manager"), &manager);
	zephir_update_property_zval(this_ptr, ZEND_STRL("metaData"), &metaData);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(intermediate, intermediate_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &intermediate_param);
	ZEPHIR_OBS_COPY_OR_DUP(&intermediate, intermediate_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("intermediate"), &intermediate);
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
		zephir_update_property_zval(this_ptr, ZEND_STRL("sharedLock"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("sharedLock"), &__$false);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &transaction);
	zephir_update_property_zval(this_ptr, ZEND_STRL("transaction"), transaction);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &type_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_0);
	RETURN_THISW();
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(uniqueRow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &uniqueRow_param);
	if (uniqueRow) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueRow"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("uniqueRow"), &__$false);
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
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 829);
	if (UNEXPECTED(zephir_array_isset_value_long(&models, 1))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_deletemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 832);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 835);
	zephir_memory_observe(&model);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_1, &modelName, 0))) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
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
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 894);
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
	zend_string *_7;
	zend_ulong _6;
	zend_bool automaticFields = 0, _19$$8, _32$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_15 = NULL, *_17 = NULL, *_18 = NULL, *_21 = NULL, *_24 = NULL, *_26 = NULL, *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, modelName, manager, connection, metaData, attributes, fields, columnMap, dialect, insertValues, number, value, model, values, exprValue, insertValue, wildcard, fieldName, attributeName, insertModel, _0, _1, *_5, _22, _34, _2$$4, _3$$4, _4$$7, _8$$8, _10$$11, _12$$11, _13$$11, _14$$12, _16$$13, _20$$15, _23$$17, _25$$20, _27$$20, _28$$20, _29$$21, _30$$22, _33$$24;
	zval intermediate, bindParams, bindTypes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&insertValues);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&insertValue);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&insertModel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_33$$24);
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
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &intermediate, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 922);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&model);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_0, &modelName, 0))) {
		ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
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
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 957);
	if (UNEXPECTED(zephir_fast_count_int(&fields) != zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_4$$7);
		object_init_ex(&_4$$7, phalcon_mvc_model_query_exceptions_insertcolumncountmismatch_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$7, "phalcon/Mvc/Model/Query.zep", 964);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	zephir_is_iterable(&values, 0, "phalcon/Mvc/Model/Query.zep", 1031);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&number, _7);
			} else {
				ZVAL_LONG(&number, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _5);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 974);
			zephir_array_fetch_string(&_8$$8, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 976);
			do {
				if (ZEPHIR_IS_LONG(&_8$$8, 260) || ZEPHIR_IS_LONG(&_8$$8, 258) || ZEPHIR_IS_LONG(&_8$$8, 259)) {
					ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_9, 0, &exprValue);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&_8$$8, 322)) {
					ZEPHIR_INIT_NVAR(&insertValue);
					ZVAL_NULL(&insertValue);
					break;
				}
				if (ZEPHIR_IS_LONG(&_8$$8, 273) || ZEPHIR_IS_LONG(&_8$$8, 274) || ZEPHIR_IS_LONG(&_8$$8, 277)) {
					ZEPHIR_CALL_METHOD(&_10$$11, &dialect, "getsqlexpression", &_11, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_12$$11);
					ZVAL_STRING(&_12$$11, ":");
					ZEPHIR_INIT_NVAR(&_13$$11);
					ZVAL_STRING(&_13$$11, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_12$$11, &_13$$11, &_10$$11);
					ZEPHIR_OBS_NVAR(&insertValue);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0)))) {
						ZEPHIR_INIT_NVAR(&_14$$12);
						object_init_ex(&_14$$12, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", &_15, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_14$$12, "phalcon/Mvc/Model/Query.zep", 998);
						ZEPHIR_MM_RESTORE();
						return;
					}
					break;
				}
				ZEPHIR_INIT_NVAR(&insertValue);
				object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_16$$13, &dialect, "getsqlexpression", &_17, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_18, 62, &_16$$13);
				zephir_check_call_status();
				break;
			} while(0);

			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1011);
			_19$$8 = automaticFields;
			if (_19$$8) {
				_19$$8 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			}
			if (_19$$8) {
				ZEPHIR_OBS_NVAR(&attributeName);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0)))) {
					ZEPHIR_INIT_NVAR(&_20$$15);
					object_init_ex(&_20$$15, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
					ZEPHIR_CALL_METHOD(NULL, &_20$$15, "__construct", &_21, 0, &fieldName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$15, "phalcon/Mvc/Model/Query.zep", 1019);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeName, &fieldName);
			}
			zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_22, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 974);
				zephir_array_fetch_string(&_23$$17, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 976);
				do {
					if (ZEPHIR_IS_LONG(&_23$$17, 260) || ZEPHIR_IS_LONG(&_23$$17, 258) || ZEPHIR_IS_LONG(&_23$$17, 259)) {
						ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getsqlexpression", &_24, 0, &exprValue);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_23$$17, 322)) {
						ZEPHIR_INIT_NVAR(&insertValue);
						ZVAL_NULL(&insertValue);
						break;
					}
					if (ZEPHIR_IS_LONG(&_23$$17, 273) || ZEPHIR_IS_LONG(&_23$$17, 274) || ZEPHIR_IS_LONG(&_23$$17, 277)) {
						ZEPHIR_CALL_METHOD(&_25$$20, &dialect, "getsqlexpression", &_26, 0, &exprValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_27$$20);
						ZVAL_STRING(&_27$$20, ":");
						ZEPHIR_INIT_NVAR(&_28$$20);
						ZVAL_STRING(&_28$$20, "");
						ZEPHIR_INIT_NVAR(&wildcard);
						zephir_fast_str_replace(&wildcard, &_27$$20, &_28$$20, &_25$$20);
						ZEPHIR_OBS_NVAR(&insertValue);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0)))) {
							ZEPHIR_INIT_NVAR(&_29$$21);
							object_init_ex(&_29$$21, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
							ZEPHIR_CALL_METHOD(NULL, &_29$$21, "__construct", &_15, 0, &wildcard);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_29$$21, "phalcon/Mvc/Model/Query.zep", 998);
							ZEPHIR_MM_RESTORE();
							return;
						}
						break;
					}
					ZEPHIR_INIT_NVAR(&insertValue);
					object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_30$$22, &dialect, "getsqlexpression", &_31, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_18, 62, &_30$$22);
					zephir_check_call_status();
					break;
				} while(0);

				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1011);
				_32$$17 = automaticFields;
				if (_32$$17) {
					_32$$17 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				}
				if (_32$$17) {
					ZEPHIR_OBS_NVAR(&attributeName);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0)))) {
						ZEPHIR_INIT_NVAR(&_33$$24);
						object_init_ex(&_33$$24, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
						ZEPHIR_CALL_METHOD(NULL, &_33$$24, "__construct", &_21, 0, &fieldName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_33$$24, "phalcon/Mvc/Model/Query.zep", 1019);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &fieldName);
				}
				zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&insertModel, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &insertModel, "assign", NULL, 0, &insertValues);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_34, &insertModel, "create", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_34, &insertModel);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the SELECT intermediate representation producing a
 * Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeSelect)
{
	zval _97$$86, _100$$87;
	zend_string *_27, *_78, *_84, *_91, *_113$$101;
	zend_ulong _26, _77, _83, _90, _112$$101;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_7 = NULL, *_10 = NULL, *_13 = NULL, *_20 = NULL, *_30 = NULL, *_31 = NULL, *_33 = NULL, *_35 = NULL, *_43 = NULL, *_55 = NULL, *_56 = NULL, *_59 = NULL, *_67 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isSimpleStd = 0, isKeepingSnapshots = 0, _4$$3, _14$$9, _51$$32, _75$$50, _92$$84, _120$$91;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *simulate_param = NULL, __$true, __$null, manager, modelName, models, model, connection, connectionTypes, columns, column, selectColumns, simpleColumnMap, metaData, aliasCopy, sqlColumn, attributes, instance, columnMap, attribute, columnAlias, sqlAlias, dialect, sqlSelect, bindCounts, processed, wildcard, value, processedTypes, typeWildcard, result, resultData, cache, resultObject, columns1, typesColumnMap, wildcardValue, resultsetClassName, _0, *_1, _11, *_18, _22, *_25, _52, *_76, _80, *_82, _86, *_89, _101, _2$$3, _5$$3, _8$$7, _9$$8, _12$$9, _15$$9, _16$$13, _17$$14, _19$$16, _21$$15, _23$$21, _24$$20, _28$$32, _29$$33, _32$$35, _34$$35, *_36$$35, _39$$35, _42$$35, _38$$38, _41$$39, _44$$40, *_45$$41, _47$$41, _49$$45, _50$$46, _53$$50, _54$$51, _57$$53, _58$$53, *_60$$53, _63$$53, _66$$53, _62$$56, _65$$57, _68$$58, *_69$$59, _71$$59, _73$$63, _74$$64, _79$$71, _81$$75, _85$$77, _87$$80, _88$$83, _93$$85, _94$$85, _95$$85, _96$$86, _98$$87, _99$$87, _102$$93, _103$$93, _119$$93, _104$$98, *_105$$98, _108$$98, _107$$99, _110$$100, *_111$$101, _116$$101, _115$$102, _118$$103, _126$$91, _121$$106, _122$$105, _123$$105, _124$$107;
	zval intermediate, bindParams, bindTypes, _37$$38, _40$$39, _46$$42, _48$$43, _61$$56, _64$$57, _70$$60, _72$$61, _106$$99, _109$$100, _114$$102, _117$$103, _125$$105;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_37$$38);
	ZVAL_UNDEF(&_40$$39);
	ZVAL_UNDEF(&_46$$42);
	ZVAL_UNDEF(&_48$$43);
	ZVAL_UNDEF(&_61$$56);
	ZVAL_UNDEF(&_64$$57);
	ZVAL_UNDEF(&_70$$60);
	ZVAL_UNDEF(&_72$$61);
	ZVAL_UNDEF(&_106$$99);
	ZVAL_UNDEF(&_109$$100);
	ZVAL_UNDEF(&_114$$102);
	ZVAL_UNDEF(&_117$$103);
	ZVAL_UNDEF(&_125$$105);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&connectionTypes);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&simpleColumnMap);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&aliasCopy);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&columnAlias);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&bindCounts);
	ZVAL_UNDEF(&processed);
	ZVAL_UNDEF(&wildcard);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&processedTypes);
	ZVAL_UNDEF(&typeWildcard);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&resultData);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&resultObject);
	ZVAL_UNDEF(&columns1);
	ZVAL_UNDEF(&typesColumnMap);
	ZVAL_UNDEF(&wildcardValue);
	ZVAL_UNDEF(&resultsetClassName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_80);
	ZVAL_UNDEF(&_86);
	ZVAL_UNDEF(&_101);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_28$$32);
	ZVAL_UNDEF(&_29$$33);
	ZVAL_UNDEF(&_32$$35);
	ZVAL_UNDEF(&_34$$35);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_42$$35);
	ZVAL_UNDEF(&_38$$38);
	ZVAL_UNDEF(&_41$$39);
	ZVAL_UNDEF(&_44$$40);
	ZVAL_UNDEF(&_47$$41);
	ZVAL_UNDEF(&_49$$45);
	ZVAL_UNDEF(&_50$$46);
	ZVAL_UNDEF(&_53$$50);
	ZVAL_UNDEF(&_54$$51);
	ZVAL_UNDEF(&_57$$53);
	ZVAL_UNDEF(&_58$$53);
	ZVAL_UNDEF(&_63$$53);
	ZVAL_UNDEF(&_66$$53);
	ZVAL_UNDEF(&_62$$56);
	ZVAL_UNDEF(&_65$$57);
	ZVAL_UNDEF(&_68$$58);
	ZVAL_UNDEF(&_71$$59);
	ZVAL_UNDEF(&_73$$63);
	ZVAL_UNDEF(&_74$$64);
	ZVAL_UNDEF(&_79$$71);
	ZVAL_UNDEF(&_81$$75);
	ZVAL_UNDEF(&_85$$77);
	ZVAL_UNDEF(&_87$$80);
	ZVAL_UNDEF(&_88$$83);
	ZVAL_UNDEF(&_93$$85);
	ZVAL_UNDEF(&_94$$85);
	ZVAL_UNDEF(&_95$$85);
	ZVAL_UNDEF(&_96$$86);
	ZVAL_UNDEF(&_98$$87);
	ZVAL_UNDEF(&_99$$87);
	ZVAL_UNDEF(&_102$$93);
	ZVAL_UNDEF(&_103$$93);
	ZVAL_UNDEF(&_119$$93);
	ZVAL_UNDEF(&_104$$98);
	ZVAL_UNDEF(&_108$$98);
	ZVAL_UNDEF(&_107$$99);
	ZVAL_UNDEF(&_110$$100);
	ZVAL_UNDEF(&_116$$101);
	ZVAL_UNDEF(&_115$$102);
	ZVAL_UNDEF(&_118$$103);
	ZVAL_UNDEF(&_126$$91);
	ZVAL_UNDEF(&_121$$106);
	ZVAL_UNDEF(&_122$$105);
	ZVAL_UNDEF(&_123$$105);
	ZVAL_UNDEF(&_124$$107);
	ZVAL_UNDEF(&_97$$86);
	ZVAL_UNDEF(&_100$$87);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&connectionTypes);
	array_init(&connectionTypes);
	zephir_memory_observe(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1068);
	zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query.zep", 1103);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&models), _1)
		{
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _1);
			ZEPHIR_OBS_NVAR(&model);
			zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset_fetch(&model, &_2$$3, &modelName, 0))) {
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_3, 0, &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
			}
			_4$$3 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
			if (_4$$3) {
				zephir_array_fetch_string(&_5$$3, &intermediate, SL("forUpdate"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1077);
				_4$$3 = zephir_is_true(&_5$$3);
			}
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", &_6, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_7, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&connection) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_8$$7, &connection, "gettype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&connectionTypes, &_8$$7, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
					ZEPHIR_INIT_NVAR(&_9$$8);
					object_init_ex(&_9$$8, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
					ZEPHIR_CALL_METHOD(NULL, &_9$$8, "__construct", &_10, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$8, "phalcon/Mvc/Model/Query.zep", 1098);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &models, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&modelName, &models, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&model);
				zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&model, &_12$$9, &modelName, 0))) {
					ZEPHIR_CALL_METHOD(&model, &manager, "load", &_13, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
				}
				_14$$9 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
				if (_14$$9) {
					zephir_array_fetch_string(&_15$$9, &intermediate, SL("forUpdate"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1077);
					_14$$9 = zephir_is_true(&_15$$9);
				}
				if (_14$$9) {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", &_6, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getreadconnection", &_7, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&connection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_16$$13, &connection, "gettype", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&connectionTypes, &_16$$13, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
						ZEPHIR_INIT_NVAR(&_17$$14);
						object_init_ex(&_17$$14, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
						ZEPHIR_CALL_METHOD(NULL, &_17$$14, "__construct", &_10, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$14, "phalcon/Mvc/Model/Query.zep", 1098);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	zephir_memory_observe(&columns);
	zephir_array_fetch_string(&columns, &intermediate, SL("columns"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1103);
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(&columns1, &columns);
	zephir_is_iterable(&columns, 0, "phalcon/Mvc/Model/Query.zep", 1131);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _18)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _18);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_19$$16);
				object_init_ex(&_19$$16, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
				ZEPHIR_CALL_METHOD(NULL, &_19$$16, "__construct", &_20, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$16, "phalcon/Mvc/Model/Query.zep", 1115);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_21$$15, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1118);
			if (ZEPHIR_IS_STRING(&_21$$15, "scalar")) {
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
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_22, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_23$$21);
					object_init_ex(&_23$$21, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
					ZEPHIR_CALL_METHOD(NULL, &_23$$21, "__construct", &_20, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$21, "phalcon/Mvc/Model/Query.zep", 1115);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch_string(&_24$$20, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1118);
				if (ZEPHIR_IS_STRING(&_24$$20, "scalar")) {
					if (!(zephir_array_isset_value_string(&column, SL("balias")))) {
						isComplex = 1;
					}
					haveScalars = 1;
				} else {
					haveObjects = 1;
					numberObjects++;
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	zephir_is_iterable(&columns, 0, "phalcon/Mvc/Model/Query.zep", 1237);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columns), _26, _27, _25)
		{
			ZEPHIR_INIT_NVAR(&aliasCopy);
			if (_27 != NULL) { 
				ZVAL_STR_COPY(&aliasCopy, _27);
			} else {
				ZVAL_LONG(&aliasCopy, _26);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _25);
			ZEPHIR_OBS_NVAR(&sqlColumn);
			zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1154);
			zephir_array_fetch_string(&_28$$32, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1157);
			if (ZEPHIR_IS_STRING(&_28$$32, "object")) {
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1158);
				ZEPHIR_OBS_NVAR(&instance);
				zephir_read_property(&_29$$33, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_fetch(&instance, &_29$$33, &modelName, 0))) {
					ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_30, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
				}
				ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_31, 0, &instance);
				zephir_check_call_status();
				if (isComplex) {
					ZEPHIR_INIT_NVAR(&_34$$35);
					ZVAL_STRING(&_34$$35, "orm.column_renaming");
					ZEPHIR_CALL_CE_STATIC(&_32$$35, phalcon_support_settings_ce, "get", &_33, 0, &_34$$35);
					zephir_check_call_status();
					if (zephir_is_true(&_32$$35)) {
						ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_35, 0, &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&columnMap);
						ZVAL_NULL(&columnMap);
					}
					zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Query.zep", 1194);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _36$$35)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _36$$35);
							ZEPHIR_INIT_NVAR(&_37$$38);
							zephir_create_array(&_37$$38, 3, 0);
							zephir_array_fast_append(&_37$$38, &attribute);
							zephir_array_fast_append(&_37$$38, &sqlColumn);
							ZEPHIR_INIT_NVAR(&_38$$38);
							ZEPHIR_CONCAT_SVSV(&_38$$38, "_", &sqlColumn, "_", &attribute);
							zephir_array_fast_append(&_37$$38, &_38$$38);
							zephir_array_append(&selectColumns, &_37$$38, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1187);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_39$$35, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_39$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_40$$39);
								zephir_create_array(&_40$$39, 3, 0);
								zephir_array_fast_append(&_40$$39, &attribute);
								zephir_array_fast_append(&_40$$39, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_41$$39);
								ZEPHIR_CONCAT_SVSV(&_41$$39, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_40$$39, &_41$$39);
								zephir_array_append(&selectColumns, &_40$$39, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1187);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
					zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
					zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
					ZEPHIR_CALL_METHOD(&_42$$35, &manager, "iskeepingsnapshots", &_43, 0, &instance);
					zephir_check_call_status();
					isKeepingSnapshots = zephir_get_boolval(&_42$$35);
					if (isKeepingSnapshots) {
						ZEPHIR_INIT_NVAR(&_44$$40);
						ZVAL_BOOL(&_44$$40, isKeepingSnapshots);
						zephir_array_update_multi(&columns1, &_44$$40, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
					}
				} else {
					zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Query.zep", 1211);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _45$$41)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _45$$41);
							ZEPHIR_INIT_NVAR(&_46$$42);
							zephir_create_array(&_46$$42, 2, 0);
							zephir_array_fast_append(&_46$$42, &attribute);
							zephir_array_fast_append(&_46$$42, &sqlColumn);
							zephir_array_append(&selectColumns, &_46$$42, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1209);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_47$$41, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_47$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_48$$43);
								zephir_create_array(&_48$$43, 2, 0);
								zephir_array_fast_append(&_48$$43, &attribute);
								zephir_array_fast_append(&_48$$43, &sqlColumn);
								zephir_array_append(&selectColumns, &_48$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1209);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				}
			} else {
				ZEPHIR_INIT_NVAR(&columnAlias);
				if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_49$$45);
					zephir_create_array(&_49$$45, 2, 0);
					zephir_array_fast_append(&_49$$45, &sqlColumn);
					zephir_array_fast_append(&_49$$45, &__$null);
					ZEPHIR_CPY_WRT(&columnAlias, &_49$$45);
				} else {
					ZEPHIR_INIT_NVAR(&_50$$46);
					zephir_create_array(&_50$$46, 3, 0);
					zephir_array_fast_append(&_50$$46, &sqlColumn);
					zephir_array_fast_append(&_50$$46, &__$null);
					zephir_array_fast_append(&_50$$46, &aliasCopy);
					ZEPHIR_CPY_WRT(&columnAlias, &_50$$46);
				}
				zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1222);
			}
			_51$$32 = !isComplex;
			if (_51$$32) {
				_51$$32 = isSimpleStd;
			}
			if (_51$$32) {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_52, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_52)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&aliasCopy, &columns, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sqlColumn);
				zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1154);
				zephir_array_fetch_string(&_53$$50, &column, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1157);
				if (ZEPHIR_IS_STRING(&_53$$50, "object")) {
					ZEPHIR_OBS_NVAR(&modelName);
					zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1158);
					ZEPHIR_OBS_NVAR(&instance);
					zephir_read_property(&_54$$51, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset_fetch(&instance, &_54$$51, &modelName, 0))) {
						ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_55, 0, &modelName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
					}
					ZEPHIR_CALL_METHOD(&attributes, &metaData, "getattributes", &_56, 0, &instance);
					zephir_check_call_status();
					if (isComplex) {
						ZEPHIR_INIT_NVAR(&_58$$53);
						ZVAL_STRING(&_58$$53, "orm.column_renaming");
						ZEPHIR_CALL_CE_STATIC(&_57$$53, phalcon_support_settings_ce, "get", &_33, 0, &_58$$53);
						zephir_check_call_status();
						if (zephir_is_true(&_57$$53)) {
							ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", &_59, 0, &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&columnMap);
							ZVAL_NULL(&columnMap);
						}
						zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Query.zep", 1194);
						if (Z_TYPE_P(&attributes) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _60$$53)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _60$$53);
								ZEPHIR_INIT_NVAR(&_61$$56);
								zephir_create_array(&_61$$56, 3, 0);
								zephir_array_fast_append(&_61$$56, &attribute);
								zephir_array_fast_append(&_61$$56, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_62$$56);
								ZEPHIR_CONCAT_SVSV(&_62$$56, "_", &sqlColumn, "_", &attribute);
								zephir_array_fast_append(&_61$$56, &_62$$56);
								zephir_array_append(&selectColumns, &_61$$56, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1187);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_63$$53, &attributes, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_63$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_64$$57);
									zephir_create_array(&_64$$57, 3, 0);
									zephir_array_fast_append(&_64$$57, &attribute);
									zephir_array_fast_append(&_64$$57, &sqlColumn);
									ZEPHIR_INIT_NVAR(&_65$$57);
									ZEPHIR_CONCAT_SVSV(&_65$$57, "_", &sqlColumn, "_", &attribute);
									zephir_array_fast_append(&_64$$57, &_65$$57);
									zephir_array_append(&selectColumns, &_64$$57, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1187);
								ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
						zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
						zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
						ZEPHIR_CALL_METHOD(&_66$$53, &manager, "iskeepingsnapshots", &_67, 0, &instance);
						zephir_check_call_status();
						isKeepingSnapshots = zephir_get_boolval(&_66$$53);
						if (isKeepingSnapshots) {
							ZEPHIR_INIT_NVAR(&_68$$58);
							ZVAL_BOOL(&_68$$58, isKeepingSnapshots);
							zephir_array_update_multi(&columns1, &_68$$58, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
						}
					} else {
						zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Query.zep", 1211);
						if (Z_TYPE_P(&attributes) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _69$$59)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _69$$59);
								ZEPHIR_INIT_NVAR(&_70$$60);
								zephir_create_array(&_70$$60, 2, 0);
								zephir_array_fast_append(&_70$$60, &attribute);
								zephir_array_fast_append(&_70$$60, &sqlColumn);
								zephir_array_append(&selectColumns, &_70$$60, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1209);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_71$$59, &attributes, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_71$$59)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_72$$61);
									zephir_create_array(&_72$$61, 2, 0);
									zephir_array_fast_append(&_72$$61, &attribute);
									zephir_array_fast_append(&_72$$61, &sqlColumn);
									zephir_array_append(&selectColumns, &_72$$61, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1209);
								ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
					}
				} else {
					if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
						ZEPHIR_INIT_NVAR(&_73$$63);
						zephir_create_array(&_73$$63, 2, 0);
						zephir_array_fast_append(&_73$$63, &sqlColumn);
						zephir_array_fast_append(&_73$$63, &__$null);
						ZEPHIR_CPY_WRT(&columnAlias, &_73$$63);
					} else {
						ZEPHIR_INIT_NVAR(&_74$$64);
						zephir_create_array(&_74$$64, 3, 0);
						zephir_array_fast_append(&_74$$64, &sqlColumn);
						zephir_array_fast_append(&_74$$64, &__$null);
						zephir_array_fast_append(&_74$$64, &aliasCopy);
						ZEPHIR_CPY_WRT(&columnAlias, &_74$$64);
					}
					zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1222);
				}
				_75$$50 = !isComplex;
				if (_75$$50) {
					_75$$50 = isSimpleStd;
				}
				if (_75$$50) {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&aliasCopy);
	ZEPHIR_INIT_VAR(&processed);
	array_init(&processed);
	ZEPHIR_INIT_VAR(&bindCounts);
	array_init(&bindCounts);
	zephir_array_update_string(&intermediate, SL("columns"), &selectColumns, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&bindParams, 0, "phalcon/Mvc/Model/Query.zep", 1258);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindParams), _77, _78, _76)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_78 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _78);
			} else {
				ZVAL_LONG(&wildcard, _77);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _76);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&wildcardValue);
				ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
			} else {
				ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
			}
			zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_79$$71);
				ZVAL_LONG(&_79$$71, zephir_fast_count_int(&value));
				zephir_array_update_zval(&bindCounts, &wildcardValue, &_79$$71, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindParams, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_80, &bindParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_80)) {
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
					ZEPHIR_INIT_NVAR(&_81$$75);
					ZVAL_LONG(&_81$$75, zephir_fast_count_int(&value));
					zephir_array_update_zval(&bindCounts, &wildcardValue, &_81$$75, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &bindParams, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	ZEPHIR_INIT_VAR(&processedTypes);
	array_init(&processedTypes);
	zephir_is_iterable(&bindTypes, 0, "phalcon/Mvc/Model/Query.zep", 1271);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindTypes), _83, _84, _82)
		{
			ZEPHIR_INIT_NVAR(&typeWildcard);
			if (_84 != NULL) { 
				ZVAL_STR_COPY(&typeWildcard, _84);
			} else {
				ZVAL_LONG(&typeWildcard, _83);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _82);
			if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&_85$$77);
				ZEPHIR_CONCAT_SV(&_85$$77, ":", &typeWildcard);
				zephir_array_update_zval(&processedTypes, &_85$$77, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindTypes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_86, &bindTypes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_86)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&typeWildcard, &bindTypes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &bindTypes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_87$$80);
					ZEPHIR_CONCAT_SV(&_87$$80, ":", &typeWildcard);
					zephir_array_update_zval(&processedTypes, &_87$$80, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &bindTypes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&typeWildcard);
	if (zephir_fast_count_int(&bindCounts)) {
		zephir_array_update_string(&intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, &dialect, "select", NULL, 0, &intermediate);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sharedLock"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_88$$83, &dialect, "sharedlock", NULL, 0, &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_88$$83);
	}
	zephir_is_iterable(&processed, 1, "phalcon/Mvc/Model/Query.zep", 1306);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&processed), _90, _91, _89)
	{
		ZEPHIR_INIT_NVAR(&wildcard);
		if (_91 != NULL) { 
			ZVAL_STR_COPY(&wildcard, _91);
		} else {
			ZVAL_LONG(&wildcard, _90);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _89);
		_92$$84 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_92$$84) {
			_92$$84 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
		}
		if (_92$$84) {
			ZVAL_LONG(&_93$$85, 0);
			ZVAL_LONG(&_94$$85, 1);
			ZEPHIR_INIT_NVAR(&_95$$85);
			zephir_substr(&_95$$85, &wildcard, 0 , 1 , 0);
			if (ZEPHIR_IS_STRING_IDENTICAL(&_95$$85, ":")) {
				ZEPHIR_INIT_NVAR(&_96$$86);
				zephir_cast_to_string(&_97$$86, &value);
				zephir_fast_str_replace(&_96$$86, &wildcard, &_97$$86, &sqlSelect);
				ZEPHIR_CPY_WRT(&sqlSelect, &_96$$86);
			} else {
				ZEPHIR_INIT_NVAR(&_98$$87);
				ZEPHIR_INIT_NVAR(&_99$$87);
				ZEPHIR_CONCAT_SV(&_99$$87, ":", &wildcard);
				zephir_cast_to_string(&_100$$87, &value);
				zephir_fast_str_replace(&_98$$87, &_99$$87, &_100$$87, &sqlSelect);
				ZEPHIR_CPY_WRT(&sqlSelect, &_98$$87);
			}
			zephir_array_unset(&processed, &wildcard, PH_SEPARATE);
			zephir_array_unset(&processedTypes, &wildcard, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
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
	zephir_read_property(&_101, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_101);
	if (!(isComplex)) {
		if (isSimpleStd) {
			ZEPHIR_INIT_VAR(&resultObject);
			object_init_ex(&resultObject, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&resultObject)) {
				ZEPHIR_CALL_METHOD(NULL, &resultObject, "__construct", NULL, 0);
				zephir_check_call_status();
			}

			isKeepingSnapshots = 0;
		} else {
			if (Z_TYPE_P(&instance) == IS_OBJECT) {
				ZEPHIR_CPY_WRT(&resultObject, &instance);
			} else {
				ZEPHIR_CPY_WRT(&resultObject, &model);
			}
			ZEPHIR_INIT_VAR(&_103$$93);
			ZVAL_STRING(&_103$$93, "orm.cast_on_hydrate");
			ZEPHIR_CALL_CE_STATIC(&_102$$93, phalcon_support_settings_ce, "get", &_33, 0, &_103$$93);
			zephir_check_call_status();
			if (!(zephir_is_true(&_102$$93))) {
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
					ZEPHIR_CALL_METHOD(&_104$$98, &metaData, "getattributes", NULL, 0, &resultObject);
					zephir_check_call_status();
					zephir_is_iterable(&_104$$98, 0, "phalcon/Mvc/Model/Query.zep", 1376);
					if (Z_TYPE_P(&_104$$98) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_104$$98), _105$$98)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _105$$98);
							ZEPHIR_INIT_NVAR(&_106$$99);
							zephir_create_array(&_106$$99, 2, 0);
							zephir_array_fast_append(&_106$$99, &attribute);
							ZEPHIR_OBS_NVAR(&_107$$99);
							zephir_array_fetch(&_107$$99, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1374);
							zephir_array_fast_append(&_106$$99, &_107$$99);
							zephir_array_update_zval(&simpleColumnMap, &attribute, &_106$$99, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_104$$98, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_108$$98, &_104$$98, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_108$$98)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &_104$$98, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_109$$100);
								zephir_create_array(&_109$$100, 2, 0);
								zephir_array_fast_append(&_109$$100, &attribute);
								ZEPHIR_OBS_NVAR(&_110$$100);
								zephir_array_fetch(&_110$$100, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1374);
								zephir_array_fast_append(&_109$$100, &_110$$100);
								zephir_array_update_zval(&simpleColumnMap, &attribute, &_109$$100, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &_104$$98, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				} else {
					array_init(&simpleColumnMap);
					zephir_is_iterable(&columnMap, 0, "phalcon/Mvc/Model/Query.zep", 1385);
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnMap), _112$$101, _113$$101, _111$$101)
						{
							ZEPHIR_INIT_NVAR(&column);
							if (_113$$101 != NULL) { 
								ZVAL_STR_COPY(&column, _113$$101);
							} else {
								ZVAL_LONG(&column, _112$$101);
							}
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _111$$101);
							ZEPHIR_INIT_NVAR(&_114$$102);
							zephir_create_array(&_114$$102, 2, 0);
							zephir_array_fast_append(&_114$$102, &attribute);
							ZEPHIR_OBS_NVAR(&_115$$102);
							zephir_array_fetch(&_115$$102, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1383);
							zephir_array_fast_append(&_114$$102, &_115$$102);
							zephir_array_update_zval(&simpleColumnMap, &column, &_114$$102, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &columnMap, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_116$$101, &columnMap, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_116$$101)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&column, &columnMap, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, &columnMap, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_117$$103);
								zephir_create_array(&_117$$103, 2, 0);
								zephir_array_fast_append(&_117$$103, &attribute);
								ZEPHIR_OBS_NVAR(&_118$$103);
								zephir_array_fetch(&_118$$103, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1383);
								zephir_array_fast_append(&_117$$103, &_118$$103);
								zephir_array_update_zval(&simpleColumnMap, &column, &_117$$103, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &columnMap, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					ZEPHIR_INIT_NVAR(&column);
				}
			}
			ZEPHIR_CALL_METHOD(&_119$$93, &manager, "iskeepingsnapshots", NULL, 0, &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_119$$93);
		}
		_120$$91 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce);
		if (_120$$91) {
			_120$$91 = (zephir_method_exists_ex(&resultObject, ZEND_STRL("getresultsetclass")) == SUCCESS);
		}
		if (_120$$91) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, &resultObject, "getresultsetclass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (UNEXPECTED(!(zephir_class_exists(&resultsetClassName, 1)))) {
					ZEPHIR_INIT_VAR(&_121$$106);
					object_init_ex(&_121$$106, phalcon_mvc_model_query_exceptions_resultsetclassnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_121$$106, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_121$$106, "phalcon/Mvc/Model/Query.zep", 1399);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_122$$105);
				ZVAL_STRING(&_122$$105, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_123$$105, "is_subclass_of", NULL, 0, &resultsetClassName, &_122$$105);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_123$$105))) {
					ZEPHIR_INIT_VAR(&_124$$107);
					object_init_ex(&_124$$107, phalcon_mvc_model_query_exceptions_invalidresultsetclass_ce);
					ZEPHIR_CALL_METHOD(NULL, &_124$$107, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_124$$107, "phalcon/Mvc/Model/Query.zep", 1403);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_125$$105);
				zephir_create_array(&_125$$105, 5, 0);
				zephir_array_fast_append(&_125$$105, &simpleColumnMap);
				zephir_array_fast_append(&_125$$105, &resultObject);
				zephir_array_fast_append(&_125$$105, &resultData);
				zephir_array_fast_append(&_125$$105, &cache);
				ZEPHIR_INIT_NVAR(&_122$$105);
				ZVAL_BOOL(&_122$$105, isKeepingSnapshots);
				zephir_array_fast_append(&_125$$105, &_122$$105);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &resultsetClassName, &_125$$105);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_126$$91, 1);
		} else {
			ZVAL_BOOL(&_126$$91, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &simpleColumnMap, &resultObject, &resultData, &cache, &_126$$91);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &columns1, &resultData, &cache);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the UPDATE intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeUpdate)
{
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_13 = NULL, *_15 = NULL, *_17 = NULL, *_18 = NULL, *_21 = NULL, *_23 = NULL, *_29 = NULL, *_32 = NULL, *_34 = NULL, *_36 = NULL, *_38 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, exception, _1, *_3, _19, _31, _39, _0$$3, _2$$4, _6$$5, _8$$10, _10$$10, _11$$10, _12$$11, _14$$12, _16$$13, _20$$14, _22$$19, _24$$19, _25$$19, _26$$20, _27$$21, _28$$22, _30$$23, _33$$25, _35$$26, _37$$24;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_25$$19);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_37$$24);
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
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1452);
	if (UNEXPECTED(zephir_array_isset_value_long(&models, 1))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_updatemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 1455);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1458);
	zephir_memory_observe(&model);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&model, &_1, &modelName, 0))) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_2$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getwriteconnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getdialect", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&fields);
	zephir_array_fetch_string(&fields, &intermediate, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1477);
	zephir_memory_observe(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1478);
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_CPY_WRT(&selectBindParams, &bindParams);
	ZEPHIR_CPY_WRT(&selectBindTypes, &bindTypes);
	zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Query.zep", 1548);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&number, _5);
			} else {
				ZVAL_LONG(&number, _4);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1493);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1494);
			if (zephir_array_isset_value_string(&field, SL("balias"))) {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1497);
			} else {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1499);
			}
			zephir_array_fetch_string(&_6$$5, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1502);
			do {
				if (ZEPHIR_IS_LONG(&_6$$5, 260) || ZEPHIR_IS_LONG(&_6$$5, 258) || ZEPHIR_IS_LONG(&_6$$5, 259)) {
					ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_7, 0, &exprValue);
					zephir_check_call_status();
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 322)) {
					ZEPHIR_INIT_NVAR(&updateValue);
					ZVAL_NULL(&updateValue);
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 273) || ZEPHIR_IS_LONG(&_6$$5, 274) || ZEPHIR_IS_LONG(&_6$$5, 277)) {
					ZEPHIR_CALL_METHOD(&_8$$10, &dialect, "getsqlexpression", &_9, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$10);
					ZVAL_STRING(&_10$$10, ":");
					ZEPHIR_INIT_NVAR(&_11$$10);
					ZVAL_STRING(&_11$$10, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_10$$10, &_11$$10, &_8$$10);
					ZEPHIR_OBS_NVAR(&updateValue);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0)))) {
						ZEPHIR_INIT_NVAR(&_12$$11);
						object_init_ex(&_12$$11, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_12$$11, "__construct", &_13, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$11, "phalcon/Mvc/Model/Query.zep", 1523);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
					zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
					break;
				}
				if (ZEPHIR_IS_LONG(&_6$$5, 277)) {
					ZEPHIR_INIT_NVAR(&_14$$12);
					object_init_ex(&_14$$12, phalcon_mvc_model_query_exceptions_queryoperationnotsupported_ce);
					ZEPHIR_CALL_METHOD(NULL, &_14$$12, "__construct", &_15, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$12, "phalcon/Mvc/Model/Query.zep", 1532);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&updateValue);
				object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_16$$13, &dialect, "getsqlexpression", &_17, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_18, 62, &_16$$13);
				zephir_check_call_status();
				break;
			} while(0);

			zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_19, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &fields, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1493);
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1494);
				if (zephir_array_isset_value_string(&field, SL("balias"))) {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1497);
				} else {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1499);
				}
				zephir_array_fetch_string(&_20$$14, &value, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1502);
				do {
					if (ZEPHIR_IS_LONG(&_20$$14, 260) || ZEPHIR_IS_LONG(&_20$$14, 258) || ZEPHIR_IS_LONG(&_20$$14, 259)) {
						ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getsqlexpression", &_21, 0, &exprValue);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_20$$14, 322)) {
						ZEPHIR_INIT_NVAR(&updateValue);
						ZVAL_NULL(&updateValue);
						break;
					}
					if (ZEPHIR_IS_LONG(&_20$$14, 273) || ZEPHIR_IS_LONG(&_20$$14, 274) || ZEPHIR_IS_LONG(&_20$$14, 277)) {
						ZEPHIR_CALL_METHOD(&_22$$19, &dialect, "getsqlexpression", &_23, 0, &exprValue);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_24$$19);
						ZVAL_STRING(&_24$$19, ":");
						ZEPHIR_INIT_NVAR(&_25$$19);
						ZVAL_STRING(&_25$$19, "");
						ZEPHIR_INIT_NVAR(&wildcard);
						zephir_fast_str_replace(&wildcard, &_24$$19, &_25$$19, &_22$$19);
						ZEPHIR_OBS_NVAR(&updateValue);
						if (UNEXPECTED(!(zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0)))) {
							ZEPHIR_INIT_NVAR(&_26$$20);
							object_init_ex(&_26$$20, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
							ZEPHIR_CALL_METHOD(NULL, &_26$$20, "__construct", &_13, 0, &wildcard);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_26$$20, "phalcon/Mvc/Model/Query.zep", 1523);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
						zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
						break;
					}
					if (ZEPHIR_IS_LONG(&_20$$14, 277)) {
						ZEPHIR_INIT_NVAR(&_27$$21);
						object_init_ex(&_27$$21, phalcon_mvc_model_query_exceptions_queryoperationnotsupported_ce);
						ZEPHIR_CALL_METHOD(NULL, &_27$$21, "__construct", &_15, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_27$$21, "phalcon/Mvc/Model/Query.zep", 1532);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&updateValue);
					object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_28$$22, &dialect, "getsqlexpression", &_29, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_18, 62, &_28$$22);
					zephir_check_call_status();
					break;
				} while(0);

				zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getrelatedrecords", NULL, 0, &model, &intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_30$$23, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_30$$23);
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
		ZEPHIR_CALL_METHOD(&_31, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_31))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&record, &records, "current", &_32, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, &record, "assign", NULL, 0, &updateValues);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_33$$25, &record, "update", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_33$$25))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_34, 0);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_35$$26, 0);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_35$$26, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &records, "next", &_36, 0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_37$$24);
			ZVAL_OBJ(&_37$$24, EG(exception));
			Z_ADDREF_P(&_37$$24);
			if (zephir_is_instance_of(&_37$$24, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_37$$24);
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_38, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 1598);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_39, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_39);
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
	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	zephir_array_fetch_string(&_0, &argument, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1615);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _10, _18, _19, _3$$4, _4$$4, _6$$4, _8$$5, _9$$5, _12$$7, _13$$7, _14$$7, _16$$8, _17$$8;
	zval expr, _2$$4, _7$$5, _11$$7, _15$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
	ZEPHIR_INIT_VAR(&whenClauses);
	array_init(&whenClauses);
	zephir_array_fetch_string(&_0, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1633);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model/Query.zep", 1648);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&whenExpr);
			ZVAL_COPY(&whenExpr, _1);
			if (zephir_array_isset_value_string(&whenExpr, SL("right"))) {
				ZEPHIR_INIT_NVAR(&_2$$4);
				zephir_create_array(&_2$$4, 3, 0);
				add_assoc_stringl_ex(&_2$$4, SL("type"), SL("when"));
				zephir_array_fetch_string(&_4$$4, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1637);
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getexpression", &_5, 0, &_4$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_2$$4, SL("expr"), &_3$$4, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_6$$4, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1638);
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "getexpression", &_5, 0, &_6$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_2$$4, SL("then"), &_3$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_2$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1639);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$5);
				zephir_create_array(&_7$$5, 2, 0);
				add_assoc_stringl_ex(&_7$$5, SL("type"), SL("else"));
				zephir_array_fetch_string(&_9$$5, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1643);
				ZEPHIR_CALL_METHOD(&_8$$5, this_ptr, "getexpression", &_5, 0, &_9$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_7$$5, SL("expr"), &_8$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_7$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1644);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_10, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&whenExpr, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (zephir_array_isset_value_string(&whenExpr, SL("right"))) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					zephir_create_array(&_11$$7, 3, 0);
					add_assoc_stringl_ex(&_11$$7, SL("type"), SL("when"));
					zephir_array_fetch_string(&_13$$7, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1637);
					ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "getexpression", &_5, 0, &_13$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_11$$7, SL("expr"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_14$$7, &whenExpr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1638);
					ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "getexpression", &_5, 0, &_14$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_11$$7, SL("then"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_11$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1639);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$8);
					zephir_create_array(&_15$$8, 2, 0);
					add_assoc_stringl_ex(&_15$$8, SL("type"), SL("else"));
					zephir_array_fetch_string(&_17$$8, &whenExpr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1643);
					ZEPHIR_CALL_METHOD(&_16$$8, this_ptr, "getexpression", &_5, 0, &_17$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$8, SL("expr"), &_16$$8, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_15$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1644);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&whenExpr);
	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("case"));
	zephir_array_fetch_string(&_19, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1650);
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "getexpression", &_5, 0, &_19);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_18, PH_COPY | PH_SEPARATE);
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
	zend_bool quoting, tempNotQuoting = 0;
	zval *expr_param = NULL, *quoting_param = NULL, exprType, exprLeft, exprRight, left, right, listItems, exprListItem, exprReturn, value, escapedValue, exprValue, valueParts, name, bindType, bind, _85, _0$$5, _1$$6, _2$$8, _3$$9, _4$$10, _5$$11, _6$$12, _7$$13, _8$$14, _9$$16, _10$$17, _11$$18, _12$$19, _13$$20, _14$$21, _15$$22, _16$$23, _17$$24, _18$$25, _19$$25, _20$$26, _21$$27, _22$$28, _23$$33, _24$$33, _25$$33, _26$$33, _27$$33, _28$$34, _29$$34, _30$$34, _31$$37, _32$$37, _33$$37, _34$$38, _35$$38, _36$$38, _37$$39, _38$$39, _39$$39, _40$$40, _41$$40, _42$$40, _43$$41, _44$$41, _45$$41, _46$$42, _47$$42, _48$$42, _49$$43, _53$$43, _54$$43, _50$$44, _51$$45, _52$$46, _55$$47, _56$$48, _57$$48, _58$$49, _59$$50, _60$$51, _61$$52, _62$$53, _63$$54, _64$$55, _65$$56, _66$$57, _67$$58, _68$$59, _69$$60, _70$$61, _71$$62, _72$$63, _73$$64, _74$$65, _75$$66, _76$$66, _77$$69, _78$$69, _79$$69, _80$$70, *_81$$72, _83$$72, _82$$73, _84$$74;
	zval expr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&exprType);
	ZVAL_UNDEF(&exprLeft);
	ZVAL_UNDEF(&exprRight);
	ZVAL_UNDEF(&left);
	ZVAL_UNDEF(&right);
	ZVAL_UNDEF(&listItems);
	ZVAL_UNDEF(&exprListItem);
	ZVAL_UNDEF(&exprReturn);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&escapedValue);
	ZVAL_UNDEF(&exprValue);
	ZVAL_UNDEF(&valueParts);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_85);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$11);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$23);
	ZVAL_UNDEF(&_17$$24);
	ZVAL_UNDEF(&_18$$25);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$26);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$28);
	ZVAL_UNDEF(&_23$$33);
	ZVAL_UNDEF(&_24$$33);
	ZVAL_UNDEF(&_25$$33);
	ZVAL_UNDEF(&_26$$33);
	ZVAL_UNDEF(&_27$$33);
	ZVAL_UNDEF(&_28$$34);
	ZVAL_UNDEF(&_29$$34);
	ZVAL_UNDEF(&_30$$34);
	ZVAL_UNDEF(&_31$$37);
	ZVAL_UNDEF(&_32$$37);
	ZVAL_UNDEF(&_33$$37);
	ZVAL_UNDEF(&_34$$38);
	ZVAL_UNDEF(&_35$$38);
	ZVAL_UNDEF(&_36$$38);
	ZVAL_UNDEF(&_37$$39);
	ZVAL_UNDEF(&_38$$39);
	ZVAL_UNDEF(&_39$$39);
	ZVAL_UNDEF(&_40$$40);
	ZVAL_UNDEF(&_41$$40);
	ZVAL_UNDEF(&_42$$40);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_44$$41);
	ZVAL_UNDEF(&_45$$41);
	ZVAL_UNDEF(&_46$$42);
	ZVAL_UNDEF(&_47$$42);
	ZVAL_UNDEF(&_48$$42);
	ZVAL_UNDEF(&_49$$43);
	ZVAL_UNDEF(&_53$$43);
	ZVAL_UNDEF(&_54$$43);
	ZVAL_UNDEF(&_50$$44);
	ZVAL_UNDEF(&_51$$45);
	ZVAL_UNDEF(&_52$$46);
	ZVAL_UNDEF(&_55$$47);
	ZVAL_UNDEF(&_56$$48);
	ZVAL_UNDEF(&_57$$48);
	ZVAL_UNDEF(&_58$$49);
	ZVAL_UNDEF(&_59$$50);
	ZVAL_UNDEF(&_60$$51);
	ZVAL_UNDEF(&_61$$52);
	ZVAL_UNDEF(&_62$$53);
	ZVAL_UNDEF(&_63$$54);
	ZVAL_UNDEF(&_64$$55);
	ZVAL_UNDEF(&_65$$56);
	ZVAL_UNDEF(&_66$$57);
	ZVAL_UNDEF(&_67$$58);
	ZVAL_UNDEF(&_68$$59);
	ZVAL_UNDEF(&_69$$60);
	ZVAL_UNDEF(&_70$$61);
	ZVAL_UNDEF(&_71$$62);
	ZVAL_UNDEF(&_72$$63);
	ZVAL_UNDEF(&_73$$64);
	ZVAL_UNDEF(&_74$$65);
	ZVAL_UNDEF(&_75$$66);
	ZVAL_UNDEF(&_76$$66);
	ZVAL_UNDEF(&_77$$69);
	ZVAL_UNDEF(&_78$$69);
	ZVAL_UNDEF(&_79$$69);
	ZVAL_UNDEF(&_80$$70);
	ZVAL_UNDEF(&_83$$72);
	ZVAL_UNDEF(&_82$$73);
	ZVAL_UNDEF(&_84$$74);
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
		do {
			if (ZEPHIR_IS_LONG(&exprType, '<')) {
				ZEPHIR_INIT_VAR(&exprReturn);
				zephir_create_array(&exprReturn, 4, 0);
				add_assoc_stringl_ex(&exprReturn, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&exprReturn, SL("op"), SL("<"));
				zephir_array_update_string(&exprReturn, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&exprReturn, SL("right"), &right, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '=')) {
				ZEPHIR_INIT_VAR(&_2$$8);
				zephir_create_array(&_2$$8, 4, 0);
				add_assoc_stringl_ex(&_2$$8, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_2$$8, SL("op"), SL("="));
				zephir_array_update_string(&_2$$8, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_2$$8, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_2$$8);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '>')) {
				ZEPHIR_INIT_VAR(&_3$$9);
				zephir_create_array(&_3$$9, 4, 0);
				add_assoc_stringl_ex(&_3$$9, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_3$$9, SL("op"), SL(">"));
				zephir_array_update_string(&_3$$9, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_3$$9, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_3$$9);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 270)) {
				ZEPHIR_INIT_VAR(&_4$$10);
				zephir_create_array(&_4$$10, 4, 0);
				add_assoc_stringl_ex(&_4$$10, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_4$$10, SL("op"), SL("<>"));
				zephir_array_update_string(&_4$$10, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_4$$10, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_4$$10);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 271)) {
				ZEPHIR_INIT_VAR(&_5$$11);
				zephir_create_array(&_5$$11, 4, 0);
				add_assoc_stringl_ex(&_5$$11, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_5$$11, SL("op"), SL("<="));
				zephir_array_update_string(&_5$$11, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_5$$11, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_5$$11);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 272)) {
				ZEPHIR_INIT_VAR(&_6$$12);
				zephir_create_array(&_6$$12, 4, 0);
				add_assoc_stringl_ex(&_6$$12, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_6$$12, SL("op"), SL(">="));
				zephir_array_update_string(&_6$$12, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_6$$12, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_6$$12);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 266)) {
				ZEPHIR_INIT_VAR(&_7$$13);
				zephir_create_array(&_7$$13, 4, 0);
				add_assoc_stringl_ex(&_7$$13, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_7$$13, SL("op"), SL("AND"));
				zephir_array_update_string(&_7$$13, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_7$$13, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_7$$13);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 267)) {
				ZEPHIR_INIT_VAR(&_8$$14);
				zephir_create_array(&_8$$14, 4, 0);
				add_assoc_stringl_ex(&_8$$14, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_8$$14, SL("op"), SL("OR"));
				zephir_array_update_string(&_8$$14, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$14, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_8$$14);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 355)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getqualified", NULL, 0, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '+')) {
				ZEPHIR_INIT_VAR(&_9$$16);
				zephir_create_array(&_9$$16, 4, 0);
				add_assoc_stringl_ex(&_9$$16, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_9$$16, SL("op"), SL("+"));
				zephir_array_update_string(&_9$$16, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_9$$16, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_9$$16);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '-')) {
				ZEPHIR_INIT_VAR(&_10$$17);
				zephir_create_array(&_10$$17, 4, 0);
				add_assoc_stringl_ex(&_10$$17, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_10$$17, SL("op"), SL("-"));
				zephir_array_update_string(&_10$$17, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$17, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_10$$17);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '*')) {
				ZEPHIR_INIT_VAR(&_11$$18);
				zephir_create_array(&_11$$18, 4, 0);
				add_assoc_stringl_ex(&_11$$18, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_11$$18, SL("op"), SL("*"));
				zephir_array_update_string(&_11$$18, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$18, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_11$$18);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '/')) {
				ZEPHIR_INIT_VAR(&_12$$19);
				zephir_create_array(&_12$$19, 4, 0);
				add_assoc_stringl_ex(&_12$$19, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_12$$19, SL("op"), SL("/"));
				zephir_array_update_string(&_12$$19, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_12$$19, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_12$$19);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '%')) {
				ZEPHIR_INIT_VAR(&_13$$20);
				zephir_create_array(&_13$$20, 4, 0);
				add_assoc_stringl_ex(&_13$$20, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_13$$20, SL("op"), SL("%"));
				zephir_array_update_string(&_13$$20, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$20, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_13$$20);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '&')) {
				ZEPHIR_INIT_VAR(&_14$$21);
				zephir_create_array(&_14$$21, 4, 0);
				add_assoc_stringl_ex(&_14$$21, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_14$$21, SL("op"), SL("&"));
				zephir_array_update_string(&_14$$21, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$21, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_14$$21);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '|')) {
				ZEPHIR_INIT_VAR(&_15$$22);
				zephir_create_array(&_15$$22, 4, 0);
				add_assoc_stringl_ex(&_15$$22, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_15$$22, SL("op"), SL("|"));
				zephir_array_update_string(&_15$$22, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_15$$22, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_15$$22);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 356) || ZEPHIR_IS_LONG(&exprType, 407)) {
				ZEPHIR_INIT_VAR(&_16$$23);
				zephir_create_array(&_16$$23, 2, 0);
				add_assoc_stringl_ex(&_16$$23, SL("type"), SL("parentheses"));
				zephir_array_update_string(&_16$$23, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_16$$23);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 367)) {
				ZEPHIR_INIT_VAR(&_17$$24);
				zephir_create_array(&_17$$24, 3, 0);
				add_assoc_stringl_ex(&_17$$24, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_17$$24, SL("op"), SL("-"));
				zephir_array_update_string(&_17$$24, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_17$$24);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 258) || ZEPHIR_IS_LONG(&exprType, 259) || ZEPHIR_IS_LONG(&exprType, 414)) {
				ZEPHIR_INIT_VAR(&_18$$25);
				zephir_create_array(&_18$$25, 2, 0);
				add_assoc_stringl_ex(&_18$$25, SL("type"), SL("literal"));
				zephir_memory_observe(&_19$$25);
				zephir_array_fetch_string(&_19$$25, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1866);
				zephir_array_update_string(&_18$$25, SL("value"), &_19$$25, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_18$$25);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 334)) {
				ZEPHIR_INIT_VAR(&_20$$26);
				zephir_create_array(&_20$$26, 2, 0);
				add_assoc_stringl_ex(&_20$$26, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_20$$26, SL("value"), SL("TRUE"));
				ZEPHIR_CPY_WRT(&exprReturn, &_20$$26);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 335)) {
				ZEPHIR_INIT_VAR(&_21$$27);
				zephir_create_array(&_21$$27, 2, 0);
				add_assoc_stringl_ex(&_21$$27, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_21$$27, SL("value"), SL("FALSE"));
				ZEPHIR_CPY_WRT(&exprReturn, &_21$$27);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 260)) {
				zephir_memory_observe(&value);
				zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1887);
				if (quoting) {
					if (zephir_memnstr_str(&value, SL("'"), "phalcon/Mvc/Model/Query.zep", 1894)) {
						ZEPHIR_INIT_VAR(&escapedValue);
						phalcon_orm_singlequotes(&escapedValue, &value);
					} else {
						ZEPHIR_CPY_WRT(&escapedValue, &value);
					}
					ZEPHIR_INIT_VAR(&exprValue);
					ZEPHIR_CONCAT_SVS(&exprValue, "'", &escapedValue, "'");
				} else {
					ZEPHIR_CPY_WRT(&exprValue, &value);
				}
				ZEPHIR_INIT_VAR(&_22$$28);
				zephir_create_array(&_22$$28, 2, 0);
				add_assoc_stringl_ex(&_22$$28, SL("type"), SL("literal"));
				zephir_array_update_string(&_22$$28, SL("value"), &exprValue, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_22$$28);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 273)) {
				ZEPHIR_INIT_VAR(&_23$$33);
				zephir_create_array(&_23$$33, 2, 0);
				add_assoc_stringl_ex(&_23$$33, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_24$$33);
				zephir_array_fetch_string(&_25$$33, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1915);
				ZEPHIR_INIT_VAR(&_26$$33);
				ZVAL_STRING(&_26$$33, "?");
				ZEPHIR_INIT_VAR(&_27$$33);
				ZVAL_STRING(&_27$$33, ":");
				zephir_fast_str_replace(&_24$$33, &_26$$33, &_27$$33, &_25$$33);
				zephir_array_update_string(&_23$$33, SL("value"), &_24$$33, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_23$$33);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 274)) {
				ZEPHIR_INIT_VAR(&_28$$34);
				zephir_create_array(&_28$$34, 2, 0);
				add_assoc_stringl_ex(&_28$$34, SL("type"), SL("placeholder"));
				zephir_array_fetch_string(&_29$$34, &expr, SL("value"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1924);
				ZEPHIR_INIT_VAR(&_30$$34);
				ZEPHIR_CONCAT_SV(&_30$$34, ":", &_29$$34);
				zephir_array_update_string(&_28$$34, SL("value"), &_30$$34, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_28$$34);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 277)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1929);
				if (zephir_memnstr_str(&value, SL(":"), "phalcon/Mvc/Model/Query.zep", 1931)) {
					ZEPHIR_INIT_VAR(&valueParts);
					zephir_fast_explode_str(&valueParts, SL(":"), &value, LONG_MAX);
					zephir_memory_observe(&name);
					zephir_array_fetch_long(&name, &valueParts, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1933);
					zephir_memory_observe(&bindType);
					zephir_array_fetch_long(&bindType, &valueParts, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1934);
					do {
						if (ZEPHIR_IS_STRING(&bindType, "str")) {
							ZEPHIR_INIT_VAR(&_31$$37);
							ZVAL_LONG(&_31$$37, 2);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_31$$37);
							ZEPHIR_INIT_VAR(&_32$$37);
							zephir_create_array(&_32$$37, 2, 0);
							add_assoc_stringl_ex(&_32$$37, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_33$$37);
							ZEPHIR_CONCAT_SV(&_33$$37, ":", &name);
							zephir_array_update_string(&_32$$37, SL("value"), &_33$$37, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_32$$37);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "int")) {
							ZEPHIR_INIT_VAR(&_34$$38);
							ZVAL_LONG(&_34$$38, 1);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_34$$38);
							ZEPHIR_INIT_VAR(&_35$$38);
							zephir_create_array(&_35$$38, 2, 0);
							add_assoc_stringl_ex(&_35$$38, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_36$$38);
							ZEPHIR_CONCAT_SV(&_36$$38, ":", &name);
							zephir_array_update_string(&_35$$38, SL("value"), &_36$$38, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_35$$38);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "double")) {
							ZEPHIR_INIT_VAR(&_37$$39);
							ZVAL_LONG(&_37$$39, 32);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_37$$39);
							ZEPHIR_INIT_VAR(&_38$$39);
							zephir_create_array(&_38$$39, 2, 0);
							add_assoc_stringl_ex(&_38$$39, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_39$$39);
							ZEPHIR_CONCAT_SV(&_39$$39, ":", &name);
							zephir_array_update_string(&_38$$39, SL("value"), &_39$$39, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_38$$39);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "bool")) {
							ZEPHIR_INIT_VAR(&_40$$40);
							ZVAL_LONG(&_40$$40, 5);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_40$$40);
							ZEPHIR_INIT_VAR(&_41$$40);
							zephir_create_array(&_41$$40, 2, 0);
							add_assoc_stringl_ex(&_41$$40, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_42$$40);
							ZEPHIR_CONCAT_SV(&_42$$40, ":", &name);
							zephir_array_update_string(&_41$$40, SL("value"), &_42$$40, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_41$$40);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "blob")) {
							ZEPHIR_INIT_VAR(&_43$$41);
							ZVAL_LONG(&_43$$41, 3);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_43$$41);
							ZEPHIR_INIT_VAR(&_44$$41);
							zephir_create_array(&_44$$41, 2, 0);
							add_assoc_stringl_ex(&_44$$41, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_45$$41);
							ZEPHIR_CONCAT_SV(&_45$$41, ":", &name);
							zephir_array_update_string(&_44$$41, SL("value"), &_45$$41, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_44$$41);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "null")) {
							ZEPHIR_INIT_VAR(&_46$$42);
							ZVAL_LONG(&_46$$42, 0);
							zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_46$$42);
							ZEPHIR_INIT_VAR(&_47$$42);
							zephir_create_array(&_47$$42, 2, 0);
							add_assoc_stringl_ex(&_47$$42, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_48$$42);
							ZEPHIR_CONCAT_SV(&_48$$42, ":", &name);
							zephir_array_update_string(&_47$$42, SL("value"), &_48$$42, PH_COPY | PH_SEPARATE);
							ZEPHIR_CPY_WRT(&exprReturn, &_47$$42);
							break;
						}
						if (ZEPHIR_IS_STRING(&bindType, "array") || ZEPHIR_IS_STRING(&bindType, "array-str") || ZEPHIR_IS_STRING(&bindType, "array-int")) {
							zephir_memory_observe(&bind);
							zephir_read_property(&_49$$43, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&bind, &_49$$43, &name, 0)))) {
								ZEPHIR_INIT_VAR(&_50$$44);
								object_init_ex(&_50$$44, phalcon_mvc_model_query_exceptions_bindvaluerequired_ce);
								ZEPHIR_CALL_METHOD(NULL, &_50$$44, "__construct", NULL, 0, &name);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_50$$44, "phalcon/Mvc/Model/Query.zep", 2002);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(Z_TYPE_P(&bind) != IS_ARRAY)) {
								ZEPHIR_INIT_VAR(&_51$$45);
								object_init_ex(&_51$$45, phalcon_mvc_model_query_exceptions_bindtyperequiresarray_ce);
								ZEPHIR_CALL_METHOD(NULL, &_51$$45, "__construct", NULL, 0, &name);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_51$$45, "phalcon/Mvc/Model/Query.zep", 2006);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(zephir_fast_count_int(&bind) < 1)) {
								ZEPHIR_INIT_VAR(&_52$$46);
								object_init_ex(&_52$$46, phalcon_mvc_model_query_exceptions_emptyarrayplaceholdervalue_ce);
								ZEPHIR_CALL_METHOD(NULL, &_52$$46, "__construct", NULL, 0, &name);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_52$$46, "phalcon/Mvc/Model/Query.zep", 2010);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_VAR(&_53$$43);
							zephir_create_array(&_53$$43, 4, 0);
							add_assoc_stringl_ex(&_53$$43, SL("type"), SL("placeholder"));
							ZEPHIR_INIT_VAR(&_54$$43);
							ZEPHIR_CONCAT_SV(&_54$$43, ":", &name);
							zephir_array_update_string(&_53$$43, SL("value"), &_54$$43, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_53$$43, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
							add_assoc_long_ex(&_53$$43, SL("times"), zephir_fast_count_int(&bind));
							ZEPHIR_CPY_WRT(&exprReturn, &_53$$43);
							break;
						}
						ZEPHIR_INIT_VAR(&_55$$47);
						object_init_ex(&_55$$47, phalcon_mvc_model_query_exceptions_unknownbindtype_ce);
						ZEPHIR_CALL_METHOD(NULL, &_55$$47, "__construct", NULL, 0, &bindType);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_55$$47, "phalcon/Mvc/Model/Query.zep", 2023);
						ZEPHIR_MM_RESTORE();
						return;
					} while(0);

				} else {
					ZEPHIR_INIT_VAR(&_56$$48);
					zephir_create_array(&_56$$48, 2, 0);
					add_assoc_stringl_ex(&_56$$48, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_57$$48);
					ZEPHIR_CONCAT_SV(&_57$$48, ":", &value);
					zephir_array_update_string(&_56$$48, SL("value"), &_57$$48, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_56$$48);
				}
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 322)) {
				ZEPHIR_INIT_VAR(&_58$$49);
				zephir_create_array(&_58$$49, 2, 0);
				add_assoc_stringl_ex(&_58$$49, SL("type"), SL("literal"));
				add_assoc_stringl_ex(&_58$$49, SL("value"), SL("NULL"));
				ZEPHIR_CPY_WRT(&exprReturn, &_58$$49);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 268)) {
				ZEPHIR_INIT_VAR(&_59$$50);
				zephir_create_array(&_59$$50, 4, 0);
				add_assoc_stringl_ex(&_59$$50, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_59$$50, SL("op"), SL("LIKE"));
				zephir_array_update_string(&_59$$50, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_59$$50, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_59$$50);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 351)) {
				ZEPHIR_INIT_VAR(&_60$$51);
				zephir_create_array(&_60$$51, 4, 0);
				add_assoc_stringl_ex(&_60$$51, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_60$$51, SL("op"), SL("NOT LIKE"));
				zephir_array_update_string(&_60$$51, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$51, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_60$$51);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 275)) {
				ZEPHIR_INIT_VAR(&_61$$52);
				zephir_create_array(&_61$$52, 4, 0);
				add_assoc_stringl_ex(&_61$$52, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_61$$52, SL("op"), SL("ILIKE"));
				zephir_array_update_string(&_61$$52, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_61$$52, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_61$$52);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 357)) {
				ZEPHIR_INIT_VAR(&_62$$53);
				zephir_create_array(&_62$$53, 4, 0);
				add_assoc_stringl_ex(&_62$$53, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_62$$53, SL("op"), SL("NOT ILIKE"));
				zephir_array_update_string(&_62$$53, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_62$$53, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_62$$53);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, '!')) {
				ZEPHIR_INIT_VAR(&_63$$54);
				zephir_create_array(&_63$$54, 3, 0);
				add_assoc_stringl_ex(&_63$$54, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_63$$54, SL("op"), SL("NOT "));
				zephir_array_update_string(&_63$$54, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_63$$54);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 365)) {
				ZEPHIR_INIT_VAR(&_64$$55);
				zephir_create_array(&_64$$55, 3, 0);
				add_assoc_stringl_ex(&_64$$55, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_64$$55, SL("op"), SL(" IS NULL"));
				zephir_array_update_string(&_64$$55, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_64$$55);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 366)) {
				ZEPHIR_INIT_VAR(&_65$$56);
				zephir_create_array(&_65$$56, 3, 0);
				add_assoc_stringl_ex(&_65$$56, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_65$$56, SL("op"), SL(" IS NOT NULL"));
				zephir_array_update_string(&_65$$56, SL("left"), &left, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_65$$56);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 315)) {
				ZEPHIR_INIT_VAR(&_66$$57);
				zephir_create_array(&_66$$57, 4, 0);
				add_assoc_stringl_ex(&_66$$57, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_66$$57, SL("op"), SL("IN"));
				zephir_array_update_string(&_66$$57, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_66$$57, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_66$$57);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 323)) {
				ZEPHIR_INIT_VAR(&_67$$58);
				zephir_create_array(&_67$$58, 4, 0);
				add_assoc_stringl_ex(&_67$$58, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_67$$58, SL("op"), SL("NOT IN"));
				zephir_array_update_string(&_67$$58, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_67$$58, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_67$$58);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 408)) {
				ZEPHIR_INIT_VAR(&_68$$59);
				zephir_create_array(&_68$$59, 3, 0);
				add_assoc_stringl_ex(&_68$$59, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_68$$59, SL("op"), SL("EXISTS"));
				zephir_array_update_string(&_68$$59, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_68$$59);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 330)) {
				ZEPHIR_INIT_VAR(&_69$$60);
				zephir_create_array(&_69$$60, 3, 0);
				add_assoc_stringl_ex(&_69$$60, SL("type"), SL("unary-op"));
				add_assoc_stringl_ex(&_69$$60, SL("op"), SL("DISTINCT "));
				zephir_array_update_string(&_69$$60, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_69$$60);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 332)) {
				ZEPHIR_INIT_VAR(&_70$$61);
				zephir_create_array(&_70$$61, 4, 0);
				add_assoc_stringl_ex(&_70$$61, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_70$$61, SL("op"), SL("NOT BETWEEN"));
				zephir_array_update_string(&_70$$61, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_70$$61, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_70$$61);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 331)) {
				ZEPHIR_INIT_VAR(&_71$$62);
				zephir_create_array(&_71$$62, 4, 0);
				add_assoc_stringl_ex(&_71$$62, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_71$$62, SL("op"), SL("BETWEEN"));
				zephir_array_update_string(&_71$$62, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_71$$62, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_71$$62);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 276)) {
				ZEPHIR_INIT_VAR(&_72$$63);
				zephir_create_array(&_72$$63, 4, 0);
				add_assoc_stringl_ex(&_72$$63, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_72$$63, SL("op"), SL("AGAINST"));
				zephir_array_update_string(&_72$$63, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_72$$63, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_72$$63);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 333)) {
				ZEPHIR_INIT_VAR(&_73$$64);
				zephir_create_array(&_73$$64, 3, 0);
				add_assoc_stringl_ex(&_73$$64, SL("type"), SL("cast"));
				zephir_array_update_string(&_73$$64, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_73$$64, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_73$$64);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 336)) {
				ZEPHIR_INIT_VAR(&_74$$65);
				zephir_create_array(&_74$$65, 3, 0);
				add_assoc_stringl_ex(&_74$$65, SL("type"), SL("convert"));
				zephir_array_update_string(&_74$$65, SL("left"), &left, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_74$$65, SL("right"), &right, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_74$$65);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 358)) {
				ZEPHIR_INIT_VAR(&_75$$66);
				zephir_create_array(&_75$$66, 2, 0);
				add_assoc_stringl_ex(&_75$$66, SL("type"), SL("literal"));
				zephir_memory_observe(&_76$$66);
				zephir_array_fetch_string(&_76$$66, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2199);
				zephir_array_update_string(&_75$$66, SL("value"), &_76$$66, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_75$$66);
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 350)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getfunctioncall", NULL, 0, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 409)) {
				ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getcaseexpression", NULL, 0, &expr);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(&exprType, 309)) {
				ZEPHIR_INIT_VAR(&_77$$69);
				zephir_create_array(&_77$$69, 2, 0);
				add_assoc_stringl_ex(&_77$$69, SL("type"), SL("select"));
				ZVAL_BOOL(&_79$$69, 1);
				ZEPHIR_CALL_METHOD(&_78$$69, this_ptr, "_prepareselect", NULL, 0, &expr, &_79$$69);
				zephir_check_call_status();
				zephir_array_update_string(&_77$$69, SL("value"), &_78$$69, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_77$$69);
				break;
			}
			ZEPHIR_INIT_VAR(&_80$$70);
			object_init_ex(&_80$$70, phalcon_mvc_model_query_exceptions_unknownphqlexpressiontype_ce);
			ZEPHIR_CALL_METHOD(NULL, &_80$$70, "__construct", NULL, 0, &exprType);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_80$$70, "phalcon/Mvc/Model/Query.zep", 2222);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

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
		zephir_is_iterable(&expr, 0, "phalcon/Mvc/Model/Query.zep", 2245);
		if (Z_TYPE_P(&expr) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _81$$72)
			{
				ZEPHIR_INIT_NVAR(&exprListItem);
				ZVAL_COPY(&exprListItem, _81$$72);
				ZEPHIR_CALL_METHOD(&_82$$73, this_ptr, "getexpression", NULL, 0, &exprListItem);
				zephir_check_call_status();
				zephir_array_append(&listItems, &_82$$73, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2242);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &expr, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_83$$72, &expr, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_83$$72)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&exprListItem, &expr, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_84$$74, this_ptr, "getexpression", NULL, 0, &exprListItem);
					zephir_check_call_status();
					zephir_array_append(&listItems, &_84$$74, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2242);
				ZEPHIR_CALL_METHOD(NULL, &expr, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&exprListItem);
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("list"));
		zephir_array_fast_append(return_value, &listItems);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_85);
	object_init_ex(&_85, phalcon_mvc_model_query_exceptions_unknownphqlexpression_ce);
	ZEPHIR_CALL_METHOD(NULL, &_85, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_85, "phalcon/Mvc/Model/Query.zep", 2251);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves an expression in a single call argument
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getFunctionCall)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, _10, *_0$$6, _3$$6, _1$$7, _4$$8, _5$$9, _6$$9, _7$$10, _8$$10, _9$$11;
	zval expr, functionArgs;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&functionArgs);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
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
			zephir_is_iterable(&arguments, 0, "phalcon/Mvc/Model/Query.zep", 2277);
			if (Z_TYPE_P(&arguments) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&arguments), _0$$6)
				{
					ZEPHIR_INIT_NVAR(&argument);
					ZVAL_COPY(&argument, _0$$6);
					ZEPHIR_CALL_METHOD(&_1$$7, this_ptr, "getcallargument", &_2, 0, &argument);
					zephir_check_call_status();
					zephir_array_append(&functionArgs, &_1$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2275);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &arguments, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$6, &arguments, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&argument, &arguments, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "getcallargument", &_2, 0, &argument);
						zephir_check_call_status();
						zephir_array_append(&functionArgs, &_4$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2275);
					ZEPHIR_CALL_METHOD(NULL, &arguments, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			ZEPHIR_INIT_VAR(&_5$$9);
			zephir_create_array(&_5$$9, 1, 0);
			ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "getcallargument", &_2, 0, &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&_5$$9, &_6$$9);
			ZEPHIR_CPY_WRT(&functionArgs, &_5$$9);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_7$$10);
			zephir_array_fetch_string(&_7$$10, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2287);
			zephir_array_update_string(return_value, SL("name"), &_7$$10, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_8$$10);
			ZVAL_LONG(&_8$$10, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_8$$10, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_9$$11);
			zephir_array_fetch_string(&_9$$11, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2294);
			zephir_array_update_string(return_value, SL("name"), &_9$$11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	zephir_memory_observe(&_10);
	zephir_array_fetch_string(&_10, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2303);
	zephir_array_update_string(return_value, SL("name"), &_10, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Returns a processed group clause for a SELECT statement
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getGroupClause)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, *_0$$3, _3$$3, _1$$4, _4$$5, _5$$6, _6$$6;
	zval group, groupParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(group, group_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group_param);
	ZEPHIR_OBS_COPY_OR_DUP(&group, group_param);
	if (zephir_array_isset_value_long(&group, 0)) {
		ZEPHIR_INIT_VAR(&groupParts);
		array_init(&groupParts);
		zephir_is_iterable(&group, 0, "phalcon/Mvc/Model/Query.zep", 2323);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _0$$3);
				ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getexpression", &_2, 0, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupParts, &_1$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2321);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$3, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "getexpression", &_2, 0, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupParts, &_4$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2321);
				ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		ZEPHIR_INIT_VAR(&_5$$6);
		zephir_create_array(&_5$$6, 1, 0);
		ZEPHIR_CALL_METHOD(&_6$$6, this_ptr, "getexpression", &_2, 0, &group);
		zephir_check_call_status();
		zephir_array_fast_append(&_5$$6, &_6$$6);
		ZEPHIR_CPY_WRT(&groupParts, &_5$$6);
	}
	RETURN_CTOR(&groupParts);
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
	ZEPHIR_OBS_COPY_OR_DUP(&limitClause, limitClause_param);
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
		zephir_array_fetch_string(&_0$$3, &qualified, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2359);
		if (ZEPHIR_IS_LONG(&_0$$3, 355)) {
			zephir_memory_observe(&modelName);
			zephir_array_fetch_string(&modelName, &qualified, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2360);
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
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model/Query.zep", 2375);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 2386);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_LONG(&type, 360)) {
			RETURN_MM_STRING("INNER");
		}
		if (ZEPHIR_IS_LONG(&type, 361)) {
			RETURN_MM_STRING("LEFT");
		}
		if (ZEPHIR_IS_LONG(&type, 362)) {
			RETURN_MM_STRING("RIGHT");
		}
		if (ZEPHIR_IS_LONG(&type, 363)) {
			RETURN_MM_STRING("CROSS");
		}
		if (ZEPHIR_IS_LONG(&type, 364)) {
			RETURN_MM_STRING("FULL OUTER");
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_mvc_model_query_exceptions_unknownjointype_ce);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &type, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "phalcon/Mvc/Model/Query.zep", 2406);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Processes the JOINs in the query returning an internal representation for
 * the database dialect
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoins)
{
	zend_string *_17, *_35, *_23$$19, *_38$$23, *_56$$38;
	zend_ulong _16, _34, _22$$19, _37$$23, _55$$38;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_6 = NULL, *_19 = NULL, *_39 = NULL, *_40 = NULL, *_43 = NULL, *_45 = NULL, *_46 = NULL, *_57 = NULL, *_58 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select_param = NULL, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, _0, *_1, _9, *_15, *_26, _29, _32, *_33, _53, _4$$9, _5$$9, _7$$11, _8$$11, _10$$12, _11$$14, _12$$14, _13$$16, _14$$16, _18$$18, _20$$19, *_21$$19, _27$$21, _28$$21, _30$$22, _31$$22, *_36$$23, _41$$28, _42$$28, _44$$29, *_47$$32, _48$$32, _50$$36, *_54$$38, _59$$43, _60$$43, _61$$44, *_62$$47, _63$$47, _65$$51;
	zval select, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, _24$$20, _25$$20, _49$$36, _51$$37, _52$$37, _64$$51, _66$$52, _67$$52;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&joinModels);
	ZVAL_UNDEF(&joinSources);
	ZVAL_UNDEF(&joinTypes);
	ZVAL_UNDEF(&joinPreCondition);
	ZVAL_UNDEF(&joinPrepared);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_49$$36);
	ZVAL_UNDEF(&_51$$37);
	ZVAL_UNDEF(&_52$$37);
	ZVAL_UNDEF(&_64$$51);
	ZVAL_UNDEF(&_66$$52);
	ZVAL_UNDEF(&_67$$52);
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_48$$32);
	ZVAL_UNDEF(&_50$$36);
	ZVAL_UNDEF(&_59$$43);
	ZVAL_UNDEF(&_60$$43);
	ZVAL_UNDEF(&_61$$44);
	ZVAL_UNDEF(&_63$$47);
	ZVAL_UNDEF(&_65$$51);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(select, select_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &select_param);
	zephir_get_arrval(&select, select_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliases, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModels, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlModelsAliases"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlModelsAliases, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&tables);
	zephir_array_fetch_string(&tables, &select, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2442);
	if (!(zephir_array_isset_value_long(&tables, 0))) {
		ZEPHIR_INIT_VAR(&selectTables);
		zephir_create_array(&selectTables, 1, 0);
		zephir_array_fast_append(&selectTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectTables, &tables);
	}
	zephir_memory_observe(&joins);
	zephir_array_fetch_string(&joins, &select, SL("joins"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2450);
	if (!(zephir_array_isset_value_long(&joins, 0))) {
		ZEPHIR_INIT_VAR(&selectJoins);
		zephir_create_array(&selectJoins, 1, 0);
		zephir_array_fast_append(&selectJoins, &joins);
	} else {
		ZEPHIR_CPY_WRT(&selectJoins, &joins);
	}
	zephir_is_iterable(&selectJoins, 0, "phalcon/Mvc/Model/Query.zep", 2597);
	if (Z_TYPE_P(&selectJoins) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectJoins), _1)
		{
			ZEPHIR_INIT_NVAR(&joinItem);
			ZVAL_COPY(&joinItem, _1);
			ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getjoin", &_2, 0, &manager, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&source);
			zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2464);
			ZEPHIR_OBS_NVAR(&schema);
			zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2465);
			ZEPHIR_OBS_NVAR(&model);
			zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2466);
			ZEPHIR_OBS_NVAR(&realModelName);
			zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2467);
			ZEPHIR_INIT_NVAR(&completeSource);
			zephir_create_array(&completeSource, 2, 0);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
			ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getjointype", &_3, 0, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&aliasExpr);
			if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2479);
				if (UNEXPECTED(zephir_array_isset_value(&joinModels, &alias))) {
					ZEPHIR_INIT_NVAR(&_4$$9);
					object_init_ex(&_4$$9, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property(&_5$$9, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_6, 0, &alias, &_5$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$9, "phalcon/Mvc/Model/Query.zep", 2485);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2491);
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
					ZEPHIR_INIT_NVAR(&_7$$11);
					object_init_ex(&_7$$11, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property(&_8$$11, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", &_6, 0, &realModelName, &_8$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$11, "phalcon/Mvc/Model/Query.zep", 2542);
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
		ZEPHIR_CALL_METHOD(NULL, &selectJoins, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &selectJoins, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&joinItem, &selectJoins, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getjoin", &_2, 0, &manager, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2464);
				ZEPHIR_OBS_NVAR(&schema);
				zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2465);
				ZEPHIR_OBS_NVAR(&model);
				zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2466);
				ZEPHIR_OBS_NVAR(&realModelName);
				zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2467);
				ZEPHIR_INIT_NVAR(&_10$$12);
				zephir_create_array(&_10$$12, 2, 0);
				zephir_array_fast_append(&_10$$12, &source);
				zephir_array_fast_append(&_10$$12, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_10$$12);
				ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getjointype", &_3, 0, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&aliasExpr);
				if (zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0)) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2479);
					if (UNEXPECTED(zephir_array_isset_value(&joinModels, &alias))) {
						ZEPHIR_INIT_NVAR(&_11$$14);
						object_init_ex(&_11$$14, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property(&_12$$14, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_11$$14, "__construct", &_6, 0, &alias, &_12$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$14, "phalcon/Mvc/Model/Query.zep", 2485);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2491);
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
						ZEPHIR_INIT_NVAR(&_13$$16);
						object_init_ex(&_13$$16, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property(&_14$$16, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_13$$16, "__construct", &_6, 0, &realModelName, &_14$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_13$$16, "phalcon/Mvc/Model/Query.zep", 2542);
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
			ZEPHIR_CALL_METHOD(NULL, &selectJoins, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&joinItem);
	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &models);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModels"), &sqlAliasesModels);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlModelsAliases"), &sqlModelsAliases);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &modelsInstances);
	zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2617);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _16, _17, _15)
	{
		ZEPHIR_INIT_NVAR(&joinAliasName);
		if (_17 != NULL) { 
			ZVAL_STR_COPY(&joinAliasName, _17);
		} else {
			ZVAL_LONG(&joinAliasName, _16);
		}
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _15);
		ZEPHIR_OBS_NVAR(&joinExpr);
		if (zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0)) {
			ZEPHIR_CALL_METHOD(&_18$$18, this_ptr, "getexpression", &_19, 0, &joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_18$$18, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("enableImplicitJoins"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_20$$19);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2629);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _22$$19, _23$$19, _21$$19)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_23$$19 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _23$$19);
			} else {
				ZVAL_LONG(&joinAliasName, _22$$19);
			}
			ZEPHIR_INIT_NVAR(&_20$$19);
			ZVAL_COPY(&_20$$19, _21$$19);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2619);
			ZEPHIR_OBS_NVAR(&joinSource);
			zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2620);
			ZEPHIR_OBS_NVAR(&preCondition);
			zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2621);
			ZEPHIR_INIT_NVAR(&_24$$20);
			zephir_create_array(&_24$$20, 3, 0);
			zephir_array_update_string(&_24$$20, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_24$$20, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_25$$20);
			zephir_create_array(&_25$$20, 1, 0);
			zephir_array_fast_append(&_25$$20, &preCondition);
			zephir_array_update_string(&_24$$20, SL("conditions"), &_25$$20, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, &_24$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2626);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_20$$19);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	zephir_is_iterable(&selectTables, 0, "phalcon/Mvc/Model/Query.zep", 2644);
	if (Z_TYPE_P(&selectTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectTables), _26)
		{
			ZEPHIR_INIT_NVAR(&tableItem);
			ZVAL_COPY(&tableItem, _26);
			zephir_array_fetch_string(&_27$$21, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2638);
			ZEPHIR_OBS_NVAR(&_28$$21);
			zephir_array_fetch_string(&_28$$21, &_27$$21, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2638);
			zephir_array_update_zval(&fromModels, &_28$$21, &__$true, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_29, &selectTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tableItem, &selectTables, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_30$$22, &tableItem, SL("qualifiedName"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2638);
				ZEPHIR_OBS_NVAR(&_31$$22);
				zephir_array_fetch_string(&_31$$22, &_30$$22, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2638);
				zephir_array_update_zval(&fromModels, &_31$$22, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &selectTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&tableItem);
	ZEPHIR_INIT_VAR(&_32);
	zephir_is_iterable(&fromModels, 0, "phalcon/Mvc/Model/Query.zep", 2762);
	if (Z_TYPE_P(&fromModels) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fromModels), _34, _35, _33)
		{
			ZEPHIR_INIT_NVAR(&fromModelName);
			if (_35 != NULL) { 
				ZVAL_STR_COPY(&fromModelName, _35);
			} else {
				ZVAL_LONG(&fromModelName, _34);
			}
			ZEPHIR_INIT_NVAR(&_32);
			ZVAL_COPY(&_32, _33);
			zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 2760);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _37$$23, _38$$23, _36$$23)
			{
				ZEPHIR_INIT_NVAR(&joinAlias);
				if (_38$$23 != NULL) { 
					ZVAL_STR_COPY(&joinAlias, _38$$23);
				} else {
					ZVAL_LONG(&joinAlias, _37$$23);
				}
				ZEPHIR_INIT_NVAR(&joinModel);
				ZVAL_COPY(&joinModel, _36$$23);
				ZEPHIR_OBS_NVAR(&joinSource);
				zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2649);
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2654);
				ZEPHIR_OBS_NVAR(&preCondition);
				if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0))) {
					ZEPHIR_OBS_NVAR(&modelNameAlias);
					zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2663);
					ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_39, 0, &fromModelName, &modelNameAlias);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
						ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_40, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (Z_TYPE_P(&relations) == IS_ARRAY) {
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_41$$28);
								object_init_ex(&_41$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property(&_42$$28, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_41$$28, "__construct", &_43, 0, &fromModelName, &joinModel, &_42$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_41$$28, "phalcon/Mvc/Model/Query.zep", 2687);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2693);
						}
					}
					if (Z_TYPE_P(&relation) == IS_OBJECT) {
						ZEPHIR_OBS_NVAR(&modelAlias);
						zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2704);
						ZEPHIR_CALL_METHOD(&_44$$29, &relation, "isthrough", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_44$$29))) {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getsinglejoin", &_45, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getmultijoin", &_46, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						}
						if (zephir_array_isset_value_long(&sqlJoin, 0)) {
							zephir_is_iterable(&sqlJoin, 0, "phalcon/Mvc/Model/Query.zep", 2734);
							if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _47$$32)
								{
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
									ZVAL_COPY(&sqlJoinItem, _47$$32);
									zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2732);
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_48$$32, &sqlJoin, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_48$$32)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2732);
									ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&sqlJoinItem);
						} else {
							zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2735);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_49$$36);
						zephir_create_array(&_49$$36, 3, 0);
						zephir_array_update_string(&_49$$36, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_49$$36, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_50$$36);
						array_init(&_50$$36);
						zephir_array_update_string(&_49$$36, SL("conditions"), &_50$$36, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_49$$36, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2746);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_51$$37);
					zephir_create_array(&_51$$37, 3, 0);
					zephir_array_update_string(&_51$$37, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_51$$37, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_52$$37);
					zephir_create_array(&_52$$37, 1, 0);
					zephir_array_fast_append(&_52$$37, &preCondition);
					zephir_array_update_string(&_51$$37, SL("conditions"), &_52$$37, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_51$$37, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2757);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&joinModel);
			ZEPHIR_INIT_NVAR(&joinAlias);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fromModels, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_53, &fromModels, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_53)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&fromModelName, &fromModels, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_32, &fromModels, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 2760);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _55$$38, _56$$38, _54$$38)
				{
					ZEPHIR_INIT_NVAR(&joinAlias);
					if (_56$$38 != NULL) { 
						ZVAL_STR_COPY(&joinAlias, _56$$38);
					} else {
						ZVAL_LONG(&joinAlias, _55$$38);
					}
					ZEPHIR_INIT_NVAR(&joinModel);
					ZVAL_COPY(&joinModel, _54$$38);
					ZEPHIR_OBS_NVAR(&joinSource);
					zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2649);
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2654);
					ZEPHIR_OBS_NVAR(&preCondition);
					if (!(zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0))) {
						ZEPHIR_OBS_NVAR(&modelNameAlias);
						zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2663);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_57, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getrelationsbetween", &_58, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (Z_TYPE_P(&relations) == IS_ARRAY) {
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_59$$43);
									object_init_ex(&_59$$43, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property(&_60$$43, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_59$$43, "__construct", &_43, 0, &fromModelName, &joinModel, &_60$$43);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_59$$43, "phalcon/Mvc/Model/Query.zep", 2687);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2693);
							}
						}
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_OBS_NVAR(&modelAlias);
							zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2704);
							ZEPHIR_CALL_METHOD(&_61$$44, &relation, "isthrough", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_61$$44))) {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getsinglejoin", &_45, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getmultijoin", &_46, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							}
							if (zephir_array_isset_value_long(&sqlJoin, 0)) {
								zephir_is_iterable(&sqlJoin, 0, "phalcon/Mvc/Model/Query.zep", 2734);
								if (Z_TYPE_P(&sqlJoin) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&sqlJoin), _62$$47)
									{
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
										ZVAL_COPY(&sqlJoinItem, _62$$47);
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2732);
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "rewind", NULL, 0);
									zephir_check_call_status();
									while (1) {
										ZEPHIR_CALL_METHOD(&_63$$47, &sqlJoin, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_63$$47)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&sqlJoinItem, &sqlJoin, "current", NULL, 0);
										zephir_check_call_status();
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2732);
										ZEPHIR_CALL_METHOD(NULL, &sqlJoin, "next", NULL, 0);
										zephir_check_call_status();
									}
								}
								ZEPHIR_INIT_NVAR(&sqlJoinItem);
							} else {
								zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2735);
							}
						} else {
							ZEPHIR_INIT_NVAR(&_64$$51);
							zephir_create_array(&_64$$51, 3, 0);
							zephir_array_update_string(&_64$$51, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_64$$51, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_65$$51);
							array_init(&_65$$51);
							zephir_array_update_string(&_64$$51, SL("conditions"), &_65$$51, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_64$$51, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2746);
						}
					} else {
						ZEPHIR_INIT_NVAR(&_66$$52);
						zephir_create_array(&_66$$52, 3, 0);
						zephir_array_update_string(&_66$$52, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_66$$52, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_67$$52);
						zephir_create_array(&_67$$52, 1, 0);
						zephir_array_fast_append(&_67$$52, &preCondition);
						zephir_array_update_string(&_66$$52, SL("conditions"), &_67$$52, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_66$$52, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2757);
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&joinModel);
				ZEPHIR_INIT_NVAR(&joinAlias);
			ZEPHIR_CALL_METHOD(NULL, &fromModels, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_32);
	ZEPHIR_INIT_NVAR(&fromModelName);
	RETURN_CTOR(&sqlJoins);
}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string joinSource
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getMultiJoin)
{
	zend_ulong _2$$3;
	zval sqlJoins, _8$$4, _10$$4, _16$$6, _17$$6, _19$$8, _20$$8, _21$$8, _23$$8, _24$$8, _25$$8, _26$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, _0, *_1$$3, _11$$3, _4$$5, _5$$5, _7$$4, _12$$7, _13$$7, _14$$6, _15$$6, _18$$8, _22$$8;
	zend_string *joinType = NULL, *modelAlias = NULL, *joinAlias = NULL, *_3$$3;
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
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
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
		zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Query.zep", 2877);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _2$$3, _3$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&field);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&field, _3$$3);
				} else {
					ZVAL_LONG(&field, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&position);
				ZVAL_COPY(&position, _1$$3);
				if (UNEXPECTED(!(zephir_array_isset_value(&referencedFields, &position)))) {
					ZEPHIR_INIT_NVAR(&_4$$5);
					object_init_ex(&_4$$5, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", &_6, 0, &modelAlias_zv, &joinAlias_zv, &_5$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$5, "phalcon/Mvc/Model/Query.zep", 2844);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&intermediateField);
				zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2850);
				ZEPHIR_INIT_NVAR(&sqlEqualsJoinCondition);
				zephir_create_array(&sqlEqualsJoinCondition, 4, 0);
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_create_array(&_8$$4, 3, 0);
				add_assoc_long_ex(&_8$$4, SL("type"), 355);
				zephir_array_update_string(&_8$$4, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_8$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "getqualified", &_9, 0, &_8$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_7$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 3, 0);
				add_assoc_stringl_ex(&_10$$4, SL("type"), SL("qualified"));
				zephir_array_update_string(&_10$$4, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "getqualified", &_9, 0, &_10$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_7$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_11$$3, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_11$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &fields, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&position, &fields, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(!(zephir_array_isset_value(&referencedFields, &position)))) {
						ZEPHIR_INIT_NVAR(&_12$$7);
						object_init_ex(&_12$$7, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property(&_13$$7, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_6, 0, &modelAlias_zv, &joinAlias_zv, &_13$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$7, "phalcon/Mvc/Model/Query.zep", 2844);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&intermediateField);
					zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2850);
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_create_array(&_14$$6, 4, 0);
					add_assoc_stringl_ex(&_14$$6, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_14$$6, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_16$$6);
					zephir_create_array(&_16$$6, 3, 0);
					add_assoc_long_ex(&_16$$6, SL("type"), 355);
					zephir_array_update_string(&_16$$6, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$6, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "getqualified", &_9, 0, &_16$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_14$$6, SL("left"), &_15$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$6);
					zephir_create_array(&_17$$6, 3, 0);
					add_assoc_stringl_ex(&_17$$6, SL("type"), SL("qualified"));
					zephir_array_update_string(&_17$$6, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "getqualified", &_9, 0, &_17$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_14$$6, SL("right"), &_15$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlEqualsJoinCondition, &_14$$6);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&position);
		ZEPHIR_INIT_NVAR(&field);
	} else {
		ZEPHIR_INIT_VAR(&_18$$8);
		zephir_create_array(&_18$$8, 2, 0);
		ZEPHIR_INIT_VAR(&_19$$8);
		zephir_create_array(&_19$$8, 3, 0);
		zephir_array_update_string(&_19$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_20$$8);
		zephir_create_array(&_20$$8, 2, 0);
		zephir_array_fast_append(&_20$$8, &intermediateSource);
		zephir_array_fast_append(&_20$$8, &intermediateSchema);
		zephir_array_update_string(&_19$$8, SL("source"), &_20$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_20$$8);
		zephir_create_array(&_20$$8, 1, 0);
		ZEPHIR_INIT_VAR(&_21$$8);
		zephir_create_array(&_21$$8, 4, 0);
		add_assoc_stringl_ex(&_21$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_21$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_23$$8);
		zephir_create_array(&_23$$8, 3, 0);
		add_assoc_long_ex(&_23$$8, SL("type"), 355);
		zephir_array_update_string(&_23$$8, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_23$$8, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getqualified", &_9, 0, &_23$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_21$$8, SL("left"), &_22$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 3, 0);
		add_assoc_stringl_ex(&_24$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_24$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_24$$8, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getqualified", &_9, 0, &_24$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_21$$8, SL("right"), &_22$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_20$$8, &_21$$8);
		zephir_array_update_string(&_19$$8, SL("conditions"), &_20$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_INIT_NVAR(&_19$$8);
		zephir_create_array(&_19$$8, 3, 0);
		zephir_array_update_string(&_19$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_19$$8, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_20$$8);
		zephir_create_array(&_20$$8, 1, 0);
		ZEPHIR_INIT_NVAR(&_21$$8);
		zephir_create_array(&_21$$8, 4, 0);
		add_assoc_stringl_ex(&_21$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_21$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_25$$8);
		zephir_create_array(&_25$$8, 3, 0);
		add_assoc_long_ex(&_25$$8, SL("type"), 355);
		zephir_array_update_string(&_25$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_25$$8, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getqualified", &_9, 0, &_25$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_21$$8, SL("left"), &_22$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 3, 0);
		add_assoc_stringl_ex(&_26$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_26$$8, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_26$$8, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_22$$8, this_ptr, "getqualified", &_9, 0, &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_21$$8, SL("right"), &_22$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_20$$8, &_21$$8);
		zephir_array_update_string(&_19$$8, SL("conditions"), &_20$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_18$$8, &_19$$8);
		ZEPHIR_CPY_WRT(&sqlJoins, &_18$$8);
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
	zval orderParts, orderPartSort;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderItem, orderPartExpr, orderSort, *_0, _7, _1$$5, _3$$7, _4$$8, _5$$8, _6$$9, _8$$10, _9$$12, _10$$12, _11$$13, _12$$13, _13$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
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
	zephir_is_iterable(&orderColumns, 0, "phalcon/Mvc/Model/Query.zep", 2986);
	if (Z_TYPE_P(&orderColumns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&orderColumns), _0)
		{
			ZEPHIR_INIT_NVAR(&orderItem);
			ZVAL_COPY(&orderItem, _0);
			zephir_array_fetch_string(&_1$$5, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2968);
			ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getexpression", &_2, 0, &_1$$5);
			zephir_check_call_status();
			if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 1)) {
				if (ZEPHIR_IS_LONG(&orderSort, 327)) {
					ZEPHIR_INIT_NVAR(&orderPartSort);
					zephir_create_array(&orderPartSort, 2, 0);
					zephir_array_fast_append(&orderPartSort, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_3$$7);
					ZVAL_STRING(&_3$$7, "ASC");
					zephir_array_fast_append(&orderPartSort, &_3$$7);
				} else {
					ZEPHIR_INIT_NVAR(&_4$$8);
					zephir_create_array(&_4$$8, 2, 0);
					zephir_array_fast_append(&_4$$8, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_5$$8);
					ZVAL_STRING(&_5$$8, "DESC");
					zephir_array_fast_append(&_4$$8, &_5$$8);
					ZEPHIR_CPY_WRT(&orderPartSort, &_4$$8);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_6$$9);
				zephir_create_array(&_6$$9, 1, 0);
				zephir_array_fast_append(&_6$$9, &orderPartExpr);
				ZEPHIR_CPY_WRT(&orderPartSort, &_6$$9);
			}
			zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2983);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &orderColumns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &orderColumns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&orderItem, &orderColumns, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_8$$10, &orderItem, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 2968);
				ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getexpression", &_2, 0, &_8$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&orderSort);
				if (zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0)) {
					if (ZEPHIR_IS_LONG(&orderSort, 327)) {
						ZEPHIR_INIT_NVAR(&_9$$12);
						zephir_create_array(&_9$$12, 2, 0);
						zephir_array_fast_append(&_9$$12, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_10$$12);
						ZVAL_STRING(&_10$$12, "ASC");
						zephir_array_fast_append(&_9$$12, &_10$$12);
						ZEPHIR_CPY_WRT(&orderPartSort, &_9$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_11$$13);
						zephir_create_array(&_11$$13, 2, 0);
						zephir_array_fast_append(&_11$$13, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_12$$13);
						ZVAL_STRING(&_12$$13, "DESC");
						zephir_array_fast_append(&_11$$13, &_12$$13);
						ZEPHIR_CPY_WRT(&orderPartSort, &_11$$13);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_13$$14);
					zephir_create_array(&_13$$14, 1, 0);
					zephir_array_fast_append(&_13$$14, &orderPartExpr);
					ZEPHIR_CPY_WRT(&orderPartSort, &_13$$14);
				}
				zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2983);
			ZEPHIR_CALL_METHOD(NULL, &orderColumns, "next", NULL, 0);
			zephir_check_call_status();
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
	zend_bool _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_24 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _0, _5, _6, _1$$3, _2$$3, _7$$6, _11$$6, _12$$6, _8$$7, _9$$7, _10$$7, _13$$8, _14$$9, _15$$9, _16$$12, _17$$12, _18$$14, *_19$$14, _25$$14, _33$$14, _37$$14, _38$$14, _20$$15, _22$$17, _23$$17, _26$$18, _28$$20, _29$$20, _30$$21, _31$$21, _32$$21, _34$$22, _35$$23, _36$$23, _39$$27, _40$$27, _41$$27;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_33$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_41$$27);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	ZEPHIR_OBS_COPY_OR_DUP(&expr, expr_param);
	zephir_memory_observe(&columnName);
	zephir_array_fetch_string(&columnName, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3000);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("nestingLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&nestingLevel, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &nestingLevel)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("sqlColumnAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &nestingLevel, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3008);
		ZEPHIR_CPY_WRT(&sqlColumnAliases, &_2$$3);
	} else {
		ZEPHIR_INIT_NVAR(&sqlColumnAliases);
		array_init(&sqlColumnAliases);
	}
	_3 = zephir_array_isset_value(&sqlColumnAliases, &columnName);
	if (_3) {
		_4 = !(zephir_array_isset_value_string(&expr, SL("domain")));
		if (!(_4)) {
			zephir_array_fetch_string(&_5, &expr, SL("domain"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3013);
			_4 = ZEPHIR_IS_EMPTY(&_5);
		}
		_3 = _4;
	}
	if (_3) {
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
		zephir_array_update_string(return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_6);
	zephir_memory_observe(&columnDomain);
	if (zephir_array_isset_string_fetch(&columnDomain, &expr, SL("domain"), 0)) {
		zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_7$$6);
		zephir_memory_observe(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0)))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "11");
			ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 0, &columnDomain, &_10$$7, &_9$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/Model/Query.zep", 3032);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_12$$6);
		ZVAL_STRING(&_12$$6, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_11$$6, phalcon_support_settings_ce, "get", NULL, 0, &_12$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_11$$6)) {
			zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_13$$8);
			zephir_memory_observe(&model);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&model, &sqlAliasesModelsInstances, &columnDomain, 0)))) {
				ZEPHIR_INIT_VAR(&_14$$9);
				object_init_ex(&_14$$9, phalcon_mvc_model_query_exceptions_nomodelforalias_ce);
				zephir_read_property(&_15$$9, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_14$$9, "__construct", NULL, 0, &columnDomain, &_15$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$9, "phalcon/Mvc/Model/Query.zep", 3049);
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
				ZEPHIR_INIT_VAR(&_16$$12);
				object_init_ex(&_16$$12, phalcon_mvc_model_query_exceptions_columnnotindomain_ce);
				zephir_read_property(&_17$$12, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_16$$12, "__construct", NULL, 0, &columnName, &columnDomain, &_17$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_16$$12, "phalcon/Mvc/Model/Query.zep", 3059);
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
		zephir_read_property(&_18$$14, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_18$$14, 0, "phalcon/Mvc/Model/Query.zep", 3091);
		if (Z_TYPE_P(&_18$$14) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_18$$14), _19$$14)
			{
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _19$$14);
				ZEPHIR_CALL_METHOD(&_20$$15, &metaData, "hasattribute", &_21, 0, &model, &columnName);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$15)) {
					number++;
					if (UNEXPECTED(number > 1)) {
						ZEPHIR_INIT_NVAR(&_22$$17);
						object_init_ex(&_22$$17, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
						zephir_read_property(&_23$$17, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_22$$17, "__construct", &_24, 0, &columnName, &_23$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$17, "phalcon/Mvc/Model/Query.zep", 3080);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&hasModel, &model);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_18$$14, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_25$$14, &_18$$14, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_25$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&model, &_18$$14, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_26$$18, &metaData, "hasattribute", &_27, 0, &model, &columnName);
					zephir_check_call_status();
					if (zephir_is_true(&_26$$18)) {
						number++;
						if (UNEXPECTED(number > 1)) {
							ZEPHIR_INIT_NVAR(&_28$$20);
							object_init_ex(&_28$$20, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
							zephir_read_property(&_29$$20, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &_28$$20, "__construct", &_24, 0, &columnName, &_29$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_28$$20, "phalcon/Mvc/Model/Query.zep", 3080);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&hasModel, &model);
					}
				ZEPHIR_CALL_METHOD(NULL, &_18$$14, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&hasModel))) {
			ZEPHIR_INIT_VAR(&_30$$21);
			object_init_ex(&_30$$21, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
			zephir_read_property(&_31$$21, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_32$$21);
			ZVAL_STRING(&_32$$21, "1");
			ZEPHIR_CALL_METHOD(NULL, &_30$$21, "__construct", NULL, 0, &columnName, &_32$$21, &_31$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_30$$21, "phalcon/Mvc/Model/Query.zep", 3092);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_33$$14, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&models, &_33$$14);
		if (UNEXPECTED(Z_TYPE_P(&models) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_34$$22);
			object_init_ex(&_34$$22, phalcon_mvc_model_query_exceptions_modelslistnotloaded_ce);
			ZEPHIR_CALL_METHOD(NULL, &_34$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$22, "phalcon/Mvc/Model/Query.zep", 3101);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0);
		ZEPHIR_OBS_NVAR(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &models, &className, 0)))) {
			ZEPHIR_INIT_VAR(&_35$$23);
			object_init_ex(&_35$$23, phalcon_mvc_model_query_exceptions_modelsourcenotfound_ce);
			zephir_read_property(&_36$$23, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_35$$23, "__construct", NULL, 0, &className, &_36$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_35$$23, "phalcon/Mvc/Model/Query.zep", 3110);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_38$$14);
		ZVAL_STRING(&_38$$14, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_37$$14, phalcon_support_settings_ce, "get", NULL, 0, &_38$$14);
		zephir_check_call_status();
		if (zephir_is_true(&_37$$14)) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, &hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&realColumnName);
			if (UNEXPECTED(!(zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0)))) {
				ZEPHIR_INIT_VAR(&_39$$27);
				object_init_ex(&_39$$27, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
				zephir_read_property(&_40$$27, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_41$$27);
				ZVAL_STRING(&_41$$27, "3");
				ZEPHIR_CALL_METHOD(NULL, &_39$$27, "__construct", NULL, 0, &columnName, &_41$$27, &_40$$27);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_39$$27, "phalcon/Mvc/Model/Query.zep", 3127);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
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
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3169);
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
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, selectIr, whereConditions, limitConditions, query, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&selectIr);
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
	zephir_array_fetch_string(&_4, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3199);
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3201);
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
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
	zephir_read_property(&_5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
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
	zend_string *_4$$4;
	zend_ulong _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, columnData, balias, eager, _27, _0$$3, _1$$4, *_2$$4, _10$$4, _5$$5, _6$$5, _7$$5, _9$$6, _11$$7, _12$$7, _13$$7, _14$$7, _15$$8, _16$$9, _17$$10, _23$$10, _18$$11, _19$$11, _20$$11, _21$$13, _22$$13, _24$$15, _25$$16, _26$$18;
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
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$18);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(column, column_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column_param);
	ZEPHIR_OBS_COPY_OR_DUP(&column, column_param);
	zephir_memory_observe(&columnType);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columnType, &column, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 3241);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	zephir_memory_observe(&eager);
	zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$4, 0, "phalcon/Mvc/Model/Query.zep", 3271);
		if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _3$$4, _4$$4, _2$$4)
			{
				ZEPHIR_INIT_NVAR(&modelName);
				if (_4$$4 != NULL) { 
					ZVAL_STR_COPY(&modelName, _4$$4);
				} else {
					ZVAL_LONG(&modelName, _3$$4);
				}
				ZEPHIR_INIT_NVAR(&source);
				ZVAL_COPY(&source, _2$$4);
				ZEPHIR_INIT_NVAR(&sqlColumn);
				zephir_create_array(&sqlColumn, 4, 0);
				add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
				zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "\\");
				ZEPHIR_INIT_NVAR(&_7$$5);
				zephir_fast_strpos(&_7$$5, &modelName, &_6$$5, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5)) {
					ZEPHIR_CPY_WRT(&_5$$5, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&_5$$5, "lcfirst", &_8, 138, &modelName);
					zephir_check_call_status();
				}
				zephir_array_update_string(&sqlColumn, SL("balias"), &_5$$5, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&eager) != IS_NULL) {
					zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_9$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3265);
					zephir_array_update_string(&sqlColumn, SL("eagerType"), &_9$$6, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3268);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$4, &_1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelName, &_1$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &_1$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_11$$7);
					zephir_create_array(&_11$$7, 4, 0);
					add_assoc_stringl_ex(&_11$$7, SL("type"), SL("object"));
					zephir_array_update_string(&_11$$7, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_11$$7, SL("column"), &source, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, "\\");
					ZEPHIR_INIT_NVAR(&_14$$7);
					zephir_fast_strpos(&_14$$7, &modelName, &_13$$7, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_14$$7)) {
						ZEPHIR_CPY_WRT(&_12$$7, &modelName);
					} else {
						ZEPHIR_CALL_FUNCTION(&_12$$7, "lcfirst", &_8, 138, &modelName);
						zephir_check_call_status();
					}
					zephir_array_update_string(&_11$$7, SL("balias"), &_12$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlColumn, &_11$$7);
					if (Z_TYPE_P(&eager) != IS_NULL) {
						zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
						zephir_array_fetch_string(&_15$$8, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3265);
						zephir_array_update_string(&sqlColumn, SL("eagerType"), &_15$$8, PH_COPY | PH_SEPARATE);
					}
					zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3268);
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&source);
		ZEPHIR_INIT_NVAR(&modelName);
		RETURN_CTOR(&sqlColumns);
	}
	if (UNEXPECTED(!(zephir_array_isset_value_string(&column, SL("column"))))) {
		ZEPHIR_INIT_VAR(&_16$$9);
		object_init_ex(&_16$$9, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_16$$9, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_16$$9, "phalcon/Mvc/Model/Query.zep", 3275);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		zephir_read_property(&_17$$10, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_17$$10);
		zephir_memory_observe(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3287);
		ZEPHIR_OBS_NVAR(&source);
		if (UNEXPECTED(!(zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0)))) {
			ZEPHIR_INIT_VAR(&_18$$11);
			object_init_ex(&_18$$11, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property(&_19$$11, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_20$$11);
			ZVAL_STRING(&_20$$11, "2");
			ZEPHIR_CALL_METHOD(NULL, &_18$$11, "__construct", NULL, 0, &columnDomain, &_20$$11, &_19$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$11, "phalcon/Mvc/Model/Query.zep", 3290);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		zephir_memory_observe(&preparedAlias);
		zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		zephir_read_property(&_17$$10, this_ptr, ZEND_STRL("sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliasesModels, &_17$$10);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3304);
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			if (ZEPHIR_IS_EQUAL(&columnDomain, &modelName)) {
				ZEPHIR_INIT_VAR(&_21$$13);
				ZVAL_STRING(&_21$$13, "\\");
				ZEPHIR_INIT_VAR(&_22$$13);
				zephir_fast_strpos(&_22$$13, &modelName, &_21$$13, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_22$$13)) {
					ZEPHIR_CPY_WRT(&preparedAlias, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_8, 138, &modelName);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_VAR(&_23$$10);
		zephir_create_array(&_23$$10, 4, 0);
		add_assoc_stringl_ex(&_23$$10, SL("type"), SL("object"));
		zephir_array_update_string(&_23$$10, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_23$$10, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_23$$10, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&sqlColumn, &_23$$10);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_24$$15, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3326);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_24$$15, PH_COPY | PH_SEPARATE);
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3329);
		RETURN_CTOR(&sqlColumns);
	}
	if (ZEPHIR_IS_LONG(&columnType, 354)) {
		ZEPHIR_INIT_VAR(&_25$$16);
		zephir_create_array(&_25$$16, 1, 0);
		add_assoc_stringl_ex(&_25$$16, SL("type"), SL("scalar"));
		ZEPHIR_CPY_WRT(&sqlColumn, &_25$$16);
		zephir_memory_observe(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3343);
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "getexpression", NULL, 0, &columnData);
		zephir_check_call_status();
		zephir_memory_observe(&balias);
		if (zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0)) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_26$$18, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3356);
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_26$$18, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3360);
		RETURN_CTOR(&sqlColumns);
	}
	ZEPHIR_INIT_VAR(&_27);
	object_init_ex(&_27, phalcon_mvc_model_query_exceptions_unknowncolumntype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_27, "__construct", NULL, 0, &columnType);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_27, "phalcon/Mvc/Model/Query.zep", 3365);
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
	zend_ulong _6$$4;
	zval _1$$3, _3$$3, _4$$3, _11$$5, _13$$5, _14$$5, _18$$7, _20$$7, _21$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _0$$3, _2$$3, *_5$$4, _15$$4, _8$$6, _9$$6, _12$$5, _16$$8, _17$$8, _19$$7;
	zend_string *joinType = NULL, *modelAlias = NULL, *joinAlias = NULL, *_7$$4;
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
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
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
		zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Query.zep", 3453);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$4, _7$$4, _5$$4)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&position, _7$$4);
				} else {
					ZVAL_LONG(&position, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _5$$4);
				ZEPHIR_OBS_NVAR(&referencedField);
				if (UNEXPECTED(!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0)))) {
					ZEPHIR_INIT_NVAR(&_8$$6);
					object_init_ex(&_8$$6, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_10, 0, &modelAlias_zv, &joinAlias_zv, &_9$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$6, "phalcon/Mvc/Model/Query.zep", 3425);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_create_array(&_11$$5, 4, 0);
				add_assoc_stringl_ex(&_11$$5, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_11$$5, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_13$$5);
				zephir_create_array(&_13$$5, 3, 0);
				add_assoc_long_ex(&_13$$5, SL("type"), 355);
				zephir_array_update_string(&_13$$5, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getqualified", NULL, 0, &_13$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL("left"), &_12$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_14$$5);
				zephir_create_array(&_14$$5, 3, 0);
				add_assoc_stringl_ex(&_14$$5, SL("type"), SL("qualified"));
				zephir_array_update_string(&_14$$5, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_14$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "getqualified", NULL, 0, &_14$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_11$$5, SL("right"), &_12$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoinPartialConditions, &_11$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3450);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_15$$4, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, &fields, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&referencedField);
					if (UNEXPECTED(!(zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0)))) {
						ZEPHIR_INIT_NVAR(&_16$$8);
						object_init_ex(&_16$$8, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property(&_17$$8, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_16$$8, "__construct", &_10, 0, &modelAlias_zv, &joinAlias_zv, &_17$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_16$$8, "phalcon/Mvc/Model/Query.zep", 3425);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_18$$7);
					zephir_create_array(&_18$$7, 4, 0);
					add_assoc_stringl_ex(&_18$$7, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_18$$7, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_20$$7);
					zephir_create_array(&_20$$7, 3, 0);
					add_assoc_long_ex(&_20$$7, SL("type"), 355);
					zephir_array_update_string(&_20$$7, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$7, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "getqualified", NULL, 0, &_20$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_18$$7, SL("left"), &_19$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_21$$7);
					zephir_create_array(&_21$$7, 3, 0);
					add_assoc_stringl_ex(&_21$$7, SL("type"), SL("qualified"));
					zephir_array_update_string(&_21$$7, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_21$$7, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_19$$7, this_ptr, "getqualified", NULL, 0, &_21$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_18$$7, SL("right"), &_19$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoinPartialConditions, &_18$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3450);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 3475);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transaction"), PH_NOISY_CC | PH_READONLY);
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
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3511);
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
 * Refreshes the schema/source of every model referenced in a cached
 * intermediate representation. The PHQL cache is keyed by the PHQL
 * string only, so a model that switches its schema or source at
 * runtime (for instance via setSchema()/setSource() in initialize())
 * would otherwise see the value frozen at first parse. See #17020.
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, refreshSchemasInIntermediate)
{
	zend_bool _5$$6, _11$$15;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *irPhql_param = NULL, __$null, manager, models, tables, modelName, model, schema, source, currentTable, alias, index, _0, *_1, _9;
	zval irPhql, _6$$10, _7$$11, _8$$13, _12$$19, _13$$20, _14$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$22);
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
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(irPhql, irPhql_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &irPhql_param);
	zephir_get_arrval(&irPhql, irPhql_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query.zep", 3581);
	if (Z_TYPE_P(&models) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&index, _3);
			} else {
				ZVAL_LONG(&index, _2);
			}
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _1);
			if (!(zephir_array_isset_value(&tables, &index))) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_4, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3553);
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_NULL(&alias);
			_5$$6 = Z_TYPE_P(&currentTable) == IS_ARRAY;
			if (_5$$6) {
				_5$$6 = zephir_array_isset_value_long(&currentTable, 2);
			}
			if (_5$$6) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3563);
			}
			if (zephir_is_true(&schema)) {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_6$$10);
					zephir_create_array(&_6$$10, 3, 0);
					zephir_array_fast_append(&_6$$10, &source);
					zephir_array_fast_append(&_6$$10, &schema);
					zephir_array_fast_append(&_6$$10, &alias);
					zephir_array_update_zval(&tables, &index, &_6$$10, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_7$$11);
					zephir_create_array(&_7$$11, 2, 0);
					zephir_array_fast_append(&_7$$11, &source);
					zephir_array_fast_append(&_7$$11, &schema);
					zephir_array_update_zval(&tables, &index, &_7$$11, PH_COPY | PH_SEPARATE);
				}
			} else {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_8$$13);
					zephir_create_array(&_8$$13, 3, 0);
					zephir_array_fast_append(&_8$$13, &source);
					zephir_array_fast_append(&_8$$13, &__$null);
					zephir_array_fast_append(&_8$$13, &alias);
					zephir_array_update_zval(&tables, &index, &_8$$13, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &models, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &models, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &models, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&modelName, &models, "current", NULL, 0);
			zephir_check_call_status();
				if (!(zephir_array_isset_value(&tables, &index))) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_10, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&currentTable);
				zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3553);
				ZEPHIR_INIT_NVAR(&alias);
				ZVAL_NULL(&alias);
				_11$$15 = Z_TYPE_P(&currentTable) == IS_ARRAY;
				if (_11$$15) {
					_11$$15 = zephir_array_isset_value_long(&currentTable, 2);
				}
				if (_11$$15) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3563);
				}
				if (zephir_is_true(&schema)) {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_12$$19);
						zephir_create_array(&_12$$19, 3, 0);
						zephir_array_fast_append(&_12$$19, &source);
						zephir_array_fast_append(&_12$$19, &schema);
						zephir_array_fast_append(&_12$$19, &alias);
						zephir_array_update_zval(&tables, &index, &_12$$19, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_13$$20);
						zephir_create_array(&_13$$20, 2, 0);
						zephir_array_fast_append(&_13$$20, &source);
						zephir_array_fast_append(&_13$$20, &schema);
						zephir_array_update_zval(&tables, &index, &_13$$20, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_14$$22);
						zephir_create_array(&_14$$22, 3, 0);
						zephir_array_fast_append(&_14$$22, &source);
						zephir_array_fast_append(&_14$$22, &__$null);
						zephir_array_fast_append(&_14$$22, &alias);
						zephir_array_update_zval(&tables, &index, &_14$$22, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &models, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	ZEPHIR_INIT_NVAR(&index);
	zephir_array_update_string(&irPhql, SL("tables"), &tables, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(&irPhql);
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, _0, *_3, _7, _1$$3, _2$$4, _5$$8, _6$$9, _9$$13, _10$$14, _11$$17, _12$$17, _13$$18;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$18);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("ast"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&delete);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&delete, &ast, SL("delete"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3600);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 3604);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(&deleteTables, 0, "phalcon/Mvc/Model/Query.zep", 3664);
	if (Z_TYPE_P(&deleteTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deleteTables), _3)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _3);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3628);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3629);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_4, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_5$$8);
				zephir_create_array(&_5$$8, 2, 0);
				zephir_array_fast_append(&_5$$8, &source);
				zephir_array_fast_append(&_5$$8, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_5$$8);
			} else {
				ZEPHIR_INIT_NVAR(&_6$$9);
				zephir_create_array(&_6$$9, 2, 0);
				zephir_array_fast_append(&_6$$9, &source);
				zephir_array_fast_append(&_6$$9, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_6$$9);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3646);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3647);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3653);
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3657);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &deleteTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &deleteTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, &deleteTables, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3628);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3629);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_8, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_9$$13);
					zephir_create_array(&_9$$13, 2, 0);
					zephir_array_fast_append(&_9$$13, &source);
					zephir_array_fast_append(&_9$$13, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_9$$13);
				} else {
					ZEPHIR_INIT_NVAR(&_10$$14);
					zephir_create_array(&_10$$14, 2, 0);
					zephir_array_fast_append(&_10$$14, &source);
					zephir_array_fast_append(&_10$$14, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_10$$14);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3646);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3647);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3653);
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3657);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &deleteTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &models);
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &modelsInstances);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlDelete);
	array_init(&sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_12$$17, 1);
		ZEPHIR_CALL_METHOD(&_11$$17, this_ptr, "getexpression", NULL, 0, &where, &_12$$17);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_11$$17, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_13$$18, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_13$$18, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlDelete);
}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert)
{
	zval _7$$7, _13$$8;
	zend_bool notQuoting = 0;
	zval ast, qualifiedName, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, _0, _5, *_6, _12, _1$$3, _2$$4, _3$$5, _4$$6, _8$$7, _9$$7, _10$$7, _14$$8, _15$$8, _16$$8, *_17$$9, _23$$9, _18$$10, _20$$11, _21$$11, _24$$12, _26$$13, _27$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_19 = NULL, *_22 = NULL, *_25 = NULL;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_13$$8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("ast"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&ast, SL("qualifiedName"))))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3698);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_value_string(&ast, SL("values"))))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 3702);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3705);
	if (UNEXPECTED(!(zephir_array_isset_value_string(&qualifiedName, SL("name"))))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 3709);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3713);
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
	zephir_array_fetch_string(&_5, &ast, SL("values"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3726);
	zephir_is_iterable(&_5, 0, "phalcon/Mvc/Model/Query.zep", 3734);
	if (Z_TYPE_P(&_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
		{
			ZEPHIR_INIT_NVAR(&exprValue);
			ZVAL_COPY(&exprValue, _6);
			ZEPHIR_INIT_NVAR(&_7$$7);
			zephir_create_array(&_7$$7, 2, 0);
			ZEPHIR_OBS_NVAR(&_8$$7);
			zephir_array_fetch_string(&_8$$7, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3729);
			zephir_array_update_string(&_7$$7, SL("type"), &_8$$7, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_10$$7, 1);
			} else {
				ZVAL_BOOL(&_10$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_9$$7, this_ptr, "getexpression", &_11, 0, &exprValue, &_10$$7);
			zephir_check_call_status();
			zephir_array_update_string(&_7$$7, SL("value"), &_9$$7, PH_COPY | PH_SEPARATE);
			zephir_array_append(&exprValues, &_7$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3731);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_5, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_12, &_5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&exprValue, &_5, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$8);
				zephir_create_array(&_13$$8, 2, 0);
				ZEPHIR_OBS_NVAR(&_14$$8);
				zephir_array_fetch_string(&_14$$8, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3729);
				zephir_array_update_string(&_13$$8, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_16$$8, 1);
				} else {
					ZVAL_BOOL(&_16$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_15$$8, this_ptr, "getexpression", &_11, 0, &exprValue, &_16$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$8, SL("value"), &_15$$8, PH_COPY | PH_SEPARATE);
				zephir_array_append(&exprValues, &_13$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3731);
			ZEPHIR_CALL_METHOD(NULL, &_5, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&exprValue);
	ZEPHIR_INIT_VAR(&sqlInsert);
	zephir_create_array(&sqlInsert, 2, 0);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	zephir_memory_observe(&fields);
	if (zephir_array_isset_string_fetch(&fields, &ast, SL("fields"), 0)) {
		ZEPHIR_INIT_VAR(&sqlFields);
		array_init(&sqlFields);
		zephir_is_iterable(&fields, 0, "phalcon/Mvc/Model/Query.zep", 3756);
		if (Z_TYPE_P(&fields) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _17$$9)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _17$$9);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3745);
				ZEPHIR_CALL_METHOD(&_18$$10, &metaData, "hasattribute", &_19, 0, &model, &name);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_18$$10))) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					object_init_ex(&_20$$11, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
					zephir_read_property(&_21$$11, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_20$$11, "__construct", &_22, 0, &modelName, &name, &_21$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_20$$11, "phalcon/Mvc/Model/Query.zep", 3749);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3753);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_23$$9, &fields, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_23$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3745);
					ZEPHIR_CALL_METHOD(&_24$$12, &metaData, "hasattribute", &_25, 0, &model, &name);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_24$$12))) {
						ZEPHIR_INIT_NVAR(&_26$$13);
						object_init_ex(&_26$$13, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
						zephir_read_property(&_27$$13, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_26$$13, "__construct", &_22, 0, &modelName, &name, &_27$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$13, "phalcon/Mvc/Model/Query.zep", 3749);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3753);
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
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
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect)
{
	zval _14$$24, _27$$28, _46$$43, _58$$47, _87$$66, _91$$73, _97$$81, _101$$88;
	zval sqlModels, sqlTables, sqlAliases, sqlColumns, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, models, modelsInstances, _22$$24, _23$$24, _24$$24, _34$$28, _35$$28, _36$$28, _53$$43, _54$$43, _55$$43, _65$$47, _66$$47, _67$$47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_15 = NULL, *_17 = NULL, *_20 = NULL, *_28 = NULL, *_30 = NULL, *_38 = NULL, *_47 = NULL, *_49 = NULL, *_59 = NULL, *_61 = NULL, *_83 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zend_bool merge;
	zval *ast = NULL, ast_sub, *merge_param = NULL, __$null, __$true, select, tables, columns, selectedModels, manager, metaData, selectedModel, qualifiedName, modelName, model, schema, source, completeSource, alias, joins, sqlJoins, selectColumns, sqlColumnAliases, column, sqlColumn, sqlSelect, distinct, having, where, groupBy, order, limit, tempModels, tempModelsInstances, tempSqlAliases, tempSqlModelsAliases, tempSqlAliasesModelsInstances, tempSqlAliasesModels, with, withs, withItem, automaticJoins, relation, joinAlias, relationModel, bestAlias, eagerType, _3, *_6, _37, *_81, _92, _102, _0$$3, _1$$5, _2$$6, _4$$11, _5$$12, _8$$17, _9$$17, _11$$19, *_12$$21, _25$$21, _13$$24, _16$$25, _18$$27, _19$$27, _21$$26, _26$$28, _29$$29, _31$$31, _32$$31, _33$$30, _39$$33, _40$$36, _41$$36, _42$$38, _43$$41, *_44$$40, _56$$40, _45$$43, _48$$44, _50$$46, _51$$46, _52$$45, _57$$47, _60$$48, _62$$50, _63$$50, _64$$49, _68$$52, _69$$52, _70$$52, _71$$52, _72$$52, _73$$52, _74$$52, _75$$52, _76$$52, _77$$52, _78$$52, _79$$52, _80$$55, _82$$60, *_84$$60, _88$$60, _85$$65, _86$$66, _89$$72, _90$$73, _93$$75, *_94$$75, _98$$75, _95$$80, _96$$81, _99$$87, _100$$88, _103$$92, _104$$93, _105$$94, _106$$95, _107$$96;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ast_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&selectedModels);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&selectedModel);
	ZVAL_UNDEF(&qualifiedName);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&completeSource);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&selectColumns);
	ZVAL_UNDEF(&sqlColumnAliases);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&sqlColumn);
	ZVAL_UNDEF(&sqlSelect);
	ZVAL_UNDEF(&distinct);
	ZVAL_UNDEF(&having);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&groupBy);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&tempModels);
	ZVAL_UNDEF(&tempModelsInstances);
	ZVAL_UNDEF(&tempSqlAliases);
	ZVAL_UNDEF(&tempSqlModelsAliases);
	ZVAL_UNDEF(&tempSqlAliasesModelsInstances);
	ZVAL_UNDEF(&tempSqlAliasesModels);
	ZVAL_UNDEF(&with);
	ZVAL_UNDEF(&withs);
	ZVAL_UNDEF(&withItem);
	ZVAL_UNDEF(&automaticJoins);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&joinAlias);
	ZVAL_UNDEF(&relationModel);
	ZVAL_UNDEF(&bestAlias);
	ZVAL_UNDEF(&eagerType);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_92);
	ZVAL_UNDEF(&_102);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_8$$17);
	ZVAL_UNDEF(&_9$$17);
	ZVAL_UNDEF(&_11$$19);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_13$$24);
	ZVAL_UNDEF(&_16$$25);
	ZVAL_UNDEF(&_18$$27);
	ZVAL_UNDEF(&_19$$27);
	ZVAL_UNDEF(&_21$$26);
	ZVAL_UNDEF(&_26$$28);
	ZVAL_UNDEF(&_29$$29);
	ZVAL_UNDEF(&_31$$31);
	ZVAL_UNDEF(&_32$$31);
	ZVAL_UNDEF(&_33$$30);
	ZVAL_UNDEF(&_39$$33);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_41$$36);
	ZVAL_UNDEF(&_42$$38);
	ZVAL_UNDEF(&_43$$41);
	ZVAL_UNDEF(&_56$$40);
	ZVAL_UNDEF(&_45$$43);
	ZVAL_UNDEF(&_48$$44);
	ZVAL_UNDEF(&_50$$46);
	ZVAL_UNDEF(&_51$$46);
	ZVAL_UNDEF(&_52$$45);
	ZVAL_UNDEF(&_57$$47);
	ZVAL_UNDEF(&_60$$48);
	ZVAL_UNDEF(&_62$$50);
	ZVAL_UNDEF(&_63$$50);
	ZVAL_UNDEF(&_64$$49);
	ZVAL_UNDEF(&_68$$52);
	ZVAL_UNDEF(&_69$$52);
	ZVAL_UNDEF(&_70$$52);
	ZVAL_UNDEF(&_71$$52);
	ZVAL_UNDEF(&_72$$52);
	ZVAL_UNDEF(&_73$$52);
	ZVAL_UNDEF(&_74$$52);
	ZVAL_UNDEF(&_75$$52);
	ZVAL_UNDEF(&_76$$52);
	ZVAL_UNDEF(&_77$$52);
	ZVAL_UNDEF(&_78$$52);
	ZVAL_UNDEF(&_79$$52);
	ZVAL_UNDEF(&_80$$55);
	ZVAL_UNDEF(&_82$$60);
	ZVAL_UNDEF(&_88$$60);
	ZVAL_UNDEF(&_85$$65);
	ZVAL_UNDEF(&_86$$66);
	ZVAL_UNDEF(&_89$$72);
	ZVAL_UNDEF(&_90$$73);
	ZVAL_UNDEF(&_93$$75);
	ZVAL_UNDEF(&_98$$75);
	ZVAL_UNDEF(&_95$$80);
	ZVAL_UNDEF(&_96$$81);
	ZVAL_UNDEF(&_99$$87);
	ZVAL_UNDEF(&_100$$88);
	ZVAL_UNDEF(&_103$$92);
	ZVAL_UNDEF(&_104$$93);
	ZVAL_UNDEF(&_105$$94);
	ZVAL_UNDEF(&_106$$95);
	ZVAL_UNDEF(&_107$$96);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&_22$$24);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_34$$28);
	ZVAL_UNDEF(&_35$$28);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_53$$43);
	ZVAL_UNDEF(&_54$$43);
	ZVAL_UNDEF(&_55$$43);
	ZVAL_UNDEF(&_65$$47);
	ZVAL_UNDEF(&_66$$47);
	ZVAL_UNDEF(&_67$$47);
	ZVAL_UNDEF(&_14$$24);
	ZVAL_UNDEF(&_27$$28);
	ZVAL_UNDEF(&_46$$43);
	ZVAL_UNDEF(&_58$$47);
	ZVAL_UNDEF(&_87$$66);
	ZVAL_UNDEF(&_91$$73);
	ZVAL_UNDEF(&_97$$81);
	ZVAL_UNDEF(&_101$$88);
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
	if (ZEPHIR_IS_EMPTY(ast)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("ast"), PH_NOISY_CC | PH_READONLY);
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
		zephir_throw_exception_debug(&_1$$5, "phalcon/Mvc/Model/Query.zep", 3792);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		object_init_ex(&_2$$6, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$6, "phalcon/Mvc/Model/Query.zep", 3796);
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
	zephir_read_property(&_3, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("metaData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_3);
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_4$$11);
		object_init_ex(&_4$$11, phalcon_mvc_model_query_exceptions_missingmodelsmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$11, "phalcon/Mvc/Model/Query.zep", 3861);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_5$$12);
		object_init_ex(&_5$$12, phalcon_mvc_model_query_exceptions_missingmetadata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$12, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$12, "phalcon/Mvc/Model/Query.zep", 3865);
		ZEPHIR_MM_RESTORE();
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	zephir_is_iterable(&selectedModels, 0, "phalcon/Mvc/Model/Query.zep", 3991);
	if (Z_TYPE_P(&selectedModels) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectedModels), _6)
		{
			ZEPHIR_INIT_NVAR(&selectedModel);
			ZVAL_COPY(&selectedModel, _6);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3873);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3874);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_7, 0, &modelName);
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
					ZEPHIR_INIT_NVAR(&_8$$17);
					object_init_ex(&_8$$17, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
					zephir_read_property(&_9$$17, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_8$$17, "__construct", &_10, 0, &alias, &_9$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$17, "phalcon/Mvc/Model/Query.zep", 3897);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3909);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$19);
					zephir_create_array(&_11$$19, 3, 0);
					zephir_array_fast_append(&_11$$19, &source);
					zephir_array_fast_append(&_11$$19, &__$null);
					zephir_array_fast_append(&_11$$19, &alias);
					ZEPHIR_CPY_WRT(&completeSource, &_11$$19);
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
				zephir_is_iterable(&withs, 0, "phalcon/Mvc/Model/Query.zep", 3983);
				if (Z_TYPE_P(&withs) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&withs), _12$$21)
					{
						ZEPHIR_INIT_NVAR(&withItem);
						ZVAL_COPY(&withItem, _12$$21);
						ZEPHIR_INIT_NVAR(&_13$$24);
						ZVAL_LONG(&_13$$24, number);
						ZEPHIR_INIT_NVAR(&_14$$24);
						ZEPHIR_CONCAT_SV(&_14$$24, "AA", &_13$$24);
						ZEPHIR_CPY_WRT(&joinAlias, &_14$$24);
						ZEPHIR_OBS_NVAR(&relationModel);
						zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3935);
						ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_15, 0, &modelName, &relationModel);
						zephir_check_call_status();
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_16$$25);
							ZVAL_STRING(&_16$$25, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_16$$25);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_17, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
								ZEPHIR_INIT_NVAR(&_18$$27);
								object_init_ex(&_18$$27, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
								zephir_read_property(&_19$$27, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_18$$27, "__construct", &_20, 0, &modelName, &relationModel, &_19$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_18$$27, "phalcon/Mvc/Model/Query.zep", 3953);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_21$$26);
							ZVAL_STRING(&_21$$26, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_21$$26);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_22$$24);
						zephir_create_array(&_22$$24, 5, 0);
						add_assoc_long_ex(&_22$$24, SL("type"), 353);
						zephir_array_update_string(&_22$$24, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_22$$24, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_22$$24, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_22$$24, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
						zephir_array_append(&selectColumns, &_22$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3967);
						ZEPHIR_INIT_NVAR(&_23$$24);
						zephir_create_array(&_23$$24, 3, 0);
						add_assoc_long_ex(&_23$$24, SL("type"), 360);
						ZEPHIR_INIT_NVAR(&_24$$24);
						zephir_create_array(&_24$$24, 2, 0);
						add_assoc_long_ex(&_24$$24, SL("type"), 355);
						zephir_array_update_string(&_24$$24, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_23$$24, SL("qualified"), &_24$$24, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_24$$24);
						zephir_create_array(&_24$$24, 2, 0);
						add_assoc_long_ex(&_24$$24, SL("type"), 355);
						zephir_array_update_string(&_24$$24, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_23$$24, SL("alias"), &_24$$24, PH_COPY | PH_SEPARATE);
						zephir_array_append(&automaticJoins, &_23$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3979);
						number++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &withs, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_25$$21, &withs, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_25$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&withItem, &withs, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_26$$28);
							ZVAL_LONG(&_26$$28, number);
							ZEPHIR_INIT_NVAR(&_27$$28);
							ZEPHIR_CONCAT_SV(&_27$$28, "AA", &_26$$28);
							ZEPHIR_CPY_WRT(&joinAlias, &_27$$28);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3935);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_28, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_29$$29);
								ZVAL_STRING(&_29$$29, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_29$$29);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_30, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
									ZEPHIR_INIT_NVAR(&_31$$31);
									object_init_ex(&_31$$31, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property(&_32$$31, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_31$$31, "__construct", &_20, 0, &modelName, &relationModel, &_32$$31);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_31$$31, "phalcon/Mvc/Model/Query.zep", 3953);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_33$$30);
								ZVAL_STRING(&_33$$30, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_33$$30);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_34$$28);
							zephir_create_array(&_34$$28, 5, 0);
							add_assoc_long_ex(&_34$$28, SL("type"), 353);
							zephir_array_update_string(&_34$$28, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_34$$28, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_34$$28, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_34$$28, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_34$$28, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3967);
							ZEPHIR_INIT_NVAR(&_35$$28);
							zephir_create_array(&_35$$28, 3, 0);
							add_assoc_long_ex(&_35$$28, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_36$$28);
							zephir_create_array(&_36$$28, 2, 0);
							add_assoc_long_ex(&_36$$28, SL("type"), 355);
							zephir_array_update_string(&_36$$28, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_35$$28, SL("qualified"), &_36$$28, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_36$$28);
							zephir_create_array(&_36$$28, 2, 0);
							add_assoc_long_ex(&_36$$28, SL("type"), 355);
							zephir_array_update_string(&_36$$28, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_35$$28, SL("alias"), &_36$$28, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_35$$28, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3979);
							number++;
						ZEPHIR_CALL_METHOD(NULL, &withs, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&withItem);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3985);
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3986);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectedModels, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_37, &selectedModels, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_37)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&selectedModel, &selectedModels, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3873);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3874);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_38, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_39$$33);
					zephir_create_array(&_39$$33, 2, 0);
					zephir_array_fast_append(&_39$$33, &source);
					zephir_array_fast_append(&_39$$33, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_39$$33);
				} else {
					ZEPHIR_CPY_WRT(&completeSource, &source);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0)) {
					if (UNEXPECTED(zephir_array_isset_value(&sqlAliases, &alias))) {
						ZEPHIR_INIT_NVAR(&_40$$36);
						object_init_ex(&_40$$36, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
						zephir_read_property(&_41$$36, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_40$$36, "__construct", &_10, 0, &alias, &_41$$36);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_40$$36, "phalcon/Mvc/Model/Query.zep", 3897);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
						zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3909);
					} else {
						ZEPHIR_INIT_NVAR(&_42$$38);
						zephir_create_array(&_42$$38, 3, 0);
						zephir_array_fast_append(&_42$$38, &source);
						zephir_array_fast_append(&_42$$38, &__$null);
						zephir_array_fast_append(&_42$$38, &alias);
						ZEPHIR_CPY_WRT(&completeSource, &_42$$38);
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
						ZEPHIR_INIT_NVAR(&_43$$41);
						zephir_create_array(&_43$$41, 1, 0);
						zephir_array_fast_append(&_43$$41, &with);
						ZEPHIR_CPY_WRT(&withs, &_43$$41);
					} else {
						ZEPHIR_CPY_WRT(&withs, &with);
					}
					zephir_is_iterable(&withs, 0, "phalcon/Mvc/Model/Query.zep", 3983);
					if (Z_TYPE_P(&withs) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&withs), _44$$40)
						{
							ZEPHIR_INIT_NVAR(&withItem);
							ZVAL_COPY(&withItem, _44$$40);
							ZEPHIR_INIT_NVAR(&_45$$43);
							ZVAL_LONG(&_45$$43, number);
							ZEPHIR_INIT_NVAR(&_46$$43);
							ZEPHIR_CONCAT_SV(&_46$$43, "AA", &_45$$43);
							ZEPHIR_CPY_WRT(&joinAlias, &_46$$43);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3935);
							ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_47, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_48$$44);
								ZVAL_STRING(&_48$$44, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_48$$44);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_49, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
									ZEPHIR_INIT_NVAR(&_50$$46);
									object_init_ex(&_50$$46, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property(&_51$$46, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_50$$46, "__construct", &_20, 0, &modelName, &relationModel, &_51$$46);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_50$$46, "phalcon/Mvc/Model/Query.zep", 3953);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_52$$45);
								ZVAL_STRING(&_52$$45, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_52$$45);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_53$$43);
							zephir_create_array(&_53$$43, 5, 0);
							add_assoc_long_ex(&_53$$43, SL("type"), 353);
							zephir_array_update_string(&_53$$43, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_53$$43, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_53$$43, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_53$$43, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_53$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3967);
							ZEPHIR_INIT_NVAR(&_54$$43);
							zephir_create_array(&_54$$43, 3, 0);
							add_assoc_long_ex(&_54$$43, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_55$$43);
							zephir_create_array(&_55$$43, 2, 0);
							add_assoc_long_ex(&_55$$43, SL("type"), 355);
							zephir_array_update_string(&_55$$43, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_54$$43, SL("qualified"), &_55$$43, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_55$$43);
							zephir_create_array(&_55$$43, 2, 0);
							add_assoc_long_ex(&_55$$43, SL("type"), 355);
							zephir_array_update_string(&_55$$43, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_54$$43, SL("alias"), &_55$$43, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_54$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3979);
							number++;
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &withs, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_56$$40, &withs, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_56$$40)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&withItem, &withs, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_57$$47);
								ZVAL_LONG(&_57$$47, number);
								ZEPHIR_INIT_NVAR(&_58$$47);
								ZEPHIR_CONCAT_SV(&_58$$47, "AA", &_57$$47);
								ZEPHIR_CPY_WRT(&joinAlias, &_58$$47);
								ZEPHIR_OBS_NVAR(&relationModel);
								zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3935);
								ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationbyalias", &_59, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_60$$48);
									ZVAL_STRING(&_60$$48, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_60$$48);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&relation, &manager, "getrelationsbetween", &_61, 0, &modelName, &relationModel);
									zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&relation) != IS_OBJECT)) {
										ZEPHIR_INIT_NVAR(&_62$$50);
										object_init_ex(&_62$$50, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
										zephir_read_property(&_63$$50, this_ptr, ZEND_STRL("phql"), PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_METHOD(NULL, &_62$$50, "__construct", &_20, 0, &modelName, &relationModel, &_63$$50);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_62$$50, "phalcon/Mvc/Model/Query.zep", 3953);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_64$$49);
									ZVAL_STRING(&_64$$49, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getoption", NULL, 0, &_64$$49);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getreferencedmodel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "gettype", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_INIT_NVAR(&_65$$47);
								zephir_create_array(&_65$$47, 5, 0);
								add_assoc_long_ex(&_65$$47, SL("type"), 353);
								zephir_array_update_string(&_65$$47, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_65$$47, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_65$$47, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_65$$47, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
								zephir_array_append(&selectColumns, &_65$$47, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3967);
								ZEPHIR_INIT_NVAR(&_66$$47);
								zephir_create_array(&_66$$47, 3, 0);
								add_assoc_long_ex(&_66$$47, SL("type"), 360);
								ZEPHIR_INIT_NVAR(&_67$$47);
								zephir_create_array(&_67$$47, 2, 0);
								add_assoc_long_ex(&_67$$47, SL("type"), 355);
								zephir_array_update_string(&_67$$47, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_66$$47, SL("qualified"), &_67$$47, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_67$$47);
								zephir_create_array(&_67$$47, 2, 0);
								add_assoc_long_ex(&_67$$47, SL("type"), 355);
								zephir_array_update_string(&_67$$47, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_66$$47, SL("alias"), &_67$$47, PH_COPY | PH_SEPARATE);
								zephir_array_append(&automaticJoins, &_66$$47, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3979);
								number++;
							ZEPHIR_CALL_METHOD(NULL, &withs, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&withItem);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3985);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3986);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &selectedModels, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&selectedModel);
	if (!(merge)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &models);
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &modelsInstances);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &sqlAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModels"), &sqlAliasesModels);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlModelsAliases"), &sqlModelsAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
	} else {
		zephir_memory_observe(&tempModels);
		zephir_read_property(&tempModels, this_ptr, ZEND_STRL("models"), PH_NOISY_CC);
		zephir_memory_observe(&tempModelsInstances);
		zephir_read_property(&tempModelsInstances, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC);
		zephir_memory_observe(&tempSqlAliases);
		zephir_read_property(&tempSqlAliases, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC);
		zephir_memory_observe(&tempSqlAliasesModels);
		zephir_read_property(&tempSqlAliasesModels, this_ptr, ZEND_STRL("sqlAliasesModels"), PH_NOISY_CC);
		zephir_memory_observe(&tempSqlModelsAliases);
		zephir_read_property(&tempSqlModelsAliases, this_ptr, ZEND_STRL("sqlModelsAliases"), PH_NOISY_CC);
		zephir_memory_observe(&tempSqlAliasesModelsInstances);
		zephir_read_property(&tempSqlAliasesModelsInstances, this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_68$$52);
		zephir_read_property(&_69$$52, this_ptr, ZEND_STRL("models"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_68$$52, &_69$$52, &models);
		zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &_68$$52);
		ZEPHIR_INIT_VAR(&_70$$52);
		zephir_read_property(&_71$$52, this_ptr, ZEND_STRL("modelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_70$$52, &_71$$52, &modelsInstances);
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &_70$$52);
		ZEPHIR_INIT_VAR(&_72$$52);
		zephir_read_property(&_73$$52, this_ptr, ZEND_STRL("sqlAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_72$$52, &_73$$52, &sqlAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &_72$$52);
		ZEPHIR_INIT_VAR(&_74$$52);
		zephir_read_property(&_75$$52, this_ptr, ZEND_STRL("sqlAliasesModels"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_74$$52, &_75$$52, &sqlAliasesModels);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModels"), &_74$$52);
		ZEPHIR_INIT_VAR(&_76$$52);
		zephir_read_property(&_77$$52, this_ptr, ZEND_STRL("sqlModelsAliases"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_76$$52, &_77$$52, &sqlModelsAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlModelsAliases"), &_76$$52);
		ZEPHIR_INIT_VAR(&_78$$52);
		zephir_read_property(&_79$$52, this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_78$$52, &_79$$52, &sqlAliasesModelsInstances);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &_78$$52);
	}
	zephir_memory_observe(&joins);
	zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (zephir_fast_count_int(&joins)) {
		if (zephir_fast_count_int(&automaticJoins)) {
			if (zephir_array_isset_value_long(&joins, 0)) {
				ZEPHIR_INIT_VAR(&_80$$55);
				zephir_fast_array_merge(&_80$$55, &joins, &automaticJoins);
				zephir_array_update_string(&select, SL("joins"), &_80$$55, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_append(&automaticJoins, &joins, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4022);
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getjoins", NULL, 0, &select);
		zephir_check_call_status();
	} else {
		if (zephir_fast_count_int(&automaticJoins)) {
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
	zephir_is_iterable(&selectColumns, 0, "phalcon/Mvc/Model/Query.zep", 4073);
	if (Z_TYPE_P(&selectColumns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&selectColumns), _81)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _81);
			ZEPHIR_CALL_METHOD(&_82$$60, this_ptr, "getselectcolumn", &_83, 0, &column);
			zephir_check_call_status();
			zephir_is_iterable(&_82$$60, 0, "phalcon/Mvc/Model/Query.zep", 4071);
			if (Z_TYPE_P(&_82$$60) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_82$$60), _84$$60)
				{
					ZEPHIR_INIT_NVAR(&sqlColumn);
					ZVAL_COPY(&sqlColumn, _84$$60);
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
							zephir_array_fetch_string(&_85$$65, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4061);
							if (ZEPHIR_IS_STRING(&_85$$65, "scalar")) {
								ZEPHIR_INIT_NVAR(&_86$$66);
								ZVAL_LONG(&_86$$66, position);
								ZEPHIR_INIT_NVAR(&_87$$66);
								ZEPHIR_CONCAT_SV(&_87$$66, "_", &_86$$66);
								zephir_array_update_zval(&sqlColumns, &_87$$66, &sqlColumn, PH_COPY | PH_SEPARATE);
							} else {
								zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4064);
							}
						}
					}
					position++;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_82$$60, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_88$$60, &_82$$60, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_88$$60)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&sqlColumn, &_82$$60, "current", NULL, 0);
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
								zephir_array_fetch_string(&_89$$72, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4061);
								if (ZEPHIR_IS_STRING(&_89$$72, "scalar")) {
									ZEPHIR_INIT_NVAR(&_90$$73);
									ZVAL_LONG(&_90$$73, position);
									ZEPHIR_INIT_NVAR(&_91$$73);
									ZEPHIR_CONCAT_SV(&_91$$73, "_", &_90$$73);
									zephir_array_update_zval(&sqlColumns, &_91$$73, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4064);
								}
							}
						}
						position++;
					ZEPHIR_CALL_METHOD(NULL, &_82$$60, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&sqlColumn);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &selectColumns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_92, &selectColumns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_92)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &selectColumns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_93$$75, this_ptr, "getselectcolumn", &_83, 0, &column);
				zephir_check_call_status();
				zephir_is_iterable(&_93$$75, 0, "phalcon/Mvc/Model/Query.zep", 4071);
				if (Z_TYPE_P(&_93$$75) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_93$$75), _94$$75)
					{
						ZEPHIR_INIT_NVAR(&sqlColumn);
						ZVAL_COPY(&sqlColumn, _94$$75);
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
								zephir_array_fetch_string(&_95$$80, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4061);
								if (ZEPHIR_IS_STRING(&_95$$80, "scalar")) {
									ZEPHIR_INIT_NVAR(&_96$$81);
									ZVAL_LONG(&_96$$81, position);
									ZEPHIR_INIT_NVAR(&_97$$81);
									ZEPHIR_CONCAT_SV(&_97$$81, "_", &_96$$81);
									zephir_array_update_zval(&sqlColumns, &_97$$81, &sqlColumn, PH_COPY | PH_SEPARATE);
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4064);
								}
							}
						}
						position++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_93$$75, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_98$$75, &_93$$75, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_98$$75)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&sqlColumn, &_93$$75, "current", NULL, 0);
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
									zephir_array_fetch_string(&_99$$87, &sqlColumn, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4061);
									if (ZEPHIR_IS_STRING(&_99$$87, "scalar")) {
										ZEPHIR_INIT_NVAR(&_100$$88);
										ZVAL_LONG(&_100$$88, position);
										ZEPHIR_INIT_NVAR(&_101$$88);
										ZEPHIR_CONCAT_SV(&_101$$88, "_", &_100$$88);
										zephir_array_update_zval(&sqlColumns, &_101$$88, &sqlColumn, PH_COPY | PH_SEPARATE);
									} else {
										zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4064);
									}
								}
							}
							position++;
						ZEPHIR_CALL_METHOD(NULL, &_93$$75, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&sqlColumn);
			ZEPHIR_CALL_METHOD(NULL, &selectColumns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&_102);
	zephir_read_property(&_102, this_ptr, ZEND_STRL("nestingLevel"), PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("sqlColumnAliases"), &_102, &sqlColumnAliases);
	ZEPHIR_INIT_VAR(&sqlSelect);
	zephir_create_array(&sqlSelect, 3, 0);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&distinct);
	if (zephir_array_isset_string_fetch(&distinct, &select, SL("distinct"), 0)) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(&sqlJoins)) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, ast, SL("where"), 0)) {
		ZEPHIR_CALL_METHOD(&_103$$92, this_ptr, "getexpression", NULL, 0, &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_103$$92, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&groupBy);
	if (zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_104$$93, this_ptr, "getgroupclause", NULL, 0, &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_104$$93, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&having);
	if (zephir_array_isset_string_fetch(&having, ast, SL("having"), 0)) {
		ZEPHIR_CALL_METHOD(&_105$$94, this_ptr, "getexpression", NULL, 0, &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_105$$94, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&order);
	if (zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0)) {
		ZEPHIR_CALL_METHOD(&_106$$95, this_ptr, "getorderclause", NULL, 0, &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_106$$95, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_107$$96, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_107$$96, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_value_string(ast, SL("forUpdate"))) {
		zephir_array_update_string(&sqlSelect, SL("forUpdate"), &__$true, PH_COPY | PH_SEPARATE);
	}
	if (merge) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &tempModels);
		zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &tempModelsInstances);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &tempSqlAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModels"), &tempSqlAliasesModels);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlModelsAliases"), &tempSqlModelsAliases);
		zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &tempSqlAliasesModelsInstances);
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("nestingLevel")));
	RETURN_CCTOR(&sqlSelect);
}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed
 * later
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate)
{
	zval _17$$20, _25$$21;
	zend_bool notQuoting = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModelsInstances, updateTables, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, _0, *_4, _8, *_12, _21, _1$$3, _2$$4, _3$$5, _6$$9, _7$$10, _10$$14, _11$$15, _13$$20, _14$$20, _15$$20, _18$$20, _19$$20, _20$$20, _22$$21, _23$$21, _24$$21, _26$$21, _27$$21, _28$$21, _29$$22, _30$$22, _31$$23;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_16 = NULL;
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
	ZVAL_UNDEF(&sqlFields);
	ZVAL_UNDEF(&sqlValues);
	ZVAL_UNDEF(&updateValues);
	ZVAL_UNDEF(&updateValue);
	ZVAL_UNDEF(&exprColumn);
	ZVAL_UNDEF(&sqlUpdate);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_25$$21);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("ast"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&update);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&update, &ast, SL("update"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 4150);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 4154);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&values);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&values, &update, SL("values"), 0)))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 4158);
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
		ZEPHIR_INIT_VAR(&updateTables);
		zephir_create_array(&updateTables, 1, 0);
		zephir_array_fast_append(&updateTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&updateTables, &tables);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(&updateTables, 0, "phalcon/Mvc/Model/Query.zep", 4224);
	if (Z_TYPE_P(&updateTables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateTables), _4)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _4);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4182);
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4183);
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_5, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_6$$9);
				zephir_create_array(&_6$$9, 2, 0);
				zephir_array_fast_append(&_6$$9, &source);
				zephir_array_fast_append(&_6$$9, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_6$$9);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$10);
				zephir_create_array(&_7$$10, 2, 0);
				zephir_array_fast_append(&_7$$10, &source);
				zephir_array_fast_append(&_7$$10, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_7$$10);
			}
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4206);
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4207);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4213);
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4217);
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &updateTables, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &updateTables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, &updateTables, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4182);
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4183);
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_9, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getschema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_10$$14);
					zephir_create_array(&_10$$14, 2, 0);
					zephir_array_fast_append(&_10$$14, &source);
					zephir_array_fast_append(&_10$$14, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_10$$14);
				} else {
					ZEPHIR_INIT_NVAR(&_11$$15);
					zephir_create_array(&_11$$15, 2, 0);
					zephir_array_fast_append(&_11$$15, &source);
					zephir_array_fast_append(&_11$$15, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_11$$15);
				}
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0)) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4206);
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4207);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4213);
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4217);
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &updateTables, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval(this_ptr, ZEND_STRL("models"), &models);
	zephir_update_property_zval(this_ptr, ZEND_STRL("modelsInstances"), &modelsInstances);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliases"), &sqlAliases);
	zephir_update_property_zval(this_ptr, ZEND_STRL("sqlAliasesModelsInstances"), &sqlAliasesModelsInstances);
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
	zephir_is_iterable(&updateValues, 0, "phalcon/Mvc/Model/Query.zep", 4248);
	if (Z_TYPE_P(&updateValues) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&updateValues), _12)
		{
			ZEPHIR_INIT_NVAR(&updateValue);
			ZVAL_COPY(&updateValue, _12);
			zephir_array_fetch_string(&_14$$20, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4240);
			if (notQuoting) {
				ZVAL_BOOL(&_15$$20, 1);
			} else {
				ZVAL_BOOL(&_15$$20, 0);
			}
			ZEPHIR_CALL_METHOD(&_13$$20, this_ptr, "getexpression", &_16, 0, &_14$$20, &_15$$20);
			zephir_check_call_status();
			zephir_array_append(&sqlFields, &_13$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4240);
			ZEPHIR_OBS_NVAR(&exprColumn);
			zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
			ZEPHIR_INIT_NVAR(&_17$$20);
			zephir_create_array(&_17$$20, 2, 0);
			ZEPHIR_OBS_NVAR(&_18$$20);
			zephir_array_fetch_string(&_18$$20, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4243);
			zephir_array_update_string(&_17$$20, SL("type"), &_18$$20, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_20$$20, 1);
			} else {
				ZVAL_BOOL(&_20$$20, 0);
			}
			ZEPHIR_CALL_METHOD(&_19$$20, this_ptr, "getexpression", &_16, 0, &exprColumn, &_20$$20);
			zephir_check_call_status();
			zephir_array_update_string(&_17$$20, SL("value"), &_19$$20, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlValues, &_17$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4245);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &updateValues, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_21, &updateValues, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&updateValue, &updateValues, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_string(&_23$$21, &updateValue, SL("column"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 4240);
				if (notQuoting) {
					ZVAL_BOOL(&_24$$21, 1);
				} else {
					ZVAL_BOOL(&_24$$21, 0);
				}
				ZEPHIR_CALL_METHOD(&_22$$21, this_ptr, "getexpression", &_16, 0, &_23$$21, &_24$$21);
				zephir_check_call_status();
				zephir_array_append(&sqlFields, &_22$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4240);
				ZEPHIR_OBS_NVAR(&exprColumn);
				zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
				ZEPHIR_INIT_NVAR(&_25$$21);
				zephir_create_array(&_25$$21, 2, 0);
				ZEPHIR_OBS_NVAR(&_26$$21);
				zephir_array_fetch_string(&_26$$21, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4243);
				zephir_array_update_string(&_25$$21, SL("type"), &_26$$21, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_28$$21, 1);
				} else {
					ZVAL_BOOL(&_28$$21, 0);
				}
				ZEPHIR_CALL_METHOD(&_27$$21, this_ptr, "getexpression", &_16, 0, &exprColumn, &_28$$21);
				zephir_check_call_status();
				zephir_array_update_string(&_25$$21, SL("value"), &_27$$21, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlValues, &_25$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4245);
			ZEPHIR_CALL_METHOD(NULL, &updateValues, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&updateValue);
	ZEPHIR_INIT_VAR(&sqlUpdate);
	zephir_create_array(&sqlUpdate, 4, 0);
	zephir_array_update_string(&sqlUpdate, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlUpdate, SL("values"), &sqlValues, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&where);
	if (zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0)) {
		ZVAL_BOOL(&_30$$22, 1);
		ZEPHIR_CALL_METHOD(&_29$$22, this_ptr, "getexpression", &_16, 0, &where, &_30$$22);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_29$$22, PH_COPY | PH_SEPARATE);
	}
	zephir_memory_observe(&limit);
	if (zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0)) {
		ZEPHIR_CALL_METHOD(&_31$$23, this_ptr, "getlimitclause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_31$$23, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&sqlUpdate);
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

