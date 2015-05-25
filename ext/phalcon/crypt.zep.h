
extern zend_class_entry *phalcon_crypt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt);

PHP_METHOD(Phalcon_Crypt, setPadding);
PHP_METHOD(Phalcon_Crypt, setCipher);
PHP_METHOD(Phalcon_Crypt, getCipher);
PHP_METHOD(Phalcon_Crypt, setMode);
PHP_METHOD(Phalcon_Crypt, getMode);
PHP_METHOD(Phalcon_Crypt, setKey);
PHP_METHOD(Phalcon_Crypt, getKey);
PHP_METHOD(Phalcon_Crypt, _cryptPadText);
PHP_METHOD(Phalcon_Crypt, _cryptUnpadText);
PHP_METHOD(Phalcon_Crypt, encrypt);
PHP_METHOD(Phalcon_Crypt, decrypt);
PHP_METHOD(Phalcon_Crypt, encryptBase64);
PHP_METHOD(Phalcon_Crypt, decryptBase64);
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers);
PHP_METHOD(Phalcon_Crypt, getAvailableModes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
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

ZEPHIR_INIT_FUNCS(phalcon_crypt_method_entry) {
	PHP_ME(Phalcon_Crypt, setPadding, arginfo_phalcon_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getCipher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setMode, arginfo_phalcon_crypt_setmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, _cryptPadText, arginfo_phalcon_crypt__cryptpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, _cryptUnpadText, arginfo_phalcon_crypt__cryptunpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableModes, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
