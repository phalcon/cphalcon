
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "ext/spl/spl_iterators.h"
#include "ext/spl/spl_directory.h"
#include "kernel/string.h"
#include "kernel/file.h"


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
 *
 * Capabilities:
 * - Counters: read-modify-write (doHas()/doGet()/doSet()); not atomic and racy
 *   across concurrent processes.
 * - getKeys(): recursive directory traversal; cost grows with the entry count.
 * - Serializers: Phalcon-side only.
 *
 * @phpstan-type TOptions array{
 *     storageDir?: string,
 *     defaultSerializer?: string,
 *     lifetime?: int,
 *     prefix?: string
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Stream, phalcon, storage_adapter_stream, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_stream_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "ph-strm", sizeof("ph-strm") - 1);
		zephir_declare_typed_property(phalcon_storage_adapter_stream_ce, SL("prefix"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_storage_adapter_stream_ce, SL("storageDir"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Stream constructor.
 *
 * @param TOptions          $options
 *
 * @throws InvalidConfiguration
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, storageDir, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&storageDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("storageDir", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(factory, phalcon_storage_serializerfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &factory, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "storageDir");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&storageDir, this_ptr, "getarrval", NULL, 0, &options, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&storageDir)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exceptions_invalidconfiguration_ce, "The 'storageDir' must be specified in the options", "phalcon/Storage/Adapter/Stream.zep", 64);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "todirseparator", NULL, 0, &storageDir);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 322, &_2);
	ZEPHIR_CALL_PARENT(NULL, phalcon_storage_adapter_stream_ce, getThis(), "__construct", NULL, 0, factory, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initserializer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Flushes/clears the cache
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, clear)
{
	zend_bool result = 0, _8, _3$$4, _10$$6;
	zval directory, iterator, file, _0, *_1, _7, _2$$4, _4$$4, _5$$4, _9$$6, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	result = 1;
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 286);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &directory);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(result);
	}
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 287, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 100);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			_3$$4 = ZEPHIR_IS_TRUE_IDENTICAL(&_2$$4);
			if (_3$$4) {
				ZEPHIR_CALL_METHOD(&_5$$4, &file, "getpathname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "phpunlink", &_6, 0, &_5$$4);
				zephir_check_call_status();
				_3$$4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_4$$4);
			}
			if (UNEXPECTED(_3$$4)) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &iterator, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_9$$6, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				_10$$6 = ZEPHIR_IS_TRUE_IDENTICAL(&_9$$6);
				if (_10$$6) {
					ZEPHIR_CALL_METHOD(&_12$$6, &file, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_11$$6, this_ptr, "phpunlink", &_6, 0, &_12$$6);
					zephir_check_call_status();
					_10$$6 = !ZEPHIR_IS_TRUE_IDENTICAL(&_11$$6);
				}
				if (UNEXPECTED(_10$$6)) {
					result = 0;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_BOOL(result);
}

