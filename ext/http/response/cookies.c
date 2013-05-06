
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies
 * A cookies bag is automatically registered as part of the 'response' service in the DI
 */


/**
 * Phalcon\Http\Response\Cookies initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Response, Cookies, http_response_cookies, phalcon_http_response_cookies_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("_registered"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("_useEncryption"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_cookies_ce TSRMLS_CC, 2, phalcon_http_response_cookiesinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 *
 * @param boolean $useEncryption
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption){

	zval *use_encryption;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &use_encryption) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_this(this_ptr, SL("_useEncryption"), use_encryption TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns if the bag is automatically encrypting/decrypting cookies
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption){


	RETURN_MEMBER(this_ptr, "_useEncryption");
}

/**
 * Sets a cookie to be sent at the end of the request
 * This method overrides any cookie set before with the same name
 *
 * @param string $name
 * @param mixed $value
 * @param int $expire
 * @param string $path
 * @param boolean $secure
 * @param boolean $httpOnly
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set){

	zval *name, *value = NULL, *expire = NULL, *path = NULL, *secure = NULL, *http_only = NULL;
	zval *cookies, *encryption, *dependency_injector = NULL;
	zval *cookie = NULL, *registered, *service, *response;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzzzz", &name, &value, &expire, &path, &secure, &http_only) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!value) {
		PHALCON_INIT_VAR(value);
	}
	
	if (!expire) {
		PHALCON_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}
	
	if (!path) {
		PHALCON_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	}
	
	if (!secure) {
		PHALCON_INIT_VAR(secure);
	}
	
	if (!http_only) {
		PHALCON_INIT_VAR(http_only);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "The cookie name must be string");
		return;
	}
	
	PHALCON_OBS_VAR(cookies);
	phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(encryption);
	phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	
	/** 
	 * Check if the cookie needs to be updated or 
	 */
	if (!phalcon_array_isset(cookies, name)) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cookie);
		object_init_ex(cookie, phalcon_http_cookie_ce);
	
		p0[0] = name;
		p0[1] = value;
		p0[2] = expire;
		p0[3] = path;
		p0[4] = secure;
		p0[5] = http_only;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(cookie, "__construct", 6, p0);
	
		/** 
		 * Pass the DI to created cookies
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setdi", dependency_injector);
	
		/** 
		 * Enable encryption in the cookie
		 */
		if (zend_is_true(encryption)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "useencryption", encryption);
		}
	
		phalcon_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	} else {
		PHALCON_OBS_NVAR(cookie);
		phalcon_array_fetch(&cookie, cookies, name, PH_NOISY_CC);
	
		/** 
		 * Override any settings in the cookie
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setvalue", value);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setexpiration", expire);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setpath", path);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setsecure", secure);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "sethttponly", http_only);
	}
	
	/** 
	 * Register the cookies bag in the response
	 */
	PHALCON_OBS_VAR(registered);
	phalcon_read_property_this(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(registered)) {
	
		PHALCON_OBS_NVAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'response' service");
			return;
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "response", 1);
	
		PHALCON_INIT_VAR(response);
		PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", service);
	
		/** 
		 * Pass the cookies bag to the response so it can send the headers at the of the
		 * request
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcookies", this_ptr);
	}
	
	
	RETURN_THIS();
}

/**
 * Gets a cookie from the bag
 *
 * @param string $name
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get){

	zval *name, *cookies, *cookie = NULL, *dependency_injector;
	zval *encryption;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "The cookie name must be string");
		return;
	}
	
	PHALCON_OBS_VAR(cookies);
	phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (phalcon_array_isset(cookies, name)) {
		PHALCON_OBS_VAR(cookie);
		phalcon_array_fetch(&cookie, cookies, name, PH_NOISY_CC);
		RETURN_CCTOR(cookie);
	}
	
	/** 
	 * Create the cookie if the it does not exist
	 */
	PHALCON_INIT_NVAR(cookie);
	object_init_ex(cookie, phalcon_http_cookie_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "__construct", name);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
	
		/** 
		 * Pass the DI to created cookies
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setdi", dependency_injector);
	
		PHALCON_OBS_VAR(encryption);
		phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	
		/** 
		 * Enable encryption in the cookie
		 */
		if (zend_is_true(encryption)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "useencryption", encryption);
		}
	}
	
	phalcon_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	
	RETURN_CCTOR(cookie);
}

/**
 * Check if a cookie is defined in the bag or exists in the $_COOKIE superglobal
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, has){

	zval *name, *cookies, *_COOKIE;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(cookies);
	phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	
	/** 
	 * Check the internal bag
	 */
	if (phalcon_array_isset(cookies, name)) {
		RETURN_MM_TRUE;
	}
	
	/** 
	 * Check the superglobal
	 */
	phalcon_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	if (phalcon_array_isset(_COOKIE, name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the $_COOKIE superglobal
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, delete){


	
}

/**
 * Sends the cookies to the client
 * Cookies aren't sent if headers are sent in the current request
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, send){

	zval *headers_was_sent, *cookies, *cookie = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(headers_was_sent);
	PHALCON_CALL_FUNC(headers_was_sent, "headers_sent");
	if (!zend_is_true(headers_was_sent)) {
	
		PHALCON_OBS_VAR(cookies);
		phalcon_read_property_this(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(cookies, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(cookie);
	
			PHALCON_CALL_METHOD_NORETURN(cookie, "send");
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Reset set cookies
 *
 * @return Phalcon\Http\Response\Cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset){

	zval *empty_array;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_this(this_ptr, SL("_cookies"), empty_array TSRMLS_CC);
	RETURN_THIS();
}

