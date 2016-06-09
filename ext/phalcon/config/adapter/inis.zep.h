
extern zend_class_entry *phalcon_config_adapter_inis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Inis);

PHP_METHOD(Phalcon_Config_Adapter_Inis, __construct);
PHP_METHOD(Phalcon_Config_Adapter_Inis, _parseIniString);
PHP_METHOD(Phalcon_Config_Adapter_Inis, cast);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_inis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_inis__parseinistring, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_inis_cast, 0, 0, 2)
	ZEND_ARG_INFO(0, ini)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_inis_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Inis, __construct, arginfo_phalcon_config_adapter_inis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Inis, _parseIniString, arginfo_phalcon_config_adapter_inis__parseinistring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Inis, cast, arginfo_phalcon_config_adapter_inis_cast, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
