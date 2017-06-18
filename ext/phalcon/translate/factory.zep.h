
extern zend_class_entry *phalcon_translate_factory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Factory);

PHP_METHOD(Phalcon_Translate_Factory, load);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_factory_load, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_factory_method_entry) {
	PHP_ME(Phalcon_Translate_Factory, load, arginfo_phalcon_translate_factory_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
