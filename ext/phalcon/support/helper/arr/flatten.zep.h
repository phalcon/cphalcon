
extern zend_class_entry *phalcon_support_helper_arr_flatten_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Flatten);

PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processNotArray);
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processArray);
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processArrayDeep);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_flatten___invoke, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_flatten_processnotarray, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_flatten_processarray, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_flatten_processarraydeep, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_flatten_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Flatten, __invoke, arginfo_phalcon_support_helper_arr_flatten___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Flatten, processNotArray, arginfo_phalcon_support_helper_arr_flatten_processnotarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Flatten, processArray, arginfo_phalcon_support_helper_arr_flatten_processarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Flatten, processArrayDeep, arginfo_phalcon_support_helper_arr_flatten_processarraydeep, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
