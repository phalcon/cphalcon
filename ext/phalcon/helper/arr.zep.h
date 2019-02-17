
extern zend_class_entry *phalcon_helper_arr_ce;

ZEPHIR_INIT_CLASS(Phalcon_Helper_Arr);

PHP_METHOD(Phalcon_Helper_Arr, get);
PHP_METHOD(Phalcon_Helper_Arr, has);
PHP_METHOD(Phalcon_Helper_Arr, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_helper_arr_get, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_arr_has, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_arr_has, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_arr_set, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_arr_set, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_helper_arr_method_entry) {
	PHP_ME(Phalcon_Helper_Arr, get, arginfo_phalcon_helper_arr_get, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Helper_Arr, has, arginfo_phalcon_helper_arr_has, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Helper_Arr, set, arginfo_phalcon_helper_arr_set, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
