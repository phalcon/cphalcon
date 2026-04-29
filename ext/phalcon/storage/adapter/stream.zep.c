
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
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/file.h"
#include "kernel/string.h"
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
 *
 * @property string $storageDir
 * @property array  $options
 */
ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Storage\\Adapter, Stream, phalcon, storage_adapter_stream, phalcon_storage_adapter_abstractadapter_ce, phalcon_storage_adapter_stream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_stream_ce, SL("prefix"), "ph-strm", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_storage_adapter_stream_ce, SL("storageDir"), "", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Stream constructor.
 *
 * @param SerializerFactory $factory
 * @param array             $options = [
 *     'storageDir'        => '',
 *     'defaultSerializer' => 'php',
 *     'lifetime'          => 3600,
 *     'prefix'            => ''
 * ]
 *
 * @throws Exception
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
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "storageDir");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&storageDir, this_ptr, "getarrval", NULL, 0, &options, &_0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&storageDir)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_storage_exception_ce, "The 'storageDir' must be specified in the options", "phalcon/Storage/Adapter/Stream.zep", 59);
		return;
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdirseparator", NULL, 122, &storageDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("storageDir"), &_2);
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
	zend_bool result = 0, _4$$4, _9$$6;
	zval directory, iterator, file, _0, *_1, _2, _3$$4, _5$$4, _6$$4, _8$$6, _10$$6, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	result = 1;
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 123);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &directory);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(result);
	}
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 124, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 95);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_CALL_METHOD(&_3$$4, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			_4$$4 = ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4);
			if (_4$$4) {
				ZEPHIR_CALL_METHOD(&_6$$4, &file, "getpathname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "phpunlink", &_7, 0, &_6$$4);
				zephir_check_call_status();
				_4$$4 = !ZEPHIR_IS_TRUE_IDENTICAL(&_5$$4);
			}
			if (UNEXPECTED(_4$$4)) {
				result = 0;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				_9$$6 = ZEPHIR_IS_TRUE_IDENTICAL(&_8$$6);
				if (_9$$6) {
					ZEPHIR_CALL_METHOD(&_11$$6, &file, "getpathname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "phpunlink", &_7, 0, &_11$$6);
					zephir_check_call_status();
					_9$$6 = !ZEPHIR_IS_TRUE_IDENTICAL(&_10$$6);
				}
				if (UNEXPECTED(_9$$6)) {
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
 * Stores data in the adapter
 *
 * @param string $prefix
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeys)
{
	zval files;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval prefix_zv, directory, file, iterator, _0, *_1, _2, _3$$4, _4$$5, _5$$5, _6$$5, _7$$6, _8$$7, _9$$7, _10$$7;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&iterator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&files);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!prefix) {
		prefix = zend_string_init(ZEND_STRL(""), 0);
		ZVAL_STR(&prefix_zv, prefix);
	} else {
	ZVAL_STR_COPY(&prefix_zv, prefix);
	}
	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 123);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &directory);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&iterator, this_ptr, "getiterator", NULL, 124, &directory);
	zephir_check_call_status();
	zephir_is_iterable(&iterator, 0, "phalcon/Storage/Adapter/Stream.zep", 125);
	if (Z_TYPE_P(&iterator) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&iterator), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_CALL_METHOD(&_3$$4, &file, "isfile", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_3$$4)) {
				zephir_read_property(&_4$$5, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_5$$5, &file, "getfilename", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_VV(&_6$$5, &_4$$5, &_5$$5);
				zephir_array_append(&files, &_6$$5, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 121);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &iterator, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &iterator, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &iterator, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$6, &file, "isfile", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_TRUE_IDENTICAL(&_7$$6)) {
					zephir_read_property(&_8$$7, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_9$$7, &file, "getfilename", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZEPHIR_CONCAT_VV(&_10$$7, &_8$$7, &_9$$7);
					zephir_array_append(&files, &_10$$7, PH_SEPARATE, "phalcon/Storage/Adapter/Stream.zep", 121);
				}
			ZEPHIR_CALL_METHOD(NULL, &iterator, "next", NULL, 0);
			zephir_check_call_status();
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
 *
 * @param string $key
 * @param mixed  $value
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, setForever)
{
	zval payload;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *value, value_sub, _0, _1;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&payload);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_INIT_VAR(&payload);
	zephir_create_array(&payload, 3, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	zephir_array_update_string(&payload, SL("created"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&payload, SL("ttl"), SL("forever"));
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getserializeddata", NULL, 0, value);
	zephir_check_call_status();
	zephir_array_update_string(&payload, SL("content"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "storepayload", NULL, 125, &payload, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Decrements a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
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
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "get", NULL, 0, &key_zv);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) - value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "set", NULL, 0, &key_zv, &data);
	zephir_check_call_status();
	if (EXPECTED(!ZEPHIR_IS_FALSE_IDENTICAL(&result))) {
		ZEPHIR_CPY_WRT(&result, &data);
	}
	RETURN_CCTOR(&result);
}

/**
 * Deletes data from the adapter
 *
 * @param string $key
 *
 * @return bool
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
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 126, &key_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 127, &filepath);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reads data from the adapter
 *
 * @param string     $key
 * @param mixed|null $defaultValue
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, doGet)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, content, filepath, payload, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 126, &key_zv);
	zephir_check_call_status();
	if (1 != (zephir_file_exists(&filepath) == SUCCESS)) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 128, &filepath);
	zephir_check_call_status();
	_0 = ZEPHIR_IS_EMPTY(&payload);
	if (!(_0)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "isexpired", NULL, 129, &payload);
		zephir_check_call_status();
		_0 = zephir_is_true(&_1);
	}
	if (_0) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "content");
	ZEPHIR_CALL_METHOD(&content, this_ptr, "getarrval", NULL, 0, &payload, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getunserializeddata", NULL, 0, &content, defaultValue);
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
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 126, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfileexists", NULL, 0, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&payload, this_ptr, "getpayload", NULL, 128, &filepath);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&payload))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isexpired", NULL, 129, &payload);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_1));
}

/**
 * Increments a stored number
 *
 * @param string $key
 * @param int    $value
 *
 * @return bool|int
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
	ZVAL_STR_COPY(&key_zv, key);
	if (!value_param) {
		value = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &key_zv);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "get", NULL, 0, &key_zv);
	zephir_check_call_status();
	_1 = (zephir_get_intval(&data) + value);
	ZEPHIR_INIT_NVAR(&data);
	ZVAL_LONG(&data, _1);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "set", NULL, 0, &key_zv, &data);
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
 *
 * @param string                $key
 * @param mixed                 $value
 * @param DateInterval|int|null $ttl
 *
 * @return bool
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "storepayload", NULL, 125, &payload, &key_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the folder based on the storageDir and the prefix
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key_zv, dirFromFile, dirPrefix, _0, _1, _2, _3, _4;
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!key) {
		key = zend_string_init(ZEND_STRL(""), 0);
		ZVAL_STR(&key_zv, key);
	} else {
	ZVAL_STR_COPY(&key_zv, key);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("storageDir"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	ZEPHIR_CALL_METHOD(&dirPrefix, this_ptr, "getdirseparator", NULL, 122, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getkeywithoutprefix", NULL, 130, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&dirFromFile, this_ptr, "getdirfromfile", NULL, 131, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &dirPrefix, &dirFromFile);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getdirseparator", NULL, 122, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the full path to the file
 *
 * @param string $key
 *
 * @return string
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
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdir", NULL, 123, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getkeywithoutprefix", NULL, 130, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	RETURN_MM();
}

/**
 * Check if the key has the prefix and remove it, otherwise just return the
 * key unaltered
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeyWithoutPrefix)
{
	zval key_zv, _0, _1$$3, _2$$3;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	if (zephir_start_with(&key_zv, &_0, NULL)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, zephir_fast_strlen_ev(&_1$$3));
		zephir_substr(return_value, &key_zv, zephir_get_intval(&_2$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		return;
	}
	RETURN_STR(zend_string_copy(key));
}

/**
 * Returns an iterator for the directory contents
 *
 * @param string $dir
 *
 * @return Iterator
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
	ZVAL_STR_COPY(&dir_zv, dir);
	object_init_ex(return_value, spl_ce_RecursiveIteratorIterator);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_RecursiveDirectoryIterator);
	ZVAL_LONG(&_1, 4096);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 132, &dir_zv, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 133, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the file contents and returns an array or an error if something
 * went wrong
 *
 * @param string $filepath
 *
 * @return array
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getPayload)
{
	zend_bool _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filepath_zv, __$false, payload, pointer, version, _0, _1, _2, _3, _4, _9, _5$$6, _6$$6, _7$$7, _8$$7;
	zend_string *filepath = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filepath_zv);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filepath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CALL_FUNCTION(&_2, "flock", NULL, 134, &pointer, &_1);
	zephir_check_call_status();
	if (EXPECTED(ZEPHIR_IS_TRUE_IDENTICAL(&_2))) {
		ZEPHIR_CALL_METHOD(&payload, this_ptr, "phpfilegetcontents", NULL, 0, &filepath_zv);
		zephir_check_call_status();
	}
	zephir_fclose(&pointer);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&payload))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&version, "phpversion", NULL, 135);
	zephir_check_call_status();
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "8.0");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, ">=");
	ZEPHIR_CALL_FUNCTION(&_4, "version_compare", NULL, 136, &version, &_0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		ZEPHIR_INIT_NVAR(&_5$$6);
		zephir_create_closure_ex(&_5$$6, NULL, phalcon_1__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_6$$6, 8);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 137, &_5$$6, &_6$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_7$$7);
		ZEPHIR_INIT_NVAR(&_7$$7);
		zephir_create_closure_ex(&_7$$7, NULL, phalcon_2__closure_ce, SL("__invoke"));
		ZVAL_LONG(&_8$$7, 8);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 137, &_7$$7, &_8$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_9, "unserialize", NULL, 15, &payload);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&payload, &_9);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 138);
	zephir_check_call_status();
	_10 = ZEPHIR_GLOBAL(warning).enable;
	if (!(_10)) {
		_10 = Z_TYPE_P(&payload) != IS_ARRAY;
	}
	if (UNEXPECTED(_10)) {
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
	ZEPHIR_OBS_COPY_OR_DUP(&payload, payload_param);
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
 *
 * @param array  $payload
 * @param string $key
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Storage_Adapter_Stream, storePayload)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval payload, *payload_param = NULL, key_zv, __$true, directory, _0, _2, _3, _4, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&key_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&directory);
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
	ZVAL_STR_COPY(&key_zv, key);
	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 14, &payload);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&payload, &_0);
	ZEPHIR_CALL_METHOD(&directory, this_ptr, "getdir", NULL, 123, &key_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 139, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZVAL_LONG(&_1$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 140, &directory, &_1$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &directory, &key_zv);
	ZVAL_LONG(&_4, 2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileputcontents", NULL, 0, &_3, &payload, &_4);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));
}

/**
 * @todo Remove the methods below when we get traits
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

PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFileGetContents)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	zephir_file_get_contents(return_value, &filename_zv);
	return;
}

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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 141, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, mode_zv;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZVAL_STR_COPY(&mode_zv, mode);
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 142, &filename_zv, &mode_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Stream, phpUnlink)
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
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 127, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDirFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, name, start, _0, _1, _7, _8, _9, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&file_zv, file);
	ZVAL_LONG(&_0, 8);
	ZEPHIR_CALL_FUNCTION(&name, "pathinfo", NULL, 96, &file_zv, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, -2);
	ZEPHIR_INIT_VAR(&start);
	zephir_substr(&start, &name, 0 , -2 , 0);
	if (!(ZEPHIR_IS_EMPTY(&start))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, ".");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "-");
		zephir_fast_str_replace(&_2$$3, &_3$$3, &_4$$3, &start);
		ZEPHIR_CPY_WRT(&start, &_2$$3);
	}
	if (!(zephir_is_true(&start))) {
		ZVAL_LONG(&_5$$4, 0);
		ZVAL_LONG(&_6$$4, 1);
		ZEPHIR_INIT_NVAR(&start);
		zephir_substr(&start, &name, 0 , 1 , 0);
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_8, 2);
	ZEPHIR_CALL_FUNCTION(&_9, "str_split", NULL, 95, &start, &_8);
	zephir_check_call_status();
	zephir_fast_join_str(&_7, SL("/"), &_9);
	ZEPHIR_CONCAT_VS(return_value, &_7, "/");
	RETURN_MM();
}

PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDirSeparator)
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
	ZVAL_STR_COPY(&directory_zv, directory);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &directory_zv, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();
}

