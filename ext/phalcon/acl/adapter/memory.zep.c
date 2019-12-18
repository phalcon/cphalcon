
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Manages ACL lists in memory
 *
 *```php
 * $acl = new \Phalcon\Acl\Adapter\Memory();
 *
 * $acl->setDefaultAction(
 *     \Phalcon\Acl\Enum::DENY
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
 * foreach ($roles as $role) {
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_abstractadapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("access"), ZEND_ACC_PROTECTED);

	/**
	 * Access List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("accessList"), ZEND_ACC_PROTECTED);

	/**
	 * Returns latest function used to acquire access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeFunction"), ZEND_ACC_PROTECTED);

	/**
	 * Returns number of additional arguments(excluding role and resource) for active function
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("activeFunctionCustomArgumentsCount"), 0, ZEND_ACC_PROTECTED);

	/**
	 * Returns latest key used to acquire access
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeKey"), ZEND_ACC_PROTECTED);

	/**
	 * Components
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("components"), ZEND_ACC_PROTECTED);

	/**
	 * Component Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("componentsNames"), ZEND_ACC_PROTECTED);

	/**
	 * Function List
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("func"), ZEND_ACC_PROTECTED);

	/**
	 * Default action for no arguments is allow
	 *
	 * @var mixed
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("noArgumentsDefaultAction"), 0, ZEND_ACC_PROTECTED);

	/**
	 * Roles
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roles"), ZEND_ACC_PROTECTED);

	/**
	 * Role Inherits
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roleInherits"), ZEND_ACC_PROTECTED);

	/**
	 * Roles Names
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("rolesNames"), ZEND_ACC_PROTECTED);

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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("componentsNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("accessList"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc or a list of them
 *
 * Example:
 * ```php
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
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponent) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		_0 = zephir_instance_of_ev(componentValue, phalcon_acl_componentinterface_ce);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&componentObject, componentValue);
	} else {
		ZEPHIR_INIT_NVAR(&componentObject);
		object_init_ex(&componentObject, phalcon_acl_component_ce);
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 136, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 137);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &componentName))) {
		zephir_update_property_array_append(this_ptr, SL("components"), &componentObject);
		zephir_update_property_array(this_ptr, SL("componentsNames"), &componentName, &__$true);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addcomponentaccess", NULL, 0, &componentName, accessList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds access to components
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess) {

	zend_bool exists = 0, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *componentName_param = NULL, *accessList, accessList_sub, accessName, _0, _1$$3, *_4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$8, _10$$8, _11$$9, _12$$10, _13$$10, _14$$11;
	zval componentName, accessKey, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentName_param, &accessList);

	zephir_get_strval(&componentName, componentName_param);


	zephir_read_property(&_0, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_0, &componentName)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Component '", &componentName, "' does not exist in ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 6, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 248);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_3) {
		_3 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for accessList", "phalcon/Acl/Adapter/Memory.zep", 252);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 265);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$5);
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZEPHIR_CONCAT_VSV(&_6$$6, &componentName, "!", &accessName);
				zephir_get_strval(&accessKey, &_6$$6);
				zephir_read_property(&_7$$6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_7$$6, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_8$$7);
					ZVAL_BOOL(&_8$$7, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_8$$7);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, accessList, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$5, accessList, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, accessList, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_9$$8);
					ZEPHIR_CONCAT_VSV(&_9$$8, &componentName, "!", &accessName);
					zephir_get_strval(&accessKey, &_9$$8);
					zephir_read_property(&_10$$8, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_10$$8, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_11$$9);
						ZVAL_BOOL(&_11$$9, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_11$$9);
					}
				ZEPHIR_CALL_METHOD(NULL, accessList, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_VAR(&_12$$10);
		ZEPHIR_CONCAT_VSV(&_12$$10, &componentName, "!", accessList);
		zephir_get_strval(&accessKey, &_12$$10);
		zephir_read_property(&_13$$10, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_13$$10, &accessKey))) {
			ZEPHIR_INIT_VAR(&_14$$11);
			ZVAL_BOOL(&_14$$11, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_14$$11);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Do a role inherit from another existing role
 *
 * ```php
 * $acl->addRole("administrator", "consultant");
 * $acl->addRole("administrator", ["consultant", "consultant2"]);
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit) {

	zend_bool _6$$7, _25$$22;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, rolesNames, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, *_4, _5, _1$$3, _3$$4, _7$$7, _8$$7, _11$$7, _9$$11, _10$$11, _12$$13, _13$$13, *_14$$13, _15$$13, _18$$18, _19$$18, _20$$16, _21$$19, _22$$19, *_23$$19, _24$$19, _26$$22, _27$$22, _30$$22, _28$$26, _29$$26, _31$$28, _32$$28, *_33$$28, _34$$28, _35$$33, _36$$33, _37$$31, _38$$34, _39$$34, *_40$$34, _41$$34;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_24$$19);
	ZVAL_UNDEF(&_26$$22);
	ZVAL_UNDEF(&_27$$22);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_28$$26);
	ZVAL_UNDEF(&_29$$26);
	ZVAL_UNDEF(&_31$$28);
	ZVAL_UNDEF(&_32$$28);
	ZVAL_UNDEF(&_34$$28);
	ZVAL_UNDEF(&_35$$33);
	ZVAL_UNDEF(&_36$$33);
	ZVAL_UNDEF(&_37$$31);
	ZVAL_UNDEF(&_38$$34);
	ZVAL_UNDEF(&_39$$34);
	ZVAL_UNDEF(&_41$$34);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 6, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 295);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &roleName))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		array_init(&_3$$4);
		zephir_update_property_array(this_ptr, SL("roleInherits"), &roleName, &_3$$4);
	}
	if (Z_TYPE_P(roleToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&roleToInheritList);
		zephir_create_array(&roleToInheritList, 1, 0);
		zephir_array_fast_append(&roleToInheritList, roleToInherits);
	} else {
		ZEPHIR_CPY_WRT(&roleToInheritList, roleToInherits);
	}
	zephir_is_iterable(&roleToInheritList, 0, "phalcon/Acl/Adapter/Memory.zep", 384);
	if (Z_TYPE_P(&roleToInheritList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&roleToInheritList), _4)
		{
			ZEPHIR_INIT_NVAR(&roleToInherit);
			ZVAL_COPY(&roleToInherit, _4);
			_6$$7 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
			if (_6$$7) {
				_6$$7 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
			}
			if (_6$$7) {
				ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
			}
			zephir_read_property(&_7$$7, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$7, &_7$$7, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 324);
			if (zephir_fast_in_array(&roleInheritName, &_8$$7)) {
				continue;
			}
			if (UNEXPECTED(!(zephir_array_isset(&rolesNames, &roleInheritName)))) {
				ZEPHIR_INIT_NVAR(&_9$$11);
				object_init_ex(&_9$$11, phalcon_acl_exception_ce);
				ZEPHIR_INIT_NVAR(&_10$$11);
				ZEPHIR_CONCAT_SVS(&_10$$11, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
				ZEPHIR_CALL_METHOD(NULL, &_9$$11, "__construct", NULL, 6, &_10$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$11, "phalcon/Acl/Adapter/Memory.zep", 335);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_11$$7, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_11$$7, &roleInheritName)) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property(&_12$$13, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_13$$13, &_12$$13, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 348);
				zephir_is_iterable(&_13$$13, 0, "phalcon/Acl/Adapter/Memory.zep", 352);
				if (Z_TYPE_P(&_13$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_13$$13), _14$$13)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _14$$13);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_13$$13, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_15$$13, &_13$$13, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_15$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_13$$13, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_13$$13, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZEPHIR_INIT_NVAR(&usedRoleToInherits);
				array_init(&usedRoleToInherits);
				while (1) {
					if (!(!(ZEPHIR_IS_EMPTY(&checkRoleToInherits)))) {
						break;
					}
					ZEPHIR_MAKE_REF(&checkRoleToInherits);
					ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_17, 23, &checkRoleToInherits);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
					if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName, &checkRoleToInherit))) {
						ZEPHIR_INIT_NVAR(&_18$$18);
						object_init_ex(&_18$$18, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_19$$18);
						ZEPHIR_CONCAT_SVS(&_19$$18, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
						ZEPHIR_CALL_METHOD(NULL, &_18$$18, "__construct", NULL, 6, &_19$$18);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_18$$18, "phalcon/Acl/Adapter/Memory.zep", 367);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_20$$16, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_20$$16, &checkRoleToInherit)) {
						zephir_read_property(&_21$$19, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_22$$19, &_21$$19, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 374);
						zephir_is_iterable(&_22$$19, 0, "phalcon/Acl/Adapter/Memory.zep", 377);
						if (Z_TYPE_P(&_22$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_22$$19), _23$$19)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _23$$19);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_22$$19, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_24$$19, &_22$$19, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_24$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_22$$19, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_22$$19, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					}
				}
			}
			zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &roleToInheritList, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &roleToInheritList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleToInherit, &roleToInheritList, "current", NULL, 0);
			zephir_check_call_status();
				_25$$22 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_25$$22) {
					_25$$22 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_25$$22) {
					ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				zephir_read_property(&_26$$22, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_27$$22, &_26$$22, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 324);
				if (zephir_fast_in_array(&roleInheritName, &_27$$22)) {
					continue;
				}
				if (UNEXPECTED(!(zephir_array_isset(&rolesNames, &roleInheritName)))) {
					ZEPHIR_INIT_NVAR(&_28$$26);
					object_init_ex(&_28$$26, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_29$$26);
					ZEPHIR_CONCAT_SVS(&_29$$26, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
					ZEPHIR_CALL_METHOD(NULL, &_28$$26, "__construct", NULL, 6, &_29$$26);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_28$$26, "phalcon/Acl/Adapter/Memory.zep", 335);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property(&_30$$22, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_30$$22, &roleInheritName)) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property(&_31$$28, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_32$$28, &_31$$28, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 348);
					zephir_is_iterable(&_32$$28, 0, "phalcon/Acl/Adapter/Memory.zep", 352);
					if (Z_TYPE_P(&_32$$28) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_32$$28), _33$$28)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _33$$28);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_32$$28, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_34$$28, &_32$$28, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_34$$28)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_32$$28, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_32$$28, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					ZEPHIR_INIT_NVAR(&usedRoleToInherits);
					array_init(&usedRoleToInherits);
					while (1) {
						if (!(!(ZEPHIR_IS_EMPTY(&checkRoleToInherits)))) {
							break;
						}
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_17, 23, &checkRoleToInherits);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
						if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName, &checkRoleToInherit))) {
							ZEPHIR_INIT_NVAR(&_35$$33);
							object_init_ex(&_35$$33, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_36$$33);
							ZEPHIR_CONCAT_SVS(&_36$$33, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
							ZEPHIR_CALL_METHOD(NULL, &_35$$33, "__construct", NULL, 6, &_36$$33);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_35$$33, "phalcon/Acl/Adapter/Memory.zep", 367);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property(&_37$$31, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset(&_37$$31, &checkRoleToInherit)) {
							zephir_read_property(&_38$$34, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_39$$34, &_38$$34, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 374);
							zephir_is_iterable(&_39$$34, 0, "phalcon/Acl/Adapter/Memory.zep", 377);
							if (Z_TYPE_P(&_39$$34) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_39$$34), _40$$34)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _40$$34);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_39$$34, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_41$$34, &_39$$34, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_41$$34)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_39$$34, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 138, &checkRoleToInherits, &usedRoleToInherit);
										ZEPHIR_UNREF(&checkRoleToInherits);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_39$$34, "next", NULL, 0);
									zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						}
					}
				}
				zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName);
			ZEPHIR_CALL_METHOD(NULL, &roleToInheritList, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&roleToInherit);
	RETURN_MM_BOOL(1);

}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * ```php
 * $acl->addRole(
 *     new Phalcon\Acl\Role("administrator"),
 *     "consultant"
 * );
 *
 * $acl->addRole("administrator", "consultant");
 * $acl->addRole("administrator", ["consultant", "consultant2"]);
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 139, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either a string or implement RoleInterface", "phalcon/Acl/Adapter/Memory.zep", 411);
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 140);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array_append(this_ptr, SL("roles"), &roleObject);
	zephir_update_property_array(this_ptr, SL("rolesNames"), &roleName, &__$true);
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addinherit", NULL, 0, &roleName, accessInherits);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Allow access to a role on a component. You can use `*` as wildcard
 *
 * ```php
 * // Allow access to guests to search on customers
 * $acl->allow("guests", "customers", "search");
 *
 * // Allow access to guests to search or create on customers
 * $acl->allow("guests", "customers", ["search", "create"]);
 *
 * // Allow access to any role to browse on products
 * $acl->allow("*", "products", "browse");
 *
 * // Allow access to any role to browse on any component
 * $acl->allow("*", "*", "browse");
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow) {

	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0$$3, _1$$4, _2$$4, *_3$$4, _4$$4, _7$$5, _8$$6;
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
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &roleName, &componentName, access, &_0$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$4);
		zephir_is_iterable(&_1$$4, 0, "phalcon/Acl/Adapter/Memory.zep", 468);
		if (Z_TYPE_P(&_1$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&innerRoleName);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&innerRoleName, _6$$4);
				} else {
					ZVAL_LONG(&innerRoleName, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&_2$$4);
				ZVAL_COPY(&_2$$4, _3$$4);
				ZVAL_LONG(&_7$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &innerRoleName, &componentName, access, &_7$$5, func);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &_1$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&innerRoleName, &_1$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_2$$4, &_1$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_8$$6, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &innerRoleName, &componentName, access, &_8$$6, func);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Deny access to a role on a component. You can use `*` as wildcard
 *
 * ```php
 * // Deny access to guests to search on customers
 * $acl->deny("guests", "customers", "search");
 *
 * // Deny access to guests to search or create on customers
 * $acl->deny("guests", "customers", ["search", "create"]);
 *
 * // Deny access to any role to browse on products
 * $acl->deny("*", "products", "browse");
 *
 * // Deny access to any role to browse on any component
 * $acl->deny("*", "*", "browse");
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny) {

	zend_string *_7$$4;
	zend_ulong _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, innerRoleName, _0, _1$$3, _2$$4, _3$$4, *_4$$4, _5$$4, _8$$5, _9$$6;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&innerRoleName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &componentName_param, &access, &func);

	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	if (!ZEPHIR_IS_IDENTICAL(&_0, &roleName)) {
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &roleName, &componentName, access, &_1$$3, func);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_2$$4, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_is_iterable(&_2$$4, 0, "phalcon/Acl/Adapter/Memory.zep", 504);
		if (Z_TYPE_P(&_2$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_2$$4), _6$$4, _7$$4, _4$$4)
			{
				ZEPHIR_INIT_NVAR(&innerRoleName);
				if (_7$$4 != NULL) { 
					ZVAL_STR_COPY(&innerRoleName, _7$$4);
				} else {
					ZVAL_LONG(&innerRoleName, _6$$4);
				}
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZVAL_COPY(&_3$$4, _4$$4);
				ZVAL_LONG(&_8$$5, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &innerRoleName, &componentName, access, &_8$$5, func);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$4, &_2$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&innerRoleName, &_2$$4, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_3$$4, &_2$$4, "current", NULL, 0);
				zephir_check_call_status();
					ZVAL_LONG(&_9$$6, 0);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", NULL, 141, &innerRoleName, &componentName, access, &_9$$6, func);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_2$$4, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZEPHIR_INIT_NVAR(&innerRoleName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes an access from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess) {

	zval localAccess;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *componentName_param = NULL, *accessList, accessList_sub, accessName, _0$$3, *_1$$5, _2$$5, _3$$6, _4$$6, _5$$7, _6$$8, _7$$8, _8$$9;
	zval componentName, accessKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&localAccess);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentName_param, &accessList);

	zephir_get_strval(&componentName, componentName_param);


	ZEPHIR_INIT_VAR(&localAccess);
	array_init(&localAccess);
	if (Z_TYPE_P(accessList) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_create_array(&_0$$3, 1, 0);
		zephir_array_fast_append(&_0$$3, accessList);
		ZEPHIR_CPY_WRT(&localAccess, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&localAccess, accessList);
	}
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 530);
		if (Z_TYPE_P(&localAccess) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _1$$5);
				ZEPHIR_INIT_NVAR(&_3$$6);
				ZEPHIR_CONCAT_VSV(&_3$$6, &componentName, "!", &accessName);
				zephir_get_strval(&accessKey, &_3$$6);
				zephir_read_property(&_4$$6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_4$$6, &accessKey)) {
					zephir_read_property(&_5$$7, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
					zephir_array_unset(&_5$$7, &accessKey, PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &localAccess, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$5, &localAccess, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, &localAccess, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_6$$8);
					ZEPHIR_CONCAT_VSV(&_6$$8, &componentName, "!", &accessName);
					zephir_get_strval(&accessKey, &_6$$8);
					zephir_read_property(&_7$$8, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_7$$8, &accessKey)) {
						zephir_read_property(&_8$$9, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
						zephir_array_unset(&_8$$9, &accessKey, PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &localAccess, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the default ACL access level for no arguments provided in
 * `isAllowed` action if a `func` (callable) exists for `accessKey`
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
 * ```php
 * // Does andres have access to the customers component to create?
 * $acl->isAllowed("andres", "Products", "create");
 *
 * // Do guests have access to any component to edit?
 * $acl->isAllowed("guests", "*", "edit");
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed) {

	zend_bool hasComponent, hasRole, _10, _14$$18, _18$$20, _20$$20, _21$$20, _23$$20, _24$$20, _26$$20, _35$$26, _37$$26, _38$$26, _40$$26, _41$$26, _43$$26, _55$$33, _57$$32, _59$$34;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access, _2$$6, _5$$10;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, *access_param = NULL, *parameters_param = NULL, __$null, accessKey, accessList, componentObject, haveAccess, eventsManager, funcAccess, funcList, numberOfRequiredParameters, reflectionFunction, reflectionParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionParameter, rolesNames, roleObject, userParametersSizeShouldBe, _6, _0$$5, _1$$6, _3$$9, _4$$10, _7$$11, _8$$11, _9$$13, _11$$15, _12$$16, _13$$16, _15$$18, *_16$$17, _17$$17, _61$$17, _62$$17, _19$$20, _22$$20, _25$$20, _27$$20, _28$$20, _29$$23, _30$$23, _31$$23, _32$$23, _33$$23, _34$$24, _36$$26, _39$$26, _42$$26, _44$$26, _45$$26, _46$$29, _47$$29, _48$$29, _49$$29, _50$$29, _51$$30, _52$$31, _53$$31, _54$$33, _56$$33, _58$$32, _60$$34;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&componentName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&rolesNames);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_15$$18);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_61$$17);
	ZVAL_UNDEF(&_62$$17);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_44$$26);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_48$$29);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_54$$33);
	ZVAL_UNDEF(&_56$$33);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_60$$34);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$10);
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


	ZEPHIR_INIT_VAR(&componentObject);
	ZVAL_NULL(&componentObject);
	ZEPHIR_INIT_VAR(&haveAccess);
	ZVAL_NULL(&haveAccess);
	ZEPHIR_INIT_VAR(&funcAccess);
	ZVAL_NULL(&funcAccess);
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	hasComponent = 0;
	hasRole = 0;
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleaware_ce)) {
			ZEPHIR_CPY_WRT(&roleObject, roleName);
			ZEPHIR_CALL_METHOD(roleName, &roleObject, "getrolename", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(roleName, phalcon_acl_roleinterface_ce)) {
			ZEPHIR_CALL_METHOD(&_0$$5, roleName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(roleName, &_0$$5);
		} else {
			ZEPHIR_INIT_VAR(&_1$$6);
			object_init_ex(&_1$$6, phalcon_acl_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$6);
			ZEPHIR_CONCAT_SS(&_2$$6, "Object passed as roleName must implement ", "Phalcon\\Acl\\RoleAware or Phalcon\\Acl\\RoleInterface");
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 6, &_2$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "phalcon/Acl/Adapter/Memory.zep", 590);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(componentName) == IS_OBJECT) {
		if (zephir_instance_of_ev(componentName, phalcon_acl_componentaware_ce)) {
			ZEPHIR_CPY_WRT(&componentObject, componentName);
			ZEPHIR_CALL_METHOD(componentName, &componentObject, "getcomponentname", NULL, 0);
			zephir_check_call_status();
		} else if (zephir_instance_of_ev(componentName, phalcon_acl_componentinterface_ce)) {
			ZEPHIR_CALL_METHOD(&_3$$9, componentName, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(componentName, &_3$$9);
		} else {
			ZEPHIR_INIT_VAR(&_4$$10);
			object_init_ex(&_4$$10, phalcon_acl_exception_ce);
			ZEPHIR_INIT_VAR(&_5$$10);
			ZEPHIR_CONCAT_SS(&_5$$10, "Object passed as componentName must implement ", "Phalcon\\Acl\\ComponentAware or Phalcon\\Acl\\ComponentInterface");
			ZEPHIR_CALL_METHOD(NULL, &_4$$10, "__construct", NULL, 6, &_5$$10);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$10, "phalcon/Acl/Adapter/Memory.zep", 604);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("activeRole"), roleName);
	zephir_update_property_zval(this_ptr, SL("activeComponent"), componentName);
	zephir_update_property_zval(this_ptr, SL("activeAccess"), &access);
	zephir_update_property_zval(this_ptr, SL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &__$null);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, SL("access"), PH_NOISY_CC);
	zephir_read_property(&_6, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_6);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, SL("func"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(&_6, 0);
	zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &_6);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_8$$11);
		ZVAL_STRING(&_8$$11, "acl:beforeCheckAccess");
		ZEPHIR_CALL_METHOD(&_7$$11, &eventsManager, "fire", NULL, 0, &_8$$11, this_ptr);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$11)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_6, this_ptr, SL("rolesNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&rolesNames, &_6);
	if (!(zephir_array_isset(&rolesNames, roleName))) {
		zephir_read_property(&_9$$13, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_9$$13, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 142, roleName, componentName, &access);
	zephir_check_call_status();
	_10 = !ZEPHIR_IS_FALSE(&accessKey);
	if (_10) {
		_10 = zephir_array_isset(&accessList, &accessKey);
	}
	if (_10) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 641);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
	}
	zephir_update_property_zval(this_ptr, SL("accessGranted"), &haveAccess);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_11$$15);
		ZVAL_STRING(&_11$$15, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, &eventsManager, "fire", NULL, 0, &_11$$15, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("activeKey"), &accessKey);
	zephir_update_property_zval(this_ptr, SL("activeFunction"), &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_12$$16);
		ZEPHIR_CONCAT_VSVSV(&_12$$16, roleName, "!", componentName, "!", &access);
		zephir_update_property_zval(this_ptr, SL("activeKey"), &_12$$16);
		zephir_read_property(&_13$$16, this_ptr, SL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_13$$16, 1));
	}
	if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 143, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 144);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_14$$18 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_14$$18) {
				ZEPHIR_INIT_VAR(&_15$$18);
				ZEPHIR_CALL_USER_FUNC(&_15$$18, &funcAccess);
				zephir_check_call_status();
				_14$$18 = zephir_is_true(&_15$$18);
			}
			RETURN_MM_BOOL(_14$$18);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 145);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/Acl/Adapter/Memory.zep", 746);
		if (Z_TYPE_P(&reflectionParameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _16$$17)
			{
				ZEPHIR_INIT_NVAR(&reflectionParameter);
				ZVAL_COPY(&reflectionParameter, _16$$17);
				ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
					_18$$20 = Z_TYPE_P(&roleObject) != IS_NULL;
					if (_18$$20) {
						ZEPHIR_CALL_METHOD(&_19$$20, &reflectionClass, "isinstance", NULL, 0, &roleObject);
						zephir_check_call_status();
						_18$$20 = zephir_is_true(&_19$$20);
					}
					_20$$20 = _18$$20;
					if (_20$$20) {
						_20$$20 = !hasRole;
					}
					if (_20$$20) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 699);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_21$$20 = Z_TYPE_P(&componentObject) != IS_NULL;
					if (_21$$20) {
						ZEPHIR_CALL_METHOD(&_22$$20, &reflectionClass, "isinstance", NULL, 0, &componentObject);
						zephir_check_call_status();
						_21$$20 = zephir_is_true(&_22$$20);
					}
					_23$$20 = _21$$20;
					if (_23$$20) {
						_23$$20 = !hasComponent;
					}
					if (_23$$20) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 711);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_24$$20 = zephir_array_isset(&parameters, &parameterToCheck);
					if (_24$$20) {
						zephir_array_fetch(&_25$$20, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 722);
						_24$$20 = Z_TYPE_P(&_25$$20) == IS_OBJECT;
					}
					_26$$20 = _24$$20;
					if (_26$$20) {
						zephir_array_fetch(&_28$$20, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 723);
						ZEPHIR_CALL_METHOD(&_27$$20, &reflectionClass, "isinstance", NULL, 0, &_28$$20);
						zephir_check_call_status();
						_26$$20 = !zephir_is_true(&_27$$20);
					}
					if (UNEXPECTED(_26$$20)) {
						ZEPHIR_INIT_NVAR(&_29$$23);
						object_init_ex(&_29$$23, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_30$$23);
						zephir_array_fetch(&_31$$23, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 730);
						zephir_get_class(&_30$$23, &_31$$23, 0);
						ZEPHIR_CALL_METHOD(&_32$$23, &reflectionClass, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_33$$23);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_33$$23, "Your passed parameter doesn't have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access, " ", componentName, ". Class passed: ", &_30$$23, " , Class in defined function: ", &_32$$23, ".");
						ZEPHIR_CALL_METHOD(NULL, &_29$$23, "__construct", NULL, 6, &_33$$23);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_29$$23, "phalcon/Acl/Adapter/Memory.zep", 733);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset(&parameters, &parameterToCheck)) {
					zephir_array_fetch(&_34$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 742);
					zephir_array_append(&parametersForFunction, &_34$$24, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 742);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_17$$17, &reflectionParameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$17)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reflectionParameter, &reflectionParameters, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
						_35$$26 = Z_TYPE_P(&roleObject) != IS_NULL;
						if (_35$$26) {
							ZEPHIR_CALL_METHOD(&_36$$26, &reflectionClass, "isinstance", NULL, 0, &roleObject);
							zephir_check_call_status();
							_35$$26 = zephir_is_true(&_36$$26);
						}
						_37$$26 = _35$$26;
						if (_37$$26) {
							_37$$26 = !hasRole;
						}
						if (_37$$26) {
							hasRole = 1;
							zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 699);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_38$$26 = Z_TYPE_P(&componentObject) != IS_NULL;
						if (_38$$26) {
							ZEPHIR_CALL_METHOD(&_39$$26, &reflectionClass, "isinstance", NULL, 0, &componentObject);
							zephir_check_call_status();
							_38$$26 = zephir_is_true(&_39$$26);
						}
						_40$$26 = _38$$26;
						if (_40$$26) {
							_40$$26 = !hasComponent;
						}
						if (_40$$26) {
							hasComponent = 1;
							zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 711);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_41$$26 = zephir_array_isset(&parameters, &parameterToCheck);
						if (_41$$26) {
							zephir_array_fetch(&_42$$26, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 722);
							_41$$26 = Z_TYPE_P(&_42$$26) == IS_OBJECT;
						}
						_43$$26 = _41$$26;
						if (_43$$26) {
							zephir_array_fetch(&_45$$26, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 723);
							ZEPHIR_CALL_METHOD(&_44$$26, &reflectionClass, "isinstance", NULL, 0, &_45$$26);
							zephir_check_call_status();
							_43$$26 = !zephir_is_true(&_44$$26);
						}
						if (UNEXPECTED(_43$$26)) {
							ZEPHIR_INIT_NVAR(&_46$$29);
							object_init_ex(&_46$$29, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_47$$29);
							zephir_array_fetch(&_48$$29, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 730);
							zephir_get_class(&_47$$29, &_48$$29, 0);
							ZEPHIR_CALL_METHOD(&_49$$29, &reflectionClass, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_50$$29);
							ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_50$$29, "Your passed parameter doesn't have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access, " ", componentName, ". Class passed: ", &_47$$29, " , Class in defined function: ", &_49$$29, ".");
							ZEPHIR_CALL_METHOD(NULL, &_46$$29, "__construct", NULL, 6, &_50$$29);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_46$$29, "phalcon/Acl/Adapter/Memory.zep", 733);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (zephir_array_isset(&parameters, &parameterToCheck)) {
						zephir_array_fetch(&_51$$30, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 742);
						zephir_array_append(&parametersForFunction, &_51$$30, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 742);
					}
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		zephir_update_property_zval(this_ptr, SL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
		if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters)))) {
			ZEPHIR_INIT_VAR(&_52$$31);
			ZEPHIR_CONCAT_SSVSVSVS(&_52$$31, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", roleName, "' can '", &access, "' '", componentName, "'. Extra parameters will be ignored.");
			ZVAL_LONG(&_53$$31, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 5, &_52$$31, &_53$$31);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction) == 0) {
			if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
				ZEPHIR_INIT_VAR(&_54$$33);
				ZEPHIR_CONCAT_SVSVSVS(&_54$$33, "You did not provide any parameters when '", roleName, "' can '", &access, "' '", componentName, "'. We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 5, &_54$$33);
				zephir_check_call_status();
				_55$$33 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_55$$33) {
					zephir_read_property(&_56$$33, this_ptr, SL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_55$$33 = ZEPHIR_IS_LONG(&_56$$33, 1);
				}
				RETURN_MM_BOOL(_55$$33);
			}
			_57$$32 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_57$$32) {
				ZEPHIR_INIT_VAR(&_58$$32);
				ZEPHIR_CALL_USER_FUNC(&_58$$32, &funcAccess);
				zephir_check_call_status();
				_57$$32 = zephir_is_true(&_58$$32);
			}
			RETURN_MM_BOOL(_57$$32);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
			_59$$34 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_59$$34) {
				ZEPHIR_INIT_VAR(&_60$$34);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_60$$34, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_59$$34 = zephir_is_true(&_60$$34);
			}
			RETURN_MM_BOOL(_59$$34);
		}
		ZEPHIR_INIT_VAR(&_61$$17);
		object_init_ex(&_61$$17, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_62$$17);
		ZEPHIR_CONCAT_SSVSVSVS(&_62$$17, "You did not provide all necessary parameters for the ", "defined function when checking if '", roleName, "' can '", &access, "' for '", componentName, "'.");
		ZEPHIR_CALL_METHOD(NULL, &_61$$17, "__construct", NULL, 6, &_62$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_61$$17, "phalcon/Acl/Adapter/Memory.zep", 787);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));

}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
 * Sets the default access level (`Phalcon\Enum::ALLOW` or `Phalcon\Enum::DENY`)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction) {

	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);

	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, SL("noArgumentsDefaultAction"), &_0);

}

/**
 * Checks if a role has access to a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _3, _6, _1$$3, _4$$4, *_7$$5, _8$$5, *_13$$5, _14$$5, _9$$7, _10$$7, _11$$9, _12$$9, _15$$16, _16$$16;
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
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);

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
		ZEPHIR_CONCAT_SVS(&_2$$3, "Role '", &roleName, "' does not exist in the ACL");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 6, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 829);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_3, &componentName)))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SVS(&_5$$4, "Component '", &componentName, "' does not exist in the ACL");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 6, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalcon/Acl/Adapter/Memory.zep", 835);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_6);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 852);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _7$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _7$$5);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", &accessName);
				if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
					ZEPHIR_INIT_NVAR(&_9$$7);
					object_init_ex(&_9$$7, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_10$$7);
					ZEPHIR_CONCAT_SVSVS(&_10$$7, "Access '", &accessName, "' does not exist in component '", &componentName, "'");
					ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 6, &_10$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_9$$7, "phalcon/Acl/Adapter/Memory.zep", 848);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$5, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", &accessName);
					if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
						ZEPHIR_INIT_NVAR(&_11$$9);
						object_init_ex(&_11$$9, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_12$$9);
						ZEPHIR_CONCAT_SVSVS(&_12$$9, "Access '", &accessName, "' does not exist in component '", &componentName, "'");
						ZEPHIR_CALL_METHOD(NULL, &_11$$9, "__construct", NULL, 6, &_12$$9);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_11$$9, "phalcon/Acl/Adapter/Memory.zep", 848);
						ZEPHIR_MM_RESTORE();
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 860);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _13$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _13$$5);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", &accessName);
				zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
				if (Z_TYPE_P(func) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("func"), &accessKey, func);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_14$$5, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", &accessName);
					zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
					if (Z_TYPE_P(func) != IS_NULL) {
						zephir_update_property_array(this_ptr, SL("func"), &accessKey, func);
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", access);
			if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
				ZEPHIR_INIT_VAR(&_15$$16);
				object_init_ex(&_15$$16, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_16$$16);
				ZEPHIR_CONCAT_SVSVS(&_16$$16, "Access '", access, "' does not exist in component '", &componentName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_15$$16, "__construct", NULL, 6, &_16$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$16, "phalcon/Acl/Adapter/Memory.zep", 868);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName, "!", &componentName, "!", access);
		zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("func"), &accessKey, func);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a role is allowed to access an action from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess) {

	zval usedRoleToInherits, checkRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access_param = NULL, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _0, _1$$6, _2$$6, *_3$$6, _4$$6, _7$$9, _8$$9, _9$$9, _10$$9, _11$$14, _12$$14, *_13$$14, _14$$14;
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
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_14$$14);
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
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 929);
		zephir_is_iterable(&_2$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 933);
		if (Z_TYPE_P(&_2$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$6), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _3$$6);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 138, &checkRoleToInherits, &usedRoleToInherit);
				ZEPHIR_UNREF(&checkRoleToInherits);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$6, &_2$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_2$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_MAKE_REF(&checkRoleToInherits);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 138, &checkRoleToInherits, &usedRoleToInherit);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_2$$6, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&usedRoleToInherit);
		ZEPHIR_INIT_VAR(&usedRoleToInherits);
		array_init(&usedRoleToInherits);
		while (1) {
			if (!(!(ZEPHIR_IS_EMPTY(&checkRoleToInherits)))) {
				break;
			}
			ZEPHIR_MAKE_REF(&checkRoleToInherits);
			ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_6, 23, &checkRoleToInherits);
			ZEPHIR_UNREF(&checkRoleToInherits);
			zephir_check_call_status();
			if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_7$$9);
			ZEPHIR_CONCAT_VSVSV(&_7$$9, &checkRoleToInherit, "!", &componentName, "!", &access);
			zephir_get_strval(&accessKey, &_7$$9);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&_8$$9);
			ZEPHIR_CONCAT_VSVS(&_8$$9, &checkRoleToInherit, "!", &componentName, "!*");
			zephir_get_strval(&accessKey, &_8$$9);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&_9$$9);
			ZEPHIR_CONCAT_VS(&_9$$9, &checkRoleToInherit, "!*!*");
			zephir_get_strval(&accessKey, &_9$$9);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			zephir_read_property(&_10$$9, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_10$$9, &checkRoleToInherit)) {
				zephir_read_property(&_11$$14, this_ptr, SL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_12$$14, &_11$$14, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 976);
				zephir_is_iterable(&_12$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 979);
				if (Z_TYPE_P(&_12$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$14), _13$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _13$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 138, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_12$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_14$$14, &_12$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_14$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_12$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 138, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_12$$14, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

