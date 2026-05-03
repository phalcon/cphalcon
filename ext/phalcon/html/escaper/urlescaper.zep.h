
extern zend_class_entry *phalcon_html_escaper_urlescaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_UrlEscaper);

PHP_METHOD(Phalcon_Html_Escaper_UrlEscaper, __invoke);
PHP_METHOD(Phalcon_Html_Escaper_UrlEscaper, escape);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_urlescaper___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_urlescaper_escape, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_urlescaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper_UrlEscaper, __invoke, arginfo_phalcon_html_escaper_urlescaper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_UrlEscaper, escape, arginfo_phalcon_html_escaper_urlescaper_escape, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
