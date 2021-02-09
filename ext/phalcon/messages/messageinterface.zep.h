
extern zend_class_entry *phalcon_messages_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Messages_MessageInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messageinterface_getcode, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messageinterface_getfield, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_getmessage, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_getmessage, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_getmetadata, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_getmetadata, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_gettype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_gettype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messageinterface_setcode, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_setcode, 0, 1, IS_OBJECT, "Phalcon\\Messages\\MessageInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messageinterface_setfield, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_setfield, 0, 1, IS_OBJECT, "Phalcon\\Messages\\MessageInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, field)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messageinterface_setmessage, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_setmessage, 0, 1, IS_OBJECT, "Phalcon\\Messages\\MessageInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messageinterface_setmetadata, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_setmetadata, 0, 1, IS_OBJECT, "Phalcon\\Messages\\MessageInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, metaData, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messageinterface_settype, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messageinterface_settype, 0, 1, IS_OBJECT, "Phalcon\\Messages\\MessageInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_messages_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, __toString, arginfo_phalcon_messages_messageinterface___tostring)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, getCode, arginfo_phalcon_messages_messageinterface_getcode)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, getField, arginfo_phalcon_messages_messageinterface_getfield)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, getMessage, arginfo_phalcon_messages_messageinterface_getmessage)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, getMetaData, arginfo_phalcon_messages_messageinterface_getmetadata)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, getType, arginfo_phalcon_messages_messageinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, setCode, arginfo_phalcon_messages_messageinterface_setcode)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, setField, arginfo_phalcon_messages_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, setMessage, arginfo_phalcon_messages_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, setMetaData, arginfo_phalcon_messages_messageinterface_setmetadata)
	PHP_ABSTRACT_ME(Phalcon_Messages_MessageInterface, setType, arginfo_phalcon_messages_messageinterface_settype)
	PHP_FE_END
};
