
extern zend_class_entry *phalcon_html_helper_script_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Script);

PHP_METHOD(Phalcon_Html_Helper_Script, add);
PHP_METHOD(Phalcon_Html_Helper_Script, getAttributes);
PHP_METHOD(Phalcon_Html_Helper_Script, getTag);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_script_add, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_script_getattributes, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_script_gettag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_script_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Script, add, arginfo_phalcon_html_helper_script_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Script, getAttributes, arginfo_phalcon_html_helper_script_getattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Helper_Script, getTag, arginfo_phalcon_html_helper_script_gettag, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
