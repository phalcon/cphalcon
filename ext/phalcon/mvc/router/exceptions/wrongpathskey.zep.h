
extern zend_class_entry *phalcon_mvc_router_exceptions_wrongpathskey_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Exceptions_WrongPathsKey);

PHP_METHOD(Phalcon_Mvc_Router_Exceptions_WrongPathsKey, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_exceptions_wrongpathskey___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, part, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_exceptions_wrongpathskey_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Exceptions_WrongPathsKey, __construct, arginfo_phalcon_mvc_router_exceptions_wrongpathskey___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
