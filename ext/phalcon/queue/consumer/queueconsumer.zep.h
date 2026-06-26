
extern zend_class_entry *phalcon_queue_consumer_queueconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_QueueConsumer);

PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, __construct);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, bind);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, consume);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, consumeOnce);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, end);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, isStopRequested);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, setPollInterval);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, start);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, stop);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, handleResult);
PHP_METHOD(Phalcon_Queue_Consumer_QueueConsumer, process);
zend_object *zephir_init_properties_Phalcon_Queue_Consumer_QueueConsumer(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Contracts\\Queue\\Context, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_bind, 0, 2, Phalcon\\Queue\\Consumer\\QueueConsumer, 0)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
	ZEND_ARG_OBJ_INFO(0, processor, Phalcon\\Contracts\\Queue\\Processor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_consume, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_consumeonce, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_end, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_isstoprequested, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_setpollinterval, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pollInterval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_start, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_stop, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_handleresult, 0, 3, IS_VOID, 0)

	ZEND_ARG_INFO(0, consumer)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_INFO(0, result)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_process, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, binding)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_consumer_queueconsumer_zephir_init_properties_phalcon_queue_consumer_queueconsumer, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_consumer_queueconsumer_method_entry) {
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, __construct, arginfo_phalcon_queue_consumer_queueconsumer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, bind, arginfo_phalcon_queue_consumer_queueconsumer_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, consume, arginfo_phalcon_queue_consumer_queueconsumer_consume, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, consumeOnce, arginfo_phalcon_queue_consumer_queueconsumer_consumeonce, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, end, arginfo_phalcon_queue_consumer_queueconsumer_end, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, isStopRequested, arginfo_phalcon_queue_consumer_queueconsumer_isstoprequested, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, setPollInterval, arginfo_phalcon_queue_consumer_queueconsumer_setpollinterval, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, start, arginfo_phalcon_queue_consumer_queueconsumer_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, stop, arginfo_phalcon_queue_consumer_queueconsumer_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, handleResult, arginfo_phalcon_queue_consumer_queueconsumer_handleresult, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Consumer_QueueConsumer, process, arginfo_phalcon_queue_consumer_queueconsumer_process, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
