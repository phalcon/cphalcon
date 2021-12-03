
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Provide OO wrappers to manage a HTTP cookie.
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http, Cookie, phalcon, http_cookie, phalcon_di_abstractinjectionaware_ce, phalcon_http_cookie_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("domain"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("expire"), ZEND_ACC_PROTECTED);
	/**
	 * @var FilterInterface|null
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("filter"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("httpOnly"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("path"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("read"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("restored"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("secure"), 1, ZEND_ACC_PROTECTED);
	/**
	 * The cookie's sign key.
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("signKey"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("useEncryption"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("value"), ZEND_ACC_PROTECTED);
	phalcon_http_cookie_ce->create_object = zephir_init_properties_Phalcon_Http_Cookie;

	zend_class_implements(phalcon_http_cookie_ce, 1, phalcon_http_cookie_cookieinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Http\Cookie constructor.
 */
PHP_METHOD(Phalcon_Http_Cookie, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zend_bool secure, httpOnly;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, *expire_param = NULL, *path_param = NULL, *secure_param = NULL, *domain_param = NULL, *httpOnly_param = NULL, *options_param = NULL, __$true, __$false, __$null, _0;
	zval name, path, domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 8)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_LONG(expire)
		Z_PARAM_STR(path)
		Z_PARAM_BOOL_OR_NULL(secure, is_null_true)
		Z_PARAM_STR_OR_NULL(domain)
		Z_PARAM_BOOL_OR_NULL(httpOnly, is_null_true)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 7, &name_param, &value, &expire_param, &path_param, &secure_param, &domain_param, &httpOnly_param, &options_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
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
	} else {
		zephir_get_strval(&domain, domain_param);
	}
	if (!httpOnly_param) {
		httpOnly = 0;
	} else {
		httpOnly = zephir_get_boolval(httpOnly_param);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, expire);
	zephir_update_property_zval(this_ptr, ZEND_STRL("expire"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	if (secure) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain);
	if (httpOnly) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	if (Z_TYPE_P(value) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", NULL, 0, value);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic __toString method converts the cookie's value to string
 */
PHP_METHOD(Phalcon_Http_Cookie, __toString)
{
	zval _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	RETURN_CTOR(&_1);
}

/**
 * Deletes the cookie by setting an expire time in the past
 */
PHP_METHOD(Phalcon_Http_Cookie, delete)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, container, domain, httpOnly, name, options, path, secure, session, _0, _2, _3, _7, _8, _9, _10, _11, _12, _4$$3, _5$$3, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&domain, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&path, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("secure"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&secure, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&httpOnly, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	_1 = Z_TYPE_P(&container) == IS_OBJECT;
	if (_1) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session");
		ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "session");
		ZEPHIR_CALL_METHOD(&_4$$3, &container, "getshared", NULL, 0, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_4$$3);
		ZEPHIR_CALL_METHOD(&_4$$3, &session, "exists", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZEPHIR_CONCAT_SV(&_6$$4, "_PHCOOKIE_", &name);
			ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_6$$4);
			zephir_check_call_status();
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &__$null);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_time(&_3);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "expires");
	ZVAL_LONG(&_0, (zephir_get_numberval(&_3) - 691200));
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 351, &options, &_8, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("expires"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "domain");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getarrval", NULL, 351, &options, &_8, &domain);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("domain"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "path");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 351, &options, &_8, &path);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("path"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "secure");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getarrval", NULL, 351, &options, &_8, &secure);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("secure"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "httponly");
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getarrval", NULL, 351, &options, &_8, &httpOnly);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("httponly"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 352, &name, &__$null, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "domain");
}

/**
 * Returns the current expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "expire");
}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "httpOnly");
}

/**
 * Returns the current cookie's name
 */
PHP_METHOD(Phalcon_Http_Cookie, getName)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "name");
}

/**
 * Returns the current cookie's options
 */
PHP_METHOD(Phalcon_Http_Cookie, getOptions)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "options");
}

