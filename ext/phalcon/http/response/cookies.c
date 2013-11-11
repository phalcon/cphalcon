
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies
 * A cookies bag is automatically registered as part of the 'response' service in the DI
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Cookies) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http\\Response, Cookies, phalcon, http_response_cookies, phalcon_http_response_cookies_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("_registered"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("_useEncryption"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_cookies_ce TSRMLS_CC, 1, phalcon_http_response_cookiesinterface_ce);
	zend_class_implements(phalcon_http_response_cookies_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 *
 * @param boolean useEncryption
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption) {

	zval *useEncryption_param = NULL;
	zend_bool useEncryption;

	zephir_fetch_params(0, 1, 0, &useEncryption_param);

		useEncryption = zephir_get_boolval(useEncryption_param);


	zephir_update_property_this(this_ptr, SL("_useEncryption"), useEncryption ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns if the bag is automatically encrypting/decrypting cookies
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption) {


	RETURN_MEMBER(this_ptr, "_useEncryption");

}

/**
 * Sets a cookie to be sent at the end of the request
 * This method overrides any cookie set before with the same name
 *
 * @param string name
 * @param mixed value
 * @param int expire
 * @param string path
 * @param boolean secure
 * @param string domain
 * @param boolean httpOnly
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set) {

	int expire;
	zval *name_param = NULL, *value = NULL, *expire_param = NULL, *path_param = NULL, *secure = NULL, *domain_param = NULL, *httpOnly = NULL, *cookie, *encryption, *dependencyInjector, *response, *_0, *_1 = NULL, *_2;
	zval *name = NULL, *path = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire_param, &path_param, &secure, &domain_param, &httpOnly);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}
	if (!expire_param) {
		expire = 0;	} else {
		expire = zephir_get_intval(expire_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	} else {
		zephir_get_strval(path, path_param);
	}
	if (!secure) {
		secure = ZEPHIR_GLOBAL(global_null);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
		zephir_get_strval(domain, domain_param);
	}
	if (!httpOnly) {
		httpOnly = ZEPHIR_GLOBAL(global_null);
	}


	encryption = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(cookie);
		object_init_ex(cookie, phalcon_http_cookie_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, expire);
		zephir_call_method_p7_noret(cookie, "__construct", name, value, _1, path, secure, domain, httpOnly);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		zephir_call_method_p1_noret(cookie, "setdi", _2);
		if (zephir_is_true(encryption)) {
			zephir_call_method_p1_noret(cookie, "useencryption", encryption);
		}
		zephir_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	} else {
		zephir_call_method_p1_noret(cookie, "setvalue", value);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, expire);
		zephir_call_method_p1_noret(cookie, "setexpiration", _1);
		zephir_call_method_p1_noret(cookie, "setpath", path);
		zephir_call_method_p1_noret(cookie, "setsecure", secure);
		zephir_call_method_p1_noret(cookie, "setdomain", domain);
		zephir_call_method_p1_noret(cookie, "sethttponly", httpOnly);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_2)) {
		dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'response' service");
			return;
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "response", 1);
		ZEPHIR_INIT_VAR(response);
		zephir_call_method_p1(response, dependencyInjector, "getshared", _1);
		zephir_call_method_p1_noret(response, "setcookies", this_ptr);
	}
	RETURN_THIS();

}

/**
 * Gets a cookie from the bag
 *
 * @param string name
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get) {

	zval *name_param = NULL, *dependencyInjector, *encryption, *cookie, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(cookie);
	}
	ZEPHIR_INIT_BNVAR(cookie);
	object_init_ex(cookie, phalcon_http_cookie_ce);
	zephir_call_method_p1_noret(cookie, "__construct", name);
	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
		zephir_call_method_p1_noret(cookie, "setdi", dependencyInjector);
		encryption = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
		if (zephir_is_true(encryption)) {
			zephir_call_method_p1_noret(cookie, "useencryption", encryption);
		}
	}
	zephir_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	RETURN_CCTOR(cookie);

}

/**
 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, has) {

	zval *name_param = NULL, *_0, *_COOKIE;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		RETURN_MM_BOOL(1);
	}
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	if (zephir_array_isset(_COOKIE, name)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the _COOKIE superglobal
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, delete) {

	zval *name_param = NULL, *cookie, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cookie, _0, name, 1 TSRMLS_CC)) {
		zephir_call_method_noret(cookie, "delete");
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sends the cookies to the client
 * Cookies aren't sent if headers are sent in the current request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, send) {

	zend_function *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	zval *cookie = NULL, *_0, *_1, **_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "headers_sent");
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(cookie, _4);
			zephir_call_method_cache_noret(cookie, "send", &_5);
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reset set cookies
 *
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_cookies"), _0 TSRMLS_CC);
	RETURN_THIS();

}

