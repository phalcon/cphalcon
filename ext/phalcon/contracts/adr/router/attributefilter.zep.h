
extern zend_class_entry *phalcon_contracts_adr_router_attributefilter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_ADR_Router_AttributeFilter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_adr_router_attributefilter_filter, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_adr_router_attributefilter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_ADR_Router_AttributeFilter, filter, arginfo_phalcon_contracts_adr_router_attributefilter_filter)
	PHP_FE_END
};
