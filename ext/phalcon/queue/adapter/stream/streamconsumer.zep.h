
extern zend_class_entry *phalcon_queue_adapter_stream_streamconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamConsumer);

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConsumer, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConsumer, acknowledge);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConsumer, getQueue);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConsumer, receiveNoWait);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConsumer, reject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamconsumer___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Queue\\Adapter\\Stream\\StreamContext, 0)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pollInterval, IS_LONG, 0, "200")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamconsumer_acknowledge, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamconsumer_getqueue, 0, 0, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamconsumer_receivenowait, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamconsumer_reject, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, requeue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_stream_streamconsumer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamConsumer, __construct, arginfo_phalcon_queue_adapter_stream_streamconsumer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamConsumer, acknowledge, arginfo_phalcon_queue_adapter_stream_streamconsumer_acknowledge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamConsumer, getQueue, arginfo_phalcon_queue_adapter_stream_streamconsumer_getqueue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamConsumer, receiveNoWait, arginfo_phalcon_queue_adapter_stream_streamconsumer_receivenowait, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamConsumer, reject, arginfo_phalcon_queue_adapter_stream_streamconsumer_reject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
