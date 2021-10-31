
extern zend_class_entry *phalcon_encryption_crypt_padding_isoiek_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_IsoIek);

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, pad);
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_isoiek_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_crypt_padding_isoiek_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_crypt_padding_isoiek_method_entry) {
	PHP_ME(Phalcon_Encryption_Crypt_Padding_IsoIek, pad, arginfo_phalcon_encryption_crypt_padding_isoiek_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Crypt_Padding_IsoIek, unpad, arginfo_phalcon_encryption_crypt_padding_isoiek_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
