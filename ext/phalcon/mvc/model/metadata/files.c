
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
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
 * Phalcon\Mvc\Model\MetaData\Files
 *
 * Stores model meta-data in PHP files.
 *
 *<code>
 * $metaData = new \Phalcon\Mvc\Model\Metadata\Files(array(
 *    'metaDataDir' => 'app/cache/metadata/'
 * ));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Files, phalcon, mvc_model_metadata_files, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_files_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_files_ce, SL("_metaDataDir"), "./", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_files_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Files constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, __construct) {

	zval *options = NULL, *metaDataDir, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(options) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&metaDataDir, options, SS("metaDataDir"), 1 TSRMLS_CC)) {
			zephir_update_property_this(this_ptr, SL("_metaDataDir"), metaDataDir TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_metaData"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads meta-data from files
 *
 * @param string key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read) {

	zval *key_param = NULL, *path, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "phalcon_prepare_virtual_path", key, _1);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _2, ".php");
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p1(_1, "file_exists", path);
	if (zephir_is_true(_1)) {
		RETURN_MM_BOOL((0 == 1));
	}
	RETURN_MM_NULL();

}

/**
 * Writes the meta-data to files
 *
 * @param string key
 * @param array data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write) {

	zval *key_param = NULL, *data, *path, *_0, *_1, *_2, *_3, *_4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

		if (Z_TYPE_P(key_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		key = key_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "_", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p2(_2, "phalcon_prepare_virtual_path", key, _1);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _2, ".php");
	ZEPHIR_INIT_BNVAR(_1);
	zephir_call_func_p2(_1, "var_export", data, ZEPHIR_GLOBAL(global_true));
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "<?php return ", _1, "; ");
	ZEPHIR_INIT_VAR(_4);
	zephir_call_func_p2(_4, "file_put_contents", path, _3);
	if (ZEPHIR_IS_FALSE(_4)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Meta-Data directory cannot be written");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

