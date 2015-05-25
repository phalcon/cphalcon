
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
#include "kernel/hash.h"


/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 *
 *	$acl = new \Phalcon\Acl\Adapter\Memory();
 *
 *	$acl->setDefaultAction(Phalcon\Acl::DENY);
 *
 *	//Register roles
 *	$roles = array(
 *		'users' => new \Phalcon\Acl\Role('Users'),
 *		'guests' => new \Phalcon\Acl\Role('Guests')
 *	);
 *	foreach ($roles as $role) {
 *		$acl->addRole($role);
 *	}
 *
 *	//Private area resources
 *	$privateResources = array(
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
 *	foreach ($publicResources as $resource => $actions) {
 *		$acl->addResource(new Phalcon\Acl\Resource($resource), $actions);
 *	}
 *
 *	//Grant access to public areas to both users and guests
 *	foreach ($roles as $role){
 *		foreach ($publicResources as $resource => $actions) {
 *			$acl->allow($role->getName(), $resource, '*');
 *		}
 *	}
 *
 *	//Grant access to private area to role Users
 *	foreach ($privateResources as $resource => $actions) {
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
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("*"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_resourcesNames"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
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
 * @param  array|string accessInherits
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *role, *accessInherits = NULL, *roleName = NULL, *roleObject = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &accessInherits);

	if (!accessInherits) {
		accessInherits = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(role) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&roleName, role, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(roleObject, role);
	} else {
		ZEPHIR_CPY_WRT(roleName, role);
		ZEPHIR_INIT_NVAR(roleObject);
		object_init_ex(roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, roleObject, "__construct", NULL, 1, role);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (zephir_array_isset(_0, roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), roleObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_rolesNames"), roleName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, roleName, "!*!*");
	zephir_update_property_array(this_ptr, SL("_access"), _2, _1 TSRMLS_CC);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zephir_fcall_cache_entry *_8 = NULL;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, *roleInheritName = NULL, *rolesNames, *deepInheritName = NULL, *_0 = NULL, *_2, *_3, *_4, **_7, *_9;
	zval *roleName = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherit);

	zephir_get_strval(roleName, roleName_param);


	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "Role '", roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/acl/adapter/memory.zep", 194 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(roleToInherit) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&roleInheritName, roleToInherit, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(roleInheritName, roleToInherit);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (zephir_array_isset(_2, roleInheritName)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		zephir_array_fetch(&_4, _3, roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 207 TSRMLS_CC);
		zephir_is_iterable(_4, &_6, &_5, 0, 0, "phalcon/acl/adapter/memory.zep", 210);
		for (
		  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HVALUE(deepInheritName, _7);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_8, 3, roleName, deepInheritName);
			zephir_check_call_status();
		}
	}
	if (!(zephir_array_isset(rolesNames, roleInheritName))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SVS(_9, "Role '", roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 2, _9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/acl/adapter/memory.zep", 216 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(roleName, roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), roleName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("_roleInherits"), &roleInheritName TSRMLS_CC, SL("za"), 1, roleName);
	RETURN_MM_BOOL(1);

}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zval *roleName_param = NULL, *_0;
	zval *roleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);

	zephir_get_strval(roleName, roleName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, roleName));

}

