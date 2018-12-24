
extern zend_class_entry *phalcon_http_cookieinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_CookieInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_setvalue, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_setvalue, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_send, 0, 0, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_send, 0, 0, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_useencryption, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_useencryption, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useEncryption, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useEncryption)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_isusingencryption, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_isusingencryption, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_setexpiration, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_setexpiration, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, expire, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, expire)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getexpiration, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getexpiration, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_setpath, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_setpath, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_setdomain, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_setdomain, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, domain, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, domain)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getdomain, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getdomain, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_setsecure, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_setsecure, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, secure, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, secure)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getsecure, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_getsecure, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_cookieinterface_sethttponly, 0, 1, Phalcon\\Http\\CookieInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_sethttponly, 0, 1, IS_OBJECT, "Phalcon\\Http\\CookieInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, httpOnly, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, httpOnly)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_gethttponly, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_cookieinterface_gethttponly, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_cookieinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setValue, arginfo_phalcon_http_cookieinterface_setvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getValue, arginfo_phalcon_http_cookieinterface_getvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, send, arginfo_phalcon_http_cookieinterface_send)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, useEncryption, arginfo_phalcon_http_cookieinterface_useencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, isUsingEncryption, arginfo_phalcon_http_cookieinterface_isusingencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setExpiration, arginfo_phalcon_http_cookieinterface_setexpiration)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getExpiration, arginfo_phalcon_http_cookieinterface_getexpiration)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setPath, arginfo_phalcon_http_cookieinterface_setpath)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getName, arginfo_phalcon_http_cookieinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getPath, arginfo_phalcon_http_cookieinterface_getpath)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setDomain, arginfo_phalcon_http_cookieinterface_setdomain)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getDomain, arginfo_phalcon_http_cookieinterface_getdomain)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setSecure, arginfo_phalcon_http_cookieinterface_setsecure)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getSecure, arginfo_phalcon_http_cookieinterface_getsecure)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setHttpOnly, arginfo_phalcon_http_cookieinterface_sethttponly)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getHttpOnly, arginfo_phalcon_http_cookieinterface_gethttponly)
	PHP_FE_END
};
