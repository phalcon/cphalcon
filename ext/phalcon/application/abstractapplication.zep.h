
extern zend_class_entry *phalcon_application_abstractapplication_ce;

ZEPHIR_INIT_CLASS(Phalcon_Application_AbstractApplication);

PHP_METHOD(Phalcon_Application_AbstractApplication, __construct);
PHP_METHOD(Phalcon_Application_AbstractApplication, getDefaultModule);
PHP_METHOD(Phalcon_Application_AbstractApplication, getEventsManager);
PHP_METHOD(Phalcon_Application_AbstractApplication, getModule);
PHP_METHOD(Phalcon_Application_AbstractApplication, getModules);
PHP_METHOD(Phalcon_Application_AbstractApplication, registerModules);
PHP_METHOD(Phalcon_Application_AbstractApplication, setDefaultModule);
PHP_METHOD(Phalcon_Application_AbstractApplication, setEventsManager);
zend_object *zephir_init_properties_Phalcon_Application_AbstractApplication(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_abstractapplication___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_getdefaultmodule, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_getdefaultmodule, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_application_abstractapplication_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_abstractapplication_getmodule, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_getmodules, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_getmodules, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_application_abstractapplication_registermodules, 0, 1, Phalcon\\Application\\AbstractApplication, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_registermodules, 0, 1, IS_OBJECT, "Phalcon\\Application\\AbstractApplication", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, merge)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_application_abstractapplication_setdefaultmodule, 0, 1, Phalcon\\Application\\AbstractApplication, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_setdefaultmodule, 0, 1, IS_OBJECT, "Phalcon\\Application\\AbstractApplication", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultModule, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, defaultModule)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_application_abstractapplication_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_abstractapplication_seteventsmanager, 0, 0, 1)
#define arginfo_phalcon_application_abstractapplication_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_abstractapplication_zephir_init_properties_phalcon_application_abstractapplication, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_application_abstractapplication_method_entry) {
	PHP_ME(Phalcon_Application_AbstractApplication, __construct, arginfo_phalcon_application_abstractapplication___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Application_AbstractApplication, getDefaultModule, arginfo_phalcon_application_abstractapplication_getdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, getEventsManager, arginfo_phalcon_application_abstractapplication_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, getModule, arginfo_phalcon_application_abstractapplication_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, getModules, arginfo_phalcon_application_abstractapplication_getmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, registerModules, arginfo_phalcon_application_abstractapplication_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, setDefaultModule, arginfo_phalcon_application_abstractapplication_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application_AbstractApplication, setEventsManager, arginfo_phalcon_application_abstractapplication_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
