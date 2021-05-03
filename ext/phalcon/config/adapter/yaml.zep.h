
extern zend_class_entry *phalcon_config_adapter_yaml_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Yaml);

PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_yaml___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, callbacks, IS_ARRAY, 1, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, callbacks, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_yaml_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Yaml, __construct, arginfo_phalcon_config_adapter_yaml___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
