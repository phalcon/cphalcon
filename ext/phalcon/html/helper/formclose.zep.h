
extern zend_class_entry *phalcon_html_helper_formclose_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_FormClose);

PHP_METHOD(Phalcon_Html_Helper_FormClose, __invoke);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_formclose___invoke, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_formclose___invoke, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_formclose_method_entry) {
	PHP_ME(Phalcon_Html_Helper_FormClose, __invoke, arginfo_phalcon_html_helper_formclose___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
