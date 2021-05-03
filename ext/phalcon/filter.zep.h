
extern zend_class_entry *phalcon_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter);

PHP_METHOD(Phalcon_Filter, __construct);
PHP_METHOD(Phalcon_Filter, get);
PHP_METHOD(Phalcon_Filter, has);
PHP_METHOD(Phalcon_Filter, sanitize);
PHP_METHOD(Phalcon_Filter, set);
PHP_METHOD(Phalcon_Filter, init);
PHP_METHOD(Phalcon_Filter, processArrayValues);
PHP_METHOD(Phalcon_Filter, sanitizer);
zend_object *zephir_init_properties_Phalcon_Filter(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mapper, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, sanitizers)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_init, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_processarrayvalues, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sanitizerParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitizer, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sanitizerParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_zephir_init_properties_phalcon_filter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_method_entry) {
	PHP_ME(Phalcon_Filter, __construct, arginfo_phalcon_filter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter, get, arginfo_phalcon_filter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, has, arginfo_phalcon_filter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, set, arginfo_phalcon_filter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, init, arginfo_phalcon_filter_init, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter, processArrayValues, arginfo_phalcon_filter_processarrayvalues, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter, sanitizer, arginfo_phalcon_filter_sanitizer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
