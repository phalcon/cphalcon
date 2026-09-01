
extern zend_class_entry *phalcon_contracts_container_resolver_resolverservice_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Resolver_ResolverService);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_isresolvableclass, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_resolvecall, 0, 3, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_INFO(0, callableObject)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_resolveclass, 0, 3, MAY_BE_OBJECT)
	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_resolvemethod, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_OBJ_INFO(0, method, ReflectionMethod, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_resolveparameters, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolverservice_resolvetype, 0, 2, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
	ZEND_ARG_OBJ_INFO(0, type, ReflectionType, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_container_resolver_resolverservice_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, isResolvableClass, arginfo_phalcon_contracts_container_resolver_resolverservice_isresolvableclass)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, resolveCall, arginfo_phalcon_contracts_container_resolver_resolverservice_resolvecall)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, resolveClass, arginfo_phalcon_contracts_container_resolver_resolverservice_resolveclass)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, resolveMethod, arginfo_phalcon_contracts_container_resolver_resolverservice_resolvemethod)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, resolveParameters, arginfo_phalcon_contracts_container_resolver_resolverservice_resolveparameters)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_ResolverService, resolveType, arginfo_phalcon_contracts_container_resolver_resolverservice_resolvetype)
	PHP_FE_END
};
