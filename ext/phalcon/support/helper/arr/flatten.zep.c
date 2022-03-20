
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
 * Flattens an array up to the one level depth, unless `$deep` is set to
 * `true`
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Flatten)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Flatten, phalcon, support_helper_arr_flatten, phalcon_support_helper_arr_flatten_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array $collection
 * @param bool  $deep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep;
	zval *collection_param = NULL, *deep_param = NULL, data, item, *_0, _1, _2$$3, _4$$3, _6$$3, _8$$4, _9$$4, _10$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &deep_param);
	zephir_get_arrval(&collection, collection_param);
	if (!deep_param) {
		deep = 0;
	} else {
		deep = zephir_get_boolval(deep_param);
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Flatten.zep", 37);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processnotarray", &_3, 0, &data, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_2$$3);
			if (deep) {
				ZVAL_BOOL(&_4$$3, 1);
			} else {
				ZVAL_BOOL(&_4$$3, 0);
			}
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processarraydeep", &_5, 0, &data, &item, &_4$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_2$$3);
			if (deep) {
				ZVAL_BOOL(&_6$$3, 1);
			} else {
				ZVAL_BOOL(&_6$$3, 0);
			}
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "processarray", &_7, 0, &data, &item, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&data, &_2$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &collection, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &collection, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &collection, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "processnotarray", &_3, 0, &data, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_8$$4);
				if (deep) {
					ZVAL_BOOL(&_9$$4, 1);
				} else {
					ZVAL_BOOL(&_9$$4, 0);
				}
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "processarraydeep", &_5, 0, &data, &item, &_9$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_8$$4);
				if (deep) {
					ZVAL_BOOL(&_10$$4, 1);
				} else {
					ZVAL_BOOL(&_10$$4, 0);
				}
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "processarray", &_7, 0, &data, &item, &_10$$4);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&data, &_8$$4);
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&data);
}

/**
 * @param array $data
 * @param mixed $item
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processNotArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, *item, item_sub;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &item);
	zephir_get_arrval(&data, data_param);


	if (Z_TYPE_P(item) != IS_ARRAY) {
		zephir_array_append(&data, item, PH_SEPARATE, "phalcon/Support/Helper/Arr/Flatten.zep", 49);
	}
	RETURN_CTOR(&data);
}

/**
 * @param array $data
 * @param mixed $item
 * @param bool  $deep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Flatten, processArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep, _0;
	zval *data_param = NULL, *item, item_sub, *deep_param = NULL, _1$$3, _2$$3;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(item)
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &item, &deep_param);
	zephir_get_arrval(&data, data_param);
	deep = zephir_get_boolval(deep_param);


	_0 = Z_TYPE_P(item) == IS_ARRAY;
	if (_0) {
		_0 = !deep;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "array_values", NULL, 14, item);
		zephir_check_call_status();
		zephir_fast_array_merge(&_1$$3, &data, &_2$$3);
		ZEPHIR_CPY_WRT(&data, &_1$$3);
	}
	RETURN_CTOR(&data);
}

/**
 * @param array $data
 * @param mixed $item
 * @param bool  $deep
 *
 * @return array
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY(data)
		Z_PARAM_ZVAL(item)
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &item, &deep_param);
	zephir_get_arrval(&data, data_param);
	deep = zephir_get_boolval(deep_param);


	_0 = Z_TYPE_P(item) == IS_ARRAY;
	if (_0) {
		_0 = deep;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_BOOL(&_3$$3, 1);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "__invoke", NULL, 0, item, &_3$$3);
		zephir_check_call_status();
		zephir_fast_array_merge(&_1$$3, &data, &_2$$3);
		ZEPHIR_CPY_WRT(&data, &_1$$3);
	}
	RETURN_CTOR(&data);
}

