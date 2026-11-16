
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
#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Flattens an array up to the one level depth, unless `$deep` is set to
 * `true`
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Flatten)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Flatten, phalcon, support_helper_arr_flatten, phalcon_support_helper_arr_flatten_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array<array-key, mixed> $collection
 * @param bool                    $deep
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep, _5;
	zval *collection_param = NULL, *deep_param = NULL, data, item, *_0, _4, _1$$3, _2$$3, _3$$3, _6$$4, _7$$4, _8$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &collection_param, &deep_param);
	zephir_get_arrval(&collection, collection_param);
	if (!deep_param) {
		deep = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Flatten.zep", 37);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processNotArray", &_zephir_call_cache[0], &data, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_1$$3);
			if (deep) {
				ZVAL_BOOL(&_2$$3, 1);
			} else {
				ZVAL_BOOL(&_2$$3, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processArrayDeep", &_zephir_call_cache[1], &data, &item, &_2$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_1$$3);
			if (deep) {
				ZVAL_BOOL(&_3$$3, 1);
			} else {
				ZVAL_BOOL(&_3$$3, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "processArray", &_zephir_call_cache[2], &data, &item, &_3$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_1$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &collection, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&item, &collection, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "processNotArray", &_zephir_call_cache[7], &data, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_6$$4);
				if (deep) {
					ZVAL_BOOL(&_7$$4, 1);
				} else {
					ZVAL_BOOL(&_7$$4, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "processArrayDeep", &_zephir_call_cache[8], &data, &item, &_7$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_6$$4);
				if (deep) {
					ZVAL_BOOL(&_8$$4, 1);
				} else {
					ZVAL_BOOL(&_8$$4, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_6$$4, this_ptr, "processArray", &_zephir_call_cache[9], &data, &item, &_8$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_6$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&data);
}

/**
 * @param array<array-key, mixed> $data
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep, _0;
	zval *data_param = NULL, *item, item_sub, *deep_param = NULL, _1$$3, _2$$3;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(item)
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &data_param, &item, &deep_param);
	zephir_get_arrval(&data, data_param);
	_0 = Z_TYPE_P(item) == IS_ARRAY;
	if (_0) {
		_0 = !deep;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "array_values", NULL, 18, item);
		zephir_check_call_status();
		zephir_fast_array_merge(&_1$$3, &data, &_2$$3);
		if (UNEXPECTED(Z_TYPE_P(&_1$$3) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_1$$3, "data", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&data, &_1$$3);
	}
	RETURN_CTOR(&data);
}

/**
 * @param array<array-key, mixed> $data
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processArrayDeep)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep, _0;
	zval *data_param = NULL, *item, item_sub, *deep_param = NULL, _1$$3, _2$$3, _3$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(item)
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &data_param, &item, &deep_param);
	zephir_get_arrval(&data, data_param);
	_0 = Z_TYPE_P(item) == IS_ARRAY;
	if (_0) {
		_0 = deep;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "__invoke", &_zephir_call_cache[0], item, &_3$$3);
		zephir_check_call_status();
		zephir_fast_array_merge(&_1$$3, &data, &_2$$3);
		if (UNEXPECTED(Z_TYPE_P(&_1$$3) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_1$$3, "data", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&data, &_1$$3);
	}
	RETURN_CTOR(&data);
}

/**
 * @param array<array-key, mixed> $data
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processNotArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, *item, item_sub;
	zval data;

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &data_param, &item);
	zephir_get_arrval(&data, data_param);
	if (Z_TYPE_P(item) != IS_ARRAY) {
		zephir_array_append(&data, item, PH_SEPARATE, "phalcon/Support/Helper/Arr/Flatten.zep", 76);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&data);
}

