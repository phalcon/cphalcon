
extern zend_class_entry *phalcon_translate_adapter_csv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv);

PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, query);
PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_csv_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Csv, __construct, arginfo_phalcon_translate_adapter_csv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Csv, query, arginfo_phalcon_translate_adapter_csv_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, exists, arginfo_phalcon_translate_adapter_csv_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
