
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"

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
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_restored"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_useEncryption"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_filter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_expire"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_domain"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_secure"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_httpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * @param boolean $secure
 * @param boolean $httpOnly
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct){

	zval *name, *value = NULL, *expire = NULL, *path = NULL, *secure = NULL, *http_only = NULL;

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
	phalcon_update_property_zval(this_ptr, SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(value) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_value"), value TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	if (Z_TYPE_P(path) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
	}
	
	if (Z_TYPE_P(secure) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_secure"), secure TSRMLS_CC);
	}
	
	if (Z_TYPE_P(http_only) != IS_NULL) {
		phalcon_update_property_zval(this_ptr, SL("_httpOnly"), http_only TSRMLS_CC);
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

	zval *filters = NULL, *default_value = NULL, *restored, *dependency_injector = NULL;
	zval *readed, *name, *_COOKIE, *value = NULL, *encryption;
	zval *service = NULL, *crypt, *decrypted_value = NULL, *filter = NULL;
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
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	
	PHALCON_OBS_VAR(readed);
	phalcon_read_property_this(&readed, this_ptr, SL("_readed"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(readed)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
		phalcon_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
		if (phalcon_array_isset(_COOKIE, name)) {
	
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch(&value, _COOKIE, name, PH_NOISY_CC);
	
			PHALCON_OBS_VAR(encryption);
			phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
			if (zend_is_true(encryption)) {
	
				PHALCON_OBS_NVAR(dependency_injector);
				phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
					return;
				}
	
				PHALCON_INIT_VAR(service);
				ZVAL_STRING(service, "crypt", 1);
	
				PHALCON_INIT_VAR(crypt);
				PHALCON_CALL_METHOD_PARAMS_1(crypt, dependency_injector, "getshared", service);
	
				/** 
				 * Decrypt the value also decoding it with base64
				 */
				PHALCON_INIT_VAR(decrypted_value);
				PHALCON_CALL_METHOD_PARAMS_1(decrypted_value, crypt, "decryptbase64", value);
			} else {
				PHALCON_CPY_WRT(decrypted_value, value);
			}
	
			/** 
			 * Update the decrypted value
			 */
			phalcon_update_property_zval(this_ptr, SL("_value"), decrypted_value TSRMLS_CC);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					if (Z_TYPE_P(dependency_injector) == IS_NULL) {
	
						PHALCON_OBS_NVAR(dependency_injector);
						phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
							PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
							return;
						}
					}
	
					PHALCON_INIT_NVAR(service);
					ZVAL_STRING(service, "filter", 1);
	
					PHALCON_INIT_NVAR(filter);
					PHALCON_CALL_METHOD_PARAMS_1(filter, dependency_injector, "getshared", service);
					phalcon_update_property_zval(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_INIT_VAR(sanitized_value);
				PHALCON_CALL_METHOD_PARAMS_2(sanitized_value, filter, "sanitize", decrypted_value, filters);
	
				RETURN_CCTOR(sanitized_value);
			}
	
			/** 
			 * Return the value without filtering
			 */
	
			RETURN_CCTOR(decrypted_value);
		}
	
	
		RETURN_CCTOR(default_value);
	}
	
	PHALCON_OBS_NVAR(value);
	phalcon_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	
	RETURN_CCTOR(value);
}

/**
 * Sends the cookie to the HTTP client
 * Stores the cookie definition in session
 *
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, send){

	zval *name, *value, *expire, *domain, *path, *secure;
	zval *http_only, *dependency_injector, *definition;
	zval *service = NULL, *session, *key, *encryption, *crypt;
	zval *encrypt_value = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(value);
	phalcon_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(expire);
	phalcon_read_property_this(&expire, this_ptr, SL("_expire"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'session' service");
		return;
	}
	
	PHALCON_INIT_VAR(definition);
	array_init(definition);
	if (!PHALCON_IS_LONG(expire, 0)) {
		phalcon_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (PHALCON_IS_NOT_EMPTY(path)) {
		phalcon_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (PHALCON_IS_NOT_EMPTY(domain)) {
		phalcon_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (PHALCON_IS_NOT_EMPTY(secure)) {
		phalcon_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	if (PHALCON_IS_NOT_EMPTY(http_only)) {
		phalcon_array_update_string(&definition, SL("httpOnly"), &http_only, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	/** 
	 * The definition is stored in session
	 */
	if (phalcon_fast_count_ev(definition TSRMLS_CC)) {
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "session", 1);
	
		PHALCON_INIT_VAR(session);
		PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service);
	
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(session, "set", key, definition);
	}
	
	PHALCON_OBS_VAR(encryption);
	phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	if (zend_is_true(encryption)) {
		if (PHALCON_IS_NOT_EMPTY(value)) {
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
	
			PHALCON_INIT_NVAR(service);
			ZVAL_STRING(service, "crypt", 1);
	
			PHALCON_INIT_VAR(crypt);
			PHALCON_CALL_METHOD_PARAMS_1(crypt, dependency_injector, "getshared", service);
	
			/** 
			 * Encrypt the value also coding it with base64
			 */
			PHALCON_INIT_VAR(encrypt_value);
			PHALCON_CALL_METHOD_PARAMS_1(encrypt_value, crypt, "encryptbase64", value);
		} else {
			PHALCON_CPY_WRT(encrypt_value, value);
		}
	} else {
		PHALCON_CPY_WRT(encrypt_value, value);
	}
	
	/** 
	 * Sets the cookie using the standard 'setcookie' function
	 */
	
	p0[0] = name;
	p0[1] = encrypt_value;
	p0[2] = expire;
	p0[3] = path;
	p0[4] = domain;
	p0[5] = secure;
	p0[6] = http_only;
	PHALCON_CALL_FUNC_PARAMS_NORETURN("setcookie", 7, p0);
	
	RETURN_THIS();
}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
 * This method is automatically called internally so normally you don't need to call it
 */
