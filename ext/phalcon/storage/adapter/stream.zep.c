
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/time.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Storage\Adapter\Stream
 *
 * Stream adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Stream) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Stream, phalcon, storage_adapter_stream, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_stream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_stream_ce, SL("cacheDir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_stream_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_storage_adapter_stream_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Stream;
	return SUCCESS;

}

/**
 * Stream constructor.
 *
 * @param array $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL;
	zval options;
	zval *factory = NULL, factory_sub, *options_param = NULL, __$null, cacheDir, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cacheDir);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
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


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cacheDir");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_CE_STATIC(&cacheDir, phalcon_helper_arr_ce, "get", &_0, 5, &options, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&cacheDir)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "The 'cacheDir' must be specified in the options", "phalcon/Storage/Adapter/Stream.zep", 50);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_helper_str_ce, "dirseparator", &_4, 96, &cacheDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("cacheDir"), &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "phstrm-");
	zephir_update_property_zval(this_ptr, SL("prefix"), &_1);
	zephir_update_property_zval(this_ptr, SL("options"), &options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_stream_ce, getThis(), "__construct", &_5, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, clear) {

	zend_bool result = 0, _6$$3;
	zval directory, iterator, file, _1, _2, *_3, _4$$3, _7$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL, *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();

	result = 1;
	zephir_read_property(&_1, this_ptr, SL("cacheDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&directory, phalcon_helper_str_ce, "dirseparator", &_0, 96, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &directory, "/*");
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "rglob", NULL, 97, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 82);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _3)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "is_dir", &_5, 98, &file);
		zephir_check_call_status();
		_6$$3 = !zephir_is_true(&_4$$3);
		if (_6$$3) {
			ZEPHIR_CALL_FUNCTION(&_7$$3, "unlink", &_8, 99, &file);
			zephir_check_call_status();
			_6$$3 = !zephir_is_true(&_7$$3);
		}
		if (_6$$3) {
			result = 0;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_BOOL(result);

}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 * @throws \Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS, _1;
	zval *key_param = NULL, *value_param = NULL, data, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) - value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &key, &data);
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
PHP_METHOD(Phalcon_Storage_Adapter_Stream, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, directory, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&directory);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 100, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &directory, &key);
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 99, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reads data from the adapter
 *
 * @param string $key
 * @param null   $defaultValue
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, get) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$true, __$null, content, directory, payload, _0, _1, _2, _3, _4, _6;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);

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


	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 100, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VV(&_0, &directory, &key);
	if (!((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &directory, &key);
	ZEPHIR_INIT_VAR(&payload);
	zephir_file_get_contents(&payload, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_json_decode(&_2, &payload, zephir_get_intval(&__$true) );
	ZEPHIR_CPY_WRT(&payload, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 101);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_3, 0)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "isexpired", NULL, 102, &payload);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZVAL_NULL(&_6);
	ZEPHIR_CALL_CE_STATIC(&content, phalcon_helper_arr_ce, "get", &_5, 5, &payload, &_2, &_6);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &content, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the already connected adapter or connects to the Memcached
 * server(s)
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getAdapter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeys) {

	zval directory, iterator, file, split, results, _1, _2, *_3, _4$$3, _6$$4, _7$$4, _9$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL, *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	zephir_read_property(&_1, this_ptr, SL("cacheDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&directory, phalcon_helper_str_ce, "dirseparator", &_0, 96, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &directory, "/*");
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "rglob", NULL, 97, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 189);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _3)
	{
		ZEPHIR_INIT_NVAR(&file);
		ZVAL_COPY(&file, _3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "is_dir", &_5, 98, &file);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4$$3))) {
			ZEPHIR_INIT_NVAR(&split);
			zephir_fast_explode_str(&split, SL("/"), &file, LONG_MAX TSRMLS_CC);
			zephir_read_property(&_6$$4, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_CE_STATIC(&_7$$4, phalcon_helper_arr_ce, "last", &_8, 103, &split);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9$$4);
			ZEPHIR_CONCAT_VV(&_9$$4, &_6$$4, &_7$$4);
			zephir_array_append(&results, &_9$$4, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 185);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&file);
	RETURN_CCTOR(&results);

}

/**
 * Checks if an element exists in the cache and is not expired
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, directory, exists, payload, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

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


	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 100, &key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VV(&_0, &directory, &key);
	ZEPHIR_INIT_VAR(&exists);
	ZVAL_BOOL(&exists, (zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS));
	if (!(zephir_is_true(&exists))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &directory, &key);
	ZEPHIR_INIT_VAR(&payload);
	zephir_file_get_contents(&payload, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_json_decode(&_2, &payload, 0 );
	ZEPHIR_CPY_WRT(&payload, &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "isexpired", NULL, 102, &payload);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_3));

}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
 * @throws \Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS, _1;
	zval *key_param = NULL, *value_param = NULL, data, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) + value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &key, &data);
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
PHP_METHOD(Phalcon_Storage_Adapter_Stream, set) {

	zval payload;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$true, __$null, directory, _0, _1, _3, _4, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&payload);

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


	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	zephir_array_update_string(&payload, SL("created"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("ttl"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_json_encode(&_0, &payload, 0 );
	ZEPHIR_CPY_WRT(&payload, &_0);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 100, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 98, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZVAL_LONG(&_2$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 104, &directory, &_2$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &directory, &key);
	zephir_file_put_contents(&_3, &_4, &payload TSRMLS_CC);
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_3));

}

/**
 * Returns the folder based on the cacheDir and the prefix
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDir) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	zval *key_param = NULL, dirPrefix, dirFromFile, _0, _1, _3, _5;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&dirPrefix);
	ZVAL_UNDEF(&dirFromFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
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
	}


	zephir_read_property(&_0, this_ptr, SL("cacheDir"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&dirPrefix);
	ZEPHIR_CONCAT_VV(&dirPrefix, &_0, &_1);
	ZEPHIR_CALL_CE_STATIC(&dirFromFile, phalcon_helper_str_ce, "dirfromfile", &_2, 105, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_helper_str_ce, "dirseparator", &_4, 96, &dirPrefix);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_helper_str_ce, "dirseparator", &_4, 96, &dirFromFile);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_3, &_5);
	RETURN_MM();

}

/**
 * Returns if the cache has expired for this item or not
 *
 * @param array $payload
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, isExpired) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *payload_param = NULL, created, ttl, _1, _2, _3, _4;
	zval payload;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&created);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &payload_param);

	ZEPHIR_OBS_COPY_OR_DUP(&payload, payload_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "created");
	ZEPHIR_CALL_CE_STATIC(&created, phalcon_helper_arr_ce, "get", &_0, 5, &payload, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ttl");
	ZVAL_LONG(&_3, 3600);
	ZEPHIR_CALL_CE_STATIC(&ttl, phalcon_helper_arr_ce, "get", &_0, 5, &payload, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_add_function(&_4, &created, &ttl);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_time(&_2);
	RETURN_MM_BOOL(ZEPHIR_LT(&_4, &_2));

}

/**
 * @param string $pattern
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, rglob) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, dir, dirName, files, flags, recurse, _0, _1, *_2, _3$$3, _4$$3, _6$$3;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&dirName);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&flags);
	ZVAL_UNDEF(&recurse);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pattern_param);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "dirname", NULL, 106, &pattern);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dirName);
	ZEPHIR_CONCAT_VS(&dirName, &_0, "/*");
	ZEPHIR_CALL_FUNCTION(&files, "glob", NULL, 107, &pattern);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&flags);
	ZVAL_LONG(&flags, (8192 | 4));
	ZEPHIR_CALL_FUNCTION(&_1, "glob", NULL, 107, &dirName, &flags);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "phalcon/Storage/Adapter/Stream.zep", 322);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&dir);
		ZVAL_COPY(&dir, _2);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_basename(&_3$$3, &pattern TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_VSV(&_4$$3, &dir, "/", &_3$$3);
		ZEPHIR_CPY_WRT(&dir, &_4$$3);
		ZEPHIR_CALL_METHOD(&recurse, this_ptr, "rglob", &_5, 97, &dir);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_fast_array_merge(&_6$$3, &files, &recurse TSRMLS_CC);
		ZEPHIR_CPY_WRT(&files, &_6$$3);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&dir);
	RETURN_CCTOR(&files);

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Stream(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
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

