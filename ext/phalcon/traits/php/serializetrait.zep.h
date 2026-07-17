
extern zend_class_entry *phalcon_traits_php_serializetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_SerializeTrait);

PHP_METHOD(Phalcon_Traits_Php_SerializeTrait, phpSerialize);
PHP_METHOD(Phalcon_Traits_Php_SerializeTrait, phpUnserialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_serializetrait_phpserialize, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_php_serializetrait_phpunserialize, 0, 1, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_php_serializetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Php_SerializeTrait, phpSerialize, arginfo_phalcon_traits_php_serializetrait_phpserialize, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Traits_Php_SerializeTrait, phpUnserialize, arginfo_phalcon_traits_php_serializetrait_phpunserialize, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
