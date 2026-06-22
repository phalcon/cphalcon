
extern zend_class_entry *phalcon_queue_consumer_workeroptions_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_WorkerOptions);

PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, __construct);
PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getJitter);
PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxMemory);
PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxMessages);
PHP_METHOD(Phalcon_Queue_Consumer_WorkerOptions, getMaxSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_consumer_workeroptions___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMessages, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxSeconds, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, maxMemory, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, jitter, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_workeroptions_getjitter, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_workeroptions_getmaxmemory, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_workeroptions_getmaxmessages, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_workeroptions_getmaxseconds, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_consumer_workeroptions_method_entry) {
	PHP_ME(Phalcon_Queue_Consumer_WorkerOptions, __construct, arginfo_phalcon_queue_consumer_workeroptions___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Consumer_WorkerOptions, getJitter, arginfo_phalcon_queue_consumer_workeroptions_getjitter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_WorkerOptions, getMaxMemory, arginfo_phalcon_queue_consumer_workeroptions_getmaxmemory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_WorkerOptions, getMaxMessages, arginfo_phalcon_queue_consumer_workeroptions_getmaxmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_WorkerOptions, getMaxSeconds, arginfo_phalcon_queue_consumer_workeroptions_getmaxseconds, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
