
extern zend_class_entry *phalcon_http_response_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response);

PHP_METHOD(Phalcon_Http_Response, __construct);
PHP_METHOD(Phalcon_Http_Response, setDI);
PHP_METHOD(Phalcon_Http_Response, getDI);
PHP_METHOD(Phalcon_Http_Response, setStatusCode);
PHP_METHOD(Phalcon_Http_Response, getStatusCode);
PHP_METHOD(Phalcon_Http_Response, setHeaders);
PHP_METHOD(Phalcon_Http_Response, getHeaders);
PHP_METHOD(Phalcon_Http_Response, setCookies);
PHP_METHOD(Phalcon_Http_Response, getCookies);
PHP_METHOD(Phalcon_Http_Response, setHeader);
PHP_METHOD(Phalcon_Http_Response, setRawHeader);
PHP_METHOD(Phalcon_Http_Response, resetHeaders);
PHP_METHOD(Phalcon_Http_Response, setExpires);
PHP_METHOD(Phalcon_Http_Response, setNotModified);
PHP_METHOD(Phalcon_Http_Response, setContentType);
PHP_METHOD(Phalcon_Http_Response, setEtag);
PHP_METHOD(Phalcon_Http_Response, redirect);
PHP_METHOD(Phalcon_Http_Response, setContent);
PHP_METHOD(Phalcon_Http_Response, setJsonContent);
PHP_METHOD(Phalcon_Http_Response, appendContent);
PHP_METHOD(Phalcon_Http_Response, getContent);
PHP_METHOD(Phalcon_Http_Response, isSent);
PHP_METHOD(Phalcon_Http_Response, sendHeaders);
PHP_METHOD(Phalcon_Http_Response, sendCookies);
PHP_METHOD(Phalcon_Http_Response, send);
PHP_METHOD(Phalcon_Http_Response, setFileToSend);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheaders, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Http\\Response\\HeadersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcookies, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cookies, Phalcon\\Http\\Response\\CookiesInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setexpires, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setetag, 0, 0, 1)
	ZEND_ARG_INFO(0, etag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, jsonOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setfiletosend, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, attachmentName)
	ZEND_ARG_INFO(0, attachment)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_method_entry) {
	PHP_ME(Phalcon_Http_Response, __construct, arginfo_phalcon_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Response, setDI, arginfo_phalcon_http_response_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setStatusCode, arginfo_phalcon_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeaders, arginfo_phalcon_http_response_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setCookies, arginfo_phalcon_http_response_setcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeader, arginfo_phalcon_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setRawHeader, arginfo_phalcon_http_response_setrawheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, resetHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setExpires, arginfo_phalcon_http_response_setexpires, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setNotModified, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContentType, arginfo_phalcon_http_response_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setEtag, arginfo_phalcon_http_response_setetag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, redirect, arginfo_phalcon_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContent, arginfo_phalcon_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setJsonContent, arginfo_phalcon_http_response_setjsoncontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, appendContent, arginfo_phalcon_http_response_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, isSent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setFileToSend, arginfo_phalcon_http_response_setfiletosend, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
