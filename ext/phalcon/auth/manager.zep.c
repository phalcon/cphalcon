
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/main.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Composes guards (authentication) and access gates (authorization)
 * behind a single facade. Guard-specific behavior is reached through
 * Manager::guard(); callers narrow with instanceof against the
 * relevant capability interface (GuardStateful, BasicAuth, etc.).
 *
 * @phpstan-import-type AuthCredentials from Adapter
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, Manager, phalcon, auth_manager, phalcon_auth_manager_method_entry, 0);

	/**
	 * @var AccessLocator
	 */
	zend_declare_property_null(phalcon_auth_manager_ce, SL("accessFactory"), ZEND_ACC_PROTECTED);
	/**
	 * @var Access | null
	 */
	zend_declare_property_null(phalcon_auth_manager_ce, SL("activeAccess"), ZEND_ACC_PROTECTED);
	/**
	 * @var Guard | null
	 */
	zend_declare_property_null(phalcon_auth_manager_ce, SL("defaultGuard"), ZEND_ACC_PROTECTED);
	/**
	 * @var array<string, Guard>
	 */
	zend_declare_property_null(phalcon_auth_manager_ce, SL("guards"), ZEND_ACC_PROTECTED);
	phalcon_auth_manager_ce->create_object = zephir_init_properties_Phalcon_Auth_Manager;

	zend_class_implements(phalcon_auth_manager_ce, 1, phalcon_contracts_auth_manager_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Manager, __construct)
{
	zval *accessFactory, accessFactory_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessFactory_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(accessFactory, phalcon_auth_access_accesslocator_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &accessFactory);
	zephir_update_property_zval(this_ptr, ZEND_STRL("accessFactory"), accessFactory);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Manager, access)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval accessName_zv, _0, _1, _5, _6, _2$$3, _3$$3, _4$$3;
	zend_string *accessName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(accessName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&accessName_zv);
	ZVAL_STR_COPY(&accessName_zv, accessName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("accessFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &accessName_zv);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Access '%s' is not registered");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 129, &_3$$3, &accessName_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 8, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Auth/Manager.zep", 66);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("accessFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, &_5, "newinstance", NULL, 0, &accessName_zv);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), &_6);
	RETURN_THIS();
}

/**
 * @phpstan-param array<string, class-string<Access>> $accessList
 */
PHP_METHOD(Phalcon_Auth_Manager, addAccessList)
{
	zend_bool _5;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *accessList_param = NULL, className, name, *_0, _4, _3$$3, _6$$4;
	zval accessList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&accessList);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(accessList, accessList_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &accessList_param);
	zephir_get_arrval(&accessList, accessList_param);
	zephir_is_iterable(&accessList, 0, "phalcon/Auth/Manager.zep", 85);
	if (Z_TYPE_P(&accessList) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&accessList), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&name, _2);
			} else {
				ZVAL_LONG(&name, _1);
			}
			ZEPHIR_INIT_NVAR(&className);
			ZVAL_COPY(&className, _0);
			zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("accessFactory"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "register", NULL, 0, &name, &className);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &accessList, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &accessList, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &accessList, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &accessList, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&className, &accessList, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_6$$4, this_ptr, ZEND_STRL("accessFactory"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_6$$4, "register", NULL, 0, &name, &className);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&className);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, addGuard)
{
	zend_bool isDefault;
	zval nameGuard_zv, *guard, guard_sub, *isDefault_param = NULL;
	zend_string *nameGuard = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nameGuard_zv);
	ZVAL_UNDEF(&guard_sub);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(nameGuard)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(isDefault)
	ZEND_PARSE_PARAMETERS_END();
	guard = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		isDefault_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR(&nameGuard_zv, nameGuard);
	if (!isDefault_param) {
		isDefault = 0;
	} else {
		}
	zephir_update_property_array(this_ptr, SL("guards"), &nameGuard_zv, guard);
	if (isDefault) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultGuard"), guard);
	}
	RETURN_THISW();
}

/**
 * @phpstan-param AuthCredentials $credentials
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Manager, attempt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *credentials_param = NULL, *remember_param = NULL, guard, _3, _0$$3, _1$$3, _2$$3;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &credentials_param, &remember_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	if (!remember_param) {
		remember = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&guard, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(&guard, phalcon_contracts_auth_guard_guardstateful_ce))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_doesnotimplement_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Default guard");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "GuardStateful");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 143, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Manager.zep", 114);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (remember) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(&guard, "attempt", NULL, 0, &credentials, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, check)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "check", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Manager, except)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval actions, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, -1)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZEPHIR_INIT_VAR(&actions);
	zephir_get_args_from(&actions, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_auth_exception_ce, "No active access - call access() first", "phalcon/Auth/Manager.zep", 131);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 28, &actions);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setexceptactions", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, getAccess)
{

	RETURN_MEMBER(getThis(), "activeAccess");
}

/**
 * @return array<string, class-string<Access>>
 */
PHP_METHOD(Phalcon_Auth_Manager, getAccessList)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("accessFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getall", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, getDefaultGuard)
{

	RETURN_MEMBER(getThis(), "defaultGuard");
}

/**
 * @return array<string, Guard>
 */
PHP_METHOD(Phalcon_Auth_Manager, getGuards)
{

	RETURN_MEMBER_TYPED(getThis(), "guards", IS_ARRAY);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Manager, guard)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0$$3, _1, _5, _6, _2$$5, _3$$5, _4$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		ZEPHIR_INIT_VAR(&name_zv);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	if (ZEPHIR_IS_NULL(&name_zv)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("defaultGuard"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$3) == IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_auth_exception_ce, "No default guard registered", "phalcon/Auth/Manager.zep", 172);
			return;
		}
		RETURN_MM_MEMBER(getThis(), "defaultGuard");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_1, &name_zv))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "Auth guard '%s' is not defined");
		ZEPHIR_CALL_FUNCTION(&_4$$5, "sprintf", NULL, 129, &_3$$5, &name_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 8, &_4$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Auth/Manager.zep", 181);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Auth/Manager.zep", 184);
	RETURN_CTOR(&_6);
}

PHP_METHOD(Phalcon_Auth_Manager, id)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "id", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Manager, logout)
{
	zval guard, _0$$3, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&guard, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(&guard, phalcon_contracts_auth_guard_guardstateful_ce))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_doesnotimplement_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Default guard");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "GuardStateful");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 143, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Manager.zep", 199);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, &guard, "logout", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Manager, only)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval actions, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, -1)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZEPHIR_INIT_VAR(&actions);
	zephir_get_args_from(&actions, 0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_auth_exception_ce, "No active access - call access() first", "phalcon/Auth/Manager.zep", 211);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("activeAccess"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 28, &actions);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setonlyactions", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Auth_Manager, setAccess)
{
	zval *access, access_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&access_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(access, phalcon_contracts_auth_access_access_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &access);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeAccess"), access);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, setDefaultGuard)
{
	zval *guard, guard_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &guard);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultGuard"), guard);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Manager, user)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "user", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Manager, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &credentials_param);
	if (!credentials_param) {
		ZEPHIR_INIT_VAR(&credentials);
		array_init(&credentials);
	} else {
		zephir_get_arrval(&credentials, credentials_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "guard", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "validate", NULL, 0, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Auth_Manager(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("guards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guards"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

