
extern zend_class_entry *phalcon_escaper_escaperinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper_EscaperInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapecss, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapecss, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, css)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapehtml, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapehtml, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapehtmlattr, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapehtmlattr, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapejs, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapejs, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, js, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, js)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapeurl, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_escapeurl, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_getencoding, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_getencoding, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_setencoding, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_setencoding, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escaperinterface_setencoding, 0, 0, 1)
#define arginfo_phalcon_escaper_escaperinterface_setencoding NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_sethtmlquotetype, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_escaper_escaperinterface_sethtmlquotetype, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escaperinterface_sethtmlquotetype, 0, 0, 1)
#define arginfo_phalcon_escaper_escaperinterface_sethtmlquotetype NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, quoteType, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, quoteType)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_escaperinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, escapeCss, arginfo_phalcon_escaper_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, escapeHtml, arginfo_phalcon_escaper_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaper_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, escapeJs, arginfo_phalcon_escaper_escaperinterface_escapejs)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, escapeUrl, arginfo_phalcon_escaper_escaperinterface_escapeurl)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, getEncoding, arginfo_phalcon_escaper_escaperinterface_getencoding)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, setEncoding, arginfo_phalcon_escaper_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_Escaper_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaper_escaperinterface_sethtmlquotetype)
	PHP_FE_END
};
