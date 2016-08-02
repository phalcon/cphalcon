
extern zend_class_entry *phalcon_acl_roleaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleAware);

ZEPHIR_INIT_FUNCS(phalcon_acl_roleaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleAware, getRoleName, NULL)
	PHP_FE_END
};
