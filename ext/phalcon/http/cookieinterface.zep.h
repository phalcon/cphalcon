
extern zend_class_entry *phalcon_http_cookieinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_CookieInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookieinterface_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_cookieinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setValue, arginfo_phalcon_http_cookieinterface_setvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getValue, arginfo_phalcon_http_cookieinterface_getvalue)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, useEncryption, arginfo_phalcon_http_cookieinterface_useencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, isUsingEncryption, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setExpiration, arginfo_phalcon_http_cookieinterface_setexpiration)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getExpiration, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setPath, arginfo_phalcon_http_cookieinterface_setpath)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getPath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setDomain, arginfo_phalcon_http_cookieinterface_setdomain)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getDomain, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setSecure, arginfo_phalcon_http_cookieinterface_setsecure)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getSecure, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, setHttpOnly, arginfo_phalcon_http_cookieinterface_sethttponly)
	PHP_ABSTRACT_ME(Phalcon_Http_CookieInterface, getHttpOnly, NULL)
	PHP_FE_END
};
