
extern zend_class_entry *phalcon_encryption_crypt_padding_ansi_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Ansi);

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Ansi, pad);
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Ansi, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_ansi_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_ansi_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_crypt_padding_ansi_method_entry) {
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Ansi, pad, arginfo_phalcon_encryption_crypt_padding_ansi_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Ansi, unpad, arginfo_phalcon_encryption_crypt_padding_ansi_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
