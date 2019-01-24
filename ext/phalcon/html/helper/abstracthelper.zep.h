
extern zend_class_entry *phalcon_html_helper_abstracthelper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractHelper);

PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, __construct);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, orderAttributes);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderAttributes);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderElement);
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, selfClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstracthelper___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, escaper, Phalcon\\EscaperInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_orderattributes, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_orderattributes, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, overrides, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderattributes, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderattributes, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_renderelement, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tag)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstracthelper_selfclose, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, tag)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_abstracthelper_method_entry) {
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, __construct, arginfo_phalcon_html_helper_abstracthelper___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, orderAttributes, arginfo_phalcon_html_helper_abstracthelper_orderattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderAttributes, arginfo_phalcon_html_helper_abstracthelper_renderattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, renderElement, arginfo_phalcon_html_helper_abstracthelper_renderelement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_AbstractHelper, selfClose, arginfo_phalcon_html_helper_abstracthelper_selfclose, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
