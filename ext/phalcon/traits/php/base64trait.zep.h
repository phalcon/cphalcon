
extern zend_class_entry *phalcon_traits_php_base64trait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_Base64Trait);

PHP_METHOD(Phalcon_Traits_Php_Base64Trait, doDecodeUrl);
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, doEncodeUrl);
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, phpBase64Decode);
PHP_METHOD(Phalcon_Traits_Php_Base64Trait, phpBase64Encode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_base64trait_dodecodeurl, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_base64trait_doencodeurl, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_php_base64trait_phpbase64decode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, strict, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_base64trait_phpbase64encode, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_base64trait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_Base64Trait, doDecodeUrl, arginfo_phalcon_traits_php_base64trait_dodecodeurl, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_Base64Trait, doEncodeUrl, arginfo_phalcon_traits_php_base64trait_doencodeurl, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_Base64Trait, phpBase64Decode, arginfo_phalcon_traits_php_base64trait_phpbase64decode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_Base64Trait, phpBase64Encode, arginfo_phalcon_traits_php_base64trait_phpbase64encode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
