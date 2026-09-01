
extern zend_class_entry *phalcon_encryption_security_uuid_version3_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_Version3);

PHP_METHOD(Phalcon_Encryption_Security_Uuid_Version3, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_uuid_version3___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_uuid_version3_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_Uuid_Version3, __construct, arginfo_phalcon_encryption_security_uuid_version3___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
