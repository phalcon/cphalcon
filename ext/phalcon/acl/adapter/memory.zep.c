
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
		ZEPHIR_CALL_METHOD(NULL, roleObject, "__construct", NULL, 80, role);
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

	HashTable *_6$$6;
	HashPosition _5$$6;
	zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, *roleInheritName = NULL, *rolesNames = NULL, *deepInheritName = NULL, *_2, *_11, *_0$$3, *_3$$6, *_4$$6, **_7$$6, *_9$$8, *_10$$8;
	zval *roleName = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherit);

	zephir_get_strval(roleName, roleName_param);


	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVS(_1$$3, "Role '", roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 9, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "phalcon/acl/adapter/memory.zep", 194 TSRMLS_CC);
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
		_3$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		zephir_array_fetch(&_4$$6, _3$$6, roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 207 TSRMLS_CC);
		zephir_is_iterable(_4$$6, &_6$$6, &_5$$6, 0, 0, "phalcon/acl/adapter/memory.zep", 210);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$6, (void**) &_7$$6, &_5$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$6, &_5$$6)
		) {
			ZEPHIR_GET_HVALUE(deepInheritName, _7$$6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_8, 81, roleName, deepInheritName);
			zephir_check_call_status();
		}
	}
	if (!(zephir_array_isset(rolesNames, roleInheritName))) {
		ZEPHIR_INIT_VAR(_9$$8);
		object_init_ex(_9$$8, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_10$$8);
		ZEPHIR_CONCAT_SVS(_10$$8, "Role '", roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, _9$$8, "__construct", NULL, 9, _10$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$8, "phalcon/acl/adapter/memory.zep", 216 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(roleName, roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (!(zephir_array_isset(_11, roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), roleName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("_roleInherits"), &roleInheritName TSRMLS_CC, SL("za"), 2, roleName);
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
		ZEPHIR_CALL_METHOD(NULL, resourceObject, "__construct", NULL, 82, resourceName);
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

	HashTable *_5$$5;
	HashPosition _4$$5;
	zend_bool exists = 0, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, *_0, *_1$$3, **_6$$5, *_7$$7 = NULL, *_8$$9;
	zval *resourceName = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(resourceName, resourceName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, resourceName))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Resource '", resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 298 TSRMLS_CC);
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
		zephir_is_iterable(accessList, &_5$$5, &_4$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 313);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$5, (void**) &_6$$5, &_4$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$5, &_4$$5)
		) {
			ZEPHIR_GET_HVALUE(accessName, _6$$5);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_7$$7);
				ZVAL_BOOL(_7$$7, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _7$$7 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessList);
		if (!(zephir_array_isset(accessList, accessKey))) {
			ZEPHIR_INIT_VAR(_8$$9);
			ZVAL_BOOL(_8$$9, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _8$$9 TSRMLS_CC);
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

	HashTable *_1$$3;
	HashPosition _0$$3;
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, **_2$$3, *_3$$5, *_4$$8;
	zval *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_1$$3, &_0$$3, 0, 0, "phalcon/acl/adapter/memory.zep", 339);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(accessName, _2$$3);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_3$$5, accessKey, PH_SEPARATE);
			}
		}
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (zephir_array_isset(accessList, accessKey)) {
				_4$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_4$$8, accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	HashTable *_7$$5, *_12$$5;
	HashPosition _6$$5, _11$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *action, *defaultAccess = NULL, *accessList = NULL, *accessName = NULL, *accessKey = NULL, *accessKeyAll = NULL, *internalAccess = NULL, *_0, *_3, *_1$$3, *_4$$4, **_8$$5, **_13$$5, *_9$$7 = NULL, *_10$$7 = NULL, *_15$$13, *_16$$13, *_18$$15;
	zval *roleName = NULL, *resourceName = NULL, *_2$$3, *_5$$4, *_14$$9 = NULL, *_17$$14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &roleName_param, &resourceName_param, &access, &action);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, roleName))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Role '", roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 357 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_3, resourceName))) {
		ZEPHIR_INIT_VAR(_4$$4);
		object_init_ex(_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SVS(_5$$4, "Resource '", resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 9, _5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$4, "phalcon/acl/adapter/memory.zep", 361 TSRMLS_CC);
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
		zephir_is_iterable(access, &_7$$5, &_6$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 377);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$5, &_6$$5)
		) {
			ZEPHIR_GET_HVALUE(accessName, _8$$5);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_NVAR(_9$$7);
				object_init_ex(_9$$7, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_10$$7);
				ZEPHIR_CONCAT_SVSVS(_10$$7, "Access '", accessName, "' does not exist in resource '", resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, _9$$7, "__construct", NULL, 9, _10$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$7, "phalcon/acl/adapter/memory.zep", 373 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_is_iterable(access, &_12$$5, &_11$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 390);
		for (
		  ; zephir_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12$$5, &_11$$5)
		) {
			ZEPHIR_GET_HVALUE(accessName, _13$$5);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", accessName);
			zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
			if (!ZEPHIR_IS_STRING(accessName, "*")) {
				ZEPHIR_INIT_LNVAR(_14$$9);
				ZEPHIR_CONCAT_VSVS(_14$$9, roleName, "!", resourceName, "!*");
				ZEPHIR_CPY_WRT(accessKeyAll, _14$$9);
				if (!(zephir_array_isset(internalAccess, accessKeyAll))) {
					zephir_update_property_array(this_ptr, SL("_access"), accessKeyAll, defaultAccess TSRMLS_CC);
				}
			}
		}
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", access);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_VAR(_15$$13);
				object_init_ex(_15$$13, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(_16$$13);
				ZEPHIR_CONCAT_SVSVS(_16$$13, "Access '", access, "' does not exist in resource '", resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, _15$$13, "__construct", NULL, 9, _16$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15$$13, "phalcon/acl/adapter/memory.zep", 395 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_VAR(_17$$14);
			ZEPHIR_CONCAT_VSVS(_17$$14, roleName, "!", resourceName, "!*");
			ZEPHIR_CPY_WRT(accessKey, _17$$14);
			if (!(zephir_array_isset(internalAccess, accessKey))) {
				_18$$15 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
				zephir_update_property_array(this_ptr, SL("_access"), accessKey, _18$$15 TSRMLS_CC);
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

	HashTable *_5$$4;
	HashPosition _4$$4;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *innerRoleName = NULL, *_0$$3, *_2$$4, *_3$$4 = NULL, **_6$$4, *_7$$5 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &resourceName_param, &access);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", &_1, 0, roleName, resourceName, access, _0$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_is_iterable(_2$$4, &_5$$4, &_4$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 451);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$4, &_4$$4)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _5$$4, _4$$4);
			ZEPHIR_GET_HVALUE(_3$$4, _6$$4);
			ZEPHIR_INIT_NVAR(_7$$5);
			ZVAL_LONG(_7$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", &_1, 0, innerRoleName, resourceName, access, _7$$5);
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

	HashTable *_4$$4;
	HashPosition _3$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *innerRoleName = NULL, *_0$$3, *_1$$4, *_2$$4 = NULL, **_5$$4, *_6$$5 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &resourceName_param, &access);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, roleName, resourceName, access, _0$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_is_iterable(_1$$4, &_4$$4, &_3$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 484);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(_2$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_6$$5);
			ZVAL_LONG(_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, innerRoleName, resourceName, access, _6$$5);
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

	HashTable *_6$$9, *_10$$15, *_14$$21;
	HashPosition _5$$9, _9$$15, _13$$21;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access_param = NULL, *eventsManager = NULL, *accessList = NULL, *accessKey = NULL, *haveAccess = NULL, *roleInherits = NULL, *inheritedRole = NULL, *rolesNames = NULL, *inheritedRoles = NULL, *_0, *_1$$3 = NULL, *_2$$3, *_3$$5, **_7$$9, **_11$$15, **_15$$21, *_16$$24;
	zval *roleName = NULL, *resourceName = NULL, *access = NULL, *_4, *_8$$12, *_12$$18;

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
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "acl:beforeCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, eventsManager, "fire", NULL, 0, _2$$3, this_ptr);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(_3$$5, 1)));
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VSVSV(_4, roleName, "!", resourceName, "!", access);
	ZEPHIR_CPY_WRT(accessKey, _4);
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
				zephir_is_iterable(inheritedRoles, &_6$$9, &_5$$9, 0, 0, "phalcon/acl/adapter/memory.zep", 551);
				for (
				  ; zephir_hash_get_current_data_ex(_6$$9, (void**) &_7$$9, &_5$$9) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6$$9, &_5$$9)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _7$$9);
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
		ZEPHIR_INIT_VAR(_8$$12);
		ZEPHIR_CONCAT_VSVS(_8$$12, roleName, "!", resourceName, "!*");
		ZEPHIR_CPY_WRT(accessKey, _8$$12);
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 566 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_10$$15, &_9$$15, 0, 0, "phalcon/acl/adapter/memory.zep", 580);
				for (
				  ; zephir_hash_get_current_data_ex(_10$$15, (void**) &_11$$15, &_9$$15) == SUCCESS
				  ; zephir_hash_move_forward_ex(_10$$15, &_9$$15)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _11$$15);
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
		ZEPHIR_INIT_VAR(_12$$18);
		ZEPHIR_CONCAT_VS(_12$$18, roleName, "!*!*");
		ZEPHIR_CPY_WRT(accessKey, _12$$18);
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_14$$21, &_13$$21, 0, 0, "phalcon/acl/adapter/memory.zep", 609);
				for (
				  ; zephir_hash_get_current_data_ex(_14$$21, (void**) &_15$$21, &_13$$21) == SUCCESS
				  ; zephir_hash_move_forward_ex(_14$$21, &_13$$21)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _15$$21);
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
		ZEPHIR_INIT_VAR(_16$$24);
		ZVAL_STRING(_16$$24, "acl:afterCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _16$$24, this_ptr);
		zephir_check_temp_parameter(_16$$24);
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

