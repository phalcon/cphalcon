
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, *expire = NULL, expire_sub, *path = NULL, path_sub, *secure = NULL, secure_sub, *domain = NULL, domain_sub, *httpOnly = NULL, httpOnly_sub, __$null;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&secure_sub);
	ZVAL_UNDEF(&domain_sub);
	ZVAL_UNDEF(&httpOnly_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire, &path, &secure, &domain, &httpOnly);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}
	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/");
	}
	if (!secure) {
		secure = &secure_sub;
		secure = &__$null;
	}
	if (!domain) {
		domain = &domain_sub;
		domain = &__$null;
	}
	if (!httpOnly) {
		httpOnly = &httpOnly_sub;
		httpOnly = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	if (Z_TYPE_P(value) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, value);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_expire"), expire);
	if (Z_TYPE_P(path) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_path"), path);
	}
	if (Z_TYPE_P(secure) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_secure"), secure);
	}
	if (Z_TYPE_P(domain) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_domain"), domain);
	}
	if (Z_TYPE_P(httpOnly) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("_httpOnly"), httpOnly);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Cookie, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Cookie, getDI) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the cookie's value
 *
 * @param string value
 * @return \Phalcon\Http\Cookie
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue) {

	zval *value, value_sub, __$true, __$false;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &value);



	zephir_update_property_zval(this_ptr, SL("_value"), value);
	if (1) {
		zephir_update_property_zval(this_ptr, SL("_readed"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_readed"), &__$false);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, _COOKIE, __$null, dependencyInjector, value, crypt, decryptedValue, filter, _0, _1, _2$$4, _3$$5, _4$$6, _5$$6, _6$$11, _7$$10;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&crypt);
	ZVAL_UNDEF(&decryptedValue);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 0, 2, &filters, &defaultValue);

	if (!filters) {
		filters = &filters_sub;
		filters = &__$null;
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&dependencyInjector);
	ZVAL_NULL(&dependencyInjector);
	zephir_read_property(&_1, this_ptr, SL("_readed"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_OBS_VAR(&value);
		zephir_read_property(&_2$$4, this_ptr, SL("_name"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_fetch(&value, &_COOKIE, &_2$$4, 0 TSRMLS_CC)) {
			zephir_read_property(&_3$$5, this_ptr, SL("_useEncryption"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_3$$5)) {
				zephir_read_property(&_4$$6, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CPY_WRT(&dependencyInjector, &_4$$6);
				if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 152);
					return;
				}
				ZEPHIR_INIT_VAR(&_5$$6);
				ZVAL_STRING(&_5$$6, "crypt");
				ZEPHIR_CALL_METHOD(&crypt, &dependencyInjector, "getshared", NULL, 0, &_5$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&decryptedValue, &crypt, "decryptbase64", NULL, 0, &value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&decryptedValue, &value);
			}
			zephir_update_property_zval(this_ptr, SL("_value"), &decryptedValue);
			if (Z_TYPE_P(filters) != IS_NULL) {
				ZEPHIR_OBS_VAR(&filter);
				zephir_read_property(&filter, this_ptr, SL("_filter"), PH_NOISY_CC);
				if (Z_TYPE_P(&filter) != IS_OBJECT) {
					if (Z_TYPE_P(&dependencyInjector) == IS_NULL) {
						zephir_read_property(&_6$$11, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CPY_WRT(&dependencyInjector, &_6$$11);
						if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
							ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 178);
							return;
						}
					}
					ZEPHIR_INIT_VAR(&_7$$10);
					ZVAL_STRING(&_7$$10, "filter");
					ZEPHIR_CALL_METHOD(&filter, &dependencyInjector, "getshared", NULL, 0, &_7$$10);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("_filter"), &filter);
				}
				ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &decryptedValue, filters);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_CCTOR(decryptedValue);
		}
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_MM_MEMBER(this_ptr, "_value");

}

/**
 * Sends the cookie to the HTTP client
 * Stores the cookie definition in session
 */
PHP_METHOD(Phalcon_Http_Cookie, send) {

	zval _6$$12;
	zval name, value, expire, domain, path, secure, httpOnly, dependencyInjector, definition, session, crypt, encryptValue, _3, _0$$9, _1$$9, _2$$10, _4$$12, _5$$12;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&crypt);
	ZVAL_UNDEF(&encryptValue);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$9);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$10);
	ZVAL_UNDEF(&_4$$12);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_6$$12);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&name);
	zephir_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&value);
	zephir_read_property(&value, this_ptr, SL("_value"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&expire);
	zephir_read_property(&expire, this_ptr, SL("_expire"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&domain);
	zephir_read_property(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&path);
	zephir_read_property(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&secure);
	zephir_read_property(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&httpOnly);
	zephir_read_property(&httpOnly, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&dependencyInjector);
	zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'session' service", "phalcon/http/cookie.zep", 220);
		return;
	}
	ZEPHIR_INIT_VAR(&definition);
	array_init(&definition);
	if (!ZEPHIR_IS_LONG(&expire, 0)) {
		zephir_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&path))) {
		zephir_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&domain))) {
		zephir_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&secure))) {
		zephir_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&httpOnly))) {
		zephir_array_update_string(&definition, SL("httpOnly"), &httpOnly, PH_COPY | PH_SEPARATE);
	}
	if (zephir_fast_count_int(&definition TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1$$9);
		ZVAL_STRING(&_1$$9, "session");
		ZEPHIR_CALL_METHOD(&_0$$9, &dependencyInjector, "getshared", NULL, 0, &_1$$9);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_0$$9);
		ZEPHIR_CALL_METHOD(&_0$$9, &session, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$9)) {
			ZEPHIR_INIT_VAR(&_2$$10);
			ZEPHIR_CONCAT_SV(&_2$$10, "_PHCOOKIE_", &name);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_2$$10, &definition);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_3, this_ptr, SL("_useEncryption"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		if (!(ZEPHIR_IS_EMPTY(&value))) {
			if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection object is required to access the 'filter' service", "phalcon/http/cookie.zep", 260);
				return;
			}
			ZEPHIR_INIT_VAR(&_5$$12);
			ZVAL_STRING(&_5$$12, "crypt");
			ZEPHIR_CALL_METHOD(&_4$$12, &dependencyInjector, "getshared", NULL, 0, &_5$$12);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&crypt, &_4$$12);
			zephir_get_strval(&_6$$12, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_6$$12);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&encryptValue, &value);
		}
	} else {
		ZEPHIR_CPY_WRT(&encryptValue, &value);
	}
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 225, &name, &encryptValue, &expire, &path, &domain, &secure, &httpOnly);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as it was set
 * This method is automatically called internally so normally you don't need to call it
 */
