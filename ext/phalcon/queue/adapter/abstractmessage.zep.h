
extern zend_class_entry *phalcon_queue_adapter_abstractmessage_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractMessage);

PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getBody);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getCorrelationId);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getHeader);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getHeaders);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getMessageId);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getProperties);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getProperty);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getReplyTo);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, getTimestamp);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, isRedelivered);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setBody);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setCorrelationId);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setHeader);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setHeaders);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setMessageId);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setProperties);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setProperty);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setRedelivered);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setReplyTo);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractMessage, setTimestamp);
zend_object *zephir_init_properties_Phalcon_Queue_Adapter_AbstractMessage(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getcorrelationid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getmessageid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getproperties, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getproperty, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_getreplyto, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_gettimestamp, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_isredelivered, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setbody, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, body, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setcorrelationid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, correlationId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setheader, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setheaders, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setmessageid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, messageId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setproperties, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setproperty, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setredelivered, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, redelivered, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_setreplyto, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, replyTo, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_settimestamp, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_abstractmessage_zephir_init_properties_phalcon_queue_adapter_abstractmessage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_abstractmessage_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, __construct, arginfo_phalcon_queue_adapter_abstractmessage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getBody, arginfo_phalcon_queue_adapter_abstractmessage_getbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getCorrelationId, arginfo_phalcon_queue_adapter_abstractmessage_getcorrelationid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getHeader, arginfo_phalcon_queue_adapter_abstractmessage_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getHeaders, arginfo_phalcon_queue_adapter_abstractmessage_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getMessageId, arginfo_phalcon_queue_adapter_abstractmessage_getmessageid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getProperties, arginfo_phalcon_queue_adapter_abstractmessage_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getProperty, arginfo_phalcon_queue_adapter_abstractmessage_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getReplyTo, arginfo_phalcon_queue_adapter_abstractmessage_getreplyto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, getTimestamp, arginfo_phalcon_queue_adapter_abstractmessage_gettimestamp, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, isRedelivered, arginfo_phalcon_queue_adapter_abstractmessage_isredelivered, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setBody, arginfo_phalcon_queue_adapter_abstractmessage_setbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setCorrelationId, arginfo_phalcon_queue_adapter_abstractmessage_setcorrelationid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setHeader, arginfo_phalcon_queue_adapter_abstractmessage_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setHeaders, arginfo_phalcon_queue_adapter_abstractmessage_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setMessageId, arginfo_phalcon_queue_adapter_abstractmessage_setmessageid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setProperties, arginfo_phalcon_queue_adapter_abstractmessage_setproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setProperty, arginfo_phalcon_queue_adapter_abstractmessage_setproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setRedelivered, arginfo_phalcon_queue_adapter_abstractmessage_setredelivered, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setReplyTo, arginfo_phalcon_queue_adapter_abstractmessage_setreplyto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractMessage, setTimestamp, arginfo_phalcon_queue_adapter_abstractmessage_settimestamp, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
