
extern zend_class_entry *phalcon_traits_php_urltrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_UrlTrait);

PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpParseUrl);
PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpRawUrlDecode);
PHP_METHOD(Phalcon_Traits_Php_UrlTrait, phpRawUrlEncode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_php_urltrait_phpparseurl, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, component, IS_LONG, 0, "-1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_urltrait_phprawurldecode, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_urltrait_phprawurlencode, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_urltrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_UrlTrait, phpParseUrl, arginfo_phalcon_traits_php_urltrait_phpparseurl, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_UrlTrait, phpRawUrlDecode, arginfo_phalcon_traits_php_urltrait_phprawurldecode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_UrlTrait, phpRawUrlEncode, arginfo_phalcon_traits_php_urltrait_phprawurlencode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
