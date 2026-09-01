
extern zend_class_entry *phalcon_contracts_assets_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Assets_Filter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_assets_filter_filter, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_assets_filter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Filter, filter, arginfo_phalcon_contracts_assets_filter_filter)
	PHP_FE_END
};
