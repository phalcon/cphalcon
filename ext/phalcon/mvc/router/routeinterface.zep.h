
extern zend_class_entry *phalcon_mvc_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_convert, 0, 2, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getcompiledpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_gethostname, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_gethttpmethods, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getname, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getreversedpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_getrouteid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethostname, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, hostname, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 1, Phalcon\\Mvc\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, convert, arginfo_phalcon_mvc_router_routeinterface_convert)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern, arginfo_phalcon_mvc_router_routeinterface_getcompiledpattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHostname, arginfo_phalcon_mvc_router_routeinterface_gethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHttpMethods, arginfo_phalcon_mvc_router_routeinterface_gethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getName, arginfo_phalcon_mvc_router_routeinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPaths, arginfo_phalcon_mvc_router_routeinterface_getpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPattern, arginfo_phalcon_mvc_router_routeinterface_getpattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getReversedPaths, arginfo_phalcon_mvc_router_routeinterface_getreversedpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getRouteId, arginfo_phalcon_mvc_router_routeinterface_getrouteid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHostname, arginfo_phalcon_mvc_router_routeinterface_sethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setName, arginfo_phalcon_mvc_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure)
	ZEND_FENTRY(reset, NULL, arginfo_phalcon_mvc_router_routeinterface_reset, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, via, arginfo_phalcon_mvc_router_routeinterface_via)
	PHP_FE_END
};
