
extern zend_class_entry *phalcon_html_helper_label_ce;

ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Label);

PHP_METHOD(Phalcon_Html_Helper_Label, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_html_helper_label___invoke, 0, 0, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_html_helper_label_method_entry) {
	PHP_ME(Phalcon_Html_Helper_Label, __invoke, arginfo_phalcon_html_helper_label___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
