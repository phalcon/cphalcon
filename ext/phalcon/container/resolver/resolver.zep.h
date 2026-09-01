
extern zend_class_entry *phalcon_container_resolver_resolver_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Resolver);

PHP_METHOD(Phalcon_Container_Resolver_Resolver, isResolvableClass);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveCall);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveClass);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveMethod);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveParameter);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveParameters);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveType);
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveArg);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_isresolvableclass, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolvecall, 0, 3, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_INFO(0, callableObject)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_container_resolver_resolver_resolveclass, 0, 3, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolvemethod, 0, 3, IS_VOID, 0)

	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_OBJ_INFO(0, method, ReflectionMethod, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolveparameter, 0, 2, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_OBJ_INFO(0, parameter, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolveparameters, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_ARRAY_INFO(0, parameters, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolvetype, 0, 2, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_resolver_resolvearg, 0, 2, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_resolver_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Resolver, isResolvableClass, arginfo_phalcon_container_resolver_resolver_isresolvableclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveCall, arginfo_phalcon_container_resolver_resolver_resolvecall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveClass, arginfo_phalcon_container_resolver_resolver_resolveclass, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveMethod, arginfo_phalcon_container_resolver_resolver_resolvemethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveParameter, arginfo_phalcon_container_resolver_resolver_resolveparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveParameters, arginfo_phalcon_container_resolver_resolver_resolveparameters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveType, arginfo_phalcon_container_resolver_resolver_resolvetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Resolver, resolveArg, arginfo_phalcon_container_resolver_resolver_resolvearg, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
