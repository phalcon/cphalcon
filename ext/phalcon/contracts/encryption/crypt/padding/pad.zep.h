
extern zend_class_entry *phalcon_contracts_encryption_crypt_padding_pad_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Crypt_Padding_Pad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_padding_pad_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_encryption_crypt_padding_pad_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_encryption_crypt_padding_pad_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Padding_Pad, pad, arginfo_phalcon_contracts_encryption_crypt_padding_pad_pad)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Encryption_Crypt_Padding_Pad, unpad, arginfo_phalcon_contracts_encryption_crypt_padding_pad_unpad)
	PHP_FE_END
};
