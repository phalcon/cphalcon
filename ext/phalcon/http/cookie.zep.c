
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
#include "kernel/time.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
 *
 * @phpstan-import-type http_cookie_definition from HttpTypes
 * @phpstan-import-type http_cookie_options from HttpTypes
 * @phpstan-import-type http_setcookie_options from HttpTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Http, Cookie, phalcon, http_cookie, phalcon_di_abstractinjectionaware_ce, phalcon_http_cookie_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("domain"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("expire"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("filter"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Filter\\FilterInterface"));
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("httpOnly"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("name"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "/", sizeof("/") - 1);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("path"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("isRead"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("isRestored"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("secure"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	/**
	 * The cookie's sign key.
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("signKey"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING|MAY_BE_NULL, NULL, 0);
	}

	/**
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_http_cookie_ce, SL("value"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_http_cookie_ce, SL("useEncryption"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	zend_class_implements(phalcon_http_cookie_ce, 1, phalcon_http_cookie_cookieinterface_ce);
	zend_class_implements(phalcon_http_cookie_ce, 1, zend_ce_stringable);
	return SUCCESS;
}

/**
 * Phalcon\Http\Cookie constructor.
 *
 * @phpstan-param http_cookie_options $options
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("expire", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("httpOnly", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("options", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 862, &name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, expire);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 863, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 864, &path_zv);
	if (secure) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 865, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 865, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 866, &domain_zv);
	if (httpOnly) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 867, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 867, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 868, &options);
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
 * Deletes the cookie by setting an expiration time in the past
 */
PHP_METHOD(Phalcon_Http_Cookie, delete)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, options, session, _1, _2, _3, _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("value", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("name", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&session, this_ptr, "getstartedsession", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&session) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getsessionkey", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &session, "remove", NULL, 0, &_0$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 869, &__$null);
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZVAL_LONG(&_2, (zephir_get_numberval(&_1) - 691200));
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getcookieoptions", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 862, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_FUNCTION(NULL, "setcookie", NULL, 0, &_2, &_3, &options);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the domain that the cookie is available to
 */
PHP_METHOD(Phalcon_Http_Cookie, getDomain)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER_TYPED(getThis(), "domain", IS_STRING);
}

/**
 * Returns the current expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, getExpiration)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER_TYPED(getThis(), "expire", IS_LONG);
}

/**
 * Returns if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
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
 *
 * @phpstan-return http_cookie_options
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER_TYPED(getThis(), "path", IS_STRING);
}

/**
 * Returns whether the cookie must only be sent when the connection is
 * secure (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, getSecure)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_MEMBER(getThis(), "secure");
}

/**
 * Returns the cookie's value.
 *
 * @todo filters needs to be array/string
 */
PHP_METHOD(Phalcon_Http_Cookie, getValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filters = NULL, filters_sub, *defaultValue = NULL, defaultValue_sub, _COOKIE, __$null, container, value, crypt, decryptedValue, filter, signKey, name, _0, _1$$3, _2$$5, _4$$5, _5$$5, _3$$6, _6$$7, _7$$11, _8$$13, _9$$14, _10$$12, _11$$12;
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
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("isRead", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("useEncryption", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("signKey", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("value", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("filter", 6, 1);
	}

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&container);
	ZVAL_NULL(&container);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 862, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 870, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		zephir_memory_observe(&value);
		if (!(zephir_array_isset_fetch(&value, &_COOKIE, &name, 0))) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_2, 871, PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_3, 872, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&container, &_2$$5);
			if (Z_TYPE_P(&container) == IS_NULL) {
				ZEPHIR_INIT_VAR(&_3$$6);
				object_init_ex(&_3$$6, phalcon_http_cookie_exceptions_cryptserviceunavailable_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$6, "phalcon/Http/Cookie.zep", 208);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "crypt");
			ZEPHIR_CALL_METHOD(&_4$$5, &container, "getshared", NULL, 0, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&crypt, &_4$$5);
			if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_6$$7);
				object_init_ex(&_6$$7, phalcon_http_cookie_exceptions_cryptinterfacerequired_ce);
				ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$7, "phalcon/Http/Cookie.zep", 214);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_4, 873, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&signKey, &_2$$5);
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
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 869, &decryptedValue);
		if (Z_TYPE_P(filters) != IS_NULL) {
			zephir_read_property_cached(&_7$$11, this_ptr, _zephir_prop_6, 874, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&filter, &_7$$11);
			if (Z_TYPE_P(&filter) != IS_OBJECT) {
				if (Z_TYPE_P(&container) == IS_NULL) {
					zephir_read_property_cached(&_8$$13, this_ptr, _zephir_prop_3, 872, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&container, &_8$$13);
					if (Z_TYPE_P(&container) == IS_NULL) {
						ZEPHIR_INIT_VAR(&_9$$14);
						object_init_ex(&_9$$14, phalcon_http_cookie_exceptions_filterserviceunavailable_ce);
						ZEPHIR_CALL_METHOD(NULL, &_9$$14, "__construct", NULL, 0);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$14, "phalcon/Http/Cookie.zep", 253);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_VAR(&_11$$12);
				ZVAL_STRING(&_11$$12, "filter");
				ZEPHIR_CALL_METHOD(&_10$$12, &container, "getshared", NULL, 0, &_11$$12);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filter, &_10$$12);
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 874, &filter);
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
 * Reads the cookie-related info from the SESSION to restore the cookie as
 * it was set.
 *
 * This method is automatically called internally so normally you don't
 * need to call it.
 */
PHP_METHOD(Phalcon_Http_Cookie, restore)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, __$false, definition, domain, expire, httpOnly, options, path, secure, session, _0, _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&expire);
	ZVAL_UNDEF(&httpOnly);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&secure);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isRestored", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("expire", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("httpOnly", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("options", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 875, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getstartedsession", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&session) != IS_NULL) {
			ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "getsessionkey", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &session, "get", NULL, 0, &_1$$4);
			zephir_check_call_status();
			if (zephir_array_isset_string_fetch(&expire, &definition, SL("expire"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 863, &expire);
			}
			if (zephir_array_isset_string_fetch(&domain, &definition, SL("domain"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 866, &domain);
			}
			if (zephir_array_isset_string_fetch(&path, &definition, SL("path"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 864, &path);
			}
			if (zephir_array_isset_string_fetch(&secure, &definition, SL("secure"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 865, &secure);
			}
			if (zephir_array_isset_string_fetch(&httpOnly, &definition, SL("httpOnly"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 867, &httpOnly);
			}
			if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 1)) {
				zephir_update_property_zval_cached(this_ptr, _zephir_prop_6, 868, &options);
			}
		}
		if (1) {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 875, &__$true);
		} else {
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 875, &__$false);
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
	zval _9$$8, _10$$9;
	zend_bool _3;
	zval container, crypt, definition, encryptValue, expire, domain, httpOnly, name, options, path, secure, session, signKey, value, _0, _1, _11, _2$$4, _4$$6, _5$$5, _6$$5, _8$$5, _7$$7;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("value", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("expire", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("httpOnly", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("useEncryption", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("signKey", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 862, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&name, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 869, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&value, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 863, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&expire, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_3, 866, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&domain, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_4, 864, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&path, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_5, 865, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&secure, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_6, 867, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&httpOnly, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_7, 868, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_8, 872, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	ZEPHIR_INIT_VAR(&definition);
	array_init(&definition);
	zephir_array_update_string(&definition, SL("expire"), &expire, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("path"), &path, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("domain"), &domain, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("secure"), &secure, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("httpOnly"), &httpOnly, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&definition, SL("options"), &options, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 30, &definition);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&definition, &_1);
	if (!(ZEPHIR_IS_EMPTY(&definition))) {
		ZEPHIR_CALL_METHOD(&session, this_ptr, "getstartedsession", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&session) != IS_NULL) {
			ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "getsessionkey", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &session, "set", NULL, 0, &_2$$4, &definition);
			zephir_check_call_status();
		}
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_9, 871, PH_NOISY_CC | PH_READONLY);
	_3 = zephir_is_true(&_0);
	if (_3) {
		_3 = !(ZEPHIR_IS_EMPTY(&value));
	}
	if (_3) {
		if (Z_TYPE_P(&container) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$6);
			object_init_ex(&_4$$6, phalcon_http_cookie_exceptions_filterserviceunavailable_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$6, "phalcon/Http/Cookie.zep", 369);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "crypt");
		ZEPHIR_CALL_METHOD(&_5$$5, &container, "getshared", NULL, 0, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&crypt, &_5$$5);
		if (UNEXPECTED(Z_TYPE_P(&crypt) != IS_OBJECT)) {
			ZEPHIR_INIT_VAR(&_7$$7);
			object_init_ex(&_7$$7, phalcon_http_cookie_exceptions_cryptinterfacerequired_ce);
			ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$7, "phalcon/Http/Cookie.zep", 375);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_10, 873, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&signKey, &_8$$5);
		if (Z_TYPE_P(&signKey) == IS_STRING) {
			zephir_cast_to_string(&_9$$8, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_9$$8, &signKey);
			zephir_check_call_status();
		} else {
			zephir_cast_to_string(&_10$$9, &value);
			ZEPHIR_CALL_METHOD(&encryptValue, &crypt, "encryptbase64", NULL, 0, &_10$$9);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&encryptValue, &value);
	}
	zephir_read_property_cached(&_11, this_ptr, _zephir_prop_2, 863, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&options, this_ptr, "getcookieoptions", NULL, 0, &_11);
	zephir_check_call_status();
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
	zval domain_zv;
	zend_string *domain = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&domain_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("domain", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(domain)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&domain_zv);
	ZVAL_STR_COPY(&domain_zv, domain);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 866, &domain_zv);
	RETURN_THIS();
}

/**
 * Sets the cookie's expiration time
 */
PHP_METHOD(Phalcon_Http_Cookie, setExpiration)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *expire_param = NULL, _0;
	zend_long expire, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("expire", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(expire)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expire_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, expire);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 863, &_0);
	RETURN_THIS();
}

