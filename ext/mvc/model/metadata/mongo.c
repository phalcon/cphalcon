
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

#include "mvc/model/metadata/mongo.h"
#include "mvc/model/metadata.h"
#include "mvc/model/metadatainterface.h"
#include "mvc/model/exception.h"
#include "cache/backend/mongo.h"
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
 * Phalcon\Mvc\Model\MetaData\Mongo
 *
 * Stores model meta-data in the Mongo cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing mongo_get('$PMM$') or mongo_get('$PMM$my-app-id')
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Mongo(array(
 *		//'mongo' => new MongoClient(),
 *		'server' => 'mongodb://localhost',
 *		'db' => 'caches',
 *		'collection' => 'metadata',
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400
 *	));
 *</code>
 */
zend_class_entry *phalcon_mvc_model_metadata_mongo_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_mongo___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_mongo_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Mongo, __construct, arginfo_phalcon_mvc_model_metadata_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Mongo, read, arginfo_phalcon_mvc_model_metadatainterface_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Mongo, write, arginfo_phalcon_mvc_model_metadatainterface_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Mongo, reset, arginfo_phalcon_mvc_model_metadatainterface_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Mongo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Mongo){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Mongo, mvc_model_metadata_mongo, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_mongo_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_mongo_ce, SL("_lifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_metadata_mongo_ce, SL("_mongo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_mongo_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\MetaData\Mongo constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, __construct){

	zval *options, *lifetime, *prefix;
	zval *frontend_data, *mongo, *option;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The options must be an array");
		return;
	}

	PHALCON_SEPARATE_PARAM(options);
	
	if (!phalcon_array_isset_string(options, SS("mongo"))) {
		if (!phalcon_array_isset_string(options, SS("server"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The parameter 'server' is required");
			return;
		}
	}

	if (!phalcon_array_isset_string(options, SS("db"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The parameter 'db' is required");
		return;
	}

	if (!phalcon_array_isset_string(options, SS("collection"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The parameter 'collection' is required");
		return;
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

	PHALCON_INIT_VAR(option);
	array_init_size(option, 1);

	phalcon_array_update_string(&option, SL("lifetime"), lifetime, PH_COPY);

	PHALCON_INIT_VAR(frontend_data);
	object_init_ex(frontend_data, phalcon_cache_frontend_data_ce);

	PHALCON_CALL_METHOD(NULL, frontend_data, "__construct", option);

	phalcon_array_update_string_string(&options, SL("statsKey"), SL("$PMM$"), PH_COPY);;

	PHALCON_INIT_VAR(mongo);
	object_init_ex(mongo, phalcon_cache_backend_mongo_ce);

	PHALCON_CALL_METHOD(NULL, mongo, "__construct", frontend_data, options);

	phalcon_update_property_this(this_ptr, SL("_mongo"), mongo TSRMLS_CC);
	
	phalcon_update_property_empty_array(this_ptr, SL("_metaData") TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Reads metadata from Mongo
 *
 * @param  string $key
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, read){

	zval *key, *lifetime, *mongo;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	mongo = phalcon_fetch_nproperty_this(this_ptr, SL("_mongo"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(mongo) == IS_OBJECT) {
		PHALCON_RETURN_CALL_METHOD(mongo, "get", key, lifetime);

		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 *  Writes the metadata to Mongo
 *
 * @param string $key
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, write){

	zval *key, *data, *lifetime, *mongo;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &key, &data);
	
	lifetime = phalcon_fetch_nproperty_this(this_ptr, SL("_lifetime"), PH_NOISY TSRMLS_CC);
	mongo = phalcon_fetch_nproperty_this(this_ptr, SL("_mongo"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(mongo) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, mongo, "save", key, data, lifetime);	
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Mongo, reset)
{
	zval *mongo;

	PHALCON_MM_GROW();

	mongo = phalcon_fetch_nproperty_this(this_ptr, SL("_mongo"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(mongo) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, mongo, "flush");	
	}

	PHALCON_CALL_PARENT(NULL, phalcon_mvc_model_metadata_mongo_ce, getThis(), "reset");

	PHALCON_MM_RESTORE();
}
