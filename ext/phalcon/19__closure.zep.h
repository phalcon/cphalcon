
extern zend_class_entry *phalcon_19__closure_ce;

ZEPHIR_INIT_CLASS(phalcon_19__closure);

PHP_METHOD(phalcon_19__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_19__closure___invoke, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_19__closure_method_entry) {
	PHP_ME(phalcon_19__closure, __invoke, arginfo_phalcon_19__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
