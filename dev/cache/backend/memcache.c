
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
/**
 * Phalcon_Cache_Backend_Memcache
 *
 * Allows to cache output fragments, PHP data or raw data to a memcache backend
 *
 * This adapter uses the special memcached key "_PHCM" to store all the keys internally used by the adapter
 *
 *
 */

/**
 * Phalcon_Backend_Adapter_Memcache constructor
 *
 * @param mixed $frontendObject
 * @param array $backendOptions
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct){

	zval *frontend_object = NULL, *backend_options = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &frontend_object, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(backend_options);
	
	eval_int = phalcon_array_isset_string(backend_options, SL("host")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "127.0.0.1", 1);
		phalcon_array_update_string(&backend_options, SL("host"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(backend_options, SL("port")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "11211", 1);
		phalcon_array_update_string(&backend_options, SL("port"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, SL("persistent")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		phalcon_array_update_string(&backend_options, SL("persistent"), &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, SL("statsKey")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t3);
		ZVAL_STRING(t3, "_PHCM", 1);
		phalcon_array_update_string(&backend_options, SL("statsKey"), &t3, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon_Cache_Backend_Memcache", "__construct", frontend_object, backend_options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Create internal connection to memcached
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect){

	zval *backend_options = NULL, *memcache = NULL, *host = NULL, *port = NULL;
	zval *persistent = NULL, *success = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend_options, t0);
	ce0 = zend_fetch_class("Memcache", strlen("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(memcache, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend_options, SL("host"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(host, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend_options, SL("port"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(port, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, backend_options, SL("persistent"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(persistent, r2);
	if (zend_is_true(persistent)) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD_PARAMS_2(r3, memcache, "connect", host, port, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r3);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r4);
		PHALCON_CALL_METHOD_PARAMS_2(r4, memcache, "pconnect", host, port, PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(success, r4);
	}
	
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Cannot connect to Memcached server");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_memcache"), memcache TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, get){

	zval *key_name = NULL, *lifetime = NULL, *backend = NULL, *front_end = NULL;
	zval *prefixed_key = NULL, *cached_content = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &key_name, &lifetime) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_frontendObject"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t2);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t3, key_name);
	PHALCON_CPY_WRT(prefixed_key, r0);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r1, t4, "get", prefixed_key, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(cached_content, r1);
	if (Z_TYPE_P(cached_content) == IS_BOOL && !Z_BVAL_P(cached_content)) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_1(r2, front_end, "afterretrieve", cached_content, PHALCON_NO_CHECK);
	RETURN_DZVAL(r2);
}

/**
 * Stores cached content into the file backend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *front_end = NULL, *backend_options = NULL;
	zval *cached_content = NULL, *prepared_content = NULL, *ttl = NULL;
	zval *memcache = NULL, *success = NULL, *special_key = NULL, *keys = NULL, *is_buffering = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zzzz", &key_name, &content, &lifetime, &stop_buffer) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!key_name) {
		PHALCON_INIT_VAR(key_name);
		ZVAL_NULL(key_name);
	}
	
	if (!content) {
		PHALCON_INIT_VAR(content);
		ZVAL_NULL(content);
	}
	
	if (!lifetime) {
		PHALCON_INIT_VAR(lifetime);
		ZVAL_NULL(lifetime);
	}
	
	if (!stop_buffer) {
		PHALCON_INIT_VAR(stop_buffer);
		ZVAL_BOOL(stop_buffer, 1);
	}
	
	if (Z_TYPE_P(key_name) == IS_NULL) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_lastKey"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(last_key, t0);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CONCAT_VV(r0, t1, key_name);
		PHALCON_CPY_WRT(last_key, r0);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_frontendObject"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t2);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend_options, t3);
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t4)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	if (!zend_is_true(content)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, front_end, "getcontent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cached_content, r1);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_1(r2, front_end, "beforestore", cached_content, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(prepared_content, r2);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD(r3, front_end, "getlifetime", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(ttl, r3);
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_read_property(&t5, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t5);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 0);
	PHALCON_CALL_METHOD_PARAMS_4(r4, memcache, "set", last_key, prepared_content, c0, ttl, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(success, r4);
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_array_fetch_string(&r5, backend_options, SL("statsKey"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(special_key, r5);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_CALL_METHOD_PARAMS_1(r6, memcache, "get", special_key, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(keys, r6);
	if (Z_TYPE_P(keys) != IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(keys, a0);
	}
	
	eval_int = phalcon_array_isset(keys, last_key);
	if (!eval_int) {
		phalcon_array_update(&keys, last_key, &ttl, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(memcache, "set", special_key, keys, PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	PHALCON_CALL_METHOD(r7, front_end, "isbuffering", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(is_buffering, r7);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PHALCON_NO_CHECK);
	}
	
	if (zend_is_true(is_buffering)) {
		zend_print_zval(cached_content, 1);
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
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete){

	zval *key_name = NULL, *memcache = NULL, *prefixed_key = NULL, *backend_options = NULL;
	zval *special_key = NULL, *keys = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_VV(r0, t2, key_name);
	PHALCON_CPY_WRT(prefixed_key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend_options, t3);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend_options, SL("statsKey"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(special_key, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_1(r2, memcache, "get", special_key, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(keys, r2);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		PHALCON_SEPARATE(keys);
		phalcon_array_unset(keys, prefixed_key);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(memcache, "set", special_key, keys, PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_CALL_METHOD_PARAMS_1(r3, memcache, "delete", prefixed_key, PHALCON_NO_CHECK);
	RETURN_DZVAL(r3);
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys){

	zval *prefix = NULL, *memcache = NULL, *start = NULL, *prefix_length = NULL;
	zval *backend_options = NULL, *special_key = NULL, *keys = NULL, *prefixed_keys = NULL;
	zval *ttl = NULL, *key = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_NULL(prefix);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t1);
	
	PHALCON_INIT_VAR(start);
	ZVAL_LONG(start, 0);
	
	PHALCON_INIT_VAR(prefix_length);
	PHALCON_CALL_FUNC_PARAMS_1(prefix_length, "strlen", prefix);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend_options, t2);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend_options, SL("statsKey"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(special_key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, memcache, "get", special_key, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(keys, r1);
	if (Z_TYPE_P(keys) == IS_ARRAY) { 
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(prefixed_keys, a0);
		if (phalcon_valid_foreach(keys TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(keys);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_be7f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_be7f_0;
			} else {
				PHALCON_INIT_VAR(key);
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			}
			PHALCON_INIT_VAR(ttl);
			ZVAL_ZVAL(ttl, *hd, 1, 0);
			if (zend_is_true(prefix)) {
				PHALCON_INIT_VAR(r2);
				PHALCON_CALL_FUNC_PARAMS_3(r2, "substr", key, start, prefix_length);
				PHALCON_INIT_VAR(r3);
				is_not_equal_function(r3, r2, prefix TSRMLS_CC);
				if (zend_is_true(r3)) {
					goto fes_be7f_0;
				}
			}
			phalcon_array_append(&prefixed_keys, key, PHALCON_SEPARATE_PLZ TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_be7f_0;
			fee_be7f_0:
			if(0){}
		} else {
			return;
		}
		
		RETURN_CTOR(prefixed_keys);
	}
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	
	RETURN_CTOR(a1);
}

/**
 * Destructs the backend closing the memcached connection
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, __destruct){

	zval *memcache = NULL, *backend_options = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_memcache"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t0);
	if (zend_is_true(memcache)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(backend_options, t1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, backend_options, SL("persistent"), PHALCON_NOISY TSRMLS_CC);
		if (!zend_is_true(r0)) {
			PHALCON_CALL_METHOD_NORETURN(memcache, "close", PHALCON_NO_CHECK);
		}
	}
	
	PHALCON_MM_RESTORE();
}

