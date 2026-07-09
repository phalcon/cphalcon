
extern zend_class_entry *phalcon_traits_php_msgpacktrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_MsgpackTrait);

PHP_METHOD(Phalcon_Traits_Php_MsgpackTrait, phpMsgpackPack);
PHP_METHOD(Phalcon_Traits_Php_MsgpackTrait, phpMsgpackUnpack);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_msgpacktrait_phpmsgpackpack, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_php_msgpacktrait_phpmsgpackunpack, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_msgpacktrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_MsgpackTrait, phpMsgpackPack, arginfo_phalcon_traits_php_msgpacktrait_phpmsgpackpack, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_MsgpackTrait, phpMsgpackUnpack, arginfo_phalcon_traits_php_msgpacktrait_phpmsgpackunpack, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
