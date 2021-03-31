
extern zend_class_entry *phalcon_mvc_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Route);

PHP_METHOD(Phalcon_Mvc_Router_Route, getId);
PHP_METHOD(Phalcon_Mvc_Router_Route, __construct);
PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, convert);
PHP_METHOD(Phalcon_Mvc_Router_Route, extractNamedParams);
PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch);
PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters);
PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup);
PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname);
PHP_METHOD(Phalcon_Mvc_Router_Route, getMatch);
PHP_METHOD(Phalcon_Mvc_Router_Route, getName);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern);
PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId);
PHP_METHOD(Phalcon_Mvc_Router_Route, getRoutePaths);
PHP_METHOD(Phalcon_Mvc_Router_Route, match);
PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure);
PHP_METHOD(Phalcon_Mvc_Router_Route, reset);
PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup);
PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods);
PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname);
PHP_METHOD(Phalcon_Mvc_Router_Route, setName);
PHP_METHOD(Phalcon_Mvc_Router_Route, via);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_beforematch, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_compilepattern, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_convert, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_extractnamedparams, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_getbeforematch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getcompiledpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getconverters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_getgroup, 0, 0, Phalcon\\Mvc\\Router\\GroupInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_gethttpmethods, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_gethostname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_getmatch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getreversedpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getrouteid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_getroutepaths, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_match, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_reconfigure, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_route_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_setgroup, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_sethttpmethods, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_sethostname, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, hostname, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_setname, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_route_via, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_route_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Route, getId, arginfo_phalcon_mvc_router_route_getid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Route, getId, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Route, __construct, arginfo_phalcon_mvc_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Route, beforeMatch, arginfo_phalcon_mvc_router_route_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, compilePattern, arginfo_phalcon_mvc_router_route_compilepattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, convert, arginfo_phalcon_mvc_router_route_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, extractNamedParams, arginfo_phalcon_mvc_router_route_extractnamedparams, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Route, getBeforeMatch, arginfo_phalcon_mvc_router_route_getbeforematch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Route, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Route, getCompiledPattern, arginfo_phalcon_mvc_router_route_getcompiledpattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getConverters, arginfo_phalcon_mvc_router_route_getconverters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getGroup, arginfo_phalcon_mvc_router_route_getgroup, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Route, getHttpMethods, arginfo_phalcon_mvc_router_route_gethttpmethods, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Route, getHttpMethods, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Route, getHostname, arginfo_phalcon_mvc_router_route_gethostname, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Router_Route, getMatch, arginfo_phalcon_mvc_router_route_getmatch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Router_Route, getMatch, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Router_Route, getName, arginfo_phalcon_mvc_router_route_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPaths, arginfo_phalcon_mvc_router_route_getpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPattern, arginfo_phalcon_mvc_router_route_getpattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getReversedPaths, arginfo_phalcon_mvc_router_route_getreversedpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getRouteId, arginfo_phalcon_mvc_router_route_getrouteid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getRoutePaths, arginfo_phalcon_mvc_router_route_getroutepaths, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Router_Route, match, arginfo_phalcon_mvc_router_route_match, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reConfigure, arginfo_phalcon_mvc_router_route_reconfigure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reset, arginfo_phalcon_mvc_router_route_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setGroup, arginfo_phalcon_mvc_router_route_setgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHttpMethods, arginfo_phalcon_mvc_router_route_sethttpmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHostname, arginfo_phalcon_mvc_router_route_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setName, arginfo_phalcon_mvc_router_route_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, via, arginfo_phalcon_mvc_router_route_via, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
