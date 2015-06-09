
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H


zend_class_entry *phalcon_acl_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl);


zend_class_entry *phalcon_acl_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter);

static PHP_METHOD(Phalcon_Acl_Adapter, getActiveRole);
static PHP_METHOD(Phalcon_Acl_Adapter, getActiveResource);
static PHP_METHOD(Phalcon_Acl_Adapter, getActiveAccess);
static PHP_METHOD(Phalcon_Acl_Adapter, setEventsManager);
static PHP_METHOD(Phalcon_Acl_Adapter, getEventsManager);
static PHP_METHOD(Phalcon_Acl_Adapter, setDefaultAction);
static PHP_METHOD(Phalcon_Acl_Adapter, getDefaultAction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAccess)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter, getActiveRole, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveResource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getActiveAccess, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setEventsManager, arginfo_phalcon_acl_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, setDefaultAction, arginfo_phalcon_acl_adapter_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_acl_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

static PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles);
static PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addrole, 0, 0, 1)
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, accessInherits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addinherit, 0, 0, 2)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, roleToInherit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isrole, 0, 0, 1)
	ZEND_ARG_INFO(0, roleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resourceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresource, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceValue)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_dropresourceaccess, 0, 0, 2)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, accessList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory__allowordeny, 0, 0, 4)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_allow, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_deny, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_isallowed, 0, 0, 3)
	ZEND_ARG_INFO(0, roleName)
	ZEND_ARG_INFO(0, resourceName)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isrole, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isResource, arginfo_phalcon_acl_adapter_memory_isresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResource, arginfo_phalcon_acl_adapter_memory_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResourceAccess, arginfo_phalcon_acl_adapter_memory_addresourceaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropResourceAccess, arginfo_phalcon_acl_adapter_memory_dropresourceaccess, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, _allowOrDeny, arginfo_phalcon_acl_adapter_memory__allowordeny, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getRoles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Memory, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_acl_adapterinterface_ce;

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

zend_class_entry *phalcon_acl_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Exception);


zend_class_entry *phalcon_acl_resource_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Resource);

static PHP_METHOD(Phalcon_Acl_Resource, getName);
static PHP_METHOD(Phalcon_Acl_Resource, __toString);
static PHP_METHOD(Phalcon_Acl_Resource, getDescription);
static PHP_METHOD(Phalcon_Acl_Resource, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resource___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_resource_method_entry) {
	PHP_ME(Phalcon_Acl_Resource, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Resource, __construct, arginfo_phalcon_acl_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_acl_resourceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_ResourceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_resourceinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_resourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __construct, arginfo_phalcon_acl_resourceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_ResourceInterface, __toString, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_acl_role_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Role);

static PHP_METHOD(Phalcon_Acl_Role, getName);
static PHP_METHOD(Phalcon_Acl_Role, __toString);
static PHP_METHOD(Phalcon_Acl_Role, getDescription);
static PHP_METHOD(Phalcon_Acl_Role, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_role___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_role_method_entry) {
	PHP_ME(Phalcon_Acl_Role, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, getDescription, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Role, __construct, arginfo_phalcon_acl_role___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_acl_roleinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_RoleInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_roleinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_roleinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __construct, arginfo_phalcon_acl_roleinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, getDescription, NULL)
	PHP_ABSTRACT_ME(Phalcon_Acl_RoleInterface, __toString, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter);

static PHP_METHOD(Phalcon_Annotations_Adapter, setReader);
static PHP_METHOD(Phalcon_Annotations_Adapter, getReader);
static PHP_METHOD(Phalcon_Annotations_Adapter, get);
static PHP_METHOD(Phalcon_Annotations_Adapter, getMethods);
static PHP_METHOD(Phalcon_Annotations_Adapter, getMethod);
static PHP_METHOD(Phalcon_Annotations_Adapter, getProperties);
static PHP_METHOD(Phalcon_Annotations_Adapter, getProperty);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter, setReader, arginfo_phalcon_annotations_adapter_setreader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getReader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, get, arginfo_phalcon_annotations_adapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getMethods, arginfo_phalcon_annotations_adapter_getmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getMethod, arginfo_phalcon_annotations_adapter_getmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getProperties, arginfo_phalcon_annotations_adapter_getproperties, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter, getProperty, arginfo_phalcon_annotations_adapter_getproperty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapter_apc_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Apc);

static PHP_METHOD(Phalcon_Annotations_Adapter_Apc, __construct);
static PHP_METHOD(Phalcon_Annotations_Adapter_Apc, read);
static PHP_METHOD(Phalcon_Annotations_Adapter_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_apc_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Apc, __construct, arginfo_phalcon_annotations_adapter_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Adapter_Apc, read, arginfo_phalcon_annotations_adapter_apc_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Apc, write, arginfo_phalcon_annotations_adapter_apc_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapter_files_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Files);

static PHP_METHOD(Phalcon_Annotations_Adapter_Files, __construct);
static PHP_METHOD(Phalcon_Annotations_Adapter_Files, read);
static PHP_METHOD(Phalcon_Annotations_Adapter_Files, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_files___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_files_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_files_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_files_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Files, __construct, arginfo_phalcon_annotations_adapter_files___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Adapter_Files, read, arginfo_phalcon_annotations_adapter_files_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Files, write, arginfo_phalcon_annotations_adapter_files_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Memory);

static PHP_METHOD(Phalcon_Annotations_Adapter_Memory, read);
static PHP_METHOD(Phalcon_Annotations_Adapter_Memory, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_memory_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_memory_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Memory, read, arginfo_phalcon_annotations_adapter_memory_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Memory, write, arginfo_phalcon_annotations_adapter_memory_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapter_xcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_Xcache);

static PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, read);
static PHP_METHOD(Phalcon_Annotations_Adapter_Xcache, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapter_xcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Annotations\\Reflection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapter_xcache_method_entry) {
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, read, arginfo_phalcon_annotations_adapter_xcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Adapter_Xcache, write, arginfo_phalcon_annotations_adapter_xcache_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_setreader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, reader, Phalcon\\Annotations\\ReaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getmethod, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperties, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_adapterinterface_getproperty, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, setReader, arginfo_phalcon_annotations_adapterinterface_setreader)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getReader, NULL)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, get, arginfo_phalcon_annotations_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethods, arginfo_phalcon_annotations_adapterinterface_getmethods)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getMethod, arginfo_phalcon_annotations_adapterinterface_getmethod)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperties, arginfo_phalcon_annotations_adapterinterface_getproperties)
	PHP_ABSTRACT_ME(Phalcon_Annotations_AdapterInterface, getProperty, arginfo_phalcon_annotations_adapterinterface_getproperty)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_annotation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Annotation);

static PHP_METHOD(Phalcon_Annotations_Annotation, __construct);
static PHP_METHOD(Phalcon_Annotations_Annotation, getName);
static PHP_METHOD(Phalcon_Annotations_Annotation, getExpression);
static PHP_METHOD(Phalcon_Annotations_Annotation, getExprArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, getArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, numberArguments);
static PHP_METHOD(Phalcon_Annotations_Annotation, getArgument);
static PHP_METHOD(Phalcon_Annotations_Annotation, hasArgument);
static PHP_METHOD(Phalcon_Annotations_Annotation, getNamedArgument);
static PHP_METHOD(Phalcon_Annotations_Annotation, getNamedParameter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, reflectionData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getargument, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_hasargument, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getnamedargument, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_annotation_getnamedparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_annotation_method_entry) {
	PHP_ME(Phalcon_Annotations_Annotation, __construct, arginfo_phalcon_annotations_annotation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Annotation, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExpression, arginfo_phalcon_annotations_annotation_getexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getExprArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, numberArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getArgument, arginfo_phalcon_annotations_annotation_getargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, hasArgument, arginfo_phalcon_annotations_annotation_hasargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getNamedArgument, arginfo_phalcon_annotations_annotation_getnamedargument, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Annotation, getNamedParameter, arginfo_phalcon_annotations_annotation_getnamedparameter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection);

static PHP_METHOD(Phalcon_Annotations_Collection, __construct);
static PHP_METHOD(Phalcon_Annotations_Collection, count);
static PHP_METHOD(Phalcon_Annotations_Collection, rewind);
static PHP_METHOD(Phalcon_Annotations_Collection, current);
static PHP_METHOD(Phalcon_Annotations_Collection, key);
static PHP_METHOD(Phalcon_Annotations_Collection, next);
static PHP_METHOD(Phalcon_Annotations_Collection, valid);
static PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations);
static PHP_METHOD(Phalcon_Annotations_Collection, get);
static PHP_METHOD(Phalcon_Annotations_Collection, getAll);
static PHP_METHOD(Phalcon_Annotations_Collection, has);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, reflectionData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection_getall, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_collection_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_collection_method_entry) {
	PHP_ME(Phalcon_Annotations_Collection, __construct, arginfo_phalcon_annotations_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, get, arginfo_phalcon_annotations_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, getAll, arginfo_phalcon_annotations_collection_getall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Collection, has, arginfo_phalcon_annotations_collection_has, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Exception);


zend_class_entry *phalcon_annotations_reader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reader);

static PHP_METHOD(Phalcon_Annotations_Reader, parse);
static PHP_METHOD(Phalcon_Annotations_Reader, parseDocBlock);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reader_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reader_parsedocblock, 0, 0, 1)
	ZEND_ARG_INFO(0, docBlock)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_reader_method_entry) {
	PHP_ME(Phalcon_Annotations_Reader, parse, arginfo_phalcon_annotations_reader_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reader, parseDocBlock, arginfo_phalcon_annotations_reader_parsedocblock, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_readerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_ReaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_readerinterface_parsedocblock, 0, 0, 1)
	ZEND_ARG_INFO(0, docBlock)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_readerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Annotations_ReaderInterface, parse, arginfo_phalcon_annotations_readerinterface_parse)
	ZEND_FENTRY(parseDocBlock, NULL, arginfo_phalcon_annotations_readerinterface_parsedocblock, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_annotations_reflection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection);

static PHP_METHOD(Phalcon_Annotations_Reflection, __construct);
static PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations);
static PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations);
static PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations);
static PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData);
static PHP_METHOD(Phalcon_Annotations_Reflection, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, reflectionData)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_reflection___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_reflection_method_entry) {
	PHP_ME(Phalcon_Annotations_Reflection, __construct, arginfo_phalcon_annotations_reflection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Annotations_Reflection, getClassAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getMethodsAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getPropertiesAnnotations, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, getReflectionData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Annotations_Reflection, __set_state, arginfo_phalcon_annotations_reflection___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Collection);

static PHP_METHOD(Phalcon_Assets_Collection, getPrefix);
static PHP_METHOD(Phalcon_Assets_Collection, getLocal);
static PHP_METHOD(Phalcon_Assets_Collection, getResources);
static PHP_METHOD(Phalcon_Assets_Collection, getCodes);
static PHP_METHOD(Phalcon_Assets_Collection, getPosition);
static PHP_METHOD(Phalcon_Assets_Collection, getFilters);
static PHP_METHOD(Phalcon_Assets_Collection, getAttributes);
static PHP_METHOD(Phalcon_Assets_Collection, getJoin);
static PHP_METHOD(Phalcon_Assets_Collection, getTargetUri);
static PHP_METHOD(Phalcon_Assets_Collection, getTargetPath);
static PHP_METHOD(Phalcon_Assets_Collection, getTargetLocal);
static PHP_METHOD(Phalcon_Assets_Collection, getSourcePath);
static PHP_METHOD(Phalcon_Assets_Collection, add);
static PHP_METHOD(Phalcon_Assets_Collection, addInline);
static PHP_METHOD(Phalcon_Assets_Collection, addCss);
static PHP_METHOD(Phalcon_Assets_Collection, addInlineCss);
static PHP_METHOD(Phalcon_Assets_Collection, addJs);
static PHP_METHOD(Phalcon_Assets_Collection, addInlineJs);
static PHP_METHOD(Phalcon_Assets_Collection, count);
static PHP_METHOD(Phalcon_Assets_Collection, rewind);
static PHP_METHOD(Phalcon_Assets_Collection, current);
static PHP_METHOD(Phalcon_Assets_Collection, key);
static PHP_METHOD(Phalcon_Assets_Collection, next);
static PHP_METHOD(Phalcon_Assets_Collection, valid);
static PHP_METHOD(Phalcon_Assets_Collection, setTargetPath);
static PHP_METHOD(Phalcon_Assets_Collection, setSourcePath);
static PHP_METHOD(Phalcon_Assets_Collection, setTargetUri);
static PHP_METHOD(Phalcon_Assets_Collection, setPrefix);
static PHP_METHOD(Phalcon_Assets_Collection, setLocal);
static PHP_METHOD(Phalcon_Assets_Collection, setAttributes);
static PHP_METHOD(Phalcon_Assets_Collection, setFilters);
static PHP_METHOD(Phalcon_Assets_Collection, setTargetLocal);
static PHP_METHOD(Phalcon_Assets_Collection, join);
static PHP_METHOD(Phalcon_Assets_Collection, getRealTargetPath);
static PHP_METHOD(Phalcon_Assets_Collection, addFilter);
static PHP_METHOD(Phalcon_Assets_Collection, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinline, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_setfilters, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, filters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_settargetlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, targetLocal)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_join, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_getrealtargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_collection_addfilter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Phalcon\\Assets\\FilterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_collection_method_entry) {
	PHP_ME(Phalcon_Assets_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getCodes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getPosition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getJoin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getTargetLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, add, arginfo_phalcon_assets_collection_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInline, arginfo_phalcon_assets_collection_addinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addCss, arginfo_phalcon_assets_collection_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInlineCss, arginfo_phalcon_assets_collection_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addJs, arginfo_phalcon_assets_collection_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addInlineJs, arginfo_phalcon_assets_collection_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetPath, arginfo_phalcon_assets_collection_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setSourcePath, arginfo_phalcon_assets_collection_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetUri, arginfo_phalcon_assets_collection_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setPrefix, arginfo_phalcon_assets_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setLocal, arginfo_phalcon_assets_collection_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setAttributes, arginfo_phalcon_assets_collection_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setFilters, arginfo_phalcon_assets_collection_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, setTargetLocal, arginfo_phalcon_assets_collection_settargetlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, join, arginfo_phalcon_assets_collection_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, getRealTargetPath, arginfo_phalcon_assets_collection_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, addFilter, arginfo_phalcon_assets_collection_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Collection, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Exception);


zend_class_entry *phalcon_assets_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Assets_FilterInterface, filter, arginfo_phalcon_assets_filterinterface_filter)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_filters_cssmin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Cssmin);

static PHP_METHOD(Phalcon_Assets_Filters_Cssmin, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filters_cssmin_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filters_cssmin_method_entry) {
	PHP_ME(Phalcon_Assets_Filters_Cssmin, filter, arginfo_phalcon_assets_filters_cssmin_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_filters_jsmin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_Jsmin);

static PHP_METHOD(Phalcon_Assets_Filters_Jsmin, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filters_jsmin_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filters_jsmin_method_entry) {
	PHP_ME(Phalcon_Assets_Filters_Jsmin, filter, arginfo_phalcon_assets_filters_jsmin_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_filters_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Filters_None);

static PHP_METHOD(Phalcon_Assets_Filters_None, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_filters_none_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_filters_none_method_entry) {
	PHP_ME(Phalcon_Assets_Filters_None, filter, arginfo_phalcon_assets_filters_none_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_inline_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline);

static PHP_METHOD(Phalcon_Assets_Inline, getType);
static PHP_METHOD(Phalcon_Assets_Inline, getContent);
static PHP_METHOD(Phalcon_Assets_Inline, getFilter);
static PHP_METHOD(Phalcon_Assets_Inline, getAttributes);
static PHP_METHOD(Phalcon_Assets_Inline, __construct);
static PHP_METHOD(Phalcon_Assets_Inline, setType);
static PHP_METHOD(Phalcon_Assets_Inline, setFilter);
static PHP_METHOD(Phalcon_Assets_Inline, setAttributes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_inline_method_entry) {
	PHP_ME(Phalcon_Assets_Inline, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, __construct, arginfo_phalcon_assets_inline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Inline, setType, arginfo_phalcon_assets_inline_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, setFilter, arginfo_phalcon_assets_inline_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Inline, setAttributes, arginfo_phalcon_assets_inline_setattributes, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_inline_css_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Css);

static PHP_METHOD(Phalcon_Assets_Inline_Css, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_css___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_inline_css_method_entry) {
	PHP_ME(Phalcon_Assets_Inline_Css, __construct, arginfo_phalcon_assets_inline_css___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_inline_js_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Inline_Js);

static PHP_METHOD(Phalcon_Assets_Inline_Js, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_inline_js___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_inline_js_method_entry) {
	PHP_ME(Phalcon_Assets_Inline_Js, __construct, arginfo_phalcon_assets_inline_js___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Manager);

static PHP_METHOD(Phalcon_Assets_Manager, __construct);
static PHP_METHOD(Phalcon_Assets_Manager, setOptions);
static PHP_METHOD(Phalcon_Assets_Manager, getOptions);
static PHP_METHOD(Phalcon_Assets_Manager, useImplicitOutput);
static PHP_METHOD(Phalcon_Assets_Manager, addCss);
static PHP_METHOD(Phalcon_Assets_Manager, addInlineCss);
static PHP_METHOD(Phalcon_Assets_Manager, addJs);
static PHP_METHOD(Phalcon_Assets_Manager, addInlineJs);
static PHP_METHOD(Phalcon_Assets_Manager, addResourceByType);
static PHP_METHOD(Phalcon_Assets_Manager, addInlineCodeByType);
static PHP_METHOD(Phalcon_Assets_Manager, addResource);
static PHP_METHOD(Phalcon_Assets_Manager, addInlineCode);
static PHP_METHOD(Phalcon_Assets_Manager, set);
static PHP_METHOD(Phalcon_Assets_Manager, get);
static PHP_METHOD(Phalcon_Assets_Manager, getCss);
static PHP_METHOD(Phalcon_Assets_Manager, getJs);
static PHP_METHOD(Phalcon_Assets_Manager, collection);
static PHP_METHOD(Phalcon_Assets_Manager, output);
static PHP_METHOD(Phalcon_Assets_Manager, outputInline);
static PHP_METHOD(Phalcon_Assets_Manager, outputCss);
static PHP_METHOD(Phalcon_Assets_Manager, outputInlineCss);
static PHP_METHOD(Phalcon_Assets_Manager, outputJs);
static PHP_METHOD(Phalcon_Assets_Manager, outputInlineJs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_useimplicitoutput, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitOutput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addcss, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecss, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addjs, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinejs, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresourcebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecodebytype, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addresource, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, resource, Phalcon\\Assets\\Resource, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_addinlinecode, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, code, Phalcon\\Assets\\Inline, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_collection, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_output, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinline, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Assets\\Collection, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputcss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinlinecss, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputjs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_manager_outputinlinejs, 0, 0, 0)
	ZEND_ARG_INFO(0, collectionName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_manager_method_entry) {
	PHP_ME(Phalcon_Assets_Manager, __construct, arginfo_phalcon_assets_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Manager, setOptions, arginfo_phalcon_assets_manager_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, useImplicitOutput, arginfo_phalcon_assets_manager_useimplicitoutput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addCss, arginfo_phalcon_assets_manager_addcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCss, arginfo_phalcon_assets_manager_addinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addJs, arginfo_phalcon_assets_manager_addjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineJs, arginfo_phalcon_assets_manager_addinlinejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResourceByType, arginfo_phalcon_assets_manager_addresourcebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCodeByType, arginfo_phalcon_assets_manager_addinlinecodebytype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addResource, arginfo_phalcon_assets_manager_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, addInlineCode, arginfo_phalcon_assets_manager_addinlinecode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, set, arginfo_phalcon_assets_manager_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, get, arginfo_phalcon_assets_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getCss, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, getJs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, collection, arginfo_phalcon_assets_manager_collection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, output, arginfo_phalcon_assets_manager_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInline, arginfo_phalcon_assets_manager_outputinline, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputCss, arginfo_phalcon_assets_manager_outputcss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineCss, arginfo_phalcon_assets_manager_outputinlinecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputJs, arginfo_phalcon_assets_manager_outputjs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Manager, outputInlineJs, arginfo_phalcon_assets_manager_outputinlinejs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_resource_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource);

static PHP_METHOD(Phalcon_Assets_Resource, getType);
static PHP_METHOD(Phalcon_Assets_Resource, getPath);
static PHP_METHOD(Phalcon_Assets_Resource, getLocal);
static PHP_METHOD(Phalcon_Assets_Resource, getFilter);
static PHP_METHOD(Phalcon_Assets_Resource, getAttributes);
static PHP_METHOD(Phalcon_Assets_Resource, getSourcePath);
static PHP_METHOD(Phalcon_Assets_Resource, getTargetPath);
static PHP_METHOD(Phalcon_Assets_Resource, getTargetUri);
static PHP_METHOD(Phalcon_Assets_Resource, __construct);
static PHP_METHOD(Phalcon_Assets_Resource, setType);
static PHP_METHOD(Phalcon_Assets_Resource, setPath);
static PHP_METHOD(Phalcon_Assets_Resource, setLocal);
static PHP_METHOD(Phalcon_Assets_Resource, setFilter);
static PHP_METHOD(Phalcon_Assets_Resource, setAttributes);
static PHP_METHOD(Phalcon_Assets_Resource, setTargetUri);
static PHP_METHOD(Phalcon_Assets_Resource, setSourcePath);
static PHP_METHOD(Phalcon_Assets_Resource, setTargetPath);
static PHP_METHOD(Phalcon_Assets_Resource, getContent);
static PHP_METHOD(Phalcon_Assets_Resource, getRealTargetUri);
static PHP_METHOD(Phalcon_Assets_Resource, getRealSourcePath);
static PHP_METHOD(Phalcon_Assets_Resource, getRealTargetPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setlocal, 0, 0, 1)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargeturi, 0, 0, 1)
	ZEND_ARG_INFO(0, targetUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_setsourcepath, 0, 0, 1)
	ZEND_ARG_INFO(0, sourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_settargetpath, 0, 0, 1)
	ZEND_ARG_INFO(0, targetPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealsourcepath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_getrealtargetpath, 0, 0, 0)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resource_method_entry) {
	PHP_ME(Phalcon_Assets_Resource, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getLocal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getFilter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getSourcePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, __construct, arginfo_phalcon_assets_resource___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Assets_Resource, setType, arginfo_phalcon_assets_resource_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setPath, arginfo_phalcon_assets_resource_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setLocal, arginfo_phalcon_assets_resource_setlocal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setFilter, arginfo_phalcon_assets_resource_setfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setAttributes, arginfo_phalcon_assets_resource_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetUri, arginfo_phalcon_assets_resource_settargeturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setSourcePath, arginfo_phalcon_assets_resource_setsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, setTargetPath, arginfo_phalcon_assets_resource_settargetpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getContent, arginfo_phalcon_assets_resource_getcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealSourcePath, arginfo_phalcon_assets_resource_getrealsourcepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Assets_Resource, getRealTargetPath, arginfo_phalcon_assets_resource_getrealtargetpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_resource_css_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource_Css);

static PHP_METHOD(Phalcon_Assets_Resource_Css, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_css___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resource_css_method_entry) {
	PHP_ME(Phalcon_Assets_Resource_Css, __construct, arginfo_phalcon_assets_resource_css___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_assets_resource_js_ce;

ZEPHIR_INIT_CLASS(Phalcon_Assets_Resource_Js);

static PHP_METHOD(Phalcon_Assets_Resource_Js, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_assets_resource_js___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, local)
	ZEND_ARG_INFO(0, filter)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_assets_resource_js_method_entry) {
	PHP_ME(Phalcon_Assets_Resource_Js, __construct, arginfo_phalcon_assets_resource_js___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend);

static PHP_METHOD(Phalcon_Cache_Backend, getFrontend);
static PHP_METHOD(Phalcon_Cache_Backend, setFrontend);
static PHP_METHOD(Phalcon_Cache_Backend, getOptions);
static PHP_METHOD(Phalcon_Cache_Backend, setOptions);
static PHP_METHOD(Phalcon_Cache_Backend, getLastKey);
static PHP_METHOD(Phalcon_Cache_Backend, setLastKey);
static PHP_METHOD(Phalcon_Cache_Backend, __construct);
static PHP_METHOD(Phalcon_Cache_Backend, start);
static PHP_METHOD(Phalcon_Cache_Backend, stop);
static PHP_METHOD(Phalcon_Cache_Backend, isFresh);
static PHP_METHOD(Phalcon_Cache_Backend, isStarted);
static PHP_METHOD(Phalcon_Cache_Backend, getLifetime);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setfrontend, 0, 0, 1)
	ZEND_ARG_INFO(0, frontend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_method_entry) {
	PHP_ME(Phalcon_Cache_Backend, getFrontend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, setFrontend, arginfo_phalcon_cache_backend_setfrontend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, setOptions, arginfo_phalcon_cache_backend_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getLastKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, setLastKey, arginfo_phalcon_cache_backend_setlastkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, __construct, arginfo_phalcon_cache_backend___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend, start, arginfo_phalcon_cache_backend_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, stop, arginfo_phalcon_cache_backend_stop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isFresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, isStarted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_apc_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apc);

static PHP_METHOD(Phalcon_Cache_Backend_Apc, get);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, save);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Apc, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apc_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_apc_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Apc, get, arginfo_phalcon_cache_backend_apc_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, save, arginfo_phalcon_cache_backend_apc_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, increment, arginfo_phalcon_cache_backend_apc_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, decrement, arginfo_phalcon_cache_backend_apc_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, delete, arginfo_phalcon_cache_backend_apc_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, queryKeys, arginfo_phalcon_cache_backend_apc_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, exists, arginfo_phalcon_cache_backend_apc_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apc, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_File);

static PHP_METHOD(Phalcon_Cache_Backend_File, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_File, get);
static PHP_METHOD(Phalcon_Cache_Backend_File, save);
static PHP_METHOD(Phalcon_Cache_Backend_File, delete);
static PHP_METHOD(Phalcon_Cache_Backend_File, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_File, exists);
static PHP_METHOD(Phalcon_Cache_Backend_File, increment);
static PHP_METHOD(Phalcon_Cache_Backend_File, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_File, flush);
static PHP_METHOD(Phalcon_Cache_Backend_File, getKey);
static PHP_METHOD(Phalcon_Cache_Backend_File, useSafeKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_getkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_file_usesafekey, 0, 0, 1)
	ZEND_ARG_INFO(0, useSafeKey)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_file_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_File, __construct, arginfo_phalcon_cache_backend_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_File, get, arginfo_phalcon_cache_backend_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, save, arginfo_phalcon_cache_backend_file_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, delete, arginfo_phalcon_cache_backend_file_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, queryKeys, arginfo_phalcon_cache_backend_file_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, exists, arginfo_phalcon_cache_backend_file_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, increment, arginfo_phalcon_cache_backend_file_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, decrement, arginfo_phalcon_cache_backend_file_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, getKey, arginfo_phalcon_cache_backend_file_getkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_File, useSafeKey, arginfo_phalcon_cache_backend_file_usesafekey, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Libmemcached);

static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, _connect);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, get);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, save);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Libmemcached, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_libmemcached_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_libmemcached_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, __construct, arginfo_phalcon_cache_backend_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, _connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, get, arginfo_phalcon_cache_backend_libmemcached_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, save, arginfo_phalcon_cache_backend_libmemcached_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, delete, arginfo_phalcon_cache_backend_libmemcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, queryKeys, arginfo_phalcon_cache_backend_libmemcached_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, exists, arginfo_phalcon_cache_backend_libmemcached_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, increment, arginfo_phalcon_cache_backend_libmemcached_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, decrement, arginfo_phalcon_cache_backend_libmemcached_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Libmemcached, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_memcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

static PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, _connect);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, get);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, save);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Memcache, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_memcache_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Memcache, __construct, arginfo_phalcon_cache_backend_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Memcache, _connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, get, arginfo_phalcon_cache_backend_memcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, save, arginfo_phalcon_cache_backend_memcache_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, delete, arginfo_phalcon_cache_backend_memcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, queryKeys, arginfo_phalcon_cache_backend_memcache_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, exists, arginfo_phalcon_cache_backend_memcache_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, increment, arginfo_phalcon_cache_backend_memcache_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, decrement, arginfo_phalcon_cache_backend_memcache_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memcache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memory);

static PHP_METHOD(Phalcon_Cache_Backend_Memory, get);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, save);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, flush);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, serialize);
static PHP_METHOD(Phalcon_Cache_Backend_Memory, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_memory_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Memory, get, arginfo_phalcon_cache_backend_memory_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, save, arginfo_phalcon_cache_backend_memory_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, delete, arginfo_phalcon_cache_backend_memory_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, queryKeys, arginfo_phalcon_cache_backend_memory_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, exists, arginfo_phalcon_cache_backend_memory_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, increment, arginfo_phalcon_cache_backend_memory_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, decrement, arginfo_phalcon_cache_backend_memory_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, unserialize, arginfo_phalcon_cache_backend_memory_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_mongo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Mongo);

static PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, get);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, save);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_decrement, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_mongo_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Mongo, __construct, arginfo_phalcon_cache_backend_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Mongo, _getCollection, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Cache_Backend_Mongo, get, arginfo_phalcon_cache_backend_mongo_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, save, arginfo_phalcon_cache_backend_mongo_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, delete, arginfo_phalcon_cache_backend_mongo_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, queryKeys, arginfo_phalcon_cache_backend_mongo_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, exists, arginfo_phalcon_cache_backend_mongo_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, increment, arginfo_phalcon_cache_backend_mongo_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, decrement, arginfo_phalcon_cache_backend_mongo_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis);

static PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, _connect);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, get);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, save);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Redis, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_redis_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Redis, __construct, arginfo_phalcon_cache_backend_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Redis, _connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, get, arginfo_phalcon_cache_backend_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, save, arginfo_phalcon_cache_backend_redis_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, delete, arginfo_phalcon_cache_backend_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, queryKeys, arginfo_phalcon_cache_backend_redis_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, exists, arginfo_phalcon_cache_backend_redis_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, increment, arginfo_phalcon_cache_backend_redis_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, decrement, arginfo_phalcon_cache_backend_redis_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backend_xcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Xcache);

static PHP_METHOD(Phalcon_Cache_Backend_Xcache, __construct);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, get);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, save);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, delete);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, queryKeys);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, exists);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, increment);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, decrement);
static PHP_METHOD(Phalcon_Cache_Backend_Xcache, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_xcache_decrement, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_xcache_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Xcache, __construct, arginfo_phalcon_cache_backend_xcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Xcache, get, arginfo_phalcon_cache_backend_xcache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, save, arginfo_phalcon_cache_backend_xcache_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, delete, arginfo_phalcon_cache_backend_xcache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, queryKeys, arginfo_phalcon_cache_backend_xcache_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, exists, arginfo_phalcon_cache_backend_xcache_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, increment, arginfo_phalcon_cache_backend_xcache_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, decrement, arginfo_phalcon_cache_backend_xcache_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Xcache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_backendinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_BackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_stop, 0, 0, 0)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_setlastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, lastKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backendinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, start, arginfo_phalcon_cache_backendinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, stop, arginfo_phalcon_cache_backendinterface_stop)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getFrontend, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, setLastKey, arginfo_phalcon_cache_backendinterface_setlastkey)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getLastKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, get, arginfo_phalcon_cache_backendinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, save, arginfo_phalcon_cache_backendinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, delete, arginfo_phalcon_cache_backendinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, exists, arginfo_phalcon_cache_backendinterface_exists)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Exception);


zend_class_entry *phalcon_cache_frontend_base64_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Base64);

static PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, start);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_base64_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Base64, __construct, arginfo_phalcon_cache_frontend_base64___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Base64, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, beforeStore, arginfo_phalcon_cache_frontend_base64_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, afterRetrieve, arginfo_phalcon_cache_frontend_base64_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontend_data_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Data);

static PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, start);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_data_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontend_data_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontend_data_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontend_igbinary_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Igbinary);

static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, __construct);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, start);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_igbinary_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, __construct, arginfo_phalcon_cache_frontend_igbinary___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, beforeStore, arginfo_phalcon_cache_frontend_igbinary_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, afterRetrieve, arginfo_phalcon_cache_frontend_igbinary_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontend_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json);

static PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, start);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_Json, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_json_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Json, __construct, arginfo_phalcon_cache_frontend_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Json, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, beforeStore, arginfo_phalcon_cache_frontend_json_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Json, afterRetrieve, arginfo_phalcon_cache_frontend_json_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontend_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_None);

static PHP_METHOD(Phalcon_Cache_Frontend_None, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_None, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_None, start);
static PHP_METHOD(Phalcon_Cache_Frontend_None, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_None, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_None, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_None, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_none_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_none_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_None, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, beforeStore, arginfo_phalcon_cache_frontend_none_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_None, afterRetrieve, arginfo_phalcon_cache_frontend_none_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontend_output_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Output);

static PHP_METHOD(Phalcon_Cache_Frontend_Output, __construct);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, getLifetime);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, isBuffering);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, start);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, getContent);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, stop);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, beforeStore);
static PHP_METHOD(Phalcon_Cache_Frontend_Output, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_output_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_output_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Output, __construct, arginfo_phalcon_cache_frontend_output___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Output, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, beforeStore, arginfo_phalcon_cache_frontend_output_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Output, afterRetrieve, arginfo_phalcon_cache_frontend_output_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_frontendinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_FrontendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontendinterface_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontendinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getLifetime, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, isBuffering, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, stop, NULL)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, beforeStore, arginfo_phalcon_cache_frontendinterface_beforestore)
	PHP_ABSTRACT_ME(Phalcon_Cache_FrontendInterface, afterRetrieve, arginfo_phalcon_cache_frontendinterface_afterretrieve)
	PHP_FE_END
};

zend_class_entry *phalcon_cache_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Multiple);

static PHP_METHOD(Phalcon_Cache_Multiple, __construct);
static PHP_METHOD(Phalcon_Cache_Multiple, push);
static PHP_METHOD(Phalcon_Cache_Multiple, get);
static PHP_METHOD(Phalcon_Cache_Multiple, start);
static PHP_METHOD(Phalcon_Cache_Multiple, save);
static PHP_METHOD(Phalcon_Cache_Multiple, delete);
static PHP_METHOD(Phalcon_Cache_Multiple, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, backends)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_push, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Phalcon\\Cache\\BackendInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_multiple_method_entry) {
	PHP_ME(Phalcon_Cache_Multiple, __construct, arginfo_phalcon_cache_multiple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Multiple, push, arginfo_phalcon_cache_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, get, arginfo_phalcon_cache_multiple_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, start, arginfo_phalcon_cache_multiple_start, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, save, arginfo_phalcon_cache_multiple_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, delete, arginfo_phalcon_cache_multiple_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Multiple, exists, arginfo_phalcon_cache_multiple_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cli_console_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Console);

static PHP_METHOD(Phalcon_Cli_Console, __construct);
static PHP_METHOD(Phalcon_Cli_Console, setDI);
static PHP_METHOD(Phalcon_Cli_Console, getDI);
static PHP_METHOD(Phalcon_Cli_Console, setEventsManager);
static PHP_METHOD(Phalcon_Cli_Console, getEventsManager);
static PHP_METHOD(Phalcon_Cli_Console, registerModules);
static PHP_METHOD(Phalcon_Cli_Console, addModules);
static PHP_METHOD(Phalcon_Cli_Console, getModules);
static PHP_METHOD(Phalcon_Cli_Console, handle);
static PHP_METHOD(Phalcon_Cli_Console, setArgument);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_addmodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_handle, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_console_setargument, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, shift)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_console_method_entry) {
	PHP_ME(Phalcon_Cli_Console, __construct, arginfo_phalcon_cli_console___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Console, setDI, arginfo_phalcon_cli_console_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setEventsManager, arginfo_phalcon_cli_console_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, registerModules, arginfo_phalcon_cli_console_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, addModules, arginfo_phalcon_cli_console_addmodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, handle, arginfo_phalcon_cli_console_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Console, setArgument, arginfo_phalcon_cli_console_setargument, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cli_console_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Console_Exception);


zend_class_entry *phalcon_cli_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher);

static PHP_METHOD(Phalcon_Cli_Dispatcher, __construct);
static PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskSuffix);
static PHP_METHOD(Phalcon_Cli_Dispatcher, setDefaultTask);
static PHP_METHOD(Phalcon_Cli_Dispatcher, setTaskName);
static PHP_METHOD(Phalcon_Cli_Dispatcher, getTaskName);
static PHP_METHOD(Phalcon_Cli_Dispatcher, _throwDispatchException);
static PHP_METHOD(Phalcon_Cli_Dispatcher, _handleException);
static PHP_METHOD(Phalcon_Cli_Dispatcher, getLastTask);
static PHP_METHOD(Phalcon_Cli_Dispatcher, getActiveTask);
static PHP_METHOD(Phalcon_Cli_Dispatcher, setOptions);
static PHP_METHOD(Phalcon_Cli_Dispatcher, getOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settasksuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, taskSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_settaskname, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher__throwdispatchexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, exceptionCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher__handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_dispatcher_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_dispatcher_method_entry) {
	PHP_ME(Phalcon_Cli_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskSuffix, arginfo_phalcon_cli_dispatcher_settasksuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setDefaultTask, arginfo_phalcon_cli_dispatcher_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setTaskName, arginfo_phalcon_cli_dispatcher_settaskname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, _throwDispatchException, arginfo_phalcon_cli_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cli_Dispatcher, _handleException, arginfo_phalcon_cli_dispatcher__handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cli_Dispatcher, getLastTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getActiveTask, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, setOptions, arginfo_phalcon_cli_dispatcher_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Dispatcher, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cli_dispatcher_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Dispatcher_Exception);


zend_class_entry *phalcon_cli_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router);

