
extern zend_class_entry *phalcon_config_adapter_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Php);

PHP_METHOD(Phalcon_Config_Adapter_Php, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_php___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_php_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Php, __construct, arginfo_phalcon_config_adapter_php___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
