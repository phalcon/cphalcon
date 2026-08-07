
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
#include "kernel/operators.h"


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
 * @phpstan-import-type AuthCredentials from Adapter
 *
 * @template TConfig of GuardConfig
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_AbstractGuard)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guard, AbstractGuard, phalcon, auth_guard_abstractguard, phalcon_auth_guard_abstractguard_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_abstractguard_ce, SL("adapter"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Auth\\Adapter\\Adapter"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_abstractguard_ce, SL("config"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\Auth\\Guard\\GuardConfig"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_abstractguard_ce, SL("lastUserAttempted"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Contracts\\Auth\\AuthUser"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_abstractguard_ce, SL("user"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Contracts\\Auth\\AuthUser"));
	}

	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_abstractguard_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	zend_class_implements(phalcon_auth_guard_abstractguard_ce, 1, phalcon_contracts_auth_guard_guard_ce);
	return SUCCESS;
}

/**
 * @phpstan-param TConfig $config
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, __construct)
{
	zval *adapter, adapter_sub, *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&config_sub);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("config", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_contracts_auth_guard_guardconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &adapter, &config);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 155, adapter);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 156, config);
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, check)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getAdapter)
{

	RETURN_MEMBER(getThis(), "adapter");
}

/**
 * Returns the guard configuration object.
 *
 * @phpstan-return TConfig
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getConfig)
{

	RETURN_MEMBER(getThis(), "config");
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getLastUserAttempted)
{

	RETURN_MEMBER(getThis(), "lastUserAttempted");
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, guest)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasUser)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("user", 4, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 157, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, id)
{
	zval current;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&current, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&current) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_RETURN_CALL_METHOD(&current, "getauthidentifier", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setAdapter)
{
	zval *adapter, adapter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &adapter);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 155, adapter);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setUser)
{
	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("user", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &user);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 157, user);
	RETURN_THISW();
}

/**
 * user should be ?AuthUser
 * @phpstan-param AuthCredentials $credentials
 *
 * @phpstan-assert-if-true !null $user
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, hasValidCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&credentials);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapter", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(user)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	if (Z_TYPE_P(user) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 155, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "validatecredentials", NULL, 0, user, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 9, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 158, PH_NOISY_CC);
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 158, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "set", NULL, 0, &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 159, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_Auth_Guard_AbstractGuard, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, __$null, _0, _1$$3, _2$$3;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 159, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 159, PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

