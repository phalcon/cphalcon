
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
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
 * ACL-backed access gate. Checks the authenticated user's role against a
 * Phalcon\Acl adapter: the ACL component is taken from the 'handler' context
 * key (prefixed with 'module' and the module separator when present) and the
 * ACL access is the action name. The 'params' context key is passed through
 * to the ACL adapter for callable rules.
 *
 * Filter semantics differ from the binary gates: except = bypass the gate
 * for the listed actions; only = the gate applies to the listed actions
 * exclusively (everything else is allowed).
 *
 * Role resolution: no user resolves to the configured guest role; a user
 * implementing Phalcon\Acl\RoleAwareInterface supplies its role name; any
 * other user is rejected with an exception.
 *
 * @phpstan-import-type auth_access_context from AuthTypes
 * @phpstan-import-type auth_acl_options from AuthTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Acl)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Access, Acl, phalcon, auth_access_acl, phalcon_auth_access_abstractaccess_ce, phalcon_auth_access_acl_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_access_acl_ce, SL("acl"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Acl\\Adapter\\AdapterInterface"));
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "guest", sizeof("guest") - 1);
		zephir_declare_typed_property(phalcon_auth_access_acl_ce, SL("guestRole"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, ":", sizeof(":") - 1);
		zephir_declare_typed_property(phalcon_auth_access_acl_ce, SL("moduleSeparator"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param auth_acl_options $options
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, __construct)
{
	zval _1$$3, _3$$4;
	zend_bool _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *acl, acl_sub, *options_param = NULL, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&acl_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("acl", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("guestRole", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("moduleSeparator", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(acl, phalcon_acl_adapter_adapterinterface_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &acl, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 445, acl);
	zephir_memory_observe(&value);
	_0 = zephir_array_isset_string_fetch(&value, &options, SL("guestRole"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		zephir_cast_to_string(&_1$$3, &value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 446, &_1$$3);
	}
	ZEPHIR_OBS_NVAR(&value);
	_2 = zephir_array_isset_string_fetch(&value, &options, SL("moduleSeparator"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_cast_to_string(&_3$$4, &value);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 447, &_3$$4);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-param auth_access_context $context
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, isAllowed)
{
	zend_bool _3, _4, _7, _8, _10, _11, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval context;
	zend_string *actionName = NULL;
	zval *guard, guard_sub, actionName_zv, *context_param = NULL, __$true, component, handler, module, params, _0, _1, _5, _6, _14, _15, _9$$5, _12$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&guard_sub);
	ZVAL_UNDEF(&actionName_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&component);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&context);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("exceptActions", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("onlyActions", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("moduleSeparator", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("acl", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
		Z_PARAM_STR(actionName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	guard = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		context_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&actionName_zv);
	ZVAL_STR_COPY(&actionName_zv, actionName);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 448, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", &_2, 36, &actionName_zv, &_0, &__$true);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	}
	_3 = zephir_isempty_property_fast(this_ptr, _zephir_prop_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = !(_3);
	if (_4) {
		zephir_read_property_cached(&_5, this_ptr, _zephir_prop_1, 449, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_6, "in_array", &_2, 36, &actionName_zv, &_5, &__$true);
		zephir_check_call_status();
		_4 = !zephir_is_true(&_6);
	}
	if (_4) {
		RETURN_MM_BOOL(1);
	}
	zephir_memory_observe(&handler);
	_7 = zephir_array_isset_string_fetch(&handler, &context, SL("handler"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_7;
	_8 = Z_TYPE_P(&handler) != IS_STRING;
	if (!(_8)) {
		_8 = ZEPHIR_IS_STRING_IDENTICAL(&handler, "");
	}
	if (_8) {
		ZEPHIR_INIT_VAR(&_9$$5);
		object_init_ex(&_9$$5, phalcon_auth_exceptions_missinghandlercontext_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_9$$5, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$5, "phalcon/Auth/Access/Acl.zep", 84);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&component, &handler);
	zephir_memory_observe(&module);
	_10 = zephir_array_isset_string_fetch(&module, &context, SL("module"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_10;
	_11 = Z_TYPE_P(&module) == IS_STRING;
	if (_11) {
		_11 = !ZEPHIR_IS_STRING_IDENTICAL(&module, "");
	}
	if (_11) {
		zephir_read_property_cached(&_12$$6, this_ptr, _zephir_prop_2, 447, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&component);
		ZEPHIR_CONCAT_VVV(&component, &module, &_12$$6, &handler);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&params);
	ZVAL_NULL(&params);
	ZEPHIR_OBS_NVAR(&params);
	_13 = zephir_array_isset_string_fetch(&params, &context, SL("params"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_13;
	if (Z_TYPE_P(&params) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&params);
		ZVAL_NULL(&params);
	}
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_3, 445, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_15, this_ptr, "resolveRole", &_zephir_call_cache[1], guard);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_14, "isAllowed", &_zephir_call_cache[2], &_15, &component, &actionName_zv, &params);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unused: this gate overrides isAllowed() in full. Fail closed to
 * satisfy the abstract.
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, allowedIf)
{
	zval *guard, guard_sub;

	ZVAL_UNDEF(&guard_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &guard);
	RETURN_BOOL(0);
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, resolveRole)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *guard, guard_sub, user, _0, _1, _2;

	ZVAL_UNDEF(&guard_sub);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &guard);
	ZEPHIR_CALL_METHOD_CACHED(&user, guard, "user", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) == IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "guestRole", IS_STRING);
	}
	if (zephir_instance_of_ev(&user, phalcon_acl_roleawareinterface_ce)) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&user, "getRoleName", &_zephir_call_cache[1]);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_auth_exceptions_doesnotimplement_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Authenticated user");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Acl\\RoleAwareInterface");
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[2], &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Auth/Access/Acl.zep", 138);
	ZEPHIR_MM_RESTORE();
	return;
}

