
extern zend_class_entry *phalcon_html_helper_abstracthelper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractHelper);

PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, __construct);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, close);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, indent);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, orderAttributes);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderArrayElements);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderAttributes);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderElement);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderFullElement);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderTag);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, selfClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstracthelper___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\Escaper\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_close, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_indent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_orderattributes, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, overrides, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderarrayelements, 0, 2, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderattributes, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderelement, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderfullelement, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_rendertag, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, close, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_selfclose, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_abstracthelper_method_entry) {
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, __construct, arginfo_phalcon_html_helper_abstracthelper___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, close, arginfo_phalcon_html_helper_abstracthelper_close, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, indent, arginfo_phalcon_html_helper_abstracthelper_indent, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, orderAttributes, arginfo_phalcon_html_helper_abstracthelper_orderattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderArrayElements, arginfo_phalcon_html_helper_abstracthelper_renderarrayelements, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderAttributes, arginfo_phalcon_html_helper_abstracthelper_renderattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderElement, arginfo_phalcon_html_helper_abstracthelper_renderelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderFullElement, arginfo_phalcon_html_helper_abstracthelper_renderfullelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderTag, arginfo_phalcon_html_helper_abstracthelper_rendertag, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, selfClose, arginfo_phalcon_html_helper_abstracthelper_selfclose, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
