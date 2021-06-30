
extern zend_class_entry *phalcon_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper);

PHP_METHOD(Phalcon_Escaper, attributes);
PHP_METHOD(Phalcon_Escaper, css);
PHP_METHOD(Phalcon_Escaper, detectEncoding);
PHP_METHOD(Phalcon_Escaper, escapeCss);
PHP_METHOD(Phalcon_Escaper, escapeJs);
PHP_METHOD(Phalcon_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Escaper, escapeUrl);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, getFlags);
PHP_METHOD(Phalcon_Escaper, html);
PHP_METHOD(Phalcon_Escaper, js);
PHP_METHOD(Phalcon_Escaper, normalizeEncoding);
PHP_METHOD(Phalcon_Escaper, setDoubleEncode);
PHP_METHOD(Phalcon_Escaper, setEncoding);
PHP_METHOD(Phalcon_Escaper, setFlags);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);
PHP_METHOD(Phalcon_Escaper, url);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_attributes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_css, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapejs, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, js, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_getencoding, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_getflags, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_html, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_js, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setdoubleencode, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, doubleEncode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_escaper_setflags, 0, 1, Phalcon\\Escaper, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, quoteType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_url, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_method_entry) {
	PHP_ME(Phalcon_Escaper, attributes, arginfo_phalcon_escaper_attributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, css, arginfo_phalcon_escaper_css, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, detectEncoding, arginfo_phalcon_escaper_detectencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaper_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeJs, arginfo_phalcon_escaper_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaper_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaper_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaper_escapeurl, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, arginfo_phalcon_escaper_getencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getFlags, arginfo_phalcon_escaper_getflags, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, html, arginfo_phalcon_escaper_html, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, js, arginfo_phalcon_escaper_js, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, normalizeEncoding, arginfo_phalcon_escaper_normalizeencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setDoubleEncode, arginfo_phalcon_escaper_setdoubleencode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setFlags, arginfo_phalcon_escaper_setflags, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, url, arginfo_phalcon_escaper_url, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
