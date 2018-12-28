
extern zend_class_entry *phalcon_di_injectable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable);

PHP_METHOD(Phalcon_Di_Injectable, setDI);
PHP_METHOD(Phalcon_Di_Injectable, getDI);
PHP_METHOD(Phalcon_Di_Injectable, setEventsManager);
PHP_METHOD(Phalcon_Di_Injectable, getEventsManager);
PHP_METHOD(Phalcon_Di_Injectable, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_injectable_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_injectable_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_injectable_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_injectable_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, propertyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, propertyName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectable_method_entry) {
	PHP_ME(Phalcon_Di_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, getDI, arginfo_phalcon_di_injectable_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, setEventsManager, arginfo_phalcon_di_injectable_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, getEventsManager, arginfo_phalcon_di_injectable_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
