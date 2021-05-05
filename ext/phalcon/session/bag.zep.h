
extern zend_class_entry *phalcon_session_bag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Bag);

PHP_METHOD(Phalcon_Session_Bag, __construct);
PHP_METHOD(Phalcon_Session_Bag, clear);
PHP_METHOD(Phalcon_Session_Bag, getDI);
PHP_METHOD(Phalcon_Session_Bag, init);
PHP_METHOD(Phalcon_Session_Bag, remove);
PHP_METHOD(Phalcon_Session_Bag, set);
PHP_METHOD(Phalcon_Session_Bag, setDI);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_bag_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_session_bag_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_bag_init, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_bag_remove, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_bag_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_session_bag_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_bag_method_entry) {
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Bag, clear, arginfo_phalcon_session_bag_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getDI, arginfo_phalcon_session_bag_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, init, arginfo_phalcon_session_bag_init, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, remove, arginfo_phalcon_session_bag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_bag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_session_bag_setdi, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
