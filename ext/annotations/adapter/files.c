
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
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"

/**
 * Phalcon\Annotations\Adapter\Files
 *
 * Stores the parsed annotations in memory. This adapter is the suitable for development/testing
 *
 *<code>
 * $annotations = new \Phalcon\Annotations\Adapter\Files(array(
 *    'metaDataDir' => 'app/cache/metadata/'
 * ));
 *</code>
 */


/**
 * Phalcon\Annotations\Adapter\Files initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Adapter_Files){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Annotations\\Adapter, Files, annotations_adapter_files, "phalcon\\annotations\\adapter", phalcon_annotations_adapter_files_method_entry, 0);

	zend_declare_property_string(phalcon_annotations_adapter_files_ce, SL("_annotationsDir"), "./", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_annotations_adapter_files_ce TSRMLS_CC, 1, phalcon_annotations_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Annotations\Adapter\Files constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, __construct){

	zval *options = NULL, *annotations_dir;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		if (phalcon_array_isset_string(options, SS("annotationsDir"))) {
			PHALCON_OBS_VAR(annotations_dir);
			phalcon_array_fetch_string(&annotations_dir, options, SL("annotationsDir"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_annotationsDir"), annotations_dir TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads parsed annotations from files
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, read){

	zval *key, *annotations_dir, *path, *data;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(annotations_dir);
	phalcon_read_property(&annotations_dir, this_ptr, SL("_annotationsDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, annotations_dir, key, ".php");
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
 * Writes parsed annotations to files
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Annotations_Adapter_Files, write){

	zval *key, *data, *annotations_dir, *path, *to_string;
	zval *export, *php_export, *status;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &key, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(annotations_dir);
	phalcon_read_property(&annotations_dir, this_ptr, SL("_annotationsDir"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, annotations_dir, key, ".php");
	
	PHALCON_INIT_VAR(to_string);
	ZVAL_BOOL(to_string, 1);
	
	PHALCON_INIT_VAR(export);
	PHALCON_CALL_FUNC_PARAMS_2(export, "var_export", data, to_string);
	
	PHALCON_INIT_VAR(php_export);
	PHALCON_CONCAT_SVS(php_export, "<?php return ", export, "; ");
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_FUNC_PARAMS_2(status, "file_put_contents", path, php_export);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Annotations directory cannot be written");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

