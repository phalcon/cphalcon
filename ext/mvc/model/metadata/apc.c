
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

#include "mvc/model/metadata/apc.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"

/**
 * Phalcon\Mvc\Model\MetaData\Apc
 *
 * Stores model meta-data in the APC cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apc_fetch('$PMM$') or apc_fetch('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Apc(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_apc_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_apc_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, __construct, arginfo_phalcon_mvc_model_metadata_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Apc initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Apc, mvc_model_metadata_apc, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_apc_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_apc_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_metadata_apc_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_apc_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct){

	zval *options = NULL, *empty_array;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (options && Z_TYPE_P(options) == IS_ARRAY) {
		zval *prefix, *ttl;

		if (phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
			phalcon_update_property_this(this_ptr, SL("_prefix"), prefix TSRMLS_CC);
		}

		if (phalcon_array_isset_string_fetch(&ttl, options, SS("lifetime"))) {
			phalcon_update_property_this(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
		}
	}
	
	PHALCON_ALLOC_GHOST_ZVAL(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_metaData"), empty_array TSRMLS_CC);
}

/**
 * Reads meta-data from APC
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read)
{
	zval *key, *prefix, *apc_key, *data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", prefix, key);
	
	PHALCON_CALL_FUNCTION(&data, "apc_fetch", apc_key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		RETURN_CCTOR(data);
	}
	
	RETURN_MM_NULL();
}

/**
 * Writes the meta-data to APC
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write){

	zval *key, *data, *prefix, *apc_key, *ttl;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(apc_key);
	PHALCON_CONCAT_SVV(apc_key, "$PMM$", prefix, key);
	
	PHALCON_OBS_VAR(ttl);
	phalcon_read_property_this(&ttl, this_ptr, SL("_ttl"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNCTION(NULL, "apc_store", apc_key, data, ttl);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, reset)
{
	zval *meta = phalcon_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	zval *real_key = NULL;

	PHALCON_MM_GROW();

	if (Z_TYPE_P(meta) == IS_ARRAY) {
		HashTable *ht = Z_ARRVAL_P(meta);
		HashPosition hp;
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		for (
			zend_hash_internal_pointer_reset_ex(ht, &hp);
			zend_hash_get_current_key_type_ex(ht, &hp) != HASH_KEY_NON_EXISTENT;
			zend_hash_move_forward_ex(ht, &hp)
		) {
			zval key = phalcon_get_current_key_w(ht, &hp);

			PHALCON_INIT_NVAR(real_key);
			phalcon_concat_svsv(&real_key, SL("$PMM$"), prefix, SL("meta-"), &key, 0 TSRMLS_CC);
			PHALCON_CALL_FUNCTION(NULL, "apc_delete", real_key);
		}
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_apc_ce, getThis(), "reset");
	PHALCON_MM_RESTORE();
}
