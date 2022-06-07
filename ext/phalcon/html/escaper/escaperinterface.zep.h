
extern zend_class_entry *phalcon_html_escaper_escaperinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_EscaperInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_attributes, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_css, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_getencoding, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_html, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_js, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_setencoding, 0, 1, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_setflags, 0, 1, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escaperinterface_url, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_escaperinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, attributes, arginfo_phalcon_html_escaper_escaperinterface_attributes)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, css, arginfo_phalcon_html_escaper_escaperinterface_css)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, getEncoding, arginfo_phalcon_html_escaper_escaperinterface_getencoding)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, html, arginfo_phalcon_html_escaper_escaperinterface_html)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, js, arginfo_phalcon_html_escaper_escaperinterface_js)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, setEncoding, arginfo_phalcon_html_escaper_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, setFlags, arginfo_phalcon_html_escaper_escaperinterface_setflags)
	PHP_ABSTRACT_ME(Phalcon_Html_Escaper_EscaperInterface, url, arginfo_phalcon_html_escaper_escaperinterface_url)
	PHP_FE_END
};
