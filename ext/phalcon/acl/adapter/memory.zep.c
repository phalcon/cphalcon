
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * Phalcon\Acl\Adapter\Memory
 *
 * Manages ACL lists in memory
 *
 *<code>
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl::DENY
 * );
 *
 * // Register roles
 * $roles = [
 *     "users"  => new \Phalcon\Acl\Role("Users"),
 *     "guests" => new \Phalcon\Acl\Role("Guests"),
 * ];
 * foreach ($roles as $role) {
 *     $acl->addRole($role);
 * }
 *
 * // Private area resources
 * $privateResources = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateResources as $resourceName => $actions) {
 *     $acl->addResource(
 *         new \Phalcon\Acl\Resource($resourceName),
 *         $actions
 *     );
 * }
 *
 * // Public area resources
 * $publicResources = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicResources as $resourceName => $actions) {
 *     $acl->addResource(
 *         new \Phalcon\Acl\Resource($resourceName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($roles as $role){
 *     foreach ($publicResources as $resource => $actions) {
 *         $acl->allow($role->getName(), $resource, "*");
 *     }
 * }
 *
 * // Grant access to private area to role Users
 * foreach ($privateResources as $resource => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $resource, $action);
 *     }
 * }
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

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("_func"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("_noArgumentsDefaultAction"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zephir_update_property_this(getThis(), SL("_resourcesNames"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("*!*"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(getThis(), SL("_accessList"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * Example:
 * <code>
 * $acl->addRole(
 *     new Phalcon\Acl\Role("administrator"),
 *     "consultant"
 * );
 *
 * $acl->addRole("administrator", "consultant");
 * </code>
 *
 * @param  array|string         accessInherits
 * @param  RoleInterface|string role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, *accessInherits = NULL, *roleName = NULL, *roleObject = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &accessInherits);

	if (!accessInherits) {
		accessInherits = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&roleName, role, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_CPY_WRT(roleName, role);
		ZEPHIR_INIT_NVAR(roleObject);
		object_init_ex(roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, roleObject, "__construct", NULL, 84, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either an string or implement RoleInterface", "phalcon/acl/adapter/memory.zep", 201);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (zephir_array_isset(_1, roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), roleObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_rolesNames"), roleName, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
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

	HashTable *_7$$6;
	HashPosition _6$$6;
	zend_bool _2;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, *roleInheritName = NULL, *rolesNames = NULL, *deepInheritName = NULL, *_3, *_12, *_0$$3, *_4$$6, *_5$$6, **_8$$6, *_10$$8, *_11$$8;
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
		zephir_throw_exception_debug(_0$$3, "phalcon/acl/adapter/memory.zep", 227 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = Z_TYPE_P(roleToInherit) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(roleToInherit, phalcon_acl_roleinterface_ce TSRMLS_CC);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&roleInheritName, roleToInherit, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(roleInheritName, roleToInherit);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (zephir_array_isset(_3, roleInheritName)) {
		_4$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		zephir_array_fetch(&_5$$6, _4$$6, roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 240 TSRMLS_CC);
		zephir_is_iterable(_5$$6, &_7$$6, &_6$$6, 0, 0, "phalcon/acl/adapter/memory.zep", 243);
		for (
		  ; zend_hash_get_current_data_ex(_7$$6, (void**) &_8$$6, &_6$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_7$$6, &_6$$6)
		) {
			ZEPHIR_GET_HVALUE(deepInheritName, _8$$6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_9, 85, roleName, deepInheritName);
			zephir_check_call_status();
		}
	}
	if (!(zephir_array_isset(rolesNames, roleInheritName))) {
		ZEPHIR_INIT_VAR(_10$$8);
		object_init_ex(_10$$8, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_11$$8);
		ZEPHIR_CONCAT_SVS(_11$$8, "Role '", roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, _10$$8, "__construct", NULL, 9, _11$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$8, "phalcon/acl/adapter/memory.zep", 249 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(roleName, roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_roleInherits"), PH_NOISY_CC);
	if (!(zephir_array_isset(_12, roleName))) {
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
 * // Add a resource to the the list allowing access to an action
 * $acl->addResource(
 *     new Phalcon\Acl\Resource("customers"),
 *     "search"
 * );
 *
 * $acl->addResource("customers", "search");
 *
 * // Add a resource  with an access list
 * $acl->addResource(
 *     new Phalcon\Acl\Resource("customers"),
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 *
 * $acl->addResource(
 *     "customers",
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 * </code>
 *
 * @param   Phalcon\Acl\Resource|string resourceValue
 * @param   array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResource) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceValue, *accessList, *resourceName = NULL, *resourceObject = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceValue, &accessList);



	_0 = Z_TYPE_P(resourceValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(resourceValue, phalcon_acl_resourceinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&resourceName, resourceValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(resourceObject, resourceValue);
	} else {
		ZEPHIR_CPY_WRT(resourceName, resourceValue);
		ZEPHIR_INIT_NVAR(resourceObject);
		object_init_ex(resourceObject, phalcon_acl_resource_ce);
		ZEPHIR_CALL_METHOD(NULL, resourceObject, "__construct", NULL, 86, resourceName);
		zephir_check_call_status();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_resourcesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_1, resourceName))) {
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, *_0, *_1$$3, **_6$$5, *_7$$6, *_8$$7 = NULL, *_9$$8, *_10$$9;
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
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 348 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 352);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_5$$5, &_4$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 363);
		for (
		  ; zend_hash_get_current_data_ex(_5$$5, (void**) &_6$$5, &_4$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$5, &_4$$5)
		) {
			ZEPHIR_GET_HVALUE(accessName, _6$$5);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			_7$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
			if (!(zephir_array_isset(_7$$6, accessKey))) {
				ZEPHIR_INIT_NVAR(_8$$7);
				ZVAL_BOOL(_8$$7, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _8$$7 TSRMLS_CC);
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessList);
		_9$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
		if (!(zephir_array_isset(_9$$8, accessKey))) {
			ZEPHIR_INIT_VAR(_10$$9);
			ZVAL_BOOL(_10$$9, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), accessKey, _10$$9 TSRMLS_CC);
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
	zval *resourceName_param = NULL, *accessList, *accessName = NULL, *accessKey = NULL, **_2$$3, *_3$$4, *_4$$5, *_5$$7, *_6$$8;
	zval *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_1$$3, &_0$$3, 0, 0, "phalcon/acl/adapter/memory.zep", 389);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(accessName, _2$$3);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
			if (zephir_array_isset(_3$$4, accessKey)) {
				_4$$5 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_4$$5, accessKey, PH_SEPARATE);
			}
		}
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", accessName);
			_5$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
			if (zephir_array_isset(_5$$7, accessKey)) {
				_6$$8 = zephir_fetch_nproperty_this(this_ptr, SL("_accessList"), PH_NOISY_CC);
				zephir_array_unset(&_6$$8, accessKey, PH_SEPARATE);
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *action, *func = NULL, *accessList = NULL, *accessName = NULL, *accessKey = NULL, *_0, *_3, *_1$$3, *_4$$4, **_8$$5, **_13$$5, *_9$$7 = NULL, *_10$$7 = NULL, *_14$$12, *_15$$12;
	zval *roleName = NULL, *resourceName = NULL, *_2$$3, *_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &resourceName_param, &access, &action, &func);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);
	if (!func) {
		func = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(_0, roleName))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "Role '", roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 407 TSRMLS_CC);
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
		zephir_throw_exception_debug(_4$$4, "phalcon/acl/adapter/memory.zep", 411 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, &_7$$5, &_6$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 425);
		for (
		  ; zend_hash_get_current_data_ex(_7$$5, (void**) &_8$$5, &_6$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_7$$5, &_6$$5)
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
				zephir_throw_exception_debug(_9$$7, "phalcon/acl/adapter/memory.zep", 421 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_is_iterable(access, &_12$$5, &_11$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 434);
		for (
		  ; zend_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_12$$5, &_11$$5)
		) {
			ZEPHIR_GET_HVALUE(accessName, _13$$5);
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", accessName);
			zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
			if (Z_TYPE_P(func) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("_func"), accessKey, func TSRMLS_CC);
			}
		}
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(accessKey);
			ZEPHIR_CONCAT_VSV(accessKey, resourceName, "!", access);
			if (!(zephir_array_isset(accessList, accessKey))) {
				ZEPHIR_INIT_VAR(_14$$12);
				object_init_ex(_14$$12, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(_15$$12);
				ZEPHIR_CONCAT_SVSVS(_15$$12, "Access '", access, "' does not exist in resource '", resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, _14$$12, "__construct", NULL, 9, _15$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14$$12, "phalcon/acl/adapter/memory.zep", 439 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), accessKey, action TSRMLS_CC);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("_func"), accessKey, func TSRMLS_CC);
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
 * $acl->allow("guests", "customers", "search");
 *
 * //Allow access to guests to search or create on customers
 * $acl->allow("guests", "customers", ["search", "create"]);
 *
 * //Allow access to any role to browse on products
 * $acl->allow("*", "products", "browse");
 *
 * //Allow access to any role to browse on any resource
 * $acl->allow("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *func = NULL, *innerRoleName = NULL, *_0$$3, *_1$$4, *_2$$4 = NULL, **_5$$4, *_6$$5 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);
	if (!func) {
		func = ZEPHIR_GLOBAL(global_null);
	}


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, roleName, resourceName, access, _0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_is_iterable(_1$$4, &_4$$4, &_3$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 486);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(_2$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_6$$5);
			ZVAL_LONG(_6$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, innerRoleName, resourceName, access, _6$$5, func);
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
 * $acl->deny("guests", "customers", "search");
 *
 * //Deny access to guests to search or create on customers
 * $acl->deny("guests", "customers", ["search", "create"]);
 *
 * //Deny access to any role to browse on products
 * $acl->deny("*", "products", "browse");
 *
 * //Deny access to any role to browse on any resource
 * $acl->deny("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *func = NULL, *innerRoleName = NULL, *_0$$3, *_1$$4, *_2$$4 = NULL, **_5$$4, *_6$$5 = NULL;
	zval *roleName = NULL, *resourceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(roleName, roleName_param);
	zephir_get_strval(resourceName, resourceName_param);
	if (!func) {
		func = ZEPHIR_GLOBAL(global_null);
	}


	if (!ZEPHIR_IS_STRING(roleName, "*")) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, roleName, resourceName, access, _0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2$$4);
		zephir_is_iterable(_1$$4, &_4$$4, &_3$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 519);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(_2$$4, _5$$4);
			ZEPHIR_INIT_NVAR(_6$$5);
			ZVAL_LONG(_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, innerRoleName, resourceName, access, _6$$5, func);
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
 * $acl->isAllowed("andres", "Products", "create");
 *
 * //Do guests have access to any resource to edit?
 * $acl->isAllowed("guests", "*", "edit");
 * </code>
 *
 * @param  RoleInterface|RoleAware|string roleName
 * @param  ResourceInterface|ResourceAware|string resourceName
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	HashTable *_7$$17, *_10$$23, *_13$$29, *_20$$34;
	HashPosition _6$$17, _9$$23, _12$$29, _19$$34;
	zend_bool hasRole, hasResource, _17$$35, _22$$37, _24$$37, _25$$37, _27$$37, _28$$37, _30$$37, _43$$44, _45$$43, _47$$45;
	zephir_fcall_cache_entry *_38 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;
	zval *access = NULL;
	zval *roleName = NULL, *resourceName = NULL, *access_param = NULL, *parameters_param = NULL, *eventsManager = NULL, *accessList = NULL, *accessKey = NULL, *haveAccess = NULL, *roleInherits = NULL, *inheritedRole = NULL, *rolesNames = NULL, *inheritedRoles = NULL, *funcAccess = NULL, *resourceObject = NULL, *roleObject = NULL, *funcList = NULL, *reflectionFunction = NULL, *reflectionParameters = NULL, *parameterNumber = NULL, *parametersForFunction = NULL, *numberOfRequiredParameters = NULL, *userParametersSizeShouldBe = NULL, *reflectionClass = NULL, *parameterToCheck = NULL, *reflectionParameter = NULL, *_2, *_0$$5 = NULL, *_1$$9 = NULL, *_3$$11 = NULL, *_4$$11, *_5$$13, **_8$$17, **_11$$23, **_14$$29, *_15$$32, *_16$$33, *_18$$35, **_21$$34, *_49$$34, *_50$$34, *_23$$37 = NULL, *_26$$37 = NULL, *_29$$37 = NULL, *_31$$37 = NULL, *_32$$37, *_33$$40 = NULL, *_34$$40 = NULL, *_35$$40, *_36$$40 = NULL, *_37$$40 = NULL, *_39$$41, *_40$$42, _41$$42, *_42$$44, *_44$$44, *_46$$43, *_48$$45;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &resourceName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(resourceName);
	zephir_get_strval(access, access_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		zephir_get_arrval(parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(haveAccess);
	ZVAL_NULL(haveAccess);
	ZEPHIR_INIT_VAR(funcAccess);
	ZVAL_NULL(funcAccess);
	ZEPHIR_INIT_VAR(resourceObject);
	ZVAL_NULL(resourceObject);
	ZEPHIR_INIT_VAR(roleObject);
	ZVAL_NULL(roleObject);
	hasRole = 0;
	hasResource = 0;
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(roleObject, roleName);
			ZEPHIR_CALL_METHOD(&roleName, roleObject, "getrolename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(roleName, phalcon_acl_roleinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$5, roleName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(roleName, _0$$5);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface", "phalcon/acl/adapter/memory.zep", 552);
			return;
		}
	}
	if (Z_TYPE_P(resourceName) == IS_OBJECT) {
		if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(resourceObject, resourceName);
			ZEPHIR_CALL_METHOD(&resourceName, resourceObject, "getresourcename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_1$$9, resourceName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(resourceName, _1$$9);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as resourceName must implement Phalcon\\Acl\\ResourceAware or Phalcon\\Acl\\ResourceInterface", "phalcon/acl/adapter/memory.zep", 563);
			return;
		}
	}
	zephir_update_property_this(getThis(), SL("_activeRole"), roleName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_activeResource"), resourceName TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_activeAccess"), access TSRMLS_CC);
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _2);
	ZEPHIR_OBS_VAR(funcList);
	zephir_read_property_this(&funcList, this_ptr, SL("_func"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_4$$11);
		ZVAL_STRING(_4$$11, "acl:beforeCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3$$11, eventsManager, "fire", NULL, 0, _4$$11, this_ptr);
		zephir_check_temp_parameter(_4$$11);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		_5$$13 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(_5$$13, 1)));
	}
	ZEPHIR_INIT_VAR(accessKey);
	ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
	if (zephir_array_isset(accessList, accessKey)) {
		ZEPHIR_OBS_NVAR(haveAccess);
		zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595 TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(funcAccess);
	zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(roleInherits);
		zephir_read_property_this(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, roleInherits, roleName, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_7$$17, &_6$$17, 0, 0, "phalcon/acl/adapter/memory.zep", 619);
				for (
				  ; zend_hash_get_current_data_ex(_7$$17, (void**) &_8$$17, &_6$$17) == SUCCESS
				  ; zend_hash_move_forward_ex(_7$$17, &_6$$17)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _8$$17);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVSV(accessKey, inheritedRole, "!", resourceName, "!", access);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 615 TSRMLS_CC);
					}
					ZEPHIR_OBS_NVAR(funcAccess);
					zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
				}
			}
		}
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VSVS(accessKey, roleName, "!", resourceName, "!*");
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 634 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(funcAccess);
			zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_10$$23, &_9$$23, 0, 0, "phalcon/acl/adapter/memory.zep", 650);
				for (
				  ; zend_hash_get_current_data_ex(_10$$23, (void**) &_11$$23, &_9$$23) == SUCCESS
				  ; zend_hash_move_forward_ex(_10$$23, &_9$$23)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _11$$23);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVS(accessKey, inheritedRole, "!", resourceName, "!*");
					ZEPHIR_OBS_NVAR(funcAccess);
					zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 646 TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(accessKey);
		ZEPHIR_CONCAT_VS(accessKey, roleName, "!*!*");
		if (zephir_array_isset(accessList, accessKey)) {
			ZEPHIR_OBS_NVAR(haveAccess);
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 665 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(funcAccess);
			zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_13$$29, &_12$$29, 0, 0, "phalcon/acl/adapter/memory.zep", 681);
				for (
				  ; zend_hash_get_current_data_ex(_13$$29, (void**) &_14$$29, &_12$$29) == SUCCESS
				  ; zend_hash_move_forward_ex(_13$$29, &_12$$29)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _14$$29);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VS(accessKey, inheritedRole, "!*!*");
					ZEPHIR_OBS_NVAR(funcAccess);
					zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 677 TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	zephir_update_property_this(getThis(), SL("_accessGranted"), haveAccess TSRMLS_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_15$$32);
		ZVAL_STRING(_15$$32, "acl:afterCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _15$$32, this_ptr);
		zephir_check_temp_parameter(_15$$32);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		_16$$33 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(_16$$33, 1));
	}
	if (Z_TYPE_P(funcAccess) != IS_NULL) {
		ZEPHIR_INIT_VAR(reflectionFunction);
		object_init_ex(reflectionFunction, zephir_get_internal_ce(SS("reflectionfunction") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, reflectionFunction, "__construct", NULL, 87, funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, reflectionFunction, "getparameters", NULL, 88);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(parameterNumber);
		ZVAL_LONG(parameterNumber, zephir_fast_count_int(reflectionParameters TSRMLS_CC));
		if (ZEPHIR_IS_LONG_IDENTICAL(parameterNumber, 0)) {
			_17$$35 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_17$$35) {
				ZEPHIR_INIT_VAR(_18$$35);
				ZEPHIR_CALL_USER_FUNC(_18$$35, funcAccess);
				zephir_check_call_status();
				_17$$35 = zephir_is_true(_18$$35);
			}
			RETURN_MM_BOOL(_17$$35);
		}
		ZEPHIR_INIT_VAR(parametersForFunction);
		array_init(parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, reflectionFunction, "getnumberofrequiredparameters", NULL, 89);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(userParametersSizeShouldBe, parameterNumber);
		zephir_is_iterable(reflectionParameters, &_20$$34, &_19$$34, 0, 0, "phalcon/acl/adapter/memory.zep", 748);
		for (
		  ; zend_hash_get_current_data_ex(_20$$34, (void**) &_21$$34, &_19$$34) == SUCCESS
		  ; zend_hash_move_forward_ex(_20$$34, &_19$$34)
		) {
			ZEPHIR_GET_HVALUE(reflectionParameter, _21$$34);
			ZEPHIR_CALL_METHOD(&reflectionClass, reflectionParameter, "getclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(reflectionClass) != IS_NULL) {
				_22$$37 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_22$$37) {
					ZEPHIR_CALL_METHOD(&_23$$37, reflectionClass, "isinstance", NULL, 0, roleObject);
					zephir_check_call_status();
					_22$$37 = zephir_is_true(_23$$37);
				}
				_24$$37 = _22$$37;
				if (_24$$37) {
					_24$$37 = !hasRole;
				}
				if (_24$$37) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 719);
					ZEPHIR_SEPARATE(userParametersSizeShouldBe);
					zephir_decrement(userParametersSizeShouldBe);
					continue;
				}
				_25$$37 = Z_TYPE_P(resourceObject) != IS_NULL;
				if (_25$$37) {
					ZEPHIR_CALL_METHOD(&_26$$37, reflectionClass, "isinstance", NULL, 0, resourceObject);
					zephir_check_call_status();
					_25$$37 = zephir_is_true(_26$$37);
				}
				_27$$37 = _25$$37;
				if (_27$$37) {
					_27$$37 = !hasResource;
				}
				if (_27$$37) {
					hasResource = 1;
					zephir_array_append(&parametersForFunction, resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 728);
					ZEPHIR_SEPARATE(userParametersSizeShouldBe);
					zephir_decrement(userParametersSizeShouldBe);
					continue;
				}
				_28$$37 = zephir_array_isset(parameters, parameterToCheck);
				if (_28$$37) {
					ZEPHIR_OBS_NVAR(_29$$37);
					zephir_array_fetch(&_29$$37, parameters, parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 735 TSRMLS_CC);
					_28$$37 = Z_TYPE_P(_29$$37) == IS_OBJECT;
				}
				_30$$37 = _28$$37;
				if (_30$$37) {
					zephir_array_fetch(&_32$$37, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 735 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_31$$37, reflectionClass, "isinstance", NULL, 0, _32$$37);
					zephir_check_call_status();
					_30$$37 = !zephir_is_true(_31$$37);
				}
				if (_30$$37) {
					ZEPHIR_INIT_NVAR(_33$$40);
					object_init_ex(_33$$40, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(_34$$40);
					zephir_array_fetch(&_35$$40, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 737 TSRMLS_CC);
					zephir_get_class(_34$$40, _35$$40, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_36$$40, reflectionClass, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_37$$40);
					ZEPHIR_CONCAT_SVSVSVSVSVS(_37$$40, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", access, " ", resourceName, ". Class passed: ", _34$$40, " , Class in defined function: ", _36$$40, ".");
					ZEPHIR_CALL_METHOD(NULL, _33$$40, "__construct", &_38, 9, _37$$40);
					zephir_check_call_status();
					zephir_throw_exception_debug(_33$$40, "phalcon/acl/adapter/memory.zep", 738 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset(parameters, parameterToCheck)) {
				zephir_array_fetch(&_39$$41, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 744 TSRMLS_CC);
				zephir_array_append(&parametersForFunction, _39$$41, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 744);
			}
		}
		if (ZEPHIR_LT_LONG(userParametersSizeShouldBe, zephir_fast_count_int(parameters TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_40$$42);
			ZEPHIR_CONCAT_SVSVSVS(_40$$42, "Number of parameters in array is higher than the number of parameters in defined function when check ", roleName, " can ", access, " ", resourceName, ". Remember that more parameters than defined in function will be ignored.");
			ZEPHIR_SINIT_VAR(_41$$42);
			ZVAL_LONG(&_41$$42, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, _40$$42, &_41$$42);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(parametersForFunction TSRMLS_CC) == 0) {
			if (ZEPHIR_GT_LONG(numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(_42$$44);
				ZEPHIR_CONCAT_SVSVSVS(_42$$44, "You didn't provide any parameters when check ", roleName, " can ", access, " ", resourceName, ". We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, _42$$44);
				zephir_check_call_status();
				_43$$44 = ZEPHIR_IS_LONG(haveAccess, 1);
				if (_43$$44) {
					_44$$44 = zephir_fetch_nproperty_this(this_ptr, SL("_noArgumentsDefaultAction"), PH_NOISY_CC);
					_43$$44 = ZEPHIR_IS_LONG(_44$$44, 1);
				}
				RETURN_MM_BOOL(_43$$44);
			}
			_45$$43 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_45$$43) {
				ZEPHIR_INIT_VAR(_46$$43);
				ZEPHIR_CALL_USER_FUNC(_46$$43, funcAccess);
				zephir_check_call_status();
				_45$$43 = zephir_is_true(_46$$43);
			}
			RETURN_MM_BOOL(_45$$43);
		}
		if (ZEPHIR_LE_LONG(numberOfRequiredParameters, zephir_fast_count_int(parametersForFunction TSRMLS_CC))) {
			_47$$45 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_47$$45) {
				ZEPHIR_INIT_VAR(_48$$45);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_48$$45, funcAccess, parametersForFunction);
				zephir_check_call_status();
				_47$$45 = zephir_is_true(_48$$45);
			}
			RETURN_MM_BOOL(_47$$45);
		}
		ZEPHIR_INIT_VAR(_49$$34);
		object_init_ex(_49$$34, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_50$$34);
		ZEPHIR_CONCAT_SVSVSV(_50$$34, "You didn't provide all necessary parameters for defined function when check ", roleName, " can ", access, " ", resourceName);
		ZEPHIR_CALL_METHOD(NULL, _49$$34, "__construct", &_38, 9, _50$$34);
		zephir_check_call_status();
		zephir_throw_exception_debug(_49$$34, "phalcon/acl/adapter/memory.zep", 777 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(haveAccess, 1));

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, *_0;
	zend_long defaultAccess;

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, defaultAccess);
	zephir_update_property_this(getThis(), SL("_noArgumentsDefaultAction"), _0 TSRMLS_CC);

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	

	RETURN_MEMBER(getThis(), "_noArgumentsDefaultAction");

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {

	

	RETURN_MEMBER(getThis(), "_roles");

}

/**
 * Return an array with every resource registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {

	

	RETURN_MEMBER(getThis(), "_resources");

}

