
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
	 * Default action for no arguments is `allow`
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
		ZEPHIR_CALL_METHOD(NULL, &componentObject, "__construct", NULL, 145, componentValue);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&componentName, &componentObject, "getname", NULL, 146);
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
	zval accessKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessName, _0, _1, *_3$$4, _4$$4, _5$$5, _6$$5, _7$$6, _8$$7, _9$$7, _10$$8, _11$$9, _12$$9, _13$$10;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
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
	ZVAL_UNDEF(&accessKey);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	accessList = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 147, &_0, &componentName_zv, &_1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(accessList) != IS_ARRAY;
	if (_2) {
		_2 = Z_TYPE_P(accessList) != IS_STRING;
	}
	if (UNEXPECTED(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Invalid value for the accessList", "phalcon/Acl/Adapter/Memory.zep", 242);
		return;
	}
	exists = 1;
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(accessList, 0, "phalcon/Acl/Adapter/Memory.zep", 255);
		if (Z_TYPE_P(accessList) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(accessList), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _3$$4);
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZEPHIR_CONCAT_VSV(&_5$$5, &componentName_zv, "!", &accessName);
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
					ZEPHIR_CONCAT_VSV(&_8$$7, &componentName_zv, "!", &accessName);
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
		ZEPHIR_CONCAT_VSV(&_11$$9, &componentName_zv, "!", accessList);
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
	zval roleName_zv, *roleToInherits, roleToInherits_sub, __$true, roleInheritName, roleToInherit, checkRoleToInherit, roleToInheritList, usedRoleToInherit, _0, _1, _2, _3, *_5, _6, _4$$3, _8$$6, _9$$6, _10$$6, _14$$6, _11$$10, _12$$10, _15$$12, _16$$12, *_17$$12, _18$$12, _21$$17, _22$$17, _23$$15, _24$$18, _25$$18, *_26$$18, _27$$18, _29$$21, _30$$21, _31$$21, _34$$21, _32$$25, _33$$25, _35$$27, _36$$27, *_37$$27, _38$$27, _39$$32, _40$$32, _41$$30, _42$$33, _43$$33, *_44$$33, _45$$33;
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
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(roleName)
		Z_PARAM_ZVAL(roleToInherits)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	roleToInherits = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "role list");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 147, &_0, &roleName_zv, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_3, &roleName_zv))) {
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
	zephir_is_iterable(&roleToInheritList, 0, "phalcon/Acl/Adapter/Memory.zep", 368);
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
			zephir_array_fetch(&_9$$6, &_8$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 308);
			if (zephir_fast_in_array(&roleInheritName, &_9$$6)) {
				continue;
			}
			zephir_read_property(&_10$$6, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(!(zephir_array_isset(&_10$$6, &roleInheritName)))) {
				ZEPHIR_INIT_NVAR(&_11$$10);
				object_init_ex(&_11$$10, phalcon_acl_exception_ce);
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZEPHIR_CONCAT_SVS(&_12$$10, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
				ZEPHIR_CALL_METHOD(NULL, &_11$$10, "__construct", &_13, 32, &_12$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$10, "phalcon/Acl/Adapter/Memory.zep", 319);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_14$$6, &roleInheritName)) {
				ZEPHIR_INIT_NVAR(&checkRoleToInherits);
				array_init(&checkRoleToInherits);
				zephir_read_property(&_15$$12, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_16$$12, &_15$$12, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 332);
				zephir_is_iterable(&_16$$12, 0, "phalcon/Acl/Adapter/Memory.zep", 336);
				if (Z_TYPE_P(&_16$$12) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_16$$12), _17$$12)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _17$$12);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
					ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_20, 21, &checkRoleToInherits);
					ZEPHIR_UNREF(&checkRoleToInherits);
					zephir_check_call_status();
					if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
						continue;
					}
					zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
						ZEPHIR_INIT_NVAR(&_21$$17);
						object_init_ex(&_21$$17, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_22$$17);
						ZEPHIR_CONCAT_SVS(&_22$$17, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
						ZEPHIR_CALL_METHOD(NULL, &_21$$17, "__construct", &_13, 32, &_22$$17);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_21$$17, "phalcon/Acl/Adapter/Memory.zep", 351);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_read_property(&_23$$15, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					if (zephir_array_isset(&_23$$15, &checkRoleToInherit)) {
						zephir_read_property(&_24$$18, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						zephir_array_fetch(&_25$$18, &_24$$18, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 358);
						zephir_is_iterable(&_25$$18, 0, "phalcon/Acl/Adapter/Memory.zep", 361);
						if (Z_TYPE_P(&_25$$18) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_25$$18), _26$$18)
							{
								ZEPHIR_INIT_NVAR(&usedRoleToInherit);
								ZVAL_COPY(&usedRoleToInherit, _26$$18);
								ZEPHIR_MAKE_REF(&checkRoleToInherits);
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
			zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
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
				zephir_array_fetch(&_30$$21, &_29$$21, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 308);
				if (zephir_fast_in_array(&roleInheritName, &_30$$21)) {
					continue;
				}
				zephir_read_property(&_31$$21, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(!(zephir_array_isset(&_31$$21, &roleInheritName)))) {
					ZEPHIR_INIT_NVAR(&_32$$25);
					object_init_ex(&_32$$25, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_33$$25);
					ZEPHIR_CONCAT_SVS(&_33$$25, "Role '", &roleInheritName, "' (to inherit) does not exist in the role list");
					ZEPHIR_CALL_METHOD(NULL, &_32$$25, "__construct", &_13, 32, &_33$$25);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$25, "phalcon/Acl/Adapter/Memory.zep", 319);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_EQUAL(&roleName_zv, &roleInheritName)) {
					RETURN_MM_BOOL(0);
				}
				zephir_read_property(&_34$$21, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_34$$21, &roleInheritName)) {
					ZEPHIR_INIT_NVAR(&checkRoleToInherits);
					array_init(&checkRoleToInherits);
					zephir_read_property(&_35$$27, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_36$$27, &_35$$27, &roleInheritName, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 332);
					zephir_is_iterable(&_36$$27, 0, "phalcon/Acl/Adapter/Memory.zep", 336);
					if (Z_TYPE_P(&_36$$27) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_36$$27), _37$$27)
						{
							ZEPHIR_INIT_NVAR(&usedRoleToInherit);
							ZVAL_COPY(&usedRoleToInherit, _37$$27);
							ZEPHIR_MAKE_REF(&checkRoleToInherits);
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
								ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
						ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_20, 21, &checkRoleToInherits);
						ZEPHIR_UNREF(&checkRoleToInherits);
						zephir_check_call_status();
						if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
							continue;
						}
						zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(ZEPHIR_IS_EQUAL(&roleName_zv, &checkRoleToInherit))) {
							ZEPHIR_INIT_NVAR(&_39$$32);
							object_init_ex(&_39$$32, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_40$$32);
							ZEPHIR_CONCAT_SVS(&_40$$32, "Role '", &roleInheritName, "' (to inherit) produces an infinite loop");
							ZEPHIR_CALL_METHOD(NULL, &_39$$32, "__construct", &_13, 32, &_40$$32);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_39$$32, "phalcon/Acl/Adapter/Memory.zep", 351);
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_read_property(&_41$$30, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
						if (zephir_array_isset(&_41$$30, &checkRoleToInherit)) {
							zephir_read_property(&_42$$33, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
							zephir_array_fetch(&_43$$33, &_42$$33, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 358);
							zephir_is_iterable(&_43$$33, 0, "phalcon/Acl/Adapter/Memory.zep", 361);
							if (Z_TYPE_P(&_43$$33) == IS_ARRAY) {
								ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_43$$33), _44$$33)
								{
									ZEPHIR_INIT_NVAR(&usedRoleToInherit);
									ZVAL_COPY(&usedRoleToInherit, _44$$33);
									ZEPHIR_MAKE_REF(&checkRoleToInherits);
									ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
										ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_19, 148, &checkRoleToInherits, &usedRoleToInherit);
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
				zephir_update_property_array_multi(this_ptr, SL("roleInherits"), &roleInheritName, SL("za"), 2, &roleName_zv);
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
		ZEPHIR_CALL_METHOD(NULL, &roleObject, "__construct", NULL, 149, role);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_acl_exception_ce, "Role must be either a string or implement RoleInterface", "phalcon/Acl/Adapter/Memory.zep", 395);
		return;
	}
	ZEPHIR_CALL_METHOD(&roleName, &roleObject, "getname", NULL, 150);
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
 * ```
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, allow)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, _1$$3, _4$$4, _6$$5;
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
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
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
	ZVAL_STR_COPY(&roleName_zv, roleName);
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
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 448);
	if (Z_TYPE_P(&rolesArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
		{
			ZEPHIR_INIT_NVAR(&role);
			ZVAL_COPY(&role, _2);
			ZVAL_LONG(&_4$$4, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 151, &role, &componentName_zv, access, &_4$$4, func);
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
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 151, &role, &componentName_zv, access, &_6$$5, func);
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
	zval roleName_zv, componentName_zv, *access, access_sub, *func = NULL, func_sub, __$null, role, rolesArray, _0, *_2, _3, _1$$3, _4$$4, _6$$5;
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
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
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
	ZVAL_STR_COPY(&roleName_zv, roleName);
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
	zephir_is_iterable(&rolesArray, 0, "phalcon/Acl/Adapter/Memory.zep", 485);
	if (Z_TYPE_P(&rolesArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rolesArray), _2)
		{
			ZEPHIR_INIT_NVAR(&role);
			ZVAL_COPY(&role, _2);
			ZVAL_LONG(&_4$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 151, &role, &componentName_zv, access, &_4$$4, func);
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
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "allowordeny", &_5, 151, &role, &componentName_zv, access, &_6$$5, func);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &rolesArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&role);
	ZEPHIR_MM_RESTORE();
}

/**
 * Removes access from a component
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, dropComponentAccess)
{
	zval localAccess;
	zval accessKey;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval componentName_zv, *accessList, accessList_sub, accessName, _0$$3, *_1$$5, _2$$5, _3$$6, _4$$6, _5$$7, _6$$8, _7$$8, _8$$9;
	zend_string *componentName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&componentName_zv);
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
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&localAccess);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(componentName)
		Z_PARAM_ZVAL(accessList)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	accessList = ZEND_CALL_ARG(execute_data, 2);
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
	if (Z_TYPE_P(accessList) == IS_ARRAY) {
		zephir_is_iterable(&localAccess, 0, "phalcon/Acl/Adapter/Memory.zep", 510);
		if (Z_TYPE_P(&localAccess) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&localAccess), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _1$$5);
				ZEPHIR_INIT_NVAR(&_3$$6);
				ZEPHIR_CONCAT_VSV(&_3$$6, &componentName_zv, "!", &accessName);
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
					ZEPHIR_CONCAT_VSV(&_6$$8, &componentName_zv, "!", &accessName);
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

	RETURN_MEMBER(getThis(), "activeFunctionCustomArgumentsCount");
}

/**
 * Returns the latest key used to acquire access
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
		ZVAL_STR(&roleName_zv, roleName);
	} else {
		ZVAL_STR_COPY(&roleName_zv, roleName);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &roleName_zv)) {
		RETURN_MM_MEMBER(getThis(), "roleInherits");
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

	RETURN_MEMBER(getThis(), "noArgumentsDefaultAction");
}

/**
 * Return an array with every role registered in the list
 */
PHP_METHOD(Phalcon_Acl_Adapter_Memory, getRoles)
{

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
	zval _2$$6, _5$$10;
	zend_bool hasComponent, hasRole, _10, _13$$16, _17$$17, _19$$18, _22$$18, _23$$18, _25$$18, _26$$18, _28$$18, _38$$23, _39$$24, _41$$24, _42$$24, _44$$24, _45$$24, _47$$24, _59$$31, _61$$30, _63$$32;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_18 = NULL, *_21 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zend_string *access = NULL;
	zval *roleName = NULL, roleName_sub, *componentName = NULL, componentName_sub, access_zv, *parameters_param = NULL, __$null, accessKey, accessList, className, componentObject, haveAccess, funcAccess, funcList, numberOfRequiredParameters, parameterNumber, parameterToCheck, parametersForFunction, reflectionClass, reflectionFunction, reflectionParameter, reflectionParameters, reflectionType, roleObject, userParametersSizeShouldBe, _6, _7, _8, _0$$5, _1$$6, _3$$9, _4$$10, _9$$12, _11$$14, _12$$14, _14$$16, *_15$$15, _16$$15, _65$$15, _66$$15, _20$$18, _24$$18, _27$$18, _29$$18, _30$$18, _31$$21, _32$$21, _33$$21, _34$$21, _36$$21, _37$$22, _40$$24, _43$$24, _46$$24, _48$$24, _49$$24, _50$$27, _51$$27, _52$$27, _53$$27, _54$$27, _55$$28, _56$$29, _57$$29, _58$$31, _60$$31, _62$$30, _64$$32;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName_sub);
	ZVAL_UNDEF(&componentName_sub);
	ZVAL_UNDEF(&access_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&accessKey);
	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&componentObject);
	ZVAL_UNDEF(&haveAccess);
	ZVAL_UNDEF(&funcAccess);
	ZVAL_UNDEF(&funcList);
	ZVAL_UNDEF(&numberOfRequiredParameters);
	ZVAL_UNDEF(&parameterNumber);
	ZVAL_UNDEF(&parameterToCheck);
	ZVAL_UNDEF(&parametersForFunction);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&reflectionFunction);
	ZVAL_UNDEF(&reflectionParameter);
	ZVAL_UNDEF(&reflectionParameters);
	ZVAL_UNDEF(&reflectionType);
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
	ZVAL_UNDEF(&_65$$15);
	ZVAL_UNDEF(&_66$$15);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_43$$24);
	ZVAL_UNDEF(&_46$$24);
	ZVAL_UNDEF(&_48$$24);
	ZVAL_UNDEF(&_49$$24);
	ZVAL_UNDEF(&_50$$27);
	ZVAL_UNDEF(&_51$$27);
	ZVAL_UNDEF(&_52$$27);
	ZVAL_UNDEF(&_53$$27);
	ZVAL_UNDEF(&_54$$27);
	ZVAL_UNDEF(&_55$$28);
	ZVAL_UNDEF(&_56$$29);
	ZVAL_UNDEF(&_57$$29);
	ZVAL_UNDEF(&_58$$31);
	ZVAL_UNDEF(&_60$$31);
	ZVAL_UNDEF(&_62$$30);
	ZVAL_UNDEF(&_64$$32);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_5$$10);
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
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 32, &_2$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "phalcon/Acl/Adapter/Memory.zep", 615);
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
			ZEPHIR_CALL_METHOD(NULL, &_4$$10, "__construct", NULL, 32, &_5$$10);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$10, "phalcon/Acl/Adapter/Memory.zep", 629);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRole"), roleName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeComponent"), componentName);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), &access_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &__$null);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunction"), &__$null);
	zephir_memory_observe(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	zephir_memory_observe(&funcList);
	zephir_read_property(&funcList, this_ptr, ZEND_STRL("func"), PH_NOISY_CC);
	ZVAL_UNDEF(&_6);
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
	ZEPHIR_CALL_METHOD(&accessKey, this_ptr, "canaccess", NULL, 152, roleName, componentName, &access_zv);
	zephir_check_call_status();
	_10 = Z_TYPE_P(&accessKey) != IS_NULL;
	if (_10) {
		_10 = zephir_array_isset(&accessList, &accessKey);
	}
	if (_10) {
		ZEPHIR_OBS_NVAR(&haveAccess);
		zephir_array_fetch(&haveAccess, &accessList, &accessKey, PH_NOISY, "phalcon/Acl/Adapter/Memory.zep", 661);
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
		ZEPHIR_CONCAT_VSVSV(&_11$$14, roleName, "!", componentName, "!", &access_zv);
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeKey"), &_11$$14);
		zephir_read_property(&_12$$14, this_ptr, ZEND_STRL("defaultAccess"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(ZEPHIR_IS_LONG(&_12$$14, 1));
	}
	if (zephir_is_callable(&funcAccess)) {
		ZEPHIR_INIT_VAR(&reflectionFunction);
		object_init_ex(&reflectionFunction, zephir_get_internal_ce(SL("reflectionfunction")));
		ZEPHIR_CALL_METHOD(NULL, &reflectionFunction, "__construct", NULL, 153, &funcAccess);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&reflectionParameters, &reflectionFunction, "getparameters", NULL, 154);
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
		ZEPHIR_CALL_METHOD(&numberOfRequiredParameters, &reflectionFunction, "getnumberofrequiredparameters", NULL, 155);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&userParametersSizeShouldBe, &parameterNumber);
		zephir_is_iterable(&reflectionParameters, 0, "phalcon/Acl/Adapter/Memory.zep", 768);
		if (Z_TYPE_P(&reflectionParameters) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&reflectionParameters), _15$$15)
			{
				ZEPHIR_INIT_NVAR(&reflectionParameter);
				ZVAL_COPY(&reflectionParameter, _15$$15);
				ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
				zephir_check_call_status();
				_17$$17 = Z_TYPE_P(&reflectionType) != IS_NULL;
				if (_17$$17) {
					_17$$17 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
				}
				if (_17$$17) {
					ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&reflectionClass);
					object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
					ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_18, 156, &className);
					zephir_check_call_status();
					_19$$18 = Z_TYPE_P(&roleObject) != IS_NULL;
					if (_19$$18) {
						ZEPHIR_CALL_METHOD(&_20$$18, &reflectionClass, "isinstance", &_21, 157, &roleObject);
						zephir_check_call_status();
						_19$$18 = zephir_is_true(&_20$$18);
					}
					_22$$18 = _19$$18;
					if (_22$$18) {
						_22$$18 = !hasRole;
					}
					if (_22$$18) {
						hasRole = 1;
						zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 721);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_23$$18 = Z_TYPE_P(&componentObject) != IS_NULL;
					if (_23$$18) {
						ZEPHIR_CALL_METHOD(&_24$$18, &reflectionClass, "isinstance", &_21, 157, &componentObject);
						zephir_check_call_status();
						_23$$18 = zephir_is_true(&_24$$18);
					}
					_25$$18 = _23$$18;
					if (_25$$18) {
						_25$$18 = !hasComponent;
					}
					if (_25$$18) {
						hasComponent = 1;
						zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 733);
						SEPARATE_ZVAL(&userParametersSizeShouldBe);
						zephir_decrement(&userParametersSizeShouldBe);
						continue;
					}
					_26$$18 = zephir_array_isset(&parameters, &parameterToCheck);
					if (_26$$18) {
						zephir_array_fetch(&_27$$18, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 744);
						_26$$18 = Z_TYPE_P(&_27$$18) == IS_OBJECT;
					}
					_28$$18 = _26$$18;
					if (_28$$18) {
						zephir_array_fetch(&_30$$18, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 745);
						ZEPHIR_CALL_METHOD(&_29$$18, &reflectionClass, "isinstance", &_21, 157, &_30$$18);
						zephir_check_call_status();
						_28$$18 = !zephir_is_true(&_29$$18);
					}
					if (UNEXPECTED(_28$$18)) {
						ZEPHIR_INIT_NVAR(&_31$$21);
						object_init_ex(&_31$$21, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_32$$21);
						zephir_array_fetch(&_33$$21, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 752);
						zephir_get_class(&_32$$21, &_33$$21, 0);
						ZEPHIR_CALL_METHOD(&_34$$21, &reflectionClass, "getname", &_35, 158);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_36$$21);
						ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_36$$21, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access_zv, " ", componentName, ". Class passed: ", &_32$$21, " , Class in defined function: ", &_34$$21, ".");
						ZEPHIR_CALL_METHOD(NULL, &_31$$21, "__construct", NULL, 32, &_36$$21);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_31$$21, "phalcon/Acl/Adapter/Memory.zep", 755);
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_array_isset(&parameters, &parameterToCheck)) {
					zephir_array_fetch(&_37$$22, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 764);
					zephir_array_append(&parametersForFunction, &_37$$22, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 764);
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
					ZEPHIR_CALL_METHOD(&reflectionType, &reflectionParameter, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&parameterToCheck, &reflectionParameter, "getname", NULL, 0);
					zephir_check_call_status();
					_38$$23 = Z_TYPE_P(&reflectionType) != IS_NULL;
					if (_38$$23) {
						_38$$23 = (zephir_is_instance_of(&reflectionType, SL("ReflectionNamedType")));
					}
					if (_38$$23) {
						ZEPHIR_CALL_METHOD(&className, &reflectionType, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&reflectionClass);
						object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
						ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", &_18, 156, &className);
						zephir_check_call_status();
						_39$$24 = Z_TYPE_P(&roleObject) != IS_NULL;
						if (_39$$24) {
							ZEPHIR_CALL_METHOD(&_40$$24, &reflectionClass, "isinstance", &_21, 157, &roleObject);
							zephir_check_call_status();
							_39$$24 = zephir_is_true(&_40$$24);
						}
						_41$$24 = _39$$24;
						if (_41$$24) {
							_41$$24 = !hasRole;
						}
						if (_41$$24) {
							hasRole = 1;
							zephir_array_append(&parametersForFunction, &roleObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 721);
							SEPARATE_ZVAL(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_42$$24 = Z_TYPE_P(&componentObject) != IS_NULL;
						if (_42$$24) {
							ZEPHIR_CALL_METHOD(&_43$$24, &reflectionClass, "isinstance", &_21, 157, &componentObject);
							zephir_check_call_status();
							_42$$24 = zephir_is_true(&_43$$24);
						}
						_44$$24 = _42$$24;
						if (_44$$24) {
							_44$$24 = !hasComponent;
						}
						if (_44$$24) {
							hasComponent = 1;
							zephir_array_append(&parametersForFunction, &componentObject, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 733);
							SEPARATE_ZVAL(&userParametersSizeShouldBe);
							zephir_decrement(&userParametersSizeShouldBe);
							continue;
						}
						_45$$24 = zephir_array_isset(&parameters, &parameterToCheck);
						if (_45$$24) {
							zephir_array_fetch(&_46$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 744);
							_45$$24 = Z_TYPE_P(&_46$$24) == IS_OBJECT;
						}
						_47$$24 = _45$$24;
						if (_47$$24) {
							zephir_array_fetch(&_49$$24, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 745);
							ZEPHIR_CALL_METHOD(&_48$$24, &reflectionClass, "isinstance", &_21, 157, &_49$$24);
							zephir_check_call_status();
							_47$$24 = !zephir_is_true(&_48$$24);
						}
						if (UNEXPECTED(_47$$24)) {
							ZEPHIR_INIT_NVAR(&_50$$27);
							object_init_ex(&_50$$27, phalcon_acl_exception_ce);
							ZEPHIR_INIT_NVAR(&_51$$27);
							zephir_array_fetch(&_52$$27, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 752);
							zephir_get_class(&_51$$27, &_52$$27, 0);
							ZEPHIR_CALL_METHOD(&_53$$27, &reflectionClass, "getname", &_35, 158);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_54$$27);
							ZEPHIR_CONCAT_SSSVSVSVSVSVS(&_54$$27, "Your passed parameter does not have the ", "same class as the parameter in defined function ", "when checking if ", roleName, " can ", &access_zv, " ", componentName, ". Class passed: ", &_51$$27, " , Class in defined function: ", &_53$$27, ".");
							ZEPHIR_CALL_METHOD(NULL, &_50$$27, "__construct", NULL, 32, &_54$$27);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_50$$27, "phalcon/Acl/Adapter/Memory.zep", 755);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					if (zephir_array_isset(&parameters, &parameterToCheck)) {
						zephir_array_fetch(&_55$$28, &parameters, &parameterToCheck, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 764);
						zephir_array_append(&parametersForFunction, &_55$$28, PH_SEPARATE, "phalcon/Acl/Adapter/Memory.zep", 764);
					}
				ZEPHIR_CALL_METHOD(NULL, &reflectionParameters, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reflectionParameter);
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeFunctionCustomArgumentsCount"), &userParametersSizeShouldBe);
		if (UNEXPECTED(ZEPHIR_LT_LONG(&userParametersSizeShouldBe, zephir_fast_count_int(&parameters)))) {
			ZEPHIR_INIT_VAR(&_56$$29);
			ZEPHIR_CONCAT_SSVSVSVS(&_56$$29, "Number of parameters in array is higher than ", "the number of parameters in defined function when checking if '", roleName, "' can '", &access_zv, "' '", componentName, "'. Extra parameters will be ignored.");
			ZVAL_LONG(&_57$$29, 512);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 9, &_56$$29, &_57$$29);
			zephir_check_call_status();
		}
		if (zephir_fast_count_int(&parametersForFunction) == 0) {
			if (UNEXPECTED(ZEPHIR_GT_LONG(&numberOfRequiredParameters, 0))) {
				ZEPHIR_INIT_VAR(&_58$$31);
				ZEPHIR_CONCAT_SVSVSVS(&_58$$31, "You did not provide any parameters when '", roleName, "' can '", &access_zv, "' '", componentName, "'. We will use default action when no arguments.");
				ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 9, &_58$$31);
				zephir_check_call_status();
				_59$$31 = ZEPHIR_IS_LONG(&haveAccess, 1);
				if (_59$$31) {
					zephir_read_property(&_60$$31, this_ptr, ZEND_STRL("noArgumentsDefaultAction"), PH_NOISY_CC | PH_READONLY);
					_59$$31 = ZEPHIR_IS_LONG(&_60$$31, 1);
				}
				RETURN_MM_BOOL(_59$$31);
			}
			_61$$30 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_61$$30) {
				ZEPHIR_INIT_VAR(&_62$$30);
				ZEPHIR_CALL_USER_FUNC(&_62$$30, &funcAccess);
				zephir_check_call_status();
				_61$$30 = zephir_is_true(&_62$$30);
			}
			RETURN_MM_BOOL(_61$$30);
		}
		if (ZEPHIR_LE_LONG(&numberOfRequiredParameters, zephir_fast_count_int(&parametersForFunction))) {
			_63$$32 = ZEPHIR_IS_LONG(&haveAccess, 1);
			if (_63$$32) {
				ZEPHIR_INIT_VAR(&_64$$32);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_64$$32, &funcAccess, &parametersForFunction);
				zephir_check_call_status();
				_63$$32 = zephir_is_true(&_64$$32);
			}
			RETURN_MM_BOOL(_63$$32);
		}
		ZEPHIR_INIT_VAR(&_65$$15);
		object_init_ex(&_65$$15, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_66$$15);
		ZEPHIR_CONCAT_SSVSVSVS(&_66$$15, "You did not provide all necessary parameters for the ", "defined function when checking if '", roleName, "' can '", &access_zv, "' for '", componentName, "'.");
		ZEPHIR_CALL_METHOD(NULL, &_65$$15, "__construct", NULL, 32, &_66$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_65$$15, "phalcon/Acl/Adapter/Memory.zep", 809);
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
	RETURN_BOOL(zephir_array_isset(&_0, &roleName_zv));
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
	RETURN_BOOL(zephir_array_isset(&_0, &componentName_zv));
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, *access, access_sub, *action, action_sub, *func = NULL, func_sub, __$null, accessList, accessName, accessKey, _0, _1, _2, _3, *_4$$3, _5$$3, *_11$$3, _12$$3, _6$$5, _7$$5, _9$$7, _10$$7, _13$$14, _14$$14;
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
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
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
	ZVAL_STR_COPY(&roleName_zv, roleName);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	if (!func) {
		func = &func_sub;
		func = &__$null;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roles"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Role");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 147, &_0, &roleName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("componentsNames"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Component");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkexists", NULL, 147, &_2, &componentName_zv, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("accessList"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&accessList, &_3);
	if (Z_TYPE_P(access) == IS_ARRAY) {
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 865);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _4$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _4$$3);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSV(&accessKey, &componentName_zv, "!", &accessName);
				if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_acl_exception_ce);
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZEPHIR_CONCAT_SVSVS(&_7$$5, "Access '", &accessName, "' does not exist in component '", &componentName_zv, "'");
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_8, 32, &_7$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$5, "phalcon/Acl/Adapter/Memory.zep", 861);
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
					ZEPHIR_CONCAT_VSV(&accessKey, &componentName_zv, "!", &accessName);
					if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
						ZEPHIR_INIT_NVAR(&_9$$7);
						object_init_ex(&_9$$7, phalcon_acl_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$7);
						ZEPHIR_CONCAT_SVSVS(&_10$$7, "Access '", &accessName, "' does not exist in component '", &componentName_zv, "'");
						ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 32, &_10$$7);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$7, "phalcon/Acl/Adapter/Memory.zep", 861);
						ZEPHIR_MM_RESTORE();
						return;
					}
				ZEPHIR_CALL_METHOD(NULL, access, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&accessName);
		zephir_is_iterable(access, 0, "phalcon/Acl/Adapter/Memory.zep", 873);
		if (Z_TYPE_P(access) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(access), _11$$3)
			{
				ZEPHIR_INIT_NVAR(&accessName);
				ZVAL_COPY(&accessName, _11$$3);
				ZEPHIR_INIT_NVAR(&accessKey);
				ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName_zv, "!", &componentName_zv, "!", &accessName);
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
					ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName_zv, "!", &componentName_zv, "!", &accessName);
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
			ZEPHIR_CONCAT_VSV(&accessKey, &componentName_zv, "!", access);
			if (UNEXPECTED(!(zephir_array_isset(&accessList, &accessKey)))) {
				ZEPHIR_INIT_VAR(&_13$$14);
				object_init_ex(&_13$$14, phalcon_acl_exception_ce);
				ZEPHIR_INIT_VAR(&_14$$14);
				ZEPHIR_CONCAT_SVSVS(&_14$$14, "Access '", access, "' does not exist in component '", &componentName_zv, "'");
				ZEPHIR_CALL_METHOD(NULL, &_13$$14, "__construct", &_8, 32, &_14$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_13$$14, "phalcon/Acl/Adapter/Memory.zep", 881);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_NVAR(&accessKey);
		ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName_zv, "!", &componentName_zv, "!", access);
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
	zval accessKey;
	zval usedRoleToInherits, checkRoleToInherits;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval roleName_zv, componentName_zv, access_zv, __$true, accessList, checkRoleToInherit, usedRoleToInherit, _0, _1$$6, _2$$6, *_3$$6, _4$$6, _7$$9, _8$$9, _9$$9, _10$$9, _11$$14, _12$$14, *_13$$14, _14$$14;
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
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&usedRoleToInherits);
	ZVAL_UNDEF(&checkRoleToInherits);
	ZVAL_UNDEF(&accessKey);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(roleName)
		Z_PARAM_STR(componentName)
		Z_PARAM_STR(access)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&roleName_zv, roleName);
	ZVAL_STR_COPY(&componentName_zv, componentName);
	ZVAL_STR_COPY(&access_zv, access);
	zephir_memory_observe(&accessList);
	zephir_read_property(&accessList, this_ptr, ZEND_STRL("access"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&accessKey);
	ZEPHIR_CONCAT_VSVSV(&accessKey, &roleName_zv, "!", &componentName_zv, "!", &access_zv);
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VSVS(&accessKey, &roleName_zv, "!", &componentName_zv, "!*");
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	ZEPHIR_INIT_NVAR(&accessKey);
	ZEPHIR_CONCAT_VS(&accessKey, &roleName_zv, "!*!*");
	if (zephir_array_isset(&accessList, &accessKey)) {
		RETURN_CTOR(&accessKey);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &roleName_zv)) {
		ZEPHIR_INIT_VAR(&checkRoleToInherits);
		array_init(&checkRoleToInherits);
		zephir_read_property(&_1$$6, this_ptr, ZEND_STRL("roleInherits"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$6, &_1$$6, &roleName_zv, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 942);
		zephir_is_iterable(&_2$$6, 0, "phalcon/Acl/Adapter/Memory.zep", 946);
		if (Z_TYPE_P(&_2$$6) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$6), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&usedRoleToInherit);
				ZVAL_COPY(&usedRoleToInherit, _3$$6);
				ZEPHIR_MAKE_REF(&checkRoleToInherits);
				ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 148, &checkRoleToInherits, &usedRoleToInherit);
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
					ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 148, &checkRoleToInherits, &usedRoleToInherit);
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
			ZEPHIR_CALL_FUNCTION(&checkRoleToInherit, "array_shift", &_6, 21, &checkRoleToInherits);
			ZEPHIR_UNREF(&checkRoleToInherits);
			zephir_check_call_status();
			if (zephir_array_isset(&usedRoleToInherits, &checkRoleToInherit)) {
				continue;
			}
			zephir_array_update_zval(&usedRoleToInherits, &checkRoleToInherit, &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_7$$9);
			ZEPHIR_CONCAT_VSVSV(&_7$$9, &checkRoleToInherit, "!", &componentName_zv, "!", &access_zv);
			zephir_get_strval(&accessKey, &_7$$9);
			if (zephir_array_isset(&accessList, &accessKey)) {
				RETURN_CTOR(&accessKey);
			}
			ZEPHIR_INIT_NVAR(&_8$$9);
			ZEPHIR_CONCAT_VSVS(&_8$$9, &checkRoleToInherit, "!", &componentName_zv, "!*");
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
				zephir_array_fetch(&_12$$14, &_11$$14, &checkRoleToInherit, PH_NOISY | PH_READONLY, "phalcon/Acl/Adapter/Memory.zep", 989);
				zephir_is_iterable(&_12$$14, 0, "phalcon/Acl/Adapter/Memory.zep", 992);
				if (Z_TYPE_P(&_12$$14) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$14), _13$$14)
					{
						ZEPHIR_INIT_NVAR(&usedRoleToInherit);
						ZVAL_COPY(&usedRoleToInherit, _13$$14);
						ZEPHIR_MAKE_REF(&checkRoleToInherits);
						ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 148, &checkRoleToInherits, &usedRoleToInherit);
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
							ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_5, 148, &checkRoleToInherits, &usedRoleToInherit);
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
	ZVAL_STR_COPY(&element_zv, element);
	ZVAL_STR_COPY(&elementName_zv, elementName);
	if (!suffix) {
		suffix = zend_string_init(ZEND_STRL("ACL"), 0);
		ZVAL_STR(&suffix_zv, suffix);
	} else {
		ZVAL_STR_COPY(&suffix_zv, suffix);
	}
	if (1 != zephir_array_isset(&collection, &element_zv)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_acl_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSVSV(&_1$$3, &elementName_zv, " '", &element_zv, "' does not exist in the ", &suffix_zv);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 32, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Acl/Adapter/Memory.zep", 1017);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

