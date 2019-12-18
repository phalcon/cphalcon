
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This class offers quick array functions throughout the framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Helper_Arr) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Helper, Arr, phalcon, helper_arr, phalcon_helper_arr_method_entry, 0);

	return SUCCESS;

}

/**
 * Chunks an array into smaller arrays of a specified size.
 *
 * @param array $collection
 * @param int   $size
 * @param bool  $preserveKeys
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, chunk) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool preserveKeys;
	zend_long size, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *size_param = NULL, *preserveKeys_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &size_param, &preserveKeys_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	size = zephir_get_intval(size_param);
	if (!preserveKeys_param) {
		preserveKeys = 0;
	} else {
		preserveKeys = zephir_get_boolval(preserveKeys_param);
	}


	ZVAL_LONG(&_0, size);
	ZVAL_BOOL(&_1, (preserveKeys ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("array_chunk", NULL, 250, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Helper method to filter the collection
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, filter) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	zephir_get_arrval(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	_0 = Z_TYPE_P(method) == IS_NULL;
	if (!(_0)) {
		_0 = !(zephir_is_callable(method));
	}
	if (_0) {
		RETURN_CTOR(&collection);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_filter", NULL, 251, &collection, method);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the first element of the collection. If a callable is passed, the
 * element returned is the first that validates true
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Helper_Arr, first) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, filtered;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&filtered, "filter", &_0, 252, &collection, method);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&filtered);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 253, &filtered);
	ZEPHIR_UNREF(&filtered);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the key of the first element of the collection. If a callable
 * is passed, the element returned is the first that validates true
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Helper_Arr, firstKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, filtered;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&filtered, "filter", &_0, 252, &collection, method);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&filtered);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 253, &filtered);
	ZEPHIR_UNREF(&filtered);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("key", NULL, 254, &filtered);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Flattens an array up to the one level depth, unless `$deep` is set to `true`
 *
 * @param array $collection
 * @param bool  $deep
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, flatten) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep;
	zval *collection_param = NULL, *deep_param = NULL, data, item, *_0, _1, _2$$6, _3$$6, _5$$6, _6$$7, _7$$7, _9$$11, _10$$11, _11$$11, _12$$12, _13$$12;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &deep_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!deep_param) {
		deep = 0;
	} else {
		deep = zephir_get_boolval(deep_param);
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	zephir_is_iterable(&collection, 0, "phalcon/Helper/Arr.zep", 124);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			if (Z_TYPE_P(&item) != IS_ARRAY) {
				zephir_array_append(&data, &item, PH_SEPARATE, "phalcon/Helper/Arr.zep", 108);
			} else {
				if (deep) {
					ZEPHIR_INIT_NVAR(&_2$$6);
					ZVAL_BOOL(&_5$$6, 1);
					ZEPHIR_CALL_SELF(&_3$$6, "flatten", &_4, 255, &item, &_5$$6);
					zephir_check_call_status();
					zephir_fast_array_merge(&_2$$6, &data, &_3$$6);
					ZEPHIR_CPY_WRT(&data, &_2$$6);
				} else {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZEPHIR_CALL_FUNCTION(&_7$$7, "array_values", &_8, 11, &item);
					zephir_check_call_status();
					zephir_fast_array_merge(&_6$$7, &data, &_7$$7);
					ZEPHIR_CPY_WRT(&data, &_6$$7);
				}
			}
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
				if (Z_TYPE_P(&item) != IS_ARRAY) {
					zephir_array_append(&data, &item, PH_SEPARATE, "phalcon/Helper/Arr.zep", 108);
				} else {
					if (deep) {
						ZEPHIR_INIT_NVAR(&_9$$11);
						ZVAL_BOOL(&_11$$11, 1);
						ZEPHIR_CALL_SELF(&_10$$11, "flatten", &_4, 255, &item, &_11$$11);
						zephir_check_call_status();
						zephir_fast_array_merge(&_9$$11, &data, &_10$$11);
						ZEPHIR_CPY_WRT(&data, &_9$$11);
					} else {
						ZEPHIR_INIT_NVAR(&_12$$12);
						ZEPHIR_CALL_FUNCTION(&_13$$12, "array_values", &_8, 11, &item);
						zephir_check_call_status();
						zephir_fast_array_merge(&_12$$12, &data, &_13$$12);
						ZEPHIR_CPY_WRT(&data, &_12$$12);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&data);

}

/**
 * Helper method to get an array element or a default
 */
