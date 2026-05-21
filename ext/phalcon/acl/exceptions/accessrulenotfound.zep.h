
extern zend_class_entry *phalcon_acl_exceptions_accessrulenotfound_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Exceptions_AccessRuleNotFound);

PHP_METHOD(Phalcon_Acl_Exceptions_AccessRuleNotFound, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_exceptions_accessrulenotfound___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_exceptions_accessrulenotfound_method_entry) {
	PHP_ME(Phalcon_Acl_Exceptions_AccessRuleNotFound, __construct, arginfo_phalcon_acl_exceptions_accessrulenotfound___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
