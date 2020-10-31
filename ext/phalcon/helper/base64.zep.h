
extern zend_class_entry *phalcon_helper_base64_ce;

ZEPHIR_INIT_CLASS(Phalcon_Helper_Base64);

PHP_METHOD(Phalcon_Helper_Base64, encodeUrl);
PHP_METHOD(Phalcon_Helper_Base64, decodeUrl);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_base64_encodeurl, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_base64_encodeurl, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, input)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_base64_decodeurl, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_helper_base64_decodeurl, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, input)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_helper_base64_method_entry) {
	PHP_ME(Phalcon_Helper_Base64, encodeUrl, arginfo_phalcon_helper_base64_encodeurl, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Helper_Base64, decodeUrl, arginfo_phalcon_helper_base64_decodeurl, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
