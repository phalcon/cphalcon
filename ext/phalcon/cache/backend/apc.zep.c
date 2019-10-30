
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/iterator.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * Phalcon\Cache\Backend\Apc
 *
 * Allows to cache output fragments, PHP data and raw data using an APC backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Apc;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Apc(
 *     $frontCache,
 *     [
 *         "prefix" => "app-data",
 *     ]
 * );
 *
 * // Cache arbitrary data
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get("my-data");
 *</code>
 *
 * @see \Phalcon\Cache\Backend\Apcu
 * @deprecated
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apc, phalcon, cache_backend_apc, phalcon_cache_backend_ce, phalcon_cache_backend_apc_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, get) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime_param = NULL, *prefixedKey = NULL, *cachedContent = NULL, *_0, *_1;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime_param);

	zephir_get_strval(keyName, keyName_param);
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCA", _0, keyName);
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 90, prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(cachedContent)) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "afterretrieve", NULL, 0, cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string|int keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend = NULL, *cachedContent = NULL, *preparedContent = NULL, *ttl = NULL, *isBuffering = NULL, *success = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		ZEPHIR_CPY_WRT(lifetime, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(lifetime);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0$$4, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/apc.zep", 98);
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
	} else {
		ZEPHIR_CPY_WRT(preparedContent, cachedContent);
	}
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_NVAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
			zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_CALL_FUNCTION(&success, "apc_store", NULL, 91, lastKey, preparedContent, ttl);
	zephir_check_call_status();
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in apc", "phalcon/cache/backend/apc.zep", 135);
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
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Increment of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey = NULL, *cachedContent = NULL, *result = NULL, *_0, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCA", _0, keyName);
	zephir_update_property_this(getThis(), SL("_lastKey"), prefixedKey TSRMLS_CC);
	if ((zephir_function_exists_ex(SS("apc_inc") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_LONG(_1$$3, value);
		ZEPHIR_CALL_FUNCTION(&result, "apc_inc", NULL, 115, prefixedKey, _1$$3);
		zephir_check_call_status();
		RETURN_CCTOR(result);
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 90, prefixedKey);
		zephir_check_call_status();
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_NVAR(result);
			ZVAL_LONG(result, (zephir_get_numberval(cachedContent) + value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, result);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Decrement of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *lastKey = NULL, *cachedContent = NULL, *result = NULL, *_0, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lastKey);
	ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0, keyName);
	zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	if ((zephir_function_exists_ex(SS("apc_dec") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_LONG(_1$$3, value);
		ZEPHIR_RETURN_CALL_FUNCTION("apc_dec", NULL, 116, lastKey, _1$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 90, lastKey);
		zephir_check_call_status();
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(result);
			ZVAL_LONG(result, (zephir_get_numberval(cachedContent) - value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, result);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Deletes a value from the cache by its key
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *_0, *_1;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

	if (UNEXPECTED(Z_TYPE_P(keyName_param) != IS_STRING && Z_TYPE_P(keyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'keyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(keyName_param) == IS_STRING)) {
		zephir_get_strval(keyName, keyName_param);
	} else {
		ZEPHIR_INIT_VAR(keyName);
		ZVAL_EMPTY_STRING(keyName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "_PHCA", _0, keyName);
	ZEPHIR_RETURN_CALL_FUNCTION("apc_delete", NULL, 117, _1);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys) {

	zend_object_iterator *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *prefixPattern = NULL, *apc = NULL, *keys = NULL, *key = NULL, *_1 = NULL, _3$$5 = zval_used_for_init, *_4$$5 = NULL;
	zval *prefix = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(prefixPattern);
	if (ZEPHIR_IS_EMPTY(prefix)) {
		ZVAL_STRING(prefixPattern, "/^_PHCA/", 1);
	} else {
		ZEPHIR_INIT_VAR(_0$$4);
		ZEPHIR_CONCAT_SVS(_0$$4, "/^_PHCA", prefix, "/");
		ZEPHIR_CPY_WRT(prefixPattern, _0$$4);
	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(apc);
	object_init_ex(apc, zephir_get_internal_ce(SS("apciterator") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, _1, prefixPattern);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	_2 = zephir_get_iterator(apc TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(key, _2);
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_2->funcs->get_current_data(_2, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(_1, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_SINIT_NVAR(_3$$5);
		ZVAL_LONG(&_3$$5, 5);
		ZEPHIR_INIT_NVAR(_4$$5);
		zephir_substr(_4$$5, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&keys, _4$$5, PH_SEPARATE, "phalcon/cache/backend/apc.zep", 240);
	}
	_2->funcs->dtor(_2 TSRMLS_CC);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|int keyName
 * @param  int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists) {

	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *_0$$4, *_1$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime_param);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime_param) {
		lifetime = 0;
	} else {
		lifetime = zephir_get_intval(lifetime_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0$$4, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_CALL_FUNCTION(&_1$$5, "apc_exists", NULL, 118, lastKey);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(_1$$5)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Immediately invalidates all existing items.
 *
 * <code>
 * use Phalcon\Cache\Backend\Apc;
 *
 * $cache = new Apc($frontCache, ["prefix" => "app-data"]);
 *
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // 'my-data' and all other used keys are deleted
 * $cache->flush();
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, flush) {

	zend_object_iterator *_1;
	zval *item = NULL, *prefixPattern = NULL, *_0, *_2, *_3, *_4$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixPattern);
	ZEPHIR_CONCAT_SVS(prefixPattern, "/^_PHCA", _0, "/");
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("apciterator") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0, _3, prefixPattern);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	_1 = zephir_get_iterator(_2 TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_array_fetch_string(&_4$$3, item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/apc.zep", 292 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "apc_delete", &_5, 117, _4$$3);
		zephir_check_call_status();
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

