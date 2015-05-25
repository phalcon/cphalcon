
extern zend_class_entry *phalcon_assets_resource_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource);

PHP_METHOD(Phalcon_Assets_Resource, getType);
PHP_METHOD(Phalcon_Assets_Resource, getPath);
PHP_METHOD(Phalcon_Assets_Resource, getLocal);
PHP_METHOD(Phalcon_Assets_Resource, getFilter);
PHP_METHOD(Phalcon_Assets_Resource, getAttributes);
PHP_METHOD(Phalcon_Assets_Resource, getSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, getTargetPath);
PHP_METHOD(Phalcon_Assets_Resource, getTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, __construct);
PHP_METHOD(Phalcon_Assets_Resource, setType);
PHP_METHOD(Phalcon_Assets_Resource, setPath);
PHP_METHOD(Phalcon_Assets_Resource, setLocal);
PHP_METHOD(Phalcon_Assets_Resource, setFilter);
PHP_METHOD(Phalcon_Assets_Resource, setAttributes);
PHP_METHOD(Phalcon_Assets_Resource, setTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, setSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, setTargetPath);
PHP_METHOD(Phalcon_Assets_Resource, getContent);
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri);
PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath);
PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealsourcepath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealtargetpath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resource_method_entry) {
	PHP_ME(Phalcon_Assets_Resource, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, __construct, arginfo_phalcon_assets_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Resource, setType, arginfo_phalcon_assets_resource_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setPath, arginfo_phalcon_assets_resource_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setLocal, arginfo_phalcon_assets_resource_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setFilter, arginfo_phalcon_assets_resource_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setAttributes, arginfo_phalcon_assets_resource_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetUri, arginfo_phalcon_assets_resource_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setSourcePath, arginfo_phalcon_assets_resource_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetPath, arginfo_phalcon_assets_resource_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getContent, arginfo_phalcon_assets_resource_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealSourcePath, arginfo_phalcon_assets_resource_getrealsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetPath, arginfo_phalcon_assets_resource_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
