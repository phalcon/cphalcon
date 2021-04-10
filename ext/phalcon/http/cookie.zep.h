
extern zend_class_entry *phalcon_http_cookie_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie);

PHP_METHOD(Phalcon_Http_Cookie, __construct);
PHP_METHOD(Phalcon_Http_Cookie, __toString);
PHP_METHOD(Phalcon_Http_Cookie, delete);
PHP_METHOD(Phalcon_Http_Cookie, getDomain);
PHP_METHOD(Phalcon_Http_Cookie, getExpiration);
PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly);
PHP_METHOD(Phalcon_Http_Cookie, getName);
PHP_METHOD(Phalcon_Http_Cookie, getOptions);
PHP_METHOD(Phalcon_Http_Cookie, getPath);
PHP_METHOD(Phalcon_Http_Cookie, getSecure);
PHP_METHOD(Phalcon_Http_Cookie, getValue);
PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption);
PHP_METHOD(Phalcon_Http_Cookie, restore);
PHP_METHOD(Phalcon_Http_Cookie, send);
PHP_METHOD(Phalcon_Http_Cookie, setDomain);
PHP_METHOD(Phalcon_Http_Cookie, setExpiration);
PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly);
PHP_METHOD(Phalcon_Http_Cookie, setOptions);
PHP_METHOD(Phalcon_Http_Cookie, setPath);
PHP_METHOD(Phalcon_Http_Cookie, setSecure);
PHP_METHOD(Phalcon_Http_Cookie, setSignKey);
PHP_METHOD(Phalcon_Http_Cookie, setValue);
PHP_METHOD(Phalcon_Http_Cookie, useEncryption);
PHP_METHOD(Phalcon_Http_Cookie, assertSignKeyIsLongEnough);
zend_object *zephir_init_properties_Phalcon_Http_Cookie(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, expire, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 1)
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_delete, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getdomain, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getexpiration, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_gethttponly, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_getsecure, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_isusingencryption, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_restore, 0, 0, Phalcon\\Http\\Cookie\\CookieInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_send, 0, 0, Phalcon\\Http\\Cookie\\CookieInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setdomain, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setexpiration, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expire, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_sethttponly, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setoptions, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setpath, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setsecure, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setsignkey, 0, 0, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, signKey, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_setvalue, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_useencryption, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, useEncryption, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_assertsignkeyislongenough, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, signKey, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_zephir_init_properties_phalcon_http_cookie, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_cookie_method_entry) {
	PHP_ME(Phalcon_Http_Cookie, __construct, arginfo_phalcon_http_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Cookie, __toString, arginfo_phalcon_http_cookie___tostring, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Cookie, delete, arginfo_phalcon_http_cookie_delete, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Http_Cookie, delete, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Http_Cookie, getDomain, arginfo_phalcon_http_cookie_getdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getExpiration, arginfo_phalcon_http_cookie_getexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getHttpOnly, arginfo_phalcon_http_cookie_gethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getName, arginfo_phalcon_http_cookie_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getOptions, arginfo_phalcon_http_cookie_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getPath, arginfo_phalcon_http_cookie_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getSecure, arginfo_phalcon_http_cookie_getsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getValue, arginfo_phalcon_http_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, isUsingEncryption, arginfo_phalcon_http_cookie_isusingencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, restore, arginfo_phalcon_http_cookie_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, send, arginfo_phalcon_http_cookie_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setDomain, arginfo_phalcon_http_cookie_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setExpiration, arginfo_phalcon_http_cookie_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setHttpOnly, arginfo_phalcon_http_cookie_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setOptions, arginfo_phalcon_http_cookie_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setPath, arginfo_phalcon_http_cookie_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setSecure, arginfo_phalcon_http_cookie_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setSignKey, arginfo_phalcon_http_cookie_setsignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setValue, arginfo_phalcon_http_cookie_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, useEncryption, arginfo_phalcon_http_cookie_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, assertSignKeyIsLongEnough, arginfo_phalcon_http_cookie_assertsignkeyislongenough, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
