
extern zend_class_entry *phalcon_queue_adapter_beanstalk_beanstalkconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer);

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, acknowledge);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receive);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receiveNoWait);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, reject);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, touch);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, buildMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, resolveJobId);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Queue\\Adapter\\Beanstalk\\BeanstalkConnection, 0)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_acknowledge, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_receive, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_receivenowait, 0, 0, Phalcon\\Contracts\\Queue\\Message, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_reject, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, requeue, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_touch, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_buildmessage, 0, 1, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_INFO(0, job)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_resolvejobid, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_beanstalk_beanstalkconsumer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, __construct, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, acknowledge, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_acknowledge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receive, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_receive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, receiveNoWait, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_receivenowait, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, reject, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_reject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, touch, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_touch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, buildMessage, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_buildmessage, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConsumer, resolveJobId, arginfo_phalcon_queue_adapter_beanstalk_beanstalkconsumer_resolvejobid, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
