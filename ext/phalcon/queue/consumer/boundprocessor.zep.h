
extern zend_class_entry *phalcon_queue_consumer_boundprocessor_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_BoundProcessor);

PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, __construct);
PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getConsumer);
PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getProcessor);
PHP_METHOD(Phalcon_Queue_Consumer_BoundProcessor, getQueue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_consumer_boundprocessor___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
	ZEND_ARG_OBJ_INFO(0, processor, Phalcon\\Contracts\\Queue\\Processor, 0)
	ZEND_ARG_OBJ_INFO(0, consumer, Phalcon\\Contracts\\Queue\\Consumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_consumer_boundprocessor_getconsumer, 0, 0, Phalcon\\Contracts\\Queue\\Consumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_consumer_boundprocessor_getprocessor, 0, 0, Phalcon\\Contracts\\Queue\\Processor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_consumer_boundprocessor_getqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_consumer_boundprocessor_method_entry) {
	PHP_ME(Phalcon_Queue_Consumer_BoundProcessor, __construct, arginfo_phalcon_queue_consumer_boundprocessor___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Consumer_BoundProcessor, getConsumer, arginfo_phalcon_queue_consumer_boundprocessor_getconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_BoundProcessor, getProcessor, arginfo_phalcon_queue_consumer_boundprocessor_getprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_BoundProcessor, getQueue, arginfo_phalcon_queue_consumer_boundprocessor_getqueue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
