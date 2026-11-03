
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
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
 *
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_model_cache_options from MvcTypes
 * @phpstan-import-type mvc_query_ir from MvcTypes
 * @phpstan-import-type mvc_query_ast from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Query, phalcon, mvc_model_query, phalcon_mvc_model_query_method_entry, 0);

	/**
	 * @var array
	 * TODO: Add default value, instead of null, also remove type check
	 *
	 * @phpstan-var mvc_query_ast
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("ast"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @phpstan-var mvc_model_bind_params
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("bindParams"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @phpstan-var mvc_model_bind_types
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("bindTypes"), ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("cache"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 *
	 * @phpstan-var mvc_model_cache_options|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("cacheOptions"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("container"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Di\\DiInterface"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("enableImplicitJoins"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @var array
	 *
	 * @phpstan-var mvc_query_ir|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("intermediate"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 *
	 * @phpstan-var array<array-key, mvc_query_ir>|null
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
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("models"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, ModelInterface>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("modelsInstances"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, -1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("nestingLevel"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("phql"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("resultsetRowClass"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sharedLock"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sqlAliases"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sqlAliasesModels"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, ModelInterface>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sqlAliasesModelsInstances"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<int, array<string, bool>>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sqlColumnAliases"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var array<string, string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("sqlModelsAliases"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * TransactionInterface so that the query can wrap a transaction
	 * around batch updates and intermediate selects within the transaction.
	 * however if a model got a transaction set inside it will use the local
	 * transaction instead of this one
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("transaction"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Mvc\\Model\\TransactionInterface"));
	}

	/**
	 * @var int|null
	 */
	zend_declare_property_null(phalcon_mvc_model_query_ce, SL("type"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_mvc_model_query_ce, SL("uniqueRow"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

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
 *
 * @phpstan-param array<string, mixed> $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval phql_zv, *container = NULL, container_sub, *options_param = NULL, __$true, __$false, __$null, enableImplicitJoins, _3, _4, _1$$5, _2$$5;
	zend_string *phql = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql_zv);
	ZVAL_UNDEF(&container_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&enableImplicitJoins);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1072, &phql_zv);
	if (Z_TYPE_P(container) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setDI", NULL, 0, container);
		zephir_check_call_status();
	}
	zephir_memory_observe(&enableImplicitJoins);
	_0 = zephir_array_isset_string_fetch(&enableImplicitJoins, &options, SL("enable_implicit_joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		if (ZEPHIR_IS_TRUE(&enableImplicitJoins)) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1073, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1073, &__$false);
		}
	} else {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "orm.enable_implicit_joins");
		ZEPHIR_CALL_CE_STATIC(&_1$$5, phalcon_support_settings_ce, "get", NULL, 0, &_2$$5);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1073, &_1$$5);
	}
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1074, &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1075, &_4);
	ZEPHIR_MM_RESTORE();
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
 * Sets the cache parameters of the query
 *
 * @phpstan-param mvc_model_cache_options $cacheOptions
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1076, &cacheOptions);
	RETURN_THIS();
}

