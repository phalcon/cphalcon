
extern zend_class_entry *phalcon_crypt_crypt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt_Crypt);

PHP_METHOD(Phalcon_Crypt_Crypt, __construct);
PHP_METHOD(Phalcon_Crypt_Crypt, decrypt);
PHP_METHOD(Phalcon_Crypt_Crypt, decryptBase64);
PHP_METHOD(Phalcon_Crypt_Crypt, encrypt);
PHP_METHOD(Phalcon_Crypt_Crypt, encryptBase64);
PHP_METHOD(Phalcon_Crypt_Crypt, getAvailableCiphers);
PHP_METHOD(Phalcon_Crypt_Crypt, getAuthData);
PHP_METHOD(Phalcon_Crypt_Crypt, getAuthTag);
PHP_METHOD(Phalcon_Crypt_Crypt, getAuthTagLength);
PHP_METHOD(Phalcon_Crypt_Crypt, getAvailableHashAlgorithms);
PHP_METHOD(Phalcon_Crypt_Crypt, getHashAlgorithm);
PHP_METHOD(Phalcon_Crypt_Crypt, getCipher);
PHP_METHOD(Phalcon_Crypt_Crypt, getKey);
PHP_METHOD(Phalcon_Crypt_Crypt, setAuthData);
PHP_METHOD(Phalcon_Crypt_Crypt, setAuthTag);
PHP_METHOD(Phalcon_Crypt_Crypt, setAuthTagLength);
PHP_METHOD(Phalcon_Crypt_Crypt, setCipher);
PHP_METHOD(Phalcon_Crypt_Crypt, setKey);
PHP_METHOD(Phalcon_Crypt_Crypt, setHashAlgorithm);
PHP_METHOD(Phalcon_Crypt_Crypt, setPadding);
PHP_METHOD(Phalcon_Crypt_Crypt, useSigning);
PHP_METHOD(Phalcon_Crypt_Crypt, checkCipherHashIsAvailable);
PHP_METHOD(Phalcon_Crypt_Crypt, cryptPadText);
PHP_METHOD(Phalcon_Crypt_Crypt, cryptUnpadText);
PHP_METHOD(Phalcon_Crypt_Crypt, decryptGetUnpadded);
PHP_METHOD(Phalcon_Crypt_Crypt, decryptGcmCcmAuth);
PHP_METHOD(Phalcon_Crypt_Crypt, encryptGetPadded);
PHP_METHOD(Phalcon_Crypt_Crypt, encryptGcmCcm);
PHP_METHOD(Phalcon_Crypt_Crypt, initializeAvailableCiphers);
PHP_METHOD(Phalcon_Crypt_Crypt, checkIsMode);
PHP_METHOD(Phalcon_Crypt_Crypt, getBlockSize);
PHP_METHOD(Phalcon_Crypt_Crypt, getIvLength);
PHP_METHOD(Phalcon_Crypt_Crypt, getMode);
zend_object *zephir_init_properties_Phalcon_Crypt_Crypt(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_crypt___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, useSigning, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, padFactory, Phalcon\\Crypt\\PadFactory, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_decrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_decryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, safe, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_encrypt, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_encryptbase64, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, safe, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getavailableciphers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getauthdata, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getauthtag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getauthtaglength, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getavailablehashalgorithms, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_gethashalgorithm, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getcipher, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setauthdata, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setauthtag, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setauthtaglength, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setcipher, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setkey, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_sethashalgorithm, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, hashAlgorithm, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_setpadding, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, scheme, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_usesigning, 0, 1, Phalcon\\Crypt\\CryptInterface, 0)
	ZEND_ARG_TYPE_INFO(0, useSigning, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_checkcipherhashisavailable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_cryptpadtext, 0, 4, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paddingType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_cryptunpadtext, 0, 4, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paddingType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_decryptgetunpadded, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, decrypted, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_decryptgcmccmauth, 0, 4, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, cipherText, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, decryptKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, iv, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_encryptgetpadded, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_encryptgcmccm, 0, 4, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, padded, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, encryptKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, iv, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_crypt_initializeavailableciphers, 0, 0, Phalcon\\Crypt\\Crypt, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_checkismode, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, modes, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getblocksize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getivlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_crypt_getmode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_crypt_zephir_init_properties_phalcon_crypt_crypt, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_crypt_method_entry) {
	PHP_ME(Phalcon_Crypt_Crypt, __construct, arginfo_phalcon_crypt_crypt___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Crypt_Crypt, decrypt, arginfo_phalcon_crypt_crypt_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, decryptBase64, arginfo_phalcon_crypt_crypt_decryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, encrypt, arginfo_phalcon_crypt_crypt_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, encryptBase64, arginfo_phalcon_crypt_crypt_encryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getAvailableCiphers, arginfo_phalcon_crypt_crypt_getavailableciphers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getAuthData, arginfo_phalcon_crypt_crypt_getauthdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getAuthTag, arginfo_phalcon_crypt_crypt_getauthtag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getAuthTagLength, arginfo_phalcon_crypt_crypt_getauthtaglength, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getAvailableHashAlgorithms, arginfo_phalcon_crypt_crypt_getavailablehashalgorithms, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getHashAlgorithm, arginfo_phalcon_crypt_crypt_gethashalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getCipher, arginfo_phalcon_crypt_crypt_getcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, getKey, arginfo_phalcon_crypt_crypt_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setAuthData, arginfo_phalcon_crypt_crypt_setauthdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setAuthTag, arginfo_phalcon_crypt_crypt_setauthtag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setAuthTagLength, arginfo_phalcon_crypt_crypt_setauthtaglength, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setCipher, arginfo_phalcon_crypt_crypt_setcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setKey, arginfo_phalcon_crypt_crypt_setkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setHashAlgorithm, arginfo_phalcon_crypt_crypt_sethashalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, setPadding, arginfo_phalcon_crypt_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, useSigning, arginfo_phalcon_crypt_crypt_usesigning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Crypt, checkCipherHashIsAvailable, arginfo_phalcon_crypt_crypt_checkcipherhashisavailable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, cryptPadText, arginfo_phalcon_crypt_crypt_cryptpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, cryptUnpadText, arginfo_phalcon_crypt_crypt_cryptunpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, decryptGetUnpadded, arginfo_phalcon_crypt_crypt_decryptgetunpadded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, decryptGcmCcmAuth, arginfo_phalcon_crypt_crypt_decryptgcmccmauth, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, encryptGetPadded, arginfo_phalcon_crypt_crypt_encryptgetpadded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, encryptGcmCcm, arginfo_phalcon_crypt_crypt_encryptgcmccm, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, initializeAvailableCiphers, arginfo_phalcon_crypt_crypt_initializeavailableciphers, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt_Crypt, checkIsMode, arginfo_phalcon_crypt_crypt_checkismode, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Crypt_Crypt, getBlockSize, arginfo_phalcon_crypt_crypt_getblocksize, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Crypt_Crypt, getIvLength, arginfo_phalcon_crypt_crypt_getivlength, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Crypt_Crypt, getMode, arginfo_phalcon_crypt_crypt_getmode, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