PHP_METHOD(Phalcon_Http_Cookie, restore) {

	zval __$true, __$false, dependencyInjector, expire, domain, path, secure, httpOnly, session, definition, _0, _1$$4, _2$$4, _3$$5, _4$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_OBS_VAR(&dependencyInjector);
		zephir_read_property(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(&dependencyInjector) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZVAL_STRING(&_1$$4, "session");
			ZEPHIR_CALL_METHOD(&session, &dependencyInjector, "getshared", NULL, 0, &_1$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2$$4, &session, "isstarted", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_2$$4)) {
				zephir_read_property(&_3$$5, this_ptr, SL("_name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_4$$5);
				ZEPHIR_CONCAT_SV(&_4$$5, "_PHCOOKIE_", &_3$$5);
				ZEPHIR_CALL_METHOD(&definition, &session, "get", NULL, 0, &_4$$5);
				zephir_check_call_status();
				if (Z_TYPE_P(&definition) == IS_ARRAY) {
					if (zephir_array_isset_string_fetch(&expire, &definition, SL("expire"), 1)) {
						zephir_update_property_zval(this_ptr, SL("_expire"), &expire);
					}
					if (zephir_array_isset_string_fetch(&domain, &definition, SL("domain"), 1)) {
						zephir_update_property_zval(this_ptr, SL("_domain"), &domain);
					}
					if (zephir_array_isset_string_fetch(&path, &definition, SL("path"), 1)) {
						zephir_update_property_zval(this_ptr, SL("_path"), &path);
					}
					if (zephir_array_isset_string_fetch(&secure, &definition, SL("secure"), 1)) {
						zephir_update_property_zval(this_ptr, SL("_secure"), &secure);
					}
					if (zephir_array_isset_string_fetch(&httpOnly, &definition, SL("httpOnly"), 1)) {
						zephir_update_property_zval(this_ptr, SL("_httpOnly"), &httpOnly);
					}
				}
			}
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_restored"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_restored"), &__$false);
		}
	}
	RETURN_THIS();

}

