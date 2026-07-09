
extern zend_class_entry *phalcon_support_helper_str_upper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Upper);

PHP_METHOD(Phalcon_Support_Helper_Str_Upper, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_Upper, toUpper);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_upper___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_upper_toupper, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_upper_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Upper, __invoke, arginfo_phalcon_support_helper_str_upper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_Upper, toUpper, arginfo_phalcon_support_helper_str_upper_toupper, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
