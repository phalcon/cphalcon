
extern zend_class_entry *phalcon_contracts_auth_guard_guard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_Guard);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_guard_guard_fromoptions, 0, 3, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Contracts\\Auth\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Contracts\\Container\\Service\\Collection, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_getlastuserattempted, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_guest, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_hasuser, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_guard_guard_id, 0, 0, MAY_BE_NULL|MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_guard_guard_setuser, 0, 1, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_user, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guard_validate, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_guard_guard_method_entry) {
	ZEND_FENTRY(fromOptions, NULL, arginfo_phalcon_contracts_auth_guard_guard_fromoptions, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, check, arginfo_phalcon_contracts_auth_guard_guard_check)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, getLastUserAttempted, arginfo_phalcon_contracts_auth_guard_guard_getlastuserattempted)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, guest, arginfo_phalcon_contracts_auth_guard_guard_guest)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, hasUser, arginfo_phalcon_contracts_auth_guard_guard_hasuser)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, id, arginfo_phalcon_contracts_auth_guard_guard_id)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, setUser, arginfo_phalcon_contracts_auth_guard_guard_setuser)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, user, arginfo_phalcon_contracts_auth_guard_guard_user)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_Guard, validate, arginfo_phalcon_contracts_auth_guard_guard_validate)
	PHP_FE_END
};
