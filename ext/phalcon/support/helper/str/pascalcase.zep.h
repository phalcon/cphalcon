
extern zend_class_entry *phalcon_support_helper_str_pascalcase_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_PascalCase);

PHP_METHOD(Phalcon_Support_Helper_Str_PascalCase, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_PascalCase, processArray);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_pascalcase___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, delimiters, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_pascalcase_processarray, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, delimiters, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_pascalcase_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_PascalCase, __invoke, arginfo_phalcon_support_helper_str_pascalcase___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_PascalCase, processArray, arginfo_phalcon_support_helper_str_pascalcase_processarray, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
