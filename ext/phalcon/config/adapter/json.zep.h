
extern zend_class_entry *phalcon_config_adapter_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json);

PHP_METHOD(Phalcon_Config_Adapter_Json, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_json___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_json_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Json, __construct, arginfo_phalcon_config_adapter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
