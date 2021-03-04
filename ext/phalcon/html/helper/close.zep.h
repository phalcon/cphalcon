
extern zend_class_entry *phalcon_html_helper_close_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Close);

PHP_METHOD(Phalcon_Html_Helper_Close, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_close___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_close_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Close, __invoke, arginfo_phalcon_html_helper_close___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
