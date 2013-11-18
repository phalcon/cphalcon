
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


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
/**
 * Phalcon\Cache\Backend\Xcache
 *
 * Allows to cache output fragments, PHP data and raw data using an XCache backend
 *
 *<code>
 *	//Cache data for 2 days
 *	$frontCache = new Phalcon\Cache\Frontend\Data(array(
 *		'lifetime' => 172800
 *	));
 *
 *  $cache = new Phalcon\Cache\Backend\Xcache($frontCache, array(
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
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Xcache) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Cache\\Backend, Xcache, phalcon, cache_backend_xcache, phalcon_cache_backend_ce, phalcon_cache_backend_xcache_method_entry, 0);

	zend_class_implements(phalcon_cache_backend_xcache_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Cache\Backend\Xcache constructor
 *
 * @param Phalcon\Cache\FrontendInterface frontend
 * @param array options
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, __construct) {

	zval *frontend, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		ZEPHIR_CPY_WRT(options, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(options);


	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_INIT_NVAR(options);
		array_init(options);
	}
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "_PHCX", 1);
		zephir_array_update_string(&options, SL("statsKey"), &_0, PH_COPY | PH_SEPARATE);
	}
	zephir_call_parent_p2_noret(this_ptr, phalcon_cache_backend_xcache_ce, "__construct", frontend, options);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a cached content
 *
 * @param int|string keyName
 * @param   long lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, get) {

	zval *keyName, *lifetime = NULL, *frontend, *prefixedKey, *cachedContent, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	zephir_update_property_this(this_ptr, SL("_lastKey"), prefixedKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(cachedContent);
	zephir_call_func_p1(cachedContent, "xcache_get", prefixedKey);
	if (!(zephir_is_true(cachedContent))) {
		RETURN_MM_NULL();
	}
	if (zephir_is_numeric(cachedContent)) {
		RETURN_CCTOR(cachedContent);
	} else {
		zephir_call_method_p1(return_value, frontend, "afterretrieve", cachedContent);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stores cached content into the file backend and stops the frontend
 *
 * @param int|string keyName
 * @param string content
 * @param long lifetime
 * @param boolean stopBuffer
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, save) {

	zval *keyName = NULL, *content = NULL, *lifetime = NULL, *stopBuffer = NULL, *lastKey, *frontend, *cachedContent = NULL, *preparedContent, *tmp, *tt1 = NULL, *success, *isBuffering, *options, *keys = NULL, *specialKey, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &keyName, &content, &lifetime, &stopBuffer);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!content || Z_TYPE_P(content) == IS_NULL) {
		content = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}
	if (!stopBuffer || Z_TYPE_P(stopBuffer) == IS_NULL) {
		stopBuffer = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	frontend = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
	if (!(zephir_is_true(content))) {
		ZEPHIR_INIT_VAR(cachedContent);
		zephir_call_method(cachedContent, frontend, "getcontent");
	} else {
		ZEPHIR_CPY_WRT(cachedContent, content);
	}
	if (!(zephir_is_numeric(cachedContent))) {
		ZEPHIR_INIT_VAR(preparedContent);
		zephir_call_method_p1(preparedContent, frontend, "beforestore", cachedContent);
	}
	if (!(zephir_is_true(lifetime))) {
		tmp = zephir_fetch_nproperty_this(this_ptr, SL("_lastLifetime"), PH_NOISY_CC);
		if (!(zephir_is_true(tmp))) {
			ZEPHIR_INIT_VAR(tt1);
			zephir_call_method(tt1, frontend, "getlifetime");
		} else {
			ZEPHIR_CPY_WRT(tt1, tmp);
		}
	} else {
		ZEPHIR_CPY_WRT(tt1, lifetime);
	}
	ZEPHIR_INIT_VAR(success);
	if (zephir_is_numeric(cachedContent)) {
		zephir_call_func_p3(success, "xcache_set", lastKey, cachedContent, tt1);
	} else {
		zephir_call_func_p3(success, "xcache_set", lastKey, preparedContent, tt1);
	}
	ZEPHIR_INIT_VAR(isBuffering);
	zephir_call_method(isBuffering, frontend, "isbuffering");
	if (!(zephir_is_true(stopBuffer))) {
		zephir_call_method_noret(frontend, "stop");
	}
	if (ZEPHIR_IS_TRUE(isBuffering)) {
		zend_print_zval(cachedContent, 0);
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	if (zephir_is_true(success)) {
		options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
		if (!(zephir_array_isset_string(options, SS("statsKey")))) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
			return;
		}
		zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(keys);
		zephir_call_func_p1(keys, "xcache_get", specialKey);
		if ((Z_TYPE_P(keys) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(keys);
			array_init(keys);
		}
		zephir_array_update_zval(&keys, lastKey, &tt1, PH_COPY | PH_SEPARATE);
		zephir_call_func_p2_noret("xcache_set", specialKey, keys);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a value from the cache by its key
 *
 * @param int|string keyName
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, delete) {

	zval *keyName, *prefixedKey, *specialKey, *keys, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(prefixedKey);
	ZEPHIR_CONCAT_SVV(prefixedKey, "_PHCX", _0, keyName);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _1, SS("statsKey"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_call_func_p1(keys, "xcache_get", specialKey);
	if ((Z_TYPE_P(keys) != IS_ARRAY)) {
		ZEPHIR_INIT_BNVAR(keys);
		array_init(keys);
	}
	zephir_call_func_p2_noret("xcache_set", specialKey, keys);
	ZEPHIR_MM_RESTORE();

}

/**
 * Query the existing cached keys
 *
 * @param string prefix
 * @return array
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys) {

	HashTable *_1;
	HashPosition _0;
	zval *prefix = NULL, *options, *prefixed, *specialKey, *keys, *retval, *key = NULL, *realKey = NULL, **_2, _3 = zval_used_for_init, _4 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &prefix);

	if (!prefix || Z_TYPE_P(prefix) == IS_NULL) {
		prefix = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(prefixed);
	if (!(zephir_is_true(prefix))) {
		ZVAL_STRING(prefixed, "_PHCX", 1);
	} else {
		ZEPHIR_CONCAT_SV(prefixed, "_PHCX", prefix);
	}
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string(options, SS("statsKey")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	zephir_array_fetch_string(&specialKey, options, SL("statsKey"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_VAR(retval);
	array_init(retval);
	ZEPHIR_INIT_VAR(keys);
	zephir_call_func_p1(keys, "xcache_get", specialKey);
	if ((Z_TYPE_P(keys) == IS_ARRAY)) {
		zephir_is_iterable(keys, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(key, _2);
			ZEPHIR_SINIT_NVAR(_3);
			ZVAL_LONG(&_3, 5);
			ZEPHIR_SINIT_NVAR(_4);
			ZVAL_LONG(&_4, 0);
			ZEPHIR_INIT_NVAR(realKey);
			zephir_call_func_p3(realKey, "substr", key, &_3, &_4);
			zephir_array_append(&retval, realKey, PH_SEPARATE);
		}
	}
	RETURN_CCTOR(retval);

}

/**
 * Checks if cache exists and it isn't expired
 *
 * @param string keyName
 * @param   long lifetime
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists) {

	zval *keyName = NULL, *lifetime = NULL, *lastKey, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &keyName, &lifetime);

	if (!keyName || Z_TYPE_P(keyName) == IS_NULL) {
		keyName = ZEPHIR_GLOBAL(global_null);
	}
	if (!lifetime || Z_TYPE_P(lifetime) == IS_NULL) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (zephir_is_true(lastKey)) {
		zephir_call_func_p1(return_value, "xcache_isset", lastKey);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Atomic increment of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, increment) {

	long value;
	zval *keyName, *value_param = NULL, *lastKey, *newVal, *origVal, *_0, _1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param || Z_TYPE_P(value_param) == IS_NULL) {
		value = 1;	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	ZEPHIR_INIT_VAR(newVal);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "xcache_inc", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "function_exists", &_1);
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, value);
		zephir_call_func_p2(newVal, "xcache_inc", lastKey, _3);
	} else {
		ZEPHIR_INIT_VAR(origVal);
		zephir_call_func_p1(origVal, "xcache_get", lastKey);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		zephir_call_func_p2_noret("xcache_set", lastKey, newVal);
	}
	RETURN_CCTOR(newVal);

}

/**
 * Atomic decrement of a given key, by number $value
 *
 * @param  string keyName
 * @param  long value
 * @return mixed
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, decrement) {

	long value;
	zval *keyName, *value_param = NULL, *lastKey, *newVal, *origVal, *success, *_0, _1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &value_param);

	if (!value_param || Z_TYPE_P(value_param) == IS_NULL) {
		value = 1;	} else {
		value = zephir_get_intval(value_param);
	}


	ZEPHIR_INIT_VAR(lastKey);
	if (!(zephir_is_true(keyName))) {
		zephir_read_property_this(&lastKey, this_ptr, SL("_lastKey"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_prefix"), PH_NOISY_CC);
		ZEPHIR_CONCAT_SVV(lastKey, "_PHCX", _0, keyName);
	}
	if (!(zephir_is_true(lastKey))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "The cache must be started first");
		return;
	}
	ZEPHIR_INIT_VAR(newVal);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "xcache_dec", 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "function_exists", &_1);
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, value);
		zephir_call_func_p2(newVal, "xcache_dec", lastKey, _3);
	} else {
		ZEPHIR_INIT_VAR(origVal);
		zephir_call_func_p1(origVal, "xcache_get", lastKey);
		ZVAL_LONG(newVal, (zephir_get_numberval(origVal) - value));
		ZEPHIR_INIT_VAR(success);
		zephir_call_func_p2(success, "xcache_set", lastKey, newVal);
	}
	RETURN_CCTOR(newVal);

}

/**
 * Immediately invalidates all existing items.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Cache_Backend_Xcache, flush) {

	HashTable *_2;
	HashPosition _1;
	zval *prefixed, *options, *specialKey, *keys, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(prefixed);
	ZVAL_STRING(prefixed, "_PHCX", 1);
	options = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_options"), PH_NOISY_CC);
	if (!(zephir_array_isset_string_fetch(&specialKey, _0, SS("statsKey"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_cache_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	ZEPHIR_INIT_VAR(keys);
	zephir_call_func_p1(keys, "xcache_get", specialKey);
	if ((Z_TYPE_P(keys) == IS_ARRAY)) {
		zephir_is_iterable(keys, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(key, _2, _1);
			ZEPHIR_GET_HVALUE(value, _3);
			zephir_call_func_p1_noret("xcache_unset", key);
		}
		zephir_call_func_p2_noret("xcache_set", specialKey, keys);
	}
	RETURN_MM_BOOL(1);

}

