
extern zend_class_entry *phalcon_contracts_auth_guard_guardstateful_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_GuardStateful);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guardstateful_attempt, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guardstateful_login, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_guard_guardstateful_loginbyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, MAY_BE_FALSE)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guardstateful_logout, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_guardstateful_viaremember, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_guard_guardstateful_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_GuardStateful, attempt, arginfo_phalcon_contracts_auth_guard_guardstateful_attempt)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_GuardStateful, login, arginfo_phalcon_contracts_auth_guard_guardstateful_login)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_GuardStateful, loginById, arginfo_phalcon_contracts_auth_guard_guardstateful_loginbyid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_GuardStateful, logout, arginfo_phalcon_contracts_auth_guard_guardstateful_logout)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_GuardStateful, viaRemember, arginfo_phalcon_contracts_auth_guard_guardstateful_viaremember)
	PHP_FE_END
};