static PHP_METHOD(Phalcon_Cli_Router, __construct);
static PHP_METHOD(Phalcon_Cli_Router, setDI);
static PHP_METHOD(Phalcon_Cli_Router, getDI);
static PHP_METHOD(Phalcon_Cli_Router, setDefaultModule);
static PHP_METHOD(Phalcon_Cli_Router, setDefaultTask);
static PHP_METHOD(Phalcon_Cli_Router, setDefaultAction);
static PHP_METHOD(Phalcon_Cli_Router, setDefaults);
static PHP_METHOD(Phalcon_Cli_Router, handle);
static PHP_METHOD(Phalcon_Cli_Router, add);
static PHP_METHOD(Phalcon_Cli_Router, getModuleName);
static PHP_METHOD(Phalcon_Cli_Router, getTaskName);
static PHP_METHOD(Phalcon_Cli_Router, getActionName);
static PHP_METHOD(Phalcon_Cli_Router, getParams);
static PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute);
static PHP_METHOD(Phalcon_Cli_Router, getMatches);
static PHP_METHOD(Phalcon_Cli_Router, wasMatched);
static PHP_METHOD(Phalcon_Cli_Router, getRoutes);
static PHP_METHOD(Phalcon_Cli_Router, getRouteById);
static PHP_METHOD(Phalcon_Cli_Router, getRouteByName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaulttask, 0, 0, 1)
	ZEND_ARG_INFO(0, taskName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_method_entry) {
	PHP_ME(Phalcon_Cli_Router, __construct, arginfo_phalcon_cli_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Router, setDI, arginfo_phalcon_cli_router_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultModule, arginfo_phalcon_cli_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultTask, arginfo_phalcon_cli_router_setdefaulttask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaultAction, arginfo_phalcon_cli_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, setDefaults, arginfo_phalcon_cli_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, handle, arginfo_phalcon_cli_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, add, arginfo_phalcon_cli_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getTaskName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteById, arginfo_phalcon_cli_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router, getRouteByName, arginfo_phalcon_cli_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cli_router_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Exception);


zend_class_entry *phalcon_cli_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Router_Route);

static PHP_METHOD(Phalcon_Cli_Router_Route, __construct);
static PHP_METHOD(Phalcon_Cli_Router_Route, compilePattern);
static PHP_METHOD(Phalcon_Cli_Router_Route, extractNamedParams);
static PHP_METHOD(Phalcon_Cli_Router_Route, reConfigure);
static PHP_METHOD(Phalcon_Cli_Router_Route, getName);
static PHP_METHOD(Phalcon_Cli_Router_Route, setName);
static PHP_METHOD(Phalcon_Cli_Router_Route, beforeMatch);
static PHP_METHOD(Phalcon_Cli_Router_Route, getBeforeMatch);
static PHP_METHOD(Phalcon_Cli_Router_Route, getRouteId);
static PHP_METHOD(Phalcon_Cli_Router_Route, getPattern);
static PHP_METHOD(Phalcon_Cli_Router_Route, getCompiledPattern);
static PHP_METHOD(Phalcon_Cli_Router_Route, getPaths);
static PHP_METHOD(Phalcon_Cli_Router_Route, getReversedPaths);
static PHP_METHOD(Phalcon_Cli_Router_Route, convert);
static PHP_METHOD(Phalcon_Cli_Router_Route, getConverters);
static PHP_METHOD(Phalcon_Cli_Router_Route, reset);
static PHP_METHOD(Phalcon_Cli_Router_Route, delimiter);
static PHP_METHOD(Phalcon_Cli_Router_Route, getDelimiter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_extractnamedparams, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_convert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cli_router_route_delimiter, 0, 0, 0)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cli_router_route_method_entry) {
	PHP_ME(Phalcon_Cli_Router_Route, __construct, arginfo_phalcon_cli_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cli_Router_Route, compilePattern, arginfo_phalcon_cli_router_route_compilepattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, extractNamedParams, arginfo_phalcon_cli_router_route_extractnamedparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, reConfigure, arginfo_phalcon_cli_router_route_reconfigure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, setName, arginfo_phalcon_cli_router_route_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, beforeMatch, arginfo_phalcon_cli_router_route_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getRouteId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getCompiledPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getReversedPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, convert, arginfo_phalcon_cli_router_route_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, getConverters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cli_Router_Route, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Cli_Router_Route, delimiter, arginfo_phalcon_cli_router_route_delimiter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Cli_Router_Route, getDelimiter, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_cli_task_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cli_Task);

static PHP_METHOD(Phalcon_Cli_Task, __construct);

ZEPHIR_INIT_FUNCS(phalcon_cli_task_method_entry) {
	PHP_ME(Phalcon_Cli_Task, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_config_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config);

static PHP_METHOD(Phalcon_Config, __construct);
static PHP_METHOD(Phalcon_Config, offsetExists);
static PHP_METHOD(Phalcon_Config, get);
static PHP_METHOD(Phalcon_Config, offsetGet);
static PHP_METHOD(Phalcon_Config, offsetSet);
static PHP_METHOD(Phalcon_Config, offsetUnset);
static PHP_METHOD(Phalcon_Config, merge);
static PHP_METHOD(Phalcon_Config, toArray);
static PHP_METHOD(Phalcon_Config, count);
static PHP_METHOD(Phalcon_Config, __set_state);
static PHP_METHOD(Phalcon_Config, _merge);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, arrayConfig, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config__merge, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
	ZEND_ARG_INFO(0, instance)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_method_entry) {
	PHP_ME(Phalcon_Config, __construct, arginfo_phalcon_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config, offsetExists, arginfo_phalcon_config_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, get, arginfo_phalcon_config_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetGet, arginfo_phalcon_config_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetSet, arginfo_phalcon_config_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, offsetUnset, arginfo_phalcon_config_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, merge, arginfo_phalcon_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config, __set_state, arginfo_phalcon_config___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Config, _merge, arginfo_phalcon_config__merge, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_FE_END
};

zend_class_entry *phalcon_config_adapter_ini_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Ini);

static PHP_METHOD(Phalcon_Config_Adapter_Ini, __construct);
static PHP_METHOD(Phalcon_Config_Adapter_Ini, _parseIniString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_ini__parseinistring, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_ini_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Ini, __construct, arginfo_phalcon_config_adapter_ini___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_Adapter_Ini, _parseIniString, arginfo_phalcon_config_adapter_ini__parseinistring, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_config_adapter_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Json);

static PHP_METHOD(Phalcon_Config_Adapter_Json, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_json___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_json_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Json, __construct, arginfo_phalcon_config_adapter_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_config_adapter_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Php);

static PHP_METHOD(Phalcon_Config_Adapter_Php, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_php___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_php_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Php, __construct, arginfo_phalcon_config_adapter_php___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_config_adapter_yaml_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Adapter_Yaml);

static PHP_METHOD(Phalcon_Config_Adapter_Yaml, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_adapter_yaml___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_ARRAY_INFO(0, callbacks, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_adapter_yaml_method_entry) {
	PHP_ME(Phalcon_Config_Adapter_Yaml, __construct, arginfo_phalcon_config_adapter_yaml___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_config_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_Exception);


zend_class_entry *phalcon_crypt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt);

static PHP_METHOD(Phalcon_Crypt, setPadding);
static PHP_METHOD(Phalcon_Crypt, setCipher);
static PHP_METHOD(Phalcon_Crypt, getCipher);
static PHP_METHOD(Phalcon_Crypt, setMode);
static PHP_METHOD(Phalcon_Crypt, getMode);
static PHP_METHOD(Phalcon_Crypt, setKey);
static PHP_METHOD(Phalcon_Crypt, getKey);
static PHP_METHOD(Phalcon_Crypt, _cryptPadText);
static PHP_METHOD(Phalcon_Crypt, _cryptUnpadText);
static PHP_METHOD(Phalcon_Crypt, encrypt);
static PHP_METHOD(Phalcon_Crypt, decrypt);
static PHP_METHOD(Phalcon_Crypt, encryptBase64);
static PHP_METHOD(Phalcon_Crypt, decryptBase64);
static PHP_METHOD(Phalcon_Crypt, getAvailableCiphers);
static PHP_METHOD(Phalcon_Crypt, getAvailableModes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptpadtext, 0, 0, 4)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, blockSize)
	ZEND_ARG_INFO(0, paddingType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt__cryptunpadtext, 0, 0, 4)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_INFO(0, blockSize)
	ZEND_ARG_INFO(0, paddingType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_crypt_method_entry) {
	PHP_ME(Phalcon_Crypt, setPadding, arginfo_phalcon_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getCipher, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setMode, arginfo_phalcon_crypt_setmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, _cryptPadText, arginfo_phalcon_crypt__cryptpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, _cryptUnpadText, arginfo_phalcon_crypt__cryptunpadtext, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getAvailableModes, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_crypt_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Crypt_Exception);


zend_class_entry *phalcon_cryptinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_CryptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cryptinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setCipher, arginfo_phalcon_cryptinterface_setcipher)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getCipher, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setMode, arginfo_phalcon_cryptinterface_setmode)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getMode, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setKey, arginfo_phalcon_cryptinterface_setkey)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encrypt, arginfo_phalcon_cryptinterface_encrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decrypt, arginfo_phalcon_cryptinterface_decrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encryptBase64, arginfo_phalcon_cryptinterface_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decryptBase64, arginfo_phalcon_cryptinterface_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableCiphers, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableModes, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_db_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db);

static PHP_METHOD(Phalcon_Db, setup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_setup, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_method_entry) {
	PHP_ME(Phalcon_Db, setup, arginfo_phalcon_db_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter);

static PHP_METHOD(Phalcon_Db_Adapter, getDialectType);
static PHP_METHOD(Phalcon_Db_Adapter, getType);
static PHP_METHOD(Phalcon_Db_Adapter, getSqlVariables);
static PHP_METHOD(Phalcon_Db_Adapter, __construct);
static PHP_METHOD(Phalcon_Db_Adapter, setEventsManager);
static PHP_METHOD(Phalcon_Db_Adapter, getEventsManager);
static PHP_METHOD(Phalcon_Db_Adapter, setDialect);
static PHP_METHOD(Phalcon_Db_Adapter, getDialect);
static PHP_METHOD(Phalcon_Db_Adapter, fetchOne);
static PHP_METHOD(Phalcon_Db_Adapter, fetchAll);
static PHP_METHOD(Phalcon_Db_Adapter, fetchColumn);
static PHP_METHOD(Phalcon_Db_Adapter, insert);
static PHP_METHOD(Phalcon_Db_Adapter, insertAsDict);
static PHP_METHOD(Phalcon_Db_Adapter, update);
static PHP_METHOD(Phalcon_Db_Adapter, updateAsDict);
static PHP_METHOD(Phalcon_Db_Adapter, delete);
static PHP_METHOD(Phalcon_Db_Adapter, getColumnList);
static PHP_METHOD(Phalcon_Db_Adapter, limit);
static PHP_METHOD(Phalcon_Db_Adapter, tableExists);
static PHP_METHOD(Phalcon_Db_Adapter, viewExists);
static PHP_METHOD(Phalcon_Db_Adapter, forUpdate);
static PHP_METHOD(Phalcon_Db_Adapter, sharedLock);
static PHP_METHOD(Phalcon_Db_Adapter, createTable);
static PHP_METHOD(Phalcon_Db_Adapter, dropTable);
static PHP_METHOD(Phalcon_Db_Adapter, createView);
static PHP_METHOD(Phalcon_Db_Adapter, dropView);
static PHP_METHOD(Phalcon_Db_Adapter, addColumn);
static PHP_METHOD(Phalcon_Db_Adapter, modifyColumn);
static PHP_METHOD(Phalcon_Db_Adapter, dropColumn);
static PHP_METHOD(Phalcon_Db_Adapter, addIndex);
static PHP_METHOD(Phalcon_Db_Adapter, dropIndex);
static PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Adapter, addForeignKey);
static PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Adapter, listTables);
static PHP_METHOD(Phalcon_Db_Adapter, listViews);
static PHP_METHOD(Phalcon_Db_Adapter, describeIndexes);
static PHP_METHOD(Phalcon_Db_Adapter, describeReferences);
static PHP_METHOD(Phalcon_Db_Adapter, tableOptions);
static PHP_METHOD(Phalcon_Db_Adapter, createSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, releaseSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, rollbackSavepoint);
static PHP_METHOD(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints);
static PHP_METHOD(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints);
static PHP_METHOD(Phalcon_Db_Adapter, getNestedTransactionSavepointName);
static PHP_METHOD(Phalcon_Db_Adapter, getDefaultIdValue);
static PHP_METHOD(Phalcon_Db_Adapter, supportSequences);
static PHP_METHOD(Phalcon_Db_Adapter, useExplicitIdValue);
static PHP_METHOD(Phalcon_Db_Adapter, getDescriptor);
static PHP_METHOD(Phalcon_Db_Adapter, getConnectionId);
static PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement);
static PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement);
static PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_setdialect, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dialect, Phalcon\\Db\\DialectInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_fetchcolumn, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_insertasdict, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_updateasdict, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_method_entry) {
	PHP_ME(Phalcon_Db_Adapter, getDialectType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSqlVariables, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, __construct, arginfo_phalcon_db_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter, setEventsManager, arginfo_phalcon_db_adapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, setDialect, arginfo_phalcon_db_adapter_setdialect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDialect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, fetchOne, arginfo_phalcon_db_adapter_fetchone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, fetchAll, arginfo_phalcon_db_adapter_fetchall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, fetchColumn, arginfo_phalcon_db_adapter_fetchcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, insert, arginfo_phalcon_db_adapter_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, insertAsDict, arginfo_phalcon_db_adapter_insertasdict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, update, arginfo_phalcon_db_adapter_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, updateAsDict, arginfo_phalcon_db_adapter_updateasdict, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, delete, arginfo_phalcon_db_adapter_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getColumnList, arginfo_phalcon_db_adapter_getcolumnlist, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, limit, arginfo_phalcon_db_adapter_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, tableExists, arginfo_phalcon_db_adapter_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, viewExists, arginfo_phalcon_db_adapter_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, forUpdate, arginfo_phalcon_db_adapter_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, sharedLock, arginfo_phalcon_db_adapter_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createTable, arginfo_phalcon_db_adapter_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropTable, arginfo_phalcon_db_adapter_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createView, arginfo_phalcon_db_adapter_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropView, arginfo_phalcon_db_adapter_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addColumn, arginfo_phalcon_db_adapter_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, modifyColumn, arginfo_phalcon_db_adapter_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropColumn, arginfo_phalcon_db_adapter_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addIndex, arginfo_phalcon_db_adapter_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropIndex, arginfo_phalcon_db_adapter_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addPrimaryKey, arginfo_phalcon_db_adapter_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropPrimaryKey, arginfo_phalcon_db_adapter_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, addForeignKey, arginfo_phalcon_db_adapter_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, dropForeignKey, arginfo_phalcon_db_adapter_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getColumnDefinition, arginfo_phalcon_db_adapter_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, listTables, arginfo_phalcon_db_adapter_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, listViews, arginfo_phalcon_db_adapter_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, describeIndexes, arginfo_phalcon_db_adapter_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, describeReferences, arginfo_phalcon_db_adapter_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, tableOptions, arginfo_phalcon_db_adapter_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, createSavepoint, arginfo_phalcon_db_adapter_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, releaseSavepoint, arginfo_phalcon_db_adapter_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, rollbackSavepoint, arginfo_phalcon_db_adapter_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapter_setnestedtransactionswithsavepoints, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, isNestedTransactionsWithSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getNestedTransactionSavepointName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getDescriptor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getConnectionId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getRealSQLStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter, getSQLBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_pdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo, __construct);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, connect);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, prepare);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, executePrepared);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, query);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, execute);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, affectedRows);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, close);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeIdentifier);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, escapeString);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, convertBoundParams);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, lastInsertId);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, begin);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, rollback);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, commit);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, getTransactionLevel);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, isUnderTransaction);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, getInternalHandler);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo, getErrorInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_prepare, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_executeprepared, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, statement, PDOStatement, 0)
	ZEND_ARG_ARRAY_INFO(0, placeholders, 0)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_convertboundparams, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_begin, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo, __construct, arginfo_phalcon_db_adapter_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_Pdo, connect, arginfo_phalcon_db_adapter_pdo_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, prepare, arginfo_phalcon_db_adapter_pdo_prepare, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, executePrepared, arginfo_phalcon_db_adapter_pdo_executeprepared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, query, arginfo_phalcon_db_adapter_pdo_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, execute, arginfo_phalcon_db_adapter_pdo_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, affectedRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, escapeString, arginfo_phalcon_db_adapter_pdo_escapestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, convertBoundParams, arginfo_phalcon_db_adapter_pdo_convertboundparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, lastInsertId, arginfo_phalcon_db_adapter_pdo_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, begin, arginfo_phalcon_db_adapter_pdo_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, rollback, arginfo_phalcon_db_adapter_pdo_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, commit, arginfo_phalcon_db_adapter_pdo_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getTransactionLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, isUnderTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo, getErrorInfo, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier, arginfo_phalcon_db_adapter_pdo_mysql_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns, arginfo_phalcon_db_adapter_pdo_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_pdo_oracle_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, connect);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_oracle_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_oracle_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, connect, arginfo_phalcon_db_adapter_pdo_oracle_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns, arginfo_phalcon_db_adapter_pdo_oracle_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId, arginfo_phalcon_db_adapter_pdo_oracle_lastinsertid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_pdo_postgresql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_postgresql_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, connect, arginfo_phalcon_db_adapter_pdo_postgresql_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns, arginfo_phalcon_db_adapter_pdo_postgresql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, createTable, arginfo_phalcon_db_adapter_pdo_postgresql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn, arginfo_phalcon_db_adapter_pdo_postgresql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapter_pdo_sqlite_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite);

static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences);
static PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdo_sqlite_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, connect, arginfo_phalcon_db_adapter_pdo_sqlite_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns, arginfo_phalcon_db_adapter_pdo_sqlite_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes, arginfo_phalcon_db_adapter_pdo_sqlite_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences, arginfo_phalcon_db_adapter_pdo_sqlite_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchone, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_fetchall, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, fetchMode)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_update, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, whereCondition)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_INFO(0, columnList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, descriptor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, dataTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapeidentifier, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_lastinsertid, 0, 0, 0)
	ZEND_ARG_INFO(0, sequenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_begin, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_commit, 0, 0, 0)
	ZEND_ARG_INFO(0, nesting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints, 0, 0, 1)
	ZEND_ARG_INFO(0, nestedTransactionsWithSavepoints)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapterinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, __construct, arginfo_phalcon_db_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchOne, arginfo_phalcon_db_adapterinterface_fetchone)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, fetchAll, arginfo_phalcon_db_adapterinterface_fetchall)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, insert, arginfo_phalcon_db_adapterinterface_insert)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, update, arginfo_phalcon_db_adapterinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, delete, arginfo_phalcon_db_adapterinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnList, arginfo_phalcon_db_adapterinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, limit, arginfo_phalcon_db_adapterinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableExists, arginfo_phalcon_db_adapterinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, viewExists, arginfo_phalcon_db_adapterinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, forUpdate, arginfo_phalcon_db_adapterinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, sharedLock, arginfo_phalcon_db_adapterinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createTable, arginfo_phalcon_db_adapterinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropTable, arginfo_phalcon_db_adapterinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createView, arginfo_phalcon_db_adapterinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropView, arginfo_phalcon_db_adapterinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addColumn, arginfo_phalcon_db_adapterinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, modifyColumn, arginfo_phalcon_db_adapterinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropColumn, arginfo_phalcon_db_adapterinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addIndex, arginfo_phalcon_db_adapterinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropIndex, arginfo_phalcon_db_adapterinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addPrimaryKey, arginfo_phalcon_db_adapterinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropPrimaryKey, arginfo_phalcon_db_adapterinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, addForeignKey, arginfo_phalcon_db_adapterinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, dropForeignKey, arginfo_phalcon_db_adapterinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getColumnDefinition, arginfo_phalcon_db_adapterinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listTables, arginfo_phalcon_db_adapterinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, listViews, arginfo_phalcon_db_adapterinterface_listviews)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDescriptor, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getConnectionId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getRealSQLStatement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLVariables, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getSQLBindTypes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialectType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDialect, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, connect, arginfo_phalcon_db_adapterinterface_connect)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, query, arginfo_phalcon_db_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, execute, arginfo_phalcon_db_adapterinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, affectedRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeIdentifier, arginfo_phalcon_db_adapterinterface_escapeidentifier)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, escapeString, arginfo_phalcon_db_adapterinterface_escapestring)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, lastInsertId, arginfo_phalcon_db_adapterinterface_lastinsertid)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, begin, arginfo_phalcon_db_adapterinterface_begin)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollback, arginfo_phalcon_db_adapterinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, commit, arginfo_phalcon_db_adapterinterface_commit)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isUnderTransaction, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getInternalHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeIndexes, arginfo_phalcon_db_adapterinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeReferences, arginfo_phalcon_db_adapterinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, tableOptions, arginfo_phalcon_db_adapterinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, useExplicitIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getDefaultIdValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, supportSequences, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, createSavepoint, arginfo_phalcon_db_adapterinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, releaseSavepoint, arginfo_phalcon_db_adapterinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, rollbackSavepoint, arginfo_phalcon_db_adapterinterface_rollbacksavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, setNestedTransactionsWithSavepoints, arginfo_phalcon_db_adapterinterface_setnestedtransactionswithsavepoints)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, isNestedTransactionsWithSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, getNestedTransactionSavepointName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_AdapterInterface, describeColumns, arginfo_phalcon_db_adapterinterface_describecolumns)
	PHP_FE_END
};

zend_class_entry *phalcon_db_column_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Column);

static PHP_METHOD(Phalcon_Db_Column, getName);
static PHP_METHOD(Phalcon_Db_Column, getSchemaName);
static PHP_METHOD(Phalcon_Db_Column, getType);
static PHP_METHOD(Phalcon_Db_Column, getTypeReference);
static PHP_METHOD(Phalcon_Db_Column, getTypeValues);
static PHP_METHOD(Phalcon_Db_Column, getSize);
static PHP_METHOD(Phalcon_Db_Column, getScale);
static PHP_METHOD(Phalcon_Db_Column, getDefault);
static PHP_METHOD(Phalcon_Db_Column, __construct);
static PHP_METHOD(Phalcon_Db_Column, isUnsigned);
static PHP_METHOD(Phalcon_Db_Column, isNotNull);
static PHP_METHOD(Phalcon_Db_Column, isPrimary);
static PHP_METHOD(Phalcon_Db_Column, isAutoIncrement);
static PHP_METHOD(Phalcon_Db_Column, isNumeric);
static PHP_METHOD(Phalcon_Db_Column, isFirst);
static PHP_METHOD(Phalcon_Db_Column, getAfterPosition);
static PHP_METHOD(Phalcon_Db_Column, getBindType);
static PHP_METHOD(Phalcon_Db_Column, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_column_method_entry) {
	PHP_ME(Phalcon_Db_Column, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getSchemaName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getTypeReference, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getTypeValues, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getScale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, __construct, arginfo_phalcon_db_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Column, isUnsigned, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNotNull, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isAutoIncrement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNumeric, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getAfterPosition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getBindType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, __set_state, arginfo_phalcon_db_column___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_columninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ColumnInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_columninterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_columninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, __construct, arginfo_phalcon_db_columninterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getTypeReference, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getTypeValues, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getScale, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isUnsigned, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNotNull, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isPrimary, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isAutoIncrement, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isNumeric, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, isFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getAfterPosition, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getBindType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ColumnInterface, getDefault, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_columninterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialect_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect);

static PHP_METHOD(Phalcon_Db_Dialect, registerCustomFunction);
static PHP_METHOD(Phalcon_Db_Dialect, getCustomFunctions);
static PHP_METHOD(Phalcon_Db_Dialect, escape);
static PHP_METHOD(Phalcon_Db_Dialect, limit);
static PHP_METHOD(Phalcon_Db_Dialect, forUpdate);
static PHP_METHOD(Phalcon_Db_Dialect, sharedLock);
static PHP_METHOD(Phalcon_Db_Dialect, getColumnList);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlColumn);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpression);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlTable);
static PHP_METHOD(Phalcon_Db_Dialect, select);
static PHP_METHOD(Phalcon_Db_Dialect, supportsSavepoints);
static PHP_METHOD(Phalcon_Db_Dialect, supportsReleaseSavepoints);
static PHP_METHOD(Phalcon_Db_Dialect, createSavepoint);
static PHP_METHOD(Phalcon_Db_Dialect, releaseSavepoint);
static PHP_METHOD(Phalcon_Db_Dialect, rollbackSavepoint);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionScalar);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionObject);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionQualified);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFunctionCall);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionList);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionAll);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCastValue);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionConvertValue);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionCase);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionFrom);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionJoins);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionWhere);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionGroupBy);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionHaving);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionOrderBy);
static PHP_METHOD(Phalcon_Db_Dialect, getSqlExpressionLimit);
static PHP_METHOD(Phalcon_Db_Dialect, prepareColumnAlias);
static PHP_METHOD(Phalcon_Db_Dialect, prepareTable);
static PHP_METHOD(Phalcon_Db_Dialect, prepareQualified);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_registercustomfunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, customFunction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_escape, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getcolumnlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, columnList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlcolumn, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqltable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_select, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionscalar, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionqualified, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionbinaryoperations, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionunaryoperations, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionfunctioncall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressioncastvalue, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionconvertvalue, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressioncase, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expression, 0)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionjoins, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressiongroupby, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionhaving, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionorderby, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_getsqlexpressionlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparecolumnalias, 0, 0, 1)
	ZEND_ARG_INFO(0, qualified)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparetable, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_preparequalified, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, escapeChar)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_method_entry) {
	PHP_ME(Phalcon_Db_Dialect, registerCustomFunction, arginfo_phalcon_db_dialect_registercustomfunction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getCustomFunctions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, escape, arginfo_phalcon_db_dialect_escape, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, limit, arginfo_phalcon_db_dialect_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, forUpdate, arginfo_phalcon_db_dialect_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, sharedLock, arginfo_phalcon_db_dialect_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getColumnList, arginfo_phalcon_db_dialect_getcolumnlist, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlColumn, arginfo_phalcon_db_dialect_getsqlcolumn, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpression, arginfo_phalcon_db_dialect_getsqlexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlTable, arginfo_phalcon_db_dialect_getsqltable, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, select, arginfo_phalcon_db_dialect_select, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, createSavepoint, arginfo_phalcon_db_dialect_createsavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, releaseSavepoint, arginfo_phalcon_db_dialect_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, rollbackSavepoint, arginfo_phalcon_db_dialect_rollbacksavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionScalar, arginfo_phalcon_db_dialect_getsqlexpressionscalar, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionObject, arginfo_phalcon_db_dialect_getsqlexpressionobject, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionQualified, arginfo_phalcon_db_dialect_getsqlexpressionqualified, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionBinaryOperations, arginfo_phalcon_db_dialect_getsqlexpressionbinaryoperations, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionUnaryOperations, arginfo_phalcon_db_dialect_getsqlexpressionunaryoperations, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionFunctionCall, arginfo_phalcon_db_dialect_getsqlexpressionfunctioncall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionList, arginfo_phalcon_db_dialect_getsqlexpressionlist, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionAll, arginfo_phalcon_db_dialect_getsqlexpressionall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionCastValue, arginfo_phalcon_db_dialect_getsqlexpressioncastvalue, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionConvertValue, arginfo_phalcon_db_dialect_getsqlexpressionconvertvalue, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionCase, arginfo_phalcon_db_dialect_getsqlexpressioncase, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionFrom, arginfo_phalcon_db_dialect_getsqlexpressionfrom, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionJoins, arginfo_phalcon_db_dialect_getsqlexpressionjoins, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionWhere, arginfo_phalcon_db_dialect_getsqlexpressionwhere, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionGroupBy, arginfo_phalcon_db_dialect_getsqlexpressiongroupby, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionHaving, arginfo_phalcon_db_dialect_getsqlexpressionhaving, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionOrderBy, arginfo_phalcon_db_dialect_getsqlexpressionorderby, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, getSqlExpressionLimit, arginfo_phalcon_db_dialect_getsqlexpressionlimit, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Db_Dialect, prepareColumnAlias, arginfo_phalcon_db_dialect_preparecolumnalias, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect, prepareTable, arginfo_phalcon_db_dialect_preparetable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Db_Dialect, prepareQualified, arginfo_phalcon_db_dialect_preparequalified, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialect_mysql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_MySQL);

static PHP_METHOD(Phalcon_Db_Dialect_MySQL, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, addColumn);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, modifyColumn);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropColumn);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, addIndex);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropIndex);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, addForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, createTable);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropTable);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, createView);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropView);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableExists);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, viewExists);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeColumns);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, listTables);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, listViews);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeIndexes);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeReferences);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableOptions);
static PHP_METHOD(Phalcon_Db_Dialect_MySQL, _getTableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_mysql__gettableoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_mysql_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_MySQL, getColumnDefinition, arginfo_phalcon_db_dialect_mysql_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addColumn, arginfo_phalcon_db_dialect_mysql_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, modifyColumn, arginfo_phalcon_db_dialect_mysql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropColumn, arginfo_phalcon_db_dialect_mysql_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addIndex, arginfo_phalcon_db_dialect_mysql_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropIndex, arginfo_phalcon_db_dialect_mysql_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addPrimaryKey, arginfo_phalcon_db_dialect_mysql_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropPrimaryKey, arginfo_phalcon_db_dialect_mysql_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, addForeignKey, arginfo_phalcon_db_dialect_mysql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropForeignKey, arginfo_phalcon_db_dialect_mysql_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, createTable, arginfo_phalcon_db_dialect_mysql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropTable, arginfo_phalcon_db_dialect_mysql_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, createView, arginfo_phalcon_db_dialect_mysql_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, dropView, arginfo_phalcon_db_dialect_mysql_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, tableExists, arginfo_phalcon_db_dialect_mysql_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, viewExists, arginfo_phalcon_db_dialect_mysql_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeColumns, arginfo_phalcon_db_dialect_mysql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, listTables, arginfo_phalcon_db_dialect_mysql_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, listViews, arginfo_phalcon_db_dialect_mysql_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeIndexes, arginfo_phalcon_db_dialect_mysql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, describeReferences, arginfo_phalcon_db_dialect_mysql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, tableOptions, arginfo_phalcon_db_dialect_mysql_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_MySQL, _getTableOptions, arginfo_phalcon_db_dialect_mysql__gettableoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialect_oracle_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Oracle);

static PHP_METHOD(Phalcon_Db_Dialect_Oracle, limit);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, addColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, modifyColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, addIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, addForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, createTable);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropTable);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, createView);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropView);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, viewExists);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, listViews);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableExists);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeColumns);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, listTables);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeIndexes);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeReferences);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableOptions);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsSavepoints);
static PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_oracle_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_oracle_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Oracle, limit, arginfo_phalcon_db_dialect_oracle_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, getColumnDefinition, arginfo_phalcon_db_dialect_oracle_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addColumn, arginfo_phalcon_db_dialect_oracle_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, modifyColumn, arginfo_phalcon_db_dialect_oracle_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropColumn, arginfo_phalcon_db_dialect_oracle_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addIndex, arginfo_phalcon_db_dialect_oracle_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropIndex, arginfo_phalcon_db_dialect_oracle_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addPrimaryKey, arginfo_phalcon_db_dialect_oracle_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropPrimaryKey, arginfo_phalcon_db_dialect_oracle_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, addForeignKey, arginfo_phalcon_db_dialect_oracle_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropForeignKey, arginfo_phalcon_db_dialect_oracle_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createTable, arginfo_phalcon_db_dialect_oracle_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropTable, arginfo_phalcon_db_dialect_oracle_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, createView, arginfo_phalcon_db_dialect_oracle_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, dropView, arginfo_phalcon_db_dialect_oracle_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, viewExists, arginfo_phalcon_db_dialect_oracle_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listViews, arginfo_phalcon_db_dialect_oracle_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableExists, arginfo_phalcon_db_dialect_oracle_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeColumns, arginfo_phalcon_db_dialect_oracle_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, listTables, arginfo_phalcon_db_dialect_oracle_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeIndexes, arginfo_phalcon_db_dialect_oracle_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, describeReferences, arginfo_phalcon_db_dialect_oracle_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, tableOptions, arginfo_phalcon_db_dialect_oracle_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialect_postgresql_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql);

static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions);
static PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_postgresql__gettableoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_postgresql_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Postgresql, getColumnDefinition, arginfo_phalcon_db_dialect_postgresql_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addColumn, arginfo_phalcon_db_dialect_postgresql_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, modifyColumn, arginfo_phalcon_db_dialect_postgresql_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropColumn, arginfo_phalcon_db_dialect_postgresql_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addIndex, arginfo_phalcon_db_dialect_postgresql_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropIndex, arginfo_phalcon_db_dialect_postgresql_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addPrimaryKey, arginfo_phalcon_db_dialect_postgresql_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey, arginfo_phalcon_db_dialect_postgresql_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, addForeignKey, arginfo_phalcon_db_dialect_postgresql_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropForeignKey, arginfo_phalcon_db_dialect_postgresql_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createTable, arginfo_phalcon_db_dialect_postgresql_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropTable, arginfo_phalcon_db_dialect_postgresql_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, createView, arginfo_phalcon_db_dialect_postgresql_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, dropView, arginfo_phalcon_db_dialect_postgresql_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableExists, arginfo_phalcon_db_dialect_postgresql_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, viewExists, arginfo_phalcon_db_dialect_postgresql_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeColumns, arginfo_phalcon_db_dialect_postgresql_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, listTables, arginfo_phalcon_db_dialect_postgresql_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, listViews, arginfo_phalcon_db_dialect_postgresql_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeIndexes, arginfo_phalcon_db_dialect_postgresql_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, describeReferences, arginfo_phalcon_db_dialect_postgresql_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, tableOptions, arginfo_phalcon_db_dialect_postgresql_tableoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Postgresql, _getTableOptions, arginfo_phalcon_db_dialect_postgresql__gettableoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialect_sqlite_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite);

static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences);
static PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_droptable, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_listviews, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describeindex, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialect_sqlite_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialect_sqlite_method_entry) {
	PHP_ME(Phalcon_Db_Dialect_Sqlite, getColumnDefinition, arginfo_phalcon_db_dialect_sqlite_getcolumndefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addColumn, arginfo_phalcon_db_dialect_sqlite_addcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, modifyColumn, arginfo_phalcon_db_dialect_sqlite_modifycolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropColumn, arginfo_phalcon_db_dialect_sqlite_dropcolumn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addIndex, arginfo_phalcon_db_dialect_sqlite_addindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropIndex, arginfo_phalcon_db_dialect_sqlite_dropindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addPrimaryKey, arginfo_phalcon_db_dialect_sqlite_addprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey, arginfo_phalcon_db_dialect_sqlite_dropprimarykey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, addForeignKey, arginfo_phalcon_db_dialect_sqlite_addforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropForeignKey, arginfo_phalcon_db_dialect_sqlite_dropforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, createTable, arginfo_phalcon_db_dialect_sqlite_createtable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropTable, arginfo_phalcon_db_dialect_sqlite_droptable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, createView, arginfo_phalcon_db_dialect_sqlite_createview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, dropView, arginfo_phalcon_db_dialect_sqlite_dropview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableExists, arginfo_phalcon_db_dialect_sqlite_tableexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, viewExists, arginfo_phalcon_db_dialect_sqlite_viewexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeColumns, arginfo_phalcon_db_dialect_sqlite_describecolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, listTables, arginfo_phalcon_db_dialect_sqlite_listtables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, listViews, arginfo_phalcon_db_dialect_sqlite_listviews, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndexes, arginfo_phalcon_db_dialect_sqlite_describeindexes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeIndex, arginfo_phalcon_db_dialect_sqlite_describeindex, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, describeReferences, arginfo_phalcon_db_dialect_sqlite_describereferences, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Dialect_Sqlite, tableOptions, arginfo_phalcon_db_dialect_sqlite_tableoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_dialectinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_DialectInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_limit, 0, 0, 2)
	ZEND_ARG_INFO(0, sqlQuery)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_forupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_sharedlock, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlQuery)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_select, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumnlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, columnList, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_getcolumndefinition, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_modifycolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, column, Phalcon\\Db\\ColumnInterface, 0)
	ZEND_ARG_OBJ_INFO(0, currentColumn, Phalcon\\Db\\ColumnInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropcolumn, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, columnName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropindex, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, indexName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addprimarykey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, index, Phalcon\\Db\\IndexInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropprimarykey, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_addforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_OBJ_INFO(0, reference, Phalcon\\Db\\ReferenceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropforeignkey, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, referenceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createtable, 0, 0, 3)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createview, 0, 0, 2)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_droptable, 0, 0, 2)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_dropview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
	ZEND_ARG_INFO(0, ifExists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableexists, 0, 0, 1)
	ZEND_ARG_INFO(0, tableName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_viewexists, 0, 0, 1)
	ZEND_ARG_INFO(0, viewName)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describecolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_listtables, 0, 0, 0)
	ZEND_ARG_INFO(0, schemaName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describeindexes, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_describereferences, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_tableoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_createsavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_dialectinterface_rollbacksavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_dialectinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, limit, arginfo_phalcon_db_dialectinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, forUpdate, arginfo_phalcon_db_dialectinterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, sharedLock, arginfo_phalcon_db_dialectinterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, select, arginfo_phalcon_db_dialectinterface_select)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnList, arginfo_phalcon_db_dialectinterface_getcolumnlist)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, getColumnDefinition, arginfo_phalcon_db_dialectinterface_getcolumndefinition)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addColumn, arginfo_phalcon_db_dialectinterface_addcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, modifyColumn, arginfo_phalcon_db_dialectinterface_modifycolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropColumn, arginfo_phalcon_db_dialectinterface_dropcolumn)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addIndex, arginfo_phalcon_db_dialectinterface_addindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropIndex, arginfo_phalcon_db_dialectinterface_dropindex)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addPrimaryKey, arginfo_phalcon_db_dialectinterface_addprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropPrimaryKey, arginfo_phalcon_db_dialectinterface_dropprimarykey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, addForeignKey, arginfo_phalcon_db_dialectinterface_addforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropForeignKey, arginfo_phalcon_db_dialectinterface_dropforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createTable, arginfo_phalcon_db_dialectinterface_createtable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createView, arginfo_phalcon_db_dialectinterface_createview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropTable, arginfo_phalcon_db_dialectinterface_droptable)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, dropView, arginfo_phalcon_db_dialectinterface_dropview)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableExists, arginfo_phalcon_db_dialectinterface_tableexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, viewExists, arginfo_phalcon_db_dialectinterface_viewexists)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeColumns, arginfo_phalcon_db_dialectinterface_describecolumns)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, listTables, arginfo_phalcon_db_dialectinterface_listtables)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeIndexes, arginfo_phalcon_db_dialectinterface_describeindexes)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, describeReferences, arginfo_phalcon_db_dialectinterface_describereferences)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, tableOptions, arginfo_phalcon_db_dialectinterface_tableoptions)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, supportsReleaseSavepoints, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, createSavepoint, arginfo_phalcon_db_dialectinterface_createsavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, releaseSavepoint, arginfo_phalcon_db_dialectinterface_releasesavepoint)
	PHP_ABSTRACT_ME(Phalcon_Db_DialectInterface, rollbackSavepoint, arginfo_phalcon_db_dialectinterface_rollbacksavepoint)
	PHP_FE_END
};

