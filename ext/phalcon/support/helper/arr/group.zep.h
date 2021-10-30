
extern zend_class_entry *phalcon_support_helper_arr_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Group);

PHP_METHOD(Phalcon_Support_Helper_Arr_Group, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, isCallable);
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processCallable);
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processObject);
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processOther);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_group___invoke, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_group_iscallable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_group_processcallable, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, filtered, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_group_processobject, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, filtered, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_arr_group_processother, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, filtered, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_group_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_Group, __invoke, arginfo_phalcon_support_helper_arr_group___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Arr_Group, isCallable, arginfo_phalcon_support_helper_arr_group_iscallable, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Group, processCallable, arginfo_phalcon_support_helper_arr_group_processcallable, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Group, processObject, arginfo_phalcon_support_helper_arr_group_processobject, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Arr_Group, processOther, arginfo_phalcon_support_helper_arr_group_processother, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
