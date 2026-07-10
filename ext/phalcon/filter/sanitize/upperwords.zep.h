
extern zend_class_entry *phalcon_filter_sanitize_upperwords_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_UpperWords);

PHP_METHOD(Phalcon_Filter_Sanitize_UpperWords, __invoke);
PHP_METHOD(Phalcon_Filter_Sanitize_UpperWords, phpMbConvertCase);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_upperwords___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_sanitize_upperwords_phpmbconvertcase, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_upperwords_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_UpperWords, __invoke, arginfo_phalcon_filter_sanitize_upperwords___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Sanitize_UpperWords, phpMbConvertCase, arginfo_phalcon_filter_sanitize_upperwords_phpmbconvertcase, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
