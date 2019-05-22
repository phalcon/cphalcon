
extern zend_class_entry *phalcon_config_configfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory);

PHP_METHOD(Phalcon_Config_ConfigFactory, load);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configfactory_load, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_load, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_configfactory_method_entry) {
	PHP_ME(Phalcon_Config_ConfigFactory, load, arginfo_phalcon_config_configfactory_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
