
extern zend_class_entry *phalcon_traits_php_yamltrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_YamlTrait);

PHP_METHOD(Phalcon_Traits_Php_YamlTrait, phpYamlParseFile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_php_yamltrait_phpyamlparsefile, 0, 0, 1)
	ZEND_ARG_INFO(0, filename)
	ZEND_ARG_INFO(0, pos)
	ZEND_ARG_INFO(0, callbacks)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_yamltrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_YamlTrait, phpYamlParseFile, arginfo_phalcon_traits_php_yamltrait_phpyamlparsefile, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