/**
 * Returns the current cookie's path
 */
PHP_METHOD(Phalcon_Http_Cookie, getPath)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "path");
}

/**
 * Returns whether the cookie must only be sent when the connection is
 * secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER(getThis(), "secure");
}

/**
 * Returns the cookie's value.
 */
PHP_METHOD(Phalcon_Http_Cookie, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, _COOKIE, __$null, container, value, crypt, decryptedValue, filter, signKey, name, _0, _1, _2$$4, _3$$6, _4$$6, _5$$6, _6$$12, _7$$14, _8$$13, _9$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filters_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&crypt);
	ZVAL_UNDEF(&decryptedValue);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&signKey);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&container);
	ZVAL_NULL(&container);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("read"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_OBS_VAR(&value);
		if (!(zephir_array_isset_fetch(&value, &_COOKIE, &name, 0))) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("useEncryption"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_2$$4)) {
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_3$$6);
			if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection container is required to access the 'filter' and 'crypt' services", "phalcon/Http/Cookie.zep", 265);
				return;
			}
			ZEPHIR_INIT_VAR(&_5$$6);
			ZVAL_STRING(&_5$$6, "crypt");
			ZEPHIR_CALL_METHOD(&_4$$6, &container, "getshared", NULL, 0, &_5$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&crypt, &_4$$6);
			if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency which implements CryptInterface is required to use encryption", "phalcon/Http/Cookie.zep", 273);
				return;
			}
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("signKey"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&signKey, &_3$$6);
			if (Z_TYPE_P(&signKey) == IS_STRING) {
				ZEPHIR_CALL_METHOD(&decryptedValue, &crypt, "decryptbase64", NULL, 0, &value, &signKey);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&decryptedValue, &crypt, "decryptbase64", NULL, 0, &value);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CPY_WRT(&decryptedValue, &value);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &decryptedValue);
		if (Z_TYPE_P(filters) != IS_NULL) {
			zephir_read_property(&_6$$12, this_ptr, ZEND_STRL("filter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&filter, &_6$$12);
			if (Z_TYPE_P(&filter) != IS_OBJECT) {
				if (Z_TYPE_P(&container) == IS_NULL) {
					zephir_read_property(&_7$$14, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&container, &_7$$14);
					if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection container is required to access the 'filter' service", "phalcon/Http/Cookie.zep", 314);
						return;
					}
				}
				ZEPHIR_INIT_VAR(&_9$$13);
				ZVAL_STRING(&_9$$13, "filter");
				ZEPHIR_CALL_METHOD(&_8$$13, &container, "getshared", NULL, 0, &_9$$13);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filter, &_8$$13);
				zephir_update_property_zval(this_ptr, ZEND_STRL("filter"), &filter);
			}
			ZEPHIR_RETURN_CALL_METHOD(&filter, "sanitize", NULL, 0, &decryptedValue, filters);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&decryptedValue);
	}
	RETURN_MM_MEMBER(getThis(), "value");
}

/**
 * Check if the cookie is using implicit encryption
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "useEncryption");
}

/**
 * Reads the cookie-related info from the SESSION to restore the cookie as
 * it was set.
 *
 * This method is automatically called internally so normally you don't
 * need to call it.
 */
