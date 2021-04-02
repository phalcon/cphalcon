
extern zend_class_entry *phalcon_assets_asset_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Asset);

PHP_METHOD(Phalcon_Assets_Asset, getAttributes);
PHP_METHOD(Phalcon_Assets_Asset, setAutoVersion);
PHP_METHOD(Phalcon_Assets_Asset, getFilter);
PHP_METHOD(Phalcon_Assets_Asset, getLocal);
PHP_METHOD(Phalcon_Assets_Asset, getPath);
PHP_METHOD(Phalcon_Assets_Asset, getSourcePath);
PHP_METHOD(Phalcon_Assets_Asset, getTargetPath);
PHP_METHOD(Phalcon_Assets_Asset, getTargetUri);
PHP_METHOD(Phalcon_Assets_Asset, getType);
PHP_METHOD(Phalcon_Assets_Asset, getVersion);
PHP_METHOD(Phalcon_Assets_Asset, setVersion);
PHP_METHOD(Phalcon_Assets_Asset, __construct);
PHP_METHOD(Phalcon_Assets_Asset, getAssetKey);
PHP_METHOD(Phalcon_Assets_Asset, getContent);
PHP_METHOD(Phalcon_Assets_Asset, getRealSourcePath);
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetPath);
PHP_METHOD(Phalcon_Assets_Asset, getRealTargetUri);
PHP_METHOD(Phalcon_Assets_Asset, isAutoVersion);
PHP_METHOD(Phalcon_Assets_Asset, setAttributes);
PHP_METHOD(Phalcon_Assets_Asset, setFilter);
PHP_METHOD(Phalcon_Assets_Asset, setLocal);
PHP_METHOD(Phalcon_Assets_Asset, setSourcePath);
PHP_METHOD(Phalcon_Assets_Asset, setTargetPath);
PHP_METHOD(Phalcon_Assets_Asset, setTargetUri);
PHP_METHOD(Phalcon_Assets_Asset, setType);
PHP_METHOD(Phalcon_Assets_Asset, setPath);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getattributes, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_asset_setautoversion, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, autoVersion, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getfilter, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getlocal, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getsourcepath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_gettargetpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_gettargeturi, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_gettype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_asset_setversion, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_asset___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, autoVersion, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getassetkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getcontent, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, basePath, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getrealsourcepath, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, basePath, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getrealtargetpath, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, basePath, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_getrealtargeturi, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_asset_isautoversion, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_setattributes, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_setfilter, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_setlocal, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_setsourcepath, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, sourcePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_settargetpath, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, targetPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_settargeturi, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, targetUri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_settype, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_asset_setpath, 0, 1, Phalcon\\Assets\\AssetInterface, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_asset_method_entry) {
	PHP_ME(Phalcon_Assets_Asset, getAttributes, arginfo_phalcon_assets_asset_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setAutoVersion, arginfo_phalcon_assets_asset_setautoversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getFilter, arginfo_phalcon_assets_asset_getfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getLocal, arginfo_phalcon_assets_asset_getlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getPath, arginfo_phalcon_assets_asset_getpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getSourcePath, arginfo_phalcon_assets_asset_getsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getTargetPath, arginfo_phalcon_assets_asset_gettargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getTargetUri, arginfo_phalcon_assets_asset_gettargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getType, arginfo_phalcon_assets_asset_gettype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getVersion, arginfo_phalcon_assets_asset_getversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setVersion, arginfo_phalcon_assets_asset_setversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, __construct, arginfo_phalcon_assets_asset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Asset, getAssetKey, arginfo_phalcon_assets_asset_getassetkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getContent, arginfo_phalcon_assets_asset_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getRealSourcePath, arginfo_phalcon_assets_asset_getrealsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getRealTargetPath, arginfo_phalcon_assets_asset_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, getRealTargetUri, arginfo_phalcon_assets_asset_getrealtargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, isAutoVersion, arginfo_phalcon_assets_asset_isautoversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setAttributes, arginfo_phalcon_assets_asset_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setFilter, arginfo_phalcon_assets_asset_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setLocal, arginfo_phalcon_assets_asset_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setSourcePath, arginfo_phalcon_assets_asset_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setTargetPath, arginfo_phalcon_assets_asset_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setTargetUri, arginfo_phalcon_assets_asset_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setType, arginfo_phalcon_assets_asset_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Asset, setPath, arginfo_phalcon_assets_asset_setpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
