
extern zend_class_entry *phalcon_config_adapter_ini_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini);

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);
PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini__parseinistring, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_ini_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Ini, _parseIniString, arginfo_phalcon_config_adapter_ini__parseinistring, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
