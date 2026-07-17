
extern zend_class_entry *phalcon_auth_exceptions_doesnotimplement_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_DoesNotImplement);

PHP_METHOD(Phalcon_Auth_Exceptions_DoesNotImplement, __construct);
PHP_METHOD(Phalcon_Auth_Exceptions_DoesNotImplement, assert);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_exceptions_doesnotimplement___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_exceptions_doesnotimplement_assert, 0, 4, IS_VOID, 0)

	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, interfaceName)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_exceptions_doesnotimplement_method_entry) {
	PHP_ME(Phalcon_Auth_Exceptions_DoesNotImplement, __construct, arginfo_phalcon_auth_exceptions_doesnotimplement___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Exceptions_DoesNotImplement, assert, arginfo_phalcon_auth_exceptions_doesnotimplement_assert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
