
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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

PHP_METHOD(Phalcon_Http_Response_Cookies, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_cookies"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption) {

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
 * Returns if the bag is automatically encrypting/decrypting cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption) {

	

	RETURN_MEMBER(getThis(), "_useEncryption");

}

/**
 * Sets a cookie to be sent at the end of the request
 * This method overrides any cookie set before with the same name
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set) {

	zval *_3$$3;
	zend_bool secure, httpOnly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *expire_param = NULL, *path_param = NULL, *secure_param = NULL, *domain_param = NULL, *httpOnly_param = NULL, *cookie = NULL, *encryption = NULL, *dependencyInjector = NULL, *response = NULL, *_0, *_8, *_1$$3, *_2$$3 = NULL, *_4$$3 = NULL, *_5$$3, *_6$$5 = NULL, *_7$$5, *_9$$6;
	zval *name = NULL, *path = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire_param, &path_param, &secure_param, &domain_param, &httpOnly_param);

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
	if (!expire_param) {
		expire = 0;
	} else {
		expire = zephir_get_intval(expire_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "/", 1);
	} else {
		zephir_get_strval(path, path_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
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
	}
	if (!httpOnly_param) {
		httpOnly = 0;
	} else {
		httpOnly = zephir_get_boolval(httpOnly_param);
	}


	ZEPHIR_OBS_VAR(encryption);
	zephir_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_create_array(_3$$3, 7, 0 TSRMLS_CC);
		zephir_array_fast_append(_3$$3, name);
		zephir_array_fast_append(_3$$3, value);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, expire);
		zephir_array_fast_append(_3$$3, _4$$3);
		zephir_array_fast_append(_3$$3, path);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_BOOL(_4$$3, secure);
		zephir_array_fast_append(_3$$3, _4$$3);
		zephir_array_fast_append(_3$$3, domain);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_BOOL(_4$$3, httpOnly);
		zephir_array_fast_append(_3$$3, _4$$3);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_STRING(_4$$3, "Phalcon\\Http\\Cookie", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$3, _1$$3, "get", NULL, 0, _4$$3, _3$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(cookie, _2$$3);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdi", NULL, 0, _5$$3);
		zephir_check_call_status();
		if (zephir_is_true(encryption)) {
			ZEPHIR_CALL_METHOD(NULL, cookie, "useencryption", NULL, 0, encryption);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, cookie, "setvalue", NULL, 0, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$5);
		ZVAL_LONG(_6$$5, expire);
		ZEPHIR_CALL_METHOD(NULL, cookie, "setexpiration", NULL, 0, _6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "setpath", NULL, 0, path);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_6$$5);
		if (secure) {
			ZVAL_BOOL(_6$$5, 1);
		} else {
			ZVAL_BOOL(_6$$5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, cookie, "setsecure", NULL, 0, _6$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdomain", NULL, 0, domain);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$5);
		if (httpOnly) {
			ZVAL_BOOL(_7$$5, 1);
		} else {
			ZVAL_BOOL(_7$$5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, cookie, "sethttponly", NULL, 0, _7$$5);
		zephir_check_call_status();
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'response' service", "phalcon/http/response/cookies.zep", 135);
			return;
		}
		ZEPHIR_INIT_VAR(_9$$6);
		ZVAL_STRING(_9$$6, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&response, dependencyInjector, "getshared", NULL, 0, _9$$6);
		zephir_check_temp_parameter(_9$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "setcookies", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_registered"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Gets a cookie from the bag
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get) {

	zval *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dependencyInjector = NULL, *encryption = NULL, *cookie = NULL, *_0, *_1, *_2 = NULL, *_4;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(cookie);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, name);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Cookie", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, _1, "get", NULL, 0, _4, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(cookie, _2);
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdi", NULL, 0, dependencyInjector);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(encryption);
		zephir_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
		if (zephir_is_true(encryption)) {
			ZEPHIR_CALL_METHOD(NULL, cookie, "useencryption", NULL, 0, encryption);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(cookie);

}

/**
 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, has) {

	zval *name_param = NULL, *_COOKIE, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset(_0, name)) {
		RETURN_MM_BOOL(1);
	}
	if (zephir_array_isset(_COOKIE, name)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the _COOKIE superglobal
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *cookie = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, cookie, "delete", NULL, 0);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sends the cookies to the client
 * Cookies aren't sent if headers are sent in the current request
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, send) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zval *cookie = NULL, *_0 = NULL, *_1$$3, **_4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 28);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "phalcon/http/response/cookies.zep", 247);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(cookie, _4$$3);
			ZEPHIR_CALL_METHOD(NULL, cookie, "send", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reset set cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_cookies"), _0 TSRMLS_CC);
	RETURN_THIS();

}

