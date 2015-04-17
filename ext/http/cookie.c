
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "http/cookie.h"
#include "http/cookie/exception.h"
#include "cryptinterface.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"
#include "filterinterface.h"
#include "session/adapterinterface.h"

#include <ext/standard/head.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/concat.h"

#include "interned-strings.h"

/**
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie
 */
zend_class_entry *phalcon_http_cookie_ce;

PHP_METHOD(Phalcon_Http_Cookie, __construct);
PHP_METHOD(Phalcon_Http_Cookie, setDI);
PHP_METHOD(Phalcon_Http_Cookie, getDI);
PHP_METHOD(Phalcon_Http_Cookie, setValue);
PHP_METHOD(Phalcon_Http_Cookie, getValue);
PHP_METHOD(Phalcon_Http_Cookie, send);
PHP_METHOD(Phalcon_Http_Cookie, restore);
PHP_METHOD(Phalcon_Http_Cookie, delete);
PHP_METHOD(Phalcon_Http_Cookie, useEncryption);
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption);
PHP_METHOD(Phalcon_Http_Cookie, setExpiration);
PHP_METHOD(Phalcon_Http_Cookie, getExpiration);
PHP_METHOD(Phalcon_Http_Cookie, setPath);
PHP_METHOD(Phalcon_Http_Cookie, getPath);
PHP_METHOD(Phalcon_Http_Cookie, setDomain);
PHP_METHOD(Phalcon_Http_Cookie, getDomain);
PHP_METHOD(Phalcon_Http_Cookie, setSecure);
PHP_METHOD(Phalcon_Http_Cookie, getSecure);
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly);
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly);
PHP_METHOD(Phalcon_Http_Cookie, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_http_cookie_method_entry[] = {
	PHP_ME(Phalcon_Http_Cookie, __construct, arginfo_phalcon_http_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Cookie, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setValue, arginfo_phalcon_http_cookie_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getValue, arginfo_phalcon_http_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, restore, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, useEncryption, arginfo_phalcon_http_cookie_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, isUsingEncryption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setExpiration, arginfo_phalcon_http_cookie_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getExpiration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setPath, arginfo_phalcon_http_cookie_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setDomain, arginfo_phalcon_http_cookie_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setSecure, arginfo_phalcon_http_cookie_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setHttpOnly, arginfo_phalcon_http_cookie_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getHttpOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	zend_declare_property_string(phalcon_http_cookie_ce, SL("_path"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_domain"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_http_cookie_ce, SL("_secure"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("_httpOnly"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * @param string $domain
 * @param boolean $httpOnly
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct){

	zval **name, **value = NULL, **expire = NULL, **path = NULL, **secure = NULL, **domain = NULL;
	zval **http_only = NULL;

	phalcon_fetch_params_ex(1, 6, &name, &value, &expire, &path, &secure, &domain, &http_only);
	PHALCON_ENSURE_IS_STRING(name);

	if (!expire) {
		expire = &PHALCON_GLOBAL(z_zero);
	}
	
	phalcon_update_property_this(this_ptr, SL("_name"), *name TSRMLS_CC);

	if (value && Z_TYPE_PP(value) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_value"), *value TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_readed"), 1 TSRMLS_CC);
	}
	
	phalcon_update_property_this(this_ptr, SL("_expire"), *expire TSRMLS_CC);

	if (path && Z_TYPE_PP(path) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_path"), *path TSRMLS_CC);
	}
	else {
		zval *path;
		PHALCON_ALLOC_GHOST_ZVAL(path);
		ZVAL_STRINGL(path, "/", 1, 1);
		phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	}
	
	if (secure && Z_TYPE_PP(secure) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_secure"), *secure TSRMLS_CC);
	}
	
	if (domain && Z_TYPE_PP(domain) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_domain"), *domain TSRMLS_CC);
	}
	
	if (http_only && Z_TYPE_PP(http_only) != IS_NULL) {
		phalcon_update_property_this(this_ptr, SL("_httpOnly"), *http_only TSRMLS_CC);
	}
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_http_cookie_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
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

	phalcon_fetch_params(0, 1, 0, &value);
	
	phalcon_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
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
	zval *service = NULL, *crypt = NULL, *decrypted_value = NULL, *filter = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &filters, &default_value);
	
	if (!filters) {
		filters = PHALCON_GLOBAL(z_null);
	}
	
	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	
	PHALCON_OBS_VAR(readed);
	phalcon_read_property_this(&readed, this_ptr, SL("_readed"), PH_NOISY TSRMLS_CC);
	if (PHALCON_IS_FALSE(readed)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);

		_COOKIE = phalcon_get_global(SS("_COOKIE") TSRMLS_CC);
		if (phalcon_array_isset_fetch(&value, _COOKIE, name)) {
	
			PHALCON_OBS_VAR(encryption);
			phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY TSRMLS_CC);
			if (zend_is_true(encryption)) {
	
				PHALCON_OBS_NVAR(dependency_injector);
				phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'filter' service");
					return;
				}
	
				PHALCON_INIT_VAR(service);
				ZVAL_STRING(service, "crypt", 1);
	
				PHALCON_CALL_METHOD(&crypt, dependency_injector, "getshared", service);
				PHALCON_VERIFY_INTERFACE(crypt, phalcon_cryptinterface_ce);
	
				/** 
				 * Decrypt the value also decoding it with base64
				 */
				PHALCON_CALL_METHOD(&decrypted_value, crypt, "decryptbase64", value);
			} else {
				PHALCON_CPY_WRT(decrypted_value, value);
			}
	
			/** 
			 * Update the decrypted value
			 */
			phalcon_update_property_this(this_ptr, SL("_value"), decrypted_value TSRMLS_CC);
			if (Z_TYPE_P(filters) != IS_NULL) {
	
				PHALCON_OBS_VAR(filter);
				phalcon_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					if (Z_TYPE_P(dependency_injector) == IS_NULL) {
	
						PHALCON_OBS_NVAR(dependency_injector);
						phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
						PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_http_cookie_exception_ce, 1);
					}
	
					PHALCON_INIT_NVAR(service);
					PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_filter);
	
					PHALCON_CALL_METHOD(&filter, dependency_injector, "getshared", service);
					PHALCON_VERIFY_INTERFACE(filter, phalcon_filterinterface_ce);
					phalcon_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
	
				PHALCON_RETURN_CALL_METHOD(filter, "sanitize", decrypted_value, filters);
				RETURN_MM();
			}
	
			/** 
			 * Return the value without filtering
			 */
	
			RETURN_CTOR(decrypted_value);
		}
	
		RETURN_CTOR(default_value);
	}
	
	PHALCON_OBS_NVAR(value);
	phalcon_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(value);
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
	zval *service = NULL, *session = NULL, *key, *encryption, *crypt = NULL;
	zval *encrypt_value = NULL, *has_session = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(value);
	phalcon_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(expire);
	phalcon_read_property_this(&expire, this_ptr, SL("_expire"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);

		PHALCON_CALL_METHOD(&has_session, dependency_injector, "has", service);
		if (zend_is_true(has_session)) {
			PHALCON_INIT_VAR(definition);
			array_init(definition);
			if (!PHALCON_IS_LONG(expire, 0)) {
				phalcon_array_update_string(&definition, SL("expire"), expire, PH_COPY);
			}

			if (PHALCON_IS_NOT_EMPTY(path)) {
				phalcon_array_update_string(&definition, SL("path"), path, PH_COPY);
			}

			if (PHALCON_IS_NOT_EMPTY(domain)) {
				phalcon_array_update_string(&definition, ISL(domain), domain, PH_COPY);
			}

			if (PHALCON_IS_NOT_EMPTY(secure)) {
				phalcon_array_update_string(&definition, SL("secure"), secure, PH_COPY);
			}

			if (PHALCON_IS_NOT_EMPTY(http_only)) {
				phalcon_array_update_string(&definition, SL("httpOnly"), http_only, PH_COPY);
			}

			/**
			 * The definition is stored in session
			 */
			if (phalcon_fast_count_ev(definition TSRMLS_CC)) {
				PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);

				if (Z_TYPE_P(session) != IS_NULL) {
					PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);

					PHALCON_INIT_VAR(key);
					PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
					PHALCON_CALL_METHOD(NULL, session, "set", key, definition);
				}
			}
		}
	}
	
	PHALCON_OBS_VAR(encryption);
	phalcon_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(encryption) && PHALCON_IS_NOT_EMPTY(value)) {
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'filter' service");
			return;
		}

		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "crypt", 1);

		PHALCON_CALL_METHOD(&crypt, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(crypt, phalcon_cryptinterface_ce);

		/**
		 * Encrypt the value also coding it with base64
		 */
		PHALCON_CALL_METHOD(&encrypt_value, crypt, "encryptbase64", value);
	} else {
		PHALCON_CPY_WRT(encrypt_value, value);
	}
	
	/** 
	 * Sets the cookie using the standard 'setcookie' function
	 */
	convert_to_string_ex(&name);
	convert_to_string_ex(&encrypt_value);
	convert_to_long_ex(&expire);
	convert_to_string_ex(&path);
	convert_to_string_ex(&domain);
	convert_to_long_ex(&secure);
	convert_to_long_ex(&http_only);

	php_setcookie(
		Z_STRVAL_P(name), Z_STRLEN_P(name),
		Z_STRVAL_P(encrypt_value), Z_STRLEN_P(encrypt_value),
		Z_LVAL_P(expire),
		Z_STRVAL_P(path), Z_STRLEN_P(path),
		Z_STRVAL_P(domain), Z_STRLEN_P(domain),
		Z_LVAL_P(secure),
		1,
		Z_LVAL_P(http_only) TSRMLS_CC
	);
	
	RETURN_THIS();
}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
 * This method is automatically called internally so normally you don't need to call it
 *
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, restore){

	zval *restored, *dependency_injector, *service;
	zval *session = NULL, *name, *key, *definition = NULL, *expire, *domain;
	zval *path, *secure, *http_only;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(service);
			PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);
	
			PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
			PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
			PHALCON_OBS_VAR(name);
			phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
	
			PHALCON_INIT_VAR(key);
			PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
	
			PHALCON_CALL_METHOD(&definition, session, "get", key);
			if (Z_TYPE_P(definition) == IS_ARRAY) { 
				if (phalcon_array_isset_string(definition, SS("expire"))) {
					PHALCON_OBS_VAR(expire);
					phalcon_array_fetch_string(&expire, definition, SL("expire"), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_expire"), expire TSRMLS_CC);
				}
				if (phalcon_array_isset_string(definition, SS("domain"))) {
					PHALCON_OBS_VAR(domain);
					phalcon_array_fetch_string(&domain, definition, SL("domain"), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_domain"), domain TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("path"))) {
					PHALCON_OBS_VAR(path);
					phalcon_array_fetch_string(&path, definition, SL("path"), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("secure"))) {
					PHALCON_OBS_VAR(secure);
					phalcon_array_fetch_string(&secure, definition, SL("secure"), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_secure"), secure TSRMLS_CC);
				}
	
				if (phalcon_array_isset_string(definition, SS("httpOnly"))) {
					PHALCON_OBS_VAR(http_only);
					phalcon_array_fetch_string(&http_only, definition, SL("httpOnly"), PH_NOISY);
					phalcon_update_property_this(this_ptr, SL("_httpOnly"), http_only TSRMLS_CC);
				}
			}
		}
	
		phalcon_update_property_bool(this_ptr, SL("_restored"), 1 TSRMLS_CC);
	}
	
	RETURN_THIS();
}