PHP_METHOD(Phalcon_Http_Cookie, restore){

	zval *restored, *dependency_injector, *service;
	zval *session, *name, *key, *definition, *expire, *domain;
	zval *path, *secure, *http_only;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "session", 1);
	
			PHALCON_INIT_VAR(session);
			PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service);
	
			PHALCON_OBS_VAR(name);
			phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(key);
			PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
	
			PHALCON_INIT_VAR(definition);
			PHALCON_CALL_METHOD_PARAMS_1(definition, session, "get", key);
			if (Z_TYPE_P(definition) == IS_ARRAY) { 
				if (phalcon_array_isset_string(definition, SS("expire"))) {
					PHALCON_OBS_VAR(expire);
					phalcon_array_fetch_string(&expire, definition, SL("expire"), PH_NOISY_CC);
					phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
				}
				if (phalcon_array_isset_string(definition, SS("domain"))) {
					PHALCON_OBS_VAR(domain);
					phalcon_array_fetch_string(&domain, definition, SL("domain"), PH_NOISY_CC);
					phalcon_update_property_zval(this_ptr, SL("_domain"), domain TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("path"))) {
					PHALCON_OBS_VAR(path);
					phalcon_array_fetch_string(&path, definition, SL("path"), PH_NOISY_CC);
					phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("secure"))) {
					PHALCON_OBS_VAR(secure);
					phalcon_array_fetch_string(&secure, definition, SL("secure"), PH_NOISY_CC);
					phalcon_update_property_zval(this_ptr, SL("_secure"), secure TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("httpOnly"))) {
					PHALCON_OBS_VAR(http_only);
					phalcon_array_fetch_string(&http_only, definition, SL("httpOnly"), PH_NOISY_CC);
					phalcon_update_property_zval(this_ptr, SL("_httpOnly"), http_only TSRMLS_CC);
				}
			}
		}
	
		phalcon_update_property_bool(this_ptr, SL("_restored"), 1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Deletes the cookie by setting an expire time in the past
 *
 */
PHP_METHOD(Phalcon_Http_Cookie, delete){

	zval *name, *domain, *path, *secure, *http_only, *dependency_injector;
	zval *service, *session, *key, *now, *days, *yesterday;
	zval *znull;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "session", 1);
	
		PHALCON_INIT_VAR(session);
		PHALCON_CALL_METHOD_PARAMS_1(session, dependency_injector, "getshared", service);
	
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(session, "remove", key);
	}
	
	PHALCON_INIT_VAR(now);
	ZVAL_LONG(now, (long) time(NULL));
	
	PHALCON_INIT_VAR(days);
	ZVAL_LONG(days, 691200);
	
	PHALCON_INIT_VAR(yesterday);
	sub_function(yesterday, now, days TSRMLS_CC);
	
	PHALCON_INIT_VAR(znull);
	phalcon_update_property_null(this_ptr, SL("_value") TSRMLS_CC);
	
	p0[0] = name;
	p0[1] = znull;
	p0[2] = yesterday;
	p0[3] = path;
	p0[4] = domain;
	p0[5] = secure;
	p0[6] = http_only;
	PHALCON_CALL_FUNC_PARAMS_NORETURN("setcookie", 7, p0);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 *
 * @param boolean $useEncryption
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, useEncryption){

	zval *use_encryption;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &use_encryption) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_useEncryption"), use_encryption TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Check if the cookie is using implicit encryption
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption){


	RETURN_MEMBER(this_ptr, "_useEncryption");
}

/**
 * Sets the cookie's expiration time
 *
 * @param int $expire
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration){

	zval *expire, *restored;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expire) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	phalcon_update_property_zval(this_ptr, SL("_expire"), expire TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the current expiration time
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration){

	zval *restored, *expire;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(expire);
	phalcon_read_property_this(&expire, this_ptr, SL("_expire"), PH_NOISY_CC);
	
	RETURN_CCTOR(expire);
}

/**
 * Sets the cookie's expiration time
 *
 * @param string $path
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath){

	zval *path, *restored;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &path) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	phalcon_update_property_zval(this_ptr, SL("_path"), path TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the current cookie's path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath){

	zval *restored, *path;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	RETURN_CCTOR(path);
}

/**
 * Sets the domain that the cookie is available to
 *
 * @param string $domain
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setDomain){

	zval *domain, *restored;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &domain) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	phalcon_update_property_zval(this_ptr, SL("_domain"), domain TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns the domain that the cookie is available to
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain){

	zval *restored, *domain;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	
	RETURN_CCTOR(domain);
}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @param boolean $secure
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure){

	zval *secure, *restored;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &secure) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	phalcon_update_property_zval(this_ptr, SL("_secure"), secure TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure){

	zval *restored, *secure;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	
	RETURN_CCTOR(secure);
}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 *
 * @param boolean $httpOnly
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly){

	zval *http_only, *restored;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &http_only) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	phalcon_update_property_zval(this_ptr, SL("_httpOnly"), http_only TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly){

	zval *restored, *http_only;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	
	RETURN_CCTOR(http_only);
}

/**
 * Magic __toString method converts the cookie's value to string
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString){


	RETURN_MEMBER(this_ptr, "_value");
}

