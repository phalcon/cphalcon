
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

	zval _0, _1;
	zval __$true;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_resourcesNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_accessList"), &_1);
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
	zval *role, role_sub, *accessInherits = NULL, accessInherits_sub, __$true, __$null, roleName, roleObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &role, &accessInherits);

	if (!accessInherits) {
		accessInherits = &accessInherits_sub;
		accessInherits = &__$null;
	}


	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&roleName, role, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_CPY_WRT(&roleName, role);
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 76, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either an string or implement RoleInterface", "phalcon/acl/adapter/memory.zep", 201);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("_roles"), &roleObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_rolesNames"), &roleName, &__$true TSRMLS_CC);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zend_bool _2;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherit, roleToInherit_sub, __$true, roleInheritName, rolesNames, deepInheritName, _3, _10, _0$$3, _4$$6, _5$$6, *_6$$6, _8$$8, _9$$8;
	zval roleName, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&roleToInherit_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&roleInheritName);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&deepInheritName);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherit);

	zephir_get_strval(&roleName, roleName_param);


	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, &roleName))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "Role '", &roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/acl/adapter/memory.zep", 227 TSRMLS_CC);
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
		ZEPHIR_CPY_WRT(&roleInheritName, roleToInherit);
	}
	zephir_read_property(&_3, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, &roleInheritName)) {
		zephir_read_property(&_4$$6, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_5$$6, &_4$$6, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 240 TSRMLS_CC);
		zephir_is_iterable(&_5$$6, 0, "phalcon/acl/adapter/memory.zep", 243);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5$$6), _6$$6)
		{
			ZEPHIR_INIT_NVAR(&deepInheritName);
			ZVAL_COPY(&deepInheritName, _6$$6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addinherit", &_7, 77, &roleName, &deepInheritName);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&deepInheritName);
	}
	if (!(zephir_array_isset(&rolesNames, &roleInheritName))) {
		ZEPHIR_INIT_VAR(&_8$$8);
		object_init_ex(&_8$$8, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_9$$8);
		ZEPHIR_CONCAT_SVS(&_9$$8, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_8$$8, "__construct", NULL, 4, &_9$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$8, "phalcon/acl/adapter/memory.zep", 249 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_10, this_ptr, SL("_roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_10, &roleName))) {
		zephir_update_property_array(this_ptr, SL("_roleInherits"), &roleName, &__$true TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("_roleInherits"), &roleInheritName TSRMLS_CC, SL("za"), 2, &roleName);
	RETURN_MM_BOOL(1);

}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zval *roleName_param = NULL, _0;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);

	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &roleName));

}

