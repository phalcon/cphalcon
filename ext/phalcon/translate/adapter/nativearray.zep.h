
extern zend_class_entry *phalcon_translate_adapter_nativearray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray);

PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, has);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, notFound);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query);
PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, toArray);
zend_object *zephir_init_properties_Phalcon_Translate_Adapter_NativeArray(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_notfound, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_query, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_zephir_init_properties_phalcon_translate_adapter_nativearray, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_nativearray_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, __construct, arginfo_phalcon_translate_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, exists, arginfo_phalcon_translate_adapter_nativearray_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, has, arginfo_phalcon_translate_adapter_nativearray_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, notFound, arginfo_phalcon_translate_adapter_nativearray_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, query, arginfo_phalcon_translate_adapter_nativearray_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, toArray, arginfo_phalcon_translate_adapter_nativearray_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
