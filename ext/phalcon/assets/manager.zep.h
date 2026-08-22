
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
PHP_METHOD(Phalcon_Assets_Manager, getJs);
PHP_METHOD(Phalcon_Assets_Manager, getOptions);
PHP_METHOD(Phalcon_Assets_Manager, has);
PHP_METHOD(Phalcon_Assets_Manager, output);
PHP_METHOD(Phalcon_Assets_Manager, outputCss);
PHP_METHOD(Phalcon_Assets_Manager, outputInline);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss);
PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs);
PHP_METHOD(Phalcon_Assets_Manager, outputJs);
PHP_METHOD(Phalcon_Assets_Manager, set);
PHP_METHOD(Phalcon_Assets_Manager, setOptions);
PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
PHP_METHOD(Phalcon_Assets_Manager, applyFilters);
PHP_METHOD(Phalcon_Assets_Manager, calculatePrefixedPath);
PHP_METHOD(Phalcon_Assets_Manager, checkAndCreateCollection);
PHP_METHOD(Phalcon_Assets_Manager, cssLink);
PHP_METHOD(Phalcon_Assets_Manager, doCallback);
PHP_METHOD(Phalcon_Assets_Manager, getJoin);
PHP_METHOD(Phalcon_Assets_Manager, getOutput);
PHP_METHOD(Phalcon_Assets_Manager, getSourcePath);
PHP_METHOD(Phalcon_Assets_Manager, isFilterNeeded);
PHP_METHOD(Phalcon_Assets_Manager, jsLink);
PHP_METHOD(Phalcon_Assets_Manager, processParameters);
PHP_METHOD(Phalcon_Assets_Manager, phpFclose);
PHP_METHOD(Phalcon_Assets_Manager, phpFgetCsv);
PHP_METHOD(Phalcon_Assets_Manager, phpFileExists);
PHP_METHOD(Phalcon_Assets_Manager, phpFileGetContents);
PHP_METHOD(Phalcon_Assets_Manager, phpFilePutContents);
PHP_METHOD(Phalcon_Assets_Manager, phpFopen);
PHP_METHOD(Phalcon_Assets_Manager, phpFwrite);
PHP_METHOD(Phalcon_Assets_Manager, phpIsWritable);
PHP_METHOD(Phalcon_Assets_Manager, phpUnlink);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, tagFactory, Phalcon\\Html\\TagFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addasset, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addassetbytype, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addcss, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, local, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, _IS_BOOL, 0, "true")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, version, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, autoVersion, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addinlinecode, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addinlinecodebytype, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addinlinecss, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, _IS_BOOL, 0, "true")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addinlinejs, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, _IS_BOOL, 0, "true")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_addjs, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, local, _IS_BOOL, 0, "true")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, filter, _IS_BOOL, 0, "true")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, version, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, autoVersion, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 1, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_collectionassetsbytype, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, assets, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_exists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 1, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getcollections, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_getcss, 0, 0, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_getjs, 0, 0, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 2, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinline, 0, 2, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinecss, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputinlinejs, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_set, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_setoptions, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, implicitOutput, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_applyfilters, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, mustFilter, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_calculateprefixedpath, 0, 3, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_assets_manager_checkandcreatecollection, 0, 1, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_csslink, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, local, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_docallback, 0, 4, IS_STRING, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
	ZEND_ARG_TYPE_INFO(0, prefixedPath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getjoin, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, completeTargetPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getoutput, 0, 4, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_TYPE_INFO(0, completeTargetPath, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, callback, 0)
	ZEND_ARG_TYPE_INFO(0, output, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_getsourcepath, 0, 2, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
	ZEND_ARG_TYPE_INFO(0, completeSourcePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_isfilterneeded, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, asset, Phalcon\\Assets\\Asset, 0)
	ZEND_ARG_TYPE_INFO(0, targetPath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, sourcePath, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, filterNeeded, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_jslink, 0, 0, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, local, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_processparameters, 0, 5, IS_STRING, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_TYPE_INFO(0, local, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, helperClass, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_phpfopen, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, useIncludePath, _IS_BOOL, 0, "false")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_assets_manager_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_assets_manager_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, context)
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
	PHP_ME(Phalcon_Assets_Manager, getJs, arginfo_phalcon_assets_manager_getjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getOptions, arginfo_phalcon_assets_manager_getoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, has, arginfo_phalcon_assets_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, output, arginfo_phalcon_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInline, arginfo_phalcon_assets_manager_outputinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineCss, arginfo_phalcon_assets_manager_outputinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineJs, arginfo_phalcon_assets_manager_outputinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, applyFilters, arginfo_phalcon_assets_manager_applyfilters, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, calculatePrefixedPath, arginfo_phalcon_assets_manager_calculateprefixedpath, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, checkAndCreateCollection, arginfo_phalcon_assets_manager_checkandcreatecollection, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, cssLink, arginfo_phalcon_assets_manager_csslink, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, doCallback, arginfo_phalcon_assets_manager_docallback, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, getJoin, arginfo_phalcon_assets_manager_getjoin, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, getOutput, arginfo_phalcon_assets_manager_getoutput, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, getSourcePath, arginfo_phalcon_assets_manager_getsourcepath, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, isFilterNeeded, arginfo_phalcon_assets_manager_isfilterneeded, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, jsLink, arginfo_phalcon_assets_manager_jslink, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, processParameters, arginfo_phalcon_assets_manager_processparameters, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Assets_Manager, phpFclose, arginfo_phalcon_assets_manager_phpfclose, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFgetCsv, arginfo_phalcon_assets_manager_phpfgetcsv, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFileExists, arginfo_phalcon_assets_manager_phpfileexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFileGetContents, arginfo_phalcon_assets_manager_phpfilegetcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFilePutContents, arginfo_phalcon_assets_manager_phpfileputcontents, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFopen, arginfo_phalcon_assets_manager_phpfopen, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpFwrite, arginfo_phalcon_assets_manager_phpfwrite, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpIsWritable, arginfo_phalcon_assets_manager_phpiswritable, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Assets_Manager, phpUnlink, arginfo_phalcon_assets_manager_phpunlink, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
