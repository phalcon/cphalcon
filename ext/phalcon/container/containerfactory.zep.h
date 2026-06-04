
extern zend_class_entry *phalcon_container_containerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_ContainerFactory);

PHP_METHOD(Phalcon_Container_ContainerFactory, addProvider);
PHP_METHOD(Phalcon_Container_ContainerFactory, newContainer);
zend_object *zephir_init_properties_Phalcon_Container_ContainerFactory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_containerfactory_addprovider, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, provider, Phalcon\\Contracts\\Container\\Service\\Provider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_container_containerfactory_newcontainer, 0, 0, Phalcon\\Container\\Container, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_containerfactory_zephir_init_properties_phalcon_container_containerfactory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_containerfactory_method_entry) {
	PHP_ME(Phalcon_Container_ContainerFactory, addProvider, arginfo_phalcon_container_containerfactory_addprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_ContainerFactory, newContainer, arginfo_phalcon_container_containerfactory_newcontainer, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
