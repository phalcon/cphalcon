
extern zend_class_entry *phalcon_cli_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, compilePattern, arginfo_phalcon_cli_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, reConfigure, arginfo_phalcon_cli_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, setName, arginfo_phalcon_cli_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getCompiledPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_Router_RouteInterface, getReversedPaths, NULL)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
