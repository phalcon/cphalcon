
extern zend_class_entry *phalcon_queue_adapter_redis_rediscontext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Redis_RedisContext);

PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, __construct);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, blockingPop);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, close);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createProducer);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, createSubscriptionConsumer);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, popMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, purgeQueue);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, pushMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, buildMessage);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, delayedKey);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, listKey);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, now);
PHP_METHOD(Phalcon_Queue_Adapter_Redis_RedisContext, promote);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "'phalcon_queue:'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, pollInterval, IS_LONG, 0, "200")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_blockingpop, 0, 2, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_close, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_createconsumer, 0, 1, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_OBJ_INFO(0, destination, Phalcon\\Contracts\\Queue\\Destination, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_createmessage, 0, 0, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, body, IS_STRING, 0, "''")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, properties, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, headers, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_createproducer, 0, 0, Phalcon\\Contracts\\Queue\\Producer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_createsubscriptionconsumer, 0, 0, Phalcon\\Contracts\\Queue\\SubscriptionConsumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_popmessage, 0, 1, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_purgequeue, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_pushmessage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, delay, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_buildmessage, 0, 1, Phalcon\\Contracts\\Queue\\Message, 1)
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_delayedkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_listkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_now, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_queue_adapter_redis_rediscontext_promote, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, queueName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_adapter_redis_rediscontext_method_entry) {
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, __construct, arginfo_phalcon_queue_adapter_redis_rediscontext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, blockingPop, arginfo_phalcon_queue_adapter_redis_rediscontext_blockingpop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, close, arginfo_phalcon_queue_adapter_redis_rediscontext_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, createConsumer, arginfo_phalcon_queue_adapter_redis_rediscontext_createconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, createMessage, arginfo_phalcon_queue_adapter_redis_rediscontext_createmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, createProducer, arginfo_phalcon_queue_adapter_redis_rediscontext_createproducer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, createSubscriptionConsumer, arginfo_phalcon_queue_adapter_redis_rediscontext_createsubscriptionconsumer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, popMessage, arginfo_phalcon_queue_adapter_redis_rediscontext_popmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, purgeQueue, arginfo_phalcon_queue_adapter_redis_rediscontext_purgequeue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, pushMessage, arginfo_phalcon_queue_adapter_redis_rediscontext_pushmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, buildMessage, arginfo_phalcon_queue_adapter_redis_rediscontext_buildmessage, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, delayedKey, arginfo_phalcon_queue_adapter_redis_rediscontext_delayedkey, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, listKey, arginfo_phalcon_queue_adapter_redis_rediscontext_listkey, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, now, arginfo_phalcon_queue_adapter_redis_rediscontext_now, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Queue_Adapter_Redis_RedisContext, promote, arginfo_phalcon_queue_adapter_redis_rediscontext_promote, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
