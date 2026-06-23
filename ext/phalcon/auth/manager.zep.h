
extern zend_class_entry *phalcon_auth_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager);

PHP_METHOD(Phalcon_Auth_Manager, __construct);
PHP_METHOD(Phalcon_Auth_Manager, access);
PHP_METHOD(Phalcon_Auth_Manager, addAccessList);
PHP_METHOD(Phalcon_Auth_Manager, addGuard);
PHP_METHOD(Phalcon_Auth_Manager, attempt);
PHP_METHOD(Phalcon_Auth_Manager, check);
PHP_METHOD(Phalcon_Auth_Manager, except);
PHP_METHOD(Phalcon_Auth_Manager, getAccess);
PHP_METHOD(Phalcon_Auth_Manager, getAccessList);
PHP_METHOD(Phalcon_Auth_Manager, getDefaultGuard);
PHP_METHOD(Phalcon_Auth_Manager, getGuards);
PHP_METHOD(Phalcon_Auth_Manager, guard);
PHP_METHOD(Phalcon_Auth_Manager, id);
PHP_METHOD(Phalcon_Auth_Manager, logout);
PHP_METHOD(Phalcon_Auth_Manager, only);
PHP_METHOD(Phalcon_Auth_Manager, setAccess);
PHP_METHOD(Phalcon_Auth_Manager, setDefaultGuard);
PHP_METHOD(Phalcon_Auth_Manager, user);
PHP_METHOD(Phalcon_Auth_Manager, validate);
PHP_METHOD(Phalcon_Auth_Manager, requireActiveAccess);
PHP_METHOD(Phalcon_Auth_Manager, requireStatefulGuard);
zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, accessFactory, Phalcon\\Auth\\Access\\AccessLocator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_access, 0, 1, self, 0)
	ZEND_ARG_TYPE_INFO(0, accessName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addaccesslist, 0, 1, self, 0)
	ZEND_ARG_ARRAY_INFO(0, accessList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_addguard, 0, 2, self, 0)
	ZEND_ARG_TYPE_INFO(0, nameGuard, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, isDefault, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_attempt, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, remember, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_except, 0, 0, self, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, actions, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_getaccess, 0, 0, Phalcon\\Contracts\\Auth\\Access\\Access, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_getaccesslist, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_getdefaultguard, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\Guard, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_getguards, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_guard, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_manager_id, 0, 0, MAY_BE_NULL|MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_logout, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_only, 0, 0, self, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, actions, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_setaccess, 0, 1, self, 0)
	ZEND_ARG_OBJ_INFO(0, access, Phalcon\\Contracts\\Auth\\Access\\Access, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_setdefaultguard, 0, 1, self, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_user, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_manager_validate, 0, 0, _IS_BOOL, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, credentials, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_requireactiveaccess, 0, 0, Phalcon\\Contracts\\Auth\\Access\\Access, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_manager_requirestatefulguard, 0, 0, Phalcon\\Contracts\\Auth\\Guard\\GuardStateful, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_manager_zephir_init_properties_phalcon_auth_manager, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_manager_method_entry) {
	PHP_ME(Phalcon_Auth_Manager, __construct, arginfo_phalcon_auth_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Manager, access, arginfo_phalcon_auth_manager_access, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addAccessList, arginfo_phalcon_auth_manager_addaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, addGuard, arginfo_phalcon_auth_manager_addguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, attempt, arginfo_phalcon_auth_manager_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, check, arginfo_phalcon_auth_manager_check, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, except, arginfo_phalcon_auth_manager_except, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getAccess, arginfo_phalcon_auth_manager_getaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getAccessList, arginfo_phalcon_auth_manager_getaccesslist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getDefaultGuard, arginfo_phalcon_auth_manager_getdefaultguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, getGuards, arginfo_phalcon_auth_manager_getguards, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, guard, arginfo_phalcon_auth_manager_guard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, id, arginfo_phalcon_auth_manager_id, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, logout, arginfo_phalcon_auth_manager_logout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, only, arginfo_phalcon_auth_manager_only, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setAccess, arginfo_phalcon_auth_manager_setaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, setDefaultGuard, arginfo_phalcon_auth_manager_setdefaultguard, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, user, arginfo_phalcon_auth_manager_user, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, validate, arginfo_phalcon_auth_manager_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Manager, requireActiveAccess, arginfo_phalcon_auth_manager_requireactiveaccess, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Auth_Manager, requireStatefulGuard, arginfo_phalcon_auth_manager_requirestatefulguard, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
