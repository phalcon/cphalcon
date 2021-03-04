
extern zend_class_entry *phalcon_messages_messages_ce;

ZEPHIR_INIT_CLASS(Phalcon_Messages_Messages);

PHP_METHOD(Phalcon_Messages_Messages, __construct);
PHP_METHOD(Phalcon_Messages_Messages, appendMessage);
PHP_METHOD(Phalcon_Messages_Messages, appendMessages);
PHP_METHOD(Phalcon_Messages_Messages, count);
PHP_METHOD(Phalcon_Messages_Messages, current);
PHP_METHOD(Phalcon_Messages_Messages, filter);
PHP_METHOD(Phalcon_Messages_Messages, jsonSerialize);
PHP_METHOD(Phalcon_Messages_Messages, key);
PHP_METHOD(Phalcon_Messages_Messages, next);
PHP_METHOD(Phalcon_Messages_Messages, offsetExists);
PHP_METHOD(Phalcon_Messages_Messages, offsetGet);
PHP_METHOD(Phalcon_Messages_Messages, offsetSet);
PHP_METHOD(Phalcon_Messages_Messages, offsetUnset);
PHP_METHOD(Phalcon_Messages_Messages, rewind);
PHP_METHOD(Phalcon_Messages_Messages, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messages___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messages_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messages_appendmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_count, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_messages_messages_current, 0, 0, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_filter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, fieldName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_jsonserialize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_key, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_next, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_offsetexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_messages_messages_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_offsetset, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_offsetunset, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_rewind, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_messages_messages_valid, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_messages_messages_method_entry) {
	PHP_ME(Phalcon_Messages_Messages, __construct, arginfo_phalcon_messages_messages___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Messages_Messages, appendMessage, arginfo_phalcon_messages_messages_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, appendMessages, arginfo_phalcon_messages_messages_appendmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, count, arginfo_phalcon_messages_messages_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, current, arginfo_phalcon_messages_messages_current, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, filter, arginfo_phalcon_messages_messages_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, jsonSerialize, arginfo_phalcon_messages_messages_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, key, arginfo_phalcon_messages_messages_key, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, next, arginfo_phalcon_messages_messages_next, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, offsetExists, arginfo_phalcon_messages_messages_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, offsetGet, arginfo_phalcon_messages_messages_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, offsetSet, arginfo_phalcon_messages_messages_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, offsetUnset, arginfo_phalcon_messages_messages_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, rewind, arginfo_phalcon_messages_messages_rewind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Messages_Messages, valid, arginfo_phalcon_messages_messages_valid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
