
extern zend_class_entry *phalcon_mvc_router_defaultvalue_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_DefaultValue);

PHP_METHOD(Phalcon_Mvc_Router_DefaultValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_defaultvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_defaultvalue_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_DefaultValue, __construct, arginfo_phalcon_mvc_router_defaultvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
