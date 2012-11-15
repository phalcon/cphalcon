
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
 *	foreach($roles as $role){
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *  $privateResources = array(
 *		'companies' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'products' => array('index', 'search', 'new', 'edit', 'save', 'create', 'delete'),
 *		'invoices' => array('index', 'profile')
 *	);
 *	foreach($privateResources as $resource => $actions){
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Private area resources
 *	$publicResources = array(
 *		'index' => array('index'),
 *		'about' => array('index'),
 *		'session' => array('index', 'register', 'start', 'end'),
 *		'contact' => array('index', 'send')
 *	);
 *  foreach($publicResources as $resource => $actions){
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *  //Grant access to public areas to both users and guests
 *	foreach($roles as $role){
 *		foreach($publicResources as $resource => $actions){
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant acess to private area to role Users
 *  foreach($privateResources as $resource => $actions){
 * 		foreach($actions as $action){
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

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, acl_adapter_memory, "phalcon\\acl", phalcon_acl_adapter_memory_method_entry, 0);

	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_activeRole"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_activeResource"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_activeAccess"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_acl_adapter_memory_ce, SL("_accessGranted"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_defaultAccess"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_acl_adapter_memory_ce TSRMLS_CC, 1, phalcon_acl_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_rolesNames") TSRMLS_CC);
	
	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_roles") TSRMLS_CC);
	
	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_resources") TSRMLS_CC);
	
	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_access") TSRMLS_CC);
	
	phalcon_update_property_empty_array(phalcon_acl_adapter_memory_ce, this_ptr, SL("_roleInherits") TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	add_assoc_bool_ex(a0, SS("*"), 1);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_resourcesNames"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	add_assoc_bool_ex(a2, SS("*"), 1);
	phalcon_array_update_string(&a1, SL("*"), &a2, PH_COPY | PH_SEPARATE TSRMLS_CC);
	zend_update_property(phalcon_acl_adapter_memory_ce, this_ptr, SL("_accessList"), a1 TSRMLS_CC);
	

	PHALCON_MM_RESTORE();
}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 *
 * @param int $defaultAccess
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setDefaultAction){

	zval *default_access;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &default_access) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_defaultAccess"), default_access TSRMLS_CC);
	
}

/**
 * Returns the default ACL access level
 *
 * @return int
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getDefaultAction){


	RETURN_MEMBER(this_ptr, "_defaultAccess");
}

/**
 * Adds a role to the ACL list. Second parameter lets to inherit access data from other existing role
 *
 * Example:
 * <code>
 * $acl->addRole(new Phalcon\Acl\Role('administrator'), 'consultant');
 * $acl->addRole('administrator', 'consultant');
 * </code>
 *
 * @param  Phalcon\Acl\RoleInterface $roleObject
 * @param  array $accessInherits
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole){

	zval *role_object, *access_inherits = NULL, *role_name = NULL;
	zval *object = NULL, *roles_names, *default_access;
	zval *success;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &role_object, &access_inherits) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_inherits) {
		PHALCON_INIT_NVAR(access_inherits);
	}
	
	if (Z_TYPE_P(role_object) == IS_OBJECT) {
		PHALCON_INIT_VAR(role_name);
		PHALCON_CALL_METHOD(role_name, role_object, "getname", PH_NO_CHECK);
		PHALCON_CPY_WRT(object, role_object);
	} else {
		PHALCON_CPY_WRT(role_name, role_object);
	
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_role_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "__construct", role_name, PH_CHECK);
	}
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (eval_int) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_roles"), PH_NOISY_CC);
	phalcon_array_append(&t0, object, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roles"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	phalcon_read_property(&t1, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	phalcon_array_update_zval_bool(&t1, role_name, 1, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_rolesNames"), t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(t2);
	phalcon_read_property(&t2, this_ptr, SL("_access"), PH_NOISY_CC);
	phalcon_array_update_zval_string_string_multi_3(&t2, role_name, SL("*"), SL("*"), &default_access, 0 TSRMLS_CC);
	if (Z_TYPE_P(access_inherits) != IS_NULL) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_2(success, this_ptr, "addinherit", role_name, access_inherits, PH_NO_CHECK);
	
		RETURN_CCTOR(success);
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit){

	zval *role_name, *role_to_inherit, *roles_names;
	zval *exception_message = NULL, *is_the_same, *roles_inherits;
	zval *empty_arr;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &role_name, &role_to_inherit) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role '", role_name, "' does not exist in the role list");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	eval_int = phalcon_array_isset(roles_names, role_to_inherit);
	if (!eval_int) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role '", role_to_inherit, "' does not exist in the role list");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(is_the_same);
	is_equal_function(is_the_same, role_to_inherit, role_name TSRMLS_CC);
	if (PHALCON_IS_TRUE(is_the_same)) {
		PHALCON_MM_RESTORE();
		RETURN_FALSE;
	}
	
	PHALCON_INIT_VAR(roles_inherits);
	phalcon_read_property(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_inherits, role_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(empty_arr);
		array_init(empty_arr);
	
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, role_name, &empty_arr, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t0 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(t1);
	phalcon_read_property(&t1, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	phalcon_array_update_append_multi_2(&t1, role_name, role_to_inherit, 0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_roleInherits"), t1 TSRMLS_CC);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &role_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
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
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &resource_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
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
 * @return  boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource){

	zval *resource, *access_list = NULL, *resource_name = NULL;
	zval *object = NULL, *resources_names, *status;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &resource, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!access_list) {
		PHALCON_INIT_NVAR(access_list);
		array_init(access_list);
	}
	
	if (Z_TYPE_P(resource) == IS_OBJECT) {
		PHALCON_INIT_VAR(resource_name);
		PHALCON_CALL_METHOD(resource_name, resource, "getname", PH_NO_CHECK);
		PHALCON_CPY_WRT(object, resource);
	} else {
		PHALCON_CPY_WRT(resource_name, resource);
	
		PHALCON_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_resource_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "__construct", resource_name, PH_CHECK);
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_resources"), PH_NOISY_CC);
		phalcon_array_append(&t0, object, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resources"), t0 TSRMLS_CC);
	
		PHALCON_INIT_VAR(a0);
		array_init(a0);
	
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, resource_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_accessList"), t1 TSRMLS_CC);
	
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
		phalcon_array_update_zval_bool(&t2, resource_name, 1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_resourcesNames"), t2 TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, this_ptr, "addresourceaccess", resource_name, access_list, PH_NO_CHECK);
	
	RETURN_CCTOR(status);
}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess){

	zval *resource_name, *access_list, *exception_message;
	zval *access_name = NULL, *internal_access_list = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &resource_name, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, resource_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource '", resource_name, "' does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		if (!phalcon_valid_foreach(access_list TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(access_list);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(access_name);
	
			PHALCON_INIT_NVAR(internal_access_list);
			phalcon_read_property(&internal_access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(r0);
			phalcon_array_fetch(&r0, internal_access_list, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r0, access_name);
			if (!eval_int) {
				PHALCON_INIT_NVAR(t1);
				phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
				PHALCON_INIT_NVAR(t2);
				ZVAL_LONG(t2, 1);
				phalcon_array_update_multi_2(&t1, resource_name, access_name, &t2, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_accessList"), t1 TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
		if(0){}
	
	} else {
		PHALCON_INIT_VAR(t3);
		phalcon_read_property(&t3, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch(&r1, t3, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r1, access_list);
		if (!eval_int) {
			PHALCON_INIT_VAR(t4);
			phalcon_read_property(&t4, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(t5);
			ZVAL_LONG(t5, 1);
			phalcon_array_update_multi_2(&t4, resource_name, access_list, &t5, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_accessList"), t4 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &resource_name, &access_list) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(access_list) == IS_ARRAY) { 
	
		if (!phalcon_valid_foreach(access_list TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(access_list);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(access_name);
	
			PHALCON_INIT_NVAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_NVAR(r0);
			phalcon_array_fetch(&r0, t0, resource_name, PH_NOISY_CC);
			PHALCON_SEPARATE_NMO(r0);
			phalcon_array_unset(r0, access_name);
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
		if(0){}
	
	} else {
		PHALCON_INIT_VAR(t1);
		phalcon_read_property(&t1, this_ptr, SL("_accessList"), PH_NOISY_CC);
		PHALCON_INIT_VAR(r1);
		phalcon_array_fetch(&r1, t1, resource_name, PH_NOISY_CC);
		PHALCON_SEPARATE_NMO(r1);
		phalcon_array_unset(r1, access_list);
	}
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	
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
	zval *empty_arr = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL, *t10 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &role_name, &resource_name, &access, &action) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Role \"", role_name, "\" does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource_name);
	if (!eval_int) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Resource \"", resource_name, "\" does not exist in ACL");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) { 
		PHALCON_INIT_VAR(access_list);
		phalcon_read_property(&access_list, this_ptr, SL("_accessList"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(access TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(access);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_0:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
	
			PHALCON_GET_FOREACH_VALUE(access_name);
	
			PHALCON_INIT_NVAR(r0);
			phalcon_array_fetch(&r0, access_list, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r0, access_name);
			if (!eval_int) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access_name, "' does not exist in resource '", resource_name, "' in ACL");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
	
		ph_cycle_end_0:
	
	
		if (!phalcon_valid_foreach(access TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(access);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_VALUE(access_name);
	
			PHALCON_INIT_NVAR(t0);
			phalcon_read_property(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
			PHALCON_INIT_NVAR(r1);
			phalcon_array_fetch(&r1, t0, role_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r1, resource_name);
			if (!eval_int) {
				PHALCON_INIT_NVAR(empty_arr);
				array_init(empty_arr);
	
				PHALCON_INIT_NVAR(t1);
				phalcon_read_property(&t1, this_ptr, SL("_access"), PH_NOISY_CC);
				phalcon_array_update_multi_2(&t1, role_name, resource_name, &empty_arr, 0 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_access"), t1 TSRMLS_CC);
			}
	
			PHALCON_INIT_NVAR(t2);
			phalcon_read_property(&t2, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_zval_zval_zval_multi_3(&t2, role_name, resource_name, access_name, &action, 0 TSRMLS_CC);
	
			PHALCON_INIT_NVAR(t3);
			phalcon_read_property(&t3, this_ptr, SL("_access"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(r2);
			phalcon_array_fetch(&r2, t3, role_name, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(r3);
			phalcon_array_fetch(&r3, r2, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(r3, SS("*"));
			if (!eval_int) {
				PHALCON_INIT_NVAR(t4);
				phalcon_read_property(&t4, this_ptr, SL("_access"), PH_NOISY_CC);
				phalcon_array_update_string_zval_zval_multi_3(&t4, role_name, resource_name, SL("*"), &default_access, 0 TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
		if(0){}
	
	} else {
		if (!PHALCON_COMPARE_STRING(access, "*")) {
			PHALCON_INIT_VAR(t5);
			phalcon_read_property(&t5, this_ptr, SL("_accessList"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r4);
			phalcon_array_fetch(&r4, t5, resource_name, PH_NOISY_CC);
			eval_int = phalcon_array_isset(r4, access);
			if (!eval_int) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVS(exception_message, "Acccess '", access, "' does not exist in resource '", resource_name, "' in ACL");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_acl_exception_ce, exception_message);
				return;
			}
		}
	
		PHALCON_INIT_VAR(t6);
		phalcon_read_property(&t6, this_ptr, SL("_access"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch(&r5, t6, role_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r5, resource_name);
		if (!eval_int) {
			PHALCON_INIT_NVAR(empty_arr);
			array_init(empty_arr);
	
			PHALCON_INIT_VAR(t7);
			phalcon_read_property(&t7, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_multi_2(&t7, role_name, resource_name, &empty_arr, 0 TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_access"), t7 TSRMLS_CC);
		}
	
		PHALCON_INIT_VAR(t8);
		phalcon_read_property(&t8, this_ptr, SL("_access"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(r6);
		phalcon_array_fetch(&r6, t8, role_name, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch(&r7, r6, resource_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset_string(r7, SS("*"));
		if (!eval_int) {
			PHALCON_INIT_VAR(t9);
			phalcon_read_property(&t9, this_ptr, SL("_access"), PH_NOISY_CC);
			phalcon_array_update_string_zval_zval_multi_3(&t9, role_name, resource_name, SL("*"), &default_access, 0 TSRMLS_CC);
		}
	
		PHALCON_INIT_VAR(t10);
		phalcon_read_property(&t10, this_ptr, SL("_access"), PH_NOISY_CC);
		phalcon_array_update_zval_zval_zval_multi_3(&t10, role_name, resource_name, access, &action, 0 TSRMLS_CC);
	}
	
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_rebuildaccesslist", PH_NO_CHECK);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 1);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_4(status, this_ptr, "_allowordeny", role_name, resource_name, access, action, PH_NO_CHECK);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role_name, &resource_name, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(action);
	ZVAL_LONG(action, 0);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_4(status, this_ptr, "_allowordeny", role_name, resource_name, access, action, PH_NO_CHECK);
	
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
 * @param  string $accessList
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed){

	zval *role, *resource, *access, *default_access;
	zval *events_manager, *event_name = NULL, *status, *resources_names;
	zval *roles_names, *have_access = NULL, *access_roles;
	zval *resource_access = NULL, *resource_name = NULL, *same_resource = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &role, &resource, &access) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_activeRole"), role TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_activeResource"), resource TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_activeAccess"), access TSRMLS_CC);
	
	PHALCON_INIT_VAR(default_access);
	phalcon_read_property(&default_access, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "acl:beforeCheckAccess", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(status)) {
	
			RETURN_CCTOR(status);
		}
	}
	
	PHALCON_INIT_VAR(resources_names);
	phalcon_read_property(&resources_names, this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(resources_names, resource);
	if (!eval_int) {
	
		RETURN_CCTOR(default_access);
	}
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(roles_names, role);
	if (!eval_int) {
	
		RETURN_CCTOR(default_access);
	}
	
	PHALCON_INIT_VAR(have_access);
	
	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(access_roles);
	phalcon_array_fetch(&access_roles, t0, role, PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(access_roles TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(access_roles);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_KEY(resource_name, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(resource_access);
	
		PHALCON_INIT_NVAR(same_resource);
		is_equal_function(same_resource, resource_name, resource TSRMLS_CC);
		if (PHALCON_IS_TRUE(same_resource)) {
			eval_int = phalcon_array_isset(resource_access, access);
			if (eval_int) {
				PHALCON_INIT_NVAR(have_access);
				phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
				goto ph_cycle_end_0;
			}
	
			PHALCON_INIT_NVAR(have_access);
			phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
			goto ph_cycle_end_0;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
	
		if (!phalcon_valid_foreach(access_roles TSRMLS_CC)) {
			return;
		}
	
		ah1 = Z_ARRVAL_P(access_roles);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_KEY(resource_name, ah1, hp1);
			PHALCON_GET_FOREACH_VALUE(resource_access);
	
			eval_int = phalcon_array_isset_string(resource_access, SS("*"));
			if (eval_int) {
				eval_int = phalcon_array_isset(resource_access, access);
				if (eval_int) {
					PHALCON_INIT_NVAR(have_access);
					phalcon_array_fetch(&have_access, resource_access, access, PH_NOISY_CC);
					goto ph_cycle_end_1;
				}
	
				PHALCON_INIT_NVAR(have_access);
				phalcon_array_fetch_string(&have_access, resource_access, SL("*"), PH_NOISY_CC);
				goto ph_cycle_end_1;
			}
	
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
		if(0){}
	
	}
	
	phalcon_update_property_zval(this_ptr, SL("_accessGranted"), have_access TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "acl:afterCheckAccess", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
	}
	
	if (Z_TYPE_P(have_access) == IS_NULL) {
		PHALCON_MM_RESTORE();
		RETURN_LONG(0);
	}
	
	
	RETURN_CCTOR(have_access);
}

/**
 * Returns the role which the list is checking if it's allowed to certain resource/access
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveRole){


	RETURN_MEMBER(this_ptr, "_activeRole");
}

/**
 * Returns the resource which the list is checking if some role can access it
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveResource){


	RETURN_MEMBER(this_ptr, "_activeResource");
}

/**
 * Returns the access which the list is checking if some role can access it
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveAccess){


	RETURN_MEMBER(this_ptr, "_activeAccess");
}

/**
 * Rebuild the list of access from the inherit lists
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _rebuildAccessList){

	zval *roles, *number_roles, *pow_roles, *two, *middle_roles;
	zval *middle, *roles_names, *roles_inherits;
	zval *i, *internal_access = NULL, *one = NULL, *role_name = NULL, *role_inherit = NULL;
	zval *inherit_internal = NULL, *access = NULL, *resource_name = NULL;
	zval *value = NULL, *name = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3;
	HashPosition hp0, hp1, hp2, hp3;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(roles);
	phalcon_read_property(&roles, this_ptr, SL("_roles"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_roles);
	phalcon_fast_count(number_roles, roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(pow_roles);
	mul_function(pow_roles, number_roles, number_roles TSRMLS_CC);
	
	PHALCON_INIT_VAR(two);
	ZVAL_LONG(two, 2);
	
	PHALCON_INIT_VAR(middle_roles);
	div_function(middle_roles, pow_roles, two TSRMLS_CC);
	
	PHALCON_INIT_VAR(middle);
	PHALCON_CALL_FUNC_PARAMS_1(middle, "ceil", middle_roles);
	
	PHALCON_INIT_VAR(roles_names);
	phalcon_read_property(&roles_names, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(roles_inherits);
	phalcon_read_property(&roles_inherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(i);
	ZVAL_LONG(i, 0);
	ph_cycle_start_0:
	
		PHALCON_INIT_NVAR(r0);
		is_smaller_or_equal_function(r0, i, middle TSRMLS_CC);
		if (!zend_is_true(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_NVAR(internal_access);
		phalcon_read_property(&internal_access, this_ptr, SL("_access"), PH_NOISY_CC);
	
		if (!phalcon_valid_foreach(roles_names TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(roles_names);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		ph_cycle_start_1:
	
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_1;
			}
	
			PHALCON_GET_FOREACH_KEY(role_name, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(one);
	
			eval_int = phalcon_array_isset(roles_inherits, role_name);
			if (eval_int) {
				PHALCON_INIT_NVAR(r1);
				phalcon_array_fetch(&r1, roles_inherits, role_name, PH_NOISY_CC);
	
				if (!phalcon_valid_foreach(r1 TSRMLS_CC)) {
					return;
				}
	
				ah1 = Z_ARRVAL_P(r1);
				zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
				ph_cycle_start_2:
	
					if (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS) {
						goto ph_cycle_end_2;
					}
	
					PHALCON_GET_FOREACH_VALUE(role_inherit);
	
					eval_int = phalcon_array_isset(internal_access, role_inherit);
					if (eval_int) {
						PHALCON_INIT_NVAR(inherit_internal);
						phalcon_array_fetch(&inherit_internal, internal_access, role_inherit, PH_NOISY_CC);
	
						if (!phalcon_valid_foreach(inherit_internal TSRMLS_CC)) {
							return;
						}
	
						ah2 = Z_ARRVAL_P(inherit_internal);
						zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
						ph_cycle_start_3:
	
							if (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS) {
								goto ph_cycle_end_3;
							}
	
							PHALCON_GET_FOREACH_KEY(resource_name, ah2, hp2);
							PHALCON_GET_FOREACH_VALUE(access);
	
	
							if (!phalcon_valid_foreach(access TSRMLS_CC)) {
								return;
							}
	
							ah3 = Z_ARRVAL_P(access);
							zend_hash_internal_pointer_reset_ex(ah3, &hp3);
	
							ph_cycle_start_4:
	
								if (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS) {
									goto ph_cycle_end_4;
								}
	
								PHALCON_GET_FOREACH_KEY(name, ah3, hp3);
								PHALCON_GET_FOREACH_VALUE(value);
	
								eval_int = phalcon_array_isset(internal_access, role_name);
								if (eval_int) {
									PHALCON_INIT_NVAR(r2);
									phalcon_array_fetch(&r2, internal_access, role_name, PH_NOISY_CC);
									eval_int = phalcon_array_isset(r2, resource_name);
									if (eval_int) {
										PHALCON_INIT_NVAR(r3);
										phalcon_array_fetch(&r3, internal_access, role_name, PH_NOISY_CC);
										PHALCON_INIT_NVAR(r4);
										phalcon_array_fetch(&r4, r3, resource_name, PH_NOISY_CC);
										eval_int = phalcon_array_isset(r4, name);
										if (eval_int) {
											zend_hash_move_forward_ex(ah3, &hp3);
											goto ph_cycle_start_4;
										}
									}
								}
	
								PHALCON_INIT_NVAR(t0);
								phalcon_read_property(&t0, this_ptr, SL("_access"), PH_NOISY_CC);
								phalcon_array_update_zval_zval_zval_multi_3(&t0, role_name, resource_name, name, &value, 0 TSRMLS_CC);
	
								zend_hash_move_forward_ex(ah3, &hp3);
								goto ph_cycle_start_4;
	
							ph_cycle_end_4:
	
	
							zend_hash_move_forward_ex(ah2, &hp2);
							goto ph_cycle_start_3;
	
						ph_cycle_end_3:
						if(0){}
	
					}
	
					zend_hash_move_forward_ex(ah1, &hp1);
					goto ph_cycle_start_2;
	
				ph_cycle_end_2:
				if(0){}
	
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_1;
	
		ph_cycle_end_1:
		if(0){}
	
		PHALCON_SEPARATE(i);
		increment_function(i);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	if(0){}
	
	PHALCON_MM_RESTORE();
}

