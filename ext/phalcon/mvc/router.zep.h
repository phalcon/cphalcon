
extern zend_class_entry *phalcon_mvc_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router);

PHP_METHOD(Phalcon_Mvc_Router, __construct);
PHP_METHOD(Phalcon_Mvc_Router, add);
PHP_METHOD(Phalcon_Mvc_Router, addConnect);
PHP_METHOD(Phalcon_Mvc_Router, addDelete);
PHP_METHOD(Phalcon_Mvc_Router, addGet);
PHP_METHOD(Phalcon_Mvc_Router, addHead);
PHP_METHOD(Phalcon_Mvc_Router, addOptions);
PHP_METHOD(Phalcon_Mvc_Router, addPatch);
PHP_METHOD(Phalcon_Mvc_Router, addPost);
PHP_METHOD(Phalcon_Mvc_Router, addPurge);
PHP_METHOD(Phalcon_Mvc_Router, addPut);
PHP_METHOD(Phalcon_Mvc_Router, addTrace);
PHP_METHOD(Phalcon_Mvc_Router, attach);
PHP_METHOD(Phalcon_Mvc_Router, clear);
PHP_METHOD(Phalcon_Mvc_Router, getEventsManager);
PHP_METHOD(Phalcon_Mvc_Router, getActionName);
PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
PHP_METHOD(Phalcon_Mvc_Router, getDefaults);
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteNames);
PHP_METHOD(Phalcon_Mvc_Router, getKeyRouteIds);
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Mvc_Router, getMatches);
PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
PHP_METHOD(Phalcon_Mvc_Router, getParams);
PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);
PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router, handle);
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName);
PHP_METHOD(Phalcon_Mvc_Router, mount);
PHP_METHOD(Phalcon_Mvc_Router, notFound);
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
PHP_METHOD(Phalcon_Mvc_Router, setEventsManager);
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteNames);
PHP_METHOD(Phalcon_Mvc_Router, setKeyRouteIds);
PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
zend_object *zephir_init_properties_Phalcon_Mvc_Router(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, defaultRoutes, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_add, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addconnect, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_adddelete, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addget, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addhead, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addoptions, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addpatch, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addpost, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addpurge, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addput, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_addtrace, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_attach, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, route, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_clear, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getactionname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getcontrollername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getdefaults, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getkeyroutenames, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getkeyrouteids, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_getmatchedroute, 0, 0, Phalcon\\Mvc\\Router\\RouteInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getmatches, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getmodulename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getnamespacename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_getroutes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_handle, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_isexactcontrollername, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_mount, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_notfound, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_removeextraslashes, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, remove, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setdefaultaction, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setdefaultcontroller, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, controllerName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setdefaultmodule, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setdefaultnamespace, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, namespaceName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setdefaults, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setkeyroutenames, 0, 1, Phalcon\\Mvc\\Router, 0)
	ZEND_ARG_ARRAY_INFO(0, routeNames, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_setkeyrouteids, 0, 1, Phalcon\\Mvc\\Router, 0)
	ZEND_ARG_ARRAY_INFO(0, routeIds, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_wasmatched, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_zephir_init_properties_phalcon_mvc_router, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_method_entry) {
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addConnect, arginfo_phalcon_mvc_router_addconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_router_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_router_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_router_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_router_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPatch, arginfo_phalcon_mvc_router_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_router_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPurge, arginfo_phalcon_mvc_router_addpurge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_router_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addTrace, arginfo_phalcon_mvc_router_addtrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, attach, arginfo_phalcon_mvc_router_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, clear, arginfo_phalcon_mvc_router_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getEventsManager, arginfo_phalcon_mvc_router_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getActionName, arginfo_phalcon_mvc_router_getactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getControllerName, arginfo_phalcon_mvc_router_getcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaults, arginfo_phalcon_mvc_router_getdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getKeyRouteNames, arginfo_phalcon_mvc_router_getkeyroutenames, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getKeyRouteIds, arginfo_phalcon_mvc_router_getkeyrouteids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, arginfo_phalcon_mvc_router_getmatchedroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatches, arginfo_phalcon_mvc_router_getmatches, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getModuleName, arginfo_phalcon_mvc_router_getmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, arginfo_phalcon_mvc_router_getnamespacename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getParams, arginfo_phalcon_mvc_router_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRoutes, arginfo_phalcon_mvc_router_getroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, isExactControllerName, arginfo_phalcon_mvc_router_isexactcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, mount, arginfo_phalcon_mvc_router_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, notFound, arginfo_phalcon_mvc_router_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setEventsManager, arginfo_phalcon_mvc_router_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setKeyRouteNames, arginfo_phalcon_mvc_router_setkeyroutenames, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setKeyRouteIds, arginfo_phalcon_mvc_router_setkeyrouteids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, wasMatched, arginfo_phalcon_mvc_router_wasmatched, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