zend_class_entry *phalcon_db_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Exception);


zend_class_entry *phalcon_db_index_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Index);

static PHP_METHOD(Phalcon_Db_Index, getName);
static PHP_METHOD(Phalcon_Db_Index, getColumns);
static PHP_METHOD(Phalcon_Db_Index, getType);
static PHP_METHOD(Phalcon_Db_Index, __construct);
static PHP_METHOD(Phalcon_Db_Index, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_index___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_index_method_entry) {
	PHP_ME(Phalcon_Db_Index, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Index, __construct, arginfo_phalcon_db_index___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Index, __set_state, arginfo_phalcon_db_index___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_indexinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_IndexInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, indexName)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_indexinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_indexinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, __construct, arginfo_phalcon_db_indexinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_IndexInterface, getType, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_indexinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_profiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler);

static PHP_METHOD(Phalcon_Db_Profiler, startProfile);
static PHP_METHOD(Phalcon_Db_Profiler, stopProfile);
static PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements);
static PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds);
static PHP_METHOD(Phalcon_Db_Profiler, getProfiles);
static PHP_METHOD(Phalcon_Db_Profiler, reset);
static PHP_METHOD(Phalcon_Db_Profiler, getLastProfile);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_startprofile, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, sqlVariables)
	ZEND_ARG_INFO(0, sqlBindTypes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_profiler_method_entry) {
	PHP_ME(Phalcon_Db_Profiler, startProfile, arginfo_phalcon_db_profiler_startprofile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, stopProfile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getNumberTotalStatements, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getProfiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler, getLastProfile, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_profiler_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Profiler_Item);

static PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlStatement);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlStatement);
static PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlVariables);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlVariables);
static PHP_METHOD(Phalcon_Db_Profiler_Item, setSqlBindTypes);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getSqlBindTypes);
static PHP_METHOD(Phalcon_Db_Profiler_Item, setInitialTime);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getInitialTime);
static PHP_METHOD(Phalcon_Db_Profiler_Item, setFinalTime);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getFinalTime);
static PHP_METHOD(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlstatement, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlStatement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlvariables, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlVariables)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setsqlbindtypes, 0, 0, 1)
	ZEND_ARG_INFO(0, sqlBindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setinitialtime, 0, 0, 1)
	ZEND_ARG_INFO(0, initialTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_profiler_item_setfinaltime, 0, 0, 1)
	ZEND_ARG_INFO(0, finalTime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_profiler_item_method_entry) {
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlStatement, arginfo_phalcon_db_profiler_item_setsqlstatement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlStatement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlVariables, arginfo_phalcon_db_profiler_item_setsqlvariables, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlVariables, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setSqlBindTypes, arginfo_phalcon_db_profiler_item_setsqlbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getSqlBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setInitialTime, arginfo_phalcon_db_profiler_item_setinitialtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getInitialTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, setFinalTime, arginfo_phalcon_db_profiler_item_setfinaltime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getFinalTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Profiler_Item, getTotalElapsedSeconds, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_rawvalue_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue);

static PHP_METHOD(Phalcon_Db_RawValue, getValue);
static PHP_METHOD(Phalcon_Db_RawValue, __toString);
static PHP_METHOD(Phalcon_Db_RawValue, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_rawvalue___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_rawvalue_method_entry) {
	PHP_ME(Phalcon_Db_RawValue, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_RawValue, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_RawValue, __construct, arginfo_phalcon_db_rawvalue___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_db_reference_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Reference);

static PHP_METHOD(Phalcon_Db_Reference, getName);
static PHP_METHOD(Phalcon_Db_Reference, getSchemaName);
static PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema);
static PHP_METHOD(Phalcon_Db_Reference, getReferencedTable);
static PHP_METHOD(Phalcon_Db_Reference, getColumns);
static PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns);
static PHP_METHOD(Phalcon_Db_Reference, getOnDelete);
static PHP_METHOD(Phalcon_Db_Reference, getOnUpdate);
static PHP_METHOD(Phalcon_Db_Reference, __construct);
static PHP_METHOD(Phalcon_Db_Reference, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_reference___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_reference_method_entry) {
	PHP_ME(Phalcon_Db_Reference, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getSchemaName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getReferencedColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, getOnUpdate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Reference, __construct, arginfo_phalcon_db_reference___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Reference, __set_state, arginfo_phalcon_db_reference___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_referenceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ReferenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, referenceName)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_referenceinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_referenceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, __construct, arginfo_phalcon_db_referenceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getSchemaName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedTable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getReferencedColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getOnDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ReferenceInterface, getOnUpdate, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_db_referenceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_result_pdo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Result_Pdo);

static PHP_METHOD(Phalcon_Db_Result_Pdo, __construct);
static PHP_METHOD(Phalcon_Db_Result_Pdo, execute);
static PHP_METHOD(Phalcon_Db_Result_Pdo, fetch);
static PHP_METHOD(Phalcon_Db_Result_Pdo, fetchArray);
static PHP_METHOD(Phalcon_Db_Result_Pdo, fetchAll);
static PHP_METHOD(Phalcon_Db_Result_Pdo, numRows);
static PHP_METHOD(Phalcon_Db_Result_Pdo, dataSeek);
static PHP_METHOD(Phalcon_Db_Result_Pdo, setFetchMode);
static PHP_METHOD(Phalcon_Db_Result_Pdo, getInternalResult);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, result, PDOStatement, 0)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_result_pdo_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_result_pdo_method_entry) {
	PHP_ME(Phalcon_Db_Result_Pdo, __construct, arginfo_phalcon_db_result_pdo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Result_Pdo, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, fetchAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, numRows, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, dataSeek, arginfo_phalcon_db_result_pdo_dataseek, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, setFetchMode, arginfo_phalcon_db_result_pdo_setfetchmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Result_Pdo, getInternalResult, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_db_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, result, PDOStatement, 0)
	ZEND_ARG_INFO(0, sqlStatement)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_dataseek, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_resultinterface_setfetchmode, 0, 0, 1)
	ZEND_ARG_INFO(0, fetchMode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, __construct, arginfo_phalcon_db_resultinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, execute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchArray, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, fetchAll, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, numRows, NULL)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, dataSeek, arginfo_phalcon_db_resultinterface_dataseek)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, setFetchMode, arginfo_phalcon_db_resultinterface_setfetchmode)
	PHP_ABSTRACT_ME(Phalcon_Db_ResultInterface, getInternalResult, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_debug_ce;

ZEPHIR_INIT_CLASS(Phalcon_Debug);

static PHP_METHOD(Phalcon_Debug, setUri);
static PHP_METHOD(Phalcon_Debug, setShowBackTrace);
static PHP_METHOD(Phalcon_Debug, setShowFiles);
static PHP_METHOD(Phalcon_Debug, setShowFileFragment);
static PHP_METHOD(Phalcon_Debug, listen);
static PHP_METHOD(Phalcon_Debug, listenExceptions);
static PHP_METHOD(Phalcon_Debug, listenLowSeverity);
static PHP_METHOD(Phalcon_Debug, halt);
static PHP_METHOD(Phalcon_Debug, debugVar);
static PHP_METHOD(Phalcon_Debug, clearVars);
static PHP_METHOD(Phalcon_Debug, _escapeString);
static PHP_METHOD(Phalcon_Debug, _getArrayDump);
static PHP_METHOD(Phalcon_Debug, _getVarDump);
static PHP_METHOD(Phalcon_Debug, getMajorVersion);
static PHP_METHOD(Phalcon_Debug, getVersion);
static PHP_METHOD(Phalcon_Debug, getCssSources);
static PHP_METHOD(Phalcon_Debug, getJsSources);
static PHP_METHOD(Phalcon_Debug, showTraceItem);
static PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity);
static PHP_METHOD(Phalcon_Debug, onUncaughtException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_seturi, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowbacktrace, 0, 0, 1)
	ZEND_ARG_INFO(0, showBackTrace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfiles, 0, 0, 1)
	ZEND_ARG_INFO(0, showFiles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_setshowfilefragment, 0, 0, 1)
	ZEND_ARG_INFO(0, showFileFragment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_listen, 0, 0, 0)
	ZEND_ARG_INFO(0, exceptions)
	ZEND_ARG_INFO(0, lowSeverity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_debugvar, 0, 0, 1)
	ZEND_ARG_INFO(0, varz)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__escapestring, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__getarraydump, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug__getvardump, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_showtraceitem, 0, 0, 2)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_onuncaughtlowseverity, 0, 0, 4)
	ZEND_ARG_INFO(0, severity)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_onuncaughtexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_debug_method_entry) {
	PHP_ME(Phalcon_Debug, setUri, arginfo_phalcon_debug_seturi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowBackTrace, arginfo_phalcon_debug_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowFiles, arginfo_phalcon_debug_setshowfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, setShowFileFragment, arginfo_phalcon_debug_setshowfilefragment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listen, arginfo_phalcon_debug_listen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listenExceptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, listenLowSeverity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, halt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, debugVar, arginfo_phalcon_debug_debugvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, clearVars, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, _escapeString, arginfo_phalcon_debug__escapestring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, _getArrayDump, arginfo_phalcon_debug__getarraydump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, _getVarDump, arginfo_phalcon_debug__getvardump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug, getMajorVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getCssSources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, getJsSources, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, showTraceItem, arginfo_phalcon_debug_showtraceitem, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Debug, onUncaughtLowSeverity, arginfo_phalcon_debug_onuncaughtlowseverity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug, onUncaughtException, arginfo_phalcon_debug_onuncaughtexception, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_debug_dump_ce;

ZEPHIR_INIT_CLASS(Phalcon_Debug_Dump);

static PHP_METHOD(Phalcon_Debug_Dump, getDetailed);
static PHP_METHOD(Phalcon_Debug_Dump, setDetailed);
static PHP_METHOD(Phalcon_Debug_Dump, __construct);
static PHP_METHOD(Phalcon_Debug_Dump, all);
static PHP_METHOD(Phalcon_Debug_Dump, getStyle);
static PHP_METHOD(Phalcon_Debug_Dump, setStyles);
static PHP_METHOD(Phalcon_Debug_Dump, one);
static PHP_METHOD(Phalcon_Debug_Dump, output);
static PHP_METHOD(Phalcon_Debug_Dump, variable);
static PHP_METHOD(Phalcon_Debug_Dump, variables);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_setdetailed, 0, 0, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, styles, 1)
	ZEND_ARG_INFO(0, detailed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_getstyle, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_setstyles, 0, 0, 0)
	ZEND_ARG_INFO(0, styles)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_one, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_output, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, tab)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_debug_dump_variable, 0, 0, 1)
	ZEND_ARG_INFO(0, variable)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_debug_dump_method_entry) {
	PHP_ME(Phalcon_Debug_Dump, getDetailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, setDetailed, arginfo_phalcon_debug_dump_setdetailed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, __construct, arginfo_phalcon_debug_dump___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Debug_Dump, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, getStyle, arginfo_phalcon_debug_dump_getstyle, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug_Dump, setStyles, arginfo_phalcon_debug_dump_setstyles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, one, arginfo_phalcon_debug_dump_one, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, output, arginfo_phalcon_debug_dump_output, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Debug_Dump, variable, arginfo_phalcon_debug_dump_variable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Debug_Dump, variables, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_debug_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Debug_Exception);


zend_class_entry *phalcon_di_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di);

static PHP_METHOD(Phalcon_Di, __construct);
static PHP_METHOD(Phalcon_Di, setInternalEventsManager);
static PHP_METHOD(Phalcon_Di, getInternalEventsManager);
static PHP_METHOD(Phalcon_Di, set);
static PHP_METHOD(Phalcon_Di, setShared);
static PHP_METHOD(Phalcon_Di, remove);
static PHP_METHOD(Phalcon_Di, attempt);
static PHP_METHOD(Phalcon_Di, setRaw);
static PHP_METHOD(Phalcon_Di, getRaw);
static PHP_METHOD(Phalcon_Di, getService);
static PHP_METHOD(Phalcon_Di, get);
static PHP_METHOD(Phalcon_Di, getShared);
static PHP_METHOD(Phalcon_Di, has);
static PHP_METHOD(Phalcon_Di, wasFreshInstance);
static PHP_METHOD(Phalcon_Di, getServices);
static PHP_METHOD(Phalcon_Di, offsetExists);
static PHP_METHOD(Phalcon_Di, offsetSet);
static PHP_METHOD(Phalcon_Di, offsetGet);
static PHP_METHOD(Phalcon_Di, offsetUnset);
static PHP_METHOD(Phalcon_Di, __call);
static PHP_METHOD(Phalcon_Di, setDefault);
static PHP_METHOD(Phalcon_Di, getDefault);
static PHP_METHOD(Phalcon_Di, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setinternaleventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setraw, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Phalcon\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_setdefault, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_method_entry) {
	PHP_ME(Phalcon_Di, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Di, setInternalEventsManager, arginfo_phalcon_di_setinternaleventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getInternalEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, set, arginfo_phalcon_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setShared, arginfo_phalcon_di_setshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, remove, arginfo_phalcon_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, attempt, arginfo_phalcon_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setRaw, arginfo_phalcon_di_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getRaw, arginfo_phalcon_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getService, arginfo_phalcon_di_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, get, arginfo_phalcon_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getShared, arginfo_phalcon_di_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, has, arginfo_phalcon_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, wasFreshInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, getServices, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetExists, arginfo_phalcon_di_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetSet, arginfo_phalcon_di_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetGet, arginfo_phalcon_di_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, offsetUnset, arginfo_phalcon_di_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, __call, arginfo_phalcon_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di, setDefault, arginfo_phalcon_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, getDefault, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Di, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_di_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Exception);


zend_class_entry *phalcon_di_factorydefault_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault);

static PHP_METHOD(Phalcon_Di_FactoryDefault, __construct);

ZEPHIR_INIT_FUNCS(phalcon_di_factorydefault_method_entry) {
	PHP_ME(Phalcon_Di_FactoryDefault, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_di_factorydefault_cli_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault_Cli);

static PHP_METHOD(Phalcon_Di_FactoryDefault_Cli, __construct);

ZEPHIR_INIT_FUNCS(phalcon_di_factorydefault_cli_method_entry) {
	PHP_ME(Phalcon_Di_FactoryDefault_Cli, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_di_injectable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable);

static PHP_METHOD(Phalcon_Di_Injectable, setDI);
static PHP_METHOD(Phalcon_Di_Injectable, getDI);
static PHP_METHOD(Phalcon_Di_Injectable, setEventsManager);
static PHP_METHOD(Phalcon_Di_Injectable, getEventsManager);
static PHP_METHOD(Phalcon_Di_Injectable, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectable___get, 0, 0, 1)
	ZEND_ARG_INFO(0, propertyName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectable_method_entry) {
	PHP_ME(Phalcon_Di_Injectable, setDI, arginfo_phalcon_di_injectable_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, setEventsManager, arginfo_phalcon_di_injectable_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_di_injectionawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_InjectionAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectionawareinterface_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectionawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, setDI, arginfo_phalcon_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, getDI, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_di_service_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Service);

static PHP_METHOD(Phalcon_Di_Service, __construct);
static PHP_METHOD(Phalcon_Di_Service, getName);
static PHP_METHOD(Phalcon_Di_Service, setShared);
static PHP_METHOD(Phalcon_Di_Service, isShared);
static PHP_METHOD(Phalcon_Di_Service, setSharedInstance);
static PHP_METHOD(Phalcon_Di_Service, setDefinition);
static PHP_METHOD(Phalcon_Di_Service, getDefinition);
static PHP_METHOD(Phalcon_Di_Service, resolve);
static PHP_METHOD(Phalcon_Di_Service, setParameter);
static PHP_METHOD(Phalcon_Di_Service, getParameter);
static PHP_METHOD(Phalcon_Di_Service, isResolved);
static PHP_METHOD(Phalcon_Di_Service, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setsharedinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, sharedInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_setparameter, 0, 0, 2)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_ARRAY_INFO(0, parameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_getparameter, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_method_entry) {
	PHP_ME(Phalcon_Di_Service, __construct, arginfo_phalcon_di_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Di_Service, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setShared, arginfo_phalcon_di_service_setshared, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, isShared, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setSharedInstance, arginfo_phalcon_di_service_setsharedinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setDefinition, arginfo_phalcon_di_service_setdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, getDefinition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, resolve, arginfo_phalcon_di_service_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, setParameter, arginfo_phalcon_di_service_setparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, getParameter, arginfo_phalcon_di_service_getparameter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, isResolved, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Di_Service, __set_state, arginfo_phalcon_di_service___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_di_service_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder);

static PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameter);
static PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameters);
static PHP_METHOD(Phalcon_Di_Service_Builder, build);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildparameter, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, position)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder__buildparameters, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_service_builder_build, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, definition, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_service_builder_method_entry) {
	PHP_ME(Phalcon_Di_Service_Builder, _buildParameter, arginfo_phalcon_di_service_builder__buildparameter, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Di_Service_Builder, _buildParameters, arginfo_phalcon_di_service_builder__buildparameters, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Di_Service_Builder, build, arginfo_phalcon_di_service_builder_build, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_di_serviceinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setshared, 0, 0, 1)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, __construct, arginfo_phalcon_di_serviceinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, setShared, arginfo_phalcon_di_serviceinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, isShared, NULL)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, setDefinition, arginfo_phalcon_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, getDefinition, NULL)
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceInterface, resolve, arginfo_phalcon_di_serviceinterface_resolve)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_di_serviceinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_diinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setshared, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_attempt, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getshared, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setraw, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Phalcon\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getraw, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_diinterface_setdefault, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_diinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DiInterface, set, arginfo_phalcon_diinterface_set)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setShared, arginfo_phalcon_diinterface_setshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, remove, arginfo_phalcon_diinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, attempt, arginfo_phalcon_diinterface_attempt)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, get, arginfo_phalcon_diinterface_get)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getShared, arginfo_phalcon_diinterface_getshared)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, setRaw, arginfo_phalcon_diinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getRaw, arginfo_phalcon_diinterface_getraw)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getService, arginfo_phalcon_diinterface_getservice)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, has, arginfo_phalcon_diinterface_has)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, wasFreshInstance, NULL)
	PHP_ABSTRACT_ME(Phalcon_DiInterface, getServices, NULL)
	ZEND_FENTRY(setDefault, NULL, arginfo_phalcon_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(getDefault, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Dispatcher);

static PHP_METHOD(Phalcon_Dispatcher, __construct);
static PHP_METHOD(Phalcon_Dispatcher, setDI);
static PHP_METHOD(Phalcon_Dispatcher, getDI);
static PHP_METHOD(Phalcon_Dispatcher, setEventsManager);
static PHP_METHOD(Phalcon_Dispatcher, getEventsManager);
static PHP_METHOD(Phalcon_Dispatcher, setActionSuffix);
static PHP_METHOD(Phalcon_Dispatcher, setModuleName);
static PHP_METHOD(Phalcon_Dispatcher, getModuleName);
static PHP_METHOD(Phalcon_Dispatcher, setNamespaceName);
static PHP_METHOD(Phalcon_Dispatcher, getNamespaceName);
static PHP_METHOD(Phalcon_Dispatcher, setDefaultNamespace);
static PHP_METHOD(Phalcon_Dispatcher, getDefaultNamespace);
static PHP_METHOD(Phalcon_Dispatcher, setDefaultAction);
static PHP_METHOD(Phalcon_Dispatcher, setActionName);
static PHP_METHOD(Phalcon_Dispatcher, getActionName);
static PHP_METHOD(Phalcon_Dispatcher, setParams);
static PHP_METHOD(Phalcon_Dispatcher, getParams);
static PHP_METHOD(Phalcon_Dispatcher, setParam);
static PHP_METHOD(Phalcon_Dispatcher, getParam);
static PHP_METHOD(Phalcon_Dispatcher, getActiveMethod);
static PHP_METHOD(Phalcon_Dispatcher, isFinished);
static PHP_METHOD(Phalcon_Dispatcher, setReturnedValue);
static PHP_METHOD(Phalcon_Dispatcher, getReturnedValue);
static PHP_METHOD(Phalcon_Dispatcher, dispatch);
static PHP_METHOD(Phalcon_Dispatcher, forward);
static PHP_METHOD(Phalcon_Dispatcher, wasForwarded);
static PHP_METHOD(Phalcon_Dispatcher, getHandlerClass);
static PHP_METHOD(Phalcon_Dispatcher, _resolveEmptyProperties);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setnamespacename, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_setreturnedvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcher_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dispatcher_method_entry) {
	PHP_ME(Phalcon_Dispatcher, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Dispatcher, setDI, arginfo_phalcon_dispatcher_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setEventsManager, arginfo_phalcon_dispatcher_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionSuffix, arginfo_phalcon_dispatcher_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setModuleName, arginfo_phalcon_dispatcher_setmodulename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setNamespaceName, arginfo_phalcon_dispatcher_setnamespacename, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultNamespace, arginfo_phalcon_dispatcher_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getDefaultNamespace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setDefaultAction, arginfo_phalcon_dispatcher_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setActionName, arginfo_phalcon_dispatcher_setactionname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParams, arginfo_phalcon_dispatcher_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setParam, arginfo_phalcon_dispatcher_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getParam, arginfo_phalcon_dispatcher_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getActiveMethod, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, isFinished, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, setReturnedValue, arginfo_phalcon_dispatcher_setreturnedvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, dispatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, forward, arginfo_phalcon_dispatcher_forward, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, wasForwarded, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, getHandlerClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Dispatcher, _resolveEmptyProperties, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setnamespacename, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setmodulename, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setactionname, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparams, 0, 0, 1)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_setparam, 0, 0, 2)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_dispatcherinterface_forward, 0, 0, 1)
	ZEND_ARG_INFO(0, forward)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionSuffix, arginfo_phalcon_dispatcherinterface_setactionsuffix)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultNamespace, arginfo_phalcon_dispatcherinterface_setdefaultnamespace)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setDefaultAction, arginfo_phalcon_dispatcherinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setNamespaceName, arginfo_phalcon_dispatcherinterface_setnamespacename)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setModuleName, arginfo_phalcon_dispatcherinterface_setmodulename)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setActionName, arginfo_phalcon_dispatcherinterface_setactionname)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParams, arginfo_phalcon_dispatcherinterface_setparams)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, setParam, arginfo_phalcon_dispatcherinterface_setparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getParam, arginfo_phalcon_dispatcherinterface_getparam)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, isFinished, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, getReturnedValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, dispatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_DispatcherInterface, forward, arginfo_phalcon_dispatcherinterface_forward)
	PHP_FE_END
};

zend_class_entry *phalcon_escaper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper);

static PHP_METHOD(Phalcon_Escaper, setEncoding);
static PHP_METHOD(Phalcon_Escaper, getEncoding);
static PHP_METHOD(Phalcon_Escaper, setHtmlQuoteType);
static PHP_METHOD(Phalcon_Escaper, detectEncoding);
static PHP_METHOD(Phalcon_Escaper, normalizeEncoding);
static PHP_METHOD(Phalcon_Escaper, escapeHtml);
static PHP_METHOD(Phalcon_Escaper, escapeHtmlAttr);
static PHP_METHOD(Phalcon_Escaper, escapeCss);
static PHP_METHOD(Phalcon_Escaper, escapeJs);
static PHP_METHOD(Phalcon_Escaper, escapeUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_detectencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_normalizeencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaper_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaper_method_entry) {
	PHP_ME(Phalcon_Escaper, setEncoding, arginfo_phalcon_escaper_setencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, getEncoding, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, setHtmlQuoteType, arginfo_phalcon_escaper_sethtmlquotetype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, detectEncoding, arginfo_phalcon_escaper_detectencoding, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Escaper, normalizeEncoding, arginfo_phalcon_escaper_normalizeencoding, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Escaper, escapeHtml, arginfo_phalcon_escaper_escapehtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeHtmlAttr, arginfo_phalcon_escaper_escapehtmlattr, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeCss, arginfo_phalcon_escaper_escapecss, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeJs, arginfo_phalcon_escaper_escapejs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Escaper, escapeUrl, arginfo_phalcon_escaper_escapeurl, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_escaper_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Escaper_Exception);


zend_class_entry *phalcon_escaperinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_EscaperInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_setencoding, 0, 0, 1)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_sethtmlquotetype, 0, 0, 1)
	ZEND_ARG_INFO(0, quoteType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtml, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapehtmlattr, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapecss, 0, 0, 1)
	ZEND_ARG_INFO(0, css)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapejs, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_escaperinterface_escapeurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_escaperinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setEncoding, arginfo_phalcon_escaperinterface_setencoding)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, getEncoding, NULL)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, setHtmlQuoteType, arginfo_phalcon_escaperinterface_sethtmlquotetype)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtml, arginfo_phalcon_escaperinterface_escapehtml)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeHtmlAttr, arginfo_phalcon_escaperinterface_escapehtmlattr)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeCss, arginfo_phalcon_escaperinterface_escapecss)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeJs, arginfo_phalcon_escaperinterface_escapejs)
	PHP_ABSTRACT_ME(Phalcon_EscaperInterface, escapeUrl, arginfo_phalcon_escaperinterface_escapeurl)
	PHP_FE_END
};

zend_class_entry *phalcon_events_event_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Event);

static PHP_METHOD(Phalcon_Events_Event, setType);
static PHP_METHOD(Phalcon_Events_Event, getType);
static PHP_METHOD(Phalcon_Events_Event, getSource);
static PHP_METHOD(Phalcon_Events_Event, setData);
static PHP_METHOD(Phalcon_Events_Event, getData);
static PHP_METHOD(Phalcon_Events_Event, getCancelable);
static PHP_METHOD(Phalcon_Events_Event, __construct);
static PHP_METHOD(Phalcon_Events_Event, stop);
static PHP_METHOD(Phalcon_Events_Event, isStopped);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_event___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_event_method_entry) {
	PHP_ME(Phalcon_Events_Event, setType, arginfo_phalcon_events_event_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, setData, arginfo_phalcon_events_event_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, getCancelable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, __construct, arginfo_phalcon_events_event___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Events_Event, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Event, isStopped, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_events_eventsawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_EventsAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_eventsawareinterface_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_eventsawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Events_EventsAwareInterface, getEventsManager, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_events_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Exception);


zend_class_entry *phalcon_events_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_Manager);

static PHP_METHOD(Phalcon_Events_Manager, attach);
static PHP_METHOD(Phalcon_Events_Manager, detach);
static PHP_METHOD(Phalcon_Events_Manager, enablePriorities);
static PHP_METHOD(Phalcon_Events_Manager, arePrioritiesEnabled);
static PHP_METHOD(Phalcon_Events_Manager, collectResponses);
static PHP_METHOD(Phalcon_Events_Manager, isCollecting);
static PHP_METHOD(Phalcon_Events_Manager, getResponses);
static PHP_METHOD(Phalcon_Events_Manager, detachAll);
static PHP_METHOD(Phalcon_Events_Manager, dettachAll);
static PHP_METHOD(Phalcon_Events_Manager, fireQueue);
static PHP_METHOD(Phalcon_Events_Manager, fire);
static PHP_METHOD(Phalcon_Events_Manager, hasListeners);
static PHP_METHOD(Phalcon_Events_Manager, getListeners);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_enablepriorities, 0, 0, 1)
	ZEND_ARG_INFO(0, enablePriorities)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_collectresponses, 0, 0, 1)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_dettachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_firequeue, 0, 0, 2)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, cancelable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_haslisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_manager_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_manager_method_entry) {
	PHP_ME(Phalcon_Events_Manager, attach, arginfo_phalcon_events_manager_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, detach, arginfo_phalcon_events_manager_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, enablePriorities, arginfo_phalcon_events_manager_enablepriorities, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, arePrioritiesEnabled, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, collectResponses, arginfo_phalcon_events_manager_collectresponses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, isCollecting, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getResponses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, detachAll, arginfo_phalcon_events_manager_detachall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, dettachAll, arginfo_phalcon_events_manager_dettachall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, fireQueue, arginfo_phalcon_events_manager_firequeue, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Events_Manager, fire, arginfo_phalcon_events_manager_fire, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, hasListeners, arginfo_phalcon_events_manager_haslisteners, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Events_Manager, getListeners, arginfo_phalcon_events_manager_getlisteners, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_events_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Events_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_detach, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_detachall, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_fire, 0, 0, 2)
	ZEND_ARG_INFO(0, eventType)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_events_managerinterface_getlisteners, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_events_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, attach, arginfo_phalcon_events_managerinterface_attach)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, detach, arginfo_phalcon_events_managerinterface_detach)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, detachAll, arginfo_phalcon_events_managerinterface_detachall)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, fire, arginfo_phalcon_events_managerinterface_fire)
	PHP_ABSTRACT_ME(Phalcon_Events_ManagerInterface, getListeners, arginfo_phalcon_events_managerinterface_getlisteners)
	PHP_FE_END
};

zend_class_entry *phalcon_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Exception);


zend_class_entry *phalcon_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter);

static PHP_METHOD(Phalcon_Filter, add);
static PHP_METHOD(Phalcon_Filter, sanitize);
static PHP_METHOD(Phalcon_Filter, _sanitize);
static PHP_METHOD(Phalcon_Filter, getFilters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter__sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_method_entry) {
	PHP_ME(Phalcon_Filter, add, arginfo_phalcon_filter_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, _sanitize, arginfo_phalcon_filter__sanitize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_filter_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Exception);


zend_class_entry *phalcon_filter_userfilterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_UserFilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_userfilterinterface_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_userfilterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Filter_UserFilterInterface, filter, arginfo_phalcon_filter_userfilterinterface_filter)
	PHP_FE_END
};

zend_class_entry *phalcon_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_FilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, add, arginfo_phalcon_filterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, sanitize, arginfo_phalcon_filterinterface_sanitize)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, getFilters, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_flash_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash);

static PHP_METHOD(Phalcon_Flash, __construct);
static PHP_METHOD(Phalcon_Flash, setImplicitFlush);
static PHP_METHOD(Phalcon_Flash, setAutomaticHtml);
static PHP_METHOD(Phalcon_Flash, setCssClasses);
static PHP_METHOD(Phalcon_Flash, error);
static PHP_METHOD(Phalcon_Flash, notice);
static PHP_METHOD(Phalcon_Flash, success);
static PHP_METHOD(Phalcon_Flash, warning);
static PHP_METHOD(Phalcon_Flash, outputMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cssClasses)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setimplicitflush, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitFlush)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setautomatichtml, 0, 0, 1)
	ZEND_ARG_INFO(0, automaticHtml)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_setcssclasses, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cssClasses, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_outputmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_method_entry) {
	PHP_ME(Phalcon_Flash, __construct, arginfo_phalcon_flash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Flash, setImplicitFlush, arginfo_phalcon_flash_setimplicitflush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setAutomaticHtml, arginfo_phalcon_flash_setautomatichtml, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, setCssClasses, arginfo_phalcon_flash_setcssclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, error, arginfo_phalcon_flash_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, notice, arginfo_phalcon_flash_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, success, arginfo_phalcon_flash_success, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, warning, arginfo_phalcon_flash_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash, outputMessage, arginfo_phalcon_flash_outputmessage, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_flash_direct_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Direct);

static PHP_METHOD(Phalcon_Flash_Direct, message);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_direct_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_direct_method_entry) {
	PHP_ME(Phalcon_Flash_Direct, message, arginfo_phalcon_flash_direct_message, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_flash_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Exception);


zend_class_entry *phalcon_flash_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Flash_Session);

static PHP_METHOD(Phalcon_Flash_Session, setDI);
static PHP_METHOD(Phalcon_Flash_Session, getDI);
static PHP_METHOD(Phalcon_Flash_Session, _getSessionMessages);
static PHP_METHOD(Phalcon_Flash_Session, _setSessionMessages);
static PHP_METHOD(Phalcon_Flash_Session, message);
static PHP_METHOD(Phalcon_Flash_Session, has);
static PHP_METHOD(Phalcon_Flash_Session, getMessages);
static PHP_METHOD(Phalcon_Flash_Session, output);
static PHP_METHOD(Phalcon_Flash_Session, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session__getsessionmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session__setsessionmessages, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_has, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flash_session_output, 0, 0, 0)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flash_session_method_entry) {
	PHP_ME(Phalcon_Flash_Session, setDI, arginfo_phalcon_flash_session_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, _getSessionMessages, arginfo_phalcon_flash_session__getsessionmessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, _setSessionMessages, arginfo_phalcon_flash_session__setsessionmessages, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Flash_Session, message, arginfo_phalcon_flash_session_message, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, has, arginfo_phalcon_flash_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, getMessages, arginfo_phalcon_flash_session_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, output, arginfo_phalcon_flash_session_output, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Flash_Session, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_flashinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_FlashInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_success, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_flashinterface_message, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_flashinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, error, arginfo_phalcon_flashinterface_error)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, notice, arginfo_phalcon_flashinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, success, arginfo_phalcon_flashinterface_success)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, warning, arginfo_phalcon_flashinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_FlashInterface, message, arginfo_phalcon_flashinterface_message)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element);

static PHP_METHOD(Phalcon_Forms_Element, __construct);
static PHP_METHOD(Phalcon_Forms_Element, setForm);
static PHP_METHOD(Phalcon_Forms_Element, getForm);
static PHP_METHOD(Phalcon_Forms_Element, setName);
static PHP_METHOD(Phalcon_Forms_Element, getName);
static PHP_METHOD(Phalcon_Forms_Element, setFilters);
static PHP_METHOD(Phalcon_Forms_Element, addFilter);
static PHP_METHOD(Phalcon_Forms_Element, getFilters);
static PHP_METHOD(Phalcon_Forms_Element, addValidators);
static PHP_METHOD(Phalcon_Forms_Element, addValidator);
static PHP_METHOD(Phalcon_Forms_Element, getValidators);
static PHP_METHOD(Phalcon_Forms_Element, prepareAttributes);
static PHP_METHOD(Phalcon_Forms_Element, setAttribute);
static PHP_METHOD(Phalcon_Forms_Element, getAttribute);
static PHP_METHOD(Phalcon_Forms_Element, setAttributes);
static PHP_METHOD(Phalcon_Forms_Element, getAttributes);
static PHP_METHOD(Phalcon_Forms_Element, setUserOption);
static PHP_METHOD(Phalcon_Forms_Element, getUserOption);
static PHP_METHOD(Phalcon_Forms_Element, setUserOptions);
static PHP_METHOD(Phalcon_Forms_Element, getUserOptions);
static PHP_METHOD(Phalcon_Forms_Element, setLabel);
static PHP_METHOD(Phalcon_Forms_Element, getLabel);
static PHP_METHOD(Phalcon_Forms_Element, label);
static PHP_METHOD(Phalcon_Forms_Element, setDefault);
static PHP_METHOD(Phalcon_Forms_Element, getDefault);
static PHP_METHOD(Phalcon_Forms_Element, getValue);
static PHP_METHOD(Phalcon_Forms_Element, getMessages);
static PHP_METHOD(Phalcon_Forms_Element, hasMessages);
static PHP_METHOD(Phalcon_Forms_Element, setMessages);
static PHP_METHOD(Phalcon_Forms_Element, appendMessage);
static PHP_METHOD(Phalcon_Forms_Element, clear);
static PHP_METHOD(Phalcon_Forms_Element, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setform, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidators, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_addvalidator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_label, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_setmessages, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Validation\\Message\\Group, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_method_entry) {
	PHP_ME(Phalcon_Forms_Element, __construct, arginfo_phalcon_forms_element___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element, setForm, arginfo_phalcon_forms_element_setform, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getForm, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setName, arginfo_phalcon_forms_element_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setFilters, arginfo_phalcon_forms_element_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addFilter, arginfo_phalcon_forms_element_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidators, arginfo_phalcon_forms_element_addvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, addValidator, arginfo_phalcon_forms_element_addvalidator, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValidators, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, prepareAttributes, arginfo_phalcon_forms_element_prepareattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttribute, arginfo_phalcon_forms_element_setattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttribute, arginfo_phalcon_forms_element_getattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setAttributes, arginfo_phalcon_forms_element_setattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOption, arginfo_phalcon_forms_element_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOption, arginfo_phalcon_forms_element_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setUserOptions, arginfo_phalcon_forms_element_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getUserOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setLabel, arginfo_phalcon_forms_element_setlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getLabel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, label, arginfo_phalcon_forms_element_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setDefault, arginfo_phalcon_forms_element_setdefault, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getDefault, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, hasMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, setMessages, arginfo_phalcon_forms_element_setmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, appendMessage, arginfo_phalcon_forms_element_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_check_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Check);

static PHP_METHOD(Phalcon_Forms_Element_Check, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_check_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_check_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Check, render, arginfo_phalcon_forms_element_check_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_date_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Date);

static PHP_METHOD(Phalcon_Forms_Element_Date, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_date_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_date_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Date, render, arginfo_phalcon_forms_element_date_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_email_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Email);

static PHP_METHOD(Phalcon_Forms_Element_Email, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_email_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_email_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Email, render, arginfo_phalcon_forms_element_email_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_File);

static PHP_METHOD(Phalcon_Forms_Element_File, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_file_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_file_method_entry) {
	PHP_ME(Phalcon_Forms_Element_File, render, arginfo_phalcon_forms_element_file_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_hidden_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Hidden);

static PHP_METHOD(Phalcon_Forms_Element_Hidden, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_hidden_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_hidden_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Hidden, render, arginfo_phalcon_forms_element_hidden_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_numeric_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Numeric);

static PHP_METHOD(Phalcon_Forms_Element_Numeric, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_numeric_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_numeric_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Numeric, render, arginfo_phalcon_forms_element_numeric_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_password_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Password);

static PHP_METHOD(Phalcon_Forms_Element_Password, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_password_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_password_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Password, render, arginfo_phalcon_forms_element_password_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_radio_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Radio);

static PHP_METHOD(Phalcon_Forms_Element_Radio, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_radio_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_radio_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Radio, render, arginfo_phalcon_forms_element_radio_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select);

static PHP_METHOD(Phalcon_Forms_Element_Select, __construct);
static PHP_METHOD(Phalcon_Forms_Element_Select, setOptions);
static PHP_METHOD(Phalcon_Forms_Element_Select, getOptions);
static PHP_METHOD(Phalcon_Forms_Element_Select, addOption);
static PHP_METHOD(Phalcon_Forms_Element_Select, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_addoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_select_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_select_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Select, __construct, arginfo_phalcon_forms_element_select___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Element_Select, setOptions, arginfo_phalcon_forms_element_select_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, addOption, arginfo_phalcon_forms_element_select_addoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Element_Select, render, arginfo_phalcon_forms_element_select_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_submit_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Submit);

static PHP_METHOD(Phalcon_Forms_Element_Submit, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_submit_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_submit_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Submit, render, arginfo_phalcon_forms_element_submit_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_text_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Text);

static PHP_METHOD(Phalcon_Forms_Element_Text, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_text_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_text_method_entry) {
	PHP_ME(Phalcon_Forms_Element_Text, render, arginfo_phalcon_forms_element_text_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_element_textarea_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_TextArea);

static PHP_METHOD(Phalcon_Forms_Element_TextArea, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_element_textarea_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_element_textarea_method_entry) {
	PHP_ME(Phalcon_Forms_Element_TextArea, render, arginfo_phalcon_forms_element_textarea_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_elementinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_ElementInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setform, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setfilters, 0, 0, 1)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidators, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_addvalidator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_prepareattributes, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
	ZEND_ARG_INFO(0, useChecked)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setuseroptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setdefault, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_setmessages, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Validation\\Message\\Group, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_elementinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_elementinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setForm, arginfo_phalcon_forms_elementinterface_setform)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getForm, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setName, arginfo_phalcon_forms_elementinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setFilters, arginfo_phalcon_forms_elementinterface_setfilters)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addFilter, arginfo_phalcon_forms_elementinterface_addfilter)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getFilters, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidators, arginfo_phalcon_forms_elementinterface_addvalidators)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, addValidator, arginfo_phalcon_forms_elementinterface_addvalidator)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValidators, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, prepareAttributes, arginfo_phalcon_forms_elementinterface_prepareattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttribute, arginfo_phalcon_forms_elementinterface_setattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttribute, arginfo_phalcon_forms_elementinterface_getattribute)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setAttributes, arginfo_phalcon_forms_elementinterface_setattributes)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOption, arginfo_phalcon_forms_elementinterface_setuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOption, arginfo_phalcon_forms_elementinterface_getuseroption)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setUserOptions, arginfo_phalcon_forms_elementinterface_setuseroptions)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getUserOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setLabel, arginfo_phalcon_forms_elementinterface_setlabel)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getLabel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, label, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setDefault, arginfo_phalcon_forms_elementinterface_setdefault)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getDefault, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getValue, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, hasMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, setMessages, arginfo_phalcon_forms_elementinterface_setmessages)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, appendMessage, arginfo_phalcon_forms_elementinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Forms_ElementInterface, render, arginfo_phalcon_forms_elementinterface_render)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Exception);


