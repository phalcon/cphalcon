
extern zend_class_entry *phalcon_assets_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_FilterInterface, filter, arginfo_phalcon_assets_filterinterface_filter)
	PHP_FE_END
};
