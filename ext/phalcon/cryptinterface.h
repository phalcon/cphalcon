
extern zend_class_entry *phalcon_cryptinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_CryptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cryptinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setCipher, arginfo_phalcon_cryptinterface_setcipher)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getCipher, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setMode, arginfo_phalcon_cryptinterface_setmode)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getMode, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setKey, arginfo_phalcon_cryptinterface_setkey)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encrypt, arginfo_phalcon_cryptinterface_encrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decrypt, arginfo_phalcon_cryptinterface_decrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encryptBase64, arginfo_phalcon_cryptinterface_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decryptBase64, arginfo_phalcon_cryptinterface_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableCiphers, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableModes, NULL)
	PHP_FE_END
};
