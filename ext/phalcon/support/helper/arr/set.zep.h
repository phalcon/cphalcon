
extern zend_class_entry *phalcon_support_helper_arr_set_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Set);

PHP_METHOD(Phalcon_Support_Helper_Arr_Set, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Set, checkNull);
PHP_METHOD(Phalcon_Support_Helper_Arr_Set, checkNotNull);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_set___invoke, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_set_checknull, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_set_checknotnull, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_set_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Set, __invoke, arginfo_phalcon_support_helper_arr_set___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Set, checkNull, arginfo_phalcon_support_helper_arr_set_checknull, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Set, checkNotNull, arginfo_phalcon_support_helper_arr_set_checknotnull, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
