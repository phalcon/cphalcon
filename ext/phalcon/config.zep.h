
extern zend_class_entry *phalcon_config_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config);

PHP_METHOD(Phalcon_Config, getPathDelimiter);
PHP_METHOD(Phalcon_Config, merge);
PHP_METHOD(Phalcon_Config, path);
PHP_METHOD(Phalcon_Config, setPathDelimiter);
PHP_METHOD(Phalcon_Config, toArray);
PHP_METHOD(Phalcon_Config, internalMerge);
PHP_METHOD(Phalcon_Config, setData);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_getpathdelimiter, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_merge, 0, 1, Phalcon\\Config\\ConfigInterface, 0)
	ZEND_ARG_INFO(0, toMerge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_path, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_setpathdelimiter, 0, 0, Phalcon\\Config\\ConfigInterface, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_internalmerge, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_ARRAY_INFO(0, target, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_setdata, 0, 2, IS_VOID, 0)

	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_method_entry) {
	PHP_ME(Phalcon_Config, getPathDelimiter, arginfo_phalcon_config_getpathdelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, path, arginfo_phalcon_config_path, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, setPathDelimiter, arginfo_phalcon_config_setpathdelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, toArray, arginfo_phalcon_config_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, internalMerge, arginfo_phalcon_config_internalmerge, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config, setData, arginfo_phalcon_config_setdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
