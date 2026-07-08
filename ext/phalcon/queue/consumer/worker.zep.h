
extern zend_class_entry *phalcon_queue_consumer_worker_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Consumer_Worker);

PHP_METHOD(Phalcon_Queue_Consumer_Worker, __construct);
PHP_METHOD(Phalcon_Queue_Consumer_Worker, handleSignal);
PHP_METHOD(Phalcon_Queue_Consumer_Worker, run);
PHP_METHOD(Phalcon_Queue_Consumer_Worker, installSignalHandlers);
PHP_METHOD(Phalcon_Queue_Consumer_Worker, phpExtensionLoaded);
PHP_METHOD(Phalcon_Queue_Consumer_Worker, phpFunctionExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_consumer_worker___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, consumer, Phalcon\\Queue\\Consumer\\QueueConsumer, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, options, Phalcon\\Queue\\Consumer\\WorkerOptions, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_worker_handlesignal, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, signal, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_worker_run, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_worker_installsignalhandlers, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_worker_phpextensionloaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_consumer_worker_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_consumer_worker_method_entry) {
	PHP_ME(Phalcon_Queue_Consumer_Worker, __construct, arginfo_phalcon_queue_consumer_worker___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Consumer_Worker, handleSignal, arginfo_phalcon_queue_consumer_worker_handlesignal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_Worker, run, arginfo_phalcon_queue_consumer_worker_run, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Consumer_Worker, installSignalHandlers, arginfo_phalcon_queue_consumer_worker_installsignalhandlers, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Consumer_Worker, phpExtensionLoaded, arginfo_phalcon_queue_consumer_worker_phpextensionloaded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Queue_Consumer_Worker, phpFunctionExists, arginfo_phalcon_queue_consumer_worker_phpfunctionexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
