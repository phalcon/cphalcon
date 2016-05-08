
extern zend_class_entry *phalcon_acl_resourceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEPHIR_INIT_FUNCS(phalcon_acl_resourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __toString, NULL)
	PHP_FE_END
};
