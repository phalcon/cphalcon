
extern zend_class_entry *phalcon_html_helper_input_generic_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Generic);

PHP_METHOD(Phalcon_Html_Helper_Input_Generic, __construct);
PHP_METHOD(Phalcon_Html_Helper_Input_Generic, setType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_input_generic___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, doctype, Phalcon\\Html\\Helper\\Doctype, MAY_BE_NULL, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 0, "'text'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_input_generic_settype, 0, 1, Phalcon\\Html\\Helper\\Input\\AbstractInput, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_input_generic_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Input_Generic, __construct, arginfo_phalcon_html_helper_input_generic___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_Input_Generic, setType, arginfo_phalcon_html_helper_input_generic_settype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
