
extern zend_class_entry *phalcon_auth_guard_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Session);

PHP_METHOD(Phalcon_Auth_Guard_Session, __construct);
PHP_METHOD(Phalcon_Auth_Guard_Session, fromOptions);
PHP_METHOD(Phalcon_Auth_Guard_Session, attempt);
PHP_METHOD(Phalcon_Auth_Guard_Session, basic);
PHP_METHOD(Phalcon_Auth_Guard_Session, getName);
PHP_METHOD(Phalcon_Auth_Guard_Session, getRememberName);
PHP_METHOD(Phalcon_Auth_Guard_Session, login);
PHP_METHOD(Phalcon_Auth_Guard_Session, loginById);
PHP_METHOD(Phalcon_Auth_Guard_Session, logout);
PHP_METHOD(Phalcon_Auth_Guard_Session, once);
PHP_METHOD(Phalcon_Auth_Guard_Session, onceBasic);
PHP_METHOD(Phalcon_Auth_Guard_Session, user);
PHP_METHOD(Phalcon_Auth_Guard_Session, validate);
PHP_METHOD(Phalcon_Auth_Guard_Session, viaRemember);
PHP_METHOD(Phalcon_Auth_Guard_Session, attemptBasic);
PHP_METHOD(Phalcon_Auth_Guard_Session, basicCredentials);
PHP_METHOD(Phalcon_Auth_Guard_Session, createRememberToken);
PHP_METHOD(Phalcon_Auth_Guard_Session, recaller);
PHP_METHOD(Phalcon_Auth_Guard_Session, rememberUser);
PHP_METHOD(Phalcon_Auth_Guard_Session, userFromRecaller);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_session___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, cookies, Phalcon\\Http\\Response\\CookiesInterface, 0)
	ZEND_ARG_OBJ_INFO(0, session, Phalcon\\Session\\ManagerInterface, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, config, Phalcon\\Auth\\Guard\\Config\\SessionGuardConfig, MAY_BE_NULL, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_session_fromoptions, 0, 3, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_attempt, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_basic, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, field, IS_STRING, 0, "'email'")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_getremembername, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_login, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_auth_guard_session_loginbyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, MAY_BE_FALSE)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_logout, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_once, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_auth_guard_session_oncebasic, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, field, IS_STRING, 0, "'email'")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_session_user, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_validate, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_viaremember, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_attemptbasic, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_basiccredentials, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_session_createremembertoken, 0, 1, Phalcon\\Contracts\\Auth\\RememberToken, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_session_recaller, 0, 0, Phalcon\\Auth\\Guard\\UserRemember, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_session_rememberuser, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_session_userfromrecaller, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_OBJ_INFO(0, recaller, Phalcon\\Auth\\Guard\\UserRemember, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_session_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_Session, __construct, arginfo_phalcon_auth_guard_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guard_Session, fromOptions, arginfo_phalcon_auth_guard_session_fromoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Guard_Session, attempt, arginfo_phalcon_auth_guard_session_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, basic, arginfo_phalcon_auth_guard_session_basic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, getName, arginfo_phalcon_auth_guard_session_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, getRememberName, arginfo_phalcon_auth_guard_session_getremembername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, login, arginfo_phalcon_auth_guard_session_login, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, loginById, arginfo_phalcon_auth_guard_session_loginbyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, logout, arginfo_phalcon_auth_guard_session_logout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, once, arginfo_phalcon_auth_guard_session_once, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, onceBasic, arginfo_phalcon_auth_guard_session_oncebasic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, user, arginfo_phalcon_auth_guard_session_user, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, validate, arginfo_phalcon_auth_guard_session_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, viaRemember, arginfo_phalcon_auth_guard_session_viaremember, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Session, attemptBasic, arginfo_phalcon_auth_guard_session_attemptbasic, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guard_Session, basicCredentials, arginfo_phalcon_auth_guard_session_basiccredentials, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guard_Session, createRememberToken, arginfo_phalcon_auth_guard_session_createremembertoken, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guard_Session, recaller, arginfo_phalcon_auth_guard_session_recaller, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guard_Session, rememberUser, arginfo_phalcon_auth_guard_session_rememberuser, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Guard_Session, userFromRecaller, arginfo_phalcon_auth_guard_session_userfromrecaller, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
