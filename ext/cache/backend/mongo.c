
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "ext/standard/php_rand.h"

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
	
	phalcon_call_parent_p2_noret(this_ptr, phalcon_cache_backend_mongo_ce, "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection){

	zval *mongo_collection, *mongo_database;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	mongo_collection = phalcon_fetch_nproperty_this(this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		zval *options, *mongo;
		zval *server = NULL, *database = NULL, *collection = NULL;

		options = phalcon_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	
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
	
			ce0 = zend_fetch_class(SL("Mongo"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
			PHALCON_INIT_VAR(mongo);
			object_init_ex(mongo, ce0);
			assert(phalcon_has_constructor(mongo TSRMLS_CC));
			phalcon_call_method_p1_noret(mongo, "__construct", server);
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
		PHALCON_OBS_VAR(mongo_database);
		phalcon_call_method_p1_ex(mongo_database, &mongo_database, mongo, "selectdb", database);
	
		phalcon_return_call_method_p1(mongo_database, "selectcollection", collection);
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
	zval *collection, *conditions, *document, *time_condition;
	zval *cached_content;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key_name, &lifetime);
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	prefix   = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_this(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_OBS_VAR(collection);
	phalcon_call_method_p0_ex(collection, &collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 2);
	phalcon_array_update_string(&conditions, SL("key"), &prefixed_key, PH_COPY);
	
	ALLOC_INIT_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
	add_assoc_zval_ex(conditions, SS("time"), time_condition);

	PHALCON_OBS_VAR(document);
	phalcon_call_method_p1_ex(document, &document, collection, "findone", conditions);
	if (Z_TYPE_P(document) == IS_ARRAY) { 
		if (likely(phalcon_array_isset_string_fetch(&cached_content, document, SS("data")))) {
			phalcon_return_call_method_p1(frontend, "afterretrieve", cached_content);
			RETURN_MM();
		}
		else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is corrupt");
			return;
		}
	}
	
	RETURN_MM_NULL();
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
	zval *prepared_content, *ttl = NULL, *collection, *timestamp;
	zval *conditions, *document, *data, *is_buffering;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 4, &key_name, &content, &lifetime, &stop_buffer);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	frontend = phalcon_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		PHALCON_OBS_VAR(cached_content);
		phalcon_call_method_p0_ex(cached_content, &cached_content, frontend, "getcontent");
	} else {
		cached_content = content;
	}
	
	PHALCON_OBS_VAR(prepared_content);
	phalcon_call_method_p1_ex(prepared_content, &prepared_content, frontend, "beforestore", cached_content);

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		zval *tmp = phalcon_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);

		if (Z_TYPE_P(tmp) == IS_NULL) {
			PHALCON_OBS_VAR(ttl);
			phalcon_call_method_p0_ex(ttl, &ttl, frontend, "getlifetime");
		}
		else {
			ttl = tmp;
		}
	} else {
		ttl = lifetime;
	}
	
	PHALCON_OBS_VAR(collection);
	phalcon_call_method_p0_ex(collection, &collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(timestamp);
	ZVAL_LONG(timestamp, (long) time(NULL) + phalcon_get_intval(ttl));
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), &last_key, PH_COPY);
	
	PHALCON_OBS_VAR(document);
	phalcon_call_method_p1_ex(document, &document, collection, "findone", conditions);

	if (Z_TYPE_P(document) == IS_ARRAY) { 
		phalcon_array_update_string(&document, SL("time"), &timestamp, PH_COPY);
		phalcon_array_update_string(&document, SL("data"), &prepared_content, PH_COPY);
		phalcon_call_method_p1_noret(collection, "save", document);
	} else {
		PHALCON_INIT_VAR(data);
		array_init_size(data, 3);
		phalcon_array_update_string(&data, SL("key"), &last_key, PH_COPY);
		phalcon_array_update_string(&data, SL("time"), &timestamp, PH_COPY);
		phalcon_array_update_string(&data, SL("data"), &prepared_content, PH_COPY);
		phalcon_call_method_p1_noret(collection, "save", data);
	}
	
	PHALCON_OBS_VAR(is_buffering);
	phalcon_call_method_p0_ex(is_buffering, &is_buffering, frontend, "isbuffering");

	if (!stop_buffer || PHALCON_IS_TRUE(stop_buffer)) {
		phalcon_call_method_noret(frontend, "stop");
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

	zval *key_name, *prefix, *prefixed_key, *collection;
	zval *conditions;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &key_name);
	
	prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	PHALCON_OBS_VAR(collection);
	phalcon_call_method_p0_ex(collection, &collection, this_ptr, "_getcollection");
	
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	phalcon_array_update_string(&conditions, SL("key"), &prefixed_key, PH_COPY);
	phalcon_call_method_p1_noret(collection, "remove", conditions);

	if ((php_rand(TSRMLS_C) % 100) == 0) {
		phalcon_call_method_noret(getThis(), "gc");
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

	zval *prefix = NULL, *collection, *fields = NULL, *pattern, *regex;
	zval *conditions, *documents, *documents_array, *time_condition;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &prefix);
	
	PHALCON_INIT_VAR(collection);
	phalcon_call_method(collection, this_ptr, "_getcollection");
	
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
		phalcon_call_method_p1_noret(regex, "__construct", pattern);
	
		phalcon_array_update_string(&conditions, SL("key"), &regex, PH_COPY);
	}
	
	ALLOC_INIT_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
	phalcon_array_update_string(&conditions, SL("time"), &time_condition, 0);

	PHALCON_OBS_VAR(documents);
	phalcon_call_method_p2_ex(documents, &documents, collection, "find", conditions, fields);
	
	array_init(return_value);
	
	PHALCON_OBS_VAR(documents_array);
	phalcon_call_func_p1_ex(documents_array, &documents_array, "iterator_to_array", documents);

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

	zval *key_name = NULL, *lifetime = NULL, *collection;
	zval *last_key;
	zval *conditions, *number, *time_condition;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &key_name, &lifetime);
	
	if (!key_name || Z_TYPE_P(key_name) == IS_NULL) {
		last_key = phalcon_fetch_nproperty_this(this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zval *prefix = phalcon_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}

	if (zend_is_true(last_key)) {
		long int n;

		PHALCON_OBS_VAR(collection);
		phalcon_call_method_p0_ex(collection, &collection, this_ptr, "_getcollection");
	
		PHALCON_INIT_VAR(conditions);
		array_init_size(conditions, 2);
		phalcon_array_update_string(&conditions, SL("key"), &last_key, PH_COPY);

		ALLOC_INIT_ZVAL(time_condition);
		array_init_size(time_condition, 1);
		add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));
		phalcon_array_update_string(&conditions, SL("time"), &time_condition, 0);
	
		PHALCON_OBS_VAR(number);
		phalcon_call_method_p1_ex(number, &number, collection, "count", conditions);

		n = likely(Z_TYPE_P(number) == IS_LONG) ? Z_LVAL_P(number) : phalcon_get_intval(number);

		RETVAL_BOOL(n > 0);
	}
	else {
		RETVAL_FALSE;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc) {

	zval *conditions, *time_condition, *collection;

	PHALCON_MM_GROW();

	ALLOC_INIT_ZVAL(time_condition);
	array_init_size(time_condition, 1);
	add_assoc_long_ex(time_condition, SS("$gt"), (long int)time(NULL));

	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 1);
	add_assoc_zval_ex(conditions, SS("time"), time_condition);

	PHALCON_OBS_VAR(collection);
	phalcon_call_method_p0_ex(collection, &collection, this_ptr, "_getcollection");
	phalcon_call_method_p1_noret(collection, "remove", conditions);

	PHALCON_MM_RESTORE();
}
