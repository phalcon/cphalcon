
extern zend_class_entry *phalcon_acl_resource_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Resource);

PHP_METHOD(Phalcon_Acl_Resource, __construct);
PHP_METHOD(Phalcon_Acl_Resource, getName);
PHP_METHOD(Phalcon_Acl_Resource, getDescription);
PHP_METHOD(Phalcon_Acl_Resource, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resource___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_resource_method_entry) {
	PHP_ME(Phalcon_Acl_Resource, __construct, arginfo_phalcon_acl_resource___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