zend_class_entry *phalcon_forms_form_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Form);

static PHP_METHOD(Phalcon_Forms_Form, setValidation);
static PHP_METHOD(Phalcon_Forms_Form, getValidation);
static PHP_METHOD(Phalcon_Forms_Form, __construct);
static PHP_METHOD(Phalcon_Forms_Form, setAction);
static PHP_METHOD(Phalcon_Forms_Form, getAction);
static PHP_METHOD(Phalcon_Forms_Form, setUserOption);
static PHP_METHOD(Phalcon_Forms_Form, getUserOption);
static PHP_METHOD(Phalcon_Forms_Form, setUserOptions);
static PHP_METHOD(Phalcon_Forms_Form, getUserOptions);
static PHP_METHOD(Phalcon_Forms_Form, setEntity);
static PHP_METHOD(Phalcon_Forms_Form, getEntity);
static PHP_METHOD(Phalcon_Forms_Form, getElements);
static PHP_METHOD(Phalcon_Forms_Form, bind);
static PHP_METHOD(Phalcon_Forms_Form, isValid);
static PHP_METHOD(Phalcon_Forms_Form, getMessages);
static PHP_METHOD(Phalcon_Forms_Form, getMessagesFor);
static PHP_METHOD(Phalcon_Forms_Form, hasMessagesFor);
static PHP_METHOD(Phalcon_Forms_Form, add);
static PHP_METHOD(Phalcon_Forms_Form, render);
static PHP_METHOD(Phalcon_Forms_Form, get);
static PHP_METHOD(Phalcon_Forms_Form, label);
static PHP_METHOD(Phalcon_Forms_Form, getLabel);
static PHP_METHOD(Phalcon_Forms_Form, getValue);
static PHP_METHOD(Phalcon_Forms_Form, has);
static PHP_METHOD(Phalcon_Forms_Form, remove);
static PHP_METHOD(Phalcon_Forms_Form, clear);
static PHP_METHOD(Phalcon_Forms_Form, count);
static PHP_METHOD(Phalcon_Forms_Form, rewind);
static PHP_METHOD(Phalcon_Forms_Form, current);
static PHP_METHOD(Phalcon_Forms_Form, key);
static PHP_METHOD(Phalcon_Forms_Form, next);
static PHP_METHOD(Phalcon_Forms_Form, valid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setvalidation, 0, 0, 1)
	ZEND_ARG_INFO(0, validation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, userOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setaction, 0, 0, 1)
	ZEND_ARG_INFO(0, action)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getuseroption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setuseroptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_setentity, 0, 0, 1)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_bind, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, whitelist)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_isvalid, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, byItemName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_hasmessagesfor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_add, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, element, Phalcon\\Forms\\ElementInterface, 0)
	ZEND_ARG_INFO(0, postion)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_render, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, attributes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_label, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, attributes, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_form_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_form_method_entry) {
	PHP_ME(Phalcon_Forms_Form, setValidation, arginfo_phalcon_forms_form_setvalidation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getValidation, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, __construct, arginfo_phalcon_forms_form___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Forms_Form, setAction, arginfo_phalcon_forms_form_setaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOption, arginfo_phalcon_forms_form_setuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOption, arginfo_phalcon_forms_form_getuseroption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setUserOptions, arginfo_phalcon_forms_form_setuseroptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getUserOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, setEntity, arginfo_phalcon_forms_form_setentity, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getElements, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, bind, arginfo_phalcon_forms_form_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, isValid, arginfo_phalcon_forms_form_isvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessages, arginfo_phalcon_forms_form_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getMessagesFor, arginfo_phalcon_forms_form_getmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, hasMessagesFor, arginfo_phalcon_forms_form_hasmessagesfor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, add, arginfo_phalcon_forms_form_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, render, arginfo_phalcon_forms_form_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, get, arginfo_phalcon_forms_form_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, label, arginfo_phalcon_forms_form_label, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getLabel, arginfo_phalcon_forms_form_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, getValue, arginfo_phalcon_forms_form_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, has, arginfo_phalcon_forms_form_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, remove, arginfo_phalcon_forms_form_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, clear, arginfo_phalcon_forms_form_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Form, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_forms_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Forms_Manager);

static PHP_METHOD(Phalcon_Forms_Manager, create);
static PHP_METHOD(Phalcon_Forms_Manager, get);
static PHP_METHOD(Phalcon_Forms_Manager, has);
static PHP_METHOD(Phalcon_Forms_Manager, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_create, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_forms_manager_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, form, Phalcon\\Forms\\Form, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_forms_manager_method_entry) {
	PHP_ME(Phalcon_Forms_Manager, create, arginfo_phalcon_forms_manager_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, get, arginfo_phalcon_forms_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, has, arginfo_phalcon_forms_manager_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Forms_Manager, set, arginfo_phalcon_forms_manager_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_cookie_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie);

static PHP_METHOD(Phalcon_Http_Cookie, __construct);
static PHP_METHOD(Phalcon_Http_Cookie, setDI);
static PHP_METHOD(Phalcon_Http_Cookie, getDI);
static PHP_METHOD(Phalcon_Http_Cookie, setValue);
static PHP_METHOD(Phalcon_Http_Cookie, getValue);
static PHP_METHOD(Phalcon_Http_Cookie, send);
static PHP_METHOD(Phalcon_Http_Cookie, restore);
static PHP_METHOD(Phalcon_Http_Cookie, delete);
static PHP_METHOD(Phalcon_Http_Cookie, useEncryption);
static PHP_METHOD(Phalcon_Http_Cookie, isUsingEncryption);
static PHP_METHOD(Phalcon_Http_Cookie, setExpiration);
static PHP_METHOD(Phalcon_Http_Cookie, getExpiration);
static PHP_METHOD(Phalcon_Http_Cookie, setPath);
static PHP_METHOD(Phalcon_Http_Cookie, getName);
static PHP_METHOD(Phalcon_Http_Cookie, getPath);
static PHP_METHOD(Phalcon_Http_Cookie, setDomain);
static PHP_METHOD(Phalcon_Http_Cookie, getDomain);
static PHP_METHOD(Phalcon_Http_Cookie, setSecure);
static PHP_METHOD(Phalcon_Http_Cookie, getSecure);
static PHP_METHOD(Phalcon_Http_Cookie, setHttpOnly);
static PHP_METHOD(Phalcon_Http_Cookie, getHttpOnly);
static PHP_METHOD(Phalcon_Http_Cookie, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setexpiration, 0, 0, 1)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_setsecure, 0, 0, 1)
	ZEND_ARG_INFO(0, secure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_cookie_sethttponly, 0, 0, 1)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_cookie_method_entry) {
	PHP_ME(Phalcon_Http_Cookie, __construct, arginfo_phalcon_http_cookie___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Cookie, setDI, arginfo_phalcon_http_cookie_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setValue, arginfo_phalcon_http_cookie_setvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getValue, arginfo_phalcon_http_cookie_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, restore, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, useEncryption, arginfo_phalcon_http_cookie_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, isUsingEncryption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setExpiration, arginfo_phalcon_http_cookie_setexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getExpiration, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setPath, arginfo_phalcon_http_cookie_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setDomain, arginfo_phalcon_http_cookie_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setSecure, arginfo_phalcon_http_cookie_setsecure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getSecure, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, setHttpOnly, arginfo_phalcon_http_cookie_sethttponly, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, getHttpOnly, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Cookie, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_cookie_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Cookie_Exception);


zend_class_entry *phalcon_http_request_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request);

static PHP_METHOD(Phalcon_Http_Request, setDI);
static PHP_METHOD(Phalcon_Http_Request, getDI);
static PHP_METHOD(Phalcon_Http_Request, get);
static PHP_METHOD(Phalcon_Http_Request, getPost);
static PHP_METHOD(Phalcon_Http_Request, getPut);
static PHP_METHOD(Phalcon_Http_Request, getQuery);
static PHP_METHOD(Phalcon_Http_Request, getHelper);
static PHP_METHOD(Phalcon_Http_Request, getServer);
static PHP_METHOD(Phalcon_Http_Request, has);
static PHP_METHOD(Phalcon_Http_Request, hasPost);
static PHP_METHOD(Phalcon_Http_Request, hasPut);
static PHP_METHOD(Phalcon_Http_Request, hasQuery);
static PHP_METHOD(Phalcon_Http_Request, hasServer);
static PHP_METHOD(Phalcon_Http_Request, getHeader);
static PHP_METHOD(Phalcon_Http_Request, getScheme);
static PHP_METHOD(Phalcon_Http_Request, isAjax);
static PHP_METHOD(Phalcon_Http_Request, isSoapRequested);
static PHP_METHOD(Phalcon_Http_Request, isSecureRequest);
static PHP_METHOD(Phalcon_Http_Request, getRawBody);
static PHP_METHOD(Phalcon_Http_Request, getJsonRawBody);
static PHP_METHOD(Phalcon_Http_Request, getServerAddress);
static PHP_METHOD(Phalcon_Http_Request, getServerName);
static PHP_METHOD(Phalcon_Http_Request, getHttpHost);
static PHP_METHOD(Phalcon_Http_Request, getURI);
static PHP_METHOD(Phalcon_Http_Request, getClientAddress);
static PHP_METHOD(Phalcon_Http_Request, getMethod);
static PHP_METHOD(Phalcon_Http_Request, getUserAgent);
static PHP_METHOD(Phalcon_Http_Request, isMethod);
static PHP_METHOD(Phalcon_Http_Request, isPost);
static PHP_METHOD(Phalcon_Http_Request, isGet);
static PHP_METHOD(Phalcon_Http_Request, isPut);
static PHP_METHOD(Phalcon_Http_Request, isPatch);
static PHP_METHOD(Phalcon_Http_Request, isHead);
static PHP_METHOD(Phalcon_Http_Request, isDelete);
static PHP_METHOD(Phalcon_Http_Request, isOptions);
static PHP_METHOD(Phalcon_Http_Request, hasFiles);
static PHP_METHOD(Phalcon_Http_Request, hasFileHelper);
static PHP_METHOD(Phalcon_Http_Request, getUploadedFiles);
static PHP_METHOD(Phalcon_Http_Request, smoothFiles);
static PHP_METHOD(Phalcon_Http_Request, getHeaders);
static PHP_METHOD(Phalcon_Http_Request, getHTTPReferer);
static PHP_METHOD(Phalcon_Http_Request, _getQualityHeader);
static PHP_METHOD(Phalcon_Http_Request, _getBestQuality);
static PHP_METHOD(Phalcon_Http_Request, getContentType);
static PHP_METHOD(Phalcon_Http_Request, getAcceptableContent);
static PHP_METHOD(Phalcon_Http_Request, getBestAccept);
static PHP_METHOD(Phalcon_Http_Request, getClientCharsets);
static PHP_METHOD(Phalcon_Http_Request, getBestCharset);
static PHP_METHOD(Phalcon_Http_Request, getLanguages);
static PHP_METHOD(Phalcon_Http_Request, getBestLanguage);
static PHP_METHOD(Phalcon_Http_Request, getBasicAuth);
static PHP_METHOD(Phalcon_Http_Request, getDigestAuth);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, notAllowEmpty)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, notAllowEmpty)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getput, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, notAllowEmpty)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, notAllowEmpty)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_gethelper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, notAllowEmpty)
	ZEND_ARG_INFO(0, noRecursive)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasput, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getjsonrawbody, 0, 0, 0)
	ZEND_ARG_INFO(0, associative)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_hasfilehelper, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_smoothfiles, 0, 0, 6)
	ZEND_ARG_ARRAY_INFO(0, names, 0)
	ZEND_ARG_ARRAY_INFO(0, types, 0)
	ZEND_ARG_ARRAY_INFO(0, tmp_names, 0)
	ZEND_ARG_ARRAY_INFO(0, sizes, 0)
	ZEND_ARG_ARRAY_INFO(0, errors, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request__getqualityheader, 0, 0, 2)
	ZEND_ARG_INFO(0, serverIndex)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request__getbestquality, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, qualityParts, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_method_entry) {
	PHP_ME(Phalcon_Http_Request, setDI, arginfo_phalcon_http_request_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, get, arginfo_phalcon_http_request_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPost, arginfo_phalcon_http_request_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getPut, arginfo_phalcon_http_request_getput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getQuery, arginfo_phalcon_http_request_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHelper, arginfo_phalcon_http_request_gethelper, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getServer, arginfo_phalcon_http_request_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, has, arginfo_phalcon_http_request_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPost, arginfo_phalcon_http_request_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasPut, arginfo_phalcon_http_request_hasput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasQuery, arginfo_phalcon_http_request_hasquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasServer, arginfo_phalcon_http_request_hasserver, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getHeader, arginfo_phalcon_http_request_getheader, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getScheme, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isAjax, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSoapRequested, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isSecureRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getRawBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getJsonRawBody, arginfo_phalcon_http_request_getjsonrawbody, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerAddress, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getServerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHttpHost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getURI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getClientAddress, arginfo_phalcon_http_request_getclientaddress, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getMethod, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getUserAgent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isMethod, arginfo_phalcon_http_request_ismethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPost, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isGet, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPut, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isPatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isHead, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isDelete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, isOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasFiles, arginfo_phalcon_http_request_hasfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, hasFileHelper, arginfo_phalcon_http_request_hasfilehelper, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getUploadedFiles, arginfo_phalcon_http_request_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, smoothFiles, arginfo_phalcon_http_request_smoothfiles, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getHTTPReferer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, _getQualityHeader, arginfo_phalcon_http_request__getqualityheader, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, _getBestQuality, arginfo_phalcon_http_request__getbestquality, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Http_Request, getContentType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getAcceptableContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestAccept, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getClientCharsets, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getLanguages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBestLanguage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getBasicAuth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request, getDigestAuth, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_request_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_Exception);


zend_class_entry *phalcon_http_request_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_File);

static PHP_METHOD(Phalcon_Http_Request_File, getError);
static PHP_METHOD(Phalcon_Http_Request_File, getKey);
static PHP_METHOD(Phalcon_Http_Request_File, getExtension);
static PHP_METHOD(Phalcon_Http_Request_File, __construct);
static PHP_METHOD(Phalcon_Http_Request_File, getSize);
static PHP_METHOD(Phalcon_Http_Request_File, getName);
static PHP_METHOD(Phalcon_Http_Request_File, getTempName);
static PHP_METHOD(Phalcon_Http_Request_File, getType);
static PHP_METHOD(Phalcon_Http_Request_File, getRealType);
static PHP_METHOD(Phalcon_Http_Request_File, isUploadedFile);
static PHP_METHOD(Phalcon_Http_Request_File, moveTo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, file, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_file_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_file_method_entry) {
	PHP_ME(Phalcon_Http_Request_File, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, __construct, arginfo_phalcon_http_request_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Request_File, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getTempName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, getRealType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, isUploadedFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Request_File, moveTo, arginfo_phalcon_http_request_file_moveto, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_request_fileinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Request_FileInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, file, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_request_fileinterface_moveto, 0, 0, 1)
	ZEND_ARG_INFO(0, destination)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_request_fileinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, __construct, arginfo_phalcon_http_request_fileinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getSize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getTempName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, getRealType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Request_FileInterface, moveTo, arginfo_phalcon_http_request_fileinterface_moveto)
	PHP_FE_END
};

zend_class_entry *phalcon_http_requestinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_RequestInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getpost, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getquery, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_haspost, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasput, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasquery, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getclientaddress, 0, 0, 0)
	ZEND_ARG_INFO(0, trustForwardedHeader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_ismethod, 0, 0, 1)
	ZEND_ARG_INFO(0, methods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_hasfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_requestinterface_getuploadedfiles, 0, 0, 0)
	ZEND_ARG_INFO(0, onlySuccessful)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_requestinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, get, arginfo_phalcon_http_requestinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getPost, arginfo_phalcon_http_requestinterface_getpost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getQuery, arginfo_phalcon_http_requestinterface_getquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServer, arginfo_phalcon_http_requestinterface_getserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, has, arginfo_phalcon_http_requestinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPost, arginfo_phalcon_http_requestinterface_haspost)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasPut, arginfo_phalcon_http_requestinterface_hasput)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasQuery, arginfo_phalcon_http_requestinterface_hasquery)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasServer, arginfo_phalcon_http_requestinterface_hasserver)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHeader, arginfo_phalcon_http_requestinterface_getheader)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getScheme, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isAjax, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSoapRequested, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isSecureRequest, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getRawBody, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerAddress, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getServerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHttpHost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientAddress, arginfo_phalcon_http_requestinterface_getclientaddress)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getMethod, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUserAgent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isMethod, arginfo_phalcon_http_requestinterface_ismethod)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPost, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isGet, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isPut, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isHead, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isDelete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, isOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, hasFiles, arginfo_phalcon_http_requestinterface_hasfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getUploadedFiles, arginfo_phalcon_http_requestinterface_getuploadedfiles)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getHTTPReferer, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getAcceptableContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestAccept, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getClientCharsets, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestCharset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getLanguages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBestLanguage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getBasicAuth, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_RequestInterface, getDigestAuth, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_http_response_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response);

static PHP_METHOD(Phalcon_Http_Response, __construct);
static PHP_METHOD(Phalcon_Http_Response, setDI);
static PHP_METHOD(Phalcon_Http_Response, getDI);
static PHP_METHOD(Phalcon_Http_Response, setStatusCode);
static PHP_METHOD(Phalcon_Http_Response, getStatusCode);
static PHP_METHOD(Phalcon_Http_Response, setHeaders);
static PHP_METHOD(Phalcon_Http_Response, getHeaders);
static PHP_METHOD(Phalcon_Http_Response, setCookies);
static PHP_METHOD(Phalcon_Http_Response, getCookies);
static PHP_METHOD(Phalcon_Http_Response, setHeader);
static PHP_METHOD(Phalcon_Http_Response, setRawHeader);
static PHP_METHOD(Phalcon_Http_Response, resetHeaders);
static PHP_METHOD(Phalcon_Http_Response, setExpires);
static PHP_METHOD(Phalcon_Http_Response, setNotModified);
static PHP_METHOD(Phalcon_Http_Response, setContentType);
static PHP_METHOD(Phalcon_Http_Response, setEtag);
static PHP_METHOD(Phalcon_Http_Response, redirect);
static PHP_METHOD(Phalcon_Http_Response, setContent);
static PHP_METHOD(Phalcon_Http_Response, setJsonContent);
static PHP_METHOD(Phalcon_Http_Response, appendContent);
static PHP_METHOD(Phalcon_Http_Response, getContent);
static PHP_METHOD(Phalcon_Http_Response, isSent);
static PHP_METHOD(Phalcon_Http_Response, sendHeaders);
static PHP_METHOD(Phalcon_Http_Response, sendCookies);
static PHP_METHOD(Phalcon_Http_Response, send);
static PHP_METHOD(Phalcon_Http_Response, setFileToSend);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheaders, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Http\\Response\\HeadersInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcookies, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cookies, Phalcon\\Http\\Response\\CookiesInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setexpires, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setetag, 0, 0, 1)
	ZEND_ARG_INFO(0, etag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, jsonOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_setfiletosend, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, attachmentName)
	ZEND_ARG_INFO(0, attachment)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_method_entry) {
	PHP_ME(Phalcon_Http_Response, __construct, arginfo_phalcon_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_Response, setDI, arginfo_phalcon_http_response_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setStatusCode, arginfo_phalcon_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeaders, arginfo_phalcon_http_response_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setCookies, arginfo_phalcon_http_response_setcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setHeader, arginfo_phalcon_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setRawHeader, arginfo_phalcon_http_response_setrawheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, resetHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setExpires, arginfo_phalcon_http_response_setexpires, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setNotModified, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContentType, arginfo_phalcon_http_response_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setEtag, arginfo_phalcon_http_response_setetag, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, redirect, arginfo_phalcon_http_response_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setContent, arginfo_phalcon_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setJsonContent, arginfo_phalcon_http_response_setjsoncontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, appendContent, arginfo_phalcon_http_response_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, isSent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, sendCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response, setFileToSend, arginfo_phalcon_http_response_setfiletosend, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_response_cookies_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Cookies);

static PHP_METHOD(Phalcon_Http_Response_Cookies, setDI);
static PHP_METHOD(Phalcon_Http_Response_Cookies, getDI);
static PHP_METHOD(Phalcon_Http_Response_Cookies, useEncryption);
static PHP_METHOD(Phalcon_Http_Response_Cookies, isUsingEncryption);
static PHP_METHOD(Phalcon_Http_Response_Cookies, set);
static PHP_METHOD(Phalcon_Http_Response_Cookies, get);
static PHP_METHOD(Phalcon_Http_Response_Cookies, has);
static PHP_METHOD(Phalcon_Http_Response_Cookies, delete);
static PHP_METHOD(Phalcon_Http_Response_Cookies, send);
static PHP_METHOD(Phalcon_Http_Response_Cookies, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookies_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_cookies_method_entry) {
	PHP_ME(Phalcon_Http_Response_Cookies, setDI, arginfo_phalcon_http_response_cookies_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, useEncryption, arginfo_phalcon_http_response_cookies_useencryption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, isUsingEncryption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, set, arginfo_phalcon_http_response_cookies_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, get, arginfo_phalcon_http_response_cookies_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, has, arginfo_phalcon_http_response_cookies_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, delete, arginfo_phalcon_http_response_cookies_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Cookies, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_response_cookiesinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_CookiesInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_useencryption, 0, 0, 1)
	ZEND_ARG_INFO(0, useEncryption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, secure)
	ZEND_ARG_INFO(0, domain)
	ZEND_ARG_INFO(0, httpOnly)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_cookiesinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_cookiesinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, useEncryption, arginfo_phalcon_http_response_cookiesinterface_useencryption)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, isUsingEncryption, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, set, arginfo_phalcon_http_response_cookiesinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, get, arginfo_phalcon_http_response_cookiesinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, has, arginfo_phalcon_http_response_cookiesinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, delete, arginfo_phalcon_http_response_cookiesinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_CookiesInterface, reset, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_http_response_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Exception);


zend_class_entry *phalcon_http_response_headers_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_Headers);

static PHP_METHOD(Phalcon_Http_Response_Headers, set);
static PHP_METHOD(Phalcon_Http_Response_Headers, get);
static PHP_METHOD(Phalcon_Http_Response_Headers, setRaw);
static PHP_METHOD(Phalcon_Http_Response_Headers, remove);
static PHP_METHOD(Phalcon_Http_Response_Headers, send);
static PHP_METHOD(Phalcon_Http_Response_Headers, reset);
static PHP_METHOD(Phalcon_Http_Response_Headers, toArray);
static PHP_METHOD(Phalcon_Http_Response_Headers, __set_state);
static PHP_METHOD(Phalcon_Http_Response_Headers, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headers___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_headers_method_entry) {
	PHP_ME(Phalcon_Http_Response_Headers, set, arginfo_phalcon_http_response_headers_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, get, arginfo_phalcon_http_response_headers_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, setRaw, arginfo_phalcon_http_response_headers_setraw, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, remove, arginfo_phalcon_http_response_headers_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_Response_Headers, __set_state, arginfo_phalcon_http_response_headers___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Http_Response_Headers, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_http_response_headersinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_Response_HeadersInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface_setraw, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_response_headersinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_response_headersinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, set, arginfo_phalcon_http_response_headersinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, get, arginfo_phalcon_http_response_headersinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, setRaw, arginfo_phalcon_http_response_headersinterface_setraw)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_Response_HeadersInterface, reset, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_http_response_headersinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_http_responseinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_ResponseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setrawheader, 0, 0, 1)
	ZEND_ARG_INFO(0, header)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setexpires, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_redirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, externalRedirect)
	ZEND_ARG_INFO(0, statusCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setjsoncontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_appendcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_responseinterface_setfiletosend, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
	ZEND_ARG_INFO(0, attachmentName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_responseinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setStatusCode, arginfo_phalcon_http_responseinterface_setstatuscode)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setHeader, arginfo_phalcon_http_responseinterface_setheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setRawHeader, arginfo_phalcon_http_responseinterface_setrawheader)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, resetHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setExpires, arginfo_phalcon_http_responseinterface_setexpires)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setNotModified, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContentType, arginfo_phalcon_http_responseinterface_setcontenttype)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, redirect, arginfo_phalcon_http_responseinterface_redirect)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setContent, arginfo_phalcon_http_responseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setJsonContent, arginfo_phalcon_http_responseinterface_setjsoncontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, appendContent, arginfo_phalcon_http_responseinterface_appendcontent)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendHeaders, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, sendCookies, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, send, NULL)
	PHP_ABSTRACT_ME(Phalcon_Http_ResponseInterface, setFileToSend, arginfo_phalcon_http_responseinterface_setfiletosend)
	PHP_FE_END
};

zend_class_entry *phalcon_image_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image);


zend_class_entry *phalcon_image_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter);

static PHP_METHOD(Phalcon_Image_Adapter, getImage);
static PHP_METHOD(Phalcon_Image_Adapter, getRealpath);
static PHP_METHOD(Phalcon_Image_Adapter, getWidth);
static PHP_METHOD(Phalcon_Image_Adapter, getHeight);
static PHP_METHOD(Phalcon_Image_Adapter, getType);
static PHP_METHOD(Phalcon_Image_Adapter, getMime);
static PHP_METHOD(Phalcon_Image_Adapter, resize);
static PHP_METHOD(Phalcon_Image_Adapter, liquidRescale);
static PHP_METHOD(Phalcon_Image_Adapter, crop);
static PHP_METHOD(Phalcon_Image_Adapter, rotate);
static PHP_METHOD(Phalcon_Image_Adapter, flip);
static PHP_METHOD(Phalcon_Image_Adapter, sharpen);
static PHP_METHOD(Phalcon_Image_Adapter, reflection);
static PHP_METHOD(Phalcon_Image_Adapter, watermark);
static PHP_METHOD(Phalcon_Image_Adapter, text);
static PHP_METHOD(Phalcon_Image_Adapter, mask);
static PHP_METHOD(Phalcon_Image_Adapter, background);
static PHP_METHOD(Phalcon_Image_Adapter, blur);
static PHP_METHOD(Phalcon_Image_Adapter, pixelate);
static PHP_METHOD(Phalcon_Image_Adapter, save);
static PHP_METHOD(Phalcon_Image_Adapter, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_liquidrescale, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, deltaX)
	ZEND_ARG_INFO(0, rigidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_reflection, 0, 0, 1)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_watermark, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_render, 0, 0, 0)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_method_entry) {
	PHP_ME(Phalcon_Image_Adapter, getImage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getRealpath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getWidth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getHeight, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, getMime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, resize, arginfo_phalcon_image_adapter_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, liquidRescale, arginfo_phalcon_image_adapter_liquidrescale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, crop, arginfo_phalcon_image_adapter_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, rotate, arginfo_phalcon_image_adapter_rotate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, flip, arginfo_phalcon_image_adapter_flip, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, sharpen, arginfo_phalcon_image_adapter_sharpen, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, reflection, arginfo_phalcon_image_adapter_reflection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, watermark, arginfo_phalcon_image_adapter_watermark, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, text, arginfo_phalcon_image_adapter_text, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, mask, arginfo_phalcon_image_adapter_mask, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, background, arginfo_phalcon_image_adapter_background, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, blur, arginfo_phalcon_image_adapter_blur, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, pixelate, arginfo_phalcon_image_adapter_pixelate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, save, arginfo_phalcon_image_adapter_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter, render, arginfo_phalcon_image_adapter_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_image_adapter_gd_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Gd);

static PHP_METHOD(Phalcon_Image_Adapter_Gd, check);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, __construct);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _resize);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _crop);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _rotate);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _flip);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _sharpen);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _reflection);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _watermark);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _text);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _mask);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _background);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _blur);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _pixelate);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _save);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _render);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, _create);
static PHP_METHOD(Phalcon_Image_Adapter_Gd, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__reflection, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__watermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__text, 0, 0, 9)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mask, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__render, 0, 0, 2)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_gd__create, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_gd_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Gd, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Gd, __construct, arginfo_phalcon_image_adapter_gd___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_Gd, _resize, arginfo_phalcon_image_adapter_gd__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _crop, arginfo_phalcon_image_adapter_gd__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _rotate, arginfo_phalcon_image_adapter_gd__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _flip, arginfo_phalcon_image_adapter_gd__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _sharpen, arginfo_phalcon_image_adapter_gd__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _reflection, arginfo_phalcon_image_adapter_gd__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _watermark, arginfo_phalcon_image_adapter_gd__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _text, arginfo_phalcon_image_adapter_gd__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _mask, arginfo_phalcon_image_adapter_gd__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _background, arginfo_phalcon_image_adapter_gd__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _blur, arginfo_phalcon_image_adapter_gd__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _pixelate, arginfo_phalcon_image_adapter_gd__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _save, arginfo_phalcon_image_adapter_gd__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _render, arginfo_phalcon_image_adapter_gd__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, _create, arginfo_phalcon_image_adapter_gd__create, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Gd, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_image_adapter_imagick_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Adapter_Imagick);

static PHP_METHOD(Phalcon_Image_Adapter_Imagick, check);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, __construct);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _resize);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _liquidRescale);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _crop);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _rotate);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _flip);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _sharpen);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _reflection);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _watermark);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _text);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _mask);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _background);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _blur);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _pixelate);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _save);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, _render);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, __destruct);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, getInternalImInstance);
static PHP_METHOD(Phalcon_Image_Adapter_Imagick, setResourceLimit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__resize, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__liquidrescale, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, deltaX)
	ZEND_ARG_INFO(0, rigidity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__crop, 0, 0, 4)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__reflection, 0, 0, 3)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__watermark, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__text, 0, 0, 9)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, image, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__background, 0, 0, 4)
	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, g)
	ZEND_ARG_INFO(0, b)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__save, 0, 0, 2)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick__render, 0, 0, 2)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapter_imagick_setresourcelimit, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapter_imagick_method_entry) {
	PHP_ME(Phalcon_Image_Adapter_Imagick, check, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __construct, arginfo_phalcon_image_adapter_imagick___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _resize, arginfo_phalcon_image_adapter_imagick__resize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _liquidRescale, arginfo_phalcon_image_adapter_imagick__liquidrescale, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _crop, arginfo_phalcon_image_adapter_imagick__crop, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _rotate, arginfo_phalcon_image_adapter_imagick__rotate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _flip, arginfo_phalcon_image_adapter_imagick__flip, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _sharpen, arginfo_phalcon_image_adapter_imagick__sharpen, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _reflection, arginfo_phalcon_image_adapter_imagick__reflection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _watermark, arginfo_phalcon_image_adapter_imagick__watermark, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _text, arginfo_phalcon_image_adapter_imagick__text, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _mask, arginfo_phalcon_image_adapter_imagick__mask, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _background, arginfo_phalcon_image_adapter_imagick__background, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _blur, arginfo_phalcon_image_adapter_imagick__blur, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _pixelate, arginfo_phalcon_image_adapter_imagick__pixelate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _save, arginfo_phalcon_image_adapter_imagick__save, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, _render, arginfo_phalcon_image_adapter_imagick__render, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Image_Adapter_Imagick, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Phalcon_Image_Adapter_Imagick, getInternalImInstance, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Image_Adapter_Imagick, setResourceLimit, arginfo_phalcon_image_adapter_imagick_setresourcelimit, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_image_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_resize, 0, 0, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, master)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_crop, 0, 0, 2)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_rotate, 0, 0, 1)
	ZEND_ARG_INFO(0, degrees)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_flip, 0, 0, 1)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_sharpen, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_reflection, 0, 0, 1)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, fadeIn)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_watermark, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_text, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, offsetX)
	ZEND_ARG_INFO(0, offsetY)
	ZEND_ARG_INFO(0, opacity)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, size)
	ZEND_ARG_INFO(0, fontfile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_mask, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, watermark, Phalcon\\Image\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_background, 0, 0, 1)
	ZEND_ARG_INFO(0, color)
	ZEND_ARG_INFO(0, opacity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_blur, 0, 0, 1)
	ZEND_ARG_INFO(0, radius)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_pixelate, 0, 0, 1)
	ZEND_ARG_INFO(0, amount)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_image_adapterinterface_render, 0, 0, 0)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, quality)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_image_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, resize, arginfo_phalcon_image_adapterinterface_resize)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, crop, arginfo_phalcon_image_adapterinterface_crop)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, rotate, arginfo_phalcon_image_adapterinterface_rotate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, flip, arginfo_phalcon_image_adapterinterface_flip)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, sharpen, arginfo_phalcon_image_adapterinterface_sharpen)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, reflection, arginfo_phalcon_image_adapterinterface_reflection)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, watermark, arginfo_phalcon_image_adapterinterface_watermark)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, text, arginfo_phalcon_image_adapterinterface_text)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, mask, arginfo_phalcon_image_adapterinterface_mask)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, background, arginfo_phalcon_image_adapterinterface_background)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, blur, arginfo_phalcon_image_adapterinterface_blur)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, pixelate, arginfo_phalcon_image_adapterinterface_pixelate)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, save, arginfo_phalcon_image_adapterinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Image_AdapterInterface, render, arginfo_phalcon_image_adapterinterface_render)
	PHP_FE_END
};

zend_class_entry *phalcon_image_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Image_Exception);


zend_class_entry *phalcon_kernel_ce;

ZEPHIR_INIT_CLASS(Phalcon_Kernel);

static PHP_METHOD(Phalcon_Kernel, preComputeHashKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_kernel_precomputehashkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_kernel_method_entry) {
	PHP_ME(Phalcon_Kernel, preComputeHashKey, arginfo_phalcon_kernel_precomputehashkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Loader);

static PHP_METHOD(Phalcon_Loader, __construct);
static PHP_METHOD(Phalcon_Loader, setEventsManager);
static PHP_METHOD(Phalcon_Loader, getEventsManager);
static PHP_METHOD(Phalcon_Loader, setExtensions);
static PHP_METHOD(Phalcon_Loader, getExtensions);
static PHP_METHOD(Phalcon_Loader, registerNamespaces);
static PHP_METHOD(Phalcon_Loader, getNamespaces);
static PHP_METHOD(Phalcon_Loader, registerPrefixes);
static PHP_METHOD(Phalcon_Loader, getPrefixes);
static PHP_METHOD(Phalcon_Loader, registerDirs);
static PHP_METHOD(Phalcon_Loader, getDirs);
static PHP_METHOD(Phalcon_Loader, registerClasses);
static PHP_METHOD(Phalcon_Loader, getClasses);
static PHP_METHOD(Phalcon_Loader, register);
static PHP_METHOD(Phalcon_Loader, unregister);
static PHP_METHOD(Phalcon_Loader, autoLoad);
static PHP_METHOD(Phalcon_Loader, getFoundPath);
static PHP_METHOD(Phalcon_Loader, getCheckedPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_setextensions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, extensions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registernamespaces, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaces, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerprefixes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, prefixes, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerdirs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, directories, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_registerclasses, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classes, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_loader_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_loader_method_entry) {
	PHP_ME(Phalcon_Loader, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Loader, setEventsManager, arginfo_phalcon_loader_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, setExtensions, arginfo_phalcon_loader_setextensions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getExtensions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerNamespaces, arginfo_phalcon_loader_registernamespaces, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getNamespaces, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerPrefixes, arginfo_phalcon_loader_registerprefixes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getPrefixes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerDirs, arginfo_phalcon_loader_registerdirs, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getDirs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, registerClasses, arginfo_phalcon_loader_registerclasses, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getClasses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, autoLoad, arginfo_phalcon_loader_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getFoundPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Loader, getCheckedPath, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_loader_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Loader_Exception);


zend_class_entry *phalcon_logger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger);


zend_class_entry *phalcon_logger_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter);

