
extern zend_class_entry *phalcon_traits_factory_configtrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Factory_ConfigTrait);

PHP_METHOD(Phalcon_Traits_Factory_ConfigTrait, checkConfig);
PHP_METHOD(Phalcon_Traits_Factory_ConfigTrait, checkConfigElement);
PHP_METHOD(Phalcon_Traits_Factory_ConfigTrait, getExceptionClass);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_configtrait_checkconfig, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_configtrait_checkconfigelement, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_configtrait_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_factory_configtrait_method_entry) {
	PHP_ME(Phalcon_Traits_Factory_ConfigTrait, checkConfig, arginfo_phalcon_traits_factory_configtrait_checkconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_ConfigTrait, checkConfigElement, arginfo_phalcon_traits_factory_configtrait_checkconfigelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_ConfigTrait, getExceptionClass, arginfo_phalcon_traits_factory_configtrait_getexceptionclass, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
