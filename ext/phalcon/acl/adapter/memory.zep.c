
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *role, *accessInherits = NULL, *roleName = NULL, *roleObject = NULL, *_1, *_2, *_3;

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
		ZEPHIR_CALL_METHOD(NULL, roleObject, "__construct", NULL, 82, role);
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
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, roleName, "!*!*");
	zephir_update_property_array(this_ptr, SL("_access"), _3, _2 TSRMLS_CC);
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
		zephir_throw_exception_debug(_0$$3, "phalcon/acl/adapter/memory.zep", 228 TSRMLS_CC);
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
		zephir_array_fetch(&_4$$6, _3$$6, roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 241 TSRMLS_CC);
		zephir_is_iterable(_4$$6, &_6$$6, &_5$$6, 0, 0, "phalcon/acl/adapter/memory.zep", 244);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$6, (void**) &_7$$6, &_5$$6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$6, &_5$$6)
		) {
			ZEPHIR_GET_HVALUE(deepInheritName, _7$$6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_8, 83, roleName, deepInheritName);
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
		zephir_throw_exception_debug(_9$$8, "phalcon/acl/adapter/memory.zep", 250 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(NULL, resourceObject, "__construct", NULL, 84, resourceName);
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
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 349 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (_3) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/acl/adapter/memory.zep", 353);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, &_5$$5, &_4$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 364);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$5, (void**) &_6$$5, &_4$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$5, &_4$$5)
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
		zephir_is_iterable(accessList, &_1$$3, &_0$$3, 0, 0, "phalcon/acl/adapter/memory.zep", 390);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_throw_exception_debug(_1$$3, "phalcon/acl/adapter/memory.zep", 408 TSRMLS_CC);
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
		zephir_throw_exception_debug(_4$$4, "phalcon/acl/adapter/memory.zep", 412 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, &_7$$5, &_6$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 426);
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
				zephir_throw_exception_debug(_9$$7, "phalcon/acl/adapter/memory.zep", 422 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_is_iterable(access, &_12$$5, &_11$$5, 0, 0, "phalcon/acl/adapter/memory.zep", 435);
		for (
		  ; zephir_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12$$5, &_11$$5)
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
				zephir_throw_exception_debug(_14$$12, "phalcon/acl/adapter/memory.zep", 440 TSRMLS_CC);
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

	HashTable *_5$$4;
	HashPosition _4$$4;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, *func = NULL, *innerRoleName = NULL, *_0$$3, *_2$$4, *_3$$4 = NULL, **_6$$4, *_7$$5 = NULL;
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
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", &_1, 0, roleName, resourceName, access, _0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rolesNames"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3$$4);
		zephir_is_iterable(_2$$4, &_5$$4, &_4$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 487);
		for (
		  ; zephir_hash_get_current_data_ex(_5$$4, (void**) &_6$$4, &_4$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5$$4, &_4$$4)
		) {
			ZEPHIR_GET_HMKEY(innerRoleName, _5$$4, _4$$4);
			ZEPHIR_GET_HVALUE(_3$$4, _6$$4);
			ZEPHIR_INIT_NVAR(_7$$5);
			ZVAL_LONG(_7$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", &_1, 0, innerRoleName, resourceName, access, _7$$5, func);
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
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_is_iterable(_1$$4, &_4$$4, &_3$$4, 0, 0, "phalcon/acl/adapter/memory.zep", 520);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$4, &_3$$4)
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
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool _15$$31, _20$$33, _22$$33, _24$$33, _26$$33, _40$$40, _42$$39, _44$$41;
	HashTable *_5$$13, *_8$$19, *_11$$25, *_18$$30;
	HashPosition _4$$13, _7$$19, _10$$25, _17$$30;
	zephir_fcall_cache_entry *_34 = NULL, *_38 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL;
	zval *access = NULL;
	zval *roleName = NULL, *resourceName = NULL, *access_param = NULL, *parameters_param = NULL, *eventsManager = NULL, *accessList = NULL, *accessKey = NULL, *haveAccess = NULL, *roleInherits = NULL, *inheritedRole = NULL, *rolesNames = NULL, *inheritedRoles = NULL, *funcAccess = NULL, *resourceObject = NULL, *roleObject = NULL, *funcList = NULL, *reflectionFunction = NULL, *reflectionParameters = NULL, *parameterNumber = NULL, *parametersForFunction = NULL, *numberOfRequiredParameters = NULL, *userParametersSizeShouldBe = NULL, *reflectionClass = NULL, *parameterToCheck = NULL, *reflectionParameter = NULL, *_0, *_1$$7 = NULL, *_2$$7, *_3$$9, **_6$$13, **_9$$19, **_12$$25, *_13$$28, *_14$$29, *_16$$31, **_19$$30, *_46$$30, *_47$$30, *_21$$33 = NULL, *_23$$33 = NULL, *_25$$33 = NULL, *_27$$33 = NULL, *_28$$33, *_29$$36 = NULL, *_30$$36 = NULL, *_31$$36, *_32$$36 = NULL, *_33$$36 = NULL, *_35$$37, *_36$$38, _37$$38, *_39$$40, *_41$$40, *_43$$39, *_45$$41;

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
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement RoleAware", "phalcon/acl/adapter/memory.zep", 545);
			return;
		}
		ZEPHIR_CPY_WRT(roleObject, roleName);
		ZEPHIR_CALL_METHOD(&roleName, roleObject, "getrolename", NULL, 0);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(resourceName) == IS_OBJECT) {
		if (!(zephir_instance_of_ev(resourceName, phalcon_acl_resourceaware_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as resourceName must implement ResourceAware", "phalcon/acl/adapter/memory.zep", 553);
			return;
		}
		ZEPHIR_CPY_WRT(resourceObject, resourceName);
		ZEPHIR_CALL_METHOD(&resourceName, resourceObject, "getresourcename", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_activeRole"), roleName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeResource"), resourceName TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_activeAccess"), access TSRMLS_CC);
	ZEPHIR_OBS_VAR(accessList);
	zephir_read_property_this(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(eventsManager, _0);
	ZEPHIR_OBS_VAR(funcList);
	zephir_read_property_this(&funcList, this_ptr, SL("_func"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$7);
		ZVAL_STRING(_2$$7, "acl:beforeCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$7, eventsManager, "fire", NULL, 0, _2$$7, this_ptr);
		zephir_check_temp_parameter(_2$$7);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_1$$7)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(rolesNames);
	zephir_read_property_this(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(rolesNames, roleName))) {
		_3$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(_3$$9, 1)));
	}
	ZEPHIR_INIT_VAR(accessKey);
	ZEPHIR_CONCAT_VSVSV(accessKey, roleName, "!", resourceName, "!", access);
	if (zephir_array_isset(accessList, accessKey)) {
		ZEPHIR_OBS_NVAR(haveAccess);
		zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 586 TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(funcAccess);
	zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(roleInherits);
		zephir_read_property_this(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, roleInherits, roleName, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_5$$13, &_4$$13, 0, 0, "phalcon/acl/adapter/memory.zep", 610);
				for (
				  ; zephir_hash_get_current_data_ex(_5$$13, (void**) &_6$$13, &_4$$13) == SUCCESS
				  ; zephir_hash_move_forward_ex(_5$$13, &_4$$13)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _6$$13);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVSV(accessKey, inheritedRole, "!", resourceName, "!", access);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 606 TSRMLS_CC);
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
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 625 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(funcAccess);
			zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_8$$19, &_7$$19, 0, 0, "phalcon/acl/adapter/memory.zep", 641);
				for (
				  ; zephir_hash_get_current_data_ex(_8$$19, (void**) &_9$$19, &_7$$19) == SUCCESS
				  ; zephir_hash_move_forward_ex(_8$$19, &_7$$19)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _9$$19);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VSVS(accessKey, inheritedRole, "!", resourceName, "!*");
					ZEPHIR_OBS_NVAR(funcAccess);
					zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 637 TSRMLS_CC);
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
			zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 656 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(funcAccess);
			zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(inheritedRoles, &_11$$25, &_10$$25, 0, 0, "phalcon/acl/adapter/memory.zep", 672);
				for (
				  ; zephir_hash_get_current_data_ex(_11$$25, (void**) &_12$$25, &_10$$25) == SUCCESS
				  ; zephir_hash_move_forward_ex(_11$$25, &_10$$25)
				) {
					ZEPHIR_GET_HVALUE(inheritedRole, _12$$25);
					ZEPHIR_INIT_NVAR(accessKey);
					ZEPHIR_CONCAT_VS(accessKey, inheritedRole, "!*!*");
					ZEPHIR_OBS_NVAR(funcAccess);
					zephir_array_isset_fetch(&funcAccess, funcList, accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(accessList, accessKey)) {
						ZEPHIR_OBS_NVAR(haveAccess);
						zephir_array_fetch(&haveAccess, accessList, accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 668 TSRMLS_CC);
						break;
					}
				}
			}
		}
	}
	zephir_update_property_this(this_ptr, SL("_accessGranted"), haveAccess TSRMLS_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_13$$28);
		ZVAL_STRING(_13$$28, "acl:afterCheckAccess", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, 0, _13$$28, this_ptr);
		zephir_check_temp_parameter(_13$$28);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(haveAccess) == IS_NULL) {
		_14$$29 = zephir_fetch_nproperty_this(this_ptr, SL("_defaultAccess"), PH_NOISY_CC);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(_14$$29, 1));
	}
	if (Z_TYPE_P(funcAccess) != IS_NULL) {
		ZEPHIR_INIT_VAR(reflectionFunction);
		object_init_ex(reflectionFunction, zephir_get_internal_ce(SS("reflectionfunction") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, reflectionFunction, "__construct", NULL, 85, funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, reflectionFunction, "getparameters", NULL, 86);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(parameterNumber);
		ZVAL_LONG(parameterNumber, zephir_fast_count_int(reflectionParameters TSRMLS_CC));
		if (ZEPHIR_IS_LONG_IDENTICAL(parameterNumber, 0)) {
			_15$$31 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_15$$31) {
				ZEPHIR_INIT_VAR(_16$$31);
				ZEPHIR_CALL_USER_FUNC(_16$$31, funcAccess);
				zephir_check_call_status();
				_15$$31 = zephir_is_true(_16$$31);
			}
			RETURN_MM_BOOL(_15$$31);
		}
		ZEPHIR_INIT_VAR(parametersForFunction);
		array_init(parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, reflectionFunction, "getnumberofrequiredparameters", NULL, 87);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(userParametersSizeShouldBe, parameterNumber);
		zephir_is_iterable(reflectionParameters, &_18$$30, &_17$$30, 0, 0, "phalcon/acl/adapter/memory.zep", 737);
		for (
		  ; zephir_hash_get_current_data_ex(_18$$30, (void**) &_19$$30, &_17$$30) == SUCCESS
		  ; zephir_hash_move_forward_ex(_18$$30, &_17$$30)
		) {
			ZEPHIR_GET_HVALUE(reflectionParameter, _19$$30);
			ZEPHIR_CALL_METHOD(&reflectionClass, reflectionParameter, "getclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(reflectionClass) != IS_NULL) {
				_20$$33 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_20$$33) {
					ZEPHIR_CALL_METHOD(&_21$$33, reflectionClass, "isinstance", NULL, 0, roleObject);
					zephir_check_call_status();
					_20$$33 = zephir_is_true(_21$$33);
				}
				if (_20$$33) {
					zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 709);
					ZEPHIR_SEPARATE(userParametersSizeShouldBe);
					zephir_decrement(userParametersSizeShouldBe);
					continue;
				}
				_22$$33 = Z_TYPE_P(resourceObject) != IS_NULL;
				if (_22$$33) {
					ZEPHIR_CALL_METHOD(&_23$$33, reflectionClass, "isinstance", NULL, 0, resourceObject);
					zephir_check_call_status();
					_22$$33 = zephir_is_true(_23$$33);
				}
				if (_22$$33) {
					zephir_array_append(&parametersForFunction, resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 717);
					ZEPHIR_SEPARATE(userParametersSizeShouldBe);
					zephir_decrement(userParametersSizeShouldBe);
					continue;
				}
				_24$$33 = zephir_array_isset(parameters, parameterToCheck);
				if (_24$$33) {
					ZEPHIR_OBS_NVAR(_25$$33);
					zephir_array_fetch(&_25$$33, parameters, parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 724 TSRMLS_CC);
					_24$$33 = Z_TYPE_P(_25$$33) == IS_OBJECT;
				}
				_26$$33 = _24$$33;
				if (_26$$33) {
					zephir_array_fetch(&_28$$33, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 724 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_27$$33, reflectionClass, "isinstance", NULL, 0, _28$$33);
					zephir_check_call_status();
					_26$$33 = !zephir_is_true(_27$$33);
				}
				if (_26$$33) {
					ZEPHIR_INIT_NVAR(_29$$36);
					object_init_ex(_29$$36, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(_30$$36);
					zephir_array_fetch(&_31$$36, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 726 TSRMLS_CC);
					zephir_get_class(_30$$36, _31$$36, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_32$$36, reflectionClass, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_33$$36);
					ZEPHIR_CONCAT_SVSVSVSVSVS(_33$$36, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", access, " ", resourceName, ". Class passed: ", _30$$36, " , Class in defined function: ", _32$$36, ".");
					ZEPHIR_CALL_METHOD(NULL, _29$$36, "__construct", &_34, 9, _33$$36);
					zephir_check_call_status();
					zephir_throw_exception_debug(_29$$36, "phalcon/acl/adapter/memory.zep", 727 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset(parameters, parameterToCheck)) {
				zephir_array_fetch(&_35$$37, parameters, parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 733 TSRMLS_CC);
				zephir_array_append(&parametersForFunction, _35$$37, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 733);
			}
		}
		if (ZEPHIR_LT_LONG(userParametersSizeShouldBe, zephir_fast_count_int(parameters TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(_36$$38);
			ZEPHIR_CONCAT_SVSVSVS(_36$$38, "Number of parameters in array is higher than the number of parameters in defined function when check ", roleName, " can ", access, " ", resourceName, ". Remember that more parameters than defined in function will be ignored.");
			ZEPHIR_SINIT_VAR(_37$$38);
			ZVAL_LONG(&_37$$38, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_38, 2, _36$$38, &_37$$38);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(parametersForFunction TSRMLS_CC) == 0) {
			if (ZEPHIR_GT_LONG(numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(_39$$40);
				ZEPHIR_CONCAT_SVSVSVS(_39$$40, "You didn't provide any parameters when check ", roleName, " can ", access, " ", resourceName, ". We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_38, 2, _39$$40);
				zephir_check_call_status();
				_40$$40 = ZEPHIR_IS_LONG(haveAccess, 1);
				if (_40$$40) {
					_41$$40 = zephir_fetch_nproperty_this(this_ptr, SL("_noArgumentsDefaultAction"), PH_NOISY_CC);
					_40$$40 = ZEPHIR_IS_LONG(_41$$40, 1);
				}
				RETURN_MM_BOOL(_40$$40);
			}
			_42$$39 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_42$$39) {
				ZEPHIR_INIT_VAR(_43$$39);
				ZEPHIR_CALL_USER_FUNC(_43$$39, funcAccess);
				zephir_check_call_status();
				_42$$39 = zephir_is_true(_43$$39);
			}
			RETURN_MM_BOOL(_42$$39);
		}
		if (ZEPHIR_LE_LONG(numberOfRequiredParameters, zephir_fast_count_int(parametersForFunction TSRMLS_CC))) {
			_44$$41 = ZEPHIR_IS_LONG(haveAccess, 1);
			if (_44$$41) {
				ZEPHIR_INIT_VAR(_45$$41);
				ZEPHIR_CALL_USER_FUNC_ARRAY(_45$$41, funcAccess, parametersForFunction);
				zephir_check_call_status();
				_44$$41 = zephir_is_true(_45$$41);
			}
			RETURN_MM_BOOL(_44$$41);
		}
		ZEPHIR_INIT_VAR(_46$$30);
		object_init_ex(_46$$30, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(_47$$30);
		ZEPHIR_CONCAT_SVSVSV(_47$$30, "You didn't provide all necessary parameters for defined function when check ", roleName, " can ", access, " ", resourceName);
		ZEPHIR_CALL_METHOD(NULL, _46$$30, "__construct", &_34, 9, _47$$30);
		zephir_check_call_status();
		zephir_throw_exception_debug(_46$$30, "phalcon/acl/adapter/memory.zep", 766 TSRMLS_CC);
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
	int defaultAccess;

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, defaultAccess);
	zephir_update_property_this(this_ptr, SL("_noArgumentsDefaultAction"), _0 TSRMLS_CC);

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	

	RETURN_MEMBER(this_ptr, "_noArgumentsDefaultAction");

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

