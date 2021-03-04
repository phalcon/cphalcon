
extern zend_class_entry *phalcon_html_helper_ul_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Ul);

PHP_METHOD(Phalcon_Html_Helper_Ul, getTag);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_ul_gettag, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_ul_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Ul, getTag, arginfo_phalcon_html_helper_ul_gettag, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
