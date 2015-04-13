
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/iterator.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
 * @param Phalcon\Cache\FrontendInterface frontend
 * @param array options
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


	if (!(zephir_array_isset_string(options, SS("mongo")))) {
		if (!(zephir_array_isset_string(options, SS("server")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'server' is required", "phalcon/cache/backend/mongo.zep", 70);
			return;
		}
	}
	if (!(zephir_array_isset_string(options, SS("db")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'db' is required", "phalcon/cache/backend/mongo.zep", 75);
		return;
	}
	if (!(zephir_array_isset_string(options, SS("collection")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required", "phalcon/cache/backend/mongo.zep", 79);
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
	zend_bool _0;
	zval *options, *mongo = NULL, *server, *database, *collection, *mongoCollection = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(mongoCollection);
	zephir_read_property_this(&mongoCollection, this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(mongoCollection) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(mongo);
		if (zephir_array_isset_string_fetch(&mongo, options, SS("mongo"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(mongo) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance", "phalcon/cache/backend/mongo.zep", 104);
				return;
			}
		} else {
			ZEPHIR_OBS_VAR(server);
			zephir_array_fetch_string(&server, options, SL("server"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 112 TSRMLS_CC);
			_0 = !zephir_is_true(server);
			if (!(_0)) {
				_0 = Z_TYPE_P(server) != IS_STRING;
			}
			if (_0) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string", "phalcon/cache/backend/mongo.zep", 114);
				return;
			}
			ZEPHIR_INIT_NVAR(mongo);
			object_init_ex(mongo, zephir_get_internal_ce(SS("mongoclient") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongo, "__construct", NULL, server);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(database);
		zephir_array_fetch_string(&database, options, SL("db"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 123 TSRMLS_CC);
		_0 = !zephir_is_true(database);
		if (!(_0)) {
			_0 = Z_TYPE_P(database) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db", "phalcon/cache/backend/mongo.zep", 125);
			return;
		}
		ZEPHIR_OBS_VAR(collection);
		zephir_array_fetch_string(&collection, options, SL("collection"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 131 TSRMLS_CC);
		_0 = !zephir_is_true(collection);
		if (!(_0)) {
			_0 = Z_TYPE_P(collection) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection", "phalcon/cache/backend/mongo.zep", 133);
			return;
		}
		ZEPHIR_CALL_METHOD(&_1, mongo, "selectdb", NULL, database);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&mongoCollection, _1, "selectcollection", NULL, collection);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_collection"), mongoCollection TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *conditions, *document = NULL, *cachedContent, *_0, *_2, *_3 = NULL;

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
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_array_update_string(&_1, SL("$gt"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getcollection", &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&document, _3, "findone", NULL, conditions);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupt", "phalcon/cache/backend/mongo.zep", 174);
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

	zval *_2;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastkey = NULL, *prefix, *frontend, *cachedContent = NULL, *tmp, *ttl = NULL, *collection = NULL, *timestamp, *conditions, *document = NULL, *preparedContent = NULL, *isBuffering = NULL, *data, *_1, *_3;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/mongo.zep", 206);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!(zephir_is_true(content))) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL);
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
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	ZEPHIR_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (zephir_get_numberval(_1) + zephir_get_intval(ttl)));
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
		ZEPHIR_INIT_VAR(_2);
		array_init_size(_2, 2);
		ZEPHIR_OBS_VAR(_3);
		zephir_array_fetch_string(&_3, document, SL("_id"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 246 TSRMLS_CC);
		zephir_array_update_string(&_2, SL("_id"), &_3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, collection, "update", NULL, _2, document);
		zephir_check_call_status();
	} else {
		zephir_array_update_string(&data, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&data, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&data, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(NULL, collection, "insert", NULL, data);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(stopBuffer)) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
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

	zval *_2;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *_0 = NULL, *_3, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VV(_4, _3, keyName);
	zephir_array_update_string(&_2, SL("key"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "rand", &_6);
	zephir_check_call_status();
	if ((zephir_get_intval(_5) % 100) == 0) {
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

	HashTable *_7;
	HashPosition _6;
	zend_object_iterator *_5;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys, *conditions, *_2, *_4;
	zval *prefix = NULL, *collection = NULL, *key = NULL, *item = NULL, *items = NULL, *value = NULL, *_0 = NULL, *_1, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);


	if (zephir_is_true(prefix)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "/^", prefix, "/");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _1);
		zephir_check_call_status();
		zephir_array_update_string(&conditions, SL("key"), &_0, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	ZEPHIR_INIT_NVAR(_0);
	zephir_time(_0);
	zephir_array_update_string(&_2, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	array_init_size(_4, 2);
	add_assoc_long_ex(_4, SS("key"), 1);
	ZEPHIR_CALL_METHOD(&items, collection, "find", NULL, conditions, _4);
	zephir_check_call_status();
	_5 = zephir_get_iterator(items TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		{ zval **tmp; 
		_5->funcs->get_current_data(_5, &tmp TSRMLS_CC);
		item = *tmp;
		}
		zephir_is_iterable(item, &_7, &_6, 0, 0, "phalcon/cache/backend/mongo.zep", 318);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HMKEY(key, _7, _6);
			ZEPHIR_GET_HVALUE(value, _8);
			if (ZEPHIR_IS_STRING(key, "key")) {
				zephir_array_append(&keys, value, PH_SEPARATE, "phalcon/cache/backend/mongo.zep", 315);
			}
		}
	}
	_5->funcs->dtor(_5 TSRMLS_CC);
	RETURN_CTOR(keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists) {

	zval *_4, *_5;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *_0, *_1 = NULL, *_3 = NULL, *_6;

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
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		array_init_size(_4, 3);
		zephir_array_update_string(&_4, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_5);
		array_init_size(_5, 2);
		ZEPHIR_INIT_VAR(_6);
		zephir_time(_6);
		zephir_array_update_string(&_5, SL("$gt"), &_6, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4, SL("time"), &_5, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_3, _1, "count", NULL, _4);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(_3, 0));
	}
	RETURN_MM_BOOL(0);

}

/**
 * gc
 * @return collection->remove(...)
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval *_2, *_3;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 2);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	ZEPHIR_INIT_VAR(_4);
	zephir_time(_4);
	zephir_array_update_string(&_3, SL("$lt"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("time"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(_0, "remove", NULL, _2);
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

	zval *_3;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value = NULL, *prefixedKey, *document = NULL, *modifiedTime, *cachedContent, *incremented, *_0, *_1 = NULL, *_4;

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	zephir_array_update_string(&_3, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 374);
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_time(_4);
	if (ZEPHIR_LT(_4, modifiedTime)) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 383);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(incremented);
			zephir_add_function_ex(incremented, cachedContent, value TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, incremented);
			zephir_check_call_status();
			RETURN_CCTOR(incremented);
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

	zval *_3;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value = NULL, *prefixedKey, *document = NULL, *modifiedTime, *cachedContent, *decremented, *_0, *_1 = NULL, *_4;

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 2);
	zephir_array_update_string(&_3, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 413);
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_time(_4);
	if (ZEPHIR_LT(_4, modifiedTime)) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 422);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(decremented);
			sub_function(decremented, cachedContent, value TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, decremented);
			zephir_check_call_status();
			RETURN_CCTOR(decremented);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "rand", &_3);
	zephir_check_call_status();
	if ((zephir_get_intval(_2) % 100) == 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gc", NULL);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

