
extern zend_class_entry *phalcon_messages_message_ce;

ZEPHIR_INIT_CLASS(Phalcon_Messages_Message);

PHP_METHOD(Phalcon_Messages_Message, __construct);
PHP_METHOD(Phalcon_Messages_Message, __toString);
PHP_METHOD(Phalcon_Messages_Message, getCode);
PHP_METHOD(Phalcon_Messages_Message, getField);
PHP_METHOD(Phalcon_Messages_Message, getMessage);
PHP_METHOD(Phalcon_Messages_Message, getType);
PHP_METHOD(Phalcon_Messages_Message, getMetaData);
PHP_METHOD(Phalcon_Messages_Message, jsonSerialize);
PHP_METHOD(Phalcon_Messages_Message, setCode);
PHP_METHOD(Phalcon_Messages_Message, setField);
PHP_METHOD(Phalcon_Messages_Message, setMessage);
PHP_METHOD(Phalcon_Messages_Message, setMetaData);
PHP_METHOD(Phalcon_Messages_Message, setType);
zend_object *zephir_init_properties_Phalcon_Messages_Message(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_message___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, metaData, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, metaData, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_getcode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_getfield, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_getmessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_getmetadata, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_message_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_message_setcode, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_message_setfield, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_message_setmessage, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_message_setmetadata, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, metaData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_message_settype, 0, 1, Phalcon\\Messages\\MessageInterface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_message_zephir_init_properties_phalcon_messages_message, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_messages_message_method_entry) {
	PHP_ME(Phalcon_Messages_Message, __construct, arginfo_phalcon_messages_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Messages_Message, __toString, arginfo_phalcon_messages_message___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, getCode, arginfo_phalcon_messages_message_getcode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, getField, arginfo_phalcon_messages_message_getfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, getMessage, arginfo_phalcon_messages_message_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, getType, arginfo_phalcon_messages_message_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, getMetaData, arginfo_phalcon_messages_message_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, jsonSerialize, arginfo_phalcon_messages_message_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, setCode, arginfo_phalcon_messages_message_setcode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, setField, arginfo_phalcon_messages_message_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, setMessage, arginfo_phalcon_messages_message_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, setMetaData, arginfo_phalcon_messages_message_setmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Message, setType, arginfo_phalcon_messages_message_settype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
