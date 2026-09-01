
extern zend_class_entry *phalcon_html_exceptions_attributenotrenderable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Exceptions_AttributeNotRenderable);

PHP_METHOD(Phalcon_Html_Exceptions_AttributeNotRenderable, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_exceptions_attributenotrenderable___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_exceptions_attributenotrenderable_method_entry) {
	PHP_ME(Phalcon_Html_Exceptions_AttributeNotRenderable, __construct, arginfo_phalcon_html_exceptions_attributenotrenderable___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
