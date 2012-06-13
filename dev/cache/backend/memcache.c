
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Cache_Backend_Memcache
 *
 * Allows to cache output fragments using a memcache backend
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
	zval *a0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_cache_backend_memcache_ce, this_ptr, "_backendOptions", strlen("_backendOptions"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &frontend_object, &backend_options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(backend_options);
	
	eval_int = phalcon_array_isset_string(backend_options, "host", strlen("host")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_STRING(t0, "127.0.0.1", 1);
		phalcon_array_update_string(&backend_options, "host", strlen("host"), &t0, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(backend_options, "port", strlen("port")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t1);
		ZVAL_STRING(t1, "11211", 1);
		phalcon_array_update_string(&backend_options, "port", strlen("port"), &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(backend_options, "persistent", strlen("persistent")+1);
	if (!eval_int) {
		PHALCON_INIT_VAR(t2);
		ZVAL_BOOL(t2, 0);
		phalcon_array_update_string(&backend_options, "persistent", strlen("persistent"), &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, "_frontendObject", strlen("_frontendObject"), frontend_object TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_backendOptions", strlen("_backendOptions"), backend_options TSRMLS_CC);
	
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
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend_options, t0);
	ce0 = zend_fetch_class("Memcache", strlen("Memcache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CHECK);
	PHALCON_CPY_WRT(memcache, i0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, backend_options, "host", strlen("host"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(host, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, backend_options, "port", strlen("port"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(port, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_string(&r2, backend_options, "persistent", strlen("persistent"), PHALCON_NOISY TSRMLS_CC);
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
	
	phalcon_update_property_zval(this_ptr, "_memcache", strlen("_memcache"), memcache TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Starts a cache. The $keyname allow to identify the created fragment
 *
 * @param int|string $keyName
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, start){

	zval *key_name = NULL, *backend = NULL, *front_end = NULL, *existing_cache = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD_PARAMS_1(r0, this_ptr, "get", key_name, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(existing_cache, r0);
	
	PHALCON_INIT_VAR(t2);
	ZVAL_NULL(t2);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, existing_cache, t2 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "start", PHALCON_NO_CHECK);
	}
	
	
	PHALCON_RETURN_CHECK_CTOR(existing_cache);
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
	zval *cached_content = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;

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
	phalcon_read_property(&t0, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t2);
	phalcon_update_property_zval(this_ptr, "_lastKey", strlen("_lastKey"), key_name TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t3, "get", key_name, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(cached_content, r0);
	if (Z_TYPE_P(cached_content) == IS_BOOL && !Z_BVAL_P(cached_content)) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, front_end, "afterretrieve", cached_content, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r1);
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
	zval *last_key = NULL, *front_end = NULL, *backend = NULL, *cached_content = NULL;
	zval *prepared_content = NULL, *ttl = NULL, *memcache = NULL, *success = NULL;
	zval *is_buffering = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p4[] = { NULL, NULL, NULL, NULL };

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
		phalcon_read_property(&t0, this_ptr, "_lastKey", sizeof("_lastKey")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(last_key, t0);
	} else {
		PHALCON_CPY_WRT(last_key, key_name);
	}
	if (!zend_is_true(last_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_backendOptions", sizeof("_backendOptions")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t2);
	
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t3)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	if (!zend_is_true(content)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD(r0, front_end, "getcontent", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(cached_content, r0);
	} else {
		PHALCON_CPY_WRT(cached_content, content);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, front_end, "beforestore", cached_content, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(prepared_content, r1);
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, front_end, "getlifetime", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(ttl, r2);
	} else {
		PHALCON_CPY_WRT(ttl, lifetime);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t4);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	p4[0] = last_key;
	p4[1] = prepared_content;
	
	PHALCON_INIT_VAR(p4[2]);
	ZVAL_BOOL(p4[2], 0);
	p4[3] = ttl;
	PHALCON_CALL_METHOD_PARAMS(r3, memcache, "set", 4, p4, PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(success, r3);
	if (!zend_is_true(success)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Failed storing data in memcached");
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, front_end, "isbuffering", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(is_buffering, r4);
	if (zend_is_true(stop_buffer)) {
		PHALCON_CALL_METHOD_NORETURN(front_end, "stop", PHALCON_NO_CHECK);
	}
	
	if (zend_is_true(is_buffering)) {
		zend_print_zval(cached_content, 1);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete){

	zval *key_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "_connect", PHALCON_NO_CHECK);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_1(r0, t1, "delete", key_name, PHALCON_NO_CHECK);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns front-end instance adapter related to the back-end
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Memcache, getFrontend){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_frontendObject", sizeof("_frontendObject")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

PHP_METHOD(Phalcon_Cache_Backend_Memcache, __destruct){

	zval *memcache = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_memcache", sizeof("_memcache")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(memcache, t0);
	if (zend_is_true(memcache)) {
		PHALCON_CALL_METHOD_NORETURN(memcache, "close", PHALCON_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

