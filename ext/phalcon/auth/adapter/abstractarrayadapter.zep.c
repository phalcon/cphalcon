
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"
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
 * Common base for adapters whose user records come from an in-memory list
 * (Memory and Stream). Subclasses provide the row source via loadUsers();
 * everything else - credentials matching, hydration, the empty-credentials
 * guard, and a default linear retrieveById - is shared here.
 *
 * @phpstan-import-type AuthCredentials from \Phalcon\Contracts\Auth\Adapter\Adapter
 * @phpstan-type AuthUserRow array{id?: int|string}&array<string, mixed>
 *
 * @template TConfig of AdapterConfig
 * @extends AbstractAdapter<TConfig>
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractArrayAdapter)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Adapter, AbstractArrayAdapter, phalcon, auth_adapter_abstractarrayadapter, phalcon_auth_adapter_abstractadapter_ce, phalcon_auth_adapter_abstractarrayadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;
}

/**
 * Walks the user list and returns the first row whose non-'password'
 * keys all match strictly. Returns null when no row matches or when
 * $credentials carries no identifying field at all (only 'password',
 * or empty) - protects callers from the silent "first row wins" footgun.
 *
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveByCredentials)
{
	zend_bool _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, row, _0, _1, *_2, _6, _3$$4, _8$$6;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasidentifyingfield", NULL, 0, &credentials);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "loadusers", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 57);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&row);
			ZVAL_COPY(&row, _2);
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "matchesrow", &_4, 0, &row, &credentials);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$4)) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hydrate", &_5, 0, &row);
				zephir_check_call_status();
				RETURN_MM();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&row, &_1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "matchesrow", &_4, 0, &row, &credentials);
				zephir_check_call_status();
				if (zephir_is_true(&_8$$6)) {
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hydrate", &_5, 0, &row);
					zephir_check_call_status();
					RETURN_MM();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&row);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "burnhash", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_NULL();
}

/**
 * Default linear-scan implementation. Memory overrides this for an O(1)
 * id-keyed lookup; Stream uses this as-is.
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, retrieveById)
{
	zend_bool _0, _7, _3$$4, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, row, _1, *_2, _6, _4$$4, _9$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$6);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'int' or 'string'", "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 69);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "loadusers", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_1, 0, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 80);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
		{
			ZEPHIR_INIT_NVAR(&row);
			ZVAL_COPY(&row, _2);
			_3$$4 = zephir_array_isset_value_string(&row, SL("id"));
			if (_3$$4) {
				zephir_array_fetch_string(&_4$$4, &row, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 75);
				_3$$4 = ZEPHIR_IS_IDENTICAL(&_4$$4, id);
			}
			if (_3$$4) {
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hydrate", &_5, 0, &row);
				zephir_check_call_status();
				RETURN_MM();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&row, &_1, "current", NULL, 0);
			zephir_check_call_status();
				_8$$6 = zephir_array_isset_value_string(&row, SL("id"));
				if (_8$$6) {
					zephir_array_fetch_string(&_9$$6, &row, SL("id"), PH_NOISY | PH_READONLY, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 75);
					_8$$6 = ZEPHIR_IS_IDENTICAL(&_9$$6, id);
				}
				if (_8$$6) {
					ZEPHIR_RETURN_CALL_METHOD(this_ptr, "hydrate", &_5, 0, &row);
					zephir_check_call_status();
					RETURN_MM();
				}
		}
	}
	ZEPHIR_INIT_NVAR(&row);
	RETURN_MM_NULL();
}

/**
 * Tests whether a credentials payload carries at least one identifying
 * field (i.e. anything other than 'password'). An empty payload - or a
 * payload that only contains 'password' - is treated as "no lookup".
 *
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, hasIdentifyingField)
{
	zend_bool _4;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *credentials_param = NULL, key, value, *_0, _3;
	zval credentials;

	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &credentials_param);
	zephir_get_arrval(&credentials, credentials_param);
	zephir_is_iterable(&credentials, 0, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 100);
	if (Z_TYPE_P(&credentials) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&credentials), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (!ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &credentials, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &credentials, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &credentials, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &credentials, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &credentials, "current", NULL, 0);
			zephir_check_call_status();
				if (!ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
					RETURN_MM_BOOL(1);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(0);
}

/**
 * Hydrates a raw user row into either the configured model class or a
 * Phalcon\Auth\AuthUser value object.
 *
 * @phpstan-param AuthUserRow $row
 *
 * @throws DoesNotImplement
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, hydrate)
{
	zend_class_entry *_2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, instance, modelClass, _0, _1$$3, _3$$3, _4$$3, _5$$3;
	zval row;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(row, row_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &row_param);
	zephir_get_arrval(&row, row_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&modelClass, &_0, "getmodel", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&modelClass) != IS_NULL) {
		ZEPHIR_INIT_VAR(&instance);
		zephir_fetch_safe_class(&_1$$3, &modelClass);
		_2$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$3), Z_STRLEN_P(&_1$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_2$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&instance, _2$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&instance);
		zephir_check_call_status();
		if (zephir_has_constructor(&instance)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Phalcon\\Contracts\\Auth\\AuthUser");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "User model");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "AuthUser");
		ZEPHIR_CALL_CE_STATIC(NULL, phalcon_auth_exceptions_doesnotimplement_ce, "assert", NULL, 0, &instance, &_3$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&instance, ZEND_STRL("assign")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "assign", NULL, 0, &row);
			zephir_check_call_status();
		}
		RETURN_CCTOR(&instance);
	}
	object_init_ex(return_value, phalcon_auth_authuser_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 159, &row);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the source list of user rows. Concrete subclasses decide
 * where they come from (config array, JSON file, etc.).
 *
 * @phpstan-return list<AuthUserRow>
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, loadUsers)
{
}

/**
 * Strict per-key match of a row against credentials, skipping 'password'.
 *
 * @phpstan-param AuthUserRow     $row
 * @phpstan-param AuthCredentials $credentials
 */
