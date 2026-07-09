
extern zend_class_entry *phalcon_support_helper_arr_whitelist_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Whitelist);

PHP_METHOD(Phalcon_Support_Helper_Arr_Whitelist, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Whitelist, toFilter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_whitelist___invoke, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_ARRAY_INFO(0, whiteList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_whitelist_tofilter, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_whitelist_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Whitelist, __invoke, arginfo_phalcon_support_helper_arr_whitelist___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Whitelist, toFilter, arginfo_phalcon_support_helper_arr_whitelist_tofilter, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
