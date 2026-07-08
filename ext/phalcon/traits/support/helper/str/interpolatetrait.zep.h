
extern zend_class_entry *phalcon_traits_support_helper_str_interpolatetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_InterpolateTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Str_InterpolateTrait, toInterpolate);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_str_interpolatetrait_tointerpolate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, left, IS_STRING, 0, "'%'")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, right, IS_STRING, 0, "'%'")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_str_interpolatetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Str_InterpolateTrait, toInterpolate, arginfo_phalcon_traits_support_helper_str_interpolatetrait_tointerpolate, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
