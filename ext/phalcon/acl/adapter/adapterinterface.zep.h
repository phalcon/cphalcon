
extern zend_class_entry *phalcon_acl_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addinherit, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addinherit, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, roleName)
#endif
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addrole, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addrole, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addcomponent, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addcomponent, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, componentObject)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addcomponentaccess, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_addcomponentaccess, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_allow, 0, 3, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_allow, 0, 3, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_allow, 0, 0, 3)
#define arginfo_phalcon_acl_adapter_adapterinterface_allow NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, roleName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_deny, 0, 3, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_deny, 0, 3, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_deny, 0, 0, 3)
#define arginfo_phalcon_acl_adapter_adapterinterface_deny NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, roleName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, func)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_dropcomponentaccess, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_dropcomponentaccess, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_dropcomponentaccess, 0, 0, 2)
#define arginfo_phalcon_acl_adapter_adapterinterface_dropcomponentaccess NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactiveaccess, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactiveaccess, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactiverole, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactiverole, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactivecomponent, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getactivecomponent, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getnoargumentsdefaultaction, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getnoargumentsdefaultaction, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getroles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getroles, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getcomponents, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_getcomponents, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_isallowed, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_isallowed, 0, 3, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, componentName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, access, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, access)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_iscomponent, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_iscomponent, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, componentName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, componentName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_isrole, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_isrole, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, roleName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setdefaultaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setdefaultaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setdefaultaction, 0, 0, 1)
#define arginfo_phalcon_acl_adapter_adapterinterface_setdefaultaction NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setnoargumentsdefaultaction, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setnoargumentsdefaultaction, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_adapterinterface_setnoargumentsdefaultaction, 0, 0, 1)
#define arginfo_phalcon_acl_adapter_adapterinterface_setnoargumentsdefaultaction NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultAccess, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, defaultAccess)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, addInherit, arginfo_phalcon_acl_adapter_adapterinterface_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, addRole, arginfo_phalcon_acl_adapter_adapterinterface_addrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, addComponent, arginfo_phalcon_acl_adapter_adapterinterface_addcomponent)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, addComponentAccess, arginfo_phalcon_acl_adapter_adapterinterface_addcomponentaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, allow, arginfo_phalcon_acl_adapter_adapterinterface_allow)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, deny, arginfo_phalcon_acl_adapter_adapterinterface_deny)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, dropComponentAccess, arginfo_phalcon_acl_adapter_adapterinterface_dropcomponentaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getActiveAccess, arginfo_phalcon_acl_adapter_adapterinterface_getactiveaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getActiveRole, arginfo_phalcon_acl_adapter_adapterinterface_getactiverole)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getActiveComponent, arginfo_phalcon_acl_adapter_adapterinterface_getactivecomponent)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getDefaultAction, arginfo_phalcon_acl_adapter_adapterinterface_getdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_adapterinterface_getnoargumentsdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getRoles, arginfo_phalcon_acl_adapter_adapterinterface_getroles)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, getComponents, arginfo_phalcon_acl_adapter_adapterinterface_getcomponents)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, isAllowed, arginfo_phalcon_acl_adapter_adapterinterface_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, isComponent, arginfo_phalcon_acl_adapter_adapterinterface_iscomponent)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, isRole, arginfo_phalcon_acl_adapter_adapterinterface_isrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, setDefaultAction, arginfo_phalcon_acl_adapter_adapterinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_Adapter_AdapterInterface, setNoArgumentsDefaultAction, arginfo_phalcon_acl_adapter_adapterinterface_setnoargumentsdefaultaction)
	PHP_FE_END
};
