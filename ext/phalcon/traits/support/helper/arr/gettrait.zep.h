
extern zend_class_entry *phalcon_traits_support_helper_arr_gettrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Arr_GetTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Arr_GetTrait, getArrVal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_support_helper_arr_gettrait_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cast, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_arr_gettrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Arr_GetTrait, getArrVal, arginfo_phalcon_traits_support_helper_arr_gettrait_getarrval, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
