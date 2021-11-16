
extern zend_class_entry *phalcon_filter_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Filter);

PHP_METHOD(Phalcon_Filter_Filter, __construct);
PHP_METHOD(Phalcon_Filter_Filter, __call);
PHP_METHOD(Phalcon_Filter_Filter, get);
PHP_METHOD(Phalcon_Filter_Filter, has);
PHP_METHOD(Phalcon_Filter_Filter, sanitize);
PHP_METHOD(Phalcon_Filter_Filter, set);
PHP_METHOD(Phalcon_Filter_Filter, init);
PHP_METHOD(Phalcon_Filter_Filter, createInstance);
PHP_METHOD(Phalcon_Filter_Filter, processArraySanitizers);
PHP_METHOD(Phalcon_Filter_Filter, processArrayValues);
PHP_METHOD(Phalcon_Filter_Filter, sanitizer);
PHP_METHOD(Phalcon_Filter_Filter, processValueIsArray);
PHP_METHOD(Phalcon_Filter_Filter, processValueIsNotArray);
PHP_METHOD(Phalcon_Filter_Filter, splitSanitizerParameters);
zend_object *zephir_init_properties_Phalcon_Filter_Filter(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mapper, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, sanitizers)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_init, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, mapper, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_createinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_processarraysanitizers, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, sanitizers, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_processarrayvalues, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sanitizerParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_sanitizer, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, sanitizerParams, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_processvalueisarray, 0, 0, 4)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_processvalueisnotarray, 0, 0, 3)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, sanitizerName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, sanitizerParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_filter_splitsanitizerparameters, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, sanitizerKey)
	ZEND_ARG_INFO(0, sanitizer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filter_zephir_init_properties_phalcon_filter_filter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filter_method_entry) {
	PHP_ME(Phalcon_Filter_Filter, __construct, arginfo_phalcon_filter_filter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter_Filter, __call, arginfo_phalcon_filter_filter___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, get, arginfo_phalcon_filter_filter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, has, arginfo_phalcon_filter_filter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, sanitize, arginfo_phalcon_filter_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, set, arginfo_phalcon_filter_filter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Filter, init, arginfo_phalcon_filter_filter_init, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter_Filter, createInstance, arginfo_phalcon_filter_filter_createinstance, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, processArraySanitizers, arginfo_phalcon_filter_filter_processarraysanitizers, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, processArrayValues, arginfo_phalcon_filter_filter_processarrayvalues, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, sanitizer, arginfo_phalcon_filter_filter_sanitizer, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, processValueIsArray, arginfo_phalcon_filter_filter_processvalueisarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, processValueIsNotArray, arginfo_phalcon_filter_filter_processvalueisnotarray, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Filter_Filter, splitSanitizerParameters, arginfo_phalcon_filter_filter_splitsanitizerparameters, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
