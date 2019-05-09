
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * // Private area components
 * $privateComponents = [
 *     "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
 *     "invoices"  => ["index", "profile"],
 * ];
 *
 * foreach ($privateComponents as $componentName => $actions) {
 *     $acl->addComponent(
 *         new \Phalcon\Acl\Component($componentName),
 *         $actions
 *     );
 * }
 *
 * // Public area components
 * $publicComponents = [
 *     "index"   => ["index"],
 *     "about"   => ["index"],
 *     "session" => ["index", "register", "start", "end"],
 *     "contact" => ["index", "send"],
 * ];
 *
 * foreach ($publicComponents as $componentName => $actions) {
 *     $acl->addComponent(
 *         new \Phalcon\Acl\Component($componentName),
 *         $actions
 *     );
 * }
 *
 * // Grant access to public areas to both users and guests
 * foreach ($roles as $role){
 *     foreach ($publicComponents as $component => $actions) {
 *         $acl->allow($role->getName(), $component, "*");
 *     }
 * }
 *
 * // Grant access to private area to role Users
 * foreach ($privateComponents as $component => $actions) {
 *     foreach ($actions as $action) {
 *         $acl->allow("Users", $component, $action);
 *     }
 * }
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("access"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("accessList"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns latest function used to acquire access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeFunction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns number of additional arguments(excluding role and resource) for active function
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("activeFunctionCustomArgumentsCount"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Returns latest key used to acquire access
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("func"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("noArgumentsDefaultAction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Roles
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roleInherits"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("rolesNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Components
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("components"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Component Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("componentsNames"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns latest function used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeFunction");

}

/**
 * Returns number of additional arguments(excluding role and resource) for active function
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeFunctionCustomArgumentsCount");

}

/**
 * Returns latest key used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "activeKey");

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
	zephir_update_property_zval(this_ptr, SL("componentsNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("accessList"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Do a role inherit from another existing role
 *
 * Example:
 * <code>
 *
 * $acl->addRole("administrator", "consultant");
 * $acl->addRole("administrator", ["consultant", "consultant2"]);
 * </code>
 *
 * @param  array|string               accessInherits
 * @param  RoleInterface|string|array role
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zend_bool _5$$7;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, rolesNames, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, *_4, _1$$3, _3$$4, _6$$7, _7$$7, _10$$7, _8$$11, _9$$11, _11$$13, _12$$13, *_13$$13, _16$$17, _17$$17, _18$$15, _19$$18, _20$$18, *_21$$18;
	zval roleName, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&roleToInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&roleInheritName);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&roleToInherit);
	ZVAL_UNDEF(&checkRoleToInherit);
	ZVAL_UNDEF(&roleToInheritList);
	ZVAL_UNDEF(&usedRoleToInherit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_16$$17);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&usedRoleToInherits);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherits);

	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rolesNames, &_0);
	if (UNEXPECTED(!(zephir_array_isset(&rolesNames, &roleName)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in the role list");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 209 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &roleName))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		array_init(&_3$$4);
		zephir_update_property_array(this_ptr, SL("roleInherits"), &roleName, &_3$$4 TSRMLS_CC);
	}
	if (Z_TYPE_P(roleToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&roleToInheritList);
		zephir_create_array(&roleToInheritList, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&roleToInheritList, roleToInherits);
	} else {
		ZEPHIR_CPY_WRT(&roleToInheritList, roleToInherits);
	}
	zephir_is_iterable(&roleToInheritList, 0, "phalcon/Acl/Adapter/Memory.zep", 296);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&roleToInheritList), _4)
	{
		ZEPHIR_INIT_NVAR(&roleToInherit);
		ZVAL_COPY(&roleToInherit, _4);
		_5$$7 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
		if (_5$$7) {
			_5$$7 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce TSRMLS_CC);
		}
		if (_5$$7) {
			ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
		}
		zephir_read_property(&_6$$7, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$7, &_6$$7, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 238 TSRMLS_CC);
		if (zephir_fast_in_array(&roleInheritName, &_7$$7 TSRMLS_CC)) {
			continue;
		}
		if (UNEXPECTED(!(zephir_array_isset(&rolesNames, &roleInheritName)))) {
			ZEPHIR_INIT_NVAR(&_8$$11);
			object_init_ex(&_8$$11, phalcon_acl_exception_ce);
			ZEPHIR_INIT_LNVAR(_9$$11);
			ZEPHIR_CONCAT_SVS(&_9$$11, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
			ZEPHIR_CALL_METHOD(NULL, &_8$$11, "__construct", NULL, 1, &_9$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_8$$11, "phalcon/Acl/Adapter/Memory.zep", 248 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_10$$7, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_10$$7, &roleInheritName)) {
			ZEPHIR_INIT_NVAR(&checkRoleToInherits);
			array_init(&checkRoleToInherits);
			zephir_read_property(&_11$$13, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$13, &_11$$13, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 261 TSRMLS_CC);
			zephir_is_iterable(&_12$$13, 0, "phalcon/Acl/Adapter/Memory.zep", 265);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$13), _13$$13)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _13$$13);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_14, 108, &checkRoleToInherits, &usedRoleToInherit);
				ZEPHIR_UNREF(&checkRoleToInherits);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			ZEPHIR_INIT_NVAR(&usedRoleToInherits);
			array_init(&usedRoleToInherits);
			while (1) {
				if (!(!(ZEPHIR_IS_EMPTY(&checkRoleToInherits)))) {
					break;
				}
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_15, 10, &checkRoleToInherits);
				ZEPHIR_UNREF(&checkRoleToInherits);
				zephir_check_call_status();
				if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
					continue;
				}
				zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName, &checkRoleToInherit))) {
					ZEPHIR_INIT_NVAR(&_16$$17);
					object_init_ex(&_16$$17, phalcon_acl_exception_ce);
					ZEPHIR_INIT_LNVAR(_17$$17);
					ZEPHIR_CONCAT_SVS(&_17$$17, "Role '", &roleInheritName, "' (to inherit) is infinite loop ");
					ZEPHIR_CALL_METHOD(NULL, &_16$$17, "__construct", NULL, 1, &_17$$17);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_16$$17, "phalcon/Acl/Adapter/Memory.zep", 279 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property(&_18$$15, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_18$$15, &checkRoleToInherit)) {
					zephir_read_property(&_19$$18, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_20$$18, &_19$$18, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 286 TSRMLS_CC);
					zephir_is_iterable(&_20$$18, 0, "phalcon/Acl/Adapter/Memory.zep", 289);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_20$$18), _21$$18)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _21$$18);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_14, 108, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				}
			}
		}
		zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName TSRMLS_CC, SL("za"), 2, &roleName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&roleToInherit);
	RETURN_MM_BOOL(1);

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
 * $acl->addRole("administrator", ["consultant", "consultant2"]);
 * </code>
 *
 * @param  array|string               accessInherits
 * @param  RoleInterface|string|array role
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
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 109, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either an string or implement RoleInterface", "phalcon/Acl/Adapter/Memory.zep", 327);
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 110);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("roles"), &roleObject TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("rolesNames"), &roleName, &__$true TSRMLS_CC);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * <code>
 * // Add a component to the the list allowing access to an action
 * $acl->addComponent(
 *     new Phalcon\Acl\Component("customers"),
 *     "search"
 * );
 *
 * $acl->addComponent("customers", "search");
 *
 * // Add a component  with an access list
 * $acl->addComponent(
 *     new Phalcon\Acl\Component("customers"),
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 *
 * $acl->addComponent(
 *     "customers",
 *     [
 *         "create",
 *         "search",
 *     ]
 * );
 * </code>
 *
 * @param   Phalcon\Acl\Component|string componentValue
 * @param   array|string                 accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponent) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *componentValue, componentValue_sub, *accessList, accessList_sub, __$true, componentName, componentObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentValue_sub);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentValue, &accessList);



	_0 = Z_TYPE_P(componentValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(componentValue, phalcon_acl_componentinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&componentObject, componentValue);
	} else {
		ZEPHIR_INIT_NVAR(&componentObject);
		object_init_ex(&componentObject, phalcon_acl_component_ce);
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 111, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 112);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &componentName))) {
		zephir_update_property_array_append(this_ptr, SL("components"), &componentObject TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("componentsNames"), &componentName, &__$true TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addcomponentaccess", NULL, 0, &componentName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to components
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess) {

	zend_bool exists = 0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *componentName_param = NULL, *accessList, accessList_sub, accessName, _0, _1$$3, *_4$$5, _5$$6, _6$$6, _7$$7, _8$$8, _9$$8, _10$$9;
	zval componentName, accessKey, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentName_param, &accessList);

	zephir_get_strval(&componentName, componentName_param);


	zephir_read_property(&_0, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_0, &componentName)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Component '", &componentName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 417 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/Acl/Adapter/Memory.zep", 421);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 434);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _4$$5);
			ZEPHIR_INIT_LNVAR(_5$$6);
			ZEPHIR_CONCAT_VSV(&_5$$6, &componentName, "!", &accessName);
			zephir_get_strval(&accessKey, &_5$$6);
			zephir_read_property(&_6$$6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
			if (!(zephir_array_isset(&_6$$6, &accessKey))) {
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZVAL_BOOL(&_7$$7, exists);
				zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_7$$7 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_VAR(&_8$$8);
		ZEPHIR_CONCAT_VSV(&_8$$8, &componentName, "!", accessList);
		zephir_get_strval(&accessKey, &_8$$8);
		zephir_read_property(&_9$$8, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_9$$8, &accessKey))) {
			ZEPHIR_INIT_VAR(&_10$$9);
			ZVAL_BOOL(&_10$$9, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_10$$9 TSRMLS_CC);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Allow access to a role on a component
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
 * //Allow access to any role to browse on any component
 * $acl->allow("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &componentName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 113, &roleName, &componentName, access, &_0$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/Acl/Adapter/Memory.zep", 487);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 113, &innerRoleName, &componentName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deny access to a role on a component
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
 * //Deny access to any role to browse on any component
 * $acl->deny("*", "*", "browse");
 * </code>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _6$$5;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &componentName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	if (!ZEPHIR_IS_STRING(&roleName, "*")) {
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 113, &roleName, &componentName, access, &_0$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/Acl/Adapter/Memory.zep", 526);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 113, &innerRoleName, &componentName, access, &_6$$5, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an access from a component
 *
 * @param array|string accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess) {

	zval *componentName_param = NULL, *accessList = NULL, accessList_sub, accessName, *_0$$4, _1$$5, _2$$5, _3$$6;
	zval componentName, accessKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentName_param, &accessList);

	zephir_get_strval(&componentName, componentName_param);
	ZEPHIR_SEPARATE_PARAM(accessList);


	if (Z_TYPE_P(accessList) == IS_STRING) {
		ZEPHIR_INIT_NVAR(accessList);
		zephir_create_array(accessList, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(accessList, accessList);
	}
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 551);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _0$$4)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _0$$4);
			ZEPHIR_INIT_LNVAR(_1$$5);
			ZEPHIR_CONCAT_VSV(&_1$$5, &componentName, "!", &accessName);
			zephir_get_strval(&accessKey, &_1$$5);
			zephir_read_property(&_2$$5, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_2$$5, &accessKey)) {
				zephir_read_property(&_3$$6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_3$$6, &accessKey, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default ACL access level for no arguments provided in
 * isAllowed action if there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "noArgumentsDefaultAction");

}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "roles");

}

/**
 * Return an array with every component registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getComponents) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "components");

}

/**
 * Check whether a role is allowed to access an action from a component
 *
 * <code>
 * //Does andres have access to the customers component to create?
 * $acl->isAllowed("andres", "Products", "create");
 *
 * //Do guests have access to any component to edit?
 * $acl->isAllowed("guests", "*", "edit");
 * </code>
 *
 * @param  RoleInterface|RoleAware|string roleName
 * @param  ComponentInterface|ComponentAware|string componentName
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool hasRole, hasComponent, _6, _10$$18, _13$$20, _15$$20, _16$$20, _18$$20, _19$$20, _21$$20, _34$$27, _36$$26, _38$$28;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, *access_param = NULL, *parameters_param = NULL, __$null, eventsManager, accessList, accessKey, haveAccess, rolesNames, funcAccess, componentObject, roleObject, funcList, reflectionFunction, reflectionParameters, parameterNumber, parametersForFunction, numberOfRequiredParameters, userParametersSizeShouldBe, reflectionClass, parameterToCheck, reflectionParameter, _2, _0$$5, _1$$9, _3$$11, _4$$11, _5$$13, _7$$15, _8$$16, _9$$16, _11$$18, *_12$$17, _40$$17, _41$$17, _14$$20, _17$$20, _20$$20, _22$$20, _23$$20, _24$$23, _25$$23, _26$$23, _27$$23, _28$$23, _30$$24, _31$$25, _32$$25, _33$$27, _35$$27, _37$$26, _39$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&componentName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&componentObject);
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
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_9$$16);
	ZVAL_UNDEF(&_11$$18);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_17$$20);
	ZVAL_UNDEF(&_20$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$23);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$23);
	ZVAL_UNDEF(&_28$$23);
	ZVAL_UNDEF(&_30$$24);
	ZVAL_UNDEF(&_31$$25);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$27);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &componentName, &access_param, &parameters_param);

	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(componentName);
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
	ZEPHIR_INIT_VAR(&componentObject);
	ZVAL_NULL(&componentObject);
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	hasRole = 0;
	hasComponent = 0;
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as roleName must implement Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface", "phalcon/Acl/Adapter/Memory.zep", 612);
			return;
		}
	}
	if (Z_TYPE_P(componentName) == IS_OBJECT) {
		if (zephir_instance_of_ev(componentName, phalcon_acl_componentaware_ce TSRMLS_CC)) {
			ZEPHIR_CPY_WRT(&componentObject, componentName);
			ZEPHIR_CALL_METHOD(componentName, &componentObject, "getcomponentname", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(componentName, phalcon_acl_componentinterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_1$$9, componentName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(componentName, &_1$$9);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Object passed as componentName must implement Phalcon\\Acl\\ComponentAware or Phalcon\\Acl\\ComponentInterface", "phalcon/Acl/Adapter/Memory.zep", 625);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("activeRole"), roleName);
	zephir_update_property_zval(this_ptr, SL("activeComponent"), componentName);
	zephir_update_property_zval(this_ptr, SL("activeAccess"), &access);
	zephir_update_property_zval(this_ptr, SL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &__$null);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &_2);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("access"), PH_NOISY_CC);
	zephir_read_property(&_2, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("func"), PH_NOISY_CC);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$11);
		ZVAL_STRING(&_4$$11, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_3$$11, &eventsManager, "fire", NULL, 0, &_4$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_2, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rolesNames, &_2);
	if (!(zephir_array_isset(&rolesNames, roleName))) {
		zephir_read_property(&_5$$13, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_5$$13, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 114, roleName, componentName, &access);
	zephir_check_call_status();
	_6 = !ZEPHIR_IS_FALSE(&accessKey);
	if (_6) {
		_6 = zephir_array_isset(&accessList, &accessKey);
	}
	if (_6) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 661 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0 TSRMLS_CC);
	}
	zephir_update_property_zval(this_ptr, SL("accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_7$$15);
		ZVAL_STRING(&_7$$15, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_7$$15, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("activeKey"), &accessKey);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$16);
		ZEPHIR_CONCAT_VSVSV(&_8$$16, roleName, "!", componentName, "!", &access);
		zephir_update_property_zval(this_ptr, SL("activeKey"), &_8$$16);
		zephir_read_property(&_9$$16, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_9$$16, 1));
	}
	if (zephir_is_callable(&funcAccess TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 115, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 116);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters TSRMLS_CC));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_10$$18 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_10$$18) {
				ZEPHIR_INIT_VAR(&_11$$18);
				ZEPHIR_CALL_USER_FUNC(&_11$$18, &funcAccess);
				zephir_check_call_status();
				_10$$18 = zephir_is_true(&_11$$18);
			}
			RETURN_MM_BOOL(_10$$18);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 117);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/Acl/Adapter/Memory.zep", 751);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _12$$17)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _12$$17);
			ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
				_13$$20 = Z_TYPE_P(&roleObject) != IS_NULL;
				if (_13$$20) {
					ZEPHIR_CALL_METHOD(&_14$$20, &reflectionClass, "isinstance", NULL, 0, &roleObject);
					zephir_check_call_status();
					_13$$20 = zephir_is_true(&_14$$20);
				}
				_15$$20 = _13$$20;
				if (_15$$20) {
					_15$$20 = !hasRole;
				}
				if (_15$$20) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 716);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_16$$20 = Z_TYPE_P(&componentObject) != IS_NULL;
				if (_16$$20) {
					ZEPHIR_CALL_METHOD(&_17$$20, &reflectionClass, "isinstance", NULL, 0, &componentObject);
					zephir_check_call_status();
					_16$$20 = zephir_is_true(&_17$$20);
				}
				_18$$20 = _16$$20;
				if (_18$$20) {
					_18$$20 = !hasComponent;
				}
				if (_18$$20) {
					hasComponent = 1;
					zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 725);
					ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_19$$20 = zephir_array_isset(&parameters, &parameterToCheck);
				if (_19$$20) {
					ZEPHIR_OBS_NVAR(&_20$$20);
					zephir_array_fetch(&_20$$20, &parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 735 TSRMLS_CC);
					_19$$20 = Z_TYPE_P(&_20$$20) == IS_OBJECT;
				}
				_21$$20 = _19$$20;
				if (_21$$20) {
					zephir_array_fetch(&_23$$20, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 735 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_22$$20, &reflectionClass, "isinstance", NULL, 0, &_23$$20);
					zephir_check_call_status();
					_21$$20 = !zephir_is_true(&_22$$20);
				}
				if (UNEXPECTED(_21$$20)) {
					ZEPHIR_INIT_NVAR(&_24$$23);
					object_init_ex(&_24$$23, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_25$$23);
					zephir_array_fetch(&_26$$23, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 737 TSRMLS_CC);
					zephir_get_class(&_25$$23, &_26$$23, 0 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_27$$23, &reflectionClass, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$23);
					ZEPHIR_CONCAT_SVSVSVSVSVS(&_28$$23, "Your passed parameter doesn't have the same class as the parameter in defined function when check ", roleName, " can ", &access, " ", componentName, ". Class passed: ", &_25$$23, " , Class in defined function: ", &_27$$23, ".");
					ZEPHIR_CALL_METHOD(NULL, &_24$$23, "__construct", &_29, 1, &_28$$23);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$23, "phalcon/Acl/Adapter/Memory.zep", 738 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset(&parameters, &parameterToCheck)) {
				zephir_array_fetch(&_30$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 747 TSRMLS_CC);
				zephir_array_append(&parametersForFunction, &_30$$24, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 747);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
		if (ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_31$$25);
			ZEPHIR_CONCAT_SVSVSVS(&_31$$25, "Number of parameters in array is higher than the number of parameters in defined function when check ", roleName, " can ", &access, " ", componentName, ". Remember that more parameters than defined in function will be ignored.");
			ZVAL_LONG(&_32$$25, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_31$$25, &_32$$25);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction TSRMLS_CC) == 0) {
			if (ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0)) {
				ZEPHIR_INIT_VAR(&_33$$27);
				ZEPHIR_CONCAT_SVSVSVS(&_33$$27, "You didn't provide any parameters when '", roleName, "' can '", &access, "' '", componentName, "'. We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_33$$27);
				zephir_check_call_status();
				_34$$27 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_34$$27) {
					zephir_read_property(&_35$$27, this_ptr, SL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_34$$27 = ZEPHIR_IS_LONG(&_35$$27, 1);
				}
				RETURN_MM_BOOL(_34$$27);
			}
			_36$$26 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_36$$26) {
				ZEPHIR_INIT_VAR(&_37$$26);
				ZEPHIR_CALL_USER_FUNC(&_37$$26, &funcAccess);
				zephir_check_call_status();
				_36$$26 = zephir_is_true(&_37$$26);
			}
			RETURN_MM_BOOL(_36$$26);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction TSRMLS_CC))) {
			_38$$28 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_38$$28) {
				ZEPHIR_INIT_VAR(&_39$$28);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_39$$28, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_38$$28 = zephir_is_true(&_39$$28);
			}
			RETURN_MM_BOOL(_38$$28);
		}
		ZEPHIR_INIT_VAR(&_40$$17);
		object_init_ex(&_40$$17, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_41$$17);
		ZEPHIR_CONCAT_SVSVSV(&_41$$17, "You didn't provide all necessary parameters for defined function when check ", roleName, " can ", &access, " ", componentName);
		ZEPHIR_CALL_METHOD(NULL, &_40$$17, "__construct", &_29, 1, &_41$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_40$$17, "phalcon/Acl/Adapter/Memory.zep", 788 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));

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


	zephir_read_property(&_0, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &roleName));

}

/**
 * Check whether component exist in the components list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isComponent) {

	zval *componentName_param = NULL, _0;
	zval componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &componentName_param);

	zephir_get_strval(&componentName, componentName_param);


	zephir_read_property(&_0, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &componentName));

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
	zephir_update_property_zval(this_ptr, SL("noArgumentsDefaultAction"), &_0);

}

/**
 * Checks if a role has access to a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _3, _6, _1$$3, _4$$4, *_7$$5, *_10$$5, _8$$7, _9$$7, _11$$12, _12$$12;
	zval roleName, componentName, _2$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &componentName_param, &access, &action, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_0, &roleName)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 1, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 830 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_3, &componentName)))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Component '", &componentName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 1, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Acl/Adapter/Memory.zep", 836 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_6);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 852);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _7$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _7$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", &accessName);
			if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
				ZEPHIR_INIT_NVAR(&_8$$7);
				object_init_ex(&_8$$7, phalcon_acl_exception_ce);
				ZEPHIR_INIT_LNVAR(_9$$7);
				ZEPHIR_CONCAT_SVSVS(&_9$$7, "Access '", &accessName, "' does not exist in component '", &componentName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_8$$7, "__construct", NULL, 1, &_9$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_8$$7, "phalcon/Acl/Adapter/Memory.zep", 848 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 860);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _10$$5)
		{
			ZEPHIR_INIT_NVAR(&accessName);
			ZVAL_COPY(&accessName, _10$$5);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", &accessName);
			zephir_update_property_array(this_ptr, SL("access"), &accessKey, action TSRMLS_CC);
			if (Z_TYPE_P(func) != IS_NULL) {
				zephir_update_property_array(this_ptr, SL("func"), &accessKey, func TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", access);
			if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
				ZEPHIR_INIT_VAR(&_11$$12);
				object_init_ex(&_11$$12, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_12$$12);
				ZEPHIR_CONCAT_SVSVS(&_12$$12, "Access '", access, "' does not exist in component '", &componentName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", NULL, 1, &_12$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$12, "phalcon/Acl/Adapter/Memory.zep", 867 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", access);
		zephir_update_property_array(this_ptr, SL("access"), &accessKey, action TSRMLS_CC);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("func"), &accessKey, func TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a role is allowed to access an action from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess) {

	zval usedRoleToInherits, checkRoleToInherits;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zval *roleName_param = NULL, *componentName_param = NULL, *access_param = NULL, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _0, _1$$6, _2$$6, *_3$$6, _6$$8, _7$$8, _8$$8, _9$$8, _10$$13, _11$$13, *_12$$13;
	zval roleName, componentName, access, accessKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&accessKey);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&checkRoleToInherit);
	ZVAL_UNDEF(&usedRoleToInherit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZVAL_UNDEF(&checkRoleToInherits);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &componentName_param, &access_param);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	zephir_get_strval(&access, access_param);


	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("access"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", &access);
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VSVS(&accessKey, &roleName, "!", &componentName, "!*");
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleName, "!*!*");
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	zephir_read_property(&_0, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &roleName)) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property(&_1$$6, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 928 TSRMLS_CC);
		zephir_is_iterable(&_2$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 932);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$6), _3$$6)
		{
			ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			ZVAL_COPY(&usedRoleToInherit, _3$$6);
			ZEPHIR_MAKE_REF(&checkRoleToInherits);
			ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 108, &checkRoleToInherits, &usedRoleToInherit);
			ZEPHIR_UNREF(&checkRoleToInherits);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&usedRoleToInherit);
		ZEPHIR_INIT_VAR(&usedRoleToInherits);
		array_init(&usedRoleToInherits);
		while (1) {
			if (!(!(ZEPHIR_IS_EMPTY(&checkRoleToInherits)))) {
				break;
			}
			ZEPHIR_MAKE_REF(&checkRoleToInherits);
			ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_5, 10, &checkRoleToInherits);
			ZEPHIR_UNREF(&checkRoleToInherits);
			zephir_check_call_status();
			if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_LNVAR(_6$$8);
			ZEPHIR_CONCAT_VSVSV(&_6$$8, &checkRoleToInherit, "!", &componentName, "!", &access);
			zephir_get_strval(&accessKey, &_6$$8);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_LNVAR(_7$$8);
			ZEPHIR_CONCAT_VSVS(&_7$$8, &checkRoleToInherit, "!", &componentName, "!*");
			zephir_get_strval(&accessKey, &_7$$8);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_LNVAR(_8$$8);
			ZEPHIR_CONCAT_VS(&_8$$8, &checkRoleToInherit, "!*!*");
			zephir_get_strval(&accessKey, &_8$$8);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			zephir_read_property(&_9$$8, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_9$$8, &checkRoleToInherit)) {
				zephir_read_property(&_10$$13, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_11$$13, &_10$$13, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 975 TSRMLS_CC);
				zephir_is_iterable(&_11$$13, 0, "phalcon/Acl/Adapter/Memory.zep", 978);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$13), _12$$13)
				{
					ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					ZVAL_COPY(&usedRoleToInherit, _12$$13);
					ZEPHIR_MAKE_REF(&checkRoleToInherits);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 108, &checkRoleToInherits, &usedRoleToInherit);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