/**
 * Sets if the cookie is accessible only through the HTTP protocol
 */
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *httpOnly_param = NULL, __$true, __$false;
	zend_bool httpOnly;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("httpOnly", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(httpOnly)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &httpOnly_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	if (httpOnly) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 867, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 867, &__$false);
	}
	RETURN_THIS();
}

/**
 * Sets the cookie's options
 *
 * @phpstan-param http_cookie_options $options
 */
PHP_METHOD(Phalcon_Http_Cookie, setOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &options_param);
	zephir_get_arrval(&options, options_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 868, &options);
	RETURN_THIS();
}

/**
 * Sets the cookie's path
 */
PHP_METHOD(Phalcon_Http_Cookie, setPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv;
	zend_string *path = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("path", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 864, &path_zv);
	RETURN_THIS();
}

/**
 * Sets if the cookie must only be sent when the connection is secure
 * (HTTPS)
 */
PHP_METHOD(Phalcon_Http_Cookie, setSecure)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *secure_param = NULL, __$true, __$false;
	zend_bool secure;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("secure", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(secure)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &secure_param);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkrestored", NULL, 0);
	zephir_check_call_status();
	if (secure) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 865, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 865, &__$false);
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
 */
PHP_METHOD(Phalcon_Http_Cookie, setSignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval signKey_zv;
	zend_string *signKey = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&signKey_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("signKey", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 873, &signKey_zv);
	RETURN_THIS();
}

