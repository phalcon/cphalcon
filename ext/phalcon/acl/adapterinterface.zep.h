
extern zend_class_entry *phalcon_acl_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresource, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceObject)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_deny, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapterinterface_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, setDefaultAction, arginfo_phalcon_acl_adapterinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getDefaultAction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addRole, arginfo_phalcon_acl_adapterinterface_addrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addInherit, arginfo_phalcon_acl_adapterinterface_addinherit)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isRole, arginfo_phalcon_acl_adapterinterface_isrole)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isResource, arginfo_phalcon_acl_adapterinterface_isresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResource, arginfo_phalcon_acl_adapterinterface_addresource)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, addResourceAccess, arginfo_phalcon_acl_adapterinterface_addresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, dropResourceAccess, arginfo_phalcon_acl_adapterinterface_dropresourceaccess)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, allow, arginfo_phalcon_acl_adapterinterface_allow)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, deny, arginfo_phalcon_acl_adapterinterface_deny)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, isAllowed, arginfo_phalcon_acl_adapterinterface_isallowed)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveRole, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveResource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getActiveAccess, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getRoles, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_AdapterInterface, getResources, NULL)
	PHP_FE_END
};
