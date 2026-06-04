
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
		zephir_array_fetch(&value, &options, &key_zv, PH_NOISY, "phalcon/Auth/Internal/Options.zep", 36);
	} else {
		ZEPHIR_CPY_WRT(&value, &defaultValue);
	}
	if (!(Z_TYPE_P(&value) == IS_ARRAY)) {
		RETURN_CTOR(&defaultValue);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 27, &value);
	zephir_check_call_status();
	RETURN_MM();
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
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 126, &_2$$3, &context_zv, &key_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Auth/Internal/Options.zep", 60);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&value);
}

/**
 * @template T of object
 *
 * @phpstan-param class-string<T> $serviceId
 *
 * @phpstan-return T
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Auth_Internal_Options, resolveService)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *serviceId = NULL, *context = NULL;
	zval *container, container_sub, serviceId_zv, context_zv, _1, _2$$4, _3$$4, _4$$4;

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&serviceId_zv);
	ZVAL_UNDEF(&context_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(container)
		Z_PARAM_STR(serviceId)
		Z_PARAM_STR(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	container = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&serviceId_zv);
	ZVAL_STR_COPY(&serviceId_zv, serviceId);
	zephir_memory_observe(&context_zv);
	ZVAL_STR_COPY(&context_zv, context);
	_0 = !((zephir_instance_of_ev(container, phalcon_contracts_container_service_collection_ce)));
	if (_0) {
		_0 = !((zephir_instance_of_ev(container, phalcon_di_diinterface_ce)));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be an instance of Collection or DiInterface", "phalcon/Auth/Internal/Options.zep", 81);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, container, "has", NULL, 0, &serviceId_zv);
	zephir_check_call_status();
	if (!zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalcon_auth_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "Auth %s requires service '%s' to be bound in the container");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "sprintf", NULL, 126, &_3$$4, &context_zv, &serviceId_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 8, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalcon/Auth/Internal/Options.zep", 91);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(container, "get", NULL, 0, &serviceId_zv);
	zephir_check_call_status();
	RETURN_MM();
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

