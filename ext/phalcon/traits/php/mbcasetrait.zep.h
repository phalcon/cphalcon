
extern zend_class_entry *phalcon_traits_php_mbcasetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_MbCaseTrait);

PHP_METHOD(Phalcon_Traits_Php_MbCaseTrait, phpMbConvertCase);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_mbcasetrait_phpmbconvertcase, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fallback, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_mbcasetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_MbCaseTrait, phpMbConvertCase, arginfo_phalcon_traits_php_mbcasetrait_phpmbconvertcase, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
