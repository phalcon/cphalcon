
extern zend_class_entry *phalcon_contracts_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Mvc_Dispatcher);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_getactivecontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_getcontrollername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_getlastcontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_setcontrollername, 0, 1, Phalcon\\Contracts\\Dispatcher\\Dispatcher, 0)
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_setcontrollersuffix, 0, 1, Phalcon\\Contracts\\Dispatcher\\Dispatcher, 0)
	ZEND_ARG_TYPE_INFO(0, controllerSuffix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_mvc_dispatcher_setdefaultcontroller, 0, 1, Phalcon\\Contracts\\Dispatcher\\Dispatcher, 0)
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_mvc_dispatcher_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, getActiveController, arginfo_phalcon_contracts_mvc_dispatcher_getactivecontroller)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, getControllerName, arginfo_phalcon_contracts_mvc_dispatcher_getcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, getLastController, arginfo_phalcon_contracts_mvc_dispatcher_getlastcontroller)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, setControllerName, arginfo_phalcon_contracts_mvc_dispatcher_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_contracts_mvc_dispatcher_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_contracts_mvc_dispatcher_setdefaultcontroller)
	PHP_FE_END
};
