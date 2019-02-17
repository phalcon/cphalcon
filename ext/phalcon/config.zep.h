
extern zend_class_entry *phalcon_config_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config);

PHP_METHOD(Phalcon_Config, __construct);
PHP_METHOD(Phalcon_Config, offsetExists);
PHP_METHOD(Phalcon_Config, path);
PHP_METHOD(Phalcon_Config, get);
PHP_METHOD(Phalcon_Config, offsetGet);
PHP_METHOD(Phalcon_Config, offsetSet);
PHP_METHOD(Phalcon_Config, offsetUnset);
PHP_METHOD(Phalcon_Config, merge);
PHP_METHOD(Phalcon_Config, toArray);
PHP_METHOD(Phalcon_Config, count);
PHP_METHOD(Phalcon_Config, __set_state);
PHP_METHOD(Phalcon_Config, setPathDelimiter);
PHP_METHOD(Phalcon_Config, getPathDelimiter);
PHP_METHOD(Phalcon_Config, _merge);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrayConfig, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_path, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_merge, 0, 1, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_merge, 0, 1, IS_OBJECT, "Phalcon\\Config", 0)
#endif
	ZEND_ARG_INFO(0, configParam)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config___set_state, 0, 1, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config___set_state, 0, 1, IS_OBJECT, "Phalcon\\Config", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_setpathdelimiter, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_getpathdelimiter, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_getpathdelimiter, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config__merge, 0, 1, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config__merge, 0, 1, IS_OBJECT, "Phalcon\\Config", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
	ZEND_ARG_OBJ_INFO(0, instance, Phalcon\\Config, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_method_entry) {
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, path, arginfo_phalcon_config_path, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, get, arginfo_phalcon_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetUnset, arginfo_phalcon_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, toArray, arginfo_phalcon_config_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, count, arginfo_phalcon_config_count, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, __set_state, arginfo_phalcon_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config, setPathDelimiter, arginfo_phalcon_config_setpathdelimiter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config, getPathDelimiter, arginfo_phalcon_config_getpathdelimiter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config, _merge, arginfo_phalcon_config__merge, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_FE_END
};
