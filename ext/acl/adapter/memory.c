
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

#include "kernel/array.h"
#include "kernel/object.h"
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
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_adapter_memory_ce TSRMLS_CC, 1, phalcon_acl_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *ztrue, *resources_names, *access_list;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(ztrue);
	ZVAL_BOOL(ztrue, 1);
	
	PHALCON_INIT_VAR(resources_names);
	array_init_size(resources_names, 1);
	phalcon_array_update_string(&resources_names, SL("*"), &ztrue, PH_COPY | PH_SEPARATE);
	phalcon_update_property_this(this_ptr, SL("_resourcesNames"), resources_names TSRMLS_CC);
	
	PHALCON_INIT_VAR(access_list);
	array_init_size(access_list, 1);
	phalcon_array_update_string(&access_list, SL("*!*"), &ztrue, PH_COPY | PH_SEPARATE);
	phalcon_update_property_this(this_ptr, SL("_accessList"), access_list TSRMLS_CC);
	
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
	zval *key;

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
	
		PHALCON_INIT_NVAR(object);
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
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VS(key, role_name, "!*!*");
	phalcon_update_property_array(this_ptr, SL("_access"), key, default_access TSRMLS_CC);
	if (Z_TYPE_P(access_inherits) != IS_NULL) {
		phalcon_call_method_p2(return_value, this_ptr, "addinherit", role_name, access_inherits);
		RETURN_MM();
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
	phalcon_array_update_append_multi_2(&_roleInherits, role_name, role_inherit_name, 0);
	phalcon_update_property_this(this_ptr, SL("_roleInherits"), _roleInherits TSRMLS_CC);
	RETURN_MM_TRUE;
}

