
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Http\Response\Cookies
 *
 * This class is a bag to manage the cookies.
 *
 * A cookies bag is automatically registered as part of the 'response' service
 * in the DI. By default, cookies are automatically encrypted before being sent
 * to the client and are decrypted when retrieved from the user. To set sign key
 * used to generate a message authentication code use
 * `Phalcon\Http\Response\Cookies::setSignKey()`.
 *
 * ```php
 * use Phalcon\Di;
 * use Phalcon\Crypt;
 * use Phalcon\Http\Response\Cookies;
 *
 * $di = new Di();
 *
 * $di->set(
 *     'crypt',
 *     function () {
 *         $crypt = new Crypt();
 *
 *         // The `$key' should have been previously generated in a cryptographically safe way.
 *         $key = "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3";
 *
 *         $crypt->setKey($key);
 *
 *         return $crypt;
 *     }
 * );
 *
 * $di->set(
 *     'cookies',
 *     function () {
 *         $cookies = new Cookies();
 *
 *         // The `$key' MUST be at least 32 characters long and generated using a
 *         // cryptographically secure pseudo random generator.
 *         $key = "#1dj8$=dp?.ak//j1V$~%*0XaK\xb1\x8d\xa9\x98\x054t7w!z%C*F-Jk\x98\x05\\\x5c";
 *
 *         $cookies->setSignKey($key);
 *
 *         return $cookies;
 *     }
 * );
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Cookies) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http\\Response, Cookies, phalcon, http_response_cookies, phalcon_di_abstractinjectionaware_ce, phalcon_http_response_cookies_method_entry, 0);

	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("cookies"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("registered"), 0, ZEND_ACC_PROTECTED);

	/**
	 * The cookie's sign key.
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_http_response_cookies_ce, SL("signKey"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalcon_http_response_cookies_ce, SL("useEncryption"), 1, ZEND_ACC_PROTECTED);

	phalcon_http_response_cookies_ce->create_object = zephir_init_properties_Phalcon_Http_Response_Cookies;

	zend_class_implements(phalcon_http_response_cookies_ce, 1, phalcon_http_response_cookiesinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Http\Response\Cookies constructor
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval signKey;
	zval *useEncryption_param = NULL, *signKey_param = NULL, __$true, __$false;
	zend_bool useEncryption;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&signKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &useEncryption_param, &signKey_param);

	if (!useEncryption_param) {
		useEncryption = 1;
	} else {
		useEncryption = zephir_get_boolval(useEncryption_param);
	}
	if (!signKey_param) {
		ZEPHIR_INIT_VAR(&signKey);
		ZVAL_STRING(&signKey, "");
	} else {
		zephir_get_strval(&signKey, signKey_param);
	}


	if (useEncryption) {
		zephir_update_property_zval(this_ptr, SL("useEncryption"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("useEncryption"), &__$false);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsignkey", NULL, 0, &signKey);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Deletes a cookie by its name
 * This method does not removes cookies from the _COOKIE superglobal
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, delete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, cookie, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&cookie);
	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&cookie, &_0, &name, 0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, &cookie, "delete", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Gets a cookie from the bag
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, get) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, container, encryption, cookie, _0, _1, _2, _4, _5, _6$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&encryption);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	ZEPHIR_OBS_VAR(&cookie);
	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&cookie, &_0, &name, 0)) {
		RETURN_CCTOR(&cookie);
	}
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_fast_append(&_3, &name);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Http\\Cookie");
	ZEPHIR_CALL_METHOD(&_2, &_1, "get", NULL, 0, &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&cookie, &_2);
	zephir_read_property(&_5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_5);
	if (Z_TYPE_P(&container) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setdi", NULL, 0, &container);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&encryption);
		zephir_read_property(&encryption, this_ptr, SL("useEncryption"), PH_NOISY_CC);
		if (zephir_is_true(&encryption)) {
			ZEPHIR_CALL_METHOD(NULL, &cookie, "useencryption", NULL, 0, &encryption);
			zephir_check_call_status();
			zephir_read_property(&_6$$5, this_ptr, SL("signKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &cookie, "setsignkey", NULL, 0, &_6$$5);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&cookie);

}

/**
 * Gets all cookies from the bag
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

/**
 * Check if a cookie is defined in the bag or exists in the _COOKIE
 * superglobal
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, has) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, _COOKIE, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, &name);
	if (!(_1)) {
		_1 = zephir_array_isset(&_COOKIE, &name);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Returns if the bag is automatically encrypting/decrypting cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "useEncryption");

}

/**
 * Reset set cookies
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, reset) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("cookies"), &_0);
	RETURN_THIS();

}

/**
 * Sends the cookies to the client
 * Cookies aren't sent if headers are sent in the current request
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, send) {

	zval cookie, _0, _1, *_2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 354);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Http/Response/Cookies.zep", 203);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&cookie);
			ZVAL_COPY(&cookie, _2);
			ZEPHIR_CALL_METHOD(NULL, &cookie, "send", NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cookie, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &cookie, "send", NULL, 0);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cookie);
	RETURN_MM_BOOL(1);

}

/**
 * Sets a cookie to be sent at the end of the request.
 *
 * This method overrides any cookie set before with the same name.
 *
 * ```php
 * use Phalcon\Http\Response\Cookies;
 *
 * $now = new DateTimeImmutable();
 * $tomorrow = $now->modify('tomorrow');
 *
 * $cookies = new Cookies();
 * $cookies->set(
 *     'remember-me',
 *     json_encode(['user_id' => 1]),
 *     (int) $tomorrow->format('U'),
 * );
 * ```
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, set) {

	zval _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_bool secure, httpOnly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, *expire_param = NULL, *path_param = NULL, *secure_param = NULL, *domain_param = NULL, *httpOnly_param = NULL, __$true, __$false, __$null, cookie, encryption, container, response, _0, _10, _1$$3, _2$$3, _4$$3, _5$$3, _6$$4, _7$$5, _8$$5, _9$$5, _11$$6, _16$$6, _12$$7, _13$$7, _15$$7;
	zval name, path, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&encryption);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 6, &name_param, &value, &expire_param, &path_param, &secure_param, &domain_param, &httpOnly_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!expire_param) {
		expire = 0;
	} else {
		expire = zephir_get_intval(expire_param);
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "/");
	} else {
		zephir_get_strval(&path, path_param);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		secure = zephir_get_boolval(secure_param);
	}
	if (!domain_param) {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_STRING(&domain, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(&domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(&domain);
		ZVAL_EMPTY_STRING(&domain);
	}
	}
	if (!httpOnly_param) {
		httpOnly = 0;
	} else {
		httpOnly = zephir_get_boolval(httpOnly_param);
	}


	ZEPHIR_OBS_VAR(&encryption);
	zephir_read_property(&encryption, this_ptr, SL("useEncryption"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&cookie);
	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&cookie, &_0, &name, 0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 7, 0);
		zephir_array_fast_append(&_3$$3, &name);
		zephir_array_fast_append(&_3$$3, value);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_LONG(&_4$$3, expire);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_array_fast_append(&_3$$3, &path);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_BOOL(&_4$$3, secure);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		zephir_array_fast_append(&_3$$3, &domain);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_BOOL(&_4$$3, httpOnly);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Phalcon\\Http\\Cookie");
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "get", NULL, 0, &_4$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&cookie, &_2$$3);
		zephir_read_property(&_5$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setdi", NULL, 0, &_5$$3);
		zephir_check_call_status();
		if (zephir_is_true(&encryption)) {
			ZEPHIR_CALL_METHOD(NULL, &cookie, "useencryption", NULL, 0, &encryption);
			zephir_check_call_status();
			zephir_read_property(&_6$$4, this_ptr, SL("signKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &cookie, "setsignkey", NULL, 0, &_6$$4);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("cookies"), &name, &cookie);
	} else {
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setvalue", NULL, 0, value);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$5, expire);
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setexpiration", NULL, 0, &_7$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setpath", NULL, 0, &path);
		zephir_check_call_status();
		if (secure) {
			ZVAL_BOOL(&_7$$5, 1);
		} else {
			ZVAL_BOOL(&_7$$5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setsecure", NULL, 0, &_7$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setdomain", NULL, 0, &domain);
		zephir_check_call_status();
		if (httpOnly) {
			ZVAL_BOOL(&_8$$5, 1);
		} else {
			ZVAL_BOOL(&_8$$5, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, &cookie, "sethttponly", NULL, 0, &_8$$5);
		zephir_check_call_status();
		zephir_read_property(&_9$$5, this_ptr, SL("signKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &cookie, "setsignkey", NULL, 0, &_9$$5);
		zephir_check_call_status();
	}
	zephir_read_property(&_10, this_ptr, SL("registered"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_10)) {
		zephir_read_property(&_11$$6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_11$$6);
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_12$$7);
			object_init_ex(&_12$$7, phalcon_http_cookie_exception_ce);
			ZEPHIR_INIT_VAR(&_15$$7);
			ZVAL_STRING(&_15$$7, "the 'response' service");
			ZEPHIR_CALL_CE_STATIC(&_13$$7, phalcon_http_cookie_exception_ce, "containerservicenotfound", &_14, 0, &_15$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", NULL, 6, &_13$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_12$$7, "phalcon/Http/Response/Cookies.zep", 287);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_16$$6);
		ZVAL_STRING(&_16$$6, "response");
		ZEPHIR_CALL_METHOD(&response, &container, "getshared", NULL, 0, &_16$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &response, "setcookies", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (1) {
			zephir_update_property_zval(this_ptr, SL("registered"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("registered"), &__$false);
		}
	}
	RETURN_THIS();

}

/**
 * Sets the cookie's sign key.
 *
 * The `$signKey' MUST be at least 32 characters long
 * and generated using a cryptographically secure pseudo random generator.
 *
 * Use NULL to disable cookie signing.
 *
 * @see \Phalcon\Security\Random
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, setSignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *signKey_param = NULL;
	zval signKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signKey);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &signKey_param);

	if (!signKey_param) {
		ZEPHIR_INIT_VAR(&signKey);
		ZVAL_STRING(&signKey, "");
	} else {
		zephir_get_strval(&signKey, signKey_param);
	}


	zephir_update_property_zval(this_ptr, SL("signKey"), &signKey);
	RETURN_THIS();

}

/**
 * Set if cookies in the bag must be automatically encrypted/decrypted
 */
PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption) {

	zval *useEncryption_param = NULL, __$true, __$false;
	zend_bool useEncryption;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params_without_memory_grow(1, 0, &useEncryption_param);

	useEncryption = zephir_get_boolval(useEncryption_param);


	if (useEncryption) {
		zephir_update_property_zval(this_ptr, SL("useEncryption"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("useEncryption"), &__$false);
	}
	RETURN_THISW();

}

zend_object *zephir_init_properties_Phalcon_Http_Response_Cookies(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("cookies"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

