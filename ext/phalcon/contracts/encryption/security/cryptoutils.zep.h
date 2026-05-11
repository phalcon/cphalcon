
extern zend_class_entry *phalcon_contracts_encryption_security_cryptoutils_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_CryptoUtils);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_security_cryptoutils_computehmac, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, algo, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, raw, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_security_cryptoutils_getrandom, 0, 0, Phalcon\\Encryption\\Security\\Random, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_security_cryptoutils_getrandombytes, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_security_cryptoutils_setrandombytes, 0, 1, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, randomBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_security_cryptoutils_getsaltbytes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, numberBytes, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_encryption_security_cryptoutils_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Security_CryptoUtils, computeHmac, arginfo_phalcon_contracts_encryption_security_cryptoutils_computehmac)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Security_CryptoUtils, getRandom, arginfo_phalcon_contracts_encryption_security_cryptoutils_getrandom)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Security_CryptoUtils, getRandomBytes, arginfo_phalcon_contracts_encryption_security_cryptoutils_getrandombytes)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Security_CryptoUtils, setRandomBytes, arginfo_phalcon_contracts_encryption_security_cryptoutils_setrandombytes)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Security_CryptoUtils, getSaltBytes, arginfo_phalcon_contracts_encryption_security_cryptoutils_getsaltbytes)
	PHP_FE_END
};
