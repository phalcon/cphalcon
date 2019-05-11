
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
#include "kernel/require.h"
#include "kernel/variables.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in files. This adapter is suitable for production
 *
 *<code>
 * use Phalcon\Annotations\Adapter\Files;
 *
 * $annotations = new Files(
 *     [
 *         "annotationsDir" => "app/cache/annotations/",
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Files) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Files, phalcon, annotations_adapter_files, phalcon_annotations_adapter_ce, phalcon_annotations_adapter_files_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_annotations_adapter_files_ce, SL("annotationsDir"), "./", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Adapter\Files constructor
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, __construct) {

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
PHP_METHOD(Phalcon_Annotations_Adapter_Files, read) {

	zval *key_param = NULL, _0, _1, _2, _3, _4;
	zval key, path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	zephir_read_property(&_0, this_ptr, SL("annotationsDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	zephir_prepare_virtual_path(&_1, &key, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VVS(&_3, &_0, &_1, ".php");
	zephir_get_strval(&path, &_3);
	if (!((zephir_file_exists(&path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, &path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&_4);

}

/**
 * Writes parsed annotations to files
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, write) {

	zval *key_param = NULL, *data, data_sub, _0, _1, _2, _3, _4, _5, _6;
	zval key, path, code;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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
	zephir_prepare_virtual_path(&_1, &key, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VVS(&_3, &_0, &_1, ".php");
	zephir_get_strval(&path, &_3);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_var_export_ex(&_4, data TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "<?php return ", &_4, "; ");
	zephir_get_strval(&code, &_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_file_put_contents(&_6, &path, &code TSRMLS_CC);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_6))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_annotations_exception_ce, "Annotations directory cannot be written", "phalcon/Annotations/Adapter/Files.zep", 85);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

