
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Model\MetaData\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *
 *<code>
 *	$metaData = new Phalcon\Mvc\Model\Metadata\Redis(array(
 *		'prefix' => 'my-app-id',
 *		'lifetime' => 86400,
 *		'host' => 'localhost',
 *		'port' => 6379,
 *  	'persistent' => false
 *	));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Redis, phalcon, mvc_model_metadata_redis, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_redis_method_entry, 0);

	zend_declare_property_long(phalcon_mvc_model_metadata_redis_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_metadata_redis_ce TSRMLS_CC, 1, phalcon_mvc_model_metadatainterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Redis constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zval *options = NULL, *ttl, *_0 = NULL, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SS("host")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 6379);
		zephir_array_update_string(&options, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 0);
		zephir_array_update_string(&options, SL("persistent"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "_PHCM_MM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&ttl, options, SS("lifetime"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_0);
	object_init_ex(_0, phalcon_cache_backend_redis_ce);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_ttl"), PH_NOISY_CC);
	zephir_array_update_string(&_2, SL("lifetime"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 318, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 322, _1, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_redis"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("_metaData"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads metadata from Redis
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, read) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, _0, "get", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(data) == IS_ARRAY) {
		RETURN_CCTOR(data);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the metadata to Redis
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, 0, key, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flush Redis data and resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, reset) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *meta, *key = NULL, *realKey = NULL, *_0 = NULL, **_3, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(meta);
	zephir_read_property_this(&meta, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(meta) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		zephir_is_iterable(meta, &_2, &_1, 0, 0, "phalcon/mvc/model/metadata/redis.zep", 131);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(key, _2, _1);
			ZEPHIR_GET_HVALUE(_0, _3);
			ZEPHIR_INIT_NVAR(realKey);
			ZEPHIR_CONCAT_SV(realKey, "meta-", key);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _4, "delete", NULL, 0, realKey);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_redis_ce, this_ptr, "reset", &_5, 320);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

