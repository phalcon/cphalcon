
extern zend_class_entry *phalcon_config_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config);

PHP_METHOD(Phalcon_Config, __construct);
PHP_METHOD(Phalcon_Config, offsetExists);
PHP_METHOD(Phalcon_Config, get);
PHP_METHOD(Phalcon_Config, offsetGet);
PHP_METHOD(Phalcon_Config, offsetSet);
PHP_METHOD(Phalcon_Config, offsetUnset);
PHP_METHOD(Phalcon_Config, merge);
PHP_METHOD(Phalcon_Config, toArray);
PHP_METHOD(Phalcon_Config, count);
PHP_METHOD(Phalcon_Config, __set_state);
PHP_METHOD(Phalcon_Config, _merge);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrayConfig, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config__merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_method_entry) {
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, get, arginfo_phalcon_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetUnset, arginfo_phalcon_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, __set_state, arginfo_phalcon_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config, _merge, arginfo_phalcon_config__merge, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_FE_END
};
