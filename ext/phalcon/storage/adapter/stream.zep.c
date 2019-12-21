
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
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "ext/spl/spl_iterators.h"
#include "ext/spl/spl_directory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Stream adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Stream) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Stream, phalcon, storage_adapter_stream, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_stream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_stream_ce, SL("storageDir"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_storage_adapter_stream_ce, SL("options"), ZEND_ACC_PROTECTED);

	phalcon_storage_adapter_stream_ce->create_object = zephir_init_properties_Phalcon_Storage_Adapter_Stream;
	return SUCCESS;

}

/**
 * Stream constructor.
 *
 * @param array options = [
 *     'storageDir' => '',
 *     'defaultSerializer' => 'Php',
 *     'lifetime' => 3600,
 *     'serializer' => null,
 *     'prefix' => ''
 * ]
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL, *_5 = NULL;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, storageDir, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&storageDir);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "storageDir");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_CE_STATIC(&storageDir, phalcon_helper_arr_ce, "get", &_0, 15, &options, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&storageDir)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "The 'storageDir' must be specified in the options", "phalcon/Storage/Adapter/Stream.zep", 57);
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_helper_str_ce, "dirseparator", &_4, 122, &storageDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("storageDir"), &_3);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ph-strm");
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

	zend_bool result = 0, _5$$3, _10$$5;
	zval directory, iterator, file, _1, *_2, _3, _4$$3, _6$$3, _7$$3, _9$$5, _11$$5, _12$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();

	result = 1;
	zephir_read_property(&_1, this_ptr, SL("storageDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&directory, phalcon_helper_str_ce, "dirseparator", &_0, 122, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 123, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 90);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _2)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _2);
			ZEPHIR_CALL_METHOD(&_4$$3, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			_5$$3 = zephir_is_true(&_4$$3);
			if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_6$$3, &file, "getpathname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$3, "unlink", &_8, 124, &_6$$3);
				zephir_check_call_status();
				_5$$3 = !zephir_is_true(&_7$$3);
			}
			if (_5$$3) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$5, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				_10$$5 = zephir_is_true(&_9$$5);
				if (_10$$5) {
					ZEPHIR_CALL_METHOD(&_11$$5, &file, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_12$$5, "unlink", &_8, 124, &_11$$5);
					zephir_check_call_status();
					_10$$5 = !zephir_is_true(&_12$$5);
				}
				if (_10$$5) {
					result = 0;
				}
			ZEPHIR_CALL_METHOD(NULL, &iterator, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, filepath, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&filepath);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 125, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 124, &filepath);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, content, filepath, payload, _0, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

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


	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 125, &key);
	zephir_check_call_status();
	if (!((zephir_file_exists(&filepath) == SUCCESS))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 126, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&payload))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isexpired", NULL, 127, &payload);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZVAL_NULL(&_3);
	ZEPHIR_CALL_CE_STATIC(&content, phalcon_helper_arr_ce, "get", &_1, 15, &payload, &_2, &_3);
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
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getAdapter) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "adapter");

}

/**
 * Stores data in the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeys) {

	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, directory, file, iterator, *_0, _1, _2$$3, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _11$$4, _12$$4, _13$$5, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6, _21$$6, _22$$6;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&files);

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
		ZVAL_EMPTY_STRING(&prefix);
	}
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 128);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 123, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 203);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$3)) {
				zephir_read_property(&_3$$4, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CALL_METHOD(&_6$$4, &file, "getpathname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_STRING(&_7$$4, "");
				zephir_fast_str_replace(&_5$$4, &directory, &_7$$4, &_6$$4);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_STRING(&_8$$4, "/");
				ZEPHIR_CALL_FUNCTION(&_9$$4, "strrchr", &_10, 129, &_5$$4, &_8$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_STRING(&_8$$4, "/");
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, "");
				zephir_fast_str_replace(&_4$$4, &_8$$4, &_11$$4, &_9$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZEPHIR_CONCAT_VV(&_12$$4, &_3$$4, &_4$$4);
				zephir_array_append(&files, &_12$$4, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 199);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$5, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_13$$5)) {
					zephir_read_property(&_14$$6, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_NVAR(&_15$$6);
					ZEPHIR_INIT_NVAR(&_16$$6);
					ZEPHIR_CALL_METHOD(&_17$$6, &file, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$6);
					ZVAL_STRING(&_18$$6, "");
					zephir_fast_str_replace(&_16$$6, &directory, &_18$$6, &_17$$6);
					ZEPHIR_INIT_NVAR(&_19$$6);
					ZVAL_STRING(&_19$$6, "/");
					ZEPHIR_CALL_FUNCTION(&_20$$6, "strrchr", &_10, 129, &_16$$6, &_19$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_19$$6);
					ZVAL_STRING(&_19$$6, "/");
					ZEPHIR_INIT_NVAR(&_21$$6);
					ZVAL_STRING(&_21$$6, "");
					zephir_fast_str_replace(&_15$$6, &_19$$6, &_21$$6, &_20$$6);
					ZEPHIR_INIT_NVAR(&_22$$6);
					ZEPHIR_CONCAT_VV(&_22$$6, &_14$$6, &_15$$6);
					zephir_array_append(&files, &_22$$6, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 199);
				}
			ZEPHIR_CALL_METHOD(NULL, &iterator, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilteredkeys", NULL, 0, &files, &prefix);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks if an element exists in the cache and is not expired
 *
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, payload, filepath, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&filepath);
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


	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 125, &key);
	zephir_check_call_status();
	if (!((zephir_file_exists(&filepath) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 126, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&payload))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isexpired", NULL, 127, &payload);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));

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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
 * @throws \Exception
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, set) {

	zval payload;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *ttl = NULL, ttl_sub, __$true, __$null, directory, _0, _1, _2, _4, _3$$3;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&payload);

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


	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 3, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	zephir_array_update_string(&payload, SL("created"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("ttl"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_1, "serialize", NULL, 12, &payload);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&payload, &_1);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 128, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", NULL, 130, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZVAL_LONG(&_3$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 131, &directory, &_3$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &directory, &key);
	zephir_file_put_contents(&_0, &_4, &payload);
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_0));

}

/**
 * Returns the folder based on the storageDir and the prefix
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *key_param = NULL, dirFromFile, dirPrefix, _1, _2, _3, _5, _6, _7, _8;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&dirFromFile);
	ZVAL_UNDEF(&dirPrefix);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
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
	}


	zephir_read_property(&_1, this_ptr, SL("storageDir"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_1, &_2);
	ZEPHIR_CALL_CE_STATIC(&dirPrefix, phalcon_helper_str_ce, "dirseparator", &_0, 122, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "");
	zephir_fast_str_replace(&_5, &_6, &_7, &key);
	ZEPHIR_CALL_CE_STATIC(&dirFromFile, phalcon_helper_str_ce, "dirfromfile", &_4, 132, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_CONCAT_VV(&_8, &dirPrefix, &dirFromFile);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_helper_str_ce, "dirseparator", &_0, 122, &_8);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the full path to the file
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getFilepath) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, _2, _3, _4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdir", NULL, 128, &key);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZVAL_LONG(&_3, 1);
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_CALL_FUNCTION(&_4, "str_replace", NULL, 133, &_1, &_2, &key, &_3);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_4);
	RETURN_MM();

}

/**
 * Returns an iterator for the directory contents
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getIterator) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, _0, _1;
	zval dir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	if (UNEXPECTED(Z_TYPE_P(dir_param) != IS_STRING && Z_TYPE_P(dir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'dir' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(dir_param) == IS_STRING)) {
		zephir_get_strval(&dir, dir_param);
	} else {
		ZEPHIR_INIT_VAR(&dir);
		ZVAL_EMPTY_STRING(&dir);
	}


	object_init_ex(return_value, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_RecursiveDirectoryIterator);
	ZVAL_LONG(&_1, 4096);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 134, &dir, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 135, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the file contents and returns an array or an error if something
 * went wrong
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getPayload) {

	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filepath_param = NULL, __$false, payload, _0, _1, _2;
	zval filepath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filepath);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filepath_param);

	zephir_get_strval(&filepath, filepath_param);


	ZEPHIR_INIT_VAR(&payload);
	zephir_file_get_contents(&payload, &filepath);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&payload)) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_1__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 84, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "unserialize", NULL, 14, &payload);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&payload, &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 86);
	zephir_check_call_status();
	_3 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_3)) {
		_3 = Z_TYPE_P(&payload) != IS_ARRAY;
	}
	if (UNEXPECTED(_3)) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CCTOR(&payload);

}

/**
 * Returns if the cache has expired for this item or not
 *
 * @param array $payload
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, isExpired) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_CALL_CE_STATIC(&created, phalcon_helper_arr_ce, "get", &_0, 15, &payload, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ttl");
	ZVAL_LONG(&_3, 3600);
	ZEPHIR_CALL_CE_STATIC(&ttl, phalcon_helper_arr_ce, "get", &_0, 15, &payload, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_add_function(&_4, &created, &ttl);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_time(&_2);
	RETURN_MM_BOOL(ZEPHIR_LT(&_4, &_2));

}

zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Stream(zend_class_entry *class_type TSRMLS_DC) {

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

