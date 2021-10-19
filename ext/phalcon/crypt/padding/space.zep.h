
extern zend_class_entry *phalcon_crypt_padding_space_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt_Padding_Space);

PHP_METHOD(Phalcon_Crypt_Padding_Space, pad);
PHP_METHOD(Phalcon_Crypt_Padding_Space, unpad);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_padding_space_pad, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, paddingSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_crypt_padding_space_unpad, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, blockSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_padding_space_method_entry) {
	PHP_ME(Phalcon_Crypt_Padding_Space, pad, arginfo_phalcon_crypt_padding_space_pad, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt_Padding_Space, unpad, arginfo_phalcon_crypt_padding_space_unpad, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
