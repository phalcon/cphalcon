
extern zend_class_entry *phalcon_filter_sanitize_upper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Upper);

PHP_METHOD(Phalcon_Filter_Sanitize_Upper, __invoke);
PHP_METHOD(Phalcon_Filter_Sanitize_Upper, phpMbConvertCase);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_upper___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_sanitize_upper_phpmbconvertcase, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fallback, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_upper_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Upper, __invoke, arginfo_phalcon_filter_sanitize_upper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Sanitize_Upper, phpMbConvertCase, arginfo_phalcon_filter_sanitize_upper_phpmbconvertcase, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
