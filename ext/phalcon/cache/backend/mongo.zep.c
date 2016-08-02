
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


/**
 * Phalcon\Cache\Backend\Mongo
 *
 * Allows to cache output fragments, PHP data or raw data to a MongoDb backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Mongo;
 * use Phalcon\Cache\Frontend\Base64;
 *
 * // Cache data for 2 days
 * $frontCache = new Base64([
 *     'lifetime' => 172800
 * ]);
 *
 * // Create a MongoDB cache
 * $cache = new Mongo($frontCache, [
 *     'server' => "mongodb://localhost",
 *     'db' => 'caches',
 *     'collection' => 'images'
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', file_get_contents('some-image.jpg'));
 *
 * // Get data
 * $data = $cache->get('my-data');
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
 * @param \Phalcon\Cache\FrontendInterface frontend
 * @param array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
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
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_mongo_ce, this_ptr, "__construct", &_0, 113, frontend, options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection) {

	zend_bool _0$$6, _1$$3, _2$$3;
	zval *options = NULL, *mongo = NULL, *server = NULL, *database = NULL, *collection = NULL, *mongoCollection = NULL, *_3$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
			_0$$6 = !zephir_is_true(server);
			if (!(_0$$6)) {
				_0$$6 = Z_TYPE_P(server) != IS_STRING;
			}
			if (_0$$6) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string", "phalcon/cache/backend/mongo.zep", 114);
				return;
			}
			ZEPHIR_INIT_NVAR(mongo);
			object_init_ex(mongo, zephir_get_internal_ce(SS("mongoclient") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, mongo, "__construct", NULL, 0, server);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(database);
		zephir_array_fetch_string(&database, options, SL("db"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 123 TSRMLS_CC);
		_1$$3 = !zephir_is_true(database);
		if (!(_1$$3)) {
			_1$$3 = Z_TYPE_P(database) != IS_STRING;
		}
		if (_1$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db", "phalcon/cache/backend/mongo.zep", 125);
			return;
		}
		ZEPHIR_OBS_VAR(collection);
		zephir_array_fetch_string(&collection, options, SL("collection"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 131 TSRMLS_CC);
		_2$$3 = !zephir_is_true(collection);
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(collection) != IS_STRING;
		}
		if (_2$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection", "phalcon/cache/backend/mongo.zep", 133);
			return;
		}
		ZEPHIR_CALL_METHOD(&_3$$3, mongo, "selectdb", NULL, 0, database);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&mongoCollection, _3$$3, "selectcollection", NULL, 0, collection);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_collection"), mongoCollection TSRMLS_CC);
	}
	RETURN_CCTOR(mongoCollection);

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get) {

	zval *_1;
	int lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *frontend = NULL, *prefixedKey = NULL, *conditions = NULL, *document = NULL, *cachedContent = NULL, *_0, *_2, *_3 = NULL;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
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
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_array_update_string(&_1, SL("$gt"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&document, _3, "findone", NULL, 0, conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(document) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC)) {
			if (zephir_is_numeric(cachedContent)) {
				RETURN_CCTOR(cachedContent);
			}
			ZEPHIR_RETURN_CALL_METHOD(frontend, "afterretrieve", NULL, 0, cachedContent);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupt", "phalcon/cache/backend/mongo.zep", 169);
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

	zval *_1$$13;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastkey = NULL, *prefix = NULL, *frontend = NULL, *cachedContent = NULL, *tmp = NULL, *ttl = NULL, *collection = NULL, *timestamp = NULL, *conditions = NULL, *document = NULL, *preparedContent = NULL, *isBuffering = NULL, *data = NULL, *success = NULL, *_0, *_2$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_INIT_VAR(data);
	array_init(data);
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastkey);
		zephir_read_property_this(&lastkey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastkey);
		ZEPHIR_CONCAT_VV(lastkey, prefix, keyName);
	}
	if (!(zephir_is_true(lastkey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/mongo.zep", 201);
		return;
	}
	ZEPHIR_OBS_VAR(frontend);
	zephir_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(tmp);
		zephir_read_property_this(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (zephir_get_numberval(_0) + zephir_get_intval(ttl)));
	zephir_array_update_string(&conditions, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, collection, "findone", NULL, 0, conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(document) == IS_ARRAY) {
		zephir_array_update_string(&document, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&document, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&document, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_INIT_VAR(_1$$13);
		zephir_create_array(_1$$13, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_2$$13);
		zephir_array_fetch_string(&_2$$13, document, SL("_id"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 241 TSRMLS_CC);
		zephir_array_update_string(&_1$$13, SL("_id"), &_2$$13, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&success, collection, "update", NULL, 0, _1$$13, document);
		zephir_check_call_status();
	} else {
		zephir_array_update_string(&data, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		if (!(zephir_is_numeric(cachedContent))) {
			zephir_array_update_string(&data, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&data, SL("data"), &cachedContent, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(&success, collection, "insert", NULL, 0, data);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in mongodb", "phalcon/cache/backend/mongo.zep", 257);
		return;
	}
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *_0 = NULL, *_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, keyName);
	zephir_array_update_string(&_1, SL("key"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "rand", NULL, 118);
	zephir_check_call_status();
	if (zephir_safe_mod_long_long(zephir_get_intval(_4), 100 TSRMLS_CC) == 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gc", NULL, 0);
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

	HashTable *_7$$4;
	HashPosition _6$$4;
	zend_object_iterator *_5;
	zval *keys, *conditions, *_2, *_4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL, *collection = NULL, *key = NULL, *item = NULL, *items = NULL, *value = NULL, *_3, *_0$$3, *_1$$3, **_8$$4;

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
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, zephir_get_internal_ce(SS("mongoregex") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVS(_1$$3, "/^", prefix, "/");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 0, _1$$3);
		zephir_check_call_status();
		zephir_array_update_string(&conditions, SL("key"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	zephir_array_update_string(&_2, SL("$gt"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(_4, SS("key"), 1);
	ZEPHIR_CALL_METHOD(&items, collection, "find", NULL, 0, conditions, _4);
	zephir_check_call_status();
	_5 = zephir_get_iterator(items TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_5->funcs->get_current_data(_5, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_is_iterable(item, &_7$$4, &_6$$4, 0, 0, "phalcon/cache/backend/mongo.zep", 318);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$4, (void**) &_8$$4, &_6$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$4, &_6$$4)
		) {
			ZEPHIR_GET_HMKEY(key, _7$$4, _6$$4);
			ZEPHIR_GET_HVALUE(value, _8$$4);
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

	zval *_3$$5, *_4$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *_0$$4, *_1$$5 = NULL, *_2$$5 = NULL, *_5$$5;

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
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_VV(lastKey, _0$$4, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_CALL_METHOD(&_1$$5, this_ptr, "_getcollection", NULL, 117);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$5);
		zephir_create_array(_3$$5, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$5, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_4$$5);
		zephir_create_array(_4$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5$$5);
		zephir_time(_5$$5);
		zephir_array_update_string(&_4$$5, SL("$gt"), &_5$$5, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$5, SL("time"), &_4$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$5, _1$$5, "count", NULL, 0, _3$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(_2$$5, 0));
	}
	RETURN_MM_BOOL(0);

}

/**
 * gc
 * @return collection->remove(...)
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval *_1, *_2;
	zval *_0 = NULL, *_3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	zephir_array_update_string(&_2, SL("$lt"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(_0, "remove", NULL, 0, _1);
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
	zval *keyName, *value = NULL, *prefixedKey = NULL, *document = NULL, *modifiedTime = NULL, *cachedContent = NULL, *incremented = NULL, *_0, *_1 = NULL, *_3;

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 374);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	if (ZEPHIR_LT(_3, modifiedTime)) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 383);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(incremented);
			zephir_add_function(incremented, cachedContent, value);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, prefixedKey, incremented);
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

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *value = NULL, *prefixedKey = NULL, *document = NULL, *modifiedTime = NULL, *cachedContent = NULL, *decremented = NULL, *_0, *_1 = NULL, *_3;

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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, _1, "findone", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, document, SS("time"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 413);
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_time(_3);
	if (ZEPHIR_LT(_3, modifiedTime)) {
		ZEPHIR_OBS_VAR(cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, document, SS("data"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is currupted", "phalcon/cache/backend/mongo.zep", 422);
			return;
		}
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(decremented);
			zephir_sub_function(decremented, cachedContent, value);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, prefixedKey, decremented);
			zephir_check_call_status();
			RETURN_CCTOR(decremented);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

