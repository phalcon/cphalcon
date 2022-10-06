
extern zend_class_entry *phalcon_filter_sanitize_stringval_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_StringVal);

PHP_METHOD(Phalcon_Filter_Sanitize_StringVal, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_sanitize_stringval___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_stringval_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_StringVal, __invoke, arginfo_phalcon_filter_sanitize_stringval___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
