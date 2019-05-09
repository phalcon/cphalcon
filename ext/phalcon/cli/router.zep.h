
extern zend_class_entry *phalcon_cli_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router);

PHP_METHOD(Phalcon_Cli_Router, __construct);
PHP_METHOD(Phalcon_Cli_Router, add);
PHP_METHOD(Phalcon_Cli_Router, getActionName);
PHP_METHOD(Phalcon_Cli_Router, getDI);
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Cli_Router, getMatches);
PHP_METHOD(Phalcon_Cli_Router, getModuleName);
PHP_METHOD(Phalcon_Cli_Router, getParams);
PHP_METHOD(Phalcon_Cli_Router, getRouteById);
PHP_METHOD(Phalcon_Cli_Router, getRouteByName);
PHP_METHOD(Phalcon_Cli_Router, getRoutes);
PHP_METHOD(Phalcon_Cli_Router, getTaskName);
PHP_METHOD(Phalcon_Cli_Router, handle);
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction);
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule);
PHP_METHOD(Phalcon_Cli_Router, setDefaults);
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask);
PHP_METHOD(Phalcon_Cli_Router, setDI);
PHP_METHOD(Phalcon_Cli_Router, wasMatched);
zend_object *zephir_init_properties_Phalcon_Cli_Router(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultRoutes, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, defaultRoutes)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_add, 0, 1, Phalcon\\Cli\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_add, 0, 1, IS_OBJECT, "Phalcon\\Cli\\RouteInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getactionname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getactionname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_getdi, 0, 0, Phalcon\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getdi, 0, 0, IS_OBJECT, "Phalcon\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_getmatchedroute, 0, 0, Phalcon\\Cli\\RouteInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getmatchedroute, 0, 0, IS_OBJECT, "Phalcon\\Cli\\RouteInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getmatches, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getmatches, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getmodulename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getmodulename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getparams, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getparams, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getroutes, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_getroutes, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_gettaskname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_gettaskname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultaction, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, actionName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultmodule, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_setdefaults, 0, 1, Phalcon\\Cli\\Router, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_setdefaults, 0, 1, IS_OBJECT, "Phalcon\\Cli\\Router", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaulttask, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, taskName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, taskName)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_wasmatched, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_wasmatched, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_method_entry) {
	PHP_ME(Phalcon_Cli_Router, __construct, arginfo_phalcon_cli_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Router, add, arginfo_phalcon_cli_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getActionName, arginfo_phalcon_cli_router_getactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getDI, arginfo_phalcon_cli_router_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatchedRoute, arginfo_phalcon_cli_router_getmatchedroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatches, arginfo_phalcon_cli_router_getmatches, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getModuleName, arginfo_phalcon_cli_router_getmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getParams, arginfo_phalcon_cli_router_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteById, arginfo_phalcon_cli_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteByName, arginfo_phalcon_cli_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRoutes, arginfo_phalcon_cli_router_getroutes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getTaskName, arginfo_phalcon_cli_router_gettaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultAction, arginfo_phalcon_cli_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultModule, arginfo_phalcon_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaults, arginfo_phalcon_cli_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultTask, arginfo_phalcon_cli_router_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDI, arginfo_phalcon_cli_router_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, wasMatched, arginfo_phalcon_cli_router_wasmatched, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
