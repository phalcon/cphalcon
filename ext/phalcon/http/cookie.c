
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
 * Phalcon\Http\Cookie
 *
 * Provide OO wrappers to manage a HTTP cookie
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Http, Cookie, phalcon, http_cookie, phalcon_http_cookie_method_entry, 0);

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
 * @param string name
 * @param mixed value
 * @param int expire
 * @param string path
 * @param boolean secure
 * @param string domain
 * @param boolean httpOnly
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct) {

	zval *name_param = NULL, *value = NULL, *expire = NULL, *path = NULL, *secure = NULL, *domain = NULL, *httpOnly = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire, &path, &secure, &domain, &httpOnly);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;

	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}
	if (!expire) {
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}
	if (!path) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	}
	if (!secure) {
		secure = ZEPHIR_GLOBAL(global_null);
	}
	if (!domain) {
		domain = ZEPHIR_GLOBAL(global_null);
	}
	if (!httpOnly) {
		httpOnly = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if ((Z_TYPE_P(value) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_expire"), expire TSRMLS_CC);
	if ((Z_TYPE_P(path) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	}
	if ((Z_TYPE_P(secure) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_secure"), secure TSRMLS_CC);
	}
	if ((Z_TYPE_P(domain) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_domain"), domain TSRMLS_CC);
	}
	if ((Z_TYPE_P(httpOnly) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_httpOnly"), httpOnly TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Http_Cookie, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the cookie's value
 *
 * @param string value
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_readed"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the cookie's value
 *
 * @param string|array filters
 * @param string defaultValue
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Cookie, getValue) {

	zval *filters = NULL, *defaultValue = NULL, *dependencyInjector = NULL, *value, *crypt, *decryptedValue = NULL, *filter = NULL, *_0, *_1, *_COOKIE, *_2, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &filters, &defaultValue);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	ZEPHIR_INIT_VAR(dependencyInjector);
	ZVAL_NULL(dependencyInjector);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_readed"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE(_1)) {
		zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&value, _COOKIE, _2, 1 TSRMLS_CC)) {
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
			if (zephir_is_true(_3)) {
				ZEPHIR_OBS_NVAR(dependencyInjector);
				zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
					ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
					return;
				}
				ZEPHIR_INIT_VAR(_4);
				ZVAL_STRING(_4, "crypt", 1);
				ZEPHIR_INIT_VAR(crypt);
				zephir_call_method_p1(crypt, dependencyInjector, "getshared", _4);
				ZEPHIR_INIT_VAR(decryptedValue);
				zephir_call_method_p1(decryptedValue, crypt, "decryptbase64", value);
			} else {
				ZEPHIR_CPY_WRT(decryptedValue, value);
			}
			zephir_update_property_this(this_ptr, SL("_value"), decryptedValue TSRMLS_CC);
			if ((Z_TYPE_P(filters) != IS_NULL)) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if ((Z_TYPE_P(filter) != IS_OBJECT)) {
					if ((Z_TYPE_P(dependencyInjector) == IS_NULL)) {
						ZEPHIR_OBS_NVAR(dependencyInjector);
						zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
							ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
							return;
						}
					}
					ZEPHIR_INIT_NVAR(_4);
					ZVAL_STRING(_4, "filter", 1);
					ZEPHIR_INIT_NVAR(filter);
					zephir_call_method_p1(filter, dependencyInjector, "getshared", _4);
					zephir_update_property_this(this_ptr, SL("_filter"), filter TSRMLS_CC);
				}
				zephir_call_method_p2(return_value, filter, "sanitize", decryptedValue, filters);
				RETURN_MM();
			}
			RETURN_CCTOR(decryptedValue);
		}
		RETURN_CCTOR(defaultValue);
	}
	RETURN_MEMBER(this_ptr, "_value");

}

