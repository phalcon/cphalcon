
extern zend_class_entry *phalcon_html_escaper_attributeescaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_AttributeEscaper);

PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, __invoke);
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, escape);
PHP_METHOD(Phalcon_Html_Escaper_AttributeEscaper, escapeValue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_attributeescaper___invoke, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_attributeescaper_escape, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_escaper_attributeescaper_escapevalue, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_escaper_attributeescaper_method_entry) {
	PHP_ME(Phalcon_Html_Escaper_AttributeEscaper, __invoke, arginfo_phalcon_html_escaper_attributeescaper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_AttributeEscaper, escape, arginfo_phalcon_html_escaper_attributeescaper_escape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Escaper_AttributeEscaper, escapeValue, arginfo_phalcon_html_escaper_attributeescaper_escapevalue, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
