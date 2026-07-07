
extern zend_class_entry *phalcon_mvc_view_simple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple);

PHP_METHOD(Phalcon_Mvc_View_Simple, __construct);
PHP_METHOD(Phalcon_Mvc_View_Simple, __get);
PHP_METHOD(Phalcon_Mvc_View_Simple, __set);
PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath);
PHP_METHOD(Phalcon_Mvc_View_Simple, getContent);
PHP_METHOD(Phalcon_Mvc_View_Simple, getEventsManager);
PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView);
PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, getVar);
PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir);
PHP_METHOD(Phalcon_Mvc_View_Simple, partial);
PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, render);
PHP_METHOD(Phalcon_Mvc_View_Simple, setContent);
PHP_METHOD(Phalcon_Mvc_View_Simple, setEventsManager);
PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView);
PHP_METHOD(Phalcon_Mvc_View_Simple, setVar);
PHP_METHOD(Phalcon_Mvc_View_Simple, setVars);
PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir);
PHP_METHOD(Phalcon_Mvc_View_Simple, loadTemplateEngines);
PHP_METHOD(Phalcon_Mvc_View_Simple, internalRender);
PHP_METHOD(Phalcon_Mvc_View_Simple, getDirSeparator);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFclose);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFgetCsv);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFileExists);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFileGetContents);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFilePutContents);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFopen);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpFwrite);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpIsWritable);
PHP_METHOD(Phalcon_Mvc_View_Simple, phpUnlink);
zend_object *zephir_init_properties_Phalcon_Mvc_View_Simple(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple___set, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getactiverenderpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getcontent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_view_simple_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getparamstoview, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getregisteredengines, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_getvar, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getviewsdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_partial, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, partialPath, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_registerengines, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, engines, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_render, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_setcontent, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_setparamtoview, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_setvar, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_setvars, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, merge, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_setviewsdir, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, viewsDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_loadtemplateengines, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_internalrender, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_getdirseparator, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, directory, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_phpfclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, handle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_phpfgetcsv, 0, 1, MAY_BE_ARRAY|MAY_BE_FALSE)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 0, "0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, separator, IS_STRING, 0, "','")
	ZEND_ARG_INFO(0, enclosure)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_phpfileexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_phpfilegetcontents, 0, 1, MAY_BE_FALSE|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_phpfileputcontents, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_phpfopen, 0, 2, IS_MIXED, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_view_simple_phpfwrite, 0, 2, MAY_BE_FALSE|MAY_BE_LONG)
	ZEND_ARG_INFO(0, handle)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_phpiswritable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_simple_phpunlink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_zephir_init_properties_phalcon_mvc_view_simple, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_simple_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Simple, __construct, arginfo_phalcon_mvc_view_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Simple, __get, arginfo_phalcon_mvc_view_simple___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __set, arginfo_phalcon_mvc_view_simple___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getActiveRenderPath, arginfo_phalcon_mvc_view_simple_getactiverenderpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getContent, arginfo_phalcon_mvc_view_simple_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getEventsManager, arginfo_phalcon_mvc_view_simple_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getParamsToView, arginfo_phalcon_mvc_view_simple_getparamstoview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getRegisteredEngines, arginfo_phalcon_mvc_view_simple_getregisteredengines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getVar, arginfo_phalcon_mvc_view_simple_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getViewsDir, arginfo_phalcon_mvc_view_simple_getviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, partial, arginfo_phalcon_mvc_view_simple_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, registerEngines, arginfo_phalcon_mvc_view_simple_registerengines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, render, arginfo_phalcon_mvc_view_simple_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setContent, arginfo_phalcon_mvc_view_simple_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setEventsManager, arginfo_phalcon_mvc_view_simple_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setParamToView, arginfo_phalcon_mvc_view_simple_setparamtoview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVar, arginfo_phalcon_mvc_view_simple_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVars, arginfo_phalcon_mvc_view_simple_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setViewsDir, arginfo_phalcon_mvc_view_simple_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, loadTemplateEngines, arginfo_phalcon_mvc_view_simple_loadtemplateengines, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, internalRender, arginfo_phalcon_mvc_view_simple_internalrender, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, getDirSeparator, arginfo_phalcon_mvc_view_simple_getdirseparator, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFclose, arginfo_phalcon_mvc_view_simple_phpfclose, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFgetCsv, arginfo_phalcon_mvc_view_simple_phpfgetcsv, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFileExists, arginfo_phalcon_mvc_view_simple_phpfileexists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFileGetContents, arginfo_phalcon_mvc_view_simple_phpfilegetcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFilePutContents, arginfo_phalcon_mvc_view_simple_phpfileputcontents, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFopen, arginfo_phalcon_mvc_view_simple_phpfopen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpFwrite, arginfo_phalcon_mvc_view_simple_phpfwrite, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpIsWritable, arginfo_phalcon_mvc_view_simple_phpiswritable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, phpUnlink, arginfo_phalcon_mvc_view_simple_phpunlink, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
