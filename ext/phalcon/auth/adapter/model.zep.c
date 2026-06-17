
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


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
 * Phalcon Model-backed adapter.
 *
 * @phpstan-import-type AuthCredentials from \Phalcon\Contracts\Auth\Adapter\Adapter
 *
 * @extends AbstractAdapter<ModelAdapterConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Model)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, Model, phalcon, auth_adapter_model, phalcon_auth_adapter_abstractadapter_ce, phalcon_auth_adapter_model_method_entry, 0);

	zend_class_implements(phalcon_auth_adapter_model_ce, 1, phalcon_contracts_auth_adapter_rememberadapter_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hasher, hasher_sub, *config, config_sub;

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&config_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		Z_PARAM_OBJECT_OF_CLASS(config, phalcon_auth_adapter_config_modeladapterconfig_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &config);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_adapter_model_ce, getThis(), "__construct", NULL, 0, hasher, config);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, fromOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *hasher, hasher_sub, *options_param = NULL, idColumn, _0, _1, _2, _3, _4;

	ZVAL_UNDEF(&hasher_sub);
	ZVAL_UNDEF(&idColumn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(hasher, phalcon_contracts_encryption_security_security_ce)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &hasher, &options_param);
	zephir_get_arrval(&options, options_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "idColumn");
	ZEPHIR_CALL_CE_STATIC(&idColumn, phalcon_auth_internal_options_ce, "stringornull", NULL, 0, &options, &_0);
	zephir_check_call_status();
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, phalcon_auth_adapter_config_modeladapterconfig_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "model");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "model adapter");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_auth_internal_options_ce, "requirestring", NULL, 0, &options, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	if (Z_TYPE_P(&idColumn) != IS_NULL) {
		ZEPHIR_CPY_WRT(&_4, &idColumn);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "id");
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 307, &_1, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 308, hasher, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create and persist a new remember token for the user.
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Adapter_Model, createRememberToken)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, _0$$3, _1$$3, _2$$3, _3, _4, _5;

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(user, phalcon_contracts_auth_authuser_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &user);
	if (!((zephir_instance_of_ev(user, phalcon_contracts_auth_authremember_ce)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_auth_exceptions_doesnotimplement_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "User model");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "AuthRemember");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 146, &_1$$3, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Auth/Adapter/Model.zep", 63);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_3, 30);
	ZEPHIR_CALL_FUNCTION(&_4, "random_bytes", NULL, 309, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "bin2hex", NULL, 310, &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(user, "createremembertoken", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Find a user matching the given credentials (excluding 'password' key).
 *
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByCredentials)
{
	zend_class_entry *_10;
	zend_bool _6, _11;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, found, key, modelClass, value, _0, *_1, _5, _9, _4$$3, _7$$5, _12$$8, _13$$8, _14$$8;
	zval credentials, bind, conditions, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&found);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&modelClass, &_0, "getmodel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_INIT_VAR(&bind);
	array_init(&bind);
	zephir_is_iterable(&credentials, 0, "phalcon/Auth/Adapter/Model.zep", 93);
	if (Z_TYPE_P(&credentials) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&credentials), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			if (ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_SVSVS(&_4$$3, "[", &key, "] = :", &key, ":");
			zephir_array_append(&conditions, &_4$$3, PH_SEPARATE, "phalcon/Auth/Adapter/Model.zep", 89);
			zephir_array_update_zval(&bind, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &credentials, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &credentials, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &credentials, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &credentials, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &credentials, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZEPHIR_CONCAT_SVSVS(&_7$$5, "[", &key, "] = :", &key, ":");
				zephir_array_append(&conditions, &_7$$5, PH_SEPARATE, "phalcon/Auth/Adapter/Model.zep", 89);
				zephir_array_update_zval(&bind, &key, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (ZEPHIR_IS_EMPTY(&conditions)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0);
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join_str(&_9, SL(" AND "), &conditions);
	zephir_array_update_string(&_8, SL("conditions"), &_9, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("bind"), &bind, PH_COPY | PH_SEPARATE);
	_10 = zephir_fetch_class(&modelClass);
	ZEPHIR_CALL_CE_STATIC(&found, _10, "findfirst", NULL, 0, &_8);
	zephir_check_call_status();
	_11 = Z_TYPE_P(&found) != IS_NULL;
	if (_11) {
		_11 = !((zephir_instance_of_ev(&found, phalcon_contracts_auth_authuser_ce)));
	}
	if (_11) {
		ZEPHIR_INIT_VAR(&_12$$8);
		object_init_ex(&_12$$8, phalcon_auth_exceptions_doesnotimplement_ce);
		ZEPHIR_INIT_VAR(&_13$$8);
		ZVAL_STRING(&_13$$8, "User model");
		ZEPHIR_INIT_VAR(&_14$$8);
		ZVAL_STRING(&_14$$8, "AuthUser");
		ZEPHIR_CALL_METHOD(NULL, &_12$$8, "__construct", NULL, 146, &_13$$8, &_14$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$8, "phalcon/Auth/Adapter/Model.zep", 105);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&found);
}

PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveById)
{
	zend_class_entry *_6;
	zval _3, _5;
	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, found, idColumn, modelClass, _1, _2, _4, _8$$4, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&found);
	ZVAL_UNDEF(&idColumn);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &id);
	_0 = Z_TYPE_P(id) != IS_LONG;
	if (_0) {
		_0 = Z_TYPE_P(id) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'int' or 'string'", "phalcon/Auth/Adapter/Model.zep", 115);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&modelClass, &_1, "getmodel", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&idColumn, &_2, "getidcolumn", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, "[", &idColumn, "] = :id:");
	zephir_array_update_string(&_3, SL("conditions"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	zephir_array_update_string(&_5, SL("id"), id, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("bind"), &_5, PH_COPY | PH_SEPARATE);
	_6 = zephir_fetch_class(&modelClass);
	ZEPHIR_CALL_CE_STATIC(&found, _6, "findfirst", NULL, 0, &_3);
	zephir_check_call_status();
	_7 = Z_TYPE_P(&found) != IS_NULL;
	if (_7) {
		_7 = !((zephir_instance_of_ev(&found, phalcon_contracts_auth_authuser_ce)));
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_8$$4);
		object_init_ex(&_8$$4, phalcon_auth_exceptions_doesnotimplement_ce);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "User model");
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "AuthUser");
		ZEPHIR_CALL_METHOD(NULL, &_8$$4, "__construct", NULL, 146, &_9$$4, &_10$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$4, "phalcon/Auth/Adapter/Model.zep", 131);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&found);
}

/**
 * Retrieve a user by the remember-me cookie payload.
 */
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByToken)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *token = NULL, *userAgent = NULL;
	zval *id, id_sub, token_zv, userAgent_zv, tokenRow, user, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&token_zv);
	ZVAL_UNDEF(&userAgent_zv);
	ZVAL_UNDEF(&tokenRow);
	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&_1);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(id)
		Z_PARAM_STR(token)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(userAgent)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	id = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&token_zv);
	ZVAL_STR_COPY(&token_zv, token);
	if (!userAgent) {
		ZEPHIR_INIT_VAR(&userAgent_zv);
	} else {
		zephir_memory_observe(&userAgent_zv);
	ZVAL_STR_COPY(&userAgent_zv, userAgent);
	}
	ZEPHIR_CALL_METHOD(&user, this_ptr, "retrievebyid", NULL, 0, id);
	zephir_check_call_status();
	if (Z_TYPE_P(&user) == IS_NULL) {
		RETURN_MM_NULL();
	}
	if (!((zephir_instance_of_ev(&user, phalcon_contracts_auth_authremember_ce)))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&tokenRow, &user, "getremembertoken", NULL, 0, &token_zv);
	zephir_check_call_status();
	if (Z_TYPE_P(&tokenRow) == IS_NULL) {
		RETURN_MM_NULL();
	}
	_0 = !ZEPHIR_IS_NULL(&userAgent_zv);
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, &tokenRow, "getuseragent", NULL, 0);
		zephir_check_call_status();
		_0 = !ZEPHIR_IS_IDENTICAL(&_1, &userAgent_zv);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&user);
}

