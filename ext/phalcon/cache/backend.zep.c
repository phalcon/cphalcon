
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cache\Backend
 *
 * This class implements common functionality for backend adapters. A backend cache adapter may extend this class
 */
ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cache, Backend, phalcon, cache_backend, phalcon_cache_backend_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Phalcon\Cache\FrontendInterface
	 */
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cache_backend_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_prefix"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_cache_backend_ce, SL("_lastKey"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cache_backend_ce, SL("_lastLifetime"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_fresh"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cache_backend_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_cache_backend_ce TSRMLS_CC, 1, phalcon_cache_backendinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Cache_Backend, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_options");

}

/**
 */
PHP_METHOD(Phalcon_Cache_Backend, setOptions) {

	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	RETURN_THIS();

}

/**
 */
PHP_METHOD(Phalcon_Cache_Backend, getLastKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lastKey");

}

/**
 */
PHP_METHOD(Phalcon_Cache_Backend, setLastKey) {

	zval *lastKey_param = NULL;
	zval lastKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lastKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &lastKey_param);

	zephir_get_strval(&lastKey, lastKey_param);


	zephir_update_property_zval(this_ptr, SL("_lastKey"), &lastKey);
	RETURN_THIS();

}

/**
 * Phalcon\Cache\Backend constructor
 */
PHP_METHOD(Phalcon_Cache_Backend, __construct) {

	zval options;
	zval *frontend, frontend_sub, *options_param = NULL, prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &frontend, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	if (zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_prefix"), &prefix);
	}
	zephir_update_property_zval(this_ptr, SL("_frontend"), frontend);
	zephir_update_property_zval(this_ptr, SL("_options"), &options);
	ZEPHIR_MM_RESTORE();

}

/**
 * @var Phalcon\Cache\FrontendInterface
 */
PHP_METHOD(Phalcon_Cache_Backend, getFrontend) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_frontend");

}

PHP_METHOD(Phalcon_Cache_Backend, setFrontend) {

	zval *frontend, frontend_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&frontend_sub);

	zephir_fetch_params(0, 1, 0, &frontend);



	zephir_update_property_zval(this_ptr, SL("_frontend"), frontend);

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
	zval *keyName, keyName_sub, *lifetime = NULL, lifetime_sub, __$true, __$false, __$null, existingCache, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keyName_sub);
	ZVAL_UNDEF(&lifetime_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&existingCache);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keyName, &lifetime);

	if (!lifetime) {
		lifetime = &lifetime_sub;
		lifetime = &__$null;
	}


	ZEPHIR_CALL_METHOD(&existingCache, this_ptr, "get", NULL, 0, keyName, lifetime);
	zephir_check_call_status();
	if (Z_TYPE_P(&existingCache) == IS_NULL) {
		fresh = 1;
		zephir_read_property(&_0$$3, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "start", NULL, 0);
		zephir_check_call_status();
	} else {
		fresh = 0;
	}
	if (fresh) {
		zephir_update_property_zval(this_ptr, SL("_fresh"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_fresh"), &__$false);
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	if (Z_TYPE_P(lifetime) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_lastLifetime"), lifetime);
	}
	RETURN_CCTOR(&existingCache);

}

/**
 * Stops the frontend without store any cached content
 */
PHP_METHOD(Phalcon_Cache_Backend, stop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stopBuffer_param = NULL, __$true, __$false, _0$$3;
	zend_bool stopBuffer;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &stopBuffer_param);

	if (!stopBuffer_param) {
		stopBuffer = 1;
	} else {
		stopBuffer = zephir_get_boolval(stopBuffer_param);
	}


	if (stopBuffer == 1) {
		zephir_read_property(&_0$$3, this_ptr, SL("_frontend"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "stop", NULL, 0);
		zephir_check_call_status();
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks whether the last cache is fresh or cached
 */
PHP_METHOD(Phalcon_Cache_Backend, isFresh) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_fresh");

}

/**
 * Checks whether the cache has starting buffering or not
 */
PHP_METHOD(Phalcon_Cache_Backend, isStarted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_started");

}

/**
 * Gets the last lifetime set
 */
PHP_METHOD(Phalcon_Cache_Backend, getLifetime) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_lastLifetime");

}

