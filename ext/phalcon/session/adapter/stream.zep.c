
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Stream
 *
 * This is the file based adapter. It stores sessions in a file based system
 *
 * ```php
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Stream;
 *
 * $session = new Manager();
 * $files = new Stream(
 *     [
 *         'savePath' => '/tmp',
 *     ]
 * );
 * $session->setAdapter($files);
 * ```
 *
 * @property array  $options
 * @property string $prefix
 * @property string $path
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Stream, phalcon, session_adapter_stream, phalcon_session_adapter_noop_ce, phalcon_session_adapter_stream_method_entry, 0);

	/**
	 * Session options
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_session_adapter_stream_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * Session prefix
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_adapter_stream_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_adapter_stream_ce, SL("path"), "", ZEND_ACC_PRIVATE);
	phalcon_session_adapter_stream_ce->create_object = zephir_init_properties_Phalcon_Session_Adapter_Stream;

	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array $options = [
 *     'prefix' => '',
 *     'savePath' => ''
 * ]
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, path, _0, _1, _2, _3, _5, _7, _4$$3, _6$$4;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "prefix");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrval", NULL, 0, &options, &_1, &_2);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1300, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1301, &options);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "session.save_path");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "phpiniget", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "savePath");
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getarrval", NULL, 0, &options, &_1, &_3);
	zephir_check_call_status();
	if (UNEXPECTED(1 == ZEPHIR_IS_EMPTY(&path))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, phalcon_session_adapter_exceptions_invalidsavepath_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Session/Adapter/Stream.zep", 93);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "phpiswritable", NULL, 0, &path);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, phalcon_session_adapter_exceptions_savepathunavailable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 0, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalcon/Session/Adapter/Stream.zep", 97);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "todirseparator", NULL, 0, &path);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1302, &_7);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Session_Adapter_Stream, destroy)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, file, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VV(&file, &_0, &_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileexists", NULL, 0, &file);
	zephir_check_call_status();
	_3 = zephir_is_true(&_2);
	if (_3) {
		ZEPHIR_CALL_FUNCTION(&_4, "is_file", NULL, 442, &file);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpunlink", NULL, 0, &file);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Garbage Collector
 *
 * @param int $max_lifetime
 * @return false|int
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, gc)
{
	zend_bool _15$$6, _8$$7, _11$$7, _17$$9, _19$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL, *_13 = NULL;
	zval *max_lifetime_param = NULL, file, glob, last, pattern, time, _0, _1, _2, _3$$4, _4$$3, *_5$$6, _14$$6, _6$$7, _9$$7, _12$$7, _16$$9, _18$$9, _20$$9;
	zend_long max_lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&glob);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(max_lifetime)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &max_lifetime_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1300, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VVS(&pattern, &_0, &_1, "*");
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	ZEPHIR_INIT_VAR(&time);
	ZVAL_LONG(&time, (zephir_get_numberval(&_2) - max_lifetime));
	ZEPHIR_CALL_METHOD(&glob, this_ptr, "getglobfiles", NULL, 0, &pattern);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&glob)) {
		ZEPHIR_CALL_FUNCTION(&last, "error_get_last", NULL, 0);
		zephir_check_call_status();
		if (zephir_array_isset_value_string(&last, SL("message"))) {
			zephir_array_fetch_string(&_3$$4, &last, SL("message"), PH_NOISY | PH_READONLY, "phalcon/Session/Adapter/Stream.zep", 133);
			ZEPHIR_CPY_WRT(&last, &_3$$4);
		} else {
			ZEPHIR_INIT_NVAR(&last);
			ZVAL_STRING(&last, "Unexpected gc error");
		}
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, phalcon_session_adapter_exceptions_adapterruntimeerror_ce);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 8, &last);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalcon/Session/Adapter/Stream.zep", 137);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&glob))) {
		zephir_is_iterable(&glob, 0, "phalcon/Session/Adapter/Stream.zep", 148);
		if (Z_TYPE_P(&glob) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&glob), _5$$6)
			{
				ZEPHIR_INIT_NVAR(&file);
				ZVAL_COPY(&file, _5$$6);
				ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "phpfileexists", &_7, 0, &file);
				zephir_check_call_status();
				_8$$7 = ZEPHIR_IS_TRUE_IDENTICAL(&_6$$7);
				if (_8$$7) {
					ZEPHIR_CALL_FUNCTION(&_9$$7, "is_file", &_10, 442, &file);
					zephir_check_call_status();
					_8$$7 = ZEPHIR_IS_TRUE_IDENTICAL(&_9$$7);
				}
				_11$$7 = _8$$7;
				if (_11$$7) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					zephir_filemtime(&_12$$7, &file);
					_11$$7 = ZEPHIR_LT(&_12$$7, &time);
				}
				if (_11$$7) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpunlink", &_13, 0, &file);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &glob, "rewind", NULL, 0);
			zephir_check_call_status();
			_15$$6 = 1;
			while (1) {
				if (_15$$6) {
					_15$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &glob, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_14$$6, &glob, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&file, &glob, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_16$$9, this_ptr, "phpfileexists", &_7, 0, &file);
					zephir_check_call_status();
					_17$$9 = ZEPHIR_IS_TRUE_IDENTICAL(&_16$$9);
					if (_17$$9) {
						ZEPHIR_CALL_FUNCTION(&_18$$9, "is_file", &_10, 442, &file);
						zephir_check_call_status();
						_17$$9 = ZEPHIR_IS_TRUE_IDENTICAL(&_18$$9);
					}
					_19$$9 = _17$$9;
					if (_19$$9) {
						ZEPHIR_INIT_NVAR(&_20$$9);
						zephir_filemtime(&_20$$9, &file);
						_19$$9 = ZEPHIR_LT(&_20$$9, &time);
					}
					if (_19$$9) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpunlink", &_13, 0, &file);
						zephir_check_call_status();
					}
			}
		}
		ZEPHIR_INIT_NVAR(&file);
	}
	RETURN_MM_LONG(1);
}

/**
 * Ignore the savePath and use local defined path
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, open)
{
	zval *path, path_sub, *name, name_sub;

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(path)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &path, &name);
	RETURN_BOOL(1);
}

/**
 * Reads data from the adapter
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, data, name, pointer, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZEPHIR_INIT_VAR(&data);
	ZVAL_STRING(&data, "");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileexists", NULL, 0, &name);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "r");
		ZEPHIR_CALL_METHOD(&pointer, this_ptr, "phpfopen", NULL, 0, &name, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "flock", NULL, 292, &pointer, &_4$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_CALL_METHOD(&data, this_ptr, "phpfilegetcontents", NULL, 0, &name);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfclose", NULL, 0, &pointer);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			RETURN_MM_STRING("");
		}
	}
	RETURN_CCTOR(&data);
}

/**
 * Refresh the session file modification time without changing its data
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, updateTimestamp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *data, data_sub, name, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &id, &data);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZEPHIR_RETURN_CALL_FUNCTION("touch", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Validate the session id (used when strict mode is enabled)
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, validateId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpfileexists", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Session_Adapter_Stream, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *data, data_sub, name, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &id, &data);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1302, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileputcontents", NULL, 0, &name, data, &_3);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));
}

/**
 * Gets the glob array or returns false on failure
 *
 * @param string $pattern
 *
 * @return array|false
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, getGlobFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval pattern_zv, errorLevel, glob, _0;
	zend_string *pattern = NULL;

	ZVAL_UNDEF(&pattern_zv);
	ZVAL_UNDEF(&errorLevel);
	ZVAL_UNDEF(&glob);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(pattern)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&pattern_zv);
	ZVAL_STR_COPY(&pattern_zv, pattern);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&errorLevel, "error_reporting", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "error_clear_last", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&glob, "glob", NULL, 0, &pattern_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 0, &errorLevel);
	zephir_check_call_status();
	RETURN_CCTOR(&glob);
}

/**
 * Helper method to get the name prefixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, getPrefixedName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name = NULL, name_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_SEPARATE_PARAM(name);
	zephir_cast_to_string(&_0, name);
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1300, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_1, name);
	RETURN_MM();
}

/**
 * @param string $directory
 *
 * @return string
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, toDirSeparator)
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFclose)
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFgetCsv)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFileExists)
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFileGetContents)
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
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFilePutContents)
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
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFopen)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFwrite)
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
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIsWritable)
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
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpUnlink)
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
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	if (1 == zephir_array_isset_value(&collection, index)) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 16, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

/**
 * Gets the value of a configuration option
 *
 * @param string $input
 * @param string $defaultValue
 *
 * @return string
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIniGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, defaultValue_zv, value;
	zend_string *input = NULL, *defaultValue = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&defaultValue_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue) {
		defaultValue = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&defaultValue_zv);
		ZVAL_STR(&defaultValue_zv, defaultValue);
	} else {
		zephir_memory_observe(&defaultValue_zv);
	ZVAL_STR_COPY(&defaultValue_zv, defaultValue);
	}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 440, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_STR(zend_string_copy(defaultValue));
	}
	RETURN_CCTOR(&value);
}

/**
 * Query a php.ini value and return it back as boolean
 *
 * @param string $input
 * @param bool   $defaultValue
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIniGetBool)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool defaultValue, result;
	zval input_zv, *defaultValue_param = NULL, value, _0;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	result = 0;
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 440, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_BOOL(defaultValue);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &value);
	do {
		if (ZEPHIR_IS_STRING(&_0, "true") || ZEPHIR_IS_STRING(&_0, "on") || ZEPHIR_IS_STRING(&_0, "yes") || ZEPHIR_IS_STRING(&_0, "y") || ZEPHIR_IS_STRING(&_0, "1")) {
			result = 1;
		}
	} while(0);

	RETURN_MM_BOOL(result);
}

/**
 * Query a php.ini value and return it back as integer
 *
 * @param string $input
 * @param int    $defaultValue
 *
 * @return int
 *
 * @link https://php.net/manual/en/function.ini-get.php
 * @link https://php.net/manual/en/ini.list.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpIniGetInt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long defaultValue, ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, *defaultValue_param = NULL, value;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!defaultValue_param) {
		defaultValue = 0;
	} else {
		}
	ZEPHIR_CALL_FUNCTION(&value, "ini_get", NULL, 440, &input_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
		RETURN_MM_LONG(defaultValue);
	}
	RETURN_MM_LONG(zephir_get_intval(&value));
}

/**
 * Parse a configuration file
 *
 * @param string $filename
 * @param bool   $processSections
 * @param int    $scannerMode
 *
 * @return array|false
 *
 * @link https://php.net/manual/en/function.parse-ini-file.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpParseIniFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long scannerMode, ZEPHIR_LAST_CALL_STATUS;
	zend_bool processSections;
	zval filename_zv, *processSections_param = NULL, *scannerMode_param = NULL, _0, _1;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(processSections)
		Z_PARAM_LONG(scannerMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		processSections_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		scannerMode_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!processSections_param) {
		processSections = 0;
	} else {
		}
	if (!scannerMode_param) {
		scannerMode = 0;
	} else {
		}
	ZVAL_BOOL(&_0, (processSections ? 1 : 0));
	ZVAL_LONG(&_1, scannerMode);
	ZEPHIR_RETURN_CALL_FUNCTION("parse_ini_file", NULL, 441, &filename_zv, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Session_Adapter_Stream(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

