
extern zend_class_entry *phalcon_session_bag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Bag);

PHP_METHOD(Phalcon_Session_Bag, __construct);
PHP_METHOD(Phalcon_Session_Bag, setDI);
PHP_METHOD(Phalcon_Session_Bag, getDI);
PHP_METHOD(Phalcon_Session_Bag, initialize);
PHP_METHOD(Phalcon_Session_Bag, destroy);
PHP_METHOD(Phalcon_Session_Bag, set);
PHP_METHOD(Phalcon_Session_Bag, __set);
PHP_METHOD(Phalcon_Session_Bag, get);
PHP_METHOD(Phalcon_Session_Bag, __get);
PHP_METHOD(Phalcon_Session_Bag, has);
PHP_METHOD(Phalcon_Session_Bag, __isset);
PHP_METHOD(Phalcon_Session_Bag, remove);
PHP_METHOD(Phalcon_Session_Bag, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_setdi, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_bag_method_entry) {
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_session_bag_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_bag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __set, arginfo_phalcon_session_bag___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, get, arginfo_phalcon_session_bag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __get, arginfo_phalcon_session_bag___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, has, arginfo_phalcon_session_bag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __isset, arginfo_phalcon_session_bag___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, remove, arginfo_phalcon_session_bag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __unset, arginfo_phalcon_session_bag___unset, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
