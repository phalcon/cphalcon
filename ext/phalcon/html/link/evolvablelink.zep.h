
extern zend_class_entry *phalcon_html_link_evolvablelink_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_EvolvableLink);

PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withAttribute);
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withHref);
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withRel);
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withoutAttribute);
PHP_METHOD(Phalcon_Html_Link_EvolvableLink, withoutRel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelink_withattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelink_withhref, 0, 0, 1)
	ZEND_ARG_INFO(0, href)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelink_withrel, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelink_withoutattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_html_link_evolvablelink_withoutrel, 0, 0, 1)
	ZEND_ARG_INFO(0, rel)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_evolvablelink_method_entry) {
	PHP_ME(Phalcon_Html_Link_EvolvableLink, withAttribute, arginfo_phalcon_html_link_evolvablelink_withattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_EvolvableLink, withHref, arginfo_phalcon_html_link_evolvablelink_withhref, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_EvolvableLink, withRel, arginfo_phalcon_html_link_evolvablelink_withrel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_EvolvableLink, withoutAttribute, arginfo_phalcon_html_link_evolvablelink_withoutattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_EvolvableLink, withoutRel, arginfo_phalcon_html_link_evolvablelink_withoutrel, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
