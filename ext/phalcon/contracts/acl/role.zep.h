
extern zend_class_entry *phalcon_contracts_acl_role_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Role);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_role___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_role_getdescription, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_role_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_acl_role_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Role, __toString, arginfo_phalcon_contracts_acl_role___tostring)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Role, getDescription, arginfo_phalcon_contracts_acl_role_getdescription)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Role, getName, arginfo_phalcon_contracts_acl_role_getname)
	PHP_FE_END
};
