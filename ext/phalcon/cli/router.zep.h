
extern zend_class_entry *phalcon_cli_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router);

PHP_METHOD(Phalcon_Cli_Router, __construct);
PHP_METHOD(Phalcon_Cli_Router, setDI);
PHP_METHOD(Phalcon_Cli_Router, getDI);
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule);
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask);
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction);
PHP_METHOD(Phalcon_Cli_Router, setDefaults);
PHP_METHOD(Phalcon_Cli_Router, handle);
PHP_METHOD(Phalcon_Cli_Router, add);
PHP_METHOD(Phalcon_Cli_Router, getModuleName);
PHP_METHOD(Phalcon_Cli_Router, getTaskName);
PHP_METHOD(Phalcon_Cli_Router, getActionName);
PHP_METHOD(Phalcon_Cli_Router, getParams);
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute);
PHP_METHOD(Phalcon_Cli_Router, getMatches);
PHP_METHOD(Phalcon_Cli_Router, wasMatched);
PHP_METHOD(Phalcon_Cli_Router, getRoutes);
PHP_METHOD(Phalcon_Cli_Router, getRouteById);
PHP_METHOD(Phalcon_Cli_Router, getRouteByName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_method_entry) {
	PHP_ME(Phalcon_Cli_Router, __construct, arginfo_phalcon_cli_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Router, setDI, arginfo_phalcon_cli_router_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultModule, arginfo_phalcon_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultTask, arginfo_phalcon_cli_router_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultAction, arginfo_phalcon_cli_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaults, arginfo_phalcon_cli_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, add, arginfo_phalcon_cli_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteById, arginfo_phalcon_cli_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteByName, arginfo_phalcon_cli_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
