
extern zend_class_entry *phalcon_encryption_crypt_padding_zero_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Zero);

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Zero, pad);
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Zero, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_zero_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_zero_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_crypt_padding_zero_method_entry) {
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Zero, pad, arginfo_phalcon_encryption_crypt_padding_zero_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Crypt_Padding_Zero, unpad, arginfo_phalcon_encryption_crypt_padding_zero_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