/**
 * Check whether resource exist in the resources list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource) {

	zval *resourceName_param = NULL, *_0;
	zval *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resourceName_param);

	zephir_get_strval(resourceName, resourceName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, resourceName));

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
 * @param   Phalcon\Acl\Resource|string resourceValue
 * @param   array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *resourceValue, *accessList, *resourceName = NULL, *resourceObject = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceValue, &accessList);



	if (Z_TYPE_P(resourceValue) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&resourceName, resourceValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(resourceObject, resourceValue);
	} else {
		ZEPHIR_CPY_WRT(resourceName, resourceValue);
		ZEPHIR_INIT_NVAR(resourceObject);
		object_init_ex(resourceObject, phalcon_acl_resource_ce);
		ZEPHIR_CALL_METHOD(NULL, resourceObject, "__construct", NULL, 4, resourceName);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, resourceName))) {
		zephir_update_property_array_append(this_ptr, SL("_resources"), resourceObject TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_resourcesNames"), resourceName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addresourceaccess", NULL, 0, resourceName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to resources
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, _3;
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, *_0, *_1 = NULL, **_6;
	zval *resourceName = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(resourceName, resourceName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, resourceName))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Resource '", resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/acl/adapter/memory.zep", 298 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 302);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_5, &_4, 0, 0, "phalcon/acl/adapter/memory.zep", 313);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(accessName, _6);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_BOOL(_1, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _1 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessList);
		if (!(zephir_array_isset(accessList, accessKey))) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_BOOL(_1, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _1 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Removes an access from a resource
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropResourceAccess) {

	HashTable *_1;
	HashPosition _0;
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, **_2, *_3;
	zval *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_1, &_0, 0, 0, "phalcon/acl/adapter/memory.zep", 339);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(accessName, _2);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_3, accessKey, PH_SEPARATE);
			}
		}
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				_3 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_3, accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	HashTable *_5, *_9;
	HashPosition _4, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *action, *defaultAccess, *accessList, *accessName = NULL, *accessKey = NULL, *accessKeyAll = NULL, *internalAccess, *_0, *_1 = NULL, *_3, **_6, *_7 = NULL, **_10, *_11;
	zval *roleName = NULL, *resourceName = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &roleName_param, &resourceName_param, &access, &action);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, roleName))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Role '", roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/acl/adapter/memory.zep", 357 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, resourceName))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_acl_exception_ce);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Resource '", resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/acl/adapter/memory.zep", 361 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(defaultAccess);
	zephir_read_property_this(&defaultAccess, this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(internalAccess);
	zephir_read_property_this(&internalAccess, this_ptr, SL("_access"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, &_5, &_4, 0, 0, "phalcon/acl/adapter/memory.zep", 377);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(accessName, _6);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSVS(_7, "Access '", accessName, "' does not exist in resource '", resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/acl/adapter/memory.zep", 373 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_is_iterable(access, &_9, &_8, 0, 0, "phalcon/acl/adapter/memory.zep", 390);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HVALUE(accessName, _10);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", accessName);
			zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(accessName, "*")) {
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_VSVS(_2, roleName, "!", resourceName, "!*");
				ZEPHIR_CPY_WRT(accessKeyAll, _2);
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
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSVS(_7, "Access '", access, "' does not exist in resource '", resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/acl/adapter/memory.zep", 395 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_VSVS(_2, roleName, "!", resourceName, "!*");
			ZEPHIR_CPY_WRT(accessKey, _2);
			if (!(zephir_array_isset(accessList, accessKey))) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
				zephir_update_property_array(this_ptr, SL("_access"), accessKey, _11 TSRMLS_CC);
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
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *innerRoleName = NULL, *_0 = NULL, *_2, **_5, *_6 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &resourceName_param, &access);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", &_1, 0, roleName, resourceName, access, _0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_is_iterable(_2, &_4, &_3, 0, 0, "phalcon/acl/adapter/memory.zep", 451);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _4, _3);
			ZEPHIR_GET_HVALUE(_0, _5);
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_LONG(_6, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", &_1, 0, innerRoleName, resourceName, access, _6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

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
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *innerRoleName = NULL, *_0 = NULL, *_1, **_4, *_5 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &resourceName_param, &access);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, roleName, resourceName, access, _0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_0);
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/acl/adapter/memory.zep", 484);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _3, _2);
			ZEPHIR_GET_HVALUE(_0, _4);
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, innerRoleName, resourceName, access, _5);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

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
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	HashTable *_5, *_8, *_11;
	HashPosition _4, _7, _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access_param = NULL, *eventsManager = NULL, *accessList, *accessKey = NULL, *haveAccess = NULL, *roleInherits, *inheritedRole = NULL, *rolesNames, *inheritedRoles, *_0, *_1 = NULL, *_2 = NULL, **_6, **_9, **_12;
	zval *roleName = NULL, *resourceName = NULL, *access = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &resourceName_param, &access_param);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);
	zephir_get_strval(access, access_param);
	ZEPHIR_INIT_VAR(haveAccess);
	ZVAL_NULL(haveAccess);


	zephir_update_property_this(this_ptr, SL("_activeRole"), roleName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeResource"), resourceName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeAccess"), access TSRMLS_CC);
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "acl:beforeCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, eventsManager, "fire", NULL, 0, _2, this_ptr);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(_0, 1)));
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VSVSV(_3, roleName, "!", resourceName, "!", access);
	ZEPHIR_CPY_WRT(accessKey, _3);
	if (zephir_array_isset(accessList, accessKey)) {
		ZEPHIR_OBS_NVAR(haveAccess);
		zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 530 TSRMLS_CC);
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(roleInherits);
		zephir_read_property_this(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, roleInherits, roleName, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_5, &_4, 0, 0, "phalcon/acl/adapter/memory.zep", 551);
				for (
				  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
				  ; zephir_hash_move_forward_ex(_5, &_4)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _6);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVSV(accessKey, inheritedRole, "!", resourceName, "!", access);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 548 TSRMLS_CC);
					}
				}
			}
		}
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VSVS(_3, roleName, "!", resourceName, "!*");
		ZEPHIR_CPY_WRT(accessKey, _3);
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 566 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_8, &_7, 0, 0, "phalcon/acl/adapter/memory.zep", 580);
				for (
				  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8, &_7)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _9);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVS(accessKey, inheritedRole, "!", resourceName, "!*");
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 576 TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_VS(_3, roleName, "!*!*");
		ZEPHIR_CPY_WRT(accessKey, _3);
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_11, &_10, 0, 0, "phalcon/acl/adapter/memory.zep", 609);
				for (
				  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11, &_10)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _12);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VS(accessKey, inheritedRole, "!*!*");
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 605 TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	zephir_update_property_this(this_ptr, SL("_accessGranted"), haveAccess TSRMLS_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "acl:afterCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _2, this_ptr);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL((ZEPHIR_IS_LONG(haveAccess, 1)));

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {


	RETURN_MEMBER(this_ptr, "_roles");

}

/**
 * Return an array with every resource registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {


	RETURN_MEMBER(this_ptr, "_resources");

}

