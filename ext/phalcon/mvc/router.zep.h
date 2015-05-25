
extern zend_class_entry *phalcon_mvc_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router);

PHP_METHOD(Phalcon_Mvc_Router, __construct);
PHP_METHOD(Phalcon_Mvc_Router, setDI);
PHP_METHOD(Phalcon_Mvc_Router, getDI);
PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri);
PHP_METHOD(Phalcon_Mvc_Router, setUriSource);
PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
PHP_METHOD(Phalcon_Mvc_Router, getDefaults);
PHP_METHOD(Phalcon_Mvc_Router, handle);
PHP_METHOD(Phalcon_Mvc_Router, add);
PHP_METHOD(Phalcon_Mvc_Router, addGet);
PHP_METHOD(Phalcon_Mvc_Router, addPost);
PHP_METHOD(Phalcon_Mvc_Router, addPut);
PHP_METHOD(Phalcon_Mvc_Router, addPatch);
PHP_METHOD(Phalcon_Mvc_Router, addDelete);
PHP_METHOD(Phalcon_Mvc_Router, addOptions);
PHP_METHOD(Phalcon_Mvc_Router, addHead);
PHP_METHOD(Phalcon_Mvc_Router, mount);
PHP_METHOD(Phalcon_Mvc_Router, notFound);
PHP_METHOD(Phalcon_Mvc_Router, clear);
PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
PHP_METHOD(Phalcon_Mvc_Router, getActionName);
PHP_METHOD(Phalcon_Mvc_Router, getParams);
PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Mvc_Router, getMatches);
PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);
PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_seturisource, 0, 0, 1)
	ZEND_ARG_INFO(0, uriSource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_removeextraslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_mount, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_method_entry) {
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router, setDI, arginfo_phalcon_mvc_router_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRewriteUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setUriSource, arginfo_phalcon_mvc_router_seturisource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_router_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_router_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_router_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPatch, arginfo_phalcon_mvc_router_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_router_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_router_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_router_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, mount, arginfo_phalcon_mvc_router_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, notFound, arginfo_phalcon_mvc_router_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, isExactControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
