
extern zend_class_entry *phalcon_auth_cli_authdispatcherlistener_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Cli_AuthDispatcherListener);

PHP_METHOD(Phalcon_Auth_Cli_AuthDispatcherListener, beforeExecuteRoute);
PHP_METHOD(Phalcon_Auth_Cli_AuthDispatcherListener, getActionType);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_cli_authdispatcherlistener_beforeexecuteroute, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Cli\\Dispatcher, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_cli_authdispatcherlistener_getactiontype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_cli_authdispatcherlistener_method_entry) {
	PHP_ME(Phalcon_Auth_Cli_AuthDispatcherListener, beforeExecuteRoute, arginfo_phalcon_auth_cli_authdispatcherlistener_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Cli_AuthDispatcherListener, getActionType, arginfo_phalcon_auth_cli_authdispatcherlistener_getactiontype, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
