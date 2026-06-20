
extern zend_class_entry *phalcon_contracts_queue_context_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Context);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_context_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createconsumer, 0, 1, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createmessage, 0, 0, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createproducer, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createqueue, 0, 1, Phalcon\\Contracts\\Queue\\Queue, 0)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createsubscriptionconsumer, 0, 0, Phalcon\\Contracts\\Queue\\SubscriptionConsumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createtemporaryqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_queue_context_createtopic, 0, 1, Phalcon\\Contracts\\Queue\\Topic, 0)
	ZEND_ARG_TYPE_INFO(0, topicName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_context_purgequeue, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_context_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, close, arginfo_phalcon_contracts_queue_context_close)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createConsumer, arginfo_phalcon_contracts_queue_context_createconsumer)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createMessage, arginfo_phalcon_contracts_queue_context_createmessage)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createProducer, arginfo_phalcon_contracts_queue_context_createproducer)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createQueue, arginfo_phalcon_contracts_queue_context_createqueue)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createSubscriptionConsumer, arginfo_phalcon_contracts_queue_context_createsubscriptionconsumer)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createTemporaryQueue, arginfo_phalcon_contracts_queue_context_createtemporaryqueue)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, createTopic, arginfo_phalcon_contracts_queue_context_createtopic)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Context, purgeQueue, arginfo_phalcon_contracts_queue_context_purgequeue)
	PHP_FE_END
};
