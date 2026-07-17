
extern zend_class_entry *phalcon_traits_support_helper_arr_filtertrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Arr_FilterTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Arr_FilterTrait, toFilter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_arr_filtertrait_tofilter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_arr_filtertrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Arr_FilterTrait, toFilter, arginfo_phalcon_traits_support_helper_arr_filtertrait_tofilter, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
