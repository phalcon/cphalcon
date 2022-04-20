
extern zend_class_entry *phalcon_html_link_abstractlinkprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLinkProvider);

PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, __construct);
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinks);
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doGetLinksByRel);
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doWithLink);
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, doWithoutLink);
PHP_METHOD(Phalcon_Html_Link_AbstractLinkProvider, getKey);
zend_object *zephir_init_properties_Phalcon_Html_Link_AbstractLinkProvider(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, links, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, links, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_dogetlinks, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_dogetlinksbyrel, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_dowithlink, 0, 0, 1)
	ZEND_ARG_INFO(0, link)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_dowithoutlink, 0, 0, 1)
	ZEND_ARG_INFO(0, link)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_getkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, link)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_abstractlinkprovider_zephir_init_properties_phalcon_html_link_abstractlinkprovider, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_abstractlinkprovider_method_entry) {
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, __construct, arginfo_phalcon_html_link_abstractlinkprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, doGetLinks, arginfo_phalcon_html_link_abstractlinkprovider_dogetlinks, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, doGetLinksByRel, arginfo_phalcon_html_link_abstractlinkprovider_dogetlinksbyrel, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, doWithLink, arginfo_phalcon_html_link_abstractlinkprovider_dowithlink, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, doWithoutLink, arginfo_phalcon_html_link_abstractlinkprovider_dowithoutlink, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Html_Link_AbstractLinkProvider, getKey, arginfo_phalcon_html_link_abstractlinkprovider_getkey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
