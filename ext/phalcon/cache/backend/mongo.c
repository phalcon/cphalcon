
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
	zval *options, *mongo = NULL, *server, *database, *collection, *mongoDatabase = NULL, *mongoCollection;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(mongoCollection);
	zephir_read_property_this(&mongoCollection, this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(mongoCollection) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(options);
		zephir_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		if (zephir_array_isset_string(options, SS("mongo"))) {
			ZEPHIR_OBS_VAR(mongo);
			zephir_array_fetch_string(&mongo, options, SL("mongo"), PH_NOISY TSRMLS_CC);
			if (Z_TYPE_P(mongo) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance", "phalcon/cache/backend/mongo.zep", 99);
				return;
			}
		} else {
			ZEPHIR_OBS_VAR(server);
			zephir_array_fetch_string(&server, options, SL("server"), PH_NOISY TSRMLS_CC);
			_0 = !zephir_is_true(server);
			if (!(_0)) {
				_0 = Z_TYPE_P(server) != IS_STRING;
			}
			if (_0) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string", "phalcon/cache/backend/mongo.zep", 107);
				return;
			}
			ZEPHIR_INIT_NVAR(mongo);
			_1 = zend_fetch_class(SL("Mongo"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongo, _1);
			if (zephir_has_constructor(mongo TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, mongo, "__construct", NULL);
				zephir_check_call_status();
			}
		}
		ZEPHIR_OBS_VAR(database);
		zephir_array_fetch_string(&database, options, SL("db"), PH_NOISY TSRMLS_CC);
		_0 = !zephir_is_true(database);
		if (!(_0)) {
			_0 = Z_TYPE_P(database) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db", "phalcon/cache/backend/mongo.zep", 117);
			return;
		}
		ZEPHIR_OBS_VAR(collection);
		zephir_array_fetch_string(&collection, options, SL("collection"), PH_NOISY TSRMLS_CC);
		_0 = !zephir_is_true(collection);
		if (!(_0)) {
			_0 = Z_TYPE_P(collection) != IS_STRING;
		}
		if (_0) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection", "phalcon/cache/backend/mongo.zep", 125);
			return;
		}
		ZEPHIR_CALL_METHOD(&mongoDatabase, mongo, "selectdb", NULL, database);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, mongoDatabase, "selectcollection", NULL, collection);
		zephir_check_call_status();
	} else {
		RETURN_CCTOR(mongoCollection);
	}
	ZEPHIR_MM_RESTORE();

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
	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *conditions, *timeCondition, *document = NULL, *cachedContent, *_0, *_1 = NULL;

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
	ZEPHIR_INIT_VAR(timeCondition);
	array_init_size(timeCondition, 2);
	ZEPHIR_CALL_FUNCTION(&_1, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&timeCondition, SL("$gt"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(document) == IS_ARRAY) {
		if (zephir_array_isset_string(document, SS("data"))) {
			ZEPHIR_OBS_VAR(cachedContent);
			zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY TSRMLS_CC);
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CCTOR(cachedContent);
			} else {
				ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, cachedContent);
				zephir_check_call_status();
				RETURN_MM();
			}
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupt", "phalcon/cache/backend/mongo.zep", 168);
			return;
		}
	} else {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache must be started first", "phalcon/cache/backend/mongo.zep", 199);
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

	HashTable *_6;
	HashPosition _5;
	zend_class_entry *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *collection = NULL, *fields, *conditions, *timeCondition, *documents = NULL, *keys, *index = NULL, *key = NULL, *_0 = NULL, *_1, *_2, *_4, **_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(timeCondition);
	array_init_size(timeCondition, 2);
	ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&timeCondition, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_array_update_string(&fields, SL("key"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	if (zephir_is_true(prefix)) {
		ZEPHIR_INIT_VAR(_2);
		_3 = zend_fetch_class(SL("MongoRegex"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_2, _3);
		if (zephir_has_constructor(_2 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_SVS(_4, "/^", prefix, "/");
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _4);
			zephir_check_call_status();
		}
		zephir_array_update_string(&conditions, SL("key"), &_2, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&documents, collection, "find", NULL, conditions, fields);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_CALL_FUNCTION(&_0, "iterator_to_array", NULL, documents);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_6, &_5, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(index, _6, _5);
		ZEPHIR_GET_HVALUE(key, _7);
		if (ZEPHIR_IS_STRING(index, "key")) {
			zephir_array_append(&keys, key, PH_SEPARATE);
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

	int number, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *collection = NULL, *conditions, *timeCondition, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(timeCondition);
	array_init_size(timeCondition, 2);
	ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&timeCondition, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _1, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
		zephir_check_call_status();
		zephir_array_update_string(&conditions, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_0, collection, "count", NULL, conditions);
		zephir_check_call_status();
		number = zephir_get_intval(_0);
		if (number > 0) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * gc
 * @return collection->remove(...)
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *conditions, *timeCondition, *collection = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(timeCondition);
	array_init_size(timeCondition, 2);
	ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
	zephir_check_call_status();
	zephir_array_update_string(&timeCondition, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(conditions);
	array_init_size(conditions, 2);
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(collection, "remove", NULL, conditions);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Increment of a given key by $value
 *
 * @param int|string $keyName
 * @param   long $value
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notExpired;
	zval *keyName, *value = NULL, *frontend, *prefix, *prefixedKey, *collection = NULL, *document = NULL, *timestamp = NULL, *lifetime, *ttl = NULL, *modifiedTime, difference, *cachedContent, *keys;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	zephir_array_update_string(&_0, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, collection, "findone", NULL, _0);
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
	if (!(zephir_array_isset_string(document, SS("time")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 390);
		return;
	}
	ZEPHIR_OBS_VAR(modifiedTime);
	zephir_array_fetch_string(&modifiedTime, document, SL("time"), PH_NOISY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(difference);
	sub_function(&difference, timestamp, ttl TSRMLS_CC);
	notExpired = ZEPHIR_LT(&difference, modifiedTime);
	if (notExpired == 1) {
		if (!(zephir_array_isset_string(document, SS("data")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 402);
			return;
		}
		ZEPHIR_OBS_VAR(cachedContent);
		zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY TSRMLS_CC);
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(keys);
			zephir_add_function(keys, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_NVAR(ttl);
			zephir_add_function(ttl, lifetime, timestamp TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, keys);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool notExpired;
	zval *keyName, *value = NULL, *frontend, *prefix, *prefixedKey, *collection = NULL, *conditions, *document = NULL, *timestamp = NULL, *lifetime, *ttl = NULL, *modifiedTime, difference, *cachedContent, *keys;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(prefix);
	zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(conditions);
	array_init_size(conditions, 2);
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, collection, "findone", NULL, conditions);
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
	if (!(zephir_array_isset_string(document, SS("time")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 447);
		return;
	}
	ZEPHIR_OBS_VAR(modifiedTime);
	zephir_array_fetch_string(&modifiedTime, document, SL("time"), PH_NOISY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(difference);
	sub_function(&difference, timestamp, ttl TSRMLS_CC);
	notExpired = ZEPHIR_LT(&difference, modifiedTime);
	if (notExpired == 1) {
		if (!(zephir_array_isset_string(document, SS("data")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 459);
			return;
		}
		ZEPHIR_OBS_VAR(cachedContent);
		zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY TSRMLS_CC);
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(keys);
			sub_function(keys, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_NVAR(ttl);
			zephir_add_function(ttl, lifetime, timestamp TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, prefixedKey, keys);
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

