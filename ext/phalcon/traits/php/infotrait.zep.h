
extern zend_class_entry *phalcon_traits_php_infotrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_InfoTrait);

PHP_METHOD(Phalcon_Traits_Php_InfoTrait, phpExtensionLoaded);
PHP_METHOD(Phalcon_Traits_Php_InfoTrait, phpFunctionExists);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_infotrait_phpextensionloaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_infotrait_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_infotrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_InfoTrait, phpExtensionLoaded, arginfo_phalcon_traits_php_infotrait_phpextensionloaded, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Traits_Php_InfoTrait, phpFunctionExists, arginfo_phalcon_traits_php_infotrait_phpfunctionexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
