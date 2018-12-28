
extern zend_class_entry *phalcon_assets_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_filterinterface_filter, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_filterinterface_filter, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_FilterInterface, filter, arginfo_phalcon_assets_filterinterface_filter)
	PHP_FE_END
};
