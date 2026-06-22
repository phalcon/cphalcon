
extern zend_class_entry *phalcon_contracts_queue_consumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Consumer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_consumer_acknowledge, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_consumer_getqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_consumer_receive, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_consumer_receivenowait, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_consumer_reject, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, requeue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_consumer_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Consumer, acknowledge, arginfo_phalcon_contracts_queue_consumer_acknowledge)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Consumer, getQueue, arginfo_phalcon_contracts_queue_consumer_getqueue)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Consumer, receive, arginfo_phalcon_contracts_queue_consumer_receive)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Consumer, receiveNoWait, arginfo_phalcon_contracts_queue_consumer_receivenowait)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Consumer, reject, arginfo_phalcon_contracts_queue_consumer_reject)
	PHP_FE_END
};
