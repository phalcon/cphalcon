
extern zend_class_entry *phalcon_html_link_link_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Link_Link);

PHP_METHOD(Phalcon_Html_Link_Link, getAttributes);
PHP_METHOD(Phalcon_Html_Link_Link, getHref);
PHP_METHOD(Phalcon_Html_Link_Link, getRels);
PHP_METHOD(Phalcon_Html_Link_Link, isTemplated);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_link_getattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_link_gethref, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_link_getrels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_link_link_istemplated, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_link_link_method_entry) {
	PHP_ME(Phalcon_Html_Link_Link, getAttributes, arginfo_phalcon_html_link_link_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_Link, getHref, arginfo_phalcon_html_link_link_gethref, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_Link, getRels, arginfo_phalcon_html_link_link_getrels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Link_Link, isTemplated, arginfo_phalcon_html_link_link_istemplated, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
