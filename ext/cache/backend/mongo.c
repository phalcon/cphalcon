
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
 *    "lifetime" => 172800
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
 * $cache->store('my-data', file_get_contents('some-image.jpg'));
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Mongo, cache_backend_mongo, "phalcon\\cache\\backend", phalcon_cache_backend_mongo_method_entry, 0);

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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &frontend, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	eval_int = phalcon_array_isset_string(options, SS("mongo"));
	if (!eval_int) {
		eval_int = phalcon_array_isset_string(options, SS("server"));
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'server' is required");
			return;
		}
	}
	eval_int = phalcon_array_isset_string(options, SS("db"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'db' is required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(options, SS("collection"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The parameter 'collection' is required");
		return;
	}
	
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon\\Cache\\Backend\\Mongo", "__construct", frontend, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a MongoDb collection based on the backend parameters
 *
 * @return MongoCollection
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection){

	zval *mongo_collection = NULL, *options, *mongo = NULL, *server;
	zval *database, *collection, *mongo_database;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(mongo_collection);
	phalcon_read_property(&mongo_collection, this_ptr, SL("_collection"), PH_NOISY_CC);
	if (Z_TYPE_P(mongo_collection) != IS_OBJECT) {
		PHALCON_INIT_VAR(options);
		phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		/** 
		 * If mongo is defined a valid Mongo object must be passed
		 */
		eval_int = phalcon_array_isset_string(options, SS("mongo"));
		if (eval_int) {
			PHALCON_INIT_VAR(mongo);
			phalcon_array_fetch_string(&mongo, options, SL("mongo"), PH_NOISY_CC);
			if (Z_TYPE_P(mongo) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The 'mongo' parameter must be a valid Mongo instance");
				return;
			}
		} else {
			/** 
			 * Server must be defined otherwise
			 */
			PHALCON_INIT_VAR(server);
			phalcon_array_fetch_string(&server, options, SL("server"), PH_NOISY_CC);
			if (Z_TYPE_P(server) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB connection string");
				return;
			}
	
			ce0 = zend_fetch_class(SL("Mongo"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
			PHALCON_INIT_NVAR(mongo);
			object_init_ex(mongo, ce0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(mongo, "__construct", server, PH_CHECK);
		}
	
		/** 
		 * Check if the database name is a string
		 */
		PHALCON_INIT_VAR(database);
		phalcon_array_fetch_string(&database, options, SL("db"), PH_NOISY_CC);
		if (Z_TYPE_P(database) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB db");
			return;
		}
	
		/** 
		 * Retrieve the connection name
		 */
		PHALCON_INIT_VAR(collection);
		phalcon_array_fetch_string(&collection, options, SL("collection"), PH_NOISY_CC);
		if (Z_TYPE_P(collection) != IS_STRING) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The backend requires a valid MongoDB collection");
			return;
		}
	
		/** 
		 * Make the connection and get the collection
		 */
		PHALCON_INIT_VAR(mongo_database);
		PHALCON_CALL_METHOD_PARAMS_1(mongo_database, mongo, "selectdb", database, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(mongo_collection);
		PHALCON_CALL_METHOD_PARAMS_1(mongo_collection, mongo_database, "selectcollection", collection, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(mongo_collection);
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
	zval *collection, *conditions, *document, *time;
	zval *ttl = NULL, *modified_time, *difference, *not_expired;
	zval *cached_content, *content;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	PHALCON_INIT_VAR(frontend);
	phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD(collection, this_ptr, "_getcollection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	phalcon_array_update_string(&conditions, SL("key"), &prefixed_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(document);
	PHALCON_CALL_METHOD_PARAMS_1(document, collection, "findone", conditions, PH_NO_CHECK);
	if (Z_TYPE_P(document) == IS_ARRAY) { 
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			PHALCON_INIT_VAR(ttl);
			PHALCON_CALL_METHOD(ttl, frontend, "getlifetime", PH_NO_CHECK);
		} else {
			PHALCON_CPY_WRT(ttl, lifetime);
		}
	
		eval_int = phalcon_array_isset_string(document, SS("time"));
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
			return;
		}
	
		PHALCON_INIT_VAR(modified_time);
		phalcon_array_fetch_string(&modified_time, document, SL("time"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(difference);
		sub_function(difference, time, ttl TSRMLS_CC);
	
		PHALCON_INIT_VAR(not_expired);
		is_smaller_function(not_expired, difference, modified_time TSRMLS_CC);
	
		/** 
		 * The expiration is based on the column 'time'
		 */
		if (PHALCON_IS_TRUE(not_expired)) {
			eval_int = phalcon_array_isset_string(document, SS("data"));
			if (!eval_int) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache is currupted");
				return;
			}
	
			PHALCON_INIT_VAR(cached_content);
			phalcon_array_fetch_string(&cached_content, document, SL("data"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(content);
			PHALCON_CALL_METHOD_PARAMS_1(content, frontend, "afterretrieve", cached_content, PH_NO_CHECK);
	
			RETURN_CCTOR(content);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	zval *last_key = NULL, *prefix, *frontend, *cached_content = NULL;
	zval *prepared_content, *ttl = NULL, *collection, *time;
	zval *conditions, *document, *data, *is_buffering;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_NVAR(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_NVAR(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_NVAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_INIT_VAR(frontend);
	phalcon_read_property(&frontend, this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (Z_TYPE_P(content) == IS_NULL) {
		PHALCON_INIT_VAR(cached_content);
		PHALCON_CALL_METHOD(cached_content, frontend, "getcontent", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_INIT_VAR(prepared_content);
	PHALCON_CALL_METHOD_PARAMS_1(prepared_content, frontend, "beforestore", cached_content, PH_NO_CHECK);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_INIT_VAR(ttl);
		PHALCON_CALL_METHOD(ttl, frontend, "getlifetime", PH_NO_CHECK);
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}
	
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD(collection, this_ptr, "_getcollection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(time);
	PHALCON_CALL_FUNC(time, "time");
	
	PHALCON_INIT_NVAR(ttl);
	phalcon_add_function(ttl, lifetime, time TSRMLS_CC);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	phalcon_array_update_string(&conditions, SL("key"), &last_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(document);
	PHALCON_CALL_METHOD_PARAMS_1(document, collection, "findone", conditions, PH_NO_CHECK);
	if (Z_TYPE_P(document) == IS_ARRAY) { 
		phalcon_array_update_string(&document, SL("time"), &ttl, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&document, SL("data"), &prepared_content, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "save", document, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(data);
		array_init(data);
		phalcon_array_update_string(&data, SL("key"), &last_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&data, SL("time"), &ttl, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&data, SL("data"), &prepared_content, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "save", data, PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(is_buffering);
	PHALCON_CALL_METHOD(is_buffering, frontend, "isbuffering", PH_NO_CHECK);
	if (PHALCON_IS_TRUE(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(frontend, "stop", PH_NO_CHECK);
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
	zval *conditions, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(prefix);
	phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(prefixed_key);
	PHALCON_CONCAT_VV(prefixed_key, prefix, key_name);
	
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD(collection, this_ptr, "_getcollection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	phalcon_array_update_string(&conditions, SL("key"), &prefixed_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, collection, "remove", conditions, PH_NO_CHECK);
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys){

	zval *prefix = NULL, *collection, *fields = NULL, *pattern, *regex;
	zval *conditions = NULL, *documents, *keys, *documents_array;
	zval *document = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_NVAR(prefix);
	}
	
	PHALCON_INIT_VAR(collection);
	PHALCON_CALL_METHOD(collection, this_ptr, "_getcollection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	add_next_index_stringl(fields, SL("key"), 1);
	if (Z_TYPE_P(prefix) != IS_NULL) {
		PHALCON_INIT_VAR(pattern);
		PHALCON_CONCAT_SVS(pattern, "/^", prefix, "/");
		ce0 = zend_fetch_class(SL("MongoRegex"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
		PHALCON_INIT_VAR(regex);
		object_init_ex(regex, ce0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(regex, "__construct", pattern, PH_CHECK);
	
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);
		phalcon_array_update_string(&conditions, SL("key"), &regex, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(conditions);
		array_init(conditions);
	}
	
	PHALCON_INIT_NVAR(fields);
	array_init(fields);
	add_next_index_stringl(fields, SL("key"), 1);
	
	PHALCON_INIT_VAR(documents);
	PHALCON_CALL_METHOD_PARAMS_2(documents, collection, "find", conditions, fields, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(keys);
	array_init(keys);
	
	PHALCON_INIT_VAR(documents_array);
	PHALCON_CALL_FUNC_PARAMS_1(documents_array, "iterator_to_array", documents);
	
	if (!phalcon_valid_foreach(documents_array TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(documents_array);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(document);
	
		PHALCON_INIT_NVAR(key);
		phalcon_array_fetch_string(&key, document, SL("key"), PH_NOISY_CC);
		phalcon_array_append(&keys, key, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
	RETURN_CTOR(keys);
}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string $keyName
 * @param  long $lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists){

	zval *key_name = NULL, *lifetime = NULL, *last_key = NULL, *prefix, *collection;
	zval *conditions, *number, *zero, *exists;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_NVAR(key_name);
	}
	
	if (!lifetime) {
		PHALCON_INIT_NVAR(lifetime);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_INIT_VAR(last_key);
		phalcon_read_property(&last_key, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(prefix);
		phalcon_read_property(&prefix, this_ptr, SL("_prefix"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(last_key);
		PHALCON_CONCAT_VV(last_key, prefix, key_name);
	}
	if (zend_is_true(last_key)) {
		PHALCON_INIT_VAR(collection);
		PHALCON_CALL_METHOD(collection, this_ptr, "_getcollection", PH_NO_CHECK);
	
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);
		phalcon_array_update_string(&conditions, SL("key"), &last_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_VAR(number);
		PHALCON_CALL_METHOD_PARAMS_1(number, collection, "count", conditions, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(zero);
		ZVAL_LONG(zero, 0);
	
		PHALCON_INIT_VAR(exists);
		is_smaller_function(exists, zero, number TSRMLS_CC);
	
		RETURN_NCTOR(exists);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

