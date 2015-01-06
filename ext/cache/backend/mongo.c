
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

#include "cache/backend/mongo.h"
#include "cache/backend.h"
#include "cache/backendinterface.h"
#include "cache/exception.h"

#include <ext/standard/php_rand.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

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
zend_class_entry *phalcon_cache_backend_mongo_ce;

PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_empty, 0, 0, 0)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_cache_backend_mongo_method_entry[] = {
	PHP_ME(Phalcon_Cache_Backend_Mongo, __construct, arginfo_phalcon_cache_backend_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Mongo, _getCollection, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_Backend_Mongo, get, arginfo_phalcon_cache_backendinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, save, arginfo_phalcon_cache_backendinterface_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, delete, arginfo_phalcon_cache_backendinterface_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, exists, arginfo_phalcon_cache_backendinterface_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, gc, arginfo_phalcon_cache_backend_mongo_empty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, increment, arginfo_phalcon_cache_backendinterface_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, decrement, arginfo_phalcon_cache_backendinterface_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, flush, arginfo_phalcon_cache_backend_mongo_empty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Cache\Backend\Mongo initializer
 */
PHALCON_INIT_CLASS(Phalcon_Cache_Backend_Mongo){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Mongo, cache_backend_mongo, phalcon_cache_backend_ce, phalcon_cache_backend_mongo_method_entry, 0);

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
PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct){

	zval *frontend, *options = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &frontend, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (!phalcon_array_isset_string(options, SS("mongo"))) {
		if (!phalcon_array_isset_string(options, SS("server"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'server' is required");
			return;
		}
	}
	if (!phalcon_array_isset_string(options, SS("db"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'db' is required");
		return;
	}
	
	if (!phalcon_array_isset_string(options, SS("collection"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required");
		return;
	}
	
	PHALCON_CALL_PARENT(NULL, phalcon_cache_backend_mongo_ce, this_ptr, "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection){

	zval *mongo_collection, *mongo_database = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	mongo_collection = phalcon_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		zval *options, *mongo;
		zval *server = NULL, *database = NULL, *collection = NULL;

		options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	
		/** 
		 * If mongo is defined a valid Mongo object must be passed
		 */
		if (phalcon_array_isset_string_fetch(&mongo, options, SS("mongo"))) {
			if (Z_TYPE_P(mongo) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance");
				return;
			}
		} else {
			/** 
			 * Server must be defined otherwise
			 */
			phalcon_array_isset_string_fetch(&server, options, SS("server"));
			if (!server || Z_TYPE_P(server) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string");
				return;
			}
	
			ce0 = zend_fetch_class(SL("MongoClient"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
			PHALCON_INIT_VAR(mongo);
			object_init_ex(mongo, ce0);
			assert(phalcon_has_constructor(mongo TSRMLS_CC));
			PHALCON_CALL_METHOD(NULL, mongo, "__construct", server);
		}
	
		/** 
		 * Check if the database name is a string
		 */
		phalcon_array_isset_string_fetch(&database, options, SS("db"));
		if (!database || Z_TYPE_P(database) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db");
			return;
		}
	
		/** 
		 * Retrieve the connection name
		 */
		phalcon_array_isset_string_fetch(&collection, options, SS("collection"));
		if (!collection || Z_TYPE_P(collection) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection");
			return;
		}
	
		/** 
		 * Make the connection and get the collection
		 */
		PHALCON_CALL_METHOD(&mongo_database, mongo, "selectdb", database);
		PHALCON_RETURN_CALL_METHOD(mongo_database, "selectcollection", collection);
	}
	else {
		RETVAL_ZVAL(mongo_collection, 1, 0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get){

	zval *key_name, *lifetime = NULL, *frontend, *prefix, *prefixed_key;
	zval *collection = NULL, *conditions, *document = NULL, *time_condition;
	zval *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 2);
	phalcon_array_update_string(&conditions, SL("key"), prefixed_key, PH_COPY);
	
	MAKE_STD_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
	add_assoc_zval_ex(conditions, SS("time"), time_condition);

	PHALCON_CALL_METHOD(&document, collection, "findone", conditions);
	if (Z_TYPE_P(document) == IS_ARRAY) { 
		if (likely(phalcon_array_isset_string_fetch(&cached_content, document, SS("data")))) {
			if (phalcon_is_numeric(cached_content)) {
				RETURN_CCTOR(cached_content);
			} else {
				PHALCON_RETURN_CALL_METHOD(frontend, "afterretrieve", cached_content);
				RETURN_MM();
			}
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is corrupt");
			return;
		}
	} else {
		RETURN_MM_NULL();
	}
	
}

/**
 * Stores cached content into the Mongo backend and stops the frontend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key, *frontend, *cached_content = NULL;
	zval *prepared_content = NULL, *ttl = NULL, *collection = NULL, *timestamp;
	zval *conditions, *document = NULL, *data, *is_buffering = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_CALL_METHOD(&cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}

	if (!phalcon_is_numeric(cached_content)) {
		PHALCON_CALL_METHOD(&prepared_content, frontend, "beforestore", cached_content);
	}

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(tmp) == IS_NULL) {
			PHALCON_CALL_METHOD(&ttl, frontend, "getlifetime");
		}
		else {
			ttl = tmp;
		}
	} else {
		ttl = lifetime;
	}
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (long) time(NULL) + phalcon_get_intval(ttl));
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), last_key, PH_COPY);
	
	PHALCON_CALL_METHOD(&document, collection, "findone", conditions);

	if (Z_TYPE_P(document) == IS_ARRAY) { 
		phalcon_array_update_string(&document, SL("time"), timestamp, PH_COPY);
		if (prepared_content) {
			phalcon_array_update_string(&document, SL("data"), prepared_content, PH_COPY);
		} else {
			phalcon_array_update_string(&document, SL("data"), cached_content, PH_COPY);
		}
		PHALCON_CALL_METHOD(NULL, collection, "save", document);
	} else {
		PHALCON_INIT_VAR(data);
		array_init_size(data, 3);
		phalcon_array_update_string(&data, SL("key"), last_key, PH_COPY);
		phalcon_array_update_string(&data, SL("time"), timestamp, PH_COPY);

		if (prepared_content) {
			phalcon_array_update_string(&data, SL("data"), prepared_content, PH_COPY);
		} else {
			phalcon_array_update_string(&data, SL("data"), cached_content, PH_COPY);
		}

		PHALCON_CALL_METHOD(NULL, collection, "save", data);
	}
	
	PHALCON_CALL_METHOD(&is_buffering, frontend, "isbuffering");

	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD(NULL, frontend, "stop");
	}

	if (PHALCON_IS_TRUE(is_buffering)) {
		zend_print_zval(cached_content, 0);
	}
	
	phalcon_update_property_bool(this_ptr, SL("_started"), 0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete){

	zval *key_name, *prefix, *prefixed_key, *collection = NULL;
	zval *conditions;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), prefixed_key, PH_COPY);
	PHALCON_CALL_METHOD(NULL, collection, "remove", conditions);

	if ((php_rand(TSRMLS_C) % 100) == 0) {
		PHALCON_CALL_METHOD(NULL, getThis(), "gc");
	}

	RETURN_MM_TRUE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys){

	zval *prefix = NULL, *collection = NULL, *fields = NULL, *pattern, *regex;
	zval *conditions, *documents = NULL, *documents_array = NULL, *time_condition;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(fields);
	array_init_size(fields, 1);
	add_next_index_stringl(fields, SL("key"), 1);

	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 2);

	if (prefix && zend_is_true(prefix)) {
		PHALCON_INIT_VAR(pattern);
		PHALCON_CONCAT_SVS(pattern, "/^", prefix, "/");
		ce0 = zend_fetch_class(SL("MongoRegex"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
		PHALCON_INIT_VAR(regex);
		object_init_ex(regex, ce0);
		assert(phalcon_has_constructor(regex TSRMLS_CC));
		PHALCON_CALL_METHOD(NULL, regex, "__construct", pattern);
	
		phalcon_array_update_string(&conditions, SL("key"), regex, PH_COPY);
	}
	
	MAKE_STD_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
	phalcon_array_update_string(&conditions, SL("time"), time_condition, 0);

	PHALCON_CALL_METHOD(&documents, collection, "find", conditions, fields);
	
	array_init(return_value);
	
	PHALCON_CALL_FUNCTION(&documents_array, "iterator_to_array", documents);

	phalcon_is_iterable(documents_array, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
		zval *key;
		if (likely(phalcon_array_isset_string_fetch(&key, *hd, SS("key")))) {
			Z_ADDREF_P(key);
			add_next_index_zval(return_value, key);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists){

	zval *key_name = NULL, *lifetime = NULL, *collection = NULL;
	zval *last_key;
	zval *conditions, *number = NULL, *time_condition;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY TSRMLS_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		long int n;

		PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
		PHALCON_INIT_VAR(conditions);
		array_init_size(conditions, 2);
		phalcon_array_update_string(&conditions, SL("key"), last_key, PH_COPY);

		MAKE_STD_ZVAL(time_condition);
		array_init_size(time_condition, 1);
		add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
		phalcon_array_update_string(&conditions, SL("time"), time_condition, 0);
	
		PHALCON_CALL_METHOD(&number, collection, "count", conditions);

		n = likely(Z_TYPE_P(number) == IS_LONG) ? Z_LVAL_P(number) : phalcon_get_intval(number);

		RETVAL_BOOL(n > 0);
	}
	else {
		RETVAL_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval *conditions, *time_condition, *collection = NULL;

	PHALCON_MM_GROW();

	MAKE_STD_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));

	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	add_assoc_zval_ex(conditions, SS("time"), time_condition);

	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	PHALCON_CALL_METHOD(NULL, collection, "remove", conditions);

	PHALCON_MM_RESTORE();
}

/**
 * Increment of a given key by $value
 *
 * @param int|string $keyName
 * @param   long $value
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment){

	zval *key_name, *lifetime = NULL, *frontend, *prefix, *prefixed_key, *value = NULL;
	zval *collection = NULL, *conditions, *document = NULL, *timestamp;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;
	zval *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	} 

	if(Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	if (Z_TYPE_P(value) != IS_LONG) {	
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}

	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), prefixed_key, PH_COPY);
	
	PHALCON_CALL_METHOD(&document, collection, "findone", conditions);

	PHALCON_INIT_VAR(timestamp);
	PHALCON_INIT_VAR(lifetime);
	ZVAL_LONG(timestamp, (long) time(NULL));

	PHALCON_OBS_NVAR(lifetime);
	phalcon_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_CALL_METHOD(&ttl, frontend, "getlifetime");
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}

	/*
	 * phalcon_add_function(newlifetime, ttl, timestamp TSRMLS_CC);
	 */
	
	if (!phalcon_array_isset_string(document, SS("time"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
		return;
	}
	
	PHALCON_OBS_VAR(modified_time);
	phalcon_array_fetch_string(&modified_time, document, SL("time"), PH_NOISY);
	
	PHALCON_INIT_VAR(difference);
	sub_function(difference, timestamp, ttl TSRMLS_CC);
	
	PHALCON_INIT_VAR(not_expired);
	is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
	
	/** 
	 * The expiration is based on the column 'time'
	 */
	if (PHALCON_IS_TRUE(not_expired)) {
		if (!phalcon_array_isset_string(document, SS("data"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
			return;
		}
	
		PHALCON_OBS_VAR(cached_content);
		phalcon_array_fetch_string(&cached_content, document, SL("data"), PH_NOISY);

		if(Z_TYPE_P(cached_content) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(cached_content);
			convert_to_long_ex(&cached_content);
		}

		if (phalcon_is_numeric(cached_content)) {
			add_function(return_value, cached_content, value TSRMLS_CC);
				
			PHALCON_INIT_NVAR(ttl);
			phalcon_add_function(ttl, lifetime, timestamp TSRMLS_CC);

			PHALCON_CALL_METHOD(NULL, this_ptr, "save", prefixed_key, return_value);
		}

		RETURN_MM();
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
PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement){

	zval *key_name, *lifetime = NULL, *frontend, *prefix, *prefixed_key, *value = NULL;
	zval *collection = NULL, *conditions, *document = NULL, *timestamp;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;
	zval *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &value);

	if (!value) {
		PHALCON_INIT_VAR(value);
		ZVAL_LONG(value, 1);
	} 

	if(Z_TYPE_P(value) == IS_NULL) {
		ZVAL_LONG(value, 1);
	}

	if (Z_TYPE_P(value) != IS_LONG) {	
		PHALCON_SEPARATE_PARAM(value);
		convert_to_long_ex(&value);
	}

	PHALCON_OBS_VAR(frontend);
	phalcon_read_property_this(&frontend, this_ptr, SL("_frontend"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(prefix);
	phalcon_read_property_this(&prefix, this_ptr, SL("_prefix"), PH_NOISY TSRMLS_CC);

	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), prefixed_key, PH_COPY);
	
	PHALCON_CALL_METHOD(&document, collection, "findone", conditions);

	PHALCON_INIT_VAR(timestamp);
	PHALCON_INIT_VAR(lifetime);
	ZVAL_LONG(timestamp, (long) time(NULL));

	PHALCON_OBS_NVAR(lifetime);
	phalcon_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_CALL_METHOD(&ttl, frontend, "getlifetime");
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}

	/*
	 * phalcon_add_function(newlifetime, ttl, timestamp TSRMLS_CC);
	 */
	
	if (!phalcon_array_isset_string(document, SS("time"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
		return;
	}
	
	PHALCON_OBS_VAR(modified_time);
	phalcon_array_fetch_string(&modified_time, document, SL("time"), PH_NOISY);
	
	PHALCON_INIT_VAR(difference);
	sub_function(difference, timestamp, ttl TSRMLS_CC);
	
	PHALCON_INIT_VAR(not_expired);
	is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
	
	/** 
	 * The expiration is based on the column 'time'
	 */
	if (PHALCON_IS_TRUE(not_expired)) {
		if (!phalcon_array_isset_string(document, SS("data"))) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
			return;
		}
	
		PHALCON_OBS_VAR(cached_content);
		phalcon_array_fetch_string(&cached_content, document, SL("data"), PH_NOISY);

		if(Z_TYPE_P(cached_content) != IS_LONG) {
			PHALCON_SEPARATE_PARAM(cached_content);
			convert_to_long_ex(&cached_content);
		}

		if (phalcon_is_numeric(cached_content)) {
			sub_function(return_value, cached_content, value TSRMLS_CC);
				
			PHALCON_INIT_NVAR(ttl);
			phalcon_add_function(ttl, lifetime, timestamp TSRMLS_CC);

			PHALCON_CALL_METHOD(NULL, this_ptr, "save", prefixed_key, return_value);
		}

		RETURN_MM();
	}
	
	RETURN_MM_NULL();
}

/**
 * Immediately invalidates all existing items.
 * 
 * @return bool
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush){

	zval *collection = NULL;

	PHALCON_MM_GROW();
	
	PHALCON_CALL_METHOD(&collection, this_ptr, "_getcollection");
	PHALCON_CALL_METHOD(NULL, collection, "remove");

	if ((php_rand(TSRMLS_C) % 100) == 0) {
		PHALCON_CALL_METHOD(NULL, getThis(), "gc");
	}

	RETURN_MM_TRUE;
}
