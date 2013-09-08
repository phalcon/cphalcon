
extern zend_class_entry *phalcon_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper);

PHP_METHOD(Phalcon_Escaper, setEncoding);
PHP_METHOD(Phalcon_Escaper, getEncoding);
PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 0, 0)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 0, 0)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_method_entry) {
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
