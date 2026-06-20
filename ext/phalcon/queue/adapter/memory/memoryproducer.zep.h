
extern zend_class_entry *phalcon_queue_adapter_memory_memoryproducer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryProducer);

PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, getDeliveryDelay);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, getPriority);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, getTimeToLive);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, send);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, setDeliveryDelay);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, setPriority);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, setTimeToLive);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Queue\\Adapter\\Memory\\MemoryContext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_getdeliverydelay, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_getpriority, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_gettimetolive, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_send, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_setdeliverydelay, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, deliveryDelay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_setpriority, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_settimetolive, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, timeToLive)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_memory_memoryproducer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, __construct, arginfo_phalcon_queue_adapter_memory_memoryproducer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, getDeliveryDelay, arginfo_phalcon_queue_adapter_memory_memoryproducer_getdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, getPriority, arginfo_phalcon_queue_adapter_memory_memoryproducer_getpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, getTimeToLive, arginfo_phalcon_queue_adapter_memory_memoryproducer_gettimetolive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, send, arginfo_phalcon_queue_adapter_memory_memoryproducer_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, setDeliveryDelay, arginfo_phalcon_queue_adapter_memory_memoryproducer_setdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, setPriority, arginfo_phalcon_queue_adapter_memory_memoryproducer_setpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, setTimeToLive, arginfo_phalcon_queue_adapter_memory_memoryproducer_settimetolive, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
