
extern zend_class_entry *phalcon_acl_exceptions_forbiddenwildcard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Exceptions_ForbiddenWildcard);

PHP_METHOD(Phalcon_Acl_Exceptions_ForbiddenWildcard, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_exceptions_forbiddenwildcard___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, elementType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_exceptions_forbiddenwildcard_method_entry) {
	PHP_ME(Phalcon_Acl_Exceptions_ForbiddenWildcard, __construct, arginfo_phalcon_acl_exceptions_forbiddenwildcard___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
