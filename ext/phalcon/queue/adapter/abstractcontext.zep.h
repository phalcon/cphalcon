
extern zend_class_entry *phalcon_queue_adapter_abstractcontext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractContext);

PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createQueue);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createTemporaryQueue);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractContext, createTopic);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractcontext_createqueue, 0, 1, Phalcon\\Contracts\\Queue\\Queue, 0)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractcontext_createtemporaryqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractcontext_createtopic, 0, 1, Phalcon\\Contracts\\Queue\\Topic, 0)
	ZEND_ARG_TYPE_INFO(0, topicName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_abstractcontext_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_AbstractContext, createQueue, arginfo_phalcon_queue_adapter_abstractcontext_createqueue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractContext, createTemporaryQueue, arginfo_phalcon_queue_adapter_abstractcontext_createtemporaryqueue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractContext, createTopic, arginfo_phalcon_queue_adapter_abstractcontext_createtopic, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