/**
 * Sets the cookie's value
 */
PHP_METHOD(Phalcon_Http_Cookie, setValue)
{
	zval *value, value_sub, __$true, __$false;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("value", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("isRead", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 869, value);
	if (1) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 870, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 870, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("useEncryption", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(useEncryption)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &useEncryption_param);
	if (useEncryption) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 871, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 871, &__$false);
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
	ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 0, &signKey_zv);
	zephir_check_call_status();
	if (UNEXPECTED(ZEPHIR_LT_LONG(&length, 32))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_http_cookie_exceptions_cookiekeytooshort_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &length);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Http/Cookie.zep", 535);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Check if the cookie is restored and restore it if not
 */
PHP_METHOD(Phalcon_Http_Cookie, checkRestored)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("isRestored", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 875, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "restore", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-return http_setcookie_options
 */
PHP_METHOD(Phalcon_Http_Cookie, getCookieOptions)
{
	zval options;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *expiresDefault_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zend_long expiresDefault, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("domain", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("path", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("secure", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("httpOnly", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(expiresDefault)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &expiresDefault_param);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 868, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "expires");
	ZVAL_LONG(&_3, expiresDefault);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getarrval", NULL, 0, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("expires"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 866, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "domain");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getarrval", NULL, 0, &options, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("domain"), &_4, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_2, 864, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "path");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getarrval", NULL, 0, &options, &_2, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("path"), &_5, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_3, 865, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "secure");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getarrval", NULL, 0, &options, &_2, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("secure"), &_7, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_10, this_ptr, _zephir_prop_4, 867, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "httponly");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getarrval", NULL, 0, &options, &_2, &_10);
	zephir_check_call_status();
	zephir_array_update_string(&options, SL("httponly"), &_9, PH_COPY | PH_SEPARATE);
	RETURN_CTOR(&options);
}

/**
 * The session key under which this cookie's definition is stored
 */
PHP_METHOD(Phalcon_Http_Cookie, getSessionKey)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("name", 4, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 862, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_SV(return_value, "_PHCOOKIE_", &_0);
	return;
}

/**
 * Returns the session manager from the container when the service is
 * available and the session has been started; `null` otherwise
 */
PHP_METHOD(Phalcon_Http_Cookie, getStartedSession)
{
	zend_bool _1;
	zval container, session, _0, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 872, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	_1 = Z_TYPE_P(&container) != IS_OBJECT;
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "session");
		ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
		zephir_check_call_status();
		_1 = !zephir_is_true(&_2);
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "session");
	ZEPHIR_CALL_METHOD(&_4, &container, "getshared", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&session, &_4);
	ZEPHIR_CALL_METHOD(&_4, &session, "exists", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_4))) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&session);
}

/**
 * Check if implicit encryption is being used
 */
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption)
{

	RETURN_MEMBER(getThis(), "useEncryption");
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Http_Cookie, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	if (1 == zephir_array_isset_value(&collection, index)) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 16, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

