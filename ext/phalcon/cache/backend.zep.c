
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, Backend, phalcon, cache_backend, phalcon_cache_backend_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_lastLifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Phalcon_Cache_Backend, getFrontend) {

	

	RETURN_MEMBER(getThis(), "_frontend");

}

PHP_METHOD(Phalcon_Cache_Backend, setFrontend) {

	zval *frontend;

	zephir_fetch_params(0, 1, 0, &frontend);



	zephir_update_property_this(getThis(), SL("_frontend"), frontend TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Cache_Backend, getOptions) {

	

	RETURN_MEMBER(getThis(), "_options");

}

PHP_METHOD(Phalcon_Cache_Backend, setOptions) {

	zval *options;

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(Phalcon_Cache_Backend, getLastKey) {

	

	RETURN_MEMBER(getThis(), "_lastKey");

}

PHP_METHOD(Phalcon_Cache_Backend, setLastKey) {

	zval *lastKey;

	zephir_fetch_params(0, 1, 0, &lastKey);



	zephir_update_property_this(getThis(), SL("_lastKey"), lastKey TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Phalcon\Cache\Backend constructor
 *
 * @param \Phalcon\Cache\FrontendInterface frontend
 * @param array options
 */
PHP_METHOD(Phalcon_Cache_Backend, __construct) {

	zval *frontend, *options = NULL, *prefix = NULL;

	zephir_fetch_params(0, 1, 1, &frontend, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_string_fetch(&prefix, options, SS("prefix"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_prefix"), prefix TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_frontend"), frontend TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_options"), options TSRMLS_CC);

}

/**
 * Starts a cache. The keyname allows to identify the created fragment
 *
 * @param   int|string keyName
 * @param   int lifetime
 * @return  mixed
 */
PHP_METHOD(Phalcon_Cache_Backend, start) {

	zend_bool fresh = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keyName, *lifetime = NULL, *existingCache = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&existingCache, this_ptr, "get", NULL, 0, keyName, lifetime);
	zephir_check_call_status();
	if (Z_TYPE_P(existingCache) == IS_NULL) {
		fresh = 1;
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "start", NULL, 0);
		zephir_check_call_status();
	} else {
		fresh = 0;
	}
	if (fresh) {
		zephir_update_property_this(getThis(), SL("_fresh"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_fresh"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (1) {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	if (Z_TYPE_P(lifetime) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_lastLifetime"), lifetime TSRMLS_CC);
	}
	RETURN_CCTOR(existingCache);

}

/**
 * Stops the frontend without store any cached content
 */
PHP_METHOD(Phalcon_Cache_Backend, stop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stopBuffer_param = NULL, *_0$$3;
	zend_bool stopBuffer;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &stopBuffer_param);

	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (stopBuffer == 1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (0) {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_started"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether the last cache is fresh or cached
 */
PHP_METHOD(Phalcon_Cache_Backend, isFresh) {

	

	RETURN_MEMBER(getThis(), "_fresh");

}

/**
 * Checks whether the cache has starting buffering or not
 */
PHP_METHOD(Phalcon_Cache_Backend, isStarted) {

	

	RETURN_MEMBER(getThis(), "_started");

}

/**
 * Gets the last lifetime set
 *
 * @return int
 */
PHP_METHOD(Phalcon_Cache_Backend, getLifetime) {

	

	RETURN_MEMBER(getThis(), "_lastLifetime");

}

