
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/time.h"


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
 * @extends AbstractGuard<SessionGuardConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_Session)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Guard, Session, phalcon, auth_guard_session, phalcon_auth_guard_abstractguard_ce, phalcon_auth_guard_session_method_entry, 0);

	/**
	 * @var CookiesInterface
	 */
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("cookies"), ZEND_ACC_PROTECTED);
	/**
	 * @var RequestInterface
	 */
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("request"), ZEND_ACC_PROTECTED);
	/**
	 * @var SessionManagerInterface
	 */
	zend_declare_property_null(phalcon_auth_guard_session_ce, SL("session"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_auth_guard_session_ce, SL("viaRemember"), 0, ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_auth_guard_session_ce, 1, phalcon_contracts_auth_guard_guardstateful_ce);
	zend_class_implements(phalcon_auth_guard_session_ce, 1, phalcon_contracts_auth_guard_basicauth_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Guard_Session, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *adapter, adapter_sub, *request, request_sub, *cookies, cookies_sub, *session, session_sub, *config = NULL, config_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&cookies_sub);
	ZVAL_UNDEF(&session_sub);
	ZVAL_UNDEF(&config_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 5)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(cookies, phalcon_http_response_cookiesinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(session, phalcon_session_managerinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(config, phalcon_auth_guard_config_sessionguardconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 1, &adapter, &request, &cookies, &session, &config);
	if (!config) {
		config = &config_sub;
		ZEPHIR_CPY_WRT(config, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(config);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), request);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), cookies);
	zephir_update_property_zval(this_ptr, ZEND_STRL("session"), session);
	if (Z_TYPE_P(config) == IS_NULL) {
		ZEPHIR_INIT_NVAR(config);
		object_init_ex(config, phalcon_auth_guard_config_sessionguardconfig_ce);
		ZEPHIR_CALL_METHOD(NULL, config, "__construct", NULL, 311);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_guard_session_ce, getThis(), "__construct", NULL, 0, adapter, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, fromOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *adapter, adapter_sub, *container, container_sub, *options_param = NULL, config, _0, _1, _2, _3, _4, _5, _6, _7;

	ZVAL_UNDEF(&adapter_sub);
	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(adapter, phalcon_contracts_auth_adapter_adapter_ce)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_contracts_container_service_collection_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &adapter, &container, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_INIT_VAR(&config);
	object_init_ex(&config, phalcon_auth_guard_config_sessionguardconfig_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "suffix");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "rememberName");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &config, "__construct", NULL, 311, &_0, &_2, &_3);
	zephir_check_call_status();
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Http\\RequestInterface");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Session guard");
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_auth_internal_options_ce, "resolveservice", NULL, 0, container, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Http\\Response\\CookiesInterface");
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Session guard");
	ZEPHIR_CALL_CE_STATIC(&_6, phalcon_auth_internal_options_ce, "resolveservice", NULL, 0, container, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Phalcon\\Session\\ManagerInterface");
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "Session guard");
	ZEPHIR_CALL_CE_STATIC(&_7, phalcon_auth_internal_options_ce, "resolveservice", NULL, 0, container, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 312, adapter, &_4, &_6, &_7, &config);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param AuthCredentials $credentials
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, attempt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *credentials_param = NULL, *remember_param = NULL, resolved, _0, _1, _2$$3;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&resolved, &_0, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastUserAttempted"), &resolved);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "hasvalidcredentials", NULL, 0, &resolved, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		if (remember) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "login", NULL, 0, &resolved, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * @param array<string, mixed> $extraConditions
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, basic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval field_zv, *extraConditions_param = NULL, _0;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(field)
		ZEPHIR_Z_PARAM_ARRAY(extraConditions, extraConditions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extraConditions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!field) {
		field = zend_string_init(ZEND_STRL("email"), 0);
		zephir_memory_observe(&field_zv);
		ZVAL_STR(&field_zv, field);
	} else {
		zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	}
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "check", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attemptbasic", NULL, 0, &field_zv, &extraConditions);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, getRememberName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getremembername", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, login)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember;
	zval *user, user_sub, *remember_param = NULL, _0, _1, _2, _3, _4$$3, _5$$4, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &user, &remember_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "auth:beforeLogin");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, user, "getauthidentifier", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (remember) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC);
		if (!(zephir_instance_of_ev(&_4$$3, phalcon_contracts_auth_adapter_rememberadapter_ce))) {
			ZEPHIR_INIT_VAR(&_5$$4);
			object_init_ex(&_5$$4, phalcon_auth_exceptions_doesnotimplement_ce);
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "Adapter");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "RememberAdapter");
			ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 298, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$4, "phalcon/Auth/Guard/Session.zep", 153);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "rememberuser", NULL, 0, user);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setuser", NULL, 0, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "auth:afterLogin");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, loginById)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool remember, _0;
	zval *id, id_sub, *remember_param = NULL, resolved, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(remember)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &id, &remember_param);
	if (!remember_param) {
		remember = 0;
	} else {
		}
	_0 = Z_TYPE_P(id) != IS_LONG;
	if (_0) {
		_0 = Z_TYPE_P(id) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'int' or 'string'", "phalcon/Auth/Guard/Session.zep", 169);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&resolved, &_1, "retrievebyid", NULL, 0, id);
	zephir_check_call_status();
	if (Z_TYPE_P(&resolved) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	if (remember) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "login", NULL, 0, &resolved, &_2);
	zephir_check_call_status();
	RETURN_CCTOR(&resolved);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, logout)
{
	zend_bool _2;
	zval _0, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, current, recaller, token, tokenRow, _1, _8, _9, _3$$3, _4$$3, _5$$3, _6$$5, _7$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&recaller);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&tokenRow);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_10);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&current, this_ptr, "user", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_string(&_0, SL("user"), &current, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "auth:beforeLogout");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&recaller, this_ptr, "recaller", NULL, 0);
	zephir_check_call_status();
	_2 = Z_TYPE_P(&recaller) != IS_NULL;
	if (_2) {
		_2 = zephir_instance_of_ev(&current, phalcon_contracts_auth_authremember_ce);
	}
	if (_2) {
		ZEPHIR_CALL_METHOD(&token, &recaller, "gettoken", NULL, 313);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&tokenRow, &current, "getremembertoken", NULL, 0, &token);
		zephir_check_call_status();
		if (Z_TYPE_P(&tokenRow) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(NULL, &tokenRow, "delete", NULL, 0);
			zephir_check_call_status();
		}
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "getremembername", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "has", NULL, 0, &_5$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "getremembername", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "delete", NULL, 0, &_7$$5);
			zephir_check_call_status();
		}
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_8, "remove", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 1, 0);
	zephir_array_update_string(&_10, SL("user"), &current, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "auth:afterLogout");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_1, &_10);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &__$null);
	ZEPHIR_MM_RESTORE();
}

