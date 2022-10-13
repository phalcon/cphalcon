
extern zend_class_entry *phalcon_html_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper);

PHP_METHOD(Phalcon_Html_Escaper, attributes);
PHP_METHOD(Phalcon_Html_Escaper, css);
PHP_METHOD(Phalcon_Html_Escaper, detectEncoding);
PHP_METHOD(Phalcon_Html_Escaper, escapeCss);
PHP_METHOD(Phalcon_Html_Escaper, escapeJs);
PHP_METHOD(Phalcon_Html_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Html_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Html_Escaper, escapeUrl);
PHP_METHOD(Phalcon_Html_Escaper, getEncoding);
PHP_METHOD(Phalcon_Html_Escaper, getFlags);
PHP_METHOD(Phalcon_Html_Escaper, html);
PHP_METHOD(Phalcon_Html_Escaper, js);
PHP_METHOD(Phalcon_Html_Escaper, normalizeEncoding);
PHP_METHOD(Phalcon_Html_Escaper, setDoubleEncode);
PHP_METHOD(Phalcon_Html_Escaper, setEncoding);
PHP_METHOD(Phalcon_Html_Escaper, setFlags);
PHP_METHOD(Phalcon_Html_Escaper, setHtmlQuoteType);
PHP_METHOD(Phalcon_Html_Escaper, url);
PHP_METHOD(Phalcon_Html_Escaper, phpHtmlSpecialChars);
PHP_METHOD(Phalcon_Html_Escaper, doEscapeCss);
PHP_METHOD(Phalcon_Html_Escaper, doEscapeJs);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_attributes, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_css, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_detectencoding, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escapecss, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escapejs, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escapehtml, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escapehtmlattr, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_escapeurl, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_getencoding, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_getflags, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_html, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_js, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_normalizeencoding, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_setdoubleencode, 0, 1, Phalcon\\Html\\Escaper, 0)
	ZEND_ARG_TYPE_INFO(0, doubleEncode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_setencoding, 0, 1, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_setflags, 0, 1, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_escaper_sethtmlquotetype, 0, 1, Phalcon\\Html\\Escaper\\EscaperInterface, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_url, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_phphtmlspecialchars, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_doescapecss, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_doescapejs, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper, attributes, arginfo_phalcon_html_escaper_attributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, css, arginfo_phalcon_html_escaper_css, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, detectEncoding, arginfo_phalcon_html_escaper_detectencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, escapeCss, arginfo_phalcon_html_escaper_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, escapeJs, arginfo_phalcon_html_escaper_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, escapeHtml, arginfo_phalcon_html_escaper_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, escapeHtmlAttr, arginfo_phalcon_html_escaper_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, escapeUrl, arginfo_phalcon_html_escaper_escapeurl, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, getEncoding, arginfo_phalcon_html_escaper_getencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, getFlags, arginfo_phalcon_html_escaper_getflags, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, html, arginfo_phalcon_html_escaper_html, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, js, arginfo_phalcon_html_escaper_js, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, normalizeEncoding, arginfo_phalcon_html_escaper_normalizeencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, setDoubleEncode, arginfo_phalcon_html_escaper_setdoubleencode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, setEncoding, arginfo_phalcon_html_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, setFlags, arginfo_phalcon_html_escaper_setflags, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, setHtmlQuoteType, arginfo_phalcon_html_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, url, arginfo_phalcon_html_escaper_url, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper, phpHtmlSpecialChars, arginfo_phalcon_html_escaper_phphtmlspecialchars, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Escaper, doEscapeCss, arginfo_phalcon_html_escaper_doescapecss, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Html_Escaper, doEscapeJs, arginfo_phalcon_html_escaper_doescapejs, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
