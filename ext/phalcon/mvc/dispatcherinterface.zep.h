
extern zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerSuffix)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getcontrollername, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getcontrollername, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getlastcontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getlastcontroller, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ControllerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getactivecontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_getactivecontroller, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ControllerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, arginfo_phalcon_mvc_dispatcherinterface_getcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, arginfo_phalcon_mvc_dispatcherinterface_getlastcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, arginfo_phalcon_mvc_dispatcherinterface_getactivecontroller)
	PHP_FE_END
};
