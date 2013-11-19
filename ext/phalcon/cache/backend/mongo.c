
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * $frontCache = new Phalcon\Cache\Frontend\Base64(array(
 *		"lifetime" => 172800
 * ));
 *
 * //Create a MongoDB cache
 * $cache = new Phalcon\Cache\Backend\Mongo($frontCache, array(
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

	zval *frontend, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_array_isset_string(options, SS("mongo")))) {
		if (!(zephir_array_isset_string(options, SS("server")))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'server' is required");
			return;
		}
	}
	if (!(zephir_array_isset_string(options, SS("db")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'db' is required");
		return;
	}
	if (!(zephir_array_isset_string(options, SS("collection")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required");
		return;
	}
	zephir_call_parent_p2_noret(this_ptr, phalcon_cache_backend_mongo_ce, "__construct", frontend, options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection) {

	zend_class_entry *_0;
	zval *options, *mongo = NULL, *server, *database, *collection, *mongoDatabase, *mongoCollection;

	ZEPHIR_MM_GROW();

	mongoCollection = zephir_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	if ((Z_TYPE_P(mongoCollection) != IS_OBJECT)) {
		options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (zephir_array_isset_string(options, SS("mongo"))) {
			ZEPHIR_OBS_VAR(mongo);
			zephir_array_fetch_string(&mongo, options, SL("mongo"), PH_NOISY TSRMLS_CC);
			if ((Z_TYPE_P(mongo) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance");
				return;
			}
		} else {
			zephir_array_fetch_string(&server, options, SL("server"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if ((!zephir_is_true(server) || (Z_TYPE_P(server) != IS_STRING))) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string");
				return;
			}
			ZEPHIR_INIT_NVAR(mongo);
			_0 = zend_fetch_class(SL("Mongo"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(mongo, _0);
		}
		zephir_array_fetch_string(&database, options, SL("db"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if ((!zephir_is_true(database) || (Z_TYPE_P(database) != IS_STRING))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db");
			return;
		}
		zephir_array_fetch_string(&collection, options, SL("collection"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if ((!zephir_is_true(collection) || (Z_TYPE_P(collection) != IS_STRING))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection");
			return;
		}
		ZEPHIR_INIT_VAR(mongoDatabase);
		zephir_call_method_p1(mongoDatabase, mongo, "selectdb", database);
		zephir_call_method_p1_noret(mongoDatabase, "selectcollection", collection);
	} else {
		RETURN_CTOR(mongoCollection);
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

	zval *keyName, *lifetime = NULL, *frontend, *prefix, *prefixedKey, *collection, *conditions, *timeCondition, *document, *cachedContent, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(timeCondition);
	array_init(timeCondition);
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "time");
	zephir_array_update_string(&timeCondition, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(document);
	zephir_call_method_p1(document, collection, "findone", conditions);
	if ((Z_TYPE_P(document) == IS_ARRAY)) {
		if (zephir_array_isset_string(document, SS("data"))) {
			zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY | PH_READONLY TSRMLS_CC);
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CTOR(cachedContent);
			} else {
				zephir_call_method_p1(return_value, frontend, "afterretrieve", cachedContent);
				RETURN_MM();
			}
		} else {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is corrupt");
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

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastkey, *prefix, *frontend, *cachedContent = NULL, *tmp, *tt1 = NULL, *collection, *timestamp, *conditions, *document, *preparedContent, *isBuffering, *data, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer || Z_TYPE_P(stopBuffer) == IS_NULL) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_INIT_VAR(lastkey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastkey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastkey, prefix, keyName);
	}
	if (!(zephir_is_true(lastkey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!(zephir_is_true(content))) {
		ZEPHIR_INIT_VAR(cachedContent);
		zephir_call_method(cachedContent, frontend, "getcontent");
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_INIT_VAR(preparedContent);
		zephir_call_method_p1(preparedContent, frontend, "beforestore", cachedContent);
	}
	if (!(zephir_is_true(lifetime))) {
		tmp = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_INIT_VAR(tt1);
			zephir_call_method(tt1, frontend, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "time");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "intval", tt1);
	ZEPHIR_INIT_VAR(timestamp);
	zephir_add_function(timestamp, _0, _1 TSRMLS_CC);
	zephir_array_update_string(&conditions, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(document);
	zephir_call_method_p1(document, collection, "findone", conditions);
	if ((Z_TYPE_P(document) == IS_ARRAY)) {
		zephir_array_update_string(&document, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&document, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&document, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		zephir_call_method_p1_noret(collection, "save", document);
	} else {
		zephir_array_update_string(&data, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&data, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&data, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		zephir_call_method_p1_noret(collection, "save", data);
	}
	ZEPHIR_INIT_VAR(isBuffering);
	zephir_call_method(isBuffering, frontend, "isbuffering");
	if (ZEPHIR_IS_TRUE(stopBuffer)) {
		zephir_call_method_noret(frontend, "stop");
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

	zval *keyName, *prefix, *prefixedKey, *collection, *conditions, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	zephir_call_method_p1_noret(collection, "remove", conditions);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "rand");
	if (((zephir_get_intval(_0) % 100) == 0)) {
		zephir_call_method_noret(this_ptr, "gc");
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

	HashTable *_3;
	HashPosition _2;
	zval *prefix = NULL, *collection, *fields, *conditions, *pattern, *regex, *timeCondition, *documents, *documentsArray, *keys, *index = NULL, *key = NULL, *_0, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix || Z_TYPE_P(prefix) == IS_NULL) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(timeCondition);
	array_init(timeCondition);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_array_update_string(&fields, SL("key"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	if (zephir_is_true(prefix)) {
		ZEPHIR_INIT_VAR(pattern);
		ZEPHIR_CONCAT_SVS(pattern, "/^", prefix, "/");
		ZEPHIR_INIT_VAR(regex);
		zephir_call_func_p1(regex, "mongoregex", pattern);
		zephir_array_update_string(&conditions, SL("key"), &regex, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func(_1, "time");
	zephir_array_update_string(&timeCondition, SL("$gt"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(documents);
	zephir_call_method_p2(documents, collection, "find", conditions, fields);
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(documentsArray);
	zephir_call_func_p1(documentsArray, "iterator_to_array", documents);
	zephir_is_iterable(documentsArray, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(index, _3, _2);
		ZEPHIR_GET_HVALUE(key, _4);
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

	int number;
	zval *keyName = NULL, *lifetime = NULL, *lastKey, *collection, *conditions, *timeCondition, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(timeCondition);
	array_init(timeCondition);
	ZEPHIR_INIT_VAR(lastKey);
	if ((Z_TYPE_P(keyName) == IS_NULL)) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_VV(lastKey, _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_INIT_VAR(collection);
		zephir_call_method(collection, this_ptr, "_getcollection");
		zephir_array_update_string(&conditions, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func(_1, "time");
		zephir_array_update_string(&timeCondition, SL("$gt"), &_1, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_2);
		zephir_call_method_p1(_2, collection, "count", conditions);
		number = zephir_get_intval(_2);
		if ((number > 0)) {
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

	zval *conditions, *timeCondition, *collection, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(timeCondition);
	array_init(timeCondition);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "time");
	zephir_array_update_string(&timeCondition, SL("$gt"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	zephir_array_update_string(&conditions, SL("time"), &timeCondition, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	zephir_call_method_p1(return_value, collection, "remove", conditions);
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

	zend_bool notExpired;
	zval *keyName, *value = NULL, *frontend, *prefix, *prefixedKey, *collection, *conditions, *document, *timestamp, *lifetime, *tt1, *modifiedTime, difference, *cachedContent, *keys;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value || Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(document);
	zephir_call_method_p1(document, collection, "findone", conditions);
	ZEPHIR_INIT_VAR(timestamp);
	zephir_call_func(timestamp, "time");
	lifetime = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(tt1);
	if (!(zephir_is_true(lifetime))) {
		zephir_call_method(tt1, frontend, "getlifetime");
	} else {
		zephir_call_func(tt1, "lifetime");
	}
	if (!(zephir_array_isset_string(document, SS("time")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
		return;
	}
	zephir_array_fetch_string(&modifiedTime, document, SL("time"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(difference);
	sub_function(&difference, timestamp, tt1 TSRMLS_CC);
	notExpired = ZEPHIR_LT(&difference, modifiedTime);
	if ((notExpired == 1)) {
		if (!(zephir_array_isset_string(document, SS("data")))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
			return;
		}
		zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(keys);
			zephir_add_function(keys, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_BNVAR(tt1);
			zephir_add_function(tt1, lifetime, timestamp TSRMLS_CC);
			zephir_call_method_p2_noret(this_ptr, "save", prefixedKey, keys);
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

	zend_bool notExpired;
	zval *keyName, *value = NULL, *frontend, *prefix, *prefixedKey, *collection, *conditions, *document, *timestamp, *lifetime, *tt1, *modifiedTime, difference, *cachedContent, *keys;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value);

	if (!value || Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	}


	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_VV(prefixedKey, prefix, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(document);
	zephir_call_method_p1(document, collection, "findone", conditions);
	ZEPHIR_INIT_VAR(timestamp);
	zephir_call_func(timestamp, "time");
	lifetime = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(tt1);
	if (!(zephir_is_true(lifetime))) {
		zephir_call_method(tt1, frontend, "getlifetime");
	} else {
		zephir_call_func(tt1, "lifetime");
	}
	if (!(zephir_array_isset_string(document, SS("time")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
		return;
	}
	zephir_array_fetch_string(&modifiedTime, document, SL("time"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_SINIT_VAR(difference);
	sub_function(&difference, timestamp, tt1 TSRMLS_CC);
	notExpired = ZEPHIR_LT(&difference, modifiedTime);
	if ((notExpired == 1)) {
		if (!(zephir_array_isset_string(document, SS("data")))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
			return;
		}
		zephir_array_fetch_string(&cachedContent, document, SL("data"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(keys);
			sub_function(keys, cachedContent, value TSRMLS_CC);
			ZEPHIR_INIT_BNVAR(tt1);
			zephir_add_function(tt1, lifetime, timestamp TSRMLS_CC);
			zephir_call_method_p2_noret(this_ptr, "save", prefixedKey, keys);
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

	zval *collection, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(collection);
	zephir_call_method(collection, this_ptr, "_getcollection");
	zephir_call_method_noret(collection, "remove");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "rand");
	if (((zephir_get_intval(_0) % 100) == 0)) {
		zephir_call_method_noret(this_ptr, "gc");
	}
	RETURN_MM_BOOL(1);

}

