
extern zend_class_entry *phalcon_assets_asset_css_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset_Css);

PHP_METHOD(Phalcon_Assets_Asset_Css, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_asset_css___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, local)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, version)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoVersion, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoVersion)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_asset_css_method_entry) {
	PHP_ME(Phalcon_Assets_Asset_Css, __construct, arginfo_phalcon_assets_asset_css___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
