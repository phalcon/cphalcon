
extern zend_class_entry *phalcon_contracts_queue_producer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Producer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_producer_getdeliverydelay, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_producer_getpriority, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_producer_gettimetolive, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_producer_send, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_producer_setdeliverydelay, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, deliveryDelay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_producer_setpriority, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_producer_settimetolive, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, timeToLive)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_producer_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, getDeliveryDelay, arginfo_phalcon_contracts_queue_producer_getdeliverydelay)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, getPriority, arginfo_phalcon_contracts_queue_producer_getpriority)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, getTimeToLive, arginfo_phalcon_contracts_queue_producer_gettimetolive)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, send, arginfo_phalcon_contracts_queue_producer_send)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, setDeliveryDelay, arginfo_phalcon_contracts_queue_producer_setdeliverydelay)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, setPriority, arginfo_phalcon_contracts_queue_producer_setpriority)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Producer, setTimeToLive, arginfo_phalcon_contracts_queue_producer_settimetolive)
	PHP_FE_END
};
