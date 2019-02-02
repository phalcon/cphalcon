
extern zend_class_entry *phalcon_filter_sanitize_regex_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Regex);

PHP_METHOD(Phalcon_Filter_Sanitize_Regex, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_regex___invoke, 0, 0, 3)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_regex_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Regex, __invoke, arginfo_phalcon_filter_sanitize_regex___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
