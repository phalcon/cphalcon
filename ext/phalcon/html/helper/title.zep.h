
extern zend_class_entry *phalcon_html_helper_title_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Title);

PHP_METHOD(Phalcon_Html_Helper_Title, __invoke);
PHP_METHOD(Phalcon_Html_Helper_Title, __toString);
PHP_METHOD(Phalcon_Html_Helper_Title, append);
PHP_METHOD(Phalcon_Html_Helper_Title, get);
PHP_METHOD(Phalcon_Html_Helper_Title, set);
PHP_METHOD(Phalcon_Html_Helper_Title, prepend);
zend_object *zephir_init_properties_Phalcon_Html_Helper_Title(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title___invoke, 0, 0, Phalcon\\Html\\Helper\\Title, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title___invoke, 0, 0, IS_OBJECT, "Phalcon\\Html\\Helper\\Title", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, separator)
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
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_append, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_append, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Title", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_get, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_get, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_set, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_set, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Title", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_title_prepend, 0, 1, Phalcon\\Html\\Helper\\Title, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_title_prepend, 0, 1, IS_OBJECT, "Phalcon\\Html\\Helper\\Title", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, text)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, raw)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_title_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Title, __invoke, arginfo_phalcon_html_helper_title___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, append, arginfo_phalcon_html_helper_title_append, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, get, arginfo_phalcon_html_helper_title_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, set, arginfo_phalcon_html_helper_title_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Title, prepend, arginfo_phalcon_html_helper_title_prepend, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