/**
 * Deletes the cookie by setting an expire time in the past
 *
 */
PHP_METHOD(Phalcon_Http_Cookie, delete){

	zval *name, *domain, *path, *secure, *http_only, *dependency_injector;
	zval *service, *session = NULL, *key;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(name);
	phalcon_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY TSRMLS_CC);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
		PHALCON_INIT_VAR(service);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(service, phalcon_interned_session);
	
		PHALCON_CALL_METHOD(&session, dependency_injector, "getshared", service);
		PHALCON_VERIFY_INTERFACE(session, phalcon_session_adapterinterface_ce);
	
		PHALCON_INIT_VAR(key);
		PHALCON_CONCAT_SV(key, "_PHCOOKIE_", name);
		PHALCON_CALL_METHOD(NULL, session, "remove", key);
	}
	
	phalcon_update_property_null(this_ptr, SL("_value") TSRMLS_CC);

	convert_to_string_ex(&name);
	convert_to_string_ex(&path);
	convert_to_string_ex(&domain);
	convert_to_long_ex(&secure);
	convert_to_long_ex(&http_only);

	php_setcookie(
		Z_STRVAL_P(name), Z_STRLEN_P(name),
		NULL, 0,
		time(NULL) - 691200,
		Z_STRVAL_P(path), Z_STRLEN_P(path),
		Z_STRVAL_P(domain), Z_STRLEN_P(domain),
		Z_LVAL_P(secure),
		1,
		Z_LVAL_P(http_only) TSRMLS_CC
	);
	
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

	phalcon_fetch_params(0, 1, 0, &use_encryption);
	
	phalcon_update_property_this(this_ptr, SL("_useEncryption"), use_encryption TSRMLS_CC);
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

	phalcon_fetch_params(1, 1, 0, &expire);
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	phalcon_update_property_this(this_ptr, SL("_expire"), expire TSRMLS_CC);
	
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
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(expire);
	phalcon_read_property_this(&expire, this_ptr, SL("_expire"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(expire);
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

	phalcon_fetch_params(1, 1, 0, &path);
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	phalcon_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	
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
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(path);
	phalcon_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(path);
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

	phalcon_fetch_params(1, 1, 0, &domain);
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	phalcon_update_property_this(this_ptr, SL("_domain"), domain TSRMLS_CC);
	
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
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(domain);
	phalcon_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(domain);
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

	phalcon_fetch_params(1, 1, 0, &secure);
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	phalcon_update_property_this(this_ptr, SL("_secure"), secure TSRMLS_CC);
	
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
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(secure);
	phalcon_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(secure);
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

	phalcon_fetch_params(1, 1, 0, &http_only);
	
	PHALCON_OBS_VAR(restored);
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	phalcon_update_property_this(this_ptr, SL("_httpOnly"), http_only TSRMLS_CC);
	
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
	phalcon_read_property_this(&restored, this_ptr, SL("_restored"), PH_NOISY TSRMLS_CC);
	if (!zend_is_true(restored)) {
		PHALCON_CALL_METHOD(NULL, this_ptr, "restore");
	}
	
	PHALCON_OBS_VAR(http_only);
	phalcon_read_property_this(&http_only, this_ptr, SL("_httpOnly"), PH_NOISY TSRMLS_CC);
	
	RETURN_CTOR(http_only);
}

/**
 * Magic __toString method converts the cookie's value to string
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString){

	zval *value;

	value = phalcon_fetch_nproperty_this(this_ptr, SL("_value"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(value) == IS_NULL) {
		if (FAILURE == phalcon_return_call_method(return_value, return_value_ptr, this_ptr, "getvalue", 0, NULL TSRMLS_CC)) {
			if (EG(exception)) {
				zval *e = EG(exception);
				zval *m = zend_read_property(Z_OBJCE_P(e), e, SL("message"), 1 TSRMLS_CC);

				Z_ADDREF_P(m);
				if (Z_TYPE_P(m) != IS_STRING) {
					convert_to_string_ex(&m);
				}

				zend_clear_exception(TSRMLS_C);
				zend_error(E_ERROR, "%s", Z_STRVAL_P(m));
				zval_ptr_dtor(&m);
			}
		}

		convert_to_string(return_value_ptr ? *return_value_ptr : return_value);
		return;
	}
	
	RETURN_ZVAL(value, 1, 0);
}
