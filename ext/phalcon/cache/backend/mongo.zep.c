
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


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
/**
 * Phalcon\Cache\Backend\Mongo
 *
 * Allows to cache output fragments, PHP data or raw data to a MongoDb backend
 *
 *<code>
 *
 * // Cache data for 2 days
 * $frontCache = new \Phalcon\Cache\Frontend\Base64(array(
 *		"lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new \Phalcon\Cache\Backend\Mongo($frontCache, array(
 *		'server' => "mongodb://localhost",
 *      'db' => 'caches',
 *		'collection' => 'images'
 * ));
 *
 * //Cache arbitrary data
 * $cache->save('my-data', file_get_contents('some-image.jpg'));
 *
 * //Get data
 * $data = $cache->get('my-data');
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Mongo) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Mongo, phalcon, cache_backend_mongo, phalcon_cache_backend_ce, phalcon_cache_backend_mongo_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_mongo_ce, SL("_collection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_mongo_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Mongo constructor
 *
 * @param Phalcon\Cache\FrontendInterface $frontend
 * @param array $options
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *frontend, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(frontend, phalcon_cache_frontendinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'frontend' must be an instance of 'Phalcon\\Cache\\FrontendInterface'", "", 0);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("mongo")))) {
		if (!(zephir_array_isset_string(options, SS("server")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'server' is required", "phalcon/cache/backend/mongo.zep", 65);
			return;
		}
	}
	if (!(zephir_array_isset_string(options, SS("db")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'db' is required", "phalcon/cache/backend/mongo.zep", 70);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("collection")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required", "phalcon/cache/backend/mongo.zep", 74);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_mongo_ce, this_ptr, "__construct", &_0, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zend_bool _0;
	zval *options, *mongo = NULL, *server, *database, *collection, *mongoCollection, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(mongoCollection);
	zephir_read_property_this(&mongoCollection, this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(mongoCollection) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(mongo);
		if (zephir_array_isset_string_fetch(&mongo, options, SS("mongo"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(mongo) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance", "phalcon/cache/backend/mongo.zep", 98);
				return;
			}
		} else {
			ZEPHIR_OBS_VAR(server);
			zephir_array_fetch_string(&server, options, SL("server"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 104 TSRMLS_CC);
			_0 = !zephir_is_true(server);
			if (!(_0)) {
				_0 = Z_TYPE_P(server) != IS_STRING;
			}
			if (_0) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string", "phalcon/cache/backend/mongo.zep", 106);
				return;
			}
			ZEPHIR_INIT_NVAR(mongo);
			_1 = zend_fetch_class(SL("MongoClient"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongo, _1);
			if (zephir_has_constructor(mongo TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongo, "__construct", NULL);
				zephir_check_call_status();
			}
		}
		ZEPHIR_OBS_VAR(database);
		zephir_array_fetch_string(&database, options, SL("db"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 114 TSRMLS_CC);
		_0 = !zephir_is_true(database);
		if (!(_0)) {
			_0 = Z_TYPE_P(database) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db", "phalcon/cache/backend/mongo.zep", 116);
			return;
		}
		ZEPHIR_OBS_VAR(collection);
		zephir_array_fetch_string(&collection, options, SL("collection"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 122 TSRMLS_CC);
		_0 = !zephir_is_true(collection);
		if (!(_0)) {
			_0 = Z_TYPE_P(collection) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection", "phalcon/cache/backend/mongo.zep", 124);
			return;
		}
		ZEPHIR_CALL_METHOD(&_2, mongo, "selectdb", NULL, database);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _2, "selectcollection", NULL, collection);
		zephir_check_call_status();
	}
	RETURN_CCTOR(mongoCollection);

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *conditions, *document = NULL, *cachedContent, *_0, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	ZEPHIR_CALL_FUNCTION(&_2, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("$gt"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&document, _2, "findone", NULL, conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(document) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC)) {
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CCTOR(cachedContent);
			}
			ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, cachedContent);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupt", "phalcon/cache/backend/mongo.zep", 164);
			return;
		}
	}
	RETURN_MM_NULL();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastkey = NULL, *prefix, *frontend, *cachedContent = NULL, *tmp, *ttl = NULL, *collection = NULL, *timestamp, *conditions, *document = NULL, *preparedContent = NULL, *isBuffering = NULL, *data, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	if (!(zephir_is_true(keyName))) {
		ZEPHIR_OBS_VAR(lastkey);
		zephir_read_property_this(&lastkey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastkey);
		ZEPHIR_CONCAT_VV(lastkey, prefix, keyName);
	}
	if (!(zephir_is_true(lastkey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/mongo.zep", 195);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, cachedContent);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime",  NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (zephir_get_numberval(_0) + zephir_get_intval(ttl)));
	zephir_array_update_string(&conditions, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, collection, "findone", NULL, conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(document) == IS_ARRAY) {
		zephir_array_update_string(&document, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&document, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&document, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(NULL, collection, "save", NULL, document);
		zephir_check_call_status();
	} else {
		zephir_array_update_string(&data, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&data, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&data, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(NULL, collection, "save", NULL, data);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering",  NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(stopBuffer)) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *_0 = NULL, *_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, keyName);
	zephir_array_update_string(&_1, SL("key"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "rand", &_5);
	zephir_check_call_status();
	if ((zephir_get_intval(_4) % 100) == 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gc", NULL);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys) {

	HashTable *_8;
	HashPosition _7;
	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *prefix = NULL, *fields, *conditions, *keys, *index = NULL, *key = NULL, *_0, *_2, *_4 = NULL, *_5 = NULL, *_6 = NULL, **_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(fields);
	array_init_size(fields, 2);
	add_assoc_long_ex(fields, SS("key"), 1);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	if (zephir_is_true(prefix)) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("MongoRegex"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SVS(_2, "/^", prefix, "/");
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_call_status();
		}
		zephir_array_update_string(&conditions, SL("key"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	ZEPHIR_CALL_FUNCTION(&_4, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("$gt"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, _4, "find", NULL, conditions, fields);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "iterator_to_array", NULL, _5);
	zephir_check_call_status();
	zephir_is_iterable(_6, &_8, &_7, 0, 0, "phalcon/cache/backend/mongo.zep", 300);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(index, _8, _7);
		ZEPHIR_GET_HVALUE(key, _9);
		if (ZEPHIR_IS_STRING(index, "key")) {
			zephir_array_append(&keys, key, PH_SEPARATE, "phalcon/cache/backend/mongo.zep", 296);
		}
	}
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists) {

	zval *_3, *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *_0, *_1 = NULL, *_2 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection",  NULL);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		array_init_size(_3, 3);
		zephir_array_update_string(&_3, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_4);
		array_init_size(_4, 2);
		ZEPHIR_CALL_FUNCTION(&_5, "time", NULL);
		zephir_check_call_status();
		zephir_array_update_string(&_4, SL("$gt"), &_5, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3, SL("time"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2, _1, "count", NULL, _3);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(_2, 0));
	}
	RETURN_MM_BOOL(0);

}

/**
 * gc
 * @return collection->remove(...)
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	array_init_size(_1, 2);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	ZEPHIR_CALL_FUNCTION(&_3, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("$gt"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(_0, "remove", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Increment of a given key by $value
 *
 * @param int|string keyName
 * @param   long value
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value = NULL, *frontend, *prefixedKey, *document = NULL, *timestamp = NULL, *lifetime, *ttl = NULL, *modifiedTime, *cachedContent, *_0, *_1 = NULL, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&timestamp, "time", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(lifetime);
	zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
	if (!(zephir_is_true(lifetime))) {
		ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 364);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_sub_function(_3, timestamp, ttl TSRMLS_CC);
	if (ZEPHIR_LT(_3, modifiedTime)) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 373);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(_4);
			zephir_add_function(_4, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			zephir_add_function(_5, lifetime, timestamp TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, _4, _5);
			zephir_check_call_status();
		}
	}
	RETURN_MM_NULL();

}

/**
 * Decrement of a given key by $value
 *
 * @param int|string $keyName
 * @param   long $value
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value = NULL, *prefixedKey, *document = NULL, *timestamp = NULL, *lifetime, *ttl = NULL, *modifiedTime, *cachedContent, *_0, *_1 = NULL, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&timestamp, "time", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(lifetime);
	zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
	if (!(zephir_is_true(lifetime))) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&ttl, _3, "getlifetime",  NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 409);
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_sub_function(_4, timestamp, ttl TSRMLS_CC);
	if (ZEPHIR_LT(_4, modifiedTime) == 1) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 418);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(_5);
			zephir_sub_function(_5, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_VAR(_6);
			zephir_add_function(_6, lifetime, timestamp TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, _5, _6);
			zephir_check_call_status();
		}
	}
	RETURN_MM_NULL();

}

/**
 * Immediately invalidates all existing items.
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "rand", &_2);
	zephir_check_call_status();
	if ((zephir_get_intval(_1) % 100) == 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gc", NULL);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

