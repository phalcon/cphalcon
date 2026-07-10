
extern zend_class_entry *phalcon_acl_component_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Component);

PHP_METHOD(Phalcon_Acl_Component, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_component___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, description, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_component_method_entry) {
	PHP_ME(Phalcon_Acl_Component, __construct, arginfo_phalcon_acl_component___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