PHP_METHOD(Phalcon_Http_Cookie, restore)
{
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, container, definition, domain, expire, httpOnly, options, path, secure, session, _0, _1$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$5, _8$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		_2$$3 = Z_TYPE_P(&container) == IS_OBJECT;
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_STRING(&_4$$3, "session");
			ZEPHIR_CALL_METHOD(&_3$$3, &container, "has", NULL, 0, &_4$$3);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_3$$3);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "session");
			ZEPHIR_CALL_METHOD(&session, &container, "getshared", NULL, 0, &_5$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$4, &session, "exists", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$4)) {
				zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_8$$5);
				ZEPHIR_CONCAT_SV(&_8$$5, "_PHCOOKIE_", &_7$$5);
				ZEPHIR_CALL_METHOD(&definition, &session, "get", NULL, 0, &_8$$5);
				zephir_check_call_status();
				if (zephir_array_isset_string_fetch(&expire, &definition, SL("expire"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("expire"), &expire);
				}
				if (zephir_array_isset_string_fetch(&domain, &definition, SL("domain"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain);
				}
				if (zephir_array_isset_string_fetch(&path, &definition, SL("path"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
				}
				if (zephir_array_isset_string_fetch(&secure, &definition, SL("secure"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &secure);
				}
				if (zephir_array_isset_string_fetch(&httpOnly, &definition, SL("httpOnly"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &httpOnly);
				}
				if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 1)) {
					zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
				}
			}
		}
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("restored"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("restored"), &__$false);
		}
	}
	RETURN_THIS();
}

/**
 * Sends the cookie to the HTTP client.
 *
 * Stores the cookie definition in session.
 */
PHP_METHOD(Phalcon_Http_Cookie, send)
{
	zval _11$$14, _12$$15;
	zend_bool _1, _7;
	zval container, crypt, definition, encryptValue, expire, domain, httpOnly, name, options, path, secure, session, signKey, value, _0, _2, _3, _13, _14, _15, _16, _17, _4$$9, _5$$9, _6$$10, _8$$11, _9$$11, _10$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&crypt);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&encryptValue);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&signKey);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$15);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("value"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&value, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("expire"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&expire, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("domain"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&domain, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&path, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("secure"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&secure, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("httpOnly"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&httpOnly, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
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
	if (!(ZEPHIR_IS_EMPTY(&options))) {
		zephir_array_update_string(&definition, SL("options"), &options, PH_COPY | PH_SEPARATE);
	}
	_1 = ((zephir_fast_count_int(&definition)) ? 1 : 0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session");
		ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_5$$9);
		ZVAL_STRING(&_5$$9, "session");
		ZEPHIR_CALL_METHOD(&_4$$9, &container, "getshared", NULL, 0, &_5$$9);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&session, &_4$$9);
		ZEPHIR_CALL_METHOD(&_4$$9, &session, "exists", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$9)) {
			ZEPHIR_INIT_VAR(&_6$$10);
			ZEPHIR_CONCAT_SV(&_6$$10, "_PHCOOKIE_", &name);
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_6$$10, &definition);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("useEncryption"), PH_NOISY_CC | PH_READONLY);
	_7 = zephir_is_true(&_0);
	if (_7) {
		_7 = !(ZEPHIR_IS_EMPTY(&value));
	}
	if (_7) {
		if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency injection container is required to access the 'filter' service", "phalcon/Http/Cookie.zep", 462);
			return;
		}
		ZEPHIR_INIT_VAR(&_9$$11);
		ZVAL_STRING(&_9$$11, "crypt");
		ZEPHIR_CALL_METHOD(&_8$$11, &container, "getshared", NULL, 0, &_9$$11);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&crypt, &_8$$11);
		if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_http_response_exception_ce, "A dependency which implements CryptInterface is required to use encryption", "phalcon/Http/Cookie.zep", 470);
			return;
		}
		zephir_read_property(&_10$$11, this_ptr, ZEND_STRL("signKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&signKey, &_10$$11);
		if (Z_TYPE_P(&signKey) == IS_STRING) {
			zephir_cast_to_string(&_11$$14, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_11$$14, &signKey);
			zephir_check_call_status();
		} else {
			zephir_cast_to_string(&_12$$15, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_12$$15);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&encryptValue, &value);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "expires");
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "getarrval", NULL, 351, &options, &_3, &expire);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("expires"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "domain");
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getarrval", NULL, 351, &options, &_3, &domain);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("domain"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "path");
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getarrval", NULL, 351, &options, &_3, &path);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("path"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "secure");
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getarrval", NULL, 351, &options, &_3, &secure);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("secure"), &_16, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "httponly");
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "getarrval", NULL, 351, &options, &_3, &httpOnly);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("httponly"), &_17, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 352, &name, &encryptValue, &options);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, setDomain)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *domain_param = NULL, _0;
	zval domain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(domain)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &domain_param);
	if (UNEXPECTED(Z_TYPE_P(domain_param) != IS_STRING && Z_TYPE_P(domain_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'domain' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(domain_param) == IS_STRING)) {
		zephir_get_strval(&domain, domain_param);
	} else {
		ZEPHIR_INIT_VAR(&domain);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain);
	RETURN_THIS();
}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *expire_param = NULL, _0, _1;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(expire)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expire_param);
	expire = zephir_get_intval(expire_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, expire);
	zephir_update_property_zval(this_ptr, ZEND_STRL("expire"), &_1);
	RETURN_THIS();
}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpOnly_param = NULL, __$true, __$false, _0;
	zend_bool httpOnly;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(httpOnly)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &httpOnly_param);
	httpOnly = zephir_get_boolval(httpOnly_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (httpOnly) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("httpOnly"), &__$false);
	}
	RETURN_THIS();
}

