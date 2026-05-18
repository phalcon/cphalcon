
extern zend_class_entry *phalcon_html_escaper_htmlescaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_HtmlEscaper);

PHP_METHOD(Phalcon_Html_Escaper_HtmlEscaper, __invoke);
PHP_METHOD(Phalcon_Html_Escaper_HtmlEscaper, escape);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_htmlescaper___invoke, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, input, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_htmlescaper_escape, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, input, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_htmlescaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper_HtmlEscaper, __invoke, arginfo_phalcon_html_escaper_htmlescaper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_HtmlEscaper, escape, arginfo_phalcon_html_escaper_htmlescaper_escape, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
