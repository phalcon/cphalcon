
extern zend_class_entry *phalcon_html_helper_abstractlist_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractList);

PHP_METHOD(Phalcon_Html_Helper_AbstractList, __invoke);
PHP_METHOD(Phalcon_Html_Helper_AbstractList, __toString);
PHP_METHOD(Phalcon_Html_Helper_AbstractList, getTag);
zend_object *zephir_init_properties_Phalcon_Html_Helper_AbstractList(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_abstractlist___invoke, 0, 0, Phalcon\\Html\\Helper\\AbstractList, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstractlist___invoke, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\AbstractList", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, indent, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, indent)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstractlist_gettag, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstractlist_gettag, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_abstractlist_method_entry) {
	PHP_ME(Phalcon_Html_Helper_AbstractList, __invoke, arginfo_phalcon_html_helper_abstractlist___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_AbstractList, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_AbstractList, getTag, arginfo_phalcon_html_helper_abstractlist_gettag, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
