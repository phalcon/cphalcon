
extern zend_class_entry *phalcon_html_link_linkprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_LinkProvider);

PHP_METHOD(Phalcon_Html_Link_LinkProvider, __construct);
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinks);
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinksByRel);
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getKey);
zend_object *zephir_init_properties_Phalcon_Html_Link_LinkProvider(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_linkprovider___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, links, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, links, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_linkprovider_getlinks, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_linkprovider_getlinksbyrel, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_linkprovider_getkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, link, PsrExt\\Link\\LinkInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_linkprovider_zephir_init_properties_phalcon_html_link_linkprovider, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_linkprovider_method_entry) {
	PHP_ME(Phalcon_Html_Link_LinkProvider, __construct, arginfo_phalcon_html_link_linkprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Html_Link_LinkProvider, getLinks, arginfo_phalcon_html_link_linkprovider_getlinks, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Html_Link_LinkProvider, getLinks, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Html_Link_LinkProvider, getLinksByRel, arginfo_phalcon_html_link_linkprovider_getlinksbyrel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_LinkProvider, getKey, arginfo_phalcon_html_link_linkprovider_getkey, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
