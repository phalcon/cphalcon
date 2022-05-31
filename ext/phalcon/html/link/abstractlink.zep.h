
extern zend_class_entry *phalcon_html_link_abstractlink_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLink);

PHP_METHOD(Phalcon_Html_Link_AbstractLink, __construct);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetAttributes);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetHref);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetRels);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doIsTemplated);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, hrefIsTemplated);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithAttribute);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithHref);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithRel);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutAttribute);
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutRel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlink_dogetattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlink_dogethref, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlink_dogetrels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlink_doistemplated, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlink_hrefistemplated, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink_dowithattribute, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink_dowithhref, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink_dowithrel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink_dowithoutattribute, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlink_dowithoutrel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_abstractlink_method_entry) {
	PHP_ME(Phalcon_Html_Link_AbstractLink, __construct, arginfo_phalcon_html_link_abstractlink___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doGetAttributes, arginfo_phalcon_html_link_abstractlink_dogetattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doGetHref, arginfo_phalcon_html_link_abstractlink_dogethref, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doGetRels, arginfo_phalcon_html_link_abstractlink_dogetrels, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doIsTemplated, arginfo_phalcon_html_link_abstractlink_doistemplated, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, hrefIsTemplated, arginfo_phalcon_html_link_abstractlink_hrefistemplated, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doWithAttribute, arginfo_phalcon_html_link_abstractlink_dowithattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doWithHref, arginfo_phalcon_html_link_abstractlink_dowithhref, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doWithRel, arginfo_phalcon_html_link_abstractlink_dowithrel, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doWithoutAttribute, arginfo_phalcon_html_link_abstractlink_dowithoutattribute, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLink, doWithoutRel, arginfo_phalcon_html_link_abstractlink_dowithoutrel, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
