
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
 * For the full copyright and license information, please view the LICENSE.txt
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
 * @phpstan-import-type AccessContext from Access
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Acl)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Access, Acl, phalcon, auth_access_acl, phalcon_auth_access_abstractaccess_ce, phalcon_auth_access_acl_method_entry, 0);

	/**
	 * @var AdapterInterface
	 */
	zend_declare_property_null(phalcon_auth_access_acl_ce, SL("acl"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_auth_access_acl_ce, SL("guestRole"), "guest", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_auth_access_acl_ce, SL("moduleSeparator"), ":", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @phpstan-param array{guestRole?: string, moduleSeparator?: string} $options
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, __construct)
{
	zval _0$$3, _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval options;
	zval *acl, acl_sub, *options_param = NULL, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&acl_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("acl"), acl);
	zephir_memory_observe(&value);
	if (zephir_array_isset_string_fetch(&value, &options, SL("guestRole"), 0)) {
		zephir_cast_to_string(&_0$$3, &value);
		zephir_update_property_zval(this_ptr, ZEND_STRL("guestRole"), &_0$$3);
	}
	ZEPHIR_OBS_NVAR(&value);
	if (zephir_array_isset_string_fetch(&value, &options, SL("moduleSeparator"), 0)) {
		zephir_cast_to_string(&_1$$4, &value);
		zephir_update_property_zval(this_ptr, ZEND_STRL("moduleSeparator"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-param AccessContext $context
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Access_Acl, isAllowed)
{
	zend_bool _3, _6, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zend_string *actionName = NULL;
	zval *guard, guard_sub, actionName_zv, *context_param = NULL, __$true, component, handler, module, params, _0, _1, _2, _4, _5, _10, _11, _7$$5, _9$$6;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&context);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("exceptActions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 87, &actionName_zv, &_0, &__$true);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	}
	zephir_memory_observe(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC);
	_3 = !(ZEPHIR_IS_EMPTY(&_2));
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("onlyActions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_5, "in_array", NULL, 87, &actionName_zv, &_4, &__$true);
		zephir_check_call_status();
		_3 = !zephir_is_true(&_5);
	}
	if (_3) {
		RETURN_MM_BOOL(1);
	}
	zephir_memory_observe(&handler);
	zephir_array_isset_string_fetch(&handler, &context, SL("handler"), 0);
	_6 = Z_TYPE_P(&handler) != IS_STRING;
	if (!(_6)) {
		_6 = ZEPHIR_IS_STRING_IDENTICAL(&handler, "");
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_7$$5);
		object_init_ex(&_7$$5, phalcon_auth_exceptions_missinghandlercontext_ce);
		ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", NULL, 319);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$5, "phalcon/Auth/Access/Acl.zep", 93);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&component, &handler);
	zephir_memory_observe(&module);
	zephir_array_isset_string_fetch(&module, &context, SL("module"), 0);
	_8 = Z_TYPE_P(&module) == IS_STRING;
	if (_8) {
		_8 = !ZEPHIR_IS_STRING_IDENTICAL(&module, "");
	}
	if (_8) {
		zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("moduleSeparator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&component);
		ZEPHIR_CONCAT_VVV(&component, &module, &_9$$6, &handler);
	}
	ZEPHIR_INIT_VAR(&params);
	ZVAL_NULL(&params);
	ZEPHIR_OBS_NVAR(&params);
	zephir_array_isset_string_fetch(&params, &context, SL("params"), 0);
	if (Z_TYPE_P(&params) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&params);
		ZVAL_NULL(&params);
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "resolverole", NULL, 0, guard);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_10, "isallowed", NULL, 0, &_11, &component, &actionName_zv, &params);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(guard, phalcon_contracts_auth_guard_guard_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &guard);
	ZEPHIR_CALL_METHOD(&user, guard, "user", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) == IS_NULL) {
		RETURN_MM_MEMBER_TYPED(getThis(), "guestRole", IS_STRING);
	}
	if (zephir_instance_of_ev(&user, phalcon_acl_roleawareinterface_ce)) {
		ZEPHIR_RETURN_CALL_METHOD(&user, "getrolename", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_auth_exceptions_doesnotimplement_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Authenticated user");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Acl\\RoleAwareInterface");
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 320, &_1, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Auth/Access/Acl.zep", 147);
	ZEPHIR_MM_RESTORE();
	return;
}