/**
 * Check whether role exist in the roles list
 *
 * @param  string $roleName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole){

	zval *role_name, *roles_names;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &role_name);
	
	PHALCON_OBS_VAR(roles_names);
	phalcon_read_property_this(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (phalcon_array_isset(roles_names, role_name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Check whether resource exist in the resources list
 *
 * @param  string $resourceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource){

	zval *resource_name, *resources_names;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &resource_name);
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (phalcon_array_isset(resources_names, resource_name)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
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
	zval *object = NULL, *resources_names, *exists;

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
	
		PHALCON_INIT_NVAR(object);
		object_init_ex(object, phalcon_acl_resource_ce);
		phalcon_call_method_p1_noret(object, "__construct", resource_name);
	
	}
	
	PHALCON_OBS_VAR(resources_names);
	phalcon_read_property_this(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!phalcon_array_isset(resources_names, resource_name)) {
		PHALCON_INIT_VAR(exists);
		ZVAL_BOOL(exists, 1);
		phalcon_update_property_array_append(this_ptr, SL("_resources"), object TSRMLS_CC);
		phalcon_update_property_array(this_ptr, SL("_resourcesNames"), resource_name, exists TSRMLS_CC);
	}
	
	phalcon_call_method_p2(return_value, this_ptr, "addresourceaccess", resource_name, access_list);
	RETURN_MM();
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *resource_name, *access_list, *resources_names;
	zval *exception_message, *exists, *internal_access_list;
	zval *access_name = NULL, *access_key = NULL;
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
	
	PHALCON_OBS_VAR(internal_access_list);
	phalcon_read_property_this(&internal_access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		phalcon_is_iterable(access_list, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSV(access_key, resource_name, "!", access_name);
			if (!phalcon_array_isset(internal_access_list, access_key)) {
				phalcon_update_property_array(this_ptr, SL("_accessList"), access_key, exists TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		if (Z_TYPE_P(access_list) == IS_STRING) {
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSV(access_key, resource_name, "!", access_list);
			if (!phalcon_array_isset(internal_access_list, access_key)) {
				phalcon_update_property_array(this_ptr, SL("_accessList"), access_key, exists TSRMLS_CC);
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
	zval *access_key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &resource_name, &access_list);
	
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		phalcon_is_iterable(access_list, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSV(access_key, resource_name, "!", access_name);
			phalcon_unset_property_array(this_ptr, SL("_accessList"), access_key TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	} else {
		PHALCON_INIT_NVAR(access_key);
		PHALCON_CONCAT_VSV(access_key, resource_name, "!", access_name);
		phalcon_unset_property_array(this_ptr, SL("_accessList"), access_key TSRMLS_CC);
	}
	
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
	zval *default_access, *access_list, *internal_access;
	zval *access_name = NULL, *access_key = NULL, *access_key_all = NULL;
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
	
	PHALCON_OBS_VAR(access_list);
	phalcon_read_property_this(&access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(internal_access);
	phalcon_read_property_this(&internal_access, this_ptr, SL("_access"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) { 
	
		phalcon_is_iterable(access, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSV(access_key, resource_name, "!", access_name);
			if (!phalcon_array_isset(access_list, access_key)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access_name, "' does not exist in resource '", resource_name, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_is_iterable(access, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HVALUE(access_name);
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSVSV(access_key, role_name, "!", resource_name, "!", access_name);
			phalcon_update_property_array(this_ptr, SL("_access"), access_key, action TSRMLS_CC);
			if (!PHALCON_IS_STRING(access_name, "*")) {
	
				PHALCON_INIT_NVAR(access_key_all);
				PHALCON_CONCAT_VSVS(access_key_all, role_name, "!", resource_name, "!*");
				if (!phalcon_array_isset(internal_access, access_key_all)) {
					phalcon_update_property_array(this_ptr, SL("_access"), access_key_all, default_access TSRMLS_CC);
				}
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	} else {
		if (!PHALCON_IS_STRING(access, "*")) {
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSV(access_key, resource_name, "!", access);
			if (!phalcon_array_isset(access_list, access_key)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access, "' does not exist in resource '", resource_name, "'");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
		}
	
		PHALCON_INIT_NVAR(access_key);
		PHALCON_CONCAT_VSVSV(access_key, role_name, "!", resource_name, "!", access);
	
		/** 
		 * Define the access action for the specified accessKey
		 */
		phalcon_update_property_array(this_ptr, SL("_access"), access_key, action TSRMLS_CC);
		if (!PHALCON_IS_STRING(access, "*")) {
	
			PHALCON_INIT_NVAR(access_key);
			PHALCON_CONCAT_VSVS(access_key, role_name, "!", resource_name, "!*");
	
			/** 
			 * If there is no default action for all the rest actions in the resource set the
			 * default one
			 */
			if (!phalcon_array_isset(internal_access, access_key)) {
				phalcon_update_property_array(this_ptr, SL("_access"), access_key, default_access TSRMLS_CC);
			}
		}
	}
	
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &role_name, &resource_name, &access);
	
	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 1);
	phalcon_call_method_p4(return_value, this_ptr, "_allowordeny", role_name, resource_name, access, action);
	RETURN_MM();
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &role_name, &resource_name, &access);
	
	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 0);
	phalcon_call_method_p4(return_value, this_ptr, "_allowordeny", role_name, resource_name, access, action);
	RETURN_MM();
}

