
extern zend_class_entry *phalcon_http_responseinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_ResponseInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_appendcontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_responseinterface_getcontent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_responseinterface_getstatuscode, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_getheaders, 0, 0, Phalcon\\Http\\Response\\HeadersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_responseinterface_hasheader, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_responseinterface_issent, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_redirect, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_TYPE_INFO(0, externalRedirect, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_resetheaders, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setcontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setcontentlength, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, contentLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setcontenttype, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, contentType, IS_STRING, 0)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setexpires, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setfiletosend, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
	ZEND_ARG_INFO(0, attachmentName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setheader, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setjsoncontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setnotmodified, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setrawheader, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_setstatuscode, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_send, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_responseinterface_sendcookies, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_sendheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_responseinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, appendContent, arginfo_phalcon_http_responseinterface_appendcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getContent, arginfo_phalcon_http_responseinterface_getcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getStatusCode, arginfo_phalcon_http_responseinterface_getstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getHeaders, arginfo_phalcon_http_responseinterface_getheaders)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, hasHeader, arginfo_phalcon_http_responseinterface_hasheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, isSent, arginfo_phalcon_http_responseinterface_issent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, redirect, arginfo_phalcon_http_responseinterface_redirect)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, resetHeaders, arginfo_phalcon_http_responseinterface_resetheaders)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContent, arginfo_phalcon_http_responseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentLength, arginfo_phalcon_http_responseinterface_setcontentlength)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentType, arginfo_phalcon_http_responseinterface_setcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setExpires, arginfo_phalcon_http_responseinterface_setexpires)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setFileToSend, arginfo_phalcon_http_responseinterface_setfiletosend)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setHeader, arginfo_phalcon_http_responseinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setJsonContent, arginfo_phalcon_http_responseinterface_setjsoncontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setNotModified, arginfo_phalcon_http_responseinterface_setnotmodified)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setRawHeader, arginfo_phalcon_http_responseinterface_setrawheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setStatusCode, arginfo_phalcon_http_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, send, arginfo_phalcon_http_responseinterface_send)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendCookies, arginfo_phalcon_http_responseinterface_sendcookies)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendHeaders, arginfo_phalcon_http_responseinterface_sendheaders)
	PHP_FE_END
};
