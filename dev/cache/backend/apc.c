
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

#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
/**
 * Phalcon_Cache_Backend_Apc
 *
 * Allows to cache output fragments, PHP data and raw data using a memcache backend
 *
 *
 */

/**
 * Returns a cached content
 *
 * @param int|string $keyName
 * @param   long $lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, get){

	zval *key_name = NULL, *lifetime = NULL, *backend = NULL, *front_end = NULL;
	zval *prefixed_key = NULL, *cached_content = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
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
	phalcon_read_property(&t0, this_ptr, SL("_backendOptions"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(backend, t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_frontendObject"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(front_end, t1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SVV(r0, "_PHCA", t2, key_name);
	PHALCON_CPY_WRT(prefixed_key, r0);
	phalcon_update_property_zval(this_ptr, SL("_lastKey"), prefixed_key TSRMLS_CC);
	
	PHALCON_INIT_VAR(cached_content);
	PHALCON_CALL_FUNC_PARAMS_1(cached_content, "apc_fetch", prefixed_key);
	if (Z_TYPE_P(cached_content) == IS_BOOL && !Z_BVAL_P(cached_content)) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD_PARAMS_1(r1, front_end, "afterretrieve", cached_content, PHALCON_NO_CHECK);
	RETURN_DZVAL(r1);
}

/**
 * Stores cached content into the file backend
 *
 * @param int|string $keyName
 * @param string $content
 * @param long $lifetime
 * @param boolean $stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save){

	zval *key_name = NULL, *content = NULL, *lifetime = NULL, *stop_buffer = NULL;
	zval *last_key = NULL, *front_end = NULL, *backend = NULL, *cached_content = NULL;
	zval *prepared_content = NULL, *ttl = NULL, *is_buffering = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

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
		PHALCON_CONCAT_SVV(r0, "_PHCA", t1, key_name);
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
	PHALCON_CPY_WRT(backend, t3);
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
	
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("apc_store", last_key, prepared_content, ttl);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD(r4, front_end, "isbuffering", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(is_buffering, r4);
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
 * @param string|int $keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete){

	zval *key_name = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_prefix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SVV(r0, "_PHCA", t0, key_name);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "apc_delete", r0);
	RETURN_DZVAL(r1);
}

/**
 * Query the existing cached keys
 *
 * @param string $prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys){

	zval *prefix = NULL, *keys = NULL, *iterator = NULL;
	zval *a0 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &prefix) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prefix) {
		PHALCON_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_CPY_WRT(keys, a0);
	ce0 = zend_fetch_class("APCIterator", strlen("APCIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, ce0);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "user", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVS(r0, "/^_PHCA", prefix, "/");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", c0, r0, PHALCON_CHECK);
	PHALCON_CPY_WRT(iterator, i0);
	PHALCON_CALL_METHOD_NORETURN(iterator, "rewind", PHALCON_NO_CHECK);
	ws_e532_0:
		
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, iterator, "valid", PHALCON_NO_CHECK);
		if (!zend_is_true(r1)) {
			goto we_e532_0;
		}
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, iterator, "key", PHALCON_NO_CHECK);
		phalcon_array_append(&keys, r2, PHALCON_SEPARATE_PLZ TSRMLS_CC);
		PHALCON_CALL_METHOD_NORETURN(iterator, "next", PHALCON_NO_CHECK);
		goto ws_e532_0;
	we_e532_0:
	
	RETURN_CTOR(keys);
}

