
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * $frontCache = new Base64(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * // Create a MongoDB cache
 * $cache = new Mongo(
 *     $frontCache,
 *     [
 *         "server"     => "mongodb://localhost",
 *         "db"         => "caches",
 *         "collection" => "images",
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save(
 *     "my-data",
 *     file_get_contents("some-image.jpg")
 * );
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Mongo) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Mongo, phalcon, cache_backend_mongo, phalcon_cache_backend_ce, phalcon_cache_backend_mongo_method_entry, 0);

	zend_declare_property_null(phalcon_cache_backend_mongo_ce, SL("_collection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Mongo constructor
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval options;
	zval *frontend, frontend_sub, *options_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (!(zephir_array_isset_string(&options, SL("mongo")))) {
		if (!(zephir_array_isset_string(&options, SL("server")))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'server' is required", "phalcon/cache/backend/mongo.zep", 65);
			return;
		}
	}
	if (!(zephir_array_isset_string(&options, SL("db")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'db' is required", "phalcon/cache/backend/mongo.zep", 70);
		return;
	}
	if (!(zephir_array_isset_string(&options, SL("collection")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required", "phalcon/cache/backend/mongo.zep", 74);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_cache_backend_mongo_ce, getThis(), "__construct", &_0, 0, frontend, &options);
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
	zval options, mongo, server, database, collection, mongoCollection, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&mongo);
	ZVAL_UNDEF(&server);
	ZVAL_UNDEF(&database);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&mongoCollection);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&mongoCollection);
	zephir_read_property(&mongoCollection, this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(&mongoCollection) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(&options);
		zephir_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&mongo);
		if (zephir_array_isset_string_fetch(&mongo, &options, SL("mongo"), 0)) {
			if (Z_TYPE_P(&mongo) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance", "phalcon/cache/backend/mongo.zep", 99);
				return;
			}
		} else {
			ZEPHIR_OBS_VAR(&server);
			zephir_array_fetch_string(&server, &options, SL("server"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 107 TSRMLS_CC);
			_0$$6 = !zephir_is_true(&server);
			if (!(_0$$6)) {
				_0$$6 = Z_TYPE_P(&server) != IS_STRING;
			}
			if (_0$$6) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string", "phalcon/cache/backend/mongo.zep", 109);
				return;
			}
			ZEPHIR_INIT_NVAR(&mongo);
			object_init_ex(&mongo, zephir_get_internal_ce(SL("mongoclient")));
			if (zephir_has_constructor(&mongo TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &mongo, "__construct", NULL, 0, &server);
				zephir_check_call_status();
			}
		}
		ZEPHIR_OBS_VAR(&database);
		zephir_array_fetch_string(&database, &options, SL("db"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 118 TSRMLS_CC);
		_1$$3 = !zephir_is_true(&database);
		if (!(_1$$3)) {
			_1$$3 = Z_TYPE_P(&database) != IS_STRING;
		}
		if (_1$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db", "phalcon/cache/backend/mongo.zep", 120);
			return;
		}
		ZEPHIR_OBS_VAR(&collection);
		zephir_array_fetch_string(&collection, &options, SL("collection"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 126 TSRMLS_CC);
		_2$$3 = !zephir_is_true(&collection);
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(&collection) != IS_STRING;
		}
		if (_2$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection", "phalcon/cache/backend/mongo.zep", 128);
			return;
		}
		ZEPHIR_CALL_METHOD(&_3$$3, &mongo, "selectdb", NULL, 0, &database);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&mongoCollection, &_3$$3, "selectcollection", NULL, 0, &collection);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_collection"), &mongoCollection);
	}
	RETURN_CCTOR(&mongoCollection);

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, frontend, prefixedKey, conditions, document, cachedContent, _0, _2, _3;
	zval keyName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	zephir_get_strval(&keyName, keyName_param);
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, &keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	zephir_array_update_string(&conditions, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_update_string(&_1, SL("$gt"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&document, &_3, "findone", NULL, 0, &conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(&document) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&cachedContent);
		if (zephir_array_isset_string_fetch(&cachedContent, &document, SL("data"), 0)) {
			if (zephir_is_numeric(&cachedContent)) {
				RETURN_CCTOR(&cachedContent);
			}
			ZEPHIR_RETURN_CALL_METHOD(&frontend, "afterretrieve", NULL, 0, &cachedContent);
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
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save) {

	zval _2$$14;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastkey, frontend, cachedContent, tmp, ttl, collection, timestamp, conditions, document, preparedContent, isBuffering, data, success, _1, _0$$4, _3$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastkey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$14);
	ZVAL_UNDEF(&_2$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!content) {
		content = &content_sub;
		content = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastkey);
		zephir_read_property(&lastkey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastkey);
		ZEPHIR_CONCAT_VV(&lastkey, &_0$$4, keyName);
		zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastkey);
	}
	if (!(zephir_is_true(&lastkey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/mongo.zep", 195);
		return;
	}
	ZEPHIR_OBS_VAR(&frontend);
	zephir_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&cachedContent, &frontend, "getcontent", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&cachedContent, content);
	}
	if (!(zephir_is_numeric(&cachedContent))) {
		ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&preparedContent, &cachedContent);
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_VAR(&tmp);
		zephir_read_property(&tmp, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(&tmp))) {
			ZEPHIR_CALL_METHOD(&ttl, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, &tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(&ttl, lifetime);
	}
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZEPHIR_INIT_VAR(&timestamp);
	ZVAL_LONG(&timestamp, (zephir_get_numberval(&_1) + zephir_get_intval(&ttl)));
	zephir_array_update_string(&conditions, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, &collection, "findone", NULL, 0, &conditions);
	zephir_check_call_status();
	if (Z_TYPE_P(&document) == IS_ARRAY) {
		zephir_array_update_string(&document, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&document, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_2$$14);
		zephir_create_array(&_2$$14, 1, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_3$$14);
		zephir_array_fetch_string(&_3$$14, &document, SL("_id"), PH_NOISY, "phalcon/cache/backend/mongo.zep", 230 TSRMLS_CC);
		zephir_array_update_string(&_2$$14, SL("_id"), &_3$$14, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&success, &collection, "update", NULL, 0, &_2$$14, &document);
		zephir_check_call_status();
	} else {
		zephir_array_update_string(&data, SL("key"), &lastkey, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("time"), &timestamp, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&data, SL("data"), &preparedContent, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&success, &collection, "insert", NULL, 0, &data);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in mongodb", "phalcon/cache/backend/mongo.zep", 239);
		return;
	}
	ZEPHIR_CALL_METHOD(&isBuffering, &frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, &frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(&isBuffering)) {
		zend_print_zval(&cachedContent, 0);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	RETURN_CCTOR(&success);

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, _0, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_read_property(&_2, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &_2, keyName);
	zephir_array_update_string(&_1, SL("key"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "rand", NULL, 105);
	zephir_check_call_status();
	if (zephir_safe_mod_long_long(zephir_get_intval(&_4), 100 TSRMLS_CC) == 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "gc", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Query the existing cached keys.
 *
 * <code>
 * $cache->save("users-ids", [1, 2, 3]);
 * $cache->save("projects-ids", [4, 5, 6]);
 *
 * var_dump($cache->queryKeys("users")); // ["users-ids"]
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys) {

	zend_string *_9$$4;
	zend_ulong _8$$4;
	zend_object_iterator *_5;
	zval keys, conditions, _2, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, collection, key, item, items, value, _3, _0$$3, *_6$$4, _7$$4;
	zval prefix, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	if (!(ZEPHIR_IS_EMPTY(&prefix))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zephir_get_internal_ce(SL("mongoregex")));
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_CONCAT_SVS(&_1$$3, "/^", &prefix, "/");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_1$$3);
			zephir_check_call_status();
		}
		zephir_array_update_string(&conditions, SL("key"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	zephir_array_update_string(&_2, SL("$gt"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&conditions, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&collection, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(&_4, SL("key"), 1);
	ZEPHIR_CALL_METHOD(&items, &collection, "find", NULL, 0, &conditions, &_4);
	zephir_check_call_status();
	_5 = zephir_get_iterator(&items TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _5);
		}
		zephir_is_iterable(&item, 0, "phalcon/cache/backend/mongo.zep", 303);
		if (Z_TYPE_P(&item) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&item), _8$$4, _9$$4, _6$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$4);
				} else {
					ZVAL_LONG(&key, _8$$4);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _6$$4);
				if (ZEPHIR_IS_STRING(&key, "key")) {
					zephir_array_append(&keys, &value, PH_SEPARATE, "phalcon/cache/backend/mongo.zep", 300);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &item, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$4, &item, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &item, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &item, "current", NULL, 0);
				zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&key, "key")) {
						zephir_array_append(&keys, &value, PH_SEPARATE, "phalcon/cache/backend/mongo.zep", 300);
					}
				ZEPHIR_CALL_METHOD(NULL, &item, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	zend_iterator_dtor(_5);
	RETURN_CTOR(&keys);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists) {

	zval _3$$5, _4$$5;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime_param = NULL, __$null, lastKey, _0$$4, _1$$5, _2$$5, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_VV(&lastKey, &_0$$4, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		ZEPHIR_CALL_METHOD(&_1$$5, this_ptr, "_getcollection", NULL, 104);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$5);
		zephir_create_array(&_3$$5, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_3$$5, SL("key"), &lastKey, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_create_array(&_4$$5, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_time(&_5$$5);
		zephir_array_update_string(&_4$$5, SL("$gt"), &_5$$5, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_3$$5, SL("time"), &_4$$5, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_2$$5, &_1$$5, "count", NULL, 0, &_3$$5);
		zephir_check_call_status();
		RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_2$$5, 0));
	}
	RETURN_MM_BOOL(0);

}

/**
 * gc
 * @return collection->remove(...)
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval _1, _2;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	zephir_array_update_string(&_2, SL("$lt"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("time"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "remove", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Increment of a given key by $value
 *
 * @param int|string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment) {

	zval _2;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, *value_param = NULL, prefixedKey, document, modifiedTime, cachedContent, incremented, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&modifiedTime);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&incremented);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, &_1, "findone", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, &document, SL("time"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupted", "phalcon/cache/backend/mongo.zep", 356);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	if (ZEPHIR_LT(&_3, &modifiedTime)) {
		ZEPHIR_OBS_VAR(&cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, &document, SL("data"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupted", "phalcon/cache/backend/mongo.zep", 365);
			return;
		}
		if (zephir_is_numeric(&cachedContent)) {
			ZEPHIR_INIT_VAR(&incremented);
			ZVAL_LONG(&incremented, (zephir_get_numberval(&cachedContent) + value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, &prefixedKey, &incremented);
			zephir_check_call_status();
			RETURN_CCTOR(&incremented);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Decrement of a given key by $value
 *
 * @param int|string $keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement) {

	zval _2;
	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, keyName_sub, *value_param = NULL, prefixedKey, document, modifiedTime, cachedContent, decremented, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&document);
	ZVAL_UNDEF(&modifiedTime);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&decremented);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_VV(&prefixedKey, &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("key"), &prefixedKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&document, &_1, "findone", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&modifiedTime);
	if (!(zephir_array_isset_string_fetch(&modifiedTime, &document, SL("time"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupted", "phalcon/cache/backend/mongo.zep", 393);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_time(&_3);
	if (ZEPHIR_LT(&_3, &modifiedTime)) {
		ZEPHIR_OBS_VAR(&cachedContent);
		if (!(zephir_array_isset_string_fetch(&cachedContent, &document, SL("data"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "The cache is corrupted", "phalcon/cache/backend/mongo.zep", 402);
			return;
		}
		if (zephir_is_numeric(&cachedContent)) {
			ZEPHIR_INIT_VAR(&decremented);
			ZVAL_LONG(&decremented, (zephir_get_numberval(&cachedContent) - value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, &prefixedKey, &decremented);
			zephir_check_call_status();
			RETURN_CCTOR(&decremented);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getcollection", NULL, 104);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

