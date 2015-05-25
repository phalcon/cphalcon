
extern zend_class_entry *phalcon_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher);

PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__throwdispatchexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, exceptionCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcher_method_entry) {
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcher_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, _throwDispatchException, arginfo_phalcon_mvc_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, _handleException, arginfo_phalcon_mvc_dispatcher__handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getLastController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getActiveController, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
