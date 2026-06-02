
extern zend_class_entry *phalcon_contracts_container_resolver_reflectionmethodresolver_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Resolver_ReflectionMethodResolver);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_reflectionmethodresolver_resolvemethod, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_OBJ_INFO(0, method, ReflectionMethod, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_container_resolver_reflectionmethodresolver_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ReflectionMethodResolver, resolveMethod, arginfo_phalcon_contracts_container_resolver_reflectionmethodresolver_resolvemethod)
	PHP_FE_END
};
