
extern zend_class_entry *phalcon_traits_php_apcutrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_ApcuTrait);

PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuDec);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuDelete);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuExists);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuFetch);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuInc);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuIterator);
PHP_METHOD(Phalcon_Traits_Php_ApcuTrait, phpApcuStore);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcudec, 0, 1, MAY_BE_BOOL|MAY_BE_LONG)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcudelete, 0, 1, MAY_BE_BOOL|MAY_BE_ARRAY)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcuexists, 0, 1, MAY_BE_BOOL|MAY_BE_ARRAY)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_php_apcutrait_phpapcufetch, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcuinc, 0, 1, MAY_BE_BOOL|MAY_BE_LONG)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, step, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcuiterator, 0, 1, APCUIterator, MAY_BE_BOOL)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_traits_php_apcutrait_phpapcustore, 0, 2, MAY_BE_BOOL|MAY_BE_ARRAY)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, payload)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, ttl, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_apcutrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuDec, arginfo_phalcon_traits_php_apcutrait_phpapcudec, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuDelete, arginfo_phalcon_traits_php_apcutrait_phpapcudelete, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuExists, arginfo_phalcon_traits_php_apcutrait_phpapcuexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuFetch, arginfo_phalcon_traits_php_apcutrait_phpapcufetch, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuInc, arginfo_phalcon_traits_php_apcutrait_phpapcuinc, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuIterator, arginfo_phalcon_traits_php_apcutrait_phpapcuiterator, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_ApcuTrait, phpApcuStore, arginfo_phalcon_traits_php_apcutrait_phpapcustore, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