/**
 * Sets the cookie's options
 */
PHP_METHOD(Phalcon_Http_Cookie, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	RETURN_THIS();
}

/**
 * Sets the cookie's path
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);
	if (UNEXPECTED(Z_TYPE_P(path_param) != IS_STRING && Z_TYPE_P(path_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'path' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(path_param) == IS_STRING)) {
		zephir_get_strval(&path, path_param);
	} else {
		ZEPHIR_INIT_VAR(&path);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path);
	RETURN_THIS();
}

/**
 * Sets if the cookie must only be sent when the connection is secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *secure_param = NULL, __$true, __$false, _0;
	zend_bool secure;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(secure)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &secure_param);
	secure = zephir_get_boolval(secure_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("restored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	if (secure) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$false);
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
 * @throws \Phalcon\Http\Cookie\Exception
 */
PHP_METHOD(Phalcon_Http_Cookie, setSignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *signKey_param = NULL;
	zval signKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signKey);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(signKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &signKey_param);
	if (!signKey_param) {
		ZEPHIR_INIT_VAR(&signKey);
	} else {
		zephir_get_strval(&signKey, signKey_param);
	}


	if (!ZEPHIR_IS_NULL(&signKey)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertsignkeyislongenough", NULL, 0, &signKey);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("signKey"), &signKey);
	RETURN_THIS();
}

/**
 * Sets the cookie's value
 *
 * @param string value
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue)
{
	zval *value, value_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &value);


	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("read"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("read"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets if the cookie must be encrypted/decrypted automatically
 */
PHP_METHOD(Phalcon_Http_Cookie, useEncryption)
{
	zval *useEncryption_param = NULL, __$true, __$false;
	zend_bool useEncryption;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(useEncryption)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &useEncryption_param);
	useEncryption = zephir_get_boolval(useEncryption_param);


	if (useEncryption) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("useEncryption"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("useEncryption"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Assert the cookie's key is enough long.
 *
 * @throws \Phalcon\Http\Cookie\Exception
 */
PHP_METHOD(Phalcon_Http_Cookie, assertSignKeyIsLongEnough)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *signKey_param = NULL, length, _0$$3, _1$$3, _2$$3;
	zval signKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signKey);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(signKey)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &signKey_param);
	if (UNEXPECTED(Z_TYPE_P(signKey_param) != IS_STRING && Z_TYPE_P(signKey_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'signKey' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(signKey_param) == IS_STRING)) {
		zephir_get_strval(&signKey, signKey_param);
	} else {
		ZEPHIR_INIT_VAR(&signKey);
	}


	ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 252, &signKey);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_LT_LONG(&length, 32))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_cookie_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "The cookie's key should be at least 32 characters long. Current length is %d.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 141, &_1$$3, &length);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 30, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Cookie.zep", 649);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Http_Cookie, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 1)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Http_Cookie(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

