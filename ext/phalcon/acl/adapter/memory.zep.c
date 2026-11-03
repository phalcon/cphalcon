
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
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 233, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getName", NULL, 234);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addComponentAccess", NULL, 0, &componentName, accessList);
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
	zend_bool exists = 0, _1, _4, _14$$5, _11$$6, _16$$9, _19$$12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, _0, _2$$3, _3$$3, _5$$4, *_6$$5, _7$$5, *_8$$5, _13$$5, _10$$6, _12$$8, _15$$9, _17$$11, _18$$12, _20$$14;
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
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_20$$14);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &componentName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Component");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkExists", NULL, 235, &_2$$3, &componentName_zv, &_3$$3);
		zephir_check_call_status();
	}
	_4 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_4) {
		_4 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_4)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, phalcon_acl_exceptions_invalidaccesslist_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 236);
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
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_9, 237, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_read_property_cached(&_10$$6, this_ptr, _zephir_prop_1, 258, PH_NOISY_CC | PH_READONLY);
				_11$$6 = zephir_array_isset_value(&_10$$6, &accessKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_11$$6)) {
					ZEPHIR_INIT_NVAR(&_12$$8);
					ZVAL_BOOL(&_12$$8, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_12$$8);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_14$$5 = 1;
			while (1) {
				if (_14$$5) {
					_14$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _6$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_13$$5, _6$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_13$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _6$$5, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(zephir_memnstr_str(&accessName, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 258))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 259);
						return;
					}
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_9, 237, &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_read_property_cached(&_15$$9, this_ptr, _zephir_prop_1, 258, PH_NOISY_CC | PH_READONLY);
					_16$$9 = zephir_array_isset_value(&_15$$9, &accessKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (!(_16$$9)) {
						ZEPHIR_INIT_NVAR(&_17$$11);
						ZVAL_BOOL(&_17$$11, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_17$$11);
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
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_9, 237, &componentName_zv, accessList);
		zephir_check_call_status();
		zephir_read_property_cached(&_18$$12, this_ptr, _zephir_prop_1, 258, PH_NOISY_CC | PH_READONLY);
		_19$$12 = zephir_array_isset_value(&_18$$12, &accessKey);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_19$$12)) {
			ZEPHIR_INIT_VAR(&_20$$14);
			ZVAL_BOOL(&_20$$14, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_20$$14);
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
	zend_bool _1, _6, _47, _11$$7, _12$$7, _17$$7, _19$$7, _22$$7, _24$$7, _32$$14, _33$$17, _34$$17, _38$$17, _45$$20, _48$$23, _49$$23, _54$$23, _56$$23, _59$$23, _61$$23, _68$$30, _69$$33, _70$$33, _74$$33, _81$$36;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_21 = NULL, *_30 = NULL, *_36 = NULL, *_51 = NULL, *_58 = NULL, *_72 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _5, *_8, _9, *_10, _46, _2$$3, _3$$3, _4$$3, _7$$4, _15$$7, _16$$7, _18$$7, _23$$7, _13$$10, _20$$12, _25$$14, _26$$14, *_27$$14, _28$$14, *_29$$14, _31$$14, _37$$17, _35$$19, _39$$20, _40$$20, *_41$$20, _42$$20, *_43$$20, _44$$20, _52$$23, _53$$23, _55$$23, _60$$23, _50$$26, _57$$28, _62$$30, _63$$30, *_64$$30, _65$$30, *_66$$30, _67$$30, _73$$33, _71$$35, _75$$36, _76$$36, *_77$$36, _78$$36, *_79$$36, _80$$36;
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
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_35$$19);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_40$$20);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_44$$20);
	ZVAL_UNDEF(&_52$$23);
	ZVAL_UNDEF(&_53$$23);
	ZVAL_UNDEF(&_55$$23);
	ZVAL_UNDEF(&_60$$23);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_57$$28);
	ZVAL_UNDEF(&_62$$30);
	ZVAL_UNDEF(&_63$$30);
	ZVAL_UNDEF(&_65$$30);
	ZVAL_UNDEF(&_67$$30);
	ZVAL_UNDEF(&_73$$33);
	ZVAL_UNDEF(&_71$$35);
	ZVAL_UNDEF(&_75$$36);
	ZVAL_UNDEF(&_76$$36);
	ZVAL_UNDEF(&_78$$36);
	ZVAL_UNDEF(&_80$$36);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&usedRoleToInherits);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Role");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "role list");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkExists", NULL, 235, &_2$$3, &roleName_zv, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getName", NULL, 0);
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
				ZEPHIR_CALL_METHOD(NULL, &_13$$10, "__construct", &_14, 238);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$10, "phalcon/Acl/Adapter/Memory.zep", 328);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_15$$7, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_16$$7);
			zephir_array_fetch(&_16$$7, &_15$$7, &roleName_zv, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 334);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_17$$7 = zephir_fast_in_array(&roleInheritName, &_16$$7);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_17$$7) {
				continue;
			}
			zephir_read_property_cached(&_18$$7, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
			_19$$7 = zephir_array_isset_value(&_18$$7, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_19$$7))) {
				ZEPHIR_INIT_NVAR(&_20$$12);
				object_init_ex(&_20$$12, phalcon_acl_exceptions_rolenotfoundexception_ce);
				ZEPHIR_CALL_METHOD(NULL, &_20$$12, "__construct", &_21, 239, &roleInheritName);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_20$$12, "phalcon/Acl/Adapter/Memory.zep", 342);
				ZEPHIR_MM_RESTORE();
				return;
			}
			_22$$7 = ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_22$$7) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property_cached(&_23$$7, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
			_24$$7 = zephir_array_isset_value(&_23$$7, &roleInheritName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_24$$7) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property_cached(&_25$$14, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_26$$14);
				zephir_array_fetch(&_26$$14, &_25$$14, &roleInheritName, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 355);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_26$$14) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_28$$14);
					zephir_string_to_char_array(&_28$$14, &_26$$14);
					_27$$14 = &_28$$14;
				} else {
					_27$$14 = &_26$$14;
				}
				zephir_is_iterable(_27$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
				if (Z_TYPE_P(_27$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_27$$14), _29$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _29$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _27$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					_32$$14 = 1;
					while (1) {
						if (_32$$14) {
							_32$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _27$$14, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_31$$14, _27$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_31$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, _27$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
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
					_33$$17 = zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_33$$17) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_34$$17 = ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(_34$$17)) {
						ZEPHIR_INIT_NVAR(&_35$$19);
						object_init_ex(&_35$$19, phalcon_acl_exceptions_circularinheritanceerror_ce);
						ZEPHIR_CALL_METHOD(NULL, &_35$$19, "__construct", &_36, 241, &roleInheritName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_35$$19, "phalcon/Acl/Adapter/Memory.zep", 380);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_37$$17, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
					_38$$17 = zephir_array_isset_value(&_37$$17, &checkRoleToInherit);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_38$$17) {
						zephir_read_property_cached(&_39$$20, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_40$$20);
						zephir_array_fetch(&_40$$20, &_39$$20, &checkRoleToInherit, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 387);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (Z_TYPE_P(&_40$$20) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_42$$20);
							zephir_string_to_char_array(&_42$$20, &_40$$20);
							_41$$20 = &_42$$20;
						} else {
							_41$$20 = &_40$$20;
						}
						zephir_is_iterable(_41$$20, 0, "phalcon/Acl/Adapter/Memory.zep", 390);
						if (Z_TYPE_P(_41$$20) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41$$20), _43$$20)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _43$$20);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _41$$20, "rewind", NULL, 0);
							zephir_check_call_status();
							_45$$20 = 1;
							while (1) {
								if (_45$$20) {
									_45$$20 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _41$$20, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_44$$20, _41$$20, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_44$$20)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&usedRoleToInherit, _41$$20, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
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
		ZEPHIR_CALL_METHOD(NULL, _8, "rewind", NULL, 0);
		zephir_check_call_status();
		_47 = 1;
		while (1) {
			if (_47) {
				_47 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _8, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_46, _8, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_46)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleToInherit, _8, "current", NULL, 0);
			zephir_check_call_status();
				_48$$23 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_48$$23) {
					_48$$23 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_48$$23) {
					ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getName", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				_49$$23 = Z_TYPE_P(&roleInheritName) != IS_STRING;
				if (_49$$23) {
					_49$$23 = Z_TYPE_P(&roleInheritName) != IS_LONG;
				}
				if (UNEXPECTED(_49$$23)) {
					ZEPHIR_INIT_NVAR(&_50$$26);
					object_init_ex(&_50$$26, phalcon_acl_exceptions_invalidroletype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_50$$26, "__construct", &_51, 238);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_50$$26, "phalcon/Acl/Adapter/Memory.zep", 328);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_52$$23, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				ZEPHIR_OBS_NVAR(&_53$$23);
				zephir_array_fetch(&_53$$23, &_52$$23, &roleName_zv, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 334);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_54$$23 = zephir_fast_in_array(&roleInheritName, &_53$$23);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_54$$23) {
					continue;
				}
				zephir_read_property_cached(&_55$$23, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
				_56$$23 = zephir_array_isset_value(&_55$$23, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_56$$23))) {
					ZEPHIR_INIT_NVAR(&_57$$28);
					object_init_ex(&_57$$28, phalcon_acl_exceptions_rolenotfoundexception_ce);
					ZEPHIR_CALL_METHOD(NULL, &_57$$28, "__construct", &_58, 239, &roleInheritName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_57$$28, "phalcon/Acl/Adapter/Memory.zep", 342);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_59$$23 = ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_59$$23) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property_cached(&_60$$23, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
				_61$$23 = zephir_array_isset_value(&_60$$23, &roleInheritName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_61$$23) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property_cached(&_62$$30, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_63$$30);
					zephir_array_fetch(&_63$$30, &_62$$30, &roleInheritName, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 355);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&_63$$30) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_65$$30);
						zephir_string_to_char_array(&_65$$30, &_63$$30);
						_64$$30 = &_65$$30;
					} else {
						_64$$30 = &_63$$30;
					}
					zephir_is_iterable(_64$$30, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
					if (Z_TYPE_P(_64$$30) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_64$$30), _66$$30)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _66$$30);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _64$$30, "rewind", NULL, 0);
						zephir_check_call_status();
						_68$$30 = 1;
						while (1) {
							if (_68$$30) {
								_68$$30 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _64$$30, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_67$$30, _64$$30, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_67$$30)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&usedRoleToInherit, _64$$30, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
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
						_69$$33 = zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_69$$33) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_70$$33 = ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (UNEXPECTED(_70$$33)) {
							ZEPHIR_INIT_NVAR(&_71$$35);
							object_init_ex(&_71$$35, phalcon_acl_exceptions_circularinheritanceerror_ce);
							ZEPHIR_CALL_METHOD(NULL, &_71$$35, "__construct", &_72, 241, &roleInheritName);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_71$$35, "phalcon/Acl/Adapter/Memory.zep", 380);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property_cached(&_73$$33, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
						_74$$33 = zephir_array_isset_value(&_73$$33, &checkRoleToInherit);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_74$$33) {
							zephir_read_property_cached(&_75$$36, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
							ZEPHIR_OBS_NVAR(&_76$$36);
							zephir_array_fetch(&_76$$36, &_75$$36, &checkRoleToInherit, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 387);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&_76$$36) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_78$$36);
								zephir_string_to_char_array(&_78$$36, &_76$$36);
								_77$$36 = &_78$$36;
							} else {
								_77$$36 = &_76$$36;
							}
							zephir_is_iterable(_77$$36, 0, "phalcon/Acl/Adapter/Memory.zep", 390);
							if (Z_TYPE_P(_77$$36) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_77$$36), _79$$36)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _79$$36);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _77$$36, "rewind", NULL, 0);
								zephir_check_call_status();
								_81$$36 = 1;
								while (1) {
									if (_81$$36) {
										_81$$36 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _77$$36, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_80$$36, _77$$36, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_80$$36)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&usedRoleToInherit, _77$$36, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_30, 240, &checkRoleToInherits, &usedRoleToInherit);
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
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 242, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_acl_exceptions_invalidroletype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 238);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Acl/Adapter/Memory.zep", 427);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getName", NULL, 234);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addInherit", NULL, 0, &roleName, accessInherits);
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
	zephir_fcall_cache_entry *_6 = NULL;
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowOrDeny", &_6, 243, &role, &componentName_zv, access, &_5$$4, func);
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
	zephir_fcall_cache_entry *_6 = NULL;
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowOrDeny", &_6, 243, &role, &componentName_zv, access, &_5$$4, func);
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
	zend_bool _4$$5;
	zval localAccess;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, *_1, _0$$3, _3$$5;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&localAccess);
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
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_2, 237, &componentName_zv, &accessName);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 258, PH_NOISY_CC | PH_READONLY);
		_4$$5 = zephir_array_isset_value(&_3$$5, &accessKey);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_4$$5) {
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 260, PH_NOISY_CC | PH_READONLY);
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
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleawareinterface_ce)) {
			ZEPHIR_CPY_WRT(&roleObject, roleName);
		}
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "toRoleName", NULL, 244, roleName);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(roleName, &_0$$3);
	}
	if (Z_TYPE_P(componentName) == IS_OBJECT) {
		if (zephir_instance_of_ev(componentName, phalcon_acl_componentawareinterface_ce)) {
			ZEPHIR_CPY_WRT(&componentObject, componentName);
		}
		ZEPHIR_CALL_METHOD(&_1$$5, this_ptr, "toComponentName", NULL, 245, componentName);
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
	zephir_memory_observe(&funcList);
	zephir_read_property_cached(&funcList, this_ptr, _zephir_prop_7, 268, PH_NOISY_CC);
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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireManagerEvent", NULL, 0, &_5, &_4, &_2, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_3)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_9, 259, PH_NOISY_CC | PH_READONLY);
	_7 = zephir_array_isset_value(&_2, roleName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_7)) {
		zephir_read_property_cached(&_8$$8, this_ptr, _zephir_prop_10, 270, PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_8$$8, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canAccess", NULL, 246, roleName, componentName, &access_zv);
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
		ZEPHIR_CALL_METHOD(&_13$$10, this_ptr, "buildKey", NULL, 247, roleName, componentName, &access_zv);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 264, &_13$$10);
		zephir_read_property_cached(&_14$$10, this_ptr, _zephir_prop_10, 270, PH_NOISY_CC | PH_READONLY);
		allowed = ZEPHIR_IS_LONG(&_14$$10, 1);
	} else if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_CALL_METHOD(&ruleResult, this_ptr, "invokeRule", NULL, 248, &funcAccess, &haveAccess, &parameters, &roleObject, &componentObject, roleName, componentName, &access_zv);
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
	if (Z_TYPE_P(&_6) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_16$$13);
		zephir_create_array(&_16$$13, 4, 0);
		zephir_array_update_string(&_16$$13, SL("role"), roleName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$13, SL("component"), componentName, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_16$$13, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
		zephir_memory_observe(&_17$$13);
		zephir_read_property_cached(&_17$$13, this_ptr, _zephir_prop_5, 266, PH_NOISY_CC);
		zephir_array_update_string(&_16$$13, SL("granted"), &_17$$13, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_18$$13);
		ZVAL_STRING(&_18$$13, "acl:afterCheckAccess");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireManagerEvent", NULL, 0, &_18$$13, &_16$$13);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 257, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
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
	zend_bool _1, _6, _18$$5, _27$$5, _14$$6, _19$$8, _28$$15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL, *_16 = NULL, *_21 = NULL, *_25 = NULL, *_30 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _5, _9, _2$$3, _3$$3, _7$$4, _8$$4, *_10$$5, _11$$5, *_12$$5, _17$$5, *_22$$5, _23$$5, *_24$$5, _26$$5, _15$$7, _20$$9, _29$$16;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_29$$16);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_value(&_0, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_1))) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 259, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Role");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkExists", &_4, 235, &_2$$3, &roleName_zv, &_3$$3);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 257, PH_NOISY_CC | PH_READONLY);
	_6 = zephir_array_isset_value(&_5, &componentName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_6))) {
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_1, 257, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "Component");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkExists", &_4, 235, &_7$$4, &componentName_zv, &_8$$4);
		zephir_check_call_status();
	}
	zephir_read_property_cached(&_9, this_ptr, _zephir_prop_2, 258, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_9);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_11$$5);
			zephir_string_to_char_array(&_11$$5, access);
			_10$$5 = &_11$$5;
		} else {
			_10$$5 = access;
		}
		zephir_is_iterable(_10$$5, 0, "phalcon/Acl/Adapter/Memory.zep", 850);
		if (Z_TYPE_P(_10$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_10$$5), _12$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _12$$5);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_13, 237, &componentName_zv, &accessName);
				zephir_check_call_status();
				_14$$6 = zephir_array_isset_value(&accessList, &accessKey);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (UNEXPECTED(!(_14$$6))) {
					ZEPHIR_INIT_NVAR(&_15$$7);
					object_init_ex(&_15$$7, phalcon_acl_exceptions_accessrulenotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_15$$7, "__construct", &_16, 249, &accessName, &componentName_zv);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_15$$7, "phalcon/Acl/Adapter/Memory.zep", 846);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _10$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_18$$5 = 1;
			while (1) {
				if (_18$$5) {
					_18$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _10$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_17$$5, _10$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _10$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_13, 237, &componentName_zv, &accessName);
					zephir_check_call_status();
					_19$$8 = zephir_array_isset_value(&accessList, &accessKey);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (UNEXPECTED(!(_19$$8))) {
						ZEPHIR_INIT_NVAR(&_20$$9);
						object_init_ex(&_20$$9, phalcon_acl_exceptions_accessrulenotfound_ce);
						ZEPHIR_CALL_METHOD(NULL, &_20$$9, "__construct", &_21, 249, &accessName, &componentName_zv);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_20$$9, "phalcon/Acl/Adapter/Memory.zep", 846);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_23$$5);
			zephir_string_to_char_array(&_23$$5, access);
			_22$$5 = &_23$$5;
		} else {
			_22$$5 = access;
		}
		zephir_is_iterable(_22$$5, 0, "phalcon/Acl/Adapter/Memory.zep", 858);
		if (Z_TYPE_P(_22$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_22$$5), _24$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _24$$5);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildKey", &_25, 247, &roleName_zv, &componentName_zv, &accessName);
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
			ZEPHIR_CALL_METHOD(NULL, _22$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			_27$$5 = 1;
			while (1) {
				if (_27$$5) {
					_27$$5 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _22$$5, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_26$$5, _22$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_26$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _22$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildKey", &_25, 247, &roleName_zv, &componentName_zv, &accessName);
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
			ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildAccessKey", &_13, 237, &componentName_zv, access);
			zephir_check_call_status();
			_28$$15 = zephir_array_isset_value(&accessList, &accessKey);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (UNEXPECTED(!(_28$$15))) {
				ZEPHIR_INIT_VAR(&_29$$16);
				object_init_ex(&_29$$16, phalcon_acl_exceptions_accessrulenotfound_ce);
				ZEPHIR_CALL_METHOD(NULL, &_29$$16, "__construct", &_30, 249, access, &componentName_zv);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_29$$16, "phalcon/Acl/Adapter/Memory.zep", 863);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildKey", &_25, 247, &roleName_zv, &componentName_zv, access);
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
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
	_4 = zephir_array_isset_value(&_3, &roleName_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
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
			ZEPHIR_CALL_METHOD(NULL, _7$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$6 = 1;
			while (1) {
				if (_11$$6) {
					_11$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _7$$6, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$6, _7$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&usedRoleToInherit, _7$$6, "current", NULL, 0);
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
			zephir_read_property_cached(&_18$$9, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
			_19$$9 = zephir_array_isset_value(&_18$$9, &checkRoleToInherit);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_19$$9) {
				zephir_read_property_cached(&_20$$14, this_ptr, _zephir_prop_1, 260, PH_NOISY_CC | PH_READONLY);
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
					ZEPHIR_CALL_METHOD(NULL, _22$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					_26$$14 = 1;
					while (1) {
						if (_26$$14) {
							_26$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _22$$14, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_25$$14, _22$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_25$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, _22$$14, "current", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
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
	zval _69, _58$$16, _61$$18;
	zend_class_entry *_1;
	zend_bool hasComponent, hasRole, _34, _2$$3, _7$$4, _8$$4, _31$$4, _11$$5, _14$$5, _15$$5, _17$$5, _18$$5, _19$$5, _21$$5, _35$$10, _36$$10, _56$$10, _38$$11, _40$$11, _41$$11, _43$$11, _44$$11, _45$$11, _47$$11, _62$$18, _64$$17, _66$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_13 = NULL, *_28 = NULL, *_30 = NULL, *_55 = NULL, *_60 = NULL;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zend_long haveAccess, ZEPHIR_LAST_CALL_STATUS;
	zval *funcAccess, funcAccess_sub, *haveAccess_param = NULL, *parameters, parameters_sub, *roleObject, roleObject_sub, *componentObject, componentObject_sub, roleName_zv, componentName_zv, access_zv, className, numberOfRequiredParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionFunction, reflectionParameter, reflectionParameters, reflectionType, userParametersSizeShouldBe, _0, *_4, _5, *_6, _33, _68, _3$$3, _9$$4, _12$$5, _16$$5, _20$$5, _22$$5, _23$$5, _24$$8, _25$$8, _26$$8, _27$$8, _29$$8, _32$$9, _37$$10, _39$$11, _42$$11, _46$$11, _48$$11, _49$$11, _50$$14, _51$$14, _52$$14, _53$$14, _54$$14, _57$$15, _59$$16, _63$$18, _65$$17, _67$$19;
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
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_37$$10);
	ZVAL_UNDEF(&_39$$11);
	ZVAL_UNDEF(&_42$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_48$$11);
	ZVAL_UNDEF(&_49$$11);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_52$$14);
	ZVAL_UNDEF(&_53$$14);
	ZVAL_UNDEF(&_54$$14);
	ZVAL_UNDEF(&_57$$15);
	ZVAL_UNDEF(&_59$$16);
	ZVAL_UNDEF(&_63$$18);
	ZVAL_UNDEF(&_65$$17);
	ZVAL_UNDEF(&_67$$19);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_58$$16);
	ZVAL_UNDEF(&_61$$18);
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
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromCallable", NULL, 0, funcAccess);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 250, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getParameters", NULL, 251);
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
	ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getNumberOfRequiredParameters", NULL, 252);
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
			ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "getType", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getName", NULL, 0);
			zephir_check_call_status();
			_7$$4 = Z_TYPE_P(&reflectionType) != IS_NULL;
			if (_7$$4) {
				_7$$4 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
			}
			_8$$4 = _7$$4;
			if (_8$$4) {
				ZEPHIR_CALL_METHOD(&_9$$4, &reflectionType, "isBuiltin", NULL, 0);
				zephir_check_call_status();
				_8$$4 = !zephir_is_true(&_9$$4);
			}
			if (_8$$4) {
				ZEPHIR_CALL_METHOD(&className, &reflectionType, "getName", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&reflectionClass);
				object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_10, 253, &className);
				zephir_check_call_status();
				_11$$5 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_11$$5) {
					ZEPHIR_CALL_METHOD(&_12$$5, &reflectionClass, "isInstance", &_13, 254, roleObject);
					zephir_check_call_status();
					_11$$5 = zephir_is_true(&_12$$5);
				}
				_14$$5 = _11$$5;
				if (_14$$5) {
					_14$$5 = !hasRole;
				}
				if (_14$$5) {
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
				_15$$5 = Z_TYPE_P(componentObject) != IS_NULL;
				if (_15$$5) {
					ZEPHIR_CALL_METHOD(&_16$$5, &reflectionClass, "isInstance", &_13, 254, componentObject);
					zephir_check_call_status();
					_15$$5 = zephir_is_true(&_16$$5);
				}
				_17$$5 = _15$$5;
				if (_17$$5) {
					_17$$5 = !hasComponent;
				}
				if (_17$$5) {
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
				_18$$5 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$5 = _18$$5;
				if (_19$$5) {
					ZEPHIR_OBS_NVAR(&_20$$5);
					zephir_array_fetch(&_20$$5, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1124);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_19$$5 = (Z_TYPE_P(&_20$$5) == IS_OBJECT);
				}
				_21$$5 = _19$$5;
				if (_21$$5) {
					ZEPHIR_OBS_NVAR(&_23$$5);
					zephir_array_fetch(&_23$$5, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1125);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(&_22$$5, &reflectionClass, "isInstance", &_13, 254, &_23$$5);
					zephir_check_call_status();
					_21$$5 = !zephir_is_true(&_22$$5);
				}
				if (UNEXPECTED(_21$$5)) {
					ZEPHIR_INIT_NVAR(&_24$$8);
					object_init_ex(&_24$$8, phalcon_acl_exceptions_parametertypemismatch_ce);
					ZEPHIR_INIT_NVAR(&_25$$8);
					ZEPHIR_OBS_NVAR(&_26$$8);
					zephir_array_fetch(&_26$$8, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1132);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_class(&_25$$8, &_26$$8, 0);
					ZEPHIR_CALL_METHOD(&_27$$8, &reflectionClass, "getName", &_28, 255);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_29$$8);
					ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_29$$8, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_25$$8, " , Class in defined function: ", &_27$$8, ".");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD(NULL, &_24$$8, "__construct", &_30, 7, &_29$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_24$$8, "phalcon/Acl/Adapter/Memory.zep", 1135);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_31$$4 = zephir_array_isset_value(parameters, &parameterToCheck);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_31$$4) {
				ZEPHIR_OBS_NVAR(&_32$$9);
				zephir_array_fetch(&_32$$9, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&parametersForFunction, &_32$$9, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1144);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_34 = 1;
		while (1) {
			if (_34) {
				_34 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_33, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_33)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reflectionParameter, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "getType", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getName", NULL, 0);
				zephir_check_call_status();
				_35$$10 = Z_TYPE_P(&reflectionType) != IS_NULL;
				if (_35$$10) {
					_35$$10 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
				}
				_36$$10 = _35$$10;
				if (_36$$10) {
					ZEPHIR_CALL_METHOD(&_37$$10, &reflectionType, "isBuiltin", NULL, 0);
					zephir_check_call_status();
					_36$$10 = !zephir_is_true(&_37$$10);
				}
				if (_36$$10) {
					ZEPHIR_CALL_METHOD(&className, &reflectionType, "getName", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&reflectionClass);
					object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_10, 253, &className);
					zephir_check_call_status();
					_38$$11 = Z_TYPE_P(roleObject) != IS_NULL;
					if (_38$$11) {
						ZEPHIR_CALL_METHOD(&_39$$11, &reflectionClass, "isInstance", &_13, 254, roleObject);
						zephir_check_call_status();
						_38$$11 = zephir_is_true(&_39$$11);
					}
					_40$$11 = _38$$11;
					if (_40$$11) {
						_40$$11 = !hasRole;
					}
					if (_40$$11) {
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
					_41$$11 = Z_TYPE_P(componentObject) != IS_NULL;
					if (_41$$11) {
						ZEPHIR_CALL_METHOD(&_42$$11, &reflectionClass, "isInstance", &_13, 254, componentObject);
						zephir_check_call_status();
						_41$$11 = zephir_is_true(&_42$$11);
					}
					_43$$11 = _41$$11;
					if (_43$$11) {
						_43$$11 = !hasComponent;
					}
					if (_43$$11) {
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
					_44$$11 = zephir_array_isset_value(parameters, &parameterToCheck);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_45$$11 = _44$$11;
					if (_45$$11) {
						ZEPHIR_OBS_NVAR(&_46$$11);
						zephir_array_fetch(&_46$$11, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1124);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_45$$11 = (Z_TYPE_P(&_46$$11) == IS_OBJECT);
					}
					_47$$11 = _45$$11;
					if (_47$$11) {
						ZEPHIR_OBS_NVAR(&_49$$11);
						zephir_array_fetch(&_49$$11, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1125);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(&_48$$11, &reflectionClass, "isInstance", &_13, 254, &_49$$11);
						zephir_check_call_status();
						_47$$11 = !zephir_is_true(&_48$$11);
					}
					if (UNEXPECTED(_47$$11)) {
						ZEPHIR_INIT_NVAR(&_50$$14);
						object_init_ex(&_50$$14, phalcon_acl_exceptions_parametertypemismatch_ce);
						ZEPHIR_INIT_NVAR(&_51$$14);
						ZEPHIR_OBS_NVAR(&_52$$14);
						zephir_array_fetch(&_52$$14, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1132);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_get_class(&_51$$14, &_52$$14, 0);
						ZEPHIR_CALL_METHOD(&_53$$14, &reflectionClass, "getName", &_28, 255);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_54$$14);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_54$$14, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_51$$14, " , Class in defined function: ", &_53$$14, ".");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_CALL_METHOD(NULL, &_50$$14, "__construct", &_55, 7, &_54$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_50$$14, "phalcon/Acl/Adapter/Memory.zep", 1135);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_56$$10 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_56$$10) {
					ZEPHIR_OBS_NVAR(&_57$$15);
					zephir_array_fetch(&_57$$15, parameters, &parameterToCheck, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 1144);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&parametersForFunction, &_57$$15, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1144);
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
		ZEPHIR_INIT_VAR(&_58$$16);
		ZEPHIR_CONCAT_SSVSVSVS(&_58$$16, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. Extra parameters will be ignored.");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_59$$16, 512);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_60, 11, &_58$$16, &_59$$16);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&parametersForFunction)) {
		if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
			ZEPHIR_INIT_VAR(&_61$$18);
			ZEPHIR_CONCAT_SVSVSVS(&_61$$18, "You did not provide any parameters when '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. We will use default action when no arguments.");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", &_60, 11, &_61$$18);
			zephir_check_call_status();
			_62$$18 = haveAccess == 1;
			if (_62$$18) {
				zephir_read_property_cached(&_63$$18, this_ptr, _zephir_prop_1, 272, PH_NOISY_CC | PH_READONLY);
				_62$$18 = ZEPHIR_IS_LONG(&_63$$18, 1);
			}
			RETURN_MM_BOOL(_62$$18);
		}
		_64$$17 = haveAccess == 1;
		if (_64$$17) {
			ZEPHIR_INIT_VAR(&_65$$17);
			ZEPHIR_CALL_USER_FUNC(&_65$$17, funcAccess);
			zephir_check_call_status();
			_64$$17 = zephir_is_true(&_65$$17);
		}
		RETURN_MM_BOOL(_64$$17);
	}
	if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
		_66$$19 = haveAccess == 1;
		if (_66$$19) {
			ZEPHIR_INIT_VAR(&_67$$19);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_67$$19, funcAccess, &parametersForFunction);
			zephir_check_call_status();
			_66$$19 = zephir_is_true(&_67$$19);
		}
		RETURN_MM_BOOL(_66$$19);
	}
	ZEPHIR_INIT_VAR(&_68);
	object_init_ex(&_68, phalcon_acl_exceptions_missingfunctionparameters_ce);
	ZEPHIR_INIT_VAR(&_69);
	ZEPHIR_CONCAT_SSVSVSVS(&_69, "You did not provide all necessary parameters for the ", "defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' for '", &componentName_zv, "'.");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, &_68, "__construct", NULL, 7, &_69);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_68, "phalcon/Acl/Adapter/Memory.zep", 1189);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(component)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &component);
	if (Z_TYPE_P(component) == IS_OBJECT) {
		if (zephir_instance_of_ev(component, phalcon_acl_componentawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(component, "getComponentName", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(component, phalcon_acl_componentinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(component, "getName", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidcomponentimplementation_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 256);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(role)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &role);
	if (Z_TYPE_P(role) == IS_OBJECT) {
		if (zephir_instance_of_ev(role, phalcon_acl_roleawareinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(role, "getRoleName", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce)) {
			ZEPHIR_RETURN_CALL_METHOD(role, "getName", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exceptions_invalidroleimplementation_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 257);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1236);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(role, 1, 0);
	RETURN_MM();
}

