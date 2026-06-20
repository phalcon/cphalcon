
extern zend_class_entry *phalcon_queue_adapter_abstractconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractConsumer);

PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, acknowledge);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, getQueue);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, receive);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, receiveNoWait);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, reject);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractConsumer, setPollInterval);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_acknowledge, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_getqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_receive, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_receivenowait, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_reject, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, requeue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractconsumer_setpollinterval, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pollInterval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_abstractconsumer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, acknowledge, arginfo_phalcon_queue_adapter_abstractconsumer_acknowledge, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, getQueue, arginfo_phalcon_queue_adapter_abstractconsumer_getqueue, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, receive, arginfo_phalcon_queue_adapter_abstractconsumer_receive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, receiveNoWait, arginfo_phalcon_queue_adapter_abstractconsumer_receivenowait, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, reject, arginfo_phalcon_queue_adapter_abstractconsumer_reject, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractConsumer, setPollInterval, arginfo_phalcon_queue_adapter_abstractconsumer_setpollinterval, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
