
extern zend_class_entry *phalcon_assets_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager);

PHP_METHOD(Phalcon_Assets_Manager, __construct);
PHP_METHOD(Phalcon_Assets_Manager, addAsset);
PHP_METHOD(Phalcon_Assets_Manager, addAssetByType);
PHP_METHOD(Phalcon_Assets_Manager, addCss);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCode);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType);
PHP_METHOD(Phalcon_Assets_Manager, addInlineCss);
PHP_METHOD(Phalcon_Assets_Manager, addInlineJs);
PHP_METHOD(Phalcon_Assets_Manager, addJs);
PHP_METHOD(Phalcon_Assets_Manager, collection);
PHP_METHOD(Phalcon_Assets_Manager, collectionAssetsByType);
PHP_METHOD(Phalcon_Assets_Manager, exists);
PHP_METHOD(Phalcon_Assets_Manager, get);
PHP_METHOD(Phalcon_Assets_Manager, getCollections);
PHP_METHOD(Phalcon_Assets_Manager, getCss);
PHP_METHOD(Phalcon_Assets_Manager, getDI);
PHP_METHOD(Phalcon_Assets_Manager, getJs);
PHP_METHOD(Phalcon_Assets_Manager, getOptions);
PHP_METHOD(Phalcon_Assets_Manager, output);
PHP_METHOD(Phalcon_Assets_Manager, outputCss);
PHP_METHOD(Phalcon_Assets_Manager, outputInline);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs);
PHP_METHOD(Phalcon_Assets_Manager, outputJs);
PHP_METHOD(Phalcon_Assets_Manager, set);
PHP_METHOD(Phalcon_Assets_Manager, setDI);
PHP_METHOD(Phalcon_Assets_Manager, setOptions);
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
PHP_METHOD(Phalcon_Assets_Manager, getPrefixedPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addasset, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addasset, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addassetbytype, 0, 2, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addassetbytype, 0, 2, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, local)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
	ZEND_ARG_INFO(0, attributes)
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addinlinecode, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addinlinecode, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addinlinecodebytype, 0, 2, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addinlinecodebytype, 0, 2, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addinlinecss, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addinlinecss, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addinlinejs, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addinlinejs, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, local)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filter, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, filter)
#endif
	ZEND_ARG_INFO(0, attributes)
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

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 1, Phalcon\\Assets\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_collectionassetsbytype, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_collectionassetsbytype, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, assets, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_exists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_exists, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 1, Phalcon\\Assets\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Collection", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getcollections, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getcollections, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_getcss, 0, 0, Phalcon\\Assets\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getcss, 0, 0, IS_OBJECT, "Phalcon\\Assets\\Collection", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_getjs, 0, 0, Phalcon\\Assets\\Collection, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getjs, 0, 0, IS_OBJECT, "Phalcon\\Assets\\Collection", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getoptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getoptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 3, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 3, IS_STRING, NULL, 1)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, collectionName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, collectionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinline, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinline, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinecss, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinecss, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, collectionName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, collectionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinejs, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinejs, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, collectionName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, collectionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, collectionName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, collectionName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 2, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 2, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 1, Phalcon\\Assets\\Manager, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 1, IS_OBJECT, "Phalcon\\Assets\\Manager", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, implicitOutput, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, implicitOutput)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getprefixedpath, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getprefixedpath, 0, 2, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_manager_method_entry) {
	PHP_ME(Phalcon_Assets_Manager, __construct, arginfo_phalcon_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Manager, addAsset, arginfo_phalcon_assets_manager_addasset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addAssetByType, arginfo_phalcon_assets_manager_addassetbytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addCss, arginfo_phalcon_assets_manager_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCode, arginfo_phalcon_assets_manager_addinlinecode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCodeByType, arginfo_phalcon_assets_manager_addinlinecodebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCss, arginfo_phalcon_assets_manager_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineJs, arginfo_phalcon_assets_manager_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addJs, arginfo_phalcon_assets_manager_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, collection, arginfo_phalcon_assets_manager_collection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, collectionAssetsByType, arginfo_phalcon_assets_manager_collectionassetsbytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, exists, arginfo_phalcon_assets_manager_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, get, arginfo_phalcon_assets_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getCollections, arginfo_phalcon_assets_manager_getcollections, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getCss, arginfo_phalcon_assets_manager_getcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getDI, arginfo_phalcon_assets_manager_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getJs, arginfo_phalcon_assets_manager_getjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getOptions, arginfo_phalcon_assets_manager_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, output, arginfo_phalcon_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInline, arginfo_phalcon_assets_manager_outputinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineCss, arginfo_phalcon_assets_manager_outputinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineJs, arginfo_phalcon_assets_manager_outputinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, setDI, arginfo_phalcon_assets_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getPrefixedPath, arginfo_phalcon_assets_manager_getprefixedpath, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
