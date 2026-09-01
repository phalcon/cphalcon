
extern zend_class_entry *phalcon_queue_adapter_traits_messagetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Traits_MessageTrait);

PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getBody);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getCorrelationId);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeader);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaders);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getMessageId);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperties);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperty);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getReplyTo);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getTimestamp);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, isRedelivered);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setBody);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setCorrelationId);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeader);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeaders);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setMessageId);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperties);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperty);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setRedelivered);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setReplyTo);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, setTimestamp);
PHP_METHOD(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaderAsString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getcorrelationid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getmessageid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getproperties, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getproperty, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getreplyto, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_gettimestamp, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_isredelivered, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setbody, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, body, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setcorrelationid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, correlationId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setheader, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setheaders, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setmessageid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, messageId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setproperties, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setproperty, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setredelivered, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, redelivered, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_setreplyto, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, replyTo, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_settimestamp, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_traits_messagetrait_getheaderasstring, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_traits_messagetrait_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, __construct, arginfo_phalcon_queue_adapter_traits_messagetrait___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getBody, arginfo_phalcon_queue_adapter_traits_messagetrait_getbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getCorrelationId, arginfo_phalcon_queue_adapter_traits_messagetrait_getcorrelationid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeader, arginfo_phalcon_queue_adapter_traits_messagetrait_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaders, arginfo_phalcon_queue_adapter_traits_messagetrait_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getMessageId, arginfo_phalcon_queue_adapter_traits_messagetrait_getmessageid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperties, arginfo_phalcon_queue_adapter_traits_messagetrait_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getProperty, arginfo_phalcon_queue_adapter_traits_messagetrait_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getReplyTo, arginfo_phalcon_queue_adapter_traits_messagetrait_getreplyto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getTimestamp, arginfo_phalcon_queue_adapter_traits_messagetrait_gettimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, isRedelivered, arginfo_phalcon_queue_adapter_traits_messagetrait_isredelivered, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setBody, arginfo_phalcon_queue_adapter_traits_messagetrait_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setCorrelationId, arginfo_phalcon_queue_adapter_traits_messagetrait_setcorrelationid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeader, arginfo_phalcon_queue_adapter_traits_messagetrait_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setHeaders, arginfo_phalcon_queue_adapter_traits_messagetrait_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setMessageId, arginfo_phalcon_queue_adapter_traits_messagetrait_setmessageid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperties, arginfo_phalcon_queue_adapter_traits_messagetrait_setproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setProperty, arginfo_phalcon_queue_adapter_traits_messagetrait_setproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setRedelivered, arginfo_phalcon_queue_adapter_traits_messagetrait_setredelivered, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setReplyTo, arginfo_phalcon_queue_adapter_traits_messagetrait_setreplyto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, setTimestamp, arginfo_phalcon_queue_adapter_traits_messagetrait_settimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Traits_MessageTrait, getHeaderAsString, arginfo_phalcon_queue_adapter_traits_messagetrait_getheaderasstring, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
