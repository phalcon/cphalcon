
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
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

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


/**
 * Phalcon\Mvc\Model\MetaData\Files initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Files, mvc_model_metadata_files, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_files_method_entry, 0);

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

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string_fetch(&meta_data_dir, options, SS("metaDataDir"))) {
			phalcon_update_property_this(this_ptr, SL("_metaDataDir"), meta_data_dir TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from files
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read){

	zval *key, *separator, *meta_data_dir, *virtual_key;
	zval *path, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	PHALCON_INIT_VAR(separator);
	ZVAL_STRING(separator, "_", 1);
	
	PHALCON_OBS_VAR(meta_data_dir);
	phalcon_read_property_this(&meta_data_dir, this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(virtual_key);
	phalcon_prepare_virtual_path(virtual_key, key, separator TSRMLS_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, virtual_key, ".php");
	
	if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(data);
		if (phalcon_require_ret(data, path TSRMLS_CC) == FAILURE) {
			RETURN_MM();
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

	zval *key, *data, *separator, *meta_data_dir, *virtual_key;
	zval *path, *export, *php_export, *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	PHALCON_INIT_VAR(separator);
	ZVAL_STRING(separator, "_", 1);
	
	PHALCON_OBS_VAR(meta_data_dir);
	phalcon_read_property_this(&meta_data_dir, this_ptr, SL("_metaDataDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(virtual_key);
	phalcon_prepare_virtual_path(virtual_key, key, separator TSRMLS_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, virtual_key, ".php");
	
	PHALCON_INIT_VAR(export);
	phalcon_call_func_p2(export, "var_export", data, PHALCON_GLOBAL(z_true));
	
	PHALCON_INIT_VAR(php_export);
	PHALCON_CONCAT_SVS(php_export, "<?php return ", export, "; ");
	
	PHALCON_INIT_VAR(status);
	phalcon_file_put_contents(status, path, php_export TSRMLS_CC);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Meta-Data directory cannot be written");
		return;
	}
	
	PHALCON_MM_RESTORE();
}
