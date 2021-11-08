
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
ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Memory)
{
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
	return SUCCESS;
}

/**
 * Returns latest function used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunction)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeFunction");
}

/**
 * Returns number of additional arguments(excluding role and resource) for active function
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveFunctionCustomArgumentsCount)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeFunctionCustomArgumentsCount");
}

/**
 * Returns latest key used to acquire access
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getActiveKey)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "activeKey");
}

/**
 * Phalcon\Acl\Adapter\Memory constructor
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, __construct)
{
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("componentsNames"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("*!*"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessList"), &_1);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(componentValue)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 157, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 158);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &componentName))) {
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
	zend_bool exists = 0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *componentName_param = NULL, *accessList, accessList_sub, accessName, _0, _1, *_3$$4, _4$$4, _5$$5, _6$$5, _7$$6, _8$$7, _9$$7, _10$$8, _11$$9, _12$$9, _13$$10;
	zval componentName, accessKey;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList_sub);
	ZVAL_UNDEF(&accessName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &componentName_param, &accessList);
	zephir_get_strval(&componentName, componentName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 159, &_0, &componentName, &_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_2) {
		_2 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for the accessList", "phalcon/Acl/Adapter/Memory.zep", 240);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 253);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _3$$4);
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_CONCAT_VSV(&_5$$5, &componentName, "!", &accessName);
				zephir_get_strval(&accessKey, &_5$$5);
				zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
				if (!(zephir_array_isset(&_6$$5, &accessKey))) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZVAL_BOOL(&_7$$6, exists);
					zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_7$$6);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, accessList, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, accessList, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, accessList, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_8$$7);
					ZEPHIR_CONCAT_VSV(&_8$$7, &componentName, "!", &accessName);
					zephir_get_strval(&accessKey, &_8$$7);
					zephir_read_property(&_9$$7, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
					if (!(zephir_array_isset(&_9$$7, &accessKey))) {
						ZEPHIR_INIT_NVAR(&_10$$8);
						ZVAL_BOOL(&_10$$8, exists);
						zephir_update_property_array(this_ptr, SL("accessList"), &accessKey, &_10$$8);
					}
				ZEPHIR_CALL_METHOD(NULL, accessList, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
	} else {
		ZEPHIR_INIT_VAR(&_11$$9);
		ZEPHIR_CONCAT_VSV(&_11$$9, &componentName, "!", accessList);
		zephir_get_strval(&accessKey, &_11$$9);
		zephir_read_property(&_12$$9, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset(&_12$$9, &accessKey))) {
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
	zend_bool _7$$6, _28$$21;
	zval checkRoleToInherits, usedRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_19 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _1, _2, _3, *_5, _6, _4$$3, _8$$6, _9$$6, _10$$6, _14$$6, _11$$10, _12$$10, _15$$12, _16$$12, *_17$$12, _18$$12, _21$$17, _22$$17, _23$$15, _24$$18, _25$$18, *_26$$18, _27$$18, _29$$21, _30$$21, _31$$21, _34$$21, _32$$25, _33$$25, _35$$27, _36$$27, *_37$$27, _38$$27, _39$$32, _40$$32, _41$$30, _42$$33, _43$$33, *_44$$33, _45$$33;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$25);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$32);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&usedRoleToInherits);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(roleName)
		Z_PARAM_ZVAL(roleToInherits)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &roleName_param, &roleToInherits);
	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "role list");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 159, &_0, &roleName, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &roleName))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_array(this_ptr, SL("roleInherits"), &roleName, &_4$$3);
	}
	if (Z_TYPE_P(roleToInherits) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&roleToInheritList);
		zephir_create_array(&roleToInheritList, 1, 0);
		zephir_array_fast_append(&roleToInheritList, roleToInherits);
	} else {
		ZEPHIR_CPY_WRT(&roleToInheritList, roleToInherits);
	}
	zephir_is_iterable(&roleToInheritList, 0, "phalcon/Acl/Adapter/Memory.zep", 366);
	if (Z_TYPE_P(&roleToInheritList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&roleToInheritList), _5)
		{
			ZEPHIR_INIT_NVAR(&roleToInherit);
			ZVAL_COPY(&roleToInherit, _5);
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
			zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_9$$6, &_8$$6, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 306);
			if (zephir_fast_in_array(&roleInheritName, &_9$$6)) {
				continue;
			}
			zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(!(zephir_array_isset(&_10$$6, &roleInheritName)))) {
				ZEPHIR_INIT_NVAR(&_11$$10);
				object_init_ex(&_11$$10, phalcon_acl_exception_ce);
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZEPHIR_CONCAT_SVS(&_12$$10, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
				ZEPHIR_CALL_METHOD(NULL, &_11$$10, "__construct", &_13, 8, &_12$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$10, "phalcon/Acl/Adapter/Memory.zep", 317);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_14$$6, &roleInheritName)) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property(&_15$$12, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_16$$12, &_15$$12, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 330);
				zephir_is_iterable(&_16$$12, 0, "phalcon/Acl/Adapter/Memory.zep", 334);
				if (Z_TYPE_P(&_16$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_16$$12), _17$$12)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _17$$12);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_16$$12, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_18$$12, &_16$$12, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$12)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_16$$12, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &_16$$12, "next", NULL, 0);
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
					ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_20, 27, &checkRoleToInherits);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
					if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName, &checkRoleToInherit))) {
						ZEPHIR_INIT_NVAR(&_21$$17);
						object_init_ex(&_21$$17, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_22$$17);
						ZEPHIR_CONCAT_SVS(&_22$$17, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
						ZEPHIR_CALL_METHOD(NULL, &_21$$17, "__construct", &_13, 8, &_22$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_21$$17, "phalcon/Acl/Adapter/Memory.zep", 349);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_23$$15, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_23$$15, &checkRoleToInherit)) {
						zephir_read_property(&_24$$18, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_25$$18, &_24$$18, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 356);
						zephir_is_iterable(&_25$$18, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
						if (Z_TYPE_P(&_25$$18) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_25$$18), _26$$18)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _26$$18);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_25$$18, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_27$$18, &_25$$18, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_27$$18)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_25$$18, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								ZEPHIR_CALL_METHOD(NULL, &_25$$18, "next", NULL, 0);
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
			ZEPHIR_CALL_METHOD(&_6, &roleToInheritList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&roleToInherit, &roleToInheritList, "current", NULL, 0);
			zephir_check_call_status();
				_28$$21 = Z_TYPE_P(&roleToInherit) == IS_OBJECT;
				if (_28$$21) {
					_28$$21 = zephir_instance_of_ev(&roleToInherit, phalcon_acl_roleinterface_ce);
				}
				if (_28$$21) {
					ZEPHIR_CALL_METHOD(&roleInheritName, &roleToInherit, "getname", NULL, 0);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&roleInheritName, &roleToInherit);
				}
				zephir_read_property(&_29$$21, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_30$$21, &_29$$21, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 306);
				if (zephir_fast_in_array(&roleInheritName, &_30$$21)) {
					continue;
				}
				zephir_read_property(&_31$$21, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_array_isset(&_31$$21, &roleInheritName)))) {
					ZEPHIR_INIT_NVAR(&_32$$25);
					object_init_ex(&_32$$25, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_33$$25);
					ZEPHIR_CONCAT_SVS(&_33$$25, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
					ZEPHIR_CALL_METHOD(NULL, &_32$$25, "__construct", &_13, 8, &_33$$25);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$25, "phalcon/Acl/Adapter/Memory.zep", 317);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_EQUAL(&roleName, &roleInheritName)) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property(&_34$$21, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_34$$21, &roleInheritName)) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property(&_35$$27, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_36$$27, &_35$$27, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 330);
					zephir_is_iterable(&_36$$27, 0, "phalcon/Acl/Adapter/Memory.zep", 334);
					if (Z_TYPE_P(&_36$$27) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_36$$27), _37$$27)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _37$$27);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
							ZEPHIR_UNREF(&checkRoleToInherits);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_36$$27, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_38$$27, &_36$$27, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_38$$27)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_36$$27, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
								ZEPHIR_UNREF(&checkRoleToInherits);
								zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, &_36$$27, "next", NULL, 0);
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
						ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_20, 27, &checkRoleToInherits);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
						if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName, &checkRoleToInherit))) {
							ZEPHIR_INIT_NVAR(&_39$$32);
							object_init_ex(&_39$$32, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_40$$32);
							ZEPHIR_CONCAT_SVS(&_40$$32, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
							ZEPHIR_CALL_METHOD(NULL, &_39$$32, "__construct", &_13, 8, &_40$$32);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_39$$32, "phalcon/Acl/Adapter/Memory.zep", 349);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property(&_41$$30, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset(&_41$$30, &checkRoleToInherit)) {
							zephir_read_property(&_42$$33, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_43$$33, &_42$$33, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 356);
							zephir_is_iterable(&_43$$33, 0, "phalcon/Acl/Adapter/Memory.zep", 359);
							if (Z_TYPE_P(&_43$$33) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_43$$33), _44$$33)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _44$$33);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
									ZEPHIR_UNREF(&checkRoleToInherits);
									zephir_check_call_status();
								} ZEND_HASH_FOREACH_END();
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_43$$33, "rewind", NULL, 0);
								zephir_check_call_status();
								while (1) {
									ZEPHIR_CALL_METHOD(&_45$$33, &_43$$33, "valid", NULL, 0);
									zephir_check_call_status();
									if (!zend_is_true(&_45$$33)) {
										break;
									}
									ZEPHIR_CALL_METHOD(&usedRoleToInherit, &_43$$33, "current", NULL, 0);
									zephir_check_call_status();
										ZEPHIR_MAKE_REF(&checkRoleToInherits);
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 160, &checkRoleToInherits, &usedRoleToInherit);
										ZEPHIR_UNREF(&checkRoleToInherits);
										zephir_check_call_status();
									ZEPHIR_CALL_METHOD(NULL, &_43$$33, "next", NULL, 0);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, addRole)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *role, role_sub, *accessInherits = NULL, accessInherits_sub, __$null, roleName, roleObject, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&role_sub);
	ZVAL_UNDEF(&accessInherits_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(role)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(accessInherits)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 161, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either a string or implement RoleInterface", "phalcon/Acl/Adapter/Memory.zep", 393);
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 162);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &roleName)) {
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, _1$$3, _4$$4, _6$$5;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&rolesArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &componentName_param, &access, &func);
	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	ZEPHIR_INIT_VAR(&rolesArray);
	zephir_create_array(&rolesArray, 1, 0);
	zephir_array_fast_append(&rolesArray, &roleName);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 445);
	if (Z_TYPE_P(&rolesArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
		{
			ZEPHIR_INIT_NVAR(&role);
			ZVAL_COPY(&role, _2);
			ZVAL_LONG(&_4$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 163, &role, &componentName, access, &_4$$4, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &rolesArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &rolesArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&role, &rolesArray, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_6$$5, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 163, &role, &componentName, access, &_6$$5, func);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &rolesArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&role);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, deny)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, _1$$3, _4$$4, _6$$5;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&access_sub);
	ZVAL_UNDEF(&func_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&role);
	ZVAL_UNDEF(&rolesArray);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName_param, &componentName_param, &access, &func);
	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	ZEPHIR_INIT_VAR(&rolesArray);
	zephir_create_array(&rolesArray, 1, 0);
	zephir_array_fast_append(&rolesArray, &roleName);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "*");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&rolesArray);
		zephir_array_keys(&rolesArray, &_1$$3);
	}
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 482);
	if (Z_TYPE_P(&rolesArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
		{
			ZEPHIR_INIT_NVAR(&role);
			ZVAL_COPY(&role, _2);
			ZVAL_LONG(&_4$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 163, &role, &componentName, access, &_4$$4, func);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &rolesArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &rolesArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&role, &rolesArray, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_LONG(&_6$$5, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 163, &role, &componentName, access, &_6$$5, func);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &rolesArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&role);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes an access from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 507);
		if (Z_TYPE_P(&localAccess) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _1$$5);
				ZEPHIR_INIT_NVAR(&_3$$6);
				ZEPHIR_CONCAT_VSV(&_3$$6, &componentName, "!", &accessName);
				zephir_get_strval(&accessKey, &_3$$6);
				zephir_read_property(&_4$$6, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_4$$6, &accessKey)) {
					zephir_unset_property_array(this_ptr, ZEND_STRL("accessList"), &accessKey);
					zephir_read_property(&_5$$7, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
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
					zephir_read_property(&_7$$8, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_7$$8, &accessKey)) {
						zephir_unset_property_array(this_ptr, ZEND_STRL("accessList"), &accessKey);
						zephir_read_property(&_8$$9, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
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
 * Return an array with every component registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getComponents)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "components");
}

/**
 * Returns the inherited roles for a passed role name. If no role name
 * has been specified it will return the whole array. If the role has not
 * been found it returns an empty array
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getInheritedRoles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *roleName_param = NULL, result, _0, _1;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &roleName_param);
	if (!roleName_param) {
		ZEPHIR_INIT_VAR(&roleName);
		ZVAL_STRING(&roleName, "");
	} else {
		zephir_get_strval(&roleName, roleName_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName)) {
		RETURN_MM_MEMBER(getThis(), "roleInherits");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&result, &_1, &roleName, 1))) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CTOR(&result);
}

/**
 * Returns the default ACL access level for no arguments provided in
 * `isAllowed` action if a `func` (callable) exists for `accessKey`
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getNoArgumentsDefaultAction)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "noArgumentsDefaultAction");
}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "roles");
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
	zend_bool hasComponent, hasRole, _10, _13$$16, _17$$18, _19$$18, _20$$18, _22$$18, _23$$18, _25$$18, _34$$24, _36$$24, _37$$24, _39$$24, _40$$24, _42$$24, _54$$31, _56$$30, _58$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval access, _2$$6, _5$$10;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, *access_param = NULL, *parameters_param = NULL, __$null, accessKey, accessList, componentObject, haveAccess, funcAccess, funcList, numberOfRequiredParameters, reflectionFunction, reflectionParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionParameter, roleObject, userParametersSizeShouldBe, _6, _7, _8, _0$$5, _1$$6, _3$$9, _4$$10, _9$$12, _11$$14, _12$$14, _14$$16, *_15$$15, _16$$15, _60$$15, _61$$15, _18$$18, _21$$18, _24$$18, _26$$18, _27$$18, _28$$21, _29$$21, _30$$21, _31$$21, _32$$21, _33$$22, _35$$24, _38$$24, _41$$24, _43$$24, _44$$24, _45$$27, _46$$27, _47$$27, _48$$27, _49$$27, _50$$28, _51$$29, _52$$29, _53$$31, _55$$31, _57$$30, _59$$32;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&componentName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&haveAccess);
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
	ZVAL_UNDEF(&roleObject);
	ZVAL_UNDEF(&userParametersSizeShouldBe);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_14$$16);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_60$$15);
	ZVAL_UNDEF(&_61$$15);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_21$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$21);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_43$$24);
	ZVAL_UNDEF(&_44$$24);
	ZVAL_UNDEF(&_45$$27);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$27);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$29);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_57$$30);
	ZVAL_UNDEF(&_59$$32);
	ZVAL_UNDEF(&access);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&parameters);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ZVAL(roleName)
		Z_PARAM_ZVAL(componentName)
		Z_PARAM_STR(access)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_OR_NULL(parameters)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &roleName, &componentName, &access_param, &parameters_param);
	ZEPHIR_SEPARATE_PARAM(roleName);
	ZEPHIR_SEPARATE_PARAM(componentName);
	zephir_get_strval(&access, access_param);
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
	hasComponent = 0;
	hasRole = 0;
	if (Z_TYPE_P(roleName) == IS_OBJECT) {
		if (zephir_instance_of_ev(roleName, phalcon_acl_roleawareinterface_ce)) {
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
			ZEPHIR_CONCAT_SS(&_2$$6, "Object passed as roleName must implement ", "Phalcon\\Acl\\RoleAwareInterface or Phalcon\\Acl\\RoleInterface");
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 8, &_2$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "phalcon/Acl/Adapter/Memory.zep", 587);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(componentName) == IS_OBJECT) {
		if (zephir_instance_of_ev(componentName, phalcon_acl_componentawareinterface_ce)) {
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
			ZEPHIR_CONCAT_SS(&_5$$10, "Object passed as componentName must implement ", "Phalcon\\Acl\\ComponentAwareInterface or Phalcon\\Acl\\ComponentInterface");
			ZEPHIR_CALL_METHOD(NULL, &_4$$10, "__construct", NULL, 8, &_5$$10);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$10, "phalcon/Acl/Adapter/Memory.zep", 601);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRole"), roleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeComponent"), componentName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), &access);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunction"), &__$null);
	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&funcList);
	zephir_read_property(&funcList, this_ptr, ZEND_STRL("func"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(&_6, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunctionCustomArgumentsCount"), &_6);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "acl:beforeCheckAccess");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "firemanagerevent", NULL, 0, &_8, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_6, roleName))) {
		zephir_read_property(&_9$$12, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL((ZEPHIR_IS_LONG(&_9$$12, 1)));
	}
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 164, roleName, componentName, &access);
	zephir_check_call_status();
	_10 = Z_TYPE_P(&accessKey) != IS_NULL;
	if (_10) {
		_10 = zephir_array_isset(&accessList, &accessKey);
	}
	if (_10) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 633);
		ZEPHIR_OBS_NVAR(&funcAccess);
		zephir_array_isset_fetch(&funcAccess, &funcList, &accessKey, 0);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessGranted"), &haveAccess);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "acl:afterCheckAccess");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_8, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &accessKey);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunction"), &funcAccess);
	if (Z_TYPE_P(&haveAccess) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_11$$14);
		ZEPHIR_CONCAT_VSVSV(&_11$$14, roleName, "!", componentName, "!", &access);
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &_11$$14);
		zephir_read_property(&_12$$14, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_12$$14, 1));
	}
	if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 165, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 166);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&parameterNumber);
		ZVAL_LONG(&parameterNumber, zephir_fast_count_int(&reflectionParameters));
		if (ZEPHIR_IS_LONG_IDENTICAL(&parameterNumber, 0)) {
			_13$$16 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_13$$16) {
				ZEPHIR_INIT_VAR(&_14$$16);
				ZEPHIR_CALL_USER_FUNC(&_14$$16, &funcAccess);
				zephir_check_call_status();
				_13$$16 = zephir_is_true(&_14$$16);
			}
			RETURN_MM_BOOL(_13$$16);
		}
		ZEPHIR_INIT_VAR(&parametersForFunction);
		array_init(&parametersForFunction);
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 167);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/Acl/Adapter/Memory.zep", 736);
		if (Z_TYPE_P(&reflectionParameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _15$$15)
			{
				ZEPHIR_INIT_NVAR(&reflectionParameter);
				ZVAL_COPY(&reflectionParameter, _15$$15);
				ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
					_17$$18 = Z_TYPE_P(&roleObject) != IS_NULL;
					if (_17$$18) {
						ZEPHIR_CALL_METHOD(&_18$$18, &reflectionClass, "isinstance", NULL, 0, &roleObject);
						zephir_check_call_status();
						_17$$18 = zephir_is_true(&_18$$18);
					}
					_19$$18 = _17$$18;
					if (_19$$18) {
						_19$$18 = !hasRole;
					}
					if (_19$$18) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 689);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_20$$18 = Z_TYPE_P(&componentObject) != IS_NULL;
					if (_20$$18) {
						ZEPHIR_CALL_METHOD(&_21$$18, &reflectionClass, "isinstance", NULL, 0, &componentObject);
						zephir_check_call_status();
						_20$$18 = zephir_is_true(&_21$$18);
					}
					_22$$18 = _20$$18;
					if (_22$$18) {
						_22$$18 = !hasComponent;
					}
					if (_22$$18) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 701);
						ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_23$$18 = zephir_array_isset(&parameters, &parameterToCheck);
					if (_23$$18) {
						zephir_array_fetch(&_24$$18, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 712);
						_23$$18 = Z_TYPE_P(&_24$$18) == IS_OBJECT;
					}
					_25$$18 = _23$$18;
					if (_25$$18) {
						zephir_array_fetch(&_27$$18, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 713);
						ZEPHIR_CALL_METHOD(&_26$$18, &reflectionClass, "isinstance", NULL, 0, &_27$$18);
						zephir_check_call_status();
						_25$$18 = !zephir_is_true(&_26$$18);
					}
					if (UNEXPECTED(_25$$18)) {
						ZEPHIR_INIT_NVAR(&_28$$21);
						object_init_ex(&_28$$21, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_29$$21);
						zephir_array_fetch(&_30$$21, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 720);
						zephir_get_class(&_29$$21, &_30$$21, 0);
						ZEPHIR_CALL_METHOD(&_31$$21, &reflectionClass, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_32$$21);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_32$$21, "Your passed parameter doesn't have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access, " ", componentName, ". Class passed: ", &_29$$21, " , Class in defined function: ", &_31$$21, ".");
						ZEPHIR_CALL_METHOD(NULL, &_28$$21, "__construct", NULL, 8, &_32$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_28$$21, "phalcon/Acl/Adapter/Memory.zep", 723);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset(&parameters, &parameterToCheck)) {
					zephir_array_fetch(&_33$$22, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 732);
					zephir_array_append(&parametersForFunction, &_33$$22, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 732);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_16$$15, &reflectionParameters, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_16$$15)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reflectionParameter, &reflectionParameters, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionClass, &reflectionParameter, "getclass", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&reflectionClass) != IS_NULL) {
						_34$$24 = Z_TYPE_P(&roleObject) != IS_NULL;
						if (_34$$24) {
							ZEPHIR_CALL_METHOD(&_35$$24, &reflectionClass, "isinstance", NULL, 0, &roleObject);
							zephir_check_call_status();
							_34$$24 = zephir_is_true(&_35$$24);
						}
						_36$$24 = _34$$24;
						if (_36$$24) {
							_36$$24 = !hasRole;
						}
						if (_36$$24) {
							hasRole = 1;
							zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 689);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_37$$24 = Z_TYPE_P(&componentObject) != IS_NULL;
						if (_37$$24) {
							ZEPHIR_CALL_METHOD(&_38$$24, &reflectionClass, "isinstance", NULL, 0, &componentObject);
							zephir_check_call_status();
							_37$$24 = zephir_is_true(&_38$$24);
						}
						_39$$24 = _37$$24;
						if (_39$$24) {
							_39$$24 = !hasComponent;
						}
						if (_39$$24) {
							hasComponent = 1;
							zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 701);
							ZEPHIR_SEPARATE(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_40$$24 = zephir_array_isset(&parameters, &parameterToCheck);
						if (_40$$24) {
							zephir_array_fetch(&_41$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 712);
							_40$$24 = Z_TYPE_P(&_41$$24) == IS_OBJECT;
						}
						_42$$24 = _40$$24;
						if (_42$$24) {
							zephir_array_fetch(&_44$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 713);
							ZEPHIR_CALL_METHOD(&_43$$24, &reflectionClass, "isinstance", NULL, 0, &_44$$24);
							zephir_check_call_status();
							_42$$24 = !zephir_is_true(&_43$$24);
						}
						if (UNEXPECTED(_42$$24)) {
							ZEPHIR_INIT_NVAR(&_45$$27);
							object_init_ex(&_45$$27, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_46$$27);
							zephir_array_fetch(&_47$$27, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 720);
							zephir_get_class(&_46$$27, &_47$$27, 0);
							ZEPHIR_CALL_METHOD(&_48$$27, &reflectionClass, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_49$$27);
							ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_49$$27, "Your passed parameter doesn't have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access, " ", componentName, ". Class passed: ", &_46$$27, " , Class in defined function: ", &_48$$27, ".");
							ZEPHIR_CALL_METHOD(NULL, &_45$$27, "__construct", NULL, 8, &_49$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_45$$27, "phalcon/Acl/Adapter/Memory.zep", 723);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (zephir_array_isset(&parameters, &parameterToCheck)) {
						zephir_array_fetch(&_50$$28, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 732);
						zephir_array_append(&parametersForFunction, &_50$$28, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 732);
					}
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
		if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters)))) {
			ZEPHIR_INIT_VAR(&_51$$29);
			ZEPHIR_CONCAT_SSVSVSVS(&_51$$29, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", roleName, "' can '", &access, "' '", componentName, "'. Extra parameters will be ignored.");
			ZVAL_LONG(&_52$$29, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_51$$29, &_52$$29);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction) == 0) {
			if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
				ZEPHIR_INIT_VAR(&_53$$31);
				ZEPHIR_CONCAT_SVSVSVS(&_53$$31, "You did not provide any parameters when '", roleName, "' can '", &access, "' '", componentName, "'. We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_53$$31);
				zephir_check_call_status();
				_54$$31 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_54$$31) {
					zephir_read_property(&_55$$31, this_ptr, ZEND_STRL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_54$$31 = ZEPHIR_IS_LONG(&_55$$31, 1);
				}
				RETURN_MM_BOOL(_54$$31);
			}
			_56$$30 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_56$$30) {
				ZEPHIR_INIT_VAR(&_57$$30);
				ZEPHIR_CALL_USER_FUNC(&_57$$30, &funcAccess);
				zephir_check_call_status();
				_56$$30 = zephir_is_true(&_57$$30);
			}
			RETURN_MM_BOOL(_56$$30);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
			_58$$32 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_58$$32) {
				ZEPHIR_INIT_VAR(&_59$$32);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_59$$32, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_58$$32 = zephir_is_true(&_59$$32);
			}
			RETURN_MM_BOOL(_58$$32);
		}
		ZEPHIR_INIT_VAR(&_60$$15);
		object_init_ex(&_60$$15, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_61$$15);
		ZEPHIR_CONCAT_SSVSVSVS(&_61$$15, "You did not provide all necessary parameters for the ", "defined function when checking if '", roleName, "' can '", &access, "' for '", componentName, "'.");
		ZEPHIR_CALL_METHOD(NULL, &_60$$15, "__construct", NULL, 8, &_61$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_60$$15, "phalcon/Acl/Adapter/Memory.zep", 777);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(ZEPHIR_IS_LONG(&haveAccess, 1));
}

/**
 * Check whether role exist in the roles list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isRole)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *roleName_param = NULL, _0;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(roleName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);
	zephir_get_strval(&roleName, roleName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &roleName));
}

/**
 * Check whether component exist in the components list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, isComponent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *componentName_param = NULL, _0;
	zval componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(componentName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &componentName_param);
	zephir_get_strval(&componentName, componentName_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &componentName));
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(defaultAccess)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &defaultAccess_param);
	defaultAccess = zephir_get_intval(defaultAccess_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, defaultAccess);
	zephir_update_property_zval(this_ptr, ZEND_STRL("noArgumentsDefaultAction"), &_0);
}

/**
 * Checks if a role has access to a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allowOrDeny)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *roleName_param = NULL, *componentName_param = NULL, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _1, _2, _3, *_4$$3, _5$$3, *_11$$3, _12$$3, _6$$5, _7$$5, _9$$7, _10$$7, _13$$14, _14$$14;
	zval roleName, componentName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);
	ZVAL_UNDEF(&componentName);
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
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(access)
		Z_PARAM_ZVAL(action)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(func)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &roleName_param, &componentName_param, &access, &action, &func);
	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 159, &_0, &roleName, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 159, &_2, &componentName, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_3);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 833);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$3);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", &accessName);
				if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZEPHIR_CONCAT_SVSVS(&_7$$5, "Access '", &accessName, "' does not exist in component '", &componentName, "'");
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_8, 8, &_7$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$5, "phalcon/Acl/Adapter/Memory.zep", 829);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, access, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_5$$3, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_5$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&accessName, access, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&accessKey);
					ZEPHIR_CONCAT_VSV(&accessKey, &componentName, "!", &accessName);
					if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
						ZEPHIR_INIT_NVAR(&_9$$7);
						object_init_ex(&_9$$7, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$7);
						ZEPHIR_CONCAT_SVSVS(&_10$$7, "Access '", &accessName, "' does not exist in component '", &componentName, "'");
						ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 8, &_10$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$7, "phalcon/Acl/Adapter/Memory.zep", 829);
						ZEPHIR_MM_RESTORE();
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 841);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _11$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _11$$3);
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
				ZEPHIR_CALL_METHOD(&_12$$3, access, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$3)) {
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
				ZEPHIR_INIT_VAR(&_13$$14);
				object_init_ex(&_13$$14, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_14$$14);
				ZEPHIR_CONCAT_SVSVS(&_14$$14, "Access '", access, "' does not exist in component '", &componentName, "'");
				ZEPHIR_CALL_METHOD(NULL, &_13$$14, "__construct", &_8, 8, &_14$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$14, "phalcon/Acl/Adapter/Memory.zep", 849);
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
PHP_METHOD(Phalcon_Acl_Adapter_Memory, canAccess)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &roleName_param, &componentName_param, &access_param);
	zephir_get_strval(&roleName, roleName_param);
	zephir_get_strval(&componentName, componentName_param);
	zephir_get_strval(&access, access_param);


	ZEPHIR_OBS_VAR(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &roleName)) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property(&_1$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 910);
		zephir_is_iterable(&_2$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 914);
		if (Z_TYPE_P(&_2$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$6), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _3$$6);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 160, &checkRoleToInherits, &usedRoleToInherit);
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
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 160, &checkRoleToInherits, &usedRoleToInherit);
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
			ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_6, 27, &checkRoleToInherits);
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
			zephir_read_property(&_10$$9, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_10$$9, &checkRoleToInherit)) {
				zephir_read_property(&_11$$14, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_12$$14, &_11$$14, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 957);
				zephir_is_iterable(&_12$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 960);
				if (Z_TYPE_P(&_12$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$14), _13$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _13$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 160, &checkRoleToInherits, &usedRoleToInherit);
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
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 160, &checkRoleToInherits, &usedRoleToInherit);
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

/**
 * @param array  $collection
 * @param string $element
 * @param string $elementName
 * @param string $suffix
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, checkExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element, elementName, suffix, _1$$3;
	zval *collection_param = NULL, *element_param = NULL, *elementName_param = NULL, *suffix_param = NULL, _0$$3;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&elementName);
	ZVAL_UNDEF(&suffix);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_STR(element)
		Z_PARAM_STR(elementName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(suffix)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &collection_param, &element_param, &elementName_param, &suffix_param);
	zephir_get_arrval(&collection, collection_param);
	zephir_get_strval(&element, element_param);
	zephir_get_strval(&elementName, elementName_param);
	if (!suffix_param) {
		ZEPHIR_INIT_VAR(&suffix);
		ZVAL_STRING(&suffix, "ACL");
	} else {
		zephir_get_strval(&suffix, suffix_param);
	}


	if (1 != zephir_array_isset(&collection, &element)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSVSV(&_1$$3, &elementName, " '", &element, "' does not exist in the ", &suffix);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 985);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