PHP_METHOD(Phalcon_Auth_Adapter_AbstractArrayAdapter, matchesRow)
{
	zval _5$$3, _6$$3, _11$$6, _12$$6;
	zend_bool _8, _3$$3, _9$$6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *row_param = NULL, *credentials_param = NULL, key, value, *_0, _7, _4$$3, _10$$6;
	zval row, credentials;

	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&credentials);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(row, row_param)
		ZEPHIR_Z_PARAM_ARRAY(credentials, credentials_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &row_param, &credentials_param);
	zephir_get_arrval(&row, row_param);
	zephir_get_arrval(&credentials, credentials_param);
	zephir_is_iterable(&credentials, 0, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 165);
	if (Z_TYPE_P(&credentials) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&credentials), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			if (ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
				continue;
			}
			_3$$3 = !(zephir_array_isset_value(&row, &key));
			if (!(_3$$3)) {
				ZEPHIR_OBS_NVAR(&_4$$3);
				zephir_array_fetch(&_4$$3, &row, &key, PH_NOISY, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 160);
				zephir_cast_to_string(&_5$$3, &_4$$3);
				zephir_cast_to_string(&_6$$3, &value);
				_3$$3 = !ZEPHIR_IS_IDENTICAL(&_5$$3, &_6$$3);
			}
			if (_3$$3) {
				RETURN_MM_BOOL(0);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &credentials, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &credentials, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &credentials, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &credentials, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &credentials, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(&key, "password")) {
					continue;
				}
				_9$$6 = !(zephir_array_isset_value(&row, &key));
				if (!(_9$$6)) {
					ZEPHIR_OBS_NVAR(&_10$$6);
					zephir_array_fetch(&_10$$6, &row, &key, PH_NOISY, "phalcon/Auth/Adapter/AbstractArrayAdapter.zep", 160);
					zephir_cast_to_string(&_11$$6, &_10$$6);
					zephir_cast_to_string(&_12$$6, &value);
					_9$$6 = !ZEPHIR_IS_IDENTICAL(&_11$$6, &_12$$6);
				}
				if (_9$$6) {
					RETURN_MM_BOOL(0);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_BOOL(1);
}

