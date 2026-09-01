
extern zend_class_entry *phalcon_html_helper_button_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Button);

PHP_METHOD(Phalcon_Html_Helper_Button, __construct);
PHP_METHOD(Phalcon_Html_Helper_Button, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_button___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, doctype, Phalcon\\Html\\Helper\\Doctype, MAY_BE_NULL, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, forceRaw, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_button___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, raw, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_button_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Button, __construct, arginfo_phalcon_html_helper_button___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_Button, __invoke, arginfo_phalcon_html_helper_button___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