/**
 * Stores data in the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeys)
{
	zend_bool _7;
	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, directory, file, iterator, _0, *_1, _6, _2$$4, _3$$5, _4$$5, _5$$5, _8$$6, _9$$7, _10$$7, _11$$7;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&files);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&prefix_zv);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
		zephir_memory_observe(&prefix_zv);
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 286);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &directory);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 287, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 126);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_CALL_METHOD(&_2$$4, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_2$$4)) {
				zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 323, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_4$$5, &file, "getfilename", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_CONCAT_VV(&_5$$5, &_3$$5, &_4$$5);
				zephir_array_append(&files, &_5$$5, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 122);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &iterator, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_8$$6)) {
					zephir_read_property_cached(&_9$$7, this_ptr, _zephir_prop_0, 323, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_10$$7, &file, "getfilename", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZEPHIR_CONCAT_VV(&_11$$7, &_9$$7, &_10$$7);
					zephir_array_append(&files, &_11$$7, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 122);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfilteredkeys", NULL, 0, &files, &prefix_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Stores data in the adapter forever. The key needs to manually deleted
 * from the adapter.
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, setForever)
{
	zval payload;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *data, data_sub, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&payload);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 3, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	zephir_array_update_string(&payload, SL("created"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&payload, SL("ttl"), SL("forever"));
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, data);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "storepayload", NULL, 288, &payload, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decrements a stored number
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doDecrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS, _1;
	zval key_zv, *value_param = NULL, data, result, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "dohas", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "doget", NULL, 0, &key_zv);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) - value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "doset", NULL, 0, &key_zv, &data);
	zephir_check_call_status();
	if (EXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&result))) {
		ZEPHIR_CPY_WRT(&result, &data);
	}
	RETURN_CCTOR(&result);
}

/**
 * Deletes data from the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doDelete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, filepath, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "dohas", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 289, &key_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpunlink", NULL, 0, &filepath);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reads data from the adapter
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doGet)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, content, filepath, payload, _0, _2, _3;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 289, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &filepath);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 290, &filepath);
	zephir_check_call_status();
	_1 = ZEPHIR_IS_EMPTY(&payload);
	if (!(_1)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "isexpired", NULL, 291, &payload);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "content");
	ZEPHIR_CALL_METHOD(&content, this_ptr, "getarrval", NULL, 0, &payload, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &content, defaultValue);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks if an element exists in the cache and is not expired
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doHas)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, payload, filepath, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 289, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 290, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&payload))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isexpired", NULL, 291, &payload);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_1));
}

/**
 * Increments a stored number
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doIncrement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long value, ZEPHIR_LAST_CALL_STATUS, _1;
	zval key_zv, *value_param = NULL, data, result, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "dohas", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "doget", NULL, 0, &key_zv);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) + value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "doset", NULL, 0, &key_zv, &data);
	zephir_check_call_status();
	if (EXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&result))) {
		ZEPHIR_CPY_WRT(&result, &data);
	}
	RETURN_CCTOR(&result);
}

/**
 * Stores data in the adapter. If the TTL is `null` (default) or not defined
 * then the default TTL will be used, as set in this adapter. If the TTL
 * is `0` or a negative number, a `delete()` will be issued, since this
 * item has expired. If you need to set this key forever, you should use
 * the `setForever()` method.
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doSet)
{
	zend_bool _0;
	zval payload;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, *ttl = NULL, ttl_sub, __$null, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&ttl_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&payload);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(ttl)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		ttl = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!ttl) {
		ttl = &ttl_sub;
		ttl = &__$null;
	}
	_0 = Z_TYPE_P(ttl) == IS_LONG;
	if (_0) {
		_0 = ZEPHIR_LT_LONG(ttl, 1);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "delete", NULL, 0, &key_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 3, 0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	zephir_array_update_string(&payload, SL("created"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getttl", NULL, 0, ttl);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("ttl"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("content"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "storepayload", NULL, 288, &payload, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the folder based on the storageDir and the prefix
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, dirFromFile, dirPrefix, _0, _1, _2, _3, _4, _5;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&dirFromFile);
	ZVAL_UNDEF(&dirPrefix);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("storageDir", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!key) {
		key = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&key_zv);
		ZVAL_STR(&key_zv, key);
	} else {
		zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 322, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 323, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	ZEPHIR_CALL_METHOD(&dirPrefix, this_ptr, "todirseparator", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getkeywithoutprefix", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(&dirFromFile, this_ptr, "todirfromfile", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VV(&_5, &dirPrefix, &dirFromFile);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "todirseparator", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the full path to the file
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getFilepath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdir", NULL, 286, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkeywithoutprefix", NULL, 0, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	RETURN_MM();
}

/**
 * Returns an iterator for the directory contents
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getIterator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval dir_zv, _0, _1;
	zend_string *dir = NULL;

	ZVAL_UNDEF(&dir_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(dir)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&dir_zv);
	ZVAL_STR_COPY(&dir_zv, dir);
	object_init_ex(return_value, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_RecursiveDirectoryIterator);
	ZVAL_LONG(&_1, 4096);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 292, &dir_zv, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 293, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the file contents and returns an array or an error if something
 * went wrong
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getPayload)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filepath_zv, __$false, payload, pointer, _0, _1, _2, _3;
	zend_string *filepath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filepath_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filepath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filepath_zv);
	ZVAL_STR_COPY(&filepath_zv, filepath);
	ZEPHIR_INIT_VAR(&payload);
	ZVAL_BOOL(&payload, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "r");
	ZEPHIR_CALL_METHOD(&pointer, this_ptr, "phpfopen", NULL, 0, &filepath_zv, &_0);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&pointer))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(&_2, "flock", NULL, 294, &pointer, &_1);
	zephir_check_call_status();
	if (EXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_2))) {
		ZEPHIR_CALL_METHOD(&payload, this_ptr, "phpfilegetcontents", NULL, 0, &filepath_zv);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfclose", NULL, 0, &pointer);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&payload))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_2__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_1, 8);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 295, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "unserialize", NULL, 26, &payload);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&payload, &_3);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 296);
	zephir_check_call_status();
	_4 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_4)) {
		_4 = Z_TYPE_P(&payload) != IS_ARRAY;
	}
	if (UNEXPECTED(_4)) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CCTOR(&payload);
}

/**
 * Returns if the cache has expired for this item or not
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, isExpired)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload_param = NULL, created, ttl, _0, _1, _2, _3, _4;
	zval payload;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&created);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(payload, payload_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &payload_param);
	zephir_get_arrval(&payload, payload_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "created");
	ZEPHIR_CALL_METHOD(&created, this_ptr, "getarrval", NULL, 0, &payload, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ttl");
	ZVAL_LONG(&_2, 3600);
	ZEPHIR_CALL_METHOD(&ttl, this_ptr, "getarrval", NULL, 0, &payload, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "forever");
	if (ZEPHIR_IS_IDENTICAL(&_3, &ttl)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_add_function(&_4, &created, &ttl);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_time(&_1);
	RETURN_MM_BOOL(ZEPHIR_LT(&_4, &_1));
}

/**
 * Stores an array payload on the file system
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, storePayload)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval *payload_param = NULL, key_zv, __$true, directory, localPayload, _0, _2, _3, _4, _1$$3;
	zval payload;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&key_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&localPayload);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(payload, payload_param)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	payload_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&payload, payload_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_FUNCTION(&localPayload, "serialize", NULL, 21, &payload);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 286, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 297, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZVAL_LONG(&_1$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 298, &directory, &_1$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &directory, &key_zv);
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileputcontents", NULL, 0, &_3, &localPayload, &_4);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));
}

/**
 * @param string $file
 * @param bool   $filesystemSafe
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, toDirFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool filesystemSafe, _2;
	zval file_zv, *filesystemSafe_param = NULL, name, start, _0, _1, _8, _9, _3$$3, _4$$3, _5$$3, _6$$4, _7$$4;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(file)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(filesystemSafe)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		filesystemSafe_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	if (!filesystemSafe_param) {
		filesystemSafe = 0;
	} else {
		}
	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(&name, "pathinfo", NULL, 197, &file_zv, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, -2);
	ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 299, &name, &_0, &_1);
	zephir_check_call_status();
	_2 = filesystemSafe == 1;
	if (_2) {
		_2 = !(ZEPHIR_IS_EMPTY(&start));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, ".");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "-");
		zephir_fast_str_replace(&_3$$3, &_4$$3, &_5$$3, &start);
		ZEPHIR_CPY_WRT(&start, &_3$$3);
	}
	if (!zephir_is_true(&start)) {
		ZVAL_LONG(&_6$$4, 0);
		ZVAL_LONG(&_7$$4, 1);
		ZEPHIR_CALL_FUNCTION(&start, "mb_substr", NULL, 299, &name, &_6$$4, &_7$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&_9, "mb_str_split", NULL, 300, &start, &_0);
	zephir_check_call_status();
	zephir_fast_join_str(&_8, SL("/"), &_9);
	ZEPHIR_CONCAT_VS(return_value, &_8, "/");
	RETURN_MM();
}

/**
 * @param string $directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, toDirSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval directory_zv, _0, _1;
	zend_string *directory = NULL;

	ZVAL_UNDEF(&directory_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(directory)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&directory_zv);
	ZVAL_STR_COPY(&directory_zv, directory);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &directory_zv, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 157, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 158, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 158, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 159, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 160, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 161, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 162, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 163, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

