
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/variables.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Stream
 *
 * Stores model meta-data in PHP files.
 *
 *```php
 * $metaData = new \Phalcon\Mvc\Model\MetaData\Files(
 *     [
 *         "metaDataDir" => "app/cache/metadata/",
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Stream)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Stream, phalcon, mvc_model_metadata_stream, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_stream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_model_metadata_stream_ce, SL("metaDataDir"), "./", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Files constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, metaDataDir;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&metaDataDir);
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
		zephir_get_arrval(&options, options_param);
	}


	if (zephir_array_isset_string_fetch(&metaDataDir, &options, SL("metaDataDir"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("metaDataDir"), &metaDataDir);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Reads meta-data from files
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, path, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("metaDataDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_prepare_virtual_path(&_1, &key, &_2);
	ZEPHIR_INIT_VAR(&path);
	ZEPHIR_CONCAT_VVS(&path, &_0, &_1, ".php");
	if (!((zephir_file_exists(&path) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
	if (zephir_require_zval_ret(&_3, &path) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&_3);
}

/**
 * Writes the meta-data to files
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, write)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *key_param = NULL, *data_param = NULL, option, path, _6, _7, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ARRAY(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	zephir_get_arrval(&data, data_param);



	/* try_start_1: */

		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("metaDataDir"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "_");
		zephir_prepare_virtual_path(&_1$$3, &key, &_2$$3);
		ZEPHIR_INIT_VAR(&path);
		ZEPHIR_CONCAT_VVS(&path, &_0$$3, &_1$$3, ".php");
		ZEPHIR_INIT_VAR(&option);
		ZVAL_BOOL(&option, ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_var_export_ex(&_4$$3, &data);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SVS(&_5$$3, "<?php return ", &_4$$3, "; ");
		zephir_file_put_contents(&_3$$3, &path, &_5$$3);
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwwriteexception", NULL, 461, &option);
			zephir_check_call_status_or_jump(try_end_1);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_OBJ(&_6, EG(exception));
		Z_ADDREF_P(&_6);
		ZEPHIR_INIT_VAR(&_7);
		if (zephir_is_instance_of(&_6, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_7, &_6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "throwwriteexception", NULL, 461, &option);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Throws an exception when the metadata cannot be written
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Stream, throwWriteException)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(option)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);


	if (zephir_is_true(option)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Meta-Data directory cannot be written", "phalcon/Mvc/Model/MetaData/Stream.zep", 93);
		return;
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "Meta-Data directory cannot be written");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_0$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

