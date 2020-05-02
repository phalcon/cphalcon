
extern zend_class_entry *phalcon_html_helper_base_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Base);

PHP_METHOD(Phalcon_Html_Helper_Base, __invoke);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_base___invoke, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_base___invoke, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, href, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, href)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_base_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Base, __invoke, arginfo_phalcon_html_helper_base___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
