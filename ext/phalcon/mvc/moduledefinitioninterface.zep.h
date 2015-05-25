
extern zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerautoloaders, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_moduledefinitioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders, arginfo_phalcon_mvc_moduledefinitioninterface_registerautoloaders)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerServices, arginfo_phalcon_mvc_moduledefinitioninterface_registerservices)
	PHP_FE_END
};
