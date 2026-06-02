
extern zend_class_entry *phalcon_container_definition_processor_processor_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Definition_Processor_Processor);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_definition_processor_processor_canprocess, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_definition_processor_processor_process, 0, 3, Phalcon\\Container\\Definition\\ServiceDefinition, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_definition_processor_processor_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Container_Definition_Processor_Processor, canProcess, arginfo_phalcon_container_definition_processor_processor_canprocess)
	PHP_ABSTRACT_ME(Phalcon_Container_Definition_Processor_Processor, process, arginfo_phalcon_container_definition_processor_processor_process)
	PHP_FE_END
};
