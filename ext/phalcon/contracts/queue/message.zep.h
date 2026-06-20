
extern zend_class_entry *phalcon_contracts_queue_message_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Message);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getcorrelationid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_queue_message_getheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getmessageid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getproperties, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_queue_message_getproperty, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_getreplyto, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_gettimestamp, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_isredelivered, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setbody, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, body, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setcorrelationid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, correlationId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setheader, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setheaders, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setmessageid, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, messageId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setproperties, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, properties, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setproperty, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setredelivered, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, redelivered, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_setreplyto, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, replyTo, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_message_settimestamp, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_message_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getBody, arginfo_phalcon_contracts_queue_message_getbody)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getCorrelationId, arginfo_phalcon_contracts_queue_message_getcorrelationid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getHeader, arginfo_phalcon_contracts_queue_message_getheader)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getHeaders, arginfo_phalcon_contracts_queue_message_getheaders)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getMessageId, arginfo_phalcon_contracts_queue_message_getmessageid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getProperties, arginfo_phalcon_contracts_queue_message_getproperties)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getProperty, arginfo_phalcon_contracts_queue_message_getproperty)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getReplyTo, arginfo_phalcon_contracts_queue_message_getreplyto)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, getTimestamp, arginfo_phalcon_contracts_queue_message_gettimestamp)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, isRedelivered, arginfo_phalcon_contracts_queue_message_isredelivered)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setBody, arginfo_phalcon_contracts_queue_message_setbody)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setCorrelationId, arginfo_phalcon_contracts_queue_message_setcorrelationid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setHeader, arginfo_phalcon_contracts_queue_message_setheader)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setHeaders, arginfo_phalcon_contracts_queue_message_setheaders)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setMessageId, arginfo_phalcon_contracts_queue_message_setmessageid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setProperties, arginfo_phalcon_contracts_queue_message_setproperties)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setProperty, arginfo_phalcon_contracts_queue_message_setproperty)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setRedelivered, arginfo_phalcon_contracts_queue_message_setredelivered)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setReplyTo, arginfo_phalcon_contracts_queue_message_setreplyto)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Message, setTimestamp, arginfo_phalcon_contracts_queue_message_settimestamp)
	PHP_FE_END
};
