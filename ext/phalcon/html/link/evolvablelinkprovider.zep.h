
extern zend_class_entry *phalcon_html_link_evolvablelinkprovider_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_EvolvableLinkProvider);

PHP_METHOD(Phalcon_Html_Link_EvolvableLinkProvider, withLink);
PHP_METHOD(Phalcon_Html_Link_EvolvableLinkProvider, withoutLink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelinkprovider_withlink, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, link, PsrExt\\Link\\LinkInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelinkprovider_withoutlink, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, link, PsrExt\\Link\\LinkInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_evolvablelinkprovider_method_entry) {
	PHP_ME(Phalcon_Html_Link_EvolvableLinkProvider, withLink, arginfo_phalcon_html_link_evolvablelinkprovider_withlink, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_EvolvableLinkProvider, withoutLink, arginfo_phalcon_html_link_evolvablelinkprovider_withoutlink, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
