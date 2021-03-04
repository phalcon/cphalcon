
extern zend_class_entry *phalcon_html_helper_link_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Link);

PHP_METHOD(Phalcon_Html_Helper_Link, add);
PHP_METHOD(Phalcon_Html_Helper_Link, getTag);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_html_helper_link_add, 0, 2, Phalcon\\Html\\Helper\\Link, 0)
	ZEND_ARG_TYPE_INFO(0, rel, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_link_gettag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_link_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Link, add, arginfo_phalcon_html_helper_link_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Html_Helper_Link, getTag, arginfo_phalcon_html_helper_link_gettag, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
