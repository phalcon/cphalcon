
extern zend_class_entry *phalcon_contracts_auth_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Manager);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_access, 0, 1, self, 0)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_addaccesslist, 0, 1, self, 0)
	ZEND_ARG_ARRAY_INFO(0, accessList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_addguard, 0, 2, self, 0)
	ZEND_ARG_TYPE_INFO(0, nameGuard, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isDefault, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_attempt, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_except, 0, 0, self, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, actions, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_getaccess, 0, 0, Phalcon\\Contracts\\Auth\\Access\\Access, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_getaccesslist, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_getdefaultguard, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\Guard, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_getguards, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_guard, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_manager_id, 0, 0, MAY_BE_NULL|MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_logout, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_only, 0, 0, self, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, actions, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_setaccess, 0, 1, self, 0)
	ZEND_ARG_OBJ_INFO(0, access, Phalcon\\Contracts\\Auth\\Access\\Access, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_setdefaultguard, 0, 1, self, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_manager_user, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_manager_validate, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_manager_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, access, arginfo_phalcon_contracts_auth_manager_access)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, addAccessList, arginfo_phalcon_contracts_auth_manager_addaccesslist)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, addGuard, arginfo_phalcon_contracts_auth_manager_addguard)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, attempt, arginfo_phalcon_contracts_auth_manager_attempt)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, check, arginfo_phalcon_contracts_auth_manager_check)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, except, arginfo_phalcon_contracts_auth_manager_except)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, getAccess, arginfo_phalcon_contracts_auth_manager_getaccess)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, getAccessList, arginfo_phalcon_contracts_auth_manager_getaccesslist)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, getDefaultGuard, arginfo_phalcon_contracts_auth_manager_getdefaultguard)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, getGuards, arginfo_phalcon_contracts_auth_manager_getguards)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, guard, arginfo_phalcon_contracts_auth_manager_guard)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, id, arginfo_phalcon_contracts_auth_manager_id)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, logout, arginfo_phalcon_contracts_auth_manager_logout)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, only, arginfo_phalcon_contracts_auth_manager_only)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, setAccess, arginfo_phalcon_contracts_auth_manager_setaccess)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, setDefaultGuard, arginfo_phalcon_contracts_auth_manager_setdefaultguard)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, user, arginfo_phalcon_contracts_auth_manager_user)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Manager, validate, arginfo_phalcon_contracts_auth_manager_validate)
	PHP_FE_END
};
