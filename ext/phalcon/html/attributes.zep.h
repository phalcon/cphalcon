
extern zend_class_entry *phalcon_html_attributes_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Attributes);

PHP_METHOD(Phalcon_Html_Attributes, render);
PHP_METHOD(Phalcon_Html_Attributes, __toString);
PHP_METHOD(Phalcon_Html_Attributes, renderAttributes);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_attributes_render, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_attributes___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_attributes_renderattributes, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_attributes_method_entry) {
	PHP_ME(Phalcon_Html_Attributes, render, arginfo_phalcon_html_attributes_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Attributes, __toString, arginfo_phalcon_html_attributes___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Attributes, renderAttributes, arginfo_phalcon_html_attributes_renderattributes, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
