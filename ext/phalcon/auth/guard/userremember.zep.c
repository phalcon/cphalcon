
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Value object representing the contents of a remember-me cookie.
 *
 * @phpstan-type RememberPayload array{id?: int|string, token?: string, user_agent?: string}
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_UserRemember)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Guard, UserRemember, phalcon, auth_guard_userremember, phalcon_auth_guard_userremember_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var int|string|null
	 */
	zend_declare_property_null(phalcon_auth_guard_userremember_ce, SL("id"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_userremember_ce, SL("token"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_auth_guard_userremember_ce, SL("userAgent"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Accepts either the raw JSON cookie value (string) or the already
 * decoded associative array. Malformed input degrades to an empty
 * payload so callers can read getters without null-guarding.
 *
 * @param string|array<string, mixed> $payload
 */
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, __construct)
{
	zval _9, _12;
	zend_bool _0, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload, payload_sub, data, rawId, _3, _4, _5, _7, _8, _10, _11, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&rawId);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be 'array' or 'string'", "phalcon/Auth/Guard/UserRemember.zep", 49);
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
			ZEPHIR_CALL_METHOD(&data, &_1$$4, "__invoke", NULL, 305, payload, &_2$$4);
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
		}
	}
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	if (zephir_array_isset_value_string(&data, SL("id"))) {
		zephir_memory_observe(&rawId);
		zephir_array_fetch_string(&rawId, &data, SL("id"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 65);
	} else {
		ZEPHIR_INIT_NVAR(&rawId);
		ZVAL_NULL(&rawId);
	}
	ZEPHIR_INIT_VAR(&_5);
	_6 = Z_TYPE_P(&rawId) == IS_LONG;
	if (!(_6)) {
		_6 = Z_TYPE_P(&rawId) == IS_STRING;
	}
	if (_6) {
		ZEPHIR_CPY_WRT(&_5, &rawId);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		ZVAL_NULL(&_5);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("id"), &_5);
	ZEPHIR_INIT_VAR(&_7);
	if (zephir_array_isset_value_string(&data, SL("token"))) {
		zephir_memory_observe(&_8);
		zephir_array_fetch_string(&_8, &data, SL("token"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 68);
		zephir_cast_to_string(&_9, &_8);
		ZEPHIR_CPY_WRT(&_7, &_9);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("token"), &_7);
	ZEPHIR_INIT_VAR(&_10);
	if (zephir_array_isset_value_string(&data, SL("user_agent"))) {
		zephir_memory_observe(&_11);
		zephir_array_fetch_string(&_11, &data, SL("user_agent"), PH_NOISY, "phalcon/Auth/Guard/UserRemember.zep", 69);
		zephir_cast_to_string(&_12, &_11);
		ZEPHIR_CPY_WRT(&_10, &_12);
	} else {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_STRING(&_10, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("userAgent"), &_10);
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

