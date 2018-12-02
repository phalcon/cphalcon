
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
 * Phalcon\Cache\Backend\Apcu
 *
 * Allows to cache output fragments, PHP data and raw data using an APCu backend
 *
 *<code>
 * use Phalcon\Cache\Backend\Apcu;
 * use Phalcon\Cache\Frontend\Data as FrontData;
 *
 * // Cache data for 2 days
 * $frontCache = new FrontData(
 *     [
 *         "lifetime" => 172800,
 *     ]
 * );
 *
 * $cache = new Apcu(
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apcu) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apcu, phalcon, cache_backend_apcu, phalcon_cache_backend_ce, phalcon_cache_backend_apcu_method_entry, 0);

	return SUCCESS;

}

/**
 * Returns a cached content
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, get) {

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
	ZEPHIR_CALL_FUNCTION(&cachedContent, "apcu_fetch", NULL, 92, prefixedKey);
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
 * Stores cached content into the APCu backend and stops the frontend
 *
 * @param string|int keyName
 * @param string content
 * @param int lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, save) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/apcu.zep", 95);
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
	ZEPHIR_CALL_FUNCTION(&success, "apcu_store", NULL, 93, lastKey, preparedContent, ttl);
	zephir_check_call_status();
	if (!(zephir_is_true(success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in APCu", "phalcon/cache/backend/apcu.zep", 132);
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
PHP_METHOD(Phalcon_Cache_Backend_Apcu, increment) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *prefixedKey = NULL, *_0, *_1;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_inc", NULL, 119, prefixedKey, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param string keyName
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, decrement) {

	zend_long value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *value_param = NULL, *lastKey = NULL, *_0, *_1;

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
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_dec", NULL, 120, lastKey, _1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a value from the cache by its key
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, delete) {

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
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_delete", NULL, 121, _1);
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
PHP_METHOD(Phalcon_Cache_Backend_Apcu, queryKeys) {

	zend_class_entry *_3$$5 = NULL;
	zend_object_iterator *_5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, *prefixPattern = NULL, *apc = NULL, *keys = NULL, *key = NULL, _1, _2, *_6 = NULL, *_4$$6, _7$$8 = zval_used_for_init, *_8$$8 = NULL;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "APCUIterator", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "APCIterator", 0);
	if (zephir_class_exists(&_1, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(apc);
		if (!_3$$5) {
			_3$$5 = zend_fetch_class(SL("APCUIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(apc, _3$$5);
		if (zephir_has_constructor(apc TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, prefixPattern);
			zephir_check_call_status();
		}
	} else if (zephir_class_exists(&_2, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(apc);
		object_init_ex(apc, zephir_get_internal_ce(SS("apciterator") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4$$6);
		ZVAL_STRING(_4$$6, "user", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, _4$$6, prefixPattern);
		zephir_check_temp_parameter(_4$$6);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(apc) != IS_OBJECT) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_6);
	_5 = zephir_get_iterator(apc TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(key, _5);
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_5->funcs->get_current_data(_5, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(_6, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_SINIT_NVAR(_7$$8);
		ZVAL_LONG(&_7$$8, 5);
		ZEPHIR_INIT_NVAR(_8$$8);
		zephir_substr(_8$$8, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&keys, _8$$8, PH_SEPARATE, "phalcon/cache/backend/apcu.zep", 222);
	}
	_5->funcs->dtor(_5 TSRMLS_CC);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|int keyName
 * @param  int lifetime
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, exists) {

	zval *_1$$3 = NULL;
	zend_long lifetime, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, *lifetime_param = NULL, *lastKey = NULL, *_0$$3, *_2$$4;

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


	ZEPHIR_INIT_VAR(lastKey);
	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("_lastKey"), PH_NOISY_CC);
		zephir_get_strval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(lastKey, _1$$3);
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _2$$4, keyName);
	}
	if (ZEPHIR_IS_EMPTY(lastKey)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("apcu_exists", NULL, 122, lastKey);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Immediately invalidates all existing items.
 *
 * <code>
 * use Phalcon\Cache\Backend\Apcu;
 *
 * $cache = new Apcu($frontCache, ["prefix" => "app-data"]);
 *
 * $cache->save("my-data", [1, 2, 3, 4, 5]);
 *
 * // 'my-data' and all other used keys are deleted
 * $cache->flush();
 * </code>
 */
PHP_METHOD(Phalcon_Cache_Backend_Apcu, flush) {

	zend_class_entry *_3$$3 = NULL;
	zend_object_iterator *_5;
	zval *item = NULL, *prefixPattern = NULL, *apc = NULL, *_0, _1, _2, *_4$$4, *_6$$6;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(apc);
	ZVAL_NULL(apc);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixPattern);
	ZEPHIR_CONCAT_SVS(prefixPattern, "/^_PHCA", _0, "/");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "APCUIterator", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "APCIterator", 0);
	if (zephir_class_exists(&_1, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(apc);
		if (!_3$$3) {
			_3$$3 = zend_fetch_class(SL("APCUIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(apc, _3$$3);
		if (zephir_has_constructor(apc TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, prefixPattern);
			zephir_check_call_status();
		}
	} else if (zephir_class_exists(&_2, 1 TSRMLS_CC)) {
		ZEPHIR_INIT_NVAR(apc);
		object_init_ex(apc, zephir_get_internal_ce(SS("apciterator") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_STRING(_4$$4, "user", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, _4$$4, prefixPattern);
		zephir_check_temp_parameter(_4$$4);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(apc) != IS_OBJECT) {
		RETURN_MM_BOOL(0);
	}
	_5 = zephir_get_iterator(apc TSRMLS_CC);
	_5->funcs->rewind(_5 TSRMLS_CC);
	for (;_5->funcs->valid(_5 TSRMLS_CC) == SUCCESS && !EG(exception); _5->funcs->move_forward(_5 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_5->funcs->get_current_data(_5, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_array_fetch_string(&_6$$6, item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/apcu.zep", 283 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "apcu_delete", &_7, 121, _6$$6);
		zephir_check_call_status();
	}
	_5->funcs->dtor(_5 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

