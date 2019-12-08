
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Apcu, phalcon, storage_adapter_apcu, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_apcu_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_apcu_ce, SL("options"), ZEND_ACC_PROTECTED);

	phalcon_storage_adapter_apcu_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Apcu;
	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval options;
	zval *factory = NULL, factory_sub, *options_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &factory, &options_param);

	if (!factory) {
		factory = &factory_sub;
		factory = &__$null;
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "ph-apcu-");
	zephir_update_property_zval(this_ptr, SL("prefix"), &_0);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_apcu_ce, getThis(), "__construct", &_1, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, clear) {

	zend_object_iterator *_2;
	zend_class_entry *_1 = NULL;
	zend_bool result = 0;
	zval item, pattern, apc, _0, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&apc);
	ZVAL_NULL(&apc);
	zephir_read_property(&_0, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_SVS(&pattern, "/^", &_0, "/");
	ZEPHIR_INIT_NVAR(&apc);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("APCuIterator"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&apc, _1);
	if (zephir_has_constructor(&apc)) {
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &pattern);
		zephir_check_call_status();
	}
	result = 1;
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	_2 = zephir_get_iterator(&apc);
	_2->funcs->rewind(_2);
	for (;_2->funcs->valid(_2) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _2);
		}
		zephir_array_fetch_string(&_3$$4, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Apcu.zep", 62);
		ZEPHIR_CALL_FUNCTION(&_4$$4, "apcu_delete", NULL, 0, &_3$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4$$4))) {
			result = 0;
		}
	}
	zend_iterator_dtor(_2);
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
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, decrement) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_dec", NULL, 0, &_0, &_1);
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
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

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
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_delete", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reads data from the adapter
 *
 * @param string $key
 * @param null   $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, content, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "apcu_fetch", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &content, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Always returns null
 *
 * @return null
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, getAdapter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, getKeys) {

	zend_object_iterator *_2;
	zend_class_entry *_1 = NULL;
	zval results;
	zval item, pattern, apc, _0, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&results);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&apc);
	ZVAL_NULL(&apc);
	zephir_read_property(&_0, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_SVS(&pattern, "/^", &_0, "/");
	ZEPHIR_INIT_NVAR(&apc);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("APCuIterator"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&apc, _1);
	if (zephir_has_constructor(&apc)) {
		ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &pattern);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	if (Z_TYPE_P(&apc) != IS_OBJECT) {
		RETURN_CTOR(&results);
	}
	_2 = zephir_get_iterator(&apc);
	_2->funcs->rewind(_2);
	for (;_2->funcs->valid(_2) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _2);
		}
		zephir_array_fetch_string(&_3$$4, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/Storage/Adapter/Apcu.zep", 141);
		zephir_array_append(&results, &_3$$4, PH_SEPARATE, "phalcon/Storage/Adapter/Apcu.zep", 141);
	}
	zend_iterator_dtor(_2);
	RETURN_CTOR(&results);

}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

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
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, increment) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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
		ZVAL_EMPTY_STRING(&key);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_inc", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores data in the adapter
 *
 * @param string $key
 * @param mixed  $value
 * @param null   $ttl
 *
 * @return bool
 * @throws \Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Apcu, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$null, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

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
		ZVAL_EMPTY_STRING(&key);
	}
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_store", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Apcu(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

