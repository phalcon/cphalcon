
extern zend_class_entry *phalcon_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher);

PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousNamespaceName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, forward);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerSuffix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerSuffix)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, controllerName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getcontrollername, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getcontrollername, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviousnamespacename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviousnamespacename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviouscontrollername, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviouscontrollername, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviousactionname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getpreviousactionname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__throwdispatchexception, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, exceptionCode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, exceptionCode)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getcontrollerclass, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getcontrollerclass, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_dispatcher_getlastcontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getlastcontroller, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ControllerInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_dispatcher_getactivecontroller, 0, 0, Phalcon\\Mvc\\ControllerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_dispatcher_getactivecontroller, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ControllerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcher_method_entry) {
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcher_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, arginfo_phalcon_mvc_dispatcher_getcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousNamespaceName, arginfo_phalcon_mvc_dispatcher_getpreviousnamespacename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousControllerName, arginfo_phalcon_mvc_dispatcher_getpreviouscontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousActionName, arginfo_phalcon_mvc_dispatcher_getpreviousactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, _throwDispatchException, arginfo_phalcon_mvc_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, _handleException, arginfo_phalcon_mvc_dispatcher__handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, forward, arginfo_phalcon_mvc_dispatcher_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerClass, arginfo_phalcon_mvc_dispatcher_getcontrollerclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getLastController, arginfo_phalcon_mvc_dispatcher_getlastcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getActiveController, arginfo_phalcon_mvc_dispatcher_getactivecontroller, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
