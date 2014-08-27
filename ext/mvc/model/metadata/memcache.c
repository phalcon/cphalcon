
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

#include "mvc/model/metadata/memcache.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"
#include "cache/backend/memcache.h"
#include "cache/frontend/data.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"

/**
 * Phalcon\Mvc\Model\MetaData\Memcache
 *
 * Stores model meta-data in the Memcache cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing memcache_get('$PMM$') or memcache_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Memcache(array(
 *		'host' => 'localhost',
 *		'port' => 11211,
 *  	'persistent' => TRUE
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_memcache_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_memcache_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, __construct, arginfo_phalcon_mvc_model_metadata_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Memcache initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memcache){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Memcache, mvc_model_metadata_memcache, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_memcache_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_memcache_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_memcache_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_memcache_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Memcache constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, __construct){

	zval *options;
	zval *host, *port, *lifetime, *persistent, *prefix;
	zval *frontend_data, *memcache, *option;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The options must be an array");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&host, options, SS("host"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "No session host given in options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&port, options, SS("port"))) {
		PHALCON_INIT_VAR(port);
		ZVAL_LONG(port, 11211);
	}

	if (!phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}

	phalcon_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&persistent, options, SS("persistent"))) {
		PHALCON_INIT_VAR(persistent);
		ZVAL_FALSE(persistent);
	}

	if (!phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}

	/* create memcache instance */
	PHALCON_INIT_VAR(option);
	array_init_size(option, 1);

	phalcon_array_update_string(&option, SL("lifetime"), lifetime, PH_COPY);

	PHALCON_INIT_VAR(frontend_data);
	object_init_ex(frontend_data, phalcon_cache_frontend_data_ce);

	PHALCON_CALL_METHOD(NULL, frontend_data, "__construct", option);

	PHALCON_INIT_NVAR(option);
	array_init_size(option, 3);

	phalcon_array_update_string_string(&option, SL("statsKey"), SL("$PMM$"), PH_COPY);

	phalcon_array_update_string(&option, SL("host"), host, PH_COPY);
	phalcon_array_update_string(&option, SL("port"), port, PH_COPY);
	phalcon_array_update_string(&option, SL("persistent"), persistent, PH_COPY);
	phalcon_array_update_string(&option, SL("prefix"), prefix, PH_COPY);

	PHALCON_INIT_VAR(memcache);
	object_init_ex(memcache, phalcon_cache_backend_memcache_ce);

	PHALCON_CALL_METHOD(NULL, memcache, "__construct", frontend_data, option);

	phalcon_update_property_this(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	
	phalcon_update_property_empty_array(this_ptr, SL("_metaData") TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Reads metadata from Memcache
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, read){

	zval *key, *lifetime, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(memcache) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(memcache, "get", key, lifetime);

		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 *  Writes the metadata to Memcache
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, write){

	zval *key, *data, *lifetime, *memcache;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(memcache) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, memcache, "save", key, data, lifetime);	
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, reset)
{
	zval *memcache;

	PHALCON_MM_GROW();

	memcache = phalcon_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(memcache) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, memcache, "flush");	
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_memcache_ce, getThis(), "reset");

	PHALCON_MM_RESTORE();
}
