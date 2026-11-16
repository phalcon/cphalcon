
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
 * Returns a subset of the collection based on the values of the collection
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Arr_Pluck)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Arr, Pluck, phalcon, support_helper_arr_pluck, phalcon_support_helper_arr_pluck_method_entry, 0);

	return SUCCESS;
}

/**
 * @param array<array-key, mixed> $collection
 * @param string                  $element
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, __invoke)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL;
	zval *collection_param = NULL, element_zv, item, filtered, *_0, _2, _1$$3, _4$$4;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&collection, collection_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Support/Helper/Arr/Pluck.zep", 34);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "checkObject", &_zephir_call_cache[0], &filtered, &element_zv, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_1$$3);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "checkArray", &_zephir_call_cache[1], &filtered, &element_zv, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&filtered, &_1$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_3 = 1;
		while (1) {
			if (_3) {
				_3 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &collection, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_2, &collection, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&item, &collection, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "checkObject", &_zephir_call_cache[6], &filtered, &element_zv, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_4$$4);
				ZEPHIR_CALL_METHOD_CACHED(&_4$$4, this_ptr, "checkArray", &_zephir_call_cache[7], &filtered, &element_zv, &item);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&filtered, &_4$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&filtered);
}

/**
 * @param array<array-key, mixed> $filtered
 * @param string                  $element
 * @param mixed                   $item
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, checkArray)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *element = NULL;
	zval *filtered_param = NULL, element_zv, *item, item_sub, _2$$3;
	zval filtered;

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(filtered, filtered_param)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	filtered_param = ZEND_CALL_ARG(execute_data, 1);
	item = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&filtered, filtered_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	_0 = Z_TYPE_P(item) == IS_ARRAY;
	if (_0) {
		_1 = zephir_array_isset_value(item, &element_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_0 = _1;
	}
	if (_0) {
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch(&_2$$3, item, &element_zv, PH_NOISY, "phalcon/Support/Helper/Arr/Pluck.zep", 47);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&filtered, &_2$$3, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 47);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&filtered);
}

/**
 * @param array<array-key, mixed> $filtered
 * @param string                  $element
 * @param mixed                   $item
 *
 * @return array<array-key, mixed>
 */
PHP_METHOD(Phalcon_Support_Helper_Arr_Pluck, checkObject)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *element = NULL;
	zval *filtered_param = NULL, element_zv, *item, item_sub, _2$$3;
	zval filtered;

	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(filtered, filtered_param)
		Z_PARAM_STR(element)
		Z_PARAM_ZVAL(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	filtered_param = ZEND_CALL_ARG(execute_data, 1);
	item = ZEND_CALL_ARG(execute_data, 3);
	zephir_get_arrval(&filtered, filtered_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	_0 = Z_TYPE_P(item) == IS_OBJECT;
	if (_0) {
		_1 = zephir_isset_property_value_zval(item, &element_zv);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_0 = _1;
	}
	if (_0) {
		zephir_memory_observe(&_2$$3);
		zephir_read_property_zval(&_2$$3, item, &element_zv, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&filtered, &_2$$3, PH_SEPARATE, "phalcon/Support/Helper/Arr/Pluck.zep", 63);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&filtered);
}