static PHP_METHOD(Phalcon_Logger_Adapter, setLogLevel);
static PHP_METHOD(Phalcon_Logger_Adapter, getLogLevel);
static PHP_METHOD(Phalcon_Logger_Adapter, setFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter, begin);
static PHP_METHOD(Phalcon_Logger_Adapter, commit);
static PHP_METHOD(Phalcon_Logger_Adapter, rollback);
static PHP_METHOD(Phalcon_Logger_Adapter, critical);
static PHP_METHOD(Phalcon_Logger_Adapter, emergency);
static PHP_METHOD(Phalcon_Logger_Adapter, debug);
static PHP_METHOD(Phalcon_Logger_Adapter, error);
static PHP_METHOD(Phalcon_Logger_Adapter, info);
static PHP_METHOD(Phalcon_Logger_Adapter, notice);
static PHP_METHOD(Phalcon_Logger_Adapter, warning);
static PHP_METHOD(Phalcon_Logger_Adapter, alert);
static PHP_METHOD(Phalcon_Logger_Adapter, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_setformatter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_log, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter, setLogLevel, arginfo_phalcon_logger_adapter_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, getLogLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, setFormatter, arginfo_phalcon_logger_adapter_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, critical, arginfo_phalcon_logger_adapter_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, emergency, arginfo_phalcon_logger_adapter_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, debug, arginfo_phalcon_logger_adapter_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, error, arginfo_phalcon_logger_adapter_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, info, arginfo_phalcon_logger_adapter_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, notice, arginfo_phalcon_logger_adapter_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, warning, arginfo_phalcon_logger_adapter_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, alert, arginfo_phalcon_logger_adapter_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter, log, arginfo_phalcon_logger_adapter_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_adapter_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_File);

static PHP_METHOD(Phalcon_Logger_Adapter_File, getPath);
static PHP_METHOD(Phalcon_Logger_Adapter_File, __construct);
static PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal);
static PHP_METHOD(Phalcon_Logger_Adapter_File, close);
static PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_file_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_File, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_File, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, logInternal, arginfo_phalcon_logger_adapter_file_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_adapter_firephp_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Firephp);

static PHP_METHOD(Phalcon_Logger_Adapter_Firephp, getFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter_Firephp, logInternal);
static PHP_METHOD(Phalcon_Logger_Adapter_Firephp, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_firephp_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_firephp_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Firephp, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, logInternal, arginfo_phalcon_logger_adapter_firephp_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Firephp, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Stream);

static PHP_METHOD(Phalcon_Logger_Adapter_Stream, __construct);
static PHP_METHOD(Phalcon_Logger_Adapter_Stream, getFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter_Stream, logInternal);
static PHP_METHOD(Phalcon_Logger_Adapter_Stream, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_stream___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_stream_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Stream, __construct, arginfo_phalcon_logger_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_Stream, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Stream, logInternal, arginfo_phalcon_logger_adapter_stream_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Stream, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_adapter_syslog_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Syslog);

static PHP_METHOD(Phalcon_Logger_Adapter_Syslog, __construct);
static PHP_METHOD(Phalcon_Logger_Adapter_Syslog, getFormatter);
static PHP_METHOD(Phalcon_Logger_Adapter_Syslog, logInternal);
static PHP_METHOD(Phalcon_Logger_Adapter_Syslog, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_syslog___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_syslog_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_syslog_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Syslog, __construct, arginfo_phalcon_logger_adapter_syslog___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, logInternal, arginfo_phalcon_logger_adapter_syslog_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Syslog, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setformatter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_setloglevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_log, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterinterface_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setFormatter, arginfo_phalcon_logger_adapterinterface_setformatter)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getFormatter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, setLogLevel, arginfo_phalcon_logger_adapterinterface_setloglevel)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, getLogLevel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, log, arginfo_phalcon_logger_adapterinterface_log)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, rollback, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, close, NULL)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, debug, arginfo_phalcon_logger_adapterinterface_debug)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, error, arginfo_phalcon_logger_adapterinterface_error)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, info, arginfo_phalcon_logger_adapterinterface_info)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, notice, arginfo_phalcon_logger_adapterinterface_notice)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, warning, arginfo_phalcon_logger_adapterinterface_warning)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, alert, arginfo_phalcon_logger_adapterinterface_alert)
	PHP_ABSTRACT_ME(Phalcon_Logger_AdapterInterface, emergency, arginfo_phalcon_logger_adapterinterface_emergency)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Exception);


zend_class_entry *phalcon_logger_formatter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter);

static PHP_METHOD(Phalcon_Logger_Formatter, getTypeString);
static PHP_METHOD(Phalcon_Logger_Formatter, interpolate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_interpolate, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter, getTypeString, arginfo_phalcon_logger_formatter_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter, interpolate, arginfo_phalcon_logger_formatter_interpolate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_formatter_firephp_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Firephp);

static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getTypeString);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, setShowBacktrace);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, getShowBacktrace);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, enableLabels);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, labelsEnabled);
static PHP_METHOD(Phalcon_Logger_Formatter_Firephp, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_gettypestring, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, 0, 0, 0)
	ZEND_ARG_INFO(0, isShow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_enablelabels, 0, 0, 0)
	ZEND_ARG_INFO(0, isEnable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_firephp_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_firephp_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getTypeString, arginfo_phalcon_logger_formatter_firephp_gettypestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, setShowBacktrace, arginfo_phalcon_logger_formatter_firephp_setshowbacktrace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, getShowBacktrace, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, enableLabels, arginfo_phalcon_logger_formatter_firephp_enablelabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, labelsEnabled, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Firephp, format, arginfo_phalcon_logger_formatter_firephp_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_formatter_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Json);

static PHP_METHOD(Phalcon_Logger_Formatter_Json, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_json_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_json_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Json, format, arginfo_phalcon_logger_formatter_json_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_formatter_line_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Line);

static PHP_METHOD(Phalcon_Logger_Formatter_Line, getDateFormat);
static PHP_METHOD(Phalcon_Logger_Formatter_Line, setDateFormat);
static PHP_METHOD(Phalcon_Logger_Formatter_Line, getFormat);
static PHP_METHOD(Phalcon_Logger_Formatter_Line, setFormat);
static PHP_METHOD(Phalcon_Logger_Formatter_Line, __construct);
static PHP_METHOD(Phalcon_Logger_Formatter_Line, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setdateformat, 0, 0, 1)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_setformat, 0, 0, 1)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, format)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_line_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_line_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Line, getDateFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, setDateFormat, arginfo_phalcon_logger_formatter_line_setdateformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, getFormat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, setFormat, arginfo_phalcon_logger_formatter_line_setformat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Formatter_Line, __construct, arginfo_phalcon_logger_formatter_line___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Formatter_Line, format, arginfo_phalcon_logger_formatter_line_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_formatter_syslog_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_Syslog);

static PHP_METHOD(Phalcon_Logger_Formatter_Syslog, format);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatter_syslog_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatter_syslog_method_entry) {
	PHP_ME(Phalcon_Logger_Formatter_Syslog, format, arginfo_phalcon_logger_formatter_syslog_format, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_formatterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_FormatterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_formatterinterface_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_formatterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_FormatterInterface, format, arginfo_phalcon_logger_formatterinterface_format)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Item);

static PHP_METHOD(Phalcon_Logger_Item, getType);
static PHP_METHOD(Phalcon_Logger_Item, getMessage);
static PHP_METHOD(Phalcon_Logger_Item, getTime);
static PHP_METHOD(Phalcon_Logger_Item, getContext);
static PHP_METHOD(Phalcon_Logger_Item, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_item___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_item_method_entry) {
	PHP_ME(Phalcon_Logger_Item, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, getContext, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Item, __construct, arginfo_phalcon_logger_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_logger_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Multiple);

static PHP_METHOD(Phalcon_Logger_Multiple, getLoggers);
static PHP_METHOD(Phalcon_Logger_Multiple, getFormatter);
static PHP_METHOD(Phalcon_Logger_Multiple, push);
static PHP_METHOD(Phalcon_Logger_Multiple, setFormatter);
static PHP_METHOD(Phalcon_Logger_Multiple, log);
static PHP_METHOD(Phalcon_Logger_Multiple, critical);
static PHP_METHOD(Phalcon_Logger_Multiple, emergency);
static PHP_METHOD(Phalcon_Logger_Multiple, debug);
static PHP_METHOD(Phalcon_Logger_Multiple, error);
static PHP_METHOD(Phalcon_Logger_Multiple, info);
static PHP_METHOD(Phalcon_Logger_Multiple, notice);
static PHP_METHOD(Phalcon_Logger_Multiple, warning);
static PHP_METHOD(Phalcon_Logger_Multiple, alert);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_push, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Logger\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_setformatter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_log, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_multiple_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_multiple_method_entry) {
	PHP_ME(Phalcon_Logger_Multiple, getLoggers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, push, arginfo_phalcon_logger_multiple_push, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, setFormatter, arginfo_phalcon_logger_multiple_setformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, log, arginfo_phalcon_logger_multiple_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, critical, arginfo_phalcon_logger_multiple_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, emergency, arginfo_phalcon_logger_multiple_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, debug, arginfo_phalcon_logger_multiple_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, error, arginfo_phalcon_logger_multiple_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, info, arginfo_phalcon_logger_multiple_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, notice, arginfo_phalcon_logger_multiple_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, warning, arginfo_phalcon_logger_multiple_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Multiple, alert, arginfo_phalcon_logger_multiple_alert, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application);

static PHP_METHOD(Phalcon_Mvc_Application, __construct);
static PHP_METHOD(Phalcon_Mvc_Application, useImplicitView);
static PHP_METHOD(Phalcon_Mvc_Application, registerModules);
static PHP_METHOD(Phalcon_Mvc_Application, getModules);
static PHP_METHOD(Phalcon_Mvc_Application, getModule);
static PHP_METHOD(Phalcon_Mvc_Application, setDefaultModule);
static PHP_METHOD(Phalcon_Mvc_Application, getDefaultModule);
static PHP_METHOD(Phalcon_Mvc_Application, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_useimplicitview, 0, 0, 1)
	ZEND_ARG_INFO(0, implicitView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_registermodules, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_getmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultModule)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_application_method_entry) {
	PHP_ME(Phalcon_Mvc_Application, __construct, arginfo_phalcon_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Application, useImplicitView, arginfo_phalcon_mvc_application_useimplicitview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, registerModules, arginfo_phalcon_mvc_application_registermodules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, getModules, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, getModule, arginfo_phalcon_mvc_application_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, setDefaultModule, arginfo_phalcon_mvc_application_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, getDefaultModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Application, handle, arginfo_phalcon_mvc_application_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_application_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application_Exception);


zend_class_entry *phalcon_mvc_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection);

static PHP_METHOD(Phalcon_Mvc_Collection, __construct);
static PHP_METHOD(Phalcon_Mvc_Collection, setId);
static PHP_METHOD(Phalcon_Mvc_Collection, getId);
static PHP_METHOD(Phalcon_Mvc_Collection, setDI);
static PHP_METHOD(Phalcon_Mvc_Collection, getDI);
static PHP_METHOD(Phalcon_Mvc_Collection, setEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection, getEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection, getCollectionManager);
static PHP_METHOD(Phalcon_Mvc_Collection, getReservedAttributes);
static PHP_METHOD(Phalcon_Mvc_Collection, useImplicitObjectIds);
static PHP_METHOD(Phalcon_Mvc_Collection, setSource);
static PHP_METHOD(Phalcon_Mvc_Collection, getSource);
static PHP_METHOD(Phalcon_Mvc_Collection, setConnectionService);
static PHP_METHOD(Phalcon_Mvc_Collection, getConnectionService);
static PHP_METHOD(Phalcon_Mvc_Collection, getConnection);
static PHP_METHOD(Phalcon_Mvc_Collection, readAttribute);
static PHP_METHOD(Phalcon_Mvc_Collection, writeAttribute);
static PHP_METHOD(Phalcon_Mvc_Collection, cloneResult);
static PHP_METHOD(Phalcon_Mvc_Collection, _getResultset);
static PHP_METHOD(Phalcon_Mvc_Collection, _getGroupResultset);
static PHP_METHOD(Phalcon_Mvc_Collection, _preSave);
static PHP_METHOD(Phalcon_Mvc_Collection, _postSave);
static PHP_METHOD(Phalcon_Mvc_Collection, validate);
static PHP_METHOD(Phalcon_Mvc_Collection, validationHasFailed);
static PHP_METHOD(Phalcon_Mvc_Collection, fireEvent);
static PHP_METHOD(Phalcon_Mvc_Collection, fireEventCancel);
static PHP_METHOD(Phalcon_Mvc_Collection, _cancelOperation);
static PHP_METHOD(Phalcon_Mvc_Collection, _exists);
static PHP_METHOD(Phalcon_Mvc_Collection, getMessages);
static PHP_METHOD(Phalcon_Mvc_Collection, appendMessage);
static PHP_METHOD(Phalcon_Mvc_Collection, save);
static PHP_METHOD(Phalcon_Mvc_Collection, findById);
static PHP_METHOD(Phalcon_Mvc_Collection, findFirst);
static PHP_METHOD(Phalcon_Mvc_Collection, find);
static PHP_METHOD(Phalcon_Mvc_Collection, count);
static PHP_METHOD(Phalcon_Mvc_Collection, aggregate);
static PHP_METHOD(Phalcon_Mvc_Collection, summatory);
static PHP_METHOD(Phalcon_Mvc_Collection, delete);
static PHP_METHOD(Phalcon_Mvc_Collection, toArray);
static PHP_METHOD(Phalcon_Mvc_Collection, serialize);
static PHP_METHOD(Phalcon_Mvc_Collection, unserialize);
static PHP_METHOD(Phalcon_Mvc_Collection, addBehavior);
static PHP_METHOD(Phalcon_Mvc_Collection, skipOperation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, modelsManager, Phalcon\\Mvc\\Collection\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Mvc\\Collection\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_useimplicitobjectids, 0, 0, 1)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__getresultset, 0, 0, 4)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connection)
	ZEND_ARG_INFO(0, unique)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__getgroupresultset, 0, 0, 3)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\Collection, 0)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__presave, 0, 0, 3)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, disableEvents)
	ZEND_ARG_INFO(0, exists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__postsave, 0, 0, 3)
	ZEND_ARG_INFO(0, disableEvents)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, exists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Mvc\\Model\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__canceloperation, 0, 0, 1)
	ZEND_ARG_INFO(0, disableEvents)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection__exists, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_findfirst, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_find, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_count, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_aggregate, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_summatory, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, finalize)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_addbehavior, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection, __construct, arginfo_phalcon_mvc_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection, setId, arginfo_phalcon_mvc_collection_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setDI, arginfo_phalcon_mvc_collection_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setEventsManager, arginfo_phalcon_mvc_collection_seteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getEventsManager, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getCollectionManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getReservedAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, useImplicitObjectIds, arginfo_phalcon_mvc_collection_useimplicitobjectids, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, setSource, arginfo_phalcon_mvc_collection_setsource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, setConnectionService, arginfo_phalcon_mvc_collection_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, readAttribute, arginfo_phalcon_mvc_collection_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, writeAttribute, arginfo_phalcon_mvc_collection_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, cloneResult, arginfo_phalcon_mvc_collection_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getResultset, arginfo_phalcon_mvc_collection__getresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _getGroupResultset, arginfo_phalcon_mvc_collection__getgroupresultset, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, _preSave, arginfo_phalcon_mvc_collection__presave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Collection, _postSave, arginfo_phalcon_mvc_collection__postsave, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Collection, validate, arginfo_phalcon_mvc_collection_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, validationHasFailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEvent, arginfo_phalcon_mvc_collection_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, fireEventCancel, arginfo_phalcon_mvc_collection_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, _cancelOperation, arginfo_phalcon_mvc_collection__canceloperation, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, _exists, arginfo_phalcon_mvc_collection__exists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, appendMessage, arginfo_phalcon_mvc_collection_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, findById, arginfo_phalcon_mvc_collection_findbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, findFirst, arginfo_phalcon_mvc_collection_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, find, arginfo_phalcon_mvc_collection_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, count, arginfo_phalcon_mvc_collection_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, aggregate, arginfo_phalcon_mvc_collection_aggregate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, summatory, arginfo_phalcon_mvc_collection_summatory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Collection, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, unserialize, arginfo_phalcon_mvc_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection, addBehavior, arginfo_phalcon_mvc_collection_addbehavior, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection, skipOperation, arginfo_phalcon_mvc_collection_skipoperation, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_behavior_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior);

static PHP_METHOD(Phalcon_Mvc_Collection_Behavior, __construct);
static PHP_METHOD(Phalcon_Mvc_Collection_Behavior, mustTakeAction);
static PHP_METHOD(Phalcon_Mvc_Collection_Behavior, getOptions);
static PHP_METHOD(Phalcon_Mvc_Collection_Behavior, notify);
static PHP_METHOD(Phalcon_Mvc_Collection_Behavior, missingMethod);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_musttakeaction, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_getoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behavior_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Behavior, __construct, arginfo_phalcon_mvc_collection_behavior___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, mustTakeAction, arginfo_phalcon_mvc_collection_behavior_musttakeaction, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, getOptions, arginfo_phalcon_mvc_collection_behavior_getoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, notify, arginfo_phalcon_mvc_collection_behavior_notify, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Behavior, missingMethod, arginfo_phalcon_mvc_collection_behavior_missingmethod, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_behavior_softdelete_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior_SoftDelete);

static PHP_METHOD(Phalcon_Mvc_Collection_Behavior_SoftDelete, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_softdelete_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behavior_softdelete_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Behavior_SoftDelete, notify, arginfo_phalcon_mvc_collection_behavior_softdelete_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_behavior_timestampable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Behavior_Timestampable);

static PHP_METHOD(Phalcon_Mvc_Collection_Behavior_Timestampable, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behavior_timestampable_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behavior_timestampable_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Behavior_Timestampable, notify, arginfo_phalcon_mvc_collection_behavior_timestampable_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_behaviorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_behaviorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, __construct, arginfo_phalcon_mvc_collection_behaviorinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, notify, arginfo_phalcon_mvc_collection_behaviorinterface_notify)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_BehaviorInterface, missingMethod, arginfo_phalcon_mvc_collection_behaviorinterface_missingmethod)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_document_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Document);

static PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Collection_Document, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Collection_Document, readAttribute);
static PHP_METHOD(Phalcon_Mvc_Collection_Document, writeAttribute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_document_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_document_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetExists, arginfo_phalcon_mvc_collection_document_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetGet, arginfo_phalcon_mvc_collection_document_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetSet, arginfo_phalcon_mvc_collection_document_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, offsetUnset, arginfo_phalcon_mvc_collection_document_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, readAttribute, arginfo_phalcon_mvc_collection_document_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Document, writeAttribute, arginfo_phalcon_mvc_collection_document_writeattribute, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Exception);


zend_class_entry *phalcon_mvc_collection_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Manager);

static PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, missingMethod);
static PHP_METHOD(Phalcon_Mvc_Collection_Manager, addBehavior);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_isusingimplicitobjectids, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_missingmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Collection_Manager, setDI, arginfo_phalcon_mvc_collection_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setEventsManager, arginfo_phalcon_mvc_collection_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setCustomEventsManager, arginfo_phalcon_mvc_collection_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getCustomEventsManager, arginfo_phalcon_mvc_collection_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, arginfo_phalcon_mvc_collection_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setConnectionService, arginfo_phalcon_mvc_collection_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds, arginfo_phalcon_mvc_collection_manager_useimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_manager_isusingimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getConnection, arginfo_phalcon_mvc_collection_manager_getconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, notifyEvent, arginfo_phalcon_mvc_collection_manager_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, missingMethod, arginfo_phalcon_mvc_collection_manager_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, addBehavior, arginfo_phalcon_mvc_collection_manager_addbehavior, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collection_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_INFO(0, useImplicitObjectIds)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_getconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_managerinterface_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Collection\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collection_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, initialize, arginfo_phalcon_mvc_collection_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isInitialized, arginfo_phalcon_mvc_collection_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_ManagerInterface, addBehavior, arginfo_phalcon_mvc_collection_managerinterface_addbehavior)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\CollectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, document, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findbyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_findfirst, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_find, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collectioninterface_count, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, parameters, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setId, arginfo_phalcon_mvc_collectioninterface_setid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getReservedAttributes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, setConnectionService, arginfo_phalcon_mvc_collectioninterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, readAttribute, arginfo_phalcon_mvc_collectioninterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, writeAttribute, arginfo_phalcon_mvc_collectioninterface_writeattribute)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_collectioninterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEvent, arginfo_phalcon_mvc_collectioninterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, fireEventCancel, arginfo_phalcon_mvc_collectioninterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, appendMessage, arginfo_phalcon_mvc_collectioninterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, save, NULL)
	ZEND_FENTRY(findById, NULL, arginfo_phalcon_mvc_collectioninterface_findbyid, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_collectioninterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_collectioninterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_collectioninterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_CollectionInterface, delete, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller);

static PHP_METHOD(Phalcon_Mvc_Controller, __construct);

ZEPHIR_INIT_FUNCS(phalcon_mvc_controller_method_entry) {
	PHP_ME(Phalcon_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_controllerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ControllerInterface);


zend_class_entry *phalcon_mvc_dispatcher_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher);

static PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousControllerName);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getPreviousActionName);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, _throwDispatchException);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, _handleException);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerClass);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getLastController);
static PHP_METHOD(Phalcon_Mvc_Dispatcher, getActiveController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__throwdispatchexception, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, exceptionCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcher__handleexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, exception, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcher_method_entry) {
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerSuffix, arginfo_phalcon_mvc_dispatcher_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setDefaultController, arginfo_phalcon_mvc_dispatcher_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, setControllerName, arginfo_phalcon_mvc_dispatcher_setcontrollername, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getPreviousActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, _throwDispatchException, arginfo_phalcon_mvc_dispatcher__throwdispatchexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, _handleException, arginfo_phalcon_mvc_dispatcher__handleexception, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Dispatcher, getControllerClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getLastController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Dispatcher, getActiveController, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_dispatcher_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher_Exception);


zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_dispatcherinterface_setcontrollername, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_dispatcherinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_micro_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro);

static PHP_METHOD(Phalcon_Mvc_Micro, __construct);
static PHP_METHOD(Phalcon_Mvc_Micro, setDI);
static PHP_METHOD(Phalcon_Mvc_Micro, map);
static PHP_METHOD(Phalcon_Mvc_Micro, get);
static PHP_METHOD(Phalcon_Mvc_Micro, post);
static PHP_METHOD(Phalcon_Mvc_Micro, put);
static PHP_METHOD(Phalcon_Mvc_Micro, patch);
static PHP_METHOD(Phalcon_Mvc_Micro, head);
static PHP_METHOD(Phalcon_Mvc_Micro, delete);
static PHP_METHOD(Phalcon_Mvc_Micro, options);
static PHP_METHOD(Phalcon_Mvc_Micro, mount);
static PHP_METHOD(Phalcon_Mvc_Micro, notFound);
static PHP_METHOD(Phalcon_Mvc_Micro, error);
static PHP_METHOD(Phalcon_Mvc_Micro, getRouter);
static PHP_METHOD(Phalcon_Mvc_Micro, setService);
static PHP_METHOD(Phalcon_Mvc_Micro, hasService);
static PHP_METHOD(Phalcon_Mvc_Micro, getService);
static PHP_METHOD(Phalcon_Mvc_Micro, getSharedService);
static PHP_METHOD(Phalcon_Mvc_Micro, handle);
static PHP_METHOD(Phalcon_Mvc_Micro, stop);
static PHP_METHOD(Phalcon_Mvc_Micro, setActiveHandler);
static PHP_METHOD(Phalcon_Mvc_Micro, getActiveHandler);
static PHP_METHOD(Phalcon_Mvc_Micro, getReturnedValue);
static PHP_METHOD(Phalcon_Mvc_Micro, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Micro, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Micro, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Micro, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Micro, before);
static PHP_METHOD(Phalcon_Mvc_Micro, after);
static PHP_METHOD(Phalcon_Mvc_Micro, finish);
static PHP_METHOD(Phalcon_Mvc_Micro, getHandlers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_mount, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, collection, Phalcon\\Mvc\\Micro\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_error, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setservice, 0, 0, 2)
	ZEND_ARG_INFO(0, serviceName)
	ZEND_ARG_INFO(0, definition)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_hasservice, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getservice, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_getsharedservice, 0, 0, 1)
	ZEND_ARG_INFO(0, serviceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_setactivehandler, 0, 0, 1)
	ZEND_ARG_INFO(0, activeHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_before, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_after, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_finish, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro, __construct, arginfo_phalcon_mvc_micro___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Micro, setDI, arginfo_phalcon_mvc_micro_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, map, arginfo_phalcon_mvc_micro_map, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, get, arginfo_phalcon_mvc_micro_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, post, arginfo_phalcon_mvc_micro_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, put, arginfo_phalcon_mvc_micro_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, patch, arginfo_phalcon_mvc_micro_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, head, arginfo_phalcon_mvc_micro_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, delete, arginfo_phalcon_mvc_micro_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, options, arginfo_phalcon_mvc_micro_options, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, mount, arginfo_phalcon_mvc_micro_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, notFound, arginfo_phalcon_mvc_micro_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, error, arginfo_phalcon_mvc_micro_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getRouter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setService, arginfo_phalcon_mvc_micro_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, hasService, arginfo_phalcon_mvc_micro_hasservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getService, arginfo_phalcon_mvc_micro_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getSharedService, arginfo_phalcon_mvc_micro_getsharedservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, handle, arginfo_phalcon_mvc_micro_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, setActiveHandler, arginfo_phalcon_mvc_micro_setactivehandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getActiveHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getReturnedValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetExists, arginfo_phalcon_mvc_micro_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetSet, arginfo_phalcon_mvc_micro_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetGet, arginfo_phalcon_mvc_micro_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, offsetUnset, arginfo_phalcon_mvc_micro_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, before, arginfo_phalcon_mvc_micro_before, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, after, arginfo_phalcon_mvc_micro_after, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, finish, arginfo_phalcon_mvc_micro_finish, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro, getHandlers, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_micro_collection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Collection);

static PHP_METHOD(Phalcon_Mvc_Micro_Collection, _addMap);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setPrefix);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getPrefix);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandlers);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setHandler);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, setLazy);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, isLazy);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, getHandler);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, map);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, get);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, post);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, put);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, patch);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, head);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, delete);
static PHP_METHOD(Phalcon_Mvc_Micro_Collection, options);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection__addmap, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collection_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_collection_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro_Collection, _addMap, arginfo_phalcon_mvc_micro_collection__addmap, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setPrefix, arginfo_phalcon_mvc_micro_collection_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandlers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setHandler, arginfo_phalcon_mvc_micro_collection_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, setLazy, arginfo_phalcon_mvc_micro_collection_setlazy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, isLazy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, map, arginfo_phalcon_mvc_micro_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, get, arginfo_phalcon_mvc_micro_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, post, arginfo_phalcon_mvc_micro_collection_post, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, put, arginfo_phalcon_mvc_micro_collection_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, patch, arginfo_phalcon_mvc_micro_collection_patch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, head, arginfo_phalcon_mvc_micro_collection_head, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, delete, arginfo_phalcon_mvc_micro_collection_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_Collection, options, arginfo_phalcon_mvc_micro_collection_options, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_micro_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_setlazy, 0, 0, 1)
	ZEND_ARG_INFO(0, lazy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_map, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_get, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_post, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_put, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_patch, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_head, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_collectioninterface_options, 0, 0, 2)
	ZEND_ARG_INFO(0, routePattern)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setPrefix, arginfo_phalcon_mvc_micro_collectioninterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandlers, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setHandler, arginfo_phalcon_mvc_micro_collectioninterface_sethandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, setLazy, arginfo_phalcon_mvc_micro_collectioninterface_setlazy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, isLazy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, getHandler, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, map, arginfo_phalcon_mvc_micro_collectioninterface_map)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, get, arginfo_phalcon_mvc_micro_collectioninterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, post, arginfo_phalcon_mvc_micro_collectioninterface_post)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, put, arginfo_phalcon_mvc_micro_collectioninterface_put)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, patch, arginfo_phalcon_mvc_micro_collectioninterface_patch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, head, arginfo_phalcon_mvc_micro_collectioninterface_head)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, delete, arginfo_phalcon_mvc_micro_collectioninterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_CollectionInterface, options, arginfo_phalcon_mvc_micro_collectioninterface_options)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_micro_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_Exception);


zend_class_entry *phalcon_mvc_micro_lazyloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader);

static PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct);
static PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_lazyloader_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, __construct, arginfo_phalcon_mvc_micro_lazyloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, __call, arginfo_phalcon_mvc_micro_lazyloader___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_micro_middlewareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_middlewareinterface_call, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, application, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_middlewareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_MiddlewareInterface, call, arginfo_phalcon_mvc_micro_middlewareinterface_call)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model);

static PHP_METHOD(Phalcon_Mvc_Model, __construct);
static PHP_METHOD(Phalcon_Mvc_Model, setDI);
static PHP_METHOD(Phalcon_Mvc_Model, getDI);
static PHP_METHOD(Phalcon_Mvc_Model, setEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model, getEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData);
static PHP_METHOD(Phalcon_Mvc_Model, getModelsManager);
static PHP_METHOD(Phalcon_Mvc_Model, setTransaction);
static PHP_METHOD(Phalcon_Mvc_Model, setSource);
static PHP_METHOD(Phalcon_Mvc_Model, getSource);
static PHP_METHOD(Phalcon_Mvc_Model, setSchema);
static PHP_METHOD(Phalcon_Mvc_Model, getSchema);
static PHP_METHOD(Phalcon_Mvc_Model, setConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model, setDirtyState);
static PHP_METHOD(Phalcon_Mvc_Model, getDirtyState);
static PHP_METHOD(Phalcon_Mvc_Model, getReadConnection);
static PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection);
static PHP_METHOD(Phalcon_Mvc_Model, assign);
static PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap);
static PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate);
static PHP_METHOD(Phalcon_Mvc_Model, cloneResult);
static PHP_METHOD(Phalcon_Mvc_Model, find);
static PHP_METHOD(Phalcon_Mvc_Model, findFirst);
static PHP_METHOD(Phalcon_Mvc_Model, query);
static PHP_METHOD(Phalcon_Mvc_Model, _exists);
static PHP_METHOD(Phalcon_Mvc_Model, _groupResult);
static PHP_METHOD(Phalcon_Mvc_Model, count);
static PHP_METHOD(Phalcon_Mvc_Model, sum);
static PHP_METHOD(Phalcon_Mvc_Model, maximum);
static PHP_METHOD(Phalcon_Mvc_Model, minimum);
static PHP_METHOD(Phalcon_Mvc_Model, average);
static PHP_METHOD(Phalcon_Mvc_Model, fireEvent);
static PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel);
static PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation);
static PHP_METHOD(Phalcon_Mvc_Model, appendMessage);
static PHP_METHOD(Phalcon_Mvc_Model, validate);
static PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed);
static PHP_METHOD(Phalcon_Mvc_Model, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict);
static PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade);
static PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict);
static PHP_METHOD(Phalcon_Mvc_Model, _preSave);
static PHP_METHOD(Phalcon_Mvc_Model, _postSave);
static PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert);
static PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate);
static PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords);
static PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords);
static PHP_METHOD(Phalcon_Mvc_Model, save);
static PHP_METHOD(Phalcon_Mvc_Model, create);
static PHP_METHOD(Phalcon_Mvc_Model, update);
static PHP_METHOD(Phalcon_Mvc_Model, delete);
static PHP_METHOD(Phalcon_Mvc_Model, getOperationMade);
static PHP_METHOD(Phalcon_Mvc_Model, refresh);
static PHP_METHOD(Phalcon_Mvc_Model, skipOperation);
static PHP_METHOD(Phalcon_Mvc_Model, readAttribute);
static PHP_METHOD(Phalcon_Mvc_Model, writeAttribute);
static PHP_METHOD(Phalcon_Mvc_Model, skipAttributes);
static PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate);
static PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate);
static PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues);
static PHP_METHOD(Phalcon_Mvc_Model, hasOne);
static PHP_METHOD(Phalcon_Mvc_Model, belongsTo);
static PHP_METHOD(Phalcon_Mvc_Model, hasMany);
static PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany);
static PHP_METHOD(Phalcon_Mvc_Model, addBehavior);
static PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots);
static PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData);
static PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData);
static PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData);
static PHP_METHOD(Phalcon_Mvc_Model, hasChanged);
static PHP_METHOD(Phalcon_Mvc_Model, getChangedFields);
static PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate);
static PHP_METHOD(Phalcon_Mvc_Model, getRelated);
static PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords);
static PHP_METHOD(Phalcon_Mvc_Model, __call);
static PHP_METHOD(Phalcon_Mvc_Model, __callStatic);
static PHP_METHOD(Phalcon_Mvc_Model, __set);
static PHP_METHOD(Phalcon_Mvc_Model, __get);
static PHP_METHOD(Phalcon_Mvc_Model, __isset);
static PHP_METHOD(Phalcon_Mvc_Model, serialize);
static PHP_METHOD(Phalcon_Mvc_Model, unserialize);
static PHP_METHOD(Phalcon_Mvc_Model, dump);
static PHP_METHOD(Phalcon_Mvc_Model, toArray);
static PHP_METHOD(Phalcon_Mvc_Model, setup);
static PHP_METHOD(Phalcon_Mvc_Model, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, modelsManager, Phalcon\\Mvc\\Model\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_settransaction, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setsource, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setschema, 0, 0, 1)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_assign, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dataColumnMap)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_cloneresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, hydrationMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, base, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__exists, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetadataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__groupresult, 0, 0, 3)
	ZEND_ARG_INFO(0, functionName)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Mvc\\Model\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_getmessages, 0, 0, 0)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__presave, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetadataInterface, 0)
	ZEND_ARG_INFO(0, exists)
	ZEND_ARG_INFO(0, identityField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__postsave, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_INFO(0, exists)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__dolowinsert, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetadataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, identityField)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__dolowupdate, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__presaverelatedrecords, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, related)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__postsaverelatedrecords, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, related)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributesoncreate, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_skipattributesonupdate, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_allowemptystringvalues, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasone, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_belongsto, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasmany, 0, 0, 3)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_hasmanytomany, 0, 0, 6)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_INFO(0, referenceModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_addbehavior, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_keepsnapshots, 0, 0, 1)
	ZEND_ARG_INFO(0, keepSnapshot)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setsnapshotdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_haschanged, 0, 0, 0)
	ZEND_ARG_INFO(0, fieldName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_usedynamicupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, dynamicUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model__getrelatedrecords, 0, 0, 3)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___call, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___callstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_setup, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_method_entry) {
	PHP_ME(Phalcon_Mvc_Model, __construct, arginfo_phalcon_mvc_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model, setDI, arginfo_phalcon_mvc_model_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setEventsManager, arginfo_phalcon_mvc_model_seteventsmanager, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getEventsManager, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getModelsMetaData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getModelsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setTransaction, arginfo_phalcon_mvc_model_settransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setSource, arginfo_phalcon_mvc_model_setsource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setSchema, arginfo_phalcon_mvc_model_setschema, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getSchema, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setConnectionService, arginfo_phalcon_mvc_model_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setReadConnectionService, arginfo_phalcon_mvc_model_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setWriteConnectionService, arginfo_phalcon_mvc_model_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnectionService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setDirtyState, arginfo_phalcon_mvc_model_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getDirtyState, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getReadConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getWriteConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, assign, arginfo_phalcon_mvc_model_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMap, arginfo_phalcon_mvc_model_cloneresultmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResultMapHydrate, arginfo_phalcon_mvc_model_cloneresultmaphydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, cloneResult, arginfo_phalcon_mvc_model_cloneresult, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, find, arginfo_phalcon_mvc_model_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, findFirst, arginfo_phalcon_mvc_model_findfirst, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, query, arginfo_phalcon_mvc_model_query, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, _exists, arginfo_phalcon_mvc_model__exists, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _groupResult, arginfo_phalcon_mvc_model__groupresult, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, count, arginfo_phalcon_mvc_model_count, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, sum, arginfo_phalcon_mvc_model_sum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, maximum, arginfo_phalcon_mvc_model_maximum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, minimum, arginfo_phalcon_mvc_model_minimum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, average, arginfo_phalcon_mvc_model_average, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, fireEvent, arginfo_phalcon_mvc_model_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, fireEventCancel, arginfo_phalcon_mvc_model_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _cancelOperation, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, appendMessage, arginfo_phalcon_mvc_model_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, validate, arginfo_phalcon_mvc_model_validate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, validationHasFailed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getMessages, arginfo_phalcon_mvc_model_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysRestrict, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _preSave, arginfo_phalcon_mvc_model__presave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _postSave, arginfo_phalcon_mvc_model__postsave, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _doLowInsert, arginfo_phalcon_mvc_model__dolowinsert, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _doLowUpdate, arginfo_phalcon_mvc_model__dolowupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _preSaveRelatedRecords, arginfo_phalcon_mvc_model__presaverelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, _postSaveRelatedRecords, arginfo_phalcon_mvc_model__postsaverelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, save, arginfo_phalcon_mvc_model_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, create, arginfo_phalcon_mvc_model_create, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, update, arginfo_phalcon_mvc_model_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getOperationMade, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, refresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, skipOperation, arginfo_phalcon_mvc_model_skipoperation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, readAttribute, arginfo_phalcon_mvc_model_readattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, writeAttribute, arginfo_phalcon_mvc_model_writeattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, skipAttributes, arginfo_phalcon_mvc_model_skipattributes, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnCreate, arginfo_phalcon_mvc_model_skipattributesoncreate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, skipAttributesOnUpdate, arginfo_phalcon_mvc_model_skipattributesonupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, allowEmptyStringValues, arginfo_phalcon_mvc_model_allowemptystringvalues, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasOne, arginfo_phalcon_mvc_model_hasone, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, belongsTo, arginfo_phalcon_mvc_model_belongsto, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasMany, arginfo_phalcon_mvc_model_hasmany, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, hasManyToMany, arginfo_phalcon_mvc_model_hasmanytomany, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, addBehavior, arginfo_phalcon_mvc_model_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, keepSnapshots, arginfo_phalcon_mvc_model_keepsnapshots, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, setSnapshotData, arginfo_phalcon_mvc_model_setsnapshotdata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasSnapshotData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getSnapshotData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, hasChanged, arginfo_phalcon_mvc_model_haschanged, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, getChangedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, useDynamicUpdate, arginfo_phalcon_mvc_model_usedynamicupdate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, getRelated, arginfo_phalcon_mvc_model_getrelated, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, _getRelatedRecords, arginfo_phalcon_mvc_model__getrelatedrecords, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model, __call, arginfo_phalcon_mvc_model___call, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __callStatic, arginfo_phalcon_mvc_model___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, __set, arginfo_phalcon_mvc_model___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __get, arginfo_phalcon_mvc_model___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, __isset, arginfo_phalcon_mvc_model___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, unserialize, arginfo_phalcon_mvc_model_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, dump, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, toArray, arginfo_phalcon_mvc_model_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model, setup, arginfo_phalcon_mvc_model_setup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_behavior_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior);

static PHP_METHOD(Phalcon_Mvc_Model_Behavior, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Behavior, mustTakeAction);
static PHP_METHOD(Phalcon_Mvc_Model_Behavior, getOptions);
static PHP_METHOD(Phalcon_Mvc_Model_Behavior, notify);
static PHP_METHOD(Phalcon_Mvc_Model_Behavior, missingMethod);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_musttakeaction, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_getoptions, 0, 0, 0)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behavior_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Behavior, __construct, arginfo_phalcon_mvc_model_behavior___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Behavior, mustTakeAction, arginfo_phalcon_mvc_model_behavior_musttakeaction, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Behavior, getOptions, arginfo_phalcon_mvc_model_behavior_getoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Behavior, notify, arginfo_phalcon_mvc_model_behavior_notify, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Behavior, missingMethod, arginfo_phalcon_mvc_model_behavior_missingmethod, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete);

static PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_softdelete_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behavior_softdelete_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Behavior_SoftDelete, notify, arginfo_phalcon_mvc_model_behavior_softdelete_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_behavior_timestampable_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_Timestampable);

static PHP_METHOD(Phalcon_Mvc_Model_Behavior_Timestampable, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_timestampable_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behavior_timestampable_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Behavior_Timestampable, notify, arginfo_phalcon_mvc_model_behavior_timestampable_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_behaviorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BehaviorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behaviorinterface_missingmethod, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behaviorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, __construct, arginfo_phalcon_mvc_model_behaviorinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, notify, arginfo_phalcon_mvc_model_behaviorinterface_notify)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BehaviorInterface, missingMethod, arginfo_phalcon_mvc_model_behaviorinterface_missingmethod)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_criteria_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Criteria);

static PHP_METHOD(Phalcon_Mvc_Model_Criteria, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, setModelName);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getModelName);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, bind);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, bindTypes);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, columns);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, join);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, innerJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, leftJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, rightJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, where);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, addWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, andWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, orWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, betweenWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, notBetweenWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, inWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, notInWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, conditions);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, order);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, orderBy);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, limit);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, forUpdate);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, sharedLock);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, cache);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getColumns);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getConditions);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getLimit);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getOrder);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, getParams);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, fromInput);
static PHP_METHOD(Phalcon_Mvc_Model_Criteria, execute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_bind, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_bindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_addwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_order, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_cache, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteria_frominput, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteria_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Criteria, setDI, arginfo_phalcon_mvc_model_criteria_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, setModelName, arginfo_phalcon_mvc_model_criteria_setmodelname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getModelName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bind, arginfo_phalcon_mvc_model_criteria_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, bindTypes, arginfo_phalcon_mvc_model_criteria_bindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, columns, arginfo_phalcon_mvc_model_criteria_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, join, arginfo_phalcon_mvc_model_criteria_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, innerJoin, arginfo_phalcon_mvc_model_criteria_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, leftJoin, arginfo_phalcon_mvc_model_criteria_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, rightJoin, arginfo_phalcon_mvc_model_criteria_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, where, arginfo_phalcon_mvc_model_criteria_where, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, addWhere, arginfo_phalcon_mvc_model_criteria_addwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, andWhere, arginfo_phalcon_mvc_model_criteria_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orWhere, arginfo_phalcon_mvc_model_criteria_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, betweenWhere, arginfo_phalcon_mvc_model_criteria_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notBetweenWhere, arginfo_phalcon_mvc_model_criteria_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, inWhere, arginfo_phalcon_mvc_model_criteria_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, notInWhere, arginfo_phalcon_mvc_model_criteria_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, conditions, arginfo_phalcon_mvc_model_criteria_conditions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, order, arginfo_phalcon_mvc_model_criteria_order, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, orderBy, arginfo_phalcon_mvc_model_criteria_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, limit, arginfo_phalcon_mvc_model_criteria_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, forUpdate, arginfo_phalcon_mvc_model_criteria_forupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, sharedLock, arginfo_phalcon_mvc_model_criteria_sharedlock, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, cache, arginfo_phalcon_mvc_model_criteria_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getConditions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getOrder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, fromInput, arginfo_phalcon_mvc_model_criteria_frominput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Model_Criteria, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_criteriainterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_setmodelname, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bind, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_bindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_conditions, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_forupdate, 0, 0, 0)
	ZEND_ARG_INFO(0, forUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_sharedlock, 0, 0, 0)
	ZEND_ARG_INFO(0, sharedLock)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_criteriainterface_frominput, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_criteriainterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, setModelName, arginfo_phalcon_mvc_model_criteriainterface_setmodelname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getModelName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bind, arginfo_phalcon_mvc_model_criteriainterface_bind)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, bindTypes, arginfo_phalcon_mvc_model_criteriainterface_bindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, where, arginfo_phalcon_mvc_model_criteriainterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, conditions, arginfo_phalcon_mvc_model_criteriainterface_conditions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orderBy, arginfo_phalcon_mvc_model_criteriainterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, limit, arginfo_phalcon_mvc_model_criteriainterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, forUpdate, arginfo_phalcon_mvc_model_criteriainterface_forupdate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, sharedLock, arginfo_phalcon_mvc_model_criteriainterface_sharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, andWhere, arginfo_phalcon_mvc_model_criteriainterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, orWhere, arginfo_phalcon_mvc_model_criteriainterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere, arginfo_phalcon_mvc_model_criteriainterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere, arginfo_phalcon_mvc_model_criteriainterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, inWhere, arginfo_phalcon_mvc_model_criteriainterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, notInWhere, arginfo_phalcon_mvc_model_criteriainterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getConditions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getOrder, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, getParams, NULL)
	ZEND_FENTRY(fromInput, NULL, arginfo_phalcon_mvc_model_criteriainterface_frominput, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_CriteriaInterface, execute, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exception);


zend_class_entry *phalcon_mvc_model_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Manager);

static PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, load);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSource);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSource);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setModelSchema);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getModelSchema);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setWriteConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setReadConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnection);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnection);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnection);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getReadConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getWriteConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, _getConnectionService);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, keepSnapshots);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, isKeepingSnapshots);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, useDynamicUpdate);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyToMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasManyToMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getReusableRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, setReusableRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, clearReusableObjects);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyToMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, registerNamespaceAlias);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAlias);
static PHP_METHOD(Phalcon_Mvc_Model_Manager, getNamespaceAliases);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_seteventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_load, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, newInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelsource, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelsource, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setmodelschema, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getmodelschema, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreadconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager__getconnection, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionServices)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreadconnectionservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager__getconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionServices)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_missingmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_keepsnapshots, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_usedynamicupdate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, dynamicUpdate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasone, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addbelongsto, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmany, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_addhasmanytomany, 0, 0, 7)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_existshasmanytomany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationrecords, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getreusablerecords, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_setreusablerecords, 0, 0, 3)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, records)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getbelongsto, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmany, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasone, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasmanytomany, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelations, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_registernamespacealias, 0, 0, 2)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_manager_getnamespacealias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Manager, setDI, arginfo_phalcon_mvc_model_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setEventsManager, arginfo_phalcon_mvc_model_manager_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getEventsManager, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setCustomEventsManager, arginfo_phalcon_mvc_model_manager_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getCustomEventsManager, arginfo_phalcon_mvc_model_manager_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, initialize, arginfo_phalcon_mvc_model_manager_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isInitialized, arginfo_phalcon_mvc_model_manager_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, load, arginfo_phalcon_mvc_model_manager_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSource, arginfo_phalcon_mvc_model_manager_setmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSource, arginfo_phalcon_mvc_model_manager_getmodelsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setModelSchema, arginfo_phalcon_mvc_model_manager_setmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getModelSchema, arginfo_phalcon_mvc_model_manager_getmodelschema, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setConnectionService, arginfo_phalcon_mvc_model_manager_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setWriteConnectionService, arginfo_phalcon_mvc_model_manager_setwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReadConnectionService, arginfo_phalcon_mvc_model_manager_setreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnection, arginfo_phalcon_mvc_model_manager_getreadconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnection, arginfo_phalcon_mvc_model_manager_getwriteconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, _getConnection, arginfo_phalcon_mvc_model_manager__getconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReadConnectionService, arginfo_phalcon_mvc_model_manager_getreadconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getWriteConnectionService, arginfo_phalcon_mvc_model_manager_getwriteconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, _getConnectionService, arginfo_phalcon_mvc_model_manager__getconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, notifyEvent, arginfo_phalcon_mvc_model_manager_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, missingMethod, arginfo_phalcon_mvc_model_manager_missingmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBehavior, arginfo_phalcon_mvc_model_manager_addbehavior, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, keepSnapshots, arginfo_phalcon_mvc_model_manager_keepsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isKeepingSnapshots, arginfo_phalcon_mvc_model_manager_iskeepingsnapshots, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, useDynamicUpdate, arginfo_phalcon_mvc_model_manager_usedynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, isUsingDynamicUpdate, arginfo_phalcon_mvc_model_manager_isusingdynamicupdate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasOne, arginfo_phalcon_mvc_model_manager_addhasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addBelongsTo, arginfo_phalcon_mvc_model_manager_addbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasMany, arginfo_phalcon_mvc_model_manager_addhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, addHasManyToMany, arginfo_phalcon_mvc_model_manager_addhasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsBelongsTo, arginfo_phalcon_mvc_model_manager_existsbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasMany, arginfo_phalcon_mvc_model_manager_existshasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasOne, arginfo_phalcon_mvc_model_manager_existshasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, existsHasManyToMany, arginfo_phalcon_mvc_model_manager_existshasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationByAlias, arginfo_phalcon_mvc_model_manager_getrelationbyalias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationRecords, arginfo_phalcon_mvc_model_manager_getrelationrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getReusableRecords, arginfo_phalcon_mvc_model_manager_getreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, setReusableRecords, arginfo_phalcon_mvc_model_manager_setreusablerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, clearReusableObjects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsToRecords, arginfo_phalcon_mvc_model_manager_getbelongstorecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyRecords, arginfo_phalcon_mvc_model_manager_gethasmanyrecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneRecords, arginfo_phalcon_mvc_model_manager_gethasonerecords, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getBelongsTo, arginfo_phalcon_mvc_model_manager_getbelongsto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasMany, arginfo_phalcon_mvc_model_manager_gethasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOne, arginfo_phalcon_mvc_model_manager_gethasone, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasManyToMany, arginfo_phalcon_mvc_model_manager_gethasmanytomany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany, arginfo_phalcon_mvc_model_manager_gethasoneandhasmany, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelations, arginfo_phalcon_mvc_model_manager_getrelations, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getRelationsBetween, arginfo_phalcon_mvc_model_manager_getrelationsbetween, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createQuery, arginfo_phalcon_mvc_model_manager_createquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, executeQuery, arginfo_phalcon_mvc_model_manager_executequery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, createBuilder, arginfo_phalcon_mvc_model_manager_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getLastQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, registerNamespaceAlias, arginfo_phalcon_mvc_model_manager_registernamespacealias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getNamespaceAlias, arginfo_phalcon_mvc_model_manager_getnamespacealias, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Manager, getNamespaceAliases, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_initialize, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setmodelsource, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getmodelsource, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setmodelschema, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getmodelschema, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setreadconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getreadconnectionservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_setwriteconnectionservice, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getreadconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getwriteconnection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_isinitialized, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_load, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, newInstance)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasone, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbelongsto, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addhasmany, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existsbelongsto, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasmany, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_existshasone, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasonerecords, 0, 0, 4)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, modelRelation)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getbelongsto, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasmany, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasone, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelations, 0, 0, 1)
	ZEND_ARG_INFO(0, modelName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween, 0, 0, 2)
	ZEND_ARG_INFO(0, first)
	ZEND_ARG_INFO(0, second)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createquery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_executequery, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_addbehavior, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, behavior, Phalcon\\Mvc\\Model\\BehaviorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_notifyevent, 0, 0, 2)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_missingmethod, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, eventName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_managerinterface_getrelationbyalias, 0, 0, 2)
	ZEND_ARG_INFO(0, modelName)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, initialize, arginfo_phalcon_mvc_model_managerinterface_initialize)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setModelSource, arginfo_phalcon_mvc_model_managerinterface_setmodelsource)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getModelSource, arginfo_phalcon_mvc_model_managerinterface_getmodelsource)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setModelSchema, arginfo_phalcon_mvc_model_managerinterface_setmodelschema)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getModelSchema, arginfo_phalcon_mvc_model_managerinterface_getmodelschema)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setConnectionService, arginfo_phalcon_mvc_model_managerinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setReadConnectionService, arginfo_phalcon_mvc_model_managerinterface_setreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getReadConnectionService, arginfo_phalcon_mvc_model_managerinterface_getreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, setWriteConnectionService, arginfo_phalcon_mvc_model_managerinterface_setwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getWriteConnectionService, arginfo_phalcon_mvc_model_managerinterface_getwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getReadConnection, arginfo_phalcon_mvc_model_managerinterface_getreadconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getWriteConnection, arginfo_phalcon_mvc_model_managerinterface_getwriteconnection)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, isInitialized, arginfo_phalcon_mvc_model_managerinterface_isinitialized)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastInitialized, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, load, arginfo_phalcon_mvc_model_managerinterface_load)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasOne, arginfo_phalcon_mvc_model_managerinterface_addhasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBelongsTo, arginfo_phalcon_mvc_model_managerinterface_addbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addHasMany, arginfo_phalcon_mvc_model_managerinterface_addhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsBelongsTo, arginfo_phalcon_mvc_model_managerinterface_existsbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasMany, arginfo_phalcon_mvc_model_managerinterface_existshasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, existsHasOne, arginfo_phalcon_mvc_model_managerinterface_existshasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsToRecords, arginfo_phalcon_mvc_model_managerinterface_getbelongstorecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasManyRecords, arginfo_phalcon_mvc_model_managerinterface_gethasmanyrecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneRecords, arginfo_phalcon_mvc_model_managerinterface_gethasonerecords)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getBelongsTo, arginfo_phalcon_mvc_model_managerinterface_getbelongsto)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOne, arginfo_phalcon_mvc_model_managerinterface_gethasone)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getHasOneAndHasMany, arginfo_phalcon_mvc_model_managerinterface_gethasoneandhasmany)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelations, arginfo_phalcon_mvc_model_managerinterface_getrelations)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationsBetween, arginfo_phalcon_mvc_model_managerinterface_getrelationsbetween)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createQuery, arginfo_phalcon_mvc_model_managerinterface_createquery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, executeQuery, arginfo_phalcon_mvc_model_managerinterface_executequery)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, createBuilder, arginfo_phalcon_mvc_model_managerinterface_createbuilder)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, addBehavior, arginfo_phalcon_mvc_model_managerinterface_addbehavior)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, notifyEvent, arginfo_phalcon_mvc_model_managerinterface_notifyevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, missingMethod, arginfo_phalcon_mvc_model_managerinterface_missingmethod)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getLastQuery, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ManagerInterface, getRelationByAlias, arginfo_phalcon_mvc_model_managerinterface_getrelationbyalias)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_message_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Message);

static PHP_METHOD(Phalcon_Mvc_Model_Message, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Message, setType);
static PHP_METHOD(Phalcon_Mvc_Model_Message, getType);
static PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage);
static PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage);
static PHP_METHOD(Phalcon_Mvc_Model_Message, setField);
static PHP_METHOD(Phalcon_Mvc_Model_Message, getField);
static PHP_METHOD(Phalcon_Mvc_Model_Message, setModel);
static PHP_METHOD(Phalcon_Mvc_Model_Message, getModel);
static PHP_METHOD(Phalcon_Mvc_Model_Message, __toString);
static PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message_setmodel, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_message___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_message_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Message, __construct, arginfo_phalcon_mvc_model_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Message, setType, arginfo_phalcon_mvc_model_message_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setMessage, arginfo_phalcon_mvc_model_message_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setField, arginfo_phalcon_mvc_model_message_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, setModel, arginfo_phalcon_mvc_model_message_setmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Message, __set_state, arginfo_phalcon_mvc_model_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __construct, arginfo_phalcon_mvc_model_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setType, arginfo_phalcon_mvc_model_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setMessage, arginfo_phalcon_mvc_model_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, setField, arginfo_phalcon_mvc_model_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_mvc_model_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initialize);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setStrategy);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getStrategy);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaData);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readMetaDataIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, readColumnMapIndex);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDefaultValues);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, getReverseColumnMap);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, hasAttribute);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata__initialize, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setstrategy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, strategy, Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readmetadataindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_writemetadataindex, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getidentityfield, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getbindtypes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_setemptystringattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getemptystringattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getdefaultvalues, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getcolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_hasattribute, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData, _initialize, arginfo_phalcon_mvc_model_metadata__initialize, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setDI, arginfo_phalcon_mvc_model_metadata_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setStrategy, arginfo_phalcon_mvc_model_metadata_setstrategy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getStrategy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaData, arginfo_phalcon_mvc_model_metadata_readmetadata, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readMetaDataIndex, arginfo_phalcon_mvc_model_metadata_readmetadataindex, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadata_writemetadataindex, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMap, arginfo_phalcon_mvc_model_metadata_readcolumnmap, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, readColumnMapIndex, arginfo_phalcon_mvc_model_metadata_readcolumnmapindex, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAttributes, arginfo_phalcon_mvc_model_metadata_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getprimarykeyattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadata_getnonprimarykeyattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getNotNullAttributes, arginfo_phalcon_mvc_model_metadata_getnotnullattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypes, arginfo_phalcon_mvc_model_metadata_getdatatypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadata_getdatatypesnumeric, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getIdentityField, arginfo_phalcon_mvc_model_metadata_getidentityfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getBindTypes, arginfo_phalcon_mvc_model_metadata_getbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticcreateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_getautomaticupdateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticcreateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadata_setautomaticupdateattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, setEmptyStringAttributes, arginfo_phalcon_mvc_model_metadata_setemptystringattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getEmptyStringAttributes, arginfo_phalcon_mvc_model_metadata_getemptystringattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getDefaultValues, arginfo_phalcon_mvc_model_metadata_getdefaultvalues, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getColumnMap, arginfo_phalcon_mvc_model_metadata_getcolumnmap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, getReverseColumnMap, arginfo_phalcon_mvc_model_metadata_getreversecolumnmap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, hasAttribute, arginfo_phalcon_mvc_model_metadata_hasattribute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_apc_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Apc);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_apc_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_apc_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, __construct, arginfo_phalcon_mvc_model_metadata_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, read, arginfo_phalcon_mvc_model_metadata_apc_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Apc, write, arginfo_phalcon_mvc_model_metadata_apc_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_files_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Files);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, read);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Files, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_files_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_files_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, __construct, arginfo_phalcon_mvc_model_metadata_files___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, read, arginfo_phalcon_mvc_model_metadata_files_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Files, write, arginfo_phalcon_mvc_model_metadata_files_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memory);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, read);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_memory_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, __construct, arginfo_phalcon_mvc_model_metadata_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, read, arginfo_phalcon_mvc_model_metadata_memory_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, write, arginfo_phalcon_mvc_model_metadata_memory_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Session);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_session_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_session_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, __construct, arginfo_phalcon_mvc_model_metadata_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, read, arginfo_phalcon_mvc_model_metadata_session_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Session, write, arginfo_phalcon_mvc_model_metadata_session_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_strategy_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Annotations);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_annotations_getmetadata, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_annotations_getcolumnmaps, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_strategy_annotations_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getMetaData, arginfo_phalcon_mvc_model_metadata_strategy_annotations_getmetadata, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Annotations, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategy_annotations_getcolumnmaps, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_strategy_introspection_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_strategyinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_StrategyInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getmetadata, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getcolumnmaps, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_strategyinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaData_StrategyInterface, getMetaData, arginfo_phalcon_mvc_model_metadata_strategyinterface_getmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaData_StrategyInterface, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategyinterface_getcolumnmaps)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadata_xcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Xcache);

static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, read);
static PHP_METHOD(Phalcon_Mvc_Model_MetaData_Xcache, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_xcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_xcache_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, __construct, arginfo_phalcon_mvc_model_metadata_xcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, read, arginfo_phalcon_mvc_model_metadata_xcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Xcache, write, arginfo_phalcon_mvc_model_metadata_xcache_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_metadatainterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaDataInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setstrategy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, strategy, Phalcon\\Mvc\\Model\\MetaData\\StrategyInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadata, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getidentityfield, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getbindtypes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getemptystringattributes, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getdefaultvalues, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_hasattribute, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadatainterface_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadatainterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setStrategy, arginfo_phalcon_mvc_model_metadatainterface_setstrategy)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getStrategy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaData, arginfo_phalcon_mvc_model_metadatainterface_readmetadata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_readmetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, writeMetaDataIndex, arginfo_phalcon_mvc_model_metadatainterface_writemetadataindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMap, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, readColumnMapIndex, arginfo_phalcon_mvc_model_metadatainterface_readcolumnmapindex)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAttributes, arginfo_phalcon_mvc_model_metadatainterface_getattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNonPrimaryKeyAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnonprimarykeyattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getNotNullAttributes, arginfo_phalcon_mvc_model_metadatainterface_getnotnullattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypes, arginfo_phalcon_mvc_model_metadatainterface_getdatatypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDataTypesNumeric, arginfo_phalcon_mvc_model_metadatainterface_getdatatypesnumeric)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getIdentityField, arginfo_phalcon_mvc_model_metadatainterface_getidentityfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getBindTypes, arginfo_phalcon_mvc_model_metadatainterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_getautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticCreateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticcreateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setAutomaticUpdateAttributes, arginfo_phalcon_mvc_model_metadatainterface_setautomaticupdateattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, setEmptyStringAttributes, arginfo_phalcon_mvc_model_metadatainterface_setemptystringattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getEmptyStringAttributes, arginfo_phalcon_mvc_model_metadatainterface_getemptystringattributes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getDefaultValues, arginfo_phalcon_mvc_model_metadatainterface_getdefaultvalues)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getcolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, getReverseColumnMap, arginfo_phalcon_mvc_model_metadatainterface_getreversecolumnmap)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, hasAttribute, arginfo_phalcon_mvc_model_metadatainterface_hasattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, isEmpty, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, reset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, read, arginfo_phalcon_mvc_model_metadatainterface_read)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaDataInterface, write, arginfo_phalcon_mvc_model_metadatainterface_write)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query);

static PHP_METHOD(Phalcon_Mvc_Model_Query, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setUniqueRow);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getUniqueRow);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getCaseExpression);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getSingleJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getMultiJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete);
static PHP_METHOD(Phalcon_Mvc_Model_Query, parse);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getCache);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete);
static PHP_METHOD(Phalcon_Mvc_Model_Query, _getRelatedRecords);
static PHP_METHOD(Phalcon_Mvc_Model_Query, execute);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getSingleResult);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setType);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getType);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setBindParams);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getBindParams);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setBindTypes);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getBindTypes);
static PHP_METHOD(Phalcon_Mvc_Model_Query, setIntermediate);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getIntermediate);
static PHP_METHOD(Phalcon_Mvc_Model_Query, cache);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getCacheOptions);
static PHP_METHOD(Phalcon_Mvc_Model_Query, getSql);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, phql)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getqualified, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getcallargument, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getcaseexpression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getfunctioncall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getexpression, 0, 0, 1)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, quoting)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getselectcolumn, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, column, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__gettable, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, qualifiedName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjoin, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\ManagerInterface, 0)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjointype, 0, 0, 1)
	ZEND_ARG_INFO(0, join)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getsinglejoin, 0, 0, 5)
	ZEND_ARG_INFO(0, joinType)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_INFO(0, modelAlias)
	ZEND_ARG_INFO(0, joinAlias)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getmultijoin, 0, 0, 5)
	ZEND_ARG_INFO(0, joinType)
	ZEND_ARG_INFO(0, joinSource)
	ZEND_ARG_INFO(0, modelAlias)
	ZEND_ARG_INFO(0, joinAlias)
	ZEND_ARG_OBJ_INFO(0, relation, Phalcon\\Mvc\\Model\\RelationInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getjoins, 0, 0, 1)
	ZEND_ARG_INFO(0, select)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getorderclause, 0, 0, 1)
	ZEND_ARG_INFO(0, order)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getgroupclause, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getlimitclause, 0, 0, 1)
	ZEND_ARG_INFO(0, limitClause)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__prepareselect, 0, 0, 0)
	ZEND_ARG_INFO(0, ast)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeselect, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
	ZEND_ARG_INFO(0, simulate)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeinsert, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executeupdate, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__executedelete, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query__getrelatedrecords, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_INFO(0, intermediate)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_getsingleresult, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setbindtypes, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_setintermediate, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, intermediate, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query, __construct, arginfo_phalcon_mvc_model_query___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query, setDI, arginfo_phalcon_mvc_model_query_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setUniqueRow, arginfo_phalcon_mvc_model_query_setuniquerow, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getUniqueRow, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _getQualified, arginfo_phalcon_mvc_model_query__getqualified, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCallArgument, arginfo_phalcon_mvc_model_query__getcallargument, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getCaseExpression, arginfo_phalcon_mvc_model_query__getcaseexpression, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getFunctionCall, arginfo_phalcon_mvc_model_query__getfunctioncall, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getExpression, arginfo_phalcon_mvc_model_query__getexpression, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSelectColumn, arginfo_phalcon_mvc_model_query__getselectcolumn, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getTable, arginfo_phalcon_mvc_model_query__gettable, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoin, arginfo_phalcon_mvc_model_query__getjoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoinType, arginfo_phalcon_mvc_model_query__getjointype, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getSingleJoin, arginfo_phalcon_mvc_model_query__getsinglejoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getMultiJoin, arginfo_phalcon_mvc_model_query__getmultijoin, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getJoins, arginfo_phalcon_mvc_model_query__getjoins, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getOrderClause, arginfo_phalcon_mvc_model_query__getorderclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getGroupClause, arginfo_phalcon_mvc_model_query__getgroupclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getLimitClause, arginfo_phalcon_mvc_model_query__getlimitclause, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareSelect, arginfo_phalcon_mvc_model_query__prepareselect, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareInsert, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareUpdate, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _prepareDelete, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeSelect, arginfo_phalcon_mvc_model_query__executeselect, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeInsert, arginfo_phalcon_mvc_model_query__executeinsert, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeUpdate, arginfo_phalcon_mvc_model_query__executeupdate, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _executeDelete, arginfo_phalcon_mvc_model_query__executedelete, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, _getRelatedRecords, arginfo_phalcon_mvc_model_query__getrelatedrecords, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query, execute, arginfo_phalcon_mvc_model_query_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSingleResult, arginfo_phalcon_mvc_model_query_getsingleresult, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setType, arginfo_phalcon_mvc_model_query_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindParams, arginfo_phalcon_mvc_model_query_setbindparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setBindTypes, arginfo_phalcon_mvc_model_query_setbindtypes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getBindTypes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, setIntermediate, arginfo_phalcon_mvc_model_query_setintermediate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getIntermediate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, cache, arginfo_phalcon_mvc_model_query_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query, getSql, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Builder);

static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, distinct);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getDistinct);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, columns);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getColumns);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, from);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, addFrom);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getFrom);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, join);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, innerJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, leftJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, rightJoin);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, where);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, andWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, betweenWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, inWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, notInWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getWhere);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, orderBy);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOrderBy);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, having);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getHaving);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, limit);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getLimit);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, offset);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getOffset);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, groupBy);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getGroupBy);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getPhql);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Builder, getQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_distinct, 0, 0, 1)
	ZEND_ARG_INFO(0, distinct)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_limit, 0, 0, 0)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builder_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_builder_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, __construct, arginfo_phalcon_mvc_model_query_builder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, setDI, arginfo_phalcon_mvc_model_query_builder_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, distinct, arginfo_phalcon_mvc_model_query_builder_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getDistinct, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, columns, arginfo_phalcon_mvc_model_query_builder_columns, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getColumns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, from, arginfo_phalcon_mvc_model_query_builder_from, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, addFrom, arginfo_phalcon_mvc_model_query_builder_addfrom, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getFrom, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, join, arginfo_phalcon_mvc_model_query_builder_join, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, innerJoin, arginfo_phalcon_mvc_model_query_builder_innerjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, leftJoin, arginfo_phalcon_mvc_model_query_builder_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, rightJoin, arginfo_phalcon_mvc_model_query_builder_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, where, arginfo_phalcon_mvc_model_query_builder_where, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, andWhere, arginfo_phalcon_mvc_model_query_builder_andwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orWhere, arginfo_phalcon_mvc_model_query_builder_orwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, betweenWhere, arginfo_phalcon_mvc_model_query_builder_betweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notBetweenWhere, arginfo_phalcon_mvc_model_query_builder_notbetweenwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, inWhere, arginfo_phalcon_mvc_model_query_builder_inwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, notInWhere, arginfo_phalcon_mvc_model_query_builder_notinwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getWhere, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, orderBy, arginfo_phalcon_mvc_model_query_builder_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOrderBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, having, arginfo_phalcon_mvc_model_query_builder_having, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getHaving, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, limit, arginfo_phalcon_mvc_model_query_builder_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, offset, arginfo_phalcon_mvc_model_query_builder_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getOffset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, groupBy, arginfo_phalcon_mvc_model_query_builder_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getGroupBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getPhql, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Query_Builder, getQuery, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_builderinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_BuilderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_columns, 0, 0, 1)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_from, 0, 0, 1)
	ZEND_ARG_INFO(0, models)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_addfrom, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_join, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_innerjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_where, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_andwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, conditions)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere, 0, 0, 3)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_INFO(0, minimum)
	ZEND_ARG_INFO(0, maximum)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_inwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_notinwhere, 0, 0, 2)
	ZEND_ARG_INFO(0, expr)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_having, 0, 0, 1)
	ZEND_ARG_INFO(0, having)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_builderinterface_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_builderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, __construct, arginfo_phalcon_mvc_model_query_builderinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, columns, arginfo_phalcon_mvc_model_query_builderinterface_columns)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getColumns, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, from, arginfo_phalcon_mvc_model_query_builderinterface_from)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, addFrom, arginfo_phalcon_mvc_model_query_builderinterface_addfrom)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getFrom, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, join, arginfo_phalcon_mvc_model_query_builderinterface_join)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, innerJoin, arginfo_phalcon_mvc_model_query_builderinterface_innerjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, leftJoin, arginfo_phalcon_mvc_model_query_builderinterface_leftjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, rightJoin, arginfo_phalcon_mvc_model_query_builderinterface_rightjoin)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, where, arginfo_phalcon_mvc_model_query_builderinterface_where)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, andWhere, arginfo_phalcon_mvc_model_query_builderinterface_andwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orWhere, arginfo_phalcon_mvc_model_query_builderinterface_orwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, betweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_betweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notBetweenWhere, arginfo_phalcon_mvc_model_query_builderinterface_notbetweenwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, inWhere, arginfo_phalcon_mvc_model_query_builderinterface_inwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, notInWhere, arginfo_phalcon_mvc_model_query_builderinterface_notinwhere)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getWhere, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, orderBy, arginfo_phalcon_mvc_model_query_builderinterface_orderby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getOrderBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, having, arginfo_phalcon_mvc_model_query_builderinterface_having)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getHaving, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, limit, arginfo_phalcon_mvc_model_query_builderinterface_limit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getLimit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, groupBy, arginfo_phalcon_mvc_model_query_builderinterface_groupby)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getGroupBy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getPhql, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_BuilderInterface, getQuery, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_lang_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Lang);

static PHP_METHOD(Phalcon_Mvc_Model_Query_Lang, parsePHQL);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_lang_parsephql, 0, 0, 1)
	ZEND_ARG_INFO(0, phql)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_lang_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Lang, parsePHQL, arginfo_phalcon_mvc_model_query_lang_parsephql, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_status_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_Status);

static PHP_METHOD(Phalcon_Mvc_Model_Query_Status, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getModel);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Status, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Query_Status, success);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_status___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_status_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Query_Status, __construct, arginfo_phalcon_mvc_model_query_status___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Query_Status, success, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_query_statusinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Query_StatusInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_query_statusinterface___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, success)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_query_statusinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, __construct, arginfo_phalcon_mvc_model_query_statusinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Query_StatusInterface, success, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_queryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_setuniquerow, 0, 0, 1)
	ZEND_ARG_INFO(0, uniqueRow)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, bindParams)
	ZEND_ARG_INFO(0, bindTypes)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_queryinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, parse, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, cache, arginfo_phalcon_mvc_model_queryinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getCacheOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, setUniqueRow, arginfo_phalcon_mvc_model_queryinterface_setuniquerow)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getUniqueRow, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, execute, arginfo_phalcon_mvc_model_queryinterface_execute)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_relation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation);

static PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel);
static PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relation_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Relation, setIntermediateRelation, arginfo_phalcon_mvc_model_relation_setintermediaterelation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isThrough, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isReusable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_relationinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, __construct, arginfo_phalcon_mvc_model_relationinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isReusable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isThrough, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultinterface_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setDirtyState, arginfo_phalcon_mvc_model_resultinterface_setdirtystate)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_resultset_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset);

static PHP_METHOD(Phalcon_Mvc_Model_Resultset, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, next);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, valid);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, key);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, rewind);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, seek);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, count);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getType);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getFirst);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getLast);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, setIsFresh);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, isFresh);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, setHydrateMode);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getHydrateMode);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getCache);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, update);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, delete);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset, filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_seek, 0, 0, 1)
	ZEND_ARG_INFO(0, position)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_sethydratemode, 0, 0, 1)
	ZEND_ARG_INFO(0, hydrateMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_update, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_delete, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset, __construct, arginfo_phalcon_mvc_model_resultset___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, rewind, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, seek, arginfo_phalcon_mvc_model_resultset_seek, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetExists, arginfo_phalcon_mvc_model_resultset_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetGet, arginfo_phalcon_mvc_model_resultset_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetSet, arginfo_phalcon_mvc_model_resultset_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, offsetUnset, arginfo_phalcon_mvc_model_resultset_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getLast, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setIsFresh, arginfo_phalcon_mvc_model_resultset_setisfresh, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, isFresh, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, setHydrateMode, arginfo_phalcon_mvc_model_resultset_sethydratemode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getHydrateMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, update, arginfo_phalcon_mvc_model_resultset_update, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, delete, arginfo_phalcon_mvc_model_resultset_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset, filter, arginfo_phalcon_mvc_model_resultset_filter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_resultset_complex_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex);

static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, columnTypes)
	ZEND_ARG_OBJ_INFO(0, result, Phalcon\\Db\\ResultInterface, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_complex_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_complex_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, __construct, arginfo_phalcon_mvc_model_resultset_complex___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Complex, unserialize, arginfo_phalcon_mvc_model_resultset_complex_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_resultset_simple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple);

static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize);
static PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, result)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_toarray, 0, 0, 0)
	ZEND_ARG_INFO(0, renameColumns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultset_simple_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultset_simple_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, __construct, arginfo_phalcon_mvc_model_resultset_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, current, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, toArray, arginfo_phalcon_mvc_model_resultset_simple_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Resultset_Simple, unserialize, arginfo_phalcon_mvc_model_resultset_simple_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 0, 1)
	ZEND_ARG_INFO(0, isFresh)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultsetinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, toArray, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_row_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Row);

static PHP_METHOD(Phalcon_Mvc_Model_Row, setDirtyState);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetExists);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetGet);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetSet);
static PHP_METHOD(Phalcon_Mvc_Model_Row, offsetUnset);
static PHP_METHOD(Phalcon_Mvc_Model_Row, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_row_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_row_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Row, setDirtyState, arginfo_phalcon_mvc_model_row_setdirtystate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetExists, arginfo_phalcon_mvc_model_row_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetGet, arginfo_phalcon_mvc_model_row_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetSet, arginfo_phalcon_mvc_model_row_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, offsetUnset, arginfo_phalcon_mvc_model_row_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Row, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_transaction_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction);

static PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
	ZEND_ARG_INFO(0, autoBegin)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_settransactionmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction, __construct, arginfo_phalcon_mvc_model_transaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setTransactionManager, arginfo_phalcon_mvc_model_transaction_settransactionmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, rollback, arginfo_phalcon_mvc_model_transaction_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setIsNewTransaction, arginfo_phalcon_mvc_model_transaction_setisnewtransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort, arginfo_phalcon_mvc_model_transaction_setrollbackonabort, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isManaged, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isValid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackedRecord, arginfo_phalcon_mvc_model_transaction_setrollbackedrecord, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_transaction_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Exception);


zend_class_entry *phalcon_mvc_model_transaction_failed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Failed);

static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Failed, getRecord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_failed___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_failed_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, __construct, arginfo_phalcon_mvc_model_transaction_failed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecordMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Failed, getRecord, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager);

static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction);
static PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdbservice, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackPendent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_notifycommit, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager__collecttransaction, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_manager_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, __construct, arginfo_phalcon_mvc_model_transaction_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDI, arginfo_phalcon_mvc_model_transaction_manager_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDbService, arginfo_phalcon_mvc_model_transaction_manager_setdbservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDbService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent, arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, has, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, get, arginfo_phalcon_mvc_model_transaction_manager_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction, arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollback, arginfo_phalcon_mvc_model_transaction_manager_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback, arginfo_phalcon_mvc_model_transaction_manager_notifyrollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit, arginfo_phalcon_mvc_model_transaction_manager_notifycommit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction, arginfo_phalcon_mvc_model_transaction_manager__collecttransaction, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, collect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transaction_managerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, __construct, arginfo_phalcon_mvc_model_transaction_managerinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_transactioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_rollback, 0, 0, 0)
	ZEND_ARG_INFO(0, rollbackMessage)
	ZEND_ARG_INFO(0, rollbackRecord)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, 0, 0, 1)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackOnAbort)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_transactioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager, arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, begin, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, rollback, arginfo_phalcon_mvc_model_transactioninterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction, arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort, arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isManaged, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, isValid, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord, arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validationfailed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed);

static PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel);
static PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validationfailed___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, validationMessages, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validationfailed_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, __construct, arginfo_phalcon_mvc_model_validationfailed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator);

static PHP_METHOD(Phalcon_Mvc_Model_Validator, __construct);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, appendMessage);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getMessages);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getOptions);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, getOption);
static PHP_METHOD(Phalcon_Mvc_Model_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator, __construct, arginfo_phalcon_mvc_model_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Validator, appendMessage, arginfo_phalcon_mvc_model_validator_appendmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Validator, getOptions, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, getOption, arginfo_phalcon_mvc_model_validator_getoption, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, isSetOption, arginfo_phalcon_mvc_model_validator_issetoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_email_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Email);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Email, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_email_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_email_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Email, validate, arginfo_phalcon_mvc_model_validator_email_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_exclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Exclusionin);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Exclusionin, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_exclusionin_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_exclusionin_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Exclusionin, validate, arginfo_phalcon_mvc_model_validator_exclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_inclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Inclusionin);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Inclusionin, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_inclusionin_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_inclusionin_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Inclusionin, validate, arginfo_phalcon_mvc_model_validator_inclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_numericality_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Numericality);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Numericality, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_numericality_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_numericality_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Numericality, validate, arginfo_phalcon_mvc_model_validator_numericality_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_presenceof_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_PresenceOf);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_PresenceOf, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_presenceof_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_presenceof_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_PresenceOf, validate, arginfo_phalcon_mvc_model_validator_presenceof_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_regex_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Regex);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Regex, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_regex_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_regex_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Regex, validate, arginfo_phalcon_mvc_model_validator_regex_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_stringlength_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_StringLength);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_StringLength, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_stringlength_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_stringlength_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_StringLength, validate, arginfo_phalcon_mvc_model_validator_stringlength_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_uniqueness_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Uniqueness);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Uniqueness, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_uniqueness_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_uniqueness_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Uniqueness, validate, arginfo_phalcon_mvc_model_validator_uniqueness_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validator_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator_Url);

static PHP_METHOD(Phalcon_Mvc_Model_Validator_Url, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_url_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_url_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator_Url, validate, arginfo_phalcon_mvc_model_validator_url_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_model_validatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validatorinterface_validate, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, record, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ValidatorInterface, validate, arginfo_phalcon_mvc_model_validatorinterface_validate)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_modelinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModelInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_settransaction, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, transaction, Phalcon\\Mvc\\Model\\TransactionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setreadconnectionservice, 0, 0, 1)
	ZEND_ARG_INFO(0, connectionService)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setdirtystate, 0, 0, 1)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_assign, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dataColumnMap)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmap, 0, 0, 3)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, dirtyState)
	ZEND_ARG_INFO(0, keepSnapshots)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresult, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, base, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, dirtyState)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
	ZEND_ARG_INFO(0, hydrationMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_find, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_findfirst, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_query, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_count, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_sum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_maximum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_minimum, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_average, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireevent, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_fireeventcancel, 0, 0, 1)
	ZEND_ARG_INFO(0, eventName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Mvc\\Model\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_save, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_update, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_skipoperation, 0, 0, 1)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_readattribute, 0, 0, 1)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_writeattribute, 0, 0, 2)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_getrelated, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_modelinterface_setsnapshotdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, columnMap)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_modelinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setTransaction, arginfo_phalcon_mvc_modelinterface_settransaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSource, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getSchema, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setConnectionService, arginfo_phalcon_mvc_modelinterface_setconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setWriteConnectionService, arginfo_phalcon_mvc_modelinterface_setwriteconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setReadConnectionService, arginfo_phalcon_mvc_modelinterface_setreadconnectionservice)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnectionService, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getReadConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getWriteConnection, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setDirtyState, arginfo_phalcon_mvc_modelinterface_setdirtystate)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getDirtyState, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, assign, arginfo_phalcon_mvc_modelinterface_assign)
	ZEND_FENTRY(cloneResultMap, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmap, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResult, NULL, arginfo_phalcon_mvc_modelinterface_cloneresult, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(cloneResultMapHydrate, NULL, arginfo_phalcon_mvc_modelinterface_cloneresultmaphydrate, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(find, NULL, arginfo_phalcon_mvc_modelinterface_find, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(findFirst, NULL, arginfo_phalcon_mvc_modelinterface_findfirst, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(query, NULL, arginfo_phalcon_mvc_modelinterface_query, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(count, NULL, arginfo_phalcon_mvc_modelinterface_count, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(sum, NULL, arginfo_phalcon_mvc_modelinterface_sum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(maximum, NULL, arginfo_phalcon_mvc_modelinterface_maximum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(minimum, NULL, arginfo_phalcon_mvc_modelinterface_minimum, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(average, NULL, arginfo_phalcon_mvc_modelinterface_average, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEvent, arginfo_phalcon_mvc_modelinterface_fireevent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, fireEventCancel, arginfo_phalcon_mvc_modelinterface_fireeventcancel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, appendMessage, arginfo_phalcon_mvc_modelinterface_appendmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, validationHasFailed, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getMessages, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, save, arginfo_phalcon_mvc_modelinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, create, arginfo_phalcon_mvc_modelinterface_create)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, update, arginfo_phalcon_mvc_modelinterface_update)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, delete, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getOperationMade, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, refresh, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, skipOperation, arginfo_phalcon_mvc_modelinterface_skipoperation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, readAttribute, arginfo_phalcon_mvc_modelinterface_readattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, writeAttribute, arginfo_phalcon_mvc_modelinterface_writeattribute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, getRelated, arginfo_phalcon_mvc_modelinterface_getrelated)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, setSnapshotData, arginfo_phalcon_mvc_modelinterface_setsnapshotdata)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModelInterface, reset, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_moduledefinitioninterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ModuleDefinitionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerautoloaders, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_moduledefinitioninterface_registerservices, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_moduledefinitioninterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerAutoloaders, arginfo_phalcon_mvc_moduledefinitioninterface_registerautoloaders)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ModuleDefinitionInterface, registerServices, arginfo_phalcon_mvc_moduledefinitioninterface_registerservices)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router);

static PHP_METHOD(Phalcon_Mvc_Router, __construct);
static PHP_METHOD(Phalcon_Mvc_Router, setDI);
static PHP_METHOD(Phalcon_Mvc_Router, getDI);
static PHP_METHOD(Phalcon_Mvc_Router, getRewriteUri);
static PHP_METHOD(Phalcon_Mvc_Router, setUriSource);
static PHP_METHOD(Phalcon_Mvc_Router, removeExtraSlashes);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultNamespace);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultModule);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultController);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaultAction);
static PHP_METHOD(Phalcon_Mvc_Router, setDefaults);
static PHP_METHOD(Phalcon_Mvc_Router, getDefaults);
static PHP_METHOD(Phalcon_Mvc_Router, handle);
static PHP_METHOD(Phalcon_Mvc_Router, add);
static PHP_METHOD(Phalcon_Mvc_Router, addGet);
static PHP_METHOD(Phalcon_Mvc_Router, addPost);
static PHP_METHOD(Phalcon_Mvc_Router, addPut);
static PHP_METHOD(Phalcon_Mvc_Router, addPatch);
static PHP_METHOD(Phalcon_Mvc_Router, addDelete);
static PHP_METHOD(Phalcon_Mvc_Router, addOptions);
static PHP_METHOD(Phalcon_Mvc_Router, addHead);
static PHP_METHOD(Phalcon_Mvc_Router, mount);
static PHP_METHOD(Phalcon_Mvc_Router, notFound);
static PHP_METHOD(Phalcon_Mvc_Router, clear);
static PHP_METHOD(Phalcon_Mvc_Router, getNamespaceName);
static PHP_METHOD(Phalcon_Mvc_Router, getModuleName);
static PHP_METHOD(Phalcon_Mvc_Router, getControllerName);
static PHP_METHOD(Phalcon_Mvc_Router, getActionName);
static PHP_METHOD(Phalcon_Mvc_Router, getParams);
static PHP_METHOD(Phalcon_Mvc_Router, getMatchedRoute);
static PHP_METHOD(Phalcon_Mvc_Router, getMatches);
static PHP_METHOD(Phalcon_Mvc_Router, wasMatched);
static PHP_METHOD(Phalcon_Mvc_Router, getRoutes);
static PHP_METHOD(Phalcon_Mvc_Router, getRouteById);
static PHP_METHOD(Phalcon_Mvc_Router, getRouteByName);
static PHP_METHOD(Phalcon_Mvc_Router, isExactControllerName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, defaultRoutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_seturisource, 0, 0, 1)
	ZEND_ARG_INFO(0, uriSource)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_removeextraslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_mount, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_notfound, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_method_entry) {
	PHP_ME(Phalcon_Mvc_Router, __construct, arginfo_phalcon_mvc_router___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router, setDI, arginfo_phalcon_mvc_router_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRewriteUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setUriSource, arginfo_phalcon_mvc_router_seturisource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, removeExtraSlashes, arginfo_phalcon_mvc_router_removeextraslashes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultNamespace, arginfo_phalcon_mvc_router_setdefaultnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultModule, arginfo_phalcon_mvc_router_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultController, arginfo_phalcon_mvc_router_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaultAction, arginfo_phalcon_mvc_router_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, setDefaults, arginfo_phalcon_mvc_router_setdefaults, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getDefaults, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, handle, arginfo_phalcon_mvc_router_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, add, arginfo_phalcon_mvc_router_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addGet, arginfo_phalcon_mvc_router_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPost, arginfo_phalcon_mvc_router_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPut, arginfo_phalcon_mvc_router_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addPatch, arginfo_phalcon_mvc_router_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addDelete, arginfo_phalcon_mvc_router_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addOptions, arginfo_phalcon_mvc_router_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, addHead, arginfo_phalcon_mvc_router_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, mount, arginfo_phalcon_mvc_router_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, notFound, arginfo_phalcon_mvc_router_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getNamespaceName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getModuleName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatchedRoute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getMatches, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, wasMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteById, arginfo_phalcon_mvc_router_getroutebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, getRouteByName, arginfo_phalcon_mvc_router_getroutebyname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router, isExactControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Annotations);

static PHP_METHOD(Phalcon_Mvc_Router_Annotations, addResource);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, addModuleResource);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, handle);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, processControllerAnnotation);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, processActionAnnotation);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, setControllerSuffix);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, setActionSuffix);
static PHP_METHOD(Phalcon_Mvc_Router_Annotations, getResources);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_addmoduleresource, 0, 0, 2)
	ZEND_ARG_INFO(0, module)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, 0, 0, 2)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_processactionannotation, 0, 0, 5)
	ZEND_ARG_INFO(0, module)
	ZEND_ARG_INFO(0, namespaceName)
	ZEND_ARG_INFO(0, controller)
	ZEND_ARG_INFO(0, action)
	ZEND_ARG_OBJ_INFO(0, annotation, Phalcon\\Annotations\\Annotation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_annotations_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_annotations_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Annotations, addResource, arginfo_phalcon_mvc_router_annotations_addresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, addModuleResource, arginfo_phalcon_mvc_router_annotations_addmoduleresource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, handle, arginfo_phalcon_mvc_router_annotations_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processControllerAnnotation, arginfo_phalcon_mvc_router_annotations_processcontrollerannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, processActionAnnotation, arginfo_phalcon_mvc_router_annotations_processactionannotation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setControllerSuffix, arginfo_phalcon_mvc_router_annotations_setcontrollersuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, setActionSuffix, arginfo_phalcon_mvc_router_annotations_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Annotations, getResources, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Exception);


zend_class_entry *phalcon_mvc_router_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Group);

static PHP_METHOD(Phalcon_Mvc_Router_Group, __construct);
static PHP_METHOD(Phalcon_Mvc_Router_Group, setHostname);
static PHP_METHOD(Phalcon_Mvc_Router_Group, getHostname);
static PHP_METHOD(Phalcon_Mvc_Router_Group, setPrefix);
static PHP_METHOD(Phalcon_Mvc_Router_Group, getPrefix);
static PHP_METHOD(Phalcon_Mvc_Router_Group, beforeMatch);
static PHP_METHOD(Phalcon_Mvc_Router_Group, getBeforeMatch);
static PHP_METHOD(Phalcon_Mvc_Router_Group, setPaths);
static PHP_METHOD(Phalcon_Mvc_Router_Group, getPaths);
static PHP_METHOD(Phalcon_Mvc_Router_Group, getRoutes);
static PHP_METHOD(Phalcon_Mvc_Router_Group, add);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addGet);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addPost);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addPut);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addPatch);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addDelete);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addOptions);
static PHP_METHOD(Phalcon_Mvc_Router_Group, addHead);
static PHP_METHOD(Phalcon_Mvc_Router_Group, clear);
static PHP_METHOD(Phalcon_Mvc_Router_Group, _addRoute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_group__addroute, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_group_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Group, __construct, arginfo_phalcon_mvc_router_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Group, setHostname, arginfo_phalcon_mvc_router_group_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPrefix, arginfo_phalcon_mvc_router_group_setprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, beforeMatch, arginfo_phalcon_mvc_router_group_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, setPaths, arginfo_phalcon_mvc_router_group_setpaths, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, getRoutes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, add, arginfo_phalcon_mvc_router_group_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addGet, arginfo_phalcon_mvc_router_group_addget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPost, arginfo_phalcon_mvc_router_group_addpost, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPut, arginfo_phalcon_mvc_router_group_addput, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addPatch, arginfo_phalcon_mvc_router_group_addpatch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addDelete, arginfo_phalcon_mvc_router_group_adddelete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addOptions, arginfo_phalcon_mvc_router_group_addoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, addHead, arginfo_phalcon_mvc_router_group_addhead, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Group, _addRoute, arginfo_phalcon_mvc_router_group__addroute, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_groupinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_GroupInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_setpaths, 0, 0, 1)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_groupinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_groupinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setHostname, arginfo_phalcon_mvc_router_groupinterface_sethostname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getHostname, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPrefix, arginfo_phalcon_mvc_router_groupinterface_setprefix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPrefix, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, beforeMatch, arginfo_phalcon_mvc_router_groupinterface_beforematch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getBeforeMatch, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, setPaths, arginfo_phalcon_mvc_router_groupinterface_setpaths)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, add, arginfo_phalcon_mvc_router_groupinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addGet, arginfo_phalcon_mvc_router_groupinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPost, arginfo_phalcon_mvc_router_groupinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPut, arginfo_phalcon_mvc_router_groupinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addPatch, arginfo_phalcon_mvc_router_groupinterface_addpatch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addDelete, arginfo_phalcon_mvc_router_groupinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addOptions, arginfo_phalcon_mvc_router_groupinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, addHead, arginfo_phalcon_mvc_router_groupinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_GroupInterface, clear, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_Route);

static PHP_METHOD(Phalcon_Mvc_Router_Route, __construct);
static PHP_METHOD(Phalcon_Mvc_Router_Route, compilePattern);
static PHP_METHOD(Phalcon_Mvc_Router_Route, via);
static PHP_METHOD(Phalcon_Mvc_Router_Route, extractNamedParams);
static PHP_METHOD(Phalcon_Mvc_Router_Route, reConfigure);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getRoutePaths);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getName);
static PHP_METHOD(Phalcon_Mvc_Router_Route, setName);
static PHP_METHOD(Phalcon_Mvc_Router_Route, beforeMatch);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getBeforeMatch);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getRouteId);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getPattern);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getCompiledPattern);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getPaths);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getReversedPaths);
static PHP_METHOD(Phalcon_Mvc_Router_Route, setHttpMethods);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getHttpMethods);
static PHP_METHOD(Phalcon_Mvc_Router_Route, setHostname);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getHostname);
static PHP_METHOD(Phalcon_Mvc_Router_Route, setGroup);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getGroup);
static PHP_METHOD(Phalcon_Mvc_Router_Route, convert);
static PHP_METHOD(Phalcon_Mvc_Router_Route, getConverters);
static PHP_METHOD(Phalcon_Mvc_Router_Route, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_extractnamedparams, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_getroutepaths, 0, 0, 0)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_beforematch, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_sethostname, 0, 0, 1)
	ZEND_ARG_INFO(0, hostname)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_setgroup, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_route_convert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, converter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_route_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_Route, __construct, arginfo_phalcon_mvc_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Router_Route, compilePattern, arginfo_phalcon_mvc_router_route_compilepattern, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, via, arginfo_phalcon_mvc_router_route_via, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, extractNamedParams, arginfo_phalcon_mvc_router_route_extractnamedparams, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reConfigure, arginfo_phalcon_mvc_router_route_reconfigure, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getRoutePaths, arginfo_phalcon_mvc_router_route_getroutepaths, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setName, arginfo_phalcon_mvc_router_route_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, beforeMatch, arginfo_phalcon_mvc_router_route_beforematch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getBeforeMatch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getRouteId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getCompiledPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getReversedPaths, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHttpMethods, arginfo_phalcon_mvc_router_route_sethttpmethods, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getHttpMethods, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setHostname, arginfo_phalcon_mvc_router_route_sethostname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getHostname, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, setGroup, arginfo_phalcon_mvc_router_route_setgroup, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getGroup, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, convert, arginfo_phalcon_mvc_router_route_convert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, getConverters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_Route, reset, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_router_routeinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouteInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_via, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_reconfigure, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_router_routeinterface_sethttpmethods, 0, 0, 1)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_routeinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, __construct, arginfo_phalcon_mvc_router_routeinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, compilePattern, arginfo_phalcon_mvc_router_routeinterface_compilepattern)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, via, arginfo_phalcon_mvc_router_routeinterface_via)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, reConfigure, arginfo_phalcon_mvc_router_routeinterface_reconfigure)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setName, arginfo_phalcon_mvc_router_routeinterface_setname)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, setHttpMethods, arginfo_phalcon_mvc_router_routeinterface_sethttpmethods)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getRouteId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getCompiledPattern, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getReversedPaths, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Router_RouteInterface, getHttpMethods, NULL)
	ZEND_FENTRY(reset, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_routerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_RouterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, controllerName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, defaults, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_handle, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_add, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
	ZEND_ARG_INFO(0, httpMethods)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addget, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpost, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addput, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addpatch, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_adddelete, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_addhead, 0, 0, 1)
	ZEND_ARG_INFO(0, pattern)
	ZEND_ARG_INFO(0, paths)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_mount, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, group, Phalcon\\Mvc\\Router\\GroupInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_routerinterface_getroutebyname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultModule, arginfo_phalcon_mvc_routerinterface_setdefaultmodule)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultController, arginfo_phalcon_mvc_routerinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaultAction, arginfo_phalcon_mvc_routerinterface_setdefaultaction)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, setDefaults, arginfo_phalcon_mvc_routerinterface_setdefaults)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, handle, arginfo_phalcon_mvc_routerinterface_handle)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, add, arginfo_phalcon_mvc_routerinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addGet, arginfo_phalcon_mvc_routerinterface_addget)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPost, arginfo_phalcon_mvc_routerinterface_addpost)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPut, arginfo_phalcon_mvc_routerinterface_addput)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addPatch, arginfo_phalcon_mvc_routerinterface_addpatch)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addDelete, arginfo_phalcon_mvc_routerinterface_adddelete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addOptions, arginfo_phalcon_mvc_routerinterface_addoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, addHead, arginfo_phalcon_mvc_routerinterface_addhead)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, mount, arginfo_phalcon_mvc_routerinterface_mount)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, clear, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getModuleName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getNamespaceName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatchedRoute, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getMatches, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, wasMatched, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRoutes, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteById, arginfo_phalcon_mvc_routerinterface_getroutebyid)
	PHP_ABSTRACT_ME(Phalcon_Mvc_RouterInterface, getRouteByName, arginfo_phalcon_mvc_routerinterface_getroutebyname)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url);

static PHP_METHOD(Phalcon_Mvc_Url, setDI);
static PHP_METHOD(Phalcon_Mvc_Url, getDI);
static PHP_METHOD(Phalcon_Mvc_Url, setBaseUri);
static PHP_METHOD(Phalcon_Mvc_Url, setStaticBaseUri);
static PHP_METHOD(Phalcon_Mvc_Url, getBaseUri);
static PHP_METHOD(Phalcon_Mvc_Url, getStaticBaseUri);
static PHP_METHOD(Phalcon_Mvc_Url, setBasePath);
static PHP_METHOD(Phalcon_Mvc_Url, getBasePath);
static PHP_METHOD(Phalcon_Mvc_Url, get);
static PHP_METHOD(Phalcon_Mvc_Url, getStatic);
static PHP_METHOD(Phalcon_Mvc_Url, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setstaticbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, staticBaseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_getstatic, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_url_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_url_method_entry) {
	PHP_ME(Phalcon_Mvc_Url, setDI, arginfo_phalcon_mvc_url_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBaseUri, arginfo_phalcon_mvc_url_setbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setStaticBaseUri, arginfo_phalcon_mvc_url_setstaticbaseuri, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStaticBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, setBasePath, arginfo_phalcon_mvc_url_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getBasePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, get, arginfo_phalcon_mvc_url_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, getStatic, arginfo_phalcon_mvc_url_getstatic, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Url, path, arginfo_phalcon_mvc_url_path, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_url_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Url_Exception);


zend_class_entry *phalcon_mvc_urlinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_UrlInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbaseuri, 0, 0, 1)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_get, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_urlinterface_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_urlinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBaseUri, arginfo_phalcon_mvc_urlinterface_setbaseuri)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBaseUri, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, setBasePath, arginfo_phalcon_mvc_urlinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, getBasePath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, get, arginfo_phalcon_mvc_urlinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_UrlInterface, path, arginfo_phalcon_mvc_urlinterface_path)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_user_component_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_User_Component);


zend_class_entry *phalcon_mvc_user_module_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_User_Module);


zend_class_entry *phalcon_mvc_user_plugin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_User_Plugin);


zend_class_entry *phalcon_mvc_view_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View);

static PHP_METHOD(Phalcon_Mvc_View, getRenderLevel);
static PHP_METHOD(Phalcon_Mvc_View, getCurrentRenderLevel);
static PHP_METHOD(Phalcon_Mvc_View, getRegisteredEngines);
static PHP_METHOD(Phalcon_Mvc_View, __construct);
static PHP_METHOD(Phalcon_Mvc_View, setViewsDir);
static PHP_METHOD(Phalcon_Mvc_View, getViewsDir);
static PHP_METHOD(Phalcon_Mvc_View, setLayoutsDir);
static PHP_METHOD(Phalcon_Mvc_View, getLayoutsDir);
static PHP_METHOD(Phalcon_Mvc_View, setPartialsDir);
static PHP_METHOD(Phalcon_Mvc_View, getPartialsDir);
static PHP_METHOD(Phalcon_Mvc_View, setBasePath);
static PHP_METHOD(Phalcon_Mvc_View, setRenderLevel);
static PHP_METHOD(Phalcon_Mvc_View, disableLevel);
static PHP_METHOD(Phalcon_Mvc_View, setMainView);
static PHP_METHOD(Phalcon_Mvc_View, getMainView);
static PHP_METHOD(Phalcon_Mvc_View, setLayout);
static PHP_METHOD(Phalcon_Mvc_View, getLayout);
static PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore);
static PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore);
static PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter);
static PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter);
static PHP_METHOD(Phalcon_Mvc_View, setParamToView);
static PHP_METHOD(Phalcon_Mvc_View, setVars);
static PHP_METHOD(Phalcon_Mvc_View, setVar);
static PHP_METHOD(Phalcon_Mvc_View, getVar);
static PHP_METHOD(Phalcon_Mvc_View, getParamsToView);
static PHP_METHOD(Phalcon_Mvc_View, getControllerName);
static PHP_METHOD(Phalcon_Mvc_View, getActionName);
static PHP_METHOD(Phalcon_Mvc_View, getParams);
static PHP_METHOD(Phalcon_Mvc_View, start);
static PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines);
static PHP_METHOD(Phalcon_Mvc_View, _engineRender);
static PHP_METHOD(Phalcon_Mvc_View, registerEngines);
static PHP_METHOD(Phalcon_Mvc_View, exists);
static PHP_METHOD(Phalcon_Mvc_View, render);
static PHP_METHOD(Phalcon_Mvc_View, pick);
static PHP_METHOD(Phalcon_Mvc_View, getPartial);
static PHP_METHOD(Phalcon_Mvc_View, partial);
static PHP_METHOD(Phalcon_Mvc_View, getRender);
static PHP_METHOD(Phalcon_Mvc_View, finish);
static PHP_METHOD(Phalcon_Mvc_View, _createCache);
static PHP_METHOD(Phalcon_Mvc_View, isCaching);
static PHP_METHOD(Phalcon_Mvc_View, getCache);
static PHP_METHOD(Phalcon_Mvc_View, cache);
static PHP_METHOD(Phalcon_Mvc_View, setContent);
static PHP_METHOD(Phalcon_Mvc_View, getContent);
static PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath);
static PHP_METHOD(Phalcon_Mvc_View, disable);
static PHP_METHOD(Phalcon_Mvc_View, enable);
static PHP_METHOD(Phalcon_Mvc_View, reset);
static PHP_METHOD(Phalcon_Mvc_View, __set);
static PHP_METHOD(Phalcon_Mvc_View, __get);
static PHP_METHOD(Phalcon_Mvc_View, isDisabled);
static PHP_METHOD(Phalcon_Mvc_View, __isset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setpartialsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, partialsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_disablelevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setvars, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_getvar, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view__enginerender, 0, 0, 4)
	ZEND_ARG_INFO(0, engines)
	ZEND_ARG_INFO(0, viewPath)
	ZEND_ARG_INFO(0, silence)
	ZEND_ARG_INFO(0, mustClean)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_registerengines, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, engines, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_getpartial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_getrender, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, configCallback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_method_entry) {
	PHP_ME(Phalcon_Mvc_View, getRenderLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getCurrentRenderLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getRegisteredEngines, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, __construct, arginfo_phalcon_mvc_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View, setViewsDir, arginfo_phalcon_mvc_view_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getViewsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setLayoutsDir, arginfo_phalcon_mvc_view_setlayoutsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getLayoutsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setPartialsDir, arginfo_phalcon_mvc_view_setpartialsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getPartialsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setBasePath, arginfo_phalcon_mvc_view_setbasepath, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setRenderLevel, arginfo_phalcon_mvc_view_setrenderlevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, disableLevel, arginfo_phalcon_mvc_view_disablelevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setMainView, arginfo_phalcon_mvc_view_setmainview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getMainView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setLayout, arginfo_phalcon_mvc_view_setlayout, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getLayout, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setTemplateBefore, arginfo_phalcon_mvc_view_settemplatebefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, cleanTemplateBefore, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setTemplateAfter, arginfo_phalcon_mvc_view_settemplateafter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, cleanTemplateAfter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setParamToView, arginfo_phalcon_mvc_view_setparamtoview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setVars, arginfo_phalcon_mvc_view_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setVar, arginfo_phalcon_mvc_view_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getVar, arginfo_phalcon_mvc_view_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getParamsToView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getControllerName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getActionName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, _loadTemplateEngines, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View, _engineRender, arginfo_phalcon_mvc_view__enginerender, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View, registerEngines, arginfo_phalcon_mvc_view_registerengines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, exists, arginfo_phalcon_mvc_view_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, render, arginfo_phalcon_mvc_view_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, pick, arginfo_phalcon_mvc_view_pick, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getPartial, arginfo_phalcon_mvc_view_getpartial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, partial, arginfo_phalcon_mvc_view_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getRender, arginfo_phalcon_mvc_view_getrender, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, finish, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, _createCache, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View, isCaching, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, cache, arginfo_phalcon_mvc_view_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, setContent, arginfo_phalcon_mvc_view_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, getActiveRenderPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, disable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, enable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, __set, arginfo_phalcon_mvc_view___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, __get, arginfo_phalcon_mvc_view___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, isDisabled, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View, __isset, arginfo_phalcon_mvc_view___isset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_engine_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine);

static PHP_METHOD(Phalcon_Mvc_View_Engine, __construct);
static PHP_METHOD(Phalcon_Mvc_View_Engine, getContent);
static PHP_METHOD(Phalcon_Mvc_View_Engine, partial);
static PHP_METHOD(Phalcon_Mvc_View_Engine, getView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine, __construct, arginfo_phalcon_mvc_view_engine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, partial, arginfo_phalcon_mvc_view_engine_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_engine_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Php);

static PHP_METHOD(Phalcon_Mvc_View_Engine_Php, render);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_php_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_php_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Php, render, arginfo_phalcon_mvc_view_engine_php_render, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_engine_volt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt);

static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_render, 0, 0, 2)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_length, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_isincluded, 0, 0, 2)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, haystack)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_convertencoding, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, to)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_slice, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_sort, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setOptions, arginfo_phalcon_mvc_view_engine_volt_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getCompiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, render, arginfo_phalcon_mvc_view_engine_volt_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, length, arginfo_phalcon_mvc_view_engine_volt_length, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, isIncluded, arginfo_phalcon_mvc_view_engine_volt_isincluded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, convertEncoding, arginfo_phalcon_mvc_view_engine_volt_convertencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, slice, arginfo_phalcon_mvc_view_engine_volt_slice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, sort, arginfo_phalcon_mvc_view_engine_volt_sort, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_engine_volt_compiler_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler);

static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, option)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, 0, 0, 1)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, test, 0)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_resolvefilter, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, filter, 0)
	ZEND_ARG_INFO(0, left)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_expression, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, expr, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler__statementlistorextends, 0, 0, 1)
	ZEND_ARG_INFO(0, statements)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilecache, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilecall, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler__statementlist, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, statements, 0)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler__compilesource, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, compiledPath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_compile, 0, 0, 1)
	ZEND_ARG_INFO(0, templatePath)
	ZEND_ARG_INFO(0, extendsMode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_compiler_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, viewCode)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_compiler_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct, arginfo_phalcon_mvc_view_engine_volt_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI, arginfo_phalcon_mvc_view_engine_volt_compiler_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions, arginfo_phalcon_mvc_view_engine_volt_compiler_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setOption, arginfo_phalcon_mvc_view_engine_volt_compiler_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOption, arginfo_phalcon_mvc_view_engine_volt_compiler_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, fireExtensionEvent, arginfo_phalcon_mvc_view_engine_volt_compiler_fireextensionevent, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addExtension, arginfo_phalcon_mvc_view_engine_volt_compiler_addextension, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getExtensions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction, arginfo_phalcon_mvc_view_engine_volt_compiler_addfunction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_addfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, setUniquePrefix, arginfo_phalcon_mvc_view_engine_volt_compiler_setuniqueprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getUniquePrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader, arginfo_phalcon_mvc_view_engine_volt_compiler_attributereader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall, arginfo_phalcon_mvc_view_engine_volt_compiler_functioncall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvetest, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter, arginfo_phalcon_mvc_view_engine_volt_compiler_resolvefilter, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, expression, arginfo_phalcon_mvc_view_engine_volt_compiler_expression, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends, arginfo_phalcon_mvc_view_engine_volt_compiler__statementlistorextends, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForeach, arginfo_phalcon_mvc_view_engine_volt_compiler_compileforeach, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileForElse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileElseIf, arginfo_phalcon_mvc_view_engine_volt_compiler_compileelseif, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCache, arginfo_phalcon_mvc_view_engine_volt_compiler_compilecache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileSet, arginfo_phalcon_mvc_view_engine_volt_compiler_compileset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileDo, arginfo_phalcon_mvc_view_engine_volt_compiler_compiledo, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileReturn, arginfo_phalcon_mvc_view_engine_volt_compiler_compilereturn, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileAutoEscape, arginfo_phalcon_mvc_view_engine_volt_compiler_compileautoescape, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileEcho, arginfo_phalcon_mvc_view_engine_volt_compiler_compileecho, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileInclude, arginfo_phalcon_mvc_view_engine_volt_compiler_compileinclude, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileMacro, arginfo_phalcon_mvc_view_engine_volt_compiler_compilemacro, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileCall, arginfo_phalcon_mvc_view_engine_volt_compiler_compilecall, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList, arginfo_phalcon_mvc_view_engine_volt_compiler__statementlist, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource, arginfo_phalcon_mvc_view_engine_volt_compiler__compilesource, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString, arginfo_phalcon_mvc_view_engine_volt_compiler_compilestring, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile, arginfo_phalcon_mvc_view_engine_volt_compiler_compilefile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, compile, arginfo_phalcon_mvc_view_engine_volt_compiler_compile, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Compiler, parse, arginfo_phalcon_mvc_view_engine_volt_compiler_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_engineinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_EngineInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Phalcon\\Mvc\\ViewBaseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engineinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_INFO(0, mustClean)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engineinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, __construct, arginfo_phalcon_mvc_view_engineinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, getContent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, partial, arginfo_phalcon_mvc_view_engineinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_EngineInterface, render, arginfo_phalcon_mvc_view_engineinterface_render)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_view_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Exception);


zend_class_entry *phalcon_mvc_view_simple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Simple);

static PHP_METHOD(Phalcon_Mvc_View_Simple, getRegisteredEngines);
static PHP_METHOD(Phalcon_Mvc_View_Simple, __construct);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setViewsDir);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getViewsDir);
static PHP_METHOD(Phalcon_Mvc_View_Simple, registerEngines);
static PHP_METHOD(Phalcon_Mvc_View_Simple, _loadTemplateEngines);
static PHP_METHOD(Phalcon_Mvc_View_Simple, _internalRender);
static PHP_METHOD(Phalcon_Mvc_View_Simple, render);
static PHP_METHOD(Phalcon_Mvc_View_Simple, partial);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setCacheOptions);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getCacheOptions);
static PHP_METHOD(Phalcon_Mvc_View_Simple, _createCache);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getCache);
static PHP_METHOD(Phalcon_Mvc_View_Simple, cache);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setParamToView);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setVars);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setVar);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getVar);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getParamsToView);
static PHP_METHOD(Phalcon_Mvc_View_Simple, setContent);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getContent);
static PHP_METHOD(Phalcon_Mvc_View_Simple, getActiveRenderPath);
static PHP_METHOD(Phalcon_Mvc_View_Simple, __set);
static PHP_METHOD(Phalcon_Mvc_View_Simple, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_registerengines, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, engines, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple__internalrender, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_render, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setcacheoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setvars, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_getvar, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_simple___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_simple_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Simple, getRegisteredEngines, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __construct, arginfo_phalcon_mvc_view_simple___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Simple, setViewsDir, arginfo_phalcon_mvc_view_simple_setviewsdir, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getViewsDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, registerEngines, arginfo_phalcon_mvc_view_simple_registerengines, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, _loadTemplateEngines, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, _internalRender, arginfo_phalcon_mvc_view_simple__internalrender, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Mvc_View_Simple, render, arginfo_phalcon_mvc_view_simple_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, partial, arginfo_phalcon_mvc_view_simple_partial, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setCacheOptions, arginfo_phalcon_mvc_view_simple_setcacheoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getCacheOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, _createCache, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_View_Simple, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, cache, arginfo_phalcon_mvc_view_simple_cache, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setParamToView, arginfo_phalcon_mvc_view_simple_setparamtoview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVars, arginfo_phalcon_mvc_view_simple_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setVar, arginfo_phalcon_mvc_view_simple_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getVar, arginfo_phalcon_mvc_view_simple_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getParamsToView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, setContent, arginfo_phalcon_mvc_view_simple_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, getActiveRenderPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __set, arginfo_phalcon_mvc_view_simple___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Simple, __get, arginfo_phalcon_mvc_view_simple___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_viewbaseinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewBaseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_viewbaseinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setViewsDir, arginfo_phalcon_mvc_viewbaseinterface_setviewsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getViewsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setParamToView, arginfo_phalcon_mvc_viewbaseinterface_setparamtoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setVar, arginfo_phalcon_mvc_viewbaseinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getParamsToView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, cache, arginfo_phalcon_mvc_viewbaseinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setContent, arginfo_phalcon_mvc_viewbaseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getContent, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_mvc_viewinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayoutsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, layoutsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setpartialsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, partialsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_setlayout, 0, 0, 1)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_registerengines, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, engines, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewinterface_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_viewinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayoutsDir, arginfo_phalcon_mvc_viewinterface_setlayoutsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayoutsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setPartialsDir, arginfo_phalcon_mvc_viewinterface_setpartialsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getPartialsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setBasePath, arginfo_phalcon_mvc_viewinterface_setbasepath)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setRenderLevel, arginfo_phalcon_mvc_viewinterface_setrenderlevel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setMainView, arginfo_phalcon_mvc_viewinterface_setmainview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getMainView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setLayout, arginfo_phalcon_mvc_viewinterface_setlayout)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getLayout, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateBefore, arginfo_phalcon_mvc_viewinterface_settemplatebefore)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateBefore, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, setTemplateAfter, arginfo_phalcon_mvc_viewinterface_settemplateafter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, cleanTemplateAfter, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActionName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, registerEngines, arginfo_phalcon_mvc_viewinterface_registerengines)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, render, arginfo_phalcon_mvc_viewinterface_render)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, pick, arginfo_phalcon_mvc_viewinterface_pick)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, partial, arginfo_phalcon_mvc_viewinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, finish, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, getActiveRenderPath, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, disable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, enable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, reset, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewInterface, isDisabled, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter);

static PHP_METHOD(Phalcon_Paginator_Adapter, setCurrentPage);
static PHP_METHOD(Phalcon_Paginator_Adapter, setLimit);
static PHP_METHOD(Phalcon_Paginator_Adapter, getLimit);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limitRows)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter, setCurrentPage, arginfo_phalcon_paginator_adapter_setcurrentpage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, setLimit, arginfo_phalcon_paginator_adapter_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter, getLimit, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_adapter_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_Model);

static PHP_METHOD(Phalcon_Paginator_Adapter_Model, __construct);
static PHP_METHOD(Phalcon_Paginator_Adapter_Model, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_model___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_model_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_Model, __construct, arginfo_phalcon_paginator_adapter_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_Model, getPaginate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_adapter_nativearray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_NativeArray);

static PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, __construct);
static PHP_METHOD(Phalcon_Paginator_Adapter_NativeArray, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_nativearray_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, __construct, arginfo_phalcon_paginator_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_NativeArray, getPaginate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_adapter_querybuilder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_QueryBuilder);

static PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, __construct);
static PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage);
static PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder);
static PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder);
static PHP_METHOD(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, builder, Phalcon\\Mvc\\Model\\Query\\Builder, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapter_querybuilder_method_entry) {
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, __construct, arginfo_phalcon_paginator_adapter_querybuilder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getCurrentPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, setQueryBuilder, arginfo_phalcon_paginator_adapter_querybuilder_setquerybuilder, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getQueryBuilder, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Paginator_Adapter_QueryBuilder, getPaginate, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setcurrentpage, 0, 0, 1)
	ZEND_ARG_INFO(0, page)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_paginator_adapterinterface_setlimit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_paginator_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, __construct, arginfo_phalcon_paginator_adapterinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setCurrentPage, arginfo_phalcon_paginator_adapterinterface_setcurrentpage)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getPaginate, NULL)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, setLimit, arginfo_phalcon_paginator_adapterinterface_setlimit)
	PHP_ABSTRACT_ME(Phalcon_Paginator_AdapterInterface, getLimit, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_paginator_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Paginator_Exception);


zend_class_entry *phalcon_queue_beanstalk_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk);

static PHP_METHOD(Phalcon_Queue_Beanstalk, __construct);
static PHP_METHOD(Phalcon_Queue_Beanstalk, connect);
static PHP_METHOD(Phalcon_Queue_Beanstalk, put);
static PHP_METHOD(Phalcon_Queue_Beanstalk, reserve);
static PHP_METHOD(Phalcon_Queue_Beanstalk, choose);
static PHP_METHOD(Phalcon_Queue_Beanstalk, watch);
static PHP_METHOD(Phalcon_Queue_Beanstalk, stats);
static PHP_METHOD(Phalcon_Queue_Beanstalk, statsTube);
static PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady);
static PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried);
static PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus);
static PHP_METHOD(Phalcon_Queue_Beanstalk, readYaml);
static PHP_METHOD(Phalcon_Queue_Beanstalk, read);
static PHP_METHOD(Phalcon_Queue_Beanstalk, write);
static PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_put, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_reserve, 0, 0, 0)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_choose, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_watch, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_statstube, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_read, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_beanstalk_method_entry) {
	PHP_ME(Phalcon_Queue_Beanstalk, __construct, arginfo_phalcon_queue_beanstalk___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, put, arginfo_phalcon_queue_beanstalk_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, reserve, arginfo_phalcon_queue_beanstalk_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, choose, arginfo_phalcon_queue_beanstalk_choose, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, watch, arginfo_phalcon_queue_beanstalk_watch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, stats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, statsTube, arginfo_phalcon_queue_beanstalk_statstube, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekReady, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekBuried, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readStatus, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readYaml, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, read, arginfo_phalcon_queue_beanstalk_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, write, arginfo_phalcon_queue_beanstalk_write, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Queue_Beanstalk, disconnect, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_queue_beanstalk_job_ce;

ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk_Job);

static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getId);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, getBody);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __construct);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, delete);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, release);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, bury);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, touch);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, kick);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, stats);
static PHP_METHOD(Phalcon_Queue_Beanstalk_Job, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, queue)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job_release, 0, 0, 0)
	ZEND_ARG_INFO(0, priority)
	ZEND_ARG_INFO(0, delay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_job_bury, 0, 0, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_queue_beanstalk_job_method_entry) {
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, getBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __construct, arginfo_phalcon_queue_beanstalk_job___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, release, arginfo_phalcon_queue_beanstalk_job_release, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, bury, arginfo_phalcon_queue_beanstalk_job_bury, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, touch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, kick, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, stats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk_Job, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_registry_ce;

ZEPHIR_INIT_CLASS(Phalcon_Registry);

static PHP_METHOD(Phalcon_Registry, __construct);
static PHP_METHOD(Phalcon_Registry, offsetExists);
static PHP_METHOD(Phalcon_Registry, offsetGet);
static PHP_METHOD(Phalcon_Registry, offsetSet);
static PHP_METHOD(Phalcon_Registry, offsetUnset);
static PHP_METHOD(Phalcon_Registry, count);
static PHP_METHOD(Phalcon_Registry, next);
static PHP_METHOD(Phalcon_Registry, key);
static PHP_METHOD(Phalcon_Registry, rewind);
static PHP_METHOD(Phalcon_Registry, valid);
static PHP_METHOD(Phalcon_Registry, current);
static PHP_METHOD(Phalcon_Registry, __set);
static PHP_METHOD(Phalcon_Registry, __get);
static PHP_METHOD(Phalcon_Registry, __isset);
static PHP_METHOD(Phalcon_Registry, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_registry___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_registry_method_entry) {
	PHP_ME(Phalcon_Registry, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Registry, offsetExists, arginfo_phalcon_registry_offsetexists, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, offsetGet, arginfo_phalcon_registry_offsetget, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, offsetSet, arginfo_phalcon_registry_offsetset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, offsetUnset, arginfo_phalcon_registry_offsetunset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, next, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, key, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, rewind, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Registry, __set, arginfo_phalcon_registry___set, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, __get, arginfo_phalcon_registry___get, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, __isset, arginfo_phalcon_registry___isset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Registry, __unset, arginfo_phalcon_registry___unset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};

zend_class_entry *phalcon_security_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security);

static PHP_METHOD(Phalcon_Security, setWorkFactor);
static PHP_METHOD(Phalcon_Security, getWorkFactor);
static PHP_METHOD(Phalcon_Security, setDI);
static PHP_METHOD(Phalcon_Security, getDI);
static PHP_METHOD(Phalcon_Security, setRandomBytes);
static PHP_METHOD(Phalcon_Security, getRandomBytes);
static PHP_METHOD(Phalcon_Security, getSaltBytes);
static PHP_METHOD(Phalcon_Security, hash);
static PHP_METHOD(Phalcon_Security, checkHash);
static PHP_METHOD(Phalcon_Security, isLegacyHash);
static PHP_METHOD(Phalcon_Security, getTokenKey);
static PHP_METHOD(Phalcon_Security, getToken);
static PHP_METHOD(Phalcon_Security, checkToken);
static PHP_METHOD(Phalcon_Security, getSessionToken);
static PHP_METHOD(Phalcon_Security, destroyToken);
static PHP_METHOD(Phalcon_Security, computeHmac);
static PHP_METHOD(Phalcon_Security, setDefaultHash);
static PHP_METHOD(Phalcon_Security, getDefaultHash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 0, 1)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, randomBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_getsaltbytes, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
	ZEND_ARG_INFO(0, maxPassLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 0, 1)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checktoken, 0, 0, 0)
	ZEND_ARG_INFO(0, tokenKey)
	ZEND_ARG_INFO(0, tokenValue)
	ZEND_ARG_INFO(0, destroyIfValid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_computehmac, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdefaulthash, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHash)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_method_entry) {
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getWorkFactor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDI, arginfo_phalcon_security_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandomBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSaltBytes, arginfo_phalcon_security_getsaltbytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSessionToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, destroyToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, computeHmac, arginfo_phalcon_security_computehmac, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDefaultHash, arginfo_phalcon_security_setdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDefaultHash, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_security_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_Exception);


zend_class_entry *phalcon_session_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session);


zend_class_entry *phalcon_session_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter);

static PHP_METHOD(Phalcon_Session_Adapter, __construct);
static PHP_METHOD(Phalcon_Session_Adapter, start);
static PHP_METHOD(Phalcon_Session_Adapter, setOptions);
static PHP_METHOD(Phalcon_Session_Adapter, getOptions);
static PHP_METHOD(Phalcon_Session_Adapter, get);
static PHP_METHOD(Phalcon_Session_Adapter, set);
static PHP_METHOD(Phalcon_Session_Adapter, has);
static PHP_METHOD(Phalcon_Session_Adapter, remove);
static PHP_METHOD(Phalcon_Session_Adapter, getId);
static PHP_METHOD(Phalcon_Session_Adapter, setId);
static PHP_METHOD(Phalcon_Session_Adapter, isStarted);
static PHP_METHOD(Phalcon_Session_Adapter, destroy);
static PHP_METHOD(Phalcon_Session_Adapter, status);
static PHP_METHOD(Phalcon_Session_Adapter, __get);
static PHP_METHOD(Phalcon_Session_Adapter, __set);
static PHP_METHOD(Phalcon_Session_Adapter, __isset);
static PHP_METHOD(Phalcon_Session_Adapter, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, remove)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_setid, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_method_entry) {
	PHP_ME(Phalcon_Session_Adapter, __construct, arginfo_phalcon_session_adapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, setOptions, arginfo_phalcon_session_adapter_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, get, arginfo_phalcon_session_adapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, set, arginfo_phalcon_session_adapter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, has, arginfo_phalcon_session_adapter_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, remove, arginfo_phalcon_session_adapter_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, setId, arginfo_phalcon_session_adapter_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, isStarted, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __get, arginfo_phalcon_session_adapter___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __set, arginfo_phalcon_session_adapter___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __isset, arginfo_phalcon_session_adapter___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter, __unset, arginfo_phalcon_session_adapter___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_session_adapter_files_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Files);


zend_class_entry *phalcon_session_adapter_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Libmemcached);

static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLibmemcached);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, getLifetime);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, __construct);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, open);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, close);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, read);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, write);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, destroy);
static PHP_METHOD(Phalcon_Session_Adapter_Libmemcached, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_libmemcached_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_libmemcached_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLibmemcached, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, __construct, arginfo_phalcon_session_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, open, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, read, arginfo_phalcon_session_adapter_libmemcached_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, write, arginfo_phalcon_session_adapter_libmemcached_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, destroy, arginfo_phalcon_session_adapter_libmemcached_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Libmemcached, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_session_adapter_memcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Memcache);

static PHP_METHOD(Phalcon_Session_Adapter_Memcache, getMemcache);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, getLifetime);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, __construct);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, open);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, close);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, read);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, write);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, destroy);
static PHP_METHOD(Phalcon_Session_Adapter_Memcache, gc);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionId)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapter_memcache_destroy, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapter_memcache_method_entry) {
	PHP_ME(Phalcon_Session_Adapter_Memcache, getMemcache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, __construct, arginfo_phalcon_session_adapter_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Adapter_Memcache, open, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, read, arginfo_phalcon_session_adapter_memcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, write, arginfo_phalcon_session_adapter_memcache_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, destroy, arginfo_phalcon_session_adapter_memcache_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Adapter_Memcache, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_session_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_adapterinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, start, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, setOptions, arginfo_phalcon_session_adapterinterface_setoptions)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, get, arginfo_phalcon_session_adapterinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, set, arginfo_phalcon_session_adapterinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, has, arginfo_phalcon_session_adapterinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, remove, arginfo_phalcon_session_adapterinterface_remove)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, getId, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, isStarted, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_AdapterInterface, destroy, NULL)
	PHP_FE_END
};

zend_class_entry *phalcon_session_bag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Bag);

static PHP_METHOD(Phalcon_Session_Bag, __construct);
static PHP_METHOD(Phalcon_Session_Bag, setDI);
static PHP_METHOD(Phalcon_Session_Bag, getDI);
static PHP_METHOD(Phalcon_Session_Bag, initialize);
static PHP_METHOD(Phalcon_Session_Bag, destroy);
static PHP_METHOD(Phalcon_Session_Bag, set);
static PHP_METHOD(Phalcon_Session_Bag, __set);
static PHP_METHOD(Phalcon_Session_Bag, get);
static PHP_METHOD(Phalcon_Session_Bag, __get);
static PHP_METHOD(Phalcon_Session_Bag, has);
static PHP_METHOD(Phalcon_Session_Bag, __isset);
static PHP_METHOD(Phalcon_Session_Bag, remove);
static PHP_METHOD(Phalcon_Session_Bag, __unset);
static PHP_METHOD(Phalcon_Session_Bag, count);
static PHP_METHOD(Phalcon_Session_Bag, getIterator);
static PHP_METHOD(Phalcon_Session_Bag, offsetSet);
static PHP_METHOD(Phalcon_Session_Bag, offsetExists);
static PHP_METHOD(Phalcon_Session_Bag, offsetUnset);
static PHP_METHOD(Phalcon_Session_Bag, offsetGet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_bag_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_bag_method_entry) {
	PHP_ME(Phalcon_Session_Bag, __construct, arginfo_phalcon_session_bag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Session_Bag, setDI, arginfo_phalcon_session_bag_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, set, arginfo_phalcon_session_bag_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __set, arginfo_phalcon_session_bag___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, get, arginfo_phalcon_session_bag_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __get, arginfo_phalcon_session_bag___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, has, arginfo_phalcon_session_bag_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __isset, arginfo_phalcon_session_bag___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, remove, arginfo_phalcon_session_bag_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, __unset, arginfo_phalcon_session_bag___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Session_Bag, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Session_Bag, getIterator, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Session_Bag, offsetSet, arginfo_phalcon_session_bag_offsetset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Session_Bag, offsetExists, arginfo_phalcon_session_bag_offsetexists, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Session_Bag, offsetUnset, arginfo_phalcon_session_bag_offsetunset, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Session_Bag, offsetGet, arginfo_phalcon_session_bag_offsetget, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL)
	PHP_FE_END
};

zend_class_entry *phalcon_session_baginterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_BagInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___set, 0, 0, 2)
	ZEND_ARG_INFO(0, property)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_session_baginterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, property)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_session_baginterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, initialize, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, destroy, NULL)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, set, arginfo_phalcon_session_baginterface_set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, get, arginfo_phalcon_session_baginterface_get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, has, arginfo_phalcon_session_baginterface_has)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __set, arginfo_phalcon_session_baginterface___set)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __get, arginfo_phalcon_session_baginterface___get)
	PHP_ABSTRACT_ME(Phalcon_Session_BagInterface, __isset, arginfo_phalcon_session_baginterface___isset)
	PHP_FE_END
};

zend_class_entry *phalcon_session_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Session_Exception);


zend_class_entry *phalcon_tag_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag);

static PHP_METHOD(Phalcon_Tag, getEscaper);
static PHP_METHOD(Phalcon_Tag, renderAttributes);
static PHP_METHOD(Phalcon_Tag, setDI);
static PHP_METHOD(Phalcon_Tag, getDI);
static PHP_METHOD(Phalcon_Tag, getUrlService);
static PHP_METHOD(Phalcon_Tag, getEscaperService);
static PHP_METHOD(Phalcon_Tag, setAutoescape);
static PHP_METHOD(Phalcon_Tag, setDefault);
static PHP_METHOD(Phalcon_Tag, setDefaults);
static PHP_METHOD(Phalcon_Tag, displayTo);
static PHP_METHOD(Phalcon_Tag, hasValue);
static PHP_METHOD(Phalcon_Tag, getValue);
static PHP_METHOD(Phalcon_Tag, resetInput);
static PHP_METHOD(Phalcon_Tag, linkTo);
static PHP_METHOD(Phalcon_Tag, _inputField);
static PHP_METHOD(Phalcon_Tag, _inputFieldChecked);
static PHP_METHOD(Phalcon_Tag, colorField);
static PHP_METHOD(Phalcon_Tag, textField);
static PHP_METHOD(Phalcon_Tag, numericField);
static PHP_METHOD(Phalcon_Tag, rangeField);
static PHP_METHOD(Phalcon_Tag, emailField);
static PHP_METHOD(Phalcon_Tag, dateField);
static PHP_METHOD(Phalcon_Tag, dateTimeField);
static PHP_METHOD(Phalcon_Tag, dateTimeLocalField);
static PHP_METHOD(Phalcon_Tag, monthField);
static PHP_METHOD(Phalcon_Tag, timeField);
static PHP_METHOD(Phalcon_Tag, weekField);
static PHP_METHOD(Phalcon_Tag, passwordField);
static PHP_METHOD(Phalcon_Tag, hiddenField);
static PHP_METHOD(Phalcon_Tag, fileField);
static PHP_METHOD(Phalcon_Tag, searchField);
static PHP_METHOD(Phalcon_Tag, telField);
static PHP_METHOD(Phalcon_Tag, urlField);
static PHP_METHOD(Phalcon_Tag, checkField);
static PHP_METHOD(Phalcon_Tag, radioField);
static PHP_METHOD(Phalcon_Tag, imageInput);
static PHP_METHOD(Phalcon_Tag, submitButton);
static PHP_METHOD(Phalcon_Tag, selectStatic);
static PHP_METHOD(Phalcon_Tag, select);
static PHP_METHOD(Phalcon_Tag, textArea);
static PHP_METHOD(Phalcon_Tag, form);
static PHP_METHOD(Phalcon_Tag, endForm);
static PHP_METHOD(Phalcon_Tag, setTitle);
static PHP_METHOD(Phalcon_Tag, setTitleSeparator);
static PHP_METHOD(Phalcon_Tag, appendTitle);
static PHP_METHOD(Phalcon_Tag, prependTitle);
static PHP_METHOD(Phalcon_Tag, getTitle);
static PHP_METHOD(Phalcon_Tag, getTitleSeparator);
static PHP_METHOD(Phalcon_Tag, stylesheetLink);
static PHP_METHOD(Phalcon_Tag, javascriptInclude);
static PHP_METHOD(Phalcon_Tag, image);
static PHP_METHOD(Phalcon_Tag, friendlyTitle);
static PHP_METHOD(Phalcon_Tag, setDocType);
static PHP_METHOD(Phalcon_Tag, getDocType);
static PHP_METHOD(Phalcon_Tag, tagHtml);
static PHP_METHOD(Phalcon_Tag, tagHtmlClose);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getescaper, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_renderattributes, 0, 0, 2)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setautoescape, 0, 0, 1)
	ZEND_ARG_INFO(0, autoescape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefault, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdefaults, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, values, 0)
	ZEND_ARG_INFO(0, merge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_displayto, 0, 0, 2)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hasvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_linkto, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag__inputfield, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, asValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag__inputfieldchecked, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_colorfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_numericfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_rangefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_emailfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datetimefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_datetimelocalfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_monthfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_timefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_weekfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_passwordfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_hiddenfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_filefield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_searchfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_telfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_urlfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_checkfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_radiofield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_imageinput, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_submitbutton, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_selectstatic, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_textarea, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_form, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_settitleseparator, 0, 0, 1)
	ZEND_ARG_INFO(0, titleSeparator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_appendtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_prependtitle, 0, 0, 1)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_gettitle, 0, 0, 0)
	ZEND_ARG_INFO(0, tags)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_stylesheetlink, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_javascriptinclude, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_image, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, local)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_friendlytitle, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, separator)
	ZEND_ARG_INFO(0, lowercase)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_setdoctype, 0, 0, 1)
	ZEND_ARG_INFO(0, doctype)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtml, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, selfClose)
	ZEND_ARG_INFO(0, onlyStart)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_taghtmlclose, 0, 0, 1)
	ZEND_ARG_INFO(0, tagName)
	ZEND_ARG_INFO(0, useEol)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_tag_method_entry) {
	PHP_ME(Phalcon_Tag, getEscaper, arginfo_phalcon_tag_getescaper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, renderAttributes, arginfo_phalcon_tag_renderattributes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDI, arginfo_phalcon_tag_setdi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDI, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getUrlService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getEscaperService, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setAutoescape, arginfo_phalcon_tag_setautoescape, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefault, arginfo_phalcon_tag_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDefaults, arginfo_phalcon_tag_setdefaults, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, displayTo, arginfo_phalcon_tag_displayto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hasValue, arginfo_phalcon_tag_hasvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getValue, arginfo_phalcon_tag_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, resetInput, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, linkTo, arginfo_phalcon_tag_linkto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, _inputField, arginfo_phalcon_tag__inputfield, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Tag, _inputFieldChecked, arginfo_phalcon_tag__inputfieldchecked, ZEND_ACC_STATIC|ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Tag, colorField, arginfo_phalcon_tag_colorfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, textField, arginfo_phalcon_tag_textfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, numericField, arginfo_phalcon_tag_numericfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, rangeField, arginfo_phalcon_tag_rangefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, emailField, arginfo_phalcon_tag_emailfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateField, arginfo_phalcon_tag_datefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateTimeField, arginfo_phalcon_tag_datetimefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, dateTimeLocalField, arginfo_phalcon_tag_datetimelocalfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, monthField, arginfo_phalcon_tag_monthfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, timeField, arginfo_phalcon_tag_timefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, weekField, arginfo_phalcon_tag_weekfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, passwordField, arginfo_phalcon_tag_passwordfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, hiddenField, arginfo_phalcon_tag_hiddenfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, fileField, arginfo_phalcon_tag_filefield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, searchField, arginfo_phalcon_tag_searchfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, telField, arginfo_phalcon_tag_telfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, urlField, arginfo_phalcon_tag_urlfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, checkField, arginfo_phalcon_tag_checkfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, radioField, arginfo_phalcon_tag_radiofield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, imageInput, arginfo_phalcon_tag_imageinput, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, submitButton, arginfo_phalcon_tag_submitbutton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, selectStatic, arginfo_phalcon_tag_selectstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, select, arginfo_phalcon_tag_select, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, textArea, arginfo_phalcon_tag_textarea, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, form, arginfo_phalcon_tag_form, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, endForm, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitle, arginfo_phalcon_tag_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setTitleSeparator, arginfo_phalcon_tag_settitleseparator, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, appendTitle, arginfo_phalcon_tag_appendtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, prependTitle, arginfo_phalcon_tag_prependtitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitle, arginfo_phalcon_tag_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getTitleSeparator, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, stylesheetLink, arginfo_phalcon_tag_stylesheetlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, javascriptInclude, arginfo_phalcon_tag_javascriptinclude, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, image, arginfo_phalcon_tag_image, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, friendlyTitle, arginfo_phalcon_tag_friendlytitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, setDocType, arginfo_phalcon_tag_setdoctype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, getDocType, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtml, arginfo_phalcon_tag_taghtml, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag, tagHtmlClose, arginfo_phalcon_tag_taghtmlclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_tag_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag_Exception);


zend_class_entry *phalcon_tag_select_ce;

ZEPHIR_INIT_CLASS(Phalcon_Tag_Select);

static PHP_METHOD(Phalcon_Tag_Select, selectField);
static PHP_METHOD(Phalcon_Tag_Select, _optionsFromResultset);
static PHP_METHOD(Phalcon_Tag_Select, _optionsFromArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select_selectfield, 0, 0, 1)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select__optionsfromresultset, 0, 0, 4)
	ZEND_ARG_INFO(0, resultset)
	ZEND_ARG_INFO(0, using)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, closeOption)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_tag_select__optionsfromarray, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, closeOption)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_tag_select_method_entry) {
	PHP_ME(Phalcon_Tag_Select, selectField, arginfo_phalcon_tag_select_selectfield, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, _optionsFromResultset, arginfo_phalcon_tag_select__optionsfromresultset, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Tag_Select, _optionsFromArray, arginfo_phalcon_tag_select__optionsfromarray, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_text_ce;

ZEPHIR_INIT_CLASS(Phalcon_Text);

static PHP_METHOD(Phalcon_Text, camelize);
static PHP_METHOD(Phalcon_Text, uncamelize);
static PHP_METHOD(Phalcon_Text, increment);
static PHP_METHOD(Phalcon_Text, random);
static PHP_METHOD(Phalcon_Text, startsWith);
static PHP_METHOD(Phalcon_Text, endsWith);
static PHP_METHOD(Phalcon_Text, lower);
static PHP_METHOD(Phalcon_Text, upper);
static PHP_METHOD(Phalcon_Text, reduceSlashes);
static PHP_METHOD(Phalcon_Text, concat);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_increment, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_random, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, end)
	ZEND_ARG_INFO(0, ignoreCase)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_lower, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_upper, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, encoding)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_text_reduceslashes, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_text_method_entry) {
	PHP_ME(Phalcon_Text, camelize, arginfo_phalcon_text_camelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, uncamelize, arginfo_phalcon_text_uncamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, increment, arginfo_phalcon_text_increment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, random, arginfo_phalcon_text_random, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, startsWith, arginfo_phalcon_text_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, endsWith, arginfo_phalcon_text_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, lower, arginfo_phalcon_text_lower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, upper, arginfo_phalcon_text_upper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, reduceSlashes, arginfo_phalcon_text_reduceslashes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Text, concat, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate);


zend_class_entry *phalcon_translate_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter);

static PHP_METHOD(Phalcon_Translate_Adapter, t);
static PHP_METHOD(Phalcon_Translate_Adapter, _);
static PHP_METHOD(Phalcon_Translate_Adapter, offsetSet);
static PHP_METHOD(Phalcon_Translate_Adapter, offsetExists);
static PHP_METHOD(Phalcon_Translate_Adapter, offsetUnset);
static PHP_METHOD(Phalcon_Translate_Adapter, offsetGet);
static PHP_METHOD(Phalcon_Translate_Adapter, replacePlaceholders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_t, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter__, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_replaceplaceholders, 0, 0, 1)
	ZEND_ARG_INFO(0, translation)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter, t, arginfo_phalcon_translate_adapter_t, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, _, arginfo_phalcon_translate_adapter__, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetSet, arginfo_phalcon_translate_adapter_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetExists, arginfo_phalcon_translate_adapter_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetUnset, arginfo_phalcon_translate_adapter_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, offsetGet, arginfo_phalcon_translate_adapter_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter, replacePlaceholders, arginfo_phalcon_translate_adapter_replaceplaceholders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_adapter_csv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Csv);

static PHP_METHOD(Phalcon_Translate_Adapter_Csv, __construct);
static PHP_METHOD(Phalcon_Translate_Adapter_Csv, query);
static PHP_METHOD(Phalcon_Translate_Adapter_Csv, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_csv_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_csv_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Csv, __construct, arginfo_phalcon_translate_adapter_csv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Csv, query, arginfo_phalcon_translate_adapter_csv_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Csv, exists, arginfo_phalcon_translate_adapter_csv_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_adapter_gettext_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_Gettext);

static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, __construct);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, query);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, exists);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, nquery);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDomain);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, resetDomain);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDefaultDomain);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDefaultDomain);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setDirectory);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getDirectory);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, setLocale);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getLocale);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getCategory);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, prepareOptions);
static PHP_METHOD(Phalcon_Translate_Adapter_Gettext, getOptionsDefault);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_nquery, 0, 0, 3)
	ZEND_ARG_INFO(0, msgid1)
	ZEND_ARG_INFO(0, msgid2)
	ZEND_ARG_INFO(0, count)
	ZEND_ARG_INFO(0, placeholders)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, 0, 0, 1)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_getdirectory, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_setlocale, 0, 0, 2)
	ZEND_ARG_INFO(0, category)
	ZEND_ARG_INFO(0, locale)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_gettext_prepareoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_gettext_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_Gettext, __construct, arginfo_phalcon_translate_adapter_gettext___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, query, arginfo_phalcon_translate_adapter_gettext_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, exists, arginfo_phalcon_translate_adapter_gettext_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, nquery, arginfo_phalcon_translate_adapter_gettext_nquery, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDomain, arginfo_phalcon_translate_adapter_gettext_setdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, resetDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDefaultDomain, arginfo_phalcon_translate_adapter_gettext_setdefaultdomain, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDefaultDomain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setDirectory, arginfo_phalcon_translate_adapter_gettext_setdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getDirectory, arginfo_phalcon_translate_adapter_gettext_getdirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, setLocale, arginfo_phalcon_translate_adapter_gettext_setlocale, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getLocale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getCategory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, prepareOptions, arginfo_phalcon_translate_adapter_gettext_prepareoptions, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Translate_Adapter_Gettext, getOptionsDefault, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_adapter_nativearray_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_NativeArray);

static PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, __construct);
static PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, query);
static PHP_METHOD(Phalcon_Translate_Adapter_NativeArray, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapter_nativearray_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapter_nativearray_method_entry) {
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, __construct, arginfo_phalcon_translate_adapter_nativearray___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, query, arginfo_phalcon_translate_adapter_nativearray_query, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Translate_Adapter_NativeArray, exists, arginfo_phalcon_translate_adapter_nativearray_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_AdapterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_t, 0, 0, 1)
	ZEND_ARG_INFO(0, translateKey)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_query, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, placeholders)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_translate_adapterinterface_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_translate_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, t, arginfo_phalcon_translate_adapterinterface_t)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, query, arginfo_phalcon_translate_adapterinterface_query)
	PHP_ABSTRACT_ME(Phalcon_Translate_AdapterInterface, exists, arginfo_phalcon_translate_adapterinterface_exists)
	PHP_FE_END
};

zend_class_entry *phalcon_translate_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Translate_Exception);


zend_class_entry *phalcon_validation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation);

static PHP_METHOD(Phalcon_Validation, setValidators);
static PHP_METHOD(Phalcon_Validation, __construct);
static PHP_METHOD(Phalcon_Validation, validate);
static PHP_METHOD(Phalcon_Validation, add);
static PHP_METHOD(Phalcon_Validation, rule);
static PHP_METHOD(Phalcon_Validation, rules);
static PHP_METHOD(Phalcon_Validation, setFilters);
static PHP_METHOD(Phalcon_Validation, getFilters);
static PHP_METHOD(Phalcon_Validation, getValidators);
static PHP_METHOD(Phalcon_Validation, getEntity);
static PHP_METHOD(Phalcon_Validation, setDefaultMessages);
static PHP_METHOD(Phalcon_Validation, getDefaultMessage);
static PHP_METHOD(Phalcon_Validation, getMessages);
static PHP_METHOD(Phalcon_Validation, setLabels);
static PHP_METHOD(Phalcon_Validation, getLabel);
static PHP_METHOD(Phalcon_Validation, appendMessage);
static PHP_METHOD(Phalcon_Validation, bind);
static PHP_METHOD(Phalcon_Validation, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setvalidators, 0, 0, 1)
	ZEND_ARG_INFO(0, validators)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, validators, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validate, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_add, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_rule, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Validation\\ValidatorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_rules, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_ARRAY_INFO(0, validators, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setfilters, 0, 0, 2)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getfilters, 0, 0, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setdefaultmessages, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, messages, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getdefaultmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setlabels, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getlabel, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_bind, 0, 0, 2)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_method_entry) {
	PHP_ME(Phalcon_Validation, setValidators, arginfo_phalcon_validation_setvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, __construct, arginfo_phalcon_validation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation, validate, arginfo_phalcon_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, add, arginfo_phalcon_validation_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, rule, arginfo_phalcon_validation_rule, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, rules, arginfo_phalcon_validation_rules, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setFilters, arginfo_phalcon_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getFilters, arginfo_phalcon_validation_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValidators, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setDefaultMessages, arginfo_phalcon_validation_setdefaultmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getDefaultMessage, arginfo_phalcon_validation_getdefaultmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setLabels, arginfo_phalcon_validation_setlabels, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getLabel, arginfo_phalcon_validation_getlabel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, appendMessage, arginfo_phalcon_validation_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, bind, arginfo_phalcon_validation_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValue, arginfo_phalcon_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Exception);


zend_class_entry *phalcon_validation_message_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Message);

static PHP_METHOD(Phalcon_Validation_Message, __construct);
static PHP_METHOD(Phalcon_Validation_Message, setType);
static PHP_METHOD(Phalcon_Validation_Message, getType);
static PHP_METHOD(Phalcon_Validation_Message, setMessage);
static PHP_METHOD(Phalcon_Validation_Message, getMessage);
static PHP_METHOD(Phalcon_Validation_Message, setField);
static PHP_METHOD(Phalcon_Validation_Message, getField);
static PHP_METHOD(Phalcon_Validation_Message, __toString);
static PHP_METHOD(Phalcon_Validation_Message, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_message_method_entry) {
	PHP_ME(Phalcon_Validation_Message, __construct, arginfo_phalcon_validation_message___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Message, setType, arginfo_phalcon_validation_message_settype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, setMessage, arginfo_phalcon_validation_message_setmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, setField, arginfo_phalcon_validation_message_setfield, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, getField, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message, __set_state, arginfo_phalcon_validation_message___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_message_group_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Message_Group);

static PHP_METHOD(Phalcon_Validation_Message_Group, __construct);
static PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet);
static PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet);
static PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists);
static PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset);
static PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage);
static PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages);
static PHP_METHOD(Phalcon_Validation_Message_Group, filter);
static PHP_METHOD(Phalcon_Validation_Message_Group, count);
static PHP_METHOD(Phalcon_Validation_Message_Group, rewind);
static PHP_METHOD(Phalcon_Validation_Message_Group, current);
static PHP_METHOD(Phalcon_Validation_Message_Group, key);
static PHP_METHOD(Phalcon_Validation_Message_Group, next);
static PHP_METHOD(Phalcon_Validation_Message_Group, valid);
static PHP_METHOD(Phalcon_Validation_Message_Group, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_appendmessage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, message, Phalcon\\Validation\\MessageInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_appendmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, fieldName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_message_group_method_entry) {
	PHP_ME(Phalcon_Validation_Message_Group, __construct, arginfo_phalcon_validation_message_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Message_Group, offsetGet, arginfo_phalcon_validation_message_group_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetSet, arginfo_phalcon_validation_message_group_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetExists, arginfo_phalcon_validation_message_group_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetUnset, arginfo_phalcon_validation_message_group_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, appendMessage, arginfo_phalcon_validation_message_group_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, appendMessages, arginfo_phalcon_validation_message_group_appendmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, filter, arginfo_phalcon_validation_message_group_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, __set_state, arginfo_phalcon_validation_message_group___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_messageinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_MessageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_settype, 0, 0, 1)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface_setfield, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_messageinterface___set_state, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_messageinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __construct, arginfo_phalcon_validation_messageinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setType, arginfo_phalcon_validation_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setMessage, arginfo_phalcon_validation_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setField, arginfo_phalcon_validation_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __toString, NULL)
	ZEND_FENTRY(__set_state, NULL, arginfo_phalcon_validation_messageinterface___set_state, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator);

static PHP_METHOD(Phalcon_Validation_Validator, __construct);
static PHP_METHOD(Phalcon_Validation_Validator, isSetOption);
static PHP_METHOD(Phalcon_Validation_Validator, hasOption);
static PHP_METHOD(Phalcon_Validation_Validator, getOption);
static PHP_METHOD(Phalcon_Validation_Validator, setOption);
static PHP_METHOD(Phalcon_Validation_Validator, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_hasoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_method_entry) {
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validator_issetoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, hasOption, arginfo_phalcon_validation_validator_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, getOption, arginfo_phalcon_validation_validator_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, setOption, arginfo_phalcon_validation_validator_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, validate, arginfo_phalcon_validation_validator_validate, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_alnum_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Alnum);

static PHP_METHOD(Phalcon_Validation_Validator_Alnum, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_alnum_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_alnum_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Alnum, validate, arginfo_phalcon_validation_validator_alnum_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_alpha_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Alpha);

static PHP_METHOD(Phalcon_Validation_Validator_Alpha, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_alpha_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_alpha_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Alpha, validate, arginfo_phalcon_validation_validator_alpha_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_between_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Between);

static PHP_METHOD(Phalcon_Validation_Validator_Between, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_between_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_between_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Between, validate, arginfo_phalcon_validation_validator_between_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_confirmation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation);

static PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate);
static PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_confirmation_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_confirmation_compare, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_confirmation_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Confirmation, validate, arginfo_phalcon_validation_validator_confirmation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_Confirmation, compare, arginfo_phalcon_validation_validator_confirmation_compare, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_digit_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Digit);

static PHP_METHOD(Phalcon_Validation_Validator_Digit, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_digit_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_digit_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Digit, validate, arginfo_phalcon_validation_validator_digit_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_email_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Email);

static PHP_METHOD(Phalcon_Validation_Validator_Email, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_email_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_email_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Email, validate, arginfo_phalcon_validation_validator_email_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_exclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn);

static PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_exclusionin_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_exclusionin_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_ExclusionIn, validate, arginfo_phalcon_validation_validator_exclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File);

static PHP_METHOD(Phalcon_Validation_Validator_File, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_file_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_file_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_File, validate, arginfo_phalcon_validation_validator_file_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_identical_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Identical);

static PHP_METHOD(Phalcon_Validation_Validator_Identical, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_identical_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_identical_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Identical, validate, arginfo_phalcon_validation_validator_identical_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_inclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_InclusionIn);

static PHP_METHOD(Phalcon_Validation_Validator_InclusionIn, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_inclusionin_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_inclusionin_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_InclusionIn, validate, arginfo_phalcon_validation_validator_inclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_numericality_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Numericality);

static PHP_METHOD(Phalcon_Validation_Validator_Numericality, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_numericality_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_numericality_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Numericality, validate, arginfo_phalcon_validation_validator_numericality_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_presenceof_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_PresenceOf);

static PHP_METHOD(Phalcon_Validation_Validator_PresenceOf, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_presenceof_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_presenceof_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_PresenceOf, validate, arginfo_phalcon_validation_validator_presenceof_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_regex_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Regex);

static PHP_METHOD(Phalcon_Validation_Validator_Regex, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_regex_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_regex_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Regex, validate, arginfo_phalcon_validation_validator_regex_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_stringlength_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength);

static PHP_METHOD(Phalcon_Validation_Validator_StringLength, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_stringlength_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_stringlength_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_StringLength, validate, arginfo_phalcon_validation_validator_stringlength_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_uniqueness_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness);

static PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_uniqueness_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_uniqueness_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Uniqueness, validate, arginfo_phalcon_validation_validator_uniqueness_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validator_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Url);

static PHP_METHOD(Phalcon_Validation_Validator_Url, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_url_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_url_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Url, validate, arginfo_phalcon_validation_validator_url_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_validation_validatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_ValidatorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_hasoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validatorinterface_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, isSetOption, arginfo_phalcon_validation_validatorinterface_issetoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, hasOption, arginfo_phalcon_validation_validatorinterface_hasoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, getOption, arginfo_phalcon_validation_validatorinterface_getoption)
	PHP_ABSTRACT_ME(Phalcon_Validation_ValidatorInterface, validate, arginfo_phalcon_validation_validatorinterface_validate)
	PHP_FE_END
};

zend_class_entry *phalcon_version_ce;

ZEPHIR_INIT_CLASS(Phalcon_Version);

static PHP_METHOD(Phalcon_Version, _getVersion);
static PHP_METHOD(Phalcon_Version, _getSpecial);
static PHP_METHOD(Phalcon_Version, get);
static PHP_METHOD(Phalcon_Version, getId);
static PHP_METHOD(Phalcon_Version, getPart);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_version__getspecial, 0, 0, 1)
	ZEND_ARG_INFO(0, special)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_version_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, part)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_version_method_entry) {
	PHP_ME(Phalcon_Version, _getVersion, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, _getSpecial, arginfo_phalcon_version__getspecial, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Version, getPart, arginfo_phalcon_version_getpart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

#endif