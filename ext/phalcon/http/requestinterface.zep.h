
extern zend_class_entry *phalcon_http_requestinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getacceptablecontent, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getbasicauth, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getbestaccept, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getbestcharset, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getbestlanguage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, trustForwardedHeader, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getclientcharsets, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getcontenttype, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getdigestauth, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_gethttphost, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_gethttpreferer, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getjsonrawbody, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getlanguages, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getmethod, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getport, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_geturi, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, onlyPath, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getput, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getrawbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getscheme, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getserveraddress, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getservername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getuploadedfiles, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, namedKeys, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_getuseragent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_hasfiles, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_hasheader, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_hasput, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isajax, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isconnect, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isdelete, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isget, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_ishead, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, methods)
	ZEND_ARG_TYPE_INFO(0, strict, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isoptions, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_ispost, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_ispurge, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_isput, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_issecure, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_issoap, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_istrace, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_requestinterface_numfiles, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, arginfo_phalcon_http_requestinterface_getacceptablecontent)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBasicAuth, arginfo_phalcon_http_requestinterface_getbasicauth)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, arginfo_phalcon_http_requestinterface_getbestaccept)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, arginfo_phalcon_http_requestinterface_getbestcharset)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, arginfo_phalcon_http_requestinterface_getbestlanguage)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, arginfo_phalcon_http_requestinterface_getclientcharsets)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getContentType, arginfo_phalcon_http_requestinterface_getcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getDigestAuth, arginfo_phalcon_http_requestinterface_getdigestauth)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeaders, arginfo_phalcon_http_requestinterface_getheaders)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, arginfo_phalcon_http_requestinterface_gethttphost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, arginfo_phalcon_http_requestinterface_gethttpreferer)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getJsonRawBody, arginfo_phalcon_http_requestinterface_getjsonrawbody)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, arginfo_phalcon_http_requestinterface_getlanguages)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, arginfo_phalcon_http_requestinterface_getmethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPort, arginfo_phalcon_http_requestinterface_getport)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getURI, arginfo_phalcon_http_requestinterface_geturi)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPut, arginfo_phalcon_http_requestinterface_getput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, arginfo_phalcon_http_requestinterface_getrawbody)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, arginfo_phalcon_http_requestinterface_getscheme)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, arginfo_phalcon_http_requestinterface_getserveraddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, arginfo_phalcon_http_requestinterface_getservername)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, arginfo_phalcon_http_requestinterface_getuseragent)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasHeader, arginfo_phalcon_http_requestinterface_hasheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPut, arginfo_phalcon_http_requestinterface_hasput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, arginfo_phalcon_http_requestinterface_isajax)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isConnect, arginfo_phalcon_http_requestinterface_isconnect)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, arginfo_phalcon_http_requestinterface_isdelete)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, arginfo_phalcon_http_requestinterface_isget)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, arginfo_phalcon_http_requestinterface_ishead)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, arginfo_phalcon_http_requestinterface_isoptions)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, arginfo_phalcon_http_requestinterface_ispost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPurge, arginfo_phalcon_http_requestinterface_ispurge)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, arginfo_phalcon_http_requestinterface_isput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecure, arginfo_phalcon_http_requestinterface_issecure)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoap, arginfo_phalcon_http_requestinterface_issoap)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isTrace, arginfo_phalcon_http_requestinterface_istrace)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, numFiles, arginfo_phalcon_http_requestinterface_numfiles)
	PHP_FE_END
};
