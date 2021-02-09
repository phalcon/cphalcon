
extern zend_class_entry *phalcon_translate_adapter_csv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv);

PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load);
zend_object *zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, index)
#endif
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_load, 0, 4, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_load, 0, 4, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_load, 0, 0, 4)
#define arginfo_phalcon_translate_adapter_csv_load NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, file)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, length)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, enclosure, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, enclosure)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_zephir_init_properties_phalcon_translate_adapter_csv, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_csv_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Csv, __construct, arginfo_phalcon_translate_adapter_csv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Csv, exists, arginfo_phalcon_translate_adapter_csv_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, query, arginfo_phalcon_translate_adapter_csv_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, load, arginfo_phalcon_translate_adapter_csv_load, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
