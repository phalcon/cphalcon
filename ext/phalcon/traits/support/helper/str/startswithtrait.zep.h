
extern zend_class_entry *phalcon_traits_support_helper_str_startswithtrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_StartsWithTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_StartsWithTrait, toStartsWith);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_startswithtrait_tostartswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ignoreCase, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_startswithtrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_StartsWithTrait, toStartsWith, arginfo_phalcon_traits_support_helper_str_startswithtrait_tostartswith, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