PHP_METHOD(Phalcon_Helper_Arr, get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cast;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, *cast_param = NULL, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&cast);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &collection_param, &index, &defaultValue, &cast_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast_param) {
		ZEPHIR_INIT_VAR(&cast);
		ZVAL_STRING(&cast, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(cast_param) != IS_STRING && Z_TYPE_P(cast_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cast' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cast_param) == IS_STRING)) {
		zephir_get_strval(&cast, cast_param);
	} else {
		ZEPHIR_INIT_VAR(&cast);
		ZVAL_EMPTY_STRING(&cast);
	}
	}


	ZEPHIR_OBS_VAR(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	if (UNEXPECTED(zephir_is_true(&cast))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 9, &value, &cast);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);

}

/**
 * Groups the elements of an array based on the passed callable
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, group) {

	zend_bool _2$$3, _3$$3, _5$$7, _6$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *method, method_sub, element, key, *_0, _1;
	zval collection, filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Helper/Arr.zep", 177);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0);
			_2$$3 = Z_TYPE_P(method) != IS_STRING;
			if (_2$$3) {
				_2$$3 = zephir_is_callable(method);
			}
			_3$$3 = _2$$3;
			if (!(_3$$3)) {
				_3$$3 = (zephir_function_exists(method)  == SUCCESS);
			}
			if (_3$$3) {
				ZEPHIR_CALL_FUNCTION(&key, "call_user_func", &_4, 256, method, &element);
				zephir_check_call_status();
				zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
			} else if (Z_TYPE_P(&element) == IS_OBJECT) {
				ZEPHIR_OBS_NVAR(&key);
				zephir_read_property_zval(&key, &element, method, PH_NOISY_CC);
				zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
			} else if (zephir_array_isset(&element, method)) {
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch(&key, &element, method, PH_NOISY, "phalcon/Helper/Arr.zep", 172);
				zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
			}
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
			ZEPHIR_CALL_METHOD(&element, &collection, "current", NULL, 0);
			zephir_check_call_status();
				_5$$7 = Z_TYPE_P(method) != IS_STRING;
				if (_5$$7) {
					_5$$7 = zephir_is_callable(method);
				}
				_6$$7 = _5$$7;
				if (!(_6$$7)) {
					_6$$7 = (zephir_function_exists(method)  == SUCCESS);
				}
				if (_6$$7) {
					ZEPHIR_CALL_FUNCTION(&key, "call_user_func", &_4, 256, method, &element);
					zephir_check_call_status();
					zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
				} else if (Z_TYPE_P(&element) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(&key);
					zephir_read_property_zval(&key, &element, method, PH_NOISY_CC);
					zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
				} else if (zephir_array_isset(&element, method)) {
					ZEPHIR_OBS_NVAR(&key);
					zephir_array_fetch(&key, &element, method, PH_NOISY, "phalcon/Helper/Arr.zep", 172);
					zephir_array_update_multi(&filtered, &element, SL("za"), 2, &key);
				}
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CTOR(&filtered);

}

/**
 * Helper method to get an array element or a default
 *
 * @param array $collection
 * @param mixed $index
 *
 * return bool
 */
PHP_METHOD(Phalcon_Helper_Arr, has) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &index);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	RETURN_MM_BOOL(zephir_array_isset(&collection, index));

}

/**
 * Checks a flat list for duplicate values. Returns true if duplicate
 * values exist and false if values are all unique.
 *
 * @param array $collection
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Arr, isUnique) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	ZEPHIR_CALL_FUNCTION(&_0, "array_unique", NULL, 257, &collection);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_count_int(&collection) == zephir_fast_count_int(&_0));

}

/**
 * Returns the last element of the collection. If a callable is passed, the
 * element returned is the first that validates true
 *
 * @param array    $collection
 * @param callable $method
 *
 * return mixed
 */
