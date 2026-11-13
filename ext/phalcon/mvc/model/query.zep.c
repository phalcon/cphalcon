
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "setDI", &_zephir_call_cache[0], container);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(&_1$$5, phalcon_support_settings_ce, "get", &_zephir_call_cache[1], &_2$$5);
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
	ZEND_TLS zephir_static_property_cache _zephir_sprop_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_cached(phalcon_mvc_model_query_ce, phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &_zephir_sprop_cache[0], &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&uniqueRow, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1076, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&cacheOptions, &_0);
	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (UNEXPECTED(Z_TYPE_P(&cacheOptions) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_model_query_exceptions_invalidcachingoptions_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$4, "__construct", &_zephir_call_cache[0]);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[1]);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&cache, &_5$$3, "getShared", &_zephir_call_cache[2], &cacheService);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "Phalcon\\Cache\\CacheInterface");
		ZEPHIR_CALL_FUNCTION(&_7$$3, "is_a", NULL, 63, &cache, &_6$$3);
		zephir_check_call_status();
		if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3))) {
			ZEPHIR_INIT_VAR(&_8$$7);
			object_init_ex(&_8$$7, phalcon_mvc_model_query_exceptions_invalidquerycacheservice_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$7, "__construct", &_zephir_call_cache[3]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$7, "phalcon/Mvc/Model/Query.zep", 369);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&adapter, &cache, "getAdapter", &_zephir_call_cache[4]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&cacheLifetime, &adapter, "getLifetime", &_zephir_call_cache[5]);
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
		ZEPHIR_CALL_METHOD_CACHED(&_10$$3, &cache, "has", &_zephir_call_cache[6], &key);
		zephir_check_call_status();
		if (zephir_is_true(&_10$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(&result, &cache, "get", &_zephir_call_cache[7], &key);
			zephir_check_call_status();
		}
		if (!(ZEPHIR_IS_EMPTY(&result))) {
			if (UNEXPECTED(Z_TYPE_P(&result) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_11$$11);
				object_init_ex(&_11$$11, phalcon_mvc_model_query_exceptions_invalidcachedresultset_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$11, "__construct", &_zephir_call_cache[8]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model/Query.zep", 390);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_BOOL(&_12$$10, 0);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &result, "setIsFresh", &_zephir_call_cache[9], &_12$$10);
			zephir_check_call_status();
			if (zephir_is_true(&uniqueRow)) {
				ZEPHIR_CALL_METHOD_CACHED(&preparedResult, &result, "getFirst", &_zephir_call_cache[10]);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&preparedResult, &result);
			}
			RETURN_CCTOR(&preparedResult);
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1079, &cache);
	}
	ZEPHIR_CALL_METHOD_CACHED(&intermediate, this_ptr, "parse", &_zephir_call_cache[11]);
	zephir_check_call_status();
	zephir_memory_observe(&defaultBindParams);
	zephir_read_property_cached(&defaultBindParams, this_ptr, _zephir_prop_4, 1074, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&mergedParams);
	zephir_add_function(&mergedParams, &defaultBindParams, &bindParams);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&defaultBindTypes);
	zephir_read_property_cached(&defaultBindTypes, this_ptr, _zephir_prop_5, 1075, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&type, &_0);
	if (ZEPHIR_IS_LONG(&type, 309)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&type, 306)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&type, 300)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&type, 303)) { goto zephir_switch_0_clause_3; }
	goto zephir_switch_0_clause_4;
	zephir_switch_0_clause_0: ;
		ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "executeSelect", &_zephir_call_cache[12], &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "executeInsert", &_zephir_call_cache[13], &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "executeUpdate", &_zephir_call_cache[14], &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		ZEPHIR_CALL_METHOD_CACHED(&result, this_ptr, "executeDelete", &_zephir_call_cache[15], &intermediate, &mergedParams, &mergedTypes);
		zephir_check_call_status();
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		ZEPHIR_INIT_VAR(&_13$$20);
		object_init_ex(&_13$$20, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$20, "__construct", &_zephir_call_cache[16], &type);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$20, "phalcon/Mvc/Model/Query.zep", 473);
		ZEPHIR_MM_RESTORE();
		return;
	zephir_switch_0_end: ;

	if (Z_TYPE_P(&cacheOptions) != IS_NULL) {
		if (!ZEPHIR_IS_LONG(&type, 309)) {
			ZEPHIR_INIT_VAR(&_14$$22);
			object_init_ex(&_14$$22, phalcon_mvc_model_query_exceptions_resultsetnoncacheable_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_14$$22, "__construct", &_zephir_call_cache[17]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$22, "phalcon/Mvc/Model/Query.zep", 484);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &cache, "set", &_zephir_call_cache[18], &key, &result, &lifetime);
		zephir_check_call_status();
	}
	if (zephir_is_true(&uniqueRow)) {
		ZEPHIR_CALL_METHOD_CACHED(&preparedResult, &result, "getFirst", &_zephir_call_cache[19]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "execute", &_zephir_call_cache[0], &bindParams, &bindTypes);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "execute", &_zephir_call_cache[1], &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_1, "getFirst", &_zephir_call_cache[2]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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

	ZEPHIR_CALL_METHOD_CACHED(&intermediate, this_ptr, "parse", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1080, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&_0, 309)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_1, 1074, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_2, 1075, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "executeSelect", &_zephir_call_cache[1], &intermediate, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_mvc_model_query_exceptions_multiplesqlstatementsnotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_4, "__construct", &_zephir_call_cache[2]);
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
	ZEND_TLS zephir_static_property_cache _zephir_sprop_cache[2];
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&intermediate, &_0);
	if (Z_TYPE_P(&intermediate) == IS_ARRAY) {
		RETURN_CCTOR(&intermediate);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&phql, &_0);
	ZEPHIR_CALL_CE_STATIC_CACHED(&ast, phalcon_mvc_model_query_lang_ce, "parsePHQL", &_zephir_call_cache[0], &phql);
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
			zephir_read_static_property_cached(&_2$$5, phalcon_mvc_model_query_ce, phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &_zephir_sprop_cache[0], PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
					ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "refreshSchemasInIntermediate", &_zephir_call_cache[1], &irPhql);
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
				ZEPHIR_CALL_METHOD_CACHED(&irPhql, this_ptr, "prepareSelect", &_zephir_call_cache[2]);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_CALL_METHOD_CACHED(&irPhql, this_ptr, "prepareInsert", &_zephir_call_cache[3]);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD_CACHED(&irPhql, this_ptr, "prepareUpdate", &_zephir_call_cache[4]);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_CALL_METHOD_CACHED(&irPhql, this_ptr, "prepareDelete", &_zephir_call_cache[5]);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_VAR(&_6$$13);
				object_init_ex(&_6$$13, phalcon_mvc_model_query_exceptions_unknownphqlstatement_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$13, "__construct", &_zephir_call_cache[6], &type, &phql);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$14, "__construct", &_zephir_call_cache[7]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$14, "phalcon/Mvc/Model/Query.zep", 730);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&uniqueId) == IS_LONG) {
		zephir_update_static_property_array_multi_cached(phalcon_mvc_model_query_ce, phalcon_mvc_model_query_ce, SL("internalPhqlCache"), &_zephir_sprop_cache[1], &irPhql, SL("z"), 1, &uniqueId);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	ZEPHIR_CALL_METHOD_CACHED(&manager, container, "getShared", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_query_exceptions_invalidinjectedmanager_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 798);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "modelsMetadata");
	ZEPHIR_CALL_METHOD_CACHED(&metaData, container, "getShared", &_zephir_call_cache[2], &_0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_mvc_model_query_exceptions_invalidinjectedmetadata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$4, "__construct", &_zephir_call_cache[3]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0], &resultsetRowClass_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Query.zep", 833);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Mvc\\Model\\Row");
	ZEPHIR_CALL_FUNCTION(&_2, "is_subclass_of", NULL, 41, &resultsetRowClass_zv, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_mvc_model_query_exceptions_invalidresultsetrowclass_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$4, "__construct", &_zephir_call_cache[1], &resultsetRowClass_zv);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, records, connection, record, exception, _2, _6, _10, _1$$3, _4$$4, _5$$5, _7$$7, _8$$8, _9$$6;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[16];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
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
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1088, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_fetch(&model, &_2, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&model, &_4$$4, "load", &_zephir_call_cache[1], &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&records, this_ptr, "getRelatedRecords", &_zephir_call_cache[2], &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_5$$5, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[3], &_5$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[4], &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "begin", &_zephir_call_cache[5]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &records, "rewind", &_zephir_call_cache[6]);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD_CACHED(&_6, &records, "valid", &_zephir_call_cache[7]);
		zephir_check_call_status();
		if (!(zephir_is_true(&_6))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD_CACHED(&record, &records, "current", &_zephir_call_cache[8]);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD_CACHED(&_7$$7, &record, "delete", &_zephir_call_cache[9]);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_7$$7))) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "rollback", &_zephir_call_cache[10]);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_8$$8, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[11], &_8$$8, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &records, "next", &_zephir_call_cache[12]);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_OBJ(&_9$$6, EG(exception));
			Z_ADDREF_P(&_9$$6);
			if (zephir_is_instance_of(&_9$$6, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_9$$6);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "rollback", &_zephir_call_cache[13]);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "commit", &_zephir_call_cache[14]);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_10, 1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[15], &_10);
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
	zend_bool automaticFields = 0, _1, _3, _23, _19$$8, _16$$11, _20$$14, _31$$17, _28$$20, _32$$23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, attributeName, attributes, connection, dialect, exprValue, fieldName, fields, insertModel, insertValue, insertValues, manager, metaData, model, modelName, number, value, values, wildcard, columnMap, _0, _2, *_7, _8, *_9, _22, _34, _4$$4, _5$$4, _6$$7, _12$$8, _13$$11, _14$$11, _15$$11, _17$$12, _18$$13, _21$$15, _24$$17, _25$$20, _26$$20, _27$$20, _29$$21, _30$$22, _33$$24;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_33$$24);
	ZEND_TLS zephir_method_cache _zephir_call_cache[28];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&model);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1088, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_fetch(&model, &_0, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[0], &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[1], &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&metaData, &_2);
	ZEPHIR_CALL_METHOD_CACHED(&attributes, &metaData, "getAttributes", &_zephir_call_cache[2], &model);
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
		ZEPHIR_CALL_CE_STATIC_CACHED(&_4$$4, phalcon_support_settings_ce, "get", &_zephir_call_cache[3], &_5$$4);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[4], &model);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$7, "__construct", &_zephir_call_cache[5]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$7, "phalcon/Mvc/Model/Query.zep", 1036);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&dialect, &connection, "getDialect", &_zephir_call_cache[6]);
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
				ZEPHIR_CALL_METHOD_CACHED(&insertValue, &dialect, "getSqlExpression", &_zephir_call_cache[7], &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				ZVAL_NULL(&insertValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD_CACHED(&_13$$11, &dialect, "getSqlExpression", &_zephir_call_cache[8], &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$11);
				ZVAL_STRING(&_14$$11, ":");
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_14$$11, &_15$$11, &_13$$11);
				ZEPHIR_OBS_NVAR(&insertValue);
				_16$$11 = zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_16$$11))) {
					ZEPHIR_INIT_NVAR(&_17$$12);
					object_init_ex(&_17$$12, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_17$$12, "__construct", &_zephir_call_cache[9], &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$12, "phalcon/Mvc/Model/Query.zep", 1070);
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&insertValue);
				object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
				ZEPHIR_CALL_METHOD_CACHED(&_18$$13, &dialect, "getSqlExpression", &_zephir_call_cache[10], &exprValue);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, &insertValue, "__construct", &_zephir_call_cache[11], &_18$$13);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			ZEPHIR_OBS_NVAR(&fieldName);
			zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1083);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_19$$8 = automaticFields;
			if (_19$$8) {
				_19$$8 = Z_TYPE_P(&columnMap) == IS_ARRAY;
			}
			if (_19$$8) {
				ZEPHIR_OBS_NVAR(&attributeName);
				_20$$14 = zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_20$$14))) {
					ZEPHIR_INIT_NVAR(&_21$$15);
					object_init_ex(&_21$$15, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$15, "__construct", &_zephir_call_cache[12], &fieldName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_21$$15, "phalcon/Mvc/Model/Query.zep", 1091);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _7, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_22, _7, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&number, _7, "key", &_zephir_call_cache[16]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, _7, "current", &_zephir_call_cache[17]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&exprValue);
				zephir_array_fetch_string(&exprValue, &value, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1046);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_24$$17);
				zephir_array_fetch_string(&_24$$17, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1048);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_24$$17, 260)) { goto zephir_switch_1_clause_0; }
				if (ZEPHIR_IS_LONG(&_24$$17, 258)) { goto zephir_switch_1_clause_1; }
				if (ZEPHIR_IS_LONG(&_24$$17, 259)) { goto zephir_switch_1_clause_2; }
				if (ZEPHIR_IS_LONG(&_24$$17, 322)) { goto zephir_switch_1_clause_3; }
				if (ZEPHIR_IS_LONG(&_24$$17, 273)) { goto zephir_switch_1_clause_4; }
				if (ZEPHIR_IS_LONG(&_24$$17, 274)) { goto zephir_switch_1_clause_5; }
				if (ZEPHIR_IS_LONG(&_24$$17, 277)) { goto zephir_switch_1_clause_6; }
				goto zephir_switch_1_clause_7;
				zephir_switch_1_clause_0: ;
				zephir_switch_1_clause_1: ;
				zephir_switch_1_clause_2: ;
					ZEPHIR_CALL_METHOD_CACHED(&insertValue, &dialect, "getSqlExpression", &_zephir_call_cache[18], &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					ZVAL_NULL(&insertValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD_CACHED(&_25$$20, &dialect, "getSqlExpression", &_zephir_call_cache[19], &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$20);
					ZVAL_STRING(&_26$$20, ":");
					ZEPHIR_INIT_NVAR(&_27$$20);
					ZVAL_STRING(&_27$$20, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_26$$20, &_27$$20, &_25$$20);
					ZEPHIR_OBS_NVAR(&insertValue);
					_28$$20 = zephir_array_isset_fetch(&insertValue, &bindParams, &wildcard, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_28$$20))) {
						ZEPHIR_INIT_NVAR(&_29$$21);
						object_init_ex(&_29$$21, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_29$$21, "__construct", &_zephir_call_cache[20], &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_29$$21, "phalcon/Mvc/Model/Query.zep", 1070);
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&insertValue);
					object_init_ex(&insertValue, phalcon_db_rawvalue_ce);
					ZEPHIR_CALL_METHOD_CACHED(&_30$$22, &dialect, "getSqlExpression", &_zephir_call_cache[21], &exprValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(NULL, &insertValue, "__construct", &_zephir_call_cache[22], &_30$$22);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				ZEPHIR_OBS_NVAR(&fieldName);
				zephir_array_fetch(&fieldName, &fields, &number, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1083);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_31$$17 = automaticFields;
				if (_31$$17) {
					_31$$17 = Z_TYPE_P(&columnMap) == IS_ARRAY;
				}
				if (_31$$17) {
					ZEPHIR_OBS_NVAR(&attributeName);
					_32$$23 = zephir_array_isset_fetch(&attributeName, &columnMap, &fieldName, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_32$$23))) {
						ZEPHIR_INIT_NVAR(&_33$$24);
						object_init_ex(&_33$$24, phalcon_mvc_model_query_exceptions_phqlcolumnnotinmap_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_33$$24, "__construct", &_zephir_call_cache[23], &fieldName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_33$$24, "phalcon/Mvc/Model/Query.zep", 1091);
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
	ZEPHIR_CALL_METHOD_CACHED(&insertModel, &manager, "load", &_zephir_call_cache[24], &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &insertModel, "assign", &_zephir_call_cache[25], &insertValues);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZEPHIR_CALL_METHOD_CACHED(&_34, &insertModel, "create", &_zephir_call_cache[26]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[27], &_34, &insertModel);
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
	zval _116$$87, _131$$88;
	zend_string *_35, *_92, *_99, *_109, *_160$$104;
	zend_ulong _34, _91, _98, _108, _159$$104;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_123 = NULL, *_127 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberObjects = 0;
	zend_bool simulate, haveObjects = 0, haveScalars = 0, isComplex = 0, isKeepingSnapshots = 0, isSimpleStd, _12, _27, _63, _95, _102, _129, _5$$3, _6$$3, _7$$3, _14$$9, _15$$9, _16$$9, _25$$17, _30$$22, _60$$32, _38$$33, _46$$35, _56$$41, _61$$47, _88$$50, _66$$51, _74$$53, _84$$59, _89$$65, _110$$84, _153$$101, _164$$104, _168$$92;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, *simulate_param = NULL, __$true, __$null, aliasCopy, attribute, attributes, bindCounts, cache, column, columnAlias, columnMap, columns, columns1, connectionTypes, dialect, instance, manager, metaData, modelName, models, processed, processedTypes, result, resultData, resultObject, resultsetClassName, selectColumns, simpleColumnMap, sqlAlias, sqlColumn, sqlSelect, typeWildcard, typesColumnMap, value, wildcard, wildcardValue, connection, model, _0, *_1, _2, *_3, _11, *_20, _21, *_22, _26, *_31, _32, *_33, _62, *_90, _94, *_97, _101, rawWildcards, rawValue, placeholder, *_105, _106, *_107, *_112, _113, *_114, _128, _141, _4$$3, _8$$3, _9$$7, _10$$8, _13$$9, _17$$9, _18$$13, _19$$14, _23$$16, _24$$15, _28$$21, _29$$20, _36$$32, _37$$33, _39$$35, _40$$35, *_41$$35, *_42$$35, _45$$35, _49$$35, _44$$38, _48$$39, _50$$40, *_51$$41, _52$$41, *_53$$41, _55$$41, _58$$45, _59$$46, _64$$50, _65$$51, _67$$53, _68$$53, *_69$$53, *_70$$53, _73$$53, _77$$53, _72$$56, _76$$57, _78$$58, *_79$$59, _80$$59, *_81$$59, _83$$59, _86$$63, _87$$64, _93$$71, _96$$75, _100$$77, _103$$80, _104$$83, _111$$86, _115$$87, _117$$87, _118$$87, _119$$87, _120$$87, _121$$87, _122$$87, _124$$87, _125$$87, _126$$87, _130$$88, _132$$88, _133$$88, _134$$88, _135$$88, _136$$88, _137$$88, _138$$88, _139$$88, _140$$88, _142$$93, _143$$94, _144$$96, _145$$96, _167$$96, _146$$101, *_147$$101, _148$$101, *_149$$101, _152$$101, _151$$102, _155$$103, *_156$$104, _157$$104, *_158$$104, _163$$104, _162$$105, _166$$106, _174$$92, _169$$109, _170$$108, _171$$108, _172$$110;
	zval intermediate, bindParams, bindTypes, _43$$38, _47$$39, _54$$42, _57$$43, _71$$56, _75$$57, _82$$60, _85$$61, _150$$102, _154$$103, _161$$105, _165$$106, _173$$108;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&intermediate);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_43$$38);
	ZVAL_UNDEF(&_47$$39);
	ZVAL_UNDEF(&_54$$42);
	ZVAL_UNDEF(&_57$$43);
	ZVAL_UNDEF(&_71$$56);
	ZVAL_UNDEF(&_75$$57);
	ZVAL_UNDEF(&_82$$60);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_150$$102);
	ZVAL_UNDEF(&_154$$103);
	ZVAL_UNDEF(&_161$$105);
	ZVAL_UNDEF(&_165$$106);
	ZVAL_UNDEF(&_173$$108);
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_94);
	ZVAL_UNDEF(&_101);
	ZVAL_UNDEF(&rawWildcards);
	ZVAL_UNDEF(&rawValue);
	ZVAL_UNDEF(&placeholder);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_113);
	ZVAL_UNDEF(&_128);
	ZVAL_UNDEF(&_141);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_36$$32);
	ZVAL_UNDEF(&_37$$33);
	ZVAL_UNDEF(&_39$$35);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_45$$35);
	ZVAL_UNDEF(&_49$$35);
	ZVAL_UNDEF(&_44$$38);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_50$$40);
	ZVAL_UNDEF(&_52$$41);
	ZVAL_UNDEF(&_55$$41);
	ZVAL_UNDEF(&_58$$45);
	ZVAL_UNDEF(&_59$$46);
	ZVAL_UNDEF(&_64$$50);
	ZVAL_UNDEF(&_65$$51);
	ZVAL_UNDEF(&_67$$53);
	ZVAL_UNDEF(&_68$$53);
	ZVAL_UNDEF(&_73$$53);
	ZVAL_UNDEF(&_77$$53);
	ZVAL_UNDEF(&_72$$56);
	ZVAL_UNDEF(&_76$$57);
	ZVAL_UNDEF(&_78$$58);
	ZVAL_UNDEF(&_80$$59);
	ZVAL_UNDEF(&_83$$59);
	ZVAL_UNDEF(&_86$$63);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_93$$71);
	ZVAL_UNDEF(&_96$$75);
	ZVAL_UNDEF(&_100$$77);
	ZVAL_UNDEF(&_103$$80);
	ZVAL_UNDEF(&_104$$83);
	ZVAL_UNDEF(&_111$$86);
	ZVAL_UNDEF(&_115$$87);
	ZVAL_UNDEF(&_117$$87);
	ZVAL_UNDEF(&_118$$87);
	ZVAL_UNDEF(&_119$$87);
	ZVAL_UNDEF(&_120$$87);
	ZVAL_UNDEF(&_121$$87);
	ZVAL_UNDEF(&_122$$87);
	ZVAL_UNDEF(&_124$$87);
	ZVAL_UNDEF(&_125$$87);
	ZVAL_UNDEF(&_126$$87);
	ZVAL_UNDEF(&_130$$88);
	ZVAL_UNDEF(&_132$$88);
	ZVAL_UNDEF(&_133$$88);
	ZVAL_UNDEF(&_134$$88);
	ZVAL_UNDEF(&_135$$88);
	ZVAL_UNDEF(&_136$$88);
	ZVAL_UNDEF(&_137$$88);
	ZVAL_UNDEF(&_138$$88);
	ZVAL_UNDEF(&_139$$88);
	ZVAL_UNDEF(&_140$$88);
	ZVAL_UNDEF(&_142$$93);
	ZVAL_UNDEF(&_143$$94);
	ZVAL_UNDEF(&_144$$96);
	ZVAL_UNDEF(&_145$$96);
	ZVAL_UNDEF(&_167$$96);
	ZVAL_UNDEF(&_146$$101);
	ZVAL_UNDEF(&_148$$101);
	ZVAL_UNDEF(&_152$$101);
	ZVAL_UNDEF(&_151$$102);
	ZVAL_UNDEF(&_155$$103);
	ZVAL_UNDEF(&_157$$104);
	ZVAL_UNDEF(&_163$$104);
	ZVAL_UNDEF(&_162$$105);
	ZVAL_UNDEF(&_166$$106);
	ZVAL_UNDEF(&_174$$92);
	ZVAL_UNDEF(&_169$$109);
	ZVAL_UNDEF(&_170$$108);
	ZVAL_UNDEF(&_171$$108);
	ZVAL_UNDEF(&_172$$110);
	ZVAL_UNDEF(&_116$$87);
	ZVAL_UNDEF(&_131$$88);
	ZEND_TLS zephir_method_cache _zephir_call_cache[90];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
			zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_1, 1088, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_5$$3 = zephir_array_isset_fetch(&model, &_4$$3, &modelName, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_5$$3)) {
				ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[0], &modelName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_6$$3 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$3 = _6$$3;
			if (_7$$3) {
				ZEPHIR_OBS_NVAR(&_8$$3);
				zephir_array_fetch_string(&_8$$3, &intermediate, SL("forUpdate"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1155);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_7$$3 = zephir_is_true(&_8$$3);
			}
			if (_7$$3) {
				ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[1], &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getReadConnection", &_zephir_call_cache[2], &model, &intermediate, &bindParams, &bindTypes);
				zephir_check_call_status();
			}
			if (Z_TYPE_P(&connection) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD_CACHED(&_9$$7, &connection, "getType", &_zephir_call_cache[3]);
				zephir_check_call_status();
				zephir_array_update_zval(&connectionTypes, &_9$$7, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
					ZEPHIR_INIT_NVAR(&_10$$8);
					object_init_ex(&_10$$8, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$8, "__construct", &_zephir_call_cache[4]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$8, "phalcon/Mvc/Model/Query.zep", 1176);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, _1, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&modelName, _1, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&model);
				zephir_read_property_cached(&_13$$9, this_ptr, _zephir_prop_1, 1088, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_14$$9 = zephir_array_isset_fetch(&model, &_13$$9, &modelName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_14$$9)) {
					ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[9], &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &model);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_15$$9 = zephir_array_isset_value_string(&intermediate, SL("forUpdate"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_16$$9 = _15$$9;
				if (_16$$9) {
					ZEPHIR_OBS_NVAR(&_17$$9);
					zephir_array_fetch_string(&_17$$9, &intermediate, SL("forUpdate"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1155);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_16$$9 = zephir_is_true(&_17$$9);
				}
				if (_16$$9) {
					ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[10], &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getReadConnection", &_zephir_call_cache[11], &model, &intermediate, &bindParams, &bindTypes);
					zephir_check_call_status();
				}
				if (Z_TYPE_P(&connection) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD_CACHED(&_18$$13, &connection, "getType", &_zephir_call_cache[12]);
					zephir_check_call_status();
					zephir_array_update_zval(&connectionTypes, &_18$$13, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(zephir_fast_count_int(&connectionTypes) == 2)) {
						ZEPHIR_INIT_NVAR(&_19$$14);
						object_init_ex(&_19$$14, phalcon_mvc_model_query_exceptions_mixeddatabasesystems_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_19$$14, "__construct", &_zephir_call_cache[13]);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$14, "phalcon/Mvc/Model/Query.zep", 1176);
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
		ZEPHIR_INIT_VAR(&_21);
		zephir_string_to_char_array(&_21, &columns);
		_20 = &_21;
	} else {
		_20 = &columns;
	}
	zephir_is_iterable(_20, 0, "phalcon/Mvc/Model/Query.zep", 1209);
	if (Z_TYPE_P(_20) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_20), _22)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _22);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_23$$16);
				object_init_ex(&_23$$16, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$16, "__construct", &_zephir_call_cache[14]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_23$$16, "phalcon/Mvc/Model/Query.zep", 1193);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_24$$15);
			zephir_array_fetch_string(&_24$$15, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1196);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_24$$15, "scalar")) {
				_25$$17 = zephir_array_isset_value_string(&column, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_25$$17)) {
					isComplex = 1;
				}
				haveScalars = 1;
			} else {
				haveObjects = 1;
				numberObjects++;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _20, "rewind", &_zephir_call_cache[15]);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _20, "next", &_zephir_call_cache[16]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_26, _20, "valid", &_zephir_call_cache[17]);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, _20, "current", &_zephir_call_cache[18]);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_28$$21);
					object_init_ex(&_28$$21, phalcon_mvc_model_query_exceptions_invalidcolumndefinition_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_28$$21, "__construct", &_zephir_call_cache[19]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_28$$21, "phalcon/Mvc/Model/Query.zep", 1193);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_29$$20);
				zephir_array_fetch_string(&_29$$20, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1196);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_29$$20, "scalar")) {
					_30$$22 = zephir_array_isset_value_string(&column, SL("balias"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_30$$22)) {
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&metaData, &_0);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_32);
		zephir_string_to_char_array(&_32, &columns);
		_31 = &_32;
	} else {
		_31 = &columns;
	}
	zephir_is_iterable(_31, 0, "phalcon/Mvc/Model/Query.zep", 1315);
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
			zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1232);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_36$$32);
			zephir_array_fetch_string(&_36$$32, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1235);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_36$$32, "object")) {
				ZEPHIR_OBS_NVAR(&modelName);
				zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1236);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&instance);
				zephir_read_property_cached(&_37$$33, this_ptr, _zephir_prop_1, 1088, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_38$$33 = zephir_array_isset_fetch(&instance, &_37$$33, &modelName, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_38$$33)) {
					ZEPHIR_CALL_METHOD_CACHED(&instance, &manager, "load", &_zephir_call_cache[20], &modelName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&attributes, &metaData, "getAttributes", &_zephir_call_cache[21], &instance);
				zephir_check_call_status();
				if (isComplex) {
					ZEPHIR_INIT_NVAR(&_40$$35);
					ZVAL_STRING(&_40$$35, "orm.column_renaming");
					ZEPHIR_CALL_CE_STATIC_CACHED(&_39$$35, phalcon_support_settings_ce, "get", &_zephir_call_cache[22], &_40$$35);
					zephir_check_call_status();
					if (zephir_is_true(&_39$$35)) {
						ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[23], &instance);
						zephir_check_call_status();
					} else {
						ZEPHIR_INIT_NVAR(&columnMap);
						ZVAL_NULL(&columnMap);
					}
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_40$$35);
						zephir_string_to_char_array(&_40$$35, &attributes);
						_41$$35 = &_40$$35;
					} else {
						_41$$35 = &attributes;
					}
					zephir_is_iterable(_41$$35, 0, "phalcon/Mvc/Model/Query.zep", 1272);
					if (Z_TYPE_P(_41$$35) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41$$35), _42$$35)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _42$$35);
							ZEPHIR_INIT_NVAR(&_43$$38);
							zephir_create_array(&_43$$38, 3, 0);
							zephir_array_fast_append(&_43$$38, &attribute);
							zephir_array_fast_append(&_43$$38, &sqlColumn);
							ZEPHIR_INIT_NVAR(&_44$$38);
							ZEPHIR_CONCAT_SVSV(&_44$$38, "_", &sqlColumn, "_", &attribute);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_43$$38, &_44$$38);
							zephir_array_append(&selectColumns, &_43$$38, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$35, "rewind", &_zephir_call_cache[24]);
						zephir_check_call_status();
						_46$$35 = 1;
						while (1) {
							if (_46$$35) {
								_46$$35 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$35, "next", &_zephir_call_cache[25]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_45$$35, _41$$35, "valid", &_zephir_call_cache[26]);
							zephir_check_call_status();
							if (!zend_is_true(&_45$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _41$$35, "current", &_zephir_call_cache[27]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_47$$39);
								zephir_create_array(&_47$$39, 3, 0);
								zephir_array_fast_append(&_47$$39, &attribute);
								zephir_array_fast_append(&_47$$39, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_48$$39);
								ZEPHIR_CONCAT_SVSV(&_48$$39, "_", &sqlColumn, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_47$$39, &_48$$39);
								zephir_array_append(&selectColumns, &_47$$39, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
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
					ZEPHIR_CALL_METHOD_CACHED(&_49$$35, &manager, "isKeepingSnapshots", &_zephir_call_cache[28], &instance);
					zephir_check_call_status();
					isKeepingSnapshots = zephir_get_boolval(&_49$$35);
					if (isKeepingSnapshots) {
						ZEPHIR_INIT_NVAR(&_50$$40);
						ZVAL_BOOL(&_50$$40, isKeepingSnapshots);
						zephir_array_update_multi(&columns1, &_50$$40, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (Z_TYPE_P(&attributes) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_52$$41);
						zephir_string_to_char_array(&_52$$41, &attributes);
						_51$$41 = &_52$$41;
					} else {
						_51$$41 = &attributes;
					}
					zephir_is_iterable(_51$$41, 0, "phalcon/Mvc/Model/Query.zep", 1289);
					if (Z_TYPE_P(_51$$41) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_51$$41), _53$$41)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _53$$41);
							ZEPHIR_INIT_NVAR(&_54$$42);
							zephir_create_array(&_54$$42, 2, 0);
							zephir_array_fast_append(&_54$$42, &attribute);
							zephir_array_fast_append(&_54$$42, &sqlColumn);
							zephir_array_append(&selectColumns, &_54$$42, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$41, "rewind", &_zephir_call_cache[29]);
						zephir_check_call_status();
						_56$$41 = 1;
						while (1) {
							if (_56$$41) {
								_56$$41 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _51$$41, "next", &_zephir_call_cache[30]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_55$$41, _51$$41, "valid", &_zephir_call_cache[31]);
							zephir_check_call_status();
							if (!zend_is_true(&_55$$41)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _51$$41, "current", &_zephir_call_cache[32]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_57$$43);
								zephir_create_array(&_57$$43, 2, 0);
								zephir_array_fast_append(&_57$$43, &attribute);
								zephir_array_fast_append(&_57$$43, &sqlColumn);
								zephir_array_append(&selectColumns, &_57$$43, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
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
					ZEPHIR_INIT_NVAR(&_58$$45);
					zephir_create_array(&_58$$45, 2, 0);
					zephir_array_fast_append(&_58$$45, &sqlColumn);
					zephir_array_fast_append(&_58$$45, &__$null);
					ZEPHIR_CPY_WRT(&columnAlias, &_58$$45);
				} else {
					ZEPHIR_INIT_NVAR(&_59$$46);
					zephir_create_array(&_59$$46, 3, 0);
					zephir_array_fast_append(&_59$$46, &sqlColumn);
					zephir_array_fast_append(&_59$$46, &__$null);
					zephir_array_fast_append(&_59$$46, &aliasCopy);
					ZEPHIR_CPY_WRT(&columnAlias, &_59$$46);
				}
				zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1300);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_60$$32 = !isComplex;
			if (_60$$32) {
				_60$$32 = isSimpleStd;
			}
			if (_60$$32) {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				_61$$47 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_61$$47) {
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _31, "rewind", &_zephir_call_cache[33]);
		zephir_check_call_status();
		_63 = 1;
		while (1) {
			if (_63) {
				_63 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _31, "next", &_zephir_call_cache[34]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_62, _31, "valid", &_zephir_call_cache[35]);
			zephir_check_call_status();
			if (!zend_is_true(&_62)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&aliasCopy, _31, "key", &_zephir_call_cache[36]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&column, _31, "current", &_zephir_call_cache[37]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sqlColumn);
				zephir_array_fetch_string(&sqlColumn, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1232);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_64$$50);
				zephir_array_fetch_string(&_64$$50, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1235);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_64$$50, "object")) {
					ZEPHIR_OBS_NVAR(&modelName);
					zephir_array_fetch_string(&modelName, &column, SL("model"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1236);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&instance);
					zephir_read_property_cached(&_65$$51, this_ptr, _zephir_prop_1, 1088, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_66$$51 = zephir_array_isset_fetch(&instance, &_65$$51, &modelName, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_66$$51)) {
						ZEPHIR_CALL_METHOD_CACHED(&instance, &manager, "load", &_zephir_call_cache[38], &modelName);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("modelsInstances"), &modelName, &instance);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&attributes, &metaData, "getAttributes", &_zephir_call_cache[39], &instance);
					zephir_check_call_status();
					if (isComplex) {
						ZEPHIR_INIT_NVAR(&_68$$53);
						ZVAL_STRING(&_68$$53, "orm.column_renaming");
						ZEPHIR_CALL_CE_STATIC_CACHED(&_67$$53, phalcon_support_settings_ce, "get", &_zephir_call_cache[40], &_68$$53);
						zephir_check_call_status();
						if (zephir_is_true(&_67$$53)) {
							ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[41], &instance);
							zephir_check_call_status();
						} else {
							ZEPHIR_INIT_NVAR(&columnMap);
							ZVAL_NULL(&columnMap);
						}
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_68$$53);
							zephir_string_to_char_array(&_68$$53, &attributes);
							_69$$53 = &_68$$53;
						} else {
							_69$$53 = &attributes;
						}
						zephir_is_iterable(_69$$53, 0, "phalcon/Mvc/Model/Query.zep", 1272);
						if (Z_TYPE_P(_69$$53) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_69$$53), _70$$53)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _70$$53);
								ZEPHIR_INIT_NVAR(&_71$$56);
								zephir_create_array(&_71$$56, 3, 0);
								zephir_array_fast_append(&_71$$56, &attribute);
								zephir_array_fast_append(&_71$$56, &sqlColumn);
								ZEPHIR_INIT_NVAR(&_72$$56);
								ZEPHIR_CONCAT_SVSV(&_72$$56, "_", &sqlColumn, "_", &attribute);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_71$$56, &_72$$56);
								zephir_array_append(&selectColumns, &_71$$56, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$53, "rewind", &_zephir_call_cache[42]);
							zephir_check_call_status();
							_74$$53 = 1;
							while (1) {
								if (_74$$53) {
									_74$$53 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _69$$53, "next", &_zephir_call_cache[43]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_73$$53, _69$$53, "valid", &_zephir_call_cache[44]);
								zephir_check_call_status();
								if (!zend_is_true(&_73$$53)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&attribute, _69$$53, "current", &_zephir_call_cache[45]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_75$$57);
									zephir_create_array(&_75$$57, 3, 0);
									zephir_array_fast_append(&_75$$57, &attribute);
									zephir_array_fast_append(&_75$$57, &sqlColumn);
									ZEPHIR_INIT_NVAR(&_76$$57);
									ZEPHIR_CONCAT_SVSV(&_76$$57, "_", &sqlColumn, "_", &attribute);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_fast_append(&_75$$57, &_76$$57);
									zephir_array_append(&selectColumns, &_75$$57, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1265);
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
						ZEPHIR_CALL_METHOD_CACHED(&_77$$53, &manager, "isKeepingSnapshots", &_zephir_call_cache[46], &instance);
						zephir_check_call_status();
						isKeepingSnapshots = zephir_get_boolval(&_77$$53);
						if (isKeepingSnapshots) {
							ZEPHIR_INIT_NVAR(&_78$$58);
							ZVAL_BOOL(&_78$$58, isKeepingSnapshots);
							zephir_array_update_multi(&columns1, &_78$$58, SL("zs"), 3, &aliasCopy, SL("keepSnapshots"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						if (Z_TYPE_P(&attributes) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_80$$59);
							zephir_string_to_char_array(&_80$$59, &attributes);
							_79$$59 = &_80$$59;
						} else {
							_79$$59 = &attributes;
						}
						zephir_is_iterable(_79$$59, 0, "phalcon/Mvc/Model/Query.zep", 1289);
						if (Z_TYPE_P(_79$$59) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_79$$59), _81$$59)
							{
								ZEPHIR_INIT_NVAR(&attribute);
								ZVAL_COPY(&attribute, _81$$59);
								ZEPHIR_INIT_NVAR(&_82$$60);
								zephir_create_array(&_82$$60, 2, 0);
								zephir_array_fast_append(&_82$$60, &attribute);
								zephir_array_fast_append(&_82$$60, &sqlColumn);
								zephir_array_append(&selectColumns, &_82$$60, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _79$$59, "rewind", &_zephir_call_cache[47]);
							zephir_check_call_status();
							_84$$59 = 1;
							while (1) {
								if (_84$$59) {
									_84$$59 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _79$$59, "next", &_zephir_call_cache[48]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_83$$59, _79$$59, "valid", &_zephir_call_cache[49]);
								zephir_check_call_status();
								if (!zend_is_true(&_83$$59)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&attribute, _79$$59, "current", &_zephir_call_cache[50]);
								zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_85$$61);
									zephir_create_array(&_85$$61, 2, 0);
									zephir_array_fast_append(&_85$$61, &attribute);
									zephir_array_fast_append(&_85$$61, &sqlColumn);
									zephir_array_append(&selectColumns, &_85$$61, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1287);
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
						ZEPHIR_INIT_NVAR(&_86$$63);
						zephir_create_array(&_86$$63, 2, 0);
						zephir_array_fast_append(&_86$$63, &sqlColumn);
						zephir_array_fast_append(&_86$$63, &__$null);
						ZEPHIR_CPY_WRT(&columnAlias, &_86$$63);
					} else {
						ZEPHIR_INIT_NVAR(&_87$$64);
						zephir_create_array(&_87$$64, 3, 0);
						zephir_array_fast_append(&_87$$64, &sqlColumn);
						zephir_array_fast_append(&_87$$64, &__$null);
						zephir_array_fast_append(&_87$$64, &aliasCopy);
						ZEPHIR_CPY_WRT(&columnAlias, &_87$$64);
					}
					zephir_array_append(&selectColumns, &columnAlias, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1300);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_88$$50 = !isComplex;
				if (_88$$50) {
					_88$$50 = isSimpleStd;
				}
				if (_88$$50) {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					_89$$65 = zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_89$$65) {
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
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindParams), _91, _92, _90)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			if (_92 != NULL) { 
				ZVAL_STR_COPY(&wildcard, _92);
			} else {
				ZVAL_LONG(&wildcard, _91);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _90);
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
				ZEPHIR_INIT_NVAR(&_93$$71);
				ZVAL_LONG(&_93$$71, zephir_fast_count_int(&value));
				zephir_array_update_zval(&bindCounts, &wildcardValue, &_93$$71, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &bindParams, "rewind", &_zephir_call_cache[51]);
		zephir_check_call_status();
		_95 = 1;
		while (1) {
			if (_95) {
				_95 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &bindParams, "next", &_zephir_call_cache[52]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_94, &bindParams, "valid", &_zephir_call_cache[53]);
			zephir_check_call_status();
			if (!zend_is_true(&_94)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&wildcard, &bindParams, "key", &_zephir_call_cache[54]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &bindParams, "current", &_zephir_call_cache[55]);
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
					ZEPHIR_INIT_NVAR(&_96$$75);
					ZVAL_LONG(&_96$$75, zephir_fast_count_int(&value));
					zephir_array_update_zval(&bindCounts, &wildcardValue, &_96$$75, PH_COPY | PH_SEPARATE);
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
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&bindTypes), _98, _99, _97)
		{
			ZEPHIR_INIT_NVAR(&typeWildcard);
			if (_99 != NULL) { 
				ZVAL_STR_COPY(&typeWildcard, _99);
			} else {
				ZVAL_LONG(&typeWildcard, _98);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _97);
			if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
				ZEPHIR_INIT_NVAR(&_100$$77);
				ZEPHIR_CONCAT_SV(&_100$$77, ":", &typeWildcard);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&processedTypes, &_100$$77, &value, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &bindTypes, "rewind", &_zephir_call_cache[56]);
		zephir_check_call_status();
		_102 = 1;
		while (1) {
			if (_102) {
				_102 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &bindTypes, "next", &_zephir_call_cache[57]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_101, &bindTypes, "valid", &_zephir_call_cache[58]);
			zephir_check_call_status();
			if (!zend_is_true(&_101)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&typeWildcard, &bindTypes, "key", &_zephir_call_cache[59]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &bindTypes, "current", &_zephir_call_cache[60]);
			zephir_check_call_status();
				if (Z_TYPE_P(&typeWildcard) == IS_LONG) {
					ZEPHIR_INIT_NVAR(&_103$$80);
					ZEPHIR_CONCAT_SV(&_103$$80, ":", &typeWildcard);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&processedTypes, &_103$$80, &value, PH_COPY | PH_SEPARATE);
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
	ZEPHIR_CALL_METHOD_CACHED(&dialect, &connection, "getDialect", &_zephir_call_cache[61]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&sqlSelect, &dialect, "select", &_zephir_call_cache[62], &intermediate);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1086, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&_104$$83, &dialect, "sharedLock", &_zephir_call_cache[63], &sqlSelect);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&sqlSelect, &_104$$83);
	}
	ZEPHIR_INIT_VAR(&rawWildcards);
	array_init(&rawWildcards);
	if (Z_TYPE_P(&processed) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_106);
		zephir_string_to_char_array(&_106, &processed);
		_105 = &_106;
	} else {
		_105 = &processed;
	}
	zephir_is_iterable(_105, 0, "phalcon/Mvc/Model/Query.zep", 1388);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_105), _108, _109, _107)
	{
		ZEPHIR_INIT_NVAR(&wildcard);
		if (_109 != NULL) { 
			ZVAL_STR_COPY(&wildcard, _109);
		} else {
			ZVAL_LONG(&wildcard, _108);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _107);
		_110$$84 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_110$$84) {
			_110$$84 = zephir_instance_of_ev(&value, phalcon_db_rawvalue_ce);
		}
		if (_110$$84) {
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
		ZEPHIR_INIT_VAR(&_111$$86);
		ZEPHIR_INIT_NVAR(&_111$$86);
		zephir_create_closure_ex(&_111$$86, NULL, phalcon_89__closure_ce, SL("__invoke"));
		ZEPHIR_MAKE_REF(&rawWildcards);
		ZEPHIR_CALL_FUNCTION(NULL, "usort", NULL, 230, &rawWildcards, &_111$$86);
		ZEPHIR_UNREF(&rawWildcards);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&rawWildcards) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_113);
		zephir_string_to_char_array(&_113, &rawWildcards);
		_112 = &_113;
	} else {
		_112 = &rawWildcards;
	}
	zephir_is_iterable(_112, 0, "phalcon/Mvc/Model/Query.zep", 1415);
	if (Z_TYPE_P(_112) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_112), _114)
		{
			ZEPHIR_INIT_NVAR(&wildcard);
			ZVAL_COPY(&wildcard, _114);
			ZEPHIR_OBS_NVAR(&_115$$87);
			zephir_array_fetch(&_115$$87, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1398);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_116$$87, &_115$$87);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&rawValue, &_116$$87);
			ZVAL_LONG(&_117$$87, 0);
			ZVAL_LONG(&_118$$87, 1);
			ZEPHIR_INIT_NVAR(&_119$$87);
			zephir_substr(&_119$$87, &wildcard, 0 , 1 , 0);
			if (ZEPHIR_IS_STRING_IDENTICAL(&_119$$87, ":")) {
				ZVAL_LONG(&_120$$87, 1);
				ZEPHIR_INIT_NVAR(&placeholder);
				zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			} else {
				ZEPHIR_CPY_WRT(&placeholder, &wildcard);
			}
			ZEPHIR_INIT_NVAR(&_121$$87);
			ZVAL_STRING(&_121$$87, "/");
			ZEPHIR_CALL_FUNCTION(&_122$$87, "preg_quote", &_123, 173, &placeholder, &_121$$87);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_124$$87);
			ZEPHIR_CONCAT_SVS(&_124$$87, "/:", &_122$$87, "\\b/");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_121$$87);
			object_init_ex(&_121$$87, phalcon_90__closure_ce);
			zephir_update_property_zval(&_121$$87, SL("rawValue"), &rawValue);
			ZEPHIR_INIT_NVAR(&_125$$87);
			ZEPHIR_INIT_NVAR(&_125$$87);
			zephir_create_closure_bound(&_125$$87, &_121$$87, NULL, phalcon_90__closure_ce, SL("__invoke"));
			ZEPHIR_CALL_FUNCTION(&_126$$87, "preg_replace_callback", &_127, 227, &_124$$87, &_125$$87, &sqlSelect);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&sqlSelect, &_126$$87);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _112, "rewind", &_zephir_call_cache[64]);
		zephir_check_call_status();
		_129 = 1;
		while (1) {
			if (_129) {
				_129 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _112, "next", &_zephir_call_cache[65]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_128, _112, "valid", &_zephir_call_cache[66]);
			zephir_check_call_status();
			if (!zend_is_true(&_128)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&wildcard, _112, "current", &_zephir_call_cache[67]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_130$$88);
				zephir_array_fetch(&_130$$88, &processed, &wildcard, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1398);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_131$$88, &_130$$88);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&rawValue, &_131$$88);
				ZVAL_LONG(&_132$$88, 0);
				ZVAL_LONG(&_133$$88, 1);
				ZEPHIR_INIT_NVAR(&_134$$88);
				zephir_substr(&_134$$88, &wildcard, 0 , 1 , 0);
				if (ZEPHIR_IS_STRING_IDENTICAL(&_134$$88, ":")) {
					ZVAL_LONG(&_135$$88, 1);
					ZEPHIR_INIT_NVAR(&placeholder);
					zephir_substr(&placeholder, &wildcard, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
				} else {
					ZEPHIR_CPY_WRT(&placeholder, &wildcard);
				}
				ZEPHIR_INIT_NVAR(&_136$$88);
				ZVAL_STRING(&_136$$88, "/");
				ZEPHIR_CALL_FUNCTION(&_137$$88, "preg_quote", &_123, 173, &placeholder, &_136$$88);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_138$$88);
				ZEPHIR_CONCAT_SVS(&_138$$88, "/:", &_137$$88, "\\b/");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_136$$88);
				object_init_ex(&_136$$88, phalcon_91__closure_ce);
				zephir_update_property_zval(&_136$$88, SL("rawValue"), &rawValue);
				ZEPHIR_INIT_NVAR(&_139$$88);
				ZEPHIR_INIT_NVAR(&_139$$88);
				zephir_create_closure_bound(&_139$$88, &_136$$88, NULL, phalcon_91__closure_ce, SL("__invoke"));
				ZEPHIR_CALL_FUNCTION(&_140$$88, "preg_replace_callback", &_127, 227, &_138$$88, &_139$$88, &sqlSelect);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&sqlSelect, &_140$$88);
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
	ZEPHIR_CALL_METHOD_CACHED(&result, &connection, "query", &_zephir_call_cache[68], &sqlSelect, &processed, &processedTypes);
	zephir_check_call_status();
	if (zephir_instance_of_ev(&result, phalcon_db_resultinterface_ce)) {
		ZEPHIR_CPY_WRT(&resultData, &result);
	} else {
		ZEPHIR_INIT_NVAR(&resultData);
		ZVAL_NULL(&resultData);
	}
	zephir_read_property_cached(&_141, this_ptr, _zephir_prop_4, 1079, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&cache, &_141);
	if (!(isComplex)) {
		if (isSimpleStd) {
			zephir_read_property_cached(&_142$$93, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!ZEPHIR_IS_STRING_IDENTICAL(&_142$$93, "")) {
				zephir_read_property_cached(&_143$$94, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&resultObject);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&resultObject, &_143$$94);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&resultObject);
				object_init_ex(&resultObject, phalcon_mvc_model_row_ce);
				if (zephir_has_constructor(&resultObject)) {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &resultObject, "__construct", &_zephir_call_cache[69]);
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
			ZEPHIR_INIT_VAR(&_145$$96);
			ZVAL_STRING(&_145$$96, "orm.cast_on_hydrate");
			ZEPHIR_CALL_CE_STATIC_CACHED(&_144$$96, phalcon_support_settings_ce, "get", &_zephir_call_cache[70], &_145$$96);
			zephir_check_call_status();
			if (!(zephir_is_true(&_144$$96))) {
				ZEPHIR_CALL_METHOD_CACHED(&simpleColumnMap, &metaData, "getColumnMap", &_zephir_call_cache[71], &resultObject);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getColumnMap", &_zephir_call_cache[72], &resultObject);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&typesColumnMap, &metaData, "getDataTypes", &_zephir_call_cache[73], &resultObject);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&simpleColumnMap);
				if (Z_TYPE_P(&columnMap) == IS_NULL) {
					array_init(&simpleColumnMap);
					ZEPHIR_CALL_METHOD_CACHED(&_146$$101, &metaData, "getAttributes", &_zephir_call_cache[74], &resultObject);
					zephir_check_call_status();
					if (Z_TYPE_P(&_146$$101) == IS_STRING) {
						ZEPHIR_INIT_VAR(&_148$$101);
						zephir_string_to_char_array(&_148$$101, &_146$$101);
						_147$$101 = &_148$$101;
					} else {
						_147$$101 = &_146$$101;
					}
					zephir_is_iterable(_147$$101, 0, "phalcon/Mvc/Model/Query.zep", 1489);
					if (Z_TYPE_P(_147$$101) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_147$$101), _149$$101)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _149$$101);
							ZEPHIR_INIT_NVAR(&_150$$102);
							zephir_create_array(&_150$$102, 2, 0);
							zephir_array_fast_append(&_150$$102, &attribute);
							ZEPHIR_OBS_NVAR(&_151$$102);
							zephir_array_fetch(&_151$$102, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1487);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_150$$102, &_151$$102);
							zephir_array_update_zval(&simpleColumnMap, &attribute, &_150$$102, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _147$$101, "rewind", &_zephir_call_cache[75]);
						zephir_check_call_status();
						_153$$101 = 1;
						while (1) {
							if (_153$$101) {
								_153$$101 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _147$$101, "next", &_zephir_call_cache[76]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_152$$101, _147$$101, "valid", &_zephir_call_cache[77]);
							zephir_check_call_status();
							if (!zend_is_true(&_152$$101)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _147$$101, "current", &_zephir_call_cache[78]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_154$$103);
								zephir_create_array(&_154$$103, 2, 0);
								zephir_array_fast_append(&_154$$103, &attribute);
								ZEPHIR_OBS_NVAR(&_155$$103);
								zephir_array_fetch(&_155$$103, &typesColumnMap, &attribute, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1487);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_154$$103, &_155$$103);
								zephir_array_update_zval(&simpleColumnMap, &attribute, &_154$$103, PH_COPY | PH_SEPARATE);
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
						ZEPHIR_INIT_VAR(&_157$$104);
						zephir_string_to_char_array(&_157$$104, &columnMap);
						_156$$104 = &_157$$104;
					} else {
						_156$$104 = &columnMap;
					}
					zephir_is_iterable(_156$$104, 0, "phalcon/Mvc/Model/Query.zep", 1498);
					if (Z_TYPE_P(_156$$104) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_156$$104), _159$$104, _160$$104, _158$$104)
						{
							ZEPHIR_INIT_NVAR(&column);
							if (_160$$104 != NULL) { 
								ZVAL_STR_COPY(&column, _160$$104);
							} else {
								ZVAL_LONG(&column, _159$$104);
							}
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _158$$104);
							ZEPHIR_INIT_NVAR(&_161$$105);
							zephir_create_array(&_161$$105, 2, 0);
							zephir_array_fast_append(&_161$$105, &attribute);
							ZEPHIR_OBS_NVAR(&_162$$105);
							zephir_array_fetch(&_162$$105, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1496);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_fast_append(&_161$$105, &_162$$105);
							zephir_array_update_zval(&simpleColumnMap, &column, &_161$$105, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _156$$104, "rewind", &_zephir_call_cache[79]);
						zephir_check_call_status();
						_164$$104 = 1;
						while (1) {
							if (_164$$104) {
								_164$$104 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _156$$104, "next", &_zephir_call_cache[80]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_163$$104, _156$$104, "valid", &_zephir_call_cache[81]);
							zephir_check_call_status();
							if (!zend_is_true(&_163$$104)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&column, _156$$104, "key", &_zephir_call_cache[82]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&attribute, _156$$104, "current", &_zephir_call_cache[83]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_165$$106);
								zephir_create_array(&_165$$106, 2, 0);
								zephir_array_fast_append(&_165$$106, &attribute);
								ZEPHIR_OBS_NVAR(&_166$$106);
								zephir_array_fetch(&_166$$106, &typesColumnMap, &column, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1496);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_fast_append(&_165$$106, &_166$$106);
								zephir_array_update_zval(&simpleColumnMap, &column, &_165$$106, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD_CACHED(&_167$$96, &manager, "isKeepingSnapshots", &_zephir_call_cache[84], &resultObject);
			zephir_check_call_status();
			isKeepingSnapshots = zephir_get_boolval(&_167$$96);
		}
		_168$$92 = zephir_instance_of_ev(&resultObject, phalcon_mvc_modelinterface_ce);
		if (_168$$92) {
			_168$$92 = (zephir_method_exists_ex(&resultObject, ZEND_STRL("getresultsetclass")) == SUCCESS);
		}
		if (_168$$92) {
			ZEPHIR_CALL_METHOD_CACHED(&resultsetClassName, &resultObject, "getResultsetClass", &_zephir_call_cache[85]);
			zephir_check_call_status();
			if (zephir_is_true(&resultsetClassName)) {
				if (UNEXPECTED(!(zephir_class_exists(&resultsetClassName, 1)))) {
					ZEPHIR_INIT_VAR(&_169$$109);
					object_init_ex(&_169$$109, phalcon_mvc_model_query_exceptions_resultsetclassnotfound_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_169$$109, "__construct", &_zephir_call_cache[86], &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_169$$109, "phalcon/Mvc/Model/Query.zep", 1512);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_170$$108);
				ZVAL_STRING(&_170$$108, "Phalcon\\Mvc\\Model\\ResultsetInterface");
				ZEPHIR_CALL_FUNCTION(&_171$$108, "is_subclass_of", NULL, 41, &resultsetClassName, &_170$$108);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_171$$108))) {
					ZEPHIR_INIT_VAR(&_172$$110);
					object_init_ex(&_172$$110, phalcon_mvc_model_query_exceptions_invalidresultsetclass_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_172$$110, "__construct", &_zephir_call_cache[87], &resultsetClassName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_172$$110, "phalcon/Mvc/Model/Query.zep", 1516);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_173$$108);
				zephir_create_array(&_173$$108, 5, 0);
				zephir_array_fast_append(&_173$$108, &simpleColumnMap);
				zephir_array_fast_append(&_173$$108, &resultObject);
				zephir_array_fast_append(&_173$$108, &resultData);
				zephir_array_fast_append(&_173$$108, &cache);
				ZEPHIR_INIT_NVAR(&_170$$108);
				ZVAL_BOOL(&_170$$108, isKeepingSnapshots);
				zephir_array_fast_append(&_173$$108, &_170$$108);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &resultsetClassName, &_173$$108);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		object_init_ex(return_value, phalcon_mvc_model_resultset_simple_ce);
		if (isKeepingSnapshots) {
			ZVAL_BOOL(&_174$$92, 1);
		} else {
			ZVAL_BOOL(&_174$$92, 0);
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[88], &simpleColumnMap, &resultObject, &resultData, &cache, &_174$$92);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_mvc_model_resultset_complex_ce);
	zephir_read_property_cached(&_141, this_ptr, _zephir_prop_5, 1085, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[89], &columns1, &resultData, &cache, &_141);
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
	zval _33$$16, _40$$17, _49$$20, _55$$21, _79$$33, _85$$34, _94$$37, _100$$38;
	zend_string *_9;
	zend_ulong _8;
	zend_bool _0, _3, _58, _10$$5, _15$$10, _43$$13, _27$$14, _28$$15, _44$$18, _45$$19, _59$$22, _64$$27, _88$$30, _74$$31, _75$$32, _89$$35, _90$$36;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_23 = NULL, *_31 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediate_param = NULL, *bindParams_param = NULL, *bindTypes_param = NULL, models, modelName, model, connection, dialect, fields, values, updateValues, fieldName, value, selectBindParams, selectBindTypes, number, field, records, exprValue, updateValue, wildcard, record, exception, sqlExpr, namedParams, paramKey, paramKeys, paramValue, _2, *_5, _6, *_7, _57, _103, _107, _1$$3, _4$$4, _11$$5, _12$$10, _13$$10, _14$$10, _16$$11, _17$$12, _18$$12, _19$$12, _20$$13, _22$$13, *_24$$13, _25$$13, *_26$$13, _42$$13, _29$$16, _30$$16, _32$$16, _34$$16, _36$$17, _37$$17, _38$$17, _39$$17, _41$$17, _46$$20, _47$$20, _48$$20, _50$$20, _51$$21, _52$$21, _53$$21, _54$$21, _56$$21, _60$$22, _61$$27, _62$$27, _63$$27, _65$$28, _66$$29, _67$$29, _68$$29, _69$$30, _70$$30, *_71$$30, _72$$30, *_73$$30, _87$$30, _76$$33, _77$$33, _78$$33, _80$$33, _81$$34, _82$$34, _83$$34, _84$$34, _86$$34, _91$$37, _92$$37, _93$$37, _95$$37, _96$$38, _97$$38, _98$$38, _99$$38, _101$$38, _102$$39, _104$$41, _105$$42, _106$$40;
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_57);
	ZVAL_UNDEF(&_103);
	ZVAL_UNDEF(&_107);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_32$$16);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_36$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_46$$20);
	ZVAL_UNDEF(&_47$$20);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_50$$20);
	ZVAL_UNDEF(&_51$$21);
	ZVAL_UNDEF(&_52$$21);
	ZVAL_UNDEF(&_53$$21);
	ZVAL_UNDEF(&_54$$21);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_60$$22);
	ZVAL_UNDEF(&_61$$27);
	ZVAL_UNDEF(&_62$$27);
	ZVAL_UNDEF(&_63$$27);
	ZVAL_UNDEF(&_65$$28);
	ZVAL_UNDEF(&_66$$29);
	ZVAL_UNDEF(&_67$$29);
	ZVAL_UNDEF(&_68$$29);
	ZVAL_UNDEF(&_69$$30);
	ZVAL_UNDEF(&_70$$30);
	ZVAL_UNDEF(&_72$$30);
	ZVAL_UNDEF(&_87$$30);
	ZVAL_UNDEF(&_76$$33);
	ZVAL_UNDEF(&_77$$33);
	ZVAL_UNDEF(&_78$$33);
	ZVAL_UNDEF(&_80$$33);
	ZVAL_UNDEF(&_81$$34);
	ZVAL_UNDEF(&_82$$34);
	ZVAL_UNDEF(&_83$$34);
	ZVAL_UNDEF(&_84$$34);
	ZVAL_UNDEF(&_86$$34);
	ZVAL_UNDEF(&_91$$37);
	ZVAL_UNDEF(&_92$$37);
	ZVAL_UNDEF(&_93$$37);
	ZVAL_UNDEF(&_95$$37);
	ZVAL_UNDEF(&_96$$38);
	ZVAL_UNDEF(&_97$$38);
	ZVAL_UNDEF(&_98$$38);
	ZVAL_UNDEF(&_99$$38);
	ZVAL_UNDEF(&_101$$38);
	ZVAL_UNDEF(&_102$$39);
	ZVAL_UNDEF(&_104$$41);
	ZVAL_UNDEF(&_105$$42);
	ZVAL_UNDEF(&_106$$40);
	ZVAL_UNDEF(&_33$$16);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_79$$33);
	ZVAL_UNDEF(&_85$$34);
	ZVAL_UNDEF(&_94$$37);
	ZVAL_UNDEF(&_100$$38);
	ZEND_TLS zephir_method_cache _zephir_call_cache[46];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
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
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1088, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_fetch(&model, &_2, &modelName, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_3)) {
		zephir_read_property_cached(&_4$$4, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&model, &_4$$4, "load", &_zephir_call_cache[1], &modelName);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[2], &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&dialect, &connection, "getDialect", &_zephir_call_cache[3]);
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
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &fields);
		_5 = &_6;
	} else {
		_5 = &fields;
	}
	zephir_is_iterable(_5, 0, "phalcon/Mvc/Model/Query.zep", 1709);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_5), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&number, _9);
			} else {
				ZVAL_LONG(&number, _8);
			}
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _7);
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
			_10$$5 = zephir_array_isset_value_string(&field, SL("balias"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_10$$5) {
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
			ZEPHIR_OBS_NVAR(&_11$$5);
			zephir_array_fetch_string(&_11$$5, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1620);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&_11$$5, 260)) { goto zephir_switch_0_clause_0; }
			if (ZEPHIR_IS_LONG(&_11$$5, 258)) { goto zephir_switch_0_clause_1; }
			if (ZEPHIR_IS_LONG(&_11$$5, 259)) { goto zephir_switch_0_clause_2; }
			if (ZEPHIR_IS_LONG(&_11$$5, 322)) { goto zephir_switch_0_clause_3; }
			if (ZEPHIR_IS_LONG(&_11$$5, 273)) { goto zephir_switch_0_clause_4; }
			if (ZEPHIR_IS_LONG(&_11$$5, 274)) { goto zephir_switch_0_clause_5; }
			if (ZEPHIR_IS_LONG(&_11$$5, 277)) { goto zephir_switch_0_clause_6; }
			goto zephir_switch_0_clause_7;
			zephir_switch_0_clause_0: ;
			zephir_switch_0_clause_1: ;
			zephir_switch_0_clause_2: ;
				ZEPHIR_CALL_METHOD_CACHED(&updateValue, &dialect, "getSqlExpression", &_zephir_call_cache[4], &exprValue);
				zephir_check_call_status();
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&updateValue);
				ZVAL_NULL(&updateValue);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
			zephir_switch_0_clause_5: ;
			zephir_switch_0_clause_6: ;
				ZEPHIR_CALL_METHOD_CACHED(&_12$$10, &dialect, "getSqlExpression", &_zephir_call_cache[5], &exprValue);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_STRING(&_13$$10, ":");
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_STRING(&_14$$10, "");
				ZEPHIR_INIT_NVAR(&wildcard);
				zephir_fast_str_replace(&wildcard, &_13$$10, &_14$$10, &_12$$10);
				ZEPHIR_OBS_NVAR(&updateValue);
				_15$$10 = zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_15$$10))) {
					ZEPHIR_INIT_NVAR(&_16$$11);
					object_init_ex(&_16$$11, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_16$$11, "__construct", &_zephir_call_cache[6], &wildcard);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$11, "phalcon/Mvc/Model/Query.zep", 1641);
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
				ZEPHIR_CALL_METHOD_CACHED(&sqlExpr, &dialect, "getSqlExpression", &_zephir_call_cache[7], &exprValue);
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
					ZEPHIR_OBS_NVAR(&_20$$13);
					zephir_array_fetch_long(&_20$$13, &namedParams, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1667);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_21, 108, &_20$$13);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZEPHIR_INIT_NVAR(&_22$$13);
					zephir_create_closure_ex(&_22$$13, NULL, phalcon_92__closure_ce, SL("__invoke"));
					ZEPHIR_MAKE_REF(&paramKeys);
					ZEPHIR_CALL_FUNCTION(NULL, "usort", &_23, 230, &paramKeys, &_22$$13);
					ZEPHIR_UNREF(&paramKeys);
					zephir_check_call_status();
					if (Z_TYPE_P(&paramKeys) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_25$$13);
						zephir_string_to_char_array(&_25$$13, &paramKeys);
						_24$$13 = &_25$$13;
					} else {
						_24$$13 = &paramKeys;
					}
					zephir_is_iterable(_24$$13, 0, "phalcon/Mvc/Model/Query.zep", 1696);
					if (Z_TYPE_P(_24$$13) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_24$$13), _26$$13)
						{
							ZEPHIR_INIT_NVAR(&paramKey);
							ZVAL_COPY(&paramKey, _26$$13);
							ZEPHIR_OBS_NVAR(&paramValue);
							_27$$14 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_27$$14) {
								_28$$15 = Z_TYPE_P(&paramValue) == IS_LONG;
								if (!(_28$$15)) {
									_28$$15 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
								}
								if (_28$$15) {
									ZEPHIR_INIT_NVAR(&_29$$16);
									ZVAL_STRING(&_29$$16, "/");
									ZEPHIR_CALL_FUNCTION(&_30$$16, "preg_quote", &_31, 173, &paramKey, &_29$$16);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_32$$16);
									ZEPHIR_CONCAT_SVS(&_32$$16, "/:", &_30$$16, "\\b/");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_33$$16, &paramValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_FUNCTION(&_34$$16, "preg_replace", &_35, 2, &_32$$16, &_33$$16, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_34$$16);
								} else {
									ZEPHIR_INIT_NVAR(&_36$$17);
									ZVAL_STRING(&_36$$17, "/");
									ZEPHIR_CALL_FUNCTION(&_37$$17, "preg_quote", &_31, 173, &paramKey, &_36$$17);
									zephir_check_call_status();
									ZEPHIR_INIT_NVAR(&_38$$17);
									ZEPHIR_CONCAT_SVS(&_38$$17, "/:", &_37$$17, "\\b/");
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_cast_to_string(&_40$$17, &paramValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(&_39$$17, &connection, "escapeString", &_zephir_call_cache[8], &_40$$17);
									zephir_check_call_status();
									ZEPHIR_CALL_FUNCTION(&_41$$17, "preg_replace", &_35, 2, &_38$$17, &_39$$17, &sqlExpr);
									zephir_check_call_status();
									ZEPHIR_CPY_WRT(&sqlExpr, &_41$$17);
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
						ZEPHIR_CALL_METHOD_CACHED(NULL, _24$$13, "rewind", &_zephir_call_cache[9]);
						zephir_check_call_status();
						_43$$13 = 1;
						while (1) {
							if (_43$$13) {
								_43$$13 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _24$$13, "next", &_zephir_call_cache[10]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_42$$13, _24$$13, "valid", &_zephir_call_cache[11]);
							zephir_check_call_status();
							if (!zend_is_true(&_42$$13)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&paramKey, _24$$13, "current", &_zephir_call_cache[12]);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&paramValue);
								_44$$18 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_44$$18) {
									_45$$19 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_45$$19)) {
										_45$$19 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_45$$19) {
										ZEPHIR_INIT_NVAR(&_46$$20);
										ZVAL_STRING(&_46$$20, "/");
										ZEPHIR_CALL_FUNCTION(&_47$$20, "preg_quote", &_31, 173, &paramKey, &_46$$20);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_48$$20);
										ZEPHIR_CONCAT_SVS(&_48$$20, "/:", &_47$$20, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_49$$20, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_FUNCTION(&_50$$20, "preg_replace", &_35, 2, &_48$$20, &_49$$20, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_50$$20);
									} else {
										ZEPHIR_INIT_NVAR(&_51$$21);
										ZVAL_STRING(&_51$$21, "/");
										ZEPHIR_CALL_FUNCTION(&_52$$21, "preg_quote", &_31, 173, &paramKey, &_51$$21);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_53$$21);
										ZEPHIR_CONCAT_SVS(&_53$$21, "/:", &_52$$21, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_55$$21, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_54$$21, &connection, "escapeString", &_zephir_call_cache[13], &_55$$21);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_56$$21, "preg_replace", &_35, 2, &_53$$21, &_54$$21, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_56$$21);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, &updateValue, "__construct", &_zephir_call_cache[14], &sqlExpr);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[15]);
		zephir_check_call_status();
		_58 = 1;
		while (1) {
			if (_58) {
				_58 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[16]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_57, _5, "valid", &_zephir_call_cache[17]);
			zephir_check_call_status();
			if (!zend_is_true(&_57)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&number, _5, "key", &_zephir_call_cache[18]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&field, _5, "current", &_zephir_call_cache[19]);
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
				_59$$22 = zephir_array_isset_value_string(&field, SL("balias"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_59$$22) {
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
				ZEPHIR_OBS_NVAR(&_60$$22);
				zephir_array_fetch_string(&_60$$22, &value, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1620);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
					ZEPHIR_CALL_METHOD_CACHED(&updateValue, &dialect, "getSqlExpression", &_zephir_call_cache[20], &exprValue);
					zephir_check_call_status();
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&updateValue);
					ZVAL_NULL(&updateValue);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
				zephir_switch_1_clause_5: ;
				zephir_switch_1_clause_6: ;
					ZEPHIR_CALL_METHOD_CACHED(&_61$$27, &dialect, "getSqlExpression", &_zephir_call_cache[21], &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_62$$27);
					ZVAL_STRING(&_62$$27, ":");
					ZEPHIR_INIT_NVAR(&_63$$27);
					ZVAL_STRING(&_63$$27, "");
					ZEPHIR_INIT_NVAR(&wildcard);
					zephir_fast_str_replace(&wildcard, &_62$$27, &_63$$27, &_61$$27);
					ZEPHIR_OBS_NVAR(&updateValue);
					_64$$27 = zephir_array_isset_fetch(&updateValue, &bindParams, &wildcard, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_64$$27))) {
						ZEPHIR_INIT_NVAR(&_65$$28);
						object_init_ex(&_65$$28, phalcon_mvc_model_query_exceptions_bindparameternotinplaceholders_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_65$$28, "__construct", &_zephir_call_cache[22], &wildcard);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_65$$28, "phalcon/Mvc/Model/Query.zep", 1641);
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
					ZEPHIR_CALL_METHOD_CACHED(&sqlExpr, &dialect, "getSqlExpression", &_zephir_call_cache[23], &exprValue);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&namedParams);
					array_init(&namedParams);
					ZEPHIR_INIT_NVAR(&_66$$29);
					ZVAL_STRING(&_66$$29, "/:([a-zA-Z0-9_]+)/");
					ZEPHIR_INIT_NVAR(&_67$$29);
					ZEPHIR_INIT_NVAR(&_68$$29);
					ZVAL_STRING(&_68$$29, "/:([a-zA-Z0-9_]+)/");
					zephir_preg_match(&_67$$29, &_68$$29, &sqlExpr, &namedParams, 1, 0 , 0 );
					if (zephir_is_true(&_67$$29)) {
						ZEPHIR_OBS_NVAR(&_69$$30);
						zephir_array_fetch_long(&_69$$30, &namedParams, 1, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1667);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_FUNCTION(&paramKeys, "array_unique", &_21, 108, &_69$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_70$$30);
						ZEPHIR_INIT_NVAR(&_70$$30);
						zephir_create_closure_ex(&_70$$30, NULL, phalcon_93__closure_ce, SL("__invoke"));
						ZEPHIR_MAKE_REF(&paramKeys);
						ZEPHIR_CALL_FUNCTION(NULL, "usort", &_23, 230, &paramKeys, &_70$$30);
						ZEPHIR_UNREF(&paramKeys);
						zephir_check_call_status();
						if (Z_TYPE_P(&paramKeys) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_72$$30);
							zephir_string_to_char_array(&_72$$30, &paramKeys);
							_71$$30 = &_72$$30;
						} else {
							_71$$30 = &paramKeys;
						}
						zephir_is_iterable(_71$$30, 0, "phalcon/Mvc/Model/Query.zep", 1696);
						if (Z_TYPE_P(_71$$30) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$30), _73$$30)
							{
								ZEPHIR_INIT_NVAR(&paramKey);
								ZVAL_COPY(&paramKey, _73$$30);
								ZEPHIR_OBS_NVAR(&paramValue);
								_74$$31 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_74$$31) {
									_75$$32 = Z_TYPE_P(&paramValue) == IS_LONG;
									if (!(_75$$32)) {
										_75$$32 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
									}
									if (_75$$32) {
										ZEPHIR_INIT_NVAR(&_76$$33);
										ZVAL_STRING(&_76$$33, "/");
										ZEPHIR_CALL_FUNCTION(&_77$$33, "preg_quote", &_31, 173, &paramKey, &_76$$33);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_78$$33);
										ZEPHIR_CONCAT_SVS(&_78$$33, "/:", &_77$$33, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_79$$33, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_FUNCTION(&_80$$33, "preg_replace", &_35, 2, &_78$$33, &_79$$33, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_80$$33);
									} else {
										ZEPHIR_INIT_NVAR(&_81$$34);
										ZVAL_STRING(&_81$$34, "/");
										ZEPHIR_CALL_FUNCTION(&_82$$34, "preg_quote", &_31, 173, &paramKey, &_81$$34);
										zephir_check_call_status();
										ZEPHIR_INIT_NVAR(&_83$$34);
										ZEPHIR_CONCAT_SVS(&_83$$34, "/:", &_82$$34, "\\b/");
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_cast_to_string(&_85$$34, &paramValue);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(&_84$$34, &connection, "escapeString", &_zephir_call_cache[24], &_85$$34);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_86$$34, "preg_replace", &_35, 2, &_83$$34, &_84$$34, &sqlExpr);
										zephir_check_call_status();
										ZEPHIR_CPY_WRT(&sqlExpr, &_86$$34);
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
							ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$30, "rewind", &_zephir_call_cache[25]);
							zephir_check_call_status();
							_88$$30 = 1;
							while (1) {
								if (_88$$30) {
									_88$$30 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$30, "next", &_zephir_call_cache[26]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_87$$30, _71$$30, "valid", &_zephir_call_cache[27]);
								zephir_check_call_status();
								if (!zend_is_true(&_87$$30)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&paramKey, _71$$30, "current", &_zephir_call_cache[28]);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&paramValue);
									_89$$35 = zephir_array_isset_fetch(&paramValue, &bindParams, &paramKey, 0);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (_89$$35) {
										_90$$36 = Z_TYPE_P(&paramValue) == IS_LONG;
										if (!(_90$$36)) {
											_90$$36 = Z_TYPE_P(&paramValue) == IS_DOUBLE;
										}
										if (_90$$36) {
											ZEPHIR_INIT_NVAR(&_91$$37);
											ZVAL_STRING(&_91$$37, "/");
											ZEPHIR_CALL_FUNCTION(&_92$$37, "preg_quote", &_31, 173, &paramKey, &_91$$37);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_93$$37);
											ZEPHIR_CONCAT_SVS(&_93$$37, "/:", &_92$$37, "\\b/");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_94$$37, &paramValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CALL_FUNCTION(&_95$$37, "preg_replace", &_35, 2, &_93$$37, &_94$$37, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_95$$37);
										} else {
											ZEPHIR_INIT_NVAR(&_96$$38);
											ZVAL_STRING(&_96$$38, "/");
											ZEPHIR_CALL_FUNCTION(&_97$$38, "preg_quote", &_31, 173, &paramKey, &_96$$38);
											zephir_check_call_status();
											ZEPHIR_INIT_NVAR(&_98$$38);
											ZEPHIR_CONCAT_SVS(&_98$$38, "/:", &_97$$38, "\\b/");
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											zephir_cast_to_string(&_100$$38, &paramValue);
											if (UNEXPECTED(EG(exception))) {
												ZEPHIR_MM_RESTORE();
												return;
											}
											ZEPHIR_CALL_METHOD_CACHED(&_99$$38, &connection, "escapeString", &_zephir_call_cache[29], &_100$$38);
											zephir_check_call_status();
											ZEPHIR_CALL_FUNCTION(&_101$$38, "preg_replace", &_35, 2, &_98$$38, &_99$$38, &sqlExpr);
											zephir_check_call_status();
											ZEPHIR_CPY_WRT(&sqlExpr, &_101$$38);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, &updateValue, "__construct", &_zephir_call_cache[30], &sqlExpr);
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
	ZEPHIR_CALL_METHOD_CACHED(&records, this_ptr, "getRelatedRecords", &_zephir_call_cache[31], &model, &intermediate, &selectBindParams, &selectBindTypes);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(&records))) {
		object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
		ZVAL_BOOL(&_102$$39, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[32], &_102$$39);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&connection, this_ptr, "getWriteConnection", &_zephir_call_cache[33], &model, &intermediate, &bindParams, &bindTypes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "begin", &_zephir_call_cache[34]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &records, "rewind", &_zephir_call_cache[35]);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD_CACHED(&_103, &records, "valid", &_zephir_call_cache[36]);
		zephir_check_call_status();
		if (!(zephir_is_true(&_103))) {
			break;
		}

		/* try_start_1: */

			ZEPHIR_CALL_METHOD_CACHED(&record, &records, "current", &_zephir_call_cache[37]);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &record, "assign", &_zephir_call_cache[38], &updateValues);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD_CACHED(&_104$$41, &record, "update", &_zephir_call_cache[39]);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_104$$41))) {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "rollback", &_zephir_call_cache[40]);
				zephir_check_call_status_or_jump(try_end_1);
				object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
				ZVAL_BOOL(&_105$$42, 0);
				ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[41], &_105$$42, &record);
				zephir_check_call_status_or_jump(try_end_1);
				RETURN_MM();
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &records, "next", &_zephir_call_cache[42]);
			zephir_check_call_status_or_jump(try_end_1);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_106$$40);
			ZVAL_OBJ(&_106$$40, EG(exception));
			Z_ADDREF_P(&_106$$40);
			if (zephir_is_instance_of(&_106$$40, SL("PDOException"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_106$$40);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "rollback", &_zephir_call_cache[43]);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &connection, "commit", &_zephir_call_cache[44]);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_mvc_model_query_status_ce);
	ZVAL_BOOL(&_107, 1);
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[45], &_107);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getExpression", &_zephir_call_cache[0], &argument);
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
	zend_bool _13, _4$$3, _14$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *expr_param = NULL, whenClauses, whenExpr, _0, *_1, _2, *_3, _12, _22, _23, _6$$4, _7$$4, _8$$4, _10$$5, _11$$5, _16$$7, _17$$7, _18$$7, _20$$8, _21$$8;
	zval expr, _5$$4, _9$$5, _15$$7, _19$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&expr);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&whenClauses);
	ZVAL_UNDEF(&whenExpr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
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
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "getExpression", &_zephir_call_cache[0], &_7$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_5$$4, SL("expr"), &_6$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_8$$4);
				zephir_array_fetch_string(&_8$$4, &whenExpr, SL("right"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1805);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "getExpression", &_zephir_call_cache[1], &_8$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_5$$4, SL("then"), &_6$$4, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_5$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1806);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_9$$5);
				zephir_create_array(&_9$$5, 2, 0);
				add_assoc_stringl_ex(&_9$$5, SL("type"), SL("else"));
				ZEPHIR_OBS_NVAR(&_11$$5);
				zephir_array_fetch_string(&_11$$5, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1810);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$5, this_ptr, "getExpression", &_zephir_call_cache[2], &_11$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_9$$5, SL("expr"), &_10$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&whenClauses, &_9$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1811);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12, _1, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&whenExpr, _1, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				_14$$6 = zephir_array_isset_value_string(&whenExpr, SL("right"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_14$$6) {
					ZEPHIR_INIT_NVAR(&_15$$7);
					zephir_create_array(&_15$$7, 3, 0);
					add_assoc_stringl_ex(&_15$$7, SL("type"), SL("when"));
					ZEPHIR_OBS_NVAR(&_17$$7);
					zephir_array_fetch_string(&_17$$7, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1804);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_16$$7, this_ptr, "getExpression", &_zephir_call_cache[7], &_17$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$7, SL("expr"), &_16$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_OBS_NVAR(&_18$$7);
					zephir_array_fetch_string(&_18$$7, &whenExpr, SL("right"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1805);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_16$$7, this_ptr, "getExpression", &_zephir_call_cache[8], &_18$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_15$$7, SL("then"), &_16$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_15$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1806);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_19$$8);
					zephir_create_array(&_19$$8, 2, 0);
					add_assoc_stringl_ex(&_19$$8, SL("type"), SL("else"));
					ZEPHIR_OBS_NVAR(&_21$$8);
					zephir_array_fetch_string(&_21$$8, &whenExpr, SL("left"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 1810);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_20$$8, this_ptr, "getExpression", &_zephir_call_cache[9], &_21$$8);
					zephir_check_call_status();
					zephir_array_update_string(&_19$$8, SL("expr"), &_20$$8, PH_COPY | PH_SEPARATE);
					zephir_array_append(&whenClauses, &_19$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 1811);
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
	zephir_array_fetch_string(&_23, &expr, SL("left"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 1817);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_22, this_ptr, "getExpression", &_zephir_call_cache[10], &_23);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("expr"), &_22, PH_COPY | PH_SEPARATE);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool quoting, tempNotQuoting = 0, _0, _104, _105, _1$$4, _3$$4, _55$$41, _109$$80;
	zval *expr_param = NULL, *quoting_param = NULL, __$true, bind, bindType, exprType, exprLeft, exprListItem, exprRight, listItems, name, value, valueParts, exprReturn, left, right, _111, _2$$5, _4$$6, _5$$7, _6$$8, _7$$9, _8$$10, _9$$11, _10$$12, _11$$13, _12$$14, _13$$16, _14$$17, _15$$18, _16$$19, _17$$20, _18$$21, _19$$22, _20$$23, _21$$24, _22$$25, _23$$25, _24$$26, _25$$27, _26$$29, _27$$30, _28$$31, _29$$31, _30$$31, _31$$31, _32$$31, _33$$32, _34$$32, _35$$32, _36$$35, _37$$35, _38$$35, _39$$36, _40$$36, _41$$36, _42$$37, _43$$37, _44$$37, _45$$38, _46$$38, _47$$38, _48$$39, _49$$39, _50$$39, _51$$40, _52$$40, _53$$40, _54$$41, _59$$41, _60$$41, _56$$42, _57$$43, _58$$44, _61$$45, _62$$46, _63$$46, _64$$47, _65$$48, _66$$49, _67$$50, _68$$51, _69$$52, _70$$53, _71$$54, _72$$55, _73$$56, _74$$57, _75$$58, _76$$59, _77$$60, _78$$61, _79$$62, _80$$63, _81$$64, _82$$64, _83$$64, _84$$64, _85$$64, _89$$64, _90$$64, _86$$65, _87$$65, _88$$65, _91$$68, _92$$68, _93$$68, _94$$69, _95$$70, _96$$71, _97$$72, _98$$73, _99$$74, _100$$75, _101$$76, _102$$77, _103$$78, *_106$$80, _108$$80, _107$$81, _110$$82;
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
	ZVAL_UNDEF(&_111);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$17);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_18$$21);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_21$$24);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_23$$25);
	ZVAL_UNDEF(&_24$$26);
	ZVAL_UNDEF(&_25$$27);
	ZVAL_UNDEF(&_26$$29);
	ZVAL_UNDEF(&_27$$30);
	ZVAL_UNDEF(&_28$$31);
	ZVAL_UNDEF(&_29$$31);
	ZVAL_UNDEF(&_30$$31);
	ZVAL_UNDEF(&_31$$31);
	ZVAL_UNDEF(&_32$$31);
	ZVAL_UNDEF(&_33$$32);
	ZVAL_UNDEF(&_34$$32);
	ZVAL_UNDEF(&_35$$32);
	ZVAL_UNDEF(&_36$$35);
	ZVAL_UNDEF(&_37$$35);
	ZVAL_UNDEF(&_38$$35);
	ZVAL_UNDEF(&_39$$36);
	ZVAL_UNDEF(&_40$$36);
	ZVAL_UNDEF(&_41$$36);
	ZVAL_UNDEF(&_42$$37);
	ZVAL_UNDEF(&_43$$37);
	ZVAL_UNDEF(&_44$$37);
	ZVAL_UNDEF(&_45$$38);
	ZVAL_UNDEF(&_46$$38);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_49$$39);
	ZVAL_UNDEF(&_50$$39);
	ZVAL_UNDEF(&_51$$40);
	ZVAL_UNDEF(&_52$$40);
	ZVAL_UNDEF(&_53$$40);
	ZVAL_UNDEF(&_54$$41);
	ZVAL_UNDEF(&_59$$41);
	ZVAL_UNDEF(&_60$$41);
	ZVAL_UNDEF(&_56$$42);
	ZVAL_UNDEF(&_57$$43);
	ZVAL_UNDEF(&_58$$44);
	ZVAL_UNDEF(&_61$$45);
	ZVAL_UNDEF(&_62$$46);
	ZVAL_UNDEF(&_63$$46);
	ZVAL_UNDEF(&_64$$47);
	ZVAL_UNDEF(&_65$$48);
	ZVAL_UNDEF(&_66$$49);
	ZVAL_UNDEF(&_67$$50);
	ZVAL_UNDEF(&_68$$51);
	ZVAL_UNDEF(&_69$$52);
	ZVAL_UNDEF(&_70$$53);
	ZVAL_UNDEF(&_71$$54);
	ZVAL_UNDEF(&_72$$55);
	ZVAL_UNDEF(&_73$$56);
	ZVAL_UNDEF(&_74$$57);
	ZVAL_UNDEF(&_75$$58);
	ZVAL_UNDEF(&_76$$59);
	ZVAL_UNDEF(&_77$$60);
	ZVAL_UNDEF(&_78$$61);
	ZVAL_UNDEF(&_79$$62);
	ZVAL_UNDEF(&_80$$63);
	ZVAL_UNDEF(&_81$$64);
	ZVAL_UNDEF(&_82$$64);
	ZVAL_UNDEF(&_83$$64);
	ZVAL_UNDEF(&_84$$64);
	ZVAL_UNDEF(&_85$$64);
	ZVAL_UNDEF(&_89$$64);
	ZVAL_UNDEF(&_90$$64);
	ZVAL_UNDEF(&_86$$65);
	ZVAL_UNDEF(&_87$$65);
	ZVAL_UNDEF(&_88$$65);
	ZVAL_UNDEF(&_91$$68);
	ZVAL_UNDEF(&_92$$68);
	ZVAL_UNDEF(&_93$$68);
	ZVAL_UNDEF(&_94$$69);
	ZVAL_UNDEF(&_95$$70);
	ZVAL_UNDEF(&_96$$71);
	ZVAL_UNDEF(&_97$$72);
	ZVAL_UNDEF(&_98$$73);
	ZVAL_UNDEF(&_99$$74);
	ZVAL_UNDEF(&_100$$75);
	ZVAL_UNDEF(&_101$$76);
	ZVAL_UNDEF(&_102$$77);
	ZVAL_UNDEF(&_103$$78);
	ZVAL_UNDEF(&_108$$80);
	ZVAL_UNDEF(&_107$$81);
	ZVAL_UNDEF(&_110$$82);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
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
				ZEPHIR_CALL_METHOD_CACHED(&left, this_ptr, "getExpression", &_zephir_call_cache[0], &exprLeft, &_2$$5);
				zephir_check_call_status();
			}
			zephir_memory_observe(&exprRight);
			_3$$4 = zephir_array_isset_string_fetch(&exprRight, &expr, SL("right"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_3$$4) {
				if (tempNotQuoting) {
					ZVAL_BOOL(&_4$$6, 1);
				} else {
					ZVAL_BOOL(&_4$$6, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&right, this_ptr, "getExpression", &_zephir_call_cache[1], &exprRight, &_4$$6);
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
			ZEPHIR_INIT_VAR(&_5$$7);
			zephir_create_array(&_5$$7, 4, 0);
			add_assoc_stringl_ex(&_5$$7, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_5$$7, SL("op"), SL("<"));
			zephir_array_update_string(&_5$$7, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_5$$7, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_5$$7);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_1: ;
			ZEPHIR_INIT_VAR(&_6$$8);
			zephir_create_array(&_6$$8, 4, 0);
			add_assoc_stringl_ex(&_6$$8, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_6$$8, SL("op"), SL("="));
			zephir_array_update_string(&_6$$8, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_6$$8, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_6$$8);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_2: ;
			ZEPHIR_INIT_VAR(&_7$$9);
			zephir_create_array(&_7$$9, 4, 0);
			add_assoc_stringl_ex(&_7$$9, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_7$$9, SL("op"), SL(">"));
			zephir_array_update_string(&_7$$9, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_7$$9, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_7$$9);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_3: ;
			ZEPHIR_INIT_VAR(&_8$$10);
			zephir_create_array(&_8$$10, 4, 0);
			add_assoc_stringl_ex(&_8$$10, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_8$$10, SL("op"), SL("<>"));
			zephir_array_update_string(&_8$$10, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_8$$10, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_8$$10);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_4: ;
			ZEPHIR_INIT_VAR(&_9$$11);
			zephir_create_array(&_9$$11, 4, 0);
			add_assoc_stringl_ex(&_9$$11, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_9$$11, SL("op"), SL("<="));
			zephir_array_update_string(&_9$$11, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_9$$11, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_9$$11);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_5: ;
			ZEPHIR_INIT_VAR(&_10$$12);
			zephir_create_array(&_10$$12, 4, 0);
			add_assoc_stringl_ex(&_10$$12, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_10$$12, SL("op"), SL(">="));
			zephir_array_update_string(&_10$$12, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_10$$12, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_10$$12);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_6: ;
			ZEPHIR_INIT_VAR(&_11$$13);
			zephir_create_array(&_11$$13, 4, 0);
			add_assoc_stringl_ex(&_11$$13, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_11$$13, SL("op"), SL("AND"));
			zephir_array_update_string(&_11$$13, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_11$$13, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_11$$13);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_7: ;
			ZEPHIR_INIT_VAR(&_12$$14);
			zephir_create_array(&_12$$14, 4, 0);
			add_assoc_stringl_ex(&_12$$14, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_12$$14, SL("op"), SL("OR"));
			zephir_array_update_string(&_12$$14, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_12$$14, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_12$$14);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_8: ;
			ZEPHIR_CALL_METHOD_CACHED(&exprReturn, this_ptr, "getQualified", &_zephir_call_cache[2], &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_9: ;
			ZEPHIR_INIT_VAR(&_13$$16);
			zephir_create_array(&_13$$16, 4, 0);
			add_assoc_stringl_ex(&_13$$16, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_13$$16, SL("op"), SL("+"));
			zephir_array_update_string(&_13$$16, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$16, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_13$$16);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_10: ;
			ZEPHIR_INIT_VAR(&_14$$17);
			zephir_create_array(&_14$$17, 4, 0);
			add_assoc_stringl_ex(&_14$$17, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_14$$17, SL("op"), SL("-"));
			zephir_array_update_string(&_14$$17, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$17, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_14$$17);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_11: ;
			ZEPHIR_INIT_VAR(&_15$$18);
			zephir_create_array(&_15$$18, 4, 0);
			add_assoc_stringl_ex(&_15$$18, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_15$$18, SL("op"), SL("*"));
			zephir_array_update_string(&_15$$18, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$18, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_15$$18);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_12: ;
			ZEPHIR_INIT_VAR(&_16$$19);
			zephir_create_array(&_16$$19, 4, 0);
			add_assoc_stringl_ex(&_16$$19, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_16$$19, SL("op"), SL("/"));
			zephir_array_update_string(&_16$$19, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$19, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_16$$19);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_13: ;
			ZEPHIR_INIT_VAR(&_17$$20);
			zephir_create_array(&_17$$20, 4, 0);
			add_assoc_stringl_ex(&_17$$20, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_17$$20, SL("op"), SL("%"));
			zephir_array_update_string(&_17$$20, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_17$$20, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_17$$20);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_14: ;
			ZEPHIR_INIT_VAR(&_18$$21);
			zephir_create_array(&_18$$21, 4, 0);
			add_assoc_stringl_ex(&_18$$21, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_18$$21, SL("op"), SL("&"));
			zephir_array_update_string(&_18$$21, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_18$$21, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_18$$21);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_15: ;
			ZEPHIR_INIT_VAR(&_19$$22);
			zephir_create_array(&_19$$22, 4, 0);
			add_assoc_stringl_ex(&_19$$22, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_19$$22, SL("op"), SL("|"));
			zephir_array_update_string(&_19$$22, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_19$$22, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_19$$22);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_16: ;
		zephir_switch_0_clause_17: ;
			ZEPHIR_INIT_VAR(&_20$$23);
			zephir_create_array(&_20$$23, 2, 0);
			add_assoc_stringl_ex(&_20$$23, SL("type"), SL("parentheses"));
			zephir_array_update_string(&_20$$23, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_20$$23);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_18: ;
			ZEPHIR_INIT_VAR(&_21$$24);
			zephir_create_array(&_21$$24, 3, 0);
			add_assoc_stringl_ex(&_21$$24, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_21$$24, SL("op"), SL("-"));
			zephir_array_update_string(&_21$$24, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_21$$24);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_19: ;
		zephir_switch_0_clause_20: ;
		zephir_switch_0_clause_21: ;
			ZEPHIR_INIT_VAR(&_22$$25);
			zephir_create_array(&_22$$25, 2, 0);
			add_assoc_stringl_ex(&_22$$25, SL("type"), SL("literal"));
			zephir_memory_observe(&_23$$25);
			zephir_array_fetch_string(&_23$$25, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2038);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_22$$25, SL("value"), &_23$$25, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_22$$25);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_22: ;
			ZEPHIR_INIT_VAR(&_24$$26);
			zephir_create_array(&_24$$26, 2, 0);
			add_assoc_stringl_ex(&_24$$26, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_24$$26, SL("value"), SL("TRUE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_24$$26);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_23: ;
			ZEPHIR_INIT_VAR(&_25$$27);
			zephir_create_array(&_25$$27, 2, 0);
			add_assoc_stringl_ex(&_25$$27, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_25$$27, SL("value"), SL("FALSE"));
			ZEPHIR_CPY_WRT(&exprReturn, &_25$$27);
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
				ZEPHIR_INIT_VAR(&_26$$29);
				zephir_create_array(&_26$$29, 3, 0);
				add_assoc_stringl_ex(&_26$$29, SL("type"), SL("literal"));
				zephir_array_update_string(&_26$$29, SL("value"), &value, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$29, SL("escape"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_26$$29);
			} else {
				ZEPHIR_INIT_VAR(&_27$$30);
				zephir_create_array(&_27$$30, 2, 0);
				add_assoc_stringl_ex(&_27$$30, SL("type"), SL("literal"));
				zephir_array_update_string(&_27$$30, SL("value"), &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_27$$30);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_25: ;
			ZEPHIR_INIT_VAR(&_28$$31);
			zephir_create_array(&_28$$31, 2, 0);
			add_assoc_stringl_ex(&_28$$31, SL("type"), SL("placeholder"));
			ZEPHIR_INIT_VAR(&_29$$31);
			zephir_memory_observe(&_30$$31);
			zephir_array_fetch_string(&_30$$31, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2085);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_31$$31);
			ZVAL_STRING(&_31$$31, "?");
			ZEPHIR_INIT_VAR(&_32$$31);
			ZVAL_STRING(&_32$$31, ":");
			zephir_fast_str_replace(&_29$$31, &_31$$31, &_32$$31, &_30$$31);
			zephir_array_update_string(&_28$$31, SL("value"), &_29$$31, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_28$$31);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_26: ;
			ZEPHIR_INIT_VAR(&_33$$32);
			zephir_create_array(&_33$$32, 2, 0);
			add_assoc_stringl_ex(&_33$$32, SL("type"), SL("placeholder"));
			zephir_memory_observe(&_34$$32);
			zephir_array_fetch_string(&_34$$32, &expr, SL("value"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2094);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_35$$32);
			ZEPHIR_CONCAT_SV(&_35$$32, ":", &_34$$32);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_33$$32, SL("value"), &_35$$32, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_33$$32);
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
					ZEPHIR_INIT_VAR(&_36$$35);
					ZVAL_LONG(&_36$$35, 2);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_36$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_37$$35);
					zephir_create_array(&_37$$35, 2, 0);
					add_assoc_stringl_ex(&_37$$35, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_38$$35);
					ZEPHIR_CONCAT_SV(&_38$$35, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_37$$35, SL("value"), &_38$$35, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_37$$35);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_VAR(&_39$$36);
					ZVAL_LONG(&_39$$36, 1);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_39$$36);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_40$$36);
					zephir_create_array(&_40$$36, 2, 0);
					add_assoc_stringl_ex(&_40$$36, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_41$$36);
					ZEPHIR_CONCAT_SV(&_41$$36, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_40$$36, SL("value"), &_41$$36, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_40$$36);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_VAR(&_42$$37);
					ZVAL_LONG(&_42$$37, 32);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_42$$37);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_43$$37);
					zephir_create_array(&_43$$37, 2, 0);
					add_assoc_stringl_ex(&_43$$37, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_44$$37);
					ZEPHIR_CONCAT_SV(&_44$$37, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_43$$37, SL("value"), &_44$$37, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_43$$37);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_VAR(&_45$$38);
					ZVAL_LONG(&_45$$38, 5);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_45$$38);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_46$$38);
					zephir_create_array(&_46$$38, 2, 0);
					add_assoc_stringl_ex(&_46$$38, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_47$$38);
					ZEPHIR_CONCAT_SV(&_47$$38, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_46$$38, SL("value"), &_47$$38, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_46$$38);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_VAR(&_48$$39);
					ZVAL_LONG(&_48$$39, 3);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_48$$39);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_49$$39);
					zephir_create_array(&_49$$39, 2, 0);
					add_assoc_stringl_ex(&_49$$39, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_50$$39);
					ZEPHIR_CONCAT_SV(&_50$$39, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_49$$39, SL("value"), &_50$$39, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_49$$39);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_VAR(&_51$$40);
					ZVAL_LONG(&_51$$40, 0);
					zephir_update_property_array(this_ptr, SL("bindTypes"), &name, &_51$$40);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_52$$40);
					zephir_create_array(&_52$$40, 2, 0);
					add_assoc_stringl_ex(&_52$$40, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_53$$40);
					ZEPHIR_CONCAT_SV(&_53$$40, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_52$$40, SL("value"), &_53$$40, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&exprReturn, &_52$$40);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
				zephir_switch_1_clause_7: ;
				zephir_switch_1_clause_8: ;
					zephir_memory_observe(&bind);
					zephir_read_property_cached(&_54$$41, this_ptr, _zephir_prop_0, 1074, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_55$$41 = zephir_array_isset_fetch(&bind, &_54$$41, &name, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_55$$41))) {
						ZEPHIR_INIT_VAR(&_56$$42);
						object_init_ex(&_56$$42, phalcon_mvc_model_query_exceptions_bindvaluerequired_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_56$$42, "__construct", &_zephir_call_cache[3], &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_56$$42, "phalcon/Mvc/Model/Query.zep", 2172);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(Z_TYPE_P(&bind) != IS_ARRAY)) {
						ZEPHIR_INIT_VAR(&_57$$43);
						object_init_ex(&_57$$43, phalcon_mvc_model_query_exceptions_bindtyperequiresarray_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_57$$43, "__construct", &_zephir_call_cache[4], &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_57$$43, "phalcon/Mvc/Model/Query.zep", 2176);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(ZEPHIR_IS_EMPTY(&bind))) {
						ZEPHIR_INIT_VAR(&_58$$44);
						object_init_ex(&_58$$44, phalcon_mvc_model_query_exceptions_emptyarrayplaceholdervalue_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_58$$44, "__construct", &_zephir_call_cache[5], &name);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_58$$44, "phalcon/Mvc/Model/Query.zep", 2180);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_VAR(&_59$$41);
					zephir_create_array(&_59$$41, 4, 0);
					add_assoc_stringl_ex(&_59$$41, SL("type"), SL("placeholder"));
					ZEPHIR_INIT_VAR(&_60$$41);
					ZEPHIR_CONCAT_SV(&_60$$41, ":", &name);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&_59$$41, SL("value"), &_60$$41, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_59$$41, SL("rawValue"), &name, PH_COPY | PH_SEPARATE);
					add_assoc_long_ex(&_59$$41, SL("times"), zephir_fast_count_int(&bind));
					ZEPHIR_CPY_WRT(&exprReturn, &_59$$41);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_VAR(&_61$$45);
					object_init_ex(&_61$$45, phalcon_mvc_model_query_exceptions_unknownbindtype_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_61$$45, "__construct", &_zephir_call_cache[6], &bindType);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_61$$45, "phalcon/Mvc/Model/Query.zep", 2193);
					ZEPHIR_MM_RESTORE();
					return;
				zephir_switch_1_end: ;

			} else {
				ZEPHIR_INIT_VAR(&_62$$46);
				zephir_create_array(&_62$$46, 2, 0);
				add_assoc_stringl_ex(&_62$$46, SL("type"), SL("placeholder"));
				ZEPHIR_INIT_VAR(&_63$$46);
				ZEPHIR_CONCAT_SV(&_63$$46, ":", &value);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_62$$46, SL("value"), &_63$$46, PH_COPY | PH_SEPARATE);
				ZEPHIR_CPY_WRT(&exprReturn, &_62$$46);
			}
			goto zephir_switch_0_end;
		zephir_switch_0_clause_28: ;
			ZEPHIR_INIT_VAR(&_64$$47);
			zephir_create_array(&_64$$47, 2, 0);
			add_assoc_stringl_ex(&_64$$47, SL("type"), SL("literal"));
			add_assoc_stringl_ex(&_64$$47, SL("value"), SL("NULL"));
			ZEPHIR_CPY_WRT(&exprReturn, &_64$$47);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_29: ;
			ZEPHIR_INIT_VAR(&_65$$48);
			zephir_create_array(&_65$$48, 4, 0);
			add_assoc_stringl_ex(&_65$$48, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_65$$48, SL("op"), SL("LIKE"));
			zephir_array_update_string(&_65$$48, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_65$$48, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_65$$48);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_30: ;
			ZEPHIR_INIT_VAR(&_66$$49);
			zephir_create_array(&_66$$49, 4, 0);
			add_assoc_stringl_ex(&_66$$49, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_66$$49, SL("op"), SL("NOT LIKE"));
			zephir_array_update_string(&_66$$49, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_66$$49, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_66$$49);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_31: ;
			ZEPHIR_INIT_VAR(&_67$$50);
			zephir_create_array(&_67$$50, 4, 0);
			add_assoc_stringl_ex(&_67$$50, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_67$$50, SL("op"), SL("ILIKE"));
			zephir_array_update_string(&_67$$50, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_67$$50, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_67$$50);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_32: ;
			ZEPHIR_INIT_VAR(&_68$$51);
			zephir_create_array(&_68$$51, 4, 0);
			add_assoc_stringl_ex(&_68$$51, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_68$$51, SL("op"), SL("NOT ILIKE"));
			zephir_array_update_string(&_68$$51, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_68$$51, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_68$$51);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_33: ;
			ZEPHIR_INIT_VAR(&_69$$52);
			zephir_create_array(&_69$$52, 3, 0);
			add_assoc_stringl_ex(&_69$$52, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_69$$52, SL("op"), SL("NOT "));
			zephir_array_update_string(&_69$$52, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_69$$52);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_34: ;
			ZEPHIR_INIT_VAR(&_70$$53);
			zephir_create_array(&_70$$53, 3, 0);
			add_assoc_stringl_ex(&_70$$53, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_70$$53, SL("op"), SL(" IS NULL"));
			zephir_array_update_string(&_70$$53, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_70$$53);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_35: ;
			ZEPHIR_INIT_VAR(&_71$$54);
			zephir_create_array(&_71$$54, 3, 0);
			add_assoc_stringl_ex(&_71$$54, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_71$$54, SL("op"), SL(" IS NOT NULL"));
			zephir_array_update_string(&_71$$54, SL("left"), &left, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_71$$54);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_36: ;
			ZEPHIR_INIT_VAR(&_72$$55);
			zephir_create_array(&_72$$55, 4, 0);
			add_assoc_stringl_ex(&_72$$55, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_72$$55, SL("op"), SL("IN"));
			zephir_array_update_string(&_72$$55, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_72$$55, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_72$$55);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_37: ;
			ZEPHIR_INIT_VAR(&_73$$56);
			zephir_create_array(&_73$$56, 4, 0);
			add_assoc_stringl_ex(&_73$$56, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_73$$56, SL("op"), SL("NOT IN"));
			zephir_array_update_string(&_73$$56, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_73$$56, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_73$$56);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_38: ;
			ZEPHIR_INIT_VAR(&_74$$57);
			zephir_create_array(&_74$$57, 3, 0);
			add_assoc_stringl_ex(&_74$$57, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_74$$57, SL("op"), SL("EXISTS"));
			zephir_array_update_string(&_74$$57, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_74$$57);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_39: ;
			ZEPHIR_INIT_VAR(&_75$$58);
			zephir_create_array(&_75$$58, 3, 0);
			add_assoc_stringl_ex(&_75$$58, SL("type"), SL("unary-op"));
			add_assoc_stringl_ex(&_75$$58, SL("op"), SL("DISTINCT "));
			zephir_array_update_string(&_75$$58, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_75$$58);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_40: ;
			ZEPHIR_INIT_VAR(&_76$$59);
			zephir_create_array(&_76$$59, 4, 0);
			add_assoc_stringl_ex(&_76$$59, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_76$$59, SL("op"), SL("NOT BETWEEN"));
			zephir_array_update_string(&_76$$59, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_76$$59, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_76$$59);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_41: ;
			ZEPHIR_INIT_VAR(&_77$$60);
			zephir_create_array(&_77$$60, 4, 0);
			add_assoc_stringl_ex(&_77$$60, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_77$$60, SL("op"), SL("BETWEEN"));
			zephir_array_update_string(&_77$$60, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_77$$60, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_77$$60);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_42: ;
			ZEPHIR_INIT_VAR(&_78$$61);
			zephir_create_array(&_78$$61, 4, 0);
			add_assoc_stringl_ex(&_78$$61, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_78$$61, SL("op"), SL("AGAINST"));
			zephir_array_update_string(&_78$$61, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_78$$61, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_78$$61);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_43: ;
			ZEPHIR_INIT_VAR(&_79$$62);
			zephir_create_array(&_79$$62, 3, 0);
			add_assoc_stringl_ex(&_79$$62, SL("type"), SL("cast"));
			zephir_array_update_string(&_79$$62, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_79$$62, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_79$$62);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_44: ;
			ZEPHIR_INIT_VAR(&_80$$63);
			zephir_create_array(&_80$$63, 3, 0);
			add_assoc_stringl_ex(&_80$$63, SL("type"), SL("convert"));
			zephir_array_update_string(&_80$$63, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_80$$63, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_80$$63);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_45: ;
			ZEPHIR_INIT_VAR(&_81$$64);
			zephir_memory_observe(&_82$$64);
			zephir_array_fetch_string(&_82$$64, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2371);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_83$$64);
			ZVAL_STRING(&_83$$64, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			ZEPHIR_INIT_VAR(&_84$$64);
			ZEPHIR_INIT_VAR(&_85$$64);
			ZVAL_STRING(&_85$$64, "/^\\\\?[a-zA-Z_][a-zA-Z0-9_\\\\:]*$/");
			zephir_preg_match(&_84$$64, &_85$$64, &_82$$64, &_81$$64, 0, 0 , 0 );
			if (UNEXPECTED(!zephir_is_true(&_84$$64))) {
				ZEPHIR_INIT_VAR(&_86$$65);
				object_init_ex(&_86$$65, phalcon_mvc_model_query_exceptions_unsafeidentifier_ce);
				zephir_memory_observe(&_87$$65);
				zephir_array_fetch_string(&_87$$65, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2372);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_88$$65, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_86$$65, "__construct", &_zephir_call_cache[7], &_87$$65, &_88$$65);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_86$$65, "phalcon/Mvc/Model/Query.zep", 2372);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_89$$64);
			zephir_create_array(&_89$$64, 2, 0);
			add_assoc_stringl_ex(&_89$$64, SL("type"), SL("literal"));
			zephir_memory_observe(&_90$$64);
			zephir_array_fetch_string(&_90$$64, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2378);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_89$$64, SL("value"), &_90$$64, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_89$$64);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_46: ;
			ZEPHIR_CALL_METHOD_CACHED(&exprReturn, this_ptr, "getFunctionCall", &_zephir_call_cache[8], &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_47: ;
			ZEPHIR_CALL_METHOD_CACHED(&exprReturn, this_ptr, "getCaseExpression", &_zephir_call_cache[9], &expr);
			zephir_check_call_status();
			goto zephir_switch_0_end;
		zephir_switch_0_clause_48: ;
			ZEPHIR_INIT_VAR(&_91$$68);
			zephir_create_array(&_91$$68, 2, 0);
			add_assoc_stringl_ex(&_91$$68, SL("type"), SL("select"));
			ZVAL_BOOL(&_93$$68, 1);
			ZEPHIR_CALL_METHOD_CACHED(&_92$$68, this_ptr, "prepareSelect", &_zephir_call_cache[10], &expr, &_93$$68);
			zephir_check_call_status();
			zephir_array_update_string(&_91$$68, SL("value"), &_92$$68, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_91$$68);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_49: ;
			ZEPHIR_INIT_VAR(&_94$$69);
			zephir_create_array(&_94$$69, 4, 0);
			add_assoc_stringl_ex(&_94$$69, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_94$$69, SL("op"), SL("@@"));
			zephir_array_update_string(&_94$$69, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_94$$69, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_94$$69);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_50: ;
			ZEPHIR_INIT_VAR(&_95$$70);
			zephir_create_array(&_95$$70, 4, 0);
			add_assoc_stringl_ex(&_95$$70, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_95$$70, SL("op"), SL("@>"));
			zephir_array_update_string(&_95$$70, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_95$$70, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_95$$70);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_51: ;
			ZEPHIR_INIT_VAR(&_96$$71);
			zephir_create_array(&_96$$71, 4, 0);
			add_assoc_stringl_ex(&_96$$71, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_96$$71, SL("op"), SL("<@"));
			zephir_array_update_string(&_96$$71, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_96$$71, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_96$$71);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_52: ;
			ZEPHIR_INIT_VAR(&_97$$72);
			zephir_create_array(&_97$$72, 4, 0);
			add_assoc_stringl_ex(&_97$$72, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_97$$72, SL("op"), SL("&&"));
			zephir_array_update_string(&_97$$72, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_97$$72, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_97$$72);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_53: ;
			ZEPHIR_INIT_VAR(&_98$$73);
			zephir_create_array(&_98$$73, 4, 0);
			add_assoc_stringl_ex(&_98$$73, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_98$$73, SL("op"), SL("||"));
			zephir_array_update_string(&_98$$73, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_98$$73, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_98$$73);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_54: ;
			ZEPHIR_INIT_VAR(&_99$$74);
			zephir_create_array(&_99$$74, 4, 0);
			add_assoc_stringl_ex(&_99$$74, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_99$$74, SL("op"), SL("->"));
			zephir_array_update_string(&_99$$74, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_99$$74, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_99$$74);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_55: ;
			ZEPHIR_INIT_VAR(&_100$$75);
			zephir_create_array(&_100$$75, 4, 0);
			add_assoc_stringl_ex(&_100$$75, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_100$$75, SL("op"), SL("->>"));
			zephir_array_update_string(&_100$$75, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_100$$75, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_100$$75);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_56: ;
			ZEPHIR_INIT_VAR(&_101$$76);
			zephir_create_array(&_101$$76, 4, 0);
			add_assoc_stringl_ex(&_101$$76, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_101$$76, SL("op"), SL("#>"));
			zephir_array_update_string(&_101$$76, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_101$$76, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_101$$76);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_57: ;
			ZEPHIR_INIT_VAR(&_102$$77);
			zephir_create_array(&_102$$77, 4, 0);
			add_assoc_stringl_ex(&_102$$77, SL("type"), SL("binary-op"));
			add_assoc_stringl_ex(&_102$$77, SL("op"), SL("#>>"));
			zephir_array_update_string(&_102$$77, SL("left"), &left, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_102$$77, SL("right"), &right, PH_COPY | PH_SEPARATE);
			ZEPHIR_CPY_WRT(&exprReturn, &_102$$77);
			goto zephir_switch_0_end;
		zephir_switch_0_clause_58: ;
			ZEPHIR_INIT_VAR(&_103$$78);
			object_init_ex(&_103$$78, phalcon_mvc_model_query_exceptions_unknownphqlexpressiontype_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_103$$78, "__construct", &_zephir_call_cache[11], &exprType);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_103$$78, "phalcon/Mvc/Model/Query.zep", 2491);
			ZEPHIR_MM_RESTORE();
			return;
		zephir_switch_0_end: ;

		RETURN_CCTOR(&exprReturn);
	}
	_104 = zephir_array_isset_value_string(&expr, SL("domain"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_104) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getQualified", &_zephir_call_cache[12], &expr);
		zephir_check_call_status();
		RETURN_MM();
	}
	_105 = zephir_array_isset_value_long(&expr, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_105) {
		ZEPHIR_INIT_VAR(&listItems);
		array_init(&listItems);
		zephir_is_iterable(&expr, 0, "phalcon/Mvc/Model/Query.zep", 2514);
		if (Z_TYPE_P(&expr) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&expr), _106$$80)
			{
				ZEPHIR_INIT_NVAR(&exprListItem);
				ZVAL_COPY(&exprListItem, _106$$80);
				ZEPHIR_CALL_METHOD_CACHED(&_107$$81, this_ptr, "getExpression", &_zephir_call_cache[13], &exprListItem);
				zephir_check_call_status();
				zephir_array_append(&listItems, &_107$$81, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2511);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &expr, "rewind", &_zephir_call_cache[14]);
			zephir_check_call_status();
			_109$$80 = 1;
			while (1) {
				if (_109$$80) {
					_109$$80 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &expr, "next", &_zephir_call_cache[15]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_108$$80, &expr, "valid", &_zephir_call_cache[16]);
				zephir_check_call_status();
				if (!zend_is_true(&_108$$80)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&exprListItem, &expr, "current", &_zephir_call_cache[17]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_110$$82, this_ptr, "getExpression", &_zephir_call_cache[18], &exprListItem);
					zephir_check_call_status();
					zephir_array_append(&listItems, &_110$$82, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2511);
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
	ZEPHIR_INIT_VAR(&_111);
	object_init_ex(&_111, phalcon_mvc_model_query_exceptions_unknownphqlexpression_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_111, "__construct", &_zephir_call_cache[19]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_111, "phalcon/Mvc/Model/Query.zep", 2520);
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
	zend_bool _6, _7$$4, _8$$4, _14$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, distinct = 0;
	zval *expr_param = NULL, arguments, argument, name, _0, _1, _2, _3, _21, _4$$3, _5$$3, *_9$$7, _10$$7, *_11$$7, _13$$7, _12$$8, _15$$9, _16$$10, _17$$10, _18$$11, _19$$11, _20$$12;
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
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$3, "__construct", &_zephir_call_cache[0], &name, &_5$$3);
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
					ZEPHIR_CALL_METHOD_CACHED(&_12$$8, this_ptr, "getCallArgument", &_zephir_call_cache[1], &argument);
					zephir_check_call_status();
					zephir_array_append(&functionArgs, &_12$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2557);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$7, "rewind", &_zephir_call_cache[2]);
				zephir_check_call_status();
				_14$$7 = 1;
				while (1) {
					if (_14$$7) {
						_14$$7 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$7, "next", &_zephir_call_cache[3]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_13$$7, _9$$7, "valid", &_zephir_call_cache[4]);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&argument, _9$$7, "current", &_zephir_call_cache[5]);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&_15$$9, this_ptr, "getCallArgument", &_zephir_call_cache[6], &argument);
						zephir_check_call_status();
						zephir_array_append(&functionArgs, &_15$$9, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2557);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&argument);
		} else {
			ZEPHIR_INIT_VAR(&_16$$10);
			zephir_create_array(&_16$$10, 1, 0);
			ZEPHIR_CALL_METHOD_CACHED(&_17$$10, this_ptr, "getCallArgument", &_zephir_call_cache[7], &arguments);
			zephir_check_call_status();
			zephir_array_fast_append(&_16$$10, &_17$$10);
			ZEPHIR_CPY_WRT(&functionArgs, &_16$$10);
		}
		if (distinct) {
			zephir_create_array(return_value, 4, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_18$$11);
			zephir_array_fetch_string(&_18$$11, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2569);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(return_value, SL("name"), &_18$$11, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_19$$11);
			ZVAL_LONG(&_19$$11, distinct);
			zephir_array_update_string(return_value, SL("distinct"), &_19$$11, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		} else {
			zephir_create_array(return_value, 3, 0);
			add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
			zephir_memory_observe(&_20$$12);
			zephir_array_fetch_string(&_20$$12, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2576);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(return_value, SL("name"), &_20$$12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(return_value, SL("arguments"), &functionArgs, PH_COPY | PH_SEPARATE);
			RETURN_MM();
		}
	}
	zephir_create_array(return_value, 2, 0);
	add_assoc_stringl_ex(return_value, SL("type"), SL("functionCall"));
	zephir_memory_observe(&_21);
	zephir_array_fetch_string(&_21, &expr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2585);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(return_value, SL("name"), &_21, PH_COPY | PH_SEPARATE);
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
	zend_bool _0, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *group_param = NULL, groupItem, *_1$$3, _3$$3, _2$$4, _5$$5, _6$$6, _7$$6;
	zval group, groupParts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&group);
	ZVAL_UNDEF(&groupParts);
	ZVAL_UNDEF(&groupItem);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
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
				ZEPHIR_CALL_METHOD_CACHED(&_2$$4, this_ptr, "getExpression", &_zephir_call_cache[0], &groupItem);
				zephir_check_call_status();
				zephir_array_append(&groupParts, &_2$$4, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2606);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &group, "rewind", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_4$$3 = 1;
			while (1) {
				if (_4$$3) {
					_4$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, &group, "next", &_zephir_call_cache[2]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_3$$3, &group, "valid", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&groupItem, &group, "current", &_zephir_call_cache[4]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_5$$5, this_ptr, "getExpression", &_zephir_call_cache[5], &groupItem);
					zephir_check_call_status();
					zephir_array_append(&groupParts, &_5$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2606);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&groupItem);
	} else {
		ZEPHIR_INIT_VAR(&_6$$6);
		zephir_create_array(&_6$$6, 1, 0);
		ZEPHIR_CALL_METHOD_CACHED(&_7$$6, this_ptr, "getExpression", &_zephir_call_cache[6], &group);
		zephir_check_call_status();
		zephir_array_fast_append(&_6$$6, &_7$$6);
		ZEPHIR_CPY_WRT(&groupParts, &_6$$6);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
			ZEPHIR_CALL_METHOD_CACHED(&model, manager, "load", &_zephir_call_cache[0], &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[1]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[2]);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_2, "__construct", &_zephir_call_cache[3]);
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
	zend_string *_25, *_48, *_31$$19, *_51$$23, *_70$$38;
	zend_ulong _24, _47, _30$$19, _50$$23, _69$$38;
	zend_bool _1, _2, _14, _40, _67, _6$$7, _7$$8, _10$$10, _16$$12, _17$$13, _20$$15, _26$$17, _52$$24, _56$$29, _61$$32, _71$$39, _75$$44, _80$$47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *select_param = NULL, __$true, models, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, modelsInstances, fromModels, manager, selectJoins, joinItem, joins, joinData, schema, source, model, realModelName, completeSource, joinType, aliasExpr, alias, joinAliasName, joinExpr, fromModelName, joinAlias, joinModel, joinSource, preCondition, modelNameAlias, relation, relations, modelAlias, sqlJoin, sqlJoinItem, selectTables, tables, tableItem, _0, *_3, _4, *_5, _13, *_23, *_34, _35, *_36, _39, *_43, _44, _45, *_46, _66, _8$$9, _9$$9, _11$$11, _12$$11, _15$$12, _18$$14, _19$$14, _21$$16, _22$$16, _27$$18, _28$$19, *_29$$19, _37$$21, _38$$21, _41$$22, _42$$22, *_49$$23, _53$$28, _54$$28, _55$$29, *_57$$32, _58$$32, *_59$$32, _60$$32, _63$$36, *_68$$38, _72$$43, _73$$43, _74$$44, *_76$$47, _77$$47, *_78$$47, _79$$47, _82$$51;
	zval select, sqlJoins, joinModels, joinSources, joinTypes, joinPreCondition, joinPrepared, _32$$20, _33$$20, _62$$36, _64$$37, _65$$37, _81$$51, _83$$52, _84$$52;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&select);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&joinModels);
	ZVAL_UNDEF(&joinSources);
	ZVAL_UNDEF(&joinTypes);
	ZVAL_UNDEF(&joinPreCondition);
	ZVAL_UNDEF(&joinPrepared);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_62$$36);
	ZVAL_UNDEF(&_64$$37);
	ZVAL_UNDEF(&_65$$37);
	ZVAL_UNDEF(&_81$$51);
	ZVAL_UNDEF(&_83$$52);
	ZVAL_UNDEF(&_84$$52);
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_44);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_66);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_53$$28);
	ZVAL_UNDEF(&_54$$28);
	ZVAL_UNDEF(&_55$$29);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_60$$32);
	ZVAL_UNDEF(&_63$$36);
	ZVAL_UNDEF(&_72$$43);
	ZVAL_UNDEF(&_73$$43);
	ZVAL_UNDEF(&_74$$44);
	ZVAL_UNDEF(&_77$$47);
	ZVAL_UNDEF(&_79$$47);
	ZVAL_UNDEF(&_82$$51);
	ZEND_TLS zephir_method_cache _zephir_call_cache[42];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&models, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1090, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&sqlAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 1091, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&sqlAliasesModels, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 1092, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&sqlModelsAliases, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 1093, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&sqlAliasesModelsInstances, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 1088, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
			ZEPHIR_CALL_METHOD_CACHED(&joinData, this_ptr, "getJoin", &_zephir_call_cache[0], &manager, &joinItem);
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
			ZEPHIR_CALL_METHOD_CACHED(&joinType, this_ptr, "getJoinType", &_zephir_call_cache[1], &joinItem);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&aliasExpr);
			_6$$7 = zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_6$$7) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2719);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_7$$8 = zephir_array_isset_value(&joinModels, &alias);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_7$$8)) {
					ZEPHIR_INIT_NVAR(&_8$$9);
					object_init_ex(&_8$$9, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_9$$9, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_8$$9, "__construct", &_zephir_call_cache[2], &alias, &_9$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$9, "phalcon/Mvc/Model/Query.zep", 2725);
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
				_10$$10 = zephir_array_isset_value(&joinModels, &realModelName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_10$$10)) {
					ZEPHIR_INIT_NVAR(&_11$$11);
					object_init_ex(&_11$$11, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
					zephir_read_property_cached(&_12$$11, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$11, "__construct", &_zephir_call_cache[3], &realModelName, &_12$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$11, "phalcon/Mvc/Model/Query.zep", 2782);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_14 = 1;
		while (1) {
			if (_14) {
				_14 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13, _3, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&joinItem, _3, "current", &_zephir_call_cache[7]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&joinData, this_ptr, "getJoin", &_zephir_call_cache[8], &manager, &joinItem);
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
				ZEPHIR_INIT_NVAR(&_15$$12);
				zephir_create_array(&_15$$12, 2, 0);
				zephir_array_fast_append(&_15$$12, &source);
				zephir_array_fast_append(&_15$$12, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_15$$12);
				ZEPHIR_CALL_METHOD_CACHED(&joinType, this_ptr, "getJoinType", &_zephir_call_cache[9], &joinItem);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&aliasExpr);
				_16$$12 = zephir_array_isset_string_fetch(&aliasExpr, &joinItem, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_16$$12) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_string(&alias, &aliasExpr, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2719);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_17$$13 = zephir_array_isset_value(&joinModels, &alias);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_17$$13)) {
						ZEPHIR_INIT_NVAR(&_18$$14);
						object_init_ex(&_18$$14, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_19$$14, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_18$$14, "__construct", &_zephir_call_cache[10], &alias, &_19$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$14, "phalcon/Mvc/Model/Query.zep", 2725);
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
					_20$$15 = zephir_array_isset_value(&joinModels, &realModelName);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_20$$15)) {
						ZEPHIR_INIT_NVAR(&_21$$16);
						object_init_ex(&_21$$16, phalcon_mvc_model_query_exceptions_joinaliasalreadyused_ce);
						zephir_read_property_cached(&_22$$16, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_21$$16, "__construct", &_zephir_call_cache[11], &realModelName, &_22$$16);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_21$$16, "phalcon/Mvc/Model/Query.zep", 2782);
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
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _24, _25, _23)
	{
		ZEPHIR_INIT_NVAR(&joinAliasName);
		if (_25 != NULL) { 
			ZVAL_STR_COPY(&joinAliasName, _25);
		} else {
			ZVAL_LONG(&joinAliasName, _24);
		}
		ZEPHIR_INIT_NVAR(&joinItem);
		ZVAL_COPY(&joinItem, _23);
		ZEPHIR_OBS_NVAR(&joinExpr);
		_26$$17 = zephir_array_isset_string_fetch(&joinExpr, &joinItem, SL("conditions"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_26$$17) {
			ZEPHIR_CALL_METHOD_CACHED(&_27$$18, this_ptr, "getExpression", &_zephir_call_cache[12], &joinExpr);
			zephir_check_call_status();
			zephir_array_update_zval(&joinPreCondition, &joinAliasName, &_27$$18, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&joinItem);
	ZEPHIR_INIT_NVAR(&joinAliasName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 1073, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_28$$19);
		zephir_is_iterable(&joinPrepared, 0, "phalcon/Mvc/Model/Query.zep", 2869);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinPrepared), _30$$19, _31$$19, _29$$19)
		{
			ZEPHIR_INIT_NVAR(&joinAliasName);
			if (_31$$19 != NULL) { 
				ZVAL_STR_COPY(&joinAliasName, _31$$19);
			} else {
				ZVAL_LONG(&joinAliasName, _30$$19);
			}
			ZEPHIR_INIT_NVAR(&_28$$19);
			ZVAL_COPY(&_28$$19, _29$$19);
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
			ZEPHIR_INIT_NVAR(&_32$$20);
			zephir_create_array(&_32$$20, 3, 0);
			zephir_array_update_string(&_32$$20, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_32$$20, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_33$$20);
			zephir_create_array(&_33$$20, 1, 0);
			zephir_array_fast_append(&_33$$20, &preCondition);
			zephir_array_update_string(&_32$$20, SL("conditions"), &_33$$20, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlJoins, &_32$$20, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2866);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_28$$19);
		ZEPHIR_INIT_NVAR(&joinAliasName);
		RETURN_CTOR(&sqlJoins);
	}
	ZEPHIR_INIT_NVAR(&fromModels);
	array_init(&fromModels);
	if (Z_TYPE_P(&selectTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_35);
		zephir_string_to_char_array(&_35, &selectTables);
		_34 = &_35;
	} else {
		_34 = &selectTables;
	}
	zephir_is_iterable(_34, 0, "phalcon/Mvc/Model/Query.zep", 2884);
	if (Z_TYPE_P(_34) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_34), _36)
		{
			ZEPHIR_INIT_NVAR(&tableItem);
			ZVAL_COPY(&tableItem, _36);
			ZEPHIR_OBS_NVAR(&_37$$21);
			zephir_array_fetch_string(&_37$$21, &tableItem, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_38$$21);
			zephir_array_fetch_string(&_38$$21, &_37$$21, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&fromModels, &_38$$21, &__$true, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _34, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_40 = 1;
		while (1) {
			if (_40) {
				_40 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _34, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_39, _34, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_39)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&tableItem, _34, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_41$$22);
				zephir_array_fetch_string(&_41$$22, &tableItem, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_42$$22);
				zephir_array_fetch_string(&_42$$22, &_41$$22, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2878);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&fromModels, &_42$$22, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&tableItem);
	if (Z_TYPE_P(&fromModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_44);
		zephir_string_to_char_array(&_44, &fromModels);
		_43 = &_44;
	} else {
		_43 = &fromModels;
	}
	ZEPHIR_INIT_VAR(&_45);
	zephir_is_iterable(_43, 0, "phalcon/Mvc/Model/Query.zep", 3002);
	if (Z_TYPE_P(_43) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_43), _47, _48, _46)
		{
			ZEPHIR_INIT_NVAR(&fromModelName);
			if (_48 != NULL) { 
				ZVAL_STR_COPY(&fromModelName, _48);
			} else {
				ZVAL_LONG(&fromModelName, _47);
			}
			ZEPHIR_INIT_NVAR(&_45);
			ZVAL_COPY(&_45, _46);
			zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 3000);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _50$$23, _51$$23, _49$$23)
			{
				ZEPHIR_INIT_NVAR(&joinAlias);
				if (_51$$23 != NULL) { 
					ZVAL_STR_COPY(&joinAlias, _51$$23);
				} else {
					ZVAL_LONG(&joinAlias, _50$$23);
				}
				ZEPHIR_INIT_NVAR(&joinModel);
				ZVAL_COPY(&joinModel, _49$$23);
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
				_52$$24 = zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_52$$24)) {
					ZEPHIR_OBS_NVAR(&modelNameAlias);
					zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2903);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[17], &fromModelName, &modelNameAlias);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
						ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[18], &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (Z_TYPE_P(&relations) == IS_ARRAY) {
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_53$$28);
								object_init_ex(&_53$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_54$$28, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$28, "__construct", &_zephir_call_cache[19], &fromModelName, &joinModel, &_54$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_53$$28, "phalcon/Mvc/Model/Query.zep", 2927);
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
						ZEPHIR_CALL_METHOD_CACHED(&_55$$29, &relation, "isThrough", &_zephir_call_cache[20]);
						zephir_check_call_status();
						if (!(zephir_is_true(&_55$$29))) {
							ZEPHIR_CALL_METHOD_CACHED(&sqlJoin, this_ptr, "getSingleJoin", &_zephir_call_cache[21], &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(&sqlJoin, this_ptr, "getMultiJoin", &_zephir_call_cache[22], &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
							zephir_check_call_status();
						}
						_56$$29 = zephir_array_isset_value_long(&sqlJoin, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_56$$29) {
							if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_58$$32);
								zephir_string_to_char_array(&_58$$32, &sqlJoin);
								_57$$32 = &_58$$32;
							} else {
								_57$$32 = &sqlJoin;
							}
							zephir_is_iterable(_57$$32, 0, "phalcon/Mvc/Model/Query.zep", 2974);
							if (Z_TYPE_P(_57$$32) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_57$$32), _59$$32)
								{
									ZEPHIR_INIT_NVAR(&sqlJoinItem);
									ZVAL_COPY(&sqlJoinItem, _59$$32);
									zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _57$$32, "rewind", &_zephir_call_cache[23]);
								zephir_check_call_status();
								_61$$32 = 1;
								while (1) {
									if (_61$$32) {
										_61$$32 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _57$$32, "next", &_zephir_call_cache[24]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_60$$32, _57$$32, "valid", &_zephir_call_cache[25]);
									zephir_check_call_status();
									if (!zend_is_true(&_60$$32)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&sqlJoinItem, _57$$32, "current", &_zephir_call_cache[26]);
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
						ZEPHIR_INIT_NVAR(&_62$$36);
						zephir_create_array(&_62$$36, 3, 0);
						zephir_array_update_string(&_62$$36, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_62$$36, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_63$$36);
						array_init(&_63$$36);
						zephir_array_update_string(&_62$$36, SL("conditions"), &_63$$36, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_62$$36, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2986);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_INIT_NVAR(&_64$$37);
					zephir_create_array(&_64$$37, 3, 0);
					zephir_array_update_string(&_64$$37, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_64$$37, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_65$$37);
					zephir_create_array(&_65$$37, 1, 0);
					zephir_array_fast_append(&_65$$37, &preCondition);
					zephir_array_update_string(&_64$$37, SL("conditions"), &_65$$37, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoins, &_64$$37, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2997);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _43, "rewind", &_zephir_call_cache[27]);
		zephir_check_call_status();
		_67 = 1;
		while (1) {
			if (_67) {
				_67 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _43, "next", &_zephir_call_cache[28]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_66, _43, "valid", &_zephir_call_cache[29]);
			zephir_check_call_status();
			if (!zend_is_true(&_66)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&fromModelName, _43, "key", &_zephir_call_cache[30]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_45, _43, "current", &_zephir_call_cache[31]);
			zephir_check_call_status();
				zephir_is_iterable(&joinModels, 0, "phalcon/Mvc/Model/Query.zep", 3000);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&joinModels), _69$$38, _70$$38, _68$$38)
				{
					ZEPHIR_INIT_NVAR(&joinAlias);
					if (_70$$38 != NULL) { 
						ZVAL_STR_COPY(&joinAlias, _70$$38);
					} else {
						ZVAL_LONG(&joinAlias, _69$$38);
					}
					ZEPHIR_INIT_NVAR(&joinModel);
					ZVAL_COPY(&joinModel, _68$$38);
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
					_71$$39 = zephir_array_isset_fetch(&preCondition, &joinPreCondition, &joinAlias, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_71$$39)) {
						ZEPHIR_OBS_NVAR(&modelNameAlias);
						zephir_array_fetch(&modelNameAlias, &sqlAliasesModels, &joinAlias, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 2903);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[32], &fromModelName, &modelNameAlias);
						zephir_check_call_status();
						if (ZEPHIR_IS_FALSE_IDENTICAL(&relation)) {
							ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[33], &fromModelName, &modelNameAlias);
							zephir_check_call_status();
							if (Z_TYPE_P(&relations) == IS_ARRAY) {
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_72$$43);
									object_init_ex(&_72$$43, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_73$$43, this_ptr, _zephir_prop_7, 1072, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_72$$43, "__construct", &_zephir_call_cache[34], &fromModelName, &joinModel, &_73$$43);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_72$$43, "phalcon/Mvc/Model/Query.zep", 2927);
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
							ZEPHIR_CALL_METHOD_CACHED(&_74$$44, &relation, "isThrough", &_zephir_call_cache[35]);
							zephir_check_call_status();
							if (!(zephir_is_true(&_74$$44))) {
								ZEPHIR_CALL_METHOD_CACHED(&sqlJoin, this_ptr, "getSingleJoin", &_zephir_call_cache[36], &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(&sqlJoin, this_ptr, "getMultiJoin", &_zephir_call_cache[37], &joinType, &joinSource, &modelAlias, &joinAlias, &relation);
								zephir_check_call_status();
							}
							_75$$44 = zephir_array_isset_value_long(&sqlJoin, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_75$$44) {
								if (Z_TYPE_P(&sqlJoin) == IS_STRING) {
									ZEPHIR_INIT_NVAR(&_77$$47);
									zephir_string_to_char_array(&_77$$47, &sqlJoin);
									_76$$47 = &_77$$47;
								} else {
									_76$$47 = &sqlJoin;
								}
								zephir_is_iterable(_76$$47, 0, "phalcon/Mvc/Model/Query.zep", 2974);
								if (Z_TYPE_P(_76$$47) == IS_ARRAY) {
									ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_76$$47), _78$$47)
									{
										ZEPHIR_INIT_NVAR(&sqlJoinItem);
										ZVAL_COPY(&sqlJoinItem, _78$$47);
										zephir_array_append(&sqlJoins, &sqlJoinItem, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2972);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
									} ZEND_HASH_FOREACH_END();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _76$$47, "rewind", &_zephir_call_cache[38]);
									zephir_check_call_status();
									_80$$47 = 1;
									while (1) {
										if (_80$$47) {
											_80$$47 = 0;
										} else {
											ZEPHIR_CALL_METHOD_CACHED(NULL, _76$$47, "next", &_zephir_call_cache[39]);
											zephir_check_call_status();
										}
										ZEPHIR_CALL_METHOD_CACHED(&_79$$47, _76$$47, "valid", &_zephir_call_cache[40]);
										zephir_check_call_status();
										if (!zend_is_true(&_79$$47)) {
											break;
										}
										ZEPHIR_CALL_METHOD_CACHED(&sqlJoinItem, _76$$47, "current", &_zephir_call_cache[41]);
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
							ZEPHIR_INIT_NVAR(&_81$$51);
							zephir_create_array(&_81$$51, 3, 0);
							zephir_array_update_string(&_81$$51, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_81$$51, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_82$$51);
							array_init(&_82$$51);
							zephir_array_update_string(&_81$$51, SL("conditions"), &_82$$51, PH_COPY | PH_SEPARATE);
							zephir_array_append(&sqlJoins, &_81$$51, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2986);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						ZEPHIR_INIT_NVAR(&_83$$52);
						zephir_create_array(&_83$$52, 3, 0);
						zephir_array_update_string(&_83$$52, SL("type"), &joinType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_83$$52, SL("source"), &joinSource, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$52);
						zephir_create_array(&_84$$52, 1, 0);
						zephir_array_fast_append(&_84$$52, &preCondition);
						zephir_array_update_string(&_83$$52, SL("conditions"), &_84$$52, PH_COPY | PH_SEPARATE);
						zephir_array_append(&sqlJoins, &_83$$52, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 2997);
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
	ZEPHIR_INIT_NVAR(&_45);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_2, "__construct", &_zephir_call_cache[1], &type, &_3);
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
	zend_bool _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limitClause_param = NULL, number, offset, _1$$3, _3$$4;
	zval limitClause, limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limitClause);
	ZVAL_UNDEF(&limit);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "getExpression", &_zephir_call_cache[0], &number);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("number"), &_1$$3, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&offset);
	_2 = zephir_array_isset_string_fetch(&offset, &limitClause, SL("offset"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "getExpression", &_zephir_call_cache[1], &offset);
		zephir_check_call_status();
		zephir_array_update_string(&limit, SL("offset"), &_3$$4, PH_COPY | PH_SEPARATE);
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
	zend_bool _13$$3, _6$$4, _14$$6;
	zend_ulong _4$$3;
	zval sqlJoins, _10$$4, _11$$4, _19$$6, _20$$6, _22$$8, _23$$8, _24$$8, _26$$8, _27$$8, _28$$8, _29$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, intermediateModelName, intermediateModel, intermediateSource, intermediateSchema, intermediateFields, intermediateReferencedFields, referencedModelName, manager, field, position, intermediateField, sqlEqualsJoinCondition, _0, *_1$$3, _2$$3, *_3$$3, _12$$3, _9$$4, _7$$5, _8$$5, _17$$6, _18$$6, _15$$7, _16$$7, _21$$8, _25$$8;
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
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&sqlJoins);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_29$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
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
	ZEPHIR_CALL_METHOD_CACHED(&fields, relation, "getFields", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedFields, relation, "getReferencedFields", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateModelName, relation, "getIntermediateModel", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1083, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD_CACHED(&intermediateModel, &manager, "load", &_zephir_call_cache[3], &intermediateModelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateSource, &intermediateModel, "getSource", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateSchema, &intermediateModel, "getSchema", &_zephir_call_cache[5]);
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
	ZEPHIR_CALL_METHOD_CACHED(&intermediateFields, relation, "getIntermediateFields", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&intermediateReferencedFields, relation, "getIntermediateReferencedFields", &_zephir_call_cache[7]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedModelName, relation, "getReferencedModel", &_zephir_call_cache[8]);
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
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$5, "__construct", &_zephir_call_cache[9], &modelAlias_zv, &joinAlias_zv, &_8$$5);
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
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 3, 0);
				add_assoc_long_ex(&_10$$4, SL("type"), 355);
				zephir_array_update_string(&_10$$4, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$4, SL("name"), &field, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_9$$4, this_ptr, "getQualified", &_zephir_call_cache[10], &_10$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("left"), &_9$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$4);
				zephir_create_array(&_11$$4, 3, 0);
				add_assoc_stringl_ex(&_11$$4, SL("type"), SL("qualified"));
				zephir_array_update_string(&_11$$4, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_11$$4, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_9$$4, this_ptr, "getQualified", &_zephir_call_cache[11], &_11$$4);
				zephir_check_call_status();
				zephir_array_update_string(&sqlEqualsJoinCondition, SL("right"), &_9$$4, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "rewind", &_zephir_call_cache[12]);
			zephir_check_call_status();
			_13$$3 = 1;
			while (1) {
				if (_13$$3) {
					_13$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "next", &_zephir_call_cache[13]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_12$$3, _1$$3, "valid", &_zephir_call_cache[14]);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _1$$3, "key", &_zephir_call_cache[15]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&position, _1$$3, "current", &_zephir_call_cache[16]);
				zephir_check_call_status();
					_14$$6 = zephir_array_isset_value(&referencedFields, &position);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_14$$6))) {
						ZEPHIR_INIT_NVAR(&_15$$7);
						object_init_ex(&_15$$7, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_16$$7, this_ptr, _zephir_prop_1, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_15$$7, "__construct", &_zephir_call_cache[17], &modelAlias_zv, &joinAlias_zv, &_16$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$7, "phalcon/Mvc/Model/Query.zep", 3142);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&intermediateField);
					zephir_array_fetch(&intermediateField, &intermediateFields, &position, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3148);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_17$$6);
					zephir_create_array(&_17$$6, 4, 0);
					add_assoc_stringl_ex(&_17$$6, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_17$$6, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_19$$6);
					zephir_create_array(&_19$$6, 3, 0);
					add_assoc_long_ex(&_19$$6, SL("type"), 355);
					zephir_array_update_string(&_19$$6, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_19$$6, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_18$$6, this_ptr, "getQualified", &_zephir_call_cache[18], &_19$$6);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$6, SL("left"), &_18$$6, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$6);
					zephir_create_array(&_20$$6, 3, 0);
					add_assoc_stringl_ex(&_20$$6, SL("type"), SL("qualified"));
					zephir_array_update_string(&_20$$6, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_20$$6, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_18$$6, this_ptr, "getQualified", &_zephir_call_cache[19], &_20$$6);
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
		ZEPHIR_CALL_METHOD_CACHED(&_25$$8, this_ptr, "getQualified", &_zephir_call_cache[20], &_26$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("left"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 3, 0);
		add_assoc_stringl_ex(&_27$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_27$$8, SL("domain"), &intermediateModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_27$$8, SL("name"), &intermediateFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_25$$8, this_ptr, "getQualified", &_zephir_call_cache[21], &_27$$8);
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
		ZEPHIR_CALL_METHOD_CACHED(&_25$$8, this_ptr, "getQualified", &_zephir_call_cache[22], &_28$$8);
		zephir_check_call_status();
		zephir_array_update_string(&_24$$8, SL("left"), &_25$$8, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_29$$8);
		zephir_create_array(&_29$$8, 3, 0);
		add_assoc_stringl_ex(&_29$$8, SL("type"), SL("qualified"));
		zephir_array_update_string(&_29$$8, SL("domain"), &referencedModelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_29$$8, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_25$$8, this_ptr, "getQualified", &_zephir_call_cache[23], &_29$$8);
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
 *
 * @phpstan-return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getOrderClause)
{
	zend_bool _0, _11, _5$$5, _13$$10;
	zval orderParts, orderPartSort;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *order, order_sub, orderColumns, orderItem, orderPartExpr, orderSort, *_1, _2, *_3, _10, _4$$5, _6$$7, _7$$8, _8$$8, _9$$9, _12$$10, _14$$12, _15$$12, _16$$13, _17$$13, _18$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&order_sub);
	ZVAL_UNDEF(&orderColumns);
	ZVAL_UNDEF(&orderItem);
	ZVAL_UNDEF(&orderPartExpr);
	ZVAL_UNDEF(&orderSort);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&orderParts);
	ZVAL_UNDEF(&orderPartSort);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
			ZEPHIR_CALL_METHOD_CACHED(&orderPartExpr, this_ptr, "getExpression", &_zephir_call_cache[0], &_4$$5);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&orderSort);
			_5$$5 = zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_5$$5) {
				if (ZEPHIR_IS_LONG(&orderSort, 327)) {
					ZEPHIR_INIT_NVAR(&orderPartSort);
					zephir_create_array(&orderPartSort, 2, 0);
					zephir_array_fast_append(&orderPartSort, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZVAL_STRING(&_6$$7, "ASC");
					zephir_array_fast_append(&orderPartSort, &_6$$7);
				} else {
					ZEPHIR_INIT_NVAR(&_7$$8);
					zephir_create_array(&_7$$8, 2, 0);
					zephir_array_fast_append(&_7$$8, &orderPartExpr);
					ZEPHIR_INIT_NVAR(&_8$$8);
					ZVAL_STRING(&_8$$8, "DESC");
					zephir_array_fast_append(&_7$$8, &_8$$8);
					ZEPHIR_CPY_WRT(&orderPartSort, &_7$$8);
				}
			} else {
				ZEPHIR_INIT_NVAR(&_9$$9);
				zephir_create_array(&_9$$9, 1, 0);
				zephir_array_fast_append(&_9$$9, &orderPartExpr);
				ZEPHIR_CPY_WRT(&orderPartSort, &_9$$9);
			}
			zephir_array_append(&orderParts, &orderPartSort, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3281);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _1, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_10, _1, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&orderItem, _1, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_12$$10);
				zephir_array_fetch_string(&_12$$10, &orderItem, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3266);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&orderPartExpr, this_ptr, "getExpression", &_zephir_call_cache[5], &_12$$10);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&orderSort);
				_13$$10 = zephir_array_isset_string_fetch(&orderSort, &orderItem, SL("sort"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_13$$10) {
					if (ZEPHIR_IS_LONG(&orderSort, 327)) {
						ZEPHIR_INIT_NVAR(&_14$$12);
						zephir_create_array(&_14$$12, 2, 0);
						zephir_array_fast_append(&_14$$12, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_15$$12);
						ZVAL_STRING(&_15$$12, "ASC");
						zephir_array_fast_append(&_14$$12, &_15$$12);
						ZEPHIR_CPY_WRT(&orderPartSort, &_14$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_16$$13);
						zephir_create_array(&_16$$13, 2, 0);
						zephir_array_fast_append(&_16$$13, &orderPartExpr);
						ZEPHIR_INIT_NVAR(&_17$$13);
						ZVAL_STRING(&_17$$13, "DESC");
						zephir_array_fast_append(&_16$$13, &_17$$13);
						ZEPHIR_CPY_WRT(&orderPartSort, &_16$$13);
					}
				} else {
					ZEPHIR_INIT_NVAR(&_18$$14);
					zephir_create_array(&_18$$14, 1, 0);
					zephir_array_fast_append(&_18$$14, &orderPartExpr);
					ZEPHIR_CPY_WRT(&orderPartSort, &_18$$14);
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
	zend_bool _1, _4, _5, _6, _7, _8, _10, _12$$6, _19$$8, _22$$11, _33$$14, _42$$14, _47$$26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, number = 0;
	zval *expr_param = NULL, columnName, nestingLevel, sqlColumnAliases, metaData, sqlAliases, source, sqlAliasesModelsInstances, realColumnName, columnDomain, model, models, columnMap, hasModel, className, _0, _9, _2$$3, _3$$3, _11$$6, _16$$6, _17$$6, _13$$7, _14$$7, _15$$7, _18$$8, _20$$9, _21$$9, _23$$12, _24$$12, _25$$14, *_26$$14, _27$$14, *_28$$14, _32$$14, _40$$14, _45$$14, _46$$14, _29$$15, _30$$17, _31$$17, _34$$18, _35$$20, _36$$20, _37$$21, _38$$21, _39$$21, _41$$22, _43$$23, _44$$23, _48$$27, _49$$27, _50$$27;
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
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_45$$14);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$21);
	ZVAL_UNDEF(&_38$$21);
	ZVAL_UNDEF(&_39$$21);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_43$$23);
	ZVAL_UNDEF(&_44$$23);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$27);
	ZVAL_UNDEF(&_50$$27);
	ZEND_TLS zephir_method_cache _zephir_call_cache[19];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&nestingLevel, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1095, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &nestingLevel);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_1, 1095, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&metaData, &_9);
	zephir_memory_observe(&columnDomain);
	_10 = zephir_array_isset_string_fetch(&columnDomain, &expr, SL("domain"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_10) {
		zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_3, 1090, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_15$$7);
			ZVAL_STRING(&_15$$7, "11");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$7, "__construct", &_zephir_call_cache[0], &columnDomain, &_15$$7, &_14$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_13$$7, "phalcon/Mvc/Model/Query.zep", 3333);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_17$$6);
		ZVAL_STRING(&_17$$6, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_16$$6, phalcon_support_settings_ce, "get", &_zephir_call_cache[1], &_17$$6);
		zephir_check_call_status();
		if (zephir_is_true(&_16$$6)) {
			zephir_read_property_cached(&_18$$8, this_ptr, _zephir_prop_5, 1093, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$9, "__construct", &_zephir_call_cache[2], &columnDomain, &_21$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$9, "phalcon/Mvc/Model/Query.zep", 3350);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getReverseColumnMap", &_zephir_call_cache[3], &model);
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_23$$12, "__construct", &_zephir_call_cache[4], &columnName, &columnDomain, &_24$$12);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
				ZEPHIR_CALL_METHOD_CACHED(&_29$$15, &metaData, "hasAttribute", &_zephir_call_cache[5], &model, &columnName);
				zephir_check_call_status();
				if (zephir_is_true(&_29$$15)) {
					number++;
					if (UNEXPECTED(number > 1)) {
						ZEPHIR_INIT_NVAR(&_30$$17);
						object_init_ex(&_30$$17, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
						zephir_read_property_cached(&_31$$17, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_30$$17, "__construct", &_zephir_call_cache[6], &columnName, &_31$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_30$$17, "phalcon/Mvc/Model/Query.zep", 3381);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&hasModel, &model);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$14, "rewind", &_zephir_call_cache[7]);
			zephir_check_call_status();
			_33$$14 = 1;
			while (1) {
				if (_33$$14) {
					_33$$14 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _26$$14, "next", &_zephir_call_cache[8]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_32$$14, _26$$14, "valid", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!zend_is_true(&_32$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&model, _26$$14, "current", &_zephir_call_cache[10]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_34$$18, &metaData, "hasAttribute", &_zephir_call_cache[11], &model, &columnName);
					zephir_check_call_status();
					if (zephir_is_true(&_34$$18)) {
						number++;
						if (UNEXPECTED(number > 1)) {
							ZEPHIR_INIT_NVAR(&_35$$20);
							object_init_ex(&_35$$20, phalcon_mvc_model_query_exceptions_ambiguouscolumn_ce);
							zephir_read_property_cached(&_36$$20, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_35$$20, "__construct", &_zephir_call_cache[12], &columnName, &_36$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_35$$20, "phalcon/Mvc/Model/Query.zep", 3381);
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&hasModel, &model);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&model);
		if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&hasModel))) {
			ZEPHIR_INIT_VAR(&_37$$21);
			object_init_ex(&_37$$21, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
			zephir_read_property_cached(&_38$$21, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_39$$21);
			ZVAL_STRING(&_39$$21, "1");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_37$$21, "__construct", &_zephir_call_cache[13], &columnName, &_39$$21, &_38$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_37$$21, "phalcon/Mvc/Model/Query.zep", 3393);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_40$$14, this_ptr, _zephir_prop_7, 1089, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&models, &_40$$14);
		if (UNEXPECTED(Z_TYPE_P(&models) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_41$$22);
			object_init_ex(&_41$$22, phalcon_mvc_model_query_exceptions_modelslistnotloaded_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_41$$22, "__construct", &_zephir_call_cache[14]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_41$$22, "phalcon/Mvc/Model/Query.zep", 3402);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, &hasModel, 0);
		ZEPHIR_OBS_NVAR(&source);
		_42$$14 = zephir_array_isset_fetch(&source, &models, &className, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_42$$14))) {
			ZEPHIR_INIT_VAR(&_43$$23);
			object_init_ex(&_43$$23, phalcon_mvc_model_query_exceptions_modelsourcenotfound_ce);
			zephir_read_property_cached(&_44$$23, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_43$$23, "__construct", &_zephir_call_cache[15], &className, &_44$$23);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_43$$23, "phalcon/Mvc/Model/Query.zep", 3411);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_46$$14);
		ZVAL_STRING(&_46$$14, "orm.column_renaming");
		ZEPHIR_CALL_CE_STATIC_CACHED(&_45$$14, phalcon_support_settings_ce, "get", &_zephir_call_cache[16], &_46$$14);
		zephir_check_call_status();
		if (zephir_is_true(&_45$$14)) {
			ZEPHIR_CALL_METHOD_CACHED(&columnMap, &metaData, "getReverseColumnMap", &_zephir_call_cache[17], &hasModel);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&realColumnName);
			_47$$26 = zephir_array_isset_fetch(&realColumnName, &columnMap, &columnName, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_47$$26))) {
				ZEPHIR_INIT_VAR(&_48$$27);
				object_init_ex(&_48$$27, phalcon_mvc_model_query_exceptions_columnnotinselectedmodels_ce);
				zephir_read_property_cached(&_49$$27, this_ptr, _zephir_prop_4, 1072, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_VAR(&_50$$27);
				ZVAL_STRING(&_50$$27, "3");
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_48$$27, "__construct", &_zephir_call_cache[18], &columnName, &_50$$27, &_49$$27);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_48$$27, "phalcon/Mvc/Model/Query.zep", 3428);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	if (!intermediate_param || Z_TYPE_P(intermediate_param) == IS_NULL) {
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&transaction, "getConnection", &_zephir_call_cache[0]);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectreadconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(&connection, model, "selectReadConnection", &_zephir_call_cache[1], &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_readconnectionmissing_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3473);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(model, "getReadConnection", &_zephir_call_cache[3]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
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
	ZEPHIR_CALL_METHOD_CACHED(&_3, model, "getSource", &_zephir_call_cache[0]);
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
	ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "__construct", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 1078, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setDI", &_zephir_call_cache[2], &_8);
	zephir_check_call_status();
	ZVAL_LONG(&_9, 309);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setType", &_zephir_call_cache[3], &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &query, "setIntermediate", &_zephir_call_cache[4], &selectIr);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&query, "execute", &_zephir_call_cache[5], &bindParams, &bindTypes);
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
	zend_string *_8$$4;
	zend_ulong _7$$4;
	zend_bool _0, _2, _21, _15$$4, _24$$10, _28$$10, _29$$12, _35$$16;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column_param = NULL, columnType, sqlAliases, modelName, source, columnDomain, sqlColumnAlias, preparedAlias, sqlExprColumn, sqlAliasesModels, columnData, balias, eager, _37, _1$$3, _3$$4, *_4$$4, _5$$4, *_6$$4, _14$$4, _9$$5, _10$$5, _11$$5, _13$$6, _16$$7, _17$$7, _18$$7, _19$$7, _20$$8, _22$$9, _23$$10, _32$$10, _25$$11, _26$$11, _27$$11, _30$$13, _31$$13, _33$$15, _34$$16, _36$$18;
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
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_36$$18);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3560);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sqlColumns);
	array_init(&sqlColumns);
	zephir_memory_observe(&eager);
	_2 = zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2;
	if (ZEPHIR_IS_LONG(&columnType, 352)) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1089, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&_3$$4) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_string_to_char_array(&_5$$4, &_3$$4);
			_4$$4 = &_5$$4;
		} else {
			_4$$4 = &_3$$4;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Mvc/Model/Query.zep", 3590);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4$$4), _7$$4, _8$$4, _6$$4)
			{
				ZEPHIR_INIT_NVAR(&modelName);
				if (_8$$4 != NULL) { 
					ZVAL_STR_COPY(&modelName, _8$$4);
				} else {
					ZVAL_LONG(&modelName, _7$$4);
				}
				ZEPHIR_INIT_NVAR(&source);
				ZVAL_COPY(&source, _6$$4);
				ZEPHIR_INIT_NVAR(&sqlColumn);
				zephir_create_array(&sqlColumn, 4, 0);
				add_assoc_stringl_ex(&sqlColumn, SL("type"), SL("object"));
				zephir_array_update_string(&sqlColumn, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&sqlColumn, SL("column"), &source, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_STRING(&_10$$5, "\\");
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_fast_strpos(&_11$$5, &modelName, &_10$$5, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_11$$5)) {
					ZEPHIR_CPY_WRT(&_9$$5, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&_9$$5, "lcfirst", &_12, 57, &modelName);
					zephir_check_call_status();
				}
				zephir_array_update_string(&sqlColumn, SL("balias"), &_9$$5, PH_COPY | PH_SEPARATE);
				if (Z_TYPE_P(&eager) != IS_NULL) {
					zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch_string(&_13$$6, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3584);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&sqlColumn, SL("eagerType"), &_13$$6, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "rewind", &_zephir_call_cache[1]);
			zephir_check_call_status();
			_15$$4 = 1;
			while (1) {
				if (_15$$4) {
					_15$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _4$$4, "next", &_zephir_call_cache[2]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$4, _4$$4, "valid", &_zephir_call_cache[3]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&modelName, _4$$4, "key", &_zephir_call_cache[4]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&source, _4$$4, "current", &_zephir_call_cache[5]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$7);
					zephir_create_array(&_16$$7, 4, 0);
					add_assoc_stringl_ex(&_16$$7, SL("type"), SL("object"));
					zephir_array_update_string(&_16$$7, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_16$$7, SL("column"), &source, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$7);
					ZEPHIR_INIT_NVAR(&_18$$7);
					ZVAL_STRING(&_18$$7, "\\");
					ZEPHIR_INIT_NVAR(&_19$$7);
					zephir_fast_strpos(&_19$$7, &modelName, &_18$$7, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_19$$7)) {
						ZEPHIR_CPY_WRT(&_17$$7, &modelName);
					} else {
						ZEPHIR_CALL_FUNCTION(&_17$$7, "lcfirst", &_12, 57, &modelName);
						zephir_check_call_status();
					}
					zephir_array_update_string(&_16$$7, SL("balias"), &_17$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_CPY_WRT(&sqlColumn, &_16$$7);
					if (Z_TYPE_P(&eager) != IS_NULL) {
						zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch_string(&_20$$8, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3584);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&sqlColumn, SL("eagerType"), &_20$$8, PH_COPY | PH_SEPARATE);
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
	_21 = zephir_array_isset_value_string(&column, SL("column"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_21))) {
		ZEPHIR_INIT_VAR(&_22$$9);
		object_init_ex(&_22$$9, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$9, "__construct", &_zephir_call_cache[6]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_22$$9, "phalcon/Mvc/Model/Query.zep", 3594);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_LONG(&columnType, 353)) {
		zephir_read_property_cached(&_23$$10, this_ptr, _zephir_prop_1, 1090, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlAliases, &_23$$10);
		zephir_memory_observe(&columnDomain);
		zephir_array_fetch_string(&columnDomain, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3606);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&source);
		_24$$10 = zephir_array_isset_fetch(&source, &sqlAliases, &columnDomain, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_24$$10))) {
			ZEPHIR_INIT_VAR(&_25$$11);
			object_init_ex(&_25$$11, phalcon_mvc_model_query_exceptions_unknownmodeloralias_ce);
			zephir_read_property_cached(&_26$$11, this_ptr, _zephir_prop_2, 1072, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_27$$11);
			ZVAL_STRING(&_27$$11, "2");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$11, "__construct", &_zephir_call_cache[7], &columnDomain, &_27$$11, &_26$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_25$$11, "phalcon/Mvc/Model/Query.zep", 3609);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlColumnAlias, &source);
		zephir_memory_observe(&preparedAlias);
		_28$$10 = zephir_array_isset_string_fetch(&preparedAlias, &column, SL("balias"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_28$$10;
		zephir_read_property_cached(&_23$$10, this_ptr, _zephir_prop_3, 1091, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&sqlAliasesModels, &_23$$10);
		ZEPHIR_OBS_NVAR(&modelName);
		zephir_array_fetch(&modelName, &sqlAliasesModels, &columnDomain, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3623);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&preparedAlias) != IS_STRING) {
			_29$$12 = ZEPHIR_IS_EQUAL(&columnDomain, &modelName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_29$$12) {
				ZEPHIR_INIT_VAR(&_30$$13);
				ZVAL_STRING(&_30$$13, "\\");
				ZEPHIR_INIT_VAR(&_31$$13);
				zephir_fast_strpos(&_31$$13, &modelName, &_30$$13, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_31$$13)) {
					ZEPHIR_CPY_WRT(&preparedAlias, &modelName);
				} else {
					ZEPHIR_CALL_FUNCTION(&preparedAlias, "lcfirst", &_12, 57, &modelName);
					zephir_check_call_status();
				}
			} else {
				ZEPHIR_CPY_WRT(&preparedAlias, &columnDomain);
			}
		}
		ZEPHIR_INIT_VAR(&_32$$10);
		zephir_create_array(&_32$$10, 4, 0);
		add_assoc_stringl_ex(&_32$$10, SL("type"), SL("object"));
		zephir_array_update_string(&_32$$10, SL("model"), &modelName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_32$$10, SL("column"), &sqlColumnAlias, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_32$$10, SL("balias"), &preparedAlias, PH_COPY | PH_SEPARATE);
		ZEPHIR_CPY_WRT(&sqlColumn, &_32$$10);
		if (Z_TYPE_P(&eager) != IS_NULL) {
			zephir_array_update_string(&sqlColumn, SL("eager"), &eager, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch_string(&_33$$15, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3645);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_33$$15, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_INIT_VAR(&_34$$16);
		zephir_create_array(&_34$$16, 1, 0);
		add_assoc_stringl_ex(&_34$$16, SL("type"), SL("scalar"));
		ZEPHIR_CPY_WRT(&sqlColumn, &_34$$16);
		zephir_memory_observe(&columnData);
		zephir_array_fetch_string(&columnData, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3662);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&sqlExprColumn, this_ptr, "getExpression", &_zephir_call_cache[8], &columnData);
		zephir_check_call_status();
		zephir_memory_observe(&balias);
		_35$$16 = zephir_array_isset_string_fetch(&balias, &sqlExprColumn, SL("balias"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_35$$16) {
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
			zephir_array_fetch_string(&_36$$18, &column, SL("eagerType"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Query.zep", 3675);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&sqlColumn, SL("eagerType"), &_36$$18, PH_COPY | PH_SEPARATE);
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
	ZEPHIR_INIT_VAR(&_37);
	object_init_ex(&_37, phalcon_mvc_model_query_exceptions_unknowncolumntype_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_37, "__construct", &_zephir_call_cache[9], &columnType);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_37, "phalcon/Mvc/Model/Query.zep", 3684);
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
	zend_bool _18$$4, _10$$5, _19$$7;
	zend_ulong _8$$4;
	zval _1$$3, _3$$3, _4$$3, _13$$5, _15$$5, _16$$5, _22$$7, _24$$7, _25$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval joinType_zv, *joinSource, joinSource_sub, modelAlias_zv, joinAlias_zv, *relation, relation_sub, fields, referencedFields, sqlJoinConditions, sqlJoinPartialConditions, position, field, referencedField, _0$$3, _2$$3, *_5$$4, _6$$4, *_7$$4, _17$$4, _14$$5, _11$$6, _12$$6, _23$$7, _20$$8, _21$$8;
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
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
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
	ZEPHIR_CALL_METHOD_CACHED(&fields, relation, "getFields", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&referencedFields, relation, "getReferencedFields", &_zephir_call_cache[1]);
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
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "getQualified", &_zephir_call_cache[2], &_3$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_1$$3, SL("left"), &_2$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 3, 0);
		add_assoc_stringl_ex(&_4$$3, SL("type"), SL("qualified"));
		zephir_array_update_string(&_4$$3, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4$$3, SL("name"), &referencedFields, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "getQualified", &_zephir_call_cache[3], &_4$$3);
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
		zephir_is_iterable(_5$$4, 0, "phalcon/Mvc/Model/Query.zep", 3773);
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
				_10$$5 = zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_10$$5))) {
					ZEPHIR_INIT_NVAR(&_11$$6);
					object_init_ex(&_11$$6, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
					zephir_read_property_cached(&_12$$6, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_11$$6, "__construct", &_zephir_call_cache[4], &modelAlias_zv, &joinAlias_zv, &_12$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$6, "phalcon/Mvc/Model/Query.zep", 3746);
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
				ZEPHIR_CALL_METHOD_CACHED(&_14$$5, this_ptr, "getQualified", &_zephir_call_cache[5], &_15$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("left"), &_14$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$5);
				zephir_create_array(&_16$$5, 3, 0);
				add_assoc_stringl_ex(&_16$$5, SL("type"), SL("qualified"));
				zephir_array_update_string(&_16$$5, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_16$$5, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_14$$5, this_ptr, "getQualified", &_zephir_call_cache[6], &_16$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_13$$5, SL("right"), &_14$$5, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlJoinPartialConditions, &_13$$5, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3771);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _5$$4, "rewind", &_zephir_call_cache[7]);
			zephir_check_call_status();
			_18$$4 = 1;
			while (1) {
				if (_18$$4) {
					_18$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _5$$4, "next", &_zephir_call_cache[8]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_17$$4, _5$$4, "valid", &_zephir_call_cache[9]);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&position, _5$$4, "key", &_zephir_call_cache[10]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&field, _5$$4, "current", &_zephir_call_cache[11]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&referencedField);
					_19$$7 = zephir_array_isset_fetch(&referencedField, &referencedFields, &position, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_19$$7))) {
						ZEPHIR_INIT_NVAR(&_20$$8);
						object_init_ex(&_20$$8, phalcon_mvc_model_query_exceptions_joinfieldcountmismatch_ce);
						zephir_read_property_cached(&_21$$8, this_ptr, _zephir_prop_0, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_20$$8, "__construct", &_zephir_call_cache[12], &modelAlias_zv, &joinAlias_zv, &_21$$8);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$8, "phalcon/Mvc/Model/Query.zep", 3746);
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_22$$7);
					zephir_create_array(&_22$$7, 4, 0);
					add_assoc_stringl_ex(&_22$$7, SL("type"), SL("binary-op"));
					add_assoc_stringl_ex(&_22$$7, SL("op"), SL("="));
					ZEPHIR_INIT_NVAR(&_24$$7);
					zephir_create_array(&_24$$7, 3, 0);
					add_assoc_long_ex(&_24$$7, SL("type"), 355);
					zephir_array_update_string(&_24$$7, SL("domain"), &modelAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_24$$7, SL("name"), &field, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_23$$7, this_ptr, "getQualified", &_zephir_call_cache[13], &_24$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_22$$7, SL("left"), &_23$$7, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_25$$7);
					zephir_create_array(&_25$$7, 3, 0);
					add_assoc_stringl_ex(&_25$$7, SL("type"), SL("qualified"));
					zephir_array_update_string(&_25$$7, SL("domain"), &joinAlias_zv, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_25$$7, SL("name"), &referencedField, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD_CACHED(&_23$$7, this_ptr, "getQualified", &_zephir_call_cache[14], &_25$$7);
					zephir_check_call_status();
					zephir_array_update_string(&_22$$7, SL("right"), &_23$$7, PH_COPY | PH_SEPARATE);
					zephir_array_append(&sqlJoinPartialConditions, &_22$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3771);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Mvc/Model/Query.zep", 3798);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&model, manager, "load", &_zephir_call_cache[1], &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[3]);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
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
	if (!intermediate_param || Z_TYPE_P(intermediate_param) == IS_NULL) {
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&transaction, &_0);
	_1 = Z_TYPE_P(&transaction) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(&transaction, phalcon_mvc_model_transactioninterface_ce);
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&transaction, "getConnection", &_zephir_call_cache[0]);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_method_exists_ex(model, ZEND_STRL("selectwriteconnection")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD_CACHED(&connection, model, "selectWriteConnection", &_zephir_call_cache[1], &intermediate, &bindParams, &bindTypes);
		zephir_check_call_status();
		if (UNEXPECTED(Z_TYPE_P(&connection) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			object_init_ex(&_2$$5, phalcon_mvc_model_query_exceptions_writeconnectionmissing_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$5, "__construct", &_zephir_call_cache[2]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_2$$5, "phalcon/Mvc/Model/Query.zep", 3838);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&connection);
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(model, "getWriteConnection", &_zephir_call_cache[3]);
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
	zend_bool _1, _3, _5, _13, _17, _20, _11$$7, _16$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, delete, tables, models, modelsInstances, sqlTables, sqlModels, sqlAliases, sqlAliasesModelsInstances, deleteTables, manager, table, qualifiedName, modelName, model, source, schema, completeSource, alias, sqlDelete, where, limit, _0, *_6, _7, *_8, _12, _2$$3, _4$$4, _9$$8, _10$$9, _14$$13, _15$$14, _18$$17, _19$$17, _21$$18;
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
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$18);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 3862);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	_3 = zephir_array_isset_string_fetch(&tables, &delete, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_model_query_exceptions_corrupteddeleteast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Query.zep", 3866);
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
	_5 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&deleteTables);
		zephir_create_array(&deleteTables, 1, 0);
		zephir_array_fast_append(&deleteTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&deleteTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&deleteTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &deleteTables);
		_6 = &_7;
	} else {
		_6 = &deleteTables;
	}
	zephir_is_iterable(_6, 0, "phalcon/Mvc/Model/Query.zep", 3926);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6), _8)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _8);
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
			ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[2], &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_9$$8);
				zephir_create_array(&_9$$8, 2, 0);
				zephir_array_fast_append(&_9$$8, &source);
				zephir_array_fast_append(&_9$$8, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_9$$8);
			} else {
				ZEPHIR_INIT_NVAR(&_10$$9);
				zephir_create_array(&_10$$9, 2, 0);
				zephir_array_fast_append(&_10$$9, &source);
				zephir_array_fast_append(&_10$$9, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_10$$9);
			}
			ZEPHIR_OBS_NVAR(&alias);
			_11$$7 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_11$$7) {
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _6, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12, _6, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&table, _6, "current", &_zephir_call_cache[8]);
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
				ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[9], &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[10]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[11]);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_14$$13);
					zephir_create_array(&_14$$13, 2, 0);
					zephir_array_fast_append(&_14$$13, &source);
					zephir_array_fast_append(&_14$$13, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_14$$13);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$14);
					zephir_create_array(&_15$$14, 2, 0);
					zephir_array_fast_append(&_15$$14, &source);
					zephir_array_fast_append(&_15$$14, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_15$$14);
				}
				ZEPHIR_OBS_NVAR(&alias);
				_16$$12 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_16$$12) {
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
	_17 = zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_17) {
		ZVAL_BOOL(&_19$$17, 1);
		ZEPHIR_CALL_METHOD_CACHED(&_18$$17, this_ptr, "getExpression", &_zephir_call_cache[12], &where, &_19$$17);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("where"), &_18$$17, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_20 = zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_20) {
		ZEPHIR_CALL_METHOD_CACHED(&_21$$18, this_ptr, "getLimitClause", &_zephir_call_cache[13], &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlDelete, SL("limit"), &_21$$18, PH_COPY | PH_SEPARATE);
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
	zval _12$$7, _18$$8;
	zend_bool notQuoting = 0, _1, _3, _5, _17, _22, _30$$9;
	zval ast, qualifiedName, manager, modelName, model, source, schema, exprValues, exprValue, sqlInsert, metaData, fields, sqlFields, field, name, _0, _8, *_9, _10, *_11, _16, _2$$3, _4$$4, _6$$5, _7$$6, _13$$7, _14$$7, _15$$7, _19$$8, _20$$8, _21$$8, *_23$$9, _24$$9, *_25$$9, _29$$9, _26$$10, _27$$11, _28$$11, _31$$12, _32$$13, _33$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_18$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&ast, &_0);
	_1 = zephir_array_isset_value_string(&ast, SL("qualifiedName"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 3962);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value_string(&ast, SL("values"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Query.zep", 3966);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&qualifiedName);
	zephir_array_fetch_string(&qualifiedName, &ast, SL("qualifiedName"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3969);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_value_string(&qualifiedName, SL("name"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_mvc_model_query_exceptions_corruptedinsertast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$5, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model/Query.zep", 3973);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_memory_observe(&modelName);
	zephir_array_fetch_string(&modelName, &qualifiedName, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3977);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[3], &modelName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[5]);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_create_array(&_7$$6, 2, 0);
		zephir_array_fast_append(&_7$$6, &schema);
		zephir_array_fast_append(&_7$$6, &source);
		ZEPHIR_CPY_WRT(&source, &_7$$6);
	}
	notQuoting = 0;
	ZEPHIR_INIT_VAR(&exprValues);
	array_init(&exprValues);
	zephir_memory_observe(&_8);
	zephir_array_fetch_string(&_8, &ast, SL("values"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3990);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_8) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &_8);
		_9 = &_10;
	} else {
		_9 = &_8;
	}
	zephir_is_iterable(_9, 0, "phalcon/Mvc/Model/Query.zep", 3998);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _11)
		{
			ZEPHIR_INIT_NVAR(&exprValue);
			ZVAL_COPY(&exprValue, _11);
			ZEPHIR_INIT_NVAR(&_12$$7);
			zephir_create_array(&_12$$7, 2, 0);
			ZEPHIR_OBS_NVAR(&_13$$7);
			zephir_array_fetch_string(&_13$$7, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3993);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_12$$7, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_15$$7, 1);
			} else {
				ZVAL_BOOL(&_15$$7, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14$$7, this_ptr, "getExpression", &_zephir_call_cache[6], &exprValue, &_15$$7);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$7, SL("value"), &_14$$7, PH_COPY | PH_SEPARATE);
			zephir_array_append(&exprValues, &_12$$7, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3995);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, _9, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&exprValue, _9, "current", &_zephir_call_cache[10]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$8);
				zephir_create_array(&_18$$8, 2, 0);
				ZEPHIR_OBS_NVAR(&_19$$8);
				zephir_array_fetch_string(&_19$$8, &exprValue, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 3993);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_18$$8, SL("type"), &_19$$8, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_21$$8, 1);
				} else {
					ZVAL_BOOL(&_21$$8, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_20$$8, this_ptr, "getExpression", &_zephir_call_cache[11], &exprValue, &_21$$8);
				zephir_check_call_status();
				zephir_array_update_string(&_18$$8, SL("value"), &_20$$8, PH_COPY | PH_SEPARATE);
				zephir_array_append(&exprValues, &_18$$8, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 3995);
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&metaData, &_0);
	zephir_memory_observe(&fields);
	_22 = zephir_array_isset_string_fetch(&fields, &ast, SL("fields"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_22) {
		ZEPHIR_INIT_VAR(&sqlFields);
		array_init(&sqlFields);
		if (Z_TYPE_P(&fields) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_24$$9);
			zephir_string_to_char_array(&_24$$9, &fields);
			_23$$9 = &_24$$9;
		} else {
			_23$$9 = &fields;
		}
		zephir_is_iterable(_23$$9, 0, "phalcon/Mvc/Model/Query.zep", 4020);
		if (Z_TYPE_P(_23$$9) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_23$$9), _25$$9)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _25$$9);
				ZEPHIR_OBS_NVAR(&name);
				zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4009);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_26$$10, &metaData, "hasAttribute", &_zephir_call_cache[12], &model, &name);
				zephir_check_call_status();
				if (UNEXPECTED(!zephir_is_true(&_26$$10))) {
					ZEPHIR_INIT_NVAR(&_27$$11);
					object_init_ex(&_27$$11, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
					zephir_read_property_cached(&_28$$11, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$11, "__construct", &_zephir_call_cache[13], &modelName, &name, &_28$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_27$$11, "phalcon/Mvc/Model/Query.zep", 4013);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, _23$$9, "rewind", &_zephir_call_cache[14]);
			zephir_check_call_status();
			_30$$9 = 1;
			while (1) {
				if (_30$$9) {
					_30$$9 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _23$$9, "next", &_zephir_call_cache[15]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_29$$9, _23$$9, "valid", &_zephir_call_cache[16]);
				zephir_check_call_status();
				if (!zend_is_true(&_29$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&field, _23$$9, "current", &_zephir_call_cache[17]);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&name);
					zephir_array_fetch_string(&name, &field, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4009);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_31$$12, &metaData, "hasAttribute", &_zephir_call_cache[18], &model, &name);
					zephir_check_call_status();
					if (UNEXPECTED(!zephir_is_true(&_31$$12))) {
						ZEPHIR_INIT_NVAR(&_32$$13);
						object_init_ex(&_32$$13, phalcon_mvc_model_query_exceptions_missingmodelattribute_ce);
						zephir_read_property_cached(&_33$$13, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_32$$13, "__construct", &_zephir_call_cache[19], &modelName, &name, &_33$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_32$$13, "phalcon/Mvc/Model/Query.zep", 4013);
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
	zend_string *_88$$56, *_91$$56, *_94$$56, *_97$$56, *_100$$56, *_103$$56;
	zend_ulong _87$$56, _90$$56, _93$$56, _96$$56, _99$$56, _102$$56;
	zval _25$$24, _38$$29, _63$$45, _76$$50, _118$$76, _125$$83, _136$$91, _143$$98;
	zval models, modelsInstances, sqlAliases, sqlAliasesModels, sqlAliasesModelsInstances, sqlColumns, sqlModels, sqlModelsAliases, sqlTables, _32$$24, _33$$24, _34$$24, _45$$29, _46$$29, _47$$29, _70$$45, _71$$45, _72$$45, _83$$50, _84$$50, _85$$50;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, position = 0, number = 0;
	zend_bool merge, _1, _2, _4, _6, _7, _49, _104, _127, _145, _146, _148, _150, _152, _154, _156, _14$$13, _19$$13, _15$$16, _20$$21, _36$$21, _51$$34, _56$$34, _52$$37, _57$$42, _74$$42, _105$$64, _120$$70, _114$$71, _115$$73, _121$$78, _122$$80, _138$$85, _132$$86, _133$$88, _139$$93, _140$$95;
	zval *ast = NULL, ast_sub, *merge_param = NULL, __$null, __$true, alias, automaticJoins, bestAlias, column, columns, completeSource, distinct, eagerType, groupBy, having, joinAlias, joins, limit, manager, mergeKey, mergeValue, metaData, model, modelName, order, qualifiedName, relation, relationModel, relations, schema, select, selectColumns, selectedModel, selectedModels, source, sqlColumn, sqlColumnAliases, sqlJoins, sqlSelect, tables, where, with, withItem, withs, tempModels, tempModelsInstances, tempSqlAliasesModels, tempSqlAliasesModelsInstances, tempSqlModelsAliases, tempSqlAliases, _8, *_11, _12, *_13, _48, *_107, _108, *_109, _126, _144, _0$$3, _3$$5, _5$$6, _9$$11, _10$$12, _16$$17, _17$$17, _18$$19, *_21$$21, _22$$21, *_23$$21, _35$$21, _24$$24, _26$$25, _27$$27, _28$$27, _29$$28, _30$$28, _31$$26, _37$$29, _39$$30, _40$$32, _41$$32, _42$$33, _43$$33, _44$$31, _50$$35, _53$$38, _54$$38, _55$$40, *_59$$42, _60$$42, *_61$$42, _73$$42, _58$$43, _62$$45, _64$$46, _65$$48, _66$$48, _67$$49, _68$$49, _69$$47, _75$$50, _77$$51, _78$$53, _79$$53, _80$$54, _81$$54, _82$$52, *_86$$56, *_89$$56, *_92$$56, *_95$$56, *_98$$56, *_101$$56, _106$$65, _110$$70, *_111$$70, _112$$70, *_113$$70, _119$$70, _116$$75, _117$$76, _123$$82, _124$$83, _128$$85, *_129$$85, _130$$85, *_131$$85, _137$$85, _134$$90, _135$$91, _141$$97, _142$$98, _147$$102, _149$$103, _151$$104, _153$$105, _155$$106;
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
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_48);
	ZVAL_UNDEF(&_108);
	ZVAL_UNDEF(&_126);
	ZVAL_UNDEF(&_144);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$19);
	ZVAL_UNDEF(&_22$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_24$$24);
	ZVAL_UNDEF(&_26$$25);
	ZVAL_UNDEF(&_27$$27);
	ZVAL_UNDEF(&_28$$27);
	ZVAL_UNDEF(&_29$$28);
	ZVAL_UNDEF(&_30$$28);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_37$$29);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$32);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_55$$40);
	ZVAL_UNDEF(&_60$$42);
	ZVAL_UNDEF(&_73$$42);
	ZVAL_UNDEF(&_58$$43);
	ZVAL_UNDEF(&_62$$45);
	ZVAL_UNDEF(&_64$$46);
	ZVAL_UNDEF(&_65$$48);
	ZVAL_UNDEF(&_66$$48);
	ZVAL_UNDEF(&_67$$49);
	ZVAL_UNDEF(&_68$$49);
	ZVAL_UNDEF(&_69$$47);
	ZVAL_UNDEF(&_75$$50);
	ZVAL_UNDEF(&_77$$51);
	ZVAL_UNDEF(&_78$$53);
	ZVAL_UNDEF(&_79$$53);
	ZVAL_UNDEF(&_80$$54);
	ZVAL_UNDEF(&_81$$54);
	ZVAL_UNDEF(&_82$$52);
	ZVAL_UNDEF(&_106$$65);
	ZVAL_UNDEF(&_110$$70);
	ZVAL_UNDEF(&_112$$70);
	ZVAL_UNDEF(&_119$$70);
	ZVAL_UNDEF(&_116$$75);
	ZVAL_UNDEF(&_117$$76);
	ZVAL_UNDEF(&_123$$82);
	ZVAL_UNDEF(&_124$$83);
	ZVAL_UNDEF(&_128$$85);
	ZVAL_UNDEF(&_130$$85);
	ZVAL_UNDEF(&_137$$85);
	ZVAL_UNDEF(&_134$$90);
	ZVAL_UNDEF(&_135$$91);
	ZVAL_UNDEF(&_141$$97);
	ZVAL_UNDEF(&_142$$98);
	ZVAL_UNDEF(&_147$$102);
	ZVAL_UNDEF(&_149$$103);
	ZVAL_UNDEF(&_151$$104);
	ZVAL_UNDEF(&_153$$105);
	ZVAL_UNDEF(&_155$$106);
	ZVAL_UNDEF(&models);
	ZVAL_UNDEF(&modelsInstances);
	ZVAL_UNDEF(&sqlAliases);
	ZVAL_UNDEF(&sqlAliasesModels);
	ZVAL_UNDEF(&sqlAliasesModelsInstances);
	ZVAL_UNDEF(&sqlColumns);
	ZVAL_UNDEF(&sqlModels);
	ZVAL_UNDEF(&sqlModelsAliases);
	ZVAL_UNDEF(&sqlTables);
	ZVAL_UNDEF(&_32$$24);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_70$$45);
	ZVAL_UNDEF(&_71$$45);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_83$$50);
	ZVAL_UNDEF(&_84$$50);
	ZVAL_UNDEF(&_85$$50);
	ZVAL_UNDEF(&_25$$24);
	ZVAL_UNDEF(&_38$$29);
	ZVAL_UNDEF(&_63$$45);
	ZVAL_UNDEF(&_76$$50);
	ZVAL_UNDEF(&_118$$76);
	ZVAL_UNDEF(&_125$$83);
	ZVAL_UNDEF(&_136$$91);
	ZVAL_UNDEF(&_143$$98);
	ZEND_TLS zephir_method_cache _zephir_call_cache[85];
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "phalcon/Mvc/Model/Query.zep", 4062);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&columns);
	_4 = zephir_array_isset_string_fetch(&columns, &select, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_4))) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_model_query_exceptions_corruptedselectast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$6, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Query.zep", 4066);
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
	_6 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&selectedModels);
		zephir_create_array(&selectedModels, 1, 0);
		zephir_array_fast_append(&selectedModels, &tables);
	} else {
		ZEPHIR_CPY_WRT(&selectedModels, &tables);
	}
	_7 = zephir_array_isset_value_long(&columns, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&selectColumns);
		zephir_create_array(&selectColumns, 1, 0);
		zephir_array_fast_append(&selectColumns, &columns);
	} else {
		ZEPHIR_CPY_WRT(&selectColumns, &columns);
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_8);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 1084, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&metaData, &_8);
	if (UNEXPECTED(Z_TYPE_P(&manager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_9$$11);
		object_init_ex(&_9$$11, phalcon_mvc_model_query_exceptions_missingmodelsmanager_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$11, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$11, "phalcon/Mvc/Model/Query.zep", 4131);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(Z_TYPE_P(&metaData) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_10$$12);
		object_init_ex(&_10$$12, phalcon_mvc_model_query_exceptions_missingmetadata_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_10$$12, "__construct", &_zephir_call_cache[3]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$12, "phalcon/Mvc/Model/Query.zep", 4135);
		ZEPHIR_MM_RESTORE();
		return;
	}
	number = 0;
	ZEPHIR_INIT_VAR(&automaticJoins);
	array_init(&automaticJoins);
	if (Z_TYPE_P(&selectedModels) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_12);
		zephir_string_to_char_array(&_12, &selectedModels);
		_11 = &_12;
	} else {
		_11 = &selectedModels;
	}
	zephir_is_iterable(_11, 0, "phalcon/Mvc/Model/Query.zep", 4278);
	if (Z_TYPE_P(_11) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_11), _13)
		{
			ZEPHIR_INIT_NVAR(&selectedModel);
			ZVAL_COPY(&selectedModel, _13);
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
			ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[4], &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[6]);
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
			_14$$13 = zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_14$$13) {
				_15$$16 = zephir_array_isset_value(&sqlAliases, &alias);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(_15$$16)) {
					ZEPHIR_INIT_NVAR(&_16$$17);
					object_init_ex(&_16$$17, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
					zephir_read_property_cached(&_17$$17, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_16$$17, "__construct", &_zephir_call_cache[7], &alias, &_17$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$17, "phalcon/Mvc/Model/Query.zep", 4167);
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
					ZEPHIR_INIT_NVAR(&_18$$19);
					zephir_create_array(&_18$$19, 3, 0);
					zephir_array_fast_append(&_18$$19, &source);
					zephir_array_fast_append(&_18$$19, &__$null);
					zephir_array_fast_append(&_18$$19, &alias);
					ZEPHIR_CPY_WRT(&completeSource, &_18$$19);
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
			_19$$13 = zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_19$$13) {
				_20$$21 = zephir_array_isset_value_long(&with, 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_20$$21)) {
					ZEPHIR_INIT_NVAR(&withs);
					zephir_create_array(&withs, 1, 0);
					zephir_array_fast_append(&withs, &with);
				} else {
					ZEPHIR_CPY_WRT(&withs, &with);
				}
				if (Z_TYPE_P(&withs) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_22$$21);
					zephir_string_to_char_array(&_22$$21, &withs);
					_21$$21 = &_22$$21;
				} else {
					_21$$21 = &withs;
				}
				zephir_is_iterable(_21$$21, 0, "phalcon/Mvc/Model/Query.zep", 4270);
				if (Z_TYPE_P(_21$$21) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21$$21), _23$$21)
					{
						ZEPHIR_INIT_NVAR(&withItem);
						ZVAL_COPY(&withItem, _23$$21);
						ZEPHIR_INIT_NVAR(&_24$$24);
						ZVAL_LONG(&_24$$24, number);
						ZEPHIR_INIT_NVAR(&_25$$24);
						ZEPHIR_CONCAT_SV(&_25$$24, "AA", &_24$$24);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CPY_WRT(&joinAlias, &_25$$24);
						ZEPHIR_OBS_NVAR(&relationModel);
						zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[8], &modelName, &relationModel);
						zephir_check_call_status();
						if (Z_TYPE_P(&relation) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(&_26$$25);
							ZVAL_STRING(&_26$$25, "alias");
							ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[9], &_26$$25);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[10]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[11]);
							zephir_check_call_status();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[12], &modelName, &relationModel);
							zephir_check_call_status();
							if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
								ZEPHIR_INIT_NVAR(&_27$$27);
								object_init_ex(&_27$$27, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
								zephir_read_property_cached(&_28$$27, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_27$$27, "__construct", &_zephir_call_cache[13], &modelName, &relationModel, &_28$$27);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_27$$27, "phalcon/Mvc/Model/Query.zep", 4228);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
								ZEPHIR_INIT_NVAR(&_29$$28);
								object_init_ex(&_29$$28, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
								zephir_read_property_cached(&_30$$28, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(NULL, &_29$$28, "__construct", &_zephir_call_cache[14], &modelName, &relationModel, &_30$$28);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_29$$28, "phalcon/Mvc/Model/Query.zep", 4235);
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&relation);
							zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_31$$26);
							ZVAL_STRING(&_31$$26, "alias");
							ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[15], &_31$$26);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[16]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[17]);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(&_32$$24);
						zephir_create_array(&_32$$24, 5, 0);
						add_assoc_long_ex(&_32$$24, SL("type"), 353);
						zephir_array_update_string(&_32$$24, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_32$$24, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_32$$24, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_32$$24, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
						zephir_array_append(&selectColumns, &_32$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_33$$24);
						zephir_create_array(&_33$$24, 3, 0);
						add_assoc_long_ex(&_33$$24, SL("type"), 360);
						ZEPHIR_INIT_NVAR(&_34$$24);
						zephir_create_array(&_34$$24, 2, 0);
						add_assoc_long_ex(&_34$$24, SL("type"), 355);
						zephir_array_update_string(&_34$$24, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_33$$24, SL("qualified"), &_34$$24, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_34$$24);
						zephir_create_array(&_34$$24, 2, 0);
						add_assoc_long_ex(&_34$$24, SL("type"), 355);
						zephir_array_update_string(&_34$$24, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&_33$$24, SL("alias"), &_34$$24, PH_COPY | PH_SEPARATE);
						zephir_array_append(&automaticJoins, &_33$$24, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						number++;
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$21, "rewind", &_zephir_call_cache[18]);
					zephir_check_call_status();
					_36$$21 = 1;
					while (1) {
						if (_36$$21) {
							_36$$21 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _21$$21, "next", &_zephir_call_cache[19]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_35$$21, _21$$21, "valid", &_zephir_call_cache[20]);
						zephir_check_call_status();
						if (!zend_is_true(&_35$$21)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&withItem, _21$$21, "current", &_zephir_call_cache[21]);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_37$$29);
							ZVAL_LONG(&_37$$29, number);
							ZEPHIR_INIT_NVAR(&_38$$29);
							ZEPHIR_CONCAT_SV(&_38$$29, "AA", &_37$$29);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&joinAlias, &_38$$29);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[22], &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_39$$30);
								ZVAL_STRING(&_39$$30, "alias");
								ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[23], &_39$$30);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[24]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[25]);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[26], &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_40$$32);
									object_init_ex(&_40$$32, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_41$$32, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_40$$32, "__construct", &_zephir_call_cache[27], &modelName, &relationModel, &_41$$32);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_40$$32, "phalcon/Mvc/Model/Query.zep", 4228);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_42$$33);
									object_init_ex(&_42$$33, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_43$$33, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_42$$33, "__construct", &_zephir_call_cache[28], &modelName, &relationModel, &_43$$33);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_42$$33, "phalcon/Mvc/Model/Query.zep", 4235);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_44$$31);
								ZVAL_STRING(&_44$$31, "alias");
								ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[29], &_44$$31);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[30]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[31]);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_45$$29);
							zephir_create_array(&_45$$29, 5, 0);
							add_assoc_long_ex(&_45$$29, SL("type"), 353);
							zephir_array_update_string(&_45$$29, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_45$$29, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_45$$29, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_45$$29, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_45$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_46$$29);
							zephir_create_array(&_46$$29, 3, 0);
							add_assoc_long_ex(&_46$$29, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_47$$29);
							zephir_create_array(&_47$$29, 2, 0);
							add_assoc_long_ex(&_47$$29, SL("type"), 355);
							zephir_array_update_string(&_47$$29, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_46$$29, SL("qualified"), &_47$$29, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_47$$29);
							zephir_create_array(&_47$$29, 2, 0);
							add_assoc_long_ex(&_47$$29, SL("type"), 355);
							zephir_array_update_string(&_47$$29, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_46$$29, SL("alias"), &_47$$29, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_46$$29, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "rewind", &_zephir_call_cache[32]);
		zephir_check_call_status();
		_49 = 1;
		while (1) {
			if (_49) {
				_49 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _11, "next", &_zephir_call_cache[33]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_48, _11, "valid", &_zephir_call_cache[34]);
			zephir_check_call_status();
			if (!zend_is_true(&_48)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&selectedModel, _11, "current", &_zephir_call_cache[35]);
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
				ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[36], &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[37]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[38]);
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
				_51$$34 = zephir_array_isset_string_fetch(&alias, &selectedModel, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_51$$34) {
					_52$$37 = zephir_array_isset_value(&sqlAliases, &alias);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_52$$37)) {
						ZEPHIR_INIT_NVAR(&_53$$38);
						object_init_ex(&_53$$38, phalcon_mvc_model_query_exceptions_duplicatealias_ce);
						zephir_read_property_cached(&_54$$38, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$38, "__construct", &_zephir_call_cache[39], &alias, &_54$$38);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_53$$38, "phalcon/Mvc/Model/Query.zep", 4167);
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
						ZEPHIR_INIT_NVAR(&_55$$40);
						zephir_create_array(&_55$$40, 3, 0);
						zephir_array_fast_append(&_55$$40, &source);
						zephir_array_fast_append(&_55$$40, &__$null);
						zephir_array_fast_append(&_55$$40, &alias);
						ZEPHIR_CPY_WRT(&completeSource, &_55$$40);
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
				_56$$34 = zephir_array_isset_string_fetch(&with, &selectedModel, SL("with"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_56$$34) {
					_57$$42 = zephir_array_isset_value_long(&with, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_57$$42)) {
						ZEPHIR_INIT_NVAR(&_58$$43);
						zephir_create_array(&_58$$43, 1, 0);
						zephir_array_fast_append(&_58$$43, &with);
						ZEPHIR_CPY_WRT(&withs, &_58$$43);
					} else {
						ZEPHIR_CPY_WRT(&withs, &with);
					}
					if (Z_TYPE_P(&withs) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_60$$42);
						zephir_string_to_char_array(&_60$$42, &withs);
						_59$$42 = &_60$$42;
					} else {
						_59$$42 = &withs;
					}
					zephir_is_iterable(_59$$42, 0, "phalcon/Mvc/Model/Query.zep", 4270);
					if (Z_TYPE_P(_59$$42) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_59$$42), _61$$42)
						{
							ZEPHIR_INIT_NVAR(&withItem);
							ZVAL_COPY(&withItem, _61$$42);
							ZEPHIR_INIT_NVAR(&_62$$45);
							ZVAL_LONG(&_62$$45, number);
							ZEPHIR_INIT_NVAR(&_63$$45);
							ZEPHIR_CONCAT_SV(&_63$$45, "AA", &_62$$45);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CPY_WRT(&joinAlias, &_63$$45);
							ZEPHIR_OBS_NVAR(&relationModel);
							zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[40], &modelName, &relationModel);
							zephir_check_call_status();
							if (Z_TYPE_P(&relation) == IS_OBJECT) {
								ZEPHIR_INIT_NVAR(&_64$$46);
								ZVAL_STRING(&_64$$46, "alias");
								ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[41], &_64$$46);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[42]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[43]);
								zephir_check_call_status();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[44], &modelName, &relationModel);
								zephir_check_call_status();
								if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
									ZEPHIR_INIT_NVAR(&_65$$48);
									object_init_ex(&_65$$48, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
									zephir_read_property_cached(&_66$$48, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_65$$48, "__construct", &_zephir_call_cache[45], &modelName, &relationModel, &_66$$48);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_65$$48, "phalcon/Mvc/Model/Query.zep", 4228);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
									ZEPHIR_INIT_NVAR(&_67$$49);
									object_init_ex(&_67$$49, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
									zephir_read_property_cached(&_68$$49, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_CALL_METHOD_CACHED(NULL, &_67$$49, "__construct", &_zephir_call_cache[46], &modelName, &relationModel, &_68$$49);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_67$$49, "phalcon/Mvc/Model/Query.zep", 4235);
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_OBS_NVAR(&relation);
								zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_INIT_NVAR(&_69$$47);
								ZVAL_STRING(&_69$$47, "alias");
								ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[47], &_69$$47);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[48]);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[49]);
								zephir_check_call_status();
							}
							ZEPHIR_INIT_NVAR(&_70$$45);
							zephir_create_array(&_70$$45, 5, 0);
							add_assoc_long_ex(&_70$$45, SL("type"), 353);
							zephir_array_update_string(&_70$$45, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_70$$45, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_70$$45, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_70$$45, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
							zephir_array_append(&selectColumns, &_70$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_INIT_NVAR(&_71$$45);
							zephir_create_array(&_71$$45, 3, 0);
							add_assoc_long_ex(&_71$$45, SL("type"), 360);
							ZEPHIR_INIT_NVAR(&_72$$45);
							zephir_create_array(&_72$$45, 2, 0);
							add_assoc_long_ex(&_72$$45, SL("type"), 355);
							zephir_array_update_string(&_72$$45, SL("name"), &relationModel, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_71$$45, SL("qualified"), &_72$$45, PH_COPY | PH_SEPARATE);
							ZEPHIR_INIT_NVAR(&_72$$45);
							zephir_create_array(&_72$$45, 2, 0);
							add_assoc_long_ex(&_72$$45, SL("type"), 355);
							zephir_array_update_string(&_72$$45, SL("name"), &joinAlias, PH_COPY | PH_SEPARATE);
							zephir_array_update_string(&_71$$45, SL("alias"), &_72$$45, PH_COPY | PH_SEPARATE);
							zephir_array_append(&automaticJoins, &_71$$45, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							number++;
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _59$$42, "rewind", &_zephir_call_cache[50]);
						zephir_check_call_status();
						_74$$42 = 1;
						while (1) {
							if (_74$$42) {
								_74$$42 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _59$$42, "next", &_zephir_call_cache[51]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_73$$42, _59$$42, "valid", &_zephir_call_cache[52]);
							zephir_check_call_status();
							if (!zend_is_true(&_73$$42)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&withItem, _59$$42, "current", &_zephir_call_cache[53]);
							zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_75$$50);
								ZVAL_LONG(&_75$$50, number);
								ZEPHIR_INIT_NVAR(&_76$$50);
								ZEPHIR_CONCAT_SV(&_76$$50, "AA", &_75$$50);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CPY_WRT(&joinAlias, &_76$$50);
								ZEPHIR_OBS_NVAR(&relationModel);
								zephir_array_fetch_string(&relationModel, &withItem, SL("name"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4205);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								ZEPHIR_CALL_METHOD_CACHED(&relation, &manager, "getRelationByAlias", &_zephir_call_cache[54], &modelName, &relationModel);
								zephir_check_call_status();
								if (Z_TYPE_P(&relation) == IS_OBJECT) {
									ZEPHIR_INIT_NVAR(&_77$$51);
									ZVAL_STRING(&_77$$51, "alias");
									ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[55], &_77$$51);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[56]);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[57]);
									zephir_check_call_status();
								} else {
									ZEPHIR_CALL_METHOD_CACHED(&relations, &manager, "getRelationsBetween", &_zephir_call_cache[58], &modelName, &relationModel);
									zephir_check_call_status();
									if (UNEXPECTED(Z_TYPE_P(&relations) != IS_ARRAY)) {
										ZEPHIR_INIT_NVAR(&_78$$53);
										object_init_ex(&_78$$53, phalcon_mvc_model_query_exceptions_relationshipnotfound_ce);
										zephir_read_property_cached(&_79$$53, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_78$$53, "__construct", &_zephir_call_cache[59], &modelName, &relationModel, &_79$$53);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_78$$53, "phalcon/Mvc/Model/Query.zep", 4228);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (UNEXPECTED(zephir_fast_count_int(&relations) != 1)) {
										ZEPHIR_INIT_NVAR(&_80$$54);
										object_init_ex(&_80$$54, phalcon_mvc_model_query_exceptions_ambiguousjoinrelation_ce);
										zephir_read_property_cached(&_81$$54, this_ptr, _zephir_prop_3, 1072, PH_NOISY_CC | PH_READONLY);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										ZEPHIR_CALL_METHOD_CACHED(NULL, &_80$$54, "__construct", &_zephir_call_cache[60], &modelName, &relationModel, &_81$$54);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_80$$54, "phalcon/Mvc/Model/Query.zep", 4235);
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_OBS_NVAR(&relation);
									zephir_array_fetch_long(&relation, &relations, 0, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4241);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									ZEPHIR_INIT_NVAR(&_82$$52);
									ZVAL_STRING(&_82$$52, "alias");
									ZEPHIR_CALL_METHOD_CACHED(&bestAlias, &relation, "getOption", &_zephir_call_cache[61], &_82$$52);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&relationModel, &relation, "getReferencedModel", &_zephir_call_cache[62]);
									zephir_check_call_status();
									ZEPHIR_CALL_METHOD_CACHED(&eagerType, &relation, "getType", &_zephir_call_cache[63]);
									zephir_check_call_status();
								}
								ZEPHIR_INIT_NVAR(&_83$$50);
								zephir_create_array(&_83$$50, 5, 0);
								add_assoc_long_ex(&_83$$50, SL("type"), 353);
								zephir_array_update_string(&_83$$50, SL("column"), &joinAlias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("eager"), &alias, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("eagerType"), &eagerType, PH_COPY | PH_SEPARATE);
								zephir_array_update_string(&_83$$50, SL("balias"), &bestAlias, PH_COPY | PH_SEPARATE);
								zephir_array_append(&selectColumns, &_83$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4254);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
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
								zephir_array_append(&automaticJoins, &_84$$50, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4266);
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
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&tempModelsInstances);
		zephir_read_property_cached(&tempModelsInstances, this_ptr, _zephir_prop_5, 1088, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&tempSqlAliases);
		zephir_read_property_cached(&tempSqlAliases, this_ptr, _zephir_prop_6, 1090, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModels);
		zephir_read_property_cached(&tempSqlAliasesModels, this_ptr, _zephir_prop_7, 1091, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&tempSqlModelsAliases);
		zephir_read_property_cached(&tempSqlModelsAliases, this_ptr, _zephir_prop_8, 1092, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&tempSqlAliasesModelsInstances);
		zephir_read_property_cached(&tempSqlAliasesModelsInstances, this_ptr, _zephir_prop_9, 1093, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_is_iterable(&models, 0, "phalcon/Mvc/Model/Query.zep", 4302);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&modelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4306);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliases, 0, "phalcon/Mvc/Model/Query.zep", 4310);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModels, 0, "phalcon/Mvc/Model/Query.zep", 4314);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlModelsAliases, 0, "phalcon/Mvc/Model/Query.zep", 4318);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
		zephir_is_iterable(&sqlAliasesModelsInstances, 0, "phalcon/Mvc/Model/Query.zep", 4321);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&mergeValue);
		ZEPHIR_INIT_NVAR(&mergeKey);
	}
	zephir_memory_observe(&joins);
	_104 = zephir_array_isset_string_fetch(&joins, &select, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_104;
	if (!(ZEPHIR_IS_EMPTY(&joins))) {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			_105$$64 = zephir_array_isset_value_long(&joins, 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_105$$64) {
				ZEPHIR_INIT_VAR(&_106$$65);
				zephir_fast_array_merge(&_106$$65, &joins, &automaticJoins);
				zephir_array_update_string(&select, SL("joins"), &_106$$65, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD_CACHED(&sqlJoins, this_ptr, "getJoins", &_zephir_call_cache[64], &select);
		zephir_check_call_status();
	} else {
		if (!(ZEPHIR_IS_EMPTY(&automaticJoins))) {
			zephir_array_update_string(&select, SL("joins"), &automaticJoins, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&sqlJoins, this_ptr, "getJoins", &_zephir_call_cache[65], &select);
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
		ZEPHIR_INIT_VAR(&_108);
		zephir_string_to_char_array(&_108, &selectColumns);
		_107 = &_108;
	} else {
		_107 = &selectColumns;
	}
	zephir_is_iterable(_107, 0, "phalcon/Mvc/Model/Query.zep", 4382);
	if (Z_TYPE_P(_107) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_107), _109)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _109);
			ZEPHIR_CALL_METHOD_CACHED(&_110$$70, this_ptr, "getSelectColumn", &_zephir_call_cache[66], &column);
			zephir_check_call_status();
			if (Z_TYPE_P(&_110$$70) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_112$$70);
				zephir_string_to_char_array(&_112$$70, &_110$$70);
				_111$$70 = &_112$$70;
			} else {
				_111$$70 = &_110$$70;
			}
			zephir_is_iterable(_111$$70, 0, "phalcon/Mvc/Model/Query.zep", 4380);
			if (Z_TYPE_P(_111$$70) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_111$$70), _113$$70)
				{
					ZEPHIR_INIT_NVAR(&sqlColumn);
					ZVAL_COPY(&sqlColumn, _113$$70);
					ZEPHIR_OBS_NVAR(&alias);
					_114$$71 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_114$$71) {
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
						_115$$73 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_115$$73) {
							zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_OBS_NVAR(&_116$$75);
							zephir_array_fetch_string(&_116$$75, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (ZEPHIR_IS_STRING(&_116$$75, "scalar")) {
								ZEPHIR_INIT_NVAR(&_117$$76);
								ZVAL_LONG(&_117$$76, position);
								ZEPHIR_INIT_NVAR(&_118$$76);
								ZEPHIR_CONCAT_SV(&_118$$76, "_", &_117$$76);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&sqlColumns, &_118$$76, &sqlColumn, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$70, "rewind", &_zephir_call_cache[67]);
				zephir_check_call_status();
				_120$$70 = 1;
				while (1) {
					if (_120$$70) {
						_120$$70 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _111$$70, "next", &_zephir_call_cache[68]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_119$$70, _111$$70, "valid", &_zephir_call_cache[69]);
					zephir_check_call_status();
					if (!zend_is_true(&_119$$70)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&sqlColumn, _111$$70, "current", &_zephir_call_cache[70]);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&alias);
						_121$$78 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_121$$78) {
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
							_122$$80 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_122$$80) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_123$$82);
								zephir_array_fetch_string(&_123$$82, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (ZEPHIR_IS_STRING(&_123$$82, "scalar")) {
									ZEPHIR_INIT_NVAR(&_124$$83);
									ZVAL_LONG(&_124$$83, position);
									ZEPHIR_INIT_NVAR(&_125$$83);
									ZEPHIR_CONCAT_SV(&_125$$83, "_", &_124$$83);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&sqlColumns, &_125$$83, &sqlColumn, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _107, "rewind", &_zephir_call_cache[71]);
		zephir_check_call_status();
		_127 = 1;
		while (1) {
			if (_127) {
				_127 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _107, "next", &_zephir_call_cache[72]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_126, _107, "valid", &_zephir_call_cache[73]);
			zephir_check_call_status();
			if (!zend_is_true(&_126)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, _107, "current", &_zephir_call_cache[74]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_128$$85, this_ptr, "getSelectColumn", &_zephir_call_cache[75], &column);
				zephir_check_call_status();
				if (Z_TYPE_P(&_128$$85) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_130$$85);
					zephir_string_to_char_array(&_130$$85, &_128$$85);
					_129$$85 = &_130$$85;
				} else {
					_129$$85 = &_128$$85;
				}
				zephir_is_iterable(_129$$85, 0, "phalcon/Mvc/Model/Query.zep", 4380);
				if (Z_TYPE_P(_129$$85) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_129$$85), _131$$85)
					{
						ZEPHIR_INIT_NVAR(&sqlColumn);
						ZVAL_COPY(&sqlColumn, _131$$85);
						ZEPHIR_OBS_NVAR(&alias);
						_132$$86 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_132$$86) {
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
							_133$$88 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_133$$88) {
								zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_OBS_NVAR(&_134$$90);
								zephir_array_fetch_string(&_134$$90, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (ZEPHIR_IS_STRING(&_134$$90, "scalar")) {
									ZEPHIR_INIT_NVAR(&_135$$91);
									ZVAL_LONG(&_135$$91, position);
									ZEPHIR_INIT_NVAR(&_136$$91);
									ZEPHIR_CONCAT_SV(&_136$$91, "_", &_135$$91);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&sqlColumns, &_136$$91, &sqlColumn, PH_COPY | PH_SEPARATE);
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
					ZEPHIR_CALL_METHOD_CACHED(NULL, _129$$85, "rewind", &_zephir_call_cache[76]);
					zephir_check_call_status();
					_138$$85 = 1;
					while (1) {
						if (_138$$85) {
							_138$$85 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _129$$85, "next", &_zephir_call_cache[77]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_137$$85, _129$$85, "valid", &_zephir_call_cache[78]);
						zephir_check_call_status();
						if (!zend_is_true(&_137$$85)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&sqlColumn, _129$$85, "current", &_zephir_call_cache[79]);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&alias);
							_139$$93 = zephir_array_isset_string_fetch(&alias, &column, SL("alias"), 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_139$$93) {
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
								_140$$95 = zephir_array_isset_string_fetch(&alias, &sqlColumn, SL("balias"), 0);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (_140$$95) {
									zephir_array_update_zval(&sqlColumns, &alias, &sqlColumn, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								} else {
									ZEPHIR_OBS_NVAR(&_141$$97);
									zephir_array_fetch_string(&_141$$97, &sqlColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4370);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (ZEPHIR_IS_STRING(&_141$$97, "scalar")) {
										ZEPHIR_INIT_NVAR(&_142$$98);
										ZVAL_LONG(&_142$$98, position);
										ZEPHIR_INIT_NVAR(&_143$$98);
										ZEPHIR_CONCAT_SV(&_143$$98, "_", &_142$$98);
										if (UNEXPECTED(EG(exception))) {
											ZEPHIR_MM_RESTORE();
											return;
										}
										zephir_array_update_zval(&sqlColumns, &_143$$98, &sqlColumn, PH_COPY | PH_SEPARATE);
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
	zephir_memory_observe(&_144);
	zephir_read_property_cached(&_144, this_ptr, _zephir_prop_10, 1094, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("sqlColumnAliases"), &_144, &sqlColumnAliases);
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
	_145 = zephir_array_isset_string_fetch(&distinct, &select, SL("distinct"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_145) {
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
	_146 = zephir_array_isset_string_fetch(&where, ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_146) {
		ZEPHIR_CALL_METHOD_CACHED(&_147$$102, this_ptr, "getExpression", &_zephir_call_cache[80], &where);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("where"), &_147$$102, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&groupBy);
	_148 = zephir_array_isset_string_fetch(&groupBy, ast, SL("groupBy"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_148) {
		ZEPHIR_CALL_METHOD_CACHED(&_149$$103, this_ptr, "getGroupClause", &_zephir_call_cache[81], &groupBy);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("group"), &_149$$103, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&having);
	_150 = zephir_array_isset_string_fetch(&having, ast, SL("having"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_150) {
		ZEPHIR_CALL_METHOD_CACHED(&_151$$104, this_ptr, "getExpression", &_zephir_call_cache[82], &having);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("having"), &_151$$104, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&order);
	_152 = zephir_array_isset_string_fetch(&order, ast, SL("orderBy"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_152) {
		ZEPHIR_CALL_METHOD_CACHED(&_153$$105, this_ptr, "getOrderClause", &_zephir_call_cache[83], &order);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("order"), &_153$$105, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_154 = zephir_array_isset_string_fetch(&limit, ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_154) {
		ZEPHIR_CALL_METHOD_CACHED(&_155$$106, this_ptr, "getLimitClause", &_zephir_call_cache[84], &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlSelect, SL("limit"), &_155$$106, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_156 = zephir_array_isset_value_string(ast, SL("forUpdate"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_156) {
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
	zval _27$$21, _36$$22;
	zend_bool notQuoting = 0, _1, _3, _5, _7, _15, _19, _20, _32, _40, _43, _13$$8, _18$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, ast, update, tables, values, modelsInstances, models, sqlTables, sqlAliases, sqlAliasesModels, sqlModelsAliases, sqlAliasesModelsInstances, updateTables, completeSource, sqlModels, manager, table, qualifiedName, modelName, model, source, schema, alias, joins, sqlJoins, sqlFields, sqlValues, updateValues, updateValue, exprColumn, sqlUpdate, where, limit, _0, *_8, _9, *_10, _14, *_21, _22, *_23, _31, _2$$3, _4$$4, _6$$5, _11$$9, _12$$10, _16$$14, _17$$15, _24$$21, _25$$21, _26$$21, _28$$21, _29$$21, _30$$21, _33$$22, _34$$22, _35$$22, _37$$22, _38$$22, _39$$22, _41$$24, _42$$24, _44$$25;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$15);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$21);
	ZVAL_UNDEF(&_26$$21);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_42$$24);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_36$$22);
	ZEND_TLS zephir_method_cache _zephir_call_cache[24];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Mvc/Model/Query.zep", 4462);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&tables);
	_3 = zephir_array_isset_string_fetch(&tables, &update, SL("tables"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_4$$4, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Mvc/Model/Query.zep", 4466);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&values);
	_5 = zephir_array_isset_string_fetch(&values, &update, SL("values"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, phalcon_mvc_model_query_exceptions_corruptedupdateast_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$5, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$5, "phalcon/Mvc/Model/Query.zep", 4470);
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
	_7 = zephir_array_isset_value_long(&tables, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		ZEPHIR_INIT_VAR(&updateTables);
		zephir_create_array(&updateTables, 1, 0);
		zephir_array_fast_append(&updateTables, &tables);
	} else {
		ZEPHIR_CPY_WRT(&updateTables, &tables);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1083, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&updateTables) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &updateTables);
		_8 = &_9;
	} else {
		_8 = &updateTables;
	}
	zephir_is_iterable(_8, 0, "phalcon/Mvc/Model/Query.zep", 4542);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _10)
		{
			ZEPHIR_INIT_NVAR(&table);
			ZVAL_COPY(&table, _10);
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
			ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[3], &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&completeSource);
			if (zephir_is_true(&schema)) {
				ZEPHIR_INIT_NVAR(&_11$$9);
				zephir_create_array(&_11$$9, 2, 0);
				zephir_array_fast_append(&_11$$9, &source);
				zephir_array_fast_append(&_11$$9, &schema);
				ZEPHIR_CPY_WRT(&completeSource, &_11$$9);
			} else {
				ZEPHIR_INIT_NVAR(&_12$$10);
				zephir_create_array(&_12$$10, 2, 0);
				zephir_array_fast_append(&_12$$10, &source);
				zephir_array_fast_append(&_12$$10, &__$null);
				ZEPHIR_CPY_WRT(&completeSource, &_12$$10);
			}
			ZEPHIR_OBS_NVAR(&alias);
			_13$$8 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_13$$8) {
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "rewind", &_zephir_call_cache[6]);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "next", &_zephir_call_cache[7]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14, _8, "valid", &_zephir_call_cache[8]);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&table, _8, "current", &_zephir_call_cache[9]);
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
				ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[10], &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[11]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[12]);
				zephir_check_call_status();
				if (zephir_is_true(&schema)) {
					ZEPHIR_INIT_NVAR(&_16$$14);
					zephir_create_array(&_16$$14, 2, 0);
					zephir_array_fast_append(&_16$$14, &source);
					zephir_array_fast_append(&_16$$14, &schema);
					ZEPHIR_CPY_WRT(&completeSource, &_16$$14);
				} else {
					ZEPHIR_INIT_NVAR(&_17$$15);
					zephir_create_array(&_17$$15, 2, 0);
					zephir_array_fast_append(&_17$$15, &source);
					zephir_array_fast_append(&_17$$15, &__$null);
					ZEPHIR_CPY_WRT(&completeSource, &_17$$15);
				}
				ZEPHIR_OBS_NVAR(&alias);
				_18$$13 = zephir_array_isset_string_fetch(&alias, &table, SL("alias"), 0);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_18$$13) {
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
	_19 = zephir_array_isset_string_fetch(&joins, &update, SL("joins"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_19) {
		ZEPHIR_CALL_METHOD_CACHED(&sqlJoins, this_ptr, "getJoins", &_zephir_call_cache[13], &update);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&sqlFields);
	array_init(&sqlFields);
	ZEPHIR_INIT_VAR(&sqlValues);
	array_init(&sqlValues);
	_20 = zephir_array_isset_value_long(&values, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_20)) {
		ZEPHIR_INIT_VAR(&updateValues);
		zephir_create_array(&updateValues, 1, 0);
		zephir_array_fast_append(&updateValues, &values);
	} else {
		ZEPHIR_CPY_WRT(&updateValues, &values);
	}
	notQuoting = 0;
	if (Z_TYPE_P(&updateValues) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_22);
		zephir_string_to_char_array(&_22, &updateValues);
		_21 = &_22;
	} else {
		_21 = &updateValues;
	}
	zephir_is_iterable(_21, 0, "phalcon/Mvc/Model/Query.zep", 4581);
	if (Z_TYPE_P(_21) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_21), _23)
		{
			ZEPHIR_INIT_NVAR(&updateValue);
			ZVAL_COPY(&updateValue, _23);
			ZEPHIR_OBS_NVAR(&_25$$21);
			zephir_array_fetch_string(&_25$$21, &updateValue, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4573);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (notQuoting) {
				ZVAL_BOOL(&_26$$21, 1);
			} else {
				ZVAL_BOOL(&_26$$21, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24$$21, this_ptr, "getExpression", &_zephir_call_cache[14], &_25$$21, &_26$$21);
			zephir_check_call_status();
			zephir_array_append(&sqlFields, &_24$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4573);
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
			ZEPHIR_INIT_NVAR(&_27$$21);
			zephir_create_array(&_27$$21, 2, 0);
			ZEPHIR_OBS_NVAR(&_28$$21);
			zephir_array_fetch_string(&_28$$21, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4576);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_27$$21, SL("type"), &_28$$21, PH_COPY | PH_SEPARATE);
			if (notQuoting) {
				ZVAL_BOOL(&_30$$21, 1);
			} else {
				ZVAL_BOOL(&_30$$21, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29$$21, this_ptr, "getExpression", &_zephir_call_cache[15], &exprColumn, &_30$$21);
			zephir_check_call_status();
			zephir_array_update_string(&_27$$21, SL("value"), &_29$$21, PH_COPY | PH_SEPARATE);
			zephir_array_append(&sqlValues, &_27$$21, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4578);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _21, "rewind", &_zephir_call_cache[16]);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _21, "next", &_zephir_call_cache[17]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_31, _21, "valid", &_zephir_call_cache[18]);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&updateValue, _21, "current", &_zephir_call_cache[19]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_34$$22);
				zephir_array_fetch_string(&_34$$22, &updateValue, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4573);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (notQuoting) {
					ZVAL_BOOL(&_35$$22, 1);
				} else {
					ZVAL_BOOL(&_35$$22, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_33$$22, this_ptr, "getExpression", &_zephir_call_cache[20], &_34$$22, &_35$$22);
				zephir_check_call_status();
				zephir_array_append(&sqlFields, &_33$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4573);
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
				ZEPHIR_INIT_NVAR(&_36$$22);
				zephir_create_array(&_36$$22, 2, 0);
				ZEPHIR_OBS_NVAR(&_37$$22);
				zephir_array_fetch_string(&_37$$22, &exprColumn, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4576);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_36$$22, SL("type"), &_37$$22, PH_COPY | PH_SEPARATE);
				if (notQuoting) {
					ZVAL_BOOL(&_39$$22, 1);
				} else {
					ZVAL_BOOL(&_39$$22, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_38$$22, this_ptr, "getExpression", &_zephir_call_cache[21], &exprColumn, &_39$$22);
				zephir_check_call_status();
				zephir_array_update_string(&_36$$22, SL("value"), &_38$$22, PH_COPY | PH_SEPARATE);
				zephir_array_append(&sqlValues, &_36$$22, PH_SEPARATE, "phalcon/Mvc/Model/Query.zep", 4578);
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
	_40 = zephir_array_isset_string_fetch(&where, &ast, SL("where"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_40) {
		ZVAL_BOOL(&_42$$24, 1);
		ZEPHIR_CALL_METHOD_CACHED(&_41$$24, this_ptr, "getExpression", &_zephir_call_cache[22], &where, &_42$$24);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("where"), &_41$$24, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_memory_observe(&limit);
	_43 = zephir_array_isset_string_fetch(&limit, &ast, SL("limit"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_43) {
		ZEPHIR_CALL_METHOD_CACHED(&_44$$25, this_ptr, "getLimitClause", &_zephir_call_cache[23], &limit);
		zephir_check_call_status();
		zephir_array_update_string(&sqlUpdate, SL("limit"), &_44$$25, PH_COPY | PH_SEPARATE);
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
	zend_bool _1, _2, _15, _8$$6, _9$$6, _10$$6, _16$$15, _17$$15, _18$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *irPhql_param = NULL, __$null, manager, models, tables, modelName, model, schema, source, currentTable, alias, index, _0, *_3, _4, *_5, _14;
	zval irPhql, _11$$10, _12$$11, _13$$13, _19$$19, _20$$20, _21$$22;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&irPhql);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_19$$19);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_21$$22);
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
	ZVAL_UNDEF(&_14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[11];
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
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
			ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[0], &modelName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[1]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[2]);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&currentTable);
			zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4640);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_NULL(&alias);
			_9$$6 = Z_TYPE_P(&currentTable) == IS_ARRAY;
			if (_9$$6) {
				_10$$6 = zephir_array_isset_value_long(&currentTable, 2);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_9$$6 = _10$$6;
			}
			if (_9$$6) {
				ZEPHIR_OBS_NVAR(&alias);
				zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4650);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_is_true(&schema)) {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_11$$10);
					zephir_create_array(&_11$$10, 3, 0);
					zephir_array_fast_append(&_11$$10, &source);
					zephir_array_fast_append(&_11$$10, &schema);
					zephir_array_fast_append(&_11$$10, &alias);
					zephir_array_update_zval(&tables, &index, &_11$$10, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_12$$11);
					zephir_create_array(&_12$$11, 2, 0);
					zephir_array_fast_append(&_12$$11, &source);
					zephir_array_fast_append(&_12$$11, &schema);
					zephir_array_update_zval(&tables, &index, &_12$$11, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				if (Z_TYPE_P(&alias) != IS_NULL) {
					ZEPHIR_INIT_NVAR(&_13$$13);
					zephir_create_array(&_13$$13, 3, 0);
					zephir_array_fast_append(&_13$$13, &source);
					zephir_array_fast_append(&_13$$13, &__$null);
					zephir_array_fast_append(&_13$$13, &alias);
					zephir_array_update_zval(&tables, &index, &_13$$13, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14, _3, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, _3, "key", &_zephir_call_cache[6]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&modelName, _3, "current", &_zephir_call_cache[7]);
			zephir_check_call_status();
				_16$$15 = zephir_array_isset_value(&tables, &index);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_16$$15)) {
					continue;
				}
				ZEPHIR_CALL_METHOD_CACHED(&model, &manager, "load", &_zephir_call_cache[8], &modelName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&schema, &model, "getSchema", &_zephir_call_cache[9]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&source, &model, "getSource", &_zephir_call_cache[10]);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&currentTable);
				zephir_array_fetch(&currentTable, &tables, &index, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4640);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&alias);
				ZVAL_NULL(&alias);
				_17$$15 = Z_TYPE_P(&currentTable) == IS_ARRAY;
				if (_17$$15) {
					_18$$15 = zephir_array_isset_value_long(&currentTable, 2);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_17$$15 = _18$$15;
				}
				if (_17$$15) {
					ZEPHIR_OBS_NVAR(&alias);
					zephir_array_fetch_long(&alias, &currentTable, 2, PH_NOISY, "phalcon/Mvc/Model/Query.zep", 4650);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_is_true(&schema)) {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_19$$19);
						zephir_create_array(&_19$$19, 3, 0);
						zephir_array_fast_append(&_19$$19, &source);
						zephir_array_fast_append(&_19$$19, &schema);
						zephir_array_fast_append(&_19$$19, &alias);
						zephir_array_update_zval(&tables, &index, &_19$$19, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_20$$20);
						zephir_create_array(&_20$$20, 2, 0);
						zephir_array_fast_append(&_20$$20, &source);
						zephir_array_fast_append(&_20$$20, &schema);
						zephir_array_update_zval(&tables, &index, &_20$$20, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (Z_TYPE_P(&alias) != IS_NULL) {
						ZEPHIR_INIT_NVAR(&_21$$22);
						zephir_create_array(&_21$$22, 3, 0);
						zephir_array_fast_append(&_21$$22, &source);
						zephir_array_fast_append(&_21$$22, &__$null);
						zephir_array_fast_append(&_21$$22, &alias);
						zephir_array_update_zval(&tables, &index, &_21$$22, PH_COPY | PH_SEPARATE);
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