/**
 * Executes a parsed PHQL statement
 *
 * @return mixed
 *
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute)
{
	zend_bool _2$$3, _4$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bindParams_param = NULL, *bindTypes_param = NULL, adapter, cacheLifetime, cacheOptions, cacheService, defaultBindParams, defaultBindTypes, intermediate, mergedParams, mergedTypes, preparedResult, type, uniqueRow, cache, key, lifetime, result, _0, _1$$4, _5$$3, _6$$3, _7$$3, _10$$3, _3$$5, _8$$7, _11$$11, _12$$10, _13$$20, _14$$22;
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
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$20);
	ZVAL_UNDEF(&_14$$22);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1077, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uniqueRow, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1076, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cacheOptions, &_0);
	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (UNEXPECTED(Z_TYPE_P(&cacheOptions) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_model_query_exceptions_invalidcachingoptions_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Model/Query.zep", 352);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&key);
		_2$$3 = zephir_array_isset_string_fetch(&key, &cacheOptions, SL("key"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_2$$3))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_missingcachekey_ce);
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 359);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&cacheService);
		_4$$3 = zephir_array_isset_string_fetch(&cacheService, &cacheOptions, SL("service"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_4$$3)) {
			ZEPHIR_INIT_NVAR(&cacheService);
			ZVAL_STRING(&cacheService, "modelsCache");
		}
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_2, 1078, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&cache, &_5$$3, "getShared", NULL, 0, &cacheService);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Phalcon\\Cache\\CacheInterface");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "is_a", NULL, 203, &cache, &_6$$3);
		zephir_check_call_status();
		if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_mvc_model_query_exceptions_invalidquerycacheservice_ce);
			ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/Model/Query.zep", 369);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&adapter, &cache, "getAdapter", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&cacheLifetime, &adapter, "getLifetime", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&lifetime);
		_9$$3 = zephir_array_isset_string_fetch(&lifetime, &cacheOptions, SL("lifetime"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_9$$3)) {
			ZEPHIR_CPY_WRT(&lifetime, &cacheLifetime);
		}
		ZEPHIR_INIT_NVAR(&result);
		ZVAL_BOOL(&result, 0);
		ZEPHIR_CALL_METHOD(&_10$$3, &cache, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$3)) {
			ZEPHIR_CALL_METHOD(&result, &cache, "get", NULL, 0, &key);
			zephir_check_call_status();
		}
		if (!(ZEPHIR_IS_EMPTY(&result))) {
			if (UNEXPECTED(Z_TYPE_P(&result) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_11$$11);
				object_init_ex(&_11$$11, phalcon_mvc_model_query_exceptions_invalidcachedresultset_ce);
				ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model/Query.zep", 390);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_12$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &result, "setIsFresh", NULL, 0, &_12$$10);
			zephir_check_call_status();
			if (zephir_is_true(&uniqueRow)) {
				ZEPHIR_CALL_METHOD(&preparedResult, &result, "getFirst", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedResult, &result);
			}
			RETURN_CCTOR(&preparedResult);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1079, &cache);
	}
	ZEPHIR_CALL_METHOD(&intermediate, this_ptr, "parse", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&defaultBindParams);
	zephir_read_property_cached(&defaultBindParams, this_ptr, _zephir_prop_4, 1074, PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_add_function(&mergedParams, &defaultBindParams, &bindParams);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&defaultBindTypes);
	zephir_read_property_cached(&defaultBindTypes, this_ptr, _zephir_prop_5, 1075, PH_NOISY_CC);
	if (Z_TYPE_P(&defaultBindTypes) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&mergedTypes);
		zephir_add_function(&mergedTypes, &defaultBindTypes, &bindTypes);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CPY_WRT(&mergedTypes, &bindTypes);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 1080, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&type, &_0);
	if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_3; }
	goto zephir_switch_0_clause_4;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeSelect", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeInsert", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeUpdate", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		ZEPHIR_CALL_METHOD(&result, this_ptr, "executeDelete", NULL, 0, &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_13$$20);
		object_init_ex(&_13$$20, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
		ZEPHIR_CALL_METHOD(NULL, &_13$$20, "__construct", NULL, 0, &type);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$20, "phalcon/Mvc/Model/Query.zep", 473);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_INIT_VAR(&_14$$22);
			object_init_ex(&_14$$22, phalcon_mvc_model_query_exceptions_resultsetnoncacheable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_14$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$22, "phalcon/Mvc/Model/Query.zep", 484);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, &cache, "set", NULL, 0, &key, &result, &lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(&uniqueRow)) {
		ZEPHIR_CALL_METHOD(&preparedResult, &result, "getFirst", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedResult, &result);
	}
	RETURN_CCTOR(&preparedResult);
}

/**
 * Returns default bind params
 *
 * @phpstan-return mvc_model_bind_params
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams)
{

	RETURN_MEMBER_TYPED(getThis(), "bindParams", IS_ARRAY);
}

/**
 * Returns default bind types
 *
 * @phpstan-return mvc_model_bind_types
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
 *
 * @phpstan-return mvc_model_cache_options
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
 *
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate)
{

	RETURN_MEMBER_TYPED(getThis(), "intermediate", IS_ARRAY);
}

/**
 * Executes the query returning the first result
 *
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1077, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &bindParams, &bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getFirst", NULL, 0);
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
 *
 * @phpstan-return array<string, mixed>
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1080, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 309)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1074, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_2, 1075, PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "executeSelect", NULL, 0, &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_mvc_model_query_exceptions_multiplesqlstatementsnotsupported_ce);
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "phalcon/Mvc/Model/Query.zep", 609);
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
 *
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse)
{
	zend_bool _1$$4, _5$$4, _3$$5;
	zval intermediate, phql, ast, irPhql, uniqueId, type, _0, _2$$5, _4$$7, _6$$13, _7$$14;
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
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$14);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1081, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&intermediate, &_0);
	if (Z_TYPE_P(&intermediate) == IS_ARRAY) {
		RETURN_CCTOR(&intermediate);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&phql, &_0);
	ZEPHIR_CALL_CE_STATIC(&ast, phalcon_mvc_model_query_lang_ce, "parsePHQL", NULL, 0, &phql);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&irPhql);
	ZVAL_NULL(&irPhql);
	ZEPHIR_INIT_VAR(&uniqueId);
	ZVAL_NULL(&uniqueId);
	if (Z_TYPE_P(&ast) == IS_ARRAY) {
		ZEPHIR_OBS_NVAR(&uniqueId);
		_1$$4 = zephir_array_isset_string_fetch(&uniqueId, &ast, SL("id"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$4) {
			ZEPHIR_OBS_NVAR(&irPhql);
			zephir_read_static_property_ce(&_2$$5, phalcon_mvc_model_query_ce, SL("internalPhqlCache"), PH_NOISY_CC | PH_READONLY);
			_3$$5 = zephir_array_isset_fetch(&irPhql, &_2$$5, &uniqueId, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_3$$5) {
				if (Z_TYPE_P(&irPhql) == IS_ARRAY) {
					zephir_memory_observe(&_4$$7);
					zephir_array_fetch_string(&_4$$7, &ast, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 684);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &_4$$7);
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "refreshSchemasInIntermediate", NULL, 0, &irPhql);
					zephir_check_call_status();
					RETURN_MM();
				}
			}
		}
		zephir_memory_observe(&type);
		_5$$4 = zephir_array_isset_string_fetch(&type, &ast, SL("type"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_5$$4) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1082, &ast);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1080, &type);
			if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_3; }
			goto zephir_switch_0_clause_4;
			zephir_switch_0_clause_0: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareSelect", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareInsert", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareUpdate", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_CALL_METHOD(&irPhql, this_ptr, "prepareDelete", NULL, 0);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_VAR(&_6$$13);
				object_init_ex(&_6$$13, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$13, "__construct", NULL, 0, &type, &phql);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$13, "phalcon/Mvc/Model/Query.zep", 724);
				ZEPHIR_MM_RESTORE();
				return;
			zephir_switch_0_end: ;

		}
	}
	if (UNEXPECTED(Z_TYPE_P(&irPhql) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_7$$14);
		object_init_ex(&_7$$14, phalcon_mvc_model_query_exceptions_corruptedast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_7$$14, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$14, "phalcon/Mvc/Model/Query.zep", 730);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_ce(phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &irPhql, SL("z"), 1, &uniqueId);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1081, &irPhql);
	RETURN_CCTOR(&irPhql);
}

/**
 * Set default bind parameters
 *
 * @phpstan-param mvc_model_bind_params $bindParams
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
		zephir_read_property_cached(&currentBindParams, this_ptr, _zephir_prop_0, 1074, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_add_function(&_0$$3, &currentBindParams, &bindParams);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1074, &_0$$3);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1074, &bindParams);
	}
	RETURN_THIS();
}

/**
 * Set default bind parameters
 *
 * @phpstan-param mvc_model_bind_types $bindTypes
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
		zephir_read_property_cached(&currentBindTypes, this_ptr, _zephir_prop_0, 1075, PH_NOISY_CC);
		if (Z_TYPE_P(&currentBindTypes) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_add_function(&_0$$4, &currentBindTypes, &bindTypes);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1075, &_0$$4);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1075, &bindTypes);
		}
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1075, &bindTypes);
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
	ZEPHIR_CALL_METHOD(&manager, container, "getShared", NULL, 0, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_invalidinjectedmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 798);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD(&metaData, container, "getShared", NULL, 0, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_invalidinjectedmetadata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Mvc/Model/Query.zep", 804);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1083, &manager);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1084, &metaData);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1078, container);
	ZEPHIR_MM_RESTORE();
}

/**
 * Allows to set the IR to be executed
 *
 * @phpstan-param mvc_query_ir $intermediate
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1081, &intermediate);
	RETURN_THIS();
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 833);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\Row");
	ZEPHIR_CALL_FUNCTION(&_2, "is_subclass_of", NULL, 149, &resultsetRowClass_zv, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_mvc_model_query_exceptions_invalidresultsetrowclass_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 0, &resultsetRowClass_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Mvc/Model/Query.zep", 837);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1085, &resultsetRowClass_zv);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1086, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1086, &__$false);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1087, transaction);
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1080, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uniqueRow", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(uniqueRow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &uniqueRow_param);
	if (uniqueRow) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1077, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1077, &__$false);
	}
	RETURN_THISW();
}

/**
 * Executes the DELETE intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 *
 * @phpstan-param mvc_query_ir $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeDelete)
{
	zend_bool _0, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, records, connection, record, exception, _2, _7, _15, _1$$3, _4$$4, _5$$5, _9$$7, _11$$8, _13$$6;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$6);
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
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 898);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_0 = zephir_array_isset_value_long(&models, 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_deletemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 901);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 904);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1088, PH_NOISY_CC | PH_READONLY);
	_3 = zephir_array_isset_fetch(&model, &_2, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_4$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getRelatedRecords", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_5$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 0, &_5$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_7, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&record, &records, "current", &_8, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_9$$7, &record, "delete", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_9$$7))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_10, 0);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_11$$8, 0);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 0, &_11$$8, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &records, "next", &_12, 0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_OBJ(&_13$$6, EG(exception));
			Z_ADDREF_P(&_13$$6);
			if (zephir_is_instance_of(&_13$$6, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_13$$6);
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_14, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 963);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_15, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_6, 0, &_15);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the INSERT intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 *
 * @phpstan-param mvc_query_ir $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeInsert)
{
	zend_string *_11;
	zend_ulong _10;
	zend_bool automaticFields = 0, _1, _3, _29, _24$$8, _18$$11, _25$$14, _41$$17, _36$$20, _42$$23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_15 = NULL, *_20 = NULL, *_22 = NULL, *_23 = NULL, *_27 = NULL, *_31 = NULL, *_33 = NULL, *_38 = NULL, *_40 = NULL, *_44 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, attributeName, attributes, connection, dialect, exprValue, fieldName, fields, insertModel, insertValue, insertValues, manager, metaData, model, modelName, number, value, values, wildcard, columnMap, _0, _2, *_7, _8, *_9, _28, _45, _4$$4, _5$$4, _6$$7, _12$$8, _14$$11, _16$$11, _17$$11, _19$$12, _21$$13, _26$$15, _30$$17, _32$$20, _34$$20, _35$$20, _37$$21, _39$$22, _43$$24;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_43$$24);
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
	zephir_array_fetch_string(&modelName, &intermediate, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 994);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1088, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_fetch(&model, &_0, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", NULL, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_2);
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getAttributes", NULL, 0, &model);
	zephir_check_call_status();
	automaticFields = 0;
	zephir_memory_observe(&fields);
	_3 = zephir_array_isset_string_fetch(&fields, &intermediate, SL("fields"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		automaticFields = 1;
		ZEPHIR_CPY_WRT(&fields, &attributes);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_4$$4, phalcon_support_settings_ce, "get", NULL, 0, &_5$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
	}
	zephir_memory_observe(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1029);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(zephir_fast_count_int(&fields) != zephir_fast_count_int(&values))) {
		ZEPHIR_INIT_VAR(&_6$$7);
		object_init_ex(&_6$$7, phalcon_mvc_model_query_exceptions_insertcolumncountmismatch_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model/Query.zep", 1036);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getDialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&insertValues);
	array_init(&insertValues);
	if (Z_TYPE_P(&values) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_8);
		zephir_string_to_char_array(&_8, &values);
		_7 = &_8;
	} else {
		_7 = &values;
	}
	zephir_is_iterable(_7, 0, "phalcon/Mvc/Model/Query.zep", 1103);
	if (Z_TYPE_P(_7) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_7), _10, _11, _9)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_11 != NULL) { 
				ZVAL_STR_COPY(&number, _11);
			} else {
				ZVAL_LONG(&number, _10);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _9);
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1046);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_12$$8);
			zephir_array_fetch_string(&_12$$8, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1048);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&_12$$8, 260)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_12$$8, 258)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_12$$8, 259)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_12$$8, 322)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&_12$$8, 273)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&_12$$8, 274)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&_12$$8, 277)) { goto zephir_switch_0_clause_6; }
			goto zephir_switch_0_clause_7;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getSqlExpression", &_13, 0, &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				ZVAL_NULL(&insertValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD(&_14$$11, &dialect, "getSqlExpression", &_15, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_STRING(&_16$$11, ":");
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZVAL_STRING(&_17$$11, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_16$$11, &_17$$11, &_14$$11);
				ZEPHIR_OBS_NVAR(&insertValue);
				_18$$11 = zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_18$$11))) {
					ZEPHIR_INIT_NVAR(&_19$$12);
					object_init_ex(&_19$$12, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$12, "__construct", &_20, 0, &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$12, "phalcon/Mvc/Model/Query.zep", 1070);
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(&_21$$13, &dialect, "getSqlExpression", &_22, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_23, 62, &_21$$13);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1083);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_24$$8 = automaticFields;
			if (_24$$8) {
				_24$$8 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			}
			if (_24$$8) {
				ZEPHIR_OBS_NVAR(&attributeName);
				_25$$14 = zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_25$$14))) {
					ZEPHIR_INIT_NVAR(&_26$$15);
					object_init_ex(&_26$$15, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
					ZEPHIR_CALL_METHOD(NULL, &_26$$15, "__construct", &_27, 0, &fieldName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_26$$15, "phalcon/Mvc/Model/Query.zep", 1091);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeName, &fieldName);
			}
			zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _7, "rewind", NULL, 0);
		zephir_check_call_status();
		_29 = 1;
		while (1) {
			if (_29) {
				_29 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _7, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_28, _7, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_28)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, _7, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, _7, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1046);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_30$$17);
				zephir_array_fetch_string(&_30$$17, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1048);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_30$$17, 260)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_30$$17, 258)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_30$$17, 259)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_30$$17, 322)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_30$$17, 273)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_30$$17, 274)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_30$$17, 277)) { goto zephir_switch_1_clause_6; }
				goto zephir_switch_1_clause_7;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD(&insertValue, &dialect, "getSqlExpression", &_31, 0, &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					ZVAL_NULL(&insertValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD(&_32$$20, &dialect, "getSqlExpression", &_33, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_34$$20);
					ZVAL_STRING(&_34$$20, ":");
					ZEPHIR_INIT_NVAR(&_35$$20);
					ZVAL_STRING(&_35$$20, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_34$$20, &_35$$20, &_32$$20);
					ZEPHIR_OBS_NVAR(&insertValue);
					_36$$20 = zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_36$$20))) {
						ZEPHIR_INIT_NVAR(&_37$$21);
						object_init_ex(&_37$$21, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_37$$21, "__construct", &_38, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_37$$21, "phalcon/Mvc/Model/Query.zep", 1070);
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(&_39$$22, &dialect, "getSqlExpression", &_40, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &insertValue, "__construct", &_23, 62, &_39$$22);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1083);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_41$$17 = automaticFields;
				if (_41$$17) {
					_41$$17 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				}
				if (_41$$17) {
					ZEPHIR_OBS_NVAR(&attributeName);
					_42$$23 = zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_42$$23))) {
						ZEPHIR_INIT_NVAR(&_43$$24);
						object_init_ex(&_43$$24, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
						ZEPHIR_CALL_METHOD(NULL, &_43$$24, "__construct", &_44, 0, &fieldName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_43$$24, "phalcon/Mvc/Model/Query.zep", 1091);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeName, &fieldName);
				}
				zephir_array_update_zval(&insertValues, &attributeName, &insertValue, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&insertModel, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &insertModel, "assign", NULL, 0, &insertValues);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD(&_45, &insertModel, "create", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_45, &insertModel);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the SELECT intermediate representation producing a
 * Phalcon\Mvc\Model\Resultset
 *
 * @phpstan-param mvc_query_ir $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 * @phpstan-return array<array-key, mixed>|ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeSelect)
{
	zval _133$$87, _148$$88;
	zend_string *_43, *_109, *_116, *_126, *_177$$104;
	zend_ulong _42, _108, _115, _125, _176$$104;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_11 = NULL, *_14 = NULL, *_19 = NULL, *_25 = NULL, *_30 = NULL, *_36 = NULL, *_47 = NULL, *_48 = NULL, *_50 = NULL, *_52 = NULL, *_62 = NULL, *_80 = NULL, *_81 = NULL, *_84 = NULL, *_94 = NULL, *_140 = NULL, *_144 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isKeepingSnapshots = 0, isSimpleStd, _16, _34, _76, _112, _119, _146, _5$$3, _7$$3, _8$$3, _18$$9, _20$$9, _21$$9, _32$$17, _38$$22, _73$$32, _46$$33, _58$$35, _69$$41, _74$$47, _105$$50, _79$$51, _90$$53, _101$$59, _106$$65, _127$$84, _170$$101, _181$$104, _185$$92;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *simulate_param = NULL, __$true, __$null, aliasCopy, attribute, attributes, bindCounts, cache, column, columnAlias, columnMap, columns, columns1, connectionTypes, dialect, instance, manager, metaData, modelName, models, processed, processedTypes, result, resultData, resultObject, resultsetClassName, selectColumns, simpleColumnMap, sqlAlias, sqlColumn, sqlSelect, typeWildcard, typesColumnMap, value, wildcard, wildcardValue, connection, model, _0, *_1, _2, *_3, _15, *_26, _27, *_28, _33, *_39, _40, *_41, _75, *_107, _111, *_114, _118, rawWildcards, rawValue, placeholder, *_122, _123, *_124, *_129, _130, *_131, _145, _158, _4$$3, _9$$3, _12$$7, _13$$8, _17$$9, _22$$9, _23$$13, _24$$14, _29$$16, _31$$15, _35$$21, _37$$20, _44$$32, _45$$33, _49$$35, _51$$35, *_53$$35, *_54$$35, _57$$35, _61$$35, _56$$38, _60$$39, _63$$40, *_64$$41, _65$$41, *_66$$41, _68$$41, _71$$45, _72$$46, _77$$50, _78$$51, _82$$53, _83$$53, *_85$$53, *_86$$53, _89$$53, _93$$53, _88$$56, _92$$57, _95$$58, *_96$$59, _97$$59, *_98$$59, _100$$59, _103$$63, _104$$64, _110$$71, _113$$75, _117$$77, _120$$80, _121$$83, _128$$86, _132$$87, _134$$87, _135$$87, _136$$87, _137$$87, _138$$87, _139$$87, _141$$87, _142$$87, _143$$87, _147$$88, _149$$88, _150$$88, _151$$88, _152$$88, _153$$88, _154$$88, _155$$88, _156$$88, _157$$88, _159$$93, _160$$94, _161$$96, _162$$96, _184$$96, _163$$101, *_164$$101, _165$$101, *_166$$101, _169$$101, _168$$102, _172$$103, *_173$$104, _174$$104, *_175$$104, _180$$104, _179$$105, _183$$106, _191$$92, _186$$109, _187$$108, _188$$108, _189$$110;
	zval intermediate, bindParams, bindTypes, _55$$38, _59$$39, _67$$42, _70$$43, _87$$56, _91$$57, _99$$60, _102$$61, _167$$102, _171$$103, _178$$105, _182$$106, _190$$108;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_55$$38);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_67$$42);
	ZVAL_UNDEF(&_70$$43);
	ZVAL_UNDEF(&_87$$56);
	ZVAL_UNDEF(&_91$$57);
	ZVAL_UNDEF(&_99$$60);
	ZVAL_UNDEF(&_102$$61);
	ZVAL_UNDEF(&_167$$102);
	ZVAL_UNDEF(&_171$$103);
	ZVAL_UNDEF(&_178$$105);
	ZVAL_UNDEF(&_182$$106);
	ZVAL_UNDEF(&_190$$108);
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&rawWildcards);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&_123);
	ZVAL_UNDEF(&_130);
	ZVAL_UNDEF(&_145);
	ZVAL_UNDEF(&_158);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_31$$15);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_44$$32);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&_49$$35);
	ZVAL_UNDEF(&_51$$35);
	ZVAL_UNDEF(&_57$$35);
	ZVAL_UNDEF(&_61$$35);
	ZVAL_UNDEF(&_56$$38);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&_63$$40);
	ZVAL_UNDEF(&_65$$41);
	ZVAL_UNDEF(&_68$$41);
	ZVAL_UNDEF(&_71$$45);
	ZVAL_UNDEF(&_72$$46);
	ZVAL_UNDEF(&_77$$50);
	ZVAL_UNDEF(&_78$$51);
	ZVAL_UNDEF(&_82$$53);
	ZVAL_UNDEF(&_83$$53);
	ZVAL_UNDEF(&_89$$53);
	ZVAL_UNDEF(&_93$$53);
	ZVAL_UNDEF(&_88$$56);
	ZVAL_UNDEF(&_92$$57);
	ZVAL_UNDEF(&_95$$58);
	ZVAL_UNDEF(&_97$$59);
	ZVAL_UNDEF(&_100$$59);
	ZVAL_UNDEF(&_103$$63);
	ZVAL_UNDEF(&_104$$64);
	ZVAL_UNDEF(&_110$$71);
	ZVAL_UNDEF(&_113$$75);
	ZVAL_UNDEF(&_117$$77);
	ZVAL_UNDEF(&_120$$80);
	ZVAL_UNDEF(&_121$$83);
	ZVAL_UNDEF(&_128$$86);
	ZVAL_UNDEF(&_132$$87);
	ZVAL_UNDEF(&_134$$87);
	ZVAL_UNDEF(&_135$$87);
	ZVAL_UNDEF(&_136$$87);
	ZVAL_UNDEF(&_137$$87);
	ZVAL_UNDEF(&_138$$87);
	ZVAL_UNDEF(&_139$$87);
	ZVAL_UNDEF(&_141$$87);
	ZVAL_UNDEF(&_142$$87);
	ZVAL_UNDEF(&_143$$87);
	ZVAL_UNDEF(&_147$$88);
	ZVAL_UNDEF(&_149$$88);
	ZVAL_UNDEF(&_150$$88);
	ZVAL_UNDEF(&_151$$88);
	ZVAL_UNDEF(&_152$$88);
	ZVAL_UNDEF(&_153$$88);
	ZVAL_UNDEF(&_154$$88);
	ZVAL_UNDEF(&_155$$88);
	ZVAL_UNDEF(&_156$$88);
	ZVAL_UNDEF(&_157$$88);
	ZVAL_UNDEF(&_159$$93);
	ZVAL_UNDEF(&_160$$94);
	ZVAL_UNDEF(&_161$$96);
	ZVAL_UNDEF(&_162$$96);
	ZVAL_UNDEF(&_184$$96);
	ZVAL_UNDEF(&_163$$101);
	ZVAL_UNDEF(&_165$$101);
	ZVAL_UNDEF(&_169$$101);
	ZVAL_UNDEF(&_168$$102);
	ZVAL_UNDEF(&_172$$103);
	ZVAL_UNDEF(&_174$$104);
	ZVAL_UNDEF(&_180$$104);
	ZVAL_UNDEF(&_179$$105);
	ZVAL_UNDEF(&_183$$106);
	ZVAL_UNDEF(&_191$$92);
	ZVAL_UNDEF(&_186$$109);
	ZVAL_UNDEF(&_187$$108);
	ZVAL_UNDEF(&_188$$108);
	ZVAL_UNDEF(&_189$$110);
	ZVAL_UNDEF(&_133$$87);
	ZVAL_UNDEF(&_148$$88);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&connectionTypes);
	array_init(&connectionTypes);
	zephir_memory_observe(&models);
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1146);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&models) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &models);
		_1 = &_2;
	} else {
		_1 = &models;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 1181);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _3);
			ZEPHIR_OBS_NVAR(&model);
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 1088, PH_NOISY_CC | PH_READONLY);
			_5$$3 = zephir_array_isset_fetch(&model, &_4$$3, &modelName, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_5$$3)) {
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_6, 0, &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_7$$3 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_8$$3 = _7$$3;
			if (_8$$3) {
				ZEPHIR_OBS_NVAR(&_9$$3);
				zephir_array_fetch_string(&_9$$3, &intermediate, SL("forUpdate"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1155);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_8$$3 = zephir_is_true(&_9$$3);
			}
			if (_8$$3) {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", &_10, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&connection, this_ptr, "getReadConnection", &_11, 0, &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&connection) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_12$$7, &connection, "getType", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&connectionTypes, &_12$$7, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					object_init_ex(&_13$$8, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
					ZEPHIR_CALL_METHOD(NULL, &_13$$8, "__construct", &_14, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$8, "phalcon/Mvc/Model/Query.zep", 1176);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&modelName, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&model);
				zephir_read_property_cached(&_17$$9, this_ptr, _zephir_prop_1, 1088, PH_NOISY_CC | PH_READONLY);
				_18$$9 = zephir_array_isset_fetch(&model, &_17$$9, &modelName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_18$$9)) {
					ZEPHIR_CALL_METHOD(&model, &manager, "load", &_19, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_20$$9 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_21$$9 = _20$$9;
				if (_21$$9) {
					ZEPHIR_OBS_NVAR(&_22$$9);
					zephir_array_fetch_string(&_22$$9, &intermediate, SL("forUpdate"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1155);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_21$$9 = zephir_is_true(&_22$$9);
				}
				if (_21$$9) {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", &_10, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(&connection, this_ptr, "getReadConnection", &_11, 0, &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&connection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_23$$13, &connection, "getType", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&connectionTypes, &_23$$13, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
						ZEPHIR_INIT_NVAR(&_24$$14);
						object_init_ex(&_24$$14, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
						ZEPHIR_CALL_METHOD(NULL, &_24$$14, "__construct", &_25, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_24$$14, "phalcon/Mvc/Model/Query.zep", 1176);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	zephir_memory_observe(&columns);
	zephir_array_fetch_string(&columns, &intermediate, SL("columns"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1181);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	haveObjects = 0;
	haveScalars = 0;
	isComplex = 0;
	numberObjects = 0;
	ZEPHIR_CPY_WRT(&columns1, &columns);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_27);
		zephir_string_to_char_array(&_27, &columns);
		_26 = &_27;
	} else {
		_26 = &columns;
	}
	zephir_is_iterable(_26, 0, "phalcon/Mvc/Model/Query.zep", 1209);
	if (Z_TYPE_P(_26) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26), _28)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _28);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_29$$16);
				object_init_ex(&_29$$16, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
				ZEPHIR_CALL_METHOD(NULL, &_29$$16, "__construct", &_30, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_29$$16, "phalcon/Mvc/Model/Query.zep", 1193);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_31$$15);
			zephir_array_fetch_string(&_31$$15, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1196);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_31$$15, "scalar")) {
				_32$$17 = zephir_array_isset_value_string(&column, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_32$$17)) {
					isComplex = 1;
				}
				haveScalars = 1;
			} else {
				haveObjects = 1;
				numberObjects++;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _26, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _26, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, _26, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, _26, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_35$$21);
					object_init_ex(&_35$$21, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
					ZEPHIR_CALL_METHOD(NULL, &_35$$21, "__construct", &_36, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_35$$21, "phalcon/Mvc/Model/Query.zep", 1193);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_37$$20);
				zephir_array_fetch_string(&_37$$20, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1196);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_37$$20, "scalar")) {
					_38$$22 = zephir_array_isset_value_string(&column, SL("balias"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_38$$22)) {
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_40);
		zephir_string_to_char_array(&_40, &columns);
		_39 = &_40;
	} else {
		_39 = &columns;
	}
	zephir_is_iterable(_39, 0, "phalcon/Mvc/Model/Query.zep", 1315);
	if (Z_TYPE_P(_39) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_39), _42, _43, _41)
		{
			ZEPHIR_INIT_NVAR(&aliasCopy);
			if (_43 != NULL) { 
				ZVAL_STR_COPY(&aliasCopy, _43);
			} else {
				ZVAL_LONG(&aliasCopy, _42);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _41);
			ZEPHIR_OBS_NVAR(&sqlColumn);
			zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1232);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_44$$32);
			zephir_array_fetch_string(&_44$$32, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1235);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_44$$32, "object")) {
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1236);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&instance);
				zephir_read_property_cached(&_45$$33, this_ptr, _zephir_prop_1, 1088, PH_NOISY_CC | PH_READONLY);
				_46$$33 = zephir_array_isset_fetch(&instance, &_45$$33, &modelName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_46$$33)) {
					ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_47, 0, &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD(&attributes, &metaData, "getAttributes", &_48, 0, &instance);
				zephir_check_call_status();
				if (isComplex) {
					ZEPHIR_INIT_NVAR(&_51$$35);
					ZVAL_STRING(&_51$$35, "orm.column_renaming");
					ZEPHIR_CALL_CE_STATIC(&_49$$35, phalcon_support_settings_ce, "get", &_50, 0, &_51$$35);
					zephir_check_call_status();
					if (zephir_is_true(&_49$$35)) {
						ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", &_52, 0, &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&columnMap);
						ZVAL_NULL(&columnMap);
					}
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_51$$35);
						zephir_string_to_char_array(&_51$$35, &attributes);
						_53$$35 = &_51$$35;
					} else {
						_53$$35 = &attributes;
					}
					zephir_is_iterable(_53$$35, 0, "phalcon/Mvc/Model/Query.zep", 1272);
					if (Z_TYPE_P(_53$$35) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_53$$35), _54$$35)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _54$$35);
							ZEPHIR_INIT_NVAR(&_55$$38);
							zephir_create_array(&_55$$38, 3, 0);
							zephir_array_fast_append(&_55$$38, &attribute);
							zephir_array_fast_append(&_55$$38, &sqlColumn);
							ZEPHIR_INIT_NVAR(&_56$$38);
							ZEPHIR_CONCAT_SVSV(&_56$$38, "_", &sqlColumn, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_55$$38, &_56$$38);
							zephir_array_append(&selectColumns, &_55$$38, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _53$$35, "rewind", NULL, 0);
						zephir_check_call_status();
						_58$$35 = 1;
						while (1) {
							if (_58$$35) {
								_58$$35 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _53$$35, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_57$$35, _53$$35, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_57$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _53$$35, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_59$$39);
								zephir_create_array(&_59$$39, 3, 0);
								zephir_array_fast_append(&_59$$39, &attribute);
								zephir_array_fast_append(&_59$$39, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_60$$39);
								ZEPHIR_CONCAT_SVSV(&_60$$39, "_", &sqlColumn, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_59$$39, &_60$$39);
								zephir_array_append(&selectColumns, &_59$$39, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_61$$35, &manager, "isKeepingSnapshots", &_62, 0, &instance);
					zephir_check_call_status();
					isKeepingSnapshots = zephir_get_boolval(&_61$$35);
					if (isKeepingSnapshots) {
						ZEPHIR_INIT_NVAR(&_63$$40);
						ZVAL_BOOL(&_63$$40, isKeepingSnapshots);
						zephir_array_update_multi(&columns1, &_63$$40, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_65$$41);
						zephir_string_to_char_array(&_65$$41, &attributes);
						_64$$41 = &_65$$41;
					} else {
						_64$$41 = &attributes;
					}
					zephir_is_iterable(_64$$41, 0, "phalcon/Mvc/Model/Query.zep", 1289);
					if (Z_TYPE_P(_64$$41) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_64$$41), _66$$41)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _66$$41);
							ZEPHIR_INIT_NVAR(&_67$$42);
							zephir_create_array(&_67$$42, 2, 0);
							zephir_array_fast_append(&_67$$42, &attribute);
							zephir_array_fast_append(&_67$$42, &sqlColumn);
							zephir_array_append(&selectColumns, &_67$$42, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _64$$41, "rewind", NULL, 0);
						zephir_check_call_status();
						_69$$41 = 1;
						while (1) {
							if (_69$$41) {
								_69$$41 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _64$$41, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_68$$41, _64$$41, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_68$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _64$$41, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_70$$43);
								zephir_create_array(&_70$$43, 2, 0);
								zephir_array_fast_append(&_70$$43, &attribute);
								zephir_array_fast_append(&_70$$43, &sqlColumn);
								zephir_array_append(&selectColumns, &_70$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				}
			} else {
				ZEPHIR_INIT_NVAR(&columnAlias);
				if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_71$$45);
					zephir_create_array(&_71$$45, 2, 0);
					zephir_array_fast_append(&_71$$45, &sqlColumn);
					zephir_array_fast_append(&_71$$45, &__$null);
					ZEPHIR_CPY_WRT(&columnAlias, &_71$$45);
				} else {
					ZEPHIR_INIT_NVAR(&_72$$46);
					zephir_create_array(&_72$$46, 3, 0);
					zephir_array_fast_append(&_72$$46, &sqlColumn);
					zephir_array_fast_append(&_72$$46, &__$null);
					zephir_array_fast_append(&_72$$46, &aliasCopy);
					ZEPHIR_CPY_WRT(&columnAlias, &_72$$46);
				}
				zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1300);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_73$$32 = !isComplex;
			if (_73$$32) {
				_73$$32 = isSimpleStd;
			}
			if (_73$$32) {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				_74$$47 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_74$$47) {
					zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _39, "rewind", NULL, 0);
		zephir_check_call_status();
		_76 = 1;
		while (1) {
			if (_76) {
				_76 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _39, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_75, _39, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_75)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&aliasCopy, _39, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, _39, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sqlColumn);
				zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1232);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_77$$50);
				zephir_array_fetch_string(&_77$$50, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1235);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_77$$50, "object")) {
					ZEPHIR_OBS_NVAR(&modelName);
					zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1236);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&instance);
					zephir_read_property_cached(&_78$$51, this_ptr, _zephir_prop_1, 1088, PH_NOISY_CC | PH_READONLY);
					_79$$51 = zephir_array_isset_fetch(&instance, &_78$$51, &modelName, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_79$$51)) {
						ZEPHIR_CALL_METHOD(&instance, &manager, "load", &_80, 0, &modelName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD(&attributes, &metaData, "getAttributes", &_81, 0, &instance);
					zephir_check_call_status();
					if (isComplex) {
						ZEPHIR_INIT_NVAR(&_83$$53);
						ZVAL_STRING(&_83$$53, "orm.column_renaming");
						ZEPHIR_CALL_CE_STATIC(&_82$$53, phalcon_support_settings_ce, "get", &_50, 0, &_83$$53);
						zephir_check_call_status();
						if (zephir_is_true(&_82$$53)) {
							ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", &_84, 0, &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&columnMap);
							ZVAL_NULL(&columnMap);
						}
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_83$$53);
							zephir_string_to_char_array(&_83$$53, &attributes);
							_85$$53 = &_83$$53;
						} else {
							_85$$53 = &attributes;
						}
						zephir_is_iterable(_85$$53, 0, "phalcon/Mvc/Model/Query.zep", 1272);
						if (Z_TYPE_P(_85$$53) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_85$$53), _86$$53)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _86$$53);
								ZEPHIR_INIT_NVAR(&_87$$56);
								zephir_create_array(&_87$$56, 3, 0);
								zephir_array_fast_append(&_87$$56, &attribute);
								zephir_array_fast_append(&_87$$56, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_88$$56);
								ZEPHIR_CONCAT_SVSV(&_88$$56, "_", &sqlColumn, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_87$$56, &_88$$56);
								zephir_array_append(&selectColumns, &_87$$56, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _85$$53, "rewind", NULL, 0);
							zephir_check_call_status();
							_90$$53 = 1;
							while (1) {
								if (_90$$53) {
									_90$$53 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _85$$53, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_89$$53, _85$$53, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_89$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, _85$$53, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_91$$57);
									zephir_create_array(&_91$$57, 3, 0);
									zephir_array_fast_append(&_91$$57, &attribute);
									zephir_array_fast_append(&_91$$57, &sqlColumn);
									ZEPHIR_INIT_NVAR(&_92$$57);
									ZEPHIR_CONCAT_SVSV(&_92$$57, "_", &sqlColumn, "_", &attribute);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_fast_append(&_91$$57, &_92$$57);
									zephir_array_append(&selectColumns, &_91$$57, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_array_update_multi(&columns1, &instance, SL("zs"), 3, &aliasCopy, SL("instance"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&columns1, &attributes, SL("zs"), 3, &aliasCopy, SL("attributes"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_multi(&columns1, &columnMap, SL("zs"), 3, &aliasCopy, SL("columnMap"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_93$$53, &manager, "isKeepingSnapshots", &_94, 0, &instance);
						zephir_check_call_status();
						isKeepingSnapshots = zephir_get_boolval(&_93$$53);
						if (isKeepingSnapshots) {
							ZEPHIR_INIT_NVAR(&_95$$58);
							ZVAL_BOOL(&_95$$58, isKeepingSnapshots);
							zephir_array_update_multi(&columns1, &_95$$58, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_97$$59);
							zephir_string_to_char_array(&_97$$59, &attributes);
							_96$$59 = &_97$$59;
						} else {
							_96$$59 = &attributes;
						}
						zephir_is_iterable(_96$$59, 0, "phalcon/Mvc/Model/Query.zep", 1289);
						if (Z_TYPE_P(_96$$59) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_96$$59), _98$$59)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _98$$59);
								ZEPHIR_INIT_NVAR(&_99$$60);
								zephir_create_array(&_99$$60, 2, 0);
								zephir_array_fast_append(&_99$$60, &attribute);
								zephir_array_fast_append(&_99$$60, &sqlColumn);
								zephir_array_append(&selectColumns, &_99$$60, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _96$$59, "rewind", NULL, 0);
							zephir_check_call_status();
							_101$$59 = 1;
							while (1) {
								if (_101$$59) {
									_101$$59 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _96$$59, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_100$$59, _96$$59, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_100$$59)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&attribute, _96$$59, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_102$$61);
									zephir_create_array(&_102$$61, 2, 0);
									zephir_array_fast_append(&_102$$61, &attribute);
									zephir_array_fast_append(&_102$$61, &sqlColumn);
									zephir_array_append(&selectColumns, &_102$$61, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
							}
						}
						ZEPHIR_INIT_NVAR(&attribute);
					}
				} else {
					if (Z_TYPE_P(&aliasCopy) == IS_LONG) {
						ZEPHIR_INIT_NVAR(&_103$$63);
						zephir_create_array(&_103$$63, 2, 0);
						zephir_array_fast_append(&_103$$63, &sqlColumn);
						zephir_array_fast_append(&_103$$63, &__$null);
						ZEPHIR_CPY_WRT(&columnAlias, &_103$$63);
					} else {
						ZEPHIR_INIT_NVAR(&_104$$64);
						zephir_create_array(&_104$$64, 3, 0);
						zephir_array_fast_append(&_104$$64, &sqlColumn);
						zephir_array_fast_append(&_104$$64, &__$null);
						zephir_array_fast_append(&_104$$64, &aliasCopy);
						ZEPHIR_CPY_WRT(&columnAlias, &_104$$64);
					}
					zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1300);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_105$$50 = !isComplex;
				if (_105$$50) {
					_105$$50 = isSimpleStd;
				}
				if (_105$$50) {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					_106$$65 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_106$$65) {
						zephir_array_update_zval(&simpleColumnMap, &sqlAlias, &aliasCopy, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_zval(&simpleColumnMap, &aliasCopy, &aliasCopy, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&bindParams, 0, "phalcon/Mvc/Model/Query.zep", 1336);
	if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindParams), _108, _109, _107)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_109 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _109);
			} else {
				ZVAL_LONG(&wildcard, _108);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _107);
			if (Z_TYPE_P(&wildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&wildcardValue);
				ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
			}
			zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_110$$71);
				ZVAL_LONG(&_110$$71, zephir_fast_count_int(&value));
				zephir_array_update_zval(&bindCounts, &wildcardValue, &_110$$71, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindParams, "rewind", NULL, 0);
		zephir_check_call_status();
		_112 = 1;
		while (1) {
			if (_112) {
				_112 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bindParams, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_111, &bindParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_111)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&wildcard, &bindParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &bindParams, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&wildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&wildcardValue);
					ZEPHIR_CONCAT_SV(&wildcardValue, ":", &wildcard);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&wildcardValue, &wildcard);
				}
				zephir_array_update_zval(&processed, &wildcardValue, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_113$$75);
					ZVAL_LONG(&_113$$75, zephir_fast_count_int(&value));
					zephir_array_update_zval(&bindCounts, &wildcardValue, &_113$$75, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	ZEPHIR_INIT_VAR(&processedTypes);
	array_init(&processedTypes);
	zephir_is_iterable(&bindTypes, 0, "phalcon/Mvc/Model/Query.zep", 1349);
	if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindTypes), _115, _116, _114)
		{
			ZEPHIR_INIT_NVAR(&typeWildcard);
			if (_116 != NULL) { 
				ZVAL_STR_COPY(&typeWildcard, _116);
			} else {
				ZVAL_LONG(&typeWildcard, _115);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _114);
			if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&_117$$77);
				ZEPHIR_CONCAT_SV(&_117$$77, ":", &typeWildcard);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&processedTypes, &_117$$77, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bindTypes, "rewind", NULL, 0);
		zephir_check_call_status();
		_119 = 1;
		while (1) {
			if (_119) {
				_119 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bindTypes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_118, &bindTypes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_118)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&typeWildcard, &bindTypes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &bindTypes, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_120$$80);
					ZEPHIR_CONCAT_SV(&_120$$80, ":", &typeWildcard);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&processedTypes, &_120$$80, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&processedTypes, &typeWildcard, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&typeWildcard);
	if (!(ZEPHIR_IS_EMPTY(&bindCounts))) {
		zephir_array_update_string(&intermediate, SL("bindCounts"), &bindCounts, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getDialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&sqlSelect, &dialect, "select", NULL, 0, &intermediate);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1086, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_121$$83, &dialect, "sharedLock", NULL, 0, &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_121$$83);
	}
	ZEPHIR_INIT_VAR(&rawWildcards);
	array_init(&rawWildcards);
	if (Z_TYPE_P(&processed) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_123);
		zephir_string_to_char_array(&_123, &processed);
		_122 = &_123;
	} else {
		_122 = &processed;
	}
	zephir_is_iterable(_122, 0, "phalcon/Mvc/Model/Query.zep", 1388);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_122), _125, _126, _124)
	{
		ZEPHIR_INIT_NVAR(&wildcard);
		if (_126 != NULL) { 
			ZVAL_STR_COPY(&wildcard, _126);
		} else {
			ZVAL_LONG(&wildcard, _125);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _124);
		_127$$84 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_127$$84) {
			_127$$84 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
		}
		if (_127$$84) {
			zephir_array_append(&rawWildcards, &wildcard, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1375);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&wildcard);
	if (zephir_fast_count_int(&rawWildcards) > 1) {
		ZEPHIR_INIT_VAR(&_128$$86);
		ZEPHIR_INIT_NVAR(&_128$$86);
		zephir_create_closure_ex(&_128$$86, NULL, phalcon_89__closure_ce, SL("__invoke"));
		ZEPHIR_MAKE_REF(&rawWildcards);
		ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 0, &rawWildcards, &_128$$86);
		ZEPHIR_UNREF(&rawWildcards);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&rawWildcards) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_130);
		zephir_string_to_char_array(&_130, &rawWildcards);
		_129 = &_130;
	} else {
		_129 = &rawWildcards;
	}
	zephir_is_iterable(_129, 0, "phalcon/Mvc/Model/Query.zep", 1415);
	if (Z_TYPE_P(_129) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_129), _131)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			ZVAL_COPY(&wildcard, _131);
			ZEPHIR_OBS_NVAR(&_132$$87);
			zephir_array_fetch(&_132$$87, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1398);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_133$$87, &_132$$87);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&rawValue, &_133$$87);
			ZVAL_LONG(&_134$$87, 0);
			ZVAL_LONG(&_135$$87, 1);
			ZEPHIR_INIT_NVAR(&_136$$87);
			zephir_substr(&_136$$87, &wildcard, 0 , 1 , 0);
			if (ZEPHIR_IS_STRING_IDENTICAL(&_136$$87, ":")) {
				ZVAL_LONG(&_137$$87, 1);
				ZEPHIR_INIT_NVAR(&placeholder);
				zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			} else {
				ZEPHIR_CPY_WRT(&placeholder, &wildcard);
			}
			ZEPHIR_INIT_NVAR(&_138$$87);
			ZVAL_STRING(&_138$$87, "/");
			ZEPHIR_CALL_FUNCTION(&_139$$87, "preg_quote", &_140, 0, &placeholder, &_138$$87);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_141$$87);
			ZEPHIR_CONCAT_SVS(&_141$$87, "/:", &_139$$87, "\\b/");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_138$$87);
			object_init_ex(&_138$$87, phalcon_90__closure_ce);
			zephir_update_property_zval(&_138$$87, SL("rawValue"), &rawValue);
			ZEPHIR_INIT_NVAR(&_142$$87);
			ZEPHIR_INIT_NVAR(&_142$$87);
			zephir_create_closure_bound(&_142$$87, &_138$$87, NULL, phalcon_90__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_143$$87, "preg_replace_callback", &_144, 0, &_141$$87, &_142$$87, &sqlSelect);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sqlSelect, &_143$$87);
			zephir_array_unset(&processed, &wildcard, PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_unset(&processedTypes, &wildcard, PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _129, "rewind", NULL, 0);
		zephir_check_call_status();
		_146 = 1;
		while (1) {
			if (_146) {
				_146 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _129, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_145, _129, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_145)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&wildcard, _129, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_147$$88);
				zephir_array_fetch(&_147$$88, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1398);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_148$$88, &_147$$88);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&rawValue, &_148$$88);
				ZVAL_LONG(&_149$$88, 0);
				ZVAL_LONG(&_150$$88, 1);
				ZEPHIR_INIT_NVAR(&_151$$88);
				zephir_substr(&_151$$88, &wildcard, 0 , 1 , 0);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_151$$88, ":")) {
					ZVAL_LONG(&_152$$88, 1);
					ZEPHIR_INIT_NVAR(&placeholder);
					zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				} else {
					ZEPHIR_CPY_WRT(&placeholder, &wildcard);
				}
				ZEPHIR_INIT_NVAR(&_153$$88);
				ZVAL_STRING(&_153$$88, "/");
				ZEPHIR_CALL_FUNCTION(&_154$$88, "preg_quote", &_140, 0, &placeholder, &_153$$88);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_155$$88);
				ZEPHIR_CONCAT_SVS(&_155$$88, "/:", &_154$$88, "\\b/");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_153$$88);
				object_init_ex(&_153$$88, phalcon_91__closure_ce);
				zephir_update_property_zval(&_153$$88, SL("rawValue"), &rawValue);
				ZEPHIR_INIT_NVAR(&_156$$88);
				ZEPHIR_INIT_NVAR(&_156$$88);
				zephir_create_closure_bound(&_156$$88, &_153$$88, NULL, phalcon_91__closure_ce, SL("__invoke"));
				ZEPHIR_CALL_FUNCTION(&_157$$88, "preg_replace_callback", &_144, 0, &_155$$88, &_156$$88, &sqlSelect);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&sqlSelect, &_157$$88);
				zephir_array_unset(&processed, &wildcard, PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset(&processedTypes, &wildcard, PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
	zephir_read_property_cached(&_158, this_ptr, _zephir_prop_4, 1079, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_158);
	if (!(isComplex)) {
		if (isSimpleStd) {
			zephir_read_property_cached(&_159$$93, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_159$$93, "")) {
				zephir_read_property_cached(&_160$$94, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&resultObject);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&resultObject, &_160$$94);
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
			ZEPHIR_INIT_VAR(&_162$$96);
			ZVAL_STRING(&_162$$96, "orm.cast_on_hydrate");
			ZEPHIR_CALL_CE_STATIC(&_161$$96, phalcon_support_settings_ce, "get", &_50, 0, &_162$$96);
			zephir_check_call_status();
			if (!(zephir_is_true(&_161$$96))) {
				ZEPHIR_CALL_METHOD(&simpleColumnMap, &metaData, "getColumnMap", NULL, 0, &resultObject);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getColumnMap", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&typesColumnMap, &metaData, "getDataTypes", NULL, 0, &resultObject);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&simpleColumnMap);
				if (Z_TYPE_P(&columnMap) == IS_NULL) {
					array_init(&simpleColumnMap);
					ZEPHIR_CALL_METHOD(&_163$$101, &metaData, "getAttributes", NULL, 0, &resultObject);
					zephir_check_call_status();
					if (Z_TYPE_P(&_163$$101) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_165$$101);
						zephir_string_to_char_array(&_165$$101, &_163$$101);
						_164$$101 = &_165$$101;
					} else {
						_164$$101 = &_163$$101;
					}
					zephir_is_iterable(_164$$101, 0, "phalcon/Mvc/Model/Query.zep", 1489);
					if (Z_TYPE_P(_164$$101) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_164$$101), _166$$101)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _166$$101);
							ZEPHIR_INIT_NVAR(&_167$$102);
							zephir_create_array(&_167$$102, 2, 0);
							zephir_array_fast_append(&_167$$102, &attribute);
							ZEPHIR_OBS_NVAR(&_168$$102);
							zephir_array_fetch(&_168$$102, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1487);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_167$$102, &_168$$102);
							zephir_array_update_zval(&simpleColumnMap, &attribute, &_167$$102, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _164$$101, "rewind", NULL, 0);
						zephir_check_call_status();
						_170$$101 = 1;
						while (1) {
							if (_170$$101) {
								_170$$101 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _164$$101, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_169$$101, _164$$101, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_169$$101)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, _164$$101, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_171$$103);
								zephir_create_array(&_171$$103, 2, 0);
								zephir_array_fast_append(&_171$$103, &attribute);
								ZEPHIR_OBS_NVAR(&_172$$103);
								zephir_array_fetch(&_172$$103, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1487);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_171$$103, &_172$$103);
								zephir_array_update_zval(&simpleColumnMap, &attribute, &_171$$103, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
				} else {
					array_init(&simpleColumnMap);
					if (Z_TYPE_P(&columnMap) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_174$$104);
						zephir_string_to_char_array(&_174$$104, &columnMap);
						_173$$104 = &_174$$104;
					} else {
						_173$$104 = &columnMap;
					}
					zephir_is_iterable(_173$$104, 0, "phalcon/Mvc/Model/Query.zep", 1498);
					if (Z_TYPE_P(_173$$104) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_173$$104), _176$$104, _177$$104, _175$$104)
						{
							ZEPHIR_INIT_NVAR(&column);
							if (_177$$104 != NULL) { 
								ZVAL_STR_COPY(&column, _177$$104);
							} else {
								ZVAL_LONG(&column, _176$$104);
							}
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _175$$104);
							ZEPHIR_INIT_NVAR(&_178$$105);
							zephir_create_array(&_178$$105, 2, 0);
							zephir_array_fast_append(&_178$$105, &attribute);
							ZEPHIR_OBS_NVAR(&_179$$105);
							zephir_array_fetch(&_179$$105, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1496);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_178$$105, &_179$$105);
							zephir_array_update_zval(&simpleColumnMap, &column, &_178$$105, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _173$$104, "rewind", NULL, 0);
						zephir_check_call_status();
						_181$$104 = 1;
						while (1) {
							if (_181$$104) {
								_181$$104 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _173$$104, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_180$$104, _173$$104, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_180$$104)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&column, _173$$104, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attribute, _173$$104, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_182$$106);
								zephir_create_array(&_182$$106, 2, 0);
								zephir_array_fast_append(&_182$$106, &attribute);
								ZEPHIR_OBS_NVAR(&_183$$106);
								zephir_array_fetch(&_183$$106, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1496);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_182$$106, &_183$$106);
								zephir_array_update_zval(&simpleColumnMap, &column, &_182$$106, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					ZEPHIR_INIT_NVAR(&column);
				}
			}
			ZEPHIR_CALL_METHOD(&_184$$96, &manager, "isKeepingSnapshots", NULL, 0, &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_184$$96);
		}
		_185$$92 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce);
		if (_185$$92) {
			_185$$92 = (zephir_method_exists_ex(&resultObject, ZEND_STRL("getresultsetclass")) == SUCCESS);
		}
		if (_185$$92) {
			ZEPHIR_CALL_METHOD(&resultsetClassName, &resultObject, "getResultsetClass", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (UNEXPECTED(!(zephir_class_exists(&resultsetClassName, 1)))) {
					ZEPHIR_INIT_VAR(&_186$$109);
					object_init_ex(&_186$$109, phalcon_mvc_model_query_exceptions_resultsetclassnotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_186$$109, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_186$$109, "phalcon/Mvc/Model/Query.zep", 1512);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_187$$108);
				ZVAL_STRING(&_187$$108, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_188$$108, "is_subclass_of", NULL, 149, &resultsetClassName, &_187$$108);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_188$$108))) {
					ZEPHIR_INIT_VAR(&_189$$110);
					object_init_ex(&_189$$110, phalcon_mvc_model_query_exceptions_invalidresultsetclass_ce);
					ZEPHIR_CALL_METHOD(NULL, &_189$$110, "__construct", NULL, 0, &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_189$$110, "phalcon/Mvc/Model/Query.zep", 1516);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_190$$108);
				zephir_create_array(&_190$$108, 5, 0);
				zephir_array_fast_append(&_190$$108, &simpleColumnMap);
				zephir_array_fast_append(&_190$$108, &resultObject);
				zephir_array_fast_append(&_190$$108, &resultData);
				zephir_array_fast_append(&_190$$108, &cache);
				ZEPHIR_INIT_NVAR(&_187$$108);
				ZVAL_BOOL(&_187$$108, isKeepingSnapshots);
				zephir_array_fast_append(&_190$$108, &_187$$108);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &resultsetClassName, &_190$$108);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_191$$92, 1);
		} else {
			ZVAL_BOOL(&_191$$92, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &simpleColumnMap, &resultObject, &resultData, &cache, &_191$$92);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	zephir_read_property_cached(&_158, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &columns1, &resultData, &cache, &_158);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Executes the UPDATE intermediate representation producing a
 * Phalcon\Mvc\Model\Query\Status
 *
 * @phpstan-param mvc_query_ir $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, executeUpdate)
{
	zval _38$$16, _45$$17, _55$$20, _61$$21, _91$$33, _97$$34, _107$$37, _113$$38;
	zend_string *_10;
	zend_ulong _9;
	zend_bool _0, _3, _66, _11$$5, _18$$10, _49$$13, _32$$14, _33$$15, _50$$18, _51$$19, _67$$22, _74$$27, _101$$30, _86$$31, _87$$32, _102$$35, _103$$36;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_13 = NULL, *_15 = NULL, *_20 = NULL, *_21 = NULL, *_26 = NULL, *_28 = NULL, *_36 = NULL, *_40 = NULL, *_46 = NULL, *_62 = NULL, *_64 = NULL, *_69 = NULL, *_71 = NULL, *_76 = NULL, *_77 = NULL, *_98 = NULL, *_114 = NULL, *_117 = NULL, *_119 = NULL, *_121 = NULL, *_123 = NULL, *_125 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, exception, sqlExpr, namedParams, paramKey, paramKeys, paramValue, _2, *_6, _7, *_8, _65, _118, _126, _1$$3, _4$$4, _12$$5, _14$$10, _16$$10, _17$$10, _19$$11, _22$$12, _23$$12, _24$$12, _25$$13, _27$$13, *_29$$13, _30$$13, *_31$$13, _48$$13, _34$$16, _35$$16, _37$$16, _39$$16, _41$$17, _42$$17, _43$$17, _44$$17, _47$$17, _52$$20, _53$$20, _54$$20, _56$$20, _57$$21, _58$$21, _59$$21, _60$$21, _63$$21, _68$$22, _70$$27, _72$$27, _73$$27, _75$$28, _78$$29, _79$$29, _80$$29, _81$$30, _82$$30, *_83$$30, _84$$30, *_85$$30, _100$$30, _88$$33, _89$$33, _90$$33, _92$$33, _93$$34, _94$$34, _95$$34, _96$$34, _99$$34, _104$$37, _105$$37, _106$$37, _108$$37, _109$$38, _110$$38, _111$$38, _112$$38, _115$$38, _116$$39, _120$$41, _122$$42, _124$$40;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_65);
	ZVAL_UNDEF(&_118);
	ZVAL_UNDEF(&_126);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_39$$16);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_42$$17);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_56$$20);
	ZVAL_UNDEF(&_57$$21);
	ZVAL_UNDEF(&_58$$21);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_60$$21);
	ZVAL_UNDEF(&_63$$21);
	ZVAL_UNDEF(&_68$$22);
	ZVAL_UNDEF(&_70$$27);
	ZVAL_UNDEF(&_72$$27);
	ZVAL_UNDEF(&_73$$27);
	ZVAL_UNDEF(&_75$$28);
	ZVAL_UNDEF(&_78$$29);
	ZVAL_UNDEF(&_79$$29);
	ZVAL_UNDEF(&_80$$29);
	ZVAL_UNDEF(&_81$$30);
	ZVAL_UNDEF(&_82$$30);
	ZVAL_UNDEF(&_84$$30);
	ZVAL_UNDEF(&_100$$30);
	ZVAL_UNDEF(&_88$$33);
	ZVAL_UNDEF(&_89$$33);
	ZVAL_UNDEF(&_90$$33);
	ZVAL_UNDEF(&_92$$33);
	ZVAL_UNDEF(&_93$$34);
	ZVAL_UNDEF(&_94$$34);
	ZVAL_UNDEF(&_95$$34);
	ZVAL_UNDEF(&_96$$34);
	ZVAL_UNDEF(&_99$$34);
	ZVAL_UNDEF(&_104$$37);
	ZVAL_UNDEF(&_105$$37);
	ZVAL_UNDEF(&_106$$37);
	ZVAL_UNDEF(&_108$$37);
	ZVAL_UNDEF(&_109$$38);
	ZVAL_UNDEF(&_110$$38);
	ZVAL_UNDEF(&_111$$38);
	ZVAL_UNDEF(&_112$$38);
	ZVAL_UNDEF(&_115$$38);
	ZVAL_UNDEF(&_116$$39);
	ZVAL_UNDEF(&_120$$41);
	ZVAL_UNDEF(&_122$$42);
	ZVAL_UNDEF(&_124$$40);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_55$$20);
	ZVAL_UNDEF(&_61$$21);
	ZVAL_UNDEF(&_91$$33);
	ZVAL_UNDEF(&_97$$34);
	ZVAL_UNDEF(&_107$$37);
	ZVAL_UNDEF(&_113$$38);
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
	zephir_array_fetch_string(&models, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1570);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_0 = zephir_array_isset_value_long(&models, 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_updatemultiplenotsupported_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 1573);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&modelName);
	zephir_array_fetch_long(&modelName, &models, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1576);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1088, PH_NOISY_CC | PH_READONLY);
	_3 = zephir_array_isset_fetch(&model, &_2, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&model, &_4$$4, "load", NULL, 0, &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", &_5, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dialect, &connection, "getDialect", NULL, 0);
	zephir_check_call_status();
	zephir_memory_observe(&fields);
	zephir_array_fetch_string(&fields, &intermediate, SL("fields"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1595);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&values);
	zephir_array_fetch_string(&values, &intermediate, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1596);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&updateValues);
	array_init(&updateValues);
	ZEPHIR_CPY_WRT(&selectBindParams, &bindParams);
	ZEPHIR_CPY_WRT(&selectBindTypes, &bindTypes);
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &fields);
		_6 = &_7;
	} else {
		_6 = &fields;
	}
	zephir_is_iterable(_6, 0, "phalcon/Mvc/Model/Query.zep", 1709);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6), _9, _10, _8)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_10 != NULL) { 
				ZVAL_STR_COPY(&number, _10);
			} else {
				ZVAL_LONG(&number, _9);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _8);
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1611);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&exprValue);
			zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1612);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_11$$5 = zephir_array_isset_value_string(&field, SL("balias"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_11$$5) {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1615);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1617);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_12$$5);
			zephir_array_fetch_string(&_12$$5, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1620);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&_12$$5, 260)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_12$$5, 258)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_12$$5, 259)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_12$$5, 322)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&_12$$5, 273)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&_12$$5, 274)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&_12$$5, 277)) { goto zephir_switch_0_clause_6; }
			goto zephir_switch_0_clause_7;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getSqlExpression", &_13, 0, &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&updateValue);
				ZVAL_NULL(&updateValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD(&_14$$10, &dialect, "getSqlExpression", &_15, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZVAL_STRING(&_16$$10, ":");
				ZEPHIR_INIT_NVAR(&_17$$10);
				ZVAL_STRING(&_17$$10, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_16$$10, &_17$$10, &_14$$10);
				ZEPHIR_OBS_NVAR(&updateValue);
				_18$$10 = zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_18$$10))) {
					ZEPHIR_INIT_NVAR(&_19$$11);
					object_init_ex(&_19$$11, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD(NULL, &_19$$11, "__construct", &_20, 0, &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$11, "phalcon/Mvc/Model/Query.zep", 1641);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_CALL_METHOD(&sqlExpr, &dialect, "getSqlExpression", &_21, 0, &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&namedParams);
				array_init(&namedParams);
				ZEPHIR_INIT_NVAR(&_22$$12);
				ZVAL_STRING(&_22$$12, "/:([a-zA-Z0-9_]+)/");
				ZEPHIR_INIT_NVAR(&_23$$12);
				ZEPHIR_INIT_NVAR(&_24$$12);
				ZVAL_STRING(&_24$$12, "/:([a-zA-Z0-9_]+)/");
				zephir_preg_match(&_23$$12, &_24$$12, &sqlExpr, &namedParams, 1, 0 , 0 );
				if (zephir_is_true(&_23$$12)) {
					ZEPHIR_OBS_NVAR(&_25$$13);
					zephir_array_fetch_long(&_25$$13, &namedParams, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1667);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_26, 443, &_25$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_27$$13);
					ZEPHIR_INIT_NVAR(&_27$$13);
					zephir_create_closure_ex(&_27$$13, NULL, phalcon_92__closure_ce, SL("__invoke"));
					ZEPHIR_MAKE_REF(&paramKeys);
					ZEPHIR_CALL_FUNCTION(NULL, "usort", &_28, 0, &paramKeys, &_27$$13);
					ZEPHIR_UNREF(&paramKeys);
					zephir_check_call_status();
					if (Z_TYPE_P(&paramKeys) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_30$$13);
						zephir_string_to_char_array(&_30$$13, &paramKeys);
						_29$$13 = &_30$$13;
					} else {
						_29$$13 = &paramKeys;
					}
					zephir_is_iterable(_29$$13, 0, "phalcon/Mvc/Model/Query.zep", 1696);
					if (Z_TYPE_P(_29$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_29$$13), _31$$13)
						{
							ZEPHIR_INIT_NVAR(&paramKey);
							ZVAL_COPY(&paramKey, _31$$13);
							ZEPHIR_OBS_NVAR(&paramValue);
							_32$$14 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_32$$14) {
								_33$$15 = Z_TYPE_P(&paramValue) == IS_LONG;
								if (!(_33$$15)) {
									_33$$15 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
								}
								if (_33$$15) {
									ZEPHIR_INIT_NVAR(&_34$$16);
									ZVAL_STRING(&_34$$16, "/");
									ZEPHIR_CALL_FUNCTION(&_35$$16, "preg_quote", &_36, 0, &paramKey, &_34$$16);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_37$$16);
									ZEPHIR_CONCAT_SVS(&_37$$16, "/:", &_35$$16, "\\b/");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_38$$16, &paramValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_FUNCTION(&_39$$16, "preg_replace", &_40, 4, &_37$$16, &_38$$16, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_39$$16);
								} else {
									ZEPHIR_INIT_NVAR(&_41$$17);
									ZVAL_STRING(&_41$$17, "/");
									ZEPHIR_CALL_FUNCTION(&_42$$17, "preg_quote", &_36, 0, &paramKey, &_41$$17);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_43$$17);
									ZEPHIR_CONCAT_SVS(&_43$$17, "/:", &_42$$17, "\\b/");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_45$$17, &paramValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD(&_44$$17, &connection, "escapeString", &_46, 0, &_45$$17);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_47$$17, "preg_replace", &_40, 4, &_43$$17, &_44$$17, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_47$$17);
								}
								zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _29$$13, "rewind", NULL, 0);
						zephir_check_call_status();
						_49$$13 = 1;
						while (1) {
							if (_49$$13) {
								_49$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _29$$13, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_48$$13, _29$$13, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_48$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&paramKey, _29$$13, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&paramValue);
								_50$$18 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_50$$18) {
									_51$$19 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_51$$19)) {
										_51$$19 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_51$$19) {
										ZEPHIR_INIT_NVAR(&_52$$20);
										ZVAL_STRING(&_52$$20, "/");
										ZEPHIR_CALL_FUNCTION(&_53$$20, "preg_quote", &_36, 0, &paramKey, &_52$$20);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_54$$20);
										ZEPHIR_CONCAT_SVS(&_54$$20, "/:", &_53$$20, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_55$$20, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_FUNCTION(&_56$$20, "preg_replace", &_40, 4, &_54$$20, &_55$$20, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_56$$20);
									} else {
										ZEPHIR_INIT_NVAR(&_57$$21);
										ZVAL_STRING(&_57$$21, "/");
										ZEPHIR_CALL_FUNCTION(&_58$$21, "preg_quote", &_36, 0, &paramKey, &_57$$21);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_59$$21);
										ZEPHIR_CONCAT_SVS(&_59$$21, "/:", &_58$$21, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_61$$21, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD(&_60$$21, &connection, "escapeString", &_62, 0, &_61$$21);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_63$$21, "preg_replace", &_40, 4, &_59$$21, &_60$$21, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_63$$21);
									}
									zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
						}
					}
					ZEPHIR_INIT_NVAR(&paramKey);
				}
				ZEPHIR_INIT_NVAR(&updateValue);
				object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_64, 62, &sqlExpr);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_66 = 1;
		while (1) {
			if (_66) {
				_66 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_65, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_65)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, _6, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&field, _6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &values, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1611);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1612);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_67$$22 = zephir_array_isset_value_string(&field, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_67$$22) {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1615);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&fieldName);
					zephir_array_fetch_string(&fieldName, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1617);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_68$$22);
				zephir_array_fetch_string(&_68$$22, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1620);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_68$$22, 260)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_68$$22, 258)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_68$$22, 259)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_68$$22, 322)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_68$$22, 273)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_68$$22, 274)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_68$$22, 277)) { goto zephir_switch_1_clause_6; }
				goto zephir_switch_1_clause_7;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD(&updateValue, &dialect, "getSqlExpression", &_69, 0, &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&updateValue);
					ZVAL_NULL(&updateValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD(&_70$$27, &dialect, "getSqlExpression", &_71, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_72$$27);
					ZVAL_STRING(&_72$$27, ":");
					ZEPHIR_INIT_NVAR(&_73$$27);
					ZVAL_STRING(&_73$$27, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_72$$27, &_73$$27, &_70$$27);
					ZEPHIR_OBS_NVAR(&updateValue);
					_74$$27 = zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_74$$27))) {
						ZEPHIR_INIT_NVAR(&_75$$28);
						object_init_ex(&_75$$28, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD(NULL, &_75$$28, "__construct", &_76, 0, &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_75$$28, "phalcon/Mvc/Model/Query.zep", 1641);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset(&selectBindParams, &wildcard, PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_unset(&selectBindTypes, &wildcard, PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_CALL_METHOD(&sqlExpr, &dialect, "getSqlExpression", &_77, 0, &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&namedParams);
					array_init(&namedParams);
					ZEPHIR_INIT_NVAR(&_78$$29);
					ZVAL_STRING(&_78$$29, "/:([a-zA-Z0-9_]+)/");
					ZEPHIR_INIT_NVAR(&_79$$29);
					ZEPHIR_INIT_NVAR(&_80$$29);
					ZVAL_STRING(&_80$$29, "/:([a-zA-Z0-9_]+)/");
					zephir_preg_match(&_79$$29, &_80$$29, &sqlExpr, &namedParams, 1, 0 , 0 );
					if (zephir_is_true(&_79$$29)) {
						ZEPHIR_OBS_NVAR(&_81$$30);
						zephir_array_fetch_long(&_81$$30, &namedParams, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1667);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_26, 443, &_81$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_82$$30);
						ZEPHIR_INIT_NVAR(&_82$$30);
						zephir_create_closure_ex(&_82$$30, NULL, phalcon_93__closure_ce, SL("__invoke"));
						ZEPHIR_MAKE_REF(&paramKeys);
						ZEPHIR_CALL_FUNCTION(NULL, "usort", &_28, 0, &paramKeys, &_82$$30);
						ZEPHIR_UNREF(&paramKeys);
						zephir_check_call_status();
						if (Z_TYPE_P(&paramKeys) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_84$$30);
							zephir_string_to_char_array(&_84$$30, &paramKeys);
							_83$$30 = &_84$$30;
						} else {
							_83$$30 = &paramKeys;
						}
						zephir_is_iterable(_83$$30, 0, "phalcon/Mvc/Model/Query.zep", 1696);
						if (Z_TYPE_P(_83$$30) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_83$$30), _85$$30)
							{
								ZEPHIR_INIT_NVAR(&paramKey);
								ZVAL_COPY(&paramKey, _85$$30);
								ZEPHIR_OBS_NVAR(&paramValue);
								_86$$31 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_86$$31) {
									_87$$32 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_87$$32)) {
										_87$$32 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_87$$32) {
										ZEPHIR_INIT_NVAR(&_88$$33);
										ZVAL_STRING(&_88$$33, "/");
										ZEPHIR_CALL_FUNCTION(&_89$$33, "preg_quote", &_36, 0, &paramKey, &_88$$33);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_90$$33);
										ZEPHIR_CONCAT_SVS(&_90$$33, "/:", &_89$$33, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_91$$33, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_FUNCTION(&_92$$33, "preg_replace", &_40, 4, &_90$$33, &_91$$33, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_92$$33);
									} else {
										ZEPHIR_INIT_NVAR(&_93$$34);
										ZVAL_STRING(&_93$$34, "/");
										ZEPHIR_CALL_FUNCTION(&_94$$34, "preg_quote", &_36, 0, &paramKey, &_93$$34);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_95$$34);
										ZEPHIR_CONCAT_SVS(&_95$$34, "/:", &_94$$34, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_97$$34, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD(&_96$$34, &connection, "escapeString", &_98, 0, &_97$$34);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_99$$34, "preg_replace", &_40, 4, &_95$$34, &_96$$34, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_99$$34);
									}
									zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _83$$30, "rewind", NULL, 0);
							zephir_check_call_status();
							_101$$30 = 1;
							while (1) {
								if (_101$$30) {
									_101$$30 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _83$$30, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_100$$30, _83$$30, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_100$$30)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&paramKey, _83$$30, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&paramValue);
									_102$$35 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_102$$35) {
										_103$$36 = Z_TYPE_P(&paramValue) == IS_LONG;
										if (!(_103$$36)) {
											_103$$36 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
										}
										if (_103$$36) {
											ZEPHIR_INIT_NVAR(&_104$$37);
											ZVAL_STRING(&_104$$37, "/");
											ZEPHIR_CALL_FUNCTION(&_105$$37, "preg_quote", &_36, 0, &paramKey, &_104$$37);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_106$$37);
											ZEPHIR_CONCAT_SVS(&_106$$37, "/:", &_105$$37, "\\b/");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_107$$37, &paramValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CALL_FUNCTION(&_108$$37, "preg_replace", &_40, 4, &_106$$37, &_107$$37, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_108$$37);
										} else {
											ZEPHIR_INIT_NVAR(&_109$$38);
											ZVAL_STRING(&_109$$38, "/");
											ZEPHIR_CALL_FUNCTION(&_110$$38, "preg_quote", &_36, 0, &paramKey, &_109$$38);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_111$$38);
											ZEPHIR_CONCAT_SVS(&_111$$38, "/:", &_110$$38, "\\b/");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_113$$38, &paramValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CALL_METHOD(&_112$$38, &connection, "escapeString", &_114, 0, &_113$$38);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_115$$38, "preg_replace", &_40, 4, &_111$$38, &_112$$38, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_115$$38);
										}
										zephir_array_unset(&selectBindParams, &paramKey, PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_unset(&selectBindTypes, &paramKey, PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
							}
						}
						ZEPHIR_INIT_NVAR(&paramKey);
					}
					ZEPHIR_INIT_NVAR(&updateValue);
					object_init_ex(&updateValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD(NULL, &updateValue, "__construct", &_64, 62, &sqlExpr);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				zephir_array_update_zval(&updateValues, &fieldName, &updateValue, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "getRelatedRecords", NULL, 0, &model, &intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_116$$39, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_117, 0, &_116$$39);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "getWriteConnection", &_5, 0, &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_118, &records, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_118))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(&record, &records, "current", &_119, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, &record, "assign", NULL, 0, &updateValues);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&_120$$41, &record, "update", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_120$$41))) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_121, 0);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_122$$42, 0);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_117, 0, &_122$$42, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD(NULL, &records, "next", &_123, 0);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_124$$40);
			ZVAL_OBJ(&_124$$40, EG(exception));
			Z_ADDREF_P(&_124$$40);
			if (zephir_is_instance_of(&_124$$40, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_124$$40);
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", &_125, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Mvc/Model/Query.zep", 1759);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_126, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_117, 0, &_126);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves an expression in a single call argument
 *
 * @phpstan-param array<array-key, mixed> $argument
 * @phpstan-return array<array-key, mixed>
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
	zephir_memory_observe(&_0);
	zephir_array_fetch_string(&_0, &argument, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1779);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_0, 352)) {
		zephir_create_array(return_value, 1, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("all"));
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getExpression", NULL, 0, &argument);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves an expression in a single call argument
 *
 * @phpstan-param array<array-key, mixed> $expr
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getCaseExpression)
{
	zend_bool _14, _4$$3, _15$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _2, *_3, _13, _23, _24, _6$$4, _7$$4, _9$$4, _11$$5, _12$$5, _17$$7, _18$$7, _19$$7, _21$$8, _22$$8;
	zval expr, _5$$4, _10$$5, _16$$7, _20$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(expr, expr_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expr_param);
	zephir_get_arrval(&expr, expr_param);
	ZEPHIR_INIT_VAR(&whenClauses);
	array_init(&whenClauses);
	zephir_array_fetch_string(&_0, &expr, SL("right"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1800);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &_0);
		_1 = &_2;
	} else {
		_1 = &_0;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 1815);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&whenExpr);
			ZVAL_COPY(&whenExpr, _3);
			_4$$3 = zephir_array_isset_value_string(&whenExpr, SL("right"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_4$$3) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				zephir_create_array(&_5$$4, 3, 0);
				add_assoc_stringl_ex(&_5$$4, SL("type"), SL("when"));
				ZEPHIR_OBS_NVAR(&_7$$4);
				zephir_array_fetch_string(&_7$$4, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1804);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getExpression", &_8, 0, &_7$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_5$$4, SL("expr"), &_6$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_9$$4);
				zephir_array_fetch_string(&_9$$4, &whenExpr, SL("right"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1805);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "getExpression", &_8, 0, &_9$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_5$$4, SL("then"), &_6$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_5$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1806);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 2, 0);
				add_assoc_stringl_ex(&_10$$5, SL("type"), SL("else"));
				ZEPHIR_OBS_NVAR(&_12$$5);
				zephir_array_fetch_string(&_12$$5, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1810);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getExpression", &_8, 0, &_12$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("expr"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_10$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1811);
				if (UNEXPECTED(EG(exception))) {
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
			ZEPHIR_CALL_METHOD(&whenExpr, _1, "current", NULL, 0);
			zephir_check_call_status();
				_15$$6 = zephir_array_isset_value_string(&whenExpr, SL("right"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_15$$6) {
					ZEPHIR_INIT_NVAR(&_16$$7);
					zephir_create_array(&_16$$7, 3, 0);
					add_assoc_stringl_ex(&_16$$7, SL("type"), SL("when"));
					ZEPHIR_OBS_NVAR(&_18$$7);
					zephir_array_fetch_string(&_18$$7, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1804);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "getExpression", &_8, 0, &_18$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_16$$7, SL("expr"), &_17$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_19$$7);
					zephir_array_fetch_string(&_19$$7, &whenExpr, SL("right"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1805);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "getExpression", &_8, 0, &_19$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_16$$7, SL("then"), &_17$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_16$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1806);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_20$$8);
					zephir_create_array(&_20$$8, 2, 0);
					add_assoc_stringl_ex(&_20$$8, SL("type"), SL("else"));
					ZEPHIR_OBS_NVAR(&_22$$8);
					zephir_array_fetch_string(&_22$$8, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1810);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_21$$8, this_ptr, "getExpression", &_8, 0, &_22$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_20$$8, SL("expr"), &_21$$8, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_20$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1811);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&whenExpr);
	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("case"));
	zephir_array_fetch_string(&_24, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1817);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getExpression", &_8, 0, &_24);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("when-clauses"), &whenClauses, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Resolves an expression from its intermediate code into an array
 *
 * @phpstan-param array<array-key, mixed> $expr
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getExpression)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0, _0, _106, _107, _1$$4, _4$$4, _57$$41, _111$$80;
	zval *expr_param = NULL, *quoting_param = NULL, __$true, bind, bindType, exprType, exprLeft, exprListItem, exprRight, listItems, name, value, valueParts, exprReturn, left, right, _113, _2$$5, _5$$6, _6$$7, _7$$8, _8$$9, _9$$10, _10$$11, _11$$12, _12$$13, _13$$14, _15$$16, _16$$17, _17$$18, _18$$19, _19$$20, _20$$21, _21$$22, _22$$23, _23$$24, _24$$25, _25$$25, _26$$26, _27$$27, _28$$29, _29$$30, _30$$31, _31$$31, _32$$31, _33$$31, _34$$31, _35$$32, _36$$32, _37$$32, _38$$35, _39$$35, _40$$35, _41$$36, _42$$36, _43$$36, _44$$37, _45$$37, _46$$37, _47$$38, _48$$38, _49$$38, _50$$39, _51$$39, _52$$39, _53$$40, _54$$40, _55$$40, _56$$41, _61$$41, _62$$41, _58$$42, _59$$43, _60$$44, _63$$45, _64$$46, _65$$46, _66$$47, _67$$48, _68$$49, _69$$50, _70$$51, _71$$52, _72$$53, _73$$54, _74$$55, _75$$56, _76$$57, _77$$58, _78$$59, _79$$60, _80$$61, _81$$62, _82$$63, _83$$64, _84$$64, _85$$64, _86$$64, _87$$64, _91$$64, _92$$64, _88$$65, _89$$65, _90$$65, _93$$68, _94$$68, _95$$68, _96$$69, _97$$70, _98$$71, _99$$72, _100$$73, _101$$74, _102$$75, _103$$76, _104$$77, _105$$78, *_108$$80, _110$$80, _109$$81, _112$$82;
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
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_21$$22);
	ZVAL_UNDEF(&_22$$23);
	ZVAL_UNDEF(&_23$$24);
	ZVAL_UNDEF(&_24$$25);
	ZVAL_UNDEF(&_25$$25);
	ZVAL_UNDEF(&_26$$26);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_29$$30);
	ZVAL_UNDEF(&_30$$31);
	ZVAL_UNDEF(&_31$$31);
	ZVAL_UNDEF(&_32$$31);
	ZVAL_UNDEF(&_33$$31);
	ZVAL_UNDEF(&_34$$31);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_37$$32);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_41$$36);
	ZVAL_UNDEF(&_42$$36);
	ZVAL_UNDEF(&_43$$36);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_45$$37);
	ZVAL_UNDEF(&_46$$37);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_48$$38);
	ZVAL_UNDEF(&_49$$38);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_52$$39);
	ZVAL_UNDEF(&_53$$40);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_55$$40);
	ZVAL_UNDEF(&_56$$41);
	ZVAL_UNDEF(&_61$$41);
	ZVAL_UNDEF(&_62$$41);
	ZVAL_UNDEF(&_58$$42);
	ZVAL_UNDEF(&_59$$43);
	ZVAL_UNDEF(&_60$$44);
	ZVAL_UNDEF(&_63$$45);
	ZVAL_UNDEF(&_64$$46);
	ZVAL_UNDEF(&_65$$46);
	ZVAL_UNDEF(&_66$$47);
	ZVAL_UNDEF(&_67$$48);
	ZVAL_UNDEF(&_68$$49);
	ZVAL_UNDEF(&_69$$50);
	ZVAL_UNDEF(&_70$$51);
	ZVAL_UNDEF(&_71$$52);
	ZVAL_UNDEF(&_72$$53);
	ZVAL_UNDEF(&_73$$54);
	ZVAL_UNDEF(&_74$$55);
	ZVAL_UNDEF(&_75$$56);
	ZVAL_UNDEF(&_76$$57);
	ZVAL_UNDEF(&_77$$58);
	ZVAL_UNDEF(&_78$$59);
	ZVAL_UNDEF(&_79$$60);
	ZVAL_UNDEF(&_80$$61);
	ZVAL_UNDEF(&_81$$62);
	ZVAL_UNDEF(&_82$$63);
	ZVAL_UNDEF(&_83$$64);
	ZVAL_UNDEF(&_84$$64);
	ZVAL_UNDEF(&_85$$64);
	ZVAL_UNDEF(&_86$$64);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_91$$64);
	ZVAL_UNDEF(&_92$$64);
	ZVAL_UNDEF(&_88$$65);
	ZVAL_UNDEF(&_89$$65);
	ZVAL_UNDEF(&_90$$65);
	ZVAL_UNDEF(&_93$$68);
	ZVAL_UNDEF(&_94$$68);
	ZVAL_UNDEF(&_95$$68);
	ZVAL_UNDEF(&_96$$69);
	ZVAL_UNDEF(&_97$$70);
	ZVAL_UNDEF(&_98$$71);
	ZVAL_UNDEF(&_99$$72);
	ZVAL_UNDEF(&_100$$73);
	ZVAL_UNDEF(&_101$$74);
	ZVAL_UNDEF(&_102$$75);
	ZVAL_UNDEF(&_103$$76);
	ZVAL_UNDEF(&_104$$77);
	ZVAL_UNDEF(&_105$$78);
	ZVAL_UNDEF(&_110$$80);
	ZVAL_UNDEF(&_109$$81);
	ZVAL_UNDEF(&_112$$82);
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
	_0 = zephir_array_isset_string_fetch(&exprType, &expr, SL("type"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		tempNotQuoting = 1;
		if (!ZEPHIR_IS_LONG(&exprType, 409)) {
			zephir_memory_observe(&exprLeft);
			_1$$4 = zephir_array_isset_string_fetch(&exprLeft, &expr, SL("left"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_1$$4) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_2$$5, 1);
				} else {
					ZVAL_BOOL(&_2$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&left, this_ptr, "getExpression", &_3, 0, &exprLeft, &_2$$5);
				zephir_check_call_status();
			}
			zephir_memory_observe(&exprRight);
			_4$$4 = zephir_array_isset_string_fetch(&exprRight, &expr, SL("right"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_4$$4) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_5$$6, 1);
				} else {
					ZVAL_BOOL(&_5$$6, 0);
				}
				ZEPHIR_CALL_METHOD(&right, this_ptr, "getExpression", &_3, 0, &exprRight, &_5$$6);
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
		if (ZEPHIR_IS_LONG(&exprType, 355)) { goto zephir_switch_0_clause_8; }
		if (ZEPHIR_IS_LONG(&exprType, '+')) { goto zephir_switch_0_clause_9; }
		if (ZEPHIR_IS_LONG(&exprType, '-')) { goto zephir_switch_0_clause_10; }
		if (ZEPHIR_IS_LONG(&exprType, '*')) { goto zephir_switch_0_clause_11; }
		if (ZEPHIR_IS_LONG(&exprType, '/')) { goto zephir_switch_0_clause_12; }
		if (ZEPHIR_IS_LONG(&exprType, '%')) { goto zephir_switch_0_clause_13; }
		if (ZEPHIR_IS_LONG(&exprType, '&')) { goto zephir_switch_0_clause_14; }
		if (ZEPHIR_IS_LONG(&exprType, '|')) { goto zephir_switch_0_clause_15; }
		if (ZEPHIR_IS_LONG(&exprType, 356)) { goto zephir_switch_0_clause_16; }
		if (ZEPHIR_IS_LONG(&exprType, 407)) { goto zephir_switch_0_clause_17; }
		if (ZEPHIR_IS_LONG(&exprType, 367)) { goto zephir_switch_0_clause_18; }
		if (ZEPHIR_IS_LONG(&exprType, 258)) { goto zephir_switch_0_clause_19; }
		if (ZEPHIR_IS_LONG(&exprType, 259)) { goto zephir_switch_0_clause_20; }
		if (ZEPHIR_IS_LONG(&exprType, 414)) { goto zephir_switch_0_clause_21; }
		if (ZEPHIR_IS_LONG(&exprType, 334)) { goto zephir_switch_0_clause_22; }
		if (ZEPHIR_IS_LONG(&exprType, 335)) { goto zephir_switch_0_clause_23; }
		if (ZEPHIR_IS_LONG(&exprType, 260)) { goto zephir_switch_0_clause_24; }
		if (ZEPHIR_IS_LONG(&exprType, 273)) { goto zephir_switch_0_clause_25; }
		if (ZEPHIR_IS_LONG(&exprType, 274)) { goto zephir_switch_0_clause_26; }
		if (ZEPHIR_IS_LONG(&exprType, 277)) { goto zephir_switch_0_clause_27; }
		if (ZEPHIR_IS_LONG(&exprType, 322)) { goto zephir_switch_0_clause_28; }
		if (ZEPHIR_IS_LONG(&exprType, 268)) { goto zephir_switch_0_clause_29; }
		if (ZEPHIR_IS_LONG(&exprType, 351)) { goto zephir_switch_0_clause_30; }
		if (ZEPHIR_IS_LONG(&exprType, 275)) { goto zephir_switch_0_clause_31; }
		if (ZEPHIR_IS_LONG(&exprType, 357)) { goto zephir_switch_0_clause_32; }
		if (ZEPHIR_IS_LONG(&exprType, '!')) { goto zephir_switch_0_clause_33; }
		if (ZEPHIR_IS_LONG(&exprType, 365)) { goto zephir_switch_0_clause_34; }
		if (ZEPHIR_IS_LONG(&exprType, 366)) { goto zephir_switch_0_clause_35; }
		if (ZEPHIR_IS_LONG(&exprType, 315)) { goto zephir_switch_0_clause_36; }
		if (ZEPHIR_IS_LONG(&exprType, 323)) { goto zephir_switch_0_clause_37; }
		if (ZEPHIR_IS_LONG(&exprType, 408)) { goto zephir_switch_0_clause_38; }
		if (ZEPHIR_IS_LONG(&exprType, 330)) { goto zephir_switch_0_clause_39; }
		if (ZEPHIR_IS_LONG(&exprType, 332)) { goto zephir_switch_0_clause_40; }
		if (ZEPHIR_IS_LONG(&exprType, 331)) { goto zephir_switch_0_clause_41; }
		if (ZEPHIR_IS_LONG(&exprType, 276)) { goto zephir_switch_0_clause_42; }
		if (ZEPHIR_IS_LONG(&exprType, 333)) { goto zephir_switch_0_clause_43; }
		if (ZEPHIR_IS_LONG(&exprType, 336)) { goto zephir_switch_0_clause_44; }
		if (ZEPHIR_IS_LONG(&exprType, 358)) { goto zephir_switch_0_clause_45; }
		if (ZEPHIR_IS_LONG(&exprType, 350)) { goto zephir_switch_0_clause_46; }
		if (ZEPHIR_IS_LONG(&exprType, 409)) { goto zephir_switch_0_clause_47; }
		if (ZEPHIR_IS_LONG(&exprType, 309)) { goto zephir_switch_0_clause_48; }
		if (ZEPHIR_IS_LONG(&exprType, 401)) { goto zephir_switch_0_clause_49; }
		if (ZEPHIR_IS_LONG(&exprType, 402)) { goto zephir_switch_0_clause_50; }
		if (ZEPHIR_IS_LONG(&exprType, 403)) { goto zephir_switch_0_clause_51; }
		if (ZEPHIR_IS_LONG(&exprType, 404)) { goto zephir_switch_0_clause_52; }
		if (ZEPHIR_IS_LONG(&exprType, 405)) { goto zephir_switch_0_clause_53; }
		if (ZEPHIR_IS_LONG(&exprType, 406)) { goto zephir_switch_0_clause_54; }
		if (ZEPHIR_IS_LONG(&exprType, 416)) { goto zephir_switch_0_clause_55; }
		if (ZEPHIR_IS_LONG(&exprType, 417)) { goto zephir_switch_0_clause_56; }
		if (ZEPHIR_IS_LONG(&exprType, 418)) { goto zephir_switch_0_clause_57; }
		goto zephir_switch_0_clause_58;
		zephir_switch_0_clause_0: ;
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_create_array(&_6$$7, 4, 0);
			add_assoc_stringl_ex(&_6$$7, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_6$$7, SL("op"), SL("<"));
			zephir_array_update_string(&_6$$7, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$7, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_6$$7);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_VAR(&_7$$8);
			zephir_create_array(&_7$$8, 4, 0);
			add_assoc_stringl_ex(&_7$$8, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_7$$8, SL("op"), SL("="));
			zephir_array_update_string(&_7$$8, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$8, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_7$$8);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_VAR(&_8$$9);
			zephir_create_array(&_8$$9, 4, 0);
			add_assoc_stringl_ex(&_8$$9, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_8$$9, SL("op"), SL(">"));
			zephir_array_update_string(&_8$$9, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8$$9, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_8$$9);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_VAR(&_9$$10);
			zephir_create_array(&_9$$10, 4, 0);
			add_assoc_stringl_ex(&_9$$10, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_9$$10, SL("op"), SL("<>"));
			zephir_array_update_string(&_9$$10, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_9$$10, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_9$$10);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_4: ;
			ZEPHIR_INIT_VAR(&_10$$11);
			zephir_create_array(&_10$$11, 4, 0);
			add_assoc_stringl_ex(&_10$$11, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_10$$11, SL("op"), SL("<="));
			zephir_array_update_string(&_10$$11, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$11, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_10$$11);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_5: ;
			ZEPHIR_INIT_VAR(&_11$$12);
			zephir_create_array(&_11$$12, 4, 0);
			add_assoc_stringl_ex(&_11$$12, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_11$$12, SL("op"), SL(">="));
			zephir_array_update_string(&_11$$12, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$12, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_11$$12);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_6: ;
			ZEPHIR_INIT_VAR(&_12$$13);
			zephir_create_array(&_12$$13, 4, 0);
			add_assoc_stringl_ex(&_12$$13, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_12$$13, SL("op"), SL("AND"));
			zephir_array_update_string(&_12$$13, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_12$$13, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_12$$13);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_7: ;
			ZEPHIR_INIT_VAR(&_13$$14);
			zephir_create_array(&_13$$14, 4, 0);
			add_assoc_stringl_ex(&_13$$14, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_13$$14, SL("op"), SL("OR"));
			zephir_array_update_string(&_13$$14, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$14, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_13$$14);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_8: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getQualified", &_14, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_9: ;
			ZEPHIR_INIT_VAR(&_15$$16);
			zephir_create_array(&_15$$16, 4, 0);
			add_assoc_stringl_ex(&_15$$16, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_15$$16, SL("op"), SL("+"));
			zephir_array_update_string(&_15$$16, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$16, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_15$$16);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_10: ;
			ZEPHIR_INIT_VAR(&_16$$17);
			zephir_create_array(&_16$$17, 4, 0);
			add_assoc_stringl_ex(&_16$$17, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_16$$17, SL("op"), SL("-"));
			zephir_array_update_string(&_16$$17, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$17, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_16$$17);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_11: ;
			ZEPHIR_INIT_VAR(&_17$$18);
			zephir_create_array(&_17$$18, 4, 0);
			add_assoc_stringl_ex(&_17$$18, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_17$$18, SL("op"), SL("*"));
			zephir_array_update_string(&_17$$18, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_17$$18, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_17$$18);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_12: ;
			ZEPHIR_INIT_VAR(&_18$$19);
			zephir_create_array(&_18$$19, 4, 0);
			add_assoc_stringl_ex(&_18$$19, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_18$$19, SL("op"), SL("/"));
			zephir_array_update_string(&_18$$19, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_18$$19, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_18$$19);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_13: ;
			ZEPHIR_INIT_VAR(&_19$$20);
			zephir_create_array(&_19$$20, 4, 0);
			add_assoc_stringl_ex(&_19$$20, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_19$$20, SL("op"), SL("%"));
			zephir_array_update_string(&_19$$20, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_19$$20, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_19$$20);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_14: ;
			ZEPHIR_INIT_VAR(&_20$$21);
			zephir_create_array(&_20$$21, 4, 0);
			add_assoc_stringl_ex(&_20$$21, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_20$$21, SL("op"), SL("&"));
			zephir_array_update_string(&_20$$21, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_20$$21, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_20$$21);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_15: ;
			ZEPHIR_INIT_VAR(&_21$$22);
			zephir_create_array(&_21$$22, 4, 0);
			add_assoc_stringl_ex(&_21$$22, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_21$$22, SL("op"), SL("|"));
			zephir_array_update_string(&_21$$22, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_21$$22, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_21$$22);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_16: ;
		zephir_switch_0_clause_17: ;
			ZEPHIR_INIT_VAR(&_22$$23);
			zephir_create_array(&_22$$23, 2, 0);
			add_assoc_stringl_ex(&_22$$23, SL("type"), SL("parentheses"));
			zephir_array_update_string(&_22$$23, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_22$$23);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_18: ;
			ZEPHIR_INIT_VAR(&_23$$24);
			zephir_create_array(&_23$$24, 3, 0);
			add_assoc_stringl_ex(&_23$$24, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_23$$24, SL("op"), SL("-"));
			zephir_array_update_string(&_23$$24, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_23$$24);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_19: ;
		zephir_switch_0_clause_20: ;
		zephir_switch_0_clause_21: ;
			ZEPHIR_INIT_VAR(&_24$$25);
			zephir_create_array(&_24$$25, 2, 0);
			add_assoc_stringl_ex(&_24$$25, SL("type"), SL("literal"));
			zephir_memory_observe(&_25$$25);
			zephir_array_fetch_string(&_25$$25, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2038);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_24$$25, SL("value"), &_25$$25, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_24$$25);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_22: ;
			ZEPHIR_INIT_VAR(&_26$$26);
			zephir_create_array(&_26$$26, 2, 0);
			add_assoc_stringl_ex(&_26$$26, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_26$$26, SL("value"), SL("TRUE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_26$$26);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_23: ;
			ZEPHIR_INIT_VAR(&_27$$27);
			zephir_create_array(&_27$$27, 2, 0);
			add_assoc_stringl_ex(&_27$$27, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_27$$27, SL("value"), SL("FALSE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_27$$27);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_24: ;
			zephir_memory_observe(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2059);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&exprReturn);
			if (quoting) {
				ZEPHIR_INIT_VAR(&_28$$29);
				zephir_create_array(&_28$$29, 3, 0);
				add_assoc_stringl_ex(&_28$$29, SL("type"), SL("literal"));
				zephir_array_update_string(&_28$$29, SL("value"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$29, SL("escape"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_28$$29);
			} else {
				ZEPHIR_INIT_VAR(&_29$$30);
				zephir_create_array(&_29$$30, 2, 0);
				add_assoc_stringl_ex(&_29$$30, SL("type"), SL("literal"));
				zephir_array_update_string(&_29$$30, SL("value"), &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_29$$30);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_25: ;
			ZEPHIR_INIT_VAR(&_30$$31);
			zephir_create_array(&_30$$31, 2, 0);
			add_assoc_stringl_ex(&_30$$31, SL("type"), SL("placeholder"));
			ZEPHIR_INIT_VAR(&_31$$31);
			zephir_memory_observe(&_32$$31);
			zephir_array_fetch_string(&_32$$31, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2085);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_33$$31);
			ZVAL_STRING(&_33$$31, "?");
			ZEPHIR_INIT_VAR(&_34$$31);
			ZVAL_STRING(&_34$$31, ":");
			zephir_fast_str_replace(&_31$$31, &_33$$31, &_34$$31, &_32$$31);
			zephir_array_update_string(&_30$$31, SL("value"), &_31$$31, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_30$$31);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_26: ;
			ZEPHIR_INIT_VAR(&_35$$32);
			zephir_create_array(&_35$$32, 2, 0);
			add_assoc_stringl_ex(&_35$$32, SL("type"), SL("placeholder"));
			zephir_memory_observe(&_36$$32);
			zephir_array_fetch_string(&_36$$32, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2094);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_37$$32);
			ZEPHIR_CONCAT_SV(&_37$$32, ":", &_36$$32);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_35$$32, SL("value"), &_37$$32, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_35$$32);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_27: ;
			ZEPHIR_OBS_NVAR(&value);
			zephir_array_fetch_string(&value, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2099);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_memnstr_str(&value, SL(":"), "phalcon/Mvc/Model/Query.zep", 2101)) {
				ZEPHIR_INIT_VAR(&valueParts);
				zephir_fast_explode_str(&valueParts, SL(":"), &value, NULL);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&name);
				zephir_array_fetch_long(&name, &valueParts, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2103);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_memory_observe(&bindType);
				zephir_array_fetch_long(&bindType, &valueParts, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2104);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
					ZEPHIR_INIT_VAR(&_38$$35);
					ZVAL_LONG(&_38$$35, 2);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_38$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_39$$35);
					zephir_create_array(&_39$$35, 2, 0);
					add_assoc_stringl_ex(&_39$$35, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_40$$35);
					ZEPHIR_CONCAT_SV(&_40$$35, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_39$$35, SL("value"), &_40$$35, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_39$$35);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_VAR(&_41$$36);
					ZVAL_LONG(&_41$$36, 1);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_41$$36);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_42$$36);
					zephir_create_array(&_42$$36, 2, 0);
					add_assoc_stringl_ex(&_42$$36, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_43$$36);
					ZEPHIR_CONCAT_SV(&_43$$36, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_42$$36, SL("value"), &_43$$36, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_42$$36);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_VAR(&_44$$37);
					ZVAL_LONG(&_44$$37, 32);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_44$$37);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_45$$37);
					zephir_create_array(&_45$$37, 2, 0);
					add_assoc_stringl_ex(&_45$$37, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_46$$37);
					ZEPHIR_CONCAT_SV(&_46$$37, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_45$$37, SL("value"), &_46$$37, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_45$$37);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_VAR(&_47$$38);
					ZVAL_LONG(&_47$$38, 5);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_47$$38);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_48$$38);
					zephir_create_array(&_48$$38, 2, 0);
					add_assoc_stringl_ex(&_48$$38, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_49$$38);
					ZEPHIR_CONCAT_SV(&_49$$38, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_48$$38, SL("value"), &_49$$38, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_48$$38);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_VAR(&_50$$39);
					ZVAL_LONG(&_50$$39, 3);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_50$$39);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_51$$39);
					zephir_create_array(&_51$$39, 2, 0);
					add_assoc_stringl_ex(&_51$$39, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_52$$39);
					ZEPHIR_CONCAT_SV(&_52$$39, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_51$$39, SL("value"), &_52$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_51$$39);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_VAR(&_53$$40);
					ZVAL_LONG(&_53$$40, 0);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_53$$40);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_54$$40);
					zephir_create_array(&_54$$40, 2, 0);
					add_assoc_stringl_ex(&_54$$40, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_55$$40);
					ZEPHIR_CONCAT_SV(&_55$$40, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_54$$40, SL("value"), &_55$$40, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_54$$40);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
				zephir_switch_1_clause_7: ;
				zephir_switch_1_clause_8: ;
					zephir_memory_observe(&bind);
					zephir_read_property_cached(&_56$$41, this_ptr, _zephir_prop_0, 1074, PH_NOISY_CC | PH_READONLY);
					_57$$41 = zephir_array_isset_fetch(&bind, &_56$$41, &name, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_57$$41))) {
						ZEPHIR_INIT_VAR(&_58$$42);
						object_init_ex(&_58$$42, phalcon_mvc_model_query_exceptions_bindvaluerequired_ce);
						ZEPHIR_CALL_METHOD(NULL, &_58$$42, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_58$$42, "phalcon/Mvc/Model/Query.zep", 2172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(Z_TYPE_P(&bind) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(&_59$$43);
						object_init_ex(&_59$$43, phalcon_mvc_model_query_exceptions_bindtyperequiresarray_ce);
						ZEPHIR_CALL_METHOD(NULL, &_59$$43, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_59$$43, "phalcon/Mvc/Model/Query.zep", 2176);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(ZEPHIR_IS_EMPTY(&bind))) {
						ZEPHIR_INIT_VAR(&_60$$44);
						object_init_ex(&_60$$44, phalcon_mvc_model_query_exceptions_emptyarrayplaceholdervalue_ce);
						ZEPHIR_CALL_METHOD(NULL, &_60$$44, "__construct", NULL, 0, &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_60$$44, "phalcon/Mvc/Model/Query.zep", 2180);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_61$$41);
					zephir_create_array(&_61$$41, 4, 0);
					add_assoc_stringl_ex(&_61$$41, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_62$$41);
					ZEPHIR_CONCAT_SV(&_62$$41, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_61$$41, SL("value"), &_62$$41, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_61$$41, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
					add_assoc_long_ex(&_61$$41, SL("times"), zephir_fast_count_int(&bind));
					ZEPHIR_CPY_WRT(&exprReturn, &_61$$41);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_VAR(&_63$$45);
					object_init_ex(&_63$$45, phalcon_mvc_model_query_exceptions_unknownbindtype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_63$$45, "__construct", NULL, 0, &bindType);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_63$$45, "phalcon/Mvc/Model/Query.zep", 2193);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

			} else {
				ZEPHIR_INIT_VAR(&_64$$46);
				zephir_create_array(&_64$$46, 2, 0);
				add_assoc_stringl_ex(&_64$$46, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_65$$46);
				ZEPHIR_CONCAT_SV(&_65$$46, ":", &value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_64$$46, SL("value"), &_65$$46, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_64$$46);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_28: ;
			ZEPHIR_INIT_VAR(&_66$$47);
			zephir_create_array(&_66$$47, 2, 0);
			add_assoc_stringl_ex(&_66$$47, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_66$$47, SL("value"), SL("NULL"));
			ZEPHIR_CPY_WRT(&exprReturn, &_66$$47);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_29: ;
			ZEPHIR_INIT_VAR(&_67$$48);
			zephir_create_array(&_67$$48, 4, 0);
			add_assoc_stringl_ex(&_67$$48, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_67$$48, SL("op"), SL("LIKE"));
			zephir_array_update_string(&_67$$48, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_67$$48, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_67$$48);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_30: ;
			ZEPHIR_INIT_VAR(&_68$$49);
			zephir_create_array(&_68$$49, 4, 0);
			add_assoc_stringl_ex(&_68$$49, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_68$$49, SL("op"), SL("NOT LIKE"));
			zephir_array_update_string(&_68$$49, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_68$$49, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_68$$49);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_31: ;
			ZEPHIR_INIT_VAR(&_69$$50);
			zephir_create_array(&_69$$50, 4, 0);
			add_assoc_stringl_ex(&_69$$50, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_69$$50, SL("op"), SL("ILIKE"));
			zephir_array_update_string(&_69$$50, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_69$$50, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_69$$50);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_32: ;
			ZEPHIR_INIT_VAR(&_70$$51);
			zephir_create_array(&_70$$51, 4, 0);
			add_assoc_stringl_ex(&_70$$51, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_70$$51, SL("op"), SL("NOT ILIKE"));
			zephir_array_update_string(&_70$$51, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_70$$51, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_70$$51);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_33: ;
			ZEPHIR_INIT_VAR(&_71$$52);
			zephir_create_array(&_71$$52, 3, 0);
			add_assoc_stringl_ex(&_71$$52, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_71$$52, SL("op"), SL("NOT "));
			zephir_array_update_string(&_71$$52, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_71$$52);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_34: ;
			ZEPHIR_INIT_VAR(&_72$$53);
			zephir_create_array(&_72$$53, 3, 0);
			add_assoc_stringl_ex(&_72$$53, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_72$$53, SL("op"), SL(" IS NULL"));
			zephir_array_update_string(&_72$$53, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_72$$53);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_35: ;
			ZEPHIR_INIT_VAR(&_73$$54);
			zephir_create_array(&_73$$54, 3, 0);
			add_assoc_stringl_ex(&_73$$54, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_73$$54, SL("op"), SL(" IS NOT NULL"));
			zephir_array_update_string(&_73$$54, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_73$$54);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_36: ;
			ZEPHIR_INIT_VAR(&_74$$55);
			zephir_create_array(&_74$$55, 4, 0);
			add_assoc_stringl_ex(&_74$$55, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_74$$55, SL("op"), SL("IN"));
			zephir_array_update_string(&_74$$55, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_74$$55, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_74$$55);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_37: ;
			ZEPHIR_INIT_VAR(&_75$$56);
			zephir_create_array(&_75$$56, 4, 0);
			add_assoc_stringl_ex(&_75$$56, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_75$$56, SL("op"), SL("NOT IN"));
			zephir_array_update_string(&_75$$56, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_75$$56, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_75$$56);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_38: ;
			ZEPHIR_INIT_VAR(&_76$$57);
			zephir_create_array(&_76$$57, 3, 0);
			add_assoc_stringl_ex(&_76$$57, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_76$$57, SL("op"), SL("EXISTS"));
			zephir_array_update_string(&_76$$57, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_76$$57);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_39: ;
			ZEPHIR_INIT_VAR(&_77$$58);
			zephir_create_array(&_77$$58, 3, 0);
			add_assoc_stringl_ex(&_77$$58, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_77$$58, SL("op"), SL("DISTINCT "));
			zephir_array_update_string(&_77$$58, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_77$$58);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_40: ;
			ZEPHIR_INIT_VAR(&_78$$59);
			zephir_create_array(&_78$$59, 4, 0);
			add_assoc_stringl_ex(&_78$$59, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_78$$59, SL("op"), SL("NOT BETWEEN"));
			zephir_array_update_string(&_78$$59, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_78$$59, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_78$$59);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_41: ;
			ZEPHIR_INIT_VAR(&_79$$60);
			zephir_create_array(&_79$$60, 4, 0);
			add_assoc_stringl_ex(&_79$$60, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_79$$60, SL("op"), SL("BETWEEN"));
			zephir_array_update_string(&_79$$60, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_79$$60, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_79$$60);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_42: ;
			ZEPHIR_INIT_VAR(&_80$$61);
			zephir_create_array(&_80$$61, 4, 0);
			add_assoc_stringl_ex(&_80$$61, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_80$$61, SL("op"), SL("AGAINST"));
			zephir_array_update_string(&_80$$61, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_80$$61, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_80$$61);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_43: ;
			ZEPHIR_INIT_VAR(&_81$$62);
			zephir_create_array(&_81$$62, 3, 0);
			add_assoc_stringl_ex(&_81$$62, SL("type"), SL("cast"));
			zephir_array_update_string(&_81$$62, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_81$$62, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_81$$62);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_44: ;
			ZEPHIR_INIT_VAR(&_82$$63);
			zephir_create_array(&_82$$63, 3, 0);
			add_assoc_stringl_ex(&_82$$63, SL("type"), SL("convert"));
			zephir_array_update_string(&_82$$63, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_82$$63, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_82$$63);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_45: ;
			ZEPHIR_INIT_VAR(&_83$$64);
			zephir_memory_observe(&_84$$64);
			zephir_array_fetch_string(&_84$$64, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2371);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_85$$64);
			ZVAL_STRING(&_85$$64, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			ZEPHIR_INIT_VAR(&_86$$64);
			ZEPHIR_INIT_VAR(&_87$$64);
			ZVAL_STRING(&_87$$64, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			zephir_preg_match(&_86$$64, &_87$$64, &_84$$64, &_83$$64, 0, 0 , 0 );
			if (UNEXPECTED(!zephir_is_true(&_86$$64))) {
				ZEPHIR_INIT_VAR(&_88$$65);
				object_init_ex(&_88$$65, phalcon_mvc_model_query_exceptions_unsafeidentifier_ce);
				zephir_memory_observe(&_89$$65);
				zephir_array_fetch_string(&_89$$65, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2372);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_90$$65, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_88$$65, "__construct", NULL, 0, &_89$$65, &_90$$65);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_88$$65, "phalcon/Mvc/Model/Query.zep", 2372);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_91$$64);
			zephir_create_array(&_91$$64, 2, 0);
			add_assoc_stringl_ex(&_91$$64, SL("type"), SL("literal"));
			zephir_memory_observe(&_92$$64);
			zephir_array_fetch_string(&_92$$64, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2378);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_91$$64, SL("value"), &_92$$64, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_91$$64);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_46: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getFunctionCall", NULL, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_47: ;
			ZEPHIR_CALL_METHOD(&exprReturn, this_ptr, "getCaseExpression", NULL, 0, &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_48: ;
			ZEPHIR_INIT_VAR(&_93$$68);
			zephir_create_array(&_93$$68, 2, 0);
			add_assoc_stringl_ex(&_93$$68, SL("type"), SL("select"));
			ZVAL_BOOL(&_95$$68, 1);
			ZEPHIR_CALL_METHOD(&_94$$68, this_ptr, "prepareSelect", NULL, 0, &expr, &_95$$68);
			zephir_check_call_status();
			zephir_array_update_string(&_93$$68, SL("value"), &_94$$68, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_93$$68);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_49: ;
			ZEPHIR_INIT_VAR(&_96$$69);
			zephir_create_array(&_96$$69, 4, 0);
			add_assoc_stringl_ex(&_96$$69, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_96$$69, SL("op"), SL("@@"));
			zephir_array_update_string(&_96$$69, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_96$$69, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_96$$69);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_50: ;
			ZEPHIR_INIT_VAR(&_97$$70);
			zephir_create_array(&_97$$70, 4, 0);
			add_assoc_stringl_ex(&_97$$70, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_97$$70, SL("op"), SL("@>"));
			zephir_array_update_string(&_97$$70, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_97$$70, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_97$$70);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_51: ;
			ZEPHIR_INIT_VAR(&_98$$71);
			zephir_create_array(&_98$$71, 4, 0);
			add_assoc_stringl_ex(&_98$$71, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_98$$71, SL("op"), SL("<@"));
			zephir_array_update_string(&_98$$71, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_98$$71, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_98$$71);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_52: ;
			ZEPHIR_INIT_VAR(&_99$$72);
			zephir_create_array(&_99$$72, 4, 0);
			add_assoc_stringl_ex(&_99$$72, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_99$$72, SL("op"), SL("&&"));
			zephir_array_update_string(&_99$$72, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_99$$72, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_99$$72);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_53: ;
			ZEPHIR_INIT_VAR(&_100$$73);
			zephir_create_array(&_100$$73, 4, 0);
			add_assoc_stringl_ex(&_100$$73, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_100$$73, SL("op"), SL("||"));
			zephir_array_update_string(&_100$$73, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_100$$73, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_100$$73);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_54: ;
			ZEPHIR_INIT_VAR(&_101$$74);
			zephir_create_array(&_101$$74, 4, 0);
			add_assoc_stringl_ex(&_101$$74, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_101$$74, SL("op"), SL("->"));
			zephir_array_update_string(&_101$$74, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_101$$74, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_101$$74);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_55: ;
			ZEPHIR_INIT_VAR(&_102$$75);
			zephir_create_array(&_102$$75, 4, 0);
			add_assoc_stringl_ex(&_102$$75, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_102$$75, SL("op"), SL("->>"));
			zephir_array_update_string(&_102$$75, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_102$$75, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_102$$75);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_56: ;
			ZEPHIR_INIT_VAR(&_103$$76);
			zephir_create_array(&_103$$76, 4, 0);
			add_assoc_stringl_ex(&_103$$76, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_103$$76, SL("op"), SL("#>"));
			zephir_array_update_string(&_103$$76, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_103$$76, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_103$$76);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_57: ;
			ZEPHIR_INIT_VAR(&_104$$77);
			zephir_create_array(&_104$$77, 4, 0);
			add_assoc_stringl_ex(&_104$$77, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_104$$77, SL("op"), SL("#>>"));
			zephir_array_update_string(&_104$$77, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_104$$77, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_104$$77);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_58: ;
			ZEPHIR_INIT_VAR(&_105$$78);
			object_init_ex(&_105$$78, phalcon_mvc_model_query_exceptions_unknownphqlexpressiontype_ce);
			ZEPHIR_CALL_METHOD(NULL, &_105$$78, "__construct", NULL, 0, &exprType);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_105$$78, "phalcon/Mvc/Model/Query.zep", 2491);
			ZEPHIR_MM_RESTORE();
			return;
		zephir_switch_0_end: ;

		RETURN_CCTOR(&exprReturn);
	}
	_106 = zephir_array_isset_value_string(&expr, SL("domain"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_106) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getQualified", &_14, 0, &expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	_107 = zephir_array_isset_value_long(&expr, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_107) {
		ZEPHIR_INIT_VAR(&listItems);
		array_init(&listItems);
		zephir_is_iterable(&expr, 0, "phalcon/Mvc/Model/Query.zep", 2514);
		if (Z_TYPE_P(&expr) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _108$$80)
			{
				ZEPHIR_INIT_NVAR(&exprListItem);
				ZVAL_COPY(&exprListItem, _108$$80);
				ZEPHIR_CALL_METHOD(&_109$$81, this_ptr, "getExpression", &_3, 0, &exprListItem);
				zephir_check_call_status();
				zephir_array_append(&listItems, &_109$$81, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2511);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &expr, "rewind", NULL, 0);
			zephir_check_call_status();
			_111$$80 = 1;
			while (1) {
				if (_111$$80) {
					_111$$80 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &expr, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_110$$80, &expr, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_110$$80)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&exprListItem, &expr, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_112$$82, this_ptr, "getExpression", &_3, 0, &exprListItem);
					zephir_check_call_status();
					zephir_array_append(&listItems, &_112$$82, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2511);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&exprListItem);
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("list"));
		zephir_array_fast_append(return_value, &listItems);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_113);
	object_init_ex(&_113, phalcon_mvc_model_query_exceptions_unknownphqlexpression_ce);
	ZEPHIR_CALL_METHOD(NULL, &_113, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_113, "phalcon/Mvc/Model/Query.zep", 2520);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves an expression in a single call argument
 *
 * @phpstan-param array<array-key, mixed> $expr
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getFunctionCall)
{
	zend_bool _6, _7$$4, _8$$4, _15$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, name, _0, _1, _2, _3, _22, _4$$3, _5$$3, *_9$$7, _10$$7, *_11$$7, _14$$7, _12$$8, _16$$9, _17$$10, _18$$10, _19$$11, _20$$11, _21$$12;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
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
	zephir_array_fetch_string(&name, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2535);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
		zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0, &name, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Mvc/Model/Query.zep", 2542);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&arguments);
	_6 = zephir_array_isset_string_fetch(&arguments, &expr, SL("arguments"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		_7$$4 = zephir_array_isset_value_string(&expr, SL("distinct"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_7$$4) {
			distinct = 1;
		} else {
			distinct = 0;
		}
		_8$$4 = zephir_array_isset_value_long(&arguments, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_8$$4) {
			ZEPHIR_INIT_VAR(&functionArgs);
			array_init(&functionArgs);
			if (Z_TYPE_P(&arguments) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_10$$7);
				zephir_string_to_char_array(&_10$$7, &arguments);
				_9$$7 = &_10$$7;
			} else {
				_9$$7 = &arguments;
			}
			zephir_is_iterable(_9$$7, 0, "phalcon/Mvc/Model/Query.zep", 2559);
			if (Z_TYPE_P(_9$$7) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$7), _11$$7)
				{
					ZEPHIR_INIT_NVAR(&argument);
					ZVAL_COPY(&argument, _11$$7);
					ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "getCallArgument", &_13, 0, &argument);
					zephir_check_call_status();
					zephir_array_append(&functionArgs, &_12$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2557);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _9$$7, "rewind", NULL, 0);
				zephir_check_call_status();
				_15$$7 = 1;
				while (1) {
					if (_15$$7) {
						_15$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _9$$7, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_14$$7, _9$$7, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&argument, _9$$7, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_16$$9, this_ptr, "getCallArgument", &_13, 0, &argument);
						zephir_check_call_status();
						zephir_array_append(&functionArgs, &_16$$9, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2557);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			ZEPHIR_INIT_VAR(&_17$$10);
			zephir_create_array(&_17$$10, 1, 0);
			ZEPHIR_CALL_METHOD(&_18$$10, this_ptr, "getCallArgument", &_13, 0, &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&_17$$10, &_18$$10);
			ZEPHIR_CPY_WRT(&functionArgs, &_17$$10);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_19$$11);
			zephir_array_fetch_string(&_19$$11, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2569);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(return_value, SL("name"), &_19$$11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_20$$11);
			ZVAL_LONG(&_20$$11, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_20$$11, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_21$$12);
			zephir_array_fetch_string(&_21$$12, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2576);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(return_value, SL("name"), &_21$$12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	zephir_memory_observe(&_22);
	zephir_array_fetch_string(&_22, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2585);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("name"), &_22, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * Returns a processed group clause for a SELECT statement
 *
 * @phpstan-param array<array-key, mixed> $group
 * @phpstan-return list<array<array-key, mixed>>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getGroupClause)
{
	zend_bool _0, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, *_1$$3, _4$$3, _2$$4, _6$$5, _7$$6, _8$$6;
	zval group, groupParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(group, group_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &group_param);
	zephir_get_arrval(&group, group_param);
	_0 = zephir_array_isset_value_long(&group, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&groupParts);
		array_init(&groupParts);
		zephir_is_iterable(&group, 0, "phalcon/Mvc/Model/Query.zep", 2608);
		if (Z_TYPE_P(&group) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&group), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&groupItem);
				ZVAL_COPY(&groupItem, _1$$3);
				ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getExpression", &_3, 0, &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupParts, &_2$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2606);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &group, "rewind", NULL, 0);
			zephir_check_call_status();
			_5$$3 = 1;
			while (1) {
				if (_5$$3) {
					_5$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &group, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_4$$3, &group, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&groupItem, &group, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getExpression", &_3, 0, &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupParts, &_6$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2606);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_create_array(&_7$$6, 1, 0);
		ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "getExpression", &_3, 0, &group);
		zephir_check_call_status();
		zephir_array_fast_append(&_7$$6, &_8$$6);
		ZEPHIR_CPY_WRT(&groupParts, &_7$$6);
	}
	RETURN_CTOR(&groupParts);
}

/**
 * Resolves a JOIN clause checking if the associated models exist
 *
 * @phpstan-param array<array-key, mixed> $join
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoin)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval join;
	zval *manager, manager_sub, *join_param = NULL, qualified, modelName, source, model, schema, _2, _1$$3;

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&qualified);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
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
	_0 = zephir_array_isset_string_fetch(&qualified, &join, SL("qualified"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_memory_observe(&_1$$3);
		zephir_array_fetch_string(&_1$$3, &qualified, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2627);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(&_1$$3, 355)) {
			zephir_memory_observe(&modelName);
			zephir_array_fetch_string(&modelName, &qualified, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2628);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
			zephir_check_call_status();
			zephir_create_array(return_value, 4, 0);
			zephir_array_update_string(return_value, SL("schema"), &schema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("source"), &source, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("modelName"), &modelName, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("model"), &model, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model/Query.zep", 2643);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Processes the JOINs in the query returning an internal representation for
 * the database dialect
 *
 * @phpstan-param mvc_query_ir $select
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoins)
{
	zend_string *_31, *_55, *_38$$19, *_58$$23, *_82$$38;
	zend_ulong _30, _54, _37$$19, _57$$23, _81$$38;
	zend_bool _1, _2, _18, _47, _79, _8$$7, _9$$8, _13$$10, _20$$12, _21$$13, _25$$15, _32$$17, _59$$24, _68$$29, _73$$32, _83$$39, _90$$44, _95$$47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_12 = NULL, *_16 = NULL, *_24 = NULL, *_28 = NULL, *_34 = NULL, *_60 = NULL, *_61 = NULL, *_64 = NULL, *_66 = NULL, *_67 = NULL, *_84 = NULL, *_85 = NULL, *_88 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select_param = NULL, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, _0, *_3, _4, *_5, _17, *_29, *_41, _42, *_43, _46, *_50, _51, _52, *_53, _78, _10$$9, _11$$9, _14$$11, _15$$11, _19$$12, _22$$14, _23$$14, _26$$16, _27$$16, _33$$18, _35$$19, *_36$$19, _44$$21, _45$$21, _48$$22, _49$$22, *_56$$23, _62$$28, _63$$28, _65$$29, *_69$$32, _70$$32, *_71$$32, _72$$32, _75$$36, *_80$$38, _86$$43, _87$$43, _89$$44, *_91$$47, _92$$47, *_93$$47, _94$$47, _97$$51;
	zval select, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, _39$$20, _40$$20, _74$$36, _76$$37, _77$$37, _96$$51, _98$$52, _99$$52;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&joinModels);
	ZVAL_UNDEF(&joinSources);
	ZVAL_UNDEF(&joinTypes);
	ZVAL_UNDEF(&joinPreCondition);
	ZVAL_UNDEF(&joinPrepared);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_40$$20);
	ZVAL_UNDEF(&_74$$36);
	ZVAL_UNDEF(&_76$$37);
	ZVAL_UNDEF(&_77$$37);
	ZVAL_UNDEF(&_96$$51);
	ZVAL_UNDEF(&_98$$52);
	ZVAL_UNDEF(&_99$$52);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_78);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_45$$21);
	ZVAL_UNDEF(&_48$$22);
	ZVAL_UNDEF(&_49$$22);
	ZVAL_UNDEF(&_62$$28);
	ZVAL_UNDEF(&_63$$28);
	ZVAL_UNDEF(&_65$$29);
	ZVAL_UNDEF(&_70$$32);
	ZVAL_UNDEF(&_72$$32);
	ZVAL_UNDEF(&_75$$36);
	ZVAL_UNDEF(&_86$$43);
	ZVAL_UNDEF(&_87$$43);
	ZVAL_UNDEF(&_89$$44);
	ZVAL_UNDEF(&_92$$47);
	ZVAL_UNDEF(&_94$$47);
	ZVAL_UNDEF(&_97$$51);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1089, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&models, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1090, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1091, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModels, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1092, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlModelsAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1093, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1088, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&tables);
	zephir_array_fetch_string(&tables, &select, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2682);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&selectTables);
		zephir_create_array(&selectTables, 1, 0);
		zephir_array_fast_append(&selectTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectTables, &tables);
	}
	zephir_memory_observe(&joins);
	zephir_array_fetch_string(&joins, &select, SL("joins"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2690);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value_long(&joins, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&selectJoins);
		zephir_create_array(&selectJoins, 1, 0);
		zephir_array_fast_append(&selectJoins, &joins);
	} else {
		ZEPHIR_CPY_WRT(&selectJoins, &joins);
	}
	if (Z_TYPE_P(&selectJoins) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &selectJoins);
		_3 = &_4;
	} else {
		_3 = &selectJoins;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model/Query.zep", 2837);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&joinItem);
			ZVAL_COPY(&joinItem, _5);
			ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getJoin", &_6, 0, &manager, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&source);
			zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2704);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&schema);
			zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2705);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&model);
			zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2706);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&realModelName);
			zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2707);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&completeSource);
			zephir_create_array(&completeSource, 2, 0);
			zephir_array_fast_append(&completeSource, &source);
			zephir_array_fast_append(&completeSource, &schema);
			ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getJoinType", &_7, 0, &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&aliasExpr);
			_8$$7 = zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_8$$7) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2719);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_9$$8 = zephir_array_isset_value(&joinModels, &alias);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_9$$8)) {
					ZEPHIR_INIT_NVAR(&_10$$9);
					object_init_ex(&_10$$9, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_11$$9, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_10$$9, "__construct", &_12, 0, &alias, &_11$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$9, "phalcon/Mvc/Model/Query.zep", 2725);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2731);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinTypes, &alias, &joinType, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinSources, &alias, &completeSource, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinPrepared, &alias, &joinItem, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				_13$$10 = zephir_array_isset_value(&joinModels, &realModelName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_13$$10)) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					object_init_ex(&_14$$11, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_15$$11, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", &_16, 0, &realModelName, &_15$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$11, "phalcon/Mvc/Model/Query.zep", 2782);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinTypes, &realModelName, &joinType, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinModels, &realModelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinSources, &realModelName, &completeSource, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&joinPrepared, &realModelName, &joinItem, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&joinItem, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&joinData, this_ptr, "getJoin", &_6, 0, &manager, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &joinData, SL("source"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2704);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&schema);
				zephir_array_fetch_string(&schema, &joinData, SL("schema"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2705);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&model);
				zephir_array_fetch_string(&model, &joinData, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2706);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&realModelName);
				zephir_array_fetch_string(&realModelName, &joinData, SL("modelName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2707);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_19$$12);
				zephir_create_array(&_19$$12, 2, 0);
				zephir_array_fast_append(&_19$$12, &source);
				zephir_array_fast_append(&_19$$12, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_19$$12);
				ZEPHIR_CALL_METHOD(&joinType, this_ptr, "getJoinType", &_7, 0, &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&aliasExpr);
				_20$$12 = zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_20$$12) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2719);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_21$$13 = zephir_array_isset_value(&joinModels, &alias);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_21$$13)) {
						ZEPHIR_INIT_NVAR(&_22$$14);
						object_init_ex(&_22$$14, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_23$$14, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_22$$14, "__construct", &_24, 0, &alias, &_23$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$14, "phalcon/Mvc/Model/Query.zep", 2725);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2731);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinTypes, &alias, &joinType, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &realModelName, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &alias, &realModelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &realModelName, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinSources, &alias, &completeSource, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinPrepared, &alias, &joinItem, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					_25$$15 = zephir_array_isset_value(&joinModels, &realModelName);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_25$$15)) {
						ZEPHIR_INIT_NVAR(&_26$$16);
						object_init_ex(&_26$$16, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_27$$16, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_26$$16, "__construct", &_28, 0, &realModelName, &_27$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_26$$16, "phalcon/Mvc/Model/Query.zep", 2782);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinTypes, &realModelName, &joinType, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &realModelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinModels, &realModelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &realModelName, &realModelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &realModelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinSources, &realModelName, &completeSource, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&joinPrepared, &realModelName, &joinItem, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_update_zval(&modelsInstances, &realModelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&joinItem);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1089, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1090, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1091, &sqlAliasesModels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1092, &sqlModelsAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1093, &sqlAliasesModelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1088, &modelsInstances);
	zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2857);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _30, _31, _29)
	{
		ZEPHIR_INIT_NVAR(&joinAliasName);
		if (_31 != NULL) { 
			ZVAL_STR_COPY(&joinAliasName, _31);
		} else {
			ZVAL_LONG(&joinAliasName, _30);
		}
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _29);
		ZEPHIR_OBS_NVAR(&joinExpr);
		_32$$17 = zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_32$$17) {
			ZEPHIR_CALL_METHOD(&_33$$18, this_ptr, "getExpression", &_34, 0, &joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_33$$18, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 1073, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_35$$19);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2869);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _37$$19, _38$$19, _36$$19)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_38$$19 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _38$$19);
			} else {
				ZVAL_LONG(&joinAliasName, _37$$19);
			}
			ZEPHIR_INIT_NVAR(&_35$$19);
			ZVAL_COPY(&_35$$19, _36$$19);
			ZEPHIR_OBS_NVAR(&joinType);
			zephir_array_fetch(&joinType, &joinTypes, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2859);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&joinSource);
			zephir_array_fetch(&joinSource, &joinSources, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2860);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&preCondition);
			zephir_array_fetch(&preCondition, &joinPreCondition, &joinAliasName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2861);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_39$$20);
			zephir_create_array(&_39$$20, 3, 0);
			zephir_array_update_string(&_39$$20, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_39$$20, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_40$$20);
			zephir_create_array(&_40$$20, 1, 0);
			zephir_array_fast_append(&_40$$20, &preCondition);
			zephir_array_update_string(&_39$$20, SL("conditions"), &_40$$20, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, &_39$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2866);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_35$$19);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	if (Z_TYPE_P(&selectTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_42);
		zephir_string_to_char_array(&_42, &selectTables);
		_41 = &_42;
	} else {
		_41 = &selectTables;
	}
	zephir_is_iterable(_41, 0, "phalcon/Mvc/Model/Query.zep", 2884);
	if (Z_TYPE_P(_41) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41), _43)
		{
			ZEPHIR_INIT_NVAR(&tableItem);
			ZVAL_COPY(&tableItem, _43);
			ZEPHIR_OBS_NVAR(&_44$$21);
			zephir_array_fetch_string(&_44$$21, &tableItem, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_45$$21);
			zephir_array_fetch_string(&_45$$21, &_44$$21, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&fromModels, &_45$$21, &__$true, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _41, "rewind", NULL, 0);
		zephir_check_call_status();
		_47 = 1;
		while (1) {
			if (_47) {
				_47 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _41, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_46, _41, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_46)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&tableItem, _41, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_48$$22);
				zephir_array_fetch_string(&_48$$22, &tableItem, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_49$$22);
				zephir_array_fetch_string(&_49$$22, &_48$$22, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&fromModels, &_49$$22, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&tableItem);
	if (Z_TYPE_P(&fromModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_51);
		zephir_string_to_char_array(&_51, &fromModels);
		_50 = &_51;
	} else {
		_50 = &fromModels;
	}
	ZEPHIR_INIT_VAR(&_52);
	zephir_is_iterable(_50, 0, "phalcon/Mvc/Model/Query.zep", 3002);
	if (Z_TYPE_P(_50) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_50), _54, _55, _53)
		{
			ZEPHIR_INIT_NVAR(&fromModelName);
			if (_55 != NULL) { 
				ZVAL_STR_COPY(&fromModelName, _55);
			} else {
				ZVAL_LONG(&fromModelName, _54);
			}
			ZEPHIR_INIT_NVAR(&_52);
			ZVAL_COPY(&_52, _53);
			zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 3000);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _57$$23, _58$$23, _56$$23)
			{
				ZEPHIR_INIT_NVAR(&joinAlias);
				if (_58$$23 != NULL) { 
					ZVAL_STR_COPY(&joinAlias, _58$$23);
				} else {
					ZVAL_LONG(&joinAlias, _57$$23);
				}
				ZEPHIR_INIT_NVAR(&joinModel);
				ZVAL_COPY(&joinModel, _56$$23);
				ZEPHIR_OBS_NVAR(&joinSource);
				zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2889);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&joinType);
				zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2894);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&preCondition);
				_59$$24 = zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_59$$24)) {
					ZEPHIR_OBS_NVAR(&modelNameAlias);
					zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2903);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_60, 0, &fromModelName, &modelNameAlias);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
						ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_61, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (Z_TYPE_P(&relations) == IS_ARRAY) {
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_62$$28);
								object_init_ex(&_62$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_63$$28, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_62$$28, "__construct", &_64, 0, &fromModelName, &joinModel, &_63$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_62$$28, "phalcon/Mvc/Model/Query.zep", 2927);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2933);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
					if (Z_TYPE_P(&relation) == IS_OBJECT) {
						ZEPHIR_OBS_NVAR(&modelAlias);
						zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2944);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_65$$29, &relation, "isThrough", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_is_true(&_65$$29))) {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getSingleJoin", &_66, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getMultiJoin", &_67, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						}
						_68$$29 = zephir_array_isset_value_long(&sqlJoin, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_68$$29) {
							if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_70$$32);
								zephir_string_to_char_array(&_70$$32, &sqlJoin);
								_69$$32 = &_70$$32;
							} else {
								_69$$32 = &sqlJoin;
							}
							zephir_is_iterable(_69$$32, 0, "phalcon/Mvc/Model/Query.zep", 2974);
							if (Z_TYPE_P(_69$$32) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_69$$32), _71$$32)
								{
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
									ZVAL_COPY(&sqlJoinItem, _71$$32);
									zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _69$$32, "rewind", NULL, 0);
								zephir_check_call_status();
								_73$$32 = 1;
								while (1) {
									if (_73$$32) {
										_73$$32 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _69$$32, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_72$$32, _69$$32, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_72$$32)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&sqlJoinItem, _69$$32, "current", NULL, 0);
									zephir_check_call_status();
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
								}
							}
							ZEPHIR_INIT_NVAR(&sqlJoinItem);
						} else {
							zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2975);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_INIT_NVAR(&_74$$36);
						zephir_create_array(&_74$$36, 3, 0);
						zephir_array_update_string(&_74$$36, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_74$$36, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_75$$36);
						array_init(&_75$$36);
						zephir_array_update_string(&_74$$36, SL("conditions"), &_75$$36, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_74$$36, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2986);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_INIT_NVAR(&_76$$37);
					zephir_create_array(&_76$$37, 3, 0);
					zephir_array_update_string(&_76$$37, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_76$$37, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_77$$37);
					zephir_create_array(&_77$$37, 1, 0);
					zephir_array_fast_append(&_77$$37, &preCondition);
					zephir_array_update_string(&_76$$37, SL("conditions"), &_77$$37, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_76$$37, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2997);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&joinModel);
			ZEPHIR_INIT_NVAR(&joinAlias);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _50, "rewind", NULL, 0);
		zephir_check_call_status();
		_79 = 1;
		while (1) {
			if (_79) {
				_79 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _50, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_78, _50, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_78)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&fromModelName, _50, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_52, _50, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 3000);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _81$$38, _82$$38, _80$$38)
				{
					ZEPHIR_INIT_NVAR(&joinAlias);
					if (_82$$38 != NULL) { 
						ZVAL_STR_COPY(&joinAlias, _82$$38);
					} else {
						ZVAL_LONG(&joinAlias, _81$$38);
					}
					ZEPHIR_INIT_NVAR(&joinModel);
					ZVAL_COPY(&joinModel, _80$$38);
					ZEPHIR_OBS_NVAR(&joinSource);
					zephir_array_fetch(&joinSource, &joinSources, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2889);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&joinType);
					zephir_array_fetch(&joinType, &joinTypes, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2894);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&preCondition);
					_83$$39 = zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_83$$39)) {
						ZEPHIR_OBS_NVAR(&modelNameAlias);
						zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2903);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_84, 0, &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_85, 0, &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (Z_TYPE_P(&relations) == IS_ARRAY) {
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_86$$43);
									object_init_ex(&_86$$43, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_87$$43, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_86$$43, "__construct", &_88, 0, &fromModelName, &joinModel, &_87$$43);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_86$$43, "phalcon/Mvc/Model/Query.zep", 2927);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2933);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_OBS_NVAR(&modelAlias);
							zephir_array_fetch(&modelAlias, &sqlModelsAliases, &fromModelName, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2944);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&_89$$44, &relation, "isThrough", NULL, 0);
							zephir_check_call_status();
							if (!(zephir_is_true(&_89$$44))) {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getSingleJoin", &_66, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&sqlJoin, this_ptr, "getMultiJoin", &_67, 0, &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							}
							_90$$44 = zephir_array_isset_value_long(&sqlJoin, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_90$$44) {
								if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_92$$47);
									zephir_string_to_char_array(&_92$$47, &sqlJoin);
									_91$$47 = &_92$$47;
								} else {
									_91$$47 = &sqlJoin;
								}
								zephir_is_iterable(_91$$47, 0, "phalcon/Mvc/Model/Query.zep", 2974);
								if (Z_TYPE_P(_91$$47) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_91$$47), _93$$47)
									{
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
										ZVAL_COPY(&sqlJoinItem, _93$$47);
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD(NULL, _91$$47, "rewind", NULL, 0);
									zephir_check_call_status();
									_95$$47 = 1;
									while (1) {
										if (_95$$47) {
											_95$$47 = 0;
										} else {
											ZEPHIR_CALL_METHOD(NULL, _91$$47, "next", NULL, 0);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD(&_94$$47, _91$$47, "valid", NULL, 0);
										zephir_check_call_status();
										if (!zend_is_true(&_94$$47)) {
											break;
										}
										ZEPHIR_CALL_METHOD(&sqlJoinItem, _91$$47, "current", NULL, 0);
										zephir_check_call_status();
											zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
									}
								}
								ZEPHIR_INIT_NVAR(&sqlJoinItem);
							} else {
								zephir_array_append(&sqlJoins, &sqlJoin, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2975);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} else {
							ZEPHIR_INIT_NVAR(&_96$$51);
							zephir_create_array(&_96$$51, 3, 0);
							zephir_array_update_string(&_96$$51, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_96$$51, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_97$$51);
							array_init(&_97$$51);
							zephir_array_update_string(&_96$$51, SL("conditions"), &_97$$51, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_96$$51, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2986);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_INIT_NVAR(&_98$$52);
						zephir_create_array(&_98$$52, 3, 0);
						zephir_array_update_string(&_98$$52, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_98$$52, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_99$$52);
						zephir_create_array(&_99$$52, 1, 0);
						zephir_array_fast_append(&_99$$52, &preCondition);
						zephir_array_update_string(&_98$$52, SL("conditions"), &_99$$52, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_98$$52, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2997);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&joinModel);
				ZEPHIR_INIT_NVAR(&joinAlias);
		}
	}
	ZEPHIR_INIT_NVAR(&_52);
	ZEPHIR_INIT_NVAR(&fromModelName);
	RETURN_CTOR(&sqlJoins);
}

/**
 * Resolves a JOIN type
 *
 * @phpstan-param array<array-key, mixed> $join
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getJoinType)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *join_param = NULL, type, _2, _3, _1$$3;
	zval join;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
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
	_0 = zephir_array_isset_string_fetch(&type, &join, SL("type"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3015);
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

	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_query_exceptions_unknownjointype_ce);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0, &type, &_3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/Mvc/Model/Query.zep", 3035);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Returns a processed limit clause for a SELECT statement
 *
 * @phpstan-param array<array-key, mixed> $limitClause
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getLimitClause)
{
	zend_bool _0, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limitClause_param = NULL, number, offset, _1$$3, _4$$4;
	zval limitClause, limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limitClause);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
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
	_0 = zephir_array_isset_string_fetch(&number, &limitClause, SL("number"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getExpression", &_2, 0, &number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_1$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&offset);
	_3 = zephir_array_isset_string_fetch(&offset, &limitClause, SL("offset"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "getExpression", &_2, 0, &offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_4$$4, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&limit);
}

/**
 * Resolves joins involving many-to-many relations
 *
 * @param string joinSource
 *
 * @phpstan-param array<array-key, mixed>|string $joinSource
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getMultiJoin)
{
	zend_bool _15$$3, _6$$4, _16$$6;
	zend_ulong _4$$3;
	zval sqlJoins, _11$$4, _13$$4, _22$$6, _23$$6, _25$$8, _26$$8, _27$$8, _29$$8, _30$$8, _31$$8, _32$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, _0, *_1$$3, _2$$3, *_3$$3, _14$$3, _10$$4, _7$$5, _8$$5, _20$$6, _21$$6, _17$$7, _18$$7, _24$$8, _28$$8;
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
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
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
	ZEPHIR_CALL_METHOD(&fields, relation, "getFields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getReferencedFields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getIntermediateModel", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", NULL, 0, &intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSource, &intermediateModel, "getSource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateSchema, &intermediateModel, "getSchema", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("sqlAliases"), &intermediateModelName, &intermediateSource);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("sqlAliasesModelsInstances"), &intermediateModelName, &intermediateModel);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getIntermediateFields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getIntermediateReferencedFields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedModelName, relation, "getReferencedModel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &fields);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = &fields;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Mvc/Model/Query.zep", 3174);
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
				_6$$4 = zephir_array_isset_value(&referencedFields, &position);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_6$$4))) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					object_init_ex(&_7$$5, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", &_9, 0, &modelAlias_zv, &joinAlias_zv, &_8$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$5, "phalcon/Mvc/Model/Query.zep", 3142);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&intermediateField);
				zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3148);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&sqlEqualsJoinCondition);
				zephir_create_array(&sqlEqualsJoinCondition, 4, 0);
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&sqlEqualsJoinCondition, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_11$$4);
				zephir_create_array(&_11$$4, 3, 0);
				add_assoc_long_ex(&_11$$4, SL("type"), 355);
				zephir_array_update_string(&_11$$4, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getQualified", &_12, 0, &_11$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_10$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$4);
				zephir_create_array(&_13$$4, 3, 0);
				add_assoc_stringl_ex(&_13$$4, SL("type"), SL("qualified"));
				zephir_array_update_string(&_13$$4, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_13$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getQualified", &_12, 0, &_13$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_10$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_15$$3 = 1;
			while (1) {
				if (_15$$3) {
					_15$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _1$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_14$$3, _1$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _1$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&position, _1$$3, "current", NULL, 0);
				zephir_check_call_status();
					_16$$6 = zephir_array_isset_value(&referencedFields, &position);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_16$$6))) {
						ZEPHIR_INIT_NVAR(&_17$$7);
						object_init_ex(&_17$$7, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_18$$7, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_17$$7, "__construct", &_19, 0, &modelAlias_zv, &joinAlias_zv, &_18$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$7, "phalcon/Mvc/Model/Query.zep", 3142);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&intermediateField);
					zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3148);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_20$$6);
					zephir_create_array(&_20$$6, 4, 0);
					add_assoc_stringl_ex(&_20$$6, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_20$$6, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_22$$6);
					zephir_create_array(&_22$$6, 3, 0);
					add_assoc_long_ex(&_22$$6, SL("type"), 355);
					zephir_array_update_string(&_22$$6, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_22$$6, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_21$$6, this_ptr, "getQualified", &_12, 0, &_22$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_20$$6, SL("left"), &_21$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$6);
					zephir_create_array(&_23$$6, 3, 0);
					add_assoc_stringl_ex(&_23$$6, SL("type"), SL("qualified"));
					zephir_array_update_string(&_23$$6, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_23$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_21$$6, this_ptr, "getQualified", &_12, 0, &_23$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_20$$6, SL("right"), &_21$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlEqualsJoinCondition, &_20$$6);
			}
		}
		ZEPHIR_INIT_NVAR(&position);
		ZEPHIR_INIT_NVAR(&field);
	} else {
		ZEPHIR_INIT_VAR(&_24$$8);
		zephir_create_array(&_24$$8, 2, 0);
		ZEPHIR_INIT_VAR(&_25$$8);
		zephir_create_array(&_25$$8, 3, 0);
		zephir_array_update_string(&_25$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_26$$8);
		zephir_create_array(&_26$$8, 2, 0);
		zephir_array_fast_append(&_26$$8, &intermediateSource);
		zephir_array_fast_append(&_26$$8, &intermediateSchema);
		zephir_array_update_string(&_25$$8, SL("source"), &_26$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		zephir_create_array(&_26$$8, 1, 0);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 4, 0);
		add_assoc_stringl_ex(&_27$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_27$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_29$$8);
		zephir_create_array(&_29$$8, 3, 0);
		add_assoc_long_ex(&_29$$8, SL("type"), 355);
		zephir_array_update_string(&_29$$8, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_29$$8, SL("name"), &fields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "getQualified", &_12, 0, &_29$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_27$$8, SL("left"), &_28$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_30$$8);
		zephir_create_array(&_30$$8, 3, 0);
		add_assoc_stringl_ex(&_30$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_30$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_30$$8, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "getQualified", &_12, 0, &_30$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_27$$8, SL("right"), &_28$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_26$$8, &_27$$8);
		zephir_array_update_string(&_25$$8, SL("conditions"), &_26$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_24$$8, &_25$$8);
		ZEPHIR_INIT_NVAR(&_25$$8);
		zephir_create_array(&_25$$8, 3, 0);
		zephir_array_update_string(&_25$$8, SL("type"), &joinType_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_25$$8, SL("source"), joinSource, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_26$$8);
		zephir_create_array(&_26$$8, 1, 0);
		ZEPHIR_INIT_NVAR(&_27$$8);
		zephir_create_array(&_27$$8, 4, 0);
		add_assoc_stringl_ex(&_27$$8, SL("type"), SL("binary-op"));
		add_assoc_stringl_ex(&_27$$8, SL("op"), SL("="));
		ZEPHIR_INIT_VAR(&_31$$8);
		zephir_create_array(&_31$$8, 3, 0);
		add_assoc_long_ex(&_31$$8, SL("type"), 355);
		zephir_array_update_string(&_31$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_31$$8, SL("name"), &intermediateReferencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "getQualified", &_12, 0, &_31$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_27$$8, SL("left"), &_28$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_32$$8);
		zephir_create_array(&_32$$8, 3, 0);
		add_assoc_stringl_ex(&_32$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_32$$8, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_32$$8, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "getQualified", &_12, 0, &_32$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_27$$8, SL("right"), &_28$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_26$$8, &_27$$8);
		zephir_array_update_string(&_25$$8, SL("conditions"), &_26$$8, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_24$$8, &_25$$8);
		ZEPHIR_CPY_WRT(&sqlJoins, &_24$$8);
	}
	RETURN_CTOR(&sqlJoins);
}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array|string order
 *
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getOrderClause)
{
	zend_bool _0, _12, _6$$5, _14$$10;
	zval orderParts, orderPartSort;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderItem, orderPartExpr, orderSort, *_1, _2, *_3, _11, _4$$5, _7$$7, _8$$8, _9$$8, _10$$9, _13$$10, _15$$12, _16$$12, _17$$13, _18$$13, _19$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&orderParts);
	ZVAL_UNDEF(&orderPartSort);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(order)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &order);
	_0 = zephir_array_isset_value_long(order, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&orderColumns);
		zephir_create_array(&orderColumns, 1, 0);
		zephir_array_fast_append(&orderColumns, order);
	} else {
		ZEPHIR_CPY_WRT(&orderColumns, order);
	}
	ZEPHIR_INIT_VAR(&orderParts);
	array_init(&orderParts);
	if (Z_TYPE_P(&orderColumns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &orderColumns);
		_1 = &_2;
	} else {
		_1 = &orderColumns;
	}
	zephir_is_iterable(_1, 0, "phalcon/Mvc/Model/Query.zep", 3284);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1), _3)
		{
			ZEPHIR_INIT_NVAR(&orderItem);
			ZVAL_COPY(&orderItem, _3);
			ZEPHIR_OBS_NVAR(&_4$$5);
			zephir_array_fetch_string(&_4$$5, &orderItem, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3266);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getExpression", &_5, 0, &_4$$5);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&orderSort);
			_6$$5 = zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_6$$5) {
				if (ZEPHIR_IS_LONG(&orderSort, 327)) {
					ZEPHIR_INIT_NVAR(&orderPartSort);
					zephir_create_array(&orderPartSort, 2, 0);
					zephir_array_fast_append(&orderPartSort, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_7$$7);
					ZVAL_STRING(&_7$$7, "ASC");
					zephir_array_fast_append(&orderPartSort, &_7$$7);
				} else {
					ZEPHIR_INIT_NVAR(&_8$$8);
					zephir_create_array(&_8$$8, 2, 0);
					zephir_array_fast_append(&_8$$8, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZVAL_STRING(&_9$$8, "DESC");
					zephir_array_fast_append(&_8$$8, &_9$$8);
					ZEPHIR_CPY_WRT(&orderPartSort, &_8$$8);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_10$$9);
				zephir_create_array(&_10$$9, 1, 0);
				zephir_array_fast_append(&_10$$9, &orderPartExpr);
				ZEPHIR_CPY_WRT(&orderPartSort, &_10$$9);
			}
			zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3281);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
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
			ZEPHIR_CALL_METHOD(&orderItem, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_13$$10);
				zephir_array_fetch_string(&_13$$10, &orderItem, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3266);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&orderPartExpr, this_ptr, "getExpression", &_5, 0, &_13$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&orderSort);
				_14$$10 = zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_14$$10) {
					if (ZEPHIR_IS_LONG(&orderSort, 327)) {
						ZEPHIR_INIT_NVAR(&_15$$12);
						zephir_create_array(&_15$$12, 2, 0);
						zephir_array_fast_append(&_15$$12, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_16$$12);
						ZVAL_STRING(&_16$$12, "ASC");
						zephir_array_fast_append(&_15$$12, &_16$$12);
						ZEPHIR_CPY_WRT(&orderPartSort, &_15$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_17$$13);
						zephir_create_array(&_17$$13, 2, 0);
						zephir_array_fast_append(&_17$$13, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_18$$13);
						ZVAL_STRING(&_18$$13, "DESC");
						zephir_array_fast_append(&_17$$13, &_18$$13);
						ZEPHIR_CPY_WRT(&orderPartSort, &_17$$13);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$14);
					zephir_create_array(&_19$$14, 1, 0);
					zephir_array_fast_append(&_19$$14, &orderPartExpr);
					ZEPHIR_CPY_WRT(&orderPartSort, &_19$$14);
				}
				zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3281);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&orderItem);
	RETURN_CTOR(&orderParts);
}

/**
 * Replaces the model's name to its source name in a qualified-name
 * expression
 *
 * @phpstan-param array<array-key, mixed> $expr
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getQualified)
{
	zend_bool _1, _4, _5, _6, _7, _8, _10, _12$$6, _19$$8, _22$$11, _35$$14, _47$$14, _52$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_30 = NULL, *_33 = NULL, *_37 = NULL, *_40 = NULL, *_44 = NULL, *_56 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _0, _9, _2$$3, _3$$3, _11$$6, _16$$6, _17$$6, _13$$7, _14$$7, _15$$7, _18$$8, _20$$9, _21$$9, _23$$12, _24$$12, _25$$14, *_26$$14, _27$$14, *_28$$14, _34$$14, _45$$14, _50$$14, _51$$14, _29$$15, _31$$17, _32$$17, _36$$18, _38$$20, _39$$20, _41$$21, _42$$21, _43$$21, _46$$22, _48$$23, _49$$23, _53$$27, _54$$27, _55$$27;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_41$$21);
	ZVAL_UNDEF(&_42$$21);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_46$$22);
	ZVAL_UNDEF(&_48$$23);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_53$$27);
	ZVAL_UNDEF(&_54$$27);
	ZVAL_UNDEF(&_55$$27);
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
	zephir_array_fetch_string(&columnName, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3301);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1094, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&nestingLevel, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1095, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &nestingLevel);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 1095, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch(&_3$$3, &_2$$3, &nestingLevel, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3309);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAliases, &_3$$3);
	} else {
		ZEPHIR_INIT_NVAR(&sqlColumnAliases);
		array_init(&sqlColumnAliases);
	}
	_4 = zephir_array_isset_value(&sqlColumnAliases, &columnName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = _4;
	if (_5) {
		_6 = zephir_array_isset_value_string(&expr, SL("domain"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_7 = !(_6);
		if (!(_7)) {
			_8 = zephir_isempty_dim_string(&expr, SL("domain"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7 = _8;
		}
		_5 = _7;
	}
	if (_5) {
		zephir_create_array(return_value, 2, 0);
		add_assoc_stringl_ex(return_value, SL("type"), SL("qualified"));
		zephir_array_update_string(return_value, SL("name"), &columnName, PH_COPY | PH_SEPARATE);
		RETURN_MM();
	}
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_9);
	zephir_memory_observe(&columnDomain);
	_10 = zephir_array_isset_string_fetch(&columnDomain, &expr, SL("domain"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_10) {
		zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_3, 1090, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_11$$6);
		zephir_memory_observe(&source);
		_12$$6 = zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_12$$6))) {
			ZEPHIR_INIT_VAR(&_13$$7);
			object_init_ex(&_13$$7, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property_cached(&_14$$7, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$7);
			ZVAL_STRING(&_15$$7, "11");
			ZEPHIR_CALL_METHOD(NULL, &_13$$7, "__construct", NULL, 0, &columnDomain, &_15$$7, &_14$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$7, "phalcon/Mvc/Model/Query.zep", 3333);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_17$$6);
		ZVAL_STRING(&_17$$6, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_16$$6, phalcon_support_settings_ce, "get", NULL, 0, &_17$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_16$$6)) {
			zephir_read_property_cached(&_18$$8, this_ptr, _zephir_prop_5, 1093, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_18$$8);
			zephir_memory_observe(&model);
			_19$$8 = zephir_array_isset_fetch(&model, &sqlAliasesModelsInstances, &columnDomain, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_19$$8))) {
				ZEPHIR_INIT_VAR(&_20$$9);
				object_init_ex(&_20$$9, phalcon_mvc_model_query_exceptions_nomodelforalias_ce);
				zephir_read_property_cached(&_21$$9, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_20$$9, "__construct", NULL, 0, &columnDomain, &_21$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$9, "phalcon/Mvc/Model/Query.zep", 3350);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getReverseColumnMap", NULL, 0, &model);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			zephir_memory_observe(&realColumnName);
			_22$$11 = zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_22$$11))) {
				ZEPHIR_INIT_VAR(&_23$$12);
				object_init_ex(&_23$$12, phalcon_mvc_model_query_exceptions_columnnotindomain_ce);
				zephir_read_property_cached(&_24$$12, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_23$$12, "__construct", NULL, 0, &columnName, &columnDomain, &_24$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_23$$12, "phalcon/Mvc/Model/Query.zep", 3360);
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
		zephir_read_property_cached(&_25$$14, this_ptr, _zephir_prop_6, 1088, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_25$$14) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_27$$14);
			zephir_string_to_char_array(&_27$$14, &_25$$14);
			_26$$14 = &_27$$14;
		} else {
			_26$$14 = &_25$$14;
		}
		zephir_is_iterable(_26$$14, 0, "phalcon/Mvc/Model/Query.zep", 3392);
		if (Z_TYPE_P(_26$$14) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26$$14), _28$$14)
			{
				ZEPHIR_INIT_NVAR(&model);
				ZVAL_COPY(&model, _28$$14);
				ZEPHIR_CALL_METHOD(&_29$$15, &metaData, "hasAttribute", &_30, 0, &model, &columnName);
				zephir_check_call_status();
				if (zephir_is_true(&_29$$15)) {
					number++;
					if (UNEXPECTED(number > 1)) {
						ZEPHIR_INIT_NVAR(&_31$$17);
						object_init_ex(&_31$$17, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
						zephir_read_property_cached(&_32$$17, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_31$$17, "__construct", &_33, 0, &columnName, &_32$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_31$$17, "phalcon/Mvc/Model/Query.zep", 3381);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&hasModel, &model);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _26$$14, "rewind", NULL, 0);
			zephir_check_call_status();
			_35$$14 = 1;
			while (1) {
				if (_35$$14) {
					_35$$14 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _26$$14, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_34$$14, _26$$14, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_34$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&model, _26$$14, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_36$$18, &metaData, "hasAttribute", &_37, 0, &model, &columnName);
					zephir_check_call_status();
					if (zephir_is_true(&_36$$18)) {
						number++;
						if (UNEXPECTED(number > 1)) {
							ZEPHIR_INIT_NVAR(&_38$$20);
							object_init_ex(&_38$$20, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
							zephir_read_property_cached(&_39$$20, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_CALL_METHOD(NULL, &_38$$20, "__construct", &_40, 0, &columnName, &_39$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_38$$20, "phalcon/Mvc/Model/Query.zep", 3381);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&hasModel, &model);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&hasModel))) {
			ZEPHIR_INIT_VAR(&_41$$21);
			object_init_ex(&_41$$21, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
			zephir_read_property_cached(&_42$$21, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_43$$21);
			ZVAL_STRING(&_43$$21, "1");
			ZEPHIR_CALL_METHOD(NULL, &_41$$21, "__construct", &_44, 0, &columnName, &_43$$21, &_42$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_41$$21, "phalcon/Mvc/Model/Query.zep", 3393);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_45$$14, this_ptr, _zephir_prop_7, 1089, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&models, &_45$$14);
		if (UNEXPECTED(Z_TYPE_P(&models) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_46$$22);
			object_init_ex(&_46$$22, phalcon_mvc_model_query_exceptions_modelslistnotloaded_ce);
			ZEPHIR_CALL_METHOD(NULL, &_46$$22, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_46$$22, "phalcon/Mvc/Model/Query.zep", 3402);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0);
		ZEPHIR_OBS_NVAR(&source);
		_47$$14 = zephir_array_isset_fetch(&source, &models, &className, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_47$$14))) {
			ZEPHIR_INIT_VAR(&_48$$23);
			object_init_ex(&_48$$23, phalcon_mvc_model_query_exceptions_modelsourcenotfound_ce);
			zephir_read_property_cached(&_49$$23, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_48$$23, "__construct", NULL, 0, &className, &_49$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_48$$23, "phalcon/Mvc/Model/Query.zep", 3411);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_51$$14);
		ZVAL_STRING(&_51$$14, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC(&_50$$14, phalcon_support_settings_ce, "get", NULL, 0, &_51$$14);
		zephir_check_call_status();
		if (zephir_is_true(&_50$$14)) {
			ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getReverseColumnMap", NULL, 0, &hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&realColumnName);
			_52$$26 = zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_52$$26))) {
				ZEPHIR_INIT_VAR(&_53$$27);
				object_init_ex(&_53$$27, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
				zephir_read_property_cached(&_54$$27, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_55$$27);
				ZVAL_STRING(&_55$$27, "3");
				ZEPHIR_CALL_METHOD(NULL, &_53$$27, "__construct", &_56, 0, &columnName, &_55$$27, &_54$$27);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_53$$27, "phalcon/Mvc/Model/Query.zep", 3428);
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
 *
 * @phpstan-param mvc_query_ir|null $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1087, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getConnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectreadconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectReadConnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_readconnectionmissing_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3473);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getReadConnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Query the records on which the UPDATE/DELETE operation will be done
 *
 * @return ResultsetInterface
 *
 * @phpstan-param mvc_query_ir $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getRelatedRecords)
{
	zend_bool _5, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval intermediate, bindParams, bindTypes, _0, _1;
	zval *model, model_sub, *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, selectIr, joinConditions, whereConditions, limitConditions, query, _2, _3, _4, _8, _9;
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
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
	ZEPHIR_CALL_METHOD(&_3, model, "getSource", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("column"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(&selectIr, SL("columns"), &_0, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("models"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3507);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&selectIr, SL("models"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_string(&_4, &intermediate, SL("tables"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3509);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&selectIr, SL("tables"), &_4, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&joinConditions);
	_5 = zephir_array_isset_string_fetch(&joinConditions, &intermediate, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_array_update_string(&selectIr, SL("joins"), &joinConditions, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&whereConditions);
	_6 = zephir_array_isset_string_fetch(&whereConditions, &intermediate, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_6) {
		zephir_array_update_string(&selectIr, SL("where"), &whereConditions, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limitConditions);
	_7 = zephir_array_isset_string_fetch(&limitConditions, &intermediate, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_7) {
		zephir_array_update_string(&selectIr, SL("limit"), &limitConditions, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&query);
	object_init_ex(&query, phalcon_mvc_model_query_ce);
	ZEPHIR_CALL_METHOD(NULL, &query, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 1078, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &query, "setDI", NULL, 0, &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_9, 309);
	ZEPHIR_CALL_METHOD(NULL, &query, "setType", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &query, "setIntermediate", NULL, 0, &selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolves a column from its intermediate representation into an array
 * used to determine if the resultset produced is simple or complex
 *
 * @phpstan-param array<array-key, mixed> $column
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSelectColumn)
{
	zend_string *_9$$4;
	zend_ulong _8$$4;
	zend_bool _0, _3, _22, _16$$4, _26$$10, _30$$10, _31$$12, _37$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, columnData, balias, eager, _39, _1$$3, _4$$4, *_5$$4, _6$$4, *_7$$4, _15$$4, _10$$5, _11$$5, _12$$5, _14$$6, _17$$7, _18$$7, _19$$7, _20$$7, _21$$8, _23$$9, _25$$10, _34$$10, _27$$11, _28$$11, _29$$11, _32$$13, _33$$13, _35$$15, _36$$16, _38$$18;
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
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$15);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_38$$18);
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
	_0 = zephir_array_isset_string_fetch(&columnType, &column, SL("type"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_2, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3560);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	zephir_memory_observe(&eager);
	_3 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3;
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_0, 1089, PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4$$4) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_6$$4);
			zephir_string_to_char_array(&_6$$4, &_4$$4);
			_5$$4 = &_6$$4;
		} else {
			_5$$4 = &_4$$4;
		}
		zephir_is_iterable(_5$$4, 0, "phalcon/Mvc/Model/Query.zep", 3590);
		if (Z_TYPE_P(_5$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5$$4), _8$$4, _9$$4, _7$$4)
			{
				ZEPHIR_INIT_NVAR(&modelName);
				if (_9$$4 != NULL) { 
					ZVAL_STR_COPY(&modelName, _9$$4);
				} else {
					ZVAL_LONG(&modelName, _8$$4);
				}
				ZEPHIR_INIT_NVAR(&source);
				ZVAL_COPY(&source, _7$$4);
				ZEPHIR_INIT_NVAR(&sqlColumn);
				zephir_create_array(&sqlColumn, 4, 0);
				add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
				zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZEPHIR_INIT_NVAR(&_11$$5);
				ZVAL_STRING(&_11$$5, "\\");
				ZEPHIR_INIT_NVAR(&_12$$5);
				zephir_fast_strpos(&_12$$5, &modelName, &_11$$5, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_12$$5)) {
					ZEPHIR_CPY_WRT(&_10$$5, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&_10$$5, "lcfirst", &_13, 180, &modelName);
					zephir_check_call_status();
				}
				zephir_array_update_string(&sqlColumn, SL("balias"), &_10$$5, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&eager) != IS_NULL) {
					zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch_string(&_14$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3584);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&sqlColumn, SL("eagerType"), &_14$$6, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3587);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _5$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_16$$4 = 1;
			while (1) {
				if (_16$$4) {
					_16$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _5$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_15$$4, _5$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&modelName, _5$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, _5$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_17$$7);
					zephir_create_array(&_17$$7, 4, 0);
					add_assoc_stringl_ex(&_17$$7, SL("type"), SL("object"));
					zephir_array_update_string(&_17$$7, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$7, SL("column"), &source, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$7);
					ZEPHIR_INIT_NVAR(&_19$$7);
					ZVAL_STRING(&_19$$7, "\\");
					ZEPHIR_INIT_NVAR(&_20$$7);
					zephir_fast_strpos(&_20$$7, &modelName, &_19$$7, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_20$$7)) {
						ZEPHIR_CPY_WRT(&_18$$7, &modelName);
					} else {
						ZEPHIR_CALL_FUNCTION(&_18$$7, "lcfirst", &_13, 180, &modelName);
						zephir_check_call_status();
					}
					zephir_array_update_string(&_17$$7, SL("balias"), &_18$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlColumn, &_17$$7);
					if (Z_TYPE_P(&eager) != IS_NULL) {
						zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch_string(&_21$$8, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3584);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&sqlColumn, SL("eagerType"), &_21$$8, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3587);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&source);
		ZEPHIR_INIT_NVAR(&modelName);
		RETURN_CTOR(&sqlColumns);
	}
	_22 = zephir_array_isset_value_string(&column, SL("column"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_22))) {
		ZEPHIR_INIT_VAR(&_23$$9);
		object_init_ex(&_23$$9, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_23$$9, "__construct", &_24, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_23$$9, "phalcon/Mvc/Model/Query.zep", 3594);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		zephir_read_property_cached(&_25$$10, this_ptr, _zephir_prop_1, 1090, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliases, &_25$$10);
		zephir_memory_observe(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3606);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&source);
		_26$$10 = zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_26$$10))) {
			ZEPHIR_INIT_VAR(&_27$$11);
			object_init_ex(&_27$$11, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property_cached(&_28$$11, this_ptr, _zephir_prop_2, 1072, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_29$$11);
			ZVAL_STRING(&_29$$11, "2");
			ZEPHIR_CALL_METHOD(NULL, &_27$$11, "__construct", NULL, 0, &columnDomain, &_29$$11, &_28$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$11, "phalcon/Mvc/Model/Query.zep", 3609);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		zephir_memory_observe(&preparedAlias);
		_30$$10 = zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_30$$10;
		zephir_read_property_cached(&_25$$10, this_ptr, _zephir_prop_3, 1091, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&sqlAliasesModels, &_25$$10);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3623);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			_31$$12 = ZEPHIR_IS_EQUAL(&columnDomain, &modelName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_31$$12) {
				ZEPHIR_INIT_VAR(&_32$$13);
				ZVAL_STRING(&_32$$13, "\\");
				ZEPHIR_INIT_VAR(&_33$$13);
				zephir_fast_strpos(&_33$$13, &modelName, &_32$$13, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_33$$13)) {
					ZEPHIR_CPY_WRT(&preparedAlias, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_13, 180, &modelName);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_VAR(&_34$$10);
		zephir_create_array(&_34$$10, 4, 0);
		add_assoc_stringl_ex(&_34$$10, SL("type"), SL("object"));
		zephir_array_update_string(&_34$$10, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_34$$10, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_34$$10, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&sqlColumn, &_34$$10);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_35$$15, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3645);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_35$$15, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3648);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&sqlColumns);
	}
	if (ZEPHIR_IS_LONG(&columnType, 354)) {
		ZEPHIR_INIT_VAR(&_36$$16);
		zephir_create_array(&_36$$16, 1, 0);
		add_assoc_stringl_ex(&_36$$16, SL("type"), SL("scalar"));
		ZEPHIR_CPY_WRT(&sqlColumn, &_36$$16);
		zephir_memory_observe(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3662);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&sqlExprColumn, this_ptr, "getExpression", NULL, 0, &columnData);
		zephir_check_call_status();
		zephir_memory_observe(&balias);
		_37$$16 = zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_37$$16) {
			zephir_array_update_string(&sqlColumn, SL("balias"), &balias, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &balias, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_38$$18, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3675);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_38$$18, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_array_update_string(&sqlColumn, SL("column"), &sqlExprColumn, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3679);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&sqlColumns);
	}
	ZEPHIR_INIT_VAR(&_39);
	object_init_ex(&_39, phalcon_mvc_model_query_exceptions_unknowncolumntype_ce);
	ZEPHIR_CALL_METHOD(NULL, &_39, "__construct", NULL, 0, &columnType);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_39, "phalcon/Mvc/Model/Query.zep", 3684);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves joins involving has-one/belongs-to/has-many relations
 *
 * @param string joinSource
 *
 * @phpstan-return array<string, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleJoin)
{
	zend_bool _20$$4, _11$$5, _21$$7;
	zend_ulong _9$$4;
	zval _1$$3, _3$$3, _5$$3, _15$$5, _17$$5, _18$$5, _25$$7, _27$$7, _28$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_14 = NULL, *_24 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _0$$3, _2$$3, *_6$$4, _7$$4, *_8$$4, _19$$4, _16$$5, _12$$6, _13$$6, _26$$7, _22$$8, _23$$8;
	zend_string *joinType = NULL, *modelAlias = NULL, *joinAlias = NULL, *_10$$4;
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
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
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
	ZEPHIR_CALL_METHOD(&fields, relation, "getFields", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&referencedFields, relation, "getReferencedFields", NULL, 0);
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
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getQualified", &_4, 0, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("left"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 3, 0);
		add_assoc_stringl_ex(&_5$$3, SL("type"), SL("qualified"));
		zephir_array_update_string(&_5$$3, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_5$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getQualified", &_4, 0, &_5$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("right"), &_2$$3, PH_COPY | PH_SEPARATE);
		zephir_array_fast_append(&_0$$3, &_1$$3);
		ZEPHIR_CPY_WRT(&sqlJoinConditions, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&sqlJoinPartialConditions);
		array_init(&sqlJoinPartialConditions);
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_7$$4);
			zephir_string_to_char_array(&_7$$4, &fields);
			_6$$4 = &_7$$4;
		} else {
			_6$$4 = &fields;
		}
		zephir_is_iterable(_6$$4, 0, "phalcon/Mvc/Model/Query.zep", 3773);
		if (Z_TYPE_P(_6$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_6$$4), _9$$4, _10$$4, _8$$4)
			{
				ZEPHIR_INIT_NVAR(&position);
				if (_10$$4 != NULL) { 
					ZVAL_STR_COPY(&position, _10$$4);
				} else {
					ZVAL_LONG(&position, _9$$4);
				}
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _8$$4);
				ZEPHIR_OBS_NVAR(&referencedField);
				_11$$5 = zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_11$$5))) {
					ZEPHIR_INIT_NVAR(&_12$$6);
					object_init_ex(&_12$$6, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property_cached(&_13$$6, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", &_14, 0, &modelAlias_zv, &joinAlias_zv, &_13$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$6, "phalcon/Mvc/Model/Query.zep", 3746);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_15$$5);
				zephir_create_array(&_15$$5, 4, 0);
				add_assoc_stringl_ex(&_15$$5, SL("type"), SL("binary-op"));
				add_assoc_stringl_ex(&_15$$5, SL("op"), SL("="));
				ZEPHIR_INIT_NVAR(&_17$$5);
				zephir_create_array(&_17$$5, 3, 0);
				add_assoc_long_ex(&_17$$5, SL("type"), 355);
				zephir_array_update_string(&_17$$5, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_17$$5, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_16$$5, this_ptr, "getQualified", &_4, 0, &_17$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_15$$5, SL("left"), &_16$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$5);
				zephir_create_array(&_18$$5, 3, 0);
				add_assoc_stringl_ex(&_18$$5, SL("type"), SL("qualified"));
				zephir_array_update_string(&_18$$5, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_18$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_16$$5, this_ptr, "getQualified", &_4, 0, &_18$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_15$$5, SL("right"), &_16$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoinPartialConditions, &_15$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3771);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_20$$4 = 1;
			while (1) {
				if (_20$$4) {
					_20$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _6$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$4, _6$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&position, _6$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&field, _6$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&referencedField);
					_21$$7 = zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_21$$7))) {
						ZEPHIR_INIT_NVAR(&_22$$8);
						object_init_ex(&_22$$8, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_23$$8, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_22$$8, "__construct", &_24, 0, &modelAlias_zv, &joinAlias_zv, &_23$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_22$$8, "phalcon/Mvc/Model/Query.zep", 3746);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_25$$7);
					zephir_create_array(&_25$$7, 4, 0);
					add_assoc_stringl_ex(&_25$$7, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_25$$7, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_27$$7);
					zephir_create_array(&_27$$7, 3, 0);
					add_assoc_long_ex(&_27$$7, SL("type"), 355);
					zephir_array_update_string(&_27$$7, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_27$$7, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_26$$7, this_ptr, "getQualified", &_4, 0, &_27$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_25$$7, SL("left"), &_26$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$7);
					zephir_create_array(&_28$$7, 3, 0);
					add_assoc_stringl_ex(&_28$$7, SL("type"), SL("qualified"));
					zephir_array_update_string(&_28$$7, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_28$$7, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_26$$7, this_ptr, "getQualified", &_4, 0, &_28$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_25$$7, SL("right"), &_26$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoinPartialConditions, &_25$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3771);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
 *
 * @phpstan-param array<array-key, mixed> $qualifiedName
 * @phpstan-return array<array-key, mixed>|string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getTable)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval qualifiedName;
	zval *manager, manager_sub, *qualifiedName_param = NULL, modelName, model, source, schema, _1$$3;

	ZVAL_UNDEF(&manager_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_1$$3);
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
	_0 = zephir_array_isset_string_fetch(&modelName, &qualifiedName, SL("name"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3798);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&model, manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
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
 *
 * @phpstan-param mvc_query_ir|null $intermediate
 * @phpstan-param mvc_model_bind_params $bindParams
 * @phpstan-param mvc_model_bind_types $bindTypes
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1087, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getConnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectwriteconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&connection, model, "selectWriteConnection", NULL, 0, &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_writeconnectionmissing_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3838);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD(model, "getWriteConnection", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed
 * later
 *
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareDelete)
{
	zend_bool _1, _4, _7, _16, _21, _24, _14$$7, _20$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, _0, *_8, _9, *_10, _15, _2$$3, _5$$4, _12$$8, _13$$9, _18$$13, _19$$14, _22$$17, _23$$17, _25$$18;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_11 = NULL, *_17 = NULL;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$18);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&delete);
	_1 = zephir_array_isset_string_fetch(&delete, &ast, SL("delete"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_3, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 3862);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	_4 = zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_4))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_6, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model/Query.zep", 3866);
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
	_7 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&deleteTables);
		zephir_create_array(&deleteTables, 1, 0);
		zephir_array_fast_append(&deleteTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&deleteTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&deleteTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &deleteTables);
		_8 = &_9;
	} else {
		_8 = &deleteTables;
	}
	zephir_is_iterable(_8, 0, "phalcon/Mvc/Model/Query.zep", 3926);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _10)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _10);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3890);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3891);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_11, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				zephir_create_array(&_12$$8, 2, 0);
				zephir_array_fast_append(&_12$$8, &source);
				zephir_array_fast_append(&_12$$8, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_12$$8);
			} else {
				ZEPHIR_INIT_NVAR(&_13$$9);
				zephir_create_array(&_13$$9, 2, 0);
				zephir_array_fast_append(&_13$$9, &source);
				zephir_array_fast_append(&_13$$9, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_13$$9);
			}
			ZEPHIR_OBS_NVAR(&alias);
			_14$$7 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_14$$7) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3908);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3909);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3915);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3919);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _8, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3890);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3891);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_17, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_18$$13);
					zephir_create_array(&_18$$13, 2, 0);
					zephir_array_fast_append(&_18$$13, &source);
					zephir_array_fast_append(&_18$$13, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_18$$13);
				} else {
					ZEPHIR_INIT_NVAR(&_19$$14);
					zephir_create_array(&_19$$14, 2, 0);
					zephir_array_fast_append(&_19$$14, &source);
					zephir_array_fast_append(&_19$$14, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_19$$14);
				}
				ZEPHIR_OBS_NVAR(&alias);
				_20$$12 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_20$$12) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3908);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3909);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3915);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3919);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1089, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1088, &modelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1090, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1093, &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlDelete);
	array_init(&sqlDelete);
	zephir_array_update_string(&sqlDelete, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&sqlDelete, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&where);
	_21 = zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_21) {
		ZVAL_BOOL(&_23$$17, 1);
		ZEPHIR_CALL_METHOD(&_22$$17, this_ptr, "getExpression", NULL, 0, &where, &_23$$17);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_22$$17, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_24 = zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_24) {
		ZEPHIR_CALL_METHOD(&_25$$18, this_ptr, "getLimitClause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_25$$18, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&sqlDelete);
}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed
 * later
 *
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareInsert)
{
	zval _15$$7, _22$$8;
	zend_bool notQuoting = 0, _1, _4, _7, _21, _26, _36$$9;
	zval ast, qualifiedName, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, _0, _11, *_12, _13, *_14, _20, _2$$3, _5$$4, _8$$5, _10$$6, _16$$7, _17$$7, _18$$7, _23$$8, _24$$8, _25$$8, *_27$$9, _28$$9, *_29$$9, _35$$9, _30$$10, _32$$11, _33$$11, _37$$12, _39$$13, _40$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_9 = NULL, *_19 = NULL, *_31 = NULL, *_34 = NULL, *_38 = NULL, *_41 = NULL;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_35$$9);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_37$$12);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_22$$8);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	_1 = zephir_array_isset_value_string(&ast, SL("qualifiedName"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_3, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 3962);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_array_isset_value_string(&ast, SL("values"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_4))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_6, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model/Query.zep", 3966);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3969);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_7 = zephir_array_isset_value_string(&qualifiedName, SL("name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_7))) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_9, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "phalcon/Mvc/Model/Query.zep", 3973);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3977);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&model, &manager, "load", NULL, 0, &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&_10$$6);
		zephir_create_array(&_10$$6, 2, 0);
		zephir_array_fast_append(&_10$$6, &schema);
		zephir_array_fast_append(&_10$$6, &source);
		ZEPHIR_CPY_WRT(&source, &_10$$6);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(&exprValues);
	array_init(&exprValues);
	zephir_memory_observe(&_11);
	zephir_array_fetch_string(&_11, &ast, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3990);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_11) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_13);
		zephir_string_to_char_array(&_13, &_11);
		_12 = &_13;
	} else {
		_12 = &_11;
	}
	zephir_is_iterable(_12, 0, "phalcon/Mvc/Model/Query.zep", 3998);
	if (Z_TYPE_P(_12) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_12), _14)
		{
			ZEPHIR_INIT_NVAR(&exprValue);
			ZVAL_COPY(&exprValue, _14);
			ZEPHIR_INIT_NVAR(&_15$$7);
			zephir_create_array(&_15$$7, 2, 0);
			ZEPHIR_OBS_NVAR(&_16$$7);
			zephir_array_fetch_string(&_16$$7, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3993);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_15$$7, SL("type"), &_16$$7, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_18$$7, 1);
			} else {
				ZVAL_BOOL(&_18$$7, 0);
			}
			ZEPHIR_CALL_METHOD(&_17$$7, this_ptr, "getExpression", &_19, 0, &exprValue, &_18$$7);
			zephir_check_call_status();
			zephir_array_update_string(&_15$$7, SL("value"), &_17$$7, PH_COPY | PH_SEPARATE);
			zephir_array_append(&exprValues, &_15$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3995);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _12, "rewind", NULL, 0);
		zephir_check_call_status();
		_21 = 1;
		while (1) {
			if (_21) {
				_21 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _12, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_20, _12, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&exprValue, _12, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$8);
				zephir_create_array(&_22$$8, 2, 0);
				ZEPHIR_OBS_NVAR(&_23$$8);
				zephir_array_fetch_string(&_23$$8, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3993);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_22$$8, SL("type"), &_23$$8, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_25$$8, 1);
				} else {
					ZVAL_BOOL(&_25$$8, 0);
				}
				ZEPHIR_CALL_METHOD(&_24$$8, this_ptr, "getExpression", &_19, 0, &exprValue, &_25$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_22$$8, SL("value"), &_24$$8, PH_COPY | PH_SEPARATE);
				zephir_array_append(&exprValues, &_22$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3995);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&exprValue);
	ZEPHIR_INIT_VAR(&sqlInsert);
	zephir_create_array(&sqlInsert, 2, 0);
	zephir_array_update_string(&sqlInsert, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlInsert, SL("table"), &source, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_0);
	zephir_memory_observe(&fields);
	_26 = zephir_array_isset_string_fetch(&fields, &ast, SL("fields"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_26) {
		ZEPHIR_INIT_VAR(&sqlFields);
		array_init(&sqlFields);
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_28$$9);
			zephir_string_to_char_array(&_28$$9, &fields);
			_27$$9 = &_28$$9;
		} else {
			_27$$9 = &fields;
		}
		zephir_is_iterable(_27$$9, 0, "phalcon/Mvc/Model/Query.zep", 4020);
		if (Z_TYPE_P(_27$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_27$$9), _29$$9)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _29$$9);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4009);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&_30$$10, &metaData, "hasAttribute", &_31, 0, &model, &name);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_30$$10))) {
					ZEPHIR_INIT_NVAR(&_32$$11);
					object_init_ex(&_32$$11, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
					zephir_read_property_cached(&_33$$11, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_32$$11, "__construct", &_34, 0, &modelName, &name, &_33$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$11, "phalcon/Mvc/Model/Query.zep", 4013);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4017);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _27$$9, "rewind", NULL, 0);
			zephir_check_call_status();
			_36$$9 = 1;
			while (1) {
				if (_36$$9) {
					_36$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _27$$9, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_35$$9, _27$$9, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_35$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&field, _27$$9, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4009);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_37$$12, &metaData, "hasAttribute", &_38, 0, &model, &name);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_37$$12))) {
						ZEPHIR_INIT_NVAR(&_39$$13);
						object_init_ex(&_39$$13, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
						zephir_read_property_cached(&_40$$13, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_39$$13, "__construct", &_41, 0, &modelName, &name, &_40$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_39$$13, "phalcon/Mvc/Model/Query.zep", 4013);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlFields, &name, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4017);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&field);
		zephir_array_update_string(&sqlInsert, SL("fields"), &sqlFields, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_array_update_string(&sqlInsert, SL("values"), &exprValues, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&sqlInsert);
}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 *
 * @phpstan-param mvc_query_ast|null $ast
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareSelect)
{
	zend_string *_110$$56, *_113$$56, *_116$$56, *_119$$56, *_122$$56, *_125$$56;
	zend_ulong _109$$56, _112$$56, _115$$56, _118$$56, _121$$56, _124$$56;
	zval _29$$24, _46$$29, _77$$45, _94$$50, _142$$76, _149$$83, _160$$91, _167$$98;
	zval models, modelsInstances, sqlAliases, sqlAliasesModels, sqlAliasesModelsInstances, sqlColumns, sqlModels, sqlModelsAliases, sqlTables, _40$$24, _41$$24, _42$$24, _57$$29, _58$$29, _59$$29, _88$$45, _89$$45, _90$$45, _105$$50, _106$$50, _107$$50;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_16 = NULL, *_21 = NULL, *_30 = NULL, *_32 = NULL, *_35 = NULL, *_38 = NULL, *_47 = NULL, *_49 = NULL, *_52 = NULL, *_55 = NULL, *_62 = NULL, *_68 = NULL, *_78 = NULL, *_80 = NULL, *_83 = NULL, *_86 = NULL, *_95 = NULL, *_97 = NULL, *_100 = NULL, *_103 = NULL, *_129 = NULL, *_134 = NULL, *_172 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zend_bool merge, _1, _2, _5, _8, _9, _61, _126, _151, _169, _170, _173, _175, _177, _179, _181, _17$$13, _23$$13, _18$$16, _24$$21, _44$$21, _64$$34, _70$$34, _65$$37, _71$$42, _92$$42, _127$$64, _144$$70, _138$$71, _139$$73, _145$$78, _146$$80, _162$$85, _156$$86, _157$$88, _163$$93, _164$$95;
	zval *ast = NULL, ast_sub, *merge_param = NULL, __$null, __$true, alias, automaticJoins, bestAlias, column, columns, completeSource, distinct, eagerType, groupBy, having, joinAlias, joins, limit, manager, mergeKey, mergeValue, metaData, model, modelName, order, qualifiedName, relation, relationModel, relations, schema, select, selectColumns, selectedModel, selectedModels, source, sqlColumn, sqlColumnAliases, sqlJoins, sqlSelect, tables, where, with, withItem, withs, tempModels, tempModelsInstances, tempSqlAliasesModels, tempSqlAliasesModelsInstances, tempSqlModelsAliases, tempSqlAliases, _10, *_13, _14, *_15, _60, *_130, _131, *_132, _150, _168, _0$$3, _3$$5, _6$$6, _11$$11, _12$$12, _19$$17, _20$$17, _22$$19, *_25$$21, _26$$21, *_27$$21, _43$$21, _28$$24, _31$$25, _33$$27, _34$$27, _36$$28, _37$$28, _39$$26, _45$$29, _48$$30, _50$$32, _51$$32, _53$$33, _54$$33, _56$$31, _63$$35, _66$$38, _67$$38, _69$$40, *_73$$42, _74$$42, *_75$$42, _91$$42, _72$$43, _76$$45, _79$$46, _81$$48, _82$$48, _84$$49, _85$$49, _87$$47, _93$$50, _96$$51, _98$$53, _99$$53, _101$$54, _102$$54, _104$$52, *_108$$56, *_111$$56, *_114$$56, *_117$$56, *_120$$56, *_123$$56, _128$$65, _133$$70, *_135$$70, _136$$70, *_137$$70, _143$$70, _140$$75, _141$$76, _147$$82, _148$$83, _152$$85, *_153$$85, _154$$85, *_155$$85, _161$$85, _158$$90, _159$$91, _165$$97, _166$$98, _171$$102, _174$$103, _176$$104, _178$$105, _180$$106;
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_60);
	ZVAL_UNDEF(&_131);
	ZVAL_UNDEF(&_150);
	ZVAL_UNDEF(&_168);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_28$$24);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_36$$28);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_48$$30);
	ZVAL_UNDEF(&_50$$32);
	ZVAL_UNDEF(&_51$$32);
	ZVAL_UNDEF(&_53$$33);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_63$$35);
	ZVAL_UNDEF(&_66$$38);
	ZVAL_UNDEF(&_67$$38);
	ZVAL_UNDEF(&_69$$40);
	ZVAL_UNDEF(&_74$$42);
	ZVAL_UNDEF(&_91$$42);
	ZVAL_UNDEF(&_72$$43);
	ZVAL_UNDEF(&_76$$45);
	ZVAL_UNDEF(&_79$$46);
	ZVAL_UNDEF(&_81$$48);
	ZVAL_UNDEF(&_82$$48);
	ZVAL_UNDEF(&_84$$49);
	ZVAL_UNDEF(&_85$$49);
	ZVAL_UNDEF(&_87$$47);
	ZVAL_UNDEF(&_93$$50);
	ZVAL_UNDEF(&_96$$51);
	ZVAL_UNDEF(&_98$$53);
	ZVAL_UNDEF(&_99$$53);
	ZVAL_UNDEF(&_101$$54);
	ZVAL_UNDEF(&_102$$54);
	ZVAL_UNDEF(&_104$$52);
	ZVAL_UNDEF(&_128$$65);
	ZVAL_UNDEF(&_133$$70);
	ZVAL_UNDEF(&_136$$70);
	ZVAL_UNDEF(&_143$$70);
	ZVAL_UNDEF(&_140$$75);
	ZVAL_UNDEF(&_141$$76);
	ZVAL_UNDEF(&_147$$82);
	ZVAL_UNDEF(&_148$$83);
	ZVAL_UNDEF(&_152$$85);
	ZVAL_UNDEF(&_154$$85);
	ZVAL_UNDEF(&_161$$85);
	ZVAL_UNDEF(&_158$$90);
	ZVAL_UNDEF(&_159$$91);
	ZVAL_UNDEF(&_165$$97);
	ZVAL_UNDEF(&_166$$98);
	ZVAL_UNDEF(&_171$$102);
	ZVAL_UNDEF(&_174$$103);
	ZVAL_UNDEF(&_176$$104);
	ZVAL_UNDEF(&_178$$105);
	ZVAL_UNDEF(&_180$$106);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_57$$29);
	ZVAL_UNDEF(&_58$$29);
	ZVAL_UNDEF(&_59$$29);
	ZVAL_UNDEF(&_88$$45);
	ZVAL_UNDEF(&_89$$45);
	ZVAL_UNDEF(&_90$$45);
	ZVAL_UNDEF(&_105$$50);
	ZVAL_UNDEF(&_106$$50);
	ZVAL_UNDEF(&_107$$50);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_77$$45);
	ZVAL_UNDEF(&_94$$50);
	ZVAL_UNDEF(&_142$$76);
	ZVAL_UNDEF(&_149$$83);
	ZVAL_UNDEF(&_160$$91);
	ZVAL_UNDEF(&_167$$98);
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
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(ast, &_0$$3);
	}
	zephir_memory_observe(&select);
	_1 = zephir_array_isset_string_fetch(&select, ast, SL("select"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_CPY_WRT(&select, ast);
	}
	zephir_memory_observe(&tables);
	_2 = zephir_array_isset_string_fetch(&tables, &select, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_2))) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", &_4, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 4062);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	_5 = zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_5))) {
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", &_7, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$6, "phalcon/Mvc/Model/Query.zep", 4066);
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
	_8 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_8)) {
		ZEPHIR_INIT_VAR(&selectedModels);
		zephir_create_array(&selectedModels, 1, 0);
		zephir_array_fast_append(&selectedModels, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectedModels, &tables);
	}
	_9 = zephir_array_isset_value_long(&columns, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_9)) {
		ZEPHIR_INIT_VAR(&selectColumns);
		zephir_create_array(&selectColumns, 1, 0);
		zephir_array_fast_append(&selectColumns, &columns);
	} else {
		ZEPHIR_CPY_WRT(&selectColumns, &columns);
	}
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_10);
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&metaData, &_10);
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_11$$11);
		object_init_ex(&_11$$11, phalcon_mvc_model_query_exceptions_missingmodelsmanager_ce);
		ZEPHIR_CALL_METHOD(NULL, &_11$$11, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model/Query.zep", 4131);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_12$$12);
		object_init_ex(&_12$$12, phalcon_mvc_model_query_exceptions_missingmetadata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_12$$12, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$12, "phalcon/Mvc/Model/Query.zep", 4135);
		ZEPHIR_MM_RESTORE();
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	if (Z_TYPE_P(&selectedModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_14);
		zephir_string_to_char_array(&_14, &selectedModels);
		_13 = &_14;
	} else {
		_13 = &selectedModels;
	}
	zephir_is_iterable(_13, 0, "phalcon/Mvc/Model/Query.zep", 4278);
	if (Z_TYPE_P(_13) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13), _15)
		{
			ZEPHIR_INIT_NVAR(&selectedModel);
			ZVAL_COPY(&selectedModel, _15);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4143);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4144);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_16, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
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
			_17$$13 = zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_17$$13) {
				_18$$16 = zephir_array_isset_value(&sqlAliases, &alias);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_18$$16)) {
					ZEPHIR_INIT_NVAR(&_19$$17);
					object_init_ex(&_19$$17, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
					zephir_read_property_cached(&_20$$17, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_19$$17, "__construct", &_21, 0, &alias, &_20$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_19$$17, "phalcon/Mvc/Model/Query.zep", 4167);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4179);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_22$$19);
					zephir_create_array(&_22$$19, 3, 0);
					zephir_array_fast_append(&_22$$19, &source);
					zephir_array_fast_append(&_22$$19, &__$null);
					zephir_array_fast_append(&_22$$19, &alias);
					ZEPHIR_CPY_WRT(&completeSource, &_22$$19);
				}
				zephir_array_update_zval(&models, &modelName, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&alias, &source);
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&with);
			_23$$13 = zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_23$$13) {
				_24$$21 = zephir_array_isset_value_long(&with, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_24$$21)) {
					ZEPHIR_INIT_NVAR(&withs);
					zephir_create_array(&withs, 1, 0);
					zephir_array_fast_append(&withs, &with);
				} else {
					ZEPHIR_CPY_WRT(&withs, &with);
				}
				if (Z_TYPE_P(&withs) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_26$$21);
					zephir_string_to_char_array(&_26$$21, &withs);
					_25$$21 = &_26$$21;
				} else {
					_25$$21 = &withs;
				}
				zephir_is_iterable(_25$$21, 0, "phalcon/Mvc/Model/Query.zep", 4270);
				if (Z_TYPE_P(_25$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25$$21), _27$$21)
					{
						ZEPHIR_INIT_NVAR(&withItem);
						ZVAL_COPY(&withItem, _27$$21);
						ZEPHIR_INIT_NVAR(&_28$$24);
						ZVAL_LONG(&_28$$24, number);
						ZEPHIR_INIT_NVAR(&_29$$24);
						ZEPHIR_CONCAT_SV(&_29$$24, "AA", &_28$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&joinAlias, &_29$$24);
						ZEPHIR_OBS_NVAR(&relationModel);
						zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_30, 0, &modelName, &relationModel);
						zephir_check_call_status();
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_31$$25);
							ZVAL_STRING(&_31$$25, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_31$$25);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_32, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
								ZEPHIR_INIT_NVAR(&_33$$27);
								object_init_ex(&_33$$27, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
								zephir_read_property_cached(&_34$$27, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_33$$27, "__construct", &_35, 0, &modelName, &relationModel, &_34$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_33$$27, "phalcon/Mvc/Model/Query.zep", 4228);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_36$$28);
								object_init_ex(&_36$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_37$$28, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
								ZEPHIR_CALL_METHOD(NULL, &_36$$28, "__construct", &_38, 0, &modelName, &relationModel, &_37$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_36$$28, "phalcon/Mvc/Model/Query.zep", 4235);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_39$$26);
							ZVAL_STRING(&_39$$26, "alias");
							ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_39$$26);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_40$$24);
						zephir_create_array(&_40$$24, 5, 0);
						add_assoc_long_ex(&_40$$24, SL("type"), 353);
						zephir_array_update_string(&_40$$24, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_40$$24, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_40$$24, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_40$$24, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
						zephir_array_append(&selectColumns, &_40$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_41$$24);
						zephir_create_array(&_41$$24, 3, 0);
						add_assoc_long_ex(&_41$$24, SL("type"), 360);
						ZEPHIR_INIT_NVAR(&_42$$24);
						zephir_create_array(&_42$$24, 2, 0);
						add_assoc_long_ex(&_42$$24, SL("type"), 355);
						zephir_array_update_string(&_42$$24, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_41$$24, SL("qualified"), &_42$$24, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_42$$24);
						zephir_create_array(&_42$$24, 2, 0);
						add_assoc_long_ex(&_42$$24, SL("type"), 355);
						zephir_array_update_string(&_42$$24, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_41$$24, SL("alias"), &_42$$24, PH_COPY | PH_SEPARATE);
						zephir_array_append(&automaticJoins, &_41$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						number++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _25$$21, "rewind", NULL, 0);
					zephir_check_call_status();
					_44$$21 = 1;
					while (1) {
						if (_44$$21) {
							_44$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _25$$21, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_43$$21, _25$$21, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_43$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&withItem, _25$$21, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$29);
							ZVAL_LONG(&_45$$29, number);
							ZEPHIR_INIT_NVAR(&_46$$29);
							ZEPHIR_CONCAT_SV(&_46$$29, "AA", &_45$$29);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&joinAlias, &_46$$29);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_47, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_48$$30);
								ZVAL_STRING(&_48$$30, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_48$$30);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_49, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_50$$32);
									object_init_ex(&_50$$32, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_51$$32, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_50$$32, "__construct", &_52, 0, &modelName, &relationModel, &_51$$32);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_50$$32, "phalcon/Mvc/Model/Query.zep", 4228);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_53$$33);
									object_init_ex(&_53$$33, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_54$$33, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_53$$33, "__construct", &_55, 0, &modelName, &relationModel, &_54$$33);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_53$$33, "phalcon/Mvc/Model/Query.zep", 4235);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_56$$31);
								ZVAL_STRING(&_56$$31, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_56$$31);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_57$$29);
							zephir_create_array(&_57$$29, 5, 0);
							add_assoc_long_ex(&_57$$29, SL("type"), 353);
							zephir_array_update_string(&_57$$29, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_57$$29, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_57$$29, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_57$$29, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_57$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_58$$29);
							zephir_create_array(&_58$$29, 3, 0);
							add_assoc_long_ex(&_58$$29, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_59$$29);
							zephir_create_array(&_59$$29, 2, 0);
							add_assoc_long_ex(&_59$$29, SL("type"), 355);
							zephir_array_update_string(&_59$$29, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_58$$29, SL("qualified"), &_59$$29, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_59$$29);
							zephir_create_array(&_59$$29, 2, 0);
							add_assoc_long_ex(&_59$$29, SL("type"), 355);
							zephir_array_update_string(&_59$$29, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_58$$29, SL("alias"), &_59$$29, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_58$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							number++;
					}
				}
				ZEPHIR_INIT_NVAR(&withItem);
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4272);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4273);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _13, "rewind", NULL, 0);
		zephir_check_call_status();
		_61 = 1;
		while (1) {
			if (_61) {
				_61 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _13, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_60, _13, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_60)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&selectedModel, _13, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &selectedModel, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4143);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_62, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_63$$35);
					zephir_create_array(&_63$$35, 2, 0);
					zephir_array_fast_append(&_63$$35, &source);
					zephir_array_fast_append(&_63$$35, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_63$$35);
				} else {
					ZEPHIR_CPY_WRT(&completeSource, &source);
				}
				ZEPHIR_OBS_NVAR(&alias);
				_64$$34 = zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_64$$34) {
					_65$$37 = zephir_array_isset_value(&sqlAliases, &alias);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_65$$37)) {
						ZEPHIR_INIT_NVAR(&_66$$38);
						object_init_ex(&_66$$38, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
						zephir_read_property_cached(&_67$$38, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(NULL, &_66$$38, "__construct", &_68, 0, &alias, &_67$$38);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_66$$38, "phalcon/Mvc/Model/Query.zep", 4167);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&completeSource) == IS_ARRAY) {
						zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4179);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_69$$40);
						zephir_create_array(&_69$$40, 3, 0);
						zephir_array_fast_append(&_69$$40, &source);
						zephir_array_fast_append(&_69$$40, &__$null);
						zephir_array_fast_append(&_69$$40, &alias);
						ZEPHIR_CPY_WRT(&completeSource, &_69$$40);
					}
					zephir_array_update_zval(&models, &modelName, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&alias, &source);
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&with);
				_70$$34 = zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_70$$34) {
					_71$$42 = zephir_array_isset_value_long(&with, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_71$$42)) {
						ZEPHIR_INIT_NVAR(&_72$$43);
						zephir_create_array(&_72$$43, 1, 0);
						zephir_array_fast_append(&_72$$43, &with);
						ZEPHIR_CPY_WRT(&withs, &_72$$43);
					} else {
						ZEPHIR_CPY_WRT(&withs, &with);
					}
					if (Z_TYPE_P(&withs) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_74$$42);
						zephir_string_to_char_array(&_74$$42, &withs);
						_73$$42 = &_74$$42;
					} else {
						_73$$42 = &withs;
					}
					zephir_is_iterable(_73$$42, 0, "phalcon/Mvc/Model/Query.zep", 4270);
					if (Z_TYPE_P(_73$$42) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_73$$42), _75$$42)
						{
							ZEPHIR_INIT_NVAR(&withItem);
							ZVAL_COPY(&withItem, _75$$42);
							ZEPHIR_INIT_NVAR(&_76$$45);
							ZVAL_LONG(&_76$$45, number);
							ZEPHIR_INIT_NVAR(&_77$$45);
							ZEPHIR_CONCAT_SV(&_77$$45, "AA", &_76$$45);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&joinAlias, &_77$$45);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_78, 0, &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_79$$46);
								ZVAL_STRING(&_79$$46, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_79$$46);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_80, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_81$$48);
									object_init_ex(&_81$$48, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_82$$48, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_81$$48, "__construct", &_83, 0, &modelName, &relationModel, &_82$$48);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_81$$48, "phalcon/Mvc/Model/Query.zep", 4228);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_84$$49);
									object_init_ex(&_84$$49, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_85$$49, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									ZEPHIR_CALL_METHOD(NULL, &_84$$49, "__construct", &_86, 0, &modelName, &relationModel, &_85$$49);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_84$$49, "phalcon/Mvc/Model/Query.zep", 4235);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_87$$47);
								ZVAL_STRING(&_87$$47, "alias");
								ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_87$$47);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_88$$45);
							zephir_create_array(&_88$$45, 5, 0);
							add_assoc_long_ex(&_88$$45, SL("type"), 353);
							zephir_array_update_string(&_88$$45, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_88$$45, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_88$$45, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_88$$45, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_88$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_89$$45);
							zephir_create_array(&_89$$45, 3, 0);
							add_assoc_long_ex(&_89$$45, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_90$$45);
							zephir_create_array(&_90$$45, 2, 0);
							add_assoc_long_ex(&_90$$45, SL("type"), 355);
							zephir_array_update_string(&_90$$45, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_89$$45, SL("qualified"), &_90$$45, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_90$$45);
							zephir_create_array(&_90$$45, 2, 0);
							add_assoc_long_ex(&_90$$45, SL("type"), 355);
							zephir_array_update_string(&_90$$45, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_89$$45, SL("alias"), &_90$$45, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_89$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							number++;
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _73$$42, "rewind", NULL, 0);
						zephir_check_call_status();
						_92$$42 = 1;
						while (1) {
							if (_92$$42) {
								_92$$42 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _73$$42, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_91$$42, _73$$42, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_91$$42)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&withItem, _73$$42, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_93$$50);
								ZVAL_LONG(&_93$$50, number);
								ZEPHIR_INIT_NVAR(&_94$$50);
								ZEPHIR_CONCAT_SV(&_94$$50, "AA", &_93$$50);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&joinAlias, &_94$$50);
								ZEPHIR_OBS_NVAR(&relationModel);
								zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD(&relation, &manager, "getRelationByAlias", &_95, 0, &modelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_96$$51);
									ZVAL_STRING(&_96$$51, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_96$$51);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD(&relations, &manager, "getRelationsBetween", &_97, 0, &modelName, &relationModel);
									zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
										ZEPHIR_INIT_NVAR(&_98$$53);
										object_init_ex(&_98$$53, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
										zephir_read_property_cached(&_99$$53, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_METHOD(NULL, &_98$$53, "__construct", &_100, 0, &modelName, &relationModel, &_99$$53);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_98$$53, "phalcon/Mvc/Model/Query.zep", 4228);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
										ZEPHIR_INIT_NVAR(&_101$$54);
										object_init_ex(&_101$$54, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
										zephir_read_property_cached(&_102$$54, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
										ZEPHIR_CALL_METHOD(NULL, &_101$$54, "__construct", &_103, 0, &modelName, &relationModel, &_102$$54);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_101$$54, "phalcon/Mvc/Model/Query.zep", 4235);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&relation);
									zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_104$$52);
									ZVAL_STRING(&_104$$52, "alias");
									ZEPHIR_CALL_METHOD(&bestAlias, &relation, "getOption", NULL, 0, &_104$$52);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&relationModel, &relation, "getReferencedModel", NULL, 0);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD(&eagerType, &relation, "getType", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_INIT_NVAR(&_105$$50);
								zephir_create_array(&_105$$50, 5, 0);
								add_assoc_long_ex(&_105$$50, SL("type"), 353);
								zephir_array_update_string(&_105$$50, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_105$$50, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_105$$50, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_105$$50, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
								zephir_array_append(&selectColumns, &_105$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_106$$50);
								zephir_create_array(&_106$$50, 3, 0);
								add_assoc_long_ex(&_106$$50, SL("type"), 360);
								ZEPHIR_INIT_NVAR(&_107$$50);
								zephir_create_array(&_107$$50, 2, 0);
								add_assoc_long_ex(&_107$$50, SL("type"), 355);
								zephir_array_update_string(&_107$$50, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_106$$50, SL("qualified"), &_107$$50, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_107$$50);
								zephir_create_array(&_107$$50, 2, 0);
								add_assoc_long_ex(&_107$$50, SL("type"), 355);
								zephir_array_update_string(&_107$$50, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_106$$50, SL("alias"), &_107$$50, PH_COPY | PH_SEPARATE);
								zephir_array_append(&automaticJoins, &_106$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								number++;
						}
					}
					ZEPHIR_INIT_NVAR(&withItem);
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4272);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4273);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&selectedModel);
	if (!(merge)) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1089, &models);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1088, &modelsInstances);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1090, &sqlAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1091, &sqlAliasesModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1092, &sqlModelsAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1093, &sqlAliasesModelsInstances);
	} else {
		ZEPHIR_OBS_NVAR(&tempModels);
		zephir_read_property_cached(&tempModels, this_ptr, _zephir_prop_4, 1089, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempModelsInstances);
		zephir_read_property_cached(&tempModelsInstances, this_ptr, _zephir_prop_5, 1088, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliases);
		zephir_read_property_cached(&tempSqlAliases, this_ptr, _zephir_prop_6, 1090, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModels);
		zephir_read_property_cached(&tempSqlAliasesModels, this_ptr, _zephir_prop_7, 1091, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlModelsAliases);
		zephir_read_property_cached(&tempSqlModelsAliases, this_ptr, _zephir_prop_8, 1092, PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModelsInstances);
		zephir_read_property_cached(&tempSqlAliasesModelsInstances, this_ptr, _zephir_prop_9, 1093, PH_NOISY_CC);
		zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query.zep", 4302);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&models), _109$$56, _110$$56, _108$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_110$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _110$$56);
			} else {
				ZVAL_LONG(&mergeKey, _109$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _108$$56);
			zephir_update_property_array(this_ptr, SL("models"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&modelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4306);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&modelsInstances), _112$$56, _113$$56, _111$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_113$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _113$$56);
			} else {
				ZVAL_LONG(&mergeKey, _112$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _111$$56);
			zephir_update_property_array(this_ptr, SL("modelsInstances"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliases, 0, "phalcon/Mvc/Model/Query.zep", 4310);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliases), _115$$56, _116$$56, _114$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_116$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _116$$56);
			} else {
				ZVAL_LONG(&mergeKey, _115$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _114$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliases"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModels, 0, "phalcon/Mvc/Model/Query.zep", 4314);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliasesModels), _118$$56, _119$$56, _117$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_119$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _119$$56);
			} else {
				ZVAL_LONG(&mergeKey, _118$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _117$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliasesModels"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlModelsAliases, 0, "phalcon/Mvc/Model/Query.zep", 4318);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlModelsAliases), _121$$56, _122$$56, _120$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_122$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _122$$56);
			} else {
				ZVAL_LONG(&mergeKey, _121$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _120$$56);
			zephir_update_property_array(this_ptr, SL("sqlModelsAliases"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4321);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sqlAliasesModelsInstances), _124$$56, _125$$56, _123$$56)
		{
			ZEPHIR_INIT_NVAR(&mergeKey);
			if (_125$$56 != NULL) { 
				ZVAL_STR_COPY(&mergeKey, _125$$56);
			} else {
				ZVAL_LONG(&mergeKey, _124$$56);
			}
			ZEPHIR_INIT_NVAR(&mergeValue);
			ZVAL_COPY(&mergeValue, _123$$56);
			zephir_update_property_array(this_ptr, SL("sqlAliasesModelsInstances"), &mergeKey, &mergeValue);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
	}
	zephir_memory_observe(&joins);
	_126 = zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_126;
	if (!(ZEPHIR_IS_EMPTY(&joins))) {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			_127$$64 = zephir_array_isset_value_long(&joins, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_127$$64) {
				ZEPHIR_INIT_VAR(&_128$$65);
				zephir_fast_array_merge(&_128$$65, &joins, &automaticJoins);
				zephir_array_update_string(&select, SL("joins"), &_128$$65, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_append(&automaticJoins, &joins, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4331);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getJoins", &_129, 0, &select);
		zephir_check_call_status();
	} else {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getJoins", &_129, 0, &select);
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
		ZEPHIR_INIT_VAR(&_131);
		zephir_string_to_char_array(&_131, &selectColumns);
		_130 = &_131;
	} else {
		_130 = &selectColumns;
	}
	zephir_is_iterable(_130, 0, "phalcon/Mvc/Model/Query.zep", 4382);
	if (Z_TYPE_P(_130) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_130), _132)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _132);
			ZEPHIR_CALL_METHOD(&_133$$70, this_ptr, "getSelectColumn", &_134, 0, &column);
			zephir_check_call_status();
			if (Z_TYPE_P(&_133$$70) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_136$$70);
				zephir_string_to_char_array(&_136$$70, &_133$$70);
				_135$$70 = &_136$$70;
			} else {
				_135$$70 = &_133$$70;
			}
			zephir_is_iterable(_135$$70, 0, "phalcon/Mvc/Model/Query.zep", 4380);
			if (Z_TYPE_P(_135$$70) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_135$$70), _137$$70)
				{
					ZEPHIR_INIT_NVAR(&sqlColumn);
					ZVAL_COPY(&sqlColumn, _137$$70);
					ZEPHIR_OBS_NVAR(&alias);
					_138$$71 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_138$$71) {
						zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_OBS_NVAR(&alias);
						_139$$73 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_139$$73) {
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&_140$$75);
							zephir_array_fetch_string(&_140$$75, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (ZEPHIR_IS_STRING(&_140$$75, "scalar")) {
								ZEPHIR_INIT_NVAR(&_141$$76);
								ZVAL_LONG(&_141$$76, position);
								ZEPHIR_INIT_NVAR(&_142$$76);
								ZEPHIR_CONCAT_SV(&_142$$76, "_", &_141$$76);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&sqlColumns, &_142$$76, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4373);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
					position++;
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _135$$70, "rewind", NULL, 0);
				zephir_check_call_status();
				_144$$70 = 1;
				while (1) {
					if (_144$$70) {
						_144$$70 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _135$$70, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_143$$70, _135$$70, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_143$$70)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&sqlColumn, _135$$70, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&alias);
						_145$$78 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_145$$78) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							_146$$80 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_146$$80) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_147$$82);
								zephir_array_fetch_string(&_147$$82, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (ZEPHIR_IS_STRING(&_147$$82, "scalar")) {
									ZEPHIR_INIT_NVAR(&_148$$83);
									ZVAL_LONG(&_148$$83, position);
									ZEPHIR_INIT_NVAR(&_149$$83);
									ZEPHIR_CONCAT_SV(&_149$$83, "_", &_148$$83);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&sqlColumns, &_149$$83, &sqlColumn, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4373);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
						}
						position++;
				}
			}
			ZEPHIR_INIT_NVAR(&sqlColumn);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _130, "rewind", NULL, 0);
		zephir_check_call_status();
		_151 = 1;
		while (1) {
			if (_151) {
				_151 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _130, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_150, _130, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_150)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, _130, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_152$$85, this_ptr, "getSelectColumn", &_134, 0, &column);
				zephir_check_call_status();
				if (Z_TYPE_P(&_152$$85) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_154$$85);
					zephir_string_to_char_array(&_154$$85, &_152$$85);
					_153$$85 = &_154$$85;
				} else {
					_153$$85 = &_152$$85;
				}
				zephir_is_iterable(_153$$85, 0, "phalcon/Mvc/Model/Query.zep", 4380);
				if (Z_TYPE_P(_153$$85) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_153$$85), _155$$85)
					{
						ZEPHIR_INIT_NVAR(&sqlColumn);
						ZVAL_COPY(&sqlColumn, _155$$85);
						ZEPHIR_OBS_NVAR(&alias);
						_156$$86 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_156$$86) {
							zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&alias);
							_157$$88 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_157$$88) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_158$$90);
								zephir_array_fetch_string(&_158$$90, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (ZEPHIR_IS_STRING(&_158$$90, "scalar")) {
									ZEPHIR_INIT_NVAR(&_159$$91);
									ZVAL_LONG(&_159$$91, position);
									ZEPHIR_INIT_NVAR(&_160$$91);
									ZEPHIR_CONCAT_SV(&_160$$91, "_", &_159$$91);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&sqlColumns, &_160$$91, &sqlColumn, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4373);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
							}
						}
						position++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _153$$85, "rewind", NULL, 0);
					zephir_check_call_status();
					_162$$85 = 1;
					while (1) {
						if (_162$$85) {
							_162$$85 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _153$$85, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_161$$85, _153$$85, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_161$$85)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&sqlColumn, _153$$85, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&alias);
							_163$$93 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_163$$93) {
								zephir_array_update_string(&sqlColumn, SL("balias"), &alias, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_string(&sqlColumn, SL("sqlAlias"), &alias, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&sqlColumnAliases, &alias, &__$true, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&alias);
								_164$$95 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_164$$95) {
									zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_OBS_NVAR(&_165$$97);
									zephir_array_fetch_string(&_165$$97, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (ZEPHIR_IS_STRING(&_165$$97, "scalar")) {
										ZEPHIR_INIT_NVAR(&_166$$98);
										ZVAL_LONG(&_166$$98, position);
										ZEPHIR_INIT_NVAR(&_167$$98);
										ZEPHIR_CONCAT_SV(&_167$$98, "_", &_166$$98);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_zval(&sqlColumns, &_167$$98, &sqlColumn, PH_COPY | PH_SEPARATE);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} else {
										zephir_array_append(&sqlColumns, &sqlColumn, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4373);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
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
	zephir_memory_observe(&_168);
	zephir_read_property_cached(&_168, this_ptr, _zephir_prop_10, 1094, PH_NOISY_CC);
	zephir_update_property_array(this_ptr, SL("sqlColumnAliases"), &_168, &sqlColumnAliases);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sqlSelect);
	zephir_create_array(&sqlSelect, 3, 0);
	zephir_array_update_string(&sqlSelect, SL("models"), &sqlModels, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("tables"), &sqlTables, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&sqlSelect, SL("columns"), &sqlColumns, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&distinct);
	_169 = zephir_array_isset_string_fetch(&distinct, &select, SL("distinct"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_169) {
		zephir_array_update_string(&sqlSelect, SL("distinct"), &distinct, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&sqlJoins))) {
		zephir_array_update_string(&sqlSelect, SL("joins"), &sqlJoins, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&where);
	_170 = zephir_array_isset_string_fetch(&where, ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_170) {
		ZEPHIR_CALL_METHOD(&_171$$102, this_ptr, "getExpression", &_172, 0, &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_171$$102, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&groupBy);
	_173 = zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_173) {
		ZEPHIR_CALL_METHOD(&_174$$103, this_ptr, "getGroupClause", NULL, 0, &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_174$$103, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&having);
	_175 = zephir_array_isset_string_fetch(&having, ast, SL("having"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_175) {
		ZEPHIR_CALL_METHOD(&_176$$104, this_ptr, "getExpression", &_172, 0, &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_176$$104, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&order);
	_177 = zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_177) {
		ZEPHIR_CALL_METHOD(&_178$$105, this_ptr, "getOrderClause", NULL, 0, &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_178$$105, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_179 = zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_179) {
		ZEPHIR_CALL_METHOD(&_180$$106, this_ptr, "getLimitClause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_180$$106, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_181 = zephir_array_isset_value_string(ast, SL("forUpdate"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_181) {
		zephir_array_update_string(&sqlSelect, SL("forUpdate"), &__$true, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (merge) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1089, &tempModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1088, &tempModelsInstances);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1090, &tempSqlAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1091, &tempSqlAliasesModels);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 1092, &tempSqlModelsAliases);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_9, 1093, &tempSqlAliasesModelsInstances);
	}
	RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("nestingLevel")));
	RETURN_CCTOR(&sqlSelect);
}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed
 * later
 *
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, prepareUpdate)
{
	zval _33$$21, _42$$22;
	zend_bool notQuoting = 0, _1, _4, _7, _10, _19, _24, _25, _38, _46, _49, _17$$8, _23$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, updateTables, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, joins, sqlJoins, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, _0, *_11, _12, *_13, _18, *_26, _27, *_28, _37, _2$$3, _5$$4, _8$$5, _15$$9, _16$$10, _21$$14, _22$$15, _29$$21, _30$$21, _31$$21, _34$$21, _35$$21, _36$$21, _39$$22, _40$$22, _41$$22, _43$$22, _44$$22, _45$$22, _47$$24, _48$$24, _50$$25;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_9 = NULL, *_14 = NULL, *_20 = NULL, *_32 = NULL;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_43$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_45$$22);
	ZVAL_UNDEF(&_47$$24);
	ZVAL_UNDEF(&_48$$24);
	ZVAL_UNDEF(&_50$$25);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_42$$22);
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

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1082, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ast, &_0);
	zephir_memory_observe(&update);
	_1 = zephir_array_isset_string_fetch(&update, &ast, SL("update"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_3, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 4462);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	_4 = zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_4))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_6, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Mvc/Model/Query.zep", 4466);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&values);
	_7 = zephir_array_isset_string_fetch(&values, &update, SL("values"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_7))) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_9, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "phalcon/Mvc/Model/Query.zep", 4470);
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
	_10 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_10)) {
		ZEPHIR_INIT_VAR(&updateTables);
		zephir_create_array(&updateTables, 1, 0);
		zephir_array_fast_append(&updateTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&updateTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&updateTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_string_to_char_array(&_12, &updateTables);
		_11 = &_12;
	} else {
		_11 = &updateTables;
	}
	zephir_is_iterable(_11, 0, "phalcon/Mvc/Model/Query.zep", 4542);
	if (Z_TYPE_P(_11) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11), _13)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _13);
			ZEPHIR_OBS_NVAR(&qualifiedName);
			zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4496);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&modelName);
			zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4497);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_14, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_15$$9);
				zephir_create_array(&_15$$9, 2, 0);
				zephir_array_fast_append(&_15$$9, &source);
				zephir_array_fast_append(&_15$$9, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_15$$9);
			} else {
				ZEPHIR_INIT_NVAR(&_16$$10);
				zephir_create_array(&_16$$10, 2, 0);
				zephir_array_fast_append(&_16$$10, &source);
				zephir_array_fast_append(&_16$$10, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_16$$10);
			}
			ZEPHIR_OBS_NVAR(&alias);
			_17$$8 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_17$$8) {
				zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4522);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4523);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4531);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4535);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _11, "rewind", NULL, 0);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _11, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_18, _11, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&table, _11, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&qualifiedName);
				zephir_array_fetch_string(&qualifiedName, &table, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4496);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4497);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_20, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_21$$14);
					zephir_create_array(&_21$$14, 2, 0);
					zephir_array_fast_append(&_21$$14, &source);
					zephir_array_fast_append(&_21$$14, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_21$$14);
				} else {
					ZEPHIR_INIT_NVAR(&_22$$15);
					zephir_create_array(&_22$$15, 2, 0);
					zephir_array_fast_append(&_22$$15, &source);
					zephir_array_fast_append(&_22$$15, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_22$$15);
				}
				ZEPHIR_OBS_NVAR(&alias);
				_23$$13 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_23$$13) {
					zephir_array_update_zval(&sqlAliases, &alias, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &alias, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &alias, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&completeSource, &alias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4522);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlTables, &completeSource, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4523);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &alias, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &alias, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&sqlAliases, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModels, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlModelsAliases, &modelName, &modelName, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&sqlAliasesModelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&sqlTables, &source, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4531);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&models, &modelName, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&sqlModels, &modelName, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4535);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&modelsInstances, &modelName, &model, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&table);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1089, &models);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1088, &modelsInstances);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1090, &sqlAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1091, &sqlAliasesModels);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 1092, &sqlModelsAliases);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_7, 1093, &sqlAliasesModelsInstances);
	ZEPHIR_INIT_VAR(&sqlJoins);
	array_init(&sqlJoins);
	zephir_memory_observe(&joins);
	_24 = zephir_array_isset_string_fetch(&joins, &update, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_24) {
		ZEPHIR_CALL_METHOD(&sqlJoins, this_ptr, "getJoins", NULL, 0, &update);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&sqlFields);
	array_init(&sqlFields);
	ZEPHIR_INIT_VAR(&sqlValues);
	array_init(&sqlValues);
	_25 = zephir_array_isset_value_long(&values, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_25)) {
		ZEPHIR_INIT_VAR(&updateValues);
		zephir_create_array(&updateValues, 1, 0);
		zephir_array_fast_append(&updateValues, &values);
	} else {
		ZEPHIR_CPY_WRT(&updateValues, &values);
	}
	notQuoting = 0;
	if (Z_TYPE_P(&updateValues) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_27);
		zephir_string_to_char_array(&_27, &updateValues);
		_26 = &_27;
	} else {
		_26 = &updateValues;
	}
	zephir_is_iterable(_26, 0, "phalcon/Mvc/Model/Query.zep", 4581);
	if (Z_TYPE_P(_26) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_26), _28)
		{
			ZEPHIR_INIT_NVAR(&updateValue);
			ZVAL_COPY(&updateValue, _28);
			ZEPHIR_OBS_NVAR(&_30$$21);
			zephir_array_fetch_string(&_30$$21, &updateValue, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4573);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (notQuoting) {
				ZVAL_BOOL(&_31$$21, 1);
			} else {
				ZVAL_BOOL(&_31$$21, 0);
			}
			ZEPHIR_CALL_METHOD(&_29$$21, this_ptr, "getExpression", &_32, 0, &_30$$21, &_31$$21);
			zephir_check_call_status();
			zephir_array_append(&sqlFields, &_29$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4573);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&exprColumn);
			zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4574);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_33$$21);
			zephir_create_array(&_33$$21, 2, 0);
			ZEPHIR_OBS_NVAR(&_34$$21);
			zephir_array_fetch_string(&_34$$21, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4576);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_33$$21, SL("type"), &_34$$21, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_36$$21, 1);
			} else {
				ZVAL_BOOL(&_36$$21, 0);
			}
			ZEPHIR_CALL_METHOD(&_35$$21, this_ptr, "getExpression", &_32, 0, &exprColumn, &_36$$21);
			zephir_check_call_status();
			zephir_array_update_string(&_33$$21, SL("value"), &_35$$21, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlValues, &_33$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4578);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _26, "rewind", NULL, 0);
		zephir_check_call_status();
		_38 = 1;
		while (1) {
			if (_38) {
				_38 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _26, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_37, _26, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_37)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&updateValue, _26, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_40$$22);
				zephir_array_fetch_string(&_40$$22, &updateValue, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4573);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (notQuoting) {
					ZVAL_BOOL(&_41$$22, 1);
				} else {
					ZVAL_BOOL(&_41$$22, 0);
				}
				ZEPHIR_CALL_METHOD(&_39$$22, this_ptr, "getExpression", &_32, 0, &_40$$22, &_41$$22);
				zephir_check_call_status();
				zephir_array_append(&sqlFields, &_39$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4573);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&exprColumn);
				zephir_array_fetch_string(&exprColumn, &updateValue, SL("expr"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4574);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_42$$22);
				zephir_create_array(&_42$$22, 2, 0);
				ZEPHIR_OBS_NVAR(&_43$$22);
				zephir_array_fetch_string(&_43$$22, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4576);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_42$$22, SL("type"), &_43$$22, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_45$$22, 1);
				} else {
					ZVAL_BOOL(&_45$$22, 0);
				}
				ZEPHIR_CALL_METHOD(&_44$$22, this_ptr, "getExpression", &_32, 0, &exprColumn, &_45$$22);
				zephir_check_call_status();
				zephir_array_update_string(&_42$$22, SL("value"), &_44$$22, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlValues, &_42$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4578);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&where);
	_46 = zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_46) {
		ZVAL_BOOL(&_48$$24, 1);
		ZEPHIR_CALL_METHOD(&_47$$24, this_ptr, "getExpression", &_32, 0, &where, &_48$$24);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_47$$24, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_49 = zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_49) {
		ZEPHIR_CALL_METHOD(&_50$$25, this_ptr, "getLimitClause", NULL, 0, &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_50$$25, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&sqlUpdate);
}

/**
 * Refreshes the schema/source of every model referenced in a cached
 * intermediate representation. The PHQL cache is keyed by the PHQL
 * string only, so a model that switches its schema or source at
 * runtime (for instance via setSchema()/setSource() in initialize())
 * would otherwise see the value frozen at first parse. See #17020.
 *
 * @phpstan-param mvc_query_ir $irPhql
 * @phpstan-return mvc_query_ir
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, refreshSchemasInIntermediate)
{
	zend_string *_7;
	zend_ulong _6;
	zend_bool _1, _2, _16, _8$$6, _10$$6, _11$$6, _17$$15, _19$$15, _20$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *irPhql_param = NULL, __$null, manager, models, tables, modelName, model, schema, source, currentTable, alias, index, _0, *_3, _4, *_5, _15;
	zval irPhql, _12$$10, _13$$11, _14$$13, _21$$19, _22$$20, _23$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$22);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_15);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1083, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&manager) != IS_OBJECT) {
		RETURN_CTOR(&irPhql);
	}
	zephir_memory_observe(&models);
	_1 = zephir_array_isset_string_fetch(&models, &irPhql, SL("models"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		RETURN_CTOR(&irPhql);
	}
	zephir_memory_observe(&tables);
	_2 = zephir_array_isset_string_fetch(&tables, &irPhql, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		RETURN_CTOR(&irPhql);
	}
	if (Z_TYPE_P(&models) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &models);
		_3 = &_4;
	} else {
		_3 = &models;
	}
	zephir_is_iterable(_3, 0, "phalcon/Mvc/Model/Query.zep", 4668);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_3), _6, _7, _5)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&index, _7);
			} else {
				ZVAL_LONG(&index, _6);
			}
			ZEPHIR_INIT_NVAR(&modelName);
			ZVAL_COPY(&modelName, _5);
			_8$$6 = zephir_array_isset_value(&tables, &index);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_8$$6)) {
				continue;
			}
			ZEPHIR_CALL_METHOD(&model, &manager, "load", &_9, 0, &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&currentTable);
			zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4640);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_NULL(&alias);
			_10$$6 = Z_TYPE_P(&currentTable) == IS_ARRAY;
			if (_10$$6) {
				_11$$6 = zephir_array_isset_value_long(&currentTable, 2);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_10$$6 = _11$$6;
			}
			if (_10$$6) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4650);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&schema)) {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_12$$10);
					zephir_create_array(&_12$$10, 3, 0);
					zephir_array_fast_append(&_12$$10, &source);
					zephir_array_fast_append(&_12$$10, &schema);
					zephir_array_fast_append(&_12$$10, &alias);
					zephir_array_update_zval(&tables, &index, &_12$$10, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_13$$11);
					zephir_create_array(&_13$$11, 2, 0);
					zephir_array_fast_append(&_13$$11, &source);
					zephir_array_fast_append(&_13$$11, &schema);
					zephir_array_update_zval(&tables, &index, &_13$$11, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_14$$13);
					zephir_create_array(&_14$$13, 3, 0);
					zephir_array_fast_append(&_14$$13, &source);
					zephir_array_fast_append(&_14$$13, &__$null);
					zephir_array_fast_append(&_14$$13, &alias);
					zephir_array_update_zval(&tables, &index, &_14$$13, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_15, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&modelName, _3, "current", NULL, 0);
			zephir_check_call_status();
				_17$$15 = zephir_array_isset_value(&tables, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_17$$15)) {
					continue;
				}
				ZEPHIR_CALL_METHOD(&model, &manager, "load", &_18, 0, &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, &model, "getSchema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&source, &model, "getSource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&currentTable);
				zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4640);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&alias);
				ZVAL_NULL(&alias);
				_19$$15 = Z_TYPE_P(&currentTable) == IS_ARRAY;
				if (_19$$15) {
					_20$$15 = zephir_array_isset_value_long(&currentTable, 2);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_19$$15 = _20$$15;
				}
				if (_19$$15) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4650);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_is_true(&schema)) {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_21$$19);
						zephir_create_array(&_21$$19, 3, 0);
						zephir_array_fast_append(&_21$$19, &source);
						zephir_array_fast_append(&_21$$19, &schema);
						zephir_array_fast_append(&_21$$19, &alias);
						zephir_array_update_zval(&tables, &index, &_21$$19, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_22$$20);
						zephir_create_array(&_22$$20, 2, 0);
						zephir_array_fast_append(&_22$$20, &source);
						zephir_array_fast_append(&_22$$20, &schema);
						zephir_array_update_zval(&tables, &index, &_22$$20, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_23$$22);
						zephir_create_array(&_23$$22, 3, 0);
						zephir_array_fast_append(&_23$$22, &source);
						zephir_array_fast_append(&_23$$22, &__$null);
						zephir_array_fast_append(&_23$$22, &alias);
						zephir_array_update_zval(&tables, &index, &_23$$22, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_zval(&tables, &index, &source, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&modelName);
	ZEPHIR_INIT_NVAR(&index);
	zephir_array_update_string(&irPhql, SL("tables"), &tables, PH_COPY | PH_SEPARATE);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&irPhql);
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Query(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("bindTypes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindTypes"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("bindParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("bindParams"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

