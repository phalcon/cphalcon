
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/exception.h"


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
 * Internal option-parsing helpers shared by adapter / guard fromOptions()
 * implementations. Not part of the public API.
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Internal_Options)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Auth\\Internal, Options, phalcon, auth_internal_options, phalcon_auth_internal_options_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

/**
 * @phpstan-param array<string, mixed>                              $options
 * @phpstan-param list<array{id?: int|string}&array<string, mixed>> $defaultValue
 *
 * @phpstan-return list<array{id?: int|string}&array<string, mixed>>
 */
PHP_METHOD(Phalcon_Auth_Internal_Options, arrayOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL;
	zval *options_param = NULL, key_zv, *defaultValue_param = NULL, value;
	zval options, defaultValue;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
		ZEPHIR_Z_PARAM_ARRAY(defaultValue, defaultValue_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 1);
	defaultValue_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_get_arrval(&defaultValue, defaultValue_param);
	if (zephir_array_isset_value(&options, &key_zv)) {
		zephir_memory_observe(&value);
		zephir_array_fetch(&value, &options, &key_zv, PH_NOISY, "phalcon/Auth/Internal/Options.zep", 34);
	} else {
		ZEPHIR_CPY_WRT(&value, &defaultValue);
	}
	if (!(Z_TYPE_P(&value) == IS_ARRAY)) {
		RETURN_CTOR(&defaultValue);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 29, &value);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param array<string, mixed> $options
 *
 * @phpstan-return array<string, mixed>
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Internal_Options, requireArray)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL, *context = NULL;
	zval *options_param = NULL, key_zv, context_zv, value, _1$$3, _2$$3, _3$$3;
	zval options;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&context_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
		Z_PARAM_STR(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&context_zv);
	ZVAL_STR_COPY(&context_zv, context);
	zephir_memory_observe(&value);
	zephir_array_isset_fetch(&value, &options, &key_zv, 0);
	_0 = Z_TYPE_P(&value) != IS_ARRAY;
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(&value);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Auth %s requires '%s' to be a non-empty array");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 137, &_2$$3, &context_zv, &key_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Internal/Options.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&value);
}

/**
 * @phpstan-param array<string, mixed> $options
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Internal_Options, requireString)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *key = NULL, *context = NULL;
	zval *options_param = NULL, key_zv, context_zv, value, _1$$3, _2$$3, _3$$3;
	zval options;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&context_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
		Z_PARAM_STR(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&context_zv);
	ZVAL_STR_COPY(&context_zv, context);
	zephir_memory_observe(&value);
	zephir_array_isset_fetch(&value, &options, &key_zv, 0);
	_0 = Z_TYPE_P(&value) != IS_STRING;
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Auth %s requires '%s' to be a non-empty string");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 137, &_2$$3, &context_zv, &key_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Internal/Options.zep", 79);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&value);
}

/**
 * @param array<string, mixed> $options
 */
PHP_METHOD(Phalcon_Auth_Internal_Options, stringOrNull)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *key = NULL;
	zval *options_param = NULL, key_zv, value, _0;
	zval options;

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	options_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&options, options_param);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&value);
	zephir_array_isset_fetch(&value, &options, &key_zv, 0);
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(&value) == IS_STRING) {
		ZEPHIR_CPY_WRT(&_0, &value);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);
}

