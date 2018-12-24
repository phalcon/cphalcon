
extern zend_class_entry *phalcon_utility_ce;

ZEPHIR_INIT_CLASS(Phalcon_Utility);

PHP_METHOD(Phalcon_Utility, arrayGetDefault);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utility_arraygetdefault, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_utility_method_entry) {
	PHP_ME(Phalcon_Utility, arrayGetDefault, arginfo_phalcon_utility_arraygetdefault, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
