
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie
 */


/**
 * Phalcon\Http\Cookie initializer
 */
PHALCON_INIT_CLASS(Phalcon_Http_Cookie){

	PHALCON_REGISTER_CLASS(Phalcon\\Http, Cookie, http_cookie, phalcon_http_cookie_method_entry, 0);

	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_readed"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_secure"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_http_cookie_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Http\Cookie constructor
 *
 * @param string $name
 * @param mixed $value
 * @param int $expire
 * @param string $path
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct){

	zval *name, *value = NULL, *expire = NULL, *path = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &name, &value, &expire, &path) == FAILURE) {
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
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "The cookie name must be string");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(value) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	if (Z_TYPE_P(path) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI){

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
PHP_METHOD(Phalcon_Http_Cookie, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the cookie's value
 *
 * @param string $value
 * @return Phalcon\Http\CookieInterface
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue){

	zval *value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_readed"), 1 TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the cookie's value
 *
 * @param string|array $filters
 * @param string $defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Cookie, getValue){

	zval *filters = NULL, *default_value = NULL, *readed, *name, *_COOKIE;
	zval *value, *filter = NULL, *dependency_injector, *service;
	zval *sanitized_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &filters, &default_value) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!filters) {
		PHALCON_INIT_VAR(filters);
	}
	
	if (!default_value) {
		PHALCON_INIT_VAR(default_value);
	}
	
	PHALCON_OBS_VAR(readed);
	phalcon_read_property_this(&readed, this_ptr, SL("_readed"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(readed)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
		phalcon_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
		if (phalcon_array_isset(_COOKIE, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, _COOKIE, name, PH_NOISY_CC);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
	
					PHALCON_OBS_VAR(dependency_injector);
					phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
					if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_http_request_exception_ce, "A dependency injection object is required to access the 'filter' service");
						return;
					}
	
					PHALCON_INIT_VAR(service);
					ZVAL_STRING(service, "filter", 1);
	
					PHALCON_INIT_NVAR(filter);
					PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
					phalcon_update_property_zval(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_INIT_VAR(sanitized_value);
				PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", value, filters);
	
				RETURN_CCTOR(sanitized_value);
			} else {
				RETURN_CCTOR(value);
			}
		}
	
	
		RETURN_CCTOR(default_value);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the cookie's expiration time
 *
 * @param int $expire
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration){

	zval *expire;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expire) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current expiration time
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration){


	RETURN_MEMBER(this_ptr, "_expire");
}

/**
 * Sets the cookie's expiration time
 *
 * @param string $path
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath){

	zval *path;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &path) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current cookie's path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath){


	RETURN_MEMBER(this_ptr, "_path");
}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @param boolean $secure
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure){

	zval *secure;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &secure) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_secure"), secure TSRMLS_CC);
	
}

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure){


	RETURN_MEMBER(this_ptr, "_secure");
}

