
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
#include "kernel/string.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is the file based adapter. It stores sessions in a file based system
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Files;
 *
 * $session = new Manager();
 * $files = new Files(
 *     [
 *         'savePath' => '/tmp',
 *     ]
 * );
 * $session->setHandler(new Files());
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Files) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Files, phalcon, session_adapter_files, phalcon_session_adapter_noop_ce, phalcon_session_adapter_files_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_adapter_files_ce, SL("path"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Phalcon_Session_Adapter_Files, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options, *options_param = NULL, path, _1, _3, _2$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
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


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_adapter_files_ce, getThis(), "__construct", &_0, 0, &options);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_1);
	ZEPHIR_OBS_VAR(&path);
	if (!(zephir_array_isset_string_fetch(&path, &options, SL("save_path"), 0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "session.save_path");
		ZEPHIR_CALL_FUNCTION(&path, "ini_get", NULL, 413, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_writable", NULL, 414, &path);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_session_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "The save_path [", &path, "]is not writeable");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/session/adapter/files.zep", 59 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("path"), &path);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Session_Adapter_Files, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, name, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	if (1 == (zephir_file_exists(&name TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 102, &name);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Files, gc) {

	zend_bool _5$$3, _9$$5;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *maxlifetime, maxlifetime_sub, file, pattern, _0, _1, _2, *_3, _4, _6$$3, _7$$3, _10$$5, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &maxlifetime);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&pattern);
	ZEPHIR_CONCAT_VVS(&pattern, &_0, &_1, "*");
	ZEPHIR_CALL_FUNCTION(&_2, "glob", NULL, 415, &pattern);
	zephir_check_call_status();
	zephir_is_iterable(&_2, 0, "phalcon/session/adapter/files.zep", 90);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _3);
			_5$$3 = 1 == (zephir_file_exists(&file TSRMLS_CC) == SUCCESS);
			if (_5$$3) {
				ZEPHIR_INIT_NVAR(&_6$$3);
				zephir_filemtime(&_6$$3, &file TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_7$$3);
				zephir_add_function(&_7$$3, &_6$$3, maxlifetime);
				ZEPHIR_INIT_NVAR(&_6$$3);
				zephir_time(&_6$$3);
				_5$$3 = ZEPHIR_LT(&_7$$3, &_6$$3);
			}
			if (_5$$3) {
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_8, 102, &file);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &_2, "current", NULL, 0);
			zephir_check_call_status();
				_9$$5 = 1 == (zephir_file_exists(&file TSRMLS_CC) == SUCCESS);
				if (_9$$5) {
					ZEPHIR_INIT_NVAR(&_10$$5);
					zephir_filemtime(&_10$$5, &file TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_11$$5);
					zephir_add_function(&_11$$5, &_10$$5, maxlifetime);
					ZEPHIR_INIT_NVAR(&_10$$5);
					zephir_time(&_10$$5);
					_9$$5 = ZEPHIR_LT(&_11$$5, &_10$$5);
				}
				if (_9$$5) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_8, 102, &file);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Files, open) {

	zval *savePath, savePath_sub, *sessionName, sessionName_sub, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &savePath, &sessionName);



	if (1 != zephir_end_with_str(savePath, SL("/"))) {
		ZEPHIR_INIT_VAR(&path);
		ZEPHIR_CONCAT_VS(&path, savePath, "/");
	}
	zephir_update_property_zval(this_ptr, SL("path"), &path);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Phalcon_Session_Adapter_Files, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, data, name, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZEPHIR_INIT_VAR(&data);
	ZVAL_STRING(&data, "");
	if (1 == (zephir_file_exists(&name TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_NVAR(&data);
		zephir_file_get_contents(&data, &name TSRMLS_CC);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
			RETURN_MM_STRING("");
		}
	}
	RETURN_CCTOR(&data);

}

PHP_METHOD(Phalcon_Session_Adapter_Files, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, *data, data_sub, name, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &id, &data);



	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getprefixedname", NULL, 0, id);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	ZEPHIR_CONCAT_VV(&name, &_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_file_put_contents(&_2, &name, data TSRMLS_CC);
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_2));

}

