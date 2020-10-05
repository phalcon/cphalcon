
extern zend_class_entry *phalcon_config_configfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory);

PHP_METHOD(Phalcon_Config_ConfigFactory, __construct);
PHP_METHOD(Phalcon_Config_ConfigFactory, load);
PHP_METHOD(Phalcon_Config_ConfigFactory, newInstance);
PHP_METHOD(Phalcon_Config_ConfigFactory, getAdapters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_configfactory___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, services, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configfactory_load, 0, 1, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_load, 0, 1, IS_OBJECT, "Phalcon\\Config", 0)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configfactory_newinstance, 0, 2, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_newinstance, 0, 2, IS_OBJECT, "Phalcon\\Config", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, fileName)
#endif
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_getadapters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_getadapters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_configfactory_method_entry) {
	PHP_ME(Phalcon_Config_ConfigFactory, __construct, arginfo_phalcon_config_configfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_ConfigFactory, load, arginfo_phalcon_config_configfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config_ConfigFactory, newInstance, arginfo_phalcon_config_configfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config_ConfigFactory, getAdapters, arginfo_phalcon_config_configfactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
