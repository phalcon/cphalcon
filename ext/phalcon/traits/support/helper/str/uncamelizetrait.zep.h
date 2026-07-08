
extern zend_class_entry *phalcon_traits_support_helper_str_uncamelizetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_UncamelizeTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_UncamelizeTrait, toUncamelize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_uncamelizetrait_touncamelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, delimiter, IS_STRING, 0, "'_'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_uncamelizetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_UncamelizeTrait, toUncamelize, arginfo_phalcon_traits_support_helper_str_uncamelizetrait_touncamelize, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
