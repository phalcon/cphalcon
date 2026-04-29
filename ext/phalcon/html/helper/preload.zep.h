
extern zend_class_entry *phalcon_html_helper_preload_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Preload);

PHP_METHOD(Phalcon_Html_Helper_Preload, __construct);
PHP_METHOD(Phalcon_Html_Helper_Preload, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_preload___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\ResponseInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_preload___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, type, IS_STRING, 0, "'style'")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_preload_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Preload, __construct, arginfo_phalcon_html_helper_preload___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_Preload, __invoke, arginfo_phalcon_html_helper_preload___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
