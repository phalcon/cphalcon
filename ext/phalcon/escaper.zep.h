
extern zend_class_entry *phalcon_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper);

PHP_METHOD(Phalcon_Escaper, setEncoding);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);
PHP_METHOD(Phalcon_Escaper, detectEncoding);
PHP_METHOD(Phalcon_Escaper, normalizeEncoding);
PHP_METHOD(Phalcon_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Escaper, escapeCss);
PHP_METHOD(Phalcon_Escaper, escapeJs);
PHP_METHOD(Phalcon_Escaper, escapeUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_method_entry) {
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, detectEncoding, arginfo_phalcon_escaper_detectencoding, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Escaper, normalizeEncoding, arginfo_phalcon_escaper_normalizeencoding, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaper_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaper_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaper_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeJs, arginfo_phalcon_escaper_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaper_escapeurl, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
