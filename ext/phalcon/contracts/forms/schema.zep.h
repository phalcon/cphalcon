
extern zend_class_entry *phalcon_contracts_forms_schema_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Forms_Schema);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_forms_schema_load, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_forms_schema_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Forms_Schema, load, arginfo_phalcon_contracts_forms_schema_load)
	PHP_FE_END
};
