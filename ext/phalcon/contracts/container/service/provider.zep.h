
extern zend_class_entry *phalcon_contracts_container_service_provider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Container_Service_Provider);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_container_service_provider_provide, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, services, Phalcon\\Contracts\\Container\\Service\\Collection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_container_service_provider_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Container_Service_Provider, provide, arginfo_phalcon_contracts_container_service_provider_provide)
	PHP_FE_END
};
