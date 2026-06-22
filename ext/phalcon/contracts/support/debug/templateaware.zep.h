
extern zend_class_entry *phalcon_contracts_support_debug_templateaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Debug_TemplateAware);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_debug_templateaware_gettemplate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_support_debug_templateaware_settemplate, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_support_debug_templateaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_TemplateAware, getTemplate, arginfo_phalcon_contracts_support_debug_templateaware_gettemplate)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_TemplateAware, setTemplate, arginfo_phalcon_contracts_support_debug_templateaware_settemplate)
	PHP_FE_END
};
