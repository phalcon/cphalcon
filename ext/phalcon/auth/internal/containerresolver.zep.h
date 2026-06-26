
extern zend_class_entry *phalcon_auth_internal_containerresolver_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Internal_ContainerResolver);

PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, ensureContainer);
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveFresh);
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, requireService);
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, serviceCandidates);
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveCandidate);
PHP_METHOD(Phalcon_Auth_Internal_ContainerResolver, resolveShared);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_internal_containerresolver_ensurecontainer, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_internal_containerresolver_resolvefresh, 0, 2, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_internal_containerresolver_requireservice, 0, 3, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_ARRAY_INFO(0, candidates, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_internal_containerresolver_servicecandidates, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fqn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, shortName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_internal_containerresolver_resolvecandidate, 0, 6, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fqn, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, shortName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, context, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_internal_containerresolver_resolveshared, 0, 2, MAY_BE_OBJECT)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_internal_containerresolver_method_entry) {
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, ensureContainer, arginfo_phalcon_auth_internal_containerresolver_ensurecontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, resolveFresh, arginfo_phalcon_auth_internal_containerresolver_resolvefresh, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, requireService, arginfo_phalcon_auth_internal_containerresolver_requireservice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, serviceCandidates, arginfo_phalcon_auth_internal_containerresolver_servicecandidates, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, resolveCandidate, arginfo_phalcon_auth_internal_containerresolver_resolvecandidate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Internal_ContainerResolver, resolveShared, arginfo_phalcon_auth_internal_containerresolver_resolveshared, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
