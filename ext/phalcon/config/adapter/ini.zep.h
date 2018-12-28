
extern zend_class_entry *phalcon_config_adapter_ini_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini);

PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);
PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString);
PHP_METHOD(Phalcon_Config_Adapter_Ini, _cast);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_ini__parseinistring, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_adapter_ini__parseinistring, 0, 2, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini__cast, 0, 0, 1)
	ZEND_ARG_INFO(0, ini)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_ini_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Ini, _parseIniString, arginfo_phalcon_config_adapter_ini__parseinistring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_Adapter_Ini, _cast, arginfo_phalcon_config_adapter_ini__cast, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
