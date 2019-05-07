
extern zend_class_entry *phalcon_filter_sanitize_replace_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Replace);

PHP_METHOD(Phalcon_Filter_Sanitize_Replace, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_replace___invoke, 0, 0, 3)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, to)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_replace_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Replace, __invoke, arginfo_phalcon_filter_sanitize_replace___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
