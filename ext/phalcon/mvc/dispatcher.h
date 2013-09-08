
extern zend_class_entry *phalcon_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher);

PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, 0, 0, 0)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, 0, 0, 0)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 0)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcher_method_entry) {
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcher_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
