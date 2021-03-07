
extern zend_class_entry *phalcon_di_factorydefault_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault);

PHP_METHOD(Phalcon_Di_FactoryDefault, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_factorydefault___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_factorydefault_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Di_FactoryDefault, __construct, arginfo_phalcon_di_factorydefault___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Di_FactoryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_FE_END
};
