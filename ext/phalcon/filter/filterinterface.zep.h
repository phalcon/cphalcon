
extern zend_class_entry *phalcon_filter_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, sanitizers)
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Filter_FilterInterface, sanitize, arginfo_phalcon_filter_filterinterface_sanitize)
	PHP_FE_END
};
