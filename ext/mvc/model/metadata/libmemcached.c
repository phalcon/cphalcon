
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

#include "mvc/model/metadata/libmemcached.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"
#include "cache/backend/libmemcached.h"
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
 * Phalcon\Mvc\Model\MetaData\Libmemcached
 *
 * Stores model meta-data in the Libmemcached cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing libmemcached_get('$PMM$') or libmemcached_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Libmemcached(array(
 *     'servers' => array(
 *         array('host' => 'localhost', 'port' => 11211, 'weight' => 1),
 *     ),
 *     'client' => array(
 *         Memcached::OPT_HASH => Memcached::HASH_MD5,
 *         Memcached::OPT_PREFIX_KEY => 'prefix.',
 *     ),
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_libmemcached_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_libmemcached___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_libmemcached_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct, arginfo_phalcon_mvc_model_metadata_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Libmemcached){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Libmemcached, mvc_model_metadata_libmemcached, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_libmemcached_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_libmemcached_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_libmemcached_ce, SL("_libmemcached"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_libmemcached_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct){

	zval *options = NULL;
	zval *servers, *client, *lifetime, *prefix;
	zval *frontend_data, *libmemcached, *option;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The options must be an array");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&servers, options, SS("servers"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "No servers given in options");
		return;
	}

	if (!phalcon_array_isset_string_fetch(&client, options, SS("client"))) {
		client = NULL;
	}

	if (!phalcon_array_isset_string_fetch(&lifetime, options, SS("lifetime"))) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_LONG(lifetime, 8600);
	}

	phalcon_update_property_this(this_ptr, SL("_lifetime"), lifetime TSRMLS_CC);

	if (!phalcon_array_isset_string_fetch(&prefix, options, SS("prefix"))) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	}

	/* create libmemcached instance */
	PHALCON_INIT_VAR(option);
	array_init_size(option, 1);

	phalcon_array_update_string(&option, SL("lifetime"), lifetime, PH_COPY);

	PHALCON_INIT_VAR(frontend_data);
	object_init_ex(frontend_data, phalcon_cache_frontend_data_ce);

	PHALCON_CALL_METHOD(NULL, frontend_data, "__construct", option);

	PHALCON_INIT_NVAR(option);
	array_init(option);

	phalcon_array_update_string_string(&option, SL("statsKey"), SL("$PMM$"), PH_COPY);

	phalcon_array_update_string(&option, SL("servers"), servers, PH_COPY);
	if (client) {
		phalcon_array_update_string(&option, SL("client"), client, PH_COPY);
	}
	phalcon_array_update_string(&option, SL("prefix"), prefix, PH_COPY);

	PHALCON_INIT_VAR(libmemcached);
	object_init_ex(libmemcached, phalcon_cache_backend_libmemcached_ce);

	PHALCON_CALL_METHOD(NULL, libmemcached, "__construct", frontend_data, option);

	phalcon_update_property_this(this_ptr, SL("_libmemcached"), libmemcached TSRMLS_CC);
	
	phalcon_update_property_empty_array(this_ptr, SL("_metaData") TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Reads metadata from Libmemcached
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, read){

	zval *key, *lifetime, *libmemcached;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(libmemcached, "get", key, lifetime);

		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 *  Writes the metadata to Libmemcached
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, write){

	zval *key, *data, *lifetime, *libmemcached;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, libmemcached, "save", key, data, lifetime);	
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, reset)
{
	zval *libmemcached;

	PHALCON_MM_GROW();

	libmemcached = phalcon_fetch_nproperty_this(this_ptr, SL("_libmemcached"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(libmemcached) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, libmemcached, "flush");	
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_libmemcached_ce, getThis(), "reset");

	PHALCON_MM_RESTORE();
}
