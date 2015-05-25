
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
 *	//Cache data for 2 days
 *	$frontCache = new \Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new \Phalcon\Cache\Backend\Apc($frontCache, array(
 *      'prefix' => 'app-data'
 *  ));
 *
 *	//Cache arbitrary data
 *	$cache->save('my-data', array(1, 2, 3, 4, 5));
 *
 *	//Get data
 *	$data = $cache->get('my-data');
 *
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
	zval *keyName_param = NULL, *lifetime = NULL, *prefixedKey, *cachedContent = NULL, *_0, *_1;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName_param, &lifetime);

	if (unlikely(Z_TYPE_P(keyName_param) != IS_STRING && Z_TYPE_P(keyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'keyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(keyName_param) == IS_STRING)) {
		zephir_get_strval(keyName, keyName_param);
	} else {
		ZEPHIR_INIT_VAR(keyName);
		ZVAL_EMPTY_STRING(keyName);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCA", _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 7, prefixedKey);
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
 * @param string|long keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, save) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool stopBuffer;
	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer_param = NULL, *lastKey = NULL, *frontend, *cachedContent = NULL, *preparedContent = NULL, *ttl = NULL, *isBuffering = NULL, *_0;

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
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cache_exception_ce, "Cache must be started first", "phalcon/cache/backend/apc.zep", 93);
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
	ZEPHIR_CALL_METHOD(&preparedContent, frontend, "beforestore", NULL, 0, cachedContent);
	zephir_check_call_status();
	if (Z_TYPE_P(lifetime) == IS_NULL) {
		ZEPHIR_OBS_NVAR(lifetime);
		zephir_read_property_this(&lifetime, this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (Z_TYPE_P(lifetime) == IS_NULL) {
			ZEPHIR_CALL_METHOD(&ttl, frontend, "getlifetime", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(ttl, lifetime);
		}
	} else {
		ZEPHIR_CPY_WRT(ttl, lifetime);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, 8, lastKey, preparedContent, ttl);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&isBuffering, frontend, "isbuffering", NULL, 0);
	zephir_check_call_status();
	if (stopBuffer == 1) {
		ZEPHIR_CALL_METHOD(NULL, frontend, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE_IDENTICAL(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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
	zval *keyName = NULL, *value_param = NULL, *prefixedKey, *cachedContent = NULL, *result = NULL, *_0, *_1;

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
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	if ((zephir_function_exists_ex(SS("apc_inc") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, value);
		ZEPHIR_CALL_FUNCTION(&result, "apc_inc", NULL, 32, prefixedKey, _1);
		zephir_check_call_status();
		RETURN_CCTOR(result);
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 7, prefixedKey);
		zephir_check_call_status();
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_NVAR(result);
			ZVAL_LONG(result, (zephir_get_numberval(cachedContent) + value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, result);
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
	zval *keyName = NULL, *value_param = NULL, *lastKey, *cachedContent = NULL, *result, *_0, *_1;

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
	zephir_update_property_this(this_ptr, SL("_lastKey"), lastKey TSRMLS_CC);
	if ((zephir_function_exists_ex(SS("apc_dec") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, value);
		ZEPHIR_RETURN_CALL_FUNCTION("apc_dec", NULL, 33, lastKey, _1);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_FUNCTION(&cachedContent, "apc_fetch", NULL, 7, lastKey);
		zephir_check_call_status();
		if (zephir_is_numeric(cachedContent)) {
			ZEPHIR_INIT_VAR(result);
			ZVAL_LONG(result, (zephir_get_numberval(cachedContent) - value));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "save", NULL, 0, keyName, result);
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
	zval *keyName_param = NULL, *_0, *_1;
	zval *keyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName_param);

	if (unlikely(Z_TYPE_P(keyName_param) != IS_STRING && Z_TYPE_P(keyName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'keyName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(keyName_param) == IS_STRING)) {
		zephir_get_strval(keyName, keyName_param);
	} else {
		ZEPHIR_INIT_VAR(keyName);
		ZVAL_EMPTY_STRING(keyName);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVV(_1, "_PHCA", _0, keyName);
	ZEPHIR_RETURN_CALL_FUNCTION("apc_delete", NULL, 34, _1);
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

	zend_object_iterator *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_1 = NULL;
	zval *prefix_param = NULL, *prefixPattern = NULL, *apc, *keys, *key = NULL, *_2 = NULL, _4 = zval_used_for_init, *_5 = NULL;
	zval *prefix = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_EMPTY_STRING(prefix);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(prefixPattern);
	if (!(prefix && Z_STRLEN_P(prefix))) {
		ZVAL_STRING(prefixPattern, "/^_PHCA/", 1);
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "/^_PHCA", prefix, "/");
		ZEPHIR_CPY_WRT(prefixPattern, _0);
	}
	ZEPHIR_INIT_VAR(keys);
	array_init(keys);
	ZEPHIR_INIT_VAR(apc);
	if (!_1) {
		_1 = zend_fetch_class(SL("APCIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(apc, _1);
	if (zephir_has_constructor(apc TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "user", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, apc, "__construct", NULL, 0, _2, prefixPattern);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	_3 = zephir_get_iterator(apc TSRMLS_CC);
	_3->funcs->rewind(_3 TSRMLS_CC);
	for (;_3->funcs->valid(_3 TSRMLS_CC) == SUCCESS && !EG(exception); _3->funcs->move_forward(_3 TSRMLS_CC)) {
		ZEPHIR_GET_IMKEY(key, _3);
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_3->funcs->get_current_data(_3, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(_2, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, 5);
		ZEPHIR_INIT_NVAR(_5);
		zephir_substr(_5, key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_append(&keys, _5, PH_SEPARATE, "phalcon/cache/backend/apc.zep", 224);
	}
	_3->funcs->dtor(_3 TSRMLS_CC);
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
	zval *keyName = NULL, *lifetime = NULL, *lastKey = NULL, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(keyName) == IS_NULL) {
		ZEPHIR_OBS_VAR(lastKey);
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(lastKey);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCA", _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		ZEPHIR_CALL_FUNCTION(&_1, "apc_exists", NULL, 35, lastKey);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Immediately invalidates all existing items.
 */
PHP_METHOD(Phalcon_Cache_Backend_Apc, flush) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_2 = NULL;
	zend_object_iterator *_0;
	zval *item = NULL, *_1, *_3, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	if (!_2) {
		_2 = zend_fetch_class(SL("APCIterator"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_1, _2);
	if (zephir_has_constructor(_1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "user", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	_0 = zephir_get_iterator(_1 TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_array_fetch_string(&_4, item, SL("key"), PH_NOISY | PH_READONLY, "phalcon/cache/backend/apc.zep", 264 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "apc_delete", &_5, 34, _4);
		zephir_check_call_status();
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

