
extern zend_class_entry *phalcon_traits_php_headertrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_HeaderTrait);

PHP_METHOD(Phalcon_Traits_Php_HeaderTrait, phpHeadersSent);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_headertrait_phpheaderssent, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_headertrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_HeaderTrait, phpHeadersSent, arginfo_phalcon_traits_php_headertrait_phpheaderssent, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
