
extern zend_class_entry *phalcon_acl_componentaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_ComponentAware);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_componentaware_getcomponentname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_componentaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_ComponentAware, getComponentName, arginfo_phalcon_acl_componentaware_getcomponentname)
	PHP_FE_END
};
