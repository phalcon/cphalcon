
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in diles. This adapter is suitable for production
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Files(array(
 *    'annotationsDir' => 'app/cache/annotations/'
 * ));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Files) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, Files, phalcon, annotations_adapter_files, phalcon_annotations_adapter_files_method_entry, 0);

	zend_declare_property_string(phalcon_annotations_adapter_files_ce, SL("_annotationsDir"), "./", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Adapter\Files constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, __construct) {

	zval *options = NULL, *annotationsDir;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&annotationsDir, options, SS("annotationsDir"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_annotationsDir"), annotationsDir TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads parsed annotations from files
 *
 * @param string key
 * @return Phalcon\Annotations\Reflection
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, read) {

	zval *key_param = NULL, *path, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_annotationsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "prepare_virtual_path", key, _1);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _2, ".php");
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "file_exists", path);
	if (zephir_is_true(_1)) {
	}
	RETURN_MM_BOOL(0);

}

/**
 * Writes parsed annotations to files
 *
 * @param string key
 * @param Phalcon\Annotations\Reflection data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, write) {

	zval *key_param = NULL, *data, *path, *_0, *_1, *_2, *_3, *_4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		}

		key = key_param;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_annotationsDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "prepare_virtual_path", key, _1);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _2, ".php");
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p2(_1, "var_export", data, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "<?php return ", _1, "; ");
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "file_put_contents", path, _3);
	if (ZEPHIR_IS_FALSE(_4)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Annotations directory cannot be written");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

