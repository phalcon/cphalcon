
extern zend_class_entry *phalcon_support_helper_json_decode_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Json_Decode);

PHP_METHOD(Phalcon_Support_Helper_Json_Decode, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_helper_json_decode___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_json_decode_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Json_Decode, __invoke, arginfo_phalcon_support_helper_json_decode___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
