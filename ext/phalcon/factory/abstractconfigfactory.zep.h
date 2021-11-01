
extern zend_class_entry *phalcon_factory_abstractconfigfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Factory_AbstractConfigFactory);

PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, checkConfig);
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, checkConfigElement);
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, getException);
PHP_METHOD(Phalcon_Factory_AbstractConfigFactory, getExceptionClass);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_factory_abstractconfigfactory_checkconfig, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_factory_abstractconfigfactory_checkconfigelement, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_factory_abstractconfigfactory_getexception, 0, 1, Exception, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_factory_abstractconfigfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_factory_abstractconfigfactory_method_entry) {
	PHP_ME(Phalcon_Factory_AbstractConfigFactory, checkConfig, arginfo_phalcon_factory_abstractconfigfactory_checkconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Factory_AbstractConfigFactory, checkConfigElement, arginfo_phalcon_factory_abstractconfigfactory_checkconfigelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Factory_AbstractConfigFactory, getException, arginfo_phalcon_factory_abstractconfigfactory_getexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Factory_AbstractConfigFactory, getExceptionClass, arginfo_phalcon_factory_abstractconfigfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
