
extern zend_class_entry *phalcon_adr_container_adrprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Container_AdrProvider);

PHP_METHOD(Phalcon_ADR_Container_AdrProvider, provide);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_container_adrprovider_provide, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, services, Phalcon\\Contracts\\Container\\Service\\Collection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_container_adrprovider_method_entry) {
	PHP_ME(Phalcon_ADR_Container_AdrProvider, provide, arginfo_phalcon_adr_container_adrprovider_provide, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
