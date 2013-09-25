
extern zend_class_entry *phalcon_di_factorydefault_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault);

PHP_METHOD(Phalcon_Di_FactoryDefault, __construct);

ZEPHIR_INIT_FUNCS(phalcon_di_factorydefault_method_entry) {
	PHP_ME(Phalcon_Di_FactoryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
