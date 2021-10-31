
extern zend_class_entry *phalcon_encryption_crypt_padding_iso10126_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Iso10126);

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Iso10126, pad);
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Iso10126, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_iso10126_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_iso10126_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_crypt_padding_iso10126_method_entry) {
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Iso10126, pad, arginfo_phalcon_encryption_crypt_padding_iso10126_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Iso10126, unpad, arginfo_phalcon_encryption_crypt_padding_iso10126_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
