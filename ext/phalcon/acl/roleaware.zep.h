
extern zend_class_entry *phalcon_acl_roleaware_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleAware);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_roleaware_getrolename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_roleaware_getrolename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_roleaware_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleAware, getRoleName, arginfo_phalcon_acl_roleaware_getrolename)
	PHP_FE_END
};