PHP_METHOD(Phalcon_Helper_Arr, last) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, filtered;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&filtered, "filter", &_0, 252, &collection, method);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&filtered);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 258, &filtered);
	ZEPHIR_UNREF(&filtered);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the key of the last element of the collection. If a callable is
 * passed, the element returned is the first that validates true
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Helper_Arr, lastKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, filtered;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&filtered, "filter", &_0, 252, &collection, method);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&filtered);
	ZEPHIR_CALL_FUNCTION(NULL, "end", NULL, 258, &filtered);
	ZEPHIR_UNREF(&filtered);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("key", NULL, 254, &filtered);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sorts a collection of arrays or objects by key
 *
 * @param array  $collection
 * @param mixed  $attribute
 * @param string $order
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, order) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval order;
	zval *collection_param = NULL, *attribute, attribute_sub, *order_param = NULL, item, key, *_0, _1;
	zval collection, sorted;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&attribute_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&order);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &attribute, &order_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!order_param) {
		ZEPHIR_INIT_VAR(&order);
		ZVAL_STRING(&order, "asc");
	} else {
		zephir_get_strval(&order, order_param);
	}


	ZEPHIR_INIT_VAR(&sorted);
	array_init(&sorted);
	zephir_is_iterable(&collection, 0, "phalcon/Helper/Arr.zep", 273);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			if (Z_TYPE_P(&item) == IS_OBJECT) {
				ZEPHIR_OBS_NVAR(&key);
				zephir_read_property_zval(&key, &item, attribute, PH_NOISY_CC);
			} else {
				ZEPHIR_OBS_NVAR(&key);
				zephir_array_fetch(&key, &item, attribute, PH_NOISY, "phalcon/Helper/Arr.zep", 267);
			}
			zephir_array_update_zval(&sorted, &key, &item, PH_COPY | PH_SEPARATE);
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
				if (Z_TYPE_P(&item) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(&key);
					zephir_read_property_zval(&key, &item, attribute, PH_NOISY_CC);
				} else {
					ZEPHIR_OBS_NVAR(&key);
					zephir_array_fetch(&key, &item, attribute, PH_NOISY, "phalcon/Helper/Arr.zep", 267);
				}
				zephir_array_update_zval(&sorted, &key, &item, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	if (ZEPHIR_IS_STRING_IDENTICAL(&order, "asc")) {
		ZEPHIR_MAKE_REF(&sorted);
		ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 259, &sorted);
		ZEPHIR_UNREF(&sorted);
		zephir_check_call_status();
	} else {
		ZEPHIR_MAKE_REF(&sorted);
		ZEPHIR_CALL_FUNCTION(NULL, "krsort", NULL, 260, &sorted);
		ZEPHIR_UNREF(&sorted);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 11, &sorted);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Retrieves all of the values for a given key:
 *
 * @param array  $collection
 * @param string $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, pluck) {

	zend_bool _2$$3, _3$$3, _6$$6, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element;
	zval *collection_param = NULL, *element_param = NULL, item, *_0, _1, _4$$4, _5$$5, _8$$7, _9$$8;
	zval collection, filtered;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&element);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &element_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	zephir_get_strval(&element, element_param);


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_is_iterable(&collection, 0, "phalcon/Helper/Arr.zep", 305);
	if (Z_TYPE_P(&collection) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&collection), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			_2$$3 = Z_TYPE_P(&item) == IS_OBJECT;
			if (_2$$3) {
				_2$$3 = zephir_isset_property_zval(&item, &element);
			}
			_3$$3 = Z_TYPE_P(&item) == IS_ARRAY;
			if (_3$$3) {
				_3$$3 = zephir_array_isset(&item, &element);
			}
			if (_2$$3) {
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_read_property_zval(&_4$$4, &item, &element, PH_NOISY_CC);
				zephir_array_append(&filtered, &_4$$4, PH_SEPARATE, "phalcon/Helper/Arr.zep", 299);
			} else if (_3$$3) {
				zephir_array_fetch(&_5$$5, &item, &element, PH_NOISY | PH_READONLY, "phalcon/Helper/Arr.zep", 301);
				zephir_array_append(&filtered, &_5$$5, PH_SEPARATE, "phalcon/Helper/Arr.zep", 301);
			}
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
				_6$$6 = Z_TYPE_P(&item) == IS_OBJECT;
				if (_6$$6) {
					_6$$6 = zephir_isset_property_zval(&item, &element);
				}
				_7$$6 = Z_TYPE_P(&item) == IS_ARRAY;
				if (_7$$6) {
					_7$$6 = zephir_array_isset(&item, &element);
				}
				if (_6$$6) {
					ZEPHIR_OBS_NVAR(&_8$$7);
					zephir_read_property_zval(&_8$$7, &item, &element, PH_NOISY_CC);
					zephir_array_append(&filtered, &_8$$7, PH_SEPARATE, "phalcon/Helper/Arr.zep", 299);
				} else if (_7$$6) {
					zephir_array_fetch(&_9$$8, &item, &element, PH_NOISY | PH_READONLY, "phalcon/Helper/Arr.zep", 301);
					zephir_array_append(&filtered, &_9$$8, PH_SEPARATE, "phalcon/Helper/Arr.zep", 301);
				}
			ZEPHIR_CALL_METHOD(NULL, &collection, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&filtered);

}

