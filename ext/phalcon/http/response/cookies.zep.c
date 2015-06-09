
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
#include "kernel/hash.h"


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
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
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

	int expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, *expire_param = NULL, *path_param = NULL, *secure = NULL, *domain_param = NULL, *httpOnly = NULL, *cookie = NULL, *encryption, *dependencyInjector, *response = NULL, *_0, *_1 = NULL, *_2;
	zval *name = NULL, *path = NULL, *domain = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire_param, &path_param, &secure, &domain_param, &httpOnly);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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
	if (!secure) {
		secure = ZEPHIR_GLOBAL(global_null);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	} else {
	if (unlikely(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(domain);
		ZVAL_EMPTY_STRING(domain);
	}
	}
	if (!httpOnly) {
		httpOnly = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(encryption);
	zephir_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(cookie);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&cookie, _0, name, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(cookie);
		object_init_ex(cookie, phalcon_http_cookie_ce);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, expire);
		ZEPHIR_CALL_METHOD(NULL, cookie, "__construct", NULL, 215, name, value, _1, path, secure, domain, httpOnly);
		zephir_check_call_status();
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdi", NULL, 216, _2);
		zephir_check_call_status();
		if (zephir_is_true(encryption)) {
			ZEPHIR_CALL_METHOD(NULL, cookie, "useencryption", NULL, 217, encryption);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, cookie, "setvalue", NULL, 218, value);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, expire);
		ZEPHIR_CALL_METHOD(NULL, cookie, "setexpiration", NULL, 219, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "setpath", NULL, 220, path);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "setsecure", NULL, 221, secure);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdomain", NULL, 222, domain);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, cookie, "sethttponly", NULL, 223, httpOnly);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_registered"), PH_NOISY_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		ZEPHIR_OBS_VAR(dependencyInjector);
		zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_cookie_exception_ce, "A dependency injection object is required to access the 'response' service", "phalcon/http/response/cookies.zep", 138);
			return;
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "response", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&response, dependencyInjector, "getshared", NULL, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "setcookies", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Gets a cookie from the bag
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *dependencyInjector, *encryption, *cookie = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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
	ZEPHIR_INIT_NVAR(cookie);
	object_init_ex(cookie, phalcon_http_cookie_ce);
	ZEPHIR_CALL_METHOD(NULL, cookie, "__construct", NULL, 215, name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, cookie, "setdi", NULL, 216, dependencyInjector);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(encryption);
		zephir_read_property_this(&encryption, this_ptr, SL("_useEncryption"), PH_NOISY_CC);
		if (zephir_is_true(encryption)) {
			ZEPHIR_CALL_METHOD(NULL, cookie, "useencryption", NULL, 217, encryption);
			zephir_check_call_status();
		}
	}
	zephir_update_property_array(this_ptr, SL("_cookies"), name, cookie TSRMLS_CC);
	RETURN_CCTOR(cookie);

}

/**
 * Check if a cookie is defined in the bag or exists in the _COOKIE superglobal
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, has) {

	zval *name_param = NULL, *_0, *_COOKIE;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SS("_COOKIE") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *cookie, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
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

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cookie = NULL, *_0 = NULL, *_1, **_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 224);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_cookies"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/http/response/cookies.zep", 243);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(cookie, _4);
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
	zephir_update_property_this(this_ptr, SL("_cookies"), _0 TSRMLS_CC);
	RETURN_THIS();

}

