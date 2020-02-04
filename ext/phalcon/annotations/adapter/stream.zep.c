
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Stores the parsed annotations in files. This adapter is suitable for production
 *
 *```php
 * use Phalcon\Annotations\Adapter\Stream;
 *
 * $annotations = new Stream(
 *     [
 *         "annotationsDir" => "app/cache/annotations/",
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Stream) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Stream, phalcon, annotations_adapter_stream, phalcon_annotations_adapter_abstractadapter_ce, phalcon_annotations_adapter_stream_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_annotations_adapter_stream_ce, SL("annotationsDir"), "./", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * @param array options = [
 *     'annotationsDir' => 'phalconDir'
 * ]
 *
 * Phalcon\Annotations\Adapter\Stream constructor
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, annotationsDir;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&annotationsDir);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (zephir_array_isset_string_fetch(&annotationsDir, &options, SL("annotationsDir"), 1)) {
		zephir_update_property_zval(this_ptr, SL("annotationsDir"), &annotationsDir);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads parsed annotations from files
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, read) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, __$false, contents, _0, _1, _2, _3, _4, _5, _6;
	zval key, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("annotationsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_prepare_virtual_path(&_1, &key, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VVS(&_3, &_0, &_1, ".php");
	zephir_get_strval(&path, &_3);
	if (!((zephir_file_exists(&path) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&contents);
	zephir_file_get_contents(&contents, &path);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&contents))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_GLOBAL(warning).enable = zend_is_true(&__$false);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_create_closure_ex(&_4, NULL, phalcon_2__closure_ce, SL("__invoke"));
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 85, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "unserialize", NULL, 15, &contents);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&contents, &_6);
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 87);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_GLOBAL(warning).enable)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Cannot read annotation data", "/home/nikos/Work/niden/cphalcon/phalcon/Annotations/Adapter/Stream.zep", 92);
		return;
	}
	RETURN_CCTOR(&contents);

}

/**
 * Writes parsed annotations to files
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Stream, write) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, data_sub, code, _0, _1, _2, _3, _4;
	zval key, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

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


	zephir_read_property(&_0, this_ptr, SL("annotationsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_prepare_virtual_path(&_1, &key, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VVS(&_3, &_0, &_1, ".php");
	zephir_get_strval(&path, &_3);
	ZEPHIR_CALL_FUNCTION(&code, "serialize", NULL, 13, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_file_put_contents(&_4, &path, &code);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_annotations_exception_ce, "Annotations directory cannot be written", "/home/nikos/Work/niden/cphalcon/phalcon/Annotations/Adapter/Stream.zep", 113);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

