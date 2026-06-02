
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("isRead"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_http_cookie_ce, SL("isRestored"), 0, ZEND_ACC_PROTECTED);
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
	zval name_zv, *value = NULL, value_sub, *expire_param = NULL, path_zv, *secure_param = NULL, domain_zv, *httpOnly_param = NULL, *options_param = NULL, __$true, __$false, __$null, _0;
	zend_string *name = NULL, *path = NULL, *domain = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&domain_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 8)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(value)
		Z_PARAM_LONG(expire)
		Z_PARAM_STR(path)
		Z_PARAM_BOOL(secure)
		Z_PARAM_STR(domain)
		Z_PARAM_BOOL(httpOnly)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		value = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		expire_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 4) {
		secure_param = ZEND_CALL_ARG(execute_data, 5);
	}
	if (ZEND_NUM_ARGS() > 6) {
		httpOnly_param = ZEND_CALL_ARG(execute_data, 7);
	}
	if (ZEND_NUM_ARGS() > 7) {
		options_param = ZEND_CALL_ARG(execute_data, 8);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!expire_param) {
		expire = 0;
	} else {
		}
	if (!path) {
		path = zend_string_init(ZEND_STRL("/"), 0);
		zephir_memory_observe(&path_zv);
		ZVAL_STR(&path_zv, path);
	} else {
		zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	}
	if (!secure_param) {
		secure = 0;
	} else {
		}
	if (!domain) {
		domain = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&domain_zv);
		ZVAL_STR(&domain_zv, domain);
	} else {
		zephir_memory_observe(&domain_zv);
	ZVAL_STR_COPY(&domain_zv, domain);
	}
	if (!httpOnly_param) {
		httpOnly = 0;
	} else {
		}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, expire);
	zephir_update_property_zval(this_ptr, ZEND_STRL("expire"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path_zv);
	if (secure) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("secure"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain_zv);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &options, &_8, &_0);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("expires"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "domain");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getarrval", NULL, 0, &options, &_8, &domain);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("domain"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "path");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getarrval", NULL, 0, &options, &_8, &path);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("path"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "secure");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "getarrval", NULL, 0, &options, &_8, &secure);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("secure"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "httponly");
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "getarrval", NULL, 0, &options, &_8, &httpOnly);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("httponly"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "");
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 0, &name, &_8, &options);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "domain", IS_STRING);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "expire", IS_LONG);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
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

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Returns the current cookie's options
 */
