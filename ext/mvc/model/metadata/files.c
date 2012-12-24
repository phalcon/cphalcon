
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\MetaData\Files
 *
 * Stores model meta-data in PHP files.
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Files(array(
 *    'metaDataDir' => 'app/cache/metadata/'
 * ));
 *</code>
 */


/**
 * Phalcon\Mvc\Model\MetaData\Files initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Files, mvc_model_metadata_files, "phalcon\\mvc\\model\\metadata", phalcon_mvc_model_metadata_files_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_files_ce, SL("_metaDataDir"), "./", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_files_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Files constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, __construct){

	zval *options = NULL, *meta_data_dir, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("metaDataDir"))) {
			PHALCON_OBS_VAR(meta_data_dir);
			phalcon_array_fetch_string(&meta_data_dir, options, SL("metaDataDir"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_metaDataDir"), meta_data_dir TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from files
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read){

	zval *key, *meta_data_dir, *path, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(meta_data_dir);
	phalcon_read_property(&meta_data_dir, this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, key, ".php");
	if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(data);
		if (phalcon_require_ret(data, path TSRMLS_CC) == FAILURE) {
			return;
		}
		RETURN_CCTOR(data);
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes the meta-data to files
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write){

	zval *key, *data, *meta_data_dir, *path, *to_string;
	zval *export, *php_export, *status;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(meta_data_dir);
	phalcon_read_property(&meta_data_dir, this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, key, ".php");
	
	PHALCON_INIT_VAR(to_string);
	ZVAL_BOOL(to_string, 1);
	
	PHALCON_INIT_VAR(export);
	PHALCON_CALL_FUNC_PARAMS_2(export, "var_export", data, to_string);
	
	PHALCON_INIT_VAR(php_export);
	PHALCON_CONCAT_SVS(php_export, "<?php return ", export, "; ");
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_FUNC_PARAMS_2(status, "file_put_contents", path, php_export);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Meta-data directory can't be written");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

