
extern zend_class_entry *phalcon_filter_userfilterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_UserFilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_userfilterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_userfilterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Filter_UserFilterInterface, filter, arginfo_phalcon_filter_userfilterinterface_filter)
	PHP_FE_END
};
