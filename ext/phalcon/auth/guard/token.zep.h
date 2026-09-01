
extern zend_class_entry *phalcon_auth_guard_token_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Token);

PHP_METHOD(Phalcon_Auth_Guard_Token, __construct);
PHP_METHOD(Phalcon_Auth_Guard_Token, fromOptions);
PHP_METHOD(Phalcon_Auth_Guard_Token, getTokenForRequest);
PHP_METHOD(Phalcon_Auth_Guard_Token, setRequest);
PHP_METHOD(Phalcon_Auth_Guard_Token, user);
PHP_METHOD(Phalcon_Auth_Guard_Token, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_token___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Auth\\Guard\\Config\\TokenGuardConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_token_fromoptions, 0, 3, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_token_gettokenforrequest, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_token_setrequest, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_guard_token_user, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_token_validate, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_token_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_Token, __construct, arginfo_phalcon_auth_guard_token___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guard_Token, fromOptions, arginfo_phalcon_auth_guard_token_fromoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Guard_Token, getTokenForRequest, arginfo_phalcon_auth_guard_token_gettokenforrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Token, setRequest, arginfo_phalcon_auth_guard_token_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Token, user, arginfo_phalcon_auth_guard_token_user, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_Token, validate, arginfo_phalcon_auth_guard_token_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
