
extern zend_class_entry *phalcon_acl_roleinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_roleinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_roleinterface_getdescription, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_roleinterface___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_roleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, arginfo_phalcon_acl_roleinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, arginfo_phalcon_acl_roleinterface_getdescription)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __toString, arginfo_phalcon_acl_roleinterface___tostring)
	PHP_FE_END
};
