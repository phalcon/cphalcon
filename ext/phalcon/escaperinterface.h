
extern zend_class_entry *phalcon_escaperinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_EscaperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaperinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setEncoding, arginfo_phalcon_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeCss, arginfo_phalcon_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeJs, arginfo_phalcon_escaperinterface_escapejs)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl)
	PHP_FE_END
};
