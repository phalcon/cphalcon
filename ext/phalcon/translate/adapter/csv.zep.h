
extern zend_class_entry *phalcon_translate_adapter_csv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv);

PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, has);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, load);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, phpFopen);
zend_object *zephir_init_properties_Phalcon_Translate_Adapter_Csv(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, interpolator, Phalcon\\Translate\\InterpolatorFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, translateKey, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, placeholders, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_translate_adapter_csv_load, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, enclosure, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_zephir_init_properties_phalcon_translate_adapter_csv, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_csv_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Csv, __construct, arginfo_phalcon_translate_adapter_csv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Csv, exists, arginfo_phalcon_translate_adapter_csv_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, has, arginfo_phalcon_translate_adapter_csv_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, query, arginfo_phalcon_translate_adapter_csv_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, load, arginfo_phalcon_translate_adapter_csv_load, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Translate_Adapter_Csv, phpFopen, arginfo_phalcon_translate_adapter_csv_phpfopen, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
