
extern zend_class_entry *phalcon_support_helper_str_concat_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Concat);

PHP_METHOD(Phalcon_Support_Helper_Str_Concat, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_Concat, toEndsWith);
PHP_METHOD(Phalcon_Support_Helper_Str_Concat, toStartsWith);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_concat___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, many, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_concat_toendswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ignoreCase, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_concat_tostartswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ignoreCase, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_concat_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Concat, __invoke, arginfo_phalcon_support_helper_str_concat___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_Concat, toEndsWith, arginfo_phalcon_support_helper_str_concat_toendswith, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Support_Helper_Str_Concat, toStartsWith, arginfo_phalcon_support_helper_str_concat_tostartswith, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
