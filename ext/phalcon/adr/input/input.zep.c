
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Generic, string-keyed input bag for an Action.
 *
 * `fromRequest()` merges the request query, parsed body and route attributes
 * into a single bag (later sources win). Extend it to build a typed, per-domain
 * input value object: the factories use late static binding, so a subclass's
 * `fromRequest()` / `fromArray()` return that subclass.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Input_Input)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Input, Input, phalcon, adr_input_input, phalcon_adr_input_input_method_entry, 0);

	/**
	 * @var array
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_adr_input_input_ce, SL("data"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Input_Input, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &data_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 347, &data);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Input_Input, fromArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL;
	zval data;

	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 326, &data);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Input_Input, fromRequest)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, json, decoded, _0, _2, _3, _5, _6, _7, _8, _9, _4$$3;

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&json);
	ZVAL_UNDEF(&decoded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_contracts_http_attributerequest_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request);
	ZEPHIR_INIT_VAR(&json);
	array_init(&json);
	ZEPHIR_CALL_METHOD(&_0, request, "getcontenttype", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "json");
	ZEPHIR_CALL_FUNCTION(&_3, "str_contains", NULL, 327, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(&decoded, request, "getjsonrawbody", NULL, 0, &_4$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&decoded) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&json, &decoded);
		}
	}
	object_init_ex(return_value, zend_get_called_scope(execute_data));
	ZEPHIR_CALL_METHOD(&_5, request, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, request, "getpost", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, request, "getattributes", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, &_7, "all", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "array_merge", NULL, 193, &_5, &_6, &json, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 326, &_9);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_ADR_Input_Input, get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval key_zv, *defaultValue = NULL, defaultValue_sub, __$null, _0, _1, _2;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		defaultValue = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 347, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_1, &key_zv)) {
		zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 347, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_2, &key_zv, PH_NOISY, "phalcon/ADR/Input/Input.zep", 74);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaultValue);
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_ADR_Input_Input, has)
{
	zval key_zv, _0;
	zend_string *key = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&key_zv, key);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 347, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &key_zv));
}

PHP_METHOD(Phalcon_ADR_Input_Input, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "data", IS_ARRAY);
}

