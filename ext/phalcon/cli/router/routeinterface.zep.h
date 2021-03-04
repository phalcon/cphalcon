
extern zend_class_entry *phalcon_cli_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_RouteInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_compilepattern, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_delimiter, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getcompiledpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getdelimiter, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getdescription, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getreversedpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_getrouteid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_reconfigure, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_routeinterface_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_routeinterface_setdescription, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, description, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_routeinterface_setname, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, compilePattern, arginfo_phalcon_cli_router_routeinterface_compilepattern)
	ZEND_FENTRY(delimiter, NULL, arginfo_phalcon_cli_router_routeinterface_delimiter, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getCompiledPattern, arginfo_phalcon_cli_router_routeinterface_getcompiledpattern)
	ZEND_FENTRY(getDelimiter, NULL, arginfo_phalcon_cli_router_routeinterface_getdelimiter, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getDescription, arginfo_phalcon_cli_router_routeinterface_getdescription)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getName, arginfo_phalcon_cli_router_routeinterface_getname)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPaths, arginfo_phalcon_cli_router_routeinterface_getpaths)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPattern, arginfo_phalcon_cli_router_routeinterface_getpattern)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getReversedPaths, arginfo_phalcon_cli_router_routeinterface_getreversedpaths)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getRouteId, arginfo_phalcon_cli_router_routeinterface_getrouteid)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, reConfigure, arginfo_phalcon_cli_router_routeinterface_reconfigure)
	ZEND_FENTRY(reset, NULL, arginfo_phalcon_cli_router_routeinterface_reset, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, setDescription, arginfo_phalcon_cli_router_routeinterface_setdescription)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, setName, arginfo_phalcon_cli_router_routeinterface_setname)
	PHP_FE_END
};
