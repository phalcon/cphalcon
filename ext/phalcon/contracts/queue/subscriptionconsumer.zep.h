
extern zend_class_entry *phalcon_contracts_queue_subscriptionconsumer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_SubscriptionConsumer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_subscriptionconsumer_consume, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, timeout, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_subscriptionconsumer_subscribe, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, consumer, Phalcon\\Contracts\\Queue\\Consumer, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_subscriptionconsumer_unsubscribe, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, consumer, Phalcon\\Contracts\\Queue\\Consumer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_subscriptionconsumer_unsubscribeall, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_subscriptionconsumer_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_SubscriptionConsumer, consume, arginfo_phalcon_contracts_queue_subscriptionconsumer_consume)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_SubscriptionConsumer, subscribe, arginfo_phalcon_contracts_queue_subscriptionconsumer_subscribe)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_SubscriptionConsumer, unsubscribe, arginfo_phalcon_contracts_queue_subscriptionconsumer_unsubscribe)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_SubscriptionConsumer, unsubscribeAll, arginfo_phalcon_contracts_queue_subscriptionconsumer_unsubscribeall)
	PHP_FE_END
};
