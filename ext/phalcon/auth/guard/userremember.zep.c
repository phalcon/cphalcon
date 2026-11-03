
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Value object representing the contents of a remember-me cookie.
 *
 * @phpstan-import-type auth_remember_payload from AuthTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_UserRemember)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guard, UserRemember, phalcon, auth_guard_userremember, phalcon_auth_guard_userremember_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int|string|null
	 */
	zend_declare_property_null(phalcon_auth_guard_userremember_ce, SL("id"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_userremember_ce, SL("token"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_guard_userremember_ce, SL("userAgent"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Accepts either the raw JSON cookie value (string) or the already
 * decoded associative array. Malformed input degrades to an empty
 * payload so callers can read getters without null-guarding.
 *
 * @param array<string, mixed>|string $payload
 */
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, __construct)
{
	zval _11, _15;
	zend_bool _0, _5, _7, _9, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload, payload_sub, data, rawId, _3, _4, _6, _8, _10, _12, _14, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&rawId);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("id", 2, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("token", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("userAgent", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(payload)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &payload);
	_0 = Z_TYPE_P(payload) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(payload) != IS_STRING;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'array' or 'string'", "phalcon/Auth/Guard/UserRemember.zep", 44);
		return;
	}

	/* try_start_1: */

		if (Z_TYPE_P(payload) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_support_helper_json_decode_ce);
			if (zephir_has_constructor(&_1$$4)) {
				ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
			}

			ZVAL_BOOL(&_2$$4, 1);
			ZEPHIR_CALL_METHOD(&data, &_1$$4, "__invoke", NULL, 411, payload, &_2$$4);
			zephir_check_call_status_or_jump(try_end_1);
		} else {
			ZEPHIR_CPY_WRT(&data, payload);
		}

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		ZEPHIR_INIT_VAR(&_4);
		if (zephir_is_instance_of(&_3, SL("InvalidArgumentException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_4, &_3);
			ZEPHIR_INIT_NVAR(&data);
			array_init(&data);
		} else {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	_5 = zephir_array_isset_value_string(&data, SL("id"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		zephir_memory_observe(&rawId);
		zephir_array_fetch_string(&rawId, &data, SL("id"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 60);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&rawId);
		ZVAL_NULL(&rawId);
	}
	ZEPHIR_INIT_VAR(&_6);
	_7 = Z_TYPE_P(&rawId) == IS_LONG;
	if (!(_7)) {
		_7 = Z_TYPE_P(&rawId) == IS_STRING;
	}
	if (_7) {
		ZEPHIR_CPY_WRT(&_6, &rawId);
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_NULL(&_6);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 477, &_6);
	ZEPHIR_INIT_VAR(&_8);
	_9 = zephir_array_isset_value_string(&data, SL("token"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		zephir_memory_observe(&_10);
		zephir_array_fetch_string(&_10, &data, SL("token"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 63);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_11, &_10);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&_8, &_11);
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_STRING(&_8, "");
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 478, &_8);
	ZEPHIR_INIT_VAR(&_12);
	_13 = zephir_array_isset_value_string(&data, SL("user_agent"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_13) {
		zephir_memory_observe(&_14);
		zephir_array_fetch_string(&_14, &data, SL("user_agent"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 64);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_15, &_14);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&_12, &_15);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "");
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 479, &_12);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getId)
{

	RETURN_MEMBER(getThis(), "id");
}

PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getToken)
{

	RETURN_MEMBER_TYPED(getThis(), "token", IS_STRING);
}

PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getUserAgent)
{

	RETURN_MEMBER_TYPED(getThis(), "userAgent", IS_STRING);
}

