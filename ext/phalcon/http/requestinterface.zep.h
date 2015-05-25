
extern zend_class_entry *phalcon_http_requestinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasput, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPut, arginfo_phalcon_http_requestinterface_hasput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoapRequested, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecureRequest, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBasicAuth, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getDigestAuth, NULL)
	PHP_FE_END
};
