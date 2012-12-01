
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_acl_adapter_memory_ce;

PHALCON_INIT_CLASS(Phalcon_Acl_Adapter_Memory);

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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList);

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_memory_addresource, 0, 0, 1)
	ZEND_ARG_INFO(0, resource)
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
	ZEND_ARG_INFO(0, role)
	ZEND_ARG_INFO(0, resource)
	ZEND_ARG_INFO(0, access)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_acl_adapter_memory_method_entry){
	PHP_ME(Phalcon_Acl_Adapter_Memory, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addRole, arginfo_phalcon_acl_adapter_memory_addrole, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addInherit, arginfo_phalcon_acl_adapter_memory_addinherit, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isRole, arginfo_phalcon_acl_adapter_memory_isrole, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isResource, arginfo_phalcon_acl_adapter_memory_isresource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResource, arginfo_phalcon_acl_adapter_memory_addresource, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, addResourceAccess, arginfo_phalcon_acl_adapter_memory_addresourceaccess, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, dropResourceAccess, arginfo_phalcon_acl_adapter_memory_dropresourceaccess, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, _allowOrDeny, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, allow, arginfo_phalcon_acl_adapter_memory_allow, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, deny, arginfo_phalcon_acl_adapter_memory_deny, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, isAllowed, arginfo_phalcon_acl_adapter_memory_isallowed, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Acl_Adapter_Memory, _rebuildAccessList, NULL, ZEND_ACC_PROTECTED) 
	PHP_FE_END
};

