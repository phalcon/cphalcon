
extern zend_class_entry *phalcon_support_helper_str_startswith_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_StartsWith);

PHP_METHOD(Phalcon_Support_Helper_Str_StartsWith, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_startswith___invoke, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ignoreCase, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_startswith_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_StartsWith, __invoke, arginfo_phalcon_support_helper_str_startswith___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
