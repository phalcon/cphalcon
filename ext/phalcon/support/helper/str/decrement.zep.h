
extern zend_class_entry *phalcon_support_helper_str_decrement_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Decrement);

PHP_METHOD(Phalcon_Support_Helper_Str_Decrement, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_decrement___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_decrement_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Decrement, __invoke, arginfo_phalcon_support_helper_str_decrement___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
