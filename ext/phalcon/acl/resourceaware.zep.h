
extern zend_class_entry *phalcon_acl_resourceaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceAware);

ZEPHIR_INIT_FUNCS(phalcon_acl_resourceaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceAware, getResourceName, NULL)
	PHP_FE_END
};
