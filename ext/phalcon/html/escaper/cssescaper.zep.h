
extern zend_class_entry *phalcon_html_escaper_cssescaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_CssEscaper);

PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, __invoke);
PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, escape);
PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, doEscapeCss);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_cssescaper___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_cssescaper_escape, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_cssescaper_doescapecss, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_cssescaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper_CssEscaper, __invoke, arginfo_phalcon_html_escaper_cssescaper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_CssEscaper, escape, arginfo_phalcon_html_escaper_cssescaper_escape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_CssEscaper, doEscapeCss, arginfo_phalcon_html_escaper_cssescaper_doescapecss, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
