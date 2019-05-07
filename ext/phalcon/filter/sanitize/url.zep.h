
extern zend_class_entry *phalcon_filter_sanitize_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Url);

PHP_METHOD(Phalcon_Filter_Sanitize_Url, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_url___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_url_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Url, __invoke, arginfo_phalcon_filter_sanitize_url___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
