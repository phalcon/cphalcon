
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_rolesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Roles
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roles"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Resource Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resourcesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Resources
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_resources"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_access"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 *
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_array_update_string(&_0, SL("*"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_resourcesNames"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_string(&_1, SL("*!*"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_accessList"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	zval *role, *accessInherits, *roleName = NULL, *object = NULL, *rolesNames, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &role, &accessInherits);



	if ((Z_TYPE_P(role) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(roleName);
		zephir_call_method(roleName, role, "getname");
		ZEPHIR_CPY_WRT(object, role);
	} else {
		ZEPHIR_CPY_WRT(roleName, role);
		ZEPHIR_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_role_ce);
		zephir_call_method_p1_noret(object, "__construct", role);
	}
	rolesNames = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (zephir_array_isset(rolesNames, roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), object TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("_rolesNames"), roleName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, roleName, "!*!*");
	zephir_update_property_array_append(this_ptr, SL("_access"), _0 TSRMLS_CC);
	if ((Z_TYPE_P(accessInherits) == IS_NULL)) {
		zephir_call_method_p2(return_value, this_ptr, "addinherit", roleName, accessInherits);
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 *
 * @param string $roleName
 * @param string $roleToInherit
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zval *roleName, *roleToInherit, *roleInheritName = NULL, *rolesInherits, *rolesNames, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName, &roleToInherit);



	rolesNames = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role '", roleName, "' does not exist in the role list");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if ((Z_TYPE_P(roleToInherit) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(roleInheritName);
		zephir_call_method(roleInheritName, roleToInherit, "getname");
	} else {
		ZEPHIR_CPY_WRT(roleInheritName, roleToInherit);
	}
	if (!(zephir_array_isset(rolesNames, roleInheritName))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role '", roleInheritName, "' (to inherit) does not exist in the role list");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(roleName, roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	rolesInherits = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesInherits, roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), roleName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether role exist in the roles list
 *
 * @param  string $roleName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zval *roleName, *rolesNames;

	zephir_fetch_params(0, 1, 0, &roleName);



	rolesNames = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(rolesNames, roleName));

}

