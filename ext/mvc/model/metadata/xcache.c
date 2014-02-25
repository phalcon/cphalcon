
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#include "mvc/model/metadata/xcache.h"
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
 * Phalcon\Mvc\Model\MetaData\Xcache
 *
 * Stores model meta-data in the XCache cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing xcache_get('$PMM$') or xcache_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Xcache(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_xcache_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, __construct, arginfo_phalcon_mvc_model_metadata_xcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Xcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Xcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Xcache, mvc_model_metadata_xcache, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_xcache_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_model_metadata_xcache_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_metadata_xcache_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_xcache_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Xcache constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, __construct){

	zval *options = NULL, *prefix, *ttl, *empty_array;

	phalcon_fetch_params(0, 0, 1, &options);
	
	if (options && Z_TYPE_P(options) == IS_ARRAY) {
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
 * Reads metadata from XCache
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, read){

	zval *key, *prefix, *xc_key, *data = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(xc_key);
	PHALCON_CONCAT_SVV(xc_key, "$PMM$", prefix, key);
	
	PHALCON_CALL_FUNCTION(&data, "xcache_get", xc_key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		RETURN_CCTOR(data);
	}
	
	RETURN_MM_NULL();
}

/**
 *  Writes the metadata to XCache
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, write){

	zval *key, *data, *prefix, *xc_key, *ttl;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(xc_key);
	PHALCON_CONCAT_SVV(xc_key, "$PMM$", prefix, key);
	
	PHALCON_OBS_VAR(ttl);
	phalcon_read_property_this(&ttl, this_ptr, SL("_ttl"), PH_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNCTION(NULL, "xcache_set", xc_key, data, ttl);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, reset)
{
	zval *meta = phalcon_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY TSRMLS_CC);
	zval *real_key = NULL;

	PHALCON_MM_GROW();

	if (SUCCESS == phalcon_function_exists_ex(SL("xcache_unset_by_prefix") TSRMLS_CC)) {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

		PHALCON_INIT_VAR(real_key);
		phalcon_concat_svs(&real_key, SL("$PMM$"), prefix, SL("meta-"), 0 TSRMLS_CC);
		PHALCON_CALL_FUNCTION(NULL, "xcache_unset_by_prefix", real_key);
	}
	else if (Z_TYPE_P(meta) == IS_ARRAY) {
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
			PHALCON_CALL_FUNCTION(NULL, "xcache_unset", real_key);
		}
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_xcache_ce, getThis(), "reset");
	PHALCON_MM_RESTORE();
}
