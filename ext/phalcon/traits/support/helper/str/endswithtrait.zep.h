
extern zend_class_entry *phalcon_traits_support_helper_str_endswithtrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_EndsWithTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_EndsWithTrait, toEndsWith);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_endswithtrait_toendswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ignoreCase, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_endswithtrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_EndsWithTrait, toEndsWith, arginfo_phalcon_traits_support_helper_str_endswithtrait_toendswith, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
