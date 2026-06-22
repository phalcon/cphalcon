
extern zend_class_entry *phalcon_queue_adapter_memory_memorycontext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryContext);

PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, close);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createProducer);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, createSubscriptionConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, popMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, purgeQueue);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryContext, pushMessage);
zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Memory_MemoryContext(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_createconsumer, 0, 1, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_createmessage, 0, 0, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_createproducer, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_createsubscriptionconsumer, 0, 0, Phalcon\\Contracts\\Queue\\SubscriptionConsumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_popmessage, 0, 1, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_purgequeue, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_pushmessage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_memory_memorycontext_zephir_init_properties_phalcon_queue_adapter_memory_memorycontext, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_memory_memorycontext_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, close, arginfo_phalcon_queue_adapter_memory_memorycontext_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, createConsumer, arginfo_phalcon_queue_adapter_memory_memorycontext_createconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, createMessage, arginfo_phalcon_queue_adapter_memory_memorycontext_createmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, createProducer, arginfo_phalcon_queue_adapter_memory_memorycontext_createproducer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, createSubscriptionConsumer, arginfo_phalcon_queue_adapter_memory_memorycontext_createsubscriptionconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, popMessage, arginfo_phalcon_queue_adapter_memory_memorycontext_popmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, purgeQueue, arginfo_phalcon_queue_adapter_memory_memorycontext_purgequeue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryContext, pushMessage, arginfo_phalcon_queue_adapter_memory_memorycontext_pushmessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