/**
 * Sends the cookie to the HTTP client
 * Stores the cookie definition in session
 *
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, send) {

	zval *name, *value, *expire, *domain, *path, *secure, *httpOnly, *dependencyInjector, *definition, *session = NULL, *crypt = NULL, *encryptValue = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();

	name = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	value = zephir_fetch_nproperty_this(this_ptr, SL("_value"), PH_NOISY_CC);
	expire = zephir_fetch_nproperty_this(this_ptr, SL("_expire"), PH_NOISY_CC);
	domain = zephir_fetch_nproperty_this(this_ptr, SL("_domain"), PH_NOISY_CC);
	path = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	secure = zephir_fetch_nproperty_this(this_ptr, SL("_secure"), PH_NOISY_CC);
	httpOnly = zephir_fetch_nproperty_this(this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'session' service");
		return;
	}
	ZEPHIR_INIT_VAR(definition);
	array_init(definition);
	if (!ZEPHIR_IS_LONG(expire, 0)) {
		zephir_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE);
	}
	if (!((0 == 0))) {
		zephir_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE);
	}
	if (!((0 == 0))) {
		zephir_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	}
	if (!((0 == 0))) {
		zephir_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE);
	}
	if (!((0 == 0))) {
		zephir_array_update_string(&definition, SL("httpOnly"), &httpOnly, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(definition TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "session", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
		ZEPHIR_CPY_WRT(session, _0);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "_PHCOOKIE_", name);
		zephir_call_method_p2_noret(session, "set", _2, definition);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		if (!((0 == 0))) {
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service");
				return;
			}
			ZEPHIR_INIT_NVAR(_0);
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "crypt", 1);
			zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
			ZEPHIR_CPY_WRT(crypt, _0);
			ZEPHIR_INIT_VAR(encryptValue);
			zephir_call_method_p1(encryptValue, crypt, "encryptbase64", value);
		} else {
			ZEPHIR_CPY_WRT(encryptValue, value);
		}
	} else {
		ZEPHIR_CPY_WRT(encryptValue, value);
	}
	zephir_call_func_p7_noret("setcookie", name, encryptValue, expire, path, domain, secure, httpOnly);
	RETURN_THIS();

}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
 * This method is automatically called internally so normally you don't need to call it
 *
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, restore) {

	zval *dependencyInjector, *expire, *domain, *path, *secure, *httpOnly, *session, *definition, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		dependencyInjector = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if ((Z_TYPE_P(dependencyInjector) == IS_OBJECT)) {
			ZEPHIR_INIT_VAR(_1);
			ZVAL_STRING(_1, "session", 1);
			ZEPHIR_INIT_VAR(session);
			zephir_call_method_p1(session, dependencyInjector, "getshared", _1);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SV(_3, "_PHCOOKIE_", _2);
			ZEPHIR_INIT_VAR(definition);
			zephir_call_method_p1(definition, session, "get", _3);
			if ((Z_TYPE_P(definition) == IS_ARRAY)) {
				if (zephir_array_isset_string_fetch(&expire, definition, SS("expire"), 1 TSRMLS_CC)) {
					zephir_update_property_this(this_ptr, SL("_expire"), expire TSRMLS_CC);
				}
				if (zephir_array_isset_string_fetch(&domain, definition, SS("domain"), 1 TSRMLS_CC)) {
					zephir_update_property_this(this_ptr, SL("_domain"), domain TSRMLS_CC);
				}
				if (zephir_array_isset_string_fetch(&path, definition, SS("path"), 1 TSRMLS_CC)) {
					zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
				}
				if (zephir_array_isset_string_fetch(&secure, definition, SS("secure"), 1 TSRMLS_CC)) {
					zephir_update_property_this(this_ptr, SL("_secure"), secure TSRMLS_CC);
				}
				if (zephir_array_isset_string_fetch(&httpOnly, definition, SS("httpOnly"), 1 TSRMLS_CC)) {
					zephir_update_property_this(this_ptr, SL("_httpOnly"), httpOnly TSRMLS_CC);
				}
			}
		}
		zephir_update_property_this(this_ptr, SL("_restored"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Deletes the cookie by setting an expire time in the past
 *
 */
PHP_METHOD(Phalcon_Http_Cookie, delete) {

	zval *name, *domain, *path, *secure, *httpOnly, *dependencyInjector = NULL, *session = NULL, *_0, *_1 = NULL, *_2, *_3, _4;

	ZEPHIR_MM_GROW();

	name = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
	domain = zephir_fetch_nproperty_this(this_ptr, SL("_domain"), PH_NOISY_CC);
	path = zephir_fetch_nproperty_this(this_ptr, SL("_path"), PH_NOISY_CC);
	secure = zephir_fetch_nproperty_this(this_ptr, SL("_secure"), PH_NOISY_CC);
	httpOnly = zephir_fetch_nproperty_this(this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "session", 1);
		zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(session, _1);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "_PHCOOKIE_", name);
		zephir_call_method_p1_noret(session, "remove", _3);
	}
	zephir_update_property_this(this_ptr, SL("_value"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	zephir_call_func(_1, "time");
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, (zephir_get_numberval(_1) - 691200));
	zephir_call_func_p7_noret("setcookie", name, ZEPHIR_GLOBAL(global_null), &_4, path, domain, secure, httpOnly);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 *
 * @param boolean useEncryption
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, useEncryption) {

	zval *useEncryption_param = NULL;
	zend_bool useEncryption;

	zephir_fetch_params(0, 1, 0, &useEncryption_param);

		useEncryption = zephir_get_boolval(useEncryption_param);


	zephir_update_property_this(this_ptr, SL("_useEncryption"), useEncryption ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Check if the cookie is using implicit encryption
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption) {


	RETURN_MEMBER(this_ptr, "_useEncryption");

}

/**
 * Sets the cookie's expiration time
 *
 * @param int expire
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration) {

	zval *expire_param = NULL, *_0, *_1;
	int expire;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expire_param);

		expire = zephir_get_intval(expire_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, expire);
	zephir_update_property_zval(this_ptr, SL("_expire"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current expiration time
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	RETURN_MEMBER(this_ptr, "_expire");

}

/**
 * Sets the cookie's expiration time
 *
 * @param string path
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath) {

	zval *path_param = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

		if (Z_TYPE_P(path_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		path = path_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	zephir_update_property_this(this_ptr, SL("_path"), path TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cookie's path
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	RETURN_MEMBER(this_ptr, "_path");

}

/**
 * Sets the domain that the cookie is available to
 *
 * @param string domain
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setDomain) {

	zval *domain_param = NULL, *_0;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

		if (Z_TYPE_P(domain_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		domain = domain_param;



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	zephir_update_property_this(this_ptr, SL("_domain"), domain TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the domain that the cookie is available to
 *
 * @return string
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	RETURN_MEMBER(this_ptr, "_domain");

}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @param boolean secure
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure) {

	zval *secure_param = NULL, *_0;
	zend_bool secure;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &secure_param);

		secure = zephir_get_boolval(secure_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	zephir_update_property_this(this_ptr, SL("_secure"), secure ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	RETURN_MEMBER(this_ptr, "_secure");

}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 *
 * @param boolean httpOnly
 * @return Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly) {

	zval *httpOnly_param = NULL, *_0;
	zend_bool httpOnly;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpOnly_param);

		httpOnly = zephir_get_boolval(httpOnly_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	zephir_update_property_this(this_ptr, SL("_httpOnly"), httpOnly ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly) {

	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		zephir_call_method_noret(this_ptr, "restore");
	}
	RETURN_MEMBER(this_ptr, "_httpOnly");

}

/**
 * Magic __toString method converts the cookie's value to string
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString) {



}

