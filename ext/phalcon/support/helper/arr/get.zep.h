
extern zend_class_entry *phalcon_support_helper_arr_get_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Get);

PHP_METHOD(Phalcon_Support_Helper_Arr_Get, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helper_arr_get___invoke, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_get_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Get, __invoke, arginfo_phalcon_support_helper_arr_get___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
