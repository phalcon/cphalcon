
extern zend_class_entry *phalcon_queue_adapter_redis_redisproducer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisProducer);

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, getDeliveryDelay);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, send);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisProducer, setDeliveryDelay);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_redis_redisproducer___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Queue\\Adapter\\Redis\\RedisContext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_redisproducer_getdeliverydelay, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_redisproducer_send, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_redisproducer_setdeliverydelay, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
	ZEND_ARG_INFO(0, deliveryDelay)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_redis_redisproducer_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisProducer, __construct, arginfo_phalcon_queue_adapter_redis_redisproducer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisProducer, getDeliveryDelay, arginfo_phalcon_queue_adapter_redis_redisproducer_getdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisProducer, send, arginfo_phalcon_queue_adapter_redis_redisproducer_send, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisProducer, setDeliveryDelay, arginfo_phalcon_queue_adapter_redis_redisproducer_setdeliverydelay, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