/**
 * Check whether resource exist in the resources list
 *
 * @param  string $resourceName
 * @return boolean
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource) {

	zval *resourceName, *resourcesNames;

	zephir_fetch_params(0, 1, 0, &resourceName);



	resourcesNames = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(resourcesNames, resourceName));

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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource) {

	zval *resource, *accessList, *resourcesNames, *resourceName = NULL, *object = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resource, &accessList);



	if ((Z_TYPE_P(resource) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(resourceName);
		zephir_call_method(resourceName, resource, "getname");
		ZEPHIR_CPY_WRT(object, resource);
	} else {
		ZEPHIR_CPY_WRT(resourceName, resource);
		ZEPHIR_INIT_VAR(object);
		object_init_ex(object, phalcon_acl_resource_ce);
		zephir_call_method_p1_noret(object, "__construct", resourceName);
	}
	resourcesNames = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (zephir_array_isset(resourcesNames, resourceName)) {
		zephir_update_property_array_append(this_ptr, SL("_resources"), object TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_resourcesNames"), resourceName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	zephir_call_method_p2(return_value, this_ptr, "addresourceaccess", resourceName, accessList);
	RETURN_MM();

}

/**
 * Adds access to resources
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess) {

	HashTable *_3;
	HashPosition _2;
	zend_bool exists;
	zval *resourceName, *accessList, *accessName = NULL, *accessKey = NULL, *resourcesNames, *_0 = NULL, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName, &accessList);



	resourcesNames = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (zephir_array_isset(resourcesNames, resourceName)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Resource '", resourceName, "' does not exist in ACL");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	exists = 1;
	if ((Z_TYPE_P(accessList) == IS_ARRAY)) {
		zephir_is_iterable(accessList, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(accessName, _4);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_BOOL(_0, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _0 TSRMLS_CC);
			}
		}
	} else {
		if ((Z_TYPE_P(accessList) == IS_STRING)) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				ZEPHIR_INIT_NVAR(_0);
				ZVAL_BOOL(_0, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _0 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an access from a resource
 *
 * @param string $resourceName
 * @param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess) {

	HashTable *_1;
	HashPosition _0;
	zval *resourceName, *accessList, *accessName = NULL, *accessKey = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName, &accessList);



	if ((Z_TYPE_P(accessList) == IS_ARRAY)) {
		zephir_is_iterable(accessList, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(accessName, _2);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
			}
		}
	} else {
		if ((Z_TYPE_P(accessList) == IS_STRING)) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 *
 * @param string $roleName
 * @param string $resourceName
 * @param string $access
 * @param string $action
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	zend_function *_5 = NULL;
	HashTable *_3, *_7;
	HashPosition _2, _6;
	zval *roleName, *resourceName, *access, *action, *defaultAccess, *accessList, *accessName = NULL, *accessKey = NULL, *accessKeyAll = NULL, *rolesNames, *resourcesNames, *_0 = NULL, *_1 = NULL, **_4, **_8, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &roleName, &resourceName, &access, &action);



	rolesNames = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (zephir_array_isset(rolesNames, roleName)) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role '", roleName, "' does not exist in ACL");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	resourcesNames = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (zephir_array_isset(resourcesNames, resourceName)) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Resource '", resourceName, "' does not exist in ACL");
		zephir_call_method_p1_noret(_0, "__construct", _1);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	defaultAccess = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	accessList = zephir_fetch_nproperty_this(this_ptr, SL("_access"), PH_NOISY_CC);
	if ((Z_TYPE_P(access) == IS_ARRAY)) {
		zephir_is_iterable(access, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(accessName, _4);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SVSVS(_1, "Acccess '", accessName, "' does not exist in resource '", resourceName, "'");
				zephir_call_method_p1_cache_noret(_0, "__construct", &_5, _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_is_iterable(access, &_7, &_6, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
			; zend_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(accessName, _8);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", accessName);
			zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(accessName, "*")) {
				ZEPHIR_INIT_NVAR(accessKeyAll);
				ZEPHIR_CONCAT_VSVS(accessKeyAll, roleName, "!", resourceName, "!*");
				if (zephir_array_isset(accessList, accessKeyAll)) {
					zephir_update_property_array(this_ptr, SL("_access"), accessKeyAll, defaultAccess TSRMLS_CC);
				}
			}
		}
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", access);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SVSVS(_1, "Acccess '", access, "' does not exist in resource '", resourceName, "'");
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSVS(accessKey, roleName, "!", resourceName, "!*");
			if (!(zephir_array_isset(accessList, accessKey))) {
				_9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
				zephir_update_property_array(this_ptr, SL("_access"), accessKey, _9 TSRMLS_CC);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zval *roleName, *resourceName, *access, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName, &resourceName, &access);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_call_method_p4(return_value, this_ptr, "_allowordeny", roleName, resourceName, access, _0);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zval *roleName, *resourceName, *access, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName, &resourceName, &access);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	zephir_call_method_p4(return_value, this_ptr, "_allowordeny", roleName, resourceName, access, _0);
	RETURN_MM();

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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	HashTable *_4, *_7, *_10;
	HashPosition _3, _6, _9;
	zval *role, *resource, *access, *eventsManager = NULL, *accessList, *accessKey = NULL, *haveAccess = NULL, *roleInherits, *inheritedRole = NULL, *rolesNames, *inheritedRoles, *_0, *_1 = NULL, *_2, **_5, **_8, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &role, &resource, &access);



	zephir_update_property_this(this_ptr, SL("_activeRole"), role TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeResource"), resource TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeAccess"), resource TSRMLS_CC);
	accessList = zephir_fetch_nproperty_this(this_ptr, SL("_access"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	//missing empty
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "acl:beforeCheckAccess", 1);
		zephir_call_method_p2(_1, eventsManager, "fire", _2, this_ptr);
		if (ZEPHIR_IS_FALSE(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	rolesNames = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, role))) {
		RETURN_MEMBER(this_ptr, "_defaultAccess");
	}
	ZEPHIR_INIT_VAR(accessKey);
	ZEPHIR_CONCAT_VSVSV(accessKey, role, "!", resource, "!", access);
	if (zephir_array_isset(accessList, accessKey)) {
		ZEPHIR_OBS_VAR(haveAccess);
		zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
	}
	if ((Z_TYPE_P(haveAccess) == IS_NULL)) {
		roleInherits = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&inheritedRoles, roleInherits, role, 1 TSRMLS_CC)) {
			if ((Z_TYPE_P(inheritedRoles) == IS_ARRAY)) {
				zephir_is_iterable(inheritedRoles, &_4, &_3, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
					; zend_hash_move_forward_ex(_4, &_3)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _5);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVSV(accessKey, inheritedRole, "!", resource, "!", access);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
					}
				}
			}
		}
	}
	if ((Z_TYPE_P(haveAccess) == IS_NULL)) {
		ZEPHIR_INIT_BNVAR(accessKey);
		ZEPHIR_CONCAT_VSVS(accessKey, role, "!", resource, "!*");
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
		} else {
			if ((Z_TYPE_P(inheritedRoles) == IS_ARRAY)) {
				zephir_is_iterable(inheritedRoles, &_7, &_6, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
					; zend_hash_move_forward_ex(_7, &_6)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _8);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVS(accessKey, inheritedRole, "!", resource, "!*");
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	if ((Z_TYPE_P(haveAccess) == IS_NULL)) {
		ZEPHIR_INIT_BNVAR(accessKey);
		ZEPHIR_CONCAT_VS(accessKey, role, "!*!*");
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
		} else {
			if ((Z_TYPE_P(inheritedRoles) == IS_ARRAY)) {
				zephir_is_iterable(inheritedRoles, &_10, &_9, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
					; zend_hash_move_forward_ex(_10, &_9)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _11);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VS(accessKey, inheritedRole, "!*!*");
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	zephir_update_property_this(this_ptr, SL("_accessGranted"), haveAccess TSRMLS_CC);
	if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "acl:afterCheckAccess", 1);
		zephir_call_method_p2_noret(eventsManager, "fire", _1, this_ptr);
	}
	if ((Z_TYPE_P(haveAccess) == IS_NULL)) {
		RETURN_MM_LONG(0);
	}
	RETURN_CCTOR(haveAccess);

}

/**
 * Return an array with every role registered in the list
 *
 * @return Phalcon\Acl\Role[]
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {


	RETURN_MEMBER(this_ptr, "_roles");

}

/**
 * Return an array with every resource registered in the list
 *
 * @return Phalcon\Acl\Resource[]
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {


	RETURN_MEMBER(this_ptr, "_resources");

}

