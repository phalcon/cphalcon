
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
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 229, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 230);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 252, PH_NOISY_CC | PH_READONLY);
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
 *
 * The guard below is the validation, so the parameter stays `var` here.
 * The accepted values are documented on the contract.
 *
 * @phpstan-param mixed $accessList
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addComponentAccess)
{
	zend_bool exists = 0, _2, _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessKey, accessName, _0, _1, _3$$3, *_4$$4, _5$$4, *_6$$4, _10$$4, _8$$5, _9$$7, _12$$8, _13$$10, _14$$11, _15$$13;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$13);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 252, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 231, &_0, &componentName_zv, &_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_2) {
		_2 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_acl_exceptions_invalidaccesslist_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 232);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Acl/Adapter/Memory.zep", 247);
		ZEPHIR_MM_RESTORE();
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		if (Z_TYPE_P(accessList) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$4);
			zephir_string_to_char_array(&_5$$4, accessList);
			_4$$4 = &_5$$4;
		} else {
			_4$$4 = accessList;
		}
		zephir_is_iterable(_4$$4, 0, "phalcon/Acl/Adapter/Memory.zep", 265);
		if (Z_TYPE_P(_4$$4) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$4), _6$$4)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _6$$4);
				if (UNEXPECTED(zephir_memnstr_str(&accessName, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 255))) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 256);
					return;
				}
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_read_property_cached(&_8$$5, this_ptr, _zephir_prop_1, 253, PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset_value(&_8$$5, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZVAL_BOOL(&_9$$7, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_9$$7);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$4 = 1;
			while (1) {
				if (_11$$4) {
					_11$$4 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$4, _4$$4, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _4$$4, "current", NULL, 0);
				zephir_check_call_status();
					if (UNEXPECTED(zephir_memnstr_str(&accessName, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 255))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 256);
						return;
					}
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, &accessName);
					zephir_check_call_status();
					zephir_read_property_cached(&_12$$8, this_ptr, _zephir_prop_1, 253, PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset_value(&_12$$8, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_13$$10);
						ZVAL_BOOL(&_13$$10, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_13$$10);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		if (UNEXPECTED(zephir_memnstr_str(accessList, SL("!"), "phalcon/Acl/Adapter/Memory.zep", 266))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exceptions_forbiddendelimiter_ce, "access", "phalcon/Acl/Adapter/Memory.zep", 267);
			return;
		}
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, accessList);
		zephir_check_call_status();
		zephir_read_property_cached(&_14$$11, this_ptr, _zephir_prop_1, 253, PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_value(&_14$$11, &accessKey))) {
			ZEPHIR_INIT_VAR(&_15$$13);
			ZVAL_BOOL(&_15$$13, exists);
			zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_15$$13);
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
	zend_bool _36, _7$$6, _8$$6, _24$$13, _34$$19, _37$$22, _38$$22, _51$$29, _60$$35;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_15 = NULL, *_22 = NULL, *_26 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _1, _2, _3, *_5, *_6, _35, _4$$3, _11$$6, _12$$6, _13$$6, _16$$6, _9$$9, _14$$11, _17$$13, _18$$13, *_19$$13, _20$$13, *_21$$13, _23$$13, _25$$18, _27$$16, _28$$19, _29$$19, *_30$$19, _31$$19, *_32$$19, _33$$19, _40$$22, _41$$22, _42$$22, _44$$22, _39$$25, _43$$27, _45$$29, _46$$29, *_47$$29, _48$$29, *_49$$29, _50$$29, _52$$34, _53$$32, _54$$35, _55$$35, *_56$$35, _57$$35, *_58$$35, _59$$35;
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
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_42$$22);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_48$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$32);
	ZVAL_UNDEF(&_54$$35);
	ZVAL_UNDEF(&_55$$35);
	ZVAL_UNDEF(&_57$$35);
	ZVAL_UNDEF(&_59$$35);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "role list");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 231, &_0, &roleName_zv, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
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
	if (Z_TYPE_P(&roleToInheritList) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_string_to_char_array(&_1, &roleToInheritList);
		_5 = &_1;
	} else {
		_5 = &roleToInheritList;
	}
	zephir_is_iterable(_5, 0, "phalcon/Acl/Adapter/Memory.zep", 392);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _6)
		{
			ZEPHIR_INIT_NVAR(&roleToInherit);
			ZVAL_COPY(&roleToInherit, _6);
			_7$$6 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
			if (_7$$6) {
				_7$$6 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
			}
			if (_7$$6) {
				ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
			}
			_8$$6 = Z_TYPE_P(&roleInheritName) != IS_STRING;
			if (_8$$6) {
				_8$$6 = Z_TYPE_P(&roleInheritName) != IS_LONG;
			}
			if (UNEXPECTED(_8$$6)) {
				ZEPHIR_INIT_NVAR(&_9$$9);
				object_init_ex(&_9$$9, phalcon_acl_exceptions_invalidroletype_ce);
				ZEPHIR_CALL_METHOD(NULL, &_9$$9, "__construct", &_10, 234);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_9$$9, "phalcon/Acl/Adapter/Memory.zep", 323);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_11$$6, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_12$$6, &_11$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 329);
			if (zephir_fast_in_array(&roleInheritName, &_12$$6)) {
				continue;
			}
			zephir_read_property_cached(&_13$$6, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(!(zephir_array_isset_value(&_13$$6, &roleInheritName)))) {
				ZEPHIR_INIT_NVAR(&_14$$11);
				object_init_ex(&_14$$11, phalcon_acl_exceptions_rolenotfoundexception_ce);
				ZEPHIR_CALL_METHOD(NULL, &_14$$11, "__construct", &_15, 235, &roleInheritName);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$11, "phalcon/Acl/Adapter/Memory.zep", 337);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property_cached(&_16$$6, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_16$$6, &roleInheritName)) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property_cached(&_17$$13, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_18$$13, &_17$$13, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 350);
				if (Z_TYPE_P(&_18$$13) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_20$$13);
					zephir_string_to_char_array(&_20$$13, &_18$$13);
					_19$$13 = &_20$$13;
				} else {
					_19$$13 = &_18$$13;
				}
				zephir_is_iterable(_19$$13, 0, "phalcon/Acl/Adapter/Memory.zep", 354);
				if (Z_TYPE_P(_19$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_19$$13), _21$$13)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _21$$13);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _19$$13, "rewind", NULL, 0);
					zephir_check_call_status();
					_24$$13 = 1;
					while (1) {
						if (_24$$13) {
							_24$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _19$$13, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_23$$13, _19$$13, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_23$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, _19$$13, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
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
					zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 365);
					pendingIndex++;
					if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
						ZEPHIR_INIT_NVAR(&_25$$18);
						object_init_ex(&_25$$18, phalcon_acl_exceptions_circularinheritanceerror_ce);
						ZEPHIR_CALL_METHOD(NULL, &_25$$18, "__construct", &_26, 237, &roleInheritName);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_25$$18, "phalcon/Acl/Adapter/Memory.zep", 375);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property_cached(&_27$$16, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset_value(&_27$$16, &checkRoleToInherit)) {
						zephir_read_property_cached(&_28$$19, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_29$$19, &_28$$19, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 382);
						if (Z_TYPE_P(&_29$$19) == IS_STRING) {
							ZEPHIR_INIT_NVAR(&_31$$19);
							zephir_string_to_char_array(&_31$$19, &_29$$19);
							_30$$19 = &_31$$19;
						} else {
							_30$$19 = &_29$$19;
						}
						zephir_is_iterable(_30$$19, 0, "phalcon/Acl/Adapter/Memory.zep", 385);
						if (Z_TYPE_P(_30$$19) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_30$$19), _32$$19)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _32$$19);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, _30$$19, "rewind", NULL, 0);
							zephir_check_call_status();
							_34$$19 = 1;
							while (1) {
								if (_34$$19) {
									_34$$19 = 0;
								} else {
									ZEPHIR_CALL_METHOD(NULL, _30$$19, "next", NULL, 0);
									zephir_check_call_status();
								}
								ZEPHIR_CALL_METHOD(&_33$$19, _30$$19, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_33$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&usedRoleToInherit, _30$$19, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
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
		ZEPHIR_CALL_METHOD(NULL, _5, "rewind", NULL, 0);
		zephir_check_call_status();
		_36 = 1;
		while (1) {
			if (_36) {
				_36 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _5, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_35, _5, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_35)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleToInherit, _5, "current", NULL, 0);
			zephir_check_call_status();
				_37$$22 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_37$$22) {
					_37$$22 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_37$$22) {
					ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				_38$$22 = Z_TYPE_P(&roleInheritName) != IS_STRING;
				if (_38$$22) {
					_38$$22 = Z_TYPE_P(&roleInheritName) != IS_LONG;
				}
				if (UNEXPECTED(_38$$22)) {
					ZEPHIR_INIT_NVAR(&_39$$25);
					object_init_ex(&_39$$25, phalcon_acl_exceptions_invalidroletype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_39$$25, "__construct", &_10, 234);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_39$$25, "phalcon/Acl/Adapter/Memory.zep", 323);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_40$$22, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_41$$22, &_40$$22, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 329);
				if (zephir_fast_in_array(&roleInheritName, &_41$$22)) {
					continue;
				}
				zephir_read_property_cached(&_42$$22, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_array_isset_value(&_42$$22, &roleInheritName)))) {
					ZEPHIR_INIT_NVAR(&_43$$27);
					object_init_ex(&_43$$27, phalcon_acl_exceptions_rolenotfoundexception_ce);
					ZEPHIR_CALL_METHOD(NULL, &_43$$27, "__construct", &_15, 235, &roleInheritName);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_43$$27, "phalcon/Acl/Adapter/Memory.zep", 337);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property_cached(&_44$$22, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_value(&_44$$22, &roleInheritName)) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property_cached(&_45$$29, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_46$$29, &_45$$29, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 350);
					if (Z_TYPE_P(&_46$$29) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_48$$29);
						zephir_string_to_char_array(&_48$$29, &_46$$29);
						_47$$29 = &_48$$29;
					} else {
						_47$$29 = &_46$$29;
					}
					zephir_is_iterable(_47$$29, 0, "phalcon/Acl/Adapter/Memory.zep", 354);
					if (Z_TYPE_P(_47$$29) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_47$$29), _49$$29)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _49$$29);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, _47$$29, "rewind", NULL, 0);
						zephir_check_call_status();
						_51$$29 = 1;
						while (1) {
							if (_51$$29) {
								_51$$29 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, _47$$29, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_50$$29, _47$$29, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_50$$29)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&usedRoleToInherit, _47$$29, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
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
						zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 365);
						pendingIndex++;
						if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
							ZEPHIR_INIT_NVAR(&_52$$34);
							object_init_ex(&_52$$34, phalcon_acl_exceptions_circularinheritanceerror_ce);
							ZEPHIR_CALL_METHOD(NULL, &_52$$34, "__construct", &_26, 237, &roleInheritName);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_52$$34, "phalcon/Acl/Adapter/Memory.zep", 375);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property_cached(&_53$$32, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset_value(&_53$$32, &checkRoleToInherit)) {
							zephir_read_property_cached(&_54$$35, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_55$$35, &_54$$35, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 382);
							if (Z_TYPE_P(&_55$$35) == IS_STRING) {
								ZEPHIR_INIT_NVAR(&_57$$35);
								zephir_string_to_char_array(&_57$$35, &_55$$35);
								_56$$35 = &_57$$35;
							} else {
								_56$$35 = &_55$$35;
							}
							zephir_is_iterable(_56$$35, 0, "phalcon/Acl/Adapter/Memory.zep", 385);
							if (Z_TYPE_P(_56$$35) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_56$$35), _58$$35)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _58$$35);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, _56$$35, "rewind", NULL, 0);
								zephir_check_call_status();
								_60$$35 = 1;
								while (1) {
									if (_60$$35) {
										_60$$35 = 0;
									} else {
										ZEPHIR_CALL_METHOD(NULL, _56$$35, "next", NULL, 0);
										zephir_check_call_status();
									}
									ZEPHIR_CALL_METHOD(&_59$$35, _56$$35, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_59$$35)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&usedRoleToInherit, _56$$35, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_22, 236, &checkRoleToInherits, &usedRoleToInherit);
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
	_0 = Z_TYPE_P(role) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(role, phalcon_acl_roleinterface_ce);
	}
	if (_0) {
		ZEPHIR_CPY_WRT(&roleObject, role);
	} else if (Z_TYPE_P(role) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&roleObject);
		object_init_ex(&roleObject, phalcon_acl_role_ce);
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 238, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_acl_exceptions_invalidroletype_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 234);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Acl/Adapter/Memory.zep", 421);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 230);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Memory.zep", 481);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _4);
		ZVAL_LONG(&_5$$4, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_6, 239, &role, &componentName_zv, access, &_5$$4, func);
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
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(_2, 0, "phalcon/Acl/Adapter/Memory.zep", 525);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
	{
		ZEPHIR_INIT_NVAR(&role);
		ZVAL_COPY(&role, _4);
		ZVAL_LONG(&_5$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_6, 239, &role, &componentName_zv, access, &_5$$4, func);
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
		ZEPHIR_CPY_WRT(&localAccess, accessList);
	}
	zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 550);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1)
	{
		ZEPHIR_INIT_NVAR(&accessName);
		ZVAL_COPY(&accessName, _1);
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_2, 233, &componentName_zv, &accessName);
		zephir_check_call_status();
		zephir_read_property_cached(&_3$$5, this_ptr, _zephir_prop_0, 253, PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_value(&_3$$5, &accessKey)) {
			zephir_unset_property_array(this_ptr, ZEND_STRL("accessList"), &accessKey);
			zephir_read_property_cached(&_4$$6, this_ptr, _zephir_prop_0, 253, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 255, PH_NOISY_CC | PH_READONLY);
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
	zend_bool allowed = 0, _0, _1, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, _4, _13;
	zend_string *access = NULL;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, access_zv, *parameters_param = NULL, __$null, accessKey, accessList, componentObject, haveAccess, funcAccess, funcList, roleObject, ruleResult, _2, _3, _5, _6, _9, _12, _14, _7$$6, _10$$8, _11$$8;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_13);
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
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "torolename", NULL, 240, roleName);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(roleName, &_2);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "tocomponentname", NULL, 241, componentName);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(componentName, &_2);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 256, roleName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 257, componentName);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 258, &access_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 259, &__$null);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 260, &__$null);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 261, &_3);
	zephir_memory_observe(&accessList);
	zephir_read_property_cached(&accessList, this_ptr, _zephir_prop_6, 262, PH_NOISY_CC);
	zephir_memory_observe(&funcList);
	zephir_read_property_cached(&funcList, this_ptr, _zephir_prop_7, 263, PH_NOISY_CC);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_8, 264, &_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	zephir_array_update_string(&_4, SL("role"), roleName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("component"), componentName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "acl:beforeCheckAccess");
	ZVAL_BOOL(&_3, 1);
	ZVAL_BOOL(&_6, 1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "firemanagerevent", NULL, 0, &_5, &_4, &_3, &_6);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_9, 254, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_3, roleName))) {
		zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_10, 265, PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_7$$6, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 242, roleName, componentName, &access_zv);
	zephir_check_call_status();
	_8 = Z_TYPE_P(&accessKey) != IS_NULL;
	if (_8) {
		_8 = zephir_array_isset_value(&accessList, &accessKey);
	}
	if (_8) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 706);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
	}
	ZEPHIR_INIT_VAR(&_9);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&accessKey)) {
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_NULL(&_9);
	} else {
		ZEPHIR_CPY_WRT(&_9, &accessKey);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 259, &_9);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 260, &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "buildkey", NULL, 243, roleName, componentName, &access_zv);
		zephir_check_call_status();
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 259, &_10$$8);
		zephir_read_property_cached(&_11$$8, this_ptr, _zephir_prop_10, 265, PH_NOISY_CC | PH_READONLY);
		allowed = ZEPHIR_IS_LONG(&_11$$8, 1);
	} else if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_CALL_METHOD(&ruleResult, this_ptr, "invokerule", NULL, 244, &funcAccess, &haveAccess, &parameters, &roleObject, &componentObject, roleName, componentName, &access_zv);
		zephir_check_call_status();
		allowed = zephir_is_true(&ruleResult);
	} else {
		allowed = ZEPHIR_IS_LONG(&haveAccess, 1);
	}
	ZEPHIR_INIT_VAR(&_12);
	if (allowed) {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_LONG(&_12, 1);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_LONG(&_12, 0);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 261, &_12);
	ZEPHIR_INIT_VAR(&_13);
	zephir_create_array(&_13, 4, 0);
	zephir_array_update_string(&_13, SL("role"), roleName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_13, SL("component"), componentName, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_13, SL("access"), &access_zv, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_14);
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_5, 261, PH_NOISY_CC);
	zephir_array_update_string(&_13, SL("granted"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "acl:afterCheckAccess");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_5, &_13);
	zephir_check_call_status();
	RETURN_MM_BOOL(allowed);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("componentsNames", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&componentName_zv, componentName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 252, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &componentName_zv));
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("roles", 5, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&roleName_zv, roleName);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &roleName_zv));
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 266, &_0);
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
	zend_bool _11$$3, _18$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _1, _2, _3, *_4$$3, _5$$3, *_6$$3, _10$$3, *_13$$3, _14$$3, *_15$$3, _17$$3, _8$$5, _12$$7, _19$$14;
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
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_19$$14);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 254, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 231, &_0, &roleName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 252, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 231, &_2, &componentName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 253, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_3);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_5$$3);
			zephir_string_to_char_array(&_5$$3, access);
			_4$$3 = &_5$$3;
		} else {
			_4$$3 = access;
		}
		zephir_is_iterable(_4$$3, 0, "phalcon/Acl/Adapter/Memory.zep", 818);
		if (Z_TYPE_P(_4$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4$$3), _6$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _6$$3);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, &accessName);
				zephir_check_call_status();
				if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
					ZEPHIR_INIT_NVAR(&_8$$5);
					object_init_ex(&_8$$5, phalcon_acl_exceptions_accessrulenotfound_ce);
					ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", &_9, 245, &accessName, &componentName_zv);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_8$$5, "phalcon/Acl/Adapter/Memory.zep", 814);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _4$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_11$$3 = 1;
			while (1) {
				if (_11$$3) {
					_11$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _4$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_10$$3, _4$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _4$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, &accessName);
					zephir_check_call_status();
					if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
						ZEPHIR_INIT_NVAR(&_12$$7);
						object_init_ex(&_12$$7, phalcon_acl_exceptions_accessrulenotfound_ce);
						ZEPHIR_CALL_METHOD(NULL, &_12$$7, "__construct", &_9, 245, &accessName, &componentName_zv);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_12$$7, "phalcon/Acl/Adapter/Memory.zep", 814);
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		if (Z_TYPE_P(access) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_14$$3);
			zephir_string_to_char_array(&_14$$3, access);
			_13$$3 = &_14$$3;
		} else {
			_13$$3 = access;
		}
		zephir_is_iterable(_13$$3, 0, "phalcon/Acl/Adapter/Memory.zep", 826);
		if (Z_TYPE_P(_13$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_13$$3), _15$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _15$$3);
				ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_16, 243, &roleName_zv, &componentName_zv, &accessName);
				zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("access"), &accessKey, action);
				if (Z_TYPE_P(func) != IS_NULL) {
					zephir_update_property_array(this_ptr, SL("functions"), &accessKey, func);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _13$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			_18$$3 = 1;
			while (1) {
				if (_18$$3) {
					_18$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _13$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_17$$3, _13$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_17$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, _13$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_16, 243, &roleName_zv, &componentName_zv, &accessName);
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
			ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildaccesskey", &_7, 233, &componentName_zv, access);
			zephir_check_call_status();
			if (UNEXPECTED(!(zephir_array_isset_value(&accessList, &accessKey)))) {
				ZEPHIR_INIT_VAR(&_19$$14);
				object_init_ex(&_19$$14, phalcon_acl_exceptions_accessrulenotfound_ce);
				ZEPHIR_CALL_METHOD(NULL, &_19$$14, "__construct", &_9, 245, access, &componentName_zv);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$14, "phalcon/Acl/Adapter/Memory.zep", 831);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "buildkey", &_16, 243, &roleName_zv, &componentName_zv, access);
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
 *
 * Returns the rule key that grants the access, or `false` when no rule
 * matches. The native type is the wider `string | bool`.
 *
 * @return string|false
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess)
{
	zend_bool _8$$6, _18$$14;
	zval accessKey, roleComponentPrefix, inheritPrefix;
	zval usedRoleToInherits, checkRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pendingIndex = 0;
	zval roleName_zv, componentName_zv, access_zv, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _0, _1$$6, _2$$6, *_3$$6, _4$$6, *_5$$6, _7$$6, _9$$9, _10$$9, _11$$9, _12$$14, _13$$14, *_14$$14, _15$$14, *_16$$14, _17$$14;
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
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_17$$14);
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
	zephir_read_property_cached(&accessList, this_ptr, _zephir_prop_0, 262, PH_NOISY_CC);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, &roleName_zv)) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property_cached(&_1$$6, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 923);
		if (Z_TYPE_P(&_2$$6) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_4$$6);
			zephir_string_to_char_array(&_4$$6, &_2$$6);
			_3$$6 = &_4$$6;
		} else {
			_3$$6 = &_2$$6;
		}
		zephir_is_iterable(_3$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 927);
		if (Z_TYPE_P(_3$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3$$6), _5$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _5$$6);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_6, 236, &checkRoleToInherits, &usedRoleToInherit);
				ZEPHIR_UNREF(&checkRoleToInherits);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _3$$6, "rewind", NULL, 0);
			zephir_check_call_status();
			_8$$6 = 1;
			while (1) {
				if (_8$$6) {
					_8$$6 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _3$$6, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_7$$6, _3$$6, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$6)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&usedRoleToInherit, _3$$6, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_MAKE_REF(&checkRoleToInherits);
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_6, 236, &checkRoleToInherits, &usedRoleToInherit);
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
			zephir_array_fetch_long(&checkRoleToInherit, &checkRoleToInherits, pendingIndex, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 937);
			pendingIndex++;
			if (zephir_array_isset_value(&usedRoleToInherits, &checkRoleToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_9$$9);
			ZEPHIR_CONCAT_VSVS(&_9$$9, &checkRoleToInherit, "!", &componentName_zv, "!");
			zephir_get_strval(&inheritPrefix, &_9$$9);
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
			ZEPHIR_INIT_NVAR(&_10$$9);
			ZEPHIR_CONCAT_VS(&_10$$9, &checkRoleToInherit, "!*!*");
			zephir_get_strval(&accessKey, &_10$$9);
			if (zephir_array_isset_value(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			zephir_read_property_cached(&_11$$9, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_value(&_11$$9, &checkRoleToInherit)) {
				zephir_read_property_cached(&_12$$14, this_ptr, _zephir_prop_1, 255, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_13$$14, &_12$$14, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 979);
				if (Z_TYPE_P(&_13$$14) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_15$$14);
					zephir_string_to_char_array(&_15$$14, &_13$$14);
					_14$$14 = &_15$$14;
				} else {
					_14$$14 = &_13$$14;
				}
				zephir_is_iterable(_14$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 982);
				if (Z_TYPE_P(_14$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_14$$14), _16$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _16$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_6, 236, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, _14$$14, "rewind", NULL, 0);
					zephir_check_call_status();
					_18$$14 = 1;
					while (1) {
						if (_18$$14) {
							_18$$14 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, _14$$14, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_17$$14, _14$$14, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_17$$14)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, _14$$14, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_6, 236, &checkRoleToInherits, &usedRoleToInherit);
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
 * @phpstan-param array<string, mixed> $collection
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 9, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1004);
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
	zval _63, _53$$16, _55$$18;
	zend_class_entry *_1;
	zend_bool hasComponent, hasRole, _32, _2$$3, _7$$4, _8$$4, _11$$5, _14$$5, _15$$5, _17$$5, _18$$5, _20$$5, _33$$10, _34$$10, _36$$11, _38$$11, _39$$11, _41$$11, _42$$11, _44$$11, _56$$18, _58$$17, _60$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_13 = NULL, *_27 = NULL, *_29 = NULL;
	zend_string *roleName = NULL, *componentName = NULL, *access = NULL;
	zend_long haveAccess, ZEPHIR_LAST_CALL_STATUS;
	zval *funcAccess, funcAccess_sub, *haveAccess_param = NULL, *parameters, parameters_sub, *roleObject, roleObject_sub, *componentObject, componentObject_sub, roleName_zv, componentName_zv, access_zv, className, numberOfRequiredParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionFunction, reflectionParameter, reflectionParameters, reflectionType, userParametersSizeShouldBe, _0, *_4, _5, *_6, _31, _62, _3$$3, _9$$4, _12$$5, _16$$5, _19$$5, _21$$5, _22$$5, _23$$8, _24$$8, _25$$8, _26$$8, _28$$8, _30$$9, _35$$10, _37$$11, _40$$11, _43$$11, _45$$11, _46$$11, _47$$14, _48$$14, _49$$14, _50$$14, _51$$14, _52$$15, _54$$16, _57$$18, _59$$17, _61$$19;
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
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_62);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_37$$11);
	ZVAL_UNDEF(&_40$$11);
	ZVAL_UNDEF(&_43$$11);
	ZVAL_UNDEF(&_45$$11);
	ZVAL_UNDEF(&_46$$11);
	ZVAL_UNDEF(&_47$$14);
	ZVAL_UNDEF(&_48$$14);
	ZVAL_UNDEF(&_49$$14);
	ZVAL_UNDEF(&_50$$14);
	ZVAL_UNDEF(&_51$$14);
	ZVAL_UNDEF(&_52$$15);
	ZVAL_UNDEF(&_54$$16);
	ZVAL_UNDEF(&_57$$18);
	ZVAL_UNDEF(&_59$$17);
	ZVAL_UNDEF(&_61$$19);
	ZVAL_UNDEF(&_63);
	ZVAL_UNDEF(&_53$$16);
	ZVAL_UNDEF(&_55$$18);
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
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, funcAccess);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 246, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 247);
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
	ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 248);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
	if (Z_TYPE_P(&reflectionParameters) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &reflectionParameters);
		_4 = &_5;
	} else {
		_4 = &reflectionParameters;
	}
	zephir_is_iterable(_4, 0, "phalcon/Acl/Adapter/Memory.zep", 1115);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&reflectionParameter);
			ZVAL_COPY(&reflectionParameter, _6);
			ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
			zephir_check_call_status();
			_7$$4 = Z_TYPE_P(&reflectionType) != IS_NULL;
			if (_7$$4) {
				_7$$4 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
			}
			_8$$4 = _7$$4;
			if (_8$$4) {
				ZEPHIR_CALL_METHOD(&_9$$4, &reflectionType, "isbuiltin", NULL, 0);
				zephir_check_call_status();
				_8$$4 = !zephir_is_true(&_9$$4);
			}
			if (_8$$4) {
				ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&reflectionClass);
				object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
				ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_10, 249, &className);
				zephir_check_call_status();
				_11$$5 = Z_TYPE_P(roleObject) != IS_NULL;
				if (_11$$5) {
					ZEPHIR_CALL_METHOD(&_12$$5, &reflectionClass, "isinstance", &_13, 250, roleObject);
					zephir_check_call_status();
					_11$$5 = zephir_is_true(&_12$$5);
				}
				_14$$5 = _11$$5;
				if (_14$$5) {
					_14$$5 = !hasRole;
				}
				if (_14$$5) {
					hasRole = 1;
					zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1068);
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_15$$5 = Z_TYPE_P(componentObject) != IS_NULL;
				if (_15$$5) {
					ZEPHIR_CALL_METHOD(&_16$$5, &reflectionClass, "isinstance", &_13, 250, componentObject);
					zephir_check_call_status();
					_15$$5 = zephir_is_true(&_16$$5);
				}
				_17$$5 = _15$$5;
				if (_17$$5) {
					_17$$5 = !hasComponent;
				}
				if (_17$$5) {
					hasComponent = 1;
					zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1080);
					SEPARATE_ZVAL(&userParametersSizeShouldBe);
					zephir_decrement(&userParametersSizeShouldBe);
					continue;
				}
				_18$$5 = zephir_array_isset_value(parameters, &parameterToCheck);
				if (_18$$5) {
					zephir_array_fetch(&_19$$5, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1091);
					_18$$5 = Z_TYPE_P(&_19$$5) == IS_OBJECT;
				}
				_20$$5 = _18$$5;
				if (_20$$5) {
					zephir_array_fetch(&_22$$5, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1092);
					ZEPHIR_CALL_METHOD(&_21$$5, &reflectionClass, "isinstance", &_13, 250, &_22$$5);
					zephir_check_call_status();
					_20$$5 = !zephir_is_true(&_21$$5);
				}
				if (UNEXPECTED(_20$$5)) {
					ZEPHIR_INIT_NVAR(&_23$$8);
					object_init_ex(&_23$$8, phalcon_acl_exceptions_parametertypemismatch_ce);
					ZEPHIR_INIT_NVAR(&_24$$8);
					zephir_array_fetch(&_25$$8, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1099);
					zephir_get_class(&_24$$8, &_25$$8, 0);
					ZEPHIR_CALL_METHOD(&_26$$8, &reflectionClass, "getname", &_27, 251);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_28$$8);
					ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_28$$8, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_24$$8, " , Class in defined function: ", &_26$$8, ".");
					ZEPHIR_CALL_METHOD(NULL, &_23$$8, "__construct", &_29, 9, &_28$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$8, "phalcon/Acl/Adapter/Memory.zep", 1102);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_array_isset_value(parameters, &parameterToCheck)) {
				zephir_array_fetch(&_30$$9, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1111);
				zephir_array_append(&parametersForFunction, &_30$$9, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1111);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_31, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reflectionParameter, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				_33$$10 = Z_TYPE_P(&reflectionType) != IS_NULL;
				if (_33$$10) {
					_33$$10 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
				}
				_34$$10 = _33$$10;
				if (_34$$10) {
					ZEPHIR_CALL_METHOD(&_35$$10, &reflectionType, "isbuiltin", NULL, 0);
					zephir_check_call_status();
					_34$$10 = !zephir_is_true(&_35$$10);
				}
				if (_34$$10) {
					ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&reflectionClass);
					object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_10, 249, &className);
					zephir_check_call_status();
					_36$$11 = Z_TYPE_P(roleObject) != IS_NULL;
					if (_36$$11) {
						ZEPHIR_CALL_METHOD(&_37$$11, &reflectionClass, "isinstance", &_13, 250, roleObject);
						zephir_check_call_status();
						_36$$11 = zephir_is_true(&_37$$11);
					}
					_38$$11 = _36$$11;
					if (_38$$11) {
						_38$$11 = !hasRole;
					}
					if (_38$$11) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1068);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_39$$11 = Z_TYPE_P(componentObject) != IS_NULL;
					if (_39$$11) {
						ZEPHIR_CALL_METHOD(&_40$$11, &reflectionClass, "isinstance", &_13, 250, componentObject);
						zephir_check_call_status();
						_39$$11 = zephir_is_true(&_40$$11);
					}
					_41$$11 = _39$$11;
					if (_41$$11) {
						_41$$11 = !hasComponent;
					}
					if (_41$$11) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1080);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_42$$11 = zephir_array_isset_value(parameters, &parameterToCheck);
					if (_42$$11) {
						zephir_array_fetch(&_43$$11, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1091);
						_42$$11 = Z_TYPE_P(&_43$$11) == IS_OBJECT;
					}
					_44$$11 = _42$$11;
					if (_44$$11) {
						zephir_array_fetch(&_46$$11, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1092);
						ZEPHIR_CALL_METHOD(&_45$$11, &reflectionClass, "isinstance", &_13, 250, &_46$$11);
						zephir_check_call_status();
						_44$$11 = !zephir_is_true(&_45$$11);
					}
					if (UNEXPECTED(_44$$11)) {
						ZEPHIR_INIT_NVAR(&_47$$14);
						object_init_ex(&_47$$14, phalcon_acl_exceptions_parametertypemismatch_ce);
						ZEPHIR_INIT_NVAR(&_48$$14);
						zephir_array_fetch(&_49$$14, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1099);
						zephir_get_class(&_48$$14, &_49$$14, 0);
						ZEPHIR_CALL_METHOD(&_50$$14, &reflectionClass, "getname", &_27, 251);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_51$$14);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_51$$14, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", &roleName_zv, " can ", &access_zv, " ", &componentName_zv, ". Class passed: ", &_48$$14, " , Class in defined function: ", &_50$$14, ".");
						ZEPHIR_CALL_METHOD(NULL, &_47$$14, "__construct", &_29, 9, &_51$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_47$$14, "phalcon/Acl/Adapter/Memory.zep", 1102);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset_value(parameters, &parameterToCheck)) {
					zephir_array_fetch(&_52$$15, parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 1111);
					zephir_array_append(&parametersForFunction, &_52$$15, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 1111);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reflectionParameter);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 264, &userParametersSizeShouldBe);
	if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(parameters)))) {
		ZEPHIR_INIT_VAR(&_53$$16);
		ZEPHIR_CONCAT_SSVSVSVS(&_53$$16, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. Extra parameters will be ignored.");
		ZVAL_LONG(&_54$$16, 512);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 11, &_53$$16, &_54$$16);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_EMPTY(&parametersForFunction)) {
		if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
			ZEPHIR_INIT_VAR(&_55$$18);
			ZEPHIR_CONCAT_SVSVSVS(&_55$$18, "You did not provide any parameters when '", &roleName_zv, "' can '", &access_zv, "' '", &componentName_zv, "'. We will use default action when no arguments.");
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 11, &_55$$18);
			zephir_check_call_status();
			_56$$18 = haveAccess == 1;
			if (_56$$18) {
				zephir_read_property_cached(&_57$$18, this_ptr, _zephir_prop_1, 266, PH_NOISY_CC | PH_READONLY);
				_56$$18 = ZEPHIR_IS_LONG(&_57$$18, 1);
			}
			RETURN_MM_BOOL(_56$$18);
		}
		_58$$17 = haveAccess == 1;
		if (_58$$17) {
			ZEPHIR_INIT_VAR(&_59$$17);
			ZEPHIR_CALL_USER_FUNC(&_59$$17, funcAccess);
			zephir_check_call_status();
			_58$$17 = zephir_is_true(&_59$$17);
		}
		RETURN_MM_BOOL(_58$$17);
	}
	if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
		_60$$19 = haveAccess == 1;
		if (_60$$19) {
			ZEPHIR_INIT_VAR(&_61$$19);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_61$$19, funcAccess, &parametersForFunction);
			zephir_check_call_status();
			_60$$19 = zephir_is_true(&_61$$19);
		}
		RETURN_MM_BOOL(_60$$19);
	}
	ZEPHIR_INIT_VAR(&_62);
	object_init_ex(&_62, phalcon_acl_exceptions_missingfunctionparameters_ce);
	ZEPHIR_INIT_VAR(&_63);
	ZEPHIR_CONCAT_SSVSVSVS(&_63, "You did not provide all necessary parameters for the ", "defined function when checking if '", &roleName_zv, "' can '", &access_zv, "' for '", &componentName_zv, "'.");
	ZEPHIR_CALL_METHOD(NULL, &_62, "__construct", &_29, 9, &_63);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_62, "phalcon/Acl/Adapter/Memory.zep", 1156);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 252);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1178);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 253);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1203);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(role, 1, 0);
	RETURN_MM();
}

