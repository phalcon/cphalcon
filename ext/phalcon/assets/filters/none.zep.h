
extern zend_class_entry *phalcon_assets_filters_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_None);

PHP_METHOD(Phalcon_Assets_Filters_None, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filters_none_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filters_none_method_entry) {
	PHP_ME(Phalcon_Assets_Filters_None, filter, arginfo_phalcon_assets_filters_none_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
