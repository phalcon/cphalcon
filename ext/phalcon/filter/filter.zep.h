
extern zend_class_entry *phalcon_filter_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Filter);

PHP_METHOD(Phalcon_Filter_Filter, __construct);
PHP_METHOD(Phalcon_Filter_Filter, get);
PHP_METHOD(Phalcon_Filter_Filter, has);
PHP_METHOD(Phalcon_Filter_Filter, sanitize);
PHP_METHOD(Phalcon_Filter_Filter, set);
PHP_METHOD(Phalcon_Filter_Filter, init);
PHP_METHOD(Phalcon_Filter_Filter, processArrayValues);
PHP_METHOD(Phalcon_Filter_Filter, sanitizer);
zend_object *zephir_init_properties_Phalcon_Filter_Filter(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filter_filter_get, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_get, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, sanitizers)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, noRecursive)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_init, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_processarrayvalues, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_processarrayvalues, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, values, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sanitizerName)
#endif
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_sanitizer, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, sanitizerName)
#endif
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filter_method_entry) {
	PHP_ME(Phalcon_Filter_Filter, __construct, arginfo_phalcon_filter_filter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter_Filter, get, arginfo_phalcon_filter_filter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, has, arginfo_phalcon_filter_filter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, sanitize, arginfo_phalcon_filter_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, set, arginfo_phalcon_filter_filter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, init, arginfo_phalcon_filter_filter_init, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter_Filter, processArrayValues, arginfo_phalcon_filter_filter_processarrayvalues, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, sanitizer, arginfo_phalcon_filter_filter_sanitizer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
