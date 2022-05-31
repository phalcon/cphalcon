
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/iterator.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Apcu adapter
 *
 * @property array $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Apcu)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Apcu, phalcon, storage_adapter_apcu, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_apcu_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_apcu_ce, SL("prefix"), "ph-apcu-", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Apcu constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options
 *
 * @throws SupportException
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options;
	zval *factory, factory_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_apcu_ce, getThis(), "__construct", &_0, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, clear)
{
	zend_object_iterator *_1;
	zend_bool result = 0;
	zval item, pattern, apc, _0, _2$$4, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&apc);
	ZVAL_NULL(&apc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_SVS(&pattern, "/^", &_0, "/");
	ZEPHIR_CALL_METHOD(&apc, this_ptr, "phpapcuiterator", NULL, 0, &pattern);
	zephir_check_call_status();
	result = 1;
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_get_iterator(&apc);
	_1->funcs->rewind(_1);
	for (;_1->funcs->valid(_1) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _1);
		}
		zephir_array_fetch_string(&_3$$4, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Apcu.zep", 63);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "phpapcudelete", &_4, 0, &_3$$4);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_2$$4)) {
			result = 0;
		}
	}
	zend_iterator_dtor(_1);
	RETURN_MM_BOOL(result);
}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, decrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpapcudec", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reads data from the adapter
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpapcudelete", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_boolval(&_0));
}

/**
 * Stores data in the adapter
 *
 * @param string $prefix
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, getKeys)
{
	zend_object_iterator *_1;
	zval results;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, item, pattern, apc, _0, _2$$4;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&results);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(prefix_param) != IS_STRING && Z_TYPE_P(prefix_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'prefix' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(prefix_param) == IS_STRING)) {
		zephir_get_strval(&prefix, prefix_param);
	} else {
		ZEPHIR_INIT_VAR(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&apc);
	ZVAL_NULL(&apc);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_SVVS(&pattern, "/^", &_0, &prefix, "/");
	ZEPHIR_CALL_METHOD(&apc, this_ptr, "phpapcuiterator", NULL, 0, &pattern);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		RETURN_CTOR(&results);
	}
	_1 = zephir_get_iterator(&apc);
	_1->funcs->rewind(_1);
	for (;_1->funcs->valid(_1) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _1);
		}
		zephir_array_fetch_string(&_2$$4, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Apcu.zep", 117);
		zephir_array_append(&results, &_2$$4, PH_SEPARATE, "phalcon/Storage/Adapter/Apcu.zep", 117);
	}
	zend_iterator_dtor(_1);
	RETURN_CTOR(&results);
}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, has)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, result, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpapcuexists", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_1, &result);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	RETURN_CCTOR(&_1);
}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, increment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpapcuinc", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores data in the adapter. If the TTL is `null` (default) or not defined
 * then the default TTL will be used, as set in this adapter. If the TTL
 * is `0` or a negative number, a `delete()` will be issued, since this
 * item has expired. If you need to set this key forever, you should use
 * the `setForever()` method.
 *
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, set)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$null, result, _1, _2, _3, _4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &ttl);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}


	_0 = Z_TYPE_P(ttl) == IS_LONG;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(ttl, 1);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "delete", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpapcustore", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE) == 1)) {
		ZEPHIR_CPY_WRT(&_4, &result);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	RETURN_CCTOR(&_4);
}

/**
 * Stores data in the adapter forever. The key needs to manually deleted
 * from the adapter.
 *
 * @param string $key
 * @param mixed  $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, setForever)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, result, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "phpapcustore", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	if ((Z_TYPE_P(&result) == IS_TRUE || Z_TYPE_P(&result) == IS_FALSE)) {
		ZEPHIR_CPY_WRT(&_2, &result);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	RETURN_CCTOR(&_2);
}

/**
 * @param string $key
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, doGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpapcufetch", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo Remove the below once we get traits
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuDec)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long step, ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *step_param = NULL, *success = NULL, success_sub, *ttl_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&success_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
		Z_PARAM_ZVAL_OR_NULL(success)
		Z_PARAM_LONG(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key, &step_param, &success, &ttl_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}
	if (!success) {
		success = &success_sub;
		success = &__$null;
	}
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	ZVAL_LONG(&_0, step);
	ZVAL_LONG(&_1, ttl);
	ZEPHIR_MAKE_REF(success);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_dec", NULL, 98, key, &_0, success, &_1);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_RETURN_CALL_FUNCTION("apcu_delete", NULL, 99, key);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);


	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 100, key);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuInc)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long step, ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *step_param = NULL, *success = NULL, success_sub, *ttl_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&success_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(step)
		Z_PARAM_ZVAL_OR_NULL(success)
		Z_PARAM_LONG(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key, &step_param, &success, &ttl_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}
	if (!success) {
		success = &success_sub;
		success = &__$null;
	}
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	ZVAL_LONG(&_0, step);
	ZVAL_LONG(&_1, ttl);
	ZEPHIR_MAKE_REF(success);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_inc", NULL, 101, key, &_0, success, &_1);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuFetch)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *success = NULL, success_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&success_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(success)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key, &success);
	if (!success) {
		success = &success_sub;
		success = &__$null;
	}


	ZEPHIR_MAKE_REF(success);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_fetch", NULL, 102, key, success);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuIterator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);
	zephir_get_strval(&pattern, pattern_param);


	object_init_ex(return_value, zephir_get_internal_ce(SL("apcuiterator")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &pattern);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Apcu, phpApcuStore)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ttl, ZEPHIR_LAST_CALL_STATUS;
	zval *key, key_sub, *payload, payload_sub, *ttl_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(key)
		Z_PARAM_ZVAL(payload)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(ttl)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &payload, &ttl_param);
	if (!ttl_param) {
		ttl = 0;
	} else {
		ttl = zephir_get_intval(ttl_param);
	}


	ZVAL_LONG(&_0, ttl);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_store", NULL, 103, key, payload, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

