
extern zend_class_entry *phalcon_di_injectable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable);

PHP_METHOD(Phalcon_Di_Injectable, __get);
PHP_METHOD(Phalcon_Di_Injectable, __isset);
PHP_METHOD(Phalcon_Di_Injectable, getDI);
PHP_METHOD(Phalcon_Di_Injectable, setDI);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, propertyName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_injectable___isset, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_injectable_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectable_method_entry) {
	PHP_ME(Phalcon_Di_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, __isset, arginfo_phalcon_di_injectable___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, getDI, arginfo_phalcon_di_injectable_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
