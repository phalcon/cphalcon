
extern zend_class_entry *phalcon_queue_adapter_beanstalk_beanstalkcontext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext);

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, close);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createProducer);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createSubscriptionConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getTtr);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, purgeQueue);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, putMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getConnection);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, newConnection);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, host, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, port, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, persistent, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ttr, IS_LONG, 0, "86400")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pollInterval, IS_LONG, 0, "200")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createconsumer, 0, 1, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createmessage, 0, 0, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createproducer, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createsubscriptionconsumer, 0, 0, Phalcon\\Contracts\\Queue\\SubscriptionConsumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_getttr, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_purgequeue, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_putmessage, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, tube, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ttr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_getconnection, 0, 0, Phalcon\\Queue\\Adapter\\Beanstalk\\BeanstalkConnection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_newconnection, 0, 0, Phalcon\\Queue\\Adapter\\Beanstalk\\BeanstalkConnection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_beanstalk_beanstalkcontext_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, __construct, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, close, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createConsumer, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createMessage, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createProducer, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createproducer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, createSubscriptionConsumer, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_createsubscriptionconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getTtr, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_getttr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, purgeQueue, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_purgequeue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, putMessage, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_putmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, getConnection, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_getconnection, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkContext, newConnection, arginfo_phalcon_queue_adapter_beanstalk_beanstalkcontext_newconnection, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
