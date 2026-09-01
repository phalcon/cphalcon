
extern zend_class_entry *phalcon_traits_factory_factorytrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Factory_FactoryTrait);

PHP_METHOD(Phalcon_Traits_Factory_FactoryTrait, getCachedInstance);
PHP_METHOD(Phalcon_Traits_Factory_FactoryTrait, getExceptionClass);
PHP_METHOD(Phalcon_Traits_Factory_FactoryTrait, getService);
PHP_METHOD(Phalcon_Traits_Factory_FactoryTrait, getServices);
PHP_METHOD(Phalcon_Traits_Factory_FactoryTrait, init);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_factory_factorytrait_getcachedinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_VARIADIC_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_factorytrait_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_factorytrait_getservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_factorytrait_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_factory_factorytrait_init, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_factory_factorytrait_method_entry) {
	PHP_ME(Phalcon_Traits_Factory_FactoryTrait, getCachedInstance, arginfo_phalcon_traits_factory_factorytrait_getcachedinstance, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_FactoryTrait, getExceptionClass, arginfo_phalcon_traits_factory_factorytrait_getexceptionclass, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_FactoryTrait, getService, arginfo_phalcon_traits_factory_factorytrait_getservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_FactoryTrait, getServices, arginfo_phalcon_traits_factory_factorytrait_getservices, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Factory_FactoryTrait, init, arginfo_phalcon_traits_factory_factorytrait_init, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
