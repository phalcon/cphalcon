
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/main.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
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
 *
 * @phpstan-import-type acl_access_list from AclTypes
 * @phpstan-import-type acl_component_name from AclTypes
 * @phpstan-import-type acl_components from AclTypes
 * @phpstan-import-type acl_role_name from AclTypes
 * @phpstan-import-type acl_role_to_inherit from AclTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Acl\\Adapter, Memory, phalcon, acl_adapter_memory, phalcon_acl_adapter_abstractadapter_ce, phalcon_acl_adapter_memory_method_entry, 0);

	/**
	 * Access
	 *
	 * @phpstan-var array<string, int>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("access"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Access List
	 *
	 * @phpstan-var array<string, bool>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 2);
		add_assoc_bool_ex(&_zc0, SL("*!*"), 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("accessList"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Returns the latest function used to acquire access
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeFunction"), ZEND_ACC_PROTECTED);
	/**
	 * Returns number of additional arguments(excluding role and resource) for
	 * active function
	 */
	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("activeFunctionCustomArgumentsCount"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Returns the latest key used to acquire access
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_acl_adapter_memory_ce, SL("activeKey"), ZEND_ACC_PROTECTED);
	/**
	 * Components
	 *
	 * @phpstan-var acl_components
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("components"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Component Names
	 *
	 * @phpstan-var array<string, bool>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 2);
		add_assoc_bool_ex(&_zc0, SL("*"), 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("componentsNames"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Function List
	 *
	 * @phpstan-var array<string, callable|string>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("functions"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Default action for no arguments is `deny`
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_acl_adapter_memory_ce, SL("noArgumentsDefaultAction"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Role Inherits
	 *
	 * @phpstan-var array<string, array<int, string>>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("roleInherits"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Roles
	 *
	 * @phpstan-var array<string, RoleInterface>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_acl_adapter_memory_ce, SL("roles"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Adds a component to the ACL list
 *
 * Access names can be a particular action, for instance `search`, `update`
 * `delete` etc. or a list of them.
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
 *
 * @phpstan-param ComponentInterface|string $componentValue
 * @phpstan-param acl_access_list           $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponent)
{
	zend_bool _0, _2;
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("componentsNames", 15, 1);
	}

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
		ZEPHIR_CALL_METHOD_CACHED(NULL, &componentObject, "__construct", &_zephir_call_cache[0], componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&componentName, &componentObject, "getName", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 257, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value(&_1, &componentName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		zephir_update_property_array(this_ptr, SL("components"), &componentName, &componentObject);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array(this_ptr, SL("componentsNames"), &componentName, &__$true);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "addComponentAccess", &_zephir_call_cache[2], &componentName, accessList);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Adds access to components
 *
 * The guard below is the validation, so the parameter stays `var` here.
 * The accepted values are documented on the contract.
 *
 * @phpstan-param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess)
{
	zend_bool exists = 0, _1, _4, _13$$5, _10$$6, _15$$9, _18$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, _0, _2$$3, _3$$3, _5$$4, *_6$$5, _7$$5, *_8$$5, _12$$5, _9$$6, _11$$8, _14$$9, _16$$11, _17$$12, _19$$14;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_19$$14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("componentsNames", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("accessList", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	accessList = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&componentName_zv);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 257, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &componentName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Component");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "checkExists", &_zephir_call_cache[0], &_2$$3, &componentName_zv, &_3$$3);
		zephir_check_call_status();
	}
	_4 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_4) {
		_4 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_acl_exceptions_invalidaccesslist_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$4, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalcon/Acl/Adapter/Memory.zep", 250);
		ZEPHIR_MM_RESTORE();
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_string_to_char_array(&_7$$5, accessList);
			_6$$5 = &_7$$5;
		} else {
			_6$$5 = accessList;
		}
		zephir_is_iterable(_6$$5, 0, "phalcon/Acl/Adapter/Memory.zep", 268);
		if (Z_TYPE_P(_6$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6$$5), _8$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _8$$5);
				if (UNEXPECTED(zephir_memnstr_str(&accessName, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 258))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 259);
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[2], &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_read_property_cached(&_9$$6, this_ptr, _zephir_prop_1, 258, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_10$$6 = zephir_array_isset_value(&_9$$6, &accessKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_10$$6)) {
					ZEPHIR_INIT_NVAR(&_11$$8);
					ZVAL_BOOL(&_11$$8, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_11$$8);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _6$$5, "rewind", &_zephir_call_cache[3]);
			zephir_check_call_status();
			_13$$5 = 1;
			while (1) {
				if (_13$$5) {
					_13$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _6$$5, "next", &_zephir_call_cache[4]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_12$$5, _6$$5, "valid", &_zephir_call_cache[5]);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&accessName, _6$$5, "current", &_zephir_call_cache[6]);
				zephir_check_call_status();
					if (UNEXPECTED(zephir_memnstr_str(&accessName, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 258))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 259);
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[7], &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_read_property_cached(&_14$$9, this_ptr, _zephir_prop_1, 258, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_15$$9 = zephir_array_isset_value(&_14$$9, &accessKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_15$$9)) {
						ZEPHIR_INIT_NVAR(&_16$$11);
						ZVAL_BOOL(&_16$$11, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_16$$11);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (UNEXPECTED(zephir_memnstr_str(accessList, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 269))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 270);
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[8], &componentName_zv, accessList);
		zephir_check_call_status();
		zephir_read_property_cached(&_17$$12, this_ptr, _zephir_prop_1, 258, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_18$$12 = zephir_array_isset_value(&_17$$12, &accessKey);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_18$$12)) {
			ZEPHIR_INIT_VAR(&_19$$14);
			ZVAL_BOOL(&_19$$14, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_19$$14);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Add a role which inherits from an existing role
 *
 * ```php
 * $acl->addRole("administrator", "consultant");
 * $acl->addRole("administrator", ["consultant", "consultant2"]);
 * ```
 *
 * @phpstan-param acl_role_to_inherit $roleToInherits
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addInherit)
{
	zend_bool _1, _6, _44, _11$$7, _12$$7, _16$$7, _18$$7, _20$$7, _22$$7, _30$$14, _31$$17, _32$$17, _35$$17, _42$$20, _45$$23, _46$$23, _50$$23, _52$$23, _54$$23, _56$$23, _63$$30, _64$$33, _65$$33, _68$$33, _75$$36;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _5, *_8, _9, *_10, _43, _2$$3, _3$$3, _4$$3, _7$$4, _14$$7, _15$$7, _17$$7, _21$$7, _13$$10, _19$$12, _23$$14, _24$$14, *_25$$14, _26$$14, *_27$$14, _29$$14, _34$$17, _33$$19, _36$$20, _37$$20, *_38$$20, _39$$20, *_40$$20, _41$$20, _48$$23, _49$$23, _51$$23, _55$$23, _47$$26, _53$$28, _57$$30, _58$$30, *_59$$30, _60$$30, *_61$$30, _62$$30, _67$$33, _66$$35, _69$$36, _70$$36, *_71$$36, _72$$36, *_73$$36, _74$$36;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_41$$20);
	ZVAL_UNDEF(&_48$$23);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_53$$28);
	ZVAL_UNDEF(&_57$$30);
	ZVAL_UNDEF(&_58$$30);
	ZVAL_UNDEF(&_60$$30);
	ZVAL_UNDEF(&_62$$30);
	ZVAL_UNDEF(&_67$$33);
	ZVAL_UNDEF(&_66$$35);
	ZVAL_UNDEF(&_69$$36);
	ZVAL_UNDEF(&_70$$36);
	ZVAL_UNDEF(&_72$$36);
	ZVAL_UNDEF(&_74$$36);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZEND_TLS zephir_method_cache _zephir_call_cache[29];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("roleInherits", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(roleName)
		Z_PARAM_ZVAL(roleToInherits)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	roleToInherits = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&roleName_zv);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Role");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "role list");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "checkExists", &_zephir_call_cache[0], &_2$$3, &roleName_zv, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 260, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_array_isset_value(&_5, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		array_init(&_7$$4);
		zephir_update_property_array(this_ptr, SL("roleInherits"), &roleName_zv, &_7$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(roleToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&roleToInheritList);
		zephir_create_array(&roleToInheritList, 1, 0);
		zephir_array_fast_append(&roleToInheritList, roleToInherits);
	} else {
		ZEPHIR_CPY_WRT(&roleToInheritList, roleToInherits);
	}
	if (Z_TYPE_P(&roleToInheritList) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_9);
		zephir_string_to_char_array(&_9, &roleToInheritList);
		_8 = &_9;
	} else {
		_8 = &roleToInheritList;
	}
	zephir_is_iterable(_8, 0, "phalcon/Acl/Adapter/Memory.zep", 397);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8), _10)
		{
			ZEPHIR_INIT_NVAR(&roleToInherit);
			ZVAL_COPY(&roleToInherit, _10);
			_11$$7 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
			if (_11$$7) {
				_11$$7 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
			}
			if (_11$$7) {
				ZEPHIR_CALL_METHOD_CACHED(&roleInheritName, &roleToInherit, "getName", &_zephir_call_cache[1]);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
			}
			_12$$7 = Z_TYPE_P(&roleInheritName) != IS_STRING;
			if (_12$$7) {
				_12$$7 = Z_TYPE_P(&roleInheritName) != IS_LONG;
			}
			if (UNEXPECTED(_12$$7)) {
				ZEPHIR_INIT_NVAR(&_13$$10);
				object_init_ex(&_13$$10, phalcon_acl_exceptions_invalidroletype_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$10, "__construct", &_zephir_call_cache[2]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$10, "phalcon/Acl/Adapter/Memory.zep", 328);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_14$$7, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_15$$7);
			zephir_array_fetch(&_15$$7, &_14$$7, &roleName_zv, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 334);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_16$$7 = zephir_fast_in_array(&roleInheritName, &_15$$7);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_16$$7) {
				continue;
			}
			zephir_read_property_cached(&_17$$7, this_ptr, _zephir_prop_0, 259, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_18$$7 = zephir_array_isset_value(&_17$$7, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_18$$7))) {
				ZEPHIR_INIT_NVAR(&_19$$12);
				object_init_ex(&_19$$12, phalcon_acl_exceptions_rolenotfoundexception_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_19$$12, "__construct", &_zephir_call_cache[3], &roleInheritName);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$12, "phalcon/Acl/Adapter/Memory.zep", 342);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_20$$7 = ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_20$$7) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property_cached(&_21$$7, this_ptr, _zephir_prop_1, 260, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_22$$7 = zephir_array_isset_value(&_21$$7, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_22$$7) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property_cached(&_23$$14, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_24$$14);
				zephir_array_fetch(&_24$$14, &_23$$14, &roleInheritName, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 355);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_24$$14) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					zephir_string_to_char_array(&_26$$14, &_24$$14);
					_25$$14 = &_26$$14;
				} else {
					_25$$14 = &_24$$14;
				}
				zephir_is_iterable(_25$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
				if (Z_TYPE_P(_25$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_25$$14), _27$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _27$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$14, "rewind", &_zephir_call_cache[4]);
					zephir_check_call_status();
					_30$$14 = 1;
					while (1) {
						if (_30$$14) {
							_30$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _25$$14, "next", &_zephir_call_cache[5]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_29$$14, _25$$14, "valid", &_zephir_call_cache[6]);
						zephir_check_call_status();
						if (!zend_is_true(&_29$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _25$$14, "current", &_zephir_call_cache[7]);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
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
					zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 370);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					pendingIndex++;
					_31$$17 = zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_31$$17) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_32$$17 = ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_32$$17)) {
						ZEPHIR_INIT_NVAR(&_33$$19);
						object_init_ex(&_33$$19, phalcon_acl_exceptions_circularinheritanceerror_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_33$$19, "__construct", &_zephir_call_cache[8], &roleInheritName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_33$$19, "phalcon/Acl/Adapter/Memory.zep", 380);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_34$$17, this_ptr, _zephir_prop_1, 260, PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_35$$17 = zephir_array_isset_value(&_34$$17, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_35$$17) {
						zephir_read_property_cached(&_36$$20, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_OBS_NVAR(&_37$$20);
						zephir_array_fetch(&_37$$20, &_36$$20, &checkRoleToInherit, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 387);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&_37$$20) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_39$$20);
							zephir_string_to_char_array(&_39$$20, &_37$$20);
							_38$$20 = &_39$$20;
						} else {
							_38$$20 = &_37$$20;
						}
						zephir_is_iterable(_38$$20, 0, "phalcon/Acl/Adapter/Memory.zep", 390);
						if (Z_TYPE_P(_38$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_38$$20), _40$$20)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _40$$20);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _38$$20, "rewind", &_zephir_call_cache[9]);
							zephir_check_call_status();
							_42$$20 = 1;
							while (1) {
								if (_42$$20) {
									_42$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD_CACHED(NULL, _38$$20, "next", &_zephir_call_cache[10]);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD_CACHED(&_41$$20, _38$$20, "valid", &_zephir_call_cache[11]);
								zephir_check_call_status();
								if (!zend_is_true(&_41$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _38$$20, "current", &_zephir_call_cache[12]);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
					}
				}
			}
			zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "rewind", &_zephir_call_cache[13]);
		zephir_check_call_status();
		_44 = 1;
		while (1) {
			if (_44) {
				_44 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _8, "next", &_zephir_call_cache[14]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_43, _8, "valid", &_zephir_call_cache[15]);
			zephir_check_call_status();
			if (!zend_is_true(&_43)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&roleToInherit, _8, "current", &_zephir_call_cache[16]);
			zephir_check_call_status();
				_45$$23 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_45$$23) {
					_45$$23 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_45$$23) {
					ZEPHIR_CALL_METHOD_CACHED(&roleInheritName, &roleToInherit, "getName", &_zephir_call_cache[17]);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				_46$$23 = Z_TYPE_P(&roleInheritName) != IS_STRING;
				if (_46$$23) {
					_46$$23 = Z_TYPE_P(&roleInheritName) != IS_LONG;
				}
				if (UNEXPECTED(_46$$23)) {
					ZEPHIR_INIT_NVAR(&_47$$26);
					object_init_ex(&_47$$26, phalcon_acl_exceptions_invalidroletype_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_47$$26, "__construct", &_zephir_call_cache[18]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_47$$26, "phalcon/Acl/Adapter/Memory.zep", 328);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_48$$23, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_49$$23);
				zephir_array_fetch(&_49$$23, &_48$$23, &roleName_zv, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 334);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_50$$23 = zephir_fast_in_array(&roleInheritName, &_49$$23);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_50$$23) {
					continue;
				}
				zephir_read_property_cached(&_51$$23, this_ptr, _zephir_prop_0, 259, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_52$$23 = zephir_array_isset_value(&_51$$23, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_52$$23))) {
					ZEPHIR_INIT_NVAR(&_53$$28);
					object_init_ex(&_53$$28, phalcon_acl_exceptions_rolenotfoundexception_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_53$$28, "__construct", &_zephir_call_cache[19], &roleInheritName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_53$$28, "phalcon/Acl/Adapter/Memory.zep", 342);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_54$$23 = ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_54$$23) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property_cached(&_55$$23, this_ptr, _zephir_prop_1, 260, PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_56$$23 = zephir_array_isset_value(&_55$$23, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_56$$23) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property_cached(&_57$$30, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_58$$30);
					zephir_array_fetch(&_58$$30, &_57$$30, &roleInheritName, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 355);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&_58$$30) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_60$$30);
						zephir_string_to_char_array(&_60$$30, &_58$$30);
						_59$$30 = &_60$$30;
					} else {
						_59$$30 = &_58$$30;
					}
					zephir_is_iterable(_59$$30, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
					if (Z_TYPE_P(_59$$30) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_59$$30), _61$$30)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _61$$30);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _59$$30, "rewind", &_zephir_call_cache[20]);
						zephir_check_call_status();
						_63$$30 = 1;
						while (1) {
							if (_63$$30) {
								_63$$30 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _59$$30, "next", &_zephir_call_cache[21]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_62$$30, _59$$30, "valid", &_zephir_call_cache[22]);
							zephir_check_call_status();
							if (!zend_is_true(&_62$$30)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _59$$30, "current", &_zephir_call_cache[23]);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
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
						zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 370);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						pendingIndex++;
						_64$$33 = zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_64$$33) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_65$$33 = ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(_65$$33)) {
							ZEPHIR_INIT_NVAR(&_66$$35);
							object_init_ex(&_66$$35, phalcon_acl_exceptions_circularinheritanceerror_ce);
							ZEPHIR_CALL_METHOD_CACHED(NULL, &_66$$35, "__construct", &_zephir_call_cache[24], &roleInheritName);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_66$$35, "phalcon/Acl/Adapter/Memory.zep", 380);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property_cached(&_67$$33, this_ptr, _zephir_prop_1, 260, PH_READONLY);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_68$$33 = zephir_array_isset_value(&_67$$33, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_68$$33) {
							zephir_read_property_cached(&_69$$36, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							ZEPHIR_OBS_NVAR(&_70$$36);
							zephir_array_fetch(&_70$$36, &_69$$36, &checkRoleToInherit, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 387);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&_70$$36) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_72$$36);
								zephir_string_to_char_array(&_72$$36, &_70$$36);
								_71$$36 = &_72$$36;
							} else {
								_71$$36 = &_70$$36;
							}
							zephir_is_iterable(_71$$36, 0, "phalcon/Acl/Adapter/Memory.zep", 390);
							if (Z_TYPE_P(_71$$36) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_71$$36), _73$$36)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _73$$36);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$36, "rewind", &_zephir_call_cache[25]);
								zephir_check_call_status();
								_75$$36 = 1;
								while (1) {
									if (_75$$36) {
										_75$$36 = 0;
									} else {
										ZEPHIR_CALL_METHOD_CACHED(NULL, _71$$36, "next", &_zephir_call_cache[26]);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD_CACHED(&_74$$36, _71$$36, "valid", &_zephir_call_cache[27]);
									zephir_check_call_status();
									if (!zend_is_true(&_74$$36)) {
										break;
									}
									ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _71$$36, "current", &_zephir_call_cache[28]);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_28, 74, &checkRoleToInherits, &usedRoleToInherit);
										ZEPHIR_UNREF(&checkRoleToInherits);
										zephir_check_call_status();
								}
							}
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						}
					}
				}
				zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&roleToInherit);
	RETURN_MM_BOOL(1);
}

/**
 * Adds a role to the ACL list. The second parameter lets to inherit access
 * from an existing role
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
 *
 * @phpstan-param RoleInterface|string     $role
 * @phpstan-param acl_role_to_inherit|null $accessInherits
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole)
{
	zend_bool _0, _3;
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}

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
	ZEPHIR_INIT_VAR(&roleObject);
	ZVAL_NULL(&roleObject);
	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if ((Z_TYPE_P(role) == IS_STRING)) {
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &roleObject, "__construct", &_zephir_call_cache[0], role);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_acl_exceptions_invalidroletype_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$5, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Acl/Adapter/Memory.zep", 427);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&roleName, &roleObject, "getName", &_zephir_call_cache[2]);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 259, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = zephir_array_isset_value(&_2, &roleName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		RETURN_MM_BOOL(0);
	}
	zephir_update_property_array(this_ptr, SL("roles"), &roleName, &roleObject);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(accessInherits) != IS_NULL) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "addInherit", &_zephir_call_cache[3], &roleName, accessInherits);
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
 *
 * @phpstan-param callable|null $func
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, *_4, _1$$3, _5$$4;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}

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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	if (Z_TYPE_P(&rolesArray) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &rolesArray);
		_2 = &_3;
	} else {
		_2 = &rolesArray;
	}
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Memory.zep", 489);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _4);
		ZVAL_LONG(&_5$$4, 1);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "allowOrDeny", &_zephir_call_cache[0], &role, &componentName_zv, access, &_5$$4, func);
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
 *
 * @phpstan-param callable|null $func
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, *_4, _1$$3, _5$$4;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}

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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	if (Z_TYPE_P(&rolesArray) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &rolesArray);
		_2 = &_3;
	} else {
		_2 = &rolesArray;
	}
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Memory.zep", 535);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _4);
		ZVAL_LONG(&_5$$4, 0);
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "allowOrDeny", &_zephir_call_cache[0], &role, &componentName_zv, access, &_5$$4, func);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&role);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes access from a component
 *
 * @param array<string>|string $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess)
{
	zend_bool _3$$5;
	zval localAccess;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, *_1, _0$$3, _2$$5;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&localAccess);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("accessList", 10, 1);
	}

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
		if (UNEXPECTED(Z_TYPE_P(accessList) != IS_ARRAY)) {
			zephir_throw_variable_type_error(accessList, "localAccess", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&localAccess, accessList);
	}
	zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 560);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1)
	{
		ZEPHIR_INIT_NVAR(&accessName);
		ZVAL_COPY(&accessName, _1);
		ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[0], &componentName_zv, &accessName);
		zephir_check_call_status();
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 258, PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3$$5 = zephir_array_isset_value(&_2$$5, &accessKey);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_3$$5) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("accessList"), &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
 * Returns the last composite key used to acquire access.
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
 *
 * @phpstan-return array<string, ComponentInterface>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getComponents)
{

	RETURN_MEMBER_TYPED(getThis(), "components", IS_ARRAY);
}

/**
 * Returns the inherited roles for a passed role name. If no role name
 * has been specified it will return the whole array. If the role has not
 * been found it returns an empty array
 *
 * @return array<int|string, array<int, string>|string>
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getInheritedRoles)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval roleName_zv, result, _0, _1;
	zend_string *roleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roleInherits", 12, 1);
	}

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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 260, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_fetch(&result, &_1, &roleName_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
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
 *
 * @return array<string, RoleInterface>
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
 *
 * @phpstan-param acl_role_name      $roleName
 * @phpstan-param acl_component_name $componentName
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isAllowed)
{
	zend_bool allowed = 0, _7, _9, _10, _11$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, _4, _16$$13;
	zend_string *access = NULL;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, access_zv, *parameters_param = NULL, __$null, accessKey, accessList, componentObject, haveAccess, funcAccess, funcList, roleObject, ruleResult, _2, _3, _5, _6, _12, _15, _0$$3, _1$$5, _8$$8, _13$$10, _14$$10, _17$$13, _18$$13;
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
	ZVAL_UNDEF(&ruleResult);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_16$$13);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	static zend_string *_zephir_prop_8 = NULL;
	static zend_string *_zephir_prop_9 = NULL;
	static zend_string *_zephir_prop_10 = NULL;
	static zend_string *_zephir_prop_11 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeRole", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("activeComponent", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("activeAccess", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("activeKey", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("activeFunction", 14, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("accessGranted", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("access", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("functions", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_8)) {
		_zephir_prop_8 = zend_string_init("activeFunctionCustomArgumentsCount", 34, 1);
	}
	if (UNEXPECTED(!_zephir_prop_9)) {
		_zephir_prop_9 = zend_string_init("roles", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_10)) {
		_zephir_prop_10 = zend_string_init("defaultAccess", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_11)) {
		_zephir_prop_11 = zend_string_init("eventsManager", 13, 1);
	}

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
	if (!parameters_param || Z_TYPE_P(parameters_param) == IS_NULL) {
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
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleawareinterface_ce)) {
			ZEPHIR_CPY_WRT(&roleObject, roleName);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "toRoleName", &_zephir_call_cache[0], roleName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(roleName, &_0$$3);
	}
	if (Z_TYPE_P(componentName) == IS_OBJECT) {
		if (zephir_instance_of_ev(componentName, phalcon_acl_componentawareinterface_ce)) {
			ZEPHIR_CPY_WRT(&componentObject, componentName);
		}
		ZEPHIR_CALL_METHOD_CACHED(&_1$$5, this_ptr, "toComponentName", &_zephir_call_cache[1], componentName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(componentName, &_1$$5);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 261, roleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 262, componentName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 263, &access_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 264, &__$null);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 265, &__$null);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 266, &_2);
	zephir_memory_observe(&accessList);
	zephir_read_property_cached(&accessList, this_ptr, _zephir_prop_6, 267, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&funcList);
	zephir_read_property_cached(&funcList, this_ptr, _zephir_prop_7, 268, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 269, &_2);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	zephir_array_update_string(&_4, SL("role"), roleName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("component"), componentName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "acl:beforeCheckAccess");
	ZVAL_BOOL(&_2, 1);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "fireManagerEvent", &_zephir_call_cache[2], &_5, &_4, &_2, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_9, 259, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_7 = zephir_array_isset_value(&_2, roleName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		zephir_read_property_cached(&_8$$8, this_ptr, _zephir_prop_10, 270, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_8$$8, 1)));
	}
	ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "canAccess", &_zephir_call_cache[3], roleName, componentName, &access_zv);
	zephir_check_call_status();
	_9 = Z_TYPE_P(&accessKey) != IS_NULL;
	if (_9) {
		_10 = zephir_array_isset_value(&accessList, &accessKey);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_9 = _10;
	}
	if (_9) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 725);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&funcAccess);
		_11$$9 = zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_11$$9;
	}
	ZEPHIR_INIT_VAR(&_12);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&accessKey)) {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_NULL(&_12);
	} else {
		ZEPHIR_CPY_WRT(&_12, &accessKey);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 264, &_12);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 265, &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(&_13$$10, this_ptr, "buildKey", &_zephir_call_cache[4], roleName, componentName, &access_zv);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 264, &_13$$10);
		zephir_read_property_cached(&_14$$10, this_ptr, _zephir_prop_10, 270, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		allowed = ZEPHIR_IS_LONG(&_14$$10, 1);
	} else if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_CALL_METHOD_CACHED(&ruleResult, this_ptr, "invokeRule", &_zephir_call_cache[5], &funcAccess, &haveAccess, &parameters, &roleObject, &componentObject, roleName, componentName, &access_zv);
		zephir_check_call_status();
		allowed = zephir_is_true(&ruleResult);
	} else {
		allowed = ZEPHIR_IS_LONG(&haveAccess, 1);
	}
	ZEPHIR_INIT_VAR(&_15);
	if (allowed) {
		ZEPHIR_INIT_NVAR(&_15);
		ZVAL_LONG(&_15, 1);
	} else {
		ZEPHIR_INIT_NVAR(&_15);
		ZVAL_LONG(&_15, 0);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 266, &_15);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_11, 271, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_6) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_16$$13);
		zephir_create_array(&_16$$13, 4, 0);
		zephir_array_update_string(&_16$$13, SL("role"), roleName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$13, SL("component"), componentName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$13, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
		zephir_memory_observe(&_17$$13);
		zephir_read_property_cached(&_17$$13, this_ptr, _zephir_prop_5, 266, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_16$$13, SL("granted"), &_17$$13, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_18$$13);
		ZVAL_STRING(&_18$$13, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "fireManagerEvent", &_zephir_call_cache[6], &_18$$13, &_16$$13);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(allowed);
}

/**
 * Check whether component exist in the components list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isComponent)
{
	zend_bool _1;
	zval componentName_zv, _0;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("componentsNames", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&componentName_zv, componentName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 257, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &componentName_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole)
{
	zend_bool _1;
	zval roleName_zv, _0;
	zend_string *roleName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&roleName_zv, roleName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Sets the default access level (`Phalcon\Enum::ALLOW` or
 * `Phalcon\Enum::DENY`) for no arguments provided in isAllowed action if
 * there exists func for accessKey
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, setNoArgumentsDefaultAction)
{
	zval *defaultAccess_param = NULL, _0;
	zend_long defaultAccess;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("noArgumentsDefaultAction", 24, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(defaultAccess)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 272, &_0);
}

/**
 * Checks if a role has access to a component
 *
 * @phpstan-param array<string>|string $access
 * @phpstan-param int                  $action
 * @phpstan-param callable|null        $func
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny)
{
	zend_bool _1, _5, _15$$5, _22$$5, _12$$6, _16$$8, _23$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _4, _8, _2$$3, _3$$3, _6$$4, _7$$4, *_9$$5, _10$$5, *_11$$5, _14$$5, *_18$$5, _19$$5, *_20$$5, _21$$5, _13$$7, _17$$9, _24$$16;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_24$$16);
	ZEND_TLS zephir_method_cache _zephir_call_cache[19];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("componentsNames", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("accessList", 10, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Role");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "checkExists", &_zephir_call_cache[0], &_2$$3, &roleName_zv, &_3$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 257, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_array_isset_value(&_4, &componentName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_5))) {
		zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_1, 257, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "Component");
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "checkExists", &_zephir_call_cache[1], &_6$$4, &componentName_zv, &_7$$4);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 258, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&accessList, &_8);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_10$$5);
			zephir_string_to_char_array(&_10$$5, access);
			_9$$5 = &_10$$5;
		} else {
			_9$$5 = access;
		}
		zephir_is_iterable(_9$$5, 0, "phalcon/Acl/Adapter/Memory.zep", 850);
		if (Z_TYPE_P(_9$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9$$5), _11$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _11$$5);
				ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[2], &componentName_zv, &accessName);
				zephir_check_call_status();
				_12$$6 = zephir_array_isset_value(&accessList, &accessKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_12$$6))) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					object_init_ex(&_13$$7, phalcon_acl_exceptions_accessrulenotfound_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_13$$7, "__construct", &_zephir_call_cache[3], &accessName, &componentName_zv);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_13$$7, "phalcon/Acl/Adapter/Memory.zep", 846);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$5, "rewind", &_zephir_call_cache[4]);
			zephir_check_call_status();
			_15$$5 = 1;
			while (1) {
				if (_15$$5) {
					_15$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _9$$5, "next", &_zephir_call_cache[5]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$5, _9$$5, "valid", &_zephir_call_cache[6]);
				zephir_check_call_status();
				if (!zend_is_true(&_14$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&accessName, _9$$5, "current", &_zephir_call_cache[7]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[8], &componentName_zv, &accessName);
					zephir_check_call_status();
					_16$$8 = zephir_array_isset_value(&accessList, &accessKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_16$$8))) {
						ZEPHIR_INIT_NVAR(&_17$$9);
						object_init_ex(&_17$$9, phalcon_acl_exceptions_accessrulenotfound_ce);
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_17$$9, "__construct", &_zephir_call_cache[9], &accessName, &componentName_zv);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_17$$9, "phalcon/Acl/Adapter/Memory.zep", 846);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_19$$5);
			zephir_string_to_char_array(&_19$$5, access);
			_18$$5 = &_19$$5;
		} else {
			_18$$5 = access;
		}
		zephir_is_iterable(_18$$5, 0, "phalcon/Acl/Adapter/Memory.zep", 858);
		if (Z_TYPE_P(_18$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_18$$5), _20$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _20$$5);
				ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildKey", &_zephir_call_cache[10], &roleName_zv, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(func) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _18$$5, "rewind", &_zephir_call_cache[11]);
			zephir_check_call_status();
			_22$$5 = 1;
			while (1) {
				if (_22$$5) {
					_22$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _18$$5, "next", &_zephir_call_cache[12]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_21$$5, _18$$5, "valid", &_zephir_call_cache[13]);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&accessName, _18$$5, "current", &_zephir_call_cache[14]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildKey", &_zephir_call_cache[15], &roleName_zv, &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(func) != IS_NULL) {
						zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (!ZEPHIR_IS_STRING(access, "*")) {
			ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildAccessKey", &_zephir_call_cache[16], &componentName_zv, access);
			zephir_check_call_status();
			_23$$15 = zephir_array_isset_value(&accessList, &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_23$$15))) {
				ZEPHIR_INIT_VAR(&_24$$16);
				object_init_ex(&_24$$16, phalcon_acl_exceptions_accessrulenotfound_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_24$$16, "__construct", &_zephir_call_cache[17], access, &componentName_zv);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_24$$16, "phalcon/Acl/Adapter/Memory.zep", 863);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&accessKey, this_ptr, "buildKey", &_zephir_call_cache[18], &roleName_zv, &componentName_zv, access);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(func) != IS_NULL) {
			zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
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
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	return;
}

/**
 * Check whether a role is allowed to access an action from a component
 *
 * Returns the rule key that grants the access, or `false` when no rule
 * matches. The native type is the wider `bool|string` that the Zephir
 * `string | bool` maps to.
 *
 * @return false|string
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess)
{
	zend_bool _0, _1, _2, _4, _11$$6, _12$$9, _14$$9, _15$$9, _17$$9, _19$$9, _26$$14;
	zval accessKey, roleComponentPrefix, inheritPrefix;
	zval usedRoleToInherits, checkRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, componentName_zv, access_zv, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _3, _5$$6, _6$$6, *_7$$6, _8$$6, *_9$$6, _10$$6, _13$$9, _16$$9, _18$$9, _20$$14, _21$$14, *_22$$14, _23$$14, *_24$$14, _25$$14;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_zv);
	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&access_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&checkRoleToInherit);
	ZVAL_UNDEF(&usedRoleToInherit);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&roleComponentPrefix);
	ZVAL_UNDEF(&inheritPrefix);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("access", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("roleInherits", 12, 1);
	}

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
	zephir_read_property_cached(&accessList, this_ptr, _zephir_prop_0, 267, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&roleComponentPrefix);
	ZEPHIR_CONCAT_VSVS(&roleComponentPrefix, &roleName_zv, "!", &componentName_zv, "!");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VV(&accessKey, &roleComponentPrefix, &access_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_0 = zephir_array_isset_value(&accessList, &accessKey);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleComponentPrefix, "*");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&accessList, &accessKey);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleName_zv, "!*!*");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value(&accessList, &accessKey);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		RETURN_CTOR(&accessKey);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 260, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_array_isset_value(&_3, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_6$$6);
		zephir_array_fetch(&_6$$6, &_5$$6, &roleName_zv, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 956);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&_6$$6) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$6);
			zephir_string_to_char_array(&_8$$6, &_6$$6);
			_7$$6 = &_8$$6;
		} else {
			_7$$6 = &_6$$6;
		}
		zephir_is_iterable(_7$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 960);
		if (Z_TYPE_P(_7$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_7$$6), _9$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _9$$6);
				zephir_array_append(&checkRoleToInherits, &usedRoleToInherit, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 957);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$6, "rewind", &_zephir_call_cache[0]);
			zephir_check_call_status();
			_11$$6 = 1;
			while (1) {
				if (_11$$6) {
					_11$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _7$$6, "next", &_zephir_call_cache[1]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_10$$6, _7$$6, "valid", &_zephir_call_cache[2]);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _7$$6, "current", &_zephir_call_cache[3]);
				zephir_check_call_status();
					zephir_array_append(&checkRoleToInherits, &usedRoleToInherit, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 957);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
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
			zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 970);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			pendingIndex++;
			_12$$9 = zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_12$$9) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_13$$9);
			ZEPHIR_CONCAT_VSVS(&_13$$9, &checkRoleToInherit, "!", &componentName_zv, "!");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&inheritPrefix, &_13$$9);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VV(&accessKey, &inheritPrefix, &access_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_14$$9 = zephir_array_isset_value(&accessList, &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_14$$9) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&accessKey);
			ZEPHIR_CONCAT_VS(&accessKey, &inheritPrefix, "*");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_15$$9 = zephir_array_isset_value(&accessList, &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_15$$9) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&_16$$9);
			ZEPHIR_CONCAT_VS(&_16$$9, &checkRoleToInherit, "!*!*");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_get_strval(&accessKey, &_16$$9);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_17$$9 = zephir_array_isset_value(&accessList, &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_17$$9) {
				RETURN_CTOR(&accessKey);
			}
			zephir_read_property_cached(&_18$$9, this_ptr, _zephir_prop_1, 260, PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_19$$9 = zephir_array_isset_value(&_18$$9, &checkRoleToInherit);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_19$$9) {
				zephir_read_property_cached(&_20$$14, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_21$$14);
				zephir_array_fetch(&_21$$14, &_20$$14, &checkRoleToInherit, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1012);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_21$$14) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_23$$14);
					zephir_string_to_char_array(&_23$$14, &_21$$14);
					_22$$14 = &_23$$14;
				} else {
					_22$$14 = &_21$$14;
				}
				zephir_is_iterable(_22$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 1015);
				if (Z_TYPE_P(_22$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_22$$14), _24$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _24$$14);
						zephir_array_append(&checkRoleToInherits, &usedRoleToInherit, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1013);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _22$$14, "rewind", &_zephir_call_cache[4]);
					zephir_check_call_status();
					_26$$14 = 1;
					while (1) {
						if (_26$$14) {
							_26$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _22$$14, "next", &_zephir_call_cache[5]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_25$$14, _22$$14, "valid", &_zephir_call_cache[6]);
						zephir_check_call_status();
						if (!zend_is_true(&_25$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&usedRoleToInherit, _22$$14, "current", &_zephir_call_cache[7]);
						zephir_check_call_status();
							zephir_array_append(&checkRoleToInherits, &usedRoleToInherit, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1013);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
			}
		}
	}
	RETURN_MM_BOOL(0);
}

/**
 * @phpstan-param array<string, mixed> $collection
 *
 * @throws ElementNotFound
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, checkExists)
{
	zval _2$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL, *elementName = NULL, *suffix = NULL;
	zval *collection_param = NULL, element_zv, elementName_zv, suffix_zv, _1$$3;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&elementName_zv);
	ZVAL_UNDEF(&suffix_zv);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	_0 = zephir_array_isset_value(&collection, &element_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 != _0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_acl_exceptions_elementnotfound_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VSVSV(&_2$$3, &elementName_zv, " '", &element_zv, "' does not exist in the ", &suffix_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0], &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Acl/Adapter/Memory.zep", 1037);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Invokes a callable rule, binding the role/component/user objects to the
 * closure parameters by type and enforcing its arity.
 *
 * @phpstan-param callable                      $funcAccess
 * @phpstan-param array<int|string, mixed>|null $parameters
 * @phpstan-param object|null                   $roleObject
 * @phpstan-param object|null                   $componentObject
 *
 * @throws ParameterTypeMismatch
 * @throws MissingFunctionParameters
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, invokeRule)
{
	zval _64, _53$$16, _56$$18;
	zend_class_entry *_1;
	zend_bool hasComponent, hasRole, _30, _2$$3, _7$$4, _8$$4, _27$$4, _10$$5, _12$$5, _13$$5, _15$$5, _16$$5, _17$$5, _19$$5, _31$$10, _32$$10, _51$$10, _34$$11, _36$$11, _37$$11, _39$$11, _40$$11, _41$$11, _43$$11, _57$$18, _59$$17, _61$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_55 = NULL;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zend_long haveAccess, ZEPHIR_LAST_CALL_STATUS;
	zval *funcAccess, funcAccess_sub, *haveAccess_param = NULL, *parameters, parameters_sub, *roleObject, roleObject_sub, *componentObject, componentObject_sub, roleName_zv, componentName_zv, access_zv, className, numberOfRequiredParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionFunction, reflectionParameter, reflectionParameters, reflectionType, userParametersSizeShouldBe, _0, *_4, _5, *_6, _29, _63, _3$$3, _9$$4, _11$$5, _14$$5, _18$$5, _20$$5, _21$$5, _22$$8, _23$$8, _24$$8, _25$$8, _26$$8, _28$$9, _33$$10, _35$$11, _38$$11, _42$$11, _44$$11, _45$$11, _46$$14, _47$$14, _48$$14, _49$$14, _50$$14, _52$$15, _54$$16, _58$$18, _60$$17, _62$$19;
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
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_35$$11);
	ZVAL_UNDEF(&_38$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_44$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$14);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_52$$15);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_58$$18);
	ZVAL_UNDEF(&_60$$17);
	ZVAL_UNDEF(&_62$$19);
	ZVAL_UNDEF(&_64);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_56$$18);
	ZEND_TLS zephir_method_cache _zephir_call_cache[29];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("activeFunctionCustomArgumentsCount", 34, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("noArgumentsDefaultAction", 24, 1);
	}

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
	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC_CACHED(&_0, _1, "fromCallable", &_zephir_call_cache[0], funcAccess);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionFunction, "__construct", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&reflectionParameters, &reflectionFunction, "getParameters", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parameterNumber);
	ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters));
	if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
		_2$$3 = haveAccess == 1;
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_CALL_USER_FUNC(&_3$$3, funcAccess);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_3$$3);
		}
		RETURN_MM_BOOL(_2$$3);
	}
	ZEPHIR_INIT_VAR(&parametersForFunction);
	array_init(&parametersForFunction);
	ZEPHIR_CALL_METHOD_CACHED(&numberOfRequiredParameters, &reflectionFunction, "getNumberOfRequiredParameters", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
	if (Z_TYPE_P(&reflectionParameters) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &reflectionParameters);
		_4 = &_5;
	} else {
		_4 = &reflectionParameters;
	}
	zephir_is_iterable(_4, 0, "phalcon/Acl/Adapter/Memory.zep", 1148);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _6);
			ZEPHIR_CALL_METHOD_CACHED(&reflectionType, &reflectionParameter, "getType", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&parameterToCheck, &reflectionParameter, "getName", &_zephir_call_cache[5]);
			zephir_check_call_status();
			_7$$4 = Z_TYPE_P(&reflectionType) != IS_NULL;
			if (_7$$4) {
				_7$$4 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
			}
			_8$$4 = _7$$4;
			if (_8$$4) {
				ZEPHIR_CALL_METHOD_CACHED(&_9$$4, &reflectionType, "isBuiltin", &_zephir_call_cache[6]);
				zephir_check_call_status();
				_8$$4 = !zephir_is_true(&_9$$4);
			}
			if (_8$$4) {
				ZEPHIR_CALL_METHOD_CACHED(&className, &reflectionType, "getName", &_zephir_call_cache[7]);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&reflectionClass);
				object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionClass, "__construct", &_zephir_call_cache[8], &className);
				zephir_check_call_status();
				_10$$5 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_10$$5) {
					ZEPHIR_CALL_METHOD_CACHED(&_11$$5, &reflectionClass, "isInstance", &_zephir_call_cache[9], roleObject);
					zephir_check_call_status();
					_10$$5 = zephir_is_true(&_11$$5);
				}
				_12$$5 = _10$$5;
				if (_12$$5) {
					_12$$5 = !hasRole;
				}
				if (_12$$5) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1101);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				_13$$5 = Z_TYPE_P(componentObject) != IS_NULL;
				if (_13$$5) {
					ZEPHIR_CALL_METHOD_CACHED(&_14$$5, &reflectionClass, "isInstance", &_zephir_call_cache[10], componentObject);
					zephir_check_call_status();
					_13$$5 = zephir_is_true(&_14$$5);
				}
				_15$$5 = _13$$5;
				if (_15$$5) {
					_15$$5 = !hasComponent;
				}
				if (_15$$5) {
					hasComponent = 1;
					zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1113);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					continue;
				}
				_16$$5 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_17$$5 = _16$$5;
				if (_17$$5) {
					ZEPHIR_OBS_NVAR(&_18$$5);
					zephir_array_fetch(&_18$$5, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1124);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_17$$5 = (Z_TYPE_P(&_18$$5) == IS_OBJECT);
				}
				_19$$5 = _17$$5;
				if (_19$$5) {
					ZEPHIR_OBS_NVAR(&_21$$5);
					zephir_array_fetch(&_21$$5, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1125);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_20$$5, &reflectionClass, "isInstance", &_zephir_call_cache[11], &_21$$5);
					zephir_check_call_status();
					_19$$5 = !zephir_is_true(&_20$$5);
				}
				if (UNEXPECTED(_19$$5)) {
					ZEPHIR_INIT_NVAR(&_22$$8);
					object_init_ex(&_22$$8, phalcon_acl_exceptions_parametertypemismatch_ce);
					ZEPHIR_INIT_NVAR(&_23$$8);
					ZEPHIR_OBS_NVAR(&_24$$8);
					zephir_array_fetch(&_24$$8, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1132);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_class(&_23$$8, &_24$$8, 0);
					ZEPHIR_CALL_METHOD_CACHED(&_25$$8, &reflectionClass, "getName", &_zephir_call_cache[12]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_26$$8);
					ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_26$$8, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_23$$8, " , Class in defined function: ", &_25$$8, ".");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_22$$8, "__construct", &_zephir_call_cache[13], &_26$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_22$$8, "phalcon/Acl/Adapter/Memory.zep", 1135);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_27$$4 = zephir_array_isset_value(parameters, &parameterToCheck);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_27$$4) {
				ZEPHIR_OBS_NVAR(&_28$$9);
				zephir_array_fetch(&_28$$9, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&parametersForFunction, &_28$$9, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[14]);
		zephir_check_call_status();
		_30 = 1;
		while (1) {
			if (_30) {
				_30 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[15]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_29, _4, "valid", &_zephir_call_cache[16]);
			zephir_check_call_status();
			if (!zend_is_true(&_29)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&reflectionParameter, _4, "current", &_zephir_call_cache[17]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&reflectionType, &reflectionParameter, "getType", &_zephir_call_cache[18]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&parameterToCheck, &reflectionParameter, "getName", &_zephir_call_cache[19]);
				zephir_check_call_status();
				_31$$10 = Z_TYPE_P(&reflectionType) != IS_NULL;
				if (_31$$10) {
					_31$$10 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
				}
				_32$$10 = _31$$10;
				if (_32$$10) {
					ZEPHIR_CALL_METHOD_CACHED(&_33$$10, &reflectionType, "isBuiltin", &_zephir_call_cache[20]);
					zephir_check_call_status();
					_32$$10 = !zephir_is_true(&_33$$10);
				}
				if (_32$$10) {
					ZEPHIR_CALL_METHOD_CACHED(&className, &reflectionType, "getName", &_zephir_call_cache[21]);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&reflectionClass);
					object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD_CACHED(NULL, &reflectionClass, "__construct", &_zephir_call_cache[22], &className);
					zephir_check_call_status();
					_34$$11 = Z_TYPE_P(roleObject) != IS_NULL;
					if (_34$$11) {
						ZEPHIR_CALL_METHOD_CACHED(&_35$$11, &reflectionClass, "isInstance", &_zephir_call_cache[23], roleObject);
						zephir_check_call_status();
						_34$$11 = zephir_is_true(&_35$$11);
					}
					_36$$11 = _34$$11;
					if (_36$$11) {
						_36$$11 = !hasRole;
					}
					if (_36$$11) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1101);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					_37$$11 = Z_TYPE_P(componentObject) != IS_NULL;
					if (_37$$11) {
						ZEPHIR_CALL_METHOD_CACHED(&_38$$11, &reflectionClass, "isInstance", &_zephir_call_cache[24], componentObject);
						zephir_check_call_status();
						_37$$11 = zephir_is_true(&_38$$11);
					}
					_39$$11 = _37$$11;
					if (_39$$11) {
						_39$$11 = !hasComponent;
					}
					if (_39$$11) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1113);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						continue;
					}
					_40$$11 = zephir_array_isset_value(parameters, &parameterToCheck);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_41$$11 = _40$$11;
					if (_41$$11) {
						ZEPHIR_OBS_NVAR(&_42$$11);
						zephir_array_fetch(&_42$$11, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1124);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_41$$11 = (Z_TYPE_P(&_42$$11) == IS_OBJECT);
					}
					_43$$11 = _41$$11;
					if (_43$$11) {
						ZEPHIR_OBS_NVAR(&_45$$11);
						zephir_array_fetch(&_45$$11, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1125);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(&_44$$11, &reflectionClass, "isInstance", &_zephir_call_cache[25], &_45$$11);
						zephir_check_call_status();
						_43$$11 = !zephir_is_true(&_44$$11);
					}
					if (UNEXPECTED(_43$$11)) {
						ZEPHIR_INIT_NVAR(&_46$$14);
						object_init_ex(&_46$$14, phalcon_acl_exceptions_parametertypemismatch_ce);
						ZEPHIR_INIT_NVAR(&_47$$14);
						ZEPHIR_OBS_NVAR(&_48$$14);
						zephir_array_fetch(&_48$$14, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1132);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_get_class(&_47$$14, &_48$$14, 0);
						ZEPHIR_CALL_METHOD_CACHED(&_49$$14, &reflectionClass, "getName", &_zephir_call_cache[26]);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$14);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_50$$14, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_47$$14, " , Class in defined function: ", &_49$$14, ".");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD_CACHED(NULL, &_46$$14, "__construct", &_zephir_call_cache[27], &_50$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_46$$14, "phalcon/Acl/Adapter/Memory.zep", 1135);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_51$$10 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_51$$10) {
					ZEPHIR_OBS_NVAR(&_52$$15);
					zephir_array_fetch(&_52$$15, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1144);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&parametersForFunction, &_52$$15, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1144);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reflectionParameter);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 269, &userParametersSizeShouldBe);
	if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(parameters)))) {
		ZEPHIR_INIT_VAR(&_53$$16);
		ZEPHIR_CONCAT_SSVSVSVS(&_53$$16, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. Extra parameters will be ignored.");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_54$$16, 512);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_55, 8, &_53$$16, &_54$$16);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&parametersForFunction)) {
		if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
			ZEPHIR_INIT_VAR(&_56$$18);
			ZEPHIR_CONCAT_SVSVSVS(&_56$$18, "You did not provide any parameters when '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. We will use default action when no arguments.");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_55, 8, &_56$$18);
			zephir_check_call_status();
			_57$$18 = haveAccess == 1;
			if (_57$$18) {
				zephir_read_property_cached(&_58$$18, this_ptr, _zephir_prop_1, 272, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_57$$18 = ZEPHIR_IS_LONG(&_58$$18, 1);
			}
			RETURN_MM_BOOL(_57$$18);
		}
		_59$$17 = haveAccess == 1;
		if (_59$$17) {
			ZEPHIR_INIT_VAR(&_60$$17);
			ZEPHIR_CALL_USER_FUNC(&_60$$17, funcAccess);
			zephir_check_call_status();
			_59$$17 = zephir_is_true(&_60$$17);
		}
		RETURN_MM_BOOL(_59$$17);
	}
	if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
		_61$$19 = haveAccess == 1;
		if (_61$$19) {
			ZEPHIR_INIT_VAR(&_62$$19);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_62$$19, funcAccess, &parametersForFunction);
			zephir_check_call_status();
			_61$$19 = zephir_is_true(&_62$$19);
		}
		RETURN_MM_BOOL(_61$$19);
	}
	ZEPHIR_INIT_VAR(&_63);
	object_init_ex(&_63, phalcon_acl_exceptions_missingfunctionparameters_ce);
	ZEPHIR_INIT_VAR(&_64);
	ZEPHIR_CONCAT_SSVSVSVS(&_64, "You did not provide all necessary parameters for the ", "defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' for '", &componentName_zv, "'.");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_63, "__construct", &_zephir_call_cache[28], &_64);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_63, "phalcon/Acl/Adapter/Memory.zep", 1189);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Resolves a component identifier (object or string) to its name
 *
 * @phpstan-param  object|string $component
 * @phpstan-return string
 *
 * @throws InvalidComponentImplementation
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, toComponentName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *component, component_sub, _0$$3;

	ZVAL_UNDEF(&component_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(component)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &component);
	if (Z_TYPE_P(component) == IS_OBJECT) {
		if (zephir_instance_of_ev(component, phalcon_acl_componentawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(component, "getComponentName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(component, phalcon_acl_componentinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(component, "getName", &_zephir_call_cache[1]);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidcomponentimplementation_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1211);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(component, 1, 0);
	RETURN_MM();
}

/**
 * Resolves a role identifier (object or string) to its name
 *
 * @phpstan-param  object|string $role
 * @phpstan-return string
 *
 * @throws InvalidRoleImplementation
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, toRoleName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, _0$$3;

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(role)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &role);
	if (Z_TYPE_P(role) == IS_OBJECT) {
		if (zephir_instance_of_ev(role, phalcon_acl_roleawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(role, "getRoleName", &_zephir_call_cache[0]);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(role, "getName", &_zephir_call_cache[1]);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidroleimplementation_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1236);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(role, 1, 0);
	RETURN_MM();
}

