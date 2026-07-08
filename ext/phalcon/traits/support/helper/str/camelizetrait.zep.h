
extern zend_class_entry *phalcon_traits_support_helper_str_camelizetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_CamelizeTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_CamelizeTrait, staticToCamelize);
PHP_METHOD(Phalcon_Traits_Support_Helper_Str_CamelizeTrait, toCamelize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_camelizetrait_statictocamelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, delimiters, IS_STRING, 0, "'-_'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowerFirst, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_camelizetrait_tocamelize, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, delimiters, IS_STRING, 0, "'-_'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, lowerFirst, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_camelizetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_CamelizeTrait, staticToCamelize, arginfo_phalcon_traits_support_helper_str_camelizetrait_statictocamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Support_Helper_Str_CamelizeTrait, toCamelize, arginfo_phalcon_traits_support_helper_str_camelizetrait_tocamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
