
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Groups the elements of an array based on the passed callable
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Group)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Group, phalcon, support_helper_arr_group, phalcon_support_helper_arr_group_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array<array-key, mixed> $collection
 * @param callable|string         $method
 *
 * @return array<array-key, list<mixed>>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, __invoke)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method, method_sub, element, filtered, *_0, _2, _1$$3, _4$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &collection_param, &method);
	zephir_get_arrval(&collection, collection_param);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Group.zep", 40);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processCallable", &_zephir_call_cache[0], &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_1$$3);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processObject", &_zephir_call_cache[1], &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_1$$3);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processOther", &_zephir_call_cache[2], &filtered, method, &element);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_1$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &collection, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&element, &collection, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "processCallable", &_zephir_call_cache[7], &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_4$$4);
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "processObject", &_zephir_call_cache[8], &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_4$$4);
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "processOther", &_zephir_call_cache[9], &filtered, method, &element);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_4$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CCTOR(&filtered);
}

PHP_METHOD(Phalcon_Support_Helper_Arr_Group, isCallable)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(method)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &method);
	_0 = zephir_is_callable(method);
	if (!(_0)) {
		_1 = Z_TYPE_P(method) == IS_STRING;
		if (_1) {
			ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "phpFunctionExists", &_zephir_call_cache[0], method);
			zephir_check_call_status();
			_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
		}
		_0 = _1;
	}
	RETURN_MM_BOOL(_0);
}

/**
 * @param mixed $element
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, isObject)
{
	zval *element, element_sub;

	ZVAL_UNDEF(&element_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &element);
	RETURN_BOOL(Z_TYPE_P(element) == IS_OBJECT);
}

/**
 * @param array<array-key, mixed> $filtered
 * @param callable|string         $method
 * @param mixed                   $element
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processCallable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, key, output, _0;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(filtered, filtered_param)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);
	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isCallable", &_zephir_call_cache[0], method);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(&key, "call_user_func", NULL, 34, method, element);
		zephir_check_call_status();
		zephir_array_update_multi(&output, element, SL("za"), 2, &key);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&output);
}

/**
 * @param array<array-key, mixed> $filtered
 * @param callable|string         $method
 * @param mixed                   $element
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processObject)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, output, _0, _2, key$$3;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(filtered, filtered_param)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);
	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isCallable", &_zephir_call_cache[0], method);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "isObject", &_zephir_call_cache[1], element);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		zephir_memory_observe(&key$$3);
		zephir_read_property_zval(&key$$3, element, method, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&key$$3, &key$$3);
		zephir_array_update_multi(&output, element, SL("za"), 2, &key$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&output);
}

/**
 * @param array<array-key, mixed> $filtered
 * @param callable|string         $method
 * @param mixed                   $element
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, processOther)
{
	zend_bool _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filtered_param = NULL, *method, method_sub, *element, element_sub, output, _0, _2, key$$3;
	zval filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(filtered, filtered_param)
		Z_PARAM_ZVAL(method)
		Z_PARAM_ZVAL(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &filtered_param, &method, &element);
	zephir_get_arrval(&filtered, filtered_param);
	ZEPHIR_CPY_WRT(&output, &filtered);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "isCallable", &_zephir_call_cache[0], method);
	zephir_check_call_status();
	_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "isObject", &_zephir_call_cache[1], element);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	_3 = _1;
	if (_3) {
		_4 = zephir_array_isset_value(element, method);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = 1 == _4;
	}
	if (_3) {
		zephir_memory_observe(&key$$3);
		zephir_array_fetch(&key$$3, element, method, PH_NOISY, "phalcon/Support/Helper/Arr/Group.zep", 125);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&key$$3, &key$$3);
		zephir_array_update_multi(&output, element, SL("za"), 2, &key$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&output);
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 114, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Group, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

