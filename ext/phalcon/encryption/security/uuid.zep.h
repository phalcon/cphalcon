
extern zend_class_entry *phalcon_encryption_security_uuid_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid);

PHP_METHOD(Phalcon_Encryption_Security_Uuid, v1);
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v3);
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v4);
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v5);
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v6);
PHP_METHOD(Phalcon_Encryption_Security_Uuid, v7);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v1, 0, 0, Phalcon\\Encryption\\Security\\Uuid\\Version1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v3, 0, 2, Phalcon\\Encryption\\Security\\Uuid\\Version3, 0)
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v4, 0, 0, Phalcon\\Encryption\\Security\\Uuid\\Version4, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v5, 0, 2, Phalcon\\Encryption\\Security\\Uuid\\Version5, 0)
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v6, 0, 0, Phalcon\\Encryption\\Security\\Uuid\\Version6, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_uuid_v7, 0, 0, Phalcon\\Encryption\\Security\\Uuid\\Version7, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_uuid_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_Uuid, v1, arginfo_phalcon_encryption_security_uuid_v1, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid, v3, arginfo_phalcon_encryption_security_uuid_v3, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid, v4, arginfo_phalcon_encryption_security_uuid_v4, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid, v5, arginfo_phalcon_encryption_security_uuid_v5, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid, v6, arginfo_phalcon_encryption_security_uuid_v6, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_Uuid, v7, arginfo_phalcon_encryption_security_uuid_v7, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
