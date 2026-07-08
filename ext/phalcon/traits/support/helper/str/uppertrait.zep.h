
extern zend_class_entry *phalcon_traits_support_helper_str_uppertrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_UpperTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_UpperTrait, toUpper);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_uppertrait_toupper, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 0, "'UTF-8'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_uppertrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_UpperTrait, toUpper, arginfo_phalcon_traits_support_helper_str_uppertrait_toupper, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
