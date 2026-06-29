
extern zend_class_entry *phalcon_contracts_queue_inspectable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Inspectable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_queue_inspectable_getstats, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, queue, Phalcon\\Contracts\\Queue\\Queue, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_inspectable_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Inspectable, getStats, arginfo_phalcon_contracts_queue_inspectable_getstats)
	PHP_FE_END
};
