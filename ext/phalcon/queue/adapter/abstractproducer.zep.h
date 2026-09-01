
extern zend_class_entry *phalcon_queue_adapter_abstractproducer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_AbstractProducer);

PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getDeliveryDelay);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getPriority);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, getTimeToLive);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, send);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setDeliveryDelay);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setPriority);
PHP_METHOD(Phalcon_Queue_Adapter_AbstractProducer, setTimeToLive);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_getdeliverydelay, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_getpriority, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_gettimetolive, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_send, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_setdeliverydelay, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, deliveryDelay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_setpriority, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_abstractproducer_settimetolive, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, timeToLive)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_abstractproducer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, getDeliveryDelay, arginfo_phalcon_queue_adapter_abstractproducer_getdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, getPriority, arginfo_phalcon_queue_adapter_abstractproducer_getpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, getTimeToLive, arginfo_phalcon_queue_adapter_abstractproducer_gettimetolive, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, send, arginfo_phalcon_queue_adapter_abstractproducer_send, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, setDeliveryDelay, arginfo_phalcon_queue_adapter_abstractproducer_setdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, setPriority, arginfo_phalcon_queue_adapter_abstractproducer_setpriority, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_AbstractProducer, setTimeToLive, arginfo_phalcon_queue_adapter_abstractproducer_settimetolive, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