/**
 * Check whether resource exist in the resources list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isResource) {

	zval *resourceName_param = NULL, _0;
	zval resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &resourceName_param);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &resourceName));

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
	zval *resourceValue, resourceValue_sub, *accessList, accessList_sub, __$true, resourceName, resourceObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceValue_sub);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceValue, &accessList);



	_0 = Z_TYPE_P(resourceValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(resourceValue, phalcon_acl_resourceinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&resourceName, resourceValue, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&resourceObject, resourceValue);
	} else {
		ZEPHIR_CPY_WRT(&resourceName, resourceValue);
		ZEPHIR_INIT_NVAR(&resourceObject);
		object_init_ex(&resourceObject, phalcon_acl_resource_ce);
		ZEPHIR_CALL_METHOD(NULL, &resourceObject, "__construct", NULL, 78, &resourceName);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &resourceName))) {
		zephir_update_property_array_append(this_ptr, SL("_resources"), &resourceObject TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_resourcesNames"), &resourceName, &__$true TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addresourceaccess", NULL, 0, &resourceName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to resources
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addResourceAccess) {

	zend_bool exists = 0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, _0, _1$$3, *_4$$5, _5$$6, _6$$7, _7$$8, _8$$9;
	zval resourceName, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	zephir_read_property(&_0, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &resourceName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 348 TSRMLS_CC);
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
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 363);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _4$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			zephir_read_property(&_5$$6, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_5$$6, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				ZVAL_BOOL(&_6$$7, exists);
				zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_6$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", accessList);
		zephir_read_property(&_7$$8, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_7$$8, &accessKey))) {
			ZEPHIR_INIT_VAR(&_8$$9);
			ZVAL_BOOL(&_8$$9, exists);
			zephir_update_property_array(this_ptr, SL("_accessList"), &accessKey, &_8$$9 TSRMLS_CC);
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

	zval *resourceName_param = NULL, *accessList, accessList_sub, accessName, accessKey, *_0$$3, _1$$4, _2$$5, _3$$7, _4$$8;
	zval resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &resourceName_param, &accessList);

	zephir_get_strval(&resourceName, resourceName_param);


	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/acl/adapter/memory.zep", 389);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _0$$3);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			zephir_read_property(&_1$$4, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_1$$4, &accessKey)) {
				zephir_read_property(&_2$$5, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_2$$5, &accessKey, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			zephir_read_property(&_3$$7, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_3$$7, &accessKey)) {
				zephir_read_property(&_4$$8, this_ptr, SL("_accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_4$$8, &accessKey, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a role has access to a resource
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, _allowOrDeny) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _3, _1$$3, _4$$4, *_6$$5, *_9$$5, _7$$7, _8$$7, _10$$12, _11$$12;
	zval roleName, resourceName, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &resourceName_param, &access, &action, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &roleName))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/acl/adapter/memory.zep", 407 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_resourcesNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &resourceName))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Resource '", &resourceName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 4, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/acl/adapter/memory.zep", 411 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_accessList"), PH_NOISY_CC);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 425);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _6$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _6$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", &accessName);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				object_init_ex(&_7$$7, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$7);
				ZEPHIR_CONCAT_SVSVS(&_8$$7, "Access '", &accessName, "' does not exist in resource '", &resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 4, &_8$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$7, "phalcon/acl/adapter/memory.zep", 421 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/acl/adapter/memory.zep", 434);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _9$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _9$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", &accessName);
			zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action TSRMLS_CC);
			if (Z_TYPE_P(func) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &resourceName, "!", access);
			if (!(zephir_array_isset(&accessList, &accessKey))) {
				ZEPHIR_INIT_VAR(&_10$$12);
				object_init_ex(&_10$$12, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_11$$12);
				ZEPHIR_CONCAT_SVSVS(&_11$$12, "Access '", access, "' does not exist in resource '", &resourceName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", NULL, 4, &_11$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$12, "phalcon/acl/adapter/memory.zep", 439 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &resourceName, "!", access);
		zephir_update_property_array(this_ptr, SL("_access"), &accessKey, action TSRMLS_CC);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("_func"), &accessKey, func TSRMLS_CC);
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

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval roleName, resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 486);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&innerRoleName);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&innerRoleName, _5$$4);
			} else {
				ZVAL_LONG(&innerRoleName, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZVAL_LONG(&_6$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
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

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *resourceName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval roleName, resourceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&resourceName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &resourceName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&resourceName, resourceName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_allowordeny", NULL, 0, &roleName, &resourceName, access, &_0$$3, func);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("_rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/acl/adapter/memory.zep", 519);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&innerRoleName);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&innerRoleName, _5$$4);
			} else {
				ZVAL_LONG(&innerRoleName, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&_2$$4);
			ZVAL_COPY(&_2$$4, _3$$4);
			ZVAL_LONG(&_6$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_allowordeny", NULL, 0, &innerRoleName, &resourceName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
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

	zend_bool hasRole, hasResource, _11$$35, _14$$37, _16$$37, _17$$37, _19$$37, _20$$37, _22$$37, _35$$44, _37$$43, _39$$45;
	zephir_fcall_cache_entry *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access;
	zval *roleName = NULL, roleName_sub, *resourceName = NULL, resourceName_sub, *access_param = NULL, *parameters_param = NULL, eventsManager, accessList, accessKey, haveAccess, roleInherits, inheritedRole, rolesNames, inheritedRoles, funcAccess, resourceObject, roleObject, funcList, reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction, numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck, reflectionParameter, _2, _0$$5, _1$$9, _3$$11, _4$$11, _5$$13, *_6$$17, *_7$$23, *_8$$29, _9$$32, _10$$33, _12$$35, *_13$$34, _41$$34, _42$$34, _15$$37, _18$$37, _21$$37, _23$$37, _24$$37, _25$$40, _26$$40, _27$$40, _28$$40, _29$$40, _31$$41, _32$$42, _33$$42, _34$$44, _36$$44, _38$$43, _40$$45;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&resourceName_sub);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&roleInherits);
	ZVAL_UNDEF(&inheritedRole);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&inheritedRoles);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&resourceObject);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_9$$32);
	ZVAL_UNDEF(&_10$$33);
	ZVAL_UNDEF(&_12$$35);
	ZVAL_UNDEF(&_41$$34);
	ZVAL_UNDEF(&_42$$34);
	ZVAL_UNDEF(&_15$$37);
	ZVAL_UNDEF(&_18$$37);
	ZVAL_UNDEF(&_21$$37);
	ZVAL_UNDEF(&_23$$37);
	ZVAL_UNDEF(&_24$$37);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&_26$$40);
	ZVAL_UNDEF(&_27$$40);
	ZVAL_UNDEF(&_28$$40);
	ZVAL_UNDEF(&_29$$40);
	ZVAL_UNDEF(&_31$$41);
	ZVAL_UNDEF(&_32$$42);
	ZVAL_UNDEF(&_33$$42);
	ZVAL_UNDEF(&_34$$44);
	ZVAL_UNDEF(&_36$$44);
	ZVAL_UNDEF(&_38$$43);
	ZVAL_UNDEF(&_40$$45);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &resourceName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(resourceName);
	zephir_get_strval(&access, access_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&haveAccess);
	ZVAL_NULL(&haveAccess);
	ZEPHIR_INIT_VAR(&funcAccess);
	ZVAL_NULL(&funcAccess);
	ZEPHIR_INIT_VAR(&resourceObject);
	ZVAL_NULL(&resourceObject);
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	hasRole = 0;
	hasResource = 0;
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&roleObject, roleName);
			ZEPHIR_CALL_METHOD(roleName, &roleObject, "getrolename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(roleName, phalcon_acl_roleinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_0$$5, roleName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(roleName, &_0$$5);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface", "phalcon/acl/adapter/memory.zep", 552);
			return;
		}
	}
	if (Z_TYPE_P(resourceName) == IS_OBJECT) {
		if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&resourceObject, resourceName);
			ZEPHIR_CALL_METHOD(resourceName, &resourceObject, "getresourcename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(resourceName, phalcon_acl_resourceinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_1$$9, resourceName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(resourceName, &_1$$9);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as resourceName must implement Phalcon\\Acl\\ResourceAware or Phalcon\\Acl\\ResourceInterface", "phalcon/acl/adapter/memory.zep", 563);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_activeRole"), roleName);
	zephir_update_property_zval(this_ptr, SL("_activeResource"), resourceName);
	zephir_update_property_zval(this_ptr, SL("_activeAccess"), &access);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("_access"), PH_NOISY_CC);
	zephir_read_property(&_2, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("_func"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$11);
		ZVAL_STRING(&_4$$11, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_3$$11, &eventsManager, "fire", NULL, 0, &_4$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(&rolesNames);
	zephir_read_property(&rolesNames, this_ptr, SL("_rolesNames"), PH_NOISY_CC);
	if (!(zephir_array_isset(&rolesNames, roleName))) {
		zephir_read_property(&_5$$13, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_5$$13, 1)));
	}
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VSVSV(&accessKey, roleName, "!", resourceName, "!", &access);
	if (zephir_array_isset(&accessList, &accessKey)) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 595 TSRMLS_CC);
	}
	ZEPHIR_OBS_NVAR(&funcAccess);
	zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_OBS_VAR(&roleInherits);
		zephir_read_property(&roleInherits, this_ptr, SL("_roleInherits"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(&inheritedRoles);
		if (zephir_array_isset_fetch(&inheritedRoles, &roleInherits, roleName, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 619);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _6$$17)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _6$$17);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVSV(&accessKey, &inheritedRole, "!", resourceName, "!", &access);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 615 TSRMLS_CC);
					}
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVS(&accessKey, roleName, "!", resourceName, "!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 634 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&funcAccess);
			zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 650);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _7$$23)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _7$$23);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVS(&accessKey, &inheritedRole, "!", resourceName, "!*");
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 646 TSRMLS_CC);
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VS(&accessKey, roleName, "!*!*");
		if (zephir_array_isset(&accessList, &accessKey)) {
			ZEPHIR_OBS_NVAR(&haveAccess);
			zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 665 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&funcAccess);
			zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
		} else {
			if (Z_TYPE_P(&inheritedRoles) == IS_ARRAY) {
				zephir_is_iterable(&inheritedRoles, 0, "phalcon/acl/adapter/memory.zep", 681);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&inheritedRoles), _8$$29)
				{
					ZEPHIR_INIT_NVAR(&inheritedRole);
					ZVAL_COPY(&inheritedRole, _8$$29);
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VS(&accessKey, &inheritedRole, "!*!*");
					ZEPHIR_OBS_NVAR(&funcAccess);
					zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
					if (zephir_array_isset(&accessList, &accessKey)) {
						ZEPHIR_OBS_NVAR(&haveAccess);
						zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/acl/adapter/memory.zep", 677 TSRMLS_CC);
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&inheritedRole);
			}
		}
	}
	zephir_update_property_zval(this_ptr, SL("_accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_9$$32);
		ZVAL_STRING(&_9$$32, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_9$$32, this_ptr);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		zephir_read_property(&_10$$33, this_ptr, SL("_defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_10$$33, 1));
	}
	if (Z_TYPE_P(&funcAccess) != IS_NULL) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 79, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 80);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters TSRMLS_CC));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_11$$35 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_11$$35) {
				ZEPHIR_INIT_VAR(&_12$$35);
				ZEPHIR_CALL_USER_FUNC(&_12$$35, &funcAccess);
				zephir_check_call_status();
				_11$$35 = zephir_is_true(&_12$$35);
			}
			RETURN_MM_BOOL(_11$$35);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 81);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/acl/adapter/memory.zep", 748);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _13$$34)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _13$$34);
			ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
				_14$$37 = Z_TYPE_P(&roleObject) != IS_NULL;
				if (_14$$37) {
					ZEPHIR_CALL_METHOD(&_15$$37, &reflectionClass, "isinstance", NULL, 0, &roleObject);
					zephir_check_call_status();
					_14$$37 = zephir_is_true(&_15$$37);
				}
				_16$$37 = _14$$37;
				if (_16$$37) {
					_16$$37 = !hasRole;
				}
				if (_16$$37) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 719);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_17$$37 = Z_TYPE_P(&resourceObject) != IS_NULL;
				if (_17$$37) {
					ZEPHIR_CALL_METHOD(&_18$$37, &reflectionClass, "isinstance", NULL, 0, &resourceObject);
					zephir_check_call_status();
					_17$$37 = zephir_is_true(&_18$$37);
				}
				_19$$37 = _17$$37;
				if (_19$$37) {
					_19$$37 = !hasResource;
				}
				if (_19$$37) {
					hasResource = 1;
					zephir_array_append(&parametersForFunction, &resourceObject, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 728);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_20$$37 = zephir_array_isset(&parameters, &parameterToCheck);
				if (_20$$37) {
					ZEPHIR_OBS_NVAR(&_21$$37);
					zephir_array_fetch(&_21$$37, &parameters, &parameterToCheck, PH_NOISY, "phalcon/acl/adapter/memory.zep", 735 TSRMLS_CC);
					_20$$37 = Z_TYPE_P(&_21$$37) == IS_OBJECT;
				}
				_22$$37 = _20$$37;
				if (_22$$37) {
					zephir_array_fetch(&_24$$37, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 735 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_23$$37, &reflectionClass, "isinstance", NULL, 0, &_24$$37);
					zephir_check_call_status();
					_22$$37 = !zephir_is_true(&_23$$37);
				}
				if (_22$$37) {
					ZEPHIR_INIT_NVAR(&_25$$40);
					object_init_ex(&_25$$40, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_26$$40);
					zephir_array_fetch(&_27$$40, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 737 TSRMLS_CC);
					zephir_get_class(&_26$$40, &_27$$40, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_28$$40, &reflectionClass, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_29$$40);
					ZEPHIR_CONCAT_SVSVSVSVSVS(&_29$$40, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Class passed: ", &_26$$40, " , Class in defined function: ", &_28$$40, ".");
					ZEPHIR_CALL_METHOD(NULL, &_25$$40, "__construct", &_30, 4, &_29$$40);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_25$$40, "phalcon/acl/adapter/memory.zep", 738 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset(&parameters, &parameterToCheck)) {
				zephir_array_fetch(&_31$$41, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/acl/adapter/memory.zep", 744 TSRMLS_CC);
				zephir_array_append(&parametersForFunction, &_31$$41, PH_SEPARATE, "phalcon/acl/adapter/memory.zep", 744);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		if (ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_32$$42);
			ZEPHIR_CONCAT_SVSVSVS(&_32$$42, "Number of parameters in array is higher than the number of parameters in defined function when check ", roleName, " can ", &access, " ", resourceName, ". Remember that more parameters than defined in function will be ignored.");
			ZVAL_LONG(&_33$$42, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_32$$42, &_33$$42);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction TSRMLS_CC) == 0) {
			if (ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(&_34$$44);
				ZEPHIR_CONCAT_SVSVSVS(&_34$$44, "You didn't provide any parameters when check ", roleName, " can ", &access, " ", resourceName, ". We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_34$$44);
				zephir_check_call_status();
				_35$$44 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_35$$44) {
					zephir_read_property(&_36$$44, this_ptr, SL("_noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_35$$44 = ZEPHIR_IS_LONG(&_36$$44, 1);
				}
				RETURN_MM_BOOL(_35$$44);
			}
			_37$$43 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_37$$43) {
				ZEPHIR_INIT_VAR(&_38$$43);
				ZEPHIR_CALL_USER_FUNC(&_38$$43, &funcAccess);
				zephir_check_call_status();
				_37$$43 = zephir_is_true(&_38$$43);
			}
			RETURN_MM_BOOL(_37$$43);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction TSRMLS_CC))) {
			_39$$45 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_39$$45) {
				ZEPHIR_INIT_VAR(&_40$$45);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_40$$45, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_39$$45 = zephir_is_true(&_40$$45);
			}
			RETURN_MM_BOOL(_39$$45);
		}
		ZEPHIR_INIT_VAR(&_41$$34);
		object_init_ex(&_41$$34, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_42$$34);
		ZEPHIR_CONCAT_SVSVSV(&_42$$34, "You didn't provide all necessary parameters for defined function when check ", roleName, " can ", &access, " ", resourceName);
		ZEPHIR_CALL_METHOD(NULL, &_41$$34, "__construct", &_30, 4, &_42$$34);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_41$$34, "phalcon/acl/adapter/memory.zep", 777 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));

}

/**
 * Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("_noArgumentsDefaultAction"), &_0);

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_noArgumentsDefaultAction");

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_roles");

}

/**
 * Return an array with every resource registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getResources) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_resources");

}

