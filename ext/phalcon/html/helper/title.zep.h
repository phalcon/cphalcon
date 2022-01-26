
extern zend_class_entry *phalcon_html_helper_title_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Title);

PHP_METHOD(Phalcon_Html_Helper_Title, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Title, __toString);
PHP_METHOD(Phalcon_Html_Helper_Title, append);
PHP_METHOD(Phalcon_Html_Helper_Title, get);
PHP_METHOD(Phalcon_Html_Helper_Title, set);
PHP_METHOD(Phalcon_Html_Helper_Title, setSeparator);
PHP_METHOD(Phalcon_Html_Helper_Title, prepend);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Title(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title___invoke, 0, 0, Phalcon\\Html\\Helper\\Title, 0)
	ZEND_ARG_TYPE_INFO(0, indent, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_title___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_append, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_get, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_set, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_setseparator, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_prepend, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_helper_title_zephir_init_properties_phalcon_html_helper_title, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_title_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Title, __invoke, arginfo_phalcon_html_helper_title___invoke, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Helper_Title, __toString, arginfo_phalcon_html_helper_title___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Helper_Title, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Html_Helper_Title, append, arginfo_phalcon_html_helper_title_append, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, get, arginfo_phalcon_html_helper_title_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, set, arginfo_phalcon_html_helper_title_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, setSeparator, arginfo_phalcon_html_helper_title_setseparator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, prepend, arginfo_phalcon_html_helper_title_prepend, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
