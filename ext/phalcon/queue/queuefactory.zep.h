
extern zend_class_entry *phalcon_queue_queuefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_QueueFactory);

PHP_METHOD(Phalcon_Queue_QueueFactory, __construct);
PHP_METHOD(Phalcon_Queue_QueueFactory, load);
PHP_METHOD(Phalcon_Queue_QueueFactory, newInstance);
PHP_METHOD(Phalcon_Queue_QueueFactory, getExceptionClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_queuefactory___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, factory, Phalcon\\Queue\\AdapterFactory, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_queuefactory_load, 0, 1, Phalcon\\Contracts\\Queue\\Context, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_queuefactory_newinstance, 0, 1, Phalcon\\Contracts\\Queue\\Context, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_queuefactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_queuefactory_method_entry) {
	PHP_ME(Phalcon_Queue_QueueFactory, __construct, arginfo_phalcon_queue_queuefactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_QueueFactory, load, arginfo_phalcon_queue_queuefactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_QueueFactory, newInstance, arginfo_phalcon_queue_queuefactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_QueueFactory, getExceptionClass, arginfo_phalcon_queue_queuefactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
