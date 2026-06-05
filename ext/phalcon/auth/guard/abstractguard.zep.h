
extern zend_class_entry *phalcon_auth_guard_abstractguard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_AbstractGuard);

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, __construct);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getConfig);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, check);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getAdapter);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getLastUserAttempted);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, guest);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasUser);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, id);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setAdapter);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setUser);
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasValidCredentials);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_abstractguard___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Contracts\\Auth\\Guard\\GuardConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_getconfig, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\GuardConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_getadapter, 0, 0, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_getlastuserattempted, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_guest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_hasuser, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_abstractguard_id, 0, 0, MAY_BE_NULL|MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_abstractguard_setadapter, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_abstractguard_setuser, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_abstractguard_hasvalidcredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_abstractguard_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, __construct, arginfo_phalcon_auth_guard_abstractguard___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, getConfig, arginfo_phalcon_auth_guard_abstractguard_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, check, arginfo_phalcon_auth_guard_abstractguard_check, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, getAdapter, arginfo_phalcon_auth_guard_abstractguard_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, getLastUserAttempted, arginfo_phalcon_auth_guard_abstractguard_getlastuserattempted, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, guest, arginfo_phalcon_auth_guard_abstractguard_guest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, hasUser, arginfo_phalcon_auth_guard_abstractguard_hasuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, id, arginfo_phalcon_auth_guard_abstractguard_id, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, setAdapter, arginfo_phalcon_auth_guard_abstractguard_setadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, setUser, arginfo_phalcon_auth_guard_abstractguard_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_AbstractGuard, hasValidCredentials, arginfo_phalcon_auth_guard_abstractguard_hasvalidcredentials, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