static int phalcon_role_adapter_memory_check_inheritance(zval *role, zval *resource, zval *access, zval *access_list, zval* this_ptr TSRMLS_DC)
{
	zval *role_inherits, *inherited_roles, *access_key, *have_access = NULL;
	zval **parent_role;
	zval one = zval_used_for_init;
	HashPosition hp;

	ZVAL_LONG(&one, 1);

	assert(Z_TYPE_P(role) == IS_STRING);
	assert(Z_TYPE_P(resource) == IS_STRING);
	assert(Z_TYPE_P(access) == IS_STRING);
	assert(Z_TYPE_P(access_list) == IS_ARRAY);

	phalcon_read_property_this(&role_inherits, this_ptr, SL("_roleInherits"), PH_NOISY TSRMLS_CC);
	if (!phalcon_array_isset(role_inherits, role)) {
		zval_ptr_dtor(&role_inherits);
		return 0;
	}

	phalcon_array_fetch(&inherited_roles, role_inherits, role, PH_NOISY);
	zval_ptr_dtor(&role_inherits);

	if (Z_TYPE_P(inherited_roles) != IS_ARRAY) {
		return 0;
	}

	ALLOC_INIT_ZVAL(access_key);
	for (
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(inherited_roles), &hp);
		zend_hash_get_current_data_ex(Z_ARRVAL_P(inherited_roles), (void**)&parent_role, &hp) == SUCCESS;
		zend_hash_move_forward_ex(Z_ARRVAL_P(inherited_roles), &hp)
	) {
		int found;

		phalcon_concat_vsvsv(&access_key, *parent_role, SL("!"), resource, SL("!"), access, 0 TSRMLS_CC);
		if (phalcon_array_isset(access_list, access_key)) {
			phalcon_array_fetch(&have_access, access_list, access_key, PH_NOISY);
			found = Z_TYPE_P(have_access) != IS_NULL;
		}
		else {
			found = 0;
		}

		zval_ptr_dtor(&have_access);
		have_access = NULL;

		zval_dtor(access_key);
		ZVAL_NULL(access_key);

		if (found) {
			break;
		}

		if (phalcon_role_adapter_memory_check_inheritance(*parent_role, resource, access, access_list, this_ptr TSRMLS_CC)) {
			have_access = &one;
			break;
		}
	}

	zval_ptr_dtor(&access_key);
	return (have_access && Z_TYPE_P(have_access) != IS_NULL) ? 1 : 0;
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
	zval *have_access = NULL, *access_list, *access_key = NULL;
	zval resource_star, access_star;
	int allow_access;

	PHALCON_MM_GROW();

	INIT_ZVAL(access_star);
	ZVAL_STRING(&access_star, "*", 0);

	INIT_ZVAL(resource_star);
	ZVAL_STRING(&resource_star, "*", 0);

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
	
	PHALCON_OBS_VAR(access_list);
	phalcon_read_property_this(&access_list, this_ptr, SL("_access"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(access_key);
	PHALCON_CONCAT_VSVSV(access_key, role, "!", resource, "!", access);
	
	/** 
	 * Check if there is a direct combination for role-resource-access
	 */
	if (phalcon_array_isset(access_list, access_key)) {
		PHALCON_OBS_VAR(have_access);
		phalcon_array_fetch(&have_access, access_list, access_key, PH_NOISY);
		allow_access = Z_TYPE_P(have_access) != IS_NULL;
	}
	else {
		allow_access = 0;
	}
	
	/** 
	 * Check in the inherits roles
	 */
	if (!allow_access && phalcon_role_adapter_memory_check_inheritance(role, resource, access, access_list, getThis() TSRMLS_CC)) {
		allow_access = 1;
	}
	
	/** 
	 * If access wasn't found yet, try role-resource-*
	 */
	if (!allow_access) {
	
		PHALCON_INIT_NVAR(access_key);
		PHALCON_CONCAT_VSVS(access_key, role, "!", resource, "!*");
	
		/** 
		 * In the direct role
		 */
		if (phalcon_array_isset(access_list, access_key)) {
			PHALCON_OBS_VAR(have_access);
			phalcon_array_fetch(&have_access, access_list, access_key, PH_NOISY);
			allow_access = Z_TYPE_P(have_access) != IS_NULL;
		}
		else {
			allow_access = 0;
		}

		if (!allow_access && phalcon_role_adapter_memory_check_inheritance(role, resource, &access_star, access_list, getThis() TSRMLS_CC)) {
			allow_access = 1;
		}
	}
	
	/** 
	 * If access wasn't found yet, try role-*-*
	 */
	if (!allow_access) {
	
		PHALCON_INIT_NVAR(access_key);
		PHALCON_CONCAT_VS(access_key, role, "!*!*");
	
		/** 
		 * Try in the direct role
		 */
		if (phalcon_array_isset(access_list, access_key)) {
			PHALCON_OBS_VAR(have_access);
			phalcon_array_fetch(&have_access, access_list, access_key, PH_NOISY);
			allow_access = Z_TYPE_P(have_access) != IS_NULL;
		}
		else {
			allow_access = 0;
		}

		if (!allow_access && phalcon_role_adapter_memory_check_inheritance(role, &resource_star, &access_star, access_list, getThis() TSRMLS_CC)) {
			allow_access = 1;
		}
	}

	PHALCON_INIT_VAR(have_access);
	ZVAL_BOOL(have_access, allow_access);

	phalcon_update_property_this(this_ptr, SL("_accessGranted"), have_access TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "acl:afterCheckAccess", 1);
		phalcon_call_method_p3_noret(events_manager, "fire", event_name, this_ptr, have_access);
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

