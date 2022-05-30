
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/time.h"
#include "kernel/array.h"
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
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_adapter_stream_ce, SL("path"), "", ZEND_ACC_PRIVATE);
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
	zephir_fcall_cache_entry *_0 = NULL;
	zval *options_param = NULL, path, _1, _2, _3, _6, _4$$4, _5$$4;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_stream_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "session.save_path");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "phpiniget", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "savePath");
	ZEPHIR_CALL_METHOD(&path, this_ptr, "getarrval", NULL, 0, &options, &_2, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(1 == ZEPHIR_IS_EMPTY(&path))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_session_exception_ce, "The session save path cannot be empty", "phalcon/Session/Adapter/Stream.zep", 67);
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "phpiswritable", NULL, 0, &path);
	zephir_check_call_status();
	if (UNEXPECTED(!ZEPHIR_IS_TRUE_IDENTICAL(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_session_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "The session save path [", &path, "] is not writable");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 29, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Session/Adapter/Stream.zep", 71);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getdirseparator", NULL, 506, &path);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &_6);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Session_Adapter_Stream, destroy)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, file, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(sessionId)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, sessionId);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VV(&file, &_0, &_1);
	_2 = (zephir_file_exists(&file) == SUCCESS);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_file", NULL, 507, &file);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 118, &file);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);
}

/**
 * Garbage Collector
 *
 * @param int $maxlifetime
 * @return false|int
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, gc)
{
	zend_bool _6$$3, _9$$3, _12$$5, _14$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zval *maxlifetime_param = NULL, file, pattern, time, _0, _1, _2, _3, *_4, _5, _7$$3, _10$$3, _13$$5, _15$$5;
	zend_long maxlifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&time);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(maxlifetime)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime_param);
	maxlifetime = zephir_get_intval(maxlifetime_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VVS(&pattern, &_0, &_1, "*");
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	ZEPHIR_INIT_VAR(&time);
	ZVAL_LONG(&time, (zephir_get_numberval(&_2) - maxlifetime));
	ZEPHIR_CALL_FUNCTION(&_3, "glob", NULL, 508, &pattern);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Session/Adapter/Stream.zep", 111);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _4);
			_6$$3 = 1 == (zephir_file_exists(&file) == SUCCESS);
			if (_6$$3) {
				ZEPHIR_CALL_FUNCTION(&_7$$3, "is_file", &_8, 507, &file);
				zephir_check_call_status();
				_6$$3 = ZEPHIR_IS_TRUE_IDENTICAL(&_7$$3);
			}
			_9$$3 = _6$$3;
			if (_9$$3) {
				ZEPHIR_INIT_NVAR(&_10$$3);
				zephir_filemtime(&_10$$3, &file);
				_9$$3 = ZEPHIR_LT(&_10$$3, &time);
			}
			if (_9$$3) {
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_11, 118, &file);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &_3, "current", NULL, 0);
			zephir_check_call_status();
				_12$$5 = 1 == (zephir_file_exists(&file) == SUCCESS);
				if (_12$$5) {
					ZEPHIR_CALL_FUNCTION(&_13$$5, "is_file", &_8, 507, &file);
					zephir_check_call_status();
					_12$$5 = ZEPHIR_IS_TRUE_IDENTICAL(&_13$$5);
				}
				_14$$5 = _12$$5;
				if (_14$$5) {
					ZEPHIR_INIT_NVAR(&_15$$5);
					zephir_filemtime(&_15$$5, &file);
					_14$$5 = ZEPHIR_LT(&_15$$5, &time);
				}
				if (_14$$5) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_11, 118, &file);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_BOOL(1);
}

/**
 * Ignore the savePath and use local defined path
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, open)
{
	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(savePath)
		Z_PARAM_ZVAL(sessionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &savePath, &sessionName);


	RETURN_BOOL(1);
}

/**
 * Reads data from the adapter
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, data, name, pointer, _0, _1, _2, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(sessionId)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionId);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, sessionId);
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
		ZEPHIR_CALL_FUNCTION(&_5$$3, "flock", NULL, 126, &pointer, &_4$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$3)) {
			ZEPHIR_CALL_METHOD(&data, this_ptr, "phpfilegetcontents", NULL, 0, &name);
			zephir_check_call_status();
		}
		zephir_fclose(&pointer);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			RETURN_MM_STRING("");
		}
	}
	RETURN_CCTOR(&data);
}

PHP_METHOD(Phalcon_Session_Adapter_Stream, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId, sessionId_sub, *data, data_sub, name, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(sessionId)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionId, &data);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, sessionId);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "phpfileputcontents", NULL, 0, &name, data, &_3);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cast;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, *cast_param = NULL, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cast);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &collection_param, &index, &defaultValue, &cast_param);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast_param) {
		ZEPHIR_INIT_VAR(&cast);
	} else {
	if (UNEXPECTED(Z_TYPE_P(cast_param) != IS_STRING && Z_TYPE_P(cast_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cast' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cast_param) == IS_STRING)) {
		zephir_get_strval(&cast, cast_param);
	} else {
		ZEPHIR_INIT_VAR(&cast);
	}
	}


	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (UNEXPECTED(zephir_is_true(&cast))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 12, &value, &cast);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

PHP_METHOD(Phalcon_Session_Adapter_Stream, getDirSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *directory_param = NULL, _0, _1;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(directory)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &directory_param);
	if (UNEXPECTED(Z_TYPE_P(directory_param) != IS_STRING && Z_TYPE_P(directory_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'directory' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(directory_param) == IS_STRING)) {
		zephir_get_strval(&directory, directory_param);
	} else {
		ZEPHIR_INIT_VAR(&directory);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &directory, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);


	RETURN_MM_BOOL((zephir_file_exists(&filename) == SUCCESS));
}

/**
 * @param string $filename
 *
 * @return string|false
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);


	zephir_file_get_contents(return_value, &filename);
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return int|false
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &filename_param, &data, &flags_param, &context);
	zephir_get_strval(&filename, filename_param);
	if (!flags_param) {
		flags = 0;
	} else {
		flags = zephir_get_intval(flags_param);
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 133, &filename, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 * @param string $mode
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filename_param = NULL, *mode_param = NULL;
	zval filename, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &filename_param, &mode_param);
	zephir_get_strval(&filename, filename_param);
	zephir_get_strval(&mode, mode_param);


	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 134, &filename, &mode);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gets the value of a configuration option
 *
 * @param string $varname
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
	zval *varname_param = NULL;
	zval varname;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varname);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(varname)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &varname_param);
	zephir_get_strval(&varname, varname_param);


	ZEPHIR_RETURN_CALL_FUNCTION("ini_get", NULL, 509, &varname);
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
	zval *filename_param = NULL;
	zval filename;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filename);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);


	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 510, &filename);
	zephir_check_call_status();
	RETURN_MM();
}

