
extern zend_class_entry *phalcon_support_helper_arr_toobject_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_ToObject);

PHP_METHOD(Phalcon_Support_Helper_Arr_ToObject, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_support_helper_arr_toobject___invoke, 0, 1, NULL, 0)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_arr_toobject_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Arr_ToObject, __invoke, arginfo_phalcon_support_helper_arr_toobject___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
