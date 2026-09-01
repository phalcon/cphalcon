
extern zend_class_entry *phalcon_contracts_messages_messages_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Messages_Messages);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_messages_messages_appendmessage, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Messages\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_messages_messages_appendmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_messages_messages_filter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, fieldName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_messages_messages_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Messages_Messages, appendMessage, arginfo_phalcon_contracts_messages_messages_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Messages_Messages, appendMessages, arginfo_phalcon_contracts_messages_messages_appendmessages)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Messages_Messages, filter, arginfo_phalcon_contracts_messages_messages_filter)
	PHP_FE_END
};
