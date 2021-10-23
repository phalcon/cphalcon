
extern zend_class_entry *phalcon_config_adapter_ini_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini);

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);
PHP_METHOD(Phalcon_Config_Adapter_Ini, cast);
PHP_METHOD(Phalcon_Config_Adapter_Ini, castArray);
PHP_METHOD(Phalcon_Config_Adapter_Ini, parseIniString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini_cast, 0, 0, 1)
	ZEND_ARG_INFO(0, ini)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_ini_castarray, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, ini, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_ini_parseinistring, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_ini_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Ini, cast, arginfo_phalcon_config_adapter_ini_cast, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Ini, castArray, arginfo_phalcon_config_adapter_ini_castarray, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Ini, parseIniString, arginfo_phalcon_config_adapter_ini_parseinistring, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
