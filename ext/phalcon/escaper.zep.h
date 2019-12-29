
extern zend_class_entry *phalcon_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper);

PHP_METHOD(Phalcon_Escaper, detectEncoding);
PHP_METHOD(Phalcon_Escaper, escapeCss);
PHP_METHOD(Phalcon_Escaper, escapeJs);
PHP_METHOD(Phalcon_Escaper, escapeHtml);
PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
PHP_METHOD(Phalcon_Escaper, escapeUrl);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, normalizeEncoding);
PHP_METHOD(Phalcon_Escaper, setDoubleEncode);
PHP_METHOD(Phalcon_Escaper, setEncoding);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 1, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 1, IS_STRING, NULL, 1)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, str)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, css)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapejs, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapejs, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, js, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, js)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, attribute)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_getencoding, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_getencoding, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, str)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setdoubleencode, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setdoubleencode, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setdoubleencode, 0, 0, 1)
#define arginfo_phalcon_escaper_setdoubleencode NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, doubleEncode, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, doubleEncode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 0, 1)
#define arginfo_phalcon_escaper_setencoding NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 0, 1)
#define arginfo_phalcon_escaper_sethtmlquotetype NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, quoteType, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, quoteType)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_method_entry) {
	PHP_ME(Phalcon_Escaper, detectEncoding, arginfo_phalcon_escaper_detectencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaper_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeJs, arginfo_phalcon_escaper_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaper_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaper_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaper_escapeurl, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, arginfo_phalcon_escaper_getencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, normalizeEncoding, arginfo_phalcon_escaper_normalizeencoding, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setDoubleEncode, arginfo_phalcon_escaper_setdoubleencode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