/**
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, once)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, _0, _1, _2$$3, _3$$3;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
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
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "auth:beforeLogin");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "validate", NULL, 0, &credentials);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("lastUserAttempted"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setuser", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "auth:afterLogin");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "firemanagerevent", NULL, 0, &_3$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

/**
 * @param array<string, mixed> $extraConditions
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, onceBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval field_zv, *extraConditions_param = NULL, credentials, user, _0, _1, _2$$4;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(field)
		ZEPHIR_Z_PARAM_ARRAY(extraConditions, extraConditions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extraConditions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (!field) {
		field = zend_string_init(ZEND_STRL("email"), 0);
		zephir_memory_observe(&field_zv);
		ZVAL_STR(&field_zv, field);
	} else {
		zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	}
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	ZEPHIR_CALL_METHOD(&credentials, this_ptr, "basiccredentials", NULL, 0, &field_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&credentials) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_array_merge(&_1, &credentials, &extraConditions);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "once", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&user, &_2$$4);
		RETURN_CCTOR(&user);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(Phalcon_Auth_Guard_Session, user)
{
	zend_bool _3, _7;
	zval fromRecaller, id, recaller, _0, _1, _2, _6, _4$$4, _5$$4, _8$$6, _9$$6, _10$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fromRecaller);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&recaller);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "user");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&id, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&id) == IS_LONG;
	if (!(_3)) {
		_3 = Z_TYPE_P(&id) == IS_STRING;
	}
	if (_3) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "retrievebyid", NULL, 0, &id);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &_5$$4);
	}
	ZEPHIR_CALL_METHOD(&recaller, this_ptr, "recaller", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
	_7 = Z_TYPE_P(&_6) == IS_NULL;
	if (_7) {
		_7 = Z_TYPE_P(&recaller) != IS_NULL;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&fromRecaller, this_ptr, "userfromrecaller", NULL, 0, &recaller);
		zephir_check_call_status();
		if (Z_TYPE_P(&fromRecaller) != IS_NULL) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("user"), &fromRecaller);
			zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("session"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$6, &fromRecaller, "getauthidentifier", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_8$$6, "set", NULL, 0, &_9$$6, &_10$$6);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "user");
}

/**
 * @phpstan-param AuthCredentials $credentials
 *
 * @phpstan-assert-if-true !null $this->lastUserAttempted
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, validate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, resolved, _0;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&resolved);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&resolved, &_0, "retrievebycredentials", NULL, 0, &credentials);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("lastUserAttempted"), &resolved);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hasvalidcredentials", NULL, 0, &resolved, &credentials);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, viaRemember)
{

	RETURN_MEMBER(getThis(), "viaRemember");
}

/**
 * @param array<string, mixed> $extraConditions
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, attemptBasic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extraConditions;
	zval field_zv, *extraConditions_param = NULL, credentials, _0;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&extraConditions);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(field)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(extraConditions, extraConditions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		extraConditions_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	if (!extraConditions_param) {
		ZEPHIR_INIT_VAR(&extraConditions);
		array_init(&extraConditions);
	} else {
		zephir_get_arrval(&extraConditions, extraConditions_param);
	}
	ZEPHIR_CALL_METHOD(&credentials, this_ptr, "basiccredentials", NULL, 0, &field_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&credentials) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &credentials, &extraConditions);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attempt", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return array<string, mixed>|null
 */
