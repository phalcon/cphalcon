
extern zend_class_entry *phalcon_traits_php_hashtrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_HashTrait);

PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHash);
PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHashEquals);
PHP_METHOD(Phalcon_Traits_Php_HashTrait, phpHashHmac);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_hashtrait_phphash, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, algorithm, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, binary, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_hashtrait_phphashequals, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, knownString, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, userString, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_hashtrait_phphashhmac, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, algorithm, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, binary, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_hashtrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_HashTrait, phpHash, arginfo_phalcon_traits_php_hashtrait_phphash, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_HashTrait, phpHashEquals, arginfo_phalcon_traits_php_hashtrait_phphashequals, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_HashTrait, phpHashHmac, arginfo_phalcon_traits_php_hashtrait_phphashhmac, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
