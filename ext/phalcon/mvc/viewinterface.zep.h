
extern zend_class_entry *phalcon_mvc_viewinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_cleantemplateafter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_cleantemplatebefore, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_disable, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_enable, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_finish, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getactionname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_getactiverenderpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getbasepath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getcontrollername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getlayout, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getlayoutsdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getmainview, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_getpartialsdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewinterface_isdisabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_pick, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, renderView, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_registerengines, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, engines, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_render, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_reset, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, basePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayout, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, layout, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, layoutsDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setmainview, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, viewPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setpartialsdir, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, partialsDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_viewinterface_setrenderlevel, 0, 1, Phalcon\\Mvc\\ViewInterface, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_start, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_viewinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateAfter, arginfo_phalcon_mvc_viewinterface_cleantemplateafter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateBefore, arginfo_phalcon_mvc_viewinterface_cleantemplatebefore)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, disable, arginfo_phalcon_mvc_viewinterface_disable)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, enable, arginfo_phalcon_mvc_viewinterface_enable)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, finish, arginfo_phalcon_mvc_viewinterface_finish)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActionName, arginfo_phalcon_mvc_viewinterface_getactionname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActiveRenderPath, arginfo_phalcon_mvc_viewinterface_getactiverenderpath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getBasePath, arginfo_phalcon_mvc_viewinterface_getbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getControllerName, arginfo_phalcon_mvc_viewinterface_getcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayout, arginfo_phalcon_mvc_viewinterface_getlayout)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayoutsDir, arginfo_phalcon_mvc_viewinterface_getlayoutsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getMainView, arginfo_phalcon_mvc_viewinterface_getmainview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getPartialsDir, arginfo_phalcon_mvc_viewinterface_getpartialsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, isDisabled, arginfo_phalcon_mvc_viewinterface_isdisabled)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, pick, arginfo_phalcon_mvc_viewinterface_pick)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, registerEngines, arginfo_phalcon_mvc_viewinterface_registerengines)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, render, arginfo_phalcon_mvc_viewinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, reset, arginfo_phalcon_mvc_viewinterface_reset)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setBasePath, arginfo_phalcon_mvc_viewinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayout, arginfo_phalcon_mvc_viewinterface_setlayout)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayoutsDir, arginfo_phalcon_mvc_viewinterface_setlayoutsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setMainView, arginfo_phalcon_mvc_viewinterface_setmainview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setPartialsDir, arginfo_phalcon_mvc_viewinterface_setpartialsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setRenderLevel, arginfo_phalcon_mvc_viewinterface_setrenderlevel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateAfter, arginfo_phalcon_mvc_viewinterface_settemplateafter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateBefore, arginfo_phalcon_mvc_viewinterface_settemplatebefore)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, start, arginfo_phalcon_mvc_viewinterface_start)
	PHP_FE_END
};
