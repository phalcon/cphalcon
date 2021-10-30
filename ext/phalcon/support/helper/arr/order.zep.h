
extern zend_class_entry *phalcon_support_helper_arr_order_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Order);

PHP_METHOD(Phalcon_Support_Helper_Arr_Order, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Order, checkObject);
PHP_METHOD(Phalcon_Support_Helper_Arr_Order, checkNonObject);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_order___invoke, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_TYPE_INFO(0, order, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_order_checkobject, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, sorted, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_order_checknonobject, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, sorted, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_order_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Order, __invoke, arginfo_phalcon_support_helper_arr_order___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Order, checkObject, arginfo_phalcon_support_helper_arr_order_checkobject, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Order, checkNonObject, arginfo_phalcon_support_helper_arr_order_checknonobject, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
