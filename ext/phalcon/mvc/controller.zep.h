
extern zend_class_entry *phalcon_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller);

PHP_METHOD(Phalcon_Mvc_Controller, __construct);
PHP_METHOD(Phalcon_Mvc_Controller, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Controller, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Controller, fireManagerEvent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_controller___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_controller_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_controller_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_controller_firemanagerevent, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cancellable, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_controller_method_entry) {
PHP_ME(Phalcon_Mvc_Controller, __construct, arginfo_phalcon_mvc_controller___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Controller, getEventsManager, arginfo_phalcon_mvc_controller_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Controller, setEventsManager, arginfo_phalcon_mvc_controller_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Controller, fireManagerEvent, arginfo_phalcon_mvc_controller_firemanagerevent, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
