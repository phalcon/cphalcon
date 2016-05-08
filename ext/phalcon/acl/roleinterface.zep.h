
extern zend_class_entry *phalcon_acl_roleinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEPHIR_INIT_FUNCS(phalcon_acl_roleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __toString, NULL)
	PHP_FE_END
};
