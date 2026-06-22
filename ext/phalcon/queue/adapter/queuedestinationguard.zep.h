
extern zend_class_entry *phalcon_queue_adapter_queuedestinationguard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_QueueDestinationGuard);

PHP_METHOD(Phalcon_Queue_Adapter_QueueDestinationGuard, assertQueue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_queuedestinationguard_assertqueue, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_queuedestinationguard_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_QueueDestinationGuard, assertQueue, arginfo_phalcon_queue_adapter_queuedestinationguard_assertqueue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
