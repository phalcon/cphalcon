
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
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Storage\Adapter\Memory
 *
 * Memory adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Memory, phalcon, storage_adapter_memory, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_memory_method_entry, 0);

	/**
	 * @var Collection
	 */
	zend_declare_property_null(phalcon_storage_adapter_memory_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_memory_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_storage_adapter_memory_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Memory;
	return SUCCESS;

}

/**
 * Constructor
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZVAL_STRING(&_0, "ph-memo-");
	zephir_update_property_zval(this_ptr, SL("prefix"), &_0);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, phalcon_collection_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 11);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("data"), &_0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_memory_ce, getThis(), "__construct", &_1, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, clear) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, current, newValue, prefixedKey, result, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&newValue);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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


	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "has", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	if (zephir_is_true(&result)) {
		zephir_read_property(&_1$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&current, &_1$$3, "get", NULL, 0, &prefixedKey);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&newValue);
		ZVAL_LONG(&newValue, (zephir_get_intval(&current) - value));
		ZEPHIR_CPY_WRT(&result, &newValue);
		zephir_read_property(&_2$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "set", NULL, 0, &prefixedKey, &newValue);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * Reads data from the adapter
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, exists, prefixedKey, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&exists, &_0, "has", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "remove", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	RETURN_CCTOR(&exists);

}

/**
 * Reads data from the adapter
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, content, prefixedKey, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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


	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&content, &_0, "get", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &content, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the already connected adapter or connects to the Memcached
 * server(s)
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, getAdapter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, getKeys) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_keys(return_value, &_1 TSRMLS_CC);
	RETURN_MM();

}

/**
 * Checks if an element exists in the cache
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, prefixedKey, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "has", NULL, 0, &prefixedKey);
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
PHP_METHOD(Phalcon_Storage_Adapter_Memory, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL, current, newValue, prefixedKey, result, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&newValue);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &value_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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


	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&result, &_0, "has", NULL, 0, &prefixedKey);
	zephir_check_call_status();
	if (zephir_is_true(&result)) {
		zephir_read_property(&_1$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&current, &_1$$3, "get", NULL, 0, &prefixedKey);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&newValue);
		ZVAL_LONG(&newValue, (zephir_get_intval(&current) + value));
		ZEPHIR_CPY_WRT(&result, &newValue);
		zephir_read_property(&_2$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "set", NULL, 0, &prefixedKey, &newValue);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

/**
 * Stores data in the adapter
 *
 * @param string $key
 * @param mixed  $value
 * @param null   $ttl
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Memory, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$null, content, lifetime, prefixedKey, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&lifetime);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &ttl);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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


	ZEPHIR_CALL_METHOD(&content, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&lifetime, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefixedKey, this_ptr, "getprefixedkey", NULL, 0, &key);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &prefixedKey, &content);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Memory(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

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
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

