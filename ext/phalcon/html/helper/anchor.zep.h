
extern zend_class_entry *phalcon_html_helper_anchor_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Anchor);

PHP_METHOD(Phalcon_Html_Helper_Anchor, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Anchor, processAttributes);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_anchor___invoke, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_anchor_processattributes, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_anchor_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Anchor, __invoke, arginfo_phalcon_html_helper_anchor___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Anchor, processAttributes, arginfo_phalcon_html_helper_anchor_processattributes, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
