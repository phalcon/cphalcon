
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/metadata/files.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"

#include <ext/standard/php_smart_str.h>
#include <ext/standard/php_var.h>
#include <ext/spl/spl_directory.h>

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
zend_class_entry *phalcon_mvc_model_metadata_files_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_files_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, __construct, arginfo_phalcon_mvc_model_metadata_files___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	phalcon_fetch_params(0, 0, 1, &options);

	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		if (phalcon_array_isset_string_fetch(&meta_data_dir, options, SS("metaDataDir"))) {
			phalcon_update_property_this(this_ptr, SL("_metaDataDir"), meta_data_dir TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
}

/**
 * Reads meta-data from files
 *
 * @param string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read){

	zval **key, *meta_data_dir, *virtual_key;
	zval *path, *data = NULL;

	phalcon_fetch_params_ex(1, 0, &key);
	PHALCON_ENSURE_IS_STRING(key);

	PHALCON_MM_GROW();

	meta_data_dir = phalcon_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(virtual_key);
	phalcon_prepare_virtual_path_ex(virtual_key, Z_STRVAL_PP(key), Z_STRLEN_PP(key), '_' TSRMLS_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, virtual_key, ".php");
	
	if (phalcon_file_exists(path TSRMLS_CC) == SUCCESS) {
		RETURN_MM_ON_FAILURE(phalcon_require_ret(&data, Z_STRVAL_P(path) TSRMLS_CC));
		RETVAL_ZVAL(data, 1, 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Writes the meta-data to files
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write){

	zval **key, **data, *meta_data_dir, *virtual_key;
	zval *path, *php_export, *status;
	smart_str exp = { NULL, 0, 0 };

	phalcon_fetch_params_ex(2, 0, &key, &data);

	PHALCON_MM_GROW();

	meta_data_dir = phalcon_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(virtual_key);
	phalcon_prepare_virtual_path_ex(virtual_key, Z_STRVAL_PP(key), Z_STRLEN_PP(key), '_' TSRMLS_CC);
	
	PHALCON_INIT_VAR(path);
	PHALCON_CONCAT_VVS(path, meta_data_dir, virtual_key, ".php");
	
	smart_str_appends(&exp, "<?php return ");
	php_var_export_ex(data, 0, &exp TSRMLS_CC);
	smart_str_appendc(&exp, ';');
	smart_str_0(&exp);
	
	PHALCON_INIT_VAR(php_export);
	ZVAL_STRINGL(php_export, exp.c, exp.len, 0);

	PHALCON_INIT_VAR(status);
	phalcon_file_put_contents(status, path, php_export TSRMLS_CC);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Meta-Data directory cannot be written");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, reset)
{
	zval *metadata_dir, *pattern, *iterator, *itkey = NULL;
	zend_object_iterator *it;

	PHALCON_MM_GROW();

	metadata_dir = phalcon_fetch_nproperty_this(this_ptr, SL("_metaDataDir"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(pattern);
	PHALCON_CONCAT_VS(pattern, metadata_dir, "meta-*.php");

	PHALCON_INIT_VAR(iterator);
	object_init_ex(iterator, spl_ce_GlobIterator);
	PHALCON_CALL_METHOD(NULL, iterator, "__construct", pattern);

	it = spl_ce_GlobIterator->get_iterator(spl_ce_GlobIterator, iterator, 0 TSRMLS_CC);
	it->funcs->rewind(it TSRMLS_CC);
	while (SUCCESS == it->funcs->valid(it TSRMLS_CC) && !EG(exception)) {
		zval dummy;
#if PHP_VERSION_ID < 50500
		char *str_key;
		uint str_key_len;
		ulong int_key;

		int key_type = it->funcs->get_current_key(it, &str_key, &str_key_len, &int_key TSRMLS_CC);
		if (likely(key_type == HASH_KEY_IS_STRING)) {
			PHALCON_INIT_NVAR(itkey);
			/* Note that str_key_len includes the trailing zero */
			ZVAL_STRINGL(itkey, str_key, str_key_len-1, 1);
			phalcon_unlink(&dummy, itkey TSRMLS_CC);
		}
#else
		PHALCON_INIT_NVAR(itkey);
		it->funcs->get_current_key(it, itkey TSRMLS_CC);
		phalcon_unlink(&dummy, itkey TSRMLS_CC);
#endif

		it->funcs->move_forward(it TSRMLS_CC);
	}

	it->funcs->dtor(it TSRMLS_CC);

	if (!EG(exception)) {
		PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_files_ce, getThis(), "reset");
	}

	PHALCON_MM_RESTORE();
}
