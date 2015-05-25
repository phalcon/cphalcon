
extern zend_class_entry *phalcon_acl_resourceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_resourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __construct, arginfo_phalcon_acl_resourceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __toString, NULL)
	PHP_FE_END
};
