
extern zend_class_entry *phalcon_html_link_linkprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_LinkProvider);

PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinks);
PHP_METHOD(Phalcon_Html_Link_LinkProvider, getLinksByRel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_linkprovider_getlinks, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_linkprovider_getlinksbyrel, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_linkprovider_method_entry) {
	PHP_ME(Phalcon_Html_Link_LinkProvider, getLinks, arginfo_phalcon_html_link_linkprovider_getlinks, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_LinkProvider, getLinksByRel, arginfo_phalcon_html_link_linkprovider_getlinksbyrel, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
