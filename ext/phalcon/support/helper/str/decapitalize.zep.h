
extern zend_class_entry *phalcon_support_helper_str_decapitalize_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Decapitalize);

PHP_METHOD(Phalcon_Support_Helper_Str_Decapitalize, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_Decapitalize, toLower);
PHP_METHOD(Phalcon_Support_Helper_Str_Decapitalize, toUpper);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_decapitalize___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, upperRest, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_decapitalize_tolower, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_decapitalize_toupper, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_decapitalize_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Decapitalize, __invoke, arginfo_phalcon_support_helper_str_decapitalize___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_Decapitalize, toLower, arginfo_phalcon_support_helper_str_decapitalize_tolower, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Support_Helper_Str_Decapitalize, toUpper, arginfo_phalcon_support_helper_str_decapitalize_toupper, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
