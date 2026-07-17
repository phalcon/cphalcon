
extern zend_class_entry *phalcon_contracts_acl_adapter_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Acl_Adapter_Adapter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_addinherit, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_INFO(0, roleToInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_addrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_addcomponent, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, componentValue)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_addcomponentaccess, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_allow, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_deny, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_dropcomponentaccess, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getactiveaccess, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getactiverole, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getactivecomponent, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getcomponents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getdefaultaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getinheritedroles, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, roleName, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_getroles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_isallowed, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, componentName)
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, parameters, IS_ARRAY, 1, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_iscomponent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_isrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_setdefaultaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_acl_adapter_adapter_setnoargumentsdefaultaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_acl_adapter_adapter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, addInherit, arginfo_phalcon_contracts_acl_adapter_adapter_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, addRole, arginfo_phalcon_contracts_acl_adapter_adapter_addrole)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, addComponent, arginfo_phalcon_contracts_acl_adapter_adapter_addcomponent)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, addComponentAccess, arginfo_phalcon_contracts_acl_adapter_adapter_addcomponentaccess)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, allow, arginfo_phalcon_contracts_acl_adapter_adapter_allow)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, deny, arginfo_phalcon_contracts_acl_adapter_adapter_deny)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, dropComponentAccess, arginfo_phalcon_contracts_acl_adapter_adapter_dropcomponentaccess)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveAccess, arginfo_phalcon_contracts_acl_adapter_adapter_getactiveaccess)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveRole, arginfo_phalcon_contracts_acl_adapter_adapter_getactiverole)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getActiveComponent, arginfo_phalcon_contracts_acl_adapter_adapter_getactivecomponent)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getComponents, arginfo_phalcon_contracts_acl_adapter_adapter_getcomponents)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getDefaultAction, arginfo_phalcon_contracts_acl_adapter_adapter_getdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getInheritedRoles, arginfo_phalcon_contracts_acl_adapter_adapter_getinheritedroles)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getNoArgumentsDefaultAction, arginfo_phalcon_contracts_acl_adapter_adapter_getnoargumentsdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, getRoles, arginfo_phalcon_contracts_acl_adapter_adapter_getroles)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, isAllowed, arginfo_phalcon_contracts_acl_adapter_adapter_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, isComponent, arginfo_phalcon_contracts_acl_adapter_adapter_iscomponent)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, isRole, arginfo_phalcon_contracts_acl_adapter_adapter_isrole)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, setDefaultAction, arginfo_phalcon_contracts_acl_adapter_adapter_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Acl_Adapter_Adapter, setNoArgumentsDefaultAction, arginfo_phalcon_contracts_acl_adapter_adapter_setnoargumentsdefaultaction)
	PHP_FE_END
};
