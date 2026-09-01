
extern zend_class_entry *phalcon_queue_adapter_memory_memoryproducer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Memory_MemoryProducer);

PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Memory_MemoryProducer, send);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Queue\\Adapter\\Memory\\MemoryContext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_memory_memoryproducer_send, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_memory_memoryproducer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, __construct, arginfo_phalcon_queue_adapter_memory_memoryproducer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Memory_MemoryProducer, send, arginfo_phalcon_queue_adapter_memory_memoryproducer_send, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
