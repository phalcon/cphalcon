
extern zend_class_entry *phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer);

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamsubscriptionconsumer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Queue\\Adapter\\Stream\\StreamContext, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pollInterval, IS_LONG, 0, "200")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_stream_streamsubscriptionconsumer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamSubscriptionConsumer, __construct, arginfo_phalcon_queue_adapter_stream_streamsubscriptionconsumer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
