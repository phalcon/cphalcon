
extern zend_class_entry *phalcon_cli_routerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_RouterInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_routerinterface_add, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getactionname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_routerinterface_getmatchedroute, 0, 0, Phalcon\\Cli\\Router\\RouteInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getmatches, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getmodulename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getparameters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_getroutes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_gettaskname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaultaction, 0, 1, Phalcon\\Cli\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaultmodule, 0, 1, Phalcon\\Cli\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaults, 0, 1, Phalcon\\Cli\\RouterInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaulttask, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_routerinterface_wasmatched, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, add, arginfo_phalcon_cli_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getActionName, arginfo_phalcon_cli_routerinterface_getactionname)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getMatchedRoute, arginfo_phalcon_cli_routerinterface_getmatchedroute)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getMatches, arginfo_phalcon_cli_routerinterface_getmatches)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getModuleName, arginfo_phalcon_cli_routerinterface_getmodulename)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getParams, arginfo_phalcon_cli_routerinterface_getparams)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getParameters, arginfo_phalcon_cli_routerinterface_getparameters)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRouteById, arginfo_phalcon_cli_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRouteByName, arginfo_phalcon_cli_routerinterface_getroutebyname)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRoutes, arginfo_phalcon_cli_routerinterface_getroutes)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getTaskName, arginfo_phalcon_cli_routerinterface_gettaskname)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, handle, arginfo_phalcon_cli_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultAction, arginfo_phalcon_cli_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultModule, arginfo_phalcon_cli_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaults, arginfo_phalcon_cli_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultTask, arginfo_phalcon_cli_routerinterface_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, wasMatched, arginfo_phalcon_cli_routerinterface_wasmatched)
	PHP_FE_END
};
