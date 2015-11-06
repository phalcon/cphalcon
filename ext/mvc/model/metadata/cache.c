
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
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "mvc/model/metadata/cache.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"

/**
 * Phalcon\Mvc\Model\MetaData\Cache
 *
 * Stores model meta-data in the Cache cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing cache_get('$PMM$') or cache_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Cache(array(
 *		'service' => 'cache', // Service Name
 *		'lifetime' => 86400, // Service Name
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_cache_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, _getCache);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_cache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_cache_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Cache, __construct, arginfo_phalcon_mvc_model_metadata_cache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Cache, _getCache, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Cache, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Cache, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Cache, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Cache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Cache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Cache, mvc_model_metadata_cache, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_cache_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_cache_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_cache_ce, SL("_cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_cache_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Cache constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, __construct){

	zval *options = NULL, *service, *lifetime;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}

	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The options must be an array");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&service, options, SS("service"))) {
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "cache", 1);
	}

	phalcon_update_property_this(this_ptr, SL("_cache"), service TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}

	phalcon_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);

	phalcon_update_property_empty_array(this_ptr, SL("_metaData") TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, _getCache){

	zval *dependency_injector = NULL, *cache, *tmp = NULL;

	PHALCON_MM_GROW();;

	cache = phalcon_fetch_nproperty_this(this_ptr, SL("_cache"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(cache) == IS_STRING) {
		PHALCON_CALL_METHOD(&dependency_injector, this_ptr, "getdi");

		PHALCON_CALL_METHOD(&tmp, dependency_injector, "getshared", cache);

		phalcon_update_property_this(this_ptr, SL("_cache"), tmp TSRMLS_CC);

		RETURN_CTOR(tmp);
	}

	RETURN_CTOR(cache);
}

/**
 * Reads metadata from Cache
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, read){

	zval *key, *cache = NULL, *lifetime;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);

	PHALCON_CALL_METHOD(&cache, this_ptr, "_getcache");

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(cache) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(cache, "get", key, lifetime);
		RETURN_MM();
	}

	RETURN_MM_NULL();
}

/**
 *  Writes the metadata to Cache
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, write){

	zval *key, *data, *cache = NULL, *lifetime;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);

	PHALCON_CALL_METHOD(&cache, this_ptr, "_getcache");

	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(cache) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, cache, "save", key, data, lifetime);	
	}

	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Cache, reset)
{
	zval *cache = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&cache, this_ptr, "_getcache");

	if (Z_TYPE_P(cache) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, cache, "flush");	
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_cache_ce, getThis(), "reset");

	PHALCON_MM_RESTORE();
}
