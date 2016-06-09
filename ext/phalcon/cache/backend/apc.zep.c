
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
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
 * $frontCache = new FrontData([
 *     'lifetime' => 172800
 * ]);
 *
 * $cache = new Apc($frontCache, [
 *     'prefix' => 'app-data'
 * ]);
 *
 * // Cache arbitrary data
 * $cache->save('my-data', [1, 2, 3, 4, 5]);
 *
 * // Get data
 * $data = $cache->get('my-data');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apc) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Apc, phalcon, cache_backend_apc, phalcon_cache_backend_ce, phalcon_cache_backend_apc_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_apc_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 * Returns a cached content
 *
 * @param 	string|long keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, *lifetime = NULL, lifetime_sub, __$null, prefixedKey, cachedContent, _0, _1;
	zval keyName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	if (unlikely(Z_TYPE_P(keyName_param) != IS_STRING && Z_TYPE_P(keyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'keyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(keyName_param) == IS_STRING)) {
		zephir_get_strval(&keyName, keyName_param);
	} else {
		ZEPHIR_INIT_VAR(&keyName);
		ZVAL_EMPTY_STRING(&keyName);
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_SVV(&prefixedKey, "_PHCA", &_0, &keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 88, &prefixedKey);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&cachedContent)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "afterretrieve", NULL, 0, &cachedContent);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Stores cached content into the APC backend and stops the frontend
 *
 * @param string|long keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, keyName_sub, *content = NULL, content_sub, *lifetime = NULL, lifetime_sub, *stopBuffer_param = NULL, __$true, __$false, __$null, lastKey, frontend, cachedContent, preparedContent, ttl, isBuffering, success, _0$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&frontend);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&preparedContent);
	ZVAL_UNDEF(&ttl);
	ZVAL_UNDEF(&isBuffering);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0$$4);

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
		ZEPHIR_CPY_WRT(lifetime, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(lifetime);
	}
	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_0$$4, keyName);
	}
	if (!(zephir_is_true(&lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/apc.zep", 95);
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
	ZEPHIR_CALL_METHOD(&preparedContent, &frontend, "beforestore", NULL, 0, &cachedContent);
	zephir_check_call_status();
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_NVAR(lifetime);
		zephir_read_property(lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&ttl, &frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&ttl, lifetime);
		}
	} else {
		ZEPHIR_CPY_WRT(&ttl, lifetime);
	}
	ZEPHIR_CALL_FUNCTION(&success, "apc_store", NULL, 89, &lastKey, &preparedContent, &ttl);
	zephir_check_call_status();
	if (!(zephir_is_true(&success))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Failed storing data in apc", "phalcon/cache/backend/apc.zep", 127);
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
	RETURN_CCTOR(success);

}

/**
 * Increment of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, increment) {

	int value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, prefixedKey, cachedContent, result, _0, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&prefixedKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&prefixedKey);
	ZEPHIR_CONCAT_SVV(&prefixedKey, "_PHCA", &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &prefixedKey);
	if ((zephir_function_exists_ex(SL("apc_inc") TSRMLS_CC) == SUCCESS)) {
		ZVAL_LONG(&_1$$3, value);
		ZEPHIR_CALL_FUNCTION(&result, "apc_inc", NULL, 109, &prefixedKey, &_1$$3);
		zephir_check_call_status();
		RETURN_CCTOR(result);
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 88, &prefixedKey);
		zephir_check_call_status();
		if (zephir_is_numeric(&cachedContent)) {
			ZEPHIR_INIT_NVAR(&result);
			ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) + value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, &result);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		} else {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Decrement of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, decrement) {

	int value, ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *value_param = NULL, __$null, lastKey, cachedContent, result, _0, _1$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&cachedContent);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &value_param);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!value_param) {
		value = 1;
	} else {
		value = zephir_get_intval(value_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&lastKey);
	ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_0, keyName);
	zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	if ((zephir_function_exists_ex(SL("apc_dec") TSRMLS_CC) == SUCCESS)) {
		ZVAL_LONG(&_1$$3, value);
		ZEPHIR_RETURN_CALL_FUNCTION("apc_dec", NULL, 110, &lastKey, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 88, &lastKey);
		zephir_check_call_status();
		if (zephir_is_numeric(&cachedContent)) {
			ZEPHIR_INIT_VAR(&result);
			ZVAL_LONG(&result, (zephir_get_numberval(&cachedContent) - value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, &result);
			zephir_check_call_status();
			RETURN_CCTOR(result);
		} else {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName_param = NULL, _0, _1;
	zval keyName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

	if (unlikely(Z_TYPE_P(keyName_param) != IS_STRING && Z_TYPE_P(keyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'keyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(keyName_param) == IS_STRING)) {
		zephir_get_strval(&keyName, keyName_param);
	} else {
		ZEPHIR_INIT_VAR(&keyName);
		ZVAL_EMPTY_STRING(&keyName);
	}


	zephir_read_property(&_0, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVV(&_1, "_PHCA", &_0, &keyName);
	ZEPHIR_RETURN_CALL_FUNCTION("apc_delete", NULL, 111, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys) {

	zend_object_iterator *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, prefixPattern, apc, keys, key, _1, _3$$5, _4$$5;
	zval prefix, _0$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&prefixPattern);
	ZVAL_UNDEF(&apc);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(&prefix);
		ZVAL_STRING(&prefix, "");
	} else {
		zephir_get_strval(&prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(&prefixPattern);
	if (!(!(Z_TYPE_P(&prefix) == IS_UNDEF) && Z_STRLEN_P(&prefix))) {
		ZVAL_STRING(&prefixPattern, "/^_PHCA/");
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SVS(&_0$$4, "/^_PHCA", &prefix, "/");
		ZEPHIR_CPY_WRT(&prefixPattern, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&keys);
	array_init(&keys);
	ZEPHIR_INIT_VAR(&apc);
	object_init_ex(&apc, zephir_get_internal_ce(SL("apciterator")));
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "user");
	ZEPHIR_CALL_METHOD(NULL, &apc, "__construct", NULL, 0, &_1, &prefixPattern);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	_2 = zephir_get_iterator(&apc TSRMLS_CC);
	_2->funcs->rewind(_2 TSRMLS_CC);
	for (;_2->funcs->valid(_2 TSRMLS_CC) == SUCCESS && !EG(exception); _2->funcs->move_forward(_2 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(key, _2);
		{
			ZEPHIR_ITERATOR_COPY(&_1, _2);
		}
		ZVAL_LONG(&_3$$5, 5);
		ZEPHIR_INIT_NVAR(&_4$$5);
		zephir_substr(&_4$$5, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&keys, &_4$$5, PH_SEPARATE, "phalcon/cache/backend/apc.zep", 232);
	}
	zend_iterator_dtor(_2);
	RETURN_CCTOR(keys);

}

/**
 * Checks if cache exists and it hasn't expired
 *
 * @param  string|long keyName
 * @param  long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, exists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyName = NULL, keyName_sub, *lifetime = NULL, lifetime_sub, __$null, lastKey, _0$$4, _1$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&lastKey);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = &keyName_sub;
		keyName = &__$null;
	}
	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(&lastKey);
		zephir_read_property(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("_prefix"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&lastKey);
		ZEPHIR_CONCAT_SVV(&lastKey, "_PHCA", &_0$$4, keyName);
	}
	if (zephir_is_true(&lastKey)) {
		ZEPHIR_CALL_FUNCTION(&_1$$5, "apc_exists", NULL, 112, &lastKey);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$5)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, flush) {

	zend_object_iterator *_0;
	zval item, _1, _2, _3$$3;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("apciterator")));
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "user");
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	_0 = zephir_get_iterator(&_1 TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&item, _0);
		}
		zephir_array_fetch_string(&_3$$3, &item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/apc.zep", 272 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "apc_delete", &_4, 111, &_3$$3);
		zephir_check_call_status();
	}
	zend_iterator_dtor(_0);
	RETURN_MM_BOOL(1);

}

