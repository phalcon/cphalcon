
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/time.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Stream) {

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
 * @param array options = [
 *     'prefix' => '',
 *     'savePath' => ''
 * ]
 */
PHP_METHOD(Phalcon_Session_Adapter_Stream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	zval options, *options_param = NULL, path, _1, _3, _6, _2$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

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
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_1);
	ZEPHIR_OBS_VAR(&path);
	if (!(zephir_array_isset_string_fetch(&path, &options, SL("savePath"), 0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "session.save_path");
		ZEPHIR_CALL_FUNCTION(&path, "ini_get", NULL, 489, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_writable", NULL, 344, &path);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_session_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "The session save path [", &path, "] is not writable");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 8, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Session/Adapter/Stream.zep", 68);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_helper_str_ce, "dirseparator", &_7, 126, &path);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("path"), &_6);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Stream, destroy) {

	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, file, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&file);
	ZEPHIR_CONCAT_VV(&file, &_0, &_1);
	_2 = (zephir_file_exists(&file) == SUCCESS);
	if (_2) {
		ZEPHIR_CALL_FUNCTION(&_3, "is_file", NULL, 490, &file);
		zephir_check_call_status();
		_2 = zephir_is_true(&_3);
	}
	if (_2) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 128, &file);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Stream, gc) {

	zend_bool _6$$3, _9$$3, _12$$5, _14$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxlifetime, maxlifetime_sub, file, pattern, time, _0, _1, _2, _3, *_4, _5, _7$$3, _10$$3, _13$$5, _15$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VVS(&pattern, &_0, &_1, "*");
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	ZEPHIR_INIT_VAR(&time);
	zephir_sub_function(&time, &_2, maxlifetime);
	ZEPHIR_CALL_FUNCTION(&_3, "glob", NULL, 491, &pattern);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Session/Adapter/Stream.zep", 102);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _4);
			_6$$3 = (zephir_file_exists(&file) == SUCCESS);
			if (_6$$3) {
				ZEPHIR_CALL_FUNCTION(&_7$$3, "is_file", &_8, 490, &file);
				zephir_check_call_status();
				_6$$3 = zephir_is_true(&_7$$3);
			}
			_9$$3 = _6$$3;
			if (_9$$3) {
				ZEPHIR_INIT_NVAR(&_10$$3);
				zephir_filemtime(&_10$$3, &file);
				_9$$3 = ZEPHIR_LT(&_10$$3, &time);
			}
			if (_9$$3) {
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_11, 128, &file);
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
				_12$$5 = (zephir_file_exists(&file) == SUCCESS);
				if (_12$$5) {
					ZEPHIR_CALL_FUNCTION(&_13$$5, "is_file", &_8, 490, &file);
					zephir_check_call_status();
					_12$$5 = zephir_is_true(&_13$$5);
				}
				_14$$5 = _12$$5;
				if (_14$$5) {
					ZEPHIR_INIT_NVAR(&_15$$5);
					zephir_filemtime(&_15$$5, &file);
					_14$$5 = ZEPHIR_LT(&_15$$5, &time);
				}
				if (_14$$5) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_11, 128, &file);
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
PHP_METHOD(Phalcon_Session_Adapter_Stream, open) {

	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);

	zephir_fetch_params_without_memory_grow(2, 0, &savePath, &sessionName);



	RETURN_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Stream, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, data, name, pointer, _0, _1, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZEPHIR_INIT_VAR(&data);
	ZVAL_STRING(&data, "");
	if ((zephir_file_exists(&name) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "r");
		ZEPHIR_CALL_FUNCTION(&pointer, "fopen", NULL, 86, &name, &_2$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "flock", NULL, 140, &pointer, &_3$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_NVAR(&data);
			zephir_file_get_contents(&data, &name);
		}
		zephir_fclose(&pointer);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			RETURN_MM_STRING("");
		}
	}
	RETURN_CCTOR(&data);

}

PHP_METHOD(Phalcon_Session_Adapter_Stream, write) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &data);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&_3, "file_put_contents", NULL, 135, &name, data, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_3));

}

