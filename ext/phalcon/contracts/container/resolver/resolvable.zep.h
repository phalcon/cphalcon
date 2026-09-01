
extern zend_class_entry *phalcon_contracts_container_resolver_resolvable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Resolver_Resolvable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_resolver_resolvable_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, ioc, Phalcon\\Contracts\\Container\\Ioc\\IocContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_container_resolver_resolvable_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Resolver_Resolvable, resolve, arginfo_phalcon_contracts_container_resolver_resolvable_resolve)
	PHP_FE_END
};
