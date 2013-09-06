
extern zend_class_entry *phalcon_acl_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles);
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addRole, 0, 0, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addInherit, 0, 0, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isRole, 0, 0, 0)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isResource, 0, 0, 0)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addResource, 0, 0, 0)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addResourceAccess, 0, 0, 0)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropResourceAccess, 0, 0, 0)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory__allowOrDeny, 0, 0, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 0, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 0, 0)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isAllowed, 0, 0, 0)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addRole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addInherit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isRole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isResource, arginfo_phalcon_acl_adapter_memory_isResource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResource, arginfo_phalcon_acl_adapter_memory_addResource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResourceAccess, arginfo_phalcon_acl_adapter_memory_addResourceAccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropResourceAccess, arginfo_phalcon_acl_adapter_memory_dropResourceAccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, _allowOrDeny, arginfo_phalcon_acl_adapter_memory__allowOrDeny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isAllowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getRoles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
