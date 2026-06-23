
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_abstractadapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Access
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("access"), ZEND_ACC_PROTECTED);
	/**
	 * Access List
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("accessList"), ZEND_ACC_PROTECTED);
	/**
	 * Returns the latest function used to acquire access
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
	 * Returns the latest key used to acquire access
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeKey"), ZEND_ACC_PROTECTED);
	/**
	 * Components
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("components"), ZEND_ACC_PROTECTED);
	/**
	 * Component Names
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("componentsNames"), ZEND_ACC_PROTECTED);
	/**
	 * Function List
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("functions"), ZEND_ACC_PROTECTED);
	/**
	 * Default action for no arguments is `allow`
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("noArgumentsDefaultAction"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Roles
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roles"), ZEND_ACC_PROTECTED);
	/**
	 * Role Inherits
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("roleInherits"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct)
{
	zval _2, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _1, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("access"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("components"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("componentsNames"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("functions"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("roleInherits"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("roles"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	zephir_array_update_string(&_6, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &_6);
	ZEPHIR_MM_RESTORE();
}

/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, by example
 * search, update, delete, etc. or a list of them
 *
 * Example:
 * ```php
 * // Add a component to the list allowing access to an action
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponent)
{
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(componentValue)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 203, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 204);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_1, &componentName))) {
		zephir_update_property_array(this_ptr, SL("components"), &componentName, &componentObject);
		zephir_update_property_array(this_ptr, SL("componentsNames"), &componentName, &__$true);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addcomponentaccess", NULL, 0, &componentName, accessList);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds access to components
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess)
{
	zend_bool exists = 0, _2, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, _0, _1, _3$$3, *_4$$4, _8$$4, _6$$5, _7$$6, _10$$7, _11$$8, _12$$9, _13$$10;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	accessList = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 205, &_0, &componentName_zv, &_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_2) {
		_2 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_acl_exceptions_invalidaccesslist_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 206);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Acl/Adapter/Memory.zep", 255);
		ZEPHIR_MM_RESTORE();
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 268);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _4$$4)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$4);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_value(&_6$$5, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZVAL_BOOL(&_7$$6, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_7$$6);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, accessList, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$4 = 1;
			while (1) {
				if (_9$$4) {
					_9$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, accessList, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$4, accessList, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, accessList, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_read_property(&_10$$7, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset_value(&_10$$7, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_11$$8);
						ZVAL_BOOL(&_11$$8, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_11$$8);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, accessList);
		zephir_check_call_status();
		zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_value(&_12$$9, &accessKey))) {
			ZEPHIR_INIT_VAR(&_13$$10);
			ZVAL_BOOL(&_13$$10, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_13$$10);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit)
{
	zend_bool _28, _6$$6, _18$$12, _26$$18, _29$$21, _39$$27, _46$$33;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_16 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _1, _2, _3, *_5, _27, _4$$3, _7$$6, _8$$6, _9$$6, _12$$6, _10$$10, _13$$12, _14$$12, *_15$$12, _17$$12, _19$$17, _21$$15, _22$$18, _23$$18, *_24$$18, _25$$18, _30$$21, _31$$21, _32$$21, _34$$21, _33$$25, _35$$27, _36$$27, *_37$$27, _38$$27, _40$$32, _41$$30, _42$$33, _43$$33, *_44$$33, _45$$33;
	zend_string *roleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&roleToInherits_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&roleInheritName);
	ZVAL_UNDEF(&roleToInherit);
	ZVAL_UNDEF(&checkRoleToInherit);
	ZVAL_UNDEF(&roleToInheritList);
	ZVAL_UNDEF(&usedRoleToInherit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$18);
	ZVAL_UNDEF(&_23$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(roleName)
		Z_PARAM_ZVAL(roleToInherits)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	roleToInherits = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "role list");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 205, &_0, &roleName_zv, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_3, &roleName_zv))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_array(this_ptr, SL("roleInherits"), &roleName_zv, &_4$$3);
	}
	if (Z_TYPE_P(roleToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&roleToInheritList);
		zephir_create_array(&roleToInheritList, 1, 0);
		zephir_array_fast_append(&roleToInheritList, roleToInherits);
	} else {
		ZEPHIR_CPY_WRT(&roleToInheritList, roleToInherits);
	}
	zephir_is_iterable(&roleToInheritList, 0, "phalcon/Acl/Adapter/Memory.zep", 385);
	if (Z_TYPE_P(&roleToInheritList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&roleToInheritList), _5)
		{
			ZEPHIR_INIT_NVAR(&roleToInherit);
			ZVAL_COPY(&roleToInherit, _5);
			_6$$6 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
			if (_6$$6) {
				_6$$6 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
			}
			if (_6$$6) {
				ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
			}
			zephir_read_property(&_7$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$6, &_7$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 322);
			if (zephir_fast_in_array(&roleInheritName, &_8$$6)) {
				continue;
			}
			zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(!(zephir_array_isset_value(&_9$$6, &roleInheritName)))) {
				ZEPHIR_INIT_NVAR(&_10$$10);
				object_init_ex(&_10$$10, phalcon_acl_exceptions_rolenotfoundexception_ce);
				ZEPHIR_CALL_METHOD(NULL, &_10$$10, "__construct", &_11, 208, &roleInheritName);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$10, "phalcon/Acl/Adapter/Memory.zep", 330);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_12$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_12$$6, &roleInheritName)) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property(&_13$$12, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_14$$12, &_13$$12, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 343);
				zephir_is_iterable(&_14$$12, 0, "phalcon/Acl/Adapter/Memory.zep", 347);
				if (Z_TYPE_P(&_14$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_14$$12), _15$$12)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _15$$12);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_14$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					_18$$12 = 1;
					while (1) {
						if (_18$$12) {
							_18$$12 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_14$$12, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_17$$12, &_14$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_17$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_14$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZEPHIR_INIT_NVAR(&usedRoleToInherits);
				array_init(&usedRoleToInherits);
				pendingIndex = 0;
				while (1) {
					if (!(pendingIndex < zephir_fast_count_int(&checkRoleToInherits))) {
						break;
					}
					ZEPHIR_OBS_NVAR(&checkRoleToInherit);
					zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 358);
					pendingIndex++;
					if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
						ZEPHIR_INIT_NVAR(&_19$$17);
						object_init_ex(&_19$$17, phalcon_acl_exceptions_circularinheritanceerror_ce);
						ZEPHIR_CALL_METHOD(NULL, &_19$$17, "__construct", &_20, 210, &roleInheritName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_19$$17, "phalcon/Acl/Adapter/Memory.zep", 368);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_21$$15, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset_value(&_21$$15, &checkRoleToInherit)) {
						zephir_read_property(&_22$$18, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_23$$18, &_22$$18, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 375);
						zephir_is_iterable(&_23$$18, 0, "phalcon/Acl/Adapter/Memory.zep", 378);
						if (Z_TYPE_P(&_23$$18) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_23$$18), _24$$18)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _24$$18);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_23$$18, "rewind", NULL, 0);
							zephir_check_call_status();
							_26$$18 = 1;
							while (1) {
								if (_26$$18) {
									_26$$18 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, &_23$$18, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_25$$18, &_23$$18, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_25$$18)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_23$$18, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					}
				}
			}
			zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &roleToInheritList, "rewind", NULL, 0);
		zephir_check_call_status();
		_28 = 1;
		while (1) {
			if (_28) {
				_28 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &roleToInheritList, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_27, &roleToInheritList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_27)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleToInherit, &roleToInheritList, "current", NULL, 0);
			zephir_check_call_status();
				_29$$21 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_29$$21) {
					_29$$21 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_29$$21) {
					ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				zephir_read_property(&_30$$21, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_31$$21, &_30$$21, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 322);
				if (zephir_fast_in_array(&roleInheritName, &_31$$21)) {
					continue;
				}
				zephir_read_property(&_32$$21, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_array_isset_value(&_32$$21, &roleInheritName)))) {
					ZEPHIR_INIT_NVAR(&_33$$25);
					object_init_ex(&_33$$25, phalcon_acl_exceptions_rolenotfoundexception_ce);
					ZEPHIR_CALL_METHOD(NULL, &_33$$25, "__construct", &_11, 208, &roleInheritName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_33$$25, "phalcon/Acl/Adapter/Memory.zep", 330);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property(&_34$$21, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value(&_34$$21, &roleInheritName)) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property(&_35$$27, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_36$$27, &_35$$27, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 343);
					zephir_is_iterable(&_36$$27, 0, "phalcon/Acl/Adapter/Memory.zep", 347);
					if (Z_TYPE_P(&_36$$27) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_36$$27), _37$$27)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _37$$27);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_36$$27, "rewind", NULL, 0);
						zephir_check_call_status();
						_39$$27 = 1;
						while (1) {
							if (_39$$27) {
								_39$$27 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_36$$27, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_38$$27, &_36$$27, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_38$$27)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_36$$27, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					ZEPHIR_INIT_NVAR(&usedRoleToInherits);
					array_init(&usedRoleToInherits);
					pendingIndex = 0;
					while (1) {
						if (!(pendingIndex < zephir_fast_count_int(&checkRoleToInherits))) {
							break;
						}
						ZEPHIR_OBS_NVAR(&checkRoleToInherit);
						zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 358);
						pendingIndex++;
						if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
							ZEPHIR_INIT_NVAR(&_40$$32);
							object_init_ex(&_40$$32, phalcon_acl_exceptions_circularinheritanceerror_ce);
							ZEPHIR_CALL_METHOD(NULL, &_40$$32, "__construct", &_20, 210, &roleInheritName);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_40$$32, "phalcon/Acl/Adapter/Memory.zep", 368);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property(&_41$$30, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_value(&_41$$30, &checkRoleToInherit)) {
							zephir_read_property(&_42$$33, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_43$$33, &_42$$33, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 375);
							zephir_is_iterable(&_43$$33, 0, "phalcon/Acl/Adapter/Memory.zep", 378);
							if (Z_TYPE_P(&_43$$33) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_43$$33), _44$$33)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _44$$33);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_43$$33, "rewind", NULL, 0);
								zephir_check_call_status();
								_46$$33 = 1;
								while (1) {
									if (_46$$33) {
										_46$$33 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, &_43$$33, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_45$$33, &_43$$33, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_45$$33)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_43$$33, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_16, 209, &checkRoleToInherits, &usedRoleToInherit);
										ZEPHIR_UNREF(&checkRoleToInherits);
										zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						}
					}
				}
				zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
		}
	}
	ZEPHIR_INIT_NVAR(&roleToInherit);
	RETURN_MM_BOOL(1);
}

/**
 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
 *
 * If the role already exists this method returns `false` and the
 * `accessInherits` argument is ignored; the existing role is left
 * unchanged.
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, *accessInherits = NULL, accessInherits_sub, __$null, roleName, roleObject, _2, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(role)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(accessInherits)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 211, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_acl_exceptions_invalidroletype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 212);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Acl/Adapter/Memory.zep", 414);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 204);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_2, &roleName)) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("roles"), &roleName, &roleObject);
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
 * A `*` role is an eager snapshot: it expands to the roles that exist when
 * `allow()` is called, so roles added afterwards do not inherit the grant.
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
 * // Allow access to any role to perform any action on any component
 * $acl->allow("*", "*", "*");
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _1$$3, _3$$4;
	zend_string *roleName = NULL, *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&rolesArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	access = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		func = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}
	ZEPHIR_INIT_VAR(&rolesArray);
	zephir_create_array(&rolesArray, 1, 0);
	zephir_array_fast_append(&rolesArray, &roleName_zv);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName_zv)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 470);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _2);
		ZVAL_LONG(&_3$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_4, 213, &role, &componentName_zv, access, &_3$$4, func);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&role);
	ZEPHIR_MM_RESTORE();
}

/**
 * Deny access to a role on a component. You can use `*` as wildcard
 *
 * A `*` role is an eager snapshot: it expands to the roles that exist when
 * `deny()` is called, so roles added afterwards do not inherit the rule.
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
 * // Deny access to any role to perform any action on any component
 * $acl->deny("*", "*", "*");
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _1$$3, _3$$4;
	zend_string *roleName = NULL, *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&rolesArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	access = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		func = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}
	ZEPHIR_INIT_VAR(&rolesArray);
	zephir_create_array(&rolesArray, 1, 0);
	zephir_array_fast_append(&rolesArray, &roleName_zv);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName_zv)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 510);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _2);
		ZVAL_LONG(&_3$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_4, 213, &role, &componentName_zv, access, &_3$$4, func);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&role);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes access from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess)
{
	zval localAccess;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, *_1, _0$$3, _3$$5, _4$$6;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&localAccess);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	accessList = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
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
	zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 533);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1)
	{
		ZEPHIR_INIT_NVAR(&accessName);
		ZVAL_COPY(&accessName, _1);
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_2, 207, &componentName_zv, &accessName);
		zephir_check_call_status();
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_3$$5, &accessKey)) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("accessList"), &accessKey);
			zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_4$$6, &accessKey, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&accessName);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the latest function used to acquire access
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction)
{

	RETURN_MEMBER(getThis(), "activeFunction");
}

/**
 * Returns number of additional arguments(excluding role and resource) for active function
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount)
{

	RETURN_MEMBER_TYPED(getThis(), "activeFunctionCustomArgumentsCount", IS_LONG);
}

/**
 * Returns the latest key used to acquire access
 *
 * @deprecated Relies on the internal "role!component!access" encoding,
 *             which will be removed in v7. Use getActiveRole(),
 *             getActiveComponent() and getActiveAccess() instead.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey)
{

	RETURN_MEMBER(getThis(), "activeKey");
}

/**
 * Return an array with every component registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getComponents)
{

	RETURN_MEMBER_TYPED(getThis(), "components", IS_ARRAY);
}

/**
 * Returns the inherited roles for a passed role name. If no role name
 * has been specified it will return the whole array. If the role has not
 * been found it returns an empty array
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getInheritedRoles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval roleName_zv, result, _0, _1;
	zend_string *roleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!roleName) {
		roleName = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&roleName_zv);
		ZVAL_STR(&roleName_zv, roleName);
	} else {
		zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName_zv)) {
		RETURN_MM_MEMBER_TYPED(getThis(), "roleInherits", IS_ARRAY);
	}
	zephir_memory_observe(&result);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&result, &_1, &roleName_zv, 0))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CCTOR(&result);
}

/**
 * Returns the default ACL access level for no arguments provided in
 * `isAllowed` action if a `func` (callable) exists for `accessKey`
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction)
{

	RETURN_MEMBER_TYPED(getThis(), "noArgumentsDefaultAction", IS_LONG);
}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles)
{

	RETURN_MEMBER_TYPED(getThis(), "roles", IS_ARRAY);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed)
{
	zend_bool _0, _1, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, _4, _9;
	zend_string *access = NULL;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, access_zv, *parameters_param = NULL, __$null, accessKey, accessList, componentObject, haveAccess, funcAccess, funcList, roleObject, _2, _3, _5, _8, _10, _6$$6, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&componentName_sub);
	ZVAL_UNDEF(&access_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(roleName)
		Z_PARAM_ZVAL(componentName)
		Z_PARAM_STR(access)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY_OR_NULL(parameters, parameters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	roleName = ZEND_CALL_ARG(execute_data, 1);
	componentName = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 3) {
		parameters_param = ZEND_CALL_ARG(execute_data, 4);
	}
	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(componentName);
	zephir_memory_observe(&access_zv);
	ZVAL_STR_COPY(&access_zv, access);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
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
	_0 = Z_TYPE_P(roleName) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(roleName, phalcon_acl_roleawareinterface_ce);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&roleObject, roleName);
	}
	_1 = Z_TYPE_P(componentName) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(componentName, phalcon_acl_componentawareinterface_ce);
	}
	if (_1) {
		ZEPHIR_CPY_WRT(&componentObject, componentName);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "torolename", NULL, 214, roleName);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(roleName, &_2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "tocomponentname", NULL, 215, componentName);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(componentName, &_2);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRole"), roleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeComponent"), componentName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), &access_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunction"), &__$null);
	zephir_memory_observe(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	zephir_memory_observe(&funcList);
	zephir_read_property(&funcList, this_ptr, ZEND_STRL("functions"), PH_NOISY_CC);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunctionCustomArgumentsCount"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	zephir_array_update_string(&_4, SL("role"), roleName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("component"), componentName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "acl:beforeCheckAccess");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "firemanagerevent", NULL, 0, &_5, &_4);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_3, roleName))) {
		zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_6$$6, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 216, roleName, componentName, &access_zv);
	zephir_check_call_status();
	_7 = Z_TYPE_P(&accessKey) != IS_NULL;
	if (_7) {
		_7 = zephir_array_isset_value(&accessList, &accessKey);
	}
	if (_7) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 672);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
	}
	ZEPHIR_INIT_VAR(&_8);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_LONG(&_8, 0);
	} else {
		ZEPHIR_CPY_WRT(&_8, &haveAccess);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessGranted"), &_8);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 4, 0);
	zephir_array_update_string(&_9, SL("role"), roleName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("component"), componentName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_10);
	zephir_read_property(&_10, this_ptr, ZEND_STRL("accessGranted"), PH_NOISY_CC);
	zephir_array_update_string(&_9, SL("granted"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "acl:afterCheckAccess");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_5, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &accessKey);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunction"), &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_11$$8, this_ptr, "buildkey", NULL, 217, roleName, componentName, &access_zv);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &_11$$8);
		zephir_read_property(&_12$$8, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_12$$8, 1));
	}
	if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "invokerule", NULL, 218, &funcAccess, &haveAccess, &parameters, &roleObject, &componentObject, roleName, componentName, &access_zv);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));
}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole)
{
	zval roleName_zv, _0;
	zend_string *roleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&roleName_zv, roleName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &roleName_zv));
}

/**
 * Check whether component exist in the components list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isComponent)
{
	zval componentName_zv, _0;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&componentName_zv, componentName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &componentName_zv));
}

/**
 * Sets the default access level (`Phalcon\Enum::ALLOW` or `Phalcon\Enum::DENY`)
 * for no arguments provided in isAllowed action if there exists func for
 * accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction)
{
	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(defaultAccess)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, ZEND_STRL("noArgumentsDefaultAction"), &_0);
}

/**
 * Checks if a role has access to a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny)
{
	zend_bool _9$$3, _14$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _1, _2, _3, *_4$$3, _8$$3, *_11$$3, _13$$3, _6$$5, _10$$7, _15$$14;
	zend_string *roleName = NULL, *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&action_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_15$$14);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_ZVAL(action)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	access = ZEND_CALL_ARG(execute_data, 3);
	action = ZEND_CALL_ARG(execute_data, 4);
	if (ZEND_NUM_ARGS() > 4) {
		func = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 205, &_0, &roleName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 205, &_2, &componentName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_3);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 771);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$3);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, &accessName);
				zephir_check_call_status();
				if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_acl_exceptions_accessrulenotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_7, 219, &accessName, &componentName_zv);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$5, "phalcon/Acl/Adapter/Memory.zep", 767);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			_9$$3 = 1;
			while (1) {
				if (_9$$3) {
					_9$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_8$$3, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, &accessName);
					zephir_check_call_status();
					if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
						ZEPHIR_INIT_NVAR(&_10$$7);
						object_init_ex(&_10$$7, phalcon_acl_exceptions_accessrulenotfound_ce);
						ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", &_7, 219, &accessName, &componentName_zv);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$7, "phalcon/Acl/Adapter/Memory.zep", 767);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 779);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _11$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _11$$3);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_12, 217, &roleName_zv, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
				if (Z_TYPE_P(func) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			_14$$3 = 1;
			while (1) {
				if (_14$$3) {
					_14$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_13$$3, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_12, 217, &roleName_zv, &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
					if (Z_TYPE_P(func) != IS_NULL) {
						zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_5, 207, &componentName_zv, access);
			zephir_check_call_status();
			if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
				ZEPHIR_INIT_VAR(&_15$$14);
				object_init_ex(&_15$$14, phalcon_acl_exceptions_accessrulenotfound_ce);
				ZEPHIR_CALL_METHOD(NULL, &_15$$14, "__construct", &_7, 219, access, &componentName_zv);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_15$$14, "phalcon/Acl/Adapter/Memory.zep", 784);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_12, 217, &roleName_zv, &componentName_zv, access);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds the `<component>!<access>` access-list key
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, buildAccessKey)
{
	zval componentName_zv, access_zv;
	zend_string *componentName = NULL, *access = NULL;

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&componentName_zv, componentName);
	ZVAL_STR(&access_zv, access);
	ZEPHIR_CONCAT_VSV(return_value, &componentName_zv, "!", &access_zv);
	return;
}

/**
 * Builds the `<role>!<component>!<access>` rule key
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, buildKey)
{
	zval roleName_zv, componentName_zv, access_zv;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_zv);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&roleName_zv, roleName);
	ZVAL_STR(&componentName_zv, componentName);
	ZVAL_STR(&access_zv, access);
	ZEPHIR_CONCAT_VSVSV(return_value, &roleName_zv, "!", &componentName_zv, "!", &access_zv);
	return;
}

/**
 * Check whether a role is allowed to access an action from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess)
{
	zend_bool _6$$6, _14$$14;
	zval accessKey, roleComponentPrefix, inheritPrefix;
	zval usedRoleToInherits, checkRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, componentName_zv, access_zv, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _0, _1$$6, _2$$6, *_3$$6, _5$$6, _7$$9, _8$$9, _9$$9, _10$$14, _11$$14, *_12$$14, _13$$14;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&checkRoleToInherit);
	ZVAL_UNDEF(&usedRoleToInherit);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&roleComponentPrefix);
	ZVAL_UNDEF(&inheritPrefix);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	zephir_memory_observe(&access_zv);
	ZVAL_STR_COPY(&access_zv, access);
	zephir_memory_observe(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&roleComponentPrefix);
	ZEPHIR_CONCAT_VSVS(&roleComponentPrefix, &roleName_zv, "!", &componentName_zv, "!");
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VV(&accessKey, &roleComponentPrefix, &access_zv);
	if (zephir_array_isset_value(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleComponentPrefix, "*");
	if (zephir_array_isset_value(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleName_zv, "!*!*");
	if (zephir_array_isset_value(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &roleName_zv)) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property(&_1$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 869);
		zephir_is_iterable(&_2$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 873);
		if (Z_TYPE_P(&_2$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$6), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _3$$6);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 209, &checkRoleToInherits, &usedRoleToInherit);
				ZEPHIR_UNREF(&checkRoleToInherits);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_2$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			_6$$6 = 1;
			while (1) {
				if (_6$$6) {
					_6$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_2$$6, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_5$$6, &_2$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_2$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_MAKE_REF(&checkRoleToInherits);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 209, &checkRoleToInherits, &usedRoleToInherit);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&usedRoleToInherit);
		ZEPHIR_INIT_VAR(&usedRoleToInherits);
		array_init(&usedRoleToInherits);
		pendingIndex = 0;
		while (1) {
			if (!(pendingIndex < zephir_fast_count_int(&checkRoleToInherits))) {
				break;
			}
			ZEPHIR_OBS_NVAR(&checkRoleToInherit);
			zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 883);
			pendingIndex++;
			if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_7$$9);
			ZEPHIR_CONCAT_VSVS(&_7$$9, &checkRoleToInherit, "!", &componentName_zv, "!");
			zephir_get_strval(&inheritPrefix, &_7$$9);
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VV(&accessKey, &inheritPrefix, &access_zv);
			if (zephir_array_isset_value(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VS(&accessKey, &inheritPrefix, "*");
			if (zephir_array_isset_value(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&_8$$9);
			ZEPHIR_CONCAT_VS(&_8$$9, &checkRoleToInherit, "!*!*");
			zephir_get_strval(&accessKey, &_8$$9);
			if (zephir_array_isset_value(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			zephir_read_property(&_9$$9, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_9$$9, &checkRoleToInherit)) {
				zephir_read_property(&_10$$14, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_11$$14, &_10$$14, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 925);
				zephir_is_iterable(&_11$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 928);
				if (Z_TYPE_P(&_11$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_11$$14), _12$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _12$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 209, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_11$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					_14$$14 = 1;
					while (1) {
						if (_14$$14) {
							_14$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_11$$14, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_13$$14, &_11$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_11$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_4, 209, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			}
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * @param array  $collection
 * @param string $element
 * @param string $elementName
 * @param string $suffix
 *
 * @throws ElementNotFound
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, checkExists)
{
	zval _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL, *elementName = NULL, *suffix = NULL;
	zval *collection_param = NULL, element_zv, elementName_zv, suffix_zv, _0$$3;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&elementName_zv);
	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_STR(element)
		Z_PARAM_STR(elementName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&collection, collection_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	zephir_memory_observe(&elementName_zv);
	ZVAL_STR_COPY(&elementName_zv, elementName);
	if (!suffix) {
		suffix = zend_string_init(ZEND_STRL("ACL"), 0);
		zephir_memory_observe(&suffix_zv);
		ZVAL_STR(&suffix_zv, suffix);
	} else {
		zephir_memory_observe(&suffix_zv);
	ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	if (1 != zephir_array_isset_value(&collection, &element_zv)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_elementnotfound_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSVSV(&_1$$3, &elementName_zv, " '", &element_zv, "' does not exist in the ", &suffix_zv);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 953);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Invokes a callable rule, binding the role/component/user objects to the
 * closure parameters by type and enforcing its arity.
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, invokeRule)
{
	zval _55, _45$$16, _47$$18;
	zend_bool hasComponent, hasRole, _26, _0$$3, _3$$4, _5$$5, _8$$5, _9$$5, _11$$5, _12$$5, _14$$5, _27$$10, _28$$11, _30$$11, _31$$11, _33$$11, _34$$11, _36$$11, _48$$18, _50$$17, _52$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_21 = NULL, *_23 = NULL;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zend_long haveAccess, ZEPHIR_LAST_CALL_STATUS;
	zval *funcAccess, funcAccess_sub, *haveAccess_param = NULL, *parameters, parameters_sub, *roleObject, roleObject_sub, *componentObject, componentObject_sub, roleName_zv, componentName_zv, access_zv, className, numberOfRequiredParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionFunction, reflectionParameter, reflectionParameters, reflectionType, userParametersSizeShouldBe, *_2, _25, _54, _1$$3, _6$$5, _10$$5, _13$$5, _15$$5, _16$$5, _17$$8, _18$$8, _19$$8, _20$$8, _22$$8, _24$$9, _29$$11, _32$$11, _35$$11, _37$$11, _38$$11, _39$$14, _40$$14, _41$$14, _42$$14, _43$$14, _44$$15, _46$$16, _49$$18, _51$$17, _53$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&funcAccess_sub);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&roleObject_sub);
	ZVAL_UNDEF(&componentObject_sub);
	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_zv);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&reflectionType);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_54);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_43$$14);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_46$$16);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_51$$17);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_45$$16);
	ZVAL_UNDEF(&_47$$18);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_ZVAL(funcAccess)
		Z_PARAM_LONG(haveAccess)
		Z_PARAM_ZVAL(parameters)
		Z_PARAM_ZVAL(roleObject)
		Z_PARAM_ZVAL(componentObject)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	funcAccess = ZEND_CALL_ARG(execute_data, 1);
	haveAccess_param = ZEND_CALL_ARG(execute_data, 2);
	parameters = ZEND_CALL_ARG(execute_data, 3);
	roleObject = ZEND_CALL_ARG(execute_data, 4);
	componentObject = ZEND_CALL_ARG(execute_data, 5);
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	zephir_memory_observe(&access_zv);
	ZVAL_STR_COPY(&access_zv, access);
	hasComponent = 0;
	hasRole = 0;
	ZEPHIR_INIT_VAR(&reflectionFunction);
	object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 220, funcAccess);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 221);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parameterNumber);
	ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters));
	if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
		_0$$3 = haveAccess == 1;
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_CALL_USER_FUNC(&_1$$3, funcAccess);
			zephir_check_call_status();
			_0$$3 = zephir_is_true(&_1$$3);
		}
		RETURN_MM_BOOL(_0$$3);
	}
	ZEPHIR_INIT_VAR(&parametersForFunction);
	array_init(&parametersForFunction);
	ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 222);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
	zephir_is_iterable(&reflectionParameters, 0, "phalcon/Acl/Adapter/Memory.zep", 1055);
	if (Z_TYPE_P(&reflectionParameters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _2)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _2);
			ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			_3$$4 = Z_TYPE_P(&reflectionType) != IS_NULL;
			if (_3$$4) {
				_3$$4 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
			}
			if (_3$$4) {
				ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&reflectionClass);
				object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_4, 223, &className);
				zephir_check_call_status();
				_5$$5 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_5$$5) {
					ZEPHIR_CALL_METHOD(&_6$$5, &reflectionClass, "isinstance", &_7, 224, roleObject);
					zephir_check_call_status();
					_5$$5 = zephir_is_true(&_6$$5);
				}
				_8$$5 = _5$$5;
				if (_8$$5) {
					_8$$5 = !hasRole;
				}
				if (_8$$5) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1008);
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_9$$5 = Z_TYPE_P(componentObject) != IS_NULL;
				if (_9$$5) {
					ZEPHIR_CALL_METHOD(&_10$$5, &reflectionClass, "isinstance", &_7, 224, componentObject);
					zephir_check_call_status();
					_9$$5 = zephir_is_true(&_10$$5);
				}
				_11$$5 = _9$$5;
				if (_11$$5) {
					_11$$5 = !hasComponent;
				}
				if (_11$$5) {
					hasComponent = 1;
					zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1020);
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_12$$5 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (_12$$5) {
					zephir_array_fetch(&_13$$5, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1031);
					_12$$5 = Z_TYPE_P(&_13$$5) == IS_OBJECT;
				}
				_14$$5 = _12$$5;
				if (_14$$5) {
					zephir_array_fetch(&_16$$5, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1032);
					ZEPHIR_CALL_METHOD(&_15$$5, &reflectionClass, "isinstance", &_7, 224, &_16$$5);
					zephir_check_call_status();
					_14$$5 = !zephir_is_true(&_15$$5);
				}
				if (UNEXPECTED(_14$$5)) {
					ZEPHIR_INIT_NVAR(&_17$$8);
					object_init_ex(&_17$$8, phalcon_acl_exceptions_parametertypemismatch_ce);
					ZEPHIR_INIT_NVAR(&_18$$8);
					zephir_array_fetch(&_19$$8, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1039);
					zephir_get_class(&_18$$8, &_19$$8, 0);
					ZEPHIR_CALL_METHOD(&_20$$8, &reflectionClass, "getname", &_21, 225);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$8);
					ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_22$$8, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_18$$8, " , Class in defined function: ", &_20$$8, ".");
					ZEPHIR_CALL_METHOD(NULL, &_17$$8, "__construct", &_23, 8, &_22$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_17$$8, "phalcon/Acl/Adapter/Memory.zep", 1042);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset_value(parameters, &parameterToCheck)) {
				zephir_array_fetch(&_24$$9, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1051);
				zephir_array_append(&parametersForFunction, &_24$$9, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1051);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "rewind", NULL, 0);
		zephir_check_call_status();
		_26 = 1;
		while (1) {
			if (_26) {
				_26 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_25, &reflectionParameters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reflectionParameter, &reflectionParameters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				_27$$10 = Z_TYPE_P(&reflectionType) != IS_NULL;
				if (_27$$10) {
					_27$$10 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
				}
				if (_27$$10) {
					ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&reflectionClass);
					object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_4, 223, &className);
					zephir_check_call_status();
					_28$$11 = Z_TYPE_P(roleObject) != IS_NULL;
					if (_28$$11) {
						ZEPHIR_CALL_METHOD(&_29$$11, &reflectionClass, "isinstance", &_7, 224, roleObject);
						zephir_check_call_status();
						_28$$11 = zephir_is_true(&_29$$11);
					}
					_30$$11 = _28$$11;
					if (_30$$11) {
						_30$$11 = !hasRole;
					}
					if (_30$$11) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1008);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_31$$11 = Z_TYPE_P(componentObject) != IS_NULL;
					if (_31$$11) {
						ZEPHIR_CALL_METHOD(&_32$$11, &reflectionClass, "isinstance", &_7, 224, componentObject);
						zephir_check_call_status();
						_31$$11 = zephir_is_true(&_32$$11);
					}
					_33$$11 = _31$$11;
					if (_33$$11) {
						_33$$11 = !hasComponent;
					}
					if (_33$$11) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1020);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_34$$11 = zephir_array_isset_value(parameters, &parameterToCheck);
					if (_34$$11) {
						zephir_array_fetch(&_35$$11, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1031);
						_34$$11 = Z_TYPE_P(&_35$$11) == IS_OBJECT;
					}
					_36$$11 = _34$$11;
					if (_36$$11) {
						zephir_array_fetch(&_38$$11, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1032);
						ZEPHIR_CALL_METHOD(&_37$$11, &reflectionClass, "isinstance", &_7, 224, &_38$$11);
						zephir_check_call_status();
						_36$$11 = !zephir_is_true(&_37$$11);
					}
					if (UNEXPECTED(_36$$11)) {
						ZEPHIR_INIT_NVAR(&_39$$14);
						object_init_ex(&_39$$14, phalcon_acl_exceptions_parametertypemismatch_ce);
						ZEPHIR_INIT_NVAR(&_40$$14);
						zephir_array_fetch(&_41$$14, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1039);
						zephir_get_class(&_40$$14, &_41$$14, 0);
						ZEPHIR_CALL_METHOD(&_42$$14, &reflectionClass, "getname", &_21, 225);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_43$$14);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_43$$14, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_40$$14, " , Class in defined function: ", &_42$$14, ".");
						ZEPHIR_CALL_METHOD(NULL, &_39$$14, "__construct", &_23, 8, &_43$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_39$$14, "phalcon/Acl/Adapter/Memory.zep", 1042);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset_value(parameters, &parameterToCheck)) {
					zephir_array_fetch(&_44$$15, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1051);
					zephir_array_append(&parametersForFunction, &_44$$15, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1051);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reflectionParameter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
	if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(parameters)))) {
		ZEPHIR_INIT_VAR(&_45$$16);
		ZEPHIR_CONCAT_SSVSVSVS(&_45$$16, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. Extra parameters will be ignored.");
		ZVAL_LONG(&_46$$16, 512);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 10, &_45$$16, &_46$$16);
		zephir_check_call_status();
	}
	if (zephir_fast_count_int(&parametersForFunction) == 0) {
		if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
			ZEPHIR_INIT_VAR(&_47$$18);
			ZEPHIR_CONCAT_SVSVSVS(&_47$$18, "You did not provide any parameters when '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. We will use default action when no arguments.");
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 10, &_47$$18);
			zephir_check_call_status();
			_48$$18 = haveAccess == 1;
			if (_48$$18) {
				zephir_read_property(&_49$$18, this_ptr, ZEND_STRL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
				_48$$18 = ZEPHIR_IS_LONG(&_49$$18, 1);
			}
			RETURN_MM_BOOL(_48$$18);
		}
		_50$$17 = haveAccess == 1;
		if (_50$$17) {
			ZEPHIR_INIT_VAR(&_51$$17);
			ZEPHIR_CALL_USER_FUNC(&_51$$17, funcAccess);
			zephir_check_call_status();
			_50$$17 = zephir_is_true(&_51$$17);
		}
		RETURN_MM_BOOL(_50$$17);
	}
	if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
		_52$$19 = haveAccess == 1;
		if (_52$$19) {
			ZEPHIR_INIT_VAR(&_53$$19);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_53$$19, funcAccess, &parametersForFunction);
			zephir_check_call_status();
			_52$$19 = zephir_is_true(&_53$$19);
		}
		RETURN_MM_BOOL(_52$$19);
	}
	ZEPHIR_INIT_VAR(&_54);
	object_init_ex(&_54, phalcon_acl_exceptions_missingfunctionparameters_ce);
	ZEPHIR_INIT_VAR(&_55);
	ZEPHIR_CONCAT_SSVSVSVS(&_55, "You did not provide all necessary parameters for the ", "defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' for '", &componentName_zv, "'.");
	ZEPHIR_CALL_METHOD(NULL, &_54, "__construct", &_23, 8, &_55);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_54, "phalcon/Acl/Adapter/Memory.zep", 1096);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves a component identifier (object or string) to its name
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, toComponentName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *component, component_sub, _0$$3;

	ZVAL_UNDEF(&component_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(component)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &component);
	if (Z_TYPE_P(component) == IS_OBJECT) {
		if (zephir_instance_of_ev(component, phalcon_acl_componentawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(component, "getcomponentname", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(component, phalcon_acl_componentinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(component, "getname", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidcomponentimplementation_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 226);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1113);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(component, 1, 0);
	RETURN_MM();
}

/**
 * Resolves a role identifier (object or string) to its name
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, toRoleName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, _0$$3;

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(role)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &role);
	if (Z_TYPE_P(role) == IS_OBJECT) {
		if (zephir_instance_of_ev(role, phalcon_acl_roleawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(role, "getrolename", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(role, "getname", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidroleimplementation_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 227);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1133);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(role, 1, 0);
	RETURN_MM();
}

