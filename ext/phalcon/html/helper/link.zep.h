
extern zend_class_entry *phalcon_html_helper_link_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Link);

PHP_METHOD(Phalcon_Html_Helper_Link, add);
PHP_METHOD(Phalcon_Html_Helper_Link, getTag);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_link_add, 0, 2, Phalcon\\Html\\Helper\\Link, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_link_add, 0, 2, IS_OBJECT, "Phalcon\\Html\\Helper\\Link", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, rel)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, href)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_link_gettag, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_link_gettag, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_link_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Link, add, arginfo_phalcon_html_helper_link_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Link, getTag, arginfo_phalcon_html_helper_link_gettag, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
