
extern zend_class_entry *phalcon_factoryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_factoryinterface_load, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_factoryinterface_method_entry) {
	ZEND_FENTRY(load, NULL, arginfo_phalcon_factoryinterface_load, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
