
extern zend_class_entry *phalcon_acl_role_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Role);

PHP_METHOD(Phalcon_Acl_Role, getName);
PHP_METHOD(Phalcon_Acl_Role, __toString);
PHP_METHOD(Phalcon_Acl_Role, getDescription);
PHP_METHOD(Phalcon_Acl_Role, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_role___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_role_method_entry) {
	PHP_ME(Phalcon_Acl_Role, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, __construct, arginfo_phalcon_acl_role___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
