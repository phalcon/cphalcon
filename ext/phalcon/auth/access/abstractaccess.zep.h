
extern zend_class_entry *phalcon_auth_access_abstractaccess_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_AbstractAccess);

PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, __construct);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getExceptActions);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, getOnlyActions);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, isAllowed);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, redirectTo);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setExceptActions);
PHP_METHOD(Phalcon_Auth_Access_AbstractAccess, setOnlyActions);
zend_object *zephir_init_properties_Phalcon_Auth_Access_AbstractAccess(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_abstractaccess___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Contracts\\Auth\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_getexceptactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_getonlyactions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_isallowed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_redirectto, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_setexceptactions, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, exceptActions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_setonlyactions, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, onlyActions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_abstractaccess_zephir_init_properties_phalcon_auth_access_abstractaccess, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_abstractaccess_method_entry) {
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, __construct, arginfo_phalcon_auth_access_abstractaccess___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, getExceptActions, arginfo_phalcon_auth_access_abstractaccess_getexceptactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, getOnlyActions, arginfo_phalcon_auth_access_abstractaccess_getonlyactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, isAllowed, arginfo_phalcon_auth_access_abstractaccess_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, redirectTo, arginfo_phalcon_auth_access_abstractaccess_redirectto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, setExceptActions, arginfo_phalcon_auth_access_abstractaccess_setexceptactions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_AbstractAccess, setOnlyActions, arginfo_phalcon_auth_access_abstractaccess_setonlyactions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
