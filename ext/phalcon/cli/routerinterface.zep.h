
extern zend_class_entry *phalcon_cli_routerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultModule, arginfo_phalcon_cli_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultTask, arginfo_phalcon_cli_routerinterface_setdefaulttask)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaultAction, arginfo_phalcon_cli_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, setDefaults, arginfo_phalcon_cli_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, handle, arginfo_phalcon_cli_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, add, arginfo_phalcon_cli_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getModuleName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getTaskName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getMatchedRoute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getMatches, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, wasMatched, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRouteById, arginfo_phalcon_cli_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Cli_RouterInterface, getRouteByName, arginfo_phalcon_cli_routerinterface_getroutebyname)
	PHP_FE_END
};
