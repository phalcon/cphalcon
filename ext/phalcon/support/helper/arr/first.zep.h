
extern zend_class_entry *phalcon_support_helper_arr_first_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_First);

PHP_METHOD(Phalcon_Support_Helper_Arr_First, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helper_arr_first___invoke, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_first_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_First, __invoke, arginfo_phalcon_support_helper_arr_first___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
