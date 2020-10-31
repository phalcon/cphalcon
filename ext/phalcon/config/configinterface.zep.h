
extern zend_class_entry *phalcon_config_configinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configinterface_getpathdelimiter, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configinterface_getpathdelimiter, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configinterface_merge, 0, 1, Phalcon\\Config\\ConfigInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configinterface_merge, 0, 1, IS_OBJECT, "Phalcon\\Config\\ConfigInterface", 0)
#endif
	ZEND_ARG_INFO(0, toMerge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_configinterface_path, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configinterface_setpathdelimiter, 0, 0, Phalcon\\Config\\ConfigInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configinterface_setpathdelimiter, 0, 0, IS_OBJECT, "Phalcon\\Config\\ConfigInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_configinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Config_ConfigInterface, getPathDelimiter, arginfo_phalcon_config_configinterface_getpathdelimiter)
	PHP_ABSTRACT_ME(Phalcon_Config_ConfigInterface, merge, arginfo_phalcon_config_configinterface_merge)
	PHP_ABSTRACT_ME(Phalcon_Config_ConfigInterface, path, arginfo_phalcon_config_configinterface_path)
	PHP_ABSTRACT_ME(Phalcon_Config_ConfigInterface, setPathDelimiter, arginfo_phalcon_config_configinterface_setpathdelimiter)
	PHP_FE_END
};
