
extern zend_class_entry *phalcon_http_cookie_cookieinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie_CookieInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_delete, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getdomain, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getexpiration, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_gethttponly, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getsecure, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_isusingencryption, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_send, 0, 0, Phalcon\\Http\\Cookie\\CookieInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setdomain, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setexpiration, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, expire, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_sethttponly, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setoptions, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setpath, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setsecure, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_setvalue, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookie_cookieinterface_useencryption, 0, 1, Phalcon\\Http\\Cookie\\CookieInterface, 0)
	ZEND_ARG_TYPE_INFO(0, useEncryption, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_cookie_cookieinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, delete, arginfo_phalcon_http_cookie_cookieinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getDomain, arginfo_phalcon_http_cookie_cookieinterface_getdomain)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getExpiration, arginfo_phalcon_http_cookie_cookieinterface_getexpiration)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getHttpOnly, arginfo_phalcon_http_cookie_cookieinterface_gethttponly)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getName, arginfo_phalcon_http_cookie_cookieinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getOptions, arginfo_phalcon_http_cookie_cookieinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getPath, arginfo_phalcon_http_cookie_cookieinterface_getpath)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getSecure, arginfo_phalcon_http_cookie_cookieinterface_getsecure)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, getValue, arginfo_phalcon_http_cookie_cookieinterface_getvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, isUsingEncryption, arginfo_phalcon_http_cookie_cookieinterface_isusingencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, send, arginfo_phalcon_http_cookie_cookieinterface_send)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setDomain, arginfo_phalcon_http_cookie_cookieinterface_setdomain)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setExpiration, arginfo_phalcon_http_cookie_cookieinterface_setexpiration)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setHttpOnly, arginfo_phalcon_http_cookie_cookieinterface_sethttponly)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setOptions, arginfo_phalcon_http_cookie_cookieinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setPath, arginfo_phalcon_http_cookie_cookieinterface_setpath)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setSecure, arginfo_phalcon_http_cookie_cookieinterface_setsecure)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, setValue, arginfo_phalcon_http_cookie_cookieinterface_setvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_Cookie_CookieInterface, useEncryption, arginfo_phalcon_http_cookie_cookieinterface_useencryption)
	PHP_FE_END
};
