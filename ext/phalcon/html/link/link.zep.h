
extern zend_class_entry *phalcon_html_link_link_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Link);

PHP_METHOD(Phalcon_Html_Link_Link, __construct);
PHP_METHOD(Phalcon_Html_Link_Link, getAttributes);
PHP_METHOD(Phalcon_Html_Link_Link, getHref);
PHP_METHOD(Phalcon_Html_Link_Link, getRels);
PHP_METHOD(Phalcon_Html_Link_Link, isTemplated);
PHP_METHOD(Phalcon_Html_Link_Link, hrefIsTemplated);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_link___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_link_getattributes, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_link_gethref, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_link_getrels, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_link_istemplated, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_link_hrefistemplated, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_link_method_entry) {
	PHP_ME(Phalcon_Html_Link_Link, __construct, arginfo_phalcon_html_link_link___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Link_Link, getAttributes, arginfo_phalcon_html_link_link_getattributes, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Link_Link, getAttributes, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Link_Link, getHref, arginfo_phalcon_html_link_link_gethref, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Link_Link, getHref, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Link_Link, getRels, arginfo_phalcon_html_link_link_getrels, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Link_Link, getRels, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Link_Link, isTemplated, arginfo_phalcon_html_link_link_istemplated, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Link_Link, isTemplated, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Html_Link_Link, hrefIsTemplated, arginfo_phalcon_html_link_link_hrefistemplated, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
