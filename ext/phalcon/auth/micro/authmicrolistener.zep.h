
extern zend_class_entry *phalcon_auth_micro_authmicrolistener_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Micro_AuthMicroListener);

PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, __construct);
PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, beforeExecuteRoute);
PHP_METHOD(Phalcon_Auth_Micro_AuthMicroListener, getActionType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_micro_authmicrolistener___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Contracts\\Auth\\Manager, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, componentName, IS_STRING, 0, "'Micro'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_micro_authmicrolistener_beforeexecuteroute, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, application, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_micro_authmicrolistener_getactiontype, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_micro_authmicrolistener_method_entry) {
	PHP_ME(Phalcon_Auth_Micro_AuthMicroListener, __construct, arginfo_phalcon_auth_micro_authmicrolistener___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Micro_AuthMicroListener, beforeExecuteRoute, arginfo_phalcon_auth_micro_authmicrolistener_beforeexecuteroute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Micro_AuthMicroListener, getActionType, arginfo_phalcon_auth_micro_authmicrolistener_getactiontype, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
