
extern zend_class_entry *phalcon_traits_support_helper_json_decodetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Json_DecodeTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Json_DecodeTrait, toDecode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_traits_support_helper_json_decodetrait_todecode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, associative, _IS_BOOL, 0, "false")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, depth, IS_LONG, 0, "512")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_LONG, 0, "79")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_json_decodetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Json_DecodeTrait, toDecode, arginfo_phalcon_traits_support_helper_json_decodetrait_todecode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
