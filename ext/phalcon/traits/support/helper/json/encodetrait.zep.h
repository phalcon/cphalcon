
extern zend_class_entry *phalcon_traits_support_helper_json_encodetrait_ce;

ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Json_EncodeTrait);

PHP_METHOD(Phalcon_Traits_Support_Helper_Json_EncodeTrait, toEncode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_traits_support_helper_json_encodetrait_toencode, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_LONG, 0, "79")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, depth, IS_LONG, 0, "512")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_traits_support_helper_json_encodetrait_method_entry) {
	PHP_ME(Phalcon_Traits_Support_Helper_Json_EncodeTrait, toEncode, arginfo_phalcon_traits_support_helper_json_encodetrait_toencode, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
