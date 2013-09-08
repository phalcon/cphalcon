
extern zend_class_entry *phalcon_di_injectable_ce;

ZEPHIR_INIT_CLASS(Phalcon_DI_Injectable);

PHP_METHOD(Phalcon_DI_Injectable, setDI);
PHP_METHOD(Phalcon_DI_Injectable, getDI);
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_seteventsmanager, 0, 0, 0)
	ZEND_ARG_INFO(0, eventsManager)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 0)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectable_method_entry) {
	PHP_ME(Phalcon_DI_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, setEventsManager, arginfo_phalcon_di_injectable_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
