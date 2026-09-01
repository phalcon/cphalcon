
extern zend_class_entry *phalcon_html_escaper_jsescaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_JsEscaper);

PHP_METHOD(Phalcon_Html_Escaper_JsEscaper, __invoke);
PHP_METHOD(Phalcon_Html_Escaper_JsEscaper, escape);
PHP_METHOD(Phalcon_Html_Escaper_JsEscaper, doEscapeJs);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_jsescaper___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_jsescaper_escape, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_jsescaper_doescapejs, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_jsescaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper_JsEscaper, __invoke, arginfo_phalcon_html_escaper_jsescaper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_JsEscaper, escape, arginfo_phalcon_html_escaper_jsescaper_escape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_JsEscaper, doEscapeJs, arginfo_phalcon_html_escaper_jsescaper_doescapejs, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