PHP_METHOD(Phalcon_Http_Cookie, getOptions)
{

	RETURN_MEMBER_TYPED(getThis(), "options", IS_ARRAY);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "path", IS_STRING);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
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
	zval *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, _COOKIE, __$null, container, value, crypt, decryptedValue, filter, signKey, name, _0, _1, _2$$4, _3$$6, _5$$6, _6$$6, _4$$7, _7$$8, _8$$12, _9$$14, _10$$15, _11$$13, _12$$13;
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
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(filters)
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&container);
	ZVAL_NULL(&container);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("isRead"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		zephir_memory_observe(&value);
		if (!(zephir_array_isset_fetch(&value, &_COOKIE, &name, 0))) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("useEncryption"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_2$$4)) {
			zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_3$$6);
			if (Z_TYPE_P(&container) == IS_NULL) {
				ZEPHIR_INIT_VAR(&_4$$7);
				object_init_ex(&_4$$7, phalcon_http_cookie_exceptions_cryptserviceunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$7, "phalcon/Http/Cookie.zep", 266);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_6$$6);
			ZVAL_STRING(&_6$$6, "crypt");
			ZEPHIR_CALL_METHOD(&_5$$6, &container, "getshared", NULL, 0, &_6$$6);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&crypt, &_5$$6);
			if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_7$$8);
				object_init_ex(&_7$$8, phalcon_http_cookie_exceptions_cryptinterfacerequired_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$8, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$8, "phalcon/Http/Cookie.zep", 272);
				ZEPHIR_MM_RESTORE();
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
			zephir_read_property(&_8$$12, this_ptr, ZEND_STRL("filter"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&filter, &_8$$12);
			if (Z_TYPE_P(&filter) != IS_OBJECT) {
				if (Z_TYPE_P(&container) == IS_NULL) {
					zephir_read_property(&_9$$14, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&container, &_9$$14);
					if (Z_TYPE_P(&container) == IS_NULL) {
						ZEPHIR_INIT_VAR(&_10$$15);
						object_init_ex(&_10$$15, phalcon_http_cookie_exceptions_filterserviceunavailable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_10$$15, "__construct", NULL, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$15, "phalcon/Http/Cookie.zep", 311);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_VAR(&_12$$13);
				ZVAL_STRING(&_12$$13, "filter");
				ZEPHIR_CALL_METHOD(&_11$$13, &container, "getshared", NULL, 0, &_12$$13);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filter, &_11$$13);
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
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
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRestored"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isRestored"), &__$false);
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
	zval _13$$8, _14$$9;
	zend_bool _2, _7;
	zval container, crypt, definition, encryptValue, expire, domain, httpOnly, name, options, path, secure, session, signKey, value, _0, _1, _3, _15, _16, _17, _18, _19, _4$$3, _5$$3, _6$$4, _8$$6, _9$$5, _10$$5, _12$$5, _11$$7;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	zephir_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("httpOnly"), &httpOnly, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("options"), &options, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 31, &definition);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&definition, &_1);
	_2 = !(ZEPHIR_IS_EMPTY(&definition));
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session");
		ZEPHIR_CALL_METHOD(&_1, &container, "has", NULL, 0, &_3);
		zephir_check_call_status();
		_2 = zephir_is_true(&_1);
	}
	if (_2) {
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
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_6$$4, &definition);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("useEncryption"), PH_NOISY_CC | PH_READONLY);
	_7 = zephir_is_true(&_0);
	if (_7) {
		_7 = !(ZEPHIR_IS_EMPTY(&value));
	}
	if (_7) {
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_8$$6);
			object_init_ex(&_8$$6, phalcon_http_cookie_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$6, "phalcon/Http/Cookie.zep", 444);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "crypt");
		ZEPHIR_CALL_METHOD(&_9$$5, &container, "getshared", NULL, 0, &_10$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&crypt, &_9$$5);
		if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_11$$7);
			object_init_ex(&_11$$7, phalcon_http_cookie_exceptions_cryptinterfacerequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_11$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_11$$7, "phalcon/Http/Cookie.zep", 450);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("signKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&signKey, &_12$$5);
		if (Z_TYPE_P(&signKey) == IS_STRING) {
			zephir_cast_to_string(&_13$$8, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_13$$8, &signKey);
			zephir_check_call_status();
		} else {
			zephir_cast_to_string(&_14$$9, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_14$$9);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&encryptValue, &value);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "expires");
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getarrval", NULL, 0, &options, &_3, &expire);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("expires"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "domain");
	ZEPHIR_CALL_METHOD(&_16, this_ptr, "getarrval", NULL, 0, &options, &_3, &domain);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("domain"), &_16, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "path");
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "getarrval", NULL, 0, &options, &_3, &path);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("path"), &_17, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "secure");
	ZEPHIR_CALL_METHOD(&_18, this_ptr, "getarrval", NULL, 0, &options, &_3, &secure);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("secure"), &_18, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "httponly");
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "getarrval", NULL, 0, &options, &_3, &httpOnly);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("httponly"), &_19, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 0, &name, &encryptValue, &options);
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
	zval domain_zv, _0;
	zend_string *domain = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(domain)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&domain_zv);
	ZVAL_STR_COPY(&domain_zv, domain);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("domain"), &domain_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(expire)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expire_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_UNDEF(&_1);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(httpOnly)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &httpOnly_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zval path_zv, _0;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("path"), &path_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(secure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &secure_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("isRestored"), PH_NOISY_CC | PH_READONLY);
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
 * @see \Phalcon\Encryption\Security\Random
 * @throws \Phalcon\Http\Cookie\Exception
 */
PHP_METHOD(Phalcon_Http_Cookie, setSignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval signKey_zv;
	zend_string *signKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signKey_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(signKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!signKey) {
		ZEPHIR_INIT_VAR(&signKey_zv);
	} else {
		zephir_memory_observe(&signKey_zv);
	ZVAL_STR_COPY(&signKey_zv, signKey);
	}
	if (!ZEPHIR_IS_NULL(&signKey_zv)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertsignkeyislongenough", NULL, 0, &signKey_zv);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("signKey"), &signKey_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isRead"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isRead"), &__$false);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(useEncryption)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &useEncryption_param);
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
	zval signKey_zv, length, _0$$3;
	zend_string *signKey = NULL;

	ZVAL_UNDEF(&signKey_zv);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(signKey)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&signKey_zv);
	ZVAL_STR_COPY(&signKey_zv, signKey);
	ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 464, &signKey_zv);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_LT_LONG(&length, 32))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_cookie_exceptions_cookiekeytooshort_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &length);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Cookie.zep", 624);
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

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Http_Cookie(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

