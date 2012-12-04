
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies
 *
 */


/**
 * Phalcon\Http\Response\Cookies initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Response_Cookies){

	PHALCON_REGISTER_CLASS(Phalcon\\Http\\Response, Cookies, http_response_cookies, phalcon_http_response_cookies_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("_registered"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("_cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_response_cookies_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Http\Response\Cookies constructor
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, __construct){


	phalcon_update_property_empty_array(phalcon_http_response_cookies_ce, this_ptr, SL("_cookies") TSRMLS_CC);
	
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

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
 * Sets a header to be sent at the end of the request
 *
 * @param string $name
 * @param mixed $value
 * @param int $expire
 * @param string $path
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set){

	zval *name, *value = NULL, *expire = NULL, *path = NULL, *cookies, *dependency_injector = NULL;
	zval *cookie = NULL, *registered, *service, *response;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &name, &value, &expire, &path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!value) {
		PHALCON_INIT_NVAR(value);
	}
	
	if (!expire) {
		PHALCON_INIT_NVAR(expire);
		ZVAL_LONG(expire, 0);
	}
	
	if (!path) {
		PHALCON_INIT_NVAR(path);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "The cookie name must be string");
		return;
	}
	
	PHALCON_INIT_VAR(cookies);
	phalcon_read_property(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	
	/** 
	 * Check if the cookie needs to be updated or 
	 */
	eval_int = phalcon_array_isset(cookies, name);
	if (!eval_int) {
		PHALCON_INIT_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(cookie);
		object_init_ex(cookie, phalcon_http_cookie_ce);
		PHALCON_CALL_METHOD_PARAMS_4_NORETURN(cookie, "__construct", name, value, expire, path, PH_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setdi", dependency_injector, PH_NO_CHECK);
	} else {
		PHALCON_INIT_NVAR(cookie);
		phalcon_array_fetch(&cookie, cookies, name, PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setvalue", value, PH_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setexpiration", expire, PH_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "setpath", path, PH_NO_CHECK);
	}
	
	phalcon_array_update_zval(&cookies, name, &cookie, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Register the cookies bag in the response
	 */
	PHALCON_INIT_VAR(registered);
	phalcon_read_property(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(registered)) {
		PHALCON_INIT_NVAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'response' service");
			return;
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "response", 1);
	
		PHALCON_INIT_VAR(response);
		PHALCON_CALL_METHOD_PARAMS_1(response, dependency_injector, "getshared", service, PH_NO_CHECK);
	
		/** 
		 * Pass the cookies bag to the response so it can send the headers at the of the
		 * request
		 */
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(response, "setcookies", this_ptr, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets a cookie from the bag
 *
 * @param string $name
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get){

	zval *name, *cookies, *cookie = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(cookies);
	phalcon_read_property(&cookies, this_ptr, SL("_cookies"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(cookies, name);
	if (eval_int) {
		PHALCON_INIT_VAR(cookie);
		phalcon_array_fetch(&cookie, cookies, name, PH_NOISY_CC);
	
		RETURN_CCTOR(cookie);
	}
	
	PHALCON_INIT_NVAR(cookie);
	object_init_ex(cookie, phalcon_http_cookie_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(cookie, "__construct", name, PH_CHECK);
	
	RETURN_CCTOR(cookie);
}

/**
 * Reset set cookies
 *
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset){

	zval *empty_array;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_cookies"), empty_array TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

