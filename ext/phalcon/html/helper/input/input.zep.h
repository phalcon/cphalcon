
extern zend_class_entry *phalcon_html_helper_input_input_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Input);

PHP_METHOD(Phalcon_Html_Helper_Input_Input, setType);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_input_settype, 0, 1, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_input_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_Input, setType, arginfo_phalcon_html_helper_input_input_settype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
