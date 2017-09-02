
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
 * $metaData = new Redis(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 6379,
 *         "persistent" => 0,
 *         "statsKey"   => "_PHCM_MM",
 *         "lifetime"   => 172800,
 *         "index"      => 2,
 *     ]
 * );
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

	zval _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, __$null, ttl, _4, _5, _7, _0$$4, _1$$5, _2$$6, _3$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SL("host")))) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "127.0.0.1");
		zephir_array_update_string(options, SL("host"), &_0$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("port")))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		ZVAL_LONG(&_1$$5, 6379);
		zephir_array_update_string(options, SL("port"), &_1$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("persistent")))) {
		ZEPHIR_INIT_VAR(&_2$$6);
		ZVAL_LONG(&_2$$6, 0);
		zephir_array_update_string(options, SL("persistent"), &_2$$6, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(options, SL("statsKey")))) {
		ZEPHIR_INIT_VAR(&_3$$7);
		ZVAL_STRING(&_3$$7, "_PHCM_MM");
		zephir_array_update_string(options, SL("statsKey"), &_3$$7, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&ttl, options, SL("lifetime"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_ttl"), &ttl);
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_cache_backend_redis_ce);
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, SL("_ttl"), PH_NOISY_CC);
	zephir_array_update_string(&_6, SL("lifetime"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 309, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 312, &_5, options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_redis"), &_4);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads metadata from Redis
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, data, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("_redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &key);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		RETURN_CCTOR(&data);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the metadata to Redis
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *key_param = NULL, *data_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_0, this_ptr, SL("_redis"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "save", NULL, 0, &key, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flush Redis data and resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, reset) {

	zend_string *_3$$3;
	zend_ulong _2$$3;
	zval meta, key, realKey, _0$$3, *_1$$3, _4$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&realKey);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&meta);
	zephir_read_property(&meta, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&meta) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_is_iterable(&meta, 0, "phalcon/mvc/model/metadata/redis.zep", 134);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&meta), _2$$3, _3$$3, _1$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$3);
			} else {
				ZVAL_LONG(&key, _2$$3);
			}
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_COPY(&_0$$3, _1$$3);
			ZEPHIR_INIT_NVAR(&realKey);
			ZEPHIR_CONCAT_SV(&realKey, "meta-", &key);
			zephir_read_property(&_4$$4, this_ptr, SL("_redis"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "delete", NULL, 0, &realKey);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_redis_ce, getThis(), "reset", &_5, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("_metaData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("_metaData"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

