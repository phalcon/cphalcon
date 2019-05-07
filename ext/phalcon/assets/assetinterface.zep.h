
extern zend_class_entry *phalcon_assets_assetinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_AssetInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getassetkey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getassetkey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getattributes, 0, 0, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getattributes, 0, 0, IS_ARRAY, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getfilter, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_getfilter, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_gettype, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_gettype, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_assetinterface_setattributes, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_setattributes, 0, 1, IS_OBJECT, "Phalcon\\Assets\\AssetInterface", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_assetinterface_setfilter, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_setfilter, 0, 1, IS_OBJECT, "Phalcon\\Assets\\AssetInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_assetinterface_settype, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_assetinterface_settype, 0, 1, IS_OBJECT, "Phalcon\\Assets\\AssetInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_assetinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, getAssetKey, arginfo_phalcon_assets_assetinterface_getassetkey)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, getAttributes, arginfo_phalcon_assets_assetinterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, getFilter, arginfo_phalcon_assets_assetinterface_getfilter)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, getType, arginfo_phalcon_assets_assetinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, setAttributes, arginfo_phalcon_assets_assetinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, setFilter, arginfo_phalcon_assets_assetinterface_setfilter)
	PHP_ABSTRACT_ME(Phalcon_Assets_AssetInterface, setType, arginfo_phalcon_assets_assetinterface_settype)
	PHP_FE_END
};
