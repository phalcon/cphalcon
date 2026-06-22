
extern zend_class_entry *phalcon_queue_adapter_stream_streamcontext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamContext);

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, close);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createProducer);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createSubscriptionConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, popMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, purgeQueue);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, pushMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, ensureDir);
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, getFilepath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, storageDir, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pollInterval, IS_LONG, 0, "200")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_createconsumer, 0, 1, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_createmessage, 0, 0, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_createproducer, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_createsubscriptionconsumer, 0, 0, Phalcon\\Contracts\\Queue\\SubscriptionConsumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_popmessage, 0, 1, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_purgequeue, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_pushmessage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_ensuredir, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_stream_streamcontext_getfilepath, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_stream_streamcontext_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, __construct, arginfo_phalcon_queue_adapter_stream_streamcontext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, close, arginfo_phalcon_queue_adapter_stream_streamcontext_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, createConsumer, arginfo_phalcon_queue_adapter_stream_streamcontext_createconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, createMessage, arginfo_phalcon_queue_adapter_stream_streamcontext_createmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, createProducer, arginfo_phalcon_queue_adapter_stream_streamcontext_createproducer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, createSubscriptionConsumer, arginfo_phalcon_queue_adapter_stream_streamcontext_createsubscriptionconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, popMessage, arginfo_phalcon_queue_adapter_stream_streamcontext_popmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, purgeQueue, arginfo_phalcon_queue_adapter_stream_streamcontext_purgequeue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, pushMessage, arginfo_phalcon_queue_adapter_stream_streamcontext_pushmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, ensureDir, arginfo_phalcon_queue_adapter_stream_streamcontext_ensuredir, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Stream_StreamContext, getFilepath, arginfo_phalcon_queue_adapter_stream_streamcontext_getfilepath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
