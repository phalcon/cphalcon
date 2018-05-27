
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
	ZEND_ARG_INFO(0, cipher)
	ZEND_ARG_INFO(0, useSigning)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_sethashalgo, 0, 0, 1)
	ZEND_ARG_INFO(0, hashAlgo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_usesigning, 0, 0, 1)
	ZEND_ARG_INFO(0, useSigning)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptpadtext, 0, 0, 4)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, blockSize)
	ZEND_ARG_INFO(0, paddingType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptunpadtext, 0, 0, 4)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, blockSize)
	ZEND_ARG_INFO(0, paddingType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_assertcipherisavailable, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_asserthashalgorithmavailable, 0, 0, 1)
	ZEND_ARG_INFO(0, hashAlgo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_getivlength, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_method_entry) {
	PHP_ME(Phalcon_Crypt, __construct, arginfo_phalcon_crypt___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Crypt, setPadding, arginfo_phalcon_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getCipher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setHashAlgo, arginfo_phalcon_crypt_sethashalgo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getHashAlgo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, useSigning, arginfo_phalcon_crypt_usesigning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, _cryptPadText, arginfo_phalcon_crypt__cryptpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, _cryptUnpadText, arginfo_phalcon_crypt__cryptunpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableHashAlgos, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, assertCipherIsAvailable, arginfo_phalcon_crypt_assertcipherisavailable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, assertHashAlgorithmAvailable, arginfo_phalcon_crypt_asserthashalgorithmavailable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, getIvLength, arginfo_phalcon_crypt_getivlength, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, initializeAvailableCiphers, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
