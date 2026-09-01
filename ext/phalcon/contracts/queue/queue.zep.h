
extern zend_class_entry *phalcon_contracts_queue_queue_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Queue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_queue_getqueuename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_queue_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Queue, getQueueName, arginfo_phalcon_contracts_queue_queue_getqueuename)
	PHP_FE_END
};
