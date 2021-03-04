
extern zend_class_entry *phalcon_cli_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Route);

PHP_METHOD(Phalcon_Cli_Router_Route, __construct);
PHP_METHOD(Phalcon_Cli_Router_Route, beforeMatch);
PHP_METHOD(Phalcon_Cli_Router_Route, compilePattern);
PHP_METHOD(Phalcon_Cli_Router_Route, convert);
PHP_METHOD(Phalcon_Cli_Router_Route, delimiter);
PHP_METHOD(Phalcon_Cli_Router_Route, extractNamedParams);
PHP_METHOD(Phalcon_Cli_Router_Route, getBeforeMatch);
PHP_METHOD(Phalcon_Cli_Router_Route, getCompiledPattern);
PHP_METHOD(Phalcon_Cli_Router_Route, getConverters);
PHP_METHOD(Phalcon_Cli_Router_Route, getDelimiter);
PHP_METHOD(Phalcon_Cli_Router_Route, getDescription);
PHP_METHOD(Phalcon_Cli_Router_Route, getName);
PHP_METHOD(Phalcon_Cli_Router_Route, getPaths);
PHP_METHOD(Phalcon_Cli_Router_Route, getPattern);
PHP_METHOD(Phalcon_Cli_Router_Route, getReversedPaths);
PHP_METHOD(Phalcon_Cli_Router_Route, getRouteId);
PHP_METHOD(Phalcon_Cli_Router_Route, reConfigure);
PHP_METHOD(Phalcon_Cli_Router_Route, reset);
PHP_METHOD(Phalcon_Cli_Router_Route, setDescription);
PHP_METHOD(Phalcon_Cli_Router_Route, setName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_route_beforematch, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_compilepattern, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_route_convert, 0, 2, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_delimiter, 0, 0, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_extractnamedparams, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_getbeforematch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getcompiledpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getconverters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getdelimiter, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getdescription, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getpattern, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getreversedpaths, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_getrouteid, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_reconfigure, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cli_router_route_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_route_setdescription, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, description, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cli_router_route_setname, 0, 1, Phalcon\\Cli\\Router\\RouteInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_route_method_entry) {
	PHP_ME(Phalcon_Cli_Router_Route, __construct, arginfo_phalcon_cli_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Router_Route, beforeMatch, arginfo_phalcon_cli_router_route_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, compilePattern, arginfo_phalcon_cli_router_route_compilepattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, convert, arginfo_phalcon_cli_router_route_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, delimiter, arginfo_phalcon_cli_router_route_delimiter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Cli_Router_Route, extractNamedParams, arginfo_phalcon_cli_router_route_extractnamedparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getBeforeMatch, arginfo_phalcon_cli_router_route_getbeforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getCompiledPattern, arginfo_phalcon_cli_router_route_getcompiledpattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getConverters, arginfo_phalcon_cli_router_route_getconverters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getDelimiter, arginfo_phalcon_cli_router_route_getdelimiter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Cli_Router_Route, getDescription, arginfo_phalcon_cli_router_route_getdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getName, arginfo_phalcon_cli_router_route_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getPaths, arginfo_phalcon_cli_router_route_getpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getPattern, arginfo_phalcon_cli_router_route_getpattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getReversedPaths, arginfo_phalcon_cli_router_route_getreversedpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getRouteId, arginfo_phalcon_cli_router_route_getrouteid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, reConfigure, arginfo_phalcon_cli_router_route_reconfigure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, reset, arginfo_phalcon_cli_router_route_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Cli_Router_Route, setDescription, arginfo_phalcon_cli_router_route_setdescription, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, setName, arginfo_phalcon_cli_router_route_setname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
