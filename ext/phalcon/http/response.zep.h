
extern zend_class_entry *phalcon_http_response_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response);

PHP_METHOD(Phalcon_Http_Response, __construct);
PHP_METHOD(Phalcon_Http_Response, appendContent);
PHP_METHOD(Phalcon_Http_Response, getContent);
PHP_METHOD(Phalcon_Http_Response, getCookies);
PHP_METHOD(Phalcon_Http_Response, getDI);
PHP_METHOD(Phalcon_Http_Response, getEventsManager);
PHP_METHOD(Phalcon_Http_Response, getHeaders);
PHP_METHOD(Phalcon_Http_Response, getReasonPhrase);
PHP_METHOD(Phalcon_Http_Response, getStatusCode);
PHP_METHOD(Phalcon_Http_Response, hasHeader);
PHP_METHOD(Phalcon_Http_Response, isSent);
PHP_METHOD(Phalcon_Http_Response, redirect);
PHP_METHOD(Phalcon_Http_Response, removeHeader);
PHP_METHOD(Phalcon_Http_Response, resetHeaders);
PHP_METHOD(Phalcon_Http_Response, send);
PHP_METHOD(Phalcon_Http_Response, sendCookies);
PHP_METHOD(Phalcon_Http_Response, sendHeaders);
PHP_METHOD(Phalcon_Http_Response, setCache);
PHP_METHOD(Phalcon_Http_Response, setContent);
PHP_METHOD(Phalcon_Http_Response, setContentLength);
PHP_METHOD(Phalcon_Http_Response, setContentType);
PHP_METHOD(Phalcon_Http_Response, setCookies);
PHP_METHOD(Phalcon_Http_Response, setDI);
PHP_METHOD(Phalcon_Http_Response, setEtag);
PHP_METHOD(Phalcon_Http_Response, setExpires);
PHP_METHOD(Phalcon_Http_Response, setEventsManager);
PHP_METHOD(Phalcon_Http_Response, setFileToSend);
PHP_METHOD(Phalcon_Http_Response, setHeader);
PHP_METHOD(Phalcon_Http_Response, setHeaders);
PHP_METHOD(Phalcon_Http_Response, setJsonContent);
PHP_METHOD(Phalcon_Http_Response, setLastModified);
PHP_METHOD(Phalcon_Http_Response, setNotModified);
PHP_METHOD(Phalcon_Http_Response, setStatusCode);
PHP_METHOD(Phalcon_Http_Response, setRawHeader);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, content)
#endif
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_appendcontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_appendcontent, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getcontent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getcontent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_getcookies, 0, 0, Phalcon\\Http\\Response\\CookiesInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getcookies, 0, 0, IS_OBJECT, "Phalcon\\Http\\Response\\CookiesInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getdi, 0, 0, IS_OBJECT, "Phalcon\\Di\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_getheaders, 0, 0, Phalcon\\Http\\Response\\HeadersInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getheaders, 0, 0, IS_OBJECT, "Phalcon\\Http\\Response\\HeadersInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getreasonphrase, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getreasonphrase, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getstatuscode, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_getstatuscode, 0, 0, IS_LONG, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_hasheader, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_hasheader, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_issent, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_issent, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_redirect, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_redirect, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, location)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, externalRedirect, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, externalRedirect)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, statusCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, statusCode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_removeheader, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_removeheader, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_resetheaders, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_resetheaders, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_send, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_send, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_sendcookies, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_sendcookies, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setcache, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setcache, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, minutes, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, minutes)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setcontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setcontent, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setcontentlength, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setcontentlength, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contentLength, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, contentLength)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setcontenttype, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setcontenttype, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, contentType, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, contentType)
#endif
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setcookies, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setcookies, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, cookies, Phalcon\\Http\\Response\\CookiesInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 0, 1)
#define arginfo_phalcon_http_response_setdi NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setetag, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setetag, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, etag, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, etag)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setexpires, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setexpires, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_http_response_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setfiletosend, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setfiletosend, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
	ZEND_ARG_INFO(0, attachmentName)
	ZEND_ARG_INFO(0, attachment)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setheader, 0, 2, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setheader, 0, 2, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setheaders, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setheaders, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Http\\Response\\HeadersInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setjsoncontent, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setjsoncontent, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_INFO(0, content)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, jsonOptions, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, jsonOptions)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, depth)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setlastmodified, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setlastmodified, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setnotmodified, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setnotmodified, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setstatuscode, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setstatuscode, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_response_setrawheader, 0, 1, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_response_setrawheader, 0, 1, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, header)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_method_entry) {
	PHP_ME(Phalcon_Http_Response, __construct, arginfo_phalcon_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Response, appendContent, arginfo_phalcon_http_response_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getContent, arginfo_phalcon_http_response_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getCookies, arginfo_phalcon_http_response_getcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getDI, arginfo_phalcon_http_response_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getEventsManager, arginfo_phalcon_http_response_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getHeaders, arginfo_phalcon_http_response_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getReasonPhrase, arginfo_phalcon_http_response_getreasonphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getStatusCode, arginfo_phalcon_http_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, hasHeader, arginfo_phalcon_http_response_hasheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, isSent, arginfo_phalcon_http_response_issent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, redirect, arginfo_phalcon_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, removeHeader, arginfo_phalcon_http_response_removeheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, resetHeaders, arginfo_phalcon_http_response_resetheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, send, arginfo_phalcon_http_response_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendCookies, arginfo_phalcon_http_response_sendcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setCache, arginfo_phalcon_http_response_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContent, arginfo_phalcon_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContentLength, arginfo_phalcon_http_response_setcontentlength, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContentType, arginfo_phalcon_http_response_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setCookies, arginfo_phalcon_http_response_setcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setDI, arginfo_phalcon_http_response_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setEtag, arginfo_phalcon_http_response_setetag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setExpires, arginfo_phalcon_http_response_setexpires, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setEventsManager, arginfo_phalcon_http_response_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setFileToSend, arginfo_phalcon_http_response_setfiletosend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeader, arginfo_phalcon_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeaders, arginfo_phalcon_http_response_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setJsonContent, arginfo_phalcon_http_response_setjsoncontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setLastModified, arginfo_phalcon_http_response_setlastmodified, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setNotModified, arginfo_phalcon_http_response_setnotmodified, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setStatusCode, arginfo_phalcon_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setRawHeader, arginfo_phalcon_http_response_setrawheader, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
