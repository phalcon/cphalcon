
extern zend_class_entry *phalcon_contracts_encryption_crypt_crypt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Crypt_Crypt);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_decrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_decryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_encrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_encryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getauthdata, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getauthtag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getauthtaglength, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getavailableciphers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getcipher, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_getkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setauthdata, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setauthtag, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setauthtaglength, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setcipher, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setkey, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_setpadding, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, scheme, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_crypt_usesigning, 0, 1, Phalcon\\Contracts\\Encryption\\Crypt\\Crypt, 0)
	ZEND_ARG_TYPE_INFO(0, useSigning, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_encryption_crypt_crypt_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, decrypt, arginfo_phalcon_contracts_encryption_crypt_crypt_decrypt)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, decryptBase64, arginfo_phalcon_contracts_encryption_crypt_crypt_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, encrypt, arginfo_phalcon_contracts_encryption_crypt_crypt_encrypt)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, encryptBase64, arginfo_phalcon_contracts_encryption_crypt_crypt_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthData, arginfo_phalcon_contracts_encryption_crypt_crypt_getauthdata)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthTag, arginfo_phalcon_contracts_encryption_crypt_crypt_getauthtag)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthTagLength, arginfo_phalcon_contracts_encryption_crypt_crypt_getauthtaglength)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getAvailableCiphers, arginfo_phalcon_contracts_encryption_crypt_crypt_getavailableciphers)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getCipher, arginfo_phalcon_contracts_encryption_crypt_crypt_getcipher)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, getKey, arginfo_phalcon_contracts_encryption_crypt_crypt_getkey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthData, arginfo_phalcon_contracts_encryption_crypt_crypt_setauthdata)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthTag, arginfo_phalcon_contracts_encryption_crypt_crypt_setauthtag)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthTagLength, arginfo_phalcon_contracts_encryption_crypt_crypt_setauthtaglength)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setCipher, arginfo_phalcon_contracts_encryption_crypt_crypt_setcipher)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setKey, arginfo_phalcon_contracts_encryption_crypt_crypt_setkey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, setPadding, arginfo_phalcon_contracts_encryption_crypt_crypt_setpadding)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Crypt, useSigning, arginfo_phalcon_contracts_encryption_crypt_crypt_usesigning)
	PHP_FE_END
};
