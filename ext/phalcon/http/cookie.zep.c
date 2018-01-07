
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/time.h"


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

	zend_class_implements(phalcon_http_cookie_ce TSRMLS_CC, 1, phalcon_http_cookieinterface_ce);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *expire = NULL, *path = NULL, *secure = NULL, *domain = NULL, *httpOnly = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire, &path, &secure, &domain, &httpOnly);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
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


	zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
	if (Z_TYPE_P(value) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, value);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_expire"), expire TSRMLS_CC);
	if (Z_TYPE_P(path) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_path"), path TSRMLS_CC);
	}
	if (Z_TYPE_P(secure) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_secure"), secure TSRMLS_CC);
	}
	if (Z_TYPE_P(domain) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_domain"), domain TSRMLS_CC);
	}
	if (Z_TYPE_P(httpOnly) != IS_NULL) {
		zephir_update_property_this(getThis(), SL("_httpOnly"), httpOnly TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Cookie, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the cookie's value
 *
 * @param string value
 * @return \Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue) {

	zval *value;

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_this(getThis(), SL("_value"), value TSRMLS_CC);
	if (1) {
		zephir_update_property_this(getThis(), SL("_readed"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_readed"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, *defaultValue = NULL, *_COOKIE, *dependencyInjector = NULL, *value = NULL, *crypt = NULL, *decryptedValue = NULL, *filter = NULL, *_0, *_1, *_2$$4, *_3$$5, *_4$$6, *_5$$6, *_6$$11, *_7$$10;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 0, 2, &filters, &defaultValue);

	if (!filters) {
		filters = ZEPHIR_GLOBAL(global_null);
	}
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(dependencyInjector);
	ZVAL_NULL(dependencyInjector);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_readed"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
		ZEPHIR_OBS_VAR(value);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&value, _COOKIE, _2$$4, 0 TSRMLS_CC)) {
			_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
			if (zephir_is_true(_3$$5)) {
				_4$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				ZEPHIR_CPY_WRT(dependencyInjector, _4$$6);
				if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 152);
					return;
				}
				ZEPHIR_INIT_VAR(_5$$6);
				ZVAL_STRING(_5$$6, "crypt", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&crypt, dependencyInjector, "getshared", NULL, 0, _5$$6);
				zephir_check_temp_parameter(_5$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&decryptedValue, crypt, "decryptbase64", NULL, 0, value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(decryptedValue, value);
			}
			zephir_update_property_this(getThis(), SL("_value"), decryptedValue TSRMLS_CC);
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(filter);
				zephir_read_property_this(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(filter) != IS_OBJECT) {
					if (Z_TYPE_P(dependencyInjector) == IS_NULL) {
						_6$$11 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
						ZEPHIR_CPY_WRT(dependencyInjector, _6$$11);
						if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 178);
							return;
						}
					}
					ZEPHIR_INIT_VAR(_7$$10);
					ZVAL_STRING(_7$$10, "filter", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(&filter, dependencyInjector, "getshared", NULL, 0, _7$$10);
					zephir_check_temp_parameter(_7$$10);
					zephir_check_call_status();
					zephir_update_property_this(getThis(), SL("_filter"), filter TSRMLS_CC);
				}
				ZEPHIR_RETURN_CALL_METHOD(filter, "sanitize", NULL, 0, decryptedValue, filters);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_CCTOR(decryptedValue);
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_MM_MEMBER(getThis(), "_value");

}

/**
 * Sends the cookie to the HTTP client
 * Stores the cookie definition in session
 */
PHP_METHOD(Phalcon_Http_Cookie, send) {

	zval *_6$$12 = NULL;
	zval *name = NULL, *value = NULL, *expire = NULL, *domain = NULL, *path = NULL, *secure = NULL, *httpOnly = NULL, *dependencyInjector = NULL, *definition = NULL, *session = NULL, *crypt = NULL, *encryptValue = NULL, *_3, *_0$$9 = NULL, *_1$$9, *_2$$10, *_4$$12 = NULL, *_5$$12;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(name);
	zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(value);
	zephir_read_property_this(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(expire);
	zephir_read_property_this(&expire, this_ptr, SL("_expire"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(domain);
	zephir_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(path);
	zephir_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(secure);
	zephir_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(httpOnly);
	zephir_read_property_this(&httpOnly, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'session' service", "phalcon/http/cookie.zep", 220);
		return;
	}
	ZEPHIR_INIT_VAR(definition);
	array_init(definition);
	if (!ZEPHIR_IS_LONG(expire, 0)) {
		zephir_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(path))) {
		zephir_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(domain))) {
		zephir_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(secure))) {
		zephir_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(httpOnly))) {
		zephir_array_update_string(&definition, SL("httpOnly"), &httpOnly, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(definition TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_1$$9);
		ZVAL_STRING(_1$$9, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$9, dependencyInjector, "getshared", NULL, 0, _1$$9);
		zephir_check_temp_parameter(_1$$9);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(session, _0$$9);
		ZEPHIR_CALL_METHOD(&_0$$9, session, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_0$$9)) {
			ZEPHIR_INIT_VAR(_2$$10);
			ZEPHIR_CONCAT_SV(_2$$10, "_PHCOOKIE_", name);
			ZEPHIR_CALL_METHOD(NULL, session, "set", NULL, 0, _2$$10, definition);
			zephir_check_call_status();
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	if (zephir_is_true(_3)) {
		if (!(ZEPHIR_IS_EMPTY(value))) {
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 260);
				return;
			}
			ZEPHIR_INIT_VAR(_5$$12);
			ZVAL_STRING(_5$$12, "crypt", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_4$$12, dependencyInjector, "getshared", NULL, 0, _5$$12);
			zephir_check_temp_parameter(_5$$12);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(crypt, _4$$12);
			zephir_get_strval(_6$$12, value);
			ZEPHIR_CALL_METHOD(&encryptValue, crypt, "encryptbase64", NULL, 0, _6$$12);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(encryptValue, value);
		}
	} else {
		ZEPHIR_CPY_WRT(encryptValue, value);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 229, name, encryptValue, expire, path, domain, secure, httpOnly);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
 * This method is automatically called internally so normally you don't need to call it
 */
PHP_METHOD(Phalcon_Http_Cookie, restore) {

	zval *dependencyInjector = NULL, *expire = NULL, *domain = NULL, *path = NULL, *secure = NULL, *httpOnly = NULL, *session = NULL, *definition = NULL, *_0, *_1$$4, *_2$$4 = NULL, *_3$$5, *_4$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_1$$4);
			ZVAL_STRING(_1$$4, "session", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&session, dependencyInjector, "getshared", NULL, 0, _1$$4);
			zephir_check_temp_parameter(_1$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2$$4, session, "isstarted", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_2$$4)) {
				_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_name"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_4$$5);
				ZEPHIR_CONCAT_SV(_4$$5, "_PHCOOKIE_", _3$$5);
				ZEPHIR_CALL_METHOD(&definition, session, "get", NULL, 0, _4$$5);
				zephir_check_call_status();
				if (Z_TYPE_P(definition) == IS_ARRAY) {
					if (zephir_array_isset_string_fetch(&expire, definition, SS("expire"), 1 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_expire"), expire TSRMLS_CC);
					}
					if (zephir_array_isset_string_fetch(&domain, definition, SS("domain"), 1 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_domain"), domain TSRMLS_CC);
					}
					if (zephir_array_isset_string_fetch(&path, definition, SS("path"), 1 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_path"), path TSRMLS_CC);
					}
					if (zephir_array_isset_string_fetch(&secure, definition, SS("secure"), 1 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_secure"), secure TSRMLS_CC);
					}
					if (zephir_array_isset_string_fetch(&httpOnly, definition, SS("httpOnly"), 1 TSRMLS_CC)) {
						zephir_update_property_this(getThis(), SL("_httpOnly"), httpOnly TSRMLS_CC);
					}
				}
			}
		}
		if (1) {
			zephir_update_property_this(getThis(), SL("_restored"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_restored"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Deletes the cookie by setting an expire time in the past
 */
PHP_METHOD(Phalcon_Http_Cookie, delete) {

	zval *name = NULL, *domain = NULL, *path = NULL, *secure = NULL, *httpOnly = NULL, *dependencyInjector = NULL, *session = NULL, *_0, *_4, _5, *_1$$3 = NULL, *_2$$3, *_3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(name);
	zephir_read_property_this(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(domain);
	zephir_read_property_this(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(path);
	zephir_read_property_this(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(secure);
	zephir_read_property_this(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(httpOnly);
	zephir_read_property_this(&httpOnly, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "session", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, dependencyInjector, "getshared", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(session, _1$$3);
		ZEPHIR_CALL_METHOD(&_1$$3, session, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_INIT_VAR(_3$$4);
			ZEPHIR_CONCAT_SV(_3$$4, "_PHCOOKIE_", name);
			ZEPHIR_CALL_METHOD(NULL, session, "remove", NULL, 0, _3$$4);
			zephir_check_call_status();
		}
	}
	zephir_update_property_this(getThis(), SL("_value"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_time(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, (zephir_get_numberval(_4) - 691200));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 229, name, ZEPHIR_GLOBAL(global_null), &_5, path, domain, secure, httpOnly);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 */
PHP_METHOD(Phalcon_Http_Cookie, useEncryption) {

	zval *useEncryption_param = NULL;
	zend_bool useEncryption;

	zephir_fetch_params(0, 1, 0, &useEncryption_param);

	useEncryption = zephir_get_boolval(useEncryption_param);


	if (useEncryption) {
		zephir_update_property_this(getThis(), SL("_useEncryption"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_useEncryption"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Check if the cookie is using implicit encryption
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption) {

	

	RETURN_MEMBER(getThis(), "_useEncryption");

}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration) {

	zval *expire_param = NULL, *_0, *_1;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expire_param);

	expire = zephir_get_intval(expire_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, expire);
	zephir_update_property_this(getThis(), SL("_expire"), _1 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_expire");

}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *_0;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(path, path_param);
	} else {
		ZEPHIR_INIT_VAR(path);
		ZVAL_EMPTY_STRING(path);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_path"), path TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cookie's name
 */
PHP_METHOD(Phalcon_Http_Cookie, getName) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Returns the current cookie's path
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_path");

}

/**
 * Sets the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, setDomain) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL, *_0;
	zval *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_domain"), domain TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_domain");

}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *secure_param = NULL, *_0;
	zend_bool secure;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &secure_param);

	secure = zephir_get_boolval(secure_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (secure) {
		zephir_update_property_this(getThis(), SL("_secure"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_secure"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_secure");

}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpOnly_param = NULL, *_0;
	zend_bool httpOnly;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpOnly_param);

	httpOnly = zephir_get_boolval(httpOnly_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (httpOnly) {
		zephir_update_property_this(getThis(), SL("_httpOnly"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_httpOnly"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_restored"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "_httpOnly");

}

/**
 * Magic __toString method converts the cookie's value to string
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString) {

	zval *_1 = NULL;
	zval *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

