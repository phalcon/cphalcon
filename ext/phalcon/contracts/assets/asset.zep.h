
extern zend_class_entry *phalcon_contracts_assets_asset_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Assets_Asset);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_assets_asset_getassetkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_assets_asset_getattributes, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_assets_asset_getfilter, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_assets_asset_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_assets_asset_setattributes, 0, 1, Phalcon\\Contracts\\Assets\\Asset, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_assets_asset_setfilter, 0, 1, Phalcon\\Contracts\\Assets\\Asset, 0)
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_assets_asset_settype, 0, 1, Phalcon\\Contracts\\Assets\\Asset, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_assets_asset_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, getAssetKey, arginfo_phalcon_contracts_assets_asset_getassetkey)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, getAttributes, arginfo_phalcon_contracts_assets_asset_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, getFilter, arginfo_phalcon_contracts_assets_asset_getfilter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, getType, arginfo_phalcon_contracts_assets_asset_gettype)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, setAttributes, arginfo_phalcon_contracts_assets_asset_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, setFilter, arginfo_phalcon_contracts_assets_asset_setfilter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Assets_Asset, setType, arginfo_phalcon_contracts_assets_asset_settype)
	PHP_FE_END
};
