
extern zend_class_entry *phalcon_filter_filterlocator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterLocator);

PHP_METHOD(Phalcon_Filter_FilterLocator, sanitize);
PHP_METHOD(Phalcon_Filter_FilterLocator, processArrayValues);
PHP_METHOD(Phalcon_Filter_FilterLocator, sanitizer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filterlocator_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, sanitizers)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, noRecursive)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterlocator_processarrayvalues, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filterlocator_processarrayvalues, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sanitizerName)
#endif
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filterlocator_sanitizer, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sanitizerName)
#endif
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filterlocator_method_entry) {
	PHP_ME(Phalcon_Filter_FilterLocator, sanitize, arginfo_phalcon_filter_filterlocator_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_FilterLocator, processArrayValues, arginfo_phalcon_filter_filterlocator_processarrayvalues, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_FilterLocator, sanitizer, arginfo_phalcon_filter_filterlocator_sanitizer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
