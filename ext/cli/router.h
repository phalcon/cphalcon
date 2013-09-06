
extern zend_class_entry *phalcon_cli_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_CLI_Router);

PHP_METHOD(Phalcon_CLI_Router, setDI);
PHP_METHOD(Phalcon_CLI_Router, getDI);
PHP_METHOD(Phalcon_CLI_Router, setDefaultModule);
PHP_METHOD(Phalcon_CLI_Router, setDefaultTask);
PHP_METHOD(Phalcon_CLI_Router, setDefaultAction);
PHP_METHOD(Phalcon_CLI_Router, handle);
PHP_METHOD(Phalcon_CLI_Router, getModuleName);
PHP_METHOD(Phalcon_CLI_Router, getTaskName);
PHP_METHOD(Phalcon_CLI_Router, getActionName);
PHP_METHOD(Phalcon_CLI_Router, getParams);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setDI, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setDefaultModule, 0, 0, 0)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setDefaultTask, 0, 0, 0)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setDefaultAction, 0, 0, 0)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_method_entry) {
	PHP_ME(Phalcon_CLI_Router, setDI, arginfo_phalcon_cli_router_setDI, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, setDefaultModule, arginfo_phalcon_cli_router_setDefaultModule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, setDefaultTask, arginfo_phalcon_cli_router_setDefaultTask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, setDefaultAction, arginfo_phalcon_cli_router_setDefaultAction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_CLI_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
