
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * JSON file-backed adapter.
 *
 * The file must contain a JSON array of user records:
 *   [{"id":1,"email":"a@b","password":"<hashed>"}, ...]
 *
 * @phpstan-import-type AuthUserRow from AbstractArrayAdapter
 *
 * @extends AbstractArrayAdapter<StreamAdapterConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Stream, phalcon, auth_adapter_stream, phalcon_auth_adapter_abstractarrayadapter_ce, phalcon_auth_adapter_stream_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hasher, hasher_sub, *config, config_sub;

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_auth_adapter_config_streamadapterconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &config);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_stream_ce, getThis(), "__construct", NULL, 0, hasher, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, fromOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *hasher, hasher_sub, *options_param = NULL, _0, _1, _2, _3, _4;

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &options_param);
	zephir_get_arrval(&options, options_param);
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_auth_adapter_config_streamadapterconfig_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "file");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "stream adapter");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_auth_internal_options_ce, "requirestring", NULL, 0, &options, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "model");
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 327, &_1, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 328, hasher, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Loads and decodes the JSON users file. Re-read on every call - if you
 * need caching, wrap it.
 *
 * @phpstan-return list<AuthUserRow>
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Adapter_Stream, loadUsers)
{
	zval contents, data, ex, path, rows, _0, _1, _6, _2$$3, _3$$4, _4$$5, _5$$5, _7$$6, _8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&ex);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&path, &_0, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "phpfileexists", NULL, 0, &path);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_auth_exceptions_filedoesnotexist_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 329, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Auth/Adapter/Stream.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&contents, this_ptr, "phpfilegetcontents", NULL, 0, &path);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&contents)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_auth_exceptions_filecannotread_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 330, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Auth/Adapter/Stream.zep", 76);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_4$$5);
		object_init_ex(&_4$$5, phalcon_support_helper_json_decode_ce);
		if (zephir_has_constructor(&_4$$5)) {
			ZEPHIR_CALL_METHOD(NULL, &_4$$5, "__construct", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}

		ZVAL_BOOL(&_5$$5, 1);
		ZEPHIR_CALL_METHOD(&data, &_4$$5, "__invoke", NULL, 331, &contents, &_5$$5);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_OBJ(&_6, EG(exception));
		Z_ADDREF_P(&_6);
		if (zephir_is_instance_of(&_6, SL("InvalidArgumentException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&ex, &_6);
			ZEPHIR_INIT_VAR(&_7$$6);
			object_init_ex(&_7$$6, phalcon_auth_exceptions_filenotvalidjson_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 332, &path, &ex);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$6, "phalcon/Auth/Adapter/Stream.zep", 82);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_8$$7);
		object_init_ex(&_8$$7, phalcon_auth_exceptions_filedoesnotcontainjson_ce);
		ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 333, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$7, "phalcon/Auth/Adapter/Stream.zep", 86);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&rows, "array_values", NULL, 29, &data);
	zephir_check_call_status();
	RETURN_CCTOR(&rows);
}

PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFileExists)
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

PHP_METHOD(Phalcon_Auth_Adapter_Stream, phpFileGetContents)
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