/**
 * Helper method to set an array element
 *
 * @param array $collection
 * @param mixed $value
 * @param mixed $index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *value, value_sub, *index = NULL, index_sub, __$null;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&index_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &value, &index);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!index) {
		index = &index_sub;
		index = &__$null;
	}


	if (Z_TYPE_P(index) == IS_NULL) {
		zephir_array_append(&collection, value, PH_SEPARATE, "phalcon/Helper/Arr.zep", 323);
	} else {
		zephir_array_update_zval(&collection, index, value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CTOR(&collection);

}

/**
 * Returns a new array with n elements removed from the right.
 *
 * @param array $collection
 * @param int   $elements
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, sliceLeft) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long elements, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *elements_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &elements_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!elements_param) {
		elements = 1;
	} else {
		elements = zephir_get_intval(elements_param);
	}


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, elements);
	ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 261, &collection, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new array with the X elements from the right
 *
 * @param array $collection
 * @param int   $elements
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, sliceRight) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long elements, ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *elements_param = NULL, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &elements_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!elements_param) {
		elements = 1;
	} else {
		elements = zephir_get_intval(elements_param);
	}


	ZVAL_LONG(&_0, elements);
	ZEPHIR_RETURN_CALL_FUNCTION("array_slice", NULL, 261, &collection, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a new array with keys of the passed array as one element and
 * values as another
 *
 * @param array $collection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, split) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, _0, _1;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &collection);
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "array_values", NULL, 11, &collection);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_1);
	RETURN_MM();

}

/**
 * Returns the passed array as an object
 */
PHP_METHOD(Phalcon_Helper_Arr, toObject) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &collection_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);


	zephir_convert_to_object(&collection);
	RETURN_CTOR(&collection);

}

/**
 * Returns true if the provided function returns true for all elements of
 * the collection, false otherwise.
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Arr, validateAll) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&_0, "filter", &_1, 252, &collection, method);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_count_int(&_0) == zephir_fast_count_int(&collection));

}

/**
 * Returns true if the provided function returns true for at least one
 * element fo the collection, false otherwise.
 *
 * @param array    $collection
 * @param callable $method
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Helper_Arr, validateAny) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *collection_param = NULL, *method = NULL, method_sub, __$null, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&method_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &method);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!method) {
		method = &method_sub;
		method = &__$null;
	}


	ZEPHIR_CALL_SELF(&_0, "filter", &_1, 252, &collection, method);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_fast_count_int(&_0) > 0);

}

/**
 * White list filter by key: obtain elements of an array filtering
 * by the keys obtained from the elements of a whitelist
 *
 * @param array $collection
 * @param array $whiteList
 *
 * @return array
 */
PHP_METHOD(Phalcon_Helper_Arr, whiteList) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collection_param = NULL, *whiteList_param = NULL, _0, _1, _2;
	zval collection, whiteList;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&whiteList);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &collection_param, &whiteList_param);

	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	ZEPHIR_OBS_COPY_OR_DUP(&whiteList, whiteList_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_3__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&_1, "array_filter", NULL, 251, &whiteList, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&whiteList, &_1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_flip", NULL, 166, &whiteList);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_intersect_key", NULL, 8, &collection, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

