
extern zend_class_entry *phalcon_assets_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection);

PHP_METHOD(Phalcon_Assets_Collection, getPrefix);
PHP_METHOD(Phalcon_Assets_Collection, getLocal);
PHP_METHOD(Phalcon_Assets_Collection, getResources);
PHP_METHOD(Phalcon_Assets_Collection, getCodes);
PHP_METHOD(Phalcon_Assets_Collection, getPosition);
PHP_METHOD(Phalcon_Assets_Collection, getFilters);
PHP_METHOD(Phalcon_Assets_Collection, getAttributes);
PHP_METHOD(Phalcon_Assets_Collection, getJoin);
PHP_METHOD(Phalcon_Assets_Collection, getTargetUri);
PHP_METHOD(Phalcon_Assets_Collection, getTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal);
PHP_METHOD(Phalcon_Assets_Collection, getSourcePath);
PHP_METHOD(Phalcon_Assets_Collection, add);
PHP_METHOD(Phalcon_Assets_Collection, addInline);
PHP_METHOD(Phalcon_Assets_Collection, addCss);
PHP_METHOD(Phalcon_Assets_Collection, addInlineCss);
PHP_METHOD(Phalcon_Assets_Collection, addJs);
PHP_METHOD(Phalcon_Assets_Collection, addInlineJs);
PHP_METHOD(Phalcon_Assets_Collection, count);
PHP_METHOD(Phalcon_Assets_Collection, rewind);
PHP_METHOD(Phalcon_Assets_Collection, current);
PHP_METHOD(Phalcon_Assets_Collection, key);
PHP_METHOD(Phalcon_Assets_Collection, next);
PHP_METHOD(Phalcon_Assets_Collection, valid);
PHP_METHOD(Phalcon_Assets_Collection, setTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, setSourcePath);
PHP_METHOD(Phalcon_Assets_Collection, setTargetUri);
PHP_METHOD(Phalcon_Assets_Collection, setPrefix);
PHP_METHOD(Phalcon_Assets_Collection, setLocal);
PHP_METHOD(Phalcon_Assets_Collection, setAttributes);
PHP_METHOD(Phalcon_Assets_Collection, setFilters);
PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal);
PHP_METHOD(Phalcon_Assets_Collection, join);
PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath);
PHP_METHOD(Phalcon_Assets_Collection, addFilter);
PHP_METHOD(Phalcon_Assets_Collection, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinline, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, targetLocal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_join, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_getrealtargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Phalcon\\Assets\\FilterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_collection_method_entry) {
	PHP_ME(Phalcon_Assets_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getCodes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getPosition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, add, arginfo_phalcon_assets_collection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInline, arginfo_phalcon_assets_collection_addinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addCss, arginfo_phalcon_assets_collection_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInlineCss, arginfo_phalcon_assets_collection_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addJs, arginfo_phalcon_assets_collection_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInlineJs, arginfo_phalcon_assets_collection_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetPath, arginfo_phalcon_assets_collection_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setSourcePath, arginfo_phalcon_assets_collection_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetUri, arginfo_phalcon_assets_collection_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setPrefix, arginfo_phalcon_assets_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setLocal, arginfo_phalcon_assets_collection_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setAttributes, arginfo_phalcon_assets_collection_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setFilters, arginfo_phalcon_assets_collection_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetLocal, arginfo_phalcon_assets_collection_settargetlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, join, arginfo_phalcon_assets_collection_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getRealTargetPath, arginfo_phalcon_assets_collection_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addFilter, arginfo_phalcon_assets_collection_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
