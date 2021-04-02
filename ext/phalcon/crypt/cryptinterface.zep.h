
extern zend_class_entry *phalcon_crypt_cryptinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt_CryptInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_decrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_decryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_encrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_encryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getavailableciphers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getauthtag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getauthdata, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getauthtaglength, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getcipher, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_cryptinterface_getkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setauthtag, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setauthdata, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setauthtaglength, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setcipher, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setkey, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_cryptinterface_setpadding, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, scheme, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_cryptinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, decrypt, arginfo_phalcon_crypt_cryptinterface_decrypt)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, decryptBase64, arginfo_phalcon_crypt_cryptinterface_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, encrypt, arginfo_phalcon_crypt_cryptinterface_encrypt)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, encryptBase64, arginfo_phalcon_crypt_cryptinterface_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getAvailableCiphers, arginfo_phalcon_crypt_cryptinterface_getavailableciphers)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getAuthTag, arginfo_phalcon_crypt_cryptinterface_getauthtag)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getAuthData, arginfo_phalcon_crypt_cryptinterface_getauthdata)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getAuthTagLength, arginfo_phalcon_crypt_cryptinterface_getauthtaglength)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getCipher, arginfo_phalcon_crypt_cryptinterface_getcipher)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, getKey, arginfo_phalcon_crypt_cryptinterface_getkey)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setAuthTag, arginfo_phalcon_crypt_cryptinterface_setauthtag)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setAuthData, arginfo_phalcon_crypt_cryptinterface_setauthdata)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setAuthTagLength, arginfo_phalcon_crypt_cryptinterface_setauthtaglength)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setCipher, arginfo_phalcon_crypt_cryptinterface_setcipher)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setKey, arginfo_phalcon_crypt_cryptinterface_setkey)
	PHP_ABSTRACT_ME(Phalcon_Crypt_CryptInterface, setPadding, arginfo_phalcon_crypt_cryptinterface_setpadding)
	PHP_FE_END
};
