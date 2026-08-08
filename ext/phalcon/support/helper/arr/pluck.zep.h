
extern zend_class_entry *phalcon_support_helper_arr_pluck_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Pluck);

PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, checkArray);
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, checkObject);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_pluck___invoke, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_pluck_checkarray, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, filtered, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_pluck_checkobject, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, filtered, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_pluck_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Pluck, __invoke, arginfo_phalcon_support_helper_arr_pluck___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Pluck, checkArray, arginfo_phalcon_support_helper_arr_pluck_checkarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Pluck, checkObject, arginfo_phalcon_support_helper_arr_pluck_checkobject, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
