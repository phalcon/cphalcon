
extern zend_class_entry *phalcon_support_helper_str_interpolate_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Interpolate);

PHP_METHOD(Phalcon_Support_Helper_Str_Interpolate, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_interpolate___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, leftToken, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, rightToken, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_interpolate_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Interpolate, __invoke, arginfo_phalcon_support_helper_str_interpolate___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
