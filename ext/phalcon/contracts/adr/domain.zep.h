
extern zend_class_entry *phalcon_contracts_adr_domain_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Domain);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_adr_domain___invoke, 0, 1, Phalcon\\Contracts\\ADR\\Payload\\Payload, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_domain_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Domain, __invoke, arginfo_phalcon_contracts_adr_domain___invoke)
	PHP_FE_END
};