/**
 * Deletes the cookie by setting an expire time in the past
 */
PHP_METHOD(Phalcon_Http_Cookie, delete) {

	zval __$null, name, domain, path, secure, httpOnly, dependencyInjector, session, _0, _4, _1$$3, _2$$3, _3$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&name);
	zephir_read_property(&name, this_ptr, SL("_name"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&domain);
	zephir_read_property(&domain, this_ptr, SL("_domain"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&path);
	zephir_read_property(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&secure);
	zephir_read_property(&secure, this_ptr, SL("_secure"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&httpOnly);
	zephir_read_property(&httpOnly, this_ptr, SL("_httpOnly"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "session");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_1$$3);
		ZEPHIR_CALL_METHOD(&_1$$3, &session, "isstarted", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_SV(&_3$$4, "_PHCOOKIE_", &name);
			ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_3$$4);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, SL("_value"), &__$null);
	ZEPHIR_INIT_VAR(&_4);
	zephir_time(&_4);
	ZVAL_LONG(&_0, (zephir_get_numberval(&_4) - 691200));
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 225, &name, &__$null, &_0, &path, &domain, &secure, &httpOnly);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 */
PHP_METHOD(Phalcon_Http_Cookie, useEncryption) {

	zval *useEncryption_param = NULL, __$true, __$false;
	zend_bool useEncryption;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &useEncryption_param);

	useEncryption = zephir_get_boolval(useEncryption_param);


	if (useEncryption) {
		zephir_update_property_zval(this_ptr, SL("_useEncryption"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_useEncryption"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Check if the cookie is using implicit encryption
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_useEncryption");

}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration) {

	zval *expire_param = NULL, _0, _1;
	int expire, ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expire_param);

	expire = zephir_get_intval(expire_param);


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, expire);
	zephir_update_property_zval(this_ptr, SL("_expire"), &_1);
	RETURN_THIS();

}

/**
 * Returns the current expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_expire");

}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0;
	zval path;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	if (unlikely(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_EMPTY_STRING(&path);
	}


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_path"), &path);
	RETURN_THIS();

}

/**
 * Returns the current cookie's name
 */
PHP_METHOD(Phalcon_Http_Cookie, getName) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_name");

}

/**
 * Returns the current cookie's path
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_path");

}

/**
 * Sets the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, setDomain) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL, _0;
	zval domain;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);

	if (unlikely(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(&domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_EMPTY_STRING(&domain);
	}


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_domain"), &domain);
	RETURN_THIS();

}

/**
 * Returns the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_domain");

}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *secure_param = NULL, __$true, __$false, _0;
	zend_bool secure;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &secure_param);

	secure = zephir_get_boolval(secure_param);


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (secure) {
		zephir_update_property_zval(this_ptr, SL("_secure"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_secure"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Returns whether the cookie must only be sent when the connection is secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_secure");

}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *httpOnly_param = NULL, __$true, __$false, _0;
	zend_bool httpOnly;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpOnly_param);

	httpOnly = zephir_get_boolval(httpOnly_param);


	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (httpOnly) {
		zephir_update_property_zval(this_ptr, SL("_httpOnly"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_httpOnly"), &__$false);
	}
	RETURN_THIS();

}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(this_ptr, "_httpOnly");

}

/**
 * Magic __toString method converts the cookie's value to string
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString) {

	zval _1;
	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(&_1, &_0);
	RETURN_CTOR(_1);

}

