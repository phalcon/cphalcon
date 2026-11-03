
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
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
 * Lightweight value object returned by array-backed adapters (Memory, Stream)
 * when no application model class is configured.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_AuthUser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth, AuthUser, phalcon, auth_authuser, phalcon_auth_authuser_method_entry, 0);

	/**
	 * @phpstan-var array<string, mixed>
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_auth_authuser_ce, SL("data"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_auth_authuser_ce, 1, phalcon_contracts_auth_authuser_ce);
	return SUCCESS;
}

/**
 * @param array<string, mixed> $data
 *
 * @throws Exception when $data does not contain a scalar 'id' key.
 */
PHP_METHOD(Phalcon_Auth_AuthUser, __construct)
{
	zend_bool _0, _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, _2, _4, _5$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	_0 = zephir_array_isset_value_string(&data, SL("id"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = !(_0);
	if (!(_1)) {
		zephir_memory_observe(&_2);
		zephir_array_fetch_string(&_2, &data, SL("id"), PH_NOISY, "phalcon/Auth/AuthUser.zep", 37);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_2) != IS_LONG;
		if (_3) {
			zephir_memory_observe(&_4);
			zephir_array_fetch_string(&_4, &data, SL("id"), PH_NOISY, "phalcon/Auth/AuthUser.zep", 37);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_3 = Z_TYPE_P(&_4) != IS_STRING;
		}
		_1 = _3;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_5$$3);
		object_init_ex(&_5$$3, phalcon_auth_exceptions_datamustcontainidkey_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 414);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalcon/Auth/AuthUser.zep", 38);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 457, &data);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Auth_AuthUser, getAuthIdentifier)
{
	zval id, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 457, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&id);
	zephir_array_fetch_string(&id, &_0, SL("id"), PH_NOISY, "phalcon/Auth/AuthUser.zep", 49);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&id);
}

PHP_METHOD(Phalcon_Auth_AuthUser, getAuthPassword)
{
	zend_bool _1;
	zval password, _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&password);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&password);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 457, PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string_fetch(&password, &_0, SL("password"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1;
	ZEPHIR_INIT_VAR(&_2);
	if (Z_TYPE_P(&password) == IS_STRING) {
		ZEPHIR_CPY_WRT(&_2, &password);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "");
	}
	RETURN_CCTOR(&_2);
}

/**
 * Returns the underlying data array.
 *
 * @return array<string, mixed>
 */
PHP_METHOD(Phalcon_Auth_AuthUser, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "data", IS_ARRAY);
}

