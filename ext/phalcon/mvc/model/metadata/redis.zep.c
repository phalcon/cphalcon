
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
 *<code>
 * use Phalcon\Mvc\Model\Metadata\Redis;
 *
 * $metaData = new Redis([
 *     'host'       => '127.0.0.1',
 *     'port'       => 6379,
 *     'persistent' => 0,
 *     'statsKey'   => '_PHCM_MM',
 *     'lifetime'   => 172800,
 *     'index'      => 2,
 * ]);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Redis, phalcon, mvc_model_metadata_redis, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_redis_method_entry, 0);

	zend_declare_property_long(phalcon_mvc_model_metadata_redis_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_redis_ce, SL("_redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_redis_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_metadata_redis_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis;
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Redis constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, __construct) {

	zval *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *ttl = NULL, *_4, *_5, *_7, *_0$$4, *_1$$5, *_2$$6, *_3$$7;

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
		ZEPHIR_INIT_VAR(_0$$4);
		ZVAL_STRING(_0$$4, "127.0.0.1", 1);
		zephir_array_update_string(&options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("port")))) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, 6379);
		zephir_array_update_string(&options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("persistent")))) {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_LONG(_2$$6, 0);
		zephir_array_update_string(&options, SL("persistent"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_3$$7);
		ZVAL_STRING(_3$$7, "_PHCM_MM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_3$$7, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&ttl, options, SS("lifetime"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_ttl"), ttl TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, phalcon_cache_backend_redis_ce);
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_this(&_7, this_ptr, SL("_ttl"), PH_NOISY_CC);
	zephir_array_update_string(&_6, SL("lifetime"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 330, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 334, _5, options);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_redis"), _4 TSRMLS_CC);
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

	HashTable *_2$$3;
	HashPosition _1$$3;
	zval *meta = NULL, *key = NULL, *realKey = NULL, *_0$$3 = NULL, **_3$$3, *_4$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(meta);
	zephir_read_property_this(&meta, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(meta) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_is_iterable(meta, &_2$$3, &_1$$3, 0, 0, "phalcon/mvc/model/metadata/redis.zep", 132);
		for (
		  ; zephir_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(_0$$3, _3$$3);
			ZEPHIR_INIT_NVAR(realKey);
			ZEPHIR_CONCAT_SV(realKey, "meta-", key);
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_redis"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "delete", NULL, 0, realKey);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_redis_ce, this_ptr, "reset", &_5, 332);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_metaData"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

