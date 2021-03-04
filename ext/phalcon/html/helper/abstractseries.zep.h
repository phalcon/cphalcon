
extern zend_class_entry *phalcon_html_helper_abstractseries_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractSeries);

PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __invoke);
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __toString);
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, getTag);
zend_object *zephir_init_properties_Phalcon_Html_Helper_AbstractSeries(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_abstractseries___invoke, 0, 0, Phalcon\\Html\\Helper\\AbstractSeries, 0)
	ZEND_ARG_TYPE_INFO(0, indent, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstractseries___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstractseries___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_abstractseries_gettag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_abstractseries_zephir_init_properties_phalcon_html_helper_abstractseries, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_abstractseries_method_entry) {
	PHP_ME(Phalcon_Html_Helper_AbstractSeries, __invoke, arginfo_phalcon_html_helper_abstractseries___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_AbstractSeries, __toString, arginfo_phalcon_html_helper_abstractseries___tostring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_AbstractSeries, getTag, arginfo_phalcon_html_helper_abstractseries_gettag, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
