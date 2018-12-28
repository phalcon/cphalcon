
extern zend_class_entry *phalcon_crypt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt);

PHP_METHOD(Phalcon_Crypt, __construct);
PHP_METHOD(Phalcon_Crypt, setPadding);
PHP_METHOD(Phalcon_Crypt, setCipher);
PHP_METHOD(Phalcon_Crypt, getCipher);
PHP_METHOD(Phalcon_Crypt, setKey);
PHP_METHOD(Phalcon_Crypt, getKey);
PHP_METHOD(Phalcon_Crypt, setHashAlgo);
PHP_METHOD(Phalcon_Crypt, getHashAlgo);
PHP_METHOD(Phalcon_Crypt, useSigning);
PHP_METHOD(Phalcon_Crypt, _cryptPadText);
PHP_METHOD(Phalcon_Crypt, _cryptUnpadText);
PHP_METHOD(Phalcon_Crypt, encrypt);
PHP_METHOD(Phalcon_Crypt, decrypt);
PHP_METHOD(Phalcon_Crypt, encryptBase64);
PHP_METHOD(Phalcon_Crypt, decryptBase64);
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers);
PHP_METHOD(Phalcon_Crypt, getAvailableHashAlgos);
PHP_METHOD(Phalcon_Crypt, assertCipherIsAvailable);
PHP_METHOD(Phalcon_Crypt, assertHashAlgorithmAvailable);
PHP_METHOD(Phalcon_Crypt, getIvLength);
PHP_METHOD(Phalcon_Crypt, initializeAvailableCiphers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cipher)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useSigning, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useSigning)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 1, Phalcon\\CryptInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 1, IS_OBJECT, "Phalcon\\CryptInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, scheme, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, scheme)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 1, Phalcon\\CryptInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 1, IS_OBJECT, "Phalcon\\CryptInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cipher)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getcipher, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getcipher, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 1, Phalcon\\CryptInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 1, IS_OBJECT, "Phalcon\\CryptInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getkey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getkey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_sethashalgo, 0, 1, Phalcon\\CryptInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_sethashalgo, 0, 1, IS_OBJECT, "Phalcon\\CryptInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hashAlgo, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, hashAlgo)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_gethashalgo, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_gethashalgo, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_crypt_usesigning, 0, 1, Phalcon\\CryptInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_usesigning, 0, 1, IS_OBJECT, "Phalcon\\CryptInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, useSigning, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, useSigning)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptpadtext, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, blockSize)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, paddingType, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, paddingType)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptunpadtext, 0, 0, 4)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, blockSize)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, paddingType, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, paddingType)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_encrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_encrypt, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_decrypt, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_decrypt, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_encryptbase64, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_encryptbase64, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, safe, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, safe)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_INFO(0, key)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, safe, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, safe)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getavailableciphers, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getavailableciphers, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getavailablehashalgos, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getavailablehashalgos, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_assertcipherisavailable, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cipher)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_asserthashalgorithmavailable, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hashAlgo, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, hashAlgo)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getivlength, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_getivlength, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cipher, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cipher)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_method_entry) {
	PHP_ME(Phalcon_Crypt, __construct, arginfo_phalcon_crypt___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Crypt, setPadding, arginfo_phalcon_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getCipher, arginfo_phalcon_crypt_getcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getKey, arginfo_phalcon_crypt_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setHashAlgo, arginfo_phalcon_crypt_sethashalgo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getHashAlgo, arginfo_phalcon_crypt_gethashalgo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, useSigning, arginfo_phalcon_crypt_usesigning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, _cryptPadText, arginfo_phalcon_crypt__cryptpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, _cryptUnpadText, arginfo_phalcon_crypt__cryptunpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, arginfo_phalcon_crypt_getavailableciphers, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableHashAlgos, arginfo_phalcon_crypt_getavailablehashalgos, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, assertCipherIsAvailable, arginfo_phalcon_crypt_assertcipherisavailable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, assertHashAlgorithmAvailable, arginfo_phalcon_crypt_asserthashalgorithmavailable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, getIvLength, arginfo_phalcon_crypt_getivlength, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, initializeAvailableCiphers, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
