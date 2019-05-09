
extern zend_class_entry *phalcon_factory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Factory);

PHP_METHOD(Phalcon_Factory, loadClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_factory_loadclass, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, namespaceClass, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, namespaceClass)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_factory_method_entry) {
	PHP_ME(Phalcon_Factory, loadClass, arginfo_phalcon_factory_loadclass, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
