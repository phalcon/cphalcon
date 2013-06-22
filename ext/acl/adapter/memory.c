
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 *
 *	$acl = new Phalcon\Acl\Adapter\Memory();
 *
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Register roles
 *	$roles = array(
 *		'users' => new Phalcon\Acl\Role('Users'),
 *		'guests' => new Phalcon\Acl\Role('Guests')
 *	);
 *	foreach ($roles as $role) {
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *  $privateResources = array(
 *		'companies' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'products' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'invoices' => array('index', 'profile')
 *	);
 *	foreach ($privateResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Public area resources
 *	$publicResources = array(
 *		'index' => array('index'),
 *		'about' => array('index'),
 *		'session' => array('index', 'register', 'start', 'end'),
 *		'contact' => array('index', 'send')
 *	);
 *  foreach ($publicResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *  //Grant access to public areas to both users and guests
 *	foreach ($roles as $role){
 *		foreach ($publicResources as $resource => $actions) {
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant access to private area to role Users
 *  foreach ($privateResources as $resource => $actions) {
 * 		foreach ($actions as $action) {
 *			$acl->allow('Users', $resource, $action);
 *		}
 *	}
 *
 *</code>
 */


/**
 * Phalcon\Acl\Adapter\Memory initializer
 */
PHALCON_INIT_CLASS(Phalcon_Acl_Adapter_Memory){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, acl_adapter_memory, "phalcon\\acl\\adapter", phalcon_acl_adapter_memory_method_entry, 0);

	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_adapter_memory_ce TSRMLS_CC, 1, phalcon_acl_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_access") TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init_size(a0, 1);
	add_assoc_bool_ex(a0, SS("*"), 1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_resourcesNames"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init_size(a1, 1);
	
	PHALCON_INIT_VAR(a2);
	array_init_size(a2, 1);
	add_assoc_bool_ex(a2, SS("*"), 1);
	phalcon_array_update_string(&a1, SL("*"), &a2, PH_COPY | PH_SEPARATE TSRMLS_CC);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_accessList"), a1 TSRMLS_CC);
	

	PHALCON_MM_RESTORE();
}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * Example:
 * <code>
 * 	$acl->addRole(new Phalcon\Acl\Role('administrator'), 'consultant');
 * 	$acl->addRole('administrator', 'consultant');
 * </code>
 *
 * @param  Phalcon\Acl\RoleInterface $role
 * @param  array|string $accessInherits
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole){

	zval *role, *access_inherits = NULL, *role_name = NULL, *object = NULL;
	zval *roles_names, *exists, *default_access;
	zval *_access, *success;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &role, &access_inherits);
	
	if (!access_inherits) {
		PHALCON_INIT_VAR(access_inherits);
	}
	
	if (Z_TYPE_P(role) == IS_OBJECT) {
		PHALCON_INIT_VAR(role_name);
		phalcon_call_method(role_name, role, "getname");
		PHALCON_CPY_WRT(object, role);
	} else {
		PHALCON_CPY_WRT(role_name, role);
	
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_role_ce);
		phalcon_call_method_p1_noret(object, "__construct", role);
	
	}
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (phalcon_array_isset(roles_names, role_name)) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_INIT_VAR(exists);
	ZVAL_BOOL(exists, 1);
	phalcon_update_property_array_append(this_ptr, SL("_roles"), object TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_rolesNames"), role_name, exists TSRMLS_CC);
	
	PHALCON_OBS_VAR(default_access);
	phalcon_read_property_this(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(_access);
	phalcon_read_property_this(&_access, this_ptr, SL("_access"), PH_NOISY_CC);
	phalcon_array_update_zval_string_string_multi_3(&_access, role_name, SL("*"), SL("*"), &default_access, 0 TSRMLS_CC);
	if (Z_TYPE_P(access_inherits) != IS_NULL) {
		PHALCON_INIT_VAR(success);
		phalcon_call_method_p2(success, this_ptr, "addinherit", role_name, access_inherits);
		RETURN_CCTOR(success);
	}
	
	RETURN_MM_TRUE;
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *role_name, *role_to_inherit, *roles_names;
	zval *exception_message = NULL, *role_inherit_name = NULL;
	zval *roles_inherits, *empty_arr, *_roleInherits;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &role_name, &role_to_inherit);
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(roles_names, role_name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role '", role_name, "' does not exist in the role list");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	if (Z_TYPE_P(role_to_inherit) == IS_OBJECT) {
		PHALCON_INIT_VAR(role_inherit_name);
		phalcon_call_method(role_inherit_name, role_to_inherit, "getname");
	} else {
		PHALCON_CPY_WRT(role_inherit_name, role_to_inherit);
	}
	
	/** 
	 * Check if the role to inherit is valid
	 */
	if (!phalcon_array_isset(roles_names, role_inherit_name)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role '", role_inherit_name, "' (to inherit) does not exist in the role list");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	if (PHALCON_IS_EQUAL(role_inherit_name, role_name)) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_OBS_VAR(roles_inherits);
	phalcon_read_property_this(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (!phalcon_array_isset(roles_inherits, role_name)) {
		PHALCON_INIT_VAR(empty_arr);
		array_init(empty_arr);
		phalcon_update_property_array(this_ptr, SL("_roleInherits"), role_name, empty_arr TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(_roleInherits);
	phalcon_read_property_this(&_roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	phalcon_array_update_append_multi_2(&_roleInherits, role_name, role_inherit_name, 0 TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_roleInherits"), _roleInherits TSRMLS_CC);
	
	/** 
	 * Re-build the access list with its inherited roles
	 */
	phalcon_call_method_noret(this_ptr, "_rebuildaccesslist");
	RETURN_MM_TRUE;
}

/**
 * Check whether role exist in the roles list
 *
 * @param  string $roleName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole){

	zval *role_name, *roles_names, *is_role = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &role_name);
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(roles_names, role_name));
	PHALCON_CPY_WRT(is_role, r0);
	RETURN_NCTOR(is_role);
}

/**
 * Check whether resource exist in the resources list
 *
 * @param  string $resourceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource){

	zval *resource_name, *resources_names, *is_resource = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &resource_name);
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(resources_names, resource_name));
	PHALCON_CPY_WRT(is_resource, r0);
	RETURN_NCTOR(is_resource);
}

/**
 * Adds a resource to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * <code>
 * //Add a resource to the the list allowing access to an action
 * $acl->addResource(new Phalcon\Acl\Resource('customers'), 'search');
 * $acl->addResource('customers', 'search');
 *
 * //Add a resource  with an access list
 * $acl->addResource(new Phalcon\Acl\Resource('customers'), array('create', 'search'));
 * $acl->addResource('customers', array('create', 'search'));
 * </code>
 *
 * @param   Phalcon\Acl\Resource $resource
 * @param   array $accessList
 * @return  boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource){

	zval *resource, *access_list = NULL, *resource_name = NULL;
	zval *object = NULL, *resources_names, *exists, *empty_arr;
	zval *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &resource, &access_list);
	
	if (!access_list) {
		PHALCON_INIT_VAR(access_list);
	}
	
	if (Z_TYPE_P(resource) == IS_OBJECT) {
		PHALCON_INIT_VAR(resource_name);
		phalcon_call_method(resource_name, resource, "getname");
		PHALCON_CPY_WRT(object, resource);
	} else {
		PHALCON_CPY_WRT(resource_name, resource);
	
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_resource_ce);
		phalcon_call_method_p1_noret(object, "__construct", resource_name);
	
	}
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(resources_names, resource_name)) {
		PHALCON_INIT_VAR(exists);
		ZVAL_BOOL(exists, 1);
		phalcon_update_property_array_append(this_ptr, SL("_resources"), object TSRMLS_CC);
	
		PHALCON_INIT_VAR(empty_arr);
		array_init(empty_arr);
		phalcon_update_property_array(this_ptr, SL("_accessList"), resource_name, empty_arr TSRMLS_CC);
		phalcon_update_property_array(this_ptr, SL("_resourcesNames"), resource_name, exists TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(status);
	phalcon_call_method_p2(status, this_ptr, "addresourceaccess", resource_name, access_list);
	
	RETURN_CCTOR(status);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *resource_name, *access_list, *resources_names;
	zval *exception_message, *exists, *access_name = NULL;
	zval *internal_access_list = NULL, *_accessList = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &resource_name, &access_list);
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(resources_names, resource_name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource '", resource_name, "' does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(exists);
	ZVAL_BOOL(exists, 1);
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		phalcon_is_iterable(access_list, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_OBS_NVAR(internal_access_list);
			phalcon_read_property_this(&internal_access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(r0);
			phalcon_array_fetch(&r0, internal_access_list, resource_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r0, access_name)) {
				PHALCON_OBS_NVAR(_accessList);
				phalcon_read_property_this(&_accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
				phalcon_array_update_multi_2(&_accessList, resource_name, access_name, &exists, 0 TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_accessList"), _accessList TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		if (Z_TYPE_P(access_list) == IS_STRING) {
	
			PHALCON_OBS_VAR(t0);
			phalcon_read_property_this(&t0, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_OBS_VAR(r1);
			phalcon_array_fetch(&r1, t0, resource_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r1, access_list)) {
				PHALCON_OBS_VAR(t1);
				phalcon_read_property_this(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
				phalcon_array_update_multi_2(&t1, resource_name, access_list, &exists, 0 TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_accessList"), t1 TSRMLS_CC);
			}
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Removes an access from a resource
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess){

	zval *resource_name, *access_list, *access_name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &resource_name, &access_list);
	
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		phalcon_is_iterable(access_list, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_OBS_NVAR(t0);
			phalcon_read_property_this(&t0, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_OBS_NVAR(r0);
			phalcon_array_fetch(&r0, t0, resource_name, PH_NOISY_CC);
			phalcon_array_unset(&r0, access_name, PH_SEPARATE);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		if (zend_is_true(access_list)) {
			PHALCON_OBS_VAR(t1);
			phalcon_read_property_this(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_OBS_VAR(r1);
			phalcon_array_fetch(&r1, t1, resource_name, PH_NOISY_CC);
			phalcon_array_unset(&r1, access_list, PH_SEPARATE);
		}
	}
	phalcon_call_method_noret(this_ptr, "_rebuildaccesslist");
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if a role has access to a resource
 *
 * @param string $roleName
 * @param string $resourceName
 * @param string $access
 * @param string $action
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny){

	zval *role_name, *resource_name, *access, *action;
	zval *roles_names, *exception_message = NULL, *resources_names;
	zval *default_access, *access_list, *access_name = NULL;
	zval *empty_arr = NULL, *_access = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 4, 0, &role_name, &resource_name, &access, &action);
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(roles_names, role_name)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role \"", role_name, "\" does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(resources_names, resource_name)) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource \"", resource_name, "\" does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(default_access);
	phalcon_read_property_this(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(access_list);
		phalcon_read_property_this(&access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	
		phalcon_is_iterable(access, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_OBS_NVAR(r0);
			phalcon_array_fetch(&r0, access_list, resource_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r0, access_name)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access_name, "' does not exist in resource '", resource_name, "' in ACL");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_is_iterable(access, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_OBS_NVAR(t0);
			phalcon_read_property_this(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
			PHALCON_OBS_NVAR(r1);
			phalcon_array_fetch(&r1, t0, role_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r1, resource_name)) {
				PHALCON_INIT_NVAR(empty_arr);
				array_init(empty_arr);
	
				PHALCON_OBS_NVAR(_access);
				phalcon_read_property_this(&_access, this_ptr, SL("_access"), PH_NOISY_CC);
				phalcon_array_update_multi_2(&_access, role_name, resource_name, &empty_arr, 0 TSRMLS_CC);
				phalcon_update_property_this(this_ptr, SL("_access"), _access TSRMLS_CC);
			}
	
			PHALCON_OBS_NVAR(t1);
			phalcon_read_property_this(&t1, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_zval_zval_zval_multi_3(&t1, role_name, resource_name, access_name, &action, 0 TSRMLS_CC);
	
			PHALCON_OBS_NVAR(t2);
			phalcon_read_property_this(&t2, this_ptr, SL("_access"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(r2);
			phalcon_array_fetch(&r2, t2, role_name, PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(r3);
			phalcon_array_fetch(&r3, r2, resource_name, PH_NOISY_CC);
			if (!phalcon_array_isset_string(r3, SS("*"))) {
				PHALCON_OBS_NVAR(t3);
				phalcon_read_property_this(&t3, this_ptr, SL("_access"), PH_NOISY_CC);
				phalcon_array_update_string_zval_zval_multi_3(&t3, role_name, resource_name, SL("*"), &default_access, 0 TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	} else {
		if (!PHALCON_IS_STRING(access, "*")) {
	
			PHALCON_OBS_VAR(t4);
			phalcon_read_property_this(&t4, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_OBS_VAR(r4);
			phalcon_array_fetch(&r4, t4, resource_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r4, access)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access, "' does not exist in resource '", resource_name, "' in ACL");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
		}
	
		PHALCON_OBS_VAR(t5);
		phalcon_read_property_this(&t5, this_ptr, SL("_access"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(r5);
		phalcon_array_fetch(&r5, t5, role_name, PH_NOISY_CC);
		if (!phalcon_array_isset(r5, resource_name)) {
			PHALCON_INIT_NVAR(empty_arr);
			array_init(empty_arr);
	
			PHALCON_OBS_VAR(t6);
			phalcon_read_property_this(&t6, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_multi_2(&t6, role_name, resource_name, &empty_arr, 0 TSRMLS_CC);
			phalcon_update_property_this(this_ptr, SL("_access"), t6 TSRMLS_CC);
		}
	
		PHALCON_OBS_VAR(t7);
		phalcon_read_property_this(&t7, this_ptr, SL("_access"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(r6);
		phalcon_array_fetch(&r6, t7, role_name, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(r7);
		phalcon_array_fetch(&r7, r6, resource_name, PH_NOISY_CC);
		if (!phalcon_array_isset_string(r7, SS("*"))) {
			PHALCON_OBS_VAR(t8);
			phalcon_read_property_this(&t8, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_string_zval_zval_multi_3(&t8, role_name, resource_name, SL("*"), &default_access, 0 TSRMLS_CC);
		}
	
		PHALCON_OBS_VAR(t9);
		phalcon_read_property_this(&t9, this_ptr, SL("_access"), PH_NOISY_CC);
		phalcon_array_update_zval_zval_zval_multi_3(&t9, role_name, resource_name, access, &action, 0 TSRMLS_CC);
	}
	
	phalcon_call_method_noret(this_ptr, "_rebuildaccesslist");
	
	PHALCON_MM_RESTORE();
}

/**
 * Allow access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Allow access to guests to search on customers
 * $acl->allow('guests', 'customers', 'search');
 *
 * //Allow access to guests to search or create on customers
 * $acl->allow('guests', 'customers', array('search', 'create'));
 *
 * //Allow access to any role to browse on products
 * $acl->allow('*', 'products', 'browse');
 *
 * //Allow access to any role to browse on any resource
 * $acl->allow('*', '*', 'browse');
 * </code>
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow){

	zval *role_name, *resource_name, *access, *action;
	zval *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &role_name, &resource_name, &access);
	
	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 1);
	
	PHALCON_INIT_VAR(status);
	phalcon_call_method_p4(status, this_ptr, "_allowordeny", role_name, resource_name, access, action);
	RETURN_CCTOR(status);
}

/**
 * Deny access to a role on a resource
 *
 * You can use '*' as wildcard
 *
 * Example:
 * <code>
 * //Deny access to guests to search on customers
 * $acl->deny('guests', 'customers', 'search');
 *
 * //Deny access to guests to search or create on customers
 * $acl->deny('guests', 'customers', array('search', 'create'));
 *
 * //Deny access to any role to browse on products
 * $acl->deny('*', 'products', 'browse');
 *
 * //Deny access to any role to browse on any resource
 * $acl->deny('*', '*', 'browse');
 * </code>
 *
 * @param string $roleName
 * @param string $resourceName
 * @param mixed $access
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny){

	zval *role_name, *resource_name, *access, *action;
	zval *status;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &role_name, &resource_name, &access);
	
	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 0);
	
	PHALCON_INIT_VAR(status);
	phalcon_call_method_p4(status, this_ptr, "_allowordeny", role_name, resource_name, access, action);
	RETURN_CCTOR(status);
}

/**
 * Check whether a role is allowed to access an action from a resource
 *
 * <code>
 * //Does andres have access to the customers resource to create?
 * $acl->isAllowed('andres', 'Products', 'create');
 *
 * //Do guests have access to any resource to edit?
 * $acl->isAllowed('guests', '*', 'edit');
 * </code>
 *
 * @param  string $role
 * @param  string $resource
 * @param  string $access
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *role, *resource, *access, *events_manager;
	zval *event_name = NULL, *status, *default_access, *roles_names;
	zval *have_access = NULL, *access_roles, *resource_access = NULL;
	zval *resource_name = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &role, &resource, &access);
	
	phalcon_update_property_this(this_ptr, SL("_activeRole"), role TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_activeResource"), resource TSRMLS_CC);
	phalcon_update_property_this(this_ptr, SL("_activeAccess"), access TSRMLS_CC);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "acl:beforeCheckAccess", 1);
	
		PHALCON_INIT_VAR(status);
		phalcon_call_method_p2(status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	PHALCON_OBS_VAR(default_access);
	phalcon_read_property_this(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	/** 
	 * Check if the role exists
	 */
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(roles_names, role)) {
		RETURN_CCTOR(default_access);
	}
	
	PHALCON_INIT_VAR(have_access);
	
	PHALCON_OBS_VAR(t0);
	phalcon_read_property_this(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(access_roles);
	phalcon_array_fetch(&access_roles, t0, role, PH_NOISY_CC);
	if (Z_TYPE_P(access_roles) == IS_ARRAY) { 
	
		phalcon_is_iterable(access_roles, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(resource_name, ah0, hp0);
			PHALCON_GET_HVALUE(resource_access);
	
			if (PHALCON_IS_EQUAL(resource_name, resource)) {
				if (phalcon_array_isset(resource_access, access)) {
					PHALCON_OBS_NVAR(have_access);
					phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
					break;
				}
	
				PHALCON_OBS_NVAR(have_access);
				phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
				break;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
		if (Z_TYPE_P(access_roles) == IS_ARRAY) { 
	
			phalcon_is_iterable(access_roles, &ah1, &hp1, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_HMKEY(resource_name, ah1, hp1);
				PHALCON_GET_HVALUE(resource_access);
	
				if (phalcon_array_isset_string(resource_access, SS("*"))) {
					if (phalcon_array_isset(resource_access, access)) {
						PHALCON_OBS_NVAR(have_access);
						phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
						break;
					}
	
					PHALCON_OBS_NVAR(have_access);
					phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
					break;
				}
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	}
	
	phalcon_update_property_this(this_ptr, SL("_accessGranted"), have_access TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "acl:afterCheckAccess", 1);
		phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
	}
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	
	RETURN_CCTOR(have_access);
}

/**
 * Return an array with every role registered in the list
 *
 * @return Phalcon\Acl\Role[]
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles){


	RETURN_MEMBER(this_ptr, "_roles");
}

/**
 * Return an array with every resource registered in the list
 *
 * @return Phalcon\Acl\Resource[]
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources){


	RETURN_MEMBER(this_ptr, "_resources");
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *roles, *number_roles, *pow_roles, *two, *middle_roles;
	zval *middle, *roles_names, *roles_inherits;
	zval *changed = NULL, *i, *internal_access = NULL, *one = NULL, *role_name = NULL;
	zval *role_inherit = NULL, *inherit_internal = NULL, *access = NULL;
	zval *resource_name = NULL, *value = NULL, *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(roles);
	phalcon_read_property_this(&roles, this_ptr, SL("_roles"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_roles);
	phalcon_fast_count(number_roles, roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(pow_roles);
	Z_LVAL_P(pow_roles) = Z_LVAL_P(number_roles) * Z_LVAL_P(number_roles);
	
	PHALCON_INIT_VAR(two);
	ZVAL_LONG(two, 2);
	
	PHALCON_INIT_VAR(middle_roles);
	div_function(middle_roles, pow_roles, two TSRMLS_CC);
	
	PHALCON_INIT_VAR(middle);
	phalcon_call_func_p1(middle, "ceil", middle_roles);
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(roles_inherits);
	phalcon_read_property_this(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(changed);
	ZVAL_BOOL(changed, 1);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	while (1) {
	
		PHALCON_INIT_NVAR(r0);
		is_smaller_or_equal_function(r0, i, middle TSRMLS_CC);
		if (!zend_is_true(r0)) {
			break;
		}
		PHALCON_OBS_NVAR(internal_access);
		phalcon_read_property_this(&internal_access, this_ptr, SL("_access"), PH_NOISY_CC);
		if (Z_TYPE_P(internal_access) != IS_ARRAY) { 
			goto ph_cycle_incr_0;
		}
	
		phalcon_is_iterable(roles_names, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(role_name, ah0, hp0);
			PHALCON_GET_HVALUE(one);
	
			if (phalcon_array_isset(roles_inherits, role_name)) {
	
				PHALCON_OBS_NVAR(r1);
				phalcon_array_fetch(&r1, roles_inherits, role_name, PH_NOISY_CC);
	
				phalcon_is_iterable(r1, &ah1, &hp1, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
					PHALCON_GET_HVALUE(role_inherit);
	
					if (phalcon_array_isset(internal_access, role_inherit)) {
	
						PHALCON_OBS_NVAR(inherit_internal);
						phalcon_array_fetch(&inherit_internal, internal_access, role_inherit, PH_NOISY_CC);
	
						phalcon_is_iterable(inherit_internal, &ah2, &hp2, 0, 0);
	
						while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
							PHALCON_GET_HKEY(resource_name, ah2, hp2);
							PHALCON_GET_HVALUE(access);
	
							phalcon_is_iterable(access, &ah3, &hp3, 0, 0);
	
							while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
								PHALCON_GET_HKEY(name, ah3, hp3);
								PHALCON_GET_HVALUE(value);
	
								if (phalcon_array_isset(internal_access, role_name)) {
	
									PHALCON_OBS_NVAR(r2);
									phalcon_array_fetch(&r2, internal_access, role_name, PH_NOISY_CC);
									if (phalcon_array_isset(r2, resource_name)) {
	
										PHALCON_OBS_NVAR(r3);
										phalcon_array_fetch(&r3, internal_access, role_name, PH_NOISY_CC);
										PHALCON_OBS_NVAR(r4);
										phalcon_array_fetch(&r4, r3, resource_name, PH_NOISY_CC);
										if (phalcon_array_isset(r4, name)) {
											zend_hash_move_forward_ex(ah3, &hp3);
											continue;
										}
									}
								}
								phalcon_array_update_zval_zval_zval_multi_3(&internal_access, role_name, resource_name, name, &value, 0 TSRMLS_CC);
	
								PHALCON_INIT_NVAR(changed);
								ZVAL_BOOL(changed, 1);
	
								zend_hash_move_forward_ex(ah3, &hp3);
							}
	
							zend_hash_move_forward_ex(ah2, &hp2);
						}
	
					}
	
					zend_hash_move_forward_ex(ah1, &hp1);
				}
	
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		if (zend_is_true(changed)) {
			phalcon_update_property_this(this_ptr, SL("_access"), internal_access TSRMLS_CC);
		}
		ph_cycle_incr_0:
		PHALCON_SEPARATE(i);
		increment_function(i);
	}
	
	PHALCON_MM_RESTORE();
}

