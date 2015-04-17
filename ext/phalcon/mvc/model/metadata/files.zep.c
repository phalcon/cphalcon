
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
#include "kernel/file.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/variables.h"


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

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
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
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read) {

	zval *key_param = NULL, *path, *_0, *_1, _2, *_3 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "_", 0);
	zephir_prepare_virtual_path(_1, key, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _1, ".php");
	if ((zephir_file_exists(path TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
		if (zephir_require_zval_ret(&_3, path TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(_3);
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

	zval *key_param = NULL, *data, *path, *_0, *_1, _2, *_3, *_4, *_5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "_", 0);
	zephir_prepare_virtual_path(_1, key, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(path);
	ZEPHIR_CONCAT_VVS(path, _0, _1, ".php");
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	zephir_var_export_ex(_4, &(data) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVS(_5, "<?php return ", _4, "; ");
	zephir_file_put_contents(_3, path, _5 TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Meta-Data directory cannot be written", "phalcon/mvc/model/metadata/files.zep", 86);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

