
extern zend_class_entry *phalcon_contracts_queue_processor_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Processor);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_queue_processor_process, 0, 2, MAY_BE_STRING|MAY_BE_OBJECT)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Contracts\\Queue\\Message, 0)
	ZEND_ARG_OBJ_INFO(0, context, Phalcon\\Contracts\\Queue\\Context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_queue_processor_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Queue_Processor, process, arginfo_phalcon_contracts_queue_processor_process)
	PHP_FE_END
};
