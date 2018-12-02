
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached
 *
 * Stores model meta-data in the Memcache.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *             Memcached::OPT_HASH       => Memcached::HASH_MD5,
 *             Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "lifetime" => 3600,
 *         "prefix"   => "my_",
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Libmemcached) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Libmemcached, phalcon, mvc_model_metadata_libmemcached, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_libmemcached_method_entry, 0);

	zend_declare_property_long(phalcon_mvc_model_metadata_libmemcached_ce, SL("_ttl"), 172800, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_libmemcached_ce, SL("_memcache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_metadata_libmemcached_ce, SL("_metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_metadata_libmemcached_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_MetaData_Libmemcached;
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Libmemcached constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct) {

	zval *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, *ttl = NULL, *_1, *_2, *_4, *_0$$6;

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
	if (!(zephir_array_isset_string(options, SS("servers")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "No servers given in options", "phalcon/mvc/model/metadata/libmemcached.zep", 77);
		return;
	}
	if (zephir_array_isset_string_fetch(&ttl, options, SS("lifetime"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_ttl"), ttl TSRMLS_CC);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_0$$6);
		ZVAL_STRING(_0$$6, "_PHCM_MM", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0$$6, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_cache_backend_libmemcached_ce);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_cache_frontend_data_ce);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_ttl"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("lifetime"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 350, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 351, _2, options);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("_memcache"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Reads metadata from Memcache
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&data, _0, "get", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(data) == IS_ARRAY) {
		RETURN_CCTOR(data);
	}
	RETURN_MM_NULL();

}

/**
 * Writes the metadata to Memcache
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *data, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &data);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "save", NULL, 0, key, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Flush Memcache data and resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, reset) {

	HashTable *_2$$3;
	HashPosition _1$$3;
	zval *meta = NULL, *key = NULL, *realKey = NULL, *_0$$3 = NULL, **_3$$3, *_4$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(meta);
	zephir_read_property_this(&meta, this_ptr, SL("_metaData"), PH_NOISY_CC);
	if (Z_TYPE_P(meta) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_is_iterable(meta, &_2$$3, &_1$$3, 0, 0, "phalcon/mvc/model/metadata/libmemcached.zep", 132);
		for (
		  ; zend_hash_get_current_data_ex(_2$$3, (void**) &_3$$3, &_1$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$3, &_1$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$3, _1$$3);
			ZEPHIR_GET_HVALUE(_0$$3, _3$$3);
			ZEPHIR_INIT_NVAR(realKey);
			ZEPHIR_CONCAT_SV(realKey, "meta-", key);
			_4$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_memcache"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "delete", NULL, 0, realKey);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_libmemcached_ce, getThis(), "reset", &_5, 352);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_Phalcon_Mvc_Model_MetaData_Libmemcached(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_metaData"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("_metaData"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

