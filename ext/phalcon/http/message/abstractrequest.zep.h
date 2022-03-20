
extern zend_class_entry *phalcon_http_message_abstractrequest_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Message_AbstractRequest);

PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getMethod);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getUri);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, getRequestTarget);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withMethod);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withRequestTarget);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, withUri);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, processMethod);
PHP_METHOD(Phalcon_Http_Message_AbstractRequest, processUri);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractrequest_getmethod, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractrequest_geturi, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractrequest_getrequesttarget, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractrequest_withmethod, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractrequest_withrequesttarget, 0, 0, 1)
	ZEND_ARG_INFO(0, requestTarget)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_message_abstractrequest_withuri, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uri, PsrExt\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, preserveHost)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_message_abstractrequest_processmethod, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_message_abstractrequest_processuri, 0, 1, PsrExt\\Http\\Message\\UriInterface, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_message_abstractrequest_method_entry) {
	PHP_ME(Phalcon_Http_Message_AbstractRequest, getMethod, arginfo_phalcon_http_message_abstractrequest_getmethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Http_Message_AbstractRequest, getUri, arginfo_phalcon_http_message_abstractrequest_geturi, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Http_Message_AbstractRequest, getUri, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Http_Message_AbstractRequest, getRequestTarget, arginfo_phalcon_http_message_abstractrequest_getrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractRequest, withMethod, arginfo_phalcon_http_message_abstractrequest_withmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractRequest, withRequestTarget, arginfo_phalcon_http_message_abstractrequest_withrequesttarget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractRequest, withUri, arginfo_phalcon_http_message_abstractrequest_withuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Message_AbstractRequest, processMethod, arginfo_phalcon_http_message_abstractrequest_processmethod, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Http_Message_AbstractRequest, processUri, arginfo_phalcon_http_message_abstractrequest_processuri, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
