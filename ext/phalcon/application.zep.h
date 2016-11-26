
extern zend_class_entry *phalcon_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Application);

PHP_METHOD(Phalcon_Application, __construct);
PHP_METHOD(Phalcon_Application, setEventsManager);
PHP_METHOD(Phalcon_Application, getEventsManager);
PHP_METHOD(Phalcon_Application, registerModules);
PHP_METHOD(Phalcon_Application, getModules);
PHP_METHOD(Phalcon_Application, getModule);
PHP_METHOD(Phalcon_Application, setDefaultModule);
PHP_METHOD(Phalcon_Application, getDefaultModule);
PHP_METHOD(Phalcon_Application, handle);
zend_object_value zephir_init_properties_Phalcon_Application(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_getmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_application_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_application_method_entry) {
	PHP_ME(Phalcon_Application, __construct, arginfo_phalcon_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Application, setEventsManager, arginfo_phalcon_application_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, registerModules, arginfo_phalcon_application_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, getModule, arginfo_phalcon_application_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, setDefaultModule, arginfo_phalcon_application_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Application, handle, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
