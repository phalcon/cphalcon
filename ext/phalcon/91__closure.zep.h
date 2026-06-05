
extern zend_class_entry *phalcon_91__closure_ce;

ZEPHIR_INIT_CLASS(phalcon_91__closure);

PHP_METHOD(phalcon_91__closure, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_91__closure___invoke, 0, 0, 4)
	ZEND_ARG_INFO(0, number)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_91__closure_method_entry) {
	PHP_ME(phalcon_91__closure, __invoke, arginfo_phalcon_91__closure___invoke, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};