PHP_METHOD(Phalcon_Auth_Guard_Session, basicCredentials)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field_zv, basic, _0, _1;
	zend_string *field = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&basic);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&basic, &_0, "getbasicauth", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&basic) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_memory_observe(&_1);
	zephir_array_fetch_string(&_1, &basic, SL("username"), PH_NOISY, "phalcon/Auth/Guard/Session.zep", 328);
	zephir_array_update_zval(return_value, &field_zv, &_1, PH_COPY);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_array_fetch_string(&_1, &basic, SL("password"), PH_NOISY, "phalcon/Auth/Guard/Session.zep", 330);
	zephir_array_update_string(return_value, SL("password"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, createRememberToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, adapter, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&adapter);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &user);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&adapter, &_0);
	ZEPHIR_RETURN_CALL_METHOD(&adapter, "createremembertoken", NULL, 0, user);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, recaller)
{
	zval raw, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&raw);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getremembername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getremembername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &_3, "get", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&raw, &_4, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&raw)) {
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(&raw) == IS_STRING) {
		object_init_ex(return_value, phalcon_auth_guard_userremember_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 314, &raw);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(&raw) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, phalcon_auth_guard_userremember_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 314, &raw);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, rememberUser)
{
	zval _4;
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, agent, payload, token, _0, _1, _3, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&agent);
	ZVAL_UNDEF(&payload);
	ZVAL_UNDEF(&token);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &user);
	ZEPHIR_CALL_METHOD(&token, this_ptr, "createremembertoken", NULL, 0, user);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getuseragent", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	ZEPHIR_CPY_WRT(&agent, &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_support_helper_json_encode_ce);
	if (zephir_has_constructor(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	ZEPHIR_CALL_METHOD(&_5, user, "getauthidentifier", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("id"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_5, &token, "gettoken", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("token"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("user_agent"), &agent, PH_COPY | PH_SEPARATE);
	ZVAL_LONG(&_6, 4194304);
	ZEPHIR_CALL_METHOD(&payload, &_3, "__invoke", NULL, 25, &_4, &_6);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getremembername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_time(&_7);
	ZVAL_LONG(&_8, (zephir_get_numberval(&_7) + ((8640 * 60) * 60)));
	ZEPHIR_CALL_METHOD(NULL, &_6, "set", NULL, 0, &_5, &payload, &_8);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_Session, userFromRecaller)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *recaller, recaller_sub, __$true, __$false, id, resolved, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&recaller_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(recaller, phalcon_auth_guard_userremember_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &recaller);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC);
	if (!(zephir_instance_of_ev(&_0, phalcon_contracts_auth_adapter_rememberadapter_ce))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&id, recaller, "getid", NULL, 315);
	zephir_check_call_status();
	if (Z_TYPE_P(&id) == IS_NULL) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, recaller, "gettoken", NULL, 313);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, recaller, "getuseragent", NULL, 316);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resolved, &_1, "retrievebytoken", NULL, 0, &id, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&resolved) != IS_NULL) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("viaRemember"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("viaRemember"), &__$false);
	}
	RETURN_CCTOR(&resolved);
}

