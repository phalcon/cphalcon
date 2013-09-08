
extern zend_class_entry *phalcon_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter);

PHP_METHOD(Phalcon_Filter, add);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_add, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_method_entry) {
	PHP_ME(Phalcon_Filter, add, arginfo_phalcon_filter_add, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
