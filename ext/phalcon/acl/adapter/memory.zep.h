
extern zend_class_entry *phalcon_acl_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponent);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getComponents);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isComponent);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivefunction, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivefunctioncustomargumentscount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getactivekey, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addcomponent, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, componentValue)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addcomponentaccess, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_INFO(0, roleToInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_addrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropcomponentaccess, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getroles, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_getcomponents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, componentName)
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_isrole, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_iscomponent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_memory_allowordeny, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_canaccess, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveFunction, arginfo_phalcon_acl_adapter_memory_getactivefunction, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveFunction, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount, arginfo_phalcon_acl_adapter_memory_getactivefunctioncustomargumentscount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getActiveKey, arginfo_phalcon_acl_adapter_memory_getactivekey, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, arginfo_phalcon_acl_adapter_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_ME(Phalcon_Acl_Adapter_Memory, addComponent, arginfo_phalcon_acl_adapter_memory_addcomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addComponentAccess, arginfo_phalcon_acl_adapter_memory_addcomponentaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropComponentAccess, arginfo_phalcon_acl_adapter_memory_dropcomponentaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_getnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getRoles, arginfo_phalcon_acl_adapter_memory_getroles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getComponents, arginfo_phalcon_acl_adapter_memory_getcomponents, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isComponent, arginfo_phalcon_acl_adapter_memory_iscomponent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_memory_setnoargumentsdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allowOrDeny, arginfo_phalcon_acl_adapter_memory_allowordeny, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Acl_Adapter_Memory, canAccess, arginfo_phalcon_acl_adapter_memory_canaccess, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
