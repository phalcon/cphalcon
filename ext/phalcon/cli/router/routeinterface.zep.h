
extern zend_class_entry *phalcon_cli_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_RouteInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_compilepattern, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_compilepattern, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_reconfigure, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, pattern)
#endif
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_setname, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getrouteid, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getrouteid, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpattern, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpattern, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getcompiledpattern, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getcompiledpattern, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpaths, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpaths, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getreversedpaths, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getreversedpaths, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_delimiter, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getdelimiter, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getdelimiter, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, compilePattern, arginfo_phalcon_cli_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, reConfigure, arginfo_phalcon_cli_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getName, arginfo_phalcon_cli_router_routeinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, setName, arginfo_phalcon_cli_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getRouteId, arginfo_phalcon_cli_router_routeinterface_getrouteid)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPattern, arginfo_phalcon_cli_router_routeinterface_getpattern)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getCompiledPattern, arginfo_phalcon_cli_router_routeinterface_getcompiledpattern)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPaths, arginfo_phalcon_cli_router_routeinterface_getpaths)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getReversedPaths, arginfo_phalcon_cli_router_routeinterface_getreversedpaths)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(delimiter, NULL, arginfo_phalcon_cli_router_routeinterface_delimiter, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDelimiter, NULL, arginfo_phalcon_cli_router_routeinterface_getdelimiter, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
