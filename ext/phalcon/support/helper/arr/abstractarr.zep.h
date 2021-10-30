
extern zend_class_entry *phalcon_support_helper_arr_abstractarr_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_AbstractArr);

PHP_METHOD(Phalcon_Support_Helper_Arr_AbstractArr, toFilter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_abstractarr_tofilter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_abstractarr_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_AbstractArr, toFilter, arginfo_phalcon_support_helper_arr_abstractarr_tofilter, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
